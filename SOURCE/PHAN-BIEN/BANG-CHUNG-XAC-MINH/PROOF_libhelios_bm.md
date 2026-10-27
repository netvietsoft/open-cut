# Clean-Room Reconstruction Analysis — `libhelios_bm.so`

## 1. Binary Identity & Cryptographic Hashes
- **File Name**: `libhelios_bm.so`
- **File Size**: `18,424 bytes`
- **SHA-256**: `79a0bb7b7d00a64fe4f0c0182d5416ab2515768f0262c23578d436c792a20e90`
- **Task ID**: `TASK-174-RECONSTRUCTION-LIBHELIOS-BM` (`TASK_SO_157_libhelios_bm`)
- **Architecture**: `AArch64 (ARM64-v8a)` ELF64 Shared Library
- **Total Reconstructed C++17 Code Size**: `260,227 bytes` across 3 implementation files (`0` stubs)

## 2. ELF64 Layout & 22 FDE Map (`.eh_frame_hdr` @ `0x2710`)
- `.plt`: `0x0a70..0x0b70` (`256 bytes`, `64 instructions`)
- `.text`: `0x0b70..0x225c` (`5,868 bytes`, `1,467 AArch64 instructions`)
- `.rodata`: `0x225c..0x270e` (`1,202 bytes`)
- `.eh_frame_hdr`: `0x2710..0x27cc` (`188 bytes`, `22 FDEs`)

| FDE | Start VA | Size | Reconstructed Symbol / Role |
|---|---|---|---|
| `FDE[00..04]` | `0x0bac..0x0d04` | `344 B` | TLS re-entrancy guard (`pthread_key_create`, `ldarb`/`stlrb`, `IsCurrentThreadEntered`, `EnterThreadGuard`, `LeaveThreadGuard`) |
| `FDE[05]` | `0x0d04` | `128 B` | `HookArtMethodEntrypoint` (`stlr x19, [x8]` @ `0x0d68`) |
| `FDE[06..09]` | `0x0d84..0x10bc` | `824 B` | `GetArtMethodFromReflectMethod`, `GetAndroidSdkVersion` (`ro.build.version.sdk`), `GetArtFieldFromReflectField` |
| `FDE[10..13]` | `0x10bc..0x1bd4` | `2,840 B` | `HeliosReserved0Stub` (`0x10bc`), `HeliosReserved1Stub` (`0x10c0`), `HeliosContextInit`, `HeliosResolveJniAndVerifyArtOffset` (`0x128` cache) |
| `FDE[14..15]` | `0x1bd4..0x1c0c` | `56 B` | `GetHeliosGlobalState` (`0x1bd4`) & `.init_array[0]` constructor (`malloc(0x28)` @ `0x1be8`) |
| `FDE[16..18]` | `0x1c0c..0x1eac` | `672 B` | `_Z10nativeInitP7_JNIEnv` (`0x1c0c`) & 5-arg/6-arg `BinderProxy.transactNative` hooks (`0x1d24`, `0x1de4`) |
| `FDE[19..21]` | `0x1eac..0x225c` | `944 B` | `JNI_OnLoad` (`0x1eac`, `VMRuntime.setHiddenApiExemptions(["L"])`, `0x00010006`) & varargs JNI helpers |
