#include "Star.h"

namespace Graph_lib {

Star::Star(Point cen, int pp, int ww, int aa)
	:p( pp ), a( aa ), w( ww )
{
	add(Point {cen.x, cen.y});
	for (int i = 1; i < p + 1; i++){
		add(Point{(int)std::round(point(0).x + w * (cos(2.0*PI*(double)i/(double)p + ar))),
			(int)std::round(point(0).y + w * (sin(2.0*PI*(double)i/(double)p + ar)))});
	}


}

void Star::draw_lines() const
{


	if (color().visibility()){

		fl_color(color().as_int());

		int j1;
		int j2;

		if (p % 2 == 0) { 
			j1 = (p / 2) - 1; 
			j2 = (p / 2) + 1; 
		}
		else {
			j1 = (p - 1) / 2;
			j2 = (p + 1) / 2;			 
		}


		for (int i = 1; i < p + 1; i++){

			if (i+j1 < p + 1 )
			{
				fl_line(point(i).x, point(i).y,
						point(i+j1).x, point(i+j1).y);
				cout << "i = " << i << ", i+j1 = " << i + j1 << '\n';
			}
			else
			{
				fl_line(point(i).x, point(i).y,
						point(i-j2).x, point(i-j2).y);
			cout << "i = " << i << ", i-j2 = " << i-j2 << '\n';
			}



		}

	}


}

}