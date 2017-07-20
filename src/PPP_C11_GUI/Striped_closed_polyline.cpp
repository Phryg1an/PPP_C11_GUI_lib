#include "Striped_closed_polyline.h"

namespace Graph_lib {

	Striped_closed_polyline::Striped_closed_polyline()
		:Closed_polyline() { } // now the constructor is public
	Striped_closed_polyline::Striped_closed_polyline(initializer_list<Point> lst)
		:Closed_polyline(lst) { s = 4; }	

	// inline pair<int, int> min_max_x()
	// {
	// 	return pair<int,int>(Striped_closed_polyline::points.size(), points.size());
	// }

	void Striped_closed_polyline::draw_lines() const
	{
		Closed_polyline::draw_lines();

		double angle;
		int p1;
		int p2;

		//get the max and min ranges for x
		int xmin = 32767;
		int xmax = 0;

		for (int i = 0; i < number_of_points(); i++) {
			if (point(i).x < xmin) {
				xmin = point(i).x;
			}
			else if (point(i).x > xmax) {
				xmax = point(i).x;
			}
		}

		//Get all our stripe co-ordinates!!!!!!!!!!
		//Storage vectors to hold our stripe co-ordinates
		//Using vectors and ints as cannot get point integers out of vector-ref
		vector <vector<int>> vec_line_points_x;
		vector <vector<int>> vec_line_points_y;
		vector <int> line_points_x;
		vector <int> line_points_y;

		for (int i = 0; i < number_of_points(); i++){
			
			if (i+1 < number_of_points()) {
				if (point(i).x < point(i+1).x) {
					p1 = i;
					p2 = i+1;
				}
				else {
					p1 = i+1;
					p2 = i;					
				}
			}
			else {
				if (point(0).x < point(i).x) {
					p1 = 0;
					p2 = i;
				}
				else {
					p1 = i;
					p2 = 0;
				}
			}

			//Get the angle for this line
			angle = atan((double)(point(p1).x - point(p2).x) / (double)(point(p1).y - point(p2).y)); 

			for (int j = (point(p1).x - xmin)%s; j < (point(p2).x - point(p1).x); j+=s) {
				//Make our co-ordinates
				line_points_x.push_back(point(p1).x + j);
				line_points_y.push_back(point(p1).y + (int)std::round((double)j / (tan(angle))));
			}

			//Push line_points into main collection of vectors
			vec_line_points_x.push_back(line_points_x);
			vec_line_points_y.push_back(line_points_y);
			
			//Clear our temporary vectors
			line_points_x.clear();
			line_points_y.clear();
		}
	

		//New temporary vector for y_coordinates at specific x co-ordinates
		vector<int> y_coords;

		//iterate through the x-coordinates for each stripe
		for (int i = xmin + s; i < xmax; i+=s) {
		 	//search the x-coordinates along each line
		 	for (int j = 0; j < vec_line_points_x.size(); j++) {
		 		for (int k = 0; k < vec_line_points_x[j].size(); k++) {
		 			//If we find the x-coordinate we want, store the y coordinate in our temporary vector
		 			if (vec_line_points_x[j][k] == i) {
		 				y_coords.push_back(vec_line_points_y[j][k]);
		 			}
		 		}
		 	}

			//sort the y-coords for this x coordinate
			sort(y_coords.begin(), y_coords.end());

			//sort the y-coords for this x coordinate
			for (int m = 0; m < y_coords.size(); m+=2) {
			 	fl_line(i, y_coords[m], i, y_coords[m+1]);
			}

			//clear temp vector for next pass
			y_coords.clear();
		}
	
	}
}