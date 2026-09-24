Add-Type -AssemblyName System.Drawing
$orig = [System.Drawing.Bitmap]::FromFile('d:/Decompiler/App/Video/Capcut/design/screenshots/parity100/user_test_upright.jpg')
$test = [System.Drawing.Bitmap]::FromFile('d:/Decompiler/App/Video/Capcut/design/screenshots/parity100/test_lipstick_natural.jpg')

$w = $orig.Width
$h = $orig.Height

$minX = $w; $maxX = 0; $minY = $h; $maxY = 0
$sumX = 0.0; $sumY = 0.0; $count = 0

for ($y = 0; $y -lt $h; $y += 2) {
    for ($x = 0; $x -lt $w; $x += 2) {
        $p1 = $orig.GetPixel($x, $y)
        $p2 = $test.GetPixel($x, $y)
        $diff = [Math]::Abs($p1.R - $p2.R) + [Math]::Abs($p1.G - $p2.G) + [Math]::Abs($p1.B - $p2.B)
        if ($diff -gt 15) {
            $sumX += $x * $diff
            $sumY += $y * $diff
            $count += $diff
            if ($x -lt $minX) { $minX = $x }
            if ($x -gt $maxX) { $maxX = $x }
            if ($y -lt $minY) { $minY = $y }
            if ($y -gt $maxY) { $maxY = $y }
        }
    }
}

$orig.Dispose()
$test.Dispose()

$cx = $sumX / $count
$cy = $sumY / $count
$rx = ($maxX - $minX) / 2
$ry = ($maxY - $minY) / 2

Write-Host "Diff Analysis of test_lipstick_natural.jpg:"
Write-Host "Center: CX=$cx, CY=$cy (Y% = $([Math]::Round($cy/$h*100, 2))%)"
Write-Host "Bounding: X=[$minX, $maxX], Y=[$minY, $maxY]"
Write-Host "Radii: RX=$rx, RY=$ry"
