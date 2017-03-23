

SRC := src/
BIN := bin/
OBJS := $(wildcard src/PPP_C11_GUI/*.cpp)
INC := -Iinclude/PPP_C11_GUI 
CC = g++
DEBUG = -g
LFLAGS = -w -Wall -std=c++11 `fltk-config --ldflags --use-images` $(DEBUG)
ARGS := $(CC) $(LFLAGS) $(OBJS) $(INC)

chap12_drill: $(OBJS) $(SRC)chap12_ex6to7.cpp
	$(ARGS) $(SRC)chap12_drill.cpp -o $(BIN)chap12_drill 

chap12_ex1to5: $(OBJS) $(SRC)chap12_ex6to7.cpp
	$(ARGS) $(SRC)chap12_ex1to5.cpp -o $(BIN)chap12_ex1to5 

chap12_ex6to7: $(OBJS) $(SRC)chap12_ex6to7.cpp
	$(ARGS) $(SRC)chap12_ex6to7.cpp -o $(BIN)chap12_ex6to7 

chap12_ex8: $(OBJS)c$(SRC)chap12_ex8.cpp
	$(ARGS) $(SRC)chap12_ex8.cpp -o $(BIN)chap12_ex8 

chap12_ex12: $(OBJS) $(SRC)chap12_ex12.cpp
	$(ARGS) $(SRC)chap12_ex12.cpp -o $(BIN)chap12_ex12

chap13_ex11: $(OBJS) $(SRC)chap13_ex11.cpp
	$(ARGS) $(SRC)chap13_ex11.cpp -o $(BIN)chap13_ex11

13_12_moving_mark: $(OBJS) $(SRC)13_12_moving_mark.cpp
	$(ARGS) $(SRC)13_12_moving_mark.cpp -o $(BIN)13_12_moving_mark

13_13_Col_matrix: $(OBJS) $(SRC)13_13_Col_matrix.cpp
	$(ARGS) $(SRC)13_13_Col_matrix.cpp -o $(BIN)13_13_Col_matrix

13_14_Right_triangle: $(OBJS) $(SRC)13_14_Right_triangle.cpp
	$(ARGS) $(SRC)13_14_Right_triangle.cpp -o $(BIN)13_14_Right_triangle

13_15_Tiled_Right_Triangles: $(OBJS) $(SRC)13_15_Tiled_Right_Triangles.cpp
	$(ARGS) $(SRC)13_15_Tiled_Right_Triangles.cpp -o $(BIN)13_15_Tiled_Right_Triangles

Star_test: $(OBJS) $(SRC)Star_test.cpp
	$(ARGS) $(SRC)Star_test.cpp -o $(BIN)Star_test

scratch: $(OBJS) $(SRC)scratch.cpp
	$(ARGS)  $(SRC)scratch.cpp -o $(BIN)scratch

hexagons: $(OBJS) $(SRC)hexagons.cpp
	$(ARGS)  $(SRC)hexagons.cpp -o $(BIN)hexagons
