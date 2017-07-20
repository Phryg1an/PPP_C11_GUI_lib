#include "Striped_circle.h"

namespace Graph_lib {

	Striped_circle::Striped_circle(Point p, int rr, int ss = 4)
		:s{ ss }, Circle(p, rr) {}
		

	void Striped_circle::draw_lines() const
	{
		Circle::draw_lines();

		double diff;

		for (int x = 0; x <= r; x+=s)
		{

			//Get y differential
			diff =  (double)radius() * sin((acos((double)x / (double)radius()) * (180.00 / PI)) * (PI / 180.00));

			//Make stripes
			fl_line(center().x + x, center().y - (int)diff, center().x + x, center().y + (int)diff);
			fl_line(center().x - x, center().y - (int)diff, center().x - x, center().y + (int)diff);
		}
	}
}