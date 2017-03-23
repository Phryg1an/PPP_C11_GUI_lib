//#include "Graph.h"
#include "Arrow.h"

//#include <map>

namespace Graph_lib {

void Arrow::draw_lines() const
{


	double a1;
	double a2;
	int p3x;
	int p3y;
	int p4x;
	int p4y;

	if (color().visibility()){

		// Draw arrow line
		fl_line(point(0).x, point(0).y, point(1).x, point(1).y) ;

		// Get outer angles for arrowhead
		a1 = atan((double)(point(0).y - point(1).y) / (double)(point(1).x - point(0).x)) * (180.00 / PI);
		a2 = 90.00 - a1;

		p3x = (int)((double)l * (cos((a1 - a) * (PI / 180.00))));
		p3y = (int)((double)l * (sin((a1 - a) * (PI / 180.00))));

		p4x = (int)((double)l * (sin((a2 - a) * (PI / 180.00))));
		p4y = (int)((double)l * (cos((a2 - a) * (PI / 180.00))));

		// Add arrowheads
		// Extra handling to deal with arrow direction
		if (point(0).x <= point(1).x) {
			fl_line(point(1).x, point(1).y, point(1).x - p3x, point(1).y + p3y);
			fl_line(point(1).x, point(1).y, point(1).x - p4x, point(1).y + p4y);
		}
		else {
			fl_line(point(1).x, point(1).y, point(1).x + p3x, point(1).y - p3y);
			fl_line(point(1).x, point(1).y, point(1).x + p4x, point(1).y - p4y);			
		}

	}

}



}