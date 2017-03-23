#ifndef ARROW_GUARD
#define ARROW_GUARD 1

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


//static const double PI = 3.14159265359;

struct Arrow : Shape {
	Arrow(Point p1, Point p2, int ll, double aa)	// start of arrow, tip of arrow, arrowhead length and angle
	:l{ ll }, a{ aa }  //initialise members
	{
		if (p1 == p2) error("Arrow must have two distinct points.");

		add(Point{ p1.x, p1.y });
		add(Point{ p2.x, p2.y });
	}

	void draw_lines() const;


private:
	int l;
	double a;
	double a1;
	double a2;
	int p3x;
	int p3y;
	int p4x;
	int p4y;

};

}
#endif