# Clean-Room Forensics & Reconstruction Report: `libvcn.so` (`TASK_SO_042_libvcn`)

> **Báo cáo Giải mã & Tái tạo Sạch**: `libvcn.so` (ByteDance MediaKit Video Cloud Network — HTTP/HTTPS/TLS/TCP/DNS/Socket Engine)  
> **Binary Path / Đường dẫn nhị phân**: `SOURCE/apktool-res/lib/arm64-v8a/libvcn.so`  
> **Size / Dung lượng**: `214,960 bytes` (`0x347b0`)  
> **SHA-256**: `b1060ae9e0451374c5f18ad95a777123d937c9c7e81c93b8bbe98618790af3e3`

---

## 1. Binary Architecture & ELF Section Layout / Kiến trúc Nhị phân & Bố cục ELF (`[OBSERVED]`)

| Section | Virtual Address (`VMA`) | File Offset | Size (Bytes) | Role / Vai trò |
|---|---|---|---|---|
| `.text` | `0x008f80 .. 0x02a20c` | `0x008f80` | `135,820` | 33,955 AArch64 instructions across 94 exported `STT_FUNC` symbols |
| `.rodata` | `0x02a210 .. 0x02e4fb` | `0x02a210` | `17,131` | HTTP 400..404 `FFERRTAG` table (`0x02e330`), User-Agent `"ttplayer(default)57.56.101"` (`0x02ca3d`), Default Whitelist (`0x02cd23`), `VCNHttpContext` init constants (`0x02a290`, `0x02a298`) |
| `.fini_array` | `0x035728 .. 0x035738` | `0x031728` | `16` | Static destructors |
| `.data.rel.ro` | `0x035738 .. 0x037778` | `0x031738` | `8,256` | 66-entry `error_entries` table (`0x035740..0x035d70`), 4 `URLProtocol` descriptors (`0x035fa0` `tcp`, `0x036500` `tls`, `0x036960` `http`, `0x037340` `https`), `url_protocols` array (`0x037460`), `VCNDNSParserInterface` vtable (`0x037730`) |
| `.data` | `0x038000 .. 0x038018` | `0x034000` | `24` | Default log level (`32 = AV_LOG_INFO`) |
| `.bss` | `0x038018 .. 0x038470` | `0x034018` | `1,112` | Global custom TLS verify callback pointer (`0x038450`) |

---

## 2. Six Reconstructed Subsystems (`94 Exported Functions`, `120,026 Bytes` C++17/H, `0` Stubs)

1. **`vcn_av_*` String, Dictionary, Option, Memory, 66-Entry Error Table & Time Engine (`0x008fbc..0x010508`)**:
   - `vcn_av_strerror` (`0x00b464`): scans 66 24-byte `error_entries` at `.data.rel.ro 0x035740..0x035d70`.
   - `vcn_av_malloc` (`0x00eab0`): enforces `size <= 0x7FFFFFDF` and calls `posix_memalign(&ptr, 16, size)`.
   - `vcn_av_gettime_relative` (`0x00b178`): adds `0x000000233438E800ULL` (`42 * 365 * 86400 * 1000000`) to `gettimeofday`.
   - `vcn_av_timegm` (`0x010438`): Gregorian civil-to-days conversion (`-719469 = 0xFFF50593`, `* 86400`).
2. **`vcn_url_*`, `vcn_tcp_*`, `vcn_tls_*` & 4 `URLProtocol` Descriptors (`0x01050c..0x017244`, `.data.rel.ro 0x035fa0..0x037480`)**:
   - `ff_tcp_protocol` (`0x035fa0`, `priv_data_size = 0x178 = 376 B`), `ff_tls_protocol` (`0x036500`, `priv_data_size = 0x140 = 320 B`), `ff_http_protocol` (`0x036960`, `priv_data_size = 0x18a0 = 6,304 B`), `ff_https_protocol` (`0x037340`, `priv_data_size = 0x18a0 = 6,304 B`).
   - `vcn_tcp_get_ip_addr` (`0x014cb0`: `h->priv_data + 0x58`), `vcn_tls_get_ip_addr` (`0x0171ac`: `((VCNURLContext**)((uint8_t*)h->priv_data + 0x108))[0]->priv_data + 0x58`).
3. **`com::ss::mediakit::vcn::httpParser*` & `VCNHttpContext` (`0x01ddb0..0x029140`)**:
   - `httpParserHttpAVError` (`0x01ddb0`): uses bitmask `0x1B = 0b11011` and `.rodata 0x02e330` table (`0xCFCFCB08`, `0xCECFCB08`, `0xCCCFCB08`, `0xCBCFCB08`) + `0xA7A7CB08` (`4xx`) / `0xA7A7CA08` (`5xx`).
   - `createHttpContext` (`0x028e74`): allocates `0x2ad0` (`10,960`) bytes and initializes `+0x08 = 3`, `+0x28fc = 120`, `+0x2910 = 200`, `+0x2920 = 1`, `+0x2928 = 5`, `+0x2a10 = 0x7fffffff`.
4. **`VCNDNSParserInterface` (`0x029144..0x029177`), `VCNSocketInfo` (`0x029178..0x029a63`), `vcnUrlSplit` (`0x029a64`) & `vcnDoCustomVerify` (`0x02a1c4`)**.
