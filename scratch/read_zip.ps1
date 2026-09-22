Add-Type -AssemblyName System.IO.Compression.FileSystem

function Read-ZipEntry($zipPath, $entryName) {
    Write-Host "`n================================================"
    Write-Host "ENTRY: $zipPath :: $entryName"
    Write-Host "================================================"
    $zip = [System.IO.Compression.ZipFile]::OpenRead($zipPath)
    $entry = $zip.GetEntry($entryName)
    if ($entry) {
        $stream = $entry.Open()
        $reader = New-Object System.IO.StreamReader($stream)
        Write-Host $reader.ReadToEnd()
        $reader.Close()
        $stream.Close()
    } else {
        Write-Host "Entry not found!"
    }
    $zip.Dispose()
}

Read-ZipEntry "extracted/assets/lips_none.zip" "FaceMakeupV2_byTool/makeup.json"
Read-ZipEntry "extracted/assets/lips_none.zip" "FaceMakeupV2_byTool/lipShader2/fragShader.glsl"
Read-ZipEntry "extracted/assets/ManualReshape.zip" "event.lua"
Read-ZipEntry "extracted/assets/zip/FaceReshape_V2.zip" "FaceReshape_V2/distortion.json"
