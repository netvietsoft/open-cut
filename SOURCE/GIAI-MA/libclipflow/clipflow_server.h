// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libclipflow.so (ByteDance Vega ClipFlow DAG Task & Agent Engine)
// File: clipflow_server.h
// Description: ClipflowServer Session & RPC Dispatcher
//              Reverse-engineered from ARM64 opcodes 0x1ba13c, 0x1ba5b8, 0x1baa38
// ===================================================================================

#pragma once

#include "clipflow_types.h"
#include "clipflow_dag.h"
#include "clipflow_agent_tools.h"
#include <string>
#include <memory>
#include <mutex>
#include <unordered_map>

namespace clipflow {

using LogFunction = std::function<void(int32_t level, const std::string& tag, const std::string& msg)>;

/**
 * @brief Máy chủ RPC ClipflowServer điều phối phiên làm việc biên tập đa tiến trình
 * (Opcodes 0x1ba13c, 0x1ba5b8, 0x1baa38, 0x1b9d64)
 */
class ClipflowServer {
public:
    static ClipflowServer& getInstance();

    /// Khởi tạo JNI Server (Opcode 0x1baa38: clipflowServerJniInit)
    bool initServer();

    /// Hủy máy chủ và giải phóng tài nguyên
    void releaseServer();

    /// Đăng ký hàm ghi log (Opcode 0x1b9d64: setLogFunction)
    void setLogFunction(LogFunction log_func);

    /// Thực thi lệnh đồng bộ (Opcode 0x1ba13c: invokeSync)
    std::string invokeSync(const std::string& request_payload);

    /// Thực thi lệnh bất đồng bộ (Opcode 0x1ba5b8: invokeAsync)
    void invokeAsync(
        const std::string& request_payload,
        std::function<void(int32_t code, const std::string& response)> callback
    );

    /// Quản lý đồ thị DAG theo session_id
    std::shared_ptr<TaskGrapher> getOrCreateGraph(const std::string& session_id);
    bool destroyGraph(const std::string& session_id);

    /// Quản lý bộ thực thi Agent Tools
    std::shared_ptr<ClipflowAgentToolsExecutor> getAgentExecutor() { return m_agent_executor; }

private:
    ClipflowServer();
    ~ClipflowServer();

    mutable std::mutex m_server_mutex;
    bool m_is_initialized;
    LogFunction m_log_func;

    std::unordered_map<std::string, std::shared_ptr<TaskGrapher>> m_session_graphs;
    std::shared_ptr<ClipflowAgentToolsExecutor> m_agent_executor;
};

} // namespace clipflow
