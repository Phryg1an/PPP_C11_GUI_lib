#ifndef CLOSED_POLYLINE_GUARD
#define CLOSED_POLYLINE_GUARD 1

#include "Open_polyline.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Closed_polyline : public Open_polyline {

public:
	Closed_polyline();
	Closed_polyline(initializer_list<Point> lst);

protected:
	void draw_lines() const;

private:
};

}
#endif