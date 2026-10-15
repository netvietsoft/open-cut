// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_beauty_engine.h
// Description: Facial beauty engine, skin smoothing, whitening, slimming, eye enlargement
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "retouch_types.h"
#include <vector>
#include <cstdint>
#include <memory>

namespace retouch_sdk {

// EN: RGBA image buffer container for image processing
// VN: Bộ đệm ảnh định dạng RGBA phục vụ xử lý hiệu ứng
struct ImageBuffer {
    int32_t width = 0;
    int32_t height = 0;
    int32_t stride = 0;
    std::vector<uint8_t> data;

    ImageBuffer() = default;
    ImageBuffer(int32_t w, int32_t h) : width(w), height(h), stride(w * 4), data(w * h * 4, 0) {}

    uint8_t* GetPixel(int32_t x, int32_t y) {
        if (x < 0 || x >= width || y < 0 || y >= height) return nullptr;
        return &data[y * stride + x * 4];
    }

    const uint8_t* GetPixel(int32_t x, int32_t y) const {
        if (x < 0 || x >= width || y < 0 || y >= height) return nullptr;
        return &data[y * stride + x * 4];
    }
};

// EN: Facial Beauty & Retouch Processing Engine
// VN: Động cơ xử lý làm đẹp khuôn mặt và tút tát chân dung
class BeautyEngine {
public:
    BeautyEngine();
    ~BeautyEngine();

    // EN: Set beauty intensity parameters (Opcode 0xcbc80)
    // VN: Thiết lập các tham số cường độ làm đẹp (Opcode 0xcbc80)
    void SetIntensities(const BeautyIntensityParams& params);

    // EN: Get current beauty parameters
    // VN: Lấy cấu hình tham số làm đẹp hiện hành
    const BeautyIntensityParams& GetIntensities() const { return m_params; }

    // EN: Generate skin tone probability mask using YCrCb color space
    // VN: Tạo mặt nạ xác suất màu da sử dụng không gian màu YCrCb
    std::vector<float> GenerateSkinMask(const ImageBuffer& src);

    // EN: Apply edge-preserving bilateral skin smoothing (Opcode 0xcbc80)
    // VN: Áp dụng bộ lọc song phương làm mịn da bảo toàn cạnh (Opcode 0xcbc80)
    void ApplySkinSmoothing(const ImageBuffer& src, ImageBuffer& dst, const std::vector<float>& skin_mask);

    // EN: Apply skin tone whitening with luminance curve adjustment
    // VN: Làm trắng da thông qua hiệu chỉnh đường cong độ sáng
    void ApplySkinWhitening(ImageBuffer& img, const std::vector<float>& skin_mask);

    // EN: Apply teeth whitening inside mouth landmark contour
    // VN: Tẩy trắng răng trong phạm vi chu vi điểm mốc khuôn miệng
    void ApplyTeethWhitening(ImageBuffer& img, const Face106Landmarks& landmarks);

    // EN: Apply radial mesh warp for eye enlargement (Opcode 0x153168)
    // VN: Biến dạng lưới bán kính phóng to mắt tự nhiên (Opcode 0x153168)
    void ApplyEyeEnlargement(const ImageBuffer& src, ImageBuffer& dst, const Face106Landmarks& landmarks);

    // EN: Apply jawline slimming vector deformation toward face center
    // VN: Áp dụng trường vector gọt cằm thon gọn mặt hướng về tâm khuôn mặt
    void ApplyFaceSlimming(const ImageBuffer& src, ImageBuffer& dst, const Face106Landmarks& landmarks);

    // EN: Apply lipstick color blending with natural highlights
    // VN: Hòa trộn màu son môi tự nhiên giữ lại vân môi và độ phản quang
    void ApplyLipstick(ImageBuffer& img, const Face106Landmarks& landmarks);

    // EN: Execute complete beauty retouch pipeline on input image
    // VN: Thực thi toàn bộ chu trình xử lý làm đẹp lên ảnh đầu vào
    bool ProcessFrame(const ImageBuffer& src, ImageBuffer& dst, const Face106Landmarks& landmarks);

    // EN: Reset/remove makeup composer descriptors (Opcode 0xcb9b8)
    // VN: Đặt lại và loại bỏ bộ hòa trộn hiệu ứng trang điểm (Opcode 0xcb9b8)
    void ResetMakeupComposer();

private:
    BeautyIntensityParams m_params;
    float m_gaussian_spatial[5][5];

    void InitSpatialWeights(float sigma_s);
    bool IsInPolygon(float px, float py, const std::vector<Point2F>& polygon) const;
};

} // namespace retouch_sdk
