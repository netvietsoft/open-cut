// ======================================================================
// RECONSTRUCTED HEADER: bytenn_engine.h
// Library: libbytenn.so (ByteDance ByteNN Inference Engine)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Top-level ByteDance ByteNN Engine API, Config structures,
//   ARM64 HWCAP detection (FP16 & DotProd), EngineFactory,
//   and ByteNNUtils matching version "3.12.91" (opcode 0x5c6c8).
//
// Mô tả (Tiếng Việt):
//   API cấp cao nhất của ByteDance ByteNN Engine, cấu trúc Config,
//   phát hiện năng lực phần cứng ARM64 (FP16 & DotProd), EngineFactory
//   và ByteNNUtils khớp phiên bản "3.12.91" (opcode 0x5c6c8).
// ======================================================================

#pragma once

#include "bytenn_types.h"
#include "bytenn_tensor.h"
#include "bytenn_espresso_thrustor.h"
#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace NextAI::OpenCut::bytenn {

// ----------------------------------------------------------------------
// BYTENN::Config (Cấu hình khởi tạo Engine)
// Demangled: BYTENN::Config (opcode 0x2ae84)
// ----------------------------------------------------------------------
struct Config {
    std::string model_path{""};
    const void* model_buffer{nullptr};
    size_t model_buffer_size{0};
    ForwardType forward_type{ForwardType::FORWARD_CPU};
    int32_t num_threads{4};
    PrecisionType precision_type{PrecisionType::PRECISION_NORMAL};
    std::vector<std::string> input_names;
    std::vector<std::string> output_names;
    int32_t cpu_affinity{0};
    bool dynamic_shape{true};
    std::string algo_model_name{""};
};

// ----------------------------------------------------------------------
// BYTENN::ConfigExt (Cấu hình mở rộng hỗ trợ GPU / Texture IO)
// Demangled: BYTENN::ConfigExt (opcode 0x2ee5c)
// ----------------------------------------------------------------------
struct ConfigExt : public Config {
    bool enable_texture_io{false};
    bool enable_async_init{false};
    bool enable_c4_flag{true};
    std::string task_id{""};
    std::string cache_path{""};
};

// ----------------------------------------------------------------------
// BYTENN::ByteNNEngine (Giao diện suy luận thuần ảo)
// Demangled: BYTENN::ByteNNEngine (opcode 0x27ea4)
// ----------------------------------------------------------------------
class ByteNNEngine {
public:
    virtual ~ByteNNEngine() = default;

    virtual int32_t Init(const Config& config) = 0;
    virtual int32_t Init(const ConfigExt& config_ext) = 0;
    virtual int32_t SetInput(const std::vector<Tensor>& inputs) = 0;
    virtual int32_t SetInput(const std::vector<std::shared_ptr<TensorExt>>& inputs) = 0;
    virtual int32_t GetInputConfig(std::vector<Tensor>& configs) = 0;
    virtual int32_t ReInferShape(int32_t width, int32_t height) = 0;
    virtual int32_t ReInferShape(const std::vector<Tensor>& inputs) = 0;
    virtual int32_t Inference() = 0;
    virtual int32_t Inference(const std::string& model_name) = 0;
    virtual int32_t GetOutput(std::vector<Tensor>* outputs) = 0;
    virtual int32_t GetOutput(std::vector<std::shared_ptr<TensorExt>>* outputs) = 0;
    virtual ForwardType GetForwardType() const noexcept = 0;
    virtual bool isSupportCpuFp16() const noexcept = 0;
    virtual bool isSupportCPUDotProd() const noexcept = 0;
    virtual std::string GetByteNNmd5() const = 0;
    virtual int32_t SetProperty(PropertyType prop, const void* val, const std::string& extra = "") = 0;
    virtual int32_t GetProperty(PropertyType prop, void* val, const std::string& extra = "") = 0;
    virtual void ClearState() = 0;
    virtual void Release() = 0;
};

// ----------------------------------------------------------------------
// BYTENN::ByteNNEngineImpl (Lớp triển khai cụ thể của ByteNN)
// Demangled: BYTENN::ByteNNEngineImpl (opcode 0x27eac)
// ----------------------------------------------------------------------
class ByteNNEngineImpl : public ByteNNEngine {
public:
    ByteNNEngineImpl();
    virtual ~ByteNNEngineImpl() override;

    virtual int32_t Init(const Config& config) override;
    virtual int32_t Init(const ConfigExt& config_ext) override;
    virtual int32_t SetInput(const std::vector<Tensor>& inputs) override;
    virtual int32_t SetInput(const std::vector<std::shared_ptr<TensorExt>>& inputs) override;
    virtual int32_t GetInputConfig(std::vector<Tensor>& configs) override;
    virtual int32_t ReInferShape(int32_t width, int32_t height) override;
    virtual int32_t ReInferShape(const std::vector<Tensor>& inputs) override;
    virtual int32_t Inference() override;
    virtual int32_t Inference(const std::string& model_name) override;
    virtual int32_t GetOutput(std::vector<Tensor>* outputs) override;
    virtual int32_t GetOutput(std::vector<std::shared_ptr<TensorExt>>* outputs) override;
    virtual ForwardType GetForwardType() const noexcept override { return forward_type_; }
    
    // Kiểm tra khả năng phần cứng AArch64 (ARMv8.2-A FP16 & DotProd)
    // isSupportCpuFp16 at opcode 0x2b150
    // isSupportCPUDotProd at opcode 0x2b1e4
    virtual bool isSupportCpuFp16() const noexcept override;
    virtual bool isSupportCPUDotProd() const noexcept override;

    virtual std::string GetByteNNmd5() const override;
    virtual int32_t SetProperty(PropertyType prop, const void* val, const std::string& extra = "") override;
    virtual int32_t GetProperty(PropertyType prop, void* val, const std::string& extra = "") override;
    virtual void ClearState() override;
    virtual void Release() override;

    // Truy cập backend Thrustor
    espresso::Thrustor* GetThrustor() noexcept { return thrustor_.get(); }

private:
    ConfigExt config_;
    ForwardType forward_type_{ForwardType::FORWARD_CPU};
    std::unique_ptr<espresso::Thrustor> thrustor_;
    bool is_initialized_{false};
    std::string engine_md5_{"a3b890f142c67de99052bfa816e89021"};
};

// ----------------------------------------------------------------------
// BYTENN::ByteNNUtils
// Binary Opcode: 0x5c6c8 (GetVersion -> returns "3.12.91" from 0x265150)
// ----------------------------------------------------------------------
class ByteNNUtils {
public:
    // Trả về phiên bản chính thức "3.12.91" của ByteNN trong CapCut
    static const char* GetVersion() noexcept;
    static int32_t ByteNNSystemSettings(const SystemSetting& setting);
    static int32_t GetDeviceInfo(const std::string& device_type, std::vector<std::string>& info);
};

// ----------------------------------------------------------------------
// BYTENN::EngineFactory
// Binary Opcode: 0x39ac0 (Create) & 0x39b8c (AsyncRelease)
// ----------------------------------------------------------------------
class EngineFactory {
public:
    static std::shared_ptr<ByteNNEngine> Create();
    static void AsyncRelease(std::shared_ptr<ByteNNEngine> engine);
};

// Global legacy C API: BYTENN::GetVersion() (opcode 0x5c784)
const char* GetVersion() noexcept;

} // namespace NextAI::OpenCut::bytenn
