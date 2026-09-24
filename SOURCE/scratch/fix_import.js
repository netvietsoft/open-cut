const fs = require('fs');
const path = 'apps/android/app/src/main/java/com/nextai/opencut/presentation/MainActivity.java';
let code = fs.readFileSync(path, 'utf8');

const idxStart = code.indexOf('private void openMediaPicker(boolean forPhotoOnly) {');
const idxEnd = code.indexOf('} else if (isAddingPip) {');

console.log('idxStart:', idxStart, 'idxEnd:', idxEnd);

const fixedSection = `    private void openMediaPicker(boolean forPhotoOnly) {
        this.isPickingForPhotoEditor = forPhotoOnly;
        selectedMediaItems.clear();
        for (MediaItem mi : allMediaItems) {
            mi.isSelected = false;
        }

        if (tvPickerTitle != null) {
            if (isAddingToTimeline) {
                tvPickerTitle.setText("Th\u00EAm Clip N\u1ED1i Ti\u1EBFp \u25BE");
            } else if (isReplacingClip) {
                tvPickerTitle.setText("Thay Th\u1EBF Clip \u25BE");
            } else if (forPhotoOnly) {
                tvPickerTitle.setText("Ch\u1ECDn \u1EA2nh Bi\u00EAn T\u1EADp \u25BE");
            } else {
                tvPickerTitle.setText("D\u1EF1 \u00C1n M\u1EDBi \u25BE");
            }
        }

        renderMediaPickerGrid();

        rootFrame.removeAllViews();
        rootFrame.addView(mediaPickerView);
    }

    private void importSelectedMediaToProject() {
        if (selectedMediaItems.isEmpty()) return;

        if (isPickingForPhotoEditor) {
            MediaItem chosenPhoto = selectedMediaItems.get(0);
            openPhotoEditorWithMedia(chosenPhoto);
            return;
        }

        if (isReplacingClip) {
            // Replace Clip while preserving all timeline attributes / \u0110\u1ED5i clip gi\u1EEF nguy\u00EAn thu\u1ED9c t\u00EDnh
            if (!activeProjectClips.isEmpty() && selectedClipIndex < activeProjectClips.size()) {
                MediaItem rep = selectedMediaItems.get(0);
                MediaItem cur = activeProjectClips.get(selectedClipIndex);
                cur.id = rep.id;
                cur.title = rep.title;
                cur.uri = rep.uri;
                cur.isVideo = rep.isVideo;
                cur.duration = rep.duration;
                cur.durationSeconds = rep.durationSeconds;
                cur.colorBg = rep.colorBg;
                cur.icon = rep.icon;
                cur.thumbnailBitmap = rep.thumbnailBitmap;
                isReplacingClip = false;
                renderTimelineFilmstrip();
                updatePlayerPreview();
                rootFrame.removeAllViews();
                showRibbonLevel(ribbonMainMenu);
                rootFrame.addView(editorView);
                Toast.makeText(this, "\uD83D\uDD04 \u0110\u00E3 thay th\u1EBF clip th\u00E0nh c\u00F4ng (B\u1EA3o l\u01B0u to\u00E0n b\u1ED9 thu\u1ED9c t\u00EDnh)!", Toast.LENGTH_SHORT).show();
            }
            return;
        `;

code = code.substring(0, idxStart) + fixedSection + code.substring(idxEnd);
fs.writeFileSync(path, code, 'utf8');
console.log('Restored openMediaPicker and importSelectedMediaToProject successfully!');
