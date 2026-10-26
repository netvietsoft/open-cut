/**
 * @file lynxtrace_perfetto_event.h
 * @brief Declarations for `lynx::perfetto::LynxDebugAnnotation`,
 *        `lynx::perfetto::TrackEvent_LegacyEvent`, `lynx::perfetto::TrackEvent`,
 *        `lynx::perfetto::EventContext`, and the C/C++ `lynx::trace::*` functions
 *        exported in `.dynsym [010]..[043]` of `liblynxtrace.so`.
 *        Khai báo các lớp `LynxDebugAnnotation`, `TrackEvent_LegacyEvent`,
 *        `TrackEvent`, `EventContext` và các hàm `lynx::trace::*` xuất trong
 *        `.dynsym [010]..[043]` của `liblynxtrace.so`.
 */

#ifndef NEXTAI_OPENCUT_LYNXTRACE_PERFETTO_EVENT_H_
#define NEXTAI_OPENCUT_LYNXTRACE_PERFETTO_EVENT_H_

#include "lynxtrace_types.h"

#include <cstdint>
#include <functional>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace lynxtrace {

// ============================================================================
// 1. `lynx::perfetto::LynxDebugAnnotation` (8 Exported Methods in `.dynsym`)
//    Lớp `lynx::perfetto::LynxDebugAnnotation` (8 Phương thức Xuất trong `.dynsym`)
// ============================================================================

/**
 * @brief Reconstruction of `lynx::perfetto::LynxDebugAnnotation` covering all 8
 *        exported `.dynsym` methods (`[014]`, `[021]`, `[022]`, `[026]`, `[027]`, `[028]`, `[036]`, `[037]`).
 *        Tái dựng `lynx::perfetto::LynxDebugAnnotation` bao phủ 8 phương thức xuất `.dynsym`.
 *
 * In `liblynxtrace.so` release mode (`OBSERVED`), all 8 methods resolve to `0x0040f8` (`ret`).
 * When telemetry capture is enabled (`NEW_DESIGN`), they populate the annotation fields.
 */
class LynxDebugAnnotation {
public:
    LynxDebugAnnotation() = default;

    // [021] _ZN4lynx8perfetto19LynxDebugAnnotation8set_nameERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE @ 0x0040f8
    void set_name(const std::string& name);

    // [026] _ZN4lynx8perfetto19LynxDebugAnnotation14set_bool_valueEb @ 0x0040f8
    void set_bool_value(bool val);

    // [022] _ZN4lynx8perfetto19LynxDebugAnnotation14set_uint_valueEm @ 0x0040f8
    void set_uint_value(uint64_t val);

    // [027] _ZN4lynx8perfetto19LynxDebugAnnotation13set_int_valueEl @ 0x0040f8
    void set_int_value(int64_t val);

    // [036] _ZN4lynx8perfetto19LynxDebugAnnotation16set_double_valueEd @ 0x0040f8
    void set_double_value(double val);

    // [014] _ZN4lynx8perfetto19LynxDebugAnnotation16set_string_valueEPKcm @ 0x0040f8
    void set_string_value(const char* data, size_t len);

    // [028] _ZN4lynx8perfetto19LynxDebugAnnotation16set_string_valueERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE @ 0x0040f8
    void set_string_value(const std::string& val);

    // [037] _ZN4lynx8perfetto19LynxDebugAnnotation21set_legacy_json_valueERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE @ 0x0040f8
    void set_legacy_json_value(const std::string& json_val);

    const std::string& name() const noexcept { return name_; }
    const std::string& string_value() const noexcept { return string_val_; }
    int64_t int_value() const noexcept { return int_val_; }
    uint64_t uint_value() const noexcept { return uint_val_; }
    double double_value() const noexcept { return double_val_; }
    bool bool_value() const noexcept { return bool_val_; }

private:
    std::string name_;
    std::string string_val_;
    int64_t     int_val_    = 0;
    uint64_t    uint_val_   = 0;
    double      double_val_ = 0.0;
    bool        bool_val_   = false;
};

// ============================================================================
// 2. `lynx::perfetto::TrackEvent_LegacyEvent` (4 Exported Methods in `.dynsym`)
//    Lớp `lynx::perfetto::TrackEvent_LegacyEvent` (4 Phương thức Xuất trong `.dynsym`)
// ============================================================================

/**
 * @brief Reconstruction of `lynx::perfetto::TrackEvent_LegacyEvent` covering all 4
 *        exported `.dynsym` methods (`[015]`, `[016]`, `[038]`, `[039]`).
 *        Tái dựng `lynx::perfetto::TrackEvent_LegacyEvent` bao phủ 4 phương thức xuất `.dynsym`.
 */
class TrackEvent_LegacyEvent {
public:
    // [015] _ZN4lynx8perfetto22TrackEvent_LegacyEvent9set_phaseEi @ 0x0040f8
    void set_phase(int32_t phase);

    // [016] _ZN4lynx8perfetto22TrackEvent_LegacyEvent18set_flow_directionENS0_13FlowDirectionE @ 0x0040f8
    void set_flow_direction(FlowDirection dir);

    // [038] _ZN4lynx8perfetto22TrackEvent_LegacyEvent15set_unscoped_idEm @ 0x0040f8
    void set_unscoped_id(uint64_t id);

    // [039] _ZN4lynx8perfetto22TrackEvent_LegacyEvent11set_bind_idEm @ 0x0040f8
    void set_bind_id(uint64_t bind_id);

    int32_t phase() const noexcept { return phase_; }
    FlowDirection flow_direction() const noexcept { return flow_dir_; }
    uint64_t unscoped_id() const noexcept { return unscoped_id_; }
    uint64_t bind_id() const noexcept { return bind_id_; }

private:
    int32_t       phase_       = 0;
    FlowDirection flow_dir_    = FlowDirection::kUnspecified;
    uint64_t      unscoped_id_ = 0;
    uint64_t      bind_id_     = 0;
};

// ============================================================================
// 3. `lynx::perfetto::TrackEvent` (8 Exported Methods in `.dynsym`)
//    Lớp `lynx::perfetto::TrackEvent` (8 Phương thức Xuất trong `.dynsym`)
// ============================================================================

/**
 * @brief Reconstruction of `lynx::perfetto::TrackEvent` covering all 8 exported
 *        `.dynsym` methods (`[017]`, `[018]`, `[019]`, `[023]`, `[029]`, `[030]`, `[034]`, `[042]`, `[043]`).
 *        Tái dựng `lynx::perfetto::TrackEvent` bao phủ 8 phương thức xuất `.dynsym`.
 */
class TrackEvent {
public:
    // [029] _ZN4lynx8perfetto10TrackEvent8set_nameERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE @ 0x0040f8
    void set_name(const std::string& name);

    // [023] _ZN4lynx8perfetto10TrackEvent14set_track_uuidEm @ 0x0040f8
    void set_track_uuid(uint64_t uuid);

    // [019] _ZN4lynx8perfetto10TrackEvent25set_timestamp_absolute_usEl @ 0x0040f8
    void set_timestamp_absolute_us(int64_t timestamp_us);

    // [017] _ZN4lynx8perfetto10TrackEvent12add_flow_idsEm @ 0x0040f8
    void add_flow_ids(uint64_t flow_id);

    // [034] _ZN4lynx8perfetto10TrackEvent24add_terminating_flow_idsEm @ 0x0040f8
    void add_terminating_flow_ids(uint64_t flow_id);

    // [018] _ZN4lynx8perfetto10TrackEvent21add_debug_annotationsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_ @ 0x0040f8
    void add_debug_annotations(const std::string& key, const std::string& val);

    // [030] _ZN4lynx8perfetto10TrackEvent21add_debug_annotationsEONSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEES9_ @ 0x0040f8
    void add_debug_annotations_rvalue(std::string&& key, std::string&& val);

    // [042] _ZN4lynx8perfetto10TrackEvent21add_debug_annotationsEv @ 0x0041ac -> 0x0041ec (mov x0, xzr; ret)
    LynxDebugAnnotation* add_debug_annotations_ptr();

    // [043] _ZN4lynx8perfetto10TrackEvent16set_legacy_eventEv @ 0x0041ac -> 0x0041ec (mov x0, xzr; ret)
    TrackEvent_LegacyEvent* set_legacy_event();

    const std::string& name() const noexcept { return name_; }
    uint64_t track_uuid() const noexcept { return track_uuid_; }
    int64_t timestamp_us() const noexcept { return timestamp_us_; }

private:
    std::string                      name_;
    uint64_t                         track_uuid_   = 0;
    int64_t                          timestamp_us_ = 0;
    std::vector<uint64_t>            flow_ids_;
    std::vector<uint64_t>            terminating_flow_ids_;
    std::vector<LynxDebugAnnotation> annotations_;
    TrackEvent_LegacyEvent           legacy_event_;
};

struct EventContext {
    TrackEvent* event = nullptr;
};

// ============================================================================
// 4. Exported `lynx::trace::*` and `Trace*Ex` C/C++ Functions
//    Các hàm C/C++ `lynx::trace::*` và `Trace*Ex` xuất trong `.dynsym`
// ============================================================================

struct RecordedLynxTraceEvent {
    TraceEventType type;
    std::string    category;
    std::string    name;
    uint64_t       counter_value;
    bool           incremental;
};

// [010] TraceEventBeginEx @ 0x0040f8
void TraceEventBeginExImpl(const char* category, const char* name);

// [025] TraceEventEndEx @ 0x0040f8
void TraceEventEndExImpl(const char* category, const char* name);

// [020] TraceCounterEx @ 0x0040f8
void TraceCounterExImpl(const char* category, const char* name, uint64_t value, bool incremental);

// [012] _ZN4lynx5trace9GetFlowIdEv @ 0x0041ac -> 0x0041ec (mov x0, xzr; ret)
uint64_t GetFlowIdImpl() noexcept;

// [040] _ZN4lynx5trace14GetTraceTimeNsEv @ 0x0041ac -> 0x0041ec (mov x0, xzr; ret)
int64_t GetTraceTimeNsImpl() noexcept;

// [031] _ZN4lynx5trace25TraceEventCategoryEnabledEPKc @ 0x0041a4 -> 0x0041e4 (mov w0, wzr; ret)
bool TraceEventCategoryEnabledImpl(const char* category) noexcept;

// [032] _ZN4lynx5trace19TraceRuntimeProfileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEmi @ 0x0040f8
void TraceRuntimeProfileImpl(const std::string& profile_data, uint64_t track_id, int32_t profile_type);

// [033] TraceEventImplementation (CounterTrack overload) @ 0x0040f8
void TraceEventImplementationCounter(
    const char* category,
    const CounterTrack& track,
    TraceEventType type,
    const uint64_t& timestamp,
    const uint64_t& value,
    const std::function<void(EventContext)>& callback);

// [035] TraceEventImplementation (std::string name overload) @ 0x0040f8
void TraceEventImplementationStringName(
    const char* category,
    const std::string& name,
    TraceEventType type,
    const Track* track,
    const uint64_t& timestamp,
    const std::function<void(EventContext)>& callback);

// [041] TraceEventImplementation (const char* name overload) @ 0x0040f8
void TraceEventImplementationCStringName(
    const char* category,
    const char* name,
    TraceEventType type,
    const Track* track,
    const uint64_t& timestamp,
    const std::function<void(EventContext)>& callback);

void SetTelemetryCaptureMode(bool enabled) noexcept;
bool IsTelemetryCaptureModeEnabled() noexcept;
std::vector<RecordedLynxTraceEvent> GetRecordedLynxTraceEvents();
void ClearRecordedLynxTraceEvents();

} // namespace lynxtrace
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LYNXTRACE_PERFETTO_EVENT_H_
