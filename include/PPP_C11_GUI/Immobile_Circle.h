#ifndef IMMOBILE_CIRCLE_GUARD
#define IMMOBILE_CIRCLE_GUARD 1

#include "Graph.h"
#include "Circle.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Immobile_Circle : public Circle {
public:
	Immobile_Circle(Point pp, int rr)	// center of smiley, radius of smiley, is it smiling? 1 = yes 
	:Circle(pp, rr) {} //initialise members

	void move(int dx, int dy);

protected:
	
};

} 
#endif