# scripts/build_apk_only.ps1
# Dedicated Android APK Builder for NextAI OpenCut

$SDK_DIR = "$env:LOCALAPPDATA\Android\Sdk"
$BUILD_TOOLS = "$SDK_DIR\build-tools\34.0.0"
$PLATFORM_JAR = "$SDK_DIR\platforms\android-34\android.jar"

$PROJECT_ROOT = "D:\Decompiler\App\Video\Capcut"
$APP_DIR = "$PROJECT_ROOT\apps\android\app"
$OUT_DIR = "$APP_DIR\build\manual_build"

Write-Host ">>> [1/6] Cleaning and preparing build folders..." -ForegroundColor Cyan
if (Test-Path $OUT_DIR) { Remove-Item -Recurse -Force $OUT_DIR }
New-Item -ItemType Directory -Force -Path "$OUT_DIR\res_compiled" | Out-Null
New-Item -ItemType Directory -Force -Path "$OUT_DIR\gen" | Out-Null
New-Item -ItemType Directory -Force -Path "$OUT_DIR\classes" | Out-Null

Write-Host ">>> [2/6] Compiling XML resources with AAPT2..." -ForegroundColor Cyan
& "$BUILD_TOOLS\aapt2.exe" compile --dir "$APP_DIR\src\main\res" -o "$OUT_DIR\res_compiled.zip"

Write-Host ">>> [3/6] Linking resources..." -ForegroundColor Cyan
& "$BUILD_TOOLS\aapt2.exe" link -o "$OUT_DIR\unaligned.apk" `
    -I "$PLATFORM_JAR" `
    --manifest "$APP_DIR\src\main\AndroidManifest.xml" `
    --java "$OUT_DIR\gen" `
    --auto-add-overlay `
    "$OUT_DIR\res_compiled.zip"

Write-Host ">>> [4/6] Compiling Java classes..." -ForegroundColor Cyan
$javaSources = @(Get-ChildItem -Path "$APP_DIR\src\main\java", "$OUT_DIR\gen" -Filter *.java -Recurse | Select-Object -ExpandProperty FullName)
& javac --release 8 -g:none -cp "$PLATFORM_JAR" -d "$OUT_DIR\classes" $javaSources

Write-Host ">>> [5/6] Converting classes to DEX with D8..." -ForegroundColor Cyan
& jar cf "$OUT_DIR\app_classes.jar" -C "$OUT_DIR\classes" .
& "$BUILD_TOOLS\d8.bat" --lib "$PLATFORM_JAR" --output "$OUT_DIR" "$OUT_DIR\app_classes.jar"

Write-Host ">>> [6/6] Packaging and signing APK..." -ForegroundColor Cyan
& jar uf "$OUT_DIR\unaligned.apk" -C "$OUT_DIR" classes.dex
& "$BUILD_TOOLS\zipalign.exe" -f -v 4 "$OUT_DIR\unaligned.apk" "$OUT_DIR\nextai_opencut_aligned.apk" | Out-Null

$KEYSTORE = "$APP_DIR\debug.keystore"
if (-not (Test-Path $KEYSTORE)) {
    & keytool -genkeypair -v -keystore "$KEYSTORE" -alias androiddebugkey -keyalg RSA -keysize 2048 -validity 10000 -storepass android -keypass android -dname "CN=Android Debug,O=Android,C=US"
}

& "$BUILD_TOOLS\apksigner.bat" sign --ks "$KEYSTORE" --ks-pass pass:android --ks-key-alias androiddebugkey --key-pass pass:android --out "$OUT_DIR\nextai_opencut_signed.apk" "$OUT_DIR\nextai_opencut_aligned.apk"

Write-Host ">>> APK BUILD COMPLETED SUCCESSFULLY: $OUT_DIR\nextai_opencut_signed.apk" -ForegroundColor Green
