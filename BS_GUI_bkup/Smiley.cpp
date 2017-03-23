#include "Smiley.h"

namespace Graph_lib {

void Smiley::draw_lines() const
{
	Circle::draw_lines();
		
	//Eyes
	fl_arc(point(0).x + ((r/5)*3),point(0).y + (r / 2),r/5,r/5,0,360);
	fl_arc(point(0).x + ((r/5)*6),point(0).y + (r / 2),r/5,r/5,0,360);

	//Mouth
	fl_arc(point(0).x + (r / 2),point(0).y + (r / 3) * 2,r,r,180,360);

	}

}
