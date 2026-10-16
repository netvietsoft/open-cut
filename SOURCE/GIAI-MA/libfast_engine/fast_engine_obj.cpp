// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_obj.cpp
// Description: Implementation of object lifecycle, dynamic dispatch, and collections
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "fast_engine_obj.h"
#include <sstream>
#include <cmath>
#include <cstring>
#include <iomanip>

namespace fast_engine {

// ===================================================================================
// NULL OBJECT IMPLEMENTATION
// ===================================================================================

NullObj* NullObj::GetInstance() {
    static NullObj instance;
    return &instance;
}

// ===================================================================================
// BOOLEAN OBJECT IMPLEMENTATION
// ===================================================================================

BoolObj* BoolObj::GetTrue() {
    static BoolObj true_inst(true);
    return &true_inst;
}

BoolObj* BoolObj::GetFalse() {
    static BoolObj false_inst(false);
    return &false_inst;
}

bool BoolObj::Equals(const Obj* other) const {
    if (!other) return false;
    if (other->type_tag == ObjTypeTag::TYPE_BOOL) {
        return val == static_cast<const BoolObj*>(other)->val;
    }
    if (other->type_tag == ObjTypeTag::TYPE_INT) {
        return (val ? 1 : 0) == static_cast<const LongObj*>(other)->val;
    }
    return false;
}

// ===================================================================================
// INTEGER OBJECT IMPLEMENTATION
// ===================================================================================

bool LongObj::Equals(const Obj* other) const {
    if (!other) return false;
    if (other->type_tag == ObjTypeTag::TYPE_INT) {
        return val == static_cast<const LongObj*>(other)->val;
    }
    if (other->type_tag == ObjTypeTag::TYPE_FLOAT) {
        return static_cast<double>(val) == static_cast<const FloatObj*>(other)->val;
    }
    if (other->type_tag == ObjTypeTag::TYPE_BOOL) {
        return val == (static_cast<const BoolObj*>(other)->val ? 1 : 0);
    }
    return false;
}

// ===================================================================================
// FLOAT OBJECT IMPLEMENTATION & IEEE-754 DOUBLE HASHING
// ===================================================================================

bool FloatObj::Equals(const Obj* other) const {
    if (!other) return false;
    if (other->type_tag == ObjTypeTag::TYPE_FLOAT) {
        return val == static_cast<const FloatObj*>(other)->val;
    }
    if (other->type_tag == ObjTypeTag::TYPE_INT) {
        return val == static_cast<double>(static_cast<const LongObj*>(other)->val);
    }
    return false;
}

// EN: Numerical IEEE-754 double hashing helper (Opcode 0x51af0: HashDouble)
// VN: Hàm băm số thực IEEE-754 nhị phân chuẩn xác (Opcode 0x51af0: HashDouble)
uint64_t HashDouble(const void* /*ptr*/, double val) {
    if (val == 0.0) {
        return 0ULL; // Standardize +0.0 and -0.0
    }
    if (std::isnan(val)) {
        return 0x7FF8000000000000ULL;
    }

    uint64_t bits = 0;
    std::memcpy(&bits, &val, sizeof(double));

    // MurmurHash64A finalizer mix
    bits ^= bits >> 33;
    bits *= 0xff51afd7ed558ccdULL;
    bits ^= bits >> 33;
    bits *= 0xc4ceb9fe1a85ec53ULL;
    bits ^= bits >> 33;

    return bits;
}

uint64_t FloatObj::Hash(Engine* /*engine*/) const {
    return HashDouble(this, val);
}

// ===================================================================================
// STRING OBJECT IMPLEMENTATION
// ===================================================================================

bool StrObj::Equals(const Obj* other) const {
    if (!other || other->type_tag != ObjTypeTag::TYPE_STR) return false;
    return val == static_cast<const StrObj*>(other)->val;
}

uint64_t StrObj::Hash(Engine* /*engine*/) const {
    uint64_t h = 14695981039346656037ULL;
    for (char c : val) {
        h ^= static_cast<uint64_t>(static_cast<uint8_t>(c));
        h *= 1099511628211ULL;
    }
    return h;
}

StrObj* StrObj::Slice(int64_t start, int64_t stop, int64_t step) const {
    int64_t len = static_cast<int64_t>(val.length());
    int64_t s = start, e = stop;
    int64_t slice_len = SliceIndices::AdjustIndices(len, &s, &e, step);

    if (slice_len <= 0) {
        return new StrObj("");
    }

    if (step == 1) {
        return new StrObj(val.substr(s, e - s));
    }

    std::string res;
    res.reserve(static_cast<size_t>(slice_len));
    for (int64_t cur = s, idx = 0; idx < slice_len; cur += step, ++idx) {
        res.push_back(val[cur]);
    }
    return new StrObj(res);
}

// ===================================================================================
// BYTES OBJECT IMPLEMENTATION
// ===================================================================================

BytesObj::BytesObj(const void* data, size_t size) : Obj(ObjTypeTag::TYPE_BYTES) {
    if (data && size > 0) {
        val.assign(reinterpret_cast<const uint8_t*>(data), reinterpret_cast<const uint8_t*>(data) + size);
    }
}

// EN: Create BytesObj from string and length (Opcode 0xb59cc)
// VN: Tạo đối tượng BytesObj từ chuỗi và kích thước (Opcode 0xb59cc)
BytesObj* BytesObj::FromStringAndSize(const char* data, int64_t size, Engine* /*engine*/) {
    if (size <= 0 || !data) {
        return new BytesObj(nullptr, 0);
    }
    return new BytesObj(data, static_cast<size_t>(size));
}

std::string BytesObj::Repr() const {
    std::ostringstream ss;
    ss << "b'";
    for (uint8_t b : val) {
        if (b >= 32 && b < 127 && b != '\'' && b != '\\') {
            ss << static_cast<char>(b);
        } else {
            ss << "\\x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
        }
    }
    ss << "'";
    return ss.str();
}

uint64_t BytesObj::Hash(Engine* /*engine*/) const {
    uint64_t h = 14695981039346656037ULL;
    for (uint8_t b : val) {
        h ^= static_cast<uint64_t>(b);
        h *= 1099511628211ULL;
    }
    return h;
}

// ===================================================================================
// TUPLE OBJECT IMPLEMENTATION
// ===================================================================================

TupleObj::TupleObj(std::vector<Obj*> elements) : Obj(ObjTypeTag::TYPE_TUPLE), items(std::move(elements)) {
    for (Obj* item : items) {
        if (item) item->IncRef();
    }
}

TupleObj::~TupleObj() {
    for (Obj* item : items) {
        if (item) item->DecRef();
    }
}

std::string TupleObj::Repr() const {
    std::string res = "(";
    for (size_t i = 0; i < items.size(); ++i) {
        if (i > 0) res += ", ";
        res += items[i] ? items[i]->Repr() : "None";
    }
    if (items.size() == 1) res += ",";
    res += ")";
    return res;
}

uint64_t TupleObj::Hash(Engine* engine) const {
    uint64_t mult = 1000003ULL;
    uint64_t h = 0x345678ULL;
    for (Obj* item : items) {
        uint64_t item_h = item ? item->Hash(engine) : 0ULL;
        h = (h ^ item_h) * mult;
        mult += 82520ULL + items.size() * 2ULL;
    }
    return h + 97531ULL;
}

Obj* TupleObj::Copy(Engine* /*engine*/) const {
    IncRef();
    return const_cast<TupleObj*>(this); // Tuples are immutable
}

// ===================================================================================
// LIST OBJECT IMPLEMENTATION
// ===================================================================================

ListObj::ListObj() : Obj(ObjTypeTag::TYPE_LIST) {}

ListObj::ListObj(size_t reserve_size) : Obj(ObjTypeTag::TYPE_LIST) {
    items.reserve(reserve_size);
}

ListObj::~ListObj() {
    Clear();
}

void ListObj::Append(Obj* item) {
    if (item) item->IncRef();
    items.push_back(item);
}

Obj* ListObj::Pop() {
    if (items.empty()) return nullptr;
    Obj* last = items.back();
    items.pop_back();
    // Return with existing reference
    return last;
}

void ListObj::Clear() {
    for (Obj* item : items) {
        if (item) item->DecRef();
    }
    items.clear();
}

Obj* ListObj::GetItem(size_t index) const {
    return index < items.size() ? items[index] : nullptr;
}

void ListObj::SetItem(size_t index, Obj* item) {
    if (index >= items.size()) return;
    if (item) item->IncRef();
    if (items[index]) items[index]->DecRef();
    items[index] = item;
}

std::string ListObj::Repr() const {
    std::string res = "[";
    for (size_t i = 0; i < items.size(); ++i) {
        if (i > 0) res += ", ";
        res += items[i] ? items[i]->Repr() : "None";
    }
    res += "]";
    return res;
}

Obj* ListObj::Copy(Engine* /*engine*/) const {
    auto* cp = new ListObj(items.size());
    for (Obj* item : items) {
        cp->Append(item);
    }
    return cp;
}

// ===================================================================================
// DICTIONARY OBJECT IMPLEMENTATION
// ===================================================================================

DictObj::DictObj() : Obj(ObjTypeTag::TYPE_DICT) {}

DictObj::~DictObj() {
    ClearContent(nullptr);
}

// EN: Set key-value pair with string key reference (Opcode 0xbf6bc)
// VN: Gán cặp khóa-giá trị với khóa chuỗi tham chiếu nhanh (Opcode 0xbf6bc)
void DictObj::SetItemStringRef(const std::string& key, Obj* value, Engine* engine) {
    auto it = string_keys_fast_lookup.find(key);
    if (it != string_keys_fast_lookup.end()) {
        Obj* old_val = it->second;
        if (value) value->IncRef();
        it->second = value;

        for (auto& entry : entries) {
            if (entry.key && entry.key->type_tag == ObjTypeTag::TYPE_STR &&
                static_cast<StrObj*>(entry.key)->val == key) {
                if (entry.value) entry.value->DecRef();
                entry.value = value;
                break;
            }
        }
        if (old_val) old_val->DecRef();
    } else {
        StrObj* key_obj = new StrObj(key);
        SetItem(key_obj, value, engine);
        key_obj->DecRef();
    }
}

void DictObj::SetItem(Obj* key, Obj* value, Engine* engine) {
    if (!key) return;

    uint64_t key_hash = key->Hash(engine);

    for (auto& entry : entries) {
        if (entry.hash == key_hash && entry.key && entry.key->Equals(key)) {
            if (value) value->IncRef();
            if (entry.value) entry.value->DecRef();
            entry.value = value;

            if (key->type_tag == ObjTypeTag::TYPE_STR) {
                string_keys_fast_lookup[static_cast<StrObj*>(key)->val] = value;
            }
            return;
        }
    }

    // New insertion
    key->IncRef();
    if (value) value->IncRef();
    entries.push_back({key, value, key_hash});

    if (key->type_tag == ObjTypeTag::TYPE_STR) {
        string_keys_fast_lookup[static_cast<StrObj*>(key)->val] = value;
    }
}

Obj* DictObj::GetItem(Obj* key, Engine* engine) const {
    if (!key) return nullptr;

    if (key->type_tag == ObjTypeTag::TYPE_STR) {
        return GetItemString(static_cast<StrObj*>(key)->val);
    }

    uint64_t key_hash = key->Hash(engine);
    for (const auto& entry : entries) {
        if (entry.hash == key_hash && entry.key && entry.key->Equals(key)) {
            return entry.value;
        }
    }
    return nullptr;
}

Obj* DictObj::GetItemString(const std::string& key) const {
    auto it = string_keys_fast_lookup.find(key);
    return (it != string_keys_fast_lookup.end()) ? it->second : nullptr;
}

// EN: Remove key from dictionary (Opcode 0x4f864)
// VN: Xóa khóa khỏi từ điển (Opcode 0x4f864)
bool DictObj::DelItem(Obj* key, Engine* engine) {
    if (!key) return false;

    uint64_t key_hash = key->Hash(engine);
    for (auto it = entries.begin(); it != entries.end(); ++it) {
        if (it->hash == key_hash && it->key && it->key->Equals(key)) {
            if (it->key->type_tag == ObjTypeTag::TYPE_STR) {
                string_keys_fast_lookup.erase(static_cast<StrObj*>(it->key)->val);
            }
            if (it->key) it->key->DecRef();
            if (it->value) it->value->DecRef();
            entries.erase(it);
            return true;
        }
    }
    return false;
}

// EN: Clear dictionary content (Opcode 0xbfbdc: DictObj::ClearContent)
// VN: Xóa toàn bộ nội dung từ điển (Opcode 0xbfbdc: DictObj::ClearContent)
void DictObj::ClearContent(Engine* /*engine*/) {
    for (auto& entry : entries) {
        if (entry.key) entry.key->DecRef();
        if (entry.value) entry.value->DecRef();
    }
    entries.clear();
    string_keys_fast_lookup.clear();
}

// EN: Iterate to next dictionary item (Opcode 0xbd274: DictObj::Next)
// VN: Duyệt sang phần tử tiếp theo của từ điển (Opcode 0xbd274: DictObj::Next)
bool DictObj::Next(int64_t* pos, Obj** out_key, Obj** out_val) const {
    if (!pos || *pos < 0 || static_cast<size_t>(*pos) >= entries.size()) {
        return false;
    }
    size_t idx = static_cast<size_t>(*pos);
    if (out_key) *out_key = entries[idx].key;
    if (out_val) *out_val = entries[idx].value;
    *pos = static_cast<int64_t>(idx + 1);
    return true;
}

std::string DictObj::Repr() const {
    std::string res = "{";
    for (size_t i = 0; i < entries.size(); ++i) {
        if (i > 0) res += ", ";
        res += entries[i].key ? entries[i].key->Repr() : "None";
        res += ": ";
        res += entries[i].value ? entries[i].value->Repr() : "None";
    }
    res += "}";
    return res;
}

Obj* DictObj::Copy(Engine* engine) const {
    auto* cp = new DictObj();
    for (const auto& entry : entries) {
        cp->SetItem(entry.key, entry.value, engine);
    }
    return cp;
}

// ===================================================================================
// SET OBJECT IMPLEMENTATION
// ===================================================================================

SetObj::SetObj() : Obj(ObjTypeTag::TYPE_SET) {}

SetObj::~SetObj() {
    Clear();
}

bool SetObj::Add(Obj* item, Engine* engine) {
    if (!item) return false;
    if (Contains(item, engine)) {
        return false;
    }
    item->IncRef();
    items.push_back(item);
    return true;
}

// EN: Remove item from set (Opcode 0xe7de4: SetObj::Remove)
// VN: Loại bỏ phần tử khỏi tập hợp (Opcode 0xe7de4: SetObj::Remove)
bool SetObj::Remove(Obj* item, Engine* /*engine*/) {
    if (!item) return false;
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->Equals(item)) {
            (*it)->DecRef();
            items.erase(it);
            return true;
        }
    }
    return false;
}

bool SetObj::Contains(Obj* item, Engine* /*engine*/) const {
    if (!item) return false;
    for (Obj* elem : items) {
        if (elem && elem->Equals(item)) {
            return true;
        }
    }
    return false;
}

void SetObj::Clear() {
    for (Obj* item : items) {
        if (item) item->DecRef();
    }
    items.clear();
}

// EN: Compute set difference (Opcode 0xe8110: SetObj::Difference)
// VN: Tính tập hiệu giữa hai tập hợp (Opcode 0xe8110: SetObj::Difference)
SetObj* SetObj::Difference(const SetObj* other, Engine* engine) const {
    auto* diff = new SetObj();
    for (Obj* item : items) {
        if (!other || !other->Contains(item, engine)) {
            diff->Add(item, engine);
        }
    }
    return diff;
}

SetObj* SetObj::Union(const SetObj* other, Engine* engine) const {
    auto* uni = new SetObj();
    for (Obj* item : items) {
        uni->Add(item, engine);
    }
    if (other) {
        for (Obj* item : other->items) {
            uni->Add(item, engine);
        }
    }
    return uni;
}

std::string SetObj::Repr() const {
    if (items.empty()) return "set()";
    std::string res = "{";
    for (size_t i = 0; i < items.size(); ++i) {
        if (i > 0) res += ", ";
        res += items[i] ? items[i]->Repr() : "None";
    }
    res += "}";
    return res;
}

Obj* SetObj::Copy(Engine* engine) const {
    auto* cp = new SetObj();
    for (Obj* item : items) {
        cp->Add(item, engine);
    }
    return cp;
}

} // namespace fast_engine
