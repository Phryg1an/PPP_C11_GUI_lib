#ifndef ELLIPSE_GUARD
#define ELLIPSE_GUARD 1

#include "Graph.h"

namespace Graph_lib {

#undef major
#undef minor

struct Ellipse : Shape {
	Ellipse(Point p, int ww, int hh)	// center, min, and max distance from center
	:w{ ww }, h{ hh } {
		add(Point{ p.x - ww, p.y - hh });
	}

	void draw_lines() const;

	Point center() const { return{ point(0).x + w, point(0).y + h }; }
	Point focus1() const { return{ center().x + int(sqrt(double(w*w - h*h))), center().y }; }
	Point focus2() const { return{ center().x - int(sqrt(double(w*w - h*h))), center().y }; }

	// Functions for returning compass points on the ellipse
	double dminor() const { return (double)h; }
	double dmajor() const { return (double)w; }
	double get_corner_angle() const;

	int cdiffx() const;
	int cdiffy() const;

	void set_major(int ww) { w=ww; }
	int major() const { return w; }
	void set_minor(int hh) { h=hh; }
	int minor() const { return h; }

private:
	int w;
	int h;
};

Point ne(Ellipse &e);
Point nw(Ellipse &e);
Point se(Ellipse &e);
Point sw(Ellipse &e);
Point nn(Ellipse &e);
Point ee(Ellipse &e);
Point ww(Ellipse &e);
Point ss(Ellipse &e);

}
#endif