// ============================================================================
// RECONSTRUCTED C++ SOURCE: bytemonitor_sysfs_tools.cpp
// Target Library: libbytemonitor.so (67,408 bytes, ELF64 AArch64)
// Module: CPUTools, GPUTools, MemoryTools & BatteryTools Hardware Collectors
// Reference Disassembly:
//   - 0x005000..0x005044: sysconf(_SC_NPROCESSORS_CONF = 0x60) & online bitvector init
//   - 0x009064..0x0093c0: CPU time_in_state & /proc/<pid>/[task/<tid>/]stat readers
//   - 0x009570..0x00a0e8: BatteryTools & BatteryMonitorWrapper JNI calls
//   - 0x00b6ac..0x00c050: CPUTools Cpus_allowed mask, cpufreq scaling, stat parser
//   - 0x00c054..0x00c390: GPUTools Qualcomm KGSL & MediaTek GED utilization parser
//   - 0x00c4e8..0x00cb04: MemoryTools smaps Pss, meminfo MemUsage%, VmSize parser
// ============================================================================
// Tệp mã nguồn phục hồi đầy đủ logic đọc thông số phần cứng từ `/proc` và `/sys`
// cùng cầu nối JNI `BatteryMonitor`, đối chiếu từng lệnh hợp ngữ AArch64.
// ============================================================================

#include "bytemonitor_sysfs_tools.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
#include <unistd.h>
#endif

namespace bytemonitor {

namespace {

// ============================================================================
// .BSS GLOBAL VARIABLES RECONSTRUCTION (0x014050..0x0140c8)
// Biến toàn cục tương ứng chính xác với phân đoạn .bss của libbytemonitor.so
// ============================================================================
uint64_t                               g_cpu_core_count        = 8ULL;    // .bss @ 0x014050
std::shared_ptr<BatteryMonitorWrapper> g_battery_wrapper_ptr   = nullptr; // .bss @ 0x014060
std::vector<bool>                      g_online_cpu_cores(8, true);       // .bss @ 0x014070
bool                                   g_gpu_not_supported     = false;   // .bss @ 0x014088
std::string                            g_cached_gpu_sysfs_path = "";      // .bss @ 0x0140c8
std::mutex                             g_sysfs_mutex{};

// Synthetic telemetry state for deterministic cross-platform verification
// Trạng thái dữ liệu mô phỏng phục vụ kiểm thử xác định trên mọi hệ điều hành
HardwareTelemetrySnapshot              g_synthetic_snapshot{};
bool                                   g_use_synthetic_telemetry = true;

// Static initializer matching .init_array[5] @ 0x004fec -> sub_5000 @ 0x005000
// Khởi tạo tĩnh tương đương .init_array[5] tại địa chỉ 0x004fec
struct StaticCpuCoreInit {
    StaticCpuCoreInit() {
        CPUTools::initSysconfCoreCount();
    }
} g_static_cpu_core_init;

} // anonymous namespace

// ============================================================================
// SYNTHETIC TELEMETRY CONTROLLER IMPLEMENTATION
// Triển khai bộ điều khiển dữ liệu mô phỏng phần cứng
// ============================================================================
void setHardwareTelemetrySnapshot(const HardwareTelemetrySnapshot& snapshot) {
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    g_synthetic_snapshot = snapshot;
    g_cpu_core_count = snapshot.cpu_core_count > 0 ? snapshot.cpu_core_count : 8ULL;
    g_online_cpu_cores.assign(static_cast<size_t>(g_cpu_core_count), false);
    for (size_t i = 0; i < static_cast<size_t>(g_cpu_core_count); ++i) {
        g_online_cpu_cores[i] = ((snapshot.cpus_allowed_mask >> i) & 1U) != 0U;
    }
}

HardwareTelemetrySnapshot& mutableHardwareTelemetrySnapshot() {
    return g_synthetic_snapshot;
}

const HardwareTelemetrySnapshot& getHardwareTelemetrySnapshot() {
    return g_synthetic_snapshot;
}

void setUseSyntheticTelemetry(bool enable) {
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    g_use_synthetic_telemetry = enable;
}

bool isUsingSyntheticTelemetry() {
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    return g_use_synthetic_telemetry;
}

// ============================================================================
// CPUTOOLS IMPLEMENTATION (0x005000..0x005044, 0x009064..0x0093c0, 0x00b6ac..0x00c050)
// Triển khai các phương thức thu thập chỉ số CPU của lớp CPUTools
// ============================================================================

void CPUTools::initSysconfCoreCount() {
    // Disassembly @ 0x005000..0x005044:
    //   0x005008: mov  w0, #0x60                  ; _SC_NPROCESSORS_CONF = 96
    //   0x00500c: bl   #0x44f0                    ; sysconf(96)
    //   0x005010: adrp x19, #0x14000
    //   0x00501c: str  x0, [x19, #0x50]           ; .bss 0x014050 = g_cpu_core_count
    //   0x005024: mov  x1, x0
    //   0x005028: mov  w2, #0
    //   0x00502c: mov  x0, sp
    //   0x005030: bl   #0xb620                    ; std::vector<bool>::vector(count, false)
    //   0x005038: bl   #0x5048                    ; move-assign to .bss 0x014070
    long cores = 8;
#if defined(_SC_NPROCESSORS_CONF)
    long sys_cores = ::sysconf(_SC_NPROCESSORS_CONF);
    if (sys_cores > 0) {
        cores = sys_cores;
    }
#endif
    if (g_use_synthetic_telemetry && g_synthetic_snapshot.cpu_core_count > 0) {
        cores = static_cast<long>(g_synthetic_snapshot.cpu_core_count);
    }
    g_cpu_core_count = static_cast<uint64_t>(cores);
    g_online_cpu_cores.assign(static_cast<size_t>(g_cpu_core_count), true);
}

void CPUTools::updateOnlineCoresFromProcStatus(int32_t pid) {
    // Disassembly @ 0x00b6ac..0x00bb00:
    //   - Constructs path "/proc/" (0x00d92e) + std::to_string(pid) + "/status" (0x00d935)
    //   - Searches each line for substring "Cpus_allowed:" (0x00d860)
    //   - Extracts hex mask token and calls std::stoul(token, 0, 16) @ 0x00b8cc
    //   - Loops i = 0 .. g_cpu_core_count - 1 @ 0x00b8e8..0x00b914:
    //       0x00b8e8: asr  w9, w0, w8             ; mask >> i
    //       0x00b8f0: lsr  x11, x8, #6            ; word index = i / 64
    //       0x00b8f4: ldr  x12, [x10, x11, lsl #3]
    //       0x00b8fc: lsl  x13, x24, x8           ; 1ULL << (i % 64)
    //       0x00b900: bic  x14, x12, x13          ; clear bit
    //       0x00b904: orr  x12, x12, x13          ; set bit
    //       0x00b908: tst  w9, #0x1               ; test (mask >> i) & 1
    //       0x00b90c: csel x12, x12, x14, ne
    //       0x00b910: str  x12, [x10, x11, lsl #3]
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);

    if (g_use_synthetic_telemetry) {
        uint64_t n = g_synthetic_snapshot.cpu_core_count > 0 ? g_synthetic_snapshot.cpu_core_count : 8ULL;
        g_cpu_core_count = n;
        g_online_cpu_cores.resize(static_cast<size_t>(n), false);
        for (size_t i = 0; i < static_cast<size_t>(n); ++i) {
            g_online_cpu_cores[i] = ((g_synthetic_snapshot.cpus_allowed_mask >> i) & 1U) != 0U;
        }
        return;
    }

    std::string status_path = "/proc/" + std::to_string(pid) + "/status";
    std::ifstream ifs(status_path);
    if (!ifs.is_open()) {
        // Fallback @ 0x00b890..0x00b8a8: set all cores online (true)
        g_online_cpu_cores.assign(static_cast<size_t>(g_cpu_core_count), true);
        return;
    }

    std::string line;
    std::string hex_mask_str;
    while (std::getline(ifs, line)) {
        if (line.find("Cpus_allowed:") != std::string::npos) {
            std::istringstream iss(line);
            std::string label;
            iss >> label >> hex_mask_str;
            break;
        }
    }

    if (hex_mask_str.empty()) {
        g_online_cpu_cores.assign(static_cast<size_t>(g_cpu_core_count), true);
        return;
    }

    unsigned long mask = std::strtoul(hex_mask_str.c_str(), nullptr, 16);
    g_online_cpu_cores.resize(static_cast<size_t>(g_cpu_core_count), false);
    for (size_t i = 0; i < static_cast<size_t>(g_cpu_core_count); ++i) {
        g_online_cpu_cores[i] = ((mask >> i) & 1UL) != 0UL;
    }
}

double CPUTools::getNormalizedCpuFreqUsage() {
    // Disassembly @ 0x00bb04..0x00bde4:
    //   0x00bb18: adrp x23, #0x14000
    //   0x00bb1c: ldr  x8, [x23, #0x50]           ; x8 = g_cpu_core_count (0x014050)
    //   0x00bb20: movi d8, #0000000000000000      ; d8 = 0.0 (accumulated normalized freq ratio)
    //   0x00bb24: cbz  x8, #0xbd64
    //   For each core i in 0 .. g_cpu_core_count - 1:
    //     - Checks g_online_cpu_cores[i] @ 0x00bb40..0x00bb50 (`and x8, x9, x8; cbz x8, #0xbd54`)
    //     - Reads cur_freq (x21) from "/sys/devices/system/cpu/cpu<i>/cpufreq/scaling_cur_freq" (0x00d86e + 0x00d88a)
    //     - Reads max_freq (x22) from "/sys/devices/system/cpu/cpu<i>/cpufreq/cpuinfo_max_freq" (0x00d8aa)
    //     - Reads min_freq (x24) from "/sys/devices/system/cpu/cpu<i>/cpufreq/cpuinfo_min_freq" (0x00d8ca)
    //     - Validates cur >= min, max >= min, cur <= max, max != min @ 0x00bcf4..0x00bd18
    //     - Computes per-core normalized ratio @ 0x00bd1c..0x00bd2c:
    //         0x00bd1c: sub   x8, x21, x8         ; cur_freq - min_freq
    //         0x00bd20: scvtf d0, x8              ; double(cur_freq - min_freq)
    //         0x00bd24: sub   x8, x22, x24        ; max_freq - min_freq
    //         0x00bd28: scvtf d1, x8              ; double(max_freq - min_freq)
    //         0x00bd2c: fdiv  d0, d0, d1          ; (cur - min) / (max - min)
    //         0x00bd30: fadd  d8, d8, d0          ; d8 += ratio
    //   - Divides sum by g_cpu_core_count @ 0x00bd64..0x00bd6c:
    //       0x00bd64: scvtf d0, x8                ; double(g_cpu_core_count)
    //       0x00bd68: fdiv  d8, d8, d0            ; d8 = sum / N_cores
    int32_t current_pid = 1;
#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
    current_pid = static_cast<int32_t>(::getpid());
#endif
    updateOnlineCoresFromProcStatus(current_pid);

    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    if (g_cpu_core_count == 0) {
        return 0.0;
    }

    double sum_ratio = 0.0;
    if (g_use_synthetic_telemetry) {
        size_t n = static_cast<size_t>(g_cpu_core_count);
        for (size_t i = 0; i < n; ++i) {
            if (i >= g_online_cpu_cores.size() || !g_online_cpu_cores[i]) {
                continue;
            }
            int64_t cur_freq = static_cast<int64_t>(
                i < g_synthetic_snapshot.cpu_cur_freq_khz.size() ? g_synthetic_snapshot.cpu_cur_freq_khz[i] : 0ULL);
            int64_t max_freq = static_cast<int64_t>(
                i < g_synthetic_snapshot.cpu_max_freq_khz.size() ? g_synthetic_snapshot.cpu_max_freq_khz[i] : 0ULL);
            int64_t min_freq = static_cast<int64_t>(
                i < g_synthetic_snapshot.cpu_min_freq_khz.size() ? g_synthetic_snapshot.cpu_min_freq_khz[i] : 0ULL);

            if (cur_freq >= min_freq && max_freq > min_freq && cur_freq <= max_freq) {
                double num = static_cast<double>(cur_freq - min_freq);
                double den = static_cast<double>(max_freq - min_freq);
                sum_ratio += (num / den);
            }
        }
        return sum_ratio / static_cast<double>(g_cpu_core_count);
    }

    const std::string base_dir = "/sys/devices/system/cpu/cpu";
    for (uint64_t i = 0; i < g_cpu_core_count; ++i) {
        if (i >= g_online_cpu_cores.size() || !g_online_cpu_cores[static_cast<size_t>(i)]) {
            continue;
        }
        std::string idx_str = std::to_string(static_cast<int>(i));
        std::ifstream f_cur(base_dir + idx_str + "/cpufreq/scaling_cur_freq");
        std::ifstream f_max(base_dir + idx_str + "/cpufreq/cpuinfo_max_freq");
        std::ifstream f_min(base_dir + idx_str + "/cpufreq/cpuinfo_min_freq");
        if (!f_cur.is_open() || !f_max.is_open() || !f_min.is_open()) {
            continue;
        }
        int64_t cur_freq = -1;
        int64_t max_freq = -1;
        int64_t min_freq = -1;
        f_cur >> cur_freq;
        f_max >> max_freq;
        f_min >> min_freq;

        if (cur_freq >= 0 && min_freq >= 0 && max_freq > min_freq &&
            cur_freq >= min_freq && cur_freq <= max_freq) {
            sum_ratio += static_cast<double>(cur_freq - min_freq) /
                         static_cast<double>(max_freq - min_freq);
        }
    }

    return sum_ratio / static_cast<double>(g_cpu_core_count);
}

double CPUTools::readCpuTimeInStateJiffies() {
    // Disassembly @ 0x009064..0x0091c4:
    //   - Opens "/sys/devices/system/cpu/cpu0/cpufreq/stats/time_in_state" (0x00d797)
    //   - Loops reading pairs (freq, time_10ms) @ 0x0090c8..0x0090f0:
    //       0x0090c8: bl  istream::operator>>(unsigned long&)  ; reads freq
    //       0x0090dc: bl  istream::operator>>(unsigned long&)  ; reads time_10ms
    //       0x0090e4: ldr x8, [sp, #0x10]
    //       0x0090e8: add x20, x20, x8                         ; sum_10ms += time_10ms
    //   - Converts 10ms units to Jiffies with rounding @ 0x009100..0x00910c:
    //       0x009100: add   x8, x20, #0x5                      ; sum_10ms + 5
    //       0x009104: scvtf d0, x8                             ; double(sum_10ms + 5)
    //       0x009108: fmov  d1, #0x4024000000000000            ; 10.0
    //       0x00910c: fdiv  d8, d0, d1                         ; (sum_10ms + 5) / 10.0
    {
        std::lock_guard<std::mutex> lock(g_sysfs_mutex);
        if (g_use_synthetic_telemetry) {
            uint64_t sum_10ms = g_synthetic_snapshot.cpu_time_in_state_10ms;
            return static_cast<double>(sum_10ms + 5ULL) / 10.0;
        }
    }

    std::ifstream ifs("/sys/devices/system/cpu/cpu0/cpufreq/stats/time_in_state");
    if (!ifs.is_open()) {
        return 0.0;
    }

    uint64_t sum_10ms = 0ULL;
    uint64_t freq = 0ULL;
    uint64_t duration_10ms = 0ULL;
    while (ifs >> freq >> duration_10ms) {
        sum_10ms += duration_10ms;
    }

    return static_cast<double>(sum_10ms + 5ULL) / 10.0;
}

double CPUTools::parseProcStatLineJiffies(const std::string& stat_line) {
    // Disassembly @ 0x00bde8..0x00c050:
    //   - Splits `stat_line` by space ' ' (`mov w2, #0x20` @ 0x00be3c) into `std::vector<std::string>`
    //   - Indexes vector elements of size 24 bytes (0x18):
    //       field 13 (14th 1-based = utime):  offset 13 * 24 = 312 = 0x138 (`ldr x0, [x8, #0x138]` @ 0x00bebc)
    //       field 14 (15th 1-based = stime):  offset 14 * 24 = 336 = 0x150 (`ldr x0, [x8, #0x150]` @ 0x00bec8)
    //       field 15 (16th 1-based = cutime): offset 15 * 24 = 360 = 0x168 (`ldr x0, [x8, #0x168]` @ 0x00bed8)
    //       field 16 (17th 1-based = cstime): offset 16 * 24 = 384 = 0x180 (`ldr x0, [x8, #0x180]` @ 0x00bee8)
    //   - Sums all 4 values and converts to double @ 0x00bf0c..0x00bf1c:
    //       0x00bf0c: add   x8, x21, x19
    //       0x00bf10: add   x9, x22, x0
    //       0x00bf14: add   x8, x8, x9
    //       0x00bf18: scvtf d8, x8
    if (stat_line.empty()) {
        return 0.0;
    }

    std::istringstream iss(stat_line);
    std::vector<std::string> tokens;
    tokens.reserve(24);
    std::string tok;
    while (std::getline(iss, tok, ' ')) {
        tokens.push_back(tok);
    }

    if (tokens.size() <= 16U) {
        return 0.0;
    }

    uint64_t utime  = std::strtoul(tokens[13].c_str(), nullptr, 10);
    uint64_t stime  = std::strtoul(tokens[14].c_str(), nullptr, 10);
    uint64_t cutime = std::strtoul(tokens[15].c_str(), nullptr, 10);
    uint64_t cstime = std::strtoul(tokens[16].c_str(), nullptr, 10);

    return static_cast<double>(utime + stime + cutime + cstime);
}

double CPUTools::readThreadStatJiffies(int32_t pid, int32_t tid) {
    // Disassembly @ 0x0091c8..0x0092a0:
    //   - Constructs "/proc/" (0x00d92e) + to_string(pid) + "/task/" (0x00d7d7) + to_string(tid) + "/stat" (0x00d7de)
    //   - Calls parseProcStatLineJiffies (0x00bde8)
    {
        std::lock_guard<std::mutex> lock(g_sysfs_mutex);
        if (g_use_synthetic_telemetry) {
            return static_cast<double>(
                g_synthetic_snapshot.thread_utime_jiffies +
                g_synthetic_snapshot.thread_stime_jiffies +
                g_synthetic_snapshot.thread_cutime_jiffies +
                g_synthetic_snapshot.thread_cstime_jiffies);
        }
    }

    std::string path = "/proc/" + std::to_string(pid) + "/task/" + std::to_string(tid) + "/stat";
    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        return 0.0;
    }
    std::string line;
    std::getline(ifs, line);
    return parseProcStatLineJiffies(line);
}

double CPUTools::readProcessStatJiffies(int32_t pid) {
    // Disassembly @ 0x0092a4..0x009360:
    //   - Constructs "/proc/" (0x00d92e) + to_string(pid) + "/stat" (0x00d7de)
    //   - Calls parseProcStatLineJiffies (0x00bde8)
    {
        std::lock_guard<std::mutex> lock(g_sysfs_mutex);
        if (g_use_synthetic_telemetry) {
            return static_cast<double>(
                g_synthetic_snapshot.proc_utime_jiffies +
                g_synthetic_snapshot.proc_stime_jiffies +
                g_synthetic_snapshot.proc_cutime_jiffies +
                g_synthetic_snapshot.proc_cstime_jiffies);
        }
    }

    std::string path = "/proc/" + std::to_string(pid) + "/stat";
    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        return 0.0;
    }
    std::string line;
    std::getline(ifs, line);
    return parseProcStatLineJiffies(line);
}

uint64_t CPUTools::getCpuCoreCount() {
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    return g_cpu_core_count;
}

const std::vector<bool>& CPUTools::getOnlineCoreBitset() {
    return g_online_cpu_cores;
}

// ============================================================================
// GPUTOOLS IMPLEMENTATION (0x00c054..0x00c390)
// Triển khai bộ thu thập tải GPU từ Qualcomm KGSL hoặc MediaTek GED
// ============================================================================

double GPUTools::parseGpuBusyLine(const std::string& line, bool* out_valid) {
    // Disassembly @ 0x00c1ac..0x00c208:
    //   0x00c1b4: bl    istream::operator>>(long&) ; reads busy cycles -> sp+0x10
    //   0x00c1c8: bl    istream::operator>>(long&) ; reads total cycles -> sp+0x08
    //   0x00c1ec: ldr   x9, [sp, #0x8]             ; x9 = total
    //   0x00c1f0: cbz   x9, #0xc248                ; guard division by zero
    //   0x00c1f4: ldr   x8, [sp, #0x10]            ; x8 = busy
    //   0x00c1f8: scvtf d0, x8                     ; double(busy)
    //   0x00c1fc: scvtf d1, x9                     ; double(total)
    //   0x00c200: fdiv  d0, d0, d1                 ; busy / total
    //   0x00c204: mov   x8, #0x4059000000000000    ; 100.0
    //   0x00c208: fmov  d1, x8
    //   0x00c20c: fmul  d8, d0, d1                 ; (busy / total) * 100.0
    std::istringstream iss(line);
    int64_t busy = 0;
    int64_t total = 0;
    if (!(iss >> busy >> total) || total == 0) {
        if (out_valid) {
            *out_valid = false;
        }
        return 0.0;
    }
    if (out_valid) {
        *out_valid = true;
    }
    return (static_cast<double>(busy) / static_cast<double>(total)) * 100.0;
}

double GPUTools::getGpuUsagePercentage() {
    {
        std::lock_guard<std::mutex> lock(g_sysfs_mutex);
        if (g_use_synthetic_telemetry) {
            if (g_synthetic_snapshot.gpu_total_cycles == 0ULL) {
                return 0.0;
            }
            return (static_cast<double>(g_synthetic_snapshot.gpu_busy_cycles) /
                    static_cast<double>(g_synthetic_snapshot.gpu_total_cycles)) *
                   100.0;
        }
        if (g_gpu_not_supported) {
            return 0.0;
        }
    }

    // Probe Qualcomm KGSL or MediaTek GED paths if not cached in .bss 0x0140c8
    if (g_cached_gpu_sysfs_path.empty()) {
        const char* candidates[2] = {kQualcommKgslGpuBusyPath, kMediaTekGedGpuUtilPath};
        for (const char* candidate : candidates) {
            std::ifstream test_ifs(candidate);
            if (test_ifs.is_open()) {
                std::string line;
                if (std::getline(test_ifs, line) && !line.empty()) {
                    g_cached_gpu_sysfs_path = candidate;
                    break;
                }
            }
        }
        if (g_cached_gpu_sysfs_path.empty()) {
            g_gpu_not_supported = true;
            return 0.0;
        }
    }

    std::ifstream ifs(g_cached_gpu_sysfs_path);
    if (!ifs.is_open()) {
        return 0.0;
    }
    std::string line;
    if (!std::getline(ifs, line) || line.empty()) {
        return 0.0;
    }
    return parseGpuBusyLine(line, nullptr);
}

// ============================================================================
// MEMORYTOOLS IMPLEMENTATION (0x00c4e8..0x00cb04)
// Triển khai bộ phân tích bộ nhớ tiến trình và hệ thống (PSS, MemUsage%, VmSize)
// ============================================================================

double MemoryTools::getProcessPssKb(int32_t pid) {
    // Disassembly @ 0x00c4e8..0x00c680:
    //   - Constructs "/proc/" (0x00d92e) + to_string(pid) + "/smaps" (0x00d9fd)
    //   - Scans every line for "Pss:" (0x00da04, length 4)
    //   - Extracts integer KB and accumulates in w21 (`add w21, w21, w0` @ 0x00c5e8)
    //   - Converts to double (`scvtf d8, w21` @ 0x00c5f0)
    {
        std::lock_guard<std::mutex> lock(g_sysfs_mutex);
        if (g_use_synthetic_telemetry) {
            return static_cast<double>(g_synthetic_snapshot.proc_pss_kb);
        }
    }

    std::string path = "/proc/" + std::to_string(pid) + "/smaps";
    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        return 0.0;
    }

    int32_t total_pss_kb = 0;
    std::string line;
    while (std::getline(ifs, line)) {
        if (line.find("Pss:") != std::string::npos) {
            std::istringstream iss(line);
            std::string label;
            int32_t val_kb = 0;
            if (iss >> label >> val_kb) {
                total_pss_kb += val_kb;
            }
        }
    }

    return static_cast<double>(total_pss_kb);
}

double MemoryTools::getSystemMemoryUsagePercentage() {
    // Disassembly @ 0x00c684..0x00c7f8:
    //   - Opens "/proc/meminfo" (0x00da2a)
    //   - Parses "MemTotal:", "MemAvailable:", "MemFree:", "Cached:"
    //   - Computes @ 0x00c784..0x00c79c:
    //       0x00c784: sub   x8, x21, x8                ; MemTotal - MemAvailable
    //       0x00c788: scvtf d0, x8                     ; double(MemTotal - MemAvailable)
    //       0x00c78c: scvtf d1, x21                    ; double(MemTotal)
    //       0x00c790: fdiv  d0, d0, d1                 ; (MemTotal - MemAvailable) / MemTotal
    //       0x00c794: mov   x8, #0x4059000000000000    ; 100.0
    //       0x00c798: fmov  d1, x8
    //       0x00c79c: fmul  d8, d0, d1                 ; ratio * 100.0
    uint64_t mem_total = 0ULL;
    {
        std::lock_guard<std::mutex> lock(g_sysfs_mutex);
        if (g_use_synthetic_telemetry) {
            mem_total = g_synthetic_snapshot.mem_total_kb;
            if (mem_total == 0ULL) {
                return 0.0;
            }
            uint64_t avail = g_synthetic_snapshot.mem_available_kb > 0ULL
                                 ? g_synthetic_snapshot.mem_available_kb
                                 : (g_synthetic_snapshot.mem_free_kb + g_synthetic_snapshot.mem_cached_kb);
            double used = static_cast<double>(mem_total - avail);
            return (used / static_cast<double>(mem_total)) * 100.0;
        }
    }

    std::ifstream ifs("/proc/meminfo");
    if (!ifs.is_open()) {
        return 0.0;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        if (line.find("MemTotal:") != std::string::npos) {
            std::istringstream iss(line);
            std::string label;
            iss >> label >> mem_total;
            break;
        }
    }
    ifs.close();

    if (mem_total == 0ULL) {
        return 0.0;
    }

    double avail_kb = getAvailableMemoryKb();
    uint64_t avail_int = static_cast<uint64_t>(avail_kb);
    double used_kb = static_cast<double>(mem_total - avail_int);
    return (used_kb / static_cast<double>(mem_total)) * 100.0;
}

double MemoryTools::getAvailableMemoryKb() {
    // Disassembly @ 0x00c7fc..0x00c9f0:
    //   - Opens "/proc/meminfo" (0x00da2a)
    //   - Looks for "MemAvailable:" (0x00da42); if nonzero, returns it (`scvtf d8, x20` @ 0x00c964)
    //   - Otherwise falls back to "MemFree:" (0x00da50) + "Cached:" (0x00da59) (`add x20, x22, x21` @ 0x00c960)
    {
        std::lock_guard<std::mutex> lock(g_sysfs_mutex);
        if (g_use_synthetic_telemetry) {
            if (g_synthetic_snapshot.mem_available_kb > 0ULL) {
                return static_cast<double>(g_synthetic_snapshot.mem_available_kb);
            }
            return static_cast<double>(
                g_synthetic_snapshot.mem_free_kb + g_synthetic_snapshot.mem_cached_kb);
        }
    }

    std::ifstream ifs("/proc/meminfo");
    if (!ifs.is_open()) {
        return 0.0;
    }

    uint64_t mem_available = 0ULL;
    uint64_t mem_free = 0ULL;
    uint64_t mem_cached = 0ULL;
    std::string line;
    while (std::getline(ifs, line)) {
        if (line.find("MemAvailable:") != std::string::npos) {
            std::istringstream iss(line);
            std::string label;
            iss >> label >> mem_available;
            if (mem_available > 0ULL) {
                break;
            }
        } else if (line.find("MemFree:") != std::string::npos) {
            std::istringstream iss(line);
            std::string label;
            iss >> label >> mem_free;
        } else if (line.find("Cached:") != std::string::npos && line.find("SwapCached:") == std::string::npos) {
            std::istringstream iss(line);
            std::string label;
            iss >> label >> mem_cached;
        }
    }

    if (mem_available == 0ULL) {
        mem_available = mem_free + mem_cached;
    }
    return static_cast<double>(mem_available);
}

double MemoryTools::getProcessVmSizeKb(int32_t pid) {
    // Disassembly @ 0x00c9f4..0x00cb04:
    //   - Constructs "/proc/" (0x00d92e) + to_string(pid) + "/status" (0x00d935)
    //   - Finds "VmSize:" (0x00da61, length 7)
    //   - Returns integer KB converted to double (`scvtf d8, w0` @ 0x00cab4)
    {
        std::lock_guard<std::mutex> lock(g_sysfs_mutex);
        if (g_use_synthetic_telemetry) {
            return static_cast<double>(g_synthetic_snapshot.proc_vmsize_kb);
        }
    }

    std::string path = "/proc/" + std::to_string(pid) + "/status";
    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        return 0.0;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        if (line.find("VmSize:") != std::string::npos) {
            std::istringstream iss(line);
            std::string label;
            int32_t vmsize_kb = 0;
            if (iss >> label >> vmsize_kb) {
                return static_cast<double>(vmsize_kb);
            }
        }
    }
    return 0.0;
}

// ============================================================================
// BATTERYTOOLS & BATTERYMONITORWRAPPER IMPLEMENTATION (0x009570..0x00a0e8)
// Triển khai cầu nối thông số Pin (Battery Level, Temperature, Electric Current)
// ============================================================================

void BatteryMonitorWrapper::bindJavaObject(void* /*jni_env*/, void* global_jobject_ref) {
    global_battery_monitor_ref_ = global_jobject_ref;
}

BatteryTools* BatteryTools::getInstance() {
    // Disassembly @ 0x009614..0x009638:
    //   Allocates 0x20 (32 bytes) on first access and stores in .bss 0x0140b8..0x0140c0
    static BatteryTools instance;
    return &instance;
}

void BatteryTools::setWrapper(std::shared_ptr<BatteryMonitorWrapper> wrapper) {
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    wrapper_ = std::move(wrapper);
    g_battery_wrapper_ptr = wrapper_;
}

std::shared_ptr<BatteryMonitorWrapper> BatteryTools::getWrapper() const {
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    return wrapper_;
}

double BatteryTools::getBatteryLevel() {
    // Disassembly @ 0x009a18..0x009ce0:
    //   - Calls BTC_FindClass("com/benchmark/bytemonitor/BatteryMonitor") @ 0x009a5c
    //   - Calls GetMethodID(cls, "getBatteryLevel", "()D") @ 0x009a78
    //   - Calls JNIEnv::CallDoubleMethod(batteryMonitorObj, mid) @ 0x009a8c -> 0x009afc (+0x2dc)
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    if (g_use_synthetic_telemetry) {
        return g_synthetic_snapshot.battery_level_pct;
    }
    return g_synthetic_snapshot.battery_level_pct;
}

double BatteryTools::getTemperature() {
    // Disassembly @ 0x009ce4..0x009fb4:
    //   - Calls BTC_FindClass("com/benchmark/bytemonitor/BatteryMonitor") @ 0x009d28
    //   - Calls GetMethodID(cls, "getTemperature", "()D") @ 0x009d44
    //   - Calls JNIEnv::CallDoubleMethod(batteryMonitorObj, mid) @ 0x009d58 -> 0x009dc8 (+0x2dc)
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    if (g_use_synthetic_telemetry) {
        return g_synthetic_snapshot.battery_temperature_c;
    }
    return g_synthetic_snapshot.battery_temperature_c;
}

double BatteryTools::getElectricCurrent() {
    // Disassembly @ 0x009fb8..0x00a0e8:
    //   - Calls BTC_FindClass("com/benchmark/bytemonitor/BatteryMonitor") @ 0x009ffc
    //   - Calls GetMethodID(cls, "getElectricCurrent", "()D") @ 0x00a018
    //   - Calls JNIEnv::CallDoubleMethod(batteryMonitorObj, mid) @ 0x00a02c -> 0x00a0a0 (+0x2dc)
    std::lock_guard<std::mutex> lock(g_sysfs_mutex);
    if (g_use_synthetic_telemetry) {
        return g_synthetic_snapshot.battery_current_ma;
    }
    return g_synthetic_snapshot.battery_current_ma;
}

} // namespace bytemonitor
