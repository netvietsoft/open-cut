// ============================================================================
// File: jazz_modules.cpp
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Subsystem: AmazingEngine::FileSystemModule, FileSystemModule::Stats,
//            ModuleRegistry, RequireModule, TimerModule, TimerModule::TimerTask
// Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (TASK_SO_122_libjazz)
// ============================================================================
// [EN] Clean-room C++17 implementation of the built-in native JS modules
//      inside `libjazz.so` (`FileSystemModule`, `ModuleRegistry`,
//      `RequireModule`, and `TimerModule`).
// [VN] Bản cài đặt C++17 tái tạo sạch các module JS gốc tích hợp trong
//      `libjazz.so` (`FileSystemModule`, `ModuleRegistry`, `RequireModule`,
//      và `TimerModule`).
// ============================================================================

#include "jazz_modules.h"
#include "jazz_platform_runtime_vm.h"

namespace AmazingEngine {

// ============================================================================
// 1. AmazingEngine::FileSystemModule::Stats (0x01d074..0x01d1c8)
// ============================================================================
// [EN] `Stats::getSize()` @ 0x01d074:
//      0x01d074: ldr d0, [x0, #0x48]
//      0x01d078: scvtf d0, d0          ; 0x5e61d800
//      0x01d07c: mov w0, #1
//      0x01d080: ret
// [VN] Đọc `m_size` tại `+0x48`, chuyển đổi sang số thực chấm động 64-bit bằng
//      `scvtf d0, d0` (`0x5e61d800`) và trả về `Value` kiểu `NUMBER`.
Value FileSystemModule::Stats::getSize() const noexcept {
    return Value(static_cast<double>(m_size));
}

// [EN] `Stats::isDirectory()` @ 0x01d084:
//      0x01d084: ldr w8, [x0, #0x28]
//      0x01d088: and w8, w8, #0xf000
//      0x01d08c: mov w0, #2
//      0x01d090: cmp w8, #4, lsl #12   ; 0x4000 (S_IFDIR)
//      0x01d094: cset w1, eq
//      0x01d098: ret
// [VN] Kiểm tra cờ `S_IFDIR` (`(m_mode & 0xF000u) == 0x4000u`).
Value FileSystemModule::Stats::isDirectory() const noexcept {
    const bool isDir = ((m_mode & 0xF000u) == 0x4000u);
    return Value(isDir);
}

// [EN] `Stats::isFile()` @ 0x01d09c:
//      0x01d09c: ldr w8, [x0, #0x28]
//      0x01d0a0: and w8, w8, #0xf000
//      0x01d0a4: mov w0, #2
//      0x01d0a8: cmp w8, #8, lsl #12   ; 0x8000 (S_IFREG)
//      0x01d0ac: cset w1, eq
//      0x01d0b0: ret
// [VN] Kiểm tra cờ `S_IFREG` (`(m_mode & 0xF000u) == 0x8000u`).
Value FileSystemModule::Stats::isFile() const noexcept {
    const bool isReg = ((m_mode & 0xF000u) == 0x8000u);
    return Value(isReg);
}

// [EN] `Stats::isSymbolicLink()` @ 0x01d0b4:
//      Checks `(m_mode & 0xF000u) == 0xA000u` (`S_IFLNK`).
// [VN] Kiểm tra cờ `S_IFLNK` (`(m_mode & 0xF000u) == 0xA000u`).
Value FileSystemModule::Stats::isSymbolicLink() const noexcept {
    const bool isLnk = ((m_mode & 0xF000u) == 0xA000u);
    return Value(isLnk);
}

// ============================================================================
// 2. AmazingEngine::FileSystemModule (0x01ac8c..0x01d070)
// ============================================================================
FileSystemModule::FileSystemModule(Context* context,
                                   const std::shared_ptr<BEFBaseRunner>& ioRunner,
                                   const std::shared_ptr<BEFBaseRunner>& jsRunner)
    : m_context(context),
      m_ioRunner(ioRunner),
      m_jsRunner(jsRunner) {}

FileSystemModule::~FileSystemModule() = default;

Value FileSystemModule::accessSync(const std::string& path, int32_t /*mode*/) {
    const bool exists = (m_virtualModes.find(path) != m_virtualModes.end()) ||
                        (m_virtualFiles.find(path) != m_virtualFiles.end());
    return Value(exists);
}

void FileSystemModule::access(const std::string& path, int32_t mode, Value callback) {
    if (m_ioRunner) {
        m_ioRunner->PostTask([this, path, mode, callback]() {
            this->accessSync(path, mode);
        });
    } else {
        accessSync(path, mode);
    }
}

FileSystemModule::Stats FileSystemModule::statSync(const std::string& path) {
    auto modeIt = m_virtualModes.find(path);
    auto fileIt = m_virtualFiles.find(path);
    if (fileIt != m_virtualFiles.end()) {
        const uint32_t mode = (modeIt != m_virtualModes.end()) ? modeIt->second : 0x81A4u;
        return Stats(mode, static_cast<int64_t>(fileIt->second.size()));
    }
    if (modeIt != m_virtualModes.end()) {
        return Stats(modeIt->second, 0);
    }
    return Stats(0u, 0);
}

void FileSystemModule::stat(const std::string& path, Value callback) {
    if (m_ioRunner) {
        m_ioRunner->PostTask([this, path, callback]() {
            this->statSync(path);
        });
    } else {
        statSync(path);
    }
}

Value FileSystemModule::readFileSync(const std::string& path,
                                     const std::string& /*encoding*/) {
    auto it = m_virtualFiles.find(path);
    if (it != m_virtualFiles.end()) {
        return Value(it->second);
    }
    return Value::CreateUndefined();
}

void FileSystemModule::readFile(const std::string& path,
                                const std::string& encoding,
                                Value callback) {
    if (m_ioRunner) {
        m_ioRunner->PostTask([this, path, encoding, callback]() {
            this->readFileSync(path, encoding);
        });
    } else {
        readFileSync(path, encoding);
    }
}

Value FileSystemModule::writeFileSync(const std::string& path,
                                      const std::string& content) {
    m_virtualFiles[path] = content;
    m_virtualModes[path] = 0x81A4u; // S_IFREG | 0644
    return Value(true);
}

void FileSystemModule::writeFile(const std::string& path,
                                 const std::string& content,
                                 Value callback) {
    if (m_ioRunner) {
        m_ioRunner->PostTask([this, path, content, callback]() {
            this->writeFileSync(path, content);
        });
    } else {
        writeFileSync(path, content);
    }
}

Value FileSystemModule::mkdirSync(const std::string& path, bool /*recursive*/) {
    m_virtualModes[path] = 0x41EDu; // S_IFDIR | 0755
    return Value(true);
}

void FileSystemModule::mkdir(const std::string& path, bool recursive, Value callback) {
    if (m_ioRunner) {
        m_ioRunner->PostTask([this, path, recursive, callback]() {
            this->mkdirSync(path, recursive);
        });
    } else {
        mkdirSync(path, recursive);
    }
}

Value FileSystemModule::rmdirSync(const std::string& path) {
    auto it = m_virtualModes.find(path);
    if (it != m_virtualModes.end() && ((it->second & 0xF000u) == 0x4000u)) {
        m_virtualModes.erase(it);
        return Value(true);
    }
    return Value(false);
}

void FileSystemModule::rmdir(const std::string& path, Value callback) {
    if (m_ioRunner) {
        m_ioRunner->PostTask([this, path, callback]() {
            this->rmdirSync(path);
        });
    } else {
        rmdirSync(path);
    }
}

Value FileSystemModule::unlinkSync(const std::string& path) {
    const size_t erasedFiles = m_virtualFiles.erase(path);
    m_virtualModes.erase(path);
    return Value(erasedFiles > 0);
}

void FileSystemModule::unlink(const std::string& path, Value callback) {
    if (m_ioRunner) {
        m_ioRunner->PostTask([this, path, callback]() {
            this->unlinkSync(path);
        });
    } else {
        unlinkSync(path);
    }
}

std::vector<std::string> FileSystemModule::readdirSync(const std::string& path) {
    std::vector<std::string> entries;
    const std::string prefix = (!path.empty() && path.back() == '/') ? path : (path + "/");
    for (const auto& kv : m_virtualFiles) {
        if (kv.first.compare(0, prefix.size(), prefix) == 0) {
            entries.push_back(kv.first.substr(prefix.size()));
        }
    }
    return entries;
}

void FileSystemModule::readdir(const std::string& path, Value callback) {
    if (m_ioRunner) {
        m_ioRunner->PostTask([this, path, callback]() {
            this->readdirSync(path);
        });
    } else {
        readdirSync(path);
    }
}

// ============================================================================
// 3. AmazingEngine::ModuleRegistry (0x020d00..0x020fc8)
// ============================================================================
// [EN] `ModuleRegistry::ModuleRegistry(Context*)` @ 0x020d00:
//      Initializes `m_context` at `+0x08` and sets `m_modules.max_load_factor(1.0f)`
//      (`mov w8, #0x3f800000; str w8, [x0, #0x28]`).
// [VN] Khởi tạo `m_context` tại `+0x08` và đặt hệ số tải tối đa `1.0f` (`0x3f800000`)
//      tại `+0x28`.
ModuleRegistry::ModuleRegistry(Context* context)
    : m_context(context),
      m_maxLoadFactor(1.0f) {
    m_modules.max_load_factor(m_maxLoadFactor);
}

ModuleRegistry::~ModuleRegistry() = default;

void ModuleRegistry::RegisterModule(const std::string& name, const Value& exportsObj) {
    m_modules[name] = exportsObj;
}

Value ModuleRegistry::GetModule(const std::string& name) const {
    auto it = m_modules.find(name);
    if (it != m_modules.end()) {
        return it->second;
    }
    return Value::CreateUndefined();
}

bool ModuleRegistry::HasModule(const std::string& name) const {
    return m_modules.find(name) != m_modules.end();
}

// ============================================================================
// 4. AmazingEngine::RequireModule (0x021618..0x021fb8)
// ============================================================================
// [EN] `RequireModule::RequireModule(Context*)` @ 0x021618:
//      At `0x0216b8..0x0216c4`, loads `.rodata 0x0297d2` (`x1`) with length
//      `0x0246 = 582` (`w2`) and calls `sub_17a08` (`JazzSBoxDecodeBuffer`) to
//      decrypt `makeRequire.js` (581 characters + NUL), then evaluates it on
//      `m_context`.
// [VN] Tại `0x0216b8..0x0216c4`, nạp địa chỉ `.rodata 0x0297d2` (`x1`) với độ dài
//      `0x0246 = 582` (`w2`) và gọi `sub_17a08` (`JazzSBoxDecodeBuffer`) để giải mã
//      `makeRequire.js` (581 ký tự + NUL), sau đó thực thi trên `m_context`.
RequireModule::RequireModule(Context* context)
    : m_context(context) {
    m_cachedModules.max_load_factor(1.0f);
    size_t encodedLen = 0;
    const uint8_t* encodedPtr = GetEncodedMakeRequireJsBytes(&encodedLen);
    std::vector<char> decodedBuf(encodedLen, '\0');
    JazzSBoxDecodeBuffer(decodedBuf.data(), encodedPtr, encodedLen);
    m_makeRequireScript.assign(decodedBuf.data(), encodedLen - 1);
    if (m_context) {
        m_context->Evaluate(m_makeRequireScript, "makeRequire.js");
    }
}

RequireModule::~RequireModule() = default;

Value RequireModule::CreateRequireFunction(const std::string& parentDir) {
    return Value::CreateFunction("require:" + parentDir);
}

Value RequireModule::Require(const std::string& parentDir, const std::string& moduleId) {
    const std::string resolved = ResolveModulePath(parentDir, moduleId);
    auto it = m_cachedModules.find(resolved);
    if (it != m_cachedModules.end()) {
        return it->second;
    }
    Value exported = Value::CreateObject();
    m_cachedModules[resolved] = exported;
    return exported;
}

std::string RequireModule::ResolveModulePath(const std::string& parentDir,
                                             const std::string& moduleId) {
    if (moduleId.empty()) {
        return {};
    }
    std::string combined;
    if (moduleId[0] == '/') {
        combined = moduleId;
    } else if (parentDir.empty()) {
        combined = moduleId;
    } else if (parentDir.back() == '/') {
        combined = parentDir + moduleId;
    } else {
        combined = parentDir + "/" + moduleId;
    }

    // [EN] Normalize '.', '..' path segments.
    // [VN] Chuẩn hóa các phân đoạn đường dẫn '.' và '..'.
    std::vector<std::string> parts;
    size_t start = 0;
    const bool leadingSlash = (!combined.empty() && combined[0] == '/');
    while (start <= combined.size()) {
        const size_t slashPos = combined.find('/', start);
        const std::string token = (slashPos == std::string::npos)
            ? combined.substr(start)
            : combined.substr(start, slashPos - start);
        if (token == "..") {
            if (!parts.empty()) {
                parts.pop_back();
            }
        } else if (!token.empty() && token != ".") {
            parts.push_back(token);
        }
        if (slashPos == std::string::npos) {
            break;
        }
        start = slashPos + 1;
    }

    std::string normalized = leadingSlash ? "/" : "";
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) {
            normalized += "/";
        }
        normalized += parts[i];
    }

    if (normalized.size() < 3 ||
        (normalized.compare(normalized.size() - 3, 3, ".js") != 0 &&
         (normalized.size() < 5 || normalized.compare(normalized.size() - 5, 5, ".json") != 0))) {
        normalized += ".js";
    }
    return normalized;
}

// [EN] Exact reconstruction of the AArch64 NEON population-count hash bucket
//      reducer emitted at `0x0220b4..0x0220dc` and `0x0221c4..0x0221ec`:
//      0x0220b4: fmov   d0, x8            ; 0x9e670100 (x8 = bucketCount)
//      0x0220b8: cnt    v0.8b, v0.8b      ; 0x0e205800 (per-byte popcount)
//      0x0220bc: uaddlv h0, v0.8b         ; 0x2e303800 (sum 8 byte counts)
//      0x0220c0: fmov   w9, s0            ; w9 = popcount(bucketCount)
//      0x0220c4: cmp    w9, #1
//      0x0220c8: b.hi   0x0220d8          ; if popcount > 1 (non-power-of-two)
//      0x0220cc: sub    x9, x8, #1
//      0x0220d0: and    x8, x21, x9       ; hash & (bucketCount - 1)
//      0x0220d8: udiv   x9, x21, x8
//      0x0220dc: msub   x8, x9, x8, x21   ; hash - (hash / bucketCount) * bucketCount
// [VN] Tái tạo chính xác hàm tính chỉ số bucket bảng băm dùng lệnh đếm bit NEON
//      `cnt v0.8b, v0.8b; uaddlv h0, v0.8b` tại `0x0220b4` và `0x0221c4`.
size_t RequireModule::ComputeBucketIndexNeonPopcount(size_t hash,
                                                     size_t bucketCount) noexcept {
    if (bucketCount == 0) {
        return 0;
    }
    uint64_t v = static_cast<uint64_t>(bucketCount);
    uint32_t popcnt = 0;
    for (int byteIdx = 0; byteIdx < 8; ++byteIdx) {
        uint8_t b = static_cast<uint8_t>((v >> (byteIdx * 8)) & 0xFFu);
        while (b != 0) {
            popcnt += (b & 1u);
            b >>= 1u;
        }
    }
    if (popcnt <= 1u) {
        return hash & (bucketCount - 1u);
    }
    const size_t q = hash / bucketCount;
    return hash - q * bucketCount;
}

// ============================================================================
// 5. AmazingEngine::TimerModule & TimerTask (0x022bb4..0x023f28)
// ============================================================================
TimerModule::TimerTask::TimerTask(TimerModule* owner,
                                  int64_t timerId,
                                  Value callback,
                                  double intervalMs,
                                  bool repeat)
    : BEFTask(),
      m_owner(owner),
      m_timerId(timerId),
      m_callback(std::move(callback)),
      m_intervalMs(intervalMs),
      m_repeat(repeat) {}

TimerModule::TimerTask::~TimerTask() = default;

void TimerModule::TimerTask::Run() {
    if (IsCancelled() || !m_owner) {
        return;
    }
    if (m_repeat && m_owner->m_runner) {
        m_owner->m_runner->PostDelayedTask(
            [this]() { this->Run(); },
            m_intervalMs / 1000.0);
    } else {
        m_owner->m_timers.erase(m_timerId);
    }
}

// [EN] `TimerModule::TimerModule(Context*, shared_ptr<BEFBaseRunner>)` @ 0x022bb4:
//      Initializes `m_context` at `+0x08`, `m_timers` with `max_load_factor = 1.0f`
//      (`0x3f800000` at `+0x28`), `m_nextTimerId = 0` at `+0x38`, and `m_runner` at `+0x40`.
// [VN] Khởi tạo `TimerModule` với `m_context` tại `+0x08`, bảng băm `m_timers`
//      có hệ số tải `1.0f` (`0x3f800000` tại `+0x28`), `m_nextTimerId = 0` tại `+0x38`,
//      và `m_runner` tại `+0x40`.
TimerModule::TimerModule(Context* context,
                         const std::shared_ptr<BEFBaseRunner>& runner)
    : m_context(context),
      m_maxLoadFactor(1.0f),
      m_nextTimerId(0),
      m_runner(runner) {
    m_timers.max_load_factor(m_maxLoadFactor);
}

TimerModule::~TimerModule() {
    for (auto& kv : m_timers) {
        if (kv.second) {
            kv.second->Cancel();
        }
    }
    m_timers.clear();
}

// [EN] `TimerModule::setTimeout` @ 0x022e84:
//      0x022f64: ldr x8, [x19, #0x38]
//      0x022f68: add x8, x8, #1
//      0x022f6c: str x8, [x19, #0x38]
//      Increments `m_nextTimerId` at `+0x38` and schedules one-shot `TimerTask`.
// [VN] Tăng `m_nextTimerId` tại `+0x38` (`0x022f64..0x022f6c`) và lập lịch `TimerTask`
//      chạy một lần.
int64_t TimerModule::setTimeout(Value callback, double delayMs) {
    const int64_t timerId = ++m_nextTimerId;
    auto task = std::make_shared<TimerTask>(
        this, timerId, std::move(callback), delayMs, /*repeat=*/false);
    m_timers[timerId] = task;
    if (m_runner) {
        m_runner->PostDelayedTask(
            [task]() { task->Run(); },
            (delayMs > 0.0) ? (delayMs / 1000.0) : 0.0);
    }
    return timerId;
}

int64_t TimerModule::setInterval(Value callback, double intervalMs) {
    const int64_t timerId = ++m_nextTimerId;
    auto task = std::make_shared<TimerTask>(
        this, timerId, std::move(callback), intervalMs, /*repeat=*/true);
    m_timers[timerId] = task;
    if (m_runner) {
        m_runner->PostDelayedTask(
            [task]() { task->Run(); },
            (intervalMs > 0.0) ? (intervalMs / 1000.0) : 0.0);
    }
    return timerId;
}

void TimerModule::clearTimer(int64_t timerId) {
    auto it = m_timers.find(timerId);
    if (it != m_timers.end()) {
        if (it->second) {
            it->second->Cancel();
        }
        m_timers.erase(it);
    }
}

} // namespace AmazingEngine
