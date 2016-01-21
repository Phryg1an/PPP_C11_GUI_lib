#!/bin/bash

g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp try_this.cpp `fltk-config --ldflags --use-images` -o try_this 2>&1 | tee log.txt

