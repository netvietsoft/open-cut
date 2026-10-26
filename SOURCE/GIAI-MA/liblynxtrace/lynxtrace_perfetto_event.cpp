/**
 * @file lynxtrace_perfetto_event.cpp
 * @brief Exact AArch64 opcode-verified implementation of `lynx::perfetto::*`
 *        and `lynx::trace::*` functions exported in `.dynsym [010]..[043]`
 *        of `liblynxtrace.so`.
 *        Triển khai đối soát opcode AArch64 chính xác của các hàm `lynx::perfetto::*`
 *        và `lynx::trace::*` xuất trong `.dynsym [010]..[043]` của `liblynxtrace.so`.
 */

#include "lynxtrace_perfetto_event.h"

#include <atomic>
#include <mutex>

namespace nextai {
namespace opencut {
namespace lynxtrace {

namespace {

std::atomic<bool> g_telemetry_capture_enabled{false};
std::atomic<uint64_t> g_flow_id_counter{1u};
std::mutex g_trace_events_mutex;
std::vector<RecordedLynxTraceEvent> g_recorded_events;

} // namespace

// ============================================================================
// 1. `ThreadTrack::Current()` (`.dynsym [013]` @ `0x0041ac -> 0x0041ec`)
//    Phương thức `ThreadTrack::Current()` (`.dynsym [013]` @ `0x0041ac -> 0x0041ec`)
// ============================================================================

ThreadTrack ThreadTrack::Current() noexcept {
    // Disassembly @ 0x0041ac -> 0x0041ec:
    //   0x0041ac: b   #0x41ec
    //   0x0041ec: mov x0, xzr
    //   0x0041f0: ret
    ThreadTrack track;
    track.uuid = 0u;
    return track;
}

// ============================================================================
// 2. `LynxDebugAnnotation` Implementation (`.dynsym [014], [021], [022], [026..028], [036..037]`)
//    Triển khai `LynxDebugAnnotation` (tất cả tại `0x0040f8: ret` ở chế độ Release)
// ============================================================================

void LynxDebugAnnotation::set_name(const std::string& name) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        name_ = name;
    }
}

void LynxDebugAnnotation::set_bool_value(bool val) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        bool_val_ = val;
    }
}

void LynxDebugAnnotation::set_uint_value(uint64_t val) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        uint_val_ = val;
    }
}

void LynxDebugAnnotation::set_int_value(int64_t val) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        int_val_ = val;
    }
}

void LynxDebugAnnotation::set_double_value(double val) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        double_val_ = val;
    }
}

void LynxDebugAnnotation::set_string_value(const char* data, size_t len) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed) && data != nullptr) {
        string_val_.assign(data, len);
    }
}

void LynxDebugAnnotation::set_string_value(const std::string& val) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        string_val_ = val;
    }
}

void LynxDebugAnnotation::set_legacy_json_value(const std::string& json_val) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        string_val_ = json_val;
    }
}

// ============================================================================
// 3. `TrackEvent_LegacyEvent` Implementation (`.dynsym [015], [016], [038], [039]`)
//    Triển khai `TrackEvent_LegacyEvent` (tất cả tại `0x0040f8: ret` ở chế độ Release)
// ============================================================================

void TrackEvent_LegacyEvent::set_phase(int32_t phase) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        phase_ = phase;
    }
}

void TrackEvent_LegacyEvent::set_flow_direction(FlowDirection dir) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        flow_dir_ = dir;
    }
}

void TrackEvent_LegacyEvent::set_unscoped_id(uint64_t id) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        unscoped_id_ = id;
    }
}

void TrackEvent_LegacyEvent::set_bind_id(uint64_t bind_id) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        bind_id_ = bind_id;
    }
}

// ============================================================================
// 4. `TrackEvent` Implementation (`.dynsym [017..019], [023], [029], [030], [034], [042], [043]`)
//    Triển khai `TrackEvent`
// ============================================================================

void TrackEvent::set_name(const std::string& name) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        name_ = name;
    }
}

void TrackEvent::set_track_uuid(uint64_t uuid) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        track_uuid_ = uuid;
    }
}

void TrackEvent::set_timestamp_absolute_us(int64_t timestamp_us) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        timestamp_us_ = timestamp_us;
    }
}

void TrackEvent::add_flow_ids(uint64_t flow_id) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        flow_ids_.push_back(flow_id);
    }
}

void TrackEvent::add_terminating_flow_ids(uint64_t flow_id) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        terminating_flow_ids_.push_back(flow_id);
    }
}

void TrackEvent::add_debug_annotations(const std::string& key, const std::string& val) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        LynxDebugAnnotation ann;
        ann.set_name(key);
        ann.set_string_value(val);
        annotations_.push_back(std::move(ann));
    }
}

void TrackEvent::add_debug_annotations_rvalue(std::string&& key, std::string&& val) {
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        LynxDebugAnnotation ann;
        ann.set_name(key);
        ann.set_string_value(val);
        annotations_.push_back(std::move(ann));
    }
}

LynxDebugAnnotation* TrackEvent::add_debug_annotations_ptr() {
    // Disassembly @ 0x0041ac -> 0x0041ec:
    //   mov x0, xzr; ret (returns nullptr in release binary)
    if (!g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        return nullptr;
    }
    annotations_.emplace_back();
    return &annotations_.back();
}

TrackEvent_LegacyEvent* TrackEvent::set_legacy_event() {
    // Disassembly @ 0x0041ac -> 0x0041ec:
    //   mov x0, xzr; ret (returns nullptr in release binary)
    if (!g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        return nullptr;
    }
    return &legacy_event_;
}

// ============================================================================
// 5. `TraceEventBeginEx`, `TraceEventEndEx`, `TraceCounterEx` & `lynx::trace::*`
//    Triển khai `TraceEventBeginEx`, `TraceEventEndEx`, `TraceCounterEx` & `lynx::trace::*`
// ============================================================================

void TraceEventBeginExImpl(const char* category, const char* name) {
    // Disassembly @ 0x0040f8: ret
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        std::lock_guard<std::mutex> lock(g_trace_events_mutex);
        g_recorded_events.push_back(RecordedLynxTraceEvent{
            TraceEventType::kBegin,
            category ? category : "",
            name ? name : "",
            0u,
            false,
        });
    }
}

void TraceEventEndExImpl(const char* category, const char* name) {
    // Disassembly @ 0x0040f8: ret
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        std::lock_guard<std::mutex> lock(g_trace_events_mutex);
        g_recorded_events.push_back(RecordedLynxTraceEvent{
            TraceEventType::kEnd,
            category ? category : "",
            name ? name : "",
            0u,
            false,
        });
    }
}

void TraceCounterExImpl(const char* category, const char* name, uint64_t value, bool incremental) {
    // Disassembly @ 0x0040f8: ret
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        std::lock_guard<std::mutex> lock(g_trace_events_mutex);
        g_recorded_events.push_back(RecordedLynxTraceEvent{
            TraceEventType::kCounter,
            category ? category : "",
            name ? name : "",
            value,
            incremental,
        });
    }
}

uint64_t GetFlowIdImpl() noexcept {
    // Disassembly @ 0x0041ac -> 0x0041ec: mov x0, xzr; ret
    if (!g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        return 0u;
    }
    return g_flow_id_counter.fetch_add(1u, std::memory_order_relaxed);
}

int64_t GetTraceTimeNsImpl() noexcept {
    // Disassembly @ 0x0041ac -> 0x0041ec: mov x0, xzr; ret
    return 0;
}

bool TraceEventCategoryEnabledImpl(const char* category) noexcept {
    (void)category;
    // Disassembly @ 0x0041a4 -> 0x0041e4: mov w0, wzr; ret
    return g_telemetry_capture_enabled.load(std::memory_order_relaxed);
}

void TraceRuntimeProfileImpl(const std::string& profile_data, uint64_t track_id, int32_t profile_type) {
    (void)profile_data;
    (void)track_id;
    (void)profile_type;
    // Disassembly @ 0x0040f8: ret
}

void TraceEventImplementationCounter(
    const char* category,
    const CounterTrack& track,
    TraceEventType type,
    const uint64_t& timestamp,
    const uint64_t& value,
    const std::function<void(EventContext)>& callback) {
    (void)timestamp;
    // Disassembly @ 0x0040f8: ret
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        TrackEvent ev;
        if (callback) {
            callback(EventContext{&ev});
        }
        std::lock_guard<std::mutex> lock(g_trace_events_mutex);
        g_recorded_events.push_back(RecordedLynxTraceEvent{
            type,
            category ? category : "",
            track.name ? track.name : "",
            value,
            false,
        });
    }
}

void TraceEventImplementationStringName(
    const char* category,
    const std::string& name,
    TraceEventType type,
    const Track* track,
    const uint64_t& timestamp,
    const std::function<void(EventContext)>& callback) {
    (void)track;
    (void)timestamp;
    // Disassembly @ 0x0040f8: ret
    if (g_telemetry_capture_enabled.load(std::memory_order_relaxed)) {
        TrackEvent ev;
        ev.set_name(name);
        if (callback) {
            callback(EventContext{&ev});
        }
        std::lock_guard<std::mutex> lock(g_trace_events_mutex);
        g_recorded_events.push_back(RecordedLynxTraceEvent{
            type,
            category ? category : "",
            name,
            0u,
            false,
        });
    }
}

void TraceEventImplementationCStringName(
    const char* category,
    const char* name,
    TraceEventType type,
    const Track* track,
    const uint64_t& timestamp,
    const std::function<void(EventContext)>& callback) {
    TraceEventImplementationStringName(
        category,
        name ? std::string(name) : std::string(),
        type,
        track,
        timestamp,
        callback);
}

void SetTelemetryCaptureMode(bool enabled) noexcept {
    g_telemetry_capture_enabled.store(enabled, std::memory_order_relaxed);
}

bool IsTelemetryCaptureModeEnabled() noexcept {
    return g_telemetry_capture_enabled.load(std::memory_order_relaxed);
}

std::vector<RecordedLynxTraceEvent> GetRecordedLynxTraceEvents() {
    std::lock_guard<std::mutex> lock(g_trace_events_mutex);
    return g_recorded_events;
}

void ClearRecordedLynxTraceEvents() {
    std::lock_guard<std::mutex> lock(g_trace_events_mutex);
    g_recorded_events.clear();
}

} // namespace lynxtrace
} // namespace opencut
} // namespace nextai
