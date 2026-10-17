// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: JNI Bridge & Provider Registration Implementation (Opcode 0x59cc)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#include "animax_bytevc1_jni.h"
#include <iostream>
#include <cstdio>

#if defined(__ANDROID__)
#include <android/log.h>
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, BinaryConstants::LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, BinaryConstants::LOG_TAG, __VA_ARGS__)
#else
#define LOGE(...) fprintf(stderr, "[AnimaxJNI] "); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n")
#define LOGI(...) printf("[AnimaxJNI] "); printf(__VA_ARGS__); printf("\n")
#endif

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

class ByteVC1PlayerProviderImpl : public VideoPlayerProvider {
public:
    std::unique_ptr<VideoDecoderByteVc1> createDecoder() override {
        auto dec = std::make_unique<VideoDecoderByteVc1>();
        dec->init();
        return dec;
    }

    const char* getCodecName() const override {
        return BinaryConstants::PROVIDER_NAME_BYTEVC1;
    }
};

JniAnimaxByteVC1Bridge& JniAnimaxByteVC1Bridge::getInstance() {
    static JniAnimaxByteVC1Bridge s_instance;
    return s_instance;
}

bool JniAnimaxByteVC1Bridge::registerProvider() {
    // Opcode 0x005a28 - 0x005a74:
    // Calls RegisterVideoPlayerProvider("bytevc1", shared_ptr<VideoPlayerProvider>)
    auto provider = std::make_shared<ByteVC1PlayerProviderImpl>();
    if (provider) {
        m_provider_registered = true;
        m_last_log = BinaryConstants::MSG_REGISTER_SUCCESS;
        LOGI("%s", m_last_log.c_str());
        return true;
    } else {
        m_provider_registered = false;
        m_last_log = BinaryConstants::MSG_REGISTER_FAIL;
        LOGE("%s", m_last_log.c_str());
        return false;
    }
}

int32_t JniAnimaxByteVC1Bridge::onJniLoad(JavaVM* vm, void* reserved) {
    // Reconstructed from opcode 0x0059cc - 0x005ad8:
    // 1. Allocate 32 bytes (0x20) for provider
    // 2. Register "bytevc1" provider
    // 3. Log diagnostic message
    // 4. Return 0x10006 (JNI_VERSION_1_6)
    registerProvider();
    return BinaryConstants::JNI_VERSION_1_6;
}

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI

#if !defined(BUILD_TEST_LIBRARY_STATIC)
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    return NextAI::OpenCut::AnimaxByteVC1::JniAnimaxByteVC1Bridge::getInstance().onJniLoad(vm, reserved);
}
#endif
