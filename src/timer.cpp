#include <iomanip>
#include <cmath>
#include "timer.h"

using namespace std;

clock_t Timer::start_time = 0;
clock_t Timer::end_time = 0;

Timer::Timer()
{ }

Timer::Timer(int number)
{
	if(number == COMMON_START) { start_time = clock(); }
}

void Timer::stop()
{
	end_time = clock();
}

void Timer::reset()
{
	start_time = clock();
	end_time = 0;
}

double Timer::getDiff() const
{
	return float(end_time - start_time)/CLOCKS_PER_SEC;
}

ostream& operator<<(ostream &stream,Timer &t)
{
	t.stop();
	int seconds = round(t.getDiff());
	int minutes =  seconds/60;
	int hours = minutes/60;
	minutes = minutes%60;
	seconds = seconds%60;
	stream << setw(4) << hours << ":" << std::setfill('0')
		   << setw(2) << minutes << ":"
		   << setw(2)<< seconds << " " << setfill(' ');
	return stream;
}