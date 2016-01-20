# Interaction Between Concepts
by Giacomo Giudice

## Introduction
This is a __C++__ implementation of an automated ontology learning tool to extract the relationship between concepts in scientific literature.
For more information about the methodology see the [report](../tex/Concepts.pdf).

This code was developed as the numerical support for the project _Interaction Between Concepts: A Pseudolikelihood Approach_ for the course _Computer Simulations of Physical Systems_ by Prof. Pasquarello.

## Compilation
In order to run the code one must compile the [ALGLIB](http://www.alglib.net/) library first. The `makefile` handles this &mdash; from the trunck lauch  
`$ make all`  
That's it! The executable can now be run with  
`$ bin/main` or `$ bin/main < config.in` using a configuration file.  
Finally, the object files can be optionally removed with `$ make clean`.

__Note__: requires __C++11__ to compile correctly. Tested on a x86_64 architectures compiling under GCC 4.8.4, GCC 4.8.1 and Clang 3.4.

## Data Formatting
The original data is provided in `.json` form. To prepare the data for the main routine some short programs in __Node.js__ are provided in the `node/` directory:
- `createCSV.js` creates the "spin matrix" and the corresponding list of the concept names. 
- `topSpins.js` does the same for a subset of the most frequent concepts
- `randomSpins.js` creates a random matrix for testing purposes.
- `conceptCats.js` creates a file with the indexes of the category for each concepts
- `createTagList.js` and `getCategories.js` are used to generate statistics on the database for the paper.

## Community Detection
Once the main optimization routine is completed, several __MATLAB__ scripts are available in the `matlab/` directory to analyse the data:
- `couplings.m` extracts the couplings and places them in a matrix
- `plotPDF.m` plots the parameter distribution
- `tscan.m` calculates a certain t-value for a distribution
- `toNcol.m` creates a sparse adjacency matrix to be saved in the `.ncol` format for community detection.

The `communities.py` script extracts the communies from an  the `python/` directory and saves it to a file. Requires the `igraph` module.

## Licence
This software is distributed under the GNU General Public License (GPLv3). Details can be found at the [GNU website](http://www.gnu.org/licenses/gpl.html).
