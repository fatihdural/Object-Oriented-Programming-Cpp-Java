#include <iostream>
#include <fstream>
#include <math.h>
# define PI 3.141592653589793238462643383279502884L // pi
#include "source.h"
using namespace std;

int main(){
	char shape_c; int count;
	double width, height, radius, side;
	double small_height, small_width, small_radius, small_side, empty_area;
	enum shapes {R, C, T}; 
	shapes shape, small_shape;
	cout << "Please enter the main container shape (R, C, T)" << endl;
	cin >> shape_c;
	if( shape_c == 'R'){
		shape = R;
		cout << "Please enter the width" << endl;
		cin >> width;
		cout << "Please enter the height" << endl;
		cin >> height;
		cout << "Please enter the small shape (R, C, T)" << endl;
		cin >> shape_c;
		if( shape_c == 'R'){
			small_shape = R;
			cout << "Please enter the width" << endl;
			cin >> small_width;
			cout << "Please enter the height" << endl;
			cin >> small_height;
		}
		else if( shape_c == 'C'){
			small_shape = C;
			cout << "Please enter the radius" << endl;
			cin >> small_radius;
		}
		else if( shape_c == 'T'){
			small_shape = T;
			cout << "Please enter the side" << endl;
			cin >> small_side;
		}
	}
	else if( shape_c == 'C'){
		shape = C;
		cout << "Please enter the radius" << endl;
		cin >> radius;
		cout << "Please enter the small shape (R, C, T)" << endl;
		cin >> shape_c;
		if( shape_c == 'R'){
			small_shape = R;
			cout << "Please enter the width" << endl;
			cin >> small_width;
			cout << "Please enter the height" << endl;
			cin >> small_height;
		}
		else if( shape_c == 'C'){
			small_shape = C;
			cout << "Please enter the radius" << endl;
			cin >> small_radius;
		}
		else if( shape_c == 'T'){
			small_shape = T;
			cout << "Please enter the side" << endl;
			cin >> small_side;
		}
	}
	else if( shape_c == 'T'){
		shape = T;
		cout << "Please enter the side" << endl;
		cin >> side;
		cout << "Please enter the small shape (R, C, T)" << endl;
		cin >> shape_c;
		if( shape_c == 'R'){
			small_shape = R;
			cout << "Please enter the width" << endl;
			cin >> small_width;
			cout << "Please enter the height" << endl;
			cin >> small_height;
		}
		else if( shape_c == 'C'){
			small_shape = C;
			cout << "Please enter the radius" << endl;
			cin >> small_radius;
		}
		else if( shape_c == 'T'){
			small_shape = T;
			cout << "Please enter the side" << endl;
			cin >> small_side;
		}
	}
	if( shape == R && small_shape == R ){
		count = rect_in_rect(width, height, small_width, small_height);
		empty_area = rect_in_rect_area(width, height, small_width, small_height, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";
	}
	else if( shape == R && small_shape == C ){
		count = circ_in_rect(width, height, small_radius);
		empty_area = circ_in_rect_area(width, height, small_radius, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";
	}
	else if( shape == R && small_shape == T ){
		count = triangle_in_rect(width, height, small_side);
		empty_area = triangle_in_rect_area(width, height, small_side, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";
	}
	
	else if( shape == C && small_shape == R ){
		count = rect_in_circ(radius, small_width, small_height);
		empty_area = rect_in_circ_area(radius, small_width, small_height, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";	
	}
	else if( shape == C && small_shape == C ){
		count = circ_in_circ(radius, small_radius);
		empty_area = circ_in_circ_area(radius, small_radius, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";	
	}
	else if( shape == C && small_shape == T ){
		count = triangle_in_circ(radius, small_side);
		empty_area = triangle_in_circ_area(radius, small_side, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";	
	}
	
	else if( shape == T && small_shape == R ){
		count = rect_in_triangle(side, small_width, small_height);
		empty_area = rect_in_triangle_area(side, small_width, small_height, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";	
	}
	else if( shape == T && small_shape == C ){
		count = circ_in_triangle(side, small_radius);
		empty_area = circ_in_triangle_area(side, small_radius, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";
	}
	else if( shape == T && small_shape == T ){
		count = triangle_in_triangle(side, small_side);
		empty_area = triangle_in_triangle_area(side, small_side, count);
		cout << "I can fit at most " << count <<  " small shapes into the main container. The empty area (red) in container is " << empty_area << ".";
	}			
	return 0;
}








