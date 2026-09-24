Add-Type -AssemblyName System.Drawing
$bmp = [System.Drawing.Bitmap]::FromFile('d:/Decompiler/App/Video/Capcut/design/screenshots/parity100/user_test_upright.jpg')
$w = $bmp.Width
$h = $bmp.Height

$midEyesX = $w * 0.50
$midEyesY = $h * 0.44
$eyesDist = $w * 0.28

$searchTop = [Math]::Max(0, [int]($midEyesY + $eyesDist * 0.80))
$searchBottom = [Math]::Min($h - 1, [int]($midEyesY + $eyesDist * 1.60))
$searchLeft = [Math]::Max(0, [int]($midEyesX - $eyesDist * 0.65))
$searchRight = [Math]::Min($w - 1, [int]($midEyesX + $eyesDist * 0.65))

Write-Host "Search ROI: Top=$searchTop, Bottom=$searchBottom, Left=$searchLeft, Right=$searchRight"

$sumX = 0.0
$sumY = 0.0
$sumWeight = 0.0
$minX = $w
$maxX = 0
$minY = $h
$maxY = 0

$step = [Math]::Max(2, [int]($w / 400))

for ($y = $searchTop; $y -le $searchBottom; $y += $step) {
    for ($x = $searchLeft; $x -le $searchRight; $x += $step) {
        $p = $bmp.GetPixel($x, $y)
        $r = [double]$p.R
        $g = [double]$p.G
        $b = [double]$p.B
        $lum = ($r + $g + $b) / 3.0
        $redRatio = ($r - $g) / [Math]::Max(1.0, $lum)

        if ($redRatio -gt 0.38 -and $lum -lt 165.0 -and $r -gt 125) {
            $weight = ($redRatio - 0.35) * (170.0 - $lum)
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
    Write-Host "Detected Lips Center: X=$cx, Y=$cy (Y% = $pctY %)"
    $wBox = $maxX - $minX
    $hBox = $maxY - $minY
    Write-Host "Detected Lip Bounding Box: X=[$minX, $maxX] (W=$wBox), Y=[$minY, $maxY] (H=$hBox)"
} else {
    Write-Host 'No lips detected!'
}
$bmp.Dispose()
