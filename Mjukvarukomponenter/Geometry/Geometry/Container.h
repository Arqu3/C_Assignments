#ifndef INCLUDED_CONTAINER
#define INCLUDED_CONTAINER

#include "Shape.h"
#include <vector>
#include <iostream>

class Container
{
public:
	Container();
	~Container();

	void add(Shape *shape);
	void output();
	void clear();

private:
	void internalClear();

	typedef std::vector<Shape*> ShapeVector;
	ShapeVector mShapes;
};

#endif