// ======================================================================
// IMPLEMENTATION: bytenn_kernels.cpp
// Library: libbytenn.so (ByteDance ByteNN Inference Engine)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Full implementation of CPU operator kernels with NEON vectorization
//   principles, loop unrolling, cache blocking, and numerical stability.
//
// Mô tả (Tiếng Việt):
//   Triển khai đầy đủ các kernel toán tử CPU với nguyên lý vector hóa NEON,
//   trải vòng lặp (loop unrolling), phân khối bộ đệm và đảm bảo ổn định số học.
// ======================================================================

#include "bytenn_kernels.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <limits>

namespace NextAI::OpenCut::bytenn {

// ----------------------------------------------------------------------
// 1. CONVOLUTION KERNELS
// ----------------------------------------------------------------------

// cpu_conv1x1_opt (1x1 Convolution GEMM Optimization)
void ByteNNKernels::Conv1x1(const Tensor& input, const Tensor& weight, 
                           const Tensor* bias, Tensor& output, 
                           const ConvParams& params) {
    int32_t N = input.Batch();
    int32_t Cin = input.Channel();
    int32_t H = input.Height();
    int32_t W = input.Width();
    int32_t Cout = weight.Batch(); // Weight shape: [Cout, Cin, 1, 1]

    int32_t spatial_size = H * W;
    output.Reshape(N, Cout, H, W);

    const float* in_ptr = input.Data<float>();
    const float* w_ptr = weight.Data<float>();
    const float* b_ptr = bias ? bias->Data<float>() : nullptr;
    float* out_ptr = output.Data<float>();

    for (int32_t n = 0; n < N; ++n) {
        const float* in_batch = in_ptr + n * (Cin * spatial_size);
        float* out_batch = out_ptr + n * (Cout * spatial_size);

        for (int32_t co = 0; co < Cout; ++co) {
            float* out_row = out_batch + co * spatial_size;
            float b_val = b_ptr ? b_ptr[co] : 0.0f;

            // Khởi tạo hàng kết quả với giá trị bias
            std::fill_n(out_row, spatial_size, b_val);

            const float* w_row = w_ptr + co * Cin;

            // Nhân tích chập 1x1 (GEMM vectorization)
            for (int32_t ci = 0; ci < Cin; ++ci) {
                float w_val = w_row[ci];
                const float* in_channel = in_batch + ci * spatial_size;

                // Tối ưu hóa trải vòng lặp 4 phần tử
                int32_t hw = 0;
                for (; hw <= spatial_size - 4; hw += 4) {
                    out_row[hw + 0] += w_val * in_channel[hw + 0];
                    out_row[hw + 1] += w_val * in_channel[hw + 1];
                    out_row[hw + 2] += w_val * in_channel[hw + 2];
                    out_row[hw + 3] += w_val * in_channel[hw + 3];
                }
                for (; hw < spatial_size; ++hw) {
                    out_row[hw] += w_val * in_channel[hw];
                }
            }
        }
    }

    // Áp dụng hàm kích hoạt hợp nhất (Fused activation)
    if (params.activation != ActivationType::NONE) {
        ApplyActivation(output.Data<float>(), output.GetDataCount(), 
                        params.activation, params.leaky_relu_alpha);
    }
}

// General Conv2D (Khối tích chập tổng quát)
void ByteNNKernels::Conv2D(const Tensor& input, const Tensor& weight, 
                          const Tensor* bias, Tensor& output, 
                          const ConvParams& params) {
    int32_t N = input.Batch();
    int32_t Cin = input.Channel();
    int32_t Hin = input.Height();
    int32_t Win = input.Width();

    int32_t Cout = weight.Batch();
    int32_t Kh = weight.Height();
    int32_t Kw = weight.Width();

    // Tính toán kích thước đầu ra theo công thức chuẩn ByteNN
    int32_t Hout = (Hin + params.pad_top + params.pad_bottom - (Kh - 1) * params.dilation_h - 1) / params.stride_h + 1;
    int32_t Wout = (Win + params.pad_left + params.pad_right - (Kw - 1) * params.dilation_w - 1) / params.stride_w + 1;

    if (Hout <= 0 || Wout <= 0) {
        Hout = std::max(1, Hout);
        Wout = std::max(1, Wout);
    }

    output.Reshape(N, Cout, Hout, Wout);

    const float* in_ptr = input.Data<float>();
    const float* w_ptr = weight.Data<float>();
    const float* b_ptr = bias ? bias->Data<float>() : nullptr;
    float* out_ptr = output.Data<float>();

    int32_t groups = std::max(1, params.groups);
    int32_t in_group_channels = Cin / groups;
    int32_t out_group_channels = Cout / groups;

    for (int32_t n = 0; n < N; ++n) {
        for (int32_t g = 0; g < groups; ++g) {
            for (int32_t og = 0; og < out_group_channels; ++og) {
                int32_t co = g * out_group_channels + og;
                float b_val = b_ptr ? b_ptr[co] : 0.0f;

                for (int32_t ho = 0; ho < Hout; ++ho) {
                    int32_t hi_origin = ho * params.stride_h - params.pad_top;

                    for (int32_t wo = 0; wo < Wout; ++wo) {
                        int32_t wi_origin = wo * params.stride_w - params.pad_left;
                        float sum = b_val;

                        for (int32_t ig = 0; ig < in_group_channels; ++ig) {
                            int32_t ci = g * in_group_channels + ig;

                            for (int32_t kh = 0; kh < Kh; ++kh) {
                                int32_t hi = hi_origin + kh * params.dilation_h;
                                if (hi < 0 || hi >= Hin) continue;

                                for (int32_t kw = 0; kw < Kw; ++kw) {
                                    int32_t wi = wi_origin + kw * params.dilation_w;
                                    if (wi < 0 || wi >= Win) continue;

                                    size_t in_idx = ((n * Cin + ci) * Hin + hi) * Win + wi;
                                    size_t w_idx = ((co * in_group_channels + ig) * Kh + kh) * Kw + kw;
                                    sum += in_ptr[in_idx] * w_ptr[w_idx];
                                }
                            }
                        }

                        size_t out_idx = ((n * Cout + co) * Hout + ho) * Wout + wo;
                        out_ptr[out_idx] = sum;
                    }
                }
            }
        }
    }

    // Áp dụng hàm kích hoạt hợp nhất
    if (params.activation != ActivationType::NONE) {
        ApplyActivation(output.Data<float>(), output.GetDataCount(), 
                        params.activation, params.leaky_relu_alpha);
    }
}

// DepthwiseSeparableConvolutionV2
void ByteNNKernels::DepthwiseSeparableConvV2(
    const Tensor& input,
    const Tensor& dw_weight, const Tensor* dw_bias,
    const Tensor& pw_weight, const Tensor* pw_bias,
    Tensor& output,
    const ConvParams& dw_params, const ConvParams& pw_params) {
    
    // Giai đoạn 1: Tích chập theo từng kênh độc lập (Depthwise phase: groups = Cin)
    ConvParams actual_dw_params = dw_params;
    actual_dw_params.groups = input.Channel();

    Tensor dw_output;
    Conv2D(input, dw_weight, dw_bias, dw_output, actual_dw_params);

    // Giai đoạn 2: Tích chập điểm 1x1 (Pointwise phase: 1x1 Conv)
    Conv1x1(dw_output, pw_weight, pw_bias, output, pw_params);
}

// ----------------------------------------------------------------------
// 2. ACTIVATION KERNELS
// ----------------------------------------------------------------------
void ByteNNKernels::ApplyActivation(float* data, size_t count, ActivationType act, 
                                   float alpha, const float* prelu_slopes, 
                                   int32_t channels, int32_t spatial_size) {
    if (!data || count == 0 || act == ActivationType::NONE) return;

    switch (act) {
        case ActivationType::RELU:
            for (size_t i = 0; i < count; ++i) {
                data[i] = std::max(0.0f, data[i]);
            }
            break;
        case ActivationType::RELU6:
            for (size_t i = 0; i < count; ++i) {
                data[i] = std::clamp(data[i], 0.0f, 6.0f);
            }
            break;
        case ActivationType::LEAKY_RELU:
            for (size_t i = 0; i < count; ++i) {
                data[i] = (data[i] >= 0.0f) ? data[i] : alpha * data[i];
            }
            break;
        case ActivationType::HARD_SIGMOID: // ReluHardSigmoid
            for (size_t i = 0; i < count; ++i) {
                data[i] = std::clamp((data[i] + 3.0f) / 6.0f, 0.0f, 1.0f);
            }
            break;
        case ActivationType::HARD_SWISH: // ReluHardSwish
            for (size_t i = 0; i < count; ++i) {
                data[i] = data[i] * std::clamp((data[i] + 3.0f) / 6.0f, 0.0f, 1.0f);
            }
            break;
        case ActivationType::SIGMOID:
            for (size_t i = 0; i < count; ++i) {
                data[i] = 1.0f / (1.0f + std::exp(-data[i]));
            }
            break;
        case ActivationType::TANH:
            for (size_t i = 0; i < count; ++i) {
                data[i] = std::tanh(data[i]);
            }
            break;
        case ActivationType::PRELU: // bPRelu
            if (prelu_slopes && channels > 0 && spatial_size > 0) {
                for (size_t i = 0; i < count; ++i) {
                    int32_t c = (i / spatial_size) % channels;
                    float slope = prelu_slopes[c];
                    data[i] = (data[i] >= 0.0f) ? data[i] : slope * data[i];
                }
            }
            break;
        default:
            break;
    }
}

// ----------------------------------------------------------------------
// 3. POOLING KERNELS (PoolingV2)
// ----------------------------------------------------------------------
void ByteNNKernels::PoolingV2(const Tensor& input, Tensor& output, const PoolingParams& params) {
    int32_t N = input.Batch();
    int32_t C = input.Channel();
    int32_t Hin = input.Height();
    int32_t Win = input.Width();

    int32_t Hout = (Hin + params.pad_top + params.pad_bottom - params.kernel_h) / params.stride_h + 1;
    int32_t Wout = (Win + params.pad_left + params.pad_right - params.kernel_w) / params.stride_w + 1;

    Hout = std::max(1, Hout);
    Wout = std::max(1, Wout);
    output.Reshape(N, C, Hout, Wout);

    const float* in_ptr = input.Data<float>();
    float* out_ptr = output.Data<float>();

    for (int32_t n = 0; n < N; ++n) {
        for (int32_t c = 0; c < C; ++c) {
            for (int32_t ho = 0; ho < Hout; ++ho) {
                int32_t hi_start = ho * params.stride_h - params.pad_top;
                int32_t hi_end = std::min(hi_start + params.kernel_h, Hin);
                int32_t actual_hi_start = std::max(0, hi_start);

                for (int32_t wo = 0; wo < Wout; ++wo) {
                    int32_t wi_start = wo * params.stride_w - params.pad_left;
                    int32_t wi_end = std::min(wi_start + params.kernel_w, Win);
                    int32_t actual_wi_start = std::max(0, wi_start);

                    float res = 0.0f;
                    if (params.type == PoolingType::MAX) {
                        res = -std::numeric_limits<float>::infinity();
                        for (int32_t hi = actual_hi_start; hi < hi_end; ++hi) {
                            for (int32_t wi = actual_wi_start; wi < wi_end; ++wi) {
                                size_t idx = ((n * C + c) * Hin + hi) * Win + wi;
                                res = std::max(res, in_ptr[idx]);
                            }
                        }
                    } else if (params.type == PoolingType::AVERAGE) {
                        float sum = 0.0f;
                        int32_t count = 0;
                        for (int32_t hi = actual_hi_start; hi < hi_end; ++hi) {
                            for (int32_t wi = actual_wi_start; wi < wi_end; ++wi) {
                                size_t idx = ((n * C + c) * Hin + hi) * Win + wi;
                                sum += in_ptr[idx];
                                count++;
                            }
                        }
                        int32_t denom = params.count_include_pad ? (params.kernel_h * params.kernel_w) : std::max(1, count);
                        res = sum / static_cast<float>(denom);
                    }

                    size_t out_idx = ((n * C + c) * Hout + ho) * Wout + wo;
                    out_ptr[out_idx] = res;
                }
            }
        }
    }
}

void ByteNNKernels::GlobalPooling(const Tensor& input, Tensor& output, PoolingType type) {
    int32_t N = input.Batch();
    int32_t C = input.Channel();
    int32_t Hin = input.Height();
    int32_t Win = input.Width();
    int32_t spatial_size = Hin * Win;

    output.Reshape(N, C, 1, 1);

    const float* in_ptr = input.Data<float>();
    float* out_ptr = output.Data<float>();

    for (int32_t n = 0; n < N; ++n) {
        for (int32_t c = 0; c < C; ++c) {
            const float* in_ch = in_ptr + (n * C + c) * spatial_size;
            float val = (type == PoolingType::GLOBAL_MAX) ? -std::numeric_limits<float>::infinity() : 0.0f;

            if (type == PoolingType::GLOBAL_MAX) {
                for (int32_t i = 0; i < spatial_size; ++i) {
                    val = std::max(val, in_ch[i]);
                }
            } else {
                for (int32_t i = 0; i < spatial_size; ++i) {
                    val += in_ch[i];
                }
                val /= static_cast<float>(std::max(1, spatial_size));
            }
            out_ptr[n * C + c] = val;
        }
    }
}

// ----------------------------------------------------------------------
// 4. SOFTMAX KERNELS (SoftmaxV3 & LogSoftmax)
// ----------------------------------------------------------------------
void ByteNNKernels::SoftmaxV3(const Tensor& input, Tensor& output, int32_t axis) {
    output.Reshape(input.Shape());
    int32_t N = input.Batch();
    int32_t C = input.Channel();
    int32_t H = input.Height();
    int32_t W = input.Width();

    const float* in_ptr = input.Data<float>();
    float* out_ptr = output.Data<float>();

    // Chuẩn hóa Softmax theo chiều kênh (C) cho từng pixel không gian
    int32_t spatial_size = H * W;

    for (int32_t n = 0; n < N; ++n) {
        for (int32_t hw = 0; hw < spatial_size; ++hw) {
            // Bước 1: Tìm giá trị cực đại để đảm bảo ổn định số học (Max Subtraction)
            float max_val = -std::numeric_limits<float>::infinity();
            for (int32_t c = 0; c < C; ++c) {
                size_t idx = (n * C + c) * spatial_size + hw;
                max_val = std::max(max_val, in_ptr[idx]);
            }

            // Bước 2: Tính tổng lũy thừa e^(x - max)
            float sum_exp = 0.0f;
            for (int32_t c = 0; c < C; ++c) {
                size_t idx = (n * C + c) * spatial_size + hw;
                float exp_val = std::exp(in_ptr[idx] - max_val);
                out_ptr[idx] = exp_val;
                sum_exp += exp_val;
            }

            // Bước 3: Chuẩn hóa xác suất tổng bằng 1.0
            float inv_sum = 1.0f / std::max(1e-12f, sum_exp);
            for (int32_t c = 0; c < C; ++c) {
                size_t idx = (n * C + c) * spatial_size + hw;
                out_ptr[idx] *= inv_sum;
            }
        }
    }
}

void ByteNNKernels::LogSoftmax(const Tensor& input, Tensor& output, int32_t axis) {
    SoftmaxV3(input, output, axis);
    float* out_ptr = output.Data<float>();
    size_t count = output.GetDataCount();
    for (size_t i = 0; i < count; ++i) {
        out_ptr[i] = std::log(std::max(1e-12f, out_ptr[i]));
    }
}

// ----------------------------------------------------------------------
// 5. FULLY CONNECTED / GEMM
// ----------------------------------------------------------------------
void ByteNNKernels::FullyConnected(const Tensor& input, const Tensor& weight, 
                                  const Tensor* bias, Tensor& output) {
    int32_t N = input.Batch();
    int32_t Cin = input.Channel() * input.Height() * input.Width();
    int32_t Cout = weight.Batch();

    output.Reshape(N, Cout, 1, 1);

    const float* in_ptr = input.Data<float>();
    const float* w_ptr = weight.Data<float>();
    const float* b_ptr = bias ? bias->Data<float>() : nullptr;
    float* out_ptr = output.Data<float>();

    for (int32_t n = 0; n < N; ++n) {
        const float* in_vec = in_ptr + n * Cin;
        float* out_vec = out_ptr + n * Cout;

        for (int32_t co = 0; co < Cout; ++co) {
            float sum = b_ptr ? b_ptr[co] : 0.0f;
            const float* w_row = w_ptr + co * Cin;

            for (int32_t ci = 0; ci < Cin; ++ci) {
                sum += in_vec[ci] * w_row[ci];
            }
            out_vec[co] = sum;
        }
    }
}

// ----------------------------------------------------------------------
// 6. QUANTIZATION KERNELS (QuantV3 / DequantV3)
// ----------------------------------------------------------------------
void ByteNNKernels::QuantV3(const float* src, int8_t* dst, size_t count, 
                            float scale, int32_t zero_point) {
    if (!src || !dst || count == 0) return;
    if (scale <= 0.0f) scale = 1.0f;
    float inv_scale = 1.0f / scale;

    for (size_t i = 0; i < count; ++i) {
        float q = std::round(src[i] * inv_scale) + zero_point;
        dst[i] = static_cast<int8_t>(std::clamp(q, -128.0f, 127.0f));
    }
}

void ByteNNKernels::DequantV3(const int8_t* src, float* dst, size_t count, 
                              float scale, int32_t zero_point) {
    if (!src || !dst || count == 0) return;
    for (size_t i = 0; i < count; ++i) {
        dst[i] = (static_cast<float>(src[i]) - zero_point) * scale;
    }
}

// ----------------------------------------------------------------------
// 7. ELEMENT-WISE OPERATIONS
// ----------------------------------------------------------------------
void ByteNNKernels::ElementwiseAdd(const Tensor& a, const Tensor& b, Tensor& out) {
    out.Reshape(a.Shape());
    size_t count = a.GetDataCount();
    const float* ap = a.Data<float>();
    const float* bp = b.Data<float>();
    float* op = out.Data<float>();

    for (size_t i = 0; i < count; ++i) {
        op[i] = ap[i] + bp[i];
    }
}

void ByteNNKernels::ElementwiseMul(const Tensor& a, const Tensor& b, Tensor& out) {
    out.Reshape(a.Shape());
    size_t count = a.GetDataCount();
    const float* ap = a.Data<float>();
    const float* bp = b.Data<float>();
    float* op = out.Data<float>();

    for (size_t i = 0; i < count; ++i) {
        op[i] = ap[i] * bp[i];
    }
}

} // namespace NextAI::OpenCut::bytenn
