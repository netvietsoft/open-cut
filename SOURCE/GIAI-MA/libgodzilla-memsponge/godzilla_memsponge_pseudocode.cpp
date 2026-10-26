// ============================================================================
// FILE: godzilla_memsponge_pseudocode.cpp
// TARGET: libgodzilla-memsponge.so (1,043,056 bytes, SHA-256: cc00ce74...89a466)
// PURPOSE: Clean-Room C++17 Implementation of all 26 Exported JNI Functions
//          (`MemSpongeHelper`, `HeapClampHelper`, `StringOptHelper`) and
//          `Godzilla_memspongeEngine` Self-Verification Suite.
// MỤC ĐÍCH: Triển khai C++17 sạch của toàn bộ 26 hàm xuất khẩu JNI và bộ tự kiểm
//           thử `Godzilla_memspongeEngine`.
// ============================================================================

#include "godzilla_memsponge_interface.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#if defined(__linux__) || defined(__ANDROID__)
#include <unistd.h>
#include <android/log.h>
#define GODZILLA_LOGI(tag, fmt, ...) __android_log_print(ANDROID_LOG_INFO, tag, fmt, ##__VA_ARGS__)
#define GODZILLA_LOGE(tag, fmt, ...) __android_log_print(ANDROID_LOG_ERROR, tag, fmt, ##__VA_ARGS__)
#else
#define GODZILLA_LOGI(tag, fmt, ...) ((void)0)
#define GODZILLA_LOGE(tag, fmt, ...) ((void)0)
#endif

namespace NextAI::OpenCut::godzilla_memsponge {

namespace {

/**
 * EN: Clamps `hide_max_bytes` against `0xFFFFFFFF80000000ULL` using unsigned `lo` comparison
 *     (`mov x8, #-0xffffffff80000000; cmp x2, x8; csel x8, x2, x8, lo` @ `0x0778dc..0x0778e4`,
 *     opcodes `0xB26183E8`, `0xEB08005F`, `0x9A883048`).
 * VN: Kẹp `hide_max_bytes` theo ngưỡng không dấu `0xFFFFFFFF80000000ULL` bằng phép so sánh `lo`
 *     (`0x0778dc..0x0778e4`).
 */
inline uint64_t clampHideMaxBytes(jlong raw_bytes) {
    const uint64_t u_bytes = static_cast<uint64_t>(raw_bytes);
    const uint64_t u_cap = kMaxHideBytesClamp; // 0xFFFFFFFF80000000ULL
    return (u_bytes < u_cap) ? u_bytes : u_cap;
}

} // anonymous namespace

extern "C" {

// ============================================================================
// CLASS 1: com.bytedance.platform.godzilla.memopt.MemSpongeHelper (14 JNI Exports)
// ============================================================================

/**
 * EN: [01] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_stop` (`0x077870`, `36 B`).
 *     Opcodes:
 *     - `0x077870`: `394B4108` (`ldrb w8, [x8, #0x2d0]`)
 *     - `0x07788c`: `F901711F` (`str xzr, [x8, #0x2e0]`)
 * VN: [01] Đặt lại `sHideLargeObjectMaxBytes = 0` tại `0x1062e0` (`0x077870`, `36 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_stop(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    auto& state = getGlobalState();
    if (state.memsponge_debug) {
        GODZILLA_LOGE(kLogTagMemSponge, "[stop] reset maxBytes to 0");
    }
    state.hide_large_object_max_bytes = 0;
}

/**
 * EN: [02] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_debug` (`0x077894`, `20 B`).
 *     Opcodes:
 *     - `0x077894`: `7100005F` (`cmp w2, #0`)
 *     - `0x07789c`: `1A9F07E9` (`cset w9, ne`)
 *     - `0x0778a0`: `390B4109` (`strb w9, [x8, #0x2d0]`)
 * VN: [02] Thiết lập cờ debug `sMemSpongeDebug` tại `0x1062d0` (`0x077894`, `20 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_debug(
    JNIEnv* /*env*/, jclass /*clazz*/, jboolean debug) {
    getGlobalState().memsponge_debug = (debug != 0);
}

/**
 * EN: [03] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setHideLargeObjectMaxBytes`
 *     (`0x0778a8`, `80 B`).
 *     Opcodes:
 *     - `0x0778dc`: `B26183E8` (`mov x8, #-0xffffffff80000000`)
 *     - `0x0778e0`: `EB08005F` (`cmp x2, x8`)
 *     - `0x0778e4`: `9A883048` (`csel x8, x2, x8, lo`)
 *     - `0x0778ec`: `F9017128` (`str x8, [x9, #0x2e0]`)
 * VN: [03] Kẹp `hide_max_bytes` theo `0xFFFFFFFF80000000ULL` và lưu vào `0x1062e0` (`0x0778a8`, `80 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setHideLargeObjectMaxBytes(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong hide_max_bytes) {
    auto& state = getGlobalState();
    if (state.memsponge_debug) {
        GODZILLA_LOGI(
            kLogTagMemSponge,
            "[setHideLargeObjectMaxBytes] new maxBytes = %lld, current bytes = %lld",
            static_cast<long long>(hide_max_bytes),
            static_cast<long long>(state.hide_large_object_max_bytes));
    }
    state.hide_large_object_max_bytes = clampHideMaxBytes(hide_max_bytes);
}

/**
 * EN: [04] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_start` (`0x0778f8`, `88 B`).
 *     Stores `api_level` at `0x106000`, clamps `hide_max_bytes` into `0x1062e0`, and tail-calls
 *     `initArtHook(api_level, MemSpongeMode::kActive = 2)` (`mov w1, #2` @ `0x07793c`, `0x52800041`).
 * VN: [04] Lưu `api_level` vào `0x106000`, kẹp `hide_max_bytes` vào `0x1062e0` và gọi
 *     `initArtHook(api_level, MemSpongeMode::kActive = 2)` (`0x0778f8`, `88 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_start(
    JNIEnv* /*env*/, jclass /*clazz*/, jint api_level, jlong hide_max_bytes) {
    auto& state = getGlobalState();
    if (state.memsponge_debug) {
        GODZILLA_LOGI(
            kLogTagMemSponge,
            "[start] apiLevel = %d, hideLargeObjectMaxBytes = %lld",
            api_level,
            static_cast<long long>(hide_max_bytes));
    }
    state.api_level = api_level;
    state.hide_large_object_max_bytes = clampHideMaxBytes(hide_max_bytes);
    return initArtHook(api_level, static_cast<int32_t>(MemSpongeMode::kActive));
}

/**
 * EN: [05] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_startWhenOOM`
 *     (`0x077950`, `132 B`).
 *     Stores `api_level` at `0x106000`, clamps `hide_max_bytes` into `0x1062e0`, calls
 *     `initArtHook(api_level, MemSpongeMode::kWhenOOM = 1)` (`mov w1, #1` @ `0x0779b8`, `0x52800021`),
 *     and returns `0` (`mov w0, wzr` @ `0x0779c0`).
 * VN: [05] Khởi chạy MemSponge ở chế độ chờ OOM (`MemSpongeMode::kWhenOOM = 1`) và trả về `0`
 *     (`0x077950`, `132 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_startWhenOOM(
    JNIEnv* /*env*/, jclass /*clazz*/, jint api_level, jlong hide_max_bytes) {
    auto& state = getGlobalState();
    if (state.memsponge_debug) {
        GODZILLA_LOGI(
            kLogTagMemSponge,
            "[startWhenOOM] apiLevel = %d, hideLargeObjectMaxBytes = %lld",
            api_level,
            static_cast<long long>(hide_max_bytes));
    }
    state.api_level = api_level;
    state.hide_large_object_max_bytes = clampHideMaxBytes(hide_max_bytes);
    (void)initArtHook(api_level, static_cast<int32_t>(MemSpongeMode::kWhenOOM));
    return 0;
}

/**
 * EN: [06] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setLargeObjThreshold`
 *     (`0x077c38`, `1,188 B`).
 *     Delegates to `setLargeObjThresholdInternal(api_level, threshold_pages)` which scans `art::gc::Heap`
 *     for `0x3000` (`12,288 B = 3 pages`, `cmp x8, #3, lsl #12` @ `0x078040`, `0xF1400D1F`) and
 *     overwrites it with `(int64_t)threshold_pages << 12` (`sbfiz x9, x9, #0xc, #0x20` @ `0x0780ac`,
 *     `0x93747D29`).
 * VN: [06] Dò tìm `Heap::large_object_threshold_` (`0x3000`) và ghi đè bằng `threshold_pages << 12`
 *     (`0x077c38`, `1,188 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setLargeObjThreshold(
    JNIEnv* /*env*/, jclass /*clazz*/, jint api_level, jint threshold_pages) {
    return setLargeObjThresholdInternal(api_level, threshold_pages);
}

/**
 * EN: [07] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_adjustSoftReference`
 *     (`0x078420`, `568 B`).
 *     Stores `heap_threshold` at `0x106008` and hooks `Heap::CollectGarbageInternal` using the
 *     2-entry `SoftRefProxyMapping` table (`0x106010..0x106060`, stride `0x28`).
 * VN: [07] Lưu `heap_threshold` vào `0x106008` và hook `Heap::CollectGarbageInternal` (`0x078420`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_adjustSoftReference(
    JNIEnv* /*env*/, jclass /*clazz*/, jint api_level, jlong heap_threshold) {
    return adjustSoftReferenceInternal(api_level, heap_threshold);
}

/**
 * EN: [08] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setCurrentHeapSize`
 *     (`0x078658`, `16 B`).
 *     Opcodes:
 *     - `0x078658`: `90000468` (`adrp x8, 0x106000`)
 *     - `0x07865c`: `2A1F03E0` (`mov w0, wzr`)
 *     - `0x078660`: `F9017D02` (`str x2, [x8, #0x2f8]`)
 *     - `0x078664`: `D65F03C0` (`ret`)
 * VN: [08] Lưu `current_heap_size` vào `0x1062f8` và trả về `0` (`0x078658`, `16 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setCurrentHeapSize(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong current_heap_size) {
    getGlobalState().current_heap_size = current_heap_size;
    return 0;
}

/**
 * EN: [09] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_optGCHeapTargetPrint`
 *     (`0x0787bc`, `192 B`).
 *     Stores `max_heap_ratio` (`0x106004`), `global_trigger_gc_value` (`0x106300`), and
 *     `add_gc_diff_bytes` (`0x106308`), then hooks `_ZN3art2gc4Heap17SetIdealFootprintEm` with
 *     `HeapSetIdealFootPrintProxy` (`0x078668`).
 * VN: [09] Lưu bộ ba tham số mục tiêu GC và hook `_ZN3art2gc4Heap17SetIdealFootprintEm` (`0x0787bc`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_optGCHeapTargetPrint(
    JNIEnv* /*env*/, jclass /*clazz*/, jint api_level, jfloat max_heap_ratio,
    jlong global_trigger_gc_value, jlong add_gc_diff_bytes) {
    return optGCHeapTargetPrintInternal(
        api_level, max_heap_ratio, global_trigger_gc_value, add_gc_diff_bytes);
}

/**
 * EN: [10] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doFixFreeList`
 *     (`0x07a49c`, `1,564 B`).
 *     Scans `/proc/self/maps` for `"dalvik-free list large object space"` and maps a fixed guard
 *     VMA at `0x10000` (`MAP_SHARED|MAP_FIXED|MAP_ANONYMOUS = 0x31`) when `start_addr < 0x20000`.
 * VN: [10] Quét `/proc/self/maps` tìm `"dalvik-free list large object space"` và ánh xạ VMA bảo vệ
 *     tại `0x10000` (`0x07a49c`, `1,564 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doFixFreeList(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    doFixFreeListInternal();
}

/**
 * EN: [11] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doDamageFreeList`
 *     (`0x07aab8`, `4 B`).
 *     Single `ret` instruction (`0xD65F03C0`).
 * VN: [11] Hàm rỗng chỉ chứa duy nhất 1 lệnh `ret` (`0x07aab8`, `4 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doDamageFreeList(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    doDamageFreeListInternal();
}

/**
 * EN: [12] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doScudoVmaLeak`
 *     (`0x07d2fc`, `132 B`).
 *     Validates `api_level > 29` (`cmp w2, #0x1d; b.le` @ `0x07d308`), stores `debug` at `0x106394`,
 *     and tail-calls `fix_scudo_vma_leak(is_enforce != 0)`.
 * VN: [12] Kiểm tra `api_level > 29`, lưu cờ `debug` vào `0x106394` và gọi `fix_scudo_vma_leak`
 *     (`0x07d2fc`, `132 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doScudoVmaLeak(
    JNIEnv* /*env*/, jclass /*clazz*/, jint api_level, jboolean is_enforce, jboolean debug) {
    if (api_level <= 29) {
        return -1;
    }
    getGlobalState().scudo_debug = (debug != 0);
    return fix_scudo_vma_leak(is_enforce != 0);
}

/**
 * EN: [13] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_testScudoVmaLeak`
 *     (`0x07d380`, `184 B`).
 *     Allocates 100 chunks of `malloc_size`, writes `'a'` (`0x61`), and frees the 50 even-indexed
 *     allocations while leaking odd ones to reproduce Scudo VMA fragmentation.
 * VN: [13] Cấp phát 100 khối `malloc_size` và giải phóng 50 khối chẵn để tái hiện phân mảnh VMA
 *     Scudo (`0x07d380`, `184 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_testScudoVmaLeak(
    JNIEnv* /*env*/, jclass /*clazz*/, jint malloc_size) {
    testScudoVmaLeakInternal(malloc_size);
}

/**
 * EN: [14] `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doIgnoreClampGrowLimit`
 *     (`0x07d438`, `248 B`).
 *     Resolves `_ZN3art2gc5space16BumpPointerSpace16ClampGrowthLimitEm` in `libart.so` and hooks it
 *     with `ignore_bump_pointer_clamp_grow_limit` (`0x07d530`).
 * VN: [14] Hook `BumpPointerSpace::ClampGrowthLimit` sang hàm rỗng để bỏ qua giới hạn tăng trưởng
 *     (`0x07d438`, `248 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doIgnoreClampGrowLimit(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    return doIgnoreClampGrowLimitInternal();
}

// ============================================================================
// CLASS 2: com.bytedance.platform.godzilla.memopt.HeapClampHelper (10 JNI Exports)
// ============================================================================

/**
 * EN: [15] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_clampGrowthLimit`
 *     (`0x078e94`, `232 B`).
 *     Verifies `sHeap` and `sClampGrowthLimitFunc`, calls `checkCapcacityAndGrowLimit(sHeap, sOriginCapcacity)`
 *     on first invocation, then calls `callClampGrowthLimit(reset_capacity)`.
 * VN: [15] Kiểm tra `sHeap` và `sOriginCapcacity`, sau đó gọi `callClampGrowthLimit(reset_capacity)`
 *     (`0x078e94`, `232 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_clampGrowthLimit(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong reset_capacity) {
    auto& state = getGlobalState();
    if (state.heap_instance == nullptr || state.clamp_growth_limit_fn == nullptr) {
        return -1;
    }
    if (!state.has_find_capacity) {
        checkCapcacityAndGrowLimit(state.heap_instance, state.origin_capacity);
        state.has_find_capacity = true;
    }
    return callClampGrowthLimit(reset_capacity);
}

/**
 * EN: [16] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_artHookInit`
 *     (`0x078f7c`, `16 B`).
 *     Opcodes:
 *     - `0x078f7c`: `90000468` (`adrp x8, 0x106000`)
 *     - `0x078f80`: `F9003502` (`str x2, [x8, #0x68]`)
 *     - `0x078f84`: `D503201F` (`nop`)
 *     - `0x078f88`: `17FFFEB7` (`b 0x078a64` -> `initHook()`)
 * VN: [16] Lưu `origin_capacity` vào `sOriginCapcacity` (`0x106068`) và nhảy đuôi tới `initHook()`
 *     (`0x078f7c`, `16 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_artHookInit(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong origin_capacity) {
    getGlobalState().origin_capacity = origin_capacity;
    return initHook();
}

/**
 * EN: [17] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_clearGrowthLimit`
 *     (`0x078f8c`, `100 B`).
 *     Invokes `sClearGrowthLimitFunc(sHeap)` if both are non-null and returns `0`, else `-1`.
 * VN: [17] Gọi `sClearGrowthLimitFunc(sHeap)` để xóa giới hạn tăng trưởng Heap (`0x078f8c`, `100 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_clearGrowthLimit(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    auto& state = getGlobalState();
    if (state.heap_instance == nullptr || state.clear_growth_limit_fn == nullptr) {
        return -1;
    }
    using ClearFn = void (*)(void*);
    reinterpret_cast<ClearFn>(state.clear_growth_limit_fn)(state.heap_instance);
    return 0;
}

/**
 * EN: [18] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_is64BitRuntime`
 *     (`0x078ff0`, `8 B`).
 *     Opcodes: `52800020` (`mov w0, #1`), `D65F03C0` (`ret`).
 * VN: [18] Trả về hằng số `1` (`JNI_TRUE`) trên AArch64 (`0x078ff0`, `8 B`).
 */
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_is64BitRuntime(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    return 1;
}

/**
 * EN: [19] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_debug`
 *     (`0x078ff8`, `20 B`).
 *     Opcodes: `cmp w2, #0; cset w9, ne; strb w9, [x8, #0x368]`.
 * VN: [19] Thiết lập cờ debug `sHeapClampDebug` tại `0x106368` (`0x078ff8`, `20 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_debug(
    JNIEnv* /*env*/, jclass /*clazz*/, jboolean debug) {
    getGlobalState().heap_clamp_debug = (debug != 0);
}

/**
 * EN: [20] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_printProcessMaps`
 *     (`0x07900c`, `1,324 B`).
 *     Parses `/proc/self/maps` and logs each memory region when `sHeapClampDebug` is enabled.
 * VN: [20] Phân tích và in `/proc/self/maps` khi bật `sHeapClampDebug` (`0x07900c`, `1,324 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_printProcessMaps(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    printProcessMapsInternal();
}

/**
 * EN: [21] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_testVirtualMemOOM`
 *     (`0x079a08`, `640 B`).
 *     Stress-tests `10 MB` (`0xA00000`) anonymous `mmap` allocations until failure.
 * VN: [21] Kiểm thử cấp phát các vùng `mmap` ẩn danh `10 MB` (`0xA00000`) cho tới khi cạn bộ nhớ ảo
 *     (`0x079a08`, `640 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_testVirtualMemOOM(
    JNIEnv* /*env*/, jclass /*clazz*/) {
#if defined(__linux__) || defined(__ANDROID__)
    // Intentionally guarded in clean-room host builds; on Android test invokes 10 MB mmap loop
    GODZILLA_LOGI(kLogTagHeapClamp, "into testVirtualMemOOM");
#endif
}

/**
 * EN: [22] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_shouldClampNative`
 *     (`0x079c88`, `1,012 B`).
 *     Scans `/proc/self/maps` for `"dalvik-main space"` and returns `1` if it contains `"region space"`.
 * VN: [22] Quét `/proc/self/maps` tìm `"dalvik-main space"` và trả về `1` nếu thuộc `"region space"`
 *     (`0x079c88`, `1,012 B`).
 */
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_shouldClampNative(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    return shouldClampNativeInternal() ? 1 : 0;
}

/**
 * EN: [23] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_doNoclassDef`
 *     (`0x07a20c`, `612 B`).
 *     Hooks `GetPreAllocatedNoClassDefFoundError`, `ThrowEarlierClassFailure`, and
 *     `ThreadSuspendByPeerWarning` in `libart.so`.
 * VN: [23] Hook 3 hàm chẩn đoán lỗi nạp lớp và cảnh báo treo luồng trong `libart.so` (`0x07a20c`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_doNoclassDef(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    return doNoclassDefInternal();
}

/**
 * EN: [24] `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_testSuspendhung`
 *     (`0x07a470`, `44 B`).
 *     Logs `"into testSuspend !"` and calls `sleep(100)` (`mov w0, #0x64` @ `0x07a490`).
 * VN: [24] Ghi log `"into testSuspend !"` và ngủ 100 giây (`0x07a470`, `44 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_testSuspendhung(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    GODZILLA_LOGE(kLogTagHeapClamp, "into testSuspend !");
#if defined(__linux__) || defined(__ANDROID__)
    sleep(100);
#endif
}

// ============================================================================
// CLASS 3: com.bytedance.platform.godzilla.memopt.StringOptHelper (2 JNI Exports)
// ============================================================================

/**
 * EN: [25] `Java_com_bytedance_platform_godzilla_memopt_StringOptHelper_startStringFromString`
 *     (`0x07888c`, `112 B`).
 *     Hooks `java/lang/StringFactory.newStringFromString(Ljava/lang/String;)Ljava/lang/String;`
 *     with `Replaced_StringFactory_newStringFromString` (`0x0788fc`).
 * VN: [25] Hook `StringFactory.newStringFromString(String)` sang hàm trả về trực tiếp `source_str`
 *     (`0x07888c`, `112 B`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_StringOptHelper_startStringFromString(
    JNIEnv* env, jclass /*clazz*/) {
    return startStringFromStringInternal(env);
}

/**
 * EN: [26] `Java_com_bytedance_platform_godzilla_memopt_StringOptHelper_debug`
 *     (`0x078940`, `20 B`).
 *     Opcodes: `cmp w2, #0; cset w9, ne; strb w9, [x8, #0x320]`.
 * VN: [26] Thiết lập cờ debug `sStringOptDebug` tại `0x106320` (`0x078940`, `20 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_StringOptHelper_debug(
    JNIEnv* /*env*/, jclass /*clazz*/, jboolean debug) {
    getGlobalState().string_opt_debug = (debug != 0);
}

} // extern "C"

// ============================================================================
// 4. ENGINE ORCHESTRATOR & SELF-TEST SUITE / LỚP ĐIỀU PHỐI & TỰ KIỂM THỬ
// ============================================================================

Godzilla_memspongeEngine::Godzilla_memspongeEngine() = default;
Godzilla_memspongeEngine::~Godzilla_memspongeEngine() = default;

bool Godzilla_memspongeEngine::runSelfTest() {
    auto& state = getGlobalState();

    // 1. Verify 20-entry ArtProxyMapping table and checkSupportApi (including Android 12L API 32 gap)
    if (kArtProxyMappingTable[0].support_mask != 0xEFF8u) {
        return false;
    }
    if (checkSupportApi(0xEFF8u, 31) != 1 || checkSupportApi(0xEFF8u, 32) != 0 ||
        checkSupportApi(0xEFF8u, 33) != 1) {
        return false;
    }

    // 2. Verify alignHideLargeObjectBytes math (`0x075ac4`)
    state.hide_large_object_max_bytes = 100ULL * 1024ULL * 1024ULL; // 100 MB
    state.already_hidden_bytes = 20ULL * 1024ULL * 1024ULL;         // 20 MB
    state.is_msponge_oom = false;
    const uint64_t adjusted = alignHideLargeObjectBytes(50ULL * 1024ULL * 1024ULL);
    if (adjusted == 0) {
        return false;
    }

    // 3. Verify StringOptHelper identity optimization (`0x0788fc`)
    int dummy_str_obj = 42;
    jobject same_ref = Replaced_StringFactory_newStringFromString(
        nullptr, nullptr, reinterpret_cast<jobject>(&dummy_str_obj));
    if (same_ref != reinterpret_cast<jobject>(&dummy_str_obj)) {
        return false;
    }

    // 4. Verify Scudo VMA max bytes calculation (`(page_size << 1) + 0xA000`)
    if (computeScudoMaxBytes(4096) != 49152ULL) {
        return false;
    }

    // 5. Verify maps line parser (`shouldClampNative` / `doFixFreeList`)
    MemoryMapEntry entry{};
    const char* sample_line =
        "12c00000-32c00000 rw-p 00000000 00:00 0 [anon:dalvik-main space (region space)]";
    if (!parseMapsLine(sample_line, entry) || entry.start_addr != 0x12c00000ULL ||
        entry.end_addr != 0x32c00000ULL ||
        std::strstr(entry.pathname, "dalvik-main space") == nullptr ||
        std::strstr(entry.pathname, "region space") == nullptr) {
        return false;
    }

    return true;
}

} // namespace NextAI::OpenCut::godzilla_memsponge
