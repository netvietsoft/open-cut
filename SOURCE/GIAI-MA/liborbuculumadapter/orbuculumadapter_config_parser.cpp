// ============================================================================
// File: orbuculumadapter_config_parser.cpp
// Target Binary: liborbuculumadapter.so (149,936 bytes)
// SHA-256: c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785
//
// [EN] Clean-room C++17 implementation of atomic BlockSnapshot evaluation,
//      RFC & KV HTTP header parsers, URL scheme/host/path extractors, wildcard
//      domain & path prefix rule matcher, 1P/3P Dataflow ID replenishment,
//      and hexadecimal/decimal DFID string conversion (0x00b09c..0x010924).
// [VN] Triển khai C++17 tái tạo sạch cho đánh giá BlockSnapshot nguyên tử,
//      bộ phân tích HTTP header chuẩn RFC & KV, bộ trích xuất giao thức/host/path
//      URL, bộ khớp quy tắc tên miền đại diện & tiền tố đường dẫn, bổ sung mã
//      Dataflow ID 1P/3P, và chuyển đổi chuỗi DFID hệ 16/hệ 10 (0x00b09c..0x010924).
// ============================================================================

#include "orbuculumadapter_config_parser.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <sstream>

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

namespace {

// ============================================================================
// [EN] Helper: trim leading and trailing ASCII whitespace (' ' and '\t')
//      Reconstructed from 0x00bbc4..0x00bc38 & 0x00bf3c..0x00bfb0.
// [VN] Hàm phụ trợ: cắt khoảng trắng ASCII đầu và cuối (' ' và '\t')
//      Phục dựng từ 0x00bbc4..0x00bc38 & 0x00bf3c..0x00bfb0.
// ============================================================================
std::string TrimSpacesAndTabs(const std::string& input) {
    const size_t first = input.find_first_not_of(" \t");
    if (first == std::string::npos) {
        return std::string();
    }
    const size_t last = input.find_last_not_of(" \t");
    return input.substr(first, (last - first) + 1);
}

// ============================================================================
// [EN] Helper: convert string to lowercase via std::tolower
//      Reconstructed from 0x00cc78..0x00cc98 & 0x00d150..0x00d174.
// [VN] Hàm phụ trợ: chuyển chuỗi sang chữ thường qua std::tolower
//      Phục dựng từ 0x00cc78..0x00cc98 & 0x00d150..0x00d174.
// ============================================================================
std::string ToLowerAscii(const std::string& input) {
    std::string out = input;
    std::transform(out.begin(), out.end(), out.begin(), [](unsigned char ch) {
        return static_cast<char>(std::tolower(ch));
    });
    return out;
}

}  // namespace

// ============================================================================
// 1. ATOMIC BLOCK SNAPSHOT MANAGEMENT (0x00b09c, 0x00b1a8, 0x00cfc0)
// ============================================================================

/**
 * [EN] Reconstructed from `0x00b09c..0x00b0f8`:
 *      Calls `std::__ndk1::__get_sp_mut(&g_block_snapshot)` (`0x028340`),
 *      locks the spin-mutex, copies the `shared_ptr<BlockSnapshot>` (`0x028340`
 *      and control block `0x028348` via `__shared_count::__add_shared`), and
 *      unlocks the spin-mutex.
 * [VN] Phục dựng từ `0x00b09c..0x00b0f8`:
 *      Gọi `std::__ndk1::__get_sp_mut(&g_block_snapshot)` (`0x028340`),
 *      khóa mutex xoay, sao chép `shared_ptr<BlockSnapshot>` (`0x028340`
 *      và khối điều khiển `0x028348` qua `__shared_count::__add_shared`), rồi
 *      mở khóa mutex.
 */
std::shared_ptr<BlockSnapshot> GetBlockSnapshot() {
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    std::lock_guard<std::mutex> lock(state.block_snapshot_mutex);
    return state.block_snapshot;
}

/**
 * [EN] Reconstructed from `0x00b1a8..0x00b214`:
 *      Acquires `__get_sp_mut(&0x028340)`, swaps `(ptr, cntrl)` with the new
 *      `shared_ptr<BlockSnapshot>`, unlocks `__sp_mut`, and releases the old
 *      control block via `__shared_weak_count::__release_shared()`.
 * [VN] Phục dựng từ `0x00b1a8..0x00b214`:
 *      Khóa `__get_sp_mut(&0x028340)`, hoán đổi `(ptr, cntrl)` với
 *      `shared_ptr<BlockSnapshot>` mới, mở khóa `__sp_mut`, và giải phóng
 *      khối điều khiển cũ qua `__shared_weak_count::__release_shared()`.
 */
void UpdateBlockSnapshot(std::shared_ptr<BlockSnapshot> new_snapshot) {
    std::shared_ptr<BlockSnapshot> old_snapshot;
    {
        GlobalRuntimeState& state = GetGlobalRuntimeState();
        std::lock_guard<std::mutex> lock(state.block_snapshot_mutex);
        old_snapshot = std::move(state.block_snapshot);
        state.block_snapshot = std::move(new_snapshot);
    }
}

/**
 * [EN] Reconstructed from `0x00cfc0..0x00d27c` (`isNativeNetworkResultNeedBlockInner`):
 *      1. If `result_code == 0`, immediately returns `false` (`w0 = 0`).
 *      2. Loads `snapshot = GetBlockSnapshot()` (`0x00b09c`). If `!snapshot`, returns `false`.
 *      3. Checks `snapshot->enable_network_hard_block` (`+0x00`). If `0`, returns `false`.
 *      4. Checks `snapshot->is_target_rule_group` (`+0x01`). If `0`, returns `false`.
 *      5. Linearly scans `snapshot->allow_code_list` (`+0x08..+0x10`) for `result_code`:
 *         if found (`0x00d020..0x00d038`), returns `false` (allowed).
 *      6. If `!dfid.empty()`, lowercases both `dfid` and each entry in
 *         `snapshot->allow_dfid_list` (`+0x20..+0x28`) via `tolower` (`0x00d150`)
 *         and compares for equality (`0x00d1a0`). If matched, returns `false` (allowed).
 *      7. If `snapshot->enable_dynamic_check` (`+0x02`) is false (`0`), returns `true` (block!).
 *      8. Otherwise, checks `g_in_target_block_cb` (`0x028240`): if non-null, calls
 *         `g_in_target_block_cb()` (`0x007b18` -> `TTKNativeNetworkManager.inTargetBlockRuleHashList()Z`)
 *         and returns `(cb_result != 0)`.
 * [VN] Phục dựng từ `0x00cfc0..0x00d27c` (`isNativeNetworkResultNeedBlockInner`):
 *      1. Nếu `result_code == 0`, trả về ngay `false` (`w0 = 0`).
 *      2. Nạp `snapshot = GetBlockSnapshot()` (`0x00b09c`). Nếu `!snapshot`, trả về `false`.
 *      3. Kiểm tra `snapshot->enable_network_hard_block` (`+0x00`). Nếu `0`, trả về `false`.
 *      4. Kiểm tra `snapshot->is_target_rule_group` (`+0x01`). Nếu `0`, trả về `false`.
 *      5. Quét tuyến tính `snapshot->allow_code_list` (`+0x08..+0x10`) tìm `result_code`:
 *         nếu tìm thấy (`0x00d020..0x00d038`), trả về `false` (cho phép).
 *      6. Nếu `!dfid.empty()`, chuyển chữ thường cả `dfid` và từng phần tử trong
 *         `snapshot->allow_dfid_list` (`+0x20..+0x28`) qua `tolower` (`0x00d150`)
 *         rồi so sánh bằng (`0x00d1a0`). Nếu khớp, trả về `false` (cho phép).
 *      7. Nếu `snapshot->enable_dynamic_check` (`+0x02`) bằng `false` (`0`), trả về `true` (chặn!).
 *      8. Ngược lại, kiểm tra `g_in_target_block_cb` (`0x028240`): nếu khác null, gọi
 *         `g_in_target_block_cb()` (`0x007b18` -> `TTKNativeNetworkManager.inTargetBlockRuleHashList()Z`)
 *         và trả về `(cb_result != 0)`.
 */
bool EvaluateNetworkResultNeedBlock(int32_t result_code, const std::string& dfid) {
    if (result_code == 0) {
        return false;
    }

    const std::shared_ptr<BlockSnapshot> snapshot = GetBlockSnapshot();
    if (!snapshot) {
        return false;
    }

    if (!snapshot->enable_network_hard_block || !snapshot->is_target_rule_group) {
        return false;
    }

    // [EN] Step 5: Check allow_code_list (+0x08) / [VN] Bước 5: Kiểm tra danh sách mã cho phép (+0x08)
    const auto& allow_codes = snapshot->allow_code_list;
    if (std::find(allow_codes.begin(), allow_codes.end(), result_code) != allow_codes.end()) {
        return false;
    }

    // [EN] Step 6: Case-insensitive check against allow_dfid_list (+0x20)
    // [VN] Bước 6: Kiểm tra không phân biệt hoa thường với allow_dfid_list (+0x20)
    if (!dfid.empty()) {
        const std::string lowered_dfid = ToLowerAscii(dfid);
        for (const std::string& allowed_entry : snapshot->allow_dfid_list) {
            if (ToLowerAscii(allowed_entry) == lowered_dfid) {
                return false;
            }
        }
    }

    // [EN] Step 7 & 8: Dynamic rule hash list check (+0x02 & 0x028240)
    // [VN] Bước 7 & 8: Kiểm tra động danh sách băm quy tắc (+0x02 & 0x028240)
    if (!snapshot->enable_dynamic_check) {
        return true;
    }

    const InTargetBlockRuleHashListCallbackFn dynamic_cb =
        GetGlobalRuntimeState().in_target_block_cb;
    if (dynamic_cb == nullptr) {
        return false;
    }
    return dynamic_cb();
}

// ============================================================================
// 2. HTTP HEADER PARSERS & SERIALIZER (0x00b99c, 0x00ba34, 0x00bda8, 0x010924)
// ============================================================================

/**
 * [EN] Reconstructed from `0x00ba34..0x00bda4` (`parseRfcHeaders`):
 *      Iterates through `raw_headers` searching for `"\r\n"` (`0x01acdf`) delimiter:
 *      - Extracts each line `raw_headers.substr(pos, next_crlf - pos)`.
 *      - Finds first `':'` (`w1 = 0x3a`) via `std::string::find(':', 0)` (`0x00ed28`).
 *      - Splits into `key = TrimSpacesAndTabs(line.substr(0, colon_pos))` and
 *        `val = TrimSpacesAndTabs(line.substr(colon_pos + 1))`.
 *      - Inserts `headers[key] = val` into `std::map<std::string, std::string>` if `!key.empty()`.
 * [VN] Phục dựng từ `0x00ba34..0x00bda4` (`parseRfcHeaders`):
 *      Duyệt qua `raw_headers` tìm dấu phân cách `"\r\n"` (`0x01acdf`):
 *      - Trích xuất từng dòng `raw_headers.substr(pos, next_crlf - pos)`.
 *      - Tìm ký tự `':'` đầu tiên (`w1 = 0x3a`) qua `std::string::find(':', 0)` (`0x00ed28`).
 *      - Tách thành `key = TrimSpacesAndTabs(line.substr(0, colon_pos))` và
 *        `val = TrimSpacesAndTabs(line.substr(colon_pos + 1))`.
 *      - Chèn `headers[key] = val` vào `std::map<std::string, std::string>` nếu `!key.empty()`.
 */
std::map<std::string, std::string> ParseRfcHttpHeaders(const std::string& raw_headers) {
    std::map<std::string, std::string> result;
    if (raw_headers.empty()) {
        return result;
    }

    size_t pos = 0;
    const size_t total_len = raw_headers.size();
    while (pos <= total_len) {
        const size_t crlf_pos = raw_headers.find("\r\n", pos);
        const std::string line = (crlf_pos == std::string::npos)
                                     ? raw_headers.substr(pos)
                                     : raw_headers.substr(pos, crlf_pos - pos);

        if (!line.empty()) {
            const size_t colon_pos = line.find(':');
            if (colon_pos != std::string::npos) {
                std::string key = TrimSpacesAndTabs(line.substr(0, colon_pos));
                std::string val = TrimSpacesAndTabs(line.substr(colon_pos + 1));
                if (!key.empty()) {
                    result[std::move(key)] = std::move(val);
                }
            }
        }

        if (crlf_pos == std::string::npos) {
            break;
        }
        pos = crlf_pos + 2;
    }
    return result;
}

/**
 * [EN] Reconstructed from `0x00bda8..0x00c138` (`parseKvHeaders`):
 *      1. Checks that `raw_headers.find('=') != npos` (`w1 = 0x3d`) AND
 *         `raw_headers.find("\r\n") == npos` (`0x01acdf`). If either check fails,
 *         returns an empty map immediately (`0x00bdf4..0x00be10`).
 *      2. Uses `std::stringstream` (`0x00be24`) with `std::getline(ss, line, '\n')` (`w2 = 0x0a`).
 *      3. Within each `\n`-delimited segment, splits further by `'&'` (`w1 = 0x26`),
 *         then locates `'='` (`w1 = 0x3d`), trims spaces/tabs (`" \t"`), and stores
 *         `result[key] = val` if `!key.empty()`.
 * [VN] Phục dựng từ `0x00bda8..0x00c138` (`parseKvHeaders`):
 *      1. Kiểm tra `raw_headers.find('=') != npos` (`w1 = 0x3d`) VÀ
 *         `raw_headers.find("\r\n") == npos` (`0x01acdf`). Nếu một trong hai điều kiện
 *         không thỏa, trả về map rỗng ngay lập tức (`0x00bdf4..0x00be10`).
 *      2. Dùng `std::stringstream` (`0x00be24`) với `std::getline(ss, line, '\n')` (`w2 = 0x0a`).
 *      3. Trong mỗi đoạn phân tách bởi `\n`, tách tiếp theo `'&'` (`w1 = 0x26`),
 *         sau đó tìm `'='` (`w1 = 0x3d`), cắt khoảng trắng/tab (`" \t"`), và lưu
 *         `result[key] = val` nếu `!key.empty()`.
 */
std::map<std::string, std::string> ParseKvHttpHeaders(const std::string& raw_headers) {
    std::map<std::string, std::string> result;
    if (raw_headers.find('=') == std::string::npos ||
        raw_headers.find("\r\n") != std::string::npos) {
        return result;
    }

    std::stringstream ss(raw_headers);
    std::string line;
    while (std::getline(ss, line, '\n')) {
        size_t pos = 0;
        while (pos <= line.size()) {
            const size_t amp_pos = line.find('&', pos);
            const std::string token = (amp_pos == std::string::npos)
                                          ? line.substr(pos)
                                          : line.substr(pos, amp_pos - pos);

            if (!token.empty()) {
                const size_t eq_pos = token.find('=');
                if (eq_pos != std::string::npos) {
                    std::string key = TrimSpacesAndTabs(token.substr(0, eq_pos));
                    std::string val = TrimSpacesAndTabs(token.substr(eq_pos + 1));
                    if (!key.empty()) {
                        result[std::move(key)] = std::move(val);
                    }
                }
            }

            if (amp_pos == std::string::npos) {
                break;
            }
            pos = amp_pos + 1;
        }
    }
    return result;
}

/**
 * [EN] Reconstructed from `0x00b99c..0x00ba30` (`parseHttpHeadersUnified`):
 *      Calls `ParseKvHttpHeaders(raw_headers)` (`0x00bda8`). If the returned
 *      `std::map` has `size() == 0` (`ldr x8, [x19, #0x10]; cbz x8`), falls back
 *      to `ParseRfcHttpHeaders(raw_headers)` (`0x00ba34`).
 * [VN] Phục dựng từ `0x00b99c..0x00ba30` (`parseHttpHeadersUnified`):
 *      Gọi `ParseKvHttpHeaders(raw_headers)` (`0x00bda8`). Nếu `std::map` trả về
 *      có `size() == 0` (`ldr x8, [x19, #0x10]; cbz x8`), chuyển sang gọi
 *      `ParseRfcHttpHeaders(raw_headers)` (`0x00ba34`).
 */
std::map<std::string, std::string> ParseHttpHeadersUnified(const std::string& raw_headers) {
    std::map<std::string, std::string> parsed = ParseKvHttpHeaders(raw_headers);
    if (parsed.empty()) {
        parsed = ParseRfcHttpHeaders(raw_headers);
    }
    return parsed;
}

/**
 * [EN] Reconstructed from `0x010924..0x010af4` (`serializeHeadersMap`):
 *      Iterates over `std::map<std::string, std::string>` in-order (`0x010950..0x010a60`)
 *      and formats each pair into `std::ostringstream` as `it->first << ":" << it->second << "\r\n"`.
 * [VN] Phục dựng từ `0x010924..0x010af4` (`serializeHeadersMap`):
 *      Duyệt qua `std::map<std::string, std::string>` theo thứ tự (`0x010950..0x010a60`)
 *      và định dạng từng cặp vào `std::ostringstream` theo mẫu `it->first << ":" << it->second << "\r\n"`.
 */
std::string SerializeHeadersToRfcString(const std::map<std::string, std::string>& headers) {
    std::ostringstream oss;
    for (const auto& kv : headers) {
        oss << kv.first << ":" << kv.second << "\r\n";
    }
    return oss.str();
}

// ============================================================================
// 3. URL SCHEME FILTER, HOST/PATH PARSER & WILDCARD RULE MATCHER
//    (0x00c13c, 0x00ca60, 0x00d660, 0x00da64, 0x00dc60, 0x00e1d8)
// ============================================================================

/**
 * [EN] Reconstructed from `0x00c13c..0x00c4bc`:
 *      1. Initializes static default vector of 7 schemes at `.bss 0x028758`
 *         guarded by `0x028770`: `{"http://", "https://", "wss://", "tcp://",
 *         "udp://", "tls://", "quic://"}` (`.rodata 0x01ace8..0x01ad17`).
 *      2. Selects `NetConfigRepository::compliance_prefix_list` (`0x028320`) if
 *         non-empty; otherwise uses the 7 default schemes.
 *      3. Checks whether `url` starts with any prefix (`url.rfind(prefix, 0) == 0`
 *         via `0x00f6ec`).
 * [VN] Phục dựng từ `0x00c13c..0x00c4bc`:
 *      1. Khởi tạo vector tĩnh mặc định gồm 7 giao thức tại `.bss 0x028758`
 *         bảo vệ bởi `0x028770`: `{"http://", "https://", "wss://", "tcp://",
 *         "udp://", "tls://", "quic://"}` (`.rodata 0x01ace8..0x01ad17`).
 *      2. Chọn `NetConfigRepository::compliance_prefix_list` (`0x028320`) nếu
 *         không rỗng; ngược lại dùng 7 giao thức mặc định.
 *      3. Kiểm tra xem `url` có bắt đầu bằng bất kỳ tiền tố nào không
 *         (`url.rfind(prefix, 0) == 0` qua `0x00f6ec`).
 */
bool IsUrlMatchingComplianceScheme(const std::string& url) {
    static const std::vector<std::string> kDefaultSchemes = {
        "http://",
        "https://",
        "wss://",
        "tcp://",
        "udp://",
        "tls://",
        "quic://"
    };

    const NetConfigRepository& repo = GetNetConfigRepository();
    const std::vector<std::string>& active_prefixes =
        repo.compliance_prefix_list.empty() ? kDefaultSchemes : repo.compliance_prefix_list;

    for (const std::string& prefix : active_prefixes) {
        if (!prefix.empty() && url.rfind(prefix, 0) == 0) {
            return true;
        }
    }
    return false;
}

/**
 * [EN] Reconstructed from `0x00d660..0x00da60` (`extractUrlHostAndPath`):
 *      1. Finds `"://"` (`.rodata 0x01ad54`) in `url`. If not found (`pos == npos`),
 *         returns `false`.
 *      2. Advances `host_start = scheme_pos + 3`. Finds first `'/'` (`w1 = 0x2f`) at
 *         or after `host_start`:
 *         - If `'/'` is not found: `raw_host = url.substr(host_start)`, `raw_path = ""`.
 *         - If `'/'` is found at `slash_pos`:
 *           `raw_host = url.substr(host_start, slash_pos - host_start)`.
 *           Searches for `'?'` or `'#'` (`"?#"`, `.rodata 0x01ad58`) via `find_first_of`:
 *           `raw_path = url.substr(slash_pos, query_pos - slash_pos)`.
 *      3. Strips `:port` from `raw_host` (`find(':', 0)` at `0x00d798`).
 *      4. If `raw_host.empty()`, returns `false`.
 *      5. Converts `raw_host` to lowercase via `std::tolower` loop (`0x00d7f4..0x00d880`).
 *      6. If `raw_path` ends with `'/'` (`0x2f`), pops trailing `'/'` (`0x00d8c0..0x00d8f8`).
 * [VN] Phục dựng từ `0x00d660..0x00da60` (`extractUrlHostAndPath`):
 *      1. Tìm `"://"` (`.rodata 0x01ad54`) trong `url`. Nếu không thấy (`pos == npos`),
 *         trả về `false`.
 *      2. Đặt `host_start = scheme_pos + 3`. Tìm ký tự `'/'` đầu tiên (`w1 = 0x2f`) từ
 *         `host_start`:
 *         - Nếu không thấy `'/'`: `raw_host = url.substr(host_start)`, `raw_path = ""`.
 *         - Nếu thấy `'/'` tại `slash_pos`:
 *           `raw_host = url.substr(host_start, slash_pos - host_start)`.
 *           Tìm `'?'` hoặc `'#'` (`"?#"`, `.rodata 0x01ad58`) qua `find_first_of`:
 *           `raw_path = url.substr(slash_pos, query_pos - slash_pos)`.
 *      3. Cắt bỏ `:port` khỏi `raw_host` (`find(':', 0)` tại `0x00d798`).
 *      4. Nếu `raw_host.empty()`, trả về `false`.
 *      5. Chuyển `raw_host` sang chữ thường qua vòng lặp `std::tolower` (`0x00d7f4..0x00d880`).
 *      6. Nếu `raw_path` kết thúc bằng `'/'` (`0x2f`), xóa dấu `'/'` ở cuối (`0x00d8c0..0x00d8f8`).
 */
bool ExtractUrlHostAndPath(
    const std::string& url,
    std::string* out_host,
    std::string* out_path) {
    if (out_host == nullptr || out_path == nullptr) {
        return false;
    }

    const size_t scheme_pos = url.find("://");
    if (scheme_pos == std::string::npos) {
        return false;
    }

    const size_t host_start = scheme_pos + 3;
    const size_t slash_pos = url.find('/', host_start);

    std::string host_part;
    std::string path_part;
    if (slash_pos == std::string::npos) {
        host_part = url.substr(host_start);
        path_part.clear();
    } else {
        host_part = url.substr(host_start, slash_pos - host_start);
        const size_t query_or_hash = url.find_first_of("?#", slash_pos);
        if (query_or_hash == std::string::npos) {
            path_part = url.substr(slash_pos);
        } else {
            path_part = url.substr(slash_pos, query_or_hash - slash_pos);
        }
    }

    const size_t colon_pos = host_part.find(':');
    if (colon_pos != std::string::npos) {
        host_part = host_part.substr(0, colon_pos);
    }

    if (host_part.empty()) {
        return false;
    }

    host_part = ToLowerAscii(host_part);
    if (!path_part.empty() && path_part.back() == '/') {
        path_part.pop_back();
    }

    *out_host = std::move(host_part);
    *out_path = std::move(path_part);
    return true;
}

/**
 * [EN] Reconstructed from `0x00da64..0x00dc5c` (`matchNetConfigRule`):
 *      1. Iterates through `rule.hosts` (`+0x00..+0x08`):
 *         - Checks wildcard prefix: if `rule_host.size() >= 2`, `(rule_host[0] == '-' || rule_host[0] == '*')`
 *           (in AArch64 at `0x00daf8`: `ldrb w10, [x8]; cmp w10, #0x2d ('-')` or `0x2a ('*')` and
 *           `ldrb w9, [x8, #1]; cmp w9, #0x2e ('.')`), extracts `suffix = rule_host.substr(1)`
 *           (e.g. `".tiktokv.com"`) and checks whether `host.size() >= suffix.size()` and
 *           `host.compare(host.size() - suffix.size(), suffix.size(), suffix) == 0`.
 *         - Otherwise checks exact equality `host == rule_host`.
 *      2. If no host in `rule.hosts` matches, returns `false`.
 *      3. Checks `rule.paths` (`+0x18..+0x20`):
 *         - If `rule.paths.empty()`, returns `true` immediately (`0x00dbc0`).
 *         - Otherwise iterates over `rule_path` in `rule.paths` and checks prefix match
 *           `path.rfind(rule_path, 0) == 0` (`0x00f6ec`). Returns `true` on first match.
 * [VN] Phục dựng từ `0x00da64..0x00dc5c` (`matchNetConfigRule`):
 *      1. Duyệt qua `rule.hosts` (`+0x00..+0x08`):
 *         - Kiểm tra tiền tố đại diện: nếu `rule_host.size() >= 2`, `(rule_host[0] == '-' || rule_host[0] == '*')`
 *           (trong AArch64 tại `0x00daf8`: `ldrb w10, [x8]; cmp w10, #0x2d ('-')` hoặc `0x2a ('*')` và
 *           `ldrb w9, [x8, #1]; cmp w9, #0x2e ('.')`), lấy `suffix = rule_host.substr(1)`
 *           (ví dụ `".tiktokv.com"`) rồi kiểm tra `host.size() >= suffix.size()` và
 *           `host.compare(host.size() - suffix.size(), suffix.size(), suffix) == 0`.
 *         - Ngược lại kiểm tra khớp chính xác `host == rule_host`.
 *      2. Nếu không có host nào trong `rule.hosts` khớp, trả về `false`.
 *      3. Kiểm tra `rule.paths` (`+0x18..+0x20`):
 *         - Nếu `rule.paths.empty()`, trả về `true` ngay lập tức (`0x00dbc0`).
 *         - Ngược lại duyệt qua từng `rule_path` trong `rule.paths` và kiểm tra khớp tiền tố
 *           `path.rfind(rule_path, 0) == 0` (`0x00f6ec`). Trả về `true` ngay khi khớp.
 */
bool MatchNetConfigRule(
    const NetConfig& rule,
    const std::string& host,
    const std::string& path) {
    bool host_matched = false;
    for (const std::string& pattern : rule.hosts) {
        if (pattern.size() >= 2 &&
            (pattern[0] == '-' || pattern[0] == '*') &&
            pattern[1] == '.') {
            const std::string suffix = pattern.substr(1);
            if (host.size() >= suffix.size() &&
                host.compare(host.size() - suffix.size(), suffix.size(), suffix) == 0) {
                host_matched = true;
                break;
            }
        } else if (host == pattern) {
            host_matched = true;
            break;
        }
    }

    if (!host_matched) {
        return false;
    }

    if (rule.paths.empty()) {
        return true;
    }

    for (const std::string& rule_path : rule.paths) {
        if (path.rfind(rule_path, 0) == 0) {
            return true;
        }
    }
    return false;
}

/**
 * [EN] Reconstructed from `0x00dc60..0x00e1d4` (`replenishDataflowId`):
 *      1. Extracts `(host, path)` from `url` via `ExtractUrlHostAndPath` (`0x00d660`).
 *         If extraction fails, returns `""`.
 *      2. Checks `repo.boot`: if `boot` is empty (`hosts.empty() && paths.empty()`),
 *         returns `"0x28000600"` (`kDfidTikTokFirstPartyEmpty`).
 *      3. If `MatchNetConfigRule(repo.boot, host, path)` is true, returns `repo.boot.dataflow_id`.
 *      4. Checks if `repo.ag` AND `repo.ag_special` are empty: if so, returns `"0x28000600"`.
 *      5. Iterates through `repo.ag_special` (`0x0282d8`): on first matching rule,
 *         returns `special_rule.dataflow_id`.
 *      6. Checks `MatchNetConfigRule(repo.ag, host, path)`: if true, returns `repo.ag.dataflow_id`.
 *      7. If no rule matched, returns `"0x28000602"` (`kDfidTikTokFirstPartyNoMatch`).
 * [VN] Phục dựng từ `0x00dc60..0x00e1d4` (`replenishDataflowId`):
 *      1. Trích xuất `(host, path)` từ `url` qua `ExtractUrlHostAndPath` (`0x00d660`).
 *         Nếu trích xuất thất bại, trả về `""`.
 *      2. Kiểm tra `repo.boot`: nếu `boot` rỗng (`hosts.empty() && paths.empty()`),
 *         trả về `"0x28000600"` (`kDfidTikTokFirstPartyEmpty`).
 *      3. Nếu `MatchNetConfigRule(repo.boot, host, path)` đúng, trả về `repo.boot.dataflow_id`.
 *      4. Kiểm tra nếu cả `repo.ag` VÀ `repo.ag_special` đều rỗng: trả về `"0x28000600"`.
 *      5. Duyệt qua `repo.ag_special` (`0x0282d8`): trả về `special_rule.dataflow_id` đầu tiên khớp.
 *      6. Kiểm tra `MatchNetConfigRule(repo.ag, host, path)`: nếu đúng, trả về `repo.ag.dataflow_id`.
 *      7. Nếu không khớp quy tắc nào, trả về `"0x28000602"` (`kDfidTikTokFirstPartyNoMatch`).
 */
std::string ReplenishFirstPartyDataflowId(const std::string& url) {
    std::string host;
    std::string path;
    if (!ExtractUrlHostAndPath(url, &host, &path)) {
        return std::string();
    }

    const NetConfigRepository& repo = GetNetConfigRepository();
    if (repo.boot.hosts.empty() && repo.boot.paths.empty()) {
        return kDfidTikTokFirstPartyEmpty;
    }

    if (MatchNetConfigRule(repo.boot, host, path)) {
        return repo.boot.dataflow_id;
    }

    if (repo.ag.hosts.empty() && repo.ag.paths.empty() && repo.ag_special.empty()) {
        return kDfidTikTokFirstPartyEmpty;
    }

    for (const NetConfig& special_rule : repo.ag_special) {
        if (MatchNetConfigRule(special_rule, host, path)) {
            return special_rule.dataflow_id;
        }
    }

    if (MatchNetConfigRule(repo.ag, host, path)) {
        return repo.ag.dataflow_id;
    }

    return kDfidTikTokFirstPartyNoMatch;
}

/**
 * [EN] Reconstructed from `0x00e1d8..0x00e550` (`assign3PDataflowId`):
 *      1. Extracts `(host, path)` from `url` via `ExtractUrlHostAndPath` (`0x00d660`).
 *         If extraction fails, returns `repo.third_party_fallback_dfid`.
 *      2. Iterates through `repo.third_party_config` (`0x0282f0`): if
 *         `MatchNetConfigRule(rule, host, path)` is true, returns `rule.dataflow_id`.
 *      3. Otherwise returns `repo.third_party_fallback_dfid` (`0x028308`).
 * [VN] Phục dựng từ `0x00e1d8..0x00e550` (`assign3PDataflowId`):
 *      1. Trích xuất `(host, path)` từ `url` qua `ExtractUrlHostAndPath` (`0x00d660`).
 *         Nếu thất bại, trả về `repo.third_party_fallback_dfid`.
 *      2. Duyệt qua `repo.third_party_config` (`0x0282f0`): nếu
 *         `MatchNetConfigRule(rule, host, path)` đúng, trả về `rule.dataflow_id`.
 *      3. Ngược lại trả về `repo.third_party_fallback_dfid` (`0x028308`).
 */
std::string AssignThirdPartyDataflowId(const std::string& url) {
    const NetConfigRepository& repo = GetNetConfigRepository();
    std::string host;
    std::string path;
    if (!ExtractUrlHostAndPath(url, &host, &path)) {
        return repo.third_party_fallback_dfid;
    }

    for (const NetConfig& rule : repo.third_party_config) {
        if (MatchNetConfigRule(rule, host, path)) {
            return rule.dataflow_id;
        }
    }

    return repo.third_party_fallback_dfid;
}

/**
 * [EN] Reconstructed from `0x00ca60..0x00ce04` (`parseDfidToInt`):
 *      1. If `dfid_str.empty()`, returns `-1` (`0xFFFFFFFF`).
 *      2. Lowercases `dfid_str` via `std::tolower` (`0x00cc78`) and checks if it starts
 *         with `"0x"` (`.rodata 0x01ad1f` via `rfind("0x", 0) == 0`).
 *      3. If it starts with `"0x"`, parses as unsigned hex via `std::stringstream` with
 *         `std::hex` (`ios_base::flags = (flags & ~0x4A) | 0x08` at `0x00cd38`) into
 *         `uint32_t value` (`operator>>(unsigned int&)` at `0x04070`).
 *      4. Otherwise parses decimal via `std::stoi` / `std::strtol`.
 *      5. On parse failure or out-of-range, returns `-1`.
 * [VN] Phục dựng từ `0x00ca60..0x00ce04` (`parseDfidToInt`):
 *      1. Nếu `dfid_str.empty()`, trả về `-1` (`0xFFFFFFFF`).
 *      2. Chuyển chữ thường `dfid_str` qua `std::tolower` (`0x00cc78`) và kiểm tra xem chuỗi
 *         có bắt đầu bằng `"0x"` không (`.rodata 0x01ad1f` qua `rfind("0x", 0) == 0`).
 *      3. Nếu bắt đầu bằng `"0x"`, phân tích số nguyên hệ 16 qua `std::stringstream` với
 *         `std::hex` (`ios_base::flags = (flags & ~0x4A) | 0x08` tại `0x00cd38`) vào
 *         `uint32_t value` (`operator>>(unsigned int&)` tại `0x04070`).
 *      4. Ngược lại phân tích số thập phân qua `std::stoi` / `std::strtol`.
 *      5. Nếu lỗi phân tích hoặc tràn số, trả về `-1`.
 */
int32_t ParseDataflowIdStringToInt(const std::string& dfid_str) {
    if (dfid_str.empty()) {
        return -1;
    }

    const std::string lowered = ToLowerAscii(dfid_str);
    if (lowered.rfind("0x", 0) == 0) {
        std::stringstream ss;
        ss << std::hex << lowered;
        uint32_t hex_val = 0;
        if (!(ss >> hex_val)) {
            return -1;
        }
        return static_cast<int32_t>(hex_val);
    }

    char* end_ptr = nullptr;
    const long dec_val = std::strtol(dfid_str.c_str(), &end_ptr, 10);
    if (end_ptr == dfid_str.c_str() || *end_ptr != '\0') {
        return -1;
    }
    return static_cast<int32_t>(dec_val);
}

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai
