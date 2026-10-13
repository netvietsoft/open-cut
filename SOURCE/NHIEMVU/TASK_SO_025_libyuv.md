# NHIỆM VỤ: TASK_SO_025_libyuv

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libyuv.so`
> **Phân công**: `Agent 3 - FRONTEND / Native Engine`
> **Cụm Lõi**: `Lõi Xử lý Video, Codec TTFFmpeg & TTPlayer` (Ưu tiên: 4)
> **Dung lượng**: `0.21 MB` | Symbols: `582` | JNI: `0`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libyuv.so (0.21 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libyuv\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_025_libyuv.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
