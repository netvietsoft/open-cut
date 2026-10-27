# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libtttext_lite.so` (`TASK-132` / `TASK_SO_115_libtttext_lite`)

- **Thư viện mục tiêu**: `libtttext_lite.so` (ByteDance Lynx / TTOffice TTText Lite Typography, Shaping, Bidi & TextLayout Engine)
- **Dung lượng nhị phân gốc**: `297,312 bytes` (`0x48960`)
- **Mã băm SHA-256**: `8860b2ff8bdd7458117fb7475fdfd9c84accda90c492d1572714ef9e8260282e`
- **Dung lượng C++17 phòng sạch tái cấu trúc**: `675,258 bytes` (9 files trong `SOURCE/GIAI-MA/libtttext_lite/`, `0` stub)
- **Số lượng lệnh máy AArch64 đối chiếu**: `4,993` lệnh từ `.text` (`0x014000 .. 0x04014c`)
- **Số lượng ký hiệu xuất (`.dynsym` Exported Symbols)**: `434` ký hiệu

---

## 1. Đối Chiếu Opcode AArch64 Cốt Lõi (Direct Binary Disassembly Match)

| Địa chỉ VA | Opcode (Hex) | Lệnh Hợp Ngữ AArch64 | Hàm / Ý Nghĩa Toán Học |
|---|---|---|---|
| `0x01a7a0` | `d100c3ff` | `sub sp, sp, #0x30` | Prologue của `JNI_OnLoad` (`0x01a7a0`, `132 B`) |
| `0x01a7b8` | `528000d3` | `mov w19, #6` | Khởi tạo hằng số `JNI_VERSION_1_6` (`0x00010006`) phần thấp |
| `0x01a7bc` | `72a00033` | `movk w19, #1, lsl #16` | Khởi tạo hằng số `JNI_VERSION_1_6` (`0x00010006`) phần cao |
| `0x01c588` | `3dc27980` | `ldr q0, [x12, #0x9e0]` | `DefaultBidiResult` nạp vector `uint32x4_t {0, 1, 2, 3}` từ `.rodata` `0x00d9e0` |
| `0x01c59c` | `0f07e7c1` | `movi v1.8b, #0xfe` | `DefaultBidiResult` điền mức Bidi `0xFE` (`UBIDI_DEFAULT_LTR`) cho 8 ký tự/vòng |
| `0x01d7b8` | `90ffff80` | `adrp x0, #0xd000` | `HarfbuzzLib::LoadHarfbuzzLib` nạp tên `"libkryptoni18n.so"` (`.rodata` `0x00dd29`) |
| `0x01dbf4` | `52802700` | `mov w0, #0x138` | Cấp phát bảng 39 con trỏ hàm HarfBuzz (`39 * 8 = 312 = 0x138` bytes) |
| `0x02b284` | `9127f210` | `add x16, x16, #0x9fc` | `BoundaryAnalyst` trỏ tới bảng nhảy 175-byte `.rodata` `0x00d9fc` (`U+0009..U+00B7`) |
| `0x02ca84` | `39407008` | `ldrb w8, [x0, #0x1c]` | `LayoutMeasurer::CalcRunHeightByLinePitch` đọc `Spacing::line_height_rule` (`+0x1C`) |
| `0x02cbe0` | `1e3c1002` | `fmov s2, #-0.50000000` | `LayoutMeasurer::CalcElementY` nhân `-0.5f` khi căn giữa dọc (`kCenter = 3`) |
| `0x0307f8` | `91002000` | `add x0, x0, #8` | `BaseRun::ControlRunList()` trả về `.data` `0x048008` (6 cặp ký tự điều khiển) |
| `0x030804` | `9101a000` | `add x0, x0, #0x68` | `BaseRun::SpaceList()` trả về `.data` `0x048068` (`" "`, `"\u200b"`, `"\xa0"`) |
| `0x033990` | `51001828` | `sub w8, w1, #6` | `StyleManager::GetStyleValue` dịch chỉ số `AttributeType` (`6..19 -> 0..13`) |
| `0x033a5c` | `fd455d20` | `ldr d0, [x9, #0xab8]` | `StyleManager::GetStyle` nạp `{13.333333f, 1.0f}` từ `.rodata` `0x00dab8` vào `Style+0x28` |
| `0x03d29c` | `5296e2e8` | `mov w8, #0xb717` | `PointF::operator==` nạp phần thấp của `kFloatEpsilon = 0x38D1B717` (`1.0e-4f`) |
| `0x03d2a0` | `72a71a28` | `movk w8, #0x38d1, lsl #16` | `PointF::operator==` nạp phần cao của `kFloatEpsilon = 0x38D1B717` (`1.0e-4f`) |
| `0x03d500` | `0ea00800` | `rev64 v0.2s, v0.2s` | `Range::Swap()` đảo 2 trường 32-bit `start` và `end` bằng lệnh SIMD `rev64` |
| `0x03ecf8` | `331a6540` | `bfi w0, w10, #6, #0x1a` | `U8CharToU32` ghép 6 bit của byte tiếp theo vào mã UTF-32 |
| `0x03ed78` | `1e2d1001` | `fmov s1, #0.75000000` | `U8StringToU32` nhân độ dài UTF-8 với `0.75f` để `reserve` bộ nhớ UTF-32 |

---

## 2. Xác Minh Bố Cục ABI (`Style`, `Spacing`, `HarfbuzzFuncTable`)

1. **`ttoffice::tttext::Style` (`0xA0 = 160 bytes`)**:
   - `+0x00..+0x17`: `font_family` (`std::string`, 24B)
   - `+0x18`: `font_style_packed` (`0x00050190`: `Weight=400`, `Width=5`, `Slant=0`)
   - `+0x28`: `text_size` (`13.333333f = 0x41555555`) & `+0x2C`: `text_scale` (`1.0f = 0x3F800000`)
   - `+0x30..+0x78`: 14 thuộc tính ánh xạ qua bảng nhảy `.rodata` `0x00daf8` (`GetStyleValue`), `0x00db06` (`GetStyle`), `0x00db14` (`SetStyle`).
2. **`ttoffice::tttext::HarfbuzzFuncTable` (`0x138 = 312 bytes`)**:
   - Gồm đúng 39 con trỏ hàm `hb_*` nạp động từ `"libkryptoni18n.so"` trong `HarfbuzzLib::LoadHarfbuzzLib` (`0x01d798..0x01dd34`).
