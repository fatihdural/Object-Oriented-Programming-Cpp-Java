#ifndef Polygon_h_
#define Polygon_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Shape.h"

using namespace std;

namespace cpp{
	class Polygon : public Shape{
		public:
			Polygon();
			~Polygon(); // destructor.
			Polygon(const Polygon & P); // copy constructor.
			Polygon & operator=(const Polygon & P);	// copy assignment operator.	
			class Point2D
			{
				public:
					Point2D(){}
					Point2D(double a, double b);
					void set_points(double a, double b);
					double get_x();
					double get_y();
				private:
					double x;
					double y;
			};
			Polygon(Rectangle &R);
			Polygon(Circle &C);
			Polygon(Triangle &T);
			Polygon(vector<Point2D> &point2d);
			Polygon(Point2D &point);
			virtual double get_area() = 0;
			virtual double get_perimeter() = 0;
			virtual Shape & operator++() = 0;
			virtual Shape & operator--() = 0;
			virtual Shape & operator++(int) = 0;
			virtual Shape & operator--(int) = 0;
			virtual ofstream &draw_shape(ofstream &dosya) = 0;
			Point2D * get_points();
			void set_points_mem(int count);
			void set_po_points(double x, double y);
			friend ofstream &operator<<( ofstream &output, Polygon &po );
			friend ostream &operator<<( ostream &output, Polygon &po );
			const bool operator== (Polygon &p2);
		    const bool operator!= (Polygon &p2);
		    Point2D& operator[] (int x);	
		private:
			Point2D *points;
			int count;
	};	
}
#endif
