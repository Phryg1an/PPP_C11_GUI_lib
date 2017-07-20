// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include "Simple_window.h"
#include "Striped_circle.h"
#include "Striped_closed_polyline.h"
#include <stdexcept>
#include <cmath>;
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	Point tl{100,100};

	Simple_window win(tl,1000,1000,"Playing about");

	Striped_closed_polyline opl1 = {{100,50},{130,70},{180,500},{270,400},{50,800}};
	Striped_closed_polyline opl2 = {{300,50},{500,50},{300,400},{500,400}};

	Striped_circle sc1 = {{400,400}, 200};

	win.attach(opl1);
	win.attach(opl2);
	win.attach(sc1);
	

	win.wait_for_button();

	sc1.set_stripes(10);
	opl1.set_stripes(20);
	win.wait_for_button();

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}