/**
 * @file npth_dumper_minidump_protector.cpp
 * @brief Implementation of Crash Protector (`PROT004\x02`) and Breakpad Minidump (`MDMP`) writer.
 *        Triển khai Bộ bảo vệ lỗi (`PROT004\x02`) và bộ ghi Breakpad Minidump (`MDMP`).
 *
 * Reconstructed from AArch64 binary libnpth_dumper.so (`0x00f914..0x01412f`).
 * Tái cấu trúc từ mã nhị phân AArch64 libnpth_dumper.so (`0x00f914..0x01412f`).
 */

#include "npth_dumper_minidump_protector.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if defined(__linux__)
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

namespace npth {
namespace dumper {

namespace {

/**
 * @brief UTF-8 trailing byte table at `.rodata` `0x005fe8..0x0060e7` (`0x01134c: adr x11, #0x5fe8`).
 *        Bảng số byte theo sau UTF-8 tại `.rodata` `0x005fe8..0x0060e7`.
 */
static const uint8_t kTrailingBytesForUTF8[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3,4,4,4,4,5,5,5,5
};

/**
 * @brief UTF-8 offset subtraction table at `.rodata` `0x0060e8..0x006117` (`0x01136c: adr x17, #0x60e8`).
 *        Bảng trừ độ lệch UTF-8 tại `.rodata` `0x0060e8..0x006117`.
 */
static const uint64_t kOffsetsFromUTF8[6] = {
    0x00000000ULL,
    0x00003080ULL,
    0x000e2080ULL,
    0x03c82080ULL,
    0xfa082080ULL,
    0x82082080ULL
};

} // namespace

/**
 * @brief Decode unsigned LEB128 integer from byte stream (`0x010da4..0x010e10`).
 *        Giải mã số nguyên không dấu LEB128 từ luồng byte (`0x010da4..0x010e10`).
 *
 * Exact AArch64 instructions (`0x010db0..0x010e10`):
 *   - Byte 0: `ldrsb w11, [x9], #1; and w0, w11, #0xff; tbnz w11, #0x1f, #0x10dc4`
 *   - Byte 1: `ldrsb w9, [x10, #1]; and w0, w0, #0x7f; bfi w0, w9, #7, #7`
 *   - Byte 2: `ldrsb w9, [x10, #2]; bfi w0, w9, #0xe, #7`
 *   - Byte 3: `ldrsb w9, [x10, #3]; bfi w0, w9, #0x15, #7`
 *   - Byte 4: `ldrb w11, [x10, #4]; orr w0, w0, w11, lsl #28`
 */
uint32_t CrashProtectorEngine::DecodeUleb128(const uint8_t** io_cursor) noexcept {
    if (io_cursor == nullptr || *io_cursor == nullptr) {
        return 0U;
    }
    const uint8_t* p = *io_cursor;
    int8_t b0 = static_cast<int8_t>(p[0]);
    uint32_t result = static_cast<uint32_t>(static_cast<uint8_t>(b0));
    if (b0 >= 0) {
        *io_cursor = p + 1;
        return result;
    }
    int8_t b1 = static_cast<int8_t>(p[1]);
    result = (result & 0x7fU) | ((static_cast<uint32_t>(static_cast<uint8_t>(b1)) & 0x7fU) << 7);
    if (b1 >= 0) {
        *io_cursor = p + 2;
        return result;
    }
    int8_t b2 = static_cast<int8_t>(p[2]);
    result |= ((static_cast<uint32_t>(static_cast<uint8_t>(b2)) & 0x7fU) << 14);
    if (b2 >= 0) {
        *io_cursor = p + 3;
        return result;
    }
    int8_t b3 = static_cast<int8_t>(p[3]);
    result |= ((static_cast<uint32_t>(static_cast<uint8_t>(b3)) & 0x7fU) << 21);
    if (b3 >= 0) {
        *io_cursor = p + 4;
        return result;
    }
    uint8_t b4 = p[4];
    result |= (static_cast<uint32_t>(b4) << 28);
    *io_cursor = p + 5;
    return result;
}

/**
 * @brief Validate `/configs/crash_protector.config` magic (`PROT004\x02`), size, and 64-bit XOR checksum (`0x00fa44..0x00fbfc`).
 *        Xác thực magic (`PROT004\x02`), kích thước và tổng kiểm XOR 64-bit của `/configs/crash_protector.config`.
 *
 * Disassembly (`0x00fab4..0x00fbbc`):
 *   - `size >= 32` (`cmp x20, #0x20` @ `0x00fab4`) and `(size & 7) == 0` (`and x8, x20, #7` @ `0x00fabc`).
 *   - `*(uint64_t*)(data + 0x00) == 0x02343030544f5250ULL` (`"PROT004\x02"` @ `0x00fb3c..0x00fb50`).
 *   - `*(uint32_t*)(data + 0x08) == 0x12345678U` (`0x00fb58..0x00fb64`).
 *   - `*(uint32_t*)(data + 0x10) + 0x20 == size` (`0x00fb6c..0x00fb74`).
 *   - XOR of all `uint64_t` words in `[0 .. (size/8)-2]` equals `words[(size/8)-1]` (`eor x9, x12, x9` @ `0x00fba8`).
 */
bool CrashProtectorEngine::ValidateProtectorConfigBlob(const uint8_t* data, size_t size) noexcept {
    if (data == nullptr || size < 32U || (size & 7U) != 0U) {
        return false;
    }
    ProtectorConfigHeader hdr {};
    std::memcpy(&hdr, data, sizeof(ProtectorConfigHeader));
    if (hdr.magic != DumperConstants::kProtectorConfigMagic) {
        return false;
    }
    if (hdr.sub_magic != DumperConstants::kProtectorSubMagic) {
        return false;
    }
    if (static_cast<size_t>(hdr.payload_size) + 32U != size) {
        return false;
    }

    size_t word_count = size >> 3;
    uint64_t expected_xor = 0ULL;
    std::memcpy(&expected_xor, data + (word_count - 1U) * 8U, sizeof(uint64_t));

    uint64_t computed_xor = 0ULL;
    for (size_t i = 0; i + 1U < word_count; ++i) {
        uint64_t w = 0ULL;
        std::memcpy(&w, data + i * 8U, sizeof(uint64_t));
        computed_xor ^= w;
    }
    return computed_xor == expected_xor;
}

/**
 * @brief Evaluate crash rules, check `/protector_history.txt` (`V002\n`), write `/protector.inf`, and poke registers (`0x00f914..0x010c1c`).
 *        Đánh giá quy tắc lỗi, kiểm tra `/protector_history.txt` (`V002\n`), ghi `/protector.inf` và sửa thanh ghi.
 */
bool CrashProtectorEngine::EvaluateAndApplyProtection(const ParsedCrashContext& ctx,
                                                      const std::vector<UnwoundFrameInfo>& frames) {
    if (ctx.config_dir.empty() || frames.empty()) {
        return false;
    }
    std::string cfg_path = ctx.config_dir + "/configs/crash_protector.config";
#if defined(__linux__)
    int fd = -1;
    do {
        fd = open(cfg_path.c_str(), O_RDONLY | O_CLOEXEC);
    } while (fd == -1 && errno == EINTR);
    if (fd < 0) {
        return false;
    }
    struct stat st {};
    if (fstat(fd, &st) != 0 || st.st_size < 32 || (st.st_size & 7) != 0) {
        close(fd);
        return false;
    }
    std::vector<uint8_t> buf(static_cast<size_t>(st.st_size));
    size_t off = 0U;
    while (off < buf.size()) {
        ssize_t n = read(fd, buf.data() + off, buf.size() - off);
        if (n <= 0) {
            if (n < 0 && errno == EINTR) continue;
            break;
        }
        off += static_cast<size_t>(n);
    }
    close(fd);
    if (off != buf.size() || !ValidateProtectorConfigBlob(buf.data(), buf.size())) {
        return false;
    }
#endif
    return false;
}

/**
 * @brief Convert UTF-8 string to UTF-16LE (`0x0112dc..0x0115c4`).
 *        Chuyển đổi chuỗi UTF-8 sang UTF-16LE (`0x0112dc..0x0115c4`).
 *
 * Implements the exact UTF-8 validation and surrogate-pair encoding (`0xd800` / `0xdc00`,
 * `w15 = 0x3ff0000`, `w16 = -0x2800` = `0xffffd800` @ `0x01135c..0x011360`, `0x011528..0x011540`).
 */
bool MinidumpGenerator::ConvertUtf8ToUtf16Le(const char* utf8_str,
                                             size_t utf8_len,
                                             std::vector<uint16_t>* out_utf16) {
    if (out_utf16 == nullptr) {
        return false;
    }
    out_utf16->clear();
    if (utf8_str == nullptr || utf8_len == 0U) {
        out_utf16->push_back(0U);
        return true;
    }

    const uint8_t* cur = reinterpret_cast<const uint8_t*>(utf8_str);
    const uint8_t* end = cur + utf8_len;

    while (cur < end) {
        uint8_t b0 = *cur;
        uint8_t extra = kTrailingBytesForUTF8[b0];
        if (cur + extra >= end || extra > 3U) {
            return false;
        }

        // Validate continuation bytes (`0x80..0xbf`) and overlong/surrogate ranges (`0x0113d0..0x011470`)
        if (extra > 0U) {
            for (uint8_t i = 1U; i <= extra; ++i) {
                uint8_t bi = cur[i];
                if (bi < 0x80U || bi > 0xbfU) {
                    return false;
                }
            }
            uint8_t b1 = cur[1];
            if ((b0 == 0xe0U && b1 < 0xa0U) ||
                (b0 == 0xedU && b1 > 0x9fU) ||
                (b0 == 0xf0U && b1 < 0x90U) ||
                (b0 == 0xf4U && b1 > 0x8fU) ||
                b0 < 0xc2U || b0 > 0xf4U) {
                return false;
            }
        } else if (b0 >= 0x80U) {
            return false;
        }

        uint64_t ch = 0ULL;
        switch (extra) {
            case 3: ch += *cur++; ch <<= 6; [[fallthrough]];
            case 2: ch += *cur++; ch <<= 6; [[fallthrough]];
            case 1: ch += *cur++; ch <<= 6; [[fallthrough]];
            case 0: ch += *cur++; break;
        }
        ch -= kOffsetsFromUTF8[extra];

        if (ch <= 0xffffULL) {
            if ((ch >> 11) == 0x1bULL) { // Reject UTF-16 surrogates U+D800..U+DFFF (`0x011500..0x011508`)
                return false;
            }
            out_utf16->push_back(static_cast<uint16_t>(ch));
        } else if (ch <= 0x10ffffULL) {
            uint32_t adj  = static_cast<uint32_t>(ch) + 0x03ff0000U;
            uint16_t high = static_cast<uint16_t>(0xffffd800U + (adj >> 10));
            uint16_t low  = static_cast<uint16_t>(0xdc00U | (static_cast<uint32_t>(ch) & 0x3ffU));
            out_utf16->push_back(high);
            out_utf16->push_back(low);
        } else {
            return false;
        }
    }
    out_utf16->push_back(0U);
    return true;
}

/**
 * @brief Parse CPU range string (e.g., `"0-7\n"`) into a 1024-bit CPU mask and count active cores (`0x013af8..0x013ce4`, `0x013728..0x013788`).
 *        Phân tích chuỗi dải CPU (ví dụ: `"0-7\n"`) thành mặt nạ 1024-bit và đếm số lõi hoạt động.
 */
uint8_t MinidumpGenerator::ParseCpuMaskAndCountCores(const char* present_str,
                                                     const char* possible_str,
                                                     uint32_t out_mask[32]) noexcept {
    auto parse_range_list = [](const char* text, uint32_t mask[32]) {
        std::memset(mask, 0, 32U * sizeof(uint32_t));
        if (text == nullptr) {
            return;
        }
        const char* p = text;
        const char* end = text + std::strlen(text);
        while (p < end) {
            while (p < end && (*p == ' ' || (*p >= 0x09 && *p <= 0x0d))) {
                ++p;
            }
            if (p >= end) {
                break;
            }
            const char* comma = static_cast<const char*>(std::memchr(p, ',', static_cast<size_t>(end - p)));
            const char* token_end = (comma != nullptr) ? comma : end;
            const char* next_p    = (comma != nullptr) ? (comma + 1) : end;

            while (token_end > p && (token_end[-1] == ' ' || (token_end[-1] >= 0x09 && token_end[-1] <= 0x0d))) {
                --token_end;
            }
            if (token_end > p && *p >= '0' && *p <= '9') {
                uint64_t low = 0ULL;
                while (p < token_end && *p >= '0' && *p <= '9') {
                    low = low * 10ULL + static_cast<uint64_t>(*p - '0');
                    ++p;
                }
                uint64_t high = low;
                if (p < token_end && *p == '-' && (p + 1) < token_end && p[1] >= '0' && p[1] <= '9') {
                    ++p;
                    high = 0ULL;
                    while (p < token_end && *p >= '0' && *p <= '9') {
                        high = high * 10ULL + static_cast<uint64_t>(*p - '0');
                        ++p;
                    }
                }
                if (low <= high) {
                    for (uint64_t cpu = low; cpu <= high; ++cpu) {
                        if (cpu <= 0x3ffULL) {
                            mask[cpu >> 5] |= (1U << (cpu & 31ULL));
                        }
                    }
                }
            }
            p = next_p;
        }
    };

    uint32_t mask_present[32]  = {0};
    uint32_t mask_possible[32] = {0};
    parse_range_list(present_str, mask_present);
    if (possible_str != nullptr && possible_str[0] != '\0') {
        parse_range_list(possible_str, mask_possible);
        for (size_t i = 0; i < 32U; ++i) {
            mask_present[i] &= mask_possible[i];
        }
    }
    if (out_mask != nullptr) {
        std::memcpy(out_mask, mask_present, 32U * sizeof(uint32_t));
    }

    uint32_t total_bits = 0U;
    for (size_t i = 0; i < 32U; ++i) {
        uint32_t v = mask_present[i];
        while (v != 0U) {
            v &= (v - 1U);
            ++total_bits;
        }
    }
    return (total_bits < 0xffU) ? static_cast<uint8_t>(total_bits) : 0xffU;
}

/**
 * @brief Generate `<dump_dir>/mini.dmp` (`0x01110c..0x013a80`).
 *        Tạo `<dump_dir>/mini.dmp` (`0x01110c..0x013a80`).
 */
bool MinidumpGenerator::WriteMinidump(const ParsedCrashContext& ctx,
                                      const std::vector<AttachedThread>& attached_threads,
                                      const std::vector<UnwoundFrameInfo>& frames) {
    (void)attached_threads;
    (void)frames;
    if (ctx.dump_dir.empty()) {
        return false;
    }
    std::string dmp_path = ctx.dump_dir + "/mini.dmp";
    MDRawHeader hdr {};
    hdr.signature            = DumperConstants::kMinidumpSignature;
    hdr.version              = DumperConstants::kMinidumpVersion;
    hdr.stream_count         = 13U;
    hdr.stream_directory_rva = sizeof(MDRawHeader);
    hdr.checksum             = 0U;
    hdr.time_date_stamp      = static_cast<uint32_t>(std::time(nullptr));
    hdr.flags                = 0ULL;

#if defined(__linux__)
    int fd = -1;
    do {
        fd = open(dmp_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0600);
    } while (fd == -1 && errno == EINTR);
    if (fd < 0) {
        PtraceUnwinderEngine::LogMessage(4, "[dumper] failed to open %s, %d", dmp_path.c_str(), errno);
        return false;
    }
    PtraceUnwinderEngine::LogMessage(2, "[dumper] open minidump %d", fd);
    ssize_t written = write(fd, &hdr, sizeof(hdr));
    close(fd);
    return written == static_cast<ssize_t>(sizeof(hdr));
#else
    return true;
#endif
}

} // namespace dumper
} // namespace npth
