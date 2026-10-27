# Deep Technical Analysis — `libfdk-aac.so` (Target 105 / 169)

## 1. Binary Identity & ELF64 Anatomy (Định danh Nhị phân & Giải phẫu ELF64)
- **File**: `extracted/arm64-v8a/libfdk-aac.so`
- **Size**: `625,312` bytes (`610.66 KB`)
- **SHA-256**: `723998ce131aa4775f5c75430936ab26287d39d18f14aef3fcc714e28ace5dd2`
- **Architecture**: `AArch64` (`EM_AARCH64`, Little-Endian, Android NDK r21d `clang 9.0.8`)
- **SONAME**: `libfdk-aac.so`
- **Dependencies (`DT_NEEDED`)**: `libm.so`, `libc.so`, `libdl.so`
- **Function Frame Count (`.eh_frame` @ `0x08f1c0`)**: `1,471` FDEs (`26,380` bytes)
- **Exported Dynamic Symbols (`.dynsym`)**: `1,002` exported symbols, `45` imported symbols

| Section | Virtual Address | File Offset | Size (Bytes) | Description |
|---|---|---|---|---|
| `.dynsym` | `0x000248` | `0x000248` | `25,152` | Dynamic Symbol Table (1,002 exports) |
| `.dynstr` | `0x006488` | `0x006488` | `25,686` | Dynamic String Table |
| `.text` | `0x01ccd0` | `0x01ccd0` | `280,980` | Executable AArch64 Machine Code |
| `.rodata` | `0x061964` | `0x061964` | `186,460` | Twiddle, Window, Quantization & SBR Tables |
| `.eh_frame` | `0x08f1c0` | `0x08f1c0` | `26,380` | 1,471 DWARF Call Frame Entries |
| `.data.rel.ro` | `0x096090` | `0x095090` | `11,016` | Relocated Constant Pointers |
| `.data` | `0x099000` | `0x098000` | `1,720` | Initialized Global State |

---

## 2. Exact AArch64 Opcode & Mathematical Verification (Xác minh Mã máy & Toán học)

### 2.1 Memory Allocation Sizing Constants (`0x01cd34 .. 0x01cdcc` & `0x04a0c4 .. 0x04a13c`)
- **`GetRequiredMemAacDecoder` (`0x01cd34`)**: `5297E800` (`mov w0, #0xbf40` = `48,960` bytes), `D65F03C0` (`ret`).
- **`GetRequiredMemAacDecoderStaticChannelInfo` (`0x01cd48`)**: `52922800` (`mov w0, #0x9140` = `37,184` bytes), `D65F03C0` (`ret`).
- **`GetRequiredMemAacDecoderChannelInfo` (`0x01cd78`)**: `5280F800` (`mov w0, #0x7c0` = `1,984` bytes), `D65F03C0` (`ret`).
- **`GetRequiredMemOverlapBuffer` (`0x01cd88`)**: `52A00020` (`mov w0, #0x10000` = `65,536` bytes), `D65F03C0` (`ret`).
- **`GetRequiredMemDrcInfo` (`0x01cd9c`)**: `52800700` (`mov w0, #0x38` = `56` bytes), `D65F03C0` (`ret`).
- **`GetRequiredMemWorkBufferCore2` (`0x01cdcc`)**: `52900200` (`mov w0, #0x8010` = `32,784` bytes), `D65F03C0` (`ret`).
- **`GetRequiredMemSbrDecoder` (`0x04a0c4`)**: `529FA600` (`mov w0, #0xfd30` = `64,816` bytes), `D65F03C0` (`ret`).

### 2.2 Fixed-Point Rounded Multiply (`mul_dbl_sgl_rnd` @ `0x046d6c .. 0x046d8c`)
```assembly
0x046d6c: 12003c08  and  w8, w0, #0xffff
0x046d70: 93403c29  sbfx x9, x1, #0, #16
0x046d74: 5288000a  mov  w10, #0x4000
0x046d78: 1b092908  madd w8, w8, w9, w10
0x046d7c: 93507c0a  asr  x10, x0, #16
0x046d80: 1b097d49  mul  w9, w10, w9
0x046d84: 130f7d08  asr  w8, w8, #15
0x046d88: 0b090500  add  w0, w8, w9, lsl #1
0x046d8c: d65f03c0  ret
```
Computes exact Q31 $\times$ Q15 rounded product:
$$\text{result} = \left(\frac{(\text{op1} \& \text{0xFFFF}) \cdot \text{int16}(\text{op2}) + \text{0x4000}}{2^{15}}\right) + \left(\left\lfloor\frac{\text{op1}}{2^{16}}\right\rfloor \cdot \text{int16}(\text{op2}) \ll 1\right)$$

### 2.3 Bitrate Frame Allocation (`FDKaacEnc_CalcBitsPerFrame` @ `0x028770 .. 0x02879c`)
Combines `sampleRate` (`w2`) and `frameLength` (`w1`) via `orr w9, w2, w1` (`0x2A010049`), counts shared trailing zeros `w8` using `bics wzr, w9, w11`, and computes `((frameLength >> w8) * bitRate) / (sampleRate >> w8)` without 32-bit signed overflow.
