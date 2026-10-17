# BÁO CÁO NGHIỆM THU: REPORT_TASK_SO_028_libanimax_bytevc1

- **Task ID**: `TASK_SO_028_libanimax_bytevc1`
- **Thư viện mục tiêu**: `libanimax_bytevc1.so` (51,184 bytes / 50.0 KB)
- **Agent thực hiện**: `Agent 3 - FRONTEND & Agent 13 - AUDITOR`
- **Trạng thái**: `COMPLETED (100%)`
- **Chứng nhận đối kháng**: `VERIFIED_AND_ACCEPTED` tại `SO-CAI-DOI-KHANG/LEDGER_DOI_KHANG.json`

## Bằng chứng kỹ thuật:
- **Symbols**: 64
- **JNI Exports**: 1 (`JNI_OnLoad` tại opcode `0x59cc`, trả về `0x10006`)
- **C++ Demangled**: 40
- **Thư mục tái dựng**: `GIAI-MA/libanimax_bytevc1/` (11 files, 62,544 bytes / 61.08 KB, 0 stub)
- **Bằng chứng xác minh**: `PHAN-BIEN/BANG-CHUNG-XAC-MINH/PROOF_libanimax_bytevc1.md` & `.json`
- **Kiểm thử khép kín**: 169/169 tests PASS (100.0%) trong `verify_reconstruction_suite.py`

## Tóm tắt cấu trúc & thuật toán:
1. `animax_bytevc1_types.h`: ABI con trỏ hàm 28 ký hiệu `ByteVC1_*` từ `libByteVC1_dec.so`, enum định dạng điểm ảnh `YUVPixFmt` (`PIX_FMT_YUV420P`, `NV12`, `P010`), `YUVChannelType`, `AnimaXLogLevel`.
2. `animax_yuv_frame`: Khung hình `lynx::animax::YUVFrameInfo` quản lý 3 mặt phẳng Y, U, V, tính toán linesize, và ma trận chuyển đổi màu ITU-R BT.709 hai chiều khả nghịch sai số $< 1.0$ LSB; tiện ích RAII `ScopedGLResetRestore`.
3. `animax_bytevc1_loader`: Trình nạp động `ByteVC1LibLoader` (opcode `0x4660`) nạp `libByteVC1_dec.so` qua `dlopen(0x1002)`, rẽ nhánh phân giải ABI v1 vs v2 (opcode `0x4788`, `0x4790`), cung cấp bộ mô phỏng phần mềm sạch.
4. `animax_bytevc1_decoder`: Bộ giải mã `VideoDecoderByteVc1` nạp bitstream HEVC, kiểm tra Annex-B NAL unit (VPS/SPS/PPS/IDR), giải mã frame, chuyển tiếp YUV vào `YUVFrameInfo`, kiểm tra hỗ trợ phần cứng hệ thống 4K@60.
5. `animax_bytevc1_jni`: `JNI_OnLoad` (opcode `0x59cc`) cấp phát 32 bytes `VideoPlayerProvider`, đăng ký provider `"bytevc1"` vào `lynx::animax::RegisterVideoPlayerProvider`, xuất log `"animax bytevc1 loaded, register bytevc1 success."`.
6. `animax_bytevc1_interface` & `pseudocode`: Động cơ master và chuỗi tự kiểm thử 7 giai đoạn.
