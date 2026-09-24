$adb = Join-Path $env:LOCALAPPDATA "Android\Sdk\platform-tools\adb.exe"
& $adb -s 192.168.1.3:36903 exec-out screencap -p > current_user_screen.png
& $adb -s 192.168.1.3:36903 shell uiautomator dump /sdcard/window_dump.xml
& $adb -s 192.168.1.3:36903 pull /sdcard/window_dump.xml user_screen_dump.xml
Copy-Item current_user_screen.png "C:\Users\boluc\.gemini\antigravity-ide\brain\3fc1c617-da25-4ece-bbd0-eb9bb3669d3e" -Force
