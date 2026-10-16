// ======================================================================
// RECONSTRUCTED C++ SOURCE: ByteAIDT_pseudocode.cpp
// Library: libByteAIDT.so (ByteDance Pitaya ByteDT Decision Tree Bridge)
// Component: NextAI OpenCut AI & Decision Tree Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   JNI bindings connecting Android Java/Kotlin layer
//   (com.nextai.opencut.ai.bytedt.ByteAIDTNative) to native Pitaya ByteDTEngine.
//
// Mô tả (Tiếng Việt):
//   Liên kết JNI kết nối tầng Android Java/Kotlin
//   (com.nextai.opencut.ai.bytedt.ByteAIDTNative) tới động cơ native Pitaya ByteDTEngine.
// ======================================================================

#include "ByteAIDT_interface.h"

namespace NextAI::OpenCut::ByteAIDT {

extern "C" {

bool ByteAIDT_Initialize(const char* model_dir) {
    if (!model_dir) return false;
    return ByteDTAdapterBridge::Instance().Initialize(model_dir);
}

int32_t ByteAIDT_RecommendExportBitrate(int32_t width, int32_t height, float fps, float duration, float motion, float texture, int32_t tier) {
    VideoExportMeta meta;
    meta.width = width;
    meta.height = height;
    meta.fps = fps;
    meta.duration_sec = duration;
    meta.motion_score = motion;
    meta.texture_complexity = texture;
    meta.target_tier = tier;
    return ByteDTAdapterBridge::Instance().RecommendExportBitrateKbps(meta);
}

float ByteAIDT_EvaluateAesthetic(const float* features, int32_t count) {
    if (!features || count <= 0) return 50.0f;
    std::vector<float> feats(features, features + count);
    return ByteDTAdapterBridge::Instance().EvaluateAestheticScore(feats);
}

void ByteAIDT_Release() {
    ByteDTAdapterBridge::Instance().Release();
}

// ----------------------------------------------------------------------
// Android JNI Implementations
// ----------------------------------------------------------------------
JNIEXPORT jboolean JNICALL Java_com_nextai_opencut_ai_bytedt_ByteAIDTNative_nativeInit(
    JNIEnv* env, jclass clazz, jstring model_dir) {
    (void)clazz;
    if (!model_dir) return JNI_FALSE;
    const char* dir = env->GetStringUTFChars(model_dir, nullptr);
    if (!dir) return JNI_FALSE;

    bool ok = ByteAIDT_Initialize(dir);
    env->ReleaseStringUTFChars(model_dir, dir);
    return ok ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jint JNICALL Java_com_nextai_opencut_ai_bytedt_ByteAIDTNative_nativeRecommendBitrate(
    JNIEnv* env, jclass clazz, jint width, jint height, jfloat fps, jfloat duration, jfloat motion, jfloat texture, jint tier) {
    (void)env; (void)clazz;
    return ByteAIDT_RecommendExportBitrate(width, height, fps, duration, motion, texture, tier);
}

JNIEXPORT jfloat JNICALL Java_com_nextai_opencut_ai_bytedt_ByteAIDTNative_nativeEvaluateAesthetic(
    JNIEnv* env, jclass clazz, jfloatArray features) {
    (void)clazz;
    if (!features) return 50.0f;
    jsize len = env->GetArrayLength(features);
    jfloat* data = env->GetFloatArrayElements(features, nullptr);
    if (!data) return 50.0f;

    float score = ByteAIDT_EvaluateAesthetic(data, len);
    env->ReleaseFloatArrayElements(features, data, JNI_ABORT);
    return score;
}

JNIEXPORT void JNICALL Java_com_nextai_opencut_ai_bytedt_ByteAIDTNative_nativeRelease(
    JNIEnv* env, jclass clazz) {
    (void)env; (void)clazz;
    ByteAIDT_Release();
}

} // extern "C"

} // namespace NextAI::OpenCut::ByteAIDT
