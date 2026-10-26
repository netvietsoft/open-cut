/**
 * @file iesapplogger_types.h
 * @brief Exact ABI Structs, ELF64 Offsets, .rodata/.bss Layout for libiesapplogger.so
 *        Cấu trúc ABI chuẩn xác, Offset ELF64, Bố cục .rodata/.bss cho libiesapplogger.so
 *
 * Reconstructed from AArch64 ELF64 binary: libiesapplogger.so (67,616 bytes)
 * Tái dựng từ nhị phân ELF64 AArch64: libiesapplogger.so (67.616 byte)
 *
 * Evidence Classification / Phân loại Bằng chứng:
 *   - OBSERVED: Exact section offsets, .bss addresses (0x014010..0x014048),
 *     struct sizes (AppLogReporter = 80 bytes @ 0x004cf8, AppLogTracker::Impl = 80 bytes @ 0x00588c,
 *     RbTreeNodeString = 56 bytes @ 0x00488c), and .rodata string literals (0x00c28c..0x00c4bd).
 *   - Quan sát trực tiếp: Offset các section, địa chỉ .bss (0x014010..0x014048),
 *     kích thước struct (AppLogReporter = 80 byte @ 0x004cf8, AppLogTracker::Impl = 80 byte @ 0x00588c,
 *     RbTreeNodeString = 56 byte @ 0x00488c), và chuỗi hằng .rodata (0x00c28c..0x00c4bd).
 */

#ifndef NEXTAI_OPENCUT_IESAPPLOGGER_TYPES_H_
#define NEXTAI_OPENCUT_IESAPPLOGGER_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <mutex>
#include <set>
#include <string>
#include <vector>

namespace iesapplogger {

// ============================================================================
// 1. ELF64 Section Geometry & Binary Constants (OBSERVED)
//    Hình học Section ELF64 & Hằng số Nhị phân (QUAN SÁT TRỰC TIẾP)
// ============================================================================
struct Elf64Geometry {
    static constexpr uint64_t kFileSizeBytes       = 67616ULL;  // 67,616 B
    static constexpr uint32_t kElfSectionCount     = 25U;       // 25 ELF64 sections
    static constexpr uint32_t kDynsymTotalEntries  = 123U;      // 123 .dynsym entries
    static constexpr uint32_t kDynsymImportCount   = 45U;       // [003..047]
    static constexpr uint32_t kDynsymExportCount   = 75U;       // [048..122]

    static constexpr uint64_t kDynsymVa            = 0x000828ULL;
    static constexpr uint64_t kDynsymSize          = 2952ULL;
    static constexpr uint64_t kDynstrVa            = 0x0013b0ULL;
    static constexpr uint64_t kDynstrSize          = 5636ULL;
    static constexpr uint64_t kRelaDynVa           = 0x003038ULL;
    static constexpr uint64_t kRelaDynSize         = 720ULL;    // 30 entries
    static constexpr uint64_t kRelaPltVa           = 0x003308ULL;
    static constexpr uint64_t kRelaPltSize         = 1728ULL;   // 72 entries
    static constexpr uint64_t kPltVa               = 0x0039d0ULL;
    static constexpr uint64_t kPltSize             = 1184ULL;
    static constexpr uint64_t kTextVa              = 0x003e70ULL;
    static constexpr uint64_t kTextSize            = 33820ULL;  // 0x003e70..0x00c28c
    static constexpr uint64_t kRodataVa            = 0x00c28cULL;
    static constexpr uint64_t kRodataSize          = 705ULL;    // 0x00c28c..0x00c54d
    static constexpr uint64_t kDataRelRoVa         = 0x013ac8ULL;
    static constexpr uint64_t kDataRelRoSize       = 168ULL;    // 0x013ac8..0x013b70
    static constexpr uint64_t kGotVa               = 0x013fa8ULL;
    static constexpr uint64_t kGotSize             = 88ULL;
    static constexpr uint64_t kDataVa              = 0x014000ULL;
    static constexpr uint64_t kDataSize            = 16ULL;
    static constexpr uint64_t kBssVa               = 0x014010ULL;
    static constexpr uint64_t kBssSize             = 640ULL;    // 0x014010..0x014290
};

// ============================================================================
// 2. .bss Global State Addresses (0x014010..0x014048) (OBSERVED)
//    Địa chỉ Biến Toàn cục .bss (0x014010..0x014048) (QUAN SÁT TRỰC TIẾP)
// ============================================================================
struct BssOffsets {
    // Exported in .dynsym [053] gJvm (8 bytes, GOT @ 0x013fe8)
    // Được xuất trong .dynsym [053] gJvm (8 byte, GOT @ 0x013fe8)
    static constexpr uint64_t kGlobalJvmPtr               = 0x014010ULL;

    // AppLogReporter* singleton instance pointer (8 bytes, allocated 0x50 B @ 0x004cf8)
    // Con trỏ thực thể đơn lệ AppLogReporter* (8 byte, cấp phát 0x50 B @ 0x004cf8)
    static constexpr uint64_t kReporterSingletonPtr       = 0x014018ULL;

    // std::once_flag for AppLogReporter::GetSingleton() (8 bytes, checked via ldar @ 0x0043e4)
    // Cờ std::once_flag cho AppLogReporter::GetSingleton() (8 byte, kiểm tra qua ldar @ 0x0043e4)
    static constexpr uint64_t kReporterOnceFlag           = 0x014020ULL;

    // Cached jmethodID for IESAppLogger.appLogOnEvent(String, String, String, boolean)V
    // jmethodID lưu đệm cho IESAppLogger.appLogOnEvent(String, String, String, boolean)V
    static constexpr uint64_t kAppLogOnEventMethodId      = 0x014028ULL;

    // Cached GlobalRef to IESAppLogger.sharedInstance() jobject
    // Tham chiếu toàn cục GlobalRef tới đối tượng IESAppLogger.sharedInstance()
    static constexpr uint64_t kIesAppLoggerInstanceObj    = 0x014030ULL;

    // Cached GlobalRef to java/lang/String jclass
    // Tham chiếu toàn cục GlobalRef tới lớp java/lang/String
    static constexpr uint64_t kJavaLangStringClass        = 0x014038ULL;

    // Cached jmethodID for java/lang/String.<init>([BLjava/lang/String;)V
    // jmethodID lưu đệm cho hàm tạo java/lang/String.<init>([BLjava/lang/String;)V
    static constexpr uint64_t kJavaLangStringCtorMethodId = 0x014040ULL;

    // Boolean flag indicating initJniIds() succeeded (1 byte, set to 1 @ 0x0043ac)
    // Cờ boolean báo hiệu initJniIds() đã khởi tạo thành công (1 byte, gán 1 @ 0x0043ac)
    static constexpr uint64_t kJniIdsInitializedFlag      = 0x014048ULL;
};

// ============================================================================
// 3. .rodata String Table Offsets & Values (0x00c28c..0x00c4bd) (OBSERVED)
//    Bảng Chuỗi .rodata & Giá trị Thực tế (0x00c28c..0x00c4bd) (QUAN SÁT TRỰC TIẾP)
// ============================================================================
struct RodataStrings {
    static constexpr uint64_t kVaClassIesAppLogger   = 0x00c28cULL;
    static constexpr const char* kClassIesAppLogger  = "com/bytedance/ies/common/IESAppLogger";

    static constexpr uint64_t kVaMethodSharedInst    = 0x00c2b2ULL;
    static constexpr const char* kMethodSharedInst   = "sharedInstance";

    static constexpr uint64_t kVaSigSharedInst       = 0x00c2c1ULL;
    static constexpr const char* kSigSharedInst      = "()Lcom/bytedance/ies/common/IESAppLogger;";

    static constexpr uint64_t kVaMethodAppLogOnEvent = 0x00c2ebULL;
    static constexpr const char* kMethodAppLogOnEvent = "appLogOnEvent";

    static constexpr uint64_t kVaSigAppLogOnEvent    = 0x00c2f9ULL;
    static constexpr const char* kSigAppLogOnEvent   = "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V";

    static constexpr uint64_t kVaClassJavaString     = 0x00c334ULL;
    static constexpr const char* kClassJavaString    = "java/lang/String";

    static constexpr uint64_t kVaMethodInit          = 0x00c345ULL;
    static constexpr const char* kMethodInit         = "<init>";

    static constexpr uint64_t kVaSigStringInit       = 0x00c34cULL;
    static constexpr const char* kSigStringInit      = "([BLjava/lang/String;)V";

    static constexpr uint64_t kVaClassJavaSet        = 0x00c364ULL;
    static constexpr const char* kClassJavaSet       = "java/util/Set";

    static constexpr uint64_t kVaMethodIterator      = 0x00c372ULL;
    static constexpr const char* kMethodIterator     = "iterator";

    static constexpr uint64_t kVaSigIterator         = 0x00c37bULL;
    static constexpr const char* kSigIterator        = "()Ljava/util/Iterator;";

    static constexpr uint64_t kVaClassJavaIterator   = 0x00c392ULL;
    static constexpr const char* kClassJavaIterator  = "java/util/Iterator";

    static constexpr uint64_t kVaMethodHasNext       = 0x00c3a5ULL;
    static constexpr const char* kMethodHasNext      = "hasNext";

    static constexpr uint64_t kVaSigHasNext          = 0x00c3adULL;
    static constexpr const char* kSigHasNext         = "()Z";

    static constexpr uint64_t kVaMethodNext          = 0x00c3b1ULL;
    static constexpr const char* kMethodNext         = "next";

    static constexpr uint64_t kVaSigNext             = 0x00c3b6ULL;
    static constexpr const char* kSigNext            = "()Ljava/lang/Object;";

    static constexpr uint64_t kVaTypeinfoLambda0     = 0x00c3cbULL;
    static constexpr const char* kTypeinfoLambda0    = "Z10JNI_OnLoadE3$_0";

    static constexpr uint64_t kVaUtf8Encoding        = 0x00c457ULL;
    static constexpr const char* kUtf8Encoding       = "utf-8";

    static constexpr uint64_t kVaTypeinfoLambda2     = 0x00c45dULL;
    static constexpr const char* kTypeinfoLambda2    = "ZL10appLogFuncPKcS3_S3_bE3$_2";

    static constexpr uint64_t kVaJsonOpenBrace       = 0x00c48bULL;
    static constexpr const char* kJsonOpenBrace      = "{";

    static constexpr uint64_t kVaJsonCloseBrace      = 0x00c48dULL;
    static constexpr const char* kJsonCloseBrace     = "}";

    static constexpr uint64_t kVaJsonComma           = 0x00c48fULL;
    static constexpr const char* kJsonComma          = ",";

    static constexpr uint64_t kVaJsonKeyValueSep     = 0x00c491ULL;
    static constexpr const char* kJsonKeyValueSep    = "\":";

    static constexpr uint64_t kVaJsonKeyQuoteSep     = 0x00c494ULL;
    static constexpr const char* kJsonKeyQuoteSep    = "\":\"";

    static constexpr uint64_t kVaBasicStringErr      = 0x00c498ULL;
    static constexpr const char* kBasicStringErr     = "basic_string";
};

// ============================================================================
// 4. NDK libc++ SSO String & Red-Black Tree Node Layout (OBSERVED)
//    Bố cục Chuỗi SSO & Nút Cây Đỏ-Đen NDK libc++ (QUAN SÁT TRỰC TIẾP)
// ============================================================================

/**
 * @brief NDK libc++ 24-byte Small String Optimization (SSO) ABI layout (little-endian AArch64).
 *        Bố cục ABI 24 byte của chuỗi tối ưu hóa ngắn (SSO) trong NDK libc++ (AArch64 little-endian).
 *
 * Observed at 0x0048ac..0x0048e0, 0x0083f4..0x008a48:
 *   - Short mode: byte[0] bit 0 == 0, length = (byte[0] >> 1), inline capacity = 22 (0x16),
 *     characters stored at byte[1..22] with null terminator.
 *   - Long mode:  cap_and_flag (offset +0x00) has bit 0 == 1 (true capacity = (cap & ~1ULL) - 1),
 *     size (offset +0x08), heap data pointer (offset +0x10).
 */
union LibcppSsoStringAbi {
    struct LongLayout {
        uint64_t cap_and_flag;  // +0x00: (allocated_bytes | 1ULL)
        uint64_t size;          // +0x08: string length in bytes
        char*    data;          // +0x10: heap-allocated buffer
    } long_rep;

    struct ShortLayout {
        uint8_t  size_shifted;  // +0x00: (length << 1) | 0
        char     inline_buf[23];// +0x01..+0x17: up to 22 chars + '\0'
    } short_rep;

    uint8_t raw_bytes[24];
};
static_assert(sizeof(LibcppSsoStringAbi) == 24, "LibcppSsoStringAbi must be 24 bytes (0x18)");

/**
 * @brief NDK libc++ Red-Black Tree Node for std::set<std::string> (56 bytes = 0x38).
 *        Nút Cây Đỏ-Đen NDK libc++ cho std::set<std::string> (56 byte = 0x38).
 *
 * Observed at 0x004888 (`mov w0, #0x38; bl _Znwm`) and 0x005390 (`mov w0, #0x38; bl _Znwm`):
 *   - +0x00: __left_     (8 bytes)
 *   - +0x08: __right_    (8 bytes)
 *   - +0x10: __parent_   (8 bytes)
 *   - +0x18: __is_black_ (1 byte + 7 bytes alignment padding)
 *   - +0x20: __value_    (24-byte std::string key)
 *   Total = 56 bytes (0x38).
 */
struct RbTreeNodeStringAbi {
    RbTreeNodeStringAbi* left;      // +0x00
    RbTreeNodeStringAbi* right;     // +0x08
    RbTreeNodeStringAbi* parent;    // +0x10
    bool                 is_black;  // +0x18
    uint8_t              pad[7];    // +0x19..+0x1F
    LibcppSsoStringAbi   value;     // +0x20..+0x37 (24 bytes)
};
static_assert(sizeof(RbTreeNodeStringAbi) == 56, "RbTreeNodeStringAbi must be 56 bytes (0x38)");

/**
 * @brief NDK libc++ std::set<std::string> header layout (24 bytes = 0x18).
 *        Bố cục phần đầu std::set<std::string> của NDK libc++ (24 byte = 0x18).
 *
 * Observed at 0x0046f8..0x004700 and 0x004d0c..0x004d18:
 *   - +0x00: __begin_node_ (points to __pair1_ when empty)
 *   - +0x08: __pair1_.__first_ (end-node __left_ / root pointer, nullptr when empty)
 *   - +0x10: __pair3_.__first_ (node count / size, 0 when empty)
 */
struct RbTreeSetHeaderAbi {
    void*                begin_node; // +0x00
    RbTreeNodeStringAbi* root_left;  // +0x08
    uint64_t             node_count; // +0x10
};
static_assert(sizeof(RbTreeSetHeaderAbi) == 24, "RbTreeSetHeaderAbi must be 24 bytes (0x18)");

// ============================================================================
// 5. AppLogReporter Singleton ABI Layout (80 bytes = 0x50) (OBSERVED)
//    Bố cục ABI của Singleton AppLogReporter (80 byte = 0x50) (QUAN SÁT TRỰC TIẾP)
// ============================================================================

using AppLogReportCallback = int (*)(const char* app_id,
                                     const char* event_name,
                                     const char* params_json,
                                     bool report_to_business);

/**
 * @brief Exact 80-byte (0x50) memory layout of AppLogReporter allocated at 0x004cf4..0x004d24.
 *        Bố cục bộ nhớ chuẩn xác 80 byte (0x50) của AppLogReporter cấp phát tại 0x004cf4..0x004d24.
 *
 * Disassembly proof at 0x004cf0..0x004d24:
 *   0x004cf4: mov w0, #0x50        ; 80 bytes
 *   0x004cf8: bl  _Znwm            ; operator new(80)
 *   0x004cfc: adrp x8, #0x4000
 *   0x004d04: add  x8, x8, #0xd3c  ; x8 = 0x004d3c (appLogFunc)
 *   0x004d08: str  x8, [x0, #0x28] ; +0x28 = report_func_
 *   0x004d0c: add  x8, x0, #0x40   ; &sampler_set_.__pair1_
 *   0x004d10: mov  w9, #1
 *   0x004d14: strb w9, [x0, #0x30] ; +0x30 = enabled_ (true)
 *   0x004d18: str  x8, [x0, #0x38] ; +0x38 = sampler_set_.__begin_node_
 *   0x004d1c: stp  xzr, xzr, [x0, #0x40] ; +0x40 = root (nullptr), +0x48 = size (0)
 *   0x004d24: stp  xzr, xzr, [x0, #0x18] ; zero mutex_ (+0x00..+0x27)
 */
struct AppLogReporterAbi {
    uint8_t              mutex_storage[40]; // +0x00..+0x27: pthread_mutex_t / std::mutex (40 B on AArch64)
    AppLogReportCallback report_func;       // +0x28..+0x2F: callback pointer (default: appLogFunc @ 0x004d3c)
    bool                 enabled;           // +0x30: global reporting enabled flag (default: true)
    uint8_t              pad_31[7];         // +0x31..+0x37: alignment padding
    RbTreeSetHeaderAbi   sampler_set;       // +0x38..+0x4F: std::set<std::string> sampler whitelist (24 B)
};
static_assert(sizeof(AppLogReporterAbi) == 80, "AppLogReporterAbi must be 80 bytes (0x50)");
static_assert(offsetof(AppLogReporterAbi, report_func) == 0x28, "report_func must be at +0x28");
static_assert(offsetof(AppLogReporterAbi, enabled) == 0x30, "enabled must be at +0x30");
static_assert(offsetof(AppLogReporterAbi, sampler_set) == 0x38, "sampler_set must be at +0x38");

// ============================================================================
// 6. IESAppLogger::AppLogTracker::Impl ABI Layout (80 bytes = 0x50) (OBSERVED)
//    Bố cục ABI của IESAppLogger::AppLogTracker::Impl (80 byte = 0x50) (QUAN SÁT TRỰC TIẾP)
// ============================================================================

/**
 * @brief Exact 80-byte (0x50) layout of IESAppLogger::AppLogTracker::Impl.
 *        Bố cục bộ nhớ 80 byte (0x50) chuẩn xác của IESAppLogger::AppLogTracker::Impl.
 *
 * Disassembly proof at 0x005878..0x005950 & 0x005b50..0x005ccc:
 *   - Allocated via `_Znwm(0x50)` at 0x00588c, 0x0059e4, 0x005b60, 0x005bd0.
 *   - +0x00..+0x17: std::string app_id_       (24 bytes)
 *   - +0x18..+0x2F: std::string event_name_   (24 bytes)
 *   - +0x30..+0x47: std::string json_buffer_  (24 bytes, reserved to 0x200 = 512 B @ 0x005918,
 *                                              initialized with "{" @ 0x005928)
 *   - +0x48:        bool is_reported_         (1 byte, initialized to 0, set to 1 in dtor @ 0x005ccc)
 *   - +0x49:        bool report_to_business_  (1 byte, initialized to 0, set in setReportToBusiness @ 0x0083c8)
 *   - +0x4A:        bool is_enabled_          (1 byte, initialized to 1 @ 0x00590c, checked before putVal/putVals)
 *   - +0x4B..+0x4F: 5 bytes tail padding to 80 bytes (0x50).
 */
struct AppLogTrackerImplAbi {
    LibcppSsoStringAbi app_id;              // +0x00..+0x17 (24 bytes)
    LibcppSsoStringAbi event_name;          // +0x18..+0x2F (24 bytes)
    LibcppSsoStringAbi json_buffer;         // +0x30..+0x47 (24 bytes, reserve(512), starts with "{")
    bool               is_reported;         // +0x48
    bool               report_to_business;  // +0x49
    bool               is_enabled;          // +0x4A
    uint8_t            pad_4b[5];           // +0x4B..+0x4F
};
static_assert(sizeof(AppLogTrackerImplAbi) == 80, "AppLogTrackerImplAbi must be 80 bytes (0x50)");
static_assert(offsetof(AppLogTrackerImplAbi, app_id) == 0x00, "app_id must be at +0x00");
static_assert(offsetof(AppLogTrackerImplAbi, event_name) == 0x18, "event_name must be at +0x18");
static_assert(offsetof(AppLogTrackerImplAbi, json_buffer) == 0x30, "json_buffer must be at +0x30");
static_assert(offsetof(AppLogTrackerImplAbi, is_reported) == 0x48, "is_reported must be at +0x48");
static_assert(offsetof(AppLogTrackerImplAbi, report_to_business) == 0x49, "report_to_business must be at +0x49");
static_assert(offsetof(AppLogTrackerImplAbi, is_enabled) == 0x4a, "is_enabled must be at +0x4a");

/**
 * @brief Control block for std::shared_ptr<int> thread-detach RAII guard (32 bytes = 0x20).
 *        Khối điều khiển cho con trỏ thông minh RAII tách luồng JNI (32 byte = 0x20).
 *
 * Allocated via `_Znwm(0x20)` at 0x003fb0 (JNI_OnLoad::$_0, vtable 0x013ae0)
 * and 0x004dd4 (appLogFunc::$_2, vtable 0x013b30).
 */
struct SharedPtrThreadGuardControlBlock {
    const void* vtable_ptr;       // +0x00: points to 0x013ae0 or 0x013b30 (+0x10 inside vtable)
    int64_t     shared_owners;    // +0x08: initialized to 0 (means 1 owner in libc++)
    int64_t     shared_weak_owners;// +0x10: initialized to 0
    int*        attached_flag_ptr;// +0x18: pointer to local `int attached` on stack
};
static_assert(sizeof(SharedPtrThreadGuardControlBlock) == 32, "SharedPtrThreadGuardControlBlock must be 32 bytes (0x20)");

}  // namespace iesapplogger

#endif  // NEXTAI_OPENCUT_IESAPPLOGGER_TYPES_H_
