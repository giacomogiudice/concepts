# Interaction Between Concepts
Author: Giacomo Giudice

## Introduction
This code was developed as the numerical support for the project _Interaction Between Concepts: A Pseudolikelihood Approach_.

## Compilation
In order to run the code one must compile the __ALGLIB__ library first, and then the rest of the code. This is conveniently handled by the `makefile`. Once you're in the trunk directory the commands are
`$ make lib` to compile the library
`$ make` to compile the main source code
The object files in `build/` can then optionally be removed with
`$ make clean`
That's it! The executable can then be run with
`$ bin/main`

## Licence
This software is distributed under the GNU General Public License (GPLv3). Details can be found at the [GNU website](http://www.gnu.org/licenses/gpl.html)
