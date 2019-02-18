#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "Triangle.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

Triangle::Triangle(double s){ // side bilgisini assign eden Triangle constructor.
	side = s;
}

int Triangle::draw(ofstream& dosya)const{ /* Triangle draw fonksiyonu, kucuk sekil icin gerekli bilgileri parametre olarak verilen dosyaya yazar. */
	dosya <<" <polygon points=\" "; 
	for( auto i = 0; i < 6; i++){
		dosya << position_t[i] << " ";
	} 
	dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;
}

