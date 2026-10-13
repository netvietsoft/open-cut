# NHIỆM VỤ: TASK_SO_119_libnapi

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libnapi.so`
> **Phân công**: `Agent 7 - RECONSTRUCTION`
> **Cụm Lõi**: `Lõi Bổ trợ / Tiện ích khác` (Ưu tiên: 99)
> **Dung lượng**: `0.24 MB` | Symbols: `498` | JNI: `0`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libnapi.so (0.24 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libnapi\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_119_libnapi.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
