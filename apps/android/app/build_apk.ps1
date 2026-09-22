# Build & Sign APK Script for NextAI OpenCut
Set-Location $PSScriptRoot

$BUILD_DIR = "build\manual_build"
Remove-Item -Recurse -Force -ErrorAction SilentlyContinue "$BUILD_DIR\classes"
Remove-Item -Recurse -Force -ErrorAction SilentlyContinue "$BUILD_DIR\compiled_res"
Remove-Item -Recurse -Force -ErrorAction SilentlyContinue "$BUILD_DIR\src"
New-Item -ItemType Directory -Force -Path "$BUILD_DIR\compiled_res" | Out-Null
New-Item -ItemType Directory -Force -Path "$BUILD_DIR\classes" | Out-Null
New-Item -ItemType Directory -Force -Path "$BUILD_DIR\src" | Out-Null

$AAPT2 = "C:\Users\boluc\AppData\Local\Android\Sdk\build-tools\34.0.0\aapt2.exe"
$D8 = "C:\Users\boluc\AppData\Local\Android\Sdk\build-tools\34.0.0\d8.bat"
$ZIPALIGN = "C:\Users\boluc\AppData\Local\Android\Sdk\build-tools\34.0.0\zipalign.exe"
$APKSIGNER = "C:\Users\boluc\AppData\Local\Android\Sdk\build-tools\34.0.0\apksigner.bat"
$ANDROID_JAR = "C:\Users\boluc\AppData\Local\Android\Sdk\platforms\android-34\android.jar"
$JAVAC = "C:\Program Files\Eclipse Adoptium\jdk-21.0.12.101-hotspot\bin\javac.exe"
$JAR = "C:\Program Files\Eclipse Adoptium\jdk-21.0.12.101-hotspot\bin\jar.exe"

Write-Host "1. Compiling Android Resources with AAPT2..."
& $AAPT2 compile --dir src\main\res -o "$BUILD_DIR\compiled_res\"
if ($LASTEXITCODE -ne 0) { throw "AAPT2 compile failed" }

Write-Host "2. Linking Resources and generating R.java..."
$flats = (Get-ChildItem "$BUILD_DIR\compiled_res\*.flat").FullName
& $AAPT2 link -I $ANDROID_JAR --manifest src\main\AndroidManifest.xml -A src\main\assets --java "$BUILD_DIR\src" -o "$BUILD_DIR\app-unaligned.apk" $flats --auto-add-overlay
if ($LASTEXITCODE -ne 0) { throw "AAPT2 link failed" }

Write-Host "3. Compiling Java Sources with javac..."
$javaSources = (Get-ChildItem -Recurse src\main\java\*.java).FullName + (Get-ChildItem -Recurse "$BUILD_DIR\src\*.java").FullName
& $JAVAC -cp $ANDROID_JAR -d "$BUILD_DIR\classes" --release 8 -g $javaSources
if ($LASTEXITCODE -ne 0) { throw "javac failed" }

Write-Host "4. Converting Class files to DEX with d8..."
& $JAR cf "$BUILD_DIR\app_classes.jar" -C "$BUILD_DIR\classes" .
if ($LASTEXITCODE -ne 0) { throw "jar creation failed" }
& $D8 --output "$BUILD_DIR\" --lib $ANDROID_JAR "$BUILD_DIR\app_classes.jar"
if ($LASTEXITCODE -ne 0) { throw "d8 failed" }

Write-Host "5. Adding DEX and Assets into APK with standard forward slash paths..."
Add-Type -AssemblyName System.IO.Compression
Add-Type -AssemblyName System.IO.Compression.FileSystem

$apkFullPath = (Resolve-Path "$BUILD_DIR\app-unaligned.apk").Path
$zipArchive = [System.IO.Compression.ZipFile]::Open($apkFullPath, [System.IO.Compression.ZipArchiveMode]::Update)

# Add or replace classes.dex
$oldDex = $zipArchive.GetEntry("classes.dex")
if ($oldDex) { $oldDex.Delete() }
[System.IO.Compression.ZipFileExtensions]::CreateEntryFromFile($zipArchive, (Resolve-Path "$BUILD_DIR\classes.dex").Path, "classes.dex") | Out-Null

# Add all assets with forward slashes
if (Test-Path "src\main\assets") {
    $baseAssetsPath = (Resolve-Path "src\main\assets").Path
    $assetFiles = Get-ChildItem -Recurse -File "src\main\assets"
    foreach ($file in $assetFiles) {
        $rel = $file.FullName.Substring($baseAssetsPath.Length + 1).Replace("\", "/")
        $entryName = "assets/$rel"
        $existing = $zipArchive.GetEntry($entryName)
        if ($existing) { $existing.Delete() }
        [System.IO.Compression.ZipFileExtensions]::CreateEntryFromFile($zipArchive, $file.FullName, $entryName) | Out-Null
    }
}
$zipArchive.Dispose()

Write-Host "6. ZipAligning APK..."
Remove-Item -Force -ErrorAction SilentlyContinue "$BUILD_DIR\app-aligned.apk"
& $ZIPALIGN -f -p 4 "$BUILD_DIR\app-unaligned.apk" "$BUILD_DIR\app-aligned.apk"
if ($LASTEXITCODE -ne 0) { throw "zipalign failed" }

Write-Host "7. Signing APK with apksigner..."
Remove-Item -Force -ErrorAction SilentlyContinue "$BUILD_DIR\nextai_opencut_signed.apk"
& $APKSIGNER sign --ks debug.keystore --ks-pass pass:android --ks-key-alias androiddebugkey --key-pass pass:android --out "$BUILD_DIR\nextai_opencut_signed.apk" "$BUILD_DIR\app-aligned.apk"
if ($LASTEXITCODE -ne 0) { throw "apksigner failed" }

Write-Host "=== BUILD SUCCESSFUL: $BUILD_DIR\nextai_opencut_signed.apk ==="
