// ============================================================================
// RECONSTRUCTED C++ HEADER: speechengine_sdk_client.h
// Target Library: libspeechengine.so (18,256 bytes, ELF64 AArch64)
// Module: lab::speech::client::Engine, Options, Listener & EngineResult
// Reference Disassembly (.dynsym [006]..[036] & .plt 0x001a90..0x001c60):
//   - lab::speech::client::Options (C1Ev @ 0x001b60, D1Ev @ 0x001b00, IsValid @ 0x001c10)
//   - lab::speech::client::DefaultOptions(Options*) @ 0x001b90
//   - lab::speech::client::Options::SetOption (string @ 0x001c20, bool @ 0x001b30,
//                                              int @ 0x001c60, double @ 0x001b20)
//   - lab::speech::client::Listener (vtable @ 0x007c28, OnMessage @ 0x003098)
//   - lab::speech::client::EngineResult (32 bytes on stack @ 0x002c2c, ToString @ 0x001b10)
//   - lab::speech::client::Engine (C1Ev @ 0x001c40, D1Ev @ 0x001ac0, GetVersion @ 0x001ae0,
//       IsEngineSupported @ 0x001b70, Init @ 0x001aa0, AddListener @ 0x001bc0,
//       SendDirective @ 0x001a90, Feed @ 0x001c50, Reset @ 0x001ab0,
//       Process @ 0x001af0, FetchResult @ 0x001b40)
// ============================================================================
// Tệp tiêu đề phục hồi toàn bộ 20 biểu tượng C++ thuộc không gian tên
// `lab::speech::client` và 3 hàm móc yếu (`JNI_SetAssetManager`, `JNI_OnLoad_UUID`,
// `licbag_set_java_vm`) được liên kết động qua bảng `.plt` của `libspeechengine.so`.
// ============================================================================

#pragma once

#include "speechengine_types.h"
#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

// Weak C hooks imported at .dynsym [022], [027], [033]
extern "C" {
void JNI_SetAssetManager(void* env, void* asset_manager);
int32_t JNI_OnLoad_UUID(void* vm, void* reserved);
void licbag_set_java_vm(void* vm);
}

namespace lab::speech::client {

// ============================================================================
// 1. OPTIONS — KEY-VALUE CONFIGURATION CONTAINER (8 BYTES ABI POINTER HANDLE)
// Phục hồi từ `createEngineToNative` @ 0x0020bc (`mov w0, #8; bl operator new(nothrow)`)
// và 4 nạp chồng `Options::SetOption` @ 0x0022b0..0x002838
// ============================================================================
class Options {
public:
    static constexpr size_t kAbiAllocatedSize = 8U; // `mov w0, #8` @ 0x0020bc

    // [020] _ZN3lab6speech6client7OptionsC1Ev (.plt @ 0x001b60)
    Options();

    // [014] _ZN3lab6speech6client7OptionsD1Ev (.plt @ 0x001b00)
    ~Options();

    // [031] _ZNK3lab6speech6client7Options7IsValidEv (.plt @ 0x001c10)
    bool IsValid() const;

    // [032] _ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_string...ESB_ (.plt @ 0x001c20)
    void SetOption(const std::string& key, const std::string& value);

    // [017] _ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_string...ERKb (.plt @ 0x001b30)
    void SetOption(const std::string& key, const bool& value);

    // [036] _ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_string...ERKi (.plt @ 0x001c60)
    void SetOption(const std::string& key, const int& value);

    // [016] _ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_string...ERKd (.plt @ 0x001b20)
    void SetOption(const std::string& key, const double& value);

    // Inspection helpers for verification / Hàm truy vấn phục vụ kiểm thử
    void setValid(bool valid) { is_valid_ = valid; }
    std::string getStringOption(const std::string& key, const std::string& def = "") const;
    bool getBoolOption(const std::string& key, bool def = false) const;
    int getIntOption(const std::string& key, int def = 0) const;
    double getDoubleOption(const std::string& key, double def = 0.0) const;
    size_t totalOptionCount() const;

private:
    struct OptionsImpl {
        bool                                         valid{false};
        std::unordered_map<std::string, std::string> str_opts{};
        std::unordered_map<std::string, bool>        bool_opts{};
        std::unordered_map<std::string, int>         int_opts{};
        std::unordered_map<std::string, double>      double_opts{};
    };
    OptionsImpl* impl_{nullptr}; // 8-byte pointer matching `mov w0, #8` @ 0x0020bc
    bool         is_valid_{false};
};

/**
 * @brief [023] `_ZN3lab6speech6client14DefaultOptionsEPNS1_7OptionsE` (`.plt @ 0x001b90`).
 * Populates default ASR/TTS/AFP speech parameters and marks `options->IsValid() == true`.
 * Thiết lập bộ tham số mặc định cho `Options` và đánh dấu hợp lệ.
 */
void DefaultOptions(Options* options);

// ============================================================================
// 2. LISTENER — POLYMORPHIC CALLBACK INTERFACE (VTABLE @ 0x007c28)
// Giao diện cơ sở đa hình cho `SpeechEngineListener` (48 bytes = 0x30 @ 0x002108)
// ============================================================================
class Listener {
public:
    Listener() = default;
    virtual ~Listener() = default;                                       // slots [2..3] @ 0x007c38, 0x007c40
    virtual void OnMessage(int type, const std::string& data) = 0;       // slot [4]     @ 0x007c48 -> 0x003098
};

// ============================================================================
// 3. ENGINERESULT — 32-BYTE STACK RETURN STRUCT (sp+0x08..sp+0x27 @ 0x002bf8)
// Cấu trúc kết quả 32 byte trả về qua thanh ghi x8 (indirect result location)
// ============================================================================
struct EngineResult {
    static constexpr size_t kAbiSize = 32U; // +0x00 int32_t err_code (+pad), +0x08 std::string (24 B)

    int32_t     err_code{0}; // +0x00 (`ldr w21, [sp, #8]` @ 0x002c3c)
    int32_t     padding{0};  // +0x04
    std::string data{};      // +0x08..+0x1f (`ldrb w8, [sp, #0x10]` @ 0x002c44)

    EngineResult() = default;
    EngineResult(int32_t code, std::string payload)
        : err_code(code), padding(0), data(std::move(payload)) {}

    /**
     * @brief [015] `_ZN3lab6speech6client12EngineResult8ToStringEv` (`.plt @ 0x001b10`).
     * Invoked by `fetchStringResultToNative` at `0x002d58`.
     * Chuyển đổi `EngineResult` thành chuỗi JSON kết quả cho tầng Java.
     */
    std::string ToString();
};

// ============================================================================
// 4. ENGINE — CORE SPEECH CLIENT ENGINE (8 BYTES ABI POINTER HANDLE)
// Phục hồi từ `createEngineToNative` @ 0x00214c (`mov w0, #8; bl operator new(nothrow)`)
// ============================================================================
class Engine {
public:
    static constexpr size_t kAbiAllocatedSize = 8U; // `mov w0, #8` @ 0x00214c

    // [034] _ZN3lab6speech6client6EngineC1Ev (.plt @ 0x001c40)
    Engine();

    // [009] _ZN3lab6speech6client6EngineD1Ev (.plt @ 0x001ac0)
    ~Engine();

    // [012] _ZN3lab6speech6client6Engine10GetVersionEv (.plt @ 0x001ae0)
    static std::string GetVersion();

    // [021] _ZN3lab6speech6client6Engine17IsEngineSupportedEPKc (.plt @ 0x001b70)
    static bool IsEngineSupported(const char* engine_name);

    // [007] _ZN3lab6speech6client6Engine4InitEPNS1_7OptionsE (.plt @ 0x001aa0)
    int Init(Options* options);

    // [026] _ZN3lab6speech6client6Engine11AddListenerEPNS1_8ListenerE (.plt @ 0x001bc0)
    void AddListener(Listener* listener);

    // [006] _ZN3lab6speech6client6Engine13SendDirectiveEiRKNSt6__ndk112basic_string... (.plt @ 0x001a90)
    int SendDirective(int directive_type, const std::string& directive_data);

    // [035] _ZN3lab6speech6client6Engine4FeedEPKsi (.plt @ 0x001c50)
    int Feed(const int16_t* pcm_samples, int num_samples);

    // [008] _ZN3lab6speech6client6Engine5ResetEv (.plt @ 0x001ab0)
    int Reset();

    // [013] _ZN3lab6speech6client6Engine7ProcessEPKsib (.plt @ 0x001af0)
    int Process(const int16_t* pcm_samples, int num_samples, bool is_last);

    // [018] _ZN3lab6speech6client6Engine11FetchResultEi (.plt @ 0x001b40)
    EngineResult FetchResult(int result_type);

    // Helper math function matching 0x002a98..0x002aa0 & 0x002b88..0x002b94:
    //   `cmp w22, #0; cinc w8, w22, lt; asr w2, w8, #1` -> signed division by 2 toward zero
    static constexpr int32_t computePcm16SampleCountFromBytes(int32_t byte_length) {
        int32_t adjusted = byte_length + (byte_length < 0 ? 1 : 0);
        return adjusted >> 1;
    }

    // Inspection helpers for verification
    int64_t totalFedSamples() const;
    double lastRmsDbFs() const;

private:
    struct EngineImpl;
    EngineImpl* impl_{nullptr};
};

} // namespace lab::speech::client
