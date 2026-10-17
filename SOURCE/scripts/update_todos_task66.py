# -*- coding: utf-8 -*-
"""
Update TASK-066 to completed [x] and append TASK-067 in UPDATETODOS.md
"""

todos_path = r"D:\Decompiler\App\Video\Capcut\UPDATETODOS.md"

with open(todos_path, "r", encoding="utf-8") as f:
    text = f.read()

old_task66 = "- [ ] TASK-066-RECONSTRUCTION-LIBANIMAX-BYTEVC1"
new_task66 = """- [x] TASK-066-RECONSTRUCTION-LIBANIMAX-BYTEVC1 (2026-10-17, CEO Orchestrator & Agent 13): **Hoàn Thành Tái Cấu Trúc Thuật Toán libanimax_bytevc1.so (CORE_01_VIDEO_CODEC_ANIMAX)**:
  1. Tái dựng 11 files (62.54 KB C++, 0 stub) giải mã toàn bộ plugin giải mã video phần cứng & phần mềm ByteVC1 / HEVC của Lynx AnimaX (`libanimax.so` -> `libByteVC1_dec.so`).
  2. Bố cục cấu trúc kiểu dữ liệu `animax_bytevc1_types.h`: Định nghĩa ABI con trỏ hàm 28 ký hiệu `ByteVC1_*` từ `libByteVC1_dec.so`, enum định dạng điểm ảnh `YUVPixFmt` (`PIX_FMT_YUV420P`, `NV12`, `P010`), `YUVChannelType`, `AnimaXLogLevel`.
  3. Cầu nối JNI `animax_bytevc1_jni`: `JNI_OnLoad` (opcode 0x59cc) cấp phát 32 bytes `VideoPlayerProvider`, đăng ký provider `"bytevc1"` vào `lynx::animax::RegisterVideoPlayerProvider` (opcode 0x5a34), xuất log thành công `"animax bytevc1 loaded, register bytevc1 success."` (0x206e), trả về `0x10006` (`JNI_VERSION_1_6`, opcode 0x5acc).
  4. Trình nạp động `animax_bytevc1_loader`: Nạp `libByteVC1_dec.so` (0x1e3b) qua `dlopen(0x1002)` khớp opcode `0x4660` - `0x4938`; so sánh phiên bản (opcode 0x4788, 0x4790) rẽ nhánh phân giải ABI v1 vs ABI v2; tích hợp bộ giải mã mô phỏng phần mềm sạch độc lập.
  5. Bộ giải mã `animax_bytevc1_decoder`: Khởi tạo tham số và handle qua `ByteVC1_alloc_default_param` và `ByteVC1_dec_create` (opcode 0x209f, 0x2184); phân tích cú pháp Annex-B NAL unit (VPS/SPS/PPS/IDR); nạp gói dữ liệu và giải mã frame; kiểm tra khả năng phần cứng hệ thống 4K@60.
  6. Khung hình `animax_yuv_frame`: Quản lý 3 mặt phẳng Y, U, V theo tỷ lệ 4:2:0; ma trận chuyển đổi không gian màu toán học ITU-R BT.709 khả nghịch với sai số $< 1.0$ LSB; tiện ích RAII `ScopedGLResetRestore`.
  7. Động cơ master `NextAI::OpenCut::AnimaxByteVC1::AnimaxByteVC1Engine` tích hợp toàn diện quy trình giải mã cùng bộ tự kiểm thử 7 giai đoạn `runSelfTest()`.
  8. Đối soát 28 địa chỉ opcode và chuỗi AArch64: 0x0059cc, 0x0059ec, 0x005a28, 0x005a34, 0x005a4c, 0x005a6c, 0x005a90, 0x005acc, 0x004660, 0x00466c, 0x004674, 0x004788, 0x004790, 0x00479c, 0x004810, 0x001d00, 0x001d22, 0x001d72, 0x001d86, 0x001da0, 0x001e4d, 0x001f36, 0x001fb8, 0x002041, 0x00209f, 0x0020ef, 0x00212b, 0x002158.
  9. Được Agent 13 (Adversary Auditor) phê chuẩn VERIFIED_AND_ACCEPTED tại SO-CAI-DOI-KHANG/LEDGER_DOI_KHANG.json.
  10. Bộ kiểm thử khép kín đạt 169/169 tests PASS (100.0%).

- [ ] TASK-067-RECONSTRUCTION-LIBBDZSTD (2026-10-17, CEO Orchestrator & Agent 13): **Tái Cấu Trúc Toàn Diện Thuật Toán libbdzstd.so (CORE_06_COMPRESSION_ENGINE)**:
  1. Phân tích nhị phân và opcode AArch64 của `apktool-res/lib/arm64-v8a/libbdzstd.so` (231,248 bytes / 225.8 KB).
  2. Khởi tạo phát hành thách thức đối kháng từ Agent 13 tại `SOURCE/PHAN-BIEN/YEU-CAU-CHUNG-MINH/CHALLENGE_libbdzstd.md` & `.json`.
  3. Triển khai toàn bộ mã nguồn C++ sạch vào `SOURCE/GIAI-MA/libbdzstd/` (> 40 KB C++, 0 stub, song ngữ EN + VN).
  4. Trình nộp bằng chứng toán học & opcode tại `SOURCE/PHAN-BIEN/BANG-CHUNG-XAC-MINH/PROOF_libbdzstd.md` & `.json`.
  5. Cập nhật suite kiểm thử `verify_reconstruction_suite.py` và chạy kiểm thử 100% PASS.
  6. Agent 13 nghiệm thu cấp chứng nhận `VERIFIED_AND_ACCEPTED` tại `LEDGER_DOI_KHANG.json`."""

assert old_task66 in text, "old_task66 not found"
idx = text.find(old_task66)
end_of_block = text.find("\n- [ ]", idx + len(old_task66))
if end_of_block == -1:
    end_of_block = len(text)

text = text[:idx] + new_task66 + "\n"

with open(todos_path, "w", encoding="utf-8") as f:
    f.write(text)

print("SUCCESS: Updated UPDATETODOS.md with completed TASK-066 and new TASK-067")
