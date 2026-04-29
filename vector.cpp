#include "vector.h"

#include <cmath>



Vector::Vector() {
	x = 0;
	y = 0;
}

Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
}

float Vector::getMagnitude() {
	return abs(x+y);
}