# Architectural & Binary Forensics Analysis: `libgodzilla-sysopt.so`
# Phân Tích Kiến Trúc & Pháp Y Nhị Phân: `libgodzilla-sysopt.so`

## 1. Binary Identity & ELF Layout / Định Danh Nhị Phân & Bố Cục ELF (`[OBSERVED]`)

| Property / Thuộc tính | Value / Giá trị (`[OBSERVED]`) |
|---|---|
| **Binary Path** | `SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so` |
| **File Size** | `164,440 bytes` (`0x28258`) |
| **SHA-256** | `28605f81e2c8d9d0fae96d52a70efc5192c90d93377ddadff09726874911d704` |
| **Architecture** | `AArch64` (`EM_AARCH64 = 183`, Little-Endian, 64-bit ELF) |
| **SONAME** | `libgodzilla-sysopt.so` |
| **Dependencies (`DT_NEEDED`)** | `liblog.so`, `libz.so`, `libm.so`, `libdl.so`, `libc.so` |
| **`.rodata`** | VMA `0x003ec0..0x0059a8` (`6,888 bytes`, file offset `0x003ec0`) |
| **`.text`** | VMA `0x007ce0..0x026980` (`126,112 bytes`, file offset `0x007ce0`) |
| **`.data.rel.ro`** | VMA `0x02af20..0x02b290` (`880 bytes`, file offset `0x026f20`) |
| **`.init_array`** | VMA `0x02b290..0x02b298` (`8 bytes`, file offset `0x027290` -> `0x0082ec`) |
| **`.data`** | VMA `0x02f7c8..0x02f9c8` (`512 bytes`, file offset `0x0277c8`) |
| **`.bss`** | VMA `0x02f9c8..0x0304a0` (`2,776 bytes`) |

---

## 2. Exported JNI Surface (10 Exports Across 5 Java Classes) / Bề Mặt 10 Hàm Xuất JNI (`[OBSERVED]`)

| # | VMA | Size | Exported JNI Symbol | Reconstructed Behavior |
|---|---|---|---|---|
| 1 | `0x00819c` | `84 B` | `Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_start` | Logs `"register ivimage optimize"` (`0x003f35`) under `"GODZILLA"` (`0x004f87`), calls `getElfBuildId("/system/lib/libIVImageSR.so")` (`0x007d30`). |
| 2 | `0x0081f0` | `4 B` | `Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_end` | Shared 4-byte `ret` (`c0035fd6`). |
| 3 | `0x0081f4` | `84 B` | `Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_start` | Logs `"register ubsan optimize"` (`0x0046b3`), calls `getElfBuildId("/system/lib/libbinder.so")` (`0x007d30`). |
| 4 | `0x0081f0` | `4 B` | `Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_end` | Shared 4-byte `ret` (`c0035fd6`). |
| 5 | `0x008254` | `152 B` | `Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_start` | Updates `.data 0x02f7c8` (`default = 0x00083000 = 536,576 B`) if `stack_size >= 1`, enables xHook debug & `SIGSEGV` protection, registers PLT hook on `"libart.so"` -> `"pthread_attr_setstacksize"` -> `0x008248`, calls `xhook_refresh(0)`. |
| 6 | `0x0081f0` | `4 B` | `Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_end` | Shared 4-byte `ret` (`c0035fd6`). |
| 7 | `0x00aa3c` | `160 B` | `Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_start` | Logs `"thread start SIGBUS"` (`0x0041f3`, tag `"pyt123"` @ `0x0046ea`), locks mutex at `.bss 0x02fbf8`, creates 2 TLS keys (`.bss 0x02fbac`, `0x02fbb0`), installs `sigaction(SIGBUS = 7)` with `sa_flags = 0x18000004` (`SA_SIGINFO \| SA_ONSTACK \| SA_RESTART`) and handler `0x00aaf4`. |
| 8 | `0x00aadc` | `24 B` | `Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_end` | Logs `"thread end"` (`0x004fb2`, tag `"pyt123"` @ `0x0046ea`). |
| 9 | `0x017978` | `1,916 B` | `Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkMyShit` | Resolves APK path from `/proc/self/maps` via `.data 0x02f8a0` (`0x0141ec`), extracts X.509 certificate from `META-INF/*.RSA\|DSA\|EC` via `.data 0x02f900` (`0x00afcc`), returns 64-char SHA-256 `jstring`. |
| 10 | `0x0180f4` | `408 B` | `Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkHookFrameworks` | Calls `.data 0x02f940` (`0x019fb4` `scanMapsForHookFrameworks`) and returns matching `/proc/self/maps` line, `"use_more_than_39_bits"`, or `""`. |

---

## 3. Core Subsystem Forensics & Mathematical Proofs / Pháp Y Phân Hệ & Chứng Minh Toán Học (`[OBSERVED]`)

### 3.1 ELF `.note.gnu.build-id` Inspector (`0x007d30..0x008060`)
- Opens the target shared library with `O_RDONLY | O_CLOEXEC` (`mov w2, #0x80000` at `0x007e18`).
- Reads the 64-byte `Elf64_Ehdr`, verifies `e_shnum < 0x41` (`cmp w20, #0x41; b.hs #0x80a0` at `0x007e64..0x007e68`), and computes the section header table size via `lsl x22, x20, #6` (`e_shnum * 64` at `0x007ea4`).
- Matches `sh_type == 7` (`SHT_NOTE` at `0x007ec4`) and compares the 19-byte section name `".note.gnu.build-id\0"` using 3 unaligned 64-bit loads (`0x6e672e65746f6e2e`, `0x2d646c6975622e75`, `0x0064692d646c6975` at `0x007ed0..0x007f0c`).
- Reads `Elf64_Nhdr` (`12 B`), validates `0 < n_descsz <= 0x40` (`sub x8, x22, #1; cmp x8, #0x40` at `0x007fd4..0x007fd8`), allocates `(n_descsz << 1) | 1` bytes via `mov w0, #1; bfi x0, x22, #1, #0x20` (`0x007fe4..0x007fe8`), seeks to `sh_offset + 12 + ((n_namesz + 3) & ~3)` (`0x008004..0x008010`), and formats lowercase hex via `"%02hhx"`.

### 3.2 OLLVM/Tigress Opaque Predicates & Mixed Boolean-Arithmetic (MBA) Rolling-XOR (`0x01b18c..0x022684`)
Every protected function references a 20-byte parameter block in `.data` (e.g., `0x02f988`, `0x02f99c`) containing `(p0, p1, p2, p3, p4) = (9, 8, 1, 7, 3)`:
$$\text{IntQuotientDelta} = \left\lfloor \frac{p_0 + 7}{p_1} \right\rfloor - p_2 = \left\lfloor \frac{9 + 7}{8} \right\rfloor - 1 = 1$$
$$\text{FmaScale} = \bigl(p_4 \cdot (-2.0) + p_3\bigr) \cdot \text{IntQuotientDelta} = \bigl(3.0 \cdot (-2.0) + 7.0\bigr) \cdot 1.0 = 1.0$$

At `0x01b238..0x01b244`, the 12 hook framework keywords are decrypted on the stack using the Mixed Boolean-Arithmetic (MBA) XOR identity:
$$c_i \oplus k_i = (c_i + k_i) - 2(c_i \mathbin{\&} k_i), \quad k_i = (\text{base} + i) \bmod 256$$

| # | Init VMA | Base Key | Encrypted Hex Bytes (`[OBSERVED]`) | Decrypted Keyword |
|---|---|---|---|---|
| 1 | `0x022108` | `0x87` | `f4 e9 e7 ee e3 e3 e2 e5 8f` | `"sandhook"` |
| 2 | `0x01ba70` | `0x88` | `ed f9 e3 e8 8c` | `"epic"` |
| 3 | `0x01c330` | `0x89` | `ef f8 e2 e8 ec 8e` | `"frida"` |
| 4 | `0x01cbf8` | `0x8b` | `f3 fc e2 fd ea f4 91` | `"xposed"` |
| 5 | `0x02233c` | `0x8c` | `e9 e9 f6 ff ff e2 f7 f7 94` | `"edxposed"` |
| 6 | `0x022404` | `0x8d` | `e1 fd ff ff e2 f7 f7 94` | `"lsposed"` |
| 7 | `0x0224d0` | `0x8e` | `fd fa f2 e2 e6 e1 f5 e1 f3 97` | `"substrate"` |
| 8 | `0x01ef58` | `0x8f` | `ec e9 f5 fb f2 94` | `"cydia"` |
| 9 | `0x01f86c` | `0x90` | `e2 f8 e0 e6 94` | `"riru"` |
| 10 | `0x02017c` | `0x92` | `e8 ea f3 fc e5 fc 98` | `"zygisk"` |
| 11 | `0x0225a0` | `0x93` | `f7 f1 ed e6 f8 eb fc fe 9b` | `"dexposed"` |
| 12 | `0x02266c` | `0x94` | `fc fa e3 f3 f1 f7 f3 9b` | `"houdini"` |

### 3.3 >39-Bit VMA Detector (`0x01a438..0x01a458`)
At `0x01a448..0x01a458`, `scanMapsForHookFrameworks` checks whether any `/proc/self/maps` VMA range `[start_addr, end_addr]` exceeds Android's standard 39-bit user-space virtual address layout (`512 GB`):
```asm
0x01a448: 29615992  and   x9, x9, #0xffffff8000000000
0x01a450: 09fd67b3  bfxil x9, x8, #0x27, #0x19
0x01a458: 3f0100f1  cmp   x9, #0
```
If non-zero, it logs `"More than 39 bits in maps"` (`0x00448d`) and returns `"use_more_than_39_bits"` (`0x003fb9`).
