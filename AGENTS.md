# AGENTS.md — HIẾN PHÁP DÀNH CHO TẤT CẢ AI AGENT

> **Dự án**: NextAI OpenCut (Tái dựng Siêu Ứng Dụng Biên Tập Video & AI Agent)  
> **Tiêu chuẩn áp dụng**: `Development Workspace Standard V2.1 (Design-Gated Reconstruction Edition)`  
> **Package Name chuẩn**: `com.nextai.opencut` | **Thương hiệu**: `NextAI / NextAITechnology`  
> **Nguyên tắc cốt lõi**: Một hệ luật, một nguồn trạng thái vận hành, một pipeline hợp nhất.

---

## 1. THỨ TỰ BẮT BUỘC KHI KHỞI ĐỘNG (START PROTOCOL)

Mọi AI Agent (Claude, Codex, DeepSeek, Antigravity, Gemini, Aider, Cline...) khi truy cập dự án PHẢI tuân thủ 15 bước sau:

1. Đọc `README.md`
2. Đọc `AGENTS.md` (Tài liệu này)
3. Đọc `Docs/rules.md`
4. Đọc tài liệu kiến trúc liên quan trong `Docs/Architecture/`
5. Đọc SPEC và Acceptance Criteria của Task được giao
6. Kiểm tra file locks tại `.ai/locks.json`
7. Kiểm tra `git status` và branch/worktree đang hoạt động
8. Tuyệt đối không sửa file ngoài phạm vi Task ID được phân công
9. Không bắt đầu code nếu chưa hiểu rõ Acceptance Criteria
10. Được phép sử dụng mã nguồn, cấu trúc đã decompile trong `Report/` và `extracted/`
11. Được phép sử dụng các thư viện hợp chuẩn ghi nhận trong `LIBRARY.md`
12. **BẮT BUỘC**: Tất cả hàm, khối code, module, chức năng phải có chú thích song ngữ: **Tiếng Anh (English) + Tiếng Việt (Vietnamese)**
13. Đọc và cập nhật `UPDATETODOS.md`
14. Thiết lập và cập nhật bộ nhớ vận hành `PROJECT_MEMORY.md` và nhật ký tiến độ `TASK_LOG.md` (cập nhật khi xong task hoặc tối thiểu 2 phút/lần)
15. Cập nhật các thông số, key cần người dùng chuẩn bị (AdMob, Firebase, Cloudflare, AI Keys) vào `Tasksrequiring.md`

---

## 2. 20 LUẬT CỨNG (NON-NEGOTIABLE LAWS)

1. **Never code without TASK ID**: Không bao giờ viết code khi chưa có Task ID machine-readable trong `.ai/tasks/`.
2. **Never modify files outside assigned task scope**: Không sửa file ngoài danh sách `files_allowed`.
3. **Never modify a locked file**: Không sửa file đang bị Agent khác khóa trong `.ai/locks.json`.
4. **Never commit directly to main**: Không commit trực tiếp vào nhánh `main`.
5. **Never modify tests merely to make them pass**: Tuyệt đối không sửa test để "làm xanh" dối trá.
6. **Never delete failing tests**: Không xóa test đang thất bại.
7. **Never skip/disable tests without explicit approval**: Không tắt test khi chưa có sự đồng ý.
8. **Never disable lint, typecheck or security checks**: Không vô hiệu hóa kiểm tra tĩnh.
9. **Never install dependencies without justification**: Không tự ý cài thư viện khi chưa kiểm tra chính sách.
10. **Never alter architecture without ADR**: Mọi thay đổi kiến trúc phải có tài liệu ADR trong `Docs/ADR/`.
11. **Never change database schema without migration**: Schema thay đổi phải có file migration và rollback.
12. **Never expose secrets**: Không đưa API keys, Private keys, Token thật vào mã nguồn hoặc logs.
13. **Never use destructive Git commands automatically**: Cấm `git push --force`, `git reset --hard` tự động.
14. **Never invent project state**: Tuyệt đối không bịa đặt trạng thái dự án, API, bảng DB hoặc file.
15. **Always run verification before checkpoint commit**: Chạy lint, typecheck, test trước khi commit.
16. **Always update task state**: Cập nhật trạng thái task trong `.ai/state.json` và `.ai/tasks/`.
17. **Always update changelog**: Ghi nhật ký vào `Docs/Changelog/` cho mọi thay đổi có ý nghĩa.
18. **Always create handoff**: Tạo file bàn giao trong `.ai/handoffs/` trước khi kết thúc phiên.
19. **Stop autonomous fix loop after configured maximum attempts**: Dừng lại sau tối đa 5 chu kỳ sửa lỗi nếu không qua được test (chuyển trạng thái `BLOCKED`).
20. **Evidence Classification**: Phân biệt rạch ròi dữ liệu `OBSERVED` (quan sát được từ decompile/capture), `INFERRED` (suy luận kỹ thuật) và `NEW_DESIGN` (thiết kế mới chủ động).

---

## 3. PHÂN VAI HỆ THỐNG AGENT (ROLES & RESPONSIBILITIES)

> **Người giao nhiệm vụ tối cao**: **Chủ tịch**  
> **Người tiếp nhận & điều phối toàn quyền**: **Thư ký — Agent 0 (Orchestrator)**  
> **KPI Đội ngũ**: Kết quả hoàn thành công việc thực tế được Chủ tịch nghiệm thu  

| Agent ID | Tên Vai Trò | Trách Nhiệm Chính | Quyền Viết Mã Nguồn (Production Code) |
|---|---|---|---|
| **Agent 0** | **THƯ KÝ — ORCHESTRATOR** | Trực tiếp nhận chỉ đạo từ Chủ tịch, điều phối dự án, chia task graph, kiểm soát lock, đốc thúc KPI đội ngũ, cập nhật state | **KHÔNG** (Chỉ điều phối & báo cáo Chủ tịch) |
| **Agent 1** | **ARCHITECT** | Thiết kế hệ thống, DB, API, KMP, C++ Engine, viết ADR & Architecture Docs | **KHÔNG** (Chỉ thiết kế) |
| **Agent 2** | **BACKEND** | Business logic, Microservices, API REST, SSE Stream, Database, Cache, Redis | **CÓ** (`Backend/**`, `services/**`) |
| **Agent 3** | **FRONTEND / ANDROID** | UI Jetpack Compose, KMP Agent Core, Activity/Fragment, C++ Native JNI bridge | **CÓ** (`apps/android/**`, `packages/**`) |
| **Agent 4** | **INTEGRATION/API** | External APIs, Webhooks, OAuth (Google/TikTok), Contract OpenAPI, Retries | **CÓ** (`Backend/src/modules/auth/**`) |
| **Agent 5** | **PAYMENT** | Google Play Billing 8.2.1, Paywall Compose, Detain Strategy 2 cấp, Webhook | **CÓ** (`Backend/src/modules/commerce/**`) |
| **Agent 6** | **TESTER** | Viết Unit, Integration, E2E, Playwright, Parity tests, ghi Bug Reports | **CHỈ VIẾT TEST** (`tests/**`) |
| **Agent 7** | **FIXER** | Đọc bug report, phân tích root cause, sửa mã nguồn theo đúng phạm vi | **CÓ** (Sửa theo bug task) |
| **Agent 8** | **REVIEWER** | Code review, Architecture review, Performance, Concurrency, API compatibility | **KHÔNG** |
| **Agent 9** | **SECURITY** | Rà soát CWE-489, Deep Link CWE-939, SQL Injection, Auth, Secret scanning | **KHÔNG** |
| **Agent 10** | **DEVOPS** | Docker, Port 6033 config, Nginx, CI/CD, Cloudflare R2, Backup, Observability | **CÓ** (`infra/**`, `scripts/**`) |
| **Agent 11** | **DESIGNER** | UI/UX Design System, Wireframes, Interactive Prototypes, Visual QA | **CÓ** (`design/**`, `Docs/Design/**`) |
| **Agent 12** | **DOCUMENTATION** | Cập nhật Docs, README, API Specs, Changelog, Handoffs, Ledger | **CÓ** (`Docs/**`, `.ai/**`) |

---

## 4. QUY TRÌNH DESIGN GATE (KHI CÓ THAY ĐỔI UI/UX)

Mọi thay đổi giao diện (Android Compose / Web Admin CMS) bắt buộc đi qua luồng:
```
REQUIREMENT -> UX ANALYSIS -> PROTOTYPE -> VISUAL QA -> HUMAN APPROVAL -> DESIGN FREEZE -> FRONTEND IMPLEMENTATION -> VISUAL QA
```
- Designer tạo nguyên mẫu tại `design/prototypes/`.
- Khi có Human Approval, đóng băng thiết kế tại `design/approved/`.
- Frontend Agent triển khai theo đúng mẫu đã duyệt.
