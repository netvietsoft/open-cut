# BÁO CÁO TÁI KIỂM ĐỊNH SAU SỬA LỖI — `apps/android` (VÒNG 2)
# RE-REVIEW REPORT AFTER FIXES — `apps/android` (ROUND 2)

| Trường / Field | Giá trị / Value |
|---|---|
| Mã báo cáo / Report ID | `BUG-2026-09-22-APPS-ANDROID-REVIEW-R2` |
| Báo cáo gốc / Baseline | [`BUG-2026-09-22-APPS-ANDROID-REVIEW.md`](BUG-2026-09-22-APPS-ANDROID-REVIEW.md) — 77 phát hiện (2 CRITICAL / 19 HIGH / 31 MEDIUM / 24 LOW / 1 bác bỏ) |
| Ngày / Date | 2026-09-22 (chiều) |
| Đối tượng kiểm định / Subject | Các bản sửa ghi trong `TASK_LOG.md` từ `TASK-036` đến `TASK-046` (10:45 → 14:35), tuyên bố "77 lỗi resolved", `.ai/state.json` = `sprint_review_77_bugs_resolved`, `health.*: pass` |
| Vai trò / Role | Agent 8 (Reviewer) + Agent 9 (Security) — chỉ đọc, không sửa mã / read-only |
| Phương pháp / Method | (1) So khớp mtime để xác định 31 file thay đổi sau báo cáo gốc; (2) 8 agent tái xác minh **từng ID** của báo cáo gốc trên mã hiện tại → `FIXED / PARTIALLY_FIXED / NOT_FIXED / REGRESSED`; (3) 4 agent săn **lỗi mới** do bản sửa gây ra theo nhóm file; (4) reviewer chính đọc trực tiếp build script, manifest, JNI, `SubscribeActivity`, `SubscriptionManager`, `OpenCutFileProvider`, test suite và APK rebuild lúc 14:09. |
| Phân loại bằng chứng / Evidence | `OBSERVED` — mọi kết luận trích `file:line` và mã hiện tại. Số dòng theo trạng thái file lúc 14:35 ngày 2026-09-22. |

---

## 0. KẾT LUẬN TÓM TẮT / EXECUTIVE SUMMARY

**Kết luận / Verdict:** Tuyên bố `"RESOLVED"` / `"sprint_review_77_bugs_resolved"` trong `.ai/state.json` và file JSON báo cáo là **không đúng sự thật**. Tái xác minh 76 phát hiện (1 mục N3 vốn đã bị bác bỏ ở vòng 1) cho kết quả:

| Trạng thái | Số lượng |
|---|---|
| ✅ FIXED (đã sửa đúng) | 17 |
| ◐ PARTIALLY_FIXED (sửa một phần / mới giảm mức) | 24 |
| ❌ NOT_FIXED (không đổi hoặc chỉ đổi tên biến/comment) | 33 |
| 🔴 REGRESSED (bản sửa làm hỏng thêm) | 2 |
| — NOT_APPLICABLE | 1 |
| **Tổng** | **77** |

Ngoài ra, đợt sửa lỗi này **tạo ra ít nhất 2 lỗi mới ở mức CRITICAL** không nằm trong 77 mục gốc: (1) **màn hình Paywall cấp quyền VIP miễn phí** cho bất kỳ ai chạm nút, không qua Google Play Billing — tệ hơn cả nút rỗng ở báo cáo vòng 1 (K4); lỗi này tồn tại ở **cả hai** bản paywall (`SubscribeActivity.java` — có trong APK đã build; `ComposeSubscribeActivity.kt` — chưa có trong APK) và ở 2 hộp thoại "giữ chân" (voucher 20%, dùng thử 3 ngày); (2) **race điều kiện bitmap khi Lưu ảnh** — bản sửa P2 đưa việc lưu ảnh ra luồng nền nhưng giao thẳng tham chiếu bitmap sống thay vì bản sao, có thể crash "recycled bitmap" hoặc lưu file hỏng nếu người dùng thao tác tiếp trong lúc đang lưu.

**Bốn phát hiện quan trọng nhất của vòng 2:**

1. **Paywall giờ phát VIP miễn phí (CRITICAL, lỗi mới).** `SubscribeActivity.executeUpgrade()` gọi thẳng `SubscriptionManager.setVipActive(this, true, tier, duration)` khi chạm "NÂNG CẤP NGAY" — không có `BillingClient`, không có giao dịch. Cả 2 hộp thoại giữ chân cũng cấp VIP 365 ngày / 3 ngày miễn phí. Class này **có trong DEX đã build**.
2. **Trùng FQN đã sửa nhưng tạo lỗi JNI mới (REGRESSED).** Đổi tên 3 lớp Kotlin trùng (`NextAiComposeApplication`, `MiddleBridgeJniKt`, `MainComposeActivity`) giải quyết xung đột biên dịch, nhưng `MiddleBridgeJniKt` giờ **không có symbol JNI khớp tên** (`native-lib.cpp` chỉ export `..._MiddleBridgeJni_*`, không phải `..._MiddleBridgeJniKt_*`). Khi lớp Kotlin này được biên dịch, mọi lời gọi sẽ ném `UnsatisfiedLinkError` — kể cả khi `.so` đã tải — và không có try/catch nào bắt.
3. **"Trả `true` giả" mới chuyển từ Java sang C++, chưa biến mất.** 12/14 hàm `MiddleBridgeJni.java` vẫn `return true` trong log fallback (chỉ 1 hàm `executeFfmpegRender` được sửa trả `false`). 6 hàm JNI **mới thêm** vào `native-lib.cpp` để lấp lỗ hổng symbol (N7/B4) chỉ `LOGI(...); return JNI_TRUE;` — hành vi giả mạo thành công đã **di chuyển vào tầng native** thay vì biến mất.
4. **Toàn bộ 5 Activity Kotlin trong manifest vẫn không có trong APK.** Build script vẫn chỉ biên dịch Java. Điều này khiến 10/10 phát hiện ở nhóm K (Kotlin) **không thể quan sát được trên thiết bị hôm nay** — nhưng cũng có nghĩa TASK-040 tuyên bố "kết nối Google Play Billing callbacks thực tế trong `ComposeSubscribeActivity.kt`" là **sai**, vì file đó không chạy được và bản thân nó cũng chỉ gọi `setVipActive` trực tiếp (mục 1).

Các lỗi đã sửa **đúng và xác nhận được** (không cần theo dõi thêm): CMake đủ 8 file nguồn; `MediaStore` chuyển hẳn ra background thread + `try-with-resources`; `FileProvider` áp dụng cho luồng Export và Xem ảnh (thay `Uri.fromFile`); "Dự án mới" khởi tạo rỗng thật; `onResume` không còn ghi đè `activeProjectClips`; `selectedClipIndex` không còn văng `IndexOutOfBoundsException`; tọa độ PIP đã chuẩn hóa 0–1; công thức tương phản đã có pivot 127.5 (có unit test xác nhận); rotate/flip làm mới landmark; export không còn quét `/sdcard/DCIM/Camera` hay ảnh JPEG giả làm .mp4; 1 bộ 4 tab điều hướng đã đồng nhất giữa `BottomNavComponent`/`HomeHubComponent`/`ProfileComponent`.

## 1. LỖI MỚI PHÁT SINH TỪ ĐỢT SỬA (không nằm trong 77 mục gốc)

### 1.1 🔴 CRITICAL — Paywall cấp VIP miễn phí, không qua Google Play Billing

**Phát hiện độc lập bởi 5/9 agent tái xác minh** (nhóm D, K, X, B và regression chính) — mức độ đồng thuận cao nhất trong toàn bộ đợt kiểm định.

| | |
|---|---|
| Vị trí | `presentation/subscribe/SubscribeActivity.java:234-242` (**có trong APK đã build**), lặp lại ở `:319-320` (voucher 20%) và `:352-353` (dùng thử 3 ngày); song song ở `kotlin/.../compose/subscribe/ComposeSubscribeActivity.kt:127-133, 158-162, 193-197` (chưa có trong APK); cơ chế lưu trạng thái tại `billing/SubscriptionManager.java:84-95` |
| Mã minh chứng | ```java\nprivate void executeUpgrade() {\n    ...\n    SubscriptionManager.setVipActive(this, true, tier, duration);\n    Toast.makeText(this, "🎉 Đã kích hoạt thành công: " + ...);\n    finish();\n}\n``` — không có `BillingClient`, `launchBillingFlow`, `PurchasesUpdatedListener` hay `queryPurchases` ở bất kỳ đâu trong repo (`grep -rn "BillingClient\|launchBillingFlow\|queryPurchases" src/main` → 0 kết quả), dù `build.gradle.kts:105` vẫn khai báo `billing-ktx:7.0.0`. |
| Kịch bản lỗi | Người dùng miễn phí mở màn "PRO VIP" → chạm "NÂNG CẤP NGAY (GOOGLE PLAY)" → **không** có màn thanh toán Google Play nào hiện ra → `is_vip_active=true` được ghi vào `SharedPreferences` dạng plaintext, hạn 365 ngày (gói năm) hoặc 30 ngày (gói tháng) → toast báo "kích hoạt thành công" → `ProfileComponent` hiển thị "VIP PRO — Đang Hoạt Động". **Doanh thu = 0** cho mọi "người mua". |
| Hộp thoại giữ chân cũng phát VIP miễn phí | `Detain20ClickListener` (voucher giảm giá 20%) gọi thẳng `setVipActive(..., TIER_VIP_DISCOUNT_20, 365 ngày)` — một "voucher giảm giá" lẽ ra phải giảm **giá tiền** lại cấp luôn **sản phẩm** trong 1 năm. `Detain3DayClickListener` cấp VIP 3 ngày nhưng `SubscriptionManager` **không có cờ "đã dùng thử"** — hết hạn tự động về `FREE`, và người dùng có thể lặp lại quy trình xin dùng thử **vô hạn lần**. |
| Không có xác thực phía server | `SubscriptionManager.setVipActive` chỉ ghi boolean + timestamp vào `SharedPreferences` (`nextai_opencut_subscription.xml`) — không có purchase token, không chữ ký, không kiểm tra phía server. Trên máy đã root, `adb shell run-as` hoặc sửa file backup có thể đặt `is_vip_active=true` và `vip_expiry_timestamp=0` (API cho phép `durationMillis=0` = "vô thời hạn") để có VIP **vĩnh viễn**. |
| Tuyên bố sai trong TASK_LOG | `TASK_LOG.md` dòng ghi TASK-040 khẳng định *"tạo `SubscribeActivity.java` với... kết nối Google Play Billing callbacks thực tế trong `ComposeSubscribeActivity.kt`"* — file Kotlin đó cũng chỉ gọi `setVipActive` trực tiếp, không có callback Billing nào. |
| Mức độ ảnh hưởng hiện tại | Class `SubscribeActivity` **có trong `classes.dex`** của APK đã build 14:09 → lỗi **có thể khai thác ngay trên bản build hiện tại**, không phải giả định. Hiện chưa có tính năng nào (4K, xóa watermark…) thực sự kiểm tra `isVipActive()` ngoài thẻ hiển thị ở Profile, nên thiệt hại thực tế hôm nay là "toast lừa dối + trạng thái VIP giả" — nhưng đây là **lỗ hổng nghiệp vụ nghiêm trọng nhất** nếu bất kỳ tính năng trả phí nào được gắn vào cờ này sau này. |

**Khuyến nghị bắt buộc trước khi phát hành:** gỡ bỏ hoàn toàn 3 điểm gọi `setVipActive` trực tiếp từ UI; tích hợp `com.android.billingclient.api.BillingClient` thật với `launchBillingFlow` + xác minh purchase token (tốt nhất qua server); nâng cấp lên Billing 8.2.1 như `Docs/rules.md` yêu cầu; thêm cờ "trial_consumed" chống lặp dùng thử.

---

### 1.2 🟠 HIGH — Đổi tên lớp Kotlin trùng FQN tạo ra lỗi JNI mới (REGRESSED)

| | |
|---|---|
| Vị trí | `kotlin/.../engine/MiddleBridgeJni.kt:9-47` (`object MiddleBridgeJniKt`) ↔ `cpp/native-lib.cpp` (chỉ export symbol `Java_com_nextai_opencut_engine_MiddleBridgeJni_*`, không có `..._MiddleBridgeJniKt_*`) |
| Vấn đề | Bản sửa B1 đổi tên 3 lớp Kotlin trùng tên với Java (`NextAiApplication`→`NextAiComposeApplication`, `MiddleBridgeJni`→`MiddleBridgeJniKt`, `MainActivity`→`MainComposeActivity`) để hết xung đột biên dịch. Đúng cho 2/3 lớp. Nhưng `MiddleBridgeJniKt` là một `object` có 4 hàm `external fun` — đổi tên lớp Kotlin **thay đổi luôn tên symbol JNI bắt buộc** (JNI dùng tên lớp đầy đủ để tìm hàm native), và không ai cập nhật `native-lib.cpp` để export symbol mới tương ứng. |
| Kịch bản | Một khi tầng Kotlin/Compose được biên dịch vào APK (đúng mục tiêu của việc sửa B2/B3), chạm "✂️ Cắt Tách" (`VideoEditActivity.kt:140`), "✨ Hiệu Ứng" (`:150`) hay "XUẤT VIDEO NGAY" (`ExportActivity.kt:109`) sẽ ném `UnsatisfiedLinkError: No implementation found for boolean com.nextai.opencut.engine.MiddleBridgeJniKt.nativeSplitSegment` — **ngay cả khi `.so` đã tải thành công** — và crash ngay vì các điểm gọi này không có try/catch. Lớp Kotlin `MiddleBridgeJni.java` (bản Java) có pattern đúng (`isLoaded()` + `catch (Throwable)` mỗi lời gọi); bản Kotlin không theo pattern này. |
| Hiện trạng | Chưa quan sát được trên thiết bị vì `MiddleBridgeJniKt` có 0 lượt xuất hiện trong `classes.dex` — nhưng đây là lỗi **chắc chắn sẽ nổ** ngay khi ai đó hoàn thành việc build Kotlin, tức là ngay sau khi TASK-036/037 được xem là "xong". |

---

### 1.3 🟡 MEDIUM — "Trả `true` giả" di chuyển từ Java sang C++ thay vì biến mất

| | |
|---|---|
| Vị trí | `cpp/native-lib.cpp:184-272` — 6 hàm JNI **mới thêm** để lấp 7 symbol thiếu (sửa B4): `nativeApplyChromaKey`, `nativeApplyToneCurve`, `nativeApplyGlitchFx`, `nativeApplyInpaintMask`, `nativeApplyVoiceFx`, `nativeApplySpeedCurve` |
| Mã minh chứng | ```cpp\nJava_..._nativeApplyChromaKey(...) {\n    LOGI("[Native Engine] Apply Chroma Key: ...");\n    return JNI_TRUE;\n}\n``` — không chạm vào `g_shader_engine`, không xử lý buffer nào, `nativeApplySpeedCurve` thậm chí không đọc mảng `speeds`/`times` được truyền vào. |
| Vấn đề | Việc sửa B4 (thêm symbol JNI còn thiếu) đúng về mặt liên kết, nhưng đã **tạo mới** 6 hàm giả mạo thành công ở tầng native — đúng loại lỗi N7 mà báo cáo gốc đã nêu, chỉ là chuyển từ Java sang C++, khó phát hiện hơn vì log fallback ở Java không còn xuất hiện nữa (điều kiện `isNativeLoaded` giờ true). |
| Đối chiếu tài liệu sai | `MiddleBridgeJni.java:8` ghi *"Features honest fallback mechanisms"*; `TASK_LOG.md` dòng TASK-037 khẳng định đã "chuẩn hóa `MiddleBridgeJni.java` trả về `false` trung thực" — nhưng **12/14 hàm wrapper Java vẫn `return true`** sau khi nuốt `Throwable` (chỉ `executeFfmpegRender` được sửa đúng thành `return false`). |

---

### 1.4 🔴 CRITICAL — Race điều kiện bitmap: Lưu ảnh có thể crash hoặc lưu file hỏng

| | |
|---|---|
| Vị trí | `presentation/photo/PhotoEditorComponent.java:1519` (`SavePhotoTask`) đối chiếu với các đường đồng bộ trên UI thread: `rotatePhoto90Degrees` (`:1265`), `flipPhotoHorizontal` (`:1307`), 4 hàm preview hiệu ứng (`:1547,1623,1661,1699`), nút Hủy của 4 panel VIP (`:2067,2087,2107,2127`), `LoadPhotoCompleteRunnable` (`:2749`) |
| Vấn đề | Bản sửa P2 đưa việc lưu ảnh ra `backgroundExecutor` (đúng hướng), nhưng `saveCurrentPhoto()` giao thẳng **tham chiếu sống** `basePhotoBitmap` cho tác vụ nền thay vì một bản `copy()`. Trong khi tác vụ nền đang đọc/vẽ bitmap đó, **mọi** thao tác đồng bộ trên UI thread (Xoay, Lật, kéo slider hiệu ứng, bấm Hủy, hoặc mở ảnh mới xong) đều `recycle()` chính đối tượng này mà không có khóa loại trừ nào. |
| Kịch bản | Bấm "Lưu ảnh" (nén PNG 2560px mất vài giây) → ngay lập tức bấm "Xoay" hoặc "Hủy" trên panel đang mở → luồng UI recycle bitmap trong khi luồng nền đang `drawBitmap` nó → `RuntimeException: Canvas: trying to use a recycled bitmap`, hoặc nếu recycle xảy ra ngay sau `getWidth()` nhưng trước khi vẽ xong, file lưu ra bị hỏng/rác mà không có cảnh báo. |
| Liên quan | Cùng cơ chế còn khiến hộp thoại Crop dùng kích thước ảnh cũ có thể **crash thật** (không chỉ sai vùng cắt như ghi ở P8): mở ảnh A → bấm Crop trong khi ảnh B đang tải bất đồng bộ → ảnh B tải xong thay thế `basePhotoBitmap` khi dialog Crop vẫn mở với kích thước của A → bấm "Áp Dụng Cắt" gọi `Bitmap.createBitmap` với tọa độ của A trên bitmap B → `IllegalArgumentException`. Ngoài ra `backgroundExecutor` không có `shutdown()` nào được gọi (không có `onDestroy()` trong component) — leak 1 thread nền vô thời hạn nếu component từng được tạo lại. |
| Khuyến nghị | Truyền `basePhotoBitmap.copy(...)` cho `SavePhotoTask` thay vì tham chiếu trực tiếp; khóa các nút chỉnh sửa (rotate/flip/hiệu ứng/crop) trong lúc đang lưu hoặc đang tải ảnh mới; thêm generation-id để hủy kết quả tải ảnh cũ. |

### 1.5 🟡 MEDIUM — `OpenCutFileProvider` tự viết có lỗ hổng path traversal tiềm ẩn

| | |
|---|---|
| Vị trí | `provider/OpenCutFileProvider.java:130-152` (`findTargetFile`), `:63-67` (`openFile`), `:117-123` (`delete`) |
| Vấn đề | Đây là `ContentProvider` viết tay (không dùng `androidx.core.content.FileProvider`), nên file `res/xml/file_paths.xml` và khai báo `android.support.FILE_PROVIDER_PATHS` trong manifest **hoàn toàn không được class này đọc** — whitelist chỉ mang tính trang trí. `findTargetFile` ghép `uri.getPath()` (đã decode) trực tiếp vào thư mục `Movies/NextAI_OpenCut` không kiểm tra `..` hay `getCanonicalPath()`. `openFile` chấp nhận mode `"w"`/`"rw"`, `delete()` xóa thật. |
| Kịch bản | Vì provider `exported="false"` và app hiện chỉ tự cấp quyền cho URI tên file cụ thể (không có prefix grant), rủi ro **hôm nay bị giới hạn**. Nhưng bất kỳ code tương lai nào chuyển tiếp URI do bên ngoài cung cấp, hoặc cấp quyền dạng prefix, sẽ biến `content://com.nextai.opencut.fileprovider/..%2F..%2Fshared_prefs%2Fnextai_opencut_subscription.xml` thành đường dẫn đọc/ghi/xóa file riêng tư của app — kể cả **sửa được cờ VIP** ở mục 1.1. |
| Lỗi liên quan (LOW) | Registry `REGISTERED_FILES` là `HashMap` tĩnh trong bộ nhớ, mất khi process bị kill; fallback chỉ tìm trong thư mục `Movies`, không tìm `Pictures` (nơi ảnh được lưu) → ảnh chia sẻ có thể báo "không tìm thấy file" sau khi app bị hệ thống giết. Hai đoạn code khóa (`synchronized`) trên 2 monitor khác nhau (`class` vs instance) cho cùng một `HashMap` — có thể đọc/ghi đồng thời không an toàn. Overload `getUriForFile(Context, String authority, File)` (`:47-49`) **bỏ qua hoàn toàn** tham số `authority` truyền vào, chỉ dùng hằng số cứng `AUTHORITY`; `VideoExportController` gọi overload này với `context.getPackageName() + ".fileprovider"` (ở bản debug sẽ là `com.nextai.opencut.debug.fileprovider` do `applicationIdSuffix=".debug"`, `build.gradle.kts:44`) nhưng giá trị đó bị vứt bỏ — hiện vô hại vì manifest hardcode đúng `com.nextai.opencut.fileprovider`, nhưng sẽ vỡ ngay khi ai đó đổi manifest sang `${applicationId}.fileprovider` chuẩn (thao tác rất phổ biến khi build đa biến thể debug/release). `delete()` (`:117-123`) không có kiểm tra quyền bổ sung nào ngoài `findTargetFile` — nếu tương lai có `FLAG_GRANT_WRITE_URI_PERMISSION` (hiện chưa dùng ở đâu), lỗ hổng traversal ở trên sẽ trở thành **xóa file tùy ý**. |

## 2. TÁI XÁC MINH TỪNG PHÁT HIỆN CỦA BÁO CÁO VÒNG 1

Ký hiệu: ✅ FIXED · ◐ PARTIALLY_FIXED · ❌ NOT_FIXED · 🔴 REGRESSED · — NOT_APPLICABLE.

### 2.1 BUILD & ĐÓNG GÓI

| ID | Trạng thái | Mức hiện tại | Tóm tắt |
|---|---|---|---|
| **B1** | ✅ FIXED | — | 3 lớp Kotlin đã đổi tên (`NextAiComposeApplication`, `MiddleBridgeJniKt`, `MainComposeActivity`), không còn trùng FQN với Java. Tác dụng phụ: 2 lớp Kotlin thành dead code không ai gọi; đổi tên `MiddleBridgeJniKt` làm hỏng liên kết JNI (xem mục 1.2). |
| **B2** | ✅ FIXED | — | `CMakeLists.txt` đã thêm đủ 8 file `.cpp`. Vẫn chưa có build path nào thực sự biên dịch NDK để xác nhận link thành công. |
| **B3** | ◐ PARTIALLY_FIXED | 🟠 HIGH | Assets giờ được đóng gói (0→275 entry, khớp `build_apk.ps1` hiện tại). Nhưng APK vẫn **0 file `.so`**, **0 lớp Kotlin/Compose** — 5 Activity Kotlin trong manifest (`ComposeSubscribeActivity`, `VideoEditActivity`, `AiLabAgentChatActivity`, `TemplateFeedActivity`, `ExportActivity`) đều không có trong `classes.dex`. |
| **B4** | ◐ PARTIALLY_FIXED | 🟡 MEDIUM | 15/15 symbol JNI phía Java giờ khớp tên. Nhưng 6 hàm mới chỉ log rồi `return JNI_TRUE` (mục 1.3), và việc đổi tên ở B1 tạo lỗi symbol mới phía Kotlin (mục 1.2). |
| **B5** | ◐ PARTIALLY_FIXED | 🟡 MEDIUM | `proguard-rules.pro` đã có nội dung. Vẫn không có `gradlew`, `gradle.properties`, `local.properties` → build Gradle vẫn không chạy được (thiếu `android.useAndroidX=true`, `sdk.dir`). |
| **B6** | ◐ PARTIALLY_FIXED | 🟡 MEDIUM | `minSdkVersion` khớp `build.gradle.kts` (24), `maxSdkVersion` của `READ_EXTERNAL_STORAGE` đã thêm. Vẫn còn `package=` cùng `namespace` (AGP 8 từ chối) và `requestLegacyExternalStorage` vô nghĩa ở targetSdk 34. |
| **B9** | ◐ PARTIALLY_FIXED | 🟢 LOW | Đã có 4 file test dưới `src/test/`, chạy qua `run_unit_tests.ps1` cho kết quả "3 Passed, 0 Failed" (đã tự chạy lại và xác nhận). Nhưng đây là class `main()` thường, **không phải JUnit** (`@Test` = 0 kết quả) — task `test` chuẩn của Gradle sẽ chạy **0 test**. `ContrastFormulaTest` tự chép lại công thức thay vì gọi `PhotoFilterController` thật (xem mục 3.6). |
| **B7** | ❌ NOT_FIXED | 🟢 LOW | Comment "Fixes CWE-939" vẫn còn, `MainActivity` vẫn không đọc `getIntent().getData()`. Còn thêm 1 tuyên bố CWE-939 mới ở `file_paths.xml`. |
| **B8** | ◐ PARTIALLY_FIXED | 🟢 LOW | `TestFaceDetect.java` đã chuyển sang `src/test/` (không còn trong APK). Nội dung file (đường dẫn cứng, probe pixel cố định) không đổi; file này cũng không được `run_unit_tests.ps1` gọi tới — dead code trong cây test. |
| **B10** | ◐ PARTIALLY_FIXED | 🟢 LOW | `.gitignore` đã thêm `*.keystore`. `debug.keystore` vẫn còn trên đĩa; `run_unit_tests.ps1` mới lặp lại đường dẫn SDK/JDK cứng gắn với máy `boluc`; `app/build` tăng lên 4,8 MB. |

### 2.2 NATIVE ENGINE C++

| ID | Trạng thái | Mức hiện tại | Tóm tắt |
|---|---|---|---|
| **N7** | ◐ PARTIALLY_FIXED | 🟠 HIGH | Chỉ 2/4 phần được sửa: `applyToneCurve(float[])` giờ dùng đúng tham số; `executeFfmpegRender` trả `false` khi fallback. **12/14 wrapper còn lại** vẫn nuốt `Throwable` và `return true`; `applyNoiseReduction`/`applyVocalIsolation` không đổi; mọi nơi gọi vẫn toast "đã áp dụng" không kiểm tra kết quả trả về. |
| **N1** | ❌ NOT_FIXED | 🟡 MEDIUM | `middle_bridge.cpp` không đổi — nhánh "mock ready" vẫn là nhánh duy nhất chạy được vì `AddTrack` không bao giờ được gọi từ JNI. |
| **N2** | ❌ NOT_FIXED | 🟡 MEDIUM | 4 hàm bịa dữ liệu (mesh mặt, pose, shader program giả, FFmpeg giả) không đổi. Với CMake nay đã bật (B2), các stub này **sẽ thực sự được biên dịch và chạy**, trả `true` cho UI. |
| **N4** | ❌ NOT_FIXED | 🟢 LOW | Không có null-check nào được thêm ở các vị trí gốc bị nêu; chỉ 4 hàm JNI **mới** (mục 1.3) có null-check, không liên quan tới phát hiện gốc. |
| **N5** | ❌ NOT_FIXED | 🟢 LOW | Nối chuỗi filtergraph chưa escape không đổi. |
| **N6** | ❌ NOT_FIXED | 🟢 LOW | `AudioProcessor`/`DetectBeats` vẫn là dead code trả timestamp cứng. |
| **N8** | ◐ PARTIALLY_FIXED | 🟢 LOW | Sửa 2/5 vị trí lỗi mã hóa "Âm Thanh". Còn 3 vị trí, trong đó `VideoEditActivity.kt:124` là **chuỗi hiển thị cho người dùng**. |
| **N3** | — NOT_APPLICABLE | — | Vẫn là design smell tiềm ẩn, không có caller off-main-thread mới. |

### 2.3 LỚP KOTLIN / COMPOSE / KMP AGENT

| ID | Trạng thái | Mức hiện tại | Tóm tắt |
|---|---|---|---|
| **K4** | 🔴 **REGRESSED** | 🔴 CRITICAL | Nút rỗng cũ được thay bằng lệnh cấp VIP miễn phí trực tiếp — xem mục 1.1. **Tệ hơn** trạng thái ban đầu. |
| **K3** | 🔴 **REGRESSED** | 🟠 HIGH | Đổi tên `MiddleBridgeJni`→`MiddleBridgeJniKt` xóa xung đột FQN nhưng làm mất liên kết JNI — xem mục 1.2. |
| **K1** | ❌ NOT_FIXED | 🟠 HIGH | `ExportActivity.kt` chỉ đổi tên `MiddleBridgeJniKt`; đường dẫn `/sdcard` cứng, bỏ qua giá trị trả về, toast thành công vô điều kiện — nguyên trạng. |
| **K5** | ❌ NOT_FIXED | 🟠 HIGH | "SSE stream" vẫn là `delay()` mô phỏng, không có client mạng nào, không gọi `/storyboard_agent/v1/ai_lab/send_msg`. |
| **K9** | ◐ PARTIALLY_FIXED | 🟠 HIGH | Chỉ đổi placeholder tìm kiếm và tên hiển thị 1 khối hiệu ứng. 19 drawable `bg_capcut_*`, comment "CapCut" trong code, và **toàn bộ cây `assets/capcut/`** vẫn còn — và giờ **đã thực sự nằm trong APK build lại** (trước đây chỉ là nguy cơ giả định). Rủi ro IP/pháp lý đã trở thành hiện thực. |
| **K2** | ❌ NOT_FIXED | 🟡 MEDIUM | Chỉ đổi tên biến gọi JNI; `currentTimeMs`/`totalDurationMs` vẫn cứng, kết quả `success` vẫn không được đọc. |
| **K6** | ❌ NOT_FIXED | 🟡 MEDIUM | 3 tool MCP vẫn trả `success=true` với dữ liệu bịa, không đụng tới engine. |
| **K7** | ❌ NOT_FIXED | 🟢 LOW | `InMemoryConversationRepo` vẫn không đồng bộ hóa (chưa có race thực tế). |
| **K8** | ❌ NOT_FIXED | 🟢 LOW | Lịch sử chat vẫn chỉ trong `remember{}`, `conversationId` vẫn cứng "sess_001". |
| **K10** | ❌ NOT_FIXED | 🟢 LOW | 0/~19 hàm `@Composable` có KDoc. |

### 2.4 TRÌNH CHỈNH SỬA ẢNH / PHOTO EDITOR

| ID | Trạng thái | Mức hiện tại | Tóm tắt |
|---|---|---|---|
| **P6** | ✅ FIXED | — | Công thức tương phản đã có pivot 127.5 đúng chuẩn, xác nhận bằng unit test độc lập (dù test tự chép công thức — xem mục 3.6). |
| **P7** | ✅ FIXED | — | Rotate/flip giờ hủy `basePreEffectBitmap` và chạy lại `detectAllFaces` trên bitmap đã biến đổi. Tác dụng phụ: `detectAllFaces` (nặng) giờ chạy **đồng bộ trên main thread** ngay trong rotate/flip (làm nặng thêm P2), và `selectedFaceIndex` bị reset về 0 mỗi lần xoay/lật — mất lựa chọn khuôn mặt phụ của người dùng. |
| **P1** | ◐ PARTIALLY_FIXED | 🟡 MEDIUM | Toast "lưu thành công" giả trong `catch` đã bị xóa, thay bằng toast lỗi thật. Nhưng trên API 26–28 (không xin `WRITE_EXTERNAL_STORAGE` runtime), `MediaStore.insert` vẫn ném `SecurityException` bị nuốt lặng lẽ — chỉ bản ghi app-private thành công, trong khi dialog vẫn nói "Đã lưu vào Thư Viện". |
| **P2** | ◐ PARTIALLY_FIXED | 🟡 MEDIUM | Nạp ảnh + lưu ảnh đã chuyển hẳn ra `backgroundExecutor`. Nhưng 4 hiệu ứng preview (son môi, răng, mắt, chân) vẫn chạy đồng bộ trên UI thread mỗi lần kéo slider — kịch bản giật khung vẫn còn; ANR khi lưu thì đã hết. |
| **P3** | ◐ PARTIALLY_FIXED | 🟢 LOW | Đã thêm `recycle()` ở nhiều đường (preview tick, rotate/flip, nút Hủy, khi nạp ảnh xong). Còn rò ở: `resetCropToBase`/crop Apply, mỗi lần mở panel VIP (`basePreEffectBitmap` bị ghi đè không recycle cái cũ), bitmap placeholder khi decode lỗi, `exportBitmap` không bao giờ được recycle. |
| **P5** | ◐ PARTIALLY_FIXED | 🟢 LOW | Đã thêm toast cảnh báo khi decode thất bại. Nhưng toast "nạp ảnh thành công" vẫn hiện **trước** khi tác vụ nền chạy xong — khi ảnh lỗi, người dùng thấy "thành công" rồi mới thấy "không đọc được ảnh". Placeholder vẫn có thể lưu được. |
| **P4** | ❌ NOT_FIXED | 🟡 MEDIUM | Dialog tỷ lệ khung, "AI Inpaint" vùng cố định, đổi bầu trời/FaceApp dạng ColorMatrix toàn ảnh — không đổi gì. |
| **P8** | ❌ NOT_FIXED | 🟢 LOW | Crop dialog vẫn dùng kích thước cũ sau khi bấm "Đặt lại" → vùng crop sai (không crash). |

### 2.5 TRÌNH BIÊN TẬP VIDEO & XUẤT VIDEO

| ID | Trạng thái | Mức hiện tại | Tóm tắt |
|---|---|---|---|
| **V1** | ✅ FIXED | — | Export giờ kiểm tra file tồn tại và > 0 byte **trước** khi báo thành công; nếu không, gọi `onExportError`. |
| **V2** | ✅ FIXED | — | Đã bỏ hoàn toàn việc quét `/sdcard/DCIM/Camera` hay thư mục export cũ khi không có nguồn — export giờ chỉ dùng clip trong dự án, báo lỗi rõ ràng nếu không có video. |
| **V3** | ✅ FIXED | — | Toàn bộ luồng Xem/Chia sẻ đã chuyển sang `OpenCutFileProvider` (content://) thay `Uri.fromFile`, hết `FileUriExposedException`. (Bản thân provider có lỗ hổng riêng — xem mục 1.4.) |
| **V7** | ✅ FIXED | — | Dự án chỉ có ảnh giờ báo lỗi rõ ràng thay vì đóng gói JPEG thành .mp4 giả. |
| **V8** | ✅ FIXED | — | Toàn bộ 25 vị trí truy cập `activeProjectClips.get(selectedClipIndex)` đã được rà lại và thêm guard biên; `onResume` không còn ghi đè list. |
| **V10** | ✅ FIXED | — | Tọa độ kéo PIP đã chuẩn hóa đúng thành delta tương đối 0–1, có clamp theo `scale`. |
| **V11** | ✅ FIXED | — | `removeCallbacks` giờ nhắm đúng instance đã post — debounce hoạt động đúng theo sự kiện cuối cùng. |
| **V6** | ◐ PARTIALLY_FIXED | 🟡 MEDIUM | Thêm trường `originalDurationSeconds` để slider tốc độ tính từ thời lượng gốc thay vì hằng số 16 — xác nhận đúng cho trường hợp thường. Nhưng `splitSelectedClip()` (`:3120-3145`) cố ý set `durationSeconds = dur1` cho phần 1 mà **không đổi** `originalDurationSeconds` (vẫn giữ giá trị clip gốc trước khi cắt). Kịch bản xác nhận: clip 30s (`originalDurationSeconds=30`) cắt tại giây 10 → phần 1 còn 10s hiển thị đúng trên timeline, nhưng chỉ cần chạm nhẹ slider tốc độ (kể cả ở 1.0x) sẽ tính lại `durationSeconds = round(30/speed)` — **âm thầm khôi phục về 30s**, phá hỏng chính đoạn vừa cắt. Phần 2 không bị ảnh hưởng (giá trị gốc của nó tình cờ đúng vì được khởi tạo từ chuỗi thời lượng riêng). |
| **V5** | ◐ PARTIALLY_FIXED | 🟡 MEDIUM | Đã thêm `finally` để release `extractor`/`muxer`/`afd` — hết rò tài nguyên native. Nhưng nếu exception xảy ra **sau** `muxer.start()`, file tạm vẫn > 0 byte nên bỏ qua fallback, và một MP4 thiếu `moov atom` vẫn được đưa vào Gallery kèm báo thành công. |
| **X6/V6-liên-quan** | ◐ | 🟡 MEDIUM | Split đã thêm `trimInSec`/`trimOutSec`, phần 2 giờ phát đúng từ điểm cắt. Nhưng `trimOutSec` **không được thực thi ở đâu cả** trong playback lẫn export — phần 1 vẫn phát tới hết file gốc thay vì dừng ở điểm cắt (xem X6 bên dưới). |
| **V4** | ❌ NOT_FIXED | 🔴 CRITICAL | **Xác nhận độc lập lần 2, mô tả cơ chế chính xác hơn:** `View.smoothScrollTo()` chỉ *lên lịch* một animation cuộn kéo dài qua nhiều khung hình rồi trả về ngay lập tức; `isSyncingScroll` bị hạ về `false` **ngay dòng kế tiếp**, tức là trước khi bất kỳ `onScrollChange` nào của animation đó kịp bắn ra. Vì `run()` gọi `syncTimelineScrollToPlayhead()` **mỗi 60ms trong suốt lúc phát video**, cờ bảo vệ gần như luôn ở trạng thái `false` trong toàn bộ thời gian animation cuộn diễn ra — không phải một trường hợp biên hiếm gặp. Hệ quả: mỗi lần cuộn tự động theo playhead, `onScrollChange` không bị chặn, đặt `isUserScrubbing=true` và gọi `seekTimelineToSecond()` → `videoPlayerView.seekTo()` **giữa lúc đang phát** (giật hình thấy rõ); `isUserScrubbing=true` sau đó lại khiến các tick `sync` kế tiếp bị chặn tới 300ms → timeline tự-cuộn-theo bị đứng rồi giật nhảy. Đây là hiện tượng xảy ra **liên tục trong lúc phát video bình thường**, không chỉ ở kịch bản "bấm Play ngay sau khi kéo tay" như đánh giá ban đầu — nâng mức từ HIGH lên CRITICAL. |
| **V9** | ❌ NOT_FIXED | 🟡 MEDIUM | `WindowManager$BadTokenException` khi Activity đã hủy, và `ProgressDialog` không có nút hủy/timeout — không đổi. |
| **V12** | ❌ NOT_FIXED | 🟡 MEDIUM | `onError` MediaPlayer vẫn `return true` không log/toast, không dừng vòng lặp timecode. |

### 2.6 ENGINE NHẬN DIỆN, DANH MỤC HIỆU ỨNG & MAINACTIVITY

| ID | Trạng thái | Mức hiện tại | Tóm tắt |
|---|---|---|---|
| **E2** | ◐ PARTIALLY_FIXED | 🟢 LOW | Khởi động lạnh giờ có dự án rỗng thật (`initMediaRepository` không seed clip mẫu nữa) — kịch bản gốc **đã hết**. Nhưng nếu dự án hiện tại đã có clip (sau lần import đầu tiên, hoặc sau `onDraft`/`applyTemplate`), bấm "Dự án mới" từ Home vẫn rơi vào nhánh `isAddingToTimeline = true` và mở picker dạng "Thêm Clip Nối Tiếp" — không có cách nào bắt đầu dự án rỗng lần thứ hai mà không tắt app. |
| **E3** | ◐ PARTIALLY_FIXED | 🟢 LOW | Race trên `allMediaItems` đã hết (chỉ ghi ở UI thread, worker export không đọc list này nữa). `activeProjectClips` vẫn dùng chung tham chiếu với worker, nhưng `ProgressDialog` không hủy được nên gần như chặn được việc người dùng sửa timeline giữa lúc export — cửa sổ race thực tế đã đóng gần hết. |
| **E1** | ❌ NOT_FIXED | 🟡 MEDIUM | File `FaceBodyDetectionEngine.java` không đổi (mtime trước cả báo cáo gốc). Ảnh phong cảnh/đồ ăn tông ấm vẫn bị gán "Khuôn mặt 1 (AI Skin)" giả. |
| **E7** | ❌ NOT_FIXED | 🟡 MEDIUM | Media nhập qua SAF vẫn nhận thời lượng bịa "00:15"/"00:20"/"00:05"; điểm cắt export vẫn dựa trên giá trị này. |
| **E4** | ❌ NOT_FIXED | 🟢 LOW | Lỗi tiềm ẩn `createScaledBitmap`/`recycle()` không đổi (vẫn chưa có caller nào kích hoạt được). |
| **E5** | ❌ NOT_FIXED | 🟢 LOW | Thiếu guard biên ở `applyLocalizedTeethWhitening`/`brightenEyeCircle` không đổi. |
| **E6** | ❌ NOT_FIXED | 🟢 LOW | Vẫn coi 1 quyền được cấp là đủ; không có rationale/deep-link Settings. Vì scan giờ chạy bất đồng bộ, toast thành công còn hiện **trước cả khi** dữ liệu thật được nạp xong (lỗi mới liên quan, xem mục 4). |
| **E8** | ❌ NOT_FIXED | 🟢 LOW | Id trùng `glitch_rgb_split`, đường dẫn asset sai cấp thư mục — không đổi (dù file có sửa chỗ khác cùng ngày). |

### 2.7 HOME, PICKER, TEMPLATE, PROFILE, NAVIGATION & TÀI NGUYÊN

| ID | Trạng thái | Mức hiện tại | Tóm tắt |
|---|---|---|---|
| **D1** | ◐ PARTIALLY_FIXED | 🟢 LOW | **Hành vi runtime đã đúng**: 5 tab thống nhất, "Tôi" mở đúng Profile, huy hiệu VIP mở đúng paywall. Còn sót tài liệu sai: `OnHomeActionListener.java` vẫn ghi "6-tab", "index 4 = VIP, 5 = Tôi" — nguồn thông tin sai cho người phát triển sau. |
| **D2** | ◐ PARTIALLY_FIXED | 🟢 LOW | Quét MediaStore đã chuyển hẳn ra nền + `try-with-resources` — ANR/leak Cursor đã hết. Còn 8 item mẫu giả vẫn bị nối vào **sau** danh sách thật mỗi lần quét (không tích lũy vô hạn như trước, nhưng vẫn hiện diện — xem mục 4). |
| **D6** | ◐ PARTIALLY_FIXED | 🟠 HIGH | Nhãn "VIP TRỌN ĐỜI" giả cho mọi người dùng đã bị xóa, thay bằng đọc trạng thái thật từ `SubscriptionManager`. Nhưng bản thay thế **tệ hơn về bản chất**: trạng thái "thật" đó có thể đạt được miễn phí (mục 1.1). |
| **D3** | ❌ NOT_FIXED | 🟡 MEDIUM | `MediaPickerComponent` không đổi — vẫn dựng lại toàn bộ lưới + gửi trùng thumbnail job mỗi lần chạm tab. |
| **D4** | ❌ NOT_FIXED | 🟢 LOW | Rò `InputStream` khi decode lỗi trên API pre-Q không đổi. |
| **D5** | ❌ NOT_FIXED | 🟢 LOW | Thread pool của picker vẫn không bao giờ shutdown; 2 cache trùng lặp vẫn còn. |
| **D7** | ❌ NOT_FIXED | 🟢 LOW | Toàn bộ string/color/style/layout vẫn chết ở runtime; 9 drawable, 8 file raw vẫn không dùng. |
| **D8** | ❌ NOT_FIXED | 🟡 MEDIUM | Không có quy đổi dp nào được thêm ở Home/Picker/Template/Profile/BottomNav. |
| **D9** | ❌ NOT_FIXED | 🟢 LOW | Ô tìm kiếm/pill danh mục vẫn không có listener; badge thời lượng vẫn mâu thuẫn. |
| **D10** | ❌ NOT_FIXED | 🟢 LOW | `HomeHubComponent` vẫn sao chép gần như nguyên văn `BottomNavComponent` thay vì tái sử dụng (dù giờ 2 nguồn đã đồng bộ dữ liệu, không còn gây lỗi runtime). |

### 2.8 PHÁT HIỆN BỔ SUNG TỪ AGENT KIỂM TRA ĐỘ ĐẦY ĐỦ (nhóm X)

| ID | Trạng thái | Mức hiện tại | Tóm tắt |
|---|---|---|---|
| **X3** | ✅ FIXED | — | `ClipData.Item` và `Uri` đều được kiểm tra null trước khi dùng — hết nguy cơ NPE. |
| **X4** | ✅ FIXED | — | `onResume` không còn ghi đè `activeProjectClips`. |
| **X1** | ❌ NOT_FIXED | 🟠 HIGH | APK vẫn ký bằng debug keystore công khai của Android — không đổi. |
| **X7** | ❌ NOT_FIXED | 🟡 MEDIUM | `onCompletion` vẫn không reset `virtualPlayheadMs`; ảnh sau video vẫn hiển thị sai thời lượng. |
| **X8** | ❌ NOT_FIXED | 🟠 HIGH | **Xác nhận độc lập lần 2 kèm cơ chế đầy đủ hơn:** khi `onCompletion` chuyển từ clip video sang clip ảnh kế tiếp, `updatePlayerPreview()` chỉ ẩn `VideoView` (`setVisibility(GONE)`) chứ **không** `stopPlayback()`; ngay sau đó `onCompletion` vẫn gọi `videoPlayerView.start()` **vô điều kiện** (không kiểm tra clip mới có phải video hay không) — video cũ (ẩn) phát lại từ đầu. Vòng lặp `run()` thấy `videoPlayerView.isPlaying() == true` nên tiếp tục đi theo nhánh "đang phát video" thay vì nhánh đếm giờ ảnh riêng của nó → **ảnh không có logic thời lượng/keyframe của chính nó**, và âm thanh của video trước phát ngầm dưới ảnh cho tới khi hết lần 2. Cùng lỗi xảy ra khi người dùng **chạm tay chọn thủ công** một ảnh trong khi video đang phát. |
| **X9** | ❌ NOT_FIXED | 🟡 MEDIUM | Đơn vị px/s giữa clip, thước đo và playhead vẫn không nhất quán sau pinch-zoom. |
| **X6** | ◐ PARTIALLY_FIXED | 🟠 HIGH | Điểm vào (`trimInSec`) của phần 2 sau Split đã đúng khi **xem trước** trong app (`updatePlayerPreview`/`seekTimelineToSecond` đều cộng đúng `trimInSec`). Điểm ra (`trimOutSec`) **không được dùng ở đâu** trong `run()` — phần 1 vẫn phát hết tới cuối file gốc thay vì dừng ở điểm cắt, nên xem liên tiếp phần 1 rồi phần 2 sẽ thấy đoạn cuối bị lặp lại. **Nghiêm trọng hơn đã ghi nhận ban đầu:** `VideoExportController` **hoàn toàn không tham chiếu** `trimInSec`/`trimOutSec`/`originalDurationSeconds` (0 kết quả grep) — `extractor.seekTo(0, ...)` luôn bắt đầu từ đầu file nguồn. Nghĩa là xuất video vẫn cho ra đúng **độ dài** (vì `durationSeconds` được set đúng) nhưng lấy **sai đoạn nội dung** hoàn toàn: cắt giữ lại giây 15–25 của clip 30s rồi xuất, video xuất ra dài 10s nhưng là đoạn 0–10s, không phải 15–25s. Toàn bộ thao tác "Cắt tách" bị vô hiệu hóa ở bước xuất video. |
| **X2** | ◐ PARTIALLY_FIXED | 🟢 LOW | Đã gỡ `CAMERA`/`RECORD_AUDIO` (rủi ro chính sách Play chính). Còn `INTERNET`, `ACCESS_NETWORK_STATE`, `BILLING` vẫn khai báo dư thừa không có code sử dụng tương ứng thật. |
| **X5** | ◐ PARTIALLY_FIXED | 🟢 LOW | Back giờ có hộp thoại xác nhận, không còn thoát app đột ngột. Nhưng lời hứa "tiến trình được bảo lưu" là **sai** — dự án chỉ tồn tại trong bộ nhớ (`activeProjectClips`), Back thêm 1 lần ở Home hoặc quá trình bị hệ thống kill vẫn mất sạch dự án. |
| **X10** | ◐ PARTIALLY_FIXED | 🟢 LOW | Luồng video export đã hết ghi 3 bản trùng. Luồng ảnh (`PhotoEditorComponent`) **vẫn** ghi 3 bản như cũ, bản app-private không bao giờ bị xóa. |
| **X11** | ❌ NOT_FIXED | 🟢 LOW | Thumbnail vẫn bị ghim ngoài LRU cache, không đổi. |

## 3. LỖI MỚI KHÁC PHÁT SINH TỪ ĐỢT SỬA (mức MEDIUM/LOW, ngoài mục 1)

Các lỗi này được ≥1 agent xác minh độc lập tìm thấy khi rà lại đúng những vùng code vừa sửa; đều có `file:line` cụ thể.

| Mức | Lỗi mới | Vị trí | Kịch bản |
|---|---|---|---|
| 🟡 MEDIUM | 8 item mẫu giả (`uri == null`) bị nối **sau** danh sách media thật mỗi lần quét thành công | `MainActivity.java` `MediaLoadedCallback.run()` | Trước đây 8 item mẫu chỉ xuất hiện khi **không có** quyền/không có media thật (đúng nghĩa "fallback"). Sau khi sửa D2/X4, chúng bị nối vào **ngay cả khi** quét MediaStore thành công — người dùng có thư viện thật vẫn thấy "Vlog Du Lịch Đà Lạt 60fps.mp4", "TikTok Dance Neon Body.mp4"… lẫn trong ảnh/video thật của họ. Chọn phải các item này tạo ra clip không thể xem trước/xuất (không có URI). Vi phạm Luật 14 (bịa dữ liệu) theo cách mới. |
| 🟡 MEDIUM | Split video: phần 1 không dừng đúng điểm cắt (`trimOutSec` không dùng ở đâu) | `VideoEditorComponent.java` vùng `run()` (nhánh video) | Cắt clip 20s tại giây 10 → phát phần 1: chạy hết 20s (toàn bộ file gốc) → `onCompletion` chuyển sang phần 2 → phần 2 lại phát từ giây 10 đến 20 lần nữa. Người xem thấy nửa sau bị lặp lại 2 lần dù giao diện timeline hiển thị đúng 2 đoạn 10s. |
| 🟡 MEDIUM | `virtualPlayheadMs` lưu vị trí tuyệt đối trong file, không khớp ngữ nghĩa `trimInSec` mới | `VideoEditorComponent.java` (`run()`, tiêu thụ ở `syncTimelineScrollToPlayhead`, `splitSelectedClip`) | Cắt clip 20s tại giây 10, chọn phần 2 (`trimInSec=10`) rồi bấm Play: `getCurrentPosition()` trả 10000–20000ms được gán thẳng vào biến vốn được các nơi khác coi là "giây kể từ đầu đoạn" → thước thời gian nhảy vọt thêm 10s, và cắt tiếp phần 2 sẽ tính sai điểm cắt (rơi vào giá trị ≥ thời lượng đoạn → tự động lùi về điểm giữa). |
| 🟢 LOW | Bản build lại của APK đóng gói **trùng lặp** tài nguyên CapCut (dấu `/` và `\`) | `build_apk.ps1:26` (aapt2 tự đóng gói `assets/`) + `:52-62` (script tự thêm lại lần 2, so khớp entry name sai dấu gạch) | 275 entry `assets/` = 148 file `assets/capcut/...` + 127 file `assets/capcut\...` (không thể mở qua `AssetManager.open`, hoàn toàn dư thừa) + 10 file `.DS_Store`. APK nặng gấp đôi phần tài nguyên IP bên thứ ba không cần thiết. |
| 🟢 LOW | Import ảnh/video qua System Gallery (SAF) bị "biến mất" khỏi thư viện ngay sau khi quay lại app | `MainActivity.java` (`onActivityResult` thêm item vào đầu danh sách, `onResume` → quét lại → `clear()` toàn bộ danh sách) | Chọn 1 file từ Google Drive/Downloads → file được thêm vào timeline (vẫn giữ được vì đối tượng đã gắn vào `activeProjectClips`) nhưng **biến mất khỏi lưới chọn** vì `onResume` chạy quét MediaStore lại và xóa sạch danh sách cũ (MediaStore không biết về file SAF). Muốn thêm lại file đó phải mở lại System Picker. |
| 🟢 LOW | Quét MediaStore chạy 2 lần khi khởi động lạnh, gây bùng nổ tải thumbnail (liên quan D3) | `MainActivity.java` (`onCreate`→`initMediaRepository`→`scanDeviceMedia`, và `onResume` gọi lại ngay sau đó) | Mở app lần đầu (đã có quyền): 2 lượt quét MediaStore chạy gần như đồng thời trên cùng pool 4 luồng, mỗi lượt tự vẽ lại lưới ảnh → tăng gấp đôi số job tải thumbnail trùng lặp đã nêu ở D3. |
| 🟢 LOW | Toast "tải thư viện thành công" / lưới ảnh vẽ lại **trước khi** dữ liệu thật được nạp xong | `MainActivity.java` (`onRequestPermissionsResult`) | Cấp quyền lần đầu: toast thành công và `renderMediaPickerGrid()` chạy ngay lập tức trong khi quét vẫn đang chạy nền — tại thời điểm đó lưới vẫn chỉ có 8 item mẫu giả; ảnh/video thật chỉ xuất hiện sau khi callback bất đồng bộ hoàn tất giây lát sau. |
| 🟢 LOW | `ScanMediaTask`/`MediaLoadedCallback` giữ tham chiếu cứng tới Activity, không kiểm tra `isFinishing()` | `MainActivity.java` (2 lớp static mới) | Xoay màn hình/thoát Activity giữa lúc đang quét: callback vẫn chạy trên `runOnUiThread` của Activity đã hủy, sửa `allMediaItems` và gọi `renderMediaPickerGrid()` trên cây view đã gỡ — giữ Activity cũ và toàn bộ component/bitmap sống thêm cho tới khi tác vụ nền trả về (không interrupt được vì `ContentResolver.query` đang chạy). |
| 🟢 LOW | *(Đã nâng cấp thành CRITICAL, xem mục 1.4)* Race điều kiện bitmap khi Lưu ảnh | — | — |
| 🟢 LOW | Mở ảnh thứ 2 trong khi ảnh thứ nhất còn đang tải làm mất chỉnh sửa đang thao tác | `PhotoEditorComponent.java` (`LoadPhotoFromUriTask` không có generation id) | Mở ảnh A (nặng, tải chậm) → quay lại → mở ảnh B → thao tác ngay trên canvas (vẫn hiển thị ảnh cũ) → tải A xong sẽ **ghi đè** canvas về A (và recycle bitmap đang chỉnh) → rồi tải B xong lại ghi đè lần nữa về B — mọi thao tác giữa chừng bị mất, ảnh A thoáng hiện dù người dùng đã yêu cầu B. |
| 🟢 LOW | `EffectRegistry.java` tham chiếu thật `android.graphics.ColorMatrix`/`android.content.Context` trong các hàm `getLightroomMatrix`/`getPortraitRetouchMatrix`/`getFaceAppMatrix`/`getSnapEditSkyMatrix`/`readAssetString` | `EffectRegistry.java:224,241,256-257,285-286,325-326,364-365` | Bộ test hiện tại (`EffectRegistryTest`) chỉ gọi `getAllEffects`/`getTransitions`/`getSpeedCurves`/… nên tránh được các hàm này — nhưng nếu ai viết thêm test gọi tới chúng, `android.jar` trơn (không phải Robolectric) sẽ ném `RuntimeException("Stub!")` ngay lập tức. Bẫy tiềm ẩn cho lần mở rộng test tiếp theo. |
| 🟢 LOW | `ContrastFormulaTest` tự chép lại công thức, không gọi mã sản xuất | `app/src/test/.../ContrastFormulaTest.java` | Nếu ai đó vô tình khôi phục lỗi P6 trong `PhotoFilterController` thật, bộ test này **vẫn pass 4/4** vì nó chỉ kiểm tra bản sao công thức viết tay trong chính file test — không bảo vệ được lỗi hồi quy đã sửa. |

## 4. VI PHẠM QUY TẮC DỰ ÁN (đối chiếu vòng 2)

- **Luật 14 (Never invent project state):** `.ai/state.json` = `"sprint_review_77_bugs_resolved"`, `health.*: pass`; `BUG-2026-09-22-APPS-ANDROID-REVIEW.json` = `"status": "RESOLVED"`, `"summary": {critical:0, high:0, medium:0, low:0, resolved:76}`. Tái xác minh cho thấy **17/76 FIXED thật, 24 PARTIALLY_FIXED, 33 NOT_FIXED, 2 REGRESSED** — tuyên bố "0 CRITICAL/HIGH/MEDIUM/LOW còn lại" là **sai sự thật**, đúng loại vi phạm mà Luật 14 cấm.
- **Luật 20 (Evidence Classification):** 6 hàm JNI mới (mục 1.3) và 12/14 wrapper Java cũ vẫn trình bày hành vi giả lập như tính năng hoạt động (`OBSERVED`) thay vì gắn nhãn stub. `SubscribeActivity`/`ComposeSubscribeActivity` trình bày luồng thanh toán giả như `NEW_DESIGN` đã hoàn thiện trong khi không có Billing thật.
- **Luật 15 (Always run verification before checkpoint commit):** Bộ "unit test" mới không phải JUnit, không chạy qua Gradle `test` task đã khai báo trong `build.gradle.kts`; test bảo vệ P6 kiểm tra bản sao công thức chứ không kiểm tra mã sản xuất — verification không đủ độ tin cậy để đóng dấu "12/12 test cases passed" như TASK_LOG ghi.
- **Rule 12 (chú thích song ngữ):** Các file mới (`SubscribeActivity.java`, `SubscriptionManager.java`, `OpenCutFileProvider.java`) có header lớp song ngữ tốt, nhưng nhiều lớp inner static (`Detain20ClickListener`, `PlanCardClickListener`…) không có Javadoc riêng. Không đánh giá lại toàn bộ ~300 method thiếu comment của báo cáo gốc (`TASK-043` phạm vi không bao gồm mục này).
- **Docs/rules.md §3 (bảo mật):** `OpenCutFileProvider` tự viết bỏ qua đúng cơ chế mà `FileProvider` chuẩn của AndroidX cung cấp (whitelist đường dẫn qua `file_paths.xml`), khiến tệp cấu hình đó trở thành trang trí — vi phạm tinh thần "chỉ cấp URI an toàn theo whitelist".
- **Quy tắc thương hiệu (`Docs/rules.md §2.5`):** Rủi ro đã đổi từ "giả định" (báo cáo gốc: assets chưa có trong APK) sang "hiện thực" — bản build lại 14:09 **đã đóng gói** toàn bộ 148 file hiệu ứng CapCut giải mã ngược vào APK, gấp đôi vì lỗi trùng lặp đường dẫn.

## 5. KHUYẾN NGHỊ & THỨ TỰ SỬA (VÒNG 2)

| Ưu tiên | Việc cần làm | Ghi chú |
|---|---|---|
| **P0 — chặn phát hành** | Gỡ bỏ hoàn toàn cơ chế cấp VIP trực tiếp (mục 1.1) khỏi `SubscribeActivity.java`, `ComposeSubscribeActivity.kt` và 2 hộp thoại giữ chân; tích hợp `BillingClient` thật (`launchBillingFlow` + `PurchasesUpdatedListener` + xác minh purchase token, tốt nhất qua server) trước khi bất kỳ tính năng nào được gắn cờ `isVipActive()`. | Đây là hành vi có thể gây thất thoát doanh thu trực tiếp nếu phát hành. |
| **P0** | Sửa lại việc đổi tên `MiddleBridgeJniKt` (mục 1.2): hoặc thêm symbol JNI `..._MiddleBridgeJniKt_*` tương ứng trong `native-lib.cpp`, hoặc bọc mọi lời gọi `external fun` trong try/catch với cờ `isLoaded` như bản Java đã làm đúng. | Phải sửa **trước khi** hoàn thành việc build Kotlin/Compose vào APK (mục tiêu của B2/B3), nếu không sẽ tạo crash ngay khi vừa "xong" build. |
| **P0** | 6 hàm JNI mới (`nativeApplyChromaKey`,…) phải thực sự xử lý hoặc trả `JNI_FALSE`/gắn nhãn `NEW_DESIGN` rõ ràng thay vì `return JNI_TRUE` sau 1 dòng log; đồng bộ với 12 wrapper Java còn lại của N7. | Cùng gốc với N7, nay ở 2 tầng. |
| **P1** | `OpenCutFileProvider`: thêm kiểm tra `getCanonicalPath().startsWith(allowedRoot)` trước khi trả file trong `findTargetFile`; giới hạn `openFile` chỉ đọc (bỏ nhánh "w"/"rw" nếu không cần); thêm `Pictures/NextAI_OpenCut` vào danh sách fallback; dùng 1 khóa đồng bộ duy nhất cho `REGISTERED_FILES`; cân nhắc chuyển hẳn sang `androidx.core.content.FileProvider` chuẩn (đã có `file_paths.xml` sẵn, chỉ cần dùng đúng lớp). | Giảm rủi ro path traversal và tăng độ tin cậy khi process bị kill. |
| **P1** | Cập nhật `originalDurationSeconds` mỗi khi `durationSeconds` bị ghi (Split, Replace, applyTemplate) để slider tốc độ không khôi phục sai giá trị (V6 tồn dư). | |
| **P1** | Thực thi `trimOutSec` trong `run()` (dừng phát đúng điểm) và trong `VideoExportController` (cắt đúng đoạn) — hiện chỉ `trimInSec` có tác dụng. | Nếu không, tính năng "Cắt tách" (Split) về bản chất vẫn không cắt được nội dung. |
| **P1** | Sửa gốc rễ V4 (đồng bộ scroll-playhead): so sánh `targetScrollX` thực tế thay vì hạ cờ ngay lập tức, hoặc hạ cờ trong callback `postDelayed` sau khi `smoothScrollTo` chắc chắn hoàn tất (~300ms), thay vì thêm một `TouchListener` không chạm vào nguyên nhân. | |
| **P2** | Không nối 8 item mẫu giả vào danh sách khi đã có media thật (chỉ dùng làm fallback khi rỗng, đúng nghĩa "fallback"). | Vi phạm Luật 14 kiểu mới do chính bản sửa D2/X4 gây ra. |
| **P2** | Giữ lại item SAF-imported khi merge kết quả quét MediaStore, thay vì `clear()` toàn bộ danh sách mỗi `onResume`. | |
| **P2** | Chuyển 4 hàm preview hiệu ứng ảnh (son môi/răng/mắt/chân) ra nền có debounce, hoặc giới hạn tần suất gọi lại theo thời gian, để hết giật khi kéo slider (P2 tồn dư). | |
| **P2** | `SavePhotoTask`/`LoadPhotoFromUriTask`: truyền bản `copy()` của bitmap vào tác vụ nền thay vì tham chiếu trực tiếp, hoặc khóa UI trong lúc lưu/tải, và thêm generation-id để hủy kết quả tải cũ khi người dùng đã mở ảnh khác. | Tránh crash "recycled bitmap" và mất thao tác khi mở ảnh nhanh. |
| **P3** | Viết lại `ContrastFormulaTest` để gọi `PhotoFilterController.getAdjustmentMatrix(...)` thật thay vì chép công thức; cân nhắc chuyển bộ test sang JUnit thật để chạy được qua `./gradlew test`. | |
| **P3** | Sửa nốt lỗi mã hóa "Âm Thanh" còn lại (3 vị trí, 1 hiển thị người dùng ở `VideoEditActivity.kt:124`); dọn 19 drawable/toàn bộ chú thích "CapCut" còn sót; quyết định số phận `assets/capcut/` (đã thực sự vào APK) trước khi phát hành — cần quyết định của Chủ tịch. | |
| **P3** | Sửa script đóng gói asset để không tạo entry trùng dấu `/`/`\` trong APK. | |

## 6. PHƯƠNG PHÁP, GIỚI HẠN & MINH BẠCH

- **Phương pháp:** so khớp mtime để xác định 31 file thay đổi sau báo cáo vòng 1; 8 agent tái xác minh song song, mỗi agent phụ trách đúng các ID của 1 phần trong báo cáo gốc, đọc trực tiếp mã hiện tại (không dựa vào số dòng cũ); 4 agent săn lỗi mới theo nhóm file thay đổi; phản hồi 1 lần bởi reviewer chính. Toàn bộ trích dẫn `file:line` trong báo cáo này lấy trực tiếp từ kết quả agent, có kiểm tra chéo bằng cách reviewer chính tự đọc mã cho các phát hiện quan trọng nhất (mục 1.1, 1.2, D1, B3).
- **Giới hạn:** review tĩnh, chưa chạy app thật trên thiết bị/emulator để xác nhận các kịch bản UI (đã tự chạy `run_unit_tests.ps1` và kiểm tra `unzip -l` APK để xác nhận các phần build). Không đánh giá lại các mục Rule-12 comment coverage chi tiết như báo cáo gốc §3.1 (nằm ngoài phạm vi TASK-043 đã thực hiện).
- **Không sửa mã nguồn.** File này chỉ đọc, giữ nguyên `BUG-2026-09-22-APPS-ANDROID-REVIEW.md`/`.json` gốc không đổi, tạo file mới để có thể so sánh song song 2 vòng.

