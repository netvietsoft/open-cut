// ============================================================================
// Clean-Room C++17 ABI & Data Structures for libquick.so (Target 116 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho libquick.so (Mục tiêu 116 / 169)
// Binary Size: 1,837,504 bytes | SHA-256: 605dd5a78cda21f3b7758d9a69e88a497ef9f9df55543961037664f42a88f00d
// .dynsym: 1,547 Exported Symbols @ 0x000330 | .eh_frame_hdr: 1,893 FDEs @ 0x03768c
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <sstream>

// Constants verified directly from AArch64 opcodes in libquick.so
// Các hằng số xác minh trực tiếp từ mã máy AArch64 trong libquick.so
constexpr uint32_t kHeapObjMaxLen = 0x02000000U;      // mov w8, #0x2000000 @ 0x068a64
constexpr uint32_t kHeapObjTagMask = 0x0000003FU;     // and w8, w8, #0xffffffc0 @ 0x068a54
constexpr uint32_t kHeapObjLenShift = 6U;             // bfi w8, w1, #6, #0x1a @ 0x068a7c; asr w0, w8, #6 @ 0x068a8c
constexpr size_t kGlobalHandlesNodeSize = 40;         // add x8, x8, x8, lsl #2; lsl x0, x8, #3 @ 0x06a034 (5 * 8 = 40B)
constexpr size_t kGlobalHandlesBlockPayload = 0x2800; // add x8, x8, x8, lsl #2; lsl x0, x8, #0xb @ 0x06a020 (5 * 2048 = 10,240B)
constexpr size_t kGlobalHandlesBlockAllocSize = 0x2830; // mov w0, #0x2830 @ 0x06a0e4 (10,240B payload + 48B header)
constexpr size_t kGlobalHandlesNodeSpaceSize = 0x30;  // mov w0, #0x30 @ 0x06a05c (48 bytes)

struct LEPUSRuntime;
struct LEPUSContext;
struct malloc_state;
struct malloc_chunk;
struct malloc_tree_chunk;
struct JSToken;

// 16-byte NaN-boxed / tagged value used by LEPUS / PrimJS / QuickJS
// Giá trị gắn thẻ 16-byte dùng bởi LEPUS / PrimJS / QuickJS
struct LEPUSValue {
    uint64_t u_int64{0};
    int64_t tag{0};
};

// Negative-offset heap chunk metadata header at [ptr - 8] and [ptr - 4]
// Tiêu đề siêu dữ liệu khối heap độ lệch âm tại [ptr - 8] và [ptr - 4]
struct HeapObjNegativeHeader {
    uint32_t tag_and_len{0}; // [ptr - 8]: bits [5:0] = alloc_tag, bits [31:6] = heap_obj_len / hash_size
    uint32_t mark_word{0};   // [ptr - 4]: mark bit for multi-thread/incremental GC
};

namespace primjs {
namespace general {
namespace logging {

class LogMessage {
public:
    // 0x062c34..0x062cfc
    LogMessage(const char* file, int32_t line, int32_t severity);
    // 0x0640b4..0x0641b8
    ~LogMessage();

    // 0x062cfc..0x063048
    void Init(const char* file, int32_t line);
    // 0x0640ac..0x0640b4
    std::ostream& stream() noexcept { return stream_; }

private:
    const char* file_{nullptr};
    int32_t line_{0};
    int32_t severity_{0};
    std::ostringstream stream_;
};

int32_t GetMinAllLogLevel() noexcept;
void Log(LogMessage* msg);

} // namespace logging
} // namespace general
} // namespace primjs
