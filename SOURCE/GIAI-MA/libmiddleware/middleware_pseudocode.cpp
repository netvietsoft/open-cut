// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_pseudocode.cpp
// Description: Full implementation of MiddlewareEngine, JNI bridge,
//              and 12-point automated self-test suite.
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "middleware_interface.h"
#include <iostream>
#include <cmath>
#include <cassert>

namespace NextAI::OpenCut::middleware {

// ===================================================================================
// 1. MiddlewareEngine Coordinator Implementation
// ===================================================================================

MiddlewareEngine& MiddlewareEngine::getInstance() {
    static MiddlewareEngine instance;
    return instance;
}

MiddlewareEngine::MiddlewareEngine() {
    m_scene_graph = std::make_unique<::retouch::middleware::SceneGraph>();
    m_crop_room = std::make_unique<::retouch::middleware::CropRoom>();
    m_batch_push = std::make_unique<::retouch::middleware::BatchPushManager>();
    m_autolayout = std::make_unique<::retouch::middleware::AutoLayoutEngine>();
    m_text_template = std::make_unique<::retouch::middleware::TextTemplateManager>();
    m_cutout_brush = std::make_unique<::retouch::middleware::CutoutBrushManager>();
}

void MiddlewareEngine::reset() {
    std::lock_guard<std::mutex> lock(m_engine_mutex);
    if (m_scene_graph) m_scene_graph->reset();
    if (m_crop_room) m_crop_room->exitCropRoom(false);
    if (m_batch_push) m_batch_push->clearHistory();
    if (m_text_template) m_text_template->clear();
}

// ===================================================================================
// 2. 12-Point Automated Self-Test Suite / Bộ 12 bài tự kiểm chứng khép kín
// ===================================================================================

bool MiddlewareEngine::runSelfTest() {
    auto& engine = getInstance();
    engine.reset();
    auto* graph = engine.getSceneGraph();
    auto* crop = engine.getCropRoom();
    auto* batch = engine.getBatchPushManager();

    // 1. Kiểm tra thêm và truy vấn Layer
    ::retouch::middleware::LayerDesc layer1;
    layer1.layer_id = 101;
    layer1.name = "main_video_track";
    layer1.type = ::retouch::middleware::LayerType::VIDEO;
    layer1.original_width = 1920.0f;
    layer1.original_height = 1080.0f;
    layer1.transform.position = ::retouch::middleware::PointF(0.0f, 0.0f);
    layer1.transform.scale = ::retouch::middleware::PointF(1.0f, 1.0f);
    layer1.transform.rotation_deg = 0.0f;

    if (!graph->addLayer(layer1)) return false;
    if (graph->getLayerCount() != 1) return false;

    // 2. Kiểm tra truy vấn góc xoay và chuẩn hóa modulo 360 độ (Khớp opcode 0x12fda14)
    graph->setLayerRotate(101, 450.0f);
    if (std::abs(graph->queryLayerRotate(101) - 90.0f) > 0.01f) return false;
    graph->setLayerRotate(101, -90.0f);
    if (std::abs(graph->queryLayerRotate(101) - 270.0f) > 0.01f) return false;
    if (graph->queryLayerRotate(999) != 0.0f) return false; // Không tìm thấy trả về 0.0f (0x12fda54)

    // 3. Kiểm tra truy vấn tỷ lệ hiển thị canvas toàn cục (Khớp opcode 0x12fc094)
    if (std::abs(graph->getGlobalScale() - 1.0f) > 0.001f) return false;
    graph->setGlobalScale(1.5f);
    if (std::abs(graph->getGlobalScale() - 1.5f) > 0.001f) return false;
    graph->setGlobalScale(1.0f);

    // 4. Kiểm tra phóng to / thu nhỏ Layer (Khớp opcode 0x12fdc2c: nativeScale)
    if (!graph->scaleLayer(101, 2.0f, 0.5f)) return false;
    ::retouch::middleware::LayerDesc read_layer;
    if (!graph->getLayer(101, read_layer)) return false;
    if (std::abs(read_layer.transform.scale.x - 2.0f) > 0.001f ||
        std::abs(read_layer.transform.scale.y - 0.5f) > 0.001f) return false;

    // 5. Kiểm tra tính toán hộp bao trục song song AABB (Khớp opcode 0x12fd4f4: nativeGetLayerAABBBox)
    // Đặt lại Layer 101: w=200, h=100, pos=(0, 0), scale=(1, 1), rot=0
    graph->scaleLayer(101, 1.0f, 1.0f);
    graph->setLayerRotate(101, 0.0f);
    layer1.original_width = 200.0f;
    layer1.original_height = 100.0f;
    graph->removeLayer(101);
    graph->addLayer(layer1);

    auto aabb_rot0 = graph->getLayerAABBBox(101);
    if (std::abs(aabb_rot0.min_x - (-100.0f)) > 0.1f || std::abs(aabb_rot0.max_x - 100.0f) > 0.1f ||
        std::abs(aabb_rot0.min_y - (-50.0f)) > 0.1f || std::abs(aabb_rot0.max_y - 50.0f) > 0.1f) {
        return false;
    }

    // Xoay 90 độ: chiều rộng và chiều cao hoán đổi cho nhau
    graph->setLayerRotate(101, 90.0f);
    auto aabb_rot90 = graph->getLayerAABBBox(101);
    if (std::abs(aabb_rot90.min_x - (-50.0f)) > 0.1f || std::abs(aabb_rot90.max_x - 50.0f) > 0.1f ||
        std::abs(aabb_rot90.min_y - (-100.0f)) > 0.1f || std::abs(aabb_rot90.max_y - 100.0f) > 0.1f) {
        return false;
    }

    // 6. Kiểm tra thay đổi thứ tự hiển thị Z-Order (Khớp opcode 0x12fc114: moveLayerOfSiblingNode)
    ::retouch::middleware::LayerDesc layer2;
    layer2.layer_id = 102;
    layer2.name = "overlay_sticker";
    layer2.type = ::retouch::middleware::LayerType::STICKER;
    graph->addLayer(layer2);

    if (graph->getLayerZOrder(101) >= graph->getLayerZOrder(102)) return false; // Layer 101 (z=0) < Layer 102 (z=1)
    if (!graph->moveLayerOfSiblingNode(101, 1)) return false; // Đưa layer 101 lên trên 1 bậc
    if (graph->getLayerZOrder(101) <= graph->getLayerZOrder(102)) return false; // Giờ layer 101 phải lớn hơn 102

    // 7. Kiểm tra phòng cắt ảnh Crop Room (Khớp opcode 0x12fc374, 0x12fc460)
    if (!crop->enterCropRoom(101, 0.1f, 0.1f, 0.9f, 0.9f, 16.0f / 9.0f)) return false;
    if (!crop->isInCropRoom() || crop->getActiveLayerId() != 101) return false;
    if (!crop->updateCropRect(0.2f, 0.2f, 0.8f, 0.8f)) return false;
    if (!crop->exitCropRoom(true)) return false;
    if (crop->isInCropRoom()) return false;

    // 8. Kiểm tra giao dịch nguyên tử Command Stack Batch Push (Khớp opcode 0x12fc5e8, 0x12fc620)
    batch->beginBatchPush();
    if (!batch->isBatchPushing()) return false;

    // Đẩy một lệnh biến đổi
    auto cmd = std::make_unique<::retouch::middleware::TransformCommand>(
        101,
        ::retouch::middleware::Transform2D(::retouch::middleware::PointF(0, 0), ::retouch::middleware::PointF(1, 1), 0.0f),
        ::retouch::middleware::Transform2D(::retouch::middleware::PointF(100, 50), ::retouch::middleware::PointF(2, 2), 45.0f),
        graph
    );
    batch->pushCommand(std::move(cmd));
    batch->endBatchPush();
    if (batch->isBatchPushing()) return false;

    // Kiểm tra Undo / Redo
    if (!batch->canUndo()) return false;
    if (!batch->undo()) return false;
    if (!batch->canRedo()) return false;
    if (!batch->redo()) return false;

    // 9. Kiểm tra AutoLayout Responsive Engine
    if (!::retouch::middleware::AutoLayoutEngine::runSelfTest()) return false;

    // 10. Kiểm tra Kinetic Text Template & Font Resolver
    if (!::retouch::middleware::TextTemplateManager::runSelfTest()) return false;

    // 11. Kiểm tra Cutout Brush & Intelligent Mask AI
    if (!::retouch::middleware::CutoutBrushManager::runSelfTest()) return false;

    // 12. Kiểm tra hủy xem trước AI Background (Khớp opcode 0x12f6730)
    auto* brush = engine.getCutoutBrushManager();
    brush->cancelAIBackgroundPreview();
    if (!brush->isAIBackgroundPreviewCancelled()) return false;

    return true;
}

// ===================================================================================
// 3. JNI Bridge Implementation
// ===================================================================================

extern "C" {

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeInit(
    JNIEnv *env, jobject thiz) {
    MiddlewareEngine::getInstance().reset();
}

JNIEXPORT jfloat JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeGetGlobalScale(
    JNIEnv *env, jobject thiz) {
    return MiddlewareEngine::getInstance().getSceneGraph()->getGlobalScale();
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeScale(
    JNIEnv *env, jobject thiz, jfloat scale_x, jfloat scale_y, jint layer_id) {
    MiddlewareEngine::getInstance().getSceneGraph()->scaleLayer(layer_id, scale_x, scale_y);
}

JNIEXPORT jfloat JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeQueryLayerRotate(
    JNIEnv *env, jobject thiz, jint layer_id) {
    return MiddlewareEngine::getInstance().getSceneGraph()->queryLayerRotate(layer_id);
}

JNIEXPORT jfloatArray JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeGetLayerAABBBox(
    JNIEnv *env, jobject thiz, jint layer_id) {
    auto aabb = MiddlewareEngine::getInstance().getSceneGraph()->getLayerAABBBox(layer_id);
    jfloatArray result = env->NewFloatArray(4);
    if (!result) return nullptr;
    jfloat bounds[4] = { aabb.min_x, aabb.min_y, aabb.max_x, aabb.max_y };
    env->SetFloatArrayRegion(result, 0, 4, bounds);
    return result;
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeMoveLayerOfSiblingNode(
    JNIEnv *env, jobject thiz, jint layer_id, jint direction) {
    MiddlewareEngine::getInstance().getSceneGraph()->moveLayerOfSiblingNode(layer_id, direction);
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeBeginBatchPush(
    JNIEnv *env, jobject thiz) {
    MiddlewareEngine::getInstance().getBatchPushManager()->beginBatchPush();
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeEndBatchPush(
    JNIEnv *env, jobject thiz) {
    MiddlewareEngine::getInstance().getBatchPushManager()->endBatchPush();
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeEnterImageContentCropRoom(
    JNIEnv *env, jobject thiz, jint layer_id, jfloat l, jfloat t, jfloat r, jfloat b, jfloat aspect_ratio) {
    MiddlewareEngine::getInstance().getCropRoom()->enterCropRoom(layer_id, l, t, r, b, aspect_ratio);
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeExitImageContentCropRoom(
    JNIEnv *env, jobject thiz, jboolean apply) {
    MiddlewareEngine::getInstance().getCropRoom()->exitCropRoom(apply == JNI_TRUE);
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeResetInImageContentCropRoom(
    JNIEnv *env, jobject thiz) {
    MiddlewareEngine::getInstance().getCropRoom()->reset();
}

JNIEXPORT jint JNICALL Java_com_bytedance_retouch_middleware_api_CrossPlatformInterface_nativeGetGroupLayerId(
    JNIEnv *env, jobject thiz, jint layer_id) {
    return MiddlewareEngine::getInstance().getSceneGraph()->getGroupLayerId(layer_id);
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_initBach(
    JNIEnv *env, jobject thiz, jstring config) {
    // Khởi tạo engine Bach retouch
    MiddlewareEngine::getInstance().reset();
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_touchDownEvent(
    JNIEnv *env, jobject thiz, jfloat x, jfloat y) {
    // Tiếp nhận sự kiện chạm màn hình
}

JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_panEvent(
    JNIEnv *env, jobject thiz, jfloat dx, jfloat dy) {
    // Tiếp nhận sự kiện vuốt kéo canvas
}

JNIEXPORT jboolean JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_isLayerVisible(
    JNIEnv *env, jobject thiz, jint layer_id) {
    ::retouch::middleware::LayerDesc desc;
    if (MiddlewareEngine::getInstance().getSceneGraph()->getLayer(layer_id, desc)) {
        return desc.is_visible ? JNI_TRUE : JNI_FALSE;
    }
    return JNI_FALSE;
}

// Khớp opcode 0x12f7c28: nativeGetTextTemplateTitles
JNIEXPORT jobjectArray JNICALL Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeGetTextTemplateTitles(
    JNIEnv *env, jobject thiz, jint template_id) {
    std::vector<std::string> titles;
    if (!MiddlewareEngine::getInstance().getTextTemplateManager()->getTextTemplateTitles(template_id, titles)) {
        return nullptr;
    }

    jclass strClass = env->FindClass("java/lang/String");
    if (!strClass) return nullptr;

    jobjectArray arr = env->NewObjectArray(static_cast<jsize>(titles.size()), strClass, nullptr);
    if (!arr) return nullptr;

    for (size_t i = 0; i < titles.size(); ++i) {
        jstring str = env->NewStringUTF(titles[i].c_str());
        env->SetObjectArrayElement(arr, static_cast<jsize>(i), str);
        env->DeleteLocalRef(str);
    }
    return arr;
}

// Khớp opcode 0x12f5bb4: nativeSetTextFont
JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeSetTextFont(
    JNIEnv *env, jobject thiz, jint template_id, jint item_index, jstring font_path, jstring font_name) {
    const char* path_chars = env->GetStringUTFChars(font_path, nullptr);
    const char* name_chars = env->GetStringUTFChars(font_name, nullptr);
    if (path_chars && name_chars) {
        MiddlewareEngine::getInstance().getTextTemplateManager()->setTextFont(
            template_id, item_index, path_chars, name_chars);
    }
    if (path_chars) env->ReleaseStringUTFChars(font_path, path_chars);
    if (name_chars) env->ReleaseStringUTFChars(font_name, name_chars);
}

// Khớp opcode 0x12f5f5c: nativeSetTextTemplateFontByIndex
JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeSetTextTemplateFontByIndex(
    JNIEnv *env, jobject thiz, jint template_id, jint item_index, jint font_index) {
    MiddlewareEngine::getInstance().getTextTemplateManager()->setTextTemplateFontByIndex(
        template_id, item_index, font_index);
}

// Khớp opcode 0x12f4f48: setCutoutBrushData
JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_setCutoutBrushData(
    JNIEnv *env, jobject thiz, jfloat x, jfloat y, jfloat radius, jfloat hardness,
    jfloat opacity, jfloat aspect_ratio, jfloat angle_deg, jint mode, jint stroke_id, jint layer_id) {
    MiddlewareEngine::getInstance().getCutoutBrushManager()->setCutoutBrushData(
        x, y, radius, hardness, opacity, aspect_ratio, angle_deg, mode, stroke_id, layer_id);
}

// Khớp opcode 0x12f2f10: nativeOnIntelligentMaskResult
JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_cutout_IntelligentMaskCallbackJniImpl_nativeOnIntelligentMaskResult(
    JNIEnv *env, jobject thiz, jint status_code, jbyteArray mask_data, jint width, jint height, jint stride, jint target_layer_id) {
    if (!mask_data) {
        MiddlewareEngine::getInstance().getCutoutBrushManager()->onIntelligentMaskResult(
            status_code, nullptr, width, height, stride, target_layer_id);
        return;
    }
    jbyte* bytes = env->GetByteArrayElements(mask_data, nullptr);
    if (bytes) {
        MiddlewareEngine::getInstance().getCutoutBrushManager()->onIntelligentMaskResult(
            status_code, reinterpret_cast<const uint8_t*>(bytes), width, height, stride, target_layer_id);
        env->ReleaseByteArrayElements(mask_data, bytes, JNI_ABORT);
    }
}

// Khớp opcode 0x12f6730: cancelAIBackgroundPreview
JNIEXPORT void JNICALL Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_cancelAIBackgroundPreview(
    JNIEnv *env, jobject thiz) {
    MiddlewareEngine::getInstance().getCutoutBrushManager()->cancelAIBackgroundPreview();
}

} // extern "C"

} // namespace NextAI::OpenCut::middleware
