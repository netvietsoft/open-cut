Add-Type -AssemblyName System.Drawing
$bmp = [System.Drawing.Bitmap]::FromFile('d:/Decompiler/App/Video/Capcut/design/screenshots/parity100/user_test_upright.jpg')
$w = $bmp.Width
$h = $bmp.Height

$midEyesX = 769.5
$midEyesY = 1475.5
$eyesDist = 429.7

Write-Host "Real Eyes: Mid=($midEyesX, $midEyesY), Dist=$eyesDist"

for ($y = 1940; $y -le 2030; $y += 10) {
    $line = "Y=${y} | "
    for ($x = 680; $x -le 860; $x += 20) {
        $p = $bmp.GetPixel($x, $y)
        $r = [double]$p.R; $g = [double]$p.G; $b = [double]$p.B
        $lum = ($r + $g + $b) / 3.0
        $rr = [Math]::Round(($r - $g) / [Math]::Max(1.0, $lum), 2)
        $lumInt = [int]$lum
        $line += "${x}:[${rr},${lumInt}] "
    }
    Write-Host $line
}

Write-Host "`nChecking Right Side X=840..1000 at Y=1960..2020:"
for ($y = 1960; $y -le 2020; $y += 15) {
    $line = "Y=${y} | "
    for ($x = 840; $x -le 980; $x += 25) {
        $p = $bmp.GetPixel($x, $y)
        $r = [double]$p.R; $g = [double]$p.G; $b = [double]$p.B
        $lum = ($r + $g + $b) / 3.0
        $rr = [Math]::Round(($r - $g) / [Math]::Max(1.0, $lum), 2)
        $lumInt = [int]$lum
        $line += "${x}:[${rr},${lumInt}] "
    }
    Write-Host $line
}
$bmp.Dispose()
