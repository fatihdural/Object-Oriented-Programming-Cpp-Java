#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#define PI 3.141592653589793238462643383279502884L // pi

using namespace std;
ComposedShape::ComposedShape(Polygon P1, Polygon P2){ // iki poligon alinir.
	if( P1.get_type() == 'R' ){
		container = shapes::R;
		this->P1 = P1;
	}
	else if( P1.get_type() == 'C' ){
		container = shapes::C;
		this->P1 = P1;
	}
	else if( P1.get_type() == 'T' ){
		container = shapes::T;
		this->P1 = P1;	
	}
	if( P2.get_type() == 'R' ){
		small = shapes::R;
		this->P2 = P2;		
	}
	else if( P2.get_type() == 'C' ){
		small = shapes::C;
		this->P2 = P2;
	}
	else if( P2.get_type() == 'T' ){
		small = shapes::T;									
		this->P2 = P2;
	}
}

int ComposedShape::optimalFit(){ // cogu isi yapan fonksiyondur. objeyi tanir ve islemleri yapar.
	int count; // inner shape adetini tutan counter.
	if( container == shapes::R && small == shapes::R ){
		double width = this->P1[1].get_x() - this->P1[0].get_x();  // daha anlasilir olmasi icin Rectangledaki verileri gecici atiyoruz.
		double height = this->P1[3].get_y() - this->P1[0].get_y(); 
		double small_width = this->P2[1].get_x() - this->P2[0].get_x();  // daha anlasilir olmasi icin Rectangledaki verileri gecici atiyoruz.
		double small_height = this->P2[3].get_y() - this->P2[0].get_y(); 
		if( width < small_width || height < small_height ){
			return 0;
		}
		int x = 0, y = 0, flag = 0;
		while(1){
			Rectangle temp;// vectore push back yapmak icin gecici bir rectangle tutuyoruz, icini doldurduktan sonra vectore atanacak.
			temp.set_position_x(x); // temp objesine gerekli atamalar yapildiktan sonra vectore push back yapilir.
			temp.set_position_y(y);
			temp.set_wh(small_width,small_height);
			Polygon s(temp);
			this->Polygons.push_back(s);
			x += small_width;
			if( x + small_width > width ){
				if( width - x >= small_height && flag == 0){
					Rectangle temp;
					double d_y = y;
					while(1){
						if( d_y + small_width > height){
							break;
						}
						temp.set_position_x(x);
						temp.set_position_y(d_y);
						temp.set_wh(small_height,small_width);
						Polygon s(temp);
						this->Polygons.push_back(s);
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
		count = Polygons.size(); // adet atilir.
	} 

	// kalan islemler aynidir. gecici objeler olusuturulur. algoritmaya gore gereken yerlerde atamalar yapilir. en son istenildigi uzere vectore e atilir.
	else if( container == shapes::R && small == shapes::C ){	
		double width = this->P1[1].get_x() - this->P1[0].get_x();  // daha anlasilir olmasi icin Rectangledaki verileri gecici atiyoruz.
		double height = this->P1[3].get_y() - this->P1[0].get_y(); 
		double small_radius = this->P2[0].get_x();
		int cx = small_radius, cy = small_radius;
		if( width < small_radius * 2 || height < small_radius * 2 ){
			return 0;
		}
		while(1){
			if( cy + small_radius > height){
				break;
			}
			Circle temp;
			temp.set_position_x(cx);
			temp.set_position_y(cy);
			temp.set_radius(small_radius);
			Polygon s(temp);
			this->Polygons.push_back(s);
			if( cx + (3 * small_radius) > width){
				Circle temp;
				if( cy != small_radius){
					if( (cx + small_radius * sqrt(3) + small_radius) <= width && (cy + small_radius) <= height && (cy - small_radius) > 0 ){
						cx += small_radius * sqrt(3);
						cy -= small_radius;
						temp.set_position_x(cx);
						temp.set_position_y(cy);
						temp.set_radius(small_radius);
						Polygon s(temp);
						this->Polygons.push_back(s);
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
		count = Polygons.size();				
	}
	
	else if( container == shapes::R && small == shapes::T ){
		int flag = 0;
		double width = this->P1[1].get_x() - this->P1[0].get_x();  // daha anlasilir olmasi icin Rectangledaki verileri gecici atiyoruz.
		double height = this->P1[3].get_y() - this->P1[0].get_y(); 
		double small_side = this->P2[2].get_x() - this->P2[0].get_x();
		double perp = small_side/2 * sqrt(3);
		double t[6] = {0, perp, small_side/2, 0, small_side, perp};
		if( width < small_side || height < small_side ){
			return 0;
		}
		while(1){
			Triangle temp;
			for( int i = 0; i < 6; i++){
				temp.set_position_t(t[i], i);
				if( i % 2 == 0 ){
					t[i] += small_side;
				}
			} 
			temp.set_side(small_side);
			Polygon s(temp);
			this->Polygons.push_back(s);
			if( t[0] + small_side > width){
				Triangle temp;
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
					Polygon s(temp);
					this->Polygons.push_back(s);
				}
				t[0] = 0;
				t[1] += perp;
				t[2] = small_side/2;
				t[3] += perp;
				t[4] = small_side;
				t[5] += perp;
			}
			else{
				Triangle temp;
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
				Polygon s(temp);
				this->Polygons.push_back(s);
			}							
			if( t[1] > height)
				break;	
		}
		count = Polygons.size();	
	}
	
	else if( container == shapes::C && small == shapes::R ){
		double radius = this->P1[0].get_x();		
		double small_width = this->P2[1].get_x() - this->P2[0].get_x();  // daha anlasilir olmasi icin Rectangledaki verileri gecici atiyoruz.
		double small_height = this->P2[2].get_y() - this->P2[0].get_y();
		if( radius * 2 < small_width || radius * 2 < small_height ){
			return 0;
		} 
		int counter = 0;
		int cx = radius;
		int cy = radius;
		int x = 0, y = 0;
		while(1){
			if( (sqrt( (cy - y) * (cy - y) + (cx - x) * (cx - x) ) < radius) && (sqrt( (cy - (y+small_height) ) * (cy -(y+small_height) ) + (cx - x) * (cx - x) ) < radius) &&
				(sqrt( (cy - y) * (cy - y) + (cx -(x + small_width) ) * (cx -(x+small_width) ) ) < radius) && (sqrt( (cy - (y+small_height)) * (cy -(y+small_height) ) + (cx -(x+small_width) ) * (cx -(x+small_width) ) ) < radius)
			){
				Rectangle temp;
				temp.set_position_x(x);
				temp.set_position_y(y);
				temp.set_wh(small_width,small_height);
				Polygon s(temp);
				this->Polygons.push_back(s);			
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
		count = Polygons.size();
	}

	else if ( container == shapes::C && small == shapes::C ){
		Circle temp;
		double radius = this->P1[0].get_x();	
		double small_radius = this->P2[0].get_x();	
		int cx = radius, cy = radius;
		int x = small_radius, y = small_radius;
		if( radius < small_radius || radius < small_radius ){
			return 0;
		} 		
		while(1){	
			if( sqrt( (cy - y) * (cy - y) + (cx - x) * (cx - x) ) + small_radius <= radius){
				temp.set_position_x(x);
				temp.set_position_y(y);
				temp.set_radius(small_radius);
				Polygon s(temp);
				this->Polygons.push_back(s);
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
		count = Polygons.size();
	}
	
	else if ( container == shapes::C && small == shapes::T ){
		Triangle temp;
		double radius = this->P1[0].get_x();	
		double small_side = this->P2[2].get_x() - this->P2[0].get_x();
		if( radius * 2 < small_side || radius * 2 < small_side ){
			return 0;
		} 		
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
				Polygon s(temp);
				this->Polygons.push_back(s);
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
				Polygon s(temp);
				this->Polygons.push_back(s);	
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
		count = Polygons.size();
	}

	else if ( container == shapes::T && small == shapes::R ){
		Rectangle temp;
		double side = this->P1[2].get_x() - this->P1[0].get_x();
		double small_width = this->P2[1].get_x() - this->P2[0].get_x(); // daha anlasilir olmasi icin Rectangledaki verileri gecici atiyoruz.
		double small_height = this->P2[2].get_y() - this->P2[0].get_y();		
		double d_side = side - small_height / sqrt(3);
		double perp = side/2 * sqrt(3);
		double x = small_height / sqrt(3);
		double y = perp - small_height;
		if( side < small_width || side / 2 * sqrt(3) < small_height ){
			return 0;
		} 		
		int flag = 1;
		while(1){
			if( x + small_width > d_side){
				break;
			}
			temp.set_position_x(x);
			temp.set_position_y(y);
			temp.set_wh(small_width,small_height);
			Polygon s(temp);
			this->Polygons.push_back(s);
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
		count = Polygons.size();	
	}
	
	else if ( container == shapes::T && small == shapes::C ){
		Circle temp;
		double side = this->P1[2].get_x() - this->P1[0].get_x();
		double small_radius = this->P2[0].get_x();	
		double d_side = side - sqrt(3);
		int flag = 1;
		double perp = side/2 * sqrt(3);
		double cx = small_radius * sqrt(3);
		double cy = perp - small_radius;
		if( side < small_radius * 2){
			return 0;
		} 		
		while(1){
			if( cx + small_radius * 2 >= d_side){
				break;
			}
			temp.set_position_x(cx);
			temp.set_position_y(cy);
			temp.set_radius(small_radius);
			Polygon s(temp);
			this->Polygons.push_back(s);
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
		count = Polygons.size();
	}
	
	else if ( container == shapes::T && small == shapes::T ){
		Triangle temp;
		double side = this->P1[2].get_x() - this->P1[0].get_x();
		double small_side = this->P2[2].get_x() - this->P2[0].get_x();
		int flag = -1;
		double perp = side/2 * sqrt(3);
		double small_perp = small_side/2 * sqrt(3);		
		double t[6] = {0, perp, small_side/2, perp-small_perp, small_side, perp};
		if( side < small_side){
			return 0;
		} 		
		while(1){
			for( int i = 0; i < 6; i++){
				temp.set_position_t(t[i], i);
				if( i % 2 == 0 ){
					t[i] += small_side;
				}
			} 
			temp.set_side(small_side);
			Polygon s(temp);
			this->Polygons.push_back(s);			
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
				Polygon s(temp);
				this->Polygons.push_back(s);
			}
			if( t[1] - small_side <= 0){
				break;
			}		
		}
		count = Polygons.size();		
	}
	return count;
}

ofstream &operator<<( ofstream &dosya, ComposedShape &co ){
	if( co.container == co.shapes::R ){	
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl;
		dosya <<" <polygon points=\" "; 
		for( auto i = 0; i < 4; i++){
			dosya << co.P1[i].get_x() << " ";
			dosya << co.P1[i].get_y() << " ";
		} 
		dosya << "\" fill=\"red\" /> " << endl;
	}

	else if( co.container == co.shapes::C ){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl;
		dosya <<" <polygon points=\" "; 
		for( auto i = 0; i < 100; i++){
			dosya << co.P1[i].get_x() << " ";
			dosya << co.P1[i].get_y() << " ";
		} 
		dosya << "\" fill=\"red\" /> " << endl;
	}

	else if( co.container == co.shapes::T ){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl;
		dosya <<" <polygon points=\" "; 
		for( auto i = 0; i < 3; i++){
			dosya << co.P1[i].get_x() << " ";
			dosya << co.P1[i].get_y() << " ";
		} 
		dosya << "\" fill=\"red\" /> " << endl;	
	}
	for( auto i = 0; i < co.Polygons.size(); i++){ // inner shape basilir.
		dosya << co.Polygons[i];
	}
 	dosya << "</svg>";	
}

ostream &operator<<( ostream &output, ComposedShape &co ){
	if( co.container == co.shapes::R ){
		double width = co.P1[1].get_x() - co.P1[0].get_x(); 
		double height = co.P1[3].get_y() - co.P1[0].get_y();	
		cout << "Container width: " << width << endl;
		cout << "Container height: " << height << endl;
	}
	else if( co.container == co.shapes::C ){
		double radius = co.P1[0].get_x();
		cout << "Container circle: " << radius << endl;
	}
	else if( co.container == co.shapes::T ){
		double side = co.P1[2].get_x() - co.P1[0].get_x();
		cout << "Container side: " << side << endl;		
	}
	cout << co.P2;
	return output;	
}






