$adb = Join-Path $env:LOCALAPPDATA "Android\Sdk\platform-tools\adb.exe"
& $adb -s 192.168.1.3:36903 pull /sdcard/Pictures/NextAI_OpenCut/opencut_photo_1789811998769.png saved_photo_verified.png
Add-Type -AssemblyName System.Drawing
$img = [System.Drawing.Image]::FromFile((Resolve-Path "saved_photo_verified.png"))
Write-Host ("VERIFIED_DIMENSIONS: Width=" + $img.Width + ", Height=" + $img.Height)
$img.Dispose()
