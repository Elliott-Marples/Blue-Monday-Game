#ifndef BLUE_MONDAY_VECTOR_H_
#define BLUE_MONDAY_VECTOR_H_



class Vector {
public:
	Vector();
	Vector(float x, float y);

	float x, y;
	float getMagnitude();
};

#endif // !BLUE_MONDAY_VECTOR_H_
