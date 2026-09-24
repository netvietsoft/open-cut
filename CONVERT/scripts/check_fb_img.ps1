Add-Type -AssemblyName System.Drawing
$img = [System.Drawing.Image]::FromFile((Resolve-Path "FB_IMG_1789812444308.jpg"))
Write-Host ("DIMENSIONS: Width=" + $img.Width + ", Height=" + $img.Height)
$img.Dispose()
Copy-Item "FB_IMG_1789812444308.jpg" "C:\Users\boluc\.gemini\antigravity-ide\brain\3fc1c617-da25-4ece-bbd0-eb9bb3669d3e" -Force
