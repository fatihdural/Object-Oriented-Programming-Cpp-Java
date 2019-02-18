#ifndef Circle_h_
#define Circle_h_
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "Shape.h"

using namespace std;

namespace cpp{
	class Circle : public Shape{ // Circle classi tanimalanir.
		public:
			static double total_areas;
			static double total_perimeters;
			static double get_total_areas();
			static double get_total_perimeters();
			Circle(){}
			Circle(double r);
			void set_radius(double r); // set ve get fonksiyonlari.
			inline void set_position_x(int x){
				position_x = x;
			}
			inline void set_position_y(int y){
				position_y = y;
			}
			inline int get_radius()const{ // get fonksiyonlari classin icinde bir degisiklik yapmadigindan const.
				return radius;
			}
			inline int get_position_x()const{
				return position_x;
			}
			inline int get_position_y()const{
				return position_y;
			}
			virtual double get_area();
			virtual double get_perimeter();
			virtual ofstream &draw_shape(ofstream &dosya);
			virtual Circle & operator++();
			virtual Circle & operator--();
			virtual Circle & operator++(int);
			virtual Circle & operator--(int);
			Circle operator+(const double& size);
			Circle operator-(const double& size);
			bool operator== (Circle &c2);
	    	bool operator!= (Circle &c2);
	    	bool operator> (Circle &c2);
	    	bool operator< (Circle &c2);    	
	    	bool operator>= (Circle &c2);
	    	bool operator<= (Circle &c2);
	      	friend ofstream &operator<<( ofstream &output, Circle &c );     
	      	friend ostream &operator<<( ostream &output, Circle &c );
		private:
			double radius;
			int position_x;
			int position_y;		
	};	
}
#endif