#ifndef REGULAR_POLYGON_GUARD
#define REGULAR_POLYGON_GUARD 1

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


struct Regular_polygon : Shape {

	Regular_polygon(Point p, int ss, int ww, int aa = 0) :s{ss}, w{ ww }, a{ aa }
	{
		if (w<=0) error("Bad Regular polygon: distance from center to corner cannot be < 0");
		if (s <3) error("Bad Regular polygon: number of sides cannot be less than 3.");
		add(Point{ p.x, p.y });
	}

	void draw_lines() const;
	int width() const { return w; }
	int sides() const { return s; }
	Point center() const { return {point(0).x, point(0).y}; }


private:
	
	int w;		// width
	int s;		// number of sides
	int a;		// initial angle from center in degrees
	double ar = a * (PI / 180.0); //initial angle from center in radians
	Point p;

};




}
#endif