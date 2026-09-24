package com.nextai.opencut.presentation.model;

import android.graphics.Bitmap;

/**
 * PipClipItem — Cấu Trúc Dữ Liệu Lớp Phủ PIP Đa Tầng (Picture-in-Picture Multi-Track Overlay)
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class PipClipItem {
    public MediaItem media;
    public int startMs;
    public int durationMs;
    public float scale = 0.45f;
    public float posX = 0.55f; // relative 0.0 - 1.0
    public float posY = 0.10f;
    public String blendMode = "NORMAL"; // NORMAL, SCREEN, MULTIPLY, OVERLAY
    public int opacity = 100;
    public Bitmap pipBitmap = null;

    public PipClipItem(MediaItem media, int startMs, int durationMs) {
        this.media = media;
        this.startMs = startMs;
        this.durationMs = durationMs;
        this.scale = 0.45f;
        this.posX = 0.55f;
        this.posY = 0.10f;
        this.blendMode = "NORMAL";
        this.opacity = 100;
    }
}
