param (
    [string]$TargetDevice = "192.168.1.3:36903"
)

$SDK_DIR = "$env:LOCALAPPDATA\Android\Sdk"
$BUILD_TOOLS = "$SDK_DIR\build-tools\34.0.0"
$PLATFORM_JAR = "$SDK_DIR\platforms\android-34\android.jar"
$ADB = "$SDK_DIR\platform-tools\adb.exe"

$PROJECT_ROOT = "D:\Decompiler\App\Video\Capcut"
$APP_DIR = "$PROJECT_ROOT\CONVERT\apps\android\app"
$OUT_DIR = "$APP_DIR\build\manual_build"

Write-Host "====================================================================" -ForegroundColor Cyan
Write-Host "NextAI OpenCut APK Build & Deploy -> Target: $TargetDevice" -ForegroundColor Green
Write-Host "====================================================================" -ForegroundColor Cyan

# 1. Clean and Prepare
if (Test-Path $OUT_DIR) { Remove-Item -Recurse -Force $OUT_DIR }
New-Item -ItemType Directory -Force -Path "$OUT_DIR\res_compiled" | Out-Null
New-Item -ItemType Directory -Force -Path "$OUT_DIR\gen" | Out-Null
New-Item -ItemType Directory -Force -Path "$OUT_DIR\classes" | Out-Null
New-Item -ItemType Directory -Force -Path "$PROJECT_ROOT\design\screenshots\parity100" | Out-Null

# 2. Compile Android Resources
Write-Host "[1/7] Compiling XML resources with AAPT2..." -ForegroundColor Yellow
& "$BUILD_TOOLS\aapt2.exe" compile --dir "$APP_DIR\src\main\res" -o "$OUT_DIR\res_compiled.zip"
if ($LASTEXITCODE -ne 0) {
    Write-Error "AAPT2 compile failed"
    exit 1
}

# 3. Link Resources
Write-Host "[2/7] Linking resources..." -ForegroundColor Yellow
& "$BUILD_TOOLS\aapt2.exe" link -o "$OUT_DIR\unaligned.apk" `
    -I "$PLATFORM_JAR" `
    --manifest "$APP_DIR\src\main\AndroidManifest.xml" `
    --java "$OUT_DIR\gen" `
    --auto-add-overlay `
    "$OUT_DIR\res_compiled.zip"
if ($LASTEXITCODE -ne 0) {
    Write-Error "AAPT2 link failed"
    exit 1
}

# 4. Compile Java Code
Write-Host "[3/7] Compiling Java classes (Java 8 compatibility)..." -ForegroundColor Yellow
$javaSources = @(Get-ChildItem -Path "$APP_DIR\src\main\java", "$OUT_DIR\gen" -Filter *.java -Recurse | Select-Object -ExpandProperty FullName)
& javac --release 8 -g -cp "$PLATFORM_JAR" -d "$OUT_DIR\classes" $javaSources
if ($LASTEXITCODE -ne 0) {
    Write-Error "javac compilation failed"
    exit 1
}

# 5. D8 Dexing
Write-Host "[4/7] Converting to classes.dex using D8..." -ForegroundColor Yellow
& jar cf "$OUT_DIR\classes.jar" -C "$OUT_DIR\classes" .
if ($LASTEXITCODE -ne 0) {
    Write-Error "Creating classes.jar failed"
    exit 1
}
& "$BUILD_TOOLS\d8.bat" --lib "$PLATFORM_JAR" --output "$OUT_DIR" "$OUT_DIR\classes.jar"
if ($LASTEXITCODE -ne 0) {
    Write-Error "D8 failed"
    exit 1
}

# 6. Add Dex to APK
Write-Host "[5/7] Packaging DEX into APK..." -ForegroundColor Yellow
& jar uf "$OUT_DIR\unaligned.apk" -C "$OUT_DIR" classes.dex
if ($LASTEXITCODE -ne 0) {
    Write-Error "jar packaging failed"
    exit 1
}

# 7. Zipalign and Sign
Write-Host "[6/7] Aligning and signing APK..." -ForegroundColor Yellow
& "$BUILD_TOOLS\zipalign.exe" -f -v 4 "$OUT_DIR\unaligned.apk" "$OUT_DIR\nextai_opencut_aligned.apk" | Out-Null

$KEYSTORE = "$APP_DIR\debug.keystore"
if (-not (Test-Path $KEYSTORE)) {
    & keytool -genkeypair -v -keystore "$KEYSTORE" -alias androiddebugkey -keyalg RSA -keysize 2048 -validity 10000 -storepass android -keypass android -dname "CN=Android Debug,O=Android,C=US"
}

& "$BUILD_TOOLS\apksigner.bat" sign --ks "$KEYSTORE" --ks-pass pass:android --ks-key-alias androiddebugkey --key-pass pass:android --out "$OUT_DIR\nextai_opencut_signed.apk" "$OUT_DIR\nextai_opencut_aligned.apk"
if ($LASTEXITCODE -ne 0) {
    Write-Error "apksigner failed"
    exit 1
}

Write-Host "BUILD SUCCESS: $OUT_DIR\nextai_opencut_signed.apk" -ForegroundColor Green

# 8. Install & Launch
if ($TargetDevice) {
    Write-Host "[7/7] Installing onto $TargetDevice..." -ForegroundColor Yellow
    & "$ADB" -s $TargetDevice install -r "$OUT_DIR\nextai_opencut_signed.apk"
    if ($LASTEXITCODE -ne 0) {
        Write-Error "Install failed"
        exit 1
    }
    Write-Host "Launching NextAI OpenCut on $TargetDevice..." -ForegroundColor Green
    & "$ADB" -s $TargetDevice shell am start -n com.nextai.opencut/com.nextai.opencut.presentation.MainActivity
}
