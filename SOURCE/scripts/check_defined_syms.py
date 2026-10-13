import json

def inspect(name):
    path = f"D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/{name}/symbols_demangled.json"
    with open(path, 'r', encoding='utf-8') as f:
        syms = json.load(f)
    defined = [s for s in syms if s.get('value') != '0x0' and s.get('size', 0) > 0 and not s.get('demangled', '').startswith('std::')]
    print(f"=== {name} Defined Symbols with code size > 0: {len(defined)} ===")
    for s in defined[:20]:
        print(f"  {s.get('value')} (size {s.get('size')}): {s.get('demangled')}")

inspect('libmiddle-bridge')
