#ifndef Rectangle_h_
#define Rectangle_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Shape.h"

using namespace std;

namespace cpp{
	class Rectangle : public Shape{ // Rectangle classi tanimlanir.
		public: 
			static double total_areas;
			static double total_perimeters;
			static double get_total_areas();
			static double get_total_perimeters();	
			Rectangle(){}
			Rectangle(double w, double h);
			void set_wh(double w, double h); // set ve get fonksiyonlari.
			inline void set_position_x(int x){
				position_x = x;
			}
			inline void set_position_y(int y){
				position_y = y;
			}
			inline int get_width()const{ // get fonksiyonlari classin icinde bir degisiklik yapmadigindan const.
				return width;
			}
			inline int get_height()const{
				return height;
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
			virtual Rectangle & operator++();
			virtual Rectangle & operator--();
			virtual Rectangle & operator++(int);
			virtual Rectangle & operator--(int);
			Rectangle operator+(const double& size);
			Rectangle operator-(const double& size);
			bool operator== (Rectangle &r2);
	    	bool operator!= (Rectangle &r2);
	    	bool operator> (Rectangle &r2);
	    	bool operator< (Rectangle &r2);    	
	    	bool operator>= (Rectangle &r2);
	    	bool operator<= (Rectangle &r2);
	      	friend ofstream &operator<<( ofstream &output, Rectangle &r );     
	      	friend ostream &operator<<( ostream &output, Rectangle &r );
		private:
			double width;
			double height;
			int position_x;
			int position_y;		
	}; 	
}
#endif
