[xml]$xml = Get-Content window_dump.xml
foreach ($n in $xml.SelectNodes('//node')) {
    if ($n.text -match 'Nhạc|Sound|Chill|Bubble|Trích xuất|Audio|tiếng') {
        Write-Host "$($n.text) | $($n.bounds) | $($n.class)"
    }
}
