#ifndef INCLUDED_TRIANGLE
#define INCLUDED_TRIANGLE

#include "Shape.h"
#include <iostream>

class Triangle : public Shape
{
public:
	Triangle(int base, int height);
	~Triangle();

	void CalculateArea();
	void Output();

private:
	int mBase;
	int mHeight;
	int mArea;
};

#endif