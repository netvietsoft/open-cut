// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_obj.h
// Description: Dynamic Object Model, Refcounting, Value Types, and Hash Collections
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "fast_engine_types.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <atomic>
#include <iostream>

namespace fast_engine {

// EN: Base Dynamic Object class matching ABI symbol fast_engine::Obj
// VN: Lớp đối tượng động cơ sở khớp biểu tượng ABI fast_engine::Obj
class Obj {
public:
    ObjTypeTag type_tag = ObjTypeTag::TYPE_NULL;
    mutable std::atomic<int32_t> ref_count{1};

    explicit Obj(ObjTypeTag tag) : type_tag(tag) {}
    virtual ~Obj() = default;

    // EN: Increment reference counter
    // VN: Tăng bộ đếm tham chiếu
    void IncRef() const {
        ref_count.fetch_add(1, std::memory_order_relaxed);
    }

    // EN: Decrement reference counter and delete if zero
    // VN: Giảm bộ đếm tham chiếu và giải phóng nếu về 0
    void DecRef() const {
        if (ref_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete this;
        }
    }

    // EN: Compute object hash (Opcode 0xdd344)
    // VN: Tính mã băm của đối tượng (Opcode 0xdd344)
    virtual uint64_t Hash(Engine* engine) const {
        return reinterpret_cast<uintptr_t>(this);
    }

    // EN: Check equality with another object
    // VN: Kiểm tra tính bằng nhau với đối tượng khác
    virtual bool Equals(const Obj* other) const {
        return this == other;
    }

    // EN: String representation of object (Opcode 0xdf498: ReprEnter)
    // VN: Biểu diễn chuỗi của đối tượng (Opcode 0xdf498: ReprEnter)
    virtual std::string Repr() const {
        return "<Obj>";
    }

    // EN: Deep/Shallow clone of object (Opcode 0xdf1f0)
    // VN: Sao chép đối tượng (Opcode 0xdf1f0)
    virtual Obj* Copy(Engine* engine) const {
        IncRef();
        return const_cast<Obj*>(this);
    }

    virtual bool IsTrue() const { return true; }
};

// EN: Smart Pointer for automatic refcount management (RAII)
// VN: Con trỏ thông minh tự động quản lý bộ đếm tham chiếu (RAII)
template <typename T>
class RefPtr {
public:
    T* ptr = nullptr;

    RefPtr() : ptr(nullptr) {}
    RefPtr(T* p) : ptr(p) {}
    RefPtr(const RefPtr& other) : ptr(other.ptr) { if (ptr) ptr->IncRef(); }
    RefPtr(RefPtr&& other) noexcept : ptr(other.ptr) { other.ptr = nullptr; }
    ~RefPtr() { if (ptr) ptr->DecRef(); }

    RefPtr& operator=(const RefPtr& other) {
        if (this != &other) {
            if (ptr) ptr->DecRef();
            ptr = other.ptr;
            if (ptr) ptr->IncRef();
        }
        return *this;
    }

    RefPtr& operator=(RefPtr&& other) noexcept {
        if (this != &other) {
            if (ptr) ptr->DecRef();
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T* get() const { return ptr; }
    T* operator->() const { return ptr; }
    T& operator*() const { return *ptr; }
    explicit operator bool() const { return ptr != nullptr; }
};

// EN: Null / None Object singleton (Opcode 0x15f8e0: NullObj)
// VN: Đối tượng rỗng Null/None duy nhất (Opcode 0x15f8e0: NullObj)
class NullObj : public Obj {
public:
    NullObj() : Obj(ObjTypeTag::TYPE_NULL) {}
    static NullObj* GetInstance();
    std::string Repr() const override { return "None"; }
    bool IsTrue() const override { return false; }
    uint64_t Hash(Engine* engine) const override { return 0ULL; }
};

// EN: Boolean Object (Opcode 0x15f3b8: BoolType)
// VN: Đối tượng logic đúng/sai (Opcode 0x15f3b8: BoolType)
class BoolObj : public Obj {
public:
    bool val = false;
    explicit BoolObj(bool v) : Obj(ObjTypeTag::TYPE_BOOL), val(v) {}
    static BoolObj* GetTrue();
    static BoolObj* GetFalse();
    static BoolObj* FromBool(bool v) { return v ? GetTrue() : GetFalse(); }
    std::string Repr() const override { return val ? "True" : "False"; }
    bool IsTrue() const override { return val; }
    bool Equals(const Obj* other) const override;
    uint64_t Hash(Engine* engine) const override { return val ? 1ULL : 0ULL; }
};

// EN: 64-bit Integer Object (Opcode 0xd122c: LongObj)
// VN: Đối tượng số nguyên 64-bit (Opcode 0xd122c: LongObj)
class LongObj : public Obj {
public:
    int64_t val = 0;
    explicit LongObj(int64_t v) : Obj(ObjTypeTag::TYPE_INT), val(v) {}
    std::string Repr() const override { return std::to_string(val); }
    bool IsTrue() const override { return val != 0; }
    bool Equals(const Obj* other) const override;
    uint64_t Hash(Engine* engine) const override { return static_cast<uint64_t>(val); }
    Obj* Copy(Engine* engine) const override { return new LongObj(val); }
};

// EN: 64-bit Floating Point Object (Opcode 0x15f528: FloatType)
// VN: Đối tượng số thực dấu chấm động 64-bit (Opcode 0x15f528: FloatType)
class FloatObj : public Obj {
public:
    double val = 0.0;
    explicit FloatObj(double v) : Obj(ObjTypeTag::TYPE_FLOAT), val(v) {}
    std::string Repr() const override { return std::to_string(val); }
    bool IsTrue() const override { return val != 0.0; }
    bool Equals(const Obj* other) const override;
    uint64_t Hash(Engine* engine) const override;
    Obj* Copy(Engine* engine) const override { return new FloatObj(val); }
};

// EN: Immutable UTF-8 String Object (Opcode 0xed3e0: StrObj::CStr)
// VN: Đối tượng chuỗi ký tự UTF-8 bất biến (Opcode 0xed3e0: StrObj::CStr)
class StrObj : public Obj {
public:
    std::string val;
    explicit StrObj(const std::string& v) : Obj(ObjTypeTag::TYPE_STR), val(v) {}
    explicit StrObj(const char* s, size_t len) : Obj(ObjTypeTag::TYPE_STR), val(s, len) {}

    // EN: Get raw C string pointer matching ABI symbol fast_engine::StrObj::CStr (Opcode 0xed3e0)
    // VN: Lấy con trỏ chuỗi C thô khớp biểu tượng ABI fast_engine::StrObj::CStr (Opcode 0xed3e0)
    const char* CStr() const { return val.c_str(); }
    size_t Length() const { return val.length(); }

    std::string Repr() const override { return "'" + val + "'"; }
    bool IsTrue() const override { return !val.empty(); }
    bool Equals(const Obj* other) const override;
    uint64_t Hash(Engine* engine) const override;
    Obj* Copy(Engine* engine) const override { return new StrObj(val); }

    // EN: Substring slicing with adjusted indices
    // VN: Trích xuất chuỗi con với chỉ số cắt lát đã chuẩn hóa
    StrObj* Slice(int64_t start, int64_t stop, int64_t step) const;
};

// EN: Raw Bytes Object (Opcode 0xb59cc: BytesObj::FromStringAndSize)
// VN: Đối tượng khối byte dữ liệu thô (Opcode 0xb59cc: BytesObj::FromStringAndSize)
class BytesObj : public Obj {
public:
    std::vector<uint8_t> val;
    explicit BytesObj(const void* data, size_t size);
    static BytesObj* FromStringAndSize(const char* data, int64_t size, Engine* engine);
    std::string Repr() const override;
    bool IsTrue() const override { return !val.empty(); }
    uint64_t Hash(Engine* engine) const override;
    Obj* Copy(Engine* engine) const override { return new BytesObj(val.data(), val.size()); }
};

// EN: Immutable Tuple Object (Opcode 0x13d4e0: vtable for TupleObj)
// VN: Đối tượng bộ dữ liệu Tuple bất biến (Opcode 0x13d4e0: vtable for TupleObj)
class TupleObj : public Obj {
public:
    std::vector<Obj*> items;

    explicit TupleObj(std::vector<Obj*> elements);
    ~TupleObj() override;

    size_t Size() const { return items.size(); }
    Obj* GetItem(size_t index) const { return index < items.size() ? items[index] : nullptr; }
    std::string Repr() const override;
    bool IsTrue() const override { return !items.empty(); }
    uint64_t Hash(Engine* engine) const override;
    Obj* Copy(Engine* engine) const override;
};

// EN: Mutable List Object (SequenceObj)
// VN: Đối tượng danh sách List có thể biến đổi (SequenceObj)
class ListObj : public Obj {
public:
    std::vector<Obj*> items;

    ListObj();
    explicit ListObj(size_t reserve_size);
    ~ListObj() override;

    void Append(Obj* item);
    Obj* Pop();
    void Clear();
    size_t Size() const { return items.size(); }
    Obj* GetItem(size_t index) const;
    void SetItem(size_t index, Obj* item);

    std::string Repr() const override;
    bool IsTrue() const override { return !items.empty(); }
    Obj* Copy(Engine* engine) const override;
};

// EN: Hash Map Object matching ABI symbol fast_engine::DictObj
// VN: Đối tượng bảng băm ánh xạ khớp biểu tượng ABI fast_engine::DictObj
class DictObj : public Obj {
public:
    struct Entry {
        Obj* key = nullptr;
        Obj* value = nullptr;
        uint64_t hash = 0;
    };

    std::vector<Entry> entries;
    std::unordered_map<std::string, Obj*> string_keys_fast_lookup;

    DictObj();
    ~DictObj() override;

    // EN: Set key-value pair with string key reference (Opcode 0xbf6bc: SetItemStringRef)
    // VN: Gán cặp khóa-giá trị với khóa chuỗi (Opcode 0xbf6bc: SetItemStringRef)
    void SetItemStringRef(const std::string& key, Obj* value, Engine* engine);

    // EN: Set arbitrary key-value pair
    // VN: Gán cặp khóa-giá trị tổng quát
    void SetItem(Obj* key, Obj* value, Engine* engine);

    // EN: Lookup value by key
    // VN: Tra cứu giá trị theo khóa
    Obj* GetItem(Obj* key, Engine* engine) const;
    Obj* GetItemString(const std::string& key) const;

    // EN: Remove key from dict (Opcode 0x4f864: mapping::DelItem)
    // VN: Xóa khóa khỏi từ điển (Opcode 0x4f864: mapping::DelItem)
    bool DelItem(Obj* key, Engine* engine);

    // EN: Clear dictionary content (Opcode 0xbfbdc: DictObj::ClearContent)
    // VN: Xóa toàn bộ nội dung từ điển (Opcode 0xbfbdc: DictObj::ClearContent)
    void ClearContent(Engine* engine);

    // EN: Iterator support (Opcode 0xbd274: DictObj::Next)
    // VN: Hỗ trợ duyệt phần tử tiếp theo (Opcode 0xbd274: DictObj::Next)
    bool Next(int64_t* pos, Obj** out_key, Obj** out_val) const;

    size_t Size() const { return entries.size(); }
    std::string Repr() const override;
    bool IsTrue() const override { return !entries.empty(); }
    Obj* Copy(Engine* engine) const override;
};

// EN: Hash Set Object matching ABI symbol fast_engine::SetObj
// VN: Đối tượng tập hợp Set khớp biểu tượng ABI fast_engine::SetObj
class SetObj : public Obj {
public:
    std::vector<Obj*> items;

    SetObj();
    ~SetObj() override;

    bool Add(Obj* item, Engine* engine);
    bool Remove(Obj* item, Engine* engine); // Opcode 0xe7de4
    bool Contains(Obj* item, Engine* engine) const;
    void Clear();

    // EN: Compute set difference (Opcode 0xe8110: SetObj::Difference)
    // VN: Tính tập hiệu giữa 2 tập hợp (Opcode 0xe8110: SetObj::Difference)
    SetObj* Difference(const SetObj* other, Engine* engine) const;

    // EN: Compute set union
    // VN: Tính tập hợp hợp nhất
    SetObj* Union(const SetObj* other, Engine* engine) const;

    size_t Size() const { return items.size(); }
    std::string Repr() const override;
    bool IsTrue() const override { return !items.empty(); }
    Obj* Copy(Engine* engine) const override;
};

// EN: Numerical IEEE-754 double hashing helper (Opcode 0x51af0: HashDouble)
// VN: Hàm băm số thực IEEE-754 nhị phân chuẩn xác (Opcode 0x51af0: HashDouble)
uint64_t HashDouble(const void* ptr, double val);

} // namespace fast_engine
