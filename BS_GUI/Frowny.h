#ifndef FROWNY_GUARD
#define FROWNY_GUARD 1

#include "Graph.h"
#include "Circle.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Frowny : public Circle {
public:
	Frowny(Point pp, int rr)	// center of smiley, radius of smiley, is it smiling? 1 = yes 
	:Circle(pp, rr) {} //initialise members
	
	void draw_lines() const;

};

} 
#endif