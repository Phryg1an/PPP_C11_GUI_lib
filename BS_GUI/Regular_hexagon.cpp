#include "Regular_hexagon.h"

namespace Graph_lib {

void Regular_hexagon::draw_lines() const
{

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_begin_polygon();

			fl_vertex(point(0).x - w, 		point(0).y);
			fl_vertex(point(0).x - (w/2), 	point(0).y - y_off);
			
			fl_vertex(point(0).x + (w/2), 	point(0).y - y_off);
			fl_vertex(point(0).x + w, 		point(0).y);
			
			fl_vertex(point(0).x + (w/2), 	point(0).y + y_off);
			fl_vertex(point(0).x - (w/2), 	point(0).y + y_off);
			fl_vertex(point(0).x - w, 		point(0).y);

		fl_end_polygon();

		fl_color(color().as_int());

	}

	if (color().visibility()){

		fl_color(color().as_int());

		// Draw Lines
		fl_line(point(0).x - w, 		point(0).y,     		point(0).x - (w/2), 	point(0).y - y_off);
		fl_line(point(0).x - (w/2), 	point(0).y - y_off,     point(0).x + (w/2), 	point(0).y - y_off);
		fl_line(point(0).x + (w/2), 	point(0).y - y_off,		point(0).x + w, 		point(0).y);

		fl_line(point(0).x + w, 		point(0).y,     		point(0).x + (w/2), 	point(0).y + y_off);
		fl_line(point(0).x + (w/2), 	point(0).y + y_off,     point(0).x - (w/2), 	point(0).y + y_off);
		fl_line(point(0).x - (w/2), 	point(0).y + y_off,		point(0).x - w, 		point(0).y);

	}
}

}