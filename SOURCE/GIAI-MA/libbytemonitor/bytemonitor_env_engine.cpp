// ============================================================================
// RECONSTRUCTED C++ SOURCE: bytemonitor_env_engine.cpp
// Target Library: libbytemonitor.so (67,408 bytes, ELF64 AArch64)
// Module: EnvMonitor Dispatcher, ByteMonitor Base & AndroidMonitor Implementation
// Reference Disassembly:
//   - AndroidMonitor: 0x0050ec..0x005758 (vtable @ 0x012938, 152 bytes)
//   - EnvMonitor:     0x005888..0x009060 (72 bytes @ .bss 0x014098)
//   - ByteMonitor:    0x00cb08..0x00cbd0 (getMonitor @ 0x00cb08, setLogLevel @ 0x00cb74)
// ============================================================================
// Tệp mã nguồn phục hồi đầy đủ bộ điều phối `EnvMonitor`, lớp `ByteMonitor`
// và `AndroidMonitor`, đối chiếu từng lệnh hợp ngữ AArch64 và công thức toán học.
// ============================================================================

#include "bytemonitor_env_engine.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
#include <unistd.h>
#endif

namespace bytemonitor {

namespace {

// ============================================================================
// .DATA & .BSS GLOBALS FOR ENVMONITOR & BYTEMONITOR
// Biến toàn cục trong .data (0x014000) và .bss (0x014010, 0x014098, 0x0140a0, 0x014100)
// ============================================================================
int32_t                      g_log_level               = 8;       // .data @ 0x014000 (default 8 = SILENT)
std::once_flag               g_env_monitor_once_flag{};           // .bss  @ 0x014010
EnvMonitor*                  g_env_monitor_singleton   = nullptr; // .bss  @ 0x014098
std::shared_ptr<ByteMonitor> g_android_monitor_instance= nullptr; // .bss  @ 0x0140a0
std::mutex                   g_global_monitor_mutex{};            // .bss  @ 0x014100

int32_t currentProcessId() {
#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
    return static_cast<int32_t>(::getpid());
#else
    return 1000;
#endif
}

} // anonymous namespace

// ============================================================================
// 1. ENVMONITOR IMPLEMENTATION (0x005888..0x009060)
// Triển khai bộ điều phối trung tâm EnvMonitor (72 bytes = 0x48)
// ============================================================================

EnvMonitor::EnvMonitor() = default;

EnvMonitor* EnvMonitor::getInstance() {
    // Disassembly @ 0x006fa0..0x006fec:
    //   0x006fb0: ldr  x0, [x19, #0x98]           ; load .bss 0x014098
    //   0x006fb4: cbz  x0, #0x6fb8
    //   0x006fb8: mov  w0, #0x48                  ; 72 bytes = sizeof(EnvMonitor)
    //   0x006fbc: bl   #0x40b0                    ; operator new(0x48)
    //   0x006fc8: stp  xzr, xzr, [x20, #0x10]
    //   0x006fcc: stp  xzr, xzr, [x20]            ; unordered_map buckets/size = 0
    //   0x006fd0: mov  w8, #0x3f800000            ; max_load_factor = 1.0f
    //   0x006fd4: str  w8, [x20, #0x20]
    //   0x006fdc: stp  xzr, xzr, [x20, #0x28]     ; mutex zero-init
    //   0x006fe0: str  x20, [x19, #0x98]          ; store singleton in .bss 0x014098
    std::lock_guard<std::mutex> lock(g_global_monitor_mutex);
    if (g_env_monitor_singleton == nullptr) {
        g_env_monitor_singleton = new EnvMonitor();
    }
    return g_env_monitor_singleton;
}

void EnvMonitor::init() {
    // Disassembly @ 0x005888..0x005d5c:
    //   Registers 11 MonitorImpl (272 bytes = 0x110 each) into `monitors_` map:
    //   - 0x0058a4: bl #0x7098 -> MonitorType 1  ("CPU usage", 0x00d560)
    //   - 0x0058ec: bl #0x7168 -> MonitorType 11 ("GPU usage", 0x00d56a)
    //   - 0x005934: bl #0x7234 -> MonitorType 4  ("Memory usage", 0x00d574)
    //   - 0x00597c: bl #0x7300 -> MonitorType 3  ("Available memory", 0x00d581)
    //   - 0x0059c4: bl #0x73cc -> MonitorType 5  ("Battery level", 0x00d592)
    //   - 0x005a0c: bl #0x7498 -> MonitorType 6  ("Battery temperature", 0x00d5a0)
    //   - 0x005a54: bl #0x7564 -> MonitorType 2  ("Thread CPU usage", 0x00d5b4)
    //   - 0x005a9c: bl #0x7638 -> MonitorType 7  ("Process VM", 0x00d5c5)
    //   - 0x005ae4: bl #0x770c -> MonitorType 8  ("Process VMSize", 0x00d5d0)
    //   - 0x005b2c: bl #0x77d8 -> MonitorType 9  ("Process CPU usage", 0x00d5df)
    //   - 0x005b74: bl #0x78a4 -> MonitorType 10 ("Battery ElectricCurrent", 0x00d5f1)
    std::lock_guard<std::mutex> lock(mutex_);
    if (initialized_) {
        return;
    }

    registerMonitorType1_CPU();
    registerMonitorType11_GPU();
    registerMonitorType4_MemoryUsage();
    registerMonitorType3_AvailableMem();
    registerMonitorType5_BatteryLevel();
    registerMonitorType6_Temperature();
    registerMonitorType2_ThreadCPU();
    registerMonitorType7_ProcessVM();
    registerMonitorType8_ProcessVMSize();
    registerMonitorType9_ProcessCPU();
    registerMonitorType10_BatteryCurrent();

    initialized_ = true;
}

void EnvMonitor::registerMonitorType1_CPU() {
    // Disassembly @ 0x007098..0x007164 & Lambda @ 0x008af8..0x008b48:
    //   0x008b0c: bl   #0xbb04                    ; CPUTools::getNormalizedCpuFreqUsage()
    //   0x008b10: mov  x8, #0x4059000000000000    ; 100.0
    //   0x008b14: fmov d1, x8
    //   0x008b18: fmul d8, d0, d1                 ; ratio * 100.0
    //   0x008b1c: fcmp d8, #0.0                   ; if (val < 0.0) val = 0.0
    monitors_[static_cast<int32_t>(MonitorType::kCPUUsage)] = std::make_shared<MonitorImpl>(
        MonitorType::kCPUUsage,
        "CPU usage",
        [](std::shared_ptr<MonitorEvent>& /*ev*/) {},
        [](std::shared_ptr<MonitorEvent>& /*ev*/) -> double {
            double val = CPUTools::getNormalizedCpuFreqUsage() * 100.0;
            return val < 0.0 ? 0.0 : val;
        });
}

void EnvMonitor::registerMonitorType11_GPU() {
    // Disassembly @ 0x007168..0x007230 & Lambda @ 0x008b4c..0x008b88:
    //   0x008b60: bl   #0xc054                    ; GPUTools::getGpuUsagePercentage()
    //   0x008b64: fmov d8, d0
    //   0x008b68: fcmp d8, #0.0
    monitors_[static_cast<int32_t>(MonitorType::kGPUUsage)] = std::make_shared<MonitorImpl>(
        MonitorType::kGPUUsage,
        "GPU usage",
        [](std::shared_ptr<MonitorEvent>& /*ev*/) {},
        [](std::shared_ptr<MonitorEvent>& /*ev*/) -> double {
            double val = GPUTools::getGpuUsagePercentage();
            return val < 0.0 ? 0.0 : val;
        });
}

void EnvMonitor::registerMonitorType4_MemoryUsage() {
    // Disassembly @ 0x007234..0x0072fc & Lambda @ 0x008b8c..0x008bc0:
    //   0x008ba0: bl   #0xc684                    ; MemoryTools::getSystemMemoryUsagePercentage()
    monitors_[static_cast<int32_t>(MonitorType::kMemoryUsage)] = std::make_shared<MonitorImpl>(
        MonitorType::kMemoryUsage,
        "Memory usage",
        [](std::shared_ptr<MonitorEvent>& /*ev*/) {},
        [](std::shared_ptr<MonitorEvent>& /*ev*/) -> double {
            double val = MemoryTools::getSystemMemoryUsagePercentage();
            return val < 0.0 ? 0.0 : val;
        });
}

void EnvMonitor::registerMonitorType3_AvailableMem() {
    // Disassembly @ 0x007300..0x0073c8 & Lambda @ 0x008bc4..0x008bf8:
    //   0x008bd8: bl   #0xc7fc                    ; MemoryTools::getAvailableMemoryKb()
    monitors_[static_cast<int32_t>(MonitorType::kAvailableMemory)] = std::make_shared<MonitorImpl>(
        MonitorType::kAvailableMemory,
        "Available memory",
        [](std::shared_ptr<MonitorEvent>& /*ev*/) {},
        [](std::shared_ptr<MonitorEvent>& /*ev*/) -> double {
            double val = MemoryTools::getAvailableMemoryKb();
            return val < 0.0 ? 0.0 : val;
        });
}

void EnvMonitor::registerMonitorType5_BatteryLevel() {
    // Disassembly @ 0x0073cc..0x007494 & Lambda @ 0x008bfc..0x008c24:
    //   0x008c10: bl   #0x9a18                    ; BatteryTools::getBatteryLevel()
    monitors_[static_cast<int32_t>(MonitorType::kBatteryLevel)] = std::make_shared<MonitorImpl>(
        MonitorType::kBatteryLevel,
        "Battery level",
        [](std::shared_ptr<MonitorEvent>& /*ev*/) {},
        [](std::shared_ptr<MonitorEvent>& /*ev*/) -> double {
            double val = BatteryTools::getInstance()->getBatteryLevel();
            return val < 0.0 ? 0.0 : val;
        });
}

void EnvMonitor::registerMonitorType6_Temperature() {
    // Disassembly @ 0x007498..0x007560 & Lambda @ 0x008c28..0x008c50:
    //   0x008c3c: bl   #0x9ce4                    ; BatteryTools::getTemperature()
    monitors_[static_cast<int32_t>(MonitorType::kBatteryTemperature)] = std::make_shared<MonitorImpl>(
        MonitorType::kBatteryTemperature,
        "Battery temperature",
        [](std::shared_ptr<MonitorEvent>& /*ev*/) {},
        [](std::shared_ptr<MonitorEvent>& /*ev*/) -> double {
            double val = BatteryTools::getInstance()->getTemperature();
            return val < 0.0 ? 0.0 : val;
        });
}

void EnvMonitor::registerMonitorType2_ThreadCPU() {
    // Disassembly @ 0x007564..0x007634:
    //   Begin Lambda @ 0x008c54..0x008cb8:
    //     0x008c84: ldp w0, w1, [x20, #8]         ; pid (+8), tid (+12)
    //     0x008c88: bl  #0x91c8                   ; CPUTools::readThreadStatJiffies(pid, tid)
    //     0x008c90: str d0, [x20, #16]            ; param->start_thread_jiffies = d0 (+0x10)
    //     0x008c94: ldr w0, [x20, #8]             ; pid (+8)
    //     0x008c98: bl  #0x92a4                   ; CPUTools::readProcessStatJiffies(pid)
    //     0x008ca0: str d0, [x20, #24]            ; param->start_proc_jiffies = d0 (+0x18)
    //   End Lambda @ 0x008cbc..0x008dac:
    //     0x008cf0: ldp w0, w1, [x20, #8]
    //     0x008cf4: bl  #0x91c8                   ; end_thread_jiffies
    //     0x008cfc: ldr d1, [x20, #16]            ; start_thread_jiffies
    //     0x008d00: fsub d8, d0, d1               ; delta_thread = end_thread - start_thread
    //     0x008d04: ldr w0, [x20, #8]
    //     0x008d08: bl  #0x92a4                   ; end_proc_jiffies
    //     0x008d10: ldr d1, [x20, #24]            ; start_proc_jiffies
    //     0x008d14: fsub d0, d0, d1               ; delta_proc = end_proc - start_proc
    //     0x008d28: fdiv d0, d8, d0               ; delta_thread / delta_proc
    //     0x008d30: mov  x8, #0x4059000000000000  ; 100.0
    //     0x008d34: fmov d1, x8
    //     0x008d38: fmul d8, d0, d1               ; pct = (delta_thread / delta_proc) * 100.0
    //     0x008d3c: fcmp d8, d1                   ; clamp to [0.0, 100.0]
    //     0x008d40: fcsel d8, d1, d8, gt
    //     0x008d7c: fcvt s0, d8
    //     0x008d80: str  s0, [x20, #32]           ; param->last_usage_pct = float(pct) (+0x20)
    monitors_[static_cast<int32_t>(MonitorType::kThreadCPUUsage)] = std::make_shared<MonitorImpl>(
        MonitorType::kThreadCPUUsage,
        "Thread CPU usage",
        [](std::shared_ptr<MonitorEvent>& ev) {
            if (!ev || !ev->param) {
                return;
            }
            auto* p = dynamic_cast<ThreadCPUParam*>(ev->param.get());
            if (!p) {
                return;
            }
            p->start_thread_jiffies = CPUTools::readThreadStatJiffies(p->pid, p->tid);
            p->start_proc_jiffies   = CPUTools::readProcessStatJiffies(p->pid);
        },
        [](std::shared_ptr<MonitorEvent>& ev) -> double {
            if (!ev || !ev->param) {
                return 0.0;
            }
            auto* p = dynamic_cast<ThreadCPUParam*>(ev->param.get());
            if (!p) {
                return 0.0;
            }
            double end_thread   = CPUTools::readThreadStatJiffies(p->pid, p->tid);
            double delta_thread = end_thread - p->start_thread_jiffies;
            double end_proc     = CPUTools::readProcessStatJiffies(p->pid);
            double delta_proc   = end_proc - p->start_proc_jiffies;

            double pct = 0.0;
            if (delta_proc > 0.0 && delta_thread >= 0.0) {
                pct = (delta_thread / delta_proc) * 100.0;
                if (pct > 100.0) {
                    pct = 100.0;
                }
            }
            if (pct < 0.0) {
                pct = 0.0;
            }
            p->last_usage_pct = static_cast<float>(pct);
            return pct;
        });
}

void EnvMonitor::registerMonitorType7_ProcessVM() {
    // Disassembly @ 0x007638..0x007708:
    //   Begin Lambda @ 0x008db0..0x008de8:
    //     0x008dc8: ldr w0, [x19, #8]             ; pid (+8)
    //     0x008dcc: bl  #0xc4e8                   ; MemoryTools::getProcessPssKb(pid)
    //     0x008dd0: str d0, [x19, #16]            ; param->baseline_metric_primary = start_pss_kb (+0x10)
    //   End Lambda @ 0x008dec..0x008e70:
    //     0x008e18: ldr w0, [x20, #8]             ; pid (+8)
    //     0x008e1c: bl  #0xc4e8                   ; end_pss_kb = MemoryTools::getProcessPssKb(pid)
    //     0x008e20: ldr d1, [x20, #16]            ; start_pss_kb (+0x10)
    //     0x008e24: fsub d8, d0, d1               ; delta_pss_kb = end_pss_kb - start_pss_kb
    monitors_[static_cast<int32_t>(MonitorType::kProcessVMDelta)] = std::make_shared<MonitorImpl>(
        MonitorType::kProcessVMDelta,
        "Process VM",
        [](std::shared_ptr<MonitorEvent>& ev) {
            if (!ev || !ev->param) {
                return;
            }
            auto* p = dynamic_cast<ProcessVMParam*>(ev->param.get());
            if (!p) {
                return;
            }
            p->baseline_metric_primary = MemoryTools::getProcessPssKb(p->pid);
        },
        [](std::shared_ptr<MonitorEvent>& ev) -> double {
            if (!ev || !ev->param) {
                return 0.0;
            }
            auto* p = dynamic_cast<ProcessVMParam*>(ev->param.get());
            if (!p) {
                return 0.0;
            }
            double end_pss = MemoryTools::getProcessPssKb(p->pid);
            double delta   = end_pss - p->baseline_metric_primary;
            return delta < 0.0 ? 0.0 : delta;
        });
}

void EnvMonitor::registerMonitorType8_ProcessVMSize() {
    // Disassembly @ 0x00770c..0x0077d4 & Lambda @ 0x008e74..0x008ea0:
    //   0x008e84: bl #0x44c0                      ; getpid()
    //   0x008e88: bl #0xc9f4                      ; MemoryTools::getProcessVmSizeKb(pid)
    monitors_[static_cast<int32_t>(MonitorType::kProcessVMSize)] = std::make_shared<MonitorImpl>(
        MonitorType::kProcessVMSize,
        "Process VMSize",
        [](std::shared_ptr<MonitorEvent>& /*ev*/) {},
        [](std::shared_ptr<MonitorEvent>& /*ev*/) -> double {
            double val = MemoryTools::getProcessVmSizeKb(currentProcessId());
            return val < 0.0 ? 0.0 : val;
        });
}

void EnvMonitor::registerMonitorType9_ProcessCPU() {
    // Disassembly @ 0x0077d8..0x0078a0:
    //   Begin Lambda @ 0x008ea4..0x008ef8:
    //     0x008ed0: ldr w0, [x20, #8]             ; pid (+8)
    //     0x008ed4: bl  #0x92a4                   ; CPUTools::readProcessStatJiffies(pid)
    //     0x008ed8: str d0, [x20, #16]            ; param->baseline_metric_primary (+0x10)
    //     0x008edc: bl  #0x9064                   ; CPUTools::readCpuTimeInStateJiffies()
    //     0x008ee0: str d0, [x20, #24]            ; param->baseline_metric_secondary (+0x18)
    //   End Lambda @ 0x008efc..0x008ff8:
    //     0x008f2c: ldr w0, [x20, #8]
    //     0x008f30: bl  #0x92a4                   ; end_proc_jiffies
    //     0x008f34: ldr d1, [x20, #16]
    //     0x008f38: fsub d8, d0, d1               ; delta_proc = end_proc - start_proc
    //     0x008f3c: bl  #0x9064                   ; end_cpu_time_in_state
    //     0x008f40: ldr d1, [x20, #24]
    //     0x008f44: fsub d0, d0, d1               ; delta_cpu = end_cpu - start_cpu
    //     0x008f5c: fdiv d0, d8, d0               ; delta_proc / delta_cpu
    //     0x008f60: mov  x8, #0x4059000000000000  ; 100.0
    //     0x008f64: fmov d1, x8
    //     0x008f68: fmul d0, d0, d1               ; (delta_proc / delta_cpu) * 100.0
    //     0x008f6c: adrp x8, #0x14000
    //     0x008f70: ldr  x8, [x8, #0x50]          ; g_cpu_core_count (0x014050)
    //     0x008f74: scvtf d1, x8
    //     0x008f78: fdiv d8, d0, d1               ; divide by N_cores
    monitors_[static_cast<int32_t>(MonitorType::kProcessCPUUsage)] = std::make_shared<MonitorImpl>(
        MonitorType::kProcessCPUUsage,
        "Process CPU usage",
        [](std::shared_ptr<MonitorEvent>& ev) {
            if (!ev || !ev->param) {
                return;
            }
            auto* p = dynamic_cast<ProcessVMParam*>(ev->param.get());
            if (!p) {
                return;
            }
            p->baseline_metric_primary   = CPUTools::readProcessStatJiffies(p->pid);
            p->baseline_metric_secondary = CPUTools::readCpuTimeInStateJiffies();
        },
        [](std::shared_ptr<MonitorEvent>& ev) -> double {
            if (!ev || !ev->param) {
                return 0.0;
            }
            auto* p = dynamic_cast<ProcessVMParam*>(ev->param.get());
            if (!p) {
                return 0.0;
            }
            double end_proc   = CPUTools::readProcessStatJiffies(p->pid);
            double delta_proc = end_proc - p->baseline_metric_primary;
            double end_cpu    = CPUTools::readCpuTimeInStateJiffies();
            double delta_cpu  = end_cpu - p->baseline_metric_secondary;

            uint64_t cores = CPUTools::getCpuCoreCount();
            if (delta_cpu <= 0.0 || delta_proc < 0.0 || cores == 0ULL) {
                return 0.0;
            }
            double pct = ((delta_proc / delta_cpu) * 100.0) / static_cast<double>(cores);
            return pct < 0.0 ? 0.0 : pct;
        });
}

void EnvMonitor::registerMonitorType10_BatteryCurrent() {
    // Disassembly @ 0x0078a4..0x007970 & Lambda @ 0x008ffc..0x009060:
    //   0x009010: bl   #0x9fb8                    ; BatteryTools::getElectricCurrent()
    monitors_[static_cast<int32_t>(MonitorType::kBatteryElectricCurrent)] = std::make_shared<MonitorImpl>(
        MonitorType::kBatteryElectricCurrent,
        "Battery ElectricCurrent",
        [](std::shared_ptr<MonitorEvent>& /*ev*/) {},
        [](std::shared_ptr<MonitorEvent>& /*ev*/) -> double {
            return BatteryTools::getInstance()->getElectricCurrent();
        });
}

void EnvMonitor::beginSection(std::shared_ptr<MonitorEvent>& event) {
    // Disassembly @ 0x006a78..0x006ba4:
    //   - Acquires `this->mutex_` (`add x21, x0, #0x20; bl std::mutex::lock` @ 0x006a94)
    //   - Looks up `event->monitor_type` in `monitors_` hash table
    //   - Calls `MonitorImpl::begin_fn(event)` (`ldr x8, [x0]; ldr x8, [x8, #0x60]; blr x8` @ 0x006b20)
    if (!event) {
        return;
    }
    std::shared_ptr<MonitorImpl> impl;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = monitors_.find(event->monitor_type);
        if (it != monitors_.end()) {
            impl = it->second;
        }
    }
    if (impl && impl->begin_fn) {
        std::lock_guard<std::mutex> impl_lock(impl->mutex);
        impl->begin_fn(event);
    }
}

double EnvMonitor::endSection(std::shared_ptr<MonitorEvent>& event) {
    // Disassembly @ 0x006ba8..0x006ce0:
    //   - Acquires `this->mutex_` (`add x21, x0, #0x20; bl std::mutex::lock` @ 0x006bc8)
    //   - Looks up `event->monitor_type` in `monitors_` hash table
    //   - Calls `MonitorImpl::end_fn(event)` (`ldr x8, [x0]; ldr x8, [x8, #0x80]; blr x8` @ 0x006c58)
    if (!event) {
        return 0.0;
    }
    std::shared_ptr<MonitorImpl> impl;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = monitors_.find(event->monitor_type);
        if (it != monitors_.end()) {
            impl = it->second;
        }
    }
    if (impl && impl->end_fn) {
        std::lock_guard<std::mutex> impl_lock(impl->mutex);
        double value = impl->end_fn(event);
        impl->last_value = value;
        impl->accumulated_value += value;
        impl->sample_count += 1ULL;
        return value;
    }
    return 0.0;
}

void EnvMonitor::dumpInfo(const std::string& tag) {
    // Disassembly @ 0x006ce4..0x006f9c:
    //   Formats report header ("Monitor Performance Results:" @ 0x00d6bd) and iterates all registered monitors
    std::lock_guard<std::mutex> lock(mutex_);
    std::ostringstream oss;
    oss << "[" << tag << "] Monitor Performance Results:\n";
    oss << "--------------------------------------------------------\n";
    for (const auto& kv : monitors_) {
        const auto& m = kv.second;
        if (!m) {
            continue;
        }
        double avg = (m->sample_count > 0ULL)
                         ? (m->accumulated_value / static_cast<double>(m->sample_count))
                         : 0.0;
        oss << std::left << std::setw(26) << m->name
            << " | samples=" << std::setw(6) << m->sample_count
            << " | last=" << std::fixed << std::setprecision(2) << m->last_value
            << " | avg=" << std::fixed << std::setprecision(2) << avg << "\n";
    }
    last_dump_report_ = oss.str();
}

size_t EnvMonitor::getRegisteredMonitorCount() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return monitors_.size();
}

std::shared_ptr<MonitorImpl> EnvMonitor::getMonitorImpl(MonitorType type) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = monitors_.find(static_cast<int32_t>(type));
    return (it != monitors_.end()) ? it->second : nullptr;
}

// ============================================================================
// 2. BYTEMONITOR STATIC FACTORY & LOG LEVEL CONTROLLER (0x00cb08..0x00cbd0)
// Triển khai ByteMonitor::getMonitor() và ByteMonitor::setLogLevel(int)
// ============================================================================

std::shared_ptr<ByteMonitor> ByteMonitor::getMonitor() {
    // Disassembly @ 0x00cb08..0x00cb44:
    //   0x00cb0c: adrp x9, #0x14000
    //   0x00cb10: ldrb w9, [x9, #0xa8]            ; guard variable at .bss 0x0140a8
    //   0x00cb14: ldar w9, [x9]
    //   0x00cb28: bl   __cxa_guard_acquire
    //   0x00cb30: bl   #0xcb48                    ; constructs shared_ptr<AndroidMonitor>
    //   0x00cb3c: bl   __cxa_guard_release
    std::lock_guard<std::mutex> lock(g_global_monitor_mutex);
    if (!g_android_monitor_instance) {
        g_android_monitor_instance = std::make_shared<AndroidMonitor>();
    }
    return g_android_monitor_instance;
}

void ByteMonitor::setLogLevel(int level) {
    // Disassembly @ 0x00cb74..0x00cbd0:
    //   Maps bitmask log level `w0` to Android log priority stored at `.data 0x014000`:
    //     w0 == 1  (0x01) -> 6 (ANDROID_LOG_ERROR)   @ 0x00cb80..0x00cbb4
    //     w0 == 3  (0x03) -> 5 (ANDROID_LOG_WARN)    @ 0x00cb88..0x00cbac
    //     w0 == 7  (0x07) -> 4 (ANDROID_LOG_INFO)    @ 0x00cb90..0x00cbb8
    //     w0 == 15 (0x0f) -> 3 (ANDROID_LOG_DEBUG)   @ 0x00cb9c..0x00cbc0
    //     w0 == 31 (0x1f) -> 2 (ANDROID_LOG_VERBOSE) @ 0x00cba4..0x00cba8
    //     default         -> 8 (ANDROID_LOG_SILENT)  @ 0x00cb94
    int mapped_priority = 8;
    switch (level) {
        case 1:  mapped_priority = 6; break;
        case 3:  mapped_priority = 5; break;
        case 7:  mapped_priority = 4; break;
        case 15: mapped_priority = 3; break;
        case 31: mapped_priority = 2; break;
        default: mapped_priority = 8; break;
    }
    g_log_level = mapped_priority;
}

int ByteMonitor::getLogLevel() {
    return g_log_level;
}

// ============================================================================
// 3. ANDROIDMONITOR IMPLEMENTATION (0x0050ec..0x005758)
// Triển khai toàn bộ 17 phương thức của AndroidMonitor khớp vtable 0x012938
// ============================================================================

AndroidMonitor::AndroidMonitor() {
    // Disassembly @ 0x0050ec..0x0051a0:
    //   0x005104: adrp x8, #0x12000
    //   0x005108: add  x8, x8, #0x938             ; _ZTVN11bytemonitor14AndroidMonitorE
    //   0x00510c: add  x8, x8, #0x10              ; vptr = 0x012948
    //   0x005110: str  x8, [x19]                  ; this->vptr = 0x012948
    //   0x005114: bl   #0x6fa0                    ; EnvMonitor::getInstance()
    //   0x00511c: str  x0, [x19, #8]              ; this->env_monitor_ = x0 (+0x08)
    //   0x005168: bl   std::__call_once           ; calls EnvMonitor::init() @ 0x005888 once via 0x014010
    env_monitor_ = EnvMonitor::getInstance();
    std::call_once(g_env_monitor_once_flag, [this]() {
        if (env_monitor_) {
            env_monitor_->init();
        }
    });
}

AndroidMonitor::~AndroidMonitor() = default;

double AndroidMonitor::CPU() {
    // Disassembly @ 0x005260..0x0052a8:
    //   0x005274: mov w8, #1                      ; MonitorType::kCPUUsage = 1
    //   0x005280: bl  #0x5794                     ; MonitorEvent::create(1, nullptr)
    //   0x005284: bl  #0x6ba8                     ; env_monitor_->endSection(event)
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kCPUUsage), nullptr);
    return env_monitor_ ? env_monitor_->endSection(event) : 0.0;
}

double AndroidMonitor::GPUUsage() {
    // Disassembly @ 0x0052ac..0x0052f4:
    //   0x0052c0: mov w8, #0xb                    ; MonitorType::kGPUUsage = 11 (0x0b)
    //   0x0052cc: bl  #0x5794                     ; MonitorEvent::create(11, nullptr)
    //   0x0052d0: bl  #0x6ba8                     ; env_monitor_->endSection(event)
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kGPUUsage), nullptr);
    return env_monitor_ ? env_monitor_->endSection(event) : 0.0;
}

double AndroidMonitor::MemoryUsage() {
    // Disassembly @ 0x0052f8..0x005340:
    //   0x00530c: mov w8, #4                      ; MonitorType::kMemoryUsage = 4
    //   0x005318: bl  #0x5794                     ; MonitorEvent::create(4, nullptr)
    //   0x00531c: bl  #0x6ba8                     ; env_monitor_->endSection(event)
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kMemoryUsage), nullptr);
    return env_monitor_ ? env_monitor_->endSection(event) : 0.0;
}

double AndroidMonitor::batteryLevel() {
    // Disassembly @ 0x005344..0x00538c:
    //   0x005358: mov w8, #5                      ; MonitorType::kBatteryLevel = 5
    //   0x005364: bl  #0x5794                     ; MonitorEvent::create(5, nullptr)
    //   0x005368: bl  #0x6ba8                     ; env_monitor_->endSection(event)
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kBatteryLevel), nullptr);
    return env_monitor_ ? env_monitor_->endSection(event) : 0.0;
}

double AndroidMonitor::Temperature() {
    // Disassembly @ 0x005390..0x0053d8:
    //   0x0053a4: mov w8, #6                      ; MonitorType::kBatteryTemperature = 6
    //   0x0053b0: bl  #0x5794                     ; MonitorEvent::create(6, nullptr)
    //   0x0053b4: bl  #0x6ba8                     ; env_monitor_->endSection(event)
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kBatteryTemperature), nullptr);
    return env_monitor_ ? env_monitor_->endSection(event) : 0.0;
}

double AndroidMonitor::AvailableMem() {
    // Disassembly @ 0x0053dc..0x005424:
    //   0x0053f0: mov w8, #3                      ; MonitorType::kAvailableMemory = 3
    //   0x0053fc: bl  #0x5794                     ; MonitorEvent::create(3, nullptr)
    //   0x005400: bl  #0x6ba8                     ; env_monitor_->endSection(event)
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kAvailableMemory), nullptr);
    return env_monitor_ ? env_monitor_->endSection(event) : 0.0;
}

std::shared_ptr<MonitorEvent> AndroidMonitor::monitorThreadCPUUsageBegin(int pid, int tid) {
    // Disassembly @ 0x005428..0x0054a4:
    //   0x005444: mov w8, #2                      ; MonitorType::kThreadCPUUsage = 2
    //   0x005450: mov w0, #0x28                   ; allocate 40 bytes for ThreadCPUParam
    //   0x005454: bl  operator new
    //   0x005460: str w20, [x0, #8]               ; param->pid = pid (+0x08)
    //   0x005464: str wzr, [x0, #32]              ; param->last_usage_pct = 0.0f (+0x20)
    //   0x005468: str w19, [x0, #12]              ; param->tid = tid (+0x0c)
    //   0x005484: bl  #0x5794                     ; MonitorEvent::create(2, param)
    //   0x00548c: bl  #0x6a78                     ; env_monitor_->beginSection(event)
    auto param = std::make_shared<ThreadCPUParam>(pid, tid);
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kThreadCPUUsage), param);
    if (env_monitor_) {
        env_monitor_->beginSection(event);
    }
    return event;
}

double AndroidMonitor::monitorThreadCPUUsageEnd(std::shared_ptr<MonitorEvent>& event) {
    // Disassembly @ 0x0054a8..0x0054ec:
    //   Checks event != nullptr, calls env_monitor_->endSection(event) @ 0x0054c8 (`bl #0x6ba8`)
    if (!event || !env_monitor_) {
        return 0.0;
    }
    return env_monitor_->endSection(event);
}

std::shared_ptr<MonitorEvent> AndroidMonitor::monitorProcessVMBegin(int pid) {
    // Disassembly @ 0x0054f0..0x005558:
    //   0x005508: mov w8, #7                      ; MonitorType::kProcessVMDelta = 7
    //   0x005514: mov w0, #0x20                   ; allocate 32 bytes for ProcessVMParam
    //   0x005518: bl  operator new
    //   0x005528: str w19, [x0, #8]               ; param->pid = pid (+0x08)
    //   0x005538: bl  #0x5794                     ; MonitorEvent::create(7, param)
    //   0x005540: bl  #0x6a78                     ; env_monitor_->beginSection(event)
    auto param = std::make_shared<ProcessVMParam>(pid);
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kProcessVMDelta), param);
    if (env_monitor_) {
        env_monitor_->beginSection(event);
    }
    return event;
}

double AndroidMonitor::monitorProcessVMEnd(std::shared_ptr<MonitorEvent>& event) {
    // Disassembly @ 0x00555c..0x0055ac:
    //   Checks event != nullptr, calls env_monitor_->endSection(event) @ 0x005584 (`bl #0x6ba8`)
    if (!event || !env_monitor_) {
        return 0.0;
    }
    return env_monitor_->endSection(event);
}

double AndroidMonitor::monitorProcessVMSize() {
    // Disassembly @ 0x0055b0..0x0055f8:
    //   0x0055c4: mov w8, #8                      ; MonitorType::kProcessVMSize = 8
    //   0x0055d0: bl  #0x5794                     ; MonitorEvent::create(8, nullptr)
    //   0x0055d4: bl  #0x6ba8                     ; env_monitor_->endSection(event)
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kProcessVMSize), nullptr);
    return env_monitor_ ? env_monitor_->endSection(event) : 0.0;
}

std::shared_ptr<MonitorEvent> AndroidMonitor::monitorProcessCPUUsage() {
    // Disassembly @ 0x0055fc..0x00566c:
    //   0x005614: mov w8, #9                      ; MonitorType::kProcessCPUUsage = 9
    //   0x005618: bl  #0x44c0                     ; getpid()
    //   0x005620: mov w0, #0x20                   ; allocate 32 bytes for ProcessVMParam
    //   0x005624: bl  operator new
    //   0x005638: str w19, [x0, #8]               ; param->pid = getpid() (+0x08)
    //   0x00564c: bl  #0x5794                     ; MonitorEvent::create(9, param)
    //   0x005654: bl  #0x6a78                     ; env_monitor_->beginSection(event)
    auto param = std::make_shared<ProcessVMParam>(currentProcessId());
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kProcessCPUUsage), param);
    if (env_monitor_) {
        env_monitor_->beginSection(event);
    }
    return event;
}

double AndroidMonitor::monitorProcessCPUUsageEnd(std::shared_ptr<MonitorEvent>& event) {
    // Disassembly @ 0x005670..0x0056c0:
    //   Checks event != nullptr, calls env_monitor_->endSection(event) @ 0x005698 (`bl #0x6ba8`)
    if (!event || !env_monitor_) {
        return 0.0;
    }
    return env_monitor_->endSection(event);
}

double AndroidMonitor::monitorBatteryElectricCurrent() {
    // Disassembly @ 0x0056c4..0x00570c:
    //   0x0056d8: mov w8, #0xa                    ; MonitorType::kBatteryElectricCurrent = 10 (0x0a)
    //   0x0056e4: bl  #0x5794                     ; MonitorEvent::create(10, nullptr)
    //   0x0056e8: bl  #0x6ba8                     ; env_monitor_->endSection(event)
    auto event = MonitorEvent::create(static_cast<int32_t>(MonitorType::kBatteryElectricCurrent), nullptr);
    return env_monitor_ ? env_monitor_->endSection(event) : 0.0;
}

void AndroidMonitor::dumpInfo(const std::string& tag) {
    // Disassembly @ 0x005710..0x00571c:
    //   0x005710: ldr x0, [x0, #8]                ; this->env_monitor_
    //   0x005714: cbz x0, #0x571c
    //   0x005718: b   #0x6ce4                     ; EnvMonitor::dumpInfo(tag)
    if (env_monitor_) {
        env_monitor_->dumpInfo(tag);
    }
}

} // namespace bytemonitor
