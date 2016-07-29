#include "SoftBox.h"

namespace Graph_lib {

void SoftBox::draw_lines() const
{

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_begin_polygon();

			fl_vertex(point(0).x - (w/2) + r, point(0).y - (h/2));
			fl_vertex(point(0).x + (w/2) - r, point(0).y - (h/2));
			
			fl_vertex(point(0).x + (w/2), point(0).y - (h/2) + r);
			fl_vertex(point(0).x + (w/2), point(0).y + (h/2) - r);
			
			fl_vertex(point(0).x + (w/2) - r, point(0).y + (h/2));
			fl_vertex(point(0).x - (w/2) + r, point(0).y + (h/2));
			
			fl_vertex(point(0).x - (w/2),     point(0).y + (h/2) - r);
			fl_vertex(point(0).x - (w/2),     point(0).y - (h/2) + r);
					
		fl_end_polygon();

		fl_pie(point(0).x - (w/2),         point(0).y - (h/2),         r+r-1,r+r-1,90,180);
		fl_pie(point(0).x + (w/2) - r - r, point(0).y - (h/2),         r+r-1,r+r-1,0,90);
		fl_pie(point(0).x - (w/2),         point(0).y + (h/2) - r - r, r+r-1,r+r-1,180,270);
		fl_pie(point(0).x + (w/2) - r - r, point(0).y + (h/2) - r - r, r+r-1,r+r-1,270,360);

		fl_color(color().as_int());

	}

	if (color().visibility()){

		fl_color(color().as_int());

		// Draw Lines
		fl_line(point(0).x - (w/2) + r, point(0).y - (h/2),     point(0).x + (w/2) - r, point(0).y - (h/2));
		fl_line(point(0).x - (w/2),     point(0).y - (h/2) + r, point(0).x - (w/2),     point(0).y + (h/2) - r);
		fl_line(point(0).x - (w/2) + r, point(0).y + (h/2),     point(0).x + (w/2) - r, point(0).y + (h/2));
		fl_line(point(0).x + (w/2),     point(0).y - (h/2) + r, point(0).x + (w/2),     point(0).y + (h/2) - r);
		
		// Draw Arcs
		fl_arc(point(0).x - (w/2),         point(0).y - (h/2),         r+r,r+r,90,180);
		fl_arc(point(0).x + (w/2) - r - r, point(0).y - (h/2),         r+r,r+r,0,90);
		fl_arc(point(0).x - (w/2),         point(0).y + (h/2) - r - r, r+r,r+r,180,270);
		fl_arc(point(0).x + (w/2) - r - r, point(0).y + (h/2) - r - r, r+r,r+r,270,360);

	}

}

}