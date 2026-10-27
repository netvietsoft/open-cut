# Clean-Room C++17 Reconstruction — `libbytevc0.so` (`TASK-203-RECONSTRUCTION-LIBBYTEVC0`)

## 1. Binary Identity & ELF64 Geometry (Định danh Nhị phân & Bố cục ELF64)
- **Target Binary**: `libbytevc0.so` (`548,760 bytes`)
- **SHA-256**: `dc9c342b14505ca04f97fe75572b3b9213873762efef079f57ad23f1c790d0e7`
- **Architecture**: `AArch64 (ARM64-v8a)`
- **Role**: ByteDance ByteVC0 (H.264 / AVC) Real-Time NEON Video Encoder with ROI, LTR, Optical Flow & Mosh Rate Control (`18` exported functions, `1,142` FDEs)
- **Reconstructed C++17 Volume**: `2,394,742 bytes` across 3 files (`bytevc0.hpp`, `bytevc0_core.cpp`, `bytevc0_elf_sections_and_image.cpp`), `0` stubs.

| Section | File Offset | Size (Bytes) | Details |
|---|---:|---:|---|
| `.plt` | `0x005A70` | `1,072` | Procedure Linkage Table |
| `.text` | `0x005EA0` | `430,248` | `107,562` AArch64 32-bit instruction words |
| `.rodata` | `0x06EF80` | `26,432` | ROI/optical-flow diagnostics, `CInputPicManage::init()`, `CFrameCostEstTaskManager` |
| `.eh_frame_hdr` | `0x0756C0` | `9,148` | Header `01 1b 03 3b`, `1,142` FDE entries |
| `.eh_frame` | `0x077A80` | `37,872` | DWARF CFI unwind records |
| `.data.rel.ro` | `0x0825A0` | `3,352` | Relocated vtables (`vaddr=0x0865A0`) |
| `.data` | `0x084000` | `6,144` | Initialized preset state (`vaddr=0x088000`) |
| `.bss` | `0x085800` | `549,536` | Zero-initialized runtime state (`vaddr=0x089800`) |
