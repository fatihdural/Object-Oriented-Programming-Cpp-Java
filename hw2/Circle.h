#ifndef Circle_h_
#define Circle_h_
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class Circle{ // Circle classi tanimalanir.
	public:
		Circle(){
		}
		Circle(double r);
		inline void set_radius(double r){ // set ve get fonksiyonlari.
			radius = r;
		}
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
		int draw(ofstream& dosya)const;			
	private:
		double radius;
		int position_x;
		int position_y;		
};
#endif
