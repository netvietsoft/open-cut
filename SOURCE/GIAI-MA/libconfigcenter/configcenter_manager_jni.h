// ============================================================================
// File: configcenter_manager_jni.h
// Library: libconfigcenter.so (ARM64-v8a)
// Task ID: TASK-089-RECONSTRUCTION-LIBCONFIGCENTER (Target 50 / TASK_SO_150)
// Description:
//   EN: Declaration of com::tiktok::ttkmedia::configcenter::ConfigCenter
//       (0x04e48..0x05494, 128 bytes at .bss 0x10030), log formatting helpers
//       (0x05550..0x056d8), 16 JNI native methods (.data.rel.ro 0x0fac8..0x0fc48),
//       JNI_OnLoad (0x05a84), and recursive Java JSONObject/JSONArray -> Json::Value
//       converters (0x05bb8..0x0689c).
//   VN: Khai báo lớp com::tiktok::ttkmedia::configcenter::ConfigCenter
//       (0x04e48..0x05494, 128 byte tại .bss 0x10030), các hàm định dạng log
//       (0x05550..0x056d8), 16 hàm JNI native (.data.rel.ro 0x0fac8..0x0fc48),
//       JNI_OnLoad (0x05a84), và bộ chuyển đổi đệ quy Java JSONObject/JSONArray
//       sang Json::Value (0x05bb8..0x0689c).
// ============================================================================

#pragma once

#include "configcenter_base_config.h"

namespace com {
namespace tiktok {
namespace ttkmedia {
namespace configcenter {

// ============================================================================
// EN: ConfigCenter (128 bytes = 0x80 at .bss 0x10030..0x100b0, guard at 0x100b0)
//     Exact member layout verified from ConfigCenter() (0x04fa8) and ~ConfigCenter() (0x04ec0):
//       +0x00..+0x0f: std::shared_ptr<IConfig> player_config_ (module = 2, priority = 0)
//       +0x10..+0x1f: std::shared_ptr<IConfig> mdl_config_    (module = 3, priority = 0)
//       +0x20..+0x2f: std::shared_ptr<IConfig> strategy_center_config_ (module = 4, priority = 0)
//       +0x30..+0x57: std::mutex mutex_ (40 bytes = 0x28)
//       +0x58..+0x7f: IConfigCenterListener* listeners_[5] (indexed by ConfigModule 0..4)
// VN: Lớp ConfigCenter (128 byte = 0x80 tại .bss 0x10030..0x100b0, biến bảo vệ tại 0x100b0)
// ============================================================================
class ConfigCenter {
public:
    // _ZN3com6tiktok8ttkmedia12configcenter12ConfigCenter9SingletonEv @ 0x04e48 (120 bytes)
    static ConfigCenter* Singleton();

    // _ZN3com6tiktok8ttkmedia12configcenter12ConfigCenterC1Ev @ 0x04fa8 (380 bytes)
    // _ZN3com6tiktok8ttkmedia12configcenter12ConfigCenterC2Ev @ 0x04fa8 (380 bytes)
    ConfigCenter();

    // _ZN3com6tiktok8ttkmedia12configcenter12ConfigCenterD2Ev @ 0x04ec0 (232 bytes)
    ~ConfigCenter();

    // _ZN3com6tiktok8ttkmedia12configcenter12ConfigCenter12createConfigENS2_12ConfigModuleENS2_8PriorityE
    // @ 0x05124 (68 bytes)
    IConfig* createConfig(ConfigModule module, Priority priority);

    // _ZN3com6tiktok8ttkmedia12configcenter12ConfigCenter12createConfigENS2_12ConfigModuleENS2_8PriorityEPNS2_7IConfigE
    // @ 0x0542c (96 bytes)
    IConfig* createConfig(ConfigModule module, Priority priority, IConfig* source);

    // _ZNK3com6tiktok8ttkmedia12configcenter12ConfigCenter15getPlayerConfigEv @ 0x05168 (96 bytes)
    std::shared_ptr<IConfig> getPlayerConfig() const;

    // _ZNK3com6tiktok8ttkmedia12configcenter12ConfigCenter12getMdlConfigEv @ 0x051c8 (96 bytes)
    std::shared_ptr<IConfig> getMdlConfig() const;

    // _ZNK3com6tiktok8ttkmedia12configcenter12ConfigCenter23getStrategyCenterConfigEv @ 0x05228 (96 bytes)
    std::shared_ptr<IConfig> getStrategyCenterConfig() const;

    // _ZN3com6tiktok8ttkmedia12configcenter12ConfigCenter12updateConfigEPNS2_7IConfigE @ 0x05288 (420 bytes)
    void updateConfig(IConfig* config);

    // _ZN3com6tiktok8ttkmedia12configcenter12ConfigCenter11setListenerEPNS2_21IConfigCenterListenerENS2_12ConfigModuleE
    // @ 0x0548c (12 bytes)
    void setListener(IConfigCenterListener* listener, ConfigModule module) noexcept;

    IConfigCenterListener* getListener(ConfigModule module) const noexcept {
        int32_t idx = static_cast<int32_t>(module);
        if (idx < 0 || idx >= 5) {
            return nullptr;
        }
        return listeners_[idx];
    }

private:
    std::shared_ptr<IConfig> player_config_;          // +0x00 (module = 2)
    std::shared_ptr<IConfig> mdl_config_;             // +0x10 (module = 3)
    std::shared_ptr<IConfig> strategy_center_config_; // +0x20 (module = 4)
    mutable std::mutex mutex_;                        // +0x30 (40B)
    IConfigCenterListener* listeners_[5];             // +0x58..+0x7f
};

// ============================================================================
// EN: Internal Logging & JNI Helper Functions (0x05550..0x0689c)
// VN: Các hàm hỗ trợ ghi log và JNI nội bộ (0x05550..0x0689c)
// ============================================================================
int FormatLogHeader(char* buf, size_t buf_size, const void* ptr, const char* file, const char* func, int line) noexcept;
void WriteConfigCenterLog(const char* tag, const void* ptr, const char* file, const char* func, int line, const char* fmt, ...) noexcept;

// 15 JNINativeMethod handlers for com/tiktok/ttkmedia/configcenter/BaseConfig (0x0fac8..0x0fc30)
void JNICALL BaseConfig_nativeResetOptions(JNIEnv* env, jobject thiz, jlong handle, jobject map_obj);             // 0x056dc
jlong JNICALL BaseConfig_nativeCreate(JNIEnv* env, jobject thiz, jlong src_handle, jint module, jint priority);   // 0x056e0
jint JNICALL BaseConfig_nativeGetIntOption(JNIEnv* env, jobject thiz, jlong handle, jint key, jint default_val);  // 0x0572c
void JNICALL BaseConfig_nativeSetIntOption(JNIEnv* env, jobject thiz, jlong handle, jint key, jint val);          // 0x05750
jlong JNICALL BaseConfig_nativeGetLongOption(JNIEnv* env, jobject thiz, jlong handle, jint key, jlong default_val);// 0x05770
void JNICALL BaseConfig_nativeSetLongOption(JNIEnv* env, jobject thiz, jlong handle, jint key, jlong val);        // 0x05794
jfloat JNICALL BaseConfig_nativeGetFloatOption(JNIEnv* env, jobject thiz, jlong handle, jint key, jfloat def_val);// 0x057b4
void JNICALL BaseConfig_nativeSetFloatOption(JNIEnv* env, jobject thiz, jlong handle, jint key, jfloat val);      // 0x057d0
jstring JNICALL BaseConfig_nativeGetStringOption(JNIEnv* env, jobject thiz, jlong handle, jint key);              // 0x057ec
void JNICALL BaseConfig_nativeSetStringOption(JNIEnv* env, jobject thiz, jlong handle, jint key, jstring val);    // 0x0589c
void JNICALL BaseConfig_nativeSetJsonOption(JNIEnv* env, jobject thiz, jlong handle, jint key, jobject json_obj); // 0x058e0
jboolean JNICALL BaseConfig_nativeIsKeySet(JNIEnv* env, jobject thiz, jlong handle, jint key);                    // 0x0596c
void JNICALL BaseConfig_nativeReset(JNIEnv* env, jobject thiz, jlong handle);                                     // 0x059a0
void JNICALL BaseConfig_nativeRemove(JNIEnv* env, jobject thiz, jlong handle, jint key);                          // 0x059b8
void JNICALL BaseConfig_nativeRelease(JNIEnv* env, jobject thiz, jlong handle);                                   // 0x059d4

// 1 JNINativeMethod handler for com/tiktok/ttkmedia/configcenter/ConfigCenter (0x0fc30..0x0fc48)
void JNICALL ConfigCenter_nativeUpdateConfig(JNIEnv* env, jobject thiz, jlong handle);                            // 0x059e4

// JNI conversion & registration helpers (0x05a08..0x0689c)
void RegisterNativesHelper(JNIEnv* env, const JniClassRegistration* reg);                                         // 0x05a08
char* CopyJStringToNewCharArray(JNIEnv* env, jstring jstr);                                                       // 0x05bb8
bool CheckAndClearJniException(JNIEnv* env);                                                                      // 0x05cb8
Json::Value ConvertJavaJSONObjectToJsonCpp(JNIEnv* env, jobject json_obj);                                        // 0x05d14
Json::Value ConvertJavaObjectToJsonCpp(JNIEnv* env, jobject obj);                                                 // 0x06214

} // namespace configcenter
} // namespace ttkmedia
} // namespace tiktok
} // namespace com

extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);                                         // 0x05a84
