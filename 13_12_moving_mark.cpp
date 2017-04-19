// Programming: principles and practice 2nd Ed
// Chap 13, Excercise 12

#include "Simple_window.h"
#include "Graph.h"
#include "Ellipse.h"
#include <stdexcept>
#include <cmath>;
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace Graph_lib;

//Helper function for generating random point
Point rand_circ_point(int r, int c) {
	return {rand() % (r + r) + (c-r), rand() % (r + r) + (c-r)};
}

int main()
try
{
	//Random point
	Point rPoint;

	//Circle radius
	int radi = 150;

	//Set up window
	Point tl{100,100};
	Simple_window win(tl,1000,1000,"Playing about");

	/* initialize random seed: */
	srand (time(NULL));

	//Make a circle
	Circle c({500,500},150);
	win.attach(c);

	//Set up an initial random mark point
	rPoint = rand_circ_point(radi, c.center().x);

	//Make our initial mark
	Mark m(rPoint,'X');

	while(true){
		//Is our random point inside the circle
		if (c.is_inside(rPoint) == false) { 
			//Recalculate the x and y if not
			rPoint = rand_circ_point(radi, c.center().x);
		}
		else {
			//Attach the Mark if so
			m.set_point(rPoint);
			win.attach(m);
			win.wait_for_button();

			//Recacluate for next movment
			rPoint = rand_circ_point(radi, c.center().x);
			
		}
	}

}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}