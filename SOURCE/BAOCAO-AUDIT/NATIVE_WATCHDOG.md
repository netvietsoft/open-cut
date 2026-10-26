# Native audit watchdog / Watchdog kiểm tra mã native

`SOURCE/scripts/native_audit_watchdog.py` scans all extracted arm64 `.so` files and matching `SOURCE/GIAI-MA/<library>` C++ folders. It checks file hashes against `apktool-res`, detects changes since the previous local scan, marks empty generated scaffolds, and flags three source patterns found in the 2026-10-23 audit. The scan makes no claim that C++ behavior matches the original binary.

Script quét toàn bộ `.so` arm64 và thư mục C++ tương ứng. Script đối chiếu SHA-256 với bản `apktool-res`, nhận biết thay đổi so với lần quét trước, đánh dấu khung mã rỗng và báo ba mẫu mã rủi ro đã phát hiện. Kết quả **không phải** chứng nhận giải mã đúng thuật toán.

Run once locally / Chạy một lần tại máy:

```powershell
python SOURCE/scripts/native_audit_watchdog.py
```

Install the five-minute Windows scheduled task / Cài tác vụ Windows mỗi 5 phút:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File SOURCE/scripts/install_native_audit_task.ps1 -RunNow
Get-ScheduledTaskInfo -TaskName NextAI_OpenCut_Native_Audit_5min
```

The Windows task runs when the configured user session can run scheduled tasks. The report is saved as ignored local JSON at `SOURCE/BAOCAO-AUDIT/NATIVE_WATCHDOG_LATEST.json`; each completed run atomically replaces it. GitHub Actions also runs on `develop` every five minutes and provides each report as a one-day workflow artifact. GitHub may delay or skip scheduled runs during high load. Neither schedule commits scan output back to Git.

Tác vụ Windows chạy theo phiên người dùng đã đăng ký. Báo cáo JSON mới nhất được lưu tại `SOURCE/BAOCAO-AUDIT/NATIVE_WATCHDOG_LATEST.json` (Git bỏ qua). GitHub Actions quét nhánh mặc định `develop` theo lịch 5 phút và lưu báo cáo dưới dạng artifact một ngày; thời điểm chạy có thể trễ khi GitHub tải cao. Hai lịch không tự commit báo cáo lên Git.

To stop the local schedule / Dừng lịch quét trên máy:

```powershell
Disable-ScheduledTask -TaskName NextAI_OpenCut_Native_Audit_5min
```

## Git pull and handoff / Kéo Git và bàn giao

The Windows five-minute task now runs `SOURCE/scripts/git_audit_watchdog.py`. It clones `develop` into `%LOCALAPPDATA%/NextAI/OpenCut-audit-checkout`, then fetches and fast-forwards that separate checkout on later runs. It never pulls into a developer working tree. The scheduled user needs the `github.com-open-cut` SSH alias. Each cycle scans the fetched commit and writes ignored local `GIT_WATCHDOG_LATEST.md` and `.json` reports under `SOURCE/BAOCAO-AUDIT/`. The tracked `GIT_WATCHDOG_HANDOFF.md` is the initial evidence snapshot for the next team. This is a static scan; it does not start an AI agent process.

Task Windows 5 phút kéo nhánh `develop` vào checkout riêng, không sửa working tree đang làm việc. Báo cáo mới nhất được ghi tại `GIT_WATCHDOG_LATEST.md` và `.json` cục bộ; `GIT_WATCHDOG_HANDOFF.md` là bản chứng cứ ban đầu cho đội tiếp nhận. Script không tự đánh thức AI agent.
