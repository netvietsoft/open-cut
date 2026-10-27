/**
 * @file wasm_qjs_bindings.h
 * @brief QuickJS / LepusNG WebAssembly JS API Bindings (`vmsdk::qjs::QJSWebAssembly`)
 *        Lớp kết nối API JavaScript WebAssembly cho QuickJS / LepusNG (`vmsdk::qjs::QJSWebAssembly`)
 *
 * @details
 * Clean-room C++17 reconstruction of the QuickJS/LepusNG WebAssembly bindings in
 * `libwasm.so` (`.text 0x01003c..0x021880`, `.data.rel.ro 0x0380b0..0x038430`,
 * `.bss 0x03c000..0x03c054`).
 *
 * Evidence Classification / Phân loại bằng chứng:
 * - [OBSERVED]:
 *   - `RegisterWebAssembly` (`0x01003c`, size `4,872 bytes`)
 *   - `Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory` (`0x0117d8`, size `12 bytes`)
 *   - 7 `JSClassDef` descriptors in `.data.rel.ro`:
 *     1. `"WebAssembly"` @ `0x0380b0` (finalizer `0x011bd8`, gc_mark `0x012084`)
 *     2. `"WebAssembly.Function"` @ `0x038148` (finalizer `0x013128`, call `0x0132b8`)
 *     3. `"WebAssembly.Global"` @ `0x038188` (finalizer `0x014290`, ctor `0x013f60`)
 *     4. `"WebAssembly.Instance"` @ `0x0381f0` (finalizer `0x01b8cc`, ctor `0x015460`)
 *     5. `"WebAssembly.Memory"` @ `0x038248` (finalizer `0x01ba18`, gc_mark `0x01ce7c`, ctor `0x01b920`)
 *     6. `"WebAssembly.Module"` @ `0x0382b8` (finalizer `0x01f2f4`, gc_mark `0x01f42c`, ctor `0x01cf28`)
 *     7. `"WebAssembly.Table"` @ `0x038378` (finalizer `0x01f4d8`, ctor `0x01f460`)
 */

#ifndef NEXTAI_OPENCUT_LIBWASM_WASM_QJS_BINDINGS_H_
#define NEXTAI_OPENCUT_LIBWASM_WASM_QJS_BINDINGS_H_

#include "wasm_types.h"
#include "wasm_m3_runtime.h"

namespace vmsdk {
namespace qjs {

// ============================================================================
// 1. Simulated / Bridged LepusNG C API Surface ([OBSERVED] in .dynsym & .plt)
//    Bề mặt API C của LepusNG / QuickJS ([QUAN SÁT ĐƯỢC] trong .dynsym & .plt)
// ============================================================================

/**
 * @brief Lightweight in-memory LepusNG object & context representation for standalone
 *        deterministic testing and clean-room host execution when `libquick.so` is not linked.
 *        Biểu diễn đối tượng và ngữ cảnh LepusNG trong bộ nhớ phục vụ kiểm thử độc lập
 *        và thực thi phòng sạch.
 */
struct LepusPropertyEntry {
    wasm::LEPUSValue value      = wasm::MakeLepusUndefined();
    wasm::JSGetterFunc getter   = nullptr;
    wasm::JSSetterFunc setter   = nullptr;
    uint8_t flags               = wasm::LEPUS_PROP_C_W_E;
    bool is_accessor            = false;
};

struct LepusHeapObject {
    wasm::JSClassID class_id    = 0;
    void* opaque                = nullptr;
    wasm::JSCFunction cfunc     = nullptr;
    int cfunc_length            = 0;
    std::string cfunc_name;
    std::vector<uint8_t> buffer_storage;
    uint8_t* external_buffer    = nullptr;
    size_t external_buffer_size = 0;
    wasm::LEPUSFreeArrayBufferDataFunc buffer_free_func = nullptr;
    void* buffer_opaque         = nullptr;
    bool is_detached_buffer     = false;
    bool is_array               = false;
    bool is_error               = false;
    std::string string_value;
    std::vector<wasm::LEPUSValue> array_elements;
    std::unordered_map<std::string, LepusPropertyEntry> properties;
};

// ============================================================================
// 2. QJSWasm Wrapper Classes ([OBSERVED] in .rodata RTTI & .text 0x011bd8..0x021880)
//    Các lớp bao đối tượng WebAssembly trên JS ([QUAN SÁT ĐƯỢC])
// ============================================================================

/**
 * @brief Wrapper for `WebAssembly.Module` (`QJSWasmModule`, constructor @ `0x01cf28`).
 *        Lớp bao cho đối tượng `WebAssembly.Module` trong JS (`QJSWasmModule`).
 */
class QJSWasmModule {
public:
    QJSWasmModule(wasm::LEPUSContext* ctx,
                  std::shared_ptr<wasm::Wasm3Module> m3_module,
                  const uint8_t* raw_bytes,
                  size_t raw_size);
    ~QJSWasmModule();

    std::shared_ptr<wasm::Wasm3Module> module() const noexcept { return module_; }
    const std::vector<uint8_t>& raw_bytes() const noexcept { return raw_bytes_; }
    wasm::LEPUSContext* context() const noexcept { return ctx_; }

    // Static methods in .data.rel.ro 0x0382e0 / Các phương thức tĩnh tại 0x0382e0
    static wasm::LEPUSValue Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue new_target,
                                        int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue CustomSections(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                           int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue Exports(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                    int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue Imports(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                    int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue SupportBase64Getter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val);

    static void Finalizer(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val);
    static void GCMark(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val,
                       void (*mark_func)(wasm::LEPUSRuntime*, void*));

private:
    wasm::LEPUSContext*                ctx_;
    std::shared_ptr<wasm::Wasm3Module> module_;
    std::vector<uint8_t>               raw_bytes_;
    wasm::WASMGCPersistent             js_self_;
};

/**
 * @brief Wrapper for `WebAssembly.Memory` (`QJSWasmMemory`, constructor @ `0x01b920`).
 *        Lớp bao cho đối tượng `WebAssembly.Memory` (`QJSWasmMemory`).
 *
 * [OBSERVED] Validates `"initial"` (`.rodata 0x007b09`) and `"maximum"` (`.rodata 0x007b11`)
 * page counts (`max <= 65536`), exposes `.grow(delta)` (`0x01c880`) and `.buffer` (`0x01cce4`).
 */
class QJSWasmMemory {
public:
    QJSWasmMemory(wasm::LEPUSContext* ctx, std::shared_ptr<wasm::Wasm3Memory> memory);
    ~QJSWasmMemory();

    std::shared_ptr<wasm::Wasm3Memory> memory() const noexcept { return memory_; }
    wasm::LEPUSValue GetOrCreateArrayBuffer(wasm::LEPUSContext* ctx);
    int32_t Grow(wasm::LEPUSContext* ctx, uint32_t delta_pages);

    static wasm::LEPUSValue Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue new_target,
                                        int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue GrowCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                         int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue BufferGetter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val);

    static void Finalizer(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val);
    static void GCMark(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val,
                       void (*mark_func)(wasm::LEPUSRuntime*, void*));

private:
    wasm::LEPUSContext*                ctx_;
    std::shared_ptr<wasm::Wasm3Memory> memory_;
    wasm::WASMGCPersistent             buffer_persistent_;
};

/**
 * @brief Wrapper for `WebAssembly.Table` (`QJSWasmTable`, constructor @ `0x01f460`).
 *        Lớp bao cho đối tượng `WebAssembly.Table` (`QJSWasmTable`).
 *
 * [OBSERVED] Validates `"element"` (`"anyfunc"` @ `0x007e68` / `"funcref"` @ `0x006684`),
 * `"initial"`, and `"maximum"`, exposing `.set` (`0x01f66c`), `.get` (`0x02014c`),
 * `.grow` (`0x0210f8`), and `.length` (`0x02186c`).
 */
class QJSWasmTable {
public:
    QJSWasmTable(wasm::LEPUSContext* ctx, std::shared_ptr<wasm::Wasm3Table> table);
    ~QJSWasmTable();

    std::shared_ptr<wasm::Wasm3Table> table() const noexcept { return table_; }

    static wasm::LEPUSValue Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue new_target,
                                        int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue SetCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                        int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue GetCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                        int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue GrowCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                         int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue LengthGetter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val);

    static void Finalizer(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val);

private:
    wasm::LEPUSContext*               ctx_;
    std::shared_ptr<wasm::Wasm3Table> table_;
};

/**
 * @brief Wrapper for `WebAssembly.Global` (`QJSWasmGlobal`, constructor @ `0x013f60`).
 *        Lớp bao cho đối tượng `WebAssembly.Global` (`QJSWasmGlobal`).
 *
 * [OBSERVED] Validates descriptor `"value"` (`"i32"`, `"i64"`, `"f32"`, `"f64"`) and
 * `"mutable"`, exposing `.valueOf()` (`0x014b3c`) and `.value` getter (`0x014b40`) /
 * setter (`0x014e28`, throws `"Can't set the value of an immutable global."` @ `0x006ca2`).
 */
class QJSWasmGlobal {
public:
    QJSWasmGlobal(wasm::LEPUSContext* ctx, std::shared_ptr<wasm::Wasm3Global> global);
    ~QJSWasmGlobal();

    std::shared_ptr<wasm::Wasm3Global> global() const noexcept { return global_; }

    static wasm::LEPUSValue Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue new_target,
                                        int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue ValueOfCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                            int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue ValueGetter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val);
    static wasm::LEPUSValue ValueSetter(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                        wasm::LEPUSValue val);

    static void Finalizer(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val);

private:
    wasm::LEPUSContext*                ctx_;
    std::shared_ptr<wasm::Wasm3Global> global_;
};

/**
 * @brief Wrapper for exported/table `WebAssembly.Function` (`QJSWasmFunction` @ `0x012e94`).
 *        Lớp bao cho hàm xuất khẩu `WebAssembly.Function` (`QJSWasmFunction`).
 *
 * [OBSERVED] Uses `JSClassCall` callback at `0x0132b8` and finalizer at `0x013128`.
 */
class QJSWasmFunction {
public:
    QJSWasmFunction(wasm::LEPUSContext* ctx, std::shared_ptr<wasm::Wasm3Function> func);
    ~QJSWasmFunction();

    std::shared_ptr<wasm::Wasm3Function> function() const noexcept { return func_; }

    static wasm::LEPUSValue CreateJSObject(wasm::LEPUSContext* ctx,
                                           std::shared_ptr<wasm::Wasm3Function> func);
    static wasm::LEPUSValue CallCallback(wasm::LEPUSContext* ctx, wasm::LEPUSValue func_obj,
                                         wasm::LEPUSValue this_val, int argc,
                                         wasm::LEPUSValue* argv, int flags);
    static void Finalizer(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val);

private:
    wasm::LEPUSContext*                  ctx_;
    std::shared_ptr<wasm::Wasm3Function> func_;
};

/**
 * @brief Wrapper for `WebAssembly.Instance` (`QJSWasmInstance`, constructor @ `0x015460`).
 *        Lớp bao cho đối tượng thực thể `WebAssembly.Instance` (`QJSWasmInstance`).
 *
 * [OBSERVED] Links imports from JS `importObject`, loads module into `Wasm3Runtime`,
 * populates the frozen `instance.exports` namespace object (`0x017254..0x018950`),
 * and executes the Wasm `start` function if present.
 */
class QJSWasmInstance {
public:
    QJSWasmInstance(wasm::LEPUSContext* ctx,
                    std::shared_ptr<wasm::Wasm3Module> module,
                    wasm::LEPUSValue exports_obj);
    ~QJSWasmInstance();

    std::shared_ptr<wasm::Wasm3Module> module() const noexcept { return module_; }
    wasm::LEPUSValue exports_object() const noexcept { return exports_.Get(); }

    static wasm::LEPUSValue Constructor(wasm::LEPUSContext* ctx, wasm::LEPUSValue new_target,
                                        int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue InstantiateFromModule(wasm::LEPUSContext* ctx,
                                                  QJSWasmModule* qjs_module,
                                                  wasm::LEPUSValue import_obj);
    static void Finalizer(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val);

private:
    wasm::LEPUSContext*                ctx_;
    std::shared_ptr<wasm::Wasm3Module> module_;
    wasm::WASMGCPersistent             exports_;
};

// ============================================================================
// 3. Top-Level `QJSWebAssembly` Namespace & Registration ([OBSERVED] @ 0x01003c)
//    Lớp không gian tên `QJSWebAssembly` và hàm đăng ký ([QUAN SÁT ĐƯỢC] @ 0x01003c)
// ============================================================================

/**
 * @brief Top-level `vmsdk::qjs::QJSWebAssembly` controller.
 *        Lớp điều khiển cấp cao nhất `vmsdk::qjs::QJSWebAssembly`.
 */
class QJSWebAssembly {
public:
    /**
     * @brief Registers the `WebAssembly` global object and all 7 constructors/classes
     *        into a QuickJS/LepusNG context.
     *        Đăng ký đối tượng toàn cục `WebAssembly` và toàn bộ 7 lớp con vào `LEPUSContext`.
     *
     * [OBSERVED] Binary address `0x01003c` (`4,872 bytes`).
     */
    static bool RegisterWebAssembly(wasm::LEPUSContext* ctx,
                                    std::atomic<bool>* is_terminated = nullptr,
                                    wasm::WasmRuntimeType runtime_type = wasm::WasmRuntimeType::kWasm3);

    // Static methods on globalThis.WebAssembly (.data.rel.ro 0x0380d8)
    static wasm::LEPUSValue Compile(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                    int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue Instantiate(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                        int argc, wasm::LEPUSValue* argv);
    static wasm::LEPUSValue Validate(wasm::LEPUSContext* ctx, wasm::LEPUSValue this_val,
                                     int argc, wasm::LEPUSValue* argv);

    static void Finalizer(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val);
    static void GCMark(wasm::LEPUSRuntime* rt, wasm::LEPUSValue val,
                       void (*mark_func)(wasm::LEPUSRuntime*, void*));

    /**
     * @brief Extracts raw WebAssembly binary bytes from an ArrayBuffer, TypedArray,
     *        or Base64 string (when `decode_base64` is enabled).
     *        Trích xuất mảng byte nhị phân WebAssembly từ ArrayBuffer, TypedArray hoặc chuỗi Base64.
     *
     * [OBSERVED] Mirrors `GetWasmBinary` (`0x01d0c0..0x01dbb0`), including Base64 decoding
     * with lookup table at `.rodata 0x007da7` (`"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"`).
     */
    static bool ExtractWasmBinary(wasm::LEPUSContext* ctx,
                                  wasm::LEPUSValue source,
                                  bool allow_base64,
                                  std::vector<uint8_t>* out_bytes,
                                  std::string* out_error);

    /**
     * @brief Decodes a Base64-encoded WebAssembly binary string.
     *        Giải mã chuỗi nhị phân WebAssembly mã hóa Base64.
     */
    static bool DecodeBase64Wasm(const char* input, size_t len, std::vector<uint8_t>* out_bytes);

    // Accessors for the 7 global JSClassIDs stored in .bss 0x03c000..0x03c018
    static wasm::JSClassID webassembly_class_id() noexcept;
    static wasm::JSClassID function_class_id() noexcept;
    static wasm::JSClassID global_class_id() noexcept;
    static wasm::JSClassID table_class_id() noexcept;
    static wasm::JSClassID memory_class_id() noexcept;
    static wasm::JSClassID instance_class_id() noexcept;
    static wasm::JSClassID module_class_id() noexcept;
};

// ============================================================================
// 4. Standalone LepusContext Test/Host Harness Functions
//    Các hàm tạo và thao tác `LEPUSContext` phục vụ kiểm thử và thực thi độc lập
// ============================================================================

wasm::LEPUSRuntime* CreateStandaloneLepusRuntime();
void DestroyStandaloneLepusRuntime(wasm::LEPUSRuntime* rt);
wasm::LEPUSContext* CreateStandaloneLepusContext(wasm::LEPUSRuntime* rt);
void DestroyStandaloneLepusContext(wasm::LEPUSContext* ctx);

wasm::LEPUSValue LepusNewString(wasm::LEPUSContext* ctx, const char* str);
wasm::LEPUSValue LepusNewObject(wasm::LEPUSContext* ctx);
wasm::LEPUSValue LepusNewArray(wasm::LEPUSContext* ctx);
wasm::LEPUSValue LepusNewArrayBufferCopy(wasm::LEPUSContext* ctx, const uint8_t* data, size_t size);
wasm::LEPUSValue LepusGetGlobalObject(wasm::LEPUSContext* ctx);
wasm::LEPUSValue LepusGetPropertyStr(wasm::LEPUSContext* ctx, wasm::LEPUSValue obj, const char* prop);
int LepusSetPropertyStr(wasm::LEPUSContext* ctx, wasm::LEPUSValue obj, const char* prop, wasm::LEPUSValue val);
wasm::LEPUSValue LepusGetPropertyUint32(wasm::LEPUSContext* ctx, wasm::LEPUSValue obj, uint32_t idx);
int LepusSetPropertyUint32(wasm::LEPUSContext* ctx, wasm::LEPUSValue obj, uint32_t idx, wasm::LEPUSValue val);
const char* LepusToCString(wasm::LEPUSContext* ctx, wasm::LEPUSValue val);

} // namespace qjs
} // namespace vmsdk

// ============================================================================
// 5. Exported C / JNI Symbols from `libwasm.so` (.dynsym 107 & 108)
//    Các biểu tượng C / JNI xuất khẩu từ `libwasm.so` (.dynsym 107 & 108)
// ============================================================================

extern "C" {

/**
 * @brief Exported factory symbol (`0x01003c`, size `4,872 bytes`).
 *        Hàm C xuất khẩu đăng ký đối tượng `WebAssembly` vào `LEPUSContext`.
 */
bool RegisterWebAssembly(vmsdk::wasm::LEPUSContext* ctx,
                         std::atomic<bool>* is_terminated,
                         vmsdk::wasm::WasmRuntimeType runtime_type);

/**
 * @brief Exported JNI bridge (`0x0117d8`, size `12 bytes`):
 *        `com.bytedance.vmsdk.wasm.RegisterWebAssembly.loadWasmFactory()`
 *        Returns the function pointer address of `RegisterWebAssembly`.
 *        Trả về địa chỉ con trỏ hàm của `RegisterWebAssembly` cho tầng Java.
 */
int64_t Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory(
    void* env, void* clazz);

} // extern "C"

#endif // NEXTAI_OPENCUT_LIBWASM_WASM_QJS_BINDINGS_H_
