// ============================================================================
// FILE: memsponge_art_hook.h
// TARGET: libgodzilla-memsponge.so (.text 0x075120..0x07888b, 0x07a49c..0x07aabc, 0x07d438..0x07d5e3)
// PURPOSE: ART LargeObjectSpace Memory Sponge, SoftReference GC Adjustment,
//          Heap Ideal Footprint Optimization, and FreeList Guard VMA Fixer.
// MỤC ĐÍCH: Bộ hút bộ nhớ ART LargeObjectSpace (MemSponge), điều chỉnh thu gom
//           SoftReference, tối ưu dấu chân Heap và vá VMA bảo vệ FreeList.
// ============================================================================

#pragma once

#include "godzilla_memsponge_types.h"

namespace NextAI::OpenCut::godzilla_memsponge {

// ============================================================================
// 1. LARGE OBJECT SPACE & RECORD FREE PROXIES (0x075120..0x075cef)
// ============================================================================

/**
 * EN: Verifies that `(num_objects_allocated_addr - num_bytes_allocated_addr) == 1`.
 *     Binary address: `0x075120` (`size = 188 B`).
 *     Opcode: `sub x5, x20, x19` (`0xCB130285`), `cmp x5, #1` (`0xF10004BF`).
 * VN: Xác minh khoảng cách địa chỉ `(num_objects_allocated_addr - num_bytes_allocated_addr) == 1`.
 *     Địa chỉ nhị phân: `0x075120` (`size = 188 B`).
 */
int verify_num_objects_allocated_offset_addr(uint64_t objects_addr, uint64_t bytes_addr);

/**
 * EN: Queries `LargeObjectSpace::GetBytesAllocated()` on `sLastLargeObjectSpace` (`0x1062d8`).
 *     Binary address: `0x07539c` (`size = 44 B`).
 * VN: Truy vấn `LargeObjectSpace::GetBytesAllocated()` trên `sLastLargeObjectSpace` (`0x1062d8`).
 *     Địa chỉ nhị phân: `0x07539c` (`size = 44 B`).
 */
uint64_t GetLOSBytesAllocated();

/**
 * EN: Queries `LargeObjectSpace::GetObjectsAllocated()` on `sLastLargeObjectSpace` (`0x1062d8`).
 *     Binary address: `0x0753c8` (`size = 44 B`).
 * VN: Truy vấn `LargeObjectSpace::GetObjectsAllocated()` trên `sLastLargeObjectSpace` (`0x1062d8`).
 *     Địa chỉ nhị phân: `0x0753c8` (`size = 44 B`).
 */
uint64_t GetLOSObjectsAllocated();

/**
 * EN: Proxy for `art::gc::space::LargeObjectMapSpace::Alloc(Thread*, size_t, size_t*, size_t*, size_t*)`.
 *     Binary address: `0x0751dc` (`size = 448 B`).
 *     Saves `thiz` to `sLastLargeObjectSpace` (`0x1062d8`) when `sCurMemSpongeMode != 0` and logs
 *     allocations `> 0x80000` (`512 KB`, `cmp x20, #0x80, lsl #12` @ `0x075274`, `0xF142029F`).
 * VN: Hàm Proxy cho `LargeObjectMapSpace::Alloc` (6 tham số).
 *     Địa chỉ nhị phân: `0x0751dc` (`size = 448 B`).
 */
void* larget_object_alloc_proxy(
    void* thiz,
    void* self,
    size_t num_bytes,
    size_t* bytes_allocated,
    size_t* usable_size,
    size_t* bytes_tl_bulk_allocated);

/**
 * EN: Proxy for Android 5.x `LargeObjectMapSpace::Alloc(Thread*, size_t, size_t*, size_t*)`.
 *     Binary address: `0x075424` (`size = 428 B`).
 * VN: Hàm Proxy cho `LargeObjectMapSpace::Alloc` trên Android 5.x (5 tham số).
 *     Địa chỉ nhị phân: `0x075424` (`size = 428 B`).
 */
void* larget_object_alloc_l_32_proxy(
    void* thiz,
    void* self,
    size_t num_bytes,
    size_t* bytes_allocated,
    size_t* usable_size);

/**
 * EN: Proxy for `art::gc::space::FreeListSpace::Alloc(Thread*, size_t, size_t*, size_t*, size_t*)`.
 *     Binary address: `0x0755d0` (`size = 448 B`).
 * VN: Hàm Proxy cho `FreeListSpace::Alloc` (6 tham số).
 *     Địa chỉ nhị phân: `0x0755d0` (`size = 448 B`).
 */
void* free_list_alloc_proxy(
    void* thiz,
    void* self,
    size_t num_bytes,
    size_t* bytes_allocated,
    size_t* usable_size,
    size_t* bytes_tl_bulk_allocated);

/**
 * EN: Proxy for Android 5.x `FreeListSpace::Alloc(Thread*, size_t, size_t*, size_t*)`.
 *     Binary address: `0x075790` (`size = 428 B`).
 *     Logs allocations `> 0x40000` (`256 KB`, `cmp x20, #0x40, lsl #12` @ `0x07581c`, `0xF141029F`).
 * VN: Hàm Proxy cho `FreeListSpace::Alloc` trên Android 5.x (5 tham số).
 *     Địa chỉ nhị phân: `0x075790` (`size = 428 B`).
 */
void* free_list_alloc_l_proxy(
    void* thiz,
    void* self,
    size_t num_bytes,
    size_t* bytes_allocated,
    size_t* usable_size);

/**
 * EN: Proxy for `LargeObjectSpace::Free(Thread*, mirror::Object*)`.
 *     Binary address: `0x07593c` (`size = 352 B`).
 * VN: Hàm Proxy cho `LargeObjectSpace::Free`.
 *     Địa chỉ nhị phân: `0x07593c` (`size = 352 B`).
 */
size_t larget_object_free_proxy(void* thiz, void* self, void* obj);

/**
 * EN: Returns `0` (`mov x0, xzr; ret`). Binary addresses: `0x075a9c` and `0x075aa4` (`8 B` each).
 * VN: Trả về `0` (`mov x0, xzr; ret`). Địa chỉ nhị phân: `0x075a9c` và `0x075aa4` (`8 B`).
 */
size_t getLargeObjectAllocatedBytes();
size_t getNumObjectsAllocated();

/**
 * EN: Checks whether `sCurMemSpongeMode != 0` (`0x106230`).
 *     Binary address: `0x075aac` (`size = 24 B`).
 * VN: Kiểm tra `sCurMemSpongeMode != 0` (`0x106230`).
 *     Địa chỉ nhị phân: `0x075aac` (`size = 24 B`).
 */
bool isAllowWork();

/**
 * EN: Core MemSponge subtraction formula that adjusts `freed_bytes` passed to `Heap::RecordFree`.
 *     Binary address: `0x075ac4` (`size = 124 B`).
 *     Formula:
 *       `los_bytes = GetLOSBytesAllocated()`;
 *       `target_hide = min(sHideLargeObjectMaxBytes, los_bytes)`;
 *       `isMSpongeOOM = (sHideLargeObjectMaxBytes <= los_bytes)`;
 *       `adjusted_freed = (freed_bytes - sAlreadyHiddenBytes) + target_hide`;
 *       `sAlreadyHiddenBytes = target_hide`;
 * VN: Công thức trừ MemSponge cốt lõi điều chỉnh `freed_bytes` truyền vào `Heap::RecordFree`.
 *     Địa chỉ nhị phân: `0x075ac4` (`size = 124 B`).
 */
int64_t alignHideLargeObjectBytes(int64_t freed_bytes);

/**
 * EN: Proxy for `art::gc::Heap::RecordFree(uint64_t freed_objects, int64_t freed_bytes)`.
 *     Binary address: `0x075b40` (`size = 432 B`).
 *     When `sCurMemSpongeMode == kActive (2)` or `(sCurMemSpongeMode == kWhenOOM (1) && sHasTriggeredOOM == 1)`,
 *     inflates `freed_bytes` by `(target_hide - sAlreadyHiddenBytes)` so ART's `num_bytes_allocated_`
 *     is reduced by `target_hide` bytes!
 * VN: Hàm Proxy cho `art::gc::Heap::RecordFree(uint64_t freed_objects, int64_t freed_bytes)`.
 *     Địa chỉ nhị phân: `0x075b40` (`size = 432 B`).
 */
void RecordFreeProxy(void* heap, uint64_t freed_objects, int64_t freed_bytes);

// ============================================================================
// 2. GC UTILIZATION, ALLOCATION & OOM PROXIES (0x075cf0..0x07730f)
// ============================================================================

void ThreadThrowNewExceptionProxy(void* self, char* exception_class, const char* msg);
void GrowForUtilizationProxy_Q_32(void* heap, void* collector, uint64_t bytes_allocated_before_gc);
void GrowForUtilizationProxy_32(void* heap, void* collector, uint64_t bytes_allocated_before_gc);

void* AllocateInternalWithGcProxy(
    void* heap,
    void* self,
    AllocatorType allocator,
    bool instrumented,
    size_t alloc_size,
    size_t* bytes_allocated,
    size_t* usable_size,
    size_t* bytes_tl_bulk_allocated,
    void* klass);

void* AllocateInternalWithGcProxy_M(
    void* heap,
    void* self,
    AllocatorType allocator,
    size_t alloc_size,
    size_t* bytes_allocated,
    size_t* usable_size,
    size_t* bytes_tl_bulk_allocated,
    void* klass);

void* AllocateInternalWithGcProxy_L(
    void* heap,
    void* self,
    AllocatorType allocator,
    size_t alloc_size,
    size_t* bytes_allocated,
    size_t* usable_size,
    void* klass);

void ThrowOutOfMemoryErrorProxy(void* heap, void* self, size_t byte_count, AllocatorType allocator_type);
void* GetPreAllocatedOutOfMemoryErrorWhenThrowingExceptionProxy(void* self);
bool IsThrowableClassProxy(void* klass);
void* AllocFromModifiedUtf8Proxy(void* self, const char* utf);
void GarbageCollectorRunProxy(void* collector, int32_t gc_cause, bool clear_soft_references);
void ThreadThrowOutOfMemoryProxy(void* self, char* msg);
void ThreadSetExceptionProxy(void* self, void* exception);
size_t GetBytesAllocatedProxy(void* space);

void* get_num_bytes_allocated_ptr_addr(void* los_space, int api_level);
void* get_num_objects_allocated_ptr_addr(void* los_space, int api_level);

// ============================================================================
// 3. API SUPPORT BITMASK & ART HOOK INITIALIZATION (0x077310..0x07888b)
// ============================================================================

/**
 * EN: Checks whether `api_level` (`20..35`) is enabled in `support_api_mask`.
 *     Binary address: `0x077310` (`size = 176 B`).
 *     Note: `api_level == 32` (Android 12L) maps to default return `0` in the jump table at `0x04c510`!
 * VN: Kiểm tra `api_level` (`20..35`) có được bật trong `support_api_mask` hay không.
 *     Địa chỉ nhị phân: `0x077310` (`size = 176 B`).
 */
bool checkSupportApi(int api_level, int64_t support_api_mask);

/**
 * EN: Resolves `libart.so` symbols and installs ShadowHook proxies for all matching entries
 *     in the 20-entry `ArtProxyMapping` table (`0x105ba0..0x106000`).
 *     Binary address: `0x0773c0` (`size = 1,200 B`).
 * VN: Phân giải symbol trong `libart.so` và cài đặt ShadowHook cho các mục khớp
 *     trong bảng 20 mục `ArtProxyMapping` (`0x105ba0..0x106000`).
 *     Địa chỉ nhị phân: `0x0773c0` (`size = 1.200 B`).
 */
int initArtHook(int api_level, MemSpongeMode mode);

/**
 * EN: Safely checks whether `[ptr, ptr + len)` is readable in process virtual memory
 *     by opening `"/dev/random"` (`O_WRONLY = 1`) and calling `write(fd, ptr, len)`.
 *     Binary address: `0x0779d4` (`size = 192 B`).
 * VN: Kiểm tra an toàn vùng nhớ `[ptr, ptr + len)` có đọc được không bằng cách
 *     mở `"/dev/random"` (`O_WRONLY = 1`) và gọi `write(fd, ptr, len)`.
 *     Địa chỉ nhị phân: `0x0779d4` (`size = 192 B`).
 */
bool IsValidPtr(void* ptr, size_t len);

/**
 * EN: Finds the byte offset of `art::Runtime*` inside `art::JavaVMExt` (`sJavaVmRuntimeOffset` @ `0x106250`).
 *     Binary address: `0x077a94` (`size = 324 B`).
 * VN: Tìm độ lệch byte của `art::Runtime*` bên trong `art::JavaVMExt` (`sJavaVmRuntimeOffset` @ `0x106250`).
 *     Địa chỉ nhị phân: `0x077a94` (`size = 324 B`).
 */
int64_t findJavaVmBaseRuntimeOffset(char* runtime_instance);

/**
 * EN: Returns the relative offset of `art::gc::Heap*` from `art::Runtime*` based on Android API level.
 *     Binary address: `0x077bd8` (`size = 96 B`).
 * VN: Trả về độ lệch tương đối của `art::gc::Heap*` từ `art::Runtime*` dựa trên cấp độ API Android.
 *     Địa chỉ nhị phân: `0x077bd8` (`size = 96 B`).
 */
int64_t getBaseHeapOffsetBaseJavaVm(int api_level);

/**
 * EN: Evaluates whether `CollectGarbageInternal` should force `clear_soft_references = true`.
 *     Binary address: `0x0780dc` (`size = 112 B`).
 *     When `sCurrentHeapSize > sSoftRefHeapThreshold` (`0x1062f8 > 0x106008`), resets
 *     `sCurrentHeapSize = 0` and returns `true`.
 * VN: Đánh giá xem `CollectGarbageInternal` có nên ép `clear_soft_references = true` hay không.
 *     Địa chỉ nhị phân: `0x0780dc` (`size = 112 B`).
 */
bool shouldClearSoftReference(bool orig_clear_soft_references);

uint32_t CollectGarbageInternalSProxy(
    void* heap,
    void* gc_type,
    void* gc_cause,
    bool clear_soft_references,
    uint64_t gc_num);

uint32_t CollectGarbageInternalRProxy(
    void* heap,
    void* gc_type,
    void* gc_cause,
    bool clear_soft_references);

/**
 * EN: Proxy for `art::gc::Heap::SetIdealFootprint(size_t max_allowed_footprint)`.
 *     Binary address: `0x078668` (`size = 340 B`).
 *     If `sMaxHeapRatio * 536870912.0f > (float)max_allowed_footprint` and `sGlobalTriggerGcValue <= max_allowed_footprint`,
 *     adds `sAddGcDiffBytes` (`0x106308`) to `max_allowed_footprint`.
 * VN: Hàm Proxy cho `art::gc::Heap::SetIdealFootprint(size_t max_allowed_footprint)`.
 *     Địa chỉ nhị phân: `0x078668` (`size = 340 B`).
 */
void HeapSetIdealFootPrintProxy(void* heap, size_t max_allowed_footprint);

/**
 * EN: Proxy for `art::gc::space::BumpPointerSpace::ClampGrowthLimit(size_t new_capacity)`.
 *     Binary address: `0x07d530` (`size = 180 B`).
 *     Logs `"ignore_bump_pointer_clamp_grow_limit call, thiz: %p, new_capacity: %zu"`,
 *     prints current stack for `"BumpPointerSpace"`, and returns `0` without clamping!
 * VN: Hàm Proxy cho `BumpPointerSpace::ClampGrowthLimit(size_t new_capacity)`.
 *     Địa chỉ nhị phân: `0x07d530` (`size = 180 B`).
 */
size_t ignore_bump_pointer_clamp_grow_limit(void* thiz, size_t new_capacity);

// Accessor for the 20-entry ArtProxyMapping table (`0x105ba0..0x106000`)
const ArtProxyMapping* getArtProxyMappingTable(size_t* out_count);

// Accessor for the 2-entry SoftRefProxyMapping table (`0x106010..0x106060`)
const SoftRefProxyMapping* getSoftRefProxyMappingTable(size_t* out_count);

} // namespace NextAI::OpenCut::godzilla_memsponge
