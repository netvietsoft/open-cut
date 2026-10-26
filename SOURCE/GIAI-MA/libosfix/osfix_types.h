/**
 * @file osfix_types.h
 * @brief Clean-Room C++17 ABI Type Definitions, Bionic TLS Layouts, and Global State for libosfix.so.
 *        Định nghĩa kiểu dữ liệu C++17 Clean-Room, bố cục Bionic TLS và trạng thái toàn cục cho libosfix.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   - Library / Thư viện: libosfix.so (149,616 bytes)
 *   - SHA-256: ddd8baabbcdd7941b13ab0e961a57e92843d957a0c64e6afa3613b2c433c937d
 *   - Architecture / Kiến trúc: AArch64 (ARM64-v8a, Little-Endian LP64)
 *   - Dependencies / Phụ thuộc DT_NEEDED:
 *     liblog.so, libnpth_dl.so, libbytehook.so, libshadowhook.so, libm.so,
 *     libc++_shared.so, libdl.so, libc.so
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   - [OBSERVED]: Direct AArch64 disassembly of .init_array (0x026e10..0x026e1f),
 *     .data (0x028000..0x028017, file offset 0x024000), .bss (0x028020..0x02841f),
 *     and .text (0x005d50..0x01bfb0).
 *     Phân tách mã máy AArch64 trực tiếp từ .init_array, .data, .bss và .text.
 */

#ifndef NEXTAI_OPENCUT_OSFIX_TYPES_H_
#define NEXTAI_OPENCUT_OSFIX_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <pthread.h>
#include <shared_mutex>
#include <string>
#include <vector>

namespace bytedance {
namespace osfix {

// ============================================================================
// 1. Minimal JNI ABI Types (Standalone Clean-Room Compatibility)
//    Các kiểu JNI ABI tối thiểu (Tương thích Clean-Room độc lập)
// ============================================================================

#ifndef JNI_OK
#define JNI_OK 0
#define JNI_ERR (-1)
#define JNI_EDETACHED (-2)
#define JNI_VERSION_1_6 0x00010006
#define JNI_TRUE 1
#define JNI_FALSE 0
#endif

using jboolean = uint8_t;
using jint = int32_t;
using jlong = int64_t;
using jobject = void*;
using jclass = void*;
using jstring = void*;
using jthrowable = void*;
using jmethodID = void*;

/**
 * @brief Minimal JNI Native Interface table offsets observed in libosfix.so.
 *        Các độ lệch bảng giao diện JNI gốc quan sát được trong libosfix.so:
 *        - +0x030 (index 6): FindClass
 *        - +0x070 (index 14): ExceptionOccurred / ExceptionCheck (+0x078 = index 15)
 *        - +0x080 (index 16): ExceptionDescribe / ExceptionClear
 *        - +0x0a8 (index 21): NewGlobalRef
 *        - +0x0b8 (index 23): DeleteLocalRef
 *        - +0x0f8 (index 31): GetObjectClass
 *        - +0x108 (index 33): GetMethodID
 *        - +0x1c8 (index 57): CallObjectMethodV
 *        - +0x260 (index 76): CallIntMethodV
 *        - +0x388 (index 113): GetStaticMethodID
 *        - +0x470 (index 142): CallStaticVoidMethodV
 *        - +0x538 (index 167): NewStringUTF
 *        - +0x548 (index 169): GetStringUTFChars
 *        - +0x550 (index 170): ReleaseStringUTFChars
 */
struct JNIEnvVTable {
    void* reserved[176];
};

struct JNIEnv {
    const JNIEnvVTable* functions;
};

struct JavaVMVTable {
    void* reserved0;
    void* reserved1;
    void* reserved2;
    jint (*DestroyJavaVM)(void* vm);
    jint (*AttachCurrentThread)(void* vm, JNIEnv** p_env, void* thr_args); // +0x20
    jint (*DetachCurrentThread)(void* vm);                                 // +0x28
    jint (*GetEnv)(void* vm, void** p_env, jint version);                  // +0x30
};

struct JavaVM {
    const JavaVMVTable* functions;
};

// ============================================================================
// 2. Bionic AArch64 Thread-Local Storage (TLS) Slot Constants (tpidr_el0)
//    Hằng số khe lưu trữ cục bộ luồng (TLS) Bionic AArch64 (tpidr_el0)
//    [OBSERVED at 0x006678..0x0068c0 in log_assert_proxy]
// ============================================================================

/**
 * @brief Bionic TLS slot indices and byte offsets read via `mrs x8, tpidr_el0`
 *        inside `log_assert_proxy` (0x006678..0x0068c0).
 *        Chỉ mục khe TLS Bionic và độ lệch byte đọc qua `mrs x8, tpidr_el0`
 *        bên trong `log_assert_proxy` (0x006678..0x0068c0).
 */
enum BionicTlsSlotOffset : size_t {
    kTlsSlotSelfOffset          = 0x00, // Slot 0: TLS_SLOT_SELF
    kTlsSlotThreadIdOffset      = 0x08, // Slot 1: TLS_SLOT_THREAD_ID      ([tpidr_el0 + 0x08])
    kTlsSlotErrnoOffset         = 0x10, // Slot 2: TLS_SLOT_ERRNO
    kTlsSlotOpenGlOffset        = 0x18, // Slot 3: TLS_SLOT_OPENGL         ([tpidr_el0 + 0x18])
    kTlsSlotOpenGlApiOffset     = 0x20, // Slot 4: TLS_SLOT_OPENGL_API     ([tpidr_el0 + 0x20])
    kTlsSlotStackGuardOffset    = 0x28, // Slot 5: TLS_SLOT_STACK_GUARD    ([tpidr_el0 + 0x28])
    kTlsSlotSanitizerOffset     = 0x30, // Slot 6: TLS_SLOT_SANITIZER
    kTlsSlotArtThreadSelfOffset = 0x38, // Slot 7: TLS_SLOT_ART_THREAD_SELF([tpidr_el0 + 0x38])
    kTlsSlotDtvOffset           = 0x40, // Slot 8: TLS_SLOT_DTV            ([tpidr_el0 + 0x40])
    kTlsSlotBionicTlsOffset     = 0x48  // Slot 9: TLS_SLOT_BIONIC_TLS     ([tpidr_el0 + 0x48])
};

/**
 * @brief Snapshot of Bionic TLS slots captured during `__android_log_assert` interception.
 *        Bản chụp các khe TLS Bionic thu thập khi chặn `__android_log_assert`.
 */
struct BionicTlsDiagnosticSnapshot {
    uint64_t tls_base;             // Base address from tpidr_el0 / Địa chỉ cơ sở từ tpidr_el0
    uint64_t tls_slot_thread_id;   // [tpidr_el0 + 0x08]
    uint64_t tls_slot_opengl;      // [tpidr_el0 + 0x18]
    uint64_t tls_slot_opengl_api;  // [tpidr_el0 + 0x20]
    uint64_t tls_slot_stack_guard; // [tpidr_el0 + 0x28]
    uint64_t tls_slot_art_thread;  // [tpidr_el0 + 0x38]
    uint64_t tls_slot_dtv;         // [tpidr_el0 + 0x40]
    uint64_t tls_slot_bionic_tls;  // [tpidr_el0 + 0x48]
    uint64_t pthread_self_val;     // Return value of pthread_self()
    int32_t  tid_val;              // Return value of gettid()
};

// ============================================================================
// 3. Bionic AArch64 pthread_attr_t Layout (56 bytes = 0x38 bytes)
//    Bố cục pthread_attr_t trên Bionic AArch64 (56 byte = 0x38 byte)
//    [OBSERVED at 0x016868..0x01688c in pthread_create_proxy]
// ============================================================================

/**
 * @brief Exact 56-byte (`0x38`) Bionic LP64 `pthread_attr_t` layout allocated via
 *        `malloc(0x38)` at `0x016874..0x016878` when `attr == nullptr` and modified
 *        at offset `+0x10` (`stack_size`) at `0x01688c` (`str x8, [x23, #0x10]`).
 *        Bố cục `pthread_attr_t` LP64 Bionic đúng 56 byte (`0x38`) được cấp phát qua
 *        `malloc(0x38)` tại `0x016874..0x016878` khi `attr == nullptr` và ghi đè tại
 *        độ lệch `+0x10` (`stack_size`) ở `0x01688c`.
 */
struct BionicPthreadAttr {
    uint32_t flags;          // +0x00 (4 bytes)
    uint32_t pad0_;          // +0x04 (4 bytes)
    void*    stack_base;     // +0x08 (8 bytes)
    size_t   stack_size;     // +0x10 (8 bytes) <- Overwritten by pthread_create_proxy!
    size_t   guard_size;     // +0x18 (8 bytes)
    int32_t  sched_policy;   // +0x20 (4 bytes)
    int32_t  sched_priority; // +0x24 (4 bytes)
    char     reserved[16];   // +0x28..0x37 (16 bytes)
};
static_assert(sizeof(BionicPthreadAttr) == 0x38, "BionicPthreadAttr must be exactly 0x38 (56) bytes");
static_assert(offsetof(BionicPthreadAttr, stack_size) == 0x10, "stack_size must be at offset +0x10");

// ============================================================================
// 4. ByteHook & ShadowHook & NpthDL Types
//    Các kiểu dữ liệu ByteHook, ShadowHook và NpthDL
// ============================================================================

using ByteHookCallerAllowFilter = bool (*)(const char* caller_path_name, void* arg);
using ByteHookHookedCallback = void (*)(void* task_stub, int status_code, const char* caller_path_name,
                                        const char* sym_name, void* new_func, void* prev_func, void* arg);
using ByteHookPreDlopenCallback = void (*)(const char* filename, void* data);
using ByteHookPostDlopenCallback = void (*)(const char* filename, int result, void* data);

// ============================================================================
// 5. .data (0x028000..0x028017) & .bss (0x028020..0x02841f) Global State
//    Trạng thái toàn cục .data (0x028000..0x028017) & .bss (0x028020..0x02841f)
// ============================================================================

/**
 * @brief Exact `.data` and `.bss` memory layout of `libosfix.so`.
 *        Bố cục bộ nhớ `.data` và `.bss` chính xác của `libosfix.so`.
 *
 * [OBSERVED]:
 *   - `.data` `0x028008` (file offset `0x024008`): `0x00030000` (196,608 bytes = 192 KB)
 *   - `.data` `0x02800c` (file offset `0x02400c`): `0x00080000` (524,288 bytes = 512 KB)
 *   - `.data` `0x028010` (file offset `0x024010`): `-1` (`0xffffffff`)
 *   - `.data` `0x028014` (file offset `0x024014`): `-1` (`0xffffffff`)
 *   - `.bss`  `0x028040..0x0280cf`: `std::shared_timed_mutex` initialized in `.init_array[0]` (`0x005d50`)
 */
struct OsFixGlobalState {
    // .data (0x028000..0x028017)
    uint64_t data_reserved_0x28000 = 0;               // 0x028000
    int32_t  java_shrink_thread_size = 0x00030000;    // 0x028008: 196,608 bytes (192 KB)
    int32_t  native_shrink_thread_size = 0x00080000;  // 0x02800c: 524,288 bytes (512 KB)
    int32_t  setenv_hook_status = -1;                 // 0x028010: 0xffffffff
    int32_t  getenv_hook_status = -1;                 // 0x028014: 0xffffffff

    // .bss (0x028020..0x0281af)
    int64_t  soloader_delay_threshold_ms = 0;         // 0x028020: Set by logSoLoader
    JavaVM*  jvm = nullptr;                           // 0x028028: Cached JavaVM*
    jclass   native_tool_util_class = nullptr;        // 0x028030: GlobalRef to NativeToolUtil
    jmethodID alog_delay_method_id = nullptr;         // 0x028038: Static method alogDelay(Ljava/lang/String;J)V
    std::shared_timed_mutex env_rw_mutex;             // 0x028040..0x0280cf: Reader-Writer lock for getenv/setenv
    void*    setenv_hook_stub = nullptr;              // 0x0280d0: ByteHook stub for setenv
    void*    getenv_hook_stub = nullptr;              // 0x0280d8: ByteHook stub for getenv
    void*    log_assert_hook_stub = nullptr;          // 0x0280e0: ByteHook stub for __android_log_assert
    void*    sk_animated_image_hook_stub = nullptr;   // 0x0280e8: ShadowHook stub for SkAnimatedImage::decodeNextFrame
    void*    sk_animated_image_orig = nullptr;        // 0x0280f0: Original SkAnimatedImage::decodeNextFrame function
    uint8_t  vdex_open_hooked = 0;                    // 0x028180: Guard byte for logVdexOpen
    uint8_t  fix_vdex_enable_free = 0;                // 0x028184: Boolean flag passed to fixVdexRepeatOpen
    void*    dex_file_from_memory_orig = nullptr;     // 0x028188: Original DexFileFromMemory::Create
    void*    art_create_callback_uffd = nullptr;      // 0x028190: _ZN3art6Thread24CreateCallbackWithUffdGcEPv
    void*    art_create_callback = nullptr;           // 0x028198: _ZN3art6Thread14CreateCallbackEPv
    void*    pthread_create_hook_stub = nullptr;      // 0x0281a0: ByteHook stub for pthread_create
};

/**
 * @brief Access the singleton global state of `libosfix.so`.
 *        Truy cập trạng thái toàn cục đơn nguyên của `libosfix.so`.
 */
OsFixGlobalState& GetGlobalState();

// ============================================================================
// 6. VMA / Smaps Region Descriptor for freeVdex & clear_unused_ttf_impl
//    Bộ mô tả vùng nhớ VMA / Smaps cho freeVdex và clear_unused_ttf_impl
// ============================================================================

/**
 * @brief Parsed `/proc/self/smaps` or `/proc/self/maps` region descriptor.
 *        Bộ mô tả vùng nhớ đã phân tích từ `/proc/self/smaps` hoặc `/proc/self/maps`.
 */
struct ProcMemoryRegionInfo {
    uintptr_t   start_addr = 0;  // Start virtual address / Địa chỉ ảo bắt đầu
    uintptr_t   end_addr = 0;    // End virtual address / Địa chỉ ảo kết thúc
    std::string permissions;     // Permissions (e.g. "r--p", "r--s") / Quyền truy cập
    uint64_t    offset = 0;      // File offset / Độ lệch tệp
    std::string device;          // Device major:minor / Thiết bị
    uint64_t    inode = 0;       // Inode number / Số inode
    std::string pathname;        // Mapped file path / Đường dẫn tệp ánh xạ
    int64_t     pss_kb = -1;     // Proportional Set Size in kB / Dung lượng PSS tính bằng kB
    bool        unmapped = false;// True if munmap() succeeded / True nếu munmap() thành công
};

} // namespace osfix
} // namespace bytedance

#endif // NEXTAI_OPENCUT_OSFIX_TYPES_H_
