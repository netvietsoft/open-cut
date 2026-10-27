# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — PROOF FOR: `libpreload.so`

- **Task ID**: `TASK-160-RECONSTRUCTION-LIBPRELOAD` (`TASK_SO_093_libpreload`) — Target 121 / 169
- **Dung lượng nhị phân**: `3,657,488 bytes` | **SHA-256**: `9f88e5ffe24e072d7ba2fb5a9bfe50378664a36db5998d0524574b8a238a11b9`
- **Bảng `.eh_frame_hdr`**: `0x305cfc` (`8,944` FDEs) | **Bảng `.data` JNI (`0x3800d8`)**: `51` phương thức `JNINativeMethod`
- **Dung lượng C++17 tái dựng**: `2,274,029 bytes` (9 files `.h`/`.cpp`, `0` stubs)

## 1. Bằng Chứng Disassembly AArch64 Trực Tiếp
- `0x27b3d0`: `D10103FF` (`sub sp, sp, #0x40`), `0x27b3ec`: `52800082` (`mov w2, #4`), `0x27b404`: `72A00022` (`movk w2, #1, lsl #16` -> `JNI_VERSION_1_4 = 0x00010004`), `0x27b430`: `52800662` (`mov w2, #0x33` = 51 phương thức JNI tại `0x3800d8`), `0x27b434`: `9400003A` (`bl #0x27b51c` đăng ký lên lớp `com/bytedance/vcloud/strategy/StrategyCenter` tại `.rodata` `0x2fc56e`).
- `0x27b5a4` (`_create`): `0x27b5f4: 52821A00` (`mov w0, #0x10d0` = cấp phát `4,304 bytes` cho `com::bd::vod::ST::StrategyCenter`), `0x27b600: 97F9A1E7` (`bl #0xe3d9c`), `0x27b60c: F906E314` (`str x20, [x24, #0xdc0]`).
- `0x27c18c` (`_setIntValue`): `0x27c18c: B40000C2` (`cbz x2, #0x27c1a4`), `0x27c190: 529877E8` (`mov w8, #0xc3bf` = `50111`), `0x27c194: 6B08007F` (`cmp w3, w8`).
- `0x2919d4` (`com::ss::ttm::player::Parcel::init`): `0x291a0c: A9412018` (`ldp x24, x8, [x0, #0x10]`), `0x291a2c: 91008308` (`add x8, x24, #0x20` = `32 bytes` mỗi phần tử), `0x291a40: 9345FD39` (`asr x25, x9, #5`), `0x291a64: 9344FD4A` (`asr x10, x10, #4`).
- `0x04aac8` (`Json::FastWriter::~FastWriter`): `0x04aad8: 39402008` (`ldrb w8, [x0, #8]`), `0x04aaec: 36000068` (`tbz w8, #0, #0x4aaf8`), `0x04aaf0: F9400E60` (`ldr x0, [x19, #0x18]`).

## 2. Chứng Minh Toán Học & Bố Cục Struct ABI
1. **Phép nhân đôi dung lượng vector 32-byte trong `Parcel::init` (`0x291a38..0x291a8c`)**:
   - Với `sizeof(ParcelEntry) = 32 = 2^5` bytes:
     $$\text{size} = \frac{\text{end\_} - \text{begin\_}}{32} = (\text{end\_} - \text{begin\_}) \gg 5 \quad (\text{asr x25, x9, \#5 @ 0x291a40})$$
     $$2 \times \text{capacity} = 2 \times \frac{\text{cap\_} - \text{begin\_}}{32} = (\text{cap\_} - \text{begin\_}) \gg 4 \quad (\text{asr x10, x10, \#4 @ 0x291a64})$$
2. **Mô hình ước lượng thời gian xem có điều kiện theo phân phối Weibull (`EstPlayTimeByWeibullParams` @ `.rodata` `0x2bbb25`)**:
   - Hàm sống sót Weibull $S(t) = \exp(-(t / \lambda)^k)$ cho nghiệm giải tích thời lượng xem kỳ vọng với ngưỡng xác suất $p \in (0, 1)$ sau khi đã xem $t_0$:
     $$t_{\text{est}} = \lambda \left( \left(\frac{t_0}{\lambda}\right)^k - \ln(p) \right)^{1/k}$$
