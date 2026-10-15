// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_painter_sdk.h
// Description: PainterInterface JNI runtime, Composer management, VIP layer properties
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "retouch_types.h"
#include "retouch_face_align.h"
#include "retouch_beauty_engine.h"
#include "retouch_body_reshape.h"
#include <jni.h>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <mutex>

namespace retouch_sdk {

// EN: Preset Color Palette descriptor for one-tap portrait grading
// VN: Mô tả bảng màu chân dung mẫu phục vụ chỉnh màu một chạm
struct ColorPalette {
    std::string palette_id;
    std::string palette_name;
    float warm_cool_bias = 0.0f;       // [-1.0: Cool Blue, +1.0: Warm Gold]
    float tint_magenta_green = 0.0f;   // [-1.0: Emerald Green, +1.0: Magenta]
    float vibrance = 1.0f;             // Color vibrance scaling factor
    float contrast = 1.0f;             // S-curve contrast scaling factor
};

// EN: Painter SDK Central Runtime managing facial, body, and composer layers
// VN: Môi trường thực thi trung tâm Painter SDK quản lý khuôn mặt, cơ thể và các layer hiệu ứng
class PainterSDKRuntime {
public:
    static PainterSDKRuntime& GetInstance();

    PainterSDKRuntime();
    ~PainterSDKRuntime();

    // EN: Initialize runtime with canvas dimensions (Opcode 0x847c0)
    // VN: Khởi tạo môi trường với kích thước khung vẽ (Opcode 0x847c0)
    bool Initialize(int32_t width, int32_t height);

    // EN: Apply recommended palette preset by name (Opcode 0x133e40)
    // VN: Áp dụng bảng màu chân dung đề xuất theo tên (Opcode 0x133e40)
    bool ApplyRecommendPalette(const std::string& palette_id);

    // EN: Set composer effect intensities (Opcode 0xcbc80)
    // VN: Cấu hình cường độ các bộ lọc trong composer (Opcode 0xcbc80)
    void SetComposerIntensities(const std::vector<painter::ComposerIntensityDesc>& descriptors);

    // EN: Remove active makeup composer (Opcode 0xcb9b8)
    // VN: Loại bỏ bộ hòa trộn trang điểm hiện hành (Opcode 0xcb9b8)
    void RemoveMakeupComposer();

    // EN: Set manual body reshaping intensity (Opcode 0x153190)
    // VN: Cấu hình thủ công cường độ định hình cơ thể (Opcode 0x153190)
    void SetManualBodyIntensity(float leg_ratio, float waist_ratio);

    // EN: Transform normalized coordinates [0, 1] through active deformation field (Opcode 0x153168)
    // VN: Biến đổi tọa độ chuẩn hóa [0, 1] qua trường biến dạng hiện hành (Opcode 0x153168)
    Point2F TransformNormalizedCoordinates(float norm_x, float norm_y);

    // EN: Query VIP feature availability for a given layer (Opcode 0x8d2e0)
    // VN: Truy vấn trạng thái quyền VIP cho layer tương ứng (Opcode 0x8d2e0)
    LayerPropInfo GetAvailableVipInfo(int32_t layer_id) const;

    // EN: Register a layer property with VIP level requirement
    // VN: Đăng ký thuộc tính layer với cấp độ VIP yêu cầu
    void RegisterLayerProperty(const LayerPropInfo& prop);

    // Sub-engine accessors
    FaceAligner& GetFaceAligner() { return m_face_aligner; }
    BeautyEngine& GetBeautyEngine() { return m_beauty_engine; }
    BodyReshaper& GetBodyReshaper() { return m_body_reshaper; }

    int32_t GetCanvasWidth() const { return m_canvas_width; }
    int32_t GetCanvasHeight() const { return m_canvas_height; }

private:
    int32_t m_canvas_width = 1080;
    int32_t m_canvas_height = 1920;
    bool m_initialized = false;

    FaceAligner m_face_aligner;
    BeautyEngine m_beauty_engine;
    BodyReshaper m_body_reshaper;

    std::map<std::string, ColorPalette> m_palettes;
    std::string m_active_palette_id;
    std::map<int32_t, LayerPropInfo> m_layer_props;

    mutable std::mutex m_mutex;

    void LoadDefaultPalettes();
    void LoadDefaultLayerVipInfo();
};

} // namespace retouch_sdk

// --- JNI EXPORT DECLARATIONS ---
extern "C" {
    JNIEXPORT void JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeApplyRecommendPalette(
        JNIEnv *env, jobject thiz, jstring j_palette_id);

    JNIEXPORT void JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeRemoveMakeupComposer(
        JNIEnv *env, jobject thiz);

    JNIEXPORT void JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeSetIntensities(
        JNIEnv *env, jobject thiz, jobjectArray j_tags, jfloatArray j_values);

    JNIEXPORT jfloatArray JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeTransformNormalizedCoordinates(
        JNIEnv *env, jobject thiz, jfloat norm_x, jfloat norm_y);

    JNIEXPORT void JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeSetManualBodyIntensity(
        JNIEnv *env, jobject thiz, jfloat leg_ratio, jfloat waist_ratio);
}
