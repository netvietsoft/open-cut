# Adversarial Proof & Mathematical Verification: `libvcn.so` (`PROOF-LIBVCN-V1`)

- **Target Binary**: `SOURCE/apktool-res/lib/arm64-v8a/libvcn.so` (`214,960 bytes`)
- **SHA-256**: `b1060ae9e0451374c5f18ad95a777123d937c9c7e81c93b8bbe98618790af3e3`
- **Task ID**: `TASK_SO_042_libvcn` / `TASK-119-RECONSTRUCTION-LIBVCN`
- **Reconstructed Code Size**: `120,026 bytes` across 9 C++17/H files + `README_ANALYSIS.md` (`0` stubs)

## Key Binary & Mathematical Proofs (`[OBSERVED]`)
1. **66-Entry `error_entries` Table (`.data.rel.ro 0x035740..0x035d70`, `0x630 = 1,584 bytes`)**:
   - Scanned by `vcn_av_strerror` (`0x00b464..0x00b520`, stride `0x18 = 24 bytes`).
2. **`httpParserHttpAVError` (`0x01ddb0..0x01ddf4`, `.rodata 0x02e330`)**:
   - Uses bitmask `0x1B = 0b11011` (`mov w9, #0x1b; lsr w9, w9, w8; tbnz w9, #0, #0x1dde8`) to select `.rodata 0x02e330` for HTTP `400, 401, 403, 404` (`0xCFCFCB08`, `0xCECFCB08`, `0xCCCFCB08`, `0xCBCFCB08`), `0xA7A7CB08` for other `4xx`, and `0xA7A7CA08` for `5xx`.
3. **4 `URLProtocol` Descriptors (`.data.rel.ro 0x035fa0, 0x036500, 0x036960, 0x037340`) & `VCNHttpContext` (`0x2ad0 = 10,960 B` at `0x028e74`)**:
   - Exact `priv_data_size` values: `tcp = 0x178` (`376 B`), `tls = 0x140` (`320 B`), `http/https = 0x18a0` (`6,304 B`), User-Agent `"ttplayer(default)57.56.101"` (`.rodata 0x02ca3d`).
