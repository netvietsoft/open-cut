// ============================================================================
// File: lynx_v8_bridge_pseudocode.cpp
// Target: liblynx_v8_bridge.so (117,008 bytes, 26 ELF64 sections, 188 .dynsym)
// SHA-256: a056a8578279f5b2aa07946891d83c060858fcdde25c31096bb3cdd09a53ad65
// Task ID: TASK-109-RECONSTRUCTION-LIBLYNX_V8_BRIDGE / TASK_SO_134_liblynx_v8_bridge
// Description:
//   [EN] Master C++17 reconstruction of liblynx_v8_bridge.so integrating:
//        1. V8 Tagged-Pointer & InstanceType Inspector (`0x00db74..0x00dd78`, `0x013e7c`, `0x01419c`)
//        2. JSError Stack/Cause/Name Builder (`0x00dfe0..0x00e6e8`, `0x0132a4..0x01333c`)
//        3. Thread-Local Host Call Error Stack (`104`-byte = `0x68` frame array `0x00ed58..0x00f278`)
//        4. V8 HostObjectProxy & HostFunctionProxy Weak-Callback Hash Table (`0x00e724..0x00fa78`)
//        5. Exported `JNI_OnLoad` (`0x013590`) and `lynx_v8_bridge_run_self_test()`.
//   [VN] Bản tái dựng C++17 tổng thể của liblynx_v8_bridge.so tích hợp:
//        1. Bộ kiểm tra con trỏ gắn thẻ & InstanceType V8 (`0x00db74..0x00dd78`, `0x013e7c`, `0x01419c`)
//        2. Bộ dựng JSError Stack/Cause/Name (`0x00dfe0..0x00e6e8`, `0x0132a4..0x01333c`)
//        3. Ngăn xếp lỗi gọi hàm Host cục bộ luồng (mảng khung `104` byte = `0x68` tại `0x00ed58..0x00f278`)
//        4. Bảng băm Weak-Callback của V8 HostObjectProxy & HostFunctionProxy (`0x00e724..0x00fa78`)
//        5. Hàm xuất khẩu `JNI_OnLoad` (`0x013590`) và `lynx_v8_bridge_run_self_test()`.
// ============================================================================

#include "lynx_v8_bridge_interface.h"
#include <algorithm>
#include <cassert>
#include <cstring>
#include <sstream>
#include <vector>

namespace lynx {
namespace v8_bridge {

// ============================================================================
// [EN] 1. V8 Internal Tagged-Pointer & InstanceType Classifier
//      Reconstructed from `0x00db74..0x00dd78`, `0x00df74..0x00df8c`,
//      `0x013e7c..0x013e88`, and `0x01417c..0x0141ac`.
// [VN] 1. Bộ phân loại con trỏ gắn thẻ & InstanceType nội bộ V8
//      Tái dựng từ `0x00db74..0x00dd78`, `0x00df74..0x00df8c`,
//      `0x013e7c..0x013e88`, và `0x01417c..0x0141ac`.
// ============================================================================
struct SimulatedV8HeapObjectLayout {
    alignas(8) uint8_t map_bytes[32]{0};
    alignas(8) uint8_t object_bytes[64]{0};

    // Builds a simulated V8 HeapObject tagged pointer (`ptr | 1`) with the given
    // `instance_type` at `[map_raw + 0x0b]` and `oddball_kind` at `[obj_raw + 0x2b]`
    // or `internal_field_0` at `[obj_raw + 0x17]`.
    uint64_t Configure(uint16_t instance_type,
                       uint32_t oddball_kind,
                       uint64_t internal_field_0 = 0) noexcept {
        std::memset(map_bytes, 0, sizeof(map_bytes));
        std::memset(object_bytes, 0, sizeof(object_bytes));

        uint64_t map_raw = reinterpret_cast<uint64_t>(map_bytes);
        std::memcpy(map_bytes + kV8MapInstanceTypeOffset, &instance_type, sizeof(uint16_t));

        uint64_t map_tagged = map_raw | kV8HeapObjectTag;
        // At [tagged_obj - 1] == object_bytes[0..7], store Map pointer (or raw map_raw for ldur [x8, #-1])
        std::memcpy(object_bytes + 0, &map_raw, sizeof(uint64_t));
        std::memcpy(object_bytes + kV8OddballKindOffset + 1, &oddball_kind, sizeof(uint32_t));
        std::memcpy(object_bytes + kV8FastInternalField0Offset + 1, &internal_field_0, sizeof(uint64_t));
        (void)map_tagged;

        return reinterpret_cast<uint64_t>(object_bytes) | kV8HeapObjectTag;
    }
};

class V8TaggedValueInspector {
public:
    // [EN] Exact implementation of `0x00dc88..0x00dcd8`:
    //      `and x9, x8, #3; cmp x9, #1; b.ne`
    //      `ldur x9, [x8, #-1]; ldurh w9, [x9, #0xb]`
    //      `cmp w9, #0x83` (ODDBALL_TYPE):
    //        `ldur w8, [x8, #0x2b]; lsl x8, x8, #32`
    //        `cmp x8, #0x500000000` -> Undefined (ValueKind::UndefinedKind = 0)
    //        `cmp x8, #0x300000000` -> Null      (ValueKind::NullKind = 1)
    //      `cmp w9, #0x7f; b.ls` -> String       (ValueKind::StringKind = 5)
    // [VN] Cài đặt chính xác `0x00dc88..0x00dcd8`:
    //      Phân loại con trỏ gắn thẻ V8 (Oddball Undefined=5, Oddball Null=3, String <= 0x7f).
    static piper::ValueKind ClassifyTaggedWord(uint64_t tagged_word) noexcept {
        if ((tagged_word & kV8HeapObjectTagMask) != kV8HeapObjectTag) {
            return piper::ValueKind::NumberKind; // Smi
        }
        const uint8_t* raw_obj_plus_1 = reinterpret_cast<const uint8_t*>(tagged_word);
        uint64_t map_ptr = 0;
        std::memcpy(&map_ptr, raw_obj_plus_1 + kV8MapPointerOffset, sizeof(uint64_t));
        if (map_ptr == 0) {
            return piper::ValueKind::UndefinedKind;
        }
        uint16_t instance_type = 0;
        std::memcpy(&instance_type,
                    reinterpret_cast<const uint8_t*>(map_ptr) + kV8MapInstanceTypeOffset,
                    sizeof(uint16_t));

        if (instance_type == kV8OddballInstanceType) {
            uint32_t oddball_kind = 0;
            std::memcpy(&oddball_kind,
                        raw_obj_plus_1 + kV8OddballKindOffset,
                        sizeof(uint32_t));
            const uint64_t shifted = static_cast<uint64_t>(oddball_kind) << 32U;
            if (shifted == 0x500000000ULL) {
                return piper::ValueKind::UndefinedKind;
            }
            if (shifted == 0x300000000ULL) {
                return piper::ValueKind::NullKind;
            }
        }
        if (instance_type <= 0x007fU) {
            return piper::ValueKind::StringKind;
        }
        return piper::ValueKind::ObjectKind;
    }

    // [EN] Exact implementation of `0x013e7c..0x013e88` and `0x01417c..0x0141ac`
    //      used in `0x00ebbc..0x00ebe0`, `0x00f518..0x00f538`, `0x011440..0x011458`:
    //      Checks if `instance_type == 0x0410` (`JS_OBJECT_TYPE`) or
    //      `(uint32_t)(instance_type - 0x0421) <= 0x03e9` (`JS_SPECIAL_API_OBJECT_TYPE` range),
    //      and if so reads fast internal field 0 directly at `[x8, #0x17]`.
    // [VN] Cài đặt chính xác `0x013e7c..0x013e88` và `0x01417c..0x0141ac`:
    //      Kiểm tra `instance_type == 0x0410` hoặc nằm trong dải `0x0421..0x080a`
    //      để đọc nhanh trường nội bộ 0 tại `[x8, #0x17]`.
    static bool CanReadFastInternalField0(uint16_t instance_type) noexcept {
        if (instance_type == kV8JsObjectInstanceType) {
            return true;
        }
        const uint32_t offset_type = static_cast<uint32_t>(instance_type) - kV8SpecialApiObjTypeMin;
        return offset_type <= kV8SpecialApiObjTypeSpan;
    }

    static uint64_t ExtractInternalField0(uint64_t tagged_word) noexcept {
        if ((tagged_word & kV8HeapObjectTagMask) != kV8HeapObjectTag) {
            return 0;
        }
        const uint8_t* raw_obj_plus_1 = reinterpret_cast<const uint8_t*>(tagged_word);
        uint64_t map_ptr = 0;
        std::memcpy(&map_ptr, raw_obj_plus_1 + kV8MapPointerOffset, sizeof(uint64_t));
        if (map_ptr == 0) {
            return 0;
        }
        uint16_t instance_type = 0;
        std::memcpy(&instance_type,
                    reinterpret_cast<const uint8_t*>(map_ptr) + kV8MapInstanceTypeOffset,
                    sizeof(uint16_t));
        if (!CanReadFastInternalField0(instance_type)) {
            return 0;
        }
        uint64_t field0 = 0;
        std::memcpy(&field0, raw_obj_plus_1 + kV8FastInternalField0Offset, sizeof(uint64_t));
        return field0;
    }
};

// ============================================================================
// [EN] 2. JSError Formatting & Exception Builder (`0x00dfe0..0x00e6e8`, `0x0132a4..0x01333c`)
//      Matches:
//        - `0x00dfe0..0x00e18c`: Formats `"at " + func_name + " (" + file + ":" + std::to_string(line) + ")"`
//          with error code `0x4e87` (`mov w3, #0x4e87` @ `0x00e128`) and default name `"NativeError"` (`0x006375` @ `0x00e154`).
//        - `0x0132a4..0x01333c`: Constructs `JSError` with error code `0x4e85` (`mov w3, #0x4e85` @ `0x0132e4`).
//        - `0x00e4a4..0x00e6e8`: Attaches `"stack"` (`0x0063cd`), `"cause"` (`0x0064ed`), and `"name"` (`0x006506`)
//          properties onto `v8::Exception::Error(message)`.
// [VN] 2. Bộ định dạng JSError & Tạo ngoại lệ (`0x00dfe0..0x00e6e8`, `0x0132a4..0x01333c`)
// ============================================================================
struct FormattedJSError {
    int32_t error_code{0}; // 0x4e87 (20103) or 0x4e85 (20101)
    std::string message;
    std::string stack;
    std::string name;
    std::string cause;
    bool is_native_error{false};
};

class JSErrorFormatter {
public:
    static constexpr int32_t kErrorCodeNativeCallException = 0x4e87; // 20103 @ 0x00e128
    static constexpr int32_t kErrorCodeScriptException     = 0x4e85; // 20101 @ 0x0132e4

    // Exact reconstruction of `0x00dfe0..0x00e18c`
    static FormattedJSError BuildNativeCallException(
        const std::string& message,
        const std::string& func_name,
        const std::string& file_name,
        int32_t line_number) {
        // [EN] Disassembly @ `0x00e064..0x00e0f0`:
        //      `"at "` (`0x006807`) + `func_name` + `" ("` (`0x006754`) +
        //      `file_name` + `":"` (`0x00681d`) + `std::to_string(line_number)` + `")"` (`0x006752`).
        // [VN] Mã máy tại `0x00e064..0x00e0f0`:
        //      Định dạng chuỗi ngăn xếp `"at " + func_name + " (" + file_name + ":" + to_string(line) + ")"`.
        FormattedJSError err{};
        err.error_code = kErrorCodeNativeCallException;
        err.message = message;
        err.stack = "at " + func_name + " (" + file_name + ":" + std::to_string(line_number) + ")";
        err.name = "NativeError"; // 0x006375 @ 0x00e154
        err.is_native_error = false; // strb wzr, [x19, #0x58] @ 0x00e160
        return err;
    }

    // Exact reconstruction of `0x0132a4..0x01333c`
    static FormattedJSError BuildScriptEvalException(
        const std::string& name,
        const std::string& message,
        const std::string& stack) {
        FormattedJSError err{};
        err.error_code = kErrorCodeScriptException;
        err.message = message;
        err.stack = stack;
        err.name = name;
        err.is_native_error = true; // mov w8, #1; strb w8, [x21, #0x58] @ 0x013314..0x013318
        return err;
    }
};

// ============================================================================
// [EN] 3. Thread-Local Host Call Error Stack Manager (`0x00ed58..0x00ef08`, `0x00f02c..0x00f278`)
//      Manages dynamic array of `104`-byte (`0x68`) `V8HostCallErrorFrame` entries.
// [VN] 3. Bộ quản lý ngăn xếp lỗi gọi hàm Host cục bộ luồng (`0x00ed58..0x00ef08`, `0x00f02c..0x00f278`)
//      Quản lý mảng động các khung `V8HostCallErrorFrame` kích thước `104` byte (`0x68`).
// ============================================================================
class ThreadLocalHostErrorStack {
public:
    ThreadLocalHostErrorStack() {
        // [EN] Disassembly @ `0x00f048..0x00f054`:
        //      Initializes inline 1-element storage with capacity `-8` (`mov x8, #-0x800000000`
        //      -> `size = 0, capacity = -8` indicating inline stack buffer before heap growth).
        // [VN] Mã máy tại `0x00f048..0x00f054`:
        //      Khởi tạo bộ đệm nội tuyến trước khi nhân đôi dung lượng trên heap.
        frames_.reserve(2);
    }

    // Exact capacity growth formula @ `0x00f1e4..0x00f240`:
    //   `cmp w8, #0; cneg w8, w8, mi; lsl w9, w8, #1; csinc w20, w9, wzr, ne`
    //   `mov w8, #0x68; umull x0, w20, w8`
    static int32_t ComputeNextCapacity(int32_t current_signed_capacity) noexcept {
        const int32_t abs_cap = (current_signed_capacity < 0)
                                    ? -current_signed_capacity
                                    : current_signed_capacity;
        return (abs_cap == 0) ? 1 : (abs_cap << 1);
    }

    static uint64_t ComputeAllocationBytes(int32_t new_capacity) noexcept {
        constexpr uint64_t kFrameSize = 0x68ULL; // 104 bytes
        return static_cast<uint64_t>(static_cast<uint32_t>(new_capacity)) * kFrameSize;
    }

    void PushFrame(const piper::V8HostCallErrorFrame& frame) {
        frames_.push_back(frame);
    }

    bool PopFrame(piper::V8HostCallErrorFrame* out_frame) {
        if (frames_.empty()) {
            return false;
        }
        if (out_frame != nullptr) {
            *out_frame = frames_.back();
        }
        frames_.pop_back();
        return true;
    }

    size_t depth() const noexcept { return frames_.size(); }

private:
    std::vector<piper::V8HostCallErrorFrame> frames_;
};

} // namespace v8_bridge
} // namespace lynx

// ============================================================================
// [EN] Exported C Entrypoints (`JNI_OnLoad` @ `0x013590` & Self-Test Suite)
// [VN] Điểm vào C xuất khẩu (`JNI_OnLoad` tại `0x013590` & Bộ kiểm thử tự động)
// ============================================================================
extern "C" {

int32_t lynx_v8_bridge_JNI_OnLoad(void* vm, void* reserved) {
    return lynx::runtime::JniV8BridgeState::ExecuteJniOnLoad(vm, reserved);
}

int32_t lynx_v8_bridge_run_self_test(void) {
    using namespace lynx;
    using namespace lynx::piper;
    using namespace lynx::v8_bridge;

    // 1. Verify JNI_OnLoad (0x013590) -> 0x00010006 (JNI_VERSION_1_6)
    const int32_t jni_ver = lynx_v8_bridge_JNI_OnLoad(nullptr, nullptr);
    if (jni_ver != 0x00010006 ||
        !runtime::JniV8BridgeState::IsExternalRuntimeHelperRegistered() ||
        !runtime::JniV8BridgeState::IsV8RuntimeProxyFactoryRegistered()) {
        return -1;
    }

    // 2. Verify ObserverList (0x0133a0, 0x0133e0, 0x013538)
    struct TestObserver final : public base::Observer {
        int* counter;
        explicit TestObserver(int* c) : counter(c) {}
        void OnNotify() override { *counter += 1; }
    };
    int notify_total = 0;
    TestObserver obs1(&notify_total);
    TestObserver obs2(&notify_total);
    base::ObserverList obs_list;
    obs_list.AddObserver(&obs1);
    obs_list.AddObserver(&obs2);
    obs_list.AddObserver(&obs1);
    if (obs_list.size() != 3U) {
        return -2;
    }
    obs_list.RemoveObserver(&obs1);
    if (obs_list.size() != 1U) {
        return -3;
    }
    obs_list.ForEachObserver();
    if (notify_total != 1 || !obs_list.empty()) {
        return -4;
    }

    // 3. Verify MurmurHash64A Pointer Hash (0x00e9b8..0x00e9f0) & NEON Popcount Bucket Index (0x013f00)
    const uint64_t h1 = V8BridgeHashMath::HashPointerWords(0x12345678U, 0x0000007fU);
    const uint64_t h2 = V8BridgeHashMath::HashPointer(0x0000007f12345678ULL);
    if (h1 != h2 || h1 == 0) {
        return -5;
    }
    if (V8BridgeHashMath::ComputeBucketIndex(h1, 16U) != (h1 & 15ULL) ||
        V8BridgeHashMath::ComputeBucketIndex(h1, 17U) != (h1 % 17ULL) ||
        V8BridgeHashMath::NextPowerOfTwo(19ULL) != 32ULL) {
        return -6;
    }

    // 4. Verify V8 Bytecode Cache Generator (0x00c048..0x00c744)
    auto src_buf = std::make_shared<StringBuffer>("40 + 2");
    cache::V8BytecodeCacheGenerator cache_gen("file://lynx/app-service.js", src_buf);
    auto cached_buf = cache_gen.GenerateCache();
    if (!cached_buf || cached_buf->size() <= 24U) {
        return -7;
    }
    cache::V8ScriptCachedData cached_view(
        cached_buf->data(),
        static_cast<int32_t>(cached_buf->size()),
        cache::V8ScriptCachedData::kBufferNotOwned);
    if (!cache::V8BytecodeCacheGenerator::ValidateCachedData(cached_view, src_buf->size())) {
        return -8;
    }

    // 5. Verify V8 CPU Profiler & 120-byte (0x78) Node Serializer (0x00c748..0x00d17f)
    auto* helper = runtime::JniV8BridgeState::GetRegisteredRuntimeHelper();
    auto vm_ctx = helper->MakeVM(32LL * 1024LL * 1024LL);
    auto profiler = vm_ctx->getCpuProfiler();
    profiler->SetSamplingInterval(500);
    profiler->StartProfiling("lynx_trace", true);
    profiler->RecordSyntheticSample(2, 1500, "renderTemplate", "file://lynx/core.js", 10, 42, 8);
    auto profile_res = profiler->StopProfiling("lynx_trace");
    if (!profile_res || profile_res->nodes.size() != 2U ||
        sizeof(V8CpuProfileNodeRecord) != 120U ||
        cache::V8CpuProfilerBridge::ComputeNextNodeVectorCapacityBytes(240U, 3U) != 480U) {
        return -9;
    }

    // 6. Verify V8Runtime URL Prefixing (0x010844..0x010b38) & Evaluation (0x00ff40..0x010464)
    auto rt = helper->MakeRuntime();
    rt->InitRuntime(vm_ctx);
    rt->SetPageGroupId("card_group", true);
    rt->SetEnableUserBytecode(true);
    if (rt->AddPrefixToUrlIfNeeded("lynx_core.js") != "file://lynx/lynx_core.js" ||
        rt->AddPrefixToUrlIfNeeded("app.js") != "file://lynx/card_group/app.js") {
        return -10;
    }
    JSIValue eval_res = rt->evaluateJavaScript(src_buf, "app.js");
    if (eval_res.kind != ValueKind::NumberKind || eval_res.data.number_val != 42.0) {
        return -11;
    }

    // 7. Verify V8 Tagged-Pointer Classifier (0x00dc88..0x00dcd8) & NapiRuntimeProxyV8 (0x013958..0x013bec)
    SimulatedV8HeapObjectLayout sim_null;
    const uint64_t tagged_null = sim_null.Configure(kV8OddballInstanceType, kV8OddballKindNull);
    SimulatedV8HeapObjectLayout sim_undef;
    const uint64_t tagged_undef = sim_undef.Configure(kV8OddballInstanceType, kV8OddballKindUndefined);
    if (V8TaggedValueInspector::ClassifyTaggedWord(tagged_null) != ValueKind::NullKind ||
        V8TaggedValueInspector::ClassifyTaggedWord(tagged_undef) != ValueKind::UndefinedKind) {
        return -12;
    }

    auto* napi_factory = runtime::JniV8BridgeState::GetRegisteredNapiFactory();
    auto napi_proxy = napi_factory->Create(nullptr, nullptr);
    if (!napi_proxy || !napi_proxy->Attach()) {
        return -13;
    }
    napi_proxy->Detach();
    return 0;
}

} // extern "C"
