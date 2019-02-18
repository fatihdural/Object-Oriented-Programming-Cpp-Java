#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

int main(){
	Rectangle R[4];
	Circle C[4];
	Triangle T[4];
	ComposedShape ComShape[9]; // shapeleri tutacak ComposedShape arrayi.
	R[0].set_width(452); // container Rectangle shape.
	R[0].set_height(320);
	R[1].set_width(46);  // inner rectangle shapes.
	R[1].set_height(23);
	R[2].set_width(40);
	R[2].set_height(50);
	R[3].set_width(95);
	R[3].set_height(45);
	C[0].set_radius(555); // container Circle shape.
	C[1].set_radius(46);  // inner circle shapes
	C[2].set_radius(25);
	C[3].set_radius(23);
	T[0].set_side(715); // container Triangle shape.
	T[1].set_side(15);  // inner triangle shapes.
	T[2].set_side(31);
	T[3].set_side(48);
	
	cout << "********R - R********" << endl; // arraylerde girilen bilgilerle, ekrana sekilin verileri yazdirilir, ComposedShape objesi olusturulur.
	cout << "Container width: " << R[0].get_width() << endl;
	cout << "Container height: " << R[0].get_height() << endl;
	cout << "İnner width: " << R[1].get_width() << endl;
	cout << "İnner height: " << R[1].get_height() << endl;
	ComposedShape CoShape1(R[0], R[1]); // arrayin elemani olan objenin constructorini cagiramadigimizdan gecici ComposedShape objesi kullanilarak atama yapilir.
	ComShape[0] = CoShape1;
	int count = ComShape[0].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
	double empty_area = R[0].get_height() * R[0].get_width() - R[1].get_height() * R[1].get_width() * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;
	// ayni islemler devam eder.
	cout << "********R - C********" << endl;
	cout << "Container width: " << R[0].get_width() << endl;
	cout << "Container height: " << R[0].get_height() << endl;
	cout << "İnner radius: " << C[1].get_radius() << endl;
	ComposedShape CoShape2(R[0], C[1]);
	ComShape[1] = CoShape2;
	count = ComShape[1].optimalFit();
	empty_area = R[0].get_height() * R[0].get_width() - C[1].get_radius() * C[1].get_radius() * PI * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;
		
	cout << "********R - T********" << endl;
	cout << "Container width: " << R[0].get_width() << endl;
	cout << "Container height: " << R[0].get_height() << endl;
	cout << "İnner side: " << T[1].get_side() << endl;
	ComposedShape CoShape3(R[0], T[1]);
	ComShape[2] = CoShape3;
	count = ComShape[2].optimalFit();
	empty_area = R[0].get_height() * R[0].get_width() - T[1].get_side() * T[1].get_side() * sqrt(3) / 4 * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;			

	cout << "********C - R********" << endl;		
	cout << "Container radius: " << C[0].get_radius() << endl;
	cout << "İnner width: " << R[2].get_width() << endl;
	cout << "İnner height: " << R[2].get_height() << endl;
	ComposedShape CoShape4(C[0], R[2]);
	ComShape[3] = CoShape4;
	count = ComShape[3].optimalFit();
	empty_area = C[0].get_radius() * C[0].get_radius() * PI - R[2].get_height() * R[2].get_width() * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;
	
	cout << "********C - C********" << endl;
	cout << "Container radius: " << C[0].get_radius() << endl;
	cout << "İnner radius: " << C[2].get_radius() << endl;
	ComposedShape CoShape5(C[0], C[2]);
	ComShape[4] = CoShape5;
	count = ComShape[4].optimalFit();
	empty_area = C[0].get_radius() * C[0].get_radius() * PI - C[2].get_radius() * C[2].get_radius() * PI * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;			
			
	cout << "********C - T********" << endl;
	cout << "Container radius: " << C[0].get_radius() << endl;
	cout << "İnner side: " << T[2].get_side() << endl;
	ComposedShape CoShape6(C[0], T[2]);
	ComShape[5] = CoShape6;
	count = ComShape[5].optimalFit();
	empty_area = C[0].get_radius() * C[0].get_radius() * PI - T[2].get_side() * T[2].get_side() * sqrt(3) / 4 * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;			

	cout << "********T - R********" << endl;
	cout << "Container side: " << T[0].get_side() << endl;
	cout << "İnner width: " << R[3].get_width() << endl;
	cout << "İnner height: " << R[3].get_height() << endl;
	ComposedShape CoShape7(T[0], R[3]);
	ComShape[6] = CoShape7;
	count = ComShape[6].optimalFit();
	empty_area = T[0].get_side() * T[0].get_side() * sqrt(3) / 4 - R[3].get_height() * R[3].get_width() * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;			

	cout << "********T - C********" << endl;
	cout << "Container side: " << T[0].get_side() << endl;
	cout << "İnner radius: " << C[3].get_radius() << endl;
	ComposedShape CoShape8(T[0], C[3]);
	ComShape[7] = CoShape8;
	count = ComShape[7].optimalFit();
	empty_area = T[0].get_side() * T[0].get_side() * sqrt(3) / 4 - C[3].get_radius() * C[3].get_radius() * PI * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;		
		
	cout << "********T - T********" << endl;
	cout << "Container side: " << T[0].get_side() << endl;
	cout << "İnner side: " << T[3].get_side() << endl;
	ComposedShape CoShape9(T[0], T[3]);
	ComShape[8] = CoShape9;
	count = ComShape[8].optimalFit();
	empty_area = T[0].get_side() * T[0].get_side() * sqrt(3) / 4 - T[3].get_side() * T[3].get_side() * sqrt(3) / 4 * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;	
	cout << "You can change the shape values from driver file!!" << endl;		
	return 0;
}
