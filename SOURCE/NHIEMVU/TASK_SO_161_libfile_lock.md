# NHIỆM VỤ: TASK_SO_161_libfile_lock

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libfile_lock.so`
> **Phân công**: `Agent 7 - RECONSTRUCTION`
> **Cụm Lõi**: `Lõi Bổ trợ / Tiện ích khác` (Ưu tiên: 99)
> **Dung lượng**: `0.02 MB` | Symbols: `25` | JNI: `6`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libfile_lock.so (0.02 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libfile_lock\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_161_libfile_lock.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
