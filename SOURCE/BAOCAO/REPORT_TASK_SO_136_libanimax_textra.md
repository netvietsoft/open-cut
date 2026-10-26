# Báo Cáo Nghiệm Thu Giải Mã & Tái Dựng: `libanimax_textra.so` (`TASK_SO_136` / `TASK-104`)

- **Report ID**: `REPORT_TASK_SO_136_libanimax_textra`
- **Task ID**: `TASK-104-RECONSTRUCTION-LIBANIMAX_TEXTRA` (`TASK_SO_136_libanimax_textra`)
- **Target Binary**: `extracted/arm64-v8a/libanimax_textra.so` (`83,952 bytes`, 24 ELF64 AArch64 sections)
- **Status**: `VERIFIED_AND_ACCEPTED` (`100%`, `0 stubs`)
- **Reconstructed Code Size**: `160,666 bytes` across 8 C++17 & Header files

## Tóm Tắt Nghiệm Thu (Verification Summary)

1. **`lynx::animax::FontAssetImplTextra`** (`0x0089ec..0x008db8`, `sizeof = 0x58 = 88 bytes`, VTable @ `0x010018`): Khởi tạo trễ `FontmgrCollection` (`0x38` bytes) và sinh khóa họ phông duy nhất `<counter>@_@<name>`.
2. **`lynx::animax::TypefaceTextra`** (`0x009550..0x009c34`, `sizeof = 0x98 = 152 bytes`, VTable @ `0x010110`): Thực thi `GetHorizontalAdvance`, `GetHorizontalAdvances`, `GetWidthBound` (`fsub v0.2s, v1.2s, v0.2s`), `GetWidthBounds` (`fminnm`, `fmaxnm`, `fadd`), `UnicharToGlyph`, `UnicharsToGlyphs`, `GetUnitsPerEm`, `GetFontMetrics`.
3. **`lynx::animax::FontManagerTextra`** (`0x0092a0..0x00954c` & `0x009c38..0x009f8c`, `sizeof = 0x40 = 64 bytes`, VTables @ `0x010080` & `0x010238`): Tích hợp `CityHash64` (`0x008424..0x0089d8`) và kiểm tra số bucket lũy thừa của 2 bằng lệnh NEON `cnt v0.8b; uaddlv h0, v0.8b`.
4. **`lynx::animax::TextLayerImplTextra`** (`0x00a180..0x00ab0c`, `sizeof = 0x28 = 40 bytes`, VTable @ `0x0102c0`): Dàn trang và kết xuất văn bản với bảng tra căn lề 64-bit `0x0000030303030102ULL`, khoảng cách chữ `(size * tracking) / 100.0f`, phân đoạn `RangeSelector` + `TextAnimator`, và độ lệch vùng không giới hạn `-500000.0f` / `-1000000.0f` / `+1000000.0f`.
5. **`lynx::animax::CanvasHelperTextra`** (`0x00ab64..0x00b458`, VTable @ `0x0102e8`): Thực thi 26 phương thức `ICanvasHelper`, bao gồm `DrawGlyphs` với độ nghiêng chữ giả lập `-0.25f`, `skity::TextRun` (`sizeof = 0x68 = 104 bytes`) và `skity::MaskFilter::MakeBlur`.
6. **`lynx::animax::TextHelperTextra` & `JNI_OnLoad`** (`0x00b538..0x00b8c3`): Đăng ký `TextHelper::RegisterImpl` và trả về `0x00010006` (`JNI_VERSION_1_6`).
