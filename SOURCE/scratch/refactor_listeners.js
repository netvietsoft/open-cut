const fs = require('fs');
const path = 'apps/android/app/src/main/java/com/nextai/opencut/presentation/MainActivity.java';
let code = fs.readFileSync(path, 'utf8');

// 1. Add fields on MainActivity
const fieldTarget = '    private String currentKaraokeStyle = "karaoke_gold_glow";';
const newFields = `    private String currentKaraokeStyle = "karaoke_gold_glow"; // karaoke_gold_glow, karaoke_neon_cyan, karaoke_box_highlight, karaoke_bouncy_popup

    // Parity 100% Phase 19 - Cover Dialog & Karaoke Views (avoid anonymous classes for D8)
    private ImageView ivCoverPreview;
    private EditText etCoverTitle;
    private SeekBar sbCoverScrubber;
    private View btnUploadCustomPhoto;
    private View btnSaveCover, btnCancelCover;
    private View pillFontGold, pillFontSerif, pillFontNeon, pillFontClean;
    private View pillTplBottom, pillTplCenter, pillTplTiktok, pillTplCinema;
    private View pillKaraokeGold, pillKaraokeNeon, pillKaraokeBox, pillKaraokeBounce;`;

if (code.includes(fieldTarget)) {
    code = code.replace(fieldTarget, newFields);
    console.log('1. Added dialog view fields to MainActivity');
} else {
    console.log('1. fieldTarget already modified or missing');
}

// 2. Clean showSubtitleGeneratorDialog to use MainActivity fields and setOnClickListener(this)
const oldKaraokeSub = `        final View pillGold = createCoverPill("\uD83C\uDF1F Karaoke V\u00E0ng", currentKaraokeStyle.equals("karaoke_gold_glow"), rowKaraoke);
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
        });`;

const newKaraokeSub = `        pillKaraokeGold = createCoverPill("\uD83C\uDF1F Karaoke V\u00E0ng", currentKaraokeStyle.equals("karaoke_gold_glow"), rowKaraoke);
        pillKaraokeNeon = createCoverPill("\u26A1 Neon Cyan", currentKaraokeStyle.equals("karaoke_neon_cyan"), rowKaraoke);
        pillKaraokeBox = createCoverPill("\uD83D\uDD32 H\u1ED9p \u0110en", currentKaraokeStyle.equals("karaoke_box_highlight"), rowKaraoke);
        pillKaraokeBounce = createCoverPill("\uD83D\uDCA5 N\u1EA3y B\u1EADt", currentKaraokeStyle.equals("karaoke_bouncy_popup"), rowKaraoke);

        pillKaraokeGold.setOnClickListener(this);
        pillKaraokeNeon.setOnClickListener(this);
        pillKaraokeBox.setOnClickListener(this);
        pillKaraokeBounce.setOnClickListener(this);`;

if (code.includes(oldKaraokeSub)) {
    code = code.replace(oldKaraokeSub, newKaraokeSub);
    console.log('2. Replaced oldKaraokeSub with non-anonymous listeners');
} else {
    console.log('2. Trying regex for oldKaraokeSub');
    const regexOldK = /final View pillGold = createCoverPill[\s\S]*?pillBounce\.setOnClickListener\(new View\.OnClickListener\(\) \{[\s\S]*?\}\);\s*\}/;
    if (regexOldK.test(code)) {
        code = code.replace(regexOldK, newKaraokeSub);
        console.log('2. Replaced oldKaraokeSub via regex');
    }
}

// 3. Replace showCoverEditorDialog with clean version without anonymous classes
const regexCoverDialog = /private void showCoverEditorDialog\(\) \{[\s\S]*?activeDialog\.show\(\);\s*\}/;

const newCoverDialog = `private void showCoverEditorDialog() {
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
        ivCoverPreview = new ImageView(this);
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

        etCoverTitle = new EditText(this);
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

        sbCoverScrubber = new SeekBar(this);
        sbCoverScrubber.setMax(100);
        sbCoverScrubber.setProgress(15);
        sbCoverScrubber.setOnSeekBarChangeListener(this);
        LinearLayout.LayoutParams sbLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        sbLp.setMargins(0, 4, 0, 10);
        sbCoverScrubber.setLayoutParams(sbLp);
        root.addView(sbCoverScrubber);

        // Upload External Photo Button
        btnUploadCustomPhoto = new TextView(this);
        btnUploadCustomPhoto.setText("\uD83D\uDCE4 T\u1EA3i \u1EA2nh B\u00ECa T\u1EEB Thi\u1EBFt B\u1ECB (Custom Photo)");
        btnUploadCustomPhoto.setTextColor(Color.parseColor("#00E5FF"));
        btnUploadCustomPhoto.setTextSize(12);
        btnUploadCustomPhoto.setTypeface(null, Typeface.BOLD);
        btnUploadCustomPhoto.setBackgroundColor(Color.parseColor("#1E293B"));
        btnUploadCustomPhoto.setGravity(Gravity.CENTER);
        btnUploadCustomPhoto.setPadding(20, 14, 20, 14);
        btnUploadCustomPhoto.setOnClickListener(this);
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

        pillFontGold = createCoverPill("\uD83C\uDF1F V\u00E0ng \u0110\u1EADm", coverFontIndex == 0, rowFonts);
        pillFontSerif = createCoverPill("\uD83D\uDCDC C\u1ED5 \u0110i\u1EC3n", coverFontIndex == 1, rowFonts);
        pillFontNeon = createCoverPill("\u26A1 Neon Cyan", coverFontIndex == 2, rowFonts);
        pillFontClean = createCoverPill("\uD83D\uDD32 T\u1ED1i Gi\u1EA3n", coverFontIndex == 3, rowFonts);

        pillFontGold.setOnClickListener(this);
        pillFontSerif.setOnClickListener(this);
        pillFontNeon.setOnClickListener(this);
        pillFontClean.setOnClickListener(this);

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

        pillTplBottom = createCoverPill("\uD83D\uDCCC D\u01B0\u1EDBi T\u1ED1i Gi\u1EA3n", coverTemplateIndex == 0, rowTemplates);
        pillTplCenter = createCoverPill("\uD83C\uDFAF Khung Gi\u1EEFa", coverTemplateIndex == 1, rowTemplates);
        pillTplTiktok = createCoverPill("\uD83D\uDD25 TikTok Tag", coverTemplateIndex == 2, rowTemplates);
        pillTplCinema = createCoverPill("\uD83C\uDFAC \u0110i\u1EC7n \u1EA2nh", coverTemplateIndex == 3, rowTemplates);

        pillTplBottom.setOnClickListener(this);
        pillTplCenter.setOnClickListener(this);
        pillTplTiktok.setOnClickListener(this);
        pillTplCinema.setOnClickListener(this);

        hScrollTemplates.addView(rowTemplates);
        LinearLayout.LayoutParams hsLp2 = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        hsLp2.setMargins(0, 0, 0, 20);
        hScrollTemplates.setLayoutParams(hsLp2);
        root.addView(hScrollTemplates);

        // Action Buttons: Save Cover & Cancel
        btnSaveCover = new TextView(this);
        btnSaveCover.setText("\u2713 L\u01AFU L\u00C0M \u1EA2NH B\u00CCA (SAVE COVER)");
        btnSaveCover.setTextColor(Color.BLACK);
        btnSaveCover.setTextSize(13);
        btnSaveCover.setTypeface(null, Typeface.BOLD);
        btnSaveCover.setBackgroundColor(Color.parseColor("#00E5FF"));
        btnSaveCover.setGravity(Gravity.CENTER);
        btnSaveCover.setPadding(24, 18, 24, 18);
        btnSaveCover.setOnClickListener(this);
        LinearLayout.LayoutParams btnSaveLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        btnSaveLp.setMargins(0, 0, 0, 10);
        btnSaveCover.setLayoutParams(btnSaveLp);
        root.addView(btnSaveCover);

        btnCancelCover = new TextView(this);
        btnCancelCover.setText("\u0110\u00F3ng (Cancel)");
        btnCancelCover.setTextColor(Color.parseColor("#94A3B8"));
        btnCancelCover.setTextSize(12);
        btnCancelCover.setBackgroundColor(Color.parseColor("#1E202E"));
        btnCancelCover.setGravity(Gravity.CENTER);
        btnCancelCover.setPadding(20, 14, 20, 14);
        btnCancelCover.setOnClickListener(this);
        root.addView(btnCancelCover);

        updateCoverPreview();

        builder.setView(scrollRoot);
        activeDialog = builder.create();
        if (activeDialog.getWindow() != null) {
            activeDialog.getWindow().setBackgroundDrawableResource(android.R.color.transparent);
        }
        activeDialog.show();
    }`;

if (regexCoverDialog.test(code)) {
    code = code.replace(regexCoverDialog, newCoverDialog);
    console.log('3. Replaced showCoverEditorDialog with clean version');
} else {
    console.error('3. FAILED to match regexCoverDialog');
}

// 4. Add updateCoverPreview method if missing
if (!code.includes('private void updateCoverPreview() {')) {
    const updateCoverMethod = `    private void updateCoverPreview() {
        if (etCoverTitle != null) {
            coverTitleText = etCoverTitle.getText().toString();
        }
        if (ivCoverPreview != null) {
            ivCoverPreview.setImageBitmap(bakeCoverBitmap());
        }
    }
`;
    code = code.replace('private Bitmap bakeCoverBitmap() {', updateCoverMethod + '\n    private Bitmap bakeCoverBitmap() {');
    console.log('4. Added updateCoverPreview method');
}

// 5. Wire onProgressChanged for sbCoverScrubber
const progressTarget = '    @Override\n    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {\n';
const progressAddition = `    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        if (seekBar == sbCoverScrubber) {
            if (fromUser) updateCoverPreview();
            return;
        }
`;

if (code.includes(progressTarget)) {
    code = code.replace(progressTarget, progressAddition);
    console.log('5. Wired onProgressChanged for sbCoverScrubber');
}

// 6. Wire onClick for all dialog views
const onClickTarget = '    @Override\n    public void onClick(View v) {\n';
const onClickAddition = `    @Override
    public void onClick(View v) {
        // Parity 100% Phase 19 - Cover Editor & Karaoke Listeners
        if (v == pillKaraokeGold) {
            currentKaraokeStyle = "karaoke_gold_glow";
            setCoverPillActive(pillKaraokeGold, true);
            setCoverPillActive(pillKaraokeNeon, false);
            setCoverPillActive(pillKaraokeBox, false);
            setCoverPillActive(pillKaraokeBounce, false);
            return;
        } else if (v == pillKaraokeNeon) {
            currentKaraokeStyle = "karaoke_neon_cyan";
            setCoverPillActive(pillKaraokeGold, false);
            setCoverPillActive(pillKaraokeNeon, true);
            setCoverPillActive(pillKaraokeBox, false);
            setCoverPillActive(pillKaraokeBounce, false);
            return;
        } else if (v == pillKaraokeBox) {
            currentKaraokeStyle = "karaoke_box_highlight";
            setCoverPillActive(pillKaraokeGold, false);
            setCoverPillActive(pillKaraokeNeon, false);
            setCoverPillActive(pillKaraokeBox, true);
            setCoverPillActive(pillKaraokeBounce, false);
            return;
        } else if (v == pillKaraokeBounce) {
            currentKaraokeStyle = "karaoke_bouncy_popup";
            setCoverPillActive(pillKaraokeGold, false);
            setCoverPillActive(pillKaraokeNeon, false);
            setCoverPillActive(pillKaraokeBox, false);
            setCoverPillActive(pillKaraokeBounce, true);
            return;
        } else if (v == pillFontGold) {
            coverFontIndex = 0;
            setCoverPillActive(pillFontGold, true);
            setCoverPillActive(pillFontSerif, false);
            setCoverPillActive(pillFontNeon, false);
            setCoverPillActive(pillFontClean, false);
            updateCoverPreview();
            return;
        } else if (v == pillFontSerif) {
            coverFontIndex = 1;
            setCoverPillActive(pillFontGold, false);
            setCoverPillActive(pillFontSerif, true);
            setCoverPillActive(pillFontNeon, false);
            setCoverPillActive(pillFontClean, false);
            updateCoverPreview();
            return;
        } else if (v == pillFontNeon) {
            coverFontIndex = 2;
            setCoverPillActive(pillFontGold, false);
            setCoverPillActive(pillFontSerif, false);
            setCoverPillActive(pillFontNeon, true);
            setCoverPillActive(pillFontClean, false);
            updateCoverPreview();
            return;
        } else if (v == pillFontClean) {
            coverFontIndex = 3;
            setCoverPillActive(pillFontGold, false);
            setCoverPillActive(pillFontSerif, false);
            setCoverPillActive(pillFontNeon, false);
            setCoverPillActive(pillFontClean, true);
            updateCoverPreview();
            return;
        } else if (v == pillTplBottom) {
            coverTemplateIndex = 0;
            setCoverPillActive(pillTplBottom, true);
            setCoverPillActive(pillTplCenter, false);
            setCoverPillActive(pillTplTiktok, false);
            setCoverPillActive(pillTplCinema, false);
            updateCoverPreview();
            return;
        } else if (v == pillTplCenter) {
            coverTemplateIndex = 1;
            setCoverPillActive(pillTplBottom, false);
            setCoverPillActive(pillTplCenter, true);
            setCoverPillActive(pillTplTiktok, false);
            setCoverPillActive(pillTplCinema, false);
            updateCoverPreview();
            return;
        } else if (v == pillTplTiktok) {
            coverTemplateIndex = 2;
            setCoverPillActive(pillTplBottom, false);
            setCoverPillActive(pillTplCenter, false);
            setCoverPillActive(pillTplTiktok, true);
            setCoverPillActive(pillTplCinema, false);
            updateCoverPreview();
            return;
        } else if (v == pillTplCinema) {
            coverTemplateIndex = 3;
            setCoverPillActive(pillTplBottom, false);
            setCoverPillActive(pillTplCenter, false);
            setCoverPillActive(pillTplTiktok, false);
            setCoverPillActive(pillTplCinema, true);
            updateCoverPreview();
            return;
        } else if (v == btnUploadCustomPhoto) {
            if (!allMediaItems.isEmpty()) {
                for (MediaItem m : allMediaItems) {
                    if (!m.isVideo && m.thumbnailBitmap != null) {
                        projectCoverBitmap = m.thumbnailBitmap;
                        break;
                    }
                }
            }
            updateCoverPreview();
            Toast.makeText(this, "\uD83D\uDCE4 \u0110\u00E3 n\u1EA1p \u1EA3nh b\u00ECa t\u1EF1 ch\u1ECDn t\u1EEB th\u01B0 vi\u1EC7n!", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnSaveCover) {
            if (etCoverTitle != null) coverTitleText = etCoverTitle.getText().toString();
            projectCoverBitmap = bakeCoverBitmap();
            if (tvCoverIconView != null) {
                tvCoverIconView.setText("\u2713");
                tvCoverIconView.setTextColor(Color.parseColor("#00E5FF"));
            }
            if (tvCoverLabelView != null) {
                tvCoverLabelView.setText("\u0110\u00E3 ch\u1ECDn");
                tvCoverLabelView.setTextColor(Color.parseColor("#00E5FF"));
            }
            Toast.makeText(this, "\u2713 \u0110\u00E3 l\u01B0u \u1EA3nh b\u00ECa video th\u00E0nh c\u00F4ng!", Toast.LENGTH_SHORT).show();
            if (activeDialog != null) {
                activeDialog.dismiss();
                activeDialog = null;
            }
            return;
        } else if (v == btnCancelCover) {
            if (activeDialog != null) {
                activeDialog.dismiss();
                activeDialog = null;
            }
            return;
        }
`;

if (code.includes(onClickTarget)) {
    code = code.replace(onClickTarget, onClickAddition);
    console.log('6. Wired onClick for all dialog views');
}

fs.writeFileSync(path, code, 'utf8');
console.log('Finished refactoring listeners in MainActivity.java!');
