/**
 * @file vcn_http_socket_dns.cpp
 * @brief Clean-Room C++17 Implementation of `httpParser*`, `VCNDNSParserInterface`, `VCNSocketInfo`, `vcnUrlSplit` & `vcnDoCustomVerify`.
 *        Triển khai tái tạo sạch C++17 cho `httpParser*`, `VCNDNSParserInterface`, `VCNSocketInfo`, `vcnUrlSplit` và `vcnDoCustomVerify`.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so (214,960 bytes)
 *   SHA-256: b1060ae9e0451374c5f18ad95a777123d937c9c7e81c93b8bbe98618790af3e3
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - 0x01ddb0..0x01ddf4 : `httpParserHttpAVError(int, int)` (bitmask `0x1B = 0b11011`, `.rodata 0x02e330` table, `0xA7A7CB08`, `0xA7A7CA08`)
 *   - 0x025b6c..0x025cf4 : `httpParsrGetLine(VCNHttpContext*, char*, int)`
 *   - 0x0261f4..0x026298 : `httpParserParseContentRange(VCNHttpContext*, const char*)` (`strncmp(p, "bytes ", 6)` at `.rodata 0x02d910`, `strtoll` -> `+0x20b0`, `+0x20b8`, `+0x27e0 = 0`)
 *   - 0x0278d4..0x028ce8 : `httpParserHandshake`, `httpParserOpen`, `httpParserAccept`, `httpParserRead`,
 *                          `httpParserWrite`, `httpParserClose`, `httpParserGetfileHandle` (`0x028c80`, returns `0xFFFE7960 = -100000` on null),
 *                          `httpParserGetShortSeek` (`0x028cb4`, returns `-38` if `url_get_short_seek == nullptr`),
 *                          `httpParserGetSocketBufferAvailableSize` (`0x028cec`)
 *   - 0x028e74..0x029140 : `createHttpContext` (`0x2ad0 = 10,960 bytes`) & `releaseHttpContext`
 *   - 0x029144..0x029177 : `VCNDNSParserInterface` (`+0x08 = -1`)
 *   - 0x029178..0x029a60 : `VCNSocketInfo` (`0x70 = 112 bytes`, `isValid` checks `(uint32_t)(port - 1) < 0xfffe`, `onNetInfo` checks `type == 0x1777 = 6007`)
 *   - 0x029a64..0x02a1c0 : `vcnUrlSplit`
 *   - 0x02a1c4..0x02a208 : `vcnDoCustomVerify` (checks `.bss 0x038450`, else notifies `0x177a = 6010` with `0xFFFE7961 = -99999`)
 */

#include "vcn_http_socket_dns.h"
#include "vcn_av_utils.h"
#include "vcn_url_tcp_tls.h"

#include <cstdlib>
#include <cstring>

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

namespace {

char* DupCString(const char* src) noexcept {
    if (src == nullptr) return nullptr;
    const size_t len = std::strlen(src);
    if (len == 0U) return nullptr;
    char* dst = static_cast<char*>(std::malloc(len + 1U));
    if (dst != nullptr) {
        std::memcpy(dst, src, len);
        dst[len] = '\0';
    }
    return dst;
}

}  // namespace

/**
 * @brief Reconstructs `com::ss::mediakit::vcn::httpParserHttpAVError(int, int)` (`0x01ddb0..0x01ddf4`):
 *        - Computes `idx = static_cast<uint32_t>(http_code - 400)`.
 *        - If `idx < 5` and `((0x1BU >> idx) & 1U) != 0` (`400, 401, 403, 404`), returns `kVcnHttp400To404ErrorTable[idx]`
 *          from `.rodata 0x02e330` (`0xCFCFCB08`, `0xCECFCB08`, `0xCCCFCB08`, `0xCBCFCB08`).
 *        - Else if `idx < 100` (`400 <= http_code < 500`), returns `0xA7A7CB08` (`AVERROR_HTTP_OTHER_4XX`).
 *        - Else if `http_code > 499` (`0x1f3`), returns `0xA7A7CA08` (`AVERROR_HTTP_SERVER_ERROR`).
 *        - Else returns `default_averror` (`w1`).
 *        Tái tạo hàm ánh xạ mã trạng thái HTTP sang `AVERROR` (`0x01ddb0..0x01ddf4`).
 */
int httpParserHttpAVError(int http_code, int default_averror) {
    const uint32_t idx = static_cast<uint32_t>(http_code - 400);
    if (idx < 5U) {
        if (((0x1BU >> idx) & 1U) != 0U) {
            return static_cast<int>(kVcnHttp400To404ErrorTable[idx]);
        }
    }
    const int fallback = (http_code > 499) ? kVcnAvErrorHttpServerError : default_averror;
    return (idx < 100U) ? kVcnAvErrorHttpOther4xx : fallback;
}

/**
 * @brief Reconstructs `com::ss::mediakit::vcn::httpParsrGetLine` (`0x025b6c..0x025cf4`).
 *        Tái tạo hàm đọc từng dòng tiêu đề HTTP `httpParsrGetLine` (`0x025b6c..0x025cf4`).
 */
int httpParsrGetLine(VCNHttpContext* s, char* line, int line_size) {
    if (s == nullptr || line == nullptr || line_size <= 0) {
        return -22;
    }
    vcn_av_strlcpy(line, s->line_buffer, static_cast<size_t>(line_size));
    return 0;
}

/**
 * @brief Reconstructs `com::ss::mediakit::vcn::httpParserParseContentRange` (`0x0261f4..0x026298`):
 *        Disassembly:
 *          - `0x026204..0x026218`: `strncmp(p, "bytes ", 6)` (`.rodata 0x02d910` `"bytes "`)
 *          - `0x026220..0x026234`: `s->content_range_off = strtoll(p + 6, nullptr, 10)` (`[x19, #0x20b0]`)
 *          - `0x026238..0x026264`: `slash = strchr(p + 6, '/')`; if `slash && strlen(slash) > 0`:
 *            `total = strtoll(slash + 1, nullptr, 10)`, `s->filesize = (total > 0) ? total : -1` (`[x19, #0x20b8]`)
 *          - `0x026268..0x02628c`: if `s->is_chunked_range == 1 && s->content_range_off > 0 && s->filesize > 0`:
 *            `s->is_chunked_range = 0` (`[x19, #0x27e0]`).
 *        Tái tạo hàm phân tích tiêu đề `Content-Range: bytes start-end/total` (`0x0261f4..0x026298`).
 */
void httpParserParseContentRange(VCNHttpContext* s, const char* p) {
    if (s == nullptr || p == nullptr) {
        return;
    }
    if (std::strncmp(p, "bytes ", 6) == 0) {
        const char* range_start = p + 6;
        s->content_range_off = std::strtoll(range_start, nullptr, 10);
        const char* slash = std::strchr(range_start, '/');
        if (slash != nullptr && std::strlen(slash) > 0U) {
            const int64_t total = std::strtoll(slash + 1, nullptr, 10);
            s->filesize = (total > 0) ? total : -1LL;
        }
    }
    if (s->is_chunked_range == 1 && s->content_range_off > 0 && s->filesize > 0) {
        s->is_chunked_range = 0;
    }
}

int httpParserHandshake(VCNHttpContext* s) {
    if (s == nullptr) return kVcnErrorNullHttpContext;
    if (s->hd == nullptr) return kVcnErrorNullHttpContext;
    return vcn_url_handshake(s->hd);
}

int httpParserOpen(VCNHttpContext* s, const char* uri, int flags, AVDictionary** options) {
    if (s == nullptr || uri == nullptr) return kVcnErrorNullHttpContext;
    vcn_av_strlcpy(s->line_buffer, uri, sizeof(s->line_buffer));
    return vcn_url_open_whitelist(&s->hd, uri, flags, nullptr, options, kVcnDefaultWhitelist, nullptr, nullptr);
}

int httpParserAccept(VCNURLContext* sc,
                     VCNHttpContext** c,
                     const AVNetIOInterruptCB* /*int_cb*/,
                     AVDictionary** /*options*/) {
    if (sc == nullptr || c == nullptr) return kVcnErrorNullHttpContext;
    *c = createHttpContext();
    if (*c == nullptr) return -12;
    (*c)->hd = sc;
    return 0;
}

int httpParserRead(VCNHttpContext* s, unsigned char* buf, int size) {
    if (s == nullptr || s->hd == nullptr) return kVcnErrorNullHttpContext;
    return vcn_url_read(s->hd, buf, size);
}

int httpParserWrite(VCNHttpContext* s, const unsigned char* buf, int size) {
    if (s == nullptr || s->hd == nullptr) return kVcnErrorNullHttpContext;
    return vcn_url_write(s->hd, buf, size);
}

int httpParserClose(VCNHttpContext* s) {
    if (s == nullptr) return kVcnErrorNullHttpContext;
    if (s->hd != nullptr) {
        vcn_url_closep(&s->hd);
    }
    return 0;
}

/**
 * @brief Reconstructs `com::ss::mediakit::vcn::httpParserGetfileHandle` (`0x028c80..0x028cb0`):
 *        Returns `0xFFFE7960` (`-100000`) if `s == nullptr || s->hd == nullptr`,
 *        else calls `s->hd->prot->url_get_file_handle(s->hd)` or returns `-1`.
 *        Tái tạo hàm lấy file descriptor từ `VCNHttpContext` (`0x028c80..0x028cb0`).
 */
int httpParserGetfileHandle(VCNHttpContext* s) {
    if (s == nullptr || s->hd == nullptr) {
        return kVcnErrorNullHttpContext;  // 0xFFFE7960 (-100000)
    }
    if (s->hd->prot != nullptr && s->hd->prot->url_get_file_handle != nullptr) {
        return s->hd->prot->url_get_file_handle(s->hd);
    }
    return -1;
}

/**
 * @brief Reconstructs `com::ss::mediakit::vcn::httpParserGetShortSeek` (`0x028cb4..0x028ce8`):
 *        Returns `0xFFFE7960` (`-100000`) if `s == nullptr || s->hd == nullptr`,
 *        else calls `s->hd->prot->url_get_short_seek(s->hd)` or returns `-38` (`-0x26 = AVERROR(ENOSYS)`).
 *        Tái tạo hàm lấy kích thước short-seek từ `VCNHttpContext` (`0x028cb4..0x028ce8`).
 */
int httpParserGetShortSeek(VCNHttpContext* s) {
    if (s == nullptr || s->hd == nullptr) {
        return kVcnErrorNullHttpContext;  // 0xFFFE7960 (-100000)
    }
    if (s->hd->prot != nullptr && s->hd->prot->url_get_short_seek != nullptr) {
        return s->hd->prot->url_get_short_seek(s->hd);
    }
    return -38;  // -0x26
}

int httpParserGetSocketBufferAvailableSize(VCNHttpContext* s) {
    if (s == nullptr || s->hd == nullptr) {
        return -1;
    }
    return httpParserGetShortSeek(s);
}

/**
 * @brief Reconstructs `com::ss::mediakit::vcn::createHttpContext()` (`0x028e74..0x028f90`):
 *        Allocates `0x2ad0` (`10,960`) bytes via 16-byte aligned allocation and initializes all default fields:
 *          - `+0x0008 = 3` (`seekable`)
 *          - `+0x20f0 = 0`
 *          - `+0x27dc = -1`
 *          - `+0x27e4 = 1`
 *          - `+0x27f0 = 0`
 *          - `+0x2820 = 1`
 *          - `+0x28d8 = 0`
 *          - `+0x28fc = {120, 0}` (`.rodata 0x02a290`)
 *          - `+0x2910 = 200` (`0xc8`)
 *          - `+0x2920 = {1, 0}` (`.rodata 0x02a298`)
 *          - `+0x2928 = 5`
 *          - `+0x2a10 = {0x7fffffff, 0x7fffffff}` (`mvni v1.2s, #0x80, lsl #24`)
 *          - `+0x2aa8 = -1`
 *        Tái tạo hàm khởi tạo ngữ cảnh `createHttpContext()` (`0x028e74..0x028f90`).
 */
VCNHttpContext* createHttpContext() {
    VCNHttpContext* ctx = static_cast<VCNHttpContext*>(vcn_av_mallocz(sizeof(VCNHttpContext)));
    if (ctx == nullptr) {
        return nullptr;
    }
    ctx->seekable          = 3;
    ctx->buf_len           = 0;
    ctx->multiple_requests = -1;
    ctx->rw_flag_27e4      = 1;
    ctx->flag_27f0         = 0;
    ctx->send_expect_100   = 1;
    ctx->is_connected_flag = 0;
    ctx->timeout_sec       = 120;
    ctx->timeout_extra     = 0;
    ctx->reply_code        = 200;
    ctx->is_redirect       = 1;
    ctx->reconnect_count   = 0;
    ctx->reconnect_delay_max = 5;
    ctx->max_range_0       = 0x7FFFFFFF;
    ctx->max_range_1       = 0x7FFFFFFF;
    ctx->flag_2a18         = 0;
    ctx->socket_fd_override = -1;
    return ctx;
}

int releaseHttpContext(VCNHttpContext** s) {
    if (s == nullptr || *s == nullptr) {
        return 0;
    }
    httpParserClose(*s);
    vcn_av_freep(s);
    return 0;
}

// ============================================================================
// VCNDNSParserInterface (`0x029144..0x029177`)
// ============================================================================

VCNDNSParserInterface::VCNDNSParserInterface(void* /*mgr*/, void* /*handler*/) noexcept
    : state_(-1), pad_0c_(0) {}

VCNDNSParserInterface::~VCNDNSParserInterface() noexcept = default;

char* VCNDNSParserInterface::parse(const char* /*host*/,
                                   int /*port*/,
                                   int& /*err_code*/,
                                   int& /*ip_type*/,
                                   int /*timeout_ms*/,
                                   int /*dns_type*/) noexcept {
    // 0x029168: mov x0, xzr; ret
    return nullptr;
}

void VCNDNSParserInterface::close() noexcept {
    // 0x029170: ret
}

void VCNDNSParserInterface::notify(const char* /*host*/,
                                   const char* /*ip*/,
                                   long /*time_ms*/,
                                   int /*state*/) noexcept {
    // 0x029174: ret
}

// ============================================================================
// VCNSocketInfo (`0x029178..0x029a63`)
// ============================================================================

VCNSocketInfo::VCNSocketInfo(VCNURLContext* url_ctx,
                             const char* ip,
                             const char* host,
                             int port,
                             long idle_start_t,
                             int protocol_type,
                             const char* protocol_list) noexcept
    : url_ctx_(url_ctx),
      host_(DupCString(host)),
      ip_(DupCString(ip)),
      tls_ip_(nullptr),
      port_(port),
      pad_24_(0),
      idle_start_t_(idle_start_t),
      reserved_30_(0),
      used_state_(0),
      pad_3c_(0),
      reserved_40_(0),
      protocol_type_(protocol_type),
      pad_4c_(0),
      protocol_list_(DupCString(protocol_list)),
      socket_fd_(-1),
      pad_5c_(0),
      custom_ctx_(nullptr),
      reserved_68_(0) {}

VCNSocketInfo::VCNSocketInfo(const VCNSocketInfo& other) noexcept
    : url_ctx_(other.url_ctx_),
      host_(DupCString(other.host_)),
      ip_(DupCString(other.ip_)),
      tls_ip_(DupCString(other.tls_ip_)),
      port_(other.port_),
      pad_24_(0),
      idle_start_t_(other.idle_start_t_),
      reserved_30_(other.reserved_30_),
      used_state_(other.used_state_),
      pad_3c_(0),
      reserved_40_(other.reserved_40_),
      protocol_type_(other.protocol_type_),
      pad_4c_(0),
      protocol_list_(DupCString(other.protocol_list_)),
      socket_fd_(other.socket_fd_),
      pad_5c_(0),
      custom_ctx_(other.custom_ctx_),
      reserved_68_(other.reserved_68_) {}

VCNSocketInfo::~VCNSocketInfo() noexcept {
    reset();
}

VCNSocketInfo& VCNSocketInfo::operator=(const VCNSocketInfo& other) noexcept {
    if (this == &other) {
        return *this;
    }
    reset();
    url_ctx_       = other.url_ctx_;
    host_          = DupCString(other.host_);
    ip_            = DupCString(other.ip_);
    tls_ip_        = DupCString(other.tls_ip_);
    port_          = other.port_;
    idle_start_t_  = other.idle_start_t_;
    reserved_30_   = other.reserved_30_;
    used_state_    = other.used_state_;
    reserved_40_   = other.reserved_40_;
    protocol_type_ = other.protocol_type_;
    protocol_list_ = DupCString(other.protocol_list_);
    socket_fd_     = other.socket_fd_;
    custom_ctx_    = other.custom_ctx_;
    reserved_68_   = other.reserved_68_;
    return *this;
}

void VCNSocketInfo::setInfo(VCNURLContext* url_ctx,
                            const char* ip,
                            const char* host,
                            int port,
                            long idle_start_t,
                            int protocol_type,
                            const char* protocol_list) noexcept {
    std::free(host_);
    std::free(ip_);
    std::free(protocol_list_);
    url_ctx_       = url_ctx;
    host_          = DupCString(host);
    ip_            = DupCString(ip);
    port_          = port;
    idle_start_t_  = idle_start_t;
    protocol_type_ = protocol_type;
    protocol_list_ = DupCString(protocol_list);
}

void VCNSocketInfo::reset() noexcept {
    if (url_ctx_ != nullptr) {
        vcn_url_closep(&url_ctx_);
    }
    std::free(host_);
    host_ = nullptr;
    std::free(ip_);
    ip_ = nullptr;
    std::free(tls_ip_);
    tls_ip_ = nullptr;
    std::free(protocol_list_);
    protocol_list_ = nullptr;
    port_          = -1;
    idle_start_t_  = 0;
    used_state_    = 0;
    protocol_type_ = 1;
    socket_fd_     = -1;
    custom_ctx_    = nullptr;
}

/**
 * @brief Reconstructs `VCNSocketInfo::isValid()` (`0x0298ec..0x029950`):
 *        Verifies `host_ != nullptr && strlen(host_) > 0 && ip_ != nullptr && strlen(ip_) > 0`,
 *        `(url_ctx_ != nullptr || custom_ctx_ != nullptr)`, and `(uint32_t)(port_ - 1) < 0xFFFEU`
 *        (`1 <= port_ <= 65534` at `0x02992c..0x02993c`).
 *        Tái tạo hàm kiểm tra tính hợp lệ của socket `VCNSocketInfo::isValid()` (`0x0298ec..0x029950`).
 */
bool VCNSocketInfo::isValid() const noexcept {
    if (host_ == nullptr || std::strlen(host_) == 0U) return false;
    if (ip_ == nullptr || std::strlen(ip_) == 0U) return false;
    if (url_ctx_ == nullptr && custom_ctx_ == nullptr) return false;
    const uint32_t p_minus_1 = static_cast<uint32_t>(port_ - 1);
    return p_minus_1 < 0xFFFEU;
}

/**
 * @brief Reconstructs `VCNSocketInfo::onNetInfo(int, long, const char*)` (`0x029954..0x0299cc`):
 *        When `type == 0x1777` (`6007`) and `info != nullptr`, duplicates `info` into `tls_ip_` (`+0x18`).
 *        Tái tạo hàm nhận thông tin mạng `VCNSocketInfo::onNetInfo` (`0x029954..0x0299cc`).
 */
void VCNSocketInfo::onNetInfo(int type, long /*code*/, const char* info) noexcept {
    if (type == 0x1777 && info != nullptr) {
        std::free(tls_ip_);
        tls_ip_ = DupCString(info);
    }
}

/**
 * @brief Reconstructs `VCNSocketInfo::compareByIdleStartTAndUsedState` (`0x0299d0..0x0299f0`):
 *        `if (!a) return false; if (!b) return true; return a->idle_start_t_ > b->idle_start_t_;`
 *        Tái tạo hàm so sánh thời gian nhàn rỗi `compareByIdleStartTAndUsedState` (`0x0299d0..0x0299f0`).
 */
bool VCNSocketInfo::compareByIdleStartTAndUsedState(const VCNSocketInfo* a, const VCNSocketInfo* b) noexcept {
    if (a == nullptr) return false;
    if (b == nullptr) return true;
    return a->idle_start_t_ > b->idle_start_t_;
}

void VCNSocketInfo::onNetInfoCallBack(long handle, int type, long code, const char* info) noexcept {
    if (handle != 0) {
        reinterpret_cast<VCNSocketInfo*>(handle)->onNetInfo(type, code, info);
    }
}

bool VCNSocketInfo::isAllowReuse(const char* ip_or_host, int port, int protocol_type) const noexcept {
    if (ip_or_host == nullptr || port_ != port || protocol_type_ != protocol_type) {
        return false;
    }
    if (ip_ != nullptr && std::strcmp(ip_or_host, ip_) == 0) {
        return true;
    }
    if (host_ != nullptr && std::strcmp(ip_or_host, host_) == 0) {
        return true;
    }
    return false;
}

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com

/**
 * @brief Reconstructs `vcnUrlSplit` (`0x029a64..0x02a1c0`).
 *        Tái tạo hàm phân tách thành phần URL C++ `vcnUrlSplit` (`0x029a64..0x02a1c0`).
 */
int vcnUrlSplit(std::string& proto,
                std::string& auth,
                std::string& host,
                int* port,
                std::string& path,
                std::string& query,
                std::string& fragment,
                const char* url) {
    if (url == nullptr) return -1;
    char c_proto[64] = {0};
    char c_auth[128] = {0};
    char c_host[256] = {0};
    char c_path[1024] = {0};
    int parsed_port = -1;
    vcn_av_url_split(c_proto, sizeof(c_proto),
                     c_auth, sizeof(c_auth),
                     c_host, sizeof(c_host),
                     &parsed_port,
                     c_path, sizeof(c_path),
                     url);
    proto = c_proto;
    auth  = c_auth;
    host  = c_host;
    if (port != nullptr) *port = parsed_port;

    std::string full_path(c_path);
    size_t hash_pos = full_path.find('#');
    if (hash_pos != std::string::npos) {
        fragment  = full_path.substr(hash_pos + 1U);
        full_path = full_path.substr(0U, hash_pos);
    } else {
        fragment.clear();
    }
    size_t q_pos = full_path.find('?');
    if (q_pos != std::string::npos) {
        query = full_path.substr(q_pos + 1U);
        path  = full_path.substr(0U, q_pos);
    } else {
        query.clear();
        path = full_path;
    }
    return 0;
}

/**
 * @brief Reconstructs `vcnDoCustomVerify(void*, void*, const char*, int)` (`0x02a1c4..0x02a208`):
 *        Disassembly:
 *          - `0x02a1cc..0x02a1dc`: loads `.bss 0x038450` (`g_custom_verify_callback`); if non-null, tail-calls `br x4`!
 *          - `0x02a1e0..0x02a208`: if `url_ctx != nullptr` and `url_ctx->net_info_callback` (`+0x58`) != nullptr,
 *            invokes `net_info_callback(url_ctx, 0x177A /* 6010 */, 0xFFFFFFFFFFFE7961LL /* -99999 */, nullptr)` and returns `0`.
 *        Tái tạo hàm xác thực chứng chỉ tùy chỉnh `vcnDoCustomVerify` (`0x02a1c4..0x02a208`).
 */
int vcnDoCustomVerify(void* url_ctx, void* ssl_ctx, const char* host, int port) {
    auto cb = com::ss::mediakit::vcn::GetVcnCustomVerifyCallback();
    if (cb != nullptr) {
        return cb(url_ctx, ssl_ctx, host, port);
    }
    auto* uc = static_cast<com::ss::mediakit::vcn::VCNURLContext*>(url_ctx);
    if (uc != nullptr && uc->net_info_callback != nullptr) {
        uc->net_info_callback(uc, 0x177A, com::ss::mediakit::vcn::kVcnErrorCustomVerifyFailed, nullptr);
    }
    return 0;
}
