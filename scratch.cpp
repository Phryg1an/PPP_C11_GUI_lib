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

	Vector_ref <Arrow> ae;

	Point cen{500,500};

	// Crazy loop action
	// -----------------

	// for (int i = 250; i < 750; i+=50)
	// {
	// 	ae.push_back(new Arrow(cen,{750,i},20,20));
	// 	win.attach(ae[ae.size()-1]);
	// }
	// for (int i = 750; i > 250; i-=50)
	// {
	// 	ae.push_back(new Arrow(cen,{i,750},20,20));
	// 	win.attach(ae[ae.size()-1]);
	// }
	// for (int i = 750; i > 250; i-=50)
	// {
	// 	ae.push_back(new Arrow(cen,{250,i},20,20));
	// 	win.attach(ae[ae.size()-1]);
	// }
	// for (int i = 250; i < 750; i+=50)
	// {
	// 	ae.push_back(new Arrow(cen,{i,250},20,20));
	// 	win.attach(ae[ae.size()-1]);
	// }
	
	Circle c1({500,500},300);

	Arrow a1(c1.nw(),c1.se(),50,20);
	Arrow a2(c1.sw(),c1.ne(),50,20);
	Arrow a3(c1.nn(),c1.ss(),50,20);
	Arrow a4(c1.ee(),c1.ww(),50,20);

	win.attach(c1);
	win.attach(a1);
	win.attach(a2);
	win.attach(a3);
	win.attach(a4);
	win.wait_for_button();

	// Smiley s1 {cen,250};
	// win.attach(s1);

	// win.wait_for_button();


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}