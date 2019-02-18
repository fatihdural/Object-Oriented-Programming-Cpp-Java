#ifndef ComposedShape_h_
#define ComposedShape_h_
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"

using namespace std;

namespace cpp{
	class ComposedShape : public Shape { // container shape ve inneer shape i olusturup, uygulayacak class ComposedShape tanimlanir.
		public:
			ComposedShape(){} // default constructor.
			~ComposedShape(); // destructor
			ComposedShape(const ComposedShape & C); // copy constructor.
			ComposedShape & operator=(const ComposedShape & C);	// copy assignment operator.	
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
			virtual double get_area();
			virtual double get_perimeter();
			virtual ofstream &draw_shape(ofstream &dosya);
			virtual ComposedShape & operator++();
			virtual ComposedShape & operator--();
			virtual ComposedShape & operator++(int);
			virtual ComposedShape & operator--(int);
			friend ofstream &operator<<( ofstream &output, ComposedShape &co );
			friend ostream &operator<<( ostream &output, ComposedShape &co );
		private:	
			vector <Shape *> shape;
			shapes container, small;
			Rectangle R1, R2;
			Circle C1, C2;
			Triangle T1, T2;
			
	};	
}
#endif
