#include "ClockTest.h"
#include "Clock.h"
#include <cassert>

using namespace std;

void ClockTest::run()
{
	Clock c0;
	assert(c0.getSecond() == 0);
	assert(c0.getMinute() == 0);
	assert(c0.getHour() == 0);
	assert(c0.getDay() == 0);

	Clock c1(4, 10, 16, 1);
	assert(c1.getSecond() == 4);
	assert(c1.getMinute() == 10);
	assert(c1.getHour() == 16);
	assert(c1.getDay() == 1);

	Clock c2;
	c2 = c1;
	assert(c2.getSecond() == 4);
	assert(c2.getMinute() == 10);
	assert(c2.getHour() == 16);
	assert(c2.getDay() == 1);

	Clock c3(c2);
	assert(c3.getSecond() == 4);
	assert(c3.getMinute() == 10);
	assert(c3.getHour() == 16);
	assert(c3.getDay() == 1);

	Clock c4(1, 0, 10, 2);
	c4.setSecond(58);
	assert(c4.getSecond() == 58);
	c4.setMinute(1);
	assert(c4.getMinute() == 1);
	c4.setHour(8);
	assert(c4.getHour() == 8);
	c4.setDay(325);
	assert(c4.getDay() == 325);

	Clock cT0(0, 0, 0, 0);
	Clock cT1(0, 0, 0, 0);

	Clock cT2(2, 0, 1, 0);
	Clock cT3(2, 0, 1, 0);

	Clock cT4(0, 1, 0, 1);
	Clock cT5(0, 1, 0, 1);

	assert(cT0 == cT0);
	assert(cT2 == cT3);
	assert(cT4 == cT5);

	assert(cT0 != cT2);
	assert(cT4 != cT1);
	assert(cT3 != cT5);
}