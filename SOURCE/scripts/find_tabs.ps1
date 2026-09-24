$xml = [xml](Get-Content scratch/picker_dump_now.xml)
$nodes = $xml.SelectNodes('//node')
foreach ($n in $nodes) {
    if ($n.text -like '*Photos*' -or $n.text -like '*Video*' -or $n.text -like '*All*') {
        Write-Host ($n.text + ' => ' + $n.bounds)
    }
}
