#ifndef Triangle_h_
#define Triangle_h_
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class Triangle{ // Triangle classi tanimlanir.
	public:
		Triangle(){
		}
		Triangle(double s);
		inline void set_side(double s){ // set ve get fonksiyonlari.
			side = s;
		}
		inline void set_position_t(double x, int i){
			position_t[i] = x;	
		}
		inline int get_side()const{ // get fonksiyonlari classin icinde bir degisiklik yapmadigindan const.
			return side;
		}
		inline int get_position_x(int i)const{
			return position_t[i];
		}
		int draw(ofstream& dosya)const;			
	private:
		double side;
		int position_t[6];	
};
#endif
