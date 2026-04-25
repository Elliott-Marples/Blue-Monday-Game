#include "vector.h"



Vector::Vector() {
	x = 0;
	y = 0;
}

Vector::Vector(int x, int y) {
	this->x = x;
	this->y = y;
}

float Vector::getMagnitude() {
	return abs(x+y);
}