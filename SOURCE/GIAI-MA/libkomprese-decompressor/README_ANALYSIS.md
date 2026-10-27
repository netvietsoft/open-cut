# Clean-Room Reconstruction Analysis — `libkomprese-decompressor.so`

## 1. Binary Identity & Cryptographic Hashes (Định danh Nhị phân & Mã băm)
- **File Name**: `libkomprese-decompressor.so`
- **File Size**: `15,800 bytes`
- **SHA-256**: `7a2a91ead53359dafebaae790ec6e5807f0e037c4c73b8ec0a3a49af1c1a18c3`
- **Task ID**: `TASK-167-RECONSTRUCTION-LIBKOMPRESE-DECOMPRESSOR` (`TASK_SO_163_libkomprese_decompressor`)
- **Architecture**: `AArch64 (ARM64-v8a)` ELF64 Shared Library
- **Total Reconstructed C++17 Code Size**: `206,002 bytes` across 5 implementation files (`0` stubs)

## 2. ELF64 Layout & `.eh_frame_hdr` FDE Map (Bố cục ELF64 & Bản đồ 9 FDE)
- `.rodata`: `0x06e0..0x08c0` (`480 bytes`)
- `.eh_frame_hdr`: `0x08c0..0x0914` (`84 bytes`, `9 FDEs`)
- `.text`: `0x0a64..0x3298` (`10,292 bytes`, `2,573 AArch64 instructions`)
- `.plt`: `0x32a0..0x3360` (`192 bytes`)
- `.init_array`: `0x7378..0x7380` (`8 bytes` -> points to `0x0ab8`)
- `.bss`: `0x0b5b8..0x1c1d8` (`68,640 bytes`)

| FDE # | PC Range | Size (B) | Reconstructed Symbol / Role |
|---|---|---|---|
| `FDE[00]` | `0x0a64..0x0a74` | `16` | `__on_dlclose` (`__cxa_finalize(&__dso_handle)`) |
| `FDE[01]` | `0x0a74..0x0a7c` | `8` | `__atexit_noop_ret` |
| `FDE[02]` | `0x0a7c..0x0a84` | `8` | `__atexit_thunk` |
| `FDE[03]` | `0x0a84..0x0a98` | `20` | `__cxa_atexit_Trampoline` |
| `FDE[04]` | `0x0a98..0x0ab8` | `32` | `__cxa_atexit_Register` |
| `FDE[05]` | `0x0ab8..0x0e9c` | `996` | `KompreseInitGlobalTables` (`.init_array` constructor: NEON CRC-32 `0xEDB88320`, CRC-64/XZ `0xC96C5795D7870F42`, 16x16 ANS target CDF, reciprocal table) |
| `FDE[06]` | `0x0e9c..0x181c` | `2,432` | `komprese_decompress` (Exported C ABI entry point: `KOM` magic/v1/CRC-32 verifier, LEB128 section/patch parser, metadata CRC-32 verifier) |
| `FDE[07]` | `0x181c..0x2b24` | `4,872` | `KompreseDecompressBitstream` (16-symbol vectorized NEON ANS/Range LZMA-style decoder with 14-bit CDFs `0x3FFF` and rate-7 `ssra` adaptation) |
| `FDE[08]` | `0x2b24..0x3298` | `1,908` | `KompreseApplyBcjAndRelocFilters` (Variable-width delta relocations, AArch64 `BL`/`ADRP`/`PLT`, ARM Thumb-2 `BL`/`BLX`, and Prel31 filters) |
