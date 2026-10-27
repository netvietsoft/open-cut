# Clean-Room Reconstruction Analysis — `libfly-main-color-lib.so`

- **Task ID**: `TASK-187-RECONSTRUCTION-LIBFLY-MAIN-COLOR-LIB` (`TASK_SO_154_libfly_main_color_lib`)
- **Target Index**: 148 / 169
- **Binary Size**: `51,024 bytes`
- **SHA-256**: `4eae061db755de08346e4cec950e9748d506af1fb140b2bfd95bc7dc49a0ba57`
- **Architecture**: `EM_AARCH64` (64-bit ARMv8-A Little-Endian)
- **Unwind Table**: `74` FDEs in `.eh_frame_hdr` (`0x89c4..0x8c20`)
- **Executable `.text` Section**: `0x24b0..0x8814` (`25,444 bytes` = `6,361` AArch64 instructions)
- **Exported Symbols**: `66` functions (`5` JNI methods on `com.bytedance.fly_main_color.FlyMainColor` + `61` C++ symbols)

## Key Subsystems Reconstructed
1. **JNI Entrypoints (`0x24ec..0x2a98`)**:
   - `Java_com_bytedance_fly_1main_1color_FlyMainColor_nIsSupportNeon` (`0x24ec`, returns `w0 = #1`).
   - `Java_com_bytedance_fly_1main_1color_FlyMainColor_nGetColorDifference` (`0x250c` -> `getColorDifference` @ `0x2a98`).
   - `Java_com_bytedance_fly_1main_1color_FlyMainColor_nRGB2OKLCH` (`0x2528` -> `RGB2OK_LCH` @ `0x525c`).
   - `Java_com_bytedance_fly_1main_1color_FlyMainColor_nCutMainColor` (`0x25e8` -> `AndroidBitmap_getInfo`/`lockPixels` + `cut_main_color_at_rgb_565_neon` @ `0x7e0c` / `cut_main_color_at_argb_8888_neon` @ `0x804c`).
   - `Java_com_bytedance_fly_1main_1color_FlyMainColor_nSolveMainColor` (`0x299c` -> `solve_main_color` @ `0x3298`).
2. **Perceptual Color Space Engine (`0x2a98..0x5b94`, `0x6784..0x6ba4`)**:
   - CIE XYZ / CIE L*a*b* / CIE L*C*h* conversions (`RGB2LAB` @ `0x2ee4`, `LAB2RGB` @ `0x4230`, `RGB2LCH` @ `0x30bc`, `LCH2RGB` @ `0x4560`, `deltaE` @ `0x39c0`).
   - Björn Ottosson Oklab / Oklch conversions (`sRGB_to_Linear` @ `0x4b54`, `Linear_to_sRGB` @ `0x55a0`, `RGB2OK_LAB` @ `0x4f98`, `OK_LAB2RGB` @ `0x53b8`, `RGB2OK_LCH` @ `0x525c`, `OK_LCH2RGB` @ `0x5670`).
   - Angle conversions (`rad2deg` @ `0x6784`, `deg2rad` @ `0x67a4`) using exact IEEE-754 single-precision constants `0x43b40000` (`360.0f`) and `0x40c90fdb` (`2*pi = 6.2831855f`).
3. **Median-Cut Dominant Color Extractor (`0x6c44..0x8814`)**:
   - Quantized 15-bit RGB555 channel comparators (`compare_r` @ `0x74e4`, `compare_g` @ `0x74f8`, `compare_b` @ `0x7510`).
   - 56-byte (`0x38`) `ColorBoxNode` priority queue (`create_color_box_at` @ `0x6dfc`, `split_box_at` @ `0x7528`, `insert_box_at` @ `0x7670`).
   - Scalar C and ARMv8 NEON pixel quantizers (`cut_main_color_at_rgb_565_c` @ `0x799c`, `cut_main_color_at_argb_8888_c` @ `0x7bd4`, `cut_main_color_at_rgb_565_neon` @ `0x7e0c`, `cut_main_color_at_argb_8888_neon` @ `0x804c`).
