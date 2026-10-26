// ============================================================================
// File: ttmstrategycenter_types.h
// Target: libTTMStrategyCenter.so (395,664 bytes, AArch64 ELF64, 899 symbols)
// Package: com.nextai.opencut / com.tiktok.strategycenter
//
// Description (EN):
// Cleanroom C++17 ABI data structures, constants, and virtual interfaces for
// ByteDance / TikTok Strategy Center (`libTTMStrategyCenter.so`).
// All field offsets, struct sizes, and sentinel values are verified against
// AArch64 machine code in `apktool-res/lib/arm64-v8a/libTTMStrategyCenter.so`.
//
// Mô tả (VI):
// Định nghĩa cấu trúc dữ liệu chuẩn ABI C++17, hằng số và giao diện ảo cho
// Trung tâm Chiến lược ByteDance / TikTok (`libTTMStrategyCenter.so`).
// Toàn bộ độ lệch trường, kích thước struct và hằng số lính canh được đối soát
// trực tiếp với mã máy AArch64 trong `libTTMStrategyCenter.so`.
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <any>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace nextai {
namespace ttm_strategy_center {

// ============================================================================
// 1. Global Sentinel Constants (.data @ 0x64008..0x64058)
// Hằng số giới hạn toàn cục (.data tại 0x64008..0x64058)
// ============================================================================
constexpr int64_t kLongMaxValue        = 0x7fffffffffffffffLL;     // @ 0x64008 & 0x64048
constexpr int32_t kIntMaxValue         = 0x7fffffff;               // @ 0x64010 & 0x64050
constexpr double  kDoubleMaxValue      = 1.7976931348623157e+308;  // @ 0x64018 & 0x64058 (0x7fefffffffffffff)
constexpr int32_t kJniVersion1_6       = 0x00010006;               // JNI_OnLoad @ 0x2e6f4..0x2e710

// ============================================================================
// 2. TTM State Error & Transparent Execution Context
// Cấu trúc lỗi trạng thái TTM & Ngữ cảnh thực thi trong suốt
// Verified at 0x272a4..0x272e8, 0x4b840..0x4b880, 0x4cd3c..0x4cda8
// ============================================================================
enum class TTMStateErrorCode : int32_t {
    kOk                         = 0,
    kNullDataWrapper            = 100,  // 0x64 @ 0x27298, 0x282f4, 0x2834c
    kByteDtAllocError           = 202,  // 0xca @ 0x4cd9c
    kNullFeatureCenterContext   = 315,  // 0x13b @ 0x272b4
    kByteDtInvalidParam         = 401,  // 0x191 @ .rodata 0x523dc
    kByteDtModelParseFailed     = 402,  // 0x192 @ .rodata 0x523e0
    kByteDtPredictFailed        = 403,  // 0x193 @ .rodata 0x523e4
    kByteDtDimMismatch          = 404,  // 0x194 @ .rodata 0x523e8
    kByteDtNotInitialized       = 405,  // 0x195 @ .rodata 0x523ec
    kByteDtMemoryError          = 406,  // 0x196 @ .rodata 0x523f0
    kByteDtUnknownError         = 407,  // 0x197 @ 0x4d23c (default for > 6)
    kByteDtPredictEmptyOutput   = 408,  // 0x198 @ 0x4b874 (line 0xc1 = 193)
    kByteDtEngineNull           = 409,  // 0x199 @ 0x4b84c (line 0xb8 = 184)
    kByteDtCreateNullEngine     = 411,  // 0x19b @ 0x4cd4c (line 0x16 = 22)
    kByteDtUnsupportedDataType  = 414   // 0x19e @ 0x4d07c (line 0x31 = 49)
};

// __TTMStateError layout (24 bytes):
// +0x00: int32_t code (w10/w11 stored at [err, #0])
// +0x04: int32_t reserved
// +0x08: const char* func_name (x8/x9 stored at [err, #8])
// +0x10: int32_t line (w9/w10 stored at [err, #0x10])
// +0x14: int32_t padding
struct __TTMStateError {
    int32_t     code{0};            // +0x00
    int32_t     reserved{0};        // +0x04
    const char* func_name{nullptr}; // +0x08
    int32_t     line{0};            // +0x10
    int32_t     padding{0};         // +0x14
};
static_assert(sizeof(__TTMStateError) == 24, "__TTMStateError must be 24 bytes");
static_assert(offsetof(__TTMStateError, code) == 0x00, "code at +0x00");
static_assert(offsetof(__TTMStateError, func_name) == 0x08, "func_name at +0x08");
static_assert(offsetof(__TTMStateError, line) == 0x10, "line at +0x10");

// __TTMTransparentStruct layout (64 bytes):
// Verified at 0x27248 ([x4, #0x30] -> jni_env), 0x272a4 ([x19, #0x18] -> state_error),
// 0x4a298 ([x20, #0x18] -> state_error, [x20, #0x20] -> allocator_ctx)
struct __TTMTransparentStruct {
    void*            vm_state{nullptr};      // +0x00
    void*            rule_context{nullptr};  // +0x08
    void*            user_data{nullptr};     // +0x10
    __TTMStateError* error{nullptr};         // +0x18
    void*            alloc_ctx{nullptr};     // +0x20
    void*            ext_interface{nullptr}; // +0x28
    void*            jni_env{nullptr};       // +0x30
    void*            reserved_38{nullptr};   // +0x38
};
static_assert(sizeof(__TTMTransparentStruct) == 64, "__TTMTransparentStruct must be 64 bytes");
static_assert(offsetof(__TTMTransparentStruct, error) == 0x18, "error at +0x18");
static_assert(offsetof(__TTMTransparentStruct, alloc_ctx) == 0x20, "alloc_ctx at +0x20");
static_assert(offsetof(__TTMTransparentStruct, jni_env) == 0x30, "jni_env at +0x30");

// ============================================================================
// 3. TTM Machine Core Object Hierarchy (_object, TTMIntO, TTMStringO, TTMListO, _dictobject)
// Hệ thống phân cấp đối tượng TTM Machine Core (khớp 0x30950..0x30a24, 0x4cfa0)
// ============================================================================
struct TTMTypeObject {
    const char* name{nullptr};
    uint32_t    basic_size{0};
    uint32_t    flags{0};
};

// _object layout:
// +0x00: int64_t ref_count / header
// +0x08: TTMTypeObject* type (verified at 0x3095c: ldr x8, [x8, #8])
// +0x10: union payload (int64_t int_val @ 0x309f0, double float_val @ 0x309fc, int32_t list_size @ 0x4d018)
// +0x18: secondary ptr / capacity
// +0x20: hash / flags
// +0x28: char* c_str (for TTMStringO @ 0x26ea4, 0x30a20) or double* / int64_t* items (for TTMListO @ 0x4d024)
struct _object {
    int64_t        ob_refcnt{1};          // +0x00
    TTMTypeObject* ob_type{nullptr};      // +0x08
    union {
        int64_t    int_val;               // +0x10 (TTMIntO / TTMBoolO)
        double     float_val;             // +0x10 (TTMFloatO)
        int64_t    list_size;             // +0x10 (TTMListO count)
        void*      ptr_val;               // +0x10 (TTMByteDtO shared_ptr.px)
    } payload{0};
    void*          shared_cnt{nullptr};   // +0x18 (TTMByteDtO shared_ptr.pn)
    uint64_t       reserved_20{0};        // +0x20
    void*          data_ptr{nullptr};     // +0x28 (TTMStringO char* or TTMListO buffer*)
    std::string    owned_str{};
    std::vector<uint64_t> owned_list{};
    std::unordered_map<std::string, _object*> owned_dict{};
};

using TTMListO    = _object;
using _dictobject = _object;

// Global Type Descriptors matching imported symbols from libTTMachineCore.so
extern TTMTypeObject TTMDictO_Type;
extern TTMTypeObject TTMIntO_Type;
extern TTMTypeObject TTMFloatO_Type;
extern TTMTypeObject TTMStringO_Type;
extern TTMTypeObject TTMListO_Type;
extern TTMTypeObject TTMBoolO_Type;
extern TTMTypeObject TTMByteDtO_Type;

// ============================================================================
// 4. ElementValueType & TTMExtDataInterface (Virtual Table with 23 slots)
// Kiểu giá trị phần tử & Giao diện dữ liệu mở rộng TTMExtDataInterface
// ============================================================================
enum class ElementValueType : int32_t {
    kInt     = 0,
    kFloat   = 1,
    kBool    = 2,
    kString  = 3,
    kList    = 4,
    kDict    = 5,
    kUnknown = 6
};

// Tagged allocation wrapper created by CreateTTMAllocDataType (0x44d10, 16 bytes)
struct TTMAllocDataTag {
    uint32_t type{0};     // +0x00 (1=int_vec, 2=double_vec, 3=string_vec, 4=map, 5=vec)
    uint32_t padding{0};  // +0x04
    void*    ptr{nullptr}; // +0x08
};
static_assert(sizeof(TTMAllocDataTag) == 16, "TTMAllocDataTag must be 16 bytes");

class TTMExtDataInterface {
public:
    virtual ~TTMExtDataInterface() = default;

    virtual int64_t GetArraySize(ElementValueType type, __TTMTransparentStruct* ctx) = 0;
    virtual const char* GetStringValue(long index, __TTMTransparentStruct* ctx) = 0;
    virtual int64_t GetIntValue(long index, __TTMTransparentStruct* ctx) = 0;
    virtual double GetDoubleValue(long index, __TTMTransparentStruct* ctx) = 0;
    virtual std::vector<std::string> GetAllStringValues(__TTMTransparentStruct* ctx) = 0;
    virtual std::vector<int64_t> GetAllIntValues(__TTMTransparentStruct* ctx) = 0;
    virtual std::vector<double> GetAllDoubleValues(__TTMTransparentStruct* ctx) = 0;
    virtual std::vector<std::string> GetAllStringValues(const char* key, __TTMTransparentStruct* ctx) = 0;
    virtual std::vector<int64_t> GetAllIntValues(const char* key, __TTMTransparentStruct* ctx) = 0;
    virtual std::vector<double> GetAllDoubleValues(const char* key, __TTMTransparentStruct* ctx) = 0;
    virtual void* GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) = 0;
    virtual void* GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) = 0;
    virtual void* GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) = 0;
    virtual const char* GetStringValue(const char* key, __TTMTransparentStruct* ctx) = 0;
    virtual int64_t GetIntValue(const char* key, __TTMTransparentStruct* ctx) = 0;
    virtual double GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) = 0;
    virtual void* GetOriginData(__TTMTransparentStruct* ctx) = 0;
    virtual std::vector<std::string> GetDictAllValuesForString(__TTMTransparentStruct* ctx) = 0;
    virtual std::vector<int64_t> GetDictAllValuesForInt(__TTMTransparentStruct* ctx) = 0;
    virtual std::vector<double> GetDictAllValuesForDouble(__TTMTransparentStruct* ctx) = 0;
    virtual std::vector<std::string> GetDictAllKeys(__TTMTransparentStruct* ctx) = 0;
    virtual int32_t GetOriginDataType(__TTMTransparentStruct* ctx) {
        (void)ctx;
        return 0;
    }
};

// ============================================================================
// 5. ttm_sc_dict & ttm_sc_list & ttm_sc_input & ttm_sc_output
// Cấu trúc từ điển, danh sách, đầu vào và đầu ra của Strategy Center
// ============================================================================
class ttm_sc_dict;
class ttm_sc_list;

class ttm_sc_dict {
public:
    ttm_sc_dict();
    explicit ttm_sc_dict(std::shared_ptr<std::unordered_map<std::string, std::any>> map_ptr);
    ~ttm_sc_dict() = default;

    std::shared_ptr<std::unordered_map<std::string, std::any>> getOriginValue() const;
    std::vector<std::string> getAllKeys();

    void putInt(const std::string& key, int64_t val);
    void putDouble(const std::string& key, double val);
    void putBool(const std::string& key, bool val);
    void putString(const std::string& key, const std::string& val);
    void putDict(const std::string& key, const ttm_sc_dict& val);
    void putList(const std::string& key, const ttm_sc_list& val);

    int64_t getInt(const std::string& key, int64_t default_val = kLongMaxValue) const;
    double getDouble(const std::string& key, double default_val = kDoubleMaxValue) const;
    std::string getString(const std::string& key) const;
    bool containsKey(const std::string& key) const;
    bool removeKey(const std::string& key);

private:
    std::shared_ptr<std::unordered_map<std::string, std::any>> data_; // +0x00 (16 bytes)
};

class ttm_sc_list {
public:
    ttm_sc_list();
    explicit ttm_sc_list(std::shared_ptr<std::vector<std::any>> vec_ptr);
    ~ttm_sc_list() = default;

    std::shared_ptr<std::vector<std::any>> getOriginValue() const;
    long make_real_index(long index) const; // Verified @ 0x41fa0 (0xcccccccccccccccd magic mul)
    long getListSize() const;
    ElementValueType getValueType(long index) const;

    void putInt(long val);
    void putInt(int val);
    void putBool(bool val);
    void putDouble(double val);
    void putFloat(float val);
    void putString(const std::string& val);
    void putDict(const ttm_sc_dict& val);
    void putList(const ttm_sc_list& val);

    std::string getString(long index);
    long getInt(long index);
    double getDouble(long index);
    ttm_sc_dict getDict(long index);
    ttm_sc_list getList(long index);

    void modifyInt(long val, long index);
    void modifyDouble(double val, long index);
    void modifyDict(const ttm_sc_dict& val, long index);
    void modifyList(const ttm_sc_list& val, long index);
    void removeValueByIndex(long index);

private:
    std::shared_ptr<std::vector<std::any>> data_; // +0x00 (16 bytes)
};

// ttm_sc_input ABI layout (48 bytes = 0x30):
// Verified at 0x40c90..0x40f9c:
// +0x00: int32_t code_type_ (0 = borrowed bytecode, 1 = owned parsed bytecode)
// +0x04: int32_t padding_
// +0x08: void* param_ (ldr x0, [x0, #8] @ 0x40d28)
// +0x10: void* code_ (ldr x0, [x0, #0x10] @ 0x40c98)
// +0x18: TTMExtDataInterface* interface_param_ (ldr x0, [x0, #0x18] @ 0x40f00)
// +0x20: std::shared_ptr<ttm_sc_dict> dict_param_ (ldp @ +0x20..+0x28 @ 0x40ed4)
class ttm_sc_input {
public:
    ttm_sc_input(const char* rule_str, TTMExtDataInterface* iface, void* user_ctx);
    ttm_sc_input(const void* byte_code, TTMExtDataInterface* iface, void* param);
    ~ttm_sc_input();

    int32_t get_code_type() const { return code_type_; }
    void* get_param() const { return param_; }
    void* get_code() const { return code_; }
    TTMExtDataInterface* get_interface_param() const { return interface_param_; }
    std::shared_ptr<ttm_sc_dict> get_ttm_dict_param() const { return dict_param_; }
    void set_ttm_dict_param(std::shared_ptr<ttm_sc_dict> d) { dict_param_ = std::move(d); }

private:
    int32_t                      code_type_{0};          // +0x00
    int32_t                      padding_{0};            // +0x04
    void*                        param_{nullptr};        // +0x08
    void*                        code_{nullptr};         // +0x10
    TTMExtDataInterface*         interface_param_{nullptr}; // +0x18
    std::shared_ptr<ttm_sc_dict> dict_param_{};          // +0x20 (16 bytes)
};
static_assert(sizeof(ttm_sc_input) == 48, "ttm_sc_input must be 48 bytes");

// ttm_sc_output ABI layout (88 bytes = 0x58):
// Verified at 0x469f8..0x46dc0:
// +0x00: int32_t err_code_ (get_err_code @ 0x46db0, set_err_code @ 0x46db8)
// +0x04: int32_t type_ (getType @ 0x46b88: 0=string, 1=int, 2=double, 3=bool, 4=dict, 5=list)
// +0x08: _object* ttm_obj_ (ldr x0, [x0, #8])
// +0x10: void* ttm_obj_ctrl_
// +0x18: TTMExtDataInterface* ext_iface_ (ldr x0, [x0, #0x18])
// +0x20: void* ext_iface_ctrl_
// +0x28: union { int64_t int_val; double double_val; bool bool_val; } scalar_ (ldr x0/d0/w0, [x0, #0x28])
// +0x30: std::shared_ptr<std::string> str_val_ (ldp @ +0x30..+0x38 @ 0x46a0c)
// +0x40: std::shared_ptr<void> container_val_ (+0x40..+0x48)
// +0x50: const char* error_message_
class ttm_sc_output {
public:
    explicit ttm_sc_output(long val);    // @ 0x46af0: sets err_code=0, type=1, scalar=val
    explicit ttm_sc_output(double val);  // @ 0x46b14: sets err_code=0, type=2, scalar=val
    explicit ttm_sc_output(bool val);    // @ 0x46bf4: sets err_code=0, type=3, scalar=(val & 1)
    explicit ttm_sc_output(std::shared_ptr<std::string> str); // @ 0x46b38: sets type=0, scalar=-1
    ttm_sc_output() = default;

    int32_t get_err_code() const { return err_code_; }
    void set_err_code(int32_t c) { err_code_ = c; }
    int32_t getType() const { return type_; }
    const char* get_error_meesage() const { return error_message_; }

    int64_t getIntValue() const { return scalar_.int_val; }
    int64_t getIntValue(long index) const;
    double getDoubleValue() const { return scalar_.double_val; }
    double getDoubleValue(long index) const;
    bool getBoolValue() const { return (scalar_.int_val & 1) != 0; }
    bool getBoolValue(long index) const;
    std::shared_ptr<std::string> getStringValue() const { return str_val_; }
    std::string getStringValue(long index) const;
    std::shared_ptr<ttm_sc_dict> getDictValue() const;
    std::shared_ptr<ttm_sc_list> getListValue() const;

    void set_ext_interface(TTMExtDataInterface* iface) { ext_iface_ = iface; }

private:
    int32_t                      err_code_{0};           // +0x00
    int32_t                      type_{0};               // +0x04
    _object*                     ttm_obj_{nullptr};      // +0x08
    void*                        ttm_obj_ctrl_{nullptr}; // +0x10
    TTMExtDataInterface*         ext_iface_{nullptr};    // +0x18
    void*                        ext_iface_ctrl_{nullptr}; // +0x20
    union {
        int64_t int_val;
        double  double_val;
    } scalar_{-1};                                       // +0x28
    std::shared_ptr<std::string> str_val_{};             // +0x30 (16 bytes)
    std::shared_ptr<void>        container_val_{};       // +0x40 (16 bytes)
    const char*                  error_message_{nullptr}; // +0x50
};
static_assert(sizeof(ttm_sc_output) == 88, "ttm_sc_output must be 88 bytes");
static_assert(offsetof(ttm_sc_output, type_) == 0x04, "type_ at +0x04");
static_assert(offsetof(ttm_sc_output, ext_iface_) == 0x18, "ext_iface_ at +0x18");
static_assert(offsetof(ttm_sc_output, scalar_) == 0x28, "scalar_ at +0x28");
static_assert(offsetof(ttm_sc_output, str_val_) == 0x30, "str_val_ at +0x30");

// ============================================================================
// 6. ByteDT Decision Tree Engine & Prediction Result Structures
// Cấu trúc Động cơ Cây Quyết định ByteDT & Kết quả Dự đoán
// Verified at 0x4c4d0..0x4c4ec, 0x4cfa0..0x4d594
// ============================================================================
namespace bytedt {
enum class ByteDTDataType : uint8_t {
    kInt32   = 0,
    kFloat32 = 1
};

enum class ByteDTErrorCode : int8_t {
    kOk                 = 0,
    kInvalidParam       = 1,
    kModelParseFailed   = 2,
    kPredictFailed      = 3,
    kDimMismatch        = 4,
    kNotInitialized     = 5,
    kMemoryError        = 6
};
} // namespace bytedt

// _DTModelInfo layout (24 bytes = 0x18):
// Verified at 0x4c4d0:
//   ldr q0, [x0, #0x50]; str q0, [x1]; ldr w8, [x0, #0x60]; str w8, [x1, #0x10]; ldr w8, [x0, #0x64]; str w8, [x1, #0x14]
struct _DTModelInfo {
    int32_t model_type{0};      // +0x00 ('model_type' @ 0x5232a)
    float   tree_relation{0.0f}; // +0x04 ('tree_relation' @ 0x5235f)
    float   tree_size{0.0f};    // +0x08 ('tree_size' @ 0x5236d)
    float   max_depth{0.0f};    // +0x0c ('max_depth' @ 0x52377)
    float   n_feature{0.0f};    // +0x10 ('n_feature' @ 0x52381)
    float   load_time{0.0f};    // +0x14 ('load_time' @ 0x5238b)
};
static_assert(sizeof(_DTModelInfo) == 24, "_DTModelInfo must be 24 bytes");

struct _TTMDTInputDataType {
    const float* data{nullptr}; // +0x00
    size_t       count{0};      // +0x08
};
static_assert(sizeof(_TTMDTInputDataType) == 16, "_TTMDTInputDataType must be 16 bytes");

// TTMDTPredictResult ABI layout (88 bytes = 0x58):
// Verified at 0x4d244..0x4d594:
// +0x00: void* reserved_00
// +0x08: void* reserved_08
// +0x10: int32_t error_code_ (getErrorCode @ 0x4d244: ldr w0, [x0, #0x10])
// +0x14: int32_t model_type_ (getModelType @ 0x4d52c: ldr w0, [x0, #0x14])
// +0x18: std::shared_ptr<std::vector<float>> score_list_ (getScoreList @ 0x4d494: add x0, x0, #0x18)
// +0x28: std::shared_ptr<std::vector<float>> probability_list_ (getProbabilityList @ 0x4d4a4: add x0, x0, #0x28)
// +0x38: std::shared_ptr<std::vector<uint32_t>> leaf_idx_list_ (getLeafIdxList @ 0x4d4ac: add x0, x0, #0x38)
// +0x48: std::shared_ptr<std::vector<uint32_t>> class_list_ (getClassList @ 0x4d49c: add x0, x0, #0x48)
class TTMDTPredictResult {
public:
    explicit TTMDTPredictResult(TTMStateErrorCode code) noexcept
        : reserved_00_(nullptr),
          reserved_08_(nullptr),
          error_code_(static_cast<int32_t>(code)),
          model_type_(0) {}

    TTMDTPredictResult(
        int32_t model_type,
        std::shared_ptr<std::vector<float>> scores,
        std::shared_ptr<std::vector<float>> probs,
        std::shared_ptr<std::vector<uint32_t>> leaf_indices,
        std::shared_ptr<std::vector<uint32_t>> classes) noexcept
        : reserved_00_(nullptr),
          reserved_08_(nullptr),
          error_code_(0),
          model_type_(model_type),
          score_list_(std::move(scores)),
          probability_list_(std::move(probs)),
          leaf_idx_list_(std::move(leaf_indices)),
          class_list_(std::move(classes)) {}

    ~TTMDTPredictResult() = default;

    int32_t getErrorCode() const noexcept { return error_code_; }   // @ 0x4d244
    int32_t getModelType() const noexcept { return model_type_; }   // @ 0x4d52c
    std::shared_ptr<std::vector<float>>& getScoreList() noexcept { return score_list_; }             // @ 0x4d494 (+0x18)
    std::shared_ptr<std::vector<float>>& getProbabilityList() noexcept { return probability_list_; } // @ 0x4d4a4 (+0x28)
    std::shared_ptr<std::vector<uint32_t>>& getLeafIdxList() noexcept { return leaf_idx_list_; }     // @ 0x4d4ac (+0x38)
    std::shared_ptr<std::vector<uint32_t>>& getClassList() noexcept { return class_list_; }         // @ 0x4d49c (+0x48)

    void setLeafIdxList(std::shared_ptr<std::vector<uint32_t>> leaves) noexcept {
        leaf_idx_list_ = std::move(leaves); // @ 0x4d4b4
    }

private:
    void*                                  reserved_00_{nullptr}; // +0x00
    void*                                  reserved_08_{nullptr}; // +0x08
    int32_t                                error_code_{0};        // +0x10
    int32_t                                model_type_{0};        // +0x14
    std::shared_ptr<std::vector<float>>    score_list_{};         // +0x18
    std::shared_ptr<std::vector<float>>    probability_list_{};   // +0x28
    std::shared_ptr<std::vector<uint32_t>> leaf_idx_list_{};      // +0x38
    std::shared_ptr<std::vector<uint32_t>> class_list_{};         // +0x48
};
static_assert(sizeof(TTMDTPredictResult) == 88, "TTMDTPredictResult must be 88 bytes");

} // namespace ttm_strategy_center
} // namespace nextai
