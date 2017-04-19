// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include "Simple_window.h"
#include "Graph.h"
#include "Ellipse.h"
#include <stdexcept>
#include <cmath>;
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	Point tl{100,100};

	Simple_window win(tl,1000,1000,"Playing about");

	//Make an ellipse
	Ellipse e({500,500},150,100);

	//Make some axes
	Axis xa{Axis::x,{e.center().x - 200,500 }, 400, 10};
	Axis ya{Axis::y,{500,e.center().y + 150 }, 300, 10};

	//Mark the foci
	Mark m1(e.focus1(),'X');
	Mark m2(e.focus2(),'X');

	//Mark a (not really) random point
	Mark m3(e.ne(),'X');

	//Connect the foci to the point with lines
	Line l1 (e.focus1(),e.ne());
	Line l2 (e.focus2(),e.ne());


	win.attach(e);
	win.attach(xa);
	win.attach(ya);
	win.attach(m1);
	win.attach(m2);
	win.attach(m3);
	win.attach(l1);
	win.attach(l2);
	int xdiff = e.cdiffx();
	int ydiff = e.cdiffy();
	std::cout << xdiff << ' ' << ydiff << '\n';
	win.wait_for_button();	

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}