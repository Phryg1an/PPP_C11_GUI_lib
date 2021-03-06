//Graph header file
//
//From Bjarne Stroustrup
//
//Contains the following class definitions / declarations:
//	Font
//	Shape
//
//Contains the following struct definitions / declarations:
//	Color
//	Line_style
//	Fill
//	Suffix
//	Function : Shape
//	Line : Shape
//	Rectangle : Shape
//	Text : Shape
//	Axis : Shape
//	Circle : Shape
//	Ellipse : Shape
//	Lines : Shape 
//	Image : Shape
//	Open_polyline : Shape
//	Marked_polyline : Open_polyline
//	Closed_polyline : Open_polyline
//	Polygon : Closed_polyline 
//	Mark : Marks
//	Marks : Marked_polyline
//	Bad_image : Fl_Image
//	Mark : Text - INACTIVE 
//	Marks : Shape - INACTIVE
//
//Contains the following template definitions / declarations:
//	template<class T> class Vector_ref 
//
//Contains the following function declarations:
//	bool intersect
//	Suffix::Encoding get_encoding
//
//Contains the following typedef declarations / definitions
//	double Fct
//
#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include "Point.h"
#include<vector>
//#include<string>
#include <cmath>
#include "fltk.h"
#include "std_lib_facilities.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor


static const double PI = 3.14159265359;
//------------------------------------------

	struct Color {
		enum Color_type {
			red=FL_RED, blue=FL_BLUE, green=FL_GREEN,
			yellow=FL_YELLOW, white=FL_WHITE, black=FL_BLACK,
			magenta=FL_MAGENTA, cyan=FL_CYAN, dark_red=FL_DARK_RED,
			dark_green=FL_DARK_GREEN, dark_yellow=FL_DARK_YELLOW, dark_blue=FL_DARK_BLUE,
			dark_magenta=FL_DARK_MAGENTA, dark_cyan=FL_DARK_CYAN
		};
		enum Transparency { invisible = 0, visible=255 };

		Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
		Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
		Color(int cc) :c(Fl_Color(cc)), v(visible) { }
		Color(Transparency vv) :c(Fl_Color()), v(vv) { }

		int as_int() const { return c; }
		char visibility() const { return v; }
		void set_visibility(Transparency vv) { v=vv; }
	private:
		unsigned char v;	// 0 or 1 for now
		Fl_Color c;
	};

	//------------------------------------------

	struct Line_style {
		enum Line_style_type {
			solid=FL_SOLID,				// -------
			dash=FL_DASH,				// - - - -
			dot=FL_DOT,					// ....... 
			dashdot=FL_DASHDOT,			// - . - . 
			dashdotdot=FL_DASHDOTDOT,	// -..-..
		};
		Line_style(Line_style_type ss) :s(ss), w(0) { }
		Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
		Line_style(int ss) :s(ss), w(0) { }

		int width() const { return w; }
		int style() const { return s; }
	private:
		int s;
		int w;
	};

	struct Fill {
		Fill() :no_fill(true), fcolor(0) { }
		Fill(Color c) :no_fill(false), fcolor(c) { }

		void set_fill_color(Color col) { fcolor = col; }
		Color fill_color() { return fcolor; }
	protected:
		bool no_fill;
		Color fcolor;
	};

	//------------------------------------------

	class Font {
	public:
		enum Font_type {
			helvetica=FL_HELVETICA,
			helvetica_bold=FL_HELVETICA_BOLD,
			helvetica_italic=FL_HELVETICA_ITALIC,
			helvetica_bold_italic=FL_HELVETICA_BOLD_ITALIC,
			courier=FL_COURIER,
	  		courier_bold=FL_COURIER_BOLD,
	  		courier_italic=FL_COURIER_ITALIC,
	  		courier_bold_italic=FL_COURIER_BOLD_ITALIC,
			times=FL_TIMES,
			times_bold=FL_TIMES_BOLD,
			times_italic=FL_TIMES_ITALIC,
			times_bold_italic=FL_TIMES_BOLD_ITALIC,
			symbol=FL_SYMBOL,
			screen=FL_SCREEN,
			screen_bold=FL_SCREEN_BOLD,
			zapf_dingbats=FL_ZAPF_DINGBATS
		};

		Font(Font_type ff) :f(ff) { }
		Font(int ff) :f(ff) { }

		int as_int() const { return f; }
	private:
		int f;
	};

	//------------------------------------------

	template<class T> class Vector_ref {
		vector<T*> v;
		vector<T*> owned;
	public:
		Vector_ref() {}

		Vector_ref(T* a, T* b=0, T* c=0, T* d=0)
		{
				if (a) push_back(a);
				if (b) push_back(b);
				if (c) push_back(c);
				if (d) push_back(d);
		}

		~Vector_ref() { for (int i=0; i<owned.size(); ++i) delete owned[i]; }

		void push_back(T& s) { v.push_back(&s); }
		void push_back(T* p) { v.push_back(p); owned.push_back(p); }

		// ???void erase(???)

		T& operator[](int i) { return *v[i]; }
		const T& operator[](int i) const { return *v[i]; }
		int size() const { return v.size(); }
	};

	//------------------------------------------

	class Shape  {	// deals with color and style, and holds sequence of lines
	protected:
		Shape() { }
		Shape(initializer_list<Point> lst);

	//	Shape() : lcolor(fl_color()),
	//		ls(0),
	//		fcolor(Color::invisible) { }
		
		void add(Point p){ points.push_back(p); }
		void set_point(int i, Point p) { points[i] = p; }

	public:
		void draw() const;					// deal with color and draw_lines
	
	protected:
		virtual void draw_lines() const;	// simply draw the appropriate lines
	
	public:
		virtual void move(int dx, int dy);	// move the shape +=dx and +=dy

		void set_color(Color col) { lcolor = col; }
		Color color() const { return lcolor; }

		void set_style(Line_style sty) { ls = sty; }
		Line_style style() const { return ls; }

		void set_fill_color(Color col) { fcolor = col; }
		Color fill_color() const { return fcolor; }

		Point point(int i) const { return points[i]; }
		int number_of_points() const { return int(points.size()); }

		virtual ~Shape() { }
		/*
		struct Window* attached;
		Shape(const Shape& a)
			:attached(a.attached), points(a.points), line_color(a.line_color), ls(a.ls)
		{
			if (a.attached)error("attempt to copy attached shape");
		}
		*/
		Shape(const Shape&) = delete;
		Shape& operator=(const Shape&) = delete;
	
	private:
		vector<Point> points;	// not used by all shapes
		Color lcolor {fl_color()};
		Line_style ls {0};
		Color fcolor {Color::invisible};

	//	Shape(const Shape&);
	//	Shape& operator=(const Shape&);
	};

//------------------------------------------

struct Line : public Shape {
	Line(Point p1, Point p2) { add(p1); add(p2); }
};


bool intersect(Point p1, Point p2, Point p3, Point p4);

//------------------------------------------

struct Lines : Shape {	// indepentdent lines
	Lines() {}
	Lines(initializer_list<Point> lst) : Shape{lst} { if (lst.size() % 2) error("odd number of points for Lines"); }
	void draw_lines() const;
	void add(Point p1, Point p2) { Shape::add(p1); Shape::add(p2); }
};

//------------------------------------------

struct Text : Shape {
	// the point is the bottom left of the first letter
	Text(Point x, const string& s) : lab{ s } { add(x); }

	void draw_lines() const;

	void set_label(const string& s) { lab = s; }
	string label() const { return lab; }

	void set_font(Font f) { fnt = f; }
	Font font() const { return Font(fnt); }

	void set_font_size(int s) { fnt_sz = s; }
	int font_size() const { return fnt_sz; }
private:
	string lab;	// label
	Font fnt{ fl_font() };
	int fnt_sz{ (14<fl_size()) ? fl_size() : 14 };	// at least 14 point
};

//------------------------------------------

struct Axis : Shape {
	// representation left public
	enum Orientation { x, y, z };
	Axis(Orientation d, Point xy, int length, int nummber_of_notches=0, string label = "");

	void draw_lines() const;
	void move(int dx, int dy);

	void set_color(Color c);

	Text label;
	Lines notches;
//	Orientation orin;
//	int notches;
};

//------------------------------------------

struct Arc : Shape {
	Arc(Point p, int ww, int hh, int ss, int ee)	// center, min and max distance from center, start and end angle
	:w{ ww }, h{ hh }, s{ ss }, e{ ee } {
		add(Point{ p.x - ww, p.y - hh });
	}

	void draw_lines() const;

	Point center() const { return{ point(0).x + w, point(0).y + h }; }
	Point focus1() const { return{ center().x + int(sqrt(double(w*w - h*h))), center().y }; }
	Point focus2() const { return{ center().x - int(sqrt(double(w*w - h*h))), center().y }; }
	
	void set_major(int ww) { w=ww; }
	int major() const { return w; }
	void set_minor(int hh) { h=hh; }
	int minor() const { return h; }
	void set_start(int ss) { s=ss; }
	int arc_start() const { return s; }
	void set_end(int ee) { e=ee; }
	int arc_end() const { return e; }

private:
	int w;
	int h;
	int s;
	int e;
};
//------------------------------------------

//------------------------------------------

//------------------------------------------


//------------------------------------------

/*

struct Marks : Shape {
	Marks(char m) : mark(string(1,m)) { }
	void add(Point p) { Shape::add(p); }
	void draw_lines() const;
private:
	string mark;
};
*/

//------------------------------------------

struct Bad_image : Fl_Image {
	Bad_image(int h, int w) : Fl_Image(h,w,0) { }
	void draw(int x,int y, int, int, int, int) { draw_empty(x,y); }
};

//------------------------------------------

struct Suffix {
	enum Encoding { none, jpg, gif, bmp };
};

//------------------------------------------

Suffix::Encoding get_encoding(const string& s);

//------------------------------------------

struct Image : Shape {
	Image(Point xy, string s, Suffix::Encoding e = Suffix::none);
	~Image() { delete p; }
	void draw_lines() const;
	void set_mask(Point xy, int ww, int hh) { w=ww; h=hh; cx=xy.x; cy=xy.y; }
	void move(int dx,int dy) { Shape::move(dx,dy); p->draw(point(0).x,point(0).y); }
private:
	int w,h,cx,cy; // define "masking box" within image relative to position (cx,cy)
	Fl_Image* p;
	Text fn;
};

//------------------------------------------

struct Superellipse : Shape {
	// Using the explicit equation ->
	// y =  +/-b * (( 1 - (x/a)^m  )^(1/n))

	// Using the explicit equation ->
	// y =  +/-b * (( 1 - (x/a)^m  )^(1/n))
	// 
	// We'll give it Point origin as the graph axis 0,0
	//
	// win_limit denotes number of pixels from origin to graph limit
	// graph_limit denotes positive value from origin
	// N denotes number of points to draw across entire ellipse
	Superellipse(double a, double b, double m, double n, Point origin, int N = 200, int win_limit = 100, double graph_limit = 3);
};

}
#endif

