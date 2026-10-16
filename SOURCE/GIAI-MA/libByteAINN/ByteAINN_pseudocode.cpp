// ======================================================================
// RECONSTRUCTED C++ IMPLEMENTATION: ByteAINN_pseudocode.cpp
// Library: libByteAINN.so (ByteDance Pitaya ByteNN Neural Engine Bridge)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   JNI bindings and high-level C exports connecting Android Java/Kotlin layer
//   (com.nextai.opencut.ai.bytenn.ByteAINNNative) to native Pitaya ByteNNEngine.
//   Handles JNI string extraction, pinned byte buffer transfers, and error propagation.
//
// Mô tả (Tiếng Việt):
//   Liên kết JNI và các hàm xuất khẩu C cấp cao kết nối tầng Android Java/Kotlin
//   (com.nextai.opencut.ai.bytenn.ByteAINNNative) tới động cơ native Pitaya ByteNNEngine.
//   Xử lý trích xuất chuỗi JNI, truyền mảng byte cố định và truyền tín hiệu lỗi.
// ======================================================================

#include "ByteAINN_interface.h"
#include <cstring>
#include <vector>

namespace NextAI::OpenCut::ByteAINN {

extern "C" {

bool ByteAINN_Initialize(const char* model_dir, int32_t forward_type) {
    if (!model_dir) return false;
    return ByteNNAdapterBridge::Instance().Initialize(
        model_dir,
        static_cast<pitaya::ForwardType>(forward_type)
    );
}

bool ByteAINN_SegmentMatting(const uint8_t* rgba_frame, int32_t width, int32_t height,
                             uint8_t* out_alpha_mask, int64_t* out_time_us) {
    if (!rgba_frame || !out_alpha_mask || width <= 0 || height <= 0) {
        return false;
    }
    auto result = ByteNNAdapterBridge::Instance().SegmentHumanMatting(rgba_frame, width, height);
    if (result.alpha_mask.empty()) {
        return false;
    }
    memcpy(out_alpha_mask, result.alpha_mask.data(), width * height);
    if (out_time_us) {
        *out_time_us = result.inference_time_us;
    }
    return true;
}

void ByteAINN_Release() {
    ByteNNAdapterBridge::Instance().Release();
}

// ----------------------------------------------------------------------
// Android JNI Implementations
// ----------------------------------------------------------------------
JNIEXPORT jboolean JNICALL Java_com_nextai_opencut_ai_bytenn_ByteAINNNative_nativeInit(
    JNIEnv* env, jclass clazz, jstring model_dir, jint forward_type) {
    (void)clazz;
    if (!model_dir) return JNI_FALSE;
    const char* dir_str = env->GetStringUTFChars(model_dir, nullptr);
    if (!dir_str) return JNI_FALSE;

    bool ok = ByteAINN_Initialize(dir_str, forward_type);
    env->ReleaseStringUTFChars(model_dir, dir_str);
    return ok ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_nextai_opencut_ai_bytenn_ByteAINNNative_nativeSegmentMatting(
    JNIEnv* env, jclass clazz, jbyteArray rgba_frame, jint width, jint height, jbyteArray out_alpha_mask) {
    (void)clazz;
    if (!rgba_frame || !out_alpha_mask || width <= 0 || height <= 0) {
        return JNI_FALSE;
    }

    jbyte* in_bytes = env->GetByteArrayElements(rgba_frame, nullptr);
    jbyte* out_bytes = env->GetByteArrayElements(out_alpha_mask, nullptr);
    if (!in_bytes || !out_bytes) {
        if (in_bytes) env->ReleaseByteArrayElements(rgba_frame, in_bytes, JNI_ABORT);
        if (out_bytes) env->ReleaseByteArrayElements(out_alpha_mask, out_bytes, JNI_ABORT);
        return JNI_FALSE;
    }

    bool success = ByteAINN_SegmentMatting(
        reinterpret_cast<const uint8_t*>(in_bytes),
        width,
        height,
        reinterpret_cast<uint8_t*>(out_bytes),
        nullptr
    );

    env->ReleaseByteArrayElements(rgba_frame, in_bytes, JNI_ABORT);
    env->ReleaseByteArrayElements(out_alpha_mask, out_bytes, 0); // commit changes

    return success ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_nextai_opencut_ai_bytenn_ByteAINNNative_nativeRelease(
    JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    ByteAINN_Release();
}

} // extern "C"

} // namespace NextAI::OpenCut::ByteAINN
