'use strict';

var fs = require('fs');
var data = require('../data/phys2013.json');

var conceptID = Object.keys(data['concepts']);
var fstream = fs.createWriteStream('../data/conceptList.csv');

for(var i in conceptID) {
    fstream.write(data['concepts'][conceptID[i]]['name'] + '\n');
}
fstream.end();

