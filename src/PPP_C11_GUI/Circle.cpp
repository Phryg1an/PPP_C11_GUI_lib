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

Point Circle::ne() const
{ 
	return {center().x + (int)((double)r * (sin(45.0 * (PI / 180.00)))), 
			center().y - (int)((double)r * (cos(45.0 * (PI / 180.00))))}; 
}

Point Circle::nw() const
{
	return {center().x - (int)((double)r * (sin(45.0 * (PI / 180.00)))),
			center().y - (int)((double)r * (cos(45.0 * (PI / 180.00))))};
}

Point Circle::se() const
{
	return {center().x + (int)((double)r * (sin(45.0 * (PI / 180.00)))),
			center().y + (int)((double)r * (cos(45.0 * (PI / 180.00))))};
}

Point Circle::sw() const
{ 
	return {center().x - (int)((double)r * (sin(45.0 * (PI / 180.00)))),
			center().y + (int)((double)r * (cos(45.0 * (PI / 180.00))))};
}

Point Circle::nn() const
{ 
	return {center().x, center().x - r}; 
}

Point Circle::ee() const
{ 
	return {center().x + r, center().y};
}

Point Circle::ss() const
{ 
	return {center().x, center().y + r}; 
}

Point Circle::ww() const
{ 
	return {center().x - r, center().y};
}

Bool Circle::is_inside(Point &ii) const {
	if ( std::sqrt(std::pow(ii.x - center().x,2)  + std::pow(ii.y - center().y,2)) > r) return false;

	return true;
}

Bool Circle::is_inside(int &x, int &y) const {
	if ( std::sqrt(std::pow(x - center().x,2)  + std::pow(y - center().y,2)) > r) return false;

	return true;
}

}

