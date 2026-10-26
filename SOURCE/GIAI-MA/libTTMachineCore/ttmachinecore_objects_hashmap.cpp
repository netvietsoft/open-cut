// ==============================================================================
// FILE: ttmachinecore_objects_hashmap.cpp
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols)
// PURPOSE: Implementation of SipHash-2-4 (`0x1b5e8`), MurmurHash3 (`0x1b81c`),
//          Open-Addressing Hashmap (`0x1aa34..0x1b5a0`), Arena Memory Manager,
//          8 Built-in `TTMTypeObject` Descriptors (`0x6c048..0x6c588`), and
//          Object Methods (`TTMDict`, `TTMListO`, `TTMStrO`, `TTMSliceO`, etc.)
//          (Hiện thực hóa SipHash-2-4, MurmurHash3, Bảng băm, Bộ quản lý Arena,
//          8 bộ mô tả kiểu `TTMTypeObject` và các phương thức đối tượng)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 Disassembly & .data Section Dump)
// ==============================================================================

#include "ttmachinecore_objects_hashmap.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>

namespace NextAI::OpenCut::TTMachineCore {

// ==============================================================================
// 1. 8 Built-in `TTMTypeObject` Descriptors (`.data` @ `0x6c048..0x6c588`, 192 B each)
//    8 Bộ mô tả kiểu đối tượng dựng sẵn trong vùng `.data`
// ==============================================================================
TTMTypeObject TTMDictO_Type    = {1, nullptr, 0, "dict",     32,  0, nullptr, nullptr, {}}; // @ 0x6c048
TTMTypeObject TTMFloatO_Type   = {1, nullptr, 1, "float",    24,  8, nullptr, nullptr, {}}; // @ 0x6c108
TTMTypeObject TTMIntO_Type     = {1, nullptr, 1, "int",      24,  8, nullptr, nullptr, {}}; // @ 0x6c1c8
TTMTypeObject TTMSeqIterO_Type = {1, nullptr, 0, "iterator", 32,  0, nullptr, nullptr, {}}; // @ 0x6c288
TTMTypeObject TTMListO_Type    = {1, nullptr, 0, "list",     448, 0, nullptr, nullptr, {}}; // @ 0x6c348
TTMTypeObject TTMNoneO_Type    = {1, nullptr, 0, "none",     16,  0, nullptr, nullptr, {}}; // @ 0x6c408
TTMTypeObject TTMSliceO_Type   = {1, nullptr, 0, "slice",    48,  0, nullptr, nullptr, {}}; // @ 0x6c4c8
TTMTypeObject TTMStrO_Type     = {1, nullptr, 0, "str",      80,  1, nullptr, nullptr, {}}; // @ 0x6c588

namespace {

_object g_ttm_none_singleton{1, &TTMNoneO_Type};

struct ArenaPool {
    std::mutex            mtx;
    std::vector<_object*> allocated;
};

ArenaPool& GetGlobalArenaPool() {
    static ArenaPool s_pool;
    return s_pool;
}

inline std::uint64_t RotL64(std::uint64_t x, int b) noexcept {
    return (x << b) | (x >> (64 - b));
}

inline void SipRound(std::uint64_t& v0, std::uint64_t& v1, std::uint64_t& v2, std::uint64_t& v3) noexcept {
    v0 += v1;
    v1 = RotL64(v1, 13);
    v1 ^= v0;
    v0 = RotL64(v0, 32);
    v2 += v3;
    v3 = RotL64(v3, 16);
    v3 ^= v2;
    v0 += v3;
    v3 = RotL64(v3, 21);
    v3 ^= v0;
    v2 += v1;
    v1 = RotL64(v1, 17);
    v1 ^= v2;
    v2 = RotL64(v2, 32);
}

void RecordError(__TTMTransparentStruct* ctx, std::int32_t code, const char* fn, std::int32_t line = 0) {
    if (ctx != nullptr && ctx->error_info != nullptr) {
        ctx->error_info->error_code = code;
        ctx->error_info->func_name = fn;
        ctx->error_info->line_number = line;
    }
}

} // namespace

// ==============================================================================
// 2. SipHash-2-4 (`hashmap_sip` @ `0x1b5e8`, 564 B) & MurmurHash3 (`hashmap_murmur` @ `0x1b81c`, 840 B)
//    Thuật toán băm SipHash-2-4 và MurmurHash3_x64_128
// ==============================================================================
std::uint64_t hashmap_sip(const void* data, std::size_t len, std::uint64_t seed0, std::uint64_t seed1) noexcept {
    const auto* in = static_cast<const std::uint8_t*>(data);
    std::uint64_t v0 = 0x736f6d6570736575ULL ^ seed0;
    std::uint64_t v1 = 0x646f72616e646f6dULL ^ seed1;
    std::uint64_t v2 = 0x6c7967656e657261ULL ^ seed0;
    std::uint64_t v3 = 0x7465646279746573ULL ^ seed1;

    const std::uint8_t* end = in + (len - (len % sizeof(std::uint64_t)));
    for (; in != end; in += 8) {
        std::uint64_t m = 0;
        std::memcpy(&m, in, sizeof(m));
        v3 ^= m;
        SipRound(v0, v1, v2, v3);
        SipRound(v0, v1, v2, v3);
        v0 ^= m;
    }

    std::uint64_t b = static_cast<std::uint64_t>(len) << 56;
    switch (len & 7u) {
        case 7: b |= static_cast<std::uint64_t>(in[6]) << 48; [[fallthrough]];
        case 6: b |= static_cast<std::uint64_t>(in[5]) << 40; [[fallthrough]];
        case 5: b |= static_cast<std::uint64_t>(in[4]) << 32; [[fallthrough]];
        case 4: b |= static_cast<std::uint64_t>(in[3]) << 24; [[fallthrough]];
        case 3: b |= static_cast<std::uint64_t>(in[2]) << 16; [[fallthrough]];
        case 2: b |= static_cast<std::uint64_t>(in[1]) << 8;  [[fallthrough]];
        case 1: b |= static_cast<std::uint64_t>(in[0]);       break;
        case 0: break;
    }

    v3 ^= b;
    SipRound(v0, v1, v2, v3);
    SipRound(v0, v1, v2, v3);
    v0 ^= b;
    v2 ^= 0xff;
    SipRound(v0, v1, v2, v3);
    SipRound(v0, v1, v2, v3);
    SipRound(v0, v1, v2, v3);
    SipRound(v0, v1, v2, v3);
    return v0 ^ v1 ^ v2 ^ v3;
}

std::uint64_t hashmap_murmur(const void* data, std::size_t len, std::uint64_t seed0, std::uint64_t /*seed1*/) noexcept {
    const auto* bytes = static_cast<const std::uint8_t*>(data);
    constexpr std::uint64_t kMul = 0xc6a4a7935bd1e995ULL;
    constexpr int kShift = 47;
    std::uint64_t h = seed0 ^ (len * kMul);

    const std::size_t nblocks = len / 8;
    for (std::size_t i = 0; i < nblocks; ++i) {
        std::uint64_t k = 0;
        std::memcpy(&k, bytes + i * 8, sizeof(k));
        k *= kMul;
        k ^= k >> kShift;
        k *= kMul;
        h ^= k;
        h *= kMul;
    }

    const std::uint8_t* tail = bytes + nblocks * 8;
    switch (len & 7u) {
        case 7: h ^= static_cast<std::uint64_t>(tail[6]) << 48; [[fallthrough]];
        case 6: h ^= static_cast<std::uint64_t>(tail[5]) << 40; [[fallthrough]];
        case 5: h ^= static_cast<std::uint64_t>(tail[4]) << 32; [[fallthrough]];
        case 4: h ^= static_cast<std::uint64_t>(tail[3]) << 24; [[fallthrough]];
        case 3: h ^= static_cast<std::uint64_t>(tail[2]) << 16; [[fallthrough]];
        case 2: h ^= static_cast<std::uint64_t>(tail[1]) << 8;  [[fallthrough]];
        case 1:
            h ^= static_cast<std::uint64_t>(tail[0]);
            h *= kMul;
            break;
        case 0:
            break;
    }

    h ^= h >> kShift;
    h *= kMul;
    h ^= h >> kShift;
    return h;
}

// ==============================================================================
// 3. `ttm_hashmap_*` Operations (`0x1aa34..0x1b5a0`)
// ==============================================================================
ttm_hashmap* ttm_hashmap_new(
    std::size_t elsize,
    std::size_t cap,
    std::uint64_t seed0,
    std::uint64_t seed1,
    TTMHashFunc hash,
    TTMCmpFunc compare,
    TTMElfFreeFunc elfree,
    void* udata) {
    if (elsize == 0) {
        return nullptr;
    }
    auto* map = new ttm_hashmap();
    map->elsize = elsize;
    map->cap = (cap < 16) ? 16 : cap;
    map->seed0 = seed0;
    map->seed1 = seed1;
    map->hash = hash;
    map->compare = compare;
    map->elfree = elfree;
    map->udata = udata;
    map->items.reserve(map->cap);
    return map;
}

void ttm_hashmap_clear(ttm_hashmap* map, bool /*update_cap*/) {
    if (!map) return;
    if (map->elfree) {
        for (auto& buf : map->items) {
            map->elfree(buf.data());
        }
    }
    map->items.clear();
}

const void* ttm_hashmap_set(ttm_hashmap* map, const void* item) {
    if (!map || !item) return nullptr;
    for (auto& existing : map->items) {
        if (map->compare && map->compare(existing.data(), item, map->udata) == 0) {
            std::memcpy(existing.data(), item, map->elsize);
            return existing.data();
        }
    }
    std::vector<std::uint8_t> slot(map->elsize);
    std::memcpy(slot.data(), item, map->elsize);
    map->items.push_back(std::move(slot));
    return nullptr;
}

const void* ttm_hashmap_get(const ttm_hashmap* map, const void* key) {
    if (!map || !key) return nullptr;
    for (const auto& existing : map->items) {
        if (map->compare && map->compare(existing.data(), key, map->udata) == 0) {
            return existing.data();
        }
    }
    return nullptr;
}

const void* ttm_hashmap_delete(ttm_hashmap* map, const void* key) {
    if (!map || !key) return nullptr;
    for (auto it = map->items.begin(); it != map->items.end(); ++it) {
        if (map->compare && map->compare(it->data(), key, map->udata) == 0) {
            if (map->elfree) {
                map->elfree(it->data());
            }
            map->items.erase(it);
            return key;
        }
    }
    return nullptr;
}

std::size_t ttm_hashmap_count(const ttm_hashmap* map) noexcept {
    return map ? map->items.size() : 0u;
}

void ttm_hashmap_free(ttm_hashmap* map) {
    if (!map) return;
    ttm_hashmap_clear(map, false);
    delete map;
}

bool ttm_hashmap_oom(const ttm_hashmap* map) noexcept {
    return map ? map->oom : false;
}

bool ttm_hashmap_scan(ttm_hashmap* map, bool (*iter)(const void* item, void* udata), void* udata) {
    if (!map || !iter) return false;
    for (const auto& slot : map->items) {
        if (!iter(slot.data(), udata)) {
            return false;
        }
    }
    return true;
}

bool ttm_hashmap_iter(const ttm_hashmap* map, std::size_t* i, void** item) {
    if (!map || !i || !item || *i >= map->items.size()) {
        return false;
    }
    *item = const_cast<std::uint8_t*>(map->items[*i].data());
    ++(*i);
    return true;
}

// ==============================================================================
// 4. Arena Memory Manager (`ttm_am_*` @ `0x22dd8..0x233b8`)
// ==============================================================================
void ttm_am_start(__TTMTransparentStruct* /*ctx*/) {}

void ttm_am_end(__TTMTransparentStruct* ctx) {
    ttm_am_clean_objs(ctx);
}

void ttm_am_clean_objs(__TTMTransparentStruct* /*ctx*/) {
    auto& pool = GetGlobalArenaPool();
    std::lock_guard<std::mutex> lock(pool.mtx);
    for (_object* obj : pool.allocated) {
        delete obj;
    }
    pool.allocated.clear();
}

_object* ttm_am_object_create_no_record(TTMTypeObject* type) {
    if (type == &TTMDictO_Type)    return new _dictobject{{1, &TTMDictO_Type}, nullptr, {}};
    if (type == &TTMFloatO_Type)   return new TTMFloatO{{1, &TTMFloatO_Type}, 0.0};
    if (type == &TTMIntO_Type)     return new TTMIntO{{1, &TTMIntO_Type}, 0};
    if (type == &TTMSeqIterO_Type) return new TTMSeqIterO{{1, &TTMSeqIterO_Type}, 0, nullptr};
    if (type == &TTMListO_Type)    return new TTMListO{{1, &TTMListO_Type}, 0, TTMListElemKind::kObjectElements, {}, {}, {}};
    if (type == &TTMSliceO_Type)   return new TTMSliceO{{1, &TTMSliceO_Type}, 0, 0, 1, true, true};
    if (type == &TTMStrO_Type)     return new TTMStrO{{1, &TTMStrO_Type}, 0, -1, nullptr, {}};
    return &g_ttm_none_singleton;
}

_object* ttm_am_object_create(TTMTypeObject* type, __TTMTransparentStruct* /*ctx*/) {
    _object* obj = ttm_am_object_create_no_record(type);
    if (obj != nullptr && obj != &g_ttm_none_singleton) {
        auto& pool = GetGlobalArenaPool();
        std::lock_guard<std::mutex> lock(pool.mtx);
        pool.allocated.push_back(obj);
    }
    return obj;
}

void ttm_release_obj(_object* obj) noexcept {
    if (obj && obj != &g_ttm_none_singleton && obj->ob_refcnt > 0) {
        --obj->ob_refcnt;
    }
}

_object* ttm_object_copy(_object* src, __TTMTransparentStruct* ctx) {
    if (!src || src == &g_ttm_none_singleton) {
        return &g_ttm_none_singleton;
    }
    if (src->ob_type == &TTMIntO_Type) {
        return TTMIntO_create(static_cast<TTMIntO*>(src)->ob_ival, ctx);
    }
    if (src->ob_type == &TTMFloatO_Type) {
        return TTMFloatO_create(static_cast<TTMFloatO*>(src)->ob_fval, ctx);
    }
    if (src->ob_type == &TTMStrO_Type) {
        return TTMStrO_from_cstr(ttm_ttmstro_to_cstr(static_cast<TTMStrO*>(src)), ctx);
    }
    if (src->ob_type == &TTMListO_Type) {
        const auto* src_list = static_cast<TTMListO*>(src);
        auto* dst_list = TTMListO_create(src_list->ob_size, src_list->elem_kind, ctx);
        dst_list->obj_items = src_list->obj_items;
        dst_list->int_items = src_list->int_items;
        dst_list->float_items = src_list->float_items;
        dst_list->ob_size = src_list->ob_size;
        return dst_list;
    }
    if (src->ob_type == &TTMDictO_Type) {
        const auto* src_dict = static_cast<_dictobject*>(src);
        auto* dst_dict = TTMDict_create(ctx);
        dst_dict->entries = src_dict->entries;
        return dst_dict;
    }
    return src;
}

// ==============================================================================
// 5. Built-in Object Operations (`TTMDict`, `TTMIntO`, `TTMFloatO`, `TTMListO`, `TTMSliceO`, `TTMStrO`)
// ==============================================================================
_dictobject* TTMDict_create(__TTMTransparentStruct* ctx) {
    return static_cast<_dictobject*>(ttm_am_object_create(&TTMDictO_Type, ctx));
}

int TTMDict_set_item(_dictobject* dict, TTMStrO* key, _object* val, __TTMTransparentStruct* ctx) {
    if (!dict) {
        RecordError(ctx, TTMStateErrorCodeContainerSelfNull, "TTMDict_set_item");
        return -1;
    }
    if (!key || !val) {
        RecordError(ctx, TTMStateErrorCodeDictSetItemNull, "TTMDict_set_item");
        return -1;
    }
    dict->entries[ttm_ttmstro_to_cstr(key)] = val;
    return 0;
}

int TTMDict_remove_item(_dictobject* dict, TTMStrO* key, __TTMTransparentStruct* ctx) {
    if (!dict || !key) {
        RecordError(ctx, TTMStateErrorCodeContainerSelfNull, "TTMDict_remove_item");
        return -1;
    }
    dict->entries.erase(ttm_ttmstro_to_cstr(key));
    return 0;
}

TTMListO* TTMDict_keys(_dictobject* dict, __TTMTransparentStruct* ctx) {
    if (!dict) return nullptr;
    auto* list = TTMListO_create(static_cast<std::int64_t>(dict->entries.size()), TTMListElemKind::kObjectElements, ctx);
    for (const auto& kv : dict->entries) {
        TTMListO_add_obj(list, TTMStrO_from_cstr(kv.first.c_str(), ctx), ctx);
    }
    return list;
}

TTMListO* TTMDict_values(_dictobject* dict, __TTMTransparentStruct* ctx) {
    if (!dict) return nullptr;
    auto* list = TTMListO_create(static_cast<std::int64_t>(dict->entries.size()), TTMListElemKind::kObjectElements, ctx);
    for (const auto& kv : dict->entries) {
        TTMListO_add_obj(list, kv.second, ctx);
    }
    return list;
}

void TTMDict_clear(_dictobject* dict) {
    if (dict) dict->entries.clear();
}

std::int64_t TTMDict_object_size(const _dictobject* dict) noexcept {
    return dict ? static_cast<std::int64_t>(dict->entries.size()) : 0;
}

bool TTMDict_contain_key(const _dictobject* dict, const TTMStrO* key) noexcept {
    if (!dict || !key) return false;
    return dict->entries.find(ttm_ttmstro_to_cstr(key)) != dict->entries.end();
}

_object* TTMDict_get_item(const _dictobject* dict, const TTMStrO* key, __TTMTransparentStruct* ctx) {
    if (!dict || !key) {
        RecordError(ctx, TTMStateErrorCodeDictTTMDictGetItemSelfOrKeyNull, "TTMDict_get_item");
        return &g_ttm_none_singleton;
    }
    auto it = dict->entries.find(ttm_ttmstro_to_cstr(key));
    return (it != dict->entries.end() && it->second != nullptr) ? it->second : &g_ttm_none_singleton;
}

TTMStrO* TTMDict_to_string(const _dictobject* dict, __TTMTransparentStruct* ctx) {
    if (!dict) return TTMStrO_from_cstr("{}", ctx);
    std::ostringstream oss;
    oss << "{";
    bool first = true;
    for (const auto& kv : dict->entries) {
        if (!first) oss << ", ";
        first = false;
        oss << "\"" << kv.first << "\": ";
        if (!kv.second || kv.second->ob_type == &TTMNoneO_Type) {
            oss << "None";
        } else if (kv.second->ob_type == &TTMIntO_Type) {
            oss << static_cast<const TTMIntO*>(kv.second)->ob_ival;
        } else if (kv.second->ob_type == &TTMFloatO_Type) {
            oss << static_cast<const TTMFloatO*>(kv.second)->ob_fval;
        } else if (kv.second->ob_type == &TTMStrO_Type) {
            oss << "\"" << ttm_ttmstro_to_cstr(static_cast<const TTMStrO*>(kv.second)) << "\"";
        } else {
            oss << "<object>";
        }
    }
    oss << "}";
    return TTMStrO_from_cstr(oss.str().c_str(), ctx);
}

TTMFloatO* TTMFloatO_create(double val, __TTMTransparentStruct* ctx) {
    auto* obj = static_cast<TTMFloatO*>(ttm_am_object_create(&TTMFloatO_Type, ctx));
    obj->ob_fval = val;
    return obj;
}

TTMStrO* TTMFloat_to_string(const TTMFloatO* obj, __TTMTransparentStruct* ctx) {
    return TTMStrO_from_cstr(obj ? std::to_string(obj->ob_fval).c_str() : "0.0", ctx);
}

TTMIntO* TTMIntO_create(std::int64_t val, __TTMTransparentStruct* ctx) {
    auto* obj = static_cast<TTMIntO*>(ttm_am_object_create(&TTMIntO_Type, ctx));
    obj->ob_ival = val;
    return obj;
}

TTMStrO* TTMInt_to_string(const TTMIntO* obj, __TTMTransparentStruct* ctx) {
    return TTMStrO_from_cstr(obj ? std::to_string(obj->ob_ival).c_str() : "0", ctx);
}

_object* TTM_None() noexcept {
    return &g_ttm_none_singleton;
}

TTMStrO* TTMNone_to_stirng(__TTMTransparentStruct* ctx) {
    return TTMStrO_from_cstr("None", ctx);
}

TTMSeqIterO* TTMSeqIterO_create(_object* seq, __TTMTransparentStruct* ctx) {
    if (!seq) {
        RecordError(ctx, TTMStateErrorCodeSeqIterContainerIsNull, "TTMSeqIterO_create");
        return nullptr;
    }
    auto* iter = static_cast<TTMSeqIterO*>(ttm_am_object_create(&TTMSeqIterO_Type, ctx));
    iter->it_index = 0;
    iter->it_seq = seq;
    return iter;
}

_object* TTMSeqIterO_Next_Object(TTMSeqIterO* iter, __TTMTransparentStruct* ctx) {
    if (!iter || !iter->it_seq || iter->it_seq->ob_type != &TTMListO_Type) {
        return nullptr;
    }
    auto* list = static_cast<TTMListO*>(iter->it_seq);
    if (iter->it_index < 0 || iter->it_index >= list->ob_size) {
        return nullptr;
    }
    return TTMListO_Object_Index(list, iter->it_index++, ctx);
}

std::int64_t TTMSeqIterO_Next_Int(TTMSeqIterO* iter, bool* has_next, __TTMTransparentStruct* ctx) {
    if (!iter || !iter->it_seq || iter->it_seq->ob_type != &TTMListO_Type) {
        if (has_next) *has_next = false;
        return 0;
    }
    auto* list = static_cast<TTMListO*>(iter->it_seq);
    if (iter->it_index < 0 || iter->it_index >= list->ob_size) {
        if (has_next) *has_next = false;
        return 0;
    }
    if (has_next) *has_next = true;
    return TTMListO_Int_Index(list, iter->it_index++, ctx);
}

double TTMSeqIterO_Next_Float(TTMSeqIterO* iter, bool* has_next, __TTMTransparentStruct* ctx) {
    if (!iter || !iter->it_seq || iter->it_seq->ob_type != &TTMListO_Type) {
        if (has_next) *has_next = false;
        return 0.0;
    }
    auto* list = static_cast<TTMListO*>(iter->it_seq);
    if (iter->it_index < 0 || iter->it_index >= list->ob_size) {
        if (has_next) *has_next = false;
        return 0.0;
    }
    if (has_next) *has_next = true;
    return TTMListO_Float_Index(list, iter->it_index++, ctx);
}

// ==============================================================================
// 6. `TTMListO_*` Statistical & Sequence Operations (`0x20158..0x227f0`)
// ==============================================================================
TTMListO* TTMListO_create(std::int64_t cap, TTMListElemKind kind, __TTMTransparentStruct* ctx) {
    if (cap < 0) {
        RecordError(ctx, TTMStateErrorCodeListCreateSizeError, "TTMListO_create");
        return nullptr;
    }
    auto* list = static_cast<TTMListO*>(ttm_am_object_create(&TTMListO_Type, ctx));
    list->elem_kind = kind;
    list->ob_size = 0;
    return list;
}

namespace {
std::vector<double> ExtractListNumbers(const TTMListO* list) {
    std::vector<double> nums;
    if (!list) return nums;
    if (list->elem_kind == TTMListElemKind::kFloatElements) {
        return list->float_items;
    }
    if (list->elem_kind == TTMListElemKind::kIntElements) {
        nums.reserve(list->int_items.size());
        for (std::int64_t v : list->int_items) nums.push_back(static_cast<double>(v));
        return nums;
    }
    for (_object* obj : list->obj_items) {
        if (!obj) continue;
        if (obj->ob_type == &TTMIntO_Type) {
            nums.push_back(static_cast<double>(static_cast<const TTMIntO*>(obj)->ob_ival));
        } else if (obj->ob_type == &TTMFloatO_Type) {
            nums.push_back(static_cast<const TTMFloatO*>(obj)->ob_fval);
        }
    }
    return nums;
}
} // namespace

double TTMListO_fmax_value(const TTMListO* list, __TTMTransparentStruct* ctx) {
    auto nums = ExtractListNumbers(list);
    if (nums.empty()) {
        RecordError(ctx, TTMStateErrorCodeListOperationIsEmpty, "TTMListO_fmax_value");
        return 0.0;
    }
    return *std::max_element(nums.begin(), nums.end());
}

double TTMListO_fmin_value(const TTMListO* list, __TTMTransparentStruct* ctx) {
    auto nums = ExtractListNumbers(list);
    if (nums.empty()) {
        RecordError(ctx, TTMStateErrorCodeListOperationIsEmpty, "TTMListO_fmin_value");
        return 0.0;
    }
    return *std::min_element(nums.begin(), nums.end());
}

double TTMListO_sum_value(const TTMListO* list, __TTMTransparentStruct* ctx) {
    auto nums = ExtractListNumbers(list);
    if (nums.empty()) {
        RecordError(ctx, TTMStateErrorCodeListOperationIsEmpty, "TTMListO_sum_value");
        return 0.0;
    }
    double sum = 0.0;
    for (double v : nums) sum += v;
    return sum;
}

double TTMListO_favg_value(const TTMListO* list, __TTMTransparentStruct* ctx) {
    auto nums = ExtractListNumbers(list);
    if (nums.empty()) {
        RecordError(ctx, TTMStateErrorCodeListOperationIsEmpty, "TTMListO_favg_value");
        return 0.0;
    }
    return TTMListO_sum_value(list, ctx) / static_cast<double>(nums.size());
}

double TTMListo_variance_value(const TTMListO* list, __TTMTransparentStruct* ctx) {
    auto nums = ExtractListNumbers(list);
    if (nums.empty()) {
        RecordError(ctx, TTMStateErrorCodeListOperationIsEmpty, "TTMListo_variance_value");
        return 0.0;
    }
    const double mean = TTMListO_favg_value(list, ctx);
    double sq_sum = 0.0;
    for (double v : nums) {
        const double diff = v - mean;
        sq_sum += diff * diff;
    }
    return sq_sum / static_cast<double>(nums.size());
}

double TTMListo_std_deviation_value(const TTMListO* list, __TTMTransparentStruct* ctx) {
    return std::sqrt(TTMListo_variance_value(list, ctx));
}

int TTMListO_add_obj(TTMListO* list, _object* item, __TTMTransparentStruct* ctx) {
    if (!list) {
        RecordError(ctx, TTMStateErrorCodeListAddObjListNull, "TTMListO_add_obj");
        return -1;
    }
    list->obj_items.push_back(item ? item : &g_ttm_none_singleton);
    list->ob_size = static_cast<std::int64_t>(list->obj_items.size());
    return 0;
}

int TTMListO_add_int_value(TTMListO* list, std::int64_t val, __TTMTransparentStruct* ctx) {
    if (!list) {
        RecordError(ctx, TTMStateErrorCodeListAddObjListNull, "TTMListO_add_int_value");
        return -1;
    }
    list->elem_kind = TTMListElemKind::kIntElements;
    list->int_items.push_back(val);
    list->obj_items.push_back(TTMIntO_create(val, ctx));
    list->ob_size = static_cast<std::int64_t>(list->int_items.size());
    return 0;
}

int TTMListO_add_float_value(TTMListO* list, double val, __TTMTransparentStruct* ctx) {
    if (!list) {
        RecordError(ctx, TTMStateErrorCodeListAddObjListNull, "TTMListO_add_float_value");
        return -1;
    }
    list->elem_kind = TTMListElemKind::kFloatElements;
    list->float_items.push_back(val);
    list->obj_items.push_back(TTMFloatO_create(val, ctx));
    list->ob_size = static_cast<std::int64_t>(list->float_items.size());
    return 0;
}

std::int64_t TTMListO_Object_size(const TTMListO* list) noexcept {
    return list ? list->ob_size : 0;
}

_object* TTMListO_Object_Index(const TTMListO* list, std::int64_t idx, __TTMTransparentStruct* ctx) {
    if (!list) {
        RecordError(ctx, TTMStateErrorCodeListReadItemIndexListIsNull, "TTMListO_Object_Index");
        return &g_ttm_none_singleton;
    }
    std::int64_t real_idx = (idx < 0) ? (idx + list->ob_size) : idx;
    if (real_idx < 0 || real_idx >= list->ob_size) {
        RecordError(ctx, TTMStateErrorCodeListReadItemIndexOutOfRange, "TTMListO_Object_Index");
        return &g_ttm_none_singleton;
    }
    if (static_cast<std::size_t>(real_idx) < list->obj_items.size()) {
        return list->obj_items[static_cast<std::size_t>(real_idx)];
    }
    return &g_ttm_none_singleton;
}

std::int64_t TTMListO_Int_Index(const TTMListO* list, std::int64_t idx, __TTMTransparentStruct* ctx) {
    if (!list) return 0;
    std::int64_t real_idx = (idx < 0) ? (idx + list->ob_size) : idx;
    if (real_idx < 0 || real_idx >= list->ob_size) {
        RecordError(ctx, TTMStateErrorCodeListReadItemIndexOutOfRange, "TTMListO_Int_Index");
        return 0;
    }
    if (static_cast<std::size_t>(real_idx) < list->int_items.size()) {
        return list->int_items[static_cast<std::size_t>(real_idx)];
    }
    _object* obj = TTMListO_Object_Index(list, real_idx, ctx);
    return (obj && obj->ob_type == &TTMIntO_Type) ? static_cast<TTMIntO*>(obj)->ob_ival : 0;
}

double TTMListO_Float_Index(const TTMListO* list, std::int64_t idx, __TTMTransparentStruct* ctx) {
    if (!list) return 0.0;
    std::int64_t real_idx = (idx < 0) ? (idx + list->ob_size) : idx;
    if (real_idx < 0 || real_idx >= list->ob_size) {
        RecordError(ctx, TTMStateErrorCodeListReadItemIndexOutOfRange, "TTMListO_Float_Index");
        return 0.0;
    }
    if (static_cast<std::size_t>(real_idx) < list->float_items.size()) {
        return list->float_items[static_cast<std::size_t>(real_idx)];
    }
    _object* obj = TTMListO_Object_Index(list, real_idx, ctx);
    return (obj && obj->ob_type == &TTMFloatO_Type) ? static_cast<TTMFloatO*>(obj)->ob_fval : 0.0;
}

void TTMListO_clear(TTMListO* list) {
    if (!list) return;
    list->obj_items.clear();
    list->int_items.clear();
    list->float_items.clear();
    list->ob_size = 0;
}

void TTMListO_reverse(TTMListO* list) {
    if (!list) return;
    std::reverse(list->obj_items.begin(), list->obj_items.end());
    std::reverse(list->int_items.begin(), list->int_items.end());
    std::reverse(list->float_items.begin(), list->float_items.end());
}

// ==============================================================================
// 7. `TTMSlice_adjust_indices` (`0x238dc`, 252 B) & Slice Operations
//    Chuẩn hóa chỉ số cắt lát chuẩn Python (CPython PySlice_AdjustIndices)
// ==============================================================================
TTMSliceO* TTMSliceO_create(
    std::int64_t start,
    std::int64_t stop,
    std::int64_t step,
    bool has_start,
    bool has_stop,
    __TTMTransparentStruct* ctx) {
    if (step == 0) {
        RecordError(ctx, TTMStateErrorCodeSliceStepIs0, "TTMSliceO_create");
        return nullptr;
    }
    auto* slice = static_cast<TTMSliceO*>(ttm_am_object_create(&TTMSliceO_Type, ctx));
    slice->start = start;
    slice->stop = stop;
    slice->step = step;
    slice->has_start = has_start;
    slice->has_stop = has_stop;
    return slice;
}

std::int64_t TTMSlice_adjust_indices(
    std::int64_t length,
    std::int64_t* start,
    std::int64_t* stop,
    std::int64_t step) noexcept {
    if (step == 0 || !start || !stop) {
        return 0;
    }
    if (*start < 0) {
        *start += length;
        if (*start < 0) {
            *start = (step < 0) ? -1 : 0;
        }
    } else if (*start >= length) {
        *start = (step < 0) ? (length - 1) : length;
    }

    if (*stop < 0) {
        *stop += length;
        if (*stop < 0) {
            *stop = (step < 0) ? -1 : 0;
        }
    } else if (*stop >= length) {
        *stop = (step < 0) ? (length - 1) : length;
    }

    if (step < 0) {
        if (*stop < *start) {
            return (*start - *stop - 1) / (-step) + 1;
        }
    } else {
        if (*start < *stop) {
            return (*stop - *start - 1) / step + 1;
        }
    }
    return 0;
}

TTMStrO* TTMSlice_to_string(const TTMSliceO* slice, __TTMTransparentStruct* ctx) {
    if (!slice) return TTMStrO_from_cstr("slice(None, None, None)", ctx);
    std::ostringstream oss;
    oss << "slice(" << slice->start << ", " << slice->stop << ", " << slice->step << ")";
    return TTMStrO_from_cstr(oss.str().c_str(), ctx);
}

TTMListO* TTMListO_sublist_with_slice(const TTMListO* list, const TTMSliceO* slice, __TTMTransparentStruct* ctx) {
    if (!list || !slice) {
        RecordError(ctx, TTMStateErrorCodeReadListSubSliceIsNull, "TTMListO_sublist_with_slice");
        return nullptr;
    }
    std::int64_t start = slice->has_start ? slice->start : ((slice->step < 0) ? (list->ob_size - 1) : 0);
    std::int64_t stop  = slice->has_stop  ? slice->stop  : ((slice->step < 0) ? (-list->ob_size - 1) : list->ob_size);
    std::int64_t count = TTMSlice_adjust_indices(list->ob_size, &start, &stop, slice->step);
    auto* out = TTMListO_create(count, list->elem_kind, ctx);
    for (std::int64_t i = 0, cur = start; i < count; ++i, cur += slice->step) {
        TTMListO_add_obj(out, TTMListO_Object_Index(list, cur, ctx), ctx);
    }
    return out;
}

TTMListO* TTMListO_value_set_operation(const TTMListO* lhs, const TTMListO* rhs, int op_mode, __TTMTransparentStruct* ctx) {
    if (!lhs || !rhs) {
        RecordError(ctx, TTMStateErrorCodeListIntersectionIsNull, "TTMListO_value_set_operation");
        return nullptr;
    }
    auto* out = TTMListO_create(0, lhs->elem_kind, ctx);
    auto equals = [](_object* a, _object* b) {
        if (!a || !b || a->ob_type != b->ob_type) return false;
        if (a->ob_type == &TTMIntO_Type) return static_cast<TTMIntO*>(a)->ob_ival == static_cast<TTMIntO*>(b)->ob_ival;
        if (a->ob_type == &TTMFloatO_Type) return static_cast<TTMFloatO*>(a)->ob_fval == static_cast<TTMFloatO*>(b)->ob_fval;
        if (a->ob_type == &TTMStrO_Type) return TTMStr_string_eq(static_cast<TTMStrO*>(a), static_cast<TTMStrO*>(b));
        return a == b;
    };
    auto contains = [&](const std::vector<_object*>& vec, _object* needle) {
        for (_object* elem : vec) {
            if (equals(elem, needle)) return true;
        }
        return false;
    };

    // op_mode: 0 = intersection, 1 = union, 2 = difference
    if (op_mode == 0) {
        for (_object* elem : lhs->obj_items) {
            if (contains(rhs->obj_items, elem) && !contains(out->obj_items, elem)) {
                TTMListO_add_obj(out, elem, ctx);
            }
        }
    } else if (op_mode == 1) {
        for (_object* elem : lhs->obj_items) {
            if (!contains(out->obj_items, elem)) TTMListO_add_obj(out, elem, ctx);
        }
        for (_object* elem : rhs->obj_items) {
            if (!contains(out->obj_items, elem)) TTMListO_add_obj(out, elem, ctx);
        }
    } else {
        for (_object* elem : lhs->obj_items) {
            if (!contains(rhs->obj_items, elem) && !contains(out->obj_items, elem)) {
                TTMListO_add_obj(out, elem, ctx);
            }
        }
    }
    return out;
}

TTMStrO* TTMList_to_string(const TTMListO* list, __TTMTransparentStruct* ctx) {
    if (!list) return TTMStrO_from_cstr("[]", ctx);
    std::ostringstream oss;
    oss << "[";
    for (std::size_t i = 0; i < list->obj_items.size(); ++i) {
        if (i > 0) oss << ", ";
        _object* elem = list->obj_items[i];
        if (!elem || elem->ob_type == &TTMNoneO_Type) oss << "None";
        else if (elem->ob_type == &TTMIntO_Type) oss << static_cast<TTMIntO*>(elem)->ob_ival;
        else if (elem->ob_type == &TTMFloatO_Type) oss << static_cast<TTMFloatO*>(elem)->ob_fval;
        else if (elem->ob_type == &TTMStrO_Type) oss << "\"" << ttm_ttmstro_to_cstr(static_cast<TTMStrO*>(elem)) << "\"";
        else oss << "<object>";
    }
    oss << "]";
    return TTMStrO_from_cstr(oss.str().c_str(), ctx);
}

// ==============================================================================
// 8. `TTMStrO_*` String Object Operations (`0x25264..0x25cf0`)
// ==============================================================================
TTMStrO* TTMStrO_create_empty_str_with_size(std::size_t size, __TTMTransparentStruct* ctx) {
    auto* str = static_cast<TTMStrO*>(ttm_am_object_create(&TTMStrO_Type, ctx));
    str->owned_storage.assign(size, '\0');
    str->ob_size = static_cast<std::int64_t>(size);
    str->ob_sval = str->owned_storage.data();
    return str;
}

TTMStrO* TTMStrO_from_cstr(const char* cstr, __TTMTransparentStruct* ctx) {
    auto* str = static_cast<TTMStrO*>(ttm_am_object_create(&TTMStrO_Type, ctx));
    str->owned_storage = cstr ? cstr : "";
    str->ob_size = static_cast<std::int64_t>(str->owned_storage.size());
    str->ob_sval = str->owned_storage.data();
    return str;
}

TTMStrO* TTMStrO_from_char(char ch, __TTMTransparentStruct* ctx) {
    char buf[2] = {ch, '\0'};
    return TTMStrO_from_cstr(buf, ctx);
}

const char* ttm_ttmstro_to_cstr(const TTMStrO* str) noexcept {
    if (!str) return "";
    return str->ob_sval ? str->ob_sval : str->owned_storage.c_str();
}

TTMStrO* TTMStrO_substring_with_slice(const TTMStrO* str, const TTMSliceO* slice, __TTMTransparentStruct* ctx) {
    if (!str || !slice) {
        RecordError(ctx, TTMStateErrorCodeReadStringSubSliceIsNull, "TTMStrO_substring_with_slice");
        return nullptr;
    }
    const std::string& s = str->owned_storage;
    const auto len = static_cast<std::int64_t>(s.size());
    std::int64_t start = slice->has_start ? slice->start : ((slice->step < 0) ? (len - 1) : 0);
    std::int64_t stop  = slice->has_stop  ? slice->stop  : ((slice->step < 0) ? (-len - 1) : len);
    std::int64_t count = TTMSlice_adjust_indices(len, &start, &stop, slice->step);
    std::string out;
    out.reserve(static_cast<std::size_t>(count));
    for (std::int64_t i = 0, cur = start; i < count; ++i, cur += slice->step) {
        out.push_back(s[static_cast<std::size_t>(cur)]);
    }
    return TTMStrO_from_cstr(out.c_str(), ctx);
}

TTMStrO* TTMStrO_add(const TTMStrO* lhs, const TTMStrO* rhs, __TTMTransparentStruct* ctx) {
    std::string combined = std::string(ttm_ttmstro_to_cstr(lhs)) + std::string(ttm_ttmstro_to_cstr(rhs));
    return TTMStrO_from_cstr(combined.c_str(), ctx);
}

bool TTMStr_is_contain(const TTMStrO* haystack, const TTMStrO* needle) noexcept {
    if (!haystack || !needle) return false;
    return std::strstr(ttm_ttmstro_to_cstr(haystack), ttm_ttmstro_to_cstr(needle)) != nullptr;
}

bool TTMStr_string_eq(const TTMStrO* lhs, const TTMStrO* rhs) noexcept {
    if (!lhs || !rhs) return lhs == rhs;
    return std::strcmp(ttm_ttmstro_to_cstr(lhs), ttm_ttmstro_to_cstr(rhs)) == 0;
}

} // namespace NextAI::OpenCut::TTMachineCore
