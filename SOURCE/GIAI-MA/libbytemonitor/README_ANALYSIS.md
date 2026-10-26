# BÁO CÁO GIẢI MÃ & TÁI DỰNG HOÀN CHỈNH: `libbytemonitor.so` (ByteBench Hardware & Process Resource Monitor)

## 1. Thông Số Nhị Phân ELF64 (`OBSERVED` từ `apktool-res/lib/arm64-v8a/libbytemonitor.so`)
- **Dung lượng nhị phân gốc**: `67,408 bytes` (`0x10750 bytes`)
- **Kiến trúc**: `ELF 64-bit LSB shared object, ARM aarch64`
- **Tổng số biểu tượng `.dynsym`**: `102 entries` (`[000]` NULL + `76` imported symbols `[001]..[076]` + `25` exported symbols `[077]..[101]`)
- **Các phân đoạn ELF64 cốt lõi**:
  - `.dynsym`: `0x000238` (`2,448 bytes`, 102 entries)
  - `.dynstr`: `0x000bc8` (`2,991 bytes`)
  - `.rela.dyn`: `0x0018a0` (`8,280 bytes`)
  - `.rela.plt`: `0x0038f8` (`1,872 bytes`)
  - `.plt`: `0x004050` (`1,264 bytes`)
  - `.text`: `vaddr 0x004ed0 .. 0x00d560` (`34,448 bytes`)
  - `.rodata`: `vaddr 0x00d560 .. 0x00dc41` (`1,761 bytes`)
  - `.eh_frame_hdr`: `vaddr 0x00dc44 .. 0x00e06c` (`1,064 bytes`)
  - `.eh_frame`: `vaddr 0x00e070 .. 0x00fb50` (`6,880 bytes`)
  - `.gcc_except_table`: `vaddr 0x00fb50 .. 0x01053c` (`2,540 bytes`)
  - `.init_array`: `vaddr 0x0128f0 .. 0x012920` (`48 bytes`, 6 static constructors: `0x004ed0`, `0x004f1c`, `0x004f50`, `0x004f6c`, `0x004f90`, `0x004fec`)
  - `.data.rel.ro`: `vaddr 0x012930 .. 0x013b90` (`4,704 bytes`, chứa `_ZTVN11bytemonitor14AndroidMonitorE` tại `0x012938`, kích thước `152 bytes` = 19 pointers)
  - `.data`: `vaddr 0x014000 .. 0x014004` (`4 bytes`, chứa `g_log_level` mặc định `= 8`)
  - `.bss`: `vaddr 0x014010 .. 0x014150` (`320 bytes`)

---

## 2. Bảng 25 Biểu Tượng Xuất Xưởng `.dynsym` (`[077]..[101]`)
| STT | `.dynsym` | Địa chỉ `vaddr` | Kích thước | Tên Mangled / C Symbol | Chức năng giải mã |
|---|---|---|---|---|---|
| 1 | `[077]` | `0x0053dc` | `76 B` | `_ZN11bytemonitor14AndroidMonitor12AvailableMemEv` | `AndroidMonitor::AvailableMem()` (`MonitorType = 3`) |
| 2 | `[078]` | `0x0052ac` | `76 B` | `_ZN11bytemonitor14AndroidMonitor8GPUUsageEv` | `AndroidMonitor::GPUUsage()` (`MonitorType = 11`) |
| 3 | `[079]` | `0x00cb08` | `64 B` | `_ZN11bytemonitor11ByteMonitor10getMonitorEv` | `ByteMonitor::getMonitor()` singleton (`0x0140a0`) |
| 4 | `[080]` | `0x0050ec` | `184 B` | `_ZN11bytemonitor14AndroidMonitorC1Ev` | `AndroidMonitor::AndroidMonitor()` [C1] |
| 5 | `[081]` | `0x00977c` | `508 B` | `JNI_OnLoad` | Lưu `JavaVM*` (`0x0140b0`), tạo TLS key (`0x01408c`), cache `BatteryMonitor` (`0x0140e0`), trả về `0x00010006` |
| 6 | `[082]` | `0x0055fc` | `116 B` | `_ZN11bytemonitor14AndroidMonitor22monitorProcessCPUUsageEv` | `AndroidMonitor::monitorProcessCPUUsage()` (`MonitorType = 9`) |
| 7 | `[083]` | `0x012938` | `152 B` | `_ZTVN11bytemonitor14AndroidMonitorE` | Vtable 19 con trỏ của `bytemonitor::AndroidMonitor` |
| 8 | `[084]` | `0x0055b0` | `76 B` | `_ZN11bytemonitor14AndroidMonitor20monitorProcessVMSizeEv` | `AndroidMonitor::monitorProcessVMSize()` (`MonitorType = 8`) |
| 9 | `[085]` | `0x00555c` | `84 B` | `_ZN11bytemonitor14AndroidMonitor19monitorProcessVMEndERNSt6__ndk110shared_ptrINS_12MonitorEventEEE` | `AndroidMonitor::monitorProcessVMEnd(shared_ptr<MonitorEvent>&)` |
| 10 | `[086]` | `0x005344` | `76 B` | `_ZN11bytemonitor14AndroidMonitor12batteryLevelEv` | `AndroidMonitor::batteryLevel()` (`MonitorType = 5`) |
| 11 | `[087]` | `0x013a38` | `128 B` | `_ZTVNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEE` | Vtable của `std::__ndk1::basic_streambuf` |
| 12 | `[088]` | `0x0050ec` | `184 B` | `_ZN11bytemonitor14AndroidMonitorC2Ev` | `AndroidMonitor::AndroidMonitor()` [C2] |
| 13 | `[089]` | `0x005390` | `76 B` | `_ZN11bytemonitor14AndroidMonitor11TemperatureEv` | `AndroidMonitor::Temperature()` (`MonitorType = 6`) |
| 14 | `[090]` | `0x0054a8` | `72 B` | `_ZN11bytemonitor14AndroidMonitor24monitorThreadCPUUsageEndERNSt6__ndk110shared_ptrINS_12MonitorEventEEE` | `AndroidMonitor::monitorThreadCPUUsageEnd(shared_ptr<MonitorEvent>&)` |
| 15 | `[091]` | `0x0056c4` | `76 B` | `_ZN11bytemonitor14AndroidMonitor29monitorBatteryElectricCurrentEv` | `AndroidMonitor::monitorBatteryElectricCurrent()` (`MonitorType = 10`) |
| 16 | `[092]` | `0x00cb74` | `96 B` | `_ZN11bytemonitor11ByteMonitor11setLogLevelEi` | `ByteMonitor::setLogLevel(int)` (`1->6, 3->5, 7->4, 15->3, 31->2, default->8` vào `0x014000`) |
| 17 | `[093]` | `0x005260` | `76 B` | `_ZN11bytemonitor14AndroidMonitor3CPUEv` | `AndroidMonitor::CPU()` (`MonitorType = 1`) |
| 18 | `[094]` | `0x009a0c` | `12 B` | `JNI_OnUnload` | Xóa `JavaVM*` tại `.bss 0x0140b0` (`str xzr, [x8, #0xb0]`) |
| 19 | `[095]` | `0x0052f8` | `76 B` | `_ZN11bytemonitor14AndroidMonitor11MemoryUsageEv` | `AndroidMonitor::MemoryUsage()` (`MonitorType = 4`) |
| 20 | `[096]` | `0x005710` | `16 B` | `_ZN11bytemonitor14AndroidMonitor8dumpInfoERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE` | `AndroidMonitor::dumpInfo(const std::string&)` |
| 21 | `[097]` | `0x005428` | `128 B` | `_ZN11bytemonitor14AndroidMonitor26monitorThreadCPUUsageBeginEii` | `AndroidMonitor::monitorThreadCPUUsageBegin(int pid, int tid)` (`MonitorType = 2`) |
| 22 | `[098]` | `0x005670` | `84 B` | `_ZN11bytemonitor14AndroidMonitor25monitorProcessCPUUsageEndERNSt6__ndk110shared_ptrINS_12MonitorEventEEE` | `AndroidMonitor::monitorProcessCPUUsageEnd(shared_ptr<MonitorEvent>&)` |
| 23 | `[099]` | `0x009570` | `304 B` | `Java_com_benchmark_bytemonitor_nativePort_ByteMonitorPort_nativeInit` | Đăng ký `jobject` `BatteryMonitor` vào `BatteryTools` (`0x0140b8`) |
| 24 | `[100]` | `0x0099b8` | `84 B` | `BTC_FindClass` | Tìm kiếm lớp JNI đã cache trong `.bss 0x0140e0` qua `strcmp` |
| 25 | `[101]` | `0x0054f0` | `108 B` | `_ZN11bytemonitor14AndroidMonitor21monitorProcessVMBeginEi` | `AndroidMonitor::monitorProcessVMBegin(int pid)` (`MonitorType = 7`) |

---

## 3. Chứng Minh Toán Học & Đối Chiếu Hợp Ngữ AArch64 (`OBSERVED`)
1. **CPU Normalized Frequency Usage (`CPUTools` @ `0x00bb04..0x00bde4` & `0x008af8`)**:
   $$\text{CPUUsage\%} = \frac{100.0}{N_{\text{cores}}} \sum_{i \in \text{online}} \frac{f_{\text{cur},i} - f_{\text{min},i}}{f_{\text{max},i} - f_{\text{min},i}}$$
2. **Thread CPU Usage (`0x008cbc..0x008d40` & `0x00bde8..0x00bf18`)**:
   $$\text{ThreadCPU\%} = \text{clamp}\left(\frac{\Delta(\text{utime}+\text{stime}+\text{cutime}+\text{cstime})_{\text{tid}}}{\Delta(\text{utime}+\text{stime}+\text{cutime}+\text{cstime})_{\text{pid}}} \times 100.0,\; 0.0,\; 100.0\right)$$
3. **Process CPU Usage (`0x008efc..0x008f78` & `0x009064..0x00910c`)**:
   $$\text{ProcCPU\%} = \max\left(0.0,\; \frac{\Delta T_{\text{proc}}}{\Delta\left(\frac{\sum \text{time\_in\_state}_{10\text{ms}} + 5}{10.0}\right)} \times \frac{100.0}{N_{\text{cores}}}\right)$$
4. **GPU Usage (`GPUTools` @ `0x00c054..0x00c20c`)**:
   $$\text{GPUUsage\%} = \frac{\text{busy}}{\text{total}} \times 100.0$$
5. **System Memory Usage (`MemoryTools` @ `0x00c684..0x00c79c`)**:
   $$\text{MemUsage\%} = \frac{\text{MemTotal} - \text{MemAvailable}}{\text{MemTotal}} \times 100.0$$

---

## 4. Danh Mục Tệp Mã Nguồn Phục Hồi Trong `SOURCE/GIAI-MA/libbytemonitor/`
1. [`bytemonitor_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libbytemonitor/bytemonitor_types.h): Hằng số ELF64, 25 địa chỉ `.dynsym`, cấu trúc ABI `MonitorEvent`, `NoneEventParam`, `ThreadCPUParam` (`40 B`), `ProcessVMParam` (`32 B`), `MonitorImpl` (`272 B = 0x110`).
2. [`bytemonitor_sysfs_tools.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libbytemonitor/bytemonitor_sysfs_tools.h) & [`bytemonitor_sysfs_tools.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libbytemonitor/bytemonitor_sysfs_tools.cpp): Phục hồi `CPUTools`, `GPUTools`, `MemoryTools`, `BatteryTools` và `BatteryMonitorWrapper`.
3. [`bytemonitor_env_engine.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libbytemonitor/bytemonitor_env_engine.h) & [`bytemonitor_env_engine.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libbytemonitor/bytemonitor_env_engine.cpp): Phục hồi `EnvMonitor` (`72 B = 0x48`), `ByteMonitor` và `AndroidMonitor` (`16 B`, vtable `152 B` tại `0x012938`).
4. [`bytemonitor_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libbytemonitor/bytemonitor_interface.h), [`bytemonitor_interface.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libbytemonitor/bytemonitor_interface.cpp) & [`bytemonitor_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libbytemonitor/bytemonitor_pseudocode.cpp): Giao diện C/JNI xuất xưởng và bộ kiểm thử 6 cổng nghiệm thu độc lập.
