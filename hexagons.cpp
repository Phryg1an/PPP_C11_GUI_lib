// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include "BS_GUI/Simple_window.h"
#include "BS_GUI/Graph.h"
#include "BS_GUI/Regular_hexagon.h"
#include "BS_GUI/Arrow.h"
#include <stdexcept>
#include <cmath>;
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	Point tl{100,100};

	Simple_window win(tl,1000,1000,"Playing about");

	Vector_ref <Regular_hexagon> rh;

	int width = 50;
	int y_off = (int)((double)width * (cos((30.0) * (PI / 180.00))));
	int x_start = 0;

	for (int y = 0; y < 1000; y+=(y_off)) {

		for (int x = x_start; x < 1000; x+=150) {
			rh.push_back(new Regular_hexagon({x,y},width));
			rh[rh.size()-1].set_color(rh.size()-1);
			rh[rh.size()-1].set_fill_color(rh.size()-4);
			win.attach(rh[rh.size()-1]);
		}

		if (x_start == 0) {
			x_start+=(width+(width/2));
		}
		else {
			x_start = 0;
		}

	}


	win.wait_for_button();	

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}