#include "Circle.h"

namespace Graph_lib {

void Circle::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,r+r-1,r+r-1,0,360);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	}
}

Point ne(Circle &c) { 
	return {c.center().x + (int)((double)c.radius() * (sin(45.0 * (PI / 180.00)))), 
			c.center().y - (int)((double)c.radius() * (cos(45.0 * (PI / 180.00))))}; 
}

Point nw(Circle &c) {
	return {c.center().x - (int)((double)c.radius() * (sin(45.0 * (PI / 180.00)))),
			c.center().y - (int)((double)c.radius() * (cos(45.0 * (PI / 180.00))))};
}

Point se(Circle &c) {
	return {c.center().x + (int)((double)c.radius() * (sin(45.0 * (PI / 180.00)))),
			c.center().y + (int)((double)c.radius() * (cos(45.0 * (PI / 180.00))))};
}

Point sw(Circle &c) { 
	return {c.center().x - (int)((double)c.radius() * (sin(45.0 * (PI / 180.00)))),
			c.center().y + (int)((double)c.radius() * (cos(45.0 * (PI / 180.00))))};
}

Point nn(Circle &c) { 
	return {c.center().x, c.center().x - c.radius()}; 
}

Point ee(Circle &c) { 
	return {c.center().x + c.radius(), c.center().y};
}

Point ss(Circle &c) { 
	return {c.center().x, c.center().y + c.radius()}; 
}

Point ww(Circle &c) { 
	return {c.center().x - c.radius(), c.center().y};
}

}

