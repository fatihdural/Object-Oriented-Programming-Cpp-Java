#ifndef Rectangle_h_
#define Rectangle_h_
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;
class Rectangle{ // Rectangle classi tanimlanir.
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
		inline double get_area()const{
			return width * height;
		}
		inline double get_perimeter()const{
			return 2 * (width + height);
		}		
		const Rectangle operator++();
		const Rectangle operator--();
		const Rectangle operator++(int);
		const Rectangle operator--(int);
		const Rectangle operator+(const double& size);
		const Rectangle operator-(const double& size);
		const bool operator== (const Rectangle &r2);
    	const bool operator!= (const Rectangle &r2);
    	const bool operator> (const Rectangle &r2);
    	const bool operator< (const Rectangle &r2);    	
    	const bool operator>= (const Rectangle &r2);
    	const bool operator<= (const Rectangle &r2);
      	friend ofstream &operator<<( ofstream &output, const Rectangle &r );     
      	friend ostream &operator<<( ostream &output, const Rectangle &r );
	private:
		double width;
		double height;
		int position_x;
		int position_y;		
}; 	

#endif
