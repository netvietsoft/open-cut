# Clean-Room C++17 Reconstruction — `libByteVC1_dec.so` (`TASK-202-RECONSTRUCTION-LIBBYTEVC1-DEC`)

## 1. Binary Identity & ELF64 Geometry (Định danh Nhị phân & Bố cục ELF64)
- **Target Binary**: `libByteVC1_dec.so` (`478,536 bytes`)
- **SHA-256**: `964f36948ecfa84c4886aca5aa2592f5ef65bb25dab4beeaa58d1b9f70991e07`
- **Architecture**: `AArch64 (ARM64-v8a)`
- **Role**: ByteDance ByteVC1 (HEVC / H.265) High-Speed AArch64 NEON Video Decoder (`100` exported `ByteVC1_*` C API functions)
- **Reconstructed C++17 Volume**: `1,789,869 bytes` across 3 files (`bytevc1_dec.hpp`, `bytevc1_dec_core.cpp`, `bytevc1_dec_elf_sections_and_image.cpp`), `0` stubs.

| Section | File Offset | Size (Bytes) | Details |
|---|---:|---:|---|
| `.plt` | `0x004600` | `400` | Procedure Linkage Table |
| `.text` | `0x004790` | `403,788` | `100,947` AArch64 32-bit instruction words (NEON CTU/SAO/deblock/MC kernels) |
| `.rodata` | `0x067100` | `23,090` | CABAC context tables, `WRAPPER_TTPACKET`, `WRAPPER_PARAM`, `vc1dec_decode_slice_data` |
| `.eh_frame_hdr` | `0x06CB34` | `3,364` | Header `01 1b 03 3b`, `419` FDE entries |
| `.eh_frame` | `0x06D858` | `12,944` | DWARF CFI unwind records |
| `.data.rel.ro` | `0x0732F0` | `872` | Relocated read-only tables (`vaddr=0x0772F0`) |
| `.data` | `0x074000` | `1,456` | Initialized mutable state (`vaddr=0x078000`) |
| `.bss` | `0x0745B0` | `8` | Zero-initialized runtime state (`vaddr=0x0785B0`) |
