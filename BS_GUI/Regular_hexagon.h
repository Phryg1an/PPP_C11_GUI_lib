#ifndef REGULAR_HEXAGON_GUARD
#define REGULAR_HEXAGON_GUARD 1

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


struct Regular_hexagon : Shape {

	Regular_hexagon(Point p, int ww) :w{ ww }
	{
		if (w<=0) error("Bad Regular hexagon: distance from center to corner cannot be < 0");
		add(Point{ p.x, p.y });
	}

	void draw_lines() const;

//	void set_fill_color(Color col) { fcolor = col; }
//	Color fill_color() { return fcolor; }

	int width() const { return w; }
	Point center() const { return {point(0).x, point(0).y}; }
	int y_offset() const { return y_off; }

	Point ne() const { return {point(0).x + (w/2), point(0).y - y_off}; }
	Point nw() const { return {point(0).x - (w/2), point(0).y - y_off}; }
	Point se() const { return {point(0).x + (w/2), point(0).y + y_off}; }
	Point sw() const { return {point(0).x - (w/2), point(0).y + y_off}; }	
	Point nn() const { return {point(0).x, point(0).y - y_off}; }
	Point ee() const { return {point(0).x + w, point(0).y}; }
	Point ss() const { return {point(0).x, point(0).y + y_off}; }
	Point ww() const { return {point(0).x - w, point(0).y}; }

private:
	
	int w;			// width
	int y_off = (int)((double)w * (cos((30.0) * (PI / 180.00)))); // y offset
	Point p;

//	Color fcolor;	// fill color; 0 means "no fill"
};




}
#endif