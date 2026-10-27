# Clean-Room Reconstruction Analysis — `libsys-platform.so`

## 1. Binary Identity & Cryptographic Hashes
- **File Name**: `libsys-platform.so`
- **File Size**: `18,184 bytes`
- **SHA-256**: `98d6a70902356f55fa38a2e62808865ada53250a97e2698ae19b37c8d785988b`
- **Task ID**: `TASK-172-RECONSTRUCTION-LIBSYS-PLATFORM` (`TASK_SO_088_libsys_platform`)
- **Architecture**: `AArch64 (ARM64-v8a)` ELF64 Shared Library
- **Total Reconstructed C++17 Code Size**: `138,883 bytes` across 3 implementation files (`0` stubs)

## 2. ELF64 Layout & 8 FDE Map (`.eh_frame_hdr` @ `0x0fc0`)
- `.plt`: `0x0aa0..0x0bb0` (`272 bytes`, `68 instructions`)
- `.text`: `0x0bb0..0x0fb4` (`1,028 bytes`, `257 AArch64 instructions`)
- `.rodata`: `0x0fb4..0x0fbf` (`11 bytes` — `"pidof %s\0r\0"`)
- `.eh_frame_hdr`: `0x0fc0..0x100c` (`76 bytes`, `8 FDEs`)

| FDE | Start VA | Size | Reconstructed Symbol / Role |
|---|---|---|---|
| `FDE[00]` | `0x0bf8` | `180 B` | `Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_lockfNonBlock` |
| `FDE[01]` | `0x0cac` | `8 B` | `Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_unlockfNonBlock` |
| `FDE[02]` | `0x0cb4` | `88 B` | `get_current_time` (`ComputeEpochMillisecondsFromTimeval`) |
| `FDE[03]` | `0x0d0c` | `116 B` | `modify_process_name` (`AndroidRuntime::setArgv0` + `prctl(PR_SET_NAME=15)`) |
| `FDE[04]` | `0x0d80` | `100 B` | `get_process_name` (`prctl(PR_GET_NAME=16)`) |
| `FDE[05]` | `0x0de4` | `244 B` | `get_main_process_pid` (`popen("pidof %s", "r")` + `usleep(4000000)`) |
| `FDE[06]` | `0x0ed8` | `164 B` | `FormatPidofCommand` (`__vsprintf_chk` `"pidof %s"`) |
| `FDE[07]` | `0x0f7c` | `56 B` | `Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_waitpid` |
