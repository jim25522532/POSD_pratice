.PHONY: dirs clean

SRC = src/shape.h src/ellipse.h src/complex_shape.h
TEST = test/ut_ellipse.h
OBJ = obj/shape.o obj/find_area_visitor.o
all: dirs ut_main

obj/shape.o: src/shape.cpp src/shape.h
		g++ -std=c++11 -Wfatal-errors -Wall -c src/shape.cpp -o obj/shape.o

obj/find_area_visitor.o: src/find_area_visitor.cpp src/find_area_visitor.h
				g++ -std=c++11 -Wfatal-errors -Wall -c src/find_area_visitor.cpp -o obj/find_area_visitor.o

ut_main: test/ut_main.cpp $(SRC) $(TEST) $(OBJ)
									g++ -std=c++11 -Wfatal-errors test/ut_main.cpp obj/shape.o obj/find_area_visitor.o -o bin/ut_main -lgtest -lpthread


dirs:
			mkdir -p bin
			mkdir -p obj

clean:
			rm -rf bin/*
			rm -rf obj/*
