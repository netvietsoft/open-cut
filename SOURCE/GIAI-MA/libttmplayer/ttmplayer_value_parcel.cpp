/**
 * @file ttmplayer_value_parcel.cpp
 * @brief Cleanroom C++17 Implementation of VString, Value, and Parcel (0x16b464 .. 0x16ca2c)
 *        Hiện thực C++17 Tái cấu trúc Sạch cho VString, Value và Parcel (0x16b464 .. 0x16ca2c)
 */

#include "ttmplayer_value_parcel.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <new>
#include <utility>

namespace com {
namespace ss {
namespace ttm {
namespace player {

// ============================================================================
// 1. VString Implementation (0x16b464 .. 0x16b6a8)
//    Hiện thực Lớp Chuỗi VString (0x16b464 .. 0x16b6a8)
// ============================================================================

namespace {

inline void AssignToVString(VString& dst, const char* src, size_t len) {
    dst.reset();
    if (!src || len == 0) {
        return;
    }
    if (len <= 22) {
        // Short string optimization (SSO): bit 0 of byte 0 is 0, upper 7 bits = len << 1
        // Tối ưu chuỗi ngắn (SSO): bit 0 của byte 0 bằng 0, 7 bit cao lưu (len << 1)
        dst.short_rep.tag = static_cast<uint8_t>((len & 0x7FU) << 1U);
        std::memcpy(dst.short_rep.sso_buf, src, len);
        dst.short_rep.sso_buf[len] = '\0';
    } else {
        // Long heap string mode: bit 0 of cap_flag (+0x00) is 1, heap pointer at +0x10
        // Chế độ chuỗi dài trên heap: bit 0 tại +0x00 bằng 1, con trỏ heap tại +0x10
        size_t alloc_cap = (len + 16ULL) & ~15ULL;
        char* buf = static_cast<char*>(std::malloc(alloc_cap));
        if (!buf) {
            return;
        }
        std::memcpy(buf, src, len);
        buf[len] = '\0';
        dst.long_rep.cap_flag = (alloc_cap << 1ULL) | 1ULL;
        dst.long_rep.size = len;
        dst.long_rep.data = buf;
    }
}

}  // namespace

// Matches VString::ctor() @ 0x16b464:
//   stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ret
VString::VString() noexcept {
    raw_words[0] = 0ULL;
    raw_words[1] = 0ULL;
    raw_words[2] = 0ULL;
}

// Matches VString::ctor(char const*) @ 0x16b490
VString::VString(const char* str) : VString() {
    if (str) {
        AssignToVString(*this, str, std::strlen(str));
    }
}

// Matches VString::ctor(std::string const&) @ 0x16b470
VString::VString(const std::string& str) : VString() {
    AssignToVString(*this, str.data(), str.size());
}

// Matches VString::ctor(std::string&&) @ 0x16b474
VString::VString(std::string&& str) noexcept : VString() {
    AssignToVString(*this, str.data(), str.size());
    str.clear();
}

// Matches VString::ctor(VString const&) @ 0x16b4d4
VString::VString(const VString& other) : VString() {
    const char* s = other.c_str();
    AssignToVString(*this, s, std::strlen(s));
}

// Matches VString::ctor(VString&&) @ 0x16b4d8 (28 bytes):
//   ldp x8, x9, [x1]; ldr x10, [x1, #0x10]; stp x8, x9, [x0]; str x10, [x0, #0x10];
//   stp xzr, xzr, [x1]; str xzr, [x1, #0x10]; ret
VString::VString(VString&& other) noexcept {
    raw_words[0] = other.raw_words[0];
    raw_words[1] = other.raw_words[1];
    raw_words[2] = other.raw_words[2];
    other.raw_words[0] = 0ULL;
    other.raw_words[1] = 0ULL;
    other.raw_words[2] = 0ULL;
}

// Matches VString::dtor() @ 0x16b688 (20 bytes):
//   ldrb w8, [x0]; tbz w8, #0, #ret; ldr x0, [x0, #0x10]; b operator delete
VString::~VString() noexcept {
    reset();
}

void VString::reset() noexcept {
    if ((short_rep.tag & 1U) != 0U && long_rep.data != nullptr) {
        std::free(long_rep.data);
    }
    raw_words[0] = 0ULL;
    raw_words[1] = 0ULL;
    raw_words[2] = 0ULL;
}

// Matches VString::operator=(char const*) @ 0x16b584
VString& VString::operator=(const char* str) {
    AssignToVString(*this, str, str ? std::strlen(str) : 0);
    return *this;
}

// Matches VString::operator=(std::string const&) @ 0x16b4f4
VString& VString::operator=(const std::string& str) {
    AssignToVString(*this, str.data(), str.size());
    return *this;
}

// Matches VString::operator=(std::string&&) @ 0x16b518
VString& VString::operator=(std::string&& str) noexcept {
    AssignToVString(*this, str.data(), str.size());
    str.clear();
    return *this;
}

// Matches VString::operator=(VString const&) @ 0x16b5e4
VString& VString::operator=(const VString& other) {
    if (this != &other) {
        const char* s = other.c_str();
        AssignToVString(*this, s, std::strlen(s));
    }
    return *this;
}

// Matches VString::operator=(VString&&) @ 0x16b614
VString& VString::operator=(VString&& other) noexcept {
    if (this != &other) {
        reset();
        raw_words[0] = other.raw_words[0];
        raw_words[1] = other.raw_words[1];
        raw_words[2] = other.raw_words[2];
        other.raw_words[0] = 0ULL;
        other.raw_words[1] = 0ULL;
        other.raw_words[2] = 0ULL;
    }
    return *this;
}

// Matches VString::c_str() @ 0x16b6a8:
//   ldrb w8, [x0]; tbnz w8, #0, #0x16b6b8; add x0, x0, #1; ret; ldr x0, [x0, #0x10]; ret
const char* VString::c_str() const noexcept {
    if ((short_rep.tag & 1U) != 0U) {
        return long_rep.data ? long_rep.data : "";
    }
    return short_rep.sso_buf;
}

// Matches VString::get() @ 0x16b69c
std::string VString::get() const {
    return std::string(c_str());
}

// ============================================================================
// 2. Value Implementation (0x16b6c0 .. 0x16bc00)
//    Hiện thực Biến Đa hình Value (0x16b6c0 .. 0x16bc00)
// ============================================================================

// Matches Value::Data::ctor() @ 0x16bbf8: str xzr, [x0]; ret
Value::Data::Data() noexcept {
    raw_words[0] = 0ULL;
    raw_words[1] = 0ULL;
    raw_words[2] = 0ULL;
}

// Matches Value::Data::dtor() @ 0x16bc00: ret
Value::Data::~Data() noexcept = default;

// Matches Value::ctor() @ 0x16b6c0: str xzr, [x0]; str wzr, [x0, #0x18]; ret
Value::Value() noexcept : data_(), type_(kValueTypeNone), reserved_(0) {}

// Matches Value::ctor(int const&) @ 0x16b6cc:
//   mov w8, #1; str xzr, [x0]; str w8, [x0, #0x18]; ldrsw x8, [x1]; str x8, [x0]; ret
Value::Value(const int32_t& v) noexcept : data_(), type_(kValueTypeInt32), reserved_(0) {
    data_.i64_val = static_cast<int64_t>(v);
}

// Matches Value::ctor(long const&) @ 0x16b6e4:
//   mov w8, #2; str xzr, [x0]; str w8, [x0, #0x18]; ldr x8, [x1]; str x8, [x0]; ret
Value::Value(const int64_t& v) noexcept : data_(), type_(kValueTypeInt64), reserved_(0) {
    data_.i64_val = v;
}

// Matches Value::ctor(float const&) @ 0x16b6fc:
//   mov w8, #3; str xzr, [x0]; str w8, [x0, #0x18]; ldr w8, [x1]; str w8, [x0]; ret
Value::Value(const float& v) noexcept : data_(), type_(kValueTypeFloat), reserved_(0) {
    data_.f32_val = v;
}

// Matches Value::ctor(double const&) @ 0x16b714:
//   mov w8, #4; str xzr, [x0]; str w8, [x0, #0x18]; ldr x8, [x1]; str x8, [x0]; ret
Value::Value(const double& v) noexcept : data_(), type_(kValueTypeDouble), reserved_(0) {
    data_.f64_val = v;
}

// Matches Value::ctor(char const*) @ 0x16b764
Value::Value(const char* v) : data_(), type_(kValueTypeString), reserved_(0) {
    new (data_.raw_words) VString(v);
}

// Matches Value::ctor(std::string const&) @ 0x16b72c
Value::Value(const std::string& v) : data_(), type_(kValueTypeString), reserved_(0) {
    new (data_.raw_words) VString(v);
}

// Matches Value::ctor(std::string&&) @ 0x16b73c
Value::Value(std::string&& v) : data_(), type_(kValueTypeString), reserved_(0) {
    new (data_.raw_words) VString(std::move(v));
}

// Matches Value::ctor(void*) @ 0x16b774:
//   mov w8, #6; str x1, [x0]; str w8, [x0, #0x18]; ret
Value::Value(void* v) noexcept : data_(), type_(kValueTypePtr), reserved_(0) {
    data_.ptr_val = v;
}

// Matches Value::ctor(Value const&) @ 0x16b784
Value::Value(const Value& other) : data_(), type_(kValueTypeNone), reserved_(0) {
    copyData(other);
}

// Matches Value::ctor(Value&&) @ 0x16b7d8
Value::Value(Value&& other) noexcept : data_(), type_(kValueTypeNone), reserved_(0) {
    moveData(std::move(other));
}

// Matches Value::dtor() @ 0x16bbb8 -> clear()
Value::~Value() noexcept {
    clear();
}

// Matches Value::clear() @ 0x16b890 (72 bytes):
//   ldr w8, [x0, #0x18]; sub w8, w8, #1; cmp w8, #5; b.hi #ret;
//   Dispatch jump table @ 0x2b0050:
//   - types 1 (Int32), 2 (Int64), 4 (Double), 6 (Ptr): str xzr, [x0]
//   - type 3 (Float): str wzr, [x0]
//   - type 5 (String): ldrb w8, [x0]; tbz w8, #0, #ret; free([x0, #0x10])
void Value::clear() noexcept {
    if (type_ == kValueTypeString) {
        reinterpret_cast<VString*>(data_.raw_words)->reset();
    } else if (type_ == kValueTypeFloat) {
        data_.i32_val = 0;
    } else {
        data_.raw_words[0] = 0ULL;
        data_.raw_words[1] = 0ULL;
        data_.raw_words[2] = 0ULL;
    }
    type_ = kValueTypeNone;
}

// Matches Value::copyData(Value const&) @ 0x16b794
void Value::copyData(const Value& other) {
    clear();
    type_ = other.type_;
    switch (other.type_) {
        case kValueTypeInt32:
            data_.i32_val = other.data_.i32_val;
            break;
        case kValueTypeInt64:
            data_.i64_val = other.data_.i64_val;
            break;
        case kValueTypeFloat:
            data_.f32_val = other.data_.f32_val;
            break;
        case kValueTypeDouble:
            data_.f64_val = other.data_.f64_val;
            break;
        case kValueTypeString: {
            const auto* src_vstr = reinterpret_cast<const VString*>(other.data_.raw_words);
            new (data_.raw_words) VString(*src_vstr);
            break;
        }
        case kValueTypePtr:
            data_.ptr_val = other.data_.ptr_val;
            break;
        default:
            break;
    }
}

// Matches Value::moveData(Value&&) @ 0x16b7e8
void Value::moveData(Value&& other) noexcept {
    clear();
    type_ = other.type_;
    if (other.type_ == kValueTypeString) {
        auto* src_vstr = reinterpret_cast<VString*>(other.data_.raw_words);
        new (data_.raw_words) VString(std::move(*src_vstr));
    } else {
        data_.raw_words[0] = other.data_.raw_words[0];
        data_.raw_words[1] = other.data_.raw_words[1];
        data_.raw_words[2] = other.data_.raw_words[2];
        other.data_.raw_words[0] = 0ULL;
    }
    other.type_ = kValueTypeNone;
}

Value& Value::operator=(const int32_t& v) noexcept {
    clear();
    type_ = kValueTypeInt32;
    data_.i64_val = static_cast<int64_t>(v);
    return *this;
}

Value& Value::operator=(const int64_t& v) noexcept {
    clear();
    type_ = kValueTypeInt64;
    data_.i64_val = v;
    return *this;
}

Value& Value::operator=(const float& v) noexcept {
    clear();
    type_ = kValueTypeFloat;
    data_.f32_val = v;
    return *this;
}

Value& Value::operator=(const double& v) noexcept {
    clear();
    type_ = kValueTypeDouble;
    data_.f64_val = v;
    return *this;
}

Value& Value::operator=(const char* v) {
    clear();
    type_ = kValueTypeString;
    new (data_.raw_words) VString(v);
    return *this;
}

Value& Value::operator=(const std::string& v) {
    clear();
    type_ = kValueTypeString;
    new (data_.raw_words) VString(v);
    return *this;
}

Value& Value::operator=(std::string&& v) {
    clear();
    type_ = kValueTypeString;
    new (data_.raw_words) VString(std::move(v));
    return *this;
}

Value& Value::operator=(void* v) noexcept {
    clear();
    type_ = kValueTypePtr;
    data_.ptr_val = v;
    return *this;
}

Value& Value::operator=(const Value& other) {
    if (this != &other) {
        copyData(other);
    }
    return *this;
}

Value& Value::operator=(Value&& other) noexcept {
    if (this != &other) {
        moveData(std::move(other));
    }
    return *this;
}

// Matches Value::getInt32() @ 0x16bbc4: ldr w0, [x0]; ret
int32_t Value::getInt32() const noexcept { return data_.i32_val; }

// Matches Value::getInt64() @ 0x16bbcc: ldr x0, [x0]; ret
int64_t Value::getInt64() const noexcept { return data_.i64_val; }

// Matches Value::getFloat() @ 0x16bbd4: ldr s0, [x0]; ret
float Value::getFloat() const noexcept { return data_.f32_val; }

// Matches Value::getDouble() @ 0x16bbdc: ldr d0, [x0]; ret
double Value::getDouble() const noexcept { return data_.f64_val; }

// Matches Value::getString() @ 0x16bbe4
std::string Value::getString() const {
    if (type_ != kValueTypeString) {
        return {};
    }
    return reinterpret_cast<const VString*>(data_.raw_words)->get();
}

// Matches Value::getPtr() @ 0x16bbf0: ldr x0, [x0]; ret
void* Value::getPtr() const noexcept { return data_.ptr_val; }

// ============================================================================
// 3. Parcel Implementation (0x16bc04 .. 0x16ca2c)
//    Hiện thực Gói dữ liệu Parcel (0x16bc04 .. 0x16ca2c)
// ============================================================================

namespace {

void FreeParcelStorage(Parcel& p) noexcept {
    if (p.begin_) {
        for (Value* cur = p.begin_; cur < p.end_; ++cur) {
            cur->~Value();
        }
        std::free(p.begin_);
    }
    p.begin_ = nullptr;
    p.end_ = nullptr;
    p.cap_end_ = nullptr;
}

void ReserveParcelStorage(Parcel& p, uint64_t new_cap) {
    uint64_t old_count = p.count();
    if (new_cap <= static_cast<uint64_t>(p.cap_end_ - p.begin_)) {
        return;
    }
    Value* new_buf = static_cast<Value*>(std::malloc(sizeof(Value) * new_cap));
    if (!new_buf) {
        return;
    }
    for (uint64_t i = 0; i < old_count; ++i) {
        new (new_buf + i) Value(std::move(p.begin_[i]));
        p.begin_[i].~Value();
    }
    if (p.begin_) {
        std::free(p.begin_);
    }
    p.begin_ = new_buf;
    p.end_ = new_buf + old_count;
    p.cap_end_ = new_buf + new_cap;
}

}  // namespace

// Matches Parcel::ctor() @ 0x16c9b4: default capacity = 16
Parcel::Parcel() noexcept : Parcel(16ULL) {}

// Matches Parcel::ctor(ulong) @ 0x16bc04:
//   str x1, [x0]; stp xzr, xzr, [x0, #0x10]; str xzr, [x0, #8]!; b reserve
Parcel::Parcel(uint64_t max_elements)
    : capacity_(max_elements), begin_(nullptr), end_(nullptr), cap_end_(nullptr) {
    if (max_elements > 0) {
        ReserveParcelStorage(*this, max_elements);
    }
}

// Matches Parcel::ctor(Parcel const&) @ 0x16c9c0
Parcel::Parcel(const Parcel& other)
    : capacity_(other.capacity_), begin_(nullptr), end_(nullptr), cap_end_(nullptr) {
    uint64_t n = other.count();
    uint64_t alloc_n = std::max(capacity_, n);
    if (alloc_n > 0) {
        ReserveParcelStorage(*this, alloc_n);
        for (uint64_t i = 0; i < n; ++i) {
            new (end_) Value(other.begin_[i]);
            ++end_;
        }
    }
}

// Matches Parcel::ctor(Parcel&&) @ 0x16bc88
Parcel::Parcel(Parcel&& other) noexcept
    : capacity_(other.capacity_),
      begin_(other.begin_),
      end_(other.end_),
      cap_end_(other.cap_end_) {
    other.capacity_ = 0ULL;
    other.begin_ = nullptr;
    other.end_ = nullptr;
    other.cap_end_ = nullptr;
}

// Matches Parcel::dtor() @ 0x16bce4
Parcel::~Parcel() noexcept {
    FreeParcelStorage(*this);
}

// Matches Parcel::operator=(Parcel const&) @ 0x16c9ec
Parcel& Parcel::operator=(const Parcel& other) {
    if (this != &other) {
        FreeParcelStorage(*this);
        capacity_ = other.capacity_;
        uint64_t n = other.count();
        uint64_t alloc_n = std::max(capacity_, n);
        if (alloc_n > 0) {
            ReserveParcelStorage(*this, alloc_n);
            for (uint64_t i = 0; i < n; ++i) {
                new (end_) Value(other.begin_[i]);
                ++end_;
            }
        }
    }
    return *this;
}

// Matches Parcel::operator=(Parcel&&) @ 0x16bcec
Parcel& Parcel::operator=(Parcel&& other) noexcept {
    if (this != &other) {
        FreeParcelStorage(*this);
        capacity_ = other.capacity_;
        begin_ = other.begin_;
        end_ = other.end_;
        cap_end_ = other.cap_end_;
        other.capacity_ = 0ULL;
        other.begin_ = nullptr;
        other.end_ = nullptr;
        other.cap_end_ = nullptr;
    }
    return *this;
}

// Matches Parcel::init() @ 0x16ca2c: ret
void Parcel::init() noexcept {}

// Matches Parcel::isFull() @ 0x16be78 (24 bytes):
//   ldp x9, x8, [x0, #8]
//   ldr x10, [x0]
//   sub x8, x8, x9
//   cmp x10, x8, asr #5
//   cset w0, eq
//   ret
bool Parcel::isFull() const noexcept {
    const ptrdiff_t byte_diff =
        reinterpret_cast<const uint8_t*>(end_) - reinterpret_cast<const uint8_t*>(begin_);
    return static_cast<int64_t>(capacity_) == (byte_diff >> 5);
}

// Matches Parcel::put(Value const&) @ 0x16c5e0 & Parcel::put(int const&) @ 0x16bd40:
// Checks if count() == capacity_ (`asr x24, x10, #5; cmp x24, x9; b.eq #ret`),
// grows vector if end_ == cap_end_, and constructs Value at end_ (`add x8, x22, #0x20`).
void Parcel::put(const Value& v) {
    if (isFull()) {
        return;
    }
    if (end_ >= cap_end_) {
        uint64_t new_cap = std::max<uint64_t>(capacity_, count() + 1ULL);
        ReserveParcelStorage(*this, new_cap);
    }
    if (end_ < cap_end_) {
        new (end_) Value(v);
        ++end_;
    }
}

void Parcel::put(Value&& v) {
    if (isFull()) {
        return;
    }
    if (end_ >= cap_end_) {
        uint64_t new_cap = std::max<uint64_t>(capacity_, count() + 1ULL);
        ReserveParcelStorage(*this, new_cap);
    }
    if (end_ < cap_end_) {
        new (end_) Value(std::move(v));
        ++end_;
    }
}

void Parcel::put(const int32_t& v)      { put(Value(v)); }
void Parcel::put(const int64_t& v)      { put(Value(v)); }
void Parcel::put(const float& v)        { put(Value(v)); }
void Parcel::put(const double& v)       { put(Value(v)); }
void Parcel::put(const char* v)         { put(Value(v)); }
void Parcel::put(const std::string& v)  { put(Value(v)); }
void Parcel::put(std::string&& v)       { put(Value(std::move(v))); }
void Parcel::put(void* v)               { put(Value(v)); }

// Matches Parcel::get(ulong) @ 0x16c990 (36 bytes):
//   ldr x9, [x0]; cmp x9, x1; b.ls #out_of_range
//   ldr x9, [x0, #8]; add x1, x9, x1, lsl #5; b Value::ctor(Value const&)
Value Parcel::get(uint64_t index) const {
    if (index >= capacity_ || index >= count()) {
        return Value();
    }
    return Value(begin_[index]);
}

}  // namespace player
}  // namespace ttm
}  // namespace ss
}  // namespace com

extern "C" {

int32_t ttmplayer_verify_vstring_sso_and_heap(const char* short_str, const char* long_str) {
    using com::ss::ttm::player::VString;
    VString s_short(short_str ? short_str : "ttm_sso");
    VString s_long(long_str ? long_str : "ttmplayer_long_heap_allocated_string_payload_2026");

    // Verify SSO tag bit 0 is 0 for <=22 chars, and 1 for >22 chars
    if ((s_short.short_rep.tag & 1U) != 0U) {
        return -1;
    }
    if ((s_long.short_rep.tag & 1U) != 1U) {
        return -2;
    }
    if (std::strcmp(s_short.c_str(), short_str ? short_str : "ttm_sso") != 0) {
        return -3;
    }
    if (std::strcmp(s_long.c_str(),
                    long_str ? long_str : "ttmplayer_long_heap_allocated_string_payload_2026") != 0) {
        return -4;
    }
    return 1;
}

int32_t ttmplayer_verify_value_polymorphism(int32_t i32_in,
                                            int64_t i64_in,
                                            float f32_in,
                                            double f64_in,
                                            const char* str_in) {
    using com::ss::ttm::player::Value;
    using com::ss::ttm::player::ValueType;

    Value v_int(i32_in);
    Value v_long(i64_in);
    Value v_flt(f32_in);
    Value v_dbl(f64_in);
    Value v_str(str_in ? str_in : "ttplayer_val");

    if (v_int.type() != ValueType::kValueTypeInt32 || v_int.getInt32() != i32_in) return -1;
    if (v_long.type() != ValueType::kValueTypeInt64 || v_long.getInt64() != i64_in) return -2;
    if (v_flt.type() != ValueType::kValueTypeFloat || v_flt.getFloat() != f32_in) return -3;
    if (v_dbl.type() != ValueType::kValueTypeDouble || v_dbl.getDouble() != f64_in) return -4;
    if (v_str.type() != ValueType::kValueTypeString ||
        v_str.getString() != (str_in ? str_in : "ttplayer_val")) {
        return -5;
    }
    return 1;
}

int32_t ttmplayer_verify_parcel_container(uint64_t capacity) {
    using com::ss::ttm::player::Parcel;
    if (capacity < 3) capacity = 3;
    Parcel p(capacity);
    if (p.size() != capacity || p.isFull()) return -1;

    for (uint64_t i = 0; i < capacity; ++i) {
        p.put(static_cast<int32_t>(i * 10 + 7));
    }
    if (!p.isFull()) return -2;

    // Extra put when full must be ignored per 0x16bd84 (cmp x24, x9; b.eq #0x16be3c)
    p.put(static_cast<int32_t>(99999));
    if (p.count() != capacity) return -3;

    for (uint64_t i = 0; i < capacity; ++i) {
        if (p.get(i).getInt32() != static_cast<int32_t>(i * 10 + 7)) {
            return -4;
        }
    }
    return 1;
}

}  // extern "C"
