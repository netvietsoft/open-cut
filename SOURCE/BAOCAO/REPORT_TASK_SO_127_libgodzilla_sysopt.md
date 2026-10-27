# Reconstruction Report: `libgodzilla-sysopt.so` (`TASK_SO_127_libgodzilla_sysopt`)
# Báo Cáo Tái Tạo Sạch: `libgodzilla-sysopt.so` (`TASK_SO_127_libgodzilla_sysopt`)

- **Status**: `RECONSTRUCTED_AND_VERIFIED` (`100%`)
- **Governance Task ID**: `TASK-116-RECONSTRUCTION-LIBGODZILLA_SYSOPT`
- **Binary Size**: `164,440 bytes` (`SHA-256: 28605f81e2c8d9d0fae96d52a70efc5192c90d93377ddadff09726874911d704`)
- **Exported JNI Functions**: `10` (`IvimageOpt`, `UbsanOpt`, `PthreadCreateHook`, `ThreadHook`, `ApkSha256`)

## Key Reconstructed Subsystems / Các Phân Hệ Đã Tái Tạo
1. **ELF64 `.note.gnu.build-id` Inspector (`0x007d30..0x008060`)**: Verifies `e_shnum < 0x41`, scans `SHT_NOTE (7)` sections for `".note.gnu.build-id\0"`, allocates `(n_descsz << 1) | 1` bytes, and formats lowercase hex.
2. **Pthread Stack Size Optimizer & xHook Engine (`0x008248..0x00aa38`)**: Overrides `libart.so` `pthread_attr_setstacksize` with `.data 0x02f7c8` (`0x00083000 = 536,576 B`) and caches `sysconf(_SC_PAGESIZE = 0x28)` at `.bss 0x02f9c8`.
3. **SIGBUS `BUS_ADRERR` 3-Retry TLS Guard (`0x00aa3c..0x00abd8`)**: Installs `sigaction(SIGBUS = 7)` with `sa_flags = 0x18000004` (`SA_SIGINFO | SA_ONSTACK | SA_RESTART`) and tracks per-thread faulting `si_addr` up to 3 retries.
4. **Direct-Syscall APK PKCS#7 Certificate Extractor & SHA-256 (`0x00abdc..0x0195ec`)**: Invokes `svc #0` at `0x01789c` (`__NR_openat=56`, `__NR_close=57`, `__NR_lseek=62`, `__NR_read=63`), parses ZIP EOCD/CD/LFH and ASN.1 DER PKCS#7 SignedData, and hashes the X.509 certificate via SHA-256 (`.rodata 0x005270`, `0x005308`).
5. **12 MBA Rolling-XOR Hook Keywords & >39-Bit VMA Scanner (`0x019fb4..0x022878`)**: Deobfuscates `sandhook`, `epic`, `frida`, `xposed`, `edxposed`, `lsposed`, `substrate`, `cydia`, `riru`, `zygisk`, `dexposed`, `houdini` via `(c + k) - ((c & k) << 1)` and checks `((end & 0xffffff8000000000) | ((start >> 39) & 0x1ffffff)) != 0`.
