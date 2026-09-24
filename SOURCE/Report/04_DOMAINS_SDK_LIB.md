# BÁO CÁO 04: DANH MỤC DOMAINS, IP/CỔNG VÀ THƯ VIỆN/SDK BÊN NGOÀI

> **Mục tiêu đáp ứng**: Yêu cầu 4 (Lập bảng Client gọi những domain/IP, cổng nào ở bên ngoài) & Yêu cầu 5 (List các SDK, Library bên ngoài được sử dụng, chức năng nhiệm vụ).  
> **Tổng số Domain bóc tách**: 396 domains độc lập.  
> **Giao thức truyền dẫn**: HTTPS (Cổng 443), QUIC/UDP (Cổng 443), WSS WebSocket (Cổng 443).

---

## 1. BẢNG DANH MỤC DOMAINS, CỔNG VÀ MỤC ĐÍCH KẾT NỐI NGOẠI VI

| Nhóm chức năng | Tên Miền (Domain Hostname) | Giao thức & Cổng | Mục đích kết nối & Dữ liệu trao đổi |
|---|---|---|---|
| **AI Video & Agent Backend** | `aivideo-normal.capcutapi.com` | HTTPS / QUIC : 443 | Máy chủ AI Agent trung tâm: nhận prompt người dùng, streaming phản hồi SSE, điều phối công cụ MCP, sinh video AI tự động. |
| **API Biên tập & Dự án** | `editor-api.capcutapi.com`<br>`editor-api-va.capcutapi.com` | HTTPS / QUIC : 443 | Máy chủ API biên tập video: đồng bộ cấu trúc project timeline, nhận diện giọng nói (ASR v2t), cấu hình xuất bản. |
| **Thương mại & Gói Pro** | `commerce-api.capcutapi.com` | HTTPS : 443 | Máy chủ thanh toán: xác thực gói CapCut Pro, quản lý chiến lược giữ chân (`DetainStrategy`), kích hoạt voucher giảm giá. |
| **Mẫu Video & Mạng Xã Hội** | `feed-api.capcutapi.com`<br>`feed-api-sg.capcut.com` | HTTPS / QUIC : 443 | Cung cấp nguồn cấp dữ liệu video mẫu (Template Feed), dữ liệu tác giả, tương tác cộng đồng (like/comment/share). |
| **Đăng nhập & Định danh** | `passport-api.capcutapi.com`<br>`passport-api.capcut.com` | HTTPS : 443 | Xác thực tài khoản người dùng: đăng nhập TikTok OAuth, Google Sign-In, quản lý token phiên làm việc (`sessionid`). |
| **Lưu trữ Đám mây** | `cloudspace-normal.capcutapi.com` | HTTPS : 443 | Quản lý không gian đám mây CapCut Cloud Space, sao lưu bản nháp dự án, phân quyền cộng tác nhóm. |
| **Phân phối Tài nguyên (Gecko)**| `gecko-sg.capcutapi.com`<br>`tt-gecko-sg.capcutapi.com` | HTTPS : 443 | ByteDance Gecko Engine: Tải các gói cập nhật giao diện động, mẫu thiết kế Lynx, bộ lọc và hiệu ứng mới mà không cần cập nhật APK. |
| **Điều khiển Lưu lượng (TNC)** | `tnc-sg.capcutapi.com`<br>`tnc-v2-boot.capcutapi.com` | HTTPS : 443 | ByteDance Traffic Network Control: Phân tích đường truyền ISP, tự động định tuyến sang IP server có độ trễ thấp nhất. |
| **Giám sát Hiệu năng (APM)** | `mon-v2-boot.capcutapi.com`<br>`mon.byteoversea.com` | HTTPS : 443 | ByteDance Slardar APM: Thu thập dữ liệu crash, ANR, mức tiêu hao RAM, FPS render và độ trễ mạng của người dùng. |
| **Mạng Phân Phối CDN Đồ Họa** | `sf16-effect-capcut.byteeffecttos-g.com`<br>`p16-capcut-va.ibyteimg.com` | HTTPS : 443 | CDN phân phối tài nguyên nặng: Bộ lọc màu (LUTs), nhãn dán động, âm thanh hiệu ứng, mô hình AI on-device. |
| **Mạng Phân Phối CDN Đám Mây** | `sf16-draftcdn-sg.ibytedtos.com`<br>`sf19-draftcdn-sg.ibytedtos.com` | HTTPS : 443 | CDN lưu trữ các bản nháp video của người dùng đã tải lên mây (TOS Storage). |
| **Pitaya On-Device AI** | `pitaya.tiktokv.com`<br>`pitaya-task.tiktokv.com` | HTTPS : 443 | Tải các mô hình Machine Learning nhẹ xuống điện thoại để chạy suy luận cục bộ (On-Device AI segmentation, Face detect). |
| **Google Play Billing** | `play.googleapis.com` | HTTPS : 443 | Kết nối Google Play Store để xác thực giao dịch in-app purchase cho các gói VIP tháng/năm. |
| **Quảng cáo Google AdMob** | `googleads.g.doubleclick.net`<br>`pagead2.googlesyndication.com` | HTTPS : 443 | Tải quảng cáo banner, quảng cáo xen kẽ (interstitial) và quảng cáo thưởng (rewarded video). |
| **Quảng cáo Pangle (ByteDance)**| `api16-access-ttp.tiktokpangle.us` | HTTPS : 443 | Nền tảng quảng cáo di động Pangle Ad SDK của ByteDance để phân phối quảng cáo và kiếm tiền. |
| **Quảng cáo Mintegral** | `net.rayjump.com` | HTTPS : 443 | Nền tảng quảng cáo Mintegral / MBridge Ad SDK cho video có thưởng mở khóa tính năng Pro. |

---

## 2. DANH SÁCH SDK VÀ THƯ VIỆN BÊN NGOÀI ĐƯỢC TÍCH HỢP

### 2.1. Nhóm SDK Quảng Cáo & Kiếm Tiền (Monetization & Ad Mediation)
1. **Google Play Billing Library v8.2.1** (`com.android.billingclient.api`):
   - *Nhiệm vụ*: Quản lý toàn bộ giao dịch thanh toán trong ứng dụng, đăng ký gói gia hạn định kỳ (Auto-renewing subscriptions), xử lý hoàn tiền và khôi phục đơn hàng (`restorePurchases`).
2. **Google AdMob SDK** (`com.google.android.gms.ads` - App ID `ca-app-pub-8563181921274308~3003233985`):
   - *Nhiệm vụ*: Hiển thị quảng cáo biểu ngữ, quảng cáo toàn màn hình khi xuất video đối với tài khoản miễn phí.
3. **ByteDance Pangle Ad SDK v7.1.6.4** (`com.bytedance.sdk.pangle`):
   - *Nhiệm vụ*: Mạng lưới quảng cáo độc quyền của ByteDance tối ưu hóa eCPM cho các khu vực quốc tế.
4. **Mintegral Ad SDK (MBridge)** (`com.mbridge.msdk` - 3,037 classes):
   - *Nhiệm vụ*: Cung cấp quảng cáo video có thưởng (Rewarded Ads) để mở khóa các tính năng Pro tạm thời trong 24 giờ.
5. **Meta Audience Network (Facebook Ads)** (`assets/audience_network.dex` - ~3.5 MB):
   - *Nhiệm vụ*: Mạng lưới quảng cáo của Facebook, được tách riêng thành tập tin DEX độc lập trong thư mục `assets/` để tải động khi cần.

### 2.2. Nhóm SDK Mạng, Hạ Tầng & Dữ Liệu Lớn (Networking & Big Data)
1. **ByteDance TTNet / Chromium Cronet Fork** (`com.bytedance.ttnet`, `com.bytedance.frameworks.baselib.network`):
   - *Nhiệm vụ*: Nhân truyền tải mạng thế hệ mới, hỗ trợ song song HTTP/2 và HTTP/3 (QUIC), giảm độ trễ kết nối TCP handshake, cơ chế DNS fallback thông minh.
2. **ByteDance AppLog** (`com.ss.android.common.applog`):
   - *Nhiệm vụ*: Nền tảng theo dõi hành vi người dùng (User Event Tracking), ghi nhận mọi cú chạm, thời lượng chỉnh sửa, tính năng được ưa chuộng.
3. **ByteDance Slardar / APM Insight** (`com.bytedance.apm`):
   - *Nhiệm vụ*: Giám sát độ ổn định ứng dụng, tự động chụp crash stack-trace, đo lường thời gian khởi động (Cold Start / Warm Start), cảnh báo rò rỉ bộ nhớ.
4. **ByteDance Keva** (`com.bytedance.keva`):
   - *Nhiệm vụ*: Hệ thống lưu trữ Key-Value siêu tốc viết bằng C++ thay thế hoàn toàn `SharedPreferences` chậm chạp của Android, tránh hiện tượng giật lag UI khi lưu cache.

### 2.3. Nhóm SDK Đồ Họa, Giao Diện & m Thanh (UI, Multimedia & AI)
1. **Jetpack Compose Multiplatform** (`androidx.compose.ui`, `androidx.compose.foundation` - 4,400+ classes):
   - *Nhiệm vụ*: Framework xây dựng giao diện khai báo hiện đại cho các phân hệ mới (màn hình Paywall VIP, giao diện chọn hiệu ứng AI).
2. **ByteDance Loom Layout Engine** (`com.vega.loom`):
   - *Nhiệm vụ*: Engine layout động dựa trên Facebook Yoga Flexbox C++, cho phép render các thẻ giao diện động (dynamic cards) nhận từ server JSON.
3. **ByteDance Lynx Framework** (`com.vega.lynx`):
   - *Nhiệm vụ*: Khung hiển thị đa nền tảng tương đương React Native nhưng render trực tiếp bằng engine C++, dùng cho Template Feed.
4. **ByteDance Pitaya Core** (`com.bytedance.pitaya`, `libAndroidPitayaCore.so`):
   - *Nhiệm vụ*: Runtime AI/ML trên thiết bị, triển khai các mô hình phân loại thông minh, nhận diện khuôn mặt, gợi ý hiệu ứng phù hợp theo thời gian thực.
5. **Koin Dependency Injection** (`org.koin`, `com.vega.core.koin`):
   - *Nhiệm vụ*: Framework tiêm phụ thuộc (DI) dạng Service Locator siêu nhẹ cho Kotlin, quản lý vòng đời của hơn 350 dịch vụ (services) trong app.
6. **Facebook Fresco** (`com.facebook.drawee`, `com.facebook.imagepipeline`):
   - *Nhiệm vụ*: Quản lý tải và giải nén hình ảnh trong bộ nhớ ngoài heap (Ashmem / Native C++ Bitmap memory), chống tràn RAM (OOM) khi cuộn danh sách hàng ngàn video mẫu.
7. **Airbnb Lottie** (`com.airbnb.lottie`):
   - *Nhiệm vụ*: Render các hiệu ứng vector hoạt họa sống động (loading anim, icon tương tác) từ các tập tin JSON gọn nhẹ.

### 2.4. Nhóm SDK Đăng Nhập & Bảo Mật (Auth & Security)
1. **Google Play Services & Firebase Auth** (`com.google.android.gms.auth`, `com.google.firebase`):
   - *Nhiệm vụ*: Đăng nhập một chạm bằng tài khoản Google, Firebase Cloud Messaging (FCM) để nhận thông báo đẩy khi video xuất xong.
2. **Facebook Login SDK** (`com.facebook.login` - App ID `163543514909045`):
   - *Nhiệm vụ*: Đăng nhập và liên kết tài khoản Facebook, hỗ trợ tính năng chia sẻ tác phẩm trực tiếp lên Story/Reels.
3. **AutoNavi / AMap SDK** (`com.amap.api` - API Key `c2f1e56b87f257275fbf44a1fc067e0b`):
   - *Nhiệm vụ*: Định vị địa lý và gắn thẻ vị trí địa lý vào các video vlog du lịch.
4. **ByteDance SecSDK** (`com.bytedance.security`):
   - *Nhiệm vụ*: Tầng phòng thủ bảo mật client: kiểm tra môi trường Root/Jailbreak, phát hiện máy ảo (Emulator), chống can thiệp debugger (Anti-Debug) và tạo token bảo vệ `X-Argus`.
