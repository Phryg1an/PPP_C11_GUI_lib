#ifndef STRIPED_RECTANGLE_GUARD
#define STRIPED_RECTANGLE_GUARD 1

#include "Graph.h"
#include "Rectangle.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Striped_rectangle : public Rectangle {
public:
	Striped_rectangle(Point p, int ww, int hh);

	Striped_rectangle(Point p, Point y);

protected:
	void draw_lines() const;

private:
};

}
#endif