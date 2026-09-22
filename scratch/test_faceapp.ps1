$adb = 'C:\Users\boluc\AppData\Local\Android\Sdk\platform-tools\adb.exe'
$device = '192.168.1.3:36903'

Write-Host "1. Tap Chinh sua anh..."
& $adb -s $device shell input tap 410 770
Start-Sleep -Milliseconds 800

Write-Host "2. Tap first photo item..."
& $adb -s $device shell input tap 188 466
Start-Sleep -Milliseconds 500

Write-Host "3. Tap Them (1)..."
& $adb -s $device shell input tap 933 2121
Start-Sleep -Seconds 1

Write-Host "4. Tap Bien Hoa AI tab..."
& $adb -s $device shell input tap 848 2090
Start-Sleep -Milliseconds 800

Write-Host "5. Screencap Bien Hoa AI..."
& $adb -s $device shell screencap -p /sdcard/screen.png
& $adb -s $device pull /sdcard/screen.png d:\Decompiler\App\Video\Capcut\scratch\screen_tab_bienhoa_real.png

Write-Host "6. Tap Cuoi Rang Ro..."
& $adb -s $device shell input tap 180 1710
Start-Sleep -Milliseconds 800

Write-Host "7. Screencap Smile..."
& $adb -s $device shell screencap -p /sdcard/screen.png
& $adb -s $device pull /sdcard/screen.png d:\Decompiler\App\Video\Capcut\scratch\screen_faceapp_smile.png

Write-Host "Done FaceApp test!"
