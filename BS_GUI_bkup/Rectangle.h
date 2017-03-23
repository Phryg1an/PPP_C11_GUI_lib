#ifndef RECTANGLE_GUARD
#define RECTANGLE_GUARD 1

//#include "Point.h"
//#include<vector>
#include "Graph.h"
//#include<string>
//#include <cmath>
//#include "fltk.h"
//#include "std_lib_facilities.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor


struct Rectangle : Shape {

	Rectangle(Point xy, int ww, int hh) :w{ ww }, h{ hh }
	{
		if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
		add(xy);
	}
	Rectangle(Point x, Point y) :w{ y.x - x.x }, h{ y.y - x.y }
	{
		if (h<=0 || w<=0) error("Bad rectangle: first point is not top left");
		add(x);
	}
	void draw_lines() const;

//	void set_fill_color(Color col) { fcolor = col; }
//	Color fill_color() { return fcolor; }

	int height() const { return h; }
	int width() const { return w; }
	Point center() const { return {point(0).x + (w/2), point(0).y + (h/2)}; }
private:
	int h;			// height
	int w;			// width
//	Color fcolor;	// fill color; 0 means "no fill"
};

Point ne(Rectangle &r);
Point nw(Rectangle &r);
Point se(Rectangle &r);
Point sw(Rectangle &r);
Point nn(Rectangle &r);
Point ee(Rectangle &r);
Point ww(Rectangle &r);
Point ss(Rectangle &r);


}
#endif