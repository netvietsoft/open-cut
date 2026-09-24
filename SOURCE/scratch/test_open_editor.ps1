$ADB = "$env:LOCALAPPDATA\Android\Sdk\platform-tools\adb.exe"
$DEV = "192.168.1.3:36903"

# Go back to home if in recycle bin
& $ADB -s $DEV shell input keyevent KEYCODE_BACK
Start-Sleep -Seconds 1

# Tap "+ Dự án mới (New Project)" at X=500, Y=150
& $ADB -s $DEV shell input tap 500 150
Start-Sleep -Seconds 2

# In Media Picker: tap first video item (X=200, Y=500)
& $ADB -s $DEV shell input tap 200 500
Start-Sleep -Milliseconds 800

# Tap "Nhập (1)" at X=900, Y=2160
& $ADB -s $DEV shell input tap 900 2160
Start-Sleep -Seconds 2

& $ADB -s $DEV shell screencap -p /sdcard/editor_real.png
& $ADB -s $DEV pull /sdcard/editor_real.png design\screenshots\parity100\editor_real.png
