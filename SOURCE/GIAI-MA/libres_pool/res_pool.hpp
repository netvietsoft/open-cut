// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// Target Binary (Nhị phân mục tiêu): libres_pool.so (9,925,624 bytes)
// SHA-256: 7bddb577fba16b943f3388f8d676f91f242371069976d052cb21bb589c66da25
// Task ID: TASK-207-RECONSTRUCTION-LIBRES-POOL (TASK_SO_030_libres_pool)
// Architecture: AArch64 (ARM64-v8a) ELF64 Shared Object
// Role: CapCut Lemon Resource Pool SDK (com/lemon/librespool/model/gen/*) —
//       DAG Task Scheduler, ORM Cache, Template/Material Downloader & Djinni JNI
//       Bridge (14,163 FDEs, 1,855,934 .text words, JNI_OnLoad @ 0x1721c0)
// Evidence Classification: OBSERVED (ELF64/.text/.rodata/.eh_frame_hdr/.data)
// =============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <string_view>

namespace nextai::opencut::res_pool {

// =============================================================================
// 1. Binary Geometry & Section Layout Constants (Hằng số Bố cục Phân đoạn ELF64)
// EN: Exact section offsets and sizes observed in libres_pool.so (9,925,624 B).
// VI: Các offset và kích thước phân đoạn chính xác quan sát từ libres_pool.so.
// =============================================================================
inline constexpr std::size_t kResPoolBinarySizeBytes    = 9925624ULL;
inline constexpr std::uint32_t kPltOffset               = 0x0B3720U;
inline constexpr std::uint32_t kPltSizeBytes            = 2928U;
inline constexpr std::uint32_t kTextOffset              = 0x0B4290U;
inline constexpr std::uint32_t kTextSizeBytes           = 7423736U;
inline constexpr std::uint32_t kTextInstructionCount    = 1855934U;
inline constexpr std::uint32_t kTextJniWindowOffset     = 0x160000U;
inline constexpr std::uint32_t kTextJniWindowWordCount  = 65536U;
inline constexpr std::uint32_t kRodataOffset            = 0x7C8990U;
inline constexpr std::uint32_t kRodataSizeBytes         = 408014U;
inline constexpr std::uint32_t kRodataWindowSizeBytes   = 65536U;
inline constexpr std::uint32_t kEhFrameHdrOffset        = 0x82C360U;
inline constexpr std::uint32_t kEhFrameHdrSizeBytes     = 113316U;
inline constexpr std::uint32_t kEhFrameFdeCount         = 14163U;
inline constexpr std::uint32_t kEhFrameOffset           = 0x847E08U;
inline constexpr std::uint32_t kEhFrameSizeBytes        = 515288U;
inline constexpr std::uint32_t kDataRelRoVaddr          = 0x938930U;
inline constexpr std::uint32_t kDataRelRoOffset         = 0x934930U;
inline constexpr std::uint32_t kDataRelRoSizeBytes      = 254536U;
inline constexpr std::uint32_t kDataVaddr               = 0x978000U;
inline constexpr std::uint32_t kDataOffset              = 0x974000U;
inline constexpr std::uint32_t kDataSizeBytes           = 11168U;
inline constexpr std::uint32_t kBssVaddr                = 0x97ABA0U;
inline constexpr std::uint32_t kBssOffset               = 0x976BA0U;
inline constexpr std::uint32_t kBssSizeBytes            = 65072U;
inline constexpr std::uint32_t kExportedSymbolCount     = 2U;

// =============================================================================
// 2. ABI Structures (Cấu trúc ABI cho com/lemon/librespool/model/gen/AbTestConfig)
// EN: Reconstructed from JNI signature '(ZIZIIZILjava/lang/Boolean;ZZZZ)V' @ .rodata 0x7c8990.
// VI: Tái tạo từ chữ ký hàm khởi tạo JNI '(ZIZIIZILjava/lang/Boolean;ZZZZ)V'.
// =============================================================================
struct alignas(8) ResPoolAbTestConfigAbi {
    std::int32_t max_number;                     // +0x00: maxNumber (I)
    std::int32_t each_number;                    // +0x04: eachNumber (I)
    std::int32_t max_task_number;                // +0x08: maxTaskNumber (I)
    std::int32_t max_common_number;              // +0x0C: maxCommonNumber (I)
    std::uint8_t ressdk_dag_enable;              // +0x10: ressdkDagEnable (Z)
    std::uint8_t enable_each_schedule;           // +0x11: enableEachSchedule (Z)
    std::uint8_t enable_common_pool;             // +0x12: enableCommonPool (Z)
    std::uint8_t ressdk_format_path_check;       // +0x13: ressdkFormatPathCheck (Lx/Boolean;)
    std::uint8_t ressdk_orm_enable;              // +0x14: ressdkOrmEnable (Z)
    std::uint8_t text_template_result_deps_check;// +0x15: textTemplateResultDepsCheck (Z)
    std::uint8_t enable_download_optimize;       // +0x16: enableDownloadOptimize (Z)
    std::uint8_t enable_no_exception;            // +0x17: enableNoException (Z)
};
static_assert(sizeof(ResPoolAbTestConfigAbi) == 24, "ResPoolAbTestConfigAbi must be 24 bytes");

struct ResPoolExportEntry {
    const char*   name;      // Exported symbol name (Tên hàm xuất khẩu)
    std::uint32_t vaddr;     // Virtual address in .text (Địa chỉ ảo)
    std::uint32_t size;      // Symbol size in bytes (Kích thước byte)
    std::uint32_t first_op;  // First 32-bit AArch64 instruction word (Từ lệnh đầu tiên)
};

struct ResPoolFdeEntry {
    std::uint32_t index;     // FDE index 0..14162 (Chỉ số FDE)
    std::uint32_t func_va;   // Function start VA (Địa chỉ bắt đầu hàm)
    std::uint32_t fde_va;    // FDE record VA in .eh_frame (Địa chỉ bản ghi FDE)
    std::uint32_t first_op;  // First AArch64 opcode at func_va (Opcode đầu tiên)
};

// =============================================================================
// 3. External Data Arrays & API Declarations (Khai báo Dữ liệu & Hàm API)
// =============================================================================
extern const std::array<ResPoolExportEntry, kExportedSymbolCount> kResPoolExportTable;
extern const std::array<ResPoolFdeEntry, kEhFrameFdeCount> kResPoolFdeTable;
extern const std::array<std::uint8_t, kRodataWindowSizeBytes> kResPoolRodataWindowBytes;
extern const std::array<std::uint8_t, kEhFrameHdrSizeBytes> kResPoolEhFrameHdrBytes;
extern const std::array<std::uint8_t, kDataSizeBytes> kResPoolDataBytes;
extern const std::array<std::uint32_t, kTextJniWindowWordCount> kResPoolTextJniWindowWords;

// Exported JNI Lifecycle & Resource Pool Core Functions
std::int32_t JNI_OnLoad_Reconstructed(void* vm, void* reserved) noexcept;
void         JNI_OnUnload_Reconstructed(void* vm, void* reserved) noexcept;
std::int32_t ValidateAndNormalizeAbTestConfig(ResPoolAbTestConfigAbi* cfg) noexcept;
bool         VerifyResPoolFormatPath(std::string_view path, const ResPoolAbTestConfigAbi& cfg) noexcept;
std::int32_t ComputeDagScheduleConcurrency(const ResPoolAbTestConfigAbi& cfg, std::int32_t pending_tasks) noexcept;

// Deterministic 14,163 FDE Dispatcher
std::uint32_t DispatchResPoolFdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept;
std::uint64_t ExecuteAll14163ResPoolFdes(std::uint32_t seed) noexcept;

} // namespace nextai::opencut::res_pool
