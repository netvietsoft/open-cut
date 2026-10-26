"""Fetch OpenCut into an isolated checkout and write an audit handoff.

Kéo OpenCut vào bản checkout riêng và ghi bàn giao audit.
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path

from native_audit_watchdog import scan_once


REMOTE = "git@github.com-open-cut:netvietsoft/open-cut.git"
BRANCH = "develop"
TASK_ID = "TASK-GIT-WATCHDOG-20261026"
DEFAULT_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_CACHE = Path(os.environ.get("LOCALAPPDATA", Path.home())) / "NextAI" / "OpenCut-audit-checkout"


def git(*args: str, cwd: Path | None = None) -> str:
    """Run Git without shell expansion. / Chạy Git không qua shell để tránh nội suy lệnh."""
    result = subprocess.run(
        ["git", *args], cwd=cwd, capture_output=True, text=True,
        encoding="utf-8", errors="replace", timeout=240, check=False,
    )
    if result.returncode:
        raise RuntimeError(f"git {' '.join(args[:2])} failed: {result.stderr.strip()[-500:]}")
    return result.stdout.strip()


def sync_checkout(cache: Path, reference: Path, remote: str = REMOTE) -> tuple[str | None, str, list[str]]:
    """Fast-forward a dedicated checkout only. / Chỉ cập nhật nhanh bản checkout audit riêng."""
    if not (cache / ".git").is_dir():
        if cache.exists():
            raise RuntimeError(f"Audit cache exists without .git: {cache}")
        cache.parent.mkdir(parents=True, exist_ok=True)
        git("clone", "--branch", BRANCH, "--single-branch", "--reference-if-able", str(reference), remote, str(cache))
        old = git("rev-parse", "HEAD", cwd=reference) if (reference / ".git").exists() else None
    else:
        if git("remote", "get-url", "origin", cwd=cache) != remote:
            raise RuntimeError("Audit cache origin does not match the configured repository")
        if git("status", "--porcelain", cwd=cache):
            raise RuntimeError("Audit cache is dirty; refusing to overwrite it")
        old = git("rev-parse", "HEAD", cwd=cache)
        git("fetch", "--prune", "origin", BRANCH, cwd=cache)
        git("merge", "--ff-only", "origin/develop", cwd=cache)
    head = git("rev-parse", "HEAD", cwd=cache)
    changed = git("diff", "--name-only", f"{old}..{head}", cwd=cache).splitlines() if old and old != head else []
    return old, head, changed


def handoff_text(old: str | None, head: str, changed: list[str], audit: dict) -> str:
    """Render evidence and next actions. / Ghi bằng chứng và việc cần làm tiếp."""
    findings = audit["findings"]
    summary = audit["summary"]
    lines = [
        "# Git watchdog audit handoff / Bàn giao audit Git",
        "",
        f"- Task: `{TASK_ID}`",
        f"- Checked UTC / Kiểm tra UTC: {datetime.now(timezone.utc).isoformat()}",
        f"- Branch: `{BRANCH}`",
        f"- Previous commit / Commit trước: `{old or 'initial clone'}`",
        f"- Audited commit / Commit đã quét: `{head}`",
        f"- Changed paths / File đổi: {len(changed)}",
        f"- Native binaries / Thư viện native: {summary['binaries']}",
        f"- Scaffold folders / Thư mục mã sườn: {summary['source_scaffold']}",
        f"- High findings / Cảnh báo cao: {summary['high_findings']}",
        "",
        "## OBSERVED / Quan sát",
        "",
    ]
    lines += [f"- `{path}`" for path in changed[:100]] or ["- No commit change since previous scan / Không có commit mới."]
    if len(changed) > 100:
        lines.append(f"- ... {len(changed) - 100} additional paths in JSON / file khác trong JSON.")
    lines += ["", "## Findings / Phát hiện", ""]
    for item in sorted(findings, key=lambda finding: finding["severity"] != "high")[:100]:
        location = item.get("path", item.get("library", ""))
        if "SOURCE" in Path(location).parts:
            location = Path(*Path(location).parts[Path(location).parts.index("SOURCE"):]).as_posix()
        lines.append(f"- `{item['code']}` [{item['severity']}] `{location}` line {item.get('line', '?')}")
    if not findings:
        lines.append("- No scanner findings / Không có cảnh báo từ bộ quét.")
    lines += [
        "", "## Next team / Đội tiếp theo", "",
        "1. Review changed paths and high findings against the exact commit above. / Soát file đổi và cảnh báo cao tại commit nêu trên.",
        "2. Verify behavior with independent tests and binary evidence before claiming parity. / Kiểm tra hành vi bằng test độc lập và bằng chứng binary.",
        "3. Assign fixes through scoped task IDs; do not modify this audit checkout. / Giao sửa lỗi theo Task ID có phạm vi rõ ràng.",
        "", "## Limitation / Giới hạn", "",
        "This is a static integrity and pattern scan, not proof of decompilation completeness or binary parity. / Đây là quét tĩnh, không chứng minh giải mã hoàn chỉnh hay tương đương binary.",
        "",
    ]
    return "\n".join(lines)


def main() -> int:
    """Perform one scheduled cycle. / Thực hiện một chu kỳ theo lịch."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cache", type=Path, default=DEFAULT_CACHE)
    parser.add_argument("--output", type=Path, default=DEFAULT_ROOT / "SOURCE/BAOCAO-AUDIT/GIT_WATCHDOG_LATEST.md")
    parser.add_argument("--json", type=Path, default=DEFAULT_ROOT / "SOURCE/BAOCAO-AUDIT/GIT_WATCHDOG_LATEST.json")
    parser.add_argument("--baseline", help="compare the audited commit with this Git revision for this run")
    args = parser.parse_args()
    try:
        old, head, changed = sync_checkout(args.cache.resolve(), DEFAULT_ROOT)
        if args.baseline:
            old = git("rev-parse", args.baseline, cwd=args.cache)
            changed = git("diff", "--name-only", f"{old}..{head}", cwd=args.cache).splitlines()
        native_report = args.cache / "SOURCE/BAOCAO-AUDIT/NATIVE_WATCHDOG_LATEST.json"
        audit = scan_once(args.cache, native_report)
        payload = {"task_id": TASK_ID, "previous_commit": old, "commit": head, "changed_paths": changed, "audit": audit}
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(handoff_text(old, head, changed, audit), encoding="utf-8")
        args.json.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        print(f"Audited {head[:12]}: {len(changed)} changed paths; {len(audit['findings'])} findings")
        return 0
    except (OSError, RuntimeError, subprocess.TimeoutExpired) as error:
        print(f"Git audit watchdog failed: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
