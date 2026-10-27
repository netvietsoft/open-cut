# Adversarial Verification Proof — `libkomprese-decompressor.so`

- **Library**: `libkomprese-decompressor.so` (`15,800 bytes`)
- **SHA-256**: `7a2a91ead53359dafebaae790ec6e5807f0e037c4c73b8ec0a3a49af1c1a18c3`
- **Task ID**: `TASK-167-RECONSTRUCTION-LIBKOMPRESE-DECOMPRESSOR` (`TASK_SO_163_libkomprese_decompressor`)
- **Reconstructed Code Volume**: `206,002 bytes` (`0` stubs)
- **FDE Coverage**: `9 / 9 FDEs` (`0x08c0`, `.text` `0x0a64..0x3298`, `2,573` AArch64 instructions)

## Mathematical & Binary Proofs
1. **CRC-32 & CRC-64/XZ NEON Generator (`0x0ab8..0x0e98`)**:
   - `0x0acc`: `5290640a mov w10, #0x8320` + `0x0ad0`: `72bdb70a movk w10, #0xedb8, lsl #16` (`0xEDB88320`)
   - `0x0ae0..0x0af4`: `0xC96C5795D7870F42` (ECMA-182 XZ CRC-64 reflected polynomial)
   - `0x0e5c..0x0e84`: Reciprocal division table `((1ULL << (0x5f - clz(i - 1))) + i - 1) / i` for `i = 2..4095`.
2. **Komprese Stream Header & Section Parser (`komprese_decompress` @ `0x0e9c..0x1818`)**:
   - `0x0ef0`: `52896fea mov w10, #0x4b7f` + `0x0ef4`: `72a9a9ea movk w10, #0x4d4f, lsl #16` (`0x4D4F4B7F` = `\x7fKOM`)
   - Allocates `0x20`-byte `KompreseStreamContext` (`0x0f74`) and `num_sections * 0x318`-byte `KompreseSectionDescriptor` array (`0x1130`).
3. **16-Symbol NEON ANS/Range LZ Decoder (`0x181c..0x2b20`)**:
   - Allocates `0x801da0` (`8,396,192 bytes`) via `memalign(16, 0x801da0)` (`0x189c..0x18b4`).
   - Vectorized 16-lane `uint16_t` 14-bit CDF lookup (`cmhi v3.8h, v0.8h, v2.8h`, `addv h2, v2.8h`) and rate-7 adaptation (`ssra v0.8h, v2.8h, #7` at `0x1ce0`).
4. **Multi-Arch ELF BCJ & Relocation Post-Filter (`0x2b24..0x3294`)**:
   - 29-entry jump table at `.rodata` `0x0840` (`0x2c74..0x2c88`) dispatching variable-width delta relocations (`0x2c8c`), AArch64 `BL`/`ADRP` (`0x2eb8`), Thumb-2 `BL`/`BLX` (`0x2f70`), AArch64 `PLT` stubs (`0x2f8c`), and Prel31 (`0x30c0`).
