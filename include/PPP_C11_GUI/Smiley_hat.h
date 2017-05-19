#ifndef SMILEY_HAT_GUARD
#define SMILEY_HAT_GUARD 1

#include "Graph.h"
#include "Smiley.h"
#include "Rectangle.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Smiley_hat : public Smiley {
public:
	Smiley_hat(Point pp, int rr);	// center of smiley, radius of smiley, is it smiling? 1 = yes 
	//	:Smiley(pp, rr) {} //initialise members

private:
//	Rectangle h1(center(),radius()*2,radius());
//	Rectangle h2(center(),radius()*2,radius());

protected:
	void draw_lines() const;

};

} 
#endif