// ============================================================================
// RECONSTRUCTED C++ HEADER: bytemonitor_sysfs_tools.h
// Target Library: libbytemonitor.so (67,408 bytes, ELF64 AArch64)
// Module: CPUTools, GPUTools, MemoryTools & BatteryTools Hardware Collectors
// Reference Disassembly:
//   - CPUTools:     0x005000..0x005044, 0x009064..0x0093c0, 0x00b6ac..0x00c050
//   - GPUTools:     0x00c054..0x00c390
//   - MemoryTools:  0x00c4e8..0x00cb04
//   - BatteryTools: 0x009570..0x00a0e8
// ============================================================================
// Tệp tiêu đề định nghĩa 4 bộ thu thập chỉ số phần cứng cấp thấp (CPUTools, GPUTools,
// MemoryTools, BatteryTools) đọc trực tiếp từ hệ thống tệp ảo Linux (/proc, /sys)
// và cầu nối JNI BatteryMonitor trong libbytemonitor.so.
// ============================================================================

#pragma once

#include "bytemonitor_types.h"
#include <cstdint>
#include <string>
#include <vector>

namespace bytemonitor {

// ============================================================================
// 1. SYNTHETIC / HOST TELEMETRY SNAPSHOT FOR DETERMINISTIC VERIFICATION
// Cấu trúc dữ liệu mô phỏng phần cứng phục vụ kiểm thử độc lập trên Windows/Linux
// khi không có quyền truy cập trực tiếp /sys/devices/system/cpu hoặc /sys/class/kgsl
// ============================================================================
struct HardwareTelemetrySnapshot {
    uint32_t              cpu_core_count{8};
    uint32_t              cpus_allowed_mask{0xFFU}; // 8 cores online (0b11111111)
    std::vector<uint64_t> cpu_cur_freq_khz{1800000, 1800000, 1800000, 1800000,
                                           2400000, 2400000, 2400000, 2800000};
    std::vector<uint64_t> cpu_min_freq_khz{600000,  600000,  600000,  600000,
                                           800000,  800000,  800000,  1000000};
    std::vector<uint64_t> cpu_max_freq_khz{2000000, 2000000, 2000000, 2000000,
                                           2600000, 2600000, 2600000, 3000000};
    uint64_t              cpu_time_in_state_10ms{125005ULL}; // 10ms units in time_in_state
    uint64_t              proc_utime_jiffies{420ULL};
    uint64_t              proc_stime_jiffies{130ULL};
    uint64_t              proc_cutime_jiffies{25ULL};
    uint64_t              proc_cstime_jiffies{15ULL};
    uint64_t              thread_utime_jiffies{210ULL};
    uint64_t              thread_stime_jiffies{65ULL};
    uint64_t              thread_cutime_jiffies{10ULL};
    uint64_t              thread_cstime_jiffies{10ULL};
    uint64_t              gpu_busy_cycles{36000ULL};
    uint64_t              gpu_total_cycles{80000ULL};
    uint64_t              mem_total_kb{8388608ULL};      // 8 GB in KB
    uint64_t              mem_available_kb{3145728ULL};  // 3 GB available in KB
    uint64_t              mem_free_kb{1048576ULL};       // 1 GB free in KB
    uint64_t              mem_cached_kb{2097152ULL};     // 2 GB cached in KB
    uint64_t              proc_pss_kb{184320ULL};        // 180 MB PSS in KB
    uint64_t              proc_vmsize_kb{4718592ULL};    // 4.5 GB VmSize in KB
    double                battery_level_pct{86.5};       // 86.5 %
    double                battery_temperature_c{34.2};   // 34.2 Celsius
    double                battery_current_ma{-415.0};    // -415.0 mA discharging
};

// ============================================================================
// 2. CPUTOOLS — LINUX /PROC & /SYS CPU FREQUENCY & JIFFIES ANALYZER
// Phục hồi từ .text @ 0x005000..0x005044, 0x009064..0x0093c0, 0x00b6ac..0x00c050
// ============================================================================
class CPUTools {
public:
    /**
     * @brief Static constructor helper at 0x005000 (`sub_5000` invoked by `.init_array[5]` @ `0x004fec`).
     * Calls `sysconf(0x60 = 96 = _SC_NPROCESSORS_CONF)` and resizes `.bss 0x014070` (`g_online_cpu_cores`).
     * Khởi tạo số lõi CPU qua `sysconf(96)` và cấp phát vector bitset trạng thái lõi online.
     */
    static void initSysconfCoreCount();

    /**
     * @brief Parses `"Cpus_allowed:"` hex mask from `/proc/<pid>/status` (`0x00b6ac..0x00bb00`).
     * Đọc mặt nạ thập lục phân `Cpus_allowed:` từ `/proc/<pid>/status` để cập nhật danh sách lõi online.
     */
    static void updateOnlineCoresFromProcStatus(int32_t pid);

    /**
     * @brief Computes normalized CPU frequency load across online cores (`0x00bb04..0x00bde4`).
     * Formula at `0x00bd1c..0x00bd6c`:
     *   ratio = (1.0 / N_cores) * sum_{i in online} ((cur_freq[i] - min_freq[i]) / (max_freq[i] - min_freq[i]))
     * Note: `Lambda_Type1_CPUUsage` (`0x008af8`) multiplies this ratio by `100.0` (`0x4059000000000000`).
     * Tính tỷ lệ xung nhịp CPU chuẩn hóa trên toàn bộ các lõi đang hoạt động.
     */
    static double getNormalizedCpuFreqUsage();

    /**
     * @brief Reads `/sys/devices/system/cpu/cpu0/cpufreq/stats/time_in_state` (`0x009064..0x0091c4`).
     * Formula at `0x009100..0x00910c`:
     *   `add x8, x20, #5; scvtf d0, x8; fmov d1, #10.0; fdiv d8, d0, d1` -> `(sum_10ms + 5) / 10.0`
     * Đọc tổng thời gian hoạt động theo trạng thái xung nhịp của cụm CPU0 và quy đổi về đơn vị Jiffies.
     */
    static double readCpuTimeInStateJiffies();

    /**
     * @brief Parses space-separated `/proc/.../stat` line and sums fields 14..17 (`0x00bde8..0x00c050`).
     * Offsets in `std::vector<std::string>` (`24 B` per string):
     *   field[13] (`+0x138`) = utime
     *   field[14] (`+0x150`) = stime
     *   field[15] (`+0x168`) = cutime
     *   field[16] (`+0x180`) = cstime
     * Phân tích dòng trạng thái `/proc/.../stat` và tính tổng 4 trường `utime + stime + cutime + cstime`.
     */
    static double parseProcStatLineJiffies(const std::string& stat_line);

    /**
     * @brief Reads `/proc/<pid>/task/<tid>/stat` (`0x0091c8..0x0092a0`).
     * Đọc tổng Jiffies của một luồng cụ thể (`tid`) thuộc tiến trình (`pid`).
     */
    static double readThreadStatJiffies(int32_t pid, int32_t tid);

    /**
     * @brief Reads `/proc/<pid>/stat` (`0x0092a4..0x009360`).
     * Đọc tổng Jiffies của toàn tiến trình (`pid`).
     */
    static double readProcessStatJiffies(int32_t pid);

    // Accessors for testing and state inspection / Hàm truy vấn trạng thái phục vụ kiểm thử
    static uint64_t getCpuCoreCount();
    static const std::vector<bool>& getOnlineCoreBitset();
};

// ============================================================================
// 3. GPUTOOLS — QUALCOMM KGSL & MEDIATEK GED GPU UTILIZATION COLLECTOR
// Phục hồi từ .text @ 0x00c054..0x00c390
// ============================================================================
class GPUTools {
public:
    // .rodata @ 0x00d9a5: "/sys/class/kgsl/kgsl-3d0/gpubusy"
    static constexpr const char* kQualcommKgslGpuBusyPath =
        "/sys/class/kgsl/kgsl-3d0/gpubusy";
    // .rodata @ 0x00d9c6: "/sys/kernel/debug/ged/hal/gpu_utilization"
    static constexpr const char* kMediaTekGedGpuUtilPath =
        "/sys/kernel/debug/ged/hal/gpu_utilization";

    /**
     * @brief Computes GPU utilization percentage (`0x00c054..0x00c390`).
     * Formula at `0x00c1f4..0x00c208`:
     *   `scvtf d0, x8; scvtf d1, x9; fdiv d0, d0, d1; mov x8, #0x4059000000000000; fmov d1, x8; fmul d8, d0, d1`
     *   GPUUsage% = (double(busy) / double(total)) * 100.0
     * Tính phần trăm tải GPU từ Qualcomm KGSL hoặc MediaTek GED sysfs.
     */
    static double getGpuUsagePercentage();

    /**
     * @brief Parses a raw `"<busy> <total>"` line from `gpubusy` or `gpu_utilization`.
     * Phân tích chuỗi `"<busy> <total>"` và tính `(busy / total) * 100.0`.
     */
    static double parseGpuBusyLine(const std::string& line, bool* out_valid = nullptr);
};

// ============================================================================
// 4. MEMORYTOOLS — LINUX /PROC/MEMINFO, /PROC/<PID>/SMAPS & STATUS ANALYZER
// Phục hồi từ .text @ 0x00c4e8..0x00cb04
// ============================================================================
class MemoryTools {
public:
    /**
     * @brief Sums all `"Pss:"` entries in `/proc/<pid>/smaps` (`0x00c4e8..0x00c680`).
     * Tính tổng bộ nhớ PSS (Proportional Set Size) theo KB của tiến trình từ `/proc/<pid>/smaps`.
     */
    static double getProcessPssKb(int32_t pid);

    /**
     * @brief Computes system-wide RAM usage percentage from `/proc/meminfo` (`0x00c684..0x00c7f8`).
     * Formula at `0x00c784..0x00c79c`:
     *   `sub x8, x21, x8; scvtf d0, x8; scvtf d1, x21; fdiv d0, d0, d1; mov x8, #0x4059000000000000; fmov d1, x8; fmul d8, d0, d1`
     *   MemUsage% = ((MemTotal - MemAvailable) / MemTotal) * 100.0
     * Tính phần trăm sử dụng RAM toàn hệ thống từ `/proc/meminfo`.
     */
    static double getSystemMemoryUsagePercentage();

    /**
     * @brief Reads available system memory in KB from `/proc/meminfo` (`0x00c7fc..0x00c9f0`).
     * Returns `MemAvailable:` if present, or `MemFree: + Cached:` (`0x00c960: add x20, x22, x21`).
     * Đọc dung lượng bộ nhớ khả dụng (KB) từ `/proc/meminfo`.
     */
    static double getAvailableMemoryKb();

    /**
     * @brief Reads `"VmSize:"` in KB from `/proc/<pid>/status` (`0x00c9f4..0x00cb04`).
     * Đọc kích thước bộ nhớ ảo `VmSize:` (KB) của tiến trình từ `/proc/<pid>/status`.
     */
    static double getProcessVmSizeKb(int32_t pid);
};

// ============================================================================
// 5. BATTERYTOOLS & BATTERYMONITORWRAPPER — JNI BATTERY TELEMETRY BRIDGE
// Phục hồi từ .text @ 0x009570..0x00a0e8
// ============================================================================
class BatteryMonitorWrapper {
public:
    BatteryMonitorWrapper() = default;
    ~BatteryMonitorWrapper() = default;

    void bindJavaObject(void* jni_env, void* global_jobject_ref);
    void* getGlobalRef() const { return global_battery_monitor_ref_; }

private:
    void* global_battery_monitor_ref_{nullptr}; // +0x18 in control-block allocation @ 0x009658
};

class BatteryTools {
public:
    /**
     * @brief Returns singleton `BatteryTools*` at `.bss 0x0140b8..0x0140c0` (`0x009614..0x009638`).
     * Truy xuất thực thể đơn (Singleton) `BatteryTools`.
     */
    static BatteryTools* getInstance();

    /**
     * @brief Invokes `com/benchmark/bytemonitor/BatteryMonitor.getBatteryLevel()D` (`0x009a18..0x009ce0`).
     * Gọi phương thức JNI `getBatteryLevel()D` để lấy phần trăm pin hiện tại.
     */
    double getBatteryLevel();

    /**
     * @brief Invokes `com/benchmark/bytemonitor/BatteryMonitor.getTemperature()D` (`0x009ce4..0x009fb4`).
     * Gọi phương thức JNI `getTemperature()D` để lấy nhiệt độ pin (độ C).
     */
    double getTemperature();

    /**
     * @brief Invokes `com/benchmark/bytemonitor/BatteryMonitor.getElectricCurrent()D` (`0x009fb8..0x00a0e8`).
     * Gọi phương thức JNI `getElectricCurrent()D` để lấy cường độ dòng điện tức thời của pin (mA).
     */
    double getElectricCurrent();

    void setWrapper(std::shared_ptr<BatteryMonitorWrapper> wrapper);
    std::shared_ptr<BatteryMonitorWrapper> getWrapper() const;

private:
    BatteryTools() = default;
    std::shared_ptr<BatteryMonitorWrapper> wrapper_{nullptr};
};

// ============================================================================
// 6. SYNTHETIC TELEMETRY CONTROLLER (FOR HOST / CROSS-PLATFORM SELF-TEST)
// Bộ điều khiển dữ liệu mô phỏng phục vụ kiểm thử toán học chính xác 100%
// ============================================================================
void setHardwareTelemetrySnapshot(const HardwareTelemetrySnapshot& snapshot);
HardwareTelemetrySnapshot& mutableHardwareTelemetrySnapshot();
const HardwareTelemetrySnapshot& getHardwareTelemetrySnapshot();
void setUseSyntheticTelemetry(bool enable);
bool isUsingSyntheticTelemetry();

} // namespace bytemonitor
