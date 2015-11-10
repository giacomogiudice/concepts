'use strict';

var fs = require('fs');

var N_concepts, N_articles;

if(process.argv.length === 4) {
	 N_concepts = process.argv[2];
	 N_articles = process.argv[3];
} 
var clist = [];
for(var a = 0; a < N_articles; a++) {
	clist = [];
	for(var c = 0; c < N_concepts; c++) {
		if(Math.random() < 0.5) { clist.push(c); }
	}
	console.log(clist.join(','));
}