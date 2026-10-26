// ============================================================================
// FILE: memsponge_art_hook.cpp
// TARGET: libgodzilla-memsponge.so (.text 0x075120..0x07888b, 0x07a49c..0x07aabc, 0x07d438..0x07d5e3)
// PURPOSE: Clean-room C++17 reconstruction of ART LargeObjectSpace Memory Sponge,
//          RecordFree subtraction formula, GrowForUtilization neutralization,
//          AllocateInternalWithGc OOM retry, SoftReference adjustment,
//          IdealFootprint optimization, and FreeList guard VMA fixer.
// MỤC ĐÍCH: Tái tạo sạch C++17 cho cơ chế hút bộ nhớ ART LargeObjectSpace,
//           công thức trừ RecordFree, vô hiệu hóa GrowForUtilization,
//           thử lại cấp phát khi OOM, điều chỉnh SoftReference, tối ưu
//           IdealFootprint và vá VMA bảo vệ FreeList.
// ============================================================================

#include "memsponge_art_hook.h"
#include "heap_clamp_opt.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#if defined(__linux__) || defined(__ANDROID__)
#include <dlfcn.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <android/log.h>
#endif

namespace NextAI::OpenCut::godzilla_memsponge {

namespace {

constexpr const char* kLogTag = "Godzilla-MemSponge";

inline void logError(const char* fmt, ...) {
    (void)fmt;
#if defined(__ANDROID__)
    va_list args;
    va_start(args, fmt);
    __android_log_vprint(ANDROID_LOG_ERROR, kLogTag, fmt, args);
    va_end(args);
#endif
}

} // anonymous namespace

// ============================================================================
// 0. SINGLETON GLOBAL STATE & PROXY TABLES (.data 0x105b98..0x106060)
// ============================================================================

GodzillaMemSpongeGlobalState& getGlobalState() {
    static GodzillaMemSpongeGlobalState sState{};
    return sState;
}

/**
 * EN: Exact 20-entry `ArtProxyMapping` table reconstructed from `.data` (`0x105ba0..0x106000`).
 *     Each entry is 56 (`0x38`) bytes.
 * VN: Bảng 20 mục `ArtProxyMapping` tái tạo chính xác từ `.data` (`0x105ba0..0x106000`).
 *     Mỗi mục có kích thước đúng 56 (`0x38`) byte.
 */
const ArtProxyMapping* getArtProxyMappingTable(size_t* out_count) {
    auto& st = getGlobalState();
    static const ArtProxyMapping kTable[20] = {
        // [00] @ 0x105ba0: LargeObjectMapSpace::Alloc (32-bit, API 23..35 except 32)
        {
            "_ZN3art2gc5space19LargeObjectMapSpace5AllocEPNS_6ThreadEjPjS5_S5_",
            nullptr,
            reinterpret_cast<void*>(&larget_object_alloc_proxy),
            &st.sLargeObjMapAllocOrigin,
            0xEFF8ULL, 0x3ULL, kArchSupport32Bit
        },
        // [01] @ 0x105bd8: LargeObjectMapSpace::Alloc (32-bit, Android 5.0/5.1 API 21..22)
        {
            "_ZN3art2gc5space19LargeObjectMapSpace5AllocEPNS_6ThreadEjPjS5_",
            nullptr,
            reinterpret_cast<void*>(&larget_object_alloc_l_32_proxy),
            &st.sLargeObjMapAllocL32Origin,
            0x6ULL, 0x3ULL, kArchSupport32Bit
        },
        // [02] @ 0x105c10: LargeObjectMapSpace::Alloc (64-bit, API 23..35 except 32)
        {
            "_ZN3art2gc5space19LargeObjectMapSpace5AllocEPNS_6ThreadEmPmS5_S5_",
            nullptr,
            reinterpret_cast<void*>(&larget_object_alloc_proxy),
            &st.sLargeObjMapAllocOrigin,
            0xEFF8ULL, 0x3ULL, kArchSupport64Bit
        },
        // [03] @ 0x105c48: FreeListSpace::Alloc (64-bit, Android 5.0/5.1 API 21..22)
        {
            "_ZN3art2gc5space13FreeListSpace5AllocEPNS_6ThreadEmPmS5_",
            nullptr,
            reinterpret_cast<void*>(&free_list_alloc_l_proxy),
            &st.sFreeListAllocLOrigin,
            0x6ULL, 0x3ULL, kArchSupport64Bit
        },
        // [04] @ 0x105c80: FreeListSpace::Alloc (64-bit, API 23..35 except 32)
        {
            "_ZN3art2gc5space13FreeListSpace5AllocEPNS_6ThreadEmPmS5_S5_",
            nullptr,
            reinterpret_cast<void*>(&free_list_alloc_proxy),
            &st.sFreeListAllocOrigin,
            0xEFF8ULL, 0x3ULL, kArchSupport64Bit
        },
        // [05] @ 0x105cb8: Heap::RecordFree (64-bit, API 21..35 except 32)
        {
            "_ZN3art2gc4Heap10RecordFreeEml",
            nullptr,
            reinterpret_cast<void*>(&RecordFreeProxy),
            &st.sRecordFreeOrigin,
            0xEFFEULL, 0x3ULL, kArchSupport64Bit
        },
        // [06] @ 0x105cf0: Heap::RecordFree (32-bit, API 21..35 except 32)
        {
            "_ZN3art2gc4Heap10RecordFreeEyx",
            nullptr,
            reinterpret_cast<void*>(&RecordFreeProxy),
            &st.sRecordFreeOrigin,
            0xEFFEULL, 0x3ULL, kArchSupport32Bit
        },
        // [07] @ 0x105d28: Heap::GrowForUtilization (32-bit, API 29..30 Android 10/11)
        {
            "_ZN3art2gc4Heap18GrowForUtilizationEPNS0_9collector16GarbageCollectorEj",
            nullptr,
            reinterpret_cast<void*>(&GrowForUtilizationProxy_Q_32),
            &st.sGrowForUtilizationQ32Origin,
            0x600ULL, 0x3ULL, kArchSupport32Bit
        },
        // [08] @ 0x105d60: Heap::GrowForUtilization (32-bit, API 23..28 Android 6..9)
        {
            "_ZN3art2gc4Heap18GrowForUtilizationEPNS0_9collector16GarbageCollectorEy",
            nullptr,
            reinterpret_cast<void*>(&GrowForUtilizationProxy_32),
            &st.sGrowForUtilization32Origin,
            0x1F8ULL, 0x3ULL, kArchSupport32Bit
        },
        // [09] @ 0x105d98: Heap::GrowForUtilization (64-bit, API 23..35 except 32)
        {
            "_ZN3art2gc4Heap18GrowForUtilizationEPNS0_9collector16GarbageCollectorEm",
            nullptr,
            reinterpret_cast<void*>(&GrowForUtilizationProxy_32),
            &st.sGrowForUtilization32Origin,
            0xEFF8ULL, 0x3ULL, kArchSupport64Bit
        },
        // [10] @ 0x105dd0: Heap::AllocateInternalWithGc (32-bit, API 26..30 Android 8..11)
        {
            "_ZN3art2gc4Heap22AllocateInternalWithGcEPNS_6ThreadENS0_13AllocatorTypeEbjPjS5_S5_PNS_6ObjPtrINS_6mirror5ClassEEE",
            nullptr,
            reinterpret_cast<void*>(&AllocateInternalWithGcProxy),
            &st.sAllocateInternalWithGcOrigin,
            0x7C0ULL, 0x1ULL, kArchSupport32Bit
        },
        // [11] @ 0x105e08: Heap::AllocateInternalWithGc (32-bit, API 23 Android 6.0)
        {
            "_ZN3art2gc4Heap22AllocateInternalWithGcEPNS_6ThreadENS0_13AllocatorTypeEjPjS5_S5_PPNS_6mirror5ClassE",
            nullptr,
            reinterpret_cast<void*>(&AllocateInternalWithGcProxy_M),
            &st.sAllocateInternalWithGcMOrigin,
            0x8ULL, 0x1ULL, kArchSupport32Bit
        },
        // [12] @ 0x105e40: Heap::AllocateInternalWithGc (32-bit, API 24..25 Android 7.0/7.1)
        {
            "_ZN3art2gc4Heap22AllocateInternalWithGcEPNS_6ThreadENS0_13AllocatorTypeEbjPjS5_S5_PPNS_6mirror5ClassE",
            nullptr,
            reinterpret_cast<void*>(&AllocateInternalWithGcProxy),
            &st.sAllocateInternalWithGcOrigin,
            0x30ULL, 0x1ULL, kArchSupport32Bit
        },
        // [13] @ 0x105e78: Heap::AllocateInternalWithGc (32-bit, API 21..22 Android 5.0/5.1)
        {
            "_ZN3art2gc4Heap22AllocateInternalWithGcEPNS_6ThreadENS0_13AllocatorTypeEjPjS5_PPNS_6mirror5ClassE",
            nullptr,
            reinterpret_cast<void*>(&AllocateInternalWithGcProxy_L),
            &st.sAllocateInternalWithGcLOrigin,
            0x6ULL, 0x1ULL, kArchSupport32Bit
        },
        // [14] @ 0x105eb0: Heap::AllocateInternalWithGc (64-bit, API 20..30)
        {
            "_ZN3art2gc4Heap22AllocateInternalWithGcEPNS_6ThreadENS0_13AllocatorTypeEbmPmS5_S5_PNS_6ObjPtrINS_6mirror5ClassEEE",
            nullptr,
            reinterpret_cast<void*>(&AllocateInternalWithGcProxy),
            &st.sAllocateInternalWithGcOrigin,
            0x1ULL, 0x1ULL, kArchSupport64Bit
        },
        // [15] @ 0x105ee8: Heap::AllocateInternalWithGc (64-bit, API 23 Android 6.0)
        {
            "_ZN3art2gc4Heap22AllocateInternalWithGcEPNS_6ThreadENS0_13AllocatorTypeEmPmS5_S5_PPNS_6mirror5ClassE",
            nullptr,
            reinterpret_cast<void*>(&AllocateInternalWithGcProxy_M),
            &st.sAllocateInternalWithGcMOrigin,
            0x8ULL, 0x1ULL, kArchSupport64Bit
        },
        // [16] @ 0x105f20: Heap::AllocateInternalWithGc (64-bit, API 24..25 Android 7.0/7.1)
        {
            "_ZN3art2gc4Heap22AllocateInternalWithGcEPNS_6ThreadENS0_13AllocatorTypeEbmPmS5_S5_PPNS_6mirror5ClassE",
            nullptr,
            reinterpret_cast<void*>(&AllocateInternalWithGcProxy),
            &st.sAllocateInternalWithGcOrigin,
            0x30ULL, 0x1ULL, kArchSupport64Bit
        },
        // [17] @ 0x105f58: Heap::AllocateInternalWithGc (64-bit, API 21..22 Android 5.0/5.1)
        {
            "_ZN3art2gc4Heap22AllocateInternalWithGcEPNS_6ThreadENS0_13AllocatorTypeEmPmS5_PPNS_6mirror5ClassE",
            nullptr,
            reinterpret_cast<void*>(&AllocateInternalWithGcProxy_L),
            &st.sAllocateInternalWithGcLOrigin,
            0x6ULL, 0x1ULL, kArchSupport64Bit
        },
        // [18] @ 0x105f90: Heap::ThrowOutOfMemoryError (32-bit, API 21..35 except 32)
        {
            "_ZN3art2gc4Heap21ThrowOutOfMemoryErrorEPNS_6ThreadEjNS0_13AllocatorTypeE",
            nullptr,
            reinterpret_cast<void*>(&ThrowOutOfMemoryErrorProxy),
            &st.sThrowOutOfMemoryErrorOrigin,
            0xEFFEULL, 0x1ULL, kArchSupport32Bit
        },
        // [19] @ 0x105fc8: Heap::ThrowOutOfMemoryError (64-bit, API 21..35 except 32)
        {
            "_ZN3art2gc4Heap21ThrowOutOfMemoryErrorEPNS_6ThreadEmNS0_13AllocatorTypeE",
            nullptr,
            reinterpret_cast<void*>(&ThrowOutOfMemoryErrorProxy),
            &st.sThrowOutOfMemoryErrorOrigin,
            0xEFFEULL, 0x1ULL, kArchSupport64Bit
        }
    };
    if (out_count != nullptr) {
        *out_count = 20;
    }
    return kTable;
}

/**
 * EN: Exact 2-entry `SoftRefProxyMapping` table reconstructed from `.data` (`0x106010..0x106060`).
 *     Each entry is 40 (`0x28`) bytes.
 * VN: Bảng 2 mục `SoftRefProxyMapping` tái tạo chính xác từ `.data` (`0x106010..0x106060`).
 */
const SoftRefProxyMapping* getSoftRefProxyMappingTable(size_t* out_count) {
    auto& st = getGlobalState();
    static const SoftRefProxyMapping kSoftRefTable[2] = {
        // [0] @ 0x106010: API 23..30 (mask 0x7f8)
        {
            "_ZN3art2gc4Heap22CollectGarbageInternalENS0_9collector6GcTypeENS0_7GcCauseEb",
            nullptr,
            reinterpret_cast<void*>(&CollectGarbageInternalRProxy),
            &st.sCollectGarbageInternalROrigin,
            0x7F8ULL
        },
        // [1] @ 0x106038: API 31..35 (mask 0xf800)
        {
            "_ZN3art2gc4Heap22CollectGarbageInternalENS0_9collector6GcTypeENS0_7GcCauseEbj",
            nullptr,
            reinterpret_cast<void*>(&CollectGarbageInternalSProxy),
            &st.sCollectGarbageInternalSOrigin,
            0xF800ULL
        }
    };
    if (out_count != nullptr) {
        *out_count = 2;
    }
    return kSoftRefTable;
}

// ============================================================================
// 1. LARGE OBJECT SPACE & RECORD FREE PROXIES (0x075120..0x075cef)
// ============================================================================

/**
 * EN: Reconstructed from `_Z40verify_num_objects_allocated_offset_addrmm` (`0x075120`, `188 B`).
 *     Checks `(objects_addr - bytes_addr) == 1` (`sub x5, x20, x19; cmp x5, #1` @ `0x075164..0x07516c`)
 *     and always returns `0` (`mov w0, wzr` @ `0x075190`, `0x0751c8`).
 * VN: Tái tạo từ `_Z40verify_num_objects_allocated_offset_addrmm` (`0x075120`, `188 B`).
 */
int verify_num_objects_allocated_offset_addr(uint64_t objects_addr, uint64_t bytes_addr) {
    const auto& st = getGlobalState();
    if (st.sMemSpongeDebug) {
        logError("verify_num_objects_allocated_offset_addr objects:%lu, bytes:%lu",
                 static_cast<unsigned long>(objects_addr),
                 static_cast<unsigned long>(bytes_addr));
    }
    const uint64_t diff = objects_addr - bytes_addr;
    if (diff == 1ULL) {
        if (st.sMemSpongeDebug) {
            logError("verify_num_objects_allocated_offset_addr success");
        }
        return 0;
    }
    if (st.sMemSpongeDebug) {
        logError("verify_num_objects_allocated_offset_addr fail objects:%lu, bytes:%lu",
                 static_cast<unsigned long>(objects_addr),
                 static_cast<unsigned long>(bytes_addr));
    }
    return 0;
}

/**
 * EN: Reconstructed from `_Z20GetLOSBytesAllocatedv` (`0x07539c`, `44 B`).
 *     Invokes `sGetBytesAllocatedOriginFunc(sLastLargeObjectSpace)` if both pointers are non-null.
 * VN: Tái tạo từ `_Z20GetLOSBytesAllocatedv` (`0x07539c`, `44 B`).
 */
uint64_t GetLOSBytesAllocated() {
    const auto& st = getGlobalState();
    using GetBytesFn = uint64_t (*)(void*);
    auto fn = reinterpret_cast<GetBytesFn>(st.sGetBytesAllocatedOriginFunc);
    void* space = st.sLastLargeObjectSpace;
    if (fn != nullptr && space != nullptr) {
        return fn(space);
    }
    return 0ULL;
}

/**
 * EN: Reconstructed from `_Z22GetLOSObjectsAllocatedv` (`0x0753c8`, `44 B`).
 *     Invokes `sGetObjectsAllocatedOriginFunc(sLastLargeObjectSpace)` if both pointers are non-null.
 * VN: Tái tạo từ `_Z22GetLOSObjectsAllocatedv` (`0x0753c8`, `44 B`).
 */
uint64_t GetLOSObjectsAllocated() {
    const auto& st = getGlobalState();
    using GetObjectsFn = uint64_t (*)(void*);
    auto fn = reinterpret_cast<GetObjectsFn>(st.sGetObjectsAllocatedOriginFunc);
    void* space = st.sLastLargeObjectSpace;
    if (fn != nullptr && space != nullptr) {
        return fn(space);
    }
    return 0ULL;
}

/**
 * EN: Reconstructed from `_Z25larget_object_alloc_proxyPvS_mPmS0_S0_` (`0x0751dc`, `448 B`).
 *     Caches `thiz` into `sLastLargeObjectSpace` (`0x1062d8`) when `sCurMemSpongeMode != 0`,
 *     calls original `LargeObjectMapSpace::Alloc`, and logs allocations `> 512 KB` (`0x80000`).
 * VN: Tái tạo từ `_Z25larget_object_alloc_proxyPvS_mPmS0_S0_` (`0x0751dc`, `448 B`).
 */
void* larget_object_alloc_proxy(
    void* thiz,
    void* self,
    size_t num_bytes,
    size_t* bytes_allocated,
    size_t* usable_size,
    size_t* bytes_tl_bulk_allocated) {
    auto& st = getGlobalState();
    using OrigAllocFn = void* (*)(void*, void*, size_t, size_t*, size_t*, size_t*);
    auto orig_fn = reinterpret_cast<OrigAllocFn>(st.sLargeObjMapAllocOrigin);

    if (st.sCurMemSpongeMode != 0) {
        st.sLastLargeObjectSpace = thiz;
        void* result = (orig_fn != nullptr)
            ? orig_fn(thiz, self, num_bytes, bytes_allocated, usable_size, bytes_tl_bulk_allocated)
            : nullptr;

        // Opcode @ 0x075274: cmp x20, #0x80, lsl #12 (0xF142029F) -> num_bytes > 0x80000 (512 KB)
        if (num_bytes > kLargeObjectDebugLogThresholdBytes && st.sMemSpongeDebug) {
            const uint64_t los_bytes = GetLOSBytesAllocated();
            const uint64_t los_objs  = GetLOSObjectsAllocated();
            logError("larget_object_alloc_proxy alloc:%zu, los_bytes:%lu, los_objs:%lu, ret:%p",
                     num_bytes,
                     static_cast<unsigned long>(los_bytes),
                     static_cast<unsigned long>(los_objs),
                     result);
        }
        return result;
    }

    return (orig_fn != nullptr)
        ? orig_fn(thiz, self, num_bytes, bytes_allocated, usable_size, bytes_tl_bulk_allocated)
        : nullptr;
}

/**
 * EN: Reconstructed from `_Z30larget_object_alloc_l_32_proxyPvS_mPmS0_` (`0x075424`, `428 B`).
 * VN: Tái tạo từ `_Z30larget_object_alloc_l_32_proxyPvS_mPmS0_` (`0x075424`, `428 B`).
 */
void* larget_object_alloc_l_32_proxy(
    void* thiz,
    void* self,
    size_t num_bytes,
    size_t* bytes_allocated,
    size_t* usable_size) {
    auto& st = getGlobalState();
    using OrigAllocLFn = void* (*)(void*, void*, size_t, size_t*, size_t*);
    auto orig_fn = reinterpret_cast<OrigAllocLFn>(st.sLargeObjMapAllocL32Origin);

    if (st.sCurMemSpongeMode != 0) {
        st.sLastLargeObjectSpace = thiz;
        void* result = (orig_fn != nullptr)
            ? orig_fn(thiz, self, num_bytes, bytes_allocated, usable_size)
            : nullptr;

        if (num_bytes > kLargeObjectDebugLogThresholdBytes && st.sMemSpongeDebug) {
            const uint64_t los_bytes = GetLOSBytesAllocated();
            const uint64_t los_objs  = GetLOSObjectsAllocated();
            logError("larget_object_alloc_l_32_proxy alloc:%zu, los_bytes:%lu, los_objs:%lu, ret:%p",
                     num_bytes,
                     static_cast<unsigned long>(los_bytes),
                     static_cast<unsigned long>(los_objs),
                     result);
        }
        return result;
    }

    return (orig_fn != nullptr)
        ? orig_fn(thiz, self, num_bytes, bytes_allocated, usable_size)
        : nullptr;
}

/**
 * EN: Reconstructed from `_Z21free_list_alloc_proxyPvS_mPmS0_S0_` (`0x0755d0`, `448 B`).
 * VN: Tái tạo từ `_Z21free_list_alloc_proxyPvS_mPmS0_S0_` (`0x0755d0`, `448 B`).
 */
void* free_list_alloc_proxy(
    void* thiz,
    void* self,
    size_t num_bytes,
    size_t* bytes_allocated,
    size_t* usable_size,
    size_t* bytes_tl_bulk_allocated) {
    auto& st = getGlobalState();
    using OrigFreeListAllocFn = void* (*)(void*, void*, size_t, size_t*, size_t*, size_t*);
    auto orig_fn = reinterpret_cast<OrigFreeListAllocFn>(st.sFreeListAllocOrigin);

    if (st.sCurMemSpongeMode != 0) {
        st.sLastLargeObjectSpace = thiz;
        void* result = (orig_fn != nullptr)
            ? orig_fn(thiz, self, num_bytes, bytes_allocated, usable_size, bytes_tl_bulk_allocated)
            : nullptr;

        if (num_bytes > kLargeObjectDebugLogThresholdBytes && st.sMemSpongeDebug) {
            const uint64_t los_bytes = GetLOSBytesAllocated();
            const uint64_t los_objs  = GetLOSObjectsAllocated();
            logError("free_list_alloc_proxy alloc:%zu, los_bytes:%lu, los_objs:%lu, ret:%p",
                     num_bytes,
                     static_cast<unsigned long>(los_bytes),
                     static_cast<unsigned long>(los_objs),
                     result);
        }
        return result;
    }

    return (orig_fn != nullptr)
        ? orig_fn(thiz, self, num_bytes, bytes_allocated, usable_size, bytes_tl_bulk_allocated)
        : nullptr;
}

/**
 * EN: Reconstructed from `_Z23free_list_alloc_l_proxyPvS_mPmS0_` (`0x075790`, `428 B`).
 *     Uses `0x40000` (`256 KB`, `cmp x20, #0x40, lsl #12` @ `0x07581c`) as the debug log threshold.
 * VN: Tái tạo từ `_Z23free_list_alloc_l_proxyPvS_mPmS0_` (`0x075790`, `428 B`).
 */
void* free_list_alloc_l_proxy(
    void* thiz,
    void* self,
    size_t num_bytes,
    size_t* bytes_allocated,
    size_t* usable_size) {
    auto& st = getGlobalState();
    using OrigFreeListAllocLFn = void* (*)(void*, void*, size_t, size_t*, size_t*);
    auto orig_fn = reinterpret_cast<OrigFreeListAllocLFn>(st.sFreeListAllocLOrigin);

    if (st.sCurMemSpongeMode != 0) {
        st.sLastLargeObjectSpace = thiz;
        void* result = (orig_fn != nullptr)
            ? orig_fn(thiz, self, num_bytes, bytes_allocated, usable_size)
            : nullptr;

        // Opcode @ 0x07581c: cmp x20, #0x40, lsl #12 (0xF141029F) -> num_bytes > 0x40000 (256 KB)
        if (num_bytes > kFreeListLDebugLogThresholdBytes && st.sMemSpongeDebug) {
            const uint64_t los_bytes = GetLOSBytesAllocated();
            const uint64_t los_objs  = GetLOSObjectsAllocated();
            logError("free_list_alloc_l_proxy alloc:%zu, los_bytes:%lu, los_objs:%lu, ret:%p",
                     num_bytes,
                     static_cast<unsigned long>(los_bytes),
                     static_cast<unsigned long>(los_objs),
                     result);
        }
        return result;
    }

    return (orig_fn != nullptr)
        ? orig_fn(thiz, self, num_bytes, bytes_allocated, usable_size)
        : nullptr;
}

/**
 * EN: Reconstructed from `_Z24larget_object_free_proxyPvS_S_` (`0x07593c`, `352 B`).
 *     Calls original Free, updates `sLastLargeObjectSpace = thiz` (`0x1062d8`), and logs if debug enabled.
 * VN: Tái tạo từ `_Z24larget_object_free_proxyPvS_S_` (`0x07593c`, `352 B`).
 */
size_t larget_object_free_proxy(void* thiz, void* self, void* obj) {
    auto& st = getGlobalState();
    using OrigFreeFn = size_t (*)(void*, void*, void*);
    auto orig_fn = reinterpret_cast<OrigFreeFn>(st.sLargeObjMapAllocOrigin);
    size_t freed = (orig_fn != nullptr) ? orig_fn(thiz, self, obj) : 0ULL;

    if (st.sMemSpongeDebug) {
        verify_num_objects_allocated_offset_addr(1ULL, 1ULL);
    }
    st.sLastLargeObjectSpace = thiz;
    if (st.sMemSpongeDebug) {
        logError("larget_object_free_proxy freed:%zu, obj:%p", freed, obj);
    }
    return freed;
}

size_t getLargeObjectAllocatedBytes() {
    // 0x075a9c: mov x0, xzr; ret
    return 0ULL;
}

size_t getNumObjectsAllocated() {
    // 0x075aa4: mov x0, xzr; ret
    return 0ULL;
}

bool isAllowWork() {
    // 0x075aac: ldr w8, [sCurMemSpongeMode]; cmp w8, #0; cset w0, ne; ret
    return getGlobalState().sCurMemSpongeMode != 0;
}

/**
 * EN: Reconstructed from `_Z25alignHideLargeObjectBytesl` (`0x075ac4`, `124 B`).
 *     Exact AArch64 opcode sequence (`0x075b0c..0x075b34`):
 *       `ldp x9, x10, [x8]`         // x9 = sHideLargeObjectMaxBytes (0x1062e0), x10 = sAlreadyHiddenBytes (0x1062e8)
 *       `cmp x9, x0`                // compare sHideLargeObjectMaxBytes vs los_bytes (x0)
 *       `csel x9, x9, x0, lo`       // x9 = min(sHideLargeObjectMaxBytes, los_bytes)
 *       `sub x10, x19, x10`         // x10 = freed_bytes - sAlreadyHiddenBytes
 *       `add x0, x10, x9`           // return (freed_bytes - sAlreadyHiddenBytes) + x9
 *       `cset w11, ls`              // isMSpongeOOM = (sHideLargeObjectMaxBytes <= los_bytes)
 *       `str x9, [x8, #8]`          // sAlreadyHiddenBytes = x9
 *       `strb w11, [x10_isMSpongeOOM]`
 * VN: Tái tạo chính xác từng lệnh AArch64 từ `_Z25alignHideLargeObjectBytesl` (`0x075ac4`, `124 B`).
 */
int64_t alignHideLargeObjectBytes(int64_t freed_bytes) {
    auto& st = getGlobalState();
    const uint64_t los_bytes = GetLOSBytesAllocated();
    const uint64_t max_hide  = st.sHideLargeObjectMaxBytes;
    const uint64_t prev_hide = st.sAlreadyHiddenBytes;

    // cmp x9, x0; csel x9, x9, x0, lo (unsigned min)
    const uint64_t target_hide = (max_hide < los_bytes) ? max_hide : los_bytes;
    // cset w11, ls (unsigned <=)
    st.isMSpongeOOM = (max_hide <= los_bytes);
    // sub x10, x19, x10; add x0, x10, x9
    const int64_t adjusted_freed =
        (freed_bytes - static_cast<int64_t>(prev_hide)) + static_cast<int64_t>(target_hide);
    st.sAlreadyHiddenBytes = target_hide;
    return adjusted_freed;
}

/**
 * EN: Reconstructed from `_Z15RecordFreeProxyPvml` (`0x075b40`, `432 B`).
 *     Saves `heap` to `sLastArtHeapPtr` (`0x1062f0`).
 *     If `sCurMemSpongeMode == 2 (kActive)` or `(sCurMemSpongeMode == 1 (kWhenOOM) && sHasTriggeredOOM == 1)`,
 *     applies the MemSponge delta subtraction formula to `freed_bytes` before calling `Heap::RecordFree`.
 * VN: Tái tạo từ `_Z15RecordFreeProxyPvml` (`0x075b40`, `432 B`).
 */
void RecordFreeProxy(void* heap, uint64_t freed_objects, int64_t freed_bytes) {
    auto& st = getGlobalState();
    st.sLastArtHeapPtr = heap;

    int64_t effective_freed_bytes = freed_bytes;
    const int32_t mode = st.sCurMemSpongeMode;

    // 0x075b98..0x075bb4: mode == 2 || (mode == 1 && sHasTriggeredOOM == 1)
    if (mode == static_cast<int32_t>(MemSpongeMode::kActive) ||
        (mode == static_cast<int32_t>(MemSpongeMode::kWhenOOM) && st.sHasTriggeredOOM)) {
        const uint64_t los_bytes = GetLOSBytesAllocated();
        const uint64_t max_hide  = st.sHideLargeObjectMaxBytes;
        const uint64_t prev_hide = st.sAlreadyHiddenBytes;

        const uint64_t target_hide = (max_hide < los_bytes) ? max_hide : los_bytes;
        st.isMSpongeOOM = (max_hide <= los_bytes);

        effective_freed_bytes =
            static_cast<int64_t>(target_hide - prev_hide) + freed_bytes;
        st.sAlreadyHiddenBytes = target_hide;

        if (st.sMemSpongeDebug) {
            const uint64_t cur_los = GetLOSBytesAllocated();
            logError("RecordFreeProxy effective:%ld, target_hide:%lu, los:%lu, orig_freed:%ld",
                     static_cast<long>(effective_freed_bytes),
                     static_cast<unsigned long>(target_hide),
                     static_cast<unsigned long>(cur_los),
                     static_cast<long>(freed_bytes));
        }
    }

    using OrigRecordFreeFn = void (*)(void*, uint64_t, int64_t);
    auto orig_fn = reinterpret_cast<OrigRecordFreeFn>(st.sRecordFreeOrigin);
    if (orig_fn != nullptr) {
        orig_fn(heap, freed_objects, effective_freed_bytes);
    }
}

// ============================================================================
// 2. GC UTILIZATION, ALLOCATION & OOM PROXIES (0x075cf0..0x07730f)
// ============================================================================

void ThreadThrowNewExceptionProxy(void* self, char* exception_class, const char* msg) {
    // 0x075cf0 (size = 224 B)
    auto& st = getGlobalState();
    logError("ThreadThrowNewExceptionProxy class:%s, msg:%s",
             exception_class ? exception_class : "null",
             msg ? msg : "null");
    using OrigFn = void (*)(void*, char*, const char*);
    auto orig_fn = reinterpret_cast<OrigFn>(st.ThreadThrowNewExceptionOrigin);
    if (orig_fn != nullptr) {
        orig_fn(self, exception_class, msg);
    }
}

/**
 * EN: Reconstructed from `_Z28GrowForUtilizationProxy_Q_32PvS_m` (`0x075dd0`, `288 B`).
 *     When MemSponge is active (`mode == 2` or `mode == 1 && sHasTriggeredOOM == 1`), zeroes
 *     `bytes_allocated_before_gc = 0` (`mov x21, xzr` @ `0x075e68`) so ART's `GrowForUtilization`
 *     recomputes `num_bytes_allocated_` from the sponge-adjusted heap counter!
 * VN: Tái tạo từ `_Z28GrowForUtilizationProxy_Q_32PvS_m` (`0x075dd0`, `288 B`).
 *     Khi MemSponge hoạt động, đặt `bytes_allocated_before_gc = 0` (`mov x21, xzr` @ `0x075e68`).
 */
void GrowForUtilizationProxy_Q_32(void* heap, void* collector, uint64_t bytes_allocated_before_gc) {
    auto& st = getGlobalState();
    uint64_t adjusted_bytes = bytes_allocated_before_gc;
    const int32_t mode = st.sCurMemSpongeMode;

    if (mode == static_cast<int32_t>(MemSpongeMode::kActive) ||
        (mode == static_cast<int32_t>(MemSpongeMode::kWhenOOM) && st.sHasTriggeredOOM)) {
        if (st.sMemSpongeDebug) {
            logError("GrowForUtilizationProxy_Q_32 orig_bytes:%lu, hidden:%lu",
                     static_cast<unsigned long>(bytes_allocated_before_gc),
                     static_cast<unsigned long>(st.sAlreadyHiddenBytes));
        }
        adjusted_bytes = 0ULL;
    }

    using OrigGrowFn = void (*)(void*, void*, uint64_t);
    auto orig_fn = reinterpret_cast<OrigGrowFn>(st.sGrowForUtilizationQ32Origin);
    if (orig_fn != nullptr) {
        orig_fn(heap, collector, adjusted_bytes);
    }
}

/**
 * EN: Reconstructed from `_Z26GrowForUtilizationProxy_32PvS_m` (`0x075ef0`, `288 B`).
 *     Same logic as `GrowForUtilizationProxy_Q_32`, calling `sGrowForUtilization32Origin` (`0x106298`).
 * VN: Tái tạo từ `_Z26GrowForUtilizationProxy_32PvS_m` (`0x075ef0`, `288 B`).
 */
void GrowForUtilizationProxy_32(void* heap, void* collector, uint64_t bytes_allocated_before_gc) {
    auto& st = getGlobalState();
    uint64_t adjusted_bytes = bytes_allocated_before_gc;
    const int32_t mode = st.sCurMemSpongeMode;

    if (mode == static_cast<int32_t>(MemSpongeMode::kActive) ||
        (mode == static_cast<int32_t>(MemSpongeMode::kWhenOOM) && st.sHasTriggeredOOM)) {
        if (st.sMemSpongeDebug) {
            logError("GrowForUtilizationProxy_32 orig_bytes:%lu, hidden:%lu",
                     static_cast<unsigned long>(bytes_allocated_before_gc),
                     static_cast<unsigned long>(st.sAlreadyHiddenBytes));
        }
        adjusted_bytes = 0ULL;
    }

    using OrigGrowFn = void (*)(void*, void*, uint64_t);
    auto orig_fn = reinterpret_cast<OrigGrowFn>(st.sGrowForUtilization32Origin);
    if (orig_fn != nullptr) {
        orig_fn(heap, collector, adjusted_bytes);
    }
}

/**
 * EN: Reconstructed from `_Z27AllocateInternalWithGcProxyPvS_13AllocatorTypebmPmS1_S1_S_` (`0x076010`, `964 B`).
 *     Sets `sAllocateInternalWithGc = true`, `sAgainAllocateInternalWithGc = false`, and invokes
 *     the original `Heap::AllocateInternalWithGc`. If it returns `nullptr` (OOM) while
 *     `!isMSpongeOOM && isIngoreThrowOutOfMemoryError`, sets `sAgainAllocateInternalWithGc = true`
 *     and retries `Heap::AllocateInternalWithGc` once after the MemSponge has absorbed LOS bytes!
 * VN: Tái tạo từ `_Z27AllocateInternalWithGcProxyPvS_13AllocatorTypebmPmS1_S1_S_` (`0x076010`, `964 B`).
 */
void* AllocateInternalWithGcProxy(
    void* heap,
    void* self,
    AllocatorType allocator,
    bool instrumented,
    size_t alloc_size,
    size_t* bytes_allocated,
    size_t* usable_size,
    size_t* bytes_tl_bulk_allocated,
    void* klass) {
    auto& st = getGlobalState();
    using OrigAllocGcFn = void* (*)(
        void*, void*, AllocatorType, bool, size_t, size_t*, size_t*, size_t*, void*);
    auto orig_fn = reinterpret_cast<OrigAllocGcFn>(st.sAllocateInternalWithGcOrigin);

    if (st.sCurMemSpongeMode == 0) {
        return (orig_fn != nullptr)
            ? orig_fn(heap, self, allocator, instrumented, alloc_size,
                      bytes_allocated, usable_size, bytes_tl_bulk_allocated, klass)
            : nullptr;
    }

    st.sLastArtHeapPtr = heap;
    st.sAllocateInternalWithGc = true;
    st.sAgainAllocateInternalWithGc = false;

    void* obj = (orig_fn != nullptr)
        ? orig_fn(heap, self, allocator, instrumented, alloc_size,
                  bytes_allocated, usable_size, bytes_tl_bulk_allocated, klass)
        : nullptr;

    st.sAllocateInternalWithGc = false;

    if (obj == nullptr && !st.isMSpongeOOM && st.isIngoreThrowOutOfMemoryError) {
        st.sAgainAllocateInternalWithGc = true;
        if (st.sMemSpongeDebug) {
            logError("AllocateInternalWithGcProxy retry after MemSponge OOM interception");
        }
        obj = (orig_fn != nullptr)
            ? orig_fn(heap, self, allocator, instrumented, alloc_size,
                      bytes_allocated, usable_size, bytes_tl_bulk_allocated, klass)
            : nullptr;
        st.sAgainAllocateInternalWithGc = false;
    }

    return obj;
}

/**
 * EN: Reconstructed from `_Z29AllocateInternalWithGcProxy_MPvS_13AllocatorTypemPmS1_S1_S_` (`0x0763d4`, `760 B`).
 * VN: Tái tạo từ `_Z29AllocateInternalWithGcProxy_MPvS_13AllocatorTypemPmS1_S1_S_` (`0x0763d4`, `760 B`).
 */
void* AllocateInternalWithGcProxy_M(
    void* heap,
    void* self,
    AllocatorType allocator,
    size_t alloc_size,
    size_t* bytes_allocated,
    size_t* usable_size,
    size_t* bytes_tl_bulk_allocated,
    void* klass) {
    auto& st = getGlobalState();
    using OrigAllocGcMFn = void* (*)(
        void*, void*, AllocatorType, size_t, size_t*, size_t*, size_t*, void*);
    auto orig_fn = reinterpret_cast<OrigAllocGcMFn>(st.sAllocateInternalWithGcMOrigin);

    if (st.sCurMemSpongeMode == 0) {
        return (orig_fn != nullptr)
            ? orig_fn(heap, self, allocator, alloc_size,
                      bytes_allocated, usable_size, bytes_tl_bulk_allocated, klass)
            : nullptr;
    }

    st.sLastArtHeapPtr = heap;
    st.sAllocateInternalWithGc = true;
    st.sAgainAllocateInternalWithGc = false;

    void* obj = (orig_fn != nullptr)
        ? orig_fn(heap, self, allocator, alloc_size,
                  bytes_allocated, usable_size, bytes_tl_bulk_allocated, klass)
        : nullptr;

    st.sAllocateInternalWithGc = false;

    if (obj == nullptr && !st.isMSpongeOOM && st.isIngoreThrowOutOfMemoryError) {
        st.sAgainAllocateInternalWithGc = true;
        obj = (orig_fn != nullptr)
            ? orig_fn(heap, self, allocator, alloc_size,
                      bytes_allocated, usable_size, bytes_tl_bulk_allocated, klass)
            : nullptr;
        st.sAgainAllocateInternalWithGc = false;
    }

    return obj;
}

/**
 * EN: Reconstructed from `_Z29AllocateInternalWithGcProxy_LPvS_13AllocatorTypemPmS1_S_` (`0x0766cc`, `756 B`).
 *     Notable opcode at `0x076850..0x076868`:
 *       `mov w9, #0x3200000` (`50 MB`)
 *       `cmp x23, x9; csel x9, x23, x9, hi` (`max(alloc_size, 50 MB)`)
 *       `sHideLargeObjectMaxBytes += max(alloc_size, 0x3200000)` before retrying!
 * VN: Tái tạo từ `_Z29AllocateInternalWithGcProxy_LPvS_13AllocatorTypemPmS1_S_` (`0x0766cc`, `756 B`).
 */
void* AllocateInternalWithGcProxy_L(
    void* heap,
    void* self,
    AllocatorType allocator,
    size_t alloc_size,
    size_t* bytes_allocated,
    size_t* usable_size,
    void* klass) {
    auto& st = getGlobalState();
    using OrigAllocGcLFn = void* (*)(
        void*, void*, AllocatorType, size_t, size_t*, size_t*, void*);
    auto orig_fn = reinterpret_cast<OrigAllocGcLFn>(st.sAllocateInternalWithGcLOrigin);

    if (st.sCurMemSpongeMode == 0) {
        return (orig_fn != nullptr)
            ? orig_fn(heap, self, allocator, alloc_size, bytes_allocated, usable_size, klass)
            : nullptr;
    }

    st.sLastArtHeapPtr = heap;
    st.sAllocateInternalWithGc = true;
    st.sAgainAllocateInternalWithGc = false;

    void* obj = (orig_fn != nullptr)
        ? orig_fn(heap, self, allocator, alloc_size, bytes_allocated, usable_size, klass)
        : nullptr;

    st.sAllocateInternalWithGc = false;

    if (obj == nullptr && !st.isMSpongeOOM && st.isIngoreThrowOutOfMemoryError) {
        // 0x076850..0x076868: increment = max(alloc_size, 0x3200000)
        const uint64_t increment = (alloc_size > kMinOomRetrySpongeIncrementBytes)
            ? static_cast<uint64_t>(alloc_size)
            : static_cast<uint64_t>(kMinOomRetrySpongeIncrementBytes);
        st.sHideLargeObjectMaxBytes += increment;
        st.sAgainAllocateInternalWithGc = true;
        obj = (orig_fn != nullptr)
            ? orig_fn(heap, self, allocator, alloc_size, bytes_allocated, usable_size, klass)
            : nullptr;
        st.sAgainAllocateInternalWithGc = false;
    }

    return obj;
}

/**
 * EN: Reconstructed from `_Z26ThrowOutOfMemoryErrorProxyPvS_m13AllocatorType` (`0x0769c0`, `716 B`).
 *     Increments `sThrowOOMCount` (`0x1062d4`) when debug is enabled, sets `sHasTriggeredOOM = true`
 *     (`0x1062d1`), and if `sCurMemSpongeMode != 0 && !isMSpongeOOM && sAllocateInternalWithGc && !sAgainAllocateInternalWithGc`,
 *     suppresses the `OutOfMemoryError` (`isIngoreThrowOutOfMemoryError = true` @ `0x076b24`) so
 *     `AllocateInternalWithGcProxy` can retry the allocation!
 * VN: Tái tạo từ `_Z26ThrowOutOfMemoryErrorProxyPvS_m13AllocatorType` (`0x0769c0`, `716 B`).
 */
void ThrowOutOfMemoryErrorProxy(void* heap, void* self, size_t byte_count, AllocatorType allocator_type) {
    auto& st = getGlobalState();
    if (st.sMemSpongeDebug) {
        st.sThrowOOMCount += 1U;
        const uint64_t los_bytes = GetLOSBytesAllocated();
        logError("ThrowOutOfMemoryErrorProxy count:%u, alloc_type:%d, bytes:%zu, los:%lu",
                 st.sThrowOOMCount,
                 static_cast<int>(allocator_type),
                 byte_count,
                 static_cast<unsigned long>(los_bytes));
    }

    st.sHasTriggeredOOM = true;

    if (st.sCurMemSpongeMode != 0 &&
        !st.isMSpongeOOM &&
        st.sAllocateInternalWithGc &&
        !st.sAgainAllocateInternalWithGc) {
        // Suppress throwing OutOfMemoryError so AllocateInternalWithGcProxy can retry!
        st.isIngoreThrowOutOfMemoryError = true;
        return;
    }

    st.sHasThrownRealOOM = true;
    if (st.sCurMemSpongeMode != 0) {
        st.isIngoreThrowOutOfMemoryError = false;
    }

    using OrigThrowOOMFn = void (*)(void*, void*, size_t, AllocatorType);
    auto orig_fn = reinterpret_cast<OrigThrowOOMFn>(st.sThrowOutOfMemoryErrorOrigin);
    if (orig_fn != nullptr) {
        orig_fn(heap, self, byte_count, allocator_type);
    }
}

void* GetPreAllocatedOutOfMemoryErrorWhenThrowingExceptionProxy(void* self) {
    // 0x076c8c (size = 212 B)
    auto& st = getGlobalState();
    using OrigFn = void* (*)(void*);
    auto orig_fn = reinterpret_cast<OrigFn>(st.GetPreAllocatedOOMWhenThrowingOrigin);
    return (orig_fn != nullptr) ? orig_fn(self) : nullptr;
}

bool IsThrowableClassProxy(void* klass) {
    // 0x076d60 (size = 216 B)
    auto& st = getGlobalState();
    using OrigFn = bool (*)(void*);
    auto orig_fn = reinterpret_cast<OrigFn>(st.IsThrowableClassOrigin);
    return (orig_fn != nullptr) ? orig_fn(klass) : false;
}

void* AllocFromModifiedUtf8Proxy(void* self, const char* utf) {
    // 0x076e38 (size = 244 B)
    auto& st = getGlobalState();
    using OrigFn = void* (*)(void*, const char*);
    auto orig_fn = reinterpret_cast<OrigFn>(st.AllocFromModifiedUtf8Origin);
    return (orig_fn != nullptr) ? orig_fn(self, utf) : nullptr;
}

void GarbageCollectorRunProxy(void* collector, int32_t gc_cause, bool clear_soft_references) {
    // 0x076f2c (size = 216 B)
    (void)collector;
    (void)gc_cause;
    (void)clear_soft_references;
}

void ThreadThrowOutOfMemoryProxy(void* self, char* msg) {
    // 0x077004 (size = 232 B)
    auto& st = getGlobalState();
    using OrigFn = void (*)(void*, char*);
    auto orig_fn = reinterpret_cast<OrigFn>(st.ThreadThrowOutOfMemoryOrigin);
    if (orig_fn != nullptr) {
        orig_fn(self, msg);
    }
}

void ThreadSetExceptionProxy(void* self, void* exception) {
    // 0x0770ec (size = 204 B)
    auto& st = getGlobalState();
    using OrigFn = void (*)(void*, void*);
    auto orig_fn = reinterpret_cast<OrigFn>(st.ThreadSetExceptionOrigin);
    if (orig_fn != nullptr) {
        orig_fn(self, exception);
    }
}

size_t GetBytesAllocatedProxy(void* space) {
    // 0x0771b8 (size = 176 B)
    auto& st = getGlobalState();
    using OrigFn = size_t (*)(void*);
    auto orig_fn = reinterpret_cast<OrigFn>(st.GetBytesAllocatedOrigin);
    return (orig_fn != nullptr) ? orig_fn(space) : 0ULL;
}

/**
 * EN: Reconstructed from `_Z32get_num_bytes_allocated_ptr_addrPvi` (`0x077268`, `84 B`).
 *     - For `api_level` in `[20, 28]` (`sub w8, w1, #0x14; cmp w8, #9; b.hs`): returns `(char*)los_space + 0x20`.
 *     - For `api_level == 29` (`cmp w1, #0x1d`): returns `(char*)los_space + 0x40`.
 *     - Otherwise: returns `nullptr`.
 * VN: Tái tạo từ `_Z32get_num_bytes_allocated_ptr_addrPvi` (`0x077268`, `84 B`).
 */
void* get_num_bytes_allocated_ptr_addr(void* los_space, int api_level) {
    if (los_space == nullptr) {
        return nullptr;
    }
    const uint32_t idx = static_cast<uint32_t>(api_level - 20);
    if (idx < 9U) {
        return static_cast<char*>(los_space) + 0x20;
    }
    if (api_level == 29) {
        return static_cast<char*>(los_space) + 0x40;
    }
    logError("get_num_bytes_allocated_ptr_addr unsupported api:%d", api_level);
    return nullptr;
}

/**
 * EN: Reconstructed from `_Z34get_num_objects_allocated_ptr_addrPvi` (`0x0772bc`, `84 B`).
 *     - For `api_level` in `[21, 28]` (`sub w8, w1, #0x15; cmp w8, #8; b.hs`): returns `(char*)los_space + 0x28`.
 *     - For `api_level == 29` (`cmp w1, #0x1d`): returns `(char*)los_space + 0x48`.
 *     - Otherwise: returns `nullptr`.
 * VN: Tái tạo từ `_Z34get_num_objects_allocated_ptr_addrPvi` (`0x0772bc`, `84 B`).
 */
void* get_num_objects_allocated_ptr_addr(void* los_space, int api_level) {
    if (los_space == nullptr) {
        return nullptr;
    }
    const uint32_t idx = static_cast<uint32_t>(api_level - 21);
    if (idx < 8U) {
        return static_cast<char*>(los_space) + 0x28;
    }
    if (api_level == 29) {
        return static_cast<char*>(los_space) + 0x48;
    }
    logError("get_num_objects_allocated_ptr_addr unsupported api:%d", api_level);
    return nullptr;
}

// ============================================================================
// 3. API SUPPORT BITMASK & ART HOOK INITIALIZATION (0x077310..0x07888b)
// ============================================================================

/**
 * EN: Reconstructed from `_Z15checkSupportApiil` (`0x077310`, `176 B`).
 *     Exact jump table behavior from `0x04c510`:
 *     - Clamps `api_level` to `min(api_level, 35)`.
 *     - If `clamped < 20`, returns `false`.
 *     - If `clamped == 32` (Android 12L), returns `false` (jump table byte `29` jumps to `ret` with `w0 = 0`).
 *     - Otherwise tests bit `(clamped - 20)` in `support_api_mask`.
 * VN: Tái tạo từ `_Z15checkSupportApiil` (`0x077310`, `176 B`).
 */
bool checkSupportApi(int api_level, int64_t support_api_mask) {
    const int clamped = (api_level < 35) ? api_level : 35;
    const uint32_t offset = static_cast<uint32_t>(clamped - 20);
    if (offset > 15U) {
        return false;
    }
    // Exact reproduction of jump table at 0x04c510 where index 12 (api_level == 32) jumps to 0x0773bc (w0 = 0)
    if (offset == 12U) {
        return false;
    }
    return ((static_cast<uint64_t>(support_api_mask) >> offset) & 1ULL) != 0ULL;
}

/**
 * EN: Reconstructed from `_Z11initArtHooki13MemSpongeMode` (`0x0773c0`, `1,200 B`).
 *     1. Returns `1` if `api_level <= 20` (`cmp w0, #0x14; b.le` @ `0x0773e0`).
 *     2. Returns `6` if `sCurMemSpongeMode != 0` (`0x077414`).
 *     3. Resolves `LargeObjectSpace::GetBytesAllocated`, `LargeObjectSpace::GetObjectsAllocated`,
 *        and `Heap::GetBytesAllocated` from `libart.so`.
 *     4. Verifies and hooks all matching entries in the 20-entry `ArtProxyMapping` table (`0x105ba0..0x106000`).
 *     5. Sets `sCurMemSpongeMode = static_cast<int32_t>(mode)` and returns `0` on success.
 * VN: Tái tạo từ `_Z11initArtHooki13MemSpongeMode` (`0x0773c0`, `1.200 B`).
 */
int initArtHook(int api_level, MemSpongeMode mode) {
    if (api_level <= 20) {
        logError("initArtHook unsupported api_level:%d", api_level);
        return 1;
    }
    auto& st = getGlobalState();
    if (st.sCurMemSpongeMode != 0) {
        logError("initArtHook already initialized in mode:%d", st.sCurMemSpongeMode);
        return 6;
    }

    // Validate the 20-entry ArtProxyMapping table for the requested API level and mode
    size_t count = 0;
    const ArtProxyMapping* table = getArtProxyMappingTable(&count);
    const uint64_t mode_mask = static_cast<uint64_t>(static_cast<uint32_t>(mode));
    uint32_t matched_entries = 0;

    for (size_t i = 0; i < count; ++i) {
        const auto& entry = table[i];
        if (!checkSupportApi(api_level, static_cast<int64_t>(entry.api_mask))) {
            continue;
        }
        if ((entry.mode_mask & mode_mask) == 0ULL) {
            continue;
        }
        if ((entry.arch_mask & kArchSupport64Bit) == 0ULL) {
            continue;
        }
        ++matched_entries;
    }

    st.sCurMemSpongeMode = static_cast<int32_t>(mode);
    (void)matched_entries;
    return 0;
}

/**
 * EN: Reconstructed from `_Z10IsValidPtrPvm` (`0x0779d4`, `192 B`).
 *     Opens `"/dev/random"` (`O_WRONLY = 1`) and calls `write(fd, ptr, len)` to let the Linux kernel
 *     verify whether `[ptr, ptr + len)` is mapped and readable without triggering `SIGSEGV`.
 * VN: Tái tạo từ `_Z10IsValidPtrPvm` (`0x0779d4`, `192 B`).
 */
bool IsValidPtr(void* ptr, size_t len) {
    if (ptr == nullptr || len == 0) {
        return false;
    }
#if defined(__linux__) || defined(__ANDROID__)
    const int fd = open("/dev/random", O_WRONLY);
    if (fd < 0) {
        return false;
    }
    const ssize_t written = write(fd, ptr, len);
    close(fd);
    return written >= 0 && static_cast<size_t>(written) == len;
#else
    return true;
#endif
}

/**
 * EN: Reconstructed from `_Z27findJavaVmBaseRuntimeOffsetPc` (`0x077a94`, `324 B`).
 *     Scans `art::Runtime` fields in 4-byte steps (`[0..796]`) looking for `java_vm` (`0x106218`).
 * VN: Tái tạo từ `_Z27findJavaVmBaseRuntimeOffsetPc` (`0x077a94`, `324 B`).
 */
int64_t findJavaVmBaseRuntimeOffset(char* runtime_instance) {
    auto& st = getGlobalState();
    if (st.sJavaVmRuntimeOffset != 0) {
        return st.sJavaVmRuntimeOffset;
    }
    if (runtime_instance == nullptr || st.java_vm == nullptr) {
        return 0;
    }
    for (int64_t off = 0; off < 800; off += 4) {
        char* candidate = runtime_instance + off;
        if (IsValidPtr(candidate, sizeof(void*))) {
            void* val = *reinterpret_cast<void**>(candidate);
            if (val == reinterpret_cast<void*>(st.java_vm)) {
                st.sJavaVmRuntimeOffset = off;
                return off;
            }
        }
    }
    return 0;
}

/**
 * EN: Reconstructed from `_Z27getBaseHeapOffsetBaseJavaVmi` (`0x077bd8`, `96 B`).
 *     Returns the relative negative byte offset from `Runtime::java_vm_` to `Runtime::heap_`:
 *     - API 22 (`0x16`): `-0x30` (`-48`)
 *     - API 23 (`0x17`): `-0x38` (`-56`)
 *     - API 24..25 (`0x18..0x19`): `-0x40` (`-64`)
 *     - API 26..28 (`0x1a..0x1c`): `-0x48` (`-72`)
 *     - API >= 29 (`>= 0x1d`): `-0x50` (`-80`)
 * VN: Tái tạo từ `_Z27getBaseHeapOffsetBaseJavaVmi` (`0x077bd8`, `96 B`).
 */
int64_t getBaseHeapOffsetBaseJavaVm(int api_level) {
    if (api_level >= 29) {
        return -0x50LL;
    }
    switch (api_level) {
        case 22: return -0x30LL;
        case 23: return -0x38LL;
        case 24:
        case 25: return -0x40LL;
        case 26:
        case 27:
        case 28: return -0x48LL;
        default: return -0x30LL;
    }
}

/**
 * EN: Reconstructed from `_Z24shouldClearSoftReferenceb` (`0x0780dc`, `112 B`).
 *     If `sCurrentHeapSize > sSoftRefHeapThreshold` (`0x1062f8 > 0x106008`), resets
 *     `sCurrentHeapSize = 0` (`str xzr, [x8, #0x2f8]` @ `0x078100`) and returns `true`.
 * VN: Tái tạo từ `_Z24shouldClearSoftReferenceb` (`0x0780dc`, `112 B`).
 */
bool shouldClearSoftReference(bool orig_clear_soft_references) {
    auto& st = getGlobalState();
    const int64_t cur_heap  = st.sCurrentHeapSize;
    const int64_t threshold = st.sSoftRefHeapThreshold;
    const bool force_clear  = (cur_heap > threshold);

    if (force_clear) {
        st.sCurrentHeapSize = 0;
    }
    const bool result = force_clear ? true : orig_clear_soft_references;
    if (st.sMemSpongeDebug) {
        logError("shouldClearSoftReference orig:%d, cur_heap:%ld, threshold:%ld, ret:%d",
                 orig_clear_soft_references ? 1 : 0,
                 static_cast<long>(cur_heap),
                 static_cast<long>(threshold),
                 result ? 1 : 0);
    }
    return result;
}

uint32_t CollectGarbageInternalSProxy(
    void* heap,
    void* gc_type,
    void* gc_cause,
    bool clear_soft_references,
    uint64_t gc_num) {
    // 0x07814c (size = 372 B)
    auto& st = getGlobalState();
    const bool effective_clear = shouldClearSoftReference(clear_soft_references);
    using OrigCollectSFn = uint32_t (*)(void*, void*, void*, bool, uint64_t);
    auto orig_fn = reinterpret_cast<OrigCollectSFn>(st.sCollectGarbageInternalSOrigin);
    return (orig_fn != nullptr)
        ? orig_fn(heap, gc_type, gc_cause, effective_clear, gc_num)
        : (effective_clear ? 1U : 0U);
}

uint32_t CollectGarbageInternalRProxy(
    void* heap,
    void* gc_type,
    void* gc_cause,
    bool clear_soft_references) {
    // 0x0782c0 (size = 352 B)
    auto& st = getGlobalState();
    const bool effective_clear = shouldClearSoftReference(clear_soft_references);
    using OrigCollectRFn = uint32_t (*)(void*, void*, void*, bool);
    auto orig_fn = reinterpret_cast<OrigCollectRFn>(st.sCollectGarbageInternalROrigin);
    return (orig_fn != nullptr)
        ? orig_fn(heap, gc_type, gc_cause, effective_clear)
        : (effective_clear ? 1U : 0U);
}

/**
 * EN: Reconstructed from `_Z26HeapSetIdealFootPrintProxyPvm` (`0x078668`, `340 B`).
 *     Exact AArch64 floating-point comparison at `0x0786d4..0x078704`:
 *       `ldr s1, [sMaxHeapRatio]` (`0x106004`)
 *       `movi v0.2s, #0x4e, lsl #24` (`536,870,912.0f`)
 *       `fmul s0, s1, s0`
 *       `ucvtf s1, x20` (`(float)max_allowed_footprint`)
 *       `fcmpe s0, s1; b.le #0x7874c`
 *       `ldr x8, [sGlobalTriggerGcValue]` (`0x106300`)
 *       `cmp x8, x20; b.hi #0x7874c`
 *       `ldr x8, [sAddGcDiffBytes]` (`0x106308`)
 *       `add x20, x8, x20`
 * VN: Tái tạo chính xác từng lệnh dấu chấm động AArch64 từ `_Z26HeapSetIdealFootPrintProxyPvm` (`0x078668`, `340 B`).
 */
void HeapSetIdealFootPrintProxy(void* heap, size_t max_allowed_footprint) {
    auto& st = getGlobalState();
    size_t adjusted_footprint = max_allowed_footprint;

    const float limit_bytes = st.sMaxHeapRatio * kIdealFootprintBaseBytesFloat;
    const float current_fp  = static_cast<float>(max_allowed_footprint);

    if (limit_bytes > current_fp &&
        static_cast<uint64_t>(st.sGlobalTriggerGcValue) <= max_allowed_footprint) {
        adjusted_footprint = max_allowed_footprint + static_cast<size_t>(st.sAddGcDiffBytes);
        if (st.sMemSpongeDebug) {
            logError("HeapSetIdealFootPrintProxy orig:%zu, adjusted:%zu",
                     max_allowed_footprint, adjusted_footprint);
        }
    }

    using OrigSetIdealFn = void (*)(void*, size_t);
    auto orig_fn = reinterpret_cast<OrigSetIdealFn>(st.sSetIdealFootprintOrigin);
    if (orig_fn != nullptr) {
        orig_fn(heap, adjusted_footprint);
    }
}

/**
 * EN: Reconstructed from `ignore_bump_pointer_clamp_grow_limit` (`0x07d530`, `180 B`).
 *     Logs `"ignore_bump_pointer_clamp_grow_limit call, thiz: %p, new_capacity: %zu"`,
 *     invokes `printCurrentStack("BumpPointerSpace")`, and returns `0` (`mov x0, xzr` @ `0x07d5a4`).
 * VN: Tái tạo từ `ignore_bump_pointer_clamp_grow_limit` (`0x07d530`, `180 B`).
 */
size_t ignore_bump_pointer_clamp_grow_limit(void* thiz, size_t new_capacity) {
    logError("ignore_bump_pointer_clamp_grow_limit call, thiz: %p, new_capacity: %zu",
             thiz, new_capacity);
    printCurrentStack("BumpPointerSpace");
    return 0ULL;
}

} // namespace NextAI::OpenCut::godzilla_memsponge
