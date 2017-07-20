#ifndef POLYGON_GUARD
#define POLYGON_GUARD 1

#include "Graph.h"
#include "Closed_polyline.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Polygon : public Closed_polyline {

public:
	Polygon();
	Polygon(initializer_list<Point> lst);
	void add(Point p);

protected:
	void draw_lines() const;
	bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection);
	inline pair<double,double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel);

private:
};

}
#endif