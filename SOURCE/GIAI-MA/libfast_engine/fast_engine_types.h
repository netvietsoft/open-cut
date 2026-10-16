// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_types.h
// Description: Core types, object descriptors, bytecode opcodes, and slice indices
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

namespace fast_engine {

// EN: Core Bytecode Opcodes executed by FastEngine Virtual Machine
// VN: Mã lệnh Bytecode lõi được thực thi bởi máy ảo FastEngine
enum class Opcode : uint8_t {
    NOP                 = 9,
    POP_TOP             = 1,
    ROT_TWO             = 2,
    DUP_TOP             = 4,
    BINARY_ADD          = 23,
    BINARY_SUBTRACT     = 24,
    BINARY_MULTIPLY     = 20,
    BINARY_TRUE_DIVIDE  = 27,
    BINARY_MODULO       = 22,
    BINARY_POWER        = 19,
    BINARY_AND          = 64,
    BINARY_OR           = 66,
    BINARY_XOR          = 65,
    INPLACE_ADD         = 55,
    INPLACE_SUBTRACT    = 56,
    STORE_FAST          = 125,
    LOAD_FAST           = 124,
    STORE_GLOBAL        = 97,
    LOAD_GLOBAL         = 116,
    LOAD_CONST          = 100,
    LOAD_NAME           = 101,
    STORE_NAME          = 90,
    COMPARE_OP          = 107,
    JUMP_FORWARD        = 110,
    JUMP_IF_FALSE_OR_POP= 111,
    JUMP_IF_TRUE_OR_POP = 112,
    JUMP_ABSOLUTE       = 113,
    POP_JUMP_IF_FALSE   = 114,
    POP_JUMP_IF_TRUE    = 115,
    LOAD_METHOD         = 160,
    CALL_METHOD         = 161,
    CALL_FUNCTION       = 131,
    BUILD_TUPLE         = 102,
    BUILD_LIST          = 103,
    BUILD_MAP           = 105,
    BUILD_SET           = 104,
    BINARY_SUBSCR       = 25,
    STORE_SUBSCR        = 60,
    RETURN_VALUE        = 83
};

// EN: Comparison operators for COMPARE_OP instruction
// VN: Toán tử so sánh cho chỉ lệnh COMPARE_OP
enum class CompareOp : uint8_t {
    LT = 0, // <
    LE = 1, // <=
    EQ = 2, // ==
    NE = 3, // !=
    GT = 4, // >
    GE = 5  // >=
};

// EN: Fundamental object type tags
// VN: Nhãn định danh các kiểu đối tượng cơ bản
enum class ObjTypeTag : uint8_t {
    TYPE_NULL = 0,
    TYPE_BOOL = 1,
    TYPE_INT  = 2,
    TYPE_FLOAT= 3,
    TYPE_STR  = 4,
    TYPE_BYTES= 5,
    TYPE_TUPLE= 6,
    TYPE_LIST = 7,
    TYPE_DICT = 8,
    TYPE_SET  = 9,
    TYPE_CODE = 10,
    TYPE_FUNC = 11,
    TYPE_CFUNC= 12,
    TYPE_MODULE = 13,
    TYPE_CUSTOM = 14
};

// EN: Forward declarations of core classes
// VN: Khai báo trước các lớp đối tượng cốt lõi
class Obj;
class TypeObj;
class StrObj;
class LongObj;
class FloatObj;
class TupleObj;
class DictObj;
class CodeObj;
class FrameObj;
class Engine;
class FastEngine;

// EN: FastEngine error structure
// VN: Cấu trúc thông tin lỗi của FastEngine
struct Error {
    int32_t code = 0;
    std::string message;
    std::string traceback;

    bool HasError() const { return code != 0; }
    void Clear() { code = 0; message.clear(); traceback.clear(); }
};

// EN: Slice indices descriptor matching ABI symbol fast_engine::SliceObj::AdjustIndices (Opcode 0xeb2e0)
// VN: Mô tả chỉ số cắt lát khớp biểu tượng ABI fast_engine::SliceObj::AdjustIndices (Opcode 0xeb2e0)
struct SliceIndices {
    int64_t start = 0;
    int64_t stop = 0;
    int64_t step = 1;
    int64_t length = 0;

    // EN: Adjust indices against sequence length (Opcode 0xeb2e0)
    // VN: Chuẩn hóa chỉ số cắt lát theo độ dài chuỗi (Opcode 0xeb2e0)
    static int64_t AdjustIndices(int64_t length, int64_t* start, int64_t* stop, int64_t step) {
        if (step == 0) {
            return 0; // Invalid step
        }

        if (step > 0) {
            if (*start < 0) {
                *start += length;
                if (*start < 0) *start = 0;
            } else if (*start >= length) {
                *start = length;
            }

            if (*stop < 0) {
                *stop += length;
                if (*stop < 0) *stop = 0;
            } else if (*stop >= length) {
                *stop = length;
            }

            if (*stop < *start) {
                return 0;
            }
            return (*stop - *start + step - 1) / step;
        } else {
            // Negative step
            if (*start < 0) {
                *start += length;
                if (*start < 0) *start = -1;
            } else if (*start >= length) {
                *start = length - 1;
            }

            if (*stop < 0) {
                *stop += length;
                if (*stop < 0) *stop = -1;
            } else if (*stop >= length) {
                *stop = length - 1;
            }

            if (*start < *stop) {
                return 0;
            }
            return (*start - *stop - step - 1) / (-step);
        }
    }
};

// EN: Identifier hash structure matching ABI symbol fast_engine::Obj::GetAttrId
// VN: Cấu trúc định danh hash khớp biểu tượng ABI fast_engine::Obj::GetAttrId
struct Identifier {
    std::string name;
    uint64_t hash = 0;

    Identifier() = default;
    explicit Identifier(const std::string& n) : name(n) {
        // FNV-1a hash algorithm
        uint64_t h = 14695981039346656037ULL;
        for (char c : name) {
            h ^= static_cast<uint64_t>(c);
            h *= 1099511628211ULL;
        }
        hash = h;
    }
};

// EN: Configuration provider interface for FastEngine initialization (Opcode 0x46198)
// VN: Giao diện nhà cung cấp cấu hình phục vụ khởi tạo FastEngine (Opcode 0x46198)
class FastEngineConfigProvider {
public:
    virtual ~FastEngineConfigProvider() = default;
    virtual int32_t GetMaxMemoryMB() const { return 64; }
    virtual int32_t GetVMThreadPoolSize() const { return 4; }
    virtual bool EnableBytecodeOptimization() const { return true; }
    virtual bool EnableSecuritySandbox() const { return true; }
};

} // namespace fast_engine
