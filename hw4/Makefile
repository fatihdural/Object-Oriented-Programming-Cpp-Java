all: run

run: 
	g++ -std=c++11 -c Rectangle.cpp
	g++ -std=c++11 -c Circle.cpp
	g++ -std=c++11 -c Triangle.cpp
	g++ -std=c++11 -c Polygon.cpp
	g++ -std=c++11 -c Polyline.cpp
	g++ -std=c++11 -c driverfile.cpp
	g++ -std=c++11 -c ComposedShape.cpp

	g++ -o run driverfile.o Polygon.o Polyline.o ComposedShape.o Rectangle.o Circle.o Triangle.o  
	./run
	rm *.o run
clean:
	rm *.o run
