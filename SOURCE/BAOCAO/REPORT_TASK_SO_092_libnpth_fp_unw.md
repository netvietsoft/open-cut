# Clean-Room Forensic Analysis & C++17 Reconstruction: `libnpth_fp_unw.so`
## Phân Tích Pháp Y Nhị Phân & Tái Tạo C++17 Sạch: `libnpth_fp_unw.so`

- **Task ID**: `TASK-163-RECONSTRUCTION-LIBNPTH-FP-UNW` (`TASK_SO_092_libnpth_fp_unw`) — Target 124 / 169
- **Binary Size / Kích thước nhị phân**: `6,112 bytes` (`0x17e0` bytes)
- **SHA-256**: `30e06928f2338ea69825e5b6726f2e390e52cc84a9d96cc37ce3f7f8b75487b1`
- **Unwind FDEs**: `9` FDEs at `.eh_frame_hdr` (`0x000820..0x000874`)
- **Exported Symbols**: `3` (`npth_fp_frames` @ `0x09e0`, `npth_fp_format` @ `0x0abc`, `npth_fp_fast` @ `0x0d14`)
- **Reconstructed C++17 Volume**: `137,989 bytes` across 5 files (`0` stubs)

## Key Binary Forensics (Bằng Chứng Nhị Phân Trực Tiếp)
1. **`npth_fp_frames` (`0x0009e0..0x000abc`, `220 B`)**:
   - Clamps `max_frames` to `128` (`0x80` @ `0x09f8..0x0a08: mov w9, #0x80; cmp x1, #0x80; csel x21, x1, x9, lo`).
   - Queries `sigaltstack(nullptr, &ss)` (`0x0a18`) and walks the AArch64 `x29` frame-pointer chain:
     - Return address `lr = *(uintptr_t*)(fp + 8)` (`ldr x11, [x10, #8]` @ `0x0a34`), stored into `out_frames[count]` (`str x11, [x19, x0, lsl #3]` @ `0x0a38`).
     - If `count == 128` (`0x80` @ `0x0a3c`), returns `129` (`0x81` @ `0x0a88`).
     - Checks canonical 40-bit user space (`0x0000000000100000 .. 0x000000FFFFFFFFFF` via `add x12, x11, #-0x10000000000; cmp x12, #-0xffffffffff` @ `0x0a48..0x0a4c` and `and x12, x11, #0xfffff00000` @ `0x0a54`).
     - Checks same-stack 64 KB locality (`eor x12, x11, x29; tst x12, #0xffffff0000` @ `0x0a60..0x0a64`), minimum 16-byte upward progression (`add x10, x10, #0x10; cmp x11, x10` @ `0x0a6c..0x0a70`), and 8-byte alignment (`and x12, x11, #7` @ `0x0a78`).
2. **`npth_fp_format` (`0x000abc..0x000c78`, `444 B`) & `sub_c78` (`0x000c78..0x000d14`, `156 B`)**:
   - Allocates `clamped_count << 10` (`1,024 B` per frame @ `0x0b04`), resolves each PC via `dladdr(pc, &dl_info)` (`0x0b60`), and formats using the 4 `.rodata` templates at `0x0790..0x081e`.
3. **`npth_fp_fast` (`0x000d14..0x000d80`, `108 B`)**:
   - Zeroes stack buffer via NEON `movi v0.2d, #0; stp q0, q0, [sp, #0..#0x60]` (`0x0d2c..0x0d48`), calls `npth_fp_frames(frames, 128)` (`0x0d4c`), and returns `npth_fp_format(frames, count)` (`0x0d58`).
