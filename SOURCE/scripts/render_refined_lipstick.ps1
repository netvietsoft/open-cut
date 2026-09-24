Add-Type -AssemblyName System.Drawing
$src = [System.Drawing.Bitmap]::FromFile('d:/Decompiler/App/Video/Capcut/design/screenshots/parity100/user_test_upright.jpg')
$w = $src.Width
$h = $src.Height

# Face Landmark coordinates (simulating FaceBodyDetectionEngine with refined high-precision)
$midEyesX = 769.5
$midEyesY = 1475.5
$eyesDist = 429.7

# Search ROI
$searchTop = [int]($midEyesY + $eyesDist * 0.95)
$searchBottom = [int]($midEyesY + $eyesDist * 1.35)
$searchLeft = [int]($midEyesX - $eyesDist * 0.35)
$searchRight = [int]($midEyesX + $eyesDist * 0.35)

$sumX = 0.0; $sumY = 0.0; $sumWeight = 0.0
$minX = $w; $maxX = 0; $minY = $h; $maxY = 0

$step = 2
$maxDx = $eyesDist * 0.35

for ($y = $searchTop; $y -le $searchBottom; $y += $step) {
    for ($x = $searchLeft; $x -le $searchRight; $x += $step) {
        $p = $src.GetPixel($x, $y)
        $r = [double]$p.R; $g = [double]$p.G; $b = [double]$p.B
        $lum = ($r + $g + $b) / 3.0
        $redRatio = ($r - $g) / [Math]::Max(1.0, $lum)

        if ($redRatio -gt 0.46 -and $lum -lt 160.0 -and $r -gt 125) {
            $dx = ($x - $midEyesX) / $maxDx
            $symFactor = [Math]::Max(0.2, 1.0 - ($dx * $dx))
            $weight = ($redRatio - 0.40) * (165.0 - $lum) * $symFactor
            $sumX += $x * $weight
            $sumY += $y * $weight
            $sumWeight += $weight
            if ($x -lt $minX) { $minX = $x }
            if ($x -gt $maxX) { $maxX = $x }
            if ($y -lt $minY) { $minY = $y }
            if ($y -gt $maxY) { $maxY = $y }
        }
    }
}

$cx = [int]($sumX / $sumWeight)
$cy = [int]($sumY / $sumWeight)

$maxRx = [int]($eyesDist * 0.31)
$minRx = [int]($eyesDist * 0.22)
$maxRy = [int]($eyesDist * 0.12)
$minRy = [int]($eyesDist * 0.08)

$rx = [Math]::Min($maxRx, [Math]::Max($minRx, [int](($maxX - $minX) * 0.45)))
$ry = [Math]::Min($maxRy, [Math]::Max($minRy, [int](($maxY - $minY) * 0.35)))

Write-Host "Calculated Lip Center: CX=$cx, CY=$cy, RX=$rx, RY=$ry"

# Create output bitmap
$dst = New-Object System.Drawing.Bitmap($w, $h, [System.Drawing.Imaging.PixelFormat]::Format32bppArgb)
$g = [System.Drawing.Graphics]::FromImage($dst)
$g.DrawImage($src, 0, 0, $w, $h)
$g.Dispose()

# Rosy Red (#DE3163)
$lipR = 222
$lipG = 49
$lipB = 99
$blendOpacity = 0.58
$rxSq = [double]($rx * $rx)

$minBoxX = [Math]::Max(0, $cx - $rx - 5)
$maxBoxX = [Math]::Min($w - 1, $cx + $rx + 5)
$minBoxY = [Math]::Max(0, $cy - $ry - 5)
$maxBoxY = [Math]::Min($h - 1, $cy + $ry + 5)

for ($y = $minBoxY; $y -le $maxBoxY; $y++) {
    $dy = $y - $cy
    $effRy = [double]$ry
    if ($dy -lt 0) {
        # Upper lip cupid dip
        $effRy = $ry * 0.90
    } else {
        # Lower lip slightly fuller
        $effRy = $ry * 1.05
    }
    $rySq = $effRy * $effRy

    for ($x = $minBoxX; $x -le $maxBoxX; $x++) {
        $dx = $x - $cx
        $distNorm = ($dx * $dx) / $rxSq + ($dy * $dy) / $rySq
        if ($distNorm -le 1.0) {
            $falloff = [Math]::Pow(1.0 - $distNorm, 1.4)
            $strength = $falloff * $blendOpacity

            $orig = $src.GetPixel($x, $y)
            $origR = [double]$orig.R
            $origG = [double]$orig.G
            $origB = [double]$orig.B

            # Natural Rosy Red Tint: Enhances red, balances green/blue, preserves lip creases & specular shine
            $targetR = [Math]::Min(255.0, $origR * 1.25 + ($lipR * 0.25))
            $targetG = [Math]::Max(0.0, $origG * 0.78 + ($lipG * 0.16))
            $targetB = [Math]::Max(0.0, $origB * 0.82 + ($lipB * 0.18))

            $newR = [int]($origR * (1.0 - $strength) + $targetR * $strength)
            $newG = [int]($origG * (1.0 - $strength) + $targetG * $strength)
            $newB = [int]($origB * (1.0 - $strength) + $targetB * $strength)

            $newColor = [System.Drawing.Color]::FromArgb(255, $newR, $newG, $newB)
            $dst.SetPixel($x, $y, $newColor)
        }
    }
}

$outPath = 'd:/Decompiler/App/Video/Capcut/design/screenshots/parity100/test_lipstick_refined.jpg'
$dst.Save($outPath, [System.Drawing.Imaging.ImageFormat]::Jpeg)
$src.Dispose()
$dst.Dispose()

Write-Host "Refined Lipstick Image Saved to: $outPath"
