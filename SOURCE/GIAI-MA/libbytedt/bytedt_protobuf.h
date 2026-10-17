// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Protobuf Model Serializer
// Bộ giải mã và mã hóa Protobuf cho mô hình ByteDT (model.pb)
//
// Matches Binary Schema:
//   - bytedt.protobuf.Model
//   - bytedt.protobuf.Tree
//   - bytedt.protobuf.Node
//   - bytedt.protobuf.Model.BoostingClassificationConfig
//   - bytedt.protobuf.Model.VotingClassificationConfig
//   - bytedt.protobuf.Model.MultiLabelClassificationConfig
// ======================================================================

#pragma once

#include "bytedt_models.h"
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <unordered_map>

namespace bytedt {
namespace protobuf {

/**
 * @brief Wire types in Google Protocol Buffers.
 * Các kiểu wire cơ bản trong định dạng Protocol Buffers.
 */
enum WireType {
    VARINT = 0,
    FIXED64 = 1,
    LENGTH_DELIMITED = 2,
    START_GROUP = 3,
    END_GROUP = 4,
    FIXED32 = 5
};

/**
 * @brief Zero-dependency CodedInputStream for reading protobuf byte streams.
 * Bộ giải mã luồng nhị phân Protobuf độc lập không phụ thuộc thư viện ngoài.
 */
class CodedInputStream {
private:
    const uint8_t* buffer_;
    size_t size_;
    size_t pos_;

public:
    CodedInputStream(const void* data, size_t size)
        : buffer_(reinterpret_cast<const uint8_t*>(data)), size_(size), pos_(0) {}

    bool has_more() const { return pos_ < size_; }
    size_t bytes_remaining() const { return (pos_ < size_) ? (size_ - pos_) : 0; }
    size_t current_position() const { return pos_; }

    bool read_varint64(uint64_t* value) {
        uint64_t result = 0;
        int shift = 0;
        while (pos_ < size_ && shift < 64) {
            uint8_t b = buffer_[pos_++];
            result |= static_cast<uint64_t>(b & 0x7F) << shift;
            if ((b & 0x80) == 0) {
                *value = result;
                return true;
            }
            shift += 7;
        }
        return false;
    }

    bool read_varint32(uint32_t* value) {
        uint64_t val64 = 0;
        if (!read_varint64(&val64)) return false;
        *value = static_cast<uint32_t>(val64);
        return true;
    }

    bool read_tag(uint32_t* field_number, WireType* wire_type) {
        uint32_t tag = 0;
        if (!read_varint32(&tag)) return false;
        *field_number = tag >> 3;
        *wire_type = static_cast<WireType>(tag & 0x07);
        return true;
    }

    bool read_float(float* val) {
        if (pos_ + 4 > size_) return false;
        uint32_t raw = static_cast<uint32_t>(buffer_[pos_]) |
                      (static_cast<uint32_t>(buffer_[pos_ + 1]) << 8) |
                      (static_cast<uint32_t>(buffer_[pos_ + 2]) << 16) |
                      (static_cast<uint32_t>(buffer_[pos_ + 3]) << 24);
        pos_ += 4;
        std::memcpy(val, &raw, sizeof(float));
        return true;
    }

    bool read_string(std::string* str, size_t len) {
        if (pos_ + len > size_) return false;
        str->assign(reinterpret_cast<const char*>(buffer_ + pos_), len);
        pos_ += len;
        return true;
    }

    bool skip_field(WireType wire_type) {
        switch (wire_type) {
            case VARINT: {
                uint64_t dummy;
                return read_varint64(&dummy);
            }
            case FIXED64:
                if (pos_ + 8 > size_) return false;
                pos_ += 8;
                return true;
            case LENGTH_DELIMITED: {
                uint64_t len = 0;
                if (!read_varint64(&len)) return false;
                if (pos_ + len > size_) return false;
                pos_ += len;
                return true;
            }
            case FIXED32:
                if (pos_ + 4 > size_) return false;
                pos_ += 4;
                return true;
            default:
                return false;
        }
    }
};

/**
 * @brief Zero-dependency CodedOutputStream for serializing models to Protobuf.
 * Bộ mã hóa luồng nhị phân Protobuf độc lập.
 */
class CodedOutputStream {
private:
    std::vector<uint8_t> buffer_;

public:
    CodedOutputStream() = default;

    const std::vector<uint8_t>& get_buffer() const { return buffer_; }

    void write_tag(uint32_t field_number, WireType wire_type) {
        uint32_t tag = (field_number << 3) | static_cast<uint32_t>(wire_type);
        write_varint32(tag);
    }

    void write_varint64(uint64_t val) {
        while (val >= 0x80) {
            buffer_.push_back(static_cast<uint8_t>((val & 0x7F) | 0x80));
            val >>= 7;
        }
        buffer_.push_back(static_cast<uint8_t>(val & 0x7F));
    }

    void write_varint32(uint32_t val) {
        write_varint64(static_cast<uint64_t>(val));
    }

    void write_float(float val) {
        uint32_t raw = 0;
        std::memcpy(&raw, &val, sizeof(float));
        buffer_.push_back(static_cast<uint8_t>(raw & 0xFF));
        buffer_.push_back(static_cast<uint8_t>((raw >> 8) & 0xFF));
        buffer_.push_back(static_cast<uint8_t>((raw >> 16) & 0xFF));
        buffer_.push_back(static_cast<uint8_t>((raw >> 24) & 0xFF));
    }

    void write_string(const std::string& str) {
        write_varint64(str.size());
        buffer_.insert(buffer_.end(), str.begin(), str.end());
    }

    void write_raw_bytes(const void* data, size_t size) {
        const uint8_t* p = reinterpret_cast<const uint8_t*>(data);
        buffer_.insert(buffer_.end(), p, p + size);
    }
};

/**
 * @brief High-level Protobuf Model Loader and Serializer.
 * Lớp chuyển đổi mô hình hai chiều từ định dạng protobuf byte buffer sang C++ BaseModel.
 */
class ModelParser {
public:
    /**
     * @brief Deserializes BaseModel from protobuf byte buffer.
     * Giải mã mô hình từ vùng đệm nhị phân Protobuf.
     */
    static std::shared_ptr<BaseModel> parse_from_buffer(const void* data, size_t size);

    /**
     * @brief Deserializes BaseModel from model file path.
     * Giải mã mô hình từ file trên đĩa.
     */
    static std::shared_ptr<BaseModel> parse_from_path(const char* filepath);

    /**
     * @brief Serializes BaseModel to protobuf byte buffer.
     * Mã hóa mô hình thành chuỗi byte Protobuf.
     */
    static std::vector<uint8_t> serialize_to_buffer(const BaseModel& model);

    /**
     * @brief Serializes BaseModel to file path.
     * Ghi mô hình thành file Protobuf trên đĩa.
     */
    static bool serialize_to_path(const BaseModel& model, const char* filepath);

private:
    static Tree parse_tree(CodedInputStream& stream, size_t tree_bytes);
    static std::shared_ptr<Node> parse_node(CodedInputStream& stream, size_t node_bytes,
                                            int32_t* left_id, int32_t* right_id);
};

} // namespace protobuf
} // namespace bytedt
