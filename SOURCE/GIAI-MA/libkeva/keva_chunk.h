/**
 * @file keva_chunk.h
 * @brief ByteDance Keva Chunk Serialization & Low-Level Storage Header.
 *        Định dạng phân đoạn lưu trữ và tuần tự hóa dữ liệu Keva.
 */

#ifndef GECKOX_KEVA_CHUNK_H
#define GECKOX_KEVA_CHUNK_H

#include "keva_types.h"
#include <vector>
#include <string>

namespace nextai {
namespace opencut {
namespace keva {

/**
 * @brief Keva Chunk Formatter & Packer
 *        Bộ đóng gói và định dạng payload dữ liệu Keva
 */
class KevaChunkFormatter {
public:
    static std::vector<uint8_t> packInt(const std::string& key, int32_t val);
    static std::vector<uint8_t> packBool(const std::string& key, bool val);
    static std::vector<uint8_t> packLong(const std::string& key, int64_t val);
    static std::vector<uint8_t> packFloat(const std::string& key, float val);
    static std::vector<uint8_t> packDouble(const std::string& key, double val);
    static std::vector<uint8_t> packString(const std::string& key, const std::string& val);
    static std::vector<uint8_t> packBytes(const std::string& key, const uint8_t* bytes, size_t length);
    static std::vector<uint8_t> packStringArray(const std::string& key, const std::vector<std::string>& array);

    static bool unpackChunk(
        const uint8_t* buffer,
        size_t bufferLen,
        std::string& outKey,
        KevaDataType& outType,
        KevaEntry& outEntry
    );
};

} // namespace keva
} // namespace opencut
} // namespace nextai

#endif // GECKOX_KEVA_CHUNK_H
