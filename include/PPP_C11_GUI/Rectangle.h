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


class Rectangle : public Shape {
public:
	Rectangle(Point p, int ww, int hh) :w{ ww }, h{ hh }
	{
		if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
		add(p);
	}
	Rectangle(Point p, Point y) :w{ y.x - p.x }, h{ y.y - p.y }
	{
		if (h<=0 || w<=0) error("Bad rectangle: first point is not top left");
		add(p);
	}

	Point ne() const;
	Point nw() const;
	Point se() const;
	Point sw() const;
	Point nn() const;
	Point ee() const;
	Point ww() const;
	Point ss() const;

	int height() const { return h; }
	int width() const { return w; }
	Point center() const { return {point(0).x + (w/2), point(0).y + (h/2)}; }

protected:
	int h;			// height
	int w;			// width
	Point p;
	void draw_lines() const;
	
private:

//	Color fcolor;	// fill color; 0 means "no fill"
};


}
#endif