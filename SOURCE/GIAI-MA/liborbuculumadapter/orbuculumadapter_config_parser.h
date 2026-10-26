// ============================================================================
// File: orbuculumadapter_config_parser.h
// Target Binary: liborbuculumadapter.so (149,936 bytes)
// SHA-256: c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785
//
// [EN] Declarations for HTTP header parsers (RFC CRLF & KV '&'/'='), URL scheme
//      and host/path extractors, wildcard host & prefix path rule matching,
//      Dataflow ID replenishment (1P/3P & Pumbaa domain recognition), hex DFID
//      conversion, and atomic BlockSnapshot evaluation (0x008f98..0x00e600).
// [VN] Khai báo cho các bộ phân tích HTTP header (RFC CRLF & KV '&'/'='), bộ
//      trích xuất giao thức và host/path URL, bộ khớp quy tắc host đại diện &
//      tiền tố đường dẫn, bổ sung mã Dataflow ID (1P/3P & nhận diện tên miền
//      Pumbaa), chuyển đổi mã DFID hệ 16, và đánh giá BlockSnapshot nguyên tử
//      (0x008f98..0x00e600).
// ============================================================================

#ifndef NEXTAI_OPENCUT_ORBUCULUMADAPTER_CONFIG_PARSER_H_
#define NEXTAI_OPENCUT_ORBUCULUMADAPTER_CONFIG_PARSER_H_

#include "orbuculumadapter_types.h"

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

// ============================================================================
// 1. ATOMIC BLOCK SNAPSHOT MANAGEMENT (0x00b09c, 0x00b1a8, 0x00cfc0)
// ============================================================================

/**
 * @brief [EN] Atomically load current `std::shared_ptr<BlockSnapshot>` (0x00b09c).
 *        [VN] Đọc nguyên tử `std::shared_ptr<BlockSnapshot>` hiện hành (0x00b09c).
 */
std::shared_ptr<BlockSnapshot> GetBlockSnapshot();

/**
 * @brief [EN] Atomically swap `std::shared_ptr<BlockSnapshot>` at `.bss 0x028340` (0x00b1a8).
 *        [VN] Hoán đổi nguyên tử `std::shared_ptr<BlockSnapshot>` tại `.bss 0x028340` (0x00b1a8).
 */
void UpdateBlockSnapshot(std::shared_ptr<BlockSnapshot> new_snapshot);

/**
 * @brief [EN] Evaluate whether a native network validation result code and Dataflow ID
 *             require hard blocking (`0x00cfc0..0x00d27c`, called by `0x007174`).
 *        [VN] Đánh giá xem mã kết quả xác thực mạng native và Dataflow ID có cần
 *             chặn cứng hay không (`0x00cfc0..0x00d27c`, được gọi bởi `0x007174`).
 *
 * @param result_code [EN] Validation return code (`0` = pass, non-zero = violation)
 *                    [VN] Mã trả về xác thực (`0` = hợp lệ, khác 0 = vi phạm)
 * @param dfid        [EN] Dataflow ID string (compared case-insensitively via `tolower`)
 *                    [VN] Chuỗi Dataflow ID (so sánh không phân biệt hoa thường qua `tolower`)
 * @return `true` if the request must be blocked; `false` if allowed.
 */
bool EvaluateNetworkResultNeedBlock(int32_t result_code, const std::string& dfid);

// ============================================================================
// 2. HTTP HEADER PARSERS & SERIALIZER (0x00b99c, 0x00ba34, 0x00bda8, 0x010924)
// ============================================================================

/**
 * @brief [EN] Parse RFC-style HTTP headers separated by `\r\n` and `:` (0x00ba34).
 *             Trims leading/trailing spaces (`' '` and `'\t'`) on both keys and values.
 *        [VN] Phân tích HTTP header chuẩn RFC phân tách bởi `\r\n` và `:` (0x00ba34).
 *             Cắt bỏ khoảng trắng đầu/cuối (`' '` và `'\t'`) ở cả khóa và giá trị.
 */
std::map<std::string, std::string> ParseRfcHttpHeaders(const std::string& raw_headers);

/**
 * @brief [EN] Parse key-value headers separated by `\n` or `&` and `=` (0x00bda8).
 *             Requires at least one `'='` and no `"\r\n"` in the input string.
 *        [VN] Phân tích header khóa-giá trị phân tách bởi `\n` hoặc `&` và `=` (0x00bda8).
 *             Yêu cầu ít nhất một ký tự `'='` và không chứa `"\r\n"` trong chuỗi đầu vào.
 */
std::map<std::string, std::string> ParseKvHttpHeaders(const std::string& raw_headers);

/**
 * @brief [EN] Unified header parser dispatcher (0x00b99c): tries `ParseKvHttpHeaders`
 *             first, then falls back to `ParseRfcHttpHeaders` if empty.
 *        [VN] Bộ điều phối phân tích header hợp nhất (0x00b99c): thử `ParseKvHttpHeaders`
 *             trước, sau đó chuyển sang `ParseRfcHttpHeaders` nếu kết quả rỗng.
 */
std::map<std::string, std::string> ParseHttpHeadersUnified(const std::string& raw_headers);

/**
 * @brief [EN] Serialize `std::map<std::string, std::string>` headers into `"key:value\r\n"`
 *             lines for Java reporting (0x010924).
 *        [VN] Tuần tự hóa `std::map<std::string, std::string>` thành các dòng `"key:value\r\n"`
 *             để gửi báo cáo lên tầng Java (0x010924).
 */
std::string SerializeHeadersToRfcString(const std::map<std::string, std::string>& headers);

// ============================================================================
// 3. URL SCHEME FILTER, HOST/PATH PARSER & WILDCARD RULE MATCHER
//    (0x00c13c, 0x00ca60, 0x00d660, 0x00da64, 0x00dc60, 0x00e1d8)
// ============================================================================

/**
 * @brief [EN] Check if URL starts with any allowed compliance scheme prefix (0x00c13c).
 *             Uses `NetConfigRepository::compliance_prefix_list` if non-empty; otherwise
 *             checks default 7 prefixes (`http://`, `https://`, `wss://`, `tcp://`,
 *             `udp://`, `tls://`, `quic://` at `.bss 0x028758`).
 *        [VN] Kiểm tra xem URL có bắt đầu bằng tiền tố giao thức tuân thủ hợp lệ không (0x00c13c).
 *             Sử dụng `NetConfigRepository::compliance_prefix_list` nếu không rỗng; ngược lại
 *             kiểm tra 7 tiền tố mặc định (`http://`, `https://`, `wss://`, `tcp://`,
 *             `udp://`, `tls://`, `quic://` tại `.bss 0x028758`).
 */
bool IsUrlMatchingComplianceScheme(const std::string& url);

/**
 * @brief [EN] Extract lowercase host (stripping `:port`) and normalized path (before `?` or `#`,
 *             removing trailing `/`) from a URL string (0x00d660..0x00da60).
 *        [VN] Trích xuất host chữ thường (bỏ `:port`) và đường dẫn chuẩn hóa (trước `?` hoặc `#`,
 *             bỏ dấu `/` ở cuối) từ chuỗi URL (0x00d660..0x00da60).
 *
 * @return `true` if scheme `"://"` and non-empty host were extracted; `false` otherwise.
 */
bool ExtractUrlHostAndPath(
    const std::string& url,
    std::string* out_host,
    std::string* out_path);

/**
 * @brief [EN] Match extracted `host` and `path` against a `NetConfig` rule (0x00da64..0x00dc5c).
 *             - Host matching: exact match OR suffix match if pattern starts with `'-'` or `'*'`
 *               followed by `'.'` (i.e., `pattern.substr(1)` matches suffix of `host`).
 *             - Path matching: empty `rule.paths` matches any path; otherwise `path` must
 *               start with at least one `rule_path` (`path.rfind(rule_path, 0) == 0`).
 *        [VN] Đối sánh `host` và `path` đã trích xuất với một quy tắc `NetConfig` (0x00da64..0x00dc5c).
 *             - Khớp host: khớp chính xác HOẶC khớp hậu tố nếu mẫu bắt đầu bằng `'-'` hoặc `'*'`
 *               theo sau bởi `'.'` (tức `pattern.substr(1)` khớp hậu tố của `host`).
 *             - Khớp path: `rule.paths` rỗng sẽ khớp mọi đường dẫn; ngược lại `path` phải
 *               bắt đầu bằng ít nhất một `rule_path` (`path.rfind(rule_path, 0) == 0`).
 */
bool MatchNetConfigRule(
    const NetConfig& rule,
    const std::string& host,
    const std::string& path);

/**
 * @brief [EN] Replenish 1st-party Dataflow ID from `NetConfigRepository` (`boot`, `ag_special`, `ag`)
 *             or default error DFIDs (`"0x28000600"` / `"0x28000602"`) (0x00dc60..0x00e1d4).
 *        [VN] Bổ sung mã Dataflow ID bên thứ nhất từ `NetConfigRepository` (`boot`, `ag_special`, `ag`)
 *             hoặc mã DFID lỗi mặc định (`"0x28000600"` / `"0x28000602"`) (0x00dc60..0x00e1d4).
 */
std::string ReplenishFirstPartyDataflowId(const std::string& url);

/**
 * @brief [EN] Assign 3rd-party Dataflow ID by matching `third_party_config` rules or falling
 *             back to `third_party_fallback_dfid` (0x00e1d8..0x00e550).
 *        [VN] Gán mã Dataflow ID bên thứ ba bằng cách khớp danh sách quy tắc `third_party_config`
 *             hoặc dùng `third_party_fallback_dfid` dự phòng (0x00e1d8..0x00e550).
 */
std::string AssignThirdPartyDataflowId(const std::string& url);

/**
 * @brief [EN] Parse a Dataflow ID string (hex `"0x..."` via `std::stringstream` `std::hex`
 *             or decimal via `std::stoi`) into a 32-bit integer (0x00ca60..0x00ce04).
 *             Returns `-1` (`0xFFFFFFFF`) if empty or invalid.
 *        [VN] Phân tích chuỗi Dataflow ID (hệ 16 `"0x..."` qua `std::stringstream` `std::hex`
 *             hoặc hệ 10 qua `std::stoi`) thành số nguyên 32-bit (0x00ca60..0x00ce04).
 *             Trả về `-1` (`0xFFFFFFFF`) nếu chuỗi rỗng hoặc không hợp lệ.
 */
int32_t ParseDataflowIdStringToInt(const std::string& dfid_str);

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_ORBUCULUMADAPTER_CONFIG_PARSER_H_
