// ============================================================================
// File: lynxbase_string_crypto.h
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: RFC 1321 MD5, CityHash64, DataURIUtil, Base64Decode, js_dtoa,
//            String & UTF-8/16/32 Algorithms, High-Precision Time &
//            RefCountedStringImpl (.text 0x01ca70..0x01f0b4, 0x029410..0x02f6f0)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Clean-room C++17 header declaring the cryptographic/hash algorithms
//      (`lynx::base::md5`, `CityHash64`), binary/DataURI codecs (`FileUtils`,
//      `DataURIUtil`, `Base64Decode`), JavaScript number-to-string formatter
//      (`js_dtoa`), UTF-8/16/32 string manipulation suite, high-precision
//      time utilities (`CurrentSystemTime*`, `CurrentTime*`), and the 56-byte
//      `RefCountedStringImpl` class in `liblynxbase.so`.
// [VN] File header C++17 tái tạo sạch các thuật toán băm (`lynx::base::md5`,
//      `CityHash64`), bộ giải mã nhị phân/DataURI (`FileUtils`, `DataURIUtil`,
//      `Base64Decode`), bộ định dạng số thực chuẩn JavaScript (`js_dtoa`),
//      bộ hàm xử lý chuỗi UTF-8/16/32, các hàm thời gian độ chính xác cao,
//      và lớp `RefCountedStringImpl` (56 byte) trong `liblynxbase.so`.
// ============================================================================

#ifndef LYNXBASE_STRING_CRYPTO_H_
#define LYNXBASE_STRING_CRYPTO_H_

#include "lynxbase_types.h"

namespace lynx {
namespace base {

// ============================================================================
// 1. `FileUtils` (.text 0x01ca70..0x01cc60)
// ============================================================================
class FileUtils {
public:
    // [EN] `FileUtils::ReadFileBinary` @ 0x01ca70: reads up to `max_size` bytes
    //      from `path` using `fopen("rb")` (`.rodata 0x00cd38`).
    // [VN] `FileUtils::ReadFileBinary` @ 0x01ca70: đọc tối đa `max_size` byte
    //      từ đường dẫn `path` qua `fopen("rb")`.
    static bool ReadFileBinary(const std::string& path,
                               size_t max_size,
                               std::vector<uint8_t>& out_bytes);

    // [EN] `FileUtils::WriteFileBinary` @ 0x01cb50: writes `size` bytes to `path`
    //      using `fopen("wb+")` (`.rodata 0x00cd3b`).
    // [VN] `FileUtils::WriteFileBinary` @ 0x01cb50: ghi `size` byte ra `path`
    //      qua `fopen("wb+")`.
    static bool WriteFileBinary(const std::string& path,
                                const uint8_t* data,
                                size_t size);
};

// ============================================================================
// 2. RFC 1321 MD5 (`lynx::base::md5` @ 0x01efe4..0x01f0b4, internal 0x01e2d8..0x01efdc)
//    & `CityHash64` (`0x022314..0x022628`)
// ============================================================================
struct Md5Context {
    uint64_t bit_count{0};       // +0x00 (`q0` low 64 bits zeroed at 0x01eff8)
    uint32_t state[4]{           // +0x08..+0x14 (`0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476`)
        constants::kMd5InitA,
        constants::kMd5InitB,
        constants::kMd5InitC,
        constants::kMd5InitD,
    };
    uint8_t buffer[64]{};        // +0x18..+0x57
    uint8_t digest[16]{};        // +0x58..+0x67
};

std::string md5(const char* data, size_t length);
std::string md5(const std::string& str);

uint64_t CityHash64(const char* buf, size_t len);

// ============================================================================
// 3. `DataURIUtil` (.text 0x029410..0x029550) & `Base64Decode` (.text 0x02f290)
// ============================================================================
class DataURIUtil {
public:
    // [EN] `DataURIUtil::IsDataURI` @ 0x029410: returns true if `uri` begins
    //      with `"data:"` (`.rodata 0x00cc8f`, length 5).
    // [VN] `DataURIUtil::IsDataURI` @ 0x029410: trả về true nếu `uri` bắt đầu
    //      bằng `"data:"` (`.rodata 0x00cc8f`, độ dài 5).
    static bool IsDataURI(std::string_view uri);

    // [EN] `DataURIUtil::DecodeDataURI` @ 0x029450: scans for the 8-byte
    //      little-endian marker `";base64,"` (`0x2C3436657361623BULL`), computes
    //      buffer capacity `(b64_len >> 2) * 3 + 2`, decodes via `Base64Decode`,
    //      and invokes `buffer_factory(capacity)` returning decoded byte count.
    // [VN] `DataURIUtil::DecodeDataURI` @ 0x029450: tìm chuỗi 8 byte `";base64,"`
    //      (`0x2C3436657361623BULL`), tính kích thước bộ đệm `(b64_len >> 2) * 3 + 2`,
    //      và giải mã qua `Base64Decode`.
    static int32_t DecodeDataURI(std::string_view uri,
                                 MoveOnlyClosure<char*(size_t)> buffer_factory);
};

size_t Base64Decode(std::string_view input, char* output_buffer);
std::string Base64Encode(const uint8_t* data, size_t len);

// ============================================================================
// 4. `js_dtoa` (.text 0x029554..0x029674)
// ============================================================================
// [EN] Formats IEEE-754 `double` according to ECMAScript Number::toString rules:
//      - Checks `(bits & 0x7FFFFFFFFFFFFFFFULL) >= 0x7FF0000000000000ULL` (`0x029574`)
//        and writes `"null"` (`0x6C6C756E` at `0x029580`) for NaN/Infinity.
//      - Fast-path for exact 53-bit integers in `[-0x1FFFFFFFFFFFFF, +0x1FFFFFFFFFFFFF]`
//        using unsigned reciprocal magic `0xCCCCCCCCCCCCCCCDULL` (`umulh` >> 3).
//      - General Grisu3/Dragonbox shortest-representation fallback (`0x02df40`).
// [VN] Định dạng số thực IEEE-754 `double` theo quy tắc ECMAScript: trả về
//      `"null"` cho NaN/Infinity, dùng nhánh nhanh số nguyên 53-bit với hằng số
//      chia 10 `0xCCCCCCCCCCCCCCCDULL`, hoặc biểu diễn ngắn nhất cho số thực.
size_t js_dtoa(double value, char* buffer);

// ============================================================================
// 5. String Manipulation & UTF-8/16/32 Conversion (.text 0x0299a4..0x02cc98)
// ============================================================================
bool SplitString(std::string_view input,
                 char delimiter,
                 bool trim_whitespace,
                 const std::function<bool(const char*, size_t, int)>& handler);

void SplitString(std::string_view input,
                 char delimiter,
                 std::vector<std::string>& out_tokens);

void SplitStringByChars(std::string_view input,
                        std::string_view delimiters,
                        std::vector<std::string>& out_tokens);

std::vector<std::string> SplitStringIgnoreBracket(std::string_view input, char delimiter);

bool BeginsWith(std::string_view str, std::string_view prefix);
bool EndsWith(std::string_view str, std::string_view suffix);
bool BeginsWithCaseInsensitive(std::string_view str, std::string_view prefix);
bool EndsWithCaseInsensitive(std::string_view str, std::string_view suffix);
bool EqualsIgnoreCase(std::string_view a, std::string_view b);

std::string StringToLowerASCII(std::string_view str);
std::string SnakeToCamel(std::string_view str);
std::string CamelToDash(std::string_view str);

std::string_view TrimString(std::string_view str,
                            std::string_view trim_chars = " \t\r\n",
                            TrimPositions positions = TrimPositions::TRIM_ALL);
std::string TrimString(const std::string& str,
                       const char* trim_chars = " \t\r\n",
                       TrimPositions positions = TrimPositions::TRIM_ALL);

void ReplaceAll(std::string& str, std::string_view from, std::string_view to);
std::string RemoveSpaces(std::string_view str);

std::string FormatString(const char* fmt, ...);
void AppendFormatString(std::string& target, const char* fmt, ...);

bool StringToDouble(const std::string& input, double& output, bool error_on_trailing = true);
bool StringToFloat(const std::string& input, float& output, bool error_on_trailing = true);
bool StringToInt(const std::string& input, int64_t& output, uint8_t base = 10);
bool StringToUInt64(const std::string& input, uint64_t& output, uint8_t base = 10);

std::u16string U8StringToU16(std::string_view u8_str);
std::string U16StringToU8(std::u16string_view u16_str);
std::u32string U8StringToU32(std::string_view u8_str);
std::string U32StringToU8(std::u32string_view u32_str);
std::u32string U16StringToU32(std::u16string_view u16_str);
std::u16string U32StringToU16(std::u32string_view u32_str);

size_t UTF8IndexToCIndex(const char* utf8_str, size_t byte_len, size_t codepoint_index);
size_t LengthCalculatedByUTF32(const std::string& utf8_str);

// ============================================================================
// 6. High-Precision Time & Reciprocal Division (.text 0x02d520..0x02d65c)
// ============================================================================
uint64_t CurrentSystemTimeMilliseconds();
uint64_t CurrentSystemTimeMicroseconds();
int64_t CurrentTimeMilliseconds();
int64_t CurrentTimeMicroseconds();
uint64_t CurrentTimeNanoseconds();
int64_t CurrentThreadCPUTimeMicroseconds();
timespec ToTimeSpecFromNow(int64_t delta_microseconds);

// ============================================================================
// 7. `RefCountedStringImpl` (.text 0x02d684..0x02da58, 56 bytes = 0x38,
//    vtable @ 0x034768, `Unsafe::kEmptyString` @ 0x0382f8)
// ============================================================================
class RefCountedStringImpl {
public:
    struct Unsafe {
        static RefCountedStringImpl kEmptyString;
        static RefCountedStringImpl* RawCreate(const char* str, size_t len);
        static RefCountedStringImpl* RawCreate(std::string str);
    };

    explicit RefCountedStringImpl(const char* str);
    RefCountedStringImpl(const char* str, size_t len);
    explicit RefCountedStringImpl(std::string str);
    virtual ~RefCountedStringImpl() = default;

    const std::string& str() const noexcept { return m_str; }
    const char* c_str() const noexcept { return m_str.c_str(); }
    uint64_t hash() const noexcept { return m_hash; }
    uint32_t length() const noexcept { return m_utf8Len; }
    uint32_t length_utf8() const noexcept { return m_utf8Len; }
    uint32_t length_utf16();

    void AddRef() const noexcept {
        m_refCount.fetch_add(1, std::memory_order_relaxed);
    }
    void Release() const noexcept {
        if (this != &Unsafe::kEmptyString &&
            m_refCount.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete this;
        }
    }

private:
    mutable std::atomic<int32_t> m_refCount{1}; // +0x08
    std::string m_str;                          // +0x10 (24 bytes libc++ std::string)
    uint64_t m_hash{constants::kCityHashK2};    // +0x28 (CityHash64)
    uint32_t m_utf8Len{0};                      // +0x30
    uint32_t m_utf16Len{UINT32_MAX};            // +0x34 (lazy UTF-16 length cache)
};

} // namespace base
} // namespace lynx

#endif // LYNXBASE_STRING_CRYPTO_H_
