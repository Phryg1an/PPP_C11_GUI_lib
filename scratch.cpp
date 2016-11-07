// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include "BS_GUI/Simple_window.h"
#include "BS_GUI/Graph.h"
#include "BS_GUI/Regular_hexagon.h"
#include "BS_GUI/Regular_polygon.h"
#include "BS_GUI/Arrow.h"
#include <stdexcept>
#include <cmath>;
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	Point tl{100,100};

	Simple_window win(tl,1000,1000,"Playing about");

	int s = 6;
	int w = 250;
	Point cen{500,500};
	Regular_polygon rp {cen,s,w,};
	rp.set_fill_color(Color::green);
	rp.set_color(Color::red);
	// Point a1{891, 188};
	// Point a2{987, 611};
	// Point a3{717, 950};
	// Point a4{283, 950};
	// Point a5{13, 611};
	// Point a6{109, 188};

	// Line l1 (a1,a2);
	// Line l2 (a2,a3);
	// Line l3 (a3,a4);
	// Line l4 (a4,a5);
	// Line l5 (a5,a6);
	// Line l6 (a6,a1);

	// win.attach(l1);
	// win.attach(l2);
	// win.attach(l3);
	// win.attach(l4);
	// win.attach(l5);
	// win.attach(l6);

	// int x;
	// int y;
	// string oout;
	// Text t1({500,500},"");

	// for (int i = 1; i < 7; i++){

	// 	x = (int)std::round(cen.x + w * (cos(2.0*PI*(double)i/(double)s)));
	// 	y = (int)std::round(cen.x + w * (sin(2.0*PI*(double)i/(double)s)));
	// 	oout = "x: " + std::to_string(x) + " y: " + std::to_string(y);
	// 	t1.set_label(oout);
	// 	win.attach(t1);
	// 	win.wait_for_button();

	// 			// point(0).x + w * (int)(cos(2.0*PI*(double)(i+1)/(double)s)),
	// 			// point(0).y + w * (int)(sin(2.0*PI*(double)(i+1)/(double)s)));


	// 	}


	win.attach(rp);

	// Regular_hexagon rh {{500,500},50};
	// win.attach(rh);
	win.wait_for_button();	

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}