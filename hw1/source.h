#include <iostream>
#include <fstream>
#include <math.h>
# define PI 3.141592653589793238462643383279502884L // pi
using namespace std;

int rect_in_rect(const double width, const double height, const double small_width, const double small_height);
double rect_in_rect_area(const double width, const double height, const double small_width, const double small_height, const int count);
int circ_in_rect(const double width, const double height, const double small_radius);
double circ_in_rect_area(const double width, const double height, const double small_radius, const int count);
int triangle_in_rect(const double width, const double height, const double small_side);
double triangle_in_rect_area(const double width, const double height, const double small_side, const int count);

int rect_in_circ(const double radius, const double small_width, const double small_height);
double rect_in_circ_area(const double radius, const double small_width, const double small_height, const int count);
int circ_in_circ(const double radius, const double small_radius);
double circ_in_circ_area(const double radius, const double small_radius, const int count);
int triangle_in_circ(const double radius, const double small_side);
double triangle_in_circ_area(const double radius, const double small_side, const int count);

int rect_in_triangle(const double side, const double small_width, const double small_height);
double rect_in_triangle_area(const double side, const double small_width, const double small_height, const int count);
int circ_in_triangle(const double side, const double small_radius);
double circ_in_triangle_area(const double side, const double small_radius, const int count);
int triangle_in_triangle(const double side, const double small_side);
double triangle_in_triangle_area(const double side, const double small_side, int count);
