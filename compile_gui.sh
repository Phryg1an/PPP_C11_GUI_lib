#!/bin/bash
#
# Script to compile GUI code using Bjarne Stroustrup's interface library and FLTK
#
# Expected parameter
# 1: Main code file (without extension)
#
# Output
# 1: Compiled code as executable

if [ $1 ]
then
	g++ -w -Wall -std=c++11 BS_GUI/Graph.cpp BS_GUI/Window.cpp BS_GUI/GUI.cpp BS_GUI/Simple_window.cpp $1.cpp `fltk-config --ldflags --use-images` -o $1 2>&1 | tee log.txt
else
	echo "ERROR: usage - ./compile_gui.sh <C++11 filename without extension>"
fi
