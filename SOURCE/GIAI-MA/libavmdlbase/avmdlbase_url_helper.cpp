/**
 * @file avmdlbase_url_helper.cpp
 * @brief ByteDance Mobile Download Base - URL Parsing & URI Rewriting Implementations.
 *        Cài đặt chi tiết giải thuật phân tích URL media và định tuyến URI.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "avmdlbase_url_helper.h"
#include <algorithm>
#include <cctype>
#include <sstream>

namespace com {
namespace ss {
namespace ttmio {

ParsedUrl MIOHttpRequestHelper::parseUrl(const std::string& url) {
    ParsedUrl result;
    if (url.empty()) return result;

    size_t pos = 0;
    size_t urlLen = url.length();

    // 1. Parse Scheme (e.g., http://, https://, mdl://, file://)
    size_t schemeEnd = url.find("://");
    if (schemeEnd != std::string::npos) {
        result.scheme = url.substr(0, schemeEnd);
        std::transform(result.scheme.begin(), result.scheme.end(), result.scheme.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        pos = schemeEnd + 3;
    } else {
        // Fallback default scheme
        result.scheme = "http";
    }

    result.isMdlProtocol = (result.scheme == "mdl");

    // Default port assignment based on scheme
    if (result.scheme == "https") {
        result.port = 443;
    } else if (result.scheme == "http" || result.scheme == "mdl") {
        result.port = 80;
    } else if (result.scheme == "rtmp") {
        result.port = 1935;
    }

    // 2. Parse Authority (host + optional port)
    size_t pathStart = url.find_first_of("/?#", pos);
    std::string authority;
    if (pathStart != std::string::npos) {
        authority = url.substr(pos, pathStart - pos);
        pos = pathStart;
    } else {
        authority = url.substr(pos);
        pos = urlLen;
    }

    // Check for userinfo (username:password@host)
    size_t atPos = authority.find('@');
    if (atPos != std::string::npos) {
        authority = authority.substr(atPos + 1);
    }

    // Check for IPv6 bracketed address [::1]:port
    if (!authority.empty() && authority[0] == '[') {
        size_t closingBracket = authority.find(']');
        if (closingBracket != std::string::npos) {
            result.host = authority.substr(1, closingBracket - 1);
            if (closingBracket + 1 < authority.length() && authority[closingBracket + 1] == ':') {
                std::string portStr = authority.substr(closingBracket + 2);
                try {
                    result.port = std::stoi(portStr);
                } catch (...) {}
            }
        } else {
            result.host = authority;
        }
    } else {
        // Standard IPv4 or Domain Name: host:port
        size_t colonPos = authority.find(':');
        if (colonPos != std::string::npos) {
            result.host = authority.substr(0, colonPos);
            std::string portStr = authority.substr(colonPos + 1);
            try {
                result.port = std::stoi(portStr);
            } catch (...) {}
        } else {
            result.host = authority;
        }
    }

    // 3. Parse Path, Query, and Fragment
    if (pos < urlLen) {
        size_t hashPos = url.find('#', pos);
        std::string pathAndQuery;
        if (hashPos != std::string::npos) {
            pathAndQuery = url.substr(pos, hashPos - pos);
            result.fragment = url.substr(hashPos + 1);
        } else {
            pathAndQuery = url.substr(pos);
        }

        size_t qPos = pathAndQuery.find('?');
        if (qPos != std::string::npos) {
            result.path = pathAndQuery.substr(0, qPos);
            result.query = pathAndQuery.substr(qPos + 1);

            // Parse key-value query parameters
            std::istringstream qss(result.query);
            std::string pair;
            while (std::getline(qss, pair, '&')) {
                if (pair.empty()) continue;
                size_t eqPos = pair.find('=');
                if (eqPos != std::string::npos) {
                    std::string k = pair.substr(0, eqPos);
                    std::string v = pair.substr(eqPos + 1);
                    result.queryParams[k] = v;
                } else {
                    result.queryParams[pair] = "";
                }
            }
        } else {
            result.path = pathAndQuery;
        }
    }

    if (result.path.empty()) {
        result.path = "/";
    }

    result.isValid = !result.host.empty();
    return result;
}

std::string MIOHttpRequestHelper::rewriteUri(const std::string& originUri, const std::string& fileKey) {
    if (originUri.empty()) return "";

    ParsedUrl parsed = parseUrl(originUri);
    if (!parsed.isValid) return originUri;

    // ByteDance URI rewrite format for local caching proxy
    std::string rewritten = parsed.scheme + "://" + parsed.host;
    if ((parsed.scheme == "http" && parsed.port != 80) ||
        (parsed.scheme == "https" && parsed.port != 443)) {
        rewritten += ":" + std::to_string(parsed.port);
    }
    rewritten += parsed.path;

    // Append fileKey and cache tags
    bool hasQuery = !parsed.query.empty();
    rewritten += (hasQuery ? "?" + parsed.query : "");

    if (!fileKey.empty()) {
        rewritten += (hasQuery ? "&" : "?");
        rewritten += "fkey=" + fileKey;
        rewritten += "&bytedance_mdl=1";
    }

    if (!parsed.fragment.empty()) {
        rewritten += "#" + parsed.fragment;
    }

    return rewritten;
}

std::string MIOHttpRequestHelper::normalizePath(const std::string& path) {
    if (path.empty()) return "/";
    std::vector<std::string> parts;
    std::istringstream ss(path);
    std::string segment;

    while (std::getline(ss, segment, '/')) {
        if (segment.empty() || segment == ".") continue;
        if (segment == "..") {
            if (!parts.empty()) parts.pop_back();
        } else {
            parts.push_back(segment);
        }
    }

    std::string normalized;
    for (const auto& p : parts) {
        normalized += "/" + p;
    }
    return normalized.empty() ? "/" : normalized;
}

} // namespace ttmio
} // namespace ss
} // namespace com
