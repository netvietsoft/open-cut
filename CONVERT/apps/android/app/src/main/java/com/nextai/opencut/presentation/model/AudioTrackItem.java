package com.nextai.opencut.presentation.model;

import android.net.Uri;

/**
 * AudioTrackItem — Cấu Trúc Dữ Liệu Track Âm Thanh Đa Tầng (Multi-track Audio Data Model)
 * Hỗ trợ các dải nhạc nền (BGM), hiệu ứng âm thanh (Sound FX), thuyết minh (Voiceover), và trích xuất (Extracted).
 * Supports BGM, Sound FX, Voiceover, and Extracted audio tracks with volume and timing control.
 *
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class AudioTrackItem {
    public String id;
    public String title;
    public int trackType; // 1: BGM, 2: Sound FX, 3: Voiceover, 4: Extracted
    public int startMs;
    public int durationMs;
    public int volumePercent;
    public String colorHex;
    public Uri uri;

    public AudioTrackItem(String id, String title, int trackType, int startMs, int durationMs, int volumePercent, String colorHex, Uri uri) {
        this.id = id;
        this.title = title;
        this.trackType = trackType;
        this.startMs = startMs;
        this.durationMs = durationMs;
        this.volumePercent = volumePercent;
        this.colorHex = colorHex;
        this.uri = uri;
    }
}
