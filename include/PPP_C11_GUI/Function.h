#ifndef FUNCTION_GUARD
#define FUNCTION_GUARD 1

#include "Graph.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

typedef double Fct(double);

struct Function : Shape {
	// the function parameters are not stored
	//	Modified to allow char variable to determine which axis funtion is plot against
	//	with default being x
	Function(Fct f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25, char direction = 'x');
	//Function(Point orig, Fct f, double r1, double r2, int count, double xscale = 1, double yscale = 1);	
};

}
#endif