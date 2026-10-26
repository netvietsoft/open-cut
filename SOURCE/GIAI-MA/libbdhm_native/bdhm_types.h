// ============================================================================
// File: bdhm_types.h
// Module: libbdhm_native.so — ByteDance Hybrid Monitor V2 SparkTracing Types
//         (Định nghĩa Kiểu dữ liệu, Bố cục ABI & Hằng số Nhị phân SparkTracing)
// Project: NextAI OpenCut (com.nextai.opencut)
// Task ID: TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE (TASK_SO_102)
// Verification: OBSERVED from apktool-res/lib/arm64-v8a/libbdhm_native.so
//               (599,968 bytes, 78 dynamic symbols: 27 exported + 51 imported)
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <mutex>

namespace NextAI {
namespace OpenCut {
namespace BdhmNative {

// ============================================================================
// [EN] 1. ELF64 Binary Geometry & Segment Constants (OBSERVED)
//      Verified via llvm-objdump / readelf on libbdhm_native.so (599,968 B):
//        - PT_LOAD 0 (R):   vaddr 0x000000..0x02d51c -> file 0x000000..0x02d51c
//          (.rodata at 0x00b170..0x01a137, size 0x00efc7 = 61,383 bytes)
//        - PT_LOAD 1 (R+X): vaddr 0x03151c..0x08efd0 -> file 0x02d51c..0x08afd0
//          (delta = 0x4000; .text at 0x03151c..0x08ec8c, .plt at 0x08ec90..0x08efd0)
//        - PT_LOAD 2 (RW RELRO): vaddr 0x092fd0..0x09a020 -> file 0x08afd0..0x092020
//          (delta = 0x8000; .data.rel.ro at 0x092fd0..0x099ca8)
//        - PT_LOAD 3 (RW):  vaddr 0x09e020..0x09ead8 -> file 0x092020..0x0920c0
//          (delta = 0xc000; .data at 0x09e020..0x09e0c0, .bss at 0x09e0c0..0x09ead8)
// [VN] 1. Hình học Nhị phân ELF64 & Hằng số Phân đoạn (QUAN SÁT TRỰC TIẾP)
//      Xác minh qua llvm-objdump / readelf trên libbdhm_native.so (599.968 B).
// ============================================================================
constexpr uint64_t kBdhmBinarySizeBytes         = 599968ULL;
constexpr uint32_t kBdhmTotalDynSymCount        = 78U;
constexpr uint32_t kBdhmExportedFuncCount       = 27U;
constexpr uint32_t kBdhmImportedSymCount        = 51U;

constexpr uint64_t kRodataVaddrStart            = 0x00b170ULL;
constexpr uint64_t kRodataSizeBytes             = 0x00efc7ULL;
constexpr uint64_t kTextVaddrStart              = 0x03151cULL;
constexpr uint64_t kTextVaddrEnd                = 0x08ec8cULL;
constexpr uint64_t kDataRelRoVaddrStart         = 0x092fd0ULL;
constexpr uint64_t kBssVaddrStart               = 0x09e0c0ULL;
constexpr uint64_t kBssVaddrEnd                 = 0x09ead8ULL;

// SwissTable / hashbrown 8-byte control group high-bit mask used in
// do_getChildIds (0x043abc: mov x12, #-0x7f7f7f7f7f7f7f80 = 0x8080808080808080)
constexpr uint64_t kSwissTableControlBitMask    = 0x8080808080808080ULL;

// ============================================================================
// [EN] 2. Exported Symbol Virtual Addresses in .text (OBSERVED)
//      All 27 exported functions in .dynsym ([052]..[078]):
//        - 8 JNIReachabilityFence methods at 0x03e820..0x03e83c (4 bytes each: ret)
//        - 17 SparkTracingNative methods at 0x03eae0..0x045d10
//        - JNI_OnLoad (0x045e44) & JNI_OnUnload (0x046990)
// [VN] 2. Địa chỉ Ảo các Biểu tượng Xuất trong .text (QUAN SÁT TRỰC TIẾP)
//      Toàn bộ 27 hàm xuất trong bảng .dynsym ([052]..[078]).
// ============================================================================
constexpr uint64_t kAddrReachabilityFence1      = 0x03e820ULL;
constexpr uint64_t kAddrReachabilityFence2      = 0x03e824ULL;
constexpr uint64_t kAddrReachabilityFence3      = 0x03e828ULL;
constexpr uint64_t kAddrReachabilityFence4      = 0x03e82cULL;
constexpr uint64_t kAddrReachabilityFence5      = 0x03e830ULL;
constexpr uint64_t kAddrReachabilityFence6      = 0x03e834ULL;
constexpr uint64_t kAddrReachabilityFence7      = 0x03e838ULL;
constexpr uint64_t kAddrReachabilityFence8      = 0x03e83cULL;

constexpr uint64_t kAddrSparkInit               = 0x03eae0ULL; // size: 10,544 B
constexpr uint64_t kAddrSparkInitLogger         = 0x041410ULL; // size: 12 B
constexpr uint64_t kAddrSparkDoSnapshot         = 0x04141cULL; // size: 5,508 B
constexpr uint64_t kAddrSparkDoSetManifest      = 0x0429a0ULL; // size: 160 B
constexpr uint64_t kAddrSparkDoGetProperties    = 0x042a40ULL; // size: 404 B
constexpr uint64_t kAddrSparkDoGetProperty      = 0x042bd4ULL; // size: 224 B
constexpr uint64_t kAddrSparkDoSetProperty      = 0x042cb4ULL; // size: 316 B
constexpr uint64_t kAddrSparkDoSetProperties    = 0x042df0ULL; // size: 704 B
constexpr uint64_t kAddrSparkDoNewContextProps  = 0x0430b0ULL; // size: 616 B
constexpr uint64_t kAddrSparkDoIsContextExists  = 0x043318ULL; // size: 100 B
constexpr uint64_t kAddrSparkDoSetAliveState    = 0x04337cULL; // size: 300 B
constexpr uint64_t kAddrSparkDoUpdateLink       = 0x0434a8ULL; // size: 1,476 B
constexpr uint64_t kAddrSparkDoGetChildIds      = 0x043a6cULL; // size: 872 B
constexpr uint64_t kAddrSparkDoComputeExpr      = 0x043dd4ULL; // size: 420 B
constexpr uint64_t kAddrSparkDoCompute          = 0x043f78ULL; // size: 764 B
constexpr uint64_t kAddrSparkDoUpdate           = 0x044274ULL; // size: 6,812 B
constexpr uint64_t kAddrSparkDoDelete           = 0x045d10ULL; // size: 308 B

constexpr uint64_t kAddrJniOnLoad               = 0x045e44ULL; // size: 2,892 B
constexpr uint64_t kAddrJniOnUnload             = 0x046990ULL; // size: 648 B

// ============================================================================
// [EN] 3. System Key & Value Type Prefix Constants in .rodata (OBSERVED)
//      Extracted from .rodata 0x00be00..0x00dd80:
//        - Value type tags: "__st_string;", "__st_number;", "__st_bool;"
//        - DB composite key separator: "__SYS__###"
//        - System metadata keys:
//          "__SYS__IDS", "__SYS__PARENT_IDS", "__SYS__LIFE", "__SYS__STATIC",
//          "__SYS__LEAF", "__SYS__LAST_ACCESS_TIME", "__SYS__ALIVE"
// [VN] 3. Hằng số Khóa Hệ thống & Tiền tố Kiểu Giá trị trong .rodata (QUAN SÁT)
//      Trích xuất từ .rodata 0x00be00..0x00dd80.
// ============================================================================
constexpr const char* kPrefixStString           = "__st_string;";
constexpr const char* kPrefixStNumber           = "__st_number;";
constexpr const char* kPrefixStBool             = "__st_bool;";

constexpr const char* kSysKeySeparator          = "__SYS__###";
constexpr const char* kSysKeyIds                = "__SYS__IDS";
constexpr const char* kSysKeyParentIds          = "__SYS__PARENT_IDS";
constexpr const char* kSysKeyLife               = "__SYS__LIFE";
constexpr const char* kSysKeyStatic             = "__SYS__STATIC";
constexpr const char* kSysKeyLeaf               = "__SYS__LEAF";
constexpr const char* kSysKeyLastAccessTime     = "__SYS__LAST_ACCESS_TIME";
constexpr const char* kSysKeyAlive              = "__SYS__ALIVE";

constexpr size_t   kDefaultMaxContextPropsCount = 1024U;
constexpr uint64_t kDefaultLifeMillis           = 300000ULL; // 5 minutes default TTL
constexpr uint64_t kDefaultPulseIntervalMillis  = 60000ULL;  // 60 seconds default pulse

// ============================================================================
// [EN] 4. Property Value Representation (PropValue)
//      Maps to Rust enum in bdhm_native::api::context_props with serialized
//      prefixes "__st_string;", "__st_number;", "__st_bool;".
// [VN] 4. Biểu diễn Giá trị Thuộc tính (PropValue)
//      Ánh xạ tới enum Rust trong bdhm_native::api::context_props.
// ============================================================================
enum class PropValueKind : uint8_t {
    kNull   = 0,
    kString = 1,
    kNumber = 2,
    kBool   = 3
};

struct PropValue {
    PropValueKind kind = PropValueKind::kNull;
    std::string   str_val;
    double        num_val = 0.0;
    bool          bool_val = false;

    static PropValue MakeNull() {
        return PropValue{};
    }
    static PropValue MakeString(const std::string& s) {
        PropValue v;
        v.kind = PropValueKind::kString;
        v.str_val = s;
        return v;
    }
    static PropValue MakeNumber(double n) {
        PropValue v;
        v.kind = PropValueKind::kNumber;
        v.num_val = n;
        return v;
    }
    static PropValue MakeBool(bool b) {
        PropValue v;
        v.kind = PropValueKind::kBool;
        v.bool_val = b;
        return v;
    }

    // [EN] Encode into DB storage format with "__st_*;" prefix (0x00be01)
    // [VN] Mã hóa sang định dạng lưu trữ DB với tiền tố "__st_*;" (0x00be01)
    std::string EncodeToDbString() const;

    // [EN] Decode from DB storage format ("__st_string;", "__st_number;", "__st_bool;")
    // [VN] Giải mã từ định dạng lưu trữ DB
    static bool DecodeFromDbString(const std::string& raw, PropValue* out_val, std::string* out_err);

    // [EN] Convert to plain display / JSON string
    // [VN] Chuyển đổi sang chuỗi hiển thị / JSON
    std::string ToPlainString() const;
    std::string ToJsonLiteral() const;
};

// ============================================================================
// [EN] 5. Context Property Node (ContextInstance)
//      Reconstructed from .rodata field names at 0x00dc9f..0x00dd05:
//        "id", "is_static", "is_leaf", "last_access_time_millis",
//        "life_millis", "parent_ids", "kvs", "_computed"
// [VN] 5. Nút Thuộc tính Ngữ cảnh (ContextInstance)
//      Tái dựng từ các tên trường trong .rodata tại 0x00dc9f..0x00dd05.
// ============================================================================
struct ContextInstance {
    std::string id;
    bool        is_static               = false;
    bool        is_leaf                 = false;
    bool        is_alive                = true;
    uint64_t    last_access_time_millis = 0ULL;
    uint64_t    life_millis             = kDefaultLifeMillis;
    std::vector<std::string> parent_ids;
    std::unordered_map<std::string, PropValue> kvs;
    std::unordered_set<std::string> computed_events;
};

// ============================================================================
// [EN] 6. Declared Manifest & Event Schema (bdhm_native::api::manifest)
//      Reconstructed from .rodata serde descriptors at 0x00dd88..0x00de30:
//        - struct DeclaredManifest with 4 elements:
//          version, events, enabled, extra_mappings
//        - struct DeclaredEvent with 7 elements:
//          props_extends, target, default, props, behavior, perf_stat, ignore_null
//        - struct DeclaredEventBehavior with 4 elements:
//          when, sequence, sampling, is_alive
// [VN] 6. Lược đồ Manifest & Sự kiện Khai báo (bdhm_native::api::manifest)
//      Tái dựng từ các mô tả serde trong .rodata tại 0x00dd88..0x00de30.
// ============================================================================
struct DeclaredEventBehavior {
    std::string when_clause;
    std::string sequence_clause;
    double      sampling_rate = 1.0;
    bool        require_alive = false;
};

struct DeclaredEvent {
    std::string name;
    std::vector<std::string> props_extends;
    std::string target;
    std::unordered_map<std::string, std::string> default_props;
    std::unordered_map<std::string, std::string> props_exprs;
    std::unordered_set<std::string> required_props;
    DeclaredEventBehavior behavior;
    bool perf_stat   = false;
    bool ignore_null = true;
    double sampling  = 1.0;
};

struct DeclaredManifest {
    std::string version = "1.0.0";
    bool        enabled = true;
    std::unordered_map<std::string, DeclaredEvent> events;
    std::unordered_map<std::string, std::string>   extra_mappings;
};

// ============================================================================
// [EN] 7. SparkTracing Performance Telemetry (spark_tracing_stat)
//      Reconstructed from .rodata 0x00d895..0x00d915:
//        "version", "elapse_ms", "prop_total", "prop_valid",
//        "prop_required_total", "prop_required_valid", "char_size"
// [VN] 7. Thống kê Hiệu năng SparkTracing (spark_tracing_stat)
//      Tái dựng từ .rodata 0x00d895..0x00d915.
// ============================================================================
struct SparkTracingPerfStat {
    std::string version;
    uint64_t    elapse_ms           = 0ULL;
    uint32_t    prop_total          = 0U;
    uint32_t    prop_valid          = 0U;
    uint32_t    prop_required_total = 0U;
    uint32_t    prop_required_valid = 0U;
    uint32_t    char_size           = 0U;

    std::string ToJson() const;
};

// ============================================================================
// [EN] 8. Native Client & Config Callback Interface (bdhm_native::api::glue)
//      Reconstructed from .rodata 0x00c9f8..0x00cc87:
//        - SparkTracingNativeConfig methods:
//          isLogEnable()Z, isRecordUsedPropertyOnly()Z,
//          isReferenceMappingEnabled()Z, getManifestSrc()Ljava/lang/String;,
//          getReferenceMapSrc()Ljava/lang/String;,
//          getRepoDbStoragePath()Ljava/lang/String;,
//          getReferencesUsed()[Ljava/lang/String;,
//          getRepoSize()J, getPulseInterval()J
//        - SparkTracingNativeClient methods:
//          onEvent(ILjava/lang/String;Ljava/lang/String;)V
//          onPropertyChanged(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
// [VN] 8. Giao diện Callback Client & Cấu hình Native (bdhm_native::api::glue)
// ============================================================================
struct SparkTracingConfigData {
    bool        is_log_enable                = false;
    bool        is_record_used_property_only = false;
    bool        is_reference_mapping_enabled = false;
    std::string manifest_src;
    std::string reference_map_src;
    std::string repo_db_storage_path;
    std::vector<std::string> references_used;
    uint32_t    repo_size                    = static_cast<uint32_t>(kDefaultMaxContextPropsCount);
    uint64_t    pulse_interval_ms            = kDefaultPulseIntervalMillis;
};

class ISparkTracingNativeClient {
public:
    virtual ~ISparkTracingNativeClient() = default;
    virtual void OnEvent(int32_t level, const std::string& event_name, const std::string& payload_json) = 0;
    virtual void OnPropertyChanged(const std::string& context_id, const std::string& key, const std::string& val) = 0;
};

} // namespace BdhmNative
} // namespace OpenCut
} // namespace NextAI
