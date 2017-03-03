

OBJS = BS_GUI/Frowny.cpp BS_GUI/Smiley.cpp BS_GUI/Star.cpp BS_GUI/Graph.cpp BS_GUI/Right_triangle.cpp BS_GUI/Arrow.cpp BS_GUI/Regular_polygon.cpp BS_GUI/Regular_hexagon.cpp BS_GUI/SoftBox.cpp BS_GUI/Circle.cpp BS_GUI/Rectangle.cpp BS_GUI/Ellipse.cpp BS_GUI/Window.cpp BS_GUI/GUI.cpp BS_GUI/Simple_window.cpp
CC = g++
DEBUG = -g
LFLAGS = -w -Wall -std=c++11 `fltk-config --ldflags --use-images` $(DEBUG)

chap12_drill: $(OBJS) chap12_ex6to7.cpp
	$(CC) $(LFLAGS) $(OBJS) chap12_drill.cpp -o chap12_drill 

chap12_ex1to5: $(OBJS) chap12_ex6to7.cpp
	$(CC) $(LFLAGS) $(OBJS) chap12_ex1to5.cpp -o chap12_ex1to5 

chap12_ex6to7: $(OBJS) chap12_ex6to7.cpp
	$(CC) $(LFLAGS) $(OBJS) chap12_ex6to7.cpp -o chap12_ex6to7 

chap12_ex8: $(OBJS) chap12_ex8.cpp
	$(CC) $(LFLAGS) $(OBJS) chap12_ex8.cpp -o chap12_ex8 

chap12_ex12: $(OBJS) chap12_ex12.cpp
	$(CC) $(LFLAGS) $(OBJS) chap12_ex12.cpp -o chap12_ex12

chap13_ex11: $(OBJS) chap13_ex11.cpp
	$(CC) $(LFLAGS) $(OBJS) chap13_ex11.cpp -o chap13_ex11

13_12_moving_mark: $(OBJS) 13_12_moving_mark.cpp
	$(CC) $(LFLAGS) $(OBJS) 13_12_moving_mark.cpp -o 13_12_moving_mark

13_13_Col_matrix: $(OBJS) 13_13_Col_matrix.cpp
	$(CC) $(LFLAGS) $(OBJS) 13_13_Col_matrix.cpp -o 13_13_Col_matrix

13_14_Right_triangle: $(OBJS) 13_14_Right_triangle.cpp
	$(CC) $(LFLAGS) $(OBJS) 13_14_Right_triangle.cpp -o 13_14_Right_triangle

13_15_Tiled_Right_Triangles: $(OBJS) 13_15_Tiled_Right_Triangles.cpp
	$(CC) $(LFLAGS) $(OBJS) 13_15_Tiled_Right_Triangles.cpp -o 13_15_Tiled_Right_Triangles

Star_test: $(OBJS) Star_test.cpp
	$(CC) $(LFLAGS) $(OBJS) Star_test.cpp -o Star_test

scratch: $(OBJS) scratch.cpp
	$(CC) $(LFLAGS) $(OBJS) scratch.cpp -o scratch

hexagons: $(OBJS) hexagons.cpp
	$(CC) $(LFLAGS) $(OBJS) hexagons.cpp -o hexagons
