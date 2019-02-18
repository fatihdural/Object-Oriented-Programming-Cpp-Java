#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include "Polygon.h"
#include "Polyline.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;
using namespace circle;

double Circle::total_areas = 0;
double Circle::total_perimeters = 0;
double Triangle::total_areas = 0;
double Triangle::total_perimeters = 0;
double Rectangle::total_areas = 0;
double Rectangle::total_perimeters = 0;

int main(){
	ofstream dosya1, dosya2, dosya3, dosya4, dosya5, dosya6, dosya7, dosya8, dosya9, dosya10;
	dosya1.open("result_r_r.svg");
	dosya2.open("result_r_c.svg");
	dosya3.open("result_r_t.svg");
	dosya4.open("result_c_r.svg");
	dosya5.open("result_c_c.svg");
	dosya6.open("result_c_t.svg");
	dosya7.open("result_t_r.svg");
	dosya8.open("result_t_c.svg");
	dosya9.open("result_t_t.svg");
	dosya10.open("result_polyline_sample.svg");
	
	Rectangle R1(452,320);
	Rectangle R2(46,23);
	Rectangle R3(40,50);
	Rectangle R4(95,45);

	Circle C1(555);
	Circle C2(46);
	Circle C3(25); // container Circle shape.
	Circle C4(23);  // inner circle shapes

	Triangle T1(715);
	Triangle T2(15);
	Triangle T3(31);
	Triangle T4(48);

	Polygon P1(R1);
	Polygon P2(R2);
	Polygon P3(R1);
	Polygon P4(C2);
	Polygon P5(R1);
	Polygon P6(T2);

	Polygon P7(C1);
	Polygon P8(R3);
	Polygon P9(C1);
	Polygon P10(C3);
	Polygon P11(C1);
	Polygon P12(T3);

	Polygon P13(T1);
	Polygon P14(R4);
	Polygon P15(T1);
	Polygon P16(C4);
	Polygon P17(T1);
	Polygon P18(T4);			

	ComposedShape c1(P1, P2);
	ComposedShape c2(P3, P4);
	ComposedShape c3(P5, P6);
	ComposedShape c4(P7, P8);
	ComposedShape c5(P9, P10);
	ComposedShape c6(P11, P12);
	ComposedShape c7(P13, P14);
	ComposedShape c8(P15, P16);
	ComposedShape c9(P17, P18);

	int count = c1.optimalFit();
	double empty_area = R1.get_height() * R1.get_width() - R2.get_height() * R2.get_width() * count; // alan hesaplanir.
	dosya1 << c1;
	cout << c1;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;

	count = c2.optimalFit();
	empty_area = R1.get_height() * R1.get_width() - C2.get_radius() * C2.get_radius() * PI * count; // alan hesaplanir.
	cout << c2;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;

	count = c3.optimalFit();
	empty_area = R1.get_height() * R1.get_width() - T2.get_side() * T2.get_side() * sqrt(3) / 4 * count; // alan hesaplanir.
	cout << c3;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;

	count = c4.optimalFit();
	empty_area = C1.get_radius() * C1.get_radius() * PI - R3.get_height() * R3.get_width() * count; // alan hesaplanir.
	cout << c4;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;

	count = c5.optimalFit();
	empty_area = C1.get_radius() * C1.get_radius() * PI - C3.get_radius() * C3.get_radius() * PI * count; // alan hesaplanir.
	cout << c5;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;
	

	count = c6.optimalFit();
	empty_area = C1.get_radius() * C1.get_radius() * PI - T3.get_side() * T3.get_side() * sqrt(3) / 4 * count; // alan hesaplanir.
	cout << c6;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;
	
	count = c7.optimalFit();
	empty_area = T1.get_side() * T1.get_side() * sqrt(3) / 4 - R4.get_height() * R4.get_width() * count; // alan hesaplanir.
	cout << c7;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;
	
	count = c8.optimalFit();
	empty_area = T1.get_side() * T1.get_side() * sqrt(3) / 4 - C4.get_radius() * C4.get_radius() * PI * count; // alan hesaplanir.
	cout << c8;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;
	
	count = c9.optimalFit();
	empty_area = T1.get_side() * T1.get_side() * sqrt(3) / 4 - T4.get_side() * T4.get_side() * sqrt(3) / 4 * count; // alan hesaplanir.
	cout << c9;
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl << endl;

	dosya2 << c2;
	dosya3 << c3;
	dosya4 << c4;
	dosya5 << c5;
	dosya6 << c6;
	dosya7 << c7;
	dosya8 << c8;
	dosya9 << c9;

	Polyline Pl(T1);
	dosya10 << Pl;
	cout << Pl << endl;


	/*cout << "********R - R********" << endl; // arraylerde girilen bilgilerle, ekrana sekilin verileri yazdirilir, ComposedShape objesi olusturulur.
	Polygon P0(R[0]);
	Polygon P1(R[1]);

	ComposedShape CoShape1(P0, P1); // arrayin elemani olan objenin constructorini cagiramadigimizdan gecici ComposedShape objesi kullanilarak atama yapilir.
	ComShape[0] = CoShape1;
	int count = CoShape1.optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
	double empty_area = R[0].get_height() * R[0].get_width() - R[1].get_height() * R[1].get_width() * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;
	Polygon P23;
	ComposedShape C22;
	dosya0 << CoShape1;
	// ayni islemler devam eder.
	cout << "********R - C********" << endl;
	Polygon temp2(R[0]);
	Polygon temp3(C[1]);
	P[2] = temp2;
	P[3] = temp3;
	ComposedShape CoShape2(P[2], P[3]);
	ComShape[1] = CoShape2;
	count = ComShape[1].optimalFit();
	empty_area = R[0].get_height() * R[0].get_width() - C[1].get_radius() * C[1].get_radius() * PI * count; // alan hesaplanir.
	dosya0 << ComShape[1];
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;
	dosya1 << ComShape[1];*/
		
	/*cout << "********R - T********" << endl;
	Polygon P4(R[3]);
	Polygon P5(T[1]);

	ComposedShape CoShape3(P4, P5);
	ComShape[2] = CoShape3;
	count = CoShape3.optimalFit();
	empty_area = R[0].get_height() * R[0].get_width() - T[1].get_side() * T[1].get_side() * sqrt(3) / 4 * count; // alan hesaplanir.
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;	
	dosya2 << CoShape3;		

	cout << "********C - R********" << endl;		
	cout << "Container radius: " << C[0].get_radius() << endl;
	cout << "İnner width: " << R[2].get_width() << endl;
	cout << "İnner height: " << R[2].get_height() << endl;
	ComposedShape CoShape4(C[0], R[2]);
	ComShape[3] = CoShape4;
	count = ComShape[3].optimalFit();
	
	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;
	dosya3 << ComShape[3];
	
	cout << "********C - C********" << endl;
	cout << "Container radius: " << C[0].get_radius() << endl;
	cout << "İnner radius: " << C[2].get_radius() << endl;
	ComposedShape CoShape5(C[0], C[2]);
	ComShape[4] = CoShape5;
	count = ComShape[4].optimalFit();

	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;		
	dosya4 << ComShape[4];	
			
	cout << "********C - T********" << endl;
	cout << "Container radius: " << C[0].get_radius() << endl;
	cout << "İnner side: " << T[2].get_side() << endl;
	ComposedShape CoShape6(C[0], T[2]);
	ComShape[5] = CoShape6;
	count = ComShape[5].optimalFit();

	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;	
	dosya5 << ComShape[5];		

	cout << "********T - R********" << endl;
	cout << "Container side: " << T[0].get_side() << endl;
	cout << "İnner width: " << R[3].get_width() << endl;
	cout << "İnner height: " << R[3].get_height() << endl;
	ComposedShape CoShape7(T[0], R[3]);
	ComShape[6] = CoShape7;
	count = ComShape[6].optimalFit();

	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;			
	dosya6 << ComShape[6];

	cout << "********T - C********" << endl;
	cout << "Container side: " << T[0].get_side() << endl;
	cout << "İnner radius: " << C[3].get_radius() << endl;
	ComposedShape CoShape8(T[0], C[3]);
	ComShape[7] = CoShape8;
	count = ComShape[7].optimalFit();

	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;
	dosya7 << ComShape[7];		
		
	cout << "********T - T********" << endl;
	cout << "Container side: " << T[0].get_side() << endl;
	cout << "İnner side: " << T[3].get_side() << endl;
	ComposedShape CoShape9(T[0], T[3]);
	ComShape[8] = CoShape9;
	count = ComShape[8].optimalFit();

	cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << "." << endl;	
	cout << "You can change the shape values from driver file!!" << endl << endl;
	dosya8 << ComShape[8];
	dosya0.close();
	cout << "********Bazi Operator Testleri********" << endl;
	Triangle T1(250), T2(350); 
	Circle C1(485), C2(666);
	Rectangle R1(125,333), R2(333,125);
	cout << "Olusturulmus tum Circle uzunluklari(cevre) toplami : " << Circle::get_total_perimeters() << endl;
	cout << "Olusturulmus tum Rectangle alanlari toplami : " << Rectangle::get_total_areas() << endl;
	cout << "Triangle T1(250), T2(350);" << endl;
	cout << "Circle C1(485), C2(666);" << endl;
	cout << "Rectangle R1(125), R2(333);" << endl;
	if( R1 == R2){
		cout << "R1 == R2" << endl;
	}
	if( T1 != T2){
		cout << "T1 != T2" << endl;
	}
	if( C1 >= C2){
		cout << "C1 >= C2" << endl;
	}
	if( C1 <= C2){
		cout << "C1 <= C2" << endl;
	}
	T1++;
	C2--;
	R1 = R1 + 15; 
	cout << "R1 = R1 + 15" << endl;
	cout << R1 << endl << endl;
	cout << "HW4---------" << endl; */

	return 0;
}
