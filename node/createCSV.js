'use strict';

var fs = require('fs');
var data = require('../data/phys2013.json');
console.log("Data loaded");

var concepts = [];
var clist, spins;
var iter = 0;
var index;

console.log("Creating concept list and spin matrix...");
var fstream = fs.createWriteStream('../data/spins.csv');
for(var a in data['articles']) {
	iter++;
	spins = [];
	clist = data['articles'][a]['concepts'];
	for(var c in clist) {
		index = concepts.indexOf(c);
		if(index === -1) { 
			index = concepts.length;
			concepts.push(c);
		}
		spins.push(index);
	}
	fstream.write(spins.join(',') + "\n");
	if (iter % 10000 === 0) {console.log("    " + iter + " articles scanned" ); }
}
console.log(concepts.length + " concepts found.");
console.log(iter + " articles scanned");
fstream.end();

console.log("Creating concept list");
fstream = fs.createWriteStream('../data/concepts.csv');
fstream.write(concepts.map(function(val,i,array) {
	return data['concepts'][val]['name'];
}).join('\n'));
fstream.end();

