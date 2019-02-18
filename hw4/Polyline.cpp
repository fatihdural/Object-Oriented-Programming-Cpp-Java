#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include "Polyline.h"
#include "Polygon.h"


#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

Polyline::Polyline(vector<Polygon::Point2D> point2d){
	int count = point2d.size();
	P.set_points_mem(count);
	for( int i = 0; i < count; i++){
		this->P[i] = point2d[i];
	}
}

Polyline::Polyline(Polygon::Point2D point){
	int count = 1;
	P.set_points_mem(count);
	P.set_po_points(point.get_x(), point.get_y());
}

Polyline::Polyline(Rectangle R){
	Polygon temp(R);
	this->P = temp;
}

Polyline::Polyline(Circle C){
	Polygon temp(C);
	this->P = temp;
}

Polyline::Polyline(Triangle T){
	Polygon temp(T);
	this->P = temp;
}
ofstream &operator<<( ofstream &dosya, Polyline &po ){
	int count = po.P.get_count();
	dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl;
	dosya <<" <polyline points=\""; 
	for( auto i = 0; i < count; i++){
		dosya << po.P[i].get_x() << " ";
		dosya << po.P[i].get_y() << " ";
	} 
	dosya << "\" style=\"fill:none;stroke:black;stroke-width:1\" /> " << endl;
	dosya << "</svg>";
	return dosya;
}
ostream &operator<<( ostream &output, Polyline &po ){
	char type = po.P.get_type(); 
	cout << "***Polyline***" << endl;
	if(  type == 'R' ){
		double width = po.P[1].get_x() - po.P[0].get_x(); 
		double height = po.P[3].get_y() - po.P[0].get_y();	
		cout << "Length: " << width << endl;
		cout << "Length: " << height << endl;
	}
	else if( type == 'C' ){
		double radius = po.P[0].get_x();
		cout << "Length: " << radius << endl;
	}
	else if( type == 'T' ){
		double side = po.P[2].get_x() - po.P[0].get_x();
		cout << "Length: " << side << endl;
	}
	return output;	
}