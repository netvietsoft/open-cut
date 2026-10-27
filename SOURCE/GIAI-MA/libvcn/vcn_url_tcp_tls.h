/**
 * @file vcn_url_tcp_tls.h
 * @brief Clean-Room Header for `vcn_url_*`, `vcn_tcp_*`, `vcn_tls_*` & 4 `URLProtocol` Descriptors (`libvcn.so`).
 *        Header tái tạo sạch tầng giao thức `vcn_url_*`, `vcn_tcp_*`, `vcn_tls_*` và 4 bộ mô tả `URLProtocol` (`libvcn.so`).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so (214,960 bytes)
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x01050c..0x01053c : `vcn_ff_check_interrupt`
 *     - 0x010540..0x012094 : `vcn_url_seek`, `vcn_url_accept`, `vcn_url_handshake`, `vcn_url_open_whitelist`,
 *                            `vcn_url_closep`, `vcn_url_close`, `vcn_url_read`, `vcn_url_write`,
 *                            `vcn_url_get_file_handle`, `vcn_url_get_short_seek`, `vcn_url_join`
 *     - 0x012098..0x012400 : `vcn_ff_make_absolute_url`, `set_vcn_custom_verify_callback` (`.bss 0x038450`),
 *                            `is_has_vcn_custom_verify_callback`, `vcn_av_net_info`, `vcn_network_init`
 *     - 0x014ad0..0x017f50 : `vcn_ff_urldecode`, `vcn_tcp_get_ip_addr`, `vcn_tls_get_ip_addr`,
 *                            `vcn_tls_reset_interrupt_callback`
 *     - .data.rel.ro 0x035fa0..0x037480 : `ff_tcp_protocol`, `ff_tls_protocol`, `ff_http_protocol`, `ff_https_protocol`
 */

#ifndef NEXTAI_OPENCUT_VCN_URL_TCP_TLS_H_
#define NEXTAI_OPENCUT_VCN_URL_TCP_TLS_H_

#include "vcn_types.h"

#include <cstddef>
#include <cstdint>

extern "C" {

int     vcn_ff_check_interrupt(const com::ss::mediakit::vcn::AVNetIOInterruptCB* cb);
int64_t vcn_url_seek(com::ss::mediakit::vcn::VCNURLContext* h, int64_t pos, int whence);
int     vcn_url_accept(com::ss::mediakit::vcn::VCNURLContext* s, com::ss::mediakit::vcn::VCNURLContext** c);
int     vcn_url_handshake(com::ss::mediakit::vcn::VCNURLContext* c);
int     vcn_url_open_whitelist(com::ss::mediakit::vcn::VCNURLContext** puc,
                               const char* filename,
                               int flags,
                               const com::ss::mediakit::vcn::AVNetIOInterruptCB* int_cb,
                               com::ss::mediakit::vcn::AVDictionary** options,
                               const char* whitelist,
                               const char* blacklist,
                               com::ss::mediakit::vcn::VCNURLContext* parent);
int     vcn_url_closep(com::ss::mediakit::vcn::VCNURLContext** hh);
int     vcn_url_close(com::ss::mediakit::vcn::VCNURLContext* h);
int     vcn_url_read(com::ss::mediakit::vcn::VCNURLContext* h, unsigned char* buf, int size);
int     vcn_url_write(com::ss::mediakit::vcn::VCNURLContext* h, const unsigned char* buf, int size);
int     vcn_url_get_file_handle(com::ss::mediakit::vcn::VCNURLContext* h);
int     vcn_url_get_short_seek(com::ss::mediakit::vcn::VCNURLContext* h);
int     vcn_url_join(char* str, int size, const char* proto, const char* authorization,
                     const char* hostname, int port, const char* fmt, ...);
void    vcn_ff_make_absolute_url(char* buf, int size, const char* base, const char* rel);
void    set_vcn_custom_verify_callback(com::ss::mediakit::vcn::VcnCustomVerifyFn cb);
int     is_has_vcn_custom_verify_callback(void);
void    vcn_av_net_info(com::ss::mediakit::vcn::VCNURLContext* h, int type, int64_t code, const char* info);
int     vcn_network_init(void);
char*   vcn_ff_urldecode(const char* url, int decode_plus_sign);
const char* vcn_tcp_get_ip_addr(com::ss::mediakit::vcn::VCNURLContext* h);
const char* vcn_tls_get_ip_addr(com::ss::mediakit::vcn::VCNURLContext* h);
void    vcn_tls_reset_interrupt_callback(com::ss::mediakit::vcn::VCNURLContext* h,
                                         const com::ss::mediakit::vcn::AVNetIOInterruptCB* cb);

}  // extern "C"

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

const URLProtocol& GetVcnTcpProtocol() noexcept;
const URLProtocol& GetVcnTlsProtocol() noexcept;
const URLProtocol& GetVcnHttpProtocol() noexcept;
const URLProtocol& GetVcnHttpsProtocol() noexcept;
VcnCustomVerifyFn  GetVcnCustomVerifyCallback() noexcept;

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com

#endif  // NEXTAI_OPENCUT_VCN_URL_TCP_TLS_H_
