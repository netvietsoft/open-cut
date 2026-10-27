# Clean-Room Reconstruction Analysis — `libnpth_tls_monitor.so`

## 1. Binary Identity & Cryptographic Hashes
- **File Name**: `libnpth_tls_monitor.so`
- **File Size**: `15,904 bytes`
- **SHA-256**: `7dc9ec38a56447ae99bde0d8bb89408b3583ea62097a3c0f7d55ba8c5b4e0fa7`
- **Task ID**: `TASK-168-RECONSTRUCTION-LIBNPTH-TLS-MONITOR` (`TASK_SO_090_libnpth_tls_monitor`)
- **Architecture**: `AArch64 (ARM64-v8a)` ELF64 Shared Library
- **Total Reconstructed C++17 Code Size**: `126,829 bytes` across 4 implementation files (`0` stubs)

## 2. ELF64 Layout & 18 FDE Map (`.eh_frame_hdr` @ `0x13d4`)
- `.rodata`: `0x0ee8..0x13d2` (`1,258 bytes`)
- `.eh_frame_hdr`: `0x13d4..0x1470` (`156 bytes`, `18 FDEs`)
- `.text`: `0x17ac..0x30a8` (`6,396 bytes`, `1,599 AArch64 instructions`)
- `.data`: `0x0b660..0x0b670` (`16 bytes` — exported `tls_native_interface_func = { 0x17fc, 0x1ac8 }`)
- `.bss`: `0x0b670..0x0b6bc` (`76 bytes` — `TlsMonitorBssState`)
