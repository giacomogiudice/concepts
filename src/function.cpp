#include <cmath>
#include <iostream>
#include <omp.h>
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

void Function::init(const std::string &conceptsfile, const std::string &spinsfile, double lambda_h, double lambda_J)
{
	IO io(spinsfile);
    spins = io.parseCSV<size_t>();
    io.file(conceptsfile);
    n = io.linecount();
    N_articles = spins.size();
    computeFreq();

	Function::lambda_h = lambda_h;
	Function::lambda_J = lambda_J;
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
		}
	}
	for(size_t i = 0; i < freq.length(); i++) { freq[i] = freq[i]/double(N_articles); }
}
void Function::evaluate(const triangleMatrix &x, double &function, triangleMatrix &grad, void *ptr)
{
	// Initialize  return values to zero
	for(size_t i = 0; i < freq.length(); i++) { grad[i] = 0; }
	double func = 0;

	#pragma omp parallel for reduction(+:func) schedule(dynamic)
	for(size_t i = 0; i < n; i++)
	{
		size_t d = triangleIndex(i,i);
		double sum = 0;
		for(size_t a = 0; a < N_articles; a++)
		{
			double expterm = expTerm(x, a, i, d);
			sum += log(1.0 + expterm);
			grad[d] += expterm/(1.0 + expterm);
			for(auto s : spins[a])
			{
				if(s < i) { grad[triangleIndex(i,s)] += expterm/(1.0 + expterm); }
			}
		}
		func += sum/N_articles - freq[d]*x[d] + lambda_h*x[d]*x[d];
		grad[d] = grad[d]/N_articles - freq[d] + 2.0*lambda_h*x[d];
		for(size_t j = 0; j < i; j++)
		{
			size_t subd = triangleIndex(i,j);
			func += -2.0*freq[subd]*x[subd] + lambda_J*x[subd]*x[subd];
			grad[subd] = grad[subd]/N_articles - freq[subd] + 2.0*lambda_J*x[subd];
		} 
	}
	function = func;
	Timer time;
	std::cout << time << "Ended function evaluation " <<  N_eval << std::endl;
	N_eval++;
}

double Function::expTerm(const triangleMatrix &x, size_t a, size_t i, size_t d)
{
	double arg = x[d];
	for(auto s : spins[a])
	{
		if(s > i) { arg += x[triangleIndex(s,i)]; }
		else if(s < i) { arg += x[triangleIndex(i,s)]; }
	}
	return exp(arg);
}

size_t Function::triangleIndex(size_t i, size_t j)
{
	check_debug(i >= j, "Indexing problem on (%zu,%zu), it should be i >= j",i, j)
	size_t index = i*(i + 1)/2 + j;
	check_debug(index < freq.length(), "Index (%zu,%zu) exceeds dimensions",i, j);
	return index;
}

size_t Function::n_concepts() { return n; }
size_t Function::n_articles() { return N_articles; }