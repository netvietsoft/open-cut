// ======================================================================
// RECONSTRUCTED HEADER: pitaya_task_executor.h
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Task scheduling, dynamic thread pool with SetConcurrency parity
//   (opcode 0x1b7cac), TaskTrace telemetry, and ByteDT / ByteNN
//   Engine Stone adapters reverse-engineered from Pitaya Core.
//
// Mô tả (Tiếng Việt):
//   Lập lịch tác vụ, thread pool động tương thích SetConcurrency
//   (opcode 0x1b7cac), đo đạc hiệu năng TaskTrace và các adapter
//   Engine Stone ByteDT / ByteNN dịch ngược từ Pitaya Core.
// ======================================================================

#pragma once

#include "pitaya_types.h"
#include "pitaya_objects.h"
#include <string>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// TaskTrace: Giám sát đo đạc thời gian chạy (Tracing Span)
// Demangled: pitaya::TaskTrace (opcode 0xaac04)
// ----------------------------------------------------------------------
class TaskTrace {
public:
    explicit TaskTrace(const std::string& trace_name);
    ~TaskTrace() = default;

    static TaskTracePtr MakeTrace(const std::string& trace_name);

    void AddSpan(const std::string& span_name);
    void EndSpan(const std::string& span_name);
    void Over();

    double DurationMs() const noexcept;
    std::string DumpJSON() const;

private:
    std::string trace_name_;
    std::chrono::steady_clock::time_point start_time_;
    std::chrono::steady_clock::time_point end_time_;
    std::unordered_map<std::string, double> spans_ms_;
    bool is_over_{false};
    mutable std::mutex mutex_;
};

// ----------------------------------------------------------------------
// TaskData (Dữ liệu đầu vào và đầu ra của Task)
// Demangled: pitaya::TaskData (opcode 0xaa898)
// ----------------------------------------------------------------------
class TaskData {
public:
    TaskData();
    explicit TaskData(const PTYDictPtr& params);
    ~TaskData() = default;

    PTYDictPtr Params() const noexcept { return params_; }
    void SetParams(const PTYDictPtr& p) noexcept { params_ = p; }

    PTYObjectPtr Get(const std::string& key) const;
    void Set(const std::string& key, const PTYObjectPtr& val);

private:
    PTYDictPtr params_;
};

// ----------------------------------------------------------------------
// TaskConfig (Cấu hình thực thi của Task)
// Demangled: pitaya::TaskConfig
// ----------------------------------------------------------------------
class TaskConfig {
public:
    TaskConfig() = default;
    ~TaskConfig() = default;

    int32_t priority{0};        // Độ ưu tiên (0: Bình thường, 1: Cao, -1: Thấp)
    double timeout_seconds{5.0}; // Hạn giờ thực thi
    bool sync_mode{false};       // Đồng bộ hay bất đồng bộ
    std::string business_name{""};
};

// ----------------------------------------------------------------------
// ByteDT Engine Stone (Decision Tree Rule Evaluator)
// Demangled: pitaya::ByteDTEngineStone (opcode 0xee040)
// ----------------------------------------------------------------------
class ByteDTEngineStone {
public:
    static PTYDictPtr EvaluateRules(const PTYDictPtr& features, const std::string& rule_tree_json);
};

// ----------------------------------------------------------------------
// TaskExecutor (Bộ điều phối thực thi luồng song song)
// Demangled: pitaya::TaskExecutor (opcode 0x1b7cac)
// ----------------------------------------------------------------------
class TaskExecutor {
public:
    static TaskExecutor& Instance();

    // Thiết lập độ song song của luồng (Opcode 0x1b7cac)
    void SetConcurrency(int32_t concurrency);
    int32_t GetConcurrency() const noexcept { return concurrency_; }

    // Đẩy tác vụ vào hàng đợi thực thi
    void EnqueueTask(std::function<void()> task);

    // Dừng toàn bộ các luồng công việc
    void Shutdown();

private:
    TaskExecutor();
    ~TaskExecutor();

    void WorkerLoop();

    int32_t concurrency_{4};
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> task_queue_;
    std::mutex queue_mutex_;
    std::condition_variable cv_;
    bool stop_{false};
};

// ----------------------------------------------------------------------
// TaskManager (Quản lý các loại Task)
// Demangled: pitaya::TaskManager
// ----------------------------------------------------------------------
class TaskManager {
public:
    static TaskManager& Instance();

    int32_t RunTask(const std::string& task_name, 
                    const TaskDataPtr& in_data, 
                    const TaskConfigPtr& config, 
                    TaskCallback callback, 
                    const TaskTracePtr& trace = nullptr);
};

// Exported C runner: PTYRunTask (opcode 0x1d62d0)
extern "C" {
    int32_t PTYRunTask(const char* task_name, void* in_data, void* config, void* callback);
}

} // namespace NextAI::OpenCut::pitaya
