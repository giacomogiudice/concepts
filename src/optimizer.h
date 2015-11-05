#ifndef _OPTIMIZER_H_
#define _OPTIMIZER_H_

#include "alglib/stdafx.h"
#include "alglib/optimization.h"
#include "function.h"

class Optimizer
{
private:
	// These variables define stopping conditions for the underlying CG algorithm.
    // They should be stringent enough in order to guarantee overall stability
    // of the outer iterations.
	double epsg, epsf, epsx;
	alglib::ae_int_t maxits;

	alglib::minlbfgsstate state;
	alglib::minlbfgsreport rep;


public:
	// Optimizer();
	// ~Optimizer();
	void init();
	void run();
};

#endif