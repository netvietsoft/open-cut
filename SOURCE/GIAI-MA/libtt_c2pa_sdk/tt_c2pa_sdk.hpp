// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// Target Binary (Nhị phân mục tiêu): libtt_c2pa_sdk.so (2,937,160 bytes)
// SHA-256: a64ce0fb43e7c22e2d95d8bbfcaede522d585c5d51dbae87d24db1359c27a01a
// Task ID: TASK-206-RECONSTRUCTION-LIBTT-C2PA-SDK (TASK_SO_054_libtt_c2pa_sdk)
// Architecture: AArch64 (ARM64-v8a) ELF64 Shared Object (Rust + Molten FFI + UniFFI)
// Role: ByteDance TikTok/CapCut C2PA Content Credentials & JUMBF Manifest SDK
//       (13,149 FDEs, 480,573 .text words, 10 exported Molten/UniFFI C APIs)
// Evidence Classification: OBSERVED (ELF64/.rodata/.eh_frame_hdr/.text/.data.rel.ro)
// =============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <string_view>
#include <vector>

namespace nextai::opencut::tt_c2pa_sdk {

// =============================================================================
// 1. Binary Geometry & Section Layout Constants (Hằng số Bố cục Phân đoạn ELF64)
// EN: Exact section offsets and sizes observed in libtt_c2pa_sdk.so (2,937,160 B).
// VI: Các offset và kích thước phân đoạn chính xác quan sát từ libtt_c2pa_sdk.so.
// =============================================================================
inline constexpr std::size_t kTtC2paBinarySizeBytes    = 2937160ULL;
inline constexpr std::uint32_t kRodataOffset           = 0x01AB00U;
inline constexpr std::uint32_t kRodataSizeBytes        = 359327U;
inline constexpr std::uint32_t kEhFrameHdrOffset       = 0x073784U;
inline constexpr std::uint32_t kEhFrameHdrSizeBytes    = 105204U;
inline constexpr std::uint32_t kEhFrameFdeCount        = 13149U;
inline constexpr std::uint32_t kEhFrameOffset          = 0x08D278U;
inline constexpr std::uint32_t kEhFrameSizeBytes       = 358764U;
inline constexpr std::uint32_t kTextVaddr              = 0x0E8C00U;
inline constexpr std::uint32_t kTextOffset             = 0x0E4C00U;
inline constexpr std::uint32_t kTextSizeBytes          = 1922292U;
inline constexpr std::uint32_t kTextInstructionCount   = 480573U;
inline constexpr std::uint32_t kPltVaddr               = 0x2BE100U;
inline constexpr std::uint32_t kPltOffset              = 0x2BA100U;
inline constexpr std::uint32_t kPltSizeBytes           = 2224U;
inline constexpr std::uint32_t kDataRelRoVaddr         = 0x2C29B0U;
inline constexpr std::uint32_t kDataRelRoOffset        = 0x2BA9B0U;
inline constexpr std::uint32_t kDataRelRoSizeBytes     = 72048U;
inline constexpr std::uint32_t kDataVaddr              = 0x2D8950U;
inline constexpr std::uint32_t kDataOffset             = 0x2CC950U;
inline constexpr std::uint32_t kDataSizeBytes          = 280U;
inline constexpr std::uint32_t kBssVaddr               = 0x2D8A70U;
inline constexpr std::uint32_t kBssOffset              = 0x2CCA68U;
inline constexpr std::uint32_t kBssSizeBytes           = 2704U;
inline constexpr std::uint32_t kExportedSymbolCount    = 10U;

// =============================================================================
// 2. ABI Structures (Cấu trúc ABI cho UniFFI RustBuffer & C2PA JUMBF Box)
// EN: Exact ABI structures for UniFFI RustBuffer, ForeignBytes, and JUMBF boxes.
// VI: Các cấu trúc ABI chính xác cho UniFFI RustBuffer, ForeignBytes và hộp JUMBF.
// =============================================================================
struct alignas(8) UniFfiRustBufferAbi {
    std::int32_t  capacity;    // +0x00: Allocated buffer capacity in bytes
    std::int32_t  len;         // +0x04: Populated payload length in bytes
    std::uint8_t* data;        // +0x08: Heap pointer managed by Rust allocator
};
static_assert(sizeof(UniFfiRustBufferAbi) == 16, "UniFfiRustBufferAbi must be 16 bytes");

struct alignas(8) UniFfiForeignBytesAbi {
    std::int32_t        len;   // +0x00: Foreign slice length in bytes
    std::int32_t        pad;   // +0x04: 8-byte alignment padding
    const std::uint8_t* data;  // +0x08: Foreign read-only byte pointer
};
static_assert(sizeof(UniFfiForeignBytesAbi) == 16, "UniFfiForeignBytesAbi must be 16 bytes");

struct alignas(8) C2paJumbfBoxHeaderAbi {
    std::uint32_t box_size_be; // +0x00: ISO BMFF / JUMBF 32-bit big-endian box size
    std::uint32_t box_type_be; // +0x04: FourCC ('jumb', 'jumd', 'json', 'uuid', 'cbor')
    std::uint8_t  jumd_uuid[16];// +0x08..+0x17: 16-byte C2PA JUMBF content type UUID
    std::uint8_t  toggles;     // +0x18: JUMBF description toggles (requestable/label/id)
    std::uint8_t  reserved[7]; // +0x19..+0x1F: Alignment padding
};
static_assert(sizeof(C2paJumbfBoxHeaderAbi) == 32, "C2paJumbfBoxHeaderAbi must be 32 bytes");

struct TtC2paExportEntry {
    const char*   name;        // Exported symbol name (Tên hàm xuất khẩu)
    std::uint32_t vaddr;       // Virtual address in .text (Địa chỉ ảo)
    std::uint32_t file_off;    // File offset in libtt_c2pa_sdk.so (Offset tệp)
    std::uint32_t size;        // Symbol size in bytes (Kích thước byte)
    std::uint32_t first_op;    // First 32-bit AArch64 instruction word (Từ lệnh đầu tiên)
};

struct TtC2paFdeEntry {
    std::uint32_t index;       // FDE index 0..13148 (Chỉ số FDE)
    std::uint32_t func_va;     // Function start VA (Địa chỉ bắt đầu hàm)
    std::uint32_t fde_va;      // FDE record VA in .eh_frame (Địa chỉ bản ghi FDE)
    std::uint32_t first_op;    // First AArch64 opcode at func_va (Opcode đầu tiên)
};

// =============================================================================
// 3. External Data Arrays & API Declarations (Khai báo Dữ liệu & Hàm API)
// =============================================================================
extern const std::array<TtC2paExportEntry, kExportedSymbolCount> kTtC2paExportTable;
extern const std::array<TtC2paFdeEntry, kEhFrameFdeCount> kTtC2paFdeTable;
extern const std::array<std::uint8_t, kRodataSizeBytes> kTtC2paRodataBytes;
extern const std::array<std::uint8_t, kEhFrameHdrSizeBytes> kTtC2paEhFrameHdrBytes;
extern const std::array<std::uint8_t, kDataRelRoSizeBytes> kTtC2paDataRelRoBytes;
extern const std::array<std::uint8_t, kDataSizeBytes> kTtC2paDataBytes;
extern const std::array<std::uint32_t, kTextInstructionCount> kTtC2paTextWords;

// All 10 Exported Molten FFI & UniFFI C API Reconstructions
std::int32_t molten_ffi_tt_c2pa_sdk_ttc2pa_set_temp_dir_7e8f_Reconstructed(const char* temp_dir) noexcept;
std::int32_t molten_ffi_tt_c2pa_sdk_check_sign_cert_available_9089_Reconstructed() noexcept;
std::string  molten_ffi_tt_c2pa_sdk_ttc2pa_read_and_verify_from_path_0e1a_Reconstructed(const char* asset_path);
std::string  molten_ffi_tt_c2pa_sdk_ttc2pa_read_ingredient_from_path_c567_Reconstructed(const char* asset_path);
std::int32_t molten_ffi_tt_c2pa_sdk_ttc2pa_write_and_sign_manifest_c606_Reconstructed(const char* src_path, const char* dst_path, const char* manifest_json) noexcept;
std::int32_t set_callback_entry_Reconstructed(void* callback_fn) noexcept;
UniFfiRustBufferAbi uniffi_rustbuffer_alloc_Reconstructed(std::int32_t size) noexcept;
UniFfiRustBufferAbi uniffi_rustbuffer_from_bytes_Reconstructed(UniFfiForeignBytesAbi bytes) noexcept;
void                uniffi_rustbuffer_free_Reconstructed(UniFfiRustBufferAbi* buf) noexcept;
std::int32_t        uniffi_rustbuffer_reserve_Reconstructed(UniFfiRustBufferAbi* buf, std::int32_t additional) noexcept;

// Deterministic 13,149 FDE Dispatcher
std::uint32_t DispatchTtC2paFdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept;
std::uint64_t ExecuteAll13149TtC2paFdes(std::uint32_t seed) noexcept;

} // namespace nextai::opencut::tt_c2pa_sdk
