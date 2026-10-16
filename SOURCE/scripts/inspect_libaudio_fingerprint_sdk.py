import json
from pathlib import Path

sym_path = Path("GIAI-MA/libaudio_fingerprint_sdk/symbols_demangled.json")
data = json.load(open(sym_path, encoding="utf-8"))
defined = [s for s in data if s.get("value") != "0x0"]
print(f"Total defined symbols: {len(defined)}")
for s in sorted(defined, key=lambda x: int(x["value"], 16)):
    print(f"{s['value']:>8} ({s['size']:>5} bytes) : {s['demangled']}")
