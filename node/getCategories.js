'use strict';

var data = require('../data/phys2013.json');

var cat, counts = [];

for(var a in data['articles']) {
    cat = data['articles'][a]['primary_category'];
    if(cat in counts){ counts[cat]++; }
    else { counts[cat] = 1; }
}
Object.keys(counts).sort()
    .forEach(function(v) {
        console.log(v + ',' + counts[v])
        });
/*
for (cat in counts) {
    console.log(cat + ',' + counts[cat]);
}*/
