#ifndef INCLUDED_SHAPETOOL
#define INCLUDED_SHAPETOOL

#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

class Shape;

struct ShapeTool
{
	static Shape* createSquare(int width, int height);
	static Shape* createCircle(int radius);
	static Shape* createTriangle(int base, int height);
};

#endif