# Docs/CAU_TRUC_THU_MUC.md — SƠ ĐỒ VÀ GIẢI NGHĨA CẤU TRÚC TOÀN BỘ DỰ ÁN

```
PROJECT_ROOT/
├── AGENTS.md                          # Hiến pháp tối cao dành cho mọi AI Agent
├── README.md                          # Tổng quan dự án NextAI OpenCut & Hướng dẫn khởi chạy
├── CLAUDE.md                          # Cấu hình adapter Claude
├── .clinerules                        # Cấu hình adapter Cline / Roo Code
├── UPDATETODOS.md                     # Bảng quản lý tiến độ task thời gian thực
├── Tasksrequiring.md                  # Danh mục tài nguyên/khóa cần người dùng chuẩn bị (AdMob, Firebase, etc.)
├── PROJECT_MEMORY.md                  # Bộ nhớ vận hành dự án
├── TASK_LOG.md                        # Nhật ký chi tiết tiến độ theo phút
├── LIBRARY.md                         # Danh mục thư viện & SDK hợp chuẩn
├── .gitignore / .env.example          # Mẫu biến môi trường và cấu hình git
│
├── .agents/                           # Antigravity Adapter Layer
│   ├── rules/                         # workspace-standard.md, design-gate.md
│   ├── agents/                        # ui-designer/agent.md
│   └── skills/                        # design-mode/SKILL.md
│
├── .ai/                               # Trạng thái Machine-Readable & Task Graph
│   ├── project.yaml / agents.yaml / state.json / locks.json
│   ├── schemas/                       # 13 JSON Schemas chuẩn giao tiếp giữa các agent
│   ├── tasks/                         # backlog, ready, running, review, blocked, done
│   ├── bugs/                          # open, fixed, rejected
│   ├── handoffs/                      # Bàn giao ca giữa các Agent
│   ├── checkpoints/                   # Checkpoints kiểm thử
│   ├── reports/                       # Báo cáo kỹ thuật
│   ├── design/                        # active, review, approved, rejected
│   └── reconstruction/                # ledger.json, evidence, api, domain, parity
│
├── Docs/                              # Kho tri thức và đặc tả kiến trúc Canonical
│   ├── README.md / rules.md / CAU_TRUC_THU_MUC.md
│   ├── Architecture/                  # 14 tài liệu kiến trúc (overview, frontend, backend, video engine, etc.)
│   ├── ADR/                           # Các quyết định kiến trúc (ADR-001 -> ADR-005)
│   ├── Contracts/                     # openapi.yaml, events.md, database-schema.md, error-codes.md
│   ├── Specs/                         # Đặc tả nghiệp vụ & Acceptance criteria
│   ├── Agents/                        # Hồ sơ 13 vai trò Agent (orchestrator, backend, frontend, etc.)
│   ├── Workflows/                     # 8 quy trình (development, design, bug-fix, etc.)
│   ├── Design/                        # DESIGN_SYSTEM.md, ui-principles, accessibility, visual-qa
│   ├── Runbooks/                      # deploy.md, rollback.md, incident.md
│   ├── Security/                      # rules.md, secrets.md, threat-model.md
│   ├── Testing/                       # testing-strategy.md, unit-test.md, parity.md
│   ├── Changelog/                     # CHANGELOG.md & agent-log/
│   ├── Reconstruction/                # overview.md, evidence-model.md, api-recovery.md, parity.md
│   └── Decisions/                     # decision-log.md
│
├── Backend/                           # Hệ thống Backend & Web CMS (TypeScript + Golang, Port 6033)
│   ├── package.json / tsconfig.json
│   ├── src/
│   │   ├── server.ts                  # Khởi chạy Express API Gateway & CMS server tại port 6033
│   │   ├── config/                    # Cấu hình môi trường, bảo mật, cors
│   │   ├── database/                  # PostgreSQL 16 schema, SQLite mock driver, migrations, seeds
│   │   ├── modules/
│   │   │   ├── auth/                  # Identity & Auth Service (JWT, OAuth, Device ID)
│   │   │   ├── ai-agent/              # SSE Stream Server (`/storyboard_agent/v1/ai_lab/send_msg`) & MCP Dispatcher
│   │   │   ├── editor/                # Project Timeline JSON, ASR Speech-to-Text mock, Drafts
│   │   │   ├── templates/             # Video Template Feed, CutSame config, Trending algorithm
│   │   │   ├── commerce/              # VIP Subscriptions, Detain Strategy, Google Play Billing Webhook
│   │   │   ├── assets/                # Cloudflare R2 / S3 Asset manager (Anti-orphaned file deletion)
│   │   │   └── admin-cms/             # CMS API (User CRUD, Device Management, Prompt Tuning, A/B Paywall)
│   │   ├── middleware/                # Auth, RateLimiter, WAF signature validation mock, ErrorHandler
│   │   └── swagger/                   # OpenAPI / Swagger UI config
│   ├── public/                        # Giao diện Web CMS (Responsive, Light/Dark Theme, Dashboard Cards)
│   │   ├── index.html
│   │   ├── css/style.css
│   │   └── js/app.js
│   └── go-worker/                     # High-performance Golang background worker for rendering & SSE
│       ├── main.go
│       └── go.mod
│
├── apps/
│   └── android/                       # Ứng dụng Android Kotlin + KMP + Compose + C++ Engine
│       ├── build.gradle.kts / settings.gradle.kts
│       └── app/
│           ├── build.gradle.kts / CMakeLists.txt
│           └── src/main/
│               ├── AndroidManifest.xml # Đã vá các lỗ hổng exported & bảo mật
│               ├── cpp/               # C++ Native Video Engine Layer (middle_bridge.cpp, audio_dsp.cpp)
│               ├── kotlin/com/nextai/opencut/
│               │   ├── NextAiApplication.kt
│               │   ├── presentation/
│               │   │   ├── MainActivity.kt (6 Bottom Tabs)
│               │   │   ├── compose/subscribe/ComposeSubscribeActivity.kt (VIP Paywall + 2-tier Detain Modal)
│               │   │   ├── editor/VideoEditActivity.kt (Multi-track Timeline)
│               │   │   ├── ailab/AiLabAgentChatActivity.kt (AI Copilot Chat SSE Client)
│               │   │   ├── templates/TemplateFeedActivity.kt (Trending Templates & CutSame)
│               │   │   └── export/ExportActivity.kt (4K/60fps render settings)
│               │   ├── kmp/agent/core/ # Tầng nghiệp vụ KMP chia sẻ 100%
│               │   │   ├── Conversation.kt / ConversationRepo.kt
│               │   │   ├── DefaultAgentMessagingProtocol.kt / SseConnection.kt
│               │   │   └── tools/mcp/McpToolDispatcher.kt (Lõi gọi tool chuẩn MCP)
│               │   ├── engine/MiddleBridgeJni.kt # JNI Bridge gọi xuống C++ Native
│               │   ├── data/          # Network Retrofit client, Room Local DB, Repository pattern
│               │   └── flexbox/       # Yoga Flexbox / Lynx layout adapter
│               └── res/               # Layouts XML, Colors, Strings (vi/en), Drawables
│
├── design/                            # Design Gated Artifacts (prototypes, approved, screenshots)
├── tests/                             # Hệ Thống Kiểm Thử Đa Tầng (unit, integration, parity, playwright)
└── scripts/                           # Kịch bản tự động hóa & CI/CD (test_all, run_backend, adb_test_runner)
```
