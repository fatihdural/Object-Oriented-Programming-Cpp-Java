#include <iostream>
#include <fstream>
#include <cmath>
#include "Shape.h"
#include "Polygon.h"
#include "PolygonDyn.h"
#include <typeinfo>

namespace cpp{
	void printAll(ofstream &dosya, vector<Shape *> S){
		dosya << ":D :D " << endl;
		for( int i = 0; i < S.size(); i++){
			S[i]->draw_shape(dosya);
		}

	}

	void printPoly(ofstream &dosya, vector<Shape *> S){
		for( int i = 0; i < S.size(); i++){
			if( typeid(S[i]) == typeid(Polygon) ){
				S[i]->draw_shape(dosya);	
			}
		}
	}

	vector<Shape *> convertAll(vector<Shape *> S){
		for( int i = 0; i < S.size(); i++){
			//PolygonDyn Pd( *( static_cast<Polygon>(S[i])) );
			//S[i] = &Pd;
		}

	}
	void sortShapes(vector<Shape *> S){
		for( int i = 0; i < S.size(); i++){
			for( int j = 1; j < S.size(); j++){
				if( S[i] < S[j]){
					Shape * temp = S[i];
					S[i] = S[j];
					S[i] = temp;
				}
			}
		}
	}

	ofstream &operator<<( ofstream &dosya, Shape &s ){
		s.draw_shape(dosya);
		return dosya;
	}

	bool Shape::operator== (Shape &s2){ 
		return ( this->get_area() == s2.get_area() );
	}
	bool Shape::operator!= (Shape &s2){
		return ( this->get_area() != s2.get_area() ); 
	}
	bool Shape::operator> (Shape &s2){
	    return ( this->get_area() > s2.get_area() );
	}
	bool Shape::operator< (Shape &s2){
	   return ( this->get_area() < s2.get_area() );
	}    	
	bool Shape::operator>= (Shape &s2){
		return ( this->get_area() >= s2.get_area() );
	}   
	bool Shape::operator<= (Shape &s2){
		return ( this->get_area() <= s2.get_area() );
	}	
}
