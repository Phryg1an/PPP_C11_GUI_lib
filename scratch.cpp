// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include "BS_GUI/Simple_window.h"
#include "BS_GUI/Graph.h"
#include <stdexcept>
#include <cmath>;
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	Point tl{100,100};

	Simple_window win(tl,1000,500,"Playing about");

	// Vector_ref<Rectangle>vr;

	// for (int i = 0; i < 16; ++i)
	// 	for (int j = 0; j < 16; ++j) {
	// 		vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
	// 		vr[vr.size()-1].set_fill_color(Color{i*16+j});
	// 		win.attach(vr[vr.size()-1]);
	// 	}


	Arc e1 {Point {400,200}, 150, 50, 0, 90};

	win.attach(e1);
	win.wait_for_button();



}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}