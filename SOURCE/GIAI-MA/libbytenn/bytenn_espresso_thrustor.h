// ======================================================================
// RECONSTRUCTED HEADER: bytenn_espresso_thrustor.h
// Library: libbytenn.so (ByteDance ByteNN Inference Engine)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   espresso::Thrustor runtime engine reverse-engineered from
//   libbytenn.so. Handles model parsing, layer graph construction,
//   thread dispatch (context offset 0x20 per opcode 0x4df64), dynamic
//   shape reinference, and forward execution.
//
// Mô tả (Tiếng Việt):
//   Bộ máy thực thi espresso::Thrustor dịch ngược từ libbytenn.so.
//   Xử lý phân tích mô hình, đồ thị các lớp mạng, điều phối đa luồng
//   (ghi offset 0x20 ngữ cảnh theo opcode 0x4df64), suy luận kích thước
//   động và thực thi forward pass.
// ======================================================================

#pragma once

#include "bytenn_types.h"
#include "bytenn_tensor.h"
#include "bytenn_kernels.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <mutex>

namespace NextAI::OpenCut::espresso {

using namespace NextAI::OpenCut::bytenn;

// ----------------------------------------------------------------------
// Output cấu trúc cho TextureLayer
// Demangled: espresso::TextureLayerOutput
// ----------------------------------------------------------------------
struct TextureLayerOutput {
    std::string name;
    uint32_t texture_id{0};
    int32_t width{0};
    int32_t height{0};
    int32_t channels{4};
};

// ----------------------------------------------------------------------
// Cấu trúc Layer trừu tượng bên trong Thrustor DAG
// ----------------------------------------------------------------------
struct LayerNode {
    std::string name;
    std::string type; // "Conv2D", "Conv1x1", "DepthwiseConv", "Relu", "Pooling", "Softmax", etc.
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
    bool is_skipped{false};

    // Trọng số và tham số (Weights & Parameters)
    Tensor weight;
    Tensor bias;
    ConvParams conv_params;
    PoolingParams pooling_params;
    ActivationType activation{ActivationType::NONE};

    // Tensor trung gian lưu trữ kết quả đầu ra
    Tensor output_tensor;
};

// ----------------------------------------------------------------------
// Ngữ cảnh Runtime nội bộ (Internal Runtime Context)
// AArch64 Opcode 0x4df64:
//   ldr x8, [x0, #8]       ; x8 = runtime_context
//   str w1, [x8, #0x20]     ; context->num_threads = w1 (offset 0x20!)
//   ret
// ----------------------------------------------------------------------
struct ThrustorRuntimeContext {
    uint8_t pad_00[0x20];
    int32_t num_threads{4}; // Offset 0x20!
    int32_t power_mode{0};
    bool enforce_cpu{true};
    bool early_stop{false};
    int32_t default_width{256};
    int32_t default_height{256};
};

// ----------------------------------------------------------------------
// espresso::Thrustor Class
// Binary Vtable & Demangled Symbol Map
// ----------------------------------------------------------------------
class Thrustor {
public:
    Thrustor();
    virtual ~Thrustor();

    // Khởi tạo mạng nơ-ron từ buffer mô hình nhị phân (Opcode 0x4d93c)
    // CreateNet(const std::string&, void*, std::vector<std::string>&)
    int32_t CreateNet(const std::string& model_name, void* model_buffer, 
                      std::vector<std::string>& output_names);

    // Gán dữ liệu Tensor đầu vào (Opcode 0x4da18)
    // SetInput(std::string, void*, int, int, int)
    int32_t SetInput(const std::string& name, void* data, int32_t n, int32_t c, int32_t h, int32_t w = 1);

    // Tái tính toán kích thước động (Opcode 0x4dc50)
    // ReInferShape(int, int)
    int32_t ReInferShape(int32_t width, int32_t height);

    // Thực thi suy luận đồ thị mạng (Opcode 0x4dcf4)
    // Inference()
    int32_t Inference();

    // Trích xuất Tensor kết quả của một tầng cụ thể (Opcode 0x4dd9c)
    // Extract(const std::string&)
    Tensor Extract(const std::string& layer_name);

    // Lấy danh sách tên tất cả các tầng mạng (Opcode 0x4defc)
    std::vector<std::string> getLayers() const;

    // Thiết lập số luồng thực thi CPU (Opcode 0x4df64)
    // setThreads(int): ghi giá trị vào context offset 0x20!
    void setThreads(int32_t threads);
    int32_t getThreads() const noexcept;

    // Bỏ qua tầng cụ thể khi chạy (Opcode 0x4df70)
    int32_t SkipLayer(const std::string& layer_name);

    // Kiểm tra tính hợp lệ của tham số mạng (Opcode 0x4e01c)
    int32_t VerifyNetParamters();

    // Lấy tổng dung lượng bytes trọng số mô hình (Opcode 0x4e080)
    size_t GetWeightLen() const noexcept;

    // Thiết lập mạng con Texture Layer (Opcode 0x4e0f8)
    int32_t SetSubNet(const std::vector<TextureLayerOutput>* in_sub, 
                      const std::vector<TextureLayerOutput>* out_sub);

    // Lấy toàn bộ Tensor kết quả đầu ra (Opcode 0x4e5dc)
    std::vector<Tensor> getOutput();

    // Truy cập runtime context (phục vụ đối soát ABI)
    ThrustorRuntimeContext* GetRuntimeContext() noexcept { return runtime_context_.get(); }

    // Thêm tầng mạng phục vụ xây dựng pipeline
    void AddLayer(const LayerNode& layer);
    void SetInputTensor(const std::string& name, const Tensor& tensor);
    const Tensor* GetTensor(const std::string& name) const;

private:
    std::unique_ptr<ThrustorRuntimeContext> runtime_context_; // Offset 0x08!
    std::string model_name_{""};
    std::vector<LayerNode> layers_;
    std::unordered_map<std::string, Tensor> tensors_;
    std::vector<std::string> input_names_;
    std::vector<std::string> output_names_;
    size_t total_weight_bytes_{0};
    mutable std::mutex exec_mutex_;
};

// ----------------------------------------------------------------------
// C API Exported Functions for espresso::Thrustor
// ----------------------------------------------------------------------
extern "C" {
    Tensor* ThrustorGetInput(Thrustor* thrustor);
    int32_t ThrustorReset(Thrustor* thrustor);
    int32_t ThrustorGetEarlyStop(Thrustor* thrustor);
    int32_t ThrustorReInferShape(Thrustor* thrustor, const std::vector<std::vector<int32_t>>& shapes);
    int32_t ThrustorDefaultInSize(Thrustor* thrustor, int32_t& width, int32_t& height);
    int32_t ThrustorEnforceCPURuntime(Thrustor* thrustor);
}

} // namespace NextAI::OpenCut::espresso
