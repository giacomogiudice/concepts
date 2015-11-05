#ifndef _TIMER_H_
#define _TIMER_H_

#include <ctime>
#include <iostream>

class Timer
{
private:
	static clock_t start_time;
	static clock_t end_time;
public:
	Timer();

	void stop();
	void reset();
	double getDiff() const;

	friend std::ostream& operator<<(std::ostream &stream, Timer &t);
};

#endif