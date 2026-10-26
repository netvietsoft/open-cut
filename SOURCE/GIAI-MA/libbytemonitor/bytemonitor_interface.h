// ============================================================================
// RECONSTRUCTED C++ HEADER: bytemonitor_interface.h
// Target Library: libbytemonitor.so (67,408 bytes, ELF64 AArch64)
// Module: Public C/C++/JNI Exported Interface & Verification Facade
// Reference Disassembly:
//   - Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit: 0x009570 (304 B)
//   - JNI_OnLoad:   0x00977c (508 B, returns 0x00010006 = JNI_VERSION_1_6)
//   - BTC_FindClass: 0x0099b8 (84 B)
//   - JNI_OnUnload: 0x009a0c (12 B)
//   - ByteMonitor & AndroidMonitor: 0x0050ec..0x005718, 0x00cb08..0x00cbd0
// ============================================================================
// Tệp tiêu đề công bố giao diện xuất xưởng C/JNI (`JNI_OnLoad`, `JNI_OnUnload`,
// `BTC_FindClass`, `Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit`)
// cùng toàn bộ 25 biểu tượng động `.dynsym` (`[077]..[101]`) của `libbytemonitor.so`.
// ============================================================================

#pragma once

#include "bytemonitor_types.h"
#include "bytemonitor_sysfs_tools.h"
#include "bytemonitor_env_engine.h"
#include <cstdint>
#include <string>
#include <vector>
#include <memory>

// --- JNI & C ABI EXPORTED FUNCTIONS (4 C/JNI exports in .dynsym) ---
extern "C" {

/**
 * @brief Exported `[099]` `Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit`
 * (`0x009570..0x00969c`, 304 bytes).
 * Binds `com/benchmark/bytemonitor/BatteryMonitor` global reference into `BatteryTools` singleton.
 * Hàm JNI khởi tạo cầu nối `BatteryMonitor` từ tầng Java xuống tầng C++ Native.
 */
void Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit(
    void* env, void* clazz, void* battery_monitor_jobject);

/**
 * @brief Exported `[081]` `JNI_OnLoad` (`0x00977c..0x009974`, 508 bytes).
 * Stores `JavaVM*` at `.bss 0x0140b0`, creates TLS key at `.bss 0x01408c` via `pthread_key_create`,
 * caches `com/benchmark/bytemonitor/BatteryMonitor` class in `.bss 0x0140e0`, and returns `0x00010006`.
 * Điểm nhập khởi tạo thư viện JNI, đăng ký khóa TLS cho `JNIEnv*` và trả về `JNI_VERSION_1_6`.
 */
int32_t ByteMonitor_JNI_OnLoad(void* vm, void* reserved);

/**
 * @brief Exported `[094]` `JNI_OnUnload` (`0x009a0c..0x009a14`, 12 bytes).
 * Clears `JavaVM*` at `.bss 0x0140b0` (`str xzr, [x8, #0xb0]`).
 * Giải phóng con trỏ `JavaVM*` tại `.bss 0x0140b0` khi dỡ thư viện.
 */
void ByteMonitor_JNI_OnUnload(void* vm, void* reserved);

/**
 * @brief Exported `[100]` `BTC_FindClass` (`0x0099b8..0x009a08`, 84 bytes).
 * Searches the cached JNI class registry at `.bss 0x0140e0` by class name string (`strcmp` @ `0x0099d8`).
 * Tra cứu `jclass` đã lưu đệm trong danh mục lớp JNI tại `.bss 0x0140e0`.
 */
void* BTC_FindClass(void* env, const char* class_name);

} // extern "C"

namespace NextAI::OpenCut::bytemonitor {

// ============================================================================
// EXPORTED SYMBOL DESCRIPTOR FOR RUNTIME VERIFICATION
// Cấu trúc mô tả biểu tượng xuất xưởng `.dynsym` phục vụ đối soát nhị phân
// ============================================================================
struct ExportedSymbolDescriptor {
    uint32_t    dynsym_index;
    uint64_t    vaddr;
    uint32_t    size_bytes;
    const char* mangled_name;
    const char* demangled_name;
};

/**
 * @brief High-level reconstruction verification & orchestration facade for `libbytemonitor.so`.
 * Lớp mặt tiền điều phối và kiểm chứng toàn diện cho thư viện `libbytemonitor.so`.
 */
class BytemonitorEngine {
public:
    BytemonitorEngine();
    virtual ~BytemonitorEngine();

    /**
     * @brief Returns the complete table of 25 exported `.dynsym` symbols (`[077]..[101]`).
     * Trả về bảng danh mục 25 biểu tượng xuất xưởng `.dynsym` (`[077]..[101]`).
     */
    static const std::vector<ExportedSymbolDescriptor>& getExportedSymbols();

    /**
     * @brief Executes the full end-to-end deterministic self-test suite across all 11 MonitorTypes.
     * Thực thi bộ kịch bản tự kiểm thử toàn diện trên cả 11 loại chỉ số giám sát phần cứng.
     */
    bool runComprehensiveSelfTest(std::string* out_report = nullptr);

private:
    std::shared_ptr<::bytemonitor::ByteMonitor> monitor_{nullptr};
};

} // namespace NextAI::OpenCut::bytemonitor
