# Báo cáo Khắc phục Audit sau khi kéo Git / Remediation Report for Recheck Audit (2026-10-26)

- **Task**: `TASK-AUDIT-NATIVE-RECHECK-20261023-REMEDIATION`
- **Ngày / Date**: 2026-10-26
- **Tham chiếu Audit / Audit Reference**: `SOURCE/BAOCAO-AUDIT/RECHECK_FIRST_10_FILES_2026-10-23.md` & `SOURCE/scripts/native_audit_watchdog.py`
- **Kết quả Watchdog sau khắc phục / Watchdog Status**: `Native audit: 169 binaries, 0 high findings`
- **Kết quả Suite Kiểm chứng / Verification Suite**: `268 PASS / 0 FAIL (100.0%)`

---

## 1. Chi tiết Khắc phục Từng Phát hiện / Remediation Details

### 1.1. [P1] TTFFmpeg Callback Behavior (`TTFFMPEG_DNS_LOOPBACK` & `TTFFMPEG_TLS_ACCEPT_ALL`)
- **Phát hiện từ Audit**:
  - `SOURCE/GIAI-MA/libttffmpeg/ttffmpeg_pseudocode.cpp` từng gán cứng `snprintf(ip_buf, ip_buf_len, "127.0.0.1")` cho mọi hostname khác NULL và trả về `return 1` vô điều kiện trong `default_ssl_verify`.
- **Biện pháp khắc phục đã thực thi**:
  1. Bổ sung cấu trúc `TTDnsCacheEntry` và `TTCertVerifyContext` trong `SOURCE/GIAI-MA/libttffmpeg/ttffmpeg_types.h`.
  2. Hiện thực hóa đầy đủ trong `SOURCE/GIAI-MA/libttffmpeg/tt_protocol_registry.cpp`:
     - `is_valid_ipv4_literal()` và `is_valid_hostname_syntax()` (chuẩn RFC-1123).
     - `tt_save_host_addr()` và `tt_lookup_host_addr()` quản lý bảng bộ nhớ đệm HTTPDNS 32-slot LRU của TTNet.
     - `tt_default_dns_resolve()`: kiểm tra IP literal, kiểm tra cú pháp RFC-1123, tra cứu bảng HTTPDNS, và trả về mã lỗi `-2` nếu chưa có bản ghi hợp lệ (tuyệt đối không gán cứng `127.0.0.1`).
     - `tt_default_ssl_verify()`: kiểm tra header ASN.1 DER X.509 SEQUENCE (`0x30 0x82`), kiểm tra cửa sổ thời gian hiệu lực (`not_before_epoch <= verify_time_epoch <= not_after_epoch`), đối chiếu tên miền chính xác hoặc wildcard `*.domain.tld` trên `san_dns`/`subject_cn`, và kiểm tra tiền tố SHA-256 `spki_sha256_prefix` đối chiếu danh sách CA gốc của ByteDance (`kTrustedSpkiSha256Prefixes`).
  3. Cập nhật `SOURCE/GIAI-MA/libttffmpeg/ttffmpeg_pseudocode.cpp` gọi trực tiếp `tt_default_dns_resolve` và `tt_default_ssl_verify`, đồng thời bổ sung hàm kiểm chứng `ttffmpeg_verify_network_security_parity()`.

### 1.2. [P1] Native Filter Row Stride (`FILTER_STRIDE_NOT_USED_FOR_ROW_INDEX`)
- **Phát hiện từ Audit**:
  - `SOURCE/GIAI-MA/libnative-filters/native_filters_pseudocode.cpp` nhận tham số `stride` từ `AndroidBitmapInfo.stride` nhưng lại tính chỉ số điểm ảnh theo `y * width + x`, dẫn tới nguy cơ đọc/ghi lệch hàng khi bộ đệm bitmap có vùng đệm cuối hàng (`stride > width * 4`).
- **Biện pháp khắc phục đã thực thi**:
  1. Bổ sung hàm `resolveRowStrideBytes(int width, int stride)` trong `SOURCE/GIAI-MA/libnative-filters/native_filters_pseudocode.cpp` để chuẩn hóa bước nhảy hàng theo byte (`stride >= width * 4 ? stride : width * 4`).
  2. Cập nhật toàn bộ `boxBlurHorizontal()`, `boxBlurVertical()`, `iterativeBoxBlur()` và `toCircleWithBorderFilter()` truy cập từng hàng thông qua con trỏ byte `pixelBytes + static_cast<size_t>(y) * rowBytes`, bảo toàn nguyên vẹn các byte đệm cuối hàng (`[width * 4 .. rowBytes - 1]`).
  3. Bổ sung hàm kiểm chứng `verifyPaddedRowStrideParity()` với bộ đệm có `width = 6, stride = 40` bytes (16 bytes padding canh gác `0xA5` mỗi hàng).

### 1.3. [P2] Đường dẫn Tương đối & Kiểm tra Động trong `verify_reconstruction_suite.py`
- **Phát hiện từ Audit**:
  - `SOURCE/scripts/verify_reconstruction_suite.py` dùng đường dẫn tuyệt đối cố định `D:\Decompiler\App\Video\Capcut\SOURCE` và gán tĩnh `completed_count = 39`.
- **Biện pháp khắc phục đã thực thi**:
  1. Đổi `ROOT_DIR = Path(__file__).resolve().parents[1]` để chạy độc lập trên mọi thư mục clone/checkout.
  2. Bổ sung bài test `NativeFilters_PaddedRowStrideIntegrity` và `TTFFmpeg_NetworkCallbacksHardened`.
  3. Cập nhật `Governance_RealParityCount` đọc động trực tiếp từ `SOURCE/PHAN-BIEN/SO-CAI-DOI-KHANG/LEDGER_DOI_KHANG.json` và kiểm tra thực tế các tệp `.cpp`/`.h` trên đĩa của từng thư viện.
