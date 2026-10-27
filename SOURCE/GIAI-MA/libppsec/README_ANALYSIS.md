# Clean-Room Forensics & Reconstruction Report: `libppsec.so` (`TASK_SO_058_libppsec`)

> **Báo cáo Giải mã & Tái tạo Sạch**: `libppsec.so` (ByteDance PIPO Payment Security SDK `2.0.3`, Environment Risk Collector `1.2.7`)  
> **Binary Path / Đường dẫn nhị phân**: `SOURCE/apktool-res/lib/arm64-v8a/libppsec.so`  
> **Size / Dung lượng**: `166,400 bytes` (`0x28a00`)  
> **SHA-256**: `1815ed63470ca5e5f251f66730ca849e01ed3d1ccdbde9cb162e96d2ccfa7f2f`

---

## 1. Binary Architecture & ELF Section Layout / Kiến trúc Nhị phân & Bố cục ELF (`[OBSERVED]`)

| Section | Virtual Address (`VMA`) | File Offset | Size (Bytes) | Role / Vai trò |
|---|---|---|---|---|
| `.text` | `0x002a10 .. 0x01c914` | `0x002a10` | `106,244` | 26,561 AArch64 instructions (OLLVM-protected JNI, `BPEM` Crypto, Risk Scanner) |
| `.rodata` | `0x01c920 .. 0x024df9` | `0x01c920` | `34,009` | Pairwise-XOR encrypted string pools, AES S-Box (`0x01d048`), MD5 IV (`0x0214a0`), Default 344B RSA Key (`0x0214c0`), CRC-16 Table (`0x0243d2`) |
| `.init_array` | `0x02b6e8 .. 0x02b6f8` | `0x0276e8` | `16` | 2 static constructors: `0x002a10` (RSA key + Kid `"0"`) and `0x0185fc` (Packet seed + `atoi("19572")`) |
| `.fini_array` | `0x02b6f8 .. 0x02b708` | `0x0276f8` | `16` | 2 static destructors: `0x002abc` and `0x002aac` |
| `.data.rel.ro` | `0x02b708 .. 0x02bbd0` | `0x027708` | `1,224` | OLLVM indirect branch target pointer tables & vtables |
| `.data` | `0x02c000 .. 0x02c158` | `0x028000` | `344` | `JNINativeMethod` tables (`0x02c000` for `IlIlllIiI`, `0x02c0d0` for `CryptTool`) & Region Host table (`0x02c138`) |
| `.bss` | `0x02c160 .. 0x02f940` | `0x028158` | `14,304` | Decrypted string buffers, `JavaVM*` (`0x02c9d8`), RSA key (`0x02c9e0`), Kid (`0x02c9f8`), Session state (`0x02ca10..0x02ca70`) |

---

## 2. Dynamic JNI Registration & Native Method Tables / Bảng Đăng ký Phương thức JNI (`[OBSERVED]`)

- **`JNI_OnLoad` (`0x003188` -> `0x002dbc..0x003180`)**:
  - Stores `JavaVM*` at `.bss 0x02c9d8` (`0x002e44: str x19, [x8, #0x9d8]`).
  - Calls `sub_1b034` (`0x01b034`: `(*vm)->GetEnv(vm, &env, 0x00010004)`).
  - Calls `sub_2ae8(env)` (`0x002ae8`), which invokes `sub_2b24(env)` (`0x002b24`) and `sub_11584(env)` (`0x011584`).
  - Calls `sub_1a5d0(env)` (`0x01a5d0`), resolving static Java callback `com/bytedance/pipo/sec/IlIlllIiI.IlIllLIiL(Ljava/lang/String;)Ljava/lang/String;`.
  - Returns `JNI_VERSION_1_4` (`0x00010004` at `0x003178: mov w0, #4; 0x00317c: movk w0, #1, lsl #16`).

### 2.1 Class 1: `com/bytedance/pipo/sec/IlIlllIiI` (`.data 0x02c000..0x02c08f`, `mov w3, #6` at `0x002d88`)

| Index | `.data` VMA | Method Name | JNI Signature | Native Function VMA | Core Implementation VMA |
|---|---|---|---|---|---|
| 0 | `0x02c000` | `IlIllLIiI` | `(Ljava/lang/String;IZ)V` | `0x00318c` | `0x00fd80` (`initAppIdAndRegion`) |
| 1 | `0x02c018` | `IlIllLIiI` | `(Ljava/lang/String;Ljava/lang/String;)V` | `0x003560` | `0x010514` (`setDeviceAndInstallId`) |
| 2 | `0x02c030` | `IlIllLIiII` | `(Ljava/lang/String;Ljava/lang/String;)V` | `0x003960` | `0x00f674` (`setCustomRsaKeyAndKid`) |
| 3 | `0x02c048` | `IlIllLIiI` | `(Ljava/lang/String;)V` | `0x003f2c` | `0x010fb8` (`reportRiskEvent`) |
| 4 | `0x02c060` | `IlIllLIiI` | `()Ljava/lang/String;` | `0x004288` | `0x0110f4` (`getSecurityToken`) |
| 5 | `0x02c078` | `IlIllLIiII` | `(Ljava/lang/String;)V` | `0x004408` | `0x0109bc` (`updateDidOrHost`) |

### 2.2 Class 2: `com/bytedance/pipo/sec/CryptTool` (`.data 0x02c0d0..0x02c117`, `mov w3, #3` at `0x0115dc`)

| Index | `.data` VMA | Method Name | JNI Signature | Native Function VMA | Core Implementation VMA |
|---|---|---|---|---|---|
| 0 | `0x02c0d0` | `encrypt` | `([B)[B` | `0x0115ec` | `0x0111a0` -> `0x00f32c` -> `0x004744` (`PpsecBpemEncrypt`) |
| 1 | `0x02c0e8` | `decrypt` | `([B)[B` | `0x0117a0` | `0x0112d0` -> `0x00f37c` -> `0x005810` (`PpsecBpemDecrypt`) |
| 2 | `0x02c100` | `getKid` | `()Ljava/lang/String;` | `0x011948` | `0x0113d8` (`PpsecGetActiveKid`) |

---

## 3. OLLVM / Tigress Opaque Predicates & Pairwise-XOR Deobfuscator / Giải mã OLLVM & Chuỗi XOR (`[OBSERVED]`)

1. **Pairwise Byte-Array XOR Decryptor (`sub_4714` at `0x004714..0x004740`)**:
   - Invoked 183 times across `.text` to decrypt strings from `.rodata` into `.bss`:
     `dst[i] = src[i] ^ key[i]` while `key[i] != 0`.
2. **Quadratic Modular Inverse Opaque Predicate (`0x002b40..0x002b70`, `0x002dd4..0x002e08`)**:
   - Evaluates `((x * x + 1) * 0xA1AF286CU) == 0x0D79435EU` ($\pmod{2^{32}}$) for `x = 0x1A0` (`416`), which is identically `true`.
3. **Bitwise-Transformed Quadratic Opaque Predicate (`0x0031ac..0x00320c`)**:
   - Evaluates `(((8 * x^2 | 8) - (4 * x^2 ^ 4)) * 0x286BCA1BU) == 0x0D79435EU` ($\pmod{2^{32}}$), utilizing $(8x^2 \lor 8) - (4x^2 \oplus 4) = 4(x^2 + 1)$ and $4 \times \text{0x286BCA1B} \equiv \text{0xA1AF286C} \pmod{2^{32}}$.
4. **3-Consecutive-Integers Divisibility by 6 (`0x002ee0..0x002f14`, `0x003218..0x00325c`)**:
   - Computes $p = n(n+1)(n+2)$ and $q = \text{umulh}(p, \text{0xAAAAAAAAAAAAAAAB}) \gg 1 = \lfloor p/3 \rfloor$, verifying $p - 3(q \land \sim 1) = 0$.
5. **Mixed Boolean-Arithmetic (MBA) in CRC-16/XMODEM (`0x018948..0x0189a0`)**:
   - Uses `.rodata 0x0243d2` (256-entry CRC-16/XMODEM lookup table: `0x0000, 0x1021, 0x2042, 0x3063...`), MBA XOR `(a | b) - (a & b)` (`0x018984..0x01898c`), and MBA loop increment `((i << 1) | 2) - (i ^ 1)` (`0x018968..0x01897c`).
