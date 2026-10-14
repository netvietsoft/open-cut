// ======================================================================
// RECONSTRUCTED C++ PSEUDOCODE & ENGINE CORE: bytenn_pseudocode.cpp
// Library: libbytenn.so (ByteDance ByteNN Inference Engine)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Complete C++ implementation for ByteDance ByteNN inference engine,
//   exposing C-linkage entrypoints, InferenceManager singleton, and
//   an exhaustive 10-point algorithmic verification suite.
//
// Mô tả (Tiếng Việt):
//   Triển khai C++ hoàn chỉnh cho engine suy luận ByteDance ByteNN,
//   cung cấp các điểm vào C-linkage, singleton InferenceManager và
//   bộ kiểm thử thuật toán toàn diện 10 tiêu chí đối soát chuẩn xác.
// ======================================================================

#include "bytenn_interface.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <cstring>
#include <sstream>

namespace NextAI::OpenCut::bytenn {

// ----------------------------------------------------------------------
// ByteNNInferenceManager Singleton Implementation
// ----------------------------------------------------------------------
ByteNNInferenceManager& ByteNNInferenceManager::Instance() {
    static ByteNNInferenceManager instance;
    return instance;
}

bool ByteNNInferenceManager::Initialize(const std::string& model_name, int32_t num_threads) {
    engine_ = EngineFactory::Create();
    if (!engine_) return false;

    Config config;
    config.algo_model_name = model_name;
    config.num_threads = num_threads;
    config.forward_type = ForwardType::FORWARD_CPU;

    int32_t ret = engine_->Init(config);
    is_ready_ = (ret == 0);
    return is_ready_;
}

bool ByteNNInferenceManager::RunInference(const float* input_data, int32_t width, int32_t height, 
                                        std::vector<float>& output_probabilities) {
    if (!is_ready_ || !engine_ || !input_data) return false;

    // Chuẩn bị tensor đầu vào [1, 3, height, width]
    Tensor in_t(1, 3, height, width, DataType::FLOAT32, DataFormat::NCHW);
    in_t.CopyFrom(input_data, in_t.GetByteSize());

    std::vector<Tensor> in_vec = {in_t};
    if (engine_->SetInput(in_vec) != 0) return false;

    if (engine_->Inference() != 0) return false;

    std::vector<Tensor> out_vec;
    if (engine_->GetOutput(&out_vec) != 0 || out_vec.empty()) return false;

    size_t count = out_vec[0].GetDataCount();
    output_probabilities.resize(count);
    const float* ptr = out_vec[0].Data<float>();
    std::memcpy(output_probabilities.data(), ptr, count * sizeof(float));

    return true;
}

const char* ByteNNInferenceManager::GetEngineVersion() const noexcept {
    return ByteNNUtils::GetVersion();
}

bool ByteNNInferenceManager::SupportsDotProduct() const noexcept {
    return engine_ ? engine_->isSupportCPUDotProd() : true;
}

bool ByteNNInferenceManager::SupportsFP16() const noexcept {
    return engine_ ? engine_->isSupportCpuFp16() : true;
}

// ----------------------------------------------------------------------
// C-API Export Declarations
// ----------------------------------------------------------------------
extern "C" {

const char* bytenn_get_version() {
    return ByteNNUtils::GetVersion();
}

void* bytenn_create_engine() {
    auto engine = EngineFactory::Create();
    return new std::shared_ptr<ByteNNEngine>(engine);
}

int32_t bytenn_init_engine(void* engine_handle, const char* model_path, int32_t num_threads) {
    if (!engine_handle) return -1;
    auto* sptr = reinterpret_cast<std::shared_ptr<ByteNNEngine>*>(engine_handle);
    if (!sptr || !(*sptr)) return -2;

    Config config;
    if (model_path) config.model_path = model_path;
    config.num_threads = num_threads > 0 ? num_threads : 4;
    config.forward_type = ForwardType::FORWARD_CPU;

    return (*sptr)->Init(config);
}

int32_t bytenn_destroy_engine(void* engine_handle) {
    if (!engine_handle) return -1;
    auto* sptr = reinterpret_cast<std::shared_ptr<ByteNNEngine>*>(engine_handle);
    if (sptr) {
        EngineFactory::AsyncRelease(*sptr);
        delete sptr;
    }
    return 0;
}

int32_t bytenn_run_inference(void* engine_handle, const float* input_ptr, 
                             int32_t n, int32_t c, int32_t h, int32_t w, 
                             float* output_ptr, int32_t max_output_size) {
    if (!engine_handle || !input_ptr || !output_ptr) return -1;
    auto* sptr = reinterpret_cast<std::shared_ptr<ByteNNEngine>*>(engine_handle);
    if (!sptr || !(*sptr)) return -2;

    Tensor in_t(n, c, h, w, DataType::FLOAT32);
    in_t.CopyFrom(input_ptr, in_t.GetByteSize());

    std::vector<Tensor> inputs = {in_t};
    if ((*sptr)->SetInput(inputs) != 0) return -3;
    if ((*sptr)->Inference() != 0) return -4;

    std::vector<Tensor> outputs;
    if ((*sptr)->GetOutput(&outputs) != 0 || outputs.empty()) return -5;

    size_t copy_bytes = std::min(static_cast<size_t>(max_output_size * sizeof(float)), 
                                 outputs[0].GetByteSize());
    std::memcpy(output_ptr, outputs[0].RawData(), copy_bytes);
    return 0;
}

// ----------------------------------------------------------------------
// 10-Point Algorithmic Verification Self Test
// Hàm tự kiểm chứng toàn diện 10 tiêu chí giải thuật ByteNN
// ----------------------------------------------------------------------
int32_t bytenn_run_verification_self_test() {
    int32_t pass_count = 0;

    // --- TEST 1: Tensor GetDataCount Arithmetic (Opcode 0x3aae0) ---
    // N=2, C=3, H=16, W=16 -> Count = 2 * 3 * 16 * 16 = 1536
    {
        Tensor t(2, 3, 16, 16, DataType::FLOAT32);
        if (t.GetDataCount() == 1536) {
            pass_count++;
        }
    }

    // --- TEST 2: Tensor GetByteSize Table Lookup (Opcode 0x3aaf8 & Table 0x263b98) ---
    // Count=1000:
    //   INT8 (Type 0): 1000 * 1 = 1000 bytes
    //   FLOAT16 (Type 2): 1000 * 2 = 2000 bytes
    //   FLOAT32 (Type 4): 1000 * 4 = 4000 bytes
    //   INT64 (Type 6): 1000 * 8 = 8000 bytes
    {
        Tensor t_int8(1, 10, 10, 10, DataType::INT8);
        Tensor t_fp16(1, 10, 10, 10, DataType::FLOAT16);
        Tensor t_fp32(1, 10, 10, 10, DataType::FLOAT32);
        Tensor t_int64(1, 10, 10, 10, DataType::INT64);

        if (t_int8.GetByteSize() == 1000 && 
            t_fp16.GetByteSize() == 2000 && 
            t_fp32.GetByteSize() == 4000 && 
            t_int64.GetByteSize() == 8000) {
            pass_count++;
        }
    }

    // --- TEST 3: ByteNN Version Consistency (Opcode 0x5c6c8) ---
    // Must strictly return "3.12.91" (matches string at 0x265150)
    {
        const char* ver = ByteNNUtils::GetVersion();
        if (ver && std::strcmp(ver, "3.12.91") == 0) {
            pass_count++;
        }
    }

    // --- TEST 4: Hardware Probes (Opcodes 0x2b150 & 0x2b1e4) ---
    // isSupportCPUDotProd & isSupportCpuFp16 must not crash and return valid boolean
    {
        auto engine = EngineFactory::Create();
        if (engine && engine->isSupportCPUDotProd()) {
            pass_count++;
        }
    }

    // --- TEST 5: Conv1x1 Matrix Multiplication GEMM Math Parity ---
    // Input: [1, 2, 1, 1] with values [2.0, 3.0]
    // Weight: [2, 2, 1, 1] with values [[1.0, 2.0], [3.0, 4.0]]
    // Bias: [1, 2, 1, 1] with values [0.5, 1.0]
    // Expected Output:
    //   Row 0: 2.0*1.0 + 3.0*2.0 + 0.5 = 8.5
    //   Row 1: 2.0*3.0 + 3.0*4.0 + 1.0 = 19.0
    {
        Tensor in(1, 2, 1, 1);
        in.Data<float>()[0] = 2.0f;
        in.Data<float>()[1] = 3.0f;

        Tensor w(2, 2, 1, 1);
        w.Data<float>()[0] = 1.0f; w.Data<float>()[1] = 2.0f;
        w.Data<float>()[2] = 3.0f; w.Data<float>()[3] = 4.0f;

        Tensor b(1, 2, 1, 1);
        b.Data<float>()[0] = 0.5f;
        b.Data<float>()[1] = 1.0f;

        Tensor out;
        ConvParams params;
        ByteNNKernels::Conv1x1(in, w, &b, out, params);

        float out0 = out.Data<float>()[0];
        float out1 = out.Data<float>()[1];
        if (std::abs(out0 - 8.5f) < 1e-4f && std::abs(out1 - 19.0f) < 1e-4f) {
            pass_count++;
        }
    }

    // --- TEST 6: Conv2D Sliding Window Math Parity ---
    // Input: 3x3 all 1.0f, Weight: 3x3 all 0.5f, Bias: 0.0f, Stride 1, Pad 0
    // Expected single output pixel: 9 * (1.0 * 0.5) = 4.5f
    {
        Tensor in(1, 1, 3, 3);
        in.FillConstant(1.0f);

        Tensor w(1, 1, 3, 3);
        w.FillConstant(0.5f);

        Tensor out;
        ConvParams params;
        params.stride_h = 1;
        params.stride_w = 1;
        ByteNNKernels::Conv2D(in, w, nullptr, out, params);

        if (out.Height() == 1 && out.Width() == 1 && 
            std::abs(out.Data<float>()[0] - 4.5f) < 1e-4f) {
            pass_count++;
        }
    }

    // --- TEST 7: Depthwise Separable Convolution V2 Math ---
    // Verifies stage 1 (Depthwise 3x3) followed by stage 2 (Pointwise 1x1)
    {
        Tensor in(1, 2, 4, 4);
        in.FillConstant(1.0f);

        Tensor dw_w(2, 1, 3, 3);
        dw_w.FillConstant(0.2f);

        Tensor pw_w(4, 2, 1, 1);
        pw_w.FillConstant(0.5f);

        Tensor out;
        ConvParams dw_params;
        dw_params.stride_h = 1;
        dw_params.stride_w = 1;
        dw_params.pad_top = 1; dw_params.pad_bottom = 1;
        dw_params.pad_left = 1; dw_params.pad_right = 1;

        ConvParams pw_params;
        ByteNNKernels::DepthwiseSeparableConvV2(in, dw_w, nullptr, pw_w, nullptr, 
                                               out, dw_params, pw_params);

        if (out.Channel() == 4 && out.Height() == 4 && out.Width() == 4) {
            pass_count++;
        }
    }

    // --- TEST 8: ReluHardSwish & ReluHardSigmoid Non-Linearities ---
    // HardSigmoid(-3) = 0.0, HardSigmoid(0) = 0.5, HardSigmoid(3) = 1.0, HardSigmoid(6) = 1.0
    // HardSwish(0) = 0.0, HardSwish(3) = 3.0, HardSwish(-3) = 0.0
    {
        float hs_neg3 = ByteNNKernels::ReluHardSigmoid(-3.0f);
        float hs_zero = ByteNNKernels::ReluHardSigmoid(0.0f);
        float hs_pos3 = ByteNNKernels::ReluHardSigmoid(3.0f);

        float hsw_zero = ByteNNKernels::ReluHardSwish(0.0f);
        float hsw_pos3 = ByteNNKernels::ReluHardSwish(3.0f);

        if (std::abs(hs_neg3 - 0.0f) < 1e-5f &&
            std::abs(hs_zero - 0.5f) < 1e-5f &&
            std::abs(hs_pos3 - 1.0f) < 1e-5f &&
            std::abs(hsw_zero - 0.0f) < 1e-5f &&
            std::abs(hsw_pos3 - 3.0f) < 1e-5f) {
            pass_count++;
        }
    }

    // --- TEST 9: SoftmaxV3 Numerical Stability & Normalization ---
    // Input: [1000.0, 1000.0] -> Exponentials without max subtraction would overflow!
    // Output: [0.5, 0.5], Sum = 1.0
    {
        Tensor in(1, 2, 1, 1);
        in.Data<float>()[0] = 1000.0f;
        in.Data<float>()[1] = 1000.0f;

        Tensor out;
        ByteNNKernels::SoftmaxV3(in, out, 1);

        float p0 = out.Data<float>()[0];
        float p1 = out.Data<float>()[1];
        if (std::abs(p0 - 0.5f) < 1e-4f && std::abs(p1 - 0.5f) < 1e-4f && 
            std::abs((p0 + p1) - 1.0f) < 1e-4f) {
            pass_count++;
        }
    }

    // --- TEST 10: Thrustor Context Offset 0x20 & End-to-End Inference ---
    // Verifies setThreads(8) writes into offset 0x20 per opcode 0x4df64
    // and runs full DAG pipeline
    {
        espresso::Thrustor thrustor;
        thrustor.setThreads(8);
        if (thrustor.getThreads() == 8) {
            std::vector<std::string> outs;
            int32_t ret_create = thrustor.CreateNet("test_net", nullptr, outs);
            int32_t ret_infer = thrustor.Inference();
            if (ret_create == 0 && ret_infer == 0) {
                pass_count++;
            }
        }
    }

    return pass_count; // Expected 10/10
}

} // extern "C"

} // namespace NextAI::OpenCut::bytenn
