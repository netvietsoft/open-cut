$xml = [xml](Get-Content scratch/picker_filtered_dump.xml)
$nodes = $xml.SelectNodes('//node')
foreach ($n in $nodes) {
    if ($n.text -like '*OPENCUT_PHOTO*' -or $n.text -like '*20260918_114608*' -or $n.text -like '*Thêm*') {
        Write-Host ($n.text + ' => ' + $n.bounds)
    }
}
