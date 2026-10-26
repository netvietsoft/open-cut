// ============================================================================
// RECONSTRUCTED C++ HEADER: speechepg_sdk_client.h
// Target Library: libspeechepg.so (18,256 bytes, ELF64 AArch64)
// Module: lab::speech::client::Engine, Options, Listener & EngineResult
// Reference Disassembly (.dynsym [003]..[036] & .plt 0x001a70..0x001c70):
//   - lab::speech::client::Options (C1Ev @ 0x001a80, D1Ev @ 0x001c70, IsValid @ 0x001ba0)
//   - lab::speech::client::DefaultOptions(Options*) @ 0x001b80
//   - lab::speech::client::Options::SetOption (string @ 0x001b20, bool @ 0x001bd0,
//                                              int @ 0x001b70, double @ 0x001a90)
//   - lab::speech::client::Listener (vtable @ 0x007c18, OnMessage @ 0x002248)
//   - lab::speech::client::EngineResult (32 bytes on stack @ 0x0030a4, ToString @ 0x001c00)
//   - lab::speech::client::Engine (C1Ev @ 0x001b40, D1Ev @ 0x001bb0, GetVersion @ 0x001ac0,
//       IsEngineSupported @ 0x001b30, Init @ 0x001ad0, AddListener @ 0x001b90,
//       SendDirective @ 0x001b10, Feed @ 0x001c40, Reset @ 0x001c10,
//       Process @ 0x001b60, FetchResult @ 0x001c50)
// ============================================================================
// Tệp tiêu đề phục hồi toàn bộ 20 biểu tượng C++ thuộc không gian tên
// `lab::speech::client` và 3 hàm móc yếu (`JNI_SetAssetManager`, `JNI_OnLoad_UUID`,
// `licbag_set_java_vm`) được liên kết động qua bảng `.plt` của `libspeechepg.so`.
// ============================================================================

#pragma once

#include "speechepg_types.h"
#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

// Weak C hooks imported at .dynsym [011], [028], [032]
extern "C" {
void JNI_SetAssetManager(void* vm_or_env, void* asset_manager);
int32_t JNI_OnLoad_UUID(void* vm, void* reserved);
void licbag_set_java_vm(void* vm);
}

namespace lab::speech::client {

// ============================================================================
// 1. OPTIONS — KEY-VALUE CONFIGURATION CONTAINER (8 BYTES ABI POINTER HANDLE)
// Phục hồi từ `createEngineToNative` @ 0x002534 (`mov w0, #8; bl operator new(nothrow)`)
// và 4 nạp chồng `Options::SetOption` @ 0x002728..0x002cb0
// ============================================================================
class Options {
public:
    static constexpr size_t kAbiAllocatedSize = 8U; // `mov w0, #8` @ 0x002534

    // [004] _ZN3lab6speech6client7OptionsC1Ev (.plt @ 0x001a80)
    Options();

    // [036] _ZN3lab6speech6client7OptionsD1Ev (.plt @ 0x001c70)
    ~Options();

    // [023] _ZNK3lab6speech6client7Options7IsValidEv (.plt @ 0x001ba0)
    bool IsValid() const;

    // [014] _ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_string...ESB_ (.plt @ 0x001b20)
    void SetOption(const std::string& key, const std::string& value);

    // [026] _ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_string...ERKb (.plt @ 0x001bd0)
    void SetOption(const std::string& key, const bool& value);

    // [019] _ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_string...ERKi (.plt @ 0x001b70)
    void SetOption(const std::string& key, const int& value);

    // [005] _ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_string...ERKd (.plt @ 0x001a90)
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
    OptionsImpl* impl_{nullptr}; // 8-byte pointer matching `mov w0, #8` @ 0x002534
    bool         is_valid_{false};
};

/**
 * @brief [021] `_ZN3lab6speech6client14DefaultOptionsEPNS1_7OptionsE` (`.plt @ 0x001b80`).
 * Invoked directly inside `SpeechPluginBridge_createEngineToNative` at `0x002550`!
 * Thiết lập bộ tham số mặc định cho `Options` và đánh dấu hợp lệ.
 */
void DefaultOptions(Options* options);

// ============================================================================
// 2. LISTENER — POLYMORPHIC CALLBACK INTERFACE (VTABLE @ 0x007c18)
// Giao diện cơ sở đa hình cho `SpeechPluginListener` (48 bytes = 0x30 @ 0x002580)
// ============================================================================
class Listener {
public:
    Listener() = default;
    virtual ~Listener() = default;                                       // slots [2..3] @ 0x007c28, 0x007c30
    virtual void OnMessage(int type, const std::string& data) = 0;       // slot [4]     @ 0x007c38 -> 0x002248
};

// ============================================================================
// 3. ENGINERESULT — 32-BYTE STACK RETURN STRUCT (sp+0x08..sp+0x27 @ 0x0030a4)
// Cấu trúc kết quả 32 byte trả về qua thanh ghi x8 (indirect result location)
// ============================================================================
struct EngineResult {
    static constexpr size_t kAbiSize = 32U; // +0x00 int32_t err_code (+pad), +0x08 std::string (24 B)

    int32_t     err_code{0}; // +0x00 (`ldr w21, [sp, #8]` @ 0x0030b4)
    int32_t     padding{0};  // +0x04
    std::string data{};      // +0x08..+0x1f (`ldrb w8, [sp, #0x10]` @ 0x0030bc)

    EngineResult() = default;
    EngineResult(int32_t code, std::string payload)
        : err_code(code), padding(0), data(std::move(payload)) {}

    /**
     * @brief [029] `_ZN3lab6speech6client12EngineResult8ToStringEv` (`.plt @ 0x001c00`).
     * Invoked by `fetchStringResultToNative` at `0x0031d0`.
     * Chuyển đổi `EngineResult` thành chuỗi JSON kết quả cho tầng Java.
     */
    std::string ToString();
};

// ============================================================================
// 4. ENGINE — CORE SPEECH CLIENT ENGINE (8 BYTES ABI POINTER HANDLE)
// Phục hồi từ `createEngineToNative` @ 0x0025c4 (`mov w0, #8; bl operator new(nothrow)`)
// ============================================================================
class Engine {
public:
    static constexpr size_t kAbiAllocatedSize = 8U; // `mov w0, #8` @ 0x0025c4

    // [016] _ZN3lab6speech6client6EngineC1Ev (.plt @ 0x001b40)
    Engine();

    // [024] _ZN3lab6speech6client6EngineD1Ev (.plt @ 0x001bb0)
    ~Engine();

    // [008] _ZN3lab6speech6client6Engine10GetVersionEv (.plt @ 0x001ac0)
    static std::string GetVersion();

    // [015] _ZN3lab6speech6client6Engine17IsEngineSupportedEPKc (.plt @ 0x001b30)
    static bool IsEngineSupported(const char* engine_name);

    // [009] _ZN3lab6speech6client6Engine4InitEPNS1_7OptionsE (.plt @ 0x001ad0)
    int Init(Options* options);

    // [022] _ZN3lab6speech6client6Engine11AddListenerEPNS1_8ListenerE (.plt @ 0x001b90)
    void AddListener(Listener* listener);

    // [013] _ZN3lab6speech6client6Engine13SendDirectiveEiRKNSt6__ndk112basic_string... (.plt @ 0x001b10)
    int SendDirective(int directive_type, const std::string& directive_data);

    // [033] _ZN3lab6speech6client6Engine4FeedEPKsi (.plt @ 0x001c40)
    int Feed(const int16_t* pcm_samples, int num_samples);

    // [030] _ZN3lab6speech6client6Engine5ResetEv (.plt @ 0x001c10)
    int Reset();

    // [018] _ZN3lab6speech6client6Engine7ProcessEPKsib (.plt @ 0x001b60)
    int Process(const int16_t* pcm_samples, int num_samples, bool is_last);

    // [034] _ZN3lab6speech6client6Engine11FetchResultEi (.plt @ 0x001c50)
    EngineResult FetchResult(int result_type);

    // Helper math function matching 0x002f10..0x002f18 & 0x003000..0x00300c:
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
