#include "Square.h"

using namespace std;

Square::Square(int width, int height) :
mX(width),
mY(height)
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