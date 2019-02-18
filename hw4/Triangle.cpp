#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Triangle.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

Triangle::Triangle(double s){ // side bilgisini assign eden Triangle constructor.
	side = s;
	double perp = side / 2 * sqrt(3);
	total_areas += get_area();	
	total_perimeters += get_perimeter();
	set_position_t(0,0);
	set_position_t(perp,1);
	set_position_t(side/2,2);
	set_position_t(0,3);
	set_position_t(side,4);
	set_position_t(perp,5);
}

double Triangle::get_total_areas(){
	return total_areas;
}
double Triangle::get_total_perimeters(){
	return total_perimeters;
}
void Triangle::set_side(double s){ // set ve get fonksiyonlari.
	side = s;
	total_areas += get_area();	
	total_perimeters += get_perimeter();
}

const Triangle Triangle::operator++(){
	for( int i = 0; i < 6; i++){
		position_t[i]++;
	}
	return *this;
}
const Triangle Triangle::operator--(){
	for( int i = 0; i < 6; i++){
		position_t[i]--;
	}
	return *this;
}
const Triangle Triangle::operator++( int ){
	Triangle temp(this->side);
	for( int i = 0; i < 6; i++){
		position_t[i]++;
	}
	return temp;
}
const Triangle Triangle::operator--( int ){
	Triangle temp(this->side);
	for( int i = 0; i < 6; i++){
		position_t[i]--;
	}
	return temp;
}

const Triangle Triangle::operator+(const double& size){
	Triangle temp;
	temp.side = this->side + size;
	return temp;
}
const Triangle Triangle::operator-(const double& size){
	Triangle temp;
	temp.side = this->side - size;
	return temp;
}	

const bool Triangle::operator== (const Triangle &t2){
	return ( this->get_area() == t2.get_area() );
}
const bool Triangle::operator!= (const Triangle &t2){
	return ( this->get_area() != t2.get_area() ); 
}
const bool Triangle::operator> (const Triangle &t2){
    return ( this->get_area() > t2.get_area() );
}
const bool Triangle::operator< (const Triangle &t2){
    return ( this->get_area() < t2.get_area() );
}    	
const bool Triangle::operator>= (const Triangle &t2){
    return ( this->get_area() >= t2.get_area() );
}   
const bool Triangle::operator<= (const Triangle &t2){
    return ( this->get_area() <= t2.get_area() );
}  
     
ofstream &operator<<( ofstream &output, Triangle &t ) { 
	output <<" <polygon points=\" "; 
	for( auto i = 0; i < 6; i++){
		output << t.position_t[i] << " ";
	} 
	output << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;
	return output;            
} 	
ostream &operator<<( ostream &output, Triangle &t ) { 
	cout << "Shape: Triangle" << endl; 
	cout << "Side of triangle edge: " << t.get_side() << endl;
	cout << "Area: " << t.get_area() << endl;
	cout << "Perimeter Length:  " << t.get_perimeter() << endl;
	return output;              
} 

