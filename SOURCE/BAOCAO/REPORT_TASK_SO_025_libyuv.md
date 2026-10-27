# Clean-Room Reconstruction Analysis: `libyuv.so`
# Phân Tích Tái Tạo Phòng Sạch: `libyuv.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libyuv.so`
- **Task ID**: `TASK-198-RECONSTRUCTION-LIBYUV` (`TASK_SO_025_libyuv`)
- **Size**: `215,112` bytes
- **SHA-256**: `c343f4a98ab9dcf07b58609b3344bf62eaf696ce3571c76be616a97e0489191c`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libyuv.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.plt`: `0x0beb0` (`4,000` bytes)
- `.text`: `0x0ce50 .. 0x26634` (`104,420` bytes = `26,105` AArch64 instructions)
- `.rodata`: `0x26640` (`1,904` bytes — `LIBYUV_DISABLE_NEON`, `LIBYUV_DISABLE_ASM`, FourCC lookup tables)
- `.eh_frame_hdr`: `0x26db0` (`8,516` bytes, `1,063` sorted FDE entries)
- `.eh_frame`: `0x28ef8` (`32,096` bytes)
- `.data.rel.ro`: `0x36bb8` (`8` bytes)
- `.data`: `0x38000` (`176` bytes — `YuvConstants` matrices)
- `.bss`: `0x380b0` (`8` bytes — `cpu_info_`)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **PSNR / SSIM Quality Metrics (`ComputeSumSquareError` @ `0x0cffc`, `SumSquareErrorToPsnr` @ `0x0d168`, `CalcFrameSsim` @ `0x0d2a8`)**:
   - Computes $\text{SSE} = \sum_{i=0}^{N-1} (A_i - B_i)^2$ via ARM64 NEON `uabal`/`uabal2` and converts to PSNR:
     $$\text{PSNR} = 10 \log_{10}\left(\frac{255^2 \cdot N}{\text{SSE}}\right)$$
2. **Planar & Semi-Planar Color Space Conversions (`I420Copy` @ `0x0d5f0`, `NV12ToI420` @ `0x0d990`, `NV21ToI420` @ `0x0dc04`)**:
   - De-interleaves semi-planar UV/VU chroma rows using ARM64 NEON `ld2 {v0.16b, v1.16b}` and converts YUV to RGB via 160-byte `YuvConstantsAbi` matrices (`BT.601`, `BT.709`, `BT.2020`).
