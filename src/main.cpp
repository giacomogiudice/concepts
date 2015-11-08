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
	Timer time(COMMON_START);

    cout << time << "Program started\n";

    Optimizer simulation;
    simulation.init();
    
    cout << time << "Data loaded and frequecies computed\n";

    simulation.run();

    cout << time << "Optimization done. Writing to file\n";

    IO io("data/output.csv");
    io.writeTriangleMatrix(simulation.result());

    cout << time << "All done\n";

    return 0;
}