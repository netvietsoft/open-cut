# TÀI LIỆU GIẢI MÃ TOÀN DIỆN: `libnative-filters.so`
## Facebook Fresco ImagePipeline Native Filters
**Mô-đun**: `com.facebook.imagepipeline.nativecode`  
**Dự án**: NextAI OpenCut (`com.nextai.opencut`)  
**Tình trạng kiểm toán**: Đã khắc phục triệt để phát hiện #7 / #8 trong Báo cáo Kiểm toán `TASK-AUDIT-NATIVE-010`.

---

## 1. TỔNG QUAN VÀ BẰNG CHỨNG XÁC THỰC

Binary `libnative-filters.so` (34,824 bytes) chịu trách nhiệm xử lý các bộ lọc đồ họa 2D nhanh trực tiếp trên vùng nhớ CPU Bitmap (sử dụng NDK `jnigraphics` qua `AndroidBitmap_lockPixels`):
- Các hàm native được đăng ký động bằng `RegisterNatives` trong `JNI_OnLoad` tại địa chỉ `0xa40`:
  1. `com/facebook/imagepipeline/nativecode/NativeBlurFilter`:
     - `nativeIterativeBoxBlur(Landroid/graphics/Bitmap;II)V` $\to$ Con trỏ hàm tại `0xc00`.
  2. `com/facebook/imagepipeline/nativecode/NativeRoundingFilter`:
     - `nativeToCircleFilter(Landroid/graphics/Bitmap;Z)V` $\to$ Con trỏ hàm tại `0x13bc`.
     - `nativeToCircleWithBorderFilter(Landroid/graphics/Bitmap;IIZ)V` $\to$ Con trỏ hàm tại `0x13d0`.

---

## 2. NGUYÊN LÝ THUẬT TOÁN ĐÃ TÁI CẤU TRÚC

### 1. Thuật toán Làm Mờ Hộp Lặp (Iterative Box Blur)
- **Độ phức tạp**: $O(W \times H)$ cho mỗi pass (không phụ thuộc vào bán kính `radius`).
- **Nguyên lý cửa sổ trượt (Moving Average)**:
  - Khởi tạo tổng `sumA, sumR, sumG, sumB` cho đoạn $[-r, +r]$.
  - Khi dịch sang pixel tiếp theo: chỉ cần lấy `sum += pixel_mới - pixel_cũ`.
  - Thực hiện tách biệt 2 lượt: Lượt ngang (Horizontal) $\to$ Lượt dọc (Vertical). Lặp lại `iterations` lần cho kết quả tương đương Gaussian Blur nhưng tốc độ cao hơn gấp nhiều lần trên CPU di động.

### 2. Thuật toán Cắt Tròn Ảnh Kèm Viền (Circular Rounding & Border Ring)
- **Cắt tròn sub-pixel**: Tính khoảng cách Euclid $d = \sqrt{(x - cx)^2 + (y - cy)^2}$.
- Khử răng cưa biên bằng hệ số diện tích phủ sub-pixel: $\alpha_{\text{frac}} = \text{clamp}(r + 0.5 - d, 0, 1)$.
- Vùng viền `[r - borderWidth, r]` được pha màu mượt (Interpolation) với màu gốc của ảnh.

---

## 3. CÁC TỆP ĐÃ TÁI CẤU TRÚC ĐẦY ĐỦ 100% THÂN HÀM

- [`native_filters_interface.h`](native_filters_interface.h): Khai báo JNI và các hàm C++ lõi.
- [`native_filters_pseudocode.cpp`](native_filters_pseudocode.cpp): 100% thân hàm thực tế, xử lý trực tiếp buffer ARGB_8888, không có stub.
