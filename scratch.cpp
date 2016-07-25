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
	
	// Ellipse e1(cen, 100,400);
	// Arrow a1(cen,e1.ne(),20,20);
	// Arrow a2(cen,e1.nn(),20,20);
	// Arrow a3(cen,e1.nw(),20,20);
	// Arrow a4(cen,e1.ww(),20,20);
	// Arrow a5(cen,e1.sw(),20,20);
	// Arrow a6(cen,e1.ss(),20,20);
	// Arrow a7(cen,e1.se(),20,20);
	// Arrow a8(cen,e1.ee(),20,20);

	// e1.set_color(Color::red);
	// a1.set_color(Color::red);
	// a2.set_color(Color::red);
	// a3.set_color(Color::red);
	// a4.set_color(Color::red);
	// a5.set_color(Color::red);
	// a6.set_color(Color::red);
	// a7.set_color(Color::red);
	// a8.set_color(Color::red);

	// win.attach(e1);
	// win.attach(a1);
	// win.attach(a2);
	// win.attach(a3);
	// win.attach(a4);
	// win.attach(a5);
	// win.attach(a6);
	// win.attach(a7);
	// win.attach(a8);

	// win.wait_for_button();


	// Ellipse e2(cen, 400,100);
	// Arrow b1(cen,e2.ne(),20,20);
	// Arrow b2(cen,e2.nn(),20,20);
	// Arrow b3(cen,e2.nw(),20,20);
	// Arrow b4(cen,e2.ww(),20,20);
	// Arrow b5(cen,e2.sw(),20,20);
	// Arrow b6(cen,e2.ss(),20,20);
	// Arrow b7(cen,e2.se(),20,20);
	// Arrow b8(cen,e2.ee(),20,20);

	// e2.set_color(Color::blue);
	// b1.set_color(Color::blue);
	// b2.set_color(Color::blue);
	// b3.set_color(Color::blue);
	// b4.set_color(Color::blue);
	// b5.set_color(Color::blue);
	// b6.set_color(Color::blue);
	// b7.set_color(Color::blue);
	// b8.set_color(Color::blue);



	// win.attach(e2);
	// win.attach(b1);
	// win.attach(b2);
	// win.attach(b3);
	// win.attach(b4);
	// win.attach(b5);
	// win.attach(b6);
	// win.attach(b7);
	// win.attach(b8);


	// win.wait_for_button();

	// Smiley s1 {{500,500},250};
	// s1.set_color(Color::dark_green);
	// win.attach(s1);

	// win.wait_for_button();

	Rectangle r1 (cen,400,200);
	Arrow a1(r1.center(), ne(r1),20,20);
	Arrow a2(r1.center(), nw(r1),20,20);
	Arrow a3(r1.center(), se(r1),20,20);
	Arrow a4(r1.center(), sw(r1),20,20);
	Arrow a5(r1.center(), nn(r1),20,20);
	Arrow a6(r1.center(), ss(r1),20,20);
	Arrow a7(r1.center(), ww(r1),20,20);
	Arrow a8(r1.center(), ee(r1),20,20);
	win.attach(r1);
	win.attach(a1);
	win.attach(a2);
	win.attach(a3);
	win.attach(a4);
	win.attach(a5);
	win.attach(a6);
	win.attach(a7);
	win.attach(a8);

	win.wait_for_button();

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}