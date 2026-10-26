# Adversarial Proof Dossier — `libpl_droidsonroids_gif.so`
# Hồ Sơ Bằng Chứng Đối Kháng — `libpl_droidsonroids_gif.so`

> **Challenge Answered / Phản hồi thách thức**: `CHALLENGE_libpl_droidsonroids_gif.md`  
> **Task ID**: `TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF` (`TASK_SO_039_libpl_droidsonroids_gif`)  
> **Target Binary**: `libpl_droidsonroids_gif.so` (`42,464 bytes`, ELF64 AArch64, `97` `.dynsym` entries)  
> **Verdict**: `VERIFIED_AND_ACCEPTED`

---

## 1. AArch64 Opcode & Struct ABI Proofs (Bằng Chứng Opcode & Struct ABI)

1. **`DGifOpen` (`0x0066a8..0x0067f8`) — `GifFileType` (`0x78 B`) & `GifFilePrivateType` (`0x6160 B`)**:
   - `0x0066d0: mov w0, #1; mov w1, #0x78; bl calloc (0x9770)` $\rightarrow$ `sizeof(GifFileType) = 120 bytes`.
   - `0x0066ec: mov w0, #1; mov w1, #0x6160; bl calloc (0x9770)` $\rightarrow$ `sizeof(GifFilePrivateType) = 24,928 bytes`.
   - `0x006724: ldrh w8, [sp]; mov w10, #0x4947; ldrb w9, [sp, #2]; cmp w8, w10; mov w8, #0x46; ccmp w9, w8, #0, eq` $\rightarrow$ verifies `"GIF"` (`0x47, 0x49, 0x46`), setting `D_GIF_ERR_NOT_GIF_FILE = 103 (0x67)` on mismatch.

2. **`DGifGetLine` (`0x006e4c..0x007544`) — NEON Reverse-Stack Burst & LZW Bitmask Table**:
   - Loads `kCodeMasks[RunningBits]` from `.rodata` `0x002b70` (`0x00717c: ldrh w11, [x23, x9, lsl #1]`).
   - Vectorizes the reverse-order LZW stack pop (`priv->Stack[--stackPtr]`) into 32-byte AArch64 NEON burst transfers (`0x007480..0x0074a4` and `0x0074f8..0x00751c`):
     ```assembly
     0x007480: ldp   q1, q0, [x9, #-0x10]
     0x00748c: rev64 v1.16b, v1.16b
     0x007490: rev64 v0.16b, v0.16b
     0x007494: ext   v1.16b, v1.16b, v1.16b, #8
     0x007498: ext   v0.16b, v0.16b, v0.16b, #8
     0x00749c: stp   q0, q1, [x12, #-0x10]
     ```

3. **`getRealTime` (`0x009610..0x009680`) & `calculateInvalidationDelay` (`0x009548..0x00960c`) — Fixed-Point Reciprocal Division**:
   - Uses `0x431bde82d7b634db` ($\lceil 2^{82} / 10^6 \rceil$) with `smulh` and `asr #18` to divide `tv_nsec` by $1,000,000$:
     ```assembly
     0x00964c: mov   x10, #0x34db
     0x009650: movk  x10, #0xd7b6, lsl #16
     0x009654: movk  x10, #0xde82, lsl #32
     0x009658: movk  x10, #0x431b, lsl #48
     0x00965c: smulh x9, x9, x10
     0x009660: mov   w10, #0x3e8
     0x009664: asr   x11, x9, #0x12
     0x009668: add   x9, x11, x9, lsr #63
     0x00966c: madd  x0, x8, x10, x9
     ```
