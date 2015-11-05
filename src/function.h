#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "alglib/ap.h"

typedef alglib::real_1d_array triangleMatrix;

class Function
{
private:
	static size_t n_,N_;
	
	static triangleMatrix freq;
	static std::vector<std::vector<size_t>> spins;
	static double lambda_h, lambda_J;

	static void computeFreq();
	static double expArg(const triangleMatrix &x, size_t a, size_t i, size_t d);
	static size_t triangleIndex(size_t i, size_t j);

public:
	static void init();
	static void evaluate(const triangleMatrix &values, double &func, triangleMatrix &grad, void *ptr);

	static size_t n();
	static size_t N();
};

#endif