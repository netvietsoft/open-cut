# Script to copy and unpack authentic CapCut resource effects into OpenCut Android app
Set-Location $PSScriptRoot\..

$SRC_ASSETS = "extracted\assets"
$SRC_RAW = "apktool-res\res\raw"
$DEST_ASSETS = "apps\android\app\src\main\assets\capcut"
$DEST_RAW = "apps\android\app\src\main\res\raw"

Add-Type -AssemblyName System.IO.Compression.FileSystem

Write-Host "1. Copying GLSL Shaders from CapCut raw resources..."
Copy-Item "$SRC_RAW\spin_frag.glsl" "$DEST_ASSETS\shaders\" -Force
Copy-Item "$SRC_RAW\spin_vert.glsl" "$DEST_ASSETS\shaders\" -Force
Copy-Item "$SRC_RAW\hexagon_frag.glsl" "$DEST_ASSETS\shaders\" -Force
Copy-Item "$SRC_RAW\hexagon_vert.glsl" "$DEST_ASSETS\shaders\" -Force
Copy-Item "$SRC_RAW\hexagon_zoom_frag.glsl" "$DEST_ASSETS\shaders\" -Force

Copy-Item "$SRC_RAW\spin_frag.glsl" "$DEST_RAW\" -Force
Copy-Item "$SRC_RAW\spin_vert.glsl" "$DEST_RAW\" -Force
Copy-Item "$SRC_RAW\hexagon_frag.glsl" "$DEST_RAW\" -Force
Copy-Item "$SRC_RAW\hexagon_vert.glsl" "$DEST_RAW\" -Force
Copy-Item "$SRC_RAW\hexagon_zoom_frag.glsl" "$DEST_RAW\" -Force

Write-Host "2. Extracting Chroma Key Shaders from Chroma_V1370.zip..."
$chromaZip = [System.IO.Compression.ZipFile]::OpenRead("$SRC_ASSETS\zip\Chroma_V1370.zip")
foreach ($entry in $chromaZip.Entries) {
    if ($entry.FullName -match "chromakey\.frag$") {
        [System.IO.Compression.ZipFileExtensions]::ExtractToFile($entry, "$DEST_ASSETS\shaders\chromakey.frag", $true)
    } elseif ($entry.FullName -match "chromakey\.vert$") {
        [System.IO.Compression.ZipFileExtensions]::ExtractToFile($entry, "$DEST_ASSETS\shaders\chromakey.vert", $true)
    } elseif ($entry.FullName -match "smoothx\.frag$") {
        [System.IO.Compression.ZipFileExtensions]::ExtractToFile($entry, "$DEST_ASSETS\shaders\smoothx.frag", $true)
    } elseif ($entry.FullName -match "smoothy\.frag$") {
        [System.IO.Compression.ZipFileExtensions]::ExtractToFile($entry, "$DEST_ASSETS\shaders\smoothy.frag", $true)
    }
}
$chromaZip.Dispose()

Write-Host "3. Extracting Beauty Shaders from beauty.zip..."
$beautyZip = [System.IO.Compression.ZipFile]::OpenRead("$SRC_RAW\beauty.zip")
foreach ($entry in $beautyZip.Entries) {
    if ($entry.FullName -match "boxblur/Beauty\.frag$") {
        [System.IO.Compression.ZipFileExtensions]::ExtractToFile($entry, "$DEST_ASSETS\shaders\beauty_smooth.frag", $true)
    } elseif ($entry.FullName -match "boxblur/Beauty\.vert$") {
        [System.IO.Compression.ZipFileExtensions]::ExtractToFile($entry, "$DEST_ASSETS\shaders\beauty_smooth.vert", $true)
    }
}
$beautyZip.Dispose()

Write-Host "4. Extracting Effect Packages (FaceReshape, Curves, HSL, Matting, Particles)..."
$effectZips = @("FaceReshape_V2", "FaceReshape_V3", "curves", "hsl_v1", "vignetting", "particle", "mattingBlend", "aigc_text_template")
foreach ($ez in $effectZips) {
    $zipPath = "$SRC_ASSETS\zip\$ez.zip"
    $targetDir = "$DEST_ASSETS\effects\$ez"
    if (Test-Path $zipPath) {
        Remove-Item -Recurse -Force -ErrorAction SilentlyContinue $targetDir
        New-Item -ItemType Directory -Force -Path $targetDir | Out-Null
        [System.IO.Compression.ZipFile]::ExtractToDirectory($zipPath, $targetDir)
        Write-Host "   Extracted: $ez"
    }
}

Write-Host "5. Copying Lottie JSON files..."
Copy-Item "$SRC_RAW\cut_same_music.json" "$DEST_ASSETS\lottie\" -Force
Copy-Item "$SRC_RAW\koutu.json" "$DEST_ASSETS\lottie\" -Force
Copy-Item "$SRC_RAW\line_loading_lottie.json" "$DEST_ASSETS\lottie\" -Force
if (Test-Path "$SRC_ASSETS\star_shining\star_shining.json") {
    Copy-Item "$SRC_ASSETS\star_shining\star_shining.json" "$DEST_ASSETS\lottie\" -Force
}
Copy-Item "$SRC_RAW\cut_same_music.json" "$DEST_RAW\" -Force
Copy-Item "$SRC_RAW\koutu.json" "$DEST_RAW\" -Force

Write-Host "6. Copying Audio Files..."
Copy-Item "$SRC_RAW\credit_adding.mp3" "$DEST_ASSETS\audio\" -Force
Copy-Item "$SRC_RAW\silence_audio_placeholder.wav" "$DEST_ASSETS\audio\" -Force
Copy-Item "$SRC_RAW\credit_adding.mp3" "$DEST_RAW\" -Force

Write-Host "7. Copying Textures & Images..."
if (Test-Path "$SRC_ASSETS\text_anim_images") {
    Copy-Item "$SRC_ASSETS\text_anim_images\*.png" "$DEST_ASSETS\textures\" -Force
}
if (Test-Path "$SRC_ASSETS\star_shining\images") {
    New-Item -ItemType Directory -Force -Path "$DEST_ASSETS\textures\star_shining" | Out-Null
    Copy-Item "$SRC_ASSETS\star_shining\images\*" "$DEST_ASSETS\textures\star_shining\" -Force
}

Write-Host "=== CAPCUT ASSETS PREPARATION COMPLETE ==="
Get-ChildItem -Recurse $DEST_ASSETS | Measure-Object | Select-Object -ExpandProperty Count | ForEach-Object { Write-Host "Total CapCut Asset Files bundled: $_" }
