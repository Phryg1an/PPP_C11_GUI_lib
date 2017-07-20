#include "Polygon.h"

namespace Graph_lib {

	Polygon::Polygon()
		:Closed_polyline() { } // now the constructor is public
	Polygon::Polygon(initializer_list<Point> lst)
		:Closed_polyline(lst) { }

	void Polygon::draw_lines() const
	{
			if (number_of_points() < 3) error("less than 3 points in a Polygon");
			Closed_polyline::draw_lines();
	}

	// does two lines (p1,p2) and (p3,p4) intersect?
	// if se return the distance of the intersect point as distances from p1
	inline pair<double,double> Polygon::line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel) 
	{
	    double x1 = p1.x;
	    double x2 = p2.x;
		double x3 = p3.x;
		double x4 = p4.x;
		double y1 = p1.y;
		double y2 = p2.y;
		double y3 = p3.y;
		double y4 = p4.y;

		double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
		if (denom == 0){
			parallel= true;
			return pair<double,double>(0,0);
		}
		parallel = false;
		return pair<double,double>( ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
									((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
	}


	//intersection between two line segments
	//Returns true if the two segments intersect,
	//in which case intersection is set to the point of intersection
	bool Polygon::line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection){
	   bool parallel;
	   pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
	   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
	   intersection.x = p1.x + u.first*(p2.x - p1.x);
	   intersection.y = p1.y + u.first*(p2.y - p1.y);
	   return true;
	} 

	void Polygon::add(Point p)
	{
		int np = number_of_points();

		if (1<np) {	// check that thenew line isn't parallel to the previous one
			if (p==point(np-1)) error("polygon point equal to previous point");
			bool parallel;
			line_intersect(point(np-1),p,point(np-2),point(np-1),parallel);
			if (parallel)
				error("two polygon points lie in a straight line");
		}

		for (int i = 1; i<np-1; ++i) {	// check that new segment doesn't interset and old point
			Point ignore(0,0);
			if (line_segment_intersect(point(np-1),p,point(i-1),point(i),ignore))
				error("intersect in polygon");
		}
		

		Closed_polyline::add(p);

	}
}