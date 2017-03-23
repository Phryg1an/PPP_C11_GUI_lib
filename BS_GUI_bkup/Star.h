#ifndef STAR_GUARD
#define STAR_GUARD 1

#include "Graph.h"


namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

	
class Star : public Shape {


private:
	int w;
	int p;
	int a;
	double ar = a * (PI / 180.0); //initial angle from center in radians
	Point cen;

public:

	Star(Point cen, int pp, int ww, int aa = 0);
	//	:s1( ss1 ), s2(ss2 ), a( aa) 
	//{
//		if (s1<=0 || s2<=0) error("Bad Right triangle: sides must be greater than 0");
	//	add(Point{ p.x, p.y });
//	}

	void draw_lines() const;

};




}
#endif