#ifndef SMILEY_HAT_GUARD
#define SMILEY_HAT_GUARD 1

#include "Graph.h"
#include "Smiley.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Smiley_hat : public Smiley {
public:
	Smiley_hat(Point pp, int rr)	// center of smiley, radius of smiley, is it smiling? 1 = yes 
	:Smiley(pp, rr) {} //initialise members

protected:
	void draw_lines() const;

};

} 
#endif