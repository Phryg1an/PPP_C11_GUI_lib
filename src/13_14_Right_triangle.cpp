// Programming: principles and practice 2nd Ed
// Chap 13, Excercise 14

#include "Simple_window.h"
#include "Graph.h"
#include "Right_triangle.h"
#include <stdexcept>
#include <stdlib.h>     /* srand, rand */
#include <cmath>
#include <time.h>       /* time */



using namespace Graph_lib;

int main()
try
{

	//Set up window
	Point tl{100,100};
	Simple_window win(tl,1000,1000,"Iris");

	/* initialize random seed: */
	srand (time(NULL));

	// Use vector ref again for easy making colours
	Vector_ref <Right_triangle> rt;

	int side = 200;
	Point start{200,200};

	//Make a right triangle
	rt.push_back(new Right_triangle(start, side, side, 225));
	rt.push_back(new Right_triangle({rt[0].c_point().x + side, start.y}, side, side, 180));
	rt.push_back(new Right_triangle({rt[0].c_pointl().x + side, rt[0].c_pointl().y}, side, side, 135));
	rt.push_back(new Right_triangle({rt[2].c_point().x, rt[2].c_point().y + side}, side, side, 90));
	rt.push_back(new Right_triangle({rt[2].c_pointl().x, rt[2].c_pointl().y + side}, side, side, 45));
	rt.push_back(new Right_triangle({start.x, rt[4].c_point().y}, side, side));
	rt.push_back(new Right_triangle({rt[0].c_pointr().x, rt[0].c_pointr().y + side}, side, side, 315));
	rt.push_back(new Right_triangle({rt[0].c_pointr().x, rt[0].c_pointr().y}, side, side, 270));


	for (int y = 0; y < rt.size(); y+=1) {
		rt[y].set_color(rand() % 255);
		rt[y].set_fill_color(rand() % 255);
		win.attach(rt[y]);

	}

	win.wait_for_button();	

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}