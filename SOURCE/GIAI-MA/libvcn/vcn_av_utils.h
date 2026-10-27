/**
 * @file vcn_av_utils.h
 * @brief Clean-Room Header for all 36 `vcn_av_*` String, Dictionary, Option, Memory, Error & Time Exports (`libvcn.so`).
 *        Header tái tạo sạch toàn bộ 36 hàm xuất `vcn_av_*` xử lý chuỗi, từ điển, tùy chọn, bộ nhớ, lỗi và thời gian (`libvcn.so`).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so (214,960 bytes)
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x008fbc..0x009650 : `vcn_av_strstart`, `vcn_av_stristart`, `vcn_av_stristr`, `vcn_av_strtok`,
 *                            `vcn_av_strlcpy`, `vcn_av_strlcatf`, `vcn_av_strcasecmp`, `vcn_av_strncasecmp`,
 *                            `vcn_av_strnstr`, `vcn_av_asprintf`
 *     - 0x0099c8..0x00a040 : `vcn_av_dict_get`, `vcn_av_dict_set`, `vcn_av_dict_set_int`, `vcn_av_dict_free`, `vcn_av_dict_copy`
 *     - 0x00a244..0x00afc0 : `vcn_av_opt_set`, `vcn_av_opt_set_dict`
 *     - 0x00b144..0x00b464 : `vcn_av_gettime`, `vcn_av_gettime_relative`, `vcn_av_usleep`, `vcn_av_strerror`
 *     - 0x00dde4..0x00eaa4 : `vcn_av_log_format_line`, `vcn_av_ll`, `vcn_av_info_set_callback`,
 *                            `vcn_av_log_set_level`, `vcn_av_log_set_callback`
 *     - 0x00eab0..0x00ed64 : `vcn_av_malloc`, `vcn_av_mallocz`, `vcn_av_free`, `vcn_av_freep`,
 *                            `vcn_av_reallocp`, `vcn_av_strdup`, `vcn_av_strndup`
 *     - 0x00f1d0..0x010438 : `vcn_av_url_split`, `vcn_av_url_split_hostname`, `vcn_av_small_strptime`, `vcn_av_timegm`
 */

#ifndef NEXTAI_OPENCUT_VCN_AV_UTILS_H_
#define NEXTAI_OPENCUT_VCN_AV_UTILS_H_

#include "vcn_types.h"

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <ctime>
#include <vector>

extern "C" {

// String manipulation (`0x008fbc..0x009650`)
int   vcn_av_strstart(const char* str, const char* pfx, const char** ptr);
int   vcn_av_stristart(const char* str, const char* pfx, const char** ptr);
char* vcn_av_stristr(const char* haystack, const char* needle);
char* vcn_av_strtok(char* s, const char* delim, char** saveptr);
size_t vcn_av_strlcpy(char* dst, const char* src, size_t size);
size_t vcn_av_strlcatf(char* dst, size_t size, const char* fmt, ...);
int   vcn_av_strcasecmp(const char* a, const char* b);
int   vcn_av_strncasecmp(const char* a, const char* b, size_t n);
char* vcn_av_strnstr(const char* haystack, const char* needle, size_t hay_length);
char* vcn_av_asprintf(const char* fmt, ...);

// Dictionary (`0x0099c8..0x00a040`)
com::ss::mediakit::vcn::AVDictionaryEntry* vcn_av_dict_get(
    const com::ss::mediakit::vcn::AVDictionary* m,
    const char* key,
    const com::ss::mediakit::vcn::AVDictionaryEntry* prev,
    int flags);
int  vcn_av_dict_set(com::ss::mediakit::vcn::AVDictionary** pm,
                     const char* key,
                     const char* value,
                     int flags);
int  vcn_av_dict_set_int(com::ss::mediakit::vcn::AVDictionary** pm,
                         const char* key,
                         int64_t value,
                         int flags);
void vcn_av_dict_free(com::ss::mediakit::vcn::AVDictionary** m);
int  vcn_av_dict_copy(com::ss::mediakit::vcn::AVDictionary** dst,
                      const com::ss::mediakit::vcn::AVDictionary* src,
                      int flags);

// Options (`0x00a244..0x00afc0`)
int vcn_av_opt_set(void* obj, const char* name, const char* val, int search_flags);
int vcn_av_opt_set_dict(void* obj, com::ss::mediakit::vcn::AVDictionary** options);

// Time & Error (`0x00b144..0x00b464`)
int64_t vcn_av_gettime(void);
int64_t vcn_av_gettime_relative(void);
int     vcn_av_usleep(unsigned int usec);
int     vcn_av_strerror(int errnum, char* errbuf, size_t errbuf_size);

// Logging (`0x00dde4..0x00eaa4`)
void vcn_av_log_format_line(void* ptr, int level, const char* fmt, va_list vl,
                            char* line, int line_size, int* print_prefix);
void vcn_av_ll(void* avcl, int level, const char* fmt, ...);
void vcn_av_info_set_callback(void (*callback)(void*, int, int64_t, const char*));
void vcn_av_log_set_level(int level);
void vcn_av_log_set_callback(void (*callback)(void*, int, const char*, va_list));

// Memory (`0x00eab0..0x00ed64`)
void* vcn_av_malloc(size_t size);
void* vcn_av_mallocz(size_t size);
void  vcn_av_free(void* ptr);
void  vcn_av_freep(void* arg);
int   vcn_av_reallocp(void* ptr, size_t size);
char* vcn_av_strdup(const char* s);
char* vcn_av_strndup(const char* s, size_t len);

// URL Split & Date/Time Parsing (`0x00f1d0..0x010438`)
void   vcn_av_url_split(char* proto, int proto_size,
                        char* authorization, int authorization_size,
                        char* hostname, int hostname_size,
                        int* port_ptr,
                        char* path, int path_size,
                        const char* url);
void   vcn_av_url_split_hostname(char* proto, int proto_size,
                                 char* authorization, int authorization_size,
                                 char* hostname, int hostname_size,
                                 int* port_ptr,
                                 char* path, int path_size,
                                 const char* url);
char*  vcn_av_small_strptime(const char* p, const char* fmt, struct tm* dt);
time_t vcn_av_timegm(struct tm* tm);

}  // extern "C"

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

/**
 * @brief Returns the exact 66-entry `error_entries` table at `.data.rel.ro 0x035740..0x035d70`.
 *        Trả về bảng 66 mã lỗi `error_entries` tại `.data.rel.ro 0x035740..0x035d70`.
 */
const std::vector<VcnAvErrorEntry>& GetVcnAvErrorTable66() noexcept;

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com

#endif  // NEXTAI_OPENCUT_VCN_AV_UTILS_H_
