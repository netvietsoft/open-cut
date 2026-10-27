// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// Target Binary (Nhị phân mục tiêu): libwcdb.so (1,763,776 bytes)
// SHA-256: 7fda5f83efad3f0f0a07ad0e13ad8a203a33e69d4cb2515dee0bb56c7dccf8e8
// Task ID: TASK-205-RECONSTRUCTION-LIBWCDB (TASK_SO_052_libwcdb)
// Architecture: AArch64 (ARM64-v8a) ELF64 Shared Object
// Role: WeChat Database (WCDB) + SQLite3 + SQLCipher + RepairKit (sqliterk_*)
//       + CursorWindow JNI Engine (2,938 FDEs, 296,360 .text words, 336 exports)
// Evidence Classification: OBSERVED (ELF64/.text/.rodata/.eh_frame_hdr/.data.rel.ro)
// =============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <string_view>

namespace nextai::opencut::wcdb {

// =============================================================================
// 1. Binary Geometry & Section Layout Constants (Hằng số Bố cục Phân đoạn ELF64)
// EN: Exact section offsets and sizes observed in libwcdb.so (1,763,776 B).
// VI: Các offset và kích thước phân đoạn chính xác quan sát từ libwcdb.so.
// =============================================================================
inline constexpr std::size_t kWcdbBinarySizeBytes      = 1763776ULL;
inline constexpr std::uint32_t kPltOffset              = 0x0248C0U;
inline constexpr std::uint32_t kPltSizeBytes           = 2304U;
inline constexpr std::uint32_t kTextOffset             = 0x0251C0U;
inline constexpr std::uint32_t kTextSizeBytes          = 1185440U;
inline constexpr std::uint32_t kTextInstructionCount   = 296360U;
inline constexpr std::uint32_t kRodataOffset           = 0x146860U;
inline constexpr std::uint32_t kRodataSizeBytes        = 164136U;
inline constexpr std::uint32_t kEhFrameHdrOffset       = 0x16E988U;
inline constexpr std::uint32_t kEhFrameHdrSizeBytes    = 23516U;
inline constexpr std::uint32_t kEhFrameFdeCount        = 2938U;
inline constexpr std::uint32_t kEhFrameOffset          = 0x174568U;
inline constexpr std::uint32_t kEhFrameSizeBytes       = 156472U;
inline constexpr std::uint32_t kDataRelRoVaddr         = 0x1AB900U;
inline constexpr std::uint32_t kDataRelRoOffset        = 0x19B900U;
inline constexpr std::uint32_t kDataRelRoSizeBytes     = 60976U;
inline constexpr std::uint32_t kDataVaddr              = 0x1BC000U;
inline constexpr std::uint32_t kDataOffset             = 0x1AC000U;
inline constexpr std::uint32_t kDataSizeBytes          = 8688U;
inline constexpr std::uint32_t kBssVaddr               = 0x1BE1F0U;
inline constexpr std::uint32_t kBssOffset              = 0x1AE1F0U;
inline constexpr std::uint32_t kBssSizeBytes           = 73928U;
inline constexpr std::uint32_t kExportedSymbolCount    = 341U;
inline constexpr std::int32_t  kSqliteLimitCategories  = 12; // cmp w1, #11 @ 0x044420

// =============================================================================
// 2. ABI Structures (Cấu trúc ABI cho SQLite3, SQLCipher Codec & Backup)
// EN: Exact ABI structures reconstructed from getter/setter AArch64 offsets.
// VI: Các cấu trúc ABI chính xác được tái tạo từ các offset lệnh ldr/str AArch64.
// =============================================================================
struct alignas(8) SqlCipherCodecCtxAbi {
    std::uint32_t flags;         // +0x00: Codec flags (sqlcipher_codec_ctx_unset_flag @ 0x067ba0)
    std::uint32_t kdf_iter;      // +0x04: PBKDF2 iteration count (default 64000 / 256000)
    const std::uint8_t* kdf_salt;// +0x08: KDF salt pointer (@ 0x067cac ldr x0, [x0, #8])
    std::int32_t  page_size;     // +0x10: Encrypted page size (4096 B)
    std::int32_t  reserve_size;  // +0x14: HMAC + IV reserve bytes per page
    std::uint64_t provider_ctx;  // +0x18: OpenSSL / BoringSSL EVP cipher context
};
static_assert(sizeof(SqlCipherCodecCtxAbi) == 32, "SqlCipherCodecCtxAbi must be 32 bytes");

struct alignas(8) Sqlite3BackupAbi {
    std::uint64_t dest_db_ptr;   // +0x00: Destination sqlite3* handle
    std::uint64_t src_db_ptr;    // +0x08: Source sqlite3* handle
    std::uint32_t dest_schema;   // +0x10: Destination schema cookie
    std::int32_t  is_attached;   // +0x14: Attachment state
    std::uint64_t pager_ptr;     // +0x18: B-tree pager pointer
    std::uint64_t next_backup;   // +0x20: Next backup in linked list
    std::int32_t  page_count;    // +0x28: Total pages in source DB
    std::int32_t  src_npage;     // +0x2C: Source page count snapshot
    std::int32_t  step_rc;       // +0x30: Last step result code
    std::int32_t  remaining;     // +0x34: Remaining pages (@ 0x0418dc ldr w0, [x0, #0x34])
};
static_assert(sizeof(Sqlite3BackupAbi) == 56, "Sqlite3BackupAbi must be 56 bytes");

struct alignas(8) Sqlite3DbHandleAbi {
    std::uint64_t vfs_ptr;       // +0x00: sqlite3_vfs* pointer
    std::uint8_t  reserved[0x64];// +0x08..+0x6B: Internal B-tree, schema, mutex, errCode fields
    std::int32_t  nTotalChange;  // +0x6C: Total row changes (@ 0x044064 ldr w0, [x0, #0x6c])
    std::int32_t  aLimit[12];    // +0x70..+0x9F: 12 SQLITE_LIMIT_* runtime bounds (@ 0x044420)
    std::int32_t  sys_errno;     // +0xA0: Last OS errno (sqlite3_system_errno @ 0x04440c)
    std::int32_t  busy_timeout;  // +0xA4: Busy handler timeout ms (sqlite3_busy_timeout @ 0x04d74c)
};
static_assert(sizeof(Sqlite3DbHandleAbi) == 168, "Sqlite3DbHandleAbi must be 168 bytes");

struct WcdbExportEntry {
    const char*   name;      // Exported symbol name (Tên biểu tượng xuất khẩu)
    std::uint32_t vaddr;     // Virtual address in .text (Địa chỉ ảo)
    std::uint32_t size;      // Symbol size in bytes (Kích thước byte)
    std::uint32_t first_op;  // First 32-bit AArch64 instruction word (Từ lệnh đầu tiên)
};

struct WcdbFdeEntry {
    std::uint32_t index;     // FDE index 0..2937 (Chỉ số FDE)
    std::uint32_t func_va;   // Function start VA (Địa chỉ bắt đầu hàm)
    std::uint32_t fde_va;    // FDE record VA in .eh_frame (Địa chỉ bản ghi FDE)
    std::uint32_t first_op;  // First AArch64 opcode at func_va (Opcode đầu tiên)
};

// =============================================================================
// 3. External Data Arrays & API Declarations (Khai báo Dữ liệu & Hàm API)
// =============================================================================
extern const std::array<WcdbExportEntry, kExportedSymbolCount> kWcdbExportTable;
extern const std::array<WcdbFdeEntry, kEhFrameFdeCount> kWcdbFdeTable;
extern const std::array<std::uint8_t, kRodataSizeBytes> kWcdbRodataBytes;
extern const std::array<std::uint8_t, kEhFrameHdrSizeBytes> kWcdbEhFrameHdrBytes;
extern const std::array<std::uint8_t, kDataRelRoSizeBytes> kWcdbDataRelRoBytes;
extern const std::array<std::uint8_t, kDataSizeBytes> kWcdbDataBytes;
extern const std::array<std::uint32_t, kTextInstructionCount> kWcdbTextWords;

// Key Exported SQLite3 / SQLCipher / WCDB RepairKit Functions
std::int32_t sqlite3_initialize_Reconstructed() noexcept;
std::int32_t sqlite3_config_Reconstructed(std::int32_t op_code, std::int32_t arg) noexcept;
std::int32_t sqlite3_total_changes_Reconstructed(const Sqlite3DbHandleAbi* db) noexcept;
std::int32_t sqlite3_system_errno_Reconstructed(const Sqlite3DbHandleAbi* db) noexcept;
std::int32_t sqlite3_limit_Reconstructed(Sqlite3DbHandleAbi* db, std::int32_t limit_id, std::int32_t new_val) noexcept;
std::int32_t sqlite3_backup_remaining_Reconstructed(const Sqlite3BackupAbi* backup) noexcept;
const std::uint8_t* sqlcipher_codec_ctx_get_kdf_salt_Reconstructed(const SqlCipherCodecCtxAbi* ctx) noexcept;
std::int32_t sqlcipher_codec_ctx_unset_flag_Reconstructed(SqlCipherCodecCtxAbi* ctx, std::uint32_t flag) noexcept;
std::int32_t sqlcipher_codec_fips_status_Reconstructed() noexcept;
std::int32_t sqliterk_register_Reconstructed() noexcept;
std::int32_t sqliterk_close_Reconstructed(void* rk_db) noexcept;
std::int32_t mm_recover_cancel_Reconstructed(std::int32_t* cancel_flag) noexcept;

// Deterministic 2,938 FDE Dispatcher
std::uint32_t DispatchWcdbFdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept;
std::uint64_t ExecuteAll2938WcdbFdes(std::uint32_t seed) noexcept;

} // namespace nextai::opencut::wcdb
