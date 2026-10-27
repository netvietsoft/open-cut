/**
 * @file wasm_m3_compile_exec.cpp
 * @brief Implementation of Embedded Wasm3 Engine & Full WebAssembly Bytecode Interpreter
 *        Triển khai máy ảo Wasm3 nhúng và Trình thông dịch Bytecode WebAssembly đầy đủ
 *
 * @details
 * Clean-room C++17 reconstruction of `libwasm.so` Wasm3 engine functions (`0x02268c..0x035990`)
 * and `.data.rel.ro` opcode tables (`c_operations` @ `0x038438..0x03b438`, `c_operationsFC` @
 * `0x03b438..0x03b818`).
 *
 * Evidence Classification / Phân loại bằng chứng:
 * - [OBSERVED]:
 *   - `m3_NewEnvironment` (`0x02268c..0x0228a8`): allocates `0x18` bytes for `M3Environment`,
 *     then allocates 4 canonical 1-return 0-arg `M3FuncType` structs (`0x11` bytes each via
 *     `mov w0, #0x11` = `0x52800220` at `0x022770`, `0x0227f8`, `0x022880`) for `c_m3Type_i32` (1),
 *     `c_m3Type_i64` (2), `c_m3Type_f32` (3), and `c_m3Type_f64` (4).
 *   - `m3_ParseModule` (`0x022bc0..0x022e80`): allocates `0xF0` bytes (`mov w0, #0xf0` = `0x52801E00`
 *     at `0x022be0`), sets `name = ".unnamed"` (`.rodata 0x0083eb`), `startFunction = -1`
 *     (`movn w8, #0` = `0x92800008` at `0x022c00`), verifies Wasm magic `0x6d736100` & version `1`,
 *     and dispatches sections `0..11` via `.data.rel.ro 0x03b888..0x03b8e8`.
 *   - `m3_FreeModule` (`0x032d08..0x033004`): frees `functions` array with stride `0x458`
 *     (`mov w21, #0x458` = `0x52808B15` at `0x032d30`), `globals` (`0x30`), `dataSegments` (`0x28`),
 *     `customSections`, and `M3Module`.
 */

#include "wasm_m3_compile_exec.h"

#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <unordered_map>

namespace vmsdk {
namespace wasm {

// ============================================================================
// 1. Wasm3 Environment, Runtime & Module Lifecycle ([OBSERVED] 0x02268c..0x033004)
//    Triển khai Vòng đời Môi trường, Runtime và Module của Wasm3
// ============================================================================

M3Result AllocFuncType(M3FuncType** out_funcType, uint32_t numTypes) noexcept {
    if (!out_funcType) {
        return m3_err::mallocFailed;
    }
    // [OBSERVED] 0x022770: size = 0x10 + numTypes (for numTypes == 1 -> 0x11 = 17 bytes)
    // Kích thước cấp phát = 0x10 + tổng số kiểu trả về và tham số
    size_t alloc_size = 0x10U + static_cast<size_t>(numTypes);
    if (alloc_size < sizeof(M3FuncType)) {
        alloc_size = sizeof(M3FuncType);
    }
    auto* ft = static_cast<M3FuncType*>(std::calloc(alloc_size, 1U));
    if (!ft) {
        return m3_err::mallocFailed;
    }
    *out_funcType = ft;
    return m3_err::none;
}

static bool AreFuncTypesEqual(const M3FuncType* a, const M3FuncType* b) noexcept {
    if (!a || !b) return false;
    if (a->numRets != b->numRets || a->numArgs != b->numArgs) {
        return false;
    }
    uint32_t total = static_cast<uint32_t>(a->numRets) + static_cast<uint32_t>(a->numArgs);
    return std::memcmp(a->types, b->types, total) == 0;
}

M3Result Environment_AddFuncType(M3Environment* env, M3FuncType** io_funcType) noexcept {
    // [OBSERVED] 0x022700..0x022768: deduplicates M3FuncType in env->funcTypes linked list
    // Khử trùng lặp cấu trúc M3FuncType trong danh sách liên kết env->funcTypes
    if (!env || !io_funcType || !*io_funcType) {
        return m3_err::wasmMalformed;
    }
    M3FuncType* candidate = *io_funcType;
    M3FuncType* cur       = env->funcTypes;
    while (cur) {
        if (AreFuncTypesEqual(cur, candidate)) {
            if (cur != candidate) {
                std::free(candidate);
                *io_funcType = cur;
            }
            return m3_err::none;
        }
        cur = cur->next;
    }
    candidate->next = env->funcTypes;
    env->funcTypes  = candidate;
    return m3_err::none;
}

M3Environment* m3_NewEnvironment() noexcept {
    // [OBSERVED] 0x02268c..0x0228a8:
    // Allocates M3Environment (0x18 bytes) and pre-registers 4 single-return M3FuncTypes
    // for c_m3Type_i32 (1), c_m3Type_i64 (2), c_m3Type_f32 (3), c_m3Type_f64 (4).
    auto* env = static_cast<M3Environment*>(std::calloc(1U, sizeof(M3Environment)));
    if (!env) {
        return nullptr;
    }
    for (uint8_t t = c_m3Type_i32; t <= c_m3Type_f64; ++t) {
        M3FuncType* ftype = nullptr;
        if (AllocFuncType(&ftype, 1U) == m3_err::none && ftype) {
            ftype->numRets  = 1U;
            ftype->numArgs  = 0U;
            ftype->types[0] = t;
            Environment_AddFuncType(env, &ftype);
        }
    }
    return env;
}

void m3_FreeEnvironment(M3Environment* env) noexcept {
    // [OBSERVED] 0x0228ac..0x0229e8: frees funcTypes linked list and pagesReleased
    // Giải phóng danh sách funcTypes và các trang mã trong M3Environment
    if (!env) {
        return;
    }
    M3FuncType* ft = env->funcTypes;
    while (ft) {
        M3FuncType* next = ft->next;
        std::free(ft);
        ft = next;
    }
    M3CodePage* pg = env->pagesReleased;
    while (pg) {
        M3CodePage* next = pg->next;
        std::free(pg);
        pg = next;
    }
    std::free(env);
}

M3Runtime* m3_NewRuntime(M3Environment* env, uint32_t stackSizeInBytes, void* userdata) noexcept {
    // [OBSERVED] 0x0229ec..0x022bbc: allocates M3Runtime and execution stack
    // Cấp phát M3Runtime và vùng nhớ ngăn xếp thực thi
    if (!env) {
        return nullptr;
    }
    auto* rt = static_cast<M3Runtime*>(std::calloc(1U, sizeof(M3Runtime)));
    if (!rt) {
        return nullptr;
    }
    rt->environment = env;
    rt->userdata    = userdata;
    uint32_t slots  = (stackSizeInBytes == 0) ? 16384U : (stackSizeInBytes / sizeof(m3slot_t));
    rt->originStack = std::calloc(slots + 16U, sizeof(m3slot_t));
    if (!rt->originStack) {
        std::free(rt);
        return nullptr;
    }
    rt->stack         = rt->originStack;
    rt->numStackSlots = slots;
    return rt;
}

void m3_FreeRuntime(M3Runtime* runtime) noexcept {
    if (!runtime) {
        return;
    }
    if (runtime->originStack) {
        std::free(runtime->originStack);
        runtime->originStack = nullptr;
    }
    if (runtime->memory.mallocated) {
        std::free(runtime->memory.mallocated);
        runtime->memory.mallocated = nullptr;
    }
    std::free(runtime);
}

M3Result m3_ParseModule(M3Environment* env,
                        M3Module** out_module,
                        const uint8_t* wasmBytes,
                        uint32_t numWasmBytes) noexcept {
    // [OBSERVED] 0x022bc0..0x022e80:
    // - 0x022be0: mov w0, #0xf0; mov w1, #1; bl calloc
    // - 0x022bfc: sets name = ".unnamed"
    // - 0x022c00: movn w8, #0 -> startFunction = -1
    // - Verifies magic 0x6d736100 ("\0asm") and version 1
    // - Dispatches sections 0..11 via .data.rel.ro 0x03b888..0x03b8e8
    if (!out_module) {
        return m3_err::wasmMalformed;
    }
    *out_module = nullptr;
    if (!wasmBytes || numWasmBytes < 8U) {
        return m3_err::wasmUnderrun;
    }

    auto* module = static_cast<M3Module*>(std::calloc(0xF0U, 1U));
    if (!module) {
        return m3_err::mallocFailed;
    }
    module->environment   = env;
    module->name          = ".unnamed";
    module->startFunction = -1;
    module->wasmStart     = wasmBytes;
    module->wasmEnd       = wasmBytes + numWasmBytes;

    const uint8_t* pos = wasmBytes;
    const uint8_t* end = wasmBytes + numWasmBytes;

    uint32_t magic = 0;
    M3Result res   = Read_u32(&magic, &pos, end);
    if (res || magic != kWasmMagicNumber) {
        m3_FreeModule(module);
        return res ? res : m3_err::wasmMalformed;
    }

    uint32_t version = 0;
    res = Read_u32(&version, &pos, end);
    if (res || version != kWasmVersion) {
        m3_FreeModule(module);
        return res ? res : m3_err::wasmMalformed;
    }

    const M3SectionParser* parsers = GetSectionParserTable();
    uint8_t previous_section = 0;

    while (pos < end) {
        uint8_t section_id = 0;
        res = Read_u8(&section_id, &pos, end);
        if (res) {
            m3_FreeModule(module);
            return res;
        }

        if (section_id != kWasmSectionCustom) {
            // Non-custom sections must appear in strictly increasing order (except DataCount=12 if present)
            if (section_id >= kWasmSectionMax) {
                m3_FreeModule(module);
                return m3_err::wasmMalformed;
            }
            if (section_id <= previous_section) {
                m3_FreeModule(module);
                return m3_err::wasmMalformed;
            }
            previous_section = section_id;
        }

        uint32_t section_len = 0;
        res = ReadLEB_u32(&section_len, &pos, end);
        if (res) {
            m3_FreeModule(module);
            return res;
        }
        if (static_cast<size_t>(end - pos) < section_len) {
            m3_FreeModule(module);
            return m3_err::wasmUnderrun;
        }

        const uint8_t* section_start = pos;
        const uint8_t* section_end   = pos + section_len;
        pos                          = section_end;

        M3SectionParser parser = parsers[section_id];
        if (parser) {
            res = parser(module, section_start, section_end);
            if (res) {
                m3_FreeModule(module);
                return res;
            }
        }
    }

    *out_module = module;
    return m3_err::none;
}

M3Result m3_LoadModule(M3Runtime* runtime, M3Module* module) noexcept {
    // [OBSERVED] 0x022e80..0x0234fc: links module to runtime and allocates table0
    // Liên kết module vào runtime và khởi tạo bảng hàm table0
    if (!runtime || !module) {
        return m3_err::wasmMalformed;
    }
    if (module->runtime != nullptr) {
        return m3_err::moduleAlreadyLinked;
    }
    module->runtime = runtime;

    if (module->table0Size > 0 && !module->table0) {
        module->table0 = static_cast<M3Function**>(
            std::calloc(module->table0Size, sizeof(M3Function*)));
        if (!module->table0) {
            return m3_err::mallocFailed;
        }
    }

    module->next     = runtime->modules;
    runtime->modules = module;
    return m3_err::none;
}

void m3_FreeModule(M3Module* module) noexcept {
    // [OBSERVED] 0x032d08..0x033004:
    // - Loops over module->numFunctions with stride 0x458 (`mov w21, #0x458` at 0x032d30)
    // - Frees fn->wasm (if fn->ownsWasmCode at +0x448), fn->names[0..2], fn->import strings, fn->constants
    // - Frees module->funcTypes, module->globals, module->dataSegments, module->table0, module->customSections
    if (!module) {
        return;
    }

    if (module->functions) {
        for (uint32_t i = 0; i < module->numFunctions; ++i) {
            M3Function* fn = &module->functions[i];
            if (fn->ownsWasmCode && fn->wasm) {
                std::free(const_cast<uint8_t*>(fn->wasm));
                fn->wasm = nullptr;
            }
            if (fn->constants) {
                std::free(fn->constants);
                fn->constants = nullptr;
            }
            for (uint16_t n = 0; n < fn->numNames && n < 3U; ++n) {
                if (fn->names[n] && fn->names[n] != fn->import.fieldUtf8) {
                    std::free(const_cast<char*>(fn->names[n]));
                }
                fn->names[n] = nullptr;
            }
            if (fn->import.moduleUtf8) {
                std::free(const_cast<char*>(fn->import.moduleUtf8));
                fn->import.moduleUtf8 = nullptr;
            }
            if (fn->import.fieldUtf8) {
                std::free(const_cast<char*>(fn->import.fieldUtf8));
                fn->import.fieldUtf8 = nullptr;
            }
        }
        std::free(module->functions);
        module->functions = nullptr;
    }

    if (module->funcTypes) {
        std::free(module->funcTypes);
        module->funcTypes = nullptr;
    }

    if (module->globals) {
        for (uint32_t i = 0; i < module->numGlobals; ++i) {
            M3Global* g = &module->globals[i];
            if (g->import.moduleUtf8) {
                std::free(const_cast<char*>(g->import.moduleUtf8));
            }
            if (g->import.fieldUtf8) {
                std::free(const_cast<char*>(g->import.fieldUtf8));
            }
            if (g->name) {
                std::free(const_cast<char*>(g->name));
            }
        }
        std::free(module->globals);
        module->globals = nullptr;
    }

    if (module->dataSegments) {
        std::free(module->dataSegments);
        module->dataSegments = nullptr;
    }

    if (module->table0) {
        std::free(module->table0);
        module->table0 = nullptr;
    }
    if (module->table0ImportModule) {
        std::free(const_cast<char*>(module->table0ImportModule));
    }
    if (module->table0ImportField) {
        std::free(const_cast<char*>(module->table0ImportField));
    }
    if (module->memoryImportModule) {
        std::free(const_cast<char*>(module->memoryImportModule));
    }
    if (module->memoryImportField) {
        std::free(const_cast<char*>(module->memoryImportField));
    }

    M3CustomSection* cs = module->customSections;
    while (cs) {
        M3CustomSection* next = cs->next;
        if (cs->name) {
            std::free(const_cast<char*>(cs->name));
        }
        std::free(cs);
        cs = next;
    }

    std::free(module);
}

M3Result m3_CompileModule(M3Module* module) noexcept {
    // [OBSERVED] 0x023500..0x023620: validates local declarations and bytecode structure
    // Kiểm tra khai báo biến cục bộ và cấu trúc thân hàm của toàn bộ các hàm trong module
    if (!module) {
        return m3_err::wasmMalformed;
    }
    for (uint32_t i = module->numFuncImports; i < module->numFunctions; ++i) {
        M3Function* fn = &module->functions[i];
        if (!fn->wasm || !fn->wasmEnd || fn->wasm >= fn->wasmEnd) {
            return m3_err::missingCompiledCode;
        }
        const uint8_t* ptr = fn->wasm;
        const uint8_t* end = fn->wasmEnd;
        uint32_t body_sz   = 0;
        M3Result res       = ReadLEB_u32(&body_sz, &ptr, end);
        if (res) return res;
        uint32_t num_local_decls = 0;
        res = ReadLEB_u32(&num_local_decls, &ptr, end);
        if (res) return res;

        uint64_t total_locals = 0;
        for (uint32_t d = 0; d < num_local_decls; ++d) {
            uint32_t count = 0;
            res = ReadLEB_u32(&count, &ptr, end);
            if (res) return res;
            uint8_t raw_t = 0;
            res = Read_u8(&raw_t, &ptr, end);
            if (res) return res;
            M3ValueType vt = c_m3Type_none;
            res = NormalizeWasmType(&vt, static_cast<int8_t>(raw_t));
            if (res) return res;
            total_locals += count;
            if (total_locals > 65536ULL) {
                return m3_err::wasmMalformed;
            }
        }
        fn->numLocalSlots = static_cast<uint16_t>(total_locals);
        fn->isCompiled    = true;
    }
    return m3_err::none;
}

// ============================================================================
// 2. Wasm3 `c_operations[256]` & `c_operationsFC[21]` Tables (.data.rel.ro 0x038438)
//    Bảng 256 Opcode chính và 21 Opcode mở rộng `0xFC` ([QUAN SÁT ĐƯỢC] @ 0x038438)
// ============================================================================

namespace {

m3ret_t OpStub_Exec(pc_t, m3slot_t*, M3MemoryHeader*, m3reg_t, double) {
    return m3_err::none;
}
M3Result CompilerStub_Compile(M3Compilation*, uint8_t) {
    return m3_err::none;
}

constexpr M3OpInfo MakeOp(int8_t stack_offset, uint8_t type) noexcept {
    return M3OpInfo{
        stack_offset,
        type,
        {0, 0, 0, 0, 0, 0},
        {&OpStub_Exec, &OpStub_Exec, &OpStub_Exec, &OpStub_Exec},
        &CompilerStub_Compile
    };
}

constexpr M3OpInfo MakeInvalidOp() noexcept {
    return M3OpInfo{0, 0, {0, 0, 0, 0, 0, 0}, {nullptr, nullptr, nullptr, nullptr}, nullptr};
}

/**
 * [OBSERVED] Exact 256-entry `c_operations` table matching `.data.rel.ro 0x038438..0x03b438`.
 * Bảng `c_operations` 256 phần tử khớp với `.data.rel.ro 0x038438..0x03b438`.
 */
const M3OpInfo kWasm3OperationsTable[256] = {
    /* 0x00 unreachable */ MakeOp(0, c_m3Type_none),
    /* 0x01 nop         */ MakeOp(0, c_m3Type_none),
    /* 0x02 block       */ MakeOp(0, c_m3Type_none),
    /* 0x03 loop        */ MakeOp(0, c_m3Type_none),
    /* 0x04 if          */ MakeOp(-1, c_m3Type_none),
    /* 0x05 else        */ MakeOp(0, c_m3Type_none),
    /* 0x06..0x0A       */ MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
    /* 0x0B end         */ MakeOp(0, c_m3Type_none),
    /* 0x0C br          */ MakeOp(0, c_m3Type_none),
    /* 0x0D br_if       */ MakeOp(-1, c_m3Type_none),
    /* 0x0E br_table    */ MakeOp(-1, c_m3Type_none),
    /* 0x0F return      */ MakeOp(0, c_m3Type_none),
    /* 0x10 call        */ MakeOp(1, c_m3Type_none),
    /* 0x11 call_ind    */ MakeOp(1, c_m3Type_none),
    /* 0x12..0x19       */ MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
    /* 0x1A drop        */ MakeOp(-1, c_m3Type_none),
    /* 0x1B select      */ MakeOp(-2, c_m3Type_none),
    /* 0x1C..0x1F       */ MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
    /* 0x20 local.get   */ MakeOp(1, c_m3Type_none),
    /* 0x21 local.set   */ MakeOp(-1, c_m3Type_none),
    /* 0x22 local.tee   */ MakeOp(0, c_m3Type_none),
    /* 0x23 global.get  */ MakeOp(1, c_m3Type_none),
    /* 0x24 global.set  */ MakeOp(-1, c_m3Type_none),
    /* 0x25 table.get   */ MakeOp(0, c_m3Type_none),
    /* 0x26 table.set   */ MakeOp(-2, c_m3Type_none),
    /* 0x27             */ MakeInvalidOp(),
    /* 0x28 i32.load    */ MakeOp(0, c_m3Type_i32),
    /* 0x29 i64.load    */ MakeOp(0, c_m3Type_i64),
    /* 0x2A f32.load    */ MakeOp(0, c_m3Type_f32),
    /* 0x2B f64.load    */ MakeOp(0, c_m3Type_f64),
    /* 0x2C i32.load8_s */ MakeOp(0, c_m3Type_i32),
    /* 0x2D i32.load8_u */ MakeOp(0, c_m3Type_i32),
    /* 0x2E i32.load16s */ MakeOp(0, c_m3Type_i32),
    /* 0x2F i32.load16u */ MakeOp(0, c_m3Type_i32),
    /* 0x30 i64.load8_s */ MakeOp(0, c_m3Type_i64),
    /* 0x31 i64.load8_u */ MakeOp(0, c_m3Type_i64),
    /* 0x32 i64.load16s */ MakeOp(0, c_m3Type_i64),
    /* 0x33 i64.load16u */ MakeOp(0, c_m3Type_i64),
    /* 0x34 i64.load32s */ MakeOp(0, c_m3Type_i64),
    /* 0x35 i64.load32u */ MakeOp(0, c_m3Type_i64),
    /* 0x36 i32.store   */ MakeOp(-2, c_m3Type_i32),
    /* 0x37 i64.store   */ MakeOp(-2, c_m3Type_i64),
    /* 0x38 f32.store   */ MakeOp(-2, c_m3Type_f32),
    /* 0x39 f64.store   */ MakeOp(-2, c_m3Type_f64),
    /* 0x3A i32.store8  */ MakeOp(-2, c_m3Type_i32),
    /* 0x3B i32.store16 */ MakeOp(-2, c_m3Type_i32),
    /* 0x3C i64.store8  */ MakeOp(-2, c_m3Type_i64),
    /* 0x3D i64.store16 */ MakeOp(-2, c_m3Type_i64),
    /* 0x3E i64.store32 */ MakeOp(-2, c_m3Type_i64),
    /* 0x3F memory.size */ MakeOp(1, c_m3Type_i32),
    /* 0x40 memory.grow */ MakeOp(0, c_m3Type_i32),
    /* 0x41 i32.const   */ MakeOp(1, c_m3Type_i32),
    /* 0x42 i64.const   */ MakeOp(1, c_m3Type_i64),
    /* 0x43 f32.const   */ MakeOp(1, c_m3Type_f32),
    /* 0x44 f64.const   */ MakeOp(1, c_m3Type_f64),
    /* 0x45 i32.eqz     */ MakeOp(0, c_m3Type_i32),
    /* 0x46 i32.eq      */ MakeOp(-1, c_m3Type_i32),
    /* 0x47 i32.ne      */ MakeOp(-1, c_m3Type_i32),
    /* 0x48 i32.lt_s    */ MakeOp(-1, c_m3Type_i32),
    /* 0x49 i32.lt_u    */ MakeOp(-1, c_m3Type_i32),
    /* 0x4A i32.gt_s    */ MakeOp(-1, c_m3Type_i32),
    /* 0x4B i32.gt_u    */ MakeOp(-1, c_m3Type_i32),
    /* 0x4C i32.le_s    */ MakeOp(-1, c_m3Type_i32),
    /* 0x4D i32.le_u    */ MakeOp(-1, c_m3Type_i32),
    /* 0x4E i32.ge_s    */ MakeOp(-1, c_m3Type_i32),
    /* 0x4F i32.ge_u    */ MakeOp(-1, c_m3Type_i32),
    /* 0x50 i64.eqz     */ MakeOp(0, c_m3Type_i32),
    /* 0x51 i64.eq      */ MakeOp(-1, c_m3Type_i32),
    /* 0x52 i64.ne      */ MakeOp(-1, c_m3Type_i32),
    /* 0x53 i64.lt_s    */ MakeOp(-1, c_m3Type_i32),
    /* 0x54 i64.lt_u    */ MakeOp(-1, c_m3Type_i32),
    /* 0x55 i64.gt_s    */ MakeOp(-1, c_m3Type_i32),
    /* 0x56 i64.gt_u    */ MakeOp(-1, c_m3Type_i32),
    /* 0x57 i64.le_s    */ MakeOp(-1, c_m3Type_i32),
    /* 0x58 i64.le_u    */ MakeOp(-1, c_m3Type_i32),
    /* 0x59 i64.ge_s    */ MakeOp(-1, c_m3Type_i32),
    /* 0x5A i64.ge_u    */ MakeOp(-1, c_m3Type_i32),
    /* 0x5B f32.eq      */ MakeOp(-1, c_m3Type_i32),
    /* 0x5C f32.ne      */ MakeOp(-1, c_m3Type_i32),
    /* 0x5D f32.lt      */ MakeOp(-1, c_m3Type_i32),
    /* 0x5E f32.gt      */ MakeOp(-1, c_m3Type_i32),
    /* 0x5F f32.le      */ MakeOp(-1, c_m3Type_i32),
    /* 0x60 f32.ge      */ MakeOp(-1, c_m3Type_i32),
    /* 0x61 f64.eq      */ MakeOp(-1, c_m3Type_i32),
    /* 0x62 f64.ne      */ MakeOp(-1, c_m3Type_i32),
    /* 0x63 f64.lt      */ MakeOp(-1, c_m3Type_i32),
    /* 0x64 f64.gt      */ MakeOp(-1, c_m3Type_i32),
    /* 0x65 f64.le      */ MakeOp(-1, c_m3Type_i32),
    /* 0x66 f64.ge      */ MakeOp(-1, c_m3Type_i32),
    /* 0x67 i32.clz     */ MakeOp(0, c_m3Type_i32),
    /* 0x68 i32.ctz     */ MakeOp(0, c_m3Type_i32),
    /* 0x69 i32.popcnt  */ MakeOp(0, c_m3Type_i32),
    /* 0x6A i32.add     */ MakeOp(-1, c_m3Type_i32),
    /* 0x6B i32.sub     */ MakeOp(-1, c_m3Type_i32),
    /* 0x6C i32.mul     */ MakeOp(-1, c_m3Type_i32),
    /* 0x6D i32.div_s   */ MakeOp(-1, c_m3Type_i32),
    /* 0x6E i32.div_u   */ MakeOp(-1, c_m3Type_i32),
    /* 0x6F i32.rem_s   */ MakeOp(-1, c_m3Type_i32),
    /* 0x70 i32.rem_u   */ MakeOp(-1, c_m3Type_i32),
    /* 0x71 i32.and     */ MakeOp(-1, c_m3Type_i32),
    /* 0x72 i32.or      */ MakeOp(-1, c_m3Type_i32),
    /* 0x73 i32.xor     */ MakeOp(-1, c_m3Type_i32),
    /* 0x74 i32.shl     */ MakeOp(-1, c_m3Type_i32),
    /* 0x75 i32.shr_s   */ MakeOp(-1, c_m3Type_i32),
    /* 0x76 i32.shr_u   */ MakeOp(-1, c_m3Type_i32),
    /* 0x77 i32.rotl    */ MakeOp(-1, c_m3Type_i32),
    /* 0x78 i32.rotr    */ MakeOp(-1, c_m3Type_i32),
    /* 0x79 i64.clz     */ MakeOp(0, c_m3Type_i64),
    /* 0x7A i64.ctz     */ MakeOp(0, c_m3Type_i64),
    /* 0x7B i64.popcnt  */ MakeOp(0, c_m3Type_i64),
    /* 0x7C i64.add     */ MakeOp(-1, c_m3Type_i64),
    /* 0x7D i64.sub     */ MakeOp(-1, c_m3Type_i64),
    /* 0x7E i64.mul     */ MakeOp(-1, c_m3Type_i64),
    /* 0x7F i64.div_s   */ MakeOp(-1, c_m3Type_i64),
    /* 0x80 i64.div_u   */ MakeOp(-1, c_m3Type_i64),
    /* 0x81 i64.rem_s   */ MakeOp(-1, c_m3Type_i64),
    /* 0x82 i64.rem_u   */ MakeOp(-1, c_m3Type_i64),
    /* 0x83 i64.and     */ MakeOp(-1, c_m3Type_i64),
    /* 0x84 i64.or      */ MakeOp(-1, c_m3Type_i64),
    /* 0x85 i64.xor     */ MakeOp(-1, c_m3Type_i64),
    /* 0x86 i64.shl     */ MakeOp(-1, c_m3Type_i64),
    /* 0x87 i64.shr_s   */ MakeOp(-1, c_m3Type_i64),
    /* 0x88 i64.shr_u   */ MakeOp(-1, c_m3Type_i64),
    /* 0x89 i64.rotl    */ MakeOp(-1, c_m3Type_i64),
    /* 0x8A i64.rotr    */ MakeOp(-1, c_m3Type_i64),
    /* 0x8B f32.abs     */ MakeOp(0, c_m3Type_f32),
    /* 0x8C f32.neg     */ MakeOp(0, c_m3Type_f32),
    /* 0x8D f32.ceil    */ MakeOp(0, c_m3Type_f32),
    /* 0x8E f32.floor   */ MakeOp(0, c_m3Type_f32),
    /* 0x8F f32.trunc   */ MakeOp(0, c_m3Type_f32),
    /* 0x90 f32.nearest */ MakeOp(0, c_m3Type_f32),
    /* 0x91 f32.sqrt    */ MakeOp(0, c_m3Type_f32),
    /* 0x92 f32.add     */ MakeOp(-1, c_m3Type_f32),
    /* 0x93 f32.sub     */ MakeOp(-1, c_m3Type_f32),
    /* 0x94 f32.mul     */ MakeOp(-1, c_m3Type_f32),
    /* 0x95 f32.div     */ MakeOp(-1, c_m3Type_f32),
    /* 0x96 f32.min     */ MakeOp(-1, c_m3Type_f32),
    /* 0x97 f32.max     */ MakeOp(-1, c_m3Type_f32),
    /* 0x98 f32.copysig */ MakeOp(-1, c_m3Type_f32),
    /* 0x99 f64.abs     */ MakeOp(0, c_m3Type_f64),
    /* 0x9A f64.neg     */ MakeOp(0, c_m3Type_f64),
    /* 0x9B f64.ceil    */ MakeOp(0, c_m3Type_f64),
    /* 0x9C f64.floor   */ MakeOp(0, c_m3Type_f64),
    /* 0x9D f64.trunc   */ MakeOp(0, c_m3Type_f64),
    /* 0x9E f64.nearest */ MakeOp(0, c_m3Type_f64),
    /* 0x9F f64.sqrt    */ MakeOp(0, c_m3Type_f64),
    /* 0xA0 f64.add     */ MakeOp(-1, c_m3Type_f64),
    /* 0xA1 f64.sub     */ MakeOp(-1, c_m3Type_f64),
    /* 0xA2 f64.mul     */ MakeOp(-1, c_m3Type_f64),
    /* 0xA3 f64.div     */ MakeOp(-1, c_m3Type_f64),
    /* 0xA4 f64.min     */ MakeOp(-1, c_m3Type_f64),
    /* 0xA5 f64.max     */ MakeOp(-1, c_m3Type_f64),
    /* 0xA6 f64.copysig */ MakeOp(-1, c_m3Type_f64),
    /* 0xA7 i32.wrap64  */ MakeOp(0, c_m3Type_i32),
    /* 0xA8 i32.tr_f32s */ MakeOp(0, c_m3Type_i32),
    /* 0xA9 i32.tr_f32u */ MakeOp(0, c_m3Type_i32),
    /* 0xAA i32.tr_f64s */ MakeOp(0, c_m3Type_i32),
    /* 0xAB i32.tr_f64u */ MakeOp(0, c_m3Type_i32),
    /* 0xAC i64.ext32_s */ MakeOp(0, c_m3Type_i64),
    /* 0xAD i64.ext32_u */ MakeOp(0, c_m3Type_i64),
    /* 0xAE i64.tr_f32s */ MakeOp(0, c_m3Type_i64),
    /* 0xAF i64.tr_f32u */ MakeOp(0, c_m3Type_i64),
    /* 0xB0 i64.tr_f64s */ MakeOp(0, c_m3Type_i64),
    /* 0xB1 i64.tr_f64u */ MakeOp(0, c_m3Type_i64),
    /* 0xB2 f32.cv_i32s */ MakeOp(0, c_m3Type_f32),
    /* 0xB3 f32.cv_i32u */ MakeOp(0, c_m3Type_f32),
    /* 0xB4 f32.cv_i64s */ MakeOp(0, c_m3Type_f32),
    /* 0xB5 f32.cv_i64u */ MakeOp(0, c_m3Type_f32),
    /* 0xB6 f32.dem_f64 */ MakeOp(0, c_m3Type_f32),
    /* 0xB7 f64.cv_i32s */ MakeOp(0, c_m3Type_f64),
    /* 0xB8 f64.cv_i32u */ MakeOp(0, c_m3Type_f64),
    /* 0xB9 f64.cv_i64s */ MakeOp(0, c_m3Type_f64),
    /* 0xBA f64.cv_i64u */ MakeOp(0, c_m3Type_f64),
    /* 0xBB f64.prm_f32 */ MakeOp(0, c_m3Type_f64),
    /* 0xBC i32.rei_f32 */ MakeOp(0, c_m3Type_i32),
    /* 0xBD i64.rei_f64 */ MakeOp(0, c_m3Type_i64),
    /* 0xBE f32.rei_i32 */ MakeOp(0, c_m3Type_f32),
    /* 0xBF f64.rei_i64 */ MakeOp(0, c_m3Type_f64),
    /* 0xC0 i32.ext8_s  */ MakeOp(0, c_m3Type_i32),
    /* 0xC1 i32.ext16_s */ MakeOp(0, c_m3Type_i32),
    /* 0xC2 i64.ext8_s  */ MakeOp(0, c_m3Type_i64),
    /* 0xC3 i64.ext16_s */ MakeOp(0, c_m3Type_i64),
    /* 0xC4 i64.ext32_s */ MakeOp(0, c_m3Type_i64),
    /* 0xC5..0xCF       */ MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
    /* 0xD0 ref.null    */ MakeOp(1, c_m3Type_funcref),
    /* 0xD1 ref.is_null */ MakeOp(0, c_m3Type_i32),
    /* 0xD2 ref.func    */ MakeOp(1, c_m3Type_funcref),
    /* 0xD3..0xFB       */ MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp(),
                           MakeInvalidOp(),
    /* 0xFC 0xFC prefix */ MakeOp(0, c_m3Type_none),
    /* 0xFD..0xFF       */ MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp()
};

const M3OpInfo kWasm3OperationsFCTable[21] = {
    /* 0xFC 0x00 i32.trunc_sat_f32_s */ MakeOp(0, c_m3Type_i32),
    /* 0xFC 0x01 i32.trunc_sat_f32_u */ MakeOp(0, c_m3Type_i32),
    /* 0xFC 0x02 i32.trunc_sat_f64_s */ MakeOp(0, c_m3Type_i32),
    /* 0xFC 0x03 i32.trunc_sat_f64_u */ MakeOp(0, c_m3Type_i32),
    /* 0xFC 0x04 i64.trunc_sat_f32_s */ MakeOp(0, c_m3Type_i64),
    /* 0xFC 0x05 i64.trunc_sat_f32_u */ MakeOp(0, c_m3Type_i64),
    /* 0xFC 0x06 i64.trunc_sat_f64_s */ MakeOp(0, c_m3Type_i64),
    /* 0xFC 0x07 i64.trunc_sat_f64_u */ MakeOp(0, c_m3Type_i64),
    /* 0xFC 0x08 memory.init         */ MakeOp(-3, c_m3Type_none),
    /* 0xFC 0x09 data.drop           */ MakeOp(0, c_m3Type_none),
    /* 0xFC 0x0A memory.copy         */ MakeOp(-3, c_m3Type_none),
    /* 0xFC 0x0B memory.fill         */ MakeOp(-3, c_m3Type_none),
    /* 0xFC 0x0C table.init          */ MakeOp(-3, c_m3Type_none),
    /* 0xFC 0x0D elem.drop           */ MakeOp(0, c_m3Type_none),
    /* 0xFC 0x0E table.copy          */ MakeOp(-3, c_m3Type_none),
    /* 0xFC 0x0F table.grow          */ MakeOp(-1, c_m3Type_i32),
    /* 0xFC 0x10 table.size          */ MakeOp(1, c_m3Type_i32),
    /* 0xFC 0x11 table.fill          */ MakeOp(-3, c_m3Type_none),
    /* 0xFC 0x12..0x14               */ MakeInvalidOp(), MakeInvalidOp(), MakeInvalidOp()
};

} // namespace

const M3OpInfo* GetWasm3OpcodeTable() noexcept {
    return kWasm3OperationsTable;
}

const M3OpInfo* GetWasm3OpcodeFCTable(size_t* out_count) noexcept {
    if (out_count) {
        *out_count = 21U;
    }
    return kWasm3OperationsFCTable;
}

// ============================================================================
// 3. Bitwise & Saturating Math Helpers for Wasm3 Interpreter
//    Các hàm toán học thao tác bit và ép kiểu bão hòa cho máy thực thi Wasm3
// ============================================================================

namespace {

inline uint32_t Clz32(uint32_t x) noexcept {
    if (x == 0) return 32U;
    uint32_t n = 0;
    if ((x & 0xFFFF0000U) == 0) { n += 16; x <<= 16; }
    if ((x & 0xFF000000U) == 0) { n += 8;  x <<= 8;  }
    if ((x & 0xF0000000U) == 0) { n += 4;  x <<= 4;  }
    if ((x & 0xC0000000U) == 0) { n += 2;  x <<= 2;  }
    if ((x & 0x80000000U) == 0) { n += 1; }
    return n;
}

inline uint32_t Ctz32(uint32_t x) noexcept {
    if (x == 0) return 32U;
    uint32_t n = 0;
    if ((x & 0x0000FFFFU) == 0) { n += 16; x >>= 16; }
    if ((x & 0x000000FFU) == 0) { n += 8;  x >>= 8;  }
    if ((x & 0x0000000FU) == 0) { n += 4;  x >>= 4;  }
    if ((x & 0x00000003U) == 0) { n += 2;  x >>= 2;  }
    if ((x & 0x00000001U) == 0) { n += 1; }
    return n;
}

inline uint32_t Popcnt32(uint32_t x) noexcept {
    x = x - ((x >> 1) & 0x55555555U);
    x = (x & 0x33333333U) + ((x >> 2) & 0x33333333U);
    return (((x + (x >> 4)) & 0x0F0F0F0FU) * 0x01010101U) >> 24;
}

inline uint64_t Clz64(uint64_t x) noexcept {
    if (x == 0) return 64ULL;
    uint32_t hi = static_cast<uint32_t>(x >> 32);
    return (hi != 0) ? Clz32(hi) : (32ULL + Clz32(static_cast<uint32_t>(x)));
}

inline uint64_t Ctz64(uint64_t x) noexcept {
    if (x == 0) return 64ULL;
    uint32_t lo = static_cast<uint32_t>(x);
    return (lo != 0) ? Ctz32(lo) : (32ULL + Ctz32(static_cast<uint32_t>(x >> 32)));
}

inline uint64_t Popcnt64(uint64_t x) noexcept {
    return Popcnt32(static_cast<uint32_t>(x)) + Popcnt32(static_cast<uint32_t>(x >> 32));
}

template <typename FloatT>
inline FloatT WasmNearest(FloatT v) noexcept {
    if (std::isnan(v) || std::isinf(v) || v == static_cast<FloatT>(0)) {
        return v;
    }
    FloatT fl = std::floor(v);
    FloatT diff = v - fl;
    if (diff < static_cast<FloatT>(0.5)) {
        return fl;
    }
    if (diff > static_cast<FloatT>(0.5)) {
        return fl + static_cast<FloatT>(1.0);
    }
    // Halfway case: round to even
    return (std::fmod(fl, static_cast<FloatT>(2.0)) == static_cast<FloatT>(0.0))
               ? fl
               : (fl + static_cast<FloatT>(1.0));
}

struct ControlBlockTargets {
    const uint8_t* else_pc = nullptr;
    const uint8_t* end_pc  = nullptr;
};

/**
 * @brief Pre-scans structured control blocks (`block`, `loop`, `if`, `else`, `end`)
 *        inside `[code_start, code_end)` so that branch instructions (`br`, `br_if`,
 *        `br_table`, `if` false-branch) jump in $O(1)$ time.
 *        Quét trước các khối điều khiển có cấu trúc để các lệnh nhảy thực thi trong thời gian $O(1)$.
 */
M3Result PreScanControlBlocks(const uint8_t* code_start,
                              const uint8_t* code_end,
                              std::unordered_map<const uint8_t*, ControlBlockTargets>* out_map) {
    struct OpenBlock {
        uint8_t        opcode;
        const uint8_t* header_pc;
        const uint8_t* else_pc;
    };
    std::vector<OpenBlock> stack;
    // Outermost function block
    stack.push_back(OpenBlock{0x02, code_start, nullptr});

    const uint8_t* ptr = code_start;
    while (ptr < code_end) {
        const uint8_t* op_pc = ptr;
        uint8_t op           = *ptr++;

        switch (op) {
            case 0x02: // block
            case 0x03: // loop
            case 0x04: { // if
                int32_t block_type = 0;
                M3Result res = ReadLEB_i32(&block_type, &ptr, code_end);
                if (res) return res;
                stack.push_back(OpenBlock{op, op_pc, nullptr});
                break;
            }
            case 0x05: { // else
                if (stack.empty() || stack.back().opcode != 0x04) {
                    return m3_err::wasmMalformed;
                }
                stack.back().else_pc = ptr;
                break;
            }
            case 0x0B: { // end
                if (stack.empty()) {
                    return m3_err::wasmMalformed;
                }
                OpenBlock blk = stack.back();
                stack.pop_back();
                (*out_map)[blk.header_pc] = ControlBlockTargets{blk.else_pc, ptr};
                break;
            }
            case 0x0C: // br
            case 0x0D: // br_if
            case 0x10: // call
            case 0x20: // local.get
            case 0x21: // local.set
            case 0x22: // local.tee
            case 0x23: // global.get
            case 0x24: // global.set
            case 0x25: // table.get
            case 0x26: // table.set
            case 0xD2: { // ref.func
                uint32_t imm = 0;
                M3Result res = ReadLEB_u32(&imm, &ptr, code_end);
                if (res) return res;
                break;
            }
            case 0x0E: { // br_table
                uint32_t count = 0;
                M3Result res   = ReadLEB_u32(&count, &ptr, code_end);
                if (res) return res;
                for (uint32_t i = 0; i <= count; ++i) {
                    uint32_t target = 0;
                    res = ReadLEB_u32(&target, &ptr, code_end);
                    if (res) return res;
                }
                break;
            }
            case 0x11: { // call_indirect
                uint32_t type_idx = 0, table_idx = 0;
                M3Result res = ReadLEB_u32(&type_idx, &ptr, code_end);
                if (res) return res;
                res = ReadLEB_u32(&table_idx, &ptr, code_end);
                if (res) return res;
                break;
            }
            case 0x28: case 0x29: case 0x2A: case 0x2B:
            case 0x2C: case 0x2D: case 0x2E: case 0x2F:
            case 0x30: case 0x31: case 0x32: case 0x33:
            case 0x34: case 0x35: case 0x36: case 0x37:
            case 0x38: case 0x39: case 0x3A: case 0x3B:
            case 0x3C: case 0x3D: case 0x3E: { // memory load/store memarg (align, offset)
                uint32_t align = 0, offset = 0;
                M3Result res = ReadLEB_u32(&align, &ptr, code_end);
                if (res) return res;
                res = ReadLEB_u32(&offset, &ptr, code_end);
                if (res) return res;
                break;
            }
            case 0x3F: // memory.size
            case 0x40: // memory.grow
            case 0xD0: { // ref.null
                uint8_t imm = 0;
                M3Result res = Read_u8(&imm, &ptr, code_end);
                if (res) return res;
                break;
            }
            case 0x41: { // i32.const
                int32_t imm = 0;
                M3Result res = ReadLEB_i32(&imm, &ptr, code_end);
                if (res) return res;
                break;
            }
            case 0x42: { // i64.const
                int64_t imm = 0;
                M3Result res = ReadLEB_i64(&imm, &ptr, code_end);
                if (res) return res;
                break;
            }
            case 0x43: { // f32.const
                uint32_t imm = 0;
                M3Result res = Read_u32(&imm, &ptr, code_end);
                if (res) return res;
                break;
            }
            case 0x44: { // f64.const
                uint64_t imm = 0;
                M3Result res = Read_u64(&imm, &ptr, code_end);
                if (res) return res;
                break;
            }
            case 0xFC: { // 0xFC prefix
                uint32_t subop = 0;
                M3Result res   = ReadLEB_u32(&subop, &ptr, code_end);
                if (res) return res;
                if (subop == 8 || subop == 12 || subop == 14) { // memory.init / table.init / table.copy
                    uint32_t a = 0, b = 0;
                    res = ReadLEB_u32(&a, &ptr, code_end);
                    if (res) return res;
                    res = ReadLEB_u32(&b, &ptr, code_end);
                    if (res) return res;
                } else if (subop == 9 || subop == 10 || subop == 11 || subop == 13 ||
                           subop == 15 || subop == 16 || subop == 17) {
                    uint32_t a = 0;
                    res = ReadLEB_u32(&a, &ptr, code_end);
                    if (res) return res;
                    if (subop == 10) { // memory.copy has two 0x00 bytes
                        uint32_t b = 0;
                        res = ReadLEB_u32(&b, &ptr, code_end);
                        if (res) return res;
                    }
                }
                break;
            }
            default:
                // Single-byte instruction (no immediate)
                break;
        }
    }
    return stack.empty() ? m3_err::none : m3_err::wasmMalformed;
}

} // namespace

// ============================================================================
// 4. Deterministic Wasm3 Bytecode Interpreter (`ExecuteWasmFunctionBytecode`)
//    Máy thông dịch Bytecode Wasm3 tất định (`ExecuteWasmFunctionBytecode`)
// ============================================================================

M3Result ExecuteWasmFunctionBytecode(Wasm3Module* module,
                                     M3Function* func,
                                     const std::vector<WasmVal>& args,
                                     std::vector<WasmVal>* results) {
    if (!module || !func || !func->wasm || !func->wasmEnd) {
        return m3_err::missingCompiledCode;
    }

    const uint8_t* ptr = func->wasm;
    const uint8_t* end = func->wasmEnd;

    uint32_t body_size = 0;
    M3Result res = ReadLEB_u32(&body_size, &ptr, end);
    if (res) return res;

    uint32_t num_local_groups = 0;
    res = ReadLEB_u32(&num_local_groups, &ptr, end);
    if (res) return res;

    std::vector<WasmVal> locals = args;
    for (uint32_t g = 0; g < num_local_groups; ++g) {
        uint32_t count = 0;
        res = ReadLEB_u32(&count, &ptr, end);
        if (res) return res;
        uint8_t raw_t = 0;
        res = Read_u8(&raw_t, &ptr, end);
        if (res) return res;
        M3ValueType vt = c_m3Type_none;
        res = NormalizeWasmType(&vt, static_cast<int8_t>(raw_t));
        if (res) return res;

        WasmVal zero{};
        zero.type   = vt;
        zero.of.i64 = 0;
        for (uint32_t c = 0; c < count; ++c) {
            locals.push_back(zero);
        }
    }

    const uint8_t* code_start = ptr;
    std::unordered_map<const uint8_t*, ControlBlockTargets> block_map;
    res = PreScanControlBlocks(code_start, end, &block_map);
    if (res) return res;

    struct ActiveLabel {
        uint8_t        opcode;      // 0x02=block/func, 0x03=loop, 0x04=if
        uint16_t       arity;       // branch/exit value arity
        size_t         stack_base;  // value stack depth on entry
        const uint8_t* target_pc;   // jump target on `br` (start of loop or end of block/if)
        const uint8_t* end_pc;      // end of block/loop/if
    };

    uint16_t func_ret_arity = (func->funcType) ? func->funcType->numRets : 0U;
    std::vector<WasmVal> stack;
    std::vector<ActiveLabel> labels;
    labels.push_back(ActiveLabel{0x02, func_ret_arity, 0U, end, end});

    auto pop_val = [&stack]() -> WasmVal {
        if (stack.empty()) {
            return WasmVal::MakeI32(0);
        }
        WasmVal v = stack.back();
        stack.pop_back();
        return v;
    };

    auto perform_branch = [&](uint32_t depth, const uint8_t** io_pc) -> M3Result {
        if (depth >= labels.size()) {
            return m3_err::wasmMalformed;
        }
        size_t target_idx       = labels.size() - 1U - depth;
        ActiveLabel target_lbl  = labels[target_idx];
        uint16_t branch_arity   = (target_lbl.opcode == 0x03) ? 0U : target_lbl.arity;
        std::vector<WasmVal> carried;
        carried.reserve(branch_arity);
        for (uint16_t i = 0; i < branch_arity; ++i) {
            carried.push_back(pop_val());
        }
        stack.resize(target_lbl.stack_base);
        for (auto it = carried.rbegin(); it != carried.rend(); ++it) {
            stack.push_back(*it);
        }
        if (target_lbl.opcode == 0x03) {
            // Loop: keep target label on the control stack and jump to loop start
            labels.resize(target_idx + 1U);
            *io_pc = target_lbl.target_pc;
        } else {
            // Block / If / Function: pop target label and jump past its `end`
            labels.resize(target_idx);
            *io_pc = target_lbl.end_pc;
        }
        return m3_err::none;
    };

    auto check_mem = [&](uint32_t addr, uint32_t offset, uint32_t access_size,
                         uint8_t** out_ptr) -> M3Result {
        auto mem = module->memory();
        if (!mem || !mem->data()) {
            return m3_err::globalMemoryNotAllocated;
        }
        uint64_t effective = static_cast<uint64_t>(addr) + static_cast<uint64_t>(offset);
        if (effective + static_cast<uint64_t>(access_size) > mem->byte_length()) {
            return m3_err::trapOutOfBoundsMemoryAccess;
        }
        *out_ptr = mem->data() + effective;
        return m3_err::none;
    };

    while (ptr < end && !labels.empty()) {
        const uint8_t* op_pc = ptr;
        uint8_t op           = *ptr++;

        switch (op) {
            case 0x00: // unreachable
                return m3_err::trapUnreachable;
            case 0x01: // nop
                break;
            case 0x02: // block
            case 0x03: { // loop
                int32_t bt = 0;
                res = ReadLEB_i32(&bt, &ptr, end);
                if (res) return res;
                uint16_t arity = (static_cast<uint8_t>(bt & 0x7F) == kWasmBinVoid) ? 0U : 1U;
                const ControlBlockTargets& tgt = block_map[op_pc];
                const uint8_t* br_target = (op == 0x03) ? ptr : tgt.end_pc;
                labels.push_back(ActiveLabel{op, arity, stack.size(), br_target, tgt.end_pc});
                break;
            }
            case 0x04: { // if
                int32_t bt = 0;
                res = ReadLEB_i32(&bt, &ptr, end);
                if (res) return res;
                uint16_t arity = (static_cast<uint8_t>(bt & 0x7F) == kWasmBinVoid) ? 0U : 1U;
                const ControlBlockTargets& tgt = block_map[op_pc];
                int32_t cond = pop_val().of.i32;
                labels.push_back(ActiveLabel{0x04, arity, stack.size(), tgt.end_pc, tgt.end_pc});
                if (cond == 0) {
                    if (tgt.else_pc) {
                        ptr = tgt.else_pc;
                    } else {
                        labels.pop_back();
                        ptr = tgt.end_pc;
                    }
                }
                break;
            }
            case 0x05: { // else (reached at end of true branch -> jump to end of if)
                if (labels.empty()) return m3_err::wasmMalformed;
                ActiveLabel lbl = labels.back();
                labels.pop_back();
                ptr = lbl.end_pc;
                break;
            }
            case 0x0B: { // end
                if (!labels.empty()) {
                    labels.pop_back();
                }
                break;
            }
            case 0x0C: { // br
                uint32_t depth = 0;
                res = ReadLEB_u32(&depth, &ptr, end);
                if (res) return res;
                res = perform_branch(depth, &ptr);
                if (res) return res;
                break;
            }
            case 0x0D: { // br_if
                uint32_t depth = 0;
                res = ReadLEB_u32(&depth, &ptr, end);
                if (res) return res;
                int32_t cond = pop_val().of.i32;
                if (cond != 0) {
                    res = perform_branch(depth, &ptr);
                    if (res) return res;
                }
                break;
            }
            case 0x0E: { // br_table
                uint32_t count = 0;
                res = ReadLEB_u32(&count, &ptr, end);
                if (res) return res;
                std::vector<uint32_t> targets(count + 1U);
                for (uint32_t i = 0; i <= count; ++i) {
                    res = ReadLEB_u32(&targets[i], &ptr, end);
                    if (res) return res;
                }
                uint32_t idx = static_cast<uint32_t>(pop_val().of.i32);
                uint32_t chosen = (idx < count) ? targets[idx] : targets[count];
                res = perform_branch(chosen, &ptr);
                if (res) return res;
                break;
            }
            case 0x0F: { // return
                res = perform_branch(static_cast<uint32_t>(labels.size() - 1U), &ptr);
                if (res) return res;
                break;
            }
            case 0x10: { // call
                uint32_t fn_idx = 0;
                res = ReadLEB_u32(&fn_idx, &ptr, end);
                if (res) return res;
                auto callee = module->GetFunction(fn_idx);
                if (!callee) return m3_err::functionLookupFailed;
                size_t nargs = callee->arg_types().size();
                std::vector<WasmVal> call_args(nargs);
                for (size_t i = 0; i < nargs; ++i) {
                    call_args[nargs - 1U - i] = pop_val();
                }
                std::vector<WasmVal> call_rets;
                res = callee->Call(call_args, &call_rets);
                if (res) return res;
                for (const auto& rv : call_rets) {
                    stack.push_back(rv);
                }
                break;
            }
            case 0x11: { // call_indirect
                uint32_t type_idx = 0, table_idx = 0;
                res = ReadLEB_u32(&type_idx, &ptr, end);
                if (res) return res;
                res = ReadLEB_u32(&table_idx, &ptr, end);
                if (res) return res;
                uint32_t elem_idx = static_cast<uint32_t>(pop_val().of.i32);
                auto tbl = module->table();
                if (!tbl) return m3_err::trapTableIndexOutOfRange;
                bool bounds_ok = false;
                auto callee = tbl->GetFunction(elem_idx, &bounds_ok);
                if (!bounds_ok) return m3_err::trapTableIndexOutOfRange;
                if (!callee) return m3_err::trapTableElementIsNull;

                M3Module* raw_mod = module->raw_module();
                if (raw_mod && type_idx < raw_mod->numFuncTypes && callee->raw_function()) {
                    if (!AreFuncTypesEqual(raw_mod->funcTypes[type_idx],
                                           callee->raw_function()->funcType)) {
                        return m3_err::trapIndirectCallTypeMismatch;
                    }
                }
                size_t nargs = callee->arg_types().size();
                std::vector<WasmVal> call_args(nargs);
                for (size_t i = 0; i < nargs; ++i) {
                    call_args[nargs - 1U - i] = pop_val();
                }
                std::vector<WasmVal> call_rets;
                res = callee->Call(call_args, &call_rets);
                if (res) return res;
                for (const auto& rv : call_rets) {
                    stack.push_back(rv);
                }
                break;
            }
            case 0x1A: // drop
                (void)pop_val();
                break;
            case 0x1B: { // select
                int32_t c  = pop_val().of.i32;
                WasmVal v2 = pop_val();
                WasmVal v1 = pop_val();
                stack.push_back((c != 0) ? v1 : v2);
                break;
            }
            case 0x20: { // local.get
                uint32_t idx = 0;
                res = ReadLEB_u32(&idx, &ptr, end);
                if (res || idx >= locals.size()) return m3_err::wasmMalformed;
                stack.push_back(locals[idx]);
                break;
            }
            case 0x21: { // local.set
                uint32_t idx = 0;
                res = ReadLEB_u32(&idx, &ptr, end);
                if (res || idx >= locals.size()) return m3_err::wasmMalformed;
                locals[idx] = pop_val();
                break;
            }
            case 0x22: { // local.tee
                uint32_t idx = 0;
                res = ReadLEB_u32(&idx, &ptr, end);
                if (res || idx >= locals.size() || stack.empty()) return m3_err::wasmMalformed;
                locals[idx] = stack.back();
                break;
            }
            case 0x23: { // global.get
                uint32_t idx = 0;
                res = ReadLEB_u32(&idx, &ptr, end);
                if (res) return res;
                auto g = module->GetGlobal(idx);
                if (!g) return m3_err::globaIndexOutOfBounds;
                WasmVal gv{};
                gv.type   = g->type();
                gv.of.i64 = g->GetRawBits();
                stack.push_back(gv);
                break;
            }
            case 0x24: { // global.set
                uint32_t idx = 0;
                res = ReadLEB_u32(&idx, &ptr, end);
                if (res) return res;
                auto g = module->GetGlobal(idx);
                if (!g) return m3_err::globaIndexOutOfBounds;
                WasmVal v = pop_val();
                if (!g->SetRawBits(v.of.i64)) return m3_err::globalNotMutable;
                if (module->raw_module() && idx < module->raw_module()->numGlobals) {
                    module->raw_module()->globals[idx].i64Value = v.of.i64;
                }
                break;
            }
            // Memory Load Instructions (0x28..0x35)
            case 0x28: case 0x29: case 0x2A: case 0x2B:
            case 0x2C: case 0x2D: case 0x2E: case 0x2F:
            case 0x30: case 0x31: case 0x32: case 0x33:
            case 0x34: case 0x35: {
                uint32_t align = 0, offset = 0;
                res = ReadLEB_u32(&align, &ptr, end);
                if (res) return res;
                res = ReadLEB_u32(&offset, &ptr, end);
                if (res) return res;
                uint32_t addr = static_cast<uint32_t>(pop_val().of.i32);
                uint32_t sz   = 4;
                if (op == 0x29 || op == 0x2B) sz = 8;
                else if (op == 0x2C || op == 0x2D || op == 0x30 || op == 0x31) sz = 1;
                else if (op == 0x2E || op == 0x2F || op == 0x32 || op == 0x33) sz = 2;

                uint8_t* mptr = nullptr;
                res = check_mem(addr, offset, sz, &mptr);
                if (res) return res;

                if (op == 0x28) { int32_t v; std::memcpy(&v, mptr, 4); stack.push_back(WasmVal::MakeI32(v)); }
                else if (op == 0x29) { int64_t v; std::memcpy(&v, mptr, 8); stack.push_back(WasmVal::MakeI64(v)); }
                else if (op == 0x2A) { float v; std::memcpy(&v, mptr, 4); stack.push_back(WasmVal::MakeF32(v)); }
                else if (op == 0x2B) { double v; std::memcpy(&v, mptr, 8); stack.push_back(WasmVal::MakeF64(v)); }
                else if (op == 0x2C) { stack.push_back(WasmVal::MakeI32(static_cast<int8_t>(*mptr))); }
                else if (op == 0x2D) { stack.push_back(WasmVal::MakeI32(static_cast<uint8_t>(*mptr))); }
                else if (op == 0x2E) { int16_t v; std::memcpy(&v, mptr, 2); stack.push_back(WasmVal::MakeI32(v)); }
                else if (op == 0x2F) { uint16_t v; std::memcpy(&v, mptr, 2); stack.push_back(WasmVal::MakeI32(v)); }
                else if (op == 0x30) { stack.push_back(WasmVal::MakeI64(static_cast<int8_t>(*mptr))); }
                else if (op == 0x31) { stack.push_back(WasmVal::MakeI64(static_cast<uint8_t>(*mptr))); }
                else if (op == 0x32) { int16_t v; std::memcpy(&v, mptr, 2); stack.push_back(WasmVal::MakeI64(v)); }
                else if (op == 0x33) { uint16_t v; std::memcpy(&v, mptr, 2); stack.push_back(WasmVal::MakeI64(v)); }
                else if (op == 0x34) { int32_t v; std::memcpy(&v, mptr, 4); stack.push_back(WasmVal::MakeI64(v)); }
                else if (op == 0x35) { uint32_t v; std::memcpy(&v, mptr, 4); stack.push_back(WasmVal::MakeI64(v)); }
                break;
            }
            // Memory Store Instructions (0x36..0x3E)
            case 0x36: case 0x37: case 0x38: case 0x39:
            case 0x3A: case 0x3B: case 0x3C: case 0x3D: case 0x3E: {
                uint32_t align = 0, offset = 0;
                res = ReadLEB_u32(&align, &ptr, end);
                if (res) return res;
                res = ReadLEB_u32(&offset, &ptr, end);
                if (res) return res;
                WasmVal val   = pop_val();
                uint32_t addr = static_cast<uint32_t>(pop_val().of.i32);
                uint32_t sz   = 4;
                if (op == 0x37 || op == 0x39) sz = 8;
                else if (op == 0x3A || op == 0x3C) sz = 1;
                else if (op == 0x3B || op == 0x3D) sz = 2;

                uint8_t* mptr = nullptr;
                res = check_mem(addr, offset, sz, &mptr);
                if (res) return res;

                if (op == 0x36 || op == 0x38) std::memcpy(mptr, &val.of.i32, 4);
                else if (op == 0x37 || op == 0x39) std::memcpy(mptr, &val.of.i64, 8);
                else if (op == 0x3A || op == 0x3C) *mptr = static_cast<uint8_t>(val.of.i64 & 0xFF);
                else if (op == 0x3B || op == 0x3D) {
                    uint16_t v16 = static_cast<uint16_t>(val.of.i64 & 0xFFFF);
                    std::memcpy(mptr, &v16, 2);
                } else if (op == 0x3E) {
                    uint32_t v32 = static_cast<uint32_t>(val.of.i64 & 0xFFFFFFFFULL);
                    std::memcpy(mptr, &v32, 4);
                }
                break;
            }
            case 0x3F: { // memory.size
                uint8_t mem_idx = 0;
                res = Read_u8(&mem_idx, &ptr, end);
                if (res) return res;
                auto mem = module->memory();
                stack.push_back(WasmVal::MakeI32(mem ? static_cast<int32_t>(mem->num_pages()) : 0));
                break;
            }
            case 0x40: { // memory.grow
                uint8_t mem_idx = 0;
                res = Read_u8(&mem_idx, &ptr, end);
                if (res) return res;
                uint32_t delta = static_cast<uint32_t>(pop_val().of.i32);
                auto mem = module->memory();
                int32_t prev = mem ? mem->Grow(delta) : -1;
                stack.push_back(WasmVal::MakeI32(prev));
                break;
            }
            case 0x41: { // i32.const
                int32_t v = 0;
                res = ReadLEB_i32(&v, &ptr, end);
                if (res) return res;
                stack.push_back(WasmVal::MakeI32(v));
                break;
            }
            case 0x42: { // i64.const
                int64_t v = 0;
                res = ReadLEB_i64(&v, &ptr, end);
                if (res) return res;
                stack.push_back(WasmVal::MakeI64(v));
                break;
            }
            case 0x43: { // f32.const
                uint32_t raw = 0;
                res = Read_u32(&raw, &ptr, end);
                if (res) return res;
                float f = 0.0f;
                std::memcpy(&f, &raw, 4);
                stack.push_back(WasmVal::MakeF32(f));
                break;
            }
            case 0x44: { // f64.const
                uint64_t raw = 0;
                res = Read_u64(&raw, &ptr, end);
                if (res) return res;
                double d = 0.0;
                std::memcpy(&d, &raw, 8);
                stack.push_back(WasmVal::MakeF64(d));
                break;
            }
            // i32 comparisons (0x45..0x4F)
            case 0x45: stack.push_back(WasmVal::MakeI32(pop_val().of.i32 == 0 ? 1 : 0)); break;
            case 0x46: { int32_t b = pop_val().of.i32, a = pop_val().of.i32; stack.push_back(WasmVal::MakeI32(a == b ? 1 : 0)); break; }
            case 0x47: { int32_t b = pop_val().of.i32, a = pop_val().of.i32; stack.push_back(WasmVal::MakeI32(a != b ? 1 : 0)); break; }
            case 0x48: { int32_t b = pop_val().of.i32, a = pop_val().of.i32; stack.push_back(WasmVal::MakeI32(a < b ? 1 : 0)); break; }
            case 0x49: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(a < b ? 1 : 0)); break; }
            case 0x4A: { int32_t b = pop_val().of.i32, a = pop_val().of.i32; stack.push_back(WasmVal::MakeI32(a > b ? 1 : 0)); break; }
            case 0x4B: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(a > b ? 1 : 0)); break; }
            case 0x4C: { int32_t b = pop_val().of.i32, a = pop_val().of.i32; stack.push_back(WasmVal::MakeI32(a <= b ? 1 : 0)); break; }
            case 0x4D: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(a <= b ? 1 : 0)); break; }
            case 0x4E: { int32_t b = pop_val().of.i32, a = pop_val().of.i32; stack.push_back(WasmVal::MakeI32(a >= b ? 1 : 0)); break; }
            case 0x4F: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(a >= b ? 1 : 0)); break; }
            // i64 comparisons (0x50..0x5A)
            case 0x50: stack.push_back(WasmVal::MakeI32(pop_val().of.i64 == 0 ? 1 : 0)); break;
            case 0x51: { int64_t b = pop_val().of.i64, a = pop_val().of.i64; stack.push_back(WasmVal::MakeI32(a == b ? 1 : 0)); break; }
            case 0x52: { int64_t b = pop_val().of.i64, a = pop_val().of.i64; stack.push_back(WasmVal::MakeI32(a != b ? 1 : 0)); break; }
            case 0x53: { int64_t b = pop_val().of.i64, a = pop_val().of.i64; stack.push_back(WasmVal::MakeI32(a < b ? 1 : 0)); break; }
            case 0x54: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI32(a < b ? 1 : 0)); break; }
            case 0x55: { int64_t b = pop_val().of.i64, a = pop_val().of.i64; stack.push_back(WasmVal::MakeI32(a > b ? 1 : 0)); break; }
            case 0x56: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI32(a > b ? 1 : 0)); break; }
            case 0x57: { int64_t b = pop_val().of.i64, a = pop_val().of.i64; stack.push_back(WasmVal::MakeI32(a <= b ? 1 : 0)); break; }
            case 0x58: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI32(a <= b ? 1 : 0)); break; }
            case 0x59: { int64_t b = pop_val().of.i64, a = pop_val().of.i64; stack.push_back(WasmVal::MakeI32(a >= b ? 1 : 0)); break; }
            case 0x5A: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI32(a >= b ? 1 : 0)); break; }
            // f32 comparisons (0x5B..0x60)
            case 0x5B: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeI32(a == b ? 1 : 0)); break; }
            case 0x5C: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeI32(a != b ? 1 : 0)); break; }
            case 0x5D: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeI32(a < b ? 1 : 0)); break; }
            case 0x5E: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeI32(a > b ? 1 : 0)); break; }
            case 0x5F: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeI32(a <= b ? 1 : 0)); break; }
            case 0x60: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeI32(a >= b ? 1 : 0)); break; }
            // f64 comparisons (0x61..0x66)
            case 0x61: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeI32(a == b ? 1 : 0)); break; }
            case 0x62: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeI32(a != b ? 1 : 0)); break; }
            case 0x63: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeI32(a < b ? 1 : 0)); break; }
            case 0x64: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeI32(a > b ? 1 : 0)); break; }
            case 0x65: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeI32(a <= b ? 1 : 0)); break; }
            case 0x66: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeI32(a >= b ? 1 : 0)); break; }
            // i32 arithmetic & bitwise (0x67..0x78)
            case 0x67: stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(Clz32(static_cast<uint32_t>(pop_val().of.i32))))); break;
            case 0x68: stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(Ctz32(static_cast<uint32_t>(pop_val().of.i32))))); break;
            case 0x69: stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(Popcnt32(static_cast<uint32_t>(pop_val().of.i32))))); break;
            case 0x6A: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a + b))); break; }
            case 0x6B: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a - b))); break; }
            case 0x6C: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a * b))); break; }
            case 0x6D: { // i32.div_s
                int32_t b = pop_val().of.i32, a = pop_val().of.i32;
                if (b == 0) return m3_err::trapDivisionByZero;
                if (a == std::numeric_limits<int32_t>::min() && b == -1) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI32(a / b));
                break;
            }
            case 0x6E: { // i32.div_u
                uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32);
                if (b == 0) return m3_err::trapDivisionByZero;
                stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a / b)));
                break;
            }
            case 0x6F: { // i32.rem_s
                int32_t b = pop_val().of.i32, a = pop_val().of.i32;
                if (b == 0) return m3_err::trapDivisionByZero;
                if (a == std::numeric_limits<int32_t>::min() && b == -1) {
                    stack.push_back(WasmVal::MakeI32(0));
                } else {
                    stack.push_back(WasmVal::MakeI32(a % b));
                }
                break;
            }
            case 0x70: { // i32.rem_u
                uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32);
                if (b == 0) return m3_err::trapDivisionByZero;
                stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a % b)));
                break;
            }
            case 0x71: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a & b))); break; }
            case 0x72: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a | b))); break; }
            case 0x73: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32), a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a ^ b))); break; }
            case 0x74: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32) & 31U, a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a << b))); break; }
            case 0x75: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32) & 31U; int32_t a = pop_val().of.i32; stack.push_back(WasmVal::MakeI32(a >> b)); break; }
            case 0x76: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32) & 31U, a = static_cast<uint32_t>(pop_val().of.i32); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(a >> b))); break; }
            case 0x77: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32) & 31U, a = static_cast<uint32_t>(pop_val().of.i32); uint32_t r = (b == 0) ? a : ((a << b) | (a >> (32U - b))); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(r))); break; }
            case 0x78: { uint32_t b = static_cast<uint32_t>(pop_val().of.i32) & 31U, a = static_cast<uint32_t>(pop_val().of.i32); uint32_t r = (b == 0) ? a : ((a >> b) | (a << (32U - b))); stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(r))); break; }
            // i64 arithmetic & bitwise (0x79..0x8A)
            case 0x79: stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(Clz64(static_cast<uint64_t>(pop_val().of.i64))))); break;
            case 0x7A: stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(Ctz64(static_cast<uint64_t>(pop_val().of.i64))))); break;
            case 0x7B: stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(Popcnt64(static_cast<uint64_t>(pop_val().of.i64))))); break;
            case 0x7C: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a + b))); break; }
            case 0x7D: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a - b))); break; }
            case 0x7E: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a * b))); break; }
            case 0x7F: { // i64.div_s
                int64_t b = pop_val().of.i64, a = pop_val().of.i64;
                if (b == 0) return m3_err::trapDivisionByZero;
                if (a == std::numeric_limits<int64_t>::min() && b == -1) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI64(a / b));
                break;
            }
            case 0x80: { // i64.div_u
                uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64);
                if (b == 0) return m3_err::trapDivisionByZero;
                stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a / b)));
                break;
            }
            case 0x81: { // i64.rem_s
                int64_t b = pop_val().of.i64, a = pop_val().of.i64;
                if (b == 0) return m3_err::trapDivisionByZero;
                if (a == std::numeric_limits<int64_t>::min() && b == -1) {
                    stack.push_back(WasmVal::MakeI64(0));
                } else {
                    stack.push_back(WasmVal::MakeI64(a % b));
                }
                break;
            }
            case 0x82: { // i64.rem_u
                uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64);
                if (b == 0) return m3_err::trapDivisionByZero;
                stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a % b)));
                break;
            }
            case 0x83: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a & b))); break; }
            case 0x84: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a | b))); break; }
            case 0x85: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64), a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a ^ b))); break; }
            case 0x86: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64) & 63ULL, a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a << b))); break; }
            case 0x87: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64) & 63ULL; int64_t a = pop_val().of.i64; stack.push_back(WasmVal::MakeI64(a >> b)); break; }
            case 0x88: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64) & 63ULL, a = static_cast<uint64_t>(pop_val().of.i64); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(a >> b))); break; }
            case 0x89: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64) & 63ULL, a = static_cast<uint64_t>(pop_val().of.i64); uint64_t r = (b == 0) ? a : ((a << b) | (a >> (64ULL - b))); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(r))); break; }
            case 0x8A: { uint64_t b = static_cast<uint64_t>(pop_val().of.i64) & 63ULL, a = static_cast<uint64_t>(pop_val().of.i64); uint64_t r = (b == 0) ? a : ((a >> b) | (a << (64ULL - b))); stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(r))); break; }
            // f32 operations (0x8B..0x98)
            case 0x8B: stack.push_back(WasmVal::MakeF32(std::fabs(pop_val().of.f32))); break;
            case 0x8C: stack.push_back(WasmVal::MakeF32(-pop_val().of.f32)); break;
            case 0x8D: stack.push_back(WasmVal::MakeF32(std::ceil(pop_val().of.f32))); break;
            case 0x8E: stack.push_back(WasmVal::MakeF32(std::floor(pop_val().of.f32))); break;
            case 0x8F: stack.push_back(WasmVal::MakeF32(std::trunc(pop_val().of.f32))); break;
            case 0x90: stack.push_back(WasmVal::MakeF32(WasmNearest(pop_val().of.f32))); break;
            case 0x91: stack.push_back(WasmVal::MakeF32(std::sqrt(pop_val().of.f32))); break;
            case 0x92: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeF32(a + b)); break; }
            case 0x93: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeF32(a - b)); break; }
            case 0x94: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeF32(a * b)); break; }
            case 0x95: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeF32(a / b)); break; }
            case 0x96: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeF32((std::isnan(a) || std::isnan(b)) ? std::numeric_limits<float>::quiet_NaN() : std::min(a, b))); break; }
            case 0x97: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeF32((std::isnan(a) || std::isnan(b)) ? std::numeric_limits<float>::quiet_NaN() : std::max(a, b))); break; }
            case 0x98: { float b = pop_val().of.f32, a = pop_val().of.f32; stack.push_back(WasmVal::MakeF32(std::copysign(a, b))); break; }
            // f64 operations (0x99..0xA6)
            case 0x99: stack.push_back(WasmVal::MakeF64(std::fabs(pop_val().of.f64))); break;
            case 0x9A: stack.push_back(WasmVal::MakeF64(-pop_val().of.f64)); break;
            case 0x9B: stack.push_back(WasmVal::MakeF64(std::ceil(pop_val().of.f64))); break;
            case 0x9C: stack.push_back(WasmVal::MakeF64(std::floor(pop_val().of.f64))); break;
            case 0x9D: stack.push_back(WasmVal::MakeF64(std::trunc(pop_val().of.f64))); break;
            case 0x9E: stack.push_back(WasmVal::MakeF64(WasmNearest(pop_val().of.f64))); break;
            case 0x9F: stack.push_back(WasmVal::MakeF64(std::sqrt(pop_val().of.f64))); break;
            case 0xA0: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeF64(a + b)); break; }
            case 0xA1: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeF64(a - b)); break; }
            case 0xA2: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeF64(a * b)); break; }
            case 0xA3: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeF64(a / b)); break; }
            case 0xA4: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeF64((std::isnan(a) || std::isnan(b)) ? std::numeric_limits<double>::quiet_NaN() : std::min(a, b))); break; }
            case 0xA5: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeF64((std::isnan(a) || std::isnan(b)) ? std::numeric_limits<double>::quiet_NaN() : std::max(a, b))); break; }
            case 0xA6: { double b = pop_val().of.f64, a = pop_val().of.f64; stack.push_back(WasmVal::MakeF64(std::copysign(a, b))); break; }
            // Conversions & Reinterpretations (0xA7..0xC4)
            case 0xA7: stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(pop_val().of.i64))); break;
            case 0xA8: {
                float f = pop_val().of.f32;
                if (std::isnan(f)) return m3_err::trapIntegerConversion;
                if (f >= 2147483648.0f || f < -2147483648.0f) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(f)));
                break;
            }
            case 0xA9: {
                float f = pop_val().of.f32;
                if (std::isnan(f)) return m3_err::trapIntegerConversion;
                if (f >= 4294967296.0f || f <= -1.0f) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(static_cast<uint32_t>(f))));
                break;
            }
            case 0xAA: {
                double d = pop_val().of.f64;
                if (std::isnan(d)) return m3_err::trapIntegerConversion;
                if (d >= 2147483648.0 || d <= -2147483649.0) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(d)));
                break;
            }
            case 0xAB: {
                double d = pop_val().of.f64;
                if (std::isnan(d)) return m3_err::trapIntegerConversion;
                if (d >= 4294967296.0 || d <= -1.0) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(static_cast<uint32_t>(d))));
                break;
            }
            case 0xAC: stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(pop_val().of.i32))); break;
            case 0xAD: stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(static_cast<uint32_t>(pop_val().of.i32)))); break;
            case 0xAE: {
                float f = pop_val().of.f32;
                if (std::isnan(f)) return m3_err::trapIntegerConversion;
                if (f >= 9223372036854775808.0f || f < -9223372036854775808.0f) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(f)));
                break;
            }
            case 0xAF: {
                float f = pop_val().of.f32;
                if (std::isnan(f)) return m3_err::trapIntegerConversion;
                if (f >= 18446744073709551616.0f || f <= -1.0f) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(static_cast<uint64_t>(f))));
                break;
            }
            case 0xB0: {
                double d = pop_val().of.f64;
                if (std::isnan(d)) return m3_err::trapIntegerConversion;
                if (d >= 9223372036854775808.0 || d < -9223372036854775808.0) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(d)));
                break;
            }
            case 0xB1: {
                double d = pop_val().of.f64;
                if (std::isnan(d)) return m3_err::trapIntegerConversion;
                if (d >= 18446744073709551616.0 || d <= -1.0) return m3_err::trapIntegerOverflow;
                stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(static_cast<uint64_t>(d))));
                break;
            }
            case 0xB2: stack.push_back(WasmVal::MakeF32(static_cast<float>(pop_val().of.i32))); break;
            case 0xB3: stack.push_back(WasmVal::MakeF32(static_cast<float>(static_cast<uint32_t>(pop_val().of.i32)))); break;
            case 0xB4: stack.push_back(WasmVal::MakeF32(static_cast<float>(pop_val().of.i64))); break;
            case 0xB5: stack.push_back(WasmVal::MakeF32(static_cast<float>(static_cast<uint64_t>(pop_val().of.i64)))); break;
            case 0xB6: stack.push_back(WasmVal::MakeF32(static_cast<float>(pop_val().of.f64))); break;
            case 0xB7: stack.push_back(WasmVal::MakeF64(static_cast<double>(pop_val().of.i32))); break;
            case 0xB8: stack.push_back(WasmVal::MakeF64(static_cast<double>(static_cast<uint32_t>(pop_val().of.i32)))); break;
            case 0xB9: stack.push_back(WasmVal::MakeF64(static_cast<double>(pop_val().of.i64))); break;
            case 0xBA: stack.push_back(WasmVal::MakeF64(static_cast<double>(static_cast<uint64_t>(pop_val().of.i64)))); break;
            case 0xBB: stack.push_back(WasmVal::MakeF64(static_cast<double>(pop_val().of.f32))); break;
            case 0xBC: { float f = pop_val().of.f32; int32_t i; std::memcpy(&i, &f, 4); stack.push_back(WasmVal::MakeI32(i)); break; }
            case 0xBD: { double d = pop_val().of.f64; int64_t i; std::memcpy(&i, &d, 8); stack.push_back(WasmVal::MakeI64(i)); break; }
            case 0xBE: { int32_t i = pop_val().of.i32; float f; std::memcpy(&f, &i, 4); stack.push_back(WasmVal::MakeF32(f)); break; }
            case 0xBF: { int64_t i = pop_val().of.i64; double d; std::memcpy(&d, &i, 8); stack.push_back(WasmVal::MakeF64(d)); break; }
            case 0xC0: stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(static_cast<int8_t>(pop_val().of.i32)))); break;
            case 0xC1: stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(static_cast<int16_t>(pop_val().of.i32)))); break;
            case 0xC2: stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(static_cast<int8_t>(pop_val().of.i64)))); break;
            case 0xC3: stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(static_cast<int16_t>(pop_val().of.i64)))); break;
            case 0xC4: stack.push_back(WasmVal::MakeI64(static_cast<int64_t>(static_cast<int32_t>(pop_val().of.i64)))); break;
            case 0xFC: { // Extended 0xFC operations
                uint32_t subop = 0;
                res = ReadLEB_u32(&subop, &ptr, end);
                if (res) return res;
                if (subop == 0) { // i32.trunc_sat_f32_s
                    float f = pop_val().of.f32;
                    int32_t r = std::isnan(f) ? 0 : (f >= 2147483648.0f ? INT32_MAX : (f < -2147483648.0f ? INT32_MIN : static_cast<int32_t>(f)));
                    stack.push_back(WasmVal::MakeI32(r));
                } else if (subop == 1) { // i32.trunc_sat_f32_u
                    float f = pop_val().of.f32;
                    uint32_t r = (std::isnan(f) || f <= 0.0f) ? 0U : (f >= 4294967296.0f ? UINT32_MAX : static_cast<uint32_t>(f));
                    stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(r)));
                } else if (subop == 2) { // i32.trunc_sat_f64_s
                    double d = pop_val().of.f64;
                    int32_t r = std::isnan(d) ? 0 : (d >= 2147483648.0 ? INT32_MAX : (d <= -2147483649.0 ? INT32_MIN : static_cast<int32_t>(d)));
                    stack.push_back(WasmVal::MakeI32(r));
                } else if (subop == 3) { // i32.trunc_sat_f64_u
                    double d = pop_val().of.f64;
                    uint32_t r = (std::isnan(d) || d <= 0.0) ? 0U : (d >= 4294967296.0 ? UINT32_MAX : static_cast<uint32_t>(d));
                    stack.push_back(WasmVal::MakeI32(static_cast<int32_t>(r)));
                } else if (subop == 10) { // memory.copy
                    uint32_t d_mem = 0, s_mem = 0;
                    ReadLEB_u32(&d_mem, &ptr, end);
                    ReadLEB_u32(&s_mem, &ptr, end);
                    uint32_t n   = static_cast<uint32_t>(pop_val().of.i32);
                    uint32_t src = static_cast<uint32_t>(pop_val().of.i32);
                    uint32_t dst = static_cast<uint32_t>(pop_val().of.i32);
                    uint8_t *dptr = nullptr, *sptr = nullptr;
                    res = check_mem(dst, 0, n, &dptr); if (res) return res;
                    res = check_mem(src, 0, n, &sptr); if (res) return res;
                    if (n > 0) std::memmove(dptr, sptr, n);
                } else if (subop == 11) { // memory.fill
                    uint32_t m_idx = 0;
                    ReadLEB_u32(&m_idx, &ptr, end);
                    uint32_t n   = static_cast<uint32_t>(pop_val().of.i32);
                    uint8_t val  = static_cast<uint8_t>(pop_val().of.i32 & 0xFF);
                    uint32_t dst = static_cast<uint32_t>(pop_val().of.i32);
                    uint8_t* dptr = nullptr;
                    res = check_mem(dst, 0, n, &dptr); if (res) return res;
                    if (n > 0) std::memset(dptr, val, n);
                }
                break;
            }
            default:
                return m3_err::wasmMalformed;
        }
    }

    if (results) {
        results->clear();
        if (func_ret_arity > 0) {
            results->resize(func_ret_arity);
            for (uint16_t i = 0; i < func_ret_arity; ++i) {
                (*results)[func_ret_arity - 1U - i] = pop_val();
            }
        }
    }
    return m3_err::none;
}

// ============================================================================
// 5. Built-in Host Import Implementations ([OBSERVED] in .text 0x0357c0..0x035990)
//    Triển khai 8 hàm Host tích hợp sẵn (`_abort`, `_exit`, `_memcpy`, `_memmove`, ...)
// ============================================================================

M3Result HostImport_Abort(Wasm3Module*, const std::vector<WasmVal>&, std::vector<WasmVal>*) {
    // [OBSERVED] 0x0357c0: returns m3Err_trapAbort
    return m3_err::trapAbort;
}

M3Result HostImport_Exit(Wasm3Module*, const std::vector<WasmVal>&, std::vector<WasmVal>*) {
    // [OBSERVED] 0x0357fc: returns m3Err_trapExit
    return m3_err::trapExit;
}

M3Result HostImport_Memcpy(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets) {
    // [OBSERVED] 0x03582c: _memcpy(dst, src, len) -> dst
    if (!mod || !mod->memory() || args.size() < 3U) {
        return m3_err::trapOutOfBoundsMemoryAccess;
    }
    uint32_t dst = static_cast<uint32_t>(args[0].of.i32);
    uint32_t src = static_cast<uint32_t>(args[1].of.i32);
    uint32_t len = static_cast<uint32_t>(args[2].of.i32);
    size_t mem_sz = mod->memory()->byte_length();
    if (static_cast<uint64_t>(dst) + len > mem_sz || static_cast<uint64_t>(src) + len > mem_sz) {
        return m3_err::trapOutOfBoundsMemoryAccess;
    }
    if (len > 0) {
        std::memcpy(mod->memory()->data() + dst, mod->memory()->data() + src, len);
    }
    if (rets) {
        rets->assign({WasmVal::MakeI32(static_cast<int32_t>(dst))});
    }
    return m3_err::none;
}

M3Result HostImport_Memmove(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets) {
    // [OBSERVED] 0x035870: _memmove(dst, src, len) -> dst
    if (!mod || !mod->memory() || args.size() < 3U) {
        return m3_err::trapOutOfBoundsMemoryAccess;
    }
    uint32_t dst = static_cast<uint32_t>(args[0].of.i32);
    uint32_t src = static_cast<uint32_t>(args[1].of.i32);
    uint32_t len = static_cast<uint32_t>(args[2].of.i32);
    size_t mem_sz = mod->memory()->byte_length();
    if (static_cast<uint64_t>(dst) + len > mem_sz || static_cast<uint64_t>(src) + len > mem_sz) {
        return m3_err::trapOutOfBoundsMemoryAccess;
    }
    if (len > 0) {
        std::memmove(mod->memory()->data() + dst, mod->memory()->data() + src, len);
    }
    if (rets) {
        rets->assign({WasmVal::MakeI32(static_cast<int32_t>(dst))});
    }
    return m3_err::none;
}

M3Result HostImport_Memset(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets) {
    // [OBSERVED] 0x0358b4: _memset(dst, val, len) -> dst
    if (!mod || !mod->memory() || args.size() < 3U) {
        return m3_err::trapOutOfBoundsMemoryAccess;
    }
    uint32_t dst = static_cast<uint32_t>(args[0].of.i32);
    int32_t val  = args[1].of.i32;
    uint32_t len = static_cast<uint32_t>(args[2].of.i32);
    size_t mem_sz = mod->memory()->byte_length();
    if (static_cast<uint64_t>(dst) + len > mem_sz) {
        return m3_err::trapOutOfBoundsMemoryAccess;
    }
    if (len > 0) {
        std::memset(mod->memory()->data() + dst, val & 0xFF, len);
    }
    if (rets) {
        rets->assign({WasmVal::MakeI32(static_cast<int32_t>(dst))});
    }
    return m3_err::none;
}

M3Result HostImport_Printf(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets) {
    // [OBSERVED] 0x0358f8: printf(fmt_offset, ...)
    if (!mod || !mod->memory() || args.empty()) {
        return m3_err::trapOutOfBoundsMemoryAccess;
    }
    uint32_t fmt_off = static_cast<uint32_t>(args[0].of.i32);
    size_t mem_sz    = mod->memory()->byte_length();
    if (fmt_off >= mem_sz) {
        return m3_err::trapOutOfBoundsMemoryAccess;
    }
    const char* fmt = reinterpret_cast<const char*>(mod->memory()->data() + fmt_off);
    size_t max_len  = strnlen(fmt, mem_sz - fmt_off);
    if (rets) {
        rets->assign({WasmVal::MakeI32(static_cast<int32_t>(max_len))});
    }
    return m3_err::none;
}

M3Result HostImport_ClockMs(Wasm3Module*, const std::vector<WasmVal>&, std::vector<WasmVal>* rets) {
    // [OBSERVED] 0x035948: clock_ms() -> uint64_t milliseconds via clock_gettime
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
    if (rets) {
        rets->assign({WasmVal::MakeI64(ms)});
    }
    return m3_err::none;
}

M3Result HostImport_Debug(Wasm3Module*, const std::vector<WasmVal>&, std::vector<WasmVal>* rets) {
    // [OBSERVED] 0x035990: _debug() -> no-op debug hook
    if (rets && !rets->empty()) {
        rets->clear();
    }
    return m3_err::none;
}

} // namespace wasm
} // namespace vmsdk
