//Demo script to show Bjarne's GUI library in action
//
//19th January 2015

//#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

// int main()
// {
// 	using namespace Graph_lib;

// 	Graph_lib::Point tl {100, 100};

// 	Simple_window win {tl,600,400,"Canvas"};

// 	Polygon poly;

// 	poly.add(Graph_lib::Point{300,200});
// 	poly.add(Graph_lib::Point{350,100});
// 	poly.add(Graph_lib::Point{400,200});

// 	poly.set_color(Color::red);

// 	win.attach(poly);

// 	win.wait_for_button();
// }

using namespace Graph_lib;

int main()
try
{
	Point tl {100,100}; //top left corner of our window

	Simple_window win {tl,600,400,"Canvas"};
	//screen co-ordinate tl for top left corner
	//window size (600*400)
	//title: Canvas

	win.wait_for_button(); // display!

	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
	//an axis is a kind of shape
	//Axis::x means horizontal
	//starting at (20,300)
	//280 pixels long
	//10 'notches'
	//label the axis 'x axis'

	win.attach(xa); //attach xa to the window, win
	win.set_label("Canvas #2"); //relabel the window
	win.wait_for_button(); //display!

	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::cyan); //choose a color
	ya.label.set_color(Color::dark_red); //choose a color for the text
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button(); //display!

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}