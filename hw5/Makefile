all: run

run: 
	g++ -std=c++0x -c Rectangle.cpp
	g++ -std=c++0x -c Circle.cpp
	g++ -std=c++0x -c Triangle.cpp
	g++ -std=c++0x -c Polygon.cpp
	g++ -std=c++0x -c Shape.cpp
	g++ -std=c++0x -c ComposedShape.cpp
	g++ -std=c++0x -c driverfile.cpp
	g++ -std=c++0x -c PolygonVect.cpp
	g++ -std=c++0x -c PolygonDyn.cpp	

	g++ -o run Polygon.o Shape.o ComposedShape.o driverfile.o Rectangle.o Circle.o Triangle.o PolygonVect.o PolygonDyn.cpp
	./run
	rm *.o run
clean:
	rm *.o run
