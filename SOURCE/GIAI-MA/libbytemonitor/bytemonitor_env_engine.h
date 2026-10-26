// ============================================================================
// RECONSTRUCTED C++ HEADER: bytemonitor_env_engine.h
// Target Library: libbytemonitor.so (67,408 bytes, ELF64 AArch64)
// Module: EnvMonitor Dispatcher, ByteMonitor Base & AndroidMonitor Vtable
// Reference Disassembly:
//   - AndroidMonitor: 0x0050ec..0x005758 (vtable @ 0x012938, 152 bytes = 19 pointers)
//   - EnvMonitor:     0x005888..0x009060 (72 bytes = 0x48 singleton @ .bss 0x014098)
//   - ByteMonitor:    0x00cb08..0x00cbd0 (getMonitor @ 0x00cb08, setLogLevel @ 0x00cb74)
// ============================================================================
// Tệp tiêu đề định nghĩa bộ điều phối trung tâm `EnvMonitor`, lớp cơ sở `ByteMonitor`
// và lớp dẫn xuất `AndroidMonitor` khớp chính xác bố cục vtable 19 con trỏ (152 bytes)
// tại địa chỉ `.data.rel.ro 0x012938` của `libbytemonitor.so`.
// ============================================================================

#pragma once

#include "bytemonitor_types.h"
#include "bytemonitor_sysfs_tools.h"
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

namespace bytemonitor {

// ============================================================================
// 1. ENVMONITOR — CENTRAL 11-METRIC HARDWARE TELEMETRY DISPATCHER (72 BYTES = 0x48)
// Phục hồi từ .text @ 0x005888..0x009060, singleton lưu tại .bss 0x014098
// ============================================================================
class EnvMonitor {
public:
    static constexpr size_t   kAbiSize          = 72U;        // 0x48 bytes allocated at 0x006fb8
    static constexpr uint64_t kSingletonBssVaddr= 0x014098ULL;

    /**
     * @brief Retrieves or allocates the 72-byte `EnvMonitor` singleton (`0x006fa0..0x006fec`).
     * Truy xuất hoặc cấp phát thực thể đơn `EnvMonitor` (72 bytes) tại `.bss 0x014098`.
     */
    static EnvMonitor* getInstance();

    /**
     * @brief Initializes and registers all 11 `MonitorImpl` (272-byte) handlers (`0x005888..0x005d5c`).
     * Invoked once via `std::__call_once` at `.bss 0x014010` inside `AndroidMonitor::AndroidMonitor()`.
     * Khởi tạo và đăng ký toàn bộ 11 bộ thu thập chỉ số `MonitorImpl` (272 bytes mỗi bộ).
     */
    void init();

    /**
     * @brief Dispatches `begin_fn` for the given `MonitorEvent` (`0x006a78..0x006ba4`).
     * Looks up `event->monitor_type` in the internal hash table and invokes offset `+0x60`.
     * Bắt đầu một phiên đo lường cho sự kiện `MonitorEvent`.
     */
    void beginSection(std::shared_ptr<MonitorEvent>& event);

    /**
     * @brief Dispatches `end_fn` for the given `MonitorEvent` and returns the metric (`0x006ba8..0x006ce0`).
     * Looks up `event->monitor_type` in the internal hash table and invokes offset `+0x80`.
     * Kết thúc phiên đo lường và trả về giá trị chỉ số thu thập được.
     */
    double endSection(std::shared_ptr<MonitorEvent>& event);

    /**
     * @brief Dumps formatted telemetry report to log/output (`0x006ce4..0x006f9c`).
     * Xuất báo cáo tổng hợp các chỉ số phần cứng đã thu thập.
     */
    void dumpInfo(const std::string& tag);

    // Inspection helpers for verification test suite / Hàm hỗ trợ kiểm thử
    bool isInitialized() const { return initialized_; }
    size_t getRegisteredMonitorCount() const;
    std::shared_ptr<MonitorImpl> getMonitorImpl(MonitorType type) const;
    const std::string& getLastDumpReport() const { return last_dump_report_; }

private:
    EnvMonitor();
    ~EnvMonitor() = default;

    // 11 registration helpers matching 0x007098..0x007970
    void registerMonitorType1_CPU();
    void registerMonitorType11_GPU();
    void registerMonitorType4_MemoryUsage();
    void registerMonitorType3_AvailableMem();
    void registerMonitorType5_BatteryLevel();
    void registerMonitorType6_Temperature();
    void registerMonitorType2_ThreadCPU();
    void registerMonitorType7_ProcessVM();
    void registerMonitorType8_ProcessVMSize();
    void registerMonitorType9_ProcessCPU();
    void registerMonitorType10_BatteryCurrent();

    mutable std::mutex                                         mutex_;       // +0x20..+0x47 (40 bytes)
    std::unordered_map<int32_t, std::shared_ptr<MonitorImpl>>  monitors_;    // +0x00..+0x27 (40 bytes)
    bool                                                       initialized_{false};
    std::string                                                last_dump_report_{};
};

// ============================================================================
// 2. BYTEMONITOR — ABSTRACT BASE INTERFACE & LOG LEVEL CONTROLLER
// Phục hồi từ .text @ 0x00cb08..0x00cbd0
// ============================================================================
class ByteMonitor {
public:
    /**
     * @brief Exported `[079]` `_ZN11bytemonitor11ByteMonitor10getMonitorEv` (`0x00cb08`, 64 B).
     * Thread-safe singleton factory returning `std::shared_ptr<ByteMonitor>` (pointing to `AndroidMonitor`).
     * Hàm xuất xưởng trả về con trỏ chia sẻ tới đối tượng `AndroidMonitor` duy nhất.
     */
    static std::shared_ptr<ByteMonitor> getMonitor();

    /**
     * @brief Exported `[092]` `_ZN11bytemonitor11ByteMonitor11setLogLevelEi` (`0x00cb74`, 96 B).
     * Maps bitmask log filter `(1->6, 3->5, 7->4, 15->3, 31->2, default->8)` into `.data 0x014000`.
     * Thiết lập cấp độ ghi log toàn cục tại `.data 0x014000`.
     */
    static void setLogLevel(int level);

    /**
     * @brief Reads the active Android log priority stored at `.data 0x014000`.
     * Đọc mức ưu tiên log hiện hành tại `.data 0x014000`.
     */
    static int getLogLevel();

    // Virtual interface matching vtable slots [2]..[18] at 0x012948..0x0129c8
    virtual double CPU() = 0;                                                               // slot [2] +0x10
    virtual double GPUUsage() = 0;                                                          // slot [3] +0x18
    virtual double MemoryUsage() = 0;                                                       // slot [4] +0x20
    virtual double batteryLevel() = 0;                                                      // slot [5] +0x28
    virtual double Temperature() = 0;                                                       // slot [6] +0x30
    virtual double AvailableMem() = 0;                                                      // slot [7] +0x38
    virtual std::shared_ptr<MonitorEvent> monitorThreadCPUUsageBegin(int pid, int tid) = 0; // slot [8] +0x40
    virtual double monitorThreadCPUUsageEnd(std::shared_ptr<MonitorEvent>& event) = 0;      // slot [9] +0x48
    virtual std::shared_ptr<MonitorEvent> monitorProcessVMBegin(int pid) = 0;               // slot [10] +0x50
    virtual double monitorProcessVMEnd(std::shared_ptr<MonitorEvent>& event) = 0;           // slot [11] +0x58
    virtual double monitorProcessVMSize() = 0;                                              // slot [12] +0x60
    virtual std::shared_ptr<MonitorEvent> monitorProcessCPUUsage() = 0;                     // slot [13] +0x68
    virtual double monitorProcessCPUUsageEnd(std::shared_ptr<MonitorEvent>& event) = 0;     // slot [14] +0x70
    virtual double monitorBatteryElectricCurrent() = 0;                                     // slot [15] +0x78
    virtual void dumpInfo(const std::string& tag) = 0;                                      // slot [16] +0x80
    virtual ~ByteMonitor() = default;                                                       // slots [17..18]
};

// ============================================================================
// 3. ANDROIDMONITOR — CONCRETE MONITOR IMPLEMENTATION (16 BYTES ABI)
// Phục hồi từ .text @ 0x0050ec..0x005758 & .data.rel.ro @ 0x012938 (152 bytes)
// ============================================================================
class AndroidMonitor : public ByteMonitor {
public:
    static constexpr size_t   kAbiSize          = 16U;        // +0x00 vptr, +0x08 EnvMonitor*
    static constexpr uint64_t kVtableVaddr      = 0x012938ULL;// 152 bytes (19 pointers)
    static constexpr size_t   kVtableByteSize   = 152U;

    /**
     * @brief Exported `[080]` & `[088]` `AndroidMonitor::AndroidMonitor()` (`0x0050ec`, 184 B).
     * Sets `vptr = 0x012948`, stores `EnvMonitor::getInstance()` at `+0x08`, and runs `std::call_once`
     * on `.bss 0x014010` to invoke `EnvMonitor::init()` (`0x005888`).
     * Khởi tạo `AndroidMonitor`, gắn bảng phương thức ảo và kích hoạt `EnvMonitor::init()` đúng 1 lần.
     */
    AndroidMonitor();

    ~AndroidMonitor() override;

    // 15 Exported Telemetry Methods matching .dynsym [077..101] & vtable 0x012948..0x0129b8
    double CPU() override;                                                               // 0x005260 (Type 1)
    double GPUUsage() override;                                                          // 0x0052ac (Type 11)
    double MemoryUsage() override;                                                       // 0x0052f8 (Type 4)
    double batteryLevel() override;                                                      // 0x005344 (Type 5)
    double Temperature() override;                                                       // 0x005390 (Type 6)
    double AvailableMem() override;                                                      // 0x0053dc (Type 3)
    std::shared_ptr<MonitorEvent> monitorThreadCPUUsageBegin(int pid, int tid) override; // 0x005428 (Type 2)
    double monitorThreadCPUUsageEnd(std::shared_ptr<MonitorEvent>& event) override;      // 0x0054a8 (Type 2)
    std::shared_ptr<MonitorEvent> monitorProcessVMBegin(int pid) override;               // 0x0054f0 (Type 7)
    double monitorProcessVMEnd(std::shared_ptr<MonitorEvent>& event) override;           // 0x00555c (Type 7)
    double monitorProcessVMSize() override;                                              // 0x0055b0 (Type 8)
    std::shared_ptr<MonitorEvent> monitorProcessCPUUsage() override;                     // 0x0055fc (Type 9)
    double monitorProcessCPUUsageEnd(std::shared_ptr<MonitorEvent>& event) override;     // 0x005670 (Type 9)
    double monitorBatteryElectricCurrent() override;                                     // 0x0056c4 (Type 10)
    void dumpInfo(const std::string& tag) override;                                      // 0x005710

    EnvMonitor* getEnvMonitor() const { return env_monitor_; }

private:
    EnvMonitor* env_monitor_{nullptr}; // +0x08 (`str x0, [x19, #8]` @ 0x00511c)
};

} // namespace bytemonitor
