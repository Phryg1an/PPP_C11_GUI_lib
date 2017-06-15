// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include "Simple_window.h"
#include "Graph.h"
#include "Regular_hexagon.h"
#include "Regular_polygon.h"
#include "Arrow.h"
#include "Circle.h"
#include "Frowny.h"
#include "Smiley_hat.h"
#include "Frowny_hat.h"
#include "Striped_rectangle.h"
#include "Striped_circle.h"
#include "Immobile_Circle.h"
#include <stdexcept>
#include <cmath>;
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	Point tl{100,100};

	Simple_window win(tl,1000,1000,"Playing about");

	Point middle(500,500);
	Striped_circle c(middle,400);
	win.attach(c);
	win.wait_for_button();
}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}