// ============================================================================
// File: guarded_pool_allocator.h
// Target: libgodzilla-acurate-asan.so (160,168 bytes)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Declarations for GWP-ASan GuardedPoolAllocator,
//                   AllocatorState arithmetic helpers, POSIX VMA mapping,
//                   Xorshift32 PRNG, and LEB128/ZigZag backtrace compression.
// Mô tả (VN): Khai báo cho GuardedPoolAllocator của GWP-ASan, các hàm toán học
//             trạng thái cấp phát, ánh xạ VMA POSIX, bộ sinh số giả ngẫu nhiên
//             Xorshift32 và nén vết ngăn xếp LEB128/ZigZag.
// ============================================================================

#pragma once

#include "godzilla_acurate_asan_types.h"

namespace gwp_asan {

// ============================================================================
// [EN] Global SingletonPtr in .bss @ 0x02e928 and PRNG seed in .data @ 0x02e8d8
// [VN] Con trỏ đơn bản toàn cục tại .bss @ 0x02e928 và hạt giống PRNG tại .data @ 0x02e8d8
// ============================================================================
extern GuardedPoolAllocator* SingletonPtr;   // .bss @ 0x02e928
extern GuardedPoolAllocator* g_mmap_alloc;   // .bss @ 0x02e920
extern uint32_t g_prng_state;                // .data @ 0x02e8d8

// [EN] Initialize PRNG seed from time(nullptr) + gettid() (@ 0x011404)
// [VN] Khởi tạo hạt giống PRNG từ time(nullptr) + gettid() (@ 0x011404)
void initPRNG() noexcept;

// [EN] Advance Xorshift32 PRNG: x ^= x << 13; x ^= x >> 17; x ^= x << 5 (@ 0x011438)
// [VN] Bước tiến bộ sinh ngẫu nhiên Xorshift32: x ^= x << 13; x ^= x >> 17; x ^= x << 5 (@ 0x011438)
uint32_t getRandomUnsigned32(uint32_t* state = nullptr) noexcept;

// [EN] Query cached page size via sysconf(_SC_PAGESIZE) (@ 0x011df4)
// [VN] Truy vấn kích thước trang nhớ qua sysconf(_SC_PAGESIZE) (@ 0x011df4)
size_t getPlatformPageSize() noexcept;

// [EN] Round `Value` up to the nearest multiple of `Boundary` (@ 0x013028)
// [VN] Làm tròn `Value` lên bội số gần nhất của `Boundary` (@ 0x013028)
uintptr_t alignUp(uintptr_t Value, size_t Boundary) noexcept;

// [EN] Install pthread_atfork handlers locking/unlocking PoolMutex (@ 0x011c88)
// [VN] Cài đặt trình xử lý pthread_atfork khóa/mở khóa PoolMutex (@ 0x011c88)
void installAtFork() noexcept;

// [EN] Reserve `Size` bytes of PROT_NONE anonymous memory and name VMA (@ 0x011cf4)
//      Uses prctl(PR_SET_VMA /* 0x53564d41 */, PR_SET_VMA_ANON_NAME /* 0 */, ptr, size, name)
// [VN] Dành riêng `Size` byte bộ nhớ ẩn danh PROT_NONE và đặt tên VMA (@ 0x011cf4)
void* reserveGuardedPool(size_t Size) noexcept;

// [EN] Commit RW pages inside guarded pool and tag VMA as "GWP-ASan Alive Slot" (@ 0x011d8c)
// [VN] Cấp quyền đọc/ghi cho trang trong vùng nhớ bảo vệ và gắn nhãn "GWP-ASan Alive Slot" (@ 0x011d8c)
void allocateInGuardedPool(void* Ptr, size_t Size) noexcept;

// [EN] Decommit pages inside guarded pool to PROT_NONE and tag VMA as "GWP-ASan Guard Page" (@ 0x011dc0)
// [VN] Thu hồi quyền truy cập trang về PROT_NONE và gắn nhãn "GWP-ASan Guard Page" (@ 0x011dc0)
void deallocateInGuardedPool(void* Ptr, size_t Size) noexcept;

// [EN] Allocate metadata or free-slots buffer via mmap RW and tag VMA as "GWP-ASan Metadata" (@ 0x011e24)
// [VN] Cấp phát bộ đệm siêu dữ liệu qua mmap RW và gắn nhãn "GWP-ASan Metadata" (@ 0x011e24)
void* mapMetadataBuffer(size_t Size) noexcept;

// [EN] Obtain current thread ID via syscall(__NR_gettid /* 178 on AArch64 */) (@ 0x011ec8)
// [VN] Lấy định danh luồng hiện tại qua syscall(__NR_gettid /* 178 trên AArch64 */) (@ 0x011ec8)
uint64_t getThreadID() noexcept;

} // namespace gwp_asan
