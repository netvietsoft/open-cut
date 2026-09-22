# BÁO CÁO PH N TÍCH NGƯỢC TOÀN DIỆN CAPCUT 19.4.0 (GLOBAL)

> **Mục tiêu**: Bóc tách toàn diện mã nguồn, công nghệ, API, kiến trúc, bảo mật, payment wall, tài nguyên và thiết kế blueprint hệ thống tương đương.  
> **Tệp tin APK phân tích**: `CapCut+-+Video+Editor_19.4.0_APKPure.apk` (Dung lượng: 316.1 MB)  
> **Package Name**: `com.lemon.lvoverseas` (Lemon Video / CapCut Overseas)  
> **Phiên bản**: v19.4.0 (Build 19400300) | 39 DEX files | 315,227 classes | 337 native libraries (.so) | 485 Activities

---

## 1. MỤC LỤC BÁO CÁO CHI TIẾT (REPORT INDEX)

Toàn bộ 19 yêu cầu được giải quyết đầy đủ, có cơ sở dữ liệu thực tế và xuất thành 11 báo cáo chuyên sâu trong thư mục `Report/`:

| Tập tin Báo cáo | Nội dung & Yêu cầu đáp ứng | Quy mô dữ liệu & Điểm nhấn kỹ thuật |
|---|---|---|
| [**`00_TOM_TAT_VA_CONG_NGHE.md`**](00_TOM_TAT_VA_CONG_NGHE.md) | **Tổng quan sản phẩm & Nền tảng công nghệ (Yêu cầu 1, 2)** | Bóc tách 11 Dynamic Modules (AAB), kiến trúc đa tầng (Hybrid Multi-Tier): Jetpack Compose, ByteDance Loom (Flexbox), Lynx Native, KMP Agent Core, MiddleBridge C++20 (`libmiddle-bridge.so` 60.7 MB), TTNet HTTP/3 QUIC. |
| [**`01_CAU_TRUC_MA_NGUON.md`**](01_CAU_TRUC_MA_NGUON.md) | **Cấu trúc thư mục mã nguồn & Chức năng (Yêu cầu 9)** | Sơ đồ kiến trúc 5 tầng; bảng thống kê chi tiết 20 gói mã nguồn chính (`com.vega.edit` 30k classes, `com.xt.retouch` 20k classes, `com.vega.middlebridge` 14k classes, `com.vega.ailabagent` 4.2k classes, `com.lemon.clipmonetize` 5.7k classes). |
| [**`02_MAN_HINH_MENU_FLOW.md`**](02_MAN_HINH_MENU_FLOW.md) | **Luồng màn hình, Cây Menu/Tab & Catalog (Yêu cầu 15, 16, 17)** | Sơ đồ Mermaid điều hướng toàn ứng dụng; cấu trúc cây menu cha - con 6 Tab đáy (`MainActivity`); phân loại toàn bộ 485 Activities; liên kết xuất dữ liệu XML & HTML. |
| [**`03_API_ENDPOINTS.md`**](03_API_ENDPOINTS.md) | **Danh sách 816 API Endpoints, Models & Khả năng Dùng Lại (Yêu cầu 3, 4)** | Lập bảng chi tiết 816 Retrofit Endpoints: HTTP method, path, host domain, class/method, request/response models, dữ liệu server trả về, đánh giá khả năng dùng sẵn (Nhóm A public, Nhóm B auth, Nhóm C chữ ký WAF `X-Gorgon`). |
| [**`04_DOMAINS_SDK_LIB.md`**](04_DOMAINS_SDK_LIB.md) | **Danh mục Domains, Cổng kết nối & SDK Bên Ngoài (Yêu cầu 4, 5)** | Bảng 396 domains theo nhóm chức năng (AI Agent, Editor, Commerce, Feed, Passport, CDN, APM, TNC); thống kê chi tiết toàn bộ SDK quảng cáo (AdMob, Pangle, Mintegral, Meta), hạ tầng (TTNet, AppLog, Pitaya AI), đồ họa (Loom, Lynx, Fresco, Lottie). |
| [**`05_BAO_MAT_VA_KEYS.md`**](05_BAO_MAT_VA_KEYS.md) | **Lỗ hổng bảo mật, Véc-tơ tấn công & Bảng khóa nhạy cảm (Yêu cầu 10, 12)** | Bảng 66 khóa/token phân loại 4 mức nhạy cảm (Đỏ, Cam, Vàng, Xanh): Firebase, Facebook Client Token, AMap, ColorOS Hyper Auth; phân tích 4 lỗ hổng nghiêm trọng (`DeveloperActivity` exported không bảo vệ - CWE-489, Deep Link injection - CWE-939, PIPO wallet) kèm lệnh khai thác ADB và cách vá. |
| [**`06_PAYMENT_VIP.md`**](06_PAYMENT_VIP.md) | **Payment Wall, Kịch bản gói Subscription & Ads Mediation (Yêu cầu 14)** | Phân tích màn hình Compose Subscribe; ánh xạ SKU mua hàng (Monthly, Yearly, Weekly Retain, Student Discount, Teams); 5 điểm chạm kích hoạt Paywall; thuật toán máy trạng thái giữ chân 2 cấp (`FirstDetainModal`, `SecondDetainModal`); cơ chế xem Rewarded Ads mở khóa tính năng VIP 24h. |
| [**`07_TAI_NGUYEN_SU_DUNG.md`**](07_TAI_NGUYEN_SU_DUNG.md) | **Tổng kê Tài nguyên Tái Sử Dụng Được (Yêu cầu 8)** | Khai thác 60+ bộ ngôn ngữ bản địa hóa hoàn chỉnh (`vi.json` 94 KB chuẩn thuật ngữ video editor); 49 phông chữ nghệ thuật và toán học LaTeX; 58 gói chuyển cảnh ZIP (`AI_trans_linear.zip`); mô hình AI On-device (`SegmentJS`, OFX smart crop); mẫu prompt AI kịch bản; 150+ Lottie animations. |
| [**`08_BLUEPRINT_TAI_DUNG.md`**](08_BLUEPRINT_TAI_DUNG.md) | **Blueprint Server/Backend/CMS & Kế hoạch Tái dựng 100% (Yêu cầu 11, 13)** | Đánh giá khả thi tái dựng sản phẩm tương đương; thiết kế 7 microservices tương ứng 100% với CapCut; Database Schema PostgreSQL 16 chi tiết (Users, Subscriptions, Projects, Templates, AI Conversations, Messages); đặc tả 4 phân hệ CMS quản trị (Templates, AI Prompts, Pricing A/B, Asset Store). |
| [**`09_AI_KEYS_VA_CAU_GOI.md`**](09_AI_KEYS_VA_CAU_GOI.md) | **Phân tích Chuyên sâu Khóa AI Agent & Cơ chế Gọi API (Yêu cầu 18)** | Giải mã bí ẩn API Key: Kiến trúc Zero-Client-Key của ByteDance; giao thức luồng Server-Sent Events (SSE) `/storyboard_agent/v1/ai_lab/send_msg`; headers bảo mật native (`X-Gorgon`, `X-Khronos`, `X-Argus`); kiến trúc điều phối công cụ chuẩn **Model Context Protocol (MCP)**; hướng dẫn xây dựng client tương đương. |
| [**`10_BAO_CAO_DECOMPILE_TOAN_DIEN.md`**](10_BAO_CAO_DECOMPILE_TOAN_DIEN.md) | **Báo cáo Dịch ngược Toàn diện & Kiểm tra Bảo vệ VMP (Yêu cầu 1)** | Tổng kết quy trình giải mã 38 DEX bằng In-Memory Parser (1.69s); phân tích các lớp phòng vệ nội bộ (FaceU AntiRepacker, DexVMP Bytecode Virtualization, SecSDK, Frida detection); thống kê 337 thư viện `.so` Native; chứng thực tính toàn vẹn 100% của dữ liệu. |

---

## 2. DỮ LIỆU BÓC TÁCH THÔ (REPORT/DATA/ DIRECTORY)

Tất cả các tập tin dữ liệu cấu trúc phục vụ việc tích hợp vào hệ thống mới hoặc kiểm chứng độc lập:

- **`Report/data/screens_structure.xml`**: Cấu trúc cây XML của toàn bộ màn hình, bottom tabs, categories và deep links (đáp ứng Yêu cầu 17).
- **`Report/data/screens_structure.html`**: Báo cáo trực quan HTML hiện đại hiển thị toàn bộ 485 màn hình, phân loại màu sắc và huy hiệu bảo mật.
- **`Report/data/endpoints.full.tsv`**: Bảng dữ liệu TSV của 816 API Endpoints (Index, HTTP Verb, Path, Interface Class, Method, Return Type, DEX File).
- **`Report/data/retrofit_all_endpoints.json`**: Tập tin JSON có cấu trúc đầy đủ của 816 endpoints.
- **`Report/data/activities_inventory.json`**: Danh mục 485 Activities với trạng thái `exported`, `launch_mode`, `theme`, và danh sách intent-filters.
- **`Report/data/components.tsv`**: Bảng tổng hợp component AndroidManifest.
- **`Report/data/all_discovered_keys.json`**: Toàn bộ khóa nhạy cảm, API keys, tokens và IDs phát hiện trong ứng dụng.
- **`Report/data/extracted_domains.txt`**: Danh sách 396 domains máy chủ ngoại vi.
- **`Report/data/extracted_endpoints.txt`**: Danh sách các URI endpoints phát hiện trong string pool.
- **`Report/data/extracted_ai_strings.txt`**: 8,204 chuỗi ký tự liên quan đến AI Lab, Agent, LLM và Prompts.
- **`Report/data/extracted_keys.txt`**: Các chuỗi liên quan đến bảo mật và khóa truy cập.
