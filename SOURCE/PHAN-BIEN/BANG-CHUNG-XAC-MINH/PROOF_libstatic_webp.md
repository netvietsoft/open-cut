# Clean-Room C++17 Reconstruction: `libstatic-webp.so` (Facebook Fresco Static-WebP + libwebp + libjpeg-turbo 1.5.3 + libpng 1.6.37)
- **Target Number**: 100 / 169 (`TASK-139-RECONSTRUCTION-LIBSTATIC-WEBP` / `TASK_SO_035_libstatic_webp`)
- **Binary Size**: `396,088 bytes`
- **SHA-256**: `757a3d4beac3a14fd300c3b74605f3c7e5e80cc1048e3183ec46cb2931b64415`
- **FDE Count (`.eh_frame_hdr` @ `0x055ae8`)**: `701`
- **Exported `.dynsym` Symbols**: `16` (`JNI_OnLoad` @ `0x004ac0` + RTTI/BSS symbols)
- **Registered `JNINativeMethod` Descriptors (`.data 0x064000..0x064290`)**: `27` (`3 + 2 + 12 + 10`)
- **Reconstructed C++17/H Volume**: `1,289,934 bytes` across 9 files (`0` stubs)

## Architectural & Mathematical Proof Highlights
1. **`JNI_OnLoad` (`0x004ac0..0x0051cc`, `1,804 bytes`) & 4 `JNINativeMethod` Tables (`.data 0x064000..0x064290`)**:
   - Registers `3` methods (`nativeDecodeStream` @ `0x0053a0`, `nativeDecodeByteArray` @ `0x005450`, `nativeSeek` @ `0x0055b4`) at `.data 0x064000` (`mov w3, #3` @ `0x0050c8`) on `com/facebook/webpsupport/WebpBitmapFactoryImpl` (`0x04fc58`).
   - Calls `registerWebpTranscoderMethods` (`0x0067b8`) to register `2` methods (`nativeTranscodeWebpToJpeg` @ `0x006840`, `nativeTranscodeWebpToPng` @ `0x006954`) at `.data 0x064050` (`mov w3, #2` @ `0x0067f4`) on `com/facebook/imagepipeline/nativecode/WebpTranscoderImpl` (`0x050251`).
   - Calls `WebPImage_registerNatives` (`0x009174`) to register `12` methods at `.data 0x064080` (`mov w3, #0xc` @ `0x009200`) on `com/facebook/animated/webp/WebPImage` (`0x04fd8b`) and `10` methods at `.data 0x0641a0` on `com/facebook/animated/webp/WebPFrame` (`0x050563`).
2. **`createBitmapDecode` Pixel Format & Stride Math (`0x0049a0..0x004a0c`)**:
   - Compares `Bitmap.Config.nativeInt` against `3` (`RGB_565` @ `0x0049a0: cmp w0, #3`): selects `MODE_RGB_565 = 6` (`0x0049b0`) with `stride = width << 1` (`0x0049bc`), or `MODE_rgbA = 7` (`0x0049cc`) with `stride = width << 2` (`0x0049d4`), computes `size = stride * height` (`0x0049e0: mul w8, w8, w11`), sets `is_external_memory = 1` (`0x0049e8`), calls `WebPDecode` (`0x028c94`), and unlocks pixels via `AndroidBitmap_unlockPixels` (`0x004a0c`).
3. **`transcodeToJpeg` (`0x005768..0x005ab0`) & `WebPDecode` (`0x028c94..0x028dfc`)**:
   - Initializes `libjpeg-turbo 1.5.3` via `jpeg_CreateCompress(&cinfo, 80, 0x248)` (`0x0057f4: mov w1, #0x50; mov w2, #0x248`) and loads packed `(input_components=3, in_color_space=JCS_RGB=2)` (`0x0000000200000003` at `.rodata 0x04ff68`) via `ldr d0, [x8, #0xf68]` (`0x005820`).
   - `WebPDecode` (`0x028c94`) zeroes the 40-byte `WebPBitstreamFeatures` (`+0x00`), calls `WebPGetFeaturesInternal` (`0x028238`), maps status `7` (`VP8_STATUS_NOT_ENOUGH_DATA`) to `3` (`VP8_STATUS_BITSTREAM_ERROR` @ `0x028d04..0x028d0c`), and invokes `VP8Decode` (`0x02ac28`) with `&config->output` (`+0x28`) and `&config->options` (`+0xa0`).

## Verified AArch64 Opcode Evidence
- `0x0049a0: 71000c1f cmp w0, #3 (Bitmap.Config.RGB_565 check)`
- `0x0049b0: 528000c8 mov w8, #6; 0x0049bc: 531f7948 lsl w8, w10, #1 (MODE_RGB_565, stride = width << 1)`
- `0x0049cc: 528000e8 mov w8, #7; 0x0049d4: 531e7548 lsl w8, w10, #2 (MODE_rgbA, stride = width << 2)`
- `0x0049e0: 1b0b7d08 mul w8, w8, w11 (u.RGBA.size = stride * height)`
- `0x004ac0: d10183ff sub sp, sp, #0x60 (JNI_OnLoad entry, 1804 bytes)`
- `0x0050c8: 52800063 mov w3, #3 (RegisterNatives 3 methods @ .data 0x064000 for WebpBitmapFactoryImpl)`
- `0x0057f4: 52800a01 mov w1, #0x50; 0x0057f8: 52804902 mov w2, #0x248 (jpeg_CreateCompress version=80, size=584)`
- `0x005820: fd47b500 ldr d0, [x8, #0xf68] (.rodata 0x04ff68 = 0x0000000200000003 {3, JCS_RGB})`
- `0x0067f4: 52800043 mov w3, #2 (RegisterNatives 2 methods @ .data 0x064050 for WebpTranscoderImpl)`
- `0x009200: 52800183 mov w3, #0xc (RegisterNatives 12 methods @ .data 0x064080 for WebPImage)`
- `0x028c94: d10503ff sub sp, sp, #0x140 (WebPDecode entry)`
- `0x028d04: 71001c1f cmp w0, #7; 0x028d0c: 52800076 mov w22, #3 (VP8_STATUS_NOT_ENOUGH_DATA -> BITSTREAM_ERROR)`
