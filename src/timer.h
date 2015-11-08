#ifndef __TIMER_H__
#define __TIMER_H__

#include <ctime>
#include <iostream>

#define COMMON_START 0

class Timer
{
private:
	static clock_t start_time;
	static clock_t end_time;
public:
	Timer();
	Timer(int);

	void stop();
	void reset();
	double getDiff() const;

	friend std::ostream& operator<<(std::ostream &stream, Timer &t);
};

#endif