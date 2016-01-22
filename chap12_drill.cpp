//Demo script to show Bjarne's GUI library in action
//
//19th January 2015

//#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

// int main()
// {
// 	using namespace Graph_lib;

// 	Graph_lib::Point tl {100, 100};

// 	Simple_window win {tl,600,400,"Canvas"};

// 	Polygon poly;

// 	poly.add(Graph_lib::Point{300,200});
// 	poly.add(Graph_lib::Point{350,100});
// 	poly.add(Graph_lib::Point{400,200});

// 	poly.set_color(Color::red);

// 	win.attach(poly);

// 	win.wait_for_button();
// }

using namespace Graph_lib;

int main()
try
{

	//---------------------set window

	Point tl {100,100}; //top left corner of our window

	Simple_window win {tl,600,400,"Canvas"};
	//screen co-ordinate tl for top left corner
	//window size (600*400)
	//title: Canvas

	win.wait_for_button(); // display!

	//---------------------set x axis

	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
	//an axis is a kind of shape
	//Axis::x means horizontal
	//starting at (20,300)
	//280 pixels long
	//10 'notches'
	//label the axis 'x axis'

	win.attach(xa); //attach xa to the window, win
	win.set_label("Canvas #2"); //relabel the window
	win.wait_for_button(); //display!

	//---------------------set y axis

	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::cyan); //choose a color
	ya.label.set_color(Color::dark_red); //choose a color for the text
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button(); //display!

	//---------------------plot sine wave

	Function sine {sin,0,100,Point{20,150},1000,50,50}; //sine curve
		//plot sin() in the range {0:100} with {0,0} at {20,150}
		//using 1000 points; scale x values *50, scale y values *50

	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();

	//---------------------change sine colour and plot triangle

	sine.set_color(Color::blue); //we changed our mind about sine's color

	Polygon poly; //a polygon
	poly.add(Point{300,200}); //three points make a triangle
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);

	win.set_label("Canvas #5");
	win.wait_for_button();

	//---------------------make a rectangle

	Rectangle r (Point{200,200}, 100, 50);
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();

	//---------------------make something that looks like a rectangle,
	//---------------------but isn't.........

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);

	win.wait_for_button();

	poly_rect.add(Point{50,75});

	win.wait_for_button();

	//---------------------fill in the shapes!

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
	win.wait_for_button();

	//---------------------add some text

	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();

	//---------------------format the text

	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(20);
	win.set_label("Canvas #9");
	win.wait_for_button();

	//---------------------load in an image

	Image ii {Point(100,50),"sk.jpg"};
	win.attach(ii);
	win.set_label("Canvas #10");
	win.wait_for_button();

	//---------------------move the image

	ii.move(100,200);
	win.set_label("Canvas #11");
	win.wait_for_button();

	//---------------------additional stuff

	Circle c{Point{100,200},50};
	Ellipse e{Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m{Point{100,200},'x'};

	ostringstream oss;
	oss << "Screen size: " << x_max() << "*" << y_max()
		<< "; Window size: " << win.x_max() << '*' << win.y_max();
	Text sizes {Point(100,20),oss.str()};

	Image cal {Point(255,255), "UHOFRONTCOVERJPG.jpg"}; //huge jpg
	cal.set_mask(Point{40,40},200,150); //display centre part of image

	win.attach(c);
	win.attach(m);
	win.attach(e);

	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
	win.wait_for_button();
	



}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}