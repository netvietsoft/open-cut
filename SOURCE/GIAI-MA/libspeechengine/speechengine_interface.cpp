// ============================================================================
// RECONSTRUCTED C++ IMPLEMENTATION: speechengine_interface.cpp
// Target Library: libspeechengine.so (18,256 bytes, ELF64 AArch64)
// Module: All 18 Exported JNI Entry Points (.dynsym [037]..[054]) & Facade
// Reference Disassembly (.text @ 0x001ef0..0x003238)
// ============================================================================
// Tệp mã nguồn thực thi toàn bộ 18 điểm nhập JNI xuất xưởng (`.dynsym [037]..[054]`)
// của `libspeechengine.so` với chú thích đối chiếu từng lệnh hợp ngữ AArch64.
// ============================================================================

#include "speechengine_interface.h"
#include <cstring>
#include <new>

extern "C" {

// ============================================================================
// [042] JNI_OnLoad @ 0x001ef0..0x001f6c (128 bytes)
// ============================================================================
/**
 * Disassembly @ `0x001ef0..0x001f6c`:
 *   - `0x001f0c: adrp x8, #0x8000; str x0, [x8]` -> stores `vm` at `.bss 0x008000` (`g_jvm`)
 *   - `0x001f20: bl #0x1c30` (`licbag_set_java_vm(vm)`)
 *   - `0x001f24: adrp x8, #0x8000; str x19, [x8, #8]` -> stores `vm` at `.bss 0x008008` (`g_licbag_jvm`)
 *   - `0x001f30: mov x1, xzr; bl #0x1bd0` (`JNI_OnLoad_UUID(vm, 0)`)
 *   - `0x001f50: mov w0, #3; bl __android_log_print` (`"SpeechEngine"`, `"JNI_OnLoad Called."` @ `0x00330e`)
 *   - `0x001f60: mov w0, #0x10006` (`JNI_VERSION_1_6`)
 * Khởi tạo máy ảo `JavaVM*`, đăng ký `licbag` + `UUID` và trả về `0x00010006` (`JNI_VERSION_1_6`).
 */
int32_t JNI_OnLoad(void* vm, void* /*reserved*/) {
    speechengine::bridge::JniEnvironment::SetJavaVM(vm);
    licbag_set_java_vm(vm);
    (void)JNI_OnLoad_UUID(vm, nullptr);
    return ::lab::speech::client::SpeechEngineConstants::kJniVersion1_6; // 0x00010006
}

// ============================================================================
// [037] SpeechEngineBridge_getVersionToNative @ 0x001f70..0x002000 (148 bytes)
// ============================================================================
/**
 * Disassembly @ `0x001f70..0x002000`:
 *   - `0x001f98: add x8, sp, #8; bl #0x1ae0` (`lab::speech::client::Engine::GetVersion()`)
 *   - `0x001fa0..0x001fb4`: extracts C-string (`csel x1, x8, x9, eq`) and calls `env->NewStringUTF(cstr)` (`[env + 0x538]`).
 *   - `0x001fbc..0x001fd0`: destroys temporary `std::string` if heap-allocated (`tbz w8, #0, #0x1fd0; bl operator delete`).
 * Lấy chuỗi phiên bản `Engine::GetVersion()`.
 */
const char* Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_getVersionToNative(
    void* /*env*/, void* /*thiz*/) {
    static std::string s_version;
    s_version = ::lab::speech::client::Engine::GetVersion();
    return s_version.c_str();
}

// ============================================================================
// [048] SpeechEngineBridge_isEngineSupportedToNative @ 0x002004..0x002064 (100 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002004..0x002064`:
 *   - `0x002030: bl GetStringUTFChars` (`[env + 0x548]`)
 *   - `0x002038: bl #0x1b70` (`lab::speech::client::Engine::IsEngineSupported(const char*)`)
 *   - `0x00204c: bl ReleaseStringUTFChars` (`[env + 0x550]`)
 *   - `0x002050: and w0, w21, #0x1`
 * Kiểm tra xem tên engine nhận diện giọng nói có được hỗ trợ hay không.
 */
uint8_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_isEngineSupportedToNative(
    void* /*env*/, void* /*thiz*/, const char* engine_name) {
    bool supported = ::lab::speech::client::Engine::IsEngineSupported(engine_name);
    return supported ? 1U : 0U;
}

// ============================================================================
// [047] SpeechEngineBridge_createEngineToNative @ 0x002068..0x002234 (464 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002068..0x002234`:
 *   1. `0x002080: mov w0, #0x18; bl #0x1a80` (`operator new(24, std::nothrow)`) -> allocates `SpeechEngineHandler` (`x19`).
 *   2. `0x002094: movi v0.2d, #0; str xzr, [x19, #0x10]; str q0, [x19]` -> zeroes all 24 bytes of `handler`.
 *   3. `0x0020b4: bl #0x1b80` (`JNI_SetAssetManager(env, jasset_mgr)`).
 *   4. `0x0020b8..0x0020dc: bl DefaultOptions(&tmp); mov w0, #8; bl operator new(nothrow); bl Options(const Options&)`
 *      -> stores `Options*` at `handler->options` (`str x21, [x19, #0x10]` @ `0x0020d4`).
 *   5. `0x002108..0x002138: mov w0, #0x30; bl operator new(nothrow)` -> allocates 48-byte `SpeechEngineListener` (`x21`),
 *      constructs it (`vptr = 0x007c38` @ `0x00211c`), stores at `handler->listener` (`str x21, [x19, #8]` @ `0x002124`),
 *      and calls `listener->InitCallbackObject(jcallback_obj)` (`bl #0x2f68` @ `0x002134`).
 *   6. `0x002140..0x002160: mov w0, #8; bl operator new(nothrow)` -> allocates 8-byte `Engine` (`x20`),
 *      calls `Engine::Engine()` (`bl #0x1c40` @ `0x002158`), stores at `handler->engine` (`str x20, [x19]` @ `0x002160`).
 *   7. `0x0021bc: bl #0x1bc0` (`Engine::AddListener(listener)`).
 *   8. On any failure (`0x002168..0x002220`), frees `engine`, `options`, `listener`, and `handler` in exact order
 *      and returns `-1LL` (`mov x19, #-1` @ `0x002220`).
 * Khởi tạo khối `SpeechEngineHandler` (24 bytes), `Options` (8 bytes), `SpeechEngineListener` (48 bytes) và `Engine` (8 bytes).
 */
int64_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_createEngineToNative(
    void* env, void* /*thiz*/, void* jcallback_obj, void* jasset_mgr) {
    auto* handler = new (std::nothrow) speechengine::bridge::SpeechEngineHandler();
    if (handler == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kInvalidEngineHandle; // -1LL
    }

    if (jasset_mgr != nullptr) {
        JNI_SetAssetManager(env, jasset_mgr);
    }

    handler->options = new (std::nothrow) ::lab::speech::client::Options();
    if (handler->options == nullptr) {
        delete handler;
        return ::lab::speech::client::SpeechEngineConstants::kInvalidEngineHandle;
    }
    ::lab::speech::client::DefaultOptions(handler->options);

    handler->listener = new (std::nothrow) speechengine::bridge::SpeechEngineListener();
    if (handler->listener == nullptr ||
        handler->listener->InitCallbackObject(jcallback_obj) != 0) {
        delete handler->options;
        delete handler->listener;
        delete handler;
        return ::lab::speech::client::SpeechEngineConstants::kInvalidEngineHandle;
    }

    handler->engine = new (std::nothrow) ::lab::speech::client::Engine();
    if (handler->engine == nullptr) {
        delete handler->options;
        delete handler->listener;
        delete handler;
        return ::lab::speech::client::SpeechEngineConstants::kInvalidEngineHandle;
    }

    handler->engine->AddListener(handler->listener);
    return reinterpret_cast<int64_t>(handler);
}

// ============================================================================
// [045] SpeechEngineBridge_destroyEngineToNative @ 0x002238..0x0022ac (120 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002238..0x0022ac`:
 *   - `0x002248: cmp x2, #-1; b.eq #0x22a4; cbz x2, #0x22a4`
 *   - `0x002258..0x00226c`: if `handler->engine (+0x00) != nullptr`, calls `Engine::~Engine()` (`0x1ac0`) + `operator delete` (`0x1a70`).
 *   - `0x002270..0x002284`: if `handler->options (+0x10) != nullptr`, calls `Options::~Options()` (`0x1b00`) + `operator delete` (`0x1a70`).
 *   - `0x002288..0x002298`: if `handler->listener (+0x08) != nullptr`, calls virtual deleting destructor `[vptr + 8]` (`D0Ev` @ `0x002ea8`).
 *   - `0x00229c..0x0022ac`: tail-calls `operator delete(handler)` (`b #0x1a70`).
 * Hủy `engine`, `options`, `listener` và giải phóng bộ nhớ `SpeechEngineHandler`.
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_destroyEngineToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle) {
    if (handle == -1LL || handle == 0LL) {
        return;
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
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
// [044] SpeechEngineBridge_setOptionStringToNative @ 0x0022b0..0x002494 (488 bytes)
// ============================================================================
/**
 * Disassembly @ `0x0022b0..0x002494`:
 *   - Validates `handle != -1 && handle != 0`, `key != nullptr`, `val != nullptr`, and `handler->options (+0x10) != nullptr`.
 *   - Constructs `std::string(key)` and `std::string(val)` on stack (`sp+0x20` and `sp+0x8`).
 *   - Calls `Options::SetOption(const std::string&, const std::string&)` (`bl #0x1c20` @ `0x002400`).
 * Thiết lập tùy chọn kiểu chuỗi (`std::string`) vào `handler->options` (`+0x10`).
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionStringToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, const char* val) {
    if (handle == -1LL || handle == 0LL || key == nullptr || val == nullptr) {
        return;
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr) {
        return;
    }
    handler->options->SetOption(std::string(key), std::string(val));
}

// ============================================================================
// [051] SpeechEngineBridge_setOptionBooleanToNative @ 0x002498..0x0025d0 (316 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002498..0x0025d0`:
 *   - Validates `handle != -1 && handle != 0`, `key != nullptr`, and `handler->options (+0x10) != nullptr`.
 *   - `0x002578: cmp w20, #0; cset w2, ne; bl #0x1b30` (`Options::SetOption(const std::string&, bool)`).
 * Thiết lập tùy chọn kiểu logic (`bool`) vào `handler->options` (`+0x10`).
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionBooleanToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, uint8_t val) {
    if (handle == -1LL || handle == 0LL || key == nullptr) {
        return;
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr) {
        return;
    }
    handler->options->SetOption(std::string(key), val != 0U);
}

// ============================================================================
// [039] SpeechEngineBridge_setOptionIntToNative @ 0x0025d4..0x002704 (308 bytes)
// ============================================================================
/**
 * Disassembly @ `0x0025d4..0x002704`:
 *   - Validates `handle != -1 && handle != 0`, `key != nullptr`, and `handler->options (+0x10) != nullptr`.
 *   - `0x0026b0: add x1, sp, #8; mov w2, w20; bl #0x1c60` (`Options::SetOption(const std::string&, int)`).
 * Thiết lập tùy chọn kiểu số nguyên (`int32_t`) vào `handler->options` (`+0x10`).
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionIntToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, int32_t val) {
    if (handle == -1LL || handle == 0LL || key == nullptr) {
        return;
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr) {
        return;
    }
    handler->options->SetOption(std::string(key), static_cast<int>(val));
}

// ============================================================================
// [052] SpeechEngineBridge_setOptionDoubleToNative @ 0x002708..0x002838 (308 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002708..0x002838`:
 *   - Validates `handle != -1 && handle != 0`, `key != nullptr`, and `handler->options (+0x10) != nullptr`.
 *   - `0x0027e4: add x1, sp, #8; fmov d0, d8; bl #0x1b20` (`Options::SetOption(const std::string&, double)`).
 * Thiết lập tùy chọn kiểu số thực (`double`) vào `handler->options` (`+0x10`).
 */
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionDoubleToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, double val) {
    if (handle == -1LL || handle == 0LL || key == nullptr) {
        return;
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr) {
        return;
    }
    handler->options->SetOption(std::string(key), val);
}

// ============================================================================
// [053] SpeechEngineBridge_initEngineToNative @ 0x00283c..0x0028fc (196 bytes)
// ============================================================================
/**
 * Disassembly @ `0x00283c..0x0028fc`:
 *   1. `0x00286c..0x002880`: checks `handler->options (+0x10) != nullptr`, `handler->engine (+0x00) != nullptr`,
 *      and `handler->options->IsValid()` (`bl #0x1c10` @ `0x00287c`).
 *   2. `0x00288c: bl #0x1aa0` (`Engine::Init(const Options&)`).
 *   3. `0x002894..0x0028a8`: deletes `handler->options` (`Options::~Options()` + `operator delete`)
 *      and zeroes `handler->options = nullptr` (`str xzr, [x19, #0x10]` @ `0x0028a8`).
 *   4. `0x0028ac: cbz w20, #0x28ec` -> if `Init` returned `0`, returns `0`!
 *   5. Otherwise (`0x0028b0..0x0028e8`), destroys `handler->engine`, `handler->listener`, and `handler` itself,
 *      returning the non-zero error code `w20`.
 * Khởi tạo `Engine::Init(*options)`, giải phóng `options` sau khi nạp, và tự hủy nếu khởi tạo thất bại.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_initEngineToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle) {
    if (handle == -1LL || handle == 0LL) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument; // -1
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr || handler->engine == nullptr || !handler->options->IsValid()) {
        // Matches 0x0028b4..0x0028e8 cleanup on invalid options
        delete handler->engine;
        delete handler->options;
        delete handler->listener;
        delete handler;
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument;
    }

    int32_t ret = handler->engine->Init(handler->options);

    // Matches 0x002898..0x0028a8: Options is always destroyed and nulled right after Engine::Init!
    delete handler->options;
    handler->options = nullptr;

    if (ret != 0) {
        delete handler->engine;
        delete handler->listener;
        delete handler;
    }
    return ret;
}

// ============================================================================
// [054] SpeechEngineBridge_sendDirectiveToNative @ 0x002900..0x002a54 (344 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002900..0x002a54`:
 *   - Validates `handle != -1 && handle != 0`, `data != nullptr`, and `handler->engine (+0x00) != nullptr`.
 *   - Constructs `std::string(data)` (`0x00297c..0x0029d0`) and calls
 *     `Engine::SendDirective(directive_type, data_str)` (`bl #0x1a90` @ `0x0029dc`).
 * Gửi chỉ thị điều khiển (`directive_type`, `data`) tới `Engine::SendDirective`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_sendDirectiveToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, int32_t directive_type, const char* data) {
    if (handle == -1LL || handle == 0LL || data == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument; // -1
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument;
    }
    return handler->engine->SendDirective(directive_type, std::string(data));
}

// ============================================================================
// [038] SpeechEngineBridge_feedAudioToNative @ 0x002a58..0x002afc (168 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002a58..0x002afc`:
 *   - `0x002a98: cmp  w22, #0`
 *   - `0x002a9c: cinc w8, w22, lt`
 *   - `0x002aa0: asr  w2, w8, #1`      -> signed division by 2: `(byte_len + (byte_len < 0 ? 1 : 0)) >> 1`
 *   - `0x002aac: bl   #0x1c50`         -> `Engine::Feed(reinterpret_cast<const short*>(audio_bytes), sample_count)`
 * Chuyển đổi độ dài byte sang số mẫu PCM 16-bit (`byte_len / 2`) và nạp vào `Engine::Feed`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_feedAudioToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const uint8_t* audio_bytes, int32_t byte_len) {
    if (handle == -1LL || handle == 0LL || audio_bytes == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument; // -1
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument;
    }
    // Exact AArch64 arithmetic at 0x002a98..0x002aa0:
    int32_t adjusted = (byte_len < 0) ? (byte_len + 1) : byte_len;
    int32_t sample_count = adjusted >> 1;
    return handler->engine->Feed(reinterpret_cast<const short*>(audio_bytes), sample_count);
}

// ============================================================================
// [043] SpeechEngineBridge_resetEngineToNative @ 0x002b00..0x002b40 (68 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002b00..0x002b40`:
 *   - `0x002b28: bl #0x1ab0` (`Engine::Reset()`)
 * Đặt lại trạng thái `Engine::Reset()`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_resetEngineToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle) {
    if (handle == -1LL || handle == 0LL) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument; // -1
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument;
    }
    return handler->engine->Reset();
}

// ============================================================================
// [049] SpeechEngineBridge_processAudioToNative @ 0x002b44..0x002bf4 (180 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002b44..0x002bf4`:
 *   - `0x002b88: cmp  w22, #0`
 *   - `0x002b8c: cinc w8, w22, lt`
 *   - `0x002b90: cmp  w23, #0`
 *   - `0x002b94: asr  w2, w8, #1`      -> `sample_count = (byte_len + (byte_len < 0 ? 1 : 0)) >> 1`
 *   - `0x002b98: cset w3, ne`          -> `bool is_last = (w23 != 0)`
 *   - `0x002ba4: bl   #0x1af0`         -> `Engine::Process(pcm16, sample_count, is_last)`
 * Xử lý trực tiếp khối âm thanh PCM 16-bit qua `Engine::Process`.
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_processAudioToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, const uint8_t* audio_bytes, int32_t byte_len, uint8_t is_last) {
    if (handle == -1LL || handle == 0LL || audio_bytes == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument; // -1
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument;
    }
    int32_t adjusted = (byte_len < 0) ? (byte_len + 1) : byte_len;
    int32_t sample_count = adjusted >> 1;
    return handler->engine->Process(reinterpret_cast<const short*>(audio_bytes), sample_count, is_last != 0U);
}

// ============================================================================
// [046] SpeechEngineBridge_fetchResultToNative @ 0x002bf8..0x002d10 (284 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002bf8..0x002d10`:
 *   1. `0x002c60..0x002c64: add x8, sp, #8; bl #0x1b40` (`Engine::FetchResult(int)` returning 32-byte `EngineResult` via `x8`).
 *   2. `0x002c68..0x002c6c: ldr w21, [sp, #8]; cbnz w21, #0x2cd4` -> if `res.err_code != 0`, returns `res.err_code`.
 *   3. `0x002c70..0x002c94`: calls `env->GetArrayLength(out_buffer)` (`w0`) and compares with `res.data.size()` (`x8`):
 *      `0x002cac: cmp x8, w0, sxtw`
 *      `0x002cb0: b.ls #0x2cc0`
 *      `0x002cb8: mov w21, #-0x709` (`-1801 = kErrBufferTooSmall`) -> if `res.data.size() > out_buffer.size()`, returns `-1801`!
 *   4. `0x002cc0..0x002cd0`: copies `res.data` into `out_buffer` (`SetByteArrayRegion`) and returns `static_cast<int32_t>(res.data.size())`.
 * Lấy kết quả nhị phân `Engine::FetchResult(result_type)` với kiểm tra tràn vùng đệm (`-1801 = -0x709`).
 */
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchResultToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, int32_t result_type,
    speechengine::jni::SimulatedByteArray* out_buffer) {
    if (handle == -1LL || handle == 0LL || out_buffer == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument; // -1
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return ::lab::speech::client::SpeechEngineConstants::kErrInvalidArgument;
    }

    ::lab::speech::client::EngineResult res = handler->engine->FetchResult(result_type);
    if (res.err_code != 0) {
        return res.err_code;
    }

    // Exact check at 0x002cac..0x002cb8: cmp x8, w0, sxtw; b.ls #0x2cc0; mov w21, #-0x709 (-1801)
    if (res.data.size() > out_buffer->bytes.size()) {
        return ::lab::speech::client::SpeechEngineConstants::kErrBufferTooSmall; // -1801 (-0x709)
    }

    if (!res.data.empty()) {
        std::memcpy(out_buffer->bytes.data(), res.data.data(), res.data.size());
    }
    return static_cast<int32_t>(res.data.size());
}

// ============================================================================
// [040] SpeechEngineBridge_fetchStringResultToNative @ 0x002d14..0x002dc8 (188 bytes)
// ============================================================================
/**
 * Disassembly @ `0x002d14..0x002dc8`:
 *   - `0x002d5c: add x8, sp, #0x20; bl #0x1b40` (`Engine::FetchResult(result_type)`)
 *   - `0x002d60..0x002d6c: ldr w8, [sp, #0x20]; cbnz w8, #0x2d9c; add x0, sp, #0x20; add x8, sp, #8; bl #0x1b10`
 *     (`EngineResult::ToString()`)
 * Lấy chuỗi kết quả thông qua `Engine::FetchResult` và `EngineResult::ToString()`.
 */
std::string Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchStringResultToNative(
    void* /*env*/, void* /*thiz*/, int64_t handle, int32_t result_type) {
    if (handle == -1LL || handle == 0LL) {
        return {};
    }
    auto* handler = reinterpret_cast<speechengine::bridge::SpeechEngineHandler*>(handle);
    if (handler->engine == nullptr) {
        return {};
    }

    ::lab::speech::client::EngineResult res = handler->engine->FetchResult(result_type);
    if (res.err_code != 0) {
        return {};
    }
    return res.ToString();
}

// ============================================================================
// [041] SpeechLogTracker_getInstanceToNative @ 0x00322c..0x003230 (8 bytes)
// ============================================================================
/**
 * Disassembly @ `0x00322c..0x003230`:
 *   `0x00322c: mov x0, #-1`
 *   `0x003230: ret`
 * Trả về `-1LL` (`0xffffffffffffffff`) đúng theo hợp ngữ tại `0x00322c`.
 */
int64_t Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_getInstanceToNative(
    void* /*env*/, void* /*thiz*/) {
    return -1LL;
}

// ============================================================================
// [050] SpeechLogTracker_writeLogToNative @ 0x003234 (4 bytes)
// ============================================================================
/**
 * Disassembly @ `0x003234`:
 *   `0x003234: ret`
 * Hàm ghi nhật ký trả về trực tiếp (`ret`) tại `0x003234`.
 */
void Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_writeLogToNative(
    void* /*env*/, void* /*thiz*/, int64_t /*tracker_handle*/, const char* /*log_msg*/) {
    return;
}

} // extern "C"

namespace speechengine {

// ============================================================================
// SPEECHENGINE VERIFICATION FACADE IMPLEMENTATION
// Thực thi lớp mặt tiền kiểm thử toàn diện cho libspeechengine.so
// ============================================================================

SpeechengineEngine::SpeechengineEngine() = default;

SpeechengineEngine::~SpeechengineEngine() {
    Shutdown();
}

bool SpeechengineEngine::Initialize() {
    if (is_initialized_) {
        return true;
    }
    int32_t jni_ver = JNI_OnLoad(&callback_dummy_obj_, nullptr);
    if (jni_ver != ::lab::speech::client::SpeechEngineConstants::kJniVersion1_6) {
        return false;
    }

    handle_ = Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_createEngineToNative(
        nullptr, nullptr, &callback_dummy_obj_, &callback_dummy_obj_);
    if (handle_ == -1LL || handle_ == 0LL) {
        return false;
    }

    Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionStringToNative(
        nullptr, nullptr, handle_, "engine_name", "asr");
    Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionIntToNative(
        nullptr, nullptr, handle_, "sample_rate", 16000);
    Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionBooleanToNative(
        nullptr, nullptr, handle_, "enable_itn", 1U);
    Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionDoubleToNative(
        nullptr, nullptr, handle_, "vad_threshold", -45.0);

    last_err_code_ = Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_initEngineToNative(
        nullptr, nullptr, handle_);
    if (last_err_code_ != 0) {
        handle_ = -1LL;
        return false;
    }

    is_initialized_ = true;
    return true;
}

bool SpeechengineEngine::ExecuteCorePipeline(
    const uint8_t* input_data, size_t input_size, std::vector<uint8_t>& output_data) {
    if (!is_initialized_ || handle_ == -1LL || input_data == nullptr || input_size < 2U) {
        return false;
    }

    last_err_code_ = Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_sendDirectiveToNative(
        nullptr, nullptr, handle_,
        ::lab::speech::client::SpeechEngineConstants::kDirectiveStartEngine,
        "{\"req_id\":\"opencut_asr_01\"}");
    if (last_err_code_ != 0) {
        return false;
    }

    last_err_code_ = Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_processAudioToNative(
        nullptr, nullptr, handle_, input_data, static_cast<int32_t>(input_size), 1U);
    if (last_err_code_ != 0) {
        return false;
    }

    last_json_result_ = Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchStringResultToNative(
        nullptr, nullptr, handle_,
        ::lab::speech::client::SpeechEngineConstants::kMessageTypeFinalResult);
    if (last_json_result_.empty()) {
        return false;
    }

    output_data.assign(last_json_result_.begin(), last_json_result_.end());
    return true;
}

void SpeechengineEngine::Shutdown() {
    if (handle_ != -1LL && handle_ != 0LL) {
        Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_destroyEngineToNative(
            nullptr, nullptr, handle_);
        handle_ = -1LL;
    }
    is_initialized_ = false;
}

} // namespace speechengine
