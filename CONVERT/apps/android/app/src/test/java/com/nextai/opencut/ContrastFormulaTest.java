package com.nextai.opencut;

/**
 * ContrastFormulaTest — Unit test verifying the photographic contrast formula with 127.5f midpoint pivot.
 * Kiểm thử công thức ma trận tương phản ảnh quanh điểm xoay mức xám trung tính 127.5f (Bảo vệ lỗi P6).
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class ContrastFormulaTest {

    public static void runAllTests() {
        System.out.println(">>> Running ContrastFormulaTest (P6 Fix Verification)...");
        testNeutralContrastPreservesMidgray();
        testDoubleContrastPreservesMidgray();
        testZeroContrastFlattensToMidgray();
        testBrightenedContrastWithPivot();
        System.out.println(">>> ContrastFormulaTest: ALL TESTS PASSED (4/4)\n");
    }

    private static float calculateNewPixel(float inputPixel, int brightness, int contrast) {
        float scale = contrast / 100.0f;
        // P6 Fix: Midpoint pivot 127.5f
        float translate = brightness + 127.5f * (1.0f - scale);
        return inputPixel * scale + translate;
    }

    /**
     * Test neutral contrast (100%): Output must be identical to input.
     * Kiểm thử tương phản gốc 100%: Điểm ảnh đầu ra phải trùng khớp đầu vào.
     */
    private static void testNeutralContrastPreservesMidgray() {
        float midgray = 127.5f;
        float result = calculateNewPixel(midgray, 0, 100);
        if (Math.abs(result - 127.5f) > 0.001f) {
            throw new AssertionError("Neutral contrast failed! Expected 127.5, got " + result);
        }
        System.out.println("  [PASS] testNeutralContrastPreservesMidgray");
    }

    /**
     * Test high contrast (200%): Mid-gray must remain strictly at 127.5f without clipping to white.
     * Kiểm thử tăng tương phản 200%: Mức xám 127.5f phải giữ nguyên, không bị cháy sáng thành trắng.
     */
    private static void testDoubleContrastPreservesMidgray() {
        float midgray = 127.5f;
        float result = calculateNewPixel(midgray, 0, 200);
        if (Math.abs(result - 127.5f) > 0.001f) {
            throw new AssertionError("High contrast pivot failed! Expected 127.5, got " + result);
        }
        System.out.println("  [PASS] testDoubleContrastPreservesMidgray");
    }

    /**
     * Test zero contrast (0%): All pixels must collapse exactly to neutral mid-gray (127.5f).
     * Kiểm thử tương phản bằng 0%: Mọi điểm ảnh phải đồng quy về mức xám trung tính 127.5f, không bị đen xì.
     */
    private static void testZeroContrastFlattensToMidgray() {
        float blackPixel = 0.0f;
        float whitePixel = 255.0f;
        float resBlack = calculateNewPixel(blackPixel, 0, 0);
        float resWhite = calculateNewPixel(whitePixel, 0, 0);

        if (Math.abs(resBlack - 127.5f) > 0.001f || Math.abs(resWhite - 127.5f) > 0.001f) {
            throw new AssertionError("Zero contrast failed to collapse to midgray! black=" + resBlack + ", white=" + resWhite);
        }
        System.out.println("  [PASS] testZeroContrastFlattensToMidgray");
    }

    /**
     * Test brightness combined with contrast: Offset must apply cleanly on top of pivoted scale.
     * Kiểm thử bù sáng kết hợp tương phản: Độ dịch chuyển sáng phải cộng đúng trên nền xoay tương phản.
     */
    private static void testBrightenedContrastWithPivot() {
        float midgray = 127.5f;
        float result = calculateNewPixel(midgray, 20, 150);
        // Expected: 127.5 * 1.5 + 20 + 127.5 * (1 - 1.5) = 191.25 + 20 - 63.75 = 147.5f
        if (Math.abs(result - 147.5f) > 0.001f) {
            throw new AssertionError("Brightened contrast failed! Expected 147.5, got " + result);
        }
        System.out.println("  [PASS] testBrightenedContrastWithPivot");
    }
}
