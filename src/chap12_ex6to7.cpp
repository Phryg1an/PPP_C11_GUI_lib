// Programming: principles and practice 2nd Ed
// Chap 12, Excercises 6 to 7
//
// Code includes code for exercises:
// 6: Windows bigger than the screen
// 7: Drawing a house (oddly therapeutic)

#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>
//#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{

	// ----------------------------------------------------------
	// EXERCISE 6
	// ----------------------------------------------------------

	//An example of a shape being bigger than the window
	//is given in Exercise 5. So here we'll just create a window
	//bigger than the screen..........
	// window with helpful title

	Point tl {100,100};

//	Simple_window win{tl,x_max()+1000,y_max()+1000,"Exercise #6"};

	// pause
//	win.wait_for_button();

	//It's a bit odd in RHEL KDE. The window looks like it maximises
	//to the actual screen size, but the 'Next' button gets squished!

	// ----------------------------------------------------------
	// EXERCISE 7
	// ----------------------------------------------------------

	Simple_window win2{tl,800,800,"Exercise #6"};

	//Create the basic house
	Rectangle house (Point{200,300},400,400);
	house.set_fill_color(72);

	//Let's add some bricks
	Lines bricks;

	for (int i=320;i<700;i+=20)
		bricks.add(Point{200,i},Point{600,i});

	for (int j=300;j<680;j+=40)
	{
		for (int i=250;i<600;i+=50)
			bricks.add(Point{i,j},Point{i,j+20});
		for (int i=225;i<600;i+=50)
			bricks.add(Point{i,j+20},Point{i,j+40});
	}

	//The Roof
	Polygon roof; //a polygon
	roof.add(Point{180,300}); //three points make a triangle
	roof.add(Point{620,300});
	roof.add(Point{400,100});
	roof.set_fill_color(73);

	//A chimney
	Rectangle chimney(Point{230,150},50,150);
	chimney.set_fill_color(0);

	//A Door
	Rectangle door(Point{350,500},100,200);
	door.set_fill_color(0);

	Rectangle doorframe(Point{360,510},80,190);
	doorframe.set_fill_color(1);

	Circle doorknob{Point{425,600},5};
	doorknob.set_fill_color(0);

	//window1
	Rectangle win1_frame(Point{250,350},120,120);
	win1_frame.set_fill_color(0);
	Rectangle win1_frame2(Point{255,355},110,110);
	win1_frame2.set_fill_color(255);

	Lines win1_frame3;
	win1_frame3.add(Point{310,355},Point{310,465});
	win1_frame3.add(Point{255,410},Point{365,410});

	//window2
	Rectangle win2_frame(Point{430,350},120,120);
	win2_frame.set_fill_color(0);
	Rectangle win2_frame2(Point{435,355},110,110);
	win2_frame2.set_fill_color(255);

	Lines win2_frame3;
	win2_frame3.add(Point{490,355},Point{490,465});
	win2_frame3.add(Point{435,410},Point{545,410});

	win2.attach(house);
	win2.attach(bricks);
	win2.attach(chimney);
	win2.attach(roof);

	win2.attach(door);
	win2.attach(doorframe);
	win2.attach(doorknob);

	win2.attach(win1_frame);
	win2.attach(win1_frame2);
	win2.attach(win1_frame3);
	win2.attach(win2_frame);
	win2.attach(win2_frame2);
	win2.attach(win2_frame3);

	//Add some smoke to the chimney
	//note: using a hack of the function struct to 
	//get the sine wave going up
	Function sine {sin,0,25,Point{255,150},1000,15,15,'y'};
	win2.attach(sine);

	win2.wait_for_button();


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}