# UTF-8 script to strip photo editor code from MainActivity.java cleanly
$filePath = "apps/android/app/src/main/java/com/nextai/opencut/presentation/MainActivity.java"
$content = [System.IO.File]::ReadAllText($filePath, [System.Text.Encoding]::UTF8)

# 1. Block 1: buildPhotoEditorView to updateVideoCanvasDimensions
$block1StartStr = "    /**`r`n     * Build Photo Editor View with Real Bitmap Engine & 3D LUT Filters"
if (-not $content.Contains($block1StartStr)) {
    $block1StartStr = "    /**`n     * Build Photo Editor View with Real Bitmap Engine & 3D LUT Filters"
}
$block1EndStr = "    /**`r`n     * Dynamically update Video Canvas dimensions to maximize screen workspace"
if (-not $content.Contains($block1EndStr)) {
    $block1EndStr = "    /**`n     * Dynamically update Video Canvas dimensions to maximize screen workspace"
}

$idx1Start = $content.IndexOf($block1StartStr)
$idx1End = $content.IndexOf($block1EndStr)

if ($idx1Start -ge 0 -and $idx1End -gt $idx1Start) {
    Write-Host "Found Block 1: $idx1Start to $idx1End"
    $content = $content.Substring(0, $idx1Start) + $content.Substring($idx1End)
} else {
    Write-Error "Could not find Block 1!"
    exit 1
}

# 2. Block 2: rotatePhoto90Degrees to rotateVideo90Degrees
$block2StartStr = "    /**`r`n     * Rotate Photo by 90 degrees clockwise"
if (-not $content.Contains($block2StartStr)) {
    $block2StartStr = "    /**`n     * Rotate Photo by 90 degrees clockwise"
}
$block2EndStr = "    /**`r`n     * Rotate Video Canvas by 90 degrees clockwise"
if (-not $content.Contains($block2EndStr)) {
    $block2EndStr = "    /**`n     * Rotate Video Canvas by 90 degrees clockwise"
}

$idx2Start = $content.IndexOf($block2StartStr)
$idx2End = $content.IndexOf($block2EndStr)

if ($idx2Start -ge 0 -and $idx2End -gt $idx2Start) {
    Write-Host "Found Block 2: $idx2Start to $idx2End"
    $content = $content.Substring(0, $idx2Start) + $content.Substring($idx2End)
} else {
    Write-Error "Could not find Block 2!"
    exit 1
}

# 3. Block 3: CropSeekBarListener to showVideoCropDialog
$block3StartStr = "    private static class CropSeekBarListener implements SeekBar.OnSeekBarChangeListener {"
$block3EndStr = "    /**`r`n     * Show Video Aspect Ratio & Fit/Fill Dialog"
if (-not $content.Contains($block3EndStr)) {
    $block3EndStr = "    /**`n     * Show Video Aspect Ratio & Fit/Fill Dialog"
}

$idx3Start = $content.IndexOf($block3StartStr)
$idx3End = $content.IndexOf($block3EndStr)

if ($idx3Start -ge 0 -and $idx3End -gt $idx3Start) {
    Write-Host "Found Block 3: $idx3Start to $idx3End"
    $content = $content.Substring(0, $idx3Start) + $content.Substring($idx3End)
} else {
    Write-Error "Could not find Block 3!"
    exit 1
}

# 4. Block 4: openPhotoEditorWithMedia to buildTemplateView
$block4StartStr = "    private void openPhotoEditorWithMedia(MediaItem photoItem) {"
$block4EndStr = "    /**`r`n     * Build Template View"
if (-not $content.Contains($block4EndStr)) {
    $block4EndStr = "    /**`n     * Build Template View"
}

$idx4Start = $content.IndexOf($block4StartStr)
$idx4End = $content.IndexOf($block4EndStr)

$replacementPhotoOpen = @"
    private void openPhotoEditorWithMedia(MediaItem photoItem) {
        rootFrame.removeAllViews();
        if (photoEditorComponent == null) {
            photoEditorComponent = new PhotoEditorComponent(this, this);
        }
        photoEditorComponent.open(photoItem);
        rootFrame.addView(photoEditorComponent.getView());
    }

"@

if ($idx4Start -ge 0 -and $idx4End -gt $idx4Start) {
    Write-Host "Found Block 4: $idx4Start to $idx4End"
    $content = $content.Substring(0, $idx4Start) + $replacementPhotoOpen + $content.Substring($idx4End)
} else {
    Write-Error "Could not find Block 4!"
    exit 1
}

# 5. Block 5: onClick photo handlers
$block5StartStr = "        } else if (v == btnPhotoRotate || v == photoNavRotate) {"
$block5EndStr = "        } else if (v == btnEditorResolution) {"

$idx5Start = $content.IndexOf($block5StartStr)
$idx5End = $content.IndexOf($block5EndStr)

if ($idx5Start -ge 0 -and $idx5End -gt $idx5Start) {
    Write-Host "Found Block 5: $idx5Start to $idx5End"
    $content = $content.Substring(0, $idx5Start) + $content.Substring($idx5End)
} else {
    Write-Error "Could not find Block 5!"
    exit 1
}

[System.IO.File]::WriteAllText($filePath, $content, [System.Text.Encoding]::UTF8)
Write-Host "Successfully stripped Photo Editor from MainActivity.java!"
