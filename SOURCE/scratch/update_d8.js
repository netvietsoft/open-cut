const fs = require('fs');
const path = 'scripts/build_and_deploy.ps1';
let script = fs.readFileSync(path, 'utf8');

const regex = /Write-Host "\[4\/7\] Converting to classes\.dex using D8\.\.\."[\s\S]*?& "\$BUILD_TOOLS\\d8\.bat" --lib "\$PLATFORM_JAR" --output "\$OUT_DIR" \$classFiles/;

const newD8 = `Write-Host "[4/7] Converting to classes.dex using D8..." -ForegroundColor Yellow
& jar cf "$OUT_DIR\\classes.jar" -C "$OUT_DIR\\classes" .
if ($LASTEXITCODE -ne 0) {
    Write-Error "Creating classes.jar failed"
    exit 1
}
& "$BUILD_TOOLS\\d8.bat" --lib "$PLATFORM_JAR" --output "$OUT_DIR" "$OUT_DIR\\classes.jar"`;

if (regex.test(script)) {
    script = script.replace(regex, newD8);
    fs.writeFileSync(path, script, 'utf8');
    console.log('Updated D8 in build_and_deploy.ps1 successfully!');
} else {
    console.log('Regex did not match');
}
