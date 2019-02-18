#ifndef Shape_h_
#define Shape_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

namespace cpp{
	class Shape
	{
		public:
			virtual double get_area() = 0;
			virtual double get_perimeter() = 0;
			virtual Shape & operator++() = 0;
			virtual Shape & operator--() = 0;
			virtual Shape & operator++(int) = 0;
			virtual Shape & operator--(int) = 0;
			virtual ofstream &draw_shape(ofstream &dosya) = 0;
			friend ofstream &operator<<( ofstream &dosya, Shape &s );
			friend void printAll(ofstream &dosya, vector<Shape *> S);
			friend void printPoly(ofstream &dosya, vector<Shape *> S);
			friend vector<Shape *> convertAll(vector<Shape *> S);
			friend void sortShapes(vector<Shape *> S);
			bool operator== (Shape &s2);
	    	bool operator!= (Shape &s2);
	    	bool operator> (Shape &s2);
	    	bool operator< (Shape &s2);    	
	    	bool operator>= (Shape &s2);
	    	bool operator<= (Shape &s2);
	};
}
#endif
