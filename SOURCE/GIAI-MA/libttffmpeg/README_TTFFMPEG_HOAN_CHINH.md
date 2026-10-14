# README — TÁI CẤU TRÚC HOÀN CHỈNH THƯ VIỆN LÕI MULTIMEDIA `libttffmpeg.so`
**Dự án**: NextAI OpenCut (`com.nextai.opencut`)  
**Tiêu chuẩn áp dụng**: `Development_Workspace_Standard_V2.1_Design_Gated` | Hiến pháp `AGENTS.md` & `GEMINI.md`  
**Thư viện**: `libttffmpeg.so` (arm64-v8a: 5,771,392 bytes, SHA-256: `755c8dcac05951c52c53a3d3e02f0fe1c597b6cae3191622d3d9b220c8ba7fd9`)  
**Tình trạng hoàn thành**: **100% THÂN HÀM THỰC TẾ (ZERO STUB - PARITY VERIFIED)**

---

## 1. TỔNG QUAN KIẾN TRÚC & PHÂN HỆ ĐÃ GIẢI MÃ
Khác với bản FFmpeg tiêu chuẩn mã nguồn mở, `libttffmpeg.so` là phiên bản FFmpeg đã được các kỹ sư ByteDance tùy biến sâu rộng để phục vụ hệ sinh thái TikTok và CapCut, bổ sung các phân hệ độc quyền:

1. **Phân hệ Bộ Tham Số & NAL Unit H.264/H.265 (`tt_h264_parser.h/cpp`)**:
   - Cấp phát và quản lý `H2645NAL` (kích thước `0x68` bytes = 104 bytes tại opcode `0x1c8298`).
   - Cấp phát bảng quản lý tập tham số `H264ParamSets` (kích thước `0x920` bytes = 2,336 bytes tại opcode `0x1c82f8`).
   - Khôi phục cấu trúc `SPS` (`0x14b8` = 5,304 bytes tại `0x1c8390`) và `PPS` (`0x2a740` = 173,888 bytes tại `0x1c8364`).
   - Khôi phục bảng nhảy (Jump Table) truy vấn các trường SPS (`tt_SPS_get_int_field` tại `0x1c83b0`..`0x1c8404`):
     - Field 0 -> Profile IDC (`offset 0x14`)
     - Field 1 -> Level IDC (`offset 0x40`)
     - Field 2 -> Chroma Format IDC (`offset 0x18`)
     - Field 3 -> Bit Depth Luma (`offset 0x1c`)
     - Field 4 -> Bit Depth Chroma (`offset 0x20`)
     - Field 5 -> Max Num Reorder Frames (`offset 0x298`)

2. **Ngữ Cảnh Tính Toán Picture Order Count (POC) (`tt_H264POCContext`)**:
   - Kích thước cấu trúc chuẩn xác: `0x2c` (44 bytes tại opcode `0x1c8408`).
   - Khôi phục mảng `delta_poc[2]` tại `offset 0x0c` và `0x10` (opcode `0x1c8414`).
   - Bảng nhảy đọc/ghi đối xứng 9 trường số nguyên POC (`0x1c8420` và `0x1c8488`):
     - `field_28` (offset 0x28) <-> Field 0 (Current POC)
     - `field_24` (offset 0x24) <-> Field 1 (POC Cycle)
     - `field_18` (offset 0x18) <-> Field 2 (Prev POC MSB)
     - `field_1c` (offset 0x1c) <-> Field 3 (Prev POC LSB)
     - `field_14` (offset 0x14) <-> Field 4 (Delta POC Bottom)
     - `field_20` (offset 0x20) <-> Field 5 (Prev Frame Num Offset)
     - `field_04` (offset 0x04) <-> Field 6 (POC LSB)
     - `field_00` (offset 0x00) <-> Field 7 (Prev POC)
     - `field_08` (offset 0x08) <-> Field 8 (Prev Frame Num)

3. **Thuật Toán Quét Nhanh Bitstream MMCO == 5 (`tt_scan_mmco_reset`)**:
   - Giải thuật bóc tách mã Exp-Golomb (`ue(v)`) tối ưu trực tiếp trên thanh ghi ARM64:
     `clz w1, w1; sub w1, w2, w1` (opcode `0x1c85a4`..`0x1c85bc`).
   - Vòng lặp giải mã tiêu đề phân đoạn (Slice Header) tìm kiếm lệnh Memory Management Control Operation:
     - Nếu phát hiện `mmco == 5` (`0x001c8728: cmp w0, #5; b.eq #0x1c87ac`), trả về ngay lập tức `1`.
     - Lệnh MMCO 5 giải phóng toàn bộ Decoded Picture Buffer (DPB), hoạt động như một điểm khôi phục tức thì cho bộ tua video (Instantaneous Seek).

4. **Hệ Thống 7 Giao Thức Mạng Độc Quyền (`tt_protocol_registry.h/cpp`)**:
   - Khôi phục hàm điều phối trung tâm `tt_register_protocol` (`0x343d68`) với kích thước ABI chuẩn `sizeof(URLProtocol) = 0xc0` (192 bytes):
     - `"mdl"`: MediaDataLoader (CDN cache và tăng tốc tải video P2P).
     - `"quic"`: Giao thức vận chuyển TTQUIC độ trễ cực thấp.
     - `"httpx"`: HTTP Streaming tùy biến với header injection và nạp trước phân đoạn.
     - `"mem"`: Phát video trực tiếp từ bộ đệm RAM không qua lưu đĩa.
     - `"live"`: Phát trực tiếp FLV/RTMP/HLS Live.
     - `"hlsproxy"`: Proxy giải mã phân đoạn video HLS đã mã hóa (`.ts` / `.m4s`).
     - `"memorydatasource"`: Cầu nối Android MediaDataSource.

5. **Bộ Hooks Mạng TTNet, DNS & SSL Pinning**:
   - Bảng hook toàn cục tại `0x7be350` hỗ trợ định tuyến toàn bộ DNS và Socket IO qua TTNet/Cronet.
   - Callback xác thực chứng chỉ SSL tại `0x7be348` (`tt_set_verify_callback`) chống tấn công giả mạo Man-In-The-Middle (MITM).

6. **Phân Hệ Giải Mã DRM & Động Cơ Mã Hóa Luồng GF(2^8) (`tt_drm_crypto.h/cpp`)**:
   - Đăng ký 3 hàm DRM (init, decrypt, free) tại `0x7c57d0`.
   - Ngữ cảnh mã hóa luồng `TTDeprecatedCtx` (`0x130` = 304 bytes tại `0x3636bc`).
   - Khởi tạo bảng thế S-box trường hữu hạn Galois Field GF($2^8$) với đa thức tối giản $x^8 + x^4 + x^3 + x + 1$ (`0x11b` tại opcode `0x36373c`).

7. **Cầu Nối Ứng Dụng TTM & Định Danh An Toàn (`tt_app_cast.h/cpp`)**:
   - Con trỏ magic tĩnh tự tham chiếu: `s_ttm_app_magic` tại `0x584810`.
   - Ép kiểu an toàn `av_ttm_app_cast` (`0x3775bc`) kiểm tra hằng số phiên bản callback `0x01343f0f` (ngày 2020-12-31 theo định dạng ByteDance).
   - Truy xuất an toàn `AVCodecContext` từ luồng nội bộ `AVStreamInternal` (offset `0x18` tại `0x1c8284`).

---

## 2. DANH SÁCH MÃ NGUỒN C++ TÁI CẤU TRÚC
| Tên File | Kích Thước | Vai Trò & Thuật Toán |
|---|---:|---|
| [`ttffmpeg_types.h`](ttffmpeg_types.h) | ~6.5 KB | Khai báo toàn bộ cấu trúc dữ liệu, ABI offsets và hằng số nhị phân |
| [`tt_h264_parser.h`](tt_h264_parser.h) | ~2.5 KB | Khai báo API NAL, ParamSets, POC và MMCO |
| [`tt_h264_parser.cpp`](tt_h264_parser.cpp) | ~14.2 KB | Hiện thực 100% NAL, SPS, PPS, POC jump tables và MMCO Exp-Golomb reader |
| [`tt_protocol_registry.h`](tt_protocol_registry.h) | ~2.2 KB | Khai báo giao thức mạng và TTNet hooks |
| [`tt_protocol_registry.cpp`](tt_protocol_registry.cpp) | ~7.8 KB | Hiện thực đăng ký 7 protocols độc quyền ByteDance và network callbacks |
| [`tt_drm_crypto.h`](tt_drm_crypto.h) | ~1.5 KB | Khai báo DRM decryption callbacks và GF(2^8) cipher |
| [`tt_drm_crypto.cpp`](tt_drm_crypto.cpp) | ~6.2 KB | Hiện thực giải mã DRM và bảng nhân GF(2^8) đa thức 0x11b |
| [`tt_app_cast.h`](tt_app_cast.h) | ~1.2 KB | Khai báo định danh TTM app cast và monotonic clocks |
| [`tt_app_cast.cpp`](tt_app_cast.cpp) | ~3.8 KB | Hiện thực kiểm tra magic 0x584810 và phiên bản 0x01343f0f |
| [`ttffmpeg_interface.h`](ttffmpeg_interface.h) | ~2.0 KB | Header hợp nhất cho toàn bộ hệ thống TTFFmpeg |
| [`ttffmpeg_pseudocode.cpp`](ttffmpeg_pseudocode.cpp) | ~7.5 KB | Hiện thực điều phối vòng đời engine và bộ kiểm chứng thực tế |
