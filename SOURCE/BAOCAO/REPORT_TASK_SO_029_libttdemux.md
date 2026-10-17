# BÁO CÁO NHIỆM VỤ TÁI DỰNG: libttdemux.so
> **Task ID**: `TASK_SO_029_libttdemux`  
> **Trạng thái**: `COMPLETED (100%)`  
> **Kiểm định đối kháng**: `VERIFIED_AND_ACCEPTED` (Agent 13 phê duyệt)  
> **Thời điểm nghiệm thu**: `2026-10-17 10:55:00`  
> **Mã nguồn tái dựng**: `SOURCE/GIAI-MA/libttdemux/` (108,594 bytes / 106.05 KB C++, 13 files, 0 stub)

---

### 1. TỔNG QUAN THƯ VIỆN & PHÂN HỆ
- **Tên thư viện gốc**: `libttdemux.so` (`51,096 bytes`, ARM64-v8a).
- **Phân hệ**: TTPlayer Demuxer & Predemuxing Core Engine (ByteDance / CapCut).
- **Mục đích**: Wrapper cấp cao điều phối giải mã container đa phương tiện, tích hợp vùng đệm nạp trước (predemux), xử lý kết nối giao thức tùy biến (`mdl://` — Mobile Download), liên kết với FFmpeg `AVFormatContext` và `AVIOContext`.

---

### 2. KẾT QUẢ TÁI DỰNG CHI TIẾT
1. **Kiến trúc hướng đối tượng C++17 Cleanroom**:
   - `com::ss::vcbkit`: `BaseRef`, `RefPtr<T>`, `Mutex`, `ScopedLock`, `CondVar`.
   - `com::ss::ttm::demuxer`: `DemuxConfig`, `DemuxMetrics`, `DemuxLogInfo`, `DemuxContextHolder`.
   - Giao thức: `AVSourceProtocol`, `AVSourceProtocolFF`, `AVSourceProtocolProb`, `AVSourceProtocolLisenter`.
   - Vùng đệm đa luồng: `AVSourceInput` (17.7 KB C++ logic).
   - Vỏ bọc ngữ cảnh: `FormatHolder` và bộ tiện ích `SourceInputHelper`.
   - Giám sát cache nạp trước: `AVPredemuxMonitor`.
   - Bộ nguồn media cấp cao: `AVMediaSource` và `AVMediaSourceHelper`.
   - Master Engine: `NextAI::OpenCut::ttdemux::TtdemuxEngine` kèm bộ tự kiểm thử 7 giai đoạn `runSelfTest()`.

2. **Các phát hiện nhị phân & opcode AArch64 cốt lõi**:
   - `SourceInputHelper::openIoContext` (0x78e0): Cấp phát `TTIOContext` 272 bytes (`0x110`) và buffer 32KB (`0x8000`), đặt cờ `is_streamed = 1` tại offset `+0x90` (0x795c).
   - `SourceInputHelper::supportSourceInput` (0x7a04): Nhận diện lược đồ `"mdl://"` từ địa chỉ `.rodata` `0x8cbc`.
   - `SourceInputHelper::parseAndUpdateConnectionInfo` (0x7ac4): Đóng gói bitfield `(action << 16) | metric_id` qua lệnh `bfi w1, w20, #0x10, #0x10`.
   - `AVSourceInput::seek` (0x6ef8): Xử lý phân nhánh `0x7000`, `0x7001`, `0x10000` (`AVSEEK_SIZE`) và các chuẩn `SEEK_SET`, `SEEK_CUR`, `SEEK_END`.
   - `AVSourceInput::read` (0x71f0): Xử lý kẹp biên dòng dữ liệu và so khớp hằng số sentinel EOF `0xdfb9b0bb`.

---

### 3. CHỈ SỐ NGHIỆM THU ĐỐI KHÁNG
- **Dung lượng C++**: 108,594 bytes (Chuẩn $\ge 40\text{ KB}$ -> Đạt).
- **Tỷ lệ stub**: 0.0% (Zero stub).
- **Opcode đối soát**: 26 địa chỉ AArch64 chính xác.
- **Suite kiểm thử khép kín**: 151 / 151 test PASS (100.0%).
- **Sổ cái đối kháng**: Đã cập nhật `VERIFIED_AND_ACCEPTED` tại `SOURCE/PHAN-BIEN/SO-CAI-DOI-KHANG/LEDGER_DOI_KHANG.json`.
