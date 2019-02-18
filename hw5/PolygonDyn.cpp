#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "PolygonDyn.h"

#define PI 3.141592653589793238462643383279502884L // pi

namespace cpp{
	PolygonDyn::~PolygonDyn(){
		delete [] polygondyn;
	}
	PolygonDyn::PolygonDyn(const PolygonDyn & Pd){
		if( count < Pd.count ){
			polygondyn = new Point2D[Pd.count];
			for( int i = 0; i < Pd.count; i++){
					polygondyn[i].set_points(Pd.polygondyn[i].get_x(), Pd.polygondyn[i].get_y());	
			}
		}
		count = Pd.count;
	}
	PolygonDyn & PolygonDyn::operator=(const PolygonDyn & Pd){
		if( count < Pd.count ){
			polygondyn = new Point2D[Pd.count];
			for( int i = 0; i < Pd.count; i++){
					polygondyn[i].set_points(Pd.polygondyn[i].get_x(), Pd.polygondyn[i].get_y());	
			}
		}
		count = Pd.count;
		return *this;
	}	

	PolygonDyn::PolygonDyn(Rectangle &R){
		count = 4;
		int width = R.get_width();
		int height = R.get_height();
		if( width > 0 && height > 0){
			Point2D p1(0 + R.get_position_x(), 0 + R.get_position_y()), p2(width + R.get_position_x(), 0 + R.get_position_y()), 
			p3(width + R.get_position_x(), height + R.get_position_y()), p4(0 + R.get_position_x(), height + R.get_position_y());
			polygondyn = new Point2D[4];
			polygondyn[0] = p1;
			polygondyn[1] = p2;
			polygondyn[2] = p3;
			polygondyn[3] = p4;	
		}
	}
	PolygonDyn::PolygonDyn(Triangle &T){
		count = 3;
		int side = T.get_side();
		if( side > 0 ){
			double perp = side / 2.0 * sqrt(3);
			Point2D p1(T.get_position_t(0), T.get_position_t(1)), 
			p2(T.get_position_t(2), T.get_position_t(3)), 
			p3(T.get_position_t(4), T.get_position_t(5));
			polygondyn = new Point2D[3];
			polygondyn[0] = p1;
			polygondyn[1] = p2;
			polygondyn[2] = p3;
		}
	}
	PolygonDyn::PolygonDyn(Circle &C){
		count = 100;
		double radius = C.get_radius();
		double position_x = C.get_position_x();
		double position_y = C.get_position_y();
		if( radius > 0 ){
			polygondyn = new Point2D[100];
			for(int i = 0; i < 100; i++){			
				double sinp = radius + position_x - radius + radius * sin((2*PI/100) * i * 1.0);
				double cosp = radius + position_y - radius + radius * cos((2*PI/100) * i * 1.0);		
				Point2D p(sinp, cosp);
				polygondyn[i] = p;
			}	
		}
	}

	PolygonDyn & PolygonDyn::operator++(){
		for ( int i = 0; i < count; i++){
			int x = polygondyn[i].get_x();
			int y = polygondyn[i].get_y();
			polygondyn[i].set_points( x + 1, y + 1);	
		}
		return *this;
	}
	PolygonDyn & PolygonDyn::operator--(){
		for ( int i = 0; i < count; i++){
			int x = polygondyn[i].get_x();
			int y = polygondyn[i].get_y();
			polygondyn[i].set_points( x - 1, y - 1);	
		}
		return *this;
	}
	PolygonDyn & PolygonDyn::operator++( int ){
		PolygonDyn *temp = new PolygonDyn(*this);
		for ( int i = 0; i < count; i++){
			int x = polygondyn[i].get_x();
			int y = polygondyn[i].get_y();
			polygondyn[i].set_points( x + 1, y + 1);	
		}
		return *temp;
	}
	PolygonDyn & PolygonDyn::operator--( int ){
		PolygonDyn *temp = new PolygonDyn(*this);
		for ( int i = 0; i < count; i++){
			int x = polygondyn[i].get_x();
			int y = polygondyn[i].get_y();
			polygondyn[i].set_points( x - 1, y - 1);	
		}
		return *temp;
	}

	double PolygonDyn::get_perimeter(){
		if( this->count == 4 ){
			double width = (polygondyn[1].get_x() - polygondyn[0].get_x());
			double height = (polygondyn[3].get_y() - polygondyn[0].get_y());		
			return  2 * (width + height);
		}
		else if(  this->count == 100 ){
			double radius = polygondyn[0].get_x();
			return (2.0 * PI * radius);
		}
		else if( this->count == 3 ){
			double side = polygondyn[2].get_x();
			cout << "ucgen alan: " << ( (side * side * sqrt(3)) / 4) << endl;
			return side * 3;	
		}
	}

	double PolygonDyn::get_area(){
		if( this->count == 4 ){
			double width = (polygondyn[1].get_x() - polygondyn[0].get_x());
			double height = (polygondyn[3].get_y() - polygondyn[0].get_y());		
			return width * height;
		}
		else if(  this->count == 100 ){
			double radius = polygondyn[0].get_x();
			return (PI * radius * radius);
		}
		else if( this->count == 3 ){

			double side = polygondyn[2].get_x();
			cout << "ucgen alan: " << ( (side * side * sqrt(3)) / 4) << endl;
			return ( (side * side * sqrt(3)) / 4.0);	
		}
	}

	ofstream & PolygonDyn::draw_shape(ofstream &dosya){
		dosya << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl;
		if( this->count == 4 ){
			dosya <<" <polygon points=\" "; 
			for( int i = 0; i < 4; i++){
				dosya << polygondyn[i].get_x() << " ";
				dosya << polygondyn[i].get_y() << " ";
			} 
			dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;
		}
		else if( this->count == 100 ){
			dosya <<" <polygon points=\" "; 
			for( int i = 0; i < 100; i++){
				dosya << polygondyn[i].get_x() << " ";
				dosya << polygondyn[i].get_y() << " ";
			} 
			dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;        
		}
		else if( this->count == 3 ){
			dosya <<" <polygon points=\" "; 
			for( int i = 0; i < 3; i++){
				dosya << polygondyn[i].get_x() << " ";
				dosya << polygondyn[i].get_y() << " ";
			} 
			dosya << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;
		}
		dosya << "</svg>";
		return dosya;
	}

	PolygonDyn::PolygonDyn(vector<Point2D> &point2d){
		count = point2d.size();
		polygondyn = new Point2D[count];
		for( int i = 0; i < count; i++){
			polygondyn[i] = point2d[i];
		}
	}
	PolygonDyn::PolygonDyn(Point2D &point){
		count = 1;
		polygondyn = new Point2D;
		*polygondyn = point;
	}
}
