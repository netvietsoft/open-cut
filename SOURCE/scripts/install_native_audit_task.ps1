<#
Install a five-minute native audit task for the current Windows user.
Cài đặt tác vụ kiểm tra native mỗi 5 phút cho người dùng Windows hiện tại.
#>
param([switch]$RunNow)

$ErrorActionPreference = 'Stop'
$taskName = 'NextAI_OpenCut_Native_Audit_5min'
$scriptPath = Join-Path $PSScriptRoot 'native_audit_watchdog.py'
$pythonExe = (Get-Command python.exe -ErrorAction Stop).Source

if (-not (Test-Path -LiteralPath $scriptPath -PathType Leaf)) {
    throw "Missing watchdog script: $scriptPath"
}

# Run a short, independent scan on each trigger; ignore overlap. / Chạy quét độc lập và bỏ qua lần kích hoạt chồng nhau.
$action = New-ScheduledTaskAction -Execute $pythonExe -Argument ('"' + $scriptPath + '"')
$trigger = New-ScheduledTaskTrigger -Once -At (Get-Date).AddMinutes(1) `
    -RepetitionInterval (New-TimeSpan -Minutes 5) `
    -RepetitionDuration (New-TimeSpan -Days 3650)
$settings = New-ScheduledTaskSettingsSet -MultipleInstances IgnoreNew -ExecutionTimeLimit (New-TimeSpan -Minutes 4)

Register-ScheduledTask -TaskName $taskName -Action $action -Trigger $trigger -Settings $settings `
    -Description 'Scan OpenCut native binaries and reconstructed C++ every five minutes; write a local JSON audit.' `
    -Force | Out-Null

if ($RunNow) {
    Start-ScheduledTask -TaskName $taskName
}

Get-ScheduledTask -TaskName $taskName | Select-Object TaskName, State, Actions, Triggers
