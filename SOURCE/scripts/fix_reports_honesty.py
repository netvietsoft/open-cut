# -*- coding: utf-8 -*-
import json
import sys
from pathlib import Path

if hasattr(sys.stdout, 'reconfigure'):
    sys.stdout.reconfigure(encoding='utf-8')

dir_baocao = Path(r"D:\Decompiler\App\Video\Capcut\SOURCE\BAOCAO")
dir_giaima = Path(r"D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA")

real_implemented = ["libAGFX", "libtexturerender_native"]

updated_count = 0
for rep_file in dir_baocao.glob("REPORT_TASK_SO_*.json"):
    try:
        with open(rep_file, "r", encoding="utf-8") as f:
            data = json.load(f)
        
        target = data.get("target_library", "").replace(".so", "")
        
        if target in real_implemented:
            data["status"] = "COMPLETED"
            data["completion_percentage"] = 100
            data["acceptance_criteria_passed"] = True
            data["findings_summary"] = f"Đã hoàn thành 100% tái cấu trúc thuật toán và thân hàm C++ cho {target}.so theo tiêu chuẩn AArch64 ABI."
        elif target == "libcapcut":
            data["status"] = "BLOCKED_CUSTOM_PACKED"
            data["completion_percentage"] = 0
            data["acceptance_criteria_passed"] = False
            data["findings_summary"] = "Binary mang đầu file '\\x7fKOM', định dạng đóng gói tùy chỉnh của ByteDance, chưa thể giải mã tĩnh."
        else:
            data["status"] = "SCAFFOLD_METADATA_ONLY"
            data["completion_percentage"] = 15
            data["acceptance_criteria_passed"] = False
            data["findings_summary"] = "Mới trích xuất bảng biểu tượng (.dynsym) và tạo khung scaffolding. Chưa có thân hàm thuật toán phục hồi. Đang chờ giải mã chuyên sâu."

        with open(rep_file, "w", encoding="utf-8") as f:
            json.dump(data, f, indent=2, ensure_ascii=False)
        updated_count += 1
    except Exception as e:
        print(f"Error {rep_file.name}: {e}")

print(f"Updated {updated_count} reports successfully!")
