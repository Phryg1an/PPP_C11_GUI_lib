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

	void set_major(int ww) { w=ww; }
	int major() const { return w; }
	double dmaj() const {return (double)w; }
	
	void set_minor(int hh) { h=hh; }
	int minor() const { return h; }
	double dmin() const { return (double)h; }

	Point center() const { return{ point(0).x + w, point(0).y + h }; }
	Point focus1() const { return{ center().x + int(sqrt(dmaj()*dmaj() - dmin() * dmin())), center().y }; }
	Point focus2() const { return{ center().x - int(sqrt(dmaj()*dmaj() - dmin() * dmin())), center().y }; }

	double get_corner_angle() const {
			if (h >= w) {
				return 45.00 * (double)(dmin()-dmaj()/(dmin()+dmaj()) * (PI / 180.0));
			}
		return 45.00 * (1.00 + abs((double)((dmin()-dmaj()/(dmin()+dmaj()))) * (PI / 180.0)));
	}

	int cdiffx() const {
		return (int)((dmin()*dmaj()*sin(get_corner_angle()))/(sqrt( pow(dmaj()*cos(get_corner_angle()),2) + pow(dmin()*sin(get_corner_angle()),2))));
	}
	int cdiffy() const {
		return (int)((dmin()*dmaj()*cos(get_corner_angle()))/(sqrt(pow(dmaj()*cos(get_corner_angle()),2) + pow(dmin()*sin(get_corner_angle()),2))));
	}

	Point ne() const { return{ center().x - cdiffx(), center().y + cdiffy()}; }
	Point nw() const { return{ center().x + cdiffx(), center().y + cdiffy()}; }
	Point se() const { return{ center().x - cdiffx(), center().y - cdiffy()}; }
	Point sw() const { return{ center().x + cdiffx(), center().y - cdiffy()}; }
	Point nn() const { return{ center().x, center().y - h }; }
	Point ee() const { return{ center().x + w, center().y}; }
	Point ss() const { return{ center().x, center().y + h}; }
	Point ww() const { return{ center().x - w, center().y}; }


private:
	int w;
	int h;
	Point p;

};


}
#endif