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


	Point arrow_start {130,300};
	Point arrow_tip {250,100};
	Arrow a1 {arrow_start, arrow_tip, 100, 30.0};

	win.attach(a1);

	win.wait_for_button();

	Smiley sm1 {{400,200},50};
	win.attach(sm1);

	win.wait_for_button();
	
	win.detach(a1);
	win.detach(sm1);

	arrow_start = {50,100};
	arrow_tip = {300,91};
	Arrow a2 {arrow_start, arrow_tip, 100, 30.0};
	win.attach(a2);

	win.wait_for_button();

	Smiley sm2 {{400,200},50,0};
	win.attach(sm2);

	win.wait_for_button();

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}