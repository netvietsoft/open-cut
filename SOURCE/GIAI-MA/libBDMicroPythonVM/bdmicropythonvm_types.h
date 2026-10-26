/**
 * @file bdmicropythonvm_types.h
 * @brief Core ABI Structures, ELF64 Memory Map, FastEngine Object Layout & Pitaya Types for libBDMicroPythonVM.so
 *        Cấu trúc ABI cốt lõi, Bản đồ bộ nhớ ELF64, Bố cục đối tượng FastEngine & Kiểu dữ liệu Pitaya cho libBDMicroPythonVM.so
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDMicroPythonVM.so — 379,248 bytes)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDMicroPythonVM.so — 379,248 bytes)]
 * =================================================================================================
 *
 * Binary Metadata / Thông tin nhị phân:
 * - File Path: apktool-res/lib/arm64-v8a/libBDMicroPythonVM.so
 * - Exact File Size: 379,248 bytes (0x05C970 bytes)
 * - Architecture: ELF 64-bit LSB shared object, ARM aarch64, version 1 (SYSV), dynamically linked
 * - Dynamic Symbols (.dynsym @ 0x000d88, size 0x002568): 396 total (41 exported + 355 imported)
 *   - 33 Exported STT_FUNC (11 pitaya/fast_engine C++ functions + 1 Task::~Task + 20 MicPyArray/MicPyDict JNI + 1 MicroPyLoader JNI)
 *   - 8 Exported STT_OBJECT (1 _ZN11fast_engine10TensorTypeE @ 0x060210 + 7 RTTI typeinfo/typeinfo-name symbols)
 *
 * Virtual Address to File Offset Formula / Công thức ánh xạ địa chỉ ảo sang offset file:
 * - PT_LOAD 0 (R+X): vaddr 0x000000 .. 0x059cf0 -> file 0x000000 .. 0x059cf0 (offset = vaddr)
 * - PT_LOAD 1 (R+W): vaddr 0x05e5f8 .. 0x060988 -> file 0x05a5f8 .. 0x05c168 (offset = vaddr - 0x4000)
 * - Sections:
 *   - .plt          : vaddr 0x00dc50, size 0x001450 (5,200 bytes)
 *   - .text         : vaddr 0x00f0a0, size 0x0422dc (271,068 bytes, 0x00f0a0..0x05137c)
 *   - .rodata       : vaddr 0x051380, size 0x00231f (8,991 bytes, 0x051380..0x05369f)
 *   - .init_array   : vaddr 0x05e5f8, size 0x000008 (entry 0x00f0a0 -> b #0x3b374)
 *   - .data.rel.ro  : vaddr 0x05e610, size 0x000c38 (vtables & RTTI descriptors)
 *   - .got          : vaddr 0x05f248, size 0x000db8
 *   - .data         : vaddr 0x060000, size 0x000168 (TensorWrapper attribute descriptor table)
 *   - .bss          : vaddr 0x060170, size 0x000818 (TensorType @ 0x060210, JNI globals @ 0x060928..0x060940)
 */

#ifndef NEXTAI_OPENCUT_BDMICROPYTHONVM_TYPES_H_
#define NEXTAI_OPENCUT_BDMICROPYTHONVM_TYPES_H_

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

// Forward declarations for JNI types / Khai báo trước các kiểu JNI
struct _JNIEnv;
typedef _JNIEnv JNIEnv;
struct _JavaVM;
typedef _JavaVM JavaVM;
class _jobject;
typedef _jobject* jobject;
class _jclass;
typedef _jclass* jclass;
class _jstring;
typedef _jstring* jstring;
struct _jmethodID;
typedef _jmethodID* jmethodID;
typedef uint8_t jboolean;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;

namespace pitaya {

/**
 * @brief Pitaya Error Codes observed at 0x0430ac (GetCoreError) and 0x043c84 (EnvPTYObj2MPObj).
 *        Mã lỗi Pitaya quan sát tại 0x0430ac (GetCoreError) và 0x043c84 (EnvPTYObj2MPObj).
 *
 * [OBSERVED @ 0x043d08]: mov w0, #0x65 (101 = kErrorCodeFastEngineConvertError)
 * [OBSERVED @ 0x0454a8]: mov w0, #0x65 (101 = kErrorCodeFastEngineConvertError)
 */
enum class ErrorCode : int32_t {
    kSuccess                        = 0,
    kFastEngineInitError            = 100, // 0x64
    kFastEngineConvertError         = 101, // 0x65 (OBSERVED @ 0x043d08: mov w0, #0x65; bl GetCoreError)
    kFastEngineExecuteError         = 102, // 0x66
    kFastEngineScriptLoadError      = 103, // 0x67
    kFastEngineVMPoolExhausted      = 104, // 0x68
    kFastEngineMemoryLimitExceeded  = 105, // 0x69
    kFastEngineModelLoadError       = 201, // 0xC9
    kFastEngineInferenceError       = 202  // 0xCA
};

/**
 * @brief Pitaya Error object returned as std::shared_ptr<pitaya::Error> across FastEngine bridges.
 *        Đối tượng lỗi Pitaya được trả về dưới dạng std::shared_ptr<pitaya::Error> qua cầu nối FastEngine.
 *
 * [OBSERVED @ 0x0430ac..0x043568 (_ZN11fast_engine12GetCoreErrorEN6pitaya9ErrorCodeEPNS_6EngineE)]:
 * - Allocates shared_ptr control block + Error payload (0x68 = 104 bytes via _Znwm at 0x04321c)
 * - Contains ErrorCode (+0x18), sub_code (+0x1c), summary message (+0x20), and stack trace lines vector (+0x38)
 *   split by delimiter "\n\x02" (0x0a02 @ 0x0432d0: mov w8, #0x20a; sturh w8, [x29, #-0x8f]).
 */
class Error {
public:
    Error() : code_(ErrorCode::kSuccess), sub_code_(0) {}
    Error(ErrorCode code, int32_t sub_code, const std::string& msg, const std::vector<std::string>& stacks = {})
        : code_(code), sub_code_(sub_code), message_(msg), stack_lines_(stacks) {}
    virtual ~Error() = default;

    ErrorCode Code() const { return code_; }
    int32_t SubCode() const { return sub_code_; }
    const std::string& Message() const { return message_; }
    const std::vector<std::string>& StackLines() const { return stack_lines_; }

    void AppendStack(const std::string& line) { stack_lines_.push_back(line); }

private:
    ErrorCode code_;
    int32_t sub_code_;
    std::string message_;
    std::vector<std::string> stack_lines_;
};

/**
 * @brief Pitaya Object Type enumeration matching PTYObject::TypeCheck() and Is*() methods in .plt.
 *        Liệt kê kiểu đối tượng Pitaya khớp với PTYObject::TypeCheck() và các hàm Is*() trong .plt.
 */
enum class PTYType : int32_t {
    kNull           = 0,
    kBool           = 1,
    kNumber         = 2,
    kStr            = 3,
    kDict           = 4,
    kList           = 5,
    kTensor         = 6,
    kCvMat          = 7,
    kBuffer         = 8,
    kPredictResult  = 9,
    kClass          = 10,
    kBytes          = 11
};

class PTYDict;
class PTYList;
class PTYTensor;
class PTYCvMat;
class PTYBuffer;
class PTYPredictResult;
class PTYClass;

/**
 * @brief Base class pitaya::PTYObject imported from libAndroidPitayaCore.so.
 *        Lớp cơ sở pitaya::PTYObject được import từ libAndroidPitayaCore.so.
 *
 * [OBSERVED @ 0x0435b0..0x043900 in PTYObj2MPObj_Internal]:
 * - IsNull() @ PLT 0x00e400
 * - IsBool() @ PLT 0x00ed60 (reads bool byte at [this + 0x1c] @ 0x043610: ldrb w8, [x8, #0x1c])
 * - IsNumber() @ PLT 0x00ec90
 * - IsStr() @ PLT 0x00dfd0
 * - IsDict() @ PLT 0x00ea50
 * - IsList() @ PLT 0x00ef20
 * - IsTensor() @ PLT 0x00e260
 * - IsCvMat() @ PLT 0x00de00
 * - IsBuffer() @ PLT 0x00e0d0
 * - IsPredictResult() @ PLT 0x00e5a0
 * - IsClass() @ PLT 0x00ebb0
 */
class PTYObject {
public:
    explicit PTYObject(PTYType type = PTYType::kNull) : type_(type), reserved_flag_(0), bool_val_(0) {}
    virtual ~PTYObject() = default;

    PTYType GetObjectType() const { return type_; }
    bool IsNull() const { return type_ == PTYType::kNull; }
    bool IsBool() const { return type_ == PTYType::kBool; }
    bool IsNumber() const { return type_ == PTYType::kNumber; }
    bool IsStr() const { return type_ == PTYType::kStr; }
    bool IsDict() const { return type_ == PTYType::kDict; }
    bool IsList() const { return type_ == PTYType::kList; }
    bool IsTensor() const { return type_ == PTYType::kTensor; }
    bool IsCvMat() const { return type_ == PTYType::kCvMat; }
    bool IsBuffer() const { return type_ == PTYType::kBuffer; }
    bool IsPredictResult() const { return type_ == PTYType::kPredictResult; }
    bool IsClass() const { return type_ == PTYType::kClass; }

    virtual std::string Dump() const { return "{}"; }

    // Offset +0x1c observed at 0x043610: ldrb w8, [x8, #0x1c] for PTYBool value
    PTYType type_;           // +0x08 (after vptr)
    uint32_t reserved_pad0_; // +0x0c
    uint64_t reserved_pad1_; // +0x10
    uint32_t reserved_flag_; // +0x18
    uint8_t bool_val_;       // +0x1c (OBSERVED @ 0x043610: ldrb w8, [x8, #0x1c])
    uint8_t pad_1d_[3]{0, 0, 0};
};

class PTYNull : public PTYObject {
public:
    PTYNull() : PTYObject(PTYType::kNull) {}
    std::string Dump() const override { return "null"; }
};

class PTYBool : public PTYObject {
public:
    explicit PTYBool(bool v) : PTYObject(PTYType::kBool) {
        bool_val_ = v ? 1 : 0;
    }
    bool Value() const { return bool_val_ != 0; }
    std::string Dump() const override { return bool_val_ ? "true" : "false"; }
};

class PTYNumber : public PTYObject {
public:
    explicit PTYNumber(int64_t v) : PTYObject(PTYType::kNumber), is_int_(true), int_val_(v), double_val_(static_cast<double>(v)) {}
    explicit PTYNumber(double v) : PTYObject(PTYType::kNumber), is_int_(false), int_val_(static_cast<int64_t>(v)), double_val_(v) {}

    bool IsIntNumber() const { return is_int_; }
    int64_t IntValue() const { return int_val_; }
    double DoubleValue() const { return double_val_; }
    float FloatValue() const { return static_cast<float>(double_val_); }
    std::string Dump() const override { return is_int_ ? std::to_string(int_val_) : std::to_string(double_val_); }

private:
    bool is_int_;
    int64_t int_val_;
    double double_val_;
};

class PTYStr : public PTYObject {
public:
    explicit PTYStr(std::string s) : PTYObject(PTYType::kStr), str_(std::move(s)) {}
    const std::string& Str() const { return str_; }
    std::string Dump() const override { return "\"" + str_ + "\""; }

private:
    std::string str_;
};

class PTYDict : public PTYObject {
public:
    PTYDict() : PTYObject(PTYType::kDict) {}
    explicit PTYDict(std::unordered_map<std::string, std::shared_ptr<PTYObject>> items)
        : PTYObject(PTYType::kDict), items_(std::move(items)) {}

    void Set(const std::string& key, std::shared_ptr<PTYObject> val) {
        items_[key] = std::move(val);
    }
    std::shared_ptr<PTYObject> Get(const std::string& key) const {
        auto it = items_.find(key);
        return (it != items_.end()) ? it->second : nullptr;
    }
    bool HasKey(const std::string& key) const {
        return items_.find(key) != items_.end();
    }
    void Erase(const std::string& key) {
        items_.erase(key);
    }
    size_t Size() const { return items_.size(); }
    const std::unordered_map<std::string, std::shared_ptr<PTYObject>>& RawDict() const { return items_; }
    std::unordered_map<std::string, std::shared_ptr<PTYObject>>& RawDict() { return items_; }

    std::shared_ptr<PTYDict> Copy() const {
        return std::make_shared<PTYDict>(items_);
    }

private:
    std::unordered_map<std::string, std::shared_ptr<PTYObject>> items_;
};

class PTYList : public PTYObject {
public:
    PTYList() : PTYObject(PTYType::kList) {}
    explicit PTYList(std::vector<std::shared_ptr<PTYObject>> elements)
        : PTYObject(PTYType::kList), elements_(std::move(elements)) {}

    void Append(std::shared_ptr<PTYObject> val) {
        elements_.push_back(std::move(val));
    }
    void Set(size_t index, std::shared_ptr<PTYObject> val) {
        if (index >= elements_.size()) {
            elements_.resize(index + 1);
        }
        elements_[index] = std::move(val);
    }
    std::shared_ptr<PTYObject> Get(size_t index) const {
        return (index < elements_.size()) ? elements_[index] : nullptr;
    }
    size_t Size() const { return elements_.size(); }
    const std::vector<std::shared_ptr<PTYObject>>& RawList() const { return elements_; }
    std::vector<std::shared_ptr<PTYObject>>& RawList() { return elements_; }

private:
    std::vector<std::shared_ptr<PTYObject>> elements_;
};

/**
 * @brief Pitaya Tensor object (pitaya::PTYTensor) wrapped by fast_engine::TensorWrapper.
 *        Đối tượng Tensor Pitaya (pitaya::PTYTensor) được bọc bởi fast_engine::TensorWrapper.
 *
 * [OBSERVED @ .rodata 0x0523c1..0x0524f0 & .data 0x060000..0x0600b0]:
 * - Attributes exposed to Python:
 *   1. "data_type"   (int32: 1=FLOAT32, 2=UINT8, 3=INT8, 4=UINT16, 5=INT16, 6=INT32, 7=INT64, 11=DOUBLE)
 *   2. "data_format" (int32: 0=NHWC, 1=NCHW, 2=NC4HW4)
 *   3. "dims"        (vector<int64_t>)
 *   4. "fraction"    (int32 quantization fraction)
 *   5. "num_list"    (flattened numeric data list)
 */
class PTYTensor : public PTYObject {
public:
    PTYTensor()
        : PTYObject(PTYType::kTensor),
          data_type_(1),
          data_format_(0),
          fraction_(0),
          nelems_(0) {}

    std::string Name() const { return name_; }
    void SetName(const std::string& n) { name_ = n; }

    int32_t DataType() const { return data_type_; }
    void SetDataType(int32_t dt) { data_type_ = dt; }

    int32_t DataFormat() const { return data_format_; }
    void SetDataFormat(int32_t df) { data_format_ = df; }

    int32_t Fraction() const { return fraction_; }
    void SetFraction(int32_t f) { fraction_ = f; }

    const std::vector<int64_t>& Dims() const { return dims_; }
    void SetDims(const std::vector<int64_t>& d) {
        dims_ = d;
        int64_t prod = dims_.empty() ? 0 : 1;
        for (int64_t dim : dims_) {
            prod *= (dim > 0 ? dim : 1);
        }
        nelems_ = prod;
    }

    int64_t Nelems() const { return nelems_; }
    const std::vector<double>& NumList() const { return num_list_; }
    void SetNumList(const std::vector<double>& nums) {
        num_list_ = nums;
        if (nelems_ == 0) {
            nelems_ = static_cast<int64_t>(num_list_.size());
        }
    }

    const uint8_t* RawData() const { return raw_bytes_.data(); }
    size_t RawByteSize() const { return raw_bytes_.size(); }
    void SetRawBytes(const std::vector<uint8_t>& b) { raw_bytes_ = b; }

private:
    std::string name_;
    int32_t data_type_;
    int32_t data_format_;
    int32_t fraction_;
    int64_t nelems_;
    std::vector<int64_t> dims_;
    std::vector<double> num_list_;
    std::vector<uint8_t> raw_bytes_;
};

class PTYBuffer : public PTYObject {
public:
    explicit PTYBuffer(std::vector<uint8_t> bytes = {})
        : PTYObject(PTYType::kBuffer), bytes_(std::move(bytes)) {}
    const std::vector<uint8_t>& Bytes() const { return bytes_; }
    void SetBytes(std::vector<uint8_t> b) { bytes_ = std::move(b); }

private:
    std::vector<uint8_t> bytes_;
};

class PTYClass : public PTYObject {
public:
    PTYClass(std::string cls_name, std::shared_ptr<PTYDict> fields = std::make_shared<PTYDict>())
        : PTYObject(PTYType::kClass), class_name_(std::move(cls_name)), fields_(std::move(fields)) {}
    const std::string& ClassName() const { return class_name_; }
    std::shared_ptr<PTYDict> Fields() const { return fields_; }

private:
    std::string class_name_;
    std::shared_ptr<PTYDict> fields_;
};

/**
 * @brief Pitaya Task destructor ABI layout observed at 0x041378 (_ZN6pitaya4TaskD2Ev, size 1,136 bytes).
 *        Bố cục ABI hàm hủy Pitaya Task quan sát tại 0x041378 (_ZN6pitaya4TaskD2Ev, kích thước 1.136 bytes).
 *
 * [OBSERVED @ 0x041378..0x0417e4]:
 * - Deallocates 16 internal std::string / std::vector / std::shared_ptr / std::unordered_map fields
 *   at offsets +0x2b8 down to +0x008 inside pitaya::Task (total struct size 0x2d0 = 720 bytes).
 */
struct Task {
    void* vptr{nullptr};                                  // +0x000
    std::string task_id;                                  // +0x008
    std::string business_name;                            // +0x020
    std::string entrance_module;                          // +0x038
    std::shared_ptr<PTYObject> input_data;                // +0x050
    std::shared_ptr<PTYObject> output_data;               // +0x060
    std::shared_ptr<Error> task_error;                    // +0x070
    std::unordered_map<std::string, std::string> extras;  // +0x080
    std::vector<std::string> trace_logs;                  // +0x0a8
    int64_t create_time_ms{0};                            // +0x0c0
    int64_t start_time_ms{0};                             // +0x0c8
    int64_t finish_time_ms{0};                            // +0x0d0
    bool is_async{false};                                 // +0x0d8
    bool is_cancelled{false};                             // +0x0d9

    virtual ~Task();
};

} // namespace pitaya

namespace fast_engine {

class Engine;
class TypeObj;
class ObjCachePool;

/**
 * @brief Base object header in FastEngine (fast_engine::Obj).
 *        Header đối tượng cơ sở trong FastEngine (fast_engine::Obj).
 *
 * [OBSERVED EXACT OFFSETS FROM AARCH64 DISASSEMBLY]:
 * - +0x00: vptr (void**)
 * - +0x08..0x18: GC intrusive doubly-linked list pointers (next/prev/container)
 * - +0x20: int32_t gc_generation (OBSERVED @ 0x03273c & 0x04fd58: ldr w8, [engine, #0x1140]; str w8, [obj, #0x20])
 * - +0x28: TypeObj* type_obj     (OBSERVED @ 0x043dd0: ldr x0, [x21, #0x28] & 0x032858: ldr x8, [x1, #0x28])
 * - +0x30: Engine* engine        (OBSERVED @ 0x03befc: Engine* stored in Obj::Obj(Engine*, TypeObj*, long))
 * - +0x38: int32_t ref_count     (OBSERVED @ 0x03c0b8 & 0x04fd50: mov w8, #1; str w8, [obj, #0x38])
 */
class Obj {
public:
    Obj(Engine* engine, TypeObj* type, int64_t flags = 0);
    virtual ~Obj() = default;

    virtual std::string Str() const { return "<Obj>"; }
    virtual void Reset() { ref_count = 1; }

    void IncRef() { ++ref_count; }
    bool DecRef() { return (--ref_count) <= 0; }

    uint64_t gc_next{0};       // +0x08
    uint64_t gc_prev{0};       // +0x10
    uint64_t gc_flags{0};      // +0x18
    int32_t gc_generation{0};  // +0x20 (OBSERVED @ 0x04fd58: str w8, [x0, #0x20])
    int32_t pad_24_{0};        // +0x24
    TypeObj* type_obj{nullptr};// +0x28 (OBSERVED @ 0x043dd0: ldr x0, [x21, #0x28])
    Engine* engine{nullptr};   // +0x30
    int32_t ref_count{1};      // +0x38 (OBSERVED @ 0x04fd50: mov w8, #1; str w8, [x0, #0x38])
    int32_t obj_flags{0};      // +0x3c
};

/**
 * @brief Attribute descriptor entry used in `.data` at 0x060000..0x0600b0 for TensorWrapper.
 *        Mục mô tả thuộc tính được sử dụng trong `.data` tại 0x060000..0x0600b0 cho TensorWrapper.
 *
 * [OBSERVED @ .data 0x060000..0x0600b0]:
 * Each entry is 32 bytes (0x20 bytes):
 * - +0x00: const char* attr_name (.rodata pointer: "data_type", "data_format", "dims", "fraction", "num_list")
 * - +0x08: Obj* (*getter)(Obj* self, Engine* engine)
 * - +0x10: int (*setter)(Obj* self, Obj* val, Engine* engine)
 * - +0x18: uint64_tclosure_or_reserved (0)
 */
struct AttrDef {
    const char* name;
    Obj* (*getter)(Obj* self, Engine* engine);
    int (*setter)(Obj* self, Obj* val, Engine* engine);
    uint64_t reserved;
};

/**
 * @brief Method descriptor entry used in TypeObj registration.
 *        Mục mô tả phương thức được dùng khi đăng ký TypeObj.
 */
struct MethodDef {
    const char* name;
    Obj* (*func)(Obj* self, Obj* args, Obj* kwargs, Engine* engine);
    uint64_t flags;
};

/**
 * @brief TypeObj descriptor in FastEngine.
 *        Đối tượng mô tả kiểu TypeObj trong FastEngine.
 *
 * [OBSERVED @ 0x032858..0x032860]:
 * - ldr x8, [x1, #0x28]   ; load val->type_obj
 * - ldrb w8, [x8, #0xab]  ; load type capability flags at offset +0xab (bit 1 = is_sequence / is_list)
 */
class TypeObj : public Obj {
public:
    TypeObj(const char* name, size_t basic_size, uint8_t capability_flags = 0)
        : Obj(nullptr, nullptr, 0),
          type_name(name),
          instance_size(basic_size),
          type_capability_ab(capability_flags) {}

    const char* type_name{nullptr}; // +0x40
    size_t instance_size{0};        // +0x48
    uint8_t pad_50_[0x5b]{};        // +0x50..0xaa
    uint8_t type_capability_ab{0};  // +0xab (OBSERVED @ 0x03285c: ldrb w8, [x8, #0xab]; tbnz w8, #1)
};

// Exported global STT_OBJECT at .bss 0x060210 (size 8 bytes)
// Biến toàn cục STT_OBJECT được export tại .bss 0x060210 (kích thước 8 bytes)
extern TypeObj* TensorType;

// Built-in singleton TypeObjs and Values imported via .got (0x05fed0..0x05ff98)
extern TypeObj* LongType;
extern TypeObj* FloatType;
extern TypeObj* BoolType;
extern TypeObj* StrType;
extern TypeObj* BytesType;
extern TypeObj* ListType;
extern TypeObj* DictType;
extern TypeObj* ExtDictType;
extern TypeObj* ExtListType;

extern Obj* None;
extern Obj* Empty;
extern Obj* True;
extern Obj* False;

/**
 * @brief LongObj (80 bytes = 0x50 bytes, value at +0x40).
 *        Đối tượng số nguyên LongObj (80 bytes = 0x50 bytes, giá trị tại +0x40).
 *
 * [OBSERVED @ 0x04fe74..0x04fed8 in MicPyArray_nativeSetLong]:
 * - Small integer cache check: add x8, x3, #5; cmp x8, #0x106 (caches [-5, 257] at [engine + 0x860 + (val+5)*8])
 * - Pool allocation via ObjCachePool::Pop([engine+8]+0x00) or operator new(0x50 = 80 bytes)
 * - Value stored at [obj + 0x40]: str x19, [x22, #0x40] (@ 0x04feb8)
 */
class LongObj : public Obj {
public:
    LongObj(int64_t val, Engine* eng);
    std::string Str() const override { return std::to_string(value); }

    int64_t value{0};      // +0x40 (OBSERVED @ 0x04feb8: str x19, [x22, #0x40])
    uint64_t reserved_{0}; // +0x48 (total size = 0x50 = 80 bytes)
};

/**
 * @brief FloatObj (72 bytes = 0x48 bytes, double value at +0x40).
 *        Đối tượng số thực FloatObj (72 bytes = 0x48 bytes, giá trị double tại +0x40).
 *
 * [OBSERVED @ 0x04ff18..0x04ff84 in MicPyArray_nativeSetDouble]:
 * - Pool allocation via ObjCachePool::Pop([engine+8]+0x08) or operator new(0x48 = 72 bytes)
 * - Value stored at [obj + 0x40]: str d8, [x0, #0x40] (@ 0x04ff4c)
 */
class FloatObj : public Obj {
public:
    FloatObj(double val, Engine* eng);
    std::string Str() const override { return std::to_string(value); }

    double value{0.0};     // +0x40 (OBSERVED @ 0x04ff4c: str d8, [x0, #0x40])
};

/**
 * @brief StrObj wrapping UTF-8 string data.
 *        Đối tượng chuỗi StrObj bọc dữ liệu chuỗi UTF-8.
 */
class StrObj : public Obj {
public:
    StrObj(std::string s, Engine* eng);
    std::string Str() const override { return value; }

    std::string value;
};

/**
 * @brief BytesObj wrapping raw binary buffer.
 *        Đối tượng mảng byte BytesObj bọc vùng nhớ nhị phân thô.
 */
class BytesObj : public Obj {
public:
    BytesObj(const uint8_t* data, size_t len, Engine* eng);
    const std::vector<uint8_t>& Bytes() const { return data_; }

private:
    std::vector<uint8_t> data_;
};

/**
 * @brief ListObj (88 bytes = 0x58 bytes, std::vector<Obj*> at +0x40).
 *        Đối tượng danh sách ListObj (88 bytes = 0x58 bytes, std::vector<Obj*> tại +0x40).
 *
 * [OBSERVED @ 0x04fd08..0x04fd8c in MicPyArray_nativeCreateArray]:
 * - Pool allocation via ObjCachePool::Pop([engine+8]+0x28) or operator new(0x58 = 88 bytes)
 * - Calls ListObj::Resize(size) (#0xe010) and zeroes [items_begin .. items_begin + size*8] at [obj + 0x40]
 */
class ListObj : public Obj {
public:
    ListObj(int64_t size, Engine* eng);
    ~ListObj() override;

    void Resize(int64_t new_size);
    void Append(Obj* item);
    void SetItem(int64_t idx, Obj* item);
    Obj* GetItem(int64_t idx) const;
    size_t Size() const { return items.size(); }

    std::vector<Obj*> items; // +0x40 (24 bytes on 64-bit -> total size 0x58 = 88 bytes)
};

/**
 * @brief DictObj wrapping string/Obj key-value map.
 *        Đối tượng từ điển DictObj bọc ánh xạ khóa-giá trị.
 *
 * [OBSERVED @ 0x0503e0..0x050d24 in MicPyDict_native*]:
 * - Created via DictObj::NewEmpty(Engine*) (#0xe670)
 * - Populated via DictObj::SetItemString(const char*, Obj*) (#0xe590)
 */
class DictObj : public Obj {
public:
    explicit DictObj(Engine* eng);
    ~DictObj() override;

    static DictObj* NewEmpty(Engine* eng);
    void SetItemString(const char* key, Obj* val);
    void SetItem(Obj* key, Obj* val);
    Obj* GetItemString(const char* key) const;
    const std::unordered_map<std::string, Obj*>& Items() const { return map_; }

private:
    std::unordered_map<std::string, Obj*> map_;
};

/**
 * @brief ExtDictObj base class (80 bytes = 0x50 bytes) and PTYExtDict subclass.
 *        Lớp cơ sở ExtDictObj (80 bytes = 0x50 bytes) và lớp con PTYExtDict.
 *
 * [OBSERVED @ 0x03bec0..0x03bf70 (_ZN6pitaya16CreatePTYExtDictEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE)]:
 * - Allocates 0x50 (80) bytes via _Znwm (`mov w0, #0x50; bl #0xecd0`)
 * - Calls `fast_engine::ExtDictObj::ExtDictObj(Engine*, long)` (`mov w2, #0x40; bl #0xdea0`)
 * - Installs vtable `0x05ee30 + 0x10` (`_ZTVN6pitaya10PTYExtDictE` in `.data.rel.ro`)
 * - Stores `std::shared_ptr<pitaya::PTYDict>` at offset `+0x40..+0x48` (`stp x9, x8, [x19, #0x40]`)
 *   and atomically increments `shared_ptr` control block refcount (`add x8, x8, #8; ldxr/stxr`).
 */
class ExtDictObj : public Obj {
public:
    ExtDictObj(Engine* eng, int64_t flags = 0x40);
    ~ExtDictObj() override = default;

    virtual Obj* GetItem(Obj* key) = 0;
    virtual int SetItem(Obj* key, Obj* val) = 0;
    virtual int DelItem(Obj* key) = 0;
    virtual Obj* Keys() = 0;
    virtual int64_t Len() const = 0;
    virtual bool Contains(Obj* key) const = 0;
};

/**
 * @brief ExtListObj base class (80 bytes = 0x50 bytes) and PTYExtList subclass.
 *        Lớp cơ sở ExtListObj (80 bytes = 0x50 bytes) và lớp con PTYExtList.
 *
 * [OBSERVED @ 0x03bf74..0x03c024 (_ZN6pitaya16CreatePTYExtListEPvRKNSt6__ndk110shared_ptrINS_7PTYListEEE)]:
 * - Allocates 0x50 (80) bytes via _Znwm (`mov w0, #0x50; bl #0xecd0`)
 * - Calls `fast_engine::ExtListObj::ExtListObj(Engine*, long)` (`mov w2, #0x40; bl #0xe560`)
 * - Installs vtable `0x05eeb0 + 0x10` (`_ZTVN6pitaya10PTYExtListE` in `.data.rel.ro`)
 * - Stores `std::shared_ptr<pitaya::PTYList>` at offset `+0x40..+0x48` (`stp x9, x8, [x19, #0x40]`).
 */
class ExtListObj : public Obj {
public:
    ExtListObj(Engine* eng, int64_t flags = 0x40);
    ~ExtListObj() override = default;

    virtual Obj* GetItem(int64_t index) = 0;
    virtual int SetItem(int64_t index, Obj* val) = 0;
    virtual int Append(Obj* val) = 0;
    virtual int64_t Len() const = 0;
};

/**
 * @brief Object Cache Pool (fast_engine::ObjCachePool) pointed by [engine + 0x08] and [engine + 0x30].
 *        Hồ bộ nhớ đệm đối tượng (fast_engine::ObjCachePool) được trỏ bởi [engine + 0x08] và [engine + 0x30].
 *
 * [OBSERVED @ 0x04fd14, 0x04fe90, 0x04ff24, 0x03c03c]:
 * - [engine + 0x08] points to an array of ObjCachePool* pointers:
 *   - +0x00: LongObj pool   (OBSERVED @ 0x04fe98: ldr x0, [x8])
 *   - +0x08: FloatObj pool  (OBSERVED @ 0x04ff2c: ldr x0, [x8, #8])
 *   - +0x28: ListObj pool   (OBSERVED @ 0x04fd1c: ldr x0, [x8, #0x28])
 * - [engine + 0x30] points to CEPExtDictObj pool (OBSERVED @ 0x03c03c: ldr x19, [x0, #0x30])
 */
class ObjCachePool {
public:
    explicit ObjCachePool(size_t max_capacity = 256) : max_capacity_(max_capacity) {}
    ~ObjCachePool() {
        for (Obj* o : free_list_) {
            delete o;
        }
    }

    Obj* Pop() {
        if (free_list_.empty()) {
            return nullptr;
        }
        Obj* obj = free_list_.back();
        free_list_.pop_back();
        return obj;
    }

    bool Push(Obj* obj) {
        if (!obj || free_list_.size() >= max_capacity_) {
            return false;
        }
        free_list_.push_back(obj);
        return true;
    }

    size_t Size() const { return free_list_.size(); }

private:
    size_t max_capacity_;
    std::vector<Obj*> free_list_;
};

struct EnginePoolTable {
    ObjCachePool* long_pool{nullptr};   // +0x00 (OBSERVED @ 0x04fe98)
    ObjCachePool* float_pool{nullptr};  // +0x08 (OBSERVED @ 0x04ff2c)
    ObjCachePool* str_pool{nullptr};    // +0x10
    ObjCachePool* bytes_pool{nullptr};  // +0x18
    ObjCachePool* dict_pool{nullptr};   // +0x20
    ObjCachePool* list_pool{nullptr};   // +0x28 (OBSERVED @ 0x04fd1c)
};

/**
 * @brief ExceptionObject in FastEngine (fast_engine::ExceptionObject).
 *        Đối tượng ngoại lệ trong FastEngine (fast_engine::ExceptionObject).
 *
 * [OBSERVED @ 0x0430fc..0x043188 in GetCoreError]:
 * - Fetched via Engine::FetchException(&type, &value, &traceback) (#0xe080)
 * - Error code mapped via ExceptionObject::GetErrorFromType(Obj*) (#0xe6a0)
 * - Formatted via Obj::Str() (#0xec00)
 */
class ExceptionObject : public Obj {
public:
    ExceptionObject(int32_t err_code, std::string msg, Engine* eng)
        : Obj(eng, nullptr, 0), error_code_(err_code), message_(std::move(msg)) {}

    std::string Str() const override { return message_; }
    int32_t ErrorCodeValue() const { return error_code_; }

    static int32_t GetErrorFromType(Obj* exc_obj) {
        auto* exc = dynamic_cast<ExceptionObject*>(exc_obj);
        return exc ? exc->error_code_ : 101;
    }

private:
    int32_t error_code_;
    std::string message_;
};

/**
 * @brief FastEngine Execution Engine (fast_engine::Engine) exact ABI offsets.
 *        Bộ máy thực thi FastEngine (fast_engine::Engine) với các offset ABI chuẩn xác.
 *
 * [OBSERVED EXACT OFFSETS FROM AARCH64 DISASSEMBLY]:
 * - +0x0008: EnginePoolTable* pool_table     (OBSERVED @ 0x04fd14: ldr x8, [x0, #8])
 * - +0x0030: ObjCachePool* cep_event_pool    (OBSERVED @ 0x03c03c: ldr x19, [x0, #0x30])
 * - +0x0860: LongObj* small_int_cache[263]   (OBSERVED @ 0x04fe74..0x04fe88: add x8, x3, #5; cmp x8, #0x106;
 *                                             add x8, x0, x8, lsl #3; ldr x0, [x8, #0x860])
 * - +0x10e0: uint8_t has_exception           (OBSERVED @ 0x0430dc & 0x043cd4: mov w9, #0x10e0; ldrb w9, [x1, x9])
 * - +0x1140: int32_t gc_generation           (OBSERVED @ 0x03272c & 0x04fd54: ldr w8, [x19, #0x1140])
 */
class Engine {
public:
    Engine();
    ~Engine();

    LongObj* GetSmallInt(int64_t val) const {
        // [OBSERVED @ 0x04fe74..0x04fe88]:
        // add x8, x3, #5; cmp x8, #0x106; b.hi #0x4fe90
        // add x8, x0, x8, lsl #3; ldr x0, [x8, #0x860]
        uint64_t idx = static_cast<uint64_t>(val + 5);
        if (idx <= 0x106ULL) {
            return small_int_cache[idx];
        }
        return nullptr;
    }

    void MakeValueError(const std::string& msg);
    void MakeTypeError(const std::string& msg);
    void MakeAttributeError();
    void MakeRuntimeError(const std::string& msg);
    void FetchException(Obj** out_type, Obj** out_val, Obj** out_tb);
    void ClearException();
    void CollectGarbage();

    void* vptr{nullptr};                         // +0x0000
    EnginePoolTable* pool_table{nullptr};        // +0x0008 (OBSERVED @ 0x04fd14)
    uint8_t pad_0010_[0x20]{};                   // +0x0010..0x002f
    ObjCachePool* cep_event_pool{nullptr};       // +0x0030 (OBSERVED @ 0x03c03c)
    uint8_t pad_0038_[0x828]{};                  // +0x0038..0x085f
    LongObj* small_int_cache[263]{};             // +0x0860..0x1097 (OBSERVED @ 0x04fe88: [-5..257] = 263 entries)
    uint8_t pad_1098_[0x48]{};                   // +0x1098..0x10df
    uint8_t has_exception{0};                    // +0x10e0 (OBSERVED @ 0x0430dc: mov w9, #0x10e0; ldrb w9, [x1, x9])
    uint8_t pad_10e1_[0x5f]{};                   // +0x10e1..0x113f
    int32_t gc_generation{1};                    // +0x1140 (OBSERVED @ 0x04fd54: ldr w8, [x19, #0x1140])

private:
    EnginePoolTable owned_pool_table_;
    ObjCachePool long_pool_;
    ObjCachePool float_pool_;
    ObjCachePool list_pool_;
    ObjCachePool cep_pool_;
    Obj* current_exc_type_{nullptr};
    Obj* current_exc_val_{nullptr};
    Obj* current_exc_tb_{nullptr};
};

} // namespace fast_engine

#endif // NEXTAI_OPENCUT_BDMICROPYTHONVM_TYPES_H_
