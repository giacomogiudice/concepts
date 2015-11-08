#include <cmath>
#include <iostream>
#include "function.h"
#include "io.h"
#include "debug.h"
#include "timer.h"

// Initialization of static members to zero or null
size_t Function::n = 0, Function::N_articles = 0;
size_t Function::N_eval = 0;

triangleMatrix Function::freq = "[]";
std::vector<std::vector<size_t>> Function::spins = {}; 

double Function::lambda_h = 0, Function::lambda_J = 0;

void Function::init()
{
	IO io("data/spins.csv");
    spins = io.parseCSV<size_t>();
    io.file("data/concepts.csv");
    n = io.linecount();
    N_articles = spins.size();
    computeFreq();

	lambda_h = 1e-3;
	lambda_J = 1e-3;
	debug("n: %zu, N_articles: %zu",n,N_articles);
}

void Function::computeFreq()
{
	
	freq.setlength(n*(n + 1)/2);
	for(size_t i = 0; i < freq.length(); i++) { freq[i] = 0; }

	for(size_t a = 0; a < N_articles; a++)
	{
		for(size_t i = 0; i < spins[a].size(); i++)
		{
			for(size_t j = 0; j <= i; j++)
			{
				freq[triangleIndex(spins[a][i],spins[a][j])] += 1.0;
			}
			check_debug(freq[triangleIndex(i,i)] != 0, "Zero frequency in %zu", i);
		}
	}
	for(size_t i = 0; i < freq.length(); i++) { freq[i] = freq[i]/double(N_articles); }
}
void Function::evaluate(const triangleMatrix &x, double &func, triangleMatrix &grad, void *ptr)
{
	Timer time;

	std::cout << time << "Function evaluation " <<  N_eval << std::endl;
	N_eval++;
	size_t d = 0; // Superindex corrisponding to index kk
	size_t ind;
	// Initialize to zero
	for(size_t i = 0; i < freq.length(); i++) { grad[i] = 0; }
		func = 0;
	
	double prod, arg;
	for(size_t i = 0; i < n; i++)
	{
		prod = 1.0;
		for(size_t a = 0; a < N_articles; a++)
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
		grad[d] = grad[d]/N_articles - freq[d] + 2.0*lambda_h*x[d];
		for(size_t j = 0; j < i; j++)
		{
			ind = triangleIndex(i,j);
			func += -2.0*freq[ind]*x[ind] + lambda_J*x[ind]*x[ind];
			grad[ind] = grad[ind]/N_articles - freq[ind] + 2.0*lambda_J*x[ind];
		} 
		// Increment superindex for next iteration
		d += 2 + i;
	}
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
	size_t index = (i > j)? i*(i + 1)/2 + j : j*(j + 1)/2 + i; 
	check_debug(index < freq.length(), "Index (%zu,%zu) exceeds dimensions",i,j);
	return index;
}

size_t Function::n_concepts() { return n; }
size_t Function::n_articles() { return N_articles; }