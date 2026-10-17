// ======================================================================
// RECONSTRUCTED C++ JNI BRIDGE IMPLEMENTATION: libnativeaudio.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: AudioMonitorImpl JNI Registration & Java Callback Dispatch
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#include "nativeaudio_jni_bridge.h"
#include <cstdio>
#include <cstdlib>

namespace com::bytedance::helios::nativeaudio {

// Static member definitions matching data section offsets
JavaVM* AudioMonitorJNI::s_jvm = nullptr;                                // 0x10178
jobject AudioMonitorJNI::s_callback_global = nullptr;                    // 0x10180
jmethodID AudioMonitorJNI::s_on_opened_mid = nullptr;                    // 0x10188
jmethodID AudioMonitorJNI::s_on_closed_mid = nullptr;                    // 0x10190
bool AudioMonitorJNI::s_is_monitoring = false;                           // 0x10168
std::mutex AudioMonitorJNI::s_mutex;                                     // 0x10140
OpenSLESMonitor AudioMonitorJNI::s_opensles_monitor;
AAudioMonitor AudioMonitorJNI::s_aaudio_monitor;

// Mangled: JNI_OnLoad at 0x2bd4 (204 bytes)
// EN: JNI initialization registering startMonitor on AudioMonitorImpl
// VN: Hàm khởi tạo JNI đăng ký startMonitor trên lớp AudioMonitorImpl
jint AudioMonitorJNI::onJniLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    if (!vm) return -1;

    JNIEnv* env = nullptr;
    // Opcode 0x2c14: blr x8 -> GetEnv(&env, JNI_VERSION_1_6 = 0x10006)
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK || !env) {
        return -1;
    }

    // Opcode 0x2c50: "com/bytedance/helios/nativeaudio/AudioMonitorImpl" at rodata 0x82c8
    jclass clazz = env->FindClass("com/bytedance/helios/nativeaudio/AudioMonitorImpl");
    if (!clazz) {
        return -1;
    }

    // Opcode 0x2c70: Register JNINativeMethod table at 0x10008
    static const JNINativeMethod methods[] = {
        {
            const_cast<char*>("startMonitor"),
            const_cast<char*>("(Lcom/bytedance/helios/nativeaudio/AudioMonitorCallback;ZI)V"),
            reinterpret_cast<void*>(&AudioMonitorJNI::startMonitor)
        }
    };

    // Opcode 0x2c7c: RegisterNatives(env, clazz, methods, 1)
    if (env->RegisterNatives(clazz, methods, 1) < 0) {
        return -1;
    }

    // Opcode 0x2c94: store JavaVM pointer at 0x10178
    s_jvm = vm;
    return JNI_VERSION_1_6;
}

// Native implementation of startMonitor (Disassembly 0x2f6c - 288 bytes)
// EN: Hook audio engines, query method IDs for onOpened/onClosed, and start monitoring
// VN: Đặt hook các engine âm thanh, truy vấn method ID onOpened/onClosed và bắt đầu giám sát
void AudioMonitorJNI::startMonitor(JNIEnv* env, jobject thiz, jobject callback, jboolean recordOnly, jint flags) {
    (void)thiz;
    (void)recordOnly;
    (void)flags;

    if (!env || !callback) return;

    // Opcode 0x2f8c: pthread_mutex_lock(&s_mutex)
    std::lock_guard<std::mutex> lock(s_mutex);

    // Opcode 0x2f94: ldrb w8, [x22, #0x168]; tbnz w8, #0 -> already monitoring
    if (s_is_monitoring) {
        return;
    }

    // Opcode 0x2fa0: GetObjectClass(env, callback)
    jclass cb_class = env->GetObjectClass(callback);
    if (!cb_class) return;

    // Opcode 0x2fb8: GetMethodID(env, cb_class, "onOpened", "(I)V")
    s_on_opened_mid = env->GetMethodID(cb_class, "onOpened", "(I)V");

    // Opcode 0x2ff4: GetMethodID(env, cb_class, "onClosed", "(I)V")
    s_on_closed_mid = env->GetMethodID(cb_class, "onClosed", "(I)V");

    // Opcode 0x3018: NewGlobalRef(env, callback)
    s_callback_global = env->NewGlobalRef(callback);

    // Opcode 0x3030: set s_is_monitoring = true at 0x10168
    s_is_monitoring = true;

    // Opcode 0x3038: bl #0x48a4 -> install OpenSL ES & AAudio hooks
    s_opensles_monitor.setEventCallback([](const AudioStreamEventInfo& event, bool is_opened) {
        if (is_opened) {
            AudioMonitorJNI::dispatchOnOpened(event.stream_id);
        } else {
            AudioMonitorJNI::dispatchOnClosed(event.stream_id);
        }
    });
    s_opensles_monitor.installHook();

    s_aaudio_monitor.setEventCallback([](const AudioStreamEventInfo& event, bool is_opened) {
        if (is_opened) {
            AudioMonitorJNI::dispatchOnOpened(event.stream_id);
        } else {
            AudioMonitorJNI::dispatchOnClosed(event.stream_id);
        }
    });
    s_aaudio_monitor.installHook();
}

void AudioMonitorJNI::dispatchOnOpened(int32_t stream_id) {
    if (!s_jvm || !s_callback_global || !s_on_opened_mid) return;

    JNIEnv* env = nullptr;
    bool need_detach = false;
    if (s_jvm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        if (s_jvm->AttachCurrentThread(&env, nullptr) == JNI_OK) {
            need_detach = true;
        }
    }

    if (env) {
        env->CallVoidMethod(s_callback_global, s_on_opened_mid, static_cast<jint>(stream_id));
        if (need_detach) {
            s_jvm->DetachCurrentThread();
        }
    }
}

void AudioMonitorJNI::dispatchOnClosed(int32_t stream_id) {
    if (!s_jvm || !s_callback_global || !s_on_closed_mid) return;

    JNIEnv* env = nullptr;
    bool need_detach = false;
    if (s_jvm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        if (s_jvm->AttachCurrentThread(&env, nullptr) == JNI_OK) {
            need_detach = true;
        }
    }

    if (env) {
        env->CallVoidMethod(s_callback_global, s_on_closed_mid, static_cast<jint>(stream_id));
        if (need_detach) {
            s_jvm->DetachCurrentThread();
        }
    }
}

} // namespace com::bytedance::helios::nativeaudio

// Standard exported JNI_OnLoad
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    return com::bytedance::helios::nativeaudio::AudioMonitorJNI::onJniLoad(vm, reserved);
}
