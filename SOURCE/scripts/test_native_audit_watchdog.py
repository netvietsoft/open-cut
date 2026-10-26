"""Behavior checks for the native audit watchdog.

Kiểm tra hành vi của watchdog audit native bằng dữ liệu tạm độc lập.
"""

from __future__ import annotations

import json
import tempfile
import unittest
from pathlib import Path

from native_audit_watchdog import scan_once


class NativeAuditWatchdogTests(unittest.TestCase):
    """Exercise change and source-risk detection. / Kiểm tra phát hiện thay đổi và rủi ro mã nguồn."""

    def test_detects_binary_copy_change_and_scaffold(self) -> None:
        """A changed duplicate must alert on the next scan. / Bản sao thay đổi phải sinh cảnh báo."""
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            extracted = root / "SOURCE/extracted/lib/arm64-v8a"
            copied = root / "SOURCE/apktool-res/lib/arm64-v8a"
            generated = root / "SOURCE/GIAI-MA/libdemo"
            for directory in (extracted, copied, generated):
                directory.mkdir(parents=True)
            (extracted / "libdemo.so").write_bytes(b"\x7fELFdemo")
            (copied / "libdemo.so").write_bytes(b"\x7fELFdemo")
            (generated / "demo_pseudocode.cpp").write_text(
                "// Khởi tạo Engine lõi\n// Giải phóng tài nguyên\n", encoding="utf-8"
            )
            report_path = root / "audit.json"

            first = scan_once(root, report_path)
            self.assertEqual(first["summary"]["copy_mismatches"], 0)
            self.assertEqual(first["summary"]["source_scaffold"], 1)
            self.assertEqual(json.loads(report_path.read_text(encoding="utf-8"))["summary"]["binaries"], 1)

            (copied / "libdemo.so").write_bytes(b"\x7fELFchanged")
            second = scan_once(root, report_path)
            self.assertIn("BINARY_COPY_MISMATCH", {item["code"] for item in second["findings"]})

    def test_flags_known_dangerous_callbacks_and_stride(self) -> None:
        """Known unsafe source patterns must alert. / Mẫu mã nguy hiểm đã biết phải sinh cảnh báo."""
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            extracted = root / "SOURCE/extracted/lib/arm64-v8a"
            copied = root / "SOURCE/apktool-res/lib/arm64-v8a"
            ttffmpeg = root / "SOURCE/GIAI-MA/libttffmpeg"
            filters = root / "SOURCE/GIAI-MA/libnative-filters"
            for directory in (extracted, copied, ttffmpeg, filters):
                directory.mkdir(parents=True)
            for name in ("libttffmpeg.so", "libnative-filters.so"):
                (extracted / name).write_bytes(b"\x7fELFdemo")
                (copied / name).write_bytes(b"\x7fELFdemo")
            (ttffmpeg / "ttffmpeg_pseudocode.cpp").write_text(
                'snprintf(ip_buf, ip_buf_len, "127.0.0.1");\n'
                "return 1; // 1 = Valid, 0 = MITM detected\n",
                encoding="utf-8",
            )
            (filters / "native_filters_pseudocode.cpp").write_text(
                "void f(int stride) { int pixelIndex = y * width + x; }\n", encoding="utf-8"
            )

            findings = scan_once(root, root / "audit.json")["findings"]
            codes = {item["code"] for item in findings}
            self.assertTrue({
                "TTFFMPEG_DNS_LOOPBACK", "TTFFMPEG_TLS_ACCEPT_ALL", "FILTER_STRIDE_NOT_USED_FOR_ROW_INDEX"
            }.issubset(codes))


if __name__ == "__main__":
    unittest.main()
