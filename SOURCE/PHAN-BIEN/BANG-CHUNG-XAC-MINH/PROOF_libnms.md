# Adversarial Verification Proof: `libnms.so` (`TASK-131-RECONSTRUCTION-LIBNMS` / `TASK_SO_116_libnms`)
# Bằng Chứng Xác Minh Đối Kháng: `libnms.so` (`TASK-131-RECONSTRUCTION-LIBNMS` / `TASK_SO_116_libnms`)

## 1. Binary & Reconstruction Summary / Tóm Tắt Nhị Phân & Tái Tạo

- **Target Binary**: `SOURCE/apktool-res/lib/arm64-v8a/libnms.so` (`293,272 bytes`, SHA-256: `c448eb3aac806f9a69df7ccebcdf3fac2f77a643716bbba2e0aa5ddc40e50890`)
- **Subsystem**: ByteDance Pangle / PGL Security SDK Native Meta Engine (`com.pgl.ssdk.ces.a`, version `"7.1.0.0.overseas-rc.9-switch"`)
- **Reconstructed C++17 Code**: `353,274 bytes` across 9 `.cpp`/`.h` files in `SOURCE/GIAI-MA/libnms/` (`0` stubs)
- **Verified AArch64 Opcodes**: `2,480` exact 32-bit instructions extracted from `.text` (`0x014270..0x03cc00`)

---

## 2. Mathematical & Cryptographic Proofs / Chứng Minh Toán Học & Mật Mã

1. **64-Bit MBA ASLR Pointer Deobfuscation (`0x038b04..0x038b74` & `0x03c690..0x03c700`)**:
   - Uses bit-disjoint masks `kMask1 = 0x00A060400A021040ULL` and `kMask3 = 0x0000010400040400ULL` (`kMask1 | kMask3 == kMask2 = 0x00A061440A061440ULL`).
   - Resolves `.data 0x04eea8`/`0x04eeb0` via offset `-0xA991C0` (`0xFFFFFFFFFF566E40ULL`) to `.rodata 0x00fc3f`/`0x00fc44` (`"38816"`), and `.data 0x04ef70..0x04f0e0` (47 slots) via offset `-0x875128` (`0xFFFFFFFFFF78AED8ULL`) to `.rodata 0x010850..0x010bb0` and `.bss 0x050358..0x0504c4`.
2. **OLLVM-Flattened RC4 (`sub_1ba38` at `0x01ba38..0x01bde4`) & Null-Key XOR (`sub_14bd4` at `0x014bd4..0x014c00`)**:
   - Verified across all 185 RC4 call sites and 30 XOR entries in `.rodata` (`0x00b100..0x010be9`).
3. **OLLVM Quadratic Non-Residue Mod-7 & Mod-19 Opaque Predicates**:
   - Proven invariant via Euler's criterion ($-1$ is a quadratic non-residue modulo $7$ and $19$) using magic reciprocals `0x24924925` (`div 7`) and `0xAF286BCB` (`div 19`).
4. **Shifted Direct AArch64 Syscall Bridge (`sub_3c0bc` at `0x03c0bc..0x03c0ec`)**:
   - Subtracts `0xE9` (`233`) from `w0` before `svc #0` (`0x121 -> 56 openat`, `0x122 -> 57 close`, `0x137 -> 78 readlinkat`, `0x139 -> 80 fstat`, `0x192 -> 169 gettimeofday`, `0x195 -> 172 getpid`, `0x197 -> 174 getuid`, `0x19C -> 179 sysinfo`).
