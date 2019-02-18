#include <iostream>
#include <fstream>
#include <cmath>
#include "Circle.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;
using namespace circle;
Circle::Circle(double r){ // radius bilgisini assign eden Circle constructor.
	radius = r;
	position_x = radius;
	position_y = radius;
	total_areas += get_area();	
	total_perimeters += get_perimeter();
}

double Circle::get_total_areas(){
	return total_areas;
}

double Circle::get_total_perimeters(){
	return total_perimeters;
}

void Circle::set_radius(double r){ 
	radius = r;
	total_areas += get_area();	
	total_perimeters += get_perimeter();			
}

const Circle Circle::operator++(){
	position_x++;
	position_y++;
	return *this;
}
const Circle Circle::operator--(){
	position_x--;
	position_y--;
	return *this;
}
const Circle Circle::operator++( int ){
	Circle temp(this->radius);
	position_x++;
	position_y++;
	return temp;
}
const Circle Circle::operator--( int ){
	Circle temp(this->radius);
	position_x--;
	position_y--;
	return temp;
}
const Circle Circle::operator+(const double& size){
	Circle temp;
	temp.radius = this->radius + size;
	return temp;
}
const Circle Circle::operator-(const double& size){
	Circle temp;
	temp.radius = this->radius - size;			
	return temp;
}
const bool Circle::operator== (const Circle &c2){
	return ( this->get_area() == c2.get_area() );
}
const bool Circle::operator!= (const Circle &c2){
	return ( this->get_area() != c2.get_area() ); 
}
const bool Circle::operator> (const Circle &c2){
    return ( this->get_area() > c2.get_area() );
}
const bool Circle::operator< (const Circle &c2){
   return ( this->get_area() < c2.get_area() );
}    	
const bool Circle::operator>= (const Circle &c2){
	return ( this->get_area() >= c2.get_area() );
}   
const bool Circle::operator<= (const Circle &c2){
	return ( this->get_area() <= c2.get_area() );
}

ofstream &operator<<( ofstream &output, const Circle &c ) { 
	output << " <circle cx=\""<< c.get_position_x() << "\" cy=\"" << c.get_position_y() << "\" r=\""<< c.get_radius() << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" /> " << endl;
	return output;            
} 	
ostream &operator<<( ostream &output, const Circle &c ) {
	cout << "Shape: Circle" << endl; 
	cout << "Radius: " << c.get_radius() << endl;
	cout << "Area: " << c.get_area() << endl;
	cout << "Perimeter Length:  " << c.get_perimeter() << endl;
	return output;            
}


