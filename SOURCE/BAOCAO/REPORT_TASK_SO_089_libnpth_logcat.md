# Clean-Room Reconstruction Analysis — `libnpth_logcat.so`

## 1. Binary Identity & Cryptographic Hashes
- **File Name**: `libnpth_logcat.so`
- **File Size**: `16,856 bytes`
- **SHA-256**: `241f75ebe9208e680c0d0e77c6f23c2f87d7ba9c2d446ca5c75a9df2ab8319e8`
- **Task ID**: `TASK-169-RECONSTRUCTION-LIBNPTH-LOGCAT` (`TASK_SO_089_libnpth_logcat`)
- **Architecture**: `AArch64 (ARM64-v8a)` ELF64 PIE Executable (`ET_DYN` with `.interp = "/system/bin/linker64"` @ `0x0270`)
- **Total Reconstructed C++17 Code Size**: `143,949 bytes` across 4 implementation files (`0` stubs)

## 2. ELF64 Layout & 10 FDE Map (`.eh_frame_hdr` @ `0x1454`)
- `.interp`: `0x0270..0x0285` (`21 bytes` — `"/system/bin/linker64\0"`)
- `.rodata`: `0x0f60..0x1453` (`1,267 bytes`)
- `.eh_frame_hdr`: `0x1454..0x14b0` (`92 bytes`, `10 FDEs`)
- `.text`: `0x16e8..0x31a8` (`6,848 bytes`, `1,712 AArch64 instructions`)
- `.data`: `0x0b810..0x0b950` (`320 bytes`, file offset `0x3810..0x3950`)
- `.bss`: `0x0b950..0x0b9b0` (`96 bytes` — `NpthLogcatBssState`)

| FDE | Start VA | Size | Reconstructed Symbol / Role |
|---|---|---|---|
| `FDE[00]` | `0x16fc` | `68 B` | `_start_main` (`paciasp`, calls `__libc_init`) |
| `FDE[01]` | `0x1740` | `16 B` | `atexit_trampoline` |
| `FDE[02]` | `0x1754` | `28 B` | `register_atexit` (`__cxa_atexit`) |
| `FDE[03]` | `0x1770` | `2,428 B` | `NpthLogcatSafeVsnprintf` (signal-safe `vsnprintf`) |
| `FDE[04]` | `0x20ec` | `148 B` | `NpthLogcatSafeSnprintf` (variadic `snprintf`) |
| `FDE[05]` | `0x2180` | `1,564 B` | `RunNpthLogcatMain` (`main`: signal setup, `liblog.so` loader, `execlp` fallback) |
| `FDE[06]` | `0x279c` | `1,120 B` | `dump_log_buffer` (`ParseRawLoggerPacket`, `FormatLogcatThreadTimeLine`, `0xAF000` cap) |
| `FDE[07]` | `0x2bfc` | `496 B` | `log_status_printf` (`FormatStatusTimestamp` with 64-bit reciprocal math) |
| `FDE[08]` | `0x2dec` | `772 B` | `crash_signal_handler` (`SYS_rt_tgsigqueueinfo = 240`, `ftruncate`, `alarm(30)`, `execlp`) |
| `FDE[09]` | `0x30f0` | `184 B` | `ResolveSiblingLibraryPath` (`dladdr` + `__strrchr_chk('/')`) |
