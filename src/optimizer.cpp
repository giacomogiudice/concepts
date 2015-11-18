#include <sstream>
#include "optimizer.h" 
#include "function.h" 
#include "debug.h" 
#include "timer.h"
#include "io.h"

using namespace alglib;

Optimizer::Optimizer(double epsG, double epsF, double epsX, int maxIts)
{	
	epsg = epsG;
	epsf = epsF;
	epsx = epsX;
	maxits = maxIts;
}

void Optimizer::init(const std::string &input, const std::string &concepts, const std::string &spins,
				double lambda_h, double lambda_J)
{
	Function::init(concepts, spins, lambda_h, lambda_J);
	size_t x_length = Function::n_concepts()*(Function::n_concepts() + 1)/2;
	if(input.empty())
	{
		x.setlength(x_length);
		for(size_t i = 0; i < x_length; i++) { x[i] = 0; }
	}
	else
	{
		IO io(input);
		x = io.readTriangleMatrix();
		check(x.length() == x_length, "Number of parameters read does not match number of concepts.") 
	}
}

std::string Optimizer::run()
{
	minlbfgscreate(1, x, state);
	minlbfgssetcond(state, epsg, epsf, epsx, maxits);
	minlbfgsoptimize(state,Function::evaluate);
	minlbfgsresults(state, x, rep);

	std::ostringstream oss;
	switch(int(rep.terminationtype))
	{
		case -8: oss << "NaN or infinite values detected."; break;
		case -7: oss << "Gradient verification failed."; break;
		case -2: oss << "NaN or infinite values detected."; break;
		case 1: oss << "Condition met on EpsF."; break;
		case 2: oss << "Condition met on EpsX."; break;
		case 4: oss << "Condition met on EpsG."; break;
		case 5: oss << "Maximum number of iterations attained."; break;
		case 7: oss << "Stopping conditions are too stringent."; break;
		case 8: oss << "Terminated by user."; break;
		default: oss << "Unknown return value " << rep.terminationtype << "."; 
	}
	oss << " Total iterations: " << rep.iterationscount << "\n";
	return oss.str();
}

triangleMatrix Optimizer::result() const
{
	return x;
}