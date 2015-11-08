# Interaction Between Concepts
by Giacomo Giudice

## Introduction
This code was developed as the numerical support for the project _Interaction Between Concepts: A Pseudolikelihood Approach_ for the course _Computer Simulations of Physical Systems_ by Prof. Pasquarello.

## Compilation
In order to run the code one must compile the [ALGLIB](http://www.alglib.net/) library first, and then the rest of the code. The `makefile` handles this; once you're in the trunk directory it is sufficient to do  
`$ make all`  
That's it! The executable can then be run with  
`$ bin/main`  
Finally, the object files can be removed with `$ make clean`

__Note__: requires __C++11__ to compile correctly. Tested on a x86_64 architectures compiling under GCC 4.8.1 and Clang 3.4.

## Data
The original data is provided in `.json` form. To prepare the data for the main routine some short programs in __Node.js__ are provided in the `node/` directory.
- `createCSV.js` creates the "spin matrix" and the corresponding list of the concept names. 
- `createTagList.js` and `getCategories.js` are used to generate statistics on the database for the paper

## Licence
This software is distributed under the GNU General Public License (GPLv3). Details can be found at the [GNU website](http://www.gnu.org/licenses/gpl.html).
