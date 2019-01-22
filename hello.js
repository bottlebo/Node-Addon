const addon = require('./build/Release/hello');
const vcount = 10000000;
let a = [];
console.time('JS fill')
for(let i=0; i<vcount; i++){
  a[i] = -i;
}
console.timeEnd('JS fill')
console.time('CPP fill');
addon.fill(a);
console.timeEnd('CPP fill')

console.log(a[10])