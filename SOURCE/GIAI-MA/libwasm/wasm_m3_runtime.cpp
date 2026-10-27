/**
 * @file wasm_m3_runtime.cpp
 * @brief Implementation of VMSDK InteropRuntime, Wasm3Runtime & Binary Section Parsers
 *        Triển khai lớp InteropRuntime, Wasm3Runtime và Bộ phân tích các phân đoạn nhị phân Wasm
 *
 * @details
 * Clean-room C++17 reconstruction of `libwasm.so` section parsers (`0x033008..0x035670`),
 * `WASMGCPersistent` (`0x011a44..0x011b88`), `Wasm3Memory`, `Wasm3Table`, `Wasm3Global`,
 * `Wasm3Function`, `Wasm3Module`, `Wasm3Runtime`, and `InteropRuntime`.
 *
 * Evidence Classification / Phân loại bằng chứng:
 * - [OBSERVED]: Exact section parser jump table at `.data.rel.ro 0x03b888..0x03b8e8`,
 *   `M3Function` stride `0x458` (`1,112 bytes`), `M3Module` size `0xF0` (`240 bytes`),
 *   `M3Global` size `0x30` (`48 bytes`), `M3DataSegment` size `0x28` (`40 bytes`).
 */

#include "wasm_m3_runtime.h"
#include "wasm_m3_compile_exec.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace vmsdk {
namespace wasm {

// ============================================================================
// 1. WASMGCPersistent Implementation ([OBSERVED] in .text 0x011a44..0x011b88)
//    Triển khai lớp quản lý tham chiếu GC `WASMGCPersistent` ([QUAN SÁT ĐƯỢC])
// ============================================================================

void WASMGCPersistent::Reset(LEPUSRuntime* rt) noexcept {
    // [OBSERVED] 0x011a44..0x011a74: clears stored JSValue and weak callback state
    // Xóa giá trị JSValue được giữ và đặt lại trạng thái callback tham chiếu yếu
    (void)rt;
    ctx_        = nullptr;
    rt_         = nullptr;
    val_        = MakeLepusUndefined();
    weak_param_ = nullptr;
    weak_cb_    = nullptr;
    is_weak_    = false;
}

void WASMGCPersistent::Reset(LEPUSContext* ctx, const LEPUSValue& val) noexcept {
    // [OBSERVED] 0x011a78..0x011b3c: resets previous value and stores new persistent value
    // Giải phóng giá trị cũ và lưu trữ tham chiếu bền vững mới
    Reset(rt_);
    ctx_ = ctx;
    val_ = val;
}

void WASMGCPersistent::SetWeak(void* param, void (*cb)(void*)) noexcept {
    // [OBSERVED] 0x011b40..0x011b64: marks handle as weak with finalizer callback
    // Đánh dấu tham chiếu là yếu (weak) kèm theo hàm gọi lại khi thu gom rác
    weak_param_ = param;
    weak_cb_    = cb;
    is_weak_    = (cb != nullptr);
}

void WASMGCPersistent::ClearWeak() noexcept {
    // [OBSERVED] 0x011b68..0x011b74: clears weak state back to strong reference
    // Hủy trạng thái tham chiếu yếu, khôi phục về tham chiếu mạnh
    weak_param_ = nullptr;
    weak_cb_    = nullptr;
    is_weak_    = false;
}

// ============================================================================
// 2. LEB128 & Binary Stream Readers ([OBSERVED] in 0x033008..0x0357b0)
//    Triển khai các hàm đọc số nguyên LEB128 và luồng byte nhị phân
// ============================================================================

M3Result ReadLEB_u32(uint32_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept {
    if (!out_value || !io_bytes || !*io_bytes) {
        return m3_err::wasmMalformed;
    }
    const uint8_t* ptr = *io_bytes;
    uint32_t result = 0;
    uint32_t shift  = 0;
    for (uint32_t i = 0; i < 5; ++i) {
        if (ptr >= end) {
            return m3_err::wasmUnderrun;
        }
        uint8_t byte = *ptr++;
        result |= static_cast<uint32_t>(byte & 0x7FU) << shift;
        if ((byte & 0x80U) == 0) {
            if (i == 4 && (byte & 0xF0U) != 0) {
                return m3_err::lebOverflow;
            }
            *io_bytes  = ptr;
            *out_value = result;
            return m3_err::none;
        }
        shift += 7;
    }
    return m3_err::lebOverflow;
}

M3Result ReadLEB_u64(uint64_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept {
    if (!out_value || !io_bytes || !*io_bytes) {
        return m3_err::wasmMalformed;
    }
    const uint8_t* ptr = *io_bytes;
    uint64_t result = 0;
    uint32_t shift  = 0;
    for (uint32_t i = 0; i < 10; ++i) {
        if (ptr >= end) {
            return m3_err::wasmUnderrun;
        }
        uint8_t byte = *ptr++;
        result |= static_cast<uint64_t>(byte & 0x7FU) << shift;
        if ((byte & 0x80U) == 0) {
            if (i == 9 && (byte & 0xFEU) != 0) {
                return m3_err::lebOverflow;
            }
            *io_bytes  = ptr;
            *out_value = result;
            return m3_err::none;
        }
        shift += 7;
    }
    return m3_err::lebOverflow;
}

M3Result ReadLEB_i32(int32_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept {
    if (!out_value || !io_bytes || !*io_bytes) {
        return m3_err::wasmMalformed;
    }
    const uint8_t* ptr = *io_bytes;
    uint32_t result = 0;
    uint32_t shift  = 0;
    uint8_t byte    = 0;
    for (uint32_t i = 0; i < 5; ++i) {
        if (ptr >= end) {
            return m3_err::wasmUnderrun;
        }
        byte = *ptr++;
        result |= static_cast<uint32_t>(byte & 0x7FU) << shift;
        shift += 7;
        if ((byte & 0x80U) == 0) {
            if (i == 4) {
                bool sign_bit = (byte & 0x08U) != 0;
                uint8_t upper = byte & 0x70U;
                if ((sign_bit && upper != 0x70U) || (!sign_bit && upper != 0x00U)) {
                    return m3_err::lebOverflow;
                }
            }
            if (shift < 32 && (byte & 0x40U) != 0) {
                result |= (~0U << shift);
            }
            *io_bytes  = ptr;
            *out_value = static_cast<int32_t>(result);
            return m3_err::none;
        }
    }
    return m3_err::lebOverflow;
}

M3Result ReadLEB_i64(int64_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept {
    if (!out_value || !io_bytes || !*io_bytes) {
        return m3_err::wasmMalformed;
    }
    const uint8_t* ptr = *io_bytes;
    uint64_t result = 0;
    uint32_t shift  = 0;
    uint8_t byte    = 0;
    for (uint32_t i = 0; i < 10; ++i) {
        if (ptr >= end) {
            return m3_err::wasmUnderrun;
        }
        byte = *ptr++;
        result |= static_cast<uint64_t>(byte & 0x7FU) << shift;
        shift += 7;
        if ((byte & 0x80U) == 0) {
            if (i == 9) {
                bool sign_bit = (byte & 0x01U) != 0;
                uint8_t upper = byte & 0x7EU;
                if ((sign_bit && upper != 0x7EU) || (!sign_bit && upper != 0x00U)) {
                    return m3_err::lebOverflow;
                }
            }
            if (shift < 64 && (byte & 0x40U) != 0) {
                result |= (~0ULL << shift);
            }
            *io_bytes  = ptr;
            *out_value = static_cast<int64_t>(result);
            return m3_err::none;
        }
    }
    return m3_err::lebOverflow;
}

M3Result Read_u8(uint8_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept {
    if (!out_value || !io_bytes || !*io_bytes) {
        return m3_err::wasmMalformed;
    }
    if (*io_bytes >= end) {
        return m3_err::wasmUnderrun;
    }
    *out_value = *(*io_bytes)++;
    return m3_err::none;
}

M3Result Read_u32(uint32_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept {
    if (!out_value || !io_bytes || !*io_bytes) {
        return m3_err::wasmMalformed;
    }
    if (static_cast<size_t>(end - *io_bytes) < sizeof(uint32_t)) {
        return m3_err::wasmUnderrun;
    }
    uint32_t val = 0;
    std::memcpy(&val, *io_bytes, sizeof(uint32_t));
    *io_bytes += sizeof(uint32_t);
    *out_value = val;
    return m3_err::none;
}

M3Result Read_u64(uint64_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept {
    if (!out_value || !io_bytes || !*io_bytes) {
        return m3_err::wasmMalformed;
    }
    if (static_cast<size_t>(end - *io_bytes) < sizeof(uint64_t)) {
        return m3_err::wasmUnderrun;
    }
    uint64_t val = 0;
    std::memcpy(&val, *io_bytes, sizeof(uint64_t));
    *io_bytes += sizeof(uint64_t);
    *out_value = val;
    return m3_err::none;
}

M3Result Read_utf8(const char** out_utf8, const uint8_t** io_bytes, const uint8_t* end) noexcept {
    if (!out_utf8 || !io_bytes || !*io_bytes) {
        return m3_err::wasmMalformed;
    }
    uint32_t len = 0;
    M3Result res = ReadLEB_u32(&len, io_bytes, end);
    if (res) {
        return res;
    }
    if (static_cast<size_t>(end - *io_bytes) < len) {
        return m3_err::wasmUnderrun;
    }
    char* copy = static_cast<char*>(std::calloc(static_cast<size_t>(len) + 1U, 1U));
    if (!copy) {
        return m3_err::mallocFailed;
    }
    if (len > 0) {
        std::memcpy(copy, *io_bytes, len);
    }
    copy[len]  = '\0';
    *io_bytes += len;
    *out_utf8  = copy;
    return m3_err::none;
}

M3Result NormalizeWasmType(M3ValueType* out_type, int8_t wasm_type_byte) noexcept {
    // [OBSERVED] 0x0331e0..0x033240: maps Wasm binary value_type byte to M3ValueType
    // Ánh xạ byte kiểu dữ liệu nhị phân Wasm sang kiểu M3ValueType
    if (!out_type) {
        return m3_err::invalidTypeId;
    }
    switch (static_cast<uint8_t>(wasm_type_byte)) {
        case kWasmBinVoid:
            *out_type = c_m3Type_none;
            return m3_err::none;
        case kWasmBinI32:
            *out_type = c_m3Type_i32;
            return m3_err::none;
        case kWasmBinI64:
            *out_type = c_m3Type_i64;
            return m3_err::none;
        case kWasmBinF32:
            *out_type = c_m3Type_f32;
            return m3_err::none;
        case kWasmBinF64:
            *out_type = c_m3Type_f64;
            return m3_err::none;
        case kWasmBinFuncRef:
            *out_type = c_m3Type_funcref;
            return m3_err::none;
        case kWasmBinExternRef:
            *out_type = c_m3Type_externref;
            return m3_err::none;
        default:
            *out_type = c_m3Type_unknown;
            return m3_err::invalidTypeId;
    }
}

M3Result ScanInitExpr(const uint8_t** io_bytes, const uint8_t* end,
                      const uint8_t** out_expr_start, uint32_t* out_expr_size) noexcept {
    // [OBSERVED] Scans an initializer expression (`0x41/0x42/0x43/0x44/0x23/0xD0 ... 0x0B`)
    // Quét biểu thức khởi tạo hằng số kết thúc bằng byte `0x0B` (`end`)
    const uint8_t* start = *io_bytes;
    if (start >= end) {
        return m3_err::wasmMissingInitExpr;
    }
    uint8_t opcode = 0;
    M3Result res = Read_u8(&opcode, io_bytes, end);
    if (res) return res;

    switch (opcode) {
        case 0x41: { // i32.const
            int32_t dummy = 0;
            res = ReadLEB_i32(&dummy, io_bytes, end);
            if (res) return res;
            break;
        }
        case 0x42: { // i64.const
            int64_t dummy = 0;
            res = ReadLEB_i64(&dummy, io_bytes, end);
            if (res) return res;
            break;
        }
        case 0x43: { // f32.const
            uint32_t dummy = 0;
            res = Read_u32(&dummy, io_bytes, end);
            if (res) return res;
            break;
        }
        case 0x44: { // f64.const
            uint64_t dummy = 0;
            res = Read_u64(&dummy, io_bytes, end);
            if (res) return res;
            break;
        }
        case 0x23: { // global.get
            uint32_t dummy = 0;
            res = ReadLEB_u32(&dummy, io_bytes, end);
            if (res) return res;
            break;
        }
        case 0xD0: { // ref.null
            uint8_t dummy = 0;
            res = Read_u8(&dummy, io_bytes, end);
            if (res) return res;
            break;
        }
        case 0xD2: { // ref.func
            uint32_t dummy = 0;
            res = ReadLEB_u32(&dummy, io_bytes, end);
            if (res) return res;
            break;
        }
        default:
            return m3_err::wasmMalformed;
    }

    uint8_t end_op = 0;
    res = Read_u8(&end_op, io_bytes, end);
    if (res) return res;
    if (end_op != 0x0B) {
        return m3_err::wasmMalformed;
    }

    *out_expr_start = start;
    *out_expr_size  = static_cast<uint32_t>(*io_bytes - start);
    return m3_err::none;
}

M3Result EvaluateInitExpr(M3Module* module, const uint8_t* expr, uint32_t expr_size,
                          M3ValueType expected_type, int64_t* out_bits) noexcept {
    if (!expr || expr_size < 2 || !out_bits) {
        return m3_err::wasmMissingInitExpr;
    }
    const uint8_t* ptr = expr;
    const uint8_t* end = expr + expr_size;
    uint8_t opcode     = 0;
    M3Result res       = Read_u8(&opcode, &ptr, end);
    if (res) return res;

    int64_t bits = 0;
    switch (opcode) {
        case 0x41: { // i32.const
            if (expected_type != c_m3Type_none && expected_type != c_m3Type_i32) {
                return m3_err::globalTypeMismatch;
            }
            int32_t val = 0;
            res = ReadLEB_i32(&val, &ptr, end);
            if (res) return res;
            bits = static_cast<int64_t>(val);
            break;
        }
        case 0x42: { // i64.const
            if (expected_type != c_m3Type_none && expected_type != c_m3Type_i64) {
                return m3_err::globalTypeMismatch;
            }
            int64_t val = 0;
            res = ReadLEB_i64(&val, &ptr, end);
            if (res) return res;
            bits = val;
            break;
        }
        case 0x43: { // f32.const
            if (expected_type != c_m3Type_none && expected_type != c_m3Type_f32) {
                return m3_err::globalTypeMismatch;
            }
            uint32_t raw = 0;
            res = Read_u32(&raw, &ptr, end);
            if (res) return res;
            bits = static_cast<int64_t>(raw);
            break;
        }
        case 0x44: { // f64.const
            if (expected_type != c_m3Type_none && expected_type != c_m3Type_f64) {
                return m3_err::globalTypeMismatch;
            }
            uint64_t raw = 0;
            res = Read_u64(&raw, &ptr, end);
            if (res) return res;
            bits = static_cast<int64_t>(raw);
            break;
        }
        case 0x23: { // global.get
            uint32_t global_idx = 0;
            res = ReadLEB_u32(&global_idx, &ptr, end);
            if (res) return res;
            if (!module || global_idx >= module->numGlobals || !module->globals) {
                return m3_err::globaIndexOutOfBounds;
            }
            bits = module->globals[global_idx].i64Value;
            break;
        }
        case 0xD0: // ref.null
            bits = 0;
            break;
        case 0xD2: { // ref.func
            uint32_t func_idx = 0;
            res = ReadLEB_u32(&func_idx, &ptr, end);
            if (res) return res;
            bits = static_cast<int64_t>(func_idx);
            break;
        }
        default:
            return m3_err::wasmMalformed;
    }

    *out_bits = bits;
    return m3_err::none;
}

// ============================================================================
// 3. 12 Wasm Binary Section Parsers ([OBSERVED] in 0x033008..0x035670)
//    Triển khai 12 hàm phân tích phân đoạn nhị phân Wasm
// ============================================================================

static M3ModuleExtraMetadata* EnsureExtraMetadata(M3Module* module) {
    if (!module->extraMetadata) {
        module->extraMetadata = new M3ModuleExtraMetadata();
    }
    return static_cast<M3ModuleExtraMetadata*>(module->extraMetadata);
}

static M3Result Module_AddFunction(M3Module* module, uint32_t typeIndex, const M3ImportInfo* importInfo) {
    // [OBSERVED] 0x0336c0..0x0338c8: grows `module->functions` (stride 0x458) and binds `funcType`
    // Mở rộng mảng `module->functions` (mỗi phần tử 0x458 byte) và gán `funcType`
    if (typeIndex >= module->numFuncTypes || !module->funcTypes) {
        return m3_err::wasmMalformed;
    }
    uint32_t new_index = module->numFunctions;
    if (new_index >= module->allFunctions) {
        uint32_t new_cap = (module->allFunctions == 0) ? 8U : (module->allFunctions * 2U);
        auto* new_funcs = static_cast<M3Function*>(
            std::realloc(module->functions, static_cast<size_t>(new_cap) * sizeof(M3Function)));
        if (!new_funcs) {
            return m3_err::mallocFailed;
        }
        std::memset(new_funcs + module->allFunctions, 0,
                    static_cast<size_t>(new_cap - module->allFunctions) * sizeof(M3Function));
        module->functions    = new_funcs;
        module->allFunctions = new_cap;
    }

    M3Function* func = &module->functions[new_index];
    std::memset(func, 0, sizeof(M3Function));
    func->module   = module;
    func->funcType = module->funcTypes[typeIndex];
    func->index    = new_index;
    if (importInfo) {
        func->import   = *importInfo;
        func->names[0] = importInfo->fieldUtf8;
        func->numNames = (importInfo->fieldUtf8 != nullptr) ? 1U : 0U;
    }
    module->numFunctions++;
    return m3_err::none;
}

static M3Result Module_AddGlobal(M3Module* module, M3Global** out_global,
                                 M3ValueType type, bool isMutable, bool isImported) {
    // [OBSERVED] 0x0354b0..0x03566c: grows `module->globals` (stride 0x30 = 48 bytes)
    // Mở rộng mảng `module->globals` (mỗi phần tử 0x30 = 48 byte)
    uint32_t idx = module->numGlobals;
    auto* new_globals = static_cast<M3Global*>(
        std::realloc(module->globals, static_cast<size_t>(idx + 1U) * sizeof(M3Global)));
    if (!new_globals) {
        return m3_err::mallocFailed;
    }
    module->globals = new_globals;
    M3Global* g     = &module->globals[idx];
    std::memset(g, 0, sizeof(M3Global));
    g->type      = static_cast<uint8_t>(type);
    g->imported  = isImported;
    g->isMutable = isMutable;
    module->numGlobals++;
    if (out_global) {
        *out_global = g;
    }
    return m3_err::none;
}

M3Result ParseSection_Custom(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x035670..0x0357b0: reads custom section UTF-8 name and stores payload slice
    // Đọc tên UTF-8 của Custom Section và lưu con trỏ vùng dữ liệu
    const char* name = nullptr;
    M3Result res = Read_utf8(&name, &bytes, end);
    if (res) {
        return res;
    }
    auto* node = static_cast<M3CustomSection*>(std::calloc(1, sizeof(M3CustomSection)));
    if (!node) {
        std::free(const_cast<char*>(name));
        return m3_err::mallocFailed;
    }
    node->name     = name;
    node->data     = bytes;
    node->dataSize = static_cast<size_t>(end - bytes);
    node->next     = nullptr;

    if (!module->customSections) {
        module->customSections = node;
    } else {
        M3CustomSection* cur = module->customSections;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
    }
    return m3_err::none;
}

M3Result ParseSection_Type(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x033008..0x0335f4: parses `numTypes` function signatures (`form == 0x60`)
    // Phân tích phân đoạn Type (Section 1): đọc các chữ ký hàm `0x60`
    uint32_t num_types = 0;
    M3Result res = ReadLEB_u32(&num_types, &bytes, end);
    if (res) return res;

    if (num_types > 0) {
        module->funcTypes = static_cast<M3FuncType**>(
            std::calloc(num_types, sizeof(M3FuncType*)));
        if (!module->funcTypes) {
            return m3_err::mallocFailed;
        }
        module->numFuncTypes = num_types;

        for (uint32_t i = 0; i < num_types; ++i) {
            int8_t form = 0;
            res = ReadLEB_i32(reinterpret_cast<int32_t*>(&form), &bytes, end);
            if (res) return res;
            if (static_cast<uint8_t>(form) != kWasmBinFuncType) { // -32 == 0x60
                return m3_err::wasmMalformed;
            }

            uint32_t num_args = 0;
            res = ReadLEB_u32(&num_args, &bytes, end);
            if (res) return res;

            if (num_args > 1024U) {
                return m3_err::tooManyArgsRets;
            }
            std::vector<M3ValueType> arg_types(num_args);
            for (uint32_t a = 0; a < num_args; ++a) {
                uint8_t raw_t = 0;
                res = Read_u8(&raw_t, &bytes, end);
                if (res) return res;
                res = NormalizeWasmType(&arg_types[a], static_cast<int8_t>(raw_t));
                if (res) return res;
            }

            uint32_t num_rets = 0;
            res = ReadLEB_u32(&num_rets, &bytes, end);
            if (res) return res;
            if (num_rets > 64U) {
                return m3_err::tooManyArgsRets;
            }
            std::vector<M3ValueType> ret_types(num_rets);
            for (uint32_t r = 0; r < num_rets; ++r) {
                uint8_t raw_t = 0;
                res = Read_u8(&raw_t, &bytes, end);
                if (res) return res;
                res = NormalizeWasmType(&ret_types[r], static_cast<int8_t>(raw_t));
                if (res) return res;
            }

            M3FuncType* ftype = nullptr;
            res = AllocFuncType(&ftype, num_args + num_rets);
            if (res) return res;

            ftype->numRets = static_cast<uint16_t>(num_rets);
            ftype->numArgs = static_cast<uint16_t>(num_args);
            for (uint32_t r = 0; r < num_rets; ++r) {
                ftype->types[r] = static_cast<uint8_t>(ret_types[r]);
            }
            for (uint32_t a = 0; a < num_args; ++a) {
                ftype->types[num_rets + a] = static_cast<uint8_t>(arg_types[a]);
            }

            if (module->environment) {
                Environment_AddFuncType(module->environment, &ftype);
            }
            module->funcTypes[i] = ftype;
        }
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Import(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x0338cc..0x0342dc: parses module imports (func=0, table=1, memory=2, global=3)
    // Phân tích phân đoạn Import (Section 2): hàm, bảng, bộ nhớ, biến toàn cục
    uint32_t num_imports = 0;
    M3Result res = ReadLEB_u32(&num_imports, &bytes, end);
    if (res) return res;

    auto* extra = EnsureExtraMetadata(module);
    for (uint32_t i = 0; i < num_imports; ++i) {
        M3ImportInfo import_info{};
        res = Read_utf8(&import_info.moduleUtf8, &bytes, end);
        if (res) return res;
        res = Read_utf8(&import_info.fieldUtf8, &bytes, end);
        if (res) {
            std::free(const_cast<char*>(import_info.moduleUtf8));
            return res;
        }

        uint8_t kind = 0;
        res = Read_u8(&kind, &bytes, end);
        if (res) {
            std::free(const_cast<char*>(import_info.moduleUtf8));
            std::free(const_cast<char*>(import_info.fieldUtf8));
            return res;
        }

        M3ImportDescriptor desc{};
        desc.moduleName = import_info.moduleUtf8 ? import_info.moduleUtf8 : "";
        desc.fieldName  = import_info.fieldUtf8 ? import_info.fieldUtf8 : "";
        desc.kind       = static_cast<WasmExternalKind>(kind);
        desc.typeIndex  = 0;
        desc.globalType = c_m3Type_none;
        desc.globalMutable = false;

        switch (kind) {
            case kWasmExtFunc: {
                uint32_t type_idx = 0;
                res = ReadLEB_u32(&type_idx, &bytes, end);
                if (res) return res;
                res = Module_AddFunction(module, type_idx, &import_info);
                if (res) return res;
                module->numFuncImports++;
                desc.typeIndex = type_idx;
                break;
            }
            case kWasmExtTable: {
                uint8_t elem_type = 0;
                res = Read_u8(&elem_type, &bytes, end);
                if (res) return res;
                uint8_t has_max = 0;
                res = Read_u8(&has_max, &bytes, end);
                if (res) return res;
                uint32_t init_sz = 0;
                res = ReadLEB_u32(&init_sz, &bytes, end);
                if (res) return res;
                uint32_t max_sz = 0;
                if (has_max) {
                    res = ReadLEB_u32(&max_sz, &bytes, end);
                    if (res) return res;
                }
                module->table0Size         = init_sz;
                module->table0MaxSize      = max_sz;
                module->table0ImportModule = import_info.moduleUtf8;
                module->table0ImportField  = import_info.fieldUtf8;
                module->tableImported      = true;
                break;
            }
            case kWasmExtMemory: {
                uint8_t has_max = 0;
                res = Read_u8(&has_max, &bytes, end);
                if (res) return res;
                uint32_t init_pages = 0;
                res = ReadLEB_u32(&init_pages, &bytes, end);
                if (res) return res;
                uint32_t max_pages = 65536U;
                if (has_max) {
                    res = ReadLEB_u32(&max_pages, &bytes, end);
                    if (res) return res;
                }
                module->memoryInfo.numPages = init_pages;
                module->memoryInfo.maxPages = max_pages;
                module->memoryInfo.pageSize = kWasmPageSizeBytes;
                module->memoryInfo.hasMax   = has_max;
                module->memoryInfo.imported = 1;
                module->memoryImportModule  = import_info.moduleUtf8;
                module->memoryImportField   = import_info.fieldUtf8;
                module->memoryImported      = true;
                break;
            }
            case kWasmExtGlobal: {
                uint8_t raw_type = 0;
                res = Read_u8(&raw_type, &bytes, end);
                if (res) return res;
                M3ValueType gtype = c_m3Type_none;
                res = NormalizeWasmType(&gtype, static_cast<int8_t>(raw_type));
                if (res) return res;
                uint8_t is_mut = 0;
                res = Read_u8(&is_mut, &bytes, end);
                if (res) return res;

                M3Global* global = nullptr;
                res = Module_AddGlobal(module, &global, gtype, is_mut != 0, true);
                if (res) return res;
                global->import     = import_info;
                desc.globalType    = gtype;
                desc.globalMutable = (is_mut != 0);
                break;
            }
            default:
                std::free(const_cast<char*>(import_info.moduleUtf8));
                std::free(const_cast<char*>(import_info.fieldUtf8));
                return m3_err::wasmMalformed;
        }
        extra->imports.push_back(std::move(desc));
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Function(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x0335f8..0x0336bc: parses local function signature indices
    // Phân tích phân đoạn Function (Section 3): đọc chỉ số kiểu chữ ký của các hàm nội bộ
    uint32_t num_funcs = 0;
    M3Result res = ReadLEB_u32(&num_funcs, &bytes, end);
    if (res) return res;

    for (uint32_t i = 0; i < num_funcs; ++i) {
        uint32_t type_idx = 0;
        res = ReadLEB_u32(&type_idx, &bytes, end);
        if (res) return res;
        res = Module_AddFunction(module, type_idx, nullptr);
        if (res) return res;
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Table(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x034e98..0x03518c: parses table limits
    // Phân tích phân đoạn Table (Section 4)
    uint32_t num_tables = 0;
    M3Result res = ReadLEB_u32(&num_tables, &bytes, end);
    if (res) return res;

    for (uint32_t i = 0; i < num_tables; ++i) {
        uint8_t elem_type = 0;
        res = Read_u8(&elem_type, &bytes, end);
        if (res) return res;
        if (elem_type != kWasmBinFuncRef && elem_type != kWasmBinExternRef) {
            return m3_err::wasmMalformed;
        }
        uint8_t flags = 0;
        res = Read_u8(&flags, &bytes, end);
        if (res) return res;
        uint32_t init_sz = 0;
        res = ReadLEB_u32(&init_sz, &bytes, end);
        if (res) return res;
        uint32_t max_sz = 0;
        if (flags & 0x01U) {
            res = ReadLEB_u32(&max_sz, &bytes, end);
            if (res) return res;
            if (max_sz < init_sz) {
                return m3_err::wasmMalformed;
            }
        }
        if (i == 0) {
            module->table0Size    = init_sz;
            module->table0MaxSize = max_sz;
        }
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Memory(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x035190..0x0353d4: parses linear memory limits (enforces single memory)
    // Phân tích phân đoạn Memory (Section 5): kiểm tra giới hạn trang bộ nhớ tuyến tính
    uint32_t num_memories = 0;
    M3Result res = ReadLEB_u32(&num_memories, &bytes, end);
    if (res) return res;
    if (num_memories > 1U || (num_memories == 1U && module->memoryImported)) {
        return m3_err::tooManyMemorySections;
    }
    if (num_memories == 1U) {
        uint8_t flags = 0;
        res = Read_u8(&flags, &bytes, end);
        if (res) return res;
        uint32_t init_pages = 0;
        res = ReadLEB_u32(&init_pages, &bytes, end);
        if (res) return res;
        if (init_pages > 65536U) {
            return m3_err::wasmMalformed;
        }
        uint32_t max_pages = 65536U;
        bool has_max       = (flags & 0x01U) != 0;
        if (has_max) {
            res = ReadLEB_u32(&max_pages, &bytes, end);
            if (res) return res;
            if (max_pages < init_pages || max_pages > 65536U) {
                return m3_err::wasmMalformed;
            }
        }
        module->memoryInfo.numPages = init_pages;
        module->memoryInfo.maxPages = max_pages;
        module->memoryInfo.pageSize = kWasmPageSizeBytes;
        module->memoryInfo.hasMax   = has_max ? 1U : 0U;
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Global(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x0353d8..0x03566c: parses module globals and their initializer expressions
    // Phân tích phân đoạn Global (Section 6)
    uint32_t num_globals = 0;
    M3Result res = ReadLEB_u32(&num_globals, &bytes, end);
    if (res) return res;

    for (uint32_t i = 0; i < num_globals; ++i) {
        uint8_t raw_type = 0;
        res = Read_u8(&raw_type, &bytes, end);
        if (res) return res;
        M3ValueType gtype = c_m3Type_none;
        res = NormalizeWasmType(&gtype, static_cast<int8_t>(raw_type));
        if (res) return res;

        uint8_t is_mut = 0;
        res = Read_u8(&is_mut, &bytes, end);
        if (res) return res;
        if (is_mut > 1U) {
            return m3_err::wasmMalformed;
        }

        M3Global* global = nullptr;
        res = Module_AddGlobal(module, &global, gtype, is_mut != 0, false);
        if (res) return res;

        res = ScanInitExpr(&bytes, end, &global->initExpr, &global->initExprSize);
        if (res) return res;

        int64_t init_bits = 0;
        if (EvaluateInitExpr(module, global->initExpr, global->initExprSize, gtype, &init_bits) == m3_err::none) {
            global->i64Value = init_bits;
        }
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Export(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x0342e0..0x034674: parses module exports and attaches up to 3 names per M3Function
    // Phân tích phân đoạn Export (Section 7) và lưu tên hàm xuất khẩu
    uint32_t num_exports = 0;
    M3Result res = ReadLEB_u32(&num_exports, &bytes, end);
    if (res) return res;

    auto* extra = EnsureExtraMetadata(module);
    for (uint32_t i = 0; i < num_exports; ++i) {
        const char* utf8 = nullptr;
        res = Read_utf8(&utf8, &bytes, end);
        if (res) return res;

        uint8_t kind = 0;
        res = Read_u8(&kind, &bytes, end);
        if (res) {
            std::free(const_cast<char*>(utf8));
            return res;
        }

        uint32_t index = 0;
        res = ReadLEB_u32(&index, &bytes, end);
        if (res) {
            std::free(const_cast<char*>(utf8));
            return res;
        }

        M3ExportInfo exp{};
        exp.name          = utf8 ? utf8 : "";
        exp.kind          = static_cast<WasmExternalKind>(kind);
        exp.index         = index;
        exp.globalType    = c_m3Type_none;
        exp.globalMutable = false;

        if (kind == kWasmExtFunc) {
            if (index >= module->numFunctions) {
                std::free(const_cast<char*>(utf8));
                return m3_err::wasmMalformed;
            }
            M3Function* fn = &module->functions[index];
            if (fn->numNames < 3U) {
                fn->names[fn->numNames++] = utf8;
                utf8 = nullptr; // owned by fn->names
            }
        } else if (kind == kWasmExtGlobal) {
            if (index >= module->numGlobals) {
                std::free(const_cast<char*>(utf8));
                return m3_err::wasmMalformed;
            }
            M3Global* g       = &module->globals[index];
            exp.globalType    = static_cast<M3ValueType>(g->type);
            exp.globalMutable = g->isMutable;
            if (!g->name) {
                g->name = utf8;
                utf8    = nullptr;
            }
        }

        if (utf8) {
            std::free(const_cast<char*>(utf8));
        }
        extra->exports.push_back(std::move(exp));
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Start(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x034678..0x034754: parses start function index
    // Phân tích phân đoạn Start (Section 8)
    uint32_t start_idx = 0;
    M3Result res = ReadLEB_u32(&start_idx, &bytes, end);
    if (res) return res;
    if (start_idx >= module->numFunctions) {
        return m3_err::wasmMalformed;
    }
    module->startFunction = static_cast<int32_t>(start_idx);
    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Element(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x034758..0x034844: records element section bounds for table initialization
    // Phân tích phân đoạn Element (Section 9)
    uint32_t num_segments = 0;
    M3Result res = ReadLEB_u32(&num_segments, &bytes, end);
    if (res) return res;

    module->numElementSegments = num_segments;
    module->elementSection     = bytes;
    module->elementSectionEnd  = end;
    return m3_err::none;
}

M3Result ParseSection_Code(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x034848..0x034a54: parses function bodies and binds `[wasm, wasmEnd)` slices
    // Phân tích phân đoạn Code (Section 10): gắn vùng bytecode cho từng hàm
    uint32_t num_defs = 0;
    M3Result res = ReadLEB_u32(&num_defs, &bytes, end);
    if (res) return res;

    if (num_defs + module->numFuncImports != module->numFunctions) {
        return m3_err::wasmMalformed;
    }

    for (uint32_t i = 0; i < num_defs; ++i) {
        const uint8_t* body_record_start = bytes;
        uint32_t body_size = 0;
        res = ReadLEB_u32(&body_size, &bytes, end);
        if (res) return res;
        if (static_cast<size_t>(end - bytes) < body_size || body_size == 0) {
            return m3_err::wasmUnderrun;
        }
        const uint8_t* body_end = bytes + body_size;
        if (body_end[-1] != 0x0B) { // function body must end with 0x0B (`end`)
            return m3_err::wasmMalformed;
        }

        M3Function* fn   = &module->functions[module->numFuncImports + i];
        fn->wasm         = body_record_start;
        fn->wasmEnd      = body_end;
        fn->ownsWasmCode = false;
        bytes            = body_end;
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

M3Result ParseSection_Data(M3Module* module, const uint8_t* bytes, const uint8_t* end) {
    // [OBSERVED] 0x034a58..0x034e94: parses active/passive linear memory data segments
    // Phân tích phân đoạn Data (Section 11): đọc các đoạn dữ liệu khởi tạo bộ nhớ
    uint32_t num_segs = 0;
    M3Result res = ReadLEB_u32(&num_segs, &bytes, end);
    if (res) return res;

    if (num_segs > 0) {
        module->dataSegments = static_cast<M3DataSegment*>(
            std::calloc(num_segs, sizeof(M3DataSegment)));
        if (!module->dataSegments) {
            return m3_err::mallocFailed;
        }
        module->numDataSegments = num_segs;

        for (uint32_t i = 0; i < num_segs; ++i) {
            M3DataSegment* seg = &module->dataSegments[i];
            uint32_t mode = 0;
            res = ReadLEB_u32(&mode, &bytes, end);
            if (res) return res;

            if (mode == 0) {
                seg->memoryRegion = 0;
                res = ScanInitExpr(&bytes, end, &seg->initExpr, &seg->initExprSize);
                if (res) return res;
            } else if (mode == 1) {
                seg->initExpr     = nullptr;
                seg->initExprSize = 0;
            } else if (mode == 2) {
                res = ReadLEB_u32(&seg->memoryRegion, &bytes, end);
                if (res) return res;
                res = ScanInitExpr(&bytes, end, &seg->initExpr, &seg->initExprSize);
                if (res) return res;
            } else {
                return m3_err::wasmMalformed;
            }

            res = ReadLEB_u32(&seg->size, &bytes, end);
            if (res) return res;
            if (static_cast<size_t>(end - bytes) < seg->size) {
                return m3_err::wasmUnderrun;
            }
            seg->data  = bytes;
            bytes     += seg->size;
        }
    }

    if (bytes != end) {
        return m3_err::wasmSectionOverrun;
    }
    return m3_err::none;
}

namespace {
// [OBSERVED] Exact 12-entry jump table at .data.rel.ro 0x03b888..0x03b8e8
// Bảng nhảy 12 hàm phân tích section khớp tuyệt đối với .data.rel.ro 0x03b888..0x03b8e8
const M3SectionParser kSectionParserTable[12] = {
    &ParseSection_Custom,   // [0]  0x035670
    &ParseSection_Type,     // [1]  0x033008
    &ParseSection_Import,   // [2]  0x0338cc
    &ParseSection_Function, // [3]  0x0335f8
    &ParseSection_Table,    // [4]  0x034e98
    &ParseSection_Memory,   // [5]  0x035190
    &ParseSection_Global,   // [6]  0x0353d8
    &ParseSection_Export,   // [7]  0x0342e0
    &ParseSection_Start,    // [8]  0x034678
    &ParseSection_Element,  // [9]  0x034758
    &ParseSection_Code,     // [10] 0x034848
    &ParseSection_Data,     // [11] 0x034a58
};
} // namespace

const M3SectionParser* GetSectionParserTable() noexcept {
    return kSectionParserTable;
}

// ============================================================================
// 4. Wasm3Memory, Wasm3Table, Wasm3Global, Wasm3Function Implementation
//    Triển khai các lớp đối tượng Wasm3Memory, Wasm3Table, Wasm3Global, Wasm3Function
// ============================================================================

Wasm3Memory::Wasm3Memory(uint32_t initial_pages, uint32_t max_pages, bool has_max)
    : header_(nullptr),
      num_pages_(initial_pages),
      max_pages_(has_max ? max_pages : 65536U),
      has_max_(has_max) {
    size_t byte_len = static_cast<size_t>(initial_pages) * kWasmPageSizeBytes;
    header_ = static_cast<M3MemoryHeader*>(std::calloc(1, sizeof(M3MemoryHeader) + byte_len));
    if (header_) {
        header_->length = byte_len;
    }
}

Wasm3Memory::~Wasm3Memory() {
    if (header_) {
        std::free(header_);
        header_ = nullptr;
    }
}

uint8_t* Wasm3Memory::data() noexcept {
    return header_ ? reinterpret_cast<uint8_t*>(header_ + 1) : nullptr;
}

const uint8_t* Wasm3Memory::data() const noexcept {
    return header_ ? reinterpret_cast<const uint8_t*>(header_ + 1) : nullptr;
}

int32_t Wasm3Memory::Grow(uint32_t delta_pages) {
    uint32_t old_pages = num_pages_;
    if (delta_pages == 0) {
        return static_cast<int32_t>(old_pages);
    }
    uint64_t new_pages = static_cast<uint64_t>(old_pages) + static_cast<uint64_t>(delta_pages);
    uint32_t limit     = has_max_ ? std::min<uint32_t>(max_pages_, 65536U) : 65536U;
    if (new_pages > limit) {
        return -1;
    }

    size_t old_bytes = static_cast<size_t>(old_pages) * kWasmPageSizeBytes;
    size_t new_bytes = static_cast<size_t>(new_pages) * kWasmPageSizeBytes;
    auto* new_header = static_cast<M3MemoryHeader*>(
        std::realloc(header_, sizeof(M3MemoryHeader) + new_bytes));
    if (!new_header) {
        return -1;
    }
    std::memset(reinterpret_cast<uint8_t*>(new_header + 1) + old_bytes, 0, new_bytes - old_bytes);
    new_header->length = new_bytes;
    header_            = new_header;
    num_pages_         = static_cast<uint32_t>(new_pages);

    if (detach_cb_) {
        detach_cb_(data(), new_bytes);
    }
    return static_cast<int32_t>(old_pages);
}

Wasm3Table::Wasm3Table(M3ValueType element_type, uint32_t initial_size, uint32_t max_size, bool has_max)
    : element_type_(element_type),
      max_size_(has_max ? max_size : 10000000U),
      has_max_(has_max),
      elements_(initial_size, nullptr),
      raw_refs_(initial_size, MakeLepusNull()) {}

Wasm3Table::~Wasm3Table() = default;

bool Wasm3Table::Set(uint32_t index, std::shared_ptr<Wasm3Function> func, LEPUSValue raw_ref) {
    if (index >= elements_.size()) {
        return false;
    }
    elements_[index] = std::move(func);
    raw_refs_[index] = raw_ref;
    return true;
}

std::shared_ptr<Wasm3Function> Wasm3Table::GetFunction(uint32_t index, bool* out_bounds_ok) const {
    if (index >= elements_.size()) {
        if (out_bounds_ok) *out_bounds_ok = false;
        return nullptr;
    }
    if (out_bounds_ok) *out_bounds_ok = true;
    return elements_[index];
}

LEPUSValue Wasm3Table::GetRawRef(uint32_t index, bool* out_bounds_ok) const {
    if (index >= raw_refs_.size()) {
        if (out_bounds_ok) *out_bounds_ok = false;
        return MakeLepusUndefined();
    }
    if (out_bounds_ok) *out_bounds_ok = true;
    return raw_refs_[index];
}

int32_t Wasm3Table::Grow(uint32_t delta, std::shared_ptr<Wasm3Function> fill_func, LEPUSValue fill_ref) {
    uint32_t old_size = static_cast<uint32_t>(elements_.size());
    uint64_t new_size = static_cast<uint64_t>(old_size) + static_cast<uint64_t>(delta);
    if (has_max_ && new_size > max_size_) {
        return -1;
    }
    if (new_size > 10000000ULL) {
        return -1;
    }
    elements_.resize(static_cast<size_t>(new_size), fill_func);
    raw_refs_.resize(static_cast<size_t>(new_size), fill_ref);
    return static_cast<int32_t>(old_size);
}

Wasm3Global::Wasm3Global(M3ValueType type, bool is_mutable, int64_t initial_bits)
    : type_(type), is_mutable_(is_mutable) {
    val_.i64 = initial_bits;
}

bool Wasm3Global::SetI32(int32_t v) noexcept {
    if (!is_mutable_ || type_ != c_m3Type_i32) return false;
    val_.i64 = 0;
    val_.i32 = v;
    return true;
}

bool Wasm3Global::SetI64(int64_t v) noexcept {
    if (!is_mutable_ || type_ != c_m3Type_i64) return false;
    val_.i64 = v;
    return true;
}

bool Wasm3Global::SetF32(float v) noexcept {
    if (!is_mutable_ || type_ != c_m3Type_f32) return false;
    val_.i64 = 0;
    val_.f32 = v;
    return true;
}

bool Wasm3Global::SetF64(double v) noexcept {
    if (!is_mutable_ || type_ != c_m3Type_f64) return false;
    val_.f64 = v;
    return true;
}

bool Wasm3Global::SetRawBits(int64_t bits) noexcept {
    if (!is_mutable_) return false;
    val_.i64 = bits;
    return true;
}

Wasm3Function::Wasm3Function(Wasm3Module* parent_module, uint32_t func_index, M3Function* m3_func)
    : parent_module_(parent_module), func_index_(func_index), m3_func_(m3_func) {
    if (m3_func_) {
        if (m3_func_->numNames > 0 && m3_func_->names[0]) {
            name_ = m3_func_->names[0];
        } else {
            name_ = std::to_string(func_index);
        }
        if (m3_func_->funcType) {
            uint16_t nr = m3_func_->funcType->numRets;
            uint16_t na = m3_func_->funcType->numArgs;
            ret_types_.resize(nr);
            arg_types_.resize(na);
            for (uint16_t r = 0; r < nr; ++r) {
                ret_types_[r] = static_cast<M3ValueType>(m3_func_->funcType->types[r]);
            }
            for (uint16_t a = 0; a < na; ++a) {
                arg_types_[a] = static_cast<M3ValueType>(m3_func_->funcType->types[nr + a]);
            }
        }
    }
}

Wasm3Function::Wasm3Function(const std::string& name,
                             const std::vector<M3ValueType>& arg_types,
                             const std::vector<M3ValueType>& ret_types,
                             HostCallback host_cb)
    : parent_module_(nullptr),
      func_index_(0),
      m3_func_(nullptr),
      name_(name),
      arg_types_(arg_types),
      ret_types_(ret_types),
      host_cb_(std::move(host_cb)) {}

M3Result Wasm3Function::Call(const std::vector<WasmVal>& args, std::vector<WasmVal>* results) {
    if (args.size() != arg_types_.size()) {
        return m3_err::argumentCountMismatch;
    }
    if (host_cb_) {
        return host_cb_(args, results);
    }
    if (!parent_module_ || !m3_func_) {
        return m3_err::functionLookupFailed;
    }
    return ExecuteWasmFunctionBytecode(parent_module_, m3_func_, args, results);
}

// ============================================================================
// 5. Wasm3Module, Wasm3Runtime & InteropRuntime Implementation
//    Triển khai lớp Wasm3Module, Wasm3Runtime và InteropRuntime
// ============================================================================

Wasm3Module::Wasm3Module(std::shared_ptr<Wasm3Runtime> runtime,
                         M3Module* raw_module,
                         std::vector<uint8_t> wasm_bytes)
    : runtime_(std::move(runtime)),
      raw_module_(raw_module),
      wasm_bytes_(std::move(wasm_bytes)),
      is_loaded_(false) {
    if (raw_module_) {
        // Wrap all functions & globals parsed into M3Module
        functions_.resize(raw_module_->numFunctions);
        for (uint32_t i = 0; i < raw_module_->numFunctions; ++i) {
            functions_[i] = std::make_shared<Wasm3Function>(this, i, &raw_module_->functions[i]);
        }
        globals_.resize(raw_module_->numGlobals);
        for (uint32_t i = 0; i < raw_module_->numGlobals; ++i) {
            const M3Global& mg = raw_module_->globals[i];
            globals_[i] = std::make_shared<Wasm3Global>(
                static_cast<M3ValueType>(mg.type), mg.isMutable, mg.i64Value);
        }
        if (!raw_module_->memoryImported &&
            (raw_module_->memoryInfo.numPages > 0 || raw_module_->memoryInfo.hasMax)) {
            memory_ = std::make_shared<Wasm3Memory>(
                raw_module_->memoryInfo.numPages,
                raw_module_->memoryInfo.maxPages,
                raw_module_->memoryInfo.hasMax != 0);
        }
        if (!raw_module_->tableImported &&
            (raw_module_->table0Size > 0 || raw_module_->table0MaxSize > 0)) {
            table_ = std::make_shared<Wasm3Table>(
                c_m3Type_funcref,
                raw_module_->table0Size,
                raw_module_->table0MaxSize,
                raw_module_->table0MaxSize > 0);
        }
    }
}

Wasm3Module::~Wasm3Module() {
    if (raw_module_) {
        if (raw_module_->extraMetadata) {
            delete static_cast<M3ModuleExtraMetadata*>(raw_module_->extraMetadata);
            raw_module_->extraMetadata = nullptr;
        }
        m3_FreeModule(raw_module_);
        raw_module_ = nullptr;
    }
}

const std::vector<M3ExportInfo>& Wasm3Module::exports() const noexcept {
    static const std::vector<M3ExportInfo> kEmpty;
    if (!raw_module_ || !raw_module_->extraMetadata) {
        return kEmpty;
    }
    return static_cast<const M3ModuleExtraMetadata*>(raw_module_->extraMetadata)->exports;
}

const std::vector<M3ImportDescriptor>& Wasm3Module::imports() const noexcept {
    static const std::vector<M3ImportDescriptor> kEmpty;
    if (!raw_module_ || !raw_module_->extraMetadata) {
        return kEmpty;
    }
    return static_cast<const M3ModuleExtraMetadata*>(raw_module_->extraMetadata)->imports;
}

std::vector<M3CustomSection> Wasm3Module::custom_sections(const std::string& section_name) const {
    std::vector<M3CustomSection> matches;
    if (!raw_module_) {
        return matches;
    }
    for (M3CustomSection* cur = raw_module_->customSections; cur != nullptr; cur = cur->next) {
        if (cur->name && section_name == cur->name) {
            matches.push_back(*cur);
        }
    }
    return matches;
}

std::shared_ptr<Wasm3Function> Wasm3Module::GetFunction(uint32_t index) const {
    if (index >= functions_.size()) {
        return nullptr;
    }
    return functions_[index];
}

std::shared_ptr<Wasm3Global> Wasm3Module::GetGlobal(uint32_t index) const {
    if (index >= globals_.size()) {
        return nullptr;
    }
    return globals_[index];
}

bool Wasm3Module::BindImportFunction(uint32_t import_func_index, Wasm3Function::HostCallback cb) {
    if (import_func_index >= functions_.size() || !functions_[import_func_index]) {
        return false;
    }
    functions_[import_func_index]->SetHostCallback(std::move(cb));
    return true;
}

bool Wasm3Module::BindImportGlobal(uint32_t import_global_index, std::shared_ptr<Wasm3Global> global) {
    if (import_global_index >= globals_.size() || !global) {
        return false;
    }
    globals_[import_global_index] = std::move(global);
    if (raw_module_ && import_global_index < raw_module_->numGlobals) {
        raw_module_->globals[import_global_index].i64Value = globals_[import_global_index]->GetRawBits();
    }
    return true;
}

M3Result Wasm3Module::LoadAndInitialize() {
    if (!raw_module_ || !runtime_) {
        return m3_err::wasmMalformed;
    }
    if (!is_loaded_) {
        M3Result res = m3_LoadModule(runtime_->raw_runtime(), raw_module_);
        if (res && res != m3_err::moduleAlreadyLinked) {
            return res;
        }
        is_loaded_ = true;
    }

    // Bind default built-in host imports (`_abort`, `_exit`, `_memcpy`, `_memmove`, `_memset`, `printf`, `clock_ms`, `_debug`)
    // if any imported function has not been bound by JS yet.
    for (uint32_t i = 0; i < raw_module_->numFuncImports && i < functions_.size(); ++i) {
        auto& fn = functions_[i];
        if (fn && !fn->is_host() && raw_module_->functions[i].import.fieldUtf8) {
            const char* field = raw_module_->functions[i].import.fieldUtf8;
            if (std::strcmp(field, "_abort") == 0) {
                fn->SetHostCallback([this](const std::vector<WasmVal>& a, std::vector<WasmVal>* r) {
                    return HostImport_Abort(this, a, r);
                });
            } else if (std::strcmp(field, "_exit") == 0) {
                fn->SetHostCallback([this](const std::vector<WasmVal>& a, std::vector<WasmVal>* r) {
                    return HostImport_Exit(this, a, r);
                });
            } else if (std::strcmp(field, "_memcpy") == 0) {
                fn->SetHostCallback([this](const std::vector<WasmVal>& a, std::vector<WasmVal>* r) {
                    return HostImport_Memcpy(this, a, r);
                });
            } else if (std::strcmp(field, "_memmove") == 0) {
                fn->SetHostCallback([this](const std::vector<WasmVal>& a, std::vector<WasmVal>* r) {
                    return HostImport_Memmove(this, a, r);
                });
            } else if (std::strcmp(field, "_memset") == 0) {
                fn->SetHostCallback([this](const std::vector<WasmVal>& a, std::vector<WasmVal>* r) {
                    return HostImport_Memset(this, a, r);
                });
            } else if (std::strcmp(field, "printf") == 0) {
                fn->SetHostCallback([this](const std::vector<WasmVal>& a, std::vector<WasmVal>* r) {
                    return HostImport_Printf(this, a, r);
                });
            } else if (std::strcmp(field, "clock_ms") == 0) {
                fn->SetHostCallback([this](const std::vector<WasmVal>& a, std::vector<WasmVal>* r) {
                    return HostImport_ClockMs(this, a, r);
                });
            } else if (std::strcmp(field, "_debug") == 0) {
                fn->SetHostCallback([this](const std::vector<WasmVal>& a, std::vector<WasmVal>* r) {
                    return HostImport_Debug(this, a, r);
                });
            }
        }
    }

    // Re-evaluate non-imported globals that may depend on imported globals
    for (uint32_t i = 0; i < raw_module_->numGlobals; ++i) {
        M3Global& mg = raw_module_->globals[i];
        if (!mg.imported && mg.initExpr && mg.initExprSize > 0) {
            int64_t bits = 0;
            M3Result res = EvaluateInitExpr(raw_module_, mg.initExpr, mg.initExprSize,
                                            static_cast<M3ValueType>(mg.type), &bits);
            if (res) return res;
            mg.i64Value = bits;
            if (i < globals_.size() && globals_[i]) {
                globals_[i] = std::make_shared<Wasm3Global>(
                    static_cast<M3ValueType>(mg.type), mg.isMutable, bits);
            }
        }
    }

    // Initialize active data segments into linear memory
    for (uint32_t i = 0; i < raw_module_->numDataSegments; ++i) {
        const M3DataSegment& seg = raw_module_->dataSegments[i];
        if (seg.initExpr && seg.initExprSize > 0) {
            if (!memory_) {
                return m3_err::globalMemoryNotAllocated;
            }
            int64_t offset_bits = 0;
            M3Result res = EvaluateInitExpr(raw_module_, seg.initExpr, seg.initExprSize,
                                            c_m3Type_i32, &offset_bits);
            if (res) return res;
            uint32_t offset = static_cast<uint32_t>(static_cast<int32_t>(offset_bits));
            if (static_cast<uint64_t>(offset) + static_cast<uint64_t>(seg.size) > memory_->byte_length()) {
                return m3_err::trapOutOfBoundsMemoryAccess;
            }
            if (seg.size > 0 && seg.data) {
                std::memcpy(memory_->data() + offset, seg.data, seg.size);
            }
        }
    }

    // Initialize active element segments into table0
    if (raw_module_->numElementSegments > 0 && raw_module_->elementSection) {
        const uint8_t* ptr = raw_module_->elementSection;
        const uint8_t* end = raw_module_->elementSectionEnd;
        for (uint32_t s = 0; s < raw_module_->numElementSegments; ++s) {
            uint32_t flags = 0;
            M3Result res   = ReadLEB_u32(&flags, &ptr, end);
            if (res) return res;
            if (flags == 0) {
                const uint8_t* expr = nullptr;
                uint32_t expr_sz    = 0;
                res = ScanInitExpr(&ptr, end, &expr, &expr_sz);
                if (res) return res;
                int64_t offset_bits = 0;
                res = EvaluateInitExpr(raw_module_, expr, expr_sz, c_m3Type_i32, &offset_bits);
                if (res) return res;
                uint32_t offset = static_cast<uint32_t>(static_cast<int32_t>(offset_bits));

                uint32_t num_elems = 0;
                res = ReadLEB_u32(&num_elems, &ptr, end);
                if (res) return res;
                if (!table_ || static_cast<uint64_t>(offset) + num_elems > table_->length()) {
                    return m3_err::trapTableIndexOutOfRange;
                }
                for (uint32_t e = 0; e < num_elems; ++e) {
                    uint32_t fn_idx = 0;
                    res = ReadLEB_u32(&fn_idx, &ptr, end);
                    if (res) return res;
                    if (fn_idx >= functions_.size()) {
                        return m3_err::wasmMalformed;
                    }
                    table_->Set(offset + e, functions_[fn_idx]);
                    if (raw_module_->table0 && (offset + e) < raw_module_->table0Size) {
                        raw_module_->table0[offset + e] = &raw_module_->functions[fn_idx];
                    }
                }
            } else {
                // Skip non-active segment tail gracefully
                break;
            }
        }
    }

    // Run start function if present
    if (raw_module_->startFunction >= 0 &&
        static_cast<uint32_t>(raw_module_->startFunction) < functions_.size()) {
        std::vector<WasmVal> start_args;
        std::vector<WasmVal> start_rets;
        M3Result res = functions_[static_cast<uint32_t>(raw_module_->startFunction)]->Call(
            start_args, &start_rets);
        if (res) return res;
    }

    return m3_err::none;
}

Wasm3Runtime::Wasm3Runtime(uint32_t stack_size_bytes)
    : vtable_reserved_(nullptr),
      env_(m3_NewEnvironment()),
      runtime_(nullptr),
      flags_(0) {
    if (env_) {
        runtime_ = m3_NewRuntime(env_, stack_size_bytes, this);
    }
}

Wasm3Runtime::~Wasm3Runtime() {
    if (runtime_) {
        m3_FreeRuntime(runtime_);
        runtime_ = nullptr;
    }
    if (env_) {
        m3_FreeEnvironment(env_);
        env_ = nullptr;
    }
}

std::shared_ptr<Wasm3Module> Wasm3Runtime::ParseModule(const uint8_t* bytes,
                                                       size_t size,
                                                       M3Result* out_error) {
    if (!bytes || size < 8U) {
        if (out_error) *out_error = m3_err::wasmUnderrun;
        return nullptr;
    }
    std::vector<uint8_t> copy(bytes, bytes + size);
    M3Module* raw_mod = nullptr;
    M3Result err = m3_ParseModule(env_, &raw_mod, copy.data(), static_cast<uint32_t>(copy.size()));
    if (out_error) {
        *out_error = err;
    }
    if (err || !raw_mod) {
        if (raw_mod) {
            m3_FreeModule(raw_mod);
        }
        return nullptr;
    }
    return std::make_shared<Wasm3Module>(shared_from_this(), raw_mod, std::move(copy));
}

bool Wasm3Runtime::ValidateModule(const uint8_t* bytes, size_t size, M3Result* out_error) {
    auto mod = ParseModule(bytes, size, out_error);
    if (!mod) {
        return false;
    }
    M3Result comp_err = m3_CompileModule(mod->raw_module());
    if (out_error) {
        *out_error = comp_err;
    }
    return (comp_err == m3_err::none);
}

InteropRuntime::InteropRuntime(LEPUSContext* c, std::atomic<bool>* term, WasmRuntimeType type)
    : ctx(c),
      rt(nullptr),
      is_terminated(term),
      runtime_type(type),
      reserved_flags(0),
      wasm3_runtime(std::make_shared<Wasm3Runtime>()) {}

InteropRuntime::~InteropRuntime() = default;

} // namespace wasm
} // namespace vmsdk
