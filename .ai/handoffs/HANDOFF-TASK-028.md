# HANDOFF TASK-028: Replace Clip, Cover Frame Editor & Word-by-Word Karaoke Captions (Phase 19)

- **Task ID**: `TASK-028-REPLACECLIP-COVEREDITOR-WORDKARAOKE`
- **Release Version**: `v2.1.8-replaceclip-cover-karaoke`
- **Timestamp**: 2026-09-19T07:46:00+07:00
- **Status**: `COMPLETED & VERIFIED 100% PARITY ON PHYSICAL SAMSUNG GALAXY A50S`

---

## 1. Executive Summary & Capabilities Implemented
1. **Đổi Clip Giữ Nguyên Thuộc Tính (Replace Clip)**:
   - Tool `Thay thế` in the Edit Submenu toolbar.
   - Preserves 100% of duration, trim points, speed curves, 3D LUTs, audio boost (0-1000%), animations, transitions, and keyframes.
   - Smoothly swaps the media source and updates the timeline filmstrip and player.

2. **Trình Sửa Ảnh Bìa (Cover Frame Editor)**:
   - Tapping the `Ảnh bìa` box on the timeline opens the CapCut-style Cover Editor Dialog.
   - Features video frame scrubber (0 to duration Ms), custom photo upload from local storage, cover title input text.
   - 4 Typography font styles: `🌟 Vàng Đậm`, `📜 Cổ Điển`, `⚡ Neon Cyan`, `🔳 Tối Giản`.
   - 4 Authentic CapCut cover templates: `Minimalist Bottom`, `Bold Center Hero`, `TikTok Trending Tag`, `Cinematic Letterbox`.
   - Baking composite canvas onto `projectCoverBitmap` and updating timeline badge to `✓ Đã chọn` in neon cyan `#00E5FF`.

3. **Phụ Đề Nhảy Chữ Từng Từ (Word-By-Word Karaoke Captions)**:
   - 4 Karaoke styles selectable in Auto Subtitle dialog: `🌟 Karaoke Vàng`, `⚡ Neon Cyan`, `🔲 Hộp Đen`, `💥 Nảy Bật`.
   - Word-by-word highlight engine (`renderWordByWordKaraoke`) using `SpannableStringBuilder` with active word gold yellow `#FFD700` / neon cyan `#00E5FF`, 1.25x scale, bold style.
   - Fully synchronized with playback runnable timecode in real time.

---

## 2. Physical Device Photographic Evidence
Device: **Samsung Galaxy A50s (`SM-A507FN`, Android 11, 1080x2340, wireless ADB `192.168.1.3:36903`)**
- `design/screenshots/parity100/phase19_cover_editor_dialog.png`: Cover Editor dialog with frame scrubber, 4 typography styles, and 4 cover templates.
- `design/screenshots/parity100/phase19_cover_saved.png`: Timeline cover badge displaying `✓ Đã chọn` in `#00E5FF`.
- `design/screenshots/parity100/phase19_replace_picker.png`: Media picker in `Thay Thế Clip` mode.
- `design/screenshots/parity100/phase19_replace_clip_verified.png`: Timeline with clip replaced preserving all attributes.
- `design/screenshots/parity100/phase19_karaoke_dialog.png`: Auto Subtitle dialog showing 4 Karaoke styles.
- `design/screenshots/parity100/phase19_karaoke_highlight.png`: Real-time playback showing active word "với" highlighted in Gold `#FFD700`.

---

## 3. Files Modified & Standards Complied
- `apps/android/app/src/main/java/com/nextai/opencut/presentation/MainActivity.java`
- `apps/android/app/src/main/java/com/nextai/opencut/engine/EffectRegistry.java`
- 100% Bilingual comments EN + VN (AGENTS.md Rule 12).
- Zero compilation / D8 R8 errors.
