# NHIỆM VỤ: TASK_SO_009_libterrain

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libterrain.so`
> **Phân công**: `Agent 1 - ARCHITECT & Agent 7 - RECONSTRUCTION`
> **Cụm Lõi**: `Lõi Trí tuệ Nhân tạo, Thị giác Máy tính & Pitaya` (Ưu tiên: 2)
> **Dung lượng**: `0.32 MB` | Symbols: `350` | JNI: `0`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libterrain.so (0.32 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libterrain\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_009_libterrain.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
