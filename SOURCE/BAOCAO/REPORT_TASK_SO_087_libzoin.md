# Clean-Room Reconstruction Analysis — `libzoin.so`

## 1. Binary Identity & Cryptographic Hashes
- **File Name**: `libzoin.so`
- **File Size**: `20,304 bytes`
- **SHA-256**: `461eaaa63714d460001f67de31520aa3d5b97431d177f9f73005c9519e87adcc`
- **Task ID**: `TASK-175-RECONSTRUCTION-LIBZOIN` (`TASK_SO_087_libzoin`)
- **Architecture**: `AArch64 (ARM64-v8a)` ELF64 Shared Library (BTI-enabled)
- **Total Reconstructed C++17 Code Size**: `348,057 bytes` across 3 implementation files (`0` stubs)

## 2. ELF64 Layout & 54 FDE Map (`.eh_frame_hdr` @ `0x1ac0`)
- `.rodata`: `0x1090..0x1ac0` (`2,608 bytes`, including 256-entry IEEE 802.3 CRC-32 table at `0x16c0..0x1ac0`)
- `.eh_frame_hdr`: `0x1ac0..0x1c7c` (`444 bytes`, `54 FDEs`)
- `.text`: `0x224c..0x4120` (`7,892 bytes`, `1,973 AArch64 instructions`)
- `.plt`: `0x4120..0x43e0` (`704 bytes`, `176 AArch64 instructions`)

| FDE | Start VA | Size | Reconstructed Symbol / Role |
|---|---|---|---|
| `FDE[05]` | `0x22a0` | `228 B` | `JNI_OnLoad` (`RegisterNatives` 4 methods = `0x60` B @ `0x83e8`, returns `0x00010006`) |
| `FDE[06]` | `0x2384` | `1,044 B` | `nInit` (`calloc(8, 0x18)` thread-log ring, `dlopen("libalog.so")`, big/little CPU frequency topology scanner) |
| `FDE[07]` | `0x2798` | `4,404 B` | `ZoinDecodeAndVerifyFiles` (`komprese_decompress`, APK ZIP EOCD `0x06054B50` + `zlib` raw `inflateInit2_(-15)`, `sched_setaffinity`) |
| `FDE[08]` | `0x38cc` | `136 B` | `ZoinGetThreadLogs` (lock-free `gettid()` lookup in 8-slot `24-byte` ring buffer) |
| `FDE[09]` | `0x3954` | `384 B` | `nCalculateFileCRC` (`open` `O_CLOEXEC=0x80000`, `fstat`, `read`, `CalculateZoinCrc32PlusLength`) |
| `FDE[14]` | `0x3d58` | `96 B` | `ComputeMonotonicNanoseconds` (`clock_gettime(CLOCK_MONOTONIC)` `tv_sec * 0x3B9ACA00 + tv_nsec`) |
| `FDE[17]` | `0x3e84` | `116 B` | `CalculateZoinCrc32PlusLength` (`uint64_t(~crc32) + uint64_t(len)` @ `0x3ec8..0x3ecc`) |
| `FDE[18..53]` | `0x3ef8..0x4120` | `552 B` | Compiler-outlined prologue/epilogue/JNI/syscall helpers (`36` outlined thunks) |
