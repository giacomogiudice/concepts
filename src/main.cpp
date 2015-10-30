#include "stdafx.h"
#include <cstdio>
#include "optimization.h"

using namespace alglib;

int main(int argc, char **argv)
{
    printf("Hello World!\n");

    // These variables define stopping conditions for the underlying CG algorithm.
    // They should be stringent enough in order to guarantee overall stability
    // of the outer iterations.
    double epsg = 1e-6;
    double epsf = 0;
    double epsx = 0;

    return 0;
}
