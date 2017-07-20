#ifndef STRIPED_CLOSED_POLYLINE_GUARD
#define STRIPED_CLOSED_POLYLINE_GUARD 1

#include "Closed_polyline.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Striped_closed_polyline : public Closed_polyline {

public:
	Striped_closed_polyline();
	Striped_closed_polyline(initializer_list<Point> lst);

	void set_stripes(int ss) { s=ss; }

protected:
	void draw_lines() const;

private:
	int s;
};	

}
#endif