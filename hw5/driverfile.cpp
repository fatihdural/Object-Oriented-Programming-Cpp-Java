#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include "Polygon.h"
#include "Shape.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"

using namespace std;
using namespace cpp;

class control : public exception{
	public:
		void hata(){
			cout << "Negatif sayi girilemez!!" << endl;
		}
};

double Circle::total_areas = 0;
double Circle::total_perimeters = 0;
double Triangle::total_areas = 0;
double Triangle::total_perimeters = 0;
double Rectangle::total_areas = 0;
double Rectangle::total_perimeters = 0;
int main(){
	try{
		Rectangle R[4];
		Circle C[4];
		Triangle T[4];
		ComposedShape ComShape[9]; // shapeleri tutacak ComposedShape arrayi.
		Shape * S[9];
		R[0].set_wh(452,320); // container Rectangle shape.
		R[1].set_wh(46,23);  // inner rectangle shapes.
		R[2].set_wh(40,50);
		R[3].set_wh(95,45);
		C[0].set_radius(555); // container Circle shape.
		C[1].set_radius(46);  // inner circle shapes
		C[2].set_radius(25);
		C[3].set_radius(23);
		T[0].set_side(715); // container Triangle shape.
		T[1].set_side(15);  // inner triangle shapes.
		T[2].set_side(31);
		T[3].set_side(48);
		ofstream dosya0, dosya1,dosya2, dosya3, dosya4, dosya5, dosya6, dosya7, dosya8;
		dosya0.open("result_r_r.svg");
		dosya1.open("result_r_c.svg");
		dosya2.open("result_r_t.svg");
		dosya3.open("result_c_r.svg");
		dosya4.open("result_c_c.svg");
		dosya5.open("result_c_t.svg");
		dosya6.open("result_t_r.svg");
		dosya7.open("result_t_c.svg");
		dosya8.open("result_t_t.svg");	
		cout << "********R - R********" << endl; // arraylerde girilen bilgilerle, ekrana sekilin verileri yazdirilir, ComposedShape objesi olusturulur.
		cout << "Container width: " << R[0].get_width() << endl;
		cout << "Container height: " << R[0].get_height() << endl;
		cout << "İnner width: " << R[1].get_width() << endl;
		cout << "İnner height: " << R[1].get_height() << endl;
		ComposedShape CoShape1(R[0], R[1]); // arrayin elemani olan objenin constructorini cagiramadigimizdan gecici ComposedShape objesi kullanilarak atama yapilir.
		ComShape[0] = CoShape1;
		int count = ComShape[0].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[0] = &ComShape[0];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[0]->get_area() << "." << endl;
		dosya0 << *S[0];

		// ayni islemler devam eder.
		cout << "********R - C********" << endl;
		cout << "Container width: " << R[0].get_width() << endl;
		cout << "Container height: " << R[0].get_height() << endl;
		cout << "İnner radius: " << C[1].get_radius() << endl;
		ComposedShape CoShape2(R[0], C[1]);
		ComShape[1] = CoShape2;
		count = ComShape[1].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[1] = &ComShape[1];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[1]->get_area() << "." << endl;
		dosya1 << *S[1];
			
		cout << "********R - T********" << endl;
		cout << "Container width: " << R[0].get_width() << endl;
		cout << "Container height: " << R[0].get_height() << endl;
		cout << "İnner side: " << T[1].get_side() << endl;
		ComposedShape CoShape3(R[0], T[1]);
		ComShape[2] = CoShape3;
		count = ComShape[2].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[2] = &ComShape[2];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[2]->get_area() << "." << endl;
		dosya2 << *S[2];	

		cout << "********C - R********" << endl;		
		cout << "Container radius: " << C[0].get_radius() << endl;
		cout << "İnner width: " << R[2].get_width() << endl;
		cout << "İnner height: " << R[2].get_height() << endl;
		ComposedShape CoShape4(C[0], R[2]);
		ComShape[3] = CoShape4;
		count = ComShape[3].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[3] = &ComShape[3];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[3]->get_area() << "." << endl;
		dosya3 << *S[3];
		
		cout << "********C - C********" << endl;
		cout << "Container radius: " << C[0].get_radius() << endl;
		cout << "İnner radius: " << C[2].get_radius() << endl;
		ComposedShape CoShape5(C[0], C[2]);
		ComShape[4] = CoShape5;
		count = ComShape[4].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[4] = &ComShape[4];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[4]->get_area() << "." << endl;
		dosya4 << *S[4];
				
		cout << "********C - T********" << endl;
		cout << "Container radius: " << C[0].get_radius() << endl;
		cout << "İnner side: " << T[2].get_side() << endl;
		ComposedShape CoShape6(C[0], T[2]);
		ComShape[5] = CoShape6;
		count = ComShape[5].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[5] = &ComShape[5];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[5]->get_area() << "." << endl;
		dosya5 << *S[5];	

		cout << "********T - R********" << endl;
		cout << "Container side: " << T[0].get_side() << endl;
		cout << "İnner width: " << R[3].get_width() << endl;
		cout << "İnner height: " << R[3].get_height() << endl;
		ComposedShape CoShape7(T[0], R[3]);
		ComShape[6] = CoShape7;
		count = ComShape[6].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[6] = &ComShape[6];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[6]->get_area() << "." << endl;
		dosya6 << *S[6];

		cout << "********T - C********" << endl;
		cout << "Container side: " << T[0].get_side() << endl;
		cout << "İnner radius: " << C[3].get_radius() << endl;
		ComposedShape CoShape8(T[0], C[3]);
		ComShape[7] = CoShape8;
		count = ComShape[7].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[7] = &ComShape[7];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[7]->get_area() << "." << endl;
		dosya7 << *S[7];
			
		cout << "********T - T********" << endl;
		cout << "Container side: " << T[0].get_side() << endl;
		cout << "İnner side: " << T[3].get_side() << endl;
		ComposedShape CoShape9(T[0], T[3]);
		ComShape[8] = CoShape9;
		count = ComShape[8].optimalFit(); // ComposedShape::optimalFit() fonksiyonun geri donus degeri vektorun yani inner shapein eleman sayisini verir.
		S[8] = &ComShape[8];
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << S[8]->get_area() << "." << endl;
		cout << "You can change the shape values from driver file!!" << endl << endl;
		dosya8 << *S[8];


		cout << "********Bazi Operator Testleri********" << endl;
		Triangle T1(250), T2(350); 
		Circle C1(485), C2(666);
		Rectangle R1(125,333), R2(333,125);
		PolygonDyn Pd1(R2), Pd2(C2);
		PolygonVect Pv(T1);

		cout << "Olusturulmus tum Circle uzunluklari(cevre) toplami : " << Circle::get_total_perimeters() << endl;
		cout << "Olusturulmus tum Rectangle alanlari toplami : " << Rectangle::get_total_areas() << endl;
		cout << "Triangle T1(250), T2(350);" << endl;
		cout << "Circle C1(485), C2(666);" << endl;
		cout << "Rectangle R1(125,333), R2(333,125);" << endl;
		Shape *t1, *t2, *c1, *c2, *r1, *r2, *pd1, *pd2, *pv;
		t1 = &T1; t2 = &T2;
		c1 = &C1; c2 = &C2;
		r1 = &R1; r2 = &R2;
		pd1 = &Pd1; pd2 = &Pd2; pv = &Pv;
		ofstream dosya10, dosya11, dosya12;
		dosya10.open("result_rect_poly.svg");
		dosya11.open("result_circ_poly.svg");
		dosya12.open("result_tri_poly.svg");
		dosya10 << *pd1;
		dosya11 << *pd2;
		dosya12 << *pv;
		dosya10.close(); dosya11.close(); dosya12.close();
		cout << "R1 alani : " << r1->get_area() << endl;
		cout << "R2 alani : " << r2->get_area() << endl;
		cout << "T2 alani : " << t2->get_area() << endl;
		cout << "C1 alani : " << c1->get_area() << endl;
		if( *r1 == *r2){
			cout << "R1 == R2" << endl;
		}
		if( *t1 != *t2){
			cout << "T1 != T2" << endl;
		}
		if( *c1 <= *r2){
			cout << "C1 >= R2" << endl;
		}
		if( *c1 <= *c2){
			cout << "C1 <= C2" << endl;
		}
		*t1++;
		*c2--;
		++*r1;
		--*pd1;
		cout << "++R1" << endl;
		cout << "C2--" << endl;
		cout << "T1++" << endl;
		cout << "--Pd" << endl;
 		cout << "Operatorler uygulanabilir durumdadir." << endl;
		cout << "HW5" << endl;
	}catch(control i){
		i.hata();
	}
	return 0;
}
