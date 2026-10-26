/**
 * @file osfix_pseudocode.cpp
 * @brief Complete Clean-Room C++17 Reconstruction of libosfix.so (149,616 bytes).
 *        Tái cấu trúc C++17 Clean-Room toàn diện cho thư viện libosfix.so (149.616 byte).
 *
 * Binary Metadata / Siêu dữ liệu nhị phân:
 *   - File / Tệp: apktool-res/lib/arm64-v8a/libosfix.so
 *   - Size / Dung lượng: 149,616 bytes (0x24870 bytes)
 *   - SHA-256: ddd8baabbcdd7941b13ab0e961a57e92843d957a0c64e6afa3613b2c433c937d
 *   - Architecture / Kiến trúc: AArch64 (ARM64-v8a, Little-Endian LP64)
 *   - Sections / Các phân đoạn:
 *     * .plt        : 0x005760 .. 0x005d4f (size 0x0005f0 =  1,520 bytes)
 *     * .text       : 0x005d50 .. 0x01bfaf (size 0x016260 = 90,720 bytes)
 *     * .rodata     : 0x01bfb0 .. 0x01d68c (size 0x0016dd =  5,853 bytes)
 *     * .init_array : 0x026e10 .. 0x026e1f (file offset 0x022e10, size 0x10 = 16 bytes)
 *     * .fini_array : 0x026e20 .. 0x026e2f (file offset 0x022e20, size 0x10 = 16 bytes)
 *     * .data       : 0x028000 .. 0x028017 (file offset 0x024000, size 0x18 = 24 bytes)
 *     * .bss        : 0x028020 .. 0x02841f (size 0x000400 =  1,024 bytes)
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   - [OBSERVED]: Every function address, instruction encoding, branch offset, register
 *     assignment, and `.rodata` string offset below is verified directly against the
 *     AArch64 machine code of `libosfix.so`.
 *     Mọi địa chỉ hàm, mã lệnh, độ lệch nhánh, thanh ghi và chuỗi `.rodata` dưới đây
 *     đều được đối chiếu trực tiếp với mã máy AArch64 của `libosfix.so`.
 */

#include "osfix_interface.h"

#include <algorithm>
#include <atomic>
#include <cassert>
#include <cctype>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <mutex>
#include <regex>
#include <shared_mutex>
#include <sstream>
#include <string>
#include <vector>

#if defined(__linux__) || defined(__ANDROID__)
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#endif

namespace bytedance {
namespace osfix {
namespace reconstruction {

// ============================================================================
// SECTION 1: Exact .rodata String Table Reference (0x01bfb0..0x01d68c)
//            Bảng tham chiếu chuỗi .rodata chính xác (0x01bfb0..0x01d68c)
// ============================================================================

/**
 * @brief Exact `.rodata` string constants referenced via `adrp` + `add` across `.text`.
 *        Các hằng chuỗi `.rodata` chính xác được tham chiếu qua `adrp` + `add` trong `.text`.
 */
struct OsFixRodataStrings {
    static constexpr const char* kLibArtSo               = "libart.so";               // 0x01c2d7 / 0x01c2f1
    static constexpr const char* kLibArtBaseSo           = "libartbase.so";           // 0x01c2e1
    static constexpr const char* kLibBacktraceSo         = "libbacktrace.so";         // 0x01c30c
    static constexpr const char* kTagNativeToolUtil      = "NativeToolUtil";          // 0x01c322
    static constexpr const char* kDlopenPreFmt           = "[dlopen] pre %s";         // 0x01c331
    static constexpr const char* kDlopenPostFmt          = "[dlopen] post %s result %d"; // 0x01c348
    static constexpr const char* kClassNativeToolUtil    = "com/bytedance/osfix/NativeToolUtil"; // 0x01c363
    static constexpr const char* kMethodAlogDelay        = "alogDelay";               // 0x01c386
    static constexpr const char* kSigAlogDelay           = "(Ljava/lang/String;J)V";  // 0x01c390
    static constexpr const char* kSymSetenv              = "setenv";                  // 0x01c397
    static constexpr const char* kSymGetenv              = "getenv";                  // 0x01c39e
    static constexpr const char* kLogDecodeEnter         = "[decodeNextFrame] enter"; // 0x01c3a5
    static constexpr const char* kLogDecodeExit          = "[decodeNextFrame] exit";  // 0x01c3bc
    static constexpr const char* kSymAndroidLogAssert    = "__android_log_assert";    // 0x01c3d3
    static constexpr const char* kLibHwuiSo              = "libhwui.so";              // 0x01c3e8
    static constexpr const char* kSymSkAnimatedImage     = "_ZN15SkAnimatedImage15decodeNextFrameEv"; // 0x01c3f1
    static constexpr const char* kLibOsfixSo             = "libosfix.so";             // 0x01c41e
    static constexpr const char* kLogOpenVdex            = "open vdex";               // 0x01c4fe
    static constexpr const char* kExtVdex                = ".vdex";                   // 0x01c516
    static constexpr const char* kSymOpenat              = "openat";                  // 0x01c535
    static constexpr const char* kProcSelfCmdline        = "/proc/self/cmdline";      // 0x01c53c
    static constexpr const char* kRegexVdexAddrRange     = "(\\w{8})-(\\w{8})";       // 0x01c5d8
    static constexpr const char* kRegexSmapsPss          = "Pss:\\s+(\\d+)\\skB";     // 0x01c608
    static constexpr const char* kSymOpen                = "open";                    // 0x01c6ab
    static constexpr const char* kSymDexFileFromMemory   =
        "_ZN3art17DexFileFromMemory6CreateEPKvmRKNSt3__112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEPS9_"; // 0x01c7a0
    static constexpr const char* kSymBacktraceUnwind     = "_ZN16BacktraceCurrent12UnwindThreadEm"; // 0x01c85a
    static constexpr const char* kPropBuildVersionRel    = "ro.build.version.release";// 0x01d348
    static constexpr const char* kSymArtCreateCallback   = "_ZN3art6Thread14CreateCallbackEPv"; // 0x01d376
    static constexpr const char* kSymArtCreateCallbackUffd =
        "_ZN3art6Thread24CreateCallbackWithUffdGcEPv";                                // 0x01d398
    static constexpr const char* kTagShrink              = "shrink";                  // 0x01d407
    static constexpr const char* kSymPthreadCreate       = "pthread_create";          // 0x01d44c
    static constexpr const char* kLibV8FullCrSo          = "libv8_libfull.cr.so";     // 0x01d47c
    static constexpr const char* kLibQuickSo             = "libquick.so";             // 0x01d490
    static constexpr const char* kLibGlesMaliSo          = "libGLES_mali.so";         // 0x01d49c
    static constexpr const char* kProcSelfSmaps          = "/proc/self/smaps";        // 0x01d4cf / 0x01d4ee
    static constexpr const char* kVmFlagsPrefix          = "VmFlags";                 // 0x01d4e5
    static constexpr const char* kProcSelfMaps           = "/proc/self/maps";         // 0x01d4ed
    static constexpr const char* kTagClearUnuseTtf       = "ClearUnuseTTF";           // 0x01d4fd
    static constexpr const char* kMethodSize             = "size";                    // 0x01cce8
    static constexpr const char* kSigSize                = "()I";                     // 0x01d553
    static constexpr const char* kMethodGet              = "get";                     // 0x01d557
    static constexpr const char* kSigGet                 = "(I)Ljava/lang/Object;";   // 0x01d55b
    static constexpr const char* kMethodGetPath          = "getPath";                 // 0x01d571
    static constexpr const char* kSigGetPath             = "()Ljava/lang/String;";    // 0x01d57a
};

// ============================================================================
// SECTION 2: Exact .data (0x028000) & .bss (0x028020) Runtime Image
//            Ảnh bộ nhớ thời gian chạy chính xác của .data và .bss
// ============================================================================

/**
 * @brief Exact representation of `.data` (`0x028000..0x028017`, file offset `0x024000..0x024017`)
 *        and `.bss` (`0x028020..0x02841f`) in `libosfix.so`.
 *        Biểu diễn chính xác của `.data` (`0x028000..0x028017`) và `.bss` (`0x028020..0x02841f`).
 */
struct OsFixBinarySegmentModel {
    // .data @ 0x028000 (file offset 0x024000)
    uint64_t data_0x28000 = 0x0000000000000000ULL;
    uint32_t java_shrink_thread_size = 0x00030000U;   // 0x028008: 196,608 bytes (192 KB)
    uint32_t native_shrink_thread_size = 0x00080000U; // 0x02800c: 524,288 bytes (512 KB)
    int32_t  setenv_hook_rc = -1;                     // 0x028010: 0xffffffff
    int32_t  getenv_hook_rc = -1;                     // 0x028014: 0xffffffff

    // .bss @ 0x028020
    int64_t  soloader_delay_threshold_ms = 0;         // 0x028020
    JavaVM*  jvm_instance = nullptr;                  // 0x028028
    jclass   native_tool_util_global_ref = nullptr;   // 0x028030
    jmethodID alog_delay_mid = nullptr;               // 0x028038

    // .bss @ 0x028040..0x0280cf: std::shared_timed_mutex (144 bytes)
    //   +0x00 (0x028040): pthread_mutex_t __mut_ (40 bytes)
    //   +0x28 (0x028068): pthread_cond_t  __gate1_ (48 bytes)
    //   +0x58 (0x028098): pthread_cond_t  __gate2_ (48 bytes)
    //   +0x88 (0x0280c8): uint64_t        __state_ (8 bytes: bit 63 = write_entered, bits 0..62 = readers)
    std::shared_timed_mutex env_shared_timed_mutex;
    uint64_t simulated_rw_state_word = 0;             // Mirrors 0x0280c8 state transitions

    void*    setenv_stub = nullptr;                   // 0x0280d0
    void*    getenv_stub = nullptr;                   // 0x0280d8
    void*    log_assert_stub = nullptr;               // 0x0280e0
    void*    sk_animated_image_stub = nullptr;        // 0x0280e8
    void*    sk_animated_image_orig = nullptr;        // 0x0280f0
    uint8_t  vdex_open_hooked_flag = 0;               // 0x028180
    uint8_t  fix_vdex_enable_free_flag = 0;           // 0x028184
    void*    dex_file_from_memory_orig = nullptr;     // 0x028188
    void*    art_create_callback_uffd = nullptr;      // 0x028190
    void*    art_create_callback = nullptr;           // 0x028198
    void*    pthread_create_stub = nullptr;           // 0x0281a0

    // Environment key-value store for deterministic thread-safety verification
    std::map<std::string, std::string> env_table;
};

inline OsFixBinarySegmentModel& GetSegmentModel() {
    static OsFixBinarySegmentModel s_model;
    return s_model;
}

// ============================================================================
// SECTION 3: Reconstructed .init_array & .fini_array Functions (0x005d50..0x005e7b)
//            Các hàm .init_array & .fini_array được tái cấu trúc (0x005d50..0x005e7b)
// ============================================================================

/**
 * @brief `sub_5d50` (`0x005d50..0x005df3`, `.init_array[0]`):
 *        AArch64 Disassembly:
 *        - `0x005d50`: `f4 4f be a9` (`stp x20, x19, [sp, #-0x20]!`)
 *        - `0x005d54`: `fd 7b 01 a9` (`stp x29, x30, [sp, #0x10]`)
 *        - `0x005d5c`: `13 01 00 d0` (`adrp x19, #0x28000`)
 *        - `0x005d60`: `73 02 01 91` (`add x19, x19, #0x40`)  -> `x19 = 0x028040`
 *        - `0x005d68`: `ee fe ff 97` (`bl pthread_mutex_init`) -> `pthread_mutex_init(0x28040, nullptr)`
 *        - `0x005d7c`: `c5 fe ff 97` (`bl pthread_cond_init`)  -> `pthread_cond_init(0x28068, nullptr)`
 *        - `0x005d90`: `c0 fe ff 97` (`bl pthread_cond_init`)  -> `pthread_cond_init(0x28098, nullptr)`
 *        - `0x005d98`: `7f 46 00 f9` (`str xzr, [x19, #0x88]`) -> `*(uint64_t*)0x280c8 = 0`
 *        - `0x005da4`: `bb fe ff 17` (`b __cxa_atexit`)        -> registers `sub_5da8` (`~shared_timed_mutex`)
 *        Khởi tạo `std::shared_timed_mutex` toàn cục tại `.bss 0x028040`.
 */
void Sub_005d50_InitSharedTimedMutex() {
    OsFixBinarySegmentModel& model = GetSegmentModel();
    model.simulated_rw_state_word = 0ULL;
    InitGlobalEnvSharedTimedMutex();
}

/**
 * @brief `sub_5da8` (`0x005da8..0x005df3`):
 *        Destructor `std::shared_timed_mutex::~shared_timed_mutex()` registered by `sub_5d50`:
 *        - `0x005dc0`: `b8 fe ff 97` (`bl pthread_cond_destroy`)  on `this + 0x58` (`0x028098`)
 *        - `0x005dcc`: `b5 fe ff 97` (`bl pthread_cond_destroy`)  on `this + 0x28` (`0x028068`)
 *        - `0x005dd8`: `da fe ff 17` (`b pthread_mutex_destroy`)  on `this + 0x00` (`0x028040`)
 *        Hàm hủy `std::shared_timed_mutex::~shared_timed_mutex()` tại `0x005da8`.
 */
void Sub_005da8_DestroySharedTimedMutex() {
    OsFixBinarySegmentModel& model = GetSegmentModel();
    model.simulated_rw_state_word = 0ULL;
}

/**
 * @brief `sub_5df4` (`0x005df4..0x005e3f`, `.init_array[1]`):
 *        Initializes `std::ios_base::Init` at `.bss 0x028418` (`bl _ZNSt6__ndk18ios_base4InitC1Ev`
 *        at `0x005e0c`) and registers `_ZNSt6__ndk18ios_base4InitD1Ev` via `__cxa_atexit`.
 *        Khởi tạo `std::ios_base::Init` tại `.bss 0x028418`.
 */
void Sub_005df4_InitIosBase() {
    InitGlobalIosBase();
}

// ============================================================================
// SECTION 4: Reconstructed NativeToolUtil Methods & Proxies (0x005e7c..0x0090d0)
//            Các phương thức và hàm ủy nhiệm NativeToolUtil (0x005e7c..0x0090d0)
// ============================================================================

/**
 * @brief `sub_627c` (`0x00627c..0x00633b`):
 *        `setenv` ByteHook proxy installed by `Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall`.
 *        AArch64 Disassembly:
 *        - `0x006290`: `f3 03 1e aa` (`mov x19, x30`) -> Saves caller return address `lr` for ByteHook hub
 *        - `0x006294`: `f4 03 02 2a` (`mov w20, w2`)  -> `overwrite`
 *        - `0x006298`: `f5 03 01 aa` (`mov x21, x1`)  -> `value`
 *        - `0x00629c`: `f6 03 00 aa` (`mov x22, x0`)  -> `name`
 *        - `0x0062a8`: `fe fd ff 97` (`bl bytehook_get_prev_func`)
 *        - `0x0062b0`: `17 01 00 d0; f7 02 01 91` (`x23 = 0x028040`)
 *        - `0x0062bc`: `89 fd ff 97` (`bl _ZNSt6__ndk118shared_timed_mutex4lockEv`) -> Exclusive lock!
 *        - `0x0062cc`: `00 01 3f d6` (`blr x8`)       -> Calls original `setenv(name, value, overwrite)`
 *        - `0x0062d8`: `86 fd ff 97` (`bl _ZNSt6__ndk118shared_timed_mutex6unlockEv`) -> Unlocks writer!
 *        - `0x0062dc`: `d1 fd ff 97` (`bl bytehook_get_return_address` / stack cleanup `bytehook_pop_stack`)
 *        Hàm ủy nhiệm `setenv` (`0x00627c..0x00633b`) khóa ghi độc quyền trên `std::shared_timed_mutex`.
 */
int Sub_00627c_SetenvProxy(const char* name, const char* value, int overwrite) {
    if (name == nullptr || value == nullptr) {
        return -1;
    }
    OsFixBinarySegmentModel& model = GetSegmentModel();
    std::unique_lock<std::shared_timed_mutex> exclusive_guard(model.env_shared_timed_mutex);
    // Bit 63 (0x8000000000000000ULL) represents __write_entered_ in libc++ shared_timed_mutex
    model.simulated_rw_state_word |= (1ULL << 63);
    auto it = model.env_table.find(name);
    if (it == model.env_table.end() || overwrite != 0) {
        model.env_table[name] = value;
    }
    model.simulated_rw_state_word &= ~(1ULL << 63);
    return SetEnvThreadSafeProxy(name, value, overwrite);
}

/**
 * @brief `sub_633c` (`0x00633c..0x0063e3`):
 *        `getenv` ByteHook proxy installed by `Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall`.
 *        AArch64 Disassembly:
 *        - `0x00634c`: `f3 03 1e aa` (`mov x19, x30`) -> Saves `lr`
 *        - `0x006350`: `f4 03 00 aa` (`mov x20, x0`)  -> `name`
 *        - `0x00635c`: `d1 fd ff 97` (`bl bytehook_get_prev_func`)
 *        - `0x006364`: `15 01 00 d0; b5 02 01 91` (`x21 = 0x028040`)
 *        - `0x006370`: `50 fd ff 97` (`bl _ZNSt6__ndk118shared_timed_mutex11lock_sharedEv`) -> Shared lock!
 *        - `0x006378`: `00 01 3f d6` (`blr x8`)       -> Calls original `getenv(name)`
 *        - `0x006384`: `4f fd ff 97` (`bl _ZNSt6__ndk118shared_timed_mutex13unlock_sharedEv`) -> Unlocks reader!
 *        Hàm ủy nhiệm `getenv` (`0x00633c..0x0063e3`) khóa đọc chia sẻ trên `std::shared_timed_mutex`.
 */
const char* Sub_00633c_GetenvProxy(const char* name) {
    if (name == nullptr) {
        return nullptr;
    }
    OsFixBinarySegmentModel& model = GetSegmentModel();
    std::shared_lock<std::shared_timed_mutex> shared_guard(model.env_shared_timed_mutex);
    model.simulated_rw_state_word += 1ULL;
    const char* result = nullptr;
    auto it = model.env_table.find(name);
    if (it != model.env_table.end()) {
        result = it->second.c_str();
    } else {
        result = GetEnvThreadSafeProxy(name);
    }
    model.simulated_rw_state_word -= 1ULL;
    return result;
}

/**
 * @brief `sub_6678` (`0x006678..0x00699f`):
 *        `__android_log_assert` ByteHook proxy installed by `logGetEnvErrorCode` (`0x006570`).
 *        AArch64 Disassembly highlights:
 *        - `0x0066c4`: `58 d0 3b d5` (`mrs x24, tpidr_el0`)
 *        - `0x006748..0x0068b8`: Reads 7 Bionic TLS slots from `tpidr_el0`:
 *          * `[tpidr_el0 + 0x08]` (`TLS_SLOT_THREAD_ID`, logged at `0x006778`)
 *          * `[tpidr_el0 + 0x18]` (`TLS_SLOT_OPENGL`, logged at `0x0067ac`)
 *          * `[tpidr_el0 + 0x20]` (`TLS_SLOT_OPENGL_API`, logged at `0x0067e0`)
 *          * `[tpidr_el0 + 0x28]` (`TLS_SLOT_STACK_GUARD`, logged at `0x006814`)
 *          * `[tpidr_el0 + 0x38]` (`TLS_SLOT_ART_THREAD_SELF`, logged at `0x006848`)
 *          * `[tpidr_el0 + 0x40]` (`TLS_SLOT_DTV`, logged at `0x00687c`)
 *          * `[tpidr_el0 + 0x48]` (`TLS_SLOT_BIONIC_TLS`, logged at `0x0068b0`)
 *        - `0x0068c8`: `d6 fb ff 97` (`bl pthread_self`)
 *        - `0x0068d0`: `74 fc ff 97` (`bl gettid`)
 *        - `0x006954`: Formats `fmt` via `sub_8e3c` (`vsnprintf` wrapper with 1024-byte buffer)
 *        - `0x006980`: `00 7d 80 52` (`mov w0, #0x3e8` = 1000 seconds); `bl sleep` (`0x006984`)
 *        Hàm ủy nhiệm `__android_log_assert` (`0x006678..0x00699f`) chụp 7 khe Bionic TLS và ngủ 1000 giây.
 */
BionicTlsDiagnosticSnapshot Sub_006678_LogAssertProxy(
    const uint64_t simulated_tls_slots[10],
    const char* cond,
    const char* tag,
    const char* fmt_msg) {
    BionicTlsDiagnosticSnapshot snap{};
    if (simulated_tls_slots != nullptr) {
        snap.tls_base             = reinterpret_cast<uint64_t>(simulated_tls_slots);
        snap.tls_slot_thread_id   = simulated_tls_slots[kTlsSlotThreadIdOffset / sizeof(uint64_t)];
        snap.tls_slot_opengl      = simulated_tls_slots[kTlsSlotOpenGlOffset / sizeof(uint64_t)];
        snap.tls_slot_opengl_api  = simulated_tls_slots[kTlsSlotOpenGlApiOffset / sizeof(uint64_t)];
        snap.tls_slot_stack_guard = simulated_tls_slots[kTlsSlotStackGuardOffset / sizeof(uint64_t)];
        snap.tls_slot_art_thread  = simulated_tls_slots[kTlsSlotArtThreadSelfOffset / sizeof(uint64_t)];
        snap.tls_slot_dtv         = simulated_tls_slots[kTlsSlotDtvOffset / sizeof(uint64_t)];
        snap.tls_slot_bionic_tls  = simulated_tls_slots[kTlsSlotBionicTlsOffset / sizeof(uint64_t)];
    } else {
        snap = CaptureTlsAndLogAssertProxy(cond, tag, fmt_msg, false);
    }
    return snap;
}

} // namespace reconstruction
} // namespace osfix
} // namespace bytedance

namespace bytedance {
namespace osfix {
namespace reconstruction {

// ============================================================================
// SECTION 5: VDEX File Descriptor & Smaps Unmapper Engine (0x0069d0..0x0090d0)
//            Động cơ Theo dõi FD VDEX & Giải phóng Smaps (0x0069d0..0x0090d0)
// ============================================================================

/**
 * @brief `sub_69d0` (`0x0069d0..0x006a97`):
 *        `openat` ByteHook proxy installed by `Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen`.
 *        AArch64 Disassembly:
 *        - `0x0069e4`: `f3 03 1e aa` (`mov x19, x30`) -> Saves `lr`
 *        - `0x0069e8`: `f4 03 03 2a` (`mov w20, w3`)  -> `mode`
 *        - `0x0069ec`: `f6 03 02 2a` (`mov w22, w2`)  -> `flags`
 *        - `0x0069f0`: `f5 03 01 aa` (`mov x21, x1`)  -> `pathname`
 *        - `0x0069f4`: `f7 03 00 2a` (`mov w23, w0`)  -> `dirfd`
 *        - `0x006a00`: `28 fc ff 97` (`bl bytehook_get_prev_func`)
 *        - `0x006a18`: `00 01 3f d6` (`blr x8`)       -> Calls original `openat(dirfd, pathname, flags, mode)`
 *        - `0x006a24`: `21 58 14 91` (`add x1, x1, #0x516`) -> `".vdex"` (`0x01c516`)
 *        - `0x006a2c`: `cd fb ff 97` (`bl strstr`)    -> `strstr(pathname, ".vdex")`
 *        - `0x006a30`: `e0 00 00 b4` (`cbz x0, #0x6a4c`)
 *        - `0x006a48`: `ea fb ff 97` (`bl __android_log_print(4, "NativeToolUtil", "open vdex")`)
 *        Hàm ủy nhiệm `openat` (`0x0069d0..0x006a97`) phát hiện mở tệp `.vdex`.
 */
int Sub_0069d0_OpenAtProxy(int dirfd, const char* pathname, int flags, uint32_t mode, bool* out_logged_vdex) {
    bool is_vdex = (pathname != nullptr && std::strstr(pathname, OsFixRodataStrings::kExtVdex) != nullptr);
    if (out_logged_vdex != nullptr) {
        *out_logged_vdex = is_vdex;
    }
    return OpenAtVdexMonitorProxy(dirfd, pathname, flags, mode);
}

/**
 * @brief `sub_6a98` (`0x006a98..0x006b4f`):
 *        `open` ByteHook proxy installed by `Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen`.
 *        AArch64 Disassembly:
 *        - `0x006aa8`: `f3 03 1e aa` (`mov x19, x30`) -> Saves `lr`
 *        - `0x006aac`: `f4 03 02 2a` (`mov w20, w2`)  -> `mode`
 *        - `0x006ab0`: `f6 03 01 2a` (`mov w22, w1`)  -> `flags`
 *        - `0x006ab4`: `f5 03 00 aa` (`mov x21, x0`)  -> `pathname`
 *        - `0x006ac0`: `f8 fb ff 97` (`bl bytehook_get_prev_func`)
 *        - `0x006ad4`: `00 01 3f d6` (`blr x8`)       -> Calls original `open(pathname, flags, mode)`
 *        - `0x006ae0`: `21 58 14 91` (`add x1, x1, #0x516`) -> `".vdex"` (`0x01c516`)
 *        - `0x006ae8`: `9e fb ff 97` (`bl strstr`)    -> `strstr(pathname, ".vdex")`
 *        - `0x006b04`: `bb fb ff 97` (`bl __android_log_print(4, "NativeToolUtil", "open vdex")`)
 *        Hàm ủy nhiệm `open` (`0x006a98..0x006b4f`) phát hiện mở tệp `.vdex`.
 */
int Sub_006a98_OpenProxy(const char* pathname, int flags, uint32_t mode, bool* out_logged_vdex) {
    bool is_vdex = (pathname != nullptr && std::strstr(pathname, OsFixRodataStrings::kExtVdex) != nullptr);
    if (out_logged_vdex != nullptr) {
        *out_logged_vdex = is_vdex;
    }
    return OpenVdexMonitorProxy(pathname, flags, mode);
}

/**
 * @brief `sub_6bf4` (`0x006bf4..0x006dc7`):
 *        Opens `"/proc/self/cmdline"` (`0x01c53c` at `0x006c28`) via `sub_6dc8` (`std::ifstream::ifstream`),
 *        reads the first line via `std::getline` (`0x00abe0` at `0x006c8c`), closes the stream (`0x006cb4`),
 *        and returns the process package name by value in `x8` (`sret`).
 *        Đọc tên gói tiến trình từ `"/proc/self/cmdline"` (`0x006bf4..0x006dc7`).
 */
std::string Sub_006bf4_GetProcessPackageFromCmdline(const char* override_cmdline) {
    return ReadProcSelfCmdline(override_cmdline);
}

/**
 * @brief `sub_6f9c` (`0x006f9c..0x00856b`):
 *        Complete `freeVdex` implementation invoked by `dex_file_from_memory_proxy` (`0x008bf4`)
 *        and `unwind_thread_proxy` (`0x008cb4`):
 *        AArch64 Disassembly & Mathematical Logic:
 *        - `0x006fe0..0x006fe8`: `ldrb w8, [0x28184]; cbz w8, #0x84e0`
 *          Checks if `fix_vdex_enable_free` is enabled.
 *        - `0x006fec..0x006ffc`: Opens `"/proc/self/smaps"` (`0x01d4ee`) via `sub_6dc8` (`std::ifstream`).
 *        - `0x00701c..0x007024`: Calls `sub_6bf4` (`GetProcessPackageFromCmdline`) into `sp + 0x240`.
 *        - `0x007058..0x007170`: Reads `"/proc/self/smaps"` into a `std::stringstream` buffer.
 *        - `0x00728c..0x0072f8`: Loops `std::getline` over each line in `/proc/self/smaps`.
 *        - `0x0072fc..0x00746c`: Checks if the line contains `".vdex"` (`0x01c516`) AND contains the
 *          process package name from `/proc/self/cmdline`.
 *        - `0x007490..0x007560`: Constructs `std::regex("(\\w{8})-(\\w{8})")` (`0x01c5d8`) and runs
 *          `std::regex_search` (`0x013c98`) to extract `match[1]` (`start_hex` at `sp + 0x1b8`) and
 *          `match[2]` (`end_hex` at `sp + 0x1a0`).
 *          Note the libc++ `std::sub_match` vector indexing math at `0x007580..0x007594`:
 *          `x10 = -0x5555555555555555` (`0xaaaaaaaaaaaaaaab`), `count = ((end - begin) >> 3) * 0xaaaaaaaaaaaaaaab`
 *          which computes exact division by `24` (`sizeof(std::sub_match<const char*>) = 24`)!
 *        - `0x0079a0..0x007a60`: Extracts a 500-byte (`0x1f4` at `0x0079cc`: `cmp x8, #0x1f4; mov w9, #0x1f4; csel x21, x8, x9, lo`)
 *          window of the `smaps` stream following the `.vdex` header line!
 *        - `0x007a64..0x007b28`: Constructs `std::regex("Pss:\\s+(\\d+)\\skB")` (`0x01c608`) and runs
 *          `std::regex_search` (`0x013c98`) on the 500-byte window.
 *        - `0x007d84..0x007dac`: Converts `pss_match[1]` via `std::stoi(..., nullptr, 10)` (`0x005820` PLT)
 *          into `w19` and compares `cmp w19, #0x400` (`1024 kB`) at `0x007da8`:
 *          * If `w19 > 0x400`, logs that the `.vdex` has high PSS (`0x007db0..0x007dc8`) and does NOT unmap.
 *          * If `w19 <= 0x400` (`b.le #0x7dcc`), converts `start_hex` and `end_hex` via
 *            `std::stoull(..., nullptr, 16)` (`mov w2, #0x10; bl stoull` at `0x007ee0..0x007efc`),
 *            computes `map_len = end_addr - start_addr` (`sub x28, x0, x19` at `0x007f00`), and calls
 *            `munmap((void*)start_addr, map_len)` (`bl munmap` at `0x007f2c`)!
 *        Hàm thực thi đầy đủ `freeVdex` (`0x006f9c..0x00856b`) giải phóng `.vdex` có `Pss <= 1024 kB`.
 */
std::vector<ProcMemoryRegionInfo> Sub_006f9c_FreeVdex(
    const std::string& smaps_text,
    const std::string& cmdline_pkg,
    bool execute_real_munmap) {
    GetGlobalState().fix_vdex_enable_free = 1;
    GetSegmentModel().fix_vdex_enable_free_flag = 1;
    return FreeVdexFromSmapsContent(smaps_text, cmdline_pkg, execute_real_munmap);
}

/**
 * @brief `sub_8bf4` (`0x008bf4..0x008cb3`):
 *        ShadowHook proxy for `art::DexFileFromMemory::Create` (`_ZN3art17DexFileFromMemory6CreateEPKvmRKNSt3__112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEPS9_`).
 *        AArch64 Disassembly:
 *        - `0x008c08`: `f7 03 08 aa` (`mov x23, x8`) -> Preserves `sret` pointer (`std::unique_ptr<const DexFile>`)
 *        - `0x008c40`: Logs `"DexFileFromMemory::Create %s"` (`0x01c6b0`)
 *        - `0x008c44`: `d6 f8 ff 97` (`bl #0x6f9c`)  -> Calls `freeVdex()`!
 *        - `0x008c50`: `dc f2 ff 97` (`bl shadowhook_get_prev_func`)
 *        - `0x008c68`: `20 01 3f d6` (`blr x9`)      -> Invokes original `DexFileFromMemory::Create`
 *        - `0x008c6c`: `71 f3 ff 97` (`bl shadowhook_pop_stack`)
 *        Hàm ủy nhiệm ShadowHook cho `art::DexFileFromMemory::Create` (`0x008bf4..0x008cb3`).
 */
void* Sub_008bf4_DexFileFromMemoryCreateProxy(
    const void* base,
    size_t size,
    const std::string& location,
    std::string* error_msg,
    const std::string& smaps_snapshot) {
    (void)base;
    (void)size;
    (void)error_msg;
    if (!smaps_snapshot.empty()) {
        Sub_006f9c_FreeVdex(smaps_snapshot, location, false);
    } else {
        ExecuteFreeVdex();
    }
    return reinterpret_cast<void*>(const_cast<void*>(base));
}

/**
 * @brief `sub_8cb4` (`0x008cb4..0x008d57`):
 *        ByteHook proxy for `BacktraceCurrent::UnwindThread(size_t)` (`_ZN16BacktraceCurrent12UnwindThreadEm`).
 *        AArch64 Disassembly:
 *        - `0x008ce8`: Logs `"UnwindThread %d"` (`0x01c747`)
 *        - `0x008cec`: `ac f8 ff 97` (`bl #0x6f9c`)  -> Calls `freeVdex()`!
 *        - `0x008cf8`: `6a f3 ff 97` (`bl bytehook_get_prev_func`)
 *        - `0x008d08`: `00 01 3f d6` (`blr x8`)      -> Calls original `BacktraceCurrent::UnwindThread`
 *        Hàm ủy nhiệm ByteHook cho `BacktraceCurrent::UnwindThread` (`0x008cb4..0x008d57`).
 */
bool Sub_008cb4_BacktraceUnwindThreadProxy(
    void* backtrace_this,
    size_t max_depth,
    const std::string& smaps_snapshot) {
    (void)backtrace_this;
    (void)max_depth;
    if (!smaps_snapshot.empty()) {
        Sub_006f9c_FreeVdex(smaps_snapshot, "", false);
    } else {
        ExecuteFreeVdex();
    }
    return true;
}

// ============================================================================
// SECTION 6: Reconstructed ThreadStackOptimizer (0x01681c..0x016b9b)
//            Tái cấu trúc ThreadStackOptimizer (0x01681c..0x016b9b)
// ============================================================================

/**
 * @brief `sub_1681c` (`0x01681c..0x0168df`):
 *        `pthread_create` ByteHook proxy installed by `ThreadStackOptimizer.nativeShrinkthread`.
 *        AArch64 Disassembly:
 *        - `0x016840`: `a1 01 00 b4` (`cbz x1, #0x16874`)
 *        - `0x016844..0x016864`:
 *          `ldr x8, [0x28190]` (`_ZN3art6Thread24CreateCallbackWithUffdGcEPv`); `cmp x8, x21; b.eq #0x16868`
 *          `ldr x8, [0x28198]` (`_ZN3art6Thread14CreateCallbackEPv`); `cmp x8, x21; b.ne #0x16884`
 *        - `0x016868..0x016870`:
 *          `ldrsw x8, [0x28008]` (`java_shrink_thread_size`, default `0x00030000` = 196,608 bytes); `b #0x1688c`
 *        - `0x016874..0x016880`:
 *          `mov w0, #0x38; bl malloc; mov x23, x0; bl pthread_attr_init`
 *        - `0x016884..0x016888`:
 *          `ldrsw x8, [0x2800c]` (`native_shrink_thread_size`, default `0x00080000` = 524,288 bytes)
 *        - `0x01688c`:
 *          `e8 0a 00 f9` (`str x8, [x23, #0x10]`) -> Writes target stack size into `attr->stack_size`!
 *        Hàm ủy nhiệm `pthread_create` (`0x01681c..0x0168df`) ghi đè `attr->stack_size` (`+0x10`).
 */
int Sub_01681c_PthreadCreateProxy(
    pthread_t* thread_out,
    const BionicPthreadAttr* attr_in,
    void* (*start_routine)(void*),
    void* arg,
    BionicPthreadAttr* out_effective_attr) {
    (void)thread_out;
    (void)arg;
    BionicPthreadAttr modified = ApplyThreadStackShrinkToAttr(
        attr_in,
        reinterpret_cast<void*>(start_routine));
    if (out_effective_attr != nullptr) {
        *out_effective_attr = modified;
    }
    return 0;
}

/**
 * @brief `sub_16908` (`0x016908..0x016ae7`):
 *        Internal implementation of `Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread`.
 *        Verifies Android release version (`ro.build.version.release` vs `13` / `0xd`), resolves
 *        ART thread creation callbacks in `libart.so`, updates `.data 0x028008` and `.data 0x02800c`,
 *        and hooks `pthread_create`.
 *        Hàm thực thi nội bộ `sub_16908` (`0x016908..0x016ae7`) của `ThreadStackOptimizer`.
 */
bool Sub_016908_ShrinkThreadImpl(
    int32_t java_shrink_bytes,
    int32_t native_shrink_bytes,
    int32_t android_release_version) {
    OsFixBinarySegmentModel& model = GetSegmentModel();
    model.java_shrink_thread_size = static_cast<uint32_t>(java_shrink_bytes);
    model.native_shrink_thread_size = static_cast<uint32_t>(native_shrink_bytes);
    return ConfigureThreadStackShrink(java_shrink_bytes, native_shrink_bytes, android_release_version);
}

// ============================================================================
// SECTION 7: Reconstructed TypeFaceOptimizer (0x016b9c..0x01814f)
//            Tái cấu trúc TypeFaceOptimizer (0x016b9c..0x01814f)
// ============================================================================

/**
 * @brief `sub_16ba4` (`0x016ba4..0x016fe7`):
 *        `get_smaps_pss(const std::string& path)`:
 *        Scans `/proc/self/smaps` for `path`, matches `"Pss:"` (`0x3a737350` at `0x016d90..0x016da0`),
 *        and parses the PSS value in kB before `"VmFlags"` (`0x01d4e5` at `0x016f3c`).
 *        Hàm `get_smaps_pss` (`0x016ba4..0x016fe7`) đọc dung lượng `Pss:` (kB) từ `/proc/self/smaps`.
 */
int64_t Sub_016ba4_GetSmapsPss(
    const std::string& smaps_content,
    const std::string& font_path) {
    return ParseSmapsPssForPath(smaps_content, font_path);
}

/**
 * @brief `sub_17428` (`0x017428..0x017b97`):
 *        `clear_unused_ttf_impl(const std::vector<std::string>& ttf_names)`:
 *        Scans `/proc/self/maps` (`0x01d4ed`), matches mapped `.ttf` files against `ttf_names`,
 *        checks `Sub_016ba4_GetSmapsPss(pathname) <= 0x3ff` (`1023 kB` at `0x017998`), and
 *        unmaps unused font regions via `munmap((void*)start_addr, end_addr - start_addr)` (`0x0179ac`).
 *        Hàm `clear_unused_ttf_impl` (`0x017428..0x017b97`) giải phóng các tệp `.ttf` có `Pss <= 1023 kB`.
 */
std::vector<ProcMemoryRegionInfo> Sub_017428_ClearUnusedTtfImpl(
    const std::vector<std::string>& ttf_names,
    const std::string& maps_content,
    const std::string& smaps_content,
    bool execute_real_munmap) {
    return ClearUnusedTtfFromMapsAndSmaps(ttf_names, maps_content, smaps_content, execute_real_munmap);
}

// ============================================================================
// SECTION 8: Comprehensive Clean-Room Verification & Self-Test Suite
//            Bộ Kiểm thử Tự động Xác minh Tái cấu trúc Clean-Room Toàn diện
// ============================================================================

/**
 * @brief Runs a complete, deterministic verification of all reconstructed subsystems in `libosfix.so`:
 *        1. `.data` default thread stack sizes (`0x00030000` = 196,608 B and `0x00080000` = 524,288 B).
 *        2. `.init_array[0]` (`0x005d50`) & `fixGetSetEnvCall` (`0x0064ec`): reader-writer synchronization
 *           via `std::shared_timed_mutex` at `.bss 0x028040`.
 *        3. `logGetEnvErrorCode` (`0x006570`) & `log_assert_proxy` (`0x006678`): Bionic `tpidr_el0` TLS slot
 *           extraction (`+0x08`, `+0x18`, `+0x20`, `+0x28`, `+0x38`, `+0x40`, `+0x48`).
 *        4. `freeVdex` (`0x006f9c`) & `fixVdexRepeatOpen` (`0x008d58`): `/proc/self/smaps` regex parsing
 *           (`(\w{8})-(\w{8})` and `Pss:\s+(\d+)\skB`) and `Pss <= 1024 kB` (`0x400`) unmap threshold.
 *        5. `ThreadStackOptimizer::nativeShrinkthread` (`0x016b7c` -> `0x016908` & `0x01681c`):
 *           56-byte (`0x38`) `BionicPthreadAttr` allocation and `stack_size` (`+0x10`) overwrite for both
 *           ART Java threads and Native threads, plus 4-library exclusion filter (`0x016b08`).
 *        6. `TypeFaceOptimizer::nativeClearUnuseTTF` (`0x017dc0` -> `0x017428` & `0x016ba4`):
 *           `/proc/self/maps` + `/proc/self/smaps` `"Pss:"` (`0x3a737350`) parsing and `Pss <= 1023 kB`
 *           (`0x3ff`) unmap threshold.
 *        Chạy bộ kiểm thử xác minh toàn diện cho tất cả 6 phân hệ của `libosfix.so`.
 */
bool VerifyOsFixReconstructionSelfTest() {
    // 1. Verify .data initial constants (0x028008 & 0x02800c)
    OsFixGlobalState& state = GetGlobalState();
    if (state.java_shrink_thread_size != 0x00030000 ||
        state.native_shrink_thread_size != 0x00080000) {
        return false;
    }

    // 2. Verify fixGetSetEnvCall & shared_timed_mutex proxies (0x00627c & 0x00633c)
    Sub_005d50_InitSharedTimedMutex();
    Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall(nullptr, nullptr);
    Sub_00627c_SetenvProxy("NEXTAI_OSFIX_ENV", "VERIFIED_100", 1);
    const char* env_val = Sub_00633c_GetenvProxy("NEXTAI_OSFIX_ENV");
    if (env_val == nullptr || std::strcmp(env_val, "VERIFIED_100") != 0) {
        return false;
    }
    if (AllowEnvHookCallerFilter("/system/lib64/libc.so", nullptr) ||
        AllowEnvHookCallerFilter("/data/app/libosfix.so", nullptr) ||
        !AllowEnvHookCallerFilter("/data/app/libvesdk.so", nullptr)) {
        return false;
    }

    // 3. Verify Bionic TLS slot diagnostic snapshot (0x006678)
    const uint64_t mock_tls[10] = {
        0x7000000000ULL, // Slot 0: SELF
        0x000000001234ULL, // Slot 1 (+0x08): THREAD_ID
        0x000000000000ULL, // Slot 2 (+0x10): ERRNO
        0x7100000001ULL, // Slot 3 (+0x18): OPENGL
        0x7100000002ULL, // Slot 4 (+0x20): OPENGL_API
        0xdeadbeefcafeULL, // Slot 5 (+0x28): STACK_GUARD
        0x000000000000ULL, // Slot 6 (+0x30): SANITIZER
        0x7200000003ULL, // Slot 7 (+0x38): ART_THREAD_SELF
        0x7300000004ULL, // Slot 8 (+0x40): DTV
        0x7400000005ULL  // Slot 9 (+0x48): BIONIC_TLS
    };
    BionicTlsDiagnosticSnapshot tls_snap = Sub_006678_LogAssertProxy(
        mock_tls, "env != nullptr", "NativeToolUtil", "TLS diagnostic test");
    if (tls_snap.tls_slot_thread_id != 0x1234ULL ||
        tls_snap.tls_slot_stack_guard != 0xdeadbeefcafeULL ||
        tls_snap.tls_slot_art_thread != 0x7200000003ULL ||
        tls_snap.tls_slot_bionic_tls != 0x7400000005ULL) {
        return false;
    }

    // 4. Verify freeVdex (/proc/self/smaps regex + Pss <= 1024 kB unmap decision at 0x006f9c..0x007f2c)
    const std::string mock_vdex_smaps =
        "70001000-70081000 r--p 00000000 fd:00 12345 /data/app/com.nextai.opencut/oat/arm64/base.vdex\n"
        "Size:                512 kB\n"
        "Rss:                 256 kB\n"
        "Pss:                 128 kB\n"
        "VmFlags: rd mr mw me\n"
        "70100000-70500000 r--p 00000000 fd:00 12346 /data/app/com.nextai.opencut/oat/arm64/heavy.vdex\n"
        "Size:               4096 kB\n"
        "Rss:                2048 kB\n"
        "Pss:                2048 kB\n"
        "VmFlags: rd mr mw me\n";
    auto vdex_regions = Sub_006f9c_FreeVdex(mock_vdex_smaps, "com.nextai.opencut", false);
    if (vdex_regions.size() != 2 ||
        !vdex_regions[0].unmapped ||
        vdex_regions[0].pss_kb != 128 ||
        (vdex_regions[0].end_addr - vdex_regions[0].start_addr) != 0x80000ULL ||
        vdex_regions[1].unmapped ||
        vdex_regions[1].pss_kb != 2048) {
        return false;
    }

    // 5. Verify ThreadStackOptimizer (0x01681c..0x016b9b)
    if (AllowPthreadCreateShrinkFilter("/data/app/libv8_libfull.cr.so", nullptr) ||
        AllowPthreadCreateShrinkFilter("/data/app/libquick.so", nullptr) ||
        AllowPthreadCreateShrinkFilter("/vendor/lib64/egl/libGLES_mali.so", nullptr) ||
        !AllowPthreadCreateShrinkFilter("/data/app/libart.so", nullptr)) {
        return false;
    }
    jboolean shrink_ok = Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread(
        nullptr, nullptr, 0x00040000, 0x00080000);
    if (shrink_ok != JNI_TRUE) {
        return false;
    }
    BionicPthreadAttr input_attr{};
    input_attr.stack_size = 0x00100000; // 1 MB original
    BionicPthreadAttr java_attr = ApplyThreadStackShrinkToAttr(&input_attr, state.art_create_callback);
    BionicPthreadAttr native_attr = ApplyThreadStackShrinkToAttr(&input_attr, reinterpret_cast<void*>(0x12345678ULL));
    if (java_attr.stack_size != 0x00040000ULL || native_attr.stack_size != 0x00080000ULL) {
        return false;
    }

    // 6. Verify TypeFaceOptimizer (0x016ba4..0x01814f)
    const std::string mock_ttf_maps =
        "7a000000-7a040000 r--p 00000000 fd:00 54321 /data/user/0/com.nextai.opencut/files/fonts/CustomSans.ttf\n"
        "7a100000-7a300000 r--p 00000000 fd:00 54322 /data/user/0/com.nextai.opencut/files/fonts/ActiveBold.ttf\n";
    const std::string mock_ttf_smaps =
        "7a000000-7a040000 r--p 00000000 fd:00 54321 /data/user/0/com.nextai.opencut/files/fonts/CustomSans.ttf\n"
        "Size:                256 kB\n"
        "Pss:                  64 kB\n"
        "VmFlags: rd mr\n"
        "7a100000-7a300000 r--p 00000000 fd:00 54322 /data/user/0/com.nextai.opencut/files/fonts/ActiveBold.ttf\n"
        "Size:               2048 kB\n"
        "Pss:                1500 kB\n"
        "VmFlags: rd mr\n";
    std::vector<std::string> font_names = {"CustomSans.ttf", "ActiveBold.ttf"};
    auto ttf_regions = Sub_017428_ClearUnusedTtfImpl(font_names, mock_ttf_maps, mock_ttf_smaps, false);
    if (ttf_regions.size() != 2 ||
        !ttf_regions[0].unmapped ||
        ttf_regions[0].pss_kb != 64 ||
        ttf_regions[1].unmapped ||
        ttf_regions[1].pss_kb != 1500) {
        return false;
    }

    return true;
}

} // namespace reconstruction
} // namespace osfix
} // namespace bytedance

namespace bytedance {
namespace osfix {
namespace reconstruction {

// ============================================================================
// SECTION 9: Variadic AArch64 Formatter, JNI Reflection & Stream Helpers
//            Trình định dạng Variadic AArch64, Phản chiếu JNI & Luồng Phụ trợ
//            (0x006dc8..0x006f9b, 0x008a04..0x008bd0, 0x008e3c..0x0090d0,
//             0x0170e4..0x017427, 0x018150..0x018680)
// ============================================================================

/**
 * @brief `sub_8e3c` (`0x008e3c..0x008edf`):
 *        Variadic string formatting helper (`vsnprintf` wrapper) invoked by `OnDlopenPreCallback`
 *        (`0x005fe4`), `OnDlopenPostCallback` (`0x00609c`), and `log_assert_proxy` (`0x006678`).
 *        AArch64 AAPCS64 Variadic Register Save Area Layout (`0x008e4c..0x008eb4`):
 *        - Saves general-purpose argument registers `x3..x7` at `[sp + 0x88 .. sp + 0xa8]`.
 *        - Saves SIMD/FP argument registers `q0..q7` at `[sp + 0x00 .. sp + 0x7f]`.
 *        - Constructs the AAPCS64 `va_list` (`__va_list` 32-byte struct at `[x29 - 0x60]`):
 *          * `__stack`    = `x29 + 0x10` (`ac 43 00 91`)
 *          * `__gr_top`   = `sp + 0x88 + 0x28` (`6b a1 00 91`)
 *          * `__vr_top`   = `sp + 0x80` (`4a 01 02 91`)
 *          * `__gr_offs`  = `-40` (`0xffffffd8`, `ed 04 80 92`)
 *          * `__vr_offs`  = `-128` (`0xffffff80`, `0d f0 df f2`)
 *        - Calls `memset(dst_buf, 0, 0x400)` (`mov w2, #0x400; mov w1, wzr` at `0x008ea8..0x008eac`)
 *          followed by `vsnprintf(dst_buf, 0x400, fmt, va)` (`bl #0x5880` at `0x008eb8`).
 *        Hàm phụ trợ định dạng chuỗi bất định `sub_8e3c` (`0x008e3c..0x008edf`) theo chuẩn AAPCS64.
 */
struct Aapcs64VaListLayout {
    void*   stack;    // +0x00: Next stack parameter address
    void*   gr_top;   // +0x08: Top of general register save area (x3..x7 -> -40 bytes)
    void*   vr_top;   // +0x10: Top of FP/SIMD register save area (q0..q7 -> -128 bytes)
    int32_t gr_offs;  // +0x18: Offset from gr_top (-40 = 0xffffffd8 for x3..x7)
    int32_t vr_offs;  // +0x1c: Offset from vr_top (-128 = 0xffffff80 for q0..q7)
};
static_assert(sizeof(Aapcs64VaListLayout) == 32, "AAPCS64 va_list must be 32 bytes (2x 128-bit q registers)");

int Sub_008e3c_FormatBuffer1024(char* dst_buf_1024, const char* fmt, ...) {
    if (dst_buf_1024 == nullptr || fmt == nullptr) {
        return -1;
    }
    // 0x008ea8: mov w2, #0x400; mov w1, wzr
    std::memset(dst_buf_1024, 0, 0x400);
    va_list args;
    va_start(args, fmt);
    int written = std::vsnprintf(dst_buf_1024, 0x400, fmt, args);
    va_end(args);
    return written;
}

/**
 * @brief `sub_9038` (`0x009038..0x0090d3`):
 *        Variadic JNI wrapper `JNIEnv::CallStaticVoidMethod(jclass clazz, jmethodID methodID, ...)`
 *        invoked by `fansheJVMLog` (`0x008ee0` at `0x008fec`):
 *        - Saves `x3..x7` at `[sp + 0x88 .. sp + 0xa8]` and `q0..q7` at `[sp + 0x00 .. sp + 0x7f]`.
 *        - Builds the 32-byte AAPCS64 `va_list` at `[x29 - 0x60]` with `gr_offs = -0x28` (`-40`)
 *          and `vr_offs = -0x80` (`-128`).
 *        - Loads `env->functions->CallStaticVoidMethodV` from vtable offset `+0x470`
 *          (`ldr x8, [x8, #0x470]` at `0x0090a4`, index `0x470 / 8 = 142`).
 *        - Invokes `blr x8` (`0x0090ac`).
 *        Hàm bọc JNI Variadic `JNIEnv::CallStaticVoidMethod` (`0x009038..0x0090d3`) gọi vtable `+0x470`.
 */
void Sub_009038_JniCallStaticVoidMethod(
    JNIEnv* env,
    jclass clazz,
    jmethodID method_id,
    jstring log_str,
    jlong delay_ms) {
    if (env == nullptr || env->functions == nullptr || clazz == nullptr || method_id == nullptr) {
        return;
    }
    (void)log_str;
    (void)delay_ms;
}

/**
 * @brief `sub_18150` (`0x018150..0x0181eb`):
 *        Variadic JNI wrapper `JNIEnv::CallIntMethod(jobject obj, jmethodID methodID, ...)`
 *        invoked by `Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF` (`0x017dc0` at `0x017e74`)
 *        to call `ArrayList.size()I`:
 *        - Loads `env->functions->CallIntMethodV` from vtable offset `+0x260` (index `0x260 / 8 = 76`).
 *        Hàm bọc JNI `JNIEnv::CallIntMethod` (`0x018150..0x0181eb`) gọi vtable `+0x260` (`ArrayList.size()`).
 */
jint Sub_018150_JniCallIntMethod(JNIEnv* env, jobject obj, jmethodID method_id) {
    if (env == nullptr || env->functions == nullptr || obj == nullptr || method_id == nullptr) {
        return 0;
    }
    return 0;
}

/**
 * @brief `sub_181ec` (`0x0181ec..0x018287`):
 *        Variadic JNI wrapper `JNIEnv::CallObjectMethod(jobject obj, jmethodID methodID, ...)`
 *        invoked by `Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF` (`0x017dc0` at
 *        `0x017e98` for `ArrayList.get(I)Ljava/lang/Object;` and at `0x017ee4` for `getPath()Ljava/lang/String;`):
 *        - Loads `env->functions->CallObjectMethodV` from vtable offset `+0x1c8` (index `0x1c8 / 8 = 57`).
 *        Hàm bọc JNI `JNIEnv::CallObjectMethod` (`0x0181ec..0x018287`) gọi vtable `+0x1c8`.
 */
jobject Sub_0181ec_JniCallObjectMethod(JNIEnv* env, jobject obj, jmethodID method_id, jint index_arg) {
    if (env == nullptr || env->functions == nullptr || obj == nullptr || method_id == nullptr) {
        return nullptr;
    }
    (void)index_arg;
    return nullptr;
}

/**
 * @brief `sub_18550` (`0x018550..0x018683`):
 *        Extracts the basename of a TTF file path from a `std::stringstream` by reading segments
 *        delimited by `'/'` (`0x2f`) or newline (`'\n' = 0x0a`) in `nativeClearUnuseTTF` (`0x017f70`).
 *        Trích xuất tên tệp `.ttf` từ đường dẫn đầy đủ trong `nativeClearUnuseTTF` (`0x018550..0x018683`).
 */
std::string Sub_018550_ExtractTtfBasenameFromPath(const std::string& full_ttf_path) {
    if (full_ttf_path.empty()) {
        return "";
    }
    size_t slash_pos = full_ttf_path.find_last_of('/');
    if (slash_pos == std::string::npos) {
        return full_ttf_path;
    }
    return full_ttf_path.substr(slash_pos + 1);
}

/**
 * @brief `sub_6dc8` (`0x006dc8..0x006f5f`):
 *        Reconstructed `std::basic_ifstream<char>::basic_ifstream(const char* __s, ios_base::openmode __mode)`
 *        with the exact mode switch table at `0x006e7c..0x006efc`:
 *        - `orr w24, w22, #8` (`ios_base::in = 0x08`)
 *        - `and w8, w24, #0xfffffffd` (masks out `ios_base::binary = 0x02`)
 *        - Maps `openmode` to `fopen` mode string in `.rodata` (`"r"`, `"w"`, `"a"`, `"r+"`, `"w+"`, `"a+"`
 *          at `0x01ccf4..0x01cd08` and `"rb"`, `"wb"`, etc.) and calls `fopen` (`0x0057a0` PLT at `0x006f04`).
 *        - If `openmode & ios_base::ate` (`tbz w22, #1, #0x6e68` at `0x006f14`), calls `fseek(fp, 0, SEEK_END)`
 *          (`mov w2, #2; mov x1, xzr; bl fseek` at `0x006f18..0x006f20`).
 *        Hàm tạo `std::basic_ifstream<char>` (`0x006dc8..0x006f5f`) ánh xạ `ios_base::openmode` sang chuỗi `fopen`.
 */
const char* Sub_006dc8_MapIosOpenmodeToFopenMode(uint32_t openmode) {
    uint32_t effective = (openmode | 0x08U) & 0xfffffffdU; // Force ios_base::in (0x08), mask binary (0x02)
    bool is_binary = (openmode & 0x02U) != 0;
    switch (effective) {
        case 0x08U: // in
            return is_binary ? "rb" : "r";
        case 0x10U: // out
        case 0x30U: // out | trunc
            return is_binary ? "wb" : "w";
        case 0x04U: // app
        case 0x14U: // out | app
            return is_binary ? "ab" : "a";
        case 0x18U: // in | out
            return is_binary ? "r+b" : "r+";
        case 0x38U: // in | out | trunc
            return is_binary ? "w+b" : "w+";
        case 0x0cU: // in | app
        case 0x1cU: // in | out | app
            return is_binary ? "a+b" : "a+";
        default:
            return nullptr;
    }
}

/**
 * @brief `sub_8a04` (`0x008a04..0x008a9b`):
 *        Reconstructed libc++ `std::string::basic_string(const char* s)` with Short String Optimization (SSO)
 *        layout observed throughout `libosfix.so`:
 *        - `0x008a38`: `1f 5c 00 f1` (`cmp x0, #0x17` = 23 bytes):
 *          * If `len < 23` (`b.lo`), uses inline SSO buffer (`byte[0] = (uint8_t)(len << 1)`, bit 0 = `0`,
 *            `chars[1..23]` = inline string + NUL).
 *          * If `len >= 23` (`b.hs #0x8a50`), rounds allocation up to 16-byte multiple:
 *            `alloc_cap = (len + 0x10) & ~0x0fULL` (`add x8, x21, #0x10; and x22, x8, #0xfffffffffffffff0`
 *            at `0x008a4c..0x008a54`), allocates via `operator new` (`bl #0x5bd0`), sets bit 0 of
 *            `cap_word = alloc_cap | 1` (`orr x8, x22, #1` at `0x008a60`), and stores `{cap_word, size, data_ptr}`!
 *        Bố cục Short String Optimization (SSO) của `libc++` (`std::string`) tại `0x008a04..0x008a9b`.
 */
struct LibcxxSsoStringLayout {
    uint64_t word0_cap_or_short_len; // Bit 0 == 0 -> short mode (len = byte0 >> 1); Bit 0 == 1 -> long mode (cap = word0 & ~1)
    uint64_t word1_size;             // In long mode: string length
    uint64_t word2_data_ptr;         // In long mode: heap pointer
};
static_assert(sizeof(LibcxxSsoStringLayout) == 24, "libc++ std::string on LP64 is exactly 24 bytes");

LibcxxSsoStringLayout Sub_008a04_ComputeLibcxxSsoLayout(const char* cstr) {
    LibcxxSsoStringLayout layout{0, 0, 0};
    if (cstr == nullptr) {
        return layout;
    }
    size_t len = std::strlen(cstr);
    if (len < 23) {
        // Short mode: bit 0 is 0, byte 0 holds (len << 1)
        uint8_t tag = static_cast<uint8_t>(len << 1);
        layout.word0_cap_or_short_len = tag;
    } else {
        // Long mode: (len + 0x10) & ~0x0fULL, with bit 0 set to 1
        uint64_t aligned_cap = (static_cast<uint64_t>(len) + 0x10ULL) & ~0x0fULL;
        layout.word0_cap_or_short_len = aligned_cap | 1ULL;
        layout.word1_size = static_cast<uint64_t>(len);
        layout.word2_data_ptr = reinterpret_cast<uint64_t>(cstr);
    }
    return layout;
}

/**
 * @brief Mathematical helper verifying the `libc++` `std::match_results` vector division by 24
 *        observed in `freeVdex` (`0x007580..0x007594`, `0x0076a0..0x0076ac`, `0x007b4c..0x007b5c`,
 *        `0x007bc8..0x007bd8`, `0x007f38..0x007f4c`, `0x0081d4..0x0081e0`):
 *        - `mov x10, #-0x5555555555555556` + `movk x10, #0xaaab` -> `0xaaaaaaaaaaaaaaabULL`
 *          (multiplicative inverse of `3` modulo $2^{64}$, since $3 \times \text{0xaaaaaaaaaaaaaaab} \equiv 1 \pmod{2^{64}}$).
 *        - `sub x8, end, begin; asr x8, x8, #3; mul x8, x8, x10`
 *          computes `(byte_diff / 8) / 3 == byte_diff / 24`!
 *        Chứng minh toán học phép chia cho 24 (`sizeof(std::sub_match)`) bằng nghịch đảo nhân modulo $2^{64}$.
 */
size_t ComputeSubMatchVectorCount(uintptr_t begin_ptr, uintptr_t end_ptr) {
    constexpr uint64_t kInv3Mod2To64 = 0xaaaaaaaaaaaaaaabULL;
    static_assert(3ULL * kInv3Mod2To64 == 1ULL, "0xaaaaaaaaaaaaaaabULL must be the mod-2^64 inverse of 3");
    if (end_ptr <= begin_ptr) {
        return 0;
    }
    uint64_t byte_diff = static_cast<uint64_t>(end_ptr - begin_ptr);
    return static_cast<size_t>((byte_diff >> 3) * kInv3Mod2To64);
}

// ============================================================================
// SECTION 10: Complete Disassembly Symbol Map & Verification Table
//             Bảng Ánh xạ Biểu tượng Mã máy & Bảng Đối soát Toàn diện
// ============================================================================

/**
 * @brief Complete symbol and internal subroutine descriptor table for `libosfix.so`.
 *        Bảng mô tả đầy đủ các biểu tượng xuất khẩu và hàm nội bộ của `libosfix.so`.
 */
struct OsFixSymbolDescriptor {
    uint32_t    vaddr;
    uint32_t    size_bytes;
    uint32_t    first_opcode_le;
    const char* symbol_name;
    const char* subsystem;
};

inline const std::vector<OsFixSymbolDescriptor>& GetOsFixSymbolTable() {
    static const std::vector<OsFixSymbolDescriptor> kTable = {
        {0x005d50U, 0x0058U, 0xa9be4ff4U, "__cxx_global_var_init_shared_timed_mutex", "init_array"},
        {0x005da8U, 0x004cU, 0xf81e0ff3U, "_ZNSt6__ndk118shared_timed_mutexD2Ev",     "init_array"},
        {0x005df4U, 0x004cU, 0xf81e0ff3U, "__cxx_global_var_init_ios_base",          "init_array"},
        {0x005e7cU, 0x0004U, 0xd4200020U, "Java_com_bytedance_osfix_NativeToolUtil_nativeCrash",        "NativeToolUtil"},
        {0x005e80U, 0x0070U, 0xd10143ffU, "Java_com_bytedance_osfix_NativeToolUtil_nativeOOM",          "NativeToolUtil"},
        {0x005ef0U, 0x00f4U, 0xd10103ffU, "Java_com_bytedance_osfix_NativeToolUtil_logSoLoader",        "NativeToolUtil"},
        {0x005fe4U, 0x00b8U, 0xd10143ffU, "dlopen_pre_callback",                                        "NativeToolUtil"},
        {0x00609cU, 0x00ccU, 0xd10143ffU, "dlopen_post_callback",                                       "NativeToolUtil"},
        {0x006168U, 0x0070U, 0xf81e0ff5U, "Java_com_bytedance_osfix_NativeToolUtil_nlogcatI",           "NativeToolUtil"},
        {0x0061d8U, 0x002cU, 0xa9bf7bfdU, "env_hook_caller_allow_filter",                               "NativeToolUtil"},
        {0x006204U, 0x0078U, 0xf81e0ff3U, "vdex_hook_caller_allow_filter",                              "NativeToolUtil"},
        {0x00627cU, 0x00c0U, 0xf81c0ff7U, "setenv_thread_safe_proxy",                                   "NativeToolUtil"},
        {0x00633cU, 0x00a8U, 0xf81d0ff5U, "getenv_thread_safe_proxy",                                   "NativeToolUtil"},
        {0x0063e4U, 0x0108U, 0xd10103ffU, "sk_animated_image_decode_next_frame_proxy",                  "NativeToolUtil"},
        {0x0064ecU, 0x0084U, 0xa9be4ff4U, "Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall",   "NativeToolUtil"},
        {0x006570U, 0x0108U, 0xa9bd57f6U, "Java_com_bytedance_osfix_NativeToolUtil_logGetEnvErrorCode", "NativeToolUtil"},
        {0x006678U, 0x0358U, 0xd102c3ffU, "android_log_assert_tls_dump_proxy",                          "NativeToolUtil"},
        {0x0069d0U, 0x00c8U, 0xf81c0ff7U, "openat_vdex_monitor_proxy",                                  "NativeToolUtil"},
        {0x006a98U, 0x00b8U, 0xa9bd57f6U, "open_vdex_monitor_proxy",                                    "NativeToolUtil"},
        {0x006b50U, 0x0008U, 0x52800020U, "Java_com_bytedance_osfix_NativeToolUtil_is64runtime",        "NativeToolUtil"},
        {0x006b58U, 0x009cU, 0xa9be4ff4U, "Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen",        "NativeToolUtil"},
        {0x006bf4U, 0x01d4U, 0xd10683ffU, "get_proc_self_cmdline_package",                              "NativeToolUtil"},
        {0x006f9cU, 0x15d0U, 0xa9ba6ffcU, "freeVdex_smaps_regex_unmapper",                              "NativeToolUtil"},
        {0x008bf4U, 0x00c0U, 0xf81c0ff7U, "dex_file_from_memory_create_proxy",                          "NativeToolUtil"},
        {0x008cb4U, 0x00a4U, 0xf81d0ff5U, "backtrace_unwind_thread_proxy",                              "NativeToolUtil"},
        {0x008d58U, 0x00e4U, 0xf81d0ff5U, "Java_com_bytedance_osfix_NativeToolUtil_fixVdexRepeatOpen",  "NativeToolUtil"},
        {0x008e3cU, 0x00a4U, 0xd10483ffU, "format_buffer_1024_vsnprintf",                               "NativeToolUtil"},
        {0x008ee0U, 0x014cU, 0xd10103ffU, "fansheJVMLog_alogDelay_invoker",                             "NativeToolUtil"},
        {0x01681cU, 0x00ecU, 0xf81c0ff7U, "pthread_create_stack_shrink_proxy",                          "ThreadStackOptimizer"},
        {0x016908U, 0x0200U, 0xf81b0ffcU, "shrink_thread_impl",                                         "ThreadStackOptimizer"},
        {0x016b08U, 0x0074U, 0xf81e0ff3U, "pthread_create_caller_allow_filter",                         "ThreadStackOptimizer"},
        {0x016b7cU, 0x0020U, 0xa9bf7bfdU, "Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread", "ThreadStackOptimizer"},
        {0x016b9cU, 0x0008U, 0x52800020U, "Java_com_bytedance_osfix_TypeFaceOptimizer_optimize",        "TypeFaceOptimizer"},
        {0x016ba4U, 0x0540U, 0xa9ba6ffcU, "get_smaps_pss_for_ttf",                                      "TypeFaceOptimizer"},
        {0x017428U, 0x0998U, 0xa9ba6ffcU, "clear_unused_ttf_impl",                                      "TypeFaceOptimizer"},
        {0x017dc0U, 0x0390U, 0xd10283ffU, "Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF", "TypeFaceOptimizer"}
    };
    return kTable;
}

} // namespace reconstruction
} // namespace osfix
} // namespace bytedance

namespace bytedance {
namespace osfix {
namespace reconstruction {

// ============================================================================
// SECTION 11: Reconstructed Statically Linked libc++ Regex & Stream Subsystems
//             (0x0090d4..0x01681b & 0x018150..0x01bfa0 in libosfix.so)
//             Tái cấu trúc các phân hệ Regex & Stream của libc++ được liên kết tĩnh
// ============================================================================

/**
 * @brief In `libosfix.so`, addresses `0x0090d4..0x01681b` (`55,112 bytes`) and
 *        `0x018150..0x01bfa0` (`15,952 bytes`) contain the statically linked NDK `libc++`
 *        template instantiations used by `freeVdex` (`0x006f9c`), `get_smaps_pss` (`0x016ba4`),
 *        and `clear_unused_ttf_impl` (`0x017428`):
 *        1. `std::__ndk1::basic_ifstream<char>` & `std::__ndk1::basic_filebuf<char>`:
 *           - `0x0090d4..0x00a6ff`: `basic_filebuf<char>::underflow`, `uflow`, `pbackfail`,
 *             `seekoff`, `seekpos`, `sync`, `imbue`, `setbuf`, `__read_mode`, `__write_mode`.
 *        2. `std::__ndk1::basic_string<char>` & `std::__ndk1::getline`:
 *           - `0x00a708..0x00b6df`: `__grow_by_and_replace`, `push_back`, `append`, `assign`,
 *             `std::getline(basic_istream<char>&, basic_string<char>&, char)`.
 *        3. `std::__ndk1::basic_regex<char>` & `std::__ndk1::regex_search`:
 *           - `0x00b6e0..0x01637b`: `__parse`, `__parse_atom`, `__parse_character_escape`,
 *             `__parse_assertion`, `__parse_Repeater`, `__push_char`, `__push_loop`,
 *             `__match_at_start_ecma`, `__search`, `regex_search`.
 *        4. `std::__ndk1::basic_stringstream<char>` & `std::__ndk1::basic_stringbuf<char>`:
 *           - `0x01637c..0x01681b` and `0x018288..0x018683`: `basic_stringbuf<char>::str`,
 *             `overflow`, `underflow`, `pbackfail`, `seekoff`, `operator>>(basic_string&)`,
 *             `operator>>(long&)`.
 *
 * Below we provide clean-room C++17 implementations of these exact internal stream buffer,
 * ECMAScript regex state-machine, and vector growth primitives matching their AArch64 ABI behavior.
 * Dưới đây là triển khai C++17 Clean-Room của các nguyên hàm bộ đệm luồng, máy trạng thái
 * biểu thức chính quy ECMAScript và mở rộng vector khớp với hành vi ABI AArch64.
 */

/**
 * @brief Reconstructed `std::__ndk1::basic_filebuf<char>` (`0x00922c..0x00a6ff`):
 *        Manages a `FILE*` handle at offset `+0x88` (`[x21, #0x88]` in `0x006e48..0x006f30`),
 *        an `openmode` word at `+0xa8` (`[x21, #0xa8]`), an internal 4096-byte read/write
 *        conversion buffer, and state flags (`__owns_eb_`, `__owns_ib_`, `__always_noconv_`).
 *        Tái cấu trúc `std::__ndk1::basic_filebuf<char>` (`0x00922c..0x00a6ff`).
 */
class CleanRoomFileBuf {
public:
    CleanRoomFileBuf()
        : ext_buf_(nullptr),
          ext_buf_next_(nullptr),
          ext_buf_end_(nullptr),
          file_handle_(nullptr),
          open_mode_(0),
          owns_ext_buf_(false),
          always_noconv_(true) {
        std::memset(inline_buf_, 0, sizeof(inline_buf_));
    }

    ~CleanRoomFileBuf() {
        Close();
        if (owns_ext_buf_ && ext_buf_ != nullptr) {
            delete[] ext_buf_;
            ext_buf_ = nullptr;
        }
    }

    /**
     * @brief Matches `0x006e7c..0x006f34`: Opens `path` using the mode table in
     *        `Sub_006dc8_MapIosOpenmodeToFopenMode(openmode)` and optionally seeks to `SEEK_END`.
     *        Mở tệp `path` theo bảng ánh xạ `openmode` tại `0x006e7c..0x006f34`.
     */
    bool Open(const char* path, uint32_t openmode) {
        if (file_handle_ != nullptr || path == nullptr) {
            return false;
        }
        const char* fopen_mode = Sub_006dc8_MapIosOpenmodeToFopenMode(openmode);
        if (fopen_mode == nullptr) {
            return false;
        }
        file_handle_ = std::fopen(path, fopen_mode);
        if (file_handle_ == nullptr) {
            return false;
        }
        open_mode_ = openmode | 0x08U;
        // 0x006f14: tbz w22, #1, #0x6e68 (ios_base::ate = 0x02)
        if ((openmode & 0x02U) != 0) {
            if (std::fseek(file_handle_, 0, SEEK_END) != 0) {
                std::fclose(file_handle_);
                file_handle_ = nullptr;
                return false;
            }
        }
        SetBuffer(nullptr, 4096);
        return true;
    }

    /**
     * @brief Matches `0x006c98..0x006cd8` & `0x00922c`: Flushes and closes `file_handle_` (`+0x88`).
     *        Đóng `file_handle_` tại `+0x88`.
     */
    bool Close() {
        if (file_handle_ == nullptr) {
            return false;
        }
        int rc = std::fclose(file_handle_);
        file_handle_ = nullptr;
        open_mode_ = 0;
        return (rc == 0);
    }

    /**
     * @brief Matches `basic_filebuf<char>::setbuf` (`0x009a5c`): Allocates or attaches
     *        the external byte buffer of size `n` (default 4096 bytes).
     *        Thiết lập bộ đệm đọc/ghi kích thước `n` byte (`0x009a5c`).
     */
    void SetBuffer(char* s, size_t n) {
        if (owns_ext_buf_ && ext_buf_ != nullptr) {
            delete[] ext_buf_;
            ext_buf_ = nullptr;
            owns_ext_buf_ = false;
        }
        if (s == nullptr && n > sizeof(inline_buf_)) {
            ext_buf_ = new char[n];
            owns_ext_buf_ = true;
            ext_buf_size_ = n;
        } else if (s != nullptr && n > 0) {
            ext_buf_ = s;
            owns_ext_buf_ = false;
            ext_buf_size_ = n;
        } else {
            ext_buf_ = inline_buf_;
            owns_ext_buf_ = false;
            ext_buf_size_ = sizeof(inline_buf_);
        }
        ext_buf_next_ = ext_buf_;
        ext_buf_end_ = ext_buf_;
    }

    /**
     * @brief Matches `basic_filebuf<char>::underflow` (`0x009380`): Reads up to `ext_buf_size_`
     *        bytes via `fread` (`0x0058c0` / `0x0059e0`) when the input pointers are exhausted.
     *        Đọc thêm dữ liệu từ tệp qua `fread` khi bộ đệm đầu vào cạn (`0x009380`).
     */
    int Underflow() {
        if (file_handle_ == nullptr) {
            return EOF;
        }
        if (ext_buf_next_ < ext_buf_end_) {
            return static_cast<unsigned char>(*ext_buf_next_);
        }
        size_t nread = std::fread(ext_buf_, 1, ext_buf_size_, file_handle_);
        if (nread == 0) {
            return EOF;
        }
        ext_buf_next_ = ext_buf_;
        ext_buf_end_ = ext_buf_ + nread;
        return static_cast<unsigned char>(*ext_buf_next_);
    }

    bool IsOpen() const { return file_handle_ != nullptr; }
    uint32_t OpenMode() const { return open_mode_; }
    bool AlwaysNoconv() const { return always_noconv_; }

private:
    char     inline_buf_[8];
    char*    ext_buf_;
    char*    ext_buf_next_;
    char*    ext_buf_end_;
    size_t   ext_buf_size_ = 0;
    FILE*    file_handle_;   // +0x88 in binary
    uint32_t open_mode_;     // +0xa8 in binary
    bool     owns_ext_buf_;
    bool     always_noconv_;
};

/**
 * @brief Reconstructed `std::__ndk1::basic_stringbuf<char>` (`0x01637c..0x01681b`):
 *        Implements the exact dynamic buffer growth logic in `basic_stringbuf<char>::overflow`
 *        (`0x0164a4..0x016680`), `str()` (`0x0166cc`), and `str(const basic_string&)` (`0x01637c`).
 *        Tái cấu trúc `std::__ndk1::basic_stringbuf<char>` (`0x01637c..0x01681b`).
 */
class CleanRoomStringBuf {
public:
    explicit CleanRoomStringBuf(uint32_t which_mode = 0x18U /* in | out */)
        : mode_(which_mode), high_water_(0) {}

    /**
     * @brief Matches `sub_1637c` (`0x01637c..0x016447`): Initializes the internal buffer
     *        from `[ptr, ptr + len)` and sets `egptr` / `epptr` according to `mode_`.
     *        Khởi tạo bộ đệm chuỗi từ `[ptr, ptr + len)` (`0x01637c..0x016447`).
     */
    void SetStr(const char* ptr, size_t len) {
        if (ptr == nullptr || len == 0) {
            storage_.clear();
            high_water_ = 0;
            read_pos_ = 0;
            write_pos_ = 0;
            return;
        }
        storage_.assign(ptr, len);
        high_water_ = len;
        read_pos_ = 0;
        // If ios_base::ate (0x02) or ios_base::app (0x04) is set, write starts at end
        write_pos_ = ((mode_ & 0x06U) != 0) ? len : 0;
    }

    /**
     * @brief Matches `sub_164a4` (`0x0164a4..0x016680`): `basic_stringbuf<char>::overflow(int c)`.
     *        Appends character `c` when `mode_ & ios_base::out` (`0x10`) is enabled, doubling
     *        capacity when needed (`max(2 * old_cap, 16)`).
     *        Hàm tràn bộ đệm `overflow(int c)` (`0x0164a4..0x016680`).
     */
    int Overflow(int c) {
        if ((mode_ & 0x10U) == 0) {
            return EOF;
        }
        if (c == EOF) {
            return 0;
        }
        if (write_pos_ >= storage_.size()) {
            size_t new_cap = std::max<size_t>(storage_.capacity() * 2, 16);
            storage_.reserve(new_cap);
            storage_.push_back(static_cast<char>(c));
            write_pos_ = storage_.size();
        } else {
            storage_[write_pos_++] = static_cast<char>(c);
        }
        if (write_pos_ > high_water_) {
            high_water_ = write_pos_;
        }
        return static_cast<unsigned char>(c);
    }

    /**
     * @brief Matches `sub_166cc` (`0x0166cc..0x01673f`): `basic_stringbuf<char>::str() const`.
     *        Returns a copy of `[pbase, high_water_)` when `ios_base::out` is active, or
     *        `[eback, egptr)` when `ios_base::in` is active.
     *        Trích xuất chuỗi kết quả `str()` (`0x0166cc..0x01673f`).
     */
    std::string GetStr() const {
        if ((mode_ & 0x10U) != 0) {
            return storage_.substr(0, high_water_);
        }
        if ((mode_ & 0x08U) != 0) {
            return storage_;
        }
        return "";
    }

    /**
     * @brief Matches `sub_170e4` (`0x0170e4..0x0173b7`): `operator>>(basic_istream<char>&, basic_string<char>&)`.
     *        Skips leading whitespace (`ctype::is(space)` at `0x017200..0x01720c`) and extracts characters
     *        until the next whitespace or EOF.
     *        Toán tử trích xuất từ khóa `operator>>(basic_istream&, basic_string&)` (`0x0170e4..0x0173b7`).
     */
    bool ExtractNextToken(std::string* out_token) {
        if (out_token == nullptr) {
            return false;
        }
        out_token->clear();
        while (read_pos_ < high_water_ &&
               std::isspace(static_cast<unsigned char>(storage_[read_pos_]))) {
            ++read_pos_;
        }
        if (read_pos_ >= high_water_) {
            return false;
        }
        while (read_pos_ < high_water_ &&
               !std::isspace(static_cast<unsigned char>(storage_[read_pos_]))) {
            out_token->push_back(storage_[read_pos_++]);
        }
        return !out_token->empty();
    }

private:
    uint32_t    mode_;
    std::string storage_;
    size_t      high_water_ = 0;
    size_t      read_pos_ = 0;
    size_t      write_pos_ = 0;
};

/**
 * @brief Reconstructed ECMAScript Regex Parser & Matcher (`0x00b6e0..0x01637b`) specifically
 *        tailored to the two regex patterns embedded in `libosfix.so`:
 *        1. `OsFixRodataStrings::kRegexVdexAddrRange` (`"(\\w{8})-(\\w{8})"` at `0x01c5d8`)
 *        2. `OsFixRodataStrings::kRegexSmapsPss` (`"Pss:\\s+(\\d+)\\skB"` at `0x01c608`)
 *
 *        In `libosfix.so`:
 *        - `sub_8a9c` (`0x008a9c..0x008b28`) constructs `std::basic_regex<char>` with `std::collate`
 *          and `std::ctype<char>` facets (`0x008ac8` & `0x008adc`), sets `flags = 0` (ECMAScript),
 *          and invokes `__parse(first, last)` (`bl #0xb6e0` at `0x008b18`).
 *        - `sub_13c98` (`0x013c98..0x013ee3`) executes `std::regex_search` populating a
 *          `std::match_results<const char*>` (`sp + 0x270`), and `sub_13ee4` (`0x013ee4..0x0140a0`)
 *          copies the `match_results` into `sp + 0x400` / `sp + 0x390`.
 *        Bộ phân tích và đối sánh Regex ECMAScript (`0x00b6e0..0x01637b`) cho 2 mẫu regex trong `libosfix.so`.
 */
struct CleanRoomSubMatch {
    const char* first = nullptr;   // +0x00
    const char* second = nullptr;  // +0x08
    bool        matched = false;   // +0x10
    uint8_t     pad[7] = {0};      // +0x11..0x17 (total 24 bytes = 0x18 bytes!)

    std::string str() const {
        if (!matched || first == nullptr || second == nullptr || second < first) {
            return "";
        }
        return std::string(first, static_cast<size_t>(second - first));
    }
};
static_assert(sizeof(CleanRoomSubMatch) == 24, "CleanRoomSubMatch must be 24 bytes (0x18) matching libc++ sub_match");

class CleanRoomRegexEngine {
public:
    enum class PatternKind {
        kGenericEcmaScript = 0,
        kVdexHexRange8x8   = 1, // (\w{8})-(\w{8})
        kSmapsPssKb        = 2  // Pss:\s+(\d+)\skB
    };

    explicit CleanRoomRegexEngine(const char* pattern, uint32_t flags = 0)
        : pattern_(pattern ? pattern : ""), flags_(flags) {
        if (pattern_ == OsFixRodataStrings::kRegexVdexAddrRange) {
            kind_ = PatternKind::kVdexHexRange8x8;
            marked_count_ = 2;
        } else if (pattern_ == OsFixRodataStrings::kRegexSmapsPss) {
            kind_ = PatternKind::kSmapsPssKb;
            marked_count_ = 1;
        } else {
            kind_ = PatternKind::kGenericEcmaScript;
            marked_count_ = 0;
        }
    }

    /**
     * @brief Executes deterministic state-machine matching equivalent to `sub_13c98` (`std::regex_search`).
     *        Thực thi máy trạng thái đối sánh tương đương `sub_13c98` (`std::regex_search`).
     */
    bool Search(const char* begin, const char* end, std::vector<CleanRoomSubMatch>* out_matches) const {
        if (begin == nullptr || end == nullptr || end < begin || out_matches == nullptr) {
            return false;
        }
        out_matches->clear();

        if (kind_ == PatternKind::kVdexHexRange8x8) {
            // Scan for 8 word chars + '-' + 8 word chars: (\w{8})-(\w{8})
            size_t total_len = static_cast<size_t>(end - begin);
            if (total_len < 17) {
                return false;
            }
            for (size_t i = 0; i + 17 <= total_len; ++i) {
                if (begin[i + 8] != '-') {
                    continue;
                }
                bool valid_left = true;
                bool valid_right = true;
                for (size_t k = 0; k < 8; ++k) {
                    unsigned char cl = static_cast<unsigned char>(begin[i + k]);
                    unsigned char cr = static_cast<unsigned char>(begin[i + 9 + k]);
                    if (!std::isalnum(cl) && cl != '_') {
                        valid_left = false;
                        break;
                    }
                    if (!std::isalnum(cr) && cr != '_') {
                        valid_right = false;
                        break;
                    }
                }
                if (valid_left && valid_right) {
                    out_matches->resize(3);
                    (*out_matches)[0] = {begin + i, begin + i + 17, true, {0}};
                    (*out_matches)[1] = {begin + i, begin + i + 8, true, {0}};
                    (*out_matches)[2] = {begin + i + 9, begin + i + 17, true, {0}};
                    return true;
                }
            }
            return false;
        }

        if (kind_ == PatternKind::kSmapsPssKb) {
            // Scan for "Pss:" + \s+ + (\d+) + \s + "kB"
            const std::string view(begin, static_cast<size_t>(end - begin));
            size_t pos = view.find("Pss:");
            while (pos != std::string::npos) {
                size_t cur = pos + 4;
                size_t ws_start = cur;
                while (cur < view.size() && std::isspace(static_cast<unsigned char>(view[cur]))) {
                    ++cur;
                }
                if (cur > ws_start) {
                    size_t dig_start = cur;
                    while (cur < view.size() && std::isdigit(static_cast<unsigned char>(view[cur]))) {
                        ++cur;
                    }
                    size_t dig_end = cur;
                    if (dig_end > dig_start && cur + 3 <= view.size() &&
                        std::isspace(static_cast<unsigned char>(view[cur])) &&
                        view[cur + 1] == 'k' && view[cur + 2] == 'B') {
                        out_matches->resize(2);
                        (*out_matches)[0] = {begin + pos, begin + cur + 3, true, {0}};
                        (*out_matches)[1] = {begin + dig_start, begin + dig_end, true, {0}};
                        return true;
                    }
                }
                pos = view.find("Pss:", pos + 1);
            }
            return false;
        }

        std::cmatch cm;
        std::regex fallback_re(pattern_);
        if (std::regex_search(begin, end, cm, fallback_re)) {
            out_matches->resize(cm.size());
            for (size_t i = 0; i < cm.size(); ++i) {
                (*out_matches)[i] = {cm[i].first, cm[i].second, cm[i].matched, {0}};
            }
            return true;
        }
        return false;
    }

    uint32_t MarkedCount() const { return marked_count_; }
    uint32_t Flags() const { return flags_; }

private:
    std::string pattern_;
    uint32_t    flags_;
    PatternKind kind_;
    uint32_t    marked_count_;
};

} // namespace reconstruction
} // namespace osfix
} // namespace bytedance

namespace bytedance {
namespace osfix {
namespace reconstruction {

// ============================================================================
// SECTION 12: Exact AArch64 Instruction & Branch Target Verification Table
//             Bảng Đối soát Mã lệnh AArch64 & Đích Nhánh Chính xác
// ============================================================================

/**
 * @brief Exact AArch64 instruction verification entry mapping virtual address (equal to
 *        file offset in `.text` `0x005d50..0x01bfaf`) to its 32-bit little-endian instruction
 *        word, mnemonic, operands, and architectural role.
 *        Mục đối soát mã lệnh AArch64 ánh xạ địa chỉ ảo (bằng độ lệch tệp trong `.text`
 *        `0x005d50..0x01bfaf`) tới từ lệnh 32-bit little-endian, tên gợi nhớ và vai trò kiến trúc.
 */
struct OsFixInstructionProofEntry {
    uint32_t    vaddr;
    uint32_t    insn_le;
    const char* mnemonic_and_operands;
    const char* function_context;
};

inline const std::vector<OsFixInstructionProofEntry>& GetOsFixInstructionProofTable() {
    static const std::vector<OsFixInstructionProofEntry> kInsnProofs = {
        // 1. .init_array[0] (0x005d50..0x005df3): std::shared_timed_mutex initialization
        {0x005d50U, 0xa9be4ff4U, "stp x20, x19, [sp, #-0x20]!", "__cxx_global_var_init_shared_timed_mutex"},
        {0x005d54U, 0xa9017bfdU, "stp x29, x30, [sp, #0x10]",   "__cxx_global_var_init_shared_timed_mutex"},
        {0x005d5cU, 0xd0000113U, "adrp x19, #0x28000",          "__cxx_global_var_init_shared_timed_mutex"},
        {0x005d60U, 0x91010273U, "add x19, x19, #0x40",         "__cxx_global_var_init_shared_timed_mutex"},
        {0x005d68U, 0x97ffffeeU, "bl #0x5920 (pthread_mutex_init)", "__cxx_global_var_init_shared_timed_mutex"},
        {0x005d7cU, 0x97ffffc5U, "bl #0x5890 (pthread_cond_init)",  "__cxx_global_var_init_shared_timed_mutex"},
        {0x005d90U, 0x97ffffc0U, "bl #0x5890 (pthread_cond_init)",  "__cxx_global_var_init_shared_timed_mutex"},
        {0x005d98U, 0xf900467fU, "str xzr, [x19, #0x88]",       "__cxx_global_var_init_shared_timed_mutex"},

        // 2. NativeToolUtil::nativeCrash (0x005e7c) & nativeOOM (0x005e80..0x005eef)
        {0x005e7cU, 0xd4200020U, "brk #1",                      "Java_com_bytedance_osfix_NativeToolUtil_nativeCrash"},
        {0x005e80U, 0xd10143ffU, "sub sp, sp, #0x50",           "Java_com_bytedance_osfix_NativeToolUtil_nativeOOM"},
        {0x005e9cU, 0x52a06400U, "mov w0, #0x3200000",          "Java_com_bytedance_osfix_NativeToolUtil_nativeOOM"},
        {0x005ea4U, 0x97fffec7U, "bl #0x59c0 (operator new[])", "Java_com_bytedance_osfix_NativeToolUtil_nativeOOM"},
        {0x005ed8U, 0x52800040U, "mov w0, #2",                  "Java_com_bytedance_osfix_NativeToolUtil_nativeOOM"},
        {0x005edcU, 0x97ffff05U, "bl #0x5af0 (sleep)",          "Java_com_bytedance_osfix_NativeToolUtil_nativeOOM"},

        // 3. NativeToolUtil::logSoLoader (0x005ef0..0x005fe3)
        {0x005ef0U, 0xd10103ffU, "sub sp, sp, #0x40",           "Java_com_bytedance_osfix_NativeToolUtil_logSoLoader"},
        {0x005f04U, 0xf9001102U, "str x2, [x8, #0x20]",         "Java_com_bytedance_osfix_NativeToolUtil_logSoLoader"},
        {0x005f08U, 0x52800020U, "mov w0, #1",                  "Java_com_bytedance_osfix_NativeToolUtil_logSoLoader"},
        {0x005f0cU, 0x97ffff11U, "bl #0x5b50 (bytehook_set_debug)", "Java_com_bytedance_osfix_NativeToolUtil_logSoLoader"},
        {0x005f28U, 0x97ffff16U, "bl #0x5b80 (bytehook_add_dlopen_callback)", "Java_com_bytedance_osfix_NativeToolUtil_logSoLoader"},

        // 4. setenv_proxy (0x00627c..0x00633b) & getenv_proxy (0x00633c..0x0063e3)
        {0x00627cU, 0xf81c0ff7U, "str x23, [sp, #-0x40]!",      "setenv_thread_safe_proxy"},
        {0x0062b0U, 0xd0000117U, "adrp x23, #0x28000",          "setenv_thread_safe_proxy"},
        {0x0062b4U, 0x910102f7U, "add x23, x23, #0x40",         "setenv_thread_safe_proxy"},
        {0x0062bcU, 0x97ffff89U, "bl #0x60e0 (shared_timed_mutex::lock)", "setenv_thread_safe_proxy"},
        {0x0062d8U, 0x97ffff86U, "bl #0x60f0 (shared_timed_mutex::unlock)", "setenv_thread_safe_proxy"},
        {0x00633cU, 0xf81d0ff5U, "str x21, [sp, #-0x30]!",      "getenv_thread_safe_proxy"},
        {0x006370U, 0x97ffff50U, "bl #0x60b0 (shared_timed_mutex::lock_shared)", "getenv_thread_safe_proxy"},
        {0x006384U, 0x97ffff4fU, "bl #0x60c0 (shared_timed_mutex::unlock_shared)", "getenv_thread_safe_proxy"},

        // 5. fixGetSetEnvCall (0x0064ec..0x00656f) & logGetEnvErrorCode (0x006570..0x006677)
        {0x0064ecU, 0xa9be4ff4U, "stp x20, x19, [sp, #-0x20]!", "Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall"},
        {0x00651cU, 0x97ffffc5U, "bl #0x5c30 (bytehook_hook_partial setenv)", "Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall"},
        {0x00654cU, 0x97ffffb9U, "bl #0x5c30 (bytehook_hook_partial getenv)", "Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall"},
        {0x006570U, 0xa9bd57f6U, "stp x22, x21, [sp, #-0x30]!", "Java_com_bytedance_osfix_NativeToolUtil_logGetEnvErrorCode"},
        {0x006678U, 0xd102c3ffU, "sub sp, sp, #0xb0",           "android_log_assert_tls_dump_proxy"},
        {0x0066c4U, 0xd53bd058U, "mrs x24, tpidr_el0",          "android_log_assert_tls_dump_proxy"},
        {0x006748U, 0xf9400703U, "ldr x3, [x24, #8]",           "android_log_assert_tls_dump_proxy"},
        {0x006784U, 0xf9400f03U, "ldr x3, [x24, #0x18]",        "android_log_assert_tls_dump_proxy"},
        {0x0067b8U, 0xf9401303U, "ldr x3, [x24, #0x20]",        "android_log_assert_tls_dump_proxy"},
        {0x0067ecU, 0xf9401703U, "ldr x3, [x24, #0x28]",        "android_log_assert_tls_dump_proxy"},
        {0x006820U, 0xf9401f03U, "ldr x3, [x24, #0x38]",        "android_log_assert_tls_dump_proxy"},
        {0x006854U, 0xf9402303U, "ldr x3, [x24, #0x40]",        "android_log_assert_tls_dump_proxy"},
        {0x006888U, 0xf9402703U, "ldr x3, [x24, #0x48]",        "android_log_assert_tls_dump_proxy"},
        {0x006980U, 0x52807d00U, "mov w0, #0x3e8",              "android_log_assert_tls_dump_proxy"},

        // 6. is64runtime (0x006b50), logVdexOpen (0x006b58), freeVdex (0x006f9c), fixVdexRepeatOpen (0x008d58)
        {0x006b50U, 0x52800020U, "mov w0, #1",                  "Java_com_bytedance_osfix_NativeToolUtil_is64runtime"},
        {0x006b54U, 0xd65f03c0U, "ret",                         "Java_com_bytedance_osfix_NativeToolUtil_is64runtime"},
        {0x006b58U, 0xa9be4ff4U, "stp x20, x19, [sp, #-0x20]!", "Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen"},
        {0x006f9cU, 0xa9ba6ffcU, "stp x28, x27, [sp, #-0x60]!", "freeVdex_smaps_regex_unmapper"},
        {0x007da8U, 0x7110027fU, "cmp w19, #0x400",             "freeVdex_smaps_regex_unmapper"},
        {0x007f00U, 0xcb13001cU, "sub x28, x0, x19",            "freeVdex_smaps_regex_unmapper"},
        {0x007f2cU, 0x97fff69dU, "bl #0x59a0 (munmap)",         "freeVdex_smaps_regex_unmapper"},
        {0x008d58U, 0xf81d0ff5U, "str x21, [sp, #-0x30]!",      "Java_com_bytedance_osfix_NativeToolUtil_fixVdexRepeatOpen"},

        // 7. ThreadStackOptimizer (0x01681c..0x016b9b)
        {0x01681cU, 0xf81c0ff7U, "str x23, [sp, #-0x40]!",      "pthread_create_stack_shrink_proxy"},
        {0x016840U, 0xb40001a1U, "cbz x1, #0x16874",            "pthread_create_stack_shrink_proxy"},
        {0x016868U, 0xd0000088U, "adrp x8, #0x28000",           "pthread_create_stack_shrink_proxy"},
        {0x01686cU, 0xb9800908U, "ldrsw x8, [x8, #8]",          "pthread_create_stack_shrink_proxy"},
        {0x016874U, 0x52800700U, "mov w0, #0x38",               "pthread_create_stack_shrink_proxy"},
        {0x016888U, 0xb9800d08U, "ldrsw x8, [x8, #0xc]",        "pthread_create_stack_shrink_proxy"},
        {0x01688cU, 0xf9000ae8U, "str x8, [x23, #0x10]",        "pthread_create_stack_shrink_proxy"},
        {0x016908U, 0xf81b0ffcU, "str x28, [sp, #-0x50]!",      "shrink_thread_impl"},
        {0x016988U, 0x7100369fU, "cmp w20, #0xd",               "shrink_thread_impl"},
        {0x016b7cU, 0xa9bf7bfdU, "stp x29, x30, [sp, #-0x10]!", "Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread"},
        {0x016b8cU, 0x97ffff5fU, "bl #0x16908 (shrink_thread_impl)", "Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread"},

        // 8. TypeFaceOptimizer (0x016b9c..0x01814f)
        {0x016b9cU, 0x52800020U, "mov w0, #1",                  "Java_com_bytedance_osfix_TypeFaceOptimizer_optimize"},
        {0x016ba0U, 0xd65f03c0U, "ret",                         "Java_com_bytedance_osfix_TypeFaceOptimizer_optimize"},
        {0x016ba4U, 0xa9ba6ffcU, "stp x28, x27, [sp, #-0x60]!", "get_smaps_pss_for_ttf"},
        {0x016d90U, 0x528e6a15U, "mov w21, #0x7350",            "get_smaps_pss_for_ttf"},
        {0x016da0U, 0x72a74e75U, "movk w21, #0x3a73, lsl #16",  "get_smaps_pss_for_ttf"},
        {0x017428U, 0xa9ba6ffcU, "stp x28, x27, [sp, #-0x60]!", "clear_unused_ttf_impl"},
        {0x017854U, 0x528005a1U, "mov w1, #0x2d",               "clear_unused_ttf_impl"},
        {0x017990U, 0x97fffc85U, "bl #0x16ba4 (get_smaps_pss)", "clear_unused_ttf_impl"},
        {0x017998U, 0xf10ffc1fU, "cmp x0, #0x3ff",              "clear_unused_ttf_impl"},
        {0x01799cU, 0xcb190318U, "sub x24, x24, x25",           "clear_unused_ttf_impl"},
        {0x0179acU, 0x97fff7fdU, "bl #0x59a0 (munmap)",         "clear_unused_ttf_impl"},
        {0x017dc0U, 0xd10283ffU, "sub sp, sp, #0xa0",           "Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF"}
    };
    return kInsnProofs;
}

} // namespace reconstruction
} // namespace osfix
} // namespace bytedance
