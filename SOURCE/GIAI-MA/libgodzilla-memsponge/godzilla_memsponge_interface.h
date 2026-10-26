// ============================================================================
// FILE: godzilla_memsponge_interface.h
// TARGET: libgodzilla-memsponge.so (1,043,056 bytes, SHA-256: cc00ce74...89a466)
// PURPOSE: Public JNI Interface (26 Exported Functions Across 3 Java Classes)
//          and Godzilla_memspongeEngine Orchestrator Class.
// MỤC ĐÍCH: Giao diện JNI công khai (26 hàm xuất khẩu trên 3 lớp Java) và lớp
//           điều phối Godzilla_memspongeEngine.
// ============================================================================

#pragma once

#include "godzilla_memsponge_types.h"
#include "memsponge_art_hook.h"
#include "heap_clamp_opt.h"
#include "scudo_vma_string_opt.h"

namespace NextAI::OpenCut::godzilla_memsponge {

extern "C" {

// ============================================================================
// CLASS 1: com.bytedance.platform.godzilla.memopt.MemSpongeHelper (14 JNI Exports)
// ============================================================================

/**
 * EN: [01] Resets `sHideLargeObjectMaxBytes = 0` (`str xzr, [x8, #0x2e0]` @ `0x07788c`, `0xF901711F`).
 *     Binary address: `0x077870` (`size = 36 B`).
 * VN: [01] Đặt lại `sHideLargeObjectMaxBytes = 0` (`0x077870`, `36 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_stop(
    JNIEnv* env, jclass clazz);

/**
 * EN: [02] Sets `sMemSpongeDebug = (debug != 0)` (`strb w9, [x8, #0x2d0]` @ `0x0778a0`, `0x390B4109`).
 *     Binary address: `0x077894` (`size = 20 B`).
 * VN: [02] Thiết lập cờ debug `sMemSpongeDebug` tại `0x1062d0` (`0x077894`, `20 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_debug(
    JNIEnv* env, jclass clazz, jboolean debug);

/**
 * EN: [03] Clamps `hide_max_bytes` against `0xFFFFFFFF80000000ULL` (`mov x8, #-0xffffffff80000000`
 *     @ `0x0778dc`, `0xB26183E8`) via unsigned `lo` comparison and stores at `0x1062e0`.
 *     Binary address: `0x0778a8` (`size = 80 B`).
 * VN: [03] Kẹp `hide_max_bytes` theo ngưỡng không dấu `0xFFFFFFFF80000000ULL` và lưu vào `0x1062e0`.
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setHideLargeObjectMaxBytes(
    JNIEnv* env, jclass clazz, jlong hide_max_bytes);

/**
 * EN: [04] Stores `api_level` at `0x106000`, clamps `hide_max_bytes` into `0x1062e0`, and calls
 *     `initArtHook(api_level, MemSpongeMode::kActive = 2)` (`mov w1, #2` @ `0x07793c`, `0x52800041`).
 *     Binary address: `0x0778f8` (`size = 88 B`).
 * VN: [04] Khởi chạy MemSponge ở chế độ chủ động (`MemSpongeMode::kActive = 2`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_start(
    JNIEnv* env, jclass clazz, jint api_level, jlong hide_max_bytes);

/**
 * EN: [05] Stores `api_level` at `0x106000`, clamps `hide_max_bytes` into `0x1062e0`, and calls
 *     `initArtHook(api_level, MemSpongeMode::kWhenOOM = 1)` (`mov w1, #1` @ `0x0779b8`, `0x52800021`).
 *     Binary address: `0x077950` (`size = 132 B`).
 * VN: [05] Khởi chạy MemSponge ở chế độ chờ OOM (`MemSpongeMode::kWhenOOM = 1`).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_startWhenOOM(
    JNIEnv* env, jclass clazz, jint api_level, jlong hide_max_bytes);

/**
 * EN: [06] Locates `art::gc::Heap::large_object_threshold_` (default `3 * 4096 = 12288 = 0x3000`,
 *     `cmp x8, #3, lsl #12` @ `0x078040`) and overwrites it with `(int64_t)threshold_pages << 12`
 *     (`sbfiz x9, x9, #0xc, #0x20` @ `0x0780ac`, `0x93747D29`).
 *     Binary address: `0x077c38` (`size = 1,188 B`).
 * VN: [06] Dò tìm `Heap::large_object_threshold_` (`0x3000`) và ghi đè bằng `threshold_pages << 12`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setLargeObjThreshold(
    JNIEnv* env, jclass clazz, jint api_level, jint threshold_pages);

/**
 * EN: [07] Stores `heap_threshold` at `0x106008` and hooks `Heap::CollectGarbageInternal` using the
 *     2-entry `SoftRefProxyMapping` table (`0x106010..0x106060`, stride `0x28`).
 *     Binary address: `0x078420` (`size = 568 B`).
 * VN: [07] Thiết lập ngưỡng thu gom `SoftReference` và hook `Heap::CollectGarbageInternal`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_adjustSoftReference(
    JNIEnv* env, jclass clazz, jint api_level, jlong heap_threshold);

/**
 * EN: [08] Stores `current_heap_size` at `0x1062f8` (`str x2, [x8, #0x2f8]` @ `0x078660`) and returns `0`.
 *     Binary address: `0x078658` (`size = 16 B`).
 * VN: [08] Cập nhật `sCurrentHeapSize` tại `0x1062f8` và trả về `0`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setCurrentHeapSize(
    JNIEnv* env, jclass clazz, jlong current_heap_size);

/**
 * EN: [09] Stores `max_heap_ratio` (`s0` -> `0x106004`), `global_trigger_gc_value` (`x3` -> `0x106300`),
 *     and `add_gc_diff_bytes` (`x4` -> `0x106308`), then hooks `_ZN3art2gc4Heap17SetIdealFootprintEm`.
 *     Binary address: `0x0787bc` (`size = 192 B`).
 * VN: [09] Tối ưu hóa dấu chân bộ nhớ mục tiêu của GC qua `Heap::SetIdealFootprint`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_optGCHeapTargetPrint(
    JNIEnv* env, jclass clazz, jint api_level, jfloat max_heap_ratio,
    jlong global_trigger_gc_value, jlong add_gc_diff_bytes);

/**
 * EN: [10] Scans `/proc/self/maps` for `"dalvik-free list large object space"` and maps a fixed guard
 *     VMA at `0x10000` (`MAP_SHARED|MAP_FIXED|MAP_ANONYMOUS = 0x31`) when `start_addr < 0x20000`.
 *     Binary address: `0x07a49c` (`size = 1,564 B`).
 * VN: [10] Quét `/proc/self/maps` tìm `"dalvik-free list large object space"` và ánh xạ VMA bảo vệ tại `0x10000`.
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doFixFreeList(
    JNIEnv* env, jclass clazz);

/**
 * EN: [11] No-op (`ret` @ `0x07aab8`, `size = 4 B`, opcode `0xD65F03C0`).
 * VN: [11] Hàm rỗng (`ret` tại `0x07aab8`, `4 B`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doDamageFreeList(
    JNIEnv* env, jclass clazz);

/**
 * EN: [12] Validates `api_level > 29` (`cmp w2, #0x1d; b.le` @ `0x07d308`), stores `debug` at `0x106394`,
 *     and tail-calls `fix_scudo_vma_leak(is_enforce)`.
 *     Binary address: `0x07d2fc` (`size = 132 B`).
 * VN: [12] Kiểm tra `api_level > 29`, lưu cờ `debug` và gọi `fix_scudo_vma_leak(is_enforce)`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doScudoVmaLeak(
    JNIEnv* env, jclass clazz, jint api_level, jboolean is_enforce, jboolean debug);

/**
 * EN: [13] Allocates 100 chunks of `malloc_size`, writes `'a'` (`0x61`), saves even indices,
 *     and frees the 50 even-indexed allocations while leaking odd ones to reproduce Scudo VMA fragmentation.
 *     Binary address: `0x07d380` (`size = 184 B`).
 * VN: [13] Cấp phát 100 khối bộ nhớ và giải phóng 50 khối chẵn để kiểm thử phân mảnh VMA của Scudo.
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_testScudoVmaLeak(
    JNIEnv* env, jclass clazz, jint malloc_size);

/**
 * EN: [14] Resolves `_ZN3art2gc5space16BumpPointerSpace16ClampGrowthLimitEm` in `libart.so` and hooks
 *     it with `ignore_bump_pointer_clamp_grow_limit` (`0x07d530`).
 *     Binary address: `0x07d438` (`size = 248 B`).
 * VN: [14] Bỏ qua việc kẹp giới hạn tăng trưởng trên `BumpPointerSpace::ClampGrowthLimit`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doIgnoreClampGrowLimit(
    JNIEnv* env, jclass clazz);

// ============================================================================
// CLASS 2: com.bytedance.platform.godzilla.memopt.HeapClampHelper (10 JNI Exports)
// ============================================================================

/**
 * EN: [15] Calls `checkCapcacityAndGrowLimit(sHeap, sOriginCapcacity)` and `callClampGrowthLimit(reset_capacity)`.
 *     Binary address: `0x078e94` (`size = 232 B`).
 * VN: [15] Thực thi kẹp giới hạn tăng trưởng Heap theo `reset_capacity`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_clampGrowthLimit(
    JNIEnv* env, jclass clazz, jlong reset_capacity);

/**
 * EN: [16] Stores `origin_capacity` into `sOriginCapcacity` (`0x106068`) and tail-calls `initHook()`.
 *     Binary address: `0x078f7c` (`size = 16 B`).
 * VN: [16] Lưu `origin_capacity` vào `sOriginCapcacity` (`0x106068`) và gọi `initHook()`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_artHookInit(
    JNIEnv* env, jclass clazz, jlong origin_capacity);

/**
 * EN: [17] Invokes `sClearGrowthLimitFunc(sHeap)` if non-null, else returns `-1`.
 *     Binary address: `0x078f8c` (`size = 100 B`).
 * VN: [17] Xóa giới hạn tăng trưởng Heap thông qua `sClearGrowthLimitFunc(sHeap)`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_clearGrowthLimit(
    JNIEnv* env, jclass clazz);

/**
 * EN: [18] Returns `JNI_TRUE` (`mov w0, #1; ret` @ `0x078ff0`, `size = 8 B`).
 * VN: [18] Trả về `1` (`JNI_TRUE`) trên kiến trúc AArch64 64-bit (`0x078ff0`, `8 B`).
 */
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_is64BitRuntime(
    JNIEnv* env, jclass clazz);

/**
 * EN: [19] Stores `sHeapClampDebug = (debug != 0)` at `0x106368` (`0x078ff8`, `size = 20 B`).
 * VN: [19] Thiết lập cờ debug `sHeapClampDebug` tại `0x106368`.
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_debug(
    JNIEnv* env, jclass clazz, jboolean debug);

/**
 * EN: [20] Parses `/proc/self/maps` line by line into `MemoryMapEntry` and logs each mapping.
 *     Binary address: `0x07900c` (`size = 1,324 B`).
 * VN: [20] Đọc và in toàn bộ bảng ánh xạ bộ nhớ `/proc/self/maps`.
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_printProcessMaps(
    JNIEnv* env, jclass clazz);

/**
 * EN: [21] Stress test allocating `10 MB` (`0xA00000`) chunks to reproduce virtual memory OOM.
 *     Binary address: `0x079a08` (`size = 640 B`).
 * VN: [21] Kiểm thử cấp phát các khối `10 MB` (`0xA00000`) để mô phỏng tràn bộ nhớ ảo.
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_testVirtualMemOOM(
    JNIEnv* env, jclass clazz);

/**
 * EN: [22] Scans `/proc/self/maps` for `"dalvik-main space"` and returns `JNI_TRUE` (`1`) if it
 *     uses `"region space"`, else `JNI_FALSE` (`0`).
 *     Binary address: `0x079c88` (`size = 1,012 B`).
 * VN: [22] Kiểm tra `"dalvik-main space"` trong `/proc/self/maps` có phải `"region space"` hay không.
 */
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_shouldClampNative(
    JNIEnv* env, jclass clazz);

/**
 * EN: [23] Hooks `GetPreAllocatedNoClassDefFoundError`, `ThrowEarlierClassFailure`, and
 *     `ThreadSuspendByPeerWarning` in `libart.so`.
 *     Binary address: `0x07a20c` (`size = 612 B`).
 * VN: [23] Hook 3 hàm chẩn đoán lỗi lớp và treo luồng trong `libart.so`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_doNoclassDef(
    JNIEnv* env, jclass clazz);

/**
 * EN: [24] Logs `"into testSuspend !"` and calls `sleep(100)` (`mov w0, #0x64` @ `0x07a490`).
 *     Binary address: `0x07a470` (`size = 44 B`).
 * VN: [24] Ghi log `"into testSuspend !"` và ngủ 100 giây để kiểm thử treo luồng.
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_testSuspendhung(
    JNIEnv* env, jclass clazz);

// ============================================================================
// CLASS 3: com.bytedance.platform.godzilla.memopt.StringOptHelper (2 JNI Exports)
// ============================================================================

/**
 * EN: [25] Hooks `java/lang/StringFactory.newStringFromString(Ljava/lang/String;)Ljava/lang/String;`
 *     with `Replaced_StringFactory_newStringFromString` (`0x0788fc`).
 *     Binary address: `0x07888c` (`size = 112 B`).
 * VN: [25] Hook `StringFactory.newStringFromString(String)` sang hàm trả về trực tiếp không sao chép.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_memopt_StringOptHelper_startStringFromString(
    JNIEnv* env, jclass clazz);

/**
 * EN: [26] Sets `sStringOptDebug = (debug != 0)` at `0x106320` (`strb w9, [x8, #0x320]` @ `0x07894c`).
 *     Binary address: `0x078940` (`size = 20 B`).
 * VN: [26] Thiết lập cờ debug `sStringOptDebug` tại `0x106320`.
 */
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_memopt_StringOptHelper_debug(
    JNIEnv* env, jclass clazz, jboolean debug);

} // extern "C"

// ============================================================================
// 4. ENGINE ORCHESTRATOR & SELF-TEST SUITE / LỚP ĐIỀU PHỐI & TỰ KIỂM THỬ
// ============================================================================

class Godzilla_memspongeEngine {
public:
    Godzilla_memspongeEngine();
    virtual ~Godzilla_memspongeEngine();

    /**
     * EN: Runs the deterministic mathematical and ABI self-test suite verifying all
     *     subsystems of `libgodzilla-memsponge.so`.
     * VN: Chạy bộ tự kiểm thử toán học và ABI xác minh toàn bộ các phân hệ của `libgodzilla-memsponge.so`.
     */
    bool runSelfTest();
};

} // namespace NextAI::OpenCut::godzilla_memsponge
