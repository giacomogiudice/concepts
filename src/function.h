#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include "alglib/ap.h"

typedef alglib::real_1d_array triangleMatrix;

class Function
{
private:
	static size_t n, N_articles, N_eval;

	static triangleMatrix freq;
	static std::vector<std::vector<size_t>> spins;
	static double lambda_h, lambda_J;

	static void computeFreq();
	static double expArg(const triangleMatrix &x, size_t a, size_t i, size_t d);

public:
	static void init();
	static size_t triangleIndex(size_t i, size_t j);

	static void evaluate(const triangleMatrix &x, double &func, triangleMatrix &grad, void *ptr);

	static size_t n_concepts();
	static size_t n_articles();
};

#endif