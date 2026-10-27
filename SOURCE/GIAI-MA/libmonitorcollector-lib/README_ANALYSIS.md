# Clean-Room Forensic Analysis & C++17 Reconstruction: `libmonitorcollector-lib.so`
# Phân Tích Pháp Y & Tái Cấu Trúc C++17 Clean-Room: `libmonitorcollector-lib.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **Library / Thư viện**: `libmonitorcollector-lib.so`
- **Canonical Task ID**: `TASK-134-RECONSTRUCTION-LIBMONITORCOLLECTOR-LIB` (`TASK_SO_114_libmonitorcollector_lib`)
- **Size / Dung lượng**: `313,744 bytes` (`313,744 bytes`)
- **SHA-256**: `739e2276dd31bc2805670367cfff2abc4a3d26e73e5b75635daff2a1f125e183`
- **Architecture / Kiến trúc**: `AArch64 (ARM64-v8a)`
- **Dynamic Dependencies (`DT_NEEDED`)**: `libbytehook.so`, `libnpth_bt.so`, `libnpth_dl.so`, `libshadowhook.so`, `liblog.so`, `libGLESv2.so`, `libm.so`, `libdl.so`, `libc.so`
- **Exported `.dynsym` Symbols**: `350`
- **Unwind `.eh_frame_hdr` FDE Count**: `1,030` functions (`0x0117b0..0x038cf0`)
- **Reconstructed C++17 Volume**: `736,422 bytes` across `11` files (`0` stubs)

---

## 2. Core Architecture & Disassembly Anchors / Kiến Trúc Cốt Lõi & Điểm Neo Mã Máy
1. **`JNI_OnLoad` (`0x0147b4..0x01498c`, `472 bytes`) & 46 `MonitorJni` Native Methods (`.data.rel.ro 0x04c948..0x04cd98`)**:
   - Copies `0x450 = 1,104 bytes` (`46 * 24`) from `.data.rel.ro 0x04c948` (`0x01483c..0x014848`) and calls `RegisterNatives` (`0x014854: mov w3, #0x2e = 46`) on `com/bytedance/monitor/collector/MonitorJni`.
   - Caches `BinderMonitor.saveBinderInfo("(JJJ)V")` and `LockMonitorManager.nativePut` / `nativeGetJavaStack` before returning `0x00010006` (`JNI_VERSION_1_6`).
2. **Systrace/Atrace & Lock Contention Detector (`0x01214c..0x0143a0`)**:
   - `log_systrace` (`0x0125b4`) intercepts `write(atrace_marker_fd, ...)` for `'B'` (`0x42`) and `'E'` (`0x45`) records, matching `"monitor contention"` (`.rodata 0x038e27`) and formatting `LockEvent` via `lockinfo_chars` (`0x0135d8`, `"%lld&#&%lld&#&%s&#&%s"`).
   - `recordTrace` (`0x012dd0`) filters out `"Chrome_InProcG"` (`len = 14`) and `"RenderThread"` (`len = 12`) and records into `main_thread_events` (`1,000` entries, `.data 0x050000`) and `sub_thread_events` (`10,000` entries, `.data 0x050004`).
   - `enableSystrace` (`0x014174`) executes `ldaxr`/`stlxr` atomic OR of `atrace_tags` (`0x401a` at `.data 0x050028`) into `atrace_enabled_tags`.
3. **Binder Transaction Hook (`0x0143a0..0x0147a4`)**:
   - `transact_hook` (`0x0143a0`) measures main-thread Binder transactions (`getpid() == gettid()`) and flags transactions whose duration is $\ge 4,000,000\text{ ns}$ (`0x003D0900` = `4 ms` at `0x01441c..0x014424`), converting nanoseconds to milliseconds via division by `0x000F4240 = 1,000,000` (`0x014430..0x01443c`).
4. **ProcFS State Jump Table (`0x0165bc` & `.rodata 0x038cf4[11]`), GraphicsMonitor (`0x01701c`), ART JavaAlloc (`0x018430`), and AArch64 Call-Offset Disassembler (`0x01bda0` & `.rodata 0x038cff[7]`)**.
