all: run

run: 
	g++ -std=c++11 -c Rectangle.cpp
	g++ -std=c++11 -c Circle.cpp
	g++ -std=c++11 -c Triangle.cpp
	g++ -std=c++11 -c ComposedShape.cpp
	g++ -std=c++11 -c driverfile.cpp
	
	g++ -o run driverfile.o ComposedShape.o Rectangle.o Circle.o Triangle.o  
	./run
	rm *.o run
clean:
	rm *.o run
