// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libclipflow.so (ByteDance Vega ClipFlow DAG Task & Agent Engine)
// File: clipflow_types.h
// Description: Data contracts, DAG task execution states, agent tool executor params,
//              and AArch64 ABI layout reverse-engineered from opcodes 0x39e13c, 0x39e808,
//              0x264b30, 0x2679c4, 0x20b040.
// ===================================================================================

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <functional>
#include <chrono>

namespace clipflow {

// ===================================================================================
// 1. TASK EXECUTION STATES & EVENT TYPES
// Trạng thái thực thi tác vụ đồ thị và sự kiện vòng đời
// ===================================================================================

enum class ClipFlowTaskExecuteState : int32_t {
    IDLE = 0,         // Chờ kích hoạt
    RUNNING = 1,      // Đang xử lý
    SUCCESS = 2,      // Thành công
    FAILED = 3,       // Thất bại
    CANCELLED = -4,   // Bị hủy (Khớp opcode 0x39e848: cmn w0, #4 -> w0 == -4)
    TIMEOUT = 5       // Quá thời gian quy định
};

enum class ClipFlowEventType : int32_t {
    UNKNOWN = 0,
    TASK_START = 1,
    TASK_FINISH = 2,
    TASK_CANCEL = 3,
    TASK_ERROR = 4,
    NODE_START = 5,
    NODE_FINISH = 6,
    STAGE_RESULT = 7
};

// ===================================================================================
// 2. NODE & TASK DESCRIPTORS
// Mô tả nút đồ thị và giao diện tác vụ
// ===================================================================================

struct ClipflowNodeDesc {
    std::string node_id;
    std::string node_name;
    std::string stage_id;
    std::vector<std::string> dependencies; // Danh sách node_id tiên quyết
    int32_t priority;

    ClipflowNodeDesc() : priority(0) {}
};

class IClipFlowTask {
public:
    virtual ~IClipFlowTask() = default;

    virtual const std::string& getTaskId() const = 0;
    virtual const std::string& getTaskType() const = 0;
    virtual int32_t getPriority() const = 0;

    /// Hàm thực thi ảo tương ứng với vtable offset 0x100 (opcode 0x39e840: ldr x9, [x9, #0x100])
    virtual ClipFlowTaskExecuteState execute() = 0;

    /// Hàm hủy tác vụ khi có yêu cầu dừng khẩn cấp
    virtual void cancel() = 0;
};

// ===================================================================================
// 3. AGENT TOOLS EXECUTOR PARAMETERS
// Tham số cấu hình bộ thực thi công cụ Agent AI (Opcode 0x20b040, 0x264b30)
// ===================================================================================

struct ClipflowAgentToolsExecutorParams {
    std::string session_id;                           // Định danh phiên làm việc NLE
    std::string strategy;                             // Chiến lược thực thi (VD: "PARALLEL_ASYNC", "PIPELINE")
    int32_t independent_node_thread_pool_size;        // Kích thước thread pool độc lập (Mặc định: 4, opcode 0x20b040)
    std::string restore_task_id;                      // ID tác vụ phục hồi nếu có checkpoint
    bool need_independent_node_thread_pool;           // Cờ kích hoạt thread pool riêng biệt
    std::unordered_map<std::string, std::string> extra_params;

    ClipflowAgentToolsExecutorParams()
        : independent_node_thread_pool_size(4),
          need_independent_node_thread_pool(true) {}
};

// Cấu trúc cache kết quả tác vụ để tránh tính toán lặp lại
struct ClipflowTaskCacheInfo {
    std::string task_id;
    std::string cache_key;
    std::string output_path;
    int64_t timestamp;
    bool is_valid;

    ClipflowTaskCacheInfo() : timestamp(0), is_valid(false) {}
};

// Định nghĩa callback nhận tiến trình thực thi của Agent Tools
using AgentToolsCallback = std::function<void(
    ClipFlowTaskExecuteState state,
    int32_t code,
    const std::string& message,
    const std::vector<std::string>& outputs
)>;

} // namespace clipflow
