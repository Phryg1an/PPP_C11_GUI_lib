#include "Mandelbrot.h"

namespace Graph_lib {

void Mandelbrot::draw_lines() const
{

	double bin =  4.0 / s;
	int iter = 0;
	double a;
	double b;
	double ait;
	double bit;
	double a_t;

	for (int x = point(0).x; x <= point(0).x + s; x+=1)
	{
		for (int y = point(0).y; y <= point(0).y + s; y+=1)
		{	
			iter = 0;
			a = -2.0 + (bin*(x - point(0).x));
			b = 2.0 - (bin*(y - point(0).y));
			ait = a;
			bit = b;


			while((std::pow(a,2) + std::pow(b,2)) <=  4 && iter < i)
			{
				a_t = std::pow(a,2) - std::pow(b,2);
				b = (2 * a * b) + bit;
				a = a_t + ait;
				iter+=1;
			}

			fl_color(abs(255-iter));
			fl_point(x,y);
			//cout << "X = " << x << ", Y = " << y << std::endl;
		}
	}
}

}