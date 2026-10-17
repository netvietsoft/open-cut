# -*- coding: utf-8 -*-
import json
import os

sym_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libfile_recorder\symbols_demangled.json"
with open(sym_path, "r", encoding="utf-8") as f:
    data = json.load(f)

print("Total symbols:", len(data))
defined = [item for item in data if item.get("value") != "0x0"]
print("Defined symbols:", len(defined))
for item in defined:
    print(item.get("value"), "|", item.get("size"), "|", item.get("type"), "|", item.get("name"), "|", item.get("demangled"))

print("\n--- Undefined symbols (Imports) ---")
undefined = [item for item in data if item.get("value") == "0x0"]
for item in undefined:
    print(item.get("name"), "|", item.get("demangled"))
