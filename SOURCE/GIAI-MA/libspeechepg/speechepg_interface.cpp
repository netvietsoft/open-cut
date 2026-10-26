// ============================================================================
// RECONSTRUCTED C++ IMPLEMENTATION: speechepg_interface.cpp
// Target Library: libspeechepg.so (18,256 bytes, ELF64 AArch64)
// Module: All 18 Exported JNI Entry Points (.dynsym [037]..[054]) & Facade
// Reference Disassembly (.text @ 0x001f00..0x003244)
// ============================================================================
// Tệp mã nguồn thực thi toàn bộ 18 điểm nhập JNI xuất xưởng (`.dynsym [037]..[054]`)
// của `libspeechepg.so` (`SpeechPluginBridge`) với chú thích đối chiếu từng lệnh
// hợp ngữ AArch64.
// ============================================================================

#include "speechepg_interface.h"
#include <cstring>
#include <new>

extern "C" {

// ============================================================================
// [046] JNI_OnLoad @ 0x001f00..0x001f7c (128 bytes)
// ============================================================================
/**
 * Disassembly @ `0x001f00..0x001f7c`:
 *   - `0x001f24..0x001f28: mov w0, #4; bl __android_log_print` (`"speechengine"`, `"JNI_OnLoad got called."` @ `0x00331c`)
 *   - `0x001f30: bl #0x1cbc` (`JniEnvironment::SetJavaVM(vm)` -> stores `vm` at `.bss 0x008000` via GOT `0x007fe8`)
 *   - `0x001f34..0x001f50`: if `licbag_set_java_vm` (`[got + 0xfd0]`) is non-null, stores `vm` at `.bss 0x008008`
 *     (`[got + 0xfc8]`) and calls `licbag_set_java_vm(vm)` (`bl #0x1af0` @ `0x001f50`).
 *   - `0x001f54..0x001f68`: if `JNI_OnLoad_UUID` (`[got + 0xff8]`) is non-null, calls `JNI_OnLoad_UUID(vm, reserved)` (`bl #0x1c30`).
 *   - `0x001f70..0x001f7c: mov w0, #0x10006; ret` (`JNI_VERSION_1_6`).
 * Khởi tạo máy ảo `JavaVM*`, đăng ký `licbag` + `UUID` và trả về `0x00010006` (`JNI_VERSION_1_6`).
 */
int32_t JNI_OnLoad(void* vm, void* reserved) {
    speechepg::bridge::JniEnvironment::SetJavaVM(vm);
    licbag_set_java_vm(vm);
    (void)JNI_OnLoad_UUID(vm, reserved);
    return ::lab::speech::client::SpeechEpgConstants::kJniVersion1_6; // 0x00010006
}

// ============================================================================
// [042] SpeechLogTracker_getInstanceToNative @ 0x0023dc..0x0023e0 (8 bytes)
// ============================================================================
/**
 * Disassembly @ `0x0023dc..0x0023e0`:
 *   `0x0023dc: mov x0, #-1`
 *   `0x0023e0: ret`
 * Trả về `-1LL` (`0xffffffffffffffff`) đúng theo hợp ngữ tại `0x0023dc`.
 */
int64_t Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_getInstanceToNative(
    void* /*env*/, void* /*thiz*/) {
    return -1LL;
}

// ============================================================================
// [052] SpeechLogTracker_writeLogToNative @ 0x0023e4 (4 bytes)
// ============================================================================
/**
 * Disassembly @ `0x0023e4`:
 *   `0x0023e4: ret`
 */
void Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_writeLogToNative(
    void* /*env*/, void* /*thiz*/, int64_t /*tracker_handle*/, const char* /*log_msg*/) {
    return;
}

// ============================================================================
// [043] SpeechPluginBridge_getVersionToNative @ 0x0023e8..0x002478 (148 bytes)
// ============================================================================
/**
 * Disassembly @ `0x0023e8..0x002478`:
 *   - `0x002410..0x002414: mov x8, sp; bl #0x1ac0` (`lab::speech::client::Engine::GetVersion()`)
 *   - `0x00241c..0x002438`: extracts C-string (`csel x1, x11, x10, eq`) and calls `env->NewStringUTF(cstr)` (`[env + 0x538]`).
 * Lấy chuỗi phiên bản `Engine::GetVersion()`.
 */
const char* Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_getVersionToNative(
    void* /*env*/, void* /*thiz*/) {
    static std::string s_version;
    s_version = ::lab::speech::client::Engine::GetVersion();
    return s_version.c_str();
}

// ============================================================================
// [044] SpeechPluginBridge_isEngineSupportedToNative @ 0x00247c..0x0024dc (100 bytes)
// ============================================================================
/**
 * Disassembly @ `0x00247c..0x0024dc`:
 *   - `0x0024a4: blr GetStringUTFChars` (`[env + 0x548]`)
 *   - `0x0024ac: bl #0x1b30` (`lab::speech::client::Engine::IsEngineSupported(const char*)`)
 *   - `0x0024c8: blr ReleaseStringUTFChars` (`[env + 0x550]`)
 *   - `0x0024d4: and w0, w22, #1`
 * Kiểm tra xem tên engine nhận diện giọng nói có được hỗ trợ hay không.
 */
uint8_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_isEngineSupportedToNative(
    void* /*env*/, void* /*thiz*/, const char* engine_name) {
    bool supported = ::lab::speech::client::Engine::IsEngineSupported(engine_name);
    return supported ? 1U : 0U;
}

// ============================================================================
// [050] SpeechPluginBridge_createEngineToNative @ 0x0024e0..0x0026ac (464 bytes)
// ============================================================================
/**
 * Disassembly @ `0x0024e0..0x0026ac`:
 *   1. `0x0024f8..0x002500: mov w0, #0x18; bl #0x1a70` (`operator new(24, std::nothrow)`) -> allocates `SpeechEngineHandler`.
 *      If null (`0x002504`), logs `"Create handler failed."` (`0x003380`) and returns `-1LL` (`0x002698`).
 *   2. `0x002514..0x002528`: zeroes 24 bytes of `handler` (`stp xzr, xzr, [x0]; str xzr, [x0, #0x10]`) and logs `"Create options"` (`0x003397`).
 *   3. `0x002534..0x00255c`: allocates 8-byte `Options` (`mov w0, #8; bl #0x1a70`), calls `Options::Options()` (`bl #0x1a80`),
 *      stores at `handler->options (+0x10)`, calls `DefaultOptions(options)` (`bl #0x1b80`), and checks `options->IsValid()` (`bl #0x1ba0; tbz w0, #0, #0x260c`)!
 *   4. `0x002560..0x0025a0`: logs `"Create Listener"` (`0x0033d4`), allocates 48-byte `SpeechPluginListener` (`mov w0, #0x30; bl #0x1a70`),
 *      constructs it (`bl #0x1f80`), stores at `handler->listener (+0x08)`, and calls `listener->InitCallbackObject(jcallback_obj)` (`bl #0x2118`).
 *   5. `0x0025a4..0x0025dc`: logs `"Create Engine"` (`0x0033fc`), allocates 8-byte `Engine` (`mov w0, #8; bl #0x1a70`),
 *      calls `Engine::Engine()` (`bl #0x1b40`), stores at `handler->engine (+0x00)`, and returns `reinterpret_cast<int64_t>(handler)`.
 *   6. On any failure (`0x0025e0..0x002698`), destroys `engine`, `options`, `listener`, and `handler` and returns `-1LL`.
 * Khởi tạo khối `SpeechEngineHandler` (24B), `Options` (8B + `DefaultOptions` + `IsValid`), `SpeechPluginListener` (48B) và `Engine` (8B).
 */
int64_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_createEngineToNative(
    void* /*env*/, void* /*thiz*/, void* jcallback_obj) {
    auto* handler = new (std::nothrow) speechepg::bridge::SpeechEngineHandler();
    if (handler == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kInvalidEngineHandle; // -1LL
    }

    handler->options = new (std::nothrow) ::lab::speech::client::Options();
    if (handler->options == nullptr) {
        delete handler;
        return ::lab::speech::client::SpeechEpgConstants::kInvalidEngineHandle;
    }
    ::lab::speech::client::DefaultOptions(handler->options);
    if (!handler->options->IsValid()) {
        delete handler->options;
        delete handler;
        return ::lab::speech::client::SpeechEpgConstants::kInvalidEngineHandle;
    }

    handler->listener = new (std::nothrow) speechepg::bridge::SpeechPluginListener();
    if (handler->listener == nullptr ||
        handler->listener->InitCallbackObject(jcallback_obj) != 0) {
        delete handler->options;
        delete handler->listener;
        delete handler;
        return ::lab::speech::client::SpeechEpgConstants::kInvalidEngineHandle;
    }

    handler->engine = new (std::nothrow) ::lab::speech::client::Engine();
    if (handler->engine == nullptr) {
        delete handler->options;
        delete handler->listener;
        delete handler;
        return ::lab::speech::client::SpeechEpgConstants::kInvalidEngineHandle;
    }

    return reinterpret_cast<int64_t>(handler);
}

// ============================================================================
// [048] SpeechPluginBridge_destroyEngineToNative @ 0x0026b0..0x002724 (120 bytes)
// ============================================================================
/**
 * Disassembly @ `0x0026b0..0x002724`:
 *   - `0x0026b0: cbz x2, #0x2724`
 *   - `0x0026c0..0x0026dc`: destroys `handler->engine (+0x00)` (`Engine::~Engine` @ `0x1bb0` + `operator delete` @ `0x1b00`) and zeroes `+0x00`.
 *   - `0x0026e0..0x0026f8`: destroys `handler->options (+0x10)` (`Options::~Options` @ `0x1c70` + `operator delete` @ `0x1b00`) and zeroes `+0x10`.
 *   - `0x0026fc..0x002710`: destroys `handler->listener (+0x08)` via virtual slot `[1]` (`[vptr + 8]` = `D0Ev` @ `0x002058`) and zeroes `+0x08`.
 *   - `0x002718..0x002720`: tail-calls `operator delete(handler)` (`b #0x1b00`).
 * Hủy `engine`, `options`, `listener` và giải phóng bộ nhớ `SpeechEngineHandler`.
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_destroyEngineToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle) {
    if (handle == 0LL || handle == -1LL) {
        return;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine != nullptr) {
        delete handler->engine;
        handler->engine = nullptr;
    }
    if (handler->options != nullptr) {
        delete handler->options;
        handler->options = nullptr;
    }
    if (handler->listener != nullptr) {
        delete handler->listener;
        handler->listener = nullptr;
    }
    delete handler;
}

// ============================================================================
// [047] SpeechPluginBridge_setOptionStringToNative @ 0x002728..0x00290c (488 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002728..0x00290c`:
 *   - Loads `handler->options` (`ldr x24, [x2, #0x10]` @ `0x002764`), constructs `std::string(key)` and `std::string(val)`,
 *     and calls `Options::SetOption(const std::string&, const std::string&)` (`bl #0x1b20` @ `0x002884`).
 * Thiết lập tùy chọn kiểu chuỗi (`std::string`) vào `handler->options` (`+0x10`).
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionStringToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, const char* val) {
    if (handle == 0LL || handle == -1LL || key == nullptr || val == nullptr) {
        return;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr) {
        return;
    }
    handler->options->SetOption(std::string(key), std::string(val));
}

// ============================================================================
// [053] SpeechPluginBridge_setOptionBooleanToNative @ 0x002910..0x002a48 (316 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002910..0x002a48`:
 *   - `0x0029cc..0x0029e8: tst w22, #0xff; cset w8, ne; strb w8, [sp, #0xc]; bl #0x1bd0`
 *     (`Options::SetOption(const std::string&, const bool&)`).
 * Thiết lập tùy chọn kiểu logic (`bool`) vào `handler->options` (`+0x10`).
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionBooleanToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, uint8_t val) {
    if (handle == 0LL || handle == -1LL || key == nullptr) {
        return;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr) {
        return;
    }
    bool bval = (val != 0U);
    handler->options->SetOption(std::string(key), bval);
}

// ============================================================================
// [041] SpeechPluginBridge_setOptionIntToNative @ 0x002a4c..0x002b7c (308 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002a4c..0x002b7c`:
 *   - `0x002b08..0x002b1c: str w22, [sp, #0xc]; bl #0x1b70`
 *     (`Options::SetOption(const std::string&, const int&)`).
 * Thiết lập tùy chọn kiểu số nguyên (`int32_t`) vào `handler->options` (`+0x10`).
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionIntToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, int32_t val) {
    if (handle == 0LL || handle == -1LL || key == nullptr) {
        return;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr) {
        return;
    }
    int ival = static_cast<int>(val);
    handler->options->SetOption(std::string(key), ival);
}

// ============================================================================
// [038] SpeechPluginBridge_setOptionDoubleToNative @ 0x002b80..0x002cb0 (308 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002b80..0x002cb0`:
 *   - `0x002c3c..0x002c50: str d8, [sp, #8]; bl #0x1a90`
 *     (`Options::SetOption(const std::string&, const double&)`).
 * Thiết lập tùy chọn kiểu số thực (`double`) vào `handler->options` (`+0x10`).
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionDoubleToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, double val) {
    if (handle == 0LL || handle == -1LL || key == nullptr) {
        return;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr) {
        return;
    }
    handler->options->SetOption(std::string(key), val);
}

// ============================================================================
// [039] SpeechPluginBridge_initEngineToNative @ 0x002cb4..0x002d74 (196 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002cb4..0x002d74`:
 *   1. `0x002cc8..0x002cfc`: if `jasset_mgr != nullptr` (`x3`) and `JNI_SetAssetManager` (`[got + 0xff0]`) is non-null:
 *      logs `"Set AssetManager to native."` (`0x003420`), calls `JniEnvironment::GetJavaVM()` (`bl #0x1ccc`),
 *      and calls `JNI_SetAssetManager(jvm, jasset_mgr)` (`bl #0x1bf0`).
 *   2. `0x002d00..0x002d0c: ldr x0, [x19]; ldr x1, [x19, #0x10]; bl #0x1ad0` (`Engine::Init(Options*)`).
 *   3. `0x002d10..0x002d28`: if `Init != 0`, logs `"Fail to initialize engine!"` (`0x00343c`) and returns `w20`.
 *   4. `0x002d2c..0x002d60`: if `Init == 0`, logs `"Add listener!"` (`0x003457`), calls
 *      `Engine::AddListener(handler->listener)` (`ldp x0, x1, [x19]; bl #0x1b90` @ `0x002d48..0x002d4c`),
 *      logs `"Successfully initialize engine!"` (`0x003465`), and returns `0`.
 * Khởi tạo `JNI_SetAssetManager`, `Engine::Init(options)` và đăng ký `Engine::AddListener(listener)`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_initEngineToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, void* jasset_mgr) {
    if (handle == 0LL || handle == -1LL) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (jasset_mgr != nullptr) {
        void* jvm = speechepg::bridge::JniEnvironment::GetJavaVM();
        JNI_SetAssetManager(jvm, jasset_mgr);
    }
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    int32_t ret = handler->engine->Init(handler->options);
    if (ret == 0) {
        handler->engine->AddListener(handler->listener);
    }
    return ret;
}

// ============================================================================
// [040] SpeechPluginBridge_sendDirectiveToNative @ 0x002d78..0x002ecc (344 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002d78..0x002ecc`:
 *   - Constructs `std::string(data)` (`0x002dd0..0x002e34`) and calls
 *     `Engine::SendDirective(directive_type, data_str)` (`bl #0x1b10` @ `0x002e48`).
 *   - If non-zero (`0x002e60`), logs `"Fail to send directive!"` (`0x003485`).
 * Gửi chỉ thị điều khiển (`directive_type`, `data`) tới `Engine::SendDirective`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_sendDirectiveToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, int32_t directive_type, const char* data) {
    if (handle == 0LL || handle == -1LL || data == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    return handler->engine->SendDirective(directive_type, std::string(data));
}

// ============================================================================
// [051] SpeechPluginBridge_feedAudioToNative @ 0x002ed0..0x002f74 (168 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002ed0..0x002f74`:
 *   - `0x002f10: cmp  w22, #0`
 *   - `0x002f14: cinc w8, w22, lt`
 *   - `0x002f18: asr  w2, w8, #1`      -> signed division by 2: `(byte_len + (byte_len < 0 ? 1 : 0)) >> 1`
 *   - `0x002f20: bl   #0x1c40`         -> `Engine::Feed(pcm16, sample_count)`
 *   - If non-zero (`0x002f28`), logs `"Fail to feed audio!"` (`0x00349d`).
 * Chuyển đổi độ dài byte sang số mẫu PCM 16-bit (`byte_len / 2`) và nạp vào `Engine::Feed`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_feedAudioToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const uint8_t* audio_bytes, int32_t byte_len) {
    if (handle == 0LL || handle == -1LL || audio_bytes == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    int32_t sample_count = ::lab::speech::client::Engine::computePcm16SampleCountFromBytes(byte_len);
    return handler->engine->Feed(reinterpret_cast<const int16_t*>(audio_bytes), sample_count);
}

// ============================================================================
// [037] SpeechPluginBridge_resetEngineToNative @ 0x002f78..0x002fb8 (68 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002f78..0x002fb8`:
 *   - `0x002f88: bl #0x1c10` (`Engine::Reset()`)
 *   - If non-zero (`0x002f90`), logs `"Fail to reset engine!"` (`0x0034b1`).
 * Đặt lại trạng thái `Engine::Reset()`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_resetEngineToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle) {
    if (handle == 0LL || handle == -1LL) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    return handler->engine->Reset();
}

// ============================================================================
// [054] SpeechPluginBridge_processAudioToNative @ 0x002fbc..0x00306c (180 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002fbc..0x00306c`:
 *   - `0x003000: cmp  w23, #0`
 *   - `0x003004: cinc w8, w23, lt`
 *   - `0x003008: tst  w22, #0xff`
 *   - `0x00300c: asr  w2, w8, #1`      -> `sample_count = (byte_len + (byte_len < 0 ? 1 : 0)) >> 1`
 *   - `0x003010: cset w3, ne`          -> `bool is_last = (w22 != 0)`
 *   - `0x003018: bl   #0x1b60`         -> `Engine::Process(pcm16, sample_count, is_last)`
 *   - If non-zero (`0x003020`), logs `"Fail to process audio!"` (`0x0034c7`).
 * Xử lý trực tiếp khối âm thanh PCM 16-bit qua `Engine::Process`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_processAudioToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const uint8_t* audio_bytes, int32_t byte_len, uint8_t is_last) {
    if (handle == 0LL || handle == -1LL || audio_bytes == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    int32_t sample_count = ::lab::speech::client::Engine::computePcm16SampleCountFromBytes(byte_len);
    return handler->engine->Process(reinterpret_cast<const int16_t*>(audio_bytes), sample_count, is_last != 0U);
}

// ============================================================================
// [045] SpeechPluginBridge_fetchResultToNative @ 0x003070..0x003188 (284 bytes)
// ============================================================================
/**
 * Disassembly @ `0x003070..0x003188`:
 *   1. `0x0030a4..0x0030b0: add x8, sp, #8; bl #0x1c50` (`Engine::FetchResult(result_type)`).
 *   2. `0x0030b4..0x0030b8: ldr w21, [sp, #8]; cbz w21, #0x30fc` -> if `res.err_code != 0`, returns `res.err_code`.
 *   3. `0x0030fc..0x003130`: calls `env->GetArrayLength(out_buffer)` (`w0`) and checks `res.data.size() <= w0`:
 *      `0x003124: cmp x11, w0, sxtw`
 *      `0x00312c: b.ls #0x313c`
 *      `0x003130: mov w21, #-0x709` (`-1801 = kErrBufferTooSmall`) -> returns `-1801` if buffer is too small!
 *   4. `0x00313c..0x00317c`: copies `res.data` into `out_buffer` (`SetByteArrayRegion`) and returns `res.data.size()`.
 * Lấy kết quả nhị phân `Engine::FetchResult(result_type)` với kiểm tra tràn vùng đệm (`-1801 = -0x709`).
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchResultToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, int32_t result_type,
    speechepg::jni::SimulatedByteArray* out_buffer) {
    if (handle == 0LL || handle == -1LL || out_buffer == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEpgConstants::kErrInvalidArgument;
    }

    ::lab::speech::client::EngineResult res = handler->engine->FetchResult(result_type);
    if (res.err_code != 0) {
        return res.err_code;
    }

    // Exact check at 0x003124..0x003130: cmp x11, w0, sxtw; b.ls #0x313c; mov w21, #-0x709 (-1801)
    if (res.data.size() > out_buffer->bytes.size()) {
        return ::lab::speech::client::SpeechEpgConstants::kErrBufferTooSmall; // -1801 (-0x709)
    }

    if (!res.data.empty()) {
        std::memcpy(out_buffer->bytes.data(), res.data.data(), res.data.size());
    }
    return static_cast<int32_t>(res.data.size());
}

// ============================================================================
// [049] SpeechPluginBridge_fetchStringResultToNative @ 0x00318c..0x003244 (188 bytes)
// ============================================================================
/**
 * Disassembly @ `0x00318c..0x003244`:
 *   - `0x0031b8..0x0031c0: add x8, sp, #0x18; bl #0x1c50` (`Engine::FetchResult(result_type)`)
 *   - `0x0031c4..0x0031d0: mov x8, sp; add x0, sp, #0x18; bl #0x1c00` (`EngineResult::ToString()`)
 *   - `0x0031d4..0x0031f4`: calls `env->NewStringUTF(str.c_str())` (`[env + 0x538]`).
 * Lấy chuỗi kết quả thông qua `Engine::FetchResult` và `EngineResult::ToString()`.
 */
std::string Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchStringResultToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, int32_t result_type) {
    if (handle == 0LL || handle == -1LL) {
        return {};
    }
    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return {};
    }

    ::lab::speech::client::EngineResult res = handler->engine->FetchResult(result_type);
    return res.ToString();
}

} // extern "C"

namespace speechepg {

// ============================================================================
// SPEECHEPG VERIFICATION FACADE IMPLEMENTATION
// Thực thi lớp mặt tiền kiểm thử toàn diện cho libspeechepg.so
// ============================================================================

SpeechepgEngine::SpeechepgEngine() = default;

SpeechepgEngine::~SpeechepgEngine() {
    Shutdown();
}

bool SpeechepgEngine::Initialize() {
    if (is_initialized_) {
        return true;
    }
    int32_t jni_ver = JNI_OnLoad(&callback_dummy_obj_, nullptr);
    if (jni_ver != ::lab::speech::client::SpeechEpgConstants::kJniVersion1_6) {
        return false;
    }

    handle_ = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_createEngineToNative(
        nullptr, nullptr, &callback_dummy_obj_);
    if (handle_ == -1LL || handle_ == 0LL) {
        return false;
    }

    Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionStringToNative(
        nullptr, nullptr, handle_, "engine_name", "asr_plugin");
    Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionIntToNative(
        nullptr, nullptr, handle_, "sample_rate", 16000);
    Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionBooleanToNative(
        nullptr, nullptr, handle_, "enable_itn", 1U);
    Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionDoubleToNative(
        nullptr, nullptr, handle_, "vad_threshold_db", -45.0);

    last_err_code_ = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_initEngineToNative(
        nullptr, nullptr, handle_, &callback_dummy_obj_);
    if (last_err_code_ != 0) {
        handle_ = -1LL;
        return false;
    }

    is_initialized_ = true;
    return true;
}

bool SpeechepgEngine::ExecuteCorePipeline(
    const uint8_t* input_data, size_t input_size, std::vector<uint8_t>& output_data) {
    if (!is_initialized_ || handle_ == -1LL || input_data == nullptr || input_size < 2U) {
        return false;
    }

    last_err_code_ = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_sendDirectiveToNative(
        nullptr, nullptr, handle_,
        ::lab::speech::client::SpeechEpgConstants::kDirectiveStartEngine,
        "{\"req_id\":\"opencut_plugin_asr_01\"}");
    if (last_err_code_ != 0) {
        return false;
    }

    last_err_code_ = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_processAudioToNative(
        nullptr, nullptr, handle_, input_data, static_cast<int32_t>(input_size), 1U);
    if (last_err_code_ != 0) {
        return false;
    }

    last_json_result_ = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchStringResultToNative(
        nullptr, nullptr, handle_,
        ::lab::speech::client::SpeechEpgConstants::kMessageTypeFinalResult);
    if (last_json_result_.empty()) {
        return false;
    }

    output_data.assign(last_json_result_.begin(), last_json_result_.end());
    return true;
}

void SpeechepgEngine::Shutdown() {
    if (handle_ != -1LL && handle_ != 0LL) {
        Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_destroyEngineToNative(
            nullptr, nullptr, handle_);
        handle_ = -1LL;
    }
    is_initialized_ = false;
}

} // namespace speechepg
