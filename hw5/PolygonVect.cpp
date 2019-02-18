#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "PolygonVect.h"

#define PI 3.141592653589793238462643383279502884L // pi

namespace cpp{
	PolygonVect::PolygonVect(PolygonVect & Pv){
		polygonvect.clear();
		for( int i = 0; i < Pv.count; i++){
			Point2D temp(Pv.polygonvect[i].get_x(), Pv.polygonvect[i].get_y());
			polygonvect.push_back(temp);
		}
		count = Pv.count;
	}
	PolygonVect & PolygonVect::operator=(PolygonVect & Pv){
		polygonvect.clear();
		for( int i = 0; i < Pv.count; i++){
			Point2D temp(Pv.polygonvect[i].get_x(), Pv.polygonvect[i].get_y());
			polygonvect.push_back(temp);
		}
		count = Pv.count;
		return *this;
	}	

	PolygonVect::PolygonVect(Rectangle &R){
		count = 4;
		int width = R.get_width();
		int height = R.get_height();
		if( width > 0 && height > 0){
			Point2D p1(0 + R.get_position_x(), 0 + R.get_position_y()), p2(width + R.get_position_x(), 0 + R.get_position_y()), 
			p3(width + R.get_position_x(), height + R.get_position_y()), p4(0 + R.get_position_x(), height + R.get_position_y());
			polygonvect.push_back(p1);
			polygonvect.push_back(p2);
			polygonvect.push_back(p3);
			polygonvect.push_back(p4);
		}
	}
	PolygonVect::PolygonVect(Triangle &T){
		count = 3;
		int side = T.get_side();
		if( side > 0 ){
			double perp = side / 2.0 * sqrt(3);
			Point2D p1(T.get_position_t(0), T.get_position_t(1)), 
			p2(T.get_position_t(2), T.get_position_t(3)), 
			p3(T.get_position_t(4), T.get_position_t(5));
			polygonvect.push_back(p1);
			polygonvect.push_back(p2);
			polygonvect.push_back(p3);
		}
	}
	PolygonVect::PolygonVect(Circle &C){
		count = 100;
		double radius = C.get_radius();
		double position_x = C.get_position_x();
		double position_y = C.get_position_y();
		if( radius > 0 ){
			for(int i = 0; i < 100; i++){
				
				double sinp = radius + position_x - radius + radius * sin((2*PI/100) * i * 1.0);
				double cosp = radius + position_y - radius + radius * cos((2*PI/100) * i * 1.0);		
				//p.set_PolygonVect(sinp, cosp);
				Point2D p(sinp, cosp);
				polygonvect.push_back(p);
			}	
		}
	}

	PolygonVect & PolygonVect::operator++(){
		for ( int i = 0; i < count; i++){
			int x = polygonvect[i].get_x();
			int y = polygonvect[i].get_y();
			polygonvect[i].set_points( x + 1, y + 1);	
		}
		return *this;
	}
	PolygonVect & PolygonVect::operator--(){
		for ( int i = 0; i < count; i++){
			int x = polygonvect[i].get_x();
			int y = polygonvect[i].get_y();
			polygonvect[i].set_points( x - 1, y - 1);	
		}
		return *this;
	}
	PolygonVect & PolygonVect::operator++( int ){
		PolygonVect *temp = new PolygonVect(*this);
		for ( int i = 0; i < count; i++){
			int x = polygonvect[i].get_x();
			int y = polygonvect[i].get_y();
			polygonvect[i].set_points( x + 1, y + 1);	
		}
		return *temp;
	}
	PolygonVect & PolygonVect::operator--( int ){
		PolygonVect *temp = new PolygonVect(*this);
		for ( int i = 0; i < count; i++){
			int x = polygonvect[i].get_x();
			int y = polygonvect[i].get_y();
			polygonvect[i].set_points( x - 1, y - 1);	
		}
		return *temp;
	}

	double PolygonVect::get_perimeter(){
		if( this->count == 4 ){
			double width = (polygonvect[1].get_x() - polygonvect[0].get_x());
			double height = (polygonvect[3].get_y() - polygonvect[0].get_y());		
			return  2 * (width + height);
		}
		else if( this->count == 100 ){
			double radius = polygonvect[0].get_x();
			return (2.0 * PI * radius);
		}
		else if( this->count == 3 ){
			double side = polygonvect[2].get_x();
			cout << "ucgen alan: " << ( (side * side * sqrt(3)) / 4) << endl;
			return side * 3;	
		}
	}

	double PolygonVect::get_area(){
		if( this->count == 4 ){
			double width = (polygonvect[1].get_x() - polygonvect[0].get_x());
			double height = (polygonvect[3].get_y() - polygonvect[0].get_y());		
			return  width * height;
		}
		else if(  this->count == 100 ){
			double radius = polygonvect[0].get_x();
			return (PI * radius * radius);
		}
		else if( this->count == 3 ){

			double side = polygonvect[2].get_x();
			cout << "ucgen alan: " << ( (side * side * sqrt(3)) / 4) << endl;
			return ( (side * side * sqrt(3)) / 4);	
		}
	}

	ofstream & PolygonVect::draw_shape(ofstream &dosya){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl;
		if( this->count == 4 ){
			dosya <<" <polygon points=\" "; 
			for( int i = 0; i < 4; i++){
				dosya << polygonvect[i].get_x() << " ";
				dosya << polygonvect[i].get_y() << " ";
			} 
			dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;
		}
		else if( this->count == 100 ){
			dosya <<" <polygon points=\" "; 
			for( int i = 0; i < 100; i++){
				dosya << polygonvect[i].get_x() << " ";
				dosya << polygonvect[i].get_y() << " ";
			} 
			dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;        
		}
		else if( this->count == 3 ){
			dosya <<" <polygon points=\" "; 
			for( int i = 0; i < 3; i++){
				dosya << polygonvect[i].get_x() << " ";
				dosya << polygonvect[i].get_y() << " ";
			} 
			dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;
		}
		dosya << "</svg>";
		return dosya;
	}

	PolygonVect::PolygonVect(vector<Point2D> &point2d){
		count = point2d.size();
		polygonvect = point2d;
		
	}
	PolygonVect::PolygonVect(Point2D &point){
		polygonvect.push_back(point);
		count = 1;
	}	
}
