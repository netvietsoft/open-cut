$ADB = "$env:LOCALAPPDATA\Android\Sdk\platform-tools\adb.exe"
$DEV = "192.168.1.3:36903"

# Tap "+ Dự án mới (New Project)" at X=540, Y=155
& $ADB -s $DEV shell input tap 540 155
Start-Sleep -Seconds 2

& $ADB -s $DEV shell screencap -p /sdcard/picker_open.png
& $ADB -s $DEV pull /sdcard/picker_open.png design\screenshots\parity100\picker_open.png
