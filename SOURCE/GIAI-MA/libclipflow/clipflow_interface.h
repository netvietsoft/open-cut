// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libclipflow.so (ByteDance Vega ClipFlow DAG Task & Agent Engine)
// File: clipflow_interface.h
// Description: ClipflowEngine coordinator, SWIG JNI exports, and automated self-test
// ===================================================================================

#pragma once

#include <jni.h>
#include <string>
#include <vector>
#include <memory>
#include <mutex>

#include "clipflow_types.h"
#include "clipflow_dag.h"
#include "clipflow_agent_tools.h"

namespace NextAI::OpenCut::clipflow {

/**
 * @brief Động cơ điều phối hợp nhất ClipflowEngine
 * Kết nối đồ thị tác vụ DAG (TaskGrapher) và bộ thực thi công cụ Agent AI (ClipflowAgentToolsExecutor)
 */
class ClipflowEngine {
public:
    ClipflowEngine();
    virtual ~ClipflowEngine();

    /// Truy cập TaskGrapher
    ::clipflow::TaskGrapher* getTaskGrapher() { return m_grapher.get(); }

    /// Truy cập AgentToolsExecutor
    ::clipflow::ClipflowAgentToolsExecutor* getAgentToolsExecutor() { return m_agent_executor.get(); }

    /// Xử lý đồng bộ yêu cầu từ ClipflowServer (Khớp Java_com_vega_clipflow_ClipflowServer_invokeSync)
    std::string invokeSync(const std::string& request_json);

    /// Bộ 8 bài tự kiểm chứng khép kín (8-Point Self-Test Suite)
    static bool runSelfTest();

private:
    std::unique_ptr<::clipflow::TaskGrapher> m_grapher;
    std::unique_ptr<::clipflow::ClipflowAgentToolsExecutor> m_agent_executor;
    std::mutex m_engine_mutex;
};

// ===================================================================================
// JNI Exported Functions (Khớp bảng ký hiệu libclipflow.so)
// ===================================================================================

extern "C" {
    JNIEXPORT jstring JNICALL Java_com_vega_clipflow_ClipflowServer_invokeSync(
        JNIEnv *env, jobject thiz, jstring request);

    JNIEXPORT jlong JNICALL Java_com_vega_clipflow_swig_CreateTaskGrapherModuleJNI_CreateTaskGrapherRespStruct_1SWIGSmartPtrUpcast(
        JNIEnv *env, jobject thiz, jlong cptr);

    JNIEXPORT jint JNICALL Java_com_vega_clipflow_swig_RunAgentToolsExecutorModuleJNI_RunAgentToolsExecutorRespStruct_1state_1get(
        JNIEnv *env, jobject thiz, jlong cptr);

    JNIEXPORT jint JNICALL Java_com_vega_clipflow_swig_RunAgentToolsExecutorModuleJNI_RunAgentToolsExecutorRespStruct_1code_1get(
        JNIEnv *env, jobject thiz, jlong cptr);

    JNIEXPORT void JNICALL Java_com_vega_clipflow_swig_ClipflowAgentToolsExecutorParamsModuleJNI_ClipflowAgentToolsExecutorParams_1independent_1node_1thread_1pool_1size_1set(
        JNIEnv *env, jobject thiz, jlong cptr, jint size);

    JNIEXPORT void JNICALL Java_com_vega_clipflow_swig_QueryAgentToolsExecutorTaskInCacheModuleJNI_QueryAgentToolsExecutorTaskInCacheRespStruct_1is_1in_1cache_1set(
        JNIEnv *env, jobject thiz, jlong cptr, jboolean is_in_cache);
}

} // namespace NextAI::OpenCut::clipflow
