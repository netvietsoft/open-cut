// ============================================================================
// File: jazz_platform_runtime_vm.h
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Subsystem: AmazingEngine::Engine, VM, VM::VMScope, Runtime, PlatformInternal,
//            Platform, CreateQuickJSPlatform, CreateQuickJSVM, and S-Box Decoder
//Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (TASK_SO_122_libjazz)
// ============================================================================
// [EN] Clean-room C++17 header reconstructing the JavaScript Engine, Virtual
//      Machine (`AmazingEngine::VM`), QuickJS / Lepus bridge (`CreateQuickJSVM`
//      @ 0x024638, `CreateQuickJSPlatform` @ 0x02450c), Runtime lifecycle
//      (`AmazingEngine::Runtime` @ 0x018fd8..0x0195c0), Platform thread pool
//      orchestrator (`AmazingEngine::Platform` @ 0x014a30..0x015bcc), and the
//      256-byte GF(2)^8 affine involution S-Box decoder (`sub_17a08` @ 0x017a08)
//      that decrypts `/bootstrap.js` (.rodata 0x027037, 7,097 bytes) and
//      `makeRequire.js` (.rodata 0x0297d2, 582 bytes).
// [VN] File header C++17 tái tạo sạch tầng Máy ảo JavaScript (`AmazingEngine::VM`),
//      cầu nối QuickJS / Lepus (`CreateQuickJSVM` @ 0x024638, `CreateQuickJSPlatform`
//      @ 0x02450c), vòng đời Runtime (`AmazingEngine::Runtime` @ 0x018fd8..0x0195c0),
//      bộ điều phối Platform (`AmazingEngine::Platform` @ 0x014a30..0x015bcc), và
//      bộ giải mã hộp thế S-Box đối hợp affine GF(2)^8 256-byte (`sub_17a08` @ 0x017a08)
//      giải mã `/bootstrap.js` (.rodata 0x027037, 7.097 byte) cùng `makeRequire.js`
//      (.rodata 0x0297d2, 582 byte).
// ============================================================================

#ifndef JAZZ_PLATFORM_RUNTIME_VM_H_
#define JAZZ_PLATFORM_RUNTIME_VM_H_

#include "jazz_types.h"
#include "jazz_runner_context.h"

namespace AmazingEngine {

// ============================================================================
// 1. 256-Byte GF(2)^8 Affine Involution S-Box & Embedded Script Bundles
//    (sub_17a08 @ 0x017a08..0x017a38, Table at .rodata 0x028bf0..0x028cf0)
// ============================================================================
// [EN] Exact 256-byte lookup table extracted from .rodata 0x028bf0..0x028cf0
//      and its closed-form GF(2)^8 algebraic evaluation (`sub_17a08`).
// [VN] Bảng tra cứu 256-byte trích xuất chính xác từ .rodata 0x028bf0..0x028cf0
//      và hàm tính đại số đóng trên GF(2)^8 (`sub_17a08`).
extern const uint8_t kJazzSBoxTable_28bf0[256];

// [EN] Decodes `len - 1` bytes from `src` through `kJazzSBoxTable_28bf0` into
//      `dst` and writes a trailing NUL byte (`dst[len - 1] = 0`), matching
//      `sub_17a08(char* dst, const uint8_t* src, size_t len)` at 0x017a08.
// [VN] Giải mã `len - 1` byte từ `src` qua bảng `kJazzSBoxTable_28bf0` vào `dst`
//      và ghi byte kết thúc NUL (`dst[len - 1] = 0`), khớp tuyệt đối với
//      `sub_17a08(char* dst, const uint8_t* src, size_t len)` tại 0x017a08.
void JazzSBoxDecodeBuffer(char* dst, const uint8_t* src, size_t len) noexcept;

// [EN] Convenience C++ string helper for S-Box decoding / encoding (since SBox
//      is an involution: SBox[SBox[x]] == x).
// [VN] Hàm tiện ích C++ std::string để giải mã / mã hóa S-Box (do SBox là phép
//      đối hợp: SBox[SBox[x]] == x).
std::string JazzSBoxTransformString(const uint8_t* src, size_t lenWithNull);
std::vector<uint8_t> JazzSBoxEncodeStringWithNull(const std::string& plain);

// [EN] Returns the reconstructed `/bootstrap.js` script decoded at runtime by
//      Platform::CreateRuntime (0x0178d4) and Platform::CreateNewContextInRuntime
//      (0x017f80) from .rodata 0x027037 (0x1bb9 = 7,097 bytes -> 7,096 chars).
// [VN] Trả về kịch bản `/bootstrap.js` được giải mã lúc chạy bởi
//      Platform::CreateRuntime (0x0178d4) và Platform::CreateNewContextInRuntime
//      (0x017f80) từ .rodata 0x027037 (0x1bb9 = 7.097 byte -> 7.096 ký tự).
const std::string& GetDecodedBootstrapJs();

// [EN] Returns the exact 582-byte obfuscated payload at .rodata 0x0297d2..0x029a18
//      and the decoded 581-char `makeRequire.js` script used by RequireModule
//      (0x0216c4).
// [VN] Trả về mảng 582 byte mã hóa tại .rodata 0x0297d2..0x029a18 và kịch bản
//      `makeRequire.js` dài 581 ký tự sau giải mã dùng bởi RequireModule (0x0216c4).
const uint8_t* GetEncodedMakeRequireJsBytes(size_t* outLen) noexcept;
std::string GetDecodedMakeRequireJs();

// ============================================================================
// 2. AmazingEngine::Engine (0x0126b8..0x0126ec, vtable @ 0x03a438)
// ============================================================================
// [EN] Base polymorphic interface for JS engines (`Engine::Engine()` @ 0x0126b8,
//      `Engine::~Engine()` @ 0x0126c0, deleting dtor @ 0x0126c4).
// [VN] Giao diện đa hình cơ sở cho các JS engine (`Engine::Engine()` @ 0x0126b8,
//      `Engine::~Engine()` @ 0x0126c0, hàm hủy xóa vùng nhớ @ 0x0126c4).
class Engine {
public:
    Engine() noexcept;
    virtual ~Engine() noexcept;
};

// ============================================================================
// 3. AmazingEngine::VM & VM::VMScope (0x0126f4..0x012798, 0x01a42c..0x01a558)
// ============================================================================
// [EN] Virtual Machine wrapper managing an underlying QuickJS `LEPUSRuntime*`
//      and active context stack (`VM::CreateVM(JSEngineType)` @ 0x01a46c).
//      In `CreateQuickJSVM` (`0x024638`), 16 bytes (`0x10`) are allocated:
//      `+0x00`: vtable pointer (`0x03b0f8`)
//      `+0x08`: `LEPUSRuntime* m_lepusRuntime` (initialized with
//               `LEPUS_SetRuntimeInfo(rt, "effect")` at 0x024658).
// [VN] Lớp bao Máy ảo quản lý `LEPUSRuntime*` của QuickJS và ngăn xếp ngữ cảnh
//      (`VM::CreateVM(JSEngineType)` @ 0x01a46c).
//      Trong `CreateQuickJSVM` (`0x024638`), 16 byte (`0x10`) được cấp phát:
//      `+0x00`: con trỏ vtable (`0x03b0f8`)
//      `+0x08`: `LEPUSRuntime* m_lepusRuntime` (khởi tạo cùng
//               `LEPUS_SetRuntimeInfo(rt, "effect")` tại 0x024658).
class VM {
public:
    // ------------------------------------------------------------------------
    // VM::VMScope (0x0126f4..0x012798)
    // ------------------------------------------------------------------------
    // [EN] RAII scope guard entering a VM context (`VMScope(VM*)` @ 0x0126f4,
    //      `VMScope(const shared_ptr<VM>&)` @ 0x012738, `~VMScope()` @ 0x01278c).
    // [VN] Lớp bảo vệ phạm vi RAII khi đi vào ngữ cảnh VM (`VMScope(VM*)` @ 0x0126f4,
    //      `VMScope(const shared_ptr<VM>&)` @ 0x012738, `~VMScope()` @ 0x01278c).
    class VMScope {
    public:
        explicit VMScope(VM* vm);
        explicit VMScope(const std::shared_ptr<VM>& vm);
        ~VMScope();

        VMScope(const VMScope&) = delete;
        VMScope& operator=(const VMScope&) = delete;

    private:
        VM* m_vm{nullptr};  // +0x00
    };

    VM();
    virtual ~VM();

    // [EN] Virtual hooks matching QuickJSVM vtable @ 0x03b0f8 (`0x024668..0x024950`).
    // [VN] Các phương thức ảo khớp với vtable QuickJSVM @ 0x03b0f8 (`0x024668..0x024950`).
    virtual void Enter();
    virtual void Leave();
    virtual std::shared_ptr<Context> CreateContext();
    virtual void SetLoadFileFunction(std::function<std::string(const std::string&)> func);
    virtual std::string LoadFile(const std::string& path);

    // [EN] Static factory `VM::CreateVM(JSEngineType)` @ 0x01a46c:
    //      Checks `cmp w0, #2` (`JSEngineType::QUICKJS == 2` at 0x01a488) and
    //      dispatches to `CreateQuickJSVM()`.
    // [VN] Nhà máy tĩnh `VM::CreateVM(JSEngineType)` @ 0x01a46c:
    //      Kiểm tra `cmp w0, #2` (`JSEngineType::QUICKJS == 2` tại 0x01a488) và
    //      điều phối tới `CreateQuickJSVM()`.
    static std::shared_ptr<VM> CreateVM(JSEngineType type);

    LEPUSRuntime* GetLepusRuntime() const noexcept { return m_lepusRuntime; }
    uint32_t GetEnterCount() const noexcept { return m_enterCount; }

protected:
    LEPUSRuntime* m_lepusRuntime{nullptr};                           // +0x08
    std::string m_runtimeInfo{"effect"};                             // "effect" @ 0x02702f
    uint32_t m_enterCount{0};                                        // Scope depth counter
    std::function<std::string(const std::string&)> m_loadFileFunc;   // File loader callback
};

// [EN] QuickJS Engine & VM factory functions (`0x02450c` and `0x024638`).
// [VN] Các hàm khởi tạo QuickJS Engine & VM (`0x02450c` và `0x024638`).
std::unique_ptr<Engine> CreateQuickJSPlatform();
std::shared_ptr<VM> CreateQuickJSVM();

// ============================================================================
// 4. AmazingEngine::Runtime (0x018fd8..0x0195c0, vtable @ 0x03ac30)
// ============================================================================
// [EN] Represents an isolated JS execution runtime owning a `VM`, a runner
//      thread (`BEFBaseRunner`), a map of `Context` instances, a map of
//      `ModuleRegistry` objects, and a primary `ContextExecutor`.
//      Memory layout verified from `Runtime::Runtime(RuntimeMode)` @ 0x018fd8:
//      `+0x00`: vtable pointer (`0x03ac30`)
//      `+0x08`: `int64_t m_id` (initialized to `-1` via `mov x8, #-1; str x8, [x0, #8]`)
//      `+0x10`: `int32_t m_state` (`0` = created, `1` = running, `2` = destroyed)
//      `+0x18`: `RuntimeMode m_mode` (`str w1, [x0, #0x18]`)
//      `+0x20`: `std::shared_ptr<BEFBaseRunner> m_runner` (16 bytes)
//      `+0x30`: `std::shared_ptr<VM> m_vm` (16 bytes)
//      `+0x40`: `std::shared_ptr<ContextExecutor> m_executor` (16 bytes)
//      `+0x50..0x70`: `unordered_map<int, shared_ptr<Context>>` (`1.0f` at `+0x68`)
//      `+0x78..0x98`: `unordered_map<string, shared_ptr<ModuleRegistry>>` (`1.0f` at `+0x90`)
// [VN] Đại diện cho một môi trường thực thi JS cô lập sở hữu một `VM`, một luồng
//      chạy (`BEFBaseRunner`), bảng ánh xạ các `Context`, bảng ánh xạ `ModuleRegistry`,
//      và bộ thực thi `ContextExecutor` chính.
class Runtime {
public:
    explicit Runtime(RuntimeMode mode);
    virtual ~Runtime();

    int64_t GetId() const noexcept { return m_id; }
    void SetId(int64_t id) noexcept { m_id = id; }

    RuntimeMode GetMode() const noexcept { return m_mode; }
    int32_t GetState() const noexcept { return m_state; }
    void SetState(int32_t state) noexcept { m_state = state; }

    std::shared_ptr<BEFBaseRunner> GetRunner() const noexcept { return m_runner; }
    void SetRunner(const std::shared_ptr<BEFBaseRunner>& runner) { m_runner = runner; }

    std::shared_ptr<VM> GetVM() const noexcept { return m_vm; }
    void SetVM(const std::shared_ptr<VM>& vm) { m_vm = vm; }

    std::shared_ptr<ContextExecutor> GetExecutor() const noexcept { return m_executor; }
    void SetExecutor(const std::shared_ptr<ContextExecutor>& executor) { m_executor = executor; }

    void AddContext(int32_t contextId, const std::shared_ptr<Context>& ctx);
    std::shared_ptr<Context> GetContext(int32_t contextId) const;
    void ClearContexts();

private:
    int64_t m_id{-1};                                              // +0x08 (-1 default)
    int32_t m_state{0};                                            // +0x10
    RuntimeMode m_mode{RuntimeMode::SINGLE_CONTEXT};               // +0x18
    std::shared_ptr<BEFBaseRunner> m_runner;                       // +0x20
    std::shared_ptr<VM> m_vm;                                      // +0x30
    std::shared_ptr<ContextExecutor> m_executor;                   // +0x40
    std::unordered_map<int32_t, std::shared_ptr<Context>> m_contexts; // +0x50 (load_factor 1.0f @ +0x68)
    float m_contextMapMaxLoadFactor{1.0f};                         // +0x68 (0x3f800000)
    float m_moduleMapMaxLoadFactor{1.0f};                          // +0x90 (0x3f800000)
};

// ============================================================================
// 5. AmazingEngine::PlatformInternal & AmazingEngine::Platform
//    (0x014a30..0x015bcc, vtable @ 0x03a568)
// ============================================================================
// [EN] Internal state structure (`PlatformInternal` @ 0x014ac8, 80 bytes = 0x50)
//      allocated by `Platform::Platform(JSEngineType)` (`0x014a30`):
//      `+0x00`: `JSEngineType m_engineType`
//      `+0x08`: `std::unique_ptr<Engine> m_engine` (`CreateQuickJSPlatform()`)
//      `+0x10..0x38`: `std::mutex m_mutex` (40 bytes on AArch64 bionic)
//      `+0x38`: `std::shared_ptr<BEFBaseRunner> m_platformRunner`
//      `+0x40`: `std::atomic<int64_t> m_nextRuntimeId` (initialized to 1,
//               incremented atomically via `ldaxr`/`stlxr` at 0x015068..0x015074)
//      `+0x48`: `std::unordered_map<int64_t, std::shared_ptr<Runtime>> m_runtimes`
// [VN] Cấu trúc trạng thái nội bộ (`PlatformInternal` @ 0x014ac8, 80 byte = 0x50)
//      được cấp phát bởi `Platform::Platform(JSEngineType)` (`0x014a30`):
//      `+0x00`: `JSEngineType m_engineType`
//      `+0x08`: `std::unique_ptr<Engine> m_engine` (`CreateQuickJSPlatform()`)
//      `+0x10..0x38`: `std::mutex m_mutex` (40 byte trên AArch64 bionic)
//      `+0x38`: `std::shared_ptr<BEFBaseRunner> m_platformRunner`
//      `+0x40`: `std::atomic<int64_t> m_nextRuntimeId` (khởi tạo bằng 1,
//               tăng nguyên tử qua `ldaxr`/`stlxr` tại 0x015068..0x015074)
//      `+0x48`: `std::unordered_map<int64_t, std::shared_ptr<Runtime>> m_runtimes`
class PlatformInternal {
public:
    explicit PlatformInternal(JSEngineType type);
    ~PlatformInternal();

    JSEngineType m_engineType{JSEngineType::QUICKJS};                  // +0x00
    std::unique_ptr<Engine> m_engine;                                  // +0x08
    mutable std::mutex m_mutex;                                        // +0x10
    std::shared_ptr<BEFBaseRunner> m_platformRunner;                   // +0x38
    std::atomic<int64_t> m_nextRuntimeId{1};                           // +0x40
    std::unordered_map<int64_t, std::shared_ptr<Runtime>> m_runtimes;  // +0x48
    std::function<std::string(const std::string&)> m_fileLoader;
};

// [EN] Top-level Jazz Platform controller (`AmazingEngine::Platform` @ 0x014a30..0x015bcc).
// [VN] Bộ điều khiển Platform cấp cao nhất của Jazz (`AmazingEngine::Platform` @ 0x014a30..0x015bcc).
class Platform {
public:
    explicit Platform(JSEngineType type);
    virtual ~Platform();

    // [EN] `Platform::CreateRuntime(RuntimeMode)` @ 0x014fcc:
    //      Allocates a `Runtime`, assigns atomic ID (`ldaxr`/`stlxr` on `+0x40`),
    //      creates a `VM` via `VM::CreateVM`, decodes `/bootstrap.js` (7,097 B
    //      at 0x027037) via `sub_17a08` (`0x0178d4`), and executes it in the
    //      runtime's root context.
    // [VN] `Platform::CreateRuntime(RuntimeMode)` @ 0x014fcc:
    //      Cấp phát `Runtime`, gán ID nguyên tử (`ldaxr`/`stlxr` tại `+0x40`),
    //      tạo `VM` qua `VM::CreateVM`, giải mã `/bootstrap.js` (7.097 byte
    //      tại 0x027037) qua `sub_17a08` (`0x0178d4`), và thực thi trong
    //      ngữ cảnh gốc của runtime.
    int64_t CreateRuntime(RuntimeMode mode);

    // [EN] `Platform::CreateNewContextInRuntime(long)` @ 0x0152ac:
    //      Creates an additional context inside a `MULTI_CONTEXT` runtime and
    //      evaluates decoded `/bootstrap.js` (`0x017f80`).
    // [VN] `Platform::CreateNewContextInRuntime(long)` @ 0x0152ac:
    //      Tạo thêm ngữ cảnh mới bên trong runtime `MULTI_CONTEXT` và thực thi
    //      `/bootstrap.js` đã giải mã (`0x017f80`).
    int32_t CreateNewContextInRuntime(int64_t runtimeId);

    // [EN] `Platform::SetFileLoadingFunction(long, std::function<...>)` @ 0x0153a4.
    // [VN] `Platform::SetFileLoadingFunction(long, std::function<...>)` @ 0x0153a4.
    void SetFileLoadingFunction(int64_t runtimeId,
                                std::function<std::string(const std::string&)> loader);

    // [EN] `Platform::LoadScriptFile(long, const std::string&)` @ 0x01549c.
    // [VN] `Platform::LoadScriptFile(long, const std::string&)` @ 0x01549c.
    Value LoadScriptFile(int64_t runtimeId, const std::string& filePath);

    // [EN] `Platform::ExecuteProgram(long, const std::string&, const std::string&)` @ 0x0155a4.
    // [VN] `Platform::ExecuteProgram(long, const std::string&, const std::string&)` @ 0x0155a4.
    Value ExecuteProgram(int64_t runtimeId,
                         const std::string& code,
                         const std::string& filename = "<eval>");

    // [EN] `Platform::CallFunction(long, Value, const std::string&, const std::vector<Value>&)` @ 0x0156b4.
    // [VN] `Platform::CallFunction(long, Value, const std::string&, const std::vector<Value>&)` @ 0x0156b4.
    Value CallFunction(int64_t runtimeId,
                       Value thisObj,
                       const std::string& funcName,
                       const std::vector<Value>& args);

    // [EN] `Platform::DestroyRuntime(long)` @ 0x015928 & `Platform::Shutdown()` @ 0x015abc.
    // [VN] `Platform::DestroyRuntime(long)` @ 0x015928 & `Platform::Shutdown()` @ 0x015abc.
    bool DestroyRuntime(int64_t runtimeId);
    void Shutdown();

    std::shared_ptr<Runtime> GetRuntime(int64_t runtimeId) const;

private:
    std::unique_ptr<PlatformInternal> m_internal;  // +0x08
};

} // namespace AmazingEngine

#endif // JAZZ_PLATFORM_RUNTIME_VM_H_
