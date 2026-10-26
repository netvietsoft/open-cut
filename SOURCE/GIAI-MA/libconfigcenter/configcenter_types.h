// ============================================================================
// File: configcenter_types.h
// Library: libconfigcenter.so (51,144 bytes, 65 dynamic symbols, ARM64-v8a)
// Task ID: TASK-089-RECONSTRUCTION-LIBCONFIGCENTER (Target 50 / TASK_SO_150)
// Description:
//   EN: Exact AArch64 ABI structures, virtual method tables (.data.rel.ro
//       0x0f8d0..0x0fc48), JNI registration descriptors (.data 0x10000..0x10030),
//       .rodata string offsets (0x068a8..0x06e16), and Json::Value / BaseRef
//       primitives for com::tiktok::ttkmedia::configcenter.
//   VN: Các cấu trúc ABI AArch64 chính xác, bảng phương thức ảo (.data.rel.ro
//       0x0f8d0..0x0fc48), bộ mô tả đăng ký JNI (.data 0x10000..0x10030),
//       offset chuỗi .rodata (0x068a8..0x06e16), và các nguyên hàm Json::Value /
//       BaseRef cho com::tiktok::ttkmedia::configcenter.
// ============================================================================

#pragma once

#include <jni.h>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace com {
namespace ss {
namespace vcbkit {

// ============================================================================
// EN: com::ss::vcbkit::BaseRef (16 bytes = 0x10)
//     Base reference-counted object imported from libvcbasekit.so.
//     - +0x00: vtable pointer (8 bytes)
//     - +0x08: std::atomic<int32_t> ref_count_ (initialized to 1 at 0x0266c:
//              mov w8, #1; str w8, [x0, #8])
//     - Weak RTTI exported by libconfigcenter.so:
//       * _ZTSN3com2ss6vcbkit7BaseRefE @ 0x068d5 (25 bytes)
//       * _ZTIN3com2ss6vcbkit7BaseRefE @ 0x0f998 (16 bytes)
// VN: com::ss::vcbkit::BaseRef (16 byte = 0x10)
//     Đối tượng đếm tham chiếu cơ sở được nhập từ libvcbasekit.so.
//     - +0x00: con trỏ vtable (8 byte)
//     - +0x08: std::atomic<int32_t> ref_count_ (khởi tạo bằng 1 tại 0x0266c)
// ============================================================================
class BaseRef {
public:
    BaseRef() noexcept : ref_count_(1), reserved_pad_(0) {}
    virtual ~BaseRef() = default;

    void addRef() noexcept {
        ref_count_.fetch_add(1, std::memory_order_relaxed);
    }

    int32_t getRefCount() const noexcept {
        return ref_count_.load(std::memory_order_acquire);
    }

public:
    std::atomic<int32_t> ref_count_; // +0x08 (verified at 0x02670, 0x026c4, 0x02740)
    int32_t reserved_pad_;           // +0x0c
};

// ============================================================================
// EN: com::ss::vcbkit::UnSafe::decRef(BaseRef*) (PLT 0x02580 -> GOT 0x0ff98)
//     Called by BaseConfig JNI _release (0x059d4: cbz x2, #0x59e0; mov x0, x2;
//     b #0x02580). Decrements ref_count_ and deletes when reaching 0.
// VN: com::ss::vcbkit::UnSafe::decRef(BaseRef*) (PLT 0x02580 -> GOT 0x0ff98)
//     Được gọi bởi hàm JNI _release của BaseConfig (0x059d4). Giảm ref_count_
//     và giải phóng đối tượng khi về 0.
// ============================================================================
struct UnSafe {
    static void decRef(BaseRef* ref) noexcept {
        if (!ref) {
            return;
        }
        if (ref->ref_count_.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete ref;
        }
    }
};

} // namespace vcbkit
} // namespace ss
} // namespace com

// ============================================================================
// EN: Json::Value (Imported from libvcbasekit.so via 15 PLT entries)
//     Size in binary: 40 bytes (0x28) inside ConfigItem (+0x18..+0x40).
//     Imported symbols in .dynsym / .rela.plt:
//       - _ZN4Json5ValueC1ENS_9ValueTypeE (0x024c0)
//       - _ZN4Json5ValueC1Ei              (0x02400)
//       - _ZN4Json5ValueC1El              (0x02570)
//       - _ZN4Json5ValueC1Ed              (0x02390)
//       - _ZN4Json5ValueC1EPKc            (0x024f0)
//       - _ZN4Json5ValueC1ERKNSt6__ndk112basic_string... (0x02440)
//       - _ZN4Json5ValueC1ERKS0_          (0x023d0)
//       - _ZN4Json5ValueC1EOS0_           (0x023f0)
//       - _ZN4Json5ValueD1Ev              (0x023b0)
//       - _ZN4Json5ValueaSES0_            (0x024a0)
//       - _ZNK4Json5Value5asIntEv         (0x023e0)
//       - _ZNK4Json5Value7asInt64Ev       (0x02450)
//       - _ZNK4Json5Value7asFloatEv       (0x025c0)
//       - _ZNK4Json5Value8asStringEv      (0x02370)
//       - _ZNK4Json5Value6isNullEv        (0x02470)
//       - _ZNK4Json5Value5emptyEv         (0x02550)
//       - _ZN4Json5ValueixEPKc            (0x02500)
//       - _ZN4Json5Value6appendERKS0_     (0x025d0)
// VN: Json::Value (Nhập từ libvcbasekit.so qua 15 mục PLT)
//     Kích thước trong binary: 40 byte (0x28) bên trong ConfigItem (+0x18..+0x40).
// ============================================================================
namespace Json {

enum ValueType : int32_t {
    nullValue = 0,     // Verified at 0x03b0c, 0x05e70, 0x0624c (mov w1, wzr; bl 0x024c0)
    intValue = 1,
    uintValue = 2,
    realValue = 3,
    stringValue = 4,
    booleanValue = 5,
    arrayValue = 6,
    objectValue = 7
};

class Value {
public:
    // _ZN4Json5ValueC1ENS_9ValueTypeE @ PLT 0x024c0
    explicit Value(ValueType type = nullValue) noexcept
        : type_(type), int_val_(0), double_val_(0.0) {}

    // _ZN4Json5ValueC1Ei @ PLT 0x02400
    explicit Value(int32_t v) noexcept
        : type_(intValue), int_val_(v), double_val_(static_cast<double>(v)) {}

    // _ZN4Json5ValueC1El @ PLT 0x02570
    explicit Value(int64_t v) noexcept
        : type_(intValue), int_val_(v), double_val_(static_cast<double>(v)) {}

    // _ZN4Json5ValueC1Ed @ PLT 0x02390
    explicit Value(double v) noexcept
        : type_(realValue), int_val_(static_cast<int64_t>(v)), double_val_(v) {}

    // _ZN4Json5ValueC1EPKc @ PLT 0x024f0
    explicit Value(const char* s)
        : type_(stringValue),
          int_val_(0),
          double_val_(0.0),
          str_val_(s ? s : "") {}

    // _ZN4Json5ValueC1ERKNSt6__ndk112basic_string... @ PLT 0x02440
    explicit Value(const std::string& s)
        : type_(stringValue),
          int_val_(0),
          double_val_(0.0),
          str_val_(s) {}

    // _ZN4Json5ValueC1ERKS0_ @ PLT 0x023d0
    Value(const Value& other) = default;

    // _ZN4Json5ValueC1EOS0_ @ PLT 0x023f0
    Value(Value&& other) noexcept = default;

    // _ZN4Json5ValueD1Ev @ PLT 0x023b0
    ~Value() = default;

    // _ZN4Json5ValueaSES0_ @ PLT 0x024a0
    Value& operator=(Value other) noexcept {
        swap(other);
        return *this;
    }

    void swap(Value& other) noexcept {
        std::swap(type_, other.type_);
        std::swap(int_val_, other.int_val_);
        std::swap(double_val_, other.double_val_);
        std::swap(str_val_, other.str_val_);
        std::swap(arr_val_, other.arr_val_);
        std::swap(obj_val_, other.obj_val_);
    }

    // _ZNK4Json5Value6isNullEv @ PLT 0x02470
    bool isNull() const noexcept {
        return type_ == nullValue;
    }

    // _ZNK4Json5Value5emptyEv @ PLT 0x02550
    bool empty() const noexcept {
        switch (type_) {
            case nullValue:
                return true;
            case stringValue:
                return str_val_.empty();
            case arrayValue:
                return arr_val_.empty();
            case objectValue:
                return obj_val_.empty();
            default:
                return false;
        }
    }

    // _ZNK4Json5Value5asIntEv @ PLT 0x023e0
    int32_t asInt() const noexcept {
        if (type_ == intValue || type_ == uintValue || type_ == booleanValue) {
            return static_cast<int32_t>(int_val_);
        }
        if (type_ == realValue) {
            return static_cast<int32_t>(double_val_);
        }
        return 0;
    }

    // _ZNK4Json5Value7asInt64Ev @ PLT 0x02450
    int64_t asInt64() const noexcept {
        if (type_ == intValue || type_ == uintValue || type_ == booleanValue) {
            return int_val_;
        }
        if (type_ == realValue) {
            return static_cast<int64_t>(double_val_);
        }
        return 0;
    }

    // _ZNK4Json5Value7asFloatEv @ PLT 0x025c0
    float asFloat() const noexcept {
        if (type_ == realValue) {
            return static_cast<float>(double_val_);
        }
        if (type_ == intValue || type_ == uintValue || type_ == booleanValue) {
            return static_cast<float>(int_val_);
        }
        return 0.0f;
    }

    // _ZNK4Json5Value8asStringEv @ PLT 0x02370
    std::string asString() const {
        if (type_ == stringValue) {
            return str_val_;
        }
        if (type_ == intValue || type_ == uintValue) {
            return std::to_string(int_val_);
        }
        if (type_ == realValue) {
            return std::to_string(double_val_);
        }
        return std::string();
    }

    // _ZN4Json5ValueixEPKc @ PLT 0x02500
    Value& operator[](const char* key) {
        if (type_ == nullValue) {
            type_ = objectValue;
        }
        return obj_val_[key ? std::string(key) : std::string()];
    }

    const Value& operator[](const char* key) const {
        static const Value kNull(nullValue);
        if (type_ != objectValue || !key) {
            return kNull;
        }
        auto it = obj_val_.find(key);
        return (it != obj_val_.end()) ? it->second : kNull;
    }

    // _ZN4Json5Value6appendERKS0_ @ PLT 0x025d0
    Value& append(const Value& v) {
        if (type_ == nullValue) {
            type_ = arrayValue;
        }
        arr_val_.push_back(v);
        return arr_val_.back();
    }

    ValueType type() const noexcept { return type_; }
    size_t arraySize() const noexcept { return arr_val_.size(); }
    const Value& getElement(size_t idx) const noexcept {
        static const Value kNull(nullValue);
        return (idx < arr_val_.size()) ? arr_val_[idx] : kNull;
    }
    const std::map<std::string, Value>& objectMap() const noexcept { return obj_val_; }

private:
    ValueType type_;
    int64_t int_val_;
    double double_val_;
    std::string str_val_;
    std::vector<Value> arr_val_;
    std::map<std::string, Value> obj_val_;
};

} // namespace Json

namespace com {
namespace tiktok {
namespace ttkmedia {
namespace configcenter {

// ============================================================================
// EN: ELF64 Segment, Section & .rodata Address Constants of libconfigcenter.so
// VN: Hằng số địa chỉ Segment, Section & .rodata ELF64 của libconfigcenter.so
// ============================================================================
namespace binary_addrs {

// Segments & Sections
constexpr uint64_t kPtLoad0Vaddr               = 0x00000ULL;
constexpr uint64_t kPtLoad0Filesz              = 0x07cb0ULL;
constexpr uint64_t kPtLoad1Vaddr               = 0x0f8c0ULL;
constexpr uint64_t kPtLoad1Offset              = 0x0b8c0ULL;
constexpr uint64_t kPtLoad1Filesz              = 0x00770ULL;
constexpr uint64_t kPtLoad1Memsz               = 0x007f8ULL;

constexpr uint64_t kSecPltAddr                 = 0x02330ULL;
constexpr uint64_t kSecTextAddr                = 0x02630ULL;
constexpr uint64_t kSecTextSize                = 0x04270ULL;
constexpr uint64_t kSecRodataAddr              = 0x068a0ULL;
constexpr uint64_t kSecRodataSize              = 0x0058cULL;
constexpr uint64_t kSecFiniArrayAddr           = 0x0f8c0ULL;
constexpr uint64_t kSecDataRelRoAddr           = 0x0f8d0ULL;
constexpr uint64_t kSecDataRelRoSize           = 0x00378ULL;
constexpr uint64_t kSecGotAddr                 = 0x0fe68ULL;
constexpr uint64_t kSecDataAddr                = 0x10000ULL;
constexpr uint64_t kSecBssAddr                 = 0x10030ULL;
constexpr uint64_t kSecBssEndAddr              = 0x100b8ULL;

// .rodata constants & strings (0x068a0..0x06e2c)
constexpr uint64_t kRodataLoadFactorAndPerm    = 0x068a0ULL; // 0x000000003f800000 (1.0f) | (3ULL << 32)
constexpr uint64_t kStrRttiIConfig             = 0x068a8ULL; // "N3com6tiktok8ttkmedia12configcenter7IConfigE"
constexpr uint64_t kStrRttiBaseRef             = 0x068d5ULL; // "N3com2ss6vcbkit7BaseRefE"
constexpr uint64_t kStrRttiBaseConfig          = 0x068eeULL; // "N3com6tiktok8ttkmedia12configcenter10BaseConfigE"
constexpr uint64_t kStrRttiSharedEmplaceItem   = 0x06920ULL; // "NSt6__ndk120__shared_ptr_emplaceIN3com6tiktok8ttkmedia12configcenter10ConfigItemENS_9allocatorIS5_EEEE"
constexpr uint64_t kStrRttiSharedPtrIConfig    = 0x06987ULL; // "NSt6__ndk120__shared_ptr_pointerIPN3com6tiktok8ttkmedia12configcenter7IConfigENS_14default_deleteIS5_EENS_9allocatorIS5_EEEE"
constexpr uint64_t kStrRttiDefaultDeleteIConfig= 0x06a04ULL; // "NSt6__ndk114default_deleteIN3com6tiktok8ttkmedia12configcenter7IConfigEEE"
constexpr uint64_t kStrRttiSharedPtrBaseConfig = 0x06a4eULL; // "NSt6__ndk120__shared_ptr_pointerIPN3com6tiktok8ttkmedia12configcenter10BaseConfigENS_14default_deleteIS5_EENS_9allocatorIS5_EEEE"
constexpr uint64_t kStrRttiDefaultDelBaseCfg   = 0x06acfULL; // "NSt6__ndk114default_deleteIN3com6tiktok8ttkmedia12configcenter10BaseConfigEEE"
constexpr uint64_t kStrLogFormatHeader         = 0x06b1dULL; // "<%p,%s,%s,%d>"
constexpr uint64_t kStrClassBaseConfig         = 0x06b2bULL; // "com/tiktok/ttkmedia/configcenter/BaseConfig"
constexpr uint64_t kStrClassConfigCenter       = 0x06b57ULL; // "com/tiktok/ttkmedia/configcenter/ConfigCenter"
constexpr uint64_t kStrJniCreate               = 0x06b85ULL; // "_create"
constexpr uint64_t kStrSigCreate               = 0x06b8dULL; // "(JII)J"
constexpr uint64_t kStrJniGetIntOption         = 0x06b94ULL; // "_getIntOption"
constexpr uint64_t kStrSigGetIntOption         = 0x06ba2ULL; // "(JII)I"
constexpr uint64_t kStrJniGetLongOption        = 0x06ba9ULL; // "_getLongOption"
constexpr uint64_t kStrSigGetLongOption        = 0x06bb8ULL; // "(JIJ)J"
constexpr uint64_t kStrJniGetFloatOption       = 0x06bbfULL; // "_getFloatOption"
constexpr uint64_t kStrSigGetFloatOption       = 0x06bcfULL; // "(JIF)F"
constexpr uint64_t kStrJniGetStringOption      = 0x06bd6ULL; // "_getStringOption"
constexpr uint64_t kStrSigGetStringOption      = 0x06be7ULL; // "(JI)Ljava/lang/String;"
constexpr uint64_t kStrJniSetIntOption         = 0x06bfeULL; // "_setIntOption"
constexpr uint64_t kStrSigSetIntOption         = 0x06c0cULL; // "(JII)V"
constexpr uint64_t kStrJniSetLongOption        = 0x06c13ULL; // "_setLongOption"
constexpr uint64_t kStrSigSetLongOption        = 0x06c22ULL; // "(JIJ)V"
constexpr uint64_t kStrJniSetFloatOption       = 0x06c29ULL; // "_setFloatOption"
constexpr uint64_t kStrSigSetFloatOption       = 0x06c39ULL; // "(JIF)V"
constexpr uint64_t kStrJniSetStringOption      = 0x06c40ULL; // "_setStringOption"
constexpr uint64_t kStrSigSetStringOption      = 0x06c51ULL; // "(JILjava/lang/String;)V"
constexpr uint64_t kStrJniSetJsonOption        = 0x06c69ULL; // "_setJsonOption"
constexpr uint64_t kStrSigSetJsonOption        = 0x06c78ULL; // "(JILorg/json/JSONObject;)V"
constexpr uint64_t kStrJniIsKeySet             = 0x06c93ULL; // "_isKeySet"
constexpr uint64_t kStrSigIsKeySet             = 0x06c9dULL; // "(JI)Z"
constexpr uint64_t kStrJniResetOptions         = 0x06ca3ULL; // "_resetOptions"
constexpr uint64_t kStrSigResetOptions         = 0x06cb1ULL; // "(JLjava/util/Map;)V"
constexpr uint64_t kStrJniReset                = 0x06cc5ULL; // "_reset"
constexpr uint64_t kStrSigLongToVoid           = 0x06cccULL; // "(J)V"
constexpr uint64_t kStrJniRemove               = 0x06cd1ULL; // "_remove"
constexpr uint64_t kStrSigRemove               = 0x06cd9ULL; // "(JI)V"
constexpr uint64_t kStrJniRelease              = 0x06cdfULL; // "_release"
constexpr uint64_t kStrJniUpdateConfig         = 0x06ce8ULL; // "_updateConfig"
constexpr uint64_t kStrClassJSONObject         = 0x06cf6ULL; // "org/json/JSONObject"
constexpr uint64_t kStrMethodKeys              = 0x06d0aULL; // "keys"
constexpr uint64_t kStrSigKeys                 = 0x06d0fULL; // "()Ljava/util/Iterator;"
constexpr uint64_t kStrMethodOpt               = 0x06d26ULL; // "opt"
constexpr uint64_t kStrSigOpt                  = 0x06d2aULL; // "(Ljava/lang/String;)Ljava/lang/Object;"
constexpr uint64_t kStrClassIterator           = 0x06d51ULL; // "java/util/Iterator"
constexpr uint64_t kStrMethodHasNext           = 0x06d64ULL; // "hasNext"
constexpr uint64_t kStrSigHasNext              = 0x06d6cULL; // "()Z"
constexpr uint64_t kStrMethodNext              = 0x06d70ULL; // "next"
constexpr uint64_t kStrSigNext                 = 0x06d75ULL; // "()Ljava/lang/Object;"
constexpr uint64_t kStrClassString             = 0x06d8aULL; // "java/lang/String"
constexpr uint64_t kStrClassInteger            = 0x06d9bULL; // "java/lang/Integer"
constexpr uint64_t kStrMethodIntValue          = 0x06dadULL; // "intValue"
constexpr uint64_t kStrSigIntValue             = 0x06db6ULL; // "()I"
constexpr uint64_t kStrClassLong               = 0x06dbaULL; // "java/lang/Long"
constexpr uint64_t kStrMethodLongValue         = 0x06dc9ULL; // "longValue"
constexpr uint64_t kStrSigLongValue            = 0x06dd3ULL; // "()J"
constexpr uint64_t kStrClassDouble             = 0x06dd7ULL; // "java/lang/Double"
constexpr uint64_t kStrMethodDoubleValue       = 0x06de8ULL; // "doubleValue"
constexpr uint64_t kStrSigDoubleValue          = 0x06df4ULL; // "()D"
constexpr uint64_t kStrClassJSONArray          = 0x06df8ULL; // "org/json/JSONArray"
constexpr uint64_t kStrMethodLength            = 0x06e0bULL; // "length"
constexpr uint64_t kStrMethodGet               = 0x06e12ULL; // "get"
constexpr uint64_t kStrSigGet                  = 0x06e16ULL; // "(I)Ljava/lang/Object;"

// .data.rel.ro vtables & JNI tables (0x0f8d0..0x0fc48)
constexpr uint64_t kDsoHandleAddr              = 0x0f8d0ULL;
constexpr uint64_t kVtableBaseConfig           = 0x0f8e8ULL; // 22 virtual functions (0x0f8e8..0x0f990)
constexpr uint64_t kTypeinfoBaseRef            = 0x0f998ULL;
constexpr uint64_t kTypeinfoIConfig            = 0x0f9a8ULL;
constexpr uint64_t kTypeinfoBaseConfig         = 0x0f9c0ULL;
constexpr uint64_t kVtableSharedEmplaceItem    = 0x0f9e8ULL;
constexpr uint64_t kVtableSharedPtrIConfig     = 0x0fa38ULL;
constexpr uint64_t kVtableSharedPtrBaseConfig  = 0x0fa88ULL;
constexpr uint64_t kJniMethodsBaseConfig       = 0x0fac8ULL; // 15 JNINativeMethod entries (0x0fac8..0x0fc30)
constexpr uint64_t kJniMethodsConfigCenter     = 0x0fc30ULL; // 1 JNINativeMethod entry (0x0fc30..0x0fc48)

// .data & .bss globals
constexpr uint64_t kDataJniRegBaseConfig       = 0x10000ULL; // {0x06b2b, 15, 0x0fac8}
constexpr uint64_t kDataJniRegConfigCenter     = 0x10018ULL; // {0x06b57, 1, 0x0fc30}
constexpr uint64_t kBssSingletonInstance       = 0x10030ULL; // ConfigCenter singleton (128 bytes: 0x10030..0x100b0)
constexpr uint64_t kBssSingletonGuard          = 0x100b0ULL; // __cxa_guard_acquire guard (8 bytes: 0x100b0..0x100b8)

} // namespace binary_addrs

// ============================================================================
// EN: ConfigModule enum (verified at 0x04fd8, 0x05044, 0x050a8, and 0x052f4..0x05304)
//     - PLAYER = 2 (stored at ConfigCenter + 0x00, retrieved by getPlayerConfig @ 0x05168)
//     - MDL = 3 (stored at ConfigCenter + 0x10, retrieved by getMdlConfig @ 0x051c8)
//     - STRATEGY_CENTER = 4 (stored at ConfigCenter + 0x20, retrieved by getStrategyCenterConfig @ 0x05228)
// VN: Enum ConfigModule (đối chiếu tại 0x04fd8, 0x05044, 0x050a8 và 0x052f4..0x05304)
// ============================================================================
enum ConfigModule : int32_t {
    CONFIG_MODULE_UNKNOWN         = 0,
    CONFIG_MODULE_COMMON          = 1,
    CONFIG_MODULE_PLAYER          = 2, // Verified at 0x04fd8 (mov w1, #2) & 0x05304 (cmp w20, #2)
    CONFIG_MODULE_MDL             = 3, // Verified at 0x05044 (mov w1, #3) & 0x052fc (cmp w20, #3)
    CONFIG_MODULE_STRATEGY_CENTER = 4  // Verified at 0x050a8 (mov w1, #4) & 0x052f4 (cmp w0, #4)
};

// ============================================================================
// EN: Priority enum (verified at 0x02a30, 0x02c80, 0x02ed8, 0x031b0, 0x03cf0:
//     cmp w_this_priority, w_item_priority; b.lt skip_update)
//     Higher or equal priority overwrites existing ConfigItem.
// VN: Enum Priority (đối chiếu tại 0x02a30, 0x02c80, 0x02ed8, 0x031b0, 0x03cf0)
//     Độ ưu tiên lớn hơn hoặc bằng sẽ ghi đè ConfigItem hiện có.
// ============================================================================
enum Priority : int32_t {
    PRIORITY_DEFAULT  = 0, // Verified at 0x04fdc, 0x05048, 0x050ac (mov w2, wzr)
    PRIORITY_LOW      = 1,
    PRIORITY_NORMAL   = 2,
    PRIORITY_HIGH     = 3,
    PRIORITY_CRITICAL = 4
};

// ============================================================================
// EN: Permission bitmask stored at BaseConfig + 0x40 (std::atomic<int32_t>):
//     - Bit 0 (0x1): READABLE (checked via tbz w8, #0 at 0x03388, 0x03454,
//                    0x03520, 0x035f4, 0x03710, 0x03a58)
//     - Bit 1 (0x2): WRITABLE (checked via tbz w8, #1 at 0x0288c, 0x02adc,
//                    0x02d30, 0x02f88, 0x03850, 0x039a4, 0x03b4c, 0x03da4, 0x03ea8)
//     - Initial value in BaseConfig ctor (0x0268c): 3 (PERM_READ_WRITE)
//     - Frozen value set by ConfigCenter::updateConfig (0x052d0, 0x05380): 1 (PERM_READ_ONLY)
// VN: Mặt nạ bit quyền hạn lưu tại BaseConfig + 0x40 (std::atomic<int32_t>):
//     - Bit 0 (0x1): READABLE (quyền đọc)
//     - Bit 1 (0x2): WRITABLE (quyền ghi)
//     - Giá trị khởi tạo trong BaseConfig ctor (0x0268c): 3 (PERM_READ_WRITE)
//     - Giá trị đóng băng khi gọi ConfigCenter::updateConfig (0x052d0, 0x05380): 1 (PERM_READ_ONLY)
// ============================================================================
enum ConfigPermission : int32_t {
    PERM_NONE       = 0,
    PERM_READ_ONLY  = 1, // 0b01: bit 0 set, bit 1 clear (immutable after updateConfig)
    PERM_WRITE_ONLY = 2, // 0b10: bit 1 set
    PERM_READ_WRITE = 3  // 0b11: bit 0 and bit 1 set (default in BaseConfig ctor @ 0x0268c)
};

// ============================================================================
// EN: ConfigItem (payload inside 72-byte = 0x48 std::__shared_ptr_emplace<ConfigItem>)
//     Allocated at 0x02944, 0x02b94, 0x02de8, 0x030ac, 0x03c04:
//       - +0x00..+0x17: std::__shared_weak_count header (24 bytes, vtable 0x0f9e8)
//       - +0x18..+0x3f: Json::Value value_ (40 bytes)
//       - +0x40..+0x43: Priority priority_ (4 bytes, offset +0x28 from ConfigItem*)
// VN: ConfigItem (dữ liệu bên trong khối 72 byte = 0x48 std::__shared_ptr_emplace<ConfigItem>)
// ============================================================================
struct ConfigItem {
    Json::Value value_; // +0x00 (at alloc + 0x18)
    Priority priority_; // +0x28 (at alloc + 0x40, verified at 0x02990 & 0x02a2c)

    ConfigItem() noexcept : value_(Json::nullValue), priority_(PRIORITY_DEFAULT) {}
    ConfigItem(const Json::Value& v, Priority p) : value_(v), priority_(p) {}
    ConfigItem(Json::Value&& v, Priority p) noexcept : value_(std::move(v)), priority_(p) {}
};

// ============================================================================
// EN: IConfig — Abstract interface (inherits from com::ss::vcbkit::BaseRef)
//     RTTI at 0x0f9a8 ("N3com6tiktok8ttkmedia12configcenter7IConfigE" @ 0x068a8).
//     Exact 22-entry vtable layout verified from .data.rel.ro (0x0f8e8..0x0f990)
//     and JNI dispatch offsets (0x0572c..0x059d0) + ConfigCenter::updateConfig (0x052c8..0x0538c):
//       Slot 0  (+0x00): ~IConfig() [complete object dtor]
//       Slot 1  (+0x08): ~IConfig() [deleting dtor]
//       Slot 2  (+0x10): bool isKeySet(int key) const
//       Slot 3  (+0x18): int32_t getIntOption(int key, int32_t defaultVal) const
//       Slot 4  (+0x20): int64_t getLongOption(int key, int64_t defaultVal) const
//       Slot 5  (+0x28): float getFloatOption(int key, float defaultVal) const
//       Slot 6  (+0x30): int32_t getFloatOption(int key, float* outVal) const
//       Slot 7  (+0x38): std::string getStringOption(int key) const
//       Slot 8  (+0x40): Json::Value getJsonOption(int key) const
//       Slot 9  (+0x48): void setIntOption(int key, int32_t val)
//       Slot 10 (+0x50): void setLongOption(int key, int64_t val)
//       Slot 11 (+0x58): void setFloatOption(int key, float val)
//       Slot 12 (+0x60): void setStringOption(int key, const char* val)
//       Slot 13 (+0x68): void setJsonOption(int key, const Json::Value& val)
//       Slot 14 (+0x70): void remove(int key)
//       Slot 15 (+0x78): void reset()
//       Slot 16 (+0x80): size_t size() const
//       Slot 17 (+0x88): int32_t mergeFrom(IConfig* other)
//       Slot 18 (+0x90): int32_t copyFrom(IConfig* other, bool deepCopy)
//       Slot 19 (+0x98): void setPermission(int32_t permission)
//       Slot 20 (+0xa0): ConfigModule getModule() const
//       Slot 21 (+0xa8): Priority getPriority() const
// VN: IConfig — Giao diện trừu tượng (kế thừa từ com::ss::vcbkit::BaseRef)
//     Bố cục vtable 22 mục chính xác được xác minh từ .data.rel.ro (0x0f8e8..0x0f990).
// ============================================================================
class IConfig : public com::ss::vcbkit::BaseRef {
public:
    ~IConfig() override = default;

    virtual bool isKeySet(int key) const = 0;                                    // +0x10
    virtual int32_t getIntOption(int key, int32_t defaultVal) const = 0;         // +0x18
    virtual int64_t getLongOption(int key, int64_t defaultVal) const = 0;        // +0x20
    virtual float getFloatOption(int key, float defaultVal) const = 0;           // +0x28
    virtual int32_t getFloatOption(int key, float* outVal) const = 0;            // +0x30
    virtual std::string getStringOption(int key) const = 0;                      // +0x38
    virtual Json::Value getJsonOption(int key) const = 0;                        // +0x40
    virtual void setIntOption(int key, int32_t val) = 0;                         // +0x48
    virtual void setLongOption(int key, int64_t val) = 0;                        // +0x50
    virtual void setFloatOption(int key, float val) = 0;                         // +0x58
    virtual void setStringOption(int key, const char* val) = 0;                  // +0x60
    virtual void setJsonOption(int key, const Json::Value& val) = 0;             // +0x68
    virtual void remove(int key) = 0;                                            // +0x70
    virtual void reset() = 0;                                                    // +0x78
    virtual size_t size() const = 0;                                             // +0x80
    virtual int32_t mergeFrom(IConfig* other) = 0;                               // +0x88
    virtual int32_t copyFrom(IConfig* other, bool deepCopy) = 0;                 // +0x90
    virtual void setPermission(int32_t permission) = 0;                          // +0x98
    virtual ConfigModule getModule() const = 0;                                  // +0xa0
    virtual Priority getPriority() const = 0;                                    // +0xa8
};

// ============================================================================
// EN: IConfigCenterListener — Observer notified on ConfigCenter::updateConfig
//     Verified at 0x053f8..0x05410:
//       add x8, x19, w20, sxtw #3
//       ldr x0, [x8, #0x58]
//       cbz x0, #0x5414
//       ldr x8, [x0]
//       mov w1, w20
//       ldr x8, [x8, #0x10]
//       blr x8
// VN: IConfigCenterListener — Bộ lắng nghe được thông báo khi gọi updateConfig
// ============================================================================
class IConfigCenterListener {
public:
    virtual ~IConfigCenterListener() = default;                 // +0x00, +0x08
    virtual void onConfigUpdated(ConfigModule module) = 0;      // +0x10 (verified at 0x0540c)
};

// ============================================================================
// EN: JniClassRegistration — 24-byte struct in .data (0x10000 and 0x10018)
//     Used by RegisterNativesHelper (0x05a08) and JNI_OnLoad (0x05a84).
//     - +0x00: const char* class_name (0x06b2b or 0x06b57)
//     - +0x08: int32_t num_methods (15 or 1)
//     - +0x10: const JNINativeMethod* methods (0x0fac8 or 0x0fc30)
// VN: JniClassRegistration — Cấu trúc 24 byte trong .data (0x10000 và 0x10018)
// ============================================================================
struct JniClassRegistration {
    const char* class_name;            // +0x00
    int32_t num_methods;               // +0x08
    int32_t pad0;                      // +0x0c
    const JNINativeMethod* methods;    // +0x10
};

} // namespace configcenter
} // namespace ttkmedia
} // namespace tiktok
} // namespace com
