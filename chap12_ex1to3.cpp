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
	Simple_window win{tl,1000,500,"Exercise #1"};

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

	// A working version with iterative creation of the grid.

	Vector_ref<Rectangle> vr;

	for(int y = 1; y<4; ++y){
		for (int x = 5; x < 8; ++x){
			vr.push_back(new Rectangle(Point(x*100,y*100),100,100));
			if((y+x)%2==0)
				vr[vr.size()-1].set_fill_color(1);
			else
				vr[vr.size()-1].set_fill_color(255);
				
			win.attach(vr[vr.size()-1]);

		}
	}

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