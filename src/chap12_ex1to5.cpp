// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 1 to 5
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

	Text i1 (Point{100,200},"E");
	Text i2 (Point{200,200},"A");
	Text i3 (Point{300,200},"G");

	i1.set_font_size(150);
	i2.set_font_size(150);	
	i3.set_font_size(150);

	i1.set_color(1);
	i2.set_color(50);
	i3.set_color(150);

	win.attach(i1);
	win.attach(i2);
	win.attach(i3);

	win.set_label("Exercise #3");
	win.wait_for_button();

	// ----------------------------------------------------------
	// EXERCISE 4
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

	win.set_label("Exercise #4");
	win.wait_for_button();

	// ----------------------------------------------------------
	// EXERCISE 5
	// ----------------------------------------------------------
	// top left corner of window
	//Point tl {100,100};

	// window with helpful title
	Simple_window win{tl,1000,500,"Exercise #5"};

	//Get the width and height of the screen
	int x_size = x_max();
	int y_size = y_max();

	Rectangle r (Point{150,150},(x_size/3)*2,(y_size/4)*3);

	r.set_color(Color::red);
	
	//using magic number as don't know how to find DPI
	//in code
	//for reference, works on 1600*900 pixel monitor
	//(423x238 mm) - 24 pixels makes 1/4"
	r.set_style(Line_style(Line_style::solid,24)); 
	win.attach(r);

	// pause
	win.wait_for_button();

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}