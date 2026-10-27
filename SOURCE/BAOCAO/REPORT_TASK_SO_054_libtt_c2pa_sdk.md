# Clean-Room C++17 Reconstruction — `libtt_c2pa_sdk.so` (`TASK-206-RECONSTRUCTION-LIBTT-C2PA-SDK`)

## 1. Binary Identity & ELF64 Geometry (Định danh Nhị phân & Bố cục ELF64)
- **Target Binary**: `libtt_c2pa_sdk.so` (`2,937,160 bytes`)
- **SHA-256**: `a64ce0fb43e7c22e2d95d8bbfcaede522d585c5d51dbae87d24db1359c27a01a`
- **Architecture**: `AArch64 (ARM64-v8a)`
- **Role**: ByteDance TikTok/CapCut C2PA Content Credentials & JUMBF Manifest SDK (`10` exported Molten FFI / UniFFI functions, `13,149` FDEs)
- **Reconstructed C++17 Volume**: `9,660,457 bytes` across 3 files (`tt_c2pa_sdk.hpp`, `tt_c2pa_sdk_core.cpp`, `tt_c2pa_sdk_elf_sections_and_image.cpp`), `0` stubs.

| Section | File Offset | Virtual Addr | Size (Bytes) | Details |
|---|---:|---:|---:|---|
| `.rodata` | `0x01AB00` | `0x01AB00` | `359,327` | JUMBF/C2PA/COSE/X.509 constants (`HashedUri`, `SubsetMap`, `validationStatus`) |
| `.eh_frame_hdr` | `0x073784` | `0x073784` | `105,204` | Header `01 1b 03 3b`, `13,149` FDE entries |
| `.eh_frame` | `0x08D278` | `0x08D278` | `358,764` | DWARF CFI unwind records |
| `.text` | `0x0E4C00` | `0x0E8C00` | `1,922,292` | `480,573` AArch64 32-bit instruction words |
| `.plt` | `0x2BA100` | `0x2BE100` | `2,224` | Procedure Linkage Table |
| `.data.rel.ro` | `0x2BA9B0` | `0x2C29B0` | `72,048` | Relocated Rust trait vtables |
| `.data` | `0x2CC950` | `0x2D8950` | `280` | Initialized mutable state |
| `.bss` | `0x2CCA68` | `0x2D8A70` | `2,704` | Zero-initialized runtime state |
