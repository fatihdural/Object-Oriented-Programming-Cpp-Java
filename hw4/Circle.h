#ifndef Circle_h_
#define Circle_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

namespace circle{
	class Circle{ // Circle classi tanimalanir.
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
			inline double get_area()const{
				return radius * radius * PI;
			}
			inline double get_perimeter()const{
				return 2 * PI * radius;
			}
			const Circle operator++();
			const Circle operator--();
			const Circle operator++(int);
			const Circle operator--(int);
			const Circle operator+(const double& size);
			const Circle operator-(const double& size);
			const bool operator== (const Circle &c2);
	    	const bool operator!= (const Circle &c2);
	    	const bool operator> (const Circle &c2);
	    	const bool operator< (const Circle &c2);    	
	    	const bool operator>= (const Circle &c2);
	    	const bool operator<= (const Circle &c2);
	      	friend ofstream &operator<<( ofstream &output, const Circle &c );     
	      	friend ostream &operator<<( ostream &output, const Circle &c );
		private:
			double radius;
			int position_x;
			int position_y;		
	};
}
#endif
