// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 15
//
// Code includes code for exercises:
// Tile a screen with right triangles

#include "BS_GUI/Simple_window.h"
#include "BS_GUI/Graph.h"
#include "BS_GUI/Right_triangle.h"
#include "BS_GUI/Arrow.h"
#include <stdexcept>
#include <cmath>;
#include <stdlib.h>     /* srand, rand */
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	Point tl{100,100};

	Simple_window win(tl,1000,1000,"Right Triangles");

	Vector_ref <Right_triangle> rt;

	int side1 = 50;
	int side2 = 80;

	for (int y = 0; y < 1000; y+=side2) {

		for (int x = 0; x < 1000; x+=side1) {
			rt.push_back(new Right_triangle({x,y+side2},side1,side2));
			rt[rt.size()-1].set_color(rand() % 255);
			rt[rt.size()-1].set_fill_color(rand() % 255);
			win.attach(rt[rt.size()-1]);

			rt.push_back(new Right_triangle({x+side1,y},side1,side2,180));
			rt[rt.size()-1].set_color(rand() % 255);
			rt[rt.size()-1].set_fill_color(rand() % 255);
			win.attach(rt[rt.size()-1]);
		}

	}

	win.wait_for_button();	

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
} 