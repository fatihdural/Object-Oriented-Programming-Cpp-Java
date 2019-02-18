#ifndef Polyline_h_
#define Polyline_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include "Polygon.h"

using namespace std;
using namespace circle;
class Polyline
{
public:
	Polyline(){}
	Polyline(Rectangle R);
	Polyline(Circle C);
	Polyline(Triangle T);
	Polyline(vector<Polygon::Point2D> point2d);
	Polyline(Polygon::Point2D point);
	friend ofstream &operator<<( ofstream &dosya, Polyline &po );
	friend ostream &operator<<( ostream &dosya, Polyline &po );
private:
	int x;
	Polygon P;
};

#endif
