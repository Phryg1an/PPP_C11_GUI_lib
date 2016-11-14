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

	Bool is_inside(Point &ii) const;
	Bool is_inside(int &x, int &y) const;

	Point ne() const;
	Point nw() const;
	Point se() const;
	Point sw() const;
	Point nn() const;
	Point ee() const;
	Point ww() const;
	Point ss() const;

private:
	int r;
	Point p;
};



}
#endif