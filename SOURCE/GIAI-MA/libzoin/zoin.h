// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libzoin.so (20,304 bytes)
// SHA-256       : 461eaaa63714d460001f67de31520aa3d5b97431d177f9f73005c9519e87adcc
// Task ID       : TASK-175-RECONSTRUCTION-LIBZOIN
// Legacy Task   : TASK_SO_087_libzoin
// Architecture  : AArch64 (ARM64-v8a) ELF64 Shared Library (BTI-enabled)
// ============================================================================
// EN: Bilingual clean-room header for ByteDance Zoin Compressed Native Library
//     & Asset Extraction Engine (`libzoin.so`, .text 0x224c..0x4120,
//     54 FDEs @ 0x1ac0, 1,973 AArch64 instructions, 1 exported JNI entry point
//     `JNI_OnLoad` + 4 dynamically registered JNI native methods).
// VI: File header C++17 phòng sạch song ngữ cho Động cơ Giải nén Thư viện Native
//     & Tài nguyên Zoin của ByteDance (`libzoin.so`, .text 0x224c..0x4120,
//     54 FDE @ 0x1ac0, 1.973 lệnh AArch64, 1 biểu tượng xuất khẩu `JNI_OnLoad`
//     cùng 4 phương thức JNI đăng ký động).
// ============================================================================

#ifndef NEXTAI_OPENCUT_ZOIN_H_
#define NEXTAI_OPENCUT_ZOIN_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace zoin {

// EN: Constants verified directly from AArch64 opcodes in `libzoin.so`:
//     - `kZoinJniVersion1_6 = 0x00010006` (`mov w2, #6; movk w2, #1, lsl #16` @ 0x22c8..0x22d8).
//     - `kZoinThreadLogSlotCount = 8`, `kZoinThreadLogSlotStride = 0x18` (24 bytes @ 0x2398..0x239c),
//       `kZoinThreadLogBufferBytes = 0x2800` (10,240 bytes @ 0x23cc).
//     - `kZoinNsPerMs = 0x000F4240` (1,000,000 @ 0x2750..0x2758).
//     - `kZoinNsPerSec = 0x3B9ACA00ULL` (1,000,000,000 @ 0x3da0..0x3da8).
//     - `kZipEocdSignature = 0x06054B50U` (`mov w8, #0x4b50; movk w8, #0x605, lsl #16` @ 0x343c..0x3440).
//     - `kZipMaxEocdSearchWindow = 0x10015U` (65,557 bytes @ 0x33b4..0x33b8).
//     - `kZoinBuildFileInfoStride = 0x50U` (80 bytes @ 0x27f0..0x27f8, 0x301c, 0x30a0).
// VI: Các hằng số xác minh trực tiếp từ mã máy AArch64 trong `libzoin.so`.
constexpr int32_t  kZoinJniVersion1_6          = 0x00010006;
constexpr size_t   kZoinThreadLogSlotCount     = 8U;
constexpr size_t   kZoinThreadLogSlotStride    = 0x18U;       // 24 bytes
constexpr size_t   kZoinThreadLogBufferBytes   = 0x2800U;     // 10,240 bytes
constexpr int64_t  kZoinNsPerMs                = 0x000F4240;  // 1,000,000
constexpr uint64_t kZoinNsPerSec               = 0x3B9ACA00ULL;
constexpr uint32_t kZipEocdSignature           = 0x06054B50U;
constexpr uint32_t kZipMaxEocdSearchWindow     = 0x10015U;    // 65,557 bytes
constexpr size_t   kZoinBuildFileInfoStride    = 0x50U;       // 80 bytes
constexpr int32_t  kZlibRawWindowBitsNeg15     = -15;         // 0x3818
constexpr int32_t  kZlibStreamStructSize       = 0x70;        // 112 bytes (0x381c)

// EN: Exact 80-byte (`0x50`) layout of `ZoinBuildFileInfoNative` allocated at
//     `0x27f0..0x27fc` (`(count * 5) << 4`) and populated in `FDE[07]` (`0x2a58..0x2afc`).
// VI: Bố cục chính xác 80 byte (`0x50`) của `ZoinBuildFileInfoNative` cấp phát
//     tại `0x27f0..0x27fc` và điền dữ liệu tại `FDE[07]` (`0x2a58..0x2afc`).
struct ZoinBuildFileInfoNative {
    char*    name;                  // +0x00 (x28 - 0x28)
    char*    compressed_name;       // +0x08 (x28 - 0x20)
    char*    relative_path;         // +0x10 (x28 - 0x18)
    char*    decompress_path;       // +0x18 (x28 - 0x10)
    int64_t  begin_offset;          // +0x20 (x28 - 0x08)
    int64_t  offset_in_file;        // +0x28 (x28 + 0x00)
    int64_t  check_number;          // +0x30 (x28 + 0x08)
    int64_t  aligned_file_length;   // +0x38 (x28 + 0x10)
    int64_t  file_length;           // +0x40 (x28 + 0x18)
    int64_t  compressed_size;       // +0x48 (x28 + 0x20)
};
static_assert(sizeof(ZoinBuildFileInfoNative) == kZoinBuildFileInfoStride,
              "ZoinBuildFileInfoNative must be 0x50 (80) bytes");

// EN: Exact 24-byte (`0x18`) layout of each thread-local log slot in `.bss 0xc7c0`
//     allocated in `FDE[06]` (`0x2398..0x23dc`) and queried in `FDE[08]` (`0x38cc..0x3954`).
// VI: Bố cục chính xác 24 byte (`0x18`) của mỗi ô nhật ký luồng trong `.bss 0xc7c0`.
struct ZoinThreadLogSlot {
    char*    buffer;       // +0x00: 10,240-byte log buffer
    int64_t  write_offset; // +0x08: current byte offset in buffer
    int32_t  tid;          // +0x10: atomic owner thread ID (`ldar`/`ldaxr`/`stxr`)
    int32_t  reserved;     // +0x14
};
static_assert(sizeof(ZoinThreadLogSlot) == kZoinThreadLogSlotStride,
              "ZoinThreadLogSlot must be 0x18 (24) bytes");

struct ZoinInsnRecord {
    uint32_t    va;
    uint32_t    opcode_word;
    const char* mnemonic;
    const char* operands;
    int32_t     fde_index;
};

extern const uint32_t       kZoinCrc32Table256[256];
extern const uint8_t        kZoinRodata2608[2608];
extern const uint8_t        kZoinEhFrame1932[1932];
extern const uint32_t       kZoinTextWords1973[1973];
extern const uint32_t       kZoinPltWords176[176];
extern const ZoinInsnRecord kZoinDisassemblyTable2149[2149];

// EN: Exact mathematical formula of `FDE[17]` (`0x3e84..0x3ef8`, 116 bytes):
//     Computes IEEE 802.3 CRC-32 over `data[0..len)` using `.rodata 0x16c0`
//     (`kZoinCrc32Table256`), inverts `~crc`, and adds `len` as 64-bit unsigned integer:
//       `result = static_cast<uint64_t>(~crc32_state) + static_cast<uint64_t>(len)`
//     (`mvn w3, w8; add x19, x3, x4` @ 0x3ec8..0x3ecc).
// VI: Công thức toán học chính xác của `FDE[17]` (`0x3e84..0x3ef8`, 116 byte).
uint64_t CalculateZoinCrc32PlusLength(const uint8_t* data, size_t len) noexcept;

// EN: Exact reconstruction of `FDE[14]` (`0x3d58..0x3db8`, 96 bytes):
//     `tv_sec * 0x3B9ACA00ULL + tv_nsec` (`madd x0, x8, x10, x9` @ 0x3da8).
// VI: Tái tạo chính xác `FDE[14]` (`0x3d58..0x3db8`, 96 byte).
uint64_t ComputeMonotonicNanoseconds(int64_t tv_sec, int64_t tv_nsec) noexcept;

// EN: Exact reconstruction of the `cpu_set_t` bitmask builder in `FDE[07]`
//     (`0x2c10..0x2c44`): for each core index `c`:
//       `word_byte_offset = (c >> 3) & 0x18` (`lsr x13, x12, #3; and x13, x13, #0x18`),
//       `mask[word_byte_offset / 8] |= (1ULL << (c & 63))` (`lsl x12, x10, x12; orr`).
// VI: Tái tạo chính xác bộ dựng mặt nạ bit `cpu_set_t` trong `FDE[07]` (`0x2c10..0x2c44`).
void BuildBigCoreCpuSetMask(const uint8_t* core_ids, size_t count, uint64_t out_words[16]) noexcept;

// EN: Exact reconstruction of the ZIP End-of-Central-Directory (`0x06054B50`) backward
//     scanner in `FDE[07]` (`0x341c..0x3460`).
// VI: Tái tạo chính xác bộ quét ngược chữ ký ZIP EOCD (`0x06054B50`) trong `FDE[07]`.
int64_t FindZipEocdOffset(const uint8_t* tail_buf, size_t tail_len) noexcept;

}  // namespace zoin
}  // namespace opencut
}  // namespace nextai

extern "C" {
// EN: Exported symbol in `.dynsym` of `libzoin.so`: [43] `JNI_OnLoad` (0x22a0, 228 bytes).
// VI: Biểu tượng xuất khẩu trong `.dynsym` của `libzoin.so`: [43] `JNI_OnLoad` (0x22a0, 228 byte).
int JNI_OnLoad(void* vm, void* reserved) noexcept;
}  // extern "C"

#endif  // NEXTAI_OPENCUT_ZOIN_H_
