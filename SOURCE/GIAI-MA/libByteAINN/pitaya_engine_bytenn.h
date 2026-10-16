// ======================================================================
// RECONSTRUCTED HEADER: pitaya_engine_bytenn.h
// Library: libByteAINN.so (ByteDance Pitaya ByteNN Neural Engine Bridge)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Reconstructed header for ByteDance's Pitaya-to-ByteNN inference engine bridge.
//   Binds Pitaya On-Device AI Core (libAndroidPitayaCore.so) to ByteNN Deep Learning
//   Inference Engine (libbytenn.so). Implements the concrete ByteNNEngine class
//   inheriting from pitaya::Engine, supporting forward inference, shape reinference,
//   input validation (CheckTensorDims), and on-device training/fine-tuning.
//
// Mô tả (Tiếng Việt):
//   Tệp tiêu đề tái dựng cho cầu nối động cơ suy luận ByteNN của nền tảng Pitaya ByteDance.
//   Gắn kết lõi AI trên thiết bị Pitaya (libAndroidPitayaCore.so) với động cơ suy luận
//   học sâu ByteNN (libbytenn.so). Triển khai lớp cụ thể ByteNNEngine kế thừa từ
//   pitaya::Engine, hỗ trợ suy luận thuận, suy luận lại kích thước động (dynamic shape),
//   kiểm tra tính hợp lệ chiều tensor (CheckTensorDims), và huấn luyện/tinh chỉnh tại chỗ.
// ======================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <unordered_map>

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// ForwardType Enum (Kiểu tăng tốc phần cứng / Hardware Accelerator)
// Opcode: 0x8f94 ("ByteNN doesn't support forward_type: %d")
// ----------------------------------------------------------------------
enum class ForwardType : int32_t {
    FORWARD_CPU    = 0,  // CPU tiêu chuẩn (ARMv8 Neon)
    FORWARD_GPU    = 1,  // GPU OpenCL / Vulkan
    FORWARD_NPU    = 2,  // NPU phần cứng chuyên dụng
    FORWARD_AUTO   = 3   // Tự động lựa chọn phần cứng tối ưu
};

// ----------------------------------------------------------------------
// EngineType Enum (Phân loại động cơ thực thi Pitaya)
// Opcode: 0x3a28 (mov w2, #1 -> EngineType::BYTENN)
// ----------------------------------------------------------------------
enum class EngineType : int32_t {
    UNKNOWN     = 0,
    BYTENN      = 1,  // ByteDance ByteNN Neural Network
    BYTEDT      = 2,  // ByteDance Decision Tree
    PNN         = 3,  // Pitaya Neural Network
    PYTHON_VM   = 4   // MicroPython / Python VM
};

// ----------------------------------------------------------------------
// DataType Enum (Kiểu dữ liệu số học Tensor)
// Opcode: 0x91f3 ("ByteNN unsupported DataType: %d")
// ----------------------------------------------------------------------
enum class DataType : int32_t {
    FLOAT32 = 0,  // FP32 độ chính xác đơn (4 bytes)
    INT32   = 1,  // Số nguyên 32-bit (4 bytes)
    INT8    = 2,  // Số nguyên 8-bit định lượng (1 byte)
    UINT8   = 3,  // Số nguyên không dấu 8-bit (ảnh RGB/RGBA) (1 byte)
    FLOAT16 = 4,  // Nửa độ chính xác FP16 (2 bytes)
    INT64   = 5   // Số nguyên 64-bit (8 bytes)
};

// ----------------------------------------------------------------------
// DataFormat Enum (Định dạng bố cục bộ nhớ Tensor)
// Opcode: 0x91d1 ("ByteNN unsupported DataFormat: %d")
// ----------------------------------------------------------------------
enum class DataFormat : int32_t {
    NCHW = 0,  // Batch, Channels, Height, Width (Chuẩn ByteNN)
    NHWC = 1   // Batch, Height, Width, Channels (Chuẩn GPU / TFLite)
};

// ----------------------------------------------------------------------
// Error Structure (Cấu trúc báo cáo lỗi Pitaya chuẩn)
// ----------------------------------------------------------------------
struct Error {
    int32_t code{0};
    std::string domain{"PTY-ByteNNEngine"};
    std::string message{""};

    Error() = default;
    Error(int32_t c, const std::string& dom, const std::string& msg)
        : code(c), domain(dom), message(msg) {}

    bool IsSuccess() const noexcept { return code == 0; }
    void Set(int32_t c, const std::string& msg) {
        code = c;
        message = msg;
    }
};

// ----------------------------------------------------------------------
// Tensor Structure (Cấu trúc Tensor dữ liệu của Pitaya)
// Demangled: pitaya::Tensor
// ----------------------------------------------------------------------
class Tensor {
public:
    Tensor();
    Tensor(const Tensor& other);
    Tensor(Tensor&& other) noexcept;
    ~Tensor();

    Tensor& operator=(const Tensor& other);
    Tensor& operator=(Tensor&& other) noexcept;

    // Phân bổ bộ nhớ tensor
    void Allocate(const std::vector<int32_t>& dims, DataType type, DataFormat format = DataFormat::NCHW);
    void SetData(const void* data, size_t byte_size);

    // Truy xuất thông tin
    size_t size() const noexcept;
    size_t GetByteSize() const noexcept;
    void* GetData() noexcept { return data_; }
    const void* GetData() const noexcept { return data_; }
    const std::vector<int32_t>& GetDims() const noexcept { return dims_; }
    DataType GetDataType() const noexcept { return data_type_; }
    DataFormat GetDataFormat() const noexcept { return data_format_; }
    const std::string& GetName() const noexcept { return name_; }
    void SetName(const std::string& name) { name_ = name; }

    int32_t Batch() const noexcept { return dims_.size() > 0 ? dims_[0] : 1; }
    int32_t Channel() const noexcept { return dims_.size() > 1 ? dims_[1] : 1; }
    int32_t Height() const noexcept { return dims_.size() > 2 ? dims_[2] : 1; }
    int32_t Width() const noexcept { return dims_.size() > 3 ? dims_[3] : 1; }

private:
    void* data_{nullptr};
    size_t byte_size_{0};
    std::vector<int32_t> dims_;
    DataType data_type_{DataType::FLOAT32};
    DataFormat data_format_{DataFormat::NCHW};
    std::string name_{""};
    bool owns_data_{false};
};

// ----------------------------------------------------------------------
// ModelMeta Structure (Thông tin định danh mô hình)
// Demangled: pitaya::ModelMeta
// ----------------------------------------------------------------------
struct ModelMeta {
    std::string model_name{""};
    ForwardType forward_type{ForwardType::FORWARD_CPU};
    std::string model_path{""};
    std::string cache_path{""};
    int32_t thread_num{4};
    bool enable_fp16{false};

    ModelMeta() = default;
    ModelMeta(std::string name, ForwardType fwd)
        : model_name(std::move(name)), forward_type(fwd) {}
    ~ModelMeta() = default;
};

// ----------------------------------------------------------------------
// ModelConfig Structure (Cấu hình chi tiết tải mô hình)
// ----------------------------------------------------------------------
struct ModelConfig {
    std::string model_dir{""};
    std::string model_file_name{""};
    ForwardType forward_type{ForwardType::FORWARD_CPU};
    int32_t num_threads{4};
    bool dynamic_shape{true};
    std::vector<std::string> input_names;
    std::vector<std::string> output_names;
};

// ----------------------------------------------------------------------
// TaskTrace (Ghi nhật ký đo đạc hiệu năng vi mô)
// Demangled: pitaya::TaskTrace
// ----------------------------------------------------------------------
class TaskTrace {
public:
    TaskTrace() = default;
    explicit TaskTrace(std::string name) : trace_name_(std::move(name)) {}
    ~TaskTrace() = default;

    std::shared_ptr<TaskTrace> CreateSubTrace(const std::string& name);
    std::shared_ptr<TaskTrace> CreateSubTraceWithFlag(const std::string& name, bool flag);
    void Over();

private:
    std::string trace_name_{"root"};
    int64_t start_time_us_{0};
    int64_t end_time_us_{0};
    bool is_over_{false};
};

// ----------------------------------------------------------------------
// Engine Base Class (Lớp trừu tượng động cơ Pitaya)
// Demangled: pitaya::Engine
// ----------------------------------------------------------------------
class Engine {
public:
    virtual ~Engine() = default;
    virtual void ReleaseUse();

    int32_t GetUseCount() const noexcept { return use_count_; }
    void Retain() noexcept { ++use_count_; }

protected:
    int32_t use_count_{1};
};

// ----------------------------------------------------------------------
// ByteNNEngineStone (Đối tượng bảo vệ vòng đời C++)
// Demangled: pitaya::ByteNNEngineStone
// ----------------------------------------------------------------------
class ByteNNEngineStone {
public:
    ByteNNEngineStone();
    ~ByteNNEngineStone();
};

// ----------------------------------------------------------------------
// EngineInfo Structure (Đăng ký động cơ vào hệ thống Pitaya)
// Demangled: pitaya::EngineInfo
// ----------------------------------------------------------------------
struct EngineInfo {
    std::string engine_name{""};
    EngineType engine_type{EngineType::UNKNOWN};
    std::string version{""};
    std::shared_ptr<Engine> (*creator)(){nullptr};

    EngineInfo(std::string name, EngineType type, const std::string& ver, std::shared_ptr<Engine> (*cr)())
        : engine_name(std::move(name)), engine_type(type), version(ver), creator(cr) {}
};

// ----------------------------------------------------------------------
// pitaya::RegisterEngine
// ----------------------------------------------------------------------
void RegisterEngine(EngineInfo* info);

// ----------------------------------------------------------------------
// pitaya::ALogWrapper & Logging Utilities
// ----------------------------------------------------------------------
class ALogWrapper {
public:
    static ALogWrapper& Instance();
    void ALogWrite(uint32_t level, const char* tag, const char* file, const char* func,
                   int32_t line, const char* flag, bool sync, const char* fmt, ...);
};

// ----------------------------------------------------------------------
// pitaya::PathAppend & StrFormat
// ----------------------------------------------------------------------
std::string PathAppend(const std::string& base, const std::string& relative);
std::string StrFormat(const char* fmt, ...);

extern const char* kModelOriginFileName;
extern const char* kDownloadFileName;

} // namespace NextAI::OpenCut::pitaya

// Forward declaration of internal ByteDance ByteNN interfaces
namespace NextAI::OpenCut::bytenn {
    class ByteNNEngine;
    struct Config;
    struct ConfigExt;
    class Tensor;
}

namespace NextAI::OpenCut::pitaya {

// ======================================================================
// ByteNNEngine Class (Lớp triển khai cụ thể Động cơ ByteNN trên Pitaya)
// Vtable layout matches binary at 0xbb08 (virtual methods 0 through 17)
// ======================================================================
class ByteNNEngine : public Engine, public ByteNNEngineStone {
public:
    ByteNNEngine();
    virtual ~ByteNNEngine() override;

    // [0] ReleaseUse (opcode 0x1c00 / 0x3a80)
    virtual void ReleaseUse() override;

    // [1] SetConfig (opcode 0x3a84, line 168)
    virtual int32_t SetConfig(const ModelConfig& config, Error& error);

    // [2] load_model (opcode 0x4878, line 273)
    virtual int32_t load_model(const ModelMeta& meta, Error& error);

    // [3] release_model (opcode 0x4de0)
    virtual void release_model();

    // [4] GetInputConfig (opcode 0x4e24)
    virtual int32_t GetInputConfig(std::vector<Tensor>& configs, Error& error);

    // [5] predict / Inference (opcode 0x57dc, line 413)
    virtual int32_t predict(const std::vector<Tensor>& inputs, std::vector<Tensor>& outputs, Error& error);

    // [6] ReInferShape (opcode 0x5c6c)
    virtual int32_t ReInferShape(int32_t batch, int32_t channel, int32_t height, int32_t width, Error& error);

    // [7] ReinferShapeWithTensors (opcode 0x5f5c)
    virtual int32_t ReinferShapeWithTensors(const std::vector<Tensor>& tensors, Error& error);

    // [8] SetOptimizer (opcode 0x65f8)
    virtual int32_t SetOptimizer(int32_t opt_type, const void* opt_config, Error& error);

    // [9] Step (opcode 0x65fc)
    virtual int32_t Step(Error& error);

    // [10] GetWeight (opcode 0x6664)
    virtual int32_t GetWeight(const std::string& name, Tensor& weight, Error& error);

    // [11] SetWeight (opcode 0x66cc)
    virtual int32_t SetWeight(const std::string& name, const Tensor& weight, Error& error);

    // [12] GetGradient (opcode 0x67e0)
    virtual int32_t GetGradient(const std::string& name, Tensor& grad, Error& error);

    // [13] SetLossLayer (opcode 0x69e4)
    virtual int32_t SetLossLayer(int32_t loss_type, Error& error);

    // [14] SetLabel (opcode 0x6ab4)
    virtual int32_t SetLabel(const Tensor& label, Error& error);

    // [15] SaveModel (opcode 0x6ab4 & 0x2b00)
    virtual int32_t SaveModel(const std::string& save_path, Error& error);

    // [16] Train (opcode 0x6b1c)
    virtual int32_t Train(Error& error);

    // [17] Reserved/Extended (opcode 0x6b84)
    virtual int32_t ExtendedOp(int32_t op_code, void* params, Error& error);

    // Internal validation method (opcode 0x3780, line 139)
    bool CheckTensorDims(const Tensor& input, int32_t exp_b, int32_t exp_c, int32_t exp_h, int32_t exp_w);

private:
    // Core ByteNN engine delegate (offset +0x28 in struct)
    std::shared_ptr<NextAI::OpenCut::bytenn::ByteNNEngine> bytenn_engine_{nullptr};

    // Stored model configuration and metadata
    ModelConfig config_;
    ModelMeta meta_;
    std::string current_model_path_{""};

    // Input/output tensor specs
    std::vector<Tensor> input_configs_;
    std::vector<Tensor> output_configs_;

    // Thread synchronization mutex
    mutable std::mutex engine_mutex_;

    // Internal model saving routine with mmap (opcode 0x2b00)
    int32_t SaveModelToFile(const std::string& target_path, Error& error);
};

// Factory creator function registered with EngineInfo (opcode 0x395c)
std::shared_ptr<Engine> CreateByteNNEngine();

// Global registration called at .init_array (opcode 0x39c4)
void RegisterByteNNEngineStone();

} // namespace NextAI::OpenCut::pitaya
