'use strict';

var data = require('../data/phys2013.json');

var concept, counts = [];

var threshold = 50;
if(process.argv.length > 2) { threshold = process.argv[2]; } 

for(var aid in data['articles']) {
    for(var cid in data['articles'][aid]['concepts']) {
        concept = data['concepts'][cid]['name'];
        if (concept in counts) { counts[concept]++; }
        else { counts[concept] = 1; }
    }
}

var sortable = [];
for (concept in counts) {
    sortable.push([concept, counts[concept]]);
}
sortable.sort(function(a,b){return b[1]-a[1]});


for(var i=0; i<threshold; i++) {
    console.log(sortable[i][0] + "," + sortable[i][1]);
}
