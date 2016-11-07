

OBJS = BS_GUI/Graph.cpp BS_GUI/Arrow.cpp BS_GUI/Regular_polygon.cpp BS_GUI/Regular_hexagon.cpp BS_GUI/SoftBox.cpp BS_GUI/Circle.cpp BS_GUI/Rectangle.cpp BS_GUI/Ellipse.cpp BS_GUI/Window.cpp BS_GUI/GUI.cpp BS_GUI/Simple_window.cpp
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

scratch: $(OBJS) scratch.cpp
	$(CC) $(LFLAGS) $(OBJS) scratch.cpp -o scratch

hexagons: $(OBJS) hexagons.cpp
	$(CC) $(LFLAGS) $(OBJS) hexagons.cpp -o hexagons
