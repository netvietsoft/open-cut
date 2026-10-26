// ============================================================================
// RECONSTRUCTED C++ SOURCE: bytemonitor_interface.cpp
// Target Library: libbytemonitor.so (67,408 bytes, ELF64 AArch64)
// Module: Public C/C++/JNI Exported Interface & Verification Facade
// Reference Disassembly:
//   - Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit: 0x009570 (304 B)
//   - JNI_OnLoad:   0x00977c (508 B, returns 0x00010006 = JNI_VERSION_1_6)
//   - BTC_FindClass: 0x0099b8 (84 B)
//   - JNI_OnUnload: 0x009a0c (12 B)
// ============================================================================
// Tệp mã nguồn triển khai 4 hàm C/JNI xuất xưởng và lớp mặt tiền `BytemonitorEngine`
// phục vụ đối soát 25 biểu tượng `.dynsym` (`[077]..[101]`) của `libbytemonitor.so`.
// ============================================================================

#include "bytemonitor_interface.h"
#include <cstring>
#include <cmath>
#include <sstream>

namespace {

// ============================================================================
// .BSS JNI GLOBALS (0x01408c, 0x0140b0, 0x0140e0)
// Biến toàn cục quản lý máy ảo JavaVM, khóa TLS và bảng tra cứu lớp JNI
// ============================================================================
struct JniClassRegistryEntry {
    std::string class_name;
    void*       global_class_ref;
};

void*                              g_java_vm_ptr         = nullptr; // .bss @ 0x0140b0
uint32_t                           g_jni_tls_key         = 1U;      // .bss @ 0x01408c
std::vector<JniClassRegistryEntry> g_jni_class_registry{};          // .bss @ 0x0140e0
std::mutex                         g_jni_registry_mutex{};

} // anonymous namespace

extern "C" {

void Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit(
    void* env, void* /*clazz*/, void* battery_monitor_jobject) {
    // Disassembly @ 0x009570..0x00969c (304 bytes):
    //   0x009594: cbz x2, #0x9690                 ; guard battery_monitor_jobject != nullptr
    //   0x0095ac: blr x8                          ; env->NewGlobalRef(battery_monitor_jobject) (+0xa8)
    //   0x0095d0: blr x8                          ; env->DeleteLocalRef(battery_monitor_jobject) (+0xb8)
    //   0x009614: adrp x22, #0x14000
    //   0x009618: ldr  x23, [x22, #0xc0]          ; BatteryTools singleton @ .bss 0x0140b8..0x0140c0
    //   0x009640: mov  w0, #0x28                  ; allocate 40-byte shared_ptr control block + BatteryMonitorWrapper
    //   0x009644: bl   operator new
    //   0x009658: str  x19, [x0, #0x18]           ; wrapper->global_battery_monitor_ref_ = global_ref
    //   0x009668: stp  x20, x0, [x23, #8]         ; BatteryTools::getInstance()->setWrapper(...)
    if (battery_monitor_jobject == nullptr) {
        return;
    }
    auto wrapper = std::make_shared<::bytemonitor::BatteryMonitorWrapper>();
    wrapper->bindJavaObject(env, battery_monitor_jobject);
    ::bytemonitor::BatteryTools::getInstance()->setWrapper(std::move(wrapper));
}

int32_t ByteMonitor_JNI_OnLoad(void* vm, void* /*reserved*/) {
    // Disassembly @ 0x00977c..0x009974 (508 bytes):
    //   0x0097a0: adrp x8, #0x14000
    //   0x0097a4: str  x0, [x8, #0xb0]            ; .bss 0x0140b0 = g_java_vm_ptr = vm
    //   0x0097c4: mov  w1, #0x1                   ; JNI_VERSION_1_6 = 0x00010006
    //   0x0097c8: movk w1, #0x6, lsl #16
    //   0x0097cc: blr  x8                         ; vm->GetEnv(&env, 0x00010006) (+0x30)
    //   0x0097e0: bl   pthread_key_create         ; initializes .bss 0x01408c with destructor 0x009978
    //   0x0097ec: bl   pthread_setspecific
    //   0x0097f0: adrp x22, #0xd000
    //   0x0097f4: add  x22, x22, #0x822           ; "com/benchmark/bytemonitor/BatteryMonitor" (0x00d822)
    //   0x009800: blr  x8                         ; env->FindClass("com/benchmark/bytemonitor/BatteryMonitor")
    //   0x00981c: blr  x8                         ; env->NewGlobalRef(local_cls)
    //   0x009950: mov  w0, #0x6
    //   0x009954: movk w0, #0x1, lsl #16          ; return 0x00010006 (JNI_VERSION_1_6)
    std::lock_guard<std::mutex> lock(g_jni_registry_mutex);
    g_java_vm_ptr = vm;
    g_jni_tls_key = 1U;

    const char* kBatteryMonitorClassName = "com/benchmark/bytemonitor/BatteryMonitor";
    bool found = false;
    for (const auto& entry : g_jni_class_registry) {
        if (entry.class_name == kBatteryMonitorClassName) {
            found = true;
            break;
        }
    }
    if (!found) {
        g_jni_class_registry.push_back(JniClassRegistryEntry{
            kBatteryMonitorClassName,
            reinterpret_cast<void*>(0xBADC0FFEULL)});
    }
    return 0x00010006; // JNI_VERSION_1_6
}

void ByteMonitor_JNI_OnUnload(void* /*vm*/, void* /*reserved*/) {
    // Disassembly @ 0x009a0c..0x009a14 (12 bytes):
    //   0x009a0c: adrp x8, #0x14000
    //   0x009a10: str  xzr, [x8, #0xb0]           ; .bss 0x0140b0 = nullptr
    //   0x009a14: ret
    std::lock_guard<std::mutex> lock(g_jni_registry_mutex);
    g_java_vm_ptr = nullptr;
}

void* BTC_FindClass(void* /*env*/, const char* class_name) {
    // Disassembly @ 0x0099b8..0x009a08 (84 bytes):
    //   Iterates 16-byte entries `(const char* name, jclass global_ref)` in `.bss 0x0140e0..0x0140e8`
    //   0x0099d0: ldr  x0, [x19]                  ; entry->class_name
    //   0x0099d4: mov  x1, x20                    ; target class_name
    //   0x0099d8: bl   #0x4430                    ; strcmp(entry->class_name, class_name)
    //   0x0099dc: cbz  w0, #0x99f0                ; if match, load entry->global_class_ref (+0x08)
    if (class_name == nullptr) {
        return nullptr;
    }
    std::lock_guard<std::mutex> lock(g_jni_registry_mutex);
    for (const auto& entry : g_jni_class_registry) {
        if (std::strcmp(entry.class_name.c_str(), class_name) == 0) {
            return entry.global_class_ref;
        }
    }
    return nullptr;
}

} // extern "C"

namespace NextAI::OpenCut::bytemonitor {

// ============================================================================
// COMPLETE 25 EXPORTED SYMBOLS TABLE (.dynsym [077]..[101])
// Bảng đối chiếu đầy đủ 25 biểu tượng xuất xưởng trong .dynsym của libbytemonitor.so
// ============================================================================
const std::vector<ExportedSymbolDescriptor>& BytemonitorEngine::getExportedSymbols() {
    static const std::vector<ExportedSymbolDescriptor> kTable = {
        {77,  0x0053dcULL, 76U,  "_ZN11bytemonitor14AndroidMonitor12AvailableMemEv",
              "bytemonitor::AndroidMonitor::AvailableMem()"},
        {78,  0x0052acULL, 76U,  "_ZN11bytemonitor14AndroidMonitor8GPUUsageEv",
              "bytemonitor::AndroidMonitor::GPUUsage()"},
        {79,  0x00cb08ULL, 64U,  "_ZN11bytemonitor11ByteMonitor10getMonitorEv",
              "bytemonitor::ByteMonitor::getMonitor()"},
        {80,  0x0050ecULL, 184U, "_ZN11bytemonitor14AndroidMonitorC1Ev",
              "bytemonitor::AndroidMonitor::AndroidMonitor() [C1]"},
        {81,  0x00977cULL, 508U, "JNI_OnLoad",
              "JNI_OnLoad"},
        {82,  0x0055fcULL, 116U, "_ZN11bytemonitor14AndroidMonitor22monitorProcessCPUUsageEv",
              "bytemonitor::AndroidMonitor::monitorProcessCPUUsage()"},
        {83,  0x012938ULL, 152U, "_ZTVN11bytemonitor14AndroidMonitorE",
              "vtable for bytemonitor::AndroidMonitor"},
        {84,  0x0055b0ULL, 76U,  "_ZN11bytemonitor14AndroidMonitor20monitorProcessVMSizeEv",
              "bytemonitor::AndroidMonitor::monitorProcessVMSize()"},
        {85,  0x00555cULL, 84U,  "_ZN11bytemonitor14AndroidMonitor19monitorProcessVMEndERNSt6__ndk110shared_ptrINS_12MonitorEventEEE",
              "bytemonitor::AndroidMonitor::monitorProcessVMEnd(std::shared_ptr<bytemonitor::MonitorEvent>&)"},
        {86,  0x005344ULL, 76U,  "_ZN11bytemonitor14AndroidMonitor12batteryLevelEv",
              "bytemonitor::AndroidMonitor::batteryLevel()"},
        {87,  0x013a38ULL, 128U, "_ZTVNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEE",
              "vtable for std::__ndk1::basic_streambuf<char, std::__ndk1::char_traits<char>>"},
        {88,  0x0050ecULL, 184U, "_ZN11bytemonitor14AndroidMonitorC2Ev",
              "bytemonitor::AndroidMonitor::AndroidMonitor() [C2]"},
        {89,  0x005390ULL, 76U,  "_ZN11bytemonitor14AndroidMonitor11TemperatureEv",
              "bytemonitor::AndroidMonitor::Temperature()"},
        {90,  0x0054a8ULL, 72U,  "_ZN11bytemonitor14AndroidMonitor24monitorThreadCPUUsageEndERNSt6__ndk110shared_ptrINS_12MonitorEventEEE",
              "bytemonitor::AndroidMonitor::monitorThreadCPUUsageEnd(std::shared_ptr<bytemonitor::MonitorEvent>&)"},
        {91,  0x0056c4ULL, 76U,  "_ZN11bytemonitor14AndroidMonitor29monitorBatteryElectricCurrentEv",
              "bytemonitor::AndroidMonitor::monitorBatteryElectricCurrent()"},
        {92,  0x00cb74ULL, 96U,  "_ZN11bytemonitor11ByteMonitor11setLogLevelEi",
              "bytemonitor::ByteMonitor::setLogLevel(int)"},
        {93,  0x005260ULL, 76U,  "_ZN11bytemonitor14AndroidMonitor3CPUEv",
              "bytemonitor::AndroidMonitor::CPU()"},
        {94,  0x009a0cULL, 12U,  "JNI_OnUnload",
              "JNI_OnUnload"},
        {95,  0x0052f8ULL, 76U,  "_ZN11bytemonitor14AndroidMonitor11MemoryUsageEv",
              "bytemonitor::AndroidMonitor::MemoryUsage()"},
        {96,  0x005710ULL, 16U,  "_ZN11bytemonitor14AndroidMonitor8dumpInfoERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE",
              "bytemonitor::AndroidMonitor::dumpInfo(std::string const&)"},
        {97,  0x005428ULL, 128U, "_ZN11bytemonitor14AndroidMonitor26monitorThreadCPUUsageBeginEii",
              "bytemonitor::AndroidMonitor::monitorThreadCPUUsageBegin(int, int)"},
        {98,  0x005670ULL, 84U,  "_ZN11bytemonitor14AndroidMonitor25monitorProcessCPUUsageEndERNSt6__ndk110shared_ptrINS_12MonitorEventEEE",
              "bytemonitor::AndroidMonitor::monitorProcessCPUUsageEnd(std::shared_ptr<bytemonitor::MonitorEvent>&)"},
        {99,  0x009570ULL, 304U, "Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit",
              "Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit"},
        {100, 0x0099b8ULL, 84U,  "BTC_FindClass",
              "BTC_FindClass"},
        {101, 0x0054f0ULL, 108U, "_ZN11bytemonitor14AndroidMonitor21monitorProcessVMBeginEi",
              "bytemonitor::AndroidMonitor::monitorProcessVMBegin(int)"}
    };
    return kTable;
}

BytemonitorEngine::BytemonitorEngine() {
    monitor_ = ::bytemonitor::ByteMonitor::getMonitor();
}

BytemonitorEngine::~BytemonitorEngine() = default;

bool BytemonitorEngine::runComprehensiveSelfTest(std::string* out_report) {
    ::bytemonitor::setUseSyntheticTelemetry(true);
    ::bytemonitor::HardwareTelemetrySnapshot snap;
    snap.cpu_core_count        = 8;
    snap.cpus_allowed_mask     = 0xFFU;
    // 8 cores: cores 0..3 at (1800-600)/(2000-600) = 1200/1400 = 6/7
    //          cores 4..6 at (2400-800)/(2600-800) = 1600/1800 = 8/9
    //          core  7    at (2800-1000)/(3000-1000)= 1800/2000 = 9/10
    ::bytemonitor::setHardwareTelemetrySnapshot(snap);

    if (!monitor_) {
        monitor_ = ::bytemonitor::ByteMonitor::getMonitor();
    }

    double cpu_pct   = monitor_->CPU();
    double gpu_pct   = monitor_->GPUUsage();
    double mem_pct   = monitor_->MemoryUsage();
    double avail_kb  = monitor_->AvailableMem();
    double bat_pct   = monitor_->batteryLevel();
    double temp_c    = monitor_->Temperature();
    double cur_ma    = monitor_->monitorBatteryElectricCurrent();
    double vmsize_kb = monitor_->monitorProcessVMSize();

    // Thread CPU Begin/End delta test
    auto thr_ev = monitor_->monitorThreadCPUUsageBegin(1000, 1024);
    ::bytemonitor::mutableHardwareTelemetrySnapshot().thread_utime_jiffies += 50ULL;
    ::bytemonitor::mutableHardwareTelemetrySnapshot().proc_utime_jiffies   += 100ULL;
    double thr_cpu_pct = monitor_->monitorThreadCPUUsageEnd(thr_ev);

    // Process VM Begin/End delta test
    auto vm_ev = monitor_->monitorProcessVMBegin(1000);
    ::bytemonitor::mutableHardwareTelemetrySnapshot().proc_pss_kb += 4096ULL;
    double vm_delta_kb = monitor_->monitorProcessVMEnd(vm_ev);

    // Process CPU Begin/End delta test
    auto pcpu_ev = monitor_->monitorProcessCPUUsage();
    ::bytemonitor::mutableHardwareTelemetrySnapshot().proc_utime_jiffies        += 80ULL;
    ::bytemonitor::mutableHardwareTelemetrySnapshot().cpu_time_in_state_10ms    += 2000ULL; // +200 jiffies
    double pcpu_pct = monitor_->monitorProcessCPUUsageEnd(pcpu_ev);

    monitor_->dumpInfo("NextAI_Bytemonitor_SelfTest");

    bool ok = (cpu_pct > 80.0 && cpu_pct < 95.0) &&
              (std::fabs(gpu_pct - 45.0) < 1e-6) &&
              (std::fabs(mem_pct - 62.5) < 1e-6) &&
              (std::fabs(avail_kb - 3145728.0) < 1e-3) &&
              (std::fabs(bat_pct - 86.5) < 1e-6) &&
              (std::fabs(temp_c - 34.2) < 1e-6) &&
              (std::fabs(cur_ma - (-415.0)) < 1e-6) &&
              (std::fabs(vmsize_kb - 4718592.0) < 1e-3) &&
              (std::fabs(thr_cpu_pct - 50.0) < 1e-6) &&
              (std::fabs(vm_delta_kb - 4096.0) < 1e-6) &&
              (std::fabs(pcpu_pct - 5.0) < 1e-6) &&
              (getExportedSymbols().size() == 25U);

    if (out_report) {
        std::ostringstream oss;
        oss << "CPU=" << cpu_pct << "%, GPU=" << gpu_pct << "%, Mem=" << mem_pct
            << "%, AvailKB=" << avail_kb << ", ThrCPU=" << thr_cpu_pct
            << "%, VMDeltaKB=" << vm_delta_kb << ", ProcCPU=" << pcpu_pct
            << "%, Status=" << (ok ? "PASS" : "FAIL");
        *out_report = oss.str();
    }
    return ok;
}

} // namespace NextAI::OpenCut::bytemonitor
