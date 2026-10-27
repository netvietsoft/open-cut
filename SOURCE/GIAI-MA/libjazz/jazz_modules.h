// ============================================================================
// File: jazz_modules.h
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Subsystem: AmazingEngine::FileSystemModule, FileSystemModule::Stats,
//            ModuleRegistry, RequireModule, TimerModule, TimerModule::TimerTask
// Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (TASK_SO_122_libjazz)
// ============================================================================
// [EN] Clean-room C++17 header reconstructing the built-in native JS modules
//      inside `libjazz.so`:
//      1. `AmazingEngine::FileSystemModule` & `Stats` (0x01ac8c..0x01d1c8)
//      2. `AmazingEngine::ModuleRegistry` (0x020d00..0x020fc8)
//      3. `AmazingEngine::RequireModule` (0x021618..0x021fb8) + NEON popcount
//         hash bucket reducer (`0x0220b4` & `0x0221c4`)
//      4. `AmazingEngine::TimerModule` & `TimerTask` (0x022bb4..0x023f28)
// [VN] File header C++17 tái tạo sạch các module JS gốc tích hợp trong `libjazz.so`:
//      1. `AmazingEngine::FileSystemModule` & `Stats` (0x01ac8c..0x01d1c8)
//      2. `AmazingEngine::ModuleRegistry` (0x020d00..0x020fc8)
//      3. `AmazingEngine::RequireModule` (0x021618..0x021fb8) + hàm thu gọn
//         bucket bảng băm dùng NEON popcount (`0x0220b4` & `0x0221c4`)
//      4. `AmazingEngine::TimerModule` & `TimerTask` (0x022bb4..0x023f28)
// ============================================================================

#ifndef JAZZ_MODULES_H_
#define JAZZ_MODULES_H_

#include "jazz_types.h"
#include "jazz_runner_context.h"

namespace AmazingEngine {

// ============================================================================
// 1. AmazingEngine::FileSystemModule & Stats (0x01ac8c..0x01d1c8)
// ============================================================================
// [EN] Native filesystem bindings exposed to JS (`bootstrap.getNativeBinding("fs")`).
//      `FileSystemModule::Stats` wraps POSIX `struct stat` (128 bytes on AArch64
//      bionic at offset `+0x18..+0x98` of `Stats`):
//      - `st_mode` (`uint32_t`) sits at `Stats + 0x28` (`struct stat + 0x10`)
//      - `st_size` (`int64_t`) sits at `Stats + 0x48` (`struct stat + 0x30`)
// [VN] Liên kết hệ thống tệp gốc xuất lên JS (`bootstrap.getNativeBinding("fs")`).
//      `FileSystemModule::Stats` bọc cấu trúc POSIX `struct stat` (128 byte trên
//      AArch64 bionic tại độ lệch `+0x18..+0x98` của `Stats`):
//      - `st_mode` (`uint32_t`) nằm tại `Stats + 0x28` (`struct stat + 0x10`)
//      - `st_size` (`int64_t`) nằm tại `Stats + 0x48` (`struct stat + 0x30`)
class FileSystemModule {
public:
    // ------------------------------------------------------------------------
    // FileSystemModule::Stats (0x01d074..0x01d1c8)
    // ------------------------------------------------------------------------
    class Stats {
    public:
        Stats() noexcept = default;
        Stats(uint32_t mode, int64_t size) noexcept
            : m_mode(mode), m_size(size) {}

        // [EN] `Stats::getSize()` @ 0x01d074:
        //      0x01d074: ldr d0, [x0, #0x48]
        //      0x01d078: scvtf d0, d0          ; 0x5e61d800
        //      0x01d07c: mov w0, #1            ; ValueType::NUMBER (double)
        //      0x01d080: ret
        // [VN] `Stats::getSize()` @ 0x01d074:
        //      Đọc `m_size` (`int64_t` tại `+0x48`), chuyển sang `double` bằng
        //      `scvtf d0, d0` (`0x5e61d800`) và trả về `Value` kiểu `NUMBER`.
        Value getSize() const noexcept;

        // [EN] `Stats::isDirectory()` @ 0x01d084:
        //      0x01d084: ldr w8, [x0, #0x28]
        //      0x01d088: and w8, w8, #0xf000   ; S_IFMT = 0xF000
        //      0x01d08c: mov w0, #2            ; ValueType::BOOLEAN
        //      0x01d090: cmp w8, #4, lsl #12   ; S_IFDIR = 0x4000
        //      0x01d094: cset w1, eq
        //      0x01d098: ret
        // [VN] `Stats::isDirectory()` @ 0x01d084:
        //      Kiểm tra `(m_mode & 0xF000) == 0x4000` (`S_IFDIR`).
        Value isDirectory() const noexcept;

        // [EN] `Stats::isFile()` @ 0x01d09c:
        //      0x01d09c: ldr w8, [x0, #0x28]
        //      0x01d0a0: and w8, w8, #0xf000   ; S_IFMT = 0xF000
        //      0x01d0a4: mov w0, #2            ; ValueType::BOOLEAN
        //      0x01d0a8: cmp w8, #8, lsl #12   ; S_IFREG = 0x8000
        //      0x01d0ac: cset w1, eq
        //      0x01d0b0: ret
        // [VN] `Stats::isFile()` @ 0x01d09c:
        //      Kiểm tra `(m_mode & 0xF000) == 0x8000` (`S_IFREG`).
        Value isFile() const noexcept;

        // [EN] `Stats::isSymbolicLink()` @ 0x01d0b4:
        //      Checks `(m_mode & 0xF000) == 0xA000` (`S_IFLNK`).
        // [VN] `Stats::isSymbolicLink()` @ 0x01d0b4:
        //      Kiểm tra `(m_mode & 0xF000) == 0xA000` (`S_IFLNK`).
        Value isSymbolicLink() const noexcept;

        uint32_t GetRawMode() const noexcept { return m_mode; }
        int64_t GetRawSize() const noexcept { return m_size; }

    private:
        uint8_t m_reservedHeader[0x28]{};  // +0x00..0x27 (vtable + stat prefix)
        uint32_t m_mode{0};                // +0x28 (st_mode)
        uint8_t m_reservedMid[0x1C]{};     // +0x2C..0x47
        int64_t m_size{0};                 // +0x48 (st_size)
    };

    FileSystemModule(Context* context,
                     const std::shared_ptr<BEFBaseRunner>& ioRunner,
                     const std::shared_ptr<BEFBaseRunner>& jsRunner);
    virtual ~FileSystemModule();

    // [EN] Synchronous & asynchronous POSIX filesystem operations (`0x01adb0..0x01cf1c`).
    // [VN] Các thao tác hệ thống tệp POSIX đồng bộ và bất đồng bộ (`0x01adb0..0x01cf1c`).
    Value accessSync(const std::string& path, int32_t mode = 0);
    void access(const std::string& path, int32_t mode, Value callback);

    Stats statSync(const std::string& path);
    void stat(const std::string& path, Value callback);

    Value readFileSync(const std::string& path, const std::string& encoding = "utf8");
    void readFile(const std::string& path, const std::string& encoding, Value callback);

    Value writeFileSync(const std::string& path, const std::string& content);
    void writeFile(const std::string& path, const std::string& content, Value callback);

    Value mkdirSync(const std::string& path, bool recursive = false);
    void mkdir(const std::string& path, bool recursive, Value callback);

    Value rmdirSync(const std::string& path);
    void rmdir(const std::string& path, Value callback);

    Value unlinkSync(const std::string& path);
    void unlink(const std::string& path, Value callback);

    std::vector<std::string> readdirSync(const std::string& path);
    void readdir(const std::string& path, Value callback);

private:
    Context* m_context{nullptr};                    // +0x08
    std::shared_ptr<BEFBaseRunner> m_ioRunner;      // +0x10
    std::shared_ptr<BEFBaseRunner> m_jsRunner;      // +0x20
    std::unordered_map<std::string, std::string> m_virtualFiles;
    std::unordered_map<std::string, uint32_t> m_virtualModes;
};

// ============================================================================
// 2. AmazingEngine::ModuleRegistry (0x020d00..0x020fc8, vtable @ 0x03ae58)
// ============================================================================
// [EN] Registry of native and script modules bound to a `Context`.
//      Initializes internal `std::unordered_map` with `max_load_factor = 1.0f`
//      (`0x3f800000` at `+0x28` in `0x020d00`).
// [VN] Bộ đăng ký các module gốc và kịch bản gắn với một `Context`.
//      Khởi tạo `std::unordered_map` nội bộ với `max_load_factor = 1.0f`
//      (`0x3f800000` tại `+0x28` trong `0x020d00`).
class ModuleRegistry {
public:
    explicit ModuleRegistry(Context* context);
    virtual ~ModuleRegistry();

    void RegisterModule(const std::string& name, const Value& exportsObj);
    Value GetModule(const std::string& name) const;
    bool HasModule(const std::string& name) const;

private:
    Context* m_context{nullptr};                           // +0x08
    std::unordered_map<std::string, Value> m_modules;      // +0x10..0x30
    float m_maxLoadFactor{1.0f};                           // +0x28 (0x3f800000)
};

// ============================================================================
// 3. AmazingEngine::RequireModule (0x021618..0x021fb8, vtable @ 0x03aea0)
// ============================================================================
// [EN] CommonJS `require` implementation (`RequireModule::RequireModule` @ 0x021618)
//      that decodes `makeRequire.js` (582 bytes at `.rodata 0x0297d2`) via
//      `sub_17a08` at `0x0216c4`, resolves relative paths (`./`, `../`, `.js`,
//      `.json`), caches module exports, and evaluates wrapped modules.
// [VN] Bản cài đặt `require` chuẩn CommonJS (`RequireModule::RequireModule` @ 0x021618)
//      giải mã `makeRequire.js` (582 byte tại `.rodata 0x0297d2`) qua `sub_17a08`
//      tại `0x0216c4`, phân giải đường dẫn tương đối (`./`, `../`, `.js`, `.json`),
//      lưu đệm module exports và thực thi module đã bọc.
class RequireModule {
public:
    explicit RequireModule(Context* context);
    virtual ~RequireModule();

    // [EN] `RequireModule::CreateRequireFunction(const std::string& parentDir)` @ 0x0217b8.
    // [VN] `RequireModule::CreateRequireFunction(const std::string& parentDir)` @ 0x0217b8.
    Value CreateRequireFunction(const std::string& parentDir);

    // [EN] `RequireModule::Require(const std::string& parentDir, const std::string& id)` @ 0x0218a4.
    // [VN] `RequireModule::Require(const std::string& parentDir, const std::string& id)` @ 0x0218a4.
    Value Require(const std::string& parentDir, const std::string& moduleId);

    // [EN] Resolves relative module path (`parentDir` + `moduleId`) normalizing
    //      `./` and `../` segments and appending `.js` if needed (`0x021b20`).
    // [VN] Phân giải đường dẫn module tương đối (`parentDir` + `moduleId`), chuẩn hóa
    //      các đoạn `./` và `../` đồng thời nối đuôi `.js` nếu cần (`0x021b20`).
    static std::string ResolveModulePath(const std::string& parentDir,
                                         const std::string& moduleId);

    // [EN] libc++ hash bucket index helper at `0x0220b4` & `0x0221c4` using
    //      AArch64 NEON `cnt v0.8b, v0.8b; uaddlv h0, v0.8b` population count:
    //      - If `bucket_count` is a power of two (`popcount(bc) == 1`), returns
    //        `hash & (bc - 1)`.
    //      - Otherwise returns `hash % bc`.
    // [VN] Hàm tính chỉ số bucket bảng băm libc++ tại `0x0220b4` & `0x0221c4`
    //      sử dụng lệnh đếm bit AArch64 NEON `cnt v0.8b, v0.8b; uaddlv h0, v0.8b`:
    //      - Nếu `bucket_count` là lũy thừa của 2 (`popcount(bc) == 1`), trả về
    //        `hash & (bc - 1)`.
    //      - Ngược lại trả về `hash % bc`.
    static size_t ComputeBucketIndexNeonPopcount(size_t hash, size_t bucketCount) noexcept;

    const std::string& GetMakeRequireScript() const noexcept { return m_makeRequireScript; }

private:
    Context* m_context{nullptr};                               // +0x08
    std::string m_makeRequireScript;                           // Decoded 581-char makeRequire.js
    std::unordered_map<std::string, Value> m_cachedModules;    // +0x10..0x30 (load_factor 1.0f)
};

// ============================================================================
// 4. AmazingEngine::TimerModule & TimerTask (0x022bb4..0x023f28)
// ============================================================================
// [EN] Implements JS `setTimeout`, `clearTimeout`, `setInterval`, `clearInterval`
//      scheduled onto the runtime's `BEFBaseRunner`.
//      Memory layout verified from `TimerModule::TimerModule` @ 0x022bb4:
//      `+0x00`: vtable pointer (`0x03aef0`)
//      `+0x08`: `Context* m_context`
//      `+0x10..0x30`: `std::unordered_map<int64_t, std::shared_ptr<TimerTask>>`
//                     (`max_load_factor = 1.0f` / `0x3f800000` at `+0x28`)
//      `+0x38`: `int64_t m_nextTimerId` (initialized to 0, incremented in
//               `setTimeout` @ `0x022f64..0x022f6c`: `ldr x8, [x19, #0x38];
//               add x8, x8, #1; str x8, [x19, #0x38]`).
// [VN] Cài đặt các hàm hẹn giờ JS `setTimeout`, `clearTimeout`, `setInterval`,
//      `clearInterval` lập lịch trên `BEFBaseRunner` của runtime.
class TimerModule {
public:
    // ------------------------------------------------------------------------
    // TimerModule::TimerTask (0x023a80..0x023f28, vtable @ 0x03af30)
    // ------------------------------------------------------------------------
    class TimerTask : public BEFTask {
    public:
        TimerTask(TimerModule* owner,
                  int64_t timerId,
                  Value callback,
                  double intervalMs,
                  bool repeat);
        ~TimerTask() override;

        void Run() override;

        int64_t GetTimerId() const noexcept { return m_timerId; }
        bool IsRepeat() const noexcept { return m_repeat; }
        double GetIntervalMs() const noexcept { return m_intervalMs; }

    private:
        TimerModule* m_owner{nullptr};
        int64_t m_timerId{0};
        Value m_callback;
        double m_intervalMs{0.0};
        bool m_repeat{false};
    };

    TimerModule(Context* context, const std::shared_ptr<BEFBaseRunner>& runner);
    virtual ~TimerModule();

    // [EN] `TimerModule::setTimeout` @ 0x022e84 & `setInterval` @ 0x023250:
    //      Increments `m_nextTimerId` at `+0x38`, creates a `TimerTask`, stores
    //      it in `m_timers`, and posts it to `m_runner` with `delayMs / 1000.0`.
    // [VN] `TimerModule::setTimeout` @ 0x022e84 & `setInterval` @ 0x023250:
    //      Tăng `m_nextTimerId` tại `+0x38`, tạo `TimerTask`, lưu vào `m_timers`,
    //      và đẩy vào `m_runner` với độ trễ `delayMs / 1000.0`.
    int64_t setTimeout(Value callback, double delayMs);
    int64_t setInterval(Value callback, double intervalMs);

    // [EN] `TimerModule::clearTimeout` / `clearInterval` @ 0x02361c.
    // [VN] `TimerModule::clearTimeout` / `clearInterval` @ 0x02361c.
    void clearTimer(int64_t timerId);

    size_t GetActiveTimerCount() const noexcept { return m_timers.size(); }
    int64_t GetLastTimerId() const noexcept { return m_nextTimerId; }

private:
    friend class TimerTask;
    Context* m_context{nullptr};                                        // +0x08
    std::unordered_map<int64_t, std::shared_ptr<TimerTask>> m_timers;   // +0x10..0x30
    float m_maxLoadFactor{1.0f};                                        // +0x28 (0x3f800000)
    int64_t m_nextTimerId{0};                                           // +0x38
    std::shared_ptr<BEFBaseRunner> m_runner;                            // +0x40
};

} // namespace AmazingEngine

#endif // JAZZ_MODULES_H_
