$ADB = "$env:LOCALAPPDATA\Android\Sdk\platform-tools\adb.exe"
$DEV = "192.168.1.3:36903"
$SHOTS_DIR = "D:\Decompiler\App\Video\Capcut\design\screenshots\parity100"

function Take-Screen([string]$name) {
    Start-Sleep -Milliseconds 800
    & $ADB -s $DEV shell screencap -p "/sdcard/$name.png"
    & $ADB -s $DEV pull "/sdcard/$name.png" "$SHOTS_DIR\$name.png"
    & $ADB -s $DEV shell rm "/sdcard/$name.png"
    Write-Host "Captured: $SHOTS_DIR\$name.png" -ForegroundColor Green
}

Write-Host "=== Verifying Phase 19 on Samsung Galaxy A50s ===" -ForegroundColor Cyan

# Check current screen
Take-Screen "phase19_01_app_started"

# Tap draft card 1 to enter editor (X=300, Y=1450)
& $ADB -s $DEV shell input tap 300 1450
Start-Sleep -Seconds 2
Take-Screen "phase19_02_editor_opened"

# Test Scenario 2: Cover Frame Editor
# Tap btnCoverFrame at timeline fixed left col (X=70, Y=1900)
Write-Host "Opening Cover Frame Editor..."
& $ADB -s $DEV shell input tap 70 1900
Start-Sleep -Seconds 2
Take-Screen "phase19_cover_editor_dialog"

# In Cover Editor:
# Tap template "Khung Giữa" (X=360, Y=1680)
& $ADB -s $DEV shell input tap 360 1680
Start-Sleep -Milliseconds 500

# Tap font "Vàng Đậm" (X=160, Y=1540)
& $ADB -s $DEV shell input tap 160 1540
Start-Sleep -Milliseconds 500

# Tap "✓ LƯU LÀM ẢNH BÌA" (X=540, Y=1800)
& $ADB -s $DEV shell input tap 540 1800
Start-Sleep -Seconds 1
Take-Screen "phase19_cover_saved"

# Test Scenario 1: Replace Clip
# Select Clip 0 on timeline (X=350, Y=1900)
Write-Host "Selecting clip for Replace Clip test..."
& $ADB -s $DEV shell input tap 350 1900
Start-Sleep -Seconds 1

# Scroll ribbon left to reveal 'Thay thế' (swipe from X=800 to X=200 at Y=2100)
& $ADB -s $DEV shell input swipe 800 2100 200 2100 300
Start-Sleep -Milliseconds 600

# Tap 'Thay thế' button (X=780, Y=2100)
& $ADB -s $DEV shell input tap 780 2100
Start-Sleep -Seconds 2
Take-Screen "phase19_replace_picker_opened"

# In Picker: Tap first video/photo item (X=200, Y=500)
& $ADB -s $DEV shell input tap 200 500
Start-Sleep -Milliseconds 500

# Tap "Nhập" button (X=900, Y=2250)
& $ADB -s $DEV shell input tap 900 2250
Start-Sleep -Seconds 2
Take-Screen "phase19_replace_clip_verified"

# Test Scenario 3: Word-by-Word Karaoke Subtitles
# Return to Main ribbon (tap timeline empty area or back arrow)
& $ADB -s $DEV shell input tap 540 1000
Start-Sleep -Milliseconds 500

# Open Subtitle Dialog: Scroll ribbon or tap Captions
# Tap Audio/Text/Captions tool on main ribbon
& $ADB -s $DEV shell input tap 280 2100
Start-Sleep -Seconds 1
Take-Screen "phase19_subtitles_dialog"

# Select "Tiếng Việt" in Subtitle Dialog (X=540, Y=1350)
& $ADB -s $DEV shell input tap 540 1350
Start-Sleep -Seconds 2
Take-Screen "phase19_subtitles_generated"

# Tap Play to start playback and trigger word-by-word karaoke highlight (X=100, Y=1780)
& $ADB -s $DEV shell input tap 100 1780
Start-Sleep -Milliseconds 1200
Take-Screen "phase19_karaoke_highlight"

Write-Host "=== Phase 19 Verification Complete ===" -ForegroundColor Green
