#include "optimizer.h" 

#include <cstdlib>

using namespace alglib;

void Optimizer::init()
{
	epsg = 0;
	epsf = 0;
	epsx = 0;
	maxits = 1;

	Function::init();
}
void reply(const real_1d_array &x, double func, void *ptr) 
{
	printf("iteration");
	printf("%s\n", x.tostring(2).c_str());
}

void Optimizer::run()
{
	triangleMatrix x;
	x.setlength(Function::n()*(Function::n()+1)/2);
	minlbfgscreate(1, x, state);
	minlbfgssetcond(state, epsg, epsf, epsx, maxits);
	minlbfgsoptimize(state,Function::evaluate);
	minlbfgsresults(state, x, rep);


	printf("Termination: %d\n", int(rep.terminationtype)); // EXPECTED: 4
    // printf("%s\n", x.tostring(3).c_str()); // EXPECTED: [-3,3]
}

