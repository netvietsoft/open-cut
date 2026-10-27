# Clean-Room Forensics & C++17 Reconstruction: `libtt_ugen_layout.so` (`TASK-137` / `TASK_SO_036_libtt_ugen_layout`)

## 1. Binary Identity & ELF Layout (Định danh Nhị phân & Bố cục ELF)
- **File Name**: `libtt_ugen_layout.so` (ByteDance UGen Flexbox Layout Engine — `facebook::yoga`, `YGNode`, `YGStyle`, `YGLayout`, `YGConfig`, `YGJNIVanilla::registerNatives` for `com/bytedance/adsdk/ugeno/yoga/YogaNative`, and static `libc++abi` runtime)
- **File Size**: `360,968 bytes` (`360,968 bytes`)
- **SHA-256**: `05ddb584447d49f6ac1707d00ab557acdc1ddcc6fddbb29628bda1320745e44e`
- **Architecture**: `AArch64 (ELF64 Little-Endian, arm64-v8a, 16KB page-aligned PT_LOAD)`
- **Dependencies (`DT_NEEDED`)**: `liblog.so`, `libm.so`, `libdl.so`, `libc.so`
- **Exported `.dynsym` Symbols**: `692` symbols (`442` `STT_FUNC` + `250` `STT_OBJECT`)
- **Unwind `.eh_frame_hdr` FDEs**: `874` functions (`0x025dd4 .. 0x051d0f`)

| Section | Virtual Address (`VA`) | File Offset | Size (Bytes) | Role (EN / VN) |
|---|---:|---:|---:|---|
| `.rodata` | `0x018bc0` | `0x018bc0` | `15,969` | `YGValueZero`, `YGValueUndefined`, `YGValueAuto`, `leading`, `trailing`, JNI strings |
| `.eh_frame_hdr` | `0x01d5bc` | `0x01d5bc` | `7,004` | `874` binary-search FDE unwind entries / Bảng tháo ngăn xếp 874 hàm |
| `.text` | `0x025dd4` | `0x025dd4` | `180,028` | Executable AArch64 instructions / Mã máy thực thi AArch64 |
| `.data.rel.ro` | `0x057010` | `0x053010` | `13,112` | `YogaJniException`, `std::function`, and `libc++abi` RTTI vtables |
| `.fini_array` | `0x05a348` | `0x056348` | `16` | 2 global destructors / Hàm hủy toàn cục |
| `.data` | `0x05f010` | `0x057010` | `2,368` | 95-entry `JNINativeMethod` table at `0x05f018..0x05f900` (`2,280 B`) |
| `.bss` | `0x05f950` | `0x057950` | `1,488` | `globalJvm` (`0x05f950`), `YGConfigGetDefault` singleton, Event subscriber list |

---

## 2. Key Mathematical & Binary Proofs (Bằng chứng Toán học & Nhị phân Cốt lõi)
1. **Exported `.rodata` `YGValue` & Edge Constants (`0x01ad94 .. 0x01addc`)**:
   - `YGValueZero` (`0x01ad94`): `{value = 0.0f (0x00000000), unit = YGUnitPoint (1)}`
   - `YGValueUndefined` (`0x01ad9c`): `{value = NaN (0x7FC00000), unit = YGUnitUndefined (0)}`
   - `YGValueAuto` (`0x01ada4`): `{value = NaN (0x7FC00000), unit = YGUnitAuto (3)}`
   - `leading[4]` (`0x01adbc`): `{YGEdgeTop (1), YGEdgeBottom (3), YGEdgeLeft (0), YGEdgeRight (2)}`
   - `trailing[4]` (`0x01adcc`): `{YGEdgeBottom (3), YGEdgeTop (1), YGEdgeRight (2), YGEdgeLeft (0)}`
2. **Floating-Point Equality Epsilons (`YGFloatsEqual` at `0x025eb8` & `YGDoubleEqual` at `0x025ef4`)**:
   - `YGFloatsEqual` & `YGValueEqual` (`0x025e60`) load IEEE-754 float `0.0001f` (`0x38D1B717` via `0x025e9c: 0x5296E2E8 mov w8, #0xb717; 0x025ea0: 0x72A71A28 movk w8, #0x38d1, lsl #16`).
   - `YGDoubleEqual` loads IEEE-754 double `0.0001` (`0x3F1A36E2EB1C432D` at `.rodata 0x018bc0` via `0x025f10: 0xFD45E102 ldr d2, [x8, #0xbc0]`).
3. **95-Method `YogaNative` JNI Registration (`YGJNIVanilla::registerNatives` at `0x026650..0x026668`)**:
   - `0x026650: 0x90FFFFA1 adrp x1, #0x1a000; 0x026658: 0x910BAC21 add x1, x1, #0x2eb` -> `"com/bytedance/adsdk/ugeno/yoga/YogaNative"` (`0x01a2eb`).
   - `0x026654: 0xB00001C2 adrp x2, #0x5f000; 0x02665c: 0x91006042 add x2, x2, #0x18` -> `.data 0x05f018`.
   - `0x026660: 0x52800BE3 mov w3, #0x5f` (`95` methods from `jni_YGConfigNewJNI` to `jni_YGNodeCloneJNI`).
4. **Pixel Grid Rounding (`YGRoundValueToPixelGrid` at `0x02e7c0..0x02e8b0`) & Percentage Resolution (`0x033048`)**:
   - Computes `scaledValue = value * pointScaleFactor`, `fractial = fmod(scaledValue, 1.0)` (adding `1.0` if negative), and rounds to the nearest pixel boundary with `0.5` tie-breaking (`0x02e86c: 0x1E6C1000 fmov d0, #0.50000000`).
   - In `YGNodeCalculateLayoutWithContext` (`0x032f2c`), percentage dimensions multiply by `0.01f` (`0x3C23D70A` via `0x033048: 0x529AE148 mov w8, #0xd70a; 0x03304c: 0x72A78468 movk w8, #0x3c23, lsl #16`).
