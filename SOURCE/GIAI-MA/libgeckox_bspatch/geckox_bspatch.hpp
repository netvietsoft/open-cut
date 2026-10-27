// ============================================================================
// File: geckox_bspatch.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libgeckox_bspatch.so (119,768 bytes)
// SHA-256: caa28254b54a76d8eef6089da0bc101ca994f1129870a001ff3b9e2bea6045d8
// Task ID: TASK-195-RECONSTRUCTION-LIBGECKOX-BSPATCH (TASK_SO_132_libgeckox_bspatch)
// Architecture: AArch64 (ARM64-v8a) — 65 FDEs (.eh_frame_hdr @ 0x171dc), 18,542 .text insns
// Clean-Room C++17 Header: ByteDance GeckoX Binary Diff Patch Engine (BSDIFF40)
// & Embedded libbzip2 1.0.8 Burrows-Wheeler Transform / Move-To-Front / Huffman Codec
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures (BzStreamAbi,
// BsDiff40HeaderAbi, BsPatchControlTuple), ELF section constants, and exported APIs.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI (BzStreamAbi,
// BsDiff40HeaderAbi, BsPatchControlTuple), hằng số phân đoạn ELF và các hàm xuất khẩu.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace geckox_bspatch {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 119768ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x02690ULL;
constexpr std::uint64_t kPltSectionSize      = 0x004a0ULL; // 1,184 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x02b30ULL;
constexpr std::uint64_t kTextSectionSize     = 0x121b8ULL; // 74,168 bytes (18,542 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x14cf0ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x024ecULL; // 9,452 bytes (BZ2_crc32Table, BZ2_rNums)
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x171dcULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x00214ULL; // 532 bytes (65 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x173f0ULL;
constexpr std::uint64_t kEhFrameSize         = 0x009e8ULL; // 2,536 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x1fa50ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x00088ULL; // 136 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x20000ULL;
constexpr std::uint64_t kDataSectionSize     = 0x00c40ULL; // 3,136 bytes
constexpr std::uint64_t kBssSectionVaddr     = 0x20c40ULL;
constexpr std::uint64_t kBssSectionSize      = 0x010f0ULL; // 4,336 bytes

// ============================================================================
// [EN] 2. BSDIFF40 Header, Control Tuple & libbzip2 bz_stream ABI Structures
// [VN] 2. Cấu trúc ABI BSDIFF40 Header, Bộ Ba Điều Khiển & bz_stream của libbzip2
// ============================================================================
struct BsDiff40HeaderAbi {
    char         magic[8];          // +0x00: "BSDIFF40"
    std::int64_t ctrl_block_len;    // +0x08: Length of bzip2-compressed control block
    std::int64_t diff_block_len;    // +0x10: Length of bzip2-compressed diff block
    std::int64_t new_file_size;     // +0x18: Output patched file size in bytes
};
static_assert(sizeof(BsDiff40HeaderAbi) == 0x20, "BsDiff40HeaderAbi size must be 32 bytes");

struct BsPatchControlTuple {
    std::int64_t add_len;           // +0x00: x = number of bytes to add from diff block
    std::int64_t extra_len;         // +0x08: y = number of bytes to copy from extra block
    std::int64_t seek_offset;       // +0x10: z = signed offset to advance oldpos
};
static_assert(sizeof(BsPatchControlTuple) == 0x18, "BsPatchControlTuple size must be 24 bytes");

struct BzStreamAbi {
    char*        next_in;           // +0x00
    unsigned int avail_in;          // +0x08
    unsigned int total_in_lo32;     // +0x0c
    unsigned int total_in_hi32;     // +0x10
    unsigned int pad0;              // +0x14
    char*        next_out;          // +0x18
    unsigned int avail_out;         // +0x20
    unsigned int total_out_lo32;    // +0x24
    unsigned int total_out_hi32;    // +0x28
    unsigned int pad1;              // +0x2c
    void*        state;             // +0x30
    void*      (*bzalloc)(void*, int, int); // +0x38
    void       (*bzfree)(void*, void*);     // +0x40
    void*        opaque;            // +0x48
};
static_assert(sizeof(BzStreamAbi) == 0x50, "BzStreamAbi size must be 80 bytes");

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    std::uint64_t fde_vaddr;
};

extern const FdeDescriptor kFdeTable[65];
extern const std::uint32_t kTextInstructions[18542];
extern const std::uint8_t kElfImageBytes[119768];

std::int64_t DecodeBsPatchOfftin64(const std::uint8_t buf[8]) noexcept;
int ApplyBsPatchBlocksInMemory(const std::uint8_t* old_buf, std::int64_t old_size,
                               const std::uint8_t* diff_buf, std::int64_t diff_size,
                               const std::uint8_t* extra_buf, std::int64_t extra_size,
                               const BsPatchControlTuple* tuples, std::size_t tuple_count,
                               std::uint8_t* new_buf, std::int64_t new_size) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace geckox_bspatch
} // namespace bytedance

extern "C" {
const char* BZ2_bzlibVersion() noexcept;
int BZ2_bzCompressInit(bytedance::geckox_bspatch::BzStreamAbi* strm,
                       int blockSize100k, int verbosity, int workFactor) noexcept;
int BZ2_bzDecompressInit(bytedance::geckox_bspatch::BzStreamAbi* strm,
                         int verbosity, int small) noexcept;
int BZ2_bzDecompress(bytedance::geckox_bspatch::BzStreamAbi* strm) noexcept;
int BZ2_bzDecompressEnd(bytedance::geckox_bspatch::BzStreamAbi* strm) noexcept;
}
