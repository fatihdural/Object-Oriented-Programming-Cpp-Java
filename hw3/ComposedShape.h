#ifndef ComposedShape_h_
#define ComposedShape_h_
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "Rectangle.h"
using namespace std;

class ComposedShape{ // container shape ve inneer shape i olusturup, uygulayacak class ComposedShape tanimlanir.
	public:
		ComposedShape(){}
		ComposedShape(Rectangle R1, Rectangle R2);
		ComposedShape(Rectangle R1, Circle C1);
		ComposedShape(Rectangle R1, Triangle T1);
		ComposedShape(Circle C1, Rectangle R1);
		ComposedShape(Circle C1, Circle C2);
		ComposedShape(Circle C1, Triangle T1);
		ComposedShape(Triangle T1, Rectangle R1);
		ComposedShape(Triangle T1, Circle C1);
		ComposedShape(Triangle T1, Triangle T2);				
		enum shapes {R, C, T};
		int optimalFit();
		class ShapeElem{
			public:
				ShapeElem(){}
				ShapeElem(Rectangle R);
				ShapeElem(Circle C);
				ShapeElem(Triangle R);
				void * get_shape()const;
				double get_area()const;
				double get_perimeter()const;
				friend ofstream &operator<<( ofstream &output, const ComposedShape::ShapeElem &s );	 
      			friend ostream &operator<<( ostream &output, const ComposedShape::ShapeElem &s );
			private:
				void *shape;
				shapes shape_type;
		};
		const ShapeElem operator[](int i)const;
		const ComposedShape operator+=(ShapeElem &s);
		friend ofstream &operator<<( ofstream &output, const ComposedShape &co );
		friend ostream &operator<<( ostream &output, const ComposedShape &co );
	private:	
		vector <ShapeElem> ShapeElement;
		shapes container, small;
		Rectangle R1, R2;
		Circle C1, C2;
		Triangle T1, T2;
};
#endif
