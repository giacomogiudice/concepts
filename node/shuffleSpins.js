'use strict';

var fs = require('fs');
var rl = require('readline');

var spins;
var N_concepts = 0, N_articles = 0;
var filename;

if(process.argv.length === 4) {
    N_concepts = process.argv[2];
    filename = process.argv[3];
}
var freq = new Array(N_concepts);
for(var i = 0; i < N_concepts; i++) { freq[i] = 0; }

rl.createInterface({
    input: fs.createReadStream(filename)
}).on('line',function(line) {
    spins = line.split(',').map(Number);
    for(var i in spins) {
        if(spins[i] < 0 || spins[i] >= N_concepts) {
            console.log("Error: spin " + i + " : " + spins[i]);
            process.exit(1);
        }
        freq[spins[i]]++;
    }
    N_articles++;
}).on('close',function() {
    freq = freq.map(function(val) { return val/N_articles; });

    for(var a = 0; a < N_articles; a++) {
        spins = [];
        for(var c = 0; c < N_concepts; c++) {
            if(Math.random() <= freq[c]) { spins.push(c); }
        }
        console.log(spins.join(','));
    }
});
