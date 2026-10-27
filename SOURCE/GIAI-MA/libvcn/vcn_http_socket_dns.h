/**
 * @file vcn_http_socket_dns.h
 * @brief Clean-Room Header for `httpParser*`, `VCNDNSParserInterface`, `VCNSocketInfo`, `vcnUrlSplit` & `vcnDoCustomVerify`.
 *        Header tái tạo sạch bộ phân tích HTTP `httpParser*`, `VCNDNSParserInterface`, `VCNSocketInfo`, `vcnUrlSplit` và `vcnDoCustomVerify`.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so (214,960 bytes)
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x01ddb0..0x01ddf4 : `com::ss::mediakit::vcn::httpParserHttpAVError(int, int)`
 *     - 0x025b6c..0x029143 : `httpParsrGetLine`, `httpParserParseContentRange`, `httpParserHandshake`,
 *                            `httpParserOpen`, `httpParserAccept`, `httpParserRead`, `httpParserWrite`,
 *                            `httpParserClose`, `httpParserGetfileHandle`, `httpParserGetShortSeek`,
 *                            `httpParserGetSocketBufferAvailableSize`, `createHttpContext`, `releaseHttpContext`
 *     - 0x029144..0x029177 : `com::ss::mediakit::vcn::VCNDNSParserInterface` (vtable at `.data.rel.ro 0x037730`)
 *     - 0x029178..0x029a63 : `com::ss::mediakit::vcn::VCNSocketInfo` (`0x70 = 112 bytes`)
 *     - 0x029a64..0x02a1c3 : `vcnUrlSplit`
 *     - 0x02a1c4..0x02a208 : `vcnDoCustomVerify`
 */

#ifndef NEXTAI_OPENCUT_VCN_HTTP_SOCKET_DNS_H_
#define NEXTAI_OPENCUT_VCN_HTTP_SOCKET_DNS_H_

#include "vcn_types.h"

#include <cstdint>
#include <string>

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

int httpParserHttpAVError(int http_code, int default_averror);
int httpParsrGetLine(VCNHttpContext* s, char* line, int line_size);
void httpParserParseContentRange(VCNHttpContext* s, const char* p);
int httpParserHandshake(VCNHttpContext* s);
int httpParserOpen(VCNHttpContext* s, const char* uri, int flags, AVDictionary** options);
int httpParserAccept(VCNURLContext* sc, VCNHttpContext** c, const AVNetIOInterruptCB* int_cb, AVDictionary** options);
int httpParserRead(VCNHttpContext* s, unsigned char* buf, int size);
int httpParserWrite(VCNHttpContext* s, const unsigned char* buf, int size);
int httpParserClose(VCNHttpContext* s);
int httpParserGetfileHandle(VCNHttpContext* s);
int httpParserGetShortSeek(VCNHttpContext* s);
int httpParserGetSocketBufferAvailableSize(VCNHttpContext* s);
VCNHttpContext* createHttpContext();
int releaseHttpContext(VCNHttpContext** s);

/**
 * @brief Reconstructs `com::ss::mediakit::vcn::VCNDNSParserInterface` (`0x029144..0x029177`, vtable `.data.rel.ro 0x037730`).
 *        Tái tạo lớp giao diện phân giải DNS `VCNDNSParserInterface` (`0x029144..0x029177`).
 */
class VCNDNSParserInterface {
public:
    VCNDNSParserInterface(void* mgr, void* handler) noexcept;
    virtual ~VCNDNSParserInterface() noexcept;
    virtual char* parse(const char* host, int port, int& err_code, int& ip_type, int timeout_ms, int dns_type) noexcept;
    virtual void close() noexcept;
    virtual void notify(const char* host, const char* ip, long time_ms, int state) noexcept;

    int32_t state() const noexcept { return state_; }

private:
    int32_t state_;  // +0x08 (`0x02914c: mov w9, #-1; str w9, [x0, #8]`)
    int32_t pad_0c_;
};

/**
 * @brief Reconstructs `com::ss::mediakit::vcn::VCNSocketInfo` (`0x029178..0x029a63`, `112 bytes = 0x70`).
 *        Tái tạo lớp thông tin kết nối socket `VCNSocketInfo` (`0x029178..0x029a63`, `112 bytes`).
 */
class VCNSocketInfo {
public:
    VCNSocketInfo(VCNURLContext* url_ctx,
                  const char* ip,
                  const char* host,
                  int port,
                  long idle_start_t,
                  int protocol_type,
                  const char* protocol_list) noexcept;
    VCNSocketInfo(const VCNSocketInfo& other) noexcept;
    ~VCNSocketInfo() noexcept;
    VCNSocketInfo& operator=(const VCNSocketInfo& other) noexcept;

    void setInfo(VCNURLContext* url_ctx,
                 const char* ip,
                 const char* host,
                 int port,
                 long idle_start_t,
                 int protocol_type,
                 const char* protocol_list) noexcept;
    void reset() noexcept;
    bool isValid() const noexcept;
    void onNetInfo(int type, long code, const char* info) noexcept;
    static bool compareByIdleStartTAndUsedState(const VCNSocketInfo* a, const VCNSocketInfo* b) noexcept;
    static void onNetInfoCallBack(long handle, int type, long code, const char* info) noexcept;
    bool isAllowReuse(const char* ip_or_host, int port, int protocol_type) const noexcept;

    VCNURLContext* url_context() const noexcept { return url_ctx_; }
    const char*    host() const noexcept { return host_; }
    const char*    ip() const noexcept { return ip_; }
    const char*    tls_ip() const noexcept { return tls_ip_; }
    int32_t        port() const noexcept { return port_; }
    int64_t        idle_start_time() const noexcept { return idle_start_t_; }
    int32_t        protocol_type() const noexcept { return protocol_type_; }

private:
    VCNURLContext* url_ctx_;        // +0x00
    char*          host_;           // +0x08
    char*          ip_;             // +0x10
    char*          tls_ip_;         // +0x18 (updated on event 0x1777 = 6007)
    int32_t        port_;           // +0x20 (-1 default)
    int32_t        pad_24_;         // +0x24
    int64_t        idle_start_t_;   // +0x28
    int64_t        reserved_30_;    // +0x30
    int32_t        used_state_;     // +0x38
    int32_t        pad_3c_;         // +0x3c
    int64_t        reserved_40_;    // +0x40
    int32_t        protocol_type_;  // +0x48 (1 default)
    int32_t        pad_4c_;         // +0x4c
    char*          protocol_list_;  // +0x50
    int32_t        socket_fd_;      // +0x58 (-1 default)
    int32_t        pad_5c_;         // +0x5c
    void*          custom_ctx_;     // +0x60
    int64_t        reserved_68_;    // +0x68
};
static_assert(sizeof(VCNSocketInfo) == 0x70, "VCNSocketInfo must be 0x70 (112) bytes on AArch64");

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com

int vcnUrlSplit(std::string& proto,
                std::string& auth,
                std::string& host,
                int* port,
                std::string& path,
                std::string& query,
                std::string& fragment,
                const char* url);

int vcnDoCustomVerify(void* url_ctx, void* ssl_ctx, const char* host, int port);

#endif  // NEXTAI_OPENCUT_VCN_HTTP_SOCKET_DNS_H_
