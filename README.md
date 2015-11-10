# Interaction Between Concepts
by Giacomo Giudice

## Introduction
This code was developed as the numerical support for the project _Interaction Between Concepts: A Pseudolikelihood Approach_ for the course _Computer Simulations of Physical Systems_ by Prof. Pasquarello.

## Compilation
In order to run the code one must compile the [ALGLIB](http://www.alglib.net/) library first. The `makefile` handles this &mdash; from the trunck lauch  
`$ make all`  
That's it! The executable can now be run with  
`$ bin/main` or `$ bin/main < config.in` using a configuration file.  
Finally, the object files can be optionally removed with `$ make clean`.

__Note__: requires __C++11__ to compile correctly. Tested on a x86_64 architectures compiling under GCC 4.8.4, GCC 4.8.1 and Clang 3.4.

## Data
The original data is provided in `.json` form. To prepare the data for the main routine some short programs in __Node.js__ are provided in the `node/` directory.
- `createCSV.js` creates the "spin matrix" and the corresponding list of the concept names. 
- `randomSpins.js` creates a random matrix for testing purposes.
- `createTagList.js` and `getCategories.js` are used to generate statistics on the database for the paper.

## Licence
This software is distributed under the GNU General Public License (GPLv3). Details can be found at the [GNU website](http://www.gnu.org/licenses/gpl.html).
