"""Scan native assets without assigning a decompilation-completeness score.

Quét tài sản native mà không tự gán điểm hoàn thành giải mã.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path


INTERVAL_SECONDS = 300
DEFAULT_REPO = Path(__file__).resolve().parents[2]
REPORT_RELATIVE = Path("SOURCE/BAOCAO-AUDIT/NATIVE_WATCHDOG_LATEST.json")


def sha256_file(path: Path) -> str:
    """Hash a file in chunks. / Băm file theo từng khối để giới hạn bộ nhớ."""
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for block in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def source_snapshot(directory: Path) -> tuple[str, int, int, str | None]:
    """Record C++ files and detect exact tiny generated scaffolds. / Ghi nhận C++ và nhận diện khung sinh tự động rỗng."""
    cpp_files = sorted(directory.glob("*.cpp")) if directory.is_dir() else []
    if not cpp_files:
        return "missing", 0, 0, None

    total_bytes = 0
    digest = hashlib.sha256()
    scaffold_count = 0
    for cpp_file in cpp_files:
        content = cpp_file.read_bytes()
        total_bytes += len(content)
        digest.update(cpp_file.name.encode("utf-8"))
        digest.update(hashlib.sha256(content).digest())
        lines = content.decode("utf-8", errors="replace").splitlines()
        if len(lines) <= 20 and b"// Kh\xe1\xbb\x9fi t\xe1\xba\xa1o Engine l\xc3\xb5i" in content and b"// Gi\xe1\xba\xa3i ph\xc3\xb3ng t\xc3\xa0i nguy\xc3\xaan" in content:
            scaffold_count += 1
    status = "scaffold" if scaffold_count == len(cpp_files) else "source_present_unverified"
    return status, len(cpp_files), total_bytes, digest.hexdigest()


def matching_line(content: str, needle: str) -> int:
    """Return the first matching line number. / Trả số dòng đầu tiên chứa chuỗi cần tìm."""
    for line_number, line in enumerate(content.splitlines(), start=1):
        if needle in line:
            return line_number
    return 0


def focused_findings(source_root: Path) -> list[dict[str, object]]:
    """Flag known risky source patterns without claiming semantic proof.

    Đánh dấu mẫu mã đáng nghi đã biết; không tuyên bố tương đương nhị phân.
    """
    findings: list[dict[str, object]] = []
    focused = {
        "TTFFMPEG_DNS_LOOPBACK": (
            source_root / "GIAI-MA/libttffmpeg/ttffmpeg_pseudocode.cpp",
            "snprintf(ip_buf, ip_buf_len, \"127.0.0.1\")",
        ),
        "TTFFMPEG_TLS_ACCEPT_ALL": (
            source_root / "GIAI-MA/libttffmpeg/ttffmpeg_pseudocode.cpp",
            "return 1; // 1 = Valid, 0 = MITM detected",
        ),
    }
    for code, (path, needle) in focused.items():
        if path.is_file():
            content = path.read_text(encoding="utf-8", errors="replace")
            line = matching_line(content, needle)
            if line:
                findings.append({"code": code, "path": str(path), "line": line, "severity": "high"})

    filters_path = source_root / "GIAI-MA/libnative-filters/native_filters_pseudocode.cpp"
    if filters_path.is_file():
        content = filters_path.read_text(encoding="utf-8", errors="replace")
        if "int stride" in content and "y * width + x" in content:
            findings.append({
                "code": "FILTER_STRIDE_NOT_USED_FOR_ROW_INDEX",
                "path": str(filters_path),
                "line": matching_line(content, "y * width + x"),
                "severity": "high",
            })
    return findings


def prior_libraries(report_path: Path) -> dict[str, dict[str, object]]:
    """Load the last local snapshot when valid. / Đọc bản quét trước nếu JSON hợp lệ."""
    if not report_path.is_file():
        return {}
    try:
        previous = json.loads(report_path.read_text(encoding="utf-8"))
        return {entry["name"]: entry for entry in previous["libraries"]}
    except (OSError, ValueError, KeyError, TypeError):
        return {}


def scan_repository(repo_root: Path, previous: dict[str, dict[str, object]] | None = None) -> dict[str, object]:
    """Inventory all arm64 binaries and paired C++ trees. / Kiểm kê toàn bộ .so arm64 và thư mục C++ tương ứng."""
    source_root = repo_root / "SOURCE"
    binary_root = source_root / "extracted/lib/arm64-v8a"
    copy_root = source_root / "apktool-res/lib/arm64-v8a"
    binaries = sorted(binary_root.glob("*.so"))
    if not binaries:
        raise RuntimeError(f"No arm64 .so files found under {binary_root}")

    previous = previous or {}
    libraries: list[dict[str, object]] = []
    findings: list[dict[str, object]] = []
    for binary in binaries:
        name = binary.stem
        binary_hash = sha256_file(binary)
        copy = copy_root / binary.name
        copy_matches = copy.is_file() and sha256_file(copy) == binary_hash
        with binary.open("rb") as binary_stream:
            magic = binary_stream.read(4)
        binary_format = "ELF_magic" if magic == b"\x7fELF" else "KOM_magic" if magic == b"\x7fKOM" else "unknown_magic"
        source_status, cpp_count, cpp_bytes, source_hash = source_snapshot(source_root / "GIAI-MA" / name)
        entry = {
            "name": name,
            "binary_bytes": binary.stat().st_size,
            "binary_sha256": binary_hash,
            "binary_format": binary_format,
            "copy_matches": copy_matches,
            "cpp_count": cpp_count,
            "cpp_bytes": cpp_bytes,
            "cpp_sha256": source_hash,
            "source_status": source_status,
        }
        libraries.append(entry)

        if not copy_matches:
            findings.append({"code": "BINARY_COPY_MISMATCH", "library": name, "severity": "high"})
        if binary_format == "unknown_magic":
            findings.append({"code": "UNKNOWN_BINARY_MAGIC", "library": name, "severity": "high"})
        if source_status in {"missing", "scaffold"}:
            findings.append({"code": "SOURCE_" + source_status.upper(), "library": name, "severity": "review"})
        older = previous.get(name, {})
        if older.get("binary_sha256") and older["binary_sha256"] != binary_hash:
            findings.append({"code": "BINARY_CHANGED", "library": name, "severity": "review"})
        if older.get("cpp_sha256") and older["cpp_sha256"] != source_hash:
            findings.append({"code": "SOURCE_CHANGED", "library": name, "severity": "review"})

    findings.extend(focused_findings(source_root))
    return {
        "timestamp_utc": datetime.now(timezone.utc).isoformat(),
        "repository": str(repo_root),
        "scan_scope": "all extracted arm64 .so files and matching GIAI-MA C++ folders; magic/hash checks only",
        "interval_seconds": INTERVAL_SECONDS,
        "summary": {
            "binaries": len(libraries),
            "copy_mismatches": sum(not item["copy_matches"] for item in libraries),
            "source_missing": sum(item["source_status"] == "missing" for item in libraries),
            "source_scaffold": sum(item["source_status"] == "scaffold" for item in libraries),
            "high_findings": sum(item["severity"] == "high" for item in findings),
        },
        "findings": findings,
        "libraries": libraries,
        "limitations": "ELF_magic is not ELF validity; source presence is not functional or binary parity.",
    }


def write_report(report_path: Path, payload: dict[str, object]) -> None:
    """Atomically replace the local report. / Ghi báo cáo cục bộ bằng thao tác thay thế nguyên tử."""
    report_path.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(mode="w", encoding="utf-8", dir=report_path.parent, prefix=".native_audit_", suffix=".tmp", delete=False) as temporary:
        json.dump(payload, temporary, ensure_ascii=False, indent=2)
        temporary.write("\n")
        temp_path = Path(temporary.name)
    temp_path.replace(report_path)


def scan_once(repo_root: Path, report_path: Path) -> dict[str, object]:
    """Run one scan with change detection. / Quét một lần và đối chiếu với lần trước."""
    payload = scan_repository(repo_root, prior_libraries(report_path))
    write_report(report_path, payload)
    return payload


def main(argv: list[str] | None = None) -> int:
    """Run once for Task Scheduler or loop on demand. / Chạy một lần cho Task Scheduler hoặc lặp theo yêu cầu."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=DEFAULT_REPO, help="repository root")
    parser.add_argument("--output", type=Path, help="JSON report path; defaults under SOURCE/BAOCAO-AUDIT")
    parser.add_argument("--watch", action="store_true", help="repeat every five minutes")
    args = parser.parse_args(argv)
    repo_root = args.repo.resolve()
    report_path = (args.output or repo_root / REPORT_RELATIVE).resolve()

    while True:
        started = time.monotonic()
        try:
            payload = scan_once(repo_root, report_path)
            summary = payload["summary"]
            print(f"Native audit: {summary['binaries']} binaries, {summary['high_findings']} high findings; {report_path}", flush=True)
        except (OSError, RuntimeError, ValueError) as error:
            print(f"Native audit failed: {error}", file=sys.stderr, flush=True)
            if not args.watch:
                return 1
        if not args.watch:
            return 0
        time.sleep(max(0, INTERVAL_SECONDS - (time.monotonic() - started)))


if __name__ == "__main__":
    raise SystemExit(main())
