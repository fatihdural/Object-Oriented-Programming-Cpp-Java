#include <iostream>
#include <fstream>
#include <math.h>
#include "Circle.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

Circle::Circle(double r){ // radius bilgisini assign eden Circle constructor.
	radius = r;
}

int Circle::draw(ofstream& dosya)const{ // Circle draw fonksiyonu, kucuk sekil icin gerekli bilgileri parametre olarak verilen dosyaya yazar. 
	dosya << " <circle cx=\""<< position_x << "\" cy=\"" << position_y << "\" r=\""<< radius << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" /> " << endl;
}

