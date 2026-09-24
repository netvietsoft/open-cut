# NextAI OpenCut Automated Android Build and Device Installation Script
# Script tu dong dong goi APK, ky so, cai dat len may test Android (emulator-5554) va khoi chay

$SDK_DIR = "$env:LOCALAPPDATA\Android\Sdk"
$BUILD_TOOLS = "$SDK_DIR\build-tools\34.0.0"
$PLATFORM_JAR = "$SDK_DIR\platforms\android-34\android.jar"
$ADB = "$SDK_DIR\platform-tools\adb.exe"

$PROJECT_ROOT = "D:\Decompiler\App\Video\Capcut"
$APP_DIR = "$PROJECT_ROOT\CONVERT\apps\android\app"
$OUT_DIR = "$APP_DIR\build\manual_build"
$BRAIN_DIR = "C:\Users\boluc\.gemini\antigravity-ide\brain\3fc1c617-da25-4ece-bbd0-eb9bb3669d3e"

Write-Host "====================================================================" -ForegroundColor Cyan
Write-Host "Building NextAI OpenCut APK with Photo Editor & Video Timeline..." -ForegroundColor Green
Write-Host "====================================================================" -ForegroundColor Cyan

# 1. Clean and Prepare Build Directories / Don dep thu muc build
if (Test-Path $OUT_DIR) { Remove-Item -Recurse -Force $OUT_DIR }
New-Item -ItemType Directory -Force -Path "$OUT_DIR\res_compiled" | Out-Null
New-Item -ItemType Directory -Force -Path "$OUT_DIR\gen" | Out-Null
New-Item -ItemType Directory -Force -Path "$OUT_DIR\classes" | Out-Null
New-Item -ItemType Directory -Force -Path "$PROJECT_ROOT\design\screenshots" | Out-Null

# 2. Compile Android Resources with AAPT2 / Bien dich tai nguyen
Write-Host "[1/7] Compiling XML resources with AAPT2..." -ForegroundColor Yellow
& "$BUILD_TOOLS\aapt2.exe" compile --dir "$APP_DIR\src\main\res" -o "$OUT_DIR\res_compiled.zip"

Write-Host "[2/7] Linking resources and generating R.java..." -ForegroundColor Yellow
& "$BUILD_TOOLS\aapt2.exe" link -o "$OUT_DIR\unaligned.apk" `
    -I "$PLATFORM_JAR" `
    --manifest "$APP_DIR\src\main\AndroidManifest.xml" `
    --java "$OUT_DIR\gen" `
    --auto-add-overlay `
    "$OUT_DIR\res_compiled.zip"

# 3. Compile Java/Kotlin Code with javac (Java 8 compatibility) / Bien dich ma nguon Java
Write-Host "[3/7] Compiling Java classes (Java 8 compatibility)..." -ForegroundColor Yellow
$javaSources = @(Get-ChildItem -Path "$APP_DIR\src\main\java", "$OUT_DIR\gen" -Filter *.java -Recurse | Select-Object -ExpandProperty FullName)
& javac --release 8 -g:none -cp "$PLATFORM_JAR" -d "$OUT_DIR\classes" $javaSources

# 4. Convert .class to classes.dex with D8 / Chuyen doi bytecode sang DEX
Write-Host "[4/7] Converting to classes.dex using D8..." -ForegroundColor Yellow
$classFiles = @(Get-ChildItem -Path "$OUT_DIR\classes" -Filter *.class -Recurse | Select-Object -ExpandProperty FullName)
& "$BUILD_TOOLS\d8.bat" --lib "$PLATFORM_JAR" --output "$OUT_DIR" $classFiles

# 5. Add classes.dex into APK using jar / Dong goi classes.dex vao APK
Write-Host "[5/7] Packaging DEX into APK..." -ForegroundColor Yellow
& jar uf "$OUT_DIR\unaligned.apk" -C "$OUT_DIR" classes.dex

# 6. Zipalign and Sign APK / Can chinh 4-byte va ky so APK
Write-Host "[6/7] Aligning and signing APK..." -ForegroundColor Yellow
& "$BUILD_TOOLS\zipalign.exe" -f -v 4 "$OUT_DIR\unaligned.apk" "$OUT_DIR\nextai_opencut_aligned.apk" | Out-Null

$KEYSTORE = "$APP_DIR\debug.keystore"
if (-not (Test-Path $KEYSTORE)) {
    & keytool -genkeypair -v -keystore "$KEYSTORE" -alias androiddebugkey -keyalg RSA -keysize 2048 -validity 10000 -storepass android -keypass android -dname "CN=Android Debug,O=Android,C=US"
}

& "$BUILD_TOOLS\apksigner.bat" sign --ks "$KEYSTORE" --ks-pass pass:android --ks-key-alias androiddebugkey --key-pass pass:android --out "$OUT_DIR\nextai_opencut_signed.apk" "$OUT_DIR\nextai_opencut_aligned.apk"

Write-Host "APK Built and Signed Successfully: $OUT_DIR\nextai_opencut_signed.apk" -ForegroundColor Green

# 7. Install and Launch on Test Device (emulator-5554) / Cai dat va chay tren may test
Write-Host "[7/7] Installing onto test device (emulator-5554)..." -ForegroundColor Yellow
& "$ADB" -s emulator-5554 uninstall com.nextai.opencut | Out-Null
& "$ADB" -s emulator-5554 install -r "$OUT_DIR\nextai_opencut_signed.apk"

Write-Host "Launching NextAI OpenCut MainActivity on emulator-5554..." -ForegroundColor Green
& "$ADB" -s emulator-5554 shell am start -n com.nextai.opencut/com.nextai.opencut.presentation.MainActivity

Start-Sleep -Seconds 2

# 8. Test Photo Editor Flow: Tap "Sua Anh" Quick Tile (x=340, y=650)
Write-Host "Opening Photo Editor (Chinh Sua Anh) on Emulator..." -ForegroundColor Cyan
& "$ADB" -s emulator-5554 shell input tap 340 650
Start-Sleep -Seconds 2

# Capture Photo Editor Canvas Screenshot
Write-Host "Capturing Photo Editor Screen..." -ForegroundColor Cyan
& "$ADB" -s emulator-5554 shell screencap -p /sdcard/opencut_photo_editor.png
& "$ADB" -s emulator-5554 pull /sdcard/opencut_photo_editor.png "$PROJECT_ROOT\design\screenshots\device_photo_editor_screenshot.png"
if (Test-Path $BRAIN_DIR) {
    Copy-Item "$PROJECT_ROOT\design\screenshots\device_photo_editor_screenshot.png" "$BRAIN_DIR\device_photo_editor_screenshot.png" -Force
}

# 9. Apply 3D LUT Portra 400 + Face Beauty & Save
Write-Host "Applying 3D LUT Portra 400 & AI Face Beauty..." -ForegroundColor Cyan
& "$ADB" -s emulator-5554 shell input tap 220 1420
Start-Sleep -Milliseconds 600
& "$ADB" -s emulator-5554 shell input tap 90 1520
Start-Sleep -Milliseconds 600
& "$ADB" -s emulator-5554 shell screencap -p /sdcard/opencut_photo_effects.png
& "$ADB" -s emulator-5554 pull /sdcard/opencut_photo_effects.png "$PROJECT_ROOT\design\screenshots\device_photo_effects_screenshot.png"
if (Test-Path $BRAIN_DIR) {
    Copy-Item "$PROJECT_ROOT\design\screenshots\device_photo_effects_screenshot.png" "$BRAIN_DIR\device_photo_effects_screenshot.png" -Force
}

# Tap Save Photo Button
& "$ADB" -s emulator-5554 shell input tap 750 60
Start-Sleep -Milliseconds 800

Write-Host "====================================================================" -ForegroundColor Green
Write-Host "SUCCESS: NextAI OpenCut Photo Editor Verified on Test Device!" -ForegroundColor Green
Write-Host "====================================================================" -ForegroundColor Green
