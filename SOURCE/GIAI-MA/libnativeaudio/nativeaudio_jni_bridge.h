// ======================================================================
// RECONSTRUCTED C++ JNI BRIDGE HEADER: libnativeaudio.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: AudioMonitorImpl JNI Registration & Java Callback Dispatch
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#pragma once

#include "nativeaudio_types.h"
#include "nativeaudio_opensles_hook.h"
#include "nativeaudio_aaudio_hook.h"
#include <jni.h>
#include <mutex>

namespace com::bytedance::helios::nativeaudio {

// ======================================================================
// EN: AudioMonitorJNI Class
// VN: Lớp AudioMonitorJNI (Cầu nối JNI và truyền phát sự kiện lên tầng Java)
// ======================================================================
class AudioMonitorJNI {
private:
    static JavaVM* s_jvm;                           // Offset 0x10178
    static jobject s_callback_global;               // Offset 0x10180
    static jmethodID s_on_opened_mid;               // Offset 0x10188
    static jmethodID s_on_closed_mid;               // Offset 0x10190
    static bool s_is_monitoring;                    // Offset 0x10168
    static std::mutex s_mutex;                      // Offset 0x10140
    static OpenSLESMonitor s_opensles_monitor;
    static AAudioMonitor s_aaudio_monitor;

public:
    // Mangled: JNI_OnLoad at 0x2bd4 (204 bytes)
    // EN: Native library initialization and JNI method registration
    // VN: Khởi tạo thư viện native và đăng ký hàm JNI
    static jint onJniLoad(JavaVM* vm, void* reserved);

    // Native implementation of AudioMonitorImpl.startMonitor (Disassembly 0x2f6c)
    // Signature: (Lcom/bytedance/helios/nativeaudio/AudioMonitorCallback;ZI)V
    static void startMonitor(JNIEnv* env, jobject thiz, jobject callback, jboolean recordOnly, jint flags);

    // Dispatch callbacks to Java layer
    static void dispatchOnOpened(int32_t stream_id);
    static void dispatchOnClosed(int32_t stream_id);

    // Engine accessors
    static OpenSLESMonitor& getOpenSLESMonitor() noexcept { return s_opensles_monitor; }
    static AAudioMonitor& getAAudioMonitor() noexcept { return s_aaudio_monitor; }
    static bool isMonitoring() noexcept { return s_is_monitoring; }
};

} // namespace com::bytedance::helios::nativeaudio
