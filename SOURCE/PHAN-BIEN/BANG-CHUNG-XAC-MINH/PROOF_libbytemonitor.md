# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG: `libbytemonitor.so` (`TASK-092-RECONSTRUCTION-LIBBYTEMONITOR` / `TASK_SO_140`)

## 1. Thông Tin Thư Viện & Tổng Quan 6 Cổng Nghiệm Thu
- **Tên thư viện**: `libbytemonitor.so` (`67,408 bytes`, ELF64 AArch64)
- **Đường dẫn nhị phân**: `SOURCE/apktool-res/lib/arm64-v8a/libbytemonitor.so`
- **Biểu tượng `.dynsym`**: `102 entries` (`76` imported + `25` exported `[077]..[101]`)
- **Trạng thái đối kháng**: `VERIFIED_AND_ACCEPTED` (6/6 Gates PASS)

---

## 2. Đối Chiếu Opcode AArch64 & Bố Cục Struct ABI (`Gate 2` & `Gate 4`)
### 2.1. `AndroidMonitor` (`16 bytes`, Vtable `152 bytes` tại `.data.rel.ro 0x012938`)
- `0x005104..0x00511c`:
  ```asm
  0x005104: adrp x8, #0x12000
  0x005108: add  x8, x8, #0x938       ; _ZTVN11bytemonitor14AndroidMonitorE
  0x00510c: add  x8, x8, #0x10        ; vptr = 0x012948
  0x005110: str  x8, [x19]            ; +0x00: vptr
  0x005114: bl   #0x6fa0              ; EnvMonitor::getInstance()
  0x00511c: str  x0, [x19, #8]        ; +0x08: EnvMonitor*
  ```
- Bảng 19 con trỏ trong `_ZTVN11bytemonitor14AndroidMonitorE` (`0x012938..0x0129c8`):
  - `+0x00`: `0` (offset-to-top)
  - `+0x08`: `0x0129f0` (`_ZTIN11bytemonitor14AndroidMonitorE`)
  - `+0x10..+0x80`: 15 phương thức giám sát (`0x005260..0x005710`)
  - `+0x88..+0x90`: `~AndroidMonitor()` D1Ev (`0x005750`) & D0Ev (`0x005754`)

### 2.2. `EnvMonitor` (`72 bytes = 0x48` tại `.bss 0x014098`) & `MonitorImpl` (`272 bytes = 0x110`)
- `0x006fb8`: `mov w0, #0x48; bl operator new` — cấp phát 72 bytes cho `EnvMonitor` (`+0x00..+0x27` `std::unordered_map<int32_t, std::shared_ptr<MonitorImpl>>`, `+0x20..+0x47` `std::mutex`).
- `0x0070bc..0x0078c8`: `mov w0, #0x110; bl operator new` — cấp phát 11 đối tượng `MonitorImpl` (`272 bytes`) tương ứng với `MonitorType 1..11`.
- `ThreadCPUParam` (`0x005450`: `mov w0, #0x28`, vtable `0x012a20`): `+0x08` `pid`, `+0x0c` `tid`, `+0x10` `start_thread_jiffies`, `+0x18` `start_proc_jiffies`, `+0x20` `last_usage_pct`.
- `ProcessVMParam` (`0x005514`: `mov w0, #0x20`, vtable `0x012a00`): `+0x08` `pid`, `+0x10` `baseline_metric_primary`, `+0x18` `baseline_metric_secondary`.

---

## 3. Chứng Minh Toán Học IEEE-754 (`Gate 3`)
1. **CPU Normalized Frequency Usage (`0x00bb04..0x00bde4` & `0x008af8`)**:
   - `0x00bd1c..0x00bd6c`: `sub x8, x21, x8; scvtf d0, x8; sub x8, x22, x24; scvtf d1, x8; fdiv d0, d0, d1; fadd d8, d8, d0; ... scvtf d0, x8; fdiv d8, d8, d0`
   - `0x008b10..0x008b18`: `mov x8, #0x4059000000000000; fmov d1, x8; fmul d8, d0, d1` (`* 100.0`).
2. **Thread CPU Usage (`0x008cbc..0x008d40` & `0x00bde8..0x00bf18`)**:
   - Tổng 4 trường `utime` (`+0x138`), `stime` (`+0x150`), `cutime` (`+0x168`), `cstime` (`+0x180`) từ `/proc/<pid>/task/<tid>/stat` chia cho độ tăng tương ứng của `/proc/<pid>/stat`, nhân `100.0` và kẹp trong `[0.0, 100.0]`.
3. **Process CPU Usage (`0x008efc..0x008f78` & `0x009064..0x00910c`)**:
   - Đọc `/sys/devices/system/cpu/cpu0/cpufreq/stats/time_in_state`, tính `(sum_10ms + 5) / 10.0` (`0x009100..0x00910c`), và tính `((delta_proc / delta_cpu) * 100.0) / N_cores` (`0x008f5c..0x008f78`).
4. **GPU Usage (`0x00c054..0x00c20c`) & Memory Usage (`0x00c684..0x00c79c`)**:
   - `GPUUsage% = (busy / total) * 100.0` (`0x00c1f4..0x00c20c`).
   - `MemUsage% = ((MemTotal - MemAvailable) / MemTotal) * 100.0` (`0x00c784..0x00c79c`).
