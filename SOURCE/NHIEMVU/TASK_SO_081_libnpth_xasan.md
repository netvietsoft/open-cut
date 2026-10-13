# NHIỆM VỤ: TASK_SO_081_libnpth_xasan

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libnpth_xasan.so`
> **Phân công**: `Agent 10 - DEVOPS & Agent 6 - TESTER`
> **Cụm Lõi**: `Lõi Giám sát Hiệu năng, RAM & Crash NPTH/Slardar` (Ưu tiên: 10)
> **Dung lượng**: `0.04 MB` | Symbols: `85` | JNI: `0`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libnpth_xasan.so (0.04 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libnpth_xasan\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_081_libnpth_xasan.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
