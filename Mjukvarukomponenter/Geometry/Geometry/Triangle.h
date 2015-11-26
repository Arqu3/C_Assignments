#ifndef INCLUDED_TRIANGLE
#define INCLUDED_TRIANGLE

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(int base, int height);
	~Triangle();

	void CalculateArea();
	int Output();

private:
	int mBase;
	int mHeight;
	int mArea;
};

#endif