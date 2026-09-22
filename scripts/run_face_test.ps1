$adb = Join-Path $env:LOCALAPPDATA "Android\Sdk\platform-tools\adb.exe"
$buildTools = Join-Path $env:LOCALAPPDATA "Android\Sdk\build-tools\34.0.0"
$androidJar = Join-Path $env:LOCALAPPDATA "Android\Sdk\platforms\android-34\android.jar"
$d8 = Join-Path $buildTools "d8.bat"

# Compile TestFaceDetect.java
$outDir = "build_test"
if (Test-Path $outDir) { Remove-Item -Recurse -Force $outDir }
New-Item -ItemType Directory -Path $outDir | Out-Null

javac --release 8 -cp $androidJar -d $outDir apps\android\app\src\main\java\com\nextai\opencut\engine\FaceBodyDetectionEngine.java apps\android\app\src\main\java\com\nextai\opencut\test\TestFaceDetect.java
if ($LASTEXITCODE -ne 0) {
    Write-Host "javac failed!"
    exit 1
}

# Run D8 to generate classes.dex
& $d8 --output $outDir (Get-ChildItem -Recurse $outDir\*.class).FullName
if ($LASTEXITCODE -ne 0) {
    Write-Host "d8 failed!"
    exit 1
}

# Push classes.dex to /data/local/tmp/
& $adb -s 192.168.1.3:36903 push "$outDir\classes.dex" /data/local/tmp/test_faces.dex

# Execute via app_process
Write-Host "--- RUNNING APP_PROCESS ON SAMSUNG A50S ---"
& $adb -s 192.168.1.3:36903 shell "CLASSPATH=/data/local/tmp/test_faces.dex app_process /data/local/tmp com.nextai.opencut.test.TestFaceDetect /sdcard/DCIM/Facebook/FB_IMG_1789812444308.jpg"
