#include <iostream>
#include <fstream>
#include <cmath>
#include "Circle.h"
#define PI 3.141592653589793238462643383279502884L // pi

class control : public exception{};
namespace cpp{
	Circle::Circle(double r){ // radius bilgisini assign eden Circle constructor.
		if( r < 0 ) throw control();
		else{
			radius = r;
			position_x = radius;
			position_y = radius;
			total_areas += get_area();	
			total_perimeters += get_perimeter();		
		}
	}

	void Circle::set_radius(double r){ 
		if( r < 0 ) throw control();
		else{
			radius = r;
			total_areas += get_area();	
			total_perimeters += get_perimeter();				
		}
	}

	double Circle::get_total_areas(){
		return total_areas;
	}
	double Circle::get_total_perimeters(){
		return total_perimeters;
	}

	double Circle::get_area(){
		return radius * radius * PI;
	}
	double Circle::get_perimeter(){
		return 2 * PI * radius;
	}

	Circle & Circle::operator++(){
		position_x++;
		position_y++;
		return *this;
	}
	Circle & Circle::operator--(){
		position_x--;
		position_y--;
		return *this;
	}
	Circle & Circle::operator++( int ){
		Circle *temp = new Circle(*this) ;
		position_x++;
		position_y++;
		return *temp;
	}
	Circle & Circle::operator--( int ){
		Circle *temp = new Circle(*this);
		position_x--;
		position_y--;
		return *temp;
	}

	Circle Circle::operator+(const double& size){
		if( size < 0 ) throw control();
		else{
			Circle temp;
			temp.radius = this->radius + size;
			return temp;			
		}
	}
	Circle Circle::operator-(const double& size){
		if( size < 0 ) throw control();
		else{
			Circle temp;
			temp.radius = this->radius - size;
			return temp;			
		}
	}
	bool Circle::operator== (Circle &c2){
		return ( this->get_area() == c2.get_area() );
	}
	bool Circle::operator!= (Circle &c2){
		return ( this->get_area() != c2.get_area() ); 
	}
	bool Circle::operator> (Circle &c2){
	    return ( this->get_area() > c2.get_area() );
	}
	bool Circle::operator< (Circle &c2){
	   return ( this->get_area() < c2.get_area() );
	}    	
	bool Circle::operator>= (Circle &c2){
		return ( this->get_area() >= c2.get_area() );
	}   
	bool Circle::operator<= (Circle &c2){
		return ( this->get_area() <= c2.get_area() );
	}

	ofstream &Circle::draw_shape(ofstream &dosya){
		dosya << " <circle cx=\""<< this->position_x << "\" cy=\"" << this->position_y << "\" r=\""<< this->radius << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" /> " << endl;
		return dosya;
	}
	ofstream &operator<<( ofstream &output, Circle &c ) { 
		output << " <circle cx=\""<< c.get_position_x() << "\" cy=\"" << c.get_position_y() << "\" r=\""<< c.get_radius() << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" /> " << endl;
		return output;            
	} 	
	ostream &operator<<( ostream &output, Circle &c ) {
		cout << "Shape: Circle" << endl; 
		cout << "Radius: " << c.get_radius() << endl;
		cout << "Area: " << c.get_area() << endl;
		cout << "Perimeter Length:  " << c.get_perimeter() << endl;
		return output;            
	}	
}



