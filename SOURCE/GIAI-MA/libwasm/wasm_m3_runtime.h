/**
 * @file wasm_m3_runtime.h
 * @brief VMSDK InteropRuntime, Wasm3Runtime & Binary Section Parsers (0x02268c..0x035990)
 *        Lớp thời gian chạy InteropRuntime, Wasm3Runtime & Bộ phân tích các phân đoạn Wasm
 *
 * @details
 * Clean-room C++17 reconstruction of `vmsdk::InteropRuntime`, `vmsdk::wasm3::Wasm3Runtime`,
 * `Wasm3Module`, `Wasm3Function`, `Wasm3Memory`, `Wasm3Table`, `Wasm3Global`, LEB128 decoders,
 * and the 12-entry Wasm binary section parser jump table at `.data.rel.ro 0x03b888..0x03b8e8`.
 *
 * Evidence Classification / Phân loại bằng chứng:
 * - [OBSERVED]:
 *   - `InteropRuntime` (`0x78` = 120 bytes @ `0x01020c: mov w0, #0x78`)
 *   - `Wasm3Runtime` (`0x20` = 32 bytes @ `0x01026c: mov w0, #0x20`)
 *   - Section Parser Jump Table at `.data.rel.ro 0x03b888..0x03b8e8`:
 *     - `[0]` Custom   -> `0x035670`
 *     - `[1]` Type     -> `0x033008`
 *     - `[2]` Import   -> `0x0338cc`
 *     - `[3]` Function -> `0x0335f8`
 *     - `[4]` Table    -> `0x034e98`
 *     - `[5]` Memory   -> `0x035190`
 *     - `[6]` Global   -> `0x0353d8`
 *     - `[7]` Export   -> `0x0342e0`
 *     - `[8]` Start    -> `0x034678`
 *     - `[9]` Element  -> `0x034758`
 *     - `[10]` Code    -> `0x034848`
 *     - `[11]` Data    -> `0x034a58`
 *   - Built-in host imports linked in `m3_LoadModule` (`0x022e80..0x0234fc`):
 *     `_abort` (`0x0357c0`), `_exit` (`0x0357fc`), `_memcpy` (`0x03582c`),
 *     `_memmove` (`0x035870`), `_memset` (`0x0358b4`), `printf` (`0x0358f8`),
 *     `clock_ms` (`0x035948`), `_debug` (`0x035990`).
 */

#ifndef NEXTAI_OPENCUT_LIBWASM_WASM_M3_RUNTIME_H_
#define NEXTAI_OPENCUT_LIBWASM_WASM_M3_RUNTIME_H_

#include "wasm_types.h"

namespace vmsdk {
namespace wasm {

class Wasm3Runtime;
class Wasm3Module;
class Wasm3Function;
class Wasm3Memory;
class Wasm3Table;
class Wasm3Global;

// ============================================================================
// 1. LEB128 & Binary Stream Reader Helpers ([OBSERVED] in 0x033008..0x0357b0)
//    Các hàm giải mã số nguyên độ dài thay đổi LEB128 & luồng byte nhị phân
// ============================================================================

/**
 * @brief Reads an unsigned 32-bit LEB128 integer from `[*io_bytes, end)`.
 *        Đọc số nguyên không dấu 32-bit mã hóa LEB128 từ luồng nhị phân.
 */
M3Result ReadLEB_u32(uint32_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept;

/**
 * @brief Reads an unsigned 64-bit LEB128 integer from `[*io_bytes, end)`.
 *        Đọc số nguyên không dấu 64-bit mã hóa LEB128 từ luồng nhị phân.
 */
M3Result ReadLEB_u64(uint64_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept;

/**
 * @brief Reads a signed 32-bit LEB128 integer (`s32` / `s33`) from `[*io_bytes, end)`.
 *        Đọc số nguyên có dấu 32-bit mã hóa LEB128 từ luồng nhị phân.
 */
M3Result ReadLEB_i32(int32_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept;

/**
 * @brief Reads a signed 64-bit LEB128 integer (`s64`) from `[*io_bytes, end)`.
 *        Đọc số nguyên có dấu 64-bit mã hóa LEB128 từ luồng nhị phân.
 */
M3Result ReadLEB_i64(int64_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept;

/**
 * @brief Reads a single byte (`u8`) from `[*io_bytes, end)`.
 *        Đọc 1 byte không dấu từ luồng nhị phân.
 */
M3Result Read_u8(uint8_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept;

/**
 * @brief Reads a little-endian 32-bit unsigned integer (`u32`) from `[*io_bytes, end)`.
 *        Đọc số nguyên 32-bit little-endian từ luồng nhị phân.
 */
M3Result Read_u32(uint32_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept;

/**
 * @brief Reads a little-endian 64-bit unsigned integer (`u64`) from `[*io_bytes, end)`.
 *        Đọc số nguyên 64-bit little-endian từ luồng nhị phân.
 */
M3Result Read_u64(uint64_t* out_value, const uint8_t** io_bytes, const uint8_t* end) noexcept;

/**
 * @brief Reads a length-prefixed UTF-8 string from `[*io_bytes, end)` and allocates a null-terminated copy.
 *        Đọc chuỗi UTF-8 có độ dài đi trước và cấp phát bản sao kết thúc bằng null.
 */
M3Result Read_utf8(const char** out_utf8, const uint8_t** io_bytes, const uint8_t* end) noexcept;

/**
 * @brief Translates a WebAssembly binary value-type byte (`0x7F`..`0x6F`) into `M3ValueType`.
 *        Chuyển đổi byte kiểu dữ liệu nhị phân WebAssembly sang `M3ValueType`.
 *
 * [OBSERVED] Verified at `0x0331e0..0x033240`:
 * - `0x7F` -> `c_m3Type_i32` (1)
 * - `0x7E` -> `c_m3Type_i64` (2)
 * - `0x7D` -> `c_m3Type_f32` (3)
 * - `0x7C` -> `c_m3Type_f64` (4)
 * - `0x70` -> `c_m3Type_funcref` (5)
 * - `0x6F` -> `c_m3Type_externref` (6)
 * - `0x40` -> `c_m3Type_none` (0)
 */
M3Result NormalizeWasmType(M3ValueType* out_type, int8_t wasm_type_byte) noexcept;

/**
 * @brief Evaluates a WebAssembly constant initializer expression (`init_expr` ending with `0x0B`).
 *        Tính giá trị biểu thức khởi tạo hằng số (`init_expr` kết thúc bởi opcode `0x0B`).
 */
M3Result EvaluateInitExpr(M3Module* module, const uint8_t* expr, uint32_t expr_size,
                          M3ValueType expected_type, int64_t* out_bits) noexcept;

// ============================================================================
// 2. Wasm Binary Section Parsers (Jump Table @ .data.rel.ro 0x03b888..0x03b8e8)
//    12 hàm phân tích phân đoạn nhị phân Wasm (Bảng nhảy tại 0x03b888..0x03b8e8)
// ============================================================================

using M3SectionParser = M3Result (*)(M3Module* module, const uint8_t* bytes, const uint8_t* end);

M3Result ParseSection_Custom(M3Module* module, const uint8_t* bytes, const uint8_t* end);   // 0x035670
M3Result ParseSection_Type(M3Module* module, const uint8_t* bytes, const uint8_t* end);     // 0x033008
M3Result ParseSection_Import(M3Module* module, const uint8_t* bytes, const uint8_t* end);   // 0x0338cc
M3Result ParseSection_Function(M3Module* module, const uint8_t* bytes, const uint8_t* end); // 0x0335f8
M3Result ParseSection_Table(M3Module* module, const uint8_t* bytes, const uint8_t* end);    // 0x034e98
M3Result ParseSection_Memory(M3Module* module, const uint8_t* bytes, const uint8_t* end);   // 0x035190
M3Result ParseSection_Global(M3Module* module, const uint8_t* bytes, const uint8_t* end);   // 0x0353d8
M3Result ParseSection_Export(M3Module* module, const uint8_t* bytes, const uint8_t* end);   // 0x0342e0
M3Result ParseSection_Start(M3Module* module, const uint8_t* bytes, const uint8_t* end);    // 0x034678
M3Result ParseSection_Element(M3Module* module, const uint8_t* bytes, const uint8_t* end);  // 0x034758
M3Result ParseSection_Code(M3Module* module, const uint8_t* bytes, const uint8_t* end);     // 0x034848
M3Result ParseSection_Data(M3Module* module, const uint8_t* bytes, const uint8_t* end);     // 0x034a58

/**
 * @brief Returns the 12-entry section parser jump table matching `.data.rel.ro 0x03b888..0x03b8e8`.
 *        Trả về bảng nhảy 12 hàm phân tích section khớp với `.data.rel.ro 0x03b888..0x03b8e8`.
 */
const M3SectionParser* GetSectionParserTable() noexcept;

// ============================================================================
// 3. Wasm3 Object Wrappers (`Wasm3Memory`, `Wasm3Table`, `Wasm3Global`, `Wasm3Function`)
//    Các lớp bao đối tượng thực thi Wasm3 ([QUAN SÁT ĐƯỢC])
// ============================================================================

/**
 * @brief Linear Memory Wrapper (`vmsdk::wasm3::Wasm3Memory`).
 *        Lớp quản lý bộ nhớ tuyến tính 64KB/trang (`Wasm3Memory`).
 *
 * [OBSERVED] Enforces maximum 65,536 pages (`4 GiB`), supports `.grow(delta_pages)`
 * with detached-buffer notification callback (`SetDetachBufferCallback`).
 */
class Wasm3Memory {
public:
    using DetachCallback = std::function<void(uint8_t* new_ptr, size_t new_byte_length)>;

    Wasm3Memory(uint32_t initial_pages, uint32_t max_pages, bool has_max);
    ~Wasm3Memory();

    uint8_t* data() noexcept;
    const uint8_t* data() const noexcept;
    size_t byte_length() const noexcept { return static_cast<size_t>(num_pages_) * kWasmPageSizeBytes; }
    uint32_t num_pages() const noexcept { return num_pages_; }
    uint32_t max_pages() const noexcept { return max_pages_; }
    bool has_max() const noexcept { return has_max_; }
    M3MemoryHeader* header() noexcept { return header_; }

    /**
     * @brief Grows linear memory by `delta_pages` (64 KiB each).
     *        Returns previous page count on success, or `-1` if limit exceeded / OOM.
     *        Mở rộng bộ nhớ tuyến tính thêm `delta_pages` trang (mỗi trang 64 KiB).
     */
    int32_t Grow(uint32_t delta_pages);

    void SetDetachCallback(DetachCallback cb) { detach_cb_ = std::move(cb); }

private:
    M3MemoryHeader* header_;
    uint32_t        num_pages_;
    uint32_t        max_pages_;
    bool            has_max_;
    DetachCallback  detach_cb_;
};

/**
 * @brief Indirect Function Table Wrapper (`vmsdk::wasm3::Wasm3Table`).
 *        Lớp quản lý bảng tham chiếu hàm gián tiếp (`Wasm3Table`).
 */
class Wasm3Table {
public:
    Wasm3Table(M3ValueType element_type, uint32_t initial_size, uint32_t max_size, bool has_max);
    ~Wasm3Table();

    M3ValueType element_type() const noexcept { return element_type_; }
    uint32_t length() const noexcept { return static_cast<uint32_t>(elements_.size()); }
    uint32_t max_size() const noexcept { return max_size_; }
    bool has_max() const noexcept { return has_max_; }

    bool Set(uint32_t index, std::shared_ptr<Wasm3Function> func, LEPUSValue raw_ref = MakeLepusNull());
    std::shared_ptr<Wasm3Function> GetFunction(uint32_t index, bool* out_bounds_ok = nullptr) const;
    LEPUSValue GetRawRef(uint32_t index, bool* out_bounds_ok = nullptr) const;
    int32_t Grow(uint32_t delta, std::shared_ptr<Wasm3Function> fill_func = nullptr,
                 LEPUSValue fill_ref = MakeLepusNull());

private:
    M3ValueType                                  element_type_;
    uint32_t                                     max_size_;
    bool                                         has_max_;
    std::vector<std::shared_ptr<Wasm3Function>>  elements_;
    std::vector<LEPUSValue>                      raw_refs_;
};

/**
 * @brief Global Variable Wrapper (`vmsdk::wasm3::Wasm3Global`).
 *        Lớp quản lý biến toàn cục WebAssembly (`Wasm3Global`).
 */
class Wasm3Global {
public:
    Wasm3Global(M3ValueType type, bool is_mutable, int64_t initial_bits = 0);
    ~Wasm3Global() = default;

    M3ValueType type() const noexcept { return type_; }
    bool is_mutable() const noexcept { return is_mutable_; }

    int32_t GetI32() const noexcept { return val_.i32; }
    int64_t GetI64() const noexcept { return val_.i64; }
    float   GetF32() const noexcept { return val_.f32; }
    double  GetF64() const noexcept { return val_.f64; }
    int64_t GetRawBits() const noexcept { return val_.i64; }

    bool SetI32(int32_t v) noexcept;
    bool SetI64(int64_t v) noexcept;
    bool SetF32(float v) noexcept;
    bool SetF64(double v) noexcept;
    bool SetRawBits(int64_t bits) noexcept;

private:
    M3ValueType type_;
    bool        is_mutable_;
    union {
        int32_t i32;
        int64_t i64;
        float   f32;
        double  f64;
    } val_;
};

/**
 * @brief Value Union for Wasm Function Arguments & Results (`WasmVal`).
 *        Kiểu dữ liệu hợp nhất cho tham số và kết quả trả về của hàm Wasm.
 */
struct WasmVal {
    M3ValueType type = c_m3Type_none;
    union {
        int32_t i32;
        int64_t i64;
        float   f32;
        double  f64;
        void*   ref;
    } of{};

    static WasmVal MakeI32(int32_t v) noexcept { WasmVal w; w.type = c_m3Type_i32; w.of.i32 = v; return w; }
    static WasmVal MakeI64(int64_t v) noexcept { WasmVal w; w.type = c_m3Type_i64; w.of.i64 = v; return w; }
    static WasmVal MakeF32(float v) noexcept   { WasmVal w; w.type = c_m3Type_f32; w.of.f32 = v; return w; }
    static WasmVal MakeF64(double v) noexcept  { WasmVal w; w.type = c_m3Type_f64; w.of.f64 = v; return w; }
};

/**
 * @brief Wasm Function Wrapper (`vmsdk::wasm3::Wasm3Function`).
 *        Lớp quản lý hàm WebAssembly hoặc hàm Host nhập khẩu (`Wasm3Function`).
 */
class Wasm3Function {
public:
    using HostCallback = std::function<M3Result(const std::vector<WasmVal>& args,
                                                std::vector<WasmVal>* results)>;

    Wasm3Function(Wasm3Module* parent_module, uint32_t func_index, M3Function* m3_func);
    Wasm3Function(const std::string& name,
                  const std::vector<M3ValueType>& arg_types,
                  const std::vector<M3ValueType>& ret_types,
                  HostCallback host_cb);
    ~Wasm3Function() = default;

    const std::string& name() const noexcept { return name_; }
    uint32_t func_index() const noexcept { return func_index_; }
    const std::vector<M3ValueType>& arg_types() const noexcept { return arg_types_; }
    const std::vector<M3ValueType>& ret_types() const noexcept { return ret_types_; }
    M3Function* raw_function() const noexcept { return m3_func_; }
    bool is_host() const noexcept { return static_cast<bool>(host_cb_); }

    void SetHostCallback(HostCallback cb) { host_cb_ = std::move(cb); }

    /**
     * @brief Invokes this Wasm function (either via the Wasm3 bytecode interpreter
     *        or the bound JS/Host callback).
     *        Gọi thực thi hàm Wasm (qua trình thông dịch bytecode Wasm3 hoặc hàm Host).
     */
    M3Result Call(const std::vector<WasmVal>& args, std::vector<WasmVal>* results);

private:
    Wasm3Module*             parent_module_;
    uint32_t                 func_index_;
    M3Function*              m3_func_;
    std::string              name_;
    std::vector<M3ValueType> arg_types_;
    std::vector<M3ValueType> ret_types_;
    HostCallback             host_cb_;
};

/**
 * @brief Extra Module Metadata for C++ vector storage attached at `M3Module::extraMetadata`.
 *        Siêu dữ liệu mở rộng gắn tại trường `M3Module::extraMetadata`.
 */
struct M3ModuleExtraMetadata {
    std::vector<M3ExportInfo>       exports;
    std::vector<M3ImportDescriptor> imports;
};

/**
 * @brief Wasm3 Module Wrapper (`vmsdk::wasm3::Wasm3Module`).
 *        Lớp bao Module WebAssembly (`Wasm3Module`).
 */
class Wasm3Module : public std::enable_shared_from_this<Wasm3Module> {
public:
    Wasm3Module(std::shared_ptr<Wasm3Runtime> runtime,
                M3Module* raw_module,
                std::vector<uint8_t> wasm_bytes);
    ~Wasm3Module();

    M3Module* raw_module() const noexcept { return raw_module_; }
    std::shared_ptr<Wasm3Runtime> runtime() const noexcept { return runtime_; }

    const std::vector<M3ExportInfo>& exports() const noexcept;
    const std::vector<M3ImportDescriptor>& imports() const noexcept;
    std::vector<M3CustomSection> custom_sections(const std::string& section_name) const;

    std::shared_ptr<Wasm3Memory> memory() const noexcept { return memory_; }
    std::shared_ptr<Wasm3Table> table() const noexcept { return table_; }
    std::shared_ptr<Wasm3Function> GetFunction(uint32_t index) const;
    std::shared_ptr<Wasm3Global> GetGlobal(uint32_t index) const;

    void SetImportedMemory(std::shared_ptr<Wasm3Memory> mem) { memory_ = std::move(mem); }
    void SetImportedTable(std::shared_ptr<Wasm3Table> tbl) { table_ = std::move(tbl); }
    bool BindImportFunction(uint32_t import_func_index, Wasm3Function::HostCallback cb);
    bool BindImportGlobal(uint32_t import_global_index, std::shared_ptr<Wasm3Global> global);

    /**
     * @brief Loads and links the module into the runtime, initializes memory/table/data/element
     *        segments, and runs the start function if present.
     *        Nạp và liên kết module vào runtime, khởi tạo bộ nhớ/bảng/phân đoạn dữ liệu và chạy hàm start.
     */
    M3Result LoadAndInitialize();

private:
    std::shared_ptr<Wasm3Runtime>               runtime_;
    M3Module*                                   raw_module_;
    std::vector<uint8_t>                        wasm_bytes_;
    std::shared_ptr<Wasm3Memory>                memory_;
    std::shared_ptr<Wasm3Table>                 table_;
    std::vector<std::shared_ptr<Wasm3Function>> functions_;
    std::vector<std::shared_ptr<Wasm3Global>>   globals_;
    bool                                        is_loaded_;
};

/**
 * @brief Wasm3 Engine Runtime Wrapper (`vmsdk::wasm3::Wasm3Runtime`, 32 bytes @ `0x01026c`).
 *        Lớp quản lý máy ảo Wasm3 (`vmsdk::wasm3::Wasm3Runtime`, 32 byte tại `0x01026c`).
 */
class Wasm3Runtime : public std::enable_shared_from_this<Wasm3Runtime> {
public:
    explicit Wasm3Runtime(uint32_t stack_size_bytes = 65536U);
    ~Wasm3Runtime();

    M3Environment* environment() const noexcept { return env_; }
    M3Runtime* raw_runtime() const noexcept { return runtime_; }

    /**
     * @brief Parses and validates a WebAssembly binary buffer into a `Wasm3Module`.
     *        Phân tích và kiểm tra tính hợp lệ của buffer nhị phân WebAssembly thành `Wasm3Module`.
     */
    std::shared_ptr<Wasm3Module> ParseModule(const uint8_t* bytes,
                                             size_t size,
                                             M3Result* out_error = nullptr);

    /**
     * @brief Fast binary validation for `WebAssembly.validate(bufferSource)`.
     *        Kiểm tra nhanh cấu trúc nhị phân cho hàm `WebAssembly.validate(bufferSource)`.
     */
    bool ValidateModule(const uint8_t* bytes, size_t size, M3Result* out_error = nullptr);

private:
    void*          vtable_reserved_; // +0x00 (matches 32-byte C++ polymorphic layout)
    M3Environment* env_;             // +0x08
    M3Runtime*     runtime_;         // +0x10
    uint64_t       flags_;           // +0x18
};

/**
 * @brief Per-JSContext Interop Runtime (`vmsdk::InteropRuntime`, 120 bytes = `0x78` @ `0x01020c`).
 *        Ngữ cảnh điều phối liên thông JS-Wasm (`InteropRuntime`, 120 byte = `0x78` tại `0x01020c`).
 *
 * [OBSERVED] Allocated in `RegisterWebAssembly` (`0x01020c: mov w0, #0x78; bl operator new`),
 * stored as opaque pointer on the `globalThis.WebAssembly` object via `LEPUS_SetOpaque`.
 */
struct InteropRuntime {
    LEPUSContext*                  ctx               = nullptr; // +0x00
    LEPUSRuntime*                  rt                = nullptr; // +0x08
    std::atomic<bool>*             is_terminated     = nullptr; // +0x10
    WasmRuntimeType                runtime_type      = WasmRuntimeType::kWasm3; // +0x18
    uint32_t                       reserved_flags    = 0;       // +0x1C
    std::shared_ptr<Wasm3Runtime>  wasm3_runtime;               // +0x20 (16 bytes)
    WASMGCPersistent               webassembly_obj;             // +0x30
    WASMGCPersistent               module_ctor;                 // +0x48
    WASMGCPersistent               instance_ctor;               // +0x60

    // Additional constructors & errors tracked for JS instantiation & error reporting
    WASMGCPersistent               memory_ctor;
    WASMGCPersistent               table_ctor;
    WASMGCPersistent               global_ctor;
    WASMGCPersistent               compile_error_ctor;
    WASMGCPersistent               link_error_ctor;
    WASMGCPersistent               runtime_error_ctor;

    InteropRuntime(LEPUSContext* c, std::atomic<bool>* term, WasmRuntimeType type);
    ~InteropRuntime();

    static InteropRuntime* FromContext(LEPUSContext* ctx);
};

} // namespace wasm
} // namespace vmsdk

#endif // NEXTAI_OPENCUT_LIBWASM_WASM_M3_RUNTIME_H_
