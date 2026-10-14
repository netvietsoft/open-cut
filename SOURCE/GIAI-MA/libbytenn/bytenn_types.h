// ======================================================================
// RECONSTRUCTED HEADER: bytenn_types.h
// Library: libbytenn.so (ByteDance ByteNN Inference Engine)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Fundamental type definitions, enums, tensor metadata, execution
//   backends, and quantization parameters reverse-engineered from
//   ByteDance ByteNN inference engine.
//
// Mô tả (Tiếng Việt):
//   Định nghĩa các kiểu dữ liệu nền tảng, enum, metadata tensor,
//   backend thực thi và tham số lượng tử hóa được dịch ngược từ
//   engine suy luận ByteDance ByteNN.
// ======================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>

namespace NextAI::OpenCut::bytenn {

// ----------------------------------------------------------------------
// ByteNN Data Types (Kiểu dữ liệu Tensor ByteNN)
// Binary Table: 0x263b98 in libbytenn.so
// ----------------------------------------------------------------------
enum class DataType : int32_t {
    INT8     = 0,  // 8-bit signed integer (1 byte) - Lượng tử hóa int8
    UINT8    = 1,  // 8-bit unsigned integer (1 byte) - Ảnh RGB/RGBA hoặc uint8
    FLOAT16  = 2,  // 16-bit IEEE 754 half precision (2 bytes) - Dấu phẩy động bán chính xác
    INT16    = 3,  // 16-bit signed integer (2 bytes)
    FLOAT32  = 4,  // 32-bit IEEE 754 single precision (4 bytes) - Chuẩn dấu phẩy động
    BFLOAT16 = 5,  // 16-bit Brain floating point (2 bytes)
    INT64    = 6,  // 64-bit signed integer / double (8 bytes)
    INT32    = 7   // 32-bit signed integer (4 bytes)
};

// ----------------------------------------------------------------------
// Tensor Memory Formats (Định dạng bố cục bộ nhớ Tensor)
// ----------------------------------------------------------------------
enum class DataFormat : int32_t {
    NCHW   = 0,  // Batch, Channels, Height, Width (Standard PyTorch / ByteNN default)
    NHWC   = 1,  // Batch, Height, Width, Channels (Standard TensorFlow / Mobile GPU)
    NC4HW4 = 2,  // Channel blocked by 4 (Optimized for ARM NEON SIMD / OpenCL image2d)
    NC8HW8 = 3   // Channel blocked by 8 (Optimized for AVX2 / Vulkan sub-groups)
};

// ----------------------------------------------------------------------
// Execution Forward Types (Backend thực thi mô hình)
// Matches ByteDance log: "Run ByteNN with %s forward type."
// ----------------------------------------------------------------------
enum class ForwardType : int32_t {
    FORWARD_CPU    = 0,  // ARM64 NEON CPU runtime (with FP16 & DotProd acceleration)
    FORWARD_OPENCL = 1,  // Adreno / Mali GPU OpenCL backend
    FORWARD_DSP    = 2,  // Qualcomm Hexagon DSP / HTA (libbytenn_dsp.so)
    FORWARD_APU    = 3,  // MediaTek APU / NeuroPilot (libbytenn_apu.so)
    FORWARD_NPU    = 4,  // Dedicated Neural Processing Unit
    FORWARD_METAL  = 5,  // Apple Metal (iOS / macOS target)
    FORWARD_VULKAN = 6   // Cross-platform Vulkan compute backend
};

// ----------------------------------------------------------------------
// Activation Function Types (Các hàm kích hoạt phi tuyến tính)
// ----------------------------------------------------------------------
enum class ActivationType : int32_t {
    NONE         = 0,
    RELU         = 1,  // f(x) = max(0, x)
    RELU6        = 2,  // f(x) = min(max(0, x), 6)
    LEAKY_RELU   = 3,  // f(x) = x >= 0 ? x : alpha * x
    HARD_SIGMOID = 4,  // f(x) = clamp((x + 3) / 6, 0, 1) (ReluHardSigmoid)
    HARD_SWISH   = 5,  // f(x) = x * clamp((x + 3) / 6, 0, 1) (ReluHardSwish)
    SIGMOID      = 6,  // f(x) = 1 / (1 + exp(-x))
    TANH         = 7,  // f(x) = tanh(x)
    PRELU        = 8   // f(x) = x >= 0 ? x : weight[c] * x (bPRelu)
};

// ----------------------------------------------------------------------
// Pooling Types (Kiểu gộp không gian không tham số)
// ----------------------------------------------------------------------
enum class PoolingType : int32_t {
    MAX            = 0,
    AVERAGE        = 1,
    GLOBAL_MAX     = 2,
    GLOBAL_AVERAGE = 3
};

// ----------------------------------------------------------------------
// Precision Policy (Chính sách độ chính xác số học)
// ----------------------------------------------------------------------
enum class PrecisionType : int32_t {
    PRECISION_NORMAL = 0,  // FP32 mode
    PRECISION_HIGH   = 1,  // FP32 with strict IEEE rounding
    PRECISION_LOW    = 2   // FP16 / BF16 mixed-precision
};

// ----------------------------------------------------------------------
// Optimizer Types (Kiểu bộ tối ưu hóa khi huấn luyện on-device)
// ----------------------------------------------------------------------
enum class OptimizerType : int32_t {
    SGD      = 0,
    ADAM     = 1,
    RMSPROP  = 2,
    ADAGRAD  = 3
};

// ----------------------------------------------------------------------
// Property Types (Thuộc tính cấu hình động Engine)
// ----------------------------------------------------------------------
enum class PropertyType : int32_t {
    PROP_THREAD_NUM          = 0x1001,
    PROP_CPU_AFFINITY        = 0x1002,
    PROP_POWER_MODE          = 0x1003,
    PROP_GRAPH_OPTIMIZE      = 0x1004,
    PROP_MEMORY_REUSE        = 0x1005,
    PROP_DYNAMIC_BATCH       = 0x1006,
    PROP_GPU_QUEUE_PRIORITY  = 0x1007,
    PROP_TEXTURE_IO_ASYNC    = 0x1008
};

// ----------------------------------------------------------------------
// Device I/O Types (Loại cổng nhập xuất thiết bị)
// ----------------------------------------------------------------------
enum class DeviceIOType : int32_t {
    HOST_BUFFER    = 0,
    OPENCL_IMAGE   = 1,
    AHARDWARE_BUFFER = 2,
    EGL_TEXTURE    = 3
};

// ----------------------------------------------------------------------
// Loss Information for On-Device Fine-Tuning
// ----------------------------------------------------------------------
struct LossInfo {
    std::string layer_name;
    int32_t loss_type{0}; // 0: CrossEntropy, 1: MSE, 2: SmoothL1
    float weight{1.0f};
};

// ----------------------------------------------------------------------
// Quantization Parameters (Tham số lượng tử hóa số nguyên)
// Formula (EN): q = clamp(round(x / scale) + zero_point, q_min, q_max)
// Formula (VN): x = (q - zero_point) * scale
// ----------------------------------------------------------------------
struct QuantParams {
    float scale{1.0f};
    int32_t zero_point{0};
    int32_t q_min{-128};
    int32_t q_max{127};
    bool is_quantized{false};
};

// ----------------------------------------------------------------------
// System Settings (Thiết lập môi trường phần cứng hệ thống)
// ----------------------------------------------------------------------
struct SystemSetting {
    int32_t cpu_power_level{0};     // 0: Normal, 1: Performance, 2: BatterySaving
    int32_t preferred_threads{4};    // Số luồng ưu tiên
    bool enable_fp16{true};          // Kích hoạt FP16 nếu phần cứng hỗ trợ
    bool enable_dotprod{true};       // Kích hoạt Dot Product (sdot/udot)
    std::string cache_path{""};      // Đường dẫn lưu cache OpenCL program
};

} // namespace NextAI::OpenCut::bytenn
