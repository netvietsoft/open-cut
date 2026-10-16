// ======================================================================
// RECONSTRUCTED HEADER: pitaya_engine_bytedt.h
// Library: libByteAIDT.so (ByteDance Pitaya ByteDT Decision Tree Bridge)
// Component: NextAI OpenCut AI & Decision Tree Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Reconstructed header for ByteDance's Pitaya-to-ByteDT Decision Tree Engine Bridge.
//   Binds Pitaya On-Device AI Core (libAndroidPitayaCore.so) to ByteDT (libbytedt.so).
//   Implements ByteDTEngine inheriting from pitaya::Engine, supporting fast on-device
//   GBDT / Random Forest inference, leaf index prediction, probability/class/score outputs,
//   and TaskTrace profiling.
//
// Mô tả (Tiếng Việt):
//   Tệp tiêu đề tái dựng cho Cầu nối Động cơ Cây Quyết định ByteDT nền tảng Pitaya ByteDance.
//   Gắn kết lõi AI trên thiết bị Pitaya (libAndroidPitayaCore.so) với ByteDT (libbytedt.so).
//   Triển khai ByteDTEngine kế thừa từ pitaya::Engine, hỗ trợ suy luận cây quyết định
//   GBDT / Random Forest nhanh chóng tại chỗ, dự đoán chỉ số lá (leaf prediction),
//   xuất kết quả xác suất/lớp/điểm số (probability/class/score), và đo đạc với TaskTrace.
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

// Forward declaration of common pitaya types
enum class EngineType : int32_t {
    UNKNOWN     = 0,
    BYTENN      = 1,
    BYTEDT      = 2,  // ByteDance Decision Tree
    PNN         = 3,
    PYTHON_VM   = 4
};

enum class DataType : int32_t {
    FLOAT32 = 0,
    INT32   = 1,
    INT8    = 2,
    UINT8   = 3,
    FLOAT16 = 4,
    INT64   = 5
};

// ----------------------------------------------------------------------
// PitayaDTOut (Kết quả đầu ra của cây quyết định Pitaya)
// Demangled: pitaya::PitayaDTOut
// ----------------------------------------------------------------------
class PitayaDTOut {
public:
    PitayaDTOut() = default;
    PitayaDTOut(void* data, size_t size, DataType type, const std::string& name);
    PitayaDTOut(const PitayaDTOut& other);
    PitayaDTOut(PitayaDTOut&& other) noexcept;
    ~PitayaDTOut();

    PitayaDTOut& operator=(const PitayaDTOut& other);
    PitayaDTOut& operator=(PitayaDTOut&& other) noexcept;

    void* GetData() noexcept { return data_; }
    const void* GetData() const noexcept { return data_; }
    size_t GetSize() const noexcept { return size_; }
    DataType GetDataType() const noexcept { return data_type_; }
    const std::string& GetName() const noexcept { return name_; }

private:
    void* data_{nullptr};
    size_t size_{0};
    DataType data_type_{DataType::FLOAT32};
    std::string name_{""};
    bool owns_data_{false};
};

// ----------------------------------------------------------------------
// TaskTrace profiling class
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
// Engine Base Class & EngineStone
// ----------------------------------------------------------------------
class Engine {
public:
    virtual ~Engine() = default;
    virtual void ReleaseUse();
    int32_t GetUseCount() const noexcept { return use_count_; }
protected:
    int32_t use_count_{1};
};

class ByteDTEngineStone {
public:
    ByteDTEngineStone();
    ~ByteDTEngineStone();
};

struct EngineInfo {
    std::string engine_name{""};
    EngineType engine_type{EngineType::UNKNOWN};
    std::string version{""};
    std::shared_ptr<Engine> (*creator)(){nullptr};

    EngineInfo(std::string name, EngineType type, const std::string& ver, std::shared_ptr<Engine> (*cr)())
        : engine_name(std::move(name)), engine_type(type), version(ver), creator(cr) {}
};

void RegisterEngine(EngineInfo* info);

} // namespace NextAI::OpenCut::pitaya

// Forward declaration of internal bytedt namespace
namespace NextAI::OpenCut::bytedt {

enum class ByteDTErrorCode : int32_t {
    SUCCESS                 = 0,
    ERROR_NULL_POINTER      = 1,
    ERROR_INVALID_PARAM     = 2,
    ERROR_MODEL_LOAD        = 3,
    ERROR_MODEL_NOT_FOUND   = 4,
    ERROR_PREDICT           = 5
};

struct Input {
    const float* features{nullptr};
    size_t feature_count{0};
    int32_t batch_size{1};
};

struct RunInfo {
    int32_t thread_num{1};
    int64_t elapsed_us{0};
};

const char* get_version();

class ByteDT {
public:
    virtual ~ByteDT() = default;
    static std::shared_ptr<ByteDT> create_engine();

    virtual int32_t load_model_from_path(const std::string& path) = 0;
    virtual int32_t load_model_from_buffer(const void* buffer, size_t size) = 0;

    virtual std::vector<float> predict(Input in, ByteDTErrorCode& err, RunInfo* info = nullptr) = 0;
    virtual std::vector<int32_t> predict_leaf(Input in, ByteDTErrorCode& err, RunInfo* info = nullptr) = 0;

    virtual int32_t get_feature_num() const = 0;
    virtual int32_t get_tree_num() const = 0;
    virtual int32_t get_max_depth() const = 0;
};

} // namespace NextAI::OpenCut::bytedt

namespace NextAI::OpenCut::pitaya {

// ======================================================================
// ByteDTEngine Class (Lớp động cơ Cây quyết định ByteDT trên Pitaya)
// Vtable layout matches binary at 0x7c70
// ======================================================================
class ByteDTEngine : public Engine, public ByteDTEngineStone {
public:
    ByteDTEngine();
    virtual ~ByteDTEngine() override;

    // [0] ReleaseUse (opcode 0x1110)
    virtual void ReleaseUse() override;

    // [1] load_model (opcode 0x1468)
    virtual int32_t load_model(const std::string& model_path, int32_t& err_code);

    // [2] predict (opcode 0x18bc)
    virtual int32_t predict(const std::vector<float>& features,
                            std::vector<PitayaDTOut>& outputs,
                            int32_t& err_code,
                            TaskTrace* trace = nullptr);

    // [3] predict_leaf (opcode 0x2140)
    virtual int32_t predict_leaf(const std::vector<float>& features,
                                 std::vector<int32_t>& leaf_indices,
                                 int32_t& err_code,
                                 TaskTrace* trace = nullptr);

    // [4] release_model
    virtual void release_model();

    // Model properties queried after load (opcode 0x3743 - 0x3774)
    int32_t GetModelType() const noexcept { return model_type_; }
    int32_t GetTreeRelation() const noexcept { return tree_relation_; }
    int32_t GetTreeSize() const noexcept { return tree_size_; }
    int32_t GetMaxDepth() const noexcept { return max_depth_; }
    int32_t GetNFeature() const noexcept { return n_feature_; }
    bool IsModelLoaded() const noexcept { return is_model_loaded_; }

    // Advanced GBDT Ensemble Utilities
    // Tiện ích phân tích cụm cây quyết định nâng cao
    float ComputeTreeEnsembleVariance(const std::vector<float>& features) const;
    std::vector<float> ComputeFeatureImportance() const;
    void ExportTreeRulesToString(std::string& output_rules) const;

private:
    std::shared_ptr<NextAI::OpenCut::bytedt::ByteDT> dt_engine_{nullptr};
    std::string current_model_path_{""};
    bool is_model_loaded_{false};

    // Metadata properties
    int32_t model_type_{1};      // 1: GBDT, 2: Random Forest, 3: Linear Rule
    int32_t tree_relation_{0};   // Tree aggregation relation
    int32_t tree_size_{0};       // Total number of trees
    int32_t max_depth_{0};       // Maximum tree depth
    int32_t n_feature_{0};       // Number of input features required

    mutable std::mutex dt_mutex_;
};

// Factory creator function registered with EngineInfo (opcode 0x12bc)
std::shared_ptr<Engine> CreateByteDTEngine();

// Global registration called at .init_array (opcode 0x1200)
void RegisterByteDTEngineStone();

} // namespace NextAI::OpenCut::pitaya
