$SDK_DIR = "$env:LOCALAPPDATA\Android\Sdk"
$BUILD_TOOLS = "$SDK_DIR\build-tools\34.0.0"
$PLATFORM_JAR = "$SDK_DIR\platforms\android-34\android.jar"
$APP_DIR = "D:\Decompiler\App\Video\Capcut\apps\android\app"
$OUT_DIR = "$APP_DIR\build\manual_build"

$javaSources = @(Get-ChildItem -Path "$APP_DIR\src\main\java", "$OUT_DIR\gen" -Filter *.java -Recurse | Select-Object -ExpandProperty FullName)
& javac --release 8 -g -cp "$PLATFORM_JAR" -d "$OUT_DIR\classes" $javaSources
if ($LASTEXITCODE -ne 0) {
    Write-Error "javac compilation failed"
    exit 1
}

Write-Host "Creating classes.jar..."
& jar cf "$OUT_DIR\classes.jar" -C "$OUT_DIR\classes" .

Write-Host "Running D8..."
& "$BUILD_TOOLS\d8.bat" --lib "$PLATFORM_JAR" --output "$OUT_DIR" "$OUT_DIR\classes.jar"
if ($LASTEXITCODE -eq 0) {
    Write-Host "D8 COMPLETED SUCCESSFULLY!" -ForegroundColor Green
} else {
    Write-Error "D8 failed"
}
