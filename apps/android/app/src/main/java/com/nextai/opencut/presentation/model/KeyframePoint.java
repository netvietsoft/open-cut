package com.nextai.opencut.presentation.model;

import java.util.List;

/**
 * KeyframePoint — Cấu Trúc Điểm Mốc Khung Hình Chính (Keyframe Data Model)
 * Lưu trữ trạng thái thời gian và các thuộc tính biến đổi nội suy (Interpolation).
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class KeyframePoint {
    public int timeMs;
    public float scale = 1.0f;
    public float translationX = 0.0f;
    public float translationY = 0.0f;
    public float rotation = 0.0f;
    public float opacity = 1.0f;

    public KeyframePoint(int timeMs) {
        this.timeMs = timeMs;
    }

    public KeyframePoint(int timeMs, float scale, float translationX, float translationY, float rotation, float opacity) {
        this.timeMs = timeMs;
        this.scale = scale;
        this.translationX = translationX;
        this.translationY = translationY;
        this.rotation = rotation;
        this.opacity = opacity;
    }

    /**
     * Sắp xếp danh sách keyframe theo thứ tự thời gian tăng dần (D8/Java 8 compatible)
     * Sorts keyframe list in ascending chronological order
     */
    public static void sortKeyframes(List<KeyframePoint> list) {
        if (list == null || list.size() <= 1) return;
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (list.get(i).timeMs > list.get(j).timeMs) {
                    KeyframePoint temp = list.get(i);
                    list.set(i, list.get(j));
                    list.set(j, temp);
                }
            }
        }
    }
}
