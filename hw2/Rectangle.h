#ifndef Rectangle_h_
#define Rectangle_h_
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class Rectangle{ // Rectangle classi tanimlanir.
	public: 
		Rectangle(){
		}
		Rectangle(double w, double h);
		inline void set_width(double w){ // set ve get fonksiyonlari.
			width = w;
		}
		inline void set_height(double h){
			height = h;
		}
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
		int draw(ofstream& dosya)const;		
	private:
		double width;
		double height;
		int position_x;
		int position_y;		
}; 
#endif
