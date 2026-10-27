// ============================================================================
// File: lynxbase_string_crypto.cpp
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: RFC 1321 MD5, CityHash64, DataURIUtil, Base64Decode, js_dtoa,
//            String & UTF-8/16/32 Algorithms, High-Precision Time &
//            RefCountedStringImpl Implementation (.text 0x01ca70..0x02f6f0)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Clean-room C++17 implementation of `lynx::base` cryptographic/hash,
//      DataURI/Base64, `js_dtoa`, UTF-8/16/32 string algorithms, reciprocal
//      time division math, and `RefCountedStringImpl` reconstructed from
//      `liblynxbase.so` AArch64 machine code.
// [VN] Bản cài đặt C++17 tái tạo sạch cho các thuật toán băm MD5/CityHash64,
//      DataURI/Base64, `js_dtoa`, chuỗi UTF-8/16/32, phép chia thời gian bằng
//      nhân nghịch đảo có dấu, và `RefCountedStringImpl` từ `liblynxbase.so`.
// ============================================================================

#include "lynxbase_string_crypto.h"

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>

namespace lynx {
namespace base {

// ============================================================================
// 1. `FileUtils` (.text 0x01ca70..0x01cc60)
// ============================================================================

// [EN] `FileUtils::ReadFileBinary` @ 0x01ca70..0x01cb4c:
//      Opens `path` with `fopen(path, "rb")` (`.rodata 0x00cd38`), seeks to end
//      (`fseek(fp, 0, SEEK_END = 2)`), queries `ftell(fp)`, checks
//      `file_size <= max_size`, rewinds (`fseek(fp, 0, SEEK_SET = 0)`), resizes
//      `out_bytes`, reads `fread(out_bytes.data(), 1, file_size, fp)`, and closes.
// [VN] `FileUtils::ReadFileBinary` tại `0x01ca70..0x01cb4c`: mở file chế độ `"rb"`,
//      kiểm tra kích thước với `max_size`, đọc toàn bộ dữ liệu nhị phân và đóng file.
bool FileUtils::ReadFileBinary(const std::string& path,
                               size_t max_size,
                               std::vector<uint8_t>& out_bytes) {
    FILE* fp = std::fopen(path.c_str(), "rb");
    if (fp == nullptr) {
        return false;
    }
    if (std::fseek(fp, 0, SEEK_END) != 0) {
        std::fclose(fp);
        return false;
    }
    const long size_long = std::ftell(fp);
    if (size_long < 0 || static_cast<size_t>(size_long) > max_size) {
        std::fclose(fp);
        return false;
    }
    if (std::fseek(fp, 0, SEEK_SET) != 0) {
        std::fclose(fp);
        return false;
    }
    const size_t file_size = static_cast<size_t>(size_long);
    out_bytes.resize(file_size);
    const size_t nread =
        file_size > 0 ? std::fread(out_bytes.data(), 1, file_size, fp) : 0;
    std::fclose(fp);
    return nread == file_size;
}

// [EN] `FileUtils::WriteFileBinary` @ 0x01cb50..0x01cc60:
//      Opens `path` with `fopen(path, "wb+")` (`.rodata 0x00cd3b`), writes
//      `fwrite(data, 1, size, fp)`, flushes, and closes.
// [VN] `FileUtils::WriteFileBinary` tại `0x01cb50..0x01cc60`: mở file chế độ
//      `"wb+"`, ghi `size` byte dữ liệu và đóng file.
bool FileUtils::WriteFileBinary(const std::string& path,
                                const uint8_t* data,
                                size_t size) {
    if (data == nullptr && size > 0) {
        return false;
    }
    FILE* fp = std::fopen(path.c_str(), "wb+");
    if (fp == nullptr) {
        return false;
    }
    const size_t nwritten = size > 0 ? std::fwrite(data, 1, size, fp) : 0;
    std::fflush(fp);
    std::fclose(fp);
    return nwritten == size;
}

// ============================================================================
// 2. RFC 1321 MD5 (`0x01e2d8..0x01f0b4`) & `CityHash64` (`0x022314..0x022628`)
// ============================================================================
namespace {

constexpr uint32_t RotateLeft32(uint32_t x, uint32_t n) noexcept {
    return (x << n) | (x >> (32u - n));
}

// [EN] `MD5_Transform` @ 0x01e384..0x01edc0:
//      Unrolled 64-round RFC 1321 block compression function.
//      Round 1 starts with `mov w13, #0xa478; movk w13, #0xd76a, lsl #16`
//      (`0xD76AA478` at `0x01e3ac..0x01e3b4`).
// [VN] `MD5_Transform` tại `0x01e384..0x01edc0`: hàm nén khối 64 vòng chuẩn
//      RFC 1321 bắt đầu bằng hằng số `0xD76AA478` tại `0x01e3ac..0x01e3b4`.
void MD5_Transform(uint32_t state[4], const uint8_t block[64]) noexcept {
    static constexpr uint32_t kSinTable[64] = {
        0xd76aa478u, 0xe8c7b756u, 0x242070dbu, 0xc1bdceeeu,
        0xf57c0fafu, 0x4787c62au, 0xa8304613u, 0xfd469501u,
        0x698098d8u, 0x8b44f7afu, 0xffff5bb1u, 0x895cd7beu,
        0x6b901122u, 0xfd987193u, 0xa679438eu, 0x49b40821u,
        0xf61e2562u, 0xc040b340u, 0x265e5a51u, 0xe9b6c7aau,
        0xd62f105du, 0x02441453u, 0xd8a1e681u, 0xe7d3fbc8u,
        0x21e1cde6u, 0xc33707d6u, 0xf4d50d87u, 0x455a14edu,
        0xa9e3e905u, 0xfcefa3f8u, 0x676f02d9u, 0x8d2a4c8au,
        0xfffa3942u, 0x8771f681u, 0x6d9d6122u, 0xfde5380cu,
        0xa4beea44u, 0x4bdecfa9u, 0xf6bb4b60u, 0xbebfbc70u,
        0x289b7ec6u, 0xeaa127fau, 0xd4ef3085u, 0x04881d05u,
        0xd9d4d039u, 0xe6db99e5u, 0x1fa27cf8u, 0xc4ac5665u,
        0xf4292244u, 0x432aff97u, 0xab9423a7u, 0xfc93a039u,
        0x655b59c3u, 0x8f0ccc92u, 0xffeff47du, 0x85845dd1u,
        0x6fa87e4fu, 0xfe2ce6e0u, 0xa3014314u, 0x4e0811a1u,
        0xf7537e82u, 0xbd3af235u, 0x2ad7d2bbu, 0xeb86d391u,
    };
    static constexpr uint32_t kShifts[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
    };

    uint32_t m[16];
    for (size_t i = 0; i < 16; ++i) {
        m[i] = static_cast<uint32_t>(block[i * 4 + 0]) |
               (static_cast<uint32_t>(block[i * 4 + 1]) << 8) |
               (static_cast<uint32_t>(block[i * 4 + 2]) << 16) |
               (static_cast<uint32_t>(block[i * 4 + 3]) << 24);
    }

    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];

    for (uint32_t i = 0; i < 64; ++i) {
        uint32_t f = 0;
        uint32_t g = 0;
        if (i < 16) {
            f = (b & c) | ((~b) & d);
            g = i;
        } else if (i < 32) {
            f = (d & b) | ((~d) & c);
            g = (5u * i + 1u) & 15u;
        } else if (i < 48) {
            f = b ^ c ^ d;
            g = (3u * i + 5u) & 15u;
        } else {
            f = c ^ (b | (~d));
            g = (7u * i) & 15u;
        }
        const uint32_t temp = d;
        d = c;
        c = b;
        b = b + RotateLeft32(a + f + kSinTable[i] + m[g], kShifts[i]);
        a = temp;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

// [EN] `MD5_Update` @ 0x01edc4..0x01ee94.
// [VN] `MD5_Update` tại `0x01edc4..0x01ee94`.
void MD5_Update(Md5Context& ctx, const uint8_t* input, size_t len) noexcept {
    size_t index = static_cast<size_t>((ctx.bit_count >> 3) & 0x3Fu);
    ctx.bit_count += static_cast<uint64_t>(len) << 3;

    const size_t part_len = 64u - index;
    size_t i = 0;
    if (len >= part_len) {
        std::memcpy(&ctx.buffer[index], input, part_len);
        MD5_Transform(ctx.state, ctx.buffer);
        for (i = part_len; i + 63u < len; i += 64u) {
            MD5_Transform(ctx.state, &input[i]);
        }
        index = 0;
    }
    if (i < len) {
        std::memcpy(&ctx.buffer[index], &input[i], len - i);
    }
}

// [EN] `MD5_Final` @ 0x01e2d8..0x01e380: appends `0x80` padding and 64-bit
//      little-endian bit length, then stores 16-byte digest at `ctx.digest`.
// [VN] `MD5_Final` tại `0x01e2d8..0x01e380`: đệm byte `0x80` và độ dài bit
//      64-bit little-endian, sau đó xuất 16 byte digest.
void MD5_Final(Md5Context& ctx) noexcept {
    static constexpr uint8_t kPadding[64] = {0x80};
    uint8_t bits[8];
    uint64_t bit_len = ctx.bit_count;
    for (int i = 0; i < 8; ++i) {
        bits[i] = static_cast<uint8_t>(bit_len & 0xFFu);
        bit_len >>= 8;
    }

    const size_t index = static_cast<size_t>((ctx.bit_count >> 3) & 0x3Fu);
    const size_t pad_len = (index < 56u) ? (56u - index) : (120u - index);
    MD5_Update(ctx, kPadding, pad_len);
    MD5_Update(ctx, bits, 8u);

    for (int i = 0; i < 4; ++i) {
        ctx.digest[i * 4 + 0] = static_cast<uint8_t>(ctx.state[i] & 0xFFu);
        ctx.digest[i * 4 + 1] = static_cast<uint8_t>((ctx.state[i] >> 8) & 0xFFu);
        ctx.digest[i * 4 + 2] = static_cast<uint8_t>((ctx.state[i] >> 16) & 0xFFu);
        ctx.digest[i * 4 + 3] = static_cast<uint8_t>((ctx.state[i] >> 24) & 0xFFu);
    }
}

// [EN] `MD5_ToHex` @ 0x01ee98..0x01efdc: formats 16-byte digest into 32-char
//      lowercase hex string using `"%02x"` (`.rodata 0x00cc73`).
// [VN] `MD5_ToHex` tại `0x01ee98..0x01efdc`: định dạng 16 byte digest thành chuỗi
//      32 ký tự hex chữ thường qua `"%02x"` (`.rodata 0x00cc73`).
std::string MD5_ToHex(const Md5Context& ctx) {
    char hex_buf[33];
    for (int i = 0; i < 16; ++i) {
        std::snprintf(&hex_buf[i * 2], 3, "%02x", ctx.digest[i]);
    }
    hex_buf[32] = '\0';
    return std::string(hex_buf, 32);
}

} // namespace

// [EN] `lynx::base::md5(const char*, size_t)` @ 0x01efe4..0x01f04c:
//      Loads `q0` from `.rodata 0x00d250` (`[0, 0, 0x67452301, 0xEFCDAB89]`)
//      and `x8 = 0x1032547698BADCFEULL` (`0x01eff8..0x01f004`), runs
//      `MD5_Update` (`0x01edc4`), `MD5_Final` (`0x01e2d8`), and `MD5_ToHex` (`0x01ee98`).
// [VN] `lynx::base::md5(const char*, size_t)` tại `0x01efe4..0x01f04c`.
std::string md5(const char* data, size_t length) {
    Md5Context ctx;
    if (data != nullptr && length > 0) {
        MD5_Update(ctx, reinterpret_cast<const uint8_t*>(data), length);
    }
    MD5_Final(ctx);
    return MD5_ToHex(ctx);
}

// [EN] `lynx::base::md5(const std::string&)` @ 0x01f050..0x01f0b4.
// [VN] `lynx::base::md5(const std::string&)` tại `0x01f050..0x01f0b4`.
std::string md5(const std::string& str) {
    return md5(str.data(), str.size());
}

// ============================================================================
// `CityHash64(const char*, size_t)` (.text 0x022314..0x022628)
// ============================================================================
namespace {

uint64_t Fetch64LE(const char* p) noexcept {
    uint64_t result = 0;
    std::memcpy(&result, p, sizeof(result));
    return result;
}

uint32_t Fetch32LE(const char* p) noexcept {
    uint32_t result = 0;
    std::memcpy(&result, p, sizeof(result));
    return result;
}

constexpr uint64_t RotateRight64(uint64_t val, int shift) noexcept {
    return shift == 0 ? val : ((val >> shift) | (val << (64 - shift)));
}

constexpr uint64_t ShiftMix(uint64_t val) noexcept {
    return val ^ (val >> 47);
}

constexpr uint64_t HashLen16(uint64_t u, uint64_t v, uint64_t mul) noexcept {
    uint64_t a = (u ^ v) * mul;
    a ^= (a >> 47);
    uint64_t b = (v ^ a) * mul;
    b ^= (b >> 47);
    b *= mul;
    return b;
}

constexpr uint64_t HashLen16Default(uint64_t u, uint64_t v) noexcept {
    return HashLen16(u, v, 0x9DDFEA08EB382D69ULL);
}

uint64_t HashLen0to16(const char* s, size_t len) noexcept {
    using namespace constants;
    if (len >= 8) {
        const uint64_t mul = kCityHashK2 + len * 2;
        const uint64_t a = Fetch64LE(s) + kCityHashK2;
        const uint64_t b = Fetch64LE(s + len - 8);
        const uint64_t c = RotateRight64(b, 37) * mul + a;
        const uint64_t d = (RotateRight64(a, 25) + b) * mul;
        return HashLen16(c, d, mul);
    }
    if (len >= 4) {
        const uint64_t mul = kCityHashK2 + len * 2;
        const uint64_t a = Fetch32LE(s);
        return HashLen16(len + (a << 3), Fetch32LE(s + len - 4), mul);
    }
    if (len > 0) {
        const uint8_t a = static_cast<uint8_t>(s[0]);
        const uint8_t b = static_cast<uint8_t>(s[len >> 1]);
        const uint8_t c = static_cast<uint8_t>(s[len - 1]);
        const uint32_t y = static_cast<uint32_t>(a) + (static_cast<uint32_t>(b) << 8);
        const uint32_t z = static_cast<uint32_t>(len) + (static_cast<uint32_t>(c) << 2);
        return ShiftMix(y * kCityHashK2 ^ z * kCityHashK0) * kCityHashK2;
    }
    return kCityHashK2;
}

uint64_t HashLen17to32(const char* s, size_t len) noexcept {
    using namespace constants;
    const uint64_t mul = kCityHashK2 + len * 2;
    const uint64_t a = Fetch64LE(s) * kCityHashK1;
    const uint64_t b = Fetch64LE(s + 8);
    const uint64_t c = Fetch64LE(s + len - 8) * mul;
    const uint64_t d = Fetch64LE(s + len - 16) * kCityHashK2;
    return HashLen16(RotateRight64(a + b, 43) + RotateRight64(c, 30) + d,
                     a + RotateRight64(b + kCityHashK2, 18) + c,
                     mul);
}

uint64_t HashLen33to64(const char* s, size_t len) noexcept {
    using namespace constants;
    const uint64_t mul = kCityHashK2 + len * 2;
    uint64_t a = Fetch64LE(s) * kCityHashK2;
    uint64_t b = Fetch64LE(s + 8);
    const uint64_t c = Fetch64LE(s + len - 24);
    const uint64_t d = Fetch64LE(s + len - 32);
    const uint64_t e = Fetch64LE(s + 16) * kCityHashK2;
    const uint64_t f = Fetch64LE(s + 24) * 9;
    const uint64_t g = Fetch64LE(s + len - 8);
    const uint64_t h = Fetch64LE(s + len - 16) * mul;
    const uint64_t u = RotateRight64(a + g, 43) + (RotateRight64(b, 30) + c) * 9;
    const uint64_t v = ((a + g) ^ d) + f + 1;
    const uint64_t w = ((u + v) * mul) + h;
    const uint64_t x = RotateRight64(e + f, 42) + c;
    const uint64_t y = (((v + w) * mul) + g) * mul;
    const uint64_t z = e + f + c;
    a = ((x + z) * mul + y) + b;
    b = ShiftMix((z + a) * mul + d + h) * mul;
    return b + x;
}

std::pair<uint64_t, uint64_t> WeakHashLen32WithSeeds(
    uint64_t w, uint64_t x, uint64_t y, uint64_t z, uint64_t a, uint64_t b) noexcept {
    a += w;
    b = RotateRight64(b + a + z, 21);
    const uint64_t c = a;
    a += x;
    a += y;
    b += RotateRight64(a, 44);
    return {a + z, b + c};
}

std::pair<uint64_t, uint64_t> WeakHashLen32WithSeeds(
    const char* s, uint64_t a, uint64_t b) noexcept {
    return WeakHashLen32WithSeeds(Fetch64LE(s),
                                  Fetch64LE(s + 8),
                                  Fetch64LE(s + 16),
                                  Fetch64LE(s + 24),
                                  a,
                                  b);
}

} // namespace

// [EN] `CityHash64(const char*, size_t)` @ 0x022314..0x022628:
//      Exact Google CityHash64 with constants `k0 = 0xC3A5C85C97CB3127ULL`,
//      `k1 = 0xB492B66FBE98F273ULL`, `k2 = 0x9AE16A3B2F90404FULL`.
// [VN] `CityHash64` tại `0x022314..0x022628`: thuật toán băm 64-bit dùng trong
//      `RefCountedStringImpl`.
uint64_t CityHash64(const char* s, size_t len) {
    using namespace constants;
    if (len <= 32) {
        if (len <= 16) {
            return HashLen0to16(s, len);
        }
        return HashLen17to32(s, len);
    } else if (len <= 64) {
        return HashLen33to64(s, len);
    }

    uint64_t x = Fetch64LE(s + len - 40);
    uint64_t y = Fetch64LE(s + len - 16) + Fetch64LE(s + len - 56);
    uint64_t z = HashLen16Default(Fetch64LE(s + len - 48) + len, Fetch64LE(s + len - 24));
    std::pair<uint64_t, uint64_t> v = WeakHashLen32WithSeeds(s + len - 64, len, z);
    std::pair<uint64_t, uint64_t> w = WeakHashLen32WithSeeds(s + len - 32, y + kCityHashK1, x);
    x = x * kCityHashK1 + Fetch64LE(s);

    len = (len - 1) & ~static_cast<size_t>(63);
    do {
        x = RotateRight64(x + y + v.first + Fetch64LE(s + 8), 37) * kCityHashK1;
        y = RotateRight64(y + v.second + Fetch64LE(s + 48), 42) * kCityHashK1;
        x ^= w.second;
        y += v.first + Fetch64LE(s + 40);
        z = RotateRight64(z + w.first, 33) * kCityHashK1;
        v = WeakHashLen32WithSeeds(s, v.second * kCityHashK1, x + w.first);
        w = WeakHashLen32WithSeeds(s + 32, z + w.second, y + Fetch64LE(s + 16));
        std::swap(z, x);
        s += 64;
        len -= 64;
    } while (len != 0);

    return HashLen16Default(HashLen16Default(v.first, w.first) + ShiftMix(y) * kCityHashK1 + z,
                            HashLen16Default(v.second, w.second) + x);
}

// ============================================================================
// 3. `DataURIUtil` (.text 0x029410..0x029550) & `Base64Decode` (.text 0x02f290)
// ============================================================================

// [EN] `DataURIUtil::IsDataURI` @ 0x029410..0x02944c:
//      Compares prefix against `"data:"` (`.rodata 0x00cc8f`, 5 bytes).
// [VN] `DataURIUtil::IsDataURI` tại `0x029410..0x02944c`: kiểm tra tiền tố `"data:"`.
bool DataURIUtil::IsDataURI(std::string_view uri) {
    return BeginsWith(uri, "data:");
}

// [EN] `DataURIUtil::DecodeDataURI` @ 0x029450..0x029550:
//      1. Checks `uri.size() >= 8`, searches for 8-byte little-endian marker
//         `";base64,"` (`0x2C3436657361623BULL` at `0x02946c..0x029480`).
//      2. Extracts payload after `";base64,"` (`b64_len = uri.size() - (pos + 8)`).
//      3. Computes buffer allocation size:
//         `lsr x9, x20, #2; add x9, x9, x9, lsl #1; add x1, x9, #2` (`0x029510..0x029518`)
//         = `(b64_len >> 2) * 3 + 2`.
//      4. Invokes `buffer_factory(alloc_size)` and calls `Base64Decode` (`0x02f290`).
// [VN] `DataURIUtil::DecodeDataURI` tại `0x029450..0x029550`: tìm dấu phân cách
//      8 byte `";base64,"` (`0x2C3436657361623BULL`), cấp phát `(b64_len >> 2) * 3 + 2`
//      byte qua `buffer_factory` và giải mã Base64.
int32_t DataURIUtil::DecodeDataURI(std::string_view uri,
                                   MoveOnlyClosure<char*(size_t)> buffer_factory) {
    if (!buffer_factory || uri.size() < 8) {
        return 0;
    }

    static constexpr std::string_view kBase64Marker = ";base64,";
    // Verify our 8-byte little-endian constant matches ";base64,"
    uint64_t marker_le = 0;
    std::memcpy(&marker_le, kBase64Marker.data(), 8);
    if (marker_le != constants::kDataUriBase64MarkerLE) {
        return 0;
    }

    const size_t pos = uri.find(kBase64Marker);
    if (pos == std::string_view::npos) {
        return 0;
    }

    const size_t data_offset = pos + 8;
    if (data_offset >= uri.size()) {
        return 0;
    }

    const std::string_view b64_payload = uri.substr(data_offset);
    const size_t b64_len = b64_payload.size();
    const size_t alloc_size = (b64_len >> 2) * 3 + 2;

    char* out_buf = buffer_factory(alloc_size);
    if (out_buf == nullptr) {
        return 0;
    }

    const size_t decoded_len = Base64Decode(b64_payload, out_buf);
    return static_cast<int32_t>(decoded_len);
}

// [EN] `lynx::base::Base64Decode` @ 0x02f290..0x02f6f0.
// [VN] Giải mã chuỗi Base64 sang bộ đệm nhị phân (`0x02f290..0x02f6f0`).
size_t Base64Decode(std::string_view input, char* output_buffer) {
    if (output_buffer == nullptr || input.empty()) {
        return 0;
    }
    auto decode_char = [](unsigned char c) -> int {
        if (c >= 'A' && c <= 'Z') return c - 'A';
        if (c >= 'a' && c <= 'z') return c - 'a' + 26;
        if (c >= '0' && c <= '9') return c - '0' + 52;
        if (c == '+' || c == '-') return 62;
        if (c == '/' || c == '_') return 63;
        return -1;
    };

    uint32_t accum = 0;
    int bits_collected = 0;
    size_t out_pos = 0;

    for (char ch : input) {
        if (ch == '=') {
            break;
        }
        const int val = decode_char(static_cast<unsigned char>(ch));
        if (val < 0) {
            continue;
        }
        accum = (accum << 6) | static_cast<uint32_t>(val);
        bits_collected += 6;
        if (bits_collected >= 8) {
            bits_collected -= 8;
            output_buffer[out_pos++] =
                static_cast<char>((accum >> bits_collected) & 0xFFu);
        }
    }
    return out_pos;
}

std::string Base64Encode(const uint8_t* data, size_t len) {
    static constexpr char kAlphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    if (data == nullptr || len == 0) {
        return {};
    }
    std::string out;
    out.reserve(((len + 2) / 3) * 4);
    for (size_t i = 0; i < len; i += 3) {
        const uint32_t b0 = data[i];
        const uint32_t b1 = (i + 1 < len) ? data[i + 1] : 0;
        const uint32_t b2 = (i + 2 < len) ? data[i + 2] : 0;
        const uint32_t triple = (b0 << 16) | (b1 << 8) | b2;
        out.push_back(kAlphabet[(triple >> 18) & 0x3Fu]);
        out.push_back(kAlphabet[(triple >> 12) & 0x3Fu]);
        out.push_back((i + 1 < len) ? kAlphabet[(triple >> 6) & 0x3Fu] : '=');
        out.push_back((i + 2 < len) ? kAlphabet[triple & 0x3Fu] : '=');
    }
    return out;
}

// ============================================================================
// 4. `js_dtoa` (.text 0x029554..0x029674)
// ============================================================================
// [EN] AArch64 disassembly of `lynx::base::js_dtoa(double, char*)` @ 0x029554:
//      0x029568: fmov x8, d0
//      0x02956c: and x9, x8, #0x7fffffffffffffff
//      0x029574: mov x8, #0x7ff0000000000000   // 0xD2EFFE08
//      0x029578: cmp x9, x8
//      0x02957c: b.hs 0x29590 -> writes `0x6C6C756E` ("null") + '\0', returns 4
//      0x029594: fcvtzs x8, d0
//      0x029598: scvtf d1, x8
//      0x02959c: mov x9, #0x1fffffffffffff
//      0x0295a0: add x9, x8, x9
//      0x0295a4: mov x10, #0x3ffffffffffffe
//      0x0295a8: fcmp d0, d1
//      0x0295ac: ccmp x9, x10, #2, eq
//      0x0295b0: b.hi 0x2965c (`dtoa_lynx` @ 0x02df40)
//      0x0295c4..0x0295e0: 53-bit integer fast-path using
//      `x9 = 0xCCCCCCCCCCCCCCCDULL`, `umulh x12, x11, x9; lsr x12, x12, #3`.
// [VN] Mã máy AArch64 của `lynx::base::js_dtoa(double, char*)` tại `0x029554`:
//      kiểm tra NaN/Infinity (`0x7FF0000000000000ULL`), nhánh nhanh số nguyên
//      53-bit với hằng số chia 10 `0xCCCCCCCCCCCCCCCDULL`, và rút gọn tổng quát.
size_t js_dtoa(double value, char* buffer) {
    if (buffer == nullptr) {
        return 0;
    }

    uint64_t raw_bits = 0;
    std::memcpy(&raw_bits, &value, sizeof(raw_bits));
    if ((raw_bits & 0x7FFFFFFFFFFFFFFFULL) >= constants::kIeee754PosInfinityBits) {
        // 0x029580: mov w8, #0x756e; movk w8, #0x6c6c, lsl #16 -> "null"
        std::memcpy(buffer, "null", 5);
        return 4;
    }

    const int64_t int_val = static_cast<int64_t>(value);
    const uint64_t shifted =
        static_cast<uint64_t>(int_val) + static_cast<uint64_t>(constants::kJsDtoaMaxSafeInt53);
    if (static_cast<double>(int_val) == value &&
        shifted <= constants::kJsDtoaSafeIntRange) {
        if (int_val == 0) {
            buffer[0] = '0';
            buffer[1] = '\0';
            return 1;
        }

        char temp[24];
        size_t pos = 0;
        uint64_t mag = (int_val < 0)
                           ? (0ULL - static_cast<uint64_t>(int_val))
                           : static_cast<uint64_t>(int_val);

        while (mag != 0) {
            // Exact reciprocal division by 10 (`0xCCCCCCCCCCCCCCCDULL`, lsr #3)
#if defined(__SIZEOF_INT128__)
            const uint64_t q = static_cast<uint64_t>(
                (static_cast<unsigned __int128>(mag) * constants::kUnsignedDiv10Magic) >> 67);
#else
            const uint64_t q = mag / 10ULL;
#endif
            const uint64_t rem = mag - q * 10ULL;
            temp[pos++] = static_cast<char>('0' + rem);
            mag = q;
        }

        size_t out_idx = 0;
        if (int_val < 0) {
            buffer[out_idx++] = '-';
        }
        while (pos > 0) {
            buffer[out_idx++] = temp[--pos];
        }
        buffer[out_idx] = '\0';
        return out_idx;
    }

    const int written = std::snprintf(buffer, 32, "%.15g", value);
    return written > 0 ? static_cast<size_t>(written) : 0;
}

// ============================================================================
// 5. String Manipulation & UTF-8/16/32 Conversion (.text 0x0299a4..0x02cc98)
// ============================================================================

bool SplitString(std::string_view input,
                 char delimiter,
                 bool trim_whitespace,
                 const std::function<bool(const char*, size_t, int)>& handler) {
    if (!handler) {
        return false;
    }
    size_t start = 0;
    int part_index = 0;
    while (start <= input.size()) {
        size_t end = input.find(delimiter, start);
        if (end == std::string_view::npos) {
            end = input.size();
        }
        std::string_view token = input.substr(start, end - start);
        if (trim_whitespace) {
            token = TrimString(token, " \t\r\n", TrimPositions::TRIM_ALL);
        }
        if (!handler(token.data(), token.size(), part_index++)) {
            return false;
        }
        if (end == input.size()) {
            break;
        }
        start = end + 1;
    }
    return true;
}

void SplitString(std::string_view input,
                 char delimiter,
                 std::vector<std::string>& out_tokens) {
    SplitString(input, delimiter, false,
                [&out_tokens](const char* ptr, size_t len, int) {
                    out_tokens.emplace_back(ptr, len);
                    return true;
                });
}

void SplitStringByChars(std::string_view input,
                        std::string_view delimiters,
                        std::vector<std::string>& out_tokens) {
    size_t start = 0;
    while (start < input.size()) {
        const size_t pos = input.find_first_of(delimiters, start);
        if (pos == std::string_view::npos) {
            out_tokens.emplace_back(input.substr(start));
            break;
        }
        if (pos > start) {
            out_tokens.emplace_back(input.substr(start, pos - start));
        }
        start = pos + 1;
    }
}

// [EN] `SplitStringIgnoreBracket` @ 0x02a0d0: splits by `delimiter` only when
//      parenthesis/bracket nesting depth `()[]{}` is zero.
// [VN] `SplitStringIgnoreBracket` tại `0x02a0d0`: chỉ tách chuỗi theo `delimiter`
//      khi độ sâu ngoặc `()[]{}` bằng 0.
std::vector<std::string> SplitStringIgnoreBracket(std::string_view input, char delimiter) {
    std::vector<std::string> result;
    int depth = 0;
    size_t start = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        const char c = input[i];
        if (c == '(' || c == '[' || c == '{') {
            ++depth;
        } else if (c == ')' || c == ']' || c == '}') {
            if (depth > 0) --depth;
        } else if (c == delimiter && depth == 0) {
            result.emplace_back(TrimString(input.substr(start, i - start)));
            start = i + 1;
        }
    }
    if (start <= input.size()) {
        auto tail = TrimString(input.substr(start));
        if (!tail.empty()) {
            result.emplace_back(tail);
        }
    }
    return result;
}

bool BeginsWith(std::string_view str, std::string_view prefix) {
    return str.size() >= prefix.size() &&
           str.compare(0, prefix.size(), prefix) == 0;
}

bool EndsWith(std::string_view str, std::string_view suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool BeginsWithCaseInsensitive(std::string_view str, std::string_view prefix) {
    if (str.size() < prefix.size()) {
        return false;
    }
    return EqualsIgnoreCase(str.substr(0, prefix.size()), prefix);
}

bool EndsWithCaseInsensitive(std::string_view str, std::string_view suffix) {
    if (str.size() < suffix.size()) {
        return false;
    }
    return EqualsIgnoreCase(str.substr(str.size() - suffix.size()), suffix);
}

bool EqualsIgnoreCase(std::string_view a, std::string_view b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (std::tolower(static_cast<unsigned char>(a[i])) !=
            std::tolower(static_cast<unsigned char>(b[i]))) {
            return false;
        }
    }
    return true;
}

std::string StringToLowerASCII(std::string_view str) {
    std::string out(str);
    for (char& c : out) {
        if (c >= 'A' && c <= 'Z') {
            c = static_cast<char>(c + ('a' - 'A'));
        }
    }
    return out;
}

std::string SnakeToCamel(std::string_view str) {
    std::string out;
    out.reserve(str.size());
    bool upper_next = false;
    for (char c : str) {
        if (c == '_' || c == '-') {
            upper_next = true;
        } else if (upper_next) {
            out.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
            upper_next = false;
        } else {
            out.push_back(c);
        }
    }
    return out;
}

std::string CamelToDash(std::string_view str) {
    std::string out;
    out.reserve(str.size() + 4);
    for (size_t i = 0; i < str.size(); ++i) {
        const char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            if (i > 0) {
                out.push_back('-');
            }
            out.push_back(static_cast<char>(c + ('a' - 'A')));
        } else {
            out.push_back(c);
        }
    }
    return out;
}

std::string_view TrimString(std::string_view str,
                            std::string_view trim_chars,
                            TrimPositions positions) {
    if (str.empty()) {
        return str;
    }
    const uint32_t pos_mask = static_cast<uint32_t>(positions);
    size_t first = 0;
    size_t last = str.size();

    if (pos_mask & static_cast<uint32_t>(TrimPositions::TRIM_LEADING)) {
        first = str.find_first_not_of(trim_chars);
        if (first == std::string_view::npos) {
            return std::string_view();
        }
    }
    if (pos_mask & static_cast<uint32_t>(TrimPositions::TRIM_TRAILING)) {
        const size_t last_non_trim = str.find_last_not_of(trim_chars);
        if (last_non_trim == std::string_view::npos) {
            return std::string_view();
        }
        last = last_non_trim + 1;
    }
    return str.substr(first, last - first);
}

std::string TrimString(const std::string& str,
                       const char* trim_chars,
                       TrimPositions positions) {
    return std::string(TrimString(std::string_view(str),
                                  trim_chars != nullptr ? std::string_view(trim_chars) : " \t\r\n",
                                  positions));
}

void ReplaceAll(std::string& str, std::string_view from, std::string_view to) {
    if (from.empty()) {
        return;
    }
    size_t pos = 0;
    while ((pos = str.find(from, pos)) != std::string::npos) {
        str.replace(pos, from.size(), to);
        pos += to.size();
    }
}

std::string RemoveSpaces(std::string_view str) {
    std::string out;
    out.reserve(str.size());
    for (char c : str) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            out.push_back(c);
        }
    }
    return out;
}

std::string FormatString(const char* fmt, ...) {
    if (fmt == nullptr) {
        return {};
    }
    va_list args;
    va_start(args, fmt);
    va_list args_copy;
    va_copy(args_copy, args);
    const int needed = std::vsnprintf(nullptr, 0, fmt, args);
    va_end(args);
    if (needed <= 0) {
        va_end(args_copy);
        return {};
    }
    std::string result(static_cast<size_t>(needed), '\0');
    std::vsnprintf(result.data(), result.size() + 1, fmt, args_copy);
    va_end(args_copy);
    return result;
}

void AppendFormatString(std::string& target, const char* fmt, ...) {
    if (fmt == nullptr) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    va_list args_copy;
    va_copy(args_copy, args);
    const int needed = std::vsnprintf(nullptr, 0, fmt, args);
    va_end(args);
    if (needed <= 0) {
        va_end(args_copy);
        return;
    }
    const size_t old_size = target.size();
    target.resize(old_size + static_cast<size_t>(needed));
    std::vsnprintf(target.data() + old_size, static_cast<size_t>(needed) + 1, fmt, args_copy);
    va_end(args_copy);
}

bool StringToDouble(const std::string& input, double& output, bool error_on_trailing) {
    if (input.empty()) {
        return false;
    }
    char* end_ptr = nullptr;
    const double val = std::strtod(input.c_str(), &end_ptr);
    if (end_ptr == input.c_str()) {
        return false;
    }
    if (error_on_trailing && *end_ptr != '\0') {
        return false;
    }
    output = val;
    return true;
}

bool StringToFloat(const std::string& input, float& output, bool error_on_trailing) {
    double d = 0.0;
    if (!StringToDouble(input, d, error_on_trailing)) {
        return false;
    }
    output = static_cast<float>(d);
    return true;
}

bool StringToInt(const std::string& input, int64_t& output, uint8_t base) {
    if (input.empty()) {
        return false;
    }
    char* end_ptr = nullptr;
    const long long val = std::strtoll(input.c_str(), &end_ptr, base);
    if (end_ptr == input.c_str() || *end_ptr != '\0') {
        return false;
    }
    output = static_cast<int64_t>(val);
    return true;
}

bool StringToUInt64(const std::string& input, uint64_t& output, uint8_t base) {
    if (input.empty()) {
        return false;
    }
    char* end_ptr = nullptr;
    const unsigned long long val = std::strtoull(input.c_str(), &end_ptr, base);
    if (end_ptr == input.c_str() || *end_ptr != '\0') {
        return false;
    }
    output = static_cast<uint64_t>(val);
    return true;
}

// ============================================================================
// UTF-8 / UTF-16 / UTF-32 Codepoint Conversion (`0x02bae4..0x02cc98`)
// ============================================================================

std::u32string U8StringToU32(std::string_view u8_str) {
    std::u32string out;
    out.reserve(u8_str.size());
    size_t i = 0;
    while (i < u8_str.size()) {
        const uint8_t b0 = static_cast<uint8_t>(u8_str[i]);
        char32_t cp = 0;
        if (b0 < 0x80u) {
            cp = b0;
            i += 1;
        } else if ((b0 & 0xE0u) == 0xC0u && i + 1 < u8_str.size()) {
            cp = ((b0 & 0x1Fu) << 6) |
                 (static_cast<uint8_t>(u8_str[i + 1]) & 0x3Fu);
            i += 2;
        } else if ((b0 & 0xF0u) == 0xE0u && i + 2 < u8_str.size()) {
            cp = ((b0 & 0x0Fu) << 12) |
                 ((static_cast<uint8_t>(u8_str[i + 1]) & 0x3Fu) << 6) |
                 (static_cast<uint8_t>(u8_str[i + 2]) & 0x3Fu);
            i += 3;
        } else if ((b0 & 0xF8u) == 0xF0u && i + 3 < u8_str.size()) {
            cp = ((b0 & 0x07u) << 18) |
                 ((static_cast<uint8_t>(u8_str[i + 1]) & 0x3Fu) << 12) |
                 ((static_cast<uint8_t>(u8_str[i + 2]) & 0x3Fu) << 6) |
                 (static_cast<uint8_t>(u8_str[i + 3]) & 0x3Fu);
            i += 4;
        } else {
            cp = 0xFFFDu;
            i += 1;
        }
        out.push_back(cp);
    }
    return out;
}

std::string U32StringToU8(std::u32string_view u32_str) {
    std::string out;
    out.reserve(u32_str.size() * 2);
    for (char32_t cp : u32_str) {
        if (cp <= 0x7Fu) {
            out.push_back(static_cast<char>(cp));
        } else if (cp <= 0x7FFu) {
            out.push_back(static_cast<char>(0xC0u | ((cp >> 6) & 0x1Fu)));
            out.push_back(static_cast<char>(0x80u | (cp & 0x3Fu)));
        } else if (cp <= 0xFFFFu) {
            out.push_back(static_cast<char>(0xE0u | ((cp >> 12) & 0x0Fu)));
            out.push_back(static_cast<char>(0x80u | ((cp >> 6) & 0x3Fu)));
            out.push_back(static_cast<char>(0x80u | (cp & 0x3Fu)));
        } else if (cp <= 0x10FFFFu) {
            out.push_back(static_cast<char>(0xF0u | ((cp >> 18) & 0x07u)));
            out.push_back(static_cast<char>(0x80u | ((cp >> 12) & 0x3Fu)));
            out.push_back(static_cast<char>(0x80u | ((cp >> 6) & 0x3Fu)));
            out.push_back(static_cast<char>(0x80u | (cp & 0x3Fu)));
        }
    }
    return out;
}

std::u16string U32StringToU16(std::u32string_view u32_str) {
    std::u16string out;
    out.reserve(u32_str.size());
    for (char32_t cp : u32_str) {
        if (cp <= 0xFFFFu) {
            out.push_back(static_cast<char16_t>(cp));
        } else if (cp <= 0x10FFFFu) {
            const uint32_t v = static_cast<uint32_t>(cp) - 0x10000u;
            out.push_back(static_cast<char16_t>(0xD800u | (v >> 10)));
            out.push_back(static_cast<char16_t>(0xDC00u | (v & 0x3FFu)));
        }
    }
    return out;
}

std::u32string U16StringToU32(std::u16string_view u16_str) {
    std::u32string out;
    out.reserve(u16_str.size());
    for (size_t i = 0; i < u16_str.size(); ++i) {
        const uint16_t w1 = static_cast<uint16_t>(u16_str[i]);
        if (w1 >= 0xD800u && w1 <= 0xDBFFu && i + 1 < u16_str.size()) {
            const uint16_t w2 = static_cast<uint16_t>(u16_str[i + 1]);
            if (w2 >= 0xDC00u && w2 <= 0xDFFFu) {
                const char32_t cp =
                    0x10000u + (((static_cast<char32_t>(w1) - 0xD800u) << 10) |
                                (static_cast<char32_t>(w2) - 0xDC00u));
                out.push_back(cp);
                ++i;
                continue;
            }
        }
        out.push_back(static_cast<char32_t>(w1));
    }
    return out;
}

std::u16string U8StringToU16(std::string_view u8_str) {
    return U32StringToU16(U8StringToU32(u8_str));
}

std::string U16StringToU8(std::u16string_view u16_str) {
    return U32StringToU8(U16StringToU32(u16_str));
}

size_t UTF8IndexToCIndex(const char* utf8_str, size_t byte_len, size_t codepoint_index) {
    if (utf8_str == nullptr) {
        return 0;
    }
    size_t byte_pos = 0;
    size_t cp_pos = 0;
    while (byte_pos < byte_len && cp_pos < codepoint_index) {
        const uint8_t b = static_cast<uint8_t>(utf8_str[byte_pos]);
        if (b < 0x80u) byte_pos += 1;
        else if ((b & 0xE0u) == 0xC0u) byte_pos += 2;
        else if ((b & 0xF0u) == 0xE0u) byte_pos += 3;
        else byte_pos += 4;
        ++cp_pos;
    }
    return std::min(byte_pos, byte_len);
}

size_t LengthCalculatedByUTF32(const std::string& utf8_str) {
    return U8StringToU32(utf8_str).size();
}

// ============================================================================
// 6. High-Precision Time & Reciprocal Division (.text 0x02d520..0x02d65c)
// ============================================================================
namespace {

// [EN] Signed 64-bit division by 1,000 matching `0x02d528..0x02d540`, `0x02d584`,
//      `0x02d5c0`, and `0x02d610`:
//      `smulh x8, x0, x8` (`0x9B487C08` with `0x20C49BA5E353F7CFULL`),
//      `asr x9, x8, #7`, `add x0, x9, x8, lsr #63`.
// [VN] Phép chia 64-bit có dấu cho 1.000 khớp mã máy `0x02d528..0x02d540`:
//      nhân cao `smulh` với `0x20C49BA5E353F7CFULL` và dịch phải số học 7 bit.
constexpr int64_t SignedDivBy1000(int64_t val) noexcept {
#if defined(__SIZEOF_INT128__)
    const __int128 prod = static_cast<__int128>(val) *
                          static_cast<__int128>(static_cast<int64_t>(constants::kSignedDiv1000Magic));
    const int64_t high = static_cast<int64_t>(prod >> 64);
    return (high >> constants::kSignedDiv1000Shift) +
           static_cast<int64_t>(static_cast<uint64_t>(high) >> 63);
#else
    return val / 1000LL;
#endif
}

// [EN] Signed 64-bit division by 1,000,000 matching `0x02d558..0x02d570`:
//      `smulh x8, x0, x8` (`0x9B487C08` with `0x431BDE82D7B634DBULL`),
//      `asr x9, x8, #0x12`, `add x0, x9, x8, lsr #63`.
// [VN] Phép chia 64-bit có dấu cho 1.000.000 khớp mã máy `0x02d558..0x02d570`:
//      nhân cao `smulh` với `0x431BDE82D7B634DBULL` và dịch phải số học 18 bit.
constexpr int64_t SignedDivBy1000000(int64_t val) noexcept {
#if defined(__SIZEOF_INT128__)
    const __int128 prod = static_cast<__int128>(val) *
                          static_cast<__int128>(static_cast<int64_t>(constants::kSignedDiv1000000Magic));
    const int64_t high = static_cast<int64_t>(prod >> 64);
    return (high >> constants::kSignedDiv1000000Shift) +
           static_cast<int64_t>(static_cast<uint64_t>(high) >> 63);
#else
    return val / 1000000LL;
#endif
}

} // namespace

// [EN] `CurrentSystemTimeMilliseconds()` @ 0x02d520..0x02d53c.
// [VN] `CurrentSystemTimeMilliseconds()` tại `0x02d520..0x02d53c`.
uint64_t CurrentSystemTimeMilliseconds() {
    const int64_t us = static_cast<int64_t>(CurrentSystemTimeMicroseconds());
    return static_cast<uint64_t>(SignedDivBy1000(us));
}

// [EN] `CurrentSystemTimeMicroseconds()` @ 0x02d540..0x02d544.
// [VN] `CurrentSystemTimeMicroseconds()` tại `0x02d540..0x02d544`.
uint64_t CurrentSystemTimeMicroseconds() {
    const auto now = std::chrono::system_clock::now().time_since_epoch();
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::microseconds>(now).count());
}

// [EN] `CurrentTimeMilliseconds()` @ 0x02d548..0x02d570:
//      Calls `CurrentTimeNanoseconds()` and divides by 1,000,000 via `SignedDivBy1000000`.
// [VN] `CurrentTimeMilliseconds()` tại `0x02d548..0x02d570`: gọi
//      `CurrentTimeNanoseconds()` và chia cho 1.000.000 qua `SignedDivBy1000000`.
int64_t CurrentTimeMilliseconds() {
    const int64_t ns = static_cast<int64_t>(CurrentTimeNanoseconds());
    return SignedDivBy1000000(ns);
}

// [EN] `CurrentTimeMicroseconds()` @ 0x02d574..0x02d58c:
//      Calls `CurrentTimeNanoseconds()` and divides by 1,000 via `SignedDivBy1000`.
// [VN] `CurrentTimeMicroseconds()` tại `0x02d574..0x02d58c`: gọi
//      `CurrentTimeNanoseconds()` và chia cho 1.000 qua `SignedDivBy1000`.
int64_t CurrentTimeMicroseconds() {
    const int64_t ns = static_cast<int64_t>(CurrentTimeNanoseconds());
    return SignedDivBy1000(ns);
}

// [EN] `CurrentTimeNanoseconds()` @ 0x02d590..0x02d594 -> `steady_clock::now()`.
// [VN] `CurrentTimeNanoseconds()` tại `0x02d590..0x02d594` -> `steady_clock::now()`.
uint64_t CurrentTimeNanoseconds() {
    const auto now = std::chrono::steady_clock::now().time_since_epoch();
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::nanoseconds>(now).count());
}

// [EN] `CurrentThreadCPUTimeMicroseconds()` @ 0x02d598..0x02d5dc:
//      Calls `clock_gettime(CLOCK_THREAD_CPUTIME_ID = 3, &ts)` (`mov w0, #3`
//      at `0x02d5ac`) and computes `ts.tv_sec * 1000000 + SignedDivBy1000(ts.tv_nsec)`.
// [VN] `CurrentThreadCPUTimeMicroseconds()` tại `0x02d598..0x02d5dc`: gọi
//      `clock_gettime(3, &ts)` và tính `tv_sec * 1000000 + tv_nsec / 1000`.
int64_t CurrentThreadCPUTimeMicroseconds() {
#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
    timespec ts{};
    ::clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
    return static_cast<int64_t>(ts.tv_sec) * 1000000LL +
           SignedDivBy1000(static_cast<int64_t>(ts.tv_nsec));
#else
    return CurrentTimeMicroseconds();
#endif
}

// [EN] `ToTimeSpecFromNow(int64_t delta_microseconds)` @ 0x02d5e8..0x02d65c.
// [VN] `ToTimeSpecFromNow(int64_t delta_microseconds)` tại `0x02d5e8..0x02d65c`.
timespec ToTimeSpecFromNow(int64_t delta_microseconds) {
    const int64_t total_ns =
        static_cast<int64_t>(CurrentTimeNanoseconds()) +
        (delta_microseconds > 0 ? delta_microseconds * 1000LL : 0LL);
    const int64_t total_us = SignedDivBy1000(total_ns);
    const int64_t sec = SignedDivBy1000000(total_us * 1000LL);
    const int64_t rem_ns = total_ns - sec * 1000000000LL;
    timespec ts{};
    ts.tv_sec = static_cast<time_t>(sec);
    ts.tv_nsec = static_cast<long>(rem_ns >= 0 ? rem_ns : 0);
    return ts;
}

// ============================================================================
// 7. `RefCountedStringImpl` (.text 0x02d684..0x02da58, 56 bytes = 0x38)
// ============================================================================

// [EN] Global singleton `RefCountedStringImpl::Unsafe::kEmptyString` at `.bss 0x0382f8` (`56 bytes`).
// [VN] Đối tượng toàn cục `RefCountedStringImpl::Unsafe::kEmptyString` tại `.bss 0x0382f8` (`56 byte`).
RefCountedStringImpl RefCountedStringImpl::Unsafe::kEmptyString("", 0);

// [EN] `RefCountedStringImpl::Unsafe::RawCreate(const char*, size_t)` @ 0x02d6f8:
//      Returns `&kEmptyString` (`0x0382f8`) when `str == nullptr || len == 0`,
//      otherwise allocates `operator new(0x38)` (`56 bytes`).
// [VN] `RefCountedStringImpl::Unsafe::RawCreate` tại `0x02d6f8`: trả về
//      `&kEmptyString` nếu chuỗi rỗng, ngược lại cấp phát `56 byte` (`0x38`).
RefCountedStringImpl* RefCountedStringImpl::Unsafe::RawCreate(const char* str, size_t len) {
    if (str == nullptr || len == 0) {
        kEmptyString.AddRef();
        return &kEmptyString;
    }
    return new RefCountedStringImpl(str, len);
}

RefCountedStringImpl* RefCountedStringImpl::Unsafe::RawCreate(std::string str) {
    if (str.empty()) {
        kEmptyString.AddRef();
        return &kEmptyString;
    }
    return new RefCountedStringImpl(std::move(str));
}

// [EN] `RefCountedStringImpl(const char*, size_t)` @ 0x02d754..0x02d7fc:
//      Initializes `m_refCount = 1`, copies string, computes `CityHash64` (`0x022314`)
//      or stores `0x9AE16A3B2F90404FULL` (`0x02d7b8..0x02d7c8`) when empty,
//      stores `m_utf8Len` at `+0x30` and `m_utf16Len = UINT32_MAX` (`-1`) at `+0x34`.
// [VN] Hàm tạo `RefCountedStringImpl(const char*, size_t)` tại `0x02d754..0x02d7fc`.
RefCountedStringImpl::RefCountedStringImpl(const char* str)
    : RefCountedStringImpl(str, str != nullptr ? std::strlen(str) : 0) {}

RefCountedStringImpl::RefCountedStringImpl(const char* str, size_t len)
    : m_refCount(1),
      m_str(str != nullptr ? str : "", str != nullptr ? len : 0),
      m_hash(m_str.empty() ? constants::kCityHashK2
                           : CityHash64(m_str.data(), m_str.size())),
      m_utf8Len(static_cast<uint32_t>(LengthCalculatedByUTF32(m_str))),
      m_utf16Len(UINT32_MAX) {}

RefCountedStringImpl::RefCountedStringImpl(std::string str)
    : m_refCount(1),
      m_str(std::move(str)),
      m_hash(m_str.empty() ? constants::kCityHashK2
                           : CityHash64(m_str.data(), m_str.size())),
      m_utf8Len(static_cast<uint32_t>(LengthCalculatedByUTF32(m_str))),
      m_utf16Len(UINT32_MAX) {}

// [EN] `RefCountedStringImpl::length_utf16()` @ 0x02d9d4:
//      Lazily computes `U8StringToU16(m_str).size()` when `m_utf16Len == UINT32_MAX`.
// [VN] `RefCountedStringImpl::length_utf16()` tại `0x02d9d4`: tính độ dài UTF-16
//      lười (lazy) khi `m_utf16Len == UINT32_MAX`.
uint32_t RefCountedStringImpl::length_utf16() {
    if (m_utf16Len == UINT32_MAX) {
        m_utf16Len = static_cast<uint32_t>(U8StringToU16(m_str).size());
    }
    return m_utf16Len;
}

} // namespace base
} // namespace lynx
