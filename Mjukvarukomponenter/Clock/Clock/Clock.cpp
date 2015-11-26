#include "Clock.h"

using namespace std;

Clock::Clock(double sec, int min, int hour, int day) :
mSec(sec),
mMin(min),
mHour(hour),
mDay(day)
{
	assert(sec >= 0 && sec <= 60 && min >= 0 && min <= 60 && hour >= 0 && hour <= 24 && day >= 0);
	updateTime();
	assert(mSec == sec && mMin == min && mHour == hour && mDay == day);
	assert(invariant());
}

Clock::Clock(const Clock &clock) :
mSec(clock.mSec),
mMin(clock.mMin),
mHour(clock.mHour),
mDay(clock.mDay)
{
	assert(invariant());
}

Clock::~Clock()
{
	assert(invariant());
}

Clock& Clock::operator=(const Clock &clock)
{
	assert(invariant());
	mSec = clock.mSec;
	mMin = clock.mMin;
	mHour = clock.mHour;
	mDay = clock.mDay;
	assert(invariant());
	return *this;
}

void Clock::setSecond(double s)
{
	assert(invariant());
	assert(s >= 0 && s <= 60);
	mSec = s;
	updateTime();
	assert(mSec == s);
	assert(invariant());
}

void Clock::setMinute(int min)
{
	assert(invariant());
	assert(min >= 0 && min <= 60);
	mMin = min;
	updateTime();
	assert(mMin == min);
	assert(invariant());
}

void Clock::setHour(int hour)
{
	assert(invariant());
	assert(hour >= 0 && hour <= 24);
	mHour = hour;
	updateTime();
	assert(mHour == hour);
	assert(invariant());
}

void Clock::setDay(int day)
{
	assert(invariant());
	assert(day >= 0);
	mDay = day;
	updateTime();
	assert(mDay == day);
	assert(invariant());
}

void Clock::updateTime()
{
	if (mSec >= 59)
	{
		mMin++;
		mSec = 0;
	}

	if (mMin >= 59)
	{
		mHour++;
		mMin = 0;
	}


	if (mHour >= 24)
	{
		mDay++;
		mHour = 0;
	}
}

void Clock::tick()
{
	updateTime();
	mSec += 1;
}

void Clock::output()
{
	assert(invariant());
	cout << "Second: " << mSec << endl;
	cout << "Minute: " << mMin << endl;
	cout << "Hour: " << mHour << endl;
	cout << "Day: " << mDay << endl;
}

bool Clock::invariant() const
{
	return mSec >= 0 && mSec <= 60 && mMin >= 0 && mMin <= 60 && mHour >= 0 && mHour <= 24 && mDay >= 0;
}