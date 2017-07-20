#include "Closed_polyline.h"

namespace Graph_lib {

	Closed_polyline::Closed_polyline()
		:Open_polyline() { } // now the constructor is public
	Closed_polyline::Closed_polyline(initializer_list<Point> lst)
		:Open_polyline(lst) { }

	void Closed_polyline::draw_lines() const
	{
		Open_polyline::draw_lines();
			
		if (color().visibility())	// draw closing line:
			fl_line(point(number_of_points()-1).x,point(number_of_points()-1).y,point(0).x,point(0).y);
	}
	
}