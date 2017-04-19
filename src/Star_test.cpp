// Programming: principles and practice 2nd Ed
// Chap 13, Excercise 12

#include "Simple_window.h"
#include "Star.h"
#include "Ellipse.h"
#include <stdexcept>
#include <cmath>;
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace Graph_lib;

//Helper function for generating random point
Point rand_circ_point(int r, int c) {
	//Point P{{rand() % (r + r) + (c-r), rand() % (r + r) + (c-r)};
	return {rand() % (r + r) + (c-r), rand() % (r + r) + (c-r)};
}

int main()
try
{
	

	//Set up window
	Point tl{100,100};
	Simple_window win(tl,1000,1000,"Playing about");

	Point c{300,300};
	//Stars!
	Star s1({200,200}, 5, 100);
	Star s2({400,200}, 6, 100);
	Star s3({600,200}, 7, 100);
	Star s4({800,200}, 8, 100);
	Star s5({200,500}, 9, 100);
	Star s6({400,500}, 10, 100);
	Star s7({600,500}, 11, 100);
	Star s8({800,500}, 12, 100);

	win.attach(s1);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.attach(s6);
	win.attach(s7);
	win.attach(s8);
	win.wait_for_button();


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}