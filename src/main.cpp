/* 
 *  Author: Giacomo Giudice
 *	Released under the GNU Public License 
 */

#include <iostream>
#include "timer.h"
#include "optimizer.h"
#include "io.h"

using namespace std;

int main(int argc, char **argv)
{
	string concepts, spins, output, input;
	double epsF = 0, epsG = 0, epsX = 0;
	int maxIts = 0;
	double lambda_h = 0, lambda_J = 0;

	cout << "Enter parameter name and their valued\n";
	string key, value;
	while(!cin.eof())
	{
		cin >> key >> value;
		if(key == "concepts_list")		{ concepts = value; 		}
		else if(key == "spin_matrix") 	{ spins = value; 			}
		else if(key == "output") 		{ output = value;			}
		else if(key == "input")			{ input = value; 			}
		else if(key == "eps_f")			{ epsF = stod(value); 		}
		else if(key == "eps_g")			{ epsG = stod(value); 		}
		else if(key == "eps_x")			{ epsX = stod(value); 	 	}
		else if(key == "max_iterations"){ maxIts = stoi(value);  	}
		else if(key == "lambda_h")		{ lambda_h = stod(value);	}
		else if(key == "lambda_J")		{ lambda_J = stod(value);	}
		else { log_warn("Unrecognised parameter %s",key.c_str());	}
	}

	Timer time(COMMON_START);

    cout << time << "Routine started\n";

    Optimizer simulation(epsF, epsG, epsX, maxIts);
    
    simulation.init(input,concepts,spins,lambda_h,lambda_J);

    cout << time << "Data loaded and frequecies computed\n";

    // simulation.run();

    cout << time << "Optimization done. Writing to file\n";

    IO io(output);
    io.writeTriangleMatrix(simulation.result());

    cout << time << "All done\n";

    return 0;
}