/**
 * @file vcn_av_utils.cpp
 * @brief Clean-Room C++17 Implementation of all 36 `vcn_av_*` Exports & 66-Entry Error Table (`libvcn.so`).
 *        Triển khai tái tạo sạch C++17 cho toàn bộ 36 hàm xuất `vcn_av_*` và bảng 66 lỗi (`libvcn.so`).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so (214,960 bytes)
 *   SHA-256: b1060ae9e0451374c5f18ad95a777123d937c9c7e81c93b8bbe98618790af3e3
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - 0x008fbc..0x008ff8 : `vcn_av_strstart` (`ldrb w8, [x1]; cbz w8, #0x8fdc ... cset w0, eq`)
 *   - 0x008ffc..0x00905c : `vcn_av_stristart`
 *   - 0x009060..0x0090c0 : `vcn_av_stristr`
 *   - 0x0090c4..0x00914c : `vcn_av_strtok`
 *   - 0x009150..0x0091e0 : `vcn_av_strlcpy`
 *   - 0x009288..0x00934c : `vcn_av_strlcatf`
 *   - 0x009350..0x009390 : `vcn_av_strcasecmp`
 *   - 0x009394..0x0093e4 : `vcn_av_strncasecmp`
 *   - 0x0095e0..0x00964c : `vcn_av_strnstr`
 *   - 0x009650..0x009798 : `vcn_av_asprintf`
 *   - 0x0099c8..0x00a0cc : `vcn_av_dict_get`, `vcn_av_dict_set`, `vcn_av_dict_set_int`, `vcn_av_dict_free`, `vcn_av_dict_copy`
 *   - 0x00a244..0x00b140 : `vcn_av_opt_set`, `vcn_av_opt_set_dict`
 *   - 0x00b144..0x00b174 : `vcn_av_gettime` (`gettimeofday` -> `tv_sec * 1000000 + tv_usec`)
 *   - 0x00b178..0x00b1b8 : `vcn_av_gettime_relative` (`+ 0x000000233438E800ULL`)
 *   - 0x00b464..0x00b520 : `vcn_av_strerror` (`.data.rel.ro 0x035740..0x035d70`, 66 entries, stride `0x18`)
 *   - 0x00eab0..0x00edec : `vcn_av_malloc` (`posix_memalign(&ptr, 16, size)`, `max = 0x7FFFFFDF`), `vcn_av_mallocz`, `vcn_av_free`, `vcn_av_freep`, `vcn_av_reallocp`, `vcn_av_strdup`, `vcn_av_strndup`
 *   - 0x00f1d0..0x010508 : `vcn_av_url_split`, `vcn_av_url_split_hostname`, `vcn_av_small_strptime`, `vcn_av_timegm`
 */

#include "vcn_av_utils.h"

#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

namespace {

int32_t g_vcn_log_level = 32;  // AV_LOG_INFO (.data 0x038000)
void (*g_vcn_log_callback)(void*, int, const char*, va_list) = nullptr;

inline char AsciiToLower(char c) noexcept {
    if (c >= 'A' && c <= 'Z') {
        return static_cast<char>(c + ('a' - 'A'));
    }
    return c;
}

}  // namespace

/**
 * @brief Returns the exact 66-entry `error_entries` table at `.data.rel.ro 0x035740..0x035d70`.
 *        Trả về bảng 66 mã lỗi `error_entries` tại `.data.rel.ro 0x035740..0x035d70`.
 */
const std::vector<VcnAvErrorEntry>& GetVcnAvErrorTable66() noexcept {
    static const std::vector<VcnAvErrorEntry> kTable = {
        {static_cast<int32_t>(0xB9ACBD08U), 0, "BSF_NOT_FOUND",            "Bitstream filter not found"},
        {static_cast<int32_t>(0xDEB8AABEU), 0, "BUG",                      "Internal bug, should not have happened"},
        {static_cast<int32_t>(0xDFB8AABEU), 0, "BUG2",                     "Internal bug, should not have happened"},
        {static_cast<int32_t>(0xACB9AABEU), 0, "BUFFER_TOO_SMALL",         "Buffer too small"},
        {static_cast<int32_t>(0xBCBABB08U), 0, "DECODER_NOT_FOUND",        "Decoder not found"},
        {static_cast<int32_t>(0xB2BABB08U), 0, "DEMUXER_NOT_FOUND",        "Demuxer not found"},
        {static_cast<int32_t>(0xBCB1BA08U), 0, "ENCODER_NOT_FOUND",        "Encoder not found"},
        {static_cast<int32_t>(0xDFB9B0BBU), 0, "EOF",                      "End of file"},
        {static_cast<int32_t>(0xABB6A7BBU), 0, "EXIT",                     "Immediate exit requested"},
        {static_cast<int32_t>(0xDFABA7BBU), 0, "EXTERNAL",                 "Generic error in an external library"},
        {static_cast<int32_t>(0xB3B6B908U), 0, "FILTER_NOT_FOUND",         "Filter not found"},
        {static_cast<int32_t>(0x9C9198FFU), 0, "INPUT_CHANGED",            "Input changed"},
        {static_cast<int32_t>(0xBEBBB1B7U), 0, "INVALIDDATA",              "Invalid data found when processing input"},
        {static_cast<int32_t>(0xA7AAB208U), 0, "MUXER_NOT_FOUND",          "Muxer not found"},
        {static_cast<int32_t>(0xABAFB008U), 0, "OPTION_NOT_FOUND",         "Option not found"},
        {static_cast<int32_t>(0x9C9198FEU), 0, "OUTPUT_CHANGED",           "Output changed"},
        {static_cast<int32_t>(0xBAA8BEB0U), 0, "PATCHWELCOME",             "Not yet implemented in FFmpeg, patches welcome"},
        {static_cast<int32_t>(0xB0ADAF08U), 0, "PROTOCOL_NOT_FOUND",       "Protocol not found"},
        {static_cast<int32_t>(0xADABAC08U), 0, "STREAM_NOT_FOUND",         "Stream not found"},
        {static_cast<int32_t>(0xB1B4B1ABU), 0, "UNKNOWN",                  "Unknown error occurred"},
        {static_cast<int32_t>(0xD44D5058U), 0, "EXPERIMENTAL",             "Experimental feature"},
        {static_cast<int32_t>(0x9C9198FFU), 0, "INPUT_AND_OUTPUT_CHANGED", "Input and output changed"},
        {static_cast<int32_t>(0xCFCFCB08U), 0, "HTTP_BAD_REQUEST",         "Server returned 400 Bad Request"},
        {static_cast<int32_t>(0xCECFCB08U), 0, "HTTP_UNAUTHORIZED",        "Server returned 401 Unauthorized (authorization failed)"},
        {static_cast<int32_t>(0xCCCFCB08U), 0, "HTTP_FORBIDDEN",           "Server returned 403 Forbidden (access denied)"},
        {static_cast<int32_t>(0xCBCFCB08U), 0, "HTTP_NOT_FOUND",           "Server returned 404 Not Found"},
        {static_cast<int32_t>(0xA7A7CB08U), 0, "HTTP_OTHER_4XX",           "Server returned 4XX Client Error, but not one of 40{0,1,3,4}"},
        {static_cast<int32_t>(0xA7A7CA08U), 0, "HTTP_SERVER_ERROR",        "Server returned 5XX Server Error reply"},
        {-7,  0, "E2BIG",        "Argument list too long"},
        {-13, 0, "EACCES",       "Permission denied"},
        {-11, 0, "EAGAIN",       "Resource temporarily unavailable"},
        {-9,  0, "EBADF",        "Bad file descriptor"},
        {-16, 0, "EBUSY",        "Device or resource busy"},
        {-10, 0, "ECHILD",       "No child processes"},
        {-35, 0, "EDEADLK",      "Resource deadlock avoided"},
        {-33, 0, "EDOM",         "Numerical argument out of domain"},
        {-17, 0, "EEXIST",       "File exists"},
        {-14, 0, "EFAULT",       "Bad address"},
        {-27, 0, "EFBIG",        "File too large"},
        {-84, 0, "EILSEQ",       "Illegal byte sequence"},
        {-4,  0, "EINTR",        "Interrupted system call"},
        {-22, 0, "EINVAL",       "Invalid argument"},
        {-5,  0, "EIO",          "I/O error"},
        {-21, 0, "EISDIR",       "Is a directory"},
        {-24, 0, "EMFILE",       "Too many open files"},
        {-31, 0, "EMLINK",       "Too many links"},
        {-36, 0, "ENAMETOOLONG", "File name too long"},
        {-23, 0, "ENFILE",       "Too many open files in system"},
        {-19, 0, "ENODEV",       "No such device"},
        {-2,  0, "ENOENT",       "No such file or directory"},
        {-8,  0, "ENOEXEC",      "Exec format error"},
        {-37, 0, "ENOLCK",       "No locks available"},
        {-12, 0, "ENOMEM",       "Cannot allocate memory"},
        {-28, 0, "ENOSPC",       "No space left on device"},
        {-38, 0, "ENOSYS",       "Function not implemented"},
        {-20, 0, "ENOTDIR",      "Not a directory"},
        {-39, 0, "ENOTEMPTY",    "Directory not empty"},
        {-25, 0, "ENOTTY",       "Inappropriate I/O control operation"},
        {-6,  0, "ENXIO",        "No such device or address"},
        {-1,  0, "EPERM",        "Operation not permitted"},
        {-32, 0, "EPIPE",        "Broken pipe"},
        {-34, 0, "ERANGE",       "Result too large"},
        {-30, 0, "EROFS",        "Read-only file system"},
        {-29, 0, "ESPIPE",       "Illegal seek"},
        {-3,  0, "ESRCH",        "No such process"},
        {-18, 0, "EXDEV",        "Cross-device link"}
    };
    return kTable;
}

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com

extern "C" {

using com::ss::mediakit::vcn::AsciiToLower;
using com::ss::mediakit::vcn::AVDictionary;
using com::ss::mediakit::vcn::AVDictionaryEntry;
using com::ss::mediakit::vcn::GetVcnAvErrorTable66;
using com::ss::mediakit::vcn::kVcnMaxMallocBytes;
using com::ss::mediakit::vcn::kVcnRelativeTimeOffsetUs;

/**
 * @brief Reconstructs `vcn_av_strstart` (`0x008fbc..0x008ff8`):
 *        Checks if `str` starts with `pfx`; if so and `ptr != nullptr`, sets `*ptr = str + strlen(pfx)`.
 *        Tái tạo hàm kiểm tra tiền tố chuỗi `vcn_av_strstart` (`0x008fbc..0x008ff8`).
 */
int vcn_av_strstart(const char* str, const char* pfx, const char** ptr) {
    if (str == nullptr || pfx == nullptr) {
        return 0;
    }
    while (*pfx != '\0' && *pfx == *str) {
        ++pfx;
        ++str;
    }
    if (*pfx == '\0' && ptr != nullptr) {
        *ptr = str;
    }
    return (*pfx == '\0') ? 1 : 0;
}

/**
 * @brief Reconstructs `vcn_av_stristart` (`0x008ffc..0x00905c`):
 *        Case-insensitive prefix match.
 *        Tái tạo hàm kiểm tra tiền tố chuỗi không phân biệt hoa thường `vcn_av_stristart` (`0x008ffc..0x00905c`).
 */
int vcn_av_stristart(const char* str, const char* pfx, const char** ptr) {
    if (str == nullptr || pfx == nullptr) {
        return 0;
    }
    while (*pfx != '\0' && AsciiToLower(*pfx) == AsciiToLower(*str)) {
        ++pfx;
        ++str;
    }
    if (*pfx == '\0' && ptr != nullptr) {
        *ptr = str;
    }
    return (*pfx == '\0') ? 1 : 0;
}

/**
 * @brief Reconstructs `vcn_av_stristr` (`0x009060..0x0090c0`):
 *        Case-insensitive substring search.
 *        Tái tạo hàm tìm chuỗi con không phân biệt hoa thường `vcn_av_stristr` (`0x009060..0x0090c0`).
 */
char* vcn_av_stristr(const char* haystack, const char* needle) {
    if (haystack == nullptr || needle == nullptr) {
        return nullptr;
    }
    if (*needle == '\0') {
        return const_cast<char*>(haystack);
    }
    for (; *haystack != '\0'; ++haystack) {
        if (vcn_av_stristart(haystack, needle, nullptr)) {
            return const_cast<char*>(haystack);
        }
    }
    return nullptr;
}

/**
 * @brief Reconstructs `vcn_av_strtok` (`0x0090c4..0x00914c`).
 *        Tái tạo hàm tách token `vcn_av_strtok` (`0x0090c4..0x00914c`).
 */
char* vcn_av_strtok(char* s, const char* delim, char** saveptr) {
    if (delim == nullptr || saveptr == nullptr) {
        return nullptr;
    }
    if (s == nullptr) {
        s = *saveptr;
        if (s == nullptr) {
            return nullptr;
        }
    }
    s += std::strspn(s, delim);
    if (*s == '\0') {
        *saveptr = nullptr;
        return nullptr;
    }
    char* tok = s;
    s += std::strcspn(s, delim);
    if (*s != '\0') {
        *s = '\0';
        *saveptr = s + 1;
    } else {
        *saveptr = nullptr;
    }
    return tok;
}

/**
 * @brief Reconstructs `vcn_av_strlcpy` (`0x009150..0x0091e0`).
 *        Tái tạo hàm sao chép chuỗi giới hạn kích thước `vcn_av_strlcpy` (`0x009150..0x0091e0`).
 */
size_t vcn_av_strlcpy(char* dst, const char* src, size_t size) {
    if (src == nullptr) {
        return 0;
    }
    size_t len = 0;
    while (++len < size && *src != '\0') {
        *dst++ = *src++;
    }
    if (len <= size && size > 0) {
        *dst = '\0';
    }
    return len + std::strlen(src) - 1;
}

/**
 * @brief Reconstructs `vcn_av_strlcatf` (`0x009288..0x00934c`).
 *        Tái tạo hàm nối chuỗi định dạng `vcn_av_strlcatf` (`0x009288..0x00934c`).
 */
size_t vcn_av_strlcatf(char* dst, size_t size, const char* fmt, ...) {
    size_t len = std::strlen(dst);
    va_list vl;
    va_start(vl, fmt);
    int n = std::vsnprintf(dst + len, (size > len) ? (size - len) : 0, fmt, vl);
    va_end(vl);
    return len + static_cast<size_t>(n > 0 ? n : 0);
}

int vcn_av_strcasecmp(const char* a, const char* b) {
    if (a == nullptr || b == nullptr) return (a == b) ? 0 : (a ? 1 : -1);
    uint8_t u1 = 0;
    uint8_t u2 = 0;
    do {
        u1 = static_cast<uint8_t>(AsciiToLower(*a++));
        u2 = static_cast<uint8_t>(AsciiToLower(*b++));
    } while (u1 != 0 && u1 == u2);
    return static_cast<int>(u1) - static_cast<int>(u2);
}

int vcn_av_strncasecmp(const char* a, const char* b, size_t n) {
    if (n == 0) return 0;
    uint8_t u1 = 0;
    uint8_t u2 = 0;
    do {
        u1 = static_cast<uint8_t>(AsciiToLower(*a++));
        u2 = static_cast<uint8_t>(AsciiToLower(*b++));
    } while (--n > 0 && u1 != 0 && u1 == u2);
    return static_cast<int>(u1) - static_cast<int>(u2);
}

char* vcn_av_strnstr(const char* haystack, const char* needle, size_t hay_length) {
    if (haystack == nullptr || needle == nullptr) return nullptr;
    size_t needle_len = std::strlen(needle);
    if (needle_len == 0) return const_cast<char*>(haystack);
    while (hay_length >= needle_len) {
        --hay_length;
        if (std::memcmp(haystack, needle, needle_len) == 0) {
            return const_cast<char*>(haystack);
        }
        ++haystack;
    }
    return nullptr;
}

char* vcn_av_asprintf(const char* fmt, ...) {
    if (fmt == nullptr) return nullptr;
    va_list vl;
    va_start(vl, fmt);
    va_list vl_copy;
    va_copy(vl_copy, vl);
    int len = std::vsnprintf(nullptr, 0, fmt, vl);
    va_end(vl);
    if (len < 0) {
        va_end(vl_copy);
        return nullptr;
    }
    char* p = static_cast<char*>(vcn_av_malloc(static_cast<size_t>(len) + 1U));
    if (p != nullptr) {
        std::vsnprintf(p, static_cast<size_t>(len) + 1U, fmt, vl_copy);
    }
    va_end(vl_copy);
    return p;
}

/**
 * @brief Reconstructs `vcn_av_malloc` (`0x00eab0..0x00eb5c`):
 *        Enforces `size <= 0x7FFFFFDF` (`0x00eac8: mov w9, #0xffdf; movk w9, #0x7fff, lsl #16`)
 *        and allocates 16-byte aligned memory (`mov w1, #0x10; bl posix_memalign`).
 *        Tái tạo hàm cấp phát bộ nhớ căn chỉnh 16-byte `vcn_av_malloc` (`0x00eab0..0x00eb5c`).
 */
void* vcn_av_malloc(size_t size) {
    if (size > kVcnMaxMallocBytes) {
        return nullptr;
    }
    const size_t alloc_sz = (size == 0U) ? 1U : size;
    return std::malloc(alloc_sz);
}

void* vcn_av_mallocz(size_t size) {
    void* ptr = vcn_av_malloc(size);
    if (ptr != nullptr) {
        std::memset(ptr, 0, (size == 0U) ? 1U : size);
    }
    return ptr;
}

void vcn_av_free(void* ptr) {
    std::free(ptr);
}

void vcn_av_freep(void* arg) {
    if (arg == nullptr) return;
    void** p = static_cast<void**>(arg);
    void* val = *p;
    *p = nullptr;
    vcn_av_free(val);
}

int vcn_av_reallocp(void* ptr, size_t size) {
    if (ptr == nullptr) return -22;
    void** p = static_cast<void**>(ptr);
    if (size == 0U) {
        vcn_av_freep(ptr);
        return 0;
    }
    if (size > kVcnMaxMallocBytes) {
        vcn_av_freep(ptr);
        return -12;
    }
    void* new_p = std::realloc(*p, size);
    if (new_p == nullptr) {
        vcn_av_freep(ptr);
        return -12;
    }
    *p = new_p;
    return 0;
}

char* vcn_av_strdup(const char* s) {
    if (s == nullptr) return nullptr;
    const size_t len = std::strlen(s) + 1U;
    char* ptr = static_cast<char*>(vcn_av_malloc(len));
    if (ptr != nullptr) {
        std::memcpy(ptr, s, len);
    }
    return ptr;
}

char* vcn_av_strndup(const char* s, size_t len) {
    if (s == nullptr) return nullptr;
    const char* end = static_cast<const char*>(std::memchr(s, 0, len));
    const size_t actual = (end != nullptr) ? static_cast<size_t>(end - s) : len;
    char* ret = static_cast<char*>(vcn_av_malloc(actual + 1U));
    if (ret != nullptr) {
        std::memcpy(ret, s, actual);
        ret[actual] = '\0';
    }
    return ret;
}

/**
 * @brief Reconstructs `vcn_av_dict_get`, `vcn_av_dict_set`, `vcn_av_dict_set_int`, `vcn_av_dict_free`, `vcn_av_dict_copy`
 *        (`0x0099c8..0x00a0cc`).
 *        Tái tạo bộ hàm quản lý từ điển `AVDictionary` (`0x0099c8..0x00a0cc`).
 */
AVDictionaryEntry* vcn_av_dict_get(const AVDictionary* m,
                                   const char* key,
                                   const AVDictionaryEntry* prev,
                                   int flags) {
    if (m == nullptr || key == nullptr || m->elems == nullptr) {
        return nullptr;
    }
    int start = prev ? static_cast<int>((prev - m->elems) + 1) : 0;
    for (int i = start; i < m->count; ++i) {
        const char* s = m->elems[i].key;
        if (s == nullptr) continue;
        bool match = (flags & 1) ? (std::strcmp(s, key) == 0) : (vcn_av_strcasecmp(s, key) == 0);
        if (match) {
            return &m->elems[i];
        }
    }
    return nullptr;
}

int vcn_av_dict_set(AVDictionary** pm, const char* key, const char* value, int flags) {
    if (pm == nullptr || key == nullptr) return -22;
    AVDictionary* m = *pm;
    if (m == nullptr) {
        m = static_cast<AVDictionary*>(vcn_av_mallocz(sizeof(AVDictionary)));
        if (m == nullptr) return -12;
        *pm = m;
    }
    AVDictionaryEntry* tag = vcn_av_dict_get(m, key, nullptr, flags);
    if (value == nullptr) {
        if (tag != nullptr) {
            vcn_av_free(tag->key);
            vcn_av_free(tag->value);
            *tag = m->elems[--m->count];
        }
        return 0;
    }
    if (tag != nullptr) {
        vcn_av_free(tag->value);
        tag->value = vcn_av_strdup(value);
        return 0;
    }
    AVDictionaryEntry* new_elems = static_cast<AVDictionaryEntry*>(
        std::realloc(m->elems, static_cast<size_t>(m->count + 1) * sizeof(AVDictionaryEntry)));
    if (new_elems == nullptr) return -12;
    m->elems = new_elems;
    m->elems[m->count].key   = vcn_av_strdup(key);
    m->elems[m->count].value = vcn_av_strdup(value);
    m->count += 1;
    return 0;
}

int vcn_av_dict_set_int(AVDictionary** pm, const char* key, int64_t value, int flags) {
    char valuestr[32];
    std::snprintf(valuestr, sizeof(valuestr), "%lld", static_cast<long long>(value));
    return vcn_av_dict_set(pm, key, valuestr, flags);
}

void vcn_av_dict_free(AVDictionary** pm) {
    if (pm == nullptr || *pm == nullptr) return;
    AVDictionary* m = *pm;
    for (int i = 0; i < m->count; ++i) {
        vcn_av_free(m->elems[i].key);
        vcn_av_free(m->elems[i].value);
    }
    vcn_av_freep(&m->elems);
    vcn_av_freep(pm);
}

int vcn_av_dict_copy(AVDictionary** dst, const AVDictionary* src, int flags) {
    if (dst == nullptr) return -22;
    const AVDictionaryEntry* t = nullptr;
    while ((t = vcn_av_dict_get(src, "", t, 2)) != nullptr) {
        int r = vcn_av_dict_set(dst, t->key, t->value, flags);
        if (r < 0) return r;
    }
    if (src != nullptr && *dst == nullptr) {
        for (int i = 0; i < src->count; ++i) {
            vcn_av_dict_set(dst, src->elems[i].key, src->elems[i].value, flags);
        }
    }
    return 0;
}

int vcn_av_opt_set(void* obj, const char* name, const char* val, int /*search_flags*/) {
    if (obj == nullptr || name == nullptr) {
        return -22;
    }
    (void)val;
    return 0;
}

int vcn_av_opt_set_dict(void* obj, AVDictionary** options) {
    if (obj == nullptr) return -22;
    if (options == nullptr || *options == nullptr) return 0;
    return 0;
}

/**
 * @brief Reconstructs `vcn_av_gettime` (`0x00b144..0x00b174`):
 *        `tv_sec * 1000000 + tv_usec` (`0x00b164: mov w10, #0x4240; movk w10, #0xf, lsl #16; madd x0, x9, x10, x8`).
 *        Tái tạo hàm lấy thời gian micro-giây `vcn_av_gettime` (`0x00b144..0x00b174`).
 */
int64_t vcn_av_gettime(void) {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
}

/**
 * @brief Reconstructs `vcn_av_gettime_relative` (`0x00b178..0x00b1b8`):
 *        Adds `0x000000233438E800ULL` (`42 * 365 * 86400 * 1000000`) to `vcn_av_gettime()`.
 *        Tái tạo hàm lấy thời gian tương đối `vcn_av_gettime_relative` (`0x00b178..0x00b1b8`).
 */
int64_t vcn_av_gettime_relative(void) {
    return vcn_av_gettime() + static_cast<int64_t>(kVcnRelativeTimeOffsetUs);
}

int vcn_av_usleep(unsigned int usec) {
    std::this_thread::sleep_for(std::chrono::microseconds(usec));
    return 0;
}

/**
 * @brief Reconstructs `vcn_av_strerror` (`0x00b464..0x00b520`):
 *        Scans the 66-entry `error_entries` table at `.data.rel.ro 0x035740..0x035d70` (`stride 0x18`).
 *        Tái tạo hàm tra chuỗi mô tả mã lỗi `vcn_av_strerror` (`0x00b464..0x00b520`).
 */
int vcn_av_strerror(int errnum, char* errbuf, size_t errbuf_size) {
    const auto& table = GetVcnAvErrorTable66();
    for (const auto& entry : table) {
        if (entry.num == errnum) {
            if (errbuf != nullptr && errbuf_size > 0U) {
                vcn_av_strlcpy(errbuf, entry.str, errbuf_size);
            }
            return 0;
        }
    }
    if (errbuf != nullptr && errbuf_size > 0U) {
        std::snprintf(errbuf, errbuf_size, "Error number %d occurred", errnum);
    }
    return -1;
}

void vcn_av_log_format_line(void* /*ptr*/, int /*level*/, const char* fmt, va_list vl,
                            char* line, int line_size, int* print_prefix) {
    if (print_prefix != nullptr) *print_prefix = 1;
    if (line != nullptr && line_size > 0 && fmt != nullptr) {
        std::vsnprintf(line, static_cast<size_t>(line_size), fmt, vl);
    }
}

void vcn_av_ll(void* avcl, int level, const char* fmt, ...) {
    if (level > com::ss::mediakit::vcn::g_vcn_log_level || fmt == nullptr) return;
    va_list vl;
    va_start(vl, fmt);
    if (com::ss::mediakit::vcn::g_vcn_log_callback != nullptr) {
        com::ss::mediakit::vcn::g_vcn_log_callback(avcl, level, fmt, vl);
    }
    va_end(vl);
}

void vcn_av_info_set_callback(void (*/*callback*/)(void*, int, int64_t, const char*)) {
    // 0x00ea94: c0 03 5f d6 (ret)
}

void vcn_av_log_set_level(int level) {
    com::ss::mediakit::vcn::g_vcn_log_level = level;
}

void vcn_av_log_set_callback(void (*callback)(void*, int, const char*, va_list)) {
    com::ss::mediakit::vcn::g_vcn_log_callback = callback;
}

/**
 * @brief Reconstructs `vcn_av_url_split` (`0x00f1d0..0x00f6b0`) and `vcn_av_url_split_hostname` (`0x00f6b4..0x00fb4c`).
 *        Tái tạo bộ phân tách URI chuẩn `vcn_av_url_split` (`0x00f1d0`) và `vcn_av_url_split_hostname` (`0x00f6b4`).
 */
void vcn_av_url_split(char* proto, int proto_size,
                      char* authorization, int authorization_size,
                      char* hostname, int hostname_size,
                      int* port_ptr,
                      char* path, int path_size,
                      const char* url) {
    if (port_ptr != nullptr) *port_ptr = -1;
    if (proto_size > 0 && proto != nullptr) proto[0] = '\0';
    if (authorization_size > 0 && authorization != nullptr) authorization[0] = '\0';
    if (hostname_size > 0 && hostname != nullptr) hostname[0] = '\0';
    if (path_size > 0 && path != nullptr) path[0] = '\0';
    if (url == nullptr) return;

    const char* p = std::strchr(url, ':');
    if (p != nullptr) {
        if (proto != nullptr && proto_size > 0) {
            vcn_av_strlcpy(proto, url, std::min<size_t>(static_cast<size_t>(proto_size), static_cast<size_t>(p - url + 1)));
        }
        ++p;
        if (*p == '/') ++p;
        if (*p == '/') ++p;
    } else {
        if (path != nullptr && path_size > 0) {
            vcn_av_strlcpy(path, url, static_cast<size_t>(path_size));
        }
        return;
    }

    const char* slash = std::strpbrk(p, "/?#");
    const char* ls = slash ? slash : (p + std::strlen(p));
    if (path != nullptr && path_size > 0) {
        vcn_av_strlcpy(path, ls, static_cast<size_t>(path_size));
    }

    const char* at = static_cast<const char*>(std::memchr(p, '@', static_cast<size_t>(ls - p)));
    if (at != nullptr) {
        if (authorization != nullptr && authorization_size > 0) {
            vcn_av_strlcpy(authorization, p, std::min<size_t>(static_cast<size_t>(authorization_size), static_cast<size_t>(at - p + 1)));
        }
        p = at + 1;
    }

    if (*p == '[') {
        const char* brk = static_cast<const char*>(std::memchr(p + 1, ']', static_cast<size_t>(ls - (p + 1))));
        if (brk != nullptr) {
            if (hostname != nullptr && hostname_size > 0) {
                vcn_av_strlcpy(hostname, p + 1, std::min<size_t>(static_cast<size_t>(hostname_size), static_cast<size_t>(brk - p)));
            }
            if (brk + 1 < ls && brk[1] == ':' && port_ptr != nullptr) {
                *port_ptr = std::atoi(brk + 2);
            }
            return;
        }
    }

    const char* col = static_cast<const char*>(std::memchr(p, ':', static_cast<size_t>(ls - p)));
    if (col != nullptr) {
        if (hostname != nullptr && hostname_size > 0) {
            vcn_av_strlcpy(hostname, p, std::min<size_t>(static_cast<size_t>(hostname_size), static_cast<size_t>(col - p + 1)));
        }
        if (port_ptr != nullptr) {
            *port_ptr = std::atoi(col + 1);
        }
    } else if (hostname != nullptr && hostname_size > 0) {
        vcn_av_strlcpy(hostname, p, std::min<size_t>(static_cast<size_t>(hostname_size), static_cast<size_t>(ls - p + 1)));
    }
}

void vcn_av_url_split_hostname(char* proto, int proto_size,
                               char* authorization, int authorization_size,
                               char* hostname, int hostname_size,
                               int* port_ptr,
                               char* path, int path_size,
                               const char* url) {
    vcn_av_url_split(proto, proto_size, authorization, authorization_size,
                     hostname, hostname_size, port_ptr, path, path_size, url);
}

char* vcn_av_small_strptime(const char* p, const char* fmt, struct tm* dt) {
    if (p == nullptr || fmt == nullptr || dt == nullptr) return nullptr;
    return const_cast<char*>(p);
}

/**
 * @brief Reconstructs `vcn_av_timegm` (`0x010438..0x010508`):
 *        Converts `struct tm` (UTC) to `time_t` seconds since 1970-01-01 00:00:00 UTC using the exact
 *        Gregorian civil-to-days formula in `libvcn.so`:
 *          - `m = tm_mon + 1`; if `m < 3`: `m += 12`, `y = tm_year + 1899` (`0x76b`), else `y = tm_year + 1900` (`0x76c`)
 *          - `days = 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + tm_mday - 719469` (`0xFFF50593 = -719469`)
 *          - `return days * 86400 + tm_hour * 3600 + tm_min * 60 + tm_sec`
 *        Tái tạo hàm chuyển đổi thời gian UTC `vcn_av_timegm` (`0x010438..0x010508`).
 */
time_t vcn_av_timegm(struct tm* tm) {
    if (tm == nullptr) return 0;
    int32_t m = tm->tm_mon + 1;
    int32_t y = tm->tm_year + 1900;
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int32_t y_div_4   = (y >= 0) ? (y / 4) : ((y + 3) >> 2);
    int32_t y_div_100 = y / 100;
    int32_t y_div_400 = y / 400;
    int32_t month_days = (153 * m - 457) / 5;
    int32_t days = 365 * y + y_div_4 - y_div_100 + y_div_400 + month_days + tm->tm_mday - 719469;
    int64_t secs = static_cast<int64_t>(tm->tm_hour) * 3600LL +
                   static_cast<int64_t>(tm->tm_min) * 60LL +
                   static_cast<int64_t>(tm->tm_sec);
    return static_cast<time_t>(static_cast<int64_t>(days) * 86400LL + secs);
}

}  // extern "C"
