#include "Ellipse.h"

namespace Graph_lib {

void Ellipse::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,w+w-1,h+h-1,0,360);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,w+w,h+h,0,360);
	}
}

double Ellipse::get_corner_angle() const
{
	// Work out what the angle to the corner should be by
	// using the difference between the height and width of the ellipse
	if (h >= w) {
		return 45.00 *(double)((dminor()-dmajor())/(dminor()+dmajor())) * (PI / 180.0);
	}
	return 45.00 * (1.00 + abs((double)((dminor()-dmajor())/(dminor()+dmajor())))) * (PI / 180.0);

}

int Ellipse::cdiffx() const {
	// Return the difference along the x axis from the centre to the corner compass points 
	return (int)((dminor()*dmajor()*sin(get_corner_angle()))/(sqrt( pow(dmajor()*cos(get_corner_angle()),2) + pow(dminor()*sin(get_corner_angle()),2))));
}

int Ellipse::cdiffy() const {
	// Return the difference along the y axis from the centre to the corner compass points 
	return (int)((dminor()*dmajor()*cos(get_corner_angle()))/(sqrt( pow(dmajor()*cos(get_corner_angle()),2) + pow(dminor()*sin(get_corner_angle()),2))));
}


Point ne(Ellipse &e) { 
	return{ e.center().x - e.cdiffx(), e.center().y - e.cdiffy()}; 
}

Point nw(Ellipse &e) { 
	return{ e.center().x + e.cdiffx(), e.center().y - e.cdiffy()}; 
}

Point se(Ellipse &e) {
	return{ e.center().x - e.cdiffx(), e.center().y + e.cdiffy()}; 
}

Point sw(Ellipse &e) {
	return{ e.center().x + e.cdiffx(), e.center().y + e.cdiffy()};
}

Point nn(Ellipse &e) {
	return{ e.center().x, e.center().y - e.minor() };
}

Point ee(Ellipse &e) {
	return{ e.center().x + e.major(), e.center().y};
}

Point ss(Ellipse &e) {
	return{ e.center().x, e.center().y + e.minor()};
}

Point ww(Ellipse &e) {
	return{ e.center().x - e.major(), e.center().y};
}

}