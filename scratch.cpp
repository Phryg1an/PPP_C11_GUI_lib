// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include "BS_GUI/Simple_window.h"
#include "BS_GUI/Graph.h"
#include "BS_GUI/Regular_hexagon.h"
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

	Point cen{500,500};

	Regular_hexagon h1(cen,200);

	h1.set_fill_color(Color::green);

	win.attach(h1);


	SoftBox s1(cen,200,100,20);

	s1.set_fill_color(Color::blue);

	win.attach(s1);

	win.wait_for_button();

	h1.set_fill_color(Color::blue);
	s1.set_fill_color(Color::green);

	win.wait_for_button();	

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}