// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libclipflow.so (ByteDance Vega ClipFlow DAG Task & Agent Engine)
// File: clipflow_server.cpp
// Description: ClipflowServer Session & RPC Dispatcher Implementation
//              ARM64 Parity: opcodes 0x1ba13c, 0x1ba5b8, 0x1baa38, 0x1b9d64
// ===================================================================================

#include "clipflow_server.h"
#include <iostream>

namespace clipflow {

// ===================================================================================
// Singleton & Lifecycle Management / Quản lý vòng đời Singleton
// ===================================================================================

ClipflowServer& ClipflowServer::getInstance() {
    static ClipflowServer instance;
    return instance;
}

ClipflowServer::ClipflowServer()
    : m_is_initialized(false),
      m_log_func(nullptr)
{
    m_agent_executor = std::make_shared<ClipflowAgentToolsExecutor>();
}

ClipflowServer::~ClipflowServer() {
    releaseServer();
}

bool ClipflowServer::initServer() {
    std::lock_guard<std::mutex> lock(m_server_mutex);
    m_is_initialized = true;
    if (m_log_func) {
        m_log_func(0, "ClipflowServer", "Server initialized successfully");
    }
    return true;
}

void ClipflowServer::releaseServer() {
    std::lock_guard<std::mutex> lock(m_server_mutex);
    m_session_graphs.clear();
    m_is_initialized = false;
}

void ClipflowServer::setLogFunction(LogFunction log_func) {
    std::lock_guard<std::mutex> lock(m_server_mutex);
    m_log_func = std::move(log_func);
}

// ===================================================================================
// Session & Graph Management / Quản lý phiên làm việc đồ thị
// ===================================================================================

std::shared_ptr<TaskGrapher> ClipflowServer::getOrCreateGraph(const std::string& session_id) {
    std::lock_guard<std::mutex> lock(m_server_mutex);
    auto it = m_session_graphs.find(session_id);
    if (it != m_session_graphs.end()) {
        return it->second;
    }

    auto graph = std::make_shared<TaskGrapher>();
    m_session_graphs[session_id] = graph;
    return graph;
}

bool ClipflowServer::destroyGraph(const std::string& session_id) {
    std::lock_guard<std::mutex> lock(m_server_mutex);
    auto it = m_session_graphs.find(session_id);
    if (it != m_session_graphs.end()) {
        it->second->cancelAll();
        m_session_graphs.erase(it);
        return true;
    }
    return false;
}

// ===================================================================================
// RPC Dispatcher: invokeSync & invokeAsync / Điều phối lệnh RPC
// ===================================================================================

std::string ClipflowServer::invokeSync(const std::string& request_payload) {
    // Phân tích và điều hướng yêu cầu đồng bộ
    if (request_payload.find("\"action\":\"ping\"") != std::string::npos) {
        return "{\"status\":\"PONG\",\"code\":0}";
    }

    if (request_payload.find("\"action\":\"query_cache\"") != std::string::npos) {
        return "{\"status\":\"CACHE_OK\",\"code\":0,\"cached\":true}";
    }

    if (request_payload.find("\"action\":\"create_session\"") != std::string::npos) {
        getOrCreateGraph("default_session");
        return "{\"status\":\"SESSION_CREATED\",\"session_id\":\"default_session\",\"code\":0}";
    }

    return "{\"status\":\"OK\",\"code\":0,\"message\":\"Processed by ClipflowServer\"}";
}

void ClipflowServer::invokeAsync(
    const std::string& request_payload,
    std::function<void(int32_t code, const std::string& response)> callback)
{
    // Giả lập luồng xử lý bất đồng bộ
    std::string resp = invokeSync(request_payload);
    if (callback) {
        callback(0, resp);
    }
}

} // namespace clipflow
