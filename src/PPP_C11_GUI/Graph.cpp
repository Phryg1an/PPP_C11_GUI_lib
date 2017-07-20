#include "Graph.h"
#include <map>

namespace Graph_lib {

	Shape::Shape(initializer_list<Point> lst)
		{
			for (Point p : lst) add(p);
		}  // add() the Points to this Shape

	//	Sha

	void Shape::draw_lines() const
	{
		if (color().visibility() && 1<points.size())	// draw sole pixel?
			for (unsigned int i=1; i<points.size(); ++i)
				fl_line(points[i-1].x,points[i-1].y,points[i].x,points[i].y);
	}

	void Shape::draw() const
	{
		Fl_Color oldc = fl_color();
		// there is no good portable way of retrieving the current style
		fl_color(lcolor.as_int());
		fl_line_style(ls.style(),ls.width());
		draw_lines();
		fl_color(oldc);	// reset color (to pevious) and style (to default)
		fl_line_style(0);
	}




	void Shape::move(int dx, int dy)
	{
		for (unsigned int i = 0; i<points.size(); ++i) {
			points[i].x+=dx;
			points[i].y+=dy;
		}
	}

void Lines::draw_lines() const
{
//	if (number_of_points()%2==1) error("odd number of points in set of lines");
	if (color().visibility())
		for (int i=1; i<number_of_points(); i+=2)
			fl_line(point(i-1).x,point(i-1).y,point(i).x,point(i).y);
}

void Text::draw_lines() const
{
	int ofnt = fl_font();
	int osz = fl_size();
	fl_font(fnt.as_int(),fnt_sz);
	fl_draw(lab.c_str(), point(0).x, point(0).y);
	fl_font(ofnt,osz);
}

Axis::Axis(Orientation d, Point xy, int length, int n, string lab)
	:label(Point(0,0),lab)
{
	if (length<0) error("bad axis length");
	switch (d){
	case Axis::x:
		{	Shape::add(xy);	// axis line
			Shape::add(Point(xy.x+length,xy.y));	// axis line
			if (1<n) {
				int dist = length/n;
				int x = xy.x+dist;
				for (int i = 0; i<n; ++i) {
					notches.add(Point(x,xy.y),Point(x,xy.y-5));
				x += dist;
			}
		}
		// label under the line
		label.move(length/3,xy.y+20);
		break;
	}
	case Axis::y:
		{	Shape::add(xy);	// a y-axis goes up
			Shape::add(Point(xy.x,xy.y-length));
			if (1<n) {
			int dist = length/n;
			int y = xy.y-dist;
			for (int i = 0; i<n; ++i) {
				notches.add(Point(xy.x,y),Point(xy.x+5,y));
				y -= dist;
			}
		}
		// label at top
		label.move(xy.x-10,xy.y-length-10);
		break;
	}
	case Axis::z:
		error("z axis not implemented");
	}
}

void Axis::draw_lines() const
{
	Shape::draw_lines();	// the line
	notches.draw();	// the notches may have a different color from the line
	label.draw();	// the label may have a different color from the line
}


void Axis::set_color(Color c)
{
	Shape::set_color(c);
	notches.set_color(c);
	label.set_color(c);
}

void Axis::move(int dx, int dy)
{
	Shape::move(dx,dy);
	notches.move(dx,dy);
	label.move(dx,dy);
}


void Arc::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,w+w-1,h+h-1,s,e);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,w+w,h+h,s,e);
	}
}







/*
void Marks::draw_lines() const
{
	for (int i=0; i<number_of_points(); ++i) 
		fl_draw(mark.c_str(),point(i).x-4,point(i).y+4);
}
*/


std::map<string,Suffix::Encoding> suffix_map;

int init_suffix_map()
{
	suffix_map["jpg"] = Suffix::jpg;
	suffix_map["JPG"] = Suffix::jpg;
	suffix_map["jpeg"] = Suffix::jpg;
	suffix_map["JPEG"] = Suffix::jpg;
	suffix_map["gif"] = Suffix::gif;
	suffix_map["GIF"] = Suffix::gif;
	suffix_map["bmp"] = Suffix::bmp;
	suffix_map["BMP"] = Suffix::bmp;
	return 0;
}

Suffix::Encoding get_encoding(const string& s)
		// try to deduce type from file name using a lookup table
{
	static int x = init_suffix_map();

	string::const_iterator p = find(s.begin(),s.end(),'.');
	if (p==s.end()) return Suffix::none;	// no suffix

	string suf(p+1,s.end());
	return suffix_map[suf];
}

bool can_open(const string& s)
            // check if a file named s exists and can be opened for reading
{
	ifstream ff(s.c_str());
	return ff;
}


// somewhat overelaborate constructor
// because errors related to image files can be such a pain to debug
Image::Image(Point xy, string s, Suffix::Encoding e)
	:w(0), h(0), fn(xy,"")
{
	add(xy);

	if (!can_open(s)) {
		fn.set_label("cannot open \""+s+'\"');
		p = new Bad_image(30,20);	// the "error image"
		return;
	}

	if (e == Suffix::none) e = get_encoding(s);
	
	switch(e) {
	case Suffix::jpg:
		p = new Fl_JPEG_Image(s.c_str());
		break;
	case Suffix::gif:
		p = new Fl_GIF_Image(s.c_str());
		break;
//	case Suffix::bmp:
//		p = new Fl_BMP_Image(s.c_str());
//		break;
	default:	// Unsupported image encoding
		fn.set_label("unsupported file type \""+s+'\"');
		p = new Bad_image(30,20);	// the "error image"
	}
}

void Image::draw_lines() const
{
	if (fn.label()!="") fn.draw_lines();

	if (w&&h)
		p->draw(point(0).x,point(0).y,w,h,cx,cy);
	else
		p->draw(point(0).x,point(0).y);
}

Superellipse::Superellipse(double a, double b, double m, double n, Point origin, int N, int win_limit, double graph_limit)
	// Using the explicit equation ->
	// y =  +/-b * (( 1 - (x/a)^m  )^(1/n))
	// 
	// We'll give it Point origin as the graph axis 0,0
	//
	// win_limit denotes number of pixels from origin to graph limit
	// graph_limit denotes positive value from origin
	// N denotes number of points to draw across entire ellipse
{

	// Basic sense checking
	if (N<=0) error("non-positive graphing count");
	if (a < 0.0 || b < 0.0 || m < 0.0 || n < 0.0 || win_limit < 0 || graph_limit < 0.0) error("One or more parameters are negative");

	// Derive scale
	double win_scale = win_limit / graph_limit;

	// Derive count from origin to limit;
	int count = N / 2;

	// Derive number of points to plot along x scale
	double dist = (graph_limit*2) / (count);

	// declare y and derive negative x limit
	double y;
	double x = -(graph_limit);

	//Loop forward through positive b values
	for (int i = 0; i < count; ++i)
	{
		y = b * pow(1 - pow(abs(x/a),m),1.0/n);
		add(Point(origin.x+int(x*win_scale),origin.y+int(y*win_scale)));
		x += dist;
	}

	//Loop backwards through negative b values
	for (int i = 0; i < count; ++i)
	{
		y = -b * pow(1 - pow(abs(x/a),m),1.0/n);
		add(Point(origin.x+int(x*win_scale),origin.y+int(y*win_scale)));
		x -= dist;
	}
}






} // Graph