// ============================================================================
// Clean-Room C++17 PrimJS Logging, VmSdkMonitorAndroid & JNI_OnLoad for libquick.so
// Hiện thực C++17 sạch PrimJS Logging, VmSdkMonitorAndroid & JNI_OnLoad cho libquick.so
// ============================================================================
#include "quick_core.h"
#include <jni.h>

namespace primjs {
namespace general {
namespace logging {

namespace {
int32_t g_min_log_level = 0;
} // namespace

int32_t GetMinAllLogLevel() noexcept {
    return g_min_log_level;
}

LogMessage::LogMessage(const char* file, int32_t line, int32_t severity)
    : file_(file), line_(line), severity_(severity), stream_() {
    Init(file_, line_);
}

LogMessage::~LogMessage() {
    Log(this);
}

void LogMessage::Init(const char* file, int32_t line) {
    stream_ << "[" << (file ? file : "primjs") << ":" << line << "] ";
}

void Log(LogMessage* msg) {
    (void)msg;
}

} // namespace logging
} // namespace general
} // namespace primjs

namespace vmsdk {
namespace general {
namespace logging {

namespace {
void* g_alog_ptr = nullptr; // .bss @ 0x1c2020
} // namespace

bool RegisterJNI(void* env) {
    return env != nullptr;
}

void* GetALogPtr() {
    return g_alog_ptr;
}

void InternalLogFromJava(int32_t level, const char* tag, const char* msg) {
    primjs::general::logging::LogMessage(tag ? tag : "vmsdk", 0, level).stream() << (msg ? msg : "");
}

} // namespace logging

namespace monitor {
namespace android {

namespace {
JavaVM* g_java_vm = nullptr;   // .bss @ 0x1c1f30
int32_t g_settings_flag = 1;   // .bss @ 0x1c0478
} // namespace

bool VmSdkMonitorAndroid::RegisterJNI(void* env) {
    return env != nullptr;
}

void VmSdkMonitorAndroid::MonitorEvent(const char* p0, const char* p1, const char* p2, const char* p3) {
    (void)p0;
    (void)p1;
    (void)p2;
    (void)p3;
}

std::string VmSdkMonitorAndroid::GetSettingsWithKey(const char* key) {
    return key ? std::string(key) : std::string();
}

int32_t VmSdkMonitorAndroid::GetSettingsFlag() {
    return g_settings_flag;
}

} // namespace android
} // namespace monitor
} // namespace vmsdk

extern "C" {

// 0x1b08d8: b #0x1afe90
void MonitorEvent(const char* p0, const char* p1, const char* p2, const char* p3) {
    vmsdk::monitor::android::VmSdkMonitorAndroid::MonitorEvent(p0, p1, p2, p3);
}

// 0x1b08dc: b #0x1b03cc
std::string GetSettingsWithKey(const char* key) {
    return vmsdk::monitor::android::VmSdkMonitorAndroid::GetSettingsWithKey(key);
}

// 0x1b08e0: b #0x1b06e8
int32_t GetSettingsFlag() {
    return vmsdk::monitor::android::VmSdkMonitorAndroid::GetSettingsFlag();
}

// Reconstructed from 0x1afc1c..0x1afd18 (JNI_OnLoad)
// Tái dựng từ 0x1afc1c..0x1afd18 (JNI_OnLoad trả về JNI_VERSION_1_6 = 0x00010006)
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    constexpr jint kJniVersion1_2 = 0x00010002; // mov w20, #2; movk w20, #1, lsl #16
    JNIEnv* env = nullptr;
    if (vm) {
        vm->GetEnv(reinterpret_cast<void**>(&env), kJniVersion1_2);
    }
    vmsdk::monitor::android::VmSdkMonitorAndroid::RegisterJNI(env);
    vmsdk::general::logging::RegisterJNI(env);
    (void)vmsdk::general::logging::GetALogPtr();
    return kJniVersion1_2 + 4; // 0x1afcfc: add w0, w20, #4 -> 0x00010006 (JNI_VERSION_1_6)
}

} // extern "C"
