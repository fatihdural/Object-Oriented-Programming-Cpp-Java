all: run

run: 
	g++ -std=c++11 -c driverfile.cpp
	g++ -std=c++11 -c Iterator.cpp
	g++ -std=c++11 -c HashSet.cpp
	g++ -std=c++11 -c ArrayList.cpp
	g++ -std=c++11 -c LinkedList.cpp
	
	g++ -o run driverfile.o Iterator.o HashSet.o ArrayList.o LinkedList.o
	./run
	rm *.o run
clean:
	rm *.o run
