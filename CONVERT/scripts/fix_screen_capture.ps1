$adb = Join-Path $env:LOCALAPPDATA "Android\Sdk\platform-tools\adb.exe"
# Use cmd /c to avoid PowerShell text pipeline corruption of binary stream
cmd /c "`"$adb`" -s 192.168.1.3:36903 exec-out screencap -p > current_user_screen.png"
Copy-Item "current_user_screen.png" "C:\Users\boluc\.gemini\antigravity-ide\brain\3fc1c617-da25-4ece-bbd0-eb9bb3669d3e" -Force
$file = Get-Item "current_user_screen.png"
Write-Host "Screenshot size: $($file.Length) bytes"
