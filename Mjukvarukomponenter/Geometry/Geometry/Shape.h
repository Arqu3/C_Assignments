#ifndef INCLUDED_SHAPE
#define INCLUDED_SHAPE

class Shape
{
public:
	virtual ~Shape();
	virtual void CalculateArea() = 0;
	virtual int Output() = 0;
};

#endif 
