#ifndef PolygonVect_h_
#define PolygonVect_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "Shape.h"
#include "Polygon.h" 

using namespace std;

namespace cpp{
	class PolygonVect : public Polygon  {
		public:
			PolygonVect(){}
			PolygonVect(PolygonVect & Pv); // copy constructor.
			PolygonVect & operator=(PolygonVect & Pv);	// copy assignment operator.		
			PolygonVect(Rectangle &R);
			PolygonVect(Circle &C);
			PolygonVect(Triangle &T);
			PolygonVect(vector<PolygonVect::Point2D> &point2d);
			PolygonVect(PolygonVect::Point2D &point);
			virtual double get_area();
			virtual double get_perimeter();
			virtual PolygonVect & operator++();
			virtual PolygonVect & operator--();
			virtual PolygonVect & operator++(int);
			virtual PolygonVect & operator--(int);
			virtual ofstream &draw_shape(ofstream &dosya);
		private:
			vector<PolygonVect::Point2D> polygonvect;
			int count;
	};	
}
#endif