/**
 * @file wasm_qjs_bindings.cpp
 * @brief Implementation of QuickJS / LepusNG WebAssembly JS API Bindings (`QJSWebAssembly`)
 *        Triển khai lớp kết nối API JavaScript WebAssembly cho QuickJS / LepusNG (`QJSWebAssembly`)
 *
 * @details
 * Clean-room C++17 reconstruction of `libwasm.so` QuickJS/LepusNG bindings
 * (`.text 0x01003c..0x021880`, `.data.rel.ro 0x0380b0..0x038430`, `.bss 0x03c000..0x03c054`).
 *
 * Evidence Classification / Phân loại bằng chứng:
 * - [OBSERVED]:
 *   - `RegisterWebAssembly` (`0x01003c..0x011344`, size `4,872 bytes`):
 *     - Null-check on `LEPUSContext*` (`0x010054: cbz x0, #0x109f4`) -> logs
 *       `"Register WebAssembly with invalid js context!"` (`.rodata 0x006ea4`).
 *     - Queries `GetSettingsWithKey("vmsdk_wasm_runtime_type")` (`0x01005c..0x010064`).
 *       When PRISM runtime is requested, logs warning via `__android_log_print(5, "VmsdkWasmWarn", ...)`
 *       (`0x01007c: mov w0, #5` = `0x528000A0`):
 *       `"[VmSdkWasm] PRISM runtime requested but not built into libwasm.so; falling back to WASM3."`
 *     - Registers 7 `JSClassDef` classes in `.data.rel.ro 0x0380b0..0x038378` and stores their
 *       `JSClassID`s in `.bss 0x03c000..0x03c018`.
 *     - Allocates `InteropRuntime` (`0x78` = 120 bytes @ `0x01020c`) and `Wasm3Runtime`
 *       (`0x20` = 32 bytes @ `0x01026c`).
 *   - `Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory` (`0x0117d8..0x0117e0`,
 *     size `12 bytes`):
 *     - `0x0117d8`: `adrp x0, #0x3b000` (`0xD0000140`)
 *     - `0x0117dc`: `ldr x0, [x0, #0xae0]` (`0xF9457000`) -> loads `&RegisterWebAssembly`
 *     - `0x0117e0`: `ret` (`0xD65F03C0`).
 */

#include "wasm_qjs_bindings.h"
#include "wasm_m3_compile_exec.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <vector>

namespace vmsdk {

namespace wasm {

/**
 * @brief Internal definitions of `LEPUSRuntime` and `LEPUSContext` for standalone execution.
 *        Định nghĩa nội bộ của `LEPUSRuntime` và `LEPUSContext` phục vụ thực thi độc lập.
 */
struct LEPUSRuntime {
    uint32_t next_class_id = 100U;
    std::unordered_map<JSClassID, JSClassDef> class_defs;
    std::vector<std::unique_ptr<qjs::LepusHeapObject>> heap_objects;
};

struct LEPUSContext {
    LEPUSRuntime* runtime = nullptr;
    LEPUSValue global_obj = MakeLepusUndefined();
    LEPUSValue last_exception = MakeLepusUndefined();
    InteropRuntime* interop_runtime = nullptr;
    std::unordered_map<JSClassID, LEPUSValue> class_protos;
    std::vector<std::string> string_pool;
};

InteropRuntime* InteropRuntime::FromContext(LEPUSContext* ctx) {
    return ctx ? ctx->interop_runtime : nullptr;
}

} // namespace wasm

namespace qjs {

namespace {

// ============================================================================
// 1. Global Class IDs in `.bss 0x03c000..0x03c054` ([OBSERVED])
//    Các biến toàn cục lưu `JSClassID` tại `.bss 0x03c000..0x03c054`
// ============================================================================

wasm::JSClassID g_webassembly_class_id = 0; // .bss 0x03c000
wasm::JSClassID g_function_class_id    = 0; // .bss 0x03c004
wasm::JSClassID g_global_class_id      = 0; // .bss 0x03c008
wasm::JSClassID g_table_class_id       = 0; // .bss 0x03c00c
wasm::JSClassID g_memory_class_id      = 0; // .bss 0x03c010
wasm::JSClassID g_instance_class_id    = 0; // .bss 0x03c014
wasm::JSClassID g_module_class_id      = 0; // .bss 0x03c018

// ============================================================================
// 2. `.data.rel.ro` `JSClassDef` & `JSCFunctionListEntry` Tables ([OBSERVED])
//    Các bảng `JSClassDef` và `JSCFunctionListEntry` trong `.data.rel.ro`
// ============================================================================

// .data.rel.ro 0x0380b0: "WebAssembly"
const wasm::JSClassDef kWebAssemblyClassDef = {
    "WebAssembly",
    &QJSWebAssembly::Finalizer, // 0x011bd8
    &QJSWebAssembly::GCMark,    // 0x012084
    nullptr,
    nullptr
};

// .data.rel.ro 0x0380d8: WebAssembly static methods (3 entries * 40B = 120B)
const wasm::JSCFunctionListEntry kWebAssemblyFuncs[3] = {
    {"compile",     wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWebAssembly::Compile}},     0},
    {"instantiate", wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWebAssembly::Instantiate}}, 0},
    {"validate",    wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWebAssembly::Validate}},    0},
};

// .data.rel.ro 0x038148: "WebAssembly.Function"
const wasm::JSClassDef kWasmFunctionClassDef = {
    "WebAssembly.Function",
    &QJSWasmFunction::Finalizer,   // 0x013128
    nullptr,
    &QJSWasmFunction::CallCallback,// 0x0132b8
    nullptr
};

// .data.rel.ro 0x038188: "WebAssembly.Global"
const wasm::JSClassDef kWasmGlobalClassDef = {
    "WebAssembly.Global",
    &QJSWasmGlobal::Finalizer, // 0x014290
    nullptr,
    nullptr,
    nullptr
};

// .data.rel.ro 0x0381b0: WebAssembly.Global.prototype (2 entries * 40B = 80B)
wasm::JSCFunctionListEntry MakeGetSetEntry(const char* name, uint8_t flags,
                                           wasm::JSGetterFunc getter, wasm::JSSetterFunc setter) {
    wasm::JSCFunctionListEntry e{};
    e.name         = name;
    e.prop_flags   = flags;
    e.def_type     = wasm::LEPUS_DEF_CGETSET;
    e.u.getset.get = getter;
    e.u.getset.set = setter;
    return e;
}

// .data.rel.ro 0x0381f0: "WebAssembly.Instance"
const wasm::JSClassDef kWasmInstanceClassDef = {
    "WebAssembly.Instance",
    &QJSWasmInstance::Finalizer, // 0x01b8cc
    nullptr,
    nullptr,
    nullptr
};

// .data.rel.ro 0x038248: "WebAssembly.Memory"
const wasm::JSClassDef kWasmMemoryClassDef = {
    "WebAssembly.Memory",
    &QJSWasmMemory::Finalizer, // 0x01ba18
    &QJSWasmMemory::GCMark,    // 0x01ce7c
    nullptr,
    nullptr
};

// .data.rel.ro 0x0382b8: "WebAssembly.Module"
const wasm::JSClassDef kWasmModuleClassDef = {
    "WebAssembly.Module",
    &QJSWasmModule::Finalizer, // 0x01f2f4
    &QJSWasmModule::GCMark,    // 0x01f42c
    nullptr,
    nullptr
};

// .data.rel.ro 0x038378: "WebAssembly.Table"
const wasm::JSClassDef kWasmTableClassDef = {
    "WebAssembly.Table",
    &QJSWasmTable::Finalizer, // 0x01f4d8
    nullptr,
    nullptr,
    nullptr
};

// ============================================================================
// 3. Internal Object Helpers for Standalone LepusContext
//    Các hàm trợ giúp thao tác đối tượng trên LepusContext
// ============================================================================

LepusHeapObject* GetHeapObj(wasm::LEPUSValue val) noexcept {
    if (val.tag == wasm::LEPUS_TAG_OBJECT || val.tag == wasm::LEPUS_TAG_LEPUS_REF ||
        val.tag == wasm::LEPUS_TAG_STRING) {
        return static_cast<LepusHeapObject*>(val.u.ptr);
    }
    return nullptr;
}

wasm::LEPUSValue AllocObjectWithClass(wasm::LEPUSContext* ctx, wasm::JSClassID class_id) {
    if (!ctx || !ctx->runtime) {
        return wasm::MakeLepusUndefined();
    }
    auto obj = std::make_unique<LepusHeapObject>();
    obj->class_id = class_id;
    LepusHeapObject* raw = obj.get();
    ctx->runtime->heap_objects.push_back(std::move(obj));
    wasm::LEPUSValue v{};
    v.u.ptr = raw;
    v.tag   = wasm::LEPUS_TAG_OBJECT;
    return v;
}

wasm::LEPUSValue AllocCFunctionObj(wasm::LEPUSContext* ctx, wasm::JSCFunction fn,
                                   const char* name, int length) {
    wasm::LEPUSValue v = AllocObjectWithClass(ctx, 1U);
    LepusHeapObject* o = GetHeapObj(v);
    if (o) {
        o->cfunc        = fn;
        o->cfunc_name   = name ? name : "";
        o->cfunc_length = length;
    }
    return v;
}

void AttachFunctionList(wasm::LEPUSContext* ctx, wasm::LEPUSValue target,
                        const wasm::JSCFunctionListEntry* entries, size_t count) {
    LepusHeapObject* o = GetHeapObj(target);
    if (!ctx || !o || !entries) return;
    for (size_t i = 0; i < count; ++i) {
        const auto& e = entries[i];
        LepusPropertyEntry prop{};
        prop.flags = e.prop_flags;
        if (e.def_type == wasm::LEPUS_DEF_CFUNC) {
            prop.is_accessor = false;
            prop.value = AllocCFunctionObj(ctx, e.u.func.generic, e.name, e.u.func.length);
        } else {
            prop.is_accessor = true;
            prop.getter      = e.u.getset.get;
            prop.setter      = e.u.getset.set;
        }
        o->properties[e.name] = prop;
    }
}

wasm::LEPUSValue ThrowWasmError(wasm::LEPUSContext* ctx, wasm::WasmErrorCode code,
                                const char* detail) {
    if (!ctx) return wasm::MakeLepusException();
    const char* prefix = "[1010] Unknown Error";
    switch (code) {
        case wasm::WasmErrorCode::kInvalidArguments:    prefix = "[1001] Invalid arguments"; break;
        case wasm::WasmErrorCode::kOutOfMemory:         prefix = "[1002] Out of Memory"; break;
        case wasm::WasmErrorCode::kRuntimeException:    prefix = "[1003] Runtime Exception"; break;
        case wasm::WasmErrorCode::kInstantiateError:    prefix = "[1004] Instantiate Error"; break;
        case wasm::WasmErrorCode::kCompileError:        prefix = "[1005] Compile Error"; break;
        case wasm::WasmErrorCode::kUnreachableError:    prefix = "[1006] Unreachable Error"; break;
        case wasm::WasmErrorCode::kLinkError:           prefix = "[1007] Link Error"; break;
        case wasm::WasmErrorCode::kExceededMemoryLimit: prefix = "[1008] Exceeded Memory Limit"; break;
        case wasm::WasmErrorCode::kInvalidMemoryAccess: prefix = "[1009] Invalid Memory Access"; break;
        default: break;
    }
    std::string msg = prefix;
    if (detail && *detail) {
        msg += ": ";
        msg += detail;
    }
    wasm::LEPUSValue err_obj = LepusNewObject(ctx);
    LepusHeapObject* o = GetHeapObj(err_obj);
    if (o) {
        o->is_error = true;
    }
    LepusSetPropertyStr(ctx, err_obj, "message", LepusNewString(ctx, msg.c_str()));
    ctx->last_exception = err_obj;
    return wasm::MakeLepusException();
}

bool ToInt32Val(wasm::LEPUSValue val, int32_t* out) noexcept {
    if (!out) return false;
    if (val.tag == wasm::LEPUS_TAG_INT || val.tag == wasm::LEPUS_TAG_BOOL) {
        *out = val.u.int32;
        return true;
    }
    if (val.tag == wasm::LEPUS_TAG_FLOAT64) {
        *out = static_cast<int32_t>(val.u.float64);
        return true;
    }
    return false;
}

bool ToFloat64Val(wasm::LEPUSValue val, double* out) noexcept {
    if (!out) return false;
    if (val.tag == wasm::LEPUS_TAG_FLOAT64) {
        *out = val.u.float64;
        return true;
    }
    if (val.tag == wasm::LEPUS_TAG_INT || val.tag == wasm::LEPUS_TAG_BOOL) {
        *out = static_cast<double>(val.u.int32);
        return true;
    }
    return false;
}

} // namespace

// ============================================================================
// 4. Standalone LepusRuntime / LepusContext Host API
//    Triển khai các hàm tạo và thao tác `LEPUSContext` độc lập
// ============================================================================

wasm::LEPUSRuntime* CreateStandaloneLepusRuntime() {
    return new wasm::LEPUSRuntime();
}

void DestroyStandaloneLepusRuntime(wasm::LEPUSRuntime* rt) {
    if (!rt) return;
    // Run class finalizers on remaining heap objects
    for (auto& obj_ptr : rt->heap_objects) {
        if (obj_ptr && obj_ptr->opaque) {
            auto it = rt->class_defs.find(obj_ptr->class_id);
            if (it != rt->class_defs.end() && it->second.finalizer) {
                wasm::LEPUSValue v{};
                v.u.ptr = obj_ptr.get();
                v.tag   = wasm::LEPUS_TAG_OBJECT;
                it->second.finalizer(rt, v);
            }
        }
    }
    delete rt;
}

wasm::LEPUSContext* CreateStandaloneLepusContext(wasm::LEPUSRuntime* rt) {
    if (!rt) return nullptr;
    auto* ctx = new wasm::LEPUSContext();
    ctx->runtime    = rt;
    ctx->global_obj = AllocObjectWithClass(ctx, 1U);
    return ctx;
}

void DestroyStandaloneLepusContext(wasm::LEPUSContext* ctx) {
    if (!ctx) return;
    delete ctx;
}

wasm::LEPUSValue LepusNewString(wasm::LEPUSContext* ctx, const char* str) {
    if (!ctx || !ctx->runtime) return wasm::MakeLepusUndefined();
    auto obj = std::make_unique<LepusHeapObject>();
    obj->string_value = str ? str : "";
    LepusHeapObject* raw = obj.get();
    ctx->runtime->heap_objects.push_back(std::move(obj));
    wasm::LEPUSValue v{};
    v.u.ptr = raw;
    v.tag   = wasm::LEPUS_TAG_STRING;
    return v;
}

wasm::LEPUSValue LepusNewObject(wasm::LEPUSContext* ctx) {
    return AllocObjectWithClass(ctx, 1U);
}

wasm::LEPUSValue LepusNewArray(wasm::LEPUSContext* ctx) {
    wasm::LEPUSValue v = AllocObjectWithClass(ctx, 2U);
    LepusHeapObject* o = GetHeapObj(v);
    if (o) {
        o->is_array = true;
    }
    return v;
}

wasm::LEPUSValue LepusNewArrayBufferCopy(wasm::LEPUSContext* ctx, const uint8_t* data, size_t size) {
    wasm::LEPUSValue v = AllocObjectWithClass(ctx, 3U);
    LepusHeapObject* o = GetHeapObj(v);
    if (o) {
        if (data && size > 0) {
            o->buffer_storage.assign(data, data + size);
        } else {
            o->buffer_storage.resize(size, 0);
        }
        LepusSetPropertyStr(ctx, v, "byteLength", wasm::MakeLepusInt32(static_cast<int32_t>(size)));
    }
    return v;
}

wasm::LEPUSValue LepusGetGlobalObject(wasm::LEPUSContext* ctx) {
    return ctx ? ctx->global_obj : wasm::MakeLepusUndefined();
}

wasm::LEPUSValue LepusGetPropertyStr(wasm::LEPUSContext* ctx, wasm::LEPUSValue obj, const char* prop) {
    LepusHeapObject* o = GetHeapObj(obj);
    if (!o || !prop) return wasm::MakeLepusUndefined();
    auto it = o->properties.find(prop);
    if (it != o->properties.end()) {
        if (it->second.is_accessor && it->second.getter) {
            return it->second.getter(ctx, obj);
        }
        return it->second.value;
    }
    // Check class prototype
    if (ctx && o->class_id != 0) {
        auto pit = ctx->class_protos.find(o->class_id);
        if (pit != ctx->class_protos.end()) {
            LepusHeapObject* po = GetHeapObj(pit->second);
            if (po) {
                auto pprop = po->properties.find(prop);
                if (pprop != po->properties.end()) {
                    if (pprop->second.is_accessor && pprop->second.getter) {
                        return pprop->second.getter(ctx, obj);
                    }
                    return pprop->second.value;
                }
            }
        }
    }
    return wasm::MakeLepusUndefined();
}

int LepusSetPropertyStr(wasm::LEPUSContext* ctx, wasm::LEPUSValue obj, const char* prop, wasm::LEPUSValue val) {
    LepusHeapObject* o = GetHeapObj(obj);
    if (!o || !prop) return -1;
    auto it = o->properties.find(prop);
    if (it != o->properties.end() && it->second.is_accessor && it->second.setter) {
        wasm::LEPUSValue r = it->second.setter(ctx, obj, val);
        return (r.tag == wasm::LEPUS_TAG_EXCEPTION) ? -1 : 0;
    }
    if (ctx && o->class_id != 0) {
        auto pit = ctx->class_protos.find(o->class_id);
        if (pit != ctx->class_protos.end()) {
            LepusHeapObject* po = GetHeapObj(pit->second);
            if (po) {
                auto pprop = po->properties.find(prop);
                if (pprop != po->properties.end() && pprop->second.is_accessor && pprop->second.setter) {
                    wasm::LEPUSValue r = pprop->second.setter(ctx, obj, val);
                    return (r.tag == wasm::LEPUS_TAG_EXCEPTION) ? -1 : 0;
                }
            }
        }
    }
    LepusPropertyEntry entry{};
    entry.value = val;
    o->properties[prop] = entry;
    return 0;
}

wasm::LEPUSValue LepusGetPropertyUint32(wasm::LEPUSContext* ctx, wasm::LEPUSValue obj, uint32_t idx) {
    LepusHeapObject* o = GetHeapObj(obj);
    if (!o) return wasm::MakeLepusUndefined();
    if (o->is_array && idx < o->array_elements.size()) {
        return o->array_elements[idx];
    }
    return LepusGetPropertyStr(ctx, obj, std::to_string(idx).c_str());
}

int LepusSetPropertyUint32(wasm::LEPUSContext* ctx, wasm::LEPUSValue obj, uint32_t idx, wasm::LEPUSValue val) {
    LepusHeapObject* o = GetHeapObj(obj);
    if (!o) return -1;
    if (o->is_array) {
        if (idx >= o->array_elements.size()) {
            o->array_elements.resize(static_cast<size_t>(idx) + 1U, wasm::MakeLepusUndefined());
        }
        o->array_elements[idx] = val;
        LepusSetPropertyStr(ctx, obj, "length", wasm::MakeLepusInt32(static_cast<int32_t>(o->array_elements.size())));
        return 0;
    }
    return LepusSetPropertyStr(ctx, obj, std::to_string(idx).c_str(), val);
}

const char* LepusToCString(wasm::LEPUSContext*, wasm::LEPUSValue val) {
    LepusHeapObject* o = GetHeapObj(val);
    if (o && val.tag == wasm::LEPUS_TAG_STRING) {
        return o->string_value.c_str();
    }
    return nullptr;
}

// ============================================================================
// 5. QJSWasmModule Implementation ([OBSERVED] in .text 0x01cf28..0x01f45c)
//    Triển khai `QJSWasmModule` (`WebAssembly.Module`)
// ============================================================================

QJSWasmModule::QJSWasmModule(wasm::LEPUSContext* ctx,
                             std::shared_ptr<wasm::Wasm3Module> m3_module,
                             const uint8_t* raw_bytes,
                             size_t raw_size)
    : ctx_(ctx),
      module_(std::move(m3_module)),
      raw_bytes_(raw_bytes, raw_bytes + raw_size) {}

QJSWasmModule::~QJSWasmModule() = default;

wasm::LEPUSValue QJSWasmModule::Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                            int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x01cf28..0x01d0bc: WebAssembly.Module(bufferSource, decodeBase64?)
    if (!ctx || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Module requires at least 1 argument");
    }
    bool allow_base64 = (argc >= 2 && argv[1].tag == wasm::LEPUS_TAG_BOOL && argv[1].u.int32 != 0);
    std::vector<uint8_t> bytes;
    std::string err_str;
    if (!QJSWebAssembly::ExtractWasmBinary(ctx, argv[0], allow_base64, &bytes, &err_str)) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments, err_str.c_str());
    }

    auto* interop = wasm::InteropRuntime::FromContext(ctx);
    if (!interop || !interop->wasm3_runtime) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kCompileError, "Wasm3Runtime not initialized");
    }

    wasm::M3Result parse_err = nullptr;
    auto m3_mod = interop->wasm3_runtime->ParseModule(bytes.data(), bytes.size(), &parse_err);
    if (!m3_mod || parse_err) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kCompileError,
                              parse_err ? parse_err : "Failed to parse WebAssembly module");
    }
    wasm::M3Result comp_err = wasm::m3_CompileModule(m3_mod->raw_module());
    if (comp_err) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kCompileError, comp_err);
    }

    auto* wrapper = new QJSWasmModule(ctx, m3_mod, bytes.data(), bytes.size());
    wasm::LEPUSValue js_obj = AllocObjectWithClass(ctx, g_module_class_id);
    LepusHeapObject* o = GetHeapObj(js_obj);
    if (o) {
        o->opaque = wrapper;
    }
    wrapper->js_self_.Reset(ctx, js_obj);
    return js_obj;
}

wasm::LEPUSValue QJSWasmModule::CustomSections(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                               int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x01dbd4..0x01dbdf -> 0x01dc00: WebAssembly.Module.customSections(moduleObject, sectionName)
    if (!ctx || argc < 2 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Module.customSections requires (module, sectionName)");
    }
    LepusHeapObject* mod_obj = GetHeapObj(argv[0]);
    if (!mod_obj || mod_obj->class_id != g_module_class_id || !mod_obj->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "First argument must be a WebAssembly.Module");
    }
    const char* sec_name = LepusToCString(ctx, argv[1]);
    if (!sec_name) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "Second argument must be a string");
    }

    auto* qjs_mod = static_cast<QJSWasmModule*>(mod_obj->opaque);
    auto sections = qjs_mod->module()->custom_sections(sec_name);
    wasm::LEPUSValue arr = LepusNewArray(ctx);
    for (uint32_t i = 0; i < sections.size(); ++i) {
        wasm::LEPUSValue ab = LepusNewArrayBufferCopy(ctx, sections[i].data, sections[i].dataSize);
        LepusSetPropertyUint32(ctx, arr, i, ab);
    }
    return arr;
}

wasm::LEPUSValue QJSWasmModule::Exports(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                        int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x01dbe0..0x01e5a0: WebAssembly.Module.exports(moduleObject)
    // Returns Array of { name: string, kind: "function"|"table"|"memory"|"global" }
    if (!ctx || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Module.exports requires 1 argument");
    }
    LepusHeapObject* mod_obj = GetHeapObj(argv[0]);
    if (!mod_obj || mod_obj->class_id != g_module_class_id || !mod_obj->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "Argument must be a WebAssembly.Module");
    }
    auto* qjs_mod = static_cast<QJSWasmModule*>(mod_obj->opaque);
    const auto& exps = qjs_mod->module()->exports();
    wasm::LEPUSValue arr = LepusNewArray(ctx);
    for (uint32_t i = 0; i < exps.size(); ++i) {
        wasm::LEPUSValue item = LepusNewObject(ctx);
        const char* kind_str = "function";
        switch (exps[i].kind) {
            case wasm::kWasmExtFunc:   kind_str = "function"; break;
            case wasm::kWasmExtTable:  kind_str = "table";    break;
            case wasm::kWasmExtMemory: kind_str = "memory";   break;
            case wasm::kWasmExtGlobal: kind_str = "global";   break;
        }
        LepusSetPropertyStr(ctx, item, "name", LepusNewString(ctx, exps[i].name.c_str()));
        LepusSetPropertyStr(ctx, item, "kind", LepusNewString(ctx, kind_str));
        LepusSetPropertyUint32(ctx, arr, i, item);
    }
    return arr;
}

wasm::LEPUSValue QJSWasmModule::Imports(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                        int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x01f2dc..0x01f2e3: WebAssembly.Module.imports(moduleObject)
    // Returns Array of { module: string, name: string, kind: "function"|"table"|"memory"|"global" }
    if (!ctx || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Module.imports requires 1 argument");
    }
    LepusHeapObject* mod_obj = GetHeapObj(argv[0]);
    if (!mod_obj || mod_obj->class_id != g_module_class_id || !mod_obj->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "Argument must be a WebAssembly.Module");
    }
    auto* qjs_mod = static_cast<QJSWasmModule*>(mod_obj->opaque);
    const auto& imps = qjs_mod->module()->imports();
    wasm::LEPUSValue arr = LepusNewArray(ctx);
    for (uint32_t i = 0; i < imps.size(); ++i) {
        wasm::LEPUSValue item = LepusNewObject(ctx);
        const char* kind_str = "function";
        switch (imps[i].kind) {
            case wasm::kWasmExtFunc:   kind_str = "function"; break;
            case wasm::kWasmExtTable:  kind_str = "table";    break;
            case wasm::kWasmExtMemory: kind_str = "memory";   break;
            case wasm::kWasmExtGlobal: kind_str = "global";   break;
        }
        LepusSetPropertyStr(ctx, item, "module", LepusNewString(ctx, imps[i].moduleName.c_str()));
        LepusSetPropertyStr(ctx, item, "name",   LepusNewString(ctx, imps[i].fieldName.c_str()));
        LepusSetPropertyStr(ctx, item, "kind",   LepusNewString(ctx, kind_str));
        LepusSetPropertyUint32(ctx, arr, i, item);
    }
    return arr;
}

wasm::LEPUSValue QJSWasmModule::SupportBase64Getter(wasm::LEPUSContext*, wasm::LEPUSValue) {
    // [OBSERVED] 0x01f2e4..0x01f2f0: returns LEPUS_NewBool(ctx, true)
    // Getter `WebAssembly.Module.supportBase64` luôn trả về `true`
    return wasm::MakeLepusBool(true);
}

void QJSWasmModule::Finalizer(wasm::LEPUSRuntime*, wasm::LEPUSValue val) {
    // [OBSERVED] 0x01f2f4..0x01f428: deletes QJSWasmModule* opaque
    LepusHeapObject* o = GetHeapObj(val);
    if (o && o->opaque) {
        delete static_cast<QJSWasmModule*>(o->opaque);
        o->opaque = nullptr;
    }
}

void QJSWasmModule::GCMark(wasm::LEPUSRuntime*, wasm::LEPUSValue, void (*)(wasm::LEPUSRuntime*, void*)) {
    // [OBSERVED] 0x01f42c..0x01f45c: marks internal JSValue references during GC
}

// ============================================================================
// 6. QJSWasmMemory Implementation ([OBSERVED] in .text 0x01b920..0x01cf24)
//    Triển khai `QJSWasmMemory` (`WebAssembly.Memory`)
// ============================================================================

QJSWasmMemory::QJSWasmMemory(wasm::LEPUSContext* ctx, std::shared_ptr<wasm::Wasm3Memory> memory)
    : ctx_(ctx), memory_(std::move(memory)) {
    if (memory_) {
        memory_->SetDetachCallback([this](uint8_t*, size_t) {
            // Detach previous ArrayBuffer on memory.grow()
            LepusHeapObject* buf_obj = GetHeapObj(buffer_persistent_.Get());
            if (buf_obj) {
                buf_obj->is_detached_buffer = true;
                buf_obj->external_buffer = nullptr;
                buf_obj->external_buffer_size = 0;
            }
            buffer_persistent_.Reset();
        });
    }
}

QJSWasmMemory::~QJSWasmMemory() = default;

wasm::LEPUSValue QJSWasmMemory::GetOrCreateArrayBuffer(wasm::LEPUSContext* ctx) {
    if (!buffer_persistent_.IsEmpty()) {
        return buffer_persistent_.Get();
    }
    if (!ctx || !memory_) {
        return wasm::MakeLepusUndefined();
    }
    wasm::LEPUSValue ab = AllocObjectWithClass(ctx, 3U);
    LepusHeapObject* o = GetHeapObj(ab);
    if (o) {
        o->external_buffer      = memory_->data();
        o->external_buffer_size = memory_->byte_length();
        LepusSetPropertyStr(ctx, ab, "byteLength",
                            wasm::MakeLepusInt32(static_cast<int32_t>(memory_->byte_length())));
    }
    buffer_persistent_.Reset(ctx, ab);
    return ab;
}

int32_t QJSWasmMemory::Grow(wasm::LEPUSContext*, uint32_t delta_pages) {
    if (!memory_) return -1;
    return memory_->Grow(delta_pages);
}

wasm::LEPUSValue QJSWasmMemory::Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                            int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x01b920..0x01c87c: WebAssembly.Memory({ initial, maximum? })
    if (!ctx || argc < 1 || !argv || argv[0].tag != wasm::LEPUS_TAG_OBJECT) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Memory descriptor must be an object");
    }
    wasm::LEPUSValue init_val = LepusGetPropertyStr(ctx, argv[0], "initial");
    if (init_val.tag == wasm::LEPUS_TAG_UNDEFINED) {
        init_val = LepusGetPropertyStr(ctx, argv[0], "minimum");
    }
    int32_t initial_pages = 0;
    if (!ToInt32Val(init_val, &initial_pages) || initial_pages < 0 || initial_pages > 65536) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Memory 'initial' must be in [0, 65536]");
    }

    wasm::LEPUSValue max_val = LepusGetPropertyStr(ctx, argv[0], "maximum");
    bool has_max             = (max_val.tag != wasm::LEPUS_TAG_UNDEFINED);
    int32_t max_pages        = 65536;
    if (has_max) {
        if (!ToInt32Val(max_val, &max_pages) || max_pages < initial_pages || max_pages > 65536) {
            return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                                  "WebAssembly.Memory 'maximum' is out of bounds");
        }
    }

    auto mem = std::make_shared<wasm::Wasm3Memory>(
        static_cast<uint32_t>(initial_pages), static_cast<uint32_t>(max_pages), has_max);
    auto* wrapper = new QJSWasmMemory(ctx, mem);
    wasm::LEPUSValue js_obj = AllocObjectWithClass(ctx, g_memory_class_id);
    LepusHeapObject* o = GetHeapObj(js_obj);
    if (o) {
        o->opaque = wrapper;
    }
    return js_obj;
}

wasm::LEPUSValue QJSWasmMemory::GrowCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                             int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x01c880..0x01cce0: memory.grow(delta)
    LepusHeapObject* o = GetHeapObj(this_val);
    if (!o || o->class_id != g_memory_class_id || !o->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Memory.prototype.grow called on incompatible receiver");
    }
    int32_t delta = 0;
    if (argc < 1 || !argv || !ToInt32Val(argv[0], &delta) || delta < 0 || delta > 65536) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Memory.grow delta must be in [0, 65536]");
    }
    auto* wrapper = static_cast<QJSWasmMemory*>(o->opaque);
    int32_t prev  = wrapper->Grow(ctx, static_cast<uint32_t>(delta));
    if (prev < 0) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kExceededMemoryLimit,
                              "Unable to grow instance memory.");
    }
    return wasm::MakeLepusInt32(prev);
}

wasm::LEPUSValue QJSWasmMemory::BufferGetter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val) {
    // [OBSERVED] 0x01cce4..0x01ce78: memory.buffer getter
    LepusHeapObject* o = GetHeapObj(this_val);
    if (!o || o->class_id != g_memory_class_id || !o->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Memory.prototype.buffer called on incompatible receiver");
    }
    return static_cast<QJSWasmMemory*>(o->opaque)->GetOrCreateArrayBuffer(ctx);
}

void QJSWasmMemory::Finalizer(wasm::LEPUSRuntime*, wasm::LEPUSValue val) {
    LepusHeapObject* o = GetHeapObj(val);
    if (o && o->opaque) {
        delete static_cast<QJSWasmMemory*>(o->opaque);
        o->opaque = nullptr;
    }
}

void QJSWasmMemory::GCMark(wasm::LEPUSRuntime*, wasm::LEPUSValue, void (*)(wasm::LEPUSRuntime*, void*)) {}

// ============================================================================
// 7. QJSWasmTable Implementation ([OBSERVED] in .text 0x01f460..0x021880)
//    Triển khai `QJSWasmTable` (`WebAssembly.Table`)
// ============================================================================

QJSWasmTable::QJSWasmTable(wasm::LEPUSContext* ctx, std::shared_ptr<wasm::Wasm3Table> table)
    : ctx_(ctx), table_(std::move(table)) {}

QJSWasmTable::~QJSWasmTable() = default;

wasm::LEPUSValue QJSWasmTable::Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                           int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x01f460..0x01f668: WebAssembly.Table({ element, initial, maximum? })
    if (!ctx || argc < 1 || !argv || argv[0].tag != wasm::LEPUS_TAG_OBJECT) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table descriptor must be an object");
    }
    const char* elem_str = LepusToCString(ctx, LepusGetPropertyStr(ctx, argv[0], "element"));
    if (!elem_str || (std::strcmp(elem_str, "anyfunc") != 0 &&
                      std::strcmp(elem_str, "funcref") != 0 &&
                      std::strcmp(elem_str, "externref") != 0)) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "Descriptor property 'element' must be a WebAssembly reference type");
    }
    wasm::M3ValueType elem_type = (std::strcmp(elem_str, "externref") == 0)
                                      ? wasm::c_m3Type_externref
                                      : wasm::c_m3Type_funcref;

    wasm::LEPUSValue init_val = LepusGetPropertyStr(ctx, argv[0], "initial");
    if (init_val.tag == wasm::LEPUS_TAG_UNDEFINED) {
        init_val = LepusGetPropertyStr(ctx, argv[0], "minimum");
    }
    int32_t initial_sz = 0;
    if (!ToInt32Val(init_val, &initial_sz) || initial_sz < 0) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table 'initial' must be non-negative");
    }

    wasm::LEPUSValue max_val = LepusGetPropertyStr(ctx, argv[0], "maximum");
    bool has_max             = (max_val.tag != wasm::LEPUS_TAG_UNDEFINED);
    int32_t max_sz           = 10000000;
    if (has_max) {
        if (!ToInt32Val(max_val, &max_sz) || max_sz < initial_sz) {
            return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                                  "WebAssembly.Table 'maximum' is less than 'initial'");
        }
    }

    auto tbl = std::make_shared<wasm::Wasm3Table>(
        elem_type, static_cast<uint32_t>(initial_sz), static_cast<uint32_t>(max_sz), has_max);
    auto* wrapper = new QJSWasmTable(ctx, tbl);
    wasm::LEPUSValue js_obj = AllocObjectWithClass(ctx, g_table_class_id);
    LepusHeapObject* o = GetHeapObj(js_obj);
    if (o) {
        o->opaque = wrapper;
    }
    return js_obj;
}

wasm::LEPUSValue QJSWasmTable::SetCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                           int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x01f66c..0x020148: table.set(index, value?)
    LepusHeapObject* o = GetHeapObj(this_val);
    if (!o || o->class_id != g_table_class_id || !o->opaque || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.set invalid arguments");
    }
    int32_t index = -1;
    if (!ToInt32Val(argv[0], &index) || index < 0) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.set index out of bounds");
    }
    auto* wrapper = static_cast<QJSWasmTable*>(o->opaque);
    wasm::LEPUSValue val = (argc >= 2) ? argv[1] : wasm::MakeLepusNull();
    std::shared_ptr<wasm::Wasm3Function> fn_ptr;
    if (val.tag != wasm::LEPUS_TAG_NULL && val.tag != wasm::LEPUS_TAG_UNDEFINED) {
        LepusHeapObject* fn_obj = GetHeapObj(val);
        if (fn_obj && fn_obj->class_id == g_function_class_id && fn_obj->opaque) {
            fn_ptr = static_cast<QJSWasmFunction*>(fn_obj->opaque)->function();
        } else if (wrapper->table()->element_type() == wasm::c_m3Type_funcref) {
            return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                                  "Argument 2 must be null or a WebAssembly function");
        }
    }
    if (!wrapper->table()->Set(static_cast<uint32_t>(index), fn_ptr, val)) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.set index out of range");
    }
    return wasm::MakeLepusUndefined();
}

wasm::LEPUSValue QJSWasmTable::GetCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                           int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x02014c..0x0210f4: table.get(index)
    LepusHeapObject* o = GetHeapObj(this_val);
    if (!o || o->class_id != g_table_class_id || !o->opaque || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.get invalid arguments");
    }
    int32_t index = -1;
    if (!ToInt32Val(argv[0], &index) || index < 0) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.get index out of bounds");
    }
    auto* wrapper  = static_cast<QJSWasmTable*>(o->opaque);
    bool bounds_ok = false;
    auto fn = wrapper->table()->GetFunction(static_cast<uint32_t>(index), &bounds_ok);
    if (!bounds_ok) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.get index out of range");
    }
    if (fn) {
        return QJSWasmFunction::CreateJSObject(ctx, fn);
    }
    return wrapper->table()->GetRawRef(static_cast<uint32_t>(index), &bounds_ok);
}

wasm::LEPUSValue QJSWasmTable::GrowCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                            int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x0210f8..0x021868: table.grow(delta, value?)
    LepusHeapObject* o = GetHeapObj(this_val);
    if (!o || o->class_id != g_table_class_id || !o->opaque || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.grow invalid arguments");
    }
    int32_t delta = -1;
    if (!ToInt32Val(argv[0], &delta) || delta < 0) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.grow delta must be non-negative");
    }
    auto* wrapper = static_cast<QJSWasmTable*>(o->opaque);
    int32_t prev  = wrapper->table()->Grow(static_cast<uint32_t>(delta));
    if (prev < 0) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kRuntimeException,
                              "WebAssembly.Table.grow failed to grow table");
    }
    return wasm::MakeLepusInt32(prev);
}

wasm::LEPUSValue QJSWasmTable::LengthGetter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val) {
    // [OBSERVED] 0x02186c..0x021880: table.length getter
    LepusHeapObject* o = GetHeapObj(this_val);
    if (!o || o->class_id != g_table_class_id || !o->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Table.length invalid receiver");
    }
    auto* wrapper = static_cast<QJSWasmTable*>(o->opaque);
    return wasm::MakeLepusInt32(static_cast<int32_t>(wrapper->table()->length()));
}

void QJSWasmTable::Finalizer(wasm::LEPUSRuntime*, wasm::LEPUSValue val) {
    LepusHeapObject* o = GetHeapObj(val);
    if (o && o->opaque) {
        delete static_cast<QJSWasmTable*>(o->opaque);
        o->opaque = nullptr;
    }
}

// ============================================================================
// 8. QJSWasmGlobal Implementation ([OBSERVED] in .text 0x013f60..0x01545c)
//    Triển khai `QJSWasmGlobal` (`WebAssembly.Global`)
// ============================================================================

QJSWasmGlobal::QJSWasmGlobal(wasm::LEPUSContext* ctx, std::shared_ptr<wasm::Wasm3Global> global)
    : ctx_(ctx), global_(std::move(global)) {}

QJSWasmGlobal::~QJSWasmGlobal() = default;

wasm::LEPUSValue QJSWasmGlobal::Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                            int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x013f60..0x01428c: WebAssembly.Global({ value, mutable? }, v?)
    if (!ctx || argc < 1 || !argv || argv[0].tag != wasm::LEPUS_TAG_OBJECT) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Global descriptor must be an object");
    }
    const char* type_str = LepusToCString(ctx, LepusGetPropertyStr(ctx, argv[0], "value"));
    if (!type_str) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "Descriptor property 'value' must be a WebAssembly type");
    }
    wasm::M3ValueType vtype = wasm::c_m3Type_none;
    if (std::strcmp(type_str, "i32") == 0) vtype = wasm::c_m3Type_i32;
    else if (std::strcmp(type_str, "i64") == 0) vtype = wasm::c_m3Type_i64;
    else if (std::strcmp(type_str, "f32") == 0) vtype = wasm::c_m3Type_f32;
    else if (std::strcmp(type_str, "f64") == 0) vtype = wasm::c_m3Type_f64;
    else {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "Unsupported WebAssembly.Global value type");
    }

    wasm::LEPUSValue mut_val = LepusGetPropertyStr(ctx, argv[0], "mutable");
    bool is_mut = (mut_val.tag == wasm::LEPUS_TAG_BOOL && mut_val.u.int32 != 0);

    auto g = std::make_shared<wasm::Wasm3Global>(vtype, true, 0);
    if (argc >= 2) {
        double num = 0.0;
        if (ToFloat64Val(argv[1], &num)) {
            if (vtype == wasm::c_m3Type_i32) g->SetI32(static_cast<int32_t>(num));
            else if (vtype == wasm::c_m3Type_i64) g->SetI64(static_cast<int64_t>(num));
            else if (vtype == wasm::c_m3Type_f32) g->SetF32(static_cast<float>(num));
            else if (vtype == wasm::c_m3Type_f64) g->SetF64(num);
        }
    }
    // Lock mutability to descriptor setting
    auto final_global = std::make_shared<wasm::Wasm3Global>(vtype, is_mut, g->GetRawBits());
    auto* wrapper     = new QJSWasmGlobal(ctx, final_global);
    wasm::LEPUSValue js_obj = AllocObjectWithClass(ctx, g_global_class_id);
    LepusHeapObject* o = GetHeapObj(js_obj);
    if (o) {
        o->opaque = wrapper;
    }
    return js_obj;
}

wasm::LEPUSValue QJSWasmGlobal::ValueOfCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                                int, wasm::LEPUSValue*) {
    // [OBSERVED] 0x014b3c: tail-calls ValueGetter (`b #0x14b40`)
    return ValueGetter(ctx, this_val);
}

wasm::LEPUSValue QJSWasmGlobal::ValueGetter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val) {
    // [OBSERVED] 0x014b40..0x014e24: returns current value of WebAssembly.Global
    LepusHeapObject* o = GetHeapObj(this_val);
    if (!o || o->class_id != g_global_class_id || !o->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Global.value getter called on incompatible receiver");
    }
    auto g = static_cast<QJSWasmGlobal*>(o->opaque)->global();
    switch (g->type()) {
        case wasm::c_m3Type_i32: return wasm::MakeLepusInt32(g->GetI32());
        case wasm::c_m3Type_i64: return wasm::MakeLepusInt32(static_cast<int32_t>(g->GetI64()));
        case wasm::c_m3Type_f32: return wasm::MakeLepusFloat64(static_cast<double>(g->GetF32()));
        case wasm::c_m3Type_f64: return wasm::MakeLepusFloat64(g->GetF64());
        default: return wasm::MakeLepusUndefined();
    }
}

wasm::LEPUSValue QJSWasmGlobal::ValueSetter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                            wasm::LEPUSValue val) {
    // [OBSERVED] 0x014e28..0x01545c: sets WebAssembly.Global value (checks is_mutable)
    LepusHeapObject* o = GetHeapObj(this_val);
    if (!o || o->class_id != g_global_class_id || !o->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Global.value setter called on incompatible receiver");
    }
    auto g = static_cast<QJSWasmGlobal*>(o->opaque)->global();
    if (!g->is_mutable()) {
        // [OBSERVED] .rodata 0x006ca2: "Can't set the value of an immutable global."
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "Can't set the value of an immutable global.");
    }
    double num = 0.0;
    if (!ToFloat64Val(val, &num)) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "Invalid value for WebAssembly.Global");
    }
    switch (g->type()) {
        case wasm::c_m3Type_i32: g->SetI32(static_cast<int32_t>(num)); break;
        case wasm::c_m3Type_i64: g->SetI64(static_cast<int64_t>(num)); break;
        case wasm::c_m3Type_f32: g->SetF32(static_cast<float>(num));   break;
        case wasm::c_m3Type_f64: g->SetF64(num);                       break;
        default: break;
    }
    return wasm::MakeLepusUndefined();
}

void QJSWasmGlobal::Finalizer(wasm::LEPUSRuntime*, wasm::LEPUSValue val) {
    LepusHeapObject* o = GetHeapObj(val);
    if (o && o->opaque) {
        delete static_cast<QJSWasmGlobal*>(o->opaque);
        o->opaque = nullptr;
    }
}

// ============================================================================
// 9. QJSWasmFunction Implementation ([OBSERVED] in .text 0x012e94..0x013f5c)
//    Triển khai `QJSWasmFunction` (`WebAssembly.Function`)
// ============================================================================

QJSWasmFunction::QJSWasmFunction(wasm::LEPUSContext* ctx, std::shared_ptr<wasm::Wasm3Function> func)
    : ctx_(ctx), func_(std::move(func)) {}

QJSWasmFunction::~QJSWasmFunction() = default;

wasm::LEPUSValue QJSWasmFunction::CreateJSObject(wasm::LEPUSContext* ctx,
                                                 std::shared_ptr<wasm::Wasm3Function> func) {
    // [OBSERVED] 0x012e94..0x013124: creates callable JS object with class_id = g_function_class_id,
    // defines `length` (arg count) and `name` (function index string).
    if (!ctx || !func) return wasm::MakeLepusUndefined();
    auto* wrapper = new QJSWasmFunction(ctx, func);
    wasm::LEPUSValue obj = AllocObjectWithClass(ctx, g_function_class_id);
    LepusHeapObject* o   = GetHeapObj(obj);
    if (o) {
        o->opaque       = wrapper;
        o->cfunc_length = static_cast<int>(func->arg_types().size());
        o->cfunc_name   = std::to_string(func->func_index());
    }
    LepusSetPropertyStr(ctx, obj, "length",
                        wasm::MakeLepusInt32(static_cast<int32_t>(func->arg_types().size())));
    LepusSetPropertyStr(ctx, obj, "name",
                        LepusNewString(ctx, std::to_string(func->func_index()).c_str()));
    return obj;
}

wasm::LEPUSValue QJSWasmFunction::CallCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue func_obj,
                                               wasm::LEPUSValue, int argc,
                                               wasm::LEPUSValue* argv, int) {
    // [OBSERVED] 0x0132b8..0x013f5c: marshals JS arguments -> WasmVal, calls Wasm3Function,
    // and marshals return value(s) back to LEPUSValue.
    LepusHeapObject* o = GetHeapObj(func_obj);
    if (!o || o->class_id != g_function_class_id || !o->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Function called on invalid object");
    }
    auto fn = static_cast<QJSWasmFunction*>(o->opaque)->function();
    if (!fn) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kRuntimeException, "Null Wasm function");
    }

    const auto& arg_types = fn->arg_types();
    std::vector<wasm::WasmVal> wasm_args(arg_types.size());
    for (size_t i = 0; i < arg_types.size(); ++i) {
        double num = 0.0;
        if (static_cast<int>(i) < argc && argv) {
            ToFloat64Val(argv[i], &num);
        }
        switch (arg_types[i]) {
            case wasm::c_m3Type_i32: wasm_args[i] = wasm::WasmVal::MakeI32(static_cast<int32_t>(num)); break;
            case wasm::c_m3Type_i64: wasm_args[i] = wasm::WasmVal::MakeI64(static_cast<int64_t>(num)); break;
            case wasm::c_m3Type_f32: wasm_args[i] = wasm::WasmVal::MakeF32(static_cast<float>(num));   break;
            case wasm::c_m3Type_f64: wasm_args[i] = wasm::WasmVal::MakeF64(num);                       break;
            default: wasm_args[i] = wasm::WasmVal::MakeI32(0); break;
        }
    }

    std::vector<wasm::WasmVal> wasm_rets;
    wasm::M3Result err = fn->Call(wasm_args, &wasm_rets);
    if (err) {
        wasm::WasmErrorCode code = wasm::WasmErrorCode::kRuntimeException;
        if (err == wasm::m3_err::trapUnreachable) code = wasm::WasmErrorCode::kUnreachableError;
        else if (err == wasm::m3_err::trapOutOfBoundsMemoryAccess) code = wasm::WasmErrorCode::kInvalidMemoryAccess;
        return ThrowWasmError(ctx, code, err);
    }

    if (wasm_rets.empty()) {
        return wasm::MakeLepusUndefined();
    }
    const auto& rv = wasm_rets[0];
    switch (rv.type) {
        case wasm::c_m3Type_i32: return wasm::MakeLepusInt32(rv.of.i32);
        case wasm::c_m3Type_i64: return wasm::MakeLepusInt32(static_cast<int32_t>(rv.of.i64));
        case wasm::c_m3Type_f32: return wasm::MakeLepusFloat64(static_cast<double>(rv.of.f32));
        case wasm::c_m3Type_f64: return wasm::MakeLepusFloat64(rv.of.f64);
        default: return wasm::MakeLepusUndefined();
    }
}

void QJSWasmFunction::Finalizer(wasm::LEPUSRuntime*, wasm::LEPUSValue val) {
    LepusHeapObject* o = GetHeapObj(val);
    if (o && o->opaque) {
        delete static_cast<QJSWasmFunction*>(o->opaque);
        o->opaque = nullptr;
    }
}

// ============================================================================
// 10. QJSWasmInstance Implementation ([OBSERVED] in .text 0x015460..0x01b8fc)
//     Triển khai `QJSWasmInstance` (`WebAssembly.Instance`)
// ============================================================================

QJSWasmInstance::QJSWasmInstance(wasm::LEPUSContext* ctx,
                                 std::shared_ptr<wasm::Wasm3Module> module,
                                 wasm::LEPUSValue exports_obj)
    : ctx_(ctx), module_(std::move(module)), exports_(ctx, exports_obj) {}

QJSWasmInstance::~QJSWasmInstance() = default;

wasm::LEPUSValue QJSWasmInstance::InstantiateFromModule(wasm::LEPUSContext* ctx,
                                                        QJSWasmModule* qjs_module,
                                                        wasm::LEPUSValue import_obj) {
    // [OBSERVED] 0x0156b0..0x018950:
    // Re-parses a fresh Wasm3Module instance from qjs_module->raw_bytes(), resolves imports
    // from `import_obj`, calls LoadAndInitialize(), and constructs `instance.exports`.
    if (!ctx || !qjs_module || !qjs_module->module()) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments, "Invalid WebAssembly.Module");
    }
    auto rt = qjs_module->module()->runtime();
    wasm::M3Result parse_err = nullptr;
    auto inst_mod = rt->ParseModule(qjs_module->raw_bytes().data(),
                                    qjs_module->raw_bytes().size(),
                                    &parse_err);
    if (!inst_mod || parse_err) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInstantiateError,
                              parse_err ? parse_err : "Failed to parse module for instance");
    }

    const auto& imps = inst_mod->imports();
    if (!imps.empty()) {
        uint32_t func_imp_idx   = 0;
        uint32_t global_imp_idx = 0;
        for (const auto& imp : imps) {
            // Allow built-in host imports (`_abort`, `_exit`, `_memcpy`, `_memmove`, `_memset`, `printf`, `clock_ms`, `_debug`)
            // even if `import_obj` is omitted.
            wasm::LEPUSValue mod_ns = wasm::MakeLepusUndefined();
            if (import_obj.tag == wasm::LEPUS_TAG_OBJECT) {
                mod_ns = LepusGetPropertyStr(ctx, import_obj, imp.moduleName.c_str());
            }
            wasm::LEPUSValue field_val = wasm::MakeLepusUndefined();
            if (mod_ns.tag == wasm::LEPUS_TAG_OBJECT) {
                field_val = LepusGetPropertyStr(ctx, mod_ns, imp.fieldName.c_str());
            }

            if (imp.kind == wasm::kWasmExtFunc) {
                LepusHeapObject* fn_ho = GetHeapObj(field_val);
                if (fn_ho && fn_ho->cfunc) {
                    wasm::JSCFunction cfn = fn_ho->cfunc;
                    inst_mod->BindImportFunction(
                        func_imp_idx,
                        [ctx, field_val, cfn](const std::vector<wasm::WasmVal>& args,
                                              std::vector<wasm::WasmVal>* rets) -> wasm::M3Result {
                            std::vector<wasm::LEPUSValue> js_args(args.size());
                            for (size_t i = 0; i < args.size(); ++i) {
                                if (args[i].type == wasm::c_m3Type_i32) {
                                    js_args[i] = wasm::MakeLepusInt32(args[i].of.i32);
                                } else if (args[i].type == wasm::c_m3Type_f64) {
                                    js_args[i] = wasm::MakeLepusFloat64(args[i].of.f64);
                                } else if (args[i].type == wasm::c_m3Type_f32) {
                                    js_args[i] = wasm::MakeLepusFloat64(args[i].of.f32);
                                } else {
                                    js_args[i] = wasm::MakeLepusInt32(static_cast<int32_t>(args[i].of.i64));
                                }
                            }
                            wasm::LEPUSValue r = cfn(ctx, wasm::MakeLepusUndefined(),
                                                     static_cast<int>(js_args.size()),
                                                     js_args.empty() ? nullptr : js_args.data());
                            if (r.tag == wasm::LEPUS_TAG_EXCEPTION) {
                                return wasm::m3_err::trapAbort;
                            }
                            if (rets && r.tag != wasm::LEPUS_TAG_UNDEFINED) {
                                int32_t iv = 0;
                                ToInt32Val(r, &iv);
                                rets->assign({wasm::WasmVal::MakeI32(iv)});
                            }
                            return wasm::m3_err::none;
                        });
                } else if (fn_ho && fn_ho->class_id == g_function_class_id && fn_ho->opaque) {
                    auto target_fn = static_cast<QJSWasmFunction*>(fn_ho->opaque)->function();
                    inst_mod->BindImportFunction(
                        func_imp_idx,
                        [target_fn](const std::vector<wasm::WasmVal>& a,
                                    std::vector<wasm::WasmVal>* r) { return target_fn->Call(a, r); });
                }
                func_imp_idx++;
            } else if (imp.kind == wasm::kWasmExtMemory) {
                LepusHeapObject* mem_ho = GetHeapObj(field_val);
                if (!mem_ho || mem_ho->class_id != g_memory_class_id || !mem_ho->opaque) {
                    return ThrowWasmError(ctx, wasm::WasmErrorCode::kLinkError,
                                          "Imported memory is not a WebAssembly.Memory");
                }
                inst_mod->SetImportedMemory(static_cast<QJSWasmMemory*>(mem_ho->opaque)->memory());
            } else if (imp.kind == wasm::kWasmExtTable) {
                LepusHeapObject* tbl_ho = GetHeapObj(field_val);
                if (!tbl_ho || tbl_ho->class_id != g_table_class_id || !tbl_ho->opaque) {
                    return ThrowWasmError(ctx, wasm::WasmErrorCode::kLinkError,
                                          "Imported table is not a WebAssembly.Table");
                }
                inst_mod->SetImportedTable(static_cast<QJSWasmTable*>(tbl_ho->opaque)->table());
            } else if (imp.kind == wasm::kWasmExtGlobal) {
                LepusHeapObject* glb_ho = GetHeapObj(field_val);
                if (glb_ho && glb_ho->class_id == g_global_class_id && glb_ho->opaque) {
                    inst_mod->BindImportGlobal(
                        global_imp_idx, static_cast<QJSWasmGlobal*>(glb_ho->opaque)->global());
                } else {
                    double num = 0.0;
                    if (!ToFloat64Val(field_val, &num)) {
                        return ThrowWasmError(ctx, wasm::WasmErrorCode::kLinkError,
                                              "Imported global value is invalid");
                    }
                    auto g = std::make_shared<wasm::Wasm3Global>(imp.globalType, imp.globalMutable, 0);
                    if (imp.globalType == wasm::c_m3Type_i32) {
                        g = std::make_shared<wasm::Wasm3Global>(imp.globalType, imp.globalMutable,
                                                                static_cast<int64_t>(static_cast<int32_t>(num)));
                    }
                    inst_mod->BindImportGlobal(global_imp_idx, g);
                }
                global_imp_idx++;
            }
        }
    }

    wasm::M3Result load_err = inst_mod->LoadAndInitialize();
    if (load_err) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInstantiateError, load_err);
    }

    // Build `instance.exports` object (`0x017254..0x018950`)
    wasm::LEPUSValue exports_obj = LepusNewObject(ctx);
    for (const auto& exp : inst_mod->exports()) {
        if (exp.kind == wasm::kWasmExtFunc) {
            auto fn = inst_mod->GetFunction(exp.index);
            if (fn) {
                LepusSetPropertyStr(ctx, exports_obj, exp.name.c_str(),
                                    QJSWasmFunction::CreateJSObject(ctx, fn));
            }
        } else if (exp.kind == wasm::kWasmExtMemory) {
            if (inst_mod->memory()) {
                auto* mem_wrap = new QJSWasmMemory(ctx, inst_mod->memory());
                wasm::LEPUSValue mem_js = AllocObjectWithClass(ctx, g_memory_class_id);
                GetHeapObj(mem_js)->opaque = mem_wrap;
                LepusSetPropertyStr(ctx, exports_obj, exp.name.c_str(), mem_js);
            }
        } else if (exp.kind == wasm::kWasmExtTable) {
            if (inst_mod->table()) {
                auto* tbl_wrap = new QJSWasmTable(ctx, inst_mod->table());
                wasm::LEPUSValue tbl_js = AllocObjectWithClass(ctx, g_table_class_id);
                GetHeapObj(tbl_js)->opaque = tbl_wrap;
                LepusSetPropertyStr(ctx, exports_obj, exp.name.c_str(), tbl_js);
            }
        } else if (exp.kind == wasm::kWasmExtGlobal) {
            auto g = inst_mod->GetGlobal(exp.index);
            if (g) {
                auto* glb_wrap = new QJSWasmGlobal(ctx, g);
                wasm::LEPUSValue glb_js = AllocObjectWithClass(ctx, g_global_class_id);
                GetHeapObj(glb_js)->opaque = glb_wrap;
                LepusSetPropertyStr(ctx, exports_obj, exp.name.c_str(), glb_js);
            }
        }
    }

    auto* inst_wrap = new QJSWasmInstance(ctx, inst_mod, exports_obj);
    wasm::LEPUSValue inst_js = AllocObjectWithClass(ctx, g_instance_class_id);
    GetHeapObj(inst_js)->opaque = inst_wrap;
    LepusSetPropertyStr(ctx, inst_js, "exports", exports_obj);
    return inst_js;
}

wasm::LEPUSValue QJSWasmInstance::Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                              int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x015460..0x0156ac: new WebAssembly.Instance(moduleObject, importObject?)
    if (!ctx || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.Instance requires at least 1 argument");
    }
    LepusHeapObject* mod_ho = GetHeapObj(argv[0]);
    if (!mod_ho || mod_ho->class_id != g_module_class_id || !mod_ho->opaque) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "First argument must be a WebAssembly.Module");
    }
    wasm::LEPUSValue imp_obj = (argc >= 2) ? argv[1] : wasm::MakeLepusUndefined();
    return InstantiateFromModule(ctx, static_cast<QJSWasmModule*>(mod_ho->opaque), imp_obj);
}

void QJSWasmInstance::Finalizer(wasm::LEPUSRuntime*, wasm::LEPUSValue val) {
    LepusHeapObject* o = GetHeapObj(val);
    if (o && o->opaque) {
        delete static_cast<QJSWasmInstance*>(o->opaque);
        o->opaque = nullptr;
    }
}

// ============================================================================
// 11. QJSWebAssembly Implementation ([OBSERVED] in .text 0x01003c..0x012e90)
//     Triển khai `QJSWebAssembly` (`RegisterWebAssembly`, `compile`, `instantiate`, `validate`)
// ============================================================================

wasm::JSClassID QJSWebAssembly::webassembly_class_id() noexcept { return g_webassembly_class_id; }
wasm::JSClassID QJSWebAssembly::function_class_id() noexcept    { return g_function_class_id; }
wasm::JSClassID QJSWebAssembly::global_class_id() noexcept      { return g_global_class_id; }
wasm::JSClassID QJSWebAssembly::table_class_id() noexcept       { return g_table_class_id; }
wasm::JSClassID QJSWebAssembly::memory_class_id() noexcept      { return g_memory_class_id; }
wasm::JSClassID QJSWebAssembly::instance_class_id() noexcept    { return g_instance_class_id; }
wasm::JSClassID QJSWebAssembly::module_class_id() noexcept      { return g_module_class_id; }

bool QJSWebAssembly::DecodeBase64Wasm(const char* input, size_t len, std::vector<uint8_t>* out_bytes) {
    // [OBSERVED] 0x01d450..0x01db80: decodes Base64 Wasm binary using standard alphabet
    // at .rodata 0x007da7 ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/")
    if (!input || !out_bytes) return false;
    out_bytes->clear();
    if (len == 0) return false;

    static constexpr const char kAlphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int8_t decode_lut[256];
    std::memset(decode_lut, -1, sizeof(decode_lut));
    for (int i = 0; i < 64; ++i) {
        decode_lut[static_cast<uint8_t>(kAlphabet[i])] = static_cast<int8_t>(i);
    }

    out_bytes->reserve((len * 3U) / 4U);
    uint32_t accum = 0;
    int bits       = 0;
    for (size_t i = 0; i < len; ++i) {
        uint8_t ch = static_cast<uint8_t>(input[i]);
        if (ch == '=') {
            break;
        }
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') {
            continue;
        }
        int8_t v = decode_lut[ch];
        if (v < 0) {
            return false;
        }
        accum = (accum << 6) | static_cast<uint32_t>(v);
        bits += 6;
        if (bits >= 8) {
            bits -= 8;
            out_bytes->push_back(static_cast<uint8_t>((accum >> bits) & 0xFFU));
        }
    }
    return !out_bytes->empty();
}

bool QJSWebAssembly::ExtractWasmBinary(wasm::LEPUSContext* ctx,
                                       wasm::LEPUSValue source,
                                       bool allow_base64,
                                       std::vector<uint8_t>* out_bytes,
                                       std::string* out_error) {
    // [OBSERVED] 0x01d0c0..0x01dbb0: supports ArrayBuffer, TypedArray, or Base64 string
    if (!out_bytes) return false;
    out_bytes->clear();

    if (source.tag == wasm::LEPUS_TAG_STRING) {
        if (!allow_base64) {
            if (out_error) *out_error = "Base64 string requires decodeBase64=true";
            return false;
        }
        const char* str = LepusToCString(ctx, source);
        if (!str || !DecodeBase64Wasm(str, std::strlen(str), out_bytes)) {
            if (out_error) *out_error = "Invalid Base64 WebAssembly string";
            return false;
        }
        return true;
    }

    LepusHeapObject* o = GetHeapObj(source);
    if (!o) {
        if (out_error) *out_error = "BufferSource must be an ArrayBuffer or TypedArray";
        return false;
    }
    if (o->is_detached_buffer) {
        if (out_error) *out_error = "ArrayBuffer is detached";
        return false;
    }
    if (!o->buffer_storage.empty()) {
        *out_bytes = o->buffer_storage;
        return true;
    }
    if (o->external_buffer && o->external_buffer_size > 0) {
        out_bytes->assign(o->external_buffer, o->external_buffer + o->external_buffer_size);
        return true;
    }
    if (out_error) *out_error = "Empty or non-buffer object passed as WebAssembly BufferSource";
    return false;
}

wasm::LEPUSValue QJSWebAssembly::Compile(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                         int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x012238..0x0126f0: WebAssembly.compile(bufferSource, decodeBase64?)
    wasm::LEPUSValue mod_val = QJSWasmModule::Constructor(ctx, wasm::MakeLepusUndefined(), argc, argv);
    wasm::LEPUSValue promise = LepusNewObject(ctx);
    if (mod_val.tag == wasm::LEPUS_TAG_EXCEPTION) {
        LepusSetPropertyStr(ctx, promise, "status", LepusNewString(ctx, "rejected"));
        LepusSetPropertyStr(ctx, promise, "reason", ctx->last_exception);
    } else {
        LepusSetPropertyStr(ctx, promise, "status", LepusNewString(ctx, "fulfilled"));
        LepusSetPropertyStr(ctx, promise, "value", mod_val);
        LepusSetPropertyStr(ctx, promise, "module", mod_val);
    }
    return promise;
}

wasm::LEPUSValue QJSWebAssembly::Instantiate(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                             int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x0126f4..0x012a68: WebAssembly.instantiate(moduleOrBytes, importObject?, decodeBase64?)
    if (!ctx || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.instantiate requires at least 1 argument");
    }
    wasm::LEPUSValue promise = LepusNewObject(ctx);
    LepusHeapObject* first_ho = GetHeapObj(argv[0]);

    if (first_ho && first_ho->class_id == g_module_class_id && first_ho->opaque) {
        wasm::LEPUSValue imp = (argc >= 2) ? argv[1] : wasm::MakeLepusUndefined();
        wasm::LEPUSValue inst = QJSWasmInstance::InstantiateFromModule(
            ctx, static_cast<QJSWasmModule*>(first_ho->opaque), imp);
        if (inst.tag == wasm::LEPUS_TAG_EXCEPTION) {
            LepusSetPropertyStr(ctx, promise, "status", LepusNewString(ctx, "rejected"));
            LepusSetPropertyStr(ctx, promise, "reason", ctx->last_exception);
        } else {
            LepusSetPropertyStr(ctx, promise, "status", LepusNewString(ctx, "fulfilled"));
            LepusSetPropertyStr(ctx, promise, "value", inst);
            LepusSetPropertyStr(ctx, promise, "instance", inst);
        }
        return promise;
    }

    // First overload: bufferSource (or Base64 string when argv[2] is true)
    wasm::LEPUSValue mod_args[2] = {
        argv[0],
        (argc >= 3) ? argv[2] : wasm::MakeLepusBool(false)
    };
    wasm::LEPUSValue mod_val = QJSWasmModule::Constructor(ctx, wasm::MakeLepusUndefined(), 2, mod_args);
    if (mod_val.tag == wasm::LEPUS_TAG_EXCEPTION) {
        LepusSetPropertyStr(ctx, promise, "status", LepusNewString(ctx, "rejected"));
        LepusSetPropertyStr(ctx, promise, "reason", ctx->last_exception);
        return promise;
    }

    wasm::LEPUSValue imp = (argc >= 2) ? argv[1] : wasm::MakeLepusUndefined();
    wasm::LEPUSValue inst_val = QJSWasmInstance::InstantiateFromModule(
        ctx, static_cast<QJSWasmModule*>(GetHeapObj(mod_val)->opaque), imp);
    if (inst_val.tag == wasm::LEPUS_TAG_EXCEPTION) {
        LepusSetPropertyStr(ctx, promise, "status", LepusNewString(ctx, "rejected"));
        LepusSetPropertyStr(ctx, promise, "reason", ctx->last_exception);
        return promise;
    }

    // [OBSERVED] Result object has `{ module, instance }` (.rodata 0x0065ca "module", 0x006b76 "instance")
    wasm::LEPUSValue result_pair = LepusNewObject(ctx);
    LepusSetPropertyStr(ctx, result_pair, "module", mod_val);
    LepusSetPropertyStr(ctx, result_pair, "instance", inst_val);
    LepusSetPropertyStr(ctx, promise, "status", LepusNewString(ctx, "fulfilled"));
    LepusSetPropertyStr(ctx, promise, "value", result_pair);
    LepusSetPropertyStr(ctx, promise, "module", mod_val);
    LepusSetPropertyStr(ctx, promise, "instance", inst_val);
    return promise;
}

wasm::LEPUSValue QJSWebAssembly::Validate(wasm::LEPUSContext* ctx, wasm::LEPUSValue,
                                          int argc, wasm::LEPUSValue* argv) {
    // [OBSERVED] 0x012a6c..0x012e90: WebAssembly.validate(bufferSource, decodeBase64?)
    if (!ctx || argc < 1 || !argv) {
        return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments,
                              "WebAssembly.validate requires at least 1 argument");
    }
    bool allow_base64 = (argc >= 2 && argv[1].tag == wasm::LEPUS_TAG_BOOL && argv[1].u.int32 != 0);
    std::vector<uint8_t> bytes;
    std::string err_str;
    if (!ExtractWasmBinary(ctx, argv[0], allow_base64, &bytes, &err_str)) {
        if (!allow_base64 && argv[0].tag == wasm::LEPUS_TAG_STRING) {
            return ThrowWasmError(ctx, wasm::WasmErrorCode::kInvalidArguments, err_str.c_str());
        }
        return wasm::MakeLepusBool(false);
    }

    auto* interop = wasm::InteropRuntime::FromContext(ctx);
    if (!interop || !interop->wasm3_runtime) {
        return wasm::MakeLepusBool(false);
    }
    bool ok = interop->wasm3_runtime->ValidateModule(bytes.data(), bytes.size());
    return wasm::MakeLepusBool(ok);
}

void QJSWebAssembly::Finalizer(wasm::LEPUSRuntime*, wasm::LEPUSValue val) {
    // [OBSERVED] 0x011bd8..0x012080: deletes InteropRuntime* stored as opaque on WebAssembly object
    LepusHeapObject* o = GetHeapObj(val);
    if (o && o->opaque) {
        delete static_cast<wasm::InteropRuntime*>(o->opaque);
        o->opaque = nullptr;
    }
}

void QJSWebAssembly::GCMark(wasm::LEPUSRuntime*, wasm::LEPUSValue, void (*)(wasm::LEPUSRuntime*, void*)) {
    // [OBSERVED] 0x012084..0x012234: marks constructors & live modules in InteropRuntime
}

bool QJSWebAssembly::RegisterWebAssembly(wasm::LEPUSContext* ctx,
                                         std::atomic<bool>* is_terminated,
                                         wasm::WasmRuntimeType runtime_type) {
    // [OBSERVED] 0x01003c..0x011344 (4,872 bytes):
    // 1. Check `ctx == nullptr` (`0x010054: cbz x0, #0x109f4`)
    if (!ctx || !ctx->runtime) {
        return false;
    }

    // 2. Check runtime_type (`kPrism` fallback to `kWasm3`, 0x01005c..0x0100fc)
    if (runtime_type == wasm::WasmRuntimeType::kPrism) {
        // [OBSERVED] .rodata 0x00724b:
        // "[VmSdkWasm] PRISM runtime requested but not built into libwasm.so; falling back to WASM3."
        runtime_type = wasm::WasmRuntimeType::kWasm3;
    }

    // 3. Allocate class IDs in .bss 0x03c000..0x03c018 and register JSClassDefs
    wasm::LEPUSRuntime* rt = ctx->runtime;
    if (g_webassembly_class_id == 0) g_webassembly_class_id = ++rt->next_class_id;
    if (g_function_class_id == 0)    g_function_class_id    = ++rt->next_class_id;
    if (g_global_class_id == 0)      g_global_class_id      = ++rt->next_class_id;
    if (g_table_class_id == 0)       g_table_class_id       = ++rt->next_class_id;
    if (g_memory_class_id == 0)      g_memory_class_id      = ++rt->next_class_id;
    if (g_instance_class_id == 0)    g_instance_class_id    = ++rt->next_class_id;
    if (g_module_class_id == 0)      g_module_class_id      = ++rt->next_class_id;

    rt->class_defs[g_webassembly_class_id] = kWebAssemblyClassDef;
    rt->class_defs[g_function_class_id]    = kWasmFunctionClassDef;
    rt->class_defs[g_global_class_id]      = kWasmGlobalClassDef;
    rt->class_defs[g_instance_class_id]    = kWasmInstanceClassDef;
    rt->class_defs[g_memory_class_id]      = kWasmMemoryClassDef;
    rt->class_defs[g_module_class_id]      = kWasmModuleClassDef;
    rt->class_defs[g_table_class_id]       = kWasmTableClassDef;

    // 4. Create `WebAssembly` namespace object and attach `InteropRuntime` (0x78 bytes @ 0x01020c)
    wasm::LEPUSValue wasm_obj = AllocObjectWithClass(ctx, g_webassembly_class_id);
    auto* interop = new wasm::InteropRuntime(ctx, is_terminated, runtime_type);
    GetHeapObj(wasm_obj)->opaque = interop;
    ctx->interop_runtime = interop;
    interop->webassembly_obj.Reset(ctx, wasm_obj);

    AttachFunctionList(ctx, wasm_obj, kWebAssemblyFuncs, 3U);

    // 5. Register `WebAssembly.Module` constructor + static methods (`customSections`, `exports`, `imports`, `supportBase64`)
    wasm::LEPUSValue module_ctor = AllocCFunctionObj(ctx, &QJSWasmModule::Constructor, "Module", 1);
    const wasm::JSCFunctionListEntry kModuleStaticEntries[4] = {
        {"customSections", wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{2, 0, 0, 0, &QJSWasmModule::CustomSections}}, 0},
        {"exports",        wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWasmModule::Exports}},        0},
        {"imports",        wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWasmModule::Imports}},        0},
        MakeGetSetEntry("supportBase64", wasm::LEPUS_PROP_CONFIGURABLE, &QJSWasmModule::SupportBase64Getter, nullptr),
    };
    AttachFunctionList(ctx, module_ctor, kModuleStaticEntries, 4U);
    LepusSetPropertyStr(ctx, wasm_obj, "Module", module_ctor);
    interop->module_ctor.Reset(ctx, module_ctor);

    // 6. Register `WebAssembly.Instance` constructor
    wasm::LEPUSValue instance_ctor = AllocCFunctionObj(ctx, &QJSWasmInstance::Constructor, "Instance", 1);
    LepusSetPropertyStr(ctx, wasm_obj, "Instance", instance_ctor);
    interop->instance_ctor.Reset(ctx, instance_ctor);

    // 7. Register `WebAssembly.Memory` constructor & prototype (`grow`, `buffer`)
    wasm::LEPUSValue memory_proto = LepusNewObject(ctx);
    const wasm::JSCFunctionListEntry kMemoryProtoEntries[2] = {
        {"grow", wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWasmMemory::GrowCallback}}, 0},
        MakeGetSetEntry("buffer", wasm::LEPUS_PROP_CONFIGURABLE, &QJSWasmMemory::BufferGetter, nullptr),
    };
    AttachFunctionList(ctx, memory_proto, kMemoryProtoEntries, 2U);
    ctx->class_protos[g_memory_class_id] = memory_proto;
    wasm::LEPUSValue memory_ctor = AllocCFunctionObj(ctx, &QJSWasmMemory::Constructor, "Memory", 1);
    LepusSetPropertyStr(ctx, memory_ctor, "prototype", memory_proto);
    LepusSetPropertyStr(ctx, wasm_obj, "Memory", memory_ctor);
    interop->memory_ctor.Reset(ctx, memory_ctor);

    // 8. Register `WebAssembly.Table` constructor & prototype (`set`, `get`, `grow`, `length`)
    wasm::LEPUSValue table_proto = LepusNewObject(ctx);
    const wasm::JSCFunctionListEntry kTableProtoEntries[4] = {
        {"set",  wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWasmTable::SetCallback}},  0},
        {"get",  wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWasmTable::GetCallback}},  0},
        {"grow", wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{1, 0, 0, 0, &QJSWasmTable::GrowCallback}}, 0},
        MakeGetSetEntry("length", wasm::LEPUS_PROP_CONFIGURABLE, &QJSWasmTable::LengthGetter, nullptr),
    };
    AttachFunctionList(ctx, table_proto, kTableProtoEntries, 4U);
    ctx->class_protos[g_table_class_id] = table_proto;
    wasm::LEPUSValue table_ctor = AllocCFunctionObj(ctx, &QJSWasmTable::Constructor, "Table", 1);
    LepusSetPropertyStr(ctx, table_ctor, "prototype", table_proto);
    LepusSetPropertyStr(ctx, wasm_obj, "Table", table_ctor);
    interop->table_ctor.Reset(ctx, table_ctor);

    // 9. Register `WebAssembly.Global` constructor & prototype (`valueOf`, `value` getter/setter)
    wasm::LEPUSValue global_proto = LepusNewObject(ctx);
    const wasm::JSCFunctionListEntry kGlobalProtoEntries[2] = {
        {"valueOf", wasm::LEPUS_PROP_WRITABLE | wasm::LEPUS_PROP_CONFIGURABLE, wasm::LEPUS_DEF_CFUNC, 0, 0, {{0, 0, 0, 0, &QJSWasmGlobal::ValueOfCallback}}, 0},
        MakeGetSetEntry("value", wasm::LEPUS_PROP_CONFIGURABLE, &QJSWasmGlobal::ValueGetter, &QJSWasmGlobal::ValueSetter),
    };
    AttachFunctionList(ctx, global_proto, kGlobalProtoEntries, 2U);
    ctx->class_protos[g_global_class_id] = global_proto;
    wasm::LEPUSValue global_ctor = AllocCFunctionObj(ctx, &QJSWasmGlobal::Constructor, "Global", 1);
    LepusSetPropertyStr(ctx, global_ctor, "prototype", global_proto);
    LepusSetPropertyStr(ctx, wasm_obj, "Global", global_ctor);
    interop->global_ctor.Reset(ctx, global_ctor);

    // 10. Register `CompileError`, `LinkError`, `RuntimeError` constructors
    wasm::LEPUSValue compile_err_ctor = LepusNewObject(ctx);
    wasm::LEPUSValue link_err_ctor    = LepusNewObject(ctx);
    wasm::LEPUSValue runtime_err_ctor = LepusNewObject(ctx);
    LepusSetPropertyStr(ctx, wasm_obj, "CompileError", compile_err_ctor);
    LepusSetPropertyStr(ctx, wasm_obj, "LinkError",    link_err_ctor);
    LepusSetPropertyStr(ctx, wasm_obj, "RuntimeError", runtime_err_ctor);
    interop->compile_error_ctor.Reset(ctx, compile_err_ctor);
    interop->link_error_ctor.Reset(ctx, link_err_ctor);
    interop->runtime_error_ctor.Reset(ctx, runtime_err_ctor);

    // 11. Define `globalThis.WebAssembly`
    LepusSetPropertyStr(ctx, ctx->global_obj, "WebAssembly", wasm_obj);
    return true;
}

} // namespace qjs
} // namespace vmsdk

// ============================================================================
// 12. Exported C / JNI Entry Points ([OBSERVED] @ 0x01003c & 0x0117d8)
//     Các hàm xuất khẩu C và JNI của `libwasm.so`
// ============================================================================

extern "C" {

bool RegisterWebAssembly(vmsdk::wasm::LEPUSContext* ctx,
                         std::atomic<bool>* is_terminated,
                         vmsdk::wasm::WasmRuntimeType runtime_type) {
    // [OBSERVED] Exported symbol @ 0x01003c (size 4,872 bytes)
    return vmsdk::qjs::QJSWebAssembly::RegisterWebAssembly(ctx, is_terminated, runtime_type);
}

int64_t Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory(
    void* /*env*/, void* /*clazz*/) {
    // [OBSERVED] Exported JNI symbol @ 0x0117d8 (size 12 bytes):
    // 0x0117d8: adrp x0, #0x3b000 (0xD0000140)
    // 0x0117dc: ldr  x0, [x0, #0xae0] (0xF9457000) -> &RegisterWebAssembly
    // 0x0117e0: ret (0xD65F03C0)
    return reinterpret_cast<int64_t>(&RegisterWebAssembly);
}

} // extern "C"
