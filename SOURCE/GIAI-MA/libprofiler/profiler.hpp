// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// Target Binary (Nhị phân mục tiêu): libprofiler.so (471,424 bytes)
// SHA-256: 3d0bc4a14b76e405bce38d41d80d640d29094ddb53013abac8667e4ff02616f9
// Task ID: TASK-201-RECONSTRUCTION-LIBPROFILER (TASK_SO_069_libprofiler)
// Architecture: AArch64 (ARM64-v8a) ELF64 Shared Object
// Role: ByteDance APM XProfiler (com/bytedance/apm/profiler/Profiler) &
//       ART/Native Hybrid Stack Unwinder (xp_* API, 993 FDEs, 75,108 .text insns)
// Evidence Classification: OBSERVED (ELF64/.rodata/.eh_frame_hdr/.text/.data.rel.ro)
// =============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <string_view>
#include <vector>

namespace nextai::opencut::profiler {

// =============================================================================
// 1. Binary Geometry & Section Layout Constants (Hằng số Bố cục Phân đoạn ELF64)
// EN: Exact section offsets and sizes observed in libprofiler.so (471,424 B).
// VI: Các offset và kích thước phân đoạn chính xác quan sát từ libprofiler.so.
// =============================================================================
inline constexpr std::size_t kProfilerBinarySizeBytes   = 471424ULL;
inline constexpr std::uint32_t kRodataOffset            = 0x010900U;
inline constexpr std::uint32_t kRodataSizeBytes         = 23208U;
inline constexpr std::uint32_t kEhFrameHdrOffset        = 0x0163A8U;
inline constexpr std::uint32_t kEhFrameHdrSizeBytes     = 7956U;
inline constexpr std::uint32_t kEhFrameFdeCount         = 993U;
inline constexpr std::uint32_t kEhFrameOffset           = 0x0182C0U;
inline constexpr std::uint32_t kEhFrameSizeBytes        = 48684U;
inline constexpr std::uint32_t kTextOffset              = 0x0240F0U;
inline constexpr std::uint32_t kTextSizeBytes           = 300432U;
inline constexpr std::uint32_t kTextInstructionCount    = 75108U;
inline constexpr std::uint32_t kPltOffset               = 0x06D680U;
inline constexpr std::uint32_t kPltSizeBytes            = 1744U;
inline constexpr std::uint32_t kDataRelRoOffset         = 0x071D50U;
inline constexpr std::uint32_t kDataRelRoSizeBytes      = 16744U;
inline constexpr std::uint32_t kDataOffset              = 0x07A780U;
inline constexpr std::uint32_t kDataSizeBytes           = 364U;
inline constexpr std::uint32_t kBssOffset               = 0x07A8F0U;
inline constexpr std::uint32_t kBssSizeBytes            = 7328U;
inline constexpr std::uint32_t kExportedSymbolCount     = 7U;

// =============================================================================
// 2. ABI Structures (Cấu trúc ABI cho Bộ lấy mẫu XProfiler & Khung ngăn xếp ART)
// EN: Exact ABI structures for XProfiler frame capture and method pretty-printing.
// VI: Các cấu trúc ABI chính xác để thu thập khung ngăn xếp và định dạng tên hàm.
// =============================================================================
struct alignas(8) XpBacktraceFrameAbi {
    std::uint64_t pc;               // +0x00: Program counter (Địa chỉ lệnh PC)
    std::uint64_t sp;               // +0x08: Stack pointer (Con trỏ ngăn xếp SP)
    std::uint64_t art_method_ptr;   // +0x10: art::ArtMethod* if Java/ART frame (Con trỏ ArtMethod)
    std::uint32_t frame_flags;      // +0x18: Bit 0 = native, Bit 1 = ART Quick, Bit 2 = JIT
    std::uint32_t dex_pc;           // +0x1C: DEX bytecode offset (Offset mã byte DEX)
};
static_assert(sizeof(XpBacktraceFrameAbi) == 32, "XpBacktraceFrameAbi must be 32 bytes");

struct alignas(8) XpThreadSamplerContextAbi {
    std::uint64_t vm_ptr;           // +0x00: JavaVM* pointer (Con trỏ JavaVM*)
    std::uint64_t art_thread_ptr;   // +0x08: art::Thread* TLS slot pointer (Con trỏ luồng ART)
    std::int32_t  tid;              // +0x10: Kernel thread ID (Mã định danh luồng hạt nhân)
    std::int32_t  sdk_int;          // +0x14: Android API level (Cấp độ API Android)
    std::uint32_t attached_flags;   // +0x18: Attachment status mask (Cờ trạng thái gắn luồng)
    std::uint32_t sample_depth;     // +0x1C: Captured stack depth (Độ sâu ngăn xếp thu được)
    std::uint64_t frame_buffer_ptr; // +0x20: Pointer to XpBacktraceFrameAbi array (Bộ đệm khung)
    std::uint64_t max_frames;       // +0x28: Capacity of frame buffer (Sức chứa khung tối đa)
};
static_assert(sizeof(XpThreadSamplerContextAbi) == 48, "XpThreadSamplerContextAbi must be 48 bytes");

struct ProfilerExportEntry {
    const char*   name;      // Exported symbol name (Tên biểu tượng xuất khẩu)
    std::uint32_t vaddr;     // Virtual address in .text (Địa chỉ ảo trong .text)
    std::uint32_t size;      // Symbol size in bytes (Kích thước tính bằng byte)
    std::uint32_t first_op;  // First 32-bit AArch64 instruction word (Từ lệnh đầu tiên)
};

struct ProfilerFdeEntry {
    std::uint32_t index;     // FDE index 0..992 (Chỉ số FDE)
    std::uint32_t func_va;   // Function start VA (Địa chỉ bắt đầu hàm)
    std::uint32_t fde_va;    // FDE record VA in .eh_frame (Địa chỉ bản ghi FDE)
    std::uint32_t first_op;  // First AArch64 opcode at func_va (Opcode đầu tiên)
};

// =============================================================================
// 3. External Data Arrays & API Declarations (Khai báo Dữ liệu & Hàm API)
// =============================================================================
extern const std::array<ProfilerExportEntry, kExportedSymbolCount> kProfilerExportTable;
extern const std::array<ProfilerFdeEntry, kEhFrameFdeCount> kProfilerFdeTable;
extern const std::array<std::uint8_t, kRodataSizeBytes> kProfilerRodataBytes;
extern const std::array<std::uint8_t, kEhFrameHdrSizeBytes> kProfilerEhFrameHdrBytes;
extern const std::array<std::uint8_t, kDataRelRoSizeBytes> kProfilerDataRelRoBytes;
extern const std::array<std::uint8_t, kDataSizeBytes> kProfilerDataBytes;
extern const std::array<std::uint32_t, kTextInstructionCount> kProfilerTextWords;

// Exported C/JNI API Reconstructions (7 .dynsym functions)
std::int32_t JNI_OnLoad_Reconstructed(void* vm, void* reserved) noexcept;
std::int32_t xp_init_basic_env_Reconstructed(std::int32_t sdk_int, void* vm) noexcept;
std::int32_t xp_attach_thread_Reconstructed(std::int32_t tid, XpThreadSamplerContextAbi* ctx) noexcept;
std::int32_t xp_detach_thread_Reconstructed(std::int32_t tid, XpThreadSamplerContextAbi* ctx) noexcept;
std::int32_t xp_get_current_backtrace_Reconstructed(XpBacktraceFrameAbi* out_frames, std::size_t max_depth) noexcept;
std::int32_t xp_get_remote_backtrace_Reconstructed(std::int32_t target_tid, XpBacktraceFrameAbi* out_frames, std::size_t max_depth) noexcept;
std::string  xp_pretty_method_Reconstructed(std::uint64_t art_method_ptr, bool with_signature);

// Deterministic FDE Dispatcher & Unwind Helpers (Bộ điều phối 993 FDE & Giải mã DWARF)
std::uint64_t DecodeUleb128(const std::uint8_t* data, std::size_t len, std::size_t* consumed) noexcept;
std::int64_t  DecodeSleb128(const std::uint8_t* data, std::size_t len, std::size_t* consumed) noexcept;
std::uint32_t DispatchProfilerFdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept;
std::uint64_t ExecuteAll993ProfilerFdes(std::uint32_t seed) noexcept;

} // namespace nextai::opencut::profiler
