/**
 * @file avmdlbase_http_helper.cpp
 * @brief ByteDance Mobile Download Base - HTTP Response Header & Chunk Parsing Implementations.
 *        Cài đặt chi tiết giải thuật phân tích tiêu đề HTTP và xử lý chunk stream.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "avmdlbase_http_helper.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstring>

namespace com {
namespace ss {
namespace ttmio {

static inline std::string trimString(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

MIOHttpResponseInfo MIOHttpResponseHelper::parseHeader(const std::string& rawHeader) {
    MIOHttpResponseInfo info;
    if (rawHeader.empty()) return info;

    std::istringstream stream(rawHeader);
    std::string line;

    // 1. Parse Status Line (e.g., HTTP/1.1 200 OK or HTTP/2 206)
    if (std::getline(stream, line)) {
        line = trimString(line);
        size_t space1 = line.find(' ');
        if (space1 != std::string::npos) {
            size_t space2 = line.find(' ', space1 + 1);
            std::string codeStr = (space2 != std::string::npos) ?
                                  line.substr(space1 + 1, space2 - space1 - 1) :
                                  line.substr(space1 + 1);
            try {
                info.statusCode = std::stoi(codeStr);
            } catch (...) {
                info.statusCode = 0;
            }
        }
    }

    info.isPartialContent = (info.statusCode == 206);

    // 2. Parse Key-Value Header Lines
    while (std::getline(stream, line)) {
        line = trimString(line);
        if (line.empty()) continue;

        size_t colon = line.find(':');
        if (colon == std::string::npos) continue;

        std::string key = trimString(line.substr(0, colon));
        std::string value = trimString(line.substr(colon + 1));

        std::string lowerKey = key;
        std::transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        info.headers[lowerKey] = value;

        // Specific ByteDance CDN & HTTP protocol parsing
        if (lowerKey == "content-length") {
            try {
                info.contentLength = std::stoll(value);
            } catch (...) {}
        } else if (lowerKey == "content-type") {
            info.contentType = value;
        } else if (lowerKey == "server") {
            info.server = value;
        } else if (lowerKey == "x-tt-trace-id" || lowerKey == "x-tt-logid") {
            info.traceId = value;
        } else if (lowerKey == "transfer-encoding") {
            std::string lowerVal = value;
            std::transform(lowerVal.begin(), lowerVal.end(), lowerVal.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            if (lowerVal.find("chunked") != std::string::npos) {
                info.isChunked = true;
            }
        } else if (lowerKey == "content-range") {
            // Format: bytes 1048576-2097151/52428800 or bytes 0-100/*
            size_t bytesPos = value.find("bytes ");
            if (bytesPos != std::string::npos) {
                std::string rangeSpec = value.substr(bytesPos + 6);
                size_t dash = rangeSpec.find('-');
                size_t slash = rangeSpec.find('/');
                if (dash != std::string::npos && slash != std::string::npos && dash < slash) {
                    try {
                        info.rangeStart = std::stoll(rangeSpec.substr(0, dash));
                        info.rangeEnd = std::stoll(rangeSpec.substr(dash + 1, slash - dash - 1));
                        std::string totalStr = rangeSpec.substr(slash + 1);
                        if (totalStr != "*") {
                            info.rangeTotal = std::stoll(totalStr);
                        }
                    } catch (...) {}
                }
            }
        }
    }

    return info;
}

std::string MIOHttpResponseHelper::formatRangeHeader(int64_t start, int64_t end) {
    std::string header = "Range: bytes=" + std::to_string(start) + "-";
    if (end >= start) {
        header += std::to_string(end);
    }
    return header;
}

size_t MIOHttpResponseHelper::readSingleChunkData(const uint8_t* stream, size_t streamLen,
                                                  uint8_t* outData, size_t outCapacity,
                                                  size_t& bytesConsumed, bool& isLastChunk) {
    bytesConsumed = 0;
    isLastChunk = false;
    if (!stream || streamLen == 0 || !outData || outCapacity == 0) return 0;

    // Search for CRLF marking end of hex chunk size
    const char* str = reinterpret_cast<const char*>(stream);
    size_t lineEnd = 0;
    while (lineEnd + 1 < streamLen) {
        if (str[lineEnd] == '\r' && str[lineEnd + 1] == '\n') break;
        lineEnd++;
    }

    if (lineEnd + 1 >= streamLen) {
        return 0; // Incomplete header line
    }

    std::string hexLenStr(str, lineEnd);
    size_t chunkSize = 0;
    try {
        chunkSize = std::stoul(hexLenStr, nullptr, 16);
    } catch (...) {
        return 0; // Malformed chunk header
    }

    size_t dataStart = lineEnd + 2;
    if (chunkSize == 0) {
        // Last chunk indicator
        isLastChunk = true;
        bytesConsumed = dataStart + ((dataStart + 1 < streamLen && str[dataStart] == '\r' && str[dataStart + 1] == '\n') ? 2 : 0);
        return 0;
    }

    if (dataStart + chunkSize > streamLen) {
        return 0; // Full chunk payload not arrived yet
    }

    size_t copyBytes = std::min(chunkSize, outCapacity);
    std::memcpy(outData, stream + dataStart, copyBytes);

    size_t totalConsumed = dataStart + chunkSize;
    // Skip trailing CRLF after chunk data
    if (totalConsumed + 1 < streamLen && str[totalConsumed] == '\r' && str[totalConsumed + 1] == '\n') {
        totalConsumed += 2;
    }

    bytesConsumed = totalConsumed;
    return copyBytes;
}

} // namespace ttmio
} // namespace ss
} // namespace com
