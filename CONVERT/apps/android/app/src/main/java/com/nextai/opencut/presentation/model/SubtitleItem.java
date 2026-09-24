package com.nextai.opencut.presentation.model;

/**
 * SubtitleItem — Cấu Trúc Dữ Liệu Phụ Đề AI Thời Gian Thực (AI Subtitle Data Model)
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class SubtitleItem {
    public int startMs;
    public int endMs;
    public String text;

    public SubtitleItem(int startMs, int endMs, String text) {
        this.startMs = startMs;
        this.endMs = endMs;
        this.text = text;
    }
}
