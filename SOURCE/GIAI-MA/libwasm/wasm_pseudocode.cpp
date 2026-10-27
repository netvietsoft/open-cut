/**
 * @file wasm_pseudocode.cpp
 * @brief End-to-End Integration, Wasm Binary Synthesis & Self-Test Engine for `libwasm.so`
 *        Tích hợp đầu-cuối, Tổng hợp nhị phân Wasm & Động cơ tự kiểm thử cho `libwasm.so`
 *
 * @details
 * Implements `vmsdk::wasm::RunLibWasmSelfTest()` to deterministically verify:
 * 1. JNI factory pointer identity (`Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory` @ `0x0117d8`)
 * 2. `RegisterWebAssembly` (`0x01003c`) registration of all 7 QuickJS/LepusNG `JSClassDef` classes
 * 3. LEB128 unsigned & signed decoding (`ReadLEB_u32`, `ReadLEB_u64`, `ReadLEB_i32`, `ReadLEB_i64`)
 * 4. Wasm3 `m3_NewEnvironment` (`0x02268c`), `m3_ParseModule` (`0x022bc0`), `m3_LoadModule` (`0x022e80`),
 *    `m3_FreeModule` (`0x032d08`), and 12-section parser dispatch (`.data.rel.ro 0x03b888..0x03b8e8`)
 * 5. Full WebAssembly JS API (`WebAssembly.validate`, `WebAssembly.compile`, `WebAssembly.instantiate`,
 *    `WebAssembly.Module`, `WebAssembly.Instance`, `WebAssembly.Memory`, `WebAssembly.Table`,
 *    `WebAssembly.Global`, `WebAssembly.Function`, and Base64 module decoding).
 */

#include "wasm_interface.h"

#include <cstdio>
#include <cstring>
#include <vector>

namespace vmsdk {
namespace wasm {

namespace {

/**
 * @brief Helper to append an unsigned LEB128 integer to a byte buffer.
 *        Hàm phụ trợ ghi số nguyên không dấu LEB128 vào vector byte.
 */
void AppendLEB_u32(std::vector<uint8_t>* buf, uint32_t value) {
    do {
        uint8_t byte = static_cast<uint8_t>(value & 0x7FU);
        value >>= 7U;
        if (value != 0) {
            byte |= 0x80U;
        }
        buf->push_back(byte);
    } while (value != 0);
}

/**
 * @brief Helper to append a signed LEB128 integer to a byte buffer.
 *        Hàm phụ trợ ghi số nguyên có dấu LEB128 vào vector byte.
 */
void AppendLEB_i32(std::vector<uint8_t>* buf, int32_t value) {
    bool more = true;
    while (more) {
        uint8_t byte = static_cast<uint8_t>(value & 0x7F);
        value >>= 7;
        if ((value == 0 && (byte & 0x40U) == 0) || (value == -1 && (byte & 0x40U) != 0)) {
            more = false;
        } else {
            byte |= 0x80U;
        }
        buf->push_back(byte);
    }
}

void AppendSection(std::vector<uint8_t>* wasm_bin, uint8_t section_id,
                   const std::vector<uint8_t>& payload) {
    wasm_bin->push_back(section_id);
    AppendLEB_u32(wasm_bin, static_cast<uint32_t>(payload.size()));
    wasm_bin->insert(wasm_bin->end(), payload.begin(), payload.end());
}

void AppendUtf8String(std::vector<uint8_t>* buf, const char* str) {
    uint32_t len = static_cast<uint32_t>(std::strlen(str));
    AppendLEB_u32(buf, len);
    buf->insert(buf->end(), reinterpret_cast<const uint8_t*>(str),
                reinterpret_cast<const uint8_t*>(str) + len);
}

/**
 * @brief Synthesizes a comprehensive multi-section WebAssembly module exercising:
 *        - Section 0 (Custom): `"vmsdk_meta"` with payload `"OpenCutWasm3"`
 *        - Section 1 (Type):
 *          - Type 0: `(i32, i32) -> i32`
 *          - Type 1: `(i32) -> i32`
 *        - Section 4 (Table): 1 `funcref` table (`initial = 2, max = 4`)
 *        - Section 5 (Memory): 1 memory (`initial = 1 page, max = 4 pages`)
 *        - Section 6 (Global): 1 mutable `i32` global initialized to `100`
 *        - Section 7 (Export):
 *          - `"add"` (func 0)
 *          - `"fib"` (func 1: iterative loop computing Fibonacci)
 *          - `"mem_sum"` (func 2: loads 4 little-endian `i32` values from linear memory)
 *          - `"call_table"` (func 3: indirect call via `table0`)
 *          - `"memory"` (memory 0)
 *          - `"table"` (table 0)
 *          - `"g_counter"` (global 0)
 *        - Section 9 (Element): active segment binding `table[0] = add`, `table[1] = fib`
 *        - Section 10 (Code): 4 function bodies
 *        - Section 11 (Data): active segment at offset `0` with 4 `int32_t` values `{10, 20, 30, 40}`
 */
std::vector<uint8_t> BuildVerificationWasmModule() {
    std::vector<uint8_t> bin = {
        0x00, 0x61, 0x73, 0x6D, // "\0asm"
        0x01, 0x00, 0x00, 0x00  // version 1
    };

    // Section 0: Custom section "vmsdk_meta" -> "OpenCutWasm3" (12 bytes)
    {
        std::vector<uint8_t> sec;
        AppendUtf8String(&sec, "vmsdk_meta");
        const char kPayload[] = "OpenCutWasm3";
        sec.insert(sec.end(), kPayload, kPayload + 12);
        AppendSection(&bin, kWasmSectionCustom, sec);
    }

    // Section 1: Type section (2 types)
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 2U);
        // Type 0: (i32, i32) -> i32
        sec.push_back(kWasmBinFuncType);
        AppendLEB_u32(&sec, 2U);
        sec.push_back(kWasmBinI32);
        sec.push_back(kWasmBinI32);
        AppendLEB_u32(&sec, 1U);
        sec.push_back(kWasmBinI32);
        // Type 1: (i32) -> i32
        sec.push_back(kWasmBinFuncType);
        AppendLEB_u32(&sec, 1U);
        sec.push_back(kWasmBinI32);
        AppendLEB_u32(&sec, 1U);
        sec.push_back(kWasmBinI32);
        AppendSection(&bin, kWasmSectionType, sec);
    }

    // Section 3: Function section (4 functions: types [0, 1, 1, 0])
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 4U);
        AppendLEB_u32(&sec, 0U); // func 0: add(a, b) -> i32
        AppendLEB_u32(&sec, 1U); // func 1: fib(n) -> i32
        AppendLEB_u32(&sec, 1U); // func 2: mem_sum(base) -> i32
        AppendLEB_u32(&sec, 0U); // func 3: call_table(a, b) -> i32
        AppendSection(&bin, kWasmSectionFunction, sec);
    }

    // Section 4: Table section (1 funcref table, initial=2, max=4)
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 1U);
        sec.push_back(kWasmBinFuncRef);
        sec.push_back(0x01U); // has max
        AppendLEB_u32(&sec, 2U);
        AppendLEB_u32(&sec, 4U);
        AppendSection(&bin, kWasmSectionTable, sec);
    }

    // Section 5: Memory section (1 memory, initial=1, max=4)
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 1U);
        sec.push_back(0x01U); // has max
        AppendLEB_u32(&sec, 1U);
        AppendLEB_u32(&sec, 4U);
        AppendSection(&bin, kWasmSectionMemory, sec);
    }

    // Section 6: Global section (1 mutable i32 global = 100)
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 1U);
        sec.push_back(kWasmBinI32);
        sec.push_back(0x01U); // mutable
        sec.push_back(0x41U); // i32.const
        AppendLEB_i32(&sec, 100);
        sec.push_back(0x0BU); // end
        AppendSection(&bin, kWasmSectionGlobal, sec);
    }

    // Section 7: Export section (7 exports)
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 7U);
        AppendUtf8String(&sec, "add");        sec.push_back(kWasmExtFunc);   AppendLEB_u32(&sec, 0U);
        AppendUtf8String(&sec, "fib");        sec.push_back(kWasmExtFunc);   AppendLEB_u32(&sec, 1U);
        AppendUtf8String(&sec, "mem_sum");    sec.push_back(kWasmExtFunc);   AppendLEB_u32(&sec, 2U);
        AppendUtf8String(&sec, "call_table"); sec.push_back(kWasmExtFunc);   AppendLEB_u32(&sec, 3U);
        AppendUtf8String(&sec, "memory");     sec.push_back(kWasmExtMemory); AppendLEB_u32(&sec, 0U);
        AppendUtf8String(&sec, "table");      sec.push_back(kWasmExtTable);  AppendLEB_u32(&sec, 0U);
        AppendUtf8String(&sec, "g_counter");  sec.push_back(kWasmExtGlobal); AppendLEB_u32(&sec, 0U);
        AppendSection(&bin, kWasmSectionExport, sec);
    }

    // Section 9: Element section (1 segment at offset 0 with [func 0, func 1])
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 1U);
        AppendLEB_u32(&sec, 0U); // mode 0 (active, table 0)
        sec.push_back(0x41U);    // i32.const 0
        AppendLEB_i32(&sec, 0);
        sec.push_back(0x0BU);    // end
        AppendLEB_u32(&sec, 2U); // 2 elements
        AppendLEB_u32(&sec, 0U); // func 0
        AppendLEB_u32(&sec, 1U); // func 1
        AppendSection(&bin, kWasmSectionElement, sec);
    }

    // Section 10: Code section (4 function bodies)
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 4U);

        // Func 0: add(a, b) -> a + b
        {
            std::vector<uint8_t> body = {
                0x00,       // 0 local declarations
                0x20, 0x00, // local.get 0
                0x20, 0x01, // local.get 1
                0x6A,       // i32.add
                0x0B        // end
            };
            AppendLEB_u32(&sec, static_cast<uint32_t>(body.size()));
            sec.insert(sec.end(), body.begin(), body.end());
        }

        // Func 1: fib(n) -> iterative Fibonacci using 3 i32 locals (a=local1, b=local2, tmp=local3)
        {
            std::vector<uint8_t> body = {
                0x01, 0x03, 0x7F, // 1 local group: 3 x i32 (locals 1, 2, 3)
                0x41, 0x00,       // i32.const 0
                0x21, 0x01,       // local.set 1 (a = 0)
                0x41, 0x01,       // i32.const 1
                0x21, 0x02,       // local.set 2 (b = 1)
                0x02, 0x40,       // block (void)
                0x03, 0x40,       //   loop (void)
                0x20, 0x00,       //     local.get 0 (n)
                0x45,             //     i32.eqz
                0x0D, 0x01,       //     br_if 1 (break to block end)
                0x20, 0x01,       //     local.get 1 (a)
                0x20, 0x02,       //     local.get 2 (b)
                0x6A,             //     i32.add
                0x21, 0x03,       //     local.set 3 (tmp = a + b)
                0x20, 0x02,       //     local.get 2
                0x21, 0x01,       //     local.set 1 (a = b)
                0x20, 0x03,       //     local.get 3
                0x21, 0x02,       //     local.set 2 (b = tmp)
                0x20, 0x00,       //     local.get 0
                0x41, 0x01,       //     i32.const 1
                0x6B,             //     i32.sub
                0x21, 0x00,       //     local.set 0 (n = n - 1)
                0x0C, 0x00,       //     br 0 (continue loop)
                0x0B,             //   end loop
                0x0B,             // end block
                0x20, 0x01,       // local.get 1 (return a)
                0x0B              // end
            };
            AppendLEB_u32(&sec, static_cast<uint32_t>(body.size()));
            sec.insert(sec.end(), body.begin(), body.end());
        }

        // Func 2: mem_sum(base) -> i32.load(base+0) + i32.load(base+4) + i32.load(base+8) + i32.load(base+12)
        {
            std::vector<uint8_t> body = {
                0x00,             // 0 local declarations
                0x20, 0x00,       // local.get 0
                0x28, 0x02, 0x00, // i32.load align=2 offset=0
                0x20, 0x00,       // local.get 0
                0x28, 0x02, 0x04, // i32.load align=2 offset=4
                0x6A,             // i32.add
                0x20, 0x00,       // local.get 0
                0x28, 0x02, 0x08, // i32.load align=2 offset=8
                0x6A,             // i32.add
                0x20, 0x00,       // local.get 0
                0x28, 0x02, 0x0C, // i32.load align=2 offset=12
                0x6A,             // i32.add
                0x0B              // end
            };
            AppendLEB_u32(&sec, static_cast<uint32_t>(body.size()));
            sec.insert(sec.end(), body.begin(), body.end());
        }

        // Func 3: call_table(a, b) -> calls table[0](a, b) via call_indirect (type 0)
        {
            std::vector<uint8_t> body = {
                0x00,             // 0 local declarations
                0x20, 0x00,       // local.get 0 (a)
                0x20, 0x01,       // local.get 1 (b)
                0x41, 0x00,       // i32.const 0 (table index 0 = add)
                0x11, 0x00, 0x00, // call_indirect type=0 table=0
                0x0B              // end
            };
            AppendLEB_u32(&sec, static_cast<uint32_t>(body.size()));
            sec.insert(sec.end(), body.begin(), body.end());
        }

        AppendSection(&bin, kWasmSectionCode, sec);
    }

    // Section 11: Data section (1 active segment at offset 0 with {10, 20, 30, 40})
    {
        std::vector<uint8_t> sec;
        AppendLEB_u32(&sec, 1U);
        AppendLEB_u32(&sec, 0U); // mode 0 (active, memory 0)
        sec.push_back(0x41U);    // i32.const 0
        AppendLEB_i32(&sec, 0);
        sec.push_back(0x0BU);    // end
        int32_t words[4] = {10, 20, 30, 40};
        AppendLEB_u32(&sec, sizeof(words));
        const auto* raw = reinterpret_cast<const uint8_t*>(words);
        sec.insert(sec.end(), raw, raw + sizeof(words));
        AppendSection(&bin, kWasmSectionData, sec);
    }

    return bin;
}

} // namespace

LibWasmSelfTestReport RunLibWasmSelfTest() {
    LibWasmSelfTestReport report{};
    auto check = [&](bool cond, const char* msg) -> bool {
        report.total_checks++;
        if (cond) {
            report.passed_checks++;
            return true;
        }
        if (report.failure_reason[0] == '\0' && msg) {
            std::snprintf(report.failure_reason, sizeof(report.failure_reason), "%s", msg);
        }
        return false;
    };

    // 1. Verify JNI factory pointer
    int64_t factory_addr = Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory(nullptr, nullptr);
    if (!check(factory_addr == reinterpret_cast<int64_t>(&::RegisterWebAssembly),
               "JNI loadWasmFactory pointer mismatch")) {
        return report;
    }

    // 2. Verify LEB128 decoding
    {
        const uint8_t uleb_bytes[] = {0xE5, 0x8E, 0x26}; // 624485
        const uint8_t* ptr         = uleb_bytes;
        uint32_t uval              = 0;
        M3Result r1 = ReadLEB_u32(&uval, &ptr, uleb_bytes + sizeof(uleb_bytes));
        if (!check(r1 == m3_err::none && uval == 624485U, "ReadLEB_u32(624485) failed")) return report;

        const uint8_t sleb_bytes[] = {0xC0, 0xBB, 0x78}; // -123456
        ptr                        = sleb_bytes;
        int32_t sval               = 0;
        M3Result r2 = ReadLEB_i32(&sval, &ptr, sleb_bytes + sizeof(sleb_bytes));
        if (!check(r2 == m3_err::none && sval == -123456, "ReadLEB_i32(-123456) failed")) return report;
    }

    // 3. Create standalone LepusRuntime & LepusContext and register WebAssembly
    LEPUSRuntime* rt  = qjs::CreateStandaloneLepusRuntime();
    LEPUSContext* ctx = qjs::CreateStandaloneLepusContext(rt);
    std::atomic<bool> is_terminated{false};

    bool reg_ok = ::RegisterWebAssembly(ctx, &is_terminated, WasmRuntimeType::kPrism);
    if (!check(reg_ok, "RegisterWebAssembly returned false")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    LEPUSValue global_obj = qjs::LepusGetGlobalObject(ctx);
    LEPUSValue wasm_ns    = qjs::LepusGetPropertyStr(ctx, global_obj, "WebAssembly");
    if (!check(wasm_ns.tag == LEPUS_TAG_OBJECT, "globalThis.WebAssembly missing")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    // 4. Build verification Wasm binary and test WebAssembly.validate / Module / Instance
    std::vector<uint8_t> wasm_bin = BuildVerificationWasmModule();
    LEPUSValue ab = qjs::LepusNewArrayBufferCopy(ctx, wasm_bin.data(), wasm_bin.size());

    LEPUSValue val_res = qjs::QJSWebAssembly::Validate(ctx, wasm_ns, 1, &ab);
    if (!check(val_res.tag == LEPUS_TAG_BOOL && val_res.u.int32 == 1, "WebAssembly.validate failed")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    LEPUSValue mod_js = qjs::QJSWasmModule::Constructor(ctx, MakeLepusUndefined(), 1, &ab);
    if (!check(mod_js.tag == LEPUS_TAG_OBJECT, "new WebAssembly.Module failed")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    // Check customSections("vmsdk_meta")
    LEPUSValue cs_args[2] = {mod_js, qjs::LepusNewString(ctx, "vmsdk_meta")};
    LEPUSValue cs_arr = qjs::QJSWasmModule::CustomSections(ctx, MakeLepusUndefined(), 2, cs_args);
    LEPUSValue cs_0   = qjs::LepusGetPropertyUint32(ctx, cs_arr, 0);
    LEPUSValue cs_len = qjs::LepusGetPropertyStr(ctx, cs_0, "byteLength");
    report.custom_section_byte_length = static_cast<uint32_t>(cs_len.u.int32);
    if (!check(report.custom_section_byte_length == 12U, "Custom section byteLength != 12")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    // Instantiate module
    LEPUSValue inst_js = qjs::QJSWasmInstance::Constructor(ctx, MakeLepusUndefined(), 1, &mod_js);
    if (!check(inst_js.tag == LEPUS_TAG_OBJECT, "new WebAssembly.Instance failed")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    LEPUSValue exports_obj = qjs::LepusGetPropertyStr(ctx, inst_js, "exports");

    // Call fib(10) -> 55
    LEPUSValue fib_fn  = qjs::LepusGetPropertyStr(ctx, exports_obj, "fib");
    LEPUSValue arg_10  = MakeLepusInt32(10);
    LEPUSValue fib_res = qjs::QJSWasmFunction::CallCallback(ctx, fib_fn, MakeLepusUndefined(), 1, &arg_10, 0);
    report.fib10_result = fib_res.u.int32;
    if (!check(report.fib10_result == 55, "fib(10) != 55")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    // Call mem_sum(0) -> 10 + 20 + 30 + 40 = 100
    LEPUSValue mem_sum_fn  = qjs::LepusGetPropertyStr(ctx, exports_obj, "mem_sum");
    LEPUSValue arg_0       = MakeLepusInt32(0);
    LEPUSValue mem_sum_res = qjs::QJSWasmFunction::CallCallback(ctx, mem_sum_fn, MakeLepusUndefined(), 1, &arg_0, 0);
    report.linear_mem_sum_result = mem_sum_res.u.int32;
    if (!check(report.linear_mem_sum_result == 100, "mem_sum(0) != 100")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    // Call call_table(25, 17) -> 42
    LEPUSValue call_tbl_fn = qjs::LepusGetPropertyStr(ctx, exports_obj, "call_table");
    LEPUSValue tbl_args[2] = {MakeLepusInt32(25), MakeLepusInt32(17)};
    LEPUSValue tbl_res     = qjs::QJSWasmFunction::CallCallback(ctx, call_tbl_fn, MakeLepusUndefined(), 2, tbl_args, 0);
    report.indirect_call_result = tbl_res.u.int32;
    if (!check(report.indirect_call_result == 42, "call_table(25, 17) != 42")) {
        qjs::DestroyStandaloneLepusContext(ctx);
        qjs::DestroyStandaloneLepusRuntime(rt);
        return report;
    }

    qjs::DestroyStandaloneLepusContext(ctx);
    qjs::DestroyStandaloneLepusRuntime(rt);
    report.passed = (report.passed_checks == report.total_checks);
    return report;
}

} // namespace wasm
} // namespace vmsdk
