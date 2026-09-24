Add-Type -AssemblyName System.Drawing
$bmp = [System.Drawing.Bitmap]::FromFile('d:/Decompiler/App/Video/Capcut/design/screenshots/parity100/user_test_upright.jpg')
$w = $bmp.Width
$h = $bmp.Height

$midEyesX = 769.5
$midEyesY = 1475.5
$eyesDist = 429.7

$searchTop = [int]($midEyesY + $eyesDist * 0.95)
$searchBottom = [int]($midEyesY + $eyesDist * 1.45)
$searchLeft = [int]($midEyesX - $eyesDist * 0.38)
$searchRight = [int]($midEyesX + $eyesDist * 0.38)

$sumX = 0.0
$sumY = 0.0
$sumWeight = 0.0
$minX = $w; $maxX = 0; $minY = $h; $maxY = 0

$step = [Math]::Max(2, [int]($w / 400))
$maxDx = $eyesDist * 0.38

for ($y = $searchTop; $y -le $searchBottom; $y += $step) {
    for ($x = $searchLeft; $x -le $searchRight; $x += $step) {
        $p = $bmp.GetPixel($x, $y)
        $r = [double]$p.R
        $g = [double]$p.G
        $b = [double]$p.B
        $lum = ($r + $g + $b) / 3.0
        $redRatio = ($r - $g) / [Math]::Max(1.0, $lum)

        if ($redRatio -gt 0.38 -and $lum -lt 165.0 -and $r -gt 125) {
            # Facial symmetry prior: Lip pixels are strongest near the facial midline
            $dx = ($x - $midEyesX) / $maxDx
            $symmetryFactor = [Math]::Max(0.25, 1.0 - ($dx * $dx))
            $weight = ($redRatio - 0.35) * (170.0 - $lum) * $symmetryFactor
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

if ($sumWeight -gt 0) {
    $cx = [Math]::Round($sumX / $sumWeight, 1)
    $cy = [Math]::Round($sumY / $sumWeight, 1)
    $pctY = [Math]::Round(($cy / $h) * 100.0, 2)
    Write-Host "Detected Lips Center with Symmetry: X=$cx, Y=$cy (Y% = $pctY %)"
} else {
    Write-Host 'No lips detected!'
}
$bmp.Dispose()
