# Phân Tích Kiến Trúc & Giải Mã Nhị Phân Hoàn Chỉnh: `libanimax_textra.so`
# Complete Binary Disassembly & Architectural Analysis: `libanimax_textra.so`

- **Task ID**: `TASK-104-RECONSTRUCTION-LIBANIMAX_TEXTRA` (`TASK_SO_136`)
- **Target Binary**: `extracted/arm64-v8a/libanimax_textra.so` (`83,952 bytes`, 24 ELF64 AArch64 sections)
- **Status**: `VERIFIED_AND_ACCEPTED` (100% Clean-Room C++17 Reconstruction, `0 stubs`, `160,666 bytes` across 8 `.h`/`.cpp` files)

---

## 1. Bố Cục Phân Vùng ELF64 (ELF64 Section Geometry)

| Chỉ số | Phân vùng (Section) | Địa chỉ ảo (VA) | Offset File | Kích thước (Bytes) | Mô tả kỹ thuật (Technical Description) |
|---|---|---|---|---|---|
| `[01]` | `.note.gnu.build-id` | `0x000270` | `0x000270` | `36` | Định danh bản dựng GNU Build ID |
| `[05]` | `.dynsym` | `0x000330` | `0x000330` | `2,520` | `105` biểu tượng động (`100` imports `[001..100]`, `1` export `[101] JNI_OnLoad` @ `0x00b7cc`) |
| `[07]` | `.dynstr` | `0x000de0` | `0x000de0` | `4,901` | Chuỗi tên hàm mangled C++ (`lynx::animax::*`, `ttoffice::tttext::*`, `skity::*`) |
| `[08]` | `.rela.dyn` | `0x002108` | `0x002108` | `2,808` | `117` bản ghi định vị lại (`100` `R_AARCH64_RELATIVE`, `1` `GLOB_DAT`, `16` `ABS64`) |
| `[09]` | `.rela.plt` | `0x002c00` | `0x002c00` | `2,328` | `97` mục nhảy PLT (`R_AARCH64_JUMP_SLOT`) |
| `[10]` | `.rodata` | `0x003518` | `0x003518` | `118` | Hằng số IEEE-754 float (`-500000.0f`, `-1000000.0f`, `+1000000.0f`) & 7 chuỗi hằng |
| `[13]` | `.text` | `0x008000` | `0x008000` | `14,980` | Toàn bộ mã máy AArch64 (`0x008000 .. 0x00ba84`, `3,745` lệnh 32-bit) |
| `[14]` | `.plt` | `0x00ba90` | `0x00ba90` | `1,584` | Bảng liên kết thủ tục (`97` cổng gọi sang `libanimax.so`, `libtttext.so`, `libc++.so`) |
| `[15]` | `.data.rel.ro` | `0x010000` | `0x010000` | `1,152` | Bảng hàm ảo (VTables) của 6 lớp thực thi và 3 khối điều khiển `std::__shared_ptr_emplace` |
| `[16]` | `.fini_array` | `0x010480` | `0x010480` | `16` | Con trỏ hàm dọn dẹp tĩnh: `0x008010`, `0x008000` (`__cxa_finalize`) |
| `[20]` | `.bss` | `0x014000` | `0x014000` | `56` | Bộ đếm khóa phông `0x014000`, biến bảo vệ `__cxa_guard` (`0x014008`, `0x014010`), singleton `TextHelperTextra` (`0x014018`) |

---

## 2. Phân Vùng `.rodata` (`0x003518 .. 0x00358e`)

| Địa chỉ VA | Giá trị Hex | Giải mã (Decoded Value) | Vị trí tham chiếu trong `.text` |
|---|---|---|---|
| `0x003518` | `0xC8F42400` | `float -500000.0f` | `0x00aa54: ldr s0, [x8, #0x518]` (Độ lệch căn giữa khi `box_size` không giới hạn) |
| `0x00351c` | `0xC9742400` | `float -1000000.0f` | `0x00aa60: ldr s0, [x8, #0x51c]` (Độ lệch căn phải khi `box_size` không giới hạn) |
| `0x003520` | `0x49742400` | `float +1000000.0f` | `0x00a9a8: ldr s0, [x8, #0x520]` (Kích thước `LayoutRegion` không giới hạn) |
| `0x003524` | `"use textra text impl"` | Chuỗi log khởi tạo `TextHelperTextra` | `0x00b838` |
| `0x003539` | `"pingfang"` | Họ phông mặc định | `0x00a19c`, `0x00b4fc`, `0x00b564` |
| `0x003542` | `"sans-serif"` | Họ phông dự phòng hệ thống | `0x00a1b0`, `0x00b510` |
| `0x00354d` | `"animax textra JNI_OnLoad"` | Chuỗi log tại `JNI_OnLoad` | `0x00b7f0` |
| `0x003566` | `"textra_jni.cc"` | Tên tệp nguồn gốc của `JNI_OnLoad` | `0x00b7e0` |
| `0x003574` | `"text_helper_textra.cc"` | Tên tệp nguồn gốc của `TextHelperTextra` | `0x00b828` |
| `0x00358a` | `"@_@"` | Ký tự phân tách khóa phông duy nhất | `0x008c5c` |

---

## 3. Kiến Trúc Các Lớp C++ & Bảng Hàm Ảo (`.data.rel.ro` `0x010000 .. 0x010480`)

1. **`lynx::animax::FontAssetImplTextra`** (`sizeof = 0x58 = 88 bytes`, cấp phát tại `0x00b5c0`, VTable tại `0x010018 .. 0x010030`):
   - Quản lý bộ sưu tập phông chữ `ttoffice::tttext::FontmgrCollection` (`GetFontmgrCollection` @ `0x008a40`) và sinh khóa định danh phông chữ duy nhất `<counter>@_@<FontAsset::GetName()>` (`GetFontFamilyName` @ `0x008c0c`).
2. **`lynx::animax::TypefaceTextra`** (`sizeof = 0x98 = 152 bytes` bên trong khối `0xb0 = 176 bytes` `std::__shared_ptr_emplace<TypefaceTextra>` @ `0x009560`, VTable tại `0x010110 .. 0x010170`):
   - Kết nối `ttoffice::tttext::ITypefaceHelper` với `skity::Typeface` và `skity::Font`.
   - Tính toán `GetHorizontalAdvance` (`0x0096b8`), `GetHorizontalAdvances` (`0x009744`), `GetWidthBound` (`0x0097f8` dùng `fsub v0.2s, v1.2s, v0.2s`), `GetWidthBounds` (`0x00989c` dùng `fminnm`, `fmaxnm`, `fadd`), và `GetFontMetrics` (`0x009a40`).
3. **`lynx::animax::FontManagerTextra`** (`sizeof = 0x40 = 64 bytes` bên trong khối `0x50 = 80 bytes` `std::__shared_ptr_emplace<FontManagerTextra>` @ `0x008b2c`, VTable tại `0x010080` và `0x010238`):
   - Tra cứu bảng băm `std::unordered_map` bằng hàm băm `CityHash64` (`0x008424 .. 0x0089d8`) và kiểm tra số lượng bucket lũy thừa của 2 bằng lệnh NEON `cnt v0.8b, v0.8b; uaddlv h0, v0.8b` (`0x0090cc .. 0x0090d0`).
4. **`lynx::animax::TextLayerImplTextra`** (`sizeof = 0x28 = 40 bytes`, cấp phát tại `0x00b544`, VTable tại `0x0102c0 .. 0x0102d0`):
   - Thực thi `OnDraw(skity::Canvas*, float)` (`0x00a1e8 .. 0x00ab0c`):
     - Bảng tra căn lề ngang đóng gói 64-bit `0x0000030303030102ULL` (`0x00a534 .. 0x00a53c`).
     - Công thức khoảng cách chữ `tracking_px = (size * tracking) / 100.0f` (`0x00a594 .. 0x00a5a8`).
     - Phân tách đoạn văn bản theo `RangeSelector` và áp dụng `TextAnimator` (`0x00a280 .. 0x00a928`).
5. **`lynx::animax::CanvasHelperTextra`** (VTable tại `0x0102e8 .. 0x0103d0`):
   - Thực thi 26 phương thức ảo của `ttoffice::tttext::ICanvasHelper` (`0x00abb8 .. 0x00b458`), bao gồm `DrawGlyphs` (`0x00acf4 .. 0x00b174`) với độ nghiêng chữ giả lập `-0.25f` (`0x00af84`), đảo dấu trục Y (`fneg s10, s0` @ `0x00aeb0`), đóng gói `skity::TextRun` (`sizeof = 0x68 = 104 bytes`) và bộ lọc làm mờ `skity::MaskFilter::MakeBlur(BlurStyle::kNormal = 1, blur_radius)` (`0x00b0ac`).
6. **`lynx::animax::TextHelperTextra` & `JNI_OnLoad`** (`0x00b538 .. 0x00b8c3`, VTable tại `0x010460 .. 0x010478`):
   - Khởi tạo singleton `TextHelperTextra` tại `.bss 0x014018`, đăng ký vào `lynx::animax::TextHelper::RegisterImpl` và trả về `0x00010006` (`JNI_VERSION_1_6`).
