// ============================================================================
// File: orbuculumadapter_types.h
// Target Binary: liborbuculumadapter.so (149,936 bytes)
// SHA-256: c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785
// Architecture: AArch64 (arm64-v8a), Android NDK clang++ (libc++_shared.so)
// Dependencies: libshadowhook.so, liblog.so, libc.so, libm.so, libdl.so
// Dynamic dlopen Peers: liborbuculum.so, libpumbaa-network.so
//
// [EN] Clean-room C++17 ABI data structures, global memory layout (.data/.bss),
//      JNI callback descriptors, NetConfig repository, BlockSnapshot atomic
//      state, ShadowHook setenv/getenv export table, and SignalCrashGuard TLS
//      structures reconstructed from AArch64 machine code (0x004460..0x01a6ec).
// [VN] Các cấu trúc dữ liệu ABI C++17 tái tạo sạch, bố cục bộ nhớ toàn cục
//      (.data/.bss), bộ mô tả callback JNI, kho lưu trữ NetConfig, trạng thái
//      nguyên tử BlockSnapshot, bảng xuất hàm qua ShadowHook setenv/getenv,
//      và cấu trúc TLS SignalCrashGuard phục dựng từ mã máy AArch64
//      (0x004460..0x01a6ec).
// ============================================================================

#ifndef NEXTAI_OPENCUT_ORBUCULUMADAPTER_TYPES_H_
#define NEXTAI_OPENCUT_ORBUCULUMADAPTER_TYPES_H_

#include <atomic>
#include <condition_variable>
#include <csetjmp>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <vector>

#if defined(__ANDROID__) && __has_include(<jni.h>)
#include <jni.h>
#else
// ============================================================================
// [EN] Standalone JNI type definitions for host-side verification builds
// [VN] Định nghĩa kiểu JNI độc lập phục vụ biên dịch kiểm thử trên máy chủ
// ============================================================================
typedef uint8_t jboolean;
typedef int8_t jbyte;
typedef uint16_t jchar;
typedef int16_t jshort;
typedef int32_t jint;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;
typedef jint jsize;

struct _jobject {};
typedef _jobject* jobject;
typedef jobject jclass;
typedef jobject jstring;
typedef jobject jthrowable;
typedef jobject jarray;
typedef jobject jbyteArray;
typedef jobject jobjectArray;

struct _jfieldID;
typedef _jfieldID* jfieldID;
struct _jmethodID;
typedef _jmethodID* jmethodID;

union jvalue {
    jboolean z;
    jbyte b;
    jchar c;
    jshort s;
    jint i;
    jlong j;
    jfloat f;
    jdouble d;
    jobject l;
};

typedef struct {
    const char* name;
    const char* signature;
    void* fnPtr;
} JNINativeMethod;

struct JNIEnv_;
struct JavaVM_;
typedef JNIEnv_ JNIEnv;
typedef JavaVM_ JavaVM;

#ifndef JNI_FALSE
#define JNI_FALSE 0
#define JNI_TRUE 1
#define JNI_OK 0
#define JNI_ERR (-1)
#define JNI_EDETACHED (-2)
#define JNI_VERSION_1_6 0x00010006
#endif
#endif  // defined(__ANDROID__) && __has_include(<jni.h>)

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

// ============================================================================
// 1. BINARY CONSTANTS & LOGGING TAG
// [EN] Constants extracted directly from .rodata (0x01a6f0..0x01b8f5)
// [VN] Các hằng số trích xuất trực tiếp từ .rodata (0x01a6f0..0x01b8f5)
// ============================================================================

/// @brief [EN] Android log tag at .rodata 0x01aaa3 / [VN] Nhãn ghi log tại 0x01aaa3
constexpr const char* kLogTag = "orbu.culumadapter";

/// @brief [EN] Target Java classes in JNI_OnLoad (0x004540)
///        [VN] Các lớp Java đích trong JNI_OnLoad (0x004540)
constexpr const char* kClassTTKNativeNetworkManager =
    "com/orbu/core/init/TTKNativeNetworkManager";  // .rodata 0x01a8dc
constexpr const char* kClassTTKNativeLiveSeiFieldManager =
    "com/orbu/core/init/TTKNativeLiveSeiFieldManager";  // .rodata 0x01a907

/// @brief [EN] Dataflow ID HTTP header / metadata key (.rodata 0x01abe6)
///        [VN] Khóa header / metadata Dataflow ID (.rodata 0x01abe6)
constexpr const char* kHeaderDataflowId = "x-tt-dataflow-id";

/// @brief [EN] First-party & Third-party default Dataflow IDs (.rodata 0x01b161..0x01b184)
///        [VN] Các mã Dataflow ID mặc định bên thứ nhất & bên thứ ba (.rodata 0x01b161..0x01b184)
constexpr const char* kDfidByteDanceFirstParty = "672137215";      // 0x281001bf ("bd_1st")
constexpr const char* kDfidByteDanceThirdParty = "671088895";      // 0x280000ff ("bd_3rd")
constexpr const char* kDfidTikTokFirstPartyEmpty = "0x28000600";   // 671090176
constexpr const char* kDfidTikTokFirstPartyNoMatch = "0x28000602"; // 671090178
constexpr const char* kMetadataTransitionDfid = "transition_dfid"; // .rodata 0x01b16b

/// @brief [EN] Pumbaa sandbox constants (.rodata 0x01b226..0x01b268)
///        [VN] Các hằng số Pumbaa sandbox (.rodata 0x01b226..0x01b268)
constexpr const char* kHeaderMetasecEventSource = "x-metasec-event-source";
constexpr const char* kEventSourceNativeSo = "Native SO";
constexpr const char* kPumbaaActionNotifyOnly = "4425";
constexpr const char* kPumbaaActionIntercept = "4427";
constexpr const char* kSandboxChannelNetwork = "NETWORK";
constexpr const char* kSandboxChannelSei = "SEI";

// ============================================================================
// 2. NETCONFIG & NETCONFIG REPOSITORY ABI (0x008f98..0x009240, .bss 0x028248)
// [EN] Reconstructed from JNI extractors 0x005058 (initnetconfig), 0x008f98,
//      0x009240, and 0x00dc60 (replenishDataflowId).
// [VN] Phục dựng từ các hàm trích xuất JNI 0x005058 (initnetconfig), 0x008f98,
//      0x009240, và 0x00dc60 (replenishDataflowId).
// ============================================================================

/**
 * @brief [EN] Single network routing rule corresponding to Java
 *             `com.orbu.core.config.NetConfig` (72 bytes = 0x48 on AArch64 libc++).
 *        [VN] Quy tắc định tuyến mạng đơn lẻ tương ứng với lớp Java
 *             `com.orbu.core.config.NetConfig` (72 byte = 0x48 trên AArch64 libc++).
 *
 * Binary ABI layout (verified at 0x009240 & 0x00da64):
 *   +0x00 (24 bytes): std::vector<std::string> hosts
 *   +0x18 (24 bytes): std::vector<std::string> paths
 *   +0x30 (24 bytes): std::string dataflow_id
 *   Total = 0x48 (72 bytes)
 */
struct NetConfig {
    std::vector<std::string> hosts;  // +0x00: Matchable host patterns (supports "*." / "-.")
    std::vector<std::string> paths;  // +0x18: Matchable path prefixes
    std::string dataflow_id;         // +0x30: Assigned Dataflow ID (e.g., "0x28000401" or decimal)
};

/**
 * @brief [EN] Global singleton repository holding parsed `BootConfig` and `AgConfig`
 *             at `.bss 0x028248` (240 bytes = 0xF0 on AArch64 libc++), guarded by
 *             `__cxa_guard_acquire(&0x028338)` and destructed via `0x008a7c`.
 *        [VN] Kho lưu trữ singleton toàn cục chứa `BootConfig` và `AgConfig` đã phân tích
 *             tại `.bss 0x028248` (240 byte = 0xF0 trên AArch64 libc++), được bảo vệ bởi
 *             `__cxa_guard_acquire(&0x028338)` và hủy qua `0x008a7c`.
 *
 * Binary ABI layout (verified at 0x0050d0..0x005804 & 0x008a7c):
 *   +0x00 (72 bytes): NetConfig boot                    (0x028248)
 *   +0x48 (72 bytes): NetConfig ag                      (0x028290)
 *   +0x90 (24 bytes): std::vector<NetConfig> ag_special (0x0282d8)
 *   +0xA8 (24 bytes): std::vector<NetConfig> third_party_config (0x0282f0)
 *   +0xC0 (24 bytes): std::string third_party_fallback_dfid (0x028308)
 *   +0xD8 (24 bytes): std::vector<std::string> compliance_prefix_list (0x028320)
 *   Total = 0xF0 (240 bytes)
 */
struct NetConfigRepository {
    NetConfig boot;                                    // +0x00 (0x028248)
    NetConfig ag;                                      // +0x48 (0x028290)
    std::vector<NetConfig> ag_special;                 // +0x90 (0x0282d8)
    std::vector<NetConfig> third_party_config;         // +0xA8 (0x0282f0)
    std::string third_party_fallback_dfid;             // +0xC0 (0x028308)
    std::vector<std::string> compliance_prefix_list;   // +0xD8 (0x028320)
};

// ============================================================================
// 3. BLOCK SNAPSHOT ATOMIC CONFIG ABI (0x006874, 0x00b09c..0x00b290, 0x00cfc0)
// [EN] Reconstructed from `setNativeHardBlockConfigInner` (0x006874) and
//      `isNativeNetworkResultNeedBlock` (0x007174 -> 0x00cfc0).
// [VN] Phục dựng từ `setNativeHardBlockConfigInner` (0x006874) và
//      `isNativeNetworkResultNeedBlock` (0x007174 -> 0x00cfc0).
// ============================================================================

/**
 * @brief [EN] Immutable hard-block configuration snapshot managed via atomic
 *             `std::shared_ptr<BlockSnapshot>` at `.bss 0x028340`.
 *        [VN] Bản chụp cấu hình chặn cứng bất biến được quản lý qua
 *             `std::shared_ptr<BlockSnapshot>` nguyên tử tại `.bss 0x028340`.
 *
 * Binary ABI layout (verified at 0x006cc8..0x006ea0 & 0x00cfc0..0x00d27c):
 *   +0x00 (1 byte)  : bool enable_network_hard_block
 *   +0x01 (1 byte)  : bool is_target_rule_group
 *   +0x02 (1 byte)  : bool enable_dynamic_check
 *   +0x03 (5 bytes) : alignment padding
 *   +0x08 (24 bytes): std::vector<int32_t> allow_code_list
 *   +0x20 (24 bytes): std::vector<std::string> allow_dfid_list
 *   Total = 0x38 (56 bytes)
 */
struct BlockSnapshot {
    bool enable_network_hard_block = false;     // +0x00
    bool is_target_rule_group = false;          // +0x01
    bool enable_dynamic_check = false;          // +0x02
    std::vector<int32_t> allow_code_list;       // +0x08
    std::vector<std::string> allow_dfid_list;   // +0x20
};

// ============================================================================
// 4. SEI FIELD POLYMORPHIC VALUE & CALLBACK TYPES (0x007300, 0x00d2e8)
// [EN] Reconstructed from `orbuculumIsProceedSeiField` (0x00d2e8) and
//      `proceedSeiFieldUpcall` (0x007300..0x007b14).
// [VN] Phục dựng từ `orbuculumIsProceedSeiField` (0x00d2e8) và
//      `proceedSeiFieldUpcall` (0x007300..0x007b14).
// ============================================================================

/**
 * @brief [EN] SEI field value type tag inspected at `(type_tag - 1)` switch in 0x0073b0.
 *        [VN] Nhãn kiểu giá trị trường SEI được kiểm tra tại nhánh rẽ `(type_tag - 1)` ở 0x0073b0.
 */
enum class SeiValueType : int32_t {
    kBinaryBytes = 1,  // (tag=1): ptr at +0x00, len at +0x08 -> NewByteArray + proceedSeiField(String,[B,String)I
    kString      = 2,  // (tag=2): const char* at +0x00       -> NewStringUTF + proceedSeiField(String,String,String)I
    kBoolean     = 3,  // (tag=3): bool/uint8_t at +0x00      -> proceedSeiField(String,Z,String)I
    kInt64       = 4,  // (tag=4): int64_t at +0x00           -> proceedSeiField(String,J,String)I
    kFloat32     = 5,  // (tag=5): float at +0x00             -> proceedSeiField(String,F,String)I
};

/**
 * @brief [EN] Raw SEI field payload descriptor passed to `orbuculumIsProceedSeiField` (0x00d2e8).
 *        [VN] Bộ mô tả tải trọng trường SEI thô truyền vào `orbuculumIsProceedSeiField` (0x00d2e8).
 *
 * Binary ABI layout (verified at 0x0073ac..0x0075a8):
 *   +0x00 (8 bytes): union { const uint8_t* bytes_ptr; const char* c_str; int64_t i64; float f32; uint8_t boolean; }
 *   +0x08 (8 bytes): size_t byte_length (used when type == SeiValueType::kBinaryBytes)
 *   +0x10 (4 bytes): int32_t value_type (1..5 corresponding to SeiValueType)
 */
struct SeiFieldPayload {
    union {
        const uint8_t* bytes_ptr;
        const char* c_str;
        int64_t i64_val;
        float f32_val;
        uint8_t bool_val;
    } data;                     // +0x00
    size_t byte_length = 0;     // +0x08
    int32_t value_type = 0;     // +0x10
};

/// @brief [EN] Upcall function pointer types stored at .bss 0x028230, 0x028238, 0x028240
///        [VN] Các kiểu con trỏ hàm gọi ngược lưu tại .bss 0x028230, 0x028238, 0x028240
using SendReportCallbackFn = void (*)(
    const std::string& channel,
    const std::string& url_or_key,
    const std::string& method_or_val,
    const std::string& headers_str,
    const std::string& body_str,
    int32_t dataflow_id,
    int32_t sandbox_result,
    bool is_hit_rule,
    int64_t duration_us);

using ProceedSeiFieldCallbackFn = int32_t (*)(
    const char* sei_key,
    const SeiFieldPayload* sei_payload,
    const char* sei_channel);

using InTargetBlockRuleHashListCallbackFn = bool (*)();

using QueryJavaPropertyCallbackFn = std::string (*)(const std::string& property_key);

using LiveShutdownCallbackFn = void (*)();

// ============================================================================
// 5. SHADOWHOOK SETENV / GETENV EXPORT TABLE ABI (0x011db4..0x012354, .bss 0x028930)
// [EN] Reconstructed from `setupEnvTable` (0x012174), `hooked_setenv` (0x011db4),
//      and `hooked_getenv` (0x011e74).
// [VN] Phục dựng từ `setupEnvTable` (0x012174), `hooked_setenv` (0x011db4),
//      và `hooked_getenv` (0x011e74).
// ============================================================================

/**
 * @brief [EN] Single 128-byte entry in the 5-entry `getenv` symbol export table
 *             at `.bss 0x028930..0x028d2f` (`5 * 128 = 640 bytes = 0x280`, inside a
 *             1024-byte buffer with count at `0x028d30` and init flag at `0x028d34`).
 *        [VN] Một mục 128 byte trong bảng xuất biểu tượng 5 mục qua `getenv`
 *             tại `.bss 0x028930..0x028d2f` (`5 * 128 = 640 byte = 0x280`, nằm trong
 *             vùng đệm 1024 byte với biến đếm tại `0x028d30` và cờ khởi tạo tại `0x028d34`).
 */
struct EnvExportEntry {
    char name[64];   // +0x00..+0x3f: Exported symbol key name (strncpy, max 63 chars + NUL)
    char value[64];  // +0x40..+0x7f: Formatted function pointer string via snprintf("%p")
};

static_assert(sizeof(EnvExportEntry) == 128, "EnvExportEntry must be exactly 128 bytes (0x80)");

// ============================================================================
// 6. SANDBOX THREAD POOL ABI (0x0124d0..0x013124, .bss 0x028e98)
// [EN] Reconstructed from `getSandboxThreadPool` (0x0124d0), constructor (0x01259c),
//      worker loop (0x0128f0), and `enqueueTask` (0x012dd4).
// [VN] Phục dựng từ `getSandboxThreadPool` (0x0124d0), hàm tạo (0x01259c),
//      vòng lặp luồng xử lý (0x0128f0), và `enqueueTask` (0x012dd4).
// ============================================================================

/**
 * @brief [EN] 2-thread asynchronous task pool (`"SandboxTP-%zu"`, max 15 chars via
 *             `pthread_setname_np`) used by `sendAsync` (0x00c5e0) to dispatch
 *             JNI report callbacks without blocking network threads.
 *        [VN] Hồ luồng tác vụ bất đồng bộ 2 luồng (`"SandboxTP-%zu"`, tối đa 15 ký tự qua
 *             `pthread_setname_np`) được `sendAsync` (0x00c5e0) sử dụng để gửi
 *             callback báo cáo JNI mà không làm nghẽn luồng mạng.
 */
struct SandboxThreadPoolState {
    std::vector<std::thread> workers;               // +0x00 (0x028e98)
    std::deque<std::function<void()>> task_queue;   // +0x18 (0x028eb0)
    std::mutex queue_mutex;                         // +0x48 (0x028ee0)
    std::condition_variable queue_cv;               // +0x70 (0x028f08)
    std::atomic<bool> stop_flag{false};             // +0xA0 (0x028f38)
};

// ============================================================================
// 7. GLOBAL BSS / DATA RUNTIME STATE (0x028000..0x028fd0)
// [EN] Complete mapping of all global variables in `.data` and `.bss`.
// [VN] Ánh xạ đầy đủ toàn bộ các biến toàn cục trong `.data` và `.bss`.
// ============================================================================

struct GlobalRuntimeState {
    // --- Lifecycle synchronization (.bss 0x028160..0x0281b0) ---
    std::mutex jni_lifecycle_mutex;                 // 0x028160 (.init_array[0] 0x004460)
    std::condition_variable jni_lifecycle_cv;       // 0x028188 (.init_array[0] 0x004460)

    // --- JNI VM, GlobalClassRefs & Static MethodIDs (.bss 0x0281b8..0x028218) ---
    JavaVM* g_vm = nullptr;                         // 0x0281b8
    jclass cls_network_manager = nullptr;           // 0x0281c0 (TTKNativeNetworkManager)
    jclass cls_sei_field_manager = nullptr;         // 0x0281c8 (TTKNativeLiveSeiFieldManager)
    jmethodID mid_get_store_region = nullptr;       // 0x0281d0: ()Ljava/lang/String;
    jmethodID mid_get_sandbox_state = nullptr;      // 0x0281d8: ()Ljava/lang/String;
    jmethodID mid_send_9args = nullptr;             // 0x0281e0: (5xString,IIZZ)V
    jmethodID mid_send_7args = nullptr;             // 0x0281e8: (3xString,IIZZ)V
    jmethodID mid_proceed_sei_bytes = nullptr;      // 0x0281f0: (String,[B,String)I
    jmethodID mid_proceed_sei_string = nullptr;     // 0x0281f8: (String,String,String)I
    jmethodID mid_proceed_sei_bool = nullptr;       // 0x028200: (String,Z,String)I
    jmethodID mid_proceed_sei_long = nullptr;       // 0x028208: (String,J,String)I
    jmethodID mid_proceed_sei_float = nullptr;      // 0x028210: (String,F,String)I
    jmethodID mid_in_target_block_hash = nullptr;   // 0x028218: ()Z

    // --- Strategy flags & Upcall Pointers (.bss 0x028220..0x028240) ---
    int32_t sdk_enable_strategy = 0;                // 0x028220
    int32_t pumbaa_strategy = 0;                    // 0x028224
    int32_t sdk_report_strategy = 0;                // 0x028228
    bool hit_sample_drop = false;                   // 0x02822c
    bool native_debug = false;                      // 0x02822d
    SendReportCallbackFn send_report_cb = nullptr;  // 0x028230
    ProceedSeiFieldCallbackFn proceed_sei_cb = nullptr; // 0x028238
    InTargetBlockRuleHashListCallbackFn in_target_block_cb = nullptr; // 0x028240

    // --- Atomic BlockSnapshot & Active JNI Call Counter (.bss 0x028340..0x028360) ---
    std::shared_ptr<BlockSnapshot> block_snapshot;  // 0x028340 (16-byte shared_ptr)
    std::mutex block_snapshot_mutex;                // Replaces __get_sp_mut(&0x028340) on host
    std::atomic<int64_t> active_jni_calls{0};       // 0x028358
    std::atomic<bool> is_unloading{false};          // 0x02835c
    std::atomic<bool> is_initialized{false};        // 0x028360

    // --- Live Shutdown Callback (.bss 0x028388..0x0283e0) ---
    std::mutex live_shutdown_mutex;                 // 0x028388 (.init_array[1] 0x0044ac)
    std::function<void()> live_shutdown_fn;         // 0x0283b8

    // --- ShadowHook & Env Export Table (.bss 0x0287b8..0x028d40) ---
    std::shared_timed_mutex env_rw_mutex;           // 0x0287b8 (.init_array[2] 0x0044c8)
    void* shadowhook_stub_setenv = nullptr;         // 0x028868
    void* shadowhook_stub_getenv = nullptr;         // 0x028870
    void* orig_setenv_fn = nullptr;                 // 0x028878
    void* orig_getenv_fn = nullptr;                 // 0x028880
    EnvExportEntry env_export_table[8]{};           // 0x028930..0x028d2f (5 active entries)
    uint32_t env_export_count = 0;                  // 0x028d30
    bool env_table_initialized = false;             // 0x028d34
    std::atomic<QueryJavaPropertyCallbackFn> query_java_prop_cb{nullptr}; // 0x028d40
};

/// @brief [EN] Access global runtime state singleton / [VN] Truy cập trạng thái toàn cục
GlobalRuntimeState& GetGlobalRuntimeState();

/// @brief [EN] Access static NetConfigRepository singleton (.bss 0x028248)
///        [VN] Truy cập kho lưu trữ NetConfigRepository tĩnh (.bss 0x028248)
NetConfigRepository& GetNetConfigRepository();

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_ORBUCULUMADAPTER_TYPES_H_
