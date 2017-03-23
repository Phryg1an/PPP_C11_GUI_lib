#include "Right_triangle.h"

namespace Graph_lib {

void Right_triangle::draw_lines() const
{


	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_begin_polygon();

			fl_vertex( point(0).x, point(0).y);
			fl_vertex( c_pointl().x,  c_pointl().y);
			fl_vertex( c_pointr().x,  c_pointr().y);
					
		fl_end_polygon();

		// fl_color(color().as_int());

	}

	if (color().visibility()){

		fl_color(color().as_int());

		// Draw Lines
		fl_line(point(0).x, point(0).y,  c_pointl().x,  c_pointl().y);
		fl_line( c_pointl().x,  c_pointl().y,  c_pointr().x,  c_pointr().y);
		fl_line( c_pointr().x,  c_pointr().y, point(0).x, point(0).y);




	}

}

Point Right_triangle::c_pointr() const
{ 
	return { point(0).x + (int)(cos((double)a * (PI / 180.00)) * (double)s1),
				point(0).y - (int)(sin((double)a * (PI / 180.00)) * (double)s1) }; 
}

Point Right_triangle::c_pointl() const
{ 
	return { point(0).x - (int)(cos((90.00 - (double)a) * (PI / 180.00)) * (double)s2),
				point(0).y - (int)(sin((90.00 - (double)a) * (PI / 180.00)) * (double)s2) }; 
}

}