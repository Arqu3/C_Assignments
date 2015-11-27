#ifndef INCLUDED_CIRCLE
#define INCLUDED_CIRCLE

#include "Shape.h"
#include <iostream>

class Circle : public Shape
{
public:
	Circle(int radius);
	~Circle();

	void CalculateArea();
	void Output();

private:
	int mRadius;
	int mArea;
};

#endif