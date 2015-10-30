'use strict';

var fs = require('fs');
var data = require('../data/phys2013.json');

var conceptID = Object.keys(data['concepts']);
var spin;
var fstream = fs.createWriteStream('../data/spinmatrix.csv');

var iter = 0;
console.log("Data loaded. Creating spin matrix...");
for(var a in data['articles']) {
    spin = [];
    iter++;
    for(var i in conceptID) {
        if(i in data['articles'][a]['concepts']) { spin.push(i); }
    }
    fstream.write(spin.join(',') + "\n");
    if (iter % 1000 === 0) {console.log(iter + " articles scanned" ); }
    iter++;
}
fstream.end();
console.log("Completed! " + iter + " articles scanned");

