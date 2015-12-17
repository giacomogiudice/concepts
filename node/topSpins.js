'use strict';

var fs = require('fs');
var data = require('../data/phys2013.json');

console.log("Data loaded");

var clist, counts = [];

var n_concepts = 1000;
if(process.argv.length > 2) { n_concepts = process.argv[2]; } 

console.log('Creating concept list');
for(var a in data['articles']) {
	clist = data['articles'][a]['concepts'];
    for(var c in clist) {
        if (c in counts) { counts[c]++; }
        else { counts[c] = 1; }
    }
}

var sortable = [];
for (var c in counts) {
    sortable.push([c, counts[c]]);
}
sortable.sort(function(a,b){return b[1]-a[1]});
sortable = sortable.slice(0,n_concepts);
for(var i in sortable) {
    sortable[i] = sortable[i][0];
}
counts = [];

var spins;
var iter = 0;
var index;

console.log("Creating spin matrix...");
var fstream = fs.createWriteStream('../data/topspins.csv');
for(var a in data['articles']) {
	iter++;
	spins = [];
	clist = data['articles'][a]['concepts'];
	for(var c in clist) {
		index = sortable.indexOf(c);
		if(index !== -1) { 
            spins.push(index);
		}
	}
	fstream.write(spins.join(',') + "\n");
	if (iter % 10000 === 0) {console.log("    " + iter + " articles scanned" ); }
}
console.log(sortable.length + " concepts found.");
console.log(iter + " articles scanned");
fstream.end();

console.log("Writing concept list");
fstream = fs.createWriteStream('../data/topconcepts.csv');
fstream.write(sortable.map(function(val,i,array) {
    return data['concepts'][val]['name'];
}).join('\n'));
fstream.end();

