#include "ShapeTool.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

Shape* ShapeTool::createSquare(int width, int height)
{
	return new Square(width, height);
}

Shape* ShapeTool::createCircle(int radius)
{
	return new Circle(radius);
}

Shape* ShapeTool::createTriangle(int base, int height)
{
	return new Triangle(base, height);
}