"""Generates res/i18n/ru.json from the dictionaries in this folder.
Run: python3 tooling_i18n/generate_ru.py"""
import json, os, re, sys
here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, here)
root = os.path.dirname(here)
from ru_menu import categories, groups, tasks, ui_menu
from ru_nodes import nodes
from ru_inputs import inputs
from ru_ui import ui

out = {"ui": {}, "categories": categories, "nodes": {}, "inputs": inputs, "tasks": {}}
out["ui"].update(groups)
out["ui"].update(ui_menu)
def unescape(text):  # The keys are written like C++ literals
    return text.replace('\\n', '\n').replace('\\"', '"')
out["ui"].update({unescape(k): unescape(v) for k, v in ui.items()})
for task, (name, keywords) in tasks.items():
    out["tasks"][task] = {"name": name, "keywords": keywords}

# Check that every node exists, and report the missing ones
existing = {}
for d in os.listdir(os.path.join(root, "Nodes")):
    p = os.path.join(root, "Nodes", d)
    if os.path.isdir(p):
        existing[re.sub(r"^\d+ ", "", d)] = {f[:-8] for f in os.listdir(p) if f.endswith(".clbnode")}
for cat, entries in nodes.items():
    for name, value in entries.items():
        if name not in existing.get(cat, set()):
            continue  # e.g. particle nodes that only exist in 2D
        tr, kw = value if isinstance(value, tuple) else (value, "")
        out["nodes"][f"{cat}/{name}"] = {"name": tr, "keywords": kw} if kw else tr
for cat, names in existing.items():
    for name in names:
        if f"{cat}/{name}" not in out["nodes"]:
            print("Missing translation for node", f"{cat}/{name}")

path = os.path.join(root, "res", "i18n", "ru.json")
os.makedirs(os.path.dirname(path), exist_ok=True)
with open(path, "w", encoding="utf-8") as f:
    json.dump(out, f, ensure_ascii=False, indent=4, sort_keys=True)
print("Wrote", path)
