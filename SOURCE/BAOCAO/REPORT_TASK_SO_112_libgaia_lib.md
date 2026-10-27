# Adversarial Verification Proof: `libgaia_lib.so` (`TASK-135` / `TASK_SO_112_libgaia_lib`)

## 1. Binary & Reconstruction Metrics
- **Binary Path**: `SOURCE/apktool-res/lib/arm64-v8a/libgaia_lib.so`
- **Binary Size**: `329,704 bytes`
- **SHA-256**: `a42c9645c2acd2bebcf524e5eec1b759c39f85403fd89c36afabadfaa9e6a911`
- **Reconstructed C++17 / Header Volume**: `1,151,208 bytes` across 9 source/header files
- **Verified AArch64 Instructions**: `51,332` instructions across `757` FDEs
- **Exported `.dynsym` Symbols**: `392` symbols (`0` stubs)

## 2. Direct AArch64 Opcode & `.rodata` Evidence
- **`.init_array` (`0x052628..0x052638`, file offset `0x04e628`)**:
  - `0x00010550` (`_GLOBAL__sub_I_AMGLog.cpp`), `0x0001056c` (`_GLOBAL__sub_I_AMGAllowList.cpp`), `0x00010628` (`_GLOBAL__sub_I_AMGPerformanceEvaluation.cpp`).
- **`.data` (`0x054000`, file offset `0x050000`)**:
  - `0x00000010` (`16`, `DefaultMemoryAlignment`).
- **`AmazingEngine::PerlinNoise::Perlin3D` (`0x017098..0x01834b`)**:
  - `0x0170a4: 0x912B8108 add x8, x8, #0xae0` -> `.rodata 0x043ae0` (`kPerlinPermTable_043ae0[256]`)
  - `0x0170e8: 0x1E231004 fmov s4, #6.00000000`
  - `0x0170f8: 0x1E35D007 fmov s7, #-15.00000000`
  - `0x017128: 0x1E249016 fmov s22, #10.00000000`
- **`AmazingEngine::Slerp(Quaternionf const&, Quaternionf const&, float)` (`0x018720..0x018890`)**:
  - `0x018770: 0x52866668 mov w8, #0x3333`
  - `0x018774: 0x72A7EE68 movk w8, #0x3f73, lsl #16` (`0x3F733333 = 0.95f`)
- **`AmazingEngine::stbtt_GetGlyphSDF` (`0x03f928..0x040843`)**:
  - `0x03f928: 0xD10583FF sub sp, sp, #0x160`
  - `0x03fae8: 0x528001CB mov w11, #0xe` (`sizeof(stbtt_vertex) == 14`)
- **`AmazingEngine::RefBase::retain / release` (`0x043728..0x04379c`)**:
  - `0x04372c: 0x885FFD09 ldaxr w9, [x8]`
  - `0x043734: 0x880AFD09 stlxr w10, w9, [x8]`
