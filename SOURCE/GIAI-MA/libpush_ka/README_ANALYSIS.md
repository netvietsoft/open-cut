# Clean-Room Reconstruction Analysis — `libpush_ka.so`

## 1. Binary Identity & Cryptographic Hashes
- **File Name**: `libpush_ka.so`
- **File Size**: `18,184 bytes`
- **SHA-256**: `e8a32d5847f22373b03950fe22ee6ffa53a667ce77c57e018a2db9d409914281`
- **Task ID**: `TASK-171-RECONSTRUCTION-LIBPUSH-KA` (`TASK_SO_162_libpush_ka`)
- **Architecture**: `AArch64 (ARM64-v8a)` ELF64 Shared Library
- **Total Reconstructed C++17 Code Size**: `106,605 bytes` across 3 implementation files (`0` stubs)

## 2. ELF64 Layout & 1 FDE Map (`.eh_frame_hdr` @ `0x0890`)
- `.plt`: `0x06a0..0x0720` (`128 bytes`, `32 instructions`)
- `.text`: `0x0720..0x0824` (`260 bytes`, `65 AArch64 instructions`)
- `.rodata`: `0x0824..0x088e` (`106 bytes` — `"libandroid_runtime.so"`, `"_ZN7android14AndroidRuntime10getRuntimeEv"`, `"_ZN7android14AndroidRuntime8setArgv0EPKcb"`)
- `.eh_frame_hdr`: `0x0890..0x08a4` (`20 bytes`, `1 FDE` @ `0x0768`)

| FDE | Start VA | Size | Reconstructed Symbol / Role |
|---|---|---|---|
| `FDE[00]` | `0x0768` | `188 B` | `Java_com_bytedance_vega_ug_push_alive_undead_base_KAImpl_getRuntimeAddr` (`npth_dlopen` + `npth_dlsym` + `NewLongArray` @ `+0x5A0` + `stp x21, x22, [x0]`) |
