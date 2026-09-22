# Docs/rules.md — QUY TẮC LẬP TRÌNH & TIÊU CHUẨN KỸ THUẬT CANONICAL

> **Phạm vi**: Toàn bộ dự án NextAI OpenCut (Android, Backend, Web CMS, Native Engine)

---

## 1. CÔNG NGHỆ & PHIÊN BẢN (FRAMEWORKS & VERSIONS)
- **Backend API & Web CMS**: Node.js 20 LTS, TypeScript 5.5, Express 4.19, Golang 1.22 Worker (Port **6033**).
- **Mobile Android**: Kotlin 2.0, Java 17, Jetpack Compose 1.7, Kotlin Multiplatform (KMP) 2.0, Yoga Flexbox 1.19.
- **Native Video Engine**: C++20, FFmpeg 7.0 shared library, OpenGL ES 3.0 / Vulkan.
- **Database**: PostgreSQL 16 (Production) / SQLite 3 (Local testing & mock), Redis 7.

---

## 2. QUY ƯỚC ĐẶT TÊN & MÃ NGUỒN (NAMING & CODING STYLE)
1. **Biến & Hàm**: `camelCase` (VD: `fetchTemplateDetail`, `calculateDetainDiscount`).
2. **Class, Interface, Component**: `PascalCase` (VD: `ComposeSubscribeActivity`, `McpToolDispatcher`).
3. **Hằng số**: `UPPER_SNAKE_CASE` (VD: `MAX_STREAM_TIMEOUT_MS`, `DEFAULT_PORT`).
4. **Package Name**: `com.nextai.opencut` (Cấm sử dụng tên cũ `com.lemon.lvoverseas` hoặc `com.vega.*`).
5. **Thương hiệu**: `NextAI / NextAITechnology`.
6. **BẮT BUỘC CHÚ THÍCH SONG NGỮ (DUAL COMMENTS)**: Mọi hàm, phương thức, cấu trúc logic bắt buộc có docstring và comment bằng cả **Tiếng Việt + Tiếng Anh**.

---

## 3. QUY TẮC BẢO MẬT & VÁ LỖ HỔNG TỪ BẢN GỐC
- **Khắc phục CWE-489 (Exported Component)**: Toàn bộ Activity/Service/Receiver nội bộ bắt buộc đặt `android:exported="false"`. `DeveloperActivity` phải được gỡ bỏ hoàn toàn hoặc đóng bảo vệ bằng signature permission.
- **Khắc phục CWE-939 (Deep Link Injection)**: Các Intent Filter nhận deep link `opencut://` phải kiểm tra schema và validate whitelist domain/path trước khi dispatch.
- **Cấm lưu cứng Secret**: Toàn bộ API Key, Token, Client Secret phải được đọc từ biến môi trường qua `.env` hoặc hệ thống quản lý cấu hình tập trung.

---

## 4. QUY TẮC CƠ SỞ DỮ LIỆU & API
- Không bao giờ chạy lệnh `DROP TABLE` hoặc `TRUNCATE` tùy tiện. Mọi thay đổi schema phải có file migration tương ứng.
- Toàn bộ 816 API Endpoints tuân thủ định dạng phản hồi chuẩn `BaseResponse<T>` (`code`, `message`, `data`, `extra`).
- Endpoint SSE Stream `/storyboard_agent/v1/ai_lab/send_msg` phải hỗ trợ cơ chế heartbeat và timeout recovery.
