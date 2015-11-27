#ifndef INCLUDED_SQUARE
#define INCLUDED_SQUARE

#include "Shape.h"
#include <iostream>

class Square : public Shape
{
public:
	Square(int width, int height);
	~Square();

	void CalculateArea();
	void Output();

private:
	int mX;
	int mY;
	int mArea;
};

#endif