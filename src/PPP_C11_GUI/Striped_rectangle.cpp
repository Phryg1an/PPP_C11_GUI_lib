#include "Striped_rectangle.h"

namespace Graph_lib {

	Striped_rectangle::Striped_rectangle(Point p, int ww, int hh)
		:Rectangle(p, ww, hh) {}

	Striped_rectangle::Striped_rectangle(Point p, Point y)
		:Rectangle(p, y) {}

	void Striped_rectangle::draw_lines() const
	{
		Rectangle::draw_lines();

		for (int x = point(0).x + 4; x < point(0).x + width(); x+=4)
		{
			fl_line(x, point(0).y, x, point(0).y + height() - 1);
			std::cout << height() + point(0).y << '\n';
		}
	}
}