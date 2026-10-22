/**
 * @file keva_chunk.cpp
 * @brief ByteDance Keva Chunk Serialization Implementation.
 *        Hiện thực mã nguồn tuần tự hóa phân đoạn Keva.
 */

#include "keva_chunk.h"
#include <chrono>

namespace nextai {
namespace opencut {
namespace keva {

uint32_t calculateKevaCRC32(const uint8_t* data, size_t length) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; ++i) {
        crc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ (0xEDB88320 & (-(crc & 1)));
        }
    }
    return ~crc;
}

std::vector<uint8_t> KevaChunkFormatter::packInt(const std::string& key, int32_t val) {
    KevaChunkHeader header;
    header.keyLength = static_cast<uint16_t>(key.size());
    header.valueLength = sizeof(int32_t);
    header.type = KEVA_TYPE_INT;
    header.flags = 0x01;
    header.crc32 = calculateKevaCRC32(reinterpret_cast<const uint8_t*>(&val), sizeof(val));
    header.timestamp = static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count()
    );

    std::vector<uint8_t> out(sizeof(header) + key.size() + sizeof(val));
    std::memcpy(out.data(), &header, sizeof(header));
    std::memcpy(out.data() + sizeof(header), key.data(), key.size());
    std::memcpy(out.data() + sizeof(header) + key.size(), &val, sizeof(val));
    return out;
}

std::vector<uint8_t> KevaChunkFormatter::packBool(const std::string& key, bool val) {
    uint8_t byteVal = val ? 1 : 0;
    KevaChunkHeader header;
    header.keyLength = static_cast<uint16_t>(key.size());
    header.valueLength = 1;
    header.type = KEVA_TYPE_BOOL;
    header.flags = 0x01;
    header.crc32 = calculateKevaCRC32(&byteVal, 1);
    header.timestamp = 0;

    std::vector<uint8_t> out(sizeof(header) + key.size() + 1);
    std::memcpy(out.data(), &header, sizeof(header));
    std::memcpy(out.data() + sizeof(header), key.data(), key.size());
    out[sizeof(header) + key.size()] = byteVal;
    return out;
}

std::vector<uint8_t> KevaChunkFormatter::packLong(const std::string& key, int64_t val) {
    KevaChunkHeader header;
    header.keyLength = static_cast<uint16_t>(key.size());
    header.valueLength = sizeof(int64_t);
    header.type = KEVA_TYPE_LONG;
    header.flags = 0x01;
    header.crc32 = calculateKevaCRC32(reinterpret_cast<const uint8_t*>(&val), sizeof(val));
    header.timestamp = 0;

    std::vector<uint8_t> out(sizeof(header) + key.size() + sizeof(val));
    std::memcpy(out.data(), &header, sizeof(header));
    std::memcpy(out.data() + sizeof(header), key.data(), key.size());
    std::memcpy(out.data() + sizeof(header) + key.size(), &val, sizeof(val));
    return out;
}

std::vector<uint8_t> KevaChunkFormatter::packFloat(const std::string& key, float val) {
    KevaChunkHeader header;
    header.keyLength = static_cast<uint16_t>(key.size());
    header.valueLength = sizeof(float);
    header.type = KEVA_TYPE_FLOAT;
    header.flags = 0x01;
    header.crc32 = calculateKevaCRC32(reinterpret_cast<const uint8_t*>(&val), sizeof(val));
    header.timestamp = 0;

    std::vector<uint8_t> out(sizeof(header) + key.size() + sizeof(val));
    std::memcpy(out.data(), &header, sizeof(header));
    std::memcpy(out.data() + sizeof(header), key.data(), key.size());
    std::memcpy(out.data() + sizeof(header) + key.size(), &val, sizeof(val));
    return out;
}

std::vector<uint8_t> KevaChunkFormatter::packDouble(const std::string& key, double val) {
    KevaChunkHeader header;
    header.keyLength = static_cast<uint16_t>(key.size());
    header.valueLength = sizeof(double);
    header.type = KEVA_TYPE_DOUBLE;
    header.flags = 0x01;
    header.crc32 = calculateKevaCRC32(reinterpret_cast<const uint8_t*>(&val), sizeof(val));
    header.timestamp = 0;

    std::vector<uint8_t> out(sizeof(header) + key.size() + sizeof(val));
    std::memcpy(out.data(), &header, sizeof(header));
    std::memcpy(out.data() + sizeof(header), key.data(), key.size());
    std::memcpy(out.data() + sizeof(header) + key.size(), &val, sizeof(val));
    return out;
}

std::vector<uint8_t> KevaChunkFormatter::packString(const std::string& key, const std::string& val) {
    KevaChunkHeader header;
    header.keyLength = static_cast<uint16_t>(key.size());
    header.valueLength = static_cast<uint32_t>(val.size());
    header.type = KEVA_TYPE_STRING;
    header.flags = 0x01;
    header.crc32 = calculateKevaCRC32(reinterpret_cast<const uint8_t*>(val.data()), val.size());
    header.timestamp = 0;

    std::vector<uint8_t> out(sizeof(header) + key.size() + val.size());
    std::memcpy(out.data(), &header, sizeof(header));
    std::memcpy(out.data() + sizeof(header), key.data(), key.size());
    std::memcpy(out.data() + sizeof(header) + key.size(), val.data(), val.size());
    return out;
}

std::vector<uint8_t> KevaChunkFormatter::packBytes(const std::string& key, const uint8_t* bytes, size_t length) {
    KevaChunkHeader header;
    header.keyLength = static_cast<uint16_t>(key.size());
    header.valueLength = static_cast<uint32_t>(length);
    header.type = KEVA_TYPE_BYTES;
    header.flags = 0x01;
    header.crc32 = calculateKevaCRC32(bytes, length);
    header.timestamp = 0;

    std::vector<uint8_t> out(sizeof(header) + key.size() + length);
    std::memcpy(out.data(), &header, sizeof(header));
    std::memcpy(out.data() + sizeof(header), key.data(), key.size());
    std::memcpy(out.data() + sizeof(header) + key.size(), bytes, length);
    return out;
}

std::vector<uint8_t> KevaChunkFormatter::packStringArray(const std::string& key, const std::vector<std::string>& array) {
    // Format: uint32_t count, then for each string: uint32_t len + string bytes
    size_t payloadSize = sizeof(uint32_t);
    for (const auto& s : array) {
        payloadSize += sizeof(uint32_t) + s.size();
    }

    std::vector<uint8_t> payload(payloadSize);
    uint32_t count = static_cast<uint32_t>(array.size());
    std::memcpy(payload.data(), &count, sizeof(count));
    size_t off = sizeof(count);
    for (const auto& s : array) {
        uint32_t slen = static_cast<uint32_t>(s.size());
        std::memcpy(payload.data() + off, &slen, sizeof(slen));
        off += sizeof(slen);
        std::memcpy(payload.data() + off, s.data(), slen);
        off += slen;
    }

    KevaChunkHeader header;
    header.keyLength = static_cast<uint16_t>(key.size());
    header.valueLength = static_cast<uint32_t>(payloadSize);
    header.type = KEVA_TYPE_STRING_ARRAY;
    header.flags = 0x01;
    header.crc32 = calculateKevaCRC32(payload.data(), payloadSize);
    header.timestamp = 0;

    std::vector<uint8_t> out(sizeof(header) + key.size() + payloadSize);
    std::memcpy(out.data(), &header, sizeof(header));
    std::memcpy(out.data() + sizeof(header), key.data(), key.size());
    std::memcpy(out.data() + sizeof(header) + key.size(), payload.data(), payloadSize);
    return out;
}

bool KevaChunkFormatter::unpackChunk(
    const uint8_t* buffer,
    size_t bufferLen,
    std::string& outKey,
    KevaDataType& outType,
    KevaEntry& outEntry
) {
    if (!buffer || bufferLen < sizeof(KevaChunkHeader)) return false;

    KevaChunkHeader header;
    std::memcpy(&header, buffer, sizeof(header));

    if (bufferLen < sizeof(header) + header.keyLength + header.valueLength) return false;

    outKey.assign(reinterpret_cast<const char*>(buffer + sizeof(header)), header.keyLength);
    outType = static_cast<KevaDataType>(header.type);

    const uint8_t* valPtr = buffer + sizeof(header) + header.keyLength;

    outEntry.key = outKey;
    outEntry.type = outType;

    switch (outType) {
        case KEVA_TYPE_INT:
            if (header.valueLength == sizeof(int32_t)) {
                int32_t v;
                std::memcpy(&v, valPtr, sizeof(v));
                outEntry.intValue = v;
            }
            break;
        case KEVA_TYPE_BOOL:
            if (header.valueLength == 1) {
                outEntry.intValue = (*valPtr != 0) ? 1 : 0;
            }
            break;
        case KEVA_TYPE_LONG:
            if (header.valueLength == sizeof(int64_t)) {
                int64_t v;
                std::memcpy(&v, valPtr, sizeof(v));
                outEntry.intValue = v;
            }
            break;
        case KEVA_TYPE_FLOAT:
            if (header.valueLength == sizeof(float)) {
                float v;
                std::memcpy(&v, valPtr, sizeof(v));
                outEntry.doubleValue = v;
            }
            break;
        case KEVA_TYPE_DOUBLE:
            if (header.valueLength == sizeof(double)) {
                double v;
                std::memcpy(&v, valPtr, sizeof(v));
                outEntry.doubleValue = v;
            }
            break;
        case KEVA_TYPE_STRING:
            outEntry.stringValue.assign(reinterpret_cast<const char*>(valPtr), header.valueLength);
            break;
        case KEVA_TYPE_BYTES:
            outEntry.bytesValue.assign(valPtr, valPtr + header.valueLength);
            break;
        case KEVA_TYPE_STRING_ARRAY:
            if (header.valueLength >= sizeof(uint32_t)) {
                uint32_t count = 0;
                std::memcpy(&count, valPtr, sizeof(count));
                size_t off = sizeof(count);
                for (uint32_t i = 0; i < count && off + sizeof(uint32_t) <= header.valueLength; ++i) {
                    uint32_t slen = 0;
                    std::memcpy(&slen, valPtr + off, sizeof(slen));
                    off += sizeof(slen);
                    if (off + slen <= header.valueLength) {
                        outEntry.stringArrayValue.push_back(
                            std::string(reinterpret_cast<const char*>(valPtr + off), slen)
                        );
                        off += slen;
                    }
                }
            }
            break;
        default:
            return false;
    }
    return true;
}

} // namespace keva
} // namespace opencut
} // namespace nextai
