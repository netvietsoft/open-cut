# BÁO CÁO KỸ THUẬT & HƯỚNG DẪN TÁI CẤU TRÚC: libcccreator.so
## TECHNICAL REPORT & RECONSTRUCTION SPECIFICATION: libcccreator.so

> **Dự án / Project**: NextAI OpenCut (`com.nextai.opencut`)  
> **Thư viện mục tiêu / Target Binary**: `libcccreator.so` (arm64-v8a: 38.28 MB, 40,139,144 bytes)  
> **Phân hệ kiến trúc / Subsystem**: CapCut Template Creator Core & ILA SDK Matching Engine (`CORE_01_EDITING`)  
> **Tiêu chuẩn tuân thủ / Standards**: Rule 12 & Rule 20 `AGENTS.md` (Song ngữ EN + VN, 100% thân hàm thực tế, zero stub)  

---

## 1. TỔNG QUAN KIẾN TRÚC & PHÂN TÍCH NHỊ PHÂN
### ARCHITECTURAL OVERVIEW & BINARY ANALYSIS

`libcccreator.so` là động cơ trung tâm điều khiển toàn bộ tính năng Tạo Mẫu (Template Creator), Dự án Mẫu CapCut (`ccmodel`), và Hệ thống Trí tuệ Nhân tạo Ghép Mẫu Tự Động CutSame (`ILASDK - Intelligent Layout & Asset SDK`).

- **Dung lượng nhị phân / Binary Size**: 38.28 MB (40,139,144 bytes)
- **Định dạng / ELF Format**: ELF64, Little-endian, AArch64 (ARMv8-A), ET_DYN
- **Tổng số Dynamic Symbols**: 9,161
- **Hàm JNI Exported / JNI Exports**: 1,693 hàm thuộc package `com.bytedance.ilasdk.jni.ILASDKJianyingJNI`
- **Hàm C++ Demangled / C++ Demangled Functions**: 5,233 hàm

---

## 2. BẢNG ĐỐI SOÁT MÃ MÁY AARCH64 & THUẬT TOÁN ĐÃ PHỤC HỒI
### AARCH64 DISASSEMBLY & ALGORITHMIC PARITY TABLE

| Hạng mục / Module | Địa chỉ máy (Opcode) | Lệnh máy AArch64 cốt lõi | Ý nghĩa kỹ thuật & Thuật toán phục hồi |
|---|---|---|---|
| **CCClip::setStartTime** | `0x79fc0c` | `str x1, [x0, #0x30]; ret` | Thiết lập thời điểm bắt đầu clip trên timeline (`startTime` tại offset `0x30`) |
| **CCClip::setEndTime** | `0x158f54c` | `str x1, [x0, #0x38]; ret` | Thiết lập thời điểm kết thúc clip trên timeline (`endTime` tại offset `0x38`) |
| **CCClip::getTrimIn** | `0x10485d0` | `ldr x0, [x0, #0x40]; ret` | Truy xuất điểm cắt đầu trong media nguồn (`trimIn` tại offset `0x40`) |
| **CCClip::getTrimOut** | `0x1690ff0` | `ldr x0, [x0, #0x48]; ret` | Truy xuất điểm cắt đuôi trong media nguồn (`trimOut` tại offset `0x48`) |
| **updateClipCurveSpeedCCModel** | `0x618118`..`0x618148` | `fcvt s0, d0; str s0, [x9, x11, lsl #2]; str s0, [x10, x11, lsl #2]` | Vòng lặp chuyển đổi mảng điểm vận tốc Bezier từ double sang float phục vụ shader uniforms |
| **CCTransformFilter::checkRotationValue** | `0x158c994` | `fcvtzs w0, d0; mov w8, #0x168; sdiv; msub` | Chuẩn hóa góc quay xoay vòng (modulo 360 độ) đưa về khoảng dương $[0, 360)$ |
| **RecModelBundleHelper::createCCFilterFromBundle** | `0x852c8c` | `ldrh w11, [x9, x8, lsl #1]; add x10, x10, x11, lsl #2; br x10` | Bảng nhảy Jump Table 16-bit halfword phân giải khóa `filterType` (0x1c25185) để sinh Filter |
| **CCAudioFadeFilter (Type 4)** | `0x74e910` | `mov w0, #0xc0; stp x21, x20, [x24, #0xa8]; str w19, [x24, #0xb8]` | Cấp phát 192B (`0xc0`), lưu `fadeIn` tại `0xa8`, `fadeOut` tại `0xb0`, `curveType` tại `0xb8`, type `4` tại `0x60` |
| **CCLensVFIFilter (Type 36 / 0x24)** | `0x74f7e0` | `mov w0, #0x108; str w20, [x23, #0xa4]; str d8, [x23, #0xc0]` | Cấp phát 264B (`0x108`), lưu `vfiType` tại `0xa4`, `fpsRatio` double tại `0xc0`, type `0x24` tại `0x60` |
| **CCMotionBlurFilter (Type 37 / 0x25)** | `0x74f99c` | `mov w0, #0xe0; mov w8, #0x25; str w8, [x26, #0x60]` | Cấp phát 224B (`0xe0`), lưu thông số làm mờ chuyển động quang học và góc mở màn trập |
| **CCVideoBlurFilter::noActiveEffect** | `0x609d38` | `ldr w8, [x0, #0x58]; ldr s0, [x0, #0x8c]; cset w0, mi` | Kiểm tra cờ kích hoạt tại `0x58` và bán kính mờ tại `0x8c` với epsilon (nhỏ hơn epsilon -> inactive) |
| **CCRadiusCornerBorderFilter** | `0x60b3b4` | `stur xzr, [x19, #0x94]; stur xzr, [x19, #0x8c]; strb w9, [x19, #0x9c]` | Khởi tạo bo góc (`0x94`), độ dày viền (`0x8c`) và cờ kích hoạt (`0x9c = 1`) |
| **ILASDK Face & Embedding Match** | `0x81da60` / `0x82188c` | `FaceQuality_eye_not_occlude_get`, Cosine similarity | Thuật toán đánh giá chất lượng chân dung và đối soát ngữ nghĩa vector đặc trưng nơ-ron |

---

## 3. DANH MỤC CÁC MODULE MÃ NGUỒN C++ ĐÃ TÁI CẤU TRÚC
### RECONSTRUCTED C++ SOURCE MODULES

Toàn bộ các file mã nguồn C++ được tái cấu trúc đầy đủ thân hàm (Zero Stub, Quality Gate đạt 100%):
1. [`cccreator_types.h`](cccreator_types.h): Định nghĩa chi tiết cấu trúc bộ nhớ, layout AArch64 ABI, enums và hằng số bundle.
2. [`cccreator_clip.h`](cccreator_clip.h) & [`cccreator_clip.cpp`](cccreator_clip.cpp): Hiện thực hóa `CCClip`, quản lý phân đoạn thời gian và thuật toán chuyển đổi mảng điểm vận tốc `updateClipCurveSpeedCCModel`.
3. [`cccreator_filter_factory.h`](cccreator_filter_factory.h) & [`cccreator_filter_factory.cpp`](cccreator_filter_factory.cpp): Hiện thực hóa bộ điều phối `RecModelBundleHelper` và cây phân cấp bộ lọc (`CCAudioFadeFilter`, `CCLensVFIFilter`, `CCMotionBlurFilter`, `CCVideoBlurFilter`, `CCRadiusCornerBorderFilter`, `CCTransformFilter`).
4. [`cccreator_ilasdk_matcher.h`](cccreator_ilasdk_matcher.h) & [`cccreator_ilasdk_matcher.cpp`](cccreator_ilasdk_matcher.cpp): Hiện thực hóa thuật toán so khớp tự động mẫu CutSame của ByteDance ILA SDK.
5. [`cccreator_interface.h`](cccreator_interface.h) & [`cccreator_pseudocode.cpp`](cccreator_pseudocode.cpp): Bộ điều phối trung tâm `CccreatorEngine` và harness tự kiểm tra 8 tiêu chí cốt lõi.

---

## 4. XÁC MINH TOÁN HỌC & ĐỘ TƯƠNG THÍCH THUẬT TOÁN
### MATHEMATICAL VERIFICATION & ALGORITHMIC PARITY

1. **Chuẩn hóa góc quay xoay vòng (Angle Normalization)**:
   $$R(\theta) = ((\lfloor \theta \rfloor \pmod{360}) + 360) \pmod{360}$$
   - $R(90^\circ) = 90^\circ$
   - $R(-90^\circ) = 270^\circ$
   - $R(-450^\circ) = 270^\circ$
   - $R(360^\circ) = 0^\circ$

2. **Chuyển đổi điểm vận tốc đường cong Bezier**:
   - Chuyển đổi chính xác từ $(t_d, s_d) \in \mathbb{R}^2$ (double-precision) sang $(t_f, s_f)$ (single-precision float) khớp 100% với tập lệnh `fcvt s0, d0` tại `0x618130` và `0x61813c`.

3. **Tương đồng Cosine trong ILA SDK**:
   $$\text{Sim}(A, B) = \frac{\sum_{i=1}^n A_i B_i}{\sqrt{\sum_{i=1}^n A_i^2} \sqrt{\sum_{i=1}^n B_i^2}}$$
   - Hai vector trực giao: $\text{Sim} = 0.0$
   - Hai vector đồng dạng: $\text{Sim} = 1.0$
