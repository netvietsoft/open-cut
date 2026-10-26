// ============================================================================
// FILE: heap_clamp_opt.h
// TARGET: libgodzilla-memsponge.so (.text 0x078954..0x07aabc, 0x07d8a4..0x07dad3)
// PURPOSE: ART Heap Growth Limit Clamping, /proc/self/maps Region Space
//          Inspection, NoClassDefFoundError / ThreadSuspend Diagnostics,
//          and FreeList Guard VMA Fixer.
// MỤC ĐÍCH: Kẹp giới hạn tăng trưởng ART Heap, kiểm tra Region Space trong
//           /proc/self/maps, chẩn đoán NoClassDefFoundError / ThreadSuspend,
//           và vá VMA bảo vệ FreeList.
// ============================================================================

#pragma once

#include "godzilla_memsponge_types.h"

namespace NextAI::OpenCut::godzilla_memsponge {

// ============================================================================
// 1. HEAP CLAMP GROWTH LIMIT ENGINE (0x078954..0x07900b)
// ============================================================================

/**
 * EN: Scans `art::gc::Heap` fields in 8-byte steps (`[0x000..0x310]`, `cmp x27, #0x318` @ `0x0789e8`)
 *     for two adjacent `size_t` fields matching `origin_capacity` (`capacity_` and `growth_limit_`).
 *     Caches their addresses in `sCapcacityAdress` (`0x106358`) and `sGrowLimitAdress` (`0x106360`).
 *     Binary address: `0x078954` (`size = 440 B`).
 * VN: Quét các trường của `art::gc::Heap` theo bước nhảy 8 byte (`[0x000..0x310]`, `cmp x27, #0x318`)
 *     để tìm hai trường `size_t` liền kề khớp với `origin_capacity` (`capacity_` và `growth_limit_`).
 *     Địa chỉ nhị phân: `0x078954` (`size = 440 B`).
 */
int checkCapcacityAndGrowLimit(void* heap, size_t origin_capacity);

/**
 * EN: Writes `reset_capacity` into `*sGrowLimitAdress` (`0x106360`) and invokes
 *     `sClampGrowthLimitFunc(sHeap)`.
 *     Binary address: `0x078b0c` (`size = 168 B`).
 * VN: Ghi `reset_capacity` vào `*sGrowLimitAdress` (`0x106360`) và gọi
 *     `sClampGrowthLimitFunc(sHeap)`.
 *     Địa chỉ nhị phân: `0x078b0c` (`size = 168 B`).
 */
int callClampGrowthLimit(size_t reset_capacity);

/**
 * EN: Invokes `sClearGrowthLimitFunc(sHeap)` if both `sClearGrowthLimitFunc` (`0x106348`)
 *     and `sHeap` (`0x106350`) are non-null, returning `0` on success or `-1` on failure.
 *     Binary address: `0x078bb4` (`size = 100 B`).
 * VN: Gọi `sClearGrowthLimitFunc(sHeap)` nếu cả hai khác null, trả về `0` hoặc `-1`.
 *     Địa chỉ nhị phân: `0x078bb4` (`size = 100 B`).
 */
int callClearGrowthLimit();

void ClearGrowthLimitProxy(void* heap);
void ClampGrowthLimitProxy(void* heap);
size_t GetTotalMemoryProxy(void* heap);

/**
 * EN: Resolves `_ZN3art2gc4Heap16ClampGrowthLimitEv` (`0x504f2`) and
 *     `_ZNK3art2gc4Heap14GetTotalMemoryEv` (`0x4f95e`) in `libart.so` and hooks `GetTotalMemory`
 *     to capture `sHeap` (`0x106350`).
 *     Binary address: `0x078d2c` (`size = 360 B`).
 * VN: Phân giải `Heap::ClampGrowthLimit` và `Heap::GetTotalMemory` trong `libart.so`
 *     và hook `GetTotalMemory` để bắt con trỏ `sHeap` (`0x106350`).
 *     Địa chỉ nhị phân: `0x078d2c` (`size = 360 B`).
 */
int initHook();

// ============================================================================
// 2. /proc/self/maps PARSING & DIAGNOSTICS (0x07900c..0x07aabc)
// ============================================================================

/**
 * EN: Parses a single `/proc/self/maps` line into a 6-field `MemoryMapEntry`.
 *     Used by `HeapClampHelper_printProcessMaps` (`0x07900c`).
 * VN: Phân tích một dòng `/proc/self/maps` thành cấu trúc 6 trường `MemoryMapEntry`.
 */
bool parseProcessMapsLine(const std::string& line, MemoryMapEntry* out_entry);

/**
 * EN: Evaluates whether a `/proc/self/maps` line contains `"dalvik-main space"` (17 chars,
 *     constants `x28 = 0x6d2d6b69766c6164ULL`, `x23 = 0x63617073206e6961ULL`, `w19 = 0x65`
 *     at `0x079d7c..0x079db0`) and whether that line also contains `"region space"` (12 chars,
 *     constants `x19 = 0x73206e6f69676572ULL`, `w21 = 0x65636170` at `0x079eb4..0x079ecc`).
 *     Returns `1` if `"region space"` is present, `0` if `"dalvik-main space"` is found without
 *     `"region space"`, or `-1` if the line does not contain `"dalvik-main space"`.
 * VN: Đánh giá dòng `/proc/self/maps` có chứa `"dalvik-main space"` (17 ký tự) và
 *     `"region space"` (12 ký tự) theo đúng hằng số thanh ghi tại `0x079d7c..0x079ecc`.
 */
int evaluateDalvikMainSpaceLine(const char* line, size_t len);

/**
 * EN: Evaluates whether a `/proc/self/maps` line matches `"dalvik-free list large object space"`
 *     (35 chars, constants at `0x07a634..0x07a68c`) and whether its start address `< 0x20000`
 *     (`lsr x9, x8, #0x11; cbz x9` @ `0x07a8f8..0x07a8fc`), computing the required guard VMA
 *     size `start_addr - 0x10000`.
 * VN: Đánh giá dòng `/proc/self/maps` có khớp `"dalvik-free list large object space"` (35 ký tự)
 *     và địa chỉ bắt đầu `< 0x20000` (`start_addr >> 17 == 0`), tính kích thước VMA bảo vệ
 *     `start_addr - 0x10000`.
 */
bool evaluateFreeListSpaceGuardSize(const char* line, size_t len, uintptr_t* out_start_addr, size_t* out_guard_size);

void ThreadSuspendByPeerWarningProxy(void* self, int severity, const char* msg, jobject peer);
void* GetPreAllocatedNoClassDefFoundErrorProxy(void* runtime);
void ThrowEarlierClassFailureProxy(void* class_linker, void* klass, bool wrap_in_no_class_def, bool log);

// ============================================================================
// 3. JAVA / NATIVE STACK TRACE DIAGNOSTICS (0x07d8a4..0x07dad3)
// ============================================================================

/**
 * EN: Prints the current thread's stack trace in 1,024-byte chunks (`mov w26, #0x400` @ `0x07d920`).
 *     Binary address: `0x07d8a4` (`size = 284 B`).
 * VN: In stack trace của luồng hiện tại theo từng khối 1.024 byte (`0x400` @ `0x07d920`).
 *     Địa chỉ nhị phân: `0x07d8a4` (`size = 284 B`).
 */
void printCurrentStack(const char* tag);

/**
 * EN: Prints all threads' stack traces in 1,024-byte chunks (`mov w26, #0x400` @ `0x07da34`).
 *     Binary address: `0x07d9c0` (`size = 276 B`).
 * VN: In stack trace của toàn bộ các luồng theo từng khối 1.024 byte (`0x400` @ `0x07da34`).
 *     Địa chỉ nhị phân: `0x07d9c0` (`size = 276 B`).
 */
void printAllStack();

} // namespace NextAI::OpenCut::godzilla_memsponge
