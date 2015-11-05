#include <iomanip>
#include <cmath>
#include "timer.h"

using namespace std;

clock_t Timer::start_time = 0;
clock_t Timer::end_time = 0;

Timer::Timer()
{
	start_time = clock();
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
	stream << "<" << setw(8) << setprecision(3) << t.getDiff() << " s> ";
	return stream;
}