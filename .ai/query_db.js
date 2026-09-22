const { DatabaseSync } = require('node:sqlite');
const db = new DatabaseSync('class_index.db');

const classes = db.prepare(`
    SELECT dex_file, class_name 
    FROM classes 
    WHERE class_name IN (
        'com.vega.edit.dock.TopLevelDockProvider',
        'com.vega.edit.video.view.dock.MainVideoDockProvider',
        'com.vega.edit.video.view.dock2.BaseMainVideoDockProvider',
        'com.vega.audio.view.dock.AudioDockProvider',
        'com.vega.libsticker.caption.view.dock.CaptionDockProvider',
        'com.vega.edit.videoeffect.view.dock.GlobalVideoEffectDockProvider'
    )
`).all();
console.log(classes);
