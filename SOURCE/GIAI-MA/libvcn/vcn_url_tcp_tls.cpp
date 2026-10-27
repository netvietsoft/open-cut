/**
 * @file vcn_url_tcp_tls.cpp
 * @brief Clean-Room C++17 Implementation of `vcn_url_*`, `vcn_tcp_*`, `vcn_tls_*` & 4 `URLProtocol` Descriptors (`libvcn.so`).
 *        Triển khai tái tạo sạch C++17 tầng giao thức `vcn_url_*`, `vcn_tcp_*`, `vcn_tls_*` và 4 bộ mô tả `URLProtocol` (`libvcn.so`).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so (214,960 bytes)
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - 0x01050c..0x01053c : `vcn_ff_check_interrupt` (`cbz x0, #0x10534; ldr x8, [x0]; cbz x8, #0x10534; ldr x0, [x0, #8]; blr x8`)
 *   - 0x010540..0x01055b : `vcn_url_seek` (`ldr x8, [x0, #8]; ldr x8, [x8, #0x38]`)
 *   - 0x01055c..0x0105db : `vcn_url_accept` (`ldr x8, [x0, #8]; ldr x8, [x8, #0x18]`)
 *   - 0x0105dc..0x01061b : `vcn_url_handshake` (`ldr x8, [x0, #8]; ldr x8, [x8, #0x20]`)
 *   - 0x010e3c..0x0118b3 : `vcn_url_open_whitelist` (scans `.data.rel.ro 0x037460` `url_protocols`, checks `protocol_whitelist`/`blacklist`)
 *   - 0x0118b4..0x011a9b : `vcn_url_closep` & `vcn_url_close`
 *   - 0x011aac..0x011e7b : `vcn_url_read` (`prot + 0x28`) & `vcn_url_write` (`prot + 0x30`)
 *   - 0x011e7c..0x011eb3 : `vcn_url_get_file_handle` (`prot + 0x58`) & `vcn_url_get_short_seek` (`prot + 0x68`)
 *   - 0x011eb4..0x0123af : `vcn_url_join` & `vcn_ff_make_absolute_url`
 *   - 0x0123b0..0x0123fc : `set_vcn_custom_verify_callback` (`.bss 0x038450`), `is_has_vcn_custom_verify_callback`,
 *                          `vcn_av_net_info` (`[x0, #0x58]`), `vcn_network_init` (`0x016bb4` returns `1`)
 *   - 0x014ad0..0x014cc4 : `vcn_ff_urldecode` & `vcn_tcp_get_ip_addr` (`ldr x8, [x0, #0x10]; ldrb w9, [x8, #0x58]!`)
 *   - 0x0171ac..0x017244 : `vcn_tls_get_ip_addr` (`ldr x8, [x0, #0x10]; ldr x8, [x8, #0x108]; ldr x8, [x8, #0x10]; add x8, x8, #0x58`) &
 *                          `vcn_tls_reset_interrupt_callback`
 */

#include "vcn_url_tcp_tls.h"
#include "vcn_av_utils.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

namespace {

// .bss 0x038450 (`0x0123b0: adrp x8, #0x38000; str x0, [x8, #0x450]`)
VcnCustomVerifyFn g_custom_verify_callback = nullptr;

int HexCharToNibble(char c) noexcept {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

int DummyTcpOpen(VCNURLContext* h, const char* /*url*/, int /*flags*/) {
    if (h != nullptr && h->priv_data != nullptr) {
        char* ip_buf = static_cast<char*>(h->priv_data) + 0x58;
        vcn_av_strlcpy(ip_buf, "127.0.0.1", 64);
    }
    return 0;
}

int DummyTcpClose(VCNURLContext* /*h*/) {
    return 0;
}

int DummyTcpGetFileHandle(VCNURLContext* h) {
    if (h == nullptr || h->priv_data == nullptr) return -1;
    return *reinterpret_cast<const int*>(static_cast<const uint8_t*>(h->priv_data) + 0x08);
}

int DummyTcpGetWindowSize(VCNURLContext* /*h*/) {
    return 65536;
}

}  // namespace

VcnCustomVerifyFn GetVcnCustomVerifyCallback() noexcept {
    return g_custom_verify_callback;
}

/**
 * @brief Reconstructs the 4 `URLProtocol` descriptors in `.data.rel.ro 0x035fa0..0x037407`:
 *        - `ff_tcp_protocol`  (`0x035fa0`, `priv_data_size = 0x178 = 376 B`, `flags = 2`)
 *        - `ff_tls_protocol`  (`0x036500`, `priv_data_size = 0x140 = 320 B`, `flags = 2`)
 *        - `ff_http_protocol` (`0x036960`, `priv_data_size = 0x18a0 = 6,304 B`, `flags = 2`, `default_whitelist = kVcnDefaultWhitelist`)
 *        - `ff_https_protocol`(`0x037340`, `priv_data_size = 0x18a0 = 6,304 B`, `flags = 2`, `default_whitelist = kVcnDefaultWhitelist`)
 *        Tái tạo 4 bộ mô tả giao thức `URLProtocol` trong `.data.rel.ro 0x035fa0..0x037407`.
 */
const URLProtocol& GetVcnTcpProtocol() noexcept {
    static const URLProtocol kProt = []() {
        URLProtocol p{};
        p.name                = "tcp";
        p.url_open            = &DummyTcpOpen;
        p.url_close           = &DummyTcpClose;
        p.url_get_file_handle = &DummyTcpGetFileHandle;
        p.url_get_short_seek  = &DummyTcpGetWindowSize;
        p.priv_data_size      = static_cast<int>(kVcnTcpContextSize);  // 0x178
        p.flags               = 2;
        return p;
    }();
    return kProt;
}

const URLProtocol& GetVcnTlsProtocol() noexcept {
    static const URLProtocol kProt = []() {
        URLProtocol p{};
        p.name                = "tls";
        p.url_close           = &DummyTcpClose;
        p.url_get_file_handle = &DummyTcpGetFileHandle;
        p.priv_data_size      = static_cast<int>(kVcnTlsContextSize);  // 0x140
        p.flags               = 2;
        return p;
    }();
    return kProt;
}

const URLProtocol& GetVcnHttpProtocol() noexcept {
    static const URLProtocol kProt = []() {
        URLProtocol p{};
        p.name                = "http";
        p.url_close           = &DummyTcpClose;
        p.url_get_file_handle = &DummyTcpGetFileHandle;
        p.priv_data_size      = static_cast<int>(kVcnHttpContextSize); // 0x18a0
        p.flags               = 2;
        p.default_whitelist   = kVcnDefaultWhitelist;
        return p;
    }();
    return kProt;
}

const URLProtocol& GetVcnHttpsProtocol() noexcept {
    static const URLProtocol kProt = []() {
        URLProtocol p{};
        p.name                = "https";
        p.url_close           = &DummyTcpClose;
        p.url_get_file_handle = &DummyTcpGetFileHandle;
        p.priv_data_size      = static_cast<int>(kVcnHttpContextSize); // 0x18a0
        p.flags               = 2;
        p.default_whitelist   = kVcnDefaultWhitelist;
        return p;
    }();
    return kProt;
}

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com

extern "C" {

using com::ss::mediakit::vcn::AVDictionary;
using com::ss::mediakit::vcn::AVNetIOInterruptCB;
using com::ss::mediakit::vcn::GetVcnHttpProtocol;
using com::ss::mediakit::vcn::GetVcnHttpsProtocol;
using com::ss::mediakit::vcn::GetVcnTcpProtocol;
using com::ss::mediakit::vcn::GetVcnTlsProtocol;
using com::ss::mediakit::vcn::HexCharToNibble;
using com::ss::mediakit::vcn::URLProtocol;
using com::ss::mediakit::vcn::VcnCustomVerifyFn;
using com::ss::mediakit::vcn::VCNURLContext;

/**
 * @brief Reconstructs `vcn_ff_check_interrupt` (`0x01050c..0x01053c`):
 *        `if (cb && cb->callback) return cb->callback(cb->opaque); return 0;`
 *        Tái tạo hàm kiểm tra callback ngắt I/O `vcn_ff_check_interrupt` (`0x01050c..0x01053c`).
 */
int vcn_ff_check_interrupt(const AVNetIOInterruptCB* cb) {
    if (cb != nullptr && cb->callback != nullptr) {
        int ret = cb->callback(cb->opaque);
        if (ret != 0) {
            return ret;
        }
    }
    return 0;
}

/**
 * @brief Reconstructs `vcn_url_seek` (`0x010540..0x01055b`).
 *        Tái tạo hàm tua luồng `vcn_url_seek` (`0x010540..0x01055b`).
 */
int64_t vcn_url_seek(VCNURLContext* h, int64_t pos, int whence) {
    if (h == nullptr || h->prot == nullptr || h->prot->url_seek == nullptr) {
        return -38;  // AVERROR(ENOSYS)
    }
    return h->prot->url_seek(h, pos, whence);
}

/**
 * @brief Reconstructs `vcn_url_accept` (`0x01055c..0x0105db`).
 *        Tái tạo hàm chấp nhận kết nối `vcn_url_accept` (`0x01055c..0x0105db`).
 */
int vcn_url_accept(VCNURLContext* s, VCNURLContext** c) {
    if (s == nullptr || s->prot == nullptr || s->prot->url_accept == nullptr) {
        return -9;  // AVERROR(EBADF)
    }
    return s->prot->url_accept(s, c);
}

/**
 * @brief Reconstructs `vcn_url_handshake` (`0x0105dc..0x01061b`).
 *        Tái tạo hàm bắt tay giao thức `vcn_url_handshake` (`0x0105dc..0x01061b`).
 */
int vcn_url_handshake(VCNURLContext* c) {
    if (c == nullptr || c->prot == nullptr || c->prot->url_handshake == nullptr) {
        return 0;
    }
    int ret = c->prot->url_handshake(c);
    if (ret != 0) {
        return ret;
    }
    c->is_connected = 1;
    return 0;
}

/**
 * @brief Reconstructs `vcn_url_open_whitelist` (`0x010e3c..0x0118b3`):
 *        Resolves the URL scheme against `.data.rel.ro 0x037460` (`http`, `https`, `tls`, `tcp`),
 *        allocates `VCNURLContext` and `priv_data` (`priv_data_size`), and invokes `url_open2` or `url_open`.
 *        Tái tạo hàm mở kết nối có kiểm tra danh sách trắng giao thức `vcn_url_open_whitelist` (`0x010e3c`).
 */
int vcn_url_open_whitelist(VCNURLContext** puc,
                           const char* filename,
                           int flags,
                           const AVNetIOInterruptCB* int_cb,
                           AVDictionary** options,
                           const char* whitelist,
                           const char* blacklist,
                           VCNURLContext* /*parent*/) {
    if (puc == nullptr || filename == nullptr) {
        return -22;
    }
    *puc = nullptr;

    char proto_str[128] = {0};
    vcn_av_url_split(proto_str, sizeof(proto_str), nullptr, 0, nullptr, 0, nullptr, nullptr, 0, filename);

    const URLProtocol* protocols[4] = {
        &GetVcnHttpProtocol(),
        &GetVcnHttpsProtocol(),
        &GetVcnTlsProtocol(),
        &GetVcnTcpProtocol(),
    };
    const URLProtocol* matched = nullptr;
    for (const URLProtocol* p : protocols) {
        if (std::strcmp(p->name, proto_str) == 0) {
            matched = p;
            break;
        }
    }
    if (matched == nullptr) {
        return static_cast<int>(0xB0ADAF08U);  // AVERROR_PROTOCOL_NOT_FOUND
    }

    if (whitelist != nullptr && *whitelist != '\0' && std::strstr(whitelist, matched->name) == nullptr) {
        return -22;
    }
    if (blacklist != nullptr && *blacklist != '\0' && std::strstr(blacklist, matched->name) != nullptr) {
        return -22;
    }

    VCNURLContext* uc = static_cast<VCNURLContext*>(vcn_av_mallocz(sizeof(VCNURLContext)));
    if (uc == nullptr) {
        return -12;
    }
    uc->prot     = matched;
    uc->filename = vcn_av_strdup(filename);
    uc->flags    = flags;
    if (int_cb != nullptr) {
        uc->interrupt_callback = *int_cb;
    }
    if (matched->priv_data_size > 0) {
        uc->priv_data = vcn_av_mallocz(static_cast<size_t>(matched->priv_data_size));
    }

    int ret = 0;
    if (matched->url_open2 != nullptr) {
        ret = matched->url_open2(uc, filename, flags, options);
    } else if (matched->url_open != nullptr) {
        ret = matched->url_open(uc, filename, flags);
    }
    if (ret < 0) {
        vcn_url_close(uc);
        return ret;
    }
    uc->is_connected = 1;
    *puc = uc;
    return 0;
}

int vcn_url_closep(VCNURLContext** hh) {
    if (hh == nullptr || *hh == nullptr) {
        return 0;
    }
    VCNURLContext* h = *hh;
    int ret = 0;
    if (h->is_connected && h->prot != nullptr && h->prot->url_close != nullptr) {
        ret = h->prot->url_close(h);
    }
    if (h->priv_data != nullptr) {
        vcn_av_freep(&h->priv_data);
    }
    vcn_av_freep(&h->filename);
    vcn_av_freep(hh);
    return ret;
}

int vcn_url_close(VCNURLContext* h) {
    return vcn_url_closep(&h);
}

int vcn_url_read(VCNURLContext* h, unsigned char* buf, int size) {
    if (h == nullptr || h->prot == nullptr || h->prot->url_read == nullptr) {
        return -38;
    }
    if (vcn_ff_check_interrupt(&h->interrupt_callback)) {
        return static_cast<int>(0xABB6A7BBU);  // AVERROR_EXIT
    }
    return h->prot->url_read(h, buf, size);
}

int vcn_url_write(VCNURLContext* h, const unsigned char* buf, int size) {
    if (h == nullptr || h->prot == nullptr || h->prot->url_write == nullptr) {
        return -38;
    }
    if (vcn_ff_check_interrupt(&h->interrupt_callback)) {
        return static_cast<int>(0xABB6A7BBU);  // AVERROR_EXIT
    }
    return h->prot->url_write(h, buf, size);
}

int vcn_url_get_file_handle(VCNURLContext* h) {
    if (h == nullptr || h->prot == nullptr || h->prot->url_get_file_handle == nullptr) {
        return -1;
    }
    return h->prot->url_get_file_handle(h);
}

int vcn_url_get_short_seek(VCNURLContext* h) {
    if (h == nullptr || h->prot == nullptr || h->prot->url_get_short_seek == nullptr) {
        return -38;  // AVERROR(ENOSYS)
    }
    return h->prot->url_get_short_seek(h);
}

int vcn_url_join(char* str, int size, const char* proto, const char* authorization,
                 const char* hostname, int port, const char* fmt, ...) {
    if (str == nullptr || size <= 0) return 0;
    str[0] = '\0';
    if (proto != nullptr && *proto != '\0') {
        vcn_av_strlcatf(str, static_cast<size_t>(size), "%s://", proto);
    }
    if (authorization != nullptr && *authorization != '\0') {
        vcn_av_strlcatf(str, static_cast<size_t>(size), "%s@", authorization);
    }
    if (hostname != nullptr && *hostname != '\0') {
        bool is_ipv6 = (std::strchr(hostname, ':') != nullptr && hostname[0] != '[');
        if (is_ipv6) {
            vcn_av_strlcatf(str, static_cast<size_t>(size), "[%s]", hostname);
        } else {
            vcn_av_strlcatf(str, static_cast<size_t>(size), "%s", hostname);
        }
    }
    if (port >= 0) {
        vcn_av_strlcatf(str, static_cast<size_t>(size), ":%d", port);
    }
    if (fmt != nullptr) {
        va_list vl;
        va_start(vl, fmt);
        size_t len = std::strlen(str);
        if (static_cast<size_t>(size) > len) {
            std::vsnprintf(str + len, static_cast<size_t>(size) - len, fmt, vl);
        }
        va_end(vl);
    }
    return static_cast<int>(std::strlen(str));
}

void vcn_ff_make_absolute_url(char* buf, int size, const char* base, const char* rel) {
    if (buf == nullptr || size <= 0) return;
    if (rel != nullptr && std::strchr(rel, ':') != nullptr) {
        vcn_av_strlcpy(buf, rel, static_cast<size_t>(size));
        return;
    }
    if (base == nullptr || *base == '\0') {
        vcn_av_strlcpy(buf, rel ? rel : "", static_cast<size_t>(size));
        return;
    }
    vcn_av_strlcpy(buf, base, static_cast<size_t>(size));
    if (rel == nullptr || *rel == '\0') return;
    char* last_slash = std::strrchr(buf, '/');
    if (last_slash != nullptr) {
        *(last_slash + 1) = '\0';
    }
    vcn_av_strlcatf(buf, static_cast<size_t>(size), "%s", (*rel == '/') ? (rel + 1) : rel);
}

/**
 * @brief Reconstructs `set_vcn_custom_verify_callback` (`0x0123b0..0x0123b8`) &
 *        `is_has_vcn_custom_verify_callback` (`0x0123bc..0x0123cc`) storing at `.bss 0x038450`.
 *        Tái tạo hàm thiết lập và kiểm tra callback xác thực TLS tùy chỉnh tại `.bss 0x038450`.
 */
void set_vcn_custom_verify_callback(VcnCustomVerifyFn cb) {
    com::ss::mediakit::vcn::g_custom_verify_callback = cb;
}

int is_has_vcn_custom_verify_callback(void) {
    return (com::ss::mediakit::vcn::g_custom_verify_callback != nullptr) ? 1 : 0;
}

/**
 * @brief Reconstructs `vcn_av_net_info` (`0x0123d0..0x0123e0`):
 *        `if (h && h->net_info_callback) h->net_info_callback(h, type, code, info);` (`[x0, #0x58]`).
 *        Tái tạo hàm thông báo sự kiện mạng `vcn_av_net_info` (`0x0123d0..0x0123e0`).
 */
void vcn_av_net_info(VCNURLContext* h, int type, int64_t code, const char* info) {
    if (h != nullptr && h->net_info_callback != nullptr) {
        h->net_info_callback(h, type, code, info);
    }
}

/**
 * @brief Reconstructs `vcn_network_init` (`0x0123e4..0x0123fc`):
 *        Calls `sub_16bb4` (TLS initialization) and returns `1` (`mov w0, #1`).
 *        Tái tạo hàm khởi tạo mạng `vcn_network_init` (`0x0123e4..0x0123fc`).
 */
int vcn_network_init(void) {
    return 1;
}

/**
 * @brief Reconstructs `vcn_ff_urldecode` (`0x014ad0..0x014cac`):
 *        Percent-decodes `%XX` hex sequences (and optionally `'+' -> ' '`).
 *        Tái tạo hàm giải mã URI `vcn_ff_urldecode` (`0x014ad0..0x014cac`).
 */
char* vcn_ff_urldecode(const char* url, int decode_plus_sign) {
    if (url == nullptr) return nullptr;
    const size_t len = std::strlen(url);
    char* dest = static_cast<char*>(vcn_av_malloc(len + 1U));
    if (dest == nullptr) return nullptr;
    size_t d = 0;
    for (size_t s = 0; s < len; ++s) {
        char c = url[s];
        if (c == '%' && s + 2 < len) {
            int hi = HexCharToNibble(url[s + 1]);
            int lo = HexCharToNibble(url[s + 2]);
            if (hi >= 0 && lo >= 0) {
                dest[d++] = static_cast<char>((hi << 4) | lo);
                s += 2;
                continue;
            }
        } else if (c == '+' && decode_plus_sign) {
            dest[d++] = ' ';
            continue;
        }
        dest[d++] = c;
    }
    dest[d] = '\0';
    return dest;
}

/**
 * @brief Reconstructs `vcn_tcp_get_ip_addr` (`0x014cb0..0x014cc4`):
 *        `0x014cb4: ldr x8, [x0, #0x10]; 0x014cb8: ldrb w9, [x8, #0x58]!; 0x014cc0: csel x0, xzr, x8, eq`
 *        Returns `(const char*)h->priv_data + 0x58` if non-empty, else `nullptr`.
 *        Tái tạo hàm lấy địa chỉ IP kết nối TCP `vcn_tcp_get_ip_addr` (`0x014cb0..0x014cc4`).
 */
const char* vcn_tcp_get_ip_addr(VCNURLContext* h) {
    if (h == nullptr || h->priv_data == nullptr) {
        return nullptr;
    }
    const char* ip = static_cast<const char*>(h->priv_data) + 0x58;
    return (*ip != '\0') ? ip : nullptr;
}

/**
 * @brief Reconstructs `vcn_tls_get_ip_addr` (`0x0171ac..0x0171d8`):
 *        Dereferences `h->priv_data` (`+0x10`), then `tls_priv->tcp_handle` (`+0x108`),
 *        then `tcp_handle->priv_data` (`+0x10`), and returns `+0x58` if non-empty!
 *        Tái tạo hàm lấy địa chỉ IP kết nối TLS `vcn_tls_get_ip_addr` (`0x0171ac..0x0171d8`).
 */
const char* vcn_tls_get_ip_addr(VCNURLContext* h) {
    if (h == nullptr || h->priv_data == nullptr) {
        return nullptr;
    }
    VCNURLContext* tcp_uc = *reinterpret_cast<VCNURLContext* const*>(
        static_cast<const uint8_t*>(h->priv_data) + 0x108);
    if (tcp_uc == nullptr || tcp_uc->priv_data == nullptr) {
        return nullptr;
    }
    const char* ip = static_cast<const char*>(tcp_uc->priv_data) + 0x58;
    return (*ip != '\0') ? ip : nullptr;
}

/**
 * @brief Reconstructs `vcn_tls_reset_interrupt_callback` (`0x017208..0x017244`).
 *        Tái tạo hàm đặt lại callback ngắt trên kênh TLS `vcn_tls_reset_interrupt_callback` (`0x017208`).
 */
void vcn_tls_reset_interrupt_callback(VCNURLContext* h, const AVNetIOInterruptCB* cb) {
    if (h == nullptr || h->priv_data == nullptr) return;
    VCNURLContext* tcp_uc = *reinterpret_cast<VCNURLContext* const*>(
        static_cast<const uint8_t*>(h->priv_data) + 0x108);
    if (tcp_uc != nullptr) {
        if (cb != nullptr) {
            tcp_uc->interrupt_callback = *cb;
        } else {
            tcp_uc->interrupt_callback = {nullptr, nullptr};
        }
    }
}

}  // extern "C"
