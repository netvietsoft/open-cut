# Run Unit Tests Script for NextAI OpenCut Android
Set-Location $PSScriptRoot

$TEST_BUILD_DIR = "build\test_classes"
Remove-Item -Recurse -Force -ErrorAction SilentlyContinue $TEST_BUILD_DIR
New-Item -ItemType Directory -Force -Path $TEST_BUILD_DIR | Out-Null

$JAVAC = "C:\Program Files\Eclipse Adoptium\jdk-21.0.12.101-hotspot\bin\javac.exe"
$JAVA = "C:\Program Files\Eclipse Adoptium\jdk-21.0.12.101-hotspot\bin\java.exe"
$ANDROID_JAR = "C:\Users\boluc\AppData\Local\Android\Sdk\platforms\android-34\android.jar"

Write-Host "1. Compiling Source & Test Classes..."
$sources = @(
    "src\main\java\com\nextai\opencut\engine\EffectRegistry.java",
    "src\main\java\com\nextai\opencut\presentation\model\MediaItem.java",
    "src\main\java\com\nextai\opencut\presentation\model\KeyframePoint.java",
    "src\test\java\com\nextai\opencut\ContrastFormulaTest.java",
    "src\test\java\com\nextai\opencut\EffectRegistryTest.java",
    "src\test\java\com\nextai\opencut\MediaItemTest.java",
    "src\test\java\com\nextai\opencut\TestRunner.java"
)

$srcListFile = "$TEST_BUILD_DIR\test_sources.txt"
[System.IO.File]::WriteAllLines((Resolve-Path "$TEST_BUILD_DIR").Path + "\test_sources.txt", $sources)

& $JAVAC -encoding UTF-8 -cp "$ANDROID_JAR;$TEST_BUILD_DIR" -d $TEST_BUILD_DIR "@$srcListFile"
if ($LASTEXITCODE -ne 0) { throw "Test compilation failed!" }

Write-Host "2. Executing Test Runner..."
& $JAVA -cp "$TEST_BUILD_DIR;$ANDROID_JAR" com.nextai.opencut.TestRunner
if ($LASTEXITCODE -ne 0) { throw "One or more test suites failed!" }

Write-Host "=== UNIT TESTS COMPLETED SUCCESSFULLY ==="
