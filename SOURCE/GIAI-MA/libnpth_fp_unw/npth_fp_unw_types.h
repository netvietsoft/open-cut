// ============================================================================
// Clean-Room C++17 Types & Constants for libnpth_fp_unw.so (Target 124 / 169)
// Định nghĩa kiểu dữ liệu & hằng số C++17 cho libnpth_fp_unw.so (Mục tiêu 124 / 169)
// Binary: 6,112 bytes | SHA-256: 30e06928f2338ea69825e5b6726f2e390e52cc84a9d96cc37ce3f7f8b75487b1
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>

namespace npth_fp_unw {

// Maximum frame depth clamped at 0x09f8..0x0a08 (`mov w9, #0x80; cmp x1, #0x80; csel x21, x1, x9, lo`)
// Độ sâu khung ngăn xếp tối đa được kẹp ở 128 khung (0x80)
constexpr size_t kMaxUnwindFrames       = 0x80; // 128 frames
constexpr size_t kOverflowFrameSentinel = 0x81; // 129 returned at 0x0a88 (`mov w0, #0x81`)
constexpr size_t kFormatLineBufferSize  = 0x400; // 1024 bytes per formatted line (`lsl x21, x28, #0xa` @ 0x0b04)

// AArch64 Canonical User-Space Pointer Bounds checked at 0x0a24..0x0a78:
//   x8 = 0xFFFFFF0000000000ULL (`mov x8, #-0x10000000000` @ 0x0a24)
//   x9 = 0xFFFFFF0000000001ULL (`mov x9, #-0xffffffffff`  @ 0x0a28)
//   Low 1MB null-guard mask: `and x12, x11, #0xfffff00000` (@ 0x0a54)
//   Same-stack 64KB proximity mask: `eor x12, x11, x29; tst x12, #0xffffff0000` (@ 0x0a60..0x0a64)
//   Minimum frame step: `add x10, x10, #0x10; cmp x11, x10` (@ 0x0a6c..0x0a70)
//   8-byte alignment mask: `and x12, x11, #7` (@ 0x0a78)
constexpr uint64_t kUserSpaceAddOffset  = 0xFFFFFF0000000000ULL;
constexpr uint64_t kUserSpaceCmpBound   = 0xFFFFFF0000000001ULL;
constexpr uint64_t kLow1MbGuardMask     = 0x000000FFFFF00000ULL;
constexpr uint64_t kSameStackRegionMask = 0x000000FFFFFF0000ULL;
constexpr uint64_t kMinFrameAdvance     = 0x10ULL; // 16 bytes (fp + lr)
constexpr uint64_t kFrameAlignMask      = 0x07ULL; // 8-byte alignment

// Exact .rodata format strings at 0x0790..0x081e:
// Các chuỗi định dạng chuẩn xác trong .rodata tại 0x0790..0x081e:
constexpr const char* kFmtWithSymbol  = "    #%02zu pc %016lx  %s (%s+%zu)\n";      // 0x0790
constexpr const char* kFmtUnknown     = "    #%02zu pc %016lx  <unknown>\n";        // 0x07b3
constexpr const char* kFramePrefixTag = "    #";                                    // 0x07d4
constexpr const char* kFmtNoSymbol    = "    #%02zu pc %016lx  %s\n";              // 0x07da
constexpr const char* kFmtAnonymous   = "    #%02zu pc %016lx  <anonymous:%016lx>\n"; // 0x07f4

// Standard Bionic Dl_info layout (32 bytes on AArch64, allocated at sp + 0x10 in npth_fp_format @ 0x0b5c):
// Cấu trúc Dl_info 32 byte của Bionic trên AArch64 (tại sp + 0x10 trong npth_fp_format @ 0x0b5c):
struct BionicDlInfoAbi {
    const char* dli_fname; // +0x00 (sp + 0x10)
    void*       dli_fbase; // +0x08 (sp + 0x18)
    const char* dli_sname; // +0x10 (sp + 0x20)
    void*       dli_saddr; // +0x18 (sp + 0x28)
};
static_assert(sizeof(BionicDlInfoAbi) == 32, "BionicDlInfoAbi must be 32 bytes on AArch64");

// Standard POSIX stack_t layout (24 bytes on AArch64, queried via sigaltstack(nullptr, &ss) @ 0x0a18):
struct PosixStackTAbi {
    void*  ss_sp;    // +0x00
    int    ss_flags; // +0x08
    size_t ss_size;  // +0x10
};
static_assert(sizeof(PosixStackTAbi) == 24, "PosixStackTAbi must be 24 bytes on AArch64");

} // namespace npth_fp_unw
