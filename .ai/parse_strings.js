const fs = require('fs');
const enContent = fs.readFileSync('apktool-res/res/values/strings.xml', 'utf8');

const regex = /<string\s+name="([^"]+)">([^<]+)<\/string>/g;
let m;
const toolTerms = [
    // Clip Editing
    'Split', 'Speed', 'Volume', 'Animation', 'Delete', 'Cutout', 'Camera tracking', 
    'Volume', 'Transform', 'Overlay', 'Basic', 'Filters', 'Adjust', 'Retouch', 
    'Mask', 'Duplicate', 'Replace', 'Extract audio', 'Rotate', 'Mirror', 'Crop',
    'Reverse', 'Freeze', 'Motion blur', 'Opacity', 'Stabilize', 'Reduce noise',
    // Speed features
    'Normal', 'Curve', 'Montage', 'Hero', 'Bullet', 'Jump cut', 'Flash in', 'Flash out',
    'Make it smoother', 'Optical flow', 'Faster process',
    // Audio features
    'Sounds', 'Brand music', 'Copyright', 'Effects', 'Extract', 'Record', 'Auto beats',
    'Beats', 'Add beat', 'Voice effects', 'Voice filters', 'Voice characters', 'Speech to song',
    'Vocal isolation', 'Keep vocals', 'Remove vocals', 'Enhance voice', 'Audio balance',
    // Text features
    'Add text', 'Text templates', 'Auto captions', 'Auto lyrics', 'Draw', 'Stickers',
    'Text to speech', 'Captions', 'Bilingual captions', 'Identified language', 'Animation',
    // Effects
    'Video effects', 'Body effects', 'Photo effects', 'AI effects',
    // Keyframe & Canvas
    'Keyframe', 'Add keyframe', 'Color', 'Background', 'Blur', 'Brand',
    // Transitions
    'Transitions', 'Dissolve', 'Overlay', 'Camera', 'Slide', 'Light effect', 'Glitch', 'Distortion', 'Social', 'Split',
    // Adjustments
    'Brightness', 'Contrast', 'Saturation', 'Exposure', 'Sharpen', 'HSL', 'Curves', 
    'Highlight', 'Shadow', 'Temp', 'Hue', 'Fade', 'Vignette', 'Grain',
    // Ratio
    'Fit', '9:16', '16:9', '1:1', '4:3', '3:4', '2:3', '5.8:1', '2.35:1',
    // Cutout / Matting
    'Chroma key', 'Auto cutout', 'Customized cutout', 'Cutout stroke',
    // Smart AI features
    'Auto velocity', 'Relight', 'AI movement', 'Motion blur', 'Smart sharpness',
    'Super resolution', 'Camera shake', 'Remove flickering'
];

const found = {};
while ((m = regex.exec(enContent)) !== null) {
    const key = m[1];
    const val = m[2].trim();
    for (const term of toolTerms) {
        if (val.toLowerCase() === term.toLowerCase()) {
            if (!found[term]) found[term] = [];
            found[term].push({ key, val });
        }
    }
}

console.log('=== EXACT MATCHES FOUND IN CAPCUT APK STRINGS ===');
console.log('Matched terms count:', Object.keys(found).length, 'out of', toolTerms.length);
for (const term in found) {
    console.log(`- ${term}: ${found[term].map(x => x.key).join(', ')}`);
}

const missing = toolTerms.filter(t => !found[t]);
console.log('\nTerms not found as exact string:', missing);
