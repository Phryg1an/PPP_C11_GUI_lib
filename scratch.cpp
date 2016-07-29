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

	Simple_window win(tl,1000,1000,"Playing about");

	Point cen{500,500};

	SoftBox sb1(cen,300,200,20);
	//Rectangle r1(cen,400,300);

	// Arrow a1(r1.center(), ne(r1),20,20);
	// Arrow a2(r1.center(), nw(r1),20,20);
	// Arrow a3(r1.center(), se(r1),20,20);
	// Arrow a4(r1.center(), sw(r1),20,20);
	// Arrow a5(r1.center(), nn(r1),20,20);
	// Arrow a6(r1.center(), ss(r1),20,20);
	// Arrow a7(r1.center(), ww(r1),20,20);
	// Arrow a8(r1.center(), ee(r1),20,20);

	// win.attach(a1);
	// win.attach(a2);
	// win.attach(a3);
	// win.attach(a4);
	// win.attach(a5);
	// win.attach(a6);
	// win.attach(a7);
	// win.attach(a8);


	//win.attach(r1);
	win.attach(sb1);

	win.wait_for_button();


	//r1.set_fill_color(Color::blue);
	sb1.set_fill_color(Color::blue);

	win.wait_for_button();

	sb1.set_color(Color::green);

	win.wait_for_button();
}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}