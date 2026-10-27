# Clean-Room Forensics & C++17 Reconstruction: `libterrain.so` (`TASK-136` / `TASK_SO_062_libterrain`)

## 1. Binary Identity & ELF Layout (Định danh Nhị phân & Bố cục ELF)
- **File Name**: `libterrain.so` (ByteDance Cloak / DexVMP Native Dalvik Bytecode Virtual Machine `vmInterpret`, JNI Reflection Cache `cacheInitial`/`getCacheClass`/`gVm`, and Static `libc++abi` Runtime)
- **File Size**: `336,672 bytes` (`336,672 bytes`)
- **SHA-256**: `556d6d47d9643c641668fd79acb937a8651b5b7c78e80da8bb9e07b1171ccd2d`
- **Architecture**: `AArch64 (ELF64 Little-Endian, arm64-v8a, 16KB page-aligned PT_LOAD)`
- **Dependencies (`DT_NEEDED`)**: `liblog.so`, `libm.so`, `libdl.so`, `libc.so`
- **Exported `.dynsym` Symbols**: `310` symbols (`vmInterpret`, `cacheInitial`, `getCacheClass`, `gVm`, plus `306` C++ ABI / exception / RTTI symbols)
- **Unwind `.eh_frame_hdr` FDEs**: `1,034` functions (`0x0122e0 .. 0x03f52f`)

| Section | Virtual Address (`VA`) | File Offset | Size (Bytes) | Role (EN / VN) |
|---|---:|---:|---:|---|
| `.text` | `0x0122e0` | `0x0122e0` | `184,912` | Executable AArch64 instructions / Mã máy thực thi AArch64 |
| `.rodata` | `0x03f530` | `0x03f530` | `12,937` | 35 XOR-encrypted strings & keys, `getCacheClass` jump table, NEON shifts |
| `.eh_frame_hdr` | `0x0427bc` | `0x0427bc` | `8,284` | `1,034` binary-search FDE unwind entries / Bảng tháo ngăn xếp 1.034 hàm |
| `.fini_array` | `0x050c08` | `0x04cc08` | `16` | 2 global destructors / Hàm hủy toàn cục |
| `.data.rel.ro` | `0x050c18` | `0x04cc18` | `12,040` | `libc++abi` exception/RTTI vtables & typeinfo |
| `.data` | `0x054000` | `0x050000` | `6,656` | 256-entry VM opcode handler table (`0x054000..0x054800`) + MBA-shifted pointers (`0x055900..0x0559f8`) |
| `.bss` | `0x055a00` | `0x051a00` | `2,448` | Decoded string cache (`0x055a00..0x055ef0`), `gVm` (`0x055b80`, `96 B`), JNI class cache (`0x055bf8..0x055ed8`) |

---

## 2. Key Mathematical & Binary Proofs (Bằng chứng Toán học & Nhị phân Cốt lõi)
1. **Mixed Boolean-Arithmetic (MBA) Pointer Deobfuscation (`0x013700 .. 0x013774`)**:
   - From anchor `x13 = 0x0135AC`, computes:
     $$\Delta_{\text{MBA}} = \Big(\big((\texttt{0x00A060400A021040} \mid \sim x_{13}) \ \& \ \texttt{0x00A061440A061440}\big) + \big((x_{13} \ \& \ \texttt{0x0000010400040400}) \mid \texttt{0x01010104}\big)\Big) \oplus \texttt{0xFF5F9EBBF47538A4} = \texttt{0xFFFFFFFFFF722DE0} = -\texttt{0x008DD220}$$
   - Adding $\Delta_{\text{MBA}}$ to `.data 0x0559d8` (`0x0000000000931228`) yields `0x054008`, the exact base of the 255 Dalvik threaded-code opcode handlers in `.data 0x054008 .. 0x054800`!
2. **MBA XOR String Encryption (`DecodeXorString_012fd8` at `0x012fd8`, `0x01cb30`, `0x027678`)**:
   - Evaluates `(enc[i] | key[i]) - (enc[i] & key[i]) == enc[i] ^ key[i]` (`0x012fe8: 0x2A09016C orr w12, w11, w9; 0x012fec: 0x0A090169 and w9, w11, w9; 0x012ff0: 0x4B090189 sub w9, w12, w9`) across all 35 `.rodata` string pairs (`"length=%d; index=%d"`, `"bad packed switch magic"`, `"bad sparse switch magic"`, `"bad array data magic"`, `"divide by zero"`, `"java/lang/Boolean"`..`"java/lang/RuntimeException"`, `"TYPE"`, `"Ljava/lang/Class;"`).
3. **Dalvik Switch & Array Payload Handlers (`0x013010 .. 0x01337c`)**:
   - `HandlePackedSwitch_013010`: checks `ident == 0x0100` (`0x013060: 0x7104011F cmp w8, #0x100`) and computes `idx = (key ^ first_key) - ((~key & first_key) << 1)`.
   - `HandleSparseSwitch_0130bc`: checks `ident == 0x0200` (`0x01310c: 0x7108011F cmp w8, #0x200`) and binary-searches sorted keys using MBA midpoint `(((low | high) << 1) - (low ^ high)) >> 1`.
   - `HandleFillArrayData_0131b4`: checks `ident == 0x0300` (`0x0131e8: 0x710C011F cmp w8, #0x300`) and dispatches element widths `(1, 2, 4, 8)` via `.rodata 0x03f614`.
4. **JNI Class Cache (`cacheInitial` at `0x02673c` & `getCacheClass` at `0x0275ec`)**:
   - `getCacheClass` subtracts `'B'` (`0x42`) from `desc[0]` (`0x0275f4: 0x51010908 sub w8, w8, #0x42`), checks `idx <= 0x18` (`'Z' - 'B' = 24`), and indexes `.rodata 0x03fde4` (`kGetCacheClassJumpOffsets_03fde4[25]`) to return the 8 cached primitive `TYPE` classes at `.bss 0x055bf8 .. 0x055cd8`.
