import xml.etree.ElementTree as ET
import re

tree = ET.parse('window_dump.xml')
for node in tree.iter('node'):
    b = node.attrib.get('bounds', '')
    t = node.attrib.get('text', '')
    c = node.attrib.get('class', '')
    clickable = node.attrib.get('clickable', '')
    m = re.match(r'\[(\d+),(\d+)\]\[(\d+),(\d+)\]', b)
    if m:
        x1, y1, x2, y2 = map(int, m.groups())
        if y1 >= 1200:
            cx, cy = (x1 + x2) // 2, (y1 + y2) // 2
            print(f"center=({cx:3d}, {cy:4d}) bounds=[{x1},{y1}][{x2},{y2}] clickable={clickable:5s} class={c.split('.')[-1]:15s} text='{t}'")
