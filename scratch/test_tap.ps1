$ADB = "$env:LOCALAPPDATA\Android\Sdk\platform-tools\adb.exe"
$DEV = "192.168.1.3:36903"

# Tap draft card 1 at X=500, Y=415
& $ADB -s $DEV shell input tap 500 415
Start-Sleep -Seconds 2

& $ADB -s $DEV shell screencap -p /sdcard/editor_check.png
& $ADB -s $DEV pull /sdcard/editor_check.png design\screenshots\parity100\editor_check.png
