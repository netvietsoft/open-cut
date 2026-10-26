// ============================================================================
// FILE: cepengine_platform_jni.h
// TARGET: libCepEngine.so — NativeData, PlatformAdapter, CBlockContainer & 13 JNI Exports
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Declares `ScopedLocalRef`, `cep::NativeData` (0x2930c..0x296ab &
//      0x44468..0x47507), JNI / PlatformAdapter helpers (`GetJvmEnv` @ 0x43454,
//      `CheckJavaVM` @ 0x434c0, `GetStringFromJString` @ 0x43c1c, `CreateJavaResult`
//      @ 0x43d94, `JavaCallbackToCpp` @ 0x447c4, `JavaFunctionToCpp` @ 0x448f8,
//      `PlatformReportSync` @ 0x44a2c, `PlatformReportAsync` @ 0x454e8,
//      `DispatchAsyncGlobal` @ 0x45868, `DispatchAsync` @ 0x45964,
//      `DispatchSync` @ 0x45a74, `PlatformCreateTimer` @ 0x476f8),
//      `cep::CBlockContainer` (0x489d4..0x48c63), and the 13 JNI exports
//      (0x49250..0x4a44f).
// [VN] Khai báo `ScopedLocalRef`, `cep::NativeData` (0x2930c..0x296ab &
//      0x44468..0x47507), các tiện ích JNI / PlatformAdapter, `cep::CBlockContainer`
//      (0x489d4..0x48c63), và 13 hàm xuất JNI (0x49250..0x4a44f).
// ============================================================================

#pragma once

#include "cepengine_manager_core.h"

// [EN] RAII wrapper for JNI local references used by `JavaCallbackToCpp` (0x447c4)
//      and `JavaFunctionToCpp` (0x448f8).
// [VN] Lớp bọc RAII cho tham chiếu cục bộ JNI sử dụng bởi `JavaCallbackToCpp` (0x447c4)
//      và `JavaFunctionToCpp` (0x448f8).
class ScopedLocalRef {
public:
    ScopedLocalRef(JNIEnv* env, jobject obj) : env_(env), obj_(obj) {}
    ~ScopedLocalRef() {
        if (env_ && obj_) {
            env_->DeleteLocalRef(obj_);
        }
    }
    ScopedLocalRef(const ScopedLocalRef&) = delete;
    ScopedLocalRef& operator=(const ScopedLocalRef&) = delete;

    JNIEnv* env() const { return env_; }
    jobject get() const { return obj_; }

private:
    JNIEnv* env_ = nullptr;
    jobject obj_ = nullptr;
};

namespace cep {

// ============================================================================
// 1. NATIVE DATA (`cep::NativeData` @ 0x2930c..0x296ab & 0x44468..0x47507)
// ============================================================================

// [EN] JNI/Native implementation of `DataInterface` (`cep::NativeData`):
//      +0x00: vtable ptr
//      +0x08: `origin_obj_` (`void*` / `jobject`, `ldr x3, [x19, #8]` @ 0x45bf8)
//      +0x10: `fallback_data_` (`std::shared_ptr<MemoryDataInterface>` for non-JVM mode)
//      `InterfaceType()` @ 0x2930c returns `1` (`mov w0, #1; ret`).
// [VN] Cài đặt `DataInterface` cho tầng Native/JNI (`cep::NativeData`):
class NativeData : public DataInterface {
public:
    explicit NativeData(void* origin_obj = nullptr);                                // @ 0x46bbc (192 B)
    explicit NativeData(std::shared_ptr<MemoryDataInterface> fallback);
    ~NativeData() override;                                                         // @ 0x46c7c / 0x46d18

    int InterfaceType() override;                                                   // @ 0x2930c (8 B -> returns 1)
    int Type() override;                                                            // @ 0x45b84 (156 B)
    long IntValue() override;                                                       // @ 0x45cbc (152 B)
    double FloatValue() override;                                                   // @ 0x45df0 (156 B)
    bool BoolValue() override;                                                      // @ 0x45f28 (148 B)
    std::string StringValue() override;                                             // @ 0x45fbc (228 B)
    int Size() override;                                                            // @ 0x4613c (152 B)
    std::shared_ptr<DataInterface> GetData(int index) override;                     // @ 0x461d4 (396 B)
    std::vector<std::string> KeySet() override;                                     // @ 0x46360 (1680 B)
    std::shared_ptr<DataInterface> GetData(const std::string& key) override;        // @ 0x469f0 (460 B)
    std::string JSON() override;                                                    // @ 0x46dbc (248 B)

    void* GetOriginObject();                                                        // @ 0x44690 (152 B)
    void AppendData(const std::shared_ptr<NativeData>& item);                       // @ 0x445e4 (172 B)
    void SetData(const std::string& key, const std::shared_ptr<NativeData>& val);   // @ 0x45050 (244 B)

    // Static factories exported in .dynsym
    static std::shared_ptr<NativeData> FromDataInterface(
        const std::shared_ptr<DataInterface>& src);                                 // @ 0x29314 (920 B)
    static std::shared_ptr<NativeData> CreateList();                                // @ 0x44468 (380 B)
    static std::shared_ptr<NativeData> CreateDict();                                // @ 0x44ed4 (380 B)
    static std::shared_ptr<NativeData> CreateString(std::string val);               // @ 0x45144 (388 B)
    static std::shared_ptr<NativeData> CreateInt(long val);                         // @ 0x452c8 (388 B)
    static std::shared_ptr<NativeData> CreateNull();                                // @ 0x46eb4 (380 B)
    static std::shared_ptr<NativeData> CreateBool(bool val);                        // @ 0x47030 (388 B)
    static std::shared_ptr<NativeData> CreateFloat(double val);                     // @ 0x471b4 (400 B)
    static std::shared_ptr<NativeData> FromJson(const std::string& json_str);       // @ 0x47344 (452 B)

private:
    void* origin_obj_ = nullptr;                            // +0x08
    std::shared_ptr<MemoryDataInterface> fallback_data_;    // +0x10
};

// ============================================================================
// 2. PLATFORM ADAPTER, DISPATCH & CBLOCK CONTAINER (0x43454..0x48c63)
// ============================================================================

JNIEnv* GetJvmEnv();                                                                // @ 0x43454 (108 B)
void CheckJavaVM(JNIEnv* env);                                                      // @ 0x434c0 (144 B)
void InitPlatformAdapter(JNIEnv* env);                                              // @ 0x43550 (1740 B)
std::string GetStringFromJString(JNIEnv* env, jstring jstr);                        // @ 0x43c1c (376 B)
jobject CreateJavaResult(const std::shared_ptr<EngineResult>& result);              // @ 0x43d94 (1748 B)
CepEngineResultCallback JavaCallbackToCpp(const ScopedLocalRef& jcallback);         // @ 0x447c4 (308 B)
CepBizFunction JavaFunctionToCpp(const ScopedLocalRef& jfunction);                  // @ 0x448f8 (308 B)

void PlatformReportSync(
    const std::string& event_name,
    const std::unordered_map<std::string, std::string>& category_map,
    const std::unordered_map<std::string, long>& metric_map);                       // @ 0x44a2c (1192 B)

void PlatformReportAsync(
    const std::string& event_name,
    const std::unordered_map<std::string, std::string>& category_map,
    const std::unordered_map<std::string, long>& metric_map);                       // @ 0x454e8 (896 B)

void DispatchAsyncGlobal(const std::function<void()>& block);                       // @ 0x45868 (252 B)
void DispatchAsync(unsigned char queue_id, const std::function<void()>& block);     // @ 0x45964 (272 B)
void DispatchSync(unsigned char queue_id, const std::function<void()>& block);      // @ 0x45a74 (272 B)
void* PlatformCreateTimer(const std::function<void()>& block);                      // @ 0x476f8 (84 B)

// [EN] Thread-safe container storing `std::function<void()>*` blocks passed as `jlong`
//      handles across JNI to `PlatformAdapter.dispatch*` and `JniCaller.callNoParamsCallback`
//      (`cep::CBlockContainer` @ 0x489d4..0x48c63, singleton at `.bss 0x5c7a8`, guard `.bss 0x5c7f8`).
// [VN] Bộ chứa luồng an toàn lưu trữ các con trỏ `std::function<void()>*` truyền qua JNI:
class CBlockContainer {
public:
    static CBlockContainer* Instance();                                             // @ 0x489d4 (124 B)

    void SaveBlock(std::function<void()>* block);                                   // @ 0x48a98 (100 B)
    std::function<void()>* PopBlock(std::function<void()>* block);                  // @ 0x48afc (360 B)

private:
    CBlockContainer() = default;
    ~CBlockContainer() = default;

    mutable std::mutex mutex_;
    std::unordered_set<std::function<void()>*> blocks_;
};

} // namespace cep

// ============================================================================
// 3. 13 EXPORTED JNI FUNCTIONS (0x49250..0x4a44f)
// ============================================================================

extern "C" {

// 1. Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_init @ 0x49250 (4 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_init(
    JNIEnv* env, jobject thiz);

// 2. Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_callNoParamsCallback @ 0x49254 (128 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_callNoParamsCallback(
    JNIEnv* env, jobject thiz, jlong callback_ptr);

// 3. Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_collectCrashInfo @ 0x492d4 (152 B)
JNIEXPORT jstring JNICALL
Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_collectCrashInfo(
    JNIEnv* env, jobject thiz);

// 4. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeConfigEngine @ 0x4936c (268 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeConfigEngine(
    JNIEnv* env, jobject thiz, jobject config_json);

// 5. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterRules @ 0x49478 (1068 B)
JNIEXPORT jobject JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterRules(
    JNIEnv* env, jobject thiz, jstring biz_name, jobject rules_json, jobject config_json);

// 6. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterRule @ 0x498a4 (1068 B)
JNIEXPORT jobject JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterRule(
    JNIEnv* env, jobject thiz, jstring biz_name, jstring rule_name, jobject rule_json, jobject config_json);

// 7. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterRule @ 0x49cd0 (152 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterRule(
    JNIEnv* env, jobject thiz, jstring biz_name, jstring rule_name);

// 8. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeProcessEvent @ 0x49d68 (496 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeProcessEvent(
    JNIEnv* env, jobject thiz, jstring biz_name, jstring rule_name, jstring event_name, jobject params, jlong timestamp);

// 9. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeOnEvent @ 0x49f58 (416 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeOnEvent(
    JNIEnv* env, jobject thiz, jstring event_name, jobject params, jlong timestamp);

// 10. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterCallback @ 0x4a0f8 (276 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterCallback(
    JNIEnv* env, jobject thiz, jstring biz_name, jstring rule_name, jobject callback);

// 11. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterCallback @ 0x4a20c (152 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterCallback(
    JNIEnv* env, jobject thiz, jstring biz_name, jstring rule_name);

// 12. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterFunction @ 0x4a2a4 (276 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterFunction(
    JNIEnv* env, jobject thiz, jstring biz_name, jstring func_name, jobject function);

// 13. Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterFunction @ 0x4a3b8 (152 B)
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterFunction(
    JNIEnv* env, jobject thiz, jstring biz_name, jstring func_name);

} // extern "C"
