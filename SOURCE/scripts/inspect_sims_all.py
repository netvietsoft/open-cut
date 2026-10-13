import json
with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libAGFX\symbols_demangled.json', 'r', encoding='utf-8') as f:
    syms = json.load(f)

print('--- ALL SIMULATOR SYMBOLS ---')
for s in syms:
    d = s.get('demangled', '')
    if any(k in d for k in ['Simulator', 'Particle', 'PBF', 'GridHash']):
        print(f"{s.get('value')} (size: {s.get('size')}): {d}")
