#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "ComposedShape.h"

using namespace std;
#define PI 3.141592653589793238462643383279502884L // pi

namespace cpp{
	ComposedShape::~ComposedShape(){
		for( int i = 0; i < shape.size(); i++ ){
			delete [] shape[i];	
		}
	}
	ComposedShape::ComposedShape(const ComposedShape & C){
		container = C.container;
		small = C.small;
		R1 = C.R1;
		R2 = C.R2;
		C1 = C.C1;
		C2 = C.C2;
		T1 = C.T1;
		T2 = C.T2;
	}
	ComposedShape & ComposedShape::operator=(const ComposedShape & C){
		container = C.container;
		small = C.small;
		R1 = C.R1;
		R2 = C.R2;
		C1 = C.C1;
		C2 = C.C2;
		T1 = C.T1;
		T2 = C.T2;
		return *this;
	}

	ComposedShape::ComposedShape(Rectangle R1, Rectangle R2){ // overload constructlar ile girilen obje taninir ve ComposedShapein memberlerine assing edilir.
		container = shapes::R;
		small = shapes::R;
		this->R1 = R1;
		this->R2 = R2;
	}
	ComposedShape::ComposedShape(Rectangle R1, Circle C1){
		container = shapes::R;
		small = shapes::C;
		this->R1 = R1;
		this->C1 = C1;
	}
	ComposedShape::ComposedShape(Rectangle R1, Triangle T1){
		container = shapes::R;
		small = shapes::T;	
		this->R1 = R1;
		this->T1 = T1;
	}
	ComposedShape::ComposedShape(Circle C1, Rectangle R1){
		container = shapes::C;
		small = shapes::R;
		this->C1 = C1;
		this->R1 = R1;
	}
	ComposedShape::ComposedShape(Circle C1, Circle C2){
		container = shapes::C;
		small = shapes::C;
		this->C1 = C1;
		this->C2 = C2;
	}
	ComposedShape::ComposedShape(Circle C1, Triangle T1){
		container = shapes::C;
		small = shapes::T;
		this->C1 = C1;
		this->T1 = T1;
	}
	ComposedShape::ComposedShape(Triangle T1, Rectangle R1){
		container = shapes::T;
		small = shapes::R;
		this->T1 = T1;
		this->R1 = R1;
	}
	ComposedShape::ComposedShape(Triangle T1, Circle C1){
		container = shapes::T;
		small = shapes::C;
		this->T1 = T1;
		this->C1 = C1;
	}
	ComposedShape::ComposedShape(Triangle T1, Triangle T2){
		container = shapes::T;
		small = shapes::T;
		this->T1 = T1;
		this->T2 = T2;
	}

	int ComposedShape::optimalFit(){ // cogu isi yapan fonksiyondur. objeyi tanir ve islemleri yapar.
		int count; // inner shape adetini tutan counter.
		if( container == shapes::R && small == shapes::R ){
			double width = this->R1.get_width(); // daha anlasilir olmasi icin Rectangledaki verileri gecici atiyoruz.
			double height = this->R1.get_height();
			double small_width = this->R2.get_width();
			double small_height = this->R2.get_height();
			int x = 0, y = 0, flag = 0;
			while(1){
				Rectangle temp;// vectore push back yapmak icin gecici bir rectangle tutuyoruz, icini doldurduktan sonra vectore atanacak.
				temp.set_position_x(x); // temp objesine gerekli atamalar yapildiktan sonra vectore push back yapilir.
				temp.set_position_y(y);
				temp.set_wh(small_width,small_height);
				Shape *s = new Rectangle(temp);
				this->shape.push_back(s);
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
							Shape *s = new Rectangle(temp);
							this->shape.push_back(s);
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
			count = shape.size(); // adet atilir.
		} 

		// kalan islemler aynidir. gecici objeler olusuturulur. algoritmaya gore gereken yerlerde atamalar yapilir. en son istenildigi uzere vectore e atilir.
		else if( container == shapes::R && small == shapes::C ){
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
				Shape *s = new Circle(temp);
				this->shape.push_back(s);
				if( cx + (3 * small_radius) > width){
					if( cy != small_radius){
						if( (cx + small_radius * sqrt(3) + small_radius) <= width && (cy + small_radius) <= height && (cy - small_radius) > 0 ){
							cx += small_radius * sqrt(3);
							cy -= small_radius;
							temp.set_position_x(cx);
							temp.set_position_y(cy);
							temp.set_radius(small_radius);
							Shape *s = new Circle(temp);
							this->shape.push_back(s);
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
			count = shape.size();				
		}
		
		else if( container == shapes::R && small == shapes::T ){
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
				Shape *s = new Triangle(temp);
				this->shape.push_back(s);
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
						Shape *s = new Triangle(temp);
						this->shape.push_back(s);
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
					Shape *s = new Triangle(temp);
					this->shape.push_back(s);
				}							
				if( t[1] > height)
					break;	
			}
			count = shape.size();	
		}
		
		else if( container == shapes::C && small == shapes::R ){
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
					temp.set_wh(small_width,small_height);
					Shape *s = new Rectangle(temp);
					this->shape.push_back(s);			}
				x += small_width;			
				if( x + small_width >= radius * 2){
					x = 0;
					y +=  small_height ;		
				}
				if( y + small_height >= radius * 2 ){
					break;		
				}
			}		
			count = shape.size();
		}

		else if ( container == shapes::C && small == shapes::C ){
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
					Shape *s = new Circle(temp);
					this->shape.push_back(s);
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
			count = shape.size();
		}
		
		else if ( container == shapes::C && small == shapes::T ){
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
					Shape *s = new Triangle(temp);
					this->shape.push_back(s);
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
					Shape *s = new Triangle(temp);
					this->shape.push_back(s);	
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
			count = shape.size();
		}

		else if ( container == shapes::T && small == shapes::R ){
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
				temp.set_wh(small_width,small_height);
				Shape *s = new Rectangle(temp);
				this->shape.push_back(s);
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
			count = shape.size();	
		}
		
		else if ( container == shapes::T && small == shapes::C ){
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
				Shape *s = new Circle(temp);
				this->shape.push_back(s);
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
			count = shape.size();
		}
		
		else if ( container == shapes::T && small == shapes::T ){
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
				Shape *s = new Triangle(temp);
				this->shape.push_back(s);			
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
					Shape *s = new Triangle(temp);
					this->shape.push_back(s);
				}
				if( t[1] - small_side <= 0){
					break;
				}		
			}
			count = shape.size();		
		}
		return count;
	}

	double ComposedShape::get_area(){
		if(container == shapes::R){
			return (R1.get_area() - shape[0]->get_area() * shape.size()); 
		}
		else if( container == shapes::C){
			return (C1.get_area() - shape[0]->get_area() * shape.size());
		}
		else if( container == shapes::T){
			return (T1.get_area() - shape[0]->get_area() * shape.size());
		}
	}
	double ComposedShape::get_perimeter(){
		if(container == shapes::R){
			return (R1.get_perimeter() - shape[0]->get_perimeter() * shape.size()); 
		}
		else if( container == shapes::C){
			return (C1.get_perimeter() - shape[0]->get_perimeter() * shape.size());
		}
		else if( container == shapes::T){
			return (T1.get_perimeter() - shape[0]->get_perimeter() * shape.size());
		}
	}

	ComposedShape & ComposedShape::operator++(){
		for(int i = 0; i < shape.size(); i++){
			++shape[i];
		}
	}

	ComposedShape & ComposedShape::operator--(){
		for(int i = 0; i < shape.size(); i++){
			--shape[i];
		}
	}

	ComposedShape & ComposedShape::operator++(int){
		for(int i = 0; i < shape.size(); i++){
			shape[i]++;
		}
	}

	ComposedShape & ComposedShape::operator--(int){
		for(int i = 0; i < shape.size(); i++){
			shape[i]--;
		}
	}

	ofstream &operator<<( ofstream &dosya, ComposedShape &co ){
		/*if( co.container == co.shapes::R ){	
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
		for( auto i = 0; i < co.shape.size(); i++){ // inner shape basilir.
			dosya << co.shape[i];
		}
	 	dosya << "</svg>";	*/
	}

	ostream &operator<<( ostream &dosya, ComposedShape &co ){
		if( co.container == co.shapes::R ){
			double width = co.R1.get_width(); 
			double height = co.R1.get_height();	
			cout << "Container width: " << width << endl;
			cout << "Container height: " << height << endl;
		}
		else if( co.container == co.shapes::C ){
			double radius = co.C1.get_radius();
			cout << "Container circle: " << radius << endl;
		}
		else if( co.container == co.shapes::T ){
			double side = co.T1.get_side();
			cout << "Container side: " << side << endl;		
		}
		//cout << co.P2;
		//return output;	
	}

	ofstream & ComposedShape::draw_shape(ofstream &dosya){
		if( container == shapes::R ){
			dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
			<< "<rect  width=\""<< R1.get_width() << "\" height=\"" << R1.get_height() << "\" fill=\"red\" />" << endl;
		}
		else if( container == shapes::C){
			dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
			<< " <circle cx=\""<< C1.get_position_x() << "\" cy=\"" << C1.get_position_y() << "\" r=\""<< C1.get_radius() << "\" fill=\"red\"/> " << endl;
		}
		else if( container == shapes::T){
			dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
			<< 	" <polygon points=\"" << "0 " << T1.get_side()/2 * sqrt(3) << " " << T1.get_side() / 2 << " 0 " << T1.get_side() << " " << T1.get_side()/2 * sqrt(3) << "\"" << " fill=\"red\" />" << endl;
		}
		for( int i = 0; i < shape.size(); i++){ // inner shape basilir..
			shape[i]->draw_shape(dosya);
		}		
		dosya << "</svg>";
		return dosya;
	}
}





