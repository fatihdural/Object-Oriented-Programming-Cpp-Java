#ifndef PolygonDyn_h_
#define PolygonDyn_h_
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "Shape.h"
#include "Polygon.h" 

using namespace std;

namespace cpp{
	class PolygonDyn : public Polygon  {
		public:
			PolygonDyn(){}
			~PolygonDyn(); // destructor.
			PolygonDyn(const PolygonDyn & Pd); // copy constructor.
			PolygonDyn & operator=(const PolygonDyn & Pd);	// copy assignment operator.		
			PolygonDyn(Rectangle &R);
			PolygonDyn(Circle &C);
			PolygonDyn(Triangle &T);
			PolygonDyn(vector<PolygonDyn::Point2D> &point2d);
			PolygonDyn(PolygonDyn::Point2D &point);
			virtual double get_area();
			virtual double get_perimeter();
			virtual PolygonDyn & operator++();
			virtual PolygonDyn & operator--();
			virtual PolygonDyn & operator++(int);
			virtual PolygonDyn & operator--(int);
			virtual ofstream &draw_shape(ofstream &dosya);
		private:
			PolygonDyn::Point2D *polygondyn;
			int count;
	};	
}
#endif