// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 8
//
// Code includes code for exercises:
// 8: Olympic Rings

#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{
https://www.google.co.uk/search?q=stack+programming+definition&ie=utf-8&oe=utf-8&gws_rd=cr&ei=eoZ6V5HFJ8uQgAbR_qrIAw
	// ----------------------------------------------------------
	// EXERCISE 8
	// ----------------------------------------------------------

	Point tl{100,100};

	Simple_window win(tl,1000,500,"Olympic");

	//Let's have rings of 50 radius, with 6 pixels inbetween them
	//and a thickness of 10 pixels

	// Let's use a loop with a conditional property
	// to put the circles into a vector ref
	Vector_ref<Circle> olympic;

	for (int i = 200; i<450; i+=58)
		if(olympic.size()%2 == 0)
			olympic.push_back(new Circle(Point{i,200},50));
		else
			olympic.push_back(new Circle(Point{i,260},50));	

	//Manually code in the colors as the fltk color map is
	//not intuitive
	olympic[0].set_color(4);
	olympic[1].set_color(3);
	olympic[2].set_color(0);
	olympic[3].set_color(2);
	olympic[4].set_color(1);

	//Use loop to set line thickness and attach to window
	for (int i = 0; i < olympic.size(); ++i)
	{
		olympic[i].set_style(Line_style(Line_style::solid,10));
		win.attach(olympic[i]);
	}


	win.wait_for_button();


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}