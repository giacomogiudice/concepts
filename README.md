# Interaction Between Concepts
Author: Giacomo Giudice

## Introduction
This code was developed as the numerical support for the project _Interaction Between Concepts: A Pseudolikelihood Approach_ for the course _Computer Simulations of Physical Systems_ by Prof. Pasquarello.

## Compilation
In order to run the code one must compile the __ALGLIB__ library first, and then the rest of the code. This is conveniently handled by the `makefile`. Once you're in the trunk directory the commands are
- `$ make lib` to compile the library
- `$ make` to compile the main source code
- `$ make clean` optional, remove the object files in `build/`
That's it! The executable can then be run with
`$ bin/main

Note: requires _C++11_. Tested on a x86_64 machine compiling under clang 3.4.

## Data
The original data is provided in `.json` form. To accelerate computations the data was preprocessed using __Node.js__. The following programs are provided in the `node/` directory
- `createConceptList.js`
- `createFreqMatrix.js`
- `createSpinMatrix.js`
- `createTagList.js`
- `getCategories.js`

## Licence
This software is distributed under the GNU General Public License (GPLv3). Details can be found at the [GNU website](http://www.gnu.org/licenses/gpl.html)
