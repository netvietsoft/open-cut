<#
===================================================================================
ORCHESTRATOR ALWAYS-ON WATCHDOG - NEXTAI OPENCUT (CHỈ HUY LIÊN TỤC 24/7)
===================================================================================
Chỉ đạo tối cao: Chủ tịch
Vai trò: Agent 0 (Thư ký Orchestrator) & Agent 13 (Adversary Auditor)
Mục tiêu:
  - Luôn luôn thức, không bao giờ bị off.
  - Tự động phục hồi và tái khởi động tức thì nếu gặp ngoại lệ hoặc sập tiến trình.
  - Điều phối các Agent liên tục đào bới, giải mã 167 file .so còn lại.
  - Kích hoạt Agent Đối Kháng (Agent 13) kiểm tra và phản biện mỗi chu kỳ.
  - Lưu trữ nhật ký nhịp tim (heartbeat) vào: SOURCE/logs/orchestrator_always_on.log
===================================================================================
#>

[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
$OutputEncoding = [System.Text.Encoding]::UTF8

$PythonExe = "C:\Users\boluc\AppData\Local\Python\bin\python.exe"
$BaseDir = "D:\Decompiler\App\Video\Capcut\SOURCE"
$DaemonScript = Join-Path $BaseDir "scripts\orchestrator_daemon.py"
$AdversaryScript = Join-Path $BaseDir "scripts\adversary_critic_agent.py"
$VerifyScript = Join-Path $BaseDir "scripts\verify_reconstruction_suite.py"
$LogFile = Join-Path $BaseDir "logs\orchestrator_always_on.log"

# Đảm bảo thư mục logs tồn tại
$LogDir = Join-Path $BaseDir "logs"
if (-not (Test-Path $LogDir)) {
    New-Item -ItemType Directory -Force -Path $LogDir | Out-Null
}

function Write-Heartbeat([string]$message) {
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $line = "[$timestamp] [ALWAYS-ON WATCHDOG] $message"
    Write-Host $line -ForegroundColor Cyan
    Add-Content -Path $LogFile -Value $line -Encoding UTF8
}

Write-Heartbeat "========================================================================"
Write-Heartbeat "KHỞI CHẠY HỆ THỐNG GIÁM SÁT LUÔN LUÔN THỨC (ALWAYS-ON WATCHDOG ENGINE)"
Write-Heartbeat "CHỈ ĐẠO BỞI: CHỦ TỊCH | ĐIỀU PHỐI: AGENT 0 | ĐỐI KHÁNG: AGENT 13"
Write-Heartbeat "MỤC TIÊU: HOÀN TẤT TOÀN DIỆN 169 FILE .SO CỦA CAPCUT (ZERO STUB)"
Write-Heartbeat "========================================================================"

$loopCount = 0
$restartCount = 0

while ($true) {
    $loopCount++
    try {
        Write-Heartbeat ">>> VÒNG LẶP WATCHDOG #$loopCount (Đã tự động hồi sinh: $restartCount lần) <<<"

        # 1. Chạy 1 chu kỳ điều phối của Agent 0
        Write-Heartbeat "Bước 1: Kích hoạt Agent 0 Orchestrator (Quét báo cáo, giao task, giải mã C++)..."
        & $PythonExe $DaemonScript --once 2>&1 | Tee-Object -FilePath $LogFile -Append

        # 2. Chạy chu kỳ phản biện độc lập của Agent 13
        Write-Heartbeat "Bước 2: Kích hoạt Agent 13 Adversary Auditor (Soi code, phát hành trát thách thức)..."
        & $PythonExe $AdversaryScript 2>&1 | Tee-Object -FilePath $LogFile -Append

        # 3. Chạy kiểm chứng bộ test suite khép kín
        Write-Heartbeat "Bước 3: Chạy Closed-Loop Verification Test Suite..."
        & $PythonExe $VerifyScript 2>&1 | Tee-Object -FilePath $LogFile -Append

        Write-Heartbeat "[OK] Chu kỳ #$loopCount hoàn tất thành công. Nghỉ 60 giây trước chu kỳ tiếp theo..."
        Start-Sleep -Seconds 60

    } catch {
        $restartCount++
        $errMsg = $_.Exception.Message
        Write-Heartbeat "[CẢNH BÁO] Phát hiện lỗi trong tiến trình: $errMsg. Đang tự động hồi sinh sau 5 giây..."
        Start-Sleep -Seconds 5
    }
}
