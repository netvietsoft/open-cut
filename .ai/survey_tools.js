const fs = require('fs');
const content = fs.readFileSync('apps/android/app/src/main/java/com/nextai/opencut/presentation/MainActivity.java', 'utf8');

console.log('=== DETAILED VIDEO EDITING AUDIT OF OPENCUT ===');

// Match all methods
const methodRegex = /(?:public|private|protected)\s+[\w<>[\]]+\s+(\w+)\s*\([^)]*\)\s*\{/g;
let m;
const methods = [];
while ((m = methodRegex.exec(content)) !== null) {
    methods.push(m[1]);
}
console.log('Total methods in MainActivity:', methods.length);

const videoMethods = methods.filter(name => 
    /video|timeline|clip|editor|drawer|dialog|effect|audio|track|crop|rotate|flip|filter|speed|volume|split|mask|freeze|reverse|ruler/i.test(name)
);
console.log('Video-related methods (' + videoMethods.length + '):', videoMethods);

// Check Effects in EffectRegistry
const effectContent = fs.readFileSync('apps/android/app/src/main/java/com/nextai/opencut/engine/EffectRegistry.java', 'utf8');
console.log('\n=== EFFECT REGISTRY SURVEY ===');
const catRegex = /Category\s+\d+:\s+([^\n\r]+)/g;
let c;
const categories = [];
while ((c = catRegex.exec(effectContent)) !== null) {
    categories.push(c[1]);
}
console.log('Effect Categories (' + categories.length + '):', categories);

const effectItems = [];
const itemRegex = /new\s+EffectItem\s*\(\s*"([^"]+)"\s*,\s*"([^"]+)"\s*,\s*"([^"]+)"/g;
let it;
while ((it = itemRegex.exec(effectContent)) !== null) {
    effectItems.push({ id: it[1], name: it[2], category: it[3] });
}
console.log('Total EffectItems registered:', effectItems.length);
