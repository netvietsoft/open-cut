// ============================================================================
// Clean-Room C++17 ABI & Data Structures for libavmdlv2.so (Target 114 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho libavmdlv2.so (Mục tiêu 114 / 169)
// Binary Size: 1,411,344 bytes | SHA-256: f548a1a3303de5943289b2b467c20469733ff8b5c107a0aa1b784a9c01f5b93d
// .dynsym: 315 Exported Symbols @ 0x001ff8 | .eh_frame_hdr: 11 FDEs @ 0x1489d4
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <atomic>

namespace com {
namespace ss {
namespace ttmio {

// Constants verified directly from AArch64 opcodes
// Các hằng số xác minh trực tiếp từ mã máy AArch64
constexpr size_t kMDLMessageSlotStrideBytes = 0x30;      // 48 bytes per slot @ 0x05dae8 (add x20, x20, #0x30)
constexpr size_t kMDLMessageMaxSlots = 64;               // cmp w22, #0x3f @ 0x05dfa0; cmp x20, #0xc10 @ 0x05daec
constexpr size_t kMDLMessageCountOffset = 0xC00;         // str wzr, [x19, #0xc00] @ 0x05daf4
constexpr size_t kMDLSingletonsHolderSizeBytes = 0x78;   // 120 bytes @ 0x05e884 (mov w0, #0x78)
constexpr size_t kMDLConfigCenterSizeBytes = 0xA00;      // 2,560 bytes @ 0x05e51c (mov w0, #0xa00)
constexpr size_t kMDLFileManagerNgV2SizeBytes = 0x528;   // 1,320 bytes @ 0x05e920 (mov w0, #0x528)
constexpr size_t kMDLFileManagerNgSizeBytes = 0x358;     // 856 bytes @ 0x05e940 (mov w0, #0x358)
constexpr size_t kMDLFileManagerLegacySizeBytes = 0x350; // 848 bytes @ 0x05e954 (mov w0, #0x350)

enum class TrainingDataType : int32_t {
    RTT = 0,
    BANDWIDTH = 1,
    LOSS_RATE = 2
};

enum class ReqProtoType : int32_t {
    HTTP_1_1 = 1,
    HTTP_2 = 2,
    QUIC = 3
};

enum class MDLIoTaskInfoKey : int32_t {
    DOWNLOAD_SPEED = 0,
    CACHE_HIT_SIZE = 1,
    TOTAL_CONTENT_LEN = 2
};

struct MIOPairValue {
    int64_t first{0};
    int64_t second{0};
};

class MIOObject {
public:
    virtual ~MIOObject() = default;
};

// Exact 48-byte (0x30) entry slot inside MDLMessage (0x05dacc..0x05e4cc)
// Khe mục 48-byte (0x30) chuẩn bên trong MDLMessage (0x05dacc..0x05e4cc)
struct MDLMessageSlot {
    int32_t value_type{0};        // +0x00 (1=int32, 2=int64, 3=string, 4=pair, 5=object, 6=uint64)
    int32_t reserved_04{0};       // +0x04
    std::string key;              // +0x08
    int64_t int_val{0};           // +0x10
    uint64_t uint_val{0};         // +0x18
    std::string str_val;          // +0x20
    MIOPairValue pair_val{};
    MIOObject* obj_val{nullptr};
};

// Exact 16-byte binary ID / MD5 hash wrapper (0x116640..0x116b08)
// Bộ bọc ID nhị phân / MD5 16-byte chuẩn (0x116640..0x116b08)
class ID {
public:
    ID() noexcept;
    explicit ID(uint8_t* raw_bytes) noexcept;
    explicit ID(const std::string& hex_str);

    bool parse(const std::string& hex_str);
    static int32_t ctoi(char c) noexcept;
    std::string toStr() const;
    static void BCDtoASCII(const uint8_t* bcd, int32_t len, char* out_ascii) noexcept;
    std::string toLogStr() const;
    bool isEmpty() const noexcept;
    void reset() noexcept;
    uint8_t* getBuf() noexcept { return buf_; }

    ID& operator=(const ID& other) noexcept;
    bool operator==(const ID& other) const noexcept;
    bool operator!=(const ID& other) const noexcept;
    bool operator<(const ID& other) const noexcept;

private:
    uint8_t buf_[16]{0};
};

// Link Quality Sample Info (0x108498..0x1085f8)
// Thông tin mẫu chất lượng liên kết (0x108498..0x1085f8)
struct MDLLinkQualitySampleInfo {
    bool is_quic{false};
    int64_t rtt_ms{0};
    int64_t bw_bps{0};
    int64_t loss_ppm{0};
    int32_t status_code{0};
    std::string host;
    int64_t sample_ts{0};
    int32_t net_type{0};

    MDLLinkQualitySampleInfo() = default;
    MDLLinkQualitySampleInfo(bool quic, int64_t rtt, int64_t bw, int64_t loss,
                             int32_t code, const char* h, int64_t ts, int32_t net);
    MDLLinkQualitySampleInfo(const MDLLinkQualitySampleInfo& other) = default;
    MDLLinkQualitySampleInfo& operator=(const MDLLinkQualitySampleInfo& other) = default;
    ~MDLLinkQualitySampleInfo() = default;
    void printInfo(const char* tag) const;
};

} // namespace ttmio
} // namespace ss
} // namespace com
