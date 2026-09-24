@echo off
echo ====================================================================
echo [NextAI OpenCut] Automated Android Device Testing via ADB (Port 6033)
echo ====================================================================

REM 1. Check ADB Devices / Kiểm tra thiết bị Android kết nối qua ADB
echo [1/4] Checking connected Android devices / emulators...
adb devices

REM 2. Install Built APK / Cài đặt file APK vừa build
echo [2/4] Installing NextAI OpenCut APK (com.nextai.opencut)...
adb install -r apps/android/app/build/outputs/apk/debug/app-debug.apk

REM 3. Launch Application / Khởi động Activity chính
echo [3/4] Launching MainActivity (com.nextai.opencut/.presentation.MainActivity)...
adb shell am start -n com.nextai.opencut/com.nextai.opencut.presentation.MainActivity

REM 4. Automated UI Smoke Test Commands / Chạy các kịch bản kiểm thử tự động
echo [4/4] Simulating user navigation & stress testing...
REM Tap New Project button
adb shell input tap 540 800
REM Send Back key
adb shell input keyevent 4
REM Tap VIP Paywall button
adb shell input tap 900 150
REM Send Back key to trigger 1st Detain Modal (20% discount)
adb shell input keyevent 4
REM Send Back key to trigger 2nd Detain Modal (3-day trial)
adb shell input keyevent 4

echo ====================================================================
echo [SUCCESS] ADB Automated Test Flow Completed on Android Device!
echo ====================================================================
