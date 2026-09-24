Add-Type -AssemblyName System.Drawing
$bmp = [System.Drawing.Bitmap]::FromFile('d:/Decompiler/App/Video/Capcut/design/screenshots/parity100/phase22_03_lipstick.png')
$w = $bmp.Width
$h = $bmp.Height

$sumX = 0; $sumY = 0; $count = 0
for ($y = 0; $y -lt $h; $y += 2) {
    for ($x = 0; $x -lt $w; $x += 2) {
        $p = $bmp.GetPixel($x, $y)
        if ($p.R -gt 200 -and $p.G -lt 80 -and $p.B -lt 120) {
            $sumX += $x
            $sumY += $y
            $count++
        }
    }
}
$bmp.Dispose()
if ($count -gt 0) {
    $cx = $sumX / $count
    $cy = $sumY / $count
    Write-Host "Red spot in phase22_03: CX=$cx, CY=$cy (Y% = $([Math]::Round($cy/$h*100, 2))%) Count=$count"
} else {
    Write-Host "No red spot found"
}
