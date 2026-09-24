[xml]$xml = Get-Content "d:\Decompiler\App\Video\Capcut\window_dump.xml"
$nodes = $xml.SelectNodes("//node[@bounds]")
foreach ($n in $nodes) {
    if ($n.bounds -match '\[(\d+),(\d+)\]\[(\d+),(\d+)\]') {
        $x1 = [int]$Matches[1]
        $y1 = [int]$Matches[2]
        $x2 = [int]$Matches[3]
        $y2 = [int]$Matches[4]
        if ($y1 -ge 1200) {
            $cx = [int](($x1 + $x2) / 2)
            $cy = [int](($y1 + $y2) / 2)
            $clk = $n.clickable
            $cls = $n.class.Split('.')[-1]
            $txt = $n.text
            Write-Host "center=($cx, $cy) bounds=[$x1,$y1][$x2,$y2] clickable=$clk class=$cls text='$txt'"
        }
    }
}
