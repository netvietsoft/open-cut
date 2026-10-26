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
