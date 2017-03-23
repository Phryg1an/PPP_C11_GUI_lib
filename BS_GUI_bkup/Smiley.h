#ifndef SMILEY_GUARD
#define SMILEY_GUARD 1

#include "Graph.h"
#include "Circle.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Smiley : public Circle {
public:
	Smiley(Point pp, int rr)	// center of smiley, radius of smiley, is it smiling? 1 = yes 
	:Circle(pp, rr) {} //initialise members


protected:
	void draw_lines() const;
};

} 
#endif