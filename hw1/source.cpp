#include <iostream>
#include <fstream>
#include <math.h>
# define PI 3.141592653589793238462643383279502884L // pi
#include "source.h"
using namespace std;

int circ_in_circ(const double radius, const double small_radius){
	ofstream dosya;
	dosya.open("result.svg");	
	int counter = 0;
	int cx = radius;
	int cy = radius;
	int x = small_radius;
	int y = small_radius;
	dosya << "<svg version=\"1.1\" xmlns=\"http:\/\/www.w3.org\/2000\/svg\"> " << endl
	<< " <circle cx=\""<< cx << "\" cy=\"" << cy << "\" r=\""<< radius << "\" fill=\"red\"\/> " << endl;
	while(1){
		if( sqrt( (cy - y) * (cy - y) + (cx - x) * (cx - x) ) + small_radius <= radius){
			dosya << " <circle cx=\""<< x << "\" cy=\"" << y << "\" r=\""<< small_radius << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> " << endl;
			counter++;
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
	dosya << "<\/svg>";
	dosya.close();		
	return counter;
}
double circ_in_circ_area(const double radius, const double small_radius, const int count){
	double empty_area = radius * radius * PI - small_radius * small_radius * PI * count;
	return empty_area;
}
int rect_in_circ(const double radius, const double small_width, const double small_height){
	ofstream dosya;
	dosya.open("result.svg");	
	int counter = 0;
	int cx = radius;
	int cy = radius;
	int x = 0;
	int y = 0;
	dosya << "<svg version=\"1.1\" xmlns=\"http:\/\/www.w3.org\/2000\/svg\"> " << endl
	<< " <circle cx=\""<< cx << "\" cy=\"" << cy << "\" r=\""<< radius << "\" fill=\"red\"\/> " << endl;
	while(1){
		if( (sqrt( (cy - y) * (cy - y) + (cx - x) * (cx - x) ) + small_radius * 2 < radius) && (sqrt( (cy - y) * (cy - y) + (cx - x) * (cx - x) ) + small_height * 2 < radius)){
			dosya << " <rect x=\""<< x << "\" y=\"" << y << "\" width=\""<< small_width << "\" height=\"" << small_height << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> "<< endl;
			counter++;
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
	dosya << "<\/svg>";
	dosya.close();		
	return counter;
}
double rect_in_circ_area(const double radius, const double small_width, const double small_height, const int count){
}

int triangle_in_circ(const double radius, const double small_side){}
double triangle_in_circ_area(const double radius, const double small_side, const int count){}

int circ_in_rect(const double width, const double height, const double small_radius){
	ofstream dosya;
	dosya.open("result.svg");
	int cx = small_radius, cy = small_radius, counter = 0;
	dosya << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<< width << "\" height=\"" << height << " \" xmlns=\"http:\/\/www.w3.org\/2000\/svg\"> " << endl
	<< " <rect width=\"100%\" height=\"100%\" fill=\"red\"\/>" << endl;
	while(1){
		if( cy + small_radius > height){
			break;
		}
		dosya << " <circle cx=\""<< cx << "\" cy=\"" << cy << "\" r=\""<< small_radius << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> " << endl;
		counter++;
		dosya << counter;
		if( cx + (3 * small_radius) > width){
			if( cy != small_radius){
				if( (cx + small_radius * sqrt(3) + small_radius) <= width && (cy + small_radius) <= height && (cy - small_radius) > 0 ){
					cx += small_radius * sqrt(3);
					cy -= small_radius;
					dosya << " <circle cx=\""<< cx << "\" cy=\"" << cy << "\" r=\""<< small_radius << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> " << endl;
					counter++;
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
	dosya << "<\/svg>";
	dosya.close();		
	return counter;
}

double circ_in_rect_area(const double width, const double height, const double small_radius, const int count){
	double empty_area = width * height - small_radius * small_radius * PI * count;
	return empty_area;
}
int triangle_in_rect(const double width, const double height, const double small_side){
	ofstream dosya;
	dosya.open("result.svg");
	int counter = 0;
	double perp = small_side/2 * sqrt(3);
	dosya << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<< width << "\" height=\"" << height << " \" xmlns=\"http:\/\/www.w3.org\/2000\/svg\"> " << endl
	<< " <rect width=\"100%\" height=\"100%\" fill=\"red\"\/>" << endl;
	double t[6] = {0, perp, small_side/2, 0, small_side, perp};
	while(1){
		dosya <<" <polygon points=\" "; 
		for( int i = 0; i < 6; i++){
			dosya << t[i]<< " ";
			if( i % 2 == 0 ){
				t[i] += small_side;
			}
		} 
		dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"\/> " << endl;
		counter++;
		if( t[0] + small_side > width){
			if( t[0] + small_side / 2 <= width){
				dosya <<" <polygon transform=\"rotate( " << "180 " <<  t[0] <<" "<<  (t[1] - perp/2) << " )\" points=\""; 
				for ( int i = 0; i < 6; i++){
					if( i % 2 == 0 ){
						t[i] -= small_side / 2;
						dosya << t[i]<< " ";
						t[i] += small_side / 2;
					}
					else
						dosya << t[i]<< " ";
				}
 				dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> " << endl;
 				counter++;	
			}
			t[0] = 0;
			t[1] += perp;
			t[2] = small_side/2;
			t[3] += perp;
			t[4] = small_side;
			t[5] += perp;
		}
		else{
			dosya <<" <polygon transform=\"rotate( " << "180 " <<  t[0] <<" "<<  (t[1] - perp/2) << " )\" points=\""; 
			for ( int i = 0; i < 6; i++){
				if( i % 2 == 0 ){
					t[i] -= small_side / 2;
					dosya << t[i]<< " ";
					t[i] += small_side / 2;
				}
				else
					dosya << t[i]<< " ";
			}
 			dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> " << endl;
 			counter++;
		}							
		if( t[1] > height)
			break;	
	}
	dosya << "<\/svg>";
 	dosya.close();
	return counter;		
}

double triangle_in_rect_area(const double width, const double height, const double small_side, const int count){
	double empty_area = width * height - small_side * small_side * sqrt(3) / 4 * count;
	return empty_area;
}
int rect_in_rect(const double width, const double height, const double small_width, const double small_height){
	ofstream dosya;
	dosya.open("result.svg");
	int x = 0, y = 0, counter = 0, flag = 0;
	dosya << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<< width << "\" height=\"" << height << " \" xmlns=\"http:\/\/www.w3.org\/2000\/svg\"> " << endl
	<< " <rect width=\"100%\" height=\"100%\" fill=\"red\"\/>" << endl;
	while(1){
		dosya << " <rect x=\""<< x << "\" y=\"" << y << "\" width=\""<< small_width << "\" height=\"" << small_height << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> " << endl;
		counter++;
		x += small_width;
		if( x + small_width > width ){
			if( width - x >= small_height && flag == 0){
				double d_y = y;
				while(1){
					if( d_y + small_width > height){
						break;
					}
					dosya << " <rect x=\""<< x << "\" y=\"" << d_y << "\" width=\""<< small_height << "\" height=\"" << small_width << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> " << endl;
					counter++;
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
	dosya << "<\/svg>";
 	dosya.close();
	return counter;	
}
double rect_in_rect_area(const double width, const double height, const double small_width, const double small_height, const int count){
	double empty_area = width * height - small_width * small_height * count;
	return empty_area;
}

int circ_in_triangle(const double side, const double small_radius){
	double d_side = side - sqrt(3);
	ofstream dosya;
	dosya.open("result.svg");
	int counter = 0, flag = 1;
	double perp = side/2 * sqrt(3);
	double cx = small_radius * sqrt(3);
	double cy = perp - small_radius;
	dosya << "<svg version=\"1.1\" xmlns=\"http:\/\/www.w3.org\/2000\/svg\"> " << endl
	<< 	" <polygon points=\"" << "0 " << perp << " " << side / 2 << " 0 " << side << " " << perp << "\"" << " fill=\"red\" />" << endl;
	while(1){
		if( cx + small_radius * 2 >= d_side){
			break;
		}
		dosya << " <circle cx=\""<< cx << "\" cy=\"" << cy << "\" r=\""<< small_radius << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" \/> " << endl;
		counter++;
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
	dosya << "<\/svg>";
 	dosya.close();
	return counter;
}
double circ_in_triangle_area(const double side, const double small_radius, const int count){
	double empty_area = side * side * sqrt(3) / 4 - small_radius * small_radius * PI * count;
	return empty_area;
}
int triangle_in_triangle(double side, const double small_side){
	ofstream dosya;
	dosya.open("result.svg");
	int counter = 0, flag = -1;
	double perp = side/2 * sqrt(3);
	double small_perp = small_side/2 * sqrt(3);
	double t[6] = {0, perp, small_side/2, perp-small_perp, small_side, perp};
	dosya << "<svg version=\"1.1\" xmlns=\"http:\/\/www.w3.org\/2000\/svg\"> " << endl
	<< 	" <polygon points=\"" << "0 " << perp << " " << side / 2 << " 0 " << side << " " << perp << "\"" << " fill=\"red\" />" << endl;
	while(1){
		dosya <<" <polygon points=\" "; 
		for( int i = 0; i < 6; i++){
			dosya << t[i]<< " ";
			if( i % 2 == 0 ){
				t[i] += small_side;
			}
		} 
		dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0\"\/> " << endl;
		counter++;
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
			dosya <<" <polygon transform=\"rotate( " << "180 " <<  t[0] <<" "<<  (t[1] - small_perp/2) << " )\" points=\""; 
			for ( int i = 0; i < 6; i++){
				if( i % 2 == 0 ){
					t[i] -= small_side / 2;
					dosya << t[i]<< " ";
					t[i] += small_side / 2;
				}
				else
					dosya << t[i]<< " ";
			}
 			dosya << "\" fill=\"green\"\/> " << endl;
 			counter++;
		}
		if( t[1] - small_side <= 0){
			break;
		}		
	}
	dosya << "<\/svg>";
 	dosya.close();
	return counter;
}
double triangle_in_triangle_area(const double side, const double small_side, int count){
	double empty_area = side * side * sqrt(3) / 4 - small_side * small_side * sqrt(3) / 4 * count;
	return empty_area;
}
int rect_in_triangle(const double side, const double small_width, const double small_height){
	double d_side = side - small_height / sqrt(3);
	ofstream dosya;
	dosya.open("result.svg");
	int counter = 0, flag = 1;
	double perp = side/2 * sqrt(3);
	double x = small_height / sqrt(3);
	double y = perp - small_height;
	dosya << "<svg version=\"1.1\" xmlns=\"http:\/\/www.w3.org\/2000\/svg\"> " << endl
	<< 	" <polygon points=\"" << "0 " << perp << " " << side / 2 << " 0 " << side << " " << perp << "\"" << " fill=\"red\" />" << endl;
	if( small_width < small_height){
	}
	
	while(1){
		if( x + small_width > d_side){
			break;
		}
		dosya << " <rect x=\""<< x << "\" y=\"" << y << "\" width=\""<< small_width << "\" height=\"" << small_height << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.4\" \/> " << endl;
		counter++;
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
	dosya << "<\/svg>";
 	dosya.close();
	return counter;
}
double rect_in_triangle_area(const double side, const double small_width, const double small_height, const int count){
	double empty_area = side * side * sqrt(3) / 4 - small_width * small_height * count;
	return empty_area;
}


