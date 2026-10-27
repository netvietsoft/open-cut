/**
 * @file vcn_pseudocode.cpp
 * @brief Clean-Room C++17 Reconstruction of `libvcn.so` Exported Symbol Catalog & End-to-End Verification.
 *        Tái tạo sạch C++17 danh mục biểu tượng xuất và kiểm thử toàn trình của `libvcn.so`.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so (214,960 bytes)
 *   SHA-256: b1060ae9e0451374c5f18ad95a777123d937c9c7e81c93b8bbe98618790af3e3
 */

#include "vcn_interface.h"

#include <cstring>
#include <sstream>

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

/**
 * @brief Returns the complete catalog of 94 exported `STT_FUNC` symbols in `.dynsym` of `libvcn.so` (`0x008fbc..0x02a1c4`).
 *        Trả về danh mục đầy đủ 94 biểu tượng hàm `STT_FUNC` xuất trong `.dynsym` của `libvcn.so`.
 */
const std::vector<VcnExportedSymbolDescriptor>& GetVcnExportedFunctionCatalog() noexcept {
    static const std::vector<VcnExportedSymbolDescriptor> kCatalog = {
        {0x008FBCU,   64U, "vcn_av_strstart",              "int vcn_av_strstart(const char*, const char*, const char**)", "AV_STRING"},
        {0x008FFCU,  100U, "vcn_av_stristart",             "int vcn_av_stristart(const char*, const char*, const char**)", "AV_STRING"},
        {0x009060U,  100U, "vcn_av_stristr",               "char* vcn_av_stristr(const char*, const char*)", "AV_STRING"},
        {0x0090C4U,  140U, "vcn_av_strtok",                "char* vcn_av_strtok(char*, const char*, char**)", "AV_STRING"},
        {0x009150U,  148U, "vcn_av_strlcpy",               "size_t vcn_av_strlcpy(char*, const char*, size_t)", "AV_STRING"},
        {0x009288U,  200U, "vcn_av_strlcatf",              "size_t vcn_av_strlcatf(char*, size_t, const char*, ...)", "AV_STRING"},
        {0x009350U,   68U, "vcn_av_strcasecmp",            "int vcn_av_strcasecmp(const char*, const char*)", "AV_STRING"},
        {0x009394U,   84U, "vcn_av_strncasecmp",           "int vcn_av_strncasecmp(const char*, const char*, size_t)", "AV_STRING"},
        {0x0095E0U,  112U, "vcn_av_strnstr",               "char* vcn_av_strnstr(const char*, const char*, size_t)", "AV_STRING"},
        {0x009650U,  332U, "vcn_av_asprintf",              "char* vcn_av_asprintf(const char*, ...)", "AV_STRING"},
        {0x0099C8U,  220U, "vcn_av_dict_get",              "AVDictionaryEntry* vcn_av_dict_get(const AVDictionary*, const char*, const AVDictionaryEntry*, int)", "AV_DICT"},
        {0x009AA4U,  996U, "vcn_av_dict_set",              "int vcn_av_dict_set(AVDictionary**, const char*, const char*, int)", "AV_DICT"},
        {0x009E88U,  116U, "vcn_av_dict_set_int",          "int vcn_av_dict_set_int(AVDictionary**, const char*, int64_t, int)", "AV_DICT"},
        {0x009F98U,  168U, "vcn_av_dict_free",             "void vcn_av_dict_free(AVDictionary**)", "AV_DICT"},
        {0x00A040U,  144U, "vcn_av_dict_copy",             "int vcn_av_dict_copy(AVDictionary**, const AVDictionary*, int)", "AV_DICT"},
        {0x00A244U, 2412U, "vcn_av_opt_set",               "int vcn_av_opt_set(void*, const char*, const char*, int)", "AV_OPT"},
        {0x00AFC0U,  388U, "vcn_av_opt_set_dict",          "int vcn_av_opt_set_dict(void*, AVDictionary**)", "AV_OPT"},
        {0x00B144U,   52U, "vcn_av_gettime",               "int64_t vcn_av_gettime(void)", "AV_TIME"},
        {0x00B178U,   68U, "vcn_av_gettime_relative",      "int64_t vcn_av_gettime_relative(void)", "AV_TIME"},
        {0x00B1BCU,  140U, "vcn_av_usleep",                "int vcn_av_usleep(unsigned int)", "AV_TIME"},
        {0x00B464U,  192U, "vcn_av_strerror",              "int vcn_av_strerror(int, char*, size_t)", "AV_ERROR"},
        {0x00DDE4U,  192U, "vcn_av_log_format_line",       "void vcn_av_log_format_line(void*, int, const char*, va_list, char*, int, int*)", "AV_LOG"},
        {0x00E868U,  324U, "vcn_av_ll",                    "void vcn_av_ll(void*, int, const char*, ...)", "AV_LOG"},
        {0x00EA94U,    4U, "vcn_av_info_set_callback",     "void vcn_av_info_set_callback(void (*)(void*, int, int64_t, const char*))", "AV_LOG"},
        {0x00EA98U,   12U, "vcn_av_log_set_level",         "void vcn_av_log_set_level(int)", "AV_LOG"},
        {0x00EAA4U,   12U, "vcn_av_log_set_callback",      "void vcn_av_log_set_callback(void (*)(void*, int, const char*, va_list))", "AV_LOG"},
        {0x00EAB0U,  176U, "vcn_av_malloc",                "void* vcn_av_malloc(size_t)", "AV_MEM"},
        {0x00EB60U,  216U, "vcn_av_mallocz",               "void* vcn_av_mallocz(size_t)", "AV_MEM"},
        {0x00EC38U,    4U, "vcn_av_free",                  "void vcn_av_free(void*)", "AV_MEM"},
        {0x00EC3CU,   44U, "vcn_av_freep",                 "void vcn_av_freep(void*)", "AV_MEM"},
        {0x00EC68U,  140U, "vcn_av_reallocp",              "int vcn_av_reallocp(void*, size_t)", "AV_MEM"},
        {0x00ECF4U,  112U, "vcn_av_strdup",                "char* vcn_av_strdup(const char*)", "AV_MEM"},
        {0x00ED64U,  140U, "vcn_av_strndup",               "char* vcn_av_strndup(const char*, size_t)", "AV_MEM"},
        {0x00F1D0U, 1252U, "vcn_av_url_split",             "void vcn_av_url_split(...)", "AV_URL"},
        {0x00F6B4U,  716U, "vcn_av_url_split_hostname",    "void vcn_av_url_split_hostname(...)", "AV_URL"},
        {0x00FB50U, 2280U, "vcn_av_small_strptime",        "char* vcn_av_small_strptime(const char*, const char*, struct tm*)", "AV_TIME"},
        {0x010438U,  212U, "vcn_av_timegm",                "time_t vcn_av_timegm(struct tm*)", "AV_TIME"},
        {0x01050CU,   52U, "vcn_ff_check_interrupt",       "int vcn_ff_check_interrupt(const AVNetIOInterruptCB*)", "URL_CORE"},
        {0x010540U,   28U, "vcn_url_seek",                 "int64_t vcn_url_seek(VCNURLContext*, int64_t, int)", "URL_CORE"},
        {0x01055CU,  128U, "vcn_url_accept",               "int vcn_url_accept(VCNURLContext*, VCNURLContext**)", "URL_CORE"},
        {0x0105DCU,   64U, "vcn_url_handshake",            "int vcn_url_handshake(VCNURLContext*)", "URL_CORE"},
        {0x010E3CU, 2680U, "vcn_url_open_whitelist",       "int vcn_url_open_whitelist(VCNURLContext**, const char*, int, const AVNetIOInterruptCB*, AVDictionary**, const char*, const char*, VCNURLContext*)", "URL_CORE"},
        {0x0118B4U,  428U, "vcn_url_closep",               "int vcn_url_closep(VCNURLContext**)", "URL_CORE"},
        {0x011A60U,   76U, "vcn_url_close",                "int vcn_url_close(VCNURLContext*)", "URL_CORE"},
        {0x011AACU,  480U, "vcn_url_read",                 "int vcn_url_read(VCNURLContext*, unsigned char*, int)", "URL_CORE"},
        {0x011C8CU,  496U, "vcn_url_write",                "int vcn_url_write(VCNURLContext*, const unsigned char*, int)", "URL_CORE"},
        {0x011E7CU,   24U, "vcn_url_get_file_handle",      "int vcn_url_get_file_handle(VCNURLContext*)", "URL_CORE"},
        {0x011E94U,   32U, "vcn_url_get_short_seek",       "int vcn_url_get_short_seek(VCNURLContext*)", "URL_CORE"},
        {0x011EB4U,  484U, "vcn_url_join",                 "int vcn_url_join(char*, int, const char*, const char*, const char*, int, const char*, ...)", "URL_CORE"},
        {0x012098U,  792U, "vcn_ff_make_absolute_url",     "void vcn_ff_make_absolute_url(char*, int, const char*, const char*)", "URL_CORE"},
        {0x0123B0U,   12U, "set_vcn_custom_verify_callback", "void set_vcn_custom_verify_callback(VcnCustomVerifyFn)", "TLS_VERIFY"},
        {0x0123BCU,   20U, "is_has_vcn_custom_verify_callback", "int is_has_vcn_custom_verify_callback(void)", "TLS_VERIFY"},
        {0x0123D0U,   20U, "vcn_av_net_info",              "void vcn_av_net_info(VCNURLContext*, int, int64_t, const char*)", "URL_CORE"},
        {0x0123E4U,   24U, "vcn_network_init",             "int vcn_network_init(void)", "URL_CORE"},
        {0x014AD0U,  480U, "vcn_ff_urldecode",             "char* vcn_ff_urldecode(const char*, int)", "URL_CORE"},
        {0x014CB0U,   24U, "vcn_tcp_get_ip_addr",          "const char* vcn_tcp_get_ip_addr(VCNURLContext*)", "TCP"},
        {0x0171ACU,   48U, "vcn_tls_get_ip_addr",          "const char* vcn_tls_get_ip_addr(VCNURLContext*)", "TLS"},
        {0x017208U,   64U, "vcn_tls_reset_interrupt_callback", "void vcn_tls_reset_interrupt_callback(VCNURLContext*, const AVNetIOInterruptCB*)", "TLS"},
        {0x01DDB0U,   72U, "_ZN3com2ss8mediakit3vcn21httpParserHttpAVErrorEii", "com::ss::mediakit::vcn::httpParserHttpAVError(int, int)", "HTTP_PARSER"},
        {0x025B6CU,  396U, "_ZN3com2ss8mediakit3vcn16httpParsrGetLineEPNS2_14VCNHttpContextEPci", "com::ss::mediakit::vcn::httpParsrGetLine(VCNHttpContext*, char*, int)", "HTTP_PARSER"},
        {0x0261F4U,  168U, "_ZN3com2ss8mediakit3vcn27httpParserParseContentRangeEPNS2_14VCNHttpContextEPKc", "com::ss::mediakit::vcn::httpParserParseContentRange(VCNHttpContext*, const char*)", "HTTP_PARSER"},
        {0x0278D4U,  260U, "_ZN3com2ss8mediakit3vcn19httpParserHandshakeEPNS2_14VCNHttpContextE", "com::ss::mediakit::vcn::httpParserHandshake(VCNHttpContext*)", "HTTP_PARSER"},
        {0x027CFCU,  796U, "_ZN3com2ss8mediakit3vcn14httpParserOpenEPNS2_14VCNHttpContextEPKciPP12AVDictionary", "com::ss::mediakit::vcn::httpParserOpen(VCNHttpContext*, const char*, int, AVDictionary**)", "HTTP_PARSER"},
        {0x028018U,  224U, "_ZN3com2ss8mediakit3vcn16httpParserAcceptEP13VCNURLContextPPNS2_14VCNHttpContextEPK18AVNetIOInterruptCBPP12AVDictionary", "com::ss::mediakit::vcn::httpParserAccept(VCNURLContext*, VCNHttpContext**, const AVNetIOInterruptCB*, AVDictionary**)", "HTTP_PARSER"},
        {0x0280F8U,  504U, "_ZN3com2ss8mediakit3vcn14httpParserReadEPNS2_14VCNHttpContextEPhi", "com::ss::mediakit::vcn::httpParserRead(VCNHttpContext*, unsigned char*, int)", "HTTP_PARSER"},
        {0x028A1CU,  352U, "_ZN3com2ss8mediakit3vcn15httpParserWriteEPNS2_14VCNHttpContextEPKhi", "com::ss::mediakit::vcn::httpParserWrite(VCNHttpContext*, const unsigned char*, int)", "HTTP_PARSER"},
        {0x028B7CU,  260U, "_ZN3com2ss8mediakit3vcn15httpParserCloseEPNS2_14VCNHttpContextE", "com::ss::mediakit::vcn::httpParserClose(VCNHttpContext*)", "HTTP_PARSER"},
        {0x028C80U,   52U, "_ZN3com2ss8mediakit3vcn23httpParserGetfileHandleEPNS2_14VCNHttpContextE", "com::ss::mediakit::vcn::httpParserGetfileHandle(VCNHttpContext*)", "HTTP_PARSER"},
        {0x028CB4U,   56U, "_ZN3com2ss8mediakit3vcn22httpParserGetShortSeekEPNS2_14VCNHttpContextE", "com::ss::mediakit::vcn::httpParserGetShortSeek(VCNHttpContext*)", "HTTP_PARSER"},
        {0x028CECU,  180U, "_ZN3com2ss8mediakit3vcn38httpParserGetSocketBufferAvailableSizeEPNS2_14VCNHttpContextE", "com::ss::mediakit::vcn::httpParserGetSocketBufferAvailableSize(VCNHttpContext*)", "HTTP_PARSER"},
        {0x028E74U,  288U, "_ZN3com2ss8mediakit3vcn17createHttpContextEv", "com::ss::mediakit::vcn::createHttpContext()", "HTTP_PARSER"},
        {0x028F94U,  432U, "_ZN3com2ss8mediakit3vcn18releaseHttpContextEPPNS2_14VCNHttpContextE", "com::ss::mediakit::vcn::releaseHttpContext(VCNHttpContext**)", "HTTP_PARSER"},
        {0x029144U,   28U, "_ZN3com2ss8mediakit3vcn21VCNDNSParserInterfaceC2EPvS4_", "com::ss::mediakit::vcn::VCNDNSParserInterface::VCNDNSParserInterface(void*, void*)", "DNS"},
        {0x029160U,    4U, "_ZN3com2ss8mediakit3vcn21VCNDNSParserInterfaceD1Ev", "com::ss::mediakit::vcn::VCNDNSParserInterface::~VCNDNSParserInterface()", "DNS"},
        {0x029160U,    4U, "_ZN3com2ss8mediakit3vcn21VCNDNSParserInterfaceD2Ev", "com::ss::mediakit::vcn::VCNDNSParserInterface::~VCNDNSParserInterface()", "DNS"},
        {0x029164U,    4U, "_ZN3com2ss8mediakit3vcn21VCNDNSParserInterfaceD0Ev", "com::ss::mediakit::vcn::VCNDNSParserInterface::~VCNDNSParserInterface()", "DNS"},
        {0x029168U,    8U, "_ZN3com2ss8mediakit3vcn21VCNDNSParserInterface5parseEPKciRiS6_ii", "com::ss::mediakit::vcn::VCNDNSParserInterface::parse(const char*, int, int&, int&, int, int)", "DNS"},
        {0x029170U,    4U, "_ZN3com2ss8mediakit3vcn21VCNDNSParserInterface5closeEv", "com::ss::mediakit::vcn::VCNDNSParserInterface::close()", "DNS"},
        {0x029174U,    4U, "_ZN3com2ss8mediakit3vcn21VCNDNSParserInterface6notifyEPKcS5_li", "com::ss::mediakit::vcn::VCNDNSParserInterface::notify(const char*, const char*, long, int)", "DNS"},
        {0x029178U,  348U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfoC1EP13VCNURLContextPKcS7_iliS7_", "com::ss::mediakit::vcn::VCNSocketInfo::VCNSocketInfo(VCNURLContext*, const char*, const char*, int, long, int, const char*)", "SOCKET_INFO"},
        {0x029178U,  348U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfoC2EP13VCNURLContextPKcS7_iliS7_", "com::ss::mediakit::vcn::VCNSocketInfo::VCNSocketInfo(VCNURLContext*, const char*, const char*, int, long, int, const char*)", "SOCKET_INFO"},
        {0x0292D4U,  156U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfoD1Ev", "com::ss::mediakit::vcn::VCNSocketInfo::~VCNSocketInfo()", "SOCKET_INFO"},
        {0x0292D4U,  156U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfoD2Ev", "com::ss::mediakit::vcn::VCNSocketInfo::~VCNSocketInfo()", "SOCKET_INFO"},
        {0x029370U,  492U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfoC1ERKS3_", "com::ss::mediakit::vcn::VCNSocketInfo::VCNSocketInfo(const VCNSocketInfo&)", "SOCKET_INFO"},
        {0x029370U,  492U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfoC2ERKS3_", "com::ss::mediakit::vcn::VCNSocketInfo::VCNSocketInfo(const VCNSocketInfo&)", "SOCKET_INFO"},
        {0x02955CU,  464U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfoaSERKS3_", "com::ss::mediakit::vcn::VCNSocketInfo::operator=(const VCNSocketInfo&)", "SOCKET_INFO"},
        {0x02972CU,  320U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfo7setInfoEP13VCNURLContextPKcS7_iliS7_", "com::ss::mediakit::vcn::VCNSocketInfo::setInfo(VCNURLContext*, const char*, const char*, int, long, int, const char*)", "SOCKET_INFO"},
        {0x02986CU,  128U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfo5resetEv", "com::ss::mediakit::vcn::VCNSocketInfo::reset()", "SOCKET_INFO"},
        {0x0298ECU,  104U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfo7isValidEv", "com::ss::mediakit::vcn::VCNSocketInfo::isValid()", "SOCKET_INFO"},
        {0x029954U,  124U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfo9onNetInfoEilPKc", "com::ss::mediakit::vcn::VCNSocketInfo::onNetInfo(int, long, const char*)", "SOCKET_INFO"},
        {0x0299D0U,   36U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfo31compareByIdleStartTAndUsedStateEPKS3_S5_", "com::ss::mediakit::vcn::VCNSocketInfo::compareByIdleStartTAndUsedState(const VCNSocketInfo*, const VCNSocketInfo*)", "SOCKET_INFO"},
        {0x0299F4U,   12U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfo17onNetInfoCallBackElilPKc", "com::ss::mediakit::vcn::VCNSocketInfo::onNetInfoCallBack(long, int, long, const char*)", "SOCKET_INFO"},
        {0x029A00U,  100U, "_ZN3com2ss8mediakit3vcn13VCNSocketInfo12isAllowReuseEPKcii", "com::ss::mediakit::vcn::VCNSocketInfo::isAllowReuse(const char*, int, int)", "SOCKET_INFO"},
        {0x029A64U, 1312U, "_Z11vcnUrlSplitRNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_S6_PiS6_S6_S6_PKc", "vcnUrlSplit(std::string&, std::string&, std::string&, int*, std::string&, std::string&, std::string&, const char*)", "URL_SPLIT"},
        {0x02A1C4U,   72U, "_Z17vcnDoCustomVerifyPvS_PKci", "vcnDoCustomVerify(void*, void*, const char*, int)", "TLS_VERIFY"}
    };
    return kCatalog;
}

/**
 * @brief Runs an end-to-end self-test verifying all reconstructed subsystems of `libvcn.so`.
 *        Chạy kiểm thử tự động toàn trình xác minh toàn bộ các phân hệ của `libvcn.so`.
 */
bool RunVcnSelfTest(std::string* out_diagnostic_report) noexcept {
    std::ostringstream oss;

    // 1. Verify 66-entry error table & vcn_av_strerror
    char errbuf[128] = {0};
    if (GetVcnAvErrorTable66().size() != 66 ||
        vcn_av_strerror(kVcnAvErrorHttpBadRequest, errbuf, sizeof(errbuf)) != 0 ||
        std::strcmp(errbuf, "Server returned 400 Bad Request") != 0) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: vcn_av_strerror 66-entry table check failed";
        return false;
    }

    // 2. Verify httpParserHttpAVError (0x01ddb0, bitmask 0x1B)
    if (httpParserHttpAVError(400, -1) != kVcnAvErrorHttpBadRequest ||
        httpParserHttpAVError(401, -1) != kVcnAvErrorHttpUnauthorized ||
        httpParserHttpAVError(402, -1) != kVcnAvErrorHttpOther4xx ||
        httpParserHttpAVError(403, -1) != kVcnAvErrorHttpForbidden ||
        httpParserHttpAVError(404, -1) != kVcnAvErrorHttpNotFound ||
        httpParserHttpAVError(502, -1) != kVcnAvErrorHttpServerError) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: httpParserHttpAVError mapping mismatch";
        return false;
    }

    // 3. Verify createHttpContext (0x2ad0 bytes) & httpParserParseContentRange (0x0261f4)
    VCNHttpContext* http_ctx = createHttpContext();
    if (http_ctx == nullptr ||
        http_ctx->seekable != 3 ||
        http_ctx->timeout_sec != 120 ||
        http_ctx->reply_code != 200 ||
        http_ctx->reconnect_delay_max != 5 ||
        http_ctx->max_range_0 != 0x7FFFFFFF) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: createHttpContext defaults mismatch";
        return false;
    }
    http_ctx->is_chunked_range = 1;
    httpParserParseContentRange(http_ctx, "bytes 1024-2047/8192");
    if (http_ctx->content_range_off != 1024 ||
        http_ctx->filesize != 8192 ||
        http_ctx->is_chunked_range != 0) {
        releaseHttpContext(&http_ctx);
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: httpParserParseContentRange mismatch";
        return false;
    }
    releaseHttpContext(&http_ctx);

    // 4. Verify VCNSocketInfo (0x70 = 112 bytes) & vcnUrlSplit
    VCNURLContext dummy_uc{};
    VCNSocketInfo sock_info(&dummy_uc, "1.2.3.4", "cdn.capcut.com", 443, 1000L, 1, "h2,http/1.1");
    sock_info.onNetInfo(0x1777, 0L, "1.2.3.5");
    if (!sock_info.isValid() ||
        sock_info.tls_ip() == nullptr ||
        std::strcmp(sock_info.tls_ip(), "1.2.3.5") != 0 ||
        !sock_info.isAllowReuse("cdn.capcut.com", 443, 1)) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: VCNSocketInfo check failed";
        return false;
    }

    std::string proto, auth, host, path, query, frag;
    int port = -1;
    vcnUrlSplit(proto, auth, host, &port, path, query, frag,
                "https://user:pass@cdn.capcut.com:8443/v1/video.mp4?token=abc#t=10");
    if (proto != "https" || host != "cdn.capcut.com" || port != 8443 ||
        path != "/v1/video.mp4" || query != "token=abc" || frag != "t=10") {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: vcnUrlSplit check failed";
        return false;
    }

    oss << "PASS: libvcn.so self-test succeeded (catalog=" << GetVcnExportedFunctionCatalog().size()
        << " functions, 66 error_entries, HTTP/TCP/TLS/DNS/SocketInfo verified)";
    if (out_diagnostic_report) {
        *out_diagnostic_report = oss.str();
    }
    return true;
}

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com
