'use strict';

var fs = require('fs');
var rl = require('readline');

var spins = [];
var n = 13174;
var freqs = [];
for(var i=0; i<n; i++) {
    freqs[i] = new Array(i+1); 
    for(var j=0; j<=i; j++) {
        freqs[i][j] = 0;
    }
}

rl.createInterface({
    input: fs.createReadStream('../data/spinmatrix.csv')
}).on('line',function(line) {
    spins = line.split(',').map(Number);
    for(var i in spins) {
        if(spins[i] < 0 || spins[i] >= n) {
            console.log("Error: spin " + i + " : " + spins[i]);
            process.exit(1);
        }
        for(var j=0; j<=i; j++) {
            freqs[spins[i]][spins[j]]++;
        }
    }
}).on('close',function() {
    var fstream = fs.createWriteStream('../data/freqmatrix.csv');
    for(var i in freqs) {
        if(freqs[i][i] === 0) { console.log(i); }
        fstream.write(freqs[i].map(function(val) { return val/n}).join(',') + '\n');
    }
    fstream.end();
});
