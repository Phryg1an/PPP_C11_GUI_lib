#include "Open_polyline.h"

namespace Graph_lib {


	void Open_polyline::draw_lines() const
	{
			if (fill_color().visibility()) {
				fl_color(fill_color().as_int());
				fl_begin_complex_polygon();
				for(int i=0; i<number_of_points(); ++i){
					fl_vertex(point(i).x, point(i).y);
				}
				fl_end_complex_polygon();
				fl_color(color().as_int());	// reset color
			}
			
			if (color().visibility())
				Shape::draw_lines();
	}

	void draw_mark(Point xy, char c)
	{
		static const int dx = 4;
		static const int dy = 4;
		string m(1,c);
		fl_draw(m.c_str(),xy.x-dx,xy.y+dy);
	}

	void Marked_polyline::draw_lines() const
	{
		Open_polyline::draw_lines();
		for (int i=0; i<number_of_points(); ++i) 
			draw_mark(point(i),mark[i%mark.size()]);
	}

}