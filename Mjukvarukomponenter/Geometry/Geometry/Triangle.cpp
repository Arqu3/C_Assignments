#include "Triangle.h"

using namespace std;

Triangle::Triangle(int base, int height) :
mBase(base),
mHeight(height)
{
	CalculateArea();
}

Triangle::~Triangle()
{
}

void Triangle::CalculateArea()
{
	mArea = (mBase * mHeight) / 2;
}

void Triangle::Output()
{
	cout << "Area of triangle: " << mArea << endl;
}