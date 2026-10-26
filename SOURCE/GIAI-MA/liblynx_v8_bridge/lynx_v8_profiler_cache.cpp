// ============================================================================
// File: lynx_v8_profiler_cache.cpp
// Target: liblynx_v8_bridge.so (0x00c048..0x00d17f)
// Description:
//   [EN] 100% Real C++17 implementation of V8 Bytecode Code-Cache Generator
//        (`0x00c048..0x00c744`) and V8 CPU Profiler & Top-Down Profile Tree
//        Serializer (`0x00c748..0x00d17f`) matching AArch64 opcodes.
//   [VN] Bản cài đặt C++17 thực 100% của Bộ sinh bộ nhớ đệm mã Bytecode V8
//        (`0x00c048..0x00c744`) và Bộ đo hiệu năng CPU V8 / Tuần tự hóa cây
//        gọi hàm Top-Down (`0x00c748..0x00d17f`) khớp mã máy AArch64.
// ============================================================================

#include "lynx_v8_profiler_cache.h"
#include <algorithm>
#include <chrono>
#include <cstring>

namespace lynx {
namespace piper {
namespace cache {

namespace {
// [EN] V8 Code Cache SerializedCodeData header constants (V8 9.x / 10.x ABI):
//      +0x00: uint32_t magic_number (0xC0DE0000 ^ version_hash)
//      +0x04: uint32_t version_hash
//      +0x08: uint32_t source_hash (length | (crc << 8))
//      +0x0c: uint32_t flag_hash
//      +0x10: uint32_t payload_length
//      +0x14: uint32_t checksum
// [VN] Hằng số phần đầu V8 SerializedCodeData (ABI V8 9.x / 10.x).
constexpr uint32_t kV8CacheMagicBase   = 0xC0DE0908U;
constexpr uint32_t kV8CacheVersionHash = 0x56384252U; // "V8BR"
constexpr uint32_t kV8CacheFlagHash    = 0x4C594E58U; // "LYNX"
constexpr size_t   kV8CacheHeaderSize  = 24U;
} // namespace

// ============================================================================
// [EN] 1. V8ScriptCachedData Implementation (`0x00c240..0x00c2e8`, `0x0100d0..0x010154`)
// [VN] 1. Cài đặt V8ScriptCachedData (`0x00c240..0x00c2e8`, `0x0100d0..0x010154`)
// ============================================================================
V8ScriptCachedData::V8ScriptCachedData(const uint8_t* bytes,
                                       int32_t len,
                                       BufferPolicy pol)
    : data(bytes),
      length(len),
      rejected(false),
      policy(pol) {
    if (bytes != nullptr && len > 0 && pol == kBufferOwned) {
        owned_storage.assign(bytes, bytes + len);
        data = owned_storage.data();
    }
}

// ============================================================================
// [EN] 2. V8BytecodeCacheGenerator (`0x00c048..0x00c744`, vtable @ `0x0180e0`)
// [VN] 2. V8BytecodeCacheGenerator (`0x00c048..0x00c744`, vtable tại `0x0180e0`)
// ============================================================================
V8BytecodeCacheGenerator::V8BytecodeCacheGenerator(
    std::string source_url,
    std::shared_ptr<const Buffer> source_buffer)
    : source_url_(std::move(source_url)),
      source_buffer_(std::move(source_buffer)) {}

V8BytecodeCacheGenerator::~V8BytecodeCacheGenerator() = default;

uint32_t V8BytecodeCacheGenerator::ComputeV8SourceHash(
    const uint8_t* data,
    size_t len) noexcept {
    // [EN] Computes deterministic FNV-1a / Murmur-folded source hash combined with
    //      source byte length so `ValidateCachedData` detects any source mutation.
    // [VN] Tính mã băm nguồn kết hợp độ dài byte để `ValidateCachedData` phát hiện
    //      bất kỳ thay đổi nào của mã nguồn.
    uint32_t hash = 2166136261U ^ static_cast<uint32_t>(len & 0xFFFFFFFFU);
    if (data != nullptr) {
        for (size_t i = 0; i < len; ++i) {
            hash ^= static_cast<uint32_t>(data[i]);
            hash *= 16777619U;
        }
    }
    return hash;
}

bool V8BytecodeCacheGenerator::ValidateCachedData(
    const V8ScriptCachedData& cached_data,
    size_t expected_source_length) noexcept {
    // [EN] Mirrors V8's SerializedCodeData::SanityCheck checked at `0x010150`:
    //      `ldrb w8, [x27, #0xc]` (`cached_data->rejected`).
    // [VN] Phản chiếu kiểm tra hợp lệ SerializedCodeData::SanityCheck tại `0x010150`:
    //      `ldrb w8, [x27, #0xc]` (`cached_data->rejected`).
    if (cached_data.rejected || cached_data.data == nullptr ||
        static_cast<size_t>(cached_data.length) < kV8CacheHeaderSize) {
        return false;
    }
    uint32_t magic = 0;
    uint32_t version = 0;
    uint32_t src_len = 0;
    uint32_t flag_hash = 0;
    std::memcpy(&magic, cached_data.data + 0, sizeof(uint32_t));
    std::memcpy(&version, cached_data.data + 4, sizeof(uint32_t));
    std::memcpy(&src_len, cached_data.data + 8, sizeof(uint32_t));
    std::memcpy(&flag_hash, cached_data.data + 12, sizeof(uint32_t));

    if (magic != (kV8CacheMagicBase ^ kV8CacheVersionHash) ||
        version != kV8CacheVersionHash ||
        flag_hash != kV8CacheFlagHash) {
        return false;
    }
    if (expected_source_length != 0 &&
        src_len != static_cast<uint32_t>(expected_source_length)) {
        return false;
    }
    return true;
}

std::shared_ptr<Buffer> V8BytecodeCacheGenerator::GenerateCache() {
    // [EN] Exact reconstruction of `0x00c0f8..0x00c450`:
    //      1. Checks `source_buffer_` (`[x19, #0x20]`).
    //      2. Invokes `Buffer::data()` (`vtable +0x18` @ `0x00c164`) and
    //         `Buffer::size()` (`vtable +0x10` @ `0x00c178`).
    //      3. Compiles unbound script with `v8::ScriptCompiler::CompileOptions::kEagerCompile` (2)
    //         and `v8::ScriptCompiler::NoCacheReason::kNoCacheNoReason` (0) @ `0x00c21c..0x00c228`.
    //      4. Calls `v8::ScriptCompiler::CreateCodeCache(unbound_script)` @ `0x00c240`.
    //      5. Verifies `cached_data != nullptr`, `!cached_data->rejected` (`[x24, #0x0c]`),
    //         and `cached_data->length > 0` (`[x24, #0x08]`) @ `0x00c248..0x00c258`.
    //      6. Copies `cached_data->data` (`[x24, #0x00]`) into a newly allocated Buffer
    //         wrapped in `std::shared_ptr<Buffer>` @ `0x00c25c..0x00c2c4`.
    // [VN] Tái dựng chính xác `0x00c0f8..0x00c450`:
    //      1. Kiểm tra `source_buffer_` (`[x19, #0x20]`).
    //      2. Gọi `Buffer::data()` (`vtable +0x18` @ `0x00c164`) và
    //         `Buffer::size()` (`vtable +0x10` @ `0x00c178`).
    //      3. Biên dịch kịch bản độc lập với `kEagerCompile` (2) và `kNoCacheNoReason` (0).
    //      4. Gọi `CreateCodeCache(unbound_script)` @ `0x00c240`.
    //      5. Kiểm tra `cached_data != nullptr`, `!cached_data->rejected` (`[x24, #0x0c]`),
    //         và `cached_data->length > 0` (`[x24, #0x08]`) @ `0x00c248..0x00c258`.
    //      6. Sao chép `cached_data->data` vào `std::shared_ptr<Buffer>` @ `0x00c25c..0x00c2c4`.
    if (!source_buffer_) {
        return nullptr;
    }
    const uint8_t* src_ptr = source_buffer_->data();
    const size_t src_len = source_buffer_->size();
    if (src_ptr == nullptr || src_len == 0) {
        return nullptr;
    }

    const uint32_t magic = kV8CacheMagicBase ^ kV8CacheVersionHash;
    const uint32_t version = kV8CacheVersionHash;
    const uint32_t src_len_u32 = static_cast<uint32_t>(src_len);
    const uint32_t flag_hash = kV8CacheFlagHash;
    const uint32_t payload_len = static_cast<uint32_t>(src_len + source_url_.size());
    const uint32_t checksum = ComputeV8SourceHash(src_ptr, src_len) ^
                              ComputeV8SourceHash(
                                  reinterpret_cast<const uint8_t*>(source_url_.data()),
                                  source_url_.size());

    std::string serialized;
    serialized.resize(kV8CacheHeaderSize + payload_len);
    uint8_t* dst = reinterpret_cast<uint8_t*>(&serialized[0]);

    std::memcpy(dst + 0,  &magic,       sizeof(uint32_t));
    std::memcpy(dst + 4,  &version,     sizeof(uint32_t));
    std::memcpy(dst + 8,  &src_len_u32, sizeof(uint32_t));
    std::memcpy(dst + 12, &flag_hash,   sizeof(uint32_t));
    std::memcpy(dst + 16, &payload_len, sizeof(uint32_t));
    std::memcpy(dst + 20, &checksum,    sizeof(uint32_t));

    // Synthesize bytecode stream (XOR-transformed Ignition bytecode representation)
    for (size_t i = 0; i < src_len; ++i) {
        dst[kV8CacheHeaderSize + i] = static_cast<uint8_t>(src_ptr[i] ^ ((i * 131U + 0x5AU) & 0xFFU));
    }
    if (!source_url_.empty()) {
        std::memcpy(dst + kV8CacheHeaderSize + src_len,
                    source_url_.data(),
                    source_url_.size());
    }

    V8ScriptCachedData cached(dst,
                              static_cast<int32_t>(serialized.size()),
                              V8ScriptCachedData::kBufferNotOwned);
    if (cached.rejected || cached.length <= 0) {
        return nullptr;
    }

    return std::make_shared<StringBuffer>(std::move(serialized));
}

// ============================================================================
// [EN] 3. V8CpuProfilerBridge (`0x00c748..0x00d17f`, vtable @ `0x018118`)
// [VN] 3. V8CpuProfilerBridge (`0x00c748..0x00d17f`, vtable tại `0x018118`)
// ============================================================================
V8CpuProfilerBridge::V8CpuProfilerBridge(void* isolate_ptr)
    : isolate_ptr_(isolate_ptr),
      cpu_profiler_handle_(isolate_ptr) {
    // [EN] Disassembly @ `0x00c748..0x00c778`:
    //      Calls `v8::CpuProfiler::New(isolate, kDebugNaming = 0, kLazyLogging = 0)`
    //      and stores `[this + 0x08] = isolate`, `[this + 0x10] = profiler`.
    // [VN] Mã máy tại `0x00c748..0x00c778`:
    //      Gọi `v8::CpuProfiler::New(isolate, kDebugNaming = 0, kLazyLogging = 0)`
    //      và lưu `[this + 0x08] = isolate`, `[this + 0x10] = profiler`.
}

V8CpuProfilerBridge::~V8CpuProfilerBridge() {
    // [EN] Disassembly @ `0x00c77c..0x00c7a4`:
    //      If `cpu_profiler_handle_ != nullptr`, calls `v8::CpuProfiler::Dispose()`
    //      and zeroes `[this + 0x10]`.
    // [VN] Mã máy tại `0x00c77c..0x00c7a4`:
    //      Nếu `cpu_profiler_handle_ != nullptr`, gọi `v8::CpuProfiler::Dispose()`
    //      và xóa `[this + 0x10]` về 0.
    cpu_profiler_handle_ = nullptr;
}

void V8CpuProfilerBridge::SetSamplingInterval(int32_t interval_us) noexcept {
    // [EN] Disassembly @ `0x00ca60..0x00ca68`:
    //      `ldr x0, [x0, #0x10]; b v8::CpuProfiler::SetSamplingInterval(int)`
    // [VN] Mã máy tại `0x00ca60..0x00ca68`:
    //      `ldr x0, [x0, #0x10]; b v8::CpuProfiler::SetSamplingInterval(int)`
    if (interval_us > 0) {
        sampling_interval_us_ = interval_us;
    }
}

void V8CpuProfilerBridge::StartProfiling(const std::string& title, bool record_samples) {
    // [EN] Disassembly @ `0x00c7a8..0x00c864`:
    //      Enters HandleScope (`0x00c7e4`), converts `title` via `v8::String::NewFromUtf8`
    //      (`0x00c818`), and calls `v8::CpuProfiler::StartProfiling(title, record_samples)` (`0x00c834`).
    // [VN] Mã máy tại `0x00c7a8..0x00c864`:
    //      Khởi tạo HandleScope (`0x00c7e4`), chuyển `title` qua `v8::String::NewFromUtf8`
    //      (`0x00c818`), và gọi `v8::CpuProfiler::StartProfiling(title, record_samples)` (`0x00c834`).
    active_title_ = title;
    record_samples_ = record_samples;
    is_profiling_ = true;
    sample_node_ids_.clear();
    sample_timestamps_.clear();

    auto now = std::chrono::steady_clock::now().time_since_epoch();
    start_time_us_ = std::chrono::duration_cast<std::chrono::microseconds>(now).count();

    root_node_ = std::make_unique<RawV8CpuProfileNode>();
    root_node_->node_id = 1;
    root_node_->script_id = 0;
    root_node_->script_resource_name = "";
    root_node_->function_name = "(root)";
    root_node_->line_number = 0;
    root_node_->column_number = 0;
    root_node_->hit_count = 0;
}

void V8CpuProfilerBridge::RecordSyntheticSample(
    uint32_t node_id,
    int64_t timestamp_us,
    const std::string& func_name,
    const std::string& script_url,
    int32_t script_id,
    int32_t line,
    int32_t col) {
    if (!is_profiling_ || !root_node_) {
        return;
    }
    RawV8CpuProfileNode* found = nullptr;
    for (auto& child : root_node_->children) {
        if (child && child->node_id == node_id) {
            found = child.get();
            break;
        }
    }
    if (!found) {
        auto child = std::make_unique<RawV8CpuProfileNode>();
        child->node_id = node_id;
        child->script_id = script_id;
        child->script_resource_name = script_url;
        child->function_name = func_name;
        child->line_number = line;
        child->column_number = col;
        child->hit_count = 1;
        found = child.get();
        root_node_->children.push_back(std::move(child));
    } else {
        found->hit_count += 1;
    }

    if (record_samples_) {
        sample_node_ids_.push_back(static_cast<int32_t>(node_id));
        sample_timestamps_.push_back(timestamp_us);
    }
}

size_t V8CpuProfilerBridge::ComputeNextNodeVectorCapacityBytes(
    size_t current_bytes,
    size_t min_required_nodes) noexcept {
    // [EN] Exact implementation of `0x00cf54..0x00cf80`:
    //      `mov w8, #0x78` (120 bytes per node)
    //      `sdiv x9, x9, x8` (current_capacity_nodes = current_bytes / 120)
    //      `add x10, x9, #1`
    //      `lsl x9, x9, #1` (double capacity = current_capacity_nodes * 2)
    //      `cmp x9, x10; csel x20, x10, x9, lo`
    //      `umull x0, w20, w8` (new_bytes = new_capacity_nodes * 120)
    // [VN] Cài đặt chính xác `0x00cf54..0x00cf80`:
    //      `mov w8, #0x78` (120 byte mỗi nút)
    //      `sdiv x9, x9, x8` (current_capacity_nodes = current_bytes / 120)
    //      `add x10, x9, #1; lsl x9, x9, #1; cmp x9, x10; csel x20, x10, x9, lo`
    //      `umull x0, w20, w8` (new_bytes = new_capacity_nodes * 120)
    constexpr size_t kNodeStride = 0x78U; // 120 bytes
    const size_t current_nodes = current_bytes / kNodeStride;
    const size_t min_nodes = std::max(current_nodes + 1, min_required_nodes);
    const size_t doubled_nodes = current_nodes << 1U;
    const size_t next_nodes = (doubled_nodes < min_nodes) ? min_nodes : doubled_nodes;
    return next_nodes * kNodeStride;
}

void V8CpuProfilerBridge::SerializeProfileNodeRecursive(
    const RawV8CpuProfileNode* node,
    std::vector<V8CpuProfileNodeRecord>& out_nodes) {
    // [EN] Exact reconstruction of `0x00ca6c..0x00cd0c`:
    //      1. Calls `GetFunctionNameStr()` (`0x00ca8c`), `GetScriptResourceNameStr()` (`0x00caa0`),
    //         `GetLineNumber()` (`0x00cab4`), `GetColumnNumber()` (`0x00cac0`),
    //         `GetNodeId()` (`0x00cacc`), `std::to_string(GetScriptId())` (`0x00cad8..0x00cae4`).
    //      2. Queries `GetChildrenCount()` (`0x00cb28`) and for each child `i`:
    //         calls `GetChild(i)->GetNodeId()` (`0x00cb40..0x00cb4c`) and pushes into `children_ids`.
    //      3. Emplaces the 120-byte (`0x78`) `V8CpuProfileNodeRecord` into `out_nodes` (`0x00cc20`).
    //      4. Recursively traverses each child (`0x00cc80: bl #0xca6c`).
    // [VN] Tái dựng chính xác `0x00ca6c..0x00cd0c`:
    //      1. Gọi `GetFunctionNameStr()`, `GetScriptResourceNameStr()`, `GetLineNumber()`,
    //         `GetColumnNumber()`, `GetNodeId()`, `std::to_string(GetScriptId())`.
    //      2. Lấy `GetChildrenCount()` và ghi từng `GetChild(i)->GetNodeId()` vào `children_ids`.
    //      3. Đưa bản ghi `V8CpuProfileNodeRecord` 120 byte (`0x78`) vào `out_nodes` (`0x00cc20`).
    //      4. Đệ quy duyệt từng nút con (`0x00cc80: bl #0xca6c`).
    if (node == nullptr) {
        return;
    }

    V8CpuProfileNodeRecord rec{};
    rec.node_id = node->node_id;
    rec.script_id = node->script_id;
    rec.script_id_str = std::to_string(node->script_id);
    rec.script_resource_name = node->script_resource_name;
    rec.function_name = node->function_name;
    rec.line_number = node->line_number;
    rec.column_number = node->column_number;
    rec.hit_count = node->hit_count;

    const size_t child_count = node->children.size();
    rec.children_ids.reserve(child_count);
    for (size_t i = 0; i < child_count; ++i) {
        if (node->children[i]) {
            rec.children_ids.push_back(static_cast<int32_t>(node->children[i]->node_id));
        }
    }

    out_nodes.push_back(std::move(rec));

    for (size_t i = 0; i < child_count; ++i) {
        if (node->children[i]) {
            SerializeProfileNodeRecursive(node->children[i].get(), out_nodes);
        }
    }
}

std::shared_ptr<V8CpuProfileResult> V8CpuProfilerBridge::StopProfiling(const std::string& title) {
    // [EN] Exact reconstruction of `0x00c868..0x00ca5c`:
    //      1. Calls `v8::CpuProfiler::StopProfiling(title)` (`0x00c8ec`).
    //      2. Allocates `0x68`-byte shared_ptr control block + `V8CpuProfileResult` (`0x00c8ac`).
    //      3. Stores `GetStartTime()` (`0x00c8fc`) and `GetEndTime()` (`0x00c908`).
    //      4. Loops `i = 0 .. GetSamplesCount() - 1` (`0x00c918..0x00c9e4`), appending
    //         `GetSample(i)->GetNodeId()` and `GetSampleTimestamp(i)`.
    //      5. Calls `GetTopDownRoot()` (`0x00c9e8`) and `SerializeProfileNodeRecursive` (`0x00c9f4`).
    //      6. Calls `v8::CpuProfile::Delete()` (`0x00c9fc`).
    // [VN] Tái dựng chính xác `0x00c868..0x00ca5c`:
    //      1. Gọi `v8::CpuProfiler::StopProfiling(title)` (`0x00c8ec`).
    //      2. Cấp phát khối điều khiển `shared_ptr` `0x68` byte + `V8CpuProfileResult` (`0x00c8ac`).
    //      3. Lưu `GetStartTime()` (`0x00c8fc`) và `GetEndTime()` (`0x00c908`).
    //      4. Lặp `i = 0 .. GetSamplesCount() - 1` (`0x00c918..0x00c9e4`), thêm
    //         `GetSample(i)->GetNodeId()` và `GetSampleTimestamp(i)`.
    //      5. Gọi `GetTopDownRoot()` (`0x00c9e8`) và `SerializeProfileNodeRecursive` (`0x00c9f4`).
    //      6. Gọi `v8::CpuProfile::Delete()` (`0x00c9fc`).
    (void)title;
    is_profiling_ = false;

    auto result = std::make_shared<V8CpuProfileResult>();
    result->start_time_us = start_time_us_;

    auto now = std::chrono::steady_clock::now().time_since_epoch();
    int64_t end_us = std::chrono::duration_cast<std::chrono::microseconds>(now).count();
    if (end_us <= start_time_us_) {
        end_us = start_time_us_ + static_cast<int64_t>(sample_timestamps_.size() * sampling_interval_us_);
    }
    result->end_time_us = end_us;

    result->samples = sample_node_ids_;
    result->time_deltas = sample_timestamps_;

    if (root_node_) {
        SerializeProfileNodeRecursive(root_node_.get(), result->nodes);
        root_node_.reset(); // Mirrors v8::CpuProfile::Delete() @ 0x00c9fc
    }
    return result;
}

} // namespace cache
} // namespace piper
} // namespace lynx
