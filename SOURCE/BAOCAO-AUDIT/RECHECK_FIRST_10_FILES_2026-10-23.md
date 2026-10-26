# Kiểm tra lại 10 file sau khi kéo Git / Recheck after pull

- Task: `TASK-AUDIT-NATIVE-RECHECK-20261023`
- Ngày / Date: 2026-10-23
- Branch/HEAD: `develop` at `f0f946eeaa039b86914f311362acedf355fd47f7`, equal to `origin/develop` after fast-forward of 52 commits.
- Scope: the same five `SOURCE/extracted/lib/arm64-v8a/*.so` files and five paired `SOURCE/GIAI-MA/*/*_pseudocode.cpp` files from the 2026-10-13 audit.

## Kết quả / Result

| Library | `.so` compared with prior audit | Current pseudocode | What can be concluded |
|---|---|---|---|
| `libcapcut` | SHA-256 unchanged; KOM wrapper | 13 lines, unchanged | Still blocked; no algorithm body recovered |
| `libmiddle-bridge` | SHA-256 unchanged | 121 lines; new lifecycle and parity routines plus modules | Substantial new source; equivalence to binary not established here |
| `libttffmpeg` | SHA-256 unchanged | 223 lines; network hooks, lifecycle and parity routines plus modules | New source has concrete defects below; 100% parity unverified |
| `libnative-filters` | SHA-256 unchanged | 313 lines; blur and circle-filter implementations | New source has a stride handling defect below |
| `libtexturerender_native` | SHA-256 unchanged | 292 lines; 11 JNI functions now have bodies | Previous missing-argument header issue appears addressed; full ABI/behavior parity unverified |

**OBSERVED:** SHA-256 of each binary matches the exact hash recorded in the 2026-10-13 audit. This confirms the pull changed source and reports, not these five binaries. The earlier ELF/KOM structural findings remain applicable. / The five binary hashes are unchanged; four pseudocode files have grown and one remains a scaffold.

## Findings requiring correction / Phát hiện cần sửa

### P1 — TTFFmpeg callback behavior

**OBSERVED:** `SOURCE/GIAI-MA/libttffmpeg/ttffmpeg_pseudocode.cpp:55–60` writes `127.0.0.1` for any non-null hostname. Lines 65–69 return `1` for every certificate without inspecting it. Lines 91 and 94 register these callbacks with `tt_register_dnsparser` and `tt_set_verify_callback` respectively.

**INFERRED:** If the engine uses the registered callbacks as this source intends, DNS resolution will point arbitrary hosts to loopback, and certificate validation will accept invalid certificates. The `COMPLETED`/100% report for this library is unsupported by these behaviors. The callback semantics were not executed at runtime in this audit.

### P1 — Native filter ignores row stride

**OBSERVED:** `SOURCE/GIAI-MA/libnative-filters/native_filters_pseudocode.cpp:114` accepts `stride`, but horizontal/vertical blur indexes rows as `y * width` (lines 41–42, 95), and circular filtering indexes pixels as `y * width + x` (line 169). JNI wrappers pass the bitmap's `info.stride` (lines 253 and 304). The processing functions do not use that stride.

**INFERRED:** A bitmap whose bytes per row exceed `width * 4` can have padding treated as pixels, producing incorrect rows. This needs a padded-stride test before parity can be claimed.

### P2 — Verification suite does not establish binary parity in this clone

**OBSERVED:** `SOURCE/scripts/verify_reconstruction_suite.py:33–36` points to `D:\Decompiler\App\Video\Capcut\SOURCE`, outside this checkout. Its TTFFmpeg checks at lines 265–287 compare hardcoded constants with themselves; the suite does not exercise either DNS or certificate callback. Its overall governance test at lines 3798–3801 sets `completed_count = 39` and then checks `completed_count == 39`. `run_all()` writes evidence JSON, including the dated 2026-10-13 file (lines 3859–3873), so it was not run in this read-only review.

**INFERRED:** Existing PASS evidence cannot be taken as proof that all recovered functions match the `.so` binaries. This review does not independently validate the reported 39/169 completion count.

## Git and verification notes

- Git was fetched and local `develop` fast-forwarded from `665c026a` to `f0f946ee`; HEAD equals `origin/develop`.
- Existing local changes were stashed, then restored. Content conflicts in `PROJECT_MEMORY.md`, `TASK_LOG.md`, and `UPDATETODOS.md` were resolved by retaining both the remote updates and the local audit entries. The stash remains as a backup.
- No unmerged paths remain; `git diff --check` and `git diff --cached --check` passed.
- No C++ compilation or runtime parity test was performed. No native binary or source file was edited for this recheck.
