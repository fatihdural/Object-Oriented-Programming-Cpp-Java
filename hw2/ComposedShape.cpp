#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;

ComposedShape::ComposedShape(Rectangle R1, Rectangle R2){ // overload constructlar ile girilen obje taninir ve ComposedShapein memberlerine assing edilir.
	container = 'R';
	small = 'R';
	this->R1 = R1;
	this->R2 = R2;
}
ComposedShape::ComposedShape(Rectangle R1, Circle C1){
	container = 'R';
	small = 'C';
	this->R1 = R1;
	this->C1 = C1;
}
ComposedShape::ComposedShape(Rectangle R1, Triangle T1){
	container = 'R';
	small = 'T';
	this->R1 = R1;
	this->T1 = T1;
}
ComposedShape::ComposedShape(Circle C1, Rectangle R1){
	container = 'C';
	small = 'R';
	this->C1 = C1;
	this->R1 = R1;
}
ComposedShape::ComposedShape(Circle C1, Circle C2){
	container = 'C';
	small = 'C';
	this->C1 = C1;
	this->C2 = C2;
}
ComposedShape::ComposedShape(Circle C1, Triangle T1){
	container = 'C';
	small = 'T';
	this->C1 = C1;
	this->T1 = T1;
}
ComposedShape::ComposedShape(Triangle T1, Rectangle R1){
	container = 'T';
	small = 'R';
	this->T1 = T1;
	this->R1 = R1;
}
ComposedShape::ComposedShape(Triangle T1, Circle C1){
	container = 'T';
	small = 'C';
	this->T1 = T1;
	this->C1 = C1;
}
ComposedShape::ComposedShape(Triangle T1, Triangle T2){
	container = 'T';
	small = 'T';
	this->T1 = T1;
	this->T2 = T2;
}

Rectangle ComposedShape::get_vectR(int i)const{ // inner shapeleri iceren vectorlerin cagirilmasi icin getter fonksiyonlari. belirli bir indisi cagirir.
	return vectR[i];
}
Circle ComposedShape::get_vectC(int i)const{
	return vectC[i];
}		
Triangle ComposedShape::get_vectT(int i)const{
	return vectT[i];
}

int ComposedShape::optimalFit(){ // cogu isi yapan fonksiyondur. objeyi tanir ve islemleri yapar.
	int count; // inner shape adetini tutan counter.
	if( container == 'R' && small == 'R' ){
		ofstream dosya;
		dosya.open("result_r_r.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Rectangle temp; // vectore push back yapmak icin gecici bir rectangle tutuyoruz, icini doldurduktan sonra vectore atanacak.
		double width = this->R1.get_width(); // daha anlasilir olmasi icin Rectangledaki verileri gecici atiyoruz.
		double height = this->R1.get_height();
		double small_width = this->R2.get_width();
		double small_height = this->R2.get_height();
		int x = 0, y = 0, flag = 0;
		while(1){
			temp.set_position_x(x); // temp objesine gerekli atamalar yapildiktan sonra vectore push back yapilir.
			temp.set_position_y(y);
			temp.set_width(small_width);
			temp.set_height(small_height);
			this->vectR.push_back(temp);
			x += small_width;
			if( x + small_width > width ){
				if( width - x >= small_height && flag == 0){
					double d_y = y;
					while(1){
						if( d_y + small_width > height){
							break;
						}
						temp.set_position_x(x);
						temp.set_position_y(d_y);
						temp.set_width(small_height);
						temp.set_height(small_width);
						this->vectR.push_back(temp);
						d_y += small_width;
					}
					flag++;
				}
				x = 0;
				y += small_height;
			}
			if( y + small_height > height){
				break;
			}
		}
		draw(dosya); // draw fonksiyonu cagirilir.
		count = vectR.size(); // adet atilir.
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();
	} 
	// kalan islemler aynidir. gecici objeler olusuturulur. algoritmaya gore gereken yerlerde atamalar yapilir. en son istenildigi uzere vectore e atilir.
	else if( container == 'R' && small == 'C' ){
		ofstream dosya;
		dosya.open("result_r_c.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Circle temp;
		double width = this->R1.get_width();
		double height = this->R1.get_height();
		double small_radius = this->C1.get_radius();
		this->R1.set_position_x(0);
		this->R1.set_position_y(0);
		int cx = small_radius, cy = small_radius;
		while(1){
			if( cy + small_radius > height){
				break;
			}
			temp.set_position_x(cx);
			temp.set_position_y(cy);
			temp.set_radius(small_radius);
			this->vectC.push_back(temp);
			if( cx + (3 * small_radius) > width){
				if( cy != small_radius){
					if( (cx + small_radius * sqrt(3) + small_radius) <= width && (cy + small_radius) <= height && (cy - small_radius) > 0 ){
						cx += small_radius * sqrt(3);
						cy -= small_radius;
						temp.set_position_x(cx);
						temp.set_position_y(cy);
						temp.set_radius(small_radius);
						this->vectC.push_back(temp);
						cx = small_radius;
						cy += 3 * small_radius;
					}
					else{
						cx = small_radius;	
						cy += 2 * small_radius;
					}	
				}
				else{
					cx = small_radius;
					cy += 2 * small_radius;
				}		
			}
			else
				cx += 2 * small_radius; 
		}	
		draw(dosya);
		count = vectC.size();	
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();					
	}
	
	else if( container == 'R' && small == 'T' ){
		ofstream dosya;
		dosya.open("result_r_t.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Triangle temp;
		double width = this->R1.get_width();
		double height = this->R1.get_height();
		double small_side = this->T1.get_side();
		this->R1.set_position_x(0);
		this->R1.set_position_y(0);
		double perp = small_side/2 * sqrt(3);
		double t[6] = {0, perp, small_side/2, 0, small_side, perp};
		while(1){
			for( int i = 0; i < 6; i++){
				temp.set_position_t(t[i], i);
				if( i % 2 == 0 ){
					t[i] += small_side;
				}
			} 
			temp.set_side(small_side);
			this->vectT.push_back(temp);
			if( t[0] + small_side > width){
				if( t[0] + small_side / 2 <= width){
					for( int i = 0; i < 6; i++){
						if( i % 2 == 0 ){
							t[i] -= small_side/2;
							temp.set_position_t(t[i], i);
							t[i] += small_side/2;
						}
						else if( i == 1 || i == 5){
							t[i] -= perp;
							temp.set_position_t(t[i], i);
							t[i] += perp;				
						}  
						else{
							t[i] += perp;
							temp.set_position_t(t[i], i);
							t[i] -= perp;					
						}                        				
					}
					temp.set_side(small_side);
					this->vectT.push_back(temp);
				}
				t[0] = 0;
				t[1] += perp;
				t[2] = small_side/2;
				t[3] += perp;
				t[4] = small_side;
				t[5] += perp;
			}
			else{
				for( int i = 0; i < 6; i++){
					if( i % 2 == 0 ){
						t[i] -= small_side/2;
						temp.set_position_t(t[i], i);
						t[i] += small_side/2;
					}
					else if( i == 1 || i == 5){
						t[i] -= perp;
						temp.set_position_t(t[i], i);
						t[i] += perp;				
					}  
					else{
						t[i] += perp;
						temp.set_position_t(t[i], i);
						t[i] -= perp;					
					}                        				
				}
				temp.set_side(small_side);
				this->vectT.push_back(temp);
			}							
			if( t[1] > height)
				break;	
		}
		draw(dosya);
		count = vectT.size();
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();		
	}
	
	else if( container == 'C' && small == 'R' ){
		ofstream dosya;
		dosya.open("result_c_r.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Rectangle temp;
		double radius = this->C1.get_radius();
		double small_width = this->R1.get_width();
		double small_height = this->R1.get_height();
		C1.set_position_x(radius);
		C1.set_position_y(radius);
		int counter = 0;
		int cx = radius;
		int cy = radius;
		int x = 0, y = 0;
		while(1){
			if( (sqrt( (cy - y) * (cy - y) + (cx - x) * (cx - x) ) < radius) && (sqrt( (cy - (y+small_height) ) * (cy -(y+small_height) ) + (cx - x) * (cx - x) ) < radius) &&
				(sqrt( (cy - y) * (cy - y) + (cx -(x + small_width) ) * (cx -(x+small_width) ) ) < radius) && (sqrt( (cy - (y+small_height)) * (cy -(y+small_height) ) + (cx -(x+small_width) ) * (cx -(x+small_width) ) ) < radius)
			){
				temp.set_position_x(x);
				temp.set_position_y(y);
				temp.set_width(small_width);
				temp.set_height(small_height);
				this->vectR.push_back(temp);
			}
			x += small_width;			
			if( x + small_width >= radius * 2){
				x = 0;
				y +=  small_height ;		
			}
			if( y + small_height >= radius * 2 ){
				break;		
			}
		}		
		draw(dosya);
		count = vectR.size();
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();	
	}

	else if ( container == 'C' && small == 'C' ){
		ofstream dosya;
		dosya.open("result_c_c.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Circle temp;
		double radius = this->C1.get_radius();
		double small_radius = this->C2.get_radius();
		C1.set_position_x(radius);
		C1.set_position_y(radius);
		int cx = radius, cy = radius;
		int x = small_radius, y = small_radius;
		while(1){	
			if( sqrt( (cy - y) * (cy - y) + (cx - x) * (cx - x) ) + small_radius <= radius){
				temp.set_position_x(x);
				temp.set_position_y(y);
				temp.set_radius(small_radius);
				this->vectC.push_back(temp);
			}
			x += 2 * small_radius;			
			if( x + small_radius > radius * 2){
				x = small_radius;
				y += small_radius * 2 ;		
			}
			if( y + small_radius > radius * 2 ){
				break;		
			}
		}
		draw(dosya);
		count = vectC.size();
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();
	}
	
	else if ( container == 'C' && small == 'T' ){
		ofstream dosya;
		dosya.open("result_c_t.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Triangle temp;
		double radius = this->C1.get_radius();
		double small_side = this->T1.get_side();
		C1.set_position_x(radius);
		C1.set_position_y(radius);
		int counter = 0;
		int cx = radius, cy = radius;
		int x = 0, y = 0;
		double perp = small_side/2 * sqrt(3);
		double t[6] = {0, perp, small_side/2, 0, small_side, perp};
		while(1){
			if( (sqrt( (cy - t[1]) * (cy - t[1]) + (cx - t[0]) * (cx - t[0]) ) < radius) && 
				(sqrt( (cy - t[3]) * (cy - t[3]) + (cx - t[2]) * (cx - t[2]) ) < radius) && 
				(sqrt( (cy - t[5]) * (cy - t[5]) + (cx - t[4]) * (cx - t[4]) ) < radius)
			){
				for( int i = 0; i < 6; i++){
					temp.set_position_t(t[i], i);
				} 
				temp.set_side(small_side);
				this->vectT.push_back(temp);
			}
			for( int i = 0; i < 6; i++){
				if( i % 2 == 0 ){
					t[i] += small_side;
				}
			}
			if( (sqrt( (cy - (t[1]-perp)) * (cy - (t[1]-perp)) + (cx - (t[0]- small_side / 2)) * (cx - (t[0]- small_side / 2)) ) < radius) && 
				(sqrt( (cy - (t[3]+perp)) * (cy - (t[3]+perp)) + (cx - (t[2]- small_side / 2)) * (cx - (t[2]- small_side / 2)) ) < radius) && 
				(sqrt( (cy - (t[5]-perp)) * (cy - (t[5]-perp)) + (cx - (t[4]- small_side / 2)) * (cx - (t[4]- small_side / 2)) ) < radius) 
			){
					for( int i = 0; i < 6; i++){
						if( i % 2 == 0 ){
							t[i] -= small_side/2;
							temp.set_position_t(t[i], i);
							t[i] += small_side/2;
						}
						else if( i == 1 || i == 5){
							t[i] -= perp;
							temp.set_position_t(t[i], i);
							t[i] += perp;				
						}  
						else{
							t[i] += perp;
							temp.set_position_t(t[i], i);
							t[i] -= perp;					
						}                        				
					}
	 			temp.set_side(small_side);
				this->vectT.push_back(temp);	
			}
			if( t[4] + small_side/2 > radius * 2){
				t[0] = 0;
				t[1] += perp;
				t[2] = small_side/2;
				t[3] += perp;
				t[4] = small_side;
				t[5] += perp;	
			}						
			if( t[1] > radius * 2){
				break;
			}			
		}
		draw(dosya);
		count = vectT.size();
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();
	}

	else if ( container == 'T' && small == 'R' ){
		ofstream dosya;
		dosya.open("result_t_r.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Rectangle temp;
		double side = T1.get_side();
		double small_width = R1.get_width();
		double small_height = R1.get_height();
		double d_side = side - small_height / sqrt(3);
		double perp = side/2 * sqrt(3);
		double x = small_height / sqrt(3);
		double y = perp - small_height;
		int flag = 1;
		T1.set_position_t(0,0);
		T1.set_position_t(perp,1);
		T1.set_position_t(side/2,2);
		T1.set_position_t(0,3);
		T1.set_position_t(side,4);
		T1.set_position_t(perp,5);
		while(1){
			if( x + small_width > d_side){
				break;
			}
			temp.set_position_x(x);
			temp.set_position_y(y);
			temp.set_width(small_width);
			temp.set_height(small_height);
			this->vectR.push_back(temp);
			x += small_width;
			if( x + small_width > d_side){
				y -= small_height;
				d_side = d_side - small_height / sqrt(3);
				x = small_height / sqrt(3) + flag * small_height / sqrt(3);
				flag++;
			}
			if ( y < 0){
				break;
			}	
		}		
		draw(dosya);
		count = vectR.size();	
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();	
	}
	
	else if ( container == 'T' && small == 'C' ){
		ofstream dosya;
		dosya.open("result_t_c.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Circle temp;
		double side = T1.get_side();
		double small_radius = C1.get_radius();
		double d_side = side - sqrt(3);
		int flag = 1;
		double perp = side/2 * sqrt(3);
		double cx = small_radius * sqrt(3);
		double cy = perp - small_radius;
		T1.set_position_t(0,0);
		T1.set_position_t(perp,1);
		T1.set_position_t(side/2,2);
		T1.set_position_t(0,3);
		T1.set_position_t(side,4);
		T1.set_position_t(perp,5);
		while(1){
			if( cx + small_radius * 2 >= d_side){
				break;
			}
			temp.set_position_x(cx);
			temp.set_position_y(cy);
			temp.set_radius(small_radius);
			this->vectC.push_back(temp);
			cx += small_radius * 2;
			if( cx + small_radius * 2 >= d_side){
				cy -= small_radius * sqrt(3);
				d_side = d_side - small_radius;
				cx = small_radius * sqrt(3) + flag * small_radius;
				flag++;
			}
			if ( cy - small_radius < 0){
				break;
			}	
		}
		draw(dosya);
		count = vectC.size();
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();
	}
	
	else if ( container == 'T' && small == 'T' ){
		ofstream dosya;
		dosya.open("result_t_t.svg"); // draw fonksiyonuna gonderilecek ofstream obje burda olusturulur.
		Triangle temp;
		double side = T1.get_side();
		double small_side = T2.get_side();
		double small_height = R1.get_height();
		int flag = -1;
		double perp = side/2 * sqrt(3);
		double small_perp = small_side/2 * sqrt(3);
		T1.set_position_t(0,0);
		T1.set_position_t(perp,1);
		T1.set_position_t(side/2,2);
		T1.set_position_t(0,3);
		T1.set_position_t(side,4);
		T1.set_position_t(perp,5);		
		double t[6] = {0, perp, small_side/2, perp-small_perp, small_side, perp};
		while(1){
			for( int i = 0; i < 6; i++){
				temp.set_position_t(t[i], i);
				if( i % 2 == 0 ){
					t[i] += small_side;
				}
			} 
			temp.set_side(small_side);
			this->vectT.push_back(temp);			
			if( t[0] + small_side > side){
				side -= small_side / 2;
				flag++;
				if( flag == 0){
					t[0] = small_side/2;
					t[1] -= small_perp;
					t[2] = small_side;
					t[3] -= small_perp;
					t[4] = small_side + small_side/2;
					t[5] -= small_perp;
				}
				else if( flag != 0){
					t[0] = small_side/2 + (flag * small_side/2);
					t[1] -= small_perp;
					t[2] = small_side + (flag * small_side/2);
					t[3] -= small_perp;
					t[4] = small_side + small_side/2 + (flag * small_side/2);
					t[5] -= small_perp;				
				}
			}
			else{
				for( int i = 0; i < 6; i++){
					if( i % 2 == 0 ){
						t[i] -= small_side/2;
						temp.set_position_t(t[i], i);
						t[i] += small_side/2;
					}
					else if( i == 1 || i == 5){
						t[i] -= small_perp;
						temp.set_position_t(t[i], i);
						t[i] += small_perp;				
					}  
					else{
						t[i] += small_perp;
						temp.set_position_t(t[i], i);
						t[i] -= small_perp;					
					}                        				
				}
				temp.set_side(small_side);
				this->vectT.push_back(temp);
			}
			if( t[1] - small_side <= 0){
				break;
			}		
		}
		draw(dosya);
		count = vectT.size();	
		dosya << "</svg>"; // dosya etiketi kapanir.
		dosya.close();	
	}
	return count;
}

int ComposedShape::draw(ofstream& dosya)const{ // ComposedShape deki karakterlere bakarak, objeler tanir.
	if( container == 'R' && small == 'R' ){
		dosya << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<< R1.get_width() << "\" height=\"" << R1.get_height() << "\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< "<rect width=\"100%\" height=\"100%\" fill=\"red\"/>" << endl;
		for( auto i = 0; i < vectR.size(); i++){ // inner shape basilir..
			get_vectR(i).draw(dosya);
		}	
	}
	else if( container == 'R' && small == 'C' ){
		dosya << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<< R1.get_width() << "\" height=\"" << R1.get_height() << "\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< "<rect width=\"100%\" height=\"100%\" fill=\"red\"/>" << endl;
		for( auto i = 0; i < vectC.size(); i++){ // inner shape basilir.
			get_vectC(i).draw(dosya);
		}	
	}
	else if( container == 'R' && small == 'T' ){
		dosya << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<< R1.get_width() << "\" height=\"" << R1.get_height() << "\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< "<rect width=\"100%\" height=\"100%\" fill=\"red\"/>" << endl;
		for( auto i = 0; i < vectT.size(); i++){ // inner shape basilir.
			get_vectT(i).draw(dosya);
		}	
	}
	else if( container == 'C' && small == 'R' ){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< " <circle cx=\""<< C1.get_position_x() << "\" cy=\"" << C1.get_position_y() << "\" r=\""<< C1.get_radius() << "\" fill=\"red\"/> " << endl;
		for( auto i = 0; i < vectR.size(); i++){ // inner shape basilir.
			get_vectR(i).draw(dosya);
		}		
	}
	else if( container == 'C' && small == 'C' ){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< " <circle cx=\""<< C1.get_position_x() << "\" cy=\"" << C1.get_position_y() << "\" r=\""<< C1.get_radius() << "\" fill=\"red\"/> " << endl;
		for( auto i = 0; i < vectC.size(); i++){ // inner shape basilir.
			get_vectC(i).draw(dosya);
		}		
	}
	else if( container == 'C' && small == 'T' ){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< " <circle cx=\""<< C1.get_position_x() << "\" cy=\"" << C1.get_position_y() << "\" r=\""<< C1.get_radius() << "\" fill=\"red\"/> " << endl;
		for( auto i = 0; i < vectT.size(); i++){ // inner shape basilir.
			get_vectT(i).draw(dosya);
		}	
	}
	else if( container == 'T' && small == 'R' ){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< 	" <polygon points=\"" << "0 " << T1.get_side()/2 * sqrt(3) << " " << T1.get_side() / 2 << " 0 " << T1.get_side() << " " << T1.get_side()/2 * sqrt(3) << "\"" << " fill=\"red\" />" << endl;
		for( auto i = 0; i < vectR.size(); i++){ // inner shape basilir.
			get_vectR(i).draw(dosya);
		}		
	}
	else if( container == 'T' && small == 'C' ){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< 	" <polygon points=\"" << "0 " << T1.get_side()/2 * sqrt(3) << " " << T1.get_side() / 2 << " 0 " << T1.get_side() << " " << T1.get_side()/2 * sqrt(3) << "\"" << " fill=\"red\" />" << endl;
		for( auto i = 0; i < vectC.size(); i++){ // inner shape basilir.
			get_vectC(i).draw(dosya);
		}		
	}
	else if( container == 'T' && small == 'T' ){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< 	" <polygon points=\"" << "0 " << T1.get_side()/2 * sqrt(3) << " " << T1.get_side() / 2 << " 0 " << T1.get_side() << " " << T1.get_side()/2 * sqrt(3) << "\"" << " fill=\"red\" />" << endl;
		for( auto i = 0; i < vectT.size(); i++){ // inner shape basilir.
			get_vectT(i).draw(dosya);
		}	
	} 			
}
