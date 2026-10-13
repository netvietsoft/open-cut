# NHIỆM VỤ: TASK_SO_030_libres_pool

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libres_pool.so`
> **Phân công**: `Agent 11 - DESIGNER & Agent 3 - FRONTEND`
> **Cụm Lõi**: `Lõi Đồ họa 2D/3D & Render Giao diện Lynx/Krypton` (Ưu tiên: 5)
> **Dung lượng**: `9.47 MB` | Symbols: `193` | JNI: `0`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libres_pool.so (9.47 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libres_pool\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_030_libres_pool.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
