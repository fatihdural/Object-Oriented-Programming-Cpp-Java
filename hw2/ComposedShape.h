#ifndef ComposedShape_h_
#define ComposedShape_h_
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class ComposedShape{ // container shape ve inneer shape i olusturup, uygulayacak class ComposedShape tanimlanir.
	public:
		ComposedShape(){
		}
		ComposedShape(Rectangle R1, Rectangle R2);
		ComposedShape(Rectangle R1, Circle C1);
		ComposedShape(Rectangle R1, Triangle T1);
		ComposedShape(Circle C1, Rectangle R1);
		ComposedShape(Circle C1, Circle C2);
		ComposedShape(Circle C1, Triangle T1);
		ComposedShape(Triangle T1, Rectangle R1);
		ComposedShape(Triangle T1, Circle C1);
		ComposedShape(Triangle T1, Triangle T2);
		Rectangle get_vectR(int i)const;
		Circle get_vectC(int i)const;
		Triangle get_vectT(int i)const;						
		int optimalFit();
		int draw(ofstream& dosya)const;
	private:	
		char container, small;
		Rectangle R1, R2;
		Circle C1, C2;
		Triangle T1, T2;
		vector <Rectangle> vectR;
		vector <Circle> vectC;
		vector <Triangle> vectT;	
};
#endif
