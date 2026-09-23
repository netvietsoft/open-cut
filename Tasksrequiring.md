# Tasksrequiring.md — DANH MỤC CÁC THÔNG SỐ & KHÓA BẢO MẬT CẦN NGƯỜI DÙNG BỔ SUNG

> **Mục tiêu**: Thống kê toàn bộ các cấu hình, khóa API (Key), định danh bên thứ ba (SDK Keys) cần thiết lập để hệ thống NextAI OpenCut vận hành thương mại 100%.  
> **Trạng thái hiện tại**: Hệ thống đã được điền sẵn giá trị **Demo / Mock / Placeholder an toàn** để sẵn sàng chạy và kiểm thử ngay lập tức. Người dùng có thể thay thế bằng khóa thật khi phát hành chính thức.

---

## BẢNG THỐNG KÊ CÁC KHÓA & TÀI NGUYÊN CẦN THIẾT

| STT | Tên Tài Nguyên / Khóa Cần Bổ Sung | Phân Hệ Sử Dụng | Mức Độ Nhạy Cảm | Giá Trị Demo Đang Sử Dụng | Hướng Dẫn & Nơi Lấy Khóa Thật |
|---|---|---|---|---|---|
| **1** | **Google Cloud / Firebase Server Key** | Push Notification & Firebase Auth | 🔴 Cao (Secret) | `mock_firebase_key_nextai_dev_2026` | Lấy từ [Firebase Console](https://console.firebase.google.com/) -> Project Settings -> Cloud Messaging |
| **2** | **Google AdMob App ID & Unit IDs** | Quảng cáo Banner / Interstitial / Rewarded | 🟡 Trung bình | `ca-app-pub-3940256099942544~3347511713` (Google Test ID) | Lấy từ [Google AdMob Console](https://admob.google.com/) |
| **3** | **Google Play Console License Key** | Xác thực mua gói VIP Pro & In-App Purchase | 🔴 Cao | `MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA_mock_license` | Lấy từ [Google Play Console](https://play.google.com/console) -> Monetization setup -> Licensing |
| **4** | **Cloudflare R2 / AWS S3 Credentials** | Lưu trữ Video, Mẫu, Âm thanh, Tệp tải lên | 🔴 Cao (Secret) | AccountID: `mock_cf_acc`, AccessKey: `mock_r2_key`, Secret: `mock_r2_secret` | Lấy từ [Cloudflare Dashboard](https://dash.cloudflare.com/) -> R2 -> Manage R2 API Tokens |
| **5** | **AI LLM API Key (DeepSeek / OpenAI / Qwen)** | Nhân suy luận AI Copilot & Script to Video | 🔴 Cao (Secret) | `sk-nextai-mock-ai-copilot-dev-key-2026` | Lấy từ [DeepSeek Platform](https://platform.deepseek.com/) hoặc OpenAI Dashboard |
| **6** | **Whisper / ASR Cloud Endpoint** | Tự động tạo phụ đề (Speech-to-Text) | 🟡 Trung bình | `http://localhost:6033/api/v1/mock/asr` | Tự host bằng `whisper.cpp` hoặc gọi Cloud Speech-to-Text API |
| **7** | **TikTok Open Platform Client Key & Secret** | Đăng nhập bằng TikTok & Xuất bản trực tiếp | 🟠 Khá cao | Client Key: `mock_tiktok_client_key`, Secret: `mock_tiktok_secret` | Lấy từ [TikTok for Developers](https://developers.tiktok.com/) |
| **8** | **Pangle / Mintegral / Meta Audience Network IDs** | Mediation Quảng cáo mạng phụ | 🟡 Trung bình | `mock_pangle_slot_id_88888` | Lấy từ dashboard Pangle, Mintegral, Meta for Developers |
| **9** | **SSL / TLS Domain Certificate** | Bảo mật HTTPS / WSS cổng 6033 | 🔴 Cao | Tự sinh chứng chỉ Self-signed (`localhost.pem`) | Cài đặt chứng chỉ Let's Encrypt qua Certbot khi lên máy chủ Production |
| **10** | **Stripe / Payment Gateway Secret Key** | Cổng thanh toán phụ cho Web CMS | 🔴 Cao | `sk_test_51MockStripeKeyNextAi2026` | Lấy từ [Stripe Dashboard](https://dashboard.stripe.com/test/apikeys) |
| **11** | **Cloud Neural TTS API Key (Azure / ElevenLabs)** | Giọng đọc AI đa ngôn ngữ (Hà Nhi, Minh Quân) | 🟡 Trung bình | Thiết bị sử dụng Android TTS tích hợp sẵn | Đăng ký tài khoản Azure Speech hoặc ElevenLabs API |
| **12** | **AmazingFeature / ByteDance Effect License Key** | Chứng thực bản quyền các gói hiệu ứng động | 🔴 Cao | Nạp trực tiếp từ `assets/capcut/` cục bộ | Đăng ký ByteDance Effect Platform khi thương mại hóa |
| **13** | **Google Play Android Publisher Service Account JSON** | Xác thực Server-Side Purchase Token cho Billing 8.2.1 (Backend cổng 6033) | 🔴 Cao (Secret) | `Backend/config/mock_play_service_account.json` | Lấy từ [Google Cloud Console](https://console.cloud.google.com/) -> IAM & Admin -> Service Accounts -> Tạo Key JSON có quyền trên Google Play Console |

---

## 2. HƯỚNG DẪN CẤP PHÁT CHO SPRINT TIẾP THEO (TASK-048 BILLING HARDENING)
Để hoàn tất thương mại hóa theo kiến nghị từ báo cáo rà soát R2:
1. **Google Play Console**: Thiết lập 3 SKU In-App / Subscription:
   - `opencut_pro_yearly` (Gói Năm: 899.000 đ / voucher 20%: 719.000 đ)
   - `opencut_pro_monthly` (Gói Tháng: 99.000 đ)
   - `opencut_pro_lifetime` (Gói Trọn Đời: 1.490.000 đ)
2. **Service Account JSON**: Cung cấp tệp `service_account.json` để Backend `6033` thực hiện gọi `androidpublisher.purchases.subscriptionsv2.get` xác thực biên lai thanh toán an toàn, bảo vệ doanh thu cho Chủ tịch.

