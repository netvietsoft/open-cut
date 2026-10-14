// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libclipflow.so (ByteDance Vega ClipFlow DAG Task & Agent Engine)
// File: clipflow_agent_tools.h
// Description: Autonomous AI Agent Tools Executor
//              Reverse-engineered from ARM64 opcodes 0x264b30, 0x2679c4, 0x26bdb4, 0x20b040
// ===================================================================================

#pragma once

#include "clipflow_types.h"
#include <mutex>
#include <thread>
#include <atomic>

namespace clipflow {

// Kiểu xử lý công cụ AI Agent độc lập
using ToolHandler = std::function<bool(
    const std::string& task_id,
    const std::unordered_map<std::string, std::string>& params,
    std::vector<std::string>& outputs
)>;

/**
 * @brief Bộ thực thi công cụ Agent AI (ClipflowAgentToolsExecutor)
 * Cho phép các AI Agent trong ứng dụng NLE gọi các công cụ biên tập thông minh:
 * tự động cắt nhịp, phát hiện phách nhạc, tách âm sắc giọng nói, tự sinh phụ đề.
 */
class ClipflowAgentToolsExecutor {
public:
    ClipflowAgentToolsExecutor();
    ~ClipflowAgentToolsExecutor();

    /// Thực thi công cụ Agent bất đồng bộ (Khớp opcode 0x264b30: ClipflowAgentToolsExecutor::execute)
    void execute(
        const std::string& task_id,
        const std::shared_ptr<ClipflowAgentToolsExecutorParams>& params,
        AgentToolsCallback callback
    );

    /// Thực thi nội bộ kèm quản lý bộ nhớ đệm (Khớp opcode 0x2679c4: ClipflowAgentToolsExecutor::_execute)
    void _execute(
        const std::string& task_id,
        const std::shared_ptr<ClipflowAgentToolsExecutorParams>& params,
        const std::shared_ptr<ClipflowTaskCacheInfo>& cache_info,
        AgentToolsCallback callback
    );

    /// Hủy tác vụ công cụ Agent (Khớp opcode 0x26bdb4: ClipflowAgentToolsExecutor::cancel)
    bool cancel(const std::string& task_id);

    /// Truy vấn kết quả tác vụ trong bộ nhớ đệm cache (Khớp opcode 0x36a6a8)
    bool queryTaskInCache(const std::string& task_id, ClipflowTaskCacheInfo& out_info) const;

    /// Cài đặt số luồng thread pool độc lập (Khớp opcode 0x20b040)
    void setThreadPoolSize(int32_t size);
    int32_t getThreadPoolSize() const { return m_thread_pool_size; }

    /// Đăng ký công cụ biên tập tùy biến
    void registerTool(const std::string& tool_name, ToolHandler handler);

    /// Kiểm tra trạng thái tác vụ
    bool isTaskRunning(const std::string& task_id) const;

private:
    mutable std::mutex m_executor_mutex;
    int32_t m_thread_pool_size; // Opcode 0x20b040 (Mặc định: 4)

    std::unordered_map<std::string, ToolHandler> m_registered_tools;
    std::unordered_map<std::string, ClipflowTaskCacheInfo> m_cache;
    std::unordered_set<std::string> m_running_tasks;
    std::unordered_set<std::string> m_cancelled_tasks;

    void registerDefaultBuiltinTools();
};

} // namespace clipflow
