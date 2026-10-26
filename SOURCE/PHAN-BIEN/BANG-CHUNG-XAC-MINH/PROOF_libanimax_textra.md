# Bằng Chứng Xác Minh Nhị Phân & Toán Học (Adversarial Proof): `libanimax_textra.so`

- **Library**: `libanimax_textra.so` (`83,952 bytes`, 24 ELF64 AArch64 sections)
- **Task ID**: `TASK-104-RECONSTRUCTION-LIBANIMAX_TEXTRA` (`TASK_SO_136`)
- **Reconstructed Code Volume**: `160,666 bytes` across 8 `.h`/`.cpp` files (`0 stubs`)
- **Verdict**: `VERIFIED_AND_ACCEPTED`

---

## 1. Bằng Chứng Opcode AArch64 Trực Tiếp (Direct AArch64 Opcode Evidence)

1. **`std::__ndk1::__murmur2_or_cityhash<size_t, 64>` & NEON Popcount (`0x008424..0x0089d8` & `0x008dbc..0x009254`)**:
   - `0x0085a8`: `kMul = 0x9ddfea08eb382d69ULL`
   - `0x008648`: `k2 = 0x9ae16a3b2f90404fULL` (trả về trực tiếp khi `len == 0`)
   - `0x0090c8..0x0090d0`: `fmov d0, x21; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w8, s0; cmp w8, #1` — kiểm tra `bucket_count` là lũy thừa của 2 bằng tập lệnh vector NEON.
2. **`FontAssetImplTextra` (`sizeof = 0x58 = 88 bytes`, `0x0089ec..0x008db8`)**:
   - `0x008b2c`: `mov w0, #0x50; bl operator new` (`std::__shared_ptr_emplace<FontManagerTextra>`)
   - `0x008ba8`: `mov w0, #0x38; bl operator new` (`ttoffice::tttext::FontmgrCollection`)
   - `0x008c78..0x008cb0`: Tăng bộ đếm tĩnh tại `.bss 0x014000`, ghép chuỗi `"@_@"` tại `.rodata 0x00358a` và `font_asset_->GetName()` (`+0x30`).
3. **`TypefaceTextra` (`sizeof = 0x98 = 152 bytes`, `0x009550..0x009c34`)**:
   - `0x009850`: `fneg s8, s0` (`top = -GetHoriBearingY()`)
   - `0x009868`: `fsub v0.2s, v1.2s, v0.2s` (`[width, height] = [right - left, bottom - top]`)
   - `0x009944..0x009950`: `fminnm s1, s1, s4; fmaxnm s2, s2, s3; fsub s3, s5, s3; fadd s0, s0, s3` (`GetWidthBounds` tích lũy `min_top`, `max_bottom`, `total_width`).
4. **`TextLayerImplTextra::OnDraw` (`sizeof = 0x28 = 40 bytes`, `0x00a1e8..0x00ab0c`)**:
   - `0x00a534..0x00a54c`: Bảng tra cứu căn lề ngang đóng gói 64-bit `0x0000030303030102ULL`.
   - `0x00a598..0x00a5a8`: `mov w8, #0x42c80000; fmul s0, s0, s9; fmov s1, w8; fdiv s10, s0, s1` (`tracking_px = (size * tracking) / 100.0f`).
   - `0x00a9a8`: `ldr s0, [x8, #0x520]` (`+1000000.0f` @ `.rodata 0x003520` với `LayoutMode::kIndefinite = 2`).
   - `0x00aa54` & `0x00aa60`: `ldr s0, [x8, #0x518]` (`-500000.0f` cho `kCenter`) và `ldr s0, [x8, #0x51c]` (`-1000000.0f` cho `kRight`).
5. **`CanvasHelperTextra::DrawGlyphs` (`0x00acf4..0x00b458`)**:
   - `0x00aeb0`: `fneg s10, s0` (đảo dấu tọa độ Y của glyph).
   - `0x00af84`: `fmov s0, #-0.25000000` (độ nghiêng chữ giả lập `skew_x = -0.25f`).
   - `0x00b0ac`: `mov w0, #1; bl skity::MaskFilter::MakeBlur` (`BlurStyle::kNormal = 1`).
   - `0x00b348`: `0x0276276276276277ULL` (`2^64 / 104`, chứng minh `sizeof(skity::TextRun) == 0x68 = 104 bytes`).
6. **`TextHelperTextra` & `JNI_OnLoad` (`0x00b538..0x00b8c3`)**:
   - `0x00b848..0x00b850`: Đăng ký `TextHelper::RegisterImpl(&s_instance)` và trả về `0x00010006` (`JNI_VERSION_1_6`).
