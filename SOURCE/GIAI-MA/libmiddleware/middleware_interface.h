// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_interface.h
// Description: MiddlewareEngine coordinator, JNI exports, and automated self-test
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <jni.h>
#include <string>
#include <vector>
#include <memory>
#include <mutex>

#include "middleware_types.h"
#include "middleware_scene_graph.h"
#include "middleware_crop_room.h"
#include "middleware_batch_push.h"
#include "middleware_autolayout.h"
#include "middleware_text_template.h"
#include "middleware_cutout_brush.h"

namespace NextAI::OpenCut::middleware {

/**
 * @brief Động cơ Middleware trung tâm điều phối NLE CrossPlatform
 * Khôi phục từ singleton context 0x9b2f20 và vtable offset 0x3a0
 */
class MiddlewareEngine {
public:
    static MiddlewareEngine& getInstance();

    ::retouch::middleware::SceneGraph* getSceneGraph() { return m_scene_graph.get(); }
    ::retouch::middleware::CropRoom* getCropRoom() { return m_crop_room.get(); }
    ::retouch::middleware::BatchPushManager* getBatchPushManager() { return m_batch_push.get(); }
    ::retouch::middleware::AutoLayoutEngine* getAutoLayoutEngine() { return m_autolayout.get(); }
    ::retouch::middleware::TextTemplateManager* getTextTemplateManager() { return m_text_template.get(); }
    ::retouch::middleware::CutoutBrushManager* getCutoutBrushManager() { return m_cutout_brush.get(); }

    void reset();

    /// Bộ kiểm chứng tự động khép kín toàn diện (Comprehensive Automated Self-Test Suite)
    static bool runSelfTest();

private:
    MiddlewareEngine();
    ~MiddlewareEngine() = default;

    std::unique_ptr<::retouch::middleware::SceneGraph> m_scene_graph;
    std::unique_ptr<::retouch::middleware::CropRoom> m_crop_room;
    std::unique_ptr<::retouch::middleware::BatchPushManager> m_batch_push;
    std::unique_ptr<::retouch::middleware::AutoLayoutEngine> m_autolayout;
    std::unique_ptr<::retouch::middleware::TextTemplateManager> m_text_template;
    std::unique_ptr<::retouch::middleware::CutoutBrushManager> m_cutout_brush;
    std::mutex m_engine_mutex;
};

// ===================================================================================
// JNI Exported Functions (Khớp bảng ký hiệu libmiddleware.so)
// ===================================================================================

extern "C" {
    // CrossPlatformInterface Core
    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeInit(
        JNIEnv *env, jobject thiz);

    JNIEXPORT jfloat JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeGetGlobalScale(
        JNIEnv *env, jobject thiz);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeScale(
        JNIEnv *env, jobject thiz, jfloat scale_x, jfloat scale_y, jint layer_id);

    JNIEXPORT jfloat JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeQueryLayerRotate(
        JNIEnv *env, jobject thiz, jint layer_id);

    JNIEXPORT jfloatArray JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeGetLayerAABBBox(
        JNIEnv *env, jobject thiz, jint layer_id);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeMoveLayerOfSiblingNode(
        JNIEnv *env, jobject thiz, jint layer_id, jint direction);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeBeginBatchPush(
        JNIEnv *env, jobject thiz);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeEndBatchPush(
        JNIEnv *env, jobject thiz);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeEnterImageContentCropRoom(
        JNIEnv *env, jobject thiz, jint layer_id, jfloat l, jfloat t, jfloat r, jfloat b, jfloat aspect_ratio);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeExitImageContentCropRoom(
        JNIEnv *env, jobject thiz, jboolean apply);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeResetInImageContentCropRoom(
        JNIEnv *env, jobject thiz);

    JNIEXPORT jint JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeGetGroupLayerId(
        JNIEnv *env, jobject thiz, jint layer_id);

    // RetouchSceneModelApi
    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_initBach(
        JNIEnv *env, jobject thiz, jstring config);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_touchDownEvent(
        JNIEnv *env, jobject thiz, jfloat x, jfloat y);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_panEvent(
        JNIEnv *env, jobject thiz, jfloat dx, jfloat dy);

    JNIEXPORT jboolean JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_isLayerVisible(
        JNIEnv *env, jobject thiz, jint layer_id);

    // RetouchTextSdkModule (Opcode 0x12f7c28, 0x12f5bb4, 0x12f5f5c)
    JNIEXPORT jobjectArray JNICALL Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeGetTextTemplateTitles(
        JNIEnv *env, jobject thiz, jint template_id);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeSetTextFont(
        JNIEnv *env, jobject thiz, jint template_id, jint item_index, jstring font_path, jstring font_name);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeSetTextTemplateFontByIndex(
        JNIEnv *env, jobject thiz, jint template_id, jint item_index, jint font_index);

    // Cutout & Brush & AI Background (Opcode 0x12f4f48, 0x12f2f10, 0x12f6730)
    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_setCutoutBrushData(
        JNIEnv *env, jobject thiz, jfloat x, jfloat y, jfloat radius, jfloat hardness,
        jfloat opacity, jfloat aspect_ratio, jfloat angle_deg, jint mode, jint stroke_id, jint layer_id);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_cutout_IntelligentMaskCallbackJniImpl_nativeOnIntelligentMaskResult(
        JNIEnv *env, jobject thiz, jint status_code, jbyteArray mask_data, jint width, jint height, jint stride, jint target_layer_id);

    JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_cancelAIBackgroundPreview(
        JNIEnv *env, jobject thiz);
}

} // namespace NextAI::OpenCut::middleware
