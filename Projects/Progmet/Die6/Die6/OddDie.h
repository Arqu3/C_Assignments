#ifndef INCLUDED_ODDDIE
#define INCLUDED_ODDDIE

#include "Die.h"

class OddDie : public Die
{
public:
	OddDie(Die *die);
	virtual ~OddDie();
	virtual void roll();
	virtual int read() const;

private:
	void ensureOddity();
	Die *mDie;
};

#endif