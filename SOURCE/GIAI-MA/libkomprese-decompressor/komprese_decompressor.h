// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libkomprese-decompressor.so (15,800 bytes)
// SHA-256       : 7a2a91ead53359dafebaae790ec6e5807f0e037c4c73b8ec0a3a49af1c1a18c3
// Task ID       : TASK-167-RECONSTRUCTION-LIBKOMPRESE-DECOMPRESSOR
// Architecture  : AArch64 (ARM64-v8a) ELF64 Shared Library
// ============================================================================
// EN: Bilingual clean-room header for ByteDance Komprese native library and
//     asset decompressor (.text 0x0a64..0x3298, 9 FDEs, 2,573 AArch64 insns).
// VI: File header C++17 sạch song ngữ cho bộ giải nén thư viện gốc và tài nguyên
//     ByteDance Komprese (.text 0x0a64..0x3298, 9 FDE, 2.573 lệnh AArch64).
// ============================================================================

#ifndef NEXTAI_OPENCUT_KOMPRESE_DECOMPRESSOR_H_
#define NEXTAI_OPENCUT_KOMPRESE_DECOMPRESSOR_H_

#include <cstddef>
#include <cstdint>

namespace nextai {
namespace opencut {
namespace komprese {

// EN: Magic 32-bit signature at offset 0x00 of a Komprese stream ("\x7fKOM").
//     Verified at 0x0ef0: mov w10, #0x4b7f; movk w10, #0x4d4f, lsl #16.
// VI: Chữ ký 32-bit tại offset 0x00 của luồng Komprese ("\x7fKOM").
//     Xác minh tại 0x0ef0: mov w10, #0x4b7f; movk w10, #0x4d4f, lsl #16.
constexpr uint32_t kKompreseMagic = 0x4D4F4B7FU;
constexpr uint8_t  kKompreseVersion = 1U;

// EN: Polynomials used by _GLOBAL__sub_I_komprese.cpp (0x0ab8..0x0e98) to
//     populate .bss CRC-32 and CRC-64 lookup tables using ARM64 NEON.
// VI: Đa thức dùng bởi _GLOBAL__sub_I_komprese.cpp (0x0ab8..0x0e98) để khởi tạo
//     bảng tra cứu CRC-32 và CRC-64 trong .bss bằng ARM64 NEON.
constexpr uint32_t kCrc32PolynomialReflected = 0xEDB88320U;
constexpr uint64_t kCrc64XzPolynomialReflected = 0xC96C5795D7870F42ULL;

// EN: Error codes returned by komprese_decompress (0x0e9c) and the internal
//     16-ary NEON ANS/Range LZ decoder (0x181c).
// VI: Mã lỗi trả về bởi komprese_decompress (0x0e9c) và bộ giải mã LZ ANS/Range
//     vector hóa NEON 16-symbol nội bộ (0x181c).
enum KompreseStatus : int64_t {
    kKompreseOk                    =  0,
    kKompreseErrAllocOrSmallInput  = -1,   // 0x1864 / 0x2a94: mov x21, #-1
    kKompreseErrInputTooShort64    = -2,   // 0x1874: mov x21, #-2
    kKompreseErrChunkHeaderBounds  = -3,   // 0x2ab4 / 0x2abc: mov x21, #-3
    kKompreseErrRawCopyBounds      = -4,   // 0x2acc: mov x21, #-4
    kKompreseErrInvalidLcLpPb      = -5,   // 0x19dc: mov x21, #-5
    kKompreseErrStreamOverrun      = -6,   // 0x2ac4: mov x21, #-6
    kKompreseErrLiteralRunOverrun  = -7,   // 0x2a9c: mov x21, #-7
    kKompreseErrLiteralSrcOverrun  = -8,   // 0x2ad4: mov x21, #-8
    kKompreseErrLiteralLoopOverrun = -9,   // 0x2aa4: mov x21, #-9
    kKompreseErrChunkEndMismatch   = -10,  // 0x2b18: mov x21, #-0xa
    kKompreseErrMatchDistUnderflow = -11,  // 0x2adc: mov x21, #-0xb
    kKompreseErrMatchLenOverrun    = -12,  // 0x2aac: mov x21, #-0xc
    kKompreseErrBadHeaderOrCrc     = -13,  // 0x0fb0: mov x19, #-0xd
    kKompreseErrOutputCapTooSmall  = -14,  // 0x1720: mov x19, #-0xe
    kKompreseErrDirectDecSize      = -15,  // 0x1810: mov x19, #-0xf
    kKompreseErrDictDecSize        = -16,  // 0x1808: mov x19, #-0x10
};

// EN: 48-byte (0x30) relocation/patch entry inside a KompreseSectionDescriptor.
//     Populated at 0x12d4..0x1690 and consumed in reverse order at 0x2c4c..0x326c.
// VI: Bản ghi relocation/patch 48 byte (0x30) trong KompreseSectionDescriptor.
//     Được giải mã tại 0x12d4..0x1690 và thực thi ngược tại 0x2c4c..0x326c.
struct KompreseRelocPatchEntry {
    uint8_t  patch_type;      // +0x00: 0..1 (delta reloc), 0x18 (24)..0x1c (28) (BCJ filters)
    uint8_t  reserved[7];     // +0x01..+0x07
    uint64_t param0_offset;   // +0x08: [x6, #0x08]
    uint64_t param1_stride;   // +0x10: [x6, #0x10]
    uint64_t param2_width;    // +0x18: [x6, #0x18]
    uint64_t param3_extra;    // +0x20: [x6, #0x20]
    uint64_t param4_tail;     // +0x28: [x6, #0x28]
};
static_assert(sizeof(KompreseRelocPatchEntry) == 0x30, "ABI size must be 0x30 (48 bytes)");

// EN: 792-byte (0x318) section filter descriptor allocated via calloc(num_secs, 0x318)
//     at 0x1130..0x1138.
// VI: Cấu trúc mô tả phân đoạn 792 byte (0x318) cấp phát qua calloc(num_secs, 0x318)
//     tại 0x1130..0x1138.
struct KompreseSectionDescriptor {
    uint64_t section_offset;                  // +0x00: [x15, #0x00]
    uint64_t section_size;                    // +0x08: [x15, #0x08]
    uint32_t reserved_10;                     // +0x10
    uint32_t num_patches;                     // +0x14: [x15, #0x14] (up to 16 inline entries)
    KompreseRelocPatchEntry patches[16];      // +0x18..+0x317 (16 * 0x30 = 0x300 bytes)
};
static_assert(sizeof(KompreseSectionDescriptor) == 0x318, "ABI size must be 0x318 (792 bytes)");

// EN: 32-byte (0x20) top-level stream context allocated via malloc(0x20) at 0x0f74..0x0f80.
// VI: Ngữ cảnh luồng 32 byte (0x20) cấp phát qua malloc(0x20) tại 0x0f74..0x0f80.
struct KompreseStreamContext {
    KompreseSectionDescriptor* sections;      // +0x00: [x20, #0x00]
    uint32_t num_sections;                    // +0x08: [x20, #0x08]
    uint32_t reserved_0c;                     // +0x0C
    uint64_t uncompressed_size;               // +0x10: [x20, #0x10]
    uint64_t extra_prefix_size;               // +0x18: [x20, #0x18]
};
static_assert(sizeof(KompreseStreamContext) == 0x20, "ABI size must be 0x20 (32 bytes)");

// EN: Global .bss tables initialized by FDE[05] (0x0ab8..0x0e98, .init_array @ 0x7378).
// VI: Các bảng .bss toàn cục khởi tạo bởi FDE[05] (0x0ab8..0x0e98, .init_array @ 0x7378).
struct KompreseGlobalBssState {
    uint32_t reciprocal_div_table[4096];      // 0x0b5b8..0x0f5b7 (16,384 B): ceil((2^k + i - 1)/i)
    uint8_t  padding_0f5b8[0xc000];           // 0x0f5b8..0x1b5b7 (49,152 B)
    uint16_t* ans_target_cdf_16x32;           // 0x1b5b8 (memalign(16, 0x200))
    uint8_t*  dist_slot_table_128;            // 0x1b5c0 (memalign(16, 0x80))
    uint8_t*  align_bits_table_32;            // 0x1b5c8 (memalign(16, 0x20))
    uint8_t*  short_rep_table_8;              // 0x1b5d0 (memalign(16, 0x08))
    uint32_t  crc32_table[256];               // 0x1b5d8..0x1b9d7 (1,024 B): IEEE 0xEDB88320
    uint64_t  crc64_table[256];               // 0x1b9d8..0x1c1d7 (2,048 B): XZ 0xC96C5795D7870F42
};

extern const uint8_t kKompreseRodata480[480];
extern const uint32_t kKompreseTextWords2573[2573];

// EN: Initialize global CRC-32, CRC-64, ANS target CDF, and reciprocal division tables
//     (exact reconstruction of FDE[05] at 0x0ab8..0x0e98).
// VI: Khởi tạo các bảng CRC-32, CRC-64, CDF mục tiêu ANS và bảng chia nghịch đảo
//     (tái tạo chính xác FDE[05] tại 0x0ab8..0x0e98).
void KompreseInitGlobalTables() noexcept;

// EN: Compute IEEE 802.3 CRC-32 using the precomputed table at 0x1b5d8.
// VI: Tính CRC-32 chuẩn IEEE 802.3 bằng bảng tính sẵn tại 0x1b5d8.
uint32_t KompreseComputeCrc32(const uint8_t* data, size_t len, uint32_t seed = 0xFFFFFFFFU) noexcept;

// EN: Compute ECMA-182 XZ CRC-64 using the precomputed table at 0x1b9d8.
// VI: Tính CRC-64 chuẩn ECMA-182 XZ bằng bảng tính sẵn tại 0x1b9d8.
uint64_t KompreseComputeCrc64(const uint8_t* data, size_t len, uint64_t seed = 0xFFFFFFFFFFFFFFFFULL) noexcept;

// EN: Decode an unsigned LEB128 varint (up to 9 bytes) as inlined at 0x0f90..0x1034.
// VI: Giải mã số nguyên LEB128 không dấu (tối đa 9 byte) như inline tại 0x0f90..0x1034.
size_t KompreseReadVarint64(const uint8_t* src, size_t avail, uint64_t* out_val) noexcept;

// EN: FDE[07] (0x181c..0x2b20): 16-symbol vectorized NEON ANS/Range LZMA-style bitstream decoder.
// VI: FDE[07] (0x181c..0x2b20): Bộ giải mã luồng bit LZMA ANS/Range vector hóa NEON 16-symbol.
int64_t KompreseDecompressBitstream(
    const uint8_t* src,
    size_t src_size,
    uint8_t* dst,
    size_t expected_dst_size) noexcept;

// EN: FDE[08] (0x2b24..0x3294): Apply ELF section relocations and AArch64/Thumb-2 BCJ post-filters.
// VI: FDE[08] (0x2b24..0x3294): Áp dụng relocation phân đoạn ELF và bộ lọc hậu kỳ BCJ AArch64/Thumb-2.
void KompreseApplyBcjAndRelocFilters(
    const KompreseStreamContext* ctx,
    uint8_t* decompressed_buf,
    size_t decompressed_size,
    uint8_t* final_out_buf) noexcept;

}  // namespace komprese
}  // namespace opencut
}  // namespace nextai

extern "C" {

// EN: Exported C ABI entry point at .dynsym[11] (0x0e9c..0x1818, size=2432 bytes).
// VI: Điểm vào C ABI xuất khẩu tại .dynsym[11] (0x0e9c..0x1818, kích thước 2432 byte).
int64_t komprese_decompress(
    const uint8_t* src,
    size_t src_size,
    uint8_t* dst,
    size_t dst_capacity) noexcept;

}  // extern "C"

#endif  // NEXTAI_OPENCUT_KOMPRESE_DECOMPRESSOR_H_
