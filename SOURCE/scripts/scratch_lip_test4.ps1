Add-Type -AssemblyName System.Drawing
$bmp = [System.Drawing.Bitmap]::FromFile('d:/Decompiler/App/Video/Capcut/design/screenshots/parity100/user_test_upright.jpg')
$w = $bmp.Width
$h = $bmp.Height

$midEyesX = 769.5
$midEyesY = 1475.5
$eyesDist = 429.7

$searchTop = [int]($midEyesY + $eyesDist * 0.95)
$searchBottom = [int]($midEyesY + $eyesDist * 1.35)
$searchLeft = [int]($midEyesX - $eyesDist * 0.35)
$searchRight = [int]($midEyesX + $eyesDist * 0.35)

$sumX = 0.0
$sumY = 0.0
$sumWeight = 0.0
$minX = $w; $maxX = 0; $minY = $h; $maxY = 0

$step = 2
$maxDx = $eyesDist * 0.35

for ($y = $searchTop; $y -le $searchBottom; $y += $step) {
    for ($x = $searchLeft; $x -le $searchRight; $x += $step) {
        $p = $bmp.GetPixel($x, $y)
        $r = [double]$p.R
        $g = [double]$p.G
        $b = [double]$p.B
        $lum = ($r + $g + $b) / 3.0
        $redRatio = ($r - $g) / [Math]::Max(1.0, $lum)

        if ($redRatio -gt 0.48 -and $lum -lt 150.0 -and $r -gt 130) {
            $dx = ($x - $midEyesX) / $maxDx
            $symmetryFactor = [Math]::Max(0.2, 1.0 - ($dx * $dx))
            $weight = ($redRatio - 0.45) * (155.0 - $lum) * $symmetryFactor
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
    Write-Host "Detected Lips Center with High Precision: X=$cx, Y=$cy (Y% = $pctY %)"
    $wBox = $maxX - $minX
    $hBox = $maxY - $minY
    Write-Host "Lip Bounding Box: X=[$minX, $maxX] (W=$wBox), Y=[$minY, $maxY] (H=$hBox)"
} else {
    Write-Host 'No lips detected!'
}
$bmp.Dispose()
