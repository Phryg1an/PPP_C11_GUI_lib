// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>
#include <cmath>;
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{
	// ----------------------------------------------------------
	// EXERCISE 12
	// ----------------------------------------------------------

	Point tl{100,100};

	Simple_window win(tl,1600,800,"Super-ellipse");

	// Using a new function declared / defined in Graph

	Vector_ref <Superellipse> se;

	// Crazy loop action
	// -----------------
	for (double a = 0.5; a < 3.5; a+=0.5) // Cycle a from 0.5 to 3
	{
		for (double b = 0.5; b < 3.5; b+=0.5) // Cycle b from 0.5 to 3
		{
			double m = 0.5;

			for (int y = 200; y < win.y_max() ; y += 400) // Plot down y
			{
				double n = 0.5;

				for (int x = 200; x < win.x_max(); x+=400) // Plot across x
				{
					se.push_back(new Superellipse(a,b,m,n,Point{x,y},800,200,3));
					se[se.size()-1].set_color(se.size()-1);
					win.attach(se[se.size()-1]);	
					n += 0.5;
				}
			}

			m += 0.5;
		}
	}

	win.wait_for_button();


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}