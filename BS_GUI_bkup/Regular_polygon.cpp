#include "Regular_polygon.h"

namespace Graph_lib {

void Regular_polygon::draw_lines() const
{

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_begin_polygon();

		for (int i = 1; i < s + 1; i++){
			fl_vertex((int)std::round(point(0).x + w * (cos(2.0*PI*(double)i/(double)s + ar))),
				(int)std::round(point(0).y + w * (sin(2.0*PI*(double)i/(double)s + ar))));

		}

		fl_vertex((int)std::round(point(0).x + w * (cos(2.0*PI*1/(double)s + ar))),
			(int)std::round(point(0).y + w * (sin(2.0*PI*1/(double)s + ar))));

		fl_end_polygon();

		fl_color(color().as_int());

	}

	if (color().visibility()){

		fl_color(color().as_int());

		for (int i = 1; i < s + 1; i++){
			fl_line((int)std::round(point(0).x + w * (cos(2.0*PI*(double)i/(double)s + ar))),
				(int)std::round(point(0).y + w * (sin(2.0*PI*(double)i/(double)s + ar))),
				(int)std::round(point(0).x + w * (cos(2.0*PI*(double)(i+1)/(double)s + ar))),
				(int)std::round(point(0).y + w * (sin(2.0*PI*(double)(i+1)/(double)s + ar))));


		}

	}
}

}