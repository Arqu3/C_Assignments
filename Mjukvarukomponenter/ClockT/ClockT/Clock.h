#ifndef INCLUDED_CLOCK
#define INCLUDED_CLOCK

#include <iostream>

class Clock
{
public:
	Clock(int sec = 0, int min = 0, int hour = 0, int day = 0);
	Clock(const Clock &clock);
	~Clock();
	Clock& operator=(const Clock &clock);

	void setSecond(int sec);
	void setMinute(int min);
	void setHour(int hour);
	void setDay(int day);

	void tick();
	void output();

	int getSecond() const;
	int getMinute() const;
	int getHour() const;
	int getDay() const;

private:
	void updateTime();
	bool invariant() const;

	int mSec;
	int mMin;
	int mHour;
	int mDay;
};

bool operator==(const Clock &c0, const Clock &c1);
bool operator!=(const Clock &c0, const Clock &c1);

#endif