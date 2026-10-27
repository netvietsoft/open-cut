# Clean-Room Reconstruction Analysis: `libopus.so`
# Phân Tích Tái Tạo Phòng Sạch: `libopus.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libopus.so`
- **Task ID**: `TASK-200-RECONSTRUCTION-LIBOPUS` (`TASK_SO_013_libopus`)
- **Size**: `411,168` bytes
- **SHA-256**: `73cbdb63b9cc6f36418f3e3cdebc8c366d56f8d726616e32777aa8a0dcd654ca`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libopus.so`

## 2. Exact ELF Layout & Exported Symbol Table / Bố Cục ELF & Bảng Xuất Khẩu
- `.plt`: `0x02b50` (`496` bytes)
- `.text`: `0x02d40 .. 0x557e8` (`338,600` bytes = `84,650` AArch64 instructions)
- `.rodata`: `0x557f0` (`43,842` bytes — `celt/bands.c`, `celt/celt.c`, SILK/CELT psychoacoustic & MDCT tables)
- `.data.rel.ro`: `0x67650` (`1,080` bytes)
- **Exported Functions**: `68` RFC 6716 Opus symbols in `.dynsym`

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **RFC 6716 TOC Byte Parsing (`opus_packet_get_samples_per_frame` @ `0x42494`, `opus_packet_get_bandwidth` @ `0x44828`, `opus_packet_get_nb_channels` @ `0x44874`)**:
   - Extracts configuration bits `toc >> 3`, stereo flag `(toc >> 2) & 1`, and frame count code `toc & 3` directly from `data[0]`.
2. **Cubic Soft-Clipping (`opus_pcm_soft_clip` @ `0x4210c`) & Hybrid SILK+CELT Synthesis (`opus_decode` @ `0x44888`)**:
   - Applies continuous second-order non-linearity $y = x + a x^2$ above threshold to clamp floating-point PCM into $[-1.0, 1.0]$ without hard harmonic distortion.
