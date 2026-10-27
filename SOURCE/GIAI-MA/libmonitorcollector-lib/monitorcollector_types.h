/**
 * @file monitorcollector_types.h
 * @brief Clean-Room C++17 ABI Types & Telemetry Structures for libmonitorcollector-lib.so
 *        Các kiểu dữ liệu ABI & cấu trúc thu thập hiệu năng C++17 Clean-Room cho libmonitorcollector-lib.so
 *
 * Binary SHA-256: 739e2276dd31bc2805670367cfff2abc4a3d26e73e5b75635daff2a1f125e183
 * Binary Size:    313,744 bytes
 * Architecture:   AArch64 (ARM64-v8a)
 */

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <jni.h>

namespace bytedance {
namespace monitor {
namespace collector {

/**
 * @brief AtraceEvent — Ring-buffer entry in `main_thread_events` (1,000 entries) & `sub_thread_events` (10,000 entries)
 *        Bản ghi sự kiện Atrace trong bộ đệm vòng `main_thread_events` (1.000 mục) & `sub_thread_events` (10.000 mục)
 *
 * Disassembly Anchor / Điểm neo mã máy:
 * - `0x012dac..0x012dd0`: `reset_atrace_event(AtraceEvent*)`
 * - `0x012dd0..0x013118`: `recordTrace(const void*, size_t)`
 * - `.data 0x050000`: `main_event_size = 1000` (`0x3e8`), `sub_event_size = 10000` (`0x2710`)
 */
struct AtraceEvent {
    char*    trace_str;       // +0x00: Heap-allocated trace line (`"%u,%lld,%s\n"`)
    int64_t  timestamp_ms;    // +0x08: Monotonic timestamp in ms (`monotonicTime() / 1000`)
    uint32_t tid;             // +0x10: Thread ID (`gettid()`)
    uint32_t str_len;         // +0x14: Byte length of `trace_str`
};

/**
 * @brief LockEvent — Monitor contention sample captured by `log_systrace` (`0x0125b4..0x0128f4`)
 *        Mẫu tranh chấp khóa (monitor contention) thu thập bởi `log_systrace` (`0x0125b4..0x0128f4`)
 *
 * Disassembly Anchor / Điểm neo mã máy:
 * - `0x0135d8..0x013670`: `lockinfo_chars(LockEvent)` formatting `"%lld&#&%lld&#&%s&#&%s"` (`.rodata 0x038dcf`)
 */
struct LockEvent {
    int64_t     start_time_ms;     // +0x00: `monitor_begin` (`0x050018`)
    int64_t     end_time_ms;       // +0x08: `monitor_end` (`0x050010`)
    const char* contention_detail; // +0x10: `contention_char` (`0x0501d0`)
    const char* thread_name;       // +0x18: `lock_thread_name` (`0x0501d8`)
};

/**
 * @brief ThreadStatInfoNative — Parsed `/proc/[pid]/task/[tid]/stat` & `schedstat` telemetry
 *        Thông tin thống kê luồng phân tích từ `/proc/[pid]/task/[tid]/stat` & `schedstat`
 *
 * Disassembly Anchor / Điểm neo mã máy:
 * - `0x015ed0..0x0162a0`: `CollectSchedValueFd`
 * - `0x0165bc..0x016844`: `CollectStateValueFd` (using `.rodata 0x038cf4` 11-byte jump table)
 */
struct ThreadStatInfoNative {
    int32_t  tid;                  // +0x00
    char     state;                // +0x04: Process state char ('R', 'S', 'D', 'Z', ...)
    uint64_t utime_ticks;          // +0x08: Field 14 (`utime`)
    uint64_t stime_ticks;          // +0x10: Field 15 (`stime`)
    int64_t  cutime_ticks;         // +0x18: Field 16 (`cutime`)
    int64_t  cstime_ticks;         // +0x20: Field 17 (`cstime`)
    int64_t  priority;             // +0x28: Field 18 (`priority`)
    int64_t  nice;                 // +0x30: Field 19 (`nice`)
    int64_t  num_threads;          // +0x38: Field 20 (`num_threads`)
    uint64_t vsize_bytes;          // +0x40: Field 23 (`vsize`)
    int64_t  rss_pages;            // +0x48: Field 24 (`rss`)
    uint64_t wait_sum_ns;          // +0x50: `se.statistics.wait_sum` from `/proc/[pid]/sched`
    uint64_t sum_exec_runtime_ns;  // +0x58: `se.sum_exec_runtime`
    uint64_t nr_switches;          // +0x60: `nr_switches` (`nr_voluntary_switches + nr_involuntary_switches`)
};

/**
 * @brief ArtSymbolTable — 16 dynamically resolved `libart.so` pointers in `.bss 0x050268..0x0502e0`
 *        Bảng 16 con trỏ hàm `libart.so` phân giải động trong `.bss 0x050268..0x0502e0`
 *
 * Disassembly Anchor / Điểm neo mã máy:
 * - `0x018430..0x0186f0`: `initSymbolAndOffset()`
 */
struct ArtSymbolTable {
    void* StackWalkVisitorFunc;                             // 0x050268
    void* StackVisitor_GetDexPcFunc;                        // 0x050270
    void* GetBytesAllocatedEverFunc;                        // 0x050278
    void* GetObjectsAllocatedEverFunc;                      // 0x050280
    void* GetGcCountFunc;                                   // 0x050288
    void* GetGcTimeFunc;                                    // 0x050290
    void* GetBlockingGcCountFunc;                           // 0x050298
    void* GetBlockingGcTimeFunc;                            // 0x0502a0
    void* GetPrettyDescriptorFunc;                          // 0x0502a8
    void* SetAllocationListenerFunc;                        // 0x0502b0
    void* RemoveAllocationListenerFunc;                     // 0x0502b8
    void* PrettyMethodFunc;                                 // 0x0502c0
    void* Monitor_TranslateLocationFunc;                    // 0x0502c8
    void* ThreadList_RunCheckpointFunc;                     // 0x0502d0
    void* Thread_ResetQuickAllocEntryPointsForThreadFunc;   // 0x0502d8
    void* SetQuickAllocEntryPointsInstrumentedFunc;         // 0x0502e0
};

/**
 * @brief ByteBuffer — Native binary serializer used by `getAllocReportInfo` (`0x01b58c..0x01b71c`)
 *        Bộ tuần tự hóa nhị phân gốc dùng bởi `getAllocReportInfo` (`0x01b58c..0x01b71c`)
 */
class ByteBuffer {
public:
    explicit ByteBuffer(size_t initial_capacity = 4096) noexcept;
    ~ByteBuffer() noexcept;

    void ensureWrite(size_t additional_bytes) noexcept;
    void putLong(int64_t val) noexcept;
    void putInt(int32_t val) noexcept;
    void putStringStd(const std::string& str) noexcept;
    int64_t getLong() noexcept;
    int32_t getInt() noexcept;
    std::string getString() noexcept;
    void rebase(size_t new_pos) noexcept;

    uint8_t* data() const noexcept { return buffer_; }
    size_t position() const noexcept { return write_pos_; }
    size_t capacity() const noexcept { return capacity_; }

private:
    uint8_t* buffer_;
    size_t   write_pos_;
    size_t   read_pos_;
    size_t   capacity_;
};

/**
 * @brief JniMethodEntry — `.data.rel.ro` `JNINativeMethod` descriptor
 *        Cấu trúc mô tả phương thức JNI trong `.data.rel.ro`
 */
struct JniMethodEntry {
    const char* name;
    const char* signature;
    uint64_t    fn_vaddr;
};

} // namespace collector
} // namespace monitor
} // namespace bytedance
