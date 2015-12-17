#!/usr/bin/python

# Creates membership array from .ncol unweighed file.
# First argument is input, second is output

import sys
from igraph import *

g = Graph.Read_Ncol(sys.argv[1], directed=False)
vg = g.community_multilevel(return_levels=False)

with open(sys.argv[2], 'w') as f:
    f.write(str(vg))
print "Computed modularity: ",vg.modularity
