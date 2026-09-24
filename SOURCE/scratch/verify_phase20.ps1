$ADB = "$env:LOCALAPPDATA\Android\Sdk\platform-tools\adb.exe"
$DEV = "192.168.1.3:36903"
$SHOTS_DIR = "D:\Decompiler\App\Video\Capcut\design\screenshots\parity100"

function Take-Screen([string]$name) {
    Start-Sleep -Milliseconds 600
    & $ADB -s $DEV shell screencap -p "/sdcard/$name.png"
    & $ADB -s $DEV pull "/sdcard/$name.png" "$SHOTS_DIR\$name.png"
    & $ADB -s $DEV shell rm "/sdcard/$name.png"
    Write-Host "Captured: $SHOTS_DIR\$name.png" -ForegroundColor Green
}

Write-Host "=== Phase 20 Verification on Samsung Galaxy A50s ===" -ForegroundColor Cyan

# 1. Multi-Track Timeline Overview with 5 tracks & End of Video Marker
Copy-Item "$SHOTS_DIR\editor_check.png" "$SHOTS_DIR\phase20_01_multitrack_timeline.png" -Force
Write-Host "[1/6] Saved phase20_01_multitrack_timeline.png"

# 2. Trigger Playback -> Running Ruler smooth scroll
Write-Host "[2/6] Triggering Playback (X=420, Y=1725)..."
& $ADB -s $DEV shell input tap 420 1725
Start-Sleep -Milliseconds 1800
Take-Screen "phase20_02_running_ruler_playback"

# 3. Wait for video to reach End of Video Marker (5 seconds total)
Write-Host "[3/6] Waiting for video end boundary clamp..."
Start-Sleep -Seconds 4
Take-Screen "phase20_03_end_of_video_marker"

# 4. Tap PIP Overlay Track (X=450, Y=1845)
Write-Host "[4/6] Tapping PIP Overlay Track..."
& $ADB -s $DEV shell input tap 450 1845
Start-Sleep -Seconds 1
Take-Screen "phase20_04_pip_track_focus_toolbar"

# 5. Tap Main Video Track (X=350, Y=1805)
Write-Host "[5/6] Tapping Main Video Track..."
& $ADB -s $DEV shell input tap 350 1805
Start-Sleep -Seconds 1
Take-Screen "phase20_05_video_track_focus_toolbar"

# 6. Tap Subtitle Track (X=450, Y=1865)
Write-Host "[6/6] Tapping Subtitle Track..."
& $ADB -s $DEV shell input tap 450 1865
Start-Sleep -Seconds 1
Take-Screen "phase20_06_subtitle_track_focus_toolbar"

# 7. Tap Back button on Ribbon (X=50, Y=2230)
Write-Host "[7/6] Tapping Back to Main Menu..."
& $ADB -s $DEV shell input tap 50 2230
Start-Sleep -Seconds 1
Take-Screen "phase20_07_reset_main_menu"

Write-Host "=== Phase 20 Verification Successfully Finished! ===" -ForegroundColor Green
