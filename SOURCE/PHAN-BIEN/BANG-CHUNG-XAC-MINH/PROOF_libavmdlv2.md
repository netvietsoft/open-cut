# Clean-Room Reconstruction of `libavmdlv2.so` (Target 114 / 169)
# Tái dựng Sạch `libavmdlv2.so` (Mục tiêu 114 / 169 — `TASK-153` / `TASK_SO_019_libavmdlv2`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `libavmdlv2.so` (`com::ss::ttmio::*` / `com::ss::ttm::*` AVMDL V2 Media Data Loader, VOD Net Adapter, QUIC Racing & Storage Cache Engine)
- **File Size**: `1,411,344 bytes`
- **SHA-256**: `f548a1a3303de5943289b2b467c20469733ff8b5c107a0aa1b784a9c01f5b93d`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Dynamic Symbols (`.dynsym` @ `0x001ff8`)**: `315` exported symbols & `425` imported symbols
- **Unwind Table (`.eh_frame_hdr` @ `0x1489d4`)**: `11` FDEs (`0x1320a4 .. 0x13376c`) + `1,900` `.text` functions reconstructed

## 2. Key AArch64 Opcode & Struct Layout Proofs / Bằng chứng Opcode AArch64 & Bố cục Struct
1. **`com::ss::ttmio::MDLMessage` (`0x05dacc..0x05e4cc`, `0xc08 = 3,080 bytes`)**:
   - `MDLMessage::MDLMessage()` (`0x05dacc..0x05db04`) iterates 64 slots of stride `0x30` (`48 bytes`, `0x10..0xc10`: `9100C294 add x20, x20, #0x30`, `F130429F cmp x20, #0xc10`) and zeros `count_` at `+0xc00` (`B90C027F str wzr, [x19, #0xc00]`).
   - `MDLMessage::setInt32` (`0x05df80..0x05e050`) enforces `count_ <= 0x3f` (`7100FEDF cmp w22, #0x3f`), computes slot offset `idx * 0x30` (`52800609 mov w9, #0x30`, `9B095108 madd x8, x8, x9, x20`), and stores `value_type = 1` at `+0x00`.
2. **`com::ss::ttmio::MDLSingletonsHolder` (`0x05e4cc..0x05ea18`, `0x78 = 120 bytes`)**:
   - `getInstance()` (`0x05e848..0x05e8f0`) checks `.bss 0x15c1d8`, allocates `0x78` (`120 bytes`, `52800F00 mov w0, #0x78`), and constructs all 14 subsystem singletons at offsets `+0x00 .. +0x70`.
   - `init()` (`0x05e8f0..0x05e980`) inspects `config_center_ + 0x2ac` and `+ 0x2a8` to allocate `MDLFileManagerNgV2` (`0x528` bytes), `MDLFileManagerNg` (`0x358` bytes), or `MDLFileManager` (`0x350` bytes) into `+0x30`.
