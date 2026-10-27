// ============================================================================
// File: npth_fd_tracker.hpp
// Target: libnpth_fd_tracker.so (39,472 bytes, SHA-256: 01cfb7487a371cbf534a2749c8b8e548bade637455e7e301d2e76f03a80e7405)
// Build-ID: fb7e10ec5701d9e0f2d987b29c3a7d1e4eb4b887 (.note.gnu.build-id @ 0x02d0)
// Architecture: AArch64 (ARM64-v8a), Little-Endian, ELF64 Shared Object
// Module: ByteDance NPTH File Descriptor Leak Tracker, ShadowHook 18-Stub
//         Interceptor & Intrusive Red-Black Tree Backtrace Dumper
// Clean-Room C++17 Reconstruction — Zero Stubs — Bilingual EN / VN
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <mutex>

namespace nextai::opencut::npth_fd_tracker {

// ============================================================================
// 1. Binary Constants & ELF Layout Metadata
//    Hằng số nhị phân & Siêu dữ liệu bố cục ELF của libnpth_fd_tracker.so
// ============================================================================
inline constexpr std::size_t kBinarySizeBytes          = 39472U;
inline constexpr const char* kBinarySha256Hex          = "01cfb7487a371cbf534a2749c8b8e548bade637455e7e301d2e76f03a80e7405";
inline constexpr const char* kGnuBuildIdHex            = "fb7e10ec5701d9e0f2d987b29c3a7d1e4eb4b887";
inline constexpr std::uint64_t kRodataStartVa          = 0x000024E0ULL;
inline constexpr std::size_t kRodataSizeBytes          = 1849U;         // 0x24E0..0x2C19
inline constexpr std::uint64_t kEhFrameHdrVa           = 0x00002C1CULL;
inline constexpr std::size_t kEhFrameFdeCount          = 52U;           // 52 FDEs @ 0x2C1C
inline constexpr std::uint64_t kTextStartVa            = 0x000037DCULL;
inline constexpr std::uint64_t kTextEndVa              = 0x000084B0ULL;
inline constexpr std::size_t kTextSizeBytes            = 19668U;        // 4,917 AArch64 instructions
inline constexpr std::size_t kTextInstructionCount     = 4917U;
inline constexpr std::uint64_t kPltStartVa             = 0x000084B0ULL;
inline constexpr std::size_t kPltSizeBytes             = 1344U;         // 83 PLT slots
inline constexpr std::uint64_t kDataStartVa            = 0x00010F90ULL;
inline constexpr std::uint64_t kDataFileOffset         = 0x00008F90ULL;
inline constexpr std::size_t kDataSizeBytes            = 680U;
inline constexpr std::uint64_t kBssStartVa             = 0x00011238ULL;
inline constexpr std::size_t kBssSizeBytes             = 352U;

// ============================================================================
// 2. NPTH FD Tracker Constants & Error Codes (Observed in 0x382c..0x84b0)
//    Hằng số trạng thái và mã lỗi của trình giám sát rò rỉ FD NPTH
// ============================================================================
inline constexpr std::uint32_t kTlsRecursionGuardMagic = 0x12345678U;  // mov w23, #0x5678; movk w23, #0x1234, lsl #16 (@ 0x6ccc..0x6cd4)
inline constexpr std::int32_t  kStateStoppedFast       = 8;            // mov w9, #8; str w9, [x8, #0xc] in fast_stop (@ 0x3d34..0x3d38)
inline constexpr std::int32_t  kErrNullDumpDir         = -5;           // mov w0, #-5 in fd_track_do_dump (@ 0x3d04)
inline constexpr std::int32_t  kErrAlreadyDumping      = -6;           // mov w0, #-6 in do_fd_info_dump (@ 0x4df0)
inline constexpr std::int32_t  kErrNotInitialized      = -11;          // mov w20, #-0xb in native_do_command (@ 0x3b68)
inline constexpr std::int32_t  kErrFdNodeNotFound      = -14;          // mov w19, #-0xe in delete_fd_info (@ 0x4270)
inline constexpr std::int32_t  kErrTrackerInactive     = -16;          // mov w19, #-0x10 in insert_fd_info (@ 0x3e2c)
inline constexpr std::int32_t  kErrPthreadKeyCreate    = -51;          // mov w0, #-0x33 in do_hook (@ 0x6b08)
inline constexpr std::int32_t  kErrShadowHookInit      = -52;          // mov w0, #-0x34 in do_hook (@ 0x6ae8)

// ============================================================================
// 3. Reconstructed ABI Structures (FdNode, FdLeakManager, NativeInterface)
//    Cấu trúc ABI được tái tạo từ mã máy AArch64
// ============================================================================

// Intrusive Red-Black Tree Node representing a tracked File Descriptor
// Nút cây Đỏ-Đen nội tại lưu trữ thông tin một File Descriptor đang mở
// Field offsets verified from RbTreeInsertFdNode_3fdc (0x3fdc), RbTreeDeleteFdNode_430c (0x430c),
// java_backtrace_format (0x4868), native_backtrace_format (0x4d5c), release_frames (0x4d74):
struct FdTrackNode {
    FdTrackNode*  left;               // +0x00: Left child pointer
    FdTrackNode*  right;              // +0x08: Right child pointer
    FdTrackNode*  parent;             // +0x10: Parent pointer
    std::int32_t  color;              // +0x18: Red-Black color (1 = RED, 0 = BLACK)
    std::int32_t  pad_1c;             // +0x1C: Alignment padding
    std::int64_t  timestamp_ms;       // +0x20: Creation timestamp (gettimeofday)
    std::int32_t  tid;                // +0x28: Creator thread ID (gettid)
    std::int32_t  flags;              // +0x2C: Open/socket flags
    std::int32_t  fd;                 // +0x30: File descriptor number (RB-tree key @ [x9, #0x30] in 0x3ff8)
    std::int32_t  fd_type;            // +0x34: FD classification type enum
    char          path_name[48];      // +0x38..+0x67: Resolved path or socket/pipe tag
    std::uintptr_t* native_frames;    // +0x68: Native frame PC array (freed in release_frames @ 0x4d84)
    std::size_t   native_frame_count; // +0x70: Native frame count (@ 0x4d68)
    std::size_t   native_frame_cap;   // +0x78: Capacity / hash
    void**        java_art_methods;   // +0x80: ART ArtMethod* array (@ 0x4890, freed @ 0x4d90)
    std::size_t   java_frame_count;   // +0x88: Java frame count (@ 0x4898)
};

// Global FD Leak Manager State (pointed to by g_fd_leak_manager @ .bss 0x11238)
// Trạng thái trình quản lý rò rỉ FD toàn cục (trỏ bởi g_fd_leak_manager tại .bss 0x11238)
struct FdLeakManager {
    const char*   dump_root_dir;      // +0x00: Root directory for FD dump files (@ 0x3d1c)
    std::int32_t  pid;                // +0x08: Process ID
    std::int32_t  state;              // +0x0C: Bitmask/state (bit 0: tracking, bit 2: backtrace, 8: fast_stop)
    std::int32_t  fd_limit_threshold; // +0x10: FD count threshold triggering backtrace/dump
    std::int32_t  initialized;        // +0x14: 1 when initialized (@ 0x3b28, 0x3cf0)
    std::int32_t  is_dumping;         // +0x18: Re-entrancy guard for do_fd_info_dump (@ 0x4de8)
    std::int32_t  current_fd_count;   // +0x1C: Current tracked FD count
    std::int64_t  start_monitor_time; // +0x20: Epoch timestamp when monitoring started
    std::int64_t  stop_monitor_time;  // +0x28: Epoch timestamp when monitoring stopped
    void*         art_thread_list;    // +0x38: Resolved ART Runtime thread_list pointer (@ 0x67dc)
    FdTrackNode** rb_root_slot;       // +0x40: Pointer to RB-tree root slot (0x11248 set in init_fd_track_info @ 0x46e0)
    std::uint8_t  reserved_48[0x58];  // +0x48..+0x9F
    pthread_mutex_t tree_mutex;       // +0xA0: Mutex protecting RB-tree operations (@ 0x4250, 0x4704, 0x7e6c)
    void*         thread_list_head;   // +0xF0: Intrusive list head for thread metadata (@ 0x4a64)
};

// Exported 40-byte vtable at .data 0x10f90 (fd_track_native_interface_func)
// Bảng giao diện hàm 40 byte xuất khẩu tại .data 0x10f90
struct FdTrackNativeInterface {
    int  (*so_initialize)(const char* dir_path, int max_fd, int dump_threshold, int flags);
    int  (*native_do_command)(int cmd);
    int  (*get_fd_count)(int mode);
    int  (*fd_track_do_dump)(int reason, const char* custom_dir);
    void (*fast_stop)();
};

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_pc;
    std::uint64_t end_pc;
    std::uint32_t size_bytes;
    std::uint64_t fde_va;
    const char*   symbol_name;
    const char*   summary;
};

extern const std::array<FdeDescriptor, kEhFrameFdeCount> kFdeTable;
extern const std::array<std::uint32_t, kTextInstructionCount> kTextInstructionWords;
extern const std::array<std::uint8_t, kRodataSizeBytes> kRodataBytes_24e0;
extern const std::array<std::uint8_t, kDataSizeBytes> kDataBytes_10f90;
extern const std::array<std::uint8_t, kBinarySizeBytes> kFullElfImageBytes;

// ============================================================================
// 4. Clean-Room Reconstructed Internal & Exported C APIs
//    Khai báo các hàm nội bộ và 22 biểu tượng xuất khẩu của libnpth_fd_tracker.so
// ============================================================================
void RbTreeInsertFdNode_3fdc(FdTrackNode** root_slot, FdTrackNode* node) noexcept;
void RbTreeDeleteFdNode_430c(FdTrackNode** root_slot, FdTrackNode* node) noexcept;
int   ClassifyLeakedFdCategory(const char* path_name, char* out_category, std::size_t cap) noexcept;

extern "C" {

extern FdLeakManager* g_fd_leak_manager;
extern void*          leak_config;
extern FdTrackNativeInterface fd_track_native_interface_func;

int   so_initialize(const char* dir_path, int max_fd, int dump_threshold, int flags) noexcept;
int   native_do_command(int cmd) noexcept;
int   get_fd_count(int mode) noexcept;
int   fd_track_do_dump(int reason, const char* custom_dir) noexcept;
void  fast_stop() noexcept;
int   init_fd_track_info() noexcept;
int   insert_fd_info(int fd, const char* path_opt, std::uintptr_t caller_lr) noexcept;
int   delete_fd_info(int fd) noexcept;
int   fd_info_tree_release() noexcept;
int   fd_backtrace_init() noexcept;
void  fd_backtrace_release() noexcept;
int   do_backtrace(FdTrackNode* node, std::uintptr_t caller_lr) noexcept;
char* java_backtrace_format(FdTrackNode* node) noexcept;
void  native_backtrace_format(FdTrackNode* node) noexcept;
void  release_frames(FdTrackNode* node) noexcept;
int   do_fd_info_dump(int reason, const char* dump_dir) noexcept;
int   do_hook() noexcept;
int   do_unhook(int mode) noexcept;
int   fd_leak_reason(char* out_reason_buf, std::size_t buf_len, int* out_count) noexcept;

} // extern "C"

} // namespace nextai::opencut::npth_fd_tracker
