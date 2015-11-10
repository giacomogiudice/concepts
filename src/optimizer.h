#ifndef __OPTIMIZER_H__
#define __OPTIMIZER_H__

#include <string>
#include "alglib/stdafx.h"
#include "alglib/optimization.h"
#include "function.h" 

class Optimizer
{
private:
	size_t N_iter;

	triangleMatrix x;
	// These variables define stopping conditions for the underlying CG algorithm.
    // They should be stringent enough in order to guarantee overall stability
    // of the outer iterations.
	double epsg, epsf, epsx;
	alglib::ae_int_t maxits;

	alglib::minlbfgsstate state;
	alglib::minlbfgsreport rep;

	// void callback(const alglib::real_1d_array &x, double func, void *ptr);

public:
	Optimizer(double epsG, double epsF, double epsX, int maxIts = 0);

	void init(const std::string &input, const std::string &concepts, const std::string &spins,
				double lambda_h, double lambda_J);
	std::string run();

	triangleMatrix result() const;
};

#endif