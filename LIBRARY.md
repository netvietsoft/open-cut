# LIBRARY.md — DANH MỤC CÁC THƯ VIỆN & SDK ĐƯỢC PHÉP SỬ DỤNG

> **Tiêu chuẩn**: Chỉ sử dụng các thư viện đang duy trì tích cực, bảo mật và tương thích kiến trúc đa nền tảng. Cấm tuyệt đối các thư viện đã deprecated.

---

## 1. PHÂN HỆ ANDROID & KOTLIN MULTIPLATFORM (KMP)
- **UI Framework**:
  - `androidx.compose.ui:ui:1.7.0` (Jetpack Compose)
  - `androidx.compose.material3:material3:1.3.0`
  - `androidx.navigation:navigation-compose:2.8.0`
  - `com.facebook.yoga:yoga:1.19.0` (Yoga Flexbox Layout Engine)
- **KMP Core & Async**:
  - `org.jetbrains.kotlinx:kotlinx-coroutines-core:1.9.0`
  - `org.jetbrains.kotlinx:kotlinx-serialization-json:1.7.1`
  - `io.ktor:ktor-client-core:2.3.12` (SSE Streaming client)
  - `io.ktor:ktor-client-okhttp:2.3.12`
- **Dependency Injection**:
  - `io.insert-koin:koin-android:3.5.6`
- **Video & Đồ Họa C++**:
  - `FFmpeg 7.0-dev` (Custom shared library for media muxing/demuxing)
  - `OpenGL ES 3.0 / Vulkan API`
- **Monetization & Billing**:
  - `com.android.billingclient:billing-ktx:7.1.1` (Google Play Billing)
  - `com.google.android.gms:play-services-ads:23.3.0` (Google AdMob)

---

## 2. PHÂN HỆ BACKEND & WEB CMS (PORT 6033)
- **Core Runtime**:
  - `Node.js 20 LTS` / `TypeScript 5.5`
  - `express: ^4.19.2` (REST API & SSE Gateway)
  - `cors: ^2.8.5`
  - `dotenv: ^16.4.5`
  - `jsonwebtoken: ^9.0.2` & `bcryptjs: ^2.4.3`
- **Database & Cache**:
  - `pg: ^8.12.0` (PostgreSQL 16 Client)
  - `better-sqlite3: ^11.1.2` (Local Mock & Testing DB)
  - `ioredis: ^5.4.1` (Redis Session & Stream buffer)
- **API Documentation**:
  - `swagger-ui-express: ^5.0.1` & `swagger-jsdoc: ^6.2.8`
- **Testing**:
  - `jest: ^29.7.0` & `supertest: ^7.0.0`
  - `@playwright/test: ^1.46.0` (E2E Web CMS Testing)
