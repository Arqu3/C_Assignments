#include "Container.h"

using namespace std;

Container::Container() :
mShapes()
{
}

Container::~Container()
{
	clear();
}

void Container::add(Shape *shape)
{
	mShapes.push_back(shape);
}

void Container::output()
{
	for (ShapeVector::size_type i = 0; i < mShapes.size(); i++)
	{
		mShapes[i]->CalculateArea();
		cout << mShapes[i]->Output() << endl;
	}
}

void Container::clear()
{
	internalClear();
}

void Container::internalClear()
{
	while (!mShapes.empty())
	{
		delete mShapes.back();
		mShapes.pop_back();
	}
}