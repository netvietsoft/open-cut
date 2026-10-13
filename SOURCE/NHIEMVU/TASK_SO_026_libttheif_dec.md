# NHIỆM VỤ: TASK_SO_026_libttheif_dec

> **Mục tiêu**: Giải mã và tái dựng thuật toán cho thư viện `libttheif_dec.so`
> **Phân công**: `Agent 3 - FRONTEND / Native Engine`
> **Cụm Lõi**: `Lõi Xử lý Video, Codec TTFFmpeg & TTPlayer` (Ưu tiên: 4)
> **Dung lượng**: `0.2 MB` | Symbols: `118` | JNI: `0`

## Các bước thực hiện bắt buộc:
- 1. Khảo sát cấu trúc nhị phân libttheif_dec.so (0.2 MB).
- 2. Bóc tách các hàm JNI và C++ demangled vtable.
- 3. Trích xuất thuật toán cốt lõi, pipeline dữ liệu và ánh xạ sang kiến trúc NextAI OpenCut.
- 4. Lưu toàn bộ kết quả giải mã vào: D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libttheif_dec\
- 5. Gửi báo cáo hoàn thành định dạng JSON về: D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO\REPORT_TASK_SO_026_libttheif_dec.json

## Tiêu chí nghiệm thu (Acceptance Criteria):
- [ ] Bóc tách 100% symbols động khả dụng
- [ ] Sinh C++ Interface header tương ứng
- [ ] Không được bịa đặt cấu trúc hàm, trung thực 100%
