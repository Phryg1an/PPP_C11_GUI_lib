

OBJS = BS_GUI/Graph.cpp BS_GUI/Window.cpp BS_GUI/GUI.cpp BS_GUI/Simple_window.cpp
CC = g++
DEBUG = -g
LFLAGS = -w -Wall -std=c++11 `fltk-config --ldflags --use-images` $(DEBUG)

chap12_ex5: $(OBJS) chap12_ex6to7.cpp
	$(CC) $(LFLAGS) $(OBJS) chap12_ex6to7.cpp -o chap12_ex6to7 
