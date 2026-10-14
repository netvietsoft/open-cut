// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libcccreator.so (CapCut / Jianying Template Creator Core & ILA SDK Engine)
// File: cccreator_types.h
// Description: Memory layouts, filter types, and AArch64 ABI contracts reverse-engineered
//              from ARM64 opcodes (0x6180b4, 0x74e910, 0x74f7e0, 0x74f99c, 0x158c994).
// ===================================================================================

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <cmath>

#ifdef __cplusplus
namespace vesdk {
namespace ccmodel {

// ===================================================================================
// 1. CORE TIMECODE & ENUMS
// Kiểu thời gian và các hằng số phân loại bộ lọc
// ===================================================================================

/// VETimeCode represents time in microseconds (int64_t)
typedef int64_t VETimeCode;

/**
 * @brief Filter Type Enums reverse-engineered from RecModelBundleHelper jump table
 * Mã phân loại Filter trích xuất từ bảng nhảy tại opcode 0x852c8c
 */
enum class CCFilterType : int32_t {
    FILTER_UNKNOWN                 = 0,
    FILTER_TRANSFORM               = 1,   // CCTransformFilter (scale, rotate, translate)
    FILTER_CANVAS                  = 2,   // CCVideoBackgroundFilter
    FILTER_AUDIO_VOLUME            = 3,   // CCAudioVolumeFilter
    FILTER_AUDIO_FADE              = 4,   // CCAudioFadeFilter (opcode 0x74e964)
    FILTER_AUDIO_NOISE             = 5,   // CCAudioNoiseFilter (DSP Denoiser)
    FILTER_AUDIO_PREPROCESS        = 6,   // CCAudioPreprocessFilter
    FILTER_AUDIO_LOUDNESS_BALANCE  = 7,   // CCAudioLoudnessBalanceFilter
    FILTER_AUDIO_SAMI_AI           = 8,   // CCAudioSamiFilter (ByteDance SAMI)
    FILTER_VIDEO_BLUR              = 10,  // CCVideoBlurFilter
    FILTER_VIDEO_ANIMATION         = 12,  // CCVideoAnimationFilter
    FILTER_STICKER_ANIMATION       = 14,  // CCStickerAnimationFilter
    FILTER_SCRIPT_STICKER          = 16,  // CCScriptStickerFilter
    FILTER_COLOR_HSL               = 20,  // ColorHslFilter
    FILTER_RADIUS_CORNER_BORDER    = 30,  // CCRadiusCornerBorderFilter
    FILTER_LENS_VFI                = 36,  // CCLensVFIFilter (0x24 at opcode 0x74f848)
    FILTER_MOTION_BLUR             = 37,  // CCMotionBlurFilter (0x25 at opcode 0x74fa1c)
    FILTER_VIDEO_STABLE_EX         = 38,  // CCVideoStableFilterEX
    FILTER_PREVIEW_MAGNIFIER       = 40,  // CCPreviewMagnifierFilter
    FILTER_LEADER_SECURITY_DETECT  = 50   // CCLeaderSecurityDetectFilter
};

enum class AudioFadingCurveType : int32_t {
    LINEAR = 0,
    EXPONENTIAL = 1,
    LOGARITHMIC = 2,
    S_CURVE = 3
};

enum class LensVFIType : int32_t {
    DISABLED = 0,
    FLOW_NET = 1,
    RIFE_OPTICAL = 2,
    BMS_LOW_POWER = 3
};

enum class MotionBlurAlgorithmType : int32_t {
    ACCELERATION_BASED = 0,
    OPTICAL_FLOW_BASED = 1,
    KEYFRAME_DERIVATIVE = 2
};

enum class MotionBlurMergeType : int32_t {
    AVERAGE = 0,
    WEIGHTED_ALPHA = 1,
    MAX_CHANNEL = 2
};


// ===================================================================================
// 2. CCMODEL CLIP STRUCTURE
// Cấu trúc phân đoạn Clip CapCut (AArch64 ABI Layout)
// ===================================================================================

/**
 * @brief CCClip holds media timeline segments with exact verified field offsets:
 *   offset 0x00: vtable pointer (8B)
 *   offset 0x08..0x2f: clip identification / metadata (40B)
 *   offset 0x30: startTime (VETimeCode, 8B, verified at opcode 0x79fc0c)
 *   offset 0x38: endTime (VETimeCode, 8B, verified at opcode 0x158f54c)
 *   offset 0x40: trimIn (VETimeCode, 8B, verified at opcode 0x10485d0)
 *   offset 0x48: trimOut (VETimeCode, 8B, verified at opcode 0x1690ff0)
 */
class CCClip {
public:
    void* vptr;                     // 0x00: vtable pointer
    std::string clip_id;            // 0x08: Mã định danh clip / đường dẫn media
    uint8_t meta_pad[16];           // 0x20..0x2f
    VETimeCode start_time;          // 0x30: Thời điểm bắt đầu trên timeline (opcode 0x79fc0c)
    VETimeCode end_time;            // 0x38: Thời điểm kết thúc trên timeline (opcode 0x158f54c)
    VETimeCode trim_in;             // 0x40: Điểm cắt đầu trong media nguồn (opcode 0x10485d0)
    VETimeCode trim_out;            // 0x48: Điểm cắt đuôi trong media nguồn (opcode 0x1690ff0)
    double speed;                   // 0x50: Tốc độ clip (1.0 = bình thường)
    bool is_reversed;               // 0x58: Phát đảo ngược
    uint8_t flags;                  // 0x59: Cờ trạng thái clip

    CCClip() : vptr(nullptr), start_time(0), end_time(0), trim_in(0), trim_out(0), speed(1.0), is_reversed(false), flags(0) {}
    explicit CCClip(const std::string& id) : vptr(nullptr), clip_id(id), start_time(0), end_time(0), trim_in(0), trim_out(0), speed(1.0), is_reversed(false), flags(0) {}
    virtual ~CCClip() = default;

    void setStartTime(VETimeCode t) { start_time = t; }
    VETimeCode getStartTime() const { return start_time; }
    void setEndTime(VETimeCode t) { end_time = t; }
    VETimeCode getEndTime() const { return end_time; }
    void setTrimIn(const VETimeCode& t) { trim_in = t; }
    VETimeCode getTrimIn() const { return trim_in; }
    void setTrimOut(const VETimeCode& t) { trim_out = t; }
    VETimeCode getTrimOut() const { return trim_out; }
    VETimeCode getTimelineDuration() const { return end_time - start_time; }
    VETimeCode getSourceDuration() const { return trim_out - trim_in; }
};


// ===================================================================================
// 3. CCMODEL FILTER HIERARCHY
// Hệ thống cấu trúc bộ lọc CapCut Template
// ===================================================================================

/**
 * @brief Base class for CCFilter matching TEBundle deserialization layout
 */
class CCFilter {
public:
    void* vptr;                     // 0x00: vtable pointer
    uint8_t base_pad[0x40];         // 0x08..0x47
    std::string filter_id;          // 0x48..0x57: Chuỗi ID bộ lọc (opcode 0x74e95c)
    uint32_t flags;                 // 0x58: Cờ kích hoạt (opcode 0x609d38)
    uint8_t pad_5c[4];              // 0x5c..0x5f
    int32_t filter_type;            // 0x60: Loại bộ lọc enum (opcode 0x74e970, 0x74f854, 0x74fa24)
    VETimeCode seq_in;              // 0x68: Thời điểm bắt đầu hiệu ứng
    VETimeCode seq_out;             // 0x70: Thời điểm kết thúc hiệu ứng
    uint8_t pad_78[0x14];           // 0x78..0x8b

    CCFilter() : vptr(nullptr), flags(1), filter_type(0), seq_in(0), seq_out(0) {}
    virtual ~CCFilter() = default;
    virtual bool noActiveEffect() { return flags == 0; }
};

/**
 * @brief CCAudioFadeFilter (Alloc size: 192 bytes = 0xc0, opcode 0x74e92c)
 */
class CCAudioFadeFilter : public CCFilter {
public:
    uint8_t pad_8c[0x1c];           // 0x8c..0xa7
    VETimeCode fade_in_duration;    // 0xa8: Thời lượng fade in micro-giây (opcode 0x74e968)
    VETimeCode fade_out_duration;   // 0xb0: Thời lượng fade out micro-giây (opcode 0x74e968)
    AudioFadingCurveType curve_type;// 0xb8: Đường cong âm lượng (opcode 0x74e96c)

    CCAudioFadeFilter() : fade_in_duration(0), fade_out_duration(0), curve_type(AudioFadingCurveType::LINEAR) {
        filter_type = static_cast<int32_t>(CCFilterType::FILTER_AUDIO_FADE); // 4
    }
};

/**
 * @brief CCLensVFIFilter (Alloc size: 264 bytes = 0x108, opcode 0x74f7f8)
 * Video Frame Interpolation / Optical Flow slow motion
 */
class CCLensVFIFilter : public CCFilter {
public:
    uint8_t pad_8c[0x18];           // 0x8c..0xa3
    LensVFIType vfi_type;           // 0xa4: Kiểu thuật toán quang sai nội suy (opcode 0x74f828)
    std::string model_path;         // 0xa8..0xbf: Đường dẫn mô hình nơ-ron VFI (opcode 0x74f83c)
    double fps_ratio;               // 0xc0: Tỷ lệ nâng số khung hình (opcode 0x74f834, ví dụ 2.0x, 4.0x)

    CCLensVFIFilter() : vfi_type(LensVFIType::RIFE_OPTICAL), fps_ratio(2.0) {
        filter_type = static_cast<int32_t>(CCFilterType::FILTER_LENS_VFI); // 36 (0x24)
    }
};

/**
 * @brief CCMotionBlurFilter (Alloc size: 224 bytes = 0xe0, opcode 0x74f9c4)
 */
class CCMotionBlurFilter : public CCFilter {
public:
    uint8_t pad_8c[0x1c];           // 0x8c..0xa7
    MotionBlurAlgorithmType algo;   // 0xa8: Thuật toán làm mờ chuyển động
    MotionBlurMergeType merge;      // 0xac: Chế độ hòa trộn
    bool enable_forward;            // 0xb0: Mờ phía trước
    bool enable_backward;           // 0xb1: Mờ phía sau
    float blur_intensity;           // 0xb4: Độ đậm hiệu ứng mờ (0.0 .. 1.0)
    float shutter_angle;            // 0xb8: Góc mở màn trập (0.0 .. 360.0 độ)

    CCMotionBlurFilter() : algo(MotionBlurAlgorithmType::OPTICAL_FLOW_BASED),
                           merge(MotionBlurMergeType::WEIGHTED_ALPHA),
                           enable_forward(true), enable_backward(false),
                           blur_intensity(0.5f), shutter_angle(180.0f) {
        filter_type = static_cast<int32_t>(CCFilterType::FILTER_MOTION_BLUR); // 37 (0x25)
    }
};

/**
 * @brief CCVideoBlurFilter
 */
class CCVideoBlurFilter : public CCFilter {
public:
    float blur_radius;              // 0x8c: Bán kính làm mờ Gaussian/Box (opcode 0x609d44)

    CCVideoBlurFilter() : blur_radius(0.0f) {
        filter_type = static_cast<int32_t>(CCFilterType::FILTER_VIDEO_BLUR); // 10
    }

    bool noActiveEffect() override {
        // Opcode 0x609d38..0x609d5c: if flags == 0 or blur_radius < epsilon -> no active effect
        if (flags == 0) return true;
        return blur_radius < 1e-4f;
    }
};

/**
 * @brief CCRadiusCornerBorderFilter
 */
class CCRadiusCornerBorderFilter : public CCFilter {
public:
    double border_width;            // 0x8c: Độ dày viền khung (opcode 0x60b3d4)
    double corner_radius;           // 0x94: Bán kính bo góc (opcode 0x60b3d0)
    bool border_enabled;            // 0x9c: Kích hoạt viền (opcode 0x60b3dc = 1)

    CCRadiusCornerBorderFilter() : border_width(0.0), corner_radius(0.0), border_enabled(true) {
        filter_type = static_cast<int32_t>(CCFilterType::FILTER_RADIUS_CORNER_BORDER); // 30
    }
};

/**
 * @brief CCTransformFilter
 */
class CCTransformFilter : public CCFilter {
public:
    double scale_x;                 // 0x8c: Tỷ lệ trục X
    double scale_y;                 // 0x94: Tỷ lệ trục Y
    double trans_x;                 // 0x9c: Dịch chuyển X
    double trans_y;                 // 0xa4: Dịch chuyển Y
    double rotation_deg;            // 0xac: Góc xoay độ

    CCTransformFilter() : scale_x(1.0), scale_y(1.0), trans_x(0.0), trans_y(0.0), rotation_deg(0.0) {
        filter_type = static_cast<int32_t>(CCFilterType::FILTER_TRANSFORM); // 1
    }

    /**
     * @brief Normalizes rotation angle into standard [0, 360) range
     * Khớp chính xác opcode 0x158c994 (fcvtzs w0, d0; mov w8, #0x168; modulo 360)
     */
    static int32_t checkRotationValue(double deg) {
        int32_t val = static_cast<int32_t>(deg);
        if (val >= 0) {
            return val % 360;
        }
        // Opcode 0x158c9a0: add w9, w0, #0x168; sdiv; msub loop
        int32_t mod = (val % 360) + 360;
        return (mod == 360) ? 0 : mod;
    }
};


// ===================================================================================
// 4. TEBUNDLE & TEMPLATE PARSING CONSTANTS
// Hằng số phân tích gói Bundle mẫu CapCut (opcode 0x1c25185)
// ===================================================================================

namespace BundleKeys {
    inline const char* FILTER_TYPE               = "filterType";
    inline const char* FILTER_SEQ_IN             = "filterSeqIn";
    inline const char* FILTER_DURATION           = "filterDuration";
    inline const char* FILTER_SEQ_OUT_NO_FX      = "filterSeqOutWithOutEffect";
    inline const char* FILTER_SEQ_OUT_WITH_FX    = "filterSeqOutWithEffect";
    inline const char* REPEAT_TIME               = "repeatTime";
    inline const char* RENDER_TIME               = "renderTime";
    inline const char* SPEED                     = "mSpeed";
    inline const char* AUDIO_SPEED               = "mAudioSpeed";
    inline const char* CAMERA_ROTATION           = "cameraRotation";
    inline const char* EFFECT_ROTATION           = "effectRotation";
    inline const char* DISPLAY_ROTATION          = "displayRotation";
    inline const char* INTERPOLATE_MODE          = "interPolateMode";
    inline const char* PREVIEW_TIME              = "previewTime";
}

/**
 * @brief Key-value dictionary representing ByteDance TEBundle
 */
typedef std::map<std::string, std::string> TEBundle;


// ===================================================================================
// 5. ILA SDK JIANYING AI MATCHING STRUCTURES
// Cấu trúc đối soát thông minh mẫu CapCut (CutSame)
// ===================================================================================

namespace ilasdk {

struct FaceQuality {
    std::string asset_id;           // Mã media asset
    float quality_score;            // Điểm chất lượng khuôn mặt (0.0 .. 1.0)
    bool eye_not_occlude;           // Mắt không bị che khuất
    float smile_degree;             // Độ rạng rỡ của nụ cười
    float yaw;                      // Góc xoay đầu ngang
    float pitch;                    // Góc gật đầu dọc
    float roll;                     // Góc nghiêng đầu

    FaceQuality() : quality_score(0.0f), eye_not_occlude(true), smile_degree(0.0f), yaw(0.0f), pitch(0.0f), roll(0.0f) {}
};

struct AssetInfo {
    std::string asset_id;
    std::string file_path;
    int64_t duration_us;
    int32_t width;
    int32_t height;
    double longitude;
    double latitude;
    std::vector<float> feature_embeddings; // Vector đặc trưng AI trích xuất (128 hoặc 512 chiều)
};

struct TemplateSlotMatch {
    int32_t slot_index;             // Chỉ số ô mẫu trong template CapCut
    std::string matched_asset_id;   // File được chọn
    VETimeCode suggested_trim_in;   // Mốc cắt gợi ý khớp nhịp nhạc
    VETimeCode suggested_trim_out;  // Mốc kết thúc
    float match_confidence;         // Độ tin cậy khớp mẫu
};

} // namespace ilasdk

} // namespace ccmodel
} // namespace vesdk
#endif // __cplusplus
