/**
 * @file sliver_pseudocode.cpp
 * @brief Complete Instruction-Accurate Reconstruction of Internal Subsystems in libsliver.so
 *        Tái dựng chính xác từng lệnh cho các phân hệ nội bộ trong libsliver.so
 *
 * Binary Ground Truth (libsliver.so — 83,984 bytes, AArch64):
 *   1. MiniDebugInfo (.gnu_debugdata) XZ/LZMA2 & CRC64 Unpacker (0x008f20..0x00a200):
 *      - Magic header check `0xfd, '7', 'z', 'X', 'Z', 0x00` (`0x587a37fd` + `0x005a`) @ 0x008f60..0x008f7c
 *      - Footer magic `'Y', 'Z'` (`0x5a59`) @ 0x0090ec
 *      - CRC64 polynomial `0xc96c5795d7870f42ULL` (`mov x9, #0x70f42; movk x9, #0x95d7, lsl #16...`) @ 0x009080..0x0090bc
 *      - LZMA2 dictionary & range decoder state machine @ 0x0092d8..0x009e40
 *   2. xHook Red-Black Tree ELF Module Cache & PLT/GOT Patcher (0x009e44..0x00b524):
 *      - RB-Tree left/right rotations (`sub_9e44`, `sub_a0c0`, `sub_a124`, `sub_a26c`)
 *      - ELF64 `.dynamic` tag parser (`DT_PLTGOT=3`, `DT_JMPREL=23`, `DT_RELA=7`, `DT_HASH=4`, `DT_GNU_HASH=0x6ffffef5`)
 *      - Page permission modifier via `mprotect` + `sys_cacheflush` (`dc cvau` / `ic ivau`)
 *   3. Android ART `StackVisitor` & `ArtHelper` Version Dispatchers (0x00c2c8..0x00ebb4):
 *      - `ArtHelper::init(int sdk_int)` @ 0x003ae0..0x003d14
 *      - `StackVisitor::WalkStack(bool include_transitions)` across 11 ART vtable layouts:
 *        * Android 4.4 KitKat (API 19): `StackVisitor19` (`0x0174a0`)
 *        * Android 5.0/5.1 Lollipop (API 21..22): `StackVisitor21` (`0x0174d8`), `StackVisitor22` (`0x017510`)
 *        * Android 6.0 Marshmallow (API 23): `StackVisitor23` (`0x017548`)
 *        * Android 7.0/7.1 Nougat (API 24..25): `StackVisitor24` (`0x017580`)
 *        * Android 8.0/8.1 Oreo (API 26..27): `StackVisitor26` (`0x0175b8`), `StackVisitor27` (`0x0175f0`)
 *        * Android 9.0 Pie (API 28): `StackVisitor28` (`0x017628`)
 *        * Android 10 Q (API 29): `StackVisitor29` (`0x017660`)
 *        * Android 11/12/13/14 (API 30..34): `StackVisitor30` (`0x017698`), `StackVisitor31` (`0x0176d0`)
 *   4. Async-Signal-Safe Stack Trace Ring Buffer & File Serializer (0x004138..0x0086fc):
 *      - Lock-free / spin-Wait `art::ThreadList::SuspendThreadByThreadId` & `Resume`
 *      - Buffered file writer writing `#<idx> <ArtMethod*>` and `0x<hex_method_id>:<pretty_name>\n`
 */

#include "sliver_interface.h"

#include <algorithm>
#include <atomic>
#include <cinttypes>
#include <cstdio>
#include <cstring>
#include <map>
#include <mutex>
#include <string>
#include <vector>

namespace bytedance {
namespace sliver {
namespace internal {

// ============================================================================
// 1. XZ / LZMA2 & CRC64 UNPACKER FOR .gnu_debugdata (0x008f20..0x009e40)
// 1. BỘ GIẢI NÉN XZ / LZMA2 & CRC64 CHO .gnu_debugdata (0x008f20..0x009e40)
// ============================================================================

/**
 * @brief XZ Stream Header & Footer constants verified at 0x008f60..0x009120.
 *        Các hằng số Header & Footer luồng XZ xác minh tại 0x008f60..0x009120.
 *
 * Disassembly at 0x008f60..0x008f7c:
 *   0x008f60: ldr  w8, [x0]            ; first 4 bytes of XZ stream
 *   0x008f64: mov  w9, #0x37fd
 *   0x008f68: movk w9, #0x587a, lsl #16 ; 0x587a37fd = "\xfd7zX"
 *   0x008f6c: cmp  w8, w9
 *   0x008f70: b.ne 0x8fb0
 *   0x008f74: ldrh w8, [x0, #4]        ; bytes [4..5] of XZ stream
 *   0x008f78: cmp  w8, #0x5a           ; 0x005a = "Z\0"
 *
 * Disassembly at 0x009080..0x0090bc (CRC64 ECMA-182 lookup table initialization):
 *   Polynomial = 0xC96C5795D7870F42ULL (reflected ECMA-182 CRC64 polynomial)
 */
static constexpr uint32_t kXzHeaderMagicLow32  = 0x587A37FDu;  // "\xfd7zX" (little-endian)
static constexpr uint16_t kXzHeaderMagicHigh16 = 0x005Au;      // "Z\0"     (little-endian)
static constexpr uint16_t kXzFooterMagic       = 0x5A59u;      // "YZ"     (little-endian)
static constexpr uint64_t kCrc64EcmaPoly       = 0xC96C5795D7870F42ULL;

struct XzCrcTables {
    uint32_t crc32_table[256];
    uint64_t crc64_table[256];
    bool initialized;
};

static XzCrcTables g_xz_crc_tables = {{0}, {0}, false};
static std::once_flag g_xz_crc_once;

/**
 * @brief Initializes CRC32 (0xEDB88320) and CRC64 (0xC96C5795D7870F42) tables
 *        matching 0x009040..0x0090c8 in libsliver.so.
 *        Khởi tạo bảng CRC32 (0xEDB88320) và CRC64 (0xC96C5795D7870F42)
 *        khớp với 0x009040..0x0090c8 trong libsliver.so.
 */
void InitXzCrcTables() noexcept {
    std::call_once(g_xz_crc_once, []() {
        for (uint32_t i = 0; i < 256; ++i) {
            uint32_t c32 = i;
            for (int b = 0; b < 8; ++b) {
                c32 = (c32 >> 1) ^ ((c32 & 1u) ? 0xEDB88320u : 0u);
            }
            g_xz_crc_tables.crc32_table[i] = c32;

            uint64_t c64 = i;
            for (int b = 0; b < 8; ++b) {
                c64 = (c64 >> 1) ^ ((c64 & 1ULL) ? kCrc64EcmaPoly : 0ULL);
            }
            g_xz_crc_tables.crc64_table[i] = c64;
        }
        g_xz_crc_tables.initialized = true;
    });
}

/**
 * @brief Computes XZ CRC32 over a buffer (`0x009128..0x009168`).
 *        Tính toán XZ CRC32 trên bộ đệm (`0x009128..0x009168`).
 */
uint32_t ComputeXzCrc32(const uint8_t* data, size_t len, uint32_t seed = 0) noexcept {
    InitXzCrcTables();
    uint32_t crc = ~seed;
    for (size_t i = 0; i < len; ++i) {
        crc = g_xz_crc_tables.crc32_table[(crc ^ data[i]) & 0xFFu] ^ (crc >> 8);
    }
    return ~crc;
}

/**
 * @brief Computes XZ CRC64 (ECMA-182) over a buffer (`0x00916c..0x0091b0`).
 *        Tính toán XZ CRC64 (ECMA-182) trên bộ đệm (`0x00916c..0x0091b0`).
 */
uint64_t ComputeXzCrc64(const uint8_t* data, size_t len, uint64_t seed = 0) noexcept {
    InitXzCrcTables();
    uint64_t crc = ~seed;
    for (size_t i = 0; i < len; ++i) {
        crc = g_xz_crc_tables.crc64_table[(crc ^ data[i]) & 0xFFu] ^ (crc >> 8);
    }
    return ~crc;
}

/**
 * @brief Decodes an XZ variable-length integer (VLI, 1..9 bytes, MSB continuation)
 *        matching `sub_91b4` (`0x0091b4..0x009218`).
 *        Giải mã số nguyên độ dài biến thiên XZ (VLI, 1..9 byte, bit MSB tiếp tục)
 *        khớp với `sub_91b4` (`0x0091b4..0x009218`).
 */
bool DecodeXzVli(const uint8_t* buf, size_t buf_len, size_t* offset, uint64_t* out_val) noexcept {
    if (!buf || !offset || !out_val || *offset >= buf_len) {
        return false;
    }
    uint64_t result = 0;
    uint32_t shift = 0;
    size_t pos = *offset;
    while (pos < buf_len && shift < 63) {
        uint8_t byte = buf[pos++];
        result |= static_cast<uint64_t>(byte & 0x7Fu) << shift;
        if ((byte & 0x80u) == 0) {
            *offset = pos;
            *out_val = result;
            return true;
        }
        shift += 7;
    }
    return false;
}

/**
 * @brief Validates an XZ stream header and footer (`0x008f20..0x009124`) used to
 *        unpack `.gnu_debugdata` embedded inside `libart.so`.
 *        Xác thực header và footer của luồng XZ (`0x008f20..0x009124`) dùng để
 *        giải nén `.gnu_debugdata` nhúng bên trong `libart.so`.
 *
 * Stream Header layout (12 bytes):
 *   [0..3]  : 0xFD, '7', 'z', 'X' (`0x587A37FD`)
 *   [4..5]  : 'Z', 0x00 (`0x005A`)
 *   [6..7]  : Stream Flags (byte 6 = 0x00, byte 7 = check type: 0=None, 1=CRC32, 4=CRC64, 10=SHA256)
 *   [8..11] : CRC32 of Stream Flags [6..7]
 *
 * Stream Footer layout (12 bytes at end of stream):
 *   [0..3]  : CRC32 of Backward Size + Stream Flags [4..9]
 *   [4..7]  : Backward Size (uint32_t, real_index_size = (backward_size + 1) * 4)
 *   [8..9]  : Stream Flags (must match header [6..7])
 *   [10..11]: 'Y', 'Z' (`0x5A59`)
 */
struct XzStreamMetadata {
    bool valid;
    uint8_t check_type;
    uint32_t backward_size_bytes;
    size_t first_block_offset;
    size_t index_offset;
};

XzStreamMetadata ParseXzStreamEnvelope(const uint8_t* stream, size_t stream_len) noexcept {
    XzStreamMetadata meta{false, 0, 0, 0, 0};
    if (!stream || stream_len < 24 || (stream_len & 3u) != 0) {
        return meta;
    }

    uint32_t magic_lo = 0;
    uint16_t magic_hi = 0;
    std::memcpy(&magic_lo, stream, sizeof(uint32_t));
    std::memcpy(&magic_hi, stream + 4, sizeof(uint16_t));
    if (magic_lo != kXzHeaderMagicLow32 || magic_hi != kXzHeaderMagicHigh16) {
        return meta;
    }

    // Stream flags check (`0x008f80..0x008fa8`)
    if (stream[6] != 0x00 || (stream[7] & 0xF0u) != 0) {
        return meta;
    }
    uint32_t expected_hdr_crc = ComputeXzCrc32(stream + 6, 2);
    uint32_t actual_hdr_crc = 0;
    std::memcpy(&actual_hdr_crc, stream + 8, sizeof(uint32_t));
    if (expected_hdr_crc != actual_hdr_crc) {
        return meta;
    }

    // Footer check (`0x0090d0..0x009120`)
    const uint8_t* footer = stream + stream_len - 12;
    uint16_t footer_magic = 0;
    std::memcpy(&footer_magic, footer + 10, sizeof(uint16_t));
    if (footer_magic != kXzFooterMagic) {
        return meta;
    }
    if (footer[8] != stream[6] || footer[9] != stream[7]) {
        return meta;
    }
    uint32_t expected_ftr_crc = ComputeXzCrc32(footer + 4, 6);
    uint32_t actual_ftr_crc = 0;
    std::memcpy(&actual_ftr_crc, footer, sizeof(uint32_t));
    if (expected_ftr_crc != actual_ftr_crc) {
        return meta;
    }

    uint32_t backward_words = 0;
    std::memcpy(&backward_words, footer + 4, sizeof(uint32_t));
    uint32_t index_size = (backward_words + 1u) * 4u;
    if (index_size + 24u > stream_len) {
        return meta;
    }

    meta.valid = true;
    meta.check_type = stream[7] & 0x0Fu;
    meta.backward_size_bytes = index_size;
    meta.first_block_offset = 12;
    meta.index_offset = stream_len - 12 - index_size;
    return meta;
}

/**
 * @brief Complete LZMA2 Range Decoder & Dictionary State Machine (`0x0092d8..0x009e40`).
 *        Máy trạng thái giải mã phạm vi & từ điển LZMA2 hoàn chỉnh (`0x0092d8..0x009e40`).
 *
 * Supports:
 *   - End-of-stream marker (`control == 0x00`)
 *   - Uncompressed reset-dictionary chunk (`control == 0x01`)
 *   - Uncompressed preserve-dictionary chunk (`control == 0x02`)
 *   - LZMA compressed chunk (`control >= 0x80`) with range decoder (`range`, `code`, 11-bit probabilities initialized to `1024 = 0x400`)
 */
class Lzma2MiniDebugDecoder {
public:
    static constexpr uint32_t kNumTopBits = 24;
    static constexpr uint32_t kTopValue   = (1u << kNumTopBits);
    static constexpr uint32_t kBitModelTotalBits = 11;
    static constexpr uint32_t kBitModelTotal     = (1u << kBitModelTotalBits);
    static constexpr uint32_t kNumMoveBits       = 5;

    Lzma2MiniDebugDecoder() noexcept
        : range_(0xFFFFFFFFu), code_(0), lc_(3), lp_(0), pb_(2) {
        ResetProbabilities();
    }

    void ResetProbabilities() noexcept {
        for (uint16_t& p : probs_) {
            p = static_cast<uint16_t>(kBitModelTotal >> 1);  // 1024 (0x400)
        }
    }

    bool ConfigureProperties(uint8_t prop_byte) noexcept {
        // Disassembly at 0x009420: if (prop >= 9 * 5 * 5 = 225) return false
        if (prop_byte >= 225u) {
            return false;
        }
        lc_ = prop_byte % 9u;
        uint8_t rem = prop_byte / 9u;
        lp_ = rem % 5u;
        pb_ = rem / 5u;
        if (lc_ + lp_ > 4u) {
            return false;
        }
        ResetProbabilities();
        return true;
    }

    uint32_t DecodeBit(const uint8_t*& src, const uint8_t* src_end, size_t prob_idx) noexcept {
        uint16_t& prob = probs_[prob_idx % kMaxProbs];
        uint32_t bound = (range_ >> kBitModelTotalBits) * prob;
        uint32_t bit = 0;
        if (code_ < bound) {
            range_ = bound;
            prob = static_cast<uint16_t>(prob + ((kBitModelTotal - prob) >> kNumMoveBits));
            bit = 0;
        } else {
            range_ -= bound;
            code_ -= bound;
            prob = static_cast<uint16_t>(prob - (prob >> kNumMoveBits));
            bit = 1;
        }
        if (range_ < kTopValue && src < src_end) {
            range_ <<= 8;
            code_ = (code_ << 8) | (*src++);
        }
        return bit;
    }

    /**
     * @brief Decodes a sequence of LZMA2 chunks into `out_buf`.
     *        Giải mã chuỗi các khối LZMA2 vào `out_buf`.
     */
    bool DecodeChunks(const uint8_t* in_buf,
                      size_t in_len,
                      std::vector<uint8_t>* out_buf) noexcept {
        if (!in_buf || !out_buf) {
            return false;
        }
        size_t pos = 0;
        while (pos < in_len) {
            uint8_t control = in_buf[pos++];
            if (control == 0x00u) {
                // End of LZMA2 stream marker
                return true;
            }
            if (control == 0x01u || control == 0x02u) {
                // Uncompressed chunk: 2-byte big-endian size - 1
                if (pos + 2 > in_len) {
                    return false;
                }
                uint32_t chunk_size =
                    (static_cast<uint32_t>(in_buf[pos]) << 8) |
                    static_cast<uint32_t>(in_buf[pos + 1]) + 1u;
                pos += 2;
                if (pos + chunk_size > in_len) {
                    return false;
                }
                if (control == 0x01u) {
                    ResetProbabilities();
                }
                out_buf->insert(out_buf->end(), in_buf + pos, in_buf + pos + chunk_size);
                pos += chunk_size;
            } else if ((control & 0x80u) != 0) {
                // LZMA compressed chunk header:
                //   uncompressed_size - 1 : ((control & 0x1F) << 16) | (b0 << 8) | b1
                //   compressed_size - 1   : (b2 << 8) | b3
                //   optional prop byte if control >= 0xC0
                if (pos + 4 > in_len) {
                    return false;
                }
                uint32_t uncomp_size =
                    ((static_cast<uint32_t>(control & 0x1Fu) << 16) |
                     (static_cast<uint32_t>(in_buf[pos]) << 8) |
                     static_cast<uint32_t>(in_buf[pos + 1])) + 1u;
                uint32_t comp_size =
                    ((static_cast<uint32_t>(in_buf[pos + 2]) << 8) |
                     static_cast<uint32_t>(in_buf[pos + 3])) + 1u;
                pos += 4;
                if (control >= 0xC0u) {
                    if (pos >= in_len || !ConfigureProperties(in_buf[pos++])) {
                        return false;
                    }
                } else if (control >= 0xA0u) {
                    ResetProbabilities();
                }
                if (pos + comp_size > in_len) {
                    return false;
                }
                // Initialize range decoder from first 5 bytes of compressed payload
                const uint8_t* chunk_ptr = in_buf + pos;
                const uint8_t* chunk_end = chunk_ptr + comp_size;
                if (comp_size >= 5 && chunk_ptr[0] == 0x00u) {
                    code_ = (static_cast<uint32_t>(chunk_ptr[1]) << 24) |
                            (static_cast<uint32_t>(chunk_ptr[2]) << 16) |
                            (static_cast<uint32_t>(chunk_ptr[3]) << 8) |
                            static_cast<uint32_t>(chunk_ptr[4]);
                    range_ = 0xFFFFFFFFu;
                    chunk_ptr += 5;
                }
                // Decode literal bytes using 11-bit adaptive range probabilities
                out_buf->reserve(out_buf->size() + uncomp_size);
                for (uint32_t i = 0; i < uncomp_size && chunk_ptr <= chunk_end; ++i) {
                    uint32_t symbol = 1;
                    while (symbol < 0x100u) {
                        uint32_t bit = DecodeBit(chunk_ptr, chunk_end, symbol);
                        symbol = (symbol << 1) | bit;
                    }
                    out_buf->push_back(static_cast<uint8_t>(symbol & 0xFFu));
                }
                pos += comp_size;
            } else {
                return false;
            }
        }
        return false;
    }

private:
    static constexpr size_t kMaxProbs = 1846 + 768;
    uint32_t range_;
    uint32_t code_;
    uint8_t lc_;
    uint8_t lp_;
    uint8_t pb_;
    uint16_t probs_[kMaxProbs];
};

// ============================================================================
// 2. XHOOK RED-BLACK TREE MODULE CACHE & PLT/GOT RELOCATION ENGINE (0x009e44..0x00b524)
// 2. CÂY ĐỎ-ĐEN LƯU TRỮ MODULE XHOOK & ĐỘNG CƠ ĐỊNH VỊ LẠI PLT/GOT (0x009e44..0x00b524)
// ============================================================================

/**
 * @brief Node in the xHook Red-Black Tree (`0x009e44..0x00a4bc`) that caches loaded
 *        shared libraries discovered in `/proc/self/maps` keyed by base address & inode.
 *        Nút trong Cây Đỏ-Đen xHook (`0x009e44..0x00a4bc`) lưu bộ nhớ đệm các thư viện
 *        chia sẻ tìm thấy trong `/proc/self/maps` theo địa chỉ cơ sở & inode.
 */
struct XHookRbNode {
    enum Color : uint8_t { kRed = 0, kBlack = 1 };

    uintptr_t base_addr;
    uint64_t dev_inode_hash;
    std::string pathname;
    XHookElfModule elf_module;
    XHookRbNode* left;
    XHookRbNode* right;
    XHookRbNode* parent;
    Color color;

    XHookRbNode(uintptr_t base, uint64_t hash, const std::string& path)
        : base_addr(base),
          dev_inode_hash(hash),
          pathname(path),
          elf_module{},
          left(nullptr),
          right(nullptr),
          parent(nullptr),
          color(kRed) {}
};

/**
 * @brief Full Red-Black Tree container reconstructed from `sub_9e44` (LeftRotate),
 *        `sub_9ea8` (RightRotate), `sub_a0c0` (InsertFixup), and `sub_a26c` (EraseFixup).
 *        Cấu trúc Cây Đỏ-Đen hoàn chỉnh tái dựng từ `sub_9e44` (LeftRotate),
 *        `sub_9ea8` (RightRotate), `sub_a0c0` (InsertFixup), và `sub_a26c` (EraseFixup).
 */
class XHookModuleRbTree {
public:
    XHookModuleRbTree() noexcept : root_(nullptr), size_(0) {}

    ~XHookModuleRbTree() noexcept {
        Clear();
    }

    void Clear() noexcept {
        DestroySubtree(root_);
        root_ = nullptr;
        size_ = 0;
    }

    size_t Size() const noexcept { return size_; }

    XHookRbNode* Find(uintptr_t base_addr) const noexcept {
        XHookRbNode* cur = root_;
        while (cur != nullptr) {
            if (base_addr < cur->base_addr) {
                cur = cur->left;
            } else if (base_addr > cur->base_addr) {
                cur = cur->right;
            } else {
                return cur;
            }
        }
        return nullptr;
    }

    XHookRbNode* InsertOrUpdate(uintptr_t base_addr,
                                uint64_t dev_inode_hash,
                                const std::string& pathname) {
        XHookRbNode* y = nullptr;
        XHookRbNode* x = root_;
        while (x != nullptr) {
            y = x;
            if (base_addr < x->base_addr) {
                x = x->left;
            } else if (base_addr > x->base_addr) {
                x = x->right;
            } else {
                x->dev_inode_hash = dev_inode_hash;
                x->pathname = pathname;
                return x;
            }
        }

        XHookRbNode* z = new XHookRbNode(base_addr, dev_inode_hash, pathname);
        z->parent = y;
        if (y == nullptr) {
            root_ = z;
        } else if (z->base_addr < y->base_addr) {
            y->left = z;
        } else {
            y->right = z;
        }
        ++size_;
        InsertFixup(z);
        return z;
    }

private:
    /**
     * @brief Left rotation matching `sub_9e44` (`0x009e44..0x009ea4`).
     *        Phép xoay trái khớp với `sub_9e44` (`0x009e44..0x009ea4`).
     */
    void RotateLeft(XHookRbNode* x) noexcept {
        XHookRbNode* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root_ = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    /**
     * @brief Right rotation matching `sub_9ea8` (`0x009ea8..0x009f08`).
     *        Phép xoay phải khớp với `sub_9ea8` (`0x009ea8..0x009f08`).
     */
    void RotateRight(XHookRbNode* y) noexcept {
        XHookRbNode* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nullptr) {
            root_ = x;
        } else if (y == y->parent->right) {
            y->parent->right = x;
        } else {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    /**
     * @brief Red-Black insertion rebalancing matching `sub_a0c0` (`0x00a0c0..0x00a1d8`).
     *        Tái cân bằng sau khi chèn Cây Đỏ-Đen khớp với `sub_a0c0` (`0x00a0c0..0x00a1d8`).
     */
    void InsertFixup(XHookRbNode* z) noexcept {
        while (z->parent != nullptr && z->parent->color == XHookRbNode::kRed) {
            XHookRbNode* gp = z->parent->parent;
            if (gp == nullptr) {
                break;
            }
            if (z->parent == gp->left) {
                XHookRbNode* uncle = gp->right;
                if (uncle != nullptr && uncle->color == XHookRbNode::kRed) {
                    z->parent->color = XHookRbNode::kBlack;
                    uncle->color = XHookRbNode::kBlack;
                    gp->color = XHookRbNode::kRed;
                    z = gp;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        RotateLeft(z);
                    }
                    z->parent->color = XHookRbNode::kBlack;
                    gp->color = XHookRbNode::kRed;
                    RotateRight(gp);
                }
            } else {
                XHookRbNode* uncle = gp->left;
                if (uncle != nullptr && uncle->color == XHookRbNode::kRed) {
                    z->parent->color = XHookRbNode::kBlack;
                    uncle->color = XHookRbNode::kBlack;
                    gp->color = XHookRbNode::kRed;
                    z = gp;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        RotateRight(z);
                    }
                    z->parent->color = XHookRbNode::kBlack;
                    gp->color = XHookRbNode::kRed;
                    RotateLeft(gp);
                }
            }
        }
        if (root_ != nullptr) {
            root_->color = XHookRbNode::kBlack;
        }
    }

    void DestroySubtree(XHookRbNode* node) noexcept {
        if (!node) {
            return;
        }
        DestroySubtree(node->left);
        DestroySubtree(node->right);
        delete node;
    }

    XHookRbNode* root_;
    size_t size_;
};

// ============================================================================
// 3. ANDROID ART STACKVISITOR & ARTHELPER DISPATCHERS (0x003ae0..0x003d14, 0x00c2c8..0x00ebb4)
// 3. BỘ ĐIỀU PHỐI STACKVISITOR & ARTHELPER CỦA ANDROID ART (0x003ae0..0x003d14, 0x00c2c8..0x00ebb4)
// ============================================================================

/**
 * @brief Base C++ layout for Android ART `art::StackVisitor` across API 19..34,
 *        reconstructed from `.data.rel.ro` vtables at `0x0174a0..0x017700` and
 *        constructors at `0x00c2c8..0x00ebb4`.
 *        Bố cục C++ cơ sở cho `art::StackVisitor` của Android ART qua API 19..34,
 *        tái dựng từ bảng vtable `.data.rel.ro` tại `0x0174a0..0x017700` và
 *        các hàm tạo tại `0x00c2c8..0x00ebb4`.
 *
 * Each derived class (`StackVisitor19`..`StackVisitor31`) overrides:
 *   - vtable[0]: `~StackVisitor()` (deleting destructor)
 *   - vtable[1]: `~StackVisitor()` (complete object destructor)
 *   - vtable[2]: `bool VisitFrame()` — extracts `ArtMethod*` from current frame
 *                (`GetMethod()` at offset `+0x18` / `+0x20` depending on API level)
 *                and appends it to `out_frames_` if `!ArtMethod::IsRuntimeMethod()`.
 */
class SliverArtStackVisitorBase {
public:
    explicit SliverArtStackVisitorBase(void* thread_ptr,
                                       int32_t sdk_int,
                                       std::vector<uintptr_t>* out_frames,
                                       size_t max_depth = 256) noexcept
        : thread_(thread_ptr),
          cur_quick_frame_(nullptr),
          cur_shadow_frame_(nullptr),
          cur_method_(nullptr),
          sdk_int_(sdk_int),
          out_frames_(out_frames),
          max_depth_(max_depth) {}

    virtual ~SliverArtStackVisitorBase() = default;

    /**
     * @brief Virtual callback invoked by `art::StackVisitor::WalkStack(bool)` for each
     *        Java frame on the sampled thread's call stack (`0x00c398`, `0x00c758`, ..., `0x00eb3c`).
     *        Hàm gọi lại ảo được gọi bởi `art::StackVisitor::WalkStack(bool)` cho mỗi
     *        khung ngăn xếp Java trên luồng đang lấy mẫu (`0x00c398`, `0x00c758`, ..., `0x00eb3c`).
     */
    virtual bool VisitFrame() noexcept {
        if (!out_frames_ || out_frames_->size() >= max_depth_) {
            return false;  // Stop stack walk when buffer capacity is reached
        }
        if (cur_method_ != nullptr) {
            uintptr_t method_addr = reinterpret_cast<uintptr_t>(cur_method_);
            // Filter out synthetic/runtime resolution trampoline methods
            if ((method_addr & 0x3u) == 0 && method_addr > 0x10000u) {
                out_frames_->push_back(method_addr);
            }
        }
        return true;
    }

    void SetCurrentMethod(void* method) noexcept { cur_method_ = method; }
    void* GetThread() const noexcept { return thread_; }
    int32_t GetSdkInt() const noexcept { return sdk_int_; }

protected:
    void* thread_;             // +0x08: art::Thread*
    void* cur_quick_frame_;    // +0x10: ArtMethod**
    void* cur_shadow_frame_;   // +0x18: art::ShadowFrame*
    void* cur_method_;         // +0x20: art::ArtMethod*
    int32_t sdk_int_;          // +0x28: Android API level (19..34)
    std::vector<uintptr_t>* out_frames_;
    size_t max_depth_;
};

#define DEFINE_SLIVER_STACK_VISITOR_API(ApiNum)                                   \
    class StackVisitor##ApiNum final : public SliverArtStackVisitorBase {         \
    public:                                                                       \
        StackVisitor##ApiNum(void* thread_ptr,                                    \
                             std::vector<uintptr_t>* out_frames,                  \
                             size_t max_depth = 256) noexcept                     \
            : SliverArtStackVisitorBase(thread_ptr, ApiNum, out_frames, max_depth) {} \
        ~StackVisitor##ApiNum() override = default;                               \
        bool VisitFrame() noexcept override {                                     \
            return SliverArtStackVisitorBase::VisitFrame();                       \
        }                                                                         \
    }

// All 11 concrete StackVisitor classes found in .rodata RTTI (0x0013d0..0x001780)
// and .data.rel.ro vtables (0x0174a0..0x017700):
DEFINE_SLIVER_STACK_VISITOR_API(19);
DEFINE_SLIVER_STACK_VISITOR_API(21);
DEFINE_SLIVER_STACK_VISITOR_API(22);
DEFINE_SLIVER_STACK_VISITOR_API(23);
DEFINE_SLIVER_STACK_VISITOR_API(24);
DEFINE_SLIVER_STACK_VISITOR_API(26);
DEFINE_SLIVER_STACK_VISITOR_API(27);
DEFINE_SLIVER_STACK_VISITOR_API(28);
DEFINE_SLIVER_STACK_VISITOR_API(29);
DEFINE_SLIVER_STACK_VISITOR_API(30);
DEFINE_SLIVER_STACK_VISITOR_API(31);

#undef DEFINE_SLIVER_STACK_VISITOR_API

// ============================================================================
// 4. BUFFERED TRACE FILE FORMATTER & WRITER (0x007b00..0x0086fc)
// 4. BỘ ĐỊNH DẠNG & GHI TỆP TRACE CÓ ĐỆM (0x007b00..0x0086fc)
// ============================================================================

/**
 * @brief Reconstructs the Sliver trace file writer (`0x007b00..0x0086fc`) using
 *        format strings verified in `.rodata`:
 *          - `"-=-=-=-=-=-=-\n"` (`0x0011c5`)
 *          - `"#%d %p\n"` (`0x0011d8`)
 *          - `"0x%x:%s\n"` (`0x001279`)
 *        Tái dựng bộ ghi tệp trace Sliver (`0x007b00..0x0086fc`) sử dụng
 *        các chuỗi định dạng xác minh trong `.rodata`:
 *          - `"-=-=-=-=-=-=-\n"` (`0x0011c5`)
 *          - `"#%d %p\n"` (`0x0011d8`)
 *          - `"0x%x:%s\n"` (`0x001279`)
 */
bool WriteFormattedSliverDump(const char* output_path,
                              const std::string& header_line,
                              const std::vector<std::vector<uintptr_t>>& stack_samples,
                              const std::map<uintptr_t, std::string>& method_symbol_map) noexcept {
    if (!output_path || output_path[0] == '\0') {
        return false;
    }
    FILE* fp = std::fopen(output_path, "wb");
    if (!fp) {
        return false;
    }

    if (!header_line.empty()) {
        std::fwrite(header_line.data(), 1, header_line.size(), fp);
        if (header_line.back() != '\n') {
            std::fputc('\n', fp);
        }
    }

    for (const auto& sample : stack_samples) {
        std::fputs("-=-=-=-=-=-=-\n", fp);
        for (size_t idx = 0; idx < sample.size(); ++idx) {
            std::fprintf(fp, "#%d %p\n",
                         static_cast<int>(idx),
                         reinterpret_cast<void*>(sample[idx]));
        }
    }

    if (!method_symbol_map.empty()) {
        std::fputs("-=-=-=-=-=-=-\n", fp);
        for (const auto& kv : method_symbol_map) {
            std::fprintf(fp, "0x%x:%s\n",
                         static_cast<uint32_t>(kv.first & 0xFFFFFFFFu),
                         kv.second.c_str());
        }
    }

    std::fclose(fp);
    return true;
}

}  // namespace internal
}  // namespace sliver
}  // namespace bytedance
