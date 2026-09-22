package com.nextai.opencut.presentation.photo;

import android.graphics.ColorMatrix;

/**
 * PhotoFilterController — Manages 3D LUT photo color filter presets and basic color grading adjustments.
 * Trình điều khiển Bộ Lọc Màu Ảnh: Quản lý các Preset 3D LUT điện ảnh và tinh chỉnh màu sắc cơ bản.
 */
public class PhotoFilterController {

    /**
     * Generate ColorMatrix for specified 3D LUT photo filter preset.
     * Tạo ma trận ColorMatrix cho preset bộ lọc màu ảnh 3D LUT được chỉ định.
     *
     * @param filterKey Filter preset key (original, portra, cyberpunk, teal_orange, noir, vintage, cinema_gold, fuji, rose, moody)
     * @return ColorMatrix representing the color transformation / Ma trận biến đổi màu
     */
    public static ColorMatrix getFilterMatrix(String filterKey) {
        ColorMatrix cm = new ColorMatrix();
        if (filterKey == null || "original".equals(filterKey)) {
            return cm; // Identity matrix / Ma trận đơn vị
        }

        if ("portra".equals(filterKey)) {
            ColorMatrix portra = new ColorMatrix(new float[]{
                1.15f, 0, 0, 0, 20,
                0, 1.05f, 0, 0, 10,
                0, 0, 0.90f, 0, -5,
                0, 0, 0, 1, 0
            });
            cm.postConcat(portra);
        } else if ("cyberpunk".equals(filterKey)) {
            ColorMatrix cyberpunk = new ColorMatrix(new float[]{
                1.10f, 0, 0, 0, 25,
                0, 0.85f, 0, 0, -15,
                0, 0, 1.35f, 0, 40,
                0, 0, 0, 1, 0
            });
            cm.postConcat(cyberpunk);
        } else if ("teal_orange".equals(filterKey)) {
            ColorMatrix tealOrange = new ColorMatrix(new float[]{
                1.25f, 0, 0, 0, 30,
                0, 1.00f, 0, 0, 5,
                0, 0, 1.20f, 0, 25,
                0, 0, 0, 1, 0
            });
            cm.postConcat(tealOrange);
        } else if ("noir".equals(filterKey)) {
            ColorMatrix noir = new ColorMatrix();
            noir.setSaturation(0);
            ColorMatrix contrast = new ColorMatrix(new float[]{
                1.4f, 0, 0, 0, -30,
                0, 1.4f, 0, 0, -30,
                0, 0, 1.4f, 0, -30,
                0, 0, 0, 1, 0
            });
            noir.postConcat(contrast);
            cm.postConcat(noir);
        } else if ("vintage".equals(filterKey)) {
            ColorMatrix vintage = new ColorMatrix(new float[]{
                1.10f, 0.10f, 0, 0, 15,
                0.05f, 1.05f, 0, 0, 20,
                0, 0.10f, 0.85f, 0, -10,
                0, 0, 0, 1, 0
            });
            cm.postConcat(vintage);
        } else if ("cinema_gold".equals(filterKey)) {
            ColorMatrix cinemaGold = new ColorMatrix(new float[]{
                1.20f, 0.05f, 0, 0, 25,
                0, 1.10f, 0, 0, 15,
                0, 0, 0.80f, 0, -20,
                0, 0, 0, 1, 0
            });
            cm.postConcat(cinemaGold);
        } else if ("fuji".equals(filterKey)) {
            ColorMatrix fuji = new ColorMatrix(new float[]{
                1.02f, 0, 0.05f, 0, 5,
                0, 1.12f, 0.05f, 0, 10,
                0.05f, 0.05f, 1.18f, 0, 20,
                0, 0, 0, 1, 0
            });
            cm.postConcat(fuji);
        } else if ("rose".equals(filterKey)) {
            ColorMatrix rose = new ColorMatrix(new float[]{
                1.18f, 0.05f, 0, 0, 20,
                0, 1.02f, 0.05f, 0, 5,
                0.05f, 0, 1.10f, 0, 15,
                0, 0, 0, 1, 0
            });
            cm.postConcat(rose);
        } else if ("moody".equals(filterKey)) {
            ColorMatrix moody = new ColorMatrix(new float[]{
                0.95f, 0, 0, 0, -10,
                0, 0.95f, 0, 0, -10,
                0, 0, 1.05f, 0, 5,
                0, 0, 0, 1, 0
            });
            ColorMatrix moodySat = new ColorMatrix();
            moodySat.setSaturation(0.75f);
            moody.postConcat(moodySat);
            cm.postConcat(moody);
        }

        return cm;
    }

    /**
     * Generate ColorMatrix for brightness, contrast, and saturation adjustments.
     * Tạo ma trận ColorMatrix cho độ sáng, tương phản và độ bão hòa màu.
     *
     * @param brightness Offset brightness value (-100 to 100) / Giá trị bù sáng
     * @param contrast Contrast percentage (0 to 200, 100 is neutral) / Phần trăm tương phản
     * @param saturation Saturation percentage (0 to 200, 100 is neutral) / Phần trăm bão hòa
     * @return ColorMatrix representing the adjustments / Ma trận điều chỉnh
     */
    public static ColorMatrix getAdjustmentMatrix(int brightness, int contrast, int saturation) {
        ColorMatrix cm = new ColorMatrix();

        if (saturation != 100) {
            ColorMatrix satMatrix = new ColorMatrix();
            satMatrix.setSaturation(saturation / 100.0f);
            cm.postConcat(satMatrix);
        }

        float scale = contrast / 100.0f;
        // P6 Fix: Standard contrast formula pivoted around neutral midpoint 127.5f:
        // Công thức tương phản chuẩn quanh điểm xoay 127.5f để bảo vệ sắc độ xám trung tính:
        // new_val = (val - 127.5f) * scale + 127.5f + brightness = val * scale + (127.5f * (1 - scale) + brightness)
        float translate = brightness + 127.5f * (1.0f - scale);
        ColorMatrix adjustMatrix = new ColorMatrix(new float[]{
            scale, 0, 0, 0, translate,
            0, scale, 0, 0, translate,
            0, 0, scale, 0, translate,
            0, 0, 0, 1, 0
        });
        cm.postConcat(adjustMatrix);

        return cm;
    }
}
