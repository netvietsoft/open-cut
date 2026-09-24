Add-Type -AssemblyName System.Drawing
$img = [System.Drawing.Bitmap]::FromFile((Resolve-Path "FB_IMG_1789812444308.jpg"))
Write-Host "Image Size: $($img.Width) x $($img.Height)"

# Sample colors in the expected man's and woman's face regions:
# Man face approx: X=350, Y=290
# Woman face approx: X=445, Y=310
# Center X=368, Y=440 is the shirt/background!
$c1 = $img.GetPixel(350, 290)
$c2 = $img.GetPixel(445, 310)
$cCenter = $img.GetPixel(368, 440)
Write-Host "Man face pixel (350, 290): R=$($c1.R), G=$($c1.G), B=$($c1.B)"
Write-Host "Woman face pixel (445, 310): R=$($c2.R), G=$($c2.G), B=$($c2.B)"
Write-Host "Center fallback pixel (368, 440): R=$($cCenter.R), G=$($cCenter.G), B=$($cCenter.B)"
$img.Dispose()
