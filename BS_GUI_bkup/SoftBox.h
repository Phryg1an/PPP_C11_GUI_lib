#ifndef SOFTBOX_GUARD
#define SOFTBOX_GUARD 1

#include "Graph.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor


struct SoftBox : Shape {
	SoftBox(Point p, int ww, int hh, int rr)	// width and height of box, radius of corner arcs
	:w{ ww }, h{ hh }, r{ rr }  //initialise members
	{
		if (w <= r*2 || h <= r*2) error("Arcs longer than SoftBox sides.");
		add(Point{ p.x, p.y });
	}

	void draw_lines() const;

private:
	int w;
	int h;
	int r;
	Point p;

};

}
#endif