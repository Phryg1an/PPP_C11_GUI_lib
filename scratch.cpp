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

	for (int i = 250; i < 750; i+=50)
	{
		ae.push_back(new Arrow(cen,{750,i},20,20));
		win.attach(ae[ae.size()-1]);
	}
	for (int i = 750; i > 250; i-=50)
	{
		ae.push_back(new Arrow(cen,{i,750},20,20));
		win.attach(ae[ae.size()-1]);
	}
	for (int i = 750; i > 250; i-=50)
	{
		ae.push_back(new Arrow(cen,{250,i},20,20));
		win.attach(ae[ae.size()-1]);
	}
	for (int i = 250; i < 750; i+=50)
	{
		ae.push_back(new Arrow(cen,{i,250},20,20));
		win.attach(ae[ae.size()-1]);
	}
	// Arrow a1{cen,{750,250},50,20};
	// Arrow a2{cen,{750,300},50,20};
	// Arrow a3{cen,{750,350},50,20};
	// Arrow a3{cen,{750,400},50,20};
	// Arrow a3{cen,{750,450},50,20};
	// Arrow a3{cen,{750,500},50,20};

	// Arrow a4{cen,{100,100},50,20};
	// Arrow a5{{200,300},{200,100},50,20};
	// Arrow a6{{100,300},{300,100},50,20};

	// Arrow a7{{100,200},{300,200},50,20};
	// Arrow a8{{300,200},{100,200},50,20};

	// win.attach(a1);	
	// win.attach(a2);
	// win.attach(a3);
	// win.attach(a4);
	// win.attach(a5);
	// win.attach(a6);
	// win.attach(a7);
	// win.attach(a8);

	win.wait_for_button();


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}