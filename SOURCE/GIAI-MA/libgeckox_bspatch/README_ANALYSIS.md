# Clean-Room Reconstruction Analysis: `libgeckox_bspatch.so`
# Phân Tích Tái Tạo Phòng Sạch: `libgeckox_bspatch.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libgeckox_bspatch.so`
- **Task ID**: `TASK-195-RECONSTRUCTION-LIBGECKOX-BSPATCH` (`TASK_SO_132_libgeckox_bspatch`)
- **Size**: `119,768` bytes
- **SHA-256**: `caa28254b54a76d8eef6089da0bc101ca994f1129870a001ff3b9e2bea6045d8`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libgeckox_bspatch.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.plt`: `0x02690` (`1,184` bytes)
- `.text`: `0x02b30 .. 0x14ce8` (`74,168` bytes = `18,542` AArch64 instructions)
- `.rodata`: `0x14cf0` (`9,452` bytes — `BSDIFF40`, `BZIP2`, `BZ2_crc32Table`, `BZ2_rNums`)
- `.eh_frame_hdr`: `0x171dc` (`532` bytes, `65` sorted FDE entries)
- `.eh_frame`: `0x173f0` (`2,536` bytes)
- `.data.rel.ro`: `0x1fa50` (`136` bytes)
- `.data`: `0x20000` (`3,136` bytes)
- `.bss`: `0x20c40` (`4,336` bytes)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **BSDIFF40 Sign-Magnitude 64-Bit Integer Decoding (`offtin`) & Patch Application (`main` @ `0x02b6c`)**:
   - Reads the 32-byte `BSDIFF40` header (`magic[8]`, `ctrl_block_len`, `diff_block_len`, `new_file_size`), opens three `BZFILE*` streams over the control, diff, and extra blocks, and reconstructs the new file via:
     $$\text{new}[\text{newpos} + i] = (\text{diff}[i] + \text{old}[\text{oldpos} + i]) \bmod 256$$
2. **Embedded `libbzip2` 1.0.8 Decompression Pipeline (`BZ2_bzDecompress` @ `0x07d70`)**:
   - Reverses Huffman coding, Run-Length Encoding (RLE2), Move-To-Front (MTF) transform, Inverse Burrows-Wheeler Transform ($T$-vector permutation), and RLE1 with IEEE CRC-32 verification.
