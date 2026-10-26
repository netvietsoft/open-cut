// ==============================================================================
// FILE: ttmachinecore_types.h
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols, 19 JNI methods)
// PURPOSE: Core ABI Structures, 73 Bytecode State Opcodes, Error Codes, and
//          8 Built-in TTMTypeObject Descriptors for ByteDance TTMachineCore VM
//          (Các cấu trúc ABI cốt lõi, 73 mã lệnh trạng thái Bytecode, mã lỗi,
//          và 8 bộ mô tả kiểu TTMTypeObject dựng sẵn của máy ảo TTMachineCore)
// EVIDENCE CLASSIFICATION: OBSERVED (ELF64 .rodata, .data.rel.ro, .data, .dynsym)
// ==============================================================================

#pragma once

#include <jni.h>
#include <any>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace NextAI::OpenCut::TTMachineCore {

// ==============================================================================
// 1. ELF64 Segment & .data Constants (`0x6c000..0x6c668`, file `0x68000..0x68668`)
//    Hằng số phân đoạn ELF64 và vùng dữ liệu .data
// ==============================================================================

// [EN] Bytecode header magic verified in `pre_process_byte_code` (`0x1a724..0x1a734`):
//      `mov w9, #0xc02e; movk w9, #0x775c, lsl #16` -> `0x775cc02e`
// [VN] Hằng số ma thuật header bytecode kiểm tra tại `pre_process_byte_code` (`0x1a724..0x1a734`):
//      `mov w9, #0xc02e; movk w9, #0x775c, lsl #16` -> `0x775cc02e`
inline constexpr std::uint32_t kTTMBytecodeMagic = 0x775cc02eu;

// [EN] Max supported bytecode version returned by `ttm_support_max_bytecode_version` (`0x17244`):
//      `0x17244: 52800140 mov w0, #10; d65f03c0 ret` -> `10`
// [VN] Phiên bản bytecode tối đa được hỗ trợ trả về bởi `ttm_support_max_bytecode_version` (`0x17244`):
//      `0x17244: 52800140 mov w0, #10; d65f03c0 ret` -> `10`
inline constexpr std::uint16_t kTTMMaxBytecodeVersion = 10u;

// [EN] `.data` @ `0x6c000` (file `0x68000`, 1 byte): `ttm_use_malloc_zone_free = 1`
// [VN] `.data` tại `0x6c000` (file `0x68000`, 1 byte): `ttm_use_malloc_zone_free = 1`
inline constexpr std::uint8_t kTTMUseMallocZoneFreeDefault = 1u;

// [EN] `.data` @ `0x6c001` (file `0x68001`, 64 bytes): `ttm_base46_map` (Base64 alphabet)
// [VN] `.data` tại `0x6c001` (file `0x68001`, 64 byte): `ttm_base46_map` (Bảng chữ cái Base64)
inline constexpr char kTTMBase46Map[65] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// [EN] `.data` sentinel constants at `0x6c650..0x6c660` (file `0x68650..0x68660`)
// [VN] Các hằng số sentinel `.data` tại `0x6c650..0x6c660` (file `0x68650..0x68660`)
inline constexpr std::int64_t LONG_MAX_VALUE   = 0x7fffffffffffffffLL; // @ 0x6c650
inline constexpr std::int32_t INT_MAX_VALUE    = 0x7fffffff;           // @ 0x6c658
inline constexpr double       DOUBLE_MAX_VALUE = 1.7976931348623157e+308; // 0x7fefffffffffffff @ 0x6c660

// ==============================================================================
// 2. 73 TTM Machine Bytecode State Opcodes (`state_code_names` @ `0x6a268`, 584 B)
//    73 Mã lệnh trạng thái Bytecode của máy ảo TTM Machine
// ==============================================================================
enum class TTMInstructionState : std::int32_t {
    State_create_list_direct               = 0,  // 0x058d68
    State_replace_new_list_direct          = 1,  // 0x058d81
    State_list_add                         = 2,  // 0x058d9f
    State_list_add_seq                     = 3,  // 0x058dae
    State_read_constant                    = 4,  // 0x058dc1
    State_read_constant_str                = 5,  // 0x058dd5
    State_read_constant_data               = 6,  // 0x058ded
    State_object_add                       = 7,  // 0x058e06
    State_mv_direct                        = 8,  // 0x058e17
    State_mv_reg_x                         = 9,  // 0x058e27
    State_add_int_64                       = 10, // 0x058e36
    State_add_float_64                     = 11, // 0x058e47
    State_sub_int_64                       = 12, // 0x058e5a
    State_sub_float_64                     = 13, // 0x058e6b
    State_mul_int_64                       = 14, // 0x058e7e
    State_mul_float_64                     = 15, // 0x058e8f
    State_div_int_64                       = 16, // 0x058ea2
    State_div_float_64                     = 17, // 0x058eb3
    State_rem_int_64                       = 18, // 0x058ec6
    State_lgc_and                          = 19, // 0x058ed7
    State_lgc_or                           = 20, // 0x058ee5
    State_int_cmp                          = 21, // 0x058ef2
    State_obj_cmp                          = 22, // 0x058f00
    State_invoke                           = 23, // 0x058f0e
    State_invoke_bdi                       = 24, // 0x058f1b
    State_invoke_bdi_1_arg                 = 25, // 0x058f2c
    State_invoke_bdi_2_arg                 = 26, // 0x058f43
    State_invoke_bdi_3_arg                 = 27, // 0x058f5a
    State_back                             = 28, // 0x058f71
    State_print_vl                         = 29, // 0x058f7c
    State_invoke_usrdf_native              = 30, // 0x058f8b
    State_unary                            = 31, // 0x058fa5
    State_if_icmpne_imm                    = 32, // 0x058fb1
    State_jump_imm                         = 33, // 0x058fc5
    State_jump                             = 34, // 0x058fd4
    State_invoke_bdi_0_arg                 = 35, // 0x058fdf
    State_if_icmplt_imm                    = 36, // 0x058ff6
    State_if_icmple_imm                    = 37, // 0x05900a
    State_if_icmpgt_imm                    = 38, // 0x05901e
    State_if_icmpge_imm                    = 39, // 0x059032
    State_if_icmpeq_imm                    = 40, // 0x059046
    State_if_icmpin_imm                    = 41, // 0x05905a
    State_if_icmpnin_imm                   = 42, // 0x05906e
    State_float_cmp                        = 43, // 0x059083
    State_if_fcmplt_imm                    = 44, // 0x059093
    State_if_fcmple_imm                    = 45, // 0x0590a7
    State_if_fcmpgt_imm                    = 46, // 0x0590bb
    State_if_fcmpge_imm                    = 47, // 0x0590cf
    State_invoke_bdi_4_arg                 = 48, // 0x0590e3
    State_invoke_bdi_ge_5_arg              = 49, // 0x0590fa
    State_make_and_get_seq_iter            = 50, // 0x059114
    State_for_seq_iter                     = 51, // 0x059130
    State_list_get_item_imm                = 52, // 0x059143
    State_list_get_item                    = 53, // 0x05915b
    State_list_set_item_imm                = 54, // 0x05916f
    State_list_set_item                    = 55, // 0x059187
    State_if_icmpeqwith0_imm               = 56, // 0x05919b
    State_if_objcmpeqwith_empty_obj_imm    = 57, // 0x0591b4
    State_new_dict_rx                      = 58, // 0x0591d8
    State_store_dict_key                   = 59, // 0x0591ea
    State_get_dict_key                     = 60, // 0x0591ff
    State_store_dict_key_seq               = 61, // 0x059212
    State_val_to_num                       = 62, // 0x05922b
    State_del                              = 63, // 0x05923c
    State_num_to_value                     = 64, // 0x059246
    State_read_constant_none               = 65, // 0x059259
    State_invoke_bdi_ind_param             = 66, // 0x059272
    State_get_sub_items_with_slice         = 67, // 0x05928d
    State_build_slice                      = 68, // 0x0592ac
    State_string_get_item_imm              = 69, // 0x0592be
    State_string_get_item                  = 70, // 0x0592d8
    State_floor_div_int_64                 = 71, // 0x0592ee
    State_bin_op                           = 72  // 0x059305
};

inline constexpr std::size_t kTTMStateCodeCount = 73u;

extern const char* const state_code_names[kTTMStateCodeCount];

// ==============================================================================
// 3. TTMStateErrorCode Enumeration (`.rodata` @ `0x55fff..0x56c80`, `ttm_status_error_code_to_string` @ `0x17640`)
//    Bảng mã lỗi thực thi máy ảo TTM Machine
// ==============================================================================
enum TTMStateErrorCode : std::int32_t {
    TTMStateInvalidErrorCode                              = -1,
    TTMStateErrorCodeSuccess                              = 0,
    TTMStateErrorCodeMachineCodeIsNull                    = 1,
    TTMStateErrorCodeMachineEnvironmentFailed             = 2,
    TTMStateErrorCodeInvalidContent                       = 3,
    TTMStateErrorCodeGreaterVersion                       = 4,
    TTMStateErrorCodeGreaterSectionCount                  = 5,
    TTMStateErrorCodeSectionTypeError                     = 6,
    TTMStateErrorCodeBase64IsNull                         = 7,
    TTMStateErrorCodeDecodeBase64Failed                   = 8,
    TTMStateErrorCodeDecodeBase64OverFlow                 = 9,
    TTMStateErrorCodeTTMIsUnEnable                        = 10,
    TTMStateErrorCodeBytecodeIsNull                       = 11,
    TTMStateErrorCodeReadExtDataIsNull                    = 12,
    TTMStateErrorCodeReadExtDataKeyNotFound               = 13,
    TTMStateErrorCodeReadExtDataIndexOutOfRange           = 14,
    TTMStateErrorCodeInvokeBdiFunException                = 15,
    TTMStateErrorCodeInvokeUnImplementedBdiFun            = 16,
    TTMStateErrorCodeReadExtDataUnSupportType             = 17,
    TTMStateErrorCodeInvokeFindDynamicSymbolFailed        = 18,
    TTMStateErrorCodeReadExtDataIsNotDict                 = 19,
    TTMStateErrorCodeReadExtDataIsNotArray                = 20,
    TTMStateErrorCodeReadExtArrayItemIsNotString          = 21,
    TTMStateErrorCodeReadExtArrayItemIsNotNumber          = 22,
    TTMStateErrorCodeReadExtDictValueItemIsNotString      = 23,
    TTMStateErrorCodeReadExtDictValueItemIsNotNumber      = 24,
    TTMStateErrorCodeReturnTypeUnSupport                  = 25,
    TTMStateErrorCodeReadExtArrayItemIsNULL               = 26,
    TTMStateErrorCodeReadExtDictValueItemIsNULL           = 27,
    TTMStateErrorCodeUnSupportInstruction                 = 28,
    TTMStateErrorCodeGetFrameFailed                       = 29,
    TTMStateErrorCodeCreateObjectFailed                   = 30,
    TTMStateErrorCodeUnSupportObjectType                  = 31,
    TTMStateErrorCodeCreateMNFailed                       = 32,
    TTMStateErrorCodeMemoryAllocFailed                    = 33,
    TTMStateErrorCodeHashMapNewFailed                     = 34,
    TTMStateErrorCodeCreateStateMNCacheStackFailed        = 35,
    TTMStateErrorCodeListReadItemTypeIsNotMatch           = 36,
    TTMStateErrorCodeListReadItemIndexOutOfRange          = 37,
    TTMStateErrorCodeListReadItemIndexListIsNull          = 38,
    TTMStateErrorCodeListIntersectionIsNull               = 39,
    TTMStateErrorCodeListIntersectionTypeNotMatch         = 40,
    TTMStateErrorCodeListUnSupportOperation               = 41,
    TTMStateErrorCodeSeqIterContainerIsNull               = 42,
    TTMStateErrorCodeUnsupportSeqIterContainerType        = 43,
    TTMStateErrorCodeMakeRangeStepHasError                = 44,
    TTMStateErrorCodeCreateObjectValueEmpty               = 45,
    TTMStateErrorCodeListWriteItemIndexOutOfRange         = 46,
    TTMStateErrorCodeListCreateSizeError                  = 47,
    TTMStateErrorCodeGetTTMObjectTypeIsNull               = 48,
    TTMStateErrorCodeListAddObjListNull                   = 49,
    TTMStateErrorCodeConvert2TTMObjectIsNotDict           = 50,
    TTMStateErrorCodeConvert2TTMObjectIsNotList           = 51,
    TTMStateErrorCodeConvert2TTMObjectIsNotStr            = 52,
    TTMStateErrorCodeConvert2TTMObjectIsNotNull           = 53,
    TTMStateErrorCodeSliceStepIs0                         = 54,
    TTMStateErrorCodeReadListSubSliceIsNull               = 55,
    TTMStateErrorCodeReadStringSubSliceIsNull             = 56,
    TTMStateErrorCodeReadStringSubSliceSourceIsNull       = 57,
    TTMStateErrorCodeReadStringSubStringRangeOutOfRange   = 58,
    TTMStateErrorCodeIntegerDivisionOrmoduloByZero        = 59,
    TTMStateErrorCodeListAddContentTypeIsNotEqual         = 60,
    TTMStateErrorCodeListItemNotInSourceList              = 61,
    TTMStateErrorCodeObjectToStringIsNull                 = 62,
    TTMStateErrorCodeListRemoveItemContainerIsNull        = 63,
    TTMStateErrorCodeGetSliceSourceTypeNotSupport         = 64,
    TTMStateErrorCodeBinOpDataTypeNotSupport              = 65,
    TTMStateErrorCodeBinOpShiftIsNegative                 = 66,
    TTMStateErrorCodeBinOpShiftHasOverflow                = 67,
    TTMStateErrorCodeListOperationDataTypeNoSupport       = 68,
    TTMStateErrorCodeListOperationIsEmpty                 = 69,
    TTMStateErrorCodeStringIsNull                         = 70,
    TTMStateErrorCodeParameterIsIllegal                   = 71,
    TTMStateErrorCodeListIsEmpty                          = 72,
    TTMStateErrorCodeListNotFindTargetValue               = 73,
    TTMStateErrorCodeSubStringNotFind                     = 74,
    TTMStateErrorCodeStringIsEmpty                        = 75,
    TTMStateErrorCodeIsNotStringType                      = 76,
    TTMStateErrorCodeIOperationDataTypeNotMatch           = 77,
    TTMStateErrorCodeCreateExtObjectFailed                = 78,
    TTMStateErrorCodeObjectIsNone                         = 79,
    TTMStateErrorJson2ObjectFailed                        = 80,
    TTMStateErrorCodeDictKeyError                         = 81,
    TTMStateErrorCodeContainerSelfNull                    = 82,
    TTMStateErrorCodeDictSetItemNull                      = 83,
    TTMStateErrorCodeDictTTMDictGetItemSelfOrKeyNull      = 84,
    TTMStateErrorCodeCastTypeMisMatch                     = 85,
    TTMStateErrorCodeUnsupportItemType                    = 86,
    TTMStateErrorCodeDictHashMapOOM                       = 87,
    TTMStateErrorCodeDictEntityNull                       = 88,
    TTMStateErrorCodeNoneTypeNoLen                        = 89,
    TTMStateErrorCodeObjectNull                           = 90,
    TTMStateErrorCodeStrCharValueNull                     = 91,
    TTMStateErrorCodeDictKeyTypeUnknown                   = 92,
    TTMStateErrorCodeNotSupportExtObj                     = 93,
    TTMStateErrorCodeNotModifyImplement                   = 94,
    TTMStateErrorCodeObjectCanNotModify                   = 95,
    TTMStateErrorCodeAndroidMidOrClassNotFound            = 96,
    TTMStateErrorTransformIsNoneObj                       = 97,
    TTMStateDTEngineFileNotFound                          = 401,
    TTMStateDTEngineNotImplemented                        = 402,
    TTMStateDTEngineErrUnexpected                         = 403,
    TTMStateDTEngineErrDataNoMatch                        = 404,
    TTMStateDTEngineErrInputData                          = 405,
    TTMStateDTEngineModelParsingError                     = 406,
    TTMStateDTEngineErrUnknown                            = 407,
    TTMStateDTEngineOutPutSizeIsNotMatch                  = 408,
    TTMStateDTEngineNotCreated                            = 409,
    TTMStateDTEngineLeafOutPutSizeIsNotMatch              = 410,
    TTMStateDTEngineIsNull                                = 411,
    TTMStateDTEngineLoadModelButEngineIsNull              = 412,
    TTMStateDTEngineInputDataTypeIsNotMatch               = 413,
    TTMStateDTEngineOutPutDataTypeNotSupport              = 414,
    TTMStateDTEngineIsNotByteDTType                       = 415,
    TTMStateDTEngineCreateRuleNameOrEngineKeyIsNull       = 416,
    TTMStateDTEngineWrapperIsNull                         = 417,
    TTMStateErrorCodeNNPluginInferError                   = 501,
    TTMStateErrorCodeNNPluginClassMisMatched              = 502,
    TTMStateErrorCodeNNPluginDisable                      = 503,
    TTMStateErrorCodeEngineMaxErrorCode                   = 1000
};

// ==============================================================================
// 4. Built-in TTMTypeObject (192 bytes = 0xc0) & Object Hierarchy
//    Hệ thống đối tượng kiểu Python-like của TTMachineCore (`0x6c048..0x6c648`)
// ==============================================================================
struct _object;

using TTMDeallocFunc = void (*)(_object*);
using TTMToStringFunc = _object* (*)(_object*);

struct alignas(8) TTMTypeObject {
    std::int64_t    ob_refcnt{1};        // +0x00
    TTMTypeObject*  ob_type{nullptr};    // +0x08
    std::int64_t    ob_size{0};          // +0x10
    const char*     tp_name{nullptr};    // +0x18 ("dict", "float", "int", "iterator", "list", "none", "slice", "str")
    std::size_t     tp_basicsize{0};     // +0x20 (32, 24, 24, 32, 448, 16, 48, 80)
    std::size_t     tp_itemsize{0};      // +0x28 (0, 8, 8, 0, 0, 0, 0, 1)
    TTMDeallocFunc  tp_dealloc{nullptr}; // +0x30
    TTMToStringFunc tp_str{nullptr};     // +0x38
    std::uint64_t   tp_reserved[16]{};   // +0x40..0xbf (total = 192 bytes)
};

static_assert(sizeof(TTMTypeObject) == 192, "TTMTypeObject must match 192-byte (0xc0) .data layout");

extern TTMTypeObject TTMDictO_Type;    // @ 0x6c048 (tp_name="dict", basicsize=32, itemsize=0)
extern TTMTypeObject TTMFloatO_Type;   // @ 0x6c108 (tp_name="float", basicsize=24, itemsize=8)
extern TTMTypeObject TTMIntO_Type;     // @ 0x6c1c8 (tp_name="int", basicsize=24, itemsize=8)
extern TTMTypeObject TTMSeqIterO_Type; // @ 0x6c288 (tp_name="iterator", basicsize=32, itemsize=0)
extern TTMTypeObject TTMListO_Type;    // @ 0x6c348 (tp_name="list", basicsize=448, itemsize=0)
extern TTMTypeObject TTMNoneO_Type;    // @ 0x6c408 (tp_name="none", basicsize=16, itemsize=0)
extern TTMTypeObject TTMSliceO_Type;   // @ 0x6c4c8 (tp_name="slice", basicsize=48, itemsize=0)
extern TTMTypeObject TTMStrO_Type;     // @ 0x6c588 (tp_name="str", basicsize=80, itemsize=1)

struct _object {
    std::int64_t   ob_refcnt{1};      // +0x00
    TTMTypeObject* ob_type{nullptr};  // +0x08
    virtual ~_object() = default;
};

struct TTMIntO : _object {
    std::int64_t ob_ival{0};          // +0x10 (basicsize = 24)
};

struct TTMFloatO : _object {
    double ob_fval{0.0};              // +0x10 (basicsize = 24)
};

struct TTMStrO : _object {
    std::int64_t ob_size{0};          // +0x10
    std::int64_t ob_shash{-1};        // +0x18
    char*        ob_sval{nullptr};    // +0x20
    std::string  owned_storage{};     // C++17 backing storage for safe RAII management
};

struct TTMSliceO : _object {
    std::int64_t start{0};            // +0x10
    std::int64_t stop{0};             // +0x18
    std::int64_t step{1};             // +0x20 (basicsize = 48)
    bool         has_start{true};
    bool         has_stop{true};
};

enum class TTMListElemKind : std::int32_t {
    kObjectElements = 0,
    kIntElements    = 1,
    kFloatElements  = 2
};

struct TTMListO : _object {
    std::int64_t               ob_size{0};
    TTMListElemKind            elem_kind{TTMListElemKind::kObjectElements};
    std::vector<_object*>      obj_items{};
    std::vector<std::int64_t>  int_items{};
    std::vector<double>        float_items{};
};

struct ttm_hashmap;

struct _dictobject : _object {
    ttm_hashmap*                             ma_table{nullptr};
    std::unordered_map<std::string, _object*> entries{};
};

struct TTMSeqIterO : _object {
    std::int64_t it_index{0};         // +0x10
    _object*     it_seq{nullptr};     // +0x18 (basicsize = 32)
};

// ==============================================================================
// 5. Execution Telemetry & Transparent Context (`__TTMTransparentStruct`)
//    Cấu trúc thống kê thực thi và ngữ cảnh truyền suốt
// ==============================================================================
struct TTMStateErrorInfo {
    std::int32_t error_code{0};       // +0x00
    const char*  func_name{nullptr};  // +0x08
    std::int32_t line_number{0};      // +0x10
    std::string  error_message{};
};

struct TTMExecutionStatistics {
    std::uint64_t start_time_us{0};
    std::uint64_t end_time_us{0};
    std::uint64_t instruction_count{0};
};

struct TTMPreprocessStatistics {
    std::uint64_t decode_time_us{0};
    std::uint64_t bytecode_size{0};
};

class TTMExtDataInterface;

struct __TTMTransparentStruct {
    TTMStateErrorInfo*       error_info{nullptr};        // +0x00
    TTMExtDataInterface*     ext_data{nullptr};          // +0x08
    void*                    user_context{nullptr};      // +0x10
    TTMExecutionStatistics*  exec_stats{nullptr};        // +0x18
    TTMPreprocessStatistics* preprocess_stats{nullptr};  // +0x20
    void*                    arena_manager{nullptr};     // +0x28
    std::int32_t             business_error_base{1000};  // +0x30
};

enum class ElementValueType : std::int32_t {
    kUnknown = 0,
    kInt     = 1,
    kFloat   = 2,
    kString  = 3,
    kBool    = 4,
    kDict    = 5,
    kList    = 6,
    kObject  = 7
};

struct GetValueResult {
    ElementValueType type{ElementValueType::kUnknown};
    std::int64_t     int_val{0};
    double           float_val{0.0};
    bool             bool_val{false};
    std::string      str_val{};
    void*            ext_obj{nullptr};
};

} // namespace NextAI::OpenCut::TTMachineCore
