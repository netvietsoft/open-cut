// ============================================================================
// File: lynx_v8_runtime.h
// Target: liblynx_v8_bridge.so (0x00d1b8..0x013358, 0x01361c..0x013714)
// Description:
//   [EN] Complete V8IsolateInstanceImpl, V8ContextWrapperImpl, V8HostObjectProxy,
//        V8HostFunctionProxy, MurmurHash64A + NEON Popcount Hash Table, and
//        lynx::piper::V8Runtime (352-byte ABI layout) reconstructed from AArch64.
//   [VN] Toàn bộ V8IsolateInstanceImpl, V8ContextWrapperImpl, V8HostObjectProxy,
//        V8HostFunctionProxy, Bảng băm MurmurHash64A + NEON Popcount, và
//        lynx::piper::V8Runtime (bố cục ABI 352 byte) tái dựng từ AArch64.
// ============================================================================

#pragma once

#include "lynx_v8_bridge_types.h"
#include "lynx_v8_profiler_cache.h"
#include <atomic>
#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace lynx {
namespace piper {

class Runtime;

// ============================================================================
// [EN] 1. HostObject & HostFunction Interfaces (JSI Piper ABI)
// [VN] 1. Giao diện HostObject & HostFunction (ABI JSI Piper)
// ============================================================================
class HostObject {
public:
    virtual ~HostObject() = default;
    // Vtable +0x10: get(Runtime*, const PropNameID&) @ 0x00f57c..0x00f584
    virtual JSIValue get(Runtime* rt, const std::string& prop_name) = 0;
    // Vtable +0x18: set(Runtime*, const PropNameID&, const Value&) @ 0x00f748..0x00f750
    virtual void set(Runtime* rt, const std::string& prop_name, const JSIValue& value) = 0;
    // Vtable +0x20: getPropertyNames(Runtime&) @ 0x00f844..0x00f84c
    virtual std::vector<std::string> getPropertyNames(Runtime& rt) = 0;
};

using HostFunctionType = std::function<JSIValue(
    Runtime& rt,
    const JSIValue& this_val,
    const JSIValue* args,
    size_t count)>;

// ============================================================================
// [EN] 2. Thread-Local Host Function Call Error Stack Frame (`104 bytes = 0x68`)
//      Verified at `0x00ed58..0x00ef08` and `0x00f02c..0x00f278`:
//        `mov w26, #0x68; umaddl x0, w24, w26, x8` @ `0x00ed88..0x00ed94`
//        `mov w8, #0x68; umull x0, w20, w8` @ `0x00f210..0x00f214`
// [VN] 2. Khung ngăn xếp lỗi gọi hàm Host cục bộ luồng (`104 bytes = 0x68`)
//      Xác minh tại `0x00ed58..0x00ef08` và `0x00f02c..0x00f278`.
// ============================================================================
struct V8HostCallErrorFrame {
    uint8_t error_kind{0};          // +0x00: 0 = none, 1 = JSIValue error, 2 = JSError
    uint8_t padding0[7]{0};
    JSIValue js_value_error{};      // +0x08..0x17
    std::string message;            // +0x18..0x2f
    std::string stack;              // +0x30..0x47
    std::string name;               // +0x48..0x5f
    bool has_js_error{false};       // +0x60
    uint8_t padding1[7]{0};
};

static_assert(sizeof(V8HostCallErrorFrame) == 104,
              "V8HostCallErrorFrame ABI size must be 104 bytes (0x68)");

// ============================================================================
// [EN] 3. V8IsolateInstanceImpl (`0x00d1b8..0x00d464`, vtable @ `0x018150`)
// [VN] 3. V8IsolateInstanceImpl (`0x00d1b8..0x00d464`, vtable tại `0x018150`)
// ============================================================================
class V8IsolateInstanceImpl {
public:
    V8IsolateInstanceImpl();
    virtual ~V8IsolateInstanceImpl();

    // Disassembly @ `0x00d258..0x00d394`:
    //   1. Calls `std::call_once` (`0x01c0b8`, callback `0x00d39c`) to initialize
    //      `v8::platform::NewDefaultPlatform`, `InitializeICU`, `InitializePlatform`, `Initialize`.
    //   2. Creates `v8::ArrayBuffer::Allocator::NewDefaultAllocator()`.
    //   3. Calls `v8::Isolate::New(CreateParams)`.
    //   4. Queries `LynxEnv::GetInstance()->GetV8HeapSize()`: if `> 0`, logs
    //      `"get v8 MaxHeapSize: "` (`0x00680b`) and calls `UpdateMaxHeapSize`.
    void InitIsolate(int64_t configured_max_heap_size_bytes = 0);

    void* Isolate() const noexcept { return isolate_ptr_; }
    int64_t max_heap_size_bytes() const noexcept { return max_heap_size_bytes_; }
    static bool IsPlatformInitialized() noexcept;

private:
    static void InitializeV8PlatformOnce();

    void* isolate_ptr_{nullptr};              // +0x08
    void* array_buffer_allocator_{nullptr};   // +0x10
    int64_t max_heap_size_bytes_{0};
};

// ============================================================================
// [EN] 4. V8ContextWrapperImpl (`0x00d468..0x00d7dc`, vtable @ `0x018208`)
// [VN] 4. V8ContextWrapperImpl (`0x00d468..0x00d7dc`, vtable tại `0x018208`)
// ============================================================================
class V8ContextWrapperImpl {
public:
    explicit V8ContextWrapperImpl(std::shared_ptr<V8IsolateInstanceImpl> isolate_wrapper);
    virtual ~V8ContextWrapperImpl();

    // Disassembly @ `0x00d5cc..0x00d7dc`:
    //   Logs `"V8ContextWrapper Init"`, calls
    //   `SetCaptureStackTraceForUncaughtExceptions(true, 10, kDetailed = 7)`
    //   (`mov w1, #1; mov w2, #0xa; mov w3, #7` @ `0x00d6ec..0x00d6f4`),
    //   creates `v8::Context::New`, and globalizes handle (`0x00d730`).
    bool Init();

    std::shared_ptr<V8IsolateInstanceImpl> getIsolateWrapper() const noexcept {
        return isolate_wrapper_;
    }
    uint64_t getContextPersistentSlot() const noexcept { return context_global_slot_; }
    bool isInitialized() const noexcept { return initialized_; }

    // Vtable +0x30 (`0x010790..0x010818`): getCpuProfiler
    std::shared_ptr<cache::V8CpuProfilerBridge> getCpuProfiler() const noexcept {
        return cpu_profiler_;
    }

private:
    std::shared_ptr<V8IsolateInstanceImpl> isolate_wrapper_; // +0x18..0x27
    uint64_t context_global_slot_{0};                        // +0x28
    std::shared_ptr<cache::V8CpuProfilerBridge> cpu_profiler_;
    bool initialized_{false};
};

// ============================================================================
// [EN] 5. MurmurHash64A Pointer Hash & Bucket Indexer (`0x00e9b8..0x00e9f0`, `0x013f00`)
// [VN] 5. Hàm băm con trỏ MurmurHash64A & Bộ định chỉ số Bucket (`0x00e9b8..0x00e9f0`, `0x013f00`)
// ============================================================================
struct V8BridgeHashMath {
    // Disassembly @ `0x00e9b8..0x00e9f0`
    static uint64_t HashPointerWords(uint32_t low_word, uint32_t high_word) noexcept;
    static uint64_t HashPointer(uint64_t ptr_val) noexcept;

    // Disassembly @ `0x013f00..0x013f18`, `0x013f54..0x013f6c`, `0x014290..0x0142b4`:
    //   `cnt v0.8b, v0.8b; uaddlv h0, v0.8b; cmp x9, #1`
    static uint32_t NeonPopcount64(uint64_t val) noexcept;
    static size_t ComputeBucketIndex(uint64_t hash, size_t bucket_count) noexcept;

    // Disassembly @ `0x01400c..0x014020`:
    //   `sub x8, x0, #1; clz x8, x8; neg w8, w8; mov w9, #1; lsl x0, x9, x8`
    static uint64_t NextPowerOfTwo(uint64_t x) noexcept;
};

// ============================================================================
// [EN] 6. lynx::piper::V8Runtime (`352 bytes = 0x160` allocated @ `0x013624`)
//      Reconstructed from `0x00fd2c..0x013358` and `0x01361c..0x013714` (vtable @ `0x018430`).
// [VN] 6. lynx::piper::V8Runtime (`352 bytes = 0x160` cấp phát tại `0x013624`)
//      Tái dựng từ `0x00fd2c..0x013358` và `0x01361c..0x013714` (vtable tại `0x018430`).
// ============================================================================
class V8Runtime {
public:
    // Exported weak constants in .rodata:
    //   [179] 0x006820: kUrlLynxCore = "lynx_core"
    //   [185] 0x00682a: kUrlHost     = "file://lynx"
    static constexpr const char kUrlLynxCore[]   = "lynx_core";
    static constexpr const char kUrlHost[]       = "file://lynx";
    static constexpr const char kUrlFileShared[] = "file://shared";
    static constexpr const char kUrlFileView[]   = "file://view";

    // Constructed at `0x01361c..0x013714` (`mov w0, #0x160; bl operator new`)
    V8Runtime();
    // Destructor at `0x00fd2c..0x00ff3c`
    virtual ~V8Runtime();

    // Lifecycle & Context attachment (`0x00fb00..0x00fc48`, `0x010770..0x010840`)
    void InitRuntime(std::shared_ptr<V8ContextWrapperImpl> context_wrapper);
    void SetEnableUserBytecode(bool enable) noexcept { enable_user_bytecode_ = enable; }
    void SetBytecodeSourceUrl(std::string url) { bytecode_source_url_ = std::move(url); }
    void SetPageGroupId(std::string group_id, bool enable_prefix_mode = true) {
        group_id_ = std::move(group_id);
        enable_url_prefix_ = enable_prefix_mode;
    }
    void SetViewId(int32_t view_id) noexcept { view_id_ = view_id; }

    // URL Normalization & Substring Search (`0x010844..0x010b38`, `0x013000..0x013148`)
    static std::string PrependLeadingSlash(const std::string& url);
    static size_t FindSubstring(const std::string& haystack, const char* needle) noexcept;
    std::string AddPrefixToUrlIfNeeded(const std::string& url) const;

    // Script Preparation & Evaluation (`0x00ff40..0x01062c`, `0x013220..0x0132a0`)
    std::shared_ptr<V8JavaScriptPreparation> prepareJavaScript(
        std::shared_ptr<const Buffer> buffer,
        std::string source_url);
    JSIValue evaluatePreparedJavaScript(const std::shared_ptr<const V8JavaScriptPreparation>& js);
    JSIValue evaluateJavaScript(std::shared_ptr<const Buffer> buffer,
                                const std::string& source_url);
    JSIValue evaluateJavaScriptBytecode(std::shared_ptr<const Buffer> buffer,
                                        const std::string& source_url);

    // Global & Object Property Operations (`0x0106a4..0x0106dc`, `0x0114b0..0x0121e8`)
    JSIValue global();
    void RequestGC();
    JSIValue createObject();
    JSIValue createObjectFromHostObject(std::shared_ptr<HostObject> ho);
    std::shared_ptr<HostObject> getHostObject(const JSIValue& obj) const;
    bool isHostObject(const JSIValue& obj) const noexcept;

    JSIValue createFromHostFunction(const std::string& name,
                                    unsigned int param_count,
                                    HostFunctionType func);
    bool isHostFunction(const JSIValue& obj) const noexcept;

    bool setPropertyValue(const JSIValue& obj, const std::string& name, const JSIValue& value);
    JSIValue getProperty(const JSIValue& obj, const std::string& name) const;
    bool hasProperty(const JSIValue& obj, const std::string& name) const;
    std::vector<std::string> getPropertyNames(const JSIValue& obj) const;

    // Array & ArrayBuffer Operations (`0x01198c..0x0121e8`)
    JSIValue createArray(size_t length);
    size_t size(const JSIValue& arr) const;
    JSIValue getValueAtIndex(const JSIValue& arr, size_t idx) const;
    bool setValueAtIndexImpl(const JSIValue& arr, size_t idx, const JSIValue& value);

    JSIValue createArrayBufferCopy(const uint8_t* bytes, size_t byte_length);
    JSIValue createArrayBufferNoCopy(std::unique_ptr<const uint8_t[]> bytes, size_t byte_length);
    size_t arrayBufferSize(const JSIValue& ab) const;
    uint8_t* arrayBufferData(const JSIValue& ab) const;

    // Function & Constructor Invocation (`0x0127a4..0x012c4c`)
    JSIValue call(const JSIValue& func,
                  const JSIValue& js_this,
                  const JSIValue* args,
                  size_t count);
    JSIValue callAsConstructor(const JSIValue& func,
                               const JSIValue* args,
                               size_t count);

    // Value Conversion (`0x00dc18..0x00dd78`, `0x012dd0..0x012ec4`)
    std::string valueToString(const JSIValue& val) const;
    bool strictEquals(const JSIValue& a, const JSIValue& b) const noexcept;

    const std::string& last_exception_message() const noexcept { return last_exception_; }
    size_t gc_request_count() const noexcept { return gc_request_count_; }
    size_t host_object_count() const noexcept { return host_objects_.size(); }
    size_t host_function_count() const noexcept { return host_functions_.size(); }

private:
    struct ObjectStorage {
        std::unordered_map<std::string, JSIValue> props;
        std::vector<JSIValue> elements;
        std::vector<uint8_t> array_buffer;
        std::shared_ptr<HostObject> host_object;
        HostFunctionType host_function;
        std::string function_name;
        unsigned int param_count{0};
        bool is_array{false};
        bool is_array_buffer{false};
        bool is_function{false};
    };

    std::shared_ptr<V8ContextWrapperImpl> context_wrapper_; // +0x108 / +0x118
    bool enable_user_bytecode_{false};                      // +0x58
    std::string bytecode_source_url_;                       // +0x60..0x77
    bool enable_url_prefix_{false};                         // +0xdc
    int32_t view_id_{-1};                                   // +0xd8
    std::string group_id_;                                  // +0xe8..0xff
    float host_object_max_load_factor_{1.0f};               // +0xa8 (0x3f800000 @ 0x013684)
    float host_function_max_load_factor_{1.0f};             // +0xd0 (0x3f800000 @ 0x013690)
    bool is_finalizing_{false};                             // +0x140
    size_t gc_request_count_{0};
    uint64_t next_handle_id_{1};
    uint64_t global_object_handle_{0};
    std::string last_exception_;

    mutable std::unordered_map<uint64_t, std::shared_ptr<ObjectStorage>> objects_;
    mutable std::unordered_map<uint64_t, std::string> strings_;
    mutable std::unordered_map<uint64_t, std::shared_ptr<HostObject>> host_objects_;
    mutable std::unordered_map<uint64_t, HostFunctionType> host_functions_;
    mutable std::unordered_map<std::string, std::shared_ptr<Buffer>> bytecode_cache_;
};

} // namespace piper
} // namespace lynx
