// ============================================================================
// RECONSTRUCTED C++ HEADER: bytemonitor_types.h
// Target Library: libbytemonitor.so (67,408 bytes, ELF64 AArch64)
// Module: ByteDance / ByteBench Hardware & Process Resource Monitor Types & ABI
// Reference Evidence:
//   - .text:         vaddr 0x004ed0 .. 0x00d560 (size 0x008690 = 34,448 bytes)
//   - .rodata:       vaddr 0x00d560 .. 0x00dc41 (size 0x0006e1 = 1,761 bytes)
//   - .init_array:   vaddr 0x0128f0 .. 0x012920 (size 0x000030 = 48 bytes, 6 ctors)
//   - .data.rel.ro:  vaddr 0x012930 .. 0x013b90 (size 0x001260 = 4,704 bytes)
//   - .data:         vaddr 0x014000 .. 0x014004 (size 0x000004 = 4 bytes)
//   - .bss:          vaddr 0x014010 .. 0x014150 (size 0x000140 = 320 bytes)
// ============================================================================
// Tệp tiêu đề định nghĩa cấu trúc ABI, hằng số ELF64, địa chỉ opcodes AArch64,
// bảng phương thức ảo (vtable) và kiểu dữ liệu lõi của thư viện giám sát tài nguyên
// phần cứng ByteBench (CPU, GPU, Memory, Battery, Temperature) trong libbytemonitor.so.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <functional>

namespace bytemonitor {

// ============================================================================
// 1. ELF64 BINARY GEOMETRY & SECTION LAYOUT CONSTANTS
// Hằng số cấu trúc phân đoạn nhị phân ELF64 của libbytemonitor.so (67,408 bytes)
// ============================================================================
struct Elf64Geometry {
    static constexpr uint64_t kFileSizeBytes         = 67408ULL;   // 0x010750 bytes
    static constexpr uint32_t kDynsymTotalEntries    = 102U;       // [000]..[101] in .dynsym (0x000238)
    static constexpr uint32_t kImportedSymbolCount   = 76U;        // [001]..[076] UND imports
    static constexpr uint32_t kExportedSymbolCount   = 25U;        // [077]..[101] defined exports

    // Section virtual addresses / Địa chỉ ảo các phân đoạn ELF64
    static constexpr uint64_t kSecDynsymVaddr        = 0x000238ULL; // size 0x000990 (2,448 B)
    static constexpr uint64_t kSecDynstrVaddr        = 0x000bc8ULL; // size 0x000baf (2,991 B)
    static constexpr uint64_t kSecRelaDynVaddr       = 0x0018a0ULL; // size 0x002058 (8,280 B)
    static constexpr uint64_t kSecRelaPltVaddr       = 0x0038f8ULL; // size 0x000750 (1,872 B)
    static constexpr uint64_t kSecPltVaddr           = 0x004050ULL; // size 0x0004f0 (1,264 B)
    static constexpr uint64_t kSecTextVaddr          = 0x004ed0ULL; // size 0x008690 (34,448 B)
    static constexpr uint64_t kSecTextEndVaddr       = 0x00d560ULL;
    static constexpr uint64_t kSecRodataVaddr        = 0x00d560ULL; // size 0x0006e1 (1,761 B)
    static constexpr uint64_t kSecRodataEndVaddr     = 0x00dc41ULL;
    static constexpr uint64_t kSecEhFrameHdrVaddr    = 0x00dc44ULL; // size 0x000428 (1,064 B)
    static constexpr uint64_t kSecEhFrameVaddr       = 0x00e070ULL; // size 0x001ae0 (6,880 B)
    static constexpr uint64_t kSecGccExceptTableVaddr= 0x00fb50ULL; // size 0x0009ec (2,540 B)
    static constexpr uint64_t kSecInitArrayVaddr     = 0x0128f0ULL; // size 0x000030 (48 B, 6 ctors)
    static constexpr uint64_t kSecFiniArrayVaddr     = 0x012920ULL; // size 0x000010 (16 B)
    static constexpr uint64_t kSecDataRelRoVaddr     = 0x012930ULL; // size 0x001260 (4,704 B)
    static constexpr uint64_t kSecDynamicVaddr       = 0x013b90ULL; // size 0x000200 (512 B)
    static constexpr uint64_t kSecGotVaddr           = 0x013d90ULL; // size 0x000270 (624 B)
    static constexpr uint64_t kSecDataVaddr          = 0x014000ULL; // size 0x000004 (4 B)
    static constexpr uint64_t kSecBssVaddr           = 0x014010ULL; // size 0x000140 (320 B)
    static constexpr uint64_t kSecBssEndVaddr        = 0x014150ULL;
};

// ============================================================================
// 2. EXPORTED SYMBOL VIRTUAL ADDRESSES (.dynsym [077]..[101])
// Địa chỉ ảo chính xác của toàn bộ 25 biểu tượng xuất xưởng (.dynsym [077]..[101])
// ============================================================================
struct ExportedSymbolVaddrs {
    // [077] bytemonitor::AndroidMonitor::AvailableMem()
    static constexpr uint64_t kAndroidMonitor_AvailableMem                 = 0x0053dcULL; // size 76 B
    // [078] bytemonitor::AndroidMonitor::GPUUsage()
    static constexpr uint64_t kAndroidMonitor_GPUUsage                     = 0x0052acULL; // size 76 B
    // [079] bytemonitor::ByteMonitor::getMonitor()
    static constexpr uint64_t kByteMonitor_getMonitor                      = 0x00cb08ULL; // size 64 B
    // [080] bytemonitor::AndroidMonitor::AndroidMonitor() [C1Ev]
    static constexpr uint64_t kAndroidMonitor_C1Ev                         = 0x0050ecULL; // size 184 B
    // [081] JNI_OnLoad
    static constexpr uint64_t kJNI_OnLoad                                  = 0x00977cULL; // size 508 B
    // [082] bytemonitor::AndroidMonitor::monitorProcessCPUUsage()
    static constexpr uint64_t kAndroidMonitor_monitorProcessCPUUsage       = 0x0055fcULL; // size 116 B
    // [083] vtable for bytemonitor::AndroidMonitor (_ZTVN11bytemonitor14AndroidMonitorE)
    static constexpr uint64_t kVtable_AndroidMonitor                       = 0x012938ULL; // size 152 B
    // [084] bytemonitor::AndroidMonitor::monitorProcessVMSize()
    static constexpr uint64_t kAndroidMonitor_monitorProcessVMSize         = 0x0055b0ULL; // size 76 B
    // [085] bytemonitor::AndroidMonitor::monitorProcessVMEnd(std::shared_ptr<MonitorEvent>&)
    static constexpr uint64_t kAndroidMonitor_monitorProcessVMEnd          = 0x00555cULL; // size 84 B
    // [086] bytemonitor::AndroidMonitor::batteryLevel()
    static constexpr uint64_t kAndroidMonitor_batteryLevel                 = 0x005344ULL; // size 76 B
    // [087] vtable for std::__ndk1::basic_streambuf<char, std::__ndk1::char_traits<char>>
    static constexpr uint64_t kVtable_BasicStreambuf                       = 0x013a38ULL; // size 128 B
    // [088] bytemonitor::AndroidMonitor::AndroidMonitor() [C2Ev]
    static constexpr uint64_t kAndroidMonitor_C2Ev                         = 0x0050ecULL; // size 184 B
    // [089] bytemonitor::AndroidMonitor::Temperature()
    static constexpr uint64_t kAndroidMonitor_Temperature                  = 0x005390ULL; // size 76 B
    // [090] bytemonitor::AndroidMonitor::monitorThreadCPUUsageEnd(std::shared_ptr<MonitorEvent>&)
    static constexpr uint64_t kAndroidMonitor_monitorThreadCPUUsageEnd     = 0x0054a8ULL; // size 72 B
    // [091] bytemonitor::AndroidMonitor::monitorBatteryElectricCurrent()
    static constexpr uint64_t kAndroidMonitor_monitorBatteryElectricCurrent= 0x0056c4ULL; // size 76 B
    // [092] bytemonitor::ByteMonitor::setLogLevel(int)
    static constexpr uint64_t kByteMonitor_setLogLevel                     = 0x00cb74ULL; // size 96 B
    // [093] bytemonitor::AndroidMonitor::CPU()
    static constexpr uint64_t kAndroidMonitor_CPU                          = 0x005260ULL; // size 76 B
    // [094] JNI_OnUnload
    static constexpr uint64_t kJNI_OnUnload                                = 0x009a0cULL; // size 12 B
    // [095] bytemonitor::AndroidMonitor::MemoryUsage()
    static constexpr uint64_t kAndroidMonitor_MemoryUsage                  = 0x0052f8ULL; // size 76 B
    // [096] bytemonitor::AndroidMonitor::dumpInfo(std::string const&)
    static constexpr uint64_t kAndroidMonitor_dumpInfo                     = 0x005710ULL; // size 16 B
    // [097] bytemonitor::AndroidMonitor::monitorThreadCPUUsageBegin(int, int)
    static constexpr uint64_t kAndroidMonitor_monitorThreadCPUUsageBegin   = 0x005428ULL; // size 128 B
    // [098] bytemonitor::AndroidMonitor::monitorProcessCPUUsageEnd(std::shared_ptr<MonitorEvent>&)
    static constexpr uint64_t kAndroidMonitor_monitorProcessCPUUsageEnd    = 0x005670ULL; // size 84 B
    // [099] Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit
    static constexpr uint64_t kJNI_ByteMonitorPort_nativeInit              = 0x009570ULL; // size 304 B
    // [100] BTC_FindClass
    static constexpr uint64_t kBTC_FindClass                               = 0x0099b8ULL; // size 84 B
    // [101] bytemonitor::AndroidMonitor::monitorProcessVMBegin(int)
    static constexpr uint64_t kAndroidMonitor_monitorProcessVMBegin        = 0x0054f0ULL; // size 108 B
};

// ============================================================================
// 3. INTERNAL .TEXT SUBROUTINE & .BSS / .DATA / .RODATA OFFSETS
// Địa chỉ hàm nội bộ trong .text và biến toàn cục trong .data / .bss / .rodata
// ============================================================================
struct InternalSymbolVaddrs {
    // .init_array static constructors (0x0128f0..0x012918)
    static constexpr uint64_t kInitCtor_0_OnceFlagAndBatteryPtr = 0x004ed0ULL;
    static constexpr uint64_t kInitCtor_1_CpuOnlineBitset       = 0x004f1cULL;
    static constexpr uint64_t kInitCtor_2_BatteryToolsPtr       = 0x004f50ULL;
    static constexpr uint64_t kInitCtor_3_GpuSysfsPathString    = 0x004f6cULL;
    static constexpr uint64_t kInitCtor_4_JniClassRegistry      = 0x004f90ULL;
    static constexpr uint64_t kInitCtor_5_SysconfCpuCountInit   = 0x004fecULL;
    static constexpr uint64_t kSub_SysconfNprocessorsInit       = 0x005000ULL;

    // EnvMonitor & AndroidMonitor internal methods
    static constexpr uint64_t kEnvMonitor_Init                  = 0x005888ULL; // registers 11 MonitorTypes
    static constexpr uint64_t kEnvMonitor_BeginSection          = 0x006a78ULL; // lookup + vcall +0x60
    static constexpr uint64_t kEnvMonitor_EndSection            = 0x006ba8ULL; // lookup + vcall +0x80
    static constexpr uint64_t kEnvMonitor_GetInstance           = 0x006fa0ULL; // allocates 0x48 bytes
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_1_CPU = 0x007098ULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_11_GPU= 0x007168ULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_4_Mem = 0x007234ULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_3_Avl = 0x007300ULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_5_Bat = 0x0073ccULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_6_Tmp = 0x007498ULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_2_Thr = 0x007564ULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_7_PVM = 0x007638ULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_8_VMS = 0x00770cULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_9_PCP = 0x0077d8ULL; // alloc 0x110 (272 B)
    static constexpr uint64_t kEnvMonitor_RegisterMonitor_10_Cur= 0x0078a4ULL; // alloc 0x110 (272 B)

    // MonitorType concrete metric lambdas (0x008af8..0x009060)
    static constexpr uint64_t kLambda_Type1_CPUUsage            = 0x008af8ULL; // * 100.0 (0x4059000000000000)
    static constexpr uint64_t kLambda_Type11_GPUUsage           = 0x008b4cULL;
    static constexpr uint64_t kLambda_Type4_MemoryUsage         = 0x008b8cULL;
    static constexpr uint64_t kLambda_Type3_AvailableMem        = 0x008bc4ULL;
    static constexpr uint64_t kLambda_Type5_BatteryLevel        = 0x008bfcULL;
    static constexpr uint64_t kLambda_Type6_Temperature         = 0x008c28ULL;
    static constexpr uint64_t kLambda_Type2_ThreadCPUBegin      = 0x008c54ULL;
    static constexpr uint64_t kLambda_Type2_ThreadCPUEnd        = 0x008cbcULL;
    static constexpr uint64_t kLambda_Type7_ProcessVMBegin      = 0x008db0ULL;
    static constexpr uint64_t kLambda_Type7_ProcessVMEnd        = 0x008decULL;
    static constexpr uint64_t kLambda_Type8_ProcessVMSize       = 0x008e74ULL;
    static constexpr uint64_t kLambda_Type9_ProcessCPUBegin     = 0x008ea4ULL;
    static constexpr uint64_t kLambda_Type9_ProcessCPUEnd       = 0x008efcULL;
    static constexpr uint64_t kLambda_Type10_BatteryCurrent     = 0x008ffcULL;

    // CPUTools, GPUTools, MemoryTools, BatteryTools subroutines
    static constexpr uint64_t kCPUTools_ReadCpuTimeInState      = 0x009064ULL;
    static constexpr uint64_t kCPUTools_ReadThreadStatJiffies   = 0x0091c8ULL;
    static constexpr uint64_t kCPUTools_ReadProcessStatJiffies  = 0x0092a4ULL;
    static constexpr uint64_t kBatteryTools_GetBatteryLevel     = 0x009a18ULL;
    static constexpr uint64_t kBatteryTools_GetTemperature      = 0x009ce4ULL;
    static constexpr uint64_t kBatteryTools_GetElectricCurrent  = 0x009fb8ULL;
    static constexpr uint64_t kCPUTools_UpdateOnlineCores       = 0x00b6acULL;
    static constexpr uint64_t kCPUTools_GetNormalizedCpuFreqUsage = 0x00bb04ULL;
    static constexpr uint64_t kCPUTools_ParseProcStatFields     = 0x00bde8ULL;
    static constexpr uint64_t kGPUTools_GetGpuUsage             = 0x00c054ULL;
    static constexpr uint64_t kMemoryTools_GetProcessPssKb      = 0x00c4e8ULL;
    static constexpr uint64_t kMemoryTools_GetSystemMemUsagePct = 0x00c684ULL;
    static constexpr uint64_t kMemoryTools_GetAvailableMemKb    = 0x00c7fcULL;
    static constexpr uint64_t kMemoryTools_GetProcessVmSizeKb   = 0x00c9f4ULL;

    // .data & .bss global variable addresses
    static constexpr uint64_t kData_LogLevel                    = 0x014000ULL; // int32_t (default 8)
    static constexpr uint64_t kBss_EnvMonitorInitOnceFlag       = 0x014010ULL; // std::once_flag
    static constexpr uint64_t kBss_CpuCoreCount                 = 0x014050ULL; // uint64_t sysconf(96)
    static constexpr uint64_t kBss_BatteryWrapperSharedPtr      = 0x014060ULL; // shared_ptr<BatteryMonitorWrapper>
    static constexpr uint64_t kBss_OnlineCpuBitVector           = 0x014070ULL; // std::vector<bool> (24 B)
    static constexpr uint64_t kBss_GpuNotSupportedFlag          = 0x014088ULL; // bool
    static constexpr uint64_t kBss_JniEnvTlsKey                 = 0x01408cULL; // pthread_key_t
    static constexpr uint64_t kBss_EnvMonitorInstancePtr        = 0x014098ULL; // EnvMonitor*
    static constexpr uint64_t kBss_AndroidMonitorSingleton      = 0x0140a0ULL; // shared_ptr<ByteMonitor>
    static constexpr uint64_t kBss_JavaVMInstance               = 0x0140b0ULL; // JavaVM*
    static constexpr uint64_t kBss_BatteryToolsInstance         = 0x0140b8ULL; // BatteryTools*
    static constexpr uint64_t kBss_CachedGpuSysfsPath           = 0x0140c8ULL; // std::string (24 B)
    static constexpr uint64_t kBss_JniClassRegistryVector       = 0x0140e0ULL; // std::vector<ClassEntry>
    static constexpr uint64_t kBss_GlobalMonitorMutex           = 0x014100ULL; // std::mutex (40 B)
};

// ============================================================================
// 4. MONITOR TYPE ENUMERATION (1..11)
// Định danh 11 loại chỉ số giám sát phần cứng & tiến trình trong EnvMonitor
// Quan sát trực tiếp tại AndroidMonitor (0x005260..0x0056c4) & EnvMonitor::init (0x005888)
// ============================================================================
enum class MonitorType : int32_t {
    kUnknown                       = 0,
    kCPUUsage                      = 1,  // AndroidMonitor::CPU() @ 0x005260 (w8 = 1)
    kThreadCPUUsage                = 2,  // AndroidMonitor::monitorThreadCPUUsageBegin @ 0x005428 (w8 = 2)
    kAvailableMemory               = 3,  // AndroidMonitor::AvailableMem() @ 0x0053dc (w8 = 3)
    kMemoryUsage                   = 4,  // AndroidMonitor::MemoryUsage() @ 0x0052f8 (w8 = 4)
    kBatteryLevel                  = 5,  // AndroidMonitor::batteryLevel() @ 0x005344 (w8 = 5)
    kBatteryTemperature            = 6,  // AndroidMonitor::Temperature() @ 0x005390 (w8 = 6)
    kProcessVMDelta                = 7,  // AndroidMonitor::monitorProcessVMBegin @ 0x0054f0 (w8 = 7)
    kProcessVMSize                 = 8,  // AndroidMonitor::monitorProcessVMSize() @ 0x0055b0 (w8 = 8)
    kProcessCPUUsage               = 9,  // AndroidMonitor::monitorProcessCPUUsage() @ 0x0055fc (w8 = 9)
    kBatteryElectricCurrent        = 10, // AndroidMonitor::monitorBatteryElectricCurrent @ 0x0056c4 (w8 = 0x0a)
    kGPUUsage                      = 11  // AndroidMonitor::GPUUsage() @ 0x0052ac (w8 = 0x0b)
};

// ============================================================================
// 5. EVENT PARAMETER HIERARCHY (NoneEventParam, ThreadCPUParam, ProcessVMParam)
// Hệ thống lớp tham số sự kiện đo lường (khớp vtable tại 0x012a00..0x012a40)
// ============================================================================

/**
 * @brief Base polymorphic parameter for MonitorEvent.
 * Lớp cơ sở đa hình cho tham số sự kiện đo lường (vtable tại 0x012a40, kích thước 8 bytes).
 */
struct NoneEventParam {
    static constexpr uint64_t kVtableVaddr = 0x012a40ULL;

    NoneEventParam() = default;
    virtual ~NoneEventParam() = default;
};

/**
 * @brief Event parameter for Thread CPU Usage monitoring (MonitorType::kThreadCPUUsage = 2).
 * Tham số đo lường CPU theo luồng (Thread CPU Usage):
 * - Cấp phát tại `0x005450`: `mov w0, #0x28; bl operator new` (40 bytes aligned, 36 bytes active)
 * - Bố cục bộ nhớ ABI:
 *   +0x00: vptr (`0x012a20 + 0x10 = 0x012a30`)
 *   +0x08: `int32_t pid` (`str w20, [x0, #8]` tại `0x005460`)
 *   +0x0c: `int32_t tid` (`str w19, [x0, #12]` tại `0x005468`)
 *   +0x10: `double start_thread_jiffies` (`str d0, [x20, #16]` tại `0x008c90`)
 *   +0x18: `double start_proc_jiffies` (`str d0, [x20, #24]` tại `0x008ca0`)
 *   +0x20: `float last_usage_pct` (`str wzr, [x0, #32]` tại `0x005464`)
 */
struct ThreadCPUParam : public NoneEventParam {
    static constexpr uint64_t kVtableVaddr = 0x012a20ULL;
    static constexpr size_t   kAbiSize     = 40U; // 0x28 bytes allocated at 0x005450

    int32_t pid{0};                  // +0x08: Process ID
    int32_t tid{0};                  // +0x0c: Thread ID
    double  start_thread_jiffies{0}; // +0x10: Initial utime+stime+cutime+cstime from /proc/<pid>/task/<tid>/stat
    double  start_proc_jiffies{0};   // +0x18: Initial utime+stime+cutime+cstime from /proc/<pid>/stat
    float   last_usage_pct{0.0f};    // +0x20: Last computed thread CPU percentage

    ThreadCPUParam(int32_t p, int32_t t)
        : pid(p), tid(t), start_thread_jiffies(0.0), start_proc_jiffies(0.0), last_usage_pct(0.0f) {}
    ~ThreadCPUParam() override = default;
};

/**
 * @brief Event parameter for Process VM & Process CPU monitoring (MonitorType 7 and 9).
 * Tham số đo lường Bộ nhớ ảo (PSS) và CPU của tiến trình:
 * - Cấp phát tại `0x005514` và `0x00561c`: `mov w0, #0x20; bl operator new` (32 bytes = 0x20)
 * - Bố cục bộ nhớ ABI:
 *   +0x00: vptr (`0x012a00 + 0x10 = 0x012a10`)
 *   +0x08: `int32_t pid` (`str w19, [x0, #8]` tại `0x005528`)
 *   +0x0c: `int32_t reserved_pad`
 *   +0x10: `double baseline_metric_primary` (`str d0, [x19, #16]` tại `0x008dd0` / `0x008ed8`: PSS KB hoặc Process Jiffies)
 *   +0x18: `double baseline_metric_secondary` (`str d0, [x19, #24]` tại `0x008ee8`: CPU time_in_state Jiffies)
 */
struct ProcessVMParam : public NoneEventParam {
    static constexpr uint64_t kVtableVaddr = 0x012a00ULL;
    static constexpr size_t   kAbiSize     = 32U; // 0x20 bytes allocated at 0x005514 / 0x00561c

    int32_t pid{0};                        // +0x08: Target Process ID (or getpid() for Type 9)
    int32_t reserved_pad{0};               // +0x0c: Alignment padding
    double  baseline_metric_primary{0.0};  // +0x10: Initial PSS (KB) for Type 7, or Proc Jiffies for Type 9
    double  baseline_metric_secondary{0.0};// +0x18: Initial CPU time_in_state (10ms units) for Type 9

    explicit ProcessVMParam(int32_t p)
        : pid(p), reserved_pad(0), baseline_metric_primary(0.0), baseline_metric_secondary(0.0) {}
    ~ProcessVMParam() override = default;
};

// ============================================================================
// 6. MONITOR EVENT & MONITOR IMPL ABI STRUCTURES
// Cấu trúc sự kiện MonitorEvent và bộ thực thi MonitorImpl (272 bytes = 0x110)
// ============================================================================

/**
 * @brief Event handle returned by beginSection and consumed by endSection.
 * Cấu trúc sự kiện giám sát:
 * - Cấp phát control block + payload 40 bytes (`0x28`) tại `0x0057ac`:
 *   +0x00 (in MonitorEvent payload): `int32_t monitor_type` (MonitorType 1..11)
 *   +0x08 (in MonitorEvent payload): `std::shared_ptr<NoneEventParam> param` (16 bytes: ptr + cntrl)
 */
struct MonitorEvent {
    int32_t                         monitor_type{0}; // +0x00: MonitorType (1..11)
    int32_t                         padding{0};      // +0x04: 8-byte alignment
    std::shared_ptr<NoneEventParam> param{nullptr};  // +0x08..+0x17: Shared pointer to NoneEventParam subclass

    MonitorEvent() = default;
    MonitorEvent(int32_t type, std::shared_ptr<NoneEventParam> p)
        : monitor_type(type), padding(0), param(std::move(p)) {}

    static std::shared_ptr<MonitorEvent> create(int32_t type, std::shared_ptr<NoneEventParam> p = nullptr) {
        return std::make_shared<MonitorEvent>(type, std::move(p));
    }
};

/**
 * @brief Internal 272-byte (0x110) Monitor Handler registered in EnvMonitor::init().
 * Bộ thực thi từng loại MonitorType trong EnvMonitor:
 * - Cấp phát tại `0x0070bc`, `0x00718c`, ..., `0x0078c8`: `mov w0, #0x110; bl operator new`
 * - Bố cục ABI 272 bytes (`0x110`):
 *   +0x00: `void* vptr` (`0x012a90 + 0x10 = 0x012aa0`)
 *   +0x08..+0x2f: `std::mutex monitor_mutex` (40 bytes)
 *   +0x30: `int32_t monitor_type`
 *   +0x34: `int32_t state_flags`
 *   +0x38..+0x5f: `std::string monitor_name` (24 bytes + padding)
 *   +0x60..+0x7f: `std::function<void(std::shared_ptr<MonitorEvent>&)> begin_callback` (32 bytes)
 *   +0x80..+0x9f: `std::function<double(std::shared_ptr<MonitorEvent>&)> end_callback` (32 bytes)
 *   +0xa0..+0x10f: Statistical accumulator & history ring buffer (112 bytes)
 */
struct MonitorImpl {
    static constexpr size_t   kAbiSize     = 272U; // 0x110 bytes
    static constexpr uint64_t kVtableVaddr = 0x012a90ULL;

    MonitorType                                         type{MonitorType::kUnknown};
    std::string                                         name{};
    std::mutex                                          mutex{};
    std::function<void(std::shared_ptr<MonitorEvent>&)> begin_fn{};
    std::function<double(std::shared_ptr<MonitorEvent>&)> end_fn{};
    uint64_t                                            sample_count{0};
    double                                              last_value{0.0};
    double                                              accumulated_value{0.0};
    uint8_t                                             abi_reserved[112]{};

    MonitorImpl() = default;
    MonitorImpl(MonitorType t,
                std::string n,
                std::function<void(std::shared_ptr<MonitorEvent>&)> b_fn,
                std::function<double(std::shared_ptr<MonitorEvent>&)> e_fn)
        : type(t),
          name(std::move(n)),
          begin_fn(std::move(b_fn)),
          end_fn(std::move(e_fn)),
          sample_count(0),
          last_value(0.0),
          accumulated_value(0.0) {}
    virtual ~MonitorImpl() = default;
};

} // namespace bytemonitor
