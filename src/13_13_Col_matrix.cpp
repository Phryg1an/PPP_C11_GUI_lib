// Programming: principles and practice 2nd Ed
// Chap 13, Excercise 12

#include "BS_GUI/Simple_window.h"
#include "BS_GUI/Graph.h"
#include "BS_GUI/Ellipse.h"
#include <stdexcept>
#include <cmath>;



using namespace Graph_lib;

int main()
try
{
	Vector_ref<Rectangle> vr;

	Point tl{100,100};
	Simple_window win(tl,1000,1000,"Playing about");

	for(int i=0; i < 16; ++i) {
		for (int j=0; j<16; ++j) {
			vr.push_back(new Rectangle(Point{i*20,j*20},20,20));
			vr[vr.size()-1].set_fill_color(Color{i*16+j});
			vr[vr.size()-1].set_color(Color::invisible);
			win.attach(vr[vr.size()-1]);
		}
	}
	
	win.wait_for_button();


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}