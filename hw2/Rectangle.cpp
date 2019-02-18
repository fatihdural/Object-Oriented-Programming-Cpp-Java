#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "Rectangle.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

Rectangle::Rectangle(double w, double h){ // private bilgileri isleyecek Rectangle constructor.
	width = w;
	height = h;
}

int Rectangle::draw(ofstream& dosya)const{ // Rectangle draw fonksiyonu, kucuk sekil icin gerekli bilgileri parametre olarak verilen dosyaya yazar. 
	dosya << "<rect x=\""<< position_x << "\" y=\"" << position_y << "\" width=\""<< width << "\" height=\"" << height << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;
}
