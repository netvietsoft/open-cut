[xml]$xml = Get-Content window_dump.xml
foreach ($n in $xml.SelectNodes('//node')) {
    if ($n.bounds -match '\[\d+,(17|18|19|20|21)\d\d\]') {
        Write-Host "$($n.text) | $($n.bounds) | $($n.class)"
    }
}
