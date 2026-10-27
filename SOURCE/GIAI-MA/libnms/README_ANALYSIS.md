# Forensic Analysis & Clean-Room C++17 Reconstruction: `libnms.so`
# Phân Tích Pháp Y Nhị Phân & Tái Tạo C++17 Clean-Room: `libnms.so`

## 1. Binary Identity & Metadata / Định Danh & Siêu Dữ Liệu Nhị Phân (`OBSERVED`)

| Property / Thuộc tính | Value / Giá trị |
|---|---|
| **Binary Path** | `SOURCE/apktool-res/lib/arm64-v8a/libnms.so` |
| **File Size** | `293,272 bytes` (`0x47998`) |
| **SHA-256** | `c448eb3aac806f9a69df7ccebcdf3fac2f77a643716bbba2e0aa5ddc40e50890` |
| **Architecture** | `AArch64` (`EM_AARCH64 = 183`, Little-Endian, 64-bit ELF `ET_DYN`) |
| **SONAME** | `libnms.so` |
| **Subsystem** | ByteDance Pangle / PGL Security SDK Native Meta & Anti-Fraud Telemetry Engine (`com.pgl.ssdk.ces.a`) |
| **SDK Version** | `"7.1.0.0.overseas-rc.9-switch"` (decrypted from `.rodata 0x00dd40 ^ 0x00dee0`) |
| **Exported Symbols** | `1` (`JNI_OnLoad` at `0x015074`, `296 bytes`) |
| **Registered JNI Native** | `com.pgl.ssdk.ces.a.meta(ILandroid/content/Context;Ljava/lang/Object;)Ljava/lang/Object;` at `0x038a58` |
| **Java Upcall Callback** | `com.pgl.ssdk.ces.a.njss(ILjava/lang/Object;)Ljava/lang/Object;` invoked from `0x034918` |
| **Reconstructed C++17 Size** | `353,274 bytes` across 9 `.cpp`/`.h` files (`0` stubs) |

---

## 2. ELF Section Layout / Bố Cục Phân Đoạn ELF (`OBSERVED`)

- **`.rodata`** (`0x00b100 .. 0x010be9`, `23,273 bytes`): Contains 185 4-byte-key RC4 ciphertexts, 30+ null-terminated-key XOR ciphertexts, and `"com.pgl.ssdk.ces.a"` at `0x00b152`.
- **`.text`** (`0x014270 .. 0x03def0`, `171,136 bytes`): OLLVM control-flow flattened, opaque-predicated AArch64 machine code with deliberate invalid/SVE words in dead branches.
- **`.plt`** (`0x03def0 .. 0x03e180`, `656 bytes`): 39 imported libc/liblog/libdl stubs.
- **`.data.rel.ro`** (`vaddr 0x042180`, file `0x03e180`, `32,328 bytes`): Relocated tables.
- **`.fini_array`** (`vaddr 0x049fc8`, file `0x045fc8`, `24 bytes`): `[0x014288, 0x014ddc, 0x014270]`.
- **`.init_array`** (`vaddr 0x049fe0`, file `0x045fe0`, `8 bytes`): `[0x01432c]`.
- **`.data`** (`vaddr 0x04e4f0`, file `0x0464f0`, `3,064 bytes`): Stores `R_AARCH64_RELATIVE` MBA-biased pointers at `0x04eea8..0x04eeb0` and `0x04ef70..0x04f0e0`.
- **`.bss`** (`vaddr 0x04f0f0`, `5,268 bytes`): Runtime decrypted strings (`0x04f130`, `0x04f150`, `0x04f160`, `0x050320..0x0504c4`) and the 160-byte unaligned integrity sentinel table at `0x04f6c4`.

---

## 3. Core Obfuscation & Cryptographic Architecture / Kiến Trúc Làm Rối & Mật Mã Cốt Lõi (`OBSERVED`)

### 3.1. Dual String Encryption Engines (`sub_14bd4` & `sub_1bde4` / `sub_1ba38`)
1. **Null-Terminated Key XOR Stream Decryptor (`sub_14bd4` at `0x014bd4..0x014c00`)**:
   - Computes `out[i] = ct[i] ^ key[i]` while `key[i] != 0`, then writes trailing `'\0'`.
   - Used for critical runtime constants: `"arm64"` (`0x00b128 ^ 0x00b14c`), `"meta"` (`0x00b194 ^ 0x00b244`), `"(ILandroid/content/Context;Ljava/lang/Object;)Ljava/lang/Object;"` (`0x00b1a0 ^ 0x00b200`), `"5256"` (`0x00b1e4 ^ 0x00b1ec`), `"7.1.0.0.overseas-rc.9-switch"` (`0x00dd40 ^ 0x00dee0`), `".804c9a5b09dc1e99aefe17dd530290c3"` (`0x00df30 ^ 0x00df70`), AdShow JSON template (`0x00fae0 ^ 0x00fd70`), and SELinux property paths (`0x010850..0x010bb0`).
2. **OLLVM-Flattened RC4 (ARC4) 256-Byte S-Box Stream Cipher (`sub_1ba38` at `0x01ba38..0x01bde4`, wrapped by `sub_1bde4` at `0x01bde4..0x01be54`)**:
   - Allocates `s_box[512]` at `sp+0x120` (`x20`) and `k_box[256]` at `sp+0x20` (`x21`).
   - Uses 13 OLLVM flattened state IDs (`0xBA527277`, `0x75993646`, `0x504D3009`, `0x472F5CB8`, `0x22514940`, `0x6F53FDB6`, `0xFFAFB94C`, `0xE7258560`, `0x523F91AA`, `0x73EAF80B`, `0xB46D15B3`, `0xC53E7034`, `0x5BF71CFC`) to execute standard 256-byte RC4 KSA + PRGA with a 4-byte key.
   - Decrypts 185 strings across `.text`, including `"/proc/self/exe"` (`0x00b100`), `"/proc/%ld/fd/%d"` (`0x00b112`), `"/system/bin/app_process"` (`0x00b12e`), `"njss"` (`0x00fa38`), `"(ILjava/lang/Object;)Ljava/lang/Object;"` (`0x00fa40`), `"38816"` (`0x00fc3f`), and 38 emulator detection file paths (`0x00c9f2..0x00ceb0`).

### 3.2. Mixed Boolean-Arithmetic (MBA) 64-Bit Pointer Deobfuscation (`0x038b04` & `0x03c690`)
$$\text{offset}(X) = \left(\left(\left(\text{0x00A060400A021040} \mid \sim X\right) \ \& \ \text{0x00A061440A061440}\right) + \left(X \ \& \ \text{0x0000010400040400}\right) \mid \text{0x01010104}\right) \oplus K_{\text{xor}}$$
- Because `0x00A060400A021040` and `0x0000010400040400` are bit-disjoint and sum to `0x00A061440A061440`, the inner MBA expression evaluates to `0x00A061440B071544ULL` for `X = 0x038a58` and `X = 0x03c670`.
- For `sub_38a58` (`K_xor = 0xFF5F9EBBF4517B04ULL`): $\text{offset} = \text{0xFFFFFFFFFF566E40ULL}$ (`-0xA991C0`), resolving `.data 0x04eea8`/`0x04eeb0` to `.rodata 0x00fc3f`/`0x00fc44`.
- For `sub_3c670` (`K_xor = 0xFF5F9EBBF47FBB9CULL`): $\text{offset} = \text{0xFFFFFFFFFF78AED8ULL}$ (`-0x875128`), resolving all 47 `.data` slots (`0x04ef70..0x04f0e0`) to `.rodata 0x010850..0x010bb0` and `.bss 0x050358..0x0504c4`.

### 3.3. Shifted Direct AArch64 Syscall Bridge (`sub_3c0bc` at `0x03c0bc..0x03c0ec`)
- Executes `sub x0, x0, #0xe9; mov x8, x0; ...; svc #0`.
- All syscall numbers passed in `w0` are biased by `+0xE9` (`+233`): `0x121 -> 56 (__NR_openat)`, `0x122 -> 57 (__NR_close)`, `0x137 -> 78 (__NR_readlinkat)`, `0x139 -> 80 (__NR_fstat)`, `0x192 -> 169 (__NR_gettimeofday)`, `0x195 -> 172 (__NR_getpid)`, `0x197 -> 174 (__NR_getuid)`, `0x19C -> 179 (__NR_sysinfo)`.
