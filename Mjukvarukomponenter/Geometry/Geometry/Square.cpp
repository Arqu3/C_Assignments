#include "Square.h"

using namespace std;

Square::Square(int x, int y) :
mX(x),
mY(y)
{
	CalculateArea();
}

Square::~Square()
{
}

void Square::CalculateArea()
{
	mArea = mX * mY;
}

int Square::Output()
{
	return mArea;
}