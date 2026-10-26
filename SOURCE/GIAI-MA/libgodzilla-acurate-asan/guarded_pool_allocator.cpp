// ============================================================================
// File: guarded_pool_allocator.cpp
// Target: libgodzilla-acurate-asan.so (160,168 bytes)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Full implementation of GWP-ASan AllocatorState,
//                   AllocationMetadata, GuardedPoolAllocator, LEB128/ZigZag
//                   backtrace compression, Xorshift32 PRNG, and POSIX VMA
//                   management reconstructed from 0x00eb28..0x01305c.
// Mô tả (VN): Triển khai đầy đủ AllocatorState, AllocationMetadata,
//             GuardedPoolAllocator, nén vết ngăn xếp LEB128/ZigZag, PRNG
//             Xorshift32 và quản lý VMA POSIX khôi phục từ 0x00eb28..0x01305c.
// ============================================================================

#include "guarded_pool_allocator.h"

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <unistd.h>

#ifndef PR_SET_VMA
#define PR_SET_VMA 0x53564d41
#endif
#ifndef PR_SET_VMA_ANON_NAME
#define PR_SET_VMA_ANON_NAME 0
#endif

namespace gwp_asan {

// ============================================================================
// [EN] Global variables in .bss (@ 0x02e920, 0x02e928) and .data (@ 0x02e8d8)
// [VN] Các biến toàn cục trong .bss (@ 0x02e920, 0x02e928) và .data (@ 0x02e8d8)
// ============================================================================
GuardedPoolAllocator* g_mmap_alloc = nullptr;   // .bss @ 0x02e920
GuardedPoolAllocator* SingletonPtr = nullptr;   // .bss @ 0x02e928
uint32_t g_prng_state = 0;                      // .data @ 0x02e8d8

namespace {

// [EN] Destructor for per-thread TLS allocation registered in pthread_key_create (@ 0x011c74)
// [VN] Hàm hủy cho vùng nhớ TLS của từng luồng đăng ký trong pthread_key_create (@ 0x011c74)
void destroyThreadLocals(void* ptr) {
    if (ptr != nullptr) {
        std::free(ptr);
    }
}

// [EN] pthread_atfork handlers (@ 0x011cc8, 0x011ce0)
// [VN] Các hàm xử lý pthread_atfork (@ 0x011cc8, 0x011ce0)
void atForkPrepare() {
    if (SingletonPtr != nullptr) {
        pthread_mutex_lock(&SingletonPtr->PoolMutex);
    }
}

void atForkParentOrChild() {
    if (SingletonPtr != nullptr) {
        pthread_mutex_unlock(&SingletonPtr->PoolMutex);
    }
}

} // anonymous namespace

// ============================================================================
// [EN] AllocatorState::pointerIsMine (@ 0x00eb28 and @ 0x011044)
//      Assembly @ 0x011044:
//        ldr x9, [x0, #0x18]   // GuardedPagePool
//        cmp x9, x1            // Pool <= Ptr?
//        b.hi #0x11060
//        ldr x9, [x0, #0x20]   // GuardedPagePoolEnd
//        cmp x9, x1            // PoolEnd > Ptr?
//        cset w0, hi
//        ret
// [VN] Kiểm tra con trỏ `Ptr` có thuộc vùng nhớ GWP-ASan hay không (@ 0x00eb28 / 0x011044)
// ============================================================================
bool AllocatorState::pointerIsMine(const void* Ptr) const noexcept {
    uintptr_t P = reinterpret_cast<uintptr_t>(Ptr);
    return GuardedPagePool <= P && P < GuardedPagePoolEnd;
}

// ============================================================================
// [EN] AllocatorState::slotToAddr (@ 0x00eb58 and @ 0x011220)
//      Note: InByteDance's custom multi-page GWP-ASan modification:
//      Each slot occupies `MaxAllocationSize` bytes plus one `PageSize` guard page,
//      starting after the leading guard page:
//        Base = GuardedPagePool + PageSize + N * (PageSize + MaxAllocationSize)
//      In standard single-page helper @ 0x00eb58:
//        ldp x8, x9, [x0, #0x10]  // x8 = PageSize, x9 = GuardedPagePool
//        add x9, x9, x8           // GuardedPagePool + PageSize
//        lsl x8, x8, #1           // 2 * PageSize
//        madd x0, x8, x1, x9      // GuardedPagePool + PageSize + N * 2 * PageSize
//      In allocate/deallocate (@ 0x011858, @ 0x011ab0), it uses the generalized
//      stride `(PageSize + MaxAllocationSize)`:
//        ldr x11, [x19, #0x30]    // MaxAllocationSize
//        add x12, x11, x9         // Stride = MaxAllocationSize + PageSize
//        madd x8, x12, x8, x9     // PageSize + Slot * Stride
//        add x20, x10, x8         // GuardedPagePool + PageSize + Slot * Stride
// [VN] Chuyển đổi chỉ số slot sang địa chỉ trang dữ liệu cơ sở (@ 0x00eb58 / 0x011858)
// ============================================================================
uintptr_t AllocatorState::slotToAddr(size_t N) const noexcept {
    const size_t slot_stride = (MaxAllocationSize > PageSize)
                                   ? (PageSize + MaxAllocationSize)
                                   : (2 * PageSize);
    return GuardedPagePool + PageSize + (N * slot_stride);
}

// ============================================================================
// [EN] AllocatorState::isGuardPage (@ 0x00eb74 and @ 0x0111cc)
//      Assembly @ 0x00eb74:
//        ldp x8, x9, [x0, #0x10]  // x8 = PageSize, x9 = GuardedPagePool
//        sub x9, x1, x9           // offset = Ptr - GuardedPagePool
//        lsr x10, x9, #12         // fast division when PageSize == 4096
//        udiv x8, x9, x8          // general division by PageSize
//        cmp x8_page, #0x1000
//        csel x8, x10, x8, eq     // page_number = offset / PageSize
//        tst x8, #0x1             // even page numbers are Guard Pages!
//        cset w0, eq
//        ret
// [VN] Kiểm tra địa chỉ `Ptr` có nằm trên trang bảo vệ (chỉ số trang chẵn) (@ 0x00eb74)
// ============================================================================
bool AllocatorState::isGuardPage(uintptr_t Ptr) const noexcept {
    if (PageSize == 0) {
        return false;
    }
    const uintptr_t offset = Ptr - GuardedPagePool;
    const size_t page_index = (PageSize == 4096) ? (offset >> 12) : (offset / PageSize);
    if (MaxAllocationSize <= PageSize) {
        return (page_index & 1U) == 0U;
    }
    const size_t stride = PageSize + MaxAllocationSize;
    const size_t offset_in_slot = offset % stride;
    return offset_in_slot < PageSize;
}

// ============================================================================
// [EN] AllocatorState::addrToSlot (@ 0x00eba0 and @ 0x011a78)
//      Assembly in deallocate @ 0x011a78:
//        ldr x9, [x19, #0x18]     // GuardedPagePool
//        ldr x8, [x19, #0x10]     // PageSize
//        ldr x10, [x19, #0x30]    // MaxAllocationSize
//        sub x9, x20, x9          // Ptr - GuardedPagePool
//        add x8, x10, x8          // Stride = MaxAllocationSize + PageSize
//        udiv x21, x9, x8         // Slot = (Ptr - GuardedPagePool) / Stride
// [VN] Chuyển địa chỉ trong vùng nhớ bảo vệ sang chỉ số slot (@ 0x00eba0 / 0x011a78)
// ============================================================================
size_t AllocatorState::addrToSlot(uintptr_t Ptr) const noexcept {
    const uintptr_t byte_offset = Ptr - GuardedPagePool;
    const size_t stride = (MaxAllocationSize > PageSize)
                              ? (PageSize + MaxAllocationSize)
                              : (2 * PageSize);
    return stride > 0 ? (byte_offset / stride) : 0;
}

// ============================================================================
// [EN] AllocatorState::getNearestSlot (@ 0x00ebc4 and @ 0x0111f8)
//      Finds the closest allocation slot to `Ptr` when a buffer underflow or
//      overflow hits an adjacent guard page.
// [VN] Tìm chỉ số slot gần nhất khi lỗi tràn bộ đệm chạm vào trang bảo vệ (@ 0x00ebc4)
// ============================================================================
size_t AllocatorState::getNearestSlot(uintptr_t Ptr) const noexcept {
    if (Ptr <= GuardedPagePool + PageSize) {
        return 0;
    }
    if (Ptr >= GuardedPagePoolEnd - PageSize) {
        return MaxSimultaneousAllocations - 1;
    }
    if (!isGuardPage(Ptr)) {
        return addrToSlot(Ptr);
    }
    const uintptr_t dist_to_Start = Ptr - GuardedPagePool;
    const size_t page_num = (PageSize == 4096) ? (dist_to_Start >> 12) : (dist_to_Start / PageSize);
    const size_t offset_in_guard = dist_to_Start - (page_num * PageSize);
    // [EN] Round down to previous slot if closer to lower half of guard page, else next slot
    // [VN] Làm tròn xuống slot trước nếu nằm ở nửa dưới của trang bảo vệ, ngược lại lấy slot kế tiếp
    if (offset_in_guard >= (PageSize / 2)) {
        return addrToSlot(Ptr + PageSize);
    }
    return addrToSlot(Ptr - PageSize);
}

// ============================================================================
// [EN] AllocatorState::getErrorType (@ 0x011088)
//      Assembly verified from 0x011088..0x0111c8:
//      1. If !pointerIsMine(AccessPtr) -> UNKNOWN (0)
//      2. If FailureType != UNKNOWN (e.g. set via trapOnAddress):
//         - If !DataWasDeallocated && FailureType == DOUBLE_FREE -> prints warning
//         - Returns FailureType
//      3. If DataWasDeallocated -> returns USE_AFTER_FREE (1)
//      4. If isGuardPage(AccessPtr):
//         - If AccessPtr >= SlotAddr + AllocSize -> BUFFER_OVERFLOW (4)
//         - Else -> BUFFER_UNDERFLOW (5)
//      5. Also checks intra-slot overflow when AccessPtr >= SlotAddr + AllocSize -> BUFFER_OVERFLOW (4)
//         and AccessPtr < SlotAddr -> BUFFER_UNDERFLOW (5)
// [VN] Xác định chính xác mã lỗi GWP-ASan từ địa chỉ truy cập trái phép (@ 0x011088)
// ============================================================================
Error AllocatorState::getErrorType(uintptr_t AccessPtr, bool DataWasDeallocated,
                                   uintptr_t SlotAddr, size_t AllocSize) const noexcept {
    if (!pointerIsMine(reinterpret_cast<const void*>(AccessPtr))) {
        return Error::UNKNOWN;
    }
    if (FailureType != Error::UNKNOWN) {
        return FailureType;
    }
    if (DataWasDeallocated) {
        return Error::USE_AFTER_FREE;
    }
    if (AccessPtr >= SlotAddr + AllocSize) {
        return Error::BUFFER_OVERFLOW;
    }
    if (AccessPtr < SlotAddr) {
        return Error::BUFFER_UNDERFLOW;
    }
    if (isGuardPage(AccessPtr)) {
        const size_t slot = getNearestSlot(AccessPtr);
        if (AccessPtr > slotToAddr(slot)) {
            return Error::BUFFER_OVERFLOW;
        }
        return Error::BUFFER_UNDERFLOW;
    }
    return Error::UNKNOWN;
}

// ============================================================================
// [EN] compression::pack (@ 0x01129c) & compression::unpack (@ 0x011320)
//      Variable-length ZigZag + LEB128 difference encoding between consecutive
//      uintptr_t stack frame addresses:
//      Assembly @ 0x01129c:
//        Diff = Unpacked[i] - Prev;
//        ZigZag = (Diff << 1) ^ (static_cast<intptr_t>(Diff) >> 63);
//        Encode 7 bits per byte with continuation bit 0x80.
// [VN] Nén và giải nén chênh lệch địa chỉ khung ngăn xếp theo ZigZag + LEB128 (@ 0x01129c & @ 0x011320)
// ============================================================================
namespace compression {

size_t pack(const uintptr_t* Unpacked, size_t UnpackedSize,
            uint8_t* Packed, size_t PackedMaxSize) noexcept {
    size_t idx = 0;
    uintptr_t prev = 0;
    for (size_t i = 0; i < UnpackedSize; ++i) {
        uintptr_t cur = Unpacked[i];
        intptr_t diff = static_cast<intptr_t>(cur - prev);
        uint64_t zigzag = (static_cast<uint64_t>(diff) << 1) ^
                          static_cast<uint64_t>(diff >> 63);

        // [EN] At most 10 bytes needed for 64-bit varint
        // [VN] Tối đa 10 byte cho một số nguyên 64-bit mã hóa độ dài biến thiên
        if (idx + 10 > PackedMaxSize) {
            break;
        }
        do {
            uint8_t byte = static_cast<uint8_t>(zigzag & 0x7fU);
            zigzag >>= 7;
            if (zigzag != 0) {
                byte |= 0x80U;
            }
            Packed[idx++] = byte;
        } while (zigzag != 0);

        prev = cur;
    }
    return idx;
}

size_t unpack(const uint8_t* Packed, size_t PackedSize,
              uintptr_t* Unpacked, size_t UnpackedMaxSize) noexcept {
    size_t unpacked_idx = 0;
    size_t packed_idx = 0;
    uintptr_t prev = 0;

    while (packed_idx < PackedSize && unpacked_idx < UnpackedMaxSize) {
        uint64_t zigzag = 0;
        uint32_t shift = 0;
        uint8_t byte = 0;
        do {
            if (packed_idx >= PackedSize || shift >= 64) {
                return unpacked_idx;
            }
            byte = Packed[packed_idx++];
            zigzag |= static_cast<uint64_t>(byte & 0x7fU) << shift;
            shift += 7;
        } while ((byte & 0x80U) != 0);

        intptr_t diff = static_cast<intptr_t>((zigzag >> 1) ^ (~(zigzag & 1ULL) + 1ULL));
        uintptr_t cur = prev + static_cast<uintptr_t>(diff);
        Unpacked[unpacked_idx++] = cur;
        prev = cur;
    }
    return unpacked_idx;
}

} // namespace compression

// ============================================================================
// [EN] AllocationMetadata methods (@ 0x0118ac, @ 0x011904, @ 0x011958)
// [VN] Các phương thức của AllocationMetadata (@ 0x0118ac, @ 0x011904, @ 0x011958)
// ============================================================================
void AllocationMetadata::RecordAllocation(uintptr_t AllocAddr, size_t Size, size_t PageRoundedSize) {
    Addr = AllocAddr;
    RequestedSize = Size;
    AllocatedSize = PageRoundedSize;
    IsDeallocated = false;
    AllocationTrace.ThreadID = getThreadID();
    DeallocationTrace.TraceSize = 0;
    DeallocationTrace.ThreadID = UINT64_MAX;
}

void AllocationMetadata::RecordDeallocation() {
    IsDeallocated = true;
    DeallocationTrace.ThreadID = getThreadID();
}

void AllocationMetadata::CallSiteInfo::RecordBacktrace(Options::Backtrace_t Backtrace) {
    TraceSize = 0;
    if (Backtrace == nullptr) {
        return;
    }
    uintptr_t raw_trace[kMaxFrameDepth];
    size_t num_frames = Backtrace(raw_trace, kMaxFrameDepth);
    if (num_frames > 0) {
        TraceSize = compression::pack(raw_trace, num_frames,
                                      CompressedTrace, kMaxTraceLengthToCollect);
    }
}

// ============================================================================
// [EN] initPRNG (@ 0x011404) & getRandomUnsigned32 (@ 0x011438)
//      Assembly @ 0x011404:
//        mov x0, xzr; bl time; mov x19, x0; bl getThreadID; add w8, w0, w19; str w8, [0x02e8d8]
//      Assembly @ 0x011438 (Xorshift32):
//        ldr w0, [x8]
//        eor w8, w0, w0, lsl #13
//        eor w8, w8, w8, lsr #17
//        eor w0, w8, w8, lsl #5
//        ret
// [VN] Khởi tạo và bước tiến PRNG Xorshift32 (@ 0x011404 & @ 0x011438)
// ============================================================================
void initPRNG() noexcept {
    time_t now = std::time(nullptr);
    uint64_t tid = getThreadID();
    g_prng_state = static_cast<uint32_t>(now) + static_cast<uint32_t>(tid);
    if (g_prng_state == 0) {
        g_prng_state = 0x9e3779b9U;
    }
}

uint32_t getRandomUnsigned32(uint32_t* state) noexcept {
    uint32_t x = (state != nullptr) ? *state : g_prng_state;
    if (x == 0) {
        x = 0x9e3779b9U;
    }
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    if (state != nullptr) {
        *state = x;
    } else {
        g_prng_state = x;
    }
    return x;
}

// ============================================================================
// [EN] POSIX platform helpers (@ 0x011c88..0x011edc & @ 0x013028)
// [VN] Các hàm hỗ trợ nền tảng POSIX (@ 0x011c88..0x011edc & @ 0x013028)
// ============================================================================
size_t getPlatformPageSize() noexcept {
    long sz = sysconf(_SC_PAGESIZE);
    return (sz > 0) ? static_cast<size_t>(sz) : 4096U;
}

uintptr_t alignUp(uintptr_t Value, size_t Boundary) noexcept {
    if (Boundary == 0) {
        return Value;
    }
    uintptr_t rem = Value % Boundary;
    if (rem == 0) {
        return Value;
    }
    return Value + (Boundary - rem);
}

void installAtFork() noexcept {
    pthread_atfork(&atForkPrepare, &atForkParentOrChild, &atForkParentOrChild);
}

void* reserveGuardedPool(size_t Size) noexcept {
    void* ptr = mmap(nullptr, Size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return nullptr;
    }
    prctl(PR_SET_VMA, PR_SET_VMA_ANON_NAME,
          reinterpret_cast<unsigned long>(ptr), Size,
          reinterpret_cast<unsigned long>("GWP-ASan Guard Page"));
    return ptr;
}

void allocateInGuardedPool(void* Ptr, size_t Size) noexcept {
    if (mprotect(Ptr, Size, PROT_READ | PROT_WRITE) == 0) {
        prctl(PR_SET_VMA, PR_SET_VMA_ANON_NAME,
              reinterpret_cast<unsigned long>(Ptr), Size,
              reinterpret_cast<unsigned long>("GWP-ASan Alive Slot"));
    }
}

void deallocateInGuardedPool(void* Ptr, size_t Size) noexcept {
    if (mprotect(Ptr, Size, PROT_NONE) == 0) {
        prctl(PR_SET_VMA, PR_SET_VMA_ANON_NAME,
              reinterpret_cast<unsigned long>(Ptr), Size,
              reinterpret_cast<unsigned long>("GWP-ASan Guard Page"));
    }
}

void* mapMetadataBuffer(size_t Size) noexcept {
    void* ptr = mmap(nullptr, Size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return nullptr;
    }
    prctl(PR_SET_VMA, PR_SET_VMA_ANON_NAME,
          reinterpret_cast<unsigned long>(ptr), Size,
          reinterpret_cast<unsigned long>("GWP-ASan Metadata"));
    return ptr;
}

uint64_t getThreadID() noexcept {
#ifdef SYS_gettid
    return static_cast<uint64_t>(syscall(SYS_gettid));
#else
    return static_cast<uint64_t>(gettid());
#endif
}

// ============================================================================
// [EN] GuardedPoolAllocator::init (@ 0x011464..0x0116c8)
//      Exact instruction sequence verified from disassembly:
//      1. Writes magic {'A','S','A','N'}, version 2 to State.VersionMagic (+0x00)
//      2. Stores SingletonPtr = this (@ 0x02e928)
//      3. Sets State.MaxSimultaneousAllocations (+0x08), State.PerfectlyRightAlign (+0x4c),
//         Backtrace (+0xa0), State.MaxAllocationSize (+0x30), State.AllocateRate (+0x38),
//         AdjustedSampleRatePlusOne = Opts.SampleRate + 1 (+0xa8)
//      4. Calls getPlatformPageSize() -> State.PageSize (+0x10)
//      5. PoolBytes = PageSize * (1 + MaxSimultaneousAllocations) + MaxAllocationSize * MaxSimultaneousAllocations
//         Calls reserveGuardedPool(PoolBytes) -> State.GuardedPagePool (+0x18),
//         State.GuardedPagePoolEnd = GuardedPagePool + PoolBytes (+0x20)
//      6. Allocates Metadata = mapMetadataBuffer(roundUpToPage(MaxSimultaneousAllocations * 0x270)) (+0x90)
//      7. Allocates FreeSlots = mapMetadataBuffer(roundUpToPage(MaxSimultaneousAllocations * 8)) (+0x98)
//      8. Allocates 1 page via reserveGuardedPool(PageSize) -> State.CrashTriggerSortingPage (+0x28)
//      9. Creates TLS key via pthread_key_create(&ThreadLocalKey, destroyThreadLocals) (+0xac, +0xb0)
//      10. Allocates 8-byte TLS struct for initializing thread, seeds PRNG via initPRNG()
//      11. If Opts.InstallForkHandlers, calls installAtFork()
// [VN] Khởi tạo đầy đủ GuardedPoolAllocator (@ 0x011464..0x0116c8)
// ============================================================================
void GuardedPoolAllocator::init(const Options& Opts) {
    State.VersionMagic.Magic[0] = 'A';
    State.VersionMagic.Magic[1] = 'S';
    State.VersionMagic.Magic[2] = 'A';
    State.VersionMagic.Magic[3] = 'N';
    State.VersionMagic.Version = 2;
    State.VersionMagic.Reserved = 0;

    if (!Opts.Enabled || Opts.MaxSimultaneousAllocations <= 0 || Opts.SampleRate < 0) {
        return;
    }

    SingletonPtr = this;
    State.MaxSimultaneousAllocations = static_cast<size_t>(Opts.MaxSimultaneousAllocations);
    State.PerfectlyRightAlign = Opts.PerfectlyRightAlign ? 1U : 0U;
    Backtrace = Opts.Backtrace;
    State.MaxAllocationSize = static_cast<size_t>(Opts.MaxAllocationSize);
    State.AllocateRate = static_cast<size_t>(Opts.AllocateRate);

    if (Opts.SampleRate == 0) {
        AdjustedSampleRatePlusOne = 0;
    } else {
        AdjustedSampleRatePlusOne = static_cast<uint32_t>(Opts.SampleRate) + 1U;
    }

    const size_t page_size = getPlatformPageSize();
    State.PageSize = page_size;
    pthread_mutex_init(&PoolMutex, nullptr);

    const size_t num_slots = State.MaxSimultaneousAllocations;
    const size_t pool_size =
        page_size * (1 + num_slots) + State.MaxAllocationSize * num_slots;

    void* pool_ptr = reserveGuardedPool(pool_size);
    State.GuardedPagePool = reinterpret_cast<uintptr_t>(pool_ptr);
    State.GuardedPagePoolEnd = State.GuardedPagePool + pool_size;

    const size_t metadata_bytes = alignUp(num_slots * sizeof(AllocationMetadata), page_size);
    Metadata = static_cast<AllocationMetadata*>(mapMetadataBuffer(metadata_bytes));

    const size_t freeslots_bytes = alignUp(num_slots * sizeof(size_t), page_size);
    FreeSlots = static_cast<size_t*>(mapMetadataBuffer(freeslots_bytes));

    void* trap_page = reserveGuardedPool(page_size);
    State.CrashTriggerSortingPage = reinterpret_cast<uintptr_t>(trap_page);

    if (pthread_key_create(&ThreadLocalKey, &destroyThreadLocals) == 0) {
        ThreadLocalKeyCreated = true;
    }

    initPRNG();
    ThreadLocalPackedVariables* locals = getThreadLocals();
    if (locals != nullptr && AdjustedSampleRatePlusOne != 0) {
        uint32_t rnd = getRandomUnsigned32(&locals->RandomState);
        locals->NextSampleCounterAndGuard =
            (rnd % AdjustedSampleRatePlusOne) + 1U;
    }

    if (Opts.InstallForkHandlers) {
        installAtFork();
    }
}

// ============================================================================
// [EN] GuardedPoolAllocator::getThreadLocals (@ 0x0119c8)
//      Returns the 8-byte ThreadLocalPackedVariables via pthread_getspecific,
//      allocating with malloc(8) on first access or falling back to +0xb8.
// [VN] Lấy con trỏ biến cục bộ luồng qua pthread_getspecific (@ 0x0119c8)
// ============================================================================
ThreadLocalPackedVariables* GuardedPoolAllocator::getThreadLocals() noexcept {
    if (!ThreadLocalKeyCreated) {
        return &FallbackLocals;
    }
    auto* ptr = static_cast<ThreadLocalPackedVariables*>(pthread_getspecific(ThreadLocalKey));
    if (ptr == nullptr) {
        ptr = static_cast<ThreadLocalPackedVariables*>(std::malloc(sizeof(ThreadLocalPackedVariables)));
        if (ptr == nullptr) {
            return &FallbackLocals;
        }
        ptr->NextSampleCounterAndGuard = 0x00000000U;
        ptr->RandomState = 0x9e37ac56U ^ static_cast<uint32_t>(getThreadID());
        if (ptr->RandomState == 0) {
            ptr->RandomState = 0x9e37ac56U;
        }
        pthread_setspecific(ThreadLocalKey, ptr);
    }
    return ptr;
}

// ============================================================================
// [EN] GuardedPoolAllocator::shouldSample (inlined in custom hooks @ 0x0168ec..0x0169a0)
//      1. Checks recursive guard bit 31 of NextSampleCounterAndGuard
//      2. When counter reaches 1, re-seeds counter to (Xorshift32() % AdjustedSampleRatePlusOne) + 1
//      3. Also checks secondary AllocateRate filter:
//         if (AllocateRate > 0 && (Xorshift32() % 100) < AllocateRate) -> returns true
// [VN] Logic lấy mẫu cấp phát (được nội tuyến trong các hàm hook @ 0x0168ec..0x0169a0)
// ============================================================================
bool GuardedPoolAllocator::shouldSample() noexcept {
    if (AdjustedSampleRatePlusOne == 0) {
        return false;
    }
    ThreadLocalPackedVariables* locals = getThreadLocals();
    uint32_t counter_and_guard = locals->NextSampleCounterAndGuard;
    if ((counter_and_guard & 0x80000000U) != 0) {
        return false;
    }
    uint32_t counter = counter_and_guard & 0x7fffffffU;
    if (counter > 1) {
        locals->NextSampleCounterAndGuard = (counter - 1U);
        return false;
    }
    uint32_t rnd = getRandomUnsigned32(&locals->RandomState);
    locals->NextSampleCounterAndGuard = (rnd % AdjustedSampleRatePlusOne) + 1U;

    if (State.AllocateRate > 0) {
        uint32_t rate_roll = getRandomUnsigned32(&locals->RandomState) % 100U;
        return rate_roll < State.AllocateRate;
    }
    return false;
}

// ============================================================================
// [EN] GuardedPoolAllocator::reserveSlot (@ 0x0117c8)
//      Assembly verified from 0x0117c8..0x01184c:
//      - While NumSampledAllocations < MaxSimultaneousAllocations:
//        uses slots sequentially 0 .. MaxSimultaneousAllocations-1
//      - Once all slots have been touched, pops a random index from FreeSlots[]
//        if FreeSlotsLength == MaxSimultaneousAllocations (full pool of freed slots).
// [VN] Dành riêng một chỉ số slot trong vùng nhớ bảo vệ (@ 0x0117c8)
// ============================================================================
size_t GuardedPoolAllocator::reserveSlot() noexcept {
    const size_t max_slots = State.MaxSimultaneousAllocations;
    if (NumSampledAllocations < max_slots) {
        return NumSampledAllocations++;
    }
    if (FreeSlotsLength == max_slots && max_slots > 0) {
        ThreadLocalPackedVariables* locals = getThreadLocals();
        uint32_t rnd = getRandomUnsigned32(&locals->RandomState);
        size_t random_idx = rnd % max_slots;
        size_t chosen_slot = FreeSlots[random_idx];
        FreeSlotsLength = max_slots - 1;
        FreeSlots[random_idx] = FreeSlots[FreeSlotsLength];
        return chosen_slot;
    }
    return SIZE_MAX;
}

// ============================================================================
// [EN] GuardedPoolAllocator::freeSlot (@ 0x011bb8)
//      Assembly verified from 0x011bb8..0x011bec:
//      - If FreeSlotsLength < MaxSimultaneousAllocations:
//        stores SlotIndex at FreeSlots[FreeSlotsLength++]
//      - Else: overwrites a random entry in FreeSlots[] and increments State.FreeSlotsSlip (+0x40)
// [VN] Đưa chỉ số slot đã giải phóng vào mảng FreeSlots (@ 0x011bb8)
// ============================================================================
void GuardedPoolAllocator::freeSlot(size_t SlotIndex) noexcept {
    const size_t max_slots = State.MaxSimultaneousAllocations;
    if (FreeSlotsLength < max_slots) {
        FreeSlots[FreeSlotsLength++] = SlotIndex;
        return;
    }
    if (max_slots > 0) {
        ThreadLocalPackedVariables* locals = getThreadLocals();
        uint32_t rnd = getRandomUnsigned32(&locals->RandomState);
        FreeSlots[rnd % max_slots] = SlotIndex;
        State.FreeSlotsSlip++;
    }
}

// ============================================================================
// [EN] GuardedPoolAllocator::allocate (@ 0x0116d0..0x0118a8)
//      1. Checks Size <= State.MaxAllocationSize (+0x30)
//      2. Sets RecursiveGuard bit 31 on ThreadLocals
//      3. Acquires PoolMutex (+0x58), increments TotalSampledCount (+0xc0), calls reserveSlot()
//      4. Computes PageRoundedSize = alignUp(Size > 0 ? Size : 1, PageSize)
//      5. Computes SlotPageAddr = State.slotToAddr(SlotIndex)
//      6. Calls allocateInGuardedPool(SlotPageAddr, PageRoundedSize)
//      7. Computes UserPtr:
//         - Left-aligned if (getThreadLocals()->RandomState & 1) == 0: UserPtr = SlotPageAddr
//         - Right-aligned if odd: UserPtr = SlotPageAddr + PageRoundedSize - Size
//           (and if PerfectlyRightAlign is false, rounds Size up to 1,2,4,8,16 power-of-two alignment)
//      8. Records AllocationMetadata at Metadata[SlotIndex] (+0x270 * SlotIndex)
// [VN] Cấp phát vùng nhớ bảo vệ với mprotect RW và ghi siêu dữ liệu (@ 0x0116d0)
// ============================================================================
void* GuardedPoolAllocator::allocate(size_t Size) {
    if (Size > State.MaxAllocationSize || State.MaxSimultaneousAllocations == 0) {
        return nullptr;
    }

    ThreadLocalPackedVariables* locals = getThreadLocals();
    locals->NextSampleCounterAndGuard |= 0x80000000U;

    pthread_mutex_lock(&PoolMutex);
    TotalSampledCount++;
    size_t slot = reserveSlot();
    pthread_mutex_unlock(&PoolMutex);

    if (slot == SIZE_MAX) {
        locals->NextSampleCounterAndGuard &= 0x7fffffffU;
        return nullptr;
    }

    const size_t page_size = State.PageSize;
    const size_t effective_size = (Size != 0) ? Size : 1U;
    const size_t page_rounded_size = alignUp(effective_size, page_size);
    const uintptr_t slot_page_addr = State.slotToAddr(slot);

    allocateInGuardedPool(reinterpret_cast<void*>(slot_page_addr), page_rounded_size);

    uintptr_t user_addr = slot_page_addr;
    if ((locals->RandomState & 1U) != 0 && Size != 0) {
        size_t aligned_size = Size;
        if (State.PerfectlyRightAlign == 0) {
            size_t alignment = 16;
            if (Size <= 2) {
                alignment = Size;
            } else if (Size <= 4) {
                alignment = 4;
            } else if (Size <= 8) {
                alignment = 8;
            }
            aligned_size = (Size + alignment - 1U) & ~(alignment - 1U);
        }
        user_addr = slot_page_addr + page_rounded_size - aligned_size;
    }

    AllocationMetadata& meta = Metadata[slot];
    meta.RecordAllocation(user_addr, Size, page_rounded_size);
    meta.AllocationTrace.RecordBacktrace(Backtrace);

    locals->NextSampleCounterAndGuard &= 0x7fffffffU;
    return reinterpret_cast<void*>(user_addr);
}

// ============================================================================
// [EN] GuardedPoolAllocator::trapOnAddress (@ 0x011a0c) — EXPORTED SYMBOL
//      Exact 5 AArch64 instructions @ 0x011a0c..0x011a1c:
//        0x011a0c: 08 14 40 f9  ldr  x8, [x0, #0x28]   // State.CrashTriggerSortingPage
//        0x011a10: 02 48 00 b9  str  w2, [x0, #0x48]   // State.FailureType = Err
//        0x011a14: 01 28 00 f9  str  x1, [x0, #0x50]   // State.FailureAddress = Address
//        0x011a18: 1f 01 00 39  strb wzr, [x8]         // Deliberate write to PROT_NONE page!
//        0x011a1c: c0 03 5f d6  ret
// [VN] Hàm xuất _ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error (@ 0x011a0c)
// ============================================================================
void GuardedPoolAllocator::trapOnAddress(uintptr_t Address, Error Err) {
    State.FailureType = Err;
    State.FailureAddress = Address;
    if (State.CrashTriggerSortingPage != 0) {
        *reinterpret_cast<volatile uint8_t*>(State.CrashTriggerSortingPage) = 0;
    }
}

// ============================================================================
// [EN] GuardedPoolAllocator::deallocate (@ 0x011a30..0x011c14)
//      1. Sets RecursiveGuard bit 31
//      2. Computes slot = State.addrToSlot(UIntPtr) and slot_addr = State.slotToAddr(slot)
//      3. Looks up Metadata[slot]:
//         - If meta.Addr != UIntPtr -> calls trapOnAddress(UIntPtr, Error::INVALID_FREE /* 3 */)
//         - If meta.IsDeallocated -> calls trapOnAddress(UIntPtr, Error::DOUBLE_FREE /* 2 */)
//      4. Calls deallocateInGuardedPool(slot_addr, meta.AllocatedSize)
//      5. Records deallocation metadata and backtrace
//      6. Locks PoolMutex and calls freeSlot(slot)
// [VN] Giải phóng vùng nhớ bảo vệ, bắt lỗi INVALID_FREE / DOUBLE_FREE (@ 0x011a30)
// ============================================================================
void GuardedPoolAllocator::deallocate(void* Ptr) {
    ThreadLocalPackedVariables* locals = getThreadLocals();
    locals->NextSampleCounterAndGuard |= 0x80000000U;

    const uintptr_t addr = reinterpret_cast<uintptr_t>(Ptr);
    const size_t slot = State.addrToSlot(addr);
    const uintptr_t slot_page_addr = State.slotToAddr(slot);
    AllocationMetadata& meta = Metadata[slot];

    if (meta.Addr != addr) {
        trapOnAddress(addr, Error::INVALID_FREE);
        locals->NextSampleCounterAndGuard &= 0x7fffffffU;
        return;
    }

    if (meta.IsDeallocated) {
        trapOnAddress(addr, Error::DOUBLE_FREE);
        locals->NextSampleCounterAndGuard &= 0x7fffffffU;
        return;
    }

    // [EN] Immediately revoke RW permissions before recording backtrace to catch races
    // [VN] Thu hồi ngay quyền RW trước khi ghi vết ngăn xếp để bắt lỗi truy cập đồng thời
    deallocateInGuardedPool(reinterpret_cast<void*>(slot_page_addr), meta.AllocatedSize);

    meta.RecordDeallocation();
    meta.DeallocationTrace.RecordBacktrace(Backtrace);

    pthread_mutex_lock(&PoolMutex);
    freeSlot(slot);
    pthread_mutex_unlock(&PoolMutex);

    locals->NextSampleCounterAndGuard &= 0x7fffffffU;
}

// ============================================================================
// [EN] GuardedPoolAllocator::getSize (@ 0x011c18..0x011c70)
//      Locks PoolMutex, computes slot = addrToSlot(Ptr), verifies meta.Addr == Ptr,
//      and returns meta.RequestedSize (+0x258).
// [VN] Truy vấn kích thước cấp phát ban đầu của con trỏ được bảo vệ (@ 0x011c18)
// ============================================================================
size_t GuardedPoolAllocator::getSize(const void* Ptr) {
    ThreadLocalPackedVariables* locals = getThreadLocals();
    locals->NextSampleCounterAndGuard |= 0x80000000U;

    pthread_mutex_lock(&PoolMutex);
    const uintptr_t addr = reinterpret_cast<uintptr_t>(Ptr);
    const size_t slot = State.addrToSlot(addr);
    AllocationMetadata& meta = Metadata[slot];
    size_t req_size = 0;
    if (meta.Addr == addr) {
        req_size = meta.RequestedSize;
    }
    pthread_mutex_unlock(&PoolMutex);

    locals->NextSampleCounterAndGuard &= 0x7fffffffU;
    return req_size;
}

} // namespace gwp_asan
