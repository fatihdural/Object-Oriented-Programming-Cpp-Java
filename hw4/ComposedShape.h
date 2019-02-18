#ifndef ComposedShape_h_
#define ComposedShape_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Polyline.h"
using namespace std;
using namespace circle;
class ComposedShape{ // container shape ve inneer shape i olusturup, uygulayacak class ComposedShape tanimlanir.
	public:
		ComposedShape(){}
		ComposedShape(Polygon P1, Polygon P2);
		ComposedShape(Rectangle R1, Rectangle R2);
		ComposedShape(Rectangle R1, Circle C1);
		ComposedShape(Rectangle R1, Triangle T1);
		ComposedShape(Circle C1, Rectangle R1);
		ComposedShape(Circle C1, Circle C2);
		ComposedShape(Circle C1, Triangle T1);
		ComposedShape(Triangle T1, Rectangle R1);
		ComposedShape(Triangle T1, Circle C1);
		ComposedShape(Triangle T1, Triangle T2);				
		enum class shapes {R, C, T};
		int optimalFit();
		friend ofstream &operator<<( ofstream &output, ComposedShape &co );
		friend ostream &operator<<( ostream &output, ComposedShape &co );
	private:	
		vector <Polygon> Polygons;
		shapes container, small;
		Polygon P1, P2;
};
#endif
