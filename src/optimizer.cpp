#include <iostream>
#include "optimizer.h" 
#include "function.h" 
#include "debug.h" 
#include "timer.h"
#include "io.h"

using namespace alglib;

void Optimizer::init()
{
	N_iter = 0;
	
	epsg = 1e-8;
	epsf = 0;
	epsx = 1e-6;
	maxits = 1;

	Function::init();
}

void Optimizer::run()
{
	
	x.setlength(Function::n_concepts()*(Function::n_concepts()+1)/2);
	minlbfgscreate(1, x, state);
	minlbfgssetcond(state, epsg, epsf, epsx, maxits);
	minlbfgsoptimize(state,Function::evaluate);
	minlbfgsresults(state, x, rep);

	log_info("Termination code %d in %i iterations", int(rep.terminationtype), int(rep.iterationscount)); // EXPECTED: 4
}

triangleMatrix Optimizer::result() const
{
	return x;
}