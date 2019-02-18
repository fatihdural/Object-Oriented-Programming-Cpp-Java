#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"
#include "PolygonVect.h"
#include "PolygonDyn.h"

#define PI 3.141592653589793238462643383279502884L // pi

namespace cpp{
	Polygon::Polygon(){
		count = 0;
		points = new Point2D;
	}

	Polygon::~Polygon(){
		delete [] points;
	}
	Polygon::Polygon(const Polygon & P){
		points = new Point2D[P.count];
		for( int i = 0; i < P.count; i++){
				points[i].set_points(P.points[i].get_x(), P.points[i].get_y());	
		}	
		count = P.count;
	}
	Polygon & Polygon::operator=(const Polygon & P){
		points = new Point2D[P.count];
		for( int i = 0; i < P.count; i++){
				points[i].set_points(P.points[i].get_x(), P.points[i].get_y());	
		}
		count = P.count;
		return *this;
	}

	Polygon::Polygon(Rectangle &R){
		count = 4;
		int width = R.get_width();
		int height = R.get_height();
		if( width > 0 && height > 0){
			Point2D p1(0 + R.get_position_x(), 0 + R.get_position_y()), p2(width + R.get_position_x(), 0 + R.get_position_y()), 
			p3(width + R.get_position_x(), height + R.get_position_y()), p4(0 + R.get_position_x(), height + R.get_position_y());
			points = new Point2D[4];
			points[0] = p1;
			points[1] = p2;
			points[2] = p3;
			points[3] = p4;	
		}
	}
	Polygon::Polygon(Triangle &T){
		count = 3;
		int side = T.get_side();
		if( side > 0 ){
			double perp = side / 2.0 * sqrt(3);
			Point2D p1(T.get_position_t(0), T.get_position_t(1)), 
			p2(T.get_position_t(2), T.get_position_t(3)), 
			p3(T.get_position_t(4), T.get_position_t(5));
			points = new Point2D[3];
			points[0] = p1;
			points[1] = p2;
			points[2] = p3;
		}
	}
	Polygon::Polygon(Circle &C){
		count = 100;
		double radius = C.get_radius();
		double position_x = C.get_position_x();
		double position_y = C.get_position_y();
		if( radius > 0 ){
			points = new Point2D[100];
			for(int i = 0; i < 100; i++){
				Point2D p;
				double sinp = radius + position_x - radius + radius * sin((2*PI/100) * i * 1.0);
				double cosp = radius + position_y - radius + radius * cos((2*PI/100) * i * 1.0);		
				p.set_points(sinp, cosp);
				points[i] = p;
			}	
		}
	}
	Polygon::Polygon(vector<Point2D> &point2d){
		count = point2d.size();
		points = new Point2D[count];
		for( int i = 0; i < count; i++){
			points[i] = point2d[i];
		}
	}
	Polygon::Polygon(Point2D &point){
		count = 1;
		points = new Point2D;
		*points = point;
	}

	void Polygon::set_points_mem(int count){
		points = new Point2D[count];
	}
	void Polygon::set_po_points(double x, double y){
		this->points->set_points(x,y);
	}

	Polygon::Point2D * Polygon::get_points(){
		return this->points;
	}
	Polygon::Point2D& Polygon::operator[] (int x){
		if( x >= 0){
			return points[x];	
		}
	}

	ofstream &operator<<( ofstream &output, Polygon &po ){
		if( po.count == 4 ){
			output <<" <polygon points=\" "; 
			for( auto i = 0; i < 4; i++){
				output << po.points[i].get_x() << " ";
				output << po.points[i].get_y() << " ";
			} 
			output << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;
		}
		else if(  po.count == 100 ){
			output <<" <polygon points=\" "; 
			for( auto i = 0; i < 100; i++){
				output << po.points[i].get_x() << " ";
				output << po.points[i].get_y() << " ";
			} 
			output << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;        
		}
		else if( po.count == 3 ){
			output <<" <polygon points=\" "; 
			for( auto i = 0; i < 3; i++){
				output << po.points[i].get_x() << " ";
				output << po.points[i].get_y() << " ";
			} 
			output << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> " << endl;
		}
		return output;
	}

	ostream &operator<<( ostream &output, Polygon &po ){
		if(  po.count == 4 ){
			double width = po[1].get_x() - po[0].get_x(); 
			double height = po[3].get_y() - po[0].get_y();	
			cout << "İnner width: " << width << endl;
			cout << "İnner height: " << height << endl;
		}
		else if( po.count == 100 ){
			double radius = po[0].get_x();
			cout << "İnner circle: " << radius << endl;
		}
		else if( po.count == 3 ){
			double side = po[2].get_x() - po[0].get_x();
			cout << "İnner side: " << side << endl;
		}
		return output;	
	}

	const bool Polygon::operator== (Polygon &p2){
		if( count == p2.count ){
			for( int i = 0; i < count; i++){
				if( points[i].get_x() != p2.points[i].get_x() )
					return false;
			}
			for( int i = 0; i < count; i++){
				if( points[i].get_y() != p2.points[i].get_y() )
					return false;
			}		
			return true;
		}
		return false;
	}
	const bool Polygon::operator!= (Polygon &p2){
		if (*this == p2 )
			return false;
		return true;
	}
	// Point2D class
	Polygon::Point2D::Point2D(double a, double b){
		this->x = a;
		this->y = b;
	}

	void Polygon::Point2D::set_points(double a, double b){
		this->x = a;
		this->y = b;	
	}
	double Polygon::Point2D::get_x(){
		return this->x;
	}
	double Polygon::Point2D::get_y(){
		return this->y;
	}	
}




