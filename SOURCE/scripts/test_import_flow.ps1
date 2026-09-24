# Interactive Test Script for CapCut Media Import Flow
$ADB = "C:\Users\boluc\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$DEV = "192.168.1.7:45893"

Write-Host "1. Force-stopping and Starting MainActivity on Samsung Galaxy Note 10 Lite..."
& $ADB -s $DEV shell am force-stop com.nextai.opencut
Start-Sleep -Milliseconds 500
& $ADB -s $DEV shell am start -n com.nextai.opencut/com.nextai.opencut.presentation.MainActivity
Start-Sleep -Milliseconds 1200

Write-Host "2. Tapping Hero 'Dự án mới' to open CapCut Media Picker..."
& $ADB -s $DEV shell input tap 540 350
Start-Sleep -Milliseconds 1000

Write-Host "3. Capturing Media Picker Screenshot..."
& $ADB -s $DEV shell screencap -p /sdcard/capcut_media_picker.png
& $ADB -s $DEV pull /sdcard/capcut_media_picker.png "d:\Decompiler\App\Video\Capcut\design\screenshots\capcut_media_picker.png"

Write-Host "4. Selecting 2 Media Items (Tile 1 and Tile 3 in Grid)..."
& $ADB -s $DEV shell input tap 180 400
Start-Sleep -Milliseconds 400
& $ADB -s $DEV shell input tap 900 400
Start-Sleep -Milliseconds 600

Write-Host "5. Capturing Media Picker with Selected Badges..."
& $ADB -s $DEV shell screencap -p /sdcard/capcut_media_selected.png
& $ADB -s $DEV pull /sdcard/capcut_media_selected.png "d:\Decompiler\App\Video\Capcut\design\screenshots\capcut_media_selected.png"

Write-Host "6. Tapping 'Thêm (2)' button at bottom right (x: 880, y: 2280)..."
& $ADB -s $DEV shell input tap 880 2280
Start-Sleep -Milliseconds 1000

Write-Host "7. Capturing Video Editor with Imported Media on Timeline..."
& $ADB -s $DEV shell screencap -p /sdcard/capcut_imported_timeline.png
& $ADB -s $DEV pull /sdcard/capcut_imported_timeline.png "d:\Decompiler\App\Video\Capcut\design\screenshots\capcut_imported_timeline.png"

Write-Host "=== TEST FLOW COMPLETED SUCCESSFULLY ==="
