#ifndef CIRCLE_GUARD
#define CIRCLE_GUARD 1

#include "Graph.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor


struct Circle : Shape {
	Circle(Point p, int rr)	// center and radius
	:r{ rr } {
		add(Point{ p.x - r, p.y - r });
	}

	void draw_lines() const;

	Point center() const { return { point(0).x + r, point(0).y + r }; }

	void set_radius(int rr) { r=rr; }
	int radius() const { return r; }
	int diameter() const { return r+r; }
private:
	int r;
};

Point ne(Circle &c);
Point nw(Circle &c);
Point se(Circle &c);
Point sw(Circle &c);
Point nn(Circle &c);
Point ee(Circle &c);
Point ww(Circle &c);
Point ss(Circle &c);

}
#endif