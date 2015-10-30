var d = require('../data/phys2013.json');
for(i in d['articles']){
    if(d['articles'][i]['authors'] != undefined){
    if(d['articles'][i]['authors'].indexOf('Giudice_G')>=0)
        console.log(d['articles'][i]['title']);
    }}
