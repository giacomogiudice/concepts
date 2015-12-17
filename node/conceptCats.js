'use strict';

var data = require('../data/phys2013.json');
var fs = require('fs');

// Number of output indices
var n_index = 4;
var catIndex = {
    'astro-ph': 0,
    'cond-mat': 1,
    'gr-qc':    3,
    'hep-ex':   2,
    'hep-lat':  2,
    'hep-ph':   2,
    'hep-th':   2,
    'math-ph':  3,
    'nlin':     3,
    'nucl-ex':  3,
    'nucl-th':  3,
    'physics':  3,
    'quant-ph': 3
};

var concepts = [], ccats = {};
if(process.argv.length > 2) { 
    concepts = fs.readFileSync(process.argv[2]).toString().split('\n');
}
if(concepts[concepts.length - 1] == []) { concepts.pop() };
for(var i = 0; i < concepts.length; i++) {
    ccats[concepts[i]] = new Array(n_index);
    for(var j = 0; j < n_index; j++) { ccats[concepts[i]][j] = 0; }
}
    
var cat, name;
for(var a in data['articles']) {
    cat = data['articles'][a]['primary_category'];
    cat = cat.split('.')[0];
    for(var c in data['articles'][a]['concepts']) {
        name = data['concepts'][c]['name'];
        if(name in ccats) {
            ccats[name][catIndex[cat]]++;
        }
    }
}

for(var c in concepts) {
    cat = ccats[concepts[c]];
    console.log(cat.indexOf(Math.max.apply(null, cat)));
}
