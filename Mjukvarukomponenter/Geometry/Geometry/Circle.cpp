#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

Circle::Circle(int radius) :
mRadius(radius)
{
	CalculateArea();
}

Circle::~Circle()
{
}

void Circle::CalculateArea()
{
	mArea = (mRadius * mRadius) * M_PI;
}

int Circle::Output()
{
	return mArea;
}