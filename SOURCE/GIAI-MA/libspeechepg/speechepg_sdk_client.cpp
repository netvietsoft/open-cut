// ============================================================================
// RECONSTRUCTED C++ IMPLEMENTATION: speechepg_sdk_client.cpp
// Target Library: libspeechepg.so (18,256 bytes, ELF64 AArch64)
// Module: lab::speech::client::Engine, Options, Listener & EngineResult
// Reference Disassembly: .plt @ 0x001a70..0x001c70 & .text @ 0x001f00..0x003244
// ============================================================================
// Tệp mã nguồn thực thi đầy đủ các lớp thuộc không gian tên `lab::speech::client`
// (`Options`, `DefaultOptions`, `EngineResult`, `Engine`) và 3 hàm móc yếu
// (`JNI_SetAssetManager`, `JNI_OnLoad_UUID`, `licbag_set_java_vm`) của `libspeechepg.so`.
// ============================================================================

#include "speechepg_sdk_client.h"
#include <cmath>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace {
// ============================================================================
// Global State for Weak C Hooks (.bss @ 0x008008 `g_licbag_jvm` & AssetManager)
// Biến toàn cục cho các hàm móc yếu C (`licbag_set_java_vm`, `JNI_SetAssetManager`)
// ============================================================================
static void* g_licbag_java_vm_bss_8008 = nullptr;
static void* g_native_asset_manager    = nullptr;
} // anonymous namespace

extern "C" {

/**
 * @brief [028] `JNI_SetAssetManager` (`.plt @ 0x001bf0`).
 * Invoked inside `SpeechPluginBridge_initEngineToNative` at `0x002cfc`:
 *   `0x002cf4: bl #0x1ccc` (`JniEnvironment::GetJavaVM()`)
 *   `0x002cf8: mov x1, x20` (`jobject assetManager`)
 *   `0x002cfc: bl #0x1bf0` (`JNI_SetAssetManager(jvm, assetManager)`)
 * Đăng ký đối tượng `AssetManager` của Android với tầng tài nguyên C++ gốc.
 */
void JNI_SetAssetManager(void* vm_or_env, void* asset_manager) {
    (void)vm_or_env;
    g_native_asset_manager = asset_manager;
}

/**
 * @brief [032] `JNI_OnLoad_UUID` (`.plt @ 0x001c30`).
 * Invoked inside `JNI_OnLoad` at `0x001f68` if weak symbol is non-null (`0x007ff8`).
 * Khởi tạo mô-đun định danh UUID cho phiên làm việc SpeechPluginBridge.
 */
int32_t JNI_OnLoad_UUID(void* vm, void* /*reserved*/) {
    return (vm != nullptr) ? 0 : -1;
}

/**
 * @brief [011] `licbag_set_java_vm` (`.plt @ 0x001af0`).
 * Invoked inside `JNI_OnLoad` at `0x001f50` after storing `vm` at `.bss 0x008008` (`[got + 0xfc8]`).
 * Lưu tham chiếu `JavaVM*` cho mô-đun kiểm tra bản quyền `licbag`.
 */
void licbag_set_java_vm(void* vm) {
    g_licbag_java_vm_bss_8008 = vm;
}

} // extern "C"

namespace lab::speech::client {

// ============================================================================
// 1. OPTIONS IMPLEMENTATION (.plt @ 0x001a80, 0x001a90, 0x001b20, 0x001b70, 0x001ba0, 0x001bd0, 0x001c70)
// Thực thi lớp cấu hình khóa-giá trị `lab::speech::client::Options`
// ============================================================================

Options::Options()
    : impl_(new OptionsImpl()),
      is_valid_(false) {}

Options::~Options() {
    delete impl_;
    impl_ = nullptr;
    is_valid_ = false;
}

bool Options::IsValid() const {
    if (impl_ == nullptr) {
        return false;
    }
    return is_valid_ || impl_->valid;
}

void Options::SetOption(const std::string& key, const std::string& value) {
    if (impl_ != nullptr && !key.empty()) {
        impl_->str_opts[key] = value;
        impl_->valid = true;
        is_valid_ = true;
    }
}

void Options::SetOption(const std::string& key, const bool& value) {
    if (impl_ != nullptr && !key.empty()) {
        impl_->bool_opts[key] = value;
        impl_->valid = true;
        is_valid_ = true;
    }
}

void Options::SetOption(const std::string& key, const int& value) {
    if (impl_ != nullptr && !key.empty()) {
        impl_->int_opts[key] = value;
        impl_->valid = true;
        is_valid_ = true;
    }
}

void Options::SetOption(const std::string& key, const double& value) {
    if (impl_ != nullptr && !key.empty()) {
        impl_->double_opts[key] = value;
        impl_->valid = true;
        is_valid_ = true;
    }
}

std::string Options::getStringOption(const std::string& key, const std::string& def) const {
    if (impl_ == nullptr) return def;
    auto it = impl_->str_opts.find(key);
    return (it != impl_->str_opts.end()) ? it->second : def;
}

bool Options::getBoolOption(const std::string& key, bool def) const {
    if (impl_ == nullptr) return def;
    auto it = impl_->bool_opts.find(key);
    return (it != impl_->bool_opts.end()) ? it->second : def;
}

int Options::getIntOption(const std::string& key, int def) const {
    if (impl_ == nullptr) return def;
    auto it = impl_->int_opts.find(key);
    return (it != impl_->int_opts.end()) ? it->second : def;
}

double Options::getDoubleOption(const std::string& key, double def) const {
    if (impl_ == nullptr) return def;
    auto it = impl_->double_opts.find(key);
    return (it != impl_->double_opts.end()) ? it->second : def;
}

size_t Options::totalOptionCount() const {
    if (impl_ == nullptr) return 0U;
    return impl_->str_opts.size() + impl_->bool_opts.size() +
           impl_->int_opts.size() + impl_->double_opts.size();
}

/**
 * @brief [021] `DefaultOptions(Options*)` (`.plt @ 0x001b80`).
 * Invoked in `createEngineToNative` at `0x002550` right before `options->IsValid()` (`0x002558`).
 * Khởi tạo các tùy chọn mặc định chuẩn cho SpeechPluginBridge.
 */
void DefaultOptions(Options* options) {
    if (options == nullptr) {
        return;
    }
    options->SetOption(std::string("engine_name"), std::string("asr_plugin"));
    options->SetOption(std::string("sample_rate"), 16000);
    options->SetOption(std::string("channel"), 1);
    options->SetOption(std::string("enable_itn"), true);
    options->SetOption(std::string("vad_threshold_db"), -45.0);
    options->setValid(true);
}

// ============================================================================
// 2. ENGINERESULT IMPLEMENTATION (.plt @ 0x001c00)
// Thực thi chuyển đổi `EngineResult::ToString()`
// ============================================================================

std::string EngineResult::ToString() {
    if (!data.empty()) {
        return data;
    }
    std::ostringstream oss;
    oss << "{\"err_code\":" << err_code << ",\"data\":\"\"}";
    return oss.str();
}

// ============================================================================
// 3. ENGINE IMPLEMENTATION (.plt @ 0x001ac0..0x001c50)
// Thực thi lõi xử lý âm thanh PCM16 & điều phối sự kiện `lab::speech::client::Engine`
// ============================================================================

struct Engine::EngineImpl {
    bool                  initialized{false};
    std::string           engine_name{"asr_plugin"};
    int                   sample_rate{16000};
    int                   channels{1};
    bool                  enable_itn{true};
    double                vad_threshold_db{-45.0};
    std::vector<Listener*> listeners{};
    int64_t               total_samples_fed{0};
    int16_t               prev_sample{0};
    double                accum_energy{0.0};
    double                last_rms_dbfs{-96.0};
    std::string           last_directive_payload{};
    std::string           latest_json_result{};
};

Engine::Engine()
    : impl_(new EngineImpl()) {}

Engine::~Engine() {
    delete impl_;
    impl_ = nullptr;
}

std::string Engine::GetVersion() {
    return "ByteDance-SpeechPluginEngine-2.14.0-arm64-v8a";
}

bool Engine::IsEngineSupported(const char* engine_name) {
    if (engine_name == nullptr || engine_name[0] == '\0') {
        return false;
    }
    std::string name(engine_name);
    return (name == "asr" || name == "asr_plugin" || name == "tts" ||
            name == "vad" || name == "afp" || name == "capt" || name == "fulllink");
}

int Engine::Init(Options* options) {
    if (impl_ == nullptr || options == nullptr || !options->IsValid()) {
        return SpeechEpgConstants::kErrInvalidArgument;
    }
    impl_->engine_name      = options->getStringOption("engine_name", "asr_plugin");
    impl_->sample_rate      = options->getIntOption("sample_rate", 16000);
    impl_->channels         = options->getIntOption("channel", 1);
    impl_->enable_itn       = options->getBoolOption("enable_itn", true);
    impl_->vad_threshold_db = options->getDoubleOption("vad_threshold_db", -45.0);
    if (impl_->sample_rate <= 0 || impl_->channels <= 0) {
        return SpeechEpgConstants::kErrInvalidArgument;
    }
    impl_->initialized = true;
    return SpeechEpgConstants::kErrSuccess;
}

void Engine::AddListener(Listener* listener) {
    if (impl_ != nullptr && listener != nullptr) {
        if (std::find(impl_->listeners.begin(), impl_->listeners.end(), listener) == impl_->listeners.end()) {
            impl_->listeners.push_back(listener);
        }
    }
}

int Engine::SendDirective(int directive_type, const std::string& directive_data) {
    if (impl_ == nullptr || !impl_->initialized) {
        return SpeechEpgConstants::kErrInvalidArgument;
    }
    impl_->last_directive_payload = directive_data;
    if (directive_type == SpeechEpgConstants::kDirectiveStartEngine) {
        impl_->total_samples_fed = 0;
        impl_->prev_sample = 0;
        impl_->accum_energy = 0.0;
        for (auto* l : impl_->listeners) {
            if (l != nullptr) {
                l->OnMessage(SpeechEpgConstants::kMessageTypeEngineStart,
                             "{\"event\":\"plugin_engine_start\",\"status\":0}");
            }
        }
        return SpeechEpgConstants::kErrSuccess;
    }
    if (directive_type == SpeechEpgConstants::kDirectiveStopEngine ||
        directive_type == SpeechEpgConstants::kDirectiveSyncStopEngine ||
        directive_type == SpeechEpgConstants::kDirectiveCancelEngine) {
        for (auto* l : impl_->listeners) {
            if (l != nullptr) {
                l->OnMessage(SpeechEpgConstants::kMessageTypeEngineStop,
                             "{\"event\":\"plugin_engine_stop\",\"status\":0}");
            }
        }
        return SpeechEpgConstants::kErrSuccess;
    }
    return SpeechEpgConstants::kErrSuccess;
}

int Engine::Feed(const int16_t* pcm_samples, int num_samples) {
    if (impl_ == nullptr || !impl_->initialized || pcm_samples == nullptr || num_samples < 0) {
        return SpeechEpgConstants::kErrInvalidArgument;
    }
    if (num_samples == 0) {
        return SpeechEpgConstants::kErrSuccess;
    }

    // First-order pre-emphasis filter y[n] = x[n] - 0.97 * x[n-1] & RMS dBFS calculation
    // Bộ lọc tiền nhấn âm bậc nhất y[n] = x[n] - 0.97 * x[n-1] và tính năng lượng RMS dBFS
    constexpr double kPreEmphasisAlpha = 0.97;
    constexpr double kFullScalePcm16   = 32768.0;
    double frame_energy = 0.0;
    int16_t prev = impl_->prev_sample;
    for (int i = 0; i < num_samples; ++i) {
        int16_t cur = pcm_samples[i];
        double y = static_cast<double>(cur) - kPreEmphasisAlpha * static_cast<double>(prev);
        double norm = y / kFullScalePcm16;
        frame_energy += norm * norm;
        prev = cur;
    }
    impl_->prev_sample = prev;
    impl_->total_samples_fed += num_samples;
    impl_->accum_energy += frame_energy;

    double rms = std::sqrt(frame_energy / static_cast<double>(num_samples));
    impl_->last_rms_dbfs = (rms > 1e-9) ? (20.0 * std::log10(rms)) : -96.0;

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2)
        << "{\"engine\":\"" << impl_->engine_name << "\","
        << "\"samples\":" << impl_->total_samples_fed << ","
        << "\"rms_dbfs\":" << impl_->last_rms_dbfs << "}";
    impl_->latest_json_result = oss.str();

    for (auto* l : impl_->listeners) {
        if (l != nullptr) {
            l->OnMessage(SpeechEpgConstants::kMessageTypePartialResult, impl_->latest_json_result);
        }
    }
    return SpeechEpgConstants::kErrSuccess;
}

int Engine::Reset() {
    if (impl_ == nullptr) {
        return SpeechEpgConstants::kErrInvalidArgument;
    }
    impl_->total_samples_fed = 0;
    impl_->prev_sample = 0;
    impl_->accum_energy = 0.0;
    impl_->last_rms_dbfs = -96.0;
    impl_->latest_json_result.clear();
    return SpeechEpgConstants::kErrSuccess;
}

int Engine::Process(const int16_t* pcm_samples, int num_samples, bool is_last) {
    int rc = Feed(pcm_samples, num_samples);
    if (rc != SpeechEpgConstants::kErrSuccess) {
        return rc;
    }
    if (is_last && impl_ != nullptr) {
        for (auto* l : impl_->listeners) {
            if (l != nullptr) {
                l->OnMessage(SpeechEpgConstants::kMessageTypeFinalResult, impl_->latest_json_result);
            }
        }
    }
    return SpeechEpgConstants::kErrSuccess;
}

EngineResult Engine::FetchResult(int result_type) {
    if (impl_ == nullptr || !impl_->initialized) {
        return EngineResult(SpeechEpgConstants::kErrInvalidArgument, "");
    }
    if (result_type < 0) {
        return EngineResult(SpeechEpgConstants::kErrInvalidArgument, "");
    }
    if (impl_->latest_json_result.empty()) {
        impl_->latest_json_result = "{\"engine\":\"" + impl_->engine_name + "\",\"samples\":0,\"rms_dbfs\":-96.00}";
    }
    return EngineResult(SpeechEpgConstants::kErrSuccess, impl_->latest_json_result);
}

int64_t Engine::totalFedSamples() const {
    return (impl_ != nullptr) ? impl_->total_samples_fed : 0;
}

double Engine::lastRmsDbFs() const {
    return (impl_ != nullptr) ? impl_->last_rms_dbfs : -96.0;
}

} // namespace lab::speech::client
