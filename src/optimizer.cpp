#include <iostream>
#include "optimizer.h" 
#include "function.h" 
#include "debug.h" 
#include "timer.h"
#include "io.h"

using namespace alglib;

Optimizer::Optimizer(double epsG, double epsF, double epsX, int maxIts)
{
	N_iter = 0;
	
	epsg = epsG;
	epsf = epsF;
	epsx = epsX;
	maxits = maxIts;
}

void Optimizer::init(const std::string &input, const std::string &concepts, const std::string &spins,
				double lambda_h, double lambda_J)
{
	Function::init(concepts, spins, lambda_h, lambda_J);
	size_t x_length = Function::n_concepts()*(Function::n_concepts()+1)/2;
	if(input.empty())
	{
		x.setlength(x_length);
	}
	else
	{
		IO io(input);
		x = io.readTriangleMatrix();
		check(x.length() == x_length, "Number of parameters read does not match number of concepts.") 
		std::cout << x.tostring(2);
	}
}

void Optimizer::run()
{
	minlbfgscreate(1, x, state);
	minlbfgssetcond(state, epsg, epsf, epsx, maxits);
	minlbfgsoptimize(state,Function::evaluate);
	minlbfgsresults(state, x, rep);

	log_info("Termination code %d in %i iterations", int(rep.terminationtype), int(rep.iterationscount));
}

triangleMatrix Optimizer::result() const
{
	return x;
}