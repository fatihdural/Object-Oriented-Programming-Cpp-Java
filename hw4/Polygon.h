#ifndef Polygon_h_
#define Polygon_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"

using namespace std;
using namespace circle;

class Polygon{
public:
	Polygon();
	~Polygon();
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
	
	Point2D * get_points();
	void set_points_mem(int count);
	void set_po_points(double x, double y);
	char get_type();
	int get_count();
	friend ofstream &operator<<( ofstream &output, Polygon &po );
	friend ostream &operator<<( ostream &output, Polygon &po );
	const bool operator== (Polygon &p2);
    const bool operator!= (Polygon &p2);
    const Polygon operator+(const Polygon& p2);
    Point2D& operator[] (int x);	
private:
	Point2D *points;
	int count;
	char type;
};
#endif
