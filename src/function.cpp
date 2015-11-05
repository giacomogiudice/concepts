#include <cmath>
#include <cstdlib>
#include "function.h"
#include "io.h"

// Initialization of static members to zero or null
size_t Function::n_ = 5, Function::N_ = 0;

triangleMatrix Function::freq = "[]";
std::vector<std::vector<size_t>> Function::spins = 
{
	{0,1},
	{0,1},
	{2,3},
	{2,3},
	{0,1}
};

double Function::lambda_h = 0, Function::lambda_J = 0;

void Function::init()
{
	//TODO: parse values from external file
	// n_ = 3;
	N_ = spins.size();

	IO io;
    std::string file = "data/testdata/spinmatrix.csv";
    spins = io.parseCSV<size_t>(file);
    // std::cout << parser.writeCSV(spins);
    computeFreq();
	// printf("freq:%s\n", freq.tostring(2).c_str());

	lambda_h = 0.00;
	lambda_J = 0.00;
}

void Function::computeFreq()
{
	freq.setlength(n_*(n_ + 1)/2);
	for(size_t i = 0; i < freq.length(); i++) { freq[i] = 0; }
	for(size_t a = 0; a < N_; a++)
	{
		for(size_t i = 0; i < spins[a].size(); i++)
		{
			for(size_t j = 0; j <= i; j++)
			{
				freq[triangleIndex(spins[a][i],spins[a][j])] += 1.0;
			}
		}
	}
	for(size_t i = 0; i < freq.length(); i++) { freq[i] = freq[i]/N_; }
}
void Function::evaluate(const triangleMatrix &x, double &func, triangleMatrix &grad, void *ptr)
{
	size_t i,j;
	size_t a;
	size_t d = 0; // Superindex corrisponding to index kk
	size_t ind;
	//initialize to zero
	for(i = 0; i < freq.length(); i++) { grad[i] = 0; }
		func = 0;
	
	double prod, arg;
	for(i = 0; i < n_; i++)
	{
		prod = 1.0;
		for(a = 0; a < N_; a++)
		{
			arg = expArg(x, a, i, d);
			prod *= 1.0 + arg;
			grad[d] += exp(arg)/(1.0 + exp(arg));
			for(auto s : spins[a])
			{
				if(s < i) { grad[triangleIndex(s,i)] += exp(arg)/(1.0 + exp(arg)); }

			}
		}
		func += log(1.0 + exp(prod)) - freq[d]*x[d] + lambda_h*x[d]*x[d];
		grad[d] = grad[d]/N_ - freq[d] + 2.0*lambda_h*x[d];
		for(j = 0; j < i; j++)
		{
			ind = triangleIndex(i,j);
			func += -2.0*freq[ind]*x[ind] + lambda_J*x[ind]*x[ind];
			//double counting?
			grad[ind] = grad[ind]/N_ - freq[ind] + 2.0*lambda_J*x[ind];
			// func += -2.0*freq[d - j]*x[d -j] + lambda_J*x[d - j]*x[d - j];
			// grad[d - j] = 2.0*(grad[d - j]/N_ - freq[d - j] + lambda_J*x[d - j]);
		} 
		// Increment superindex for next iteration
		d += 2 + i;
	}
	// printf("x:%s\n", x.tostring(2).c_str());
	// printf("func:%f\n", func);
	// printf("grad:%s\n",grad.tostring(2).c_str());
}

double Function::expArg(const triangleMatrix &x, size_t a, size_t i, size_t d)
{
	double arg = x[d];
	for(auto s : spins[a])
	{
		if(s != i) { arg += x[triangleIndex(s,i)]; }
	}
	return arg;
}

size_t Function::triangleIndex(size_t i, size_t j)
{
	if(i > j) { return i*(i + 1)/2 + j; }
	else { return j*(j + 1)/2 + i; }
}

size_t Function::n() { return n_; }
size_t Function::N() { return N_; }