$adb = Join-Path $env:LOCALAPPDATA "Android\Sdk\platform-tools\adb.exe"
# Find where FB_IMG_1789812444308.jpg is located
$paths = & $adb -s 192.168.1.3:36903 shell "find /sdcard/ -name 'FB_IMG_1789812444308.jpg' 2>/dev/null"
Write-Host "Found paths: $paths"
foreach ($p in $paths) {
    if ($p.Trim()) {
        & $adb -s 192.168.1.3:36903 pull $p.Trim() "FB_IMG_1789812444308.jpg"
        break
    }
}
