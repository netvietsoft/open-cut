# NHIỆM VỤ: TASK_SO_001_libclipflow

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libclipflow.so`
> **Phân công**: `Agent 3 - FRONTEND / C++ Engine & Agent 1 - ARCHITECT`
> **Cụm Lõi**: `Lõi Biên tập Video, NLE & Timeline` (Ưu tiên: 1)
> **Dung lượng**: `4.69 MB` | Symbols: `9802` | JNI: `2498`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libclipflow.so (4.69 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libclipflow\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_001_libclipflow.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
