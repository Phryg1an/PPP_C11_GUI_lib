#ifndef STRIPED_CIRCLE_GUARD
#define STRIPED_CIRCLE_GUARD 1

#include "Graph.h"
#include "Circle.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Striped_circle : public Circle {
public:
	Striped_circle(Point p, int rr);

protected:
	void draw_lines() const;

private:

};

}
#endif