#ifndef FROWNY_HAT_GUARD
#define FROWNY_HAT_GUARD 1

#include "Graph.h"
#include "Frowny.h"
#include "Rectangle.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Frowny_hat : public Frowny {
public:
	Frowny_hat(Point pp, int rr);	// center of smiley, radius of smiley, is it smiling? 1 = yes 


private:

protected:
	void draw_lines() const;

};

} 
#endif