# Clean-Room C++17 Reconstruction — `libbytevc1enc.so` (`TASK-204-RECONSTRUCTION-LIBBYTEVC1ENC`)

## 1. Binary Identity & ELF64 Geometry (Định danh Nhị phân & Bố cục ELF64)
- **Target Binary**: `libbytevc1enc.so` (`1,279,016 bytes`)
- **SHA-256**: `5c7ce626eeca47f9feebade8214da6e0f181aebeb2b37545e1bb4d616b8db25c`
- **Architecture**: `AArch64 (ARM64-v8a)`
- **Role**: ByteDance ByteVC1 (HEVC / H.265) High-Efficiency AArch64 NEON Video Encoder (`31` exported functions, `1,819` FDEs, `23` presets, `21` usecases)
- **Reconstructed C++17 Volume**: `4,858,548 bytes` across 3 files (`bytevc1enc.hpp`, `bytevc1enc_core.cpp`, `bytevc1enc_elf_sections_and_image.cpp`), `0` stubs.

| Section | File Offset | Size (Bytes) | Details |
|---|---:|---:|---|
| `.rodata` | `0x010800` | `55,228` | `ultrafast1`, `statsqualitylog`, `iNumSlice:%d`, `iRoiMaxQpGap:%d`, RDO/CABAC tables |
| `.eh_frame_hdr` | `0x01E810` | `14,564` | Header `01 1b 03 3b`, `1,819` FDE entries |
| `.eh_frame` | `0x0220F8` | `84,652` | DWARF CFI unwind records |
| `.text` | `0x036BB0` | `1,011,840` | `252,960` AArch64 32-bit instruction words |
| `.plt` | `0x12DC30` | `1,408` | Procedure Linkage Table |
| `.data.rel.ro` | `0x12E1B0` | `17,592` | Relocated read-only vtables (`vaddr=0x1321B0`) |
| `.data` | `0x1339E0` | `17,096` | Initialized preset state (`vaddr=0x13B9E0`) |
| `.bss` | `0x137CA8` | `34,992` | Zero-initialized runtime state (`vaddr=0x13FCB0`) |
