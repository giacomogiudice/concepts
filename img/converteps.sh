#!/bin/sh

for file in *.eps; do
    echo "    $file";
    pstopdf "$file";
done 
rm -f *.eps;
