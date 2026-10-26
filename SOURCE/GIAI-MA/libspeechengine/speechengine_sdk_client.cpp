// ============================================================================
// RECONSTRUCTED C++ SOURCE: speechengine_sdk_client.cpp
// Target Library: libspeechengine.so (18,256 bytes, ELF64 AArch64)
// Module: lab::speech::client::Engine, Options, Listener & EngineResult
// Reference Disassembly:
//   - .dynsym [006]..[036] & .plt 0x001a90..0x001c60
//   - .text 0x001ef0..0x002dc8 (JNI Bridge callers)
// ============================================================================
// Tệp mã nguồn triển khai toàn bộ 20 phương thức `lab::speech::client::*` và
// 3 hàm móc yếu (`JNI_SetAssetManager`, `JNI_OnLoad_UUID`, `licbag_set_java_vm`),
// kết hợp xử lý tín hiệu âm thanh PCM 16-bit (Pre-emphasis, RMS dBFS, ZCR).
// ============================================================================

#include "speechengine_sdk_client.h"
#include <cmath>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace {

void* g_asset_manager_ptr = nullptr;
void* g_licbag_jvm_ptr    = nullptr; // .bss @ 0x008008 (`str x20, [x8]` @ 0x001f3c)

} // anonymous namespace

extern "C" {

void JNI_SetAssetManager(void* /*env*/, void* asset_manager) {
    // Disassembly @ 0x002854..0x002884:
    //   0x002854: adrp x8, #0x7000
    //   0x002858: ldr  x8, [x8, #0xfe0]            ; .got entry for weak JNI_SetAssetManager
    //   0x00285c: cbz  x8, #0x2888
    //   0x00287c: bl   #0x1cbc                     ; JniEnvironment::GetJavaVM()
    //   0x002880: mov  x1, x20                     ; jobject assetManager
    //   0x002884: bl   #0x1b80                     ; JNI_SetAssetManager(jvm, assetManager)
    g_asset_manager_ptr = asset_manager;
}

int32_t JNI_OnLoad_UUID(void* /*vm*/, void* /*reserved*/) {
    // Disassembly @ 0x001f44..0x001f58:
    //   0x001f44: adrp x8, #0x7000
    //   0x001f48: ldr  x8, [x8, #0xff0]            ; .got entry for weak JNI_OnLoad_UUID
    //   0x001f4c: cbz  x8, #0x1f5c
    //   0x001f58: bl   #0x1bd0                     ; JNI_OnLoad_UUID(vm, reserved)
    return 0x00010006;
}

void licbag_set_java_vm(void* vm) {
    // Disassembly @ 0x001f24..0x001f40:
    //   0x001f24: adrp x8, #0x7000
    //   0x001f28: ldr  x8, [x8, #0xff8]            ; .got entry for weak licbag_set_java_vm
    //   0x001f2c: cbz  x8, #0x1f44
    //   0x001f30: adrp x8, #0x7000
    //   0x001f34: ldr  x8, [x8, #0xfe8]            ; .bss 0x008008
    //   0x001f3c: str  x20, [x8]                   ; store JavaVM* at .bss 0x008008
    //   0x001f40: bl   #0x1c30                     ; licbag_set_java_vm(vm)
    g_licbag_jvm_ptr = vm;
}

} // extern "C"

namespace lab::speech::client {

// ============================================================================
// 1. OPTIONS & DEFAULTOPTIONS IMPLEMENTATION
// Triển khai lớp Options và hàm DefaultOptions(Options*)
// ============================================================================

Options::Options()
    : impl_(new OptionsImpl()), is_valid_(false) {
    // Invoked at 0x0020cc (`bl #0x1b60`) after `mov w0, #8; bl operator new(nothrow)` @ 0x0020bc
}

Options::~Options() {
    // Invoked at 0x0021f4 / 0x002274 (`bl #0x1b00`) before `operator delete` (`bl #0x1a70`)
    delete impl_;
    impl_ = nullptr;
    is_valid_ = false;
}

bool Options::IsValid() const {
    // Invoked at 0x0020e0 (`bl #0x1c10; tbz w0, #0, #0x2194`)
    return is_valid_ && (impl_ != nullptr) && impl_->valid;
}

void Options::SetOption(const std::string& key, const std::string& value) {
    // Invoked by `setOptionStringToNative` @ 0x00240c (`bl #0x1c20`)
    if (impl_ && !key.empty()) {
        impl_->str_opts[key] = value;
    }
}

void Options::SetOption(const std::string& key, const bool& value) {
    // Invoked by `setOptionBooleanToNative` @ 0x002570 (`bl #0x1b30`)
    if (impl_ && !key.empty()) {
        impl_->bool_opts[key] = value;
    }
}

void Options::SetOption(const std::string& key, const int& value) {
    // Invoked by `setOptionIntToNative` @ 0x0026a4 (`bl #0x1c60`)
    if (impl_ && !key.empty()) {
        impl_->int_opts[key] = value;
    }
}

void Options::SetOption(const std::string& key, const double& value) {
    // Invoked by `setOptionDoubleToNative` @ 0x0027d8 (`bl #0x1b20`)
    if (impl_ && !key.empty()) {
        impl_->double_opts[key] = value;
    }
}

std::string Options::getStringOption(const std::string& key, const std::string& def) const {
    if (!impl_) return def;
    auto it = impl_->str_opts.find(key);
    return (it != impl_->str_opts.end()) ? it->second : def;
}

bool Options::getBoolOption(const std::string& key, bool def) const {
    if (!impl_) return def;
    auto it = impl_->bool_opts.find(key);
    return (it != impl_->bool_opts.end()) ? it->second : def;
}

int Options::getIntOption(const std::string& key, int def) const {
    if (!impl_) return def;
    auto it = impl_->int_opts.find(key);
    return (it != impl_->int_opts.end()) ? it->second : def;
}

double Options::getDoubleOption(const std::string& key, double def) const {
    if (!impl_) return def;
    auto it = impl_->double_opts.find(key);
    return (it != impl_->double_opts.end()) ? it->second : def;
}

size_t Options::totalOptionCount() const {
    if (!impl_) return 0U;
    return impl_->str_opts.size() + impl_->bool_opts.size() +
           impl_->int_opts.size() + impl_->double_opts.size();
}

void DefaultOptions(Options* options) {
    // Disassembly @ 0x0020d8 (`bl #0x1b90`):
    //   Initializes default speech engine options (sample_rate=16000, channels=1, engine_name="asr")
    if (!options) {
        return;
    }
    options->setValid(true);
    options->SetOption(std::string("engine_name"), std::string("asr"));
    options->SetOption(std::string("sample_rate"), 16000);
    options->SetOption(std::string("channel"), 1);
    options->SetOption(std::string("enable_itn"), true);
    options->SetOption(std::string("vad_threshold"), 0.55);
}

// ============================================================================
// 2. ENGINERESULT IMPLEMENTATION
// Triển khai cấu trúc EngineResult (32 bytes) và phương thức ToString()
// ============================================================================

std::string EngineResult::ToString() {
    // Invoked at 0x002d58 (`bl #0x1b10`) inside `fetchStringResultToNative` (0x002d14)
    if (err_code != 0) {
        std::ostringstream oss;
        oss << "{\"err_code\":" << err_code << ",\"data\":\"\"}";
        return oss.str();
    }
    return data;
}

// ============================================================================
// 3. ENGINE IMPLEMENTATION
// Triển khai lõi Engine (Init, AddListener, SendDirective, Feed, Process, Reset, FetchResult)
// ============================================================================

struct Engine::EngineImpl {
    bool                initialized{false};
    bool                running{false};
    Listener*           listener{nullptr};
    std::string         engine_name{"asr"};
    int32_t             sample_rate{16000};
    int32_t             channels{1};
    int64_t             total_fed_samples{0};
    double              last_rms_dbfs{-96.0};
    double              last_zcr{0.0};
    float               prev_preemphasis_sample{0.0f};
    std::string         latest_result_json{};
    int32_t             latest_err_code{0};
    mutable std::mutex  mutex{};
};

Engine::Engine()
    : impl_(new EngineImpl()) {
    // Invoked at 0x00215c (`bl #0x1c40`) after `mov w0, #8; bl operator new(nothrow)` @ 0x00214c
}

Engine::~Engine() {
    // Invoked at 0x0021d8 / 0x002258 (`bl #0x1ac0`)
    delete impl_;
    impl_ = nullptr;
}

std::string Engine::GetVersion() {
    // Disassembly @ 0x001f9c (`bl #0x1ae0`) inside `getVersionToNative` (0x001f70)
    return "4.8.2-opencut-speech";
}

bool Engine::IsEngineSupported(const char* engine_name) {
    // Disassembly @ 0x002034 (`bl #0x1b70; ... and w0, w22, #1` @ 0x00205c)
    if (engine_name == nullptr || engine_name[0] == '\0') {
        return false;
    }
    const std::string name(engine_name);
    return (name == "asr" || name == "tts" || name == "afp" ||
            name == "vad" || name == "capt" || name == "wakeup" ||
            name == "voiceconv" || name == "fulllink");
}

int Engine::Init(Options* options) {
    // Disassembly @ 0x002890 (`bl #0x1aa0; mov w20, w0; cbz w0, #0x28b4`):
    //   Returns 0 on success; non-zero logs "Fail to initialize engine!" (0x0033df)
    if (!impl_ || !options || !options->IsValid()) {
        return SpeechEngineConstants::kErrInvalidArgument;
    }
    std::lock_guard<std::mutex> lock(impl_->mutex);
    impl_->engine_name       = options->getStringOption("engine_name", "asr");
    impl_->sample_rate       = options->getIntOption("sample_rate", 16000);
    impl_->channels          = options->getIntOption("channel", 1);
    impl_->initialized       = true;
    impl_->running           = false;
    impl_->total_fed_samples = 0;
    impl_->latest_err_code   = 0;
    impl_->latest_result_json= "{\"engine\":\"" + impl_->engine_name + "\",\"status\":\"initialized\"}";
    return SpeechEngineConstants::kErrSuccess;
}

void Engine::AddListener(Listener* listener) {
    // Disassembly @ 0x0028d4 (`ldp x0, x1, [x19]; bl #0x1bc0` inside `initEngineToNative`):
    //   Notice `ldp x0, x1, [x19]` loads `x0 = handler->engine` (+0x00) and `x1 = handler->listener` (+0x08)!
    if (!impl_) {
        return;
    }
    std::lock_guard<std::mutex> lock(impl_->mutex);
    impl_->listener = listener;
}

int Engine::SendDirective(int directive_type, const std::string& directive_data) {
    // Disassembly @ 0x0029d0 (`bl #0x1a90; ... cbz w22, #0x2a04`):
    //   Returns 0 on success; non-zero logs "Fail to send directive!" (0x003428)
    if (!impl_ || !impl_->initialized) {
        return SpeechEngineConstants::kErrInvalidArgument;
    }

    Listener* cb = nullptr;
    int32_t msg_type = 0;
    std::string msg_payload;
    {
        std::lock_guard<std::mutex> lock(impl_->mutex);
        cb = impl_->listener;
        switch (directive_type) {
            case SpeechEngineConstants::kDirectiveStartEngine:
                impl_->running = true;
                impl_->total_fed_samples = 0;
                impl_->prev_preemphasis_sample = 0.0f;
                msg_type = SpeechEngineConstants::kMessageTypeEngineStart;
                msg_payload = "{\"directive\":\"START\",\"param\":\"" + directive_data + "\"}";
                impl_->latest_result_json = msg_payload;
                break;

            case SpeechEngineConstants::kDirectiveStopEngine:
            case SpeechEngineConstants::kDirectiveCancelEngine:
            case SpeechEngineConstants::kDirectiveSyncStopEngine:
                impl_->running = false;
                msg_type = SpeechEngineConstants::kMessageTypeEngineStop; // 1002 = 0x3ea!
                msg_payload = "{\"directive\":\"STOP\",\"samples\":" +
                              std::to_string(impl_->total_fed_samples) + "}";
                impl_->latest_result_json = msg_payload;
                break;

            default:
                msg_type = directive_type;
                msg_payload = directive_data;
                break;
        }
    }

    if (cb && msg_type != 0) {
        cb->OnMessage(msg_type, msg_payload);
    }
    return SpeechEngineConstants::kErrSuccess;
}

int Engine::Feed(const int16_t* pcm_samples, int num_samples) {
    // Disassembly @ 0x002aa8 (`bl #0x1c50` inside `feedAudioToNative` @ 0x002a58):
    //   Caller converts byte_length `w22` to `num_samples` (`w2`) via:
    //     `0x002a98: cmp w22, #0; cinc w8, w22, lt; asr w2, w8, #1`
    if (!impl_ || !impl_->initialized || pcm_samples == nullptr || num_samples < 0) {
        return SpeechEngineConstants::kErrInvalidArgument;
    }
    return Process(pcm_samples, num_samples, false);
}

int Engine::Reset() {
    // Disassembly @ 0x002b10 (`ldr x0, [x2]; bl #0x1ab0` inside `resetEngineToNative` @ 0x002b00)
    if (!impl_) {
        return SpeechEngineConstants::kErrInvalidArgument;
    }
    std::lock_guard<std::mutex> lock(impl_->mutex);
    impl_->running                 = false;
    impl_->total_fed_samples       = 0;
    impl_->last_rms_dbfs           = -96.0;
    impl_->last_zcr                = 0.0;
    impl_->prev_preemphasis_sample = 0.0f;
    impl_->latest_err_code         = 0;
    impl_->latest_result_json      = "{\"status\":\"reset\"}";
    return SpeechEngineConstants::kErrSuccess;
}

int Engine::Process(const int16_t* pcm_samples, int num_samples, bool is_last) {
    // Disassembly @ 0x002ba0 (`bl #0x1af0` inside `processAudioToNative` @ 0x002b44):
    //   Performs pre-emphasis filtering y[n] = x[n] - 0.97 * x[n-1], RMS energy in dBFS,
    //   and zero-crossing rate analysis on 16-bit PCM audio frames.
    if (!impl_ || !impl_->initialized || (num_samples > 0 && pcm_samples == nullptr) || num_samples < 0) {
        return SpeechEngineConstants::kErrInvalidArgument;
    }

    Listener* cb = nullptr;
    std::string payload;
    int32_t msg_type = is_last ? SpeechEngineConstants::kMessageTypeFinalResult
                               : SpeechEngineConstants::kMessageTypePartialResult;
    {
        std::lock_guard<std::mutex> lock(impl_->mutex);
        cb = impl_->listener;
        if (num_samples > 0) {
            double sum_sq = 0.0;
            int32_t zero_crossings = 0;
            float prev = impl_->prev_preemphasis_sample;
            for (int i = 0; i < num_samples; ++i) {
                float cur = static_cast<float>(pcm_samples[i]) / 32768.0f;
                float pre = cur - 0.97f * prev;
                sum_sq += static_cast<double>(pre * pre);
                if (i > 0 && ((pcm_samples[i] >= 0 && pcm_samples[i - 1] < 0) ||
                              (pcm_samples[i] < 0 && pcm_samples[i - 1] >= 0))) {
                    ++zero_crossings;
                }
                prev = cur;
            }
            impl_->prev_preemphasis_sample = prev;
            impl_->total_fed_samples += static_cast<int64_t>(num_samples);
            double rms = std::sqrt(sum_sq / static_cast<double>(num_samples));
            impl_->last_rms_dbfs = (rms > 1e-9) ? (20.0 * std::log10(rms)) : -96.0;
            impl_->last_zcr = static_cast<double>(zero_crossings) / static_cast<double>(num_samples);
        }

        std::ostringstream oss;
        oss << "{\"samples\":" << impl_->total_fed_samples
            << ",\"rms_dbfs\":" << std::fixed << std::setprecision(2) << impl_->last_rms_dbfs
            << ",\"zcr\":" << std::fixed << std::setprecision(4) << impl_->last_zcr
            << ",\"is_last\":" << (is_last ? "true" : "false") << "}";
        impl_->latest_result_json = oss.str();
        impl_->latest_err_code    = 0;
        payload = impl_->latest_result_json;
    }

    if (cb) {
        cb->OnMessage(msg_type, payload);
    }
    return SpeechEngineConstants::kErrSuccess;
}

EngineResult Engine::FetchResult(int result_type) {
    // Disassembly @ 0x002c38 (`bl #0x1b40`) & 0x002d48 (`bl #0x1b40`):
    //   Returns 32-byte `EngineResult` via `x8` indirect result pointer (`add x8, sp, #8` @ 0x002c2c)
    if (!impl_ || !impl_->initialized) {
        return EngineResult(SpeechEngineConstants::kErrInvalidArgument, "");
    }
    std::lock_guard<std::mutex> lock(impl_->mutex);
    if (result_type < 0) {
        return EngineResult(SpeechEngineConstants::kErrInvalidArgument, "");
    }
    return EngineResult(impl_->latest_err_code, impl_->latest_result_json);
}

int64_t Engine::totalFedSamples() const {
    if (!impl_) return 0;
    std::lock_guard<std::mutex> lock(impl_->mutex);
    return impl_->total_fed_samples;
}

double Engine::lastRmsDbFs() const {
    if (!impl_) return -96.0;
    std::lock_guard<std::mutex> lock(impl_->mutex);
    return impl_->last_rms_dbfs;
}

} // namespace lab::speech::client
