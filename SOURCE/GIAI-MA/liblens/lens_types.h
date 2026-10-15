// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_types.h
// Description: Core data types, enums, pixel formats, and algorithm configurations
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>

namespace LENS::FRAMEWORK {

// EN: Supported Lens algorithm types in ByteDance Lens Engine
// VN: Các kiểu thuật toán Lens được hỗ trợ trong động cơ ByteDance Lens
enum class LensAlgorithmType : int32_t {
    LENS_ALGO_UNKNOWN = 0,
    LENS_ALGO_VHDR = 1,          // Video HDR / Local Tone Mapping (Khớp LensAlgorithmVHDR)
    LENS_ALGO_VSM = 2,           // Video Super Resolution (Khớp LensAlgorithmVSM)
    LENS_ALGO_VMB = 3,           // Video Motion Blur / Deblur (Khớp LensAlgorithmVMB)
    LENS_ALGO_NN_DENOISE = 4,    // Neural Network Video Denoising (Khớp VideoDenoiseNNProcess)
    LENS_ALGO_BILATERAL = 5      // Hierarchical Bilateral Skin Smoothing (Khớp HierarchicalBilateralFilter)
};

// EN: Color and pixel format definitions
// VN: Định dạng điểm ảnh và không gian màu
enum class LensPixelFormat : int32_t {
    PIXEL_FMT_RGBA8888 = 1,
    PIXEL_FMT_RGB888 = 2,
    PIXEL_FMT_YUV420P = 3,
    PIXEL_FMT_NV12 = 4,
    PIXEL_FMT_NV21 = 5
};

// EN: Execution backend hardware mode
// VN: Chế độ phần cứng thực thi giải thuật
enum class LensBackendType : int32_t {
    BACKEND_CPU = 0,
    BACKEND_OPENCL = 1,
    BACKEND_VULKAN = 2,
    BACKEND_NEURAL_DSP = 3
};

// EN: Configuration JSON metadata struct corresponding to binary offset 0x2c68c0
// VN: Cấu trúc thông tin JSON cấu hình giải thuật khớp địa chỉ nhị phân 0x2c68c0
struct LensAlgorithmJsonInfo {
    int32_t algorithm_id = 0;
    int32_t width = 0;
    int32_t height = 0;
    int32_t channels = 4;
    LensBackendType backend = LensBackendType::BACKEND_CPU;
    float param_strength = 1.0f;
    float param_radius = 5.0f;
    float param_sigma_spatial = 3.0f;
    float param_sigma_range = 0.15f;
    bool enable_temporal_consistency = true;
    std::string model_path = "";
};

// EN: Image frame container for input and output tensors
// VN: Khung chứa dữ liệu khung hình cho tensor đầu vào và đầu ra
struct LensImageFrame {
    int32_t width = 0;
    int32_t height = 0;
    int32_t channels = 4;
    int32_t stride = 0;
    LensPixelFormat format = LensPixelFormat::PIXEL_FMT_RGBA8888;
    std::vector<uint8_t> data;

    LensImageFrame() = default;
    LensImageFrame(int32_t w, int32_t h, int32_t c = 4)
        : width(w), height(h), channels(c), stride(w * c), data(w * h * c, 0) {}

    bool isValid() const {
        return width > 0 && height > 0 && !data.empty() && data.size() >= static_cast<size_t>(width * height * channels);
    }
};

} // namespace LENS::FRAMEWORK
