# Adversarial Verification Proof: `libtt_ugen_layout.so` (`TASK-137` / `TASK_SO_036_libtt_ugen_layout`)

## 1. Binary & Reconstruction Metrics
- **Binary Path**: `SOURCE/apktool-res/lib/arm64-v8a/libtt_ugen_layout.so`
- **Binary Size**: `360,968 bytes`
- **SHA-256**: `05ddb584447d49f6ac1707d00ab557acdc1ddcc6fddbb29628bda1320745e44e`
- **Reconstructed C++17 / Header Volume**: `1,184,430 bytes` across 9 source/header files
- **Verified AArch64 Instructions**: `44,990` instructions across `874` FDEs
- **Exported `.dynsym` Symbols**: `692` symbols (`0` stubs)

## 2. Direct AArch64 Opcode & `.rodata` / `.data` Evidence
- **Exported `.rodata` Constants (`0x01ad94..0x01addc`)**:
  - `YGValueZero` (`0x01ad94`): `00 00 00 00 01 00 00 00` (`{0.0f, YGUnitPoint}`)
  - `YGValueUndefined` (`0x01ad9c`): `00 00 C0 7F 00 00 00 00` (`{NaN, YGUnitUndefined}`)
  - `YGValueAuto` (`0x01ada4`): `00 00 C0 7F 03 00 00 00` (`{NaN, YGUnitAuto}`)
  - `leading[4]` (`0x01adbc`): `{1, 3, 0, 2}` (`{YGEdgeTop, YGEdgeBottom, YGEdgeLeft, YGEdgeRight}`)
  - `trailing[4]` (`0x01adcc`): `{3, 1, 2, 0}` (`{YGEdgeBottom, YGEdgeTop, YGEdgeRight, YGEdgeLeft}`)
- **`YGJNIVanilla::registerNatives` (`0x026650..0x026668`)**:
  - Registers `95` (`0x5f`) `JNINativeMethod` entries at `.data 0x05f018..0x05f900` on class `"com/bytedance/adsdk/ugeno/yoga/YogaNative"` (`.rodata 0x01a2eb`).
- **`YGRoundValueToPixelGrid` (`0x02e7c0..0x02e8b0`) & `YGNodeCalculateLayoutWithContext` (`0x032f2c..0x033ae4`)**:
  - `0x02e86c: 0x1E6C1000 fmov d0, #0.50000000`
  - `0x033048: 0x529AE148 mov w8, #0xd70a; 0x03304c: 0x72A78468 movk w8, #0x3c23, lsl #16` (`0x3C23D70A = 0.01f`).
