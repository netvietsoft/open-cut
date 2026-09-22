# NextAI OpenCut — Siêu Nền Tảng Biên Tập Video & AI Copilot

> **Thương hiệu**: NextAI / NextAITechnology  
> **Package Name**: `com.nextai.opencut`  
> **Phiên bản**: v2.1.0-reconstruction  
> **Tiêu chuẩn quản trị**: `Development Workspace Standard V2.1 (Design-Gated Reconstruction Edition)`

---

## 1. TỔNG QUAN DỰ ÁN

NextAI OpenCut là sản phẩm tái dựng và hiện đại hóa toàn diện siêu ứng dụng biên tập video đa nền tảng dựa trên phân tích chuyên sâu CapCut 19.4.0. Ứng dụng kết hợp giữa công nghệ biên tập đồ họa C++ Native đa luồng, giao diện phản ứng Jetpack Compose Multiplatform, lõi AI Agent theo giao thức **Model Context Protocol (MCP)**, và hệ thống máy chủ vi dịch vụ (Microservices) thời gian thực chạy trên cổng **6033**.

### Điểm nhấn công nghệ:
- **Tầng Giao diện Đa nền tảng**: Jetpack Compose Multiplatform + Yoga Flexbox + Lynx Dynamic Card View.
- **Tầng Nghiệp vụ AI**: Kotlin Multiplatform (KMP) chia sẻ 100% logic AI Agent giữa Android, iOS, Web và Desktop.
- **Tầng C++ Native Video Engine**: MiddleBridge C++20 + FFmpeg 7.0 + Audio DSP đa kênh.
- **Tầng Backend & CMS**: Node.js/TypeScript + Golang Worker + PostgreSQL 16 + Redis Cache + SSE Streaming Server tại cổng **`6033`**.
- **Tầng Quản trị CMS**: Web Admin Dashboard pro hỗ trợ Dark/Light mode, quản lý người dùng, thiết bị, mẫu video, và A/B testing giá Paywall.

---

## 2. CẤU TRÚC DỰ ÁN

- **`AGENTS.md`**: Hiến pháp tối cao dành cho AI Agent.
- **`Docs/`**: Kho tri thức chuẩn: Kiến trúc, ADRs, Contracts, Specs, Runbooks, Security, Testing, Design System.
- **`.ai/`**: Trạng thái máy học, Task Graph, Schemas, Handoffs, Ledger.
- **`Backend/`**: Máy chủ API Gateway, AI SSE Stream, và Web Admin CMS (Chạy cổng **6033**).
- **`apps/android/`**: Ứng dụng Android Kotlin (`com.nextai.opencut`) tích hợp KMP, Compose và C++ Engine.
- **`packages/`**: Thư viện dùng chung contracts, domain, shared utilities.
- **`design/`**: Nguyên mẫu thiết kế và tài sản UI/UX đã duyệt.
- **`tests/`**: Bộ kiểm thử Unit, Integration, Parity và Playwright E2E.
- **`Report/`**: Dữ liệu phân tích ngược toàn diện và báo cáo kỹ thuật.

---

## 3. HƯỚNG DẪN KHỞI CHẠY HỆ THỐNG

### 3.1. Khởi động Backend & Web CMS (Port 6033)
```bash
cd Backend
npm install
npm run build
npm start
```
- **Web Admin CMS**: Truy cập `http://localhost:6033/`
- **Swagger API Docs**: Truy cập `http://localhost:6033/api-docs`
- **AI SSE Endpoint**: `http://localhost:6033/api/storyboard_agent/v1/ai_lab/send_msg`

### 3.2. Chạy Kiểm Thử Tự Động Playwright UI Web CMS
```bash
npx playwright test tests/playwright/admin_cms.spec.ts
```

### 3.3. Xây Dựng Ứng Dụng Android & Đóng Gói Tài Nguyên Gốc CapCut
```powershell
# Biên dịch APK, đóng gói 213 tài nguyên gốc CapCut (shaders, effects, lottie, audio) và ký số
powershell -ExecutionPolicy Bypass -File apps/android/app/build_apk.ps1

# Cài đặt trực tiếp lên thiết bị Android (Emulator hoặc Thiết bị thật qua ADB)
adb install -r apps/android/app/build/manual_build/nextai_opencut_signed.apk
```

---

## 4. BẢN ĐỒ MILESTONE ĐÃ HOÀN TẤT
- ✅ **Hệ Thống Lõi & CMS Port 6033**: Backend Node.js/TypeScript + Golang Worker + Web Admin CMS.
- ✅ **Giao Diện Android 95% CapCut**: Trang chủ Home Hub, Hero Project, Media Picker chuẩn SAF, Video Timeline Editor đa track.
- ✅ **Bộ Công Cụ Sửa Ảnh & 3D LUTs**: Tỷ lệ canvas động, chuyển đổi màu điện ảnh Portra 400/Cyberpunk, lưu ảnh an toàn vào MediaStore.
- ✅ **Hoàn Thiện Triệt Để Submenus (TASK-018)**: Khóa phông Chroma Key, Phụ đề AI, Giọng đọc AI TTS, Text to Video Storyboard, Mẫu Hot CutSame, Thu mặt thon gọn & Làm đẹp Face Mesh 468 điểm.
- ✅ **Tích Hợp Kho Tài Nguyên Gốc CapCut (TASK-019)**: 213 tệp tài nguyên thực tế (ByteDance GLSL Shaders, AmazingFeature FaceReshape V2, Lottie animations, Bản quyền nhạc gốc).

---

## 5. LIÊN KẾT TÀI LIỆU CHUẨN
- [Hiến Pháp AI Agent](file:///d:/Decompiler/App/Video/Capcut/AGENTS.md)
- [Báo Cáo Nghiệm Thu Tài Nguyên Gốc CapCut](file:///d:/Decompiler/App/Video/Capcut/.ai/reports/walkthrough.md)
- [Báo Cáo Nghiệm Thu Deep Parity Submenus](file:///d:/Decompiler/App/Video/Capcut/.ai/reports/deep_parity_report.md)
- [Bàn Giao Phiên Làm Việc Mới Nhất](file:///d:/Decompiler/App/Video/Capcut/.ai/handoffs/HANDOFF-TASK-019.md)
- [Nhật Ký Thay Đổi (Changelog)](file:///d:/Decompiler/App/Video/Capcut/Docs/Changelog/CHANGELOG.md)
- [Quyết Định Kiến Trúc (ADR-004)](file:///d:/Decompiler/App/Video/Capcut/Docs/ADR/ADR-004-AUTHENTIC-CAPCUT-ASSETS-AND-FORWARD-SLASH-PACKAGING.md)
- [Quy Tắc Lập Trình Dự Án](file:///d:/Decompiler/App/Video/Capcut/Docs/rules.md)
- [Sơ Đồ Cấu Trúc Thư Mục](file:///d:/Decompiler/App/Video/Capcut/Docs/CAU_TRUC_THU_MUC.md)
- [Bản Thiết Kế Hệ Thống Backend & CMS](file:///d:/Decompiler/App/Video/Capcut/Docs/Architecture/backend.md)
- [Tài Liệu Design System](file:///d:/Decompiler/App/Video/Capcut/Docs/Design/DESIGN_SYSTEM.md)
- [Kế Hoạch & Việc Cần Người Dùng Bổ Sung](file:///d:/Decompiler/App/Video/Capcut/Tasksrequiring.md)

