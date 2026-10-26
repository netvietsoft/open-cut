// ============================================================================
// FILE: godzilla_memsponge_types.h
// TARGET: libgodzilla-memsponge.so (1,043,056 bytes, SHA-256: cc00ce74...89a466)
// ARCHITECTURE: AArch64 (ARM64-v8a) — .text [0x0750d0..0x0f3ae8]
// PURPOSE: Core ABI Structures, Proxy Mapping Tables, Global State Layout,
//          and Hardware Constants for ByteDance Godzilla MemSponge, HeapClamp,
//          StringOpt, and Scudo VMA Leak Mitigation Engine.
// MỤC ĐÍCH: Cấu trúc ABI cốt lõi, bảng ánh xạ Proxy, bố cục biến toàn cục,
//           và hằng số phần cứng cho Engine tối ưu bộ nhớ Godzilla MemSponge,
//           HeapClamp, StringOpt và vá lỗi rò rỉ VMA của Scudo.
// ============================================================================

#pragma once

#include <jni.h>
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <mutex>
#include <atomic>

namespace NextAI::OpenCut::godzilla_memsponge {

// ============================================================================
// 1. HARDWARE &BINARY CONSTANTS / HẰNG SỐ PHẦN CỨNG & NHỊ PHÂN
// ============================================================================

/**
 * EN: Maximum clamp threshold for sHideLargeObjectMaxBytes (`0x0778dc`):
 *     `mov x8, #-0xffffffff80000000` (`0xB26183E8`) = `0xFFFFFFFF80000000ULL`.
 * VN: Ngưỡng kẹp tối đa cho sHideLargeObjectMaxBytes (`0x0778dc`):
 *     `mov x8, #-0xffffffff80000000` (`0xB26183E8`) = `0xFFFFFFFF80000000ULL`.
 */
constexpr uint64_t kMaxHideLargeObjectClampMask = 0xFFFFFFFF80000000ULL;

/**
 * EN: Minimum LargeObject allocation size to trigger debug logging in
 *     `larget_object_alloc_proxy` (`0x075274`) and `free_list_alloc_proxy` (`0x075668`):
 *     `cmp x20, #0x80, lsl #12` (`0xF142029F`) = `0x80000` = `524,288` bytes (`512 KB`).
 * VN: Kích thước cấp phát đối tượng lớn tối thiểu để ghi log debug trong
 *     `larget_object_alloc_proxy` (`0x075274`) và `free_list_alloc_proxy` (`0x075668`):
 *     `cmp x20, #0x80, lsl #12` (`0xF142029F`) = `0x80000` = `524.288` byte (`512 KB`).
 */
constexpr size_t kLargeObjectDebugLogThresholdBytes = 0x80000ULL;

/**
 * EN: Minimum FreeList allocation size on Android L (`free_list_alloc_l_proxy` @ `0x07581c`):
 *     `cmp x20, #0x40, lsl #12` (`0xF141029F`) = `0x40000` = `262,144` bytes (`256 KB`).
 * VN: Kích thước cấp phát FreeList tối thiểu trên Android L (`0x07581c`):
 *     `cmp x20, #0x40, lsl #12` (`0xF141029F`) = `0x40000` = `262.144` byte (`256 KB`).
 */
constexpr size_t kFreeListLDebugLogThresholdBytes = 0x40000ULL;

/**
 * EN: Default minimum hide increment in `AllocateInternalWithGcProxy_L` (`0x076850`):
 *     `mov w9, #0x3200000` (`0x52A06409`) = `52,428,800` bytes (`50 MB`).
 * VN: Bước tăng ẩn bộ nhớ tối thiểu mặc định trong `AllocateInternalWithGcProxy_L` (`0x076850`):
 *     `mov w9, #0x3200000` (`0x52A06409`) = `52.428.800` byte (`50 MB`).
 */
constexpr size_t kMinOomRetrySpongeIncrementBytes = 0x3200000ULL;

/**
 * EN: Default ART `Heap::large_object_threshold_` value scanned in `setLargeObjThreshold` (`0x078040`):
 *     `cmp x8, #3, lsl #12` (`0xF1400D1F`) = `0x3000` = `12,288` bytes (`3 pages`).
 * VN: Giá trị `Heap::large_object_threshold_` mặc định của ART được quét tại `0x078040`:
 *     `cmp x8, #3, lsl #12` (`0xF1400D1F`) = `0x3000` = `12.288` byte (`3 trang`).
 */
constexpr size_t kDefaultArtLargeObjectThresholdBytes = 0x3000ULL;

/**
 * EN: Page shift (`12` bits = `4096` bytes) used in `setLargeObjThreshold` (`0x0780ac`):
 *     `sbfiz x9, x9, #0xc, #0x20` (`0x93747D29`).
 * VN: Dịch bit trang nhớ (`12` bit = `4096` byte) dùng trong `setLargeObjThreshold` (`0x0780ac`):
 *     `sbfiz x9, x9, #0xc, #0x20` (`0x93747D29`).
 */
constexpr uint32_t kArtPageShift = 12U;

/**
 * EN: IEEE-754 float base constant in `HeapSetIdealFootPrintProxy` (`0x0786d8`):
 *     `movi v0.2s, #0x4e, lsl #24` (`0x0F0265C0`) = `0x4E000000` = `536,870,912.0f` (`512 MB`).
 * VN: Hằng số cơ sở dấu chấm động IEEE-754 trong `HeapSetIdealFootPrintProxy` (`0x0786d8`):
 *     `movi v0.2s, #0x4e, lsl #24` (`0x0F0265C0`) = `0x4E000000` = `536.870.912,0f` (`512 MB`).
 */
constexpr uint32_t kIdealFootprintBaseFloatBits = 0x4E000000U;
constexpr float kIdealFootprintBaseBytesFloat   = 536870912.0f;

/**
 * EN: Fixed guard VMA base address used in `doFixFreeList` (`0x07a914`):
 *     `mov w0, #0x10000` (`0x52A00020`), triggered when `start_addr >> 17 == 0` (`< 0x20000`).
 * VN: Địa chỉ cơ sở VMA bảo vệ cố định dùng trong `doFixFreeList` (`0x07a914`):
 *     `mov w0, #0x10000` (`0x52A00020`), kích hoạt khi `start_addr >> 17 == 0` (`< 0x20000`).
 */
constexpr uintptr_t kFixFreeListGuardBaseAddr = 0x10000ULL;
constexpr uintptr_t kFixFreeListMaxStartAddr  = 0x20000ULL;
constexpr int kFixFreeListMmapFlags           = 0x31; // MAP_SHARED (0x01) | MAP_FIXED (0x10) | MAP_ANONYMOUS (0x20)
constexpr unsigned long kPrctlSetVmaOption    = 0x53564D41UL; // PR_SET_VMA ('SVMA')

/**
 * EN: Scudo secondary guard threshold formula (`0x07c628..0x07c62c`, `0x07c8fc..0x07c900`):
 *     `max_unguard_size = (getpagesize() << 1) + (0xA << 12)` = `2 * page_size + 40,960`.
 *     For 4 KB pages: `8,192 + 40,960 = 49,152` bytes (`0xC000`).
 * VN: Công thức ngưỡng bảo vệ thứ cấp của Scudo (`0x07c628..0x07c62c`, `0x07c8fc..0x07c900`):
 *     `max_unguard_size = (getpagesize() << 1) + (0xA << 12)` = `2 * page_size + 40.960`.
 *     Với trang 4 KB: `8.192 + 40.960 = 49.152` byte (`0xC000`).
 */
constexpr size_t kScudoSecondaryExtraThresholdBytes = 0xA000ULL; // 0xA << 12 = 40,960 bytes

// ============================================================================
// 2. ENUMERATIONS & BITMASKS / KIỂU LIỆT KÊ & MẶT NẠ BIT
// ============================================================================

/**
 * EN: Operating mode for Godzilla MemSponge (`sCurMemSpongeMode` @ `0x106230`).
 *     Verified at `MemSpongeHelper_startWhenOOM` (`0x0779b8`: `mov w1, #1`) and
 *     `MemSpongeHelper_start` (`0x07793c`: `mov w1, #2`).
 * VN: Chế độ vận hành của Godzilla MemSponge (`sCurMemSpongeMode` @ `0x106230`).
 *     Xác minh tại `MemSpongeHelper_startWhenOOM` (`0x0779b8`: `mov w1, #1`) và
 *     `MemSpongeHelper_start` (`0x07793c`: `mov w1, #2`).
 */
enum class MemSpongeMode : int32_t {
    kDisabled = 0, // Uninitialized or disabled / Chưa khởi tạo hoặc tắt
    kWhenOOM  = 1, // Activate sponge only when OOM is imminent / Chỉ kích hoạt khi sắp OOM
    kActive   = 2  // Proactively hide large object footprint / Chủ động ẩn dung lượng đối tượng lớn
};

/**
 * EN: Architecture bitmask used in `ArtProxyMapping::arch_mask` (`+0x30`):
 *     checked at `initArtHook` (`0x0775d0`: `tbz w7, #1, #0x7751c`).
 *     Bit 0 (`0x1`) = 32-bit ARMv7, Bit 1 (`0x2`) = 64-bit AArch64.
 * VN: Mặt nạ kiến trúc dùng trong `ArtProxyMapping::arch_mask` (`+0x30`):
 *     kiểm tra tại `initArtHook` (`0x0775d0`: `tbz w7, #1, #0x7751c`).
 *     Bit 0 (`0x1`) = 32-bit ARMv7, Bit 1 (`0x2`) = 64-bit AArch64.
 */
enum ArchSupportMask : uint64_t {
    kArchSupport32Bit = 0x1ULL,
    kArchSupport64Bit = 0x2ULL,
    kArchSupportBoth  = 0x3ULL
};

/**
 * EN: ART `gc::AllocatorType` enumeration passed to `AllocateInternalWithGc` and `ThrowOutOfMemoryError`.
 * VN: Kiểu liệt kê `gc::AllocatorType` của ART truyền vào `AllocateInternalWithGc` và `ThrowOutOfMemoryError`.
 */
enum class AllocatorType : int32_t {
    kAllocatorTypeBumpPointer = 0,
    kAllocatorTypeTLAB = 1,
    kAllocatorTypeRosAlloc = 2,
    kAllocatorTypeDlMalloc = 3,
    kAllocatorTypeNonMoving = 4,
    kAllocatorTypeLOS = 5,
    kAllocatorTypeRegion = 6,
    kAllocatorTypeRegionTLAB = 7
};

// ============================================================================
// 3. EXACT ABI STRUCTURES (.data & .bss) / CẤU TRÚC ABI CHÍNH XÁC
// ============================================================================

/**
 * EN: 56-byte (`0x38`) descriptor entry in the 20-entry `ArtProxyMapping` table
 *     located in `.data` at `0x105ba0..0x106000` (`20 * 56 = 1,120 = 0x460` bytes).
 *     Iterated in `initArtHook` (`0x077500..0x0777ec`) with stride `#0x38` (`add x24, x24, #0x38`).
 * VN: Phần tử mô tả 56 byte (`0x38`) trong bảng 20 mục `ArtProxyMapping`
 *     nằm trong `.data` tại `0x105ba0..0x106000` (`20 * 56 = 1.120 = 0x460` byte).
 *     Được duyệt trong `initArtHook` (`0x077500..0x0777ec`) với bước nhảy `#0x38`.
 */
struct ArtProxyMapping {
    const char* symbol_name;   // +0x00: Mangled libart.so symbol name / Tên symbol mangled trong libart.so
    void*       target_addr;   // +0x08: Resolved dlsym address / Địa chỉ hàm gốc sau khi dlsym
    void*       proxy_func;    // +0x10: Godzilla replacement proxy / Hàm proxy thay thế của Godzilla
    void**      orig_func_out; // +0x18: Pointer to global storing original trampoline / Con trỏ lưu hàm gốc
    uint64_t    api_mask;      // +0x20: Bitmask of supported Android API levels (20..35) / Mặt nạ API hỗ trợ
    uint64_t    mode_mask;     // +0x28: Bitmask of MemSpongeMode (1=WhenOOM, 2=Active, 3=Both) / Mặt nạ chế độ
    uint64_t    arch_mask;     // +0x30: Bitmask of CPU architecture (1=32-bit, 2=64-bit) / Mặt nạ kiến trúc CPU
};
static_assert(sizeof(ArtProxyMapping) == 0x38, "ArtProxyMapping must be exactly 56 (0x38) bytes");

/**
 * EN: 40-byte (`0x28`) descriptor entry in the 2-entry `SoftRefProxyMapping` table
 *     located in `.data` at `0x106010..0x106060` (`2 * 40 = 80 = 0x50` bytes).
 *     Indexed in `MemSpongeHelper_adjustSoftReference` (`0x0785bc`: `mov w8, #0x28; madd x21, x21, x8, x9`).
 * VN: Phần tử mô tả 40 byte (`0x28`) trong bảng 2 mục `SoftRefProxyMapping`
 *     nằm trong `.data` tại `0x106010..0x106060` (`2 * 40 = 80 = 0x50` byte).
 *     Truy xuất trong `MemSpongeHelper_adjustSoftReference` (`0x0785bc`: `mov w8, #0x28`).
 */
struct SoftRefProxyMapping {
    const char* symbol_name;   // +0x00: Mangled CollectGarbageInternal symbol / Tên symbol CollectGarbageInternal
    void*       target_addr;   // +0x08: Resolved symbol address / Địa chỉ hàm giải phân giải
    void*       proxy_func;    // +0x10: CollectGarbageInternalRProxy or SProxy / Hàm proxy R hoặc S
    void**      orig_func_out; // +0x18: Pointer to original trampoline slot / Con trỏ lưu hàm gốc
    uint64_t    api_mask;      // +0x20: API bitmask (0x7f8 for API 23..30, 0xf800 for API 31..35)
};
static_assert(sizeof(SoftRefProxyMapping) == 0x28, "SoftRefProxyMapping must be exactly 40 (0x28) bytes");

/**
 * EN: Parsed `/proc/self/maps` line entry used in `HeapClampHelper_printProcessMaps` (`0x07900c`)
 *     with destructor `_ZN14MemoryMapEntryD2Ev` at `0x079920` (`size = 148 B`), containing 6 `std::string` fields.
 * VN: Cấu trúc dòng `/proc/self/maps` dùng trong `HeapClampHelper_printProcessMaps` (`0x07900c`)
 *     với hàm hủy `_ZN14MemoryMapEntryD2Ev` tại `0x079920` (`size = 148 B`), gồm 6 trường `std::string`.
 */
struct MemoryMapEntry {
    std::string address_range; // +0x00: Start-end virtual address range / Dải địa chỉ ảo đầu-cuối
    std::string permissions;   // +0x18: rwxp/s flags / Quyền truy cập trang nhớ
    std::string offset;        // +0x30: File mapping offset / Độ lệch ánh xạ file
    std::string device;        // +0x48: Major:minor device ID / Mã thiết bị major:minor
    std::string inode;         // +0x60: Inode number / Số hiệu inode
    std::string pathname;      // +0x78: Mapped file or VMA name / Đường dẫn file hoặc tên vùng VMA
};

/**
 * EN: Complete global state mirror of `.data` (`0x105b98..0x106070`) and `.bss` (`0x1061e0..0x1063d0`).
 *     Every field offset is documented with its exact virtual address in `libgodzilla-memsponge.so`.
 * VN: Bản sao trạng thái toàn cục đầy đủ của `.data` (`0x105b98..0x106070`) và `.bss` (`0x1061e0..0x1063d0`).
 *     Mỗi trường đều được ghi chú địa chỉ ảo chính xác trong `libgodzilla-memsponge.so`.
 */
struct GodzillaMemSpongeGlobalState {
    // --- .data initialized globals (0x105b98..0x106070) ---
    bool     isIngoreThrowOutOfMemoryError = true;         // 0x105b98 (init = 1)
    int32_t  sConfigApiLevel               = -1;           // 0x106000 (init = 0xffffffff)
    float    sMaxHeapRatio                 = 1.0f;         // 0x106004 (init = 0x3f800000 = 1.0f)
    int64_t  sSoftRefHeapThreshold         = 0x20000000LL; // 0x106008 (init = 512 MB = 536,870,912)
    uint64_t sOriginCapcacity              = ~0ULL;        // 0x106068 (init = 0xffffffffffffffff)

    // --- .bss runtime state (0x1061e0..0x1063d0) ---
    void*    GetBytesAllocatedOrigin       = nullptr;      // 0x1061e0
    void*    ThreadThrowOutOfMemoryOrigin  = nullptr;      // 0x1061e8
    void*    ThreadSetExceptionOrigin      = nullptr;      // 0x1061f0
    void*    ThreadThrowNewExceptionOrigin = nullptr;      // 0x1061f8
    void*    GetPreAllocatedOOMWhenThrowingOrigin = nullptr; // 0x106200
    void*    IsThrowableClassOrigin        = nullptr;      // 0x106208
    void*    AllocFromModifiedUtf8Origin   = nullptr;      // 0x106210
    JavaVM*  java_vm                       = nullptr;      // 0x106218
    void*    global_runtime_p              = nullptr;      // 0x106220
    int32_t  global_api_level              = 0;            // 0x106228
    bool     sAllocateInternalWithGc       = false;        // 0x10622c
    bool     sAgainAllocateInternalWithGc  = false;        // 0x10622d
    bool     isMSpongeOOM                  = false;        // 0x10622e
    int32_t  sCurMemSpongeMode             = 0;            // 0x106230
    void*    sGetObjectsAllocatedOriginFunc = nullptr;     // 0x106238
    void*    sGetBytesAllocatedOriginFunc  = nullptr;      // 0x106240
    void*    sHeapGetBytesAllocatedFunc    = nullptr;      // 0x106248
    int64_t  sJavaVmRuntimeOffset          = 0;            // 0x106250
    int64_t  sRuntimeHeapOffset            = 0;            // 0x106258
    int64_t  sLargeObjectThresholdOffset   = 0;            // 0x106260

    // Original function trampoline slots for the 20 ArtProxyMapping entries (0x106268..0x1062c0)
    void*    sLargeObjMapAllocOrigin       = nullptr;      // 0x106268
    void*    sLargeObjMapAllocL32Origin    = nullptr;      // 0x106270
    void*    sFreeListAllocLOrigin         = nullptr;      // 0x106278
    void*    sFreeListAllocOrigin          = nullptr;      // 0x106280
    void*    sRecordFreeOrigin             = nullptr;      // 0x106288
    void*    sGrowForUtilizationQ32Origin  = nullptr;      // 0x106290
    void*    sGrowForUtilization32Origin   = nullptr;      // 0x106298
    void*    sAllocateInternalWithGcOrigin = nullptr;      // 0x1062a0
    void*    sAllocateInternalWithGcMOrigin = nullptr;     // 0x1062a8
    void*    sAllocateInternalWithGcLOrigin = nullptr;     // 0x1062b0
    void*    sThrowOutOfMemoryErrorOrigin  = nullptr;      // 0x1062b8
    void*    sCollectGarbageInternalROrigin = nullptr;     // 0x1062c0
    void*    sCollectGarbageInternalSOrigin = nullptr;     // 0x1062c8

    // MemSponge runtime tracking state (0x1062d0..0x106318)
    bool     sMemSpongeDebug               = false;        // 0x1062d0
    bool     sHasTriggeredOOM              = false;        // 0x1062d1
    bool     sHasThrownRealOOM             = false;        // 0x1062d2
    uint32_t sThrowOOMCount                = 0;            // 0x1062d4
    void*    sLastLargeObjectSpace         = nullptr;      // 0x1062d8
    uint64_t sHideLargeObjectMaxBytes      = 0;            // 0x1062e0
    uint64_t sAlreadyHiddenBytes           = 0;            // 0x1062e8
    void*    sLastArtHeapPtr               = nullptr;      // 0x1062f0
    int64_t  sCurrentHeapSize              = 0;            // 0x1062f8
    int64_t  sGlobalTriggerGcValue         = 0;            // 0x106300
    int64_t  sAddGcDiffBytes               = 0;            // 0x106308
    void*    sSetIdealFootprintOrigin      = nullptr;      // 0x106310
    void*    sSetIdealFootprintStub        = nullptr;      // 0x106318

    // StringOpt & HeapClamp runtime state (0x106320..0x106388)
    bool     sStringOptDebug               = false;        // 0x106320
    void*    ClampGrowthLimitOrigin        = nullptr;      // 0x106328
    void*    ClearGrowthLimitOrigin        = nullptr;      // 0x106330
    void*    GetTotalMemoryOrigin          = nullptr;      // 0x106338
    void*    sClampGrowthLimitFunc         = nullptr;      // 0x106340
    void*    sClearGrowthLimitFunc         = nullptr;      // 0x106348
    void*    sHeap                         = nullptr;      // 0x106350
    size_t*  sCapcacityAdress              = nullptr;      // 0x106358
    size_t*  sGrowLimitAdress              = nullptr;      // 0x106360
    bool     sHeapClampDebug               = false;        // 0x106368
    bool     sNoClassDefHooked             = false;        // 0x106370
    void*    sThreadSuspendByPeerWarningFunc = nullptr;    // 0x106378
    void*    sGetPreAllocatedNoClassDefFoundErrorFunc = nullptr; // 0x106380
    void*    sThrowEarlierClassFailureFunc = nullptr;      // 0x106388

    // Scudo VMA leak & JNI hook state (0x106390..0x1063d0)
    bool     sScudoMapHooked               = false;        // 0x106390
    bool     sScudoVmaDebug                = false;        // 0x106394
    bool     sScudoLinuxMapHooked          = false;        // 0x106395
    void*    sScudoMapStub                 = nullptr;      // 0x106398
    void*    sScudoUnmapStub               = nullptr;      // 0x1063a0
    void*    sScudoLinuxMapStub            = nullptr;      // 0x1063a8
    void*    sScudoLinuxRemapStub          = nullptr;      // 0x1063b0
    void*    sScudoLinuxUnmapStub          = nullptr;      // 0x1063b8
    void*    sBumpPointerClampGrowLimitAddr = nullptr;     // 0x1063c0
    size_t   sArtMethodEntryPointOffset    = 0;            // 0x1063c8
};

/**
 * EN: Accessor for the singleton global state mirror of `libgodzilla-memsponge.so`.
 * VN: Hàm truy xuất trạng thái toàn cục đơn nguyên của `libgodzilla-memsponge.so`.
 */
GodzillaMemSpongeGlobalState& getGlobalState();

} // namespace NextAI::OpenCut::godzilla_memsponge
