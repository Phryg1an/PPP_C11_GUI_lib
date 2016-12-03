// Programming: principles and practice 2nd Ed
// Chap 13, Excercise 14

#include "BS_GUI/Simple_window.h"
#include "BS_GUI/Graph.h"
#include "BS_GUI/Right_triangle.h"
#include <stdexcept>
#include <cmath>;



using namespace Graph_lib;

int main()
try
{

	//Set up window
	Point tl{100,100};
	Simple_window win(tl,1000,1000,"Playing about");

	//Make a right triangle
	Right_triangle rt1({300,300},150, 200);

	//Make a right triangle with rotation
	Right_triangle rt2({600,600},150, 200,30);

	// Test fill colour
	rt2.set_fill_color(Color{3});

	win.attach(rt1);
	win.attach(rt2);

	win.wait_for_button();


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}