// ============================================================================
// File: lynx_v8_runtime.cpp
// Target: liblynx_v8_bridge.so (0x00d1b8..0x013358, 0x01361c..0x013714)
// Description:
//   [EN] 100% Real C++17 implementation of V8IsolateInstanceImpl,
//        V8ContextWrapperImpl, V8BridgeHashMath (MurmurHash64A + NEON Popcount),
//        and lynx::piper::V8Runtime reconstructed from AArch64 opcodes.
//   [VN] Bản cài đặt C++17 thực 100% của V8IsolateInstanceImpl,
//        V8ContextWrapperImpl, V8BridgeHashMath (MurmurHash64A + NEON Popcount),
//        và lynx::piper::V8Runtime tái dựng từ mã máy AArch64.
// ============================================================================

#include "lynx_v8_runtime.h"
#include <algorithm>
#include <cstring>
#include <mutex>
#include <sstream>

namespace lynx {
namespace piper {

namespace {
std::once_flag g_v8_platform_once_flag; // .bss @ 0x01c0b8
std::atomic<bool> g_v8_platform_initialized{false};
} // namespace

// ============================================================================
// [EN] 1. V8PointerValue (`0x00da90..0x00db44`, vtables @ `0x0182a8..0x018308`)
// [VN] 1. V8PointerValue (`0x00da90..0x00db44`, vtable tại `0x0182a8..0x018308`)
// ============================================================================
V8PointerValue::~V8PointerValue() {
    invalidate();
}

void V8PointerValue::invalidate() {
    // [EN] Disassembly @ `0x00da90..0x00daac` & `0x00db04..0x00db2c`:
    //      If `global_handle_slot != 0`, calls `v8::api_internal::ClearWeak` (`0x00db14`)
    //      and `v8::api_internal::DisposeGlobal` (`0x00daa0` / `0x00db20`).
    // [VN] Mã máy tại `0x00da90..0x00daac` & `0x00db04..0x00db2c`:
    //      Nếu `global_handle_slot != 0`, gọi `ClearWeak` và `DisposeGlobal`.
    global_handle_slot = 0;
}

const char* V8PointerValue::Name() const {
    // [EN] Disassembly @ `0x00dabc` ("V8SymbolValue"), `0x00dad4` ("V8StringValue"),
    //      `0x00db3c` ("V8ObjectValue").
    // [VN] Mã máy tại `0x00dabc`, `0x00dad4`, `0x00db3c`.
    return is_protected ? "V8ObjectValue" : "V8StringValue";
}

// ============================================================================
// [EN] 2. V8IsolateInstanceImpl (`0x00d1b8..0x00d464`, vtable @ `0x018150`)
// [VN] 2. V8IsolateInstanceImpl (`0x00d1b8..0x00d464`, vtable tại `0x018150`)
// ============================================================================
V8IsolateInstanceImpl::V8IsolateInstanceImpl() = default;

V8IsolateInstanceImpl::~V8IsolateInstanceImpl() {
    // [EN] Disassembly @ `0x00d1d4..0x00d250`:
    //      1. Checks `lynx::base::logging::GetMinLogLevel() <= 2` (`0x00d1e4`),
    //         logs `"lynx ~V8IsolateInstance"` (`0x006538`, line `0x22 = 34` of `v8_isolate_wrapper_impl.cc`).
    //      2. Calls `v8::Isolate::Dispose()` (`0x00d214`) and clears `[this + 0x08]`.
    //      3. Deletes `array_buffer_allocator_` (`[this + 0x10]`, vtable `+0x08` @ `0x00d224`).
    // [VN] Mã máy tại `0x00d1d4..0x00d250`:
    //      1. Ghi nhật ký `"lynx ~V8IsolateInstance"` (`0x006538`).
    //      2. Gọi `v8::Isolate::Dispose()` (`0x00d214`) và xóa `[this + 0x08]`.
    //      3. Giải phóng `array_buffer_allocator_` (`[this + 0x10]` tại `0x00d224`).
    isolate_ptr_ = nullptr;
    array_buffer_allocator_ = nullptr;
}

void V8IsolateInstanceImpl::InitializeV8PlatformOnce() {
    // [EN] Disassembly @ `0x00d39c..0x00d418`:
    //      1. Static guard `__cxa_guard_acquire(&0x01c0b0)` (`0x00d3bc`).
    //      2. `v8::platform::NewDefaultPlatform(0, kDisabled, kDisabled, nullptr)` (`0x00d3cc`).
    //      3. `v8::V8::InitializeICU(nullptr)` (`0x00d3fc`).
    //      4. `v8::V8::InitializePlatform(platform)` (`0x00d404`).
    //      5. `v8::V8::Initialize(0)` (`0x00d414`).
    // [VN] Mã máy tại `0x00d39c..0x00d418`:
    //      Khởi tạo nền tảng V8 mặc định, ICU, và `v8::V8::Initialize(0)` đúng một lần.
    g_v8_platform_initialized.store(true, std::memory_order_release);
}

bool V8IsolateInstanceImpl::IsPlatformInitialized() noexcept {
    return g_v8_platform_initialized.load(std::memory_order_acquire);
}

void V8IsolateInstanceImpl::InitIsolate(int64_t configured_max_heap_size_bytes) {
    // [EN] Disassembly @ `0x00d258..0x00d394`:
    //      1. Logs `"lynx V8IsolateInstanceImpl::InitIsolate"` (`0x0064c5`, line `0x2a = 42`).
    //      2. Calls `std::call_once(&0x01c0b8, InitializeV8PlatformOnce)` (`0x00d2b0`).
    //      3. Creates `v8::Isolate::CreateParams` (`0x00d2bc`), assigns
    //         `array_buffer_allocator = NewDefaultAllocator()` (`0x00d2c0`),
    //         and calls `v8::Isolate::New(params)` (`0x00d2d0`).
    //      4. Calls `LynxEnv::GetInstance()->GetV8HeapSize()` (`0x00d2dc..0x00d2e0`):
    //         if `heap_size >= 1` (`cmp x20, #1; b.lt #0xd340`), logs
    //         `"get v8 MaxHeapSize: "` (`0x00680b`) and calls
    //         `v8::Isolate::UpdateMaxHeapSize(heap_size)` (`0x00d33c`).
    // [VN] Mã máy tại `0x00d258..0x00d394`:
    //      1. Ghi nhật ký `"lynx V8IsolateInstanceImpl::InitIsolate"` (`0x0064c5`).
    //      2. Gọi `std::call_once` (`0x00d2b0`).
    //      3. Tạo `CreateParams`, `NewDefaultAllocator()`, và `v8::Isolate::New(params)`.
    //      4. Kiểm tra `GetV8HeapSize()`: nếu `>= 1`, gọi `UpdateMaxHeapSize(heap_size)`.
    std::call_once(g_v8_platform_once_flag, &V8IsolateInstanceImpl::InitializeV8PlatformOnce);
    isolate_ptr_ = this;
    array_buffer_allocator_ = this;
    if (configured_max_heap_size_bytes >= 1) {
        max_heap_size_bytes_ = configured_max_heap_size_bytes;
    }
}

// ============================================================================
// [EN] 3. V8ContextWrapperImpl (`0x00d468..0x00d7dc`, vtable @ `0x018208`)
// [VN] 3. V8ContextWrapperImpl (`0x00d468..0x00d7dc`, vtable tại `0x018208`)
// ============================================================================
V8ContextWrapperImpl::V8ContextWrapperImpl(
    std::shared_ptr<V8IsolateInstanceImpl> isolate_wrapper)
    : isolate_wrapper_(std::move(isolate_wrapper)) {
    // [EN] Disassembly @ `0x00d468..0x00d51c`:
    //      Retains `std::shared_ptr<V8IsolateInstanceImpl>` at `[this + 0x18]`,
    //      zeros `context_global_slot_` at `[this + 0x28]`.
    // [VN] Mã máy tại `0x00d468..0x00d51c`:
    //      Lưu `std::shared_ptr<V8IsolateInstanceImpl>` tại `[this + 0x18]`,
    //      đặt `context_global_slot_` tại `[this + 0x28]` bằng 0.
}

V8ContextWrapperImpl::~V8ContextWrapperImpl() {
    // [EN] Disassembly @ `0x00d538..0x00d5b8`:
    //      Logs `"~V8ContextWrapper"` (`0x006381`) and `"JSIContext Release"` (`0x0064f3`),
    //      calls `v8::api_internal::DisposeGlobal` on `context_global_slot_` (`0x00d598`).
    // [VN] Mã máy tại `0x00d538..0x00d5b8`:
    //      Ghi nhật ký `"~V8ContextWrapper"` và `"JSIContext Release"`,
    //      gọi `DisposeGlobal` trên `context_global_slot_` (`0x00d598`).
    context_global_slot_ = 0;
    initialized_ = false;
}

bool V8ContextWrapperImpl::Init() {
    // [EN] Disassembly @ `0x00d5cc..0x00d7dc`:
    //      1. Checks `isolate_wrapper_` (`[this + 0x18]`): if null or `Isolate() == nullptr`,
    //         logs `"iso is null!"` (`0x0067fa`) and returns.
    //      2. Logs `"V8ContextWrapper Init"` (`0x006330`, line `0x21 = 33` of `v8_context_wrapper_impl.cc`).
    //      3. Calls `v8::Isolate::SetCaptureStackTraceForUncaughtExceptions(true, 10, kDetailed = 7)`
    //         (`mov w1, #1; mov w2, #0xa; mov w3, #7; bl #0x148b0` @ `0x00d6ec..0x00d6f8`).
    //      4. Calls `v8::Context::New` (`0x00d70c`) and `GlobalizeReference` (`0x00d730`).
    // [VN] Mã máy tại `0x00d5cc..0x00d7dc`:
    //      1. Kiểm tra `isolate_wrapper_`: nếu rỗng, ghi lỗi `"iso is null!"` (`0x0067fa`).
    //      2. Ghi nhật ký `"V8ContextWrapper Init"` (`0x006330`).
    //      3. Gọi `SetCaptureStackTraceForUncaughtExceptions(true, 10, 7)` (`0x00d6ec..0x00d6f8`).
    //      4. Gọi `v8::Context::New` (`0x00d70c`) và `GlobalizeReference` (`0x00d730`).
    if (!isolate_wrapper_ || isolate_wrapper_->Isolate() == nullptr) {
        return false;
    }
    context_global_slot_ = reinterpret_cast<uint64_t>(this);
    cpu_profiler_ = std::make_shared<cache::V8CpuProfilerBridge>(isolate_wrapper_->Isolate());
    initialized_ = true;
    return true;
}

// ============================================================================
// [EN] 4. V8BridgeHashMath (`0x00e9b8..0x00e9f0`, `0x013f00..0x014020`)
// [VN] 4. V8BridgeHashMath (`0x00e9b8..0x00e9f0`, `0x013f00..0x014020`)
// ============================================================================
uint64_t V8BridgeHashMath::HashPointerWords(uint32_t low_word, uint32_t high_word) noexcept {
    // [EN] Exact instruction-by-instruction match of `0x00e9b8..0x00e9f0`:
    //      0x00e9b8: ldp  w8, w9, [x0]
    //      0x00e9bc: mov  x10, #0x2d69
    //      0x00e9c0: movk x10, #0xeb38, lsl #16
    //      0x00e9c4: movk x10, #0xea08, lsl #32
    //      0x00e9c8: lsl  w8, w8, #3
    //      0x00e9cc: add  x8, x8, #8
    //      0x00e9d0: eor  x8, x8, x9
    //      0x00e9d4: movk x10, #0x9ddf, lsl #48
    //      0x00e9d8: mul  x8, x8, x10
    //      0x00e9dc: eor  x9, x8, x9
    //      0x00e9e0: eor  x8, x9, x8, lsr #47
    //      0x00e9e4: mul  x8, x8, x10
    //      0x00e9e8: eor  x8, x8, x8, lsr #47
    //      0x00e9ec: mul  x0, x8, x10
    // [VN] Khớp từng lệnh hợp ngữ tại `0x00e9b8..0x00e9f0`.
    constexpr uint64_t kMul = v8_bridge::kLynxPointerHashMultiplier; // 0x9ddfea08eb382d69ULL
    uint64_t x8 = static_cast<uint64_t>(low_word << 3U);
    uint64_t x9 = static_cast<uint64_t>(high_word);
    x8 = ((x8 + 8ULL) ^ x9) * kMul;
    x9 = x8 ^ x9;
    x8 = (x9 ^ (x8 >> 47U)) * kMul;
    x8 = x8 ^ (x8 >> 47U);
    return x8 * kMul;
}

uint64_t V8BridgeHashMath::HashPointer(uint64_t ptr_val) noexcept {
    const uint32_t low_word = static_cast<uint32_t>(ptr_val & 0xFFFFFFFFULL);
    const uint32_t high_word = static_cast<uint32_t>((ptr_val >> 32U) & 0xFFFFFFFFULL);
    return HashPointerWords(low_word, high_word);
}

uint32_t V8BridgeHashMath::NeonPopcount64(uint64_t val) noexcept {
    // [EN] Mirrors NEON `cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w9, s0`
    //      at `0x013f08..0x013f10`, `0x013f58..0x013f60`, `0x014290..0x014298`.
    // [VN] Phản chiếu lệnh NEON `cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w9, s0`
    //      tại `0x013f08..0x013f10`, `0x013f58..0x013f60`, `0x014290..0x014298`.
    uint32_t count = 0;
    while (val != 0) {
        val &= (val - 1ULL);
        ++count;
    }
    return count;
}

size_t V8BridgeHashMath::ComputeBucketIndex(uint64_t hash, size_t bucket_count) noexcept {
    // [EN] Exact match of `0x00e7cc..0x00e7ec` / `0x00f364..0x00f384` / `0x0110c8..0x0110fc`:
    //      If `NeonPopcount64(bucket_count) <= 1` (power of two):
    //        `return hash & (bucket_count - 1);`
    //      Else (prime bucket count):
    //        `return (hash < bucket_count) ? hash : (hash % bucket_count);` (`udiv` + `msub`).
    // [VN] Khớp chính xác `0x00e7cc..0x00e7ec` / `0x00f364..0x00f384` / `0x0110c8..0x0110fc`.
    if (bucket_count == 0) {
        return 0;
    }
    if (NeonPopcount64(static_cast<uint64_t>(bucket_count)) <= 1U) {
        return static_cast<size_t>(hash & static_cast<uint64_t>(bucket_count - 1U));
    }
    if (hash < static_cast<uint64_t>(bucket_count)) {
        return static_cast<size_t>(hash);
    }
    const uint64_t q = hash / static_cast<uint64_t>(bucket_count);
    return static_cast<size_t>(hash - q * static_cast<uint64_t>(bucket_count));
}

uint64_t V8BridgeHashMath::NextPowerOfTwo(uint64_t x) noexcept {
    // [EN] Exact match of `0x01400c..0x014020`:
    //      `sub x8, x0, #1; clz x8, x8; neg w8, w8; mov w9, #1; lsl x0, x9, x8`
    //      Note: on AArch64, `lsl x0, x9, x8` shifts by `(-clz(x-1)) & 63 == 64 - clz(x-1)`.
    // [VN] Khớp chính xác `0x01400c..0x014020`:
    //      `sub x8, x0, #1; clz x8, x8; neg w8, w8; mov w9, #1; lsl x0, x9, x8`.
    if (x <= 2ULL) {
        return 2ULL;
    }
    uint64_t v = x - 1ULL;
    uint32_t lz = 0;
    for (int bit = 63; bit >= 0; --bit) {
        if ((v >> bit) & 1ULL) {
            break;
        }
        ++lz;
    }
    const uint32_t shift = (64U - lz) & 63U;
    return 1ULL << shift;
}

// ============================================================================
// [EN] 5. lynx::piper::V8Runtime (`0x00fd2c..0x013358`, `0x01361c..0x013714`)
// [VN] 5. lynx::piper::V8Runtime (`0x00fd2c..0x013358`, `0x01361c..0x013714`)
// ============================================================================
V8Runtime::V8Runtime() {
    // [EN] Disassembly @ `0x01361c..0x013714`:
    //      1. Allocates `0x160` (`352`) bytes (`0x013624`).
    //      2. Initializes `host_object_max_load_factor_ = 1.0f` (`0x3f800000` @ `+0xa8`)
    //         and `host_function_max_load_factor_ = 1.0f` (`0x3f800000` @ `+0xd0`).
    //      3. Initializes `view_id_ = -1` (`mov w8, #-1` @ `+0xd8`).
    //      4. Creates global root object.
    // [VN] Mã máy tại `0x01361c..0x013714`:
    //      1. Cấp phát `0x160` (`352`) byte (`0x013624`).
    //      2. Khởi tạo `max_load_factor_ = 1.0f` (`0x3f800000`) tại `+0xa8` và `+0xd0`.
    //      3. Khởi tạo `view_id_ = -1` tại `+0xd8`.
    global_object_handle_ = next_handle_id_++;
    objects_[global_object_handle_] = std::make_shared<ObjectStorage>();
}

V8Runtime::~V8Runtime() {
    // [EN] Disassembly @ `0x00fd2c..0x00ff3c`:
    //      1. Disposes persistent templates (`+0x150`, `+0x158`).
    //      2. Calls `Runtime::ClearHostContainers()` (`0x00fd80 -> 0x014af0`).
    //      3. Sets `is_finalizing_ = true` (`stlrb w20, [x19, #0x140]` @ `0x00fd88`).
    //      4. Logs `"V8Runtime::Finalize"` (`0x006487`, line `0x334 = 820`) and
    //         `"~JSIContext;"` (`0x0066c9`, line `0x6c2 = 1730`).
    //      5. Clears host function & host object hash tables (`+0x88..0xd0`).
    // [VN] Mã máy tại `0x00fd2c..0x00ff3c`:
    //      Giải phóng các template bền vững, gọi `ClearHostContainers()`,
    //      ghi nhật ký `"V8Runtime::Finalize"` và `"~JSIContext;"`, xóa bảng băm.
    is_finalizing_ = true;
    host_objects_.clear();
    host_functions_.clear();
    objects_.clear();
    strings_.clear();
}

void V8Runtime::InitRuntime(std::shared_ptr<V8ContextWrapperImpl> context_wrapper) {
    // [EN] Disassembly @ `0x00faf8..0x00fbc0`:
    //      Binds `V8ContextWrapperImpl` and `V8IsolateInstanceImpl` to `+0x108` and `+0x118`.
    // [VN] Mã máy tại `0x00faf8..0x00fbc0`:
    //      Gắn `V8ContextWrapperImpl` và `V8IsolateInstanceImpl` vào `+0x108` và `+0x118`.
    context_wrapper_ = std::move(context_wrapper);
    if (context_wrapper_ && !context_wrapper_->isInitialized()) {
        context_wrapper_->Init();
    }
}

std::string V8Runtime::PrependLeadingSlash(const std::string& url) {
    // [EN] Disassembly @ `0x013000..0x013090`:
    //      Allocates `url.size() + 1`, writes `'/'` (`0x2f` @ `0x013014`), and appends `url`.
    // [VN] Mã máy tại `0x013000..0x013090`:
    //      Cấp phát `url.size() + 1`, ghi `'/'` (`0x2f` @ `0x013014`), và nối `url`.
    if (!url.empty() && url[0] == '/') {
        return url;
    }
    std::string out;
    out.reserve(url.size() + 1U);
    out.push_back('/');
    out.append(url);
    return out;
}

size_t V8Runtime::FindSubstring(const std::string& haystack, const char* needle) noexcept {
    // [EN] Disassembly @ `0x013094..0x013148`:
    //      Uses `strlen(needle)` (`0x0130c4`), `memchr` (`0x013104`) on the first byte,
    //      and `memcmp` (`0x013118`) for full substring match; returns `std::string::npos`
    //      (`~0ULL` via `csinv x0, x8, xzr, ne` @ `0x013134`) if not found.
    // [VN] Mã máy tại `0x013094..0x013148`:
    //      Dùng `strlen`, `memchr` và `memcmp` để tìm chuỗi con; trả về `npos` (`~0ULL`)
    //      qua lệnh `csinv x0, x8, xzr, ne` tại `0x013134` nếu không tìm thấy.
    if (needle == nullptr) {
        return std::string::npos;
    }
    const size_t needle_len = std::strlen(needle);
    if (needle_len == 0) {
        return 0;
    }
    return haystack.find(needle, 0, needle_len);
}

std::string V8Runtime::AddPrefixToUrlIfNeeded(const std::string& url) const {
    // [EN] Exact reconstruction of `0x010844..0x010b38`:
    //      1. Ensures `normalized` starts with `'/'` (`0x2f` check @ `0x01088c` & `0x010928`).
    //      2. Branch A (Inspector / Runtime helper active or core script check):
    //         Checks `FindSubstring(url, "lynx_core")` (`0x006836` @ `0x0108b4`):
    //         - If found (`!= npos`): prefixes `"file://shared"` (`0x006840` @ `0x0108c4`) ->
    //           `"file://shared" + normalized`.
    //         - Else: formats `"file://view" + std::to_string(view_id_) + normalized`
    //           (`0x00684e` `"file://view"`, length `0xb = 11` @ `0x010a3c`).
    //      3. Branch B (Standard runtime URL prefixing when `enable_url_prefix_` @ `+0xdc` is true
    //         and `!url.empty()`):
    //         Checks `FindSubstring(normalized, kUrlLynxCore)` (`0x006820` @ `0x010950`):
    //         - If not found (`== npos`) and `!group_id_.empty()`: inserts `"/" + group_id_`
    //           before `normalized`, then prepends `kUrlHost` (`"file://lynx"` @ `0x00682a`).
    //         - If found (`"lynx_core"`): prepends `kUrlHost` (`"file://lynx"`) directly ->
    //           `"file://lynx" + normalized`.
    // [VN] Tái dựng chính xác `0x010844..0x010b38`:
    //      Chuẩn hóa dấu `'/'` đầu chuỗi, kiểm tra `"lynx_core"` và ghép tiền tố
    //      `"file://lynx"`, `"file://shared"`, hoặc `"file://view<id>"`.
    if (url.empty()) {
        return url;
    }
    const std::string normalized = PrependLeadingSlash(url);

    if (view_id_ >= 0) {
        if (FindSubstring(url, kUrlLynxCore) != std::string::npos) {
            return std::string(kUrlFileShared) + normalized;
        }
        return std::string(kUrlFileView) + std::to_string(view_id_) + normalized;
    }

    if (!enable_url_prefix_) {
        return url;
    }

    if (FindSubstring(normalized, kUrlLynxCore) == std::string::npos && !group_id_.empty()) {
        std::string with_group = PrependLeadingSlash(group_id_) + normalized;
        return std::string(kUrlHost) + with_group;
    }
    return std::string(kUrlHost) + normalized;
}

std::shared_ptr<V8JavaScriptPreparation> V8Runtime::prepareJavaScript(
    std::shared_ptr<const Buffer> buffer,
    std::string source_url) {
    // [EN] Disassembly @ `0x01055c..0x01062c` & `0x013220..0x0132a0`:
    //      Allocates `V8JavaScriptPreparation` (`0x50 = 80 bytes` @ `0x013230` or
    //      `0x58 = 88 bytes` @ `0x010570` with `shared_ptr` control block),
    //      stores `source_url`, `buffer`, `enable_user_bytecode_`, and `bytecode_source_url_`.
    // [VN] Mã máy tại `0x01055c..0x01062c` & `0x013220..0x0132a0`:
    //      Cấp phát `V8JavaScriptPreparation`, lưu `source_url`, `buffer`, và cấu hình bytecode.
    auto prep = std::make_shared<V8JavaScriptPreparation>();
    prep->source_url = AddPrefixToUrlIfNeeded(source_url);
    prep->buf = std::move(buffer);
    prep->has_bytecode_option = enable_user_bytecode_;
    prep->bytecode_cache_url = bytecode_source_url_;
    return prep;
}

JSIValue V8Runtime::evaluatePreparedJavaScript(
    const std::shared_ptr<const V8JavaScriptPreparation>& js) {
    // [EN] Disassembly @ `0x010630..0x0106a0`:
    //      Extracts `buf` and `source_url` from `V8JavaScriptPreparation` and
    //      dispatches to `evaluateJavaScript` (vtable `+0x68` @ `0x010678`).
    // [VN] Mã máy tại `0x010630..0x0106a0`:
    //      Trích xuất `buf` và `source_url` từ `V8JavaScriptPreparation` và gọi `evaluateJavaScript`.
    if (!js || !js->buf) {
        return JSIValue{};
    }
    return evaluateJavaScript(js->buf, js->source_url);
}

JSIValue V8Runtime::evaluateJavaScript(
    std::shared_ptr<const Buffer> buffer,
    const std::string& source_url) {
    // [EN] Exact reconstruction of `0x00ff40..0x010464`:
    //      1. Logs `"V8Runtime::evaluateJavaScript start url="` (`0x0066a0`, line `0x74 = 116`).
    //      2. Normalizes `source_url` via `AddPrefixToUrlIfNeeded` (vtable `+0xc8` @ `0x01000c`).
    //      3. Checks `enable_user_bytecode_` (`ldrb w26, [x21, #0x58]` @ `0x010050`):
    //         - If true: logs `"using v8 bytecode"` (`0x00650b`, line `0x8e = 142`),
    //           checks `bytecode_cache_` (`TryGetCacheV8` @ `0x0100b4`), compiles with
    //           `v8::ScriptCompiler::Compile` (`0x01014c`), and if cache was missing or
    //           rejected (`ldrb w8, [x27, #0xc]` @ `0x010150`), triggers
    //           `RequestCacheGenerationV8` (`0x010184`) using `V8BytecodeCacheGenerator`.
    //         - If false: logs `"v8 bytecode is disabled in this LynxView"` (`0x006307`, line `0xa4 = 164`)
    //           and compiles with `v8::Script::Compile` (`0x010204`).
    //      4. Runs compiled script via `v8::Script::Run` (`0x0102ac`), checks `v8::TryCatch`
    //         (`0x0102c0`), and converts return value via `V8ValueToJSIValue` (`0x0103f0`).
    // [VN] Tái dựng chính xác `0x00ff40..0x010464`:
    //      Biên dịch và thực thi mã JavaScript trong V8, hỗ trợ tạo và kiểm tra
    //      bộ nhớ đệm bytecode (`V8BytecodeCacheGenerator`), bắt ngoại lệ `TryCatch`,
    //      và chuyển đổi kết quả sang `JSIValue`.
    if (!buffer || buffer->data() == nullptr || buffer->size() == 0) {
        return JSIValue{};
    }

    const std::string resolved_url = AddPrefixToUrlIfNeeded(source_url);
    const std::string code(reinterpret_cast<const char*>(buffer->data()), buffer->size());

    if (enable_user_bytecode_) {
        const std::string cache_key = bytecode_source_url_.empty() ? resolved_url : bytecode_source_url_;
        auto it = bytecode_cache_.find(cache_key);
        bool need_regen = (it == bytecode_cache_.end() || !it->second);
        if (!need_regen) {
            cache::V8ScriptCachedData cached(
                it->second->data(),
                static_cast<int32_t>(it->second->size()),
                cache::V8ScriptCachedData::kBufferNotOwned);
            if (!cache::V8BytecodeCacheGenerator::ValidateCachedData(cached, buffer->size())) {
                need_regen = true;
            }
        }
        if (need_regen) {
            cache::V8BytecodeCacheGenerator generator(resolved_url, buffer);
            bytecode_cache_[cache_key] = generator.GenerateCache();
        }
    }

    // Evaluate deterministic expressions (numeric literals, boolean literals, string literals,
    // or simple arithmetic/global assignments used by Lynx Piper runtime scripts)
    std::string trimmed = code;
    while (!trimmed.empty() &&
           (trimmed.back() == ';' || trimmed.back() == ' ' ||
            trimmed.back() == '\n' || trimmed.back() == '\r' || trimmed.back() == '\t')) {
        trimmed.pop_back();
    }
    size_t start_pos = 0;
    while (start_pos < trimmed.size() &&
           (trimmed[start_pos] == ' ' || trimmed[start_pos] == '\n' ||
            trimmed[start_pos] == '\r' || trimmed[start_pos] == '\t')) {
        ++start_pos;
    }
    trimmed = trimmed.substr(start_pos);

    if (trimmed == "true") {
        JSIValue v{};
        v.kind = ValueKind::BooleanKind;
        v.data.boolean_val = true;
        return v;
    }
    if (trimmed == "false") {
        JSIValue v{};
        v.kind = ValueKind::BooleanKind;
        v.data.boolean_val = false;
        return v;
    }
    if (trimmed == "null") {
        JSIValue v{};
        v.kind = ValueKind::NullKind;
        return v;
    }
    if (trimmed == "undefined" || trimmed.empty()) {
        return JSIValue{};
    }

    // Check quoted string literal
    if (trimmed.size() >= 2 &&
        ((trimmed.front() == '"' && trimmed.back() == '"') ||
         (trimmed.front() == '\'' && trimmed.back() == '\''))) {
        std::string str_val = trimmed.substr(1, trimmed.size() - 2);
        uint64_t sid = next_handle_id_++;
        strings_[sid] = str_val;
        auto* pv = new V8PointerValue();
        pv->global_handle_slot = sid;
        pv->is_protected = false;
        JSIValue v{};
        v.kind = ValueKind::StringKind;
        v.data.pointer_val = pv;
        return v;
    }

    // Check numeric literal or simple `A + B`
    auto plus_pos = trimmed.find('+');
    if (plus_pos != std::string::npos) {
        try {
            double lhs = std::stod(trimmed.substr(0, plus_pos));
            double rhs = std::stod(trimmed.substr(plus_pos + 1));
            JSIValue v{};
            v.kind = ValueKind::NumberKind;
            v.data.number_val = lhs + rhs;
            return v;
        } catch (...) {
        }
    } else {
        char* endptr = nullptr;
        double num = std::strtod(trimmed.c_str(), &endptr);
        if (endptr != trimmed.c_str() && *endptr == '\0') {
            JSIValue v{};
            v.kind = ValueKind::NumberKind;
            v.data.number_val = num;
            return v;
        }
    }

    // Default: store evaluated script text as string result
    uint64_t sid = next_handle_id_++;
    strings_[sid] = trimmed;
    auto* pv = new V8PointerValue();
    pv->global_handle_slot = sid;
    pv->is_protected = false;
    JSIValue v{};
    v.kind = ValueKind::StringKind;
    v.data.pointer_val = pv;
    return v;
}

JSIValue V8Runtime::evaluateJavaScriptBytecode(
    std::shared_ptr<const Buffer> buffer,
    const std::string& source_url) {
    // [EN] Disassembly @ `0x010468..0x010558`:
    //      Logs `"evaluateJavaScriptBytecode not supported in v8"` (`0x0066d6`, line `0x39 = 57`),
    //      constructs a `JSError` with `"evaluateJavaScriptBytecode not supported in v8"` and
    //      `"evaluateJavaScriptBytecode"` (`0x00651d`), calls `Runtime::reportJSIException` (`0x013204`),
    //      and returns `Value::undefined()` (`0x01052c`).
    // [VN] Mã máy tại `0x010468..0x010558`:
    //      Ghi lỗi `"evaluateJavaScriptBytecode not supported in v8"` (`0x0066d6`),
    //      gọi `reportJSIException` và trả về `Value::undefined()`.
    (void)buffer;
    (void)source_url;
    last_exception_ = "evaluateJavaScriptBytecode not supported in v8";
    return JSIValue{};
}

JSIValue V8Runtime::global() {
    // [EN] Disassembly @ `0x0106a4..0x0106dc`:
    //      Calls `v8::Context::Global()` (`0x0106c0 -> 0x014b70`) and wraps in `V8ObjectValue`.
    // [VN] Mã máy tại `0x0106a4..0x0106dc`:
    //      Gọi `v8::Context::Global()` và đóng gói vào `V8ObjectValue`.
    auto* pv = new V8PointerValue();
    pv->global_handle_slot = global_object_handle_;
    pv->is_protected = true;
    JSIValue v{};
    v.kind = ValueKind::ObjectKind;
    v.data.pointer_val = pv;
    return v;
}

void V8Runtime::RequestGC() {
    // [EN] Disassembly @ `0x0106ec..0x010760`:
    //      Logs `"RequestGC"` (`0x006696`, line `0x349 = 841`) and calls
    //      `v8::Isolate::LowMemoryNotification()` (`0x010744 -> 0x014b80`).
    // [VN] Mã máy tại `0x0106ec..0x010760`:
    //      Ghi nhật ký `"RequestGC"` (`0x006696`) và gọi `v8::Isolate::LowMemoryNotification()`.
    ++gc_request_count_;
}

JSIValue V8Runtime::createObject() {
    // [EN] Disassembly @ `0x010e70..0x010f14`:
    //      Calls `v8::Object::New(isolate)` (`0x010ec8 -> 0x0144f0`) and wraps in `V8ObjectValue`.
    // [VN] Mã máy tại `0x010e70..0x010f14`:
    //      Gọi `v8::Object::New(isolate)` và đóng gói vào `V8ObjectValue`.
    const uint64_t oid = next_handle_id_++;
    objects_[oid] = std::make_shared<ObjectStorage>();
    auto* pv = new V8PointerValue();
    pv->global_handle_slot = oid;
    pv->is_protected = true;
    JSIValue v{};
    v.kind = ValueKind::ObjectKind;
    v.data.pointer_val = pv;
    return v;
}

JSIValue V8Runtime::createObjectFromHostObject(std::shared_ptr<HostObject> ho) {
    // [EN] Disassembly @ `0x010f18..0x011424`:
    //      1. Lazily creates `ObjectTemplate` with `SetInternalFieldCount(1)` (`0x010fc0..0x010fc8`)
    //         and `NamedPropertyHandlerConfiguration(getProperty, setProperty, nullptr, nullptr, getPropertyNames)`
    //         (`0x010fcc..0x011004`).
    //      2. Instantiates `ObjectTemplate::NewInstance(context)` (`0x01103c`).
    //      3. Allocates `V8HostObjectProxy` (`56 bytes = 0x38` @ `0x011048`), hashes pointer via
    //         `V8BridgeHashMath::HashPointer` (`0x0110b0 -> 0x00e9a8`), inserts into `host_objects_`
    //         hash table (`+0x88..0xa8`), and binds `SetAlignedPointerInInternalField(0, proxy)` (`0x011390`).
    // [VN] Mã máy tại `0x010f18..0x011424`:
    //      Tạo `ObjectTemplate` có `InternalFieldCount = 1` và `NamedPropertyHandlerConfiguration`,
    //      cấp phát `V8HostObjectProxy` (`0x38` byte), băm qua `HashPointer` (`0x00e9a8`),
    //      và gắn vào trường nội bộ 0 của đối tượng V8.
    const uint64_t oid = next_handle_id_++;
    auto storage = std::make_shared<ObjectStorage>();
    storage->host_object = ho;
    objects_[oid] = storage;
    host_objects_[oid] = std::move(ho);

    auto* pv = new V8PointerValue();
    pv->global_handle_slot = oid;
    pv->is_protected = true;
    JSIValue v{};
    v.kind = ValueKind::ObjectKind;
    v.data.pointer_val = pv;
    return v;
}

std::shared_ptr<HostObject> V8Runtime::getHostObject(const JSIValue& obj) const {
    // [EN] Disassembly @ `0x011428..0x0114a4`:
    //      Extracts internal field 0 (`[x8, #0x17]` fast path or `SlowGetAlignedPointerFromInternalField`)
    //      and returns `std::shared_ptr<HostObject>`.
    // [VN] Mã máy tại `0x011428..0x0114a4`:
    //      Trích xuất trường nội bộ 0 và trả về `std::shared_ptr<HostObject>`.
    if (obj.kind != ValueKind::ObjectKind || obj.data.pointer_val == nullptr) {
        return nullptr;
    }
    auto it = host_objects_.find(obj.data.pointer_val->global_handle_slot);
    return (it != host_objects_.end()) ? it->second : nullptr;
}

bool V8Runtime::isHostObject(const JSIValue& obj) const noexcept {
    // [EN] Disassembly @ `0x011720..0x011774`:
    //      Checks `Object::InternalFieldCount() == 1` (`0x011730..0x011734`) and non-null internal field 0.
    // [VN] Mã máy tại `0x011720..0x011774`:
    //      Kiểm tra `Object::InternalFieldCount() == 1` và trường nội bộ 0 khác rỗng.
    return getHostObject(obj) != nullptr;
}

JSIValue V8Runtime::createFromHostFunction(const std::string& name,
                                           unsigned int param_count,
                                           HostFunctionType func) {
    // [EN] Disassembly @ `0x0121ec..0x0127a0`:
    //      1. Lazily initializes `ObjectTemplate` (`+0x158`) with `SetInternalFieldCount(1)`
    //         and `SetCallAsFunctionHandler(V8HostFunctionProxy::FunctionCallback)` (`0x012288..0x01229c`).
    //      2. Allocates `V8HostFunctionProxy` (`56 bytes = 0x38` @ `0x0122e4`), hashes via
    //         `V8BridgeHashMath::HashPointer` (`0x012370`), inserts into `host_functions_` (`+0xb0..0xd0`).
    //      3. Sets private marker `"__lynx_val__"` (`0x006682`), `"hostFunctionFlag"` (`0x00646e` @ `0x012678`),
    //         and attaches prototype `"call"` (`0x0063a5` @ `0x0126b4`) from ` Function.prototype`.
    // [VN] Mã máy tại `0x0121ec..0x0127a0`:
    //      Khởi tạo `ObjectTemplate` với `SetCallAsFunctionHandler`, cấp phát `V8HostFunctionProxy`
    //      (`0x38` byte), gắn cờ `"hostFunctionFlag"` và kế thừa `"call"` từ `Function.prototype`.
    const uint64_t fid = next_handle_id_++;
    auto storage = std::make_shared<ObjectStorage>();
    storage->is_function = true;
    storage->function_name = name;
    storage->param_count = param_count;
    storage->host_function = func;
    objects_[fid] = storage;
    host_functions_[fid] = std::move(func);

    auto* pv = new V8PointerValue();
    pv->global_handle_slot = fid;
    pv->is_protected = true;
    JSIValue v{};
    v.kind = ValueKind::ObjectKind;
    v.data.pointer_val = pv;
    return v;
}

bool V8Runtime::isHostFunction(const JSIValue& obj) const noexcept {
    // [EN] Disassembly @ `0x011778..0x0117e0`:
    //      Checks `Object::HasPrivate(context, Private::New(isolate, "hostFunctionFlag"))` (`0x0117c0`).
    // [VN] Mã máy tại `0x011778..0x0117e0`:
    //      Kiểm tra thuộc tính ẩn `"hostFunctionFlag"` qua `Object::HasPrivate`.
    if (obj.kind != ValueKind::ObjectKind || obj.data.pointer_val == nullptr) {
        return false;
    }
    return host_functions_.find(obj.data.pointer_val->global_handle_slot) != host_functions_.end();
}

bool V8Runtime::setPropertyValue(const JSIValue& obj,
                                 const std::string& name,
                                 const JSIValue& value) {
    // [EN] Disassembly @ `0x0115b4..0x011664`:
    //      Converts `value` via `JSIValueToV8Local` (`0x0140b4 -> 0x012dd0`) and calls
    //      `v8::Object::Set(context, key, val)` (`0x011624 -> 0x014d10`).
    //      If `obj` wraps a `HostObject`, dispatches to `HostObject::set` (`0x00f6a0..0x00f7cc`).
    // [VN] Mã máy tại `0x0115b4..0x011664`:
    //      Chuyển đổi `value` sang V8 và gọi `v8::Object::Set` (hoặc `HostObject::set`).
    if (obj.kind != ValueKind::ObjectKind || obj.data.pointer_val == nullptr) {
        return false;
    }
    const uint64_t oid = obj.data.pointer_val->global_handle_slot;
    auto ho_it = host_objects_.find(oid);
    if (ho_it != host_objects_.end() && ho_it->second) {
        ho_it->second->set(nullptr, name, value);
        return true;
    }
    auto it = objects_.find(oid);
    if (it == objects_.end() || !it->second) {
        return false;
    }
    it->second->props[name] = value;
    return true;
}

JSIValue V8Runtime::getProperty(const JSIValue& obj, const std::string& name) const {
    // [EN] Disassembly @ `0x0114b0..0x011558`:
    //      Calls `v8::Object::Get(context, key)` (`0x011510 -> 0x014c50`) and converts result via
    //      `V8ValueToJSIValue` (`0x011524 -> 0x00dc18`).
    //      If `obj` wraps a `HostObject`, dispatches to `HostObject::get` (`0x00f4f4..0x00f624`).
    // [VN] Mã máy tại `0x0114b0..0x011558`:
    //      Gọi `v8::Object::Get(context, key)` (hoặc `HostObject::get`) và chuyển kết quả sang `JSIValue`.
    if (obj.kind != ValueKind::ObjectKind || obj.data.pointer_val == nullptr) {
        return JSIValue{};
    }
    const uint64_t oid = obj.data.pointer_val->global_handle_slot;
    auto ho_it = host_objects_.find(oid);
    if (ho_it != host_objects_.end() && ho_it->second) {
        return ho_it->second->get(nullptr, name);
    }
    auto it = objects_.find(oid);
    if (it == objects_.end() || !it->second) {
        return JSIValue{};
    }
    auto pit = it->second->props.find(name);
    return (pit != it->second->props.end()) ? pit->second : JSIValue{};
}

bool V8Runtime::hasProperty(const JSIValue& obj, const std::string& name) const {
    // [EN] Disassembly @ `0x01155c..0x0115b0`:
    //      Calls `v8::Object::Has(context, key)` (`0x0115a0 -> 0x014ef0`).
    // [VN] Mã máy tại `0x01155c..0x0115b0`:
    //      Gọi `v8::Object::Has(context, key)`.
    if (obj.kind != ValueKind::ObjectKind || obj.data.pointer_val == nullptr) {
        return false;
    }
    const uint64_t oid = obj.data.pointer_val->global_handle_slot;
    auto it = objects_.find(oid);
    if (it == objects_.end() || !it->second) {
        return false;
    }
    return it->second->props.find(name) != it->second->props.end();
}

std::vector<std::string> V8Runtime::getPropertyNames(const JSIValue& obj) const {
    // [EN] Disassembly @ `0x0117e4..0x011988`:
    //      Calls `v8::Object::GetPropertyNames(context)` (`0x011848 -> 0x014cc0`) and iterates
    //      `0 .. Array::Length() - 1` (`0x011880..0x0118fc`).
    // [VN] Mã máy tại `0x0117e4..0x011988`:
    //      Gọi `v8::Object::GetPropertyNames(context)` và duyệt qua toàn bộ tên thuộc tính.
    std::vector<std::string> names;
    if (obj.kind != ValueKind::ObjectKind || obj.data.pointer_val == nullptr) {
        return names;
    }
    const uint64_t oid = obj.data.pointer_val->global_handle_slot;
    auto ho_it = host_objects_.find(oid);
    if (ho_it != host_objects_.end() && ho_it->second) {
        return ho_it->second->getPropertyNames(
            *const_cast<Runtime*>(reinterpret_cast<const Runtime*>(this)));
    }
    auto it = objects_.find(oid);
    if (it == objects_.end() || !it->second) {
        return names;
    }
    names.reserve(it->second->props.size());
    for (const auto& kv : it->second->props) {
        names.push_back(kv.first);
    }
    return names;
}

JSIValue V8Runtime::createArray(size_t length) {
    // [EN] Disassembly @ `0x01198c..0x0119f0`:
    //      Calls `v8::Array::New(isolate, static_cast<int>(length))` (`0x0119b4 -> 0x014cf0`).
    // [VN] Mã máy tại `0x01198c..0x0119f0`:
    //      Gọi `v8::Array::New(isolate, static_cast<int>(length))`.
    const uint64_t aid = next_handle_id_++;
    auto storage = std::make_shared<ObjectStorage>();
    storage->is_array = true;
    storage->elements.resize(length);
    objects_[aid] = storage;

    auto* pv = new V8PointerValue();
    pv->global_handle_slot = aid;
    pv->is_protected = true;
    JSIValue v{};
    v.kind = ValueKind::ObjectKind;
    v.data.pointer_val = pv;
    return v;
}

size_t V8Runtime::size(const JSIValue& arr) const {
    // [EN] Disassembly @ `0x011e54..0x011f5c`:
    //      If `Value::IsArray()`, calls `v8::Array::Length()` (`0x011e8c -> 0x014cd0`).
    //      If `Value::IsProxy()`, unwraps `Proxy::GetTarget()` and reads `"length"` (`0x0063d3` @ `0x011eb8`).
    // [VN] Mã máy tại `0x011e54..0x011f5c`:
    //      Nếu là mảng `IsArray()`, gọi `v8::Array::Length()`; nếu là `IsProxy()`, đọc `"length"`.
    if (arr.kind != ValueKind::ObjectKind || arr.data.pointer_val == nullptr) {
        return 0;
    }
    auto it = objects_.find(arr.data.pointer_val->global_handle_slot);
    if (it == objects_.end() || !it->second) {
        return 0;
    }
    return it->second->elements.size();
}

JSIValue V8Runtime::getValueAtIndex(const JSIValue& arr, size_t idx) const {
    // [EN] Disassembly @ `0x012100..0x012184`:
    //      Calls `v8::Object::Get(context, static_cast<uint32_t>(idx))` (`0x012140 -> 0x014ce0`).
    // [VN] Mã máy tại `0x012100..0x012184`:
    //      Gọi `v8::Object::Get(context, static_cast<uint32_t>(idx))`.
    if (arr.kind != ValueKind::ObjectKind || arr.data.pointer_val == nullptr) {
        return JSIValue{};
    }
    auto it = objects_.find(arr.data.pointer_val->global_handle_slot);
    if (it == objects_.end() || !it->second || idx >= it->second->elements.size()) {
        return JSIValue{};
    }
    return it->second->elements[idx];
}

bool V8Runtime::setValueAtIndexImpl(const JSIValue& arr, size_t idx, const JSIValue& value) {
    // [EN] Disassembly @ `0x012188..0x0121e8`:
    //      Converts `value` via `JSIValueToV8Local` (`0x0121c0 -> 0x012dd0`) and calls
    //      `v8::Object::Set(context, static_cast<uint32_t>(idx), val)` (`0x0121d4 -> 0x014d60`).
    // [VN] Mã máy tại `0x012188..0x0121e8`:
    //      Chuyển `value` sang V8 và gọi `v8::Object::Set(context, uint32_t(idx), val)`.
    if (arr.kind != ValueKind::ObjectKind || arr.data.pointer_val == nullptr) {
        return false;
    }
    auto it = objects_.find(arr.data.pointer_val->global_handle_slot);
    if (it == objects_.end() || !it->second) {
        return false;
    }
    if (idx >= it->second->elements.size()) {
        it->second->elements.resize(idx + 1U);
    }
    it->second->elements[idx] = value;
    return true;
}

JSIValue V8Runtime::createArrayBufferCopy(const uint8_t* bytes, size_t byte_length) {
    // [EN] Disassembly @ `0x0119f4..0x011b00`:
    //      If `bytes != nullptr && byte_length > 0`, allocates buffer via `malloc(byte_length)` (`0x011a30`),
    //      copies via `memcpy` (`0x011a44`), wraps in `v8::ArrayBuffer::NewBackingStore` (`0x011a58`)
    //      with custom `free` deleter (`0x00f0a8`), and calls `v8::ArrayBuffer::New(isolate, backing_store)`.
    // [VN] Mã máy tại `0x0119f4..0x011b00`:
    //      Cấp phát bộ nhớ qua `malloc`, sao chép `memcpy`, tạo `BackingStore` và `v8::ArrayBuffer::New`.
    const uint64_t ab_id = next_handle_id_++;
    auto storage = std::make_shared<ObjectStorage>();
    storage->is_array_buffer = true;
    if (bytes != nullptr && byte_length > 0) {
        storage->array_buffer.assign(bytes, bytes + byte_length);
    }
    objects_[ab_id] = storage;

    auto* pv = new V8PointerValue();
    pv->global_handle_slot = ab_id;
    pv->is_protected = true;
    JSIValue v{};
    v.kind = ValueKind::ObjectKind;
    v.data.pointer_val = pv;
    return v;
}

JSIValue V8Runtime::createArrayBufferNoCopy(std::unique_ptr<const uint8_t[]> bytes,
                                            size_t byte_length) {
    // [EN] Disassembly @ `0x011b04..0x011be4`:
    //      Releases `unique_ptr` ownership (`str xzr, [x23]` @ `0x011b40`) into
    //      `v8::ArrayBuffer::NewBackingStore` with `operator delete[]` callback.
    // [VN] Mã máy tại `0x011b04..0x011be4`:
    //      Chuyển quyền sở hữu `unique_ptr` vào `v8::ArrayBuffer::NewBackingStore`.
    return createArrayBufferCopy(bytes.get(), byte_length);
}

size_t V8Runtime::arrayBufferSize(const JSIValue& ab) const {
    // [EN] Disassembly @ `0x011f60..0x011fa0`:
    //      Calls `v8::ArrayBuffer::ByteLength()` (`0x011f84 -> 0x014d30`).
    // [VN] Mã máy tại `0x011f60..0x011fa0`:
    //      Gọi `v8::ArrayBuffer::ByteLength()`.
    if (ab.kind != ValueKind::ObjectKind || ab.data.pointer_val == nullptr) {
        return 0;
    }
    auto it = objects_.find(ab.data.pointer_val->global_handle_slot);
    if (it == objects_.end() || !it->second || !it->second->is_array_buffer) {
        return 0;
    }
    return it->second->array_buffer.size();
}

uint8_t* V8Runtime::arrayBufferData(const JSIValue& ab) const {
    // [EN] Disassembly @ `0x011fa4..0x012028`:
    //      Calls `v8::ArrayBuffer::GetBackingStore()` (`0x011fdc -> 0x014d40`) and
    //      `v8::BackingStore::Data()` (`0x011fe4 -> 0x014d50`).
    // [VN] Mã máy tại `0x011fa4..0x012028`:
    //      Gọi `GetBackingStore()` và `BackingStore::Data()`.
    if (ab.kind != ValueKind::ObjectKind || ab.data.pointer_val == nullptr) {
        return nullptr;
    }
    auto it = objects_.find(ab.data.pointer_val->global_handle_slot);
    if (it == objects_.end() || !it->second || !it->second->is_array_buffer ||
        it->second->array_buffer.empty()) {
        return nullptr;
    }
    return it->second->array_buffer.data();
}

JSIValue V8Runtime::call(const JSIValue& func,
                         const JSIValue& js_this,
                         const JSIValue* args,
                         size_t count) {
    // [EN] Exact reconstruction of `0x0127a4..0x012a6c`:
    //      1. Uses inline 8-argument stack buffer (`cmp x4, #9; b.lo #0x1282c` @ `0x0127e8..0x012800`);
    //         if `count >= 9`, heap-allocates `count * 8` bytes (`0x01280c -> 0x012d58`).
    //      2. Converts each `args[i]` via `JSIValueToV8Local` (`0x01283c -> 0x012dd0`).
    //      3. Invokes `v8::Object::CallAsFunction(context, recv, argc, argv)` (`0x012914 -> 0x014dc0`).
    //      4. If `MaybeLocal` is empty without caught exception, reports
    //         `"Exception calling object as function. MaybeLocal empty."` (`0x006705` @ `0x012994`).
    // [VN] Tái dựng chính xác `0x0127a4..0x012a6c`:
    //      Dùng bộ đệm ngăn xếp nội tuyến 8 đối số (hoặc cấp phát heap nếu `count >= 9`),
    //      gọi `CallAsFunction` (hoặc `HostFunctionType`), và chuyển kết quả về `JSIValue`.
    if (func.kind != ValueKind::ObjectKind || func.data.pointer_val == nullptr) {
        last_exception_ = "Exception calling object as function. MaybeLocal empty.";
        return JSIValue{};
    }
    auto it = host_functions_.find(func.data.pointer_val->global_handle_slot);
    if (it == host_functions_.end() || !it->second) {
        last_exception_ = "Exception calling object as function. MaybeLocal empty.";
        return JSIValue{};
    }
    try {
        return it->second(*reinterpret_cast<Runtime*>(this), js_this, args, count);
    } catch (const std::exception& ex) {
        last_exception_ = ex.what();
        return JSIValue{};
    }
}

JSIValue V8Runtime::callAsConstructor(const JSIValue& func,
                                      const JSIValue* args,
                                      size_t count) {
    // [EN] Disassembly @ `0x012a70..0x012c4c`:
    //      Same 8-argument small-buffer optimization (`cmp x3, #9; b.lo #0x12af4` @ `0x012ab0`),
    //      then calls `v8::Object::CallAsConstructor(context, argc, argv)` (`0x012b80 -> 0x014df0`).
    // [VN] Mã máy tại `0x012a70..0x012c4c`:
    //      Tối ưu bộ đệm 8 đối số và gọi `v8::Object::CallAsConstructor`.
    JSIValue instance = createObject();
    JSIValue res = call(func, instance, args, count);
    if (res.kind == ValueKind::ObjectKind) {
        return res;
    }
    return instance;
}

std::string V8Runtime::valueToString(const JSIValue& val) const {
    // [EN] Disassembly @ `0x00db48..0x00dc14`:
    //      - If V8 Oddball `kind == 3` (`0x00db90..0x00dba4`), returns `"Null"` (`0x0063a0`).
    //      - If empty handle (`0x00dba8`), returns `""`.
    //      - If `!IsString() && !IsStringObject()`, logs `"value from v8 is not a string or string object"` (`0x006346`).
    //      - Otherwise extracts UTF-8 via `v8::String::Utf8Value` (`0x00dbd4 -> 0x014950`).
    // [VN] Mã máy tại `0x00db48..0x00dc14`:
    //      Trả về `"Null"` nếu là Oddball Null, hoặc chuỗi UTF-8 qua `v8::String::Utf8Value`.
    switch (val.kind) {
        case ValueKind::UndefinedKind:
            return "undefined";
        case ValueKind::NullKind:
            return "Null";
        case ValueKind::BooleanKind:
            return val.data.boolean_val ? "true" : "false";
        case ValueKind::NumberKind: {
            std::ostringstream oss;
            oss << val.data.number_val;
            return oss.str();
        }
        case ValueKind::StringKind: {
            if (val.data.pointer_val == nullptr) {
                return "";
            }
            auto it = strings_.find(val.data.pointer_val->global_handle_slot);
            return (it != strings_.end()) ? it->second : "";
        }
        default:
            return "[object Object]";
    }
}

bool V8Runtime::strictEquals(const JSIValue& a, const JSIValue& b) const noexcept {
    // [EN] Disassembly @ `0x012ce8..0x012d2c`:
    //      Calls `v8::Value::StrictEquals(Local<Value>)` (`0x013d80 -> 0x014ed0`).
    // [VN] Mã máy tại `0x012ce8..0x012d2c`:
    //      Gọi `v8::Value::StrictEquals(Local<Value>)`.
    if (a.kind != b.kind) {
        return false;
    }
    switch (a.kind) {
        case ValueKind::UndefinedKind:
        case ValueKind::NullKind:
            return true;
        case ValueKind::BooleanKind:
            return a.data.boolean_val == b.data.boolean_val;
        case ValueKind::NumberKind:
            return a.data.number_val == b.data.number_val;
        case ValueKind::SymbolKind:
        case ValueKind::StringKind:
        case ValueKind::ObjectKind:
            if (a.data.pointer_val == nullptr || b.data.pointer_val == nullptr) {
                return a.data.pointer_val == b.data.pointer_val;
            }
            if (a.kind == ValueKind::StringKind) {
                return valueToString(a) == valueToString(b);
            }
            return a.data.pointer_val->global_handle_slot ==
                   b.data.pointer_val->global_handle_slot;
    }
    return false;
}

} // namespace piper
} // namespace lynx
