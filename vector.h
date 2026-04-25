#ifndef BLUE_MONDAY_VECTOR_H_
#define BLUE_MONDAY_VECTOR_H_

#include "SDL.h"



class Vector {
public:
	Vector();
	Vector(int x, int y);

	int x, y;
	float getMagnitude();
};

#endif // !BLUE_MONDAY_VECTOR_H_
