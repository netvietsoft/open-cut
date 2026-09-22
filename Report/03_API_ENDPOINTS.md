# BÁO CÁO 03: DANH SÁCH API ENDPOINTS, MODELS VÀ KHẢ NĂNG TÁI SỬ DỤNG

> **Mục tiêu đáp ứng**: Yêu cầu 3 (Danh sách API: chức năng, nhiệm vụ từng endpoint, dùng sẵn luôn được không, endpoint list, model list chi tiết, bảng biểu) & Yêu cầu 4 (Dữ liệu gọi được trên server, bảng kết quả, domain/IP/port).  
> **Tổng số API Endpoints bóc tách từ DEX**: 816 Retrofit Endpoints chính thức.  
> **Tập tin dữ liệu đính kèm**: `Report/data/endpoints.full.tsv` (816 dòng) & `Report/data/retrofit_all_endpoints.json`.

---

## 1. ĐÁNH GIÁ TỔNG QUAN VỀ KHẢ NĂNG SỬ DỤNG SẴN CỦA API (REUSABILITY ASSESSMENT)

Các API của CapCut được chia làm 3 nhóm mức độ sẵn sàng khi gọi từ bên ngoài:

1. **Nhóm A: Dùng sẵn trực tiếp (Public / Static CDN - ~15% API)**:
   - Các API lấy danh mục phông chữ công khai, danh sách nhãn dán thịnh hành, video mẫu public trên Feed.
   - Yêu cầu: Chỉ cần header `User-Agent` hợp lệ và `device_platform=android`.
   - Đánh giá: **Có thể dùng ngay lập tức** trong sản phẩm mới để lấy tài nguyên (templates, stickers, effects).

2. **Nhóm B: Cần Token Tài Khoản & SessionID (Authenticated API - ~45% API)**:
   - Các API quản lý dự án đám mây, thông tin cá nhân, lịch sử đơn hàng, hạn mức tín dụng AI.
   - Yêu cầu: Header `sessionid` từ Cookie hoặc `X-Tt-Token` sau khi đăng nhập qua OAuth (TikTok / Google).
   - Đánh giá: **Cần tái lập luồng đăng nhập** trước khi gọi.

3. **Nhóm C: Bị khóa bởi Chữ ký Native C++ (High-Security WAF / Anti-Scraping - ~40% API)**:
   - Các API sinh video AI (`/send_msg`), API thanh toán VIP (`/commerce/...`), API tăng lượt xem / tải video.
   - Yêu cầu: Bộ 4 headers bảo vệ native sinh từ `libsscronet.so` / `libmiddle-bridge.so`:
     - `X-Gorgon`: Chữ ký băm MD5/SHA256 kết hợp timestamp và URL params.
     - `X-Khronos`: Dấu thời gian Unix đồng bộ với server ByteDance.
     - `X-Argus`: Chữ ký kiểm tra tính toàn vẹn môi trường (chống máy ảo, chống Frida, kiểm tra Play Integrity).
     - `X-Ladon`: Dữ liệu mã hóa thông tin thiết bị phần cứng.
   - Đánh giá: **Không thể gọi trực tiếp bằng cURL/Postman thông thường** trừ khi:
     - Dùng Frida hook vào hàm sinh chữ ký trong APK để làm RPC server (Remote Procedure Call).
     - Hoặc dịch ngược thuật toán `X-Gorgon / X-Argus` trong `libsscronet.so`.

---

## 2. BẢNG CHI TIẾT CÁC ĐẦU MỤC API ENDPOINTS TIÊU BIỂU THEO PHÂN HỆ

### 2.1. Phân hệ AI Agent & Sáng tạo Thông minh (AI Video Agent & AILab)

| Phương thức HTTP | Đường dẫn Endpoint (Path) | Domain đích | Class Interface & Method | Model Request / Response | Dữ liệu trả về từ Server | Dùng sẵn luôn được không? |
|---|---|---|---|---|---|---|
| `POST` | `/storyboard_agent/v1/ai_lab/send_msg` | `aivideo-normal.capcutapi.com` | `AiLabHostSseTransport.a()` | Req: `JSONObject {session_id, agent_scene, prompt, media_items}`<br>Resp: `SSE Stream (Chunked)` | Luồng phản hồi văn bản thời gian thực (Server-Sent Events), trạng thái suy luận của LLM, mã công cụ MCP cần gọi | ⚠️ Cần `sessionid` + Chữ ký `X-Gorgon/X-Khronos` + `X-SS-REQ-TICKET` |
| `POST` | `/storyboard_agent/v1/ai_lab/get_conversation_details` | `aivideo-normal.capcutapi.com` | `UAgentApiService.getConversationDetailsRaw()` | Req: `TypedJson`<br>Resp: `JsonObject` | Chi tiết toàn bộ tin nhắn, hình ảnh đính kèm, video đã tạo trong phiên chat AI cụ thể | ⚠️ Cần Header `Uid` + `sessionid` |
| `POST` | `/storyboard_agent/v1/ai_lab/get_asset_draft` | `aivideo-normal.capcutapi.com` | `UAgentApiService.getAssetDraft()` | Req: `GetAssetDraftRequestBody`<br>Resp: `BaseResponse<GetAssetDraftResponse>` | Cấu trúc bản nháp video (Draft JSON) do AI tự động dựng: danh sách cut, track, text, font, hiệu ứng | ⚠️ Cần `sessionid` + `draft_id` hợp lệ |
| `POST` | `/storyboard_agent/v1/ai_lab/get_remain_free_credit` | `aivideo-normal.capcutapi.com` | `UnifyAgentHomepageNetworkApi.getFreeCreditToast()` | Req: `TypedJson`<br>Resp: `BaseResponse<FreeCreditInfo>` | Số lượt tạo video AI miễn phí còn lại trong ngày của người dùng, thời gian reset hạn mức | ✅ Dùng được khi có `sessionid` |
| `POST` | `/storyboard_agent/v1/ai_lab/poll_by_event_id` | `aivideo-normal.capcutapi.com` | `UAgentApiService.pollByEventId()` | Req: `TypedJson {event_id, session_id}`<br>Resp: `JsonObject` | Trạng thái tiến độ tạo video AI nền đám mây (Rendering progress 0-100%, Download URL khi hoàn tất) | ⚠️ Cần `sessionid` + `event_id` |
| `POST` | `/lv/v1/trend_agent/model_list` | `aivideo-normal.capcutapi.com` | `AiTrendsApiService.getDynamicTabConfigs()` | Req: `TypedJson`<br>Resp: `BaseResponse<DynamicTabConfig>` | Danh sách các model AI đang hỗ trợ (Text-to-Video, Scriptwriter, Avatar 3D, Face Swap) kèm metadata | ✅ **Có thể dùng sẵn** (Public Metadata) |
| `POST` | `/lv/v1/agent_gen/query_v2t` | `editor-api.capcutapi.com` | `SpeechRecognizeApiService.queryAudioText()` | Req: `QueryV2TRequest {tos_id}`<br>Resp: `BaseResponse<AsrResult>` | Toàn bộ văn bản chuyển từ giọng nói (Speech-to-Text), kèm mốc thời gian (timestamps) từng từ | ⚠️ Cần `tos_id` file âm thanh đã upload |

---

### 2.2. Phân hệ Thương mại, Gói Đăng Ký VIP & Paywall (Commerce & Subscriptions)

| Phương thức HTTP | Đường dẫn Endpoint (Path) | Domain đích | Class Interface & Method | Model Request / Response | Dữ liệu trả về từ Server | Dùng sẵn luôn được không? |
|---|---|---|---|---|---|---|
| `POST` | `/commerce/v1/subscription/user_info` | `commerce-api.capcutapi.com` | `ISubscribePageNetAPI.fetchUserInfo()` | Req: `TypedJson`<br>Resp: `BaseResponse<SubscriptionUserInfo>` | Trạng thái Pro của người dùng: `is_vip` (true/false), cấp độ VIP (`VipLevel`), ngày hết hạn, loại gói | ⚠️ Cần `sessionid` |
| `POST` | `/commerce/v1/subscription/products` | `commerce-api.capcutapi.com` | `ISubscribePageNetAPI.getProductList()` | Req: `ProductListRequest`<br>Resp: `BaseResponse<SubscriptionPlanList>` | Danh mục các gói bán Pro: Monthly, Yearly, Lifetime, kèm Google Play Product ID (`sku_id`), giá niêm yết | ✅ **Có thể dùng sẵn** (Public Catalog) |
| `POST` | `/commerce/v1/subscription/detain_strategy` | `commerce-api.capcutapi.com` | `ISubscribePageNetAPI.getDetainStrategy()` | Req: `DetainRequest`<br>Resp: `BaseResponse<DetainStrategy>` | Kịch bản giảm giá giữ chân khi người dùng chuẩn bị thoát Paywall (mức giảm 20%-50%, thời hạn voucher) | ⚠️ Cần `device_id` |
| `POST` | `/commerce/v1/order/create` | `commerce-api.capcutapi.com` | `IExtendApi.createOrder()` | Req: `CreateOrderRequest`<br>Resp: `BaseResponse<OrderInfo>` | Tạo mã đơn hàng nội bộ trước khi chuyển sang Google Play Billing hoặc cổng thanh toán web | ⚠️ Cần `sessionid` + `sku_id` |
| `POST` | `/commerce/v1/order/verify_google_token` | `commerce-api.capcutapi.com` | `IExtendApi.verifyGooglePurchase()` | Req: `VerifyGoogleRequest {purchase_token, order_id}`<br>Resp: `BaseResponse<VerifyResult>` | Xác thực biên lai mua hàng từ Google Play Store, kích hoạt quyền Pro cho tài khoản | ⚠️ Cần `purchase_token` hợp lệ |

---

### 2.3. Phân hệ Lưu Trữ Đám Mây & Đồng Bộ Bản Nháp (Cloud Storage & Drafts)

| Phương thức HTTP | Đường dẫn Endpoint (Path) | Domain đích | Class Interface & Method | Model Request / Response | Dữ liệu trả về từ Server | Dùng sẵn luôn được không? |
|---|---|---|---|---|---|---|
| `POST` | `/cloud/v1/space/info` | `cloudspace-normal.capcutapi.com` | `SpaceInfoApi.getSpaceInfo()` | Req: `TypedJson`<br>Resp: `BaseResponse<SpaceInfo>` | Tổng dung lượng đám mây (VD: 10GB/100GB/1TB), dung lượng đã sử dụng, danh sách tệp lớn | ⚠️ Cần `sessionid` |
| `POST` | `/cloud/v1/draft/list` | `cloudspace-normal.capcutapi.com` | `ICloudDraftApi.getDraftList()` | Req: `DraftListRequest`<br>Resp: `BaseResponse<DraftListResponse>` | Danh sách bản nháp lưu trên mây: tên dự án, ảnh bìa, kích thước, thời gian sửa đổi cuối | ⚠️ Cần `sessionid` |
| `POST` | `/cloud/v1/draft/get_upload_token` | `cloudspace-normal.capcutapi.com` | `ICloudDraftApi.getUploadToken()` | Req: `UploadTokenRequest`<br>Resp: `BaseResponse<UploadTokenResponse>` | Pre-signed URL và access token để client tải trực tiếp video/ảnh lên ByteDance TOS Storage (S3-compatible) | ⚠️ Cần `sessionid` + MD5 checksum |

---

### 2.4. Phân hệ Video Mẫu Cộng Đồng & Feed (Templates & CutSame)

| Phương thức HTTP | Đường dẫn Endpoint (Path) | Domain đích | Class Interface & Method | Model Request / Response | Dữ liệu trả về từ Server | Dùng sẵn luôn được không? |
|---|---|---|---|---|---|---|
| `GET` | `/feed/v2/templates/recommend` | `feed-api.capcutapi.com` | `AIAgentFeedAPIService.fetchCollections()` | Query: `count=20&cursor=0`<br>Resp: `BaseResponse<TemplateFeedData>` | Danh sách 20 video mẫu xu hướng mới nhất: URL video demo, thông tin tác giả, ID bài hát, lượt xem | ✅ **Có thể dùng sẵn ngay** |
| `GET` | `/feed/v2/template/detail` | `feed-api.capcutapi.com` | `AIAgentFeedAPIService.fetchTemplateDetail()` | Query: `template_id=...`<br>Resp: `BaseResponse<TemplateDetailData>` | Cấu trúc kỹ thuật của mẫu: số lượng slot cần thay thế, thời lượng từng đoạn cắt, hiệu ứng chuyển cảnh | ✅ **Có thể dùng sẵn ngay** |
| `POST` | `/storyboard/v1/agent/image_template_recommend` | `feed-api.capcutapi.com` | `AiCreationSugNetworkApi.fetchCollectionTemplates()` | Req: `TypedJson`<br>Resp: `BaseResponse<ImageTemplateList>` | Đề xuất các mẫu thiết kế hình ảnh phù hợp dựa trên nội dung ảnh người dùng tải lên | ✅ Dùng được với header chuẩn |

---

## 3. DỮ LIỆU TRẢ VỀ TỪ SERVER (SERVER RESPONSE PAYLOAD MAPPING)

Tất cả phản hồi từ server CapCut tuân thủ chuẩn cấu trúc bọc đồng nhất `BaseResponse<T>`:

```json
{
  "code": 0,
  "message": "success",
  "data": {
    /* Payload dữ liệu cụ thể */
  },
  "extra": {
    "now": 1725619200000,
    "logid": "2026090610522901021404403301004A"
  }
}
```

- Mã `code == 0`: Gọi API thành công.
- Mã `code == 10001` - `10099`: Lỗi xác thực tài khoản / Hết hạn phiên làm việc (`Token Expired`).
- Mã `code == 20001` - `20099`: Lỗi liên quan đến quyền VIP Pro (Cần mua gói mới xem được tài nguyên).
- Mã `code == 40001`: Lỗi chữ ký bảo mật không khớp (`X-Gorgon Invalid`).
