#ifndef INCLUDED_CLOCK
#define INCLUDED_CLOCK

#include <cassert>
#include <iostream>

class Clock
{
public:
	Clock(double sec, int min, int hour, int day);
	Clock(const Clock &clock);
	~Clock();
	Clock& operator = (const Clock &clock);
	void setSecond(double sec);
	void setMinute(int min);
	void setHour(int hour);
	void setDay(int day);
	void tick();

	void output();

private:
	void updateTime();
	bool invariant() const;

	double mSec;
	int mMin;
	int mHour;
	int mDay;
};

#endif