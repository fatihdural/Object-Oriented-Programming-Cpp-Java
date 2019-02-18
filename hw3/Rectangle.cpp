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
	position_x = 0;
	position_y = 0;
	total_areas += get_area();	
	total_perimeters += get_perimeter();
}
double Rectangle::get_total_areas(){
	return total_areas;
}
double Rectangle::get_total_perimeters(){
	return total_perimeters;
}
void Rectangle::set_wh(double w, double h){ // set ve get fonksiyonlari.
	width = w;
	height = h;
	total_areas += get_area();	
	total_perimeters += get_perimeter();
}
const Rectangle Rectangle::operator++(){
	position_x++;
	position_y++;
	return *this;
}
const Rectangle Rectangle::operator--(){
	position_x--;
	position_y--;
	return *this;
}
const Rectangle Rectangle::operator++( int ){
	Rectangle temp(this->width, this->height);
	position_x++;
	position_y++;
	return temp;
}
const Rectangle Rectangle::operator--( int ){
	Rectangle temp(this->width, this->height);
	position_x--;
	position_y--;
	return temp;
}	

const Rectangle Rectangle::operator+(const double& size){
	Rectangle temp;
	temp.width = this->width + size;
	temp.height = this->height + size;
	return temp;
}
const Rectangle Rectangle::operator-(const double& size){
	Rectangle temp;
	temp.width = this->width - size;
	temp.height = this->height - size;
	return temp;
}

const bool Rectangle::operator== (const Rectangle &r2){
	return ( this->get_area() == r2.get_area() );
}
const bool Rectangle::operator!= (const Rectangle &r2){
	return ( this->get_area() != r2.get_area() ); 
}
const bool Rectangle::operator> (const Rectangle &r2){
	return ( this->get_area() > r2.get_area() );
}
const bool Rectangle::operator< (const Rectangle &r2){
	return ( this->get_area() < r2.get_area() );
}    	
const bool Rectangle::operator>= (const Rectangle &r2){
	return ( this->get_area() >= r2.get_area() );
}   
const bool Rectangle::operator<= (const Rectangle &r2){
	return ( this->get_area() <= r2.get_area() );
}   	

ofstream &operator<<( ofstream &output, const Rectangle &r ) { 
	output << "<rect x=\""<< r.position_x << "\" y=\"" << r.position_y << "\" width=\""<< r.width << "\" height=\"" << r.height << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;
	return output;            
} 	
ostream &operator<<( ostream &output, const Rectangle &r ) { 
	cout << "Shape: Rectangle" << endl; 
	cout << "Width: " << r.get_width() << endl;
	cout << "Height: " << r.get_height() << endl;
	cout << "Area: " << r.get_area() << endl;
	cout << "Perimeter Length:  " << r.get_perimeter() << endl;
	return output;            
}
