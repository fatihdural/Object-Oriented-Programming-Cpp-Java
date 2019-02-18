#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "Rectangle.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;
class control : public exception{};
namespace cpp{
	Rectangle::Rectangle(double w, double h){ // private bilgileri isleyecek Rectangle constructor.
		if( w < 0 || h < 0 ) throw control();
		else{
			width = w;
			height = h;
			position_x = 0;
			position_y = 0;
			total_areas += get_area();	
			total_perimeters += get_perimeter();			
		}
	}

	void Rectangle::set_wh(double w, double h){ // set ve get fonksiyonlari.
		if( w < 0 || h < 0 ) throw control();
		else{
			width = w;
			height = h;
			total_areas += get_area();	
			total_perimeters += get_perimeter();			
		}		
	}

	double Rectangle::get_area(){
		return width * height;
	}
	double Rectangle::get_perimeter(){
		return 2 * (width + height);
	}
	double Rectangle::get_total_areas(){
		return total_areas;
	}
	double Rectangle::get_total_perimeters(){
		return total_perimeters;
	}

	 Rectangle & Rectangle::operator++(){
		position_x++;
		position_y++;
		return *this;
	}
	 Rectangle & Rectangle::operator--(){
		position_x--;
		position_y--;
		return *this;
	}
	 Rectangle & Rectangle::operator++( int ){
		Rectangle *temp = new Rectangle(*this);
		position_x++;
		position_y++;
		return *temp;
	}
	 Rectangle & Rectangle::operator--( int ){
		Rectangle *temp = new Rectangle(*this);
		position_x--;
		position_y--;
		return *temp;
	}	

	Rectangle Rectangle::operator+( const double& size){
		if( size < 0 ) throw control();
		else{
			Rectangle temp;
			temp.width = this->width + size;
			temp.height = this->height + size;
			return temp;			
		}
	}
	Rectangle Rectangle::operator-( const double& size){
		if( size < 0 ) throw control();
		else{
			Rectangle temp;
			temp.width = this->width - size;
			temp.height = this->height - size;
			return temp;			
		}
	}

	bool Rectangle::operator== (Rectangle &r2){
		return ( this->get_area() == r2.get_area() );
	}
	bool Rectangle::operator!= (Rectangle &r2){
		return ( this->get_area() != r2.get_area() ); 
	}
	bool Rectangle::operator> (Rectangle &r2){
		return ( this->get_area() > r2.get_area() );
	}
	bool Rectangle::operator< (Rectangle &r2){
		return ( this->get_area() < r2.get_area() );
	}    	
	bool Rectangle::operator>= (Rectangle &r2){
		return ( this->get_area() >= r2.get_area() );
	}   
	bool Rectangle::operator<= (Rectangle &r2){
		return ( this->get_area() <= r2.get_area() );
	}   	

	ofstream & Rectangle::draw_shape(ofstream &dosya){
		dosya << "<rect x=\""<< this->position_x << "\" y=\"" << this->position_y << "\" width=\""<< this->width << "\" height=\"" << this->height << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;
		return dosya;
	}

	ofstream &operator<<( ofstream &output, Rectangle &r ) { 
		output << "<rect x=\""<< r.position_x << "\" y=\"" << r.position_y << "\" width=\""<< r.width << "\" height=\"" << r.height << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;
		return output;            
	} 	
	ostream &operator<<( ostream &output, Rectangle &r ) { 
		cout << "Shape: Rectangle" << endl; 
		cout << "Width: " << r.get_width() << endl;
		cout << "Height: " << r.get_height() << endl;
		cout << "Area: " << r.get_area() << endl;
		cout << "Perimeter Length:  " << r.get_perimeter() << endl;
		return output;            
	}	
}
