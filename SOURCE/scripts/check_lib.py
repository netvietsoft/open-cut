import json

def inspect(name):
    path = f"D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/{name}/symbols_demangled.json"
    with open(path, 'r', encoding='utf-8') as f:
        syms = json.load(f)
    print(f"=== {name} (Total: {len(syms)}) ===")
    domain = [s for s in syms if not s.get('demangled', '').startswith('std::') and not s.get('demangled', '').startswith('operator ')]
    print(f"Domain symbols: {len(domain)}")
    for s in domain[:15]:
        print(f"  {s.get('value')}: {s.get('demangled')}")

inspect('libaudioeffect')
inspect('libmiddle-bridge')
