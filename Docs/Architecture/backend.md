# Docs/Architecture/backend.md — ĐẶC TẢ KIẾN TRÚC BACKEND & WEB CMS (PORT 6033)

## 1. CỔNG DỊCH VỤ & KHỞI CHẠY
- Máy chủ backend và CMS khởi chạy trên cổng **`6033`** (`http://0.0.0.0:6033`).
- Tích hợp Swagger Documentation tại `http://localhost:6033/api-docs`.
- Web Admin CMS phục vụ trực tiếp từ `http://localhost:6033/`.

## 2. CÁC PH N HỆ MICROSERVICES CỐT LÕI

### 2.1. Identity & Auth Service (`/api/v1/passport`)
- Đăng ký, đăng nhập tài khoản, xác thực Device ID.
- Quản lý phiên làm việc với JWT Token (hạn 2h) và Refresh Token (hạn 30 ngày).

### 2.2. AI Agent SSE Service (`/api/storyboard_agent/v1/ai_lab`)
- Endpoint luồng Server-Sent Events `/send_msg` tương thích ngược 100% với CapCut.
- Điều phối công cụ Model Context Protocol (MCP):
  - `cut_video`: Cắt tách video theo timestamp.
  - `auto_captions`: Sinh phụ đề tự động từ giọng nói.
  - `apply_effect`: Thêm bộ lọc, chuyển cảnh, sticker.
  - `generate_script`: Sinh kịch bản video AI.
  - `tone_clone`: Nhân bản giọng đọc AI.

### 2.3. Commerce & Paywall VIP Service (`/api/commerce/v1`)
- Danh mục gói cước: Monthly, Annual, Weekly Retain, Student Pro.
- Triển khai thuật toán giữ chân `DetainStrategy`:
  - Lần thoát 1: Kích hoạt voucher giảm giá 20%.
  - Lần thoát 2: Kích hoạt gói tuần siêu rẻ hoặc thêm ngày dùng thử.
- Webhook xác thực biên lai Google Play Developer API.

### 2.4. Template & Feed Service (`/api/feed/v2/templates`)
- Khám phá video mẫu theo thuật toán trending boost.
- Cấu hình CutSame metadata: slot media cần thay, beat sync, duration.

### 2.5. Asset & Cloudflare R2 Management (`/api/v1/assets`)
- Upload tệp lên Cloudflare R2 với Pre-signed URL.
- **Quy tắc chống file mồ côi (Orphaned File Prevention)**: Khi xóa bản ghi media trong CMS hoặc DB, hệ thống lập tức gọi lệnh xóa object tương ứng trên Cloudflare R2 / S3.
