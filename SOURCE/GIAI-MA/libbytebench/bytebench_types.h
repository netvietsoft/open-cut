// ============================================================================
// File: bytebench_types.h
// Target 107 / 169: libbytebench.so (641,376 bytes)
// SHA-256: 0c50323c365781575186c196f06dd36acea1eb80eba82d7d647581306dc4d7b2
// EN: Exact AArch64 ABI struct layouts for bytebench::BXMonitor,
//     bytebench::BXFeatureProcessConfig, bytebench::ByteBenchConfiguration,
//     bytebench::StrategySettings, and STERational.
// VI: Bố cục struct ABI AArch64 chính xác cho bytebench::BXMonitor,
//     bytebench::BXFeatureProcessConfig, bytebench::ByteBenchConfiguration,
//     bytebench::StrategySettings và STERational.
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <memory>

namespace bytebench {

enum class ByteBenchValueType : int32_t {
    kInvalid = 0,
    kInt     = 1,
    kLong    = 2,
    kFloat   = 3,
    kDouble  = 4,
    kBool    = 5,
    kString  = 6
};

enum class BXFeatureProcessTime : int32_t {
    kRealTime = 0,
    kCached   = 1,
    kSession  = 2
};

// EN: Rational fraction struct verified in BXFFReduce(STERational&) @ 0x06b084:
//     `ldpsw x22, x23, [x0]` loads int32_t num at +0x00 and int32_t den at +0x04.
// VI: Cấu trúc phân số xác minh trong BXFFReduce(STERational&) @ 0x06b084:
//     `ldpsw x22, x23, [x0]` nạp int32_t num tại +0x00 và int32_t den tại +0x04.
struct STERational {
    int32_t num; // +0x00
    int32_t den; // +0x04
};
static_assert(sizeof(STERational) == 8, "STERational must be 8 bytes");

struct BXEventWindow {
    int64_t time_window_ms{0};
    int32_t max_event_count{0};
};

struct BXSessionWindow {
    int32_t session_offset{0};
    int32_t session_count{1};
};

struct BXEventSource {
    std::string event_name;
    int64_t timestamp_ms{0};
    std::unordered_map<std::string, std::string> params;
};

// EN: Exact ABI offsets of BXMonitor verified from BXMonitor::BXMonitor (0x027a14..0x027a70)
//     and BatteryLevel/CPUFreq (0x027de8..0x027e04: ldr x0, [x0, #0x158]):
//     +0x000: vptr
//     +0x018: cpu_usage_ring   (capacity 5 @ 0x027a30)
//     +0x088: battery_cur_ring (capacity 10 @ 0x027a44, accessed in BatteryElectricCurrent @ 0x027f8c)
//     +0x0F8: cpu_speed_ring   (capacity 5 @ 0x027a54, accessed in CPUSpeedAverage @ 0x027f94)
//     +0x158: bytemonitor_ptr  (void*, dereferenced at +0x158 in BatteryLevel @ 0x027de8 & CPUFreq @ 0x027df8)
// VI: Bố cục ABI chính xác của BXMonitor xác minh từ BXMonitor::BXMonitor (0x027a14..0x027a70)
struct BXMonitorAbiLayout {
    void*    vptr;                   // +0x000
    uint64_t flags_08;               // +0x008
    uint64_t flags_10;               // +0x010
    uint8_t  cpu_usage_ring[0x70];   // +0x018..0x087
    uint8_t  battery_cur_ring[0x70]; // +0x088..0x0F7
    uint8_t  cpu_speed_ring[0x60];   // +0x0F8..0x157
    void*    bytemonitor_ptr;        // +0x158
    void*    bytemonitor_ctrl;       // +0x160
    uint64_t reserved_168[2];        // +0x168..0x177
};
static_assert(offsetof(BXMonitorAbiLayout, cpu_usage_ring) == 0x18, "cpu_usage_ring must be at +0x18");
static_assert(offsetof(BXMonitorAbiLayout, battery_cur_ring) == 0x88, "battery_cur_ring must be at +0x88");
static_assert(offsetof(BXMonitorAbiLayout, cpu_speed_ring) == 0xF8, "cpu_speed_ring must be at +0xF8");
static_assert(offsetof(BXMonitorAbiLayout, bytemonitor_ptr) == 0x158, "bytemonitor_ptr must be at +0x158");

// EN: Exact ABI offsets of BXFeatureProcessConfig verified from getters at 0x04119c..0x0411f0:
//     +0x008: key                (getKey @ 0x04119c: add x0, x0, #8)
//     +0x020: config_type        (getConfigType @ 0x0411a4: add x0, x0, #0x20)
//     +0x028: event_source       (getEventSource @ 0x0411ac: add x0, x0, #0x28)
//     +0x040: session_window     (getSessionWindow @ 0x0411cc: add x0, x0, #0x40)
//     +0x070: filter_function    (getFilterFunction @ 0x0411b4: add x0, x0, #0x70)
//     +0x0A0: event_window       (getEventWindow @ 0x0411bc: add x0, x0, #0xa0)
//     +0x0B0: component_name     (getComponentName @ 0x0411c4: add x0, x0, #0xb0)
//     +0x0C8: process_time       (getProcessTime @ 0x0411d4: ldr w0, [x0, #0xc8])
//     +0x0CC: process_type       (getProcessType @ 0x0411dc: ldr w0, [x0, #0xcc])
//     +0x0D0: agg_func_double    (getAggregationFunction<double> @ 0x0411e4: add x0, x0, #0xd0)
//     +0x100: agg_func_string    (getAggregationFunction<string> @ 0x0411ec: add x0, x0, #0x100)
// VI: Bố cục ABI chính xác của BXFeatureProcessConfig xác minh từ các hàm getter tại 0x04119c..0x0411f0
struct BXFeatureProcessConfigAbiLayout {
    void*    vptr;                  // +0x000
    uint8_t  key_sso[0x18];         // +0x008..0x01F
    int32_t  config_type;           // +0x020
    uint32_t pad_24;                // +0x024
    uint8_t  event_source_vec[0x18];// +0x028..0x03F
    uint8_t  session_win_map[0x30]; // +0x040..0x06F
    uint8_t  filter_fn_obj[0x30];   // +0x070..0x09F
    BXEventWindow event_window;     // +0x0A0..0x0AF
    uint8_t  component_sso[0x18];   // +0x0B0..0x0C7
    int32_t  process_time;          // +0x0C8
    int32_t  process_type;          // +0x0CC
    uint8_t  agg_fn_double[0x30];   // +0x0D0..0x0FF
    uint8_t  agg_fn_string[0x30];   // +0x100..0x12F
};
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, key_sso) == 0x08, "key_sso must be at +0x08");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, config_type) == 0x20, "config_type must be at +0x20");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, event_source_vec) == 0x28, "event_source_vec must be at +0x28");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, session_win_map) == 0x40, "session_win_map must be at +0x40");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, filter_fn_obj) == 0x70, "filter_fn_obj must be at +0x70");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, event_window) == 0xA0, "event_window must be at +0xA0");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, component_sso) == 0xB0, "component_sso must be at +0xB0");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, process_time) == 0xC8, "process_time must be at +0xC8");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, process_type) == 0xCC, "process_type must be at +0xCC");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, agg_fn_double) == 0xD0, "agg_fn_double must be at +0xD0");
static_assert(offsetof(BXFeatureProcessConfigAbiLayout, agg_fn_string) == 0x100, "agg_fn_string must be at +0x100");

// EN: Exact ABI offsets of ByteBenchConfiguration verified from getters at 0x0442e0..0x04435c:
//     +0x018: device_model     (add x0, x0, #0x18)
//     +0x030: status           (ldr w0, [x0, #0x30])
//     +0x034: aid              (ldr w0, [x0, #0x34])
//     +0x038: bid              (ldr w0, [x0, #0x38])
//     +0x040: app_name         (add x0, x0, #0x40)
//     +0x058: app_version      (add x0, x0, #0x58)
//     +0x070: update_ver_code  (ldr x0, [x0, #0x70])
//     +0x078: did              (add x0, x0, #0x78)
//     +0x090: uid              (add x0, x0, #0x90)
//     +0x0A8: log_level        (ldrb w0, [x0, #0xa8])
//     +0x0A9: open_rt_decision (ldrb w0, [x0, #0xa9])
//     +0x0AA: low_disk_memory  (ldrb w0, [x0, #0xaa])
//     +0x0B0: workspace        (add x0, x0, #0xb0)
//     +0x0C8: platform         (add x0, x0, #0xc8)
//     +0x0E0: cpu_vendor       (add x0, x0, #0xe0)
//     +0x0F8: gl_renderer      (add x0, x0, #0xf8)
//     +0x110: gpu_driver       (add x0, x0, #0x110)
//     +0x128: libra_info       (add x0, x0, #0x128)
// VI: Bố cục ABI chính xác của ByteBenchConfiguration xác minh từ các hàm getter tại 0x0442e0..0x04435c
struct ByteBenchConfigurationAbiLayout {
    uint8_t  base_url_sso[0x18];    // +0x000..0x017
    uint8_t  device_model_sso[0x18];// +0x018..0x02F
    int32_t  status;                // +0x030
    int32_t  aid;                   // +0x034
    int32_t  bid;                   // +0x038
    uint32_t pad_3c;                // +0x03C
    uint8_t  app_name_sso[0x18];    // +0x040..0x057
    uint8_t  app_version_sso[0x18]; // +0x058..0x06F
    int64_t  update_version_code;   // +0x070
    uint8_t  did_sso[0x18];         // +0x078..0x08F
    uint8_t  uid_sso[0x18];         // +0x090..0x0A7
    uint8_t  log_level;             // +0x0A8
    uint8_t  open_runtime_decision; // +0x0A9
    uint8_t  low_disk_memory;       // +0x0AA
    uint8_t  pad_ab[5];             // +0x0AB..0x0AF
    uint8_t  workspace_sso[0x18];   // +0x0B0..0x0C7
    uint8_t  platform_sso[0x18];    // +0x0C8..0x0DF
    uint8_t  cpu_vendor_sso[0x18];  // +0x0E0..0x0F7
    uint8_t  gl_renderer_sso[0x18]; // +0x0F8..0x10F
    uint8_t  gpu_driver_sso[0x18];  // +0x110..0x127
    uint8_t  libra_info_map[0x18];  // +0x128..0x13F
};
static_assert(offsetof(ByteBenchConfigurationAbiLayout, device_model_sso) == 0x18, "device_model_sso offset mismatch");
static_assert(offsetof(ByteBenchConfigurationAbiLayout, status) == 0x30, "status offset mismatch");
static_assert(offsetof(ByteBenchConfigurationAbiLayout, aid) == 0x34, "aid offset mismatch");
static_assert(offsetof(ByteBenchConfigurationAbiLayout, bid) == 0x38, "bid offset mismatch");
static_assert(offsetof(ByteBenchConfigurationAbiLayout, update_version_code) == 0x70, "update_version_code offset mismatch");
static_assert(offsetof(ByteBenchConfigurationAbiLayout, log_level) == 0xA8, "log_level offset mismatch");
static_assert(offsetof(ByteBenchConfigurationAbiLayout, open_runtime_decision) == 0xA9, "open_runtime_decision offset mismatch");
static_assert(offsetof(ByteBenchConfigurationAbiLayout, low_disk_memory) == 0xAA, "low_disk_memory offset mismatch");
static_assert(offsetof(ByteBenchConfigurationAbiLayout, libra_info_map) == 0x128, "libra_info_map offset mismatch");

} // namespace bytebench
