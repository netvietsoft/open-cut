$ADB = "$env:LOCALAPPDATA\Android\Sdk\platform-tools\adb.exe"
$DEV = "192.168.1.3:36903"

# Force stop any background interferers and launch com.nextai.opencut
& $ADB -s $DEV shell am start -n com.nextai.opencut/.presentation.MainActivity -W
Start-Sleep -Seconds 2

& $ADB -s $DEV shell screencap -p /sdcard/opencut_fg.png
& $ADB -s $DEV pull /sdcard/opencut_fg.png design\screenshots\parity100\opencut_fg.png
