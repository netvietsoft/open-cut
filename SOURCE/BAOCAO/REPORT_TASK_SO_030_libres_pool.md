# Clean-Room C++17 Reconstruction — `libres_pool.so` (`TASK-207-RECONSTRUCTION-LIBRES-POOL`)

## 1. Binary Identity & ELF64 Geometry (Định danh Nhị phân & Bố cục ELF64)
- **Target Binary**: `libres_pool.so` (`9,925,624 bytes`)
- **SHA-256**: `7bddb577fba16b943f3388f8d676f91f242371069976d052cb21bb589c66da25`
- **Architecture**: `AArch64 (ARM64-v8a)`
- **Role**: CapCut Lemon Resource Pool SDK (`com/lemon/librespool/model/gen/*`) — DAG Task Scheduler, ORM Cache, Material/Template Downloader & Djinni JNI Bridge (`14,163` FDEs, `1,855,934` `.text` words)
- **Reconstructed C++17 Volume**: `2,566,554 bytes` across 3 files (`res_pool.hpp`, `res_pool_core.cpp`, `res_pool_elf_sections_and_image.cpp`), `0` stubs.

| Section | File Offset | Virtual Addr | Size (Bytes) | Details |
|---|---:|---:|---:|---|
| `.plt` | `0x0B3720` | `0x0B3720` | `2,928` | Procedure Linkage Table |
| `.text` | `0x0B4290` | `0x0B4290` | `7,423,736` | `1,855,934` AArch64 32-bit instruction words |
| `.rodata` | `0x7C8990` | `0x7C8990` | `408,014` | `com/lemon/librespool/model/gen/AbTestConfig`, `ressdkDagEnable`, `ressdkOrmEnable` |
| `.eh_frame_hdr` | `0x82C360` | `0x82C360` | `113,316` | Header `01 1b 03 3b`, `14,163` FDE entries |
| `.eh_frame` | `0x847E08` | `0x847E08` | `515,288` | DWARF CFI unwind records |
| `.data.rel.ro` | `0x934930` | `0x938930` | `254,536` | Relocated Djinni & C++ vtables |
| `.data` | `0x974000` | `0x978000` | `11,168` | Initialized mutable state |
| `.bss` | `0x976BA0` | `0x97ABA0` | `65,072` | Zero-initialized runtime state |
