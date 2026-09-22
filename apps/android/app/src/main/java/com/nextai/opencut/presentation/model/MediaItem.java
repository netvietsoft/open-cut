package com.nextai.opencut.presentation.model;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.net.Uri;

import java.util.ArrayList;
import java.util.List;

/**
 * MediaItem — Cấu Trúc Dữ Liệu Clip Video & Hình Ảnh Dùng Chung (Media Item Data Model)
 * Lưu trữ thuộc tính gốc, trạng thái chọn, hiệu ứng, keyframes, và thông số xử lý đa tầng.
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class MediaItem {
    public String id;
    public String title;
    public Uri uri;
    public String duration;
    public int durationSeconds;
    public int originalDurationSeconds;
    public int trimInSec = 0;
    public int trimOutSec = 0;
    public boolean isVideo;
    public int colorBg;
    public String icon;
    public boolean isSelected;
    public int selectionIndex;
    public float speed;
    public int volume;
    public int brightness;
    public int contrast;
    public int saturation;
    public Bitmap thumbnailBitmap = null;

    // Parity 100% Phase 17 - Keyframes, Transitions, Audio Fades & Animations
    public final List<KeyframePoint> keyframes = new ArrayList<>();
    public String transitionType = "none";
    public float transitionDurationSec = 0.5f;
    public String animationType = "none";
    public float animationDurationSec = 0.5f;
    public float fadeInSec = 0.0f;
    public float fadeOutSec = 0.0f;
    public int opacityPercent = 100;

    // Parity 100% Phase 18 - Curve Speed, Chroma Key Spill, Smart Matting Stroke, DSP Audio
    public String curveSpeedPreset = "none";
    public float[] curveSpeedPoints = new float[]{0.5f, 0.5f, 0.5f, 0.5f, 0.5f};
    public boolean preservePitch = true;
    public int chromaColor = 0xFF00FF00; // Chroma Green / Xanh lá tiêu chuẩn
    public int chromaIntensity = 65;
    public int chromaShadow = 40;
    public int chromaSpill = 50;
    public String smartStrokeStyle = "none";
    public int noiseReductionLevel = 0;
    public String vocalIsolationMode = "none";

    public MediaItem(String id, String title, Uri uri, String duration, boolean isVideo, int colorBg, String icon) {
        this.id = id;
        this.title = title;
        this.uri = uri;
        this.duration = duration;
        this.durationSeconds = parseDurationToSeconds(duration);
        // Retain initial duration to prevent compounding rounding errors when speed changes
        // Lưu lại độ dài gốc ban đầu nhằm tránh lỗi tích lũy làm sai lệch độ dài khi thay đổi tốc độ
        this.originalDurationSeconds = this.durationSeconds > 0 ? this.durationSeconds : 16;
        this.trimInSec = 0;
        this.trimOutSec = this.durationSeconds;
        this.isVideo = isVideo;
        this.colorBg = colorBg;
        this.icon = icon;
        this.isSelected = false;
        this.selectionIndex = 0;
        this.speed = 1.0f;
        this.volume = 100;
        this.brightness = 0;
        this.contrast = 100;
        this.saturation = 100;
    }

    private static int parseDurationToSeconds(String d) {
        if (d == null || !d.contains(":")) return 16;
        try {
            String[] parts = d.split(":");
            return Integer.parseInt(parts[0]) * 60 + Integer.parseInt(parts[1]);
        } catch (Exception e) {
            return 16;
        }
    }
}
