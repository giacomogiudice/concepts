/* 
 *  Author: Giacomo Giudice
 *	Released under the GNU Public License 
 */

#include <iostream>
#include "timer.h"
#include "optimizer.h"

using namespace std;

int main(int argc, char **argv)
{
	Timer time;

    cout << time << "Program started.\n";

    Optimizer simulation;
    simulation.init();
    
    cout << time << "Data loaded and frequecies computed\n";

    simulation.run();

    cout << time << "Done.\n";

    return 0;
}