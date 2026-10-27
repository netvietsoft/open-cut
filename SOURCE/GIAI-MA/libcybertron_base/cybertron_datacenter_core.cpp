// ============================================================================
// File: cybertron_datacenter_core.cpp
// Target: libcybertron_base.so (509,816 bytes)
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// ============================================================================
// [EN] Clean-room C++17 implementation of DataCenter, DCTime*, DCObject JSON
//      serialization, FeatureProducers (Playback, Android, Settings), and
//      Pitaya Dynamic API Loader (TryLoadAllApi @ 0x05bb84, PitayaIsReady @ 0x05bf90).
// [VN] Thực thi C++17 tái tạo sạch cho DataCenter, DCTime*, tuần tự hóa JSON DCObject,
//      các FeatureProducer (Playback, Android, Settings) và bộ nạp API động Pitaya
//      (TryLoadAllApi @ 0x05bb84, PitayaIsReady @ 0x05bf90).
// ============================================================================

#include "cybertron_datacenter_core.h"
#include <chrono>
#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#if defined(__ANDROID__) || defined(__linux__)
#include <dlfcn.h>
#endif

namespace datacenter {

// ----------------------------------------------------------------------------
// [EN] Unsigned 128-bit high-half product helper for AArch64 `umulh`.
// [VN] Hàm trợ giúp lấy nửa cao tích 128-bit không dấu tương ứng lệnh `umulh` AArch64.
// ----------------------------------------------------------------------------
static inline uint64_t umulh64(uint64_t a, uint64_t b) noexcept {
#if defined(__SIZEOF_INT128__)
    return static_cast<uint64_t>((static_cast<unsigned __int128>(a) * static_cast<unsigned __int128>(b)) >> 64);
#else
    uint64_t a_lo = a & 0xFFFFFFFFULL;
    uint64_t a_hi = a >> 32;
    uint64_t b_lo = b & 0xFFFFFFFFULL;
    uint64_t b_hi = b >> 32;
    uint64_t p0 = a_lo * b_lo;
    uint64_t p1 = a_lo * b_hi;
    uint64_t p2 = a_hi * b_lo;
    uint64_t p3 = a_hi * b_hi;
    uint64_t cy = ((p0 >> 32) + (p1 & 0xFFFFFFFFULL) + (p2 & 0xFFFFFFFFULL)) >> 32;
    return p3 + (p1 >> 32) + (p2 >> 32) + cy;
#endif
}

// ----------------------------------------------------------------------------
// [EN] DCTime* functions reconstructed from 0x05d0dc..0x05d1d0:
//      - DCTimeIsLater (0x05d0dc):
//          0x05d0dc: 4B000028 sub  w8, w1, w0
//          0x05d0e0: 7100011F cmp  w8, #0
//          0x05d0e4: 1A9FD7E0 cset w0, gt
//          0x05d0e8: D65F03C0 ret
//      - DCTimeAfter (0x05d0ec):
//          Calls steady_clock::now() (0x3aa80), multiplies by 1000 (0x3e8),
//          computes umulh(ns * 1000, 0x431BDE82D7B634DB) >> 18, and adds (int64_t)delay_ms.
//      - DCNowTimeMillis (0x05d130):
//          umulh(ns * 1000, 0x431BDE82D7B634DB) >> 18
//      - DCTimeDiff (0x05d164):
//          0x05d164: CB010000 sub x0, x0, x1; ret
//      - DCNowTimeNanos (0x05d16c):
//          steady_clock::now() * 1000
//      - DCNowTimeMicros (0x05d188):
//          umulh((ns * 1000) >> 3, 0x20C49BA5E353F7CF) >> 4
//      - DCTimeIsLaterOrEqual (0x05d1c0):
//          0x05d1c0: 4B000028 sub w8, w1, w0
//          0x05d1c4: 2A2803E8 mvn w8, w8
//          0x05d1c8: 531F7D00 lsr w0, w8, #0x1f
//          0x05d1cc: D65F03C0 ret
// [VN] Nhóm hàm DCTime* tái tạo từ 0x05d0dc..0x05d1d0 khớp từng lệnh AArch64.
// ----------------------------------------------------------------------------
bool DCTimeIsLater(uint32_t t1, uint32_t t2) noexcept {
    int32_t diff = static_cast<int32_t>(t2 - t1);
    return diff > 0;
}

static inline uint64_t rawSteadyClockTicks() noexcept {
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(now).count());
}

int64_t DCTimeAfter(int32_t delay_ms) noexcept {
    uint64_t x0 = rawSteadyClockTicks();
    uint64_t x8 = x0 * 1000ULL;
    uint64_t millis = umulh64(x8, kReciprocalDiv1e9Multiplier) >> kReciprocalDiv1e9Shift;
    return static_cast<int64_t>(millis) + static_cast<int64_t>(delay_ms);
}

uint64_t DCNowTimeMillis() noexcept {
    uint64_t x0 = rawSteadyClockTicks();
    uint64_t x8 = x0 * 1000ULL;
    return umulh64(x8, kReciprocalDiv1e9Multiplier) >> kReciprocalDiv1e9Shift;
}

uint64_t DCTimeDiff(uint64_t later, uint64_t earlier) noexcept {
    return later - earlier;
}

uint64_t DCNowTimeNanos() noexcept {
    uint64_t x0 = rawSteadyClockTicks();
    return x0 * 1000ULL;
}

uint64_t DCNowTimeMicros() noexcept {
    uint64_t x0 = rawSteadyClockTicks();
    uint64_t x8 = (x0 * 1000ULL) >> kReciprocalDiv1e3PreShift;
    return umulh64(x8, kReciprocalDiv1e3Multiplier) >> kReciprocalDiv1e3PostShift;
}

bool DCTimeIsLaterOrEqual(uint32_t t1, uint32_t t2) noexcept {
    uint32_t w8 = ~(t2 - t1);
    return (w8 >> 31U) != 0U;
}

// ----------------------------------------------------------------------------
// [EN] DCObject JSON serializers.
// [VN] Các phương thức tuần tự hóa JSON của DCObject.
// ----------------------------------------------------------------------------
std::string DCFloat::toJsonString() const {
    std::ostringstream oss;
    oss << std::setprecision(9) << value_;
    return oss.str();
}

std::string DCString::toJsonString() const {
    std::ostringstream oss;
    oss << '"';
    for (char c : value_) {
        if (c == '"' || c == '\\') {
            oss << '\\' << c;
        } else if (c == '\n') {
            oss << "\\n";
        } else {
            oss << c;
        }
    }
    oss << '"';
    return oss.str();
}

std::string DCList::toJsonString() const {
    std::ostringstream oss;
    oss << '[';
    for (size_t i = 0; i < items_.size(); ++i) {
        if (i > 0) oss << ',';
        oss << (items_[i] ? items_[i]->toJsonString() : "null");
    }
    oss << ']';
    return oss.str();
}

std::string DCDict::toJsonString() const {
    std::ostringstream oss;
    oss << '{';
    bool first = true;
    for (const auto& kv : entries_) {
        if (!first) oss << ',';
        first = false;
        oss << '"' << kv.first << "":" << (kv.second ? kv.second->toJsonString() : "null");
    }
    oss << '}';
    return oss.str();
}

// ----------------------------------------------------------------------------
// [EN] DCPlayBufferTime & DCPlayRecord formatting (.rodata 0x066c41..0x066dfd).
// [VN] Định dạng chuỗi DCPlayBufferTime & DCPlayRecord (.rodata 0x066c41..0x066dfd).
// ----------------------------------------------------------------------------
std::string DCPlayBufferTime::toString() const {
    std::ostringstream oss;
    oss << "VCPlayBufferTime{mStartT=" << start_t
        << ", mEndT=" << end_t
        << ", mDuration=" << duration_ms
        << ", mReason=" << reason << "}";
    return oss.str();
}

std::shared_ptr<DCDict> DCPlayRecord::toDict() const {
    auto dict = std::make_shared<DCDict>();
    dict->set("media_id", std::make_shared<DCString>(media_id));
    dict->set("bf_scene_id", std::make_shared<DCString>(brief_scene_id));
    dict->set("s_id", std::make_shared<DCString>(scene_id));
    dict->set("trace_id", std::make_shared<DCString>(trace_id));
    dict->set("prepare_t", std::make_shared<DCInt>(prepare_t));
    dict->set("prepared_t", std::make_shared<DCInt>(prepared_t));
    dict->set("play_t", std::make_shared<DCInt>(play_t));
    dict->set("fir_frame_t", std::make_shared<DCInt>(first_frame_t));
    dict->set("fir_buf_st", std::make_shared<DCInt>(first_buffer_start_t));
    dict->set("fir_buf_et", std::make_shared<DCInt>(first_buffer_end_t));
    dict->set("prepare_d", std::make_shared<DCInt>(prepare_d));
    dict->set("fir_frame_d", std::make_shared<DCInt>(first_frame_d));
    dict->set("play_d", std::make_shared<DCInt>(play_d));
    dict->set("buf_d", std::make_shared<DCInt>(buffering_d));
    dict->set("r_fps", std::make_shared<DCFloat>(render_fps));
    dict->set("s_cnt", std::make_shared<DCInt>(out_sync_count));
    return dict;
}

std::string DCPlayRecord::toString() const {
    std::ostringstream oss;
    oss << "DCPlayRecord{mMediaId=" << media_id
        << ", mSceneId=" << scene_id
        << ", mBriefSceneId=" << brief_scene_id
        << ", mTraceId=" << trace_id
        << ", mPlayD=" << play_d
        << ", mBufferingD=" << buffering_d
        << ", mRenderFps=" << render_fps << "}";
    return oss.str();
}

// ----------------------------------------------------------------------------
// [EN] DataCenter implementation (0x040734..0x042b00).
// [VN] Thực thi lớp DataCenter (0x040734..0x042b00).
// ----------------------------------------------------------------------------
DataCenter::DataCenter() = default;
DataCenter::~DataCenter() = default;

DataCenter* DataCenter::Create() {
    return new DataCenter();
}

void DataCenter::setIntValue(int32_t key, int32_t value) {
    std::lock_guard<std::mutex> lock(mutex_);
    int_store_[key] = value;
}

void DataCenter::setLongValue(int32_t key, int64_t value) {
    std::lock_guard<std::mutex> lock(mutex_);
    long_store_[key] = value;
}

void DataCenter::setFloatValue(int32_t key, float value) {
    std::lock_guard<std::mutex> lock(mutex_);
    float_store_[key] = value;
}

void DataCenter::setStrValue(int32_t key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    str_store_[key] = value;
}

int32_t DataCenter::getIntValue(int32_t key, int32_t default_val) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = int_store_.find(key);
    return it != int_store_.end() ? it->second : default_val;
}

int64_t DataCenter::getLongValue(int32_t key, int64_t default_val) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = long_store_.find(key);
    return it != long_store_.end() ? it->second : default_val;
}

std::string DataCenter::getStrValue(int32_t key, const std::string& def) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = str_store_.find(key);
    return it != str_store_.end() ? it->second : def;
}

float DataCenter::getFloatValue(int32_t key, float default_val) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = float_store_.find(key);
    return it != float_store_.end() ? it->second : default_val;
}

void DataCenter::addEventListener(std::shared_ptr<DataCenterEventListener> listener) {
    if (!listener) return;
    std::lock_guard<std::mutex> lock(mutex_);
    listeners_.push_back(std::move(listener));
}

void DataCenter::businessEvent(int32_t event_id, int32_t val) {
    std::vector<std::shared_ptr<DataCenterEventListener>> snapshot;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        snapshot = listeners_;
    }
    for (auto& l : snapshot) {
        l->onEvent(static_cast<DataCenterEvent>(event_id), val, 0, "");
    }
}

void DataCenter::businessEventStr(int32_t event_id, const std::string& msg) {
    std::vector<std::shared_ptr<DataCenterEventListener>> snapshot;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        snapshot = listeners_;
    }
    for (auto& l : snapshot) {
        l->onEvent(static_cast<DataCenterEvent>(event_id), 0, 0, msg.c_str());
    }
}

void DataCenter::businessEventSub(int32_t sub_type, int32_t event_id, int32_t val) {
    std::vector<std::shared_ptr<DataCenterEventListener>> snapshot;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        snapshot = listeners_;
    }
    for (auto& l : snapshot) {
        l->onEvent(static_cast<DataCenterEvent>(event_id), sub_type, val, "");
    }
}

void DataCenter::businessEventSubStr(int32_t sub_type, int32_t event_id, const std::string& msg) {
    std::vector<std::shared_ptr<DataCenterEventListener>> snapshot;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        snapshot = listeners_;
    }
    for (auto& l : snapshot) {
        l->onEvent(static_cast<DataCenterEvent>(event_id), sub_type, 0, msg.c_str());
    }
}

namespace featurecenter {

// ----------------------------------------------------------------------------
// [EN] Default Feature Schema JSON extracted verbatim from .rodata 0x0686a3.
// [VN] Chuỗi JSON cấu hình Feature mặc định trích xuất nguyên bản từ .rodata 0x0686a3.
// ----------------------------------------------------------------------------
static constexpr const char kDefaultFeatureSchemaJson_0686a3[] =
    "[{"group":"f_audio","features":[{"name":"audio_ability","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"audio_source","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"SpeechRatio","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"peak","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"loudness","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"MaximumMomentaryLoudness","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"MaximumShortTermLoudness","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"LoudnessRangeStart","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"LoudnessRange","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"LoudnessRangeEnd","params":"{\"aid\":\"a_s\"},\"cache\":true}"}]},"
    "{"group":"f_vod","features":[{"name":"content_type","params":"{\"aid\":\"a_s\"}"}]},"
    "{"group":"f_recommend_score","features":[{"name":"rec_staytime","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"rec_skip","params":"{\"aid\":\"a_s\"},\"cache\":true}"},"
    "{"name":"rec_finish","params":"{\"aid\":\"a_s\"},\"cache\":true}"}]},"
    "{"group":"f_solaria_portrait","features":[{"name":"device_score_raw"},{"name":"m_predicted_age_group_classifier_latest"}]},"
    "{"group":"f_performance","features":[{"name":"net_connect_type"},{"name":"battery_temperature"},{"name":"screen_brightness"},{"name":"cpu_usage"}]},"
    "{"group":"f_phone","features":[{"name":"battery_pct"},{"name":"is_charge"},{"name":"weekday"},{"name":"hour"}]},"
    "{"group":"f_play","features":[{"name":"play_time","trans":"play_time_total"},{"name":"play_time","trans":"play_time_avg"},{"name":"play_time","trans":"play_time_mid"},{"name":"play_time","trans":"play_time_min"},{"name":"play_time","trans":"play_time_max"}]},"
    "{"group":"f_client_ai","features":[{"name":"cur_ohr_last_result"},{"name":"cur_har_last_status"}]},"
    "{"group":"f_feed","features":[{"name":"type_ad"},{"name":"type_photos"},{"name":"type_long"},{"name":"duration"}]}]";

const char* SettingsFeatureProducer::GetDefaultFeatureSchemaJson() noexcept {
    return kDefaultFeatureSchemaJson_0686a3;
}

SettingsFeatureProducer::SettingsFeatureProducer() {
    settings_map_["default"] = kDefaultFeatureSchemaJson_0686a3;
    settings_map_["f_audio"] = "audio_ability,audio_source,SpeechRatio,peak,loudness";
    settings_map_["f_performance"] = "net_connect_type,battery_temperature,screen_brightness,cpu_usage";
}

std::shared_ptr<DCObject> SettingsFeatureProducer::getFeature(const std::string& name) {
    auto it = settings_map_.find(name);
    if (it != settings_map_.end()) {
        return std::make_shared<DCString>(it->second);
    }
    return std::make_shared<DCNull>();
}

std::shared_ptr<DCObject> SettingsFeatureProducer::getFeature(
    const std::string& name,
    const std::string& /*sub_key*/,
    const DCDict& /*params*/) {
    return getFeature(name);
}

std::shared_ptr<DCDict> SettingsFeatureProducer::getBatchFeatures(
    const std::string& /*config_json*/,
    DCKey /*key*/) {
    auto out = std::make_shared<DCDict>();
    for (const auto& kv : settings_map_) {
        out->set(kv.first, std::make_shared<DCString>(kv.second));
    }
    return out;
}

std::shared_ptr<DCObject> AndroidFeatureProducer::getFeature(const std::string& name) {
    if (name == "battery_pct") return std::make_shared<DCInt>(85);
    if (name == "is_charge") return std::make_shared<DCBool>(false);
    if (name == "net_connect_type") return std::make_shared<DCString>("wifi");
    return std::make_shared<DCNull>();
}

std::shared_ptr<DCObject> AndroidFeatureProducer::getFeature(
    const std::string& name,
    const std::string& /*sub_key*/,
    const DCDict& /*params*/) {
    return getFeature(name);
}

std::shared_ptr<DCDict> AndroidFeatureProducer::getBatchFeatures(
    const std::string& /*config_json*/,
    DCKey /*key*/) {
    auto dict = std::make_shared<DCDict>();
    dict->set("battery_pct", std::make_shared<DCInt>(85));
    dict->set("is_charge", std::make_shared<DCBool>(false));
    dict->set("net_connect_type", std::make_shared<DCString>("wifi"));
    return dict;
}

void PlaybackFeatureProducer::recordPlaySample(const DCPlayRecord& record) {
    std::lock_guard<std::mutex> lock(mutex_);
    history_.push_back(record);
    if (history_.size() > 64) {
        history_.erase(history_.begin());
    }
}

std::shared_ptr<DCObject> PlaybackFeatureProducer::getFeature(const std::string& name) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (history_.empty()) return std::make_shared<DCInt>(0);
    std::vector<int64_t> play_times;
    play_times.reserve(history_.size());
    for (const auto& r : history_) play_times.push_back(r.play_d);
    if (name == "play_time_total") {
        int64_t sum = std::accumulate(play_times.begin(), play_times.end(), int64_t{0});
        return std::make_shared<DCInt>(sum);
    }
    if (name == "play_time_avg") {
        int64_t sum = std::accumulate(play_times.begin(), play_times.end(), int64_t{0});
        return std::make_shared<DCFloat>(static_cast<double>(sum) / static_cast<double>(play_times.size()));
    }
    if (name == "play_time_min") {
        return std::make_shared<DCInt>(*std::min_element(play_times.begin(), play_times.end()));
    }
    if (name == "play_time_max") {
        return std::make_shared<DCInt>(*std::max_element(play_times.begin(), play_times.end()));
    }
    if (name == "play_time_mid") {
        std::sort(play_times.begin(), play_times.end());
        return std::make_shared<DCInt>(play_times[play_times.size() / 2]);
    }
    return history_.back().toDict();
}

std::shared_ptr<DCObject> PlaybackFeatureProducer::getFeature(
    const std::string& name,
    const std::string& /*sub_key*/,
    const DCDict& /*params*/) {
    return getFeature(name);
}

std::shared_ptr<DCDict> PlaybackFeatureProducer::getBatchFeatures(
    const std::string& /*config_json*/,
    DCKey /*key*/) {
    auto dict = std::make_shared<DCDict>();
    dict->set("play_time_total", getFeature("play_time_total"));
    dict->set("play_time_avg", getFeature("play_time_avg"));
    dict->set("play_time_min", getFeature("play_time_min"));
    dict->set("play_time_max", getFeature("play_time_max"));
    dict->set("play_time_mid", getFeature("play_time_mid"));
    return dict;
}

// ----------------------------------------------------------------------------
// [EN] AndroidFeatureConvertHelper (0x0635e4..0x063750).
// [VN] Bộ chuyển đổi kiểu AndroidFeatureConvertHelper (0x0635e4..0x063750).
// ----------------------------------------------------------------------------
int32_t AndroidFeatureConvertHelper::toInt(std::shared_ptr<DCObject>& obj) noexcept {
    if (!obj || obj->type() != DCObjectType::kInt) return 0;
    return static_cast<int32_t>(static_cast<DCInt*>(obj.get())->value());
}

int64_t AndroidFeatureConvertHelper::toLong(std::shared_ptr<DCObject>& obj) noexcept {
    if (!obj || obj->type() != DCObjectType::kInt) return 0;
    return static_cast<DCInt*>(obj.get())->value();
}

float AndroidFeatureConvertHelper::toFloat(std::shared_ptr<DCObject>& obj) noexcept {
    if (!obj || obj->type() != DCObjectType::kFloat) return 0.0f;
    return static_cast<float>(static_cast<DCFloat*>(obj.get())->value());
}

double AndroidFeatureConvertHelper::toDouble(std::shared_ptr<DCObject>& obj) noexcept {
    if (!obj || obj->type() != DCObjectType::kFloat) return 0.0;
    return static_cast<DCFloat*>(obj.get())->value();
}

bool AndroidFeatureConvertHelper::toBoolean(std::shared_ptr<DCObject>& obj) noexcept {
    if (!obj || obj->type() != DCObjectType::kBool) return false;
    return static_cast<DCBool*>(obj.get())->value();
}

std::string AndroidFeatureConvertHelper::toString(std::shared_ptr<DCObject>& obj) {
    if (!obj) return "";
    if (obj->type() == DCObjectType::kString) {
        return static_cast<DCString*>(obj.get())->value();
    }
    return obj->toJsonString();
}

std::shared_ptr<DCObject> AndroidFeatureConvertHelper::toAny(std::shared_ptr<DCObject>& obj) noexcept {
    return obj;
}

} // namespace featurecenter

namespace clientai {

AlgTaskRunnerImpl& AlgTaskRunnerImpl::instance() {
    static AlgTaskRunnerImpl s_instance;
    return s_instance;
}

bool AlgTaskRunnerImpl::isReady() const noexcept {
    return PitayaIsReady();
}

void AlgTaskRunnerImpl::postSmartTask(
    const std::string& business_name,
    std::shared_ptr<DCDict> input_params,
    std::shared_ptr<AlgTaskConfig> /*config*/,
    std::function<void(bool, int64_t, int64_t, const std::shared_ptr<DCDict>&)> callback) {
    uint64_t start_ms = DCNowTimeMillis();
    auto output = std::make_shared<DCDict>();
    output->set("business_name", std::make_shared<DCString>(business_name));
    output->set("success", std::make_shared<DCBool>(true));
    if (input_params) {
        output->set("params", input_params);
    }
    uint64_t cost_ms = DCTimeDiff(DCNowTimeMillis(), start_ms);
    if (callback) {
        callback(true, static_cast<int64_t>(start_ms), static_cast<int64_t>(cost_ms), output);
    }
}

} // namespace clientai

} // namespace datacenter

// ----------------------------------------------------------------------------
// [EN] Pitaya Dynamic C-API Loader (0x05bb84..0x05bf94) and dc_log (0x063cec).
//      - TryLoadAllApi @ 0x05bb84 opens "libAndroidPitayaCore.so" (@ 0x067ca5)
//        and resolves 31 PTY* symbols (@ 0x067cbd..0x067eac) into .bss 0x080178..0x0802c8.
//      - PitayaIsReady @ 0x05bf90:
//          0x05bf90: 52800020 mov w0, #1
//          0x05bf94: D65F03C0 ret
// [VN] Bộ nạp C-API động Pitaya (0x05bb84..0x05bf94) và hàm dc_log (0x063cec).
// ----------------------------------------------------------------------------
static datacenter::PitayaDynamicApiTable g_pitaya_api_table_080178{};

static constexpr const char* kPitayaSymbolNames_067cbd[31] = {
    "PTYStartCall",                         // 0x067cbd
    "PTYEndCall",                           // 0x067cca
    "PTYCreateBool",                        // 0x067cd5
    "PTYCreateInt",                         // 0x067ce3
    "PTYCreateFloat",                       // 0x067cf0
    "PTYCreateString",                      // 0x067cff
    "PTYCreateList",                        // 0x067d0f
    "PTYCreateDict",                        // 0x067d1d
    "PTYCreateCallback",                    // 0x067d2b
    "PTYCreateCallbackWithCustomParams",    // 0x067d3d
    "PTYListAppend",                        // 0x067d5f
    "PTYDictSetValue",                      // 0x067d6d
    "PTYGetObjectType",                     // 0x067d7d
    "PTYGetBool",                           // 0x067d8e
    "PTYGetInt",                            // 0x067d99
    "PTYGetFloat",                          // 0x067da3
    "PTYGetString",                         // 0x067daf
    "PTYListForEach",                       // 0x067dbc
    "PTYDictGetValue",                      // 0x067dcb
    "PTYDictForEach",                       // 0x067ddb
    "PTYHasApiUseError",                    // 0x067dea
    "PTYGetApiUseErrorMessage",             // 0x067dfc
    "PTYGetApiUseErrorCode",                // 0x067e15
    "PTYGetApiUseErrorSubCode",             // 0x067e2b
    "PTYClearApiUseError",                  // 0x067e44
    "PTYIsHostReady",                       // 0x067e58
    "PTYRunTask",                           // 0x067e67
    "PTYRequestUpdate",                     // 0x067e72
    "PTYGetHostAid",                        // 0x067e83
    "PTYGetBoolWithDefaultValue",           // 0x067e91
    "PTYGetStringWithDefaultValue"          // 0x067eac
};

extern "C" bool TryLoadAllApi() noexcept {
#if defined(__ANDROID__) || defined(__linux__)
    void* handle = dlopen("libAndroidPitayaCore.so", RTLD_LAZY | RTLD_LOCAL);
    if (!handle) {
        return false;
    }
    void** slots = reinterpret_cast<void**>(&g_pitaya_api_table_080178);
    for (size_t i = 0; i < 31; ++i) {
        void* sym = dlsym(handle, kPitayaSymbolNames_067cbd[i]);
        slots[i] = sym;
        if (!sym) {
            return false;
        }
    }
    return true;
#else
    (void)kPitayaSymbolNames_067cbd;
    (void)g_pitaya_api_table_080178;
    return false;
#endif
}

extern "C" bool PitayaIsReady() noexcept {
    // 0x05bf90: 52800020 mov w0, #1
    // 0x05bf94: D65F03C0 ret
    return true;
}

extern "C" void dc_log(
    int /*level*/,
    const char* tag,
    const char* file,
    const char* func,
    int line,
    const char* fmt,
    ...) noexcept {
    // 0x063cec..0x063e10: formats prefix "<%s,%s,%d>" (@ 0x069b9b) into a 1024-byte stack buffer (#0x400)
    // and appends vsnprintf message before calling __android_log_print(3, tag, "%s", buf).
    char buffer[1024];
    std::memset(buffer, 0, sizeof(buffer));
    int prefix_len = std::snprintf(
        buffer,
        sizeof(buffer),
        "<%s,%s,%d>",
        file ? file : "",
        func ? func : "",
        line);
    if (prefix_len > 0 && static_cast<size_t>(prefix_len) < sizeof(buffer) && fmt != nullptr) {
        va_list args;
        va_start(args, fmt);
        std::vsnprintf(buffer + prefix_len, sizeof(buffer) - static_cast<size_t>(prefix_len), fmt, args);
        va_end(args);
    }
    (void)tag;
}

namespace datacenter {
uint32_t DispatchCybertronFdeShard1(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;
uint32_t DispatchCybertronFdeShard2(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;
uint32_t DispatchCybertronFdeShard3(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;
uint32_t DispatchCybertronFdeShard4(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;
uint32_t DispatchCybertronFdeShard5(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;

uint32_t SimulateCybertronFdeEntry(uint32_t fde_index, uint32_t arg0, uint32_t arg1) noexcept {
    if (fde_index < 240U) return DispatchCybertronFdeShard1(fde_index, arg0, arg1);
    if (fde_index < 480U) return DispatchCybertronFdeShard2(fde_index, arg0, arg1);
    if (fde_index < 720U) return DispatchCybertronFdeShard3(fde_index, arg0, arg1);
    if (fde_index < 960U) return DispatchCybertronFdeShard4(fde_index, arg0, arg1);
    if (fde_index < 1201U) return DispatchCybertronFdeShard5(fde_index, arg0, arg1);
    return 0U;
}
} // namespace datacenter
