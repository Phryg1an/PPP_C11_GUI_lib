// Programming: principles and practice 2nd Ed
// Chap 12, Excercise 12
//
// Code includes code for exercises:
// 9: Superellipse

#include <stdexcept>
#include <cmath>;

#include "std_lib_facilities.h"

using namespace std;

static const double PI = 3.14159265359;

int main()
try
{
	double hyp;
	int adj;
	double ang;
	double ang2;

	hyp = 100.00;
	adj = 100;
	ang=0.0;
	ang2 = 0.0;
	for (int i=0; i < 100; i+=2)
	{
		adj=adj-2;
		ang = acos((double)adj / hyp) * (180.00 / PI);
		ang2 = hyp * sin(ang*(PI/180.00));
		cout << ang << ' ' << ang2 << '\n';



	// }


}
catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
}