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

Point Rectangle::ne() const {
	return {point(0).x + width(), point(0).y};
}

Point Rectangle::nw() const { 
	return {point(0).x, point(0).y}; 
}

Point Rectangle::se() const { 
	return {point(0).x + width(), point(0).y + height()}; 
}

Point Rectangle::sw() const { 
	return {point(0).x, point(0).y + height()}; 
}

Point Rectangle::nn() const {
	return {point(0).x + (width()/2), point(0).y}; 
}

Point Rectangle::ee() const {
	return {point(0).x + width(), point(0).y + (height()/2)}; 
}

Point Rectangle::ss() const {
	return {point(0).x + (width()/2), point(0).y + height()}; 
}

Point Rectangle::ww() const {
	return {point(0).x, point(0).y + (height()/2)}; 
}


}