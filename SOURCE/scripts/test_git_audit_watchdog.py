"""Checks for Git watchdog handoff rendering. / Kiểm tra nội dung bàn giao watchdog Git."""

from __future__ import annotations

import unittest

from git_audit_watchdog import handoff_text


class GitAuditWatchdogTests(unittest.TestCase):
    """Check evidence in the report. / Kiểm tra bằng chứng trong báo cáo."""

    def test_handoff_includes_commit_changes_and_findings(self) -> None:
        """Keep actionable evidence. / Giữ bằng chứng để đội tiếp theo xử lý."""
        audit = {
            "summary": {"binaries": 1, "source_scaffold": 1, "high_findings": 1},
            "findings": [{"code": "UNSAFE_CALLBACK", "severity": "high", "path": "C:/audit/SOURCE/a.cpp", "line": 12}],
        }
        report = handoff_text("old", "new", ["SOURCE/a.cpp"], audit)
        self.assertIn("Audited commit / Commit đã quét: `new`", report)
        self.assertIn("`SOURCE/a.cpp` line 12", report)
        self.assertIn("`UNSAFE_CALLBACK`", report)
        self.assertIn("not proof of decompilation completeness", report)


if __name__ == "__main__":
    unittest.main()
