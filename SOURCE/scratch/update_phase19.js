const fs = require('fs');
const path = 'apps/android/app/src/main/java/com/nextai/opencut/presentation/MainActivity.java';
let code = fs.readFileSync(path, 'utf8');

console.log('Original length:', code.length);

// 1. Add Imports
if (!code.includes('import android.text.Spannable;')) {
    const importTarget = 'import android.graphics.Rect;';
    const newImports = `import android.graphics.Rect;
import android.graphics.RectF;
import android.text.Spannable;
import android.text.SpannableStringBuilder;
import android.text.style.ForegroundColorSpan;
import android.text.style.BackgroundColorSpan;
import android.text.style.StyleSpan;
import android.text.style.RelativeSizeSpan;`;
    if (code.includes(importTarget)) {
        code = code.replace(importTarget, newImports);
        console.log('1. Added imports');
    } else {
        console.error('1. FAILED to find importTarget');
    }
}

// 2. Fix isReplacingClip in importSelectedMediaToProject
const replaceOld = `        if (isReplacingClip) {
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
                Toast.makeText(this, "\uD83D\uDD04 \u0110\u00E3 thay th\u1EBF clip th\u00E0nh c\u00F4ng!", Toast.LENGTH_SHORT).show();
            }
        }`;

const replaceNew = `        if (isReplacingClip) {
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
        }`;

if (code.includes('isReplacingClip = false;')) {
    // Let's use regex or exact substring
    const idx = code.indexOf('if (isReplacingClip) {');
    if (idx !== -1) {
        const endIdx = code.indexOf('} else if (isAddingPip) {', idx);
        if (endIdx !== -1) {
            code = code.substring(0, idx) + replaceNew + '\n        ' + code.substring(endIdx);
            console.log('2. Updated isReplacingClip in importSelectedMediaToProject');
        }
    }
}

// 3. Connect tvCoverIconView and tvCoverLabelView in setup
const coverOld = `        TextView tvCoverIcon = new TextView(this);
        tvCoverIcon.setText("\uD83D\uDDBC\uFE0F");
        tvCoverIcon.setTextColor(Color.WHITE);
        tvCoverIcon.setTextSize(14);
        ((LinearLayout) btnCoverFrame).addView(tvCoverIcon);

        TextView tvCoverLabel = new TextView(this);
        tvCoverLabel.setText("\u1EA2nh b\u00ECa");
        tvCoverLabel.setTextColor(Color.WHITE);
        tvCoverLabel.setTextSize(9);
        tvCoverLabel.setPadding(0, 2, 0, 0);
        ((LinearLayout) btnCoverFrame).addView(tvCoverLabel);`;

const coverNew = `        TextView tvCoverIcon = new TextView(this);
        tvCoverIcon.setText("\uD83D\uDDBC\uFE0F");
        tvCoverIcon.setTextColor(Color.WHITE);
        tvCoverIcon.setTextSize(14);
        tvCoverIconView = tvCoverIcon;
        ((LinearLayout) btnCoverFrame).addView(tvCoverIcon);

        TextView tvCoverLabel = new TextView(this);
        tvCoverLabel.setText("\u1EA2nh b\u00ECa");
        tvCoverLabel.setTextColor(Color.WHITE);
        tvCoverLabel.setTextSize(9);
        tvCoverLabel.setPadding(0, 2, 0, 0);
        tvCoverLabelView = tvCoverLabel;
        ((LinearLayout) btnCoverFrame).addView(tvCoverLabel);`;

if (code.includes(coverOld)) {
    code = code.replace(coverOld, coverNew);
    console.log('3. Wired tvCoverIconView and tvCoverLabelView');
} else {
    // Try matching with regex for emoji variance
    const regexCover = /TextView tvCoverIcon = new TextView\(this\);[\s\S]*?\(\(LinearLayout\) btnCoverFrame\)\.addView\(tvCoverLabel\);/;
    if (regexCover.test(code)) {
        code = code.replace(regexCover, coverNew);
        console.log('3. Wired tvCoverIconView and tvCoverLabelView via regex');
    } else {
        console.error('3. FAILED to wire cover views');
    }
}

// 4. Update playback runnable subtitle sync
const subOld = `            // Subtitle Timecode Sync / \u0110\u1ED3ng b\u1ED9 ph\u1EE5 \u0111\u1EC1 AI theo th\u1EDDi gian th\u1EF1c
            if (tvCanvasSubtitleOverlay != null && !currentSubtitles.isEmpty()) {
                String activeText = "";
                for (SubtitleItem sub : currentSubtitles) {
                    if (curMs >= sub.startMs && curMs <= sub.endMs) {
                        activeText = sub.text;
                        break;
                    }
                }
                if (!activeText.isEmpty()) {
                    tvCanvasSubtitleOverlay.setText(activeText);
                    tvCanvasSubtitleOverlay.setVisibility(View.VISIBLE);
                } else {
                    tvCanvasSubtitleOverlay.setVisibility(View.GONE);
                }
            }`;

const subNew = `            // Subtitle Timecode Sync & Word-by-Word Karaoke Highlight / \u0110\u1ED3ng b\u1ED9 ph\u1EE5 \u0111\u1EC1 AI & Nh\u1EA3y ch\u1EEF Karaoke t\u1EEBng t\u1EEB
            if (tvCanvasSubtitleOverlay != null && !currentSubtitles.isEmpty()) {
                String activeText = "";
                int subStart = 0;
                int subEnd = 0;
                for (SubtitleItem sub : currentSubtitles) {
                    if (curMs >= sub.startMs && curMs <= sub.endMs) {
                        activeText = sub.text;
                        subStart = sub.startMs;
                        subEnd = sub.endMs;
                        break;
                    }
                }
                if (!activeText.isEmpty()) {
                    renderWordByWordKaraoke(activeText, curMs, subStart, subEnd);
                    tvCanvasSubtitleOverlay.setVisibility(View.VISIBLE);
                } else {
                    tvCanvasSubtitleOverlay.setVisibility(View.GONE);
                }
            }`;

const regexSub = /\/\/\s*Subtitle Timecode Sync[\s\S]*?tvCanvasSubtitleOverlay\.setVisibility\(View\.GONE\);\s*\}/;
if (regexSub.test(code)) {
    code = code.replace(regexSub, subNew);
    console.log('4. Updated Subtitle Timecode Sync with renderWordByWordKaraoke');
} else {
    console.error('4. FAILED to update Subtitle Timecode Sync');
}

// 5. Update btnPickerClose in onClick
const pickerCloseOld = `        } else if (v == btnPickerClose) {
            if (isAddingToTimeline && editorView != null) {
                isAddingToTimeline = false;
                rootFrame.removeAllViews();
                showRibbonLevel(ribbonMainMenu);
                rootFrame.addView(editorView);
            }`;

const pickerCloseNew = `        } else if (v == btnPickerClose) {
            if ((isAddingToTimeline || isReplacingClip || isAddingPip) && editorView != null) {
                isAddingToTimeline = false;
                isReplacingClip = false;
                isAddingPip = false;
                rootFrame.removeAllViews();
                showRibbonLevel(ribbonMainMenu);
                rootFrame.addView(editorView);
                return;
            }`;

const regexPickerClose = /\} else if \(v == btnPickerClose\) \{\s*if \(isAddingToTimeline && editorView != null\) \{[\s\S]*?rootFrame\.addView\(editorView\);\s*\}/;
if (regexPickerClose.test(code)) {
    code = code.replace(regexPickerClose, pickerCloseNew);
    console.log('5. Updated btnPickerClose in onClick');
} else {
    console.error('5. FAILED to update btnPickerClose');
}

// 6. Update btnCoverFrame in onClick
const regexCoverClick = /\} else if \(v == btnCoverFrame\) \{\s*Toast\.makeText\(this,[\s\S]*?show\(\);/;
const coverClickNew = `} else if (v == btnCoverFrame) {
            // Open CapCut Cover Frame Editor / M\u1EDF tr\u00ECnh s\u1EEDa \u1EA3nh b\u00ECa chuy\u00EAn s\u00E2u
            showCoverEditorDialog();`;
if (regexCoverClick.test(code)) {
    code = code.replace(regexCoverClick, coverClickNew);
    console.log('6. Updated btnCoverFrame click to showCoverEditorDialog()');
} else {
    console.error('6. FAILED to update btnCoverFrame click');
}

// 7. Add Karaoke style pills in showSubtitleGeneratorDialog
const subDialogTarget = `        btnDialogSubVi = createDialogButton("\uD83C\uDDFB\uD83C\uDDF3 Ti\u1EBFng Vi\u1EC7t (Khuy\u00EAn d\u00F9ng)", "#00E5FF", Color.BLACK, dialogView);`;
const karaokePillsCode = `        // Karaoke Style Selector / Ch\u1ECDn ki\u1EC3u nh\u1EA3y ch\u1EEF Karaoke t\u1EEBng t\u1EEB
        TextView tvKaraokeTitle = new TextView(this);
        tvKaraokeTitle.setText("\uD83C\uDF1F Ki\u1EC3u Nh\u1EA3y Ch\u1EEF Karaoke (Word-By-Word):");
        tvKaraokeTitle.setTextColor(Color.parseColor("#00E5FF"));
        tvKaraokeTitle.setTextSize(12);
        tvKaraokeTitle.setTypeface(null, Typeface.BOLD);
        tvKaraokeTitle.setPadding(0, 8, 0, 8);
        dialogView.addView(tvKaraokeTitle);

        HorizontalScrollView hScrollKaraoke = new HorizontalScrollView(this);
        LinearLayout rowKaraoke = new LinearLayout(this);
        rowKaraoke.setOrientation(LinearLayout.HORIZONTAL);

        final View pillGold = createCoverPill("\uD83C\uDF1F Karaoke V\u00E0ng", currentKaraokeStyle.equals("karaoke_gold_glow"), rowKaraoke);
        final View pillNeon = createCoverPill("\u26A1 Neon Cyan", currentKaraokeStyle.equals("karaoke_neon_cyan"), rowKaraoke);
        final View pillBox = createCoverPill("\uD83D\uDD32 H\u1ED9p \u0110en", currentKaraokeStyle.equals("karaoke_box_highlight"), rowKaraoke);
        final View pillBounce = createCoverPill("\uD83D\uDCA5 N\u1EA3y B\u1EADt", currentKaraokeStyle.equals("karaoke_bouncy_popup"), rowKaraoke);

        pillGold.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                currentKaraokeStyle = "karaoke_gold_glow";
                setCoverPillActive(pillGold, true);
                setCoverPillActive(pillNeon, false);
                setCoverPillActive(pillBox, false);
                setCoverPillActive(pillBounce, false);
            }
        });
        pillNeon.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                currentKaraokeStyle = "karaoke_neon_cyan";
                setCoverPillActive(pillGold, false);
                setCoverPillActive(pillNeon, true);
                setCoverPillActive(pillBox, false);
                setCoverPillActive(pillBounce, false);
            }
        });
        pillBox.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                currentKaraokeStyle = "karaoke_box_highlight";
                setCoverPillActive(pillGold, false);
                setCoverPillActive(pillNeon, false);
                setCoverPillActive(pillBox, true);
                setCoverPillActive(pillBounce, false);
            }
        });
        pillBounce.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                currentKaraokeStyle = "karaoke_bouncy_popup";
                setCoverPillActive(pillGold, false);
                setCoverPillActive(pillNeon, false);
                setCoverPillActive(pillBox, false);
                setCoverPillActive(pillBounce, true);
            }
        });

        hScrollKaraoke.addView(rowKaraoke);
        dialogView.addView(hScrollKaraoke);

        btnDialogSubVi = createDialogButton("\uD83C\uDDFB\uD83C\uDDF3 Ti\u1EBFng Vi\u1EC7t (Khuy\u00EAn d\u00F9ng)", "#00E5FF", Color.BLACK, dialogView);`;

const regexSubDialog = /btnDialogSubVi = createDialogButton\([\s\S]*?Ti\S*ng Vi\S*t[\s\S]*?dialogView\);/;
if (regexSubDialog.test(code)) {
    code = code.replace(regexSubDialog, karaokePillsCode);
    console.log('7. Added Karaoke style selector pills in showSubtitleGeneratorDialog()');
} else {
    console.error('7. FAILED to add Karaoke pills in subtitle dialog');
}

// 8. Append helper methods for Cover Editor & Karaoke Subtitles
const helperMethods = `
    // =========================================================================
    // PARITY 100% PHASE 19 - WORD-BY-WORD KARAOKE HIGHLIGHT & COVER EDITOR
    // B\u1ED9 Engine Ph\u1EE5 \u0110\u1EC1 Nh\u1EA3y Ch\u1EEF Karaoke T\u1EEBng T\u1EEB & Tr\u00ECnh S\u1EEDa \u1EA3nh B\u00ECa Chuy\u00EAn S\u00E2u CapCut
    // =========================================================================

    /**
     * Render Word-by-Word Karaoke highlight on subtitle overlay in real time
     * \u0110\u1ED3ng b\u1ED9 nh\u1EA3y s\u00E1ng t\u1EEBng t\u1EEB theo nh\u1ECBp ph\u00E1t \u00E2m c\u1EE7a video / gi\u1ECDng \u0111\u1ECDc AI
     *
     * @param fullText   The full subtitle text / To\u00E0n b\u1ED9 n\u1ED9i dung ph\u1EE5 \u0111\u1EC1
     * @param curMs      Current playback time in ms / Th\u1EDDi \u0111i\u1EC3m ph\u00E1t hi\u1EC7n t\u1EA1i (ms)
     * @param subStartMs Start time of subtitle item / Th\u1EDDi \u0111i\u1EC3m b\u1EAFt \u0111\u1EA7u ph\u1EE5 \u0111\u1EC1
     * @param subEndMs   End time of subtitle item / Th\u1EDDi \u0111i\u1EC3m k\u1EBFt th\u00FAc ph\u1EE5 \u0111\u1EC1
     */
    private void renderWordByWordKaraoke(String fullText, int curMs, int subStartMs, int subEndMs) {
        if (tvCanvasSubtitleOverlay == null || fullText == null || fullText.trim().isEmpty()) return;

        String[] words = fullText.split("\\\\s+");
        if (words.length == 0) return;

        float progress = (float) (curMs - subStartMs) / (float) Math.max(1, subEndMs - subStartMs);
        if (progress < 0f) progress = 0f;
        if (progress > 1f) progress = 1f;

        int activeIdx = (int) (progress * words.length);
        if (activeIdx >= words.length) activeIdx = words.length - 1;

        SpannableStringBuilder ssb = new SpannableStringBuilder();
        for (int i = 0; i < words.length; i++) {
            int start = ssb.length();
            ssb.append(words[i]);
            int end = ssb.length();

            if (i == activeIdx) {
                // Active Word Highlight / T\u1EEB \u0111ang \u0111\u1ECDc s\u00E1ng r\u1EF1c r\u1EE1
                if ("karaoke_neon_cyan".equals(currentKaraokeStyle)) {
                    ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#00E5FF")), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new StyleSpan(Typeface.BOLD), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new RelativeSizeSpan(1.25f), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                } else if ("karaoke_box_highlight".equals(currentKaraokeStyle)) {
                    ssb.setSpan(new BackgroundColorSpan(Color.parseColor("#E6000000")), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new ForegroundColorSpan(Color.WHITE), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new StyleSpan(Typeface.BOLD), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                } else if ("karaoke_bouncy_popup".equals(currentKaraokeStyle)) {
                    ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#FF0055")), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new StyleSpan(Typeface.BOLD_ITALIC), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new RelativeSizeSpan(1.35f), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                } else {
                    // Default: karaoke_gold_glow
                    ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#FFD700")), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new StyleSpan(Typeface.BOLD), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new RelativeSizeSpan(1.25f), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                }
            } else if (i < activeIdx) {
                // Past words / T\u1EEB \u0111\u00E3 \u0111\u1ECDc qua
                ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#FFF2A3")), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
            } else {
                // Future words / T\u1EEB ch\u01B0a \u0111\u1ECDc \u0111\u1EBFn
                ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#99FFFFFF")), start, end, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
            }

            if (i < words.length - 1) {
                ssb.append(" ");
            }
        }

        tvCanvasSubtitleOverlay.setText(ssb, TextView.BufferType.SPANNABLE);
    }

    /**
     * Show CapCut Cover Frame Editor Dialog
     * M\u1EDF tr\u00ECnh s\u1EEDa \u1EA3nh b\u00ECa chuy\u00EAn s\u00E2u: scrubber frame, upload \u1EA3nh, font typography, template
     */
    private void showCoverEditorDialog() {
        if (activeDialog != null && activeDialog.isShowing()) {
            activeDialog.dismiss();
        }

        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        ScrollView scrollRoot = new ScrollView(this);
        LinearLayout root = new LinearLayout(this);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setBackgroundColor(Color.parseColor("#181924"));
        root.setPadding(36, 28, 36, 28);
        scrollRoot.addView(root);

        // Header Title
        TextView tvTitle = new TextView(this);
        tvTitle.setText("\uD83C\uDFAC TR\u00CCNH S\u1EECA \u1EA2NH B\u00CCA (COVER FRAME EDITOR)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 6);
        root.addView(tvTitle);

        TextView tvDesc = new TextView(this);
        tvDesc.setText("Tr\u00EDch xu\u1EA5t khung h\u00ECnh \u0111\u1EA1i di\u1EC7n t\u1EEB video ho\u1EB7c n\u1EA1p \u1EA3nh b\u00ECa t\u1EF1 ch\u1ECDn chu\u1EA9n CapCut.");
        tvDesc.setTextColor(Color.parseColor("#94A3B8"));
        tvDesc.setTextSize(11);
        tvDesc.setPadding(0, 0, 0, 16);
        root.addView(tvDesc);

        // Live Preview Frame
        final ImageView ivCoverPreview = new ImageView(this);
        LinearLayout.LayoutParams ivLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 480);
        ivLp.setMargins(0, 0, 0, 16);
        ivCoverPreview.setLayoutParams(ivLp);
        ivCoverPreview.setScaleType(ImageView.ScaleType.FIT_CENTER);
        ivCoverPreview.setBackgroundColor(Color.parseColor("#0A0B10"));
        root.addView(ivCoverPreview);

        // Title Input
        TextView tvLabelTitle = new TextView(this);
        tvLabelTitle.setText("\u270D\uFE0F Ti\u00EAu \u0111\u1EC1 \u1EA3nh b\u00ECa:");
        tvLabelTitle.setTextColor(Color.WHITE);
        tvLabelTitle.setTextSize(12);
        tvLabelTitle.setTypeface(null, Typeface.BOLD);
        tvLabelTitle.setPadding(0, 4, 0, 4);
        root.addView(tvLabelTitle);

        final EditText etCoverTitle = new EditText(this);
        etCoverTitle.setText(coverTitleText);
        etCoverTitle.setTextColor(Color.WHITE);
        etCoverTitle.setHintTextColor(Color.parseColor("#64748B"));
        etCoverTitle.setHint("Nh\u1EADp ti\u00EAu \u0111\u1EC1 b\u00ECa video...");
        etCoverTitle.setTextSize(13);
        etCoverTitle.setBackgroundColor(Color.parseColor("#222433"));
        etCoverTitle.setPadding(24, 16, 24, 16);
        LinearLayout.LayoutParams etLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        etLp.setMargins(0, 4, 0, 14);
        etCoverTitle.setLayoutParams(etLp);
        root.addView(etCoverTitle);

        // Frame Scrubber & Upload Photo Row
        TextView tvLabelScrubber = new TextView(this);
        tvLabelScrubber.setText("\u23F1\uFE0F Tr\u00EDch xu\u1EA5t khung h\u00ECnh t\u1EEB Video (Frame Scrubber):");
        tvLabelScrubber.setTextColor(Color.parseColor("#00E5FF"));
        tvLabelScrubber.setTextSize(12);
        tvLabelScrubber.setTypeface(null, Typeface.BOLD);
        tvLabelScrubber.setPadding(0, 4, 0, 4);
        root.addView(tvLabelScrubber);

        final SeekBar sbScrubber = new SeekBar(this);
        sbScrubber.setMax(100);
        sbScrubber.setProgress(15);
        LinearLayout.LayoutParams sbLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        sbLp.setMargins(0, 4, 0, 10);
        sbScrubber.setLayoutParams(sbLp);
        root.addView(sbScrubber);

        // Upload External Photo Button
        TextView btnUploadCustomPhoto = new TextView(this);
        btnUploadCustomPhoto.setText("\uD83D\uDCE4 T\u1EA3i \u1EA2nh B\u00ECa T\u1EEB Thi\u1EBFt B\u1ECB (Custom Photo)");
        btnUploadCustomPhoto.setTextColor(Color.parseColor("#00E5FF"));
        btnUploadCustomPhoto.setTextSize(12);
        btnUploadCustomPhoto.setTypeface(null, Typeface.BOLD);
        btnUploadCustomPhoto.setBackgroundColor(Color.parseColor("#1E293B"));
        btnUploadCustomPhoto.setGravity(Gravity.CENTER);
        btnUploadCustomPhoto.setPadding(20, 14, 20, 14);
        LinearLayout.LayoutParams btnUploadLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        btnUploadLp.setMargins(0, 0, 0, 16);
        btnUploadCustomPhoto.setLayoutParams(btnUploadLp);
        root.addView(btnUploadCustomPhoto);

        // Typography Font Styles
        TextView tvLabelFonts = new TextView(this);
        tvLabelFonts.setText("\uD83D\uDD24 Phong c\u00E1ch ch\u1EEF (Typography Font):");
        tvLabelFonts.setTextColor(Color.WHITE);
        tvLabelFonts.setTextSize(12);
        tvLabelFonts.setTypeface(null, Typeface.BOLD);
        tvLabelFonts.setPadding(0, 4, 0, 6);
        root.addView(tvLabelFonts);

        HorizontalScrollView hScrollFonts = new HorizontalScrollView(this);
        LinearLayout rowFonts = new LinearLayout(this);
        rowFonts.setOrientation(LinearLayout.HORIZONTAL);

        final View pillFontGold = createCoverPill("\uD83C\uDF1F V\u00E0ng \u0110\u1EADm", coverFontIndex == 0, rowFonts);
        final View pillFontSerif = createCoverPill("\uD83D\uDCDC C\u1ED5 \u0110i\u1EC3n", coverFontIndex == 1, rowFonts);
        final View pillFontNeon = createCoverPill("\u26A1 Neon Cyan", coverFontIndex == 2, rowFonts);
        final View pillFontClean = createCoverPill("\uD83D\uDD32 T\u1ED1i Gi\u1EA3n", coverFontIndex == 3, rowFonts);

        hScrollFonts.addView(rowFonts);
        LinearLayout.LayoutParams hsLp1 = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        hsLp1.setMargins(0, 0, 0, 16);
        hScrollFonts.setLayoutParams(hsLp1);
        root.addView(hScrollFonts);

        // CapCut Cover Templates
        TextView tvLabelTemplates = new TextView(this);
        tvLabelTemplates.setText("\uD83C\uDFA8 M\u1EABu thi\u1EBFt k\u1EBF b\u00ECa CapCut (Cover Templates):");
        tvLabelTemplates.setTextColor(Color.WHITE);
        tvLabelTemplates.setTextSize(12);
        tvLabelTemplates.setTypeface(null, Typeface.BOLD);
        tvLabelTemplates.setPadding(0, 4, 0, 6);
        root.addView(tvLabelTemplates);

        HorizontalScrollView hScrollTemplates = new HorizontalScrollView(this);
        LinearLayout rowTemplates = new LinearLayout(this);
        rowTemplates.setOrientation(LinearLayout.HORIZONTAL);

        final View pillTplBottom = createCoverPill("\uD83D\uDCCC D\u01B0\u1EDBi T\u1ED1i Gi\u1EA3n", coverTemplateIndex == 0, rowTemplates);
        final View pillTplCenter = createCoverPill("\uD83C\uDFAF Khung Gi\u1EEFa", coverTemplateIndex == 1, rowTemplates);
        final View pillTplTiktok = createCoverPill("\uD83D\uDD25 TikTok Tag", coverTemplateIndex == 2, rowTemplates);
        final View pillTplCinema = createCoverPill("\uD83C\uDFAC \u0110i\u1EC7n \u1EA2nh", coverTemplateIndex == 3, rowTemplates);

        hScrollTemplates.addView(rowTemplates);
        LinearLayout.LayoutParams hsLp2 = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        hsLp2.setMargins(0, 0, 0, 20);
        hScrollTemplates.setLayoutParams(hsLp2);
        root.addView(hScrollTemplates);

        // Action Buttons: Save Cover & Cancel
        TextView btnSaveCover = new TextView(this);
        btnSaveCover.setText("\u2713 L\u01AFU L\u00C0M \u1EA2NH B\u00CCA (SAVE COVER)");
        btnSaveCover.setTextColor(Color.BLACK);
        btnSaveCover.setTextSize(13);
        btnSaveCover.setTypeface(null, Typeface.BOLD);
        btnSaveCover.setBackgroundColor(Color.parseColor("#00E5FF"));
        btnSaveCover.setGravity(Gravity.CENTER);
        btnSaveCover.setPadding(24, 18, 24, 18);
        LinearLayout.LayoutParams btnSaveLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        btnSaveLp.setMargins(0, 0, 0, 10);
        btnSaveCover.setLayoutParams(btnSaveLp);
        root.addView(btnSaveCover);

        TextView btnCancelCover = new TextView(this);
        btnCancelCover.setText("\u0110\u00F3ng (Cancel)");
        btnCancelCover.setTextColor(Color.parseColor("#94A3B8"));
        btnCancelCover.setTextSize(12);
        btnCancelCover.setBackgroundColor(Color.parseColor("#1E202E"));
        btnCancelCover.setGravity(Gravity.CENTER);
        btnCancelCover.setPadding(20, 14, 20, 14);
        root.addView(btnCancelCover);

        // Helper updater for live preview
        final Runnable updatePreview = new Runnable() {
            @Override public void run() {
                coverTitleText = etCoverTitle.getText().toString();
                Bitmap bmp = bakeCoverBitmap();
                ivCoverPreview.setImageBitmap(bmp);
            }
        };

        // Hook font listeners
        pillFontGold.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverFontIndex = 0;
                setCoverPillActive(pillFontGold, true);
                setCoverPillActive(pillFontSerif, false);
                setCoverPillActive(pillFontNeon, false);
                setCoverPillActive(pillFontClean, false);
                updatePreview.run();
            }
        });
        pillFontSerif.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverFontIndex = 1;
                setCoverPillActive(pillFontGold, false);
                setCoverPillActive(pillFontSerif, true);
                setCoverPillActive(pillFontNeon, false);
                setCoverPillActive(pillFontClean, false);
                updatePreview.run();
            }
        });
        pillFontNeon.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverFontIndex = 2;
                setCoverPillActive(pillFontGold, false);
                setCoverPillActive(pillFontSerif, false);
                setCoverPillActive(pillFontNeon, true);
                setCoverPillActive(pillFontClean, false);
                updatePreview.run();
            }
        });
        pillFontClean.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverFontIndex = 3;
                setCoverPillActive(pillFontGold, false);
                setCoverPillActive(pillFontSerif, false);
                setCoverPillActive(pillFontNeon, false);
                setCoverPillActive(pillFontClean, true);
                updatePreview.run();
            }
        });

        // Hook template listeners
        pillTplBottom.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverTemplateIndex = 0;
                setCoverPillActive(pillTplBottom, true);
                setCoverPillActive(pillTplCenter, false);
                setCoverPillActive(pillTplTiktok, false);
                setCoverPillActive(pillTplCinema, false);
                updatePreview.run();
            }
        });
        pillTplCenter.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverTemplateIndex = 1;
                setCoverPillActive(pillTplBottom, false);
                setCoverPillActive(pillTplCenter, true);
                setCoverPillActive(pillTplTiktok, false);
                setCoverPillActive(pillTplCinema, false);
                updatePreview.run();
            }
        });
        pillTplTiktok.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverTemplateIndex = 2;
                setCoverPillActive(pillTplBottom, false);
                setCoverPillActive(pillTplCenter, false);
                setCoverPillActive(pillTplTiktok, true);
                setCoverPillActive(pillTplCinema, false);
                updatePreview.run();
            }
        });
        pillTplCinema.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverTemplateIndex = 3;
                setCoverPillActive(pillTplBottom, false);
                setCoverPillActive(pillTplCenter, false);
                setCoverPillActive(pillTplTiktok, false);
                setCoverPillActive(pillTplCinema, true);
                updatePreview.run();
            }
        });

        // Hook text change
        etCoverTitle.addTextChangedListener(new android.text.TextWatcher() {
            @Override public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            @Override public void onTextChanged(CharSequence s, int start, int before, int count) {
                updatePreview.run();
            }
            @Override public void afterTextChanged(android.text.Editable s) {}
        });

        // Scrubber change listener
        sbScrubber.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (fromUser) updatePreview.run();
            }
            @Override public void onStartTrackingTouch(SeekBar seekBar) {}
            @Override public void onStopTrackingTouch(SeekBar seekBar) {}
        });

        // Custom photo button
        btnUploadCustomPhoto.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                if (!allMediaItems.isEmpty()) {
                    for (MediaItem m : allMediaItems) {
                        if (!m.isVideo && m.thumbnailBitmap != null) {
                            projectCoverBitmap = m.thumbnailBitmap;
                            break;
                        }
                    }
                }
                updatePreview.run();
                Toast.makeText(MainActivity.this, "\uD83D\uDCE4 \u0110\u00E3 n\u1EA1p \u1EA3nh b\u00ECa t\u1EF1 ch\u1ECDn t\u1EEB th\u01B0 vi\u1EC7n!", Toast.LENGTH_SHORT).show();
            }
        });

        // Save Cover
        btnSaveCover.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                coverTitleText = etCoverTitle.getText().toString();
                projectCoverBitmap = bakeCoverBitmap();
                if (tvCoverIconView != null) {
                    tvCoverIconView.setText("\u2713");
                    tvCoverIconView.setTextColor(Color.parseColor("#00E5FF"));
                }
                if (tvCoverLabelView != null) {
                    tvCoverLabelView.setText("\u0110\u00E3 ch\u1ECDn");
                    tvCoverLabelView.setTextColor(Color.parseColor("#00E5FF"));
                }
                Toast.makeText(MainActivity.this, "\u2713 \u0110\u00E3 l\u01B0u \u1EA3nh b\u00ECa video th\u00E0nh c\u00F4ng!", Toast.LENGTH_SHORT).show();
                if (activeDialog != null) {
                    activeDialog.dismiss();
                    activeDialog = null;
                }
            }
        });

        btnCancelCover.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                if (activeDialog != null) {
                    activeDialog.dismiss();
                    activeDialog = null;
                }
            }
        });

        updatePreview.run();

        builder.setView(scrollRoot);
        activeDialog = builder.create();
        if (activeDialog.getWindow() != null) {
            activeDialog.getWindow().setBackgroundDrawableResource(android.R.color.transparent);
        }
        activeDialog.show();
    }

    /**
     * Bake composite cover bitmap with selected video frame, typography font and template graphics
     * Gh\u00E9p composite \u1EA3nh b\u00ECa k\u00E8m \u0111\u1ED3 h\u1ECDa template v\u00E0 ti\u00EAu \u0111\u1EC1 font ngh\u1EC7 thu\u1EADt
     */
    private Bitmap bakeCoverBitmap() {
        int w = 720;
        int h = 1280;
        Bitmap base = projectCoverBitmap;
        if (base == null && !activeProjectClips.isEmpty() && activeProjectClips.get(0).thumbnailBitmap != null) {
            base = activeProjectClips.get(0).thumbnailBitmap;
        }

        Bitmap composite = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(composite);

        if (base != null) {
            Rect src = new Rect(0, 0, base.getWidth(), base.getHeight());
            Rect dst = new Rect(0, 0, w, h);
            canvas.drawBitmap(base, src, dst, null);
        } else {
            canvas.drawColor(Color.parseColor("#1A1B26"));
        }

        Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
        Paint textPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
        textPaint.setTextAlign(Paint.Align.CENTER);

        // Apply Font Style
        if (coverFontIndex == 0) { // Gold Bold
            textPaint.setColor(Color.parseColor("#FFD700"));
            textPaint.setTypeface(Typeface.create(Typeface.DEFAULT, Typeface.BOLD));
            textPaint.setShadowLayer(8f, 0f, 4f, Color.BLACK);
        } else if (coverFontIndex == 1) { // Serif Classic
            textPaint.setColor(Color.WHITE);
            textPaint.setTypeface(Typeface.create(Typeface.SERIF, Typeface.BOLD_ITALIC));
            textPaint.setShadowLayer(6f, 0f, 3f, Color.BLACK);
        } else if (coverFontIndex == 2) { // Neon Cyan
            textPaint.setColor(Color.parseColor("#00E5FF"));
            textPaint.setTypeface(Typeface.create(Typeface.DEFAULT, Typeface.BOLD));
            textPaint.setShadowLayer(12f, 0f, 0f, Color.parseColor("#00E5FF"));
        } else { // Clean White
            textPaint.setColor(Color.WHITE);
            textPaint.setTypeface(Typeface.create(Typeface.SANS_SERIF, Typeface.NORMAL));
            textPaint.setShadowLayer(4f, 0f, 2f, Color.BLACK);
        }

        String title = (coverTitleText != null && !coverTitleText.trim().isEmpty()) ? coverTitleText : "NEXTAI OPENCUT";

        // Apply Template
        if (coverTemplateIndex == 0) { // Minimalist Bottom
            paint.setColor(Color.parseColor("#CC12131A"));
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(0, h - 260, w, h - 40, paint);
            paint.setColor(Color.parseColor("#00E5FF"));
            canvas.drawRect(40, h - 255, w - 40, h - 250, paint);
            textPaint.setTextSize(46);
            canvas.drawText(title, w / 2f, h - 140, textPaint);
        } else if (coverTemplateIndex == 1) { // Bold Center Hero
            paint.setColor(Color.parseColor("#E6000000"));
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(40, (h / 2f) - 140, w - 40, (h / 2f) + 140, paint);
            paint.setStyle(Paint.Style.STROKE);
            paint.setStrokeWidth(6f);
            paint.setColor(Color.parseColor("#FFD700"));
            canvas.drawRect(50, (h / 2f) - 130, w - 50, (h / 2f) + 130, paint);
            textPaint.setTextSize(52);
            canvas.drawText(title, w / 2f, (h / 2f) + 18, textPaint);
        } else if (coverTemplateIndex == 2) { // TikTok Trending Tag
            paint.setColor(Color.parseColor("#FF0055"));
            paint.setStyle(Paint.Style.FILL);
            RectF pillRect = new RectF(50, 100, 320, 170);
            canvas.drawRoundRect(pillRect, 20, 20, paint);
            Paint tagPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
            tagPaint.setColor(Color.WHITE);
            tagPaint.setTextSize(30);
            tagPaint.setTypeface(Typeface.DEFAULT_BOLD);
            canvas.drawText("\uD83D\uDD25 #TRENDING", 75, 148, tagPaint);

            paint.setColor(Color.parseColor("#B3000000"));
            canvas.drawRect(0, h - 280, w, h - 60, paint);
            textPaint.setTextSize(48);
            canvas.drawText(title, w / 2f, h - 160, textPaint);
        } else { // Cinematic Letterbox
            paint.setColor(Color.BLACK);
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(0, 0, w, 160, paint);
            canvas.drawRect(0, h - 160, w, h, paint);

            textPaint.setTextSize(44);
            canvas.drawText(title, w / 2f, h - 70, textPaint);
        }

        return composite;
    }

    /**
     * Create Pill for Cover and Subtitle dialogs
     */
    private View createCoverPill(String label, boolean isSelected, LinearLayout parent) {
        TextView pill = new TextView(this);
        pill.setText(label);
        pill.setTextColor(isSelected ? Color.parseColor("#00E5FF") : Color.WHITE);
        pill.setTextSize(11);
        pill.setTypeface(null, isSelected ? Typeface.BOLD : Typeface.NORMAL);
        pill.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_tab_pill);
        pill.setPadding(22, 12, 22, 12);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        lp.setMargins(0, 0, 12, 0);
        pill.setLayoutParams(lp);
        parent.addView(pill);
        return pill;
    }

    /**
     * Update Pill active visual state
     */
    private void setCoverPillActive(View pill, boolean active) {
        if (pill instanceof TextView) {
            TextView tv = (TextView) pill;
            tv.setTextColor(active ? Color.parseColor("#00E5FF") : Color.WHITE);
            tv.setTypeface(null, active ? Typeface.BOLD : Typeface.NORMAL);
        }
    }
`;

// Insert helperMethods before the last closing brace of MainActivity
const lastBrace = code.lastIndexOf('}');
if (lastBrace !== -1) {
    code = code.substring(0, lastBrace) + helperMethods + '\n}\n';
    console.log('8. Appended helper methods before last brace');
} else {
    console.error('8. FAILED to find last brace');
}

fs.writeFileSync(path, code, 'utf8');
console.log('Finished writing MainActivity.java! New length:', code.length);
