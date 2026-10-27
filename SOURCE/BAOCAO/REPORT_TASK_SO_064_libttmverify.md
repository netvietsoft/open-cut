# Clean-Room Reconstruction Analysis — `libttmverify.so`

## 1. Binary Identity & Cryptographic Hashes
- **File Name**: `libttmverify.so`
- **File Size**: `18,112 bytes`
- **SHA-256**: `1e8fb5cee7d8a9ee166e6590f292580687b0958664eb37df58bbf9c92aadcd77`
- **Task ID**: `TASK-170-RECONSTRUCTION-LIBTTMVERIFY` (`TASK_SO_064_libttmverify`)
- **Architecture**: `AArch64 (ARM64-v8a)` ELF64 Shared Library
- **Total Reconstructed C++17 Code Size**: `92,536 bytes` across 4 implementation files (`0` stubs)

## 2. ELF64 Layout & 4 FDE Map (`.eh_frame_hdr` @ `0x17c0`)
- `.plt`: `0x0ed0..0x10d0` (`512 bytes`, `128 instructions`)
- `.text`: `0x10d0..0x1554` (`1,156 bytes`, `289 AArch64 instructions`)
- `.rodata`: `0x1554..0x17bd` (`617 bytes`)
- `.eh_frame_hdr`: `0x17c0..0x17ec` (`44 bytes`, `4 FDEs`)

| FDE | Start VA | Size | Reconstructed Symbol / Role |
|---|---|---|---|
| `FDE[00]` | `0x10dc` | `192 B` | `JNI_OnLoad` (logs `"Jun 26 2025"` / `"12:29:14"`, calls `tt_set_verify_callback(vcn_custom_verify_2)`, returns `0x00010004`) |
| `FDE[01]` | `0x119c` | `228 B` | `TtmVerifyFormattedLogPrint` (`vsnprintf` 512B + `__android_log_print(3, "ttmverify", "<%p,%s,%s,%d>%s", ...)`) |
| `FDE[02]` | `0x1280` | `720 B` | `vcn_custom_verify_2` (Cronet V2 & BoringSSL peer certificate, OCSP, SCT, and RSA KeyUsage verifier) |
| `FDE[03]` | `0x1550` | `4 B` | `JNI_OnUnload` (`ret`) |
