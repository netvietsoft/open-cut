// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_painter_sdk.cpp
// Description: Implementation of PainterInterface JNI runtime and composer coordination
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "retouch_painter_sdk.h"
#include <iostream>
#include <cstring>

namespace retouch_sdk {

// EN: Singleton access to central PainterSDKRuntime
// VN: Truy cập thực thể duy nhất của PainterSDKRuntime trung tâm
PainterSDKRuntime& PainterSDKRuntime::GetInstance() {
    static PainterSDKRuntime instance;
    return instance;
}

// EN: Constructor initializing default palettes and layer VIP info
// VN: Hàm khởi tạo thiết lập bảng màu mặc định và thông tin quyền VIP layer
PainterSDKRuntime::PainterSDKRuntime() {
    LoadDefaultPalettes();
    LoadDefaultLayerVipInfo();
}

// EN: Destructor
// VN: Hàm hủy
PainterSDKRuntime::~PainterSDKRuntime() = default;

// EN: Populate built-in portrait grading palettes
// VN: Khởi tạo các bảng màu chân dung mẫu tích hợp sẵn
void PainterSDKRuntime::LoadDefaultPalettes() {
    m_palettes["natural_portrait"] = {"natural_portrait", "Natural Clean", 0.05f, 0.0f, 1.05f, 1.02f};
    m_palettes["warm_film"]        = {"warm_film", "Warm Golden Film", 0.35f, 0.10f, 1.15f, 1.08f};
    m_palettes["cool_cyber"]       = {"cool_cyber", "Cool Cyber Blue", -0.40f, 0.20f, 1.25f, 1.12f};
    m_palettes["soft_glow"]        = {"soft_glow", "Soft Peach Glow", 0.20f, -0.05f, 1.10f, 0.98f};
    m_palettes["tokyo_night"]      = {"tokyo_night", "Tokyo Night Cinema", -0.25f, 0.15f, 1.30f, 1.15f};
}

// EN: Populate default VIP property constraints for retouch layers (Opcode 0x8d2e0)
// VN: Thiết lập ràng buộc quyền VIP mặc định cho các layer tút tát (Opcode 0x8d2e0)
void PainterSDKRuntime::LoadDefaultLayerVipInfo() {
    m_layer_props[100] = {100, false, 0, "BaseCanvasLayer"};
    m_layer_props[101] = {101, false, 0, "StandardSkinSmooth"};
    m_layer_props[102] = {102, false, 0, "BasicFaceSlim"};
    m_layer_props[201] = {201, true,  1, "ProEyeEnlarge4K"};
    m_layer_props[202] = {202, true,  1, "TeethWhiteningPro"};
    m_layer_props[301] = {301, true,  2, "BodyHermiteReshaper"};
    m_layer_props[302] = {302, true,  2, "VipCinemaGradePalettes"};
}

// EN: Initialize runtime with canvas dimensions (Opcode 0x847c0: JavaToCpp)
// VN: Khởi tạo môi trường với kích thước khung vẽ (Opcode 0x847c0: JavaToCpp)
bool PainterSDKRuntime::Initialize(int32_t width, int32_t height) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (width <= 0 || height <= 0) {
        return false;
    }
    m_canvas_width = width;
    m_canvas_height = height;
    m_initialized = true;
    return true;
}

// EN: Apply recommended palette preset by identifier (Opcode 0x133e40)
// VN: Áp dụng bảng màu chân dung đề xuất theo mã định danh (Opcode 0x133e40)
bool PainterSDKRuntime::ApplyRecommendPalette(const std::string& palette_id) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_palettes.find(palette_id);
    if (it == m_palettes.end()) {
        return false;
    }

    m_active_palette_id = palette_id;
    const ColorPalette& pal = it->second;

    // Apply color tone adjustments to current beauty engine
    BeautyIntensityParams params = m_beauty_engine.GetIntensities();
    if (pal.warm_cool_bias > 0.0f) {
        params.whitening_intensity = std::clamp(params.whitening_intensity * 0.9f, 0.0f, 1.0f);
    } else {
        params.whitening_intensity = std::clamp(params.whitening_intensity * 1.15f, 0.0f, 1.0f);
    }
    m_beauty_engine.SetIntensities(params);

    return true;
}

// EN: Configure composer effect intensity descriptors (Opcode 0xcbc80)
// VN: Thiết lập thông số các bộ lọc hiệu ứng trong composer (Opcode 0xcbc80)
void PainterSDKRuntime::SetComposerIntensities(const std::vector<painter::ComposerIntensityDesc>& descriptors) {
    std::lock_guard<std::mutex> lock(m_mutex);
    BeautyIntensityParams params = m_beauty_engine.GetIntensities();

    for (const auto& desc : descriptors) {
        if (desc.tag == "smooth" || desc.tag == "skin_smooth") {
            params.smooth_intensity = desc.intensity;
        } else if (desc.tag == "whitening" || desc.tag == "skin_whiten") {
            params.whitening_intensity = desc.intensity;
        } else if (desc.tag == "face_slim" || desc.tag == "slim") {
            params.face_slim_intensity = desc.intensity;
        } else if (desc.tag == "eye_enlarge" || desc.tag == "big_eye") {
            params.eye_enlarge_intensity = desc.intensity;
        } else if (desc.tag == "teeth_whiten" || desc.tag == "teeth") {
            params.teeth_whiten_intensity = desc.intensity;
        } else if (desc.tag == "lipstick" || desc.tag == "lip") {
            params.lipstick_intensity = desc.intensity;
        }
    }

    m_beauty_engine.SetIntensities(params);
}

// EN: Remove active makeup composer filters (Opcode 0xcb9b8)
// VN: Loại bỏ bộ hòa trộn hiệu ứng trang điểm đang áp dụng (Opcode 0xcb9b8)
void PainterSDKRuntime::RemoveMakeupComposer() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_beauty_engine.ResetMakeupComposer();
    m_active_palette_id.clear();
}

// EN: Set manual body reshaping intensities (Opcode 0x153190)
// VN: Cấu hình thủ công cường độ định hình cơ thể (Opcode 0x153190)
void PainterSDKRuntime::SetManualBodyIntensity(float leg_ratio, float waist_ratio) {
    std::lock_guard<std::mutex> lock(m_mutex);
    BodyReshapeParams params = m_body_reshaper.GetParams();
    params.leg_extend_ratio = leg_ratio;
    params.waist_slim_ratio = waist_ratio;
    m_body_reshaper.SetParams(params);
}

// EN: Transform normalized coordinates [0, 1] through deformation mesh (Opcode 0x153168)
// VN: Biến đổi tọa độ chuẩn hóa [0, 1] qua lưới biến dạng (Opcode 0x153168)
Point2F PainterSDKRuntime::TransformNormalizedCoordinates(float norm_x, float norm_y) {
    std::lock_guard<std::mutex> lock(m_mutex);
    float pixel_x = norm_x * static_cast<float>(m_canvas_width);
    float pixel_y = norm_y * static_cast<float>(m_canvas_height);

    Point2F mapped = m_body_reshaper.ComputeWarpMapping(pixel_x, pixel_y, m_canvas_width, m_canvas_height);

    float out_norm_x = mapped.x / static_cast<float>(m_canvas_width);
    float out_norm_y = mapped.y / static_cast<float>(m_canvas_height);

    return Point2F(out_norm_x, out_norm_y);
}

// EN: Query VIP feature availability for a given layer (Opcode 0x8d2e0)
// VN: Truy vấn trạng thái quyền VIP cho layer tương ứng (Opcode 0x8d2e0)
LayerPropInfo PainterSDKRuntime::GetAvailableVipInfo(int32_t layer_id) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_layer_props.find(layer_id);
    if (it != m_layer_props.end()) {
        return it->second;
    }
    LayerPropInfo default_prop;
    default_prop.layer_id = layer_id;
    default_prop.is_vip_feature = false;
    default_prop.min_vip_level = 0;
    default_prop.feature_name = "UnknownLayer";
    return default_prop;
}

// EN: Register a layer property with VIP level requirement
// VN: Đăng ký thuộc tính layer với cấp độ VIP yêu cầu
void PainterSDKRuntime::RegisterLayerProperty(const LayerPropInfo& prop) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_layer_props[prop.layer_id] = prop;
}

} // namespace retouch_sdk

// ===================================================================================
// JNI EXPORT IMPLEMENTATION (Opcode references from libretouch_sdk.so)
// ===================================================================================

extern "C" {

// EN: JNI export: Apply recommended palette preset (Opcode 0x133e40)
// VN: Hàm xuất JNI: Áp dụng bảng màu chân dung đề xuất (Opcode 0x133e40)
JNIEXPORT void JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeApplyRecommendPalette(
    JNIEnv *env, jobject /*thiz*/, jstring j_palette_id) {
    if (!env || !j_palette_id) return;
    const char* str = env->GetStringUTFChars(j_palette_id, nullptr);
    if (str) {
        retouch_sdk::PainterSDKRuntime::GetInstance().ApplyRecommendPalette(str);
        env->ReleaseStringUTFChars(j_palette_id, str);
    }
}

// EN: JNI export: Remove active makeup composer (Opcode 0xcb9b8)
// VN: Hàm xuất JNI: Loại bỏ bộ hòa trộn trang điểm (Opcode 0xcb9b8)
JNIEXPORT void JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeRemoveMakeupComposer(
    JNIEnv * /*env*/, jobject /*thiz*/) {
    retouch_sdk::PainterSDKRuntime::GetInstance().RemoveMakeupComposer();
}

// EN: JNI export: Set composer effect intensities (Opcode 0xcbc80)
// VN: Hàm xuất JNI: Cấu hình cường độ các hiệu ứng làm đẹp (Opcode 0xcbc80)
JNIEXPORT void JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeSetIntensities(
    JNIEnv *env, jobject /*thiz*/, jobjectArray j_tags, jfloatArray j_values) {
    if (!env || !j_tags || !j_values) return;

    jsize count_tags = env->GetArrayLength(j_tags);
    jsize count_vals = env->GetArrayLength(j_values);
    jsize count = std::min(count_tags, count_vals);

    jfloat* vals = env->GetFloatArrayElements(j_values, nullptr);
    if (!vals) return;

    std::vector<painter::ComposerIntensityDesc> descs;
    descs.reserve(count);

    for (jsize i = 0; i < count; ++i) {
        auto j_str = static_cast<jstring>(env->GetObjectArrayElement(j_tags, i));
        if (j_str) {
            const char* tag_cstr = env->GetStringUTFChars(j_str, nullptr);
            if (tag_cstr) {
                painter::ComposerIntensityDesc desc;
                desc.tag = tag_cstr;
                desc.intensity = vals[i];
                desc.sub_type = 0;
                descs.push_back(desc);
                env->ReleaseStringUTFChars(j_str, tag_cstr);
            }
            env->DeleteLocalRef(j_str);
        }
    }

    env->ReleaseFloatArrayElements(j_values, vals, JNI_ABORT);
    retouch_sdk::PainterSDKRuntime::GetInstance().SetComposerIntensities(descs);
}

// EN: JNI export: Transform normalized coordinates [0, 1] through warp mesh (Opcode 0x153168)
// VN: Hàm xuất JNI: Biến đổi tọa độ chuẩn hóa [0, 1] qua lưới biến dạng (Opcode 0x153168)
JNIEXPORT jfloatArray JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeTransformNormalizedCoordinates(
    JNIEnv *env, jobject /*thiz*/, jfloat norm_x, jfloat norm_y) {
    if (!env) return nullptr;

    retouch_sdk::Point2F out_pt = retouch_sdk::PainterSDKRuntime::GetInstance().TransformNormalizedCoordinates(norm_x, norm_y);

    jfloatArray result = env->NewFloatArray(2);
    if (!result) return nullptr;

    jfloat buffer[2] = {out_pt.x, out_pt.y};
    env->SetFloatArrayRegion(result, 0, 2, buffer);
    return result;
}

// EN: JNI export: Set manual body reshape intensity (Opcode 0x153190)
// VN: Hàm xuất JNI: Cấu hình thủ công cường độ định hình cơ thể (Opcode 0x153190)
JNIEXPORT void JNICALL Java_com_bytedance_ies_painter_sdk_jni_PainterInterface_nativeSetManualBodyIntensity(
    JNIEnv * /*env*/, jobject /*thiz*/, jfloat leg_ratio, jfloat waist_ratio) {
    retouch_sdk::PainterSDKRuntime::GetInstance().SetManualBodyIntensity(leg_ratio, waist_ratio);
}

} // extern "C"
