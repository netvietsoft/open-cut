/**
 * @file avmdlbase_http_helper.h
 * @brief ByteDance Mobile Download Base - HTTP Response Header & Chunk Parsing.
 *        Bộ phân tích tiêu đề HTTP và xử lý phân đoạn Chunked trong libavmdlbase.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef AVMDLBASE_HTTP_HELPER_H
#define AVMDLBASE_HTTP_HELPER_H

#include "avmdlbase_types.h"
#include <string>
#include <vector>

namespace com {
namespace ss {
namespace ttmio {

/**
 * @brief MIOHttpResponseHelper: Implementation matching binary offset 0x043f24 (1,520 bytes).
 *        Bộ phân tích phản hồi HTTP chuẩn xác trong libavmdlbase.so.
 */
class MIOHttpResponseHelper {
public:
    /**
     * @brief Parses full raw HTTP response header block.
     *        Phân tích khối tiêu đề phản hồi HTTP thô.
     *        Opcode 0x043f24 (1,520 bytes).
     */
    static MIOHttpResponseInfo parseHeader(const std::string& rawHeader);

    /**
     * @brief Formats an HTTP Range request header string.
     *        Định dạng tiêu đề Range cho yêu cầu tải từng phần (Partial Request).
     *        Ví dụ: "Range: bytes=1048576-2097151"
     */
    static std::string formatRangeHeader(int64_t start, int64_t end);

    /**
     * @brief Parses single chunk in Transfer-Encoding: chunked stream.
     *        Xử lý đọc từng phân đoạn chunk HTTP (opcode 0x0466a4, 572 bytes).
     */
    static size_t readSingleChunkData(const uint8_t* stream, size_t streamLen,
                                      uint8_t* outData, size_t outCapacity,
                                      size_t& bytesConsumed, bool& isLastChunk);
};

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // AVMDLBASE_HTTP_HELPER_H
