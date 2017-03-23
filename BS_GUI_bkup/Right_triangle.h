#ifndef RIGHT_TRIANGLE_GUARD
#define RIGHT_TRIANGLE_GUARD 1

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

	
class Right_triangle : public Shape {

	// assuming a triangle such as:
	// 1
	// 1x
	// 1xx
	// 1xxx
	// 02222
	//
	// Request... 
	// 		position of point 0
	// 		length of side 1 (adjacent)
	// 		length of side 2 (opposite)
	// 		relationship of side 2's angle to x-axis

private:
	int s1;
	int s2;
	int a;
	Point p;

public:

	Right_triangle(Point p, int ss1, int ss2, int aa = 0)
		:s1( ss1 ), s2(ss2 ), a( aa) 
	{
		if (s1<=0 || s2<=0) error("Bad Right triangle: sides must be greater than 0");
		add(Point{ p.x, p.y });
	}

	void draw_lines() const;

	// Helper functions:
	// Imagine the right point is at the bottom and the hypotenuse is at the top
	//
	// c_pointl returns the corner point on the left of the hypotenuse
	// c_pointr returns the corner point on the right of the hypotenuse
	
	Point c_pointl() const;
	Point c_pointr() const;
	Point c_point() const { return { point(0).x, point(0).y }; }


};




}
#endif