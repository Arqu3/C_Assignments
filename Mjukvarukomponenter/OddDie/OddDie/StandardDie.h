#ifndef INCLUDED_STANDARDDIE
#define INCLUDED_STANDARDDIE

#include "Die.h"

class StandardDie : public Die
{
public:
	virtual void roll();
	virtual int read() const;
	static StandardDie die4();
	static StandardDie die6();
	static StandardDie die8();
	static StandardDie die10();
	static StandardDie die12();
	static StandardDie die20();

private:
	StandardDie(int max);
	int mValue;
	int mMax;
};

#endif