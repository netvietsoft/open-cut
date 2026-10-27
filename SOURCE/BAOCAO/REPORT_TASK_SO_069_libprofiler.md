# Clean-Room C++17 Reconstruction — `libprofiler.so` (`TASK-201-RECONSTRUCTION-LIBPROFILER`)

## 1. Binary Identity & ELF64 Geometry (Định danh Nhị phân & Bố cục ELF64)
- **Target Binary**: `libprofiler.so` (`471,424 bytes`)
- **SHA-256**: `3d0bc4a14b76e405bce38d41d80d640d29094ddb53013abac8667e4ff02616f9`
- **Architecture**: `AArch64 (ARM64-v8a)`
- **Role**: ByteDance APM XProfiler (`com/bytedance/apm/profiler/Profiler`) & Hybrid ART/Native Stack Unwinder (`xp_*` C API)
- **Reconstructed C++17 Volume**: `1,820,433 bytes` across 3 files (`profiler.hpp`, `profiler_core.cpp`, `profiler_elf_sections_and_image.cpp`), `0` stubs.

| Section | File Offset | Size (Bytes) | Details |
|---|---:|---:|---|
| `.rodata` | `0x010900` | `23,208` | `com/bytedance/apm/profiler/Profiler`, `nStop`, `nDump`, `native init %d`, Itanium demangler & DWARF CFI strings |
| `.eh_frame_hdr` | `0x0163A8` | `7,956` | Header `01 1b 03 3b`, `993` FDE entries |
| `.eh_frame` | `0x0182C0` | `48,684` | DWARF CFI unwind records |
| `.text` | `0x0240F0` | `300,432` | `75,108` AArch64 32-bit instruction words |
| `.plt` | `0x06D680` | `1,744` | Procedure Linkage Table |
| `.data.rel.ro` | `0x071D50` | `16,744` | Relocated read-only vtables & descriptors |
| `.data` | `0x07A780` | `364` | Mutable initialized state |
| `.bss` | `0x07A8F0` | `7,328` | Zero-initialized runtime state |

## 2. Exported Symbols (`.dynsym` — 7 Functions)
1. `JNI_OnLoad` (`0x0668cc`, `152 B`, `first_op=0xd10103ff`)
2. `xp_init_basic_env` (`0x0678e8`, `128 B`, `first_op=0xd10143ff`)
3. `xp_attach_thread` (`0x068544`, `324 B`, `first_op=0xa9bd7bfd`)
4. `xp_detach_thread` (`0x068688`, `148 B`, `first_op=0xa9be7bfd`)
5. `xp_get_current_backtrace` (`0x069160`, `664 B`, `first_op=0xd10603ff`)
6. `xp_get_remote_backtrace` (`0x0693f8`, `344 B`, `first_op=0xd10343ff`)
7. `xp_pretty_method` (`0x06c684`, `384 B`, `first_op=0xd10603ff`)
