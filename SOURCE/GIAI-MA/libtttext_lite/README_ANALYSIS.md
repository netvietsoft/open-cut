# Clean-Room C++17 Reconstruction — `libtttext_lite.so` (`TASK-132` / `TASK_SO_115_libtttext_lite`)

## 1. Binary Forensics Overview (Tổng Quan Giám Định Nhị Phân)
- **File**: `SOURCE/apktool-res/lib/arm64-v8a/libtttext_lite.so`
- **Size**: `297,312 bytes` (`0x48960`)
- **SHA-256**: `8860b2ff8bdd7458117fb7475fdfd9c84accda90c492d1572714ef9e8260282e`
- **Subsystem**: ByteDance Lynx / TTOffice TTText Lite Typography, HarfBuzz/Java Text Shaper, ICU4C Bidi/Break Wrapper & Paragraph Layout Engine (`ttoffice::tttext::*`, `com/lynx/textra/*`).
- **Exported Symbols**: `434` (`414` functions/methods + `20` vtables/objects).

## 2. Clean-Room C++17 Architecture (`675,258 bytes`, `0` stubs)
1. `tttext_lite_types.h`: Exact ABI structures (`PointF`, `Range`, `RangeF`, `RectF`, `TTColor`, `Spacing`, `FontStyle`, `Style`, `ParagraphStyle`, `HarfbuzzFuncTable`, `ControlRunEntry`, `JniNativeMethodEntry`).
2. `tttext_lite_rodata_tables.h` & `tttext_lite_rodata_tables.cpp`: Exact `.rodata` (`0x00d9c0..0x00e470`) SIMD constants, relative byte-offset jump tables (`0x00d9fc`, `0x00daab`, `0x00dac0..0x00db4d`), 39 HarfBuzz symbol names, 15 ICU symbol names, and `.data` (`0x048008..0x0480df`) `ControlRunList`, `SpaceList`, and `JNINativeMethod` descriptors.
3. `tttext_lite_icu_and_harfbuzz.h` & `tttext_lite_icu_and_harfbuzz.cpp`: `ttoffice::base` UTF-8/UTF-16/UTF-32 conversion suite (`U8CharToU32`, `IsValidUtf8Bytes`, `U8StringToU32`, `U16StringToU32`, `U32StringToU16`, `U32StringToU8`, `U32IndexToU16`), `TTString`, `TTStringPiece`, `DefaultBidiResult`, `DefaultBreakResult`, `ICUWrapper`, and `HarfbuzzLib`.
4. `tttext_lite_shaper_and_layout.h` & `tttext_lite_shaper_and_layout.cpp`: `PointF`, `Range`, `RangeF`, `RectF`, `TTColor`, `BoundaryAnalyst`, `LayoutMeasurer`, `AttributesRangeList`, `StyleManager`, `ShapeResult`, `BaseRun`, `ParagraphImpl`, and `TTTextJNIProxy`.
5. `tttext_lite_interface.h` & `tttext_lite_pseudocode.cpp`: Public C/JNI entrypoints and `4,993` verified AArch64 instructions + `434` exported symbol entries.
