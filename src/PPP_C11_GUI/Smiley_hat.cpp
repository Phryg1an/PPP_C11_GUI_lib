#include "Smiley_hat.h"

namespace Graph_lib {

Smiley_hat::Smiley_hat(Point pp, int rr)
	:Smiley(pp, rr) {}

void Smiley_hat::draw_lines() const
{
	Smiley::draw_lines();

//	Rectangle h1(center(),radius()*2,radius());
	//Hat
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_rectf(center().x - r,center().y - ((r/6)*7),r*2,r/2);

		fl_begin_polygon();

			fl_vertex( center().x - ((r/3)*2), center().y - ((r/6)*7));
			fl_vertex( center().x,  center().y - ((r/6)*11));
			fl_vertex( center().x + ((r/3)*2),  center().y - ((r/6)*7));
					
		fl_end_polygon();

		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {	// edge on top of fill
		fl_color(color().as_int());
		fl_rect(center().x - r,center().y - ((r/6)*7),r*2,r/2);

		// Draw Lines
		fl_line(center().x - ((r/3)*2), center().y - ((r/6)*7), center().x,  center().y - ((r/6)*11) );
		fl_line( center().x,  center().y - ((r/6)*11),  center().x + ((r/3)*2),  center().y - ((r/6)*7));
		fl_line( center().x + ((r/3)*2),  center().y - ((r/6)*7), center().x - ((r/3)*2), center().y - ((r/6)*7));

	}

}

}
