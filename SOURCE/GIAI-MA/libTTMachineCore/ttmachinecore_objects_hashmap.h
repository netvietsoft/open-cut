// ==============================================================================
// FILE: ttmachinecore_objects_hashmap.h
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols)
// PURPOSE: Open-Addressing Hashmap (`ttm_hashmap_*`, `hashmap_sip`, `hashmap_murmur`),
//          Arena Memory Manager (`ttm_am_*`), and 8 Built-in Object Types
//          (`TTMDict`, `TTMListO`, `TTMStrO`, `TTMIntO`, `TTMFloatO`, `TTMSliceO`,
//          `TTMSeqIterO`, `TTMNoneO`)
//          (Bảng băm địa chỉ mở, Bộ quản lý bộ nhớ Arena, và 8 kiểu đối tượng dựng sẵn)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 .text `0x1aa34..0x25cf0` & .data `0x6c048..0x6c588`)
// ==============================================================================

#pragma once

#include "ttmachinecore_types.h"

namespace NextAI::OpenCut::TTMachineCore {

// ==============================================================================
// 1. Open-Addressing Hashmap (`ttm_hashmap_*` @ `0x1aa34..0x1b81c`)
//    Bảng băm địa chỉ mở kèm SipHash-2-4 và MurmurHash3
// ==============================================================================
using TTMHashFunc = std::uint64_t (*)(const void* item, std::uint64_t seed0, std::uint64_t seed1);
using TTMCmpFunc  = int (*)(const void* a, const void* b, void* udata);
using TTMElfFreeFunc = void (*)(void* item);

struct ttm_hashmap {
    std::size_t              elsize{0};
    std::size_t              cap{0};
    std::uint64_t            seed0{0};
    std::uint64_t            seed1{0};
    TTMHashFunc              hash{nullptr};
    TTMCmpFunc               compare{nullptr};
    TTMElfFreeFunc           elfree{nullptr};
    void*                    udata{nullptr};
    std::vector<std::vector<std::uint8_t>> items{};
    bool                     oom{false};
};

// SipHash-2-4 (`0x1b5e8`, 564 B) & MurmurHash3 (`0x1b81c`, 840 B)
std::uint64_t hashmap_sip(const void* data, std::size_t len, std::uint64_t seed0, std::uint64_t seed1) noexcept;
std::uint64_t hashmap_murmur(const void* data, std::size_t len, std::uint64_t seed0, std::uint64_t seed1) noexcept;

ttm_hashmap* ttm_hashmap_new(
    std::size_t elsize,
    std::size_t cap,
    std::uint64_t seed0,
    std::uint64_t seed1,
    TTMHashFunc hash,
    TTMCmpFunc compare,
    TTMElfFreeFunc elfree,
    void* udata);

void        ttm_hashmap_clear(ttm_hashmap* map, bool update_cap);
const void* ttm_hashmap_set(ttm_hashmap* map, const void* item);
const void* ttm_hashmap_get(const ttm_hashmap* map, const void* key);
const void* ttm_hashmap_delete(ttm_hashmap* map, const void* key);
std::size_t ttm_hashmap_count(const ttm_hashmap* map) noexcept;
void        ttm_hashmap_free(ttm_hashmap* map);
bool        ttm_hashmap_oom(const ttm_hashmap* map) noexcept;
bool        ttm_hashmap_scan(ttm_hashmap* map, bool (*iter)(const void* item, void* udata), void* udata);
bool        ttm_hashmap_iter(const ttm_hashmap* map, std::size_t* i, void** item);

// ==============================================================================
// 2. Arena Memory Manager (`ttm_am_*` @ `0x22dd8..0x233b8`)
//    Bộ quản lý cấp phát vùng nhớ đối tượng Arena theo phiên thực thi
// ==============================================================================
void     ttm_am_start(__TTMTransparentStruct* ctx);
void     ttm_am_end(__TTMTransparentStruct* ctx);
void     ttm_am_clean_objs(__TTMTransparentStruct* ctx);
_object* ttm_am_object_create(TTMTypeObject* type, __TTMTransparentStruct* ctx);
_object* ttm_am_object_create_no_record(TTMTypeObject* type);
void     ttm_release_obj(_object* obj) noexcept;
_object* ttm_object_copy(_object* src, __TTMTransparentStruct* ctx);

// ==============================================================================
// 3. Built-in Object Operations (`0x1ec64..0x25cf0`)
//    Các hàm thao tác trên TTMDict, TTMIntO, TTMFloatO, TTMStrO, TTMListO, TTMSliceO
// ==============================================================================

// TTMDict (`0x1ecf0..0x1f2a8`)
_dictobject* TTMDict_create(__TTMTransparentStruct* ctx);
int          TTMDict_set_item(_dictobject* dict, TTMStrO* key, _object* val, __TTMTransparentStruct* ctx);
int          TTMDict_remove_item(_dictobject* dict, TTMStrO* key, __TTMTransparentStruct* ctx);
TTMListO*    TTMDict_keys(_dictobject* dict, __TTMTransparentStruct* ctx);
TTMListO*    TTMDict_values(_dictobject* dict, __TTMTransparentStruct* ctx);
void         TTMDict_clear(_dictobject* dict);
std::int64_t TTMDict_object_size(const _dictobject* dict) noexcept;
bool         TTMDict_contain_key(const _dictobject* dict, const TTMStrO* key) noexcept;
_object*     TTMDict_get_item(const _dictobject* dict, const TTMStrO* key, __TTMTransparentStruct* ctx);
TTMStrO*     TTMDict_to_string(const _dictobject* dict, __TTMTransparentStruct* ctx);

// TTMIntO & TTMFloatO (`0x1f678..0x1fadc`)
TTMFloatO*   TTMFloatO_create(double val, __TTMTransparentStruct* ctx);
TTMStrO*     TTMFloat_to_string(const TTMFloatO* obj, __TTMTransparentStruct* ctx);
TTMIntO*     TTMIntO_create(std::int64_t val, __TTMTransparentStruct* ctx);
TTMStrO*     TTMInt_to_string(const TTMIntO* obj, __TTMTransparentStruct* ctx);
_object*     TTM_None() noexcept;
TTMStrO*     TTMNone_to_stirng(__TTMTransparentStruct* ctx);

// TTMSeqIterO (`0x1fc9c..0x1ff44`)
TTMSeqIterO* TTMSeqIterO_create(_object* seq, __TTMTransparentStruct* ctx);
_object*     TTMSeqIterO_Next_Object(TTMSeqIterO* iter, __TTMTransparentStruct* ctx);
std::int64_t TTMSeqIterO_Next_Int(TTMSeqIterO* iter, bool* has_next, __TTMTransparentStruct* ctx);
double       TTMSeqIterO_Next_Float(TTMSeqIterO* iter, bool* has_next, __TTMTransparentStruct* ctx);

// TTMListO (`0x20158..0x227f0`)
TTMListO*    TTMListO_create(std::int64_t cap, TTMListElemKind kind, __TTMTransparentStruct* ctx);
double       TTMListO_fmax_value(const TTMListO* list, __TTMTransparentStruct* ctx);
double       TTMListO_fmin_value(const TTMListO* list, __TTMTransparentStruct* ctx);
double       TTMListO_sum_value(const TTMListO* list, __TTMTransparentStruct* ctx);
double       TTMListO_favg_value(const TTMListO* list, __TTMTransparentStruct* ctx);
double       TTMListo_variance_value(const TTMListO* list, __TTMTransparentStruct* ctx);
double       TTMListo_std_deviation_value(const TTMListO* list, __TTMTransparentStruct* ctx);
int          TTMListO_add_obj(TTMListO* list, _object* item, __TTMTransparentStruct* ctx);
int          TTMListO_add_int_value(TTMListO* list, std::int64_t val, __TTMTransparentStruct* ctx);
int          TTMListO_add_float_value(TTMListO* list, double val, __TTMTransparentStruct* ctx);
std::int64_t TTMListO_Object_size(const TTMListO* list) noexcept;
_object*     TTMListO_Object_Index(const TTMListO* list, std::int64_t idx, __TTMTransparentStruct* ctx);
std::int64_t TTMListO_Int_Index(const TTMListO* list, std::int64_t idx, __TTMTransparentStruct* ctx);
double       TTMListO_Float_Index(const TTMListO* list, std::int64_t idx, __TTMTransparentStruct* ctx);
void         TTMListO_clear(TTMListO* list);
void         TTMListO_reverse(TTMListO* list);
TTMListO*    TTMListO_sublist_with_slice(const TTMListO* list, const TTMSliceO* slice, __TTMTransparentStruct* ctx);
TTMListO*    TTMListO_value_set_operation(const TTMListO* lhs, const TTMListO* rhs, int op_mode, __TTMTransparentStruct* ctx);
TTMStrO*     TTMList_to_string(const TTMListO* list, __TTMTransparentStruct* ctx);

// TTMSliceO (`0x23814..0x23a48`)
TTMSliceO*   TTMSliceO_create(std::int64_t start, std::int64_t stop, std::int64_t step, bool has_start, bool has_stop, __TTMTransparentStruct* ctx);
std::int64_t TTMSlice_adjust_indices(std::int64_t length, std::int64_t* start, std::int64_t* stop, std::int64_t step) noexcept;
TTMStrO*     TTMSlice_to_string(const TTMSliceO* slice, __TTMTransparentStruct* ctx);

// TTMStrO (`0x25264..0x25cf0`)
TTMStrO*     TTMStrO_create_empty_str_with_size(std::size_t size, __TTMTransparentStruct* ctx);
TTMStrO*     TTMStrO_from_cstr(const char* cstr, __TTMTransparentStruct* ctx);
TTMStrO*     TTMStrO_from_char(char ch, __TTMTransparentStruct* ctx);
const char*  ttm_ttmstro_to_cstr(const TTMStrO* str) noexcept;
TTMStrO*     TTMStrO_substring_with_slice(const TTMStrO* str, const TTMSliceO* slice, __TTMTransparentStruct* ctx);
TTMStrO*     TTMStrO_add(const TTMStrO* lhs, const TTMStrO* rhs, __TTMTransparentStruct* ctx);
bool         TTMStr_is_contain(const TTMStrO* haystack, const TTMStrO* needle) noexcept;
bool         TTMStr_string_eq(const TTMStrO* lhs, const TTMStrO* rhs) noexcept;

} // namespace NextAI::OpenCut::TTMachineCore
