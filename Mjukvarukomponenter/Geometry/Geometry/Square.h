#ifndef INCLUDED_SQUARE
#define INCLUDED_SQUARE

#include "Shape.h"

class Square : public Shape
{
public:
	Square(int x, int y);
	~Square();

	void CalculateArea();
	int Output();

private:
	int mX;
	int mY;
	int mArea;
};

#endif