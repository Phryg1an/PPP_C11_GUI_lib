#ifndef MANDELBROT_GUARD
#define MANDELBROT_GUARD 1
#include <windows.h>
#include "Graph.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor


class Mandelbrot : public Shape {
public:
	Mandelbrot(Point p, int ss, int ii = 255, double ee = 2.0)
	:s{ ss }, i{ ii }, e{ ee } {
		add(Point{ p.x , p.y});
	}

	void draw_lines() const;

	
protected:
	Point p;
	int s;
	int i;
	double e;
};



}
#endif
