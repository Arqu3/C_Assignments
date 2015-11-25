#include "ShapeTool.h"
#include "Square.h"

Shape* ShapeTool::createSquare(int x, int y)
{
	return new Square(x, y);
}