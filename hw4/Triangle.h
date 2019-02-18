#ifndef Triangle_h_
#define Triangle_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

class Triangle{ // Triangle classi tanimlanir.
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
		inline double get_area()const{
			return (side * side * sqrt(3)) / 4;
		}
		inline double get_perimeter()const{
			return 3 * side;
		}		
		const Triangle operator++();
		const Triangle operator--();
		const Triangle operator++(int);
		const Triangle operator--(int);
		const Triangle operator+(const double& size);
		const Triangle operator-(const double& size);
		const bool operator== (const Triangle &t2);
    	const bool operator!= (const Triangle &t2);
    	const bool operator> (const Triangle &t2);
    	const bool operator< (const Triangle &t2);    	
    	const bool operator>= (const Triangle &t2);
    	const bool operator<= (const Triangle &t2);
      	friend ofstream &operator<<( ofstream &output, Triangle &t );     
      	friend ostream &operator<<( ostream &output, Triangle &t );
	private:
		double side;
		int position_t[6];	
};
#endif
