#include "Rectangle.h"

namespace Graph_lib {

void Rectangle::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_rectf(point(0).x,point(0).y,w,h);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {	// edge on top of fill
		fl_color(color().as_int());
		fl_rect(point(0).x,point(0).y,w,h);
	}
}

Point ne(Rectangle &r) {
	return {r.point(0).x + r.width(), r.point(0).y};
}

Point nw(Rectangle &r) { 
	return {r.point(0).x, r.point(0).y}; 
}

Point se(Rectangle &r) { 
	return {r.point(0).x + r.width(), r.point(0).y + r.height()}; 
}

Point sw(Rectangle &r) { 
	return {r.point(0).x, r.point(0).y + r.height()}; 
}

Point nn(Rectangle &r) {
	return {r.point(0).x + (r.width()/2), r.point(0).y}; 
}

Point ee(Rectangle &r) {
	return {r.point(0).x + r.width(), r.point(0).y + (r.height()/2)}; 
}

Point ss(Rectangle &r) {
	return {r.point(0).x + (r.width()/2), r.point(0).y + r.height()}; 
}

Point ww(Rectangle &r) {
	return {r.point(0).x, r.point(0).y + (r.height()/2)}; 
}


}