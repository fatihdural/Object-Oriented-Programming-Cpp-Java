#ifndef Triangle_h_
#define Triangle_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Shape.h"

using namespace std;

namespace cpp{
	class Triangle : public Shape { // Triangle classi tanimlanir.
		public:
			static double total_areas;
			static double total_perimeters;
			static double get_total_areas();
			static double get_total_perimeters();
			Triangle(){}
			Triangle(double s);
			void set_side(double s);// set ve get fonksiyonlari.
			inline void set_position_t(double x, int i){
				position_t[i] = x;	
			}
			inline int get_side()const{ // get fonksiyonlari classin icinde bir degisiklik yapmadigindan const.
				return side;
			}
			inline int get_position_t(int i)const{
				return position_t[i];
			}
			virtual double get_area();
			virtual double get_perimeter();		
			virtual ofstream &draw_shape(ofstream &dosya);
			virtual Triangle & operator++();
			virtual Triangle & operator--();
			virtual Triangle & operator++(int);
			virtual Triangle & operator--(int);
			Triangle operator+(const double& size);
			Triangle operator-(const double& size);
			bool operator== (Triangle &t2);
	    	bool operator!= (Triangle &t2);
	    	bool operator> (Triangle &t2);
	    	bool operator< (Triangle &t2);    	
	    	bool operator>= (Triangle &t2);
	    	bool operator<= (Triangle &t2);
	      	friend ofstream &operator<<( ofstream &output, Triangle &t );     
	      	friend ostream &operator<<( ostream &output, Triangle &t );
		private:
			double side;
			int position_t[6];	
	};	
}
#endif
