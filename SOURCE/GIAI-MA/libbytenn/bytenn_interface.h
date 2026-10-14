// ======================================================================
// RECONSTRUCTED INTERFACE: bytenn_interface.h
// Library: libbytenn.so (ByteDance ByteNN Inference Engine)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Unified public interface for ByteDance ByteNN Neural Network
//   Inference Engine. Exports C and C++ APIs for model loading,
//   tensor manipulation, kernel execution, and hardware probing.
//
// Mô tả (Tiếng Việt):
//   Giao diện công khai hợp nhất cho Engine suy luận mạng nơ-ron
//   ByteDance ByteNN. Xuất các API C và C++ phục vụ nạp mô hình,
//   thao tác tensor, thực thi kernel và kiểm tra năng lực phần cứng.
// ======================================================================

#pragma once

#include "bytenn_types.h"
#include "bytenn_tensor.h"
#include "bytenn_kernels.h"
#include "bytenn_espresso_thrustor.h"
#include "bytenn_engine.h"

namespace NextAI::OpenCut::bytenn {

// ----------------------------------------------------------------------
// OpenCut High-Level AI Inference Helper
// ----------------------------------------------------------------------
class ByteNNInferenceManager {
public:
    static ByteNNInferenceManager& Instance();

    bool Initialize(const std::string& model_name, int32_t num_threads = 4);
    bool RunInference(const float* input_data, int32_t width, int32_t height, 
                      std::vector<float>& output_probabilities);
    const char* GetEngineVersion() const noexcept;
    bool SupportsDotProduct() const noexcept;
    bool SupportsFP16() const noexcept;

private:
    ByteNNInferenceManager() = default;
    ~ByteNNInferenceManager() = default;

    std::shared_ptr<ByteNNEngine> engine_;
    bool is_ready_{false};
};

// ----------------------------------------------------------------------
// C-API Export Declarations for JNI and Dynamic Linking
// ----------------------------------------------------------------------
extern "C" {
    // Phiên bản engine ByteNN (trả về "3.12.91")
    const char* bytenn_get_version();

    // Khởi tạo engine
    void* bytenn_create_engine();
    int32_t bytenn_init_engine(void* engine_handle, const char* model_path, int32_t num_threads);
    int32_t bytenn_destroy_engine(void* engine_handle);

    // Thực thi suy luận
    int32_t bytenn_run_inference(void* engine_handle, const float* input_ptr, 
                                 int32_t n, int32_t c, int32_t h, int32_t w, 
                                 float* output_ptr, int32_t max_output_size);

    // Tự kiểm tra toàn diện 10 tiêu chí giải thuật (10-Point Self Test)
    int32_t bytenn_run_verification_self_test();
}

} // namespace NextAI::OpenCut::bytenn
