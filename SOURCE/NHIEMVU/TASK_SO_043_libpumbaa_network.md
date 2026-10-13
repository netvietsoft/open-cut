# NHIỆM VỤ: TASK_SO_043_libpumbaa_network

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libpumbaa-network.so`
> **Phân công**: `Agent 4 - INTEGRATION/API`
> **Cụm Lõi**: `Lõi Mạng Tốc độ cao & Giao thức TTNet/Cronet` (Ưu tiên: 6)
> **Dung lượng**: `0.05 MB` | Symbols: `68` | JNI: `0`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libpumbaa-network.so (0.05 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libpumbaa-network\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_043_libpumbaa_network.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
