// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: JNI Bridge & Provider Registration (Opcode 0x59cc)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_ANIMAX_BYTEVC1_JNI_H
#define NEXTAI_OPENCUT_ANIMAX_BYTEVC1_JNI_H

#include "animax_bytevc1_types.h"
#include "animax_bytevc1_decoder.h"
#include <string>
#include <memory>

#if defined(__ANDROID__) || defined(HAVE_JNI)
#include <jni.h>
#else
typedef void* JavaVM;
typedef void* JNIEnv;
#endif

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

/**
 * @brief Interface for VideoPlayerProvider in Lynx AnimaX.
 * Giao diện nhà cung cấp trình phát video trong Lynx AnimaX.
 */
class VideoPlayerProvider {
public:
    virtual ~VideoPlayerProvider() = default;
    virtual std::unique_ptr<VideoDecoderByteVc1> createDecoder() = 0;
    virtual const char* getCodecName() const = 0;
};

/**
 * @brief JNI Lifecycle & Codec Registration Bridge.
 * Cầu nối vòng đời JNI và đăng ký bộ giải mã ByteVC1 vào Lynx AnimaX.
 */
class JniAnimaxByteVC1Bridge {
public:
    static JniAnimaxByteVC1Bridge& getInstance();

    /**
     * @brief Implementation of JNI_OnLoad (opcode 0x0059cc).
     * Returns 0x10006 (JNI_VERSION_1_6).
     */
    int32_t onJniLoad(JavaVM* vm, void* reserved);

    /**
     * @brief Register the ByteVC1 video player provider into Lynx AnimaX (opcode 0x005a34).
     * Đăng ký nhà cung cấp bộ giải mã ByteVC1 vào Lynx AnimaX.
     */
    bool registerProvider();

    /**
     * @brief Query whether provider has been successfully registered.
     */
    bool isProviderRegistered() const { return m_provider_registered; }

    /**
     * @brief Retrieve last registration diagnostic log message.
     */
    std::string getLastLogMessage() const { return m_last_log; }

    /**
     * @brief Check whether ByteVC1 decoding ability is globally disabled.
     * Kiểm tra xem tính năng giải mã ByteVC1 có bị vô hiệu hóa toàn cục không.
     */
    bool isDecoderDisabled() const { return m_decoder_disabled; }
    void setDecoderDisabled(bool disabled) { m_decoder_disabled = disabled; }

private:
    JniAnimaxByteVC1Bridge() = default;

    bool m_provider_registered{false};
    bool m_decoder_disabled{false};
    std::string m_last_log;
};

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_ANIMAX_BYTEVC1_JNI_H
