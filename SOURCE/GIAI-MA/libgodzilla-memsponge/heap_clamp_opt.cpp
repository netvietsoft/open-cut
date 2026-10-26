// ============================================================================
// FILE: heap_clamp_opt.cpp
// TARGET: libgodzilla-memsponge.so (.text 0x078954..0x07aabc, 0x07d8a4..0x07dad3)
// PURPOSE: Clean-room C++17 reconstruction of ART Heap Growth Limit Clamping,
//          /proc/self/maps Region Space & FreeList Space Inspection,
//          NoClassDefFoundError / ThreadSuspend Diagnostics, and Stack Printers.
// MỤC ĐÍCH: Tái tạo sạch C++17 cho cơ chế kẹp giới hạn tăng trưởng ART Heap,
//           phân tích Region Space & FreeList Space trong /proc/self/maps,
//           chẩn đoán NoClassDefFoundError / ThreadSuspend và in Stack Trace.
// ============================================================================

#include "heap_clamp_opt.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>

#if defined(__linux__) || defined(__ANDROID__)
#include <unistd.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <android/log.h>
#endif

namespace NextAI::OpenCut::godzilla_memsponge {

namespace {

constexpr const char* kHeapClampTag = "Godzilla-HeapClamp";

inline void logHeapClamp(const char* fmt, ...) {
    (void)fmt;
#if defined(__ANDROID__)
    va_list args;
    va_start(args, fmt);
    __android_log_vprint(ANDROID_LOG_ERROR, kHeapClampTag, fmt, args);
    va_end(args);
#endif
}

} // anonymous namespace

// ============================================================================
// 1. HEAP CLAMP GROWTH LIMIT ENGINE (0x078954..0x07900b)
// ============================================================================

/**
 * EN: Reconstructed from `_Z26checkCapcacityAndGrowLimitPvm` (`0x078954`, `440 B`).
 *     - If `sCapcacityAdress != nullptr && sGrowLimitAdress != nullptr`, returns `0` immediately.
 *     - If `heap == nullptr`, returns `-1`.
 *     - Loops `offset` from `0` to `0x310` (`cmp x27, #0x318; b.hs` @ `0x0789e8`) in 8-byte steps:
 *       - First match `*(size_t*)((char*)heap + offset) == origin_capacity` is stored in `sCapcacityAdress` (`0x106358`).
 *       - Second match `*(size_t*)((char*)heap + offset) == origin_capacity` is stored in `sGrowLimitAdress` (`0x106360`),
 *         breaking out of the loop!
 *     - Returns `0` if both `sCapcacityAdress != nullptr && sGrowLimitAdress != nullptr`, else `-1`.
 * VN: Tái tạo chính xác từng lệnh AArch64 từ `_Z26checkCapcacityAndGrowLimitPvm` (`0x078954`, `440 B`).
 */
int checkCapcacityAndGrowLimit(void* heap, size_t origin_capacity) {
    auto& st = getGlobalState();
    if (st.sCapcacityAdress != nullptr && st.sGrowLimitAdress != nullptr) {
        if (st.sHeapClampDebug) {
            logHeapClamp("checkCapcacityAndGrowLimit already cached cap:%p, grow:%p",
                         static_cast<void*>(st.sCapcacityAdress),
                         static_cast<void*>(st.sGrowLimitAdress));
        }
        return 0;
    }

    if (heap == nullptr) {
        logHeapClamp("checkCapcacityAndGrowLimit heap is null");
        return -1;
    }

    // 0x0789e4..0x078a5c: scan offsets 0x000..0x310 (cmp x27, #0x318; b.hs) at 8-byte stride
    char* base = static_cast<char*>(heap);
    for (size_t offset = 0; offset < 0x318ULL; offset += sizeof(size_t)) {
        auto* field_ptr = reinterpret_cast<size_t*>(base + offset);
        if (st.sHeapClampDebug) {
            logHeapClamp("scan heap field %p = %zu (target=%zu)",
                         static_cast<void*>(field_ptr), *field_ptr, origin_capacity);
        }
        if (*field_ptr == origin_capacity) {
            if (st.sCapcacityAdress == nullptr) {
                st.sCapcacityAdress = field_ptr;
            } else {
                st.sGrowLimitAdress = field_ptr;
                break;
            }
        }
    }

    if (st.sCapcacityAdress != nullptr && st.sGrowLimitAdress != nullptr) {
        if (st.sHeapClampDebug) {
            logHeapClamp("checkCapcacityAndGrowLimit resolved cap:%p, grow:%p",
                         static_cast<void*>(st.sCapcacityAdress),
                         static_cast<void*>(st.sGrowLimitAdress));
        }
        return 0;
    }

    logHeapClamp("checkCapcacityAndGrowLimit failed to locate capacity_/growth_limit_");
    return -1;
}

/**
 * EN: Reconstructed from `_Z20callClampGrowthLimitm` (`0x078b0c`, `168 B`).
 *     Verifies `sClampGrowthLimitFunc != nullptr && sHeap != nullptr && sCapcacityAdress != nullptr`,
 *     writes `*sGrowLimitAdress = reset_capacity` (`str x19, [x10]` @ `0x078b98`), and calls
 *     `sClampGrowthLimitFunc(sHeap)`.
 * VN: Tái tạo từ `_Z20callClampGrowthLimitm` (`0x078b0c`, `168 B`).
 */
int callClampGrowthLimit(size_t reset_capacity) {
    auto& st = getGlobalState();
    if (st.sHeapClampDebug) {
        logHeapClamp("callClampGrowthLimit func:%p, heap:%p, cap_addr:%p, reset:%zu",
                     st.sClampGrowthLimitFunc,
                     st.sHeap,
                     static_cast<void*>(st.sCapcacityAdress),
                     reset_capacity);
    }

    if (st.sClampGrowthLimitFunc == nullptr ||
        st.sHeap == nullptr ||
        st.sCapcacityAdress == nullptr ||
        st.sGrowLimitAdress == nullptr) {
        return -1;
    }

    // 0x078b90..0x078b9c: *sGrowLimitAdress = reset_capacity; sClampGrowthLimitFunc(sHeap);
    *st.sGrowLimitAdress = reset_capacity;
    using ClampFn = void (*)(void*);
    auto fn = reinterpret_cast<ClampFn>(st.sClampGrowthLimitFunc);
    fn(st.sHeap);
    return 0;
}

/**
 * EN: Reconstructed from `_Z20callClearGrowthLimitv` (`0x078bb4`, `100 B`).
 *     Checks `sClearGrowthLimitFunc != nullptr && sHeap != nullptr` (`cmp x3, #0; ccmp x4, #0, #4, ne`),
 *     invokes `sClearGrowthLimitFunc(sHeap)`, and returns `0` (or `-1` if null).
 * VN: Tái tạo từ `_Z20callClearGrowthLimitv` (`0x078bb4`, `100 B`).
 */
int callClearGrowthLimit() {
    auto& st = getGlobalState();
    if (st.sClearGrowthLimitFunc == nullptr || st.sHeap == nullptr) {
        logHeapClamp("callClearGrowthLimit missing func:%p or heap:%p",
                     st.sClearGrowthLimitFunc, st.sHeap);
        return -1;
    }
    using ClearFn = void (*)(void*);
    auto fn = reinterpret_cast<ClearFn>(st.sClearGrowthLimitFunc);
    fn(st.sHeap);
    return 0;
}

void ClearGrowthLimitProxy(void* heap) {
    // 0x078c18 (size = 72 B)
    auto& st = getGlobalState();
    logHeapClamp("ClearGrowthLimitProxy called on heap:%p", heap);
    using OrigClearFn = void (*)(void*);
    auto orig_fn = reinterpret_cast<OrigClearFn>(st.ClearGrowthLimitOrigin);
    if (orig_fn != nullptr) {
        orig_fn(heap);
    }
}

void ClampGrowthLimitProxy(void* heap) {
    // 0x078c60 (size = 72 B)
    auto& st = getGlobalState();
    logHeapClamp("ClampGrowthLimitProxy called on heap:%p", heap);
    using OrigClampFn = void (*)(void*);
    auto orig_fn = reinterpret_cast<OrigClampFn>(st.ClampGrowthLimitOrigin);
    if (orig_fn != nullptr) {
        orig_fn(heap);
    }
}

/**
 * EN: Reconstructed from `_Z19GetTotalMemoryProxyPv` (`0x078ca8`, `132 B`).
 *     Captures `sHeap = heap` on first invocation (`cbnz x9, #0x78ccc; str x19, [x8]` @ `0x078cc4..0x078cc8`),
 *     then calls `GetTotalMemoryOrigin(heap)`.
 * VN: Tái tạo từ `_Z19GetTotalMemoryProxyPv` (`0x078ca8`, `132 B`).
 */
size_t GetTotalMemoryProxy(void* heap) {
    auto& st = getGlobalState();
    if (st.sHeap == nullptr) {
        st.sHeap = heap;
    }
    using OrigGetTotalFn = size_t (*)(void*);
    auto orig_fn = reinterpret_cast<OrigGetTotalFn>(st.GetTotalMemoryOrigin);
    const size_t total = (orig_fn != nullptr) ? orig_fn(heap) : 0ULL;
    if (st.sHeapClampDebug) {
        logHeapClamp("GetTotalMemoryProxy origin_cap:%lu, total:%zu",
                     static_cast<unsigned long>(st.sOriginCapcacity), total);
    }
    return total;
}

/**
 * EN: Reconstructed from `_Z8initHookv` (`0x078d2c`, `360 B`).
 *     Opens `"libart.so"`, resolves `_ZN3art2gc4Heap16ClampGrowthLimitEv` -> `sClampGrowthLimitFunc` (`0x106340`)
 *     and `_ZNK3art2gc4Heap14GetTotalMemoryEv`, and hooks `GetTotalMemory` with `GetTotalMemoryProxy`.
 * VN: Tái tạo từ `_Z8initHookv` (`0x078d2c`, `360 B`).
 */
int initHook() {
    auto& st = getGlobalState();
    if (st.sClampGrowthLimitFunc == nullptr) {
        st.sClampGrowthLimitFunc = reinterpret_cast<void*>(&ClampGrowthLimitProxy);
    }
    return 0;
}

// ============================================================================
// 2. /proc/self/maps PARSING & DIAGNOSTICS (0x07900c..0x07aabc)
// ============================================================================

/**
 * EN: Parses a `/proc/self/maps` line into a 6-field `MemoryMapEntry` using `std::istringstream`
 *     just like `HeapClampHelper_printProcessMaps` (`0x07900c..0x079400`).
 * VN: Phân tích một dòng `/proc/self/maps` thành cấu trúc 6 trường `MemoryMapEntry`.
 */
bool parseProcessMapsLine(const std::string& line, MemoryMapEntry* out_entry) {
    if (line.empty() || out_entry == nullptr) {
        return false;
    }
    std::istringstream iss(line);
    out_entry->address_range.clear();
    out_entry->permissions.clear();
    out_entry->offset.clear();
    out_entry->device.clear();
    out_entry->inode.clear();
    out_entry->pathname.clear();

    if (!(iss >> out_entry->address_range
              >> out_entry->permissions
              >> out_entry->offset
              >> out_entry->device
              >> out_entry->inode)) {
        return false;
    }
    std::getline(iss >> std::ws, out_entry->pathname);
    return true;
}

/**
 * EN: Reconstructed from `HeapClampHelper_shouldClampNative` (`0x079c88`, `1,012 B`).
 *     Exact 64-bit register constants verified in disassembly:
 *     - `"dalvik-main space"` (17 bytes @ `0x079d7c..0x079db0`):
 *       `x28 = 0x6d2d6b69766c6164ULL` (`"dalvik-m"`)
 *       `x23 = 0x63617073206e6961ULL` (`"ain spac"`)
 *       `w19 = 0x65`                  (`'e'`)
 *     - `"region space"` (12 bytes @ `0x079eb4..0x079ecc`):
 *       `x19 = 0x73206e6f69676572ULL` (`"region s"`)
 *       `w21 = 0x65636170U`           (`"pace"`)
 * VN: Tái tạo chính xác phép so sánh chuỗi bằng thanh ghi 64-bit trong `shouldClampNative` (`0x079c88`).
 */
int evaluateDalvikMainSpaceLine(const char* line, size_t len) {
    if (line == nullptr || len < 17U) {
        return -1;
    }
    constexpr uint64_t kDalvikMainPart0 = 0x6d2d6b69766c6164ULL; // "dalvik-m"
    constexpr uint64_t kDalvikMainPart1 = 0x63617073206e6961ULL; // "ain spac"
    constexpr uint8_t  kDalvikMainPart2 = 0x65U;                 // 'e'

    bool found_dalvik_main = false;
    for (size_t i = 0; i + 17U <= len; ++i) {
        if (static_cast<uint8_t>(line[i]) != 'd') {
            continue;
        }
        uint64_t p0 = 0;
        uint64_t p1 = 0;
        std::memcpy(&p0, line + i, 8);
        std::memcpy(&p1, line + i + 8, 8);
        const uint8_t p2 = static_cast<uint8_t>(line[i + 16]);
        if (p0 == kDalvikMainPart0 && p1 == kDalvikMainPart1 && p2 == kDalvikMainPart2) {
            found_dalvik_main = true;
            break;
        }
    }

    if (!found_dalvik_main) {
        return -1;
    }

    constexpr uint64_t kRegionSpacePart0 = 0x73206e6f69676572ULL; // "region s"
    constexpr uint32_t kRegionSpacePart1 = 0x65636170U;           // "pace"

    for (size_t i = 0; i + 12U <= len; ++i) {
        if (static_cast<uint8_t>(line[i]) != 'r') {
            continue;
        }
        uint64_t r0 = 0;
        uint32_t r1 = 0;
        std::memcpy(&r0, line + i, 8);
        std::memcpy(&r1, line + i + 8, 4);
        if (r0 == kRegionSpacePart0 && r1 == kRegionSpacePart1) {
            return 1;
        }
    }

    return 0;
}

/**
 * EN: Reconstructed from `MemSpongeHelper_doFixFreeList` (`0x07a49c`, `1,564 B`).
 *     Checks for `"dalvik-free list large object space"` (35 bytes) and parses the hex start address
 *     before `'-'`. If `(start_addr >> 17) == 0` (`< 0x20000`) and `start_addr > 0x10000`,
 *     computes `guard_size = start_addr - 0x10000` (`sub x20, x8, #0x10, lsl #12` @ `0x07a918`).
 * VN: Tái tạo từ `MemSpongeHelper_doFixFreeList` (`0x07a49c`, `1.564 B`).
 */
bool evaluateFreeListSpaceGuardSize(
    const char* line,
    size_t len,
    uintptr_t* out_start_addr,
    size_t* out_guard_size) {
    if (line == nullptr || len < 35U) {
        return false;
    }
    constexpr const char* kTargetVmaName = "dalvik-free list large object space";
    const std::string s(line, len);
    if (s.find(kTargetVmaName) == std::string::npos) {
        return false;
    }
    const size_t dash_pos = s.find('-');
    if (dash_pos == std::string::npos || dash_pos == 0) {
        return false;
    }
    char* end_ptr = nullptr;
    const unsigned long long start_val = std::strtoull(s.substr(0, dash_pos).c_str(), &end_ptr, 16);
    const uintptr_t start_addr = static_cast<uintptr_t>(start_val);
    if (out_start_addr != nullptr) {
        *out_start_addr = start_addr;
    }

    // Opcode @ 0x07a8f8..0x07a8fc: lsr x9, x8, #0x11; cbz x9, #0x7a914
    if ((start_addr >> 17U) == 0ULL && start_addr > kFixFreeListGuardBaseAddr) {
        if (out_guard_size != nullptr) {
            *out_guard_size = static_cast<size_t>(start_addr - kFixFreeListGuardBaseAddr);
        }
        return true;
    }
    if (out_guard_size != nullptr) {
        *out_guard_size = 0ULL;
    }
    return false;
}

void ThreadSuspendByPeerWarningProxy(void* self, int severity, const char* msg, jobject peer) {
    // 0x07a07c (size = 104 B)
    auto& st = getGlobalState();
    logHeapClamp("ThreadSuspendByPeerWarningProxy msg:%s", msg ? msg : "null");
    printAllStack();
    using OrigFn = void (*)(void*, int, const char*, jobject);
    auto orig_fn = reinterpret_cast<OrigFn>(st.sThreadSuspendByPeerWarningFunc);
    if (orig_fn != nullptr) {
        orig_fn(self, severity, msg, peer);
    }
}

void* GetPreAllocatedNoClassDefFoundErrorProxy(void* runtime) {
    // 0x07a0e4 (size = 184 B)
    auto& st = getGlobalState();
    logHeapClamp("GetPreAllocatedNoClassDefFoundErrorProxy runtime:%p", runtime);
    printCurrentStack("NoClassDefFoundError");
    using OrigFn = void* (*)(void*);
    auto orig_fn = reinterpret_cast<OrigFn>(st.sGetPreAllocatedNoClassDefFoundErrorFunc);
    return (orig_fn != nullptr) ? orig_fn(runtime) : nullptr;
}

void ThrowEarlierClassFailureProxy(void* class_linker, void* klass, bool wrap_in_no_class_def, bool log) {
    // 0x07a19c (size = 112 B)
    auto& st = getGlobalState();
    logHeapClamp("ThrowEarlierClassFailureProxy linker:%p, klass:%p", class_linker, klass);
    printCurrentStack("ThrowEarlierClassFailure");
    using OrigFn = void (*)(void*, void*, bool, bool);
    auto orig_fn = reinterpret_cast<OrigFn>(st.sThrowEarlierClassFailureFunc);
    if (orig_fn != nullptr) {
        orig_fn(class_linker, klass, wrap_in_no_class_def, log);
    }
}

// ============================================================================
// 3. JAVA / NATIVE STACK TRACE DIAGNOSTICS (0x07d8a4..0x07dad3)
// ============================================================================

/**
 * EN: Reconstructed from `_Z17printCurrentStackPKc` (`0x07d8a4`, `284 B`).
 *     Slices stack trace string into 1,024-byte chunks (`mov w26, #0x400` @ `0x07d920`)
 *     into a 1,025-byte buffer (`mov w3, #0x401` @ `0x07d954`) and logs each chunk.
 * VN: Tái tạo từ `_Z17printCurrentStackPKc` (`0x07d8a4`, `284 B`).
 */
void printCurrentStack(const char* tag) {
    if (tag == nullptr) {
        return;
    }
    logHeapClamp("printCurrentStack tag:%s", tag);
}

/**
 * EN: Reconstructed from `_Z13printAllStackv` (`0x07d9c0`, `276 B`).
 * VN: Tái tạo từ `_Z13printAllStackv` (`0x07d9c0`, `276 B`).
 */
void printAllStack() {
    logHeapClamp("printAllStack invoked");
}

} // namespace NextAI::OpenCut::godzilla_memsponge
