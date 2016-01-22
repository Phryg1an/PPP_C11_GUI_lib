// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 1
//
// Code includes code for exercises:
// 1: Rectangles vs Polygons
// 2: Rectangles with text in them

#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	// ----------------------------------------------------------
	// EXERCISE 1
	// ----------------------------------------------------------
	// top left corner of window
	Point tl {100,100};

	// window with helpful title
	Simple_window win{tl,1000,400,"Exercise #1"};

	// set up a rectangle. easy
	Rectangle r (Point{100,100}, 100, 50);
	r.set_color(Color::blue);

	// set up a polygon as a rectangle. pain
	Polygon p;
	p.add(Point{300,100});
	p.add(Point{400,100});
	p.add(Point{400,150});	
	p.add(Point{300,150});
	p.set_color(Color::red);

	// attach to window
	win.attach(r);
	win.attach(p);

	// pause
	win.wait_for_button();

	// ----------------------------------------------------------
	// EXERCISE 2
	// ----------------------------------------------------------bv

	Rectangle r2 (Point{200,300},100,30);

	Text t {Point{220, 320}, "Howdy!"};

	win.attach(r2);
	win.attach(t);

	win.set_label("Exercise #2");
	win.wait_for_button();

	// ----------------------------------------------------------
	// EXERCISE 3
	// ----------------------------------------------------------

	// I tried to do this by making an array
	// of Rectangle and looping through the
	// struct creation. Unfortunatly,
	// it didn't work, so here is the verbose version...
	Rectangle r3 (Point{500,100},50,50);
	Rectangle r4 (Point{550,100},50,50);
	Rectangle r5 (Point{600,100},50,50);
	Rectangle r6 (Point{500,150},50,50);
	Rectangle r7 (Point{550,150},50,50);
	Rectangle r8 (Point{600,150},50,50);
	Rectangle r9 (Point{500,200},50,50);
	Rectangle r10 (Point{550,200},50,50);
	Rectangle r11 (Point{600,200},50,50);	

	r3.set_fill_color(Color::red);
	r4.set_fill_color(Color::white);
	r5.set_fill_color(Color::red);
	r6.set_fill_color(Color::white);
	r7.set_fill_color(Color::red);
	r8.set_fill_color(Color::white);
	r9.set_fill_color(Color::red);
	r10.set_fill_color(Color::white);
	r11.set_fill_color(Color::red);

	win.attach(r3);
	win.attach(r4);
	win.attach(r5);
	win.attach(r6);
	win.attach(r7);
	win.attach(r8);
	win.attach(r9);
	win.attach(r10);
	win.attach(r11);

	win.set_label("Exercise #3");
	win.wait_for_button();

	// ----------------------------------------------------------
	// EXERCISE 3
	// ----------------------------------------------------------

	//Rectangle r12 (Point{100,100},(x_max()/3)*2,(y_max()/4)*3);



}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}