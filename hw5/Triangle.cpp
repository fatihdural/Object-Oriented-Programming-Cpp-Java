#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Triangle.h"

#define PI 3.141592653589793238462643383279502884L // pi
class control : public exception{};
namespace cpp{
	Triangle::Triangle(double s){ // side bilgisini assign eden Triangle uctor.
		if( s < 0)throw control();
		else{
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
	}

	void Triangle::set_side(double s){ // set ve get fonksiyonlari.
		if( s < 0)throw control();
		else{
			side = s;
			total_areas += get_area();	
			total_perimeters += get_perimeter();			
		}
	}

	double Triangle::get_area(){
		return (side * side * sqrt(3)) / 4.0;
	}

	double Triangle::get_perimeter(){
		return 3 * side;
	}

	double Triangle::get_total_areas(){
		return total_areas;
	}
	double Triangle::get_total_perimeters(){
		return total_perimeters;
	}


	Triangle & Triangle::operator++(){
		for( int i = 0; i < 6; i++){
			position_t[i]++;
		}
		return *this;
	}
	Triangle & Triangle::operator--(){
		for( int i = 0; i < 6; i++){
			position_t[i]--;
		}
		return *this;
	}
	Triangle & Triangle::operator++( int ){
		Triangle * temp = new Triangle(*this);
		for( int i = 0; i < 6; i++){
			position_t[i]++;
		}
		return *temp;
	}
	Triangle & Triangle::operator--( int ){
		Triangle * temp = new Triangle(*this);
		for( int i = 0; i < 6; i++){
			position_t[i]--;
		}
		return *temp;
	}

	Triangle Triangle::operator+(const double& size){
		if( size < 0)throw control();
		else{
			Triangle temp;
			temp.side = this->side + size;
			return temp;		
		}
	}
	Triangle Triangle::operator-(const double& size){
		if( size < 0)throw control();
		else{
			Triangle temp;
			temp.side = this->side - size;
			return temp;
		}
	}	

	bool Triangle::operator== (Triangle &t2){
		return ( this->get_area() == t2.get_area() );
	}
	bool Triangle::operator!= (Triangle &t2){
		return ( this->get_area() != t2.get_area() ); 
	}
	bool Triangle::operator> (Triangle &t2){
	    return ( this->get_area() > t2.get_area() );
	}
	bool Triangle::operator< (Triangle &t2){
	    return ( this->get_area() < t2.get_area() );
	}    	
	bool Triangle::operator>= (Triangle &t2){
	    return ( this->get_area() >= t2.get_area() );
	}   
	bool Triangle::operator<= (Triangle &t2){
	    return ( this->get_area() <= t2.get_area() );
	} 

	ofstream &Triangle::draw_shape(ofstream &dosya){
		dosya <<" <polygon points=\" "; 
		for( auto i = 0; i < 6; i++){
			dosya << this->position_t[i] << " ";
		} 
		dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;

		return dosya;
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
}


