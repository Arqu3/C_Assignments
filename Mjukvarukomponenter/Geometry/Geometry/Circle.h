#ifndef INCLUDED_CIRCLE
#define INCLUDED_CIRCLE

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(int radius);
	~Circle();

	void CalculateArea();
	int Output();

private:
	int mRadius;
	int mArea;
};

#endif