// ======================================================================
// RECONSTRUCTED HEADER: bytenn_kernels.h
// Library: libbytenn.so (ByteDance ByteNN Inference Engine)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   High-performance CPU operator kernels reverse-engineered from
//   ByteNN disassembly: Conv1x1Dp, DepthwiseSeparableConvV2,
//   ReluHardSwish, ReluHardSigmoid, SoftmaxV3, PoolingV2, QuantV3.
//
// Mô tả (Tiếng Việt):
//   Các kernel toán tử CPU hiệu năng cao được dịch ngược từ ByteNN:
//   Conv1x1Dp, DepthwiseSeparableConvV2, ReluHardSwish, ReluHardSigmoid,
//   SoftmaxV3, PoolingV2, QuantV3.
// ======================================================================

#pragma once

#include "bytenn_tensor.h"
#include <vector>
#include <cmath>
#include <algorithm>

namespace NextAI::OpenCut::bytenn {

// ----------------------------------------------------------------------
// Tham số cho toán tử Convolution (Convolution Parameter Struct)
// ----------------------------------------------------------------------
struct ConvParams {
    int32_t stride_h{1};
    int32_t stride_w{1};
    int32_t pad_top{0};
    int32_t pad_bottom{0};
    int32_t pad_left{0};
    int32_t pad_right{0};
    int32_t dilation_h{1};
    int32_t dilation_w{1};
    int32_t groups{1};
    ActivationType activation{ActivationType::NONE};
    float leaky_relu_alpha{0.1f};
};

// ----------------------------------------------------------------------
// Tham số cho toán tử Pooling (Pooling Parameter Struct)
// ----------------------------------------------------------------------
struct PoolingParams {
    PoolingType type{PoolingType::MAX};
    int32_t kernel_h{2};
    int32_t kernel_w{2};
    int32_t stride_h{2};
    int32_t stride_w{2};
    int32_t pad_top{0};
    int32_t pad_bottom{0};
    int32_t pad_left{0};
    int32_t pad_right{0};
    bool count_include_pad{false};
};

// ----------------------------------------------------------------------
// ByteNN CPU Operator Kernels
// ----------------------------------------------------------------------
class ByteNNKernels {
public:
    // --- 1. CONVOLUTION KERNELS ---
    // cpu_conv1x1_opt / Conv2d1x1DpFloatArm (GEMM Matrix Multiplication)
    static void Conv1x1(const Tensor& input, const Tensor& weight, 
                        const Tensor* bias, Tensor& output, 
                        const ConvParams& params);

    // General Conv2D (Sliding Window with Stride, Padding, Dilation)
    static void Conv2D(const Tensor& input, const Tensor& weight, 
                       const Tensor* bias, Tensor& output, 
                       const ConvParams& params);

    // DepthwiseSeparableConvolutionV2 (ByteDance Mobile Inverted Bottleneck Core)
    static void DepthwiseSeparableConvV2(
        const Tensor& input,
        const Tensor& dw_weight, const Tensor* dw_bias,
        const Tensor& pw_weight, const Tensor* pw_bias,
        Tensor& output,
        const ConvParams& dw_params, const ConvParams& pw_params);

    // --- 2. ACTIVATION KERNELS ---
    static void ApplyActivation(float* data, size_t count, ActivationType act, 
                                float alpha = 0.1f, const float* prelu_slopes = nullptr, 
                                int32_t channels = 1, int32_t spatial_size = 1);

    static float Relu(float x) noexcept { return std::max(0.0f, x); }
    static float Relu6(float x) noexcept { return std::clamp(x, 0.0f, 6.0f); }
    static float LeakyRelu(float x, float alpha = 0.1f) noexcept { return x >= 0.0f ? x : alpha * x; }
    
    // ReluHardSigmoid: clamp((x + 3) / 6, 0, 1)
    static float ReluHardSigmoid(float x) noexcept { 
        return std::clamp((x + 3.0f) / 6.0f, 0.0f, 1.0f); 
    }

    // ReluHardSwish: x * clamp((x + 3) / 6, 0, 1)
    static float ReluHardSwish(float x) noexcept { 
        return x * std::clamp((x + 3.0f) / 6.0f, 0.0f, 1.0f); 
    }

    static float Sigmoid(float x) noexcept { 
        return 1.0f / (1.0f + std::exp(-x)); 
    }

    static float Tanh(float x) noexcept { 
        return std::tanh(x); 
    }

    // --- 3. POOLING KERNELS ---
    static void PoolingV2(const Tensor& input, Tensor& output, const PoolingParams& params);
    static void GlobalPooling(const Tensor& input, Tensor& output, PoolingType type);

    // --- 4. NORMALIZATION & SOFTMAX ---
    // SoftmaxV3 (Numerically stable with max subtraction)
    static void SoftmaxV3(const Tensor& input, Tensor& output, int32_t axis = 1);
    static void LogSoftmax(const Tensor& input, Tensor& output, int32_t axis = 1);

    // --- 5. FULLY CONNECTED / GEMM ---
    static void FullyConnected(const Tensor& input, const Tensor& weight, 
                               const Tensor* bias, Tensor& output);

    // --- 6. QUANTIZATION KERNELS (QuantV3 / DequantV3) ---
    static void QuantV3(const float* src, int8_t* dst, size_t count, 
                        float scale, int32_t zero_point);
    static void DequantV3(const int8_t* src, float* dst, size_t count, 
                          float scale, int32_t zero_point);

    // --- 7. ELEMENT-WISE OPERATIONS ---
    static void ElementwiseAdd(const Tensor& a, const Tensor& b, Tensor& out);
    static void ElementwiseMul(const Tensor& a, const Tensor& b, Tensor& out);
};

} // namespace NextAI::OpenCut::bytenn
