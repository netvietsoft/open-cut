// ============================================================================
// File: godzilla_acurate_asan_types.h
// Target: libgodzilla-acurate-asan.so (160,168 bytes, SHA-256: 0c89ab013365273e...)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Exact ABI data structures, GWP-ASan AllocatorState,
//                   AllocationMetadata (0x270 = 624 B), GuardedPoolAllocator
//                   (0xe8 = 232 B), CustomHookContext (0xa0 = 160 B),
//                   FaultHandlerConfig, RefRecordEntry (0x30 = 48 B), and
//                   .data / .bss layouts reconstructed from AArch64 opcodes.
// Mô tả (VN): Các cấu trúc dữ liệu chuẩn ABI, AllocatorState của GWP-ASan,
//             AllocationMetadata (0x270 = 624 B), GuardedPoolAllocator
//             (0xe8 = 232 B), CustomHookContext (0xa0 = 160 B),
//             FaultHandlerConfig, RefRecordEntry (0x30 = 48 B), cùng bố cục
//             .data / .bss khôi phục chính xác từ mã máy AArch64.
// ============================================================================

#pragma once

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <mutex>
#include <string>
#include <vector>
#include <jni.h>
#include <pthread.h>
#include <signal.h>

namespace gwp_asan {

// ============================================================================
// [EN] Error enum (verified from getErrorType @ 0x011088 and errorToString @ 0x013a08)
//      Lookup table in .rodata @ 0x02a0d8..0x02a108:
//      0 -> "Unknown"
//      1 -> "Use After Free"
//      2 -> "Double Free"
//      3 -> "Invalid (Wild) Free"
//      4 -> "Buffer Overflow"
//      5 -> "Buffer Underflow"
// [VN] Kiểu liệt kê lỗi GWP-ASan (đối chiếu từ getErrorType @ 0x011088 và
//      bảng chuỗi tại .rodata @ 0x02a0d8..0x02a108).
// ============================================================================
enum class Error : uint32_t {
    UNKNOWN           = 0,
    USE_AFTER_FREE    = 1,
    DOUBLE_FREE       = 2,
    INVALID_FREE      = 3,
    BUFFER_OVERFLOW   = 4,
    BUFFER_UNDERFLOW  = 5
};

// ============================================================================
// [EN] Options struct passed to GuardedPoolAllocator::init (@ 0x011464)
//      Constructed on stack at [sp, #0x40..#0x68] in initAcurateAsan (@ 0x00df28..0x00e018)
//      Total size: 0x28 (40 bytes)
// [VN] Cấu trúc Options truyền vào GuardedPoolAllocator::init (@ 0x011464)
//      Khởi tạo trên stack tại [sp, #0x40..#0x68] trong initAcurateAsan (@ 0x00df28..0x00e018)
// ============================================================================
struct Options {
    using Backtrace_t = size_t (*)(uintptr_t* trace_buffer, size_t max_depth);

    bool Enabled;                        // +0x00 (1 B)
    bool PerfectlyRightAlign;            // +0x01 (1 B)
    bool InstallForkHandlers;            // +0x02 (1 B)
    uint8_t _pad03;                      // +0x03 (1 B)
    int32_t MaxSimultaneousAllocations;  // +0x04 (4 B, default 16 / config.max_alloc)
    int32_t SampleRate;                  // +0x08 (4 B, default 5000 / config.sample_rate)
    uint32_t _pad0c;                     // +0x0C (4 B)
    Backtrace_t Backtrace;               // +0x10 (8 B, getBacktraceFastFP @ 0x01d5a8 or getBacktraceDwarf @ 0x01d684)
    uint64_t MaxAllocationSize;          // +0x18 (8 B, clamped to 1*page, 10*page, or 20*page @ 0x00dfa8)
    uint64_t AllocateRate;               // +0x20 (8 B, config.alloc_rate)
};
static_assert(sizeof(Options) == 0x28, "gwp_asan::Options must be 0x28 (40) bytes");

// ============================================================================
// [EN] AllocatorVersionMagic header (8 bytes at +0x00 of AllocatorState)
//      Initialized in GuardedPoolAllocator::init @ 0x011474:
//        mov w8, #0x4153; movk w8, #0x414e, lsl #16 -> "ASAN" (0x41,0x53,0x41,0x4e)
//        mov w8, #0x0002 -> Version = 2, Reserved = 0
// [VN] Header định danh phiên bản cấp phát (8 byte tại +0x00 của AllocatorState)
// ============================================================================
struct AllocatorVersionMagic {
    uint8_t Magic[4];     // +0x00: {'A', 'S', 'A', 'N'} (0x4e415341 LE)
    uint16_t Version;     // +0x04: 2 (0x0002)
    uint16_t Reserved;    // +0x06: 0 (0x0000)
};
static_assert(sizeof(AllocatorVersionMagic) == 0x08, "AllocatorVersionMagic must be 8 bytes");

// ============================================================================
// [EN] AllocatorState struct (embedded at +0x00..+0x58 of GuardedPoolAllocator)
//      Verified from:
//      - pointerIsMine @ 0x00eb28 / 0x011044:
//          ldr x9, [x0, #0x18] (GuardedPagePool); cmp x9, x1; b.hi false;
//          ldr x9, [x0, #0x20] (GuardedPagePoolEnd); cmp x9, x1; cset w0, hi
//      - slotToAddr @ 0x00eb58:
//          ldp x8, x9, [x0, #0x10] (PageSize, GuardedPagePool)
//          add x9, x9, x8; madd x8, x8, x1, x9; add x0, x8, x8, lsl #1 -> Pool + PageSize + 2*Slot*PageSize
//      - isGuardPage @ 0x00eb74:
//          ldp x8, x9, [x0, #0x10]; sub x9, x1, x9; lsr x10, x9, #12; udiv x8, x9, x8;
//          cmp x9, #0x1000; csel x8, x10, x8, eq; tst x8, #0x1; cset w0, eq
//      - MaxAllocationSize @ +0x30 (stored at 0x011484: str x9, [x0, #0x30])
//      - AllocateRate @ +0x38 (stored at 0x011488: str x9, [x0, #0x38])
//      - FreeSlotsSlip @ +0x40 (incremented in deallocate @ 0x011be4: ldr x9, [x19, #0x40]; add x9, x9, #1)
//      - FailureType @ +0x48 (written in trapOnAddress @ 0x011a10: str w2, [x0, #0x48])
//      - FailureAddress @ +0x50 (written in trapOnAddress @ 0x011a14: str x1, [x0, #0x50])
// [VN] Cấu trúc trạng thái bộ cấp phát (nhúng tại +0x00..+0x58 của GuardedPoolAllocator)
// ============================================================================
struct AllocatorState {
    AllocatorVersionMagic VersionMagic;  // +0x00 (8 B)
    size_t MaxSimultaneousAllocations;   // +0x08 (8 B)
    size_t PageSize;                     // +0x10 (8 B)
    uintptr_t GuardedPagePool;           // +0x18 (8 B)
    uintptr_t GuardedPagePoolEnd;        // +0x20 (8 B)
    uintptr_t CrashTriggerSortingPage;   // +0x28 (8 B, "GWP-ASan Guard Page" read-only trap page)
    size_t MaxAllocationSize;            // +0x30 (8 B)
    size_t AllocateRate;                 // +0x38 (8 B)
    size_t FreeSlotsSlip;                // +0x40 (8 B, counts slot overwrites when FreeSlots full)
    Error FailureType;                   // +0x48 (4 B)
    uint32_t PerfectlyRightAlign;        // +0x4C (4 B, 1 if PerfectlyRightAlign)
    uintptr_t FailureAddress;            // +0x50 (8 B)

    // [EN] Check whether `Ptr` points inside [GuardedPagePool, GuardedPagePoolEnd) (@ 0x00eb28)
    // [VN] Kiểm tra con trỏ `Ptr` có nằm trong vùng [GuardedPagePool, GuardedPagePoolEnd) (@ 0x00eb28)
    bool pointerIsMine(const void* Ptr) const noexcept;

    // [EN] Convert slot index to base address of the slot's data page (@ 0x00eb58)
    // [VN] Chuyển chỉ số slot sang địa chỉ cơ sở của trang dữ liệu (@ 0x00eb58)
    uintptr_t slotToAddr(size_t N) const noexcept;

    // [EN] Check whether `Ptr` falls on an even-indexed guard page (@ 0x00eb74)
    // [VN] Kiểm tra địa chỉ `Ptr` có rơi vào trang bảo vệ (chỉ số chẵn) hay không (@ 0x00eb74)
    bool isGuardPage(uintptr_t Ptr) const noexcept;

    // [EN] Convert address inside pool to slot index (@ 0x00eba0)
    // [VN] Chuyển địa chỉ trong vùng nhớ sang chỉ số slot (@ 0x00eba0)
    size_t addrToSlot(uintptr_t Ptr) const noexcept;

    // [EN] Find nearest slot index to an arbitrary address inside the pool (@ 0x00ebc4)
    // [VN] Tìm chỉ số slot gần nhất với địa chỉ bất kỳ trong vùng nhớ (@ 0x00ebc4)
    size_t getNearestSlot(uintptr_t Ptr) const noexcept;

    // [EN] Determine exact GWP-ASan error type for a fault address (@ 0x011088)
    // [VN] Xác định chính xác loại lỗi GWP-ASan cho địa chỉ gây lỗi (@ 0x011088)
    Error getErrorType(uintptr_t AccessPtr, bool DataWasDeallocated,
                       uintptr_t SlotAddr, size_t AllocSize) const noexcept;
};
static_assert(sizeof(AllocatorState) == 0x58, "gwp_asan::AllocatorState must be 0x58 (88) bytes");

// ============================================================================
// [EN] AllocationMetadata struct (0x270 = 624 bytes per slot)
//      Verified from GuardedPoolAllocator::init (@ 0x011510: mov w9, #0x270; mul x0, x8, x9)
//      and GuardedPoolAllocator::RecordAllocationMetadata (@ 0x0118ac) /
//      RecordDeallocation (@ 0x011958) / dumpErrorReport (@ 0x0134c0..0x0137d8):
//      - +0x000..+0x120: CallSiteInfo AllocationTrace
//          +0x000: uint8_t CompressedTrace[280] (kMaxTraceLengthToCollect = 280 B)
//          +0x118: uint64_t ThreadID (kInvalidThreadID = UINT64_MAX)
//          +0x120: size_t TraceSize (number of packed bytes)
//      - +0x128..+0x250: CallSiteInfo DeallocationTrace
//          +0x128: uint8_t CompressedTrace[280]
//          +0x240: uint64_t ThreadID
//          +0x248: size_t TraceSize
//      - +0x250: uintptr_t Addr (allocated user address)
//      - +0x258: size_t RequestedSize (original requested byte size)
//      - +0x260: size_t AllocatedSize (page-rounded byte size for mprotect)
//      - +0x268: bool IsDeallocated (1 byte + 7 bytes padding)
// [VN] Cấu trúc siêu dữ liệu cấp phát (0x270 = 624 byte mỗi slot), xác minh
//      từ mã máy tại 0x011510 (`mov w9, #0x270; mul x0, x8, x9`).
// ============================================================================
struct AllocationMetadata {
    static constexpr size_t kMaxTraceLengthToCollect = 280; // 0x118 bytes
    static constexpr size_t kMaxFrameDepth = 64;            // 0x40 frames

    struct CallSiteInfo {
        uint8_t CompressedTrace[kMaxTraceLengthToCollect]; // +0x000 (280 B)
        uint64_t ThreadID;                                 // +0x118 (8 B, default UINT64_MAX)
        size_t TraceSize;                                  // +0x120 (8 B, default 0)

        // [EN] Pack raw uintptr_t frames into variable-lengthzig-zag/LEB128 trace (@ 0x011904)
        // [VN] Nén mảng địa chỉ khung стек vào bộ đệm độ dài biến thiên (@ 0x011904)
        void RecordBacktrace(Options::Backtrace_t Backtrace);
    };
    static_assert(sizeof(CallSiteInfo) == 0x128, "CallSiteInfo must be 0x128 (296) bytes");

    CallSiteInfo AllocationTrace;    // +0x000..+0x128 (296 B)
    CallSiteInfo DeallocationTrace;  // +0x128..+0x250 (296 B)
    uintptr_t Addr;                  // +0x250 (8 B)
    size_t RequestedSize;            // +0x258 (8 B)
    size_t AllocatedSize;            // +0x260 (8 B)
    bool IsDeallocated;              // +0x268 (1 B)
    uint8_t _pad269[7];              // +0x269..+0x270 (7 B)

    // [EN] Initialize metadata for a new allocation (@ 0x0118ac)
    // [VN] Khởi tạo siêu dữ liệu cho một lần cấp phát mới (@ 0x0118ac)
    void RecordAllocation(uintptr_t AllocAddr, size_t Size, size_t PageRoundedSize);

    // [EN] Mark metadata as deallocated and clear DeallocationTrace (@ 0x011958)
    // [VN] Đánh dấu đã giải phóng và đặt lại DeallocationTrace (@ 0x011958)
    void RecordDeallocation();
};
static_assert(sizeof(AllocationMetadata) == 0x270, "gwp_asan::AllocationMetadata must be 0x270 (624) bytes");

// ============================================================================
// [EN] ThreadLocalPackedVariables (8 bytes per thread or global TLS state)
//      - Lower 31 bits: NextSampleCounter
//      - Bit 31 (0x80000000): RecursiveGuard boolean
//      - Upper 32 bits: RandomState (Xorshift32)
// [VN] Biến đóng gói cục bộ theo luồng (8 byte: bộ đếm lấy mẫu, cờ đệ quy, PRNG)
// ============================================================================
struct ThreadLocalPackedVariables {
    uint32_t NextSampleCounterAndGuard; // +0x00: [0..30]=Counter, [31]=RecursiveGuard
    uint32_t RandomState;               // +0x04: Xorshift32 state
};
static_assert(sizeof(ThreadLocalPackedVariables) == 0x08, "ThreadLocalPackedVariables must be 8 bytes");

// ============================================================================
// [EN] GuardedPoolAllocator class (0xe8 = 232 bytes)
//      Allocated via mmap(nullptr, 0xe8, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0)
//      in initAcurateAsan (@ 0x00dff4..0x00e000: mov w1, #0xe8; bl mmap).
//      Exact member offsets verified from GuardedPoolAllocator::init (@ 0x011464..0x0116c8):
//      - +0x00..+0x58: AllocatorState State (88 B)
//      - +0x58..+0x80: pthread_mutex_t PoolMutex (40 B on AArch64 Bionic)
//      - +0x80: size_t NumSampledAllocations (8 B)
//      - +0x88: size_t FreeSlotsLength (8 B)
//      - +0x90: AllocationMetadata* Metadata (8 B, array of MaxSimultaneousAllocations * 0x270)
//      - +0x98: size_t* FreeSlots (8 B, ring/array of MaxSimultaneousAllocations * 8)
//      - +0xa0: Options::Backtrace_t Backtrace (8 B)
//      - +0xa8: uint32_t AdjustedSampleRatePlusOne (4 B, SampleRate + 1, or 0 if disabled)
//      - +0xac: pthread_key_t ThreadLocalKey (4 B, created via pthread_key_create @ 0x01167c)
//      - +0xb0: bool ThreadLocalKeyCreated (1 B, set to 1 @ 0x011690: strb w21, [x19, #0xb0])
//      - +0xb1..+0xb8: padding (7 B)
//      - +0xb8: ThreadLocalPackedVariables FallbackLocals (8 B, initialized @ 0x00ddcc:
//               mov x8, #0xac5600000000; movk x8, #0x9e37, lsl #48 -> 0x9e37ac5600000000ULL)
//      - +0xc0: uint64_t TotalSampledCount (8 B, incremented in allocate @ 0x011728: ldr x8, [x19, #0xc0])
//      - +0xc8..+0xe8: Reserved / CrashInfo scratch area (32 B)
// [VN] Lớp GuardedPoolAllocator (0xe8 = 232 byte), cấp phát bằng mmap tại 0x00dff4.
// ============================================================================
class GuardedPoolAllocator {
public:
    AllocatorState State;                        // +0x00..+0x58 (88 B)
    pthread_mutex_t PoolMutex;                   // +0x58..+0x80 (40 B)
    size_t NumSampledAllocations;                // +0x80 (8 B)
    size_t FreeSlotsLength;                      // +0x88 (8 B)
    AllocationMetadata* Metadata;                // +0x90 (8 B)
    size_t* FreeSlots;                           // +0x98 (8 B)
    Options::Backtrace_t Backtrace;              // +0xa0 (8 B)
    uint32_t AdjustedSampleRatePlusOne;          // +0xa8 (4 B)
    pthread_key_t ThreadLocalKey;                // +0xac (4 B)
    bool ThreadLocalKeyCreated;                  // +0xb0 (1 B)
    uint8_t _padB1[7];                           // +0xb1..+0xb8 (7 B)
    ThreadLocalPackedVariables FallbackLocals;   // +0xb8..+0xc0 (8 B)
    uint64_t TotalSampledCount;                  // +0xc0..+0xc8 (8 B)
    uint64_t ReservedScratch[4];                 // +0xc8..+0xe8 (32 B)

    // [EN] Initialize pool, guard pages, metadata, and TLS key (@ 0x011464)
    // [VN] Khởi tạo vùng nhớ bảo vệ, siêu dữ liệu và khóa TLS (@ 0x011464)
    void init(const Options& Opts);

    // [EN] Allocate `Size` bytes in a guarded slot with mprotect RW (@ 0x0116d0)
    // [VN] Cấp phát `Size` byte trong một slot được bảo vệ với mprotect RW (@ 0x0116d0)
    void* allocate(size_t Size);

    // [EN] Deallocate `Ptr`, mprotect PROT_NONE, and record deallocation trace (@ 0x011a30)
    // [VN] Giải phóng `Ptr`, đặt mprotect PROT_NONE và lưu vết giải phóng (@ 0x011a30)
    void deallocate(void* Ptr);

    // [EN] Return original requested size of a guarded allocation (@ 0x011c18)
    // [VN] Trả về kích thước yêu cầu ban đầu của vùng nhớ được bảo vệ (@ 0x011c18)
    size_t getSize(const void* Ptr);

    // [EN] Exported symbol _ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error (@ 0x011a0c)
    //      Stores Error into State.FailureType (+0x48), Address into State.FailureAddress (+0x50),
    //      and writes 0 to *State.CrashTriggerSortingPage (+0x28) to trigger SIGSEGV!
    // [VN] Hàm xuất _ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error (@ 0x011a0c)
    //      Ghi mã lỗi vào +0x48, địa chỉ vào +0x50 và ghi vào trang chỉ đọc tại +0x28 để kích hoạt SIGSEGV!
    void trapOnAddress(uintptr_t Address, Error Err);

    // [EN] Should this allocation be sampled according to PRNG and AllocateRate? (inlined in hooks)
    // [VN] Kiểm tra xem lần cấp phát này có được lấy mẫu theo PRNG và AllocateRate không
    bool shouldSample() noexcept;

    // [EN] Reserve a slot index from FreeSlots or linearly up to MaxSimultaneousAllocations (@ 0x0117c8)
    // [VN] Dành riêng một chỉ số slot từ FreeSlots hoặc tuần tự (@ 0x0117c8)
    size_t reserveSlot() noexcept;

    // [EN] Free a slot index back into the FreeSlots ring/array (@ 0x011bb8)
    // [VN] Trả chỉ số slot về mảng FreeSlots (@ 0x011bb8)
    void freeSlot(size_t SlotIndex) noexcept;

    // [EN] Get pointer to ThreadLocalPackedVariables via pthread_getspecific (@ 0x0119c8)
    // [VN] Lấy con trỏ tới ThreadLocalPackedVariables qua pthread_getspecific (@ 0x0119c8)
    ThreadLocalPackedVariables* getThreadLocals() noexcept;
};
static_assert(sizeof(GuardedPoolAllocator) == 0xe8, "gwp_asan::GuardedPoolAllocator must be 0xe8 (232) bytes");

// ============================================================================
// [EN] Variable-length integer compression for stack traces (@ 0x01129c & @ 0x011320)
// [VN] Nén số nguyên độ dài biến thiên cho vết ngăn xếp (@ 0x01129c & @ 0x011320)
// ============================================================================
namespace compression {
size_t pack(const uintptr_t* Unpacked, size_t UnpackedSize,
            uint8_t* Packed, size_t PackedMaxSize) noexcept;
size_t unpack(const uint8_t* Packed, size_t PackedSize,
              uintptr_t* Unpacked, size_t UnpackedMaxSize) noexcept;
} // namespace compression

} // namespace gwp_asan

namespace godzilla_asan {

// ============================================================================
// [EN] TraceConfig and AcurateAsanConfig parsed from JSON in parseAcurateAsanConfig (@ 0x00ec3c)
//      Constructed on stack at [sp, #0x68..#0x100] in initAcurateAsan (@ 0x00dd8c..0x00dedc)
//      Total size: 0x98 (152 bytes):
//      - +0x00..+0x18: std::string target_lib (24 B)
//      - +0x18..+0x30: std::string alloc_func (24 B)
//      - +0x30..+0x48: std::string free_func (24 B)
//      - +0x48: uint32_t alloc_type (4 B: 0=malloc(size), 1=calloc/realloc(p,size), 2=fn(a,b,size), 3=fn(a,size))
//      - +0x4c: uint32_t free_type (4 B: 0=free(ptr), 1=fn(a,ptr), 2=fn(a,b,ptr))
//      - +0x50: uint32_t hook_type (4 B: 0=SHADOWHOOK_SHARED, 1=SHADOWHOOK_UNIQUE, 2=BYTEHOOK_SINGLE, 3=BYTEHOOK_PARTIAL, 4=BYTEHOOK_ALL)
//      - +0x54: uint32_t _pad54 (4 B)
//      - +0x58..+0x70: std::vector<std::string> partial_allow_list (24 B)
//      - +0x70..+0x88: std::vector<std::string> partial_ignore_list (24 B)
//      - +0x88: int32_t max_alloc (4 B, default 16)
//      - +0x8c: int32_t sample_rate (4 B, default 5000)
//      - +0x90: int32_t alloc_rate (4 B, default 50)
//      - +0x94: uint8_t right_align (1 B, default 0)
//      - +0x95: uint8_t enable_dwarf (1 B, default 0)
//      - +0x96: uint8_t recoverable (1 B, default 1)
//      - +0x97: uint8_t disable_jit (1 B, default 0)
// [VN] Cấu trúc cấu hình AcurateAsan phân tích từ chuỗi JSON tại 0x00ec3c.
// ============================================================================
struct TraceConfig {
    std::string target_lib;                        // +0x00 (24 B)
    std::string alloc_func;                        // +0x18 (24 B)
    std::string free_func;                         // +0x30 (24 B)
    uint32_t alloc_type;                           // +0x48 (4 B)
    uint32_t free_type;                            // +0x4C (4 B)
    uint32_t hook_type;                            // +0x50 (4 B)
    uint32_t _pad54;                               // +0x54 (4 B)
    std::vector<std::string> partial_allow_list;   // +0x58 (24 B)
    std::vector<std::string> partial_ignore_list;  // +0x70 (24 B)
};

struct AcurateAsanConfig {
    std::vector<TraceConfig> trace_configs;  // Parsed array of "trace_configs"
    int32_t max_alloc;                       // +0x88 (default 16)
    int32_t sample_rate;                     // +0x8C (default 5000)
    int32_t alloc_rate;                      // +0x90 (default 50)
    bool right_align;                        // +0x94 (default false)
    bool enable_dwarf;                       // +0x95 (default false)
    bool recoverable;                        // +0x96 (default true)
    bool disable_jit;                        // +0x97 (default false)
};

// ============================================================================
// [EN] CustomHookContext struct (0xa0 = 160 bytes)
//      Allocated via operator new(0xa0) in startCustomHooks (@ 0x014d94: mov w0, #0xa0; bl _Znwm)
//      Stored in g_custom_hook_contexts vector (@ 0x05e9c0, max 8 entries).
//      Exact layout verified from 0x014d9c..0x014e50 and template hooks <0>..<7> (@ 0x0168c4..0x01d2cc):
//      - +0x00..+0x88: TraceConfig config (136 B)
//      - +0x88: void* alloc_hook_stub (8 B, returned by shadowhook_hook_sym_name / bytehook_hook_*)
//      - +0x90: void* free_hook_stub (8 B)
//      - +0x98: void* orig_alloc_fn (8 B, saved by ShadowHook mode 0 or ByteHook)
//      - +0xa0 (or +0x9c): void* orig_free_fn
// [VN] Cấu trúc ngữ cảnh hook tùy chỉnh (0xa0 = 160 byte), cấp phát tại 0x014d94.
// ============================================================================
struct CustomHookContext {
    std::string target_lib;                        // +0x00 (24 B)
    std::string alloc_func;                        // +0x18 (24 B)
    std::string free_func;                         // +0x30 (24 B)
    uint32_t alloc_type;                           // +0x48 (4 B)
    uint32_t free_type;                            // +0x4C (4 B)
    uint32_t hook_type;                            // +0x50 (4 B)
    uint32_t index;                                // +0x54 (4 B, 0..7)
    std::vector<std::string> partial_allow_list;   // +0x58 (24 B)
    std::vector<std::string> partial_ignore_list;  // +0x70 (24 B)
    void* alloc_hook_stub;                         // +0x88 (8 B)
    void* free_hook_stub;                          // +0x90 (8 B)
    void* orig_alloc_fn;                           // +0x98 (8 B)
    void* orig_free_fn;                            // +0xA0 (in 64-bit host helper)
};

// ============================================================================
// [EN] Proxy Fault Handler structures parsed in parseFaultHandlerConfig (@ 0x01dfd4)
//      and executed in Java_..._initProxyFaultHandler (@ 0x01ed68):
//      Each symbol entry in the vector has size 0x38 (56 bytes):
//      - +0x00..+0x18: std::string lib_name ("libart.so", etc.)
//      - +0x18..+0x30: std::string symbol_name
//      - +0x30: bool check_scudo (1 B)
//      - +0x31: bool is_scudo (1 B)
// [VN] Cấu trúc cấu hình Proxy Fault Handler phân tích tại 0x01dfd4 và
//      thực thi trong initProxyFaultHandler (@ 0x01ed68).
// ============================================================================
struct FaultHandlerSymbolConfig {
    std::string lib_name;     // +0x00 (24 B)
    std::string symbol_name;  // +0x18 (24 B)
    bool check_scudo;         // +0x30 (1 B)
    bool is_scudo;            // +0x31 (1 B)
    uint8_t _pad32[6];        // +0x32..+0x38 (6 B)
};
static_assert(sizeof(FaultHandlerSymbolConfig) == 0x38, "FaultHandlerSymbolConfig must be 0x38 (56) bytes");

struct FaultHandlerConfig {
    bool enable;                                    // +0x00 (1 B)
    uint8_t _pad01[7];                              // +0x01..+0x08 (7 B)
    std::vector<FaultHandlerSymbolConfig> symbols;  // +0x08..+0x20 (24 B)

    std::string toString() const;
};

// ============================================================================
// [EN] GodzillaRefDebug structures (JNI GlobalRef tracking @ 0x01f810..0x021098)
//      1. RefRecordEntry (0x30 = 48 bytes per record):
//         Verified from RefDebugState::init (@ 0x0201f0: mul w8, w9, w8; add x0, x8, x8, lsl #1; lsl x0, x0, #4 -> N * 3 * 16 = 48 B)
//         and writeRecordEntry (@ 0x020938..0x020b4c) / printRecordEntry (@ 0x020c74):
//         - +0x00: uint32_t ref_value (lower 32 bits of jobject GlobalRef)
//         - +0x04: uint32_t seq_id (monotonic g_ref_alloc_seq @ 0x02e8f0 or g_ref_free_seq @ 0x02e8f4)
//         - +0x08: int16_t trace_depth (number of frames captured by getBacktraceFastFP)
//         - +0x0a: int16_t action_type (1 = NewGlobalRef, 2 = AddGlobalRef, -1 = DeleteGlobalRef)
//         - +0x0c: uint32_t _pad0c
//         - +0x10..+0x30: uintptr_t frames[4] (top 4 caller frames after skipping 2 hook frames)
//      2. RefBucket (0x10 = 16 bytes per bundle bucket):
//         Verified from NEON initialization loop at 0x0202ac..0x020354:
//         - +0x00: RefRecordEntry* records (points to `records_pool + bucket_idx * local_size * 48`)
//         - +0x08: uint32_t write_idx (next ring slot 0 .. local_size-1)
//         - +0x0c: uint32_t count (number of valid entries in bucket, max local_size)
//      3. RefDebugState (0x18 = 24 bytes):
//         Allocated at 0x020198 (`mov w0, #0x18; bl _Znwm`), stored at `0x05ea58`:
//         - +0x00: RefRecordEntry* records_pool
//         - +0x08: std::mutex* mutex_array (bundle_size mutexes)
//         - +0x10: RefBucket* buckets (bundle_size buckets)
//      4. RefTestArray (0x10 = 16 bytes):
//         Used by testcase2_1 (@ 0x01ffd4) and testcase2_2 (@ 0x020108):
//         - +0x00: int32_t count
//         - +0x04: int32_t _pad
//         - +0x08: jobject* refs
// [VN] Các cấu trúc theo dõi tham chiếu toàn cục JNI (GodzillaRefDebug @ 0x01f810..0x021098).
// ============================================================================
struct RefRecordEntry {
    uint32_t ref_value;     // +0x00 (4 B: lower 32 bits of jobject)
    uint32_t seq_id;        // +0x04 (4 B: g_ref_alloc_seq or g_ref_free_seq)
    int16_t trace_depth;    // +0x08 (2 B: frame count, max 4 stored)
    int16_t action_type;    // +0x0A (2 B: 1=NewGlobalRef, 2=AddGlobalRef, -1=DeleteGlobalRef)
    uint32_t _pad0C;        // +0x0C (4 B)
    uintptr_t frames[4];    // +0x10..+0x30 (32 B: 4 return addresses)
};
static_assert(sizeof(RefRecordEntry) == 0x30, "RefRecordEntry must be 0x30 (48) bytes");

struct RefBucket {
    RefRecordEntry* records;  // +0x00 (8 B)
    uint32_t write_idx;       // +0x08 (4 B)
    uint32_t count;           // +0x0C (4 B)
};
static_assert(sizeof(RefBucket) == 0x10, "RefBucket must be 0x10 (16) bytes");

struct RefDebugState {
    RefRecordEntry* records_pool;  // +0x00 (8 B)
    std::mutex* mutex_array;       // +0x08 (8 B)
    RefBucket* buckets;            // +0x10 (8 B)

    void init(uint32_t bundle_size, uint32_t local_size);
};
static_assert(sizeof(RefDebugState) == 0x18, "RefDebugState must be 0x18 (24) bytes");

struct RefTestArray {
    int32_t count;   // +0x00 (4 B)
    int32_t _pad04;  // +0x04 (4 B)
    jobject* refs;   // +0x08 (8 B)
};
static_assert(sizeof(RefTestArray) == 0x10, "RefTestArray must be 0x10 (16) bytes");

// ============================================================================
// [EN] RefHookContext in .bss @ 0x05e9f8..0x05ea48 (80 bytes):
//      Holds 5 shadowhook stubs (+0x00..+0x20) and 5 original function pointers (+0x28..+0x48)
// [VN] Ngữ cảnh hook của GodzillaRefDebug trong .bss @ 0x05e9f8..0x05ea48 (80 byte)
// ============================================================================
struct RefHookContext {
    void* stub_jni_false_new_global_ref;     // 0x05e9f8 (_ZN3art3JNIILb0EE12NewGlobalRefEP7_JNIEnvP8_jobject)
    void* stub_jni_true_new_global_ref;      // 0x05ea00 (_ZN3art3JNIILb1EE12NewGlobalRefEP7_JNIEnvP8_jobject)
    void* stub_javavmext_add_global_ref;     // 0x05ea08 (_ZN3art9JavaVMExt12AddGlobalRefEPNS_6ThreadENS_6ObjPtrINS_6mirror6ObjectEEE)
    void* stub_jni_false_delete_global_ref;  // 0x05ea10 (_ZN3art3JNIILb0EE15DeleteGlobalRefEP7_JNIEnvP8_jobject)
    void* stub_jni_true_delete_global_ref;   // 0x05ea18 (_ZN3art3JNIILb1EE15DeleteGlobalRefEP7_JNIEnvP8_jobject)
    void* orig_jni_false_new_global_ref;     // 0x05ea20
    void* orig_jni_true_new_global_ref;      // 0x05ea28
    void* orig_javavmext_add_global_ref;     // 0x05ea30
    void* orig_jni_false_delete_global_ref;  // 0x05ea38
    void* orig_jni_true_delete_global_ref;   // 0x05ea40
};
static_assert(sizeof(RefHookContext) == 0x50, "RefHookContext must be 0x50 (80) bytes");

} // namespace godzilla_asan
