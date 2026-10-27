// ============================================================================
// Clean-Room C++17 Core Implementation for liblynx.so (Target 120 / 169)
// Hiện thực C++17 sạch lõi cho liblynx.so (lynx::lepus::Value)
// ============================================================================
#include "lynx_core.h"

namespace lynx {
namespace lepus {

// 0x14c03c..0x14c044: mov w8, #1; strb w8, [x0, #8]; ret
Value::Value(CreateAsUndefinedTag) noexcept : type_(Value_Undefined) {}

// 0x14c048..0x14c0c0: Copy Constructor
// Checks (type_ - 9) <= 4 (Value_String..Value_ByteArray), atomically increments ref_count_ at [ptr + 8]
Value::Value(const Value& other) noexcept
    : payload_(other.payload_),
      type_(other.type_),
      flags_(other.flags_),
      env_(other.env_),
      ext_ref_(other.ext_ref_) {
    if (IsReference() && payload_.ref) {
        payload_.ref->AddRef();
    }
}

// 0x14c228..0x14c278: Move Constructor
// Copies 16-byte payload+type (ldr q0, [x19]; str q0, [x20]) and sets source type_ = 0 (strb wzr, [x19, #8])
Value::Value(Value&& other) noexcept
    : payload_(other.payload_),
      type_(other.type_),
      flags_(other.flags_),
      env_(other.env_),
      ext_ref_(other.ext_ref_) {
    other.type_ = Value_Nil;
    other.payload_.u64 = 0;
    other.env_ = nullptr;
    other.ext_ref_ = nullptr;
}

// 0x14c27c..0x14c364: Copy Assignment
Value& Value::operator=(const Value& other) noexcept {
    if (this != &other) {
        if (other.IsReference() && other.payload_.ref) {
            other.payload_.ref->AddRef();
        }
        FreeValue();
        payload_ = other.payload_;
        type_ = other.type_;
        flags_ = other.flags_;
        env_ = other.env_;
        ext_ref_ = other.ext_ref_;
    }
    return *this;
}

// 0x14c368..0x14c428: Move Assignment
Value& Value::operator=(Value&& other) noexcept {
    if (this != &other) {
        FreeValue();
        payload_ = other.payload_;
        type_ = other.type_;
        flags_ = other.flags_;
        env_ = other.env_;
        ext_ref_ = other.ext_ref_;
        other.type_ = Value_Nil;
        other.payload_.u64 = 0;
    }
    return *this;
}

// 0x14c1b4..0x14c224: FreeValue()
void Value::FreeValue() noexcept {
    if (IsReference() && payload_.ref) {
        payload_.ref->Release();
        payload_.ref = nullptr;
    }
    type_ = Value_Nil;
}

// 0x14c594..0x14c5ab: Value(bool)
Value::Value(bool val) noexcept {
    payload_.b = val;
    type_ = Value_Bool;
    flags_ = 0;
}

// 0x14c790..0x14c7a0: mov w8, #0x10; str x1, [x0]; strb w8, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(void* ptr) noexcept {
    payload_.ptr = ptr;
    type_ = Value_CPointer;
    flags_ = 0;
}

// 0x14c7a4..0x14c7b4: mov w8, #0xe; str x1, [x0]; strb w8, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(CFunction func) noexcept {
    payload_.ptr = reinterpret_cast<void*>(func);
    type_ = Value_CFunction;
    flags_ = 0;
}

// 0x14c7b8..0x14c7c8: mov w8, #0xf; str x1, [x0]; strb w8, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(BuiltinFunctionTable* table) noexcept {
    payload_.ptr = table;
    type_ = Value_BuiltinFunctionTable;
    flags_ = 0;
}

// 0x14c7cc..0x14c7e0: tbz w1, #0, #0x14c7e0; and w8, w2, #1; mov w9, #8; strb w8, [x0]; strb w9, [x0, #8]
Value::Value(bool has_val, bool val) noexcept {
    if (has_val) {
        payload_.b = val;
        type_ = Value_Bool;
    }
}

// 0x14c7e4..0x14c7f4: mov w8, #3; str d0, [x0]; strb w8, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(double val) noexcept {
    payload_.f64 = val;
    type_ = Value_Double;
    flags_ = 0;
}

// 0x14c7f8..0x14c808: mov w8, #4; str w1, [x0]; strb w8, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(int32_t val) noexcept {
    payload_.i32 = val;
    type_ = Value_Int32;
    flags_ = 0;
}

// 0x14c80c..0x14c81c: mov w8, #5; str w1, [x0]; strb w8, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(uint32_t val) noexcept {
    payload_.u32 = val;
    type_ = Value_UInt32;
    flags_ = 0;
}

// 0x14c820..0x14c830: mov w8, #6; str x1, [x0]; strb w8, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(int64_t val) noexcept {
    payload_.i64 = val;
    type_ = Value_Int64;
    flags_ = 0;
}

// 0x14c834..0x14c844: mov w8, #7; str x1, [x0]; strb w8, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(uint64_t val) noexcept {
    payload_.u64 = val;
    type_ = Value_UInt64;
    flags_ = 0;
}

// 0x14c848..0x14c85c: and w8, w1, #0xff; mov w9, #5; str w8, [x0]; strb w9, [x0, #8]; str wzr, [x0, #0xc]; ret
Value::Value(uint8_t val) noexcept {
    payload_.u32 = static_cast<uint32_t>(val);
    type_ = Value_UInt32;
    flags_ = 0;
}

// 0x14c860..0x14c88c: Value(const RefPtr<Dictionary>&) -> type_ = 0x0b (Value_Table)
Value::Value(const fml::RefPtr<Dictionary>& dict) noexcept {
    payload_.ref = dict.get();
    type_ = Value_Table;
    flags_ = 0;
    if (payload_.ref) payload_.ref->AddRef();
}

// 0x14c890..0x14c8a8: Value(RefPtr<Dictionary>&&) -> type_ = 0x0b (Value_Table)
Value::Value(fml::RefPtr<Dictionary>&& dict) noexcept {
    payload_.ref = dict.ReleaseOwnership();
    type_ = Value_Table;
    flags_ = 0;
}

// 0x14c8ac..0x14c8d8: Value(const RefPtr<CArray>&) -> type_ = 0x0a (Value_Array)
Value::Value(const fml::RefPtr<CArray>& arr) noexcept {
    payload_.ref = arr.get();
    type_ = Value_Array;
    flags_ = 0;
    if (payload_.ref) payload_.ref->AddRef();
}

// 0x14c8dc..0x14c8f4: Value(RefPtr<CArray>&&) -> type_ = 0x0a (Value_Array)
Value::Value(fml::RefPtr<CArray>&& arr) noexcept {
    payload_.ref = arr.ReleaseOwnership();
    type_ = Value_Array;
    flags_ = 0;
}

double Value::Number() const noexcept {
    switch (type_) {
        case Value_Double: return payload_.f64;
        case Value_Int32:  return static_cast<double>(payload_.i32);
        case Value_UInt32: return static_cast<double>(payload_.u32);
        case Value_Int64:  return static_cast<double>(payload_.i64);
        case Value_UInt64: return static_cast<double>(payload_.u64);
        default:           return 0.0;
    }
}

} // namespace lepus
} // namespace lynx
