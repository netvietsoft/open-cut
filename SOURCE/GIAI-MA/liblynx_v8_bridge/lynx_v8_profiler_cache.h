// ============================================================================
// File: lynx_v8_profiler_cache.h
// Target: liblynx_v8_bridge.so (0x00c048..0x00d17f)
// Description:
//   [EN] V8 Bytecode Code-Cache Generator (lynx::piper::cache::CacheGenerator)
//        and V8 CPU Profiler / Top-Down Call-Tree Serializer (0x00c748..0x00d17f).
//   [VN] Bộ sinh bộ nhớ đệm mã Bytecode V8 (lynx::piper::cache::CacheGenerator)
//        và Bộ đo hiệu năng CPU V8 / Tuần tự hóa cây gọi hàm Top-Down (0x00c748..0x00d17f).
// ============================================================================

#pragma once

#include "lynx_v8_bridge_types.h"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace lynx {
namespace piper {
namespace cache {

// ============================================================================
// [EN] Simulated V8 ScriptCompiler::CachedData ABI (`24 bytes = 0x18`)
//      Matches offsets accessed at `0x00c240..0x00c260` and `0x0100d0..0x010154`:
//        +0x00: const uint8_t* data
//        +0x08: int32_t length
//        +0x0c: bool rejected
//        +0x0d: uint8_t buffer_policy (0 = BufferNotOwned, 1 = BufferOwned)
// [VN] Cấu trúc ABI V8 ScriptCompiler::CachedData (`24 bytes = 0x18`)
//      Khớp với các offset truy cập tại `0x00c240..0x00c260` và `0x0100d0..0x010154`:
//        +0x00: const uint8_t* data
//        +0x08: int32_t length
//        +0x0c: bool rejected
//        +0x0d: uint8_t buffer_policy (0 = BufferNotOwned, 1 = BufferOwned)
// ============================================================================
struct V8ScriptCachedData {
    enum BufferPolicy : uint8_t {
        kBufferNotOwned = 0,
        kBufferOwned    = 1
    };

    const uint8_t* data{nullptr}; // +0x00
    int32_t length{0};            // +0x08
    bool rejected{false};         // +0x0c
    BufferPolicy policy{kBufferNotOwned}; // +0x0d
    uint16_t padding{0};          // +0x0e
    std::vector<uint8_t> owned_storage;

    V8ScriptCachedData() = default;
    V8ScriptCachedData(const uint8_t* bytes, int32_t len, BufferPolicy pol);
    ~V8ScriptCachedData() = default;
};

// ============================================================================
// [EN] Base class `lynx::piper::cache::CacheGenerator` & V8 Implementation
//      Reconstructed from `0x00c048..0x00c744` (vtable @ `0x0180e0`).
// [VN] Lớp cơ sở `lynx::piper::cache::CacheGenerator` & Bản cài đặt V8
//      Tái dựng từ `0x00c048..0x00c744` (vtable tại `0x0180e0`).
// ============================================================================
class CacheGenerator {
public:
    virtual ~CacheGenerator() = default;
    // Vtable slot +0x10 -> 0x00c0f8
    virtual std::shared_ptr<Buffer> GenerateCache() = 0;
};

class V8BytecodeCacheGenerator final : public CacheGenerator {
public:
    // Constructed at `0x00c048..0x00c0b8` (`48 bytes = 0x30` @ `0x00c5cc`)
    V8BytecodeCacheGenerator(std::string source_url,
                             std::shared_ptr<const Buffer> source_buffer);
    ~V8BytecodeCacheGenerator() override;

    // Disassembly @ `0x00c0f8..0x00c450`
    // Compiles unbound V8 script with `kEagerCompile = 2, kNoCacheNoReason = 0`
    // and extracts `v8::ScriptCompiler::CreateCodeCache(unbound_script)`.
    std::shared_ptr<Buffer> GenerateCache() override;

    const std::string& source_url() const noexcept { return source_url_; }
    std::shared_ptr<const Buffer> source_buffer() const noexcept { return source_buffer_; }

    // Deterministic V8 bytecode cache synthesis & validation matching V8 header layout
    static uint32_t ComputeV8SourceHash(const uint8_t* data, size_t len) noexcept;
    static bool ValidateCachedData(const V8ScriptCachedData& cached_data,
                                   size_t expected_source_length) noexcept;

private:
    std::string source_url_;                     // +0x08..0x1f
    std::shared_ptr<const Buffer> source_buffer_;// +0x20..0x2f
};

// ============================================================================
// [EN] Simulated V8 CpuProfileNode & CpuProfile for `0x00c748..0x00d17f`
// [VN] Mô phỏng V8 CpuProfileNode & CpuProfile cho `0x00c748..0x00d17f`
// ============================================================================
struct RawV8CpuProfileNode {
    uint32_t node_id{0};
    int32_t script_id{0};
    std::string script_resource_name;
    std::string function_name;
    int32_t line_number{1};
    int32_t column_number{1};
    uint32_t hit_count{0};
    std::vector<std::unique_ptr<RawV8CpuProfileNode>> children;
};

class V8CpuProfilerBridge {
public:
    // Constructed at `0x00c748..0x00c778` (`v8::CpuProfiler::New(isolate, kDebugNaming, kLazyLogging)`)
    explicit V8CpuProfilerBridge(void* isolate_ptr);
    ~V8CpuProfilerBridge();

    // Disassembly @ `0x00ca60..0x00ca68` (`v8::CpuProfiler::SetSamplingInterval`)
    void SetSamplingInterval(int32_t interval_us) noexcept;

    // Disassembly @ `0x00c7a8..0x00c864` (`v8::CpuProfiler::StartProfiling`)
    void StartProfiling(const std::string& title, bool record_samples);

    // Disassembly @ `0x00c868..0x00ca5c` (`v8::CpuProfiler::StopProfiling`)
    std::shared_ptr<V8CpuProfileResult> StopProfiling(const std::string& title);

    // Disassembly @ `0x00ca6c..0x00cd0c`
    // Recursive top-down DFS serializer packing `120`-byte (`0x78`) node records
    // (`sdiv x20, x8, x11` where `w11 = #0x78` @ `0x00cc20..0x00cc30`).
    static void SerializeProfileNodeRecursive(
        const RawV8CpuProfileNode* node,
        std::vector<V8CpuProfileNodeRecord>& out_nodes);

    // Exact capacity expansion formula @ `0x00cf54..0x00cf80`:
    //   `mov w8, #0x78; sdiv x9, x9, x8; add x10, x9, #1; lsl x9, x9, #1; cmp; csel`
    static size_t ComputeNextNodeVectorCapacityBytes(size_t current_bytes,
                                                     size_t min_required_nodes) noexcept;

    void RecordSyntheticSample(uint32_t node_id, int64_t timestamp_us,
                               const std::string& func_name,
                               const std::string& script_url,
                               int32_t script_id, int32_t line, int32_t col);

    int32_t sampling_interval_us() const noexcept { return sampling_interval_us_; }
    bool is_profiling() const noexcept { return is_profiling_; }

private:
    void* isolate_ptr_{nullptr};              // +0x08
    void* cpu_profiler_handle_{nullptr};      // +0x10
    int32_t sampling_interval_us_{1000};
    bool is_profiling_{false};
    bool record_samples_{true};
    int64_t start_time_us_{0};
    std::string active_title_;
    std::unique_ptr<RawV8CpuProfileNode> root_node_;
    std::vector<int32_t> sample_node_ids_;
    std::vector<int64_t> sample_timestamps_;
};

} // namespace cache
} // namespace piper
} // namespace lynx
