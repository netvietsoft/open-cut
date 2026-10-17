/**
 * @file avmdlbase_url_helper.h
 * @brief ByteDance Mobile Download Base - URL Parsing & URI Rewriting Engine.
 *        Bộ phân tích cú pháp URL media và định tuyến URI cho libavmdlbase.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef AVMDLBASE_URL_HELPER_H
#define AVMDLBASE_URL_HELPER_H

#include "avmdlbase_types.h"
#include <string>
#include <map>

namespace com {
namespace ss {
namespace ttmio {

/**
 * @brief Parsed URL component decomposition structure
 *        Cấu trúc phân rã thành phần URL
 */
struct ParsedUrl {
    std::string scheme;
    std::string host;
    int32_t     port = 80;
    std::string path = "/";
    std::string query;
    std::string fragment;
    bool        isValid = false;
    bool        isMdlProtocol = false;
    std::map<std::string, std::string> queryParams;
};

/**
 * @brief MIOHttpRequestHelper: URL parsing logic matching binary offset 0x041250 (1,216 bytes).
 *        Bộ phân tích URL khớp chính xác thuật toán nhị phân trong libavmdlbase.so.
 */
class MIOHttpRequestHelper {
public:
    /**
     * @brief Parses full media URL into decomposed components.
     *        Phân tích URL đầy đủ thành các thành phần scheme, host, port, path, query.
     *        Opcode 0x041250 (1,216 bytes).
     */
    static ParsedUrl parseUrl(const std::string& url);

    /**
     * @brief Rewrites URI for proxy redirection or cache key injection.
     *        Viết lại URI phục vụ điều phối bộ đệm cache cục bộ.
     */
    static std::string rewriteUri(const std::string& originUri, const std::string& fileKey);

    /**
     * @brief Normalizes path and resolves relative segments (/../, /./).
     *        Chuẩn hóa đường dẫn tệp tin media.
     */
    static std::string normalizePath(const std::string& path);
};

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // AVMDLBASE_URL_HELPER_H
