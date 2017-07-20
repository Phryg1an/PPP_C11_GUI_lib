#include "Function.h"

namespace Graph_lib {


	Function::Function(Fct f, double r1, double r2, Point xy, int count, double xscale, double yscale, char direction)
	// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
	// x coordinates are scaled by xscale and y coordinates scaled by yscale
	{
		if (r2-r1<=0) error("bad graphing range");
		if (count<=0) error("non-positive graphing count");
		double dist = (r2-r1)/count;
		double r = r1;
		for (int i = 0; i<count; ++i) {
			//	Default direction is always x. Any other character (such as 'y'!) plots function
			//	up the y axis
			if (direction=='x')
				add(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
			else
				add(Point(xy.x+int(f(r)*xscale),xy.y-int(r*yscale)));		 
			r += dist;
		}
	}

}