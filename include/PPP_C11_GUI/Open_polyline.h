#ifndef OPEN_POLYLINE_GUARD
#define OPEN_POLYLINE_GUARD 1

#include "Graph.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

class Open_polyline : public Shape {	// open sequence of lines
	
public:
	Open_polyline():Shape() { } // now the constructor is public
	Open_polyline(initializer_list<Point> lst):Shape(lst) { }
protected:
	//void add(Point p) { Shape::add(p); }
	void draw_lines() const;
};

struct Marked_polyline : Open_polyline {
	Marked_polyline(const string& m) :mark(m) { }
	void draw_lines() const;
private:
	string mark;
};

//------------------------------------------

struct Marks : Marked_polyline {
	Marks(const string& m) :Marked_polyline(m)
	{ set_color(Color(Color::invisible)); }

};

//------------------------------------------

struct Mark : Marks {
	Mark(Point xy, char c) : Marks(string(1,c)) {add(xy); }

	void set_point(Point p) { Shape::set_point(0, p); }
};


}
#endif