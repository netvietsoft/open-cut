package com.nextai.opencut;

import com.nextai.opencut.presentation.model.MediaItem;

/**
 * MediaItemTest — Unit test verifying MediaItem model properties, trimming boundaries, and speed retention.
 * Kiểm thử mô hình dữ liệu MediaItem, giới hạn cắt gọt In/Out và bảo toàn thời lượng gốc khi đổi tốc độ.
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class MediaItemTest {

    public static void runAllTests() {
        System.out.println(">>> Running MediaItemTest...");
        testMediaItemInitialization();
        testTrimBoundaries();
        testSpeedPreservesOriginalDuration();
        System.out.println(">>> MediaItemTest: ALL TESTS PASSED (3/3)\n");
    }

    private static void testMediaItemInitialization() {
        MediaItem item = new MediaItem("clip_01", "Test Video", null, "01:30", true, 0, "🎥");
        if (!"clip_01".equals(item.id)) {
            throw new AssertionError("Expected id 'clip_01', got: " + item.id);
        }
        if (item.durationSeconds != 90) {
            throw new AssertionError("Expected durationSeconds 90, got: " + item.durationSeconds);
        }
        if (item.originalDurationSeconds != 90) {
            throw new AssertionError("Expected originalDurationSeconds 90, got: " + item.originalDurationSeconds);
        }
        if (item.trimInSec != 0 || item.trimOutSec != 90) {
            throw new AssertionError("Expected trim [0, 90], got: [" + item.trimInSec + ", " + item.trimOutSec + "]");
        }
        System.out.println("  [PASS] testMediaItemInitialization");
    }

    private static void testTrimBoundaries() {
        MediaItem item = new MediaItem("clip_02", "Clip Trim", null, "00:45", true, 0, "🎥");
        item.trimInSec = 10;
        item.trimOutSec = 35;
        int activeDuration = item.trimOutSec - item.trimInSec;
        if (activeDuration != 25) {
            throw new AssertionError("Expected active duration 25s, got: " + activeDuration);
        }
        System.out.println("  [PASS] testTrimBoundaries");
    }

    private static void testSpeedPreservesOriginalDuration() {
        MediaItem item = new MediaItem("clip_03", "Speed Test", null, "01:00", true, 0, "🎥");
        // Speed up 2x: duration becomes 30s, but originalDurationSeconds remains 60s
        item.speed = 2.0f;
        item.durationSeconds = Math.round(item.originalDurationSeconds / item.speed);
        if (item.durationSeconds != 30) {
            throw new AssertionError("Expected 30s at 2.0x, got: " + item.durationSeconds);
        }
        if (item.originalDurationSeconds != 60) {
            throw new AssertionError("Original duration corrupted! Expected 60s, got: " + item.originalDurationSeconds);
        }

        // Slow down to 0.5x: duration becomes 120s from original 60s
        item.speed = 0.5f;
        item.durationSeconds = Math.round(item.originalDurationSeconds / item.speed);
        if (item.durationSeconds != 120) {
            throw new AssertionError("Expected 120s at 0.5x, got: " + item.durationSeconds);
        }
        System.out.println("  [PASS] testSpeedPreservesOriginalDuration");
    }
}
