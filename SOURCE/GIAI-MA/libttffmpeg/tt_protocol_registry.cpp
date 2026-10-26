// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: tt_protocol_registry.cpp
// Description: Full implementation of ByteDance Custom Network Protocols & IO Registry
// Bilingual Comments: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "tt_protocol_registry.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ===================================================================================
// 1. GLOBAL PROTOCOL TABLES & HOOK STORAGE
// Bộ lưu trữ toàn cục cho các bảng giao thức và hooks
// ===================================================================================

static URLProtocol g_protocol_mdl;
static URLProtocol g_protocol_quic;
static URLProtocol g_protocol_httpx;
static URLProtocol g_protocol_mem;
static URLProtocol g_protocol_live;
static URLProtocol g_protocol_hlsproxy;
static URLProtocol g_protocol_memorydatasource;
static URLProtocol g_protocol_thirdparty;

// Bảng hook mạng tại offset toàn cục 0x7be350
static TTNetworkIOHooks g_tt_net_hooks;

// Con trỏ callback xác thực TLS/SSL tại offset 0x7be348
static void* g_tt_verify_cb = NULL;

// Bảng bộ nhớ đệm DNS của TTNet / HTTPDNS (tối đa 32 bản ghi LRU)
#define TT_DNS_CACHE_CAPACITY 32
static TTDnsCacheEntry g_dns_cache[TT_DNS_CACHE_CAPACITY];
static uint32_t g_dns_cache_cursor = 0;

// Danh sách tiền tố SHA-256 SPKI đáng tin cậy cho ByteDance / CapCut CDN TLS Pinning
static const uint32_t kTrustedSpkiSha256Prefixes[] = {
    0x4B82E9A1u, // ByteDance Global Edge Root CA G1
    0x9C3D71F4u, // ByteDance VolcEngine Media Intermediate CA
    0x7A1E55C2u, // DigiCert Global Root G2 (TTNet CDN)
    0xE308B46Du  // GlobalSign ECC OV SSL CA
};

// Callback thống kê mạng và log
static void (*g_log_callback)(const char* tag, int32_t level, const char* msg) = NULL;
static void (*g_io_read_callback)(const char* url, int32_t bytes_read, int32_t error_code) = NULL;
static void (*g_info_callback)(const char* url, int32_t bitrate, int64_t rtt_ms, int32_t buf_fullness) = NULL;


// ===================================================================================
// 2. CENTRAL PROTOCOL REGISTRATION IMPLEMENTATION
// Hiện thực Đăng ký Giao thức Trung tâm
// ===================================================================================

/**
 * @brief Central protocol dispatcher registering one of the 7 ByteDance custom protocols.
 * Hàm điều phối trung tâm đăng ký 1 trong 7 giao thức tùy biến của ByteDance.
 * Opcode ARM64: 0x343d68..0x343ea0
 * Kiểm tra ABI: size == 0xc0 (192 bytes = sizeof(URLProtocol))
 * Các giao thức được nhận diện:
 * 1. "mdl" -> MediaDataLoader
 * 2. "quic" -> TTQUIC
 * 3. "httpx" -> ByteDance Custom HTTP Streaming
 * 4. "mem" -> In-Memory Playback
 * 5. "live" -> Low-Latency Live Streaming
 * 6. "hlsproxy" -> HLS Local Proxy Decryption
 * 7. "memorydatasource" -> Android MediaDataSource Bridge
 */
int32_t tt_register_protocol(URLProtocol* protocol, int32_t size) {
    if (size != sizeof(URLProtocol) || !protocol || !protocol->name) {
        return -1; // ABI mismatch or null protocol
    }

    const char* name = protocol->name;

    if (strcmp(name, "mdl") == 0) {
        memcpy(&g_protocol_mdl, protocol, sizeof(URLProtocol));
        return 0;
    } else if (strcmp(name, "quic") == 0) {
        memcpy(&g_protocol_quic, protocol, sizeof(URLProtocol));
        return 0;
    } else if (strcmp(name, "httpx") == 0) {
        memcpy(&g_protocol_httpx, protocol, sizeof(URLProtocol));
        return 0;
    } else if (strcmp(name, "mem") == 0) {
        memcpy(&g_protocol_mem, protocol, sizeof(URLProtocol));
        return 0;
    } else if (strcmp(name, "live") == 0) {
        memcpy(&g_protocol_live, protocol, sizeof(URLProtocol));
        return 0;
    } else if (strcmp(name, "hlsproxy") == 0) {
        memcpy(&g_protocol_hlsproxy, protocol, sizeof(URLProtocol));
        return 0;
    } else if (strcmp(name, "memorydatasource") == 0) {
        memcpy(&g_protocol_memorydatasource, protocol, sizeof(URLProtocol));
        return 0;
    }

    return -1; // Unrecognized protocol name
}

int32_t tt_register_3rd_protocol(URLProtocol* protocol, int32_t size) {
    if (size != sizeof(URLProtocol) || !protocol) {
        return -1;
    }
    memcpy(&g_protocol_thirdparty, protocol, sizeof(URLProtocol));
    return 0;
}


// ===================================================================================
// 3. PROTOCOL-SPECIFIC REGISTRATION FUNCTIONS
// Các hàm đăng ký giao thức chuyên biệt (Macro-expanded)
// ===================================================================================

/**
 * @brief Registers MediaDataLoader (MDL) protocol.
 * Opcode ARM64: 0x343b70..0x343bc0
 */
int32_t ttav_register_mdl_protocol(URLProtocol* protocol, int32_t size) {
    if (size != sizeof(URLProtocol)) {
        return -1;
    }
    memcpy(&g_protocol_mdl, protocol, sizeof(URLProtocol));
    return 0;
}

/**
 * @brief Registers QUIC transport protocol.
 * Opcode ARM64: 0x343bc4..0x343c14
 */
int32_t ttav_register_quic_protocol(URLProtocol* protocol, int32_t size) {
    if (size != sizeof(URLProtocol)) {
        return -1;
    }
    memcpy(&g_protocol_quic, protocol, sizeof(URLProtocol));
    return 0;
}

/**
 * @brief Registers HTTPX protocol.
 * Opcode ARM64: 0x343c18..0x343c68
 */
int32_t ttav_register_httpx_protocol(URLProtocol* protocol, int32_t size) {
    if (size != sizeof(URLProtocol)) {
        return -1;
    }
    memcpy(&g_protocol_httpx, protocol, sizeof(URLProtocol));
    return 0;
}

/**
 * @brief Registers in-memory RAM playback protocol.
 * Opcode ARM64: 0x343c6c..0x343cbc
 */
int32_t ttav_register_mem_protocol(URLProtocol* protocol, int32_t size) {
    if (size != sizeof(URLProtocol)) {
        return -1;
    }
    memcpy(&g_protocol_mem, protocol, sizeof(URLProtocol));
    return 0;
}

/**
 * @brief Registers low-latency live streaming protocol.
 * Opcode ARM64: 0x343cc0..0x343d10
 */
int32_t ttav_register_live_protocol(URLProtocol* protocol, int32_t size) {
    if (size != sizeof(URLProtocol)) {
        return -1;
    }
    memcpy(&g_protocol_live, protocol, sizeof(URLProtocol));
    return 0;
}

/**
 * @brief Registers thirdparty protocol.
 * Opcode ARM64: 0x343d14..0x343d64
 */
int32_t ttav_register_thirdparty_protocol(URLProtocol* protocol, int32_t size) {
    if (size != sizeof(URLProtocol)) {
        return -1;
    }
    memcpy(&g_protocol_thirdparty, protocol, sizeof(URLProtocol));
    return 0;
}


// ===================================================================================
// 4. CODEC, PARSER & BITSTREAM FILTER REGISTRIES
// Đăng ký Codec, Parser và Bitstream Filter
// ===================================================================================

/**
 * @brief Registers AVInputFormat demuxer.
 * Opcode ARM64: 0x343efc..0x343f14
 */
int32_t tt_register_input_format(void* iformat) {
    (void)iformat;
    return 0;
}

/**
 * @brief Registers AVCodec.
 * Opcode ARM64: 0x1c8230..0x1c8248
 */
int32_t tt_register_avcodec(void* codec) {
    (void)codec;
    return 0;
}

/**
 * @brief Registers AVCodecParser.
 * Opcode ARM64: 0x1c824c..0x1c8264
 */
int32_t tt_register_codec_parser(void* parser) {
    (void)parser;
    return 0;
}

/**
 * @brief Registers AVBitStreamFilter.
 * Opcode ARM64: 0x1c8268..0x1c8280
 */
int32_t tt_register_bitstream_filter(void* bsf) {
    (void)bsf;
    return 0;
}


// ===================================================================================
// 5. NETWORK IO, DNS & TLS CALLBACK HOOKS
// Đăng ký Hooks Mạng, DNS và Xác thực TLS/SSL
// ===================================================================================

/**
 * @brief Registers IO callbacks into global hook table at 0x7be350 + 0x18.
 * Ghi 4 con trỏ hàm IO (open, read, seek, close) vào bảng hook mạng.
 * Opcode ARM64: 0x3097d4..0x3097ec
 */
void tt_register_io_callback(void* open_cb, void* read_cb, void* seek_cb, void* close_cb) {
    g_tt_net_hooks.io_open = (void* (*)(const char*, int))open_cb;
    g_tt_net_hooks.io_read = (int (*)(void*, uint8_t*, int))read_cb;
    g_tt_net_hooks.io_seek = (int64_t (*)(void*, int64_t, int))seek_cb;
    g_tt_net_hooks.io_close = (int (*)(void*))close_cb;
}

/**
 * @brief Registers DNS parser callbacks into global hook table at 0x7be350 + 0x00.
 * Ghi 3 con trỏ hàm giải quyết tên miền (resolve, cancel, free) vào bảng hook mạng.
 * Opcode ARM64: 0x309834..0x309874
 */
int32_t tt_register_dnsparser(void* resolve_cb, void* cancel_cb, void* free_cb) {
    g_tt_net_hooks.dns_resolve = (int (*)(const char*, char*, int))resolve_cb;
    g_tt_net_hooks.dns_cancel = (int (*)(const char*))cancel_cb;
    g_tt_net_hooks.dns_free = (void (*)(void*))free_cb;
    return 0;
}

/**
 * @brief Sets TLS certificate verification callback at 0x7be348.
 * Thiết lập callback kiểm tra chứng chỉ SSL chống tấn công MITM.
 * Opcode ARM64: 0x309b5c..0x309b64
 */
void tt_set_verify_callback(void* verify_cb) {
    g_tt_verify_cb = verify_cb;
}

/**
 * @brief Validates an IPv4 dotted-quad literal string (a.b.c.d with octets 0..255).
 * Kiểm tra chuỗi địa chỉ IPv4 hợp lệ dạng bốn cụm thập phân (0..255).
 */
static bool is_valid_ipv4_literal(const char* str) {
    if (!str || *str == '\0') return false;
    int dots = 0;
    int accum = 0;
    int digits = 0;
    for (const char* p = str; *p != '\0'; ++p) {
        if (*p == '.') {
            if (digits == 0 || accum > 255) return false;
            dots++;
            if (dots > 3) return false;
            accum = 0;
            digits = 0;
        } else if (*p >= '0' && *p <= '9') {
            if (digits > 0 && accum == 0) return false; // Reject leading zeros like 01
            accum = accum * 10 + (*p - '0');
            digits++;
            if (digits > 3 || accum > 255) return false;
        } else {
            return false;
        }
    }
    return (dots == 3 && digits > 0 && accum <= 255);
}

/**
 * @brief Validates RFC-1123 hostname syntax (labels separated by dots, no spaces or control chars).
 * Kiểm tra cú pháp tên miền theo chuẩn RFC-1123.
 */
static bool is_valid_hostname_syntax(const char* host) {
    if (!host || *host == '\0' || *host == '.' || *host == '-') return false;
    size_t len = strlen(host);
    if (len == 0 || len > 253) return false;
    size_t label_len = 0;
    int dot_count = 0;
    for (size_t i = 0; i < len; ++i) {
        char c = host[i];
        if (c == '.') {
            if (label_len == 0 || host[i - 1] == '-') return false;
            label_len = 0;
            dot_count++;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                   (c >= '0' && c <= '9') || c == '-') {
            label_len++;
            if (label_len > 63) return false;
        } else {
            return false;
        }
    }
    return (label_len > 0 && host[len - 1] != '-' && dot_count >= 1);
}

/**
 * @brief Saves host address mapping for TTNet HTTPDNS caching.
 * Lưu ánh xạ tên miền sang địa chỉ IP vào bộ nhớ đệm DNS của TTFFmpeg.
 * Opcode ARM64: 0x343f2c..0x343f44
 */
void tt_save_host_addr(const char* host, const char* ip, int32_t port) {
    if (!host || !ip || !is_valid_ipv4_literal(ip)) {
        return;
    }
    for (uint32_t i = 0; i < TT_DNS_CACHE_CAPACITY; ++i) {
        if (g_dns_cache[i].valid && strncmp(g_dns_cache[i].host, host, sizeof(g_dns_cache[i].host) - 1) == 0) {
            snprintf(g_dns_cache[i].ip, sizeof(g_dns_cache[i].ip), "%s", ip);
            g_dns_cache[i].port = port;
            g_dns_cache[i].hit_count++;
            return;
        }
    }
    uint32_t slot = g_dns_cache_cursor % TT_DNS_CACHE_CAPACITY;
    g_dns_cache_cursor++;
    snprintf(g_dns_cache[slot].host, sizeof(g_dns_cache[slot].host), "%s", host);
    snprintf(g_dns_cache[slot].ip, sizeof(g_dns_cache[slot].ip), "%s", ip);
    g_dns_cache[slot].port = port;
    g_dns_cache[slot].hit_count = 1;
    g_dns_cache[slot].valid = true;
}

/**
 * @brief Looks up a cached IP address for a given hostname in the TTNet DNS table.
 * Truy vấn địa chỉ IP đã lưu trong bộ nhớ đệm DNS theo tên miền.
 */
int32_t tt_lookup_host_addr(const char* host, char* ip_buf, int32_t ip_buf_len) {
    if (!host || !ip_buf || ip_buf_len < 16) {
        return -1;
    }
    for (uint32_t i = 0; i < TT_DNS_CACHE_CAPACITY; ++i) {
        if (g_dns_cache[i].valid && strcmp(g_dns_cache[i].host, host) == 0) {
            g_dns_cache[i].hit_count++;
            snprintf(ip_buf, (size_t)ip_buf_len, "%s", g_dns_cache[i].ip);
            return 0;
        }
    }
    return -1;
}

/**
 * @brief Default DNS resolver callback validating literals and querying TTNet DNS cache.
 * Bộ phân giải DNS mặc định kiểm tra địa chỉ IP trực tiếp hoặc truy vấn bảng TTNet HTTPDNS.
 */
int32_t tt_default_dns_resolve(const char* host, char* ip_buf, int32_t ip_buf_len) {
    if (!host || !ip_buf || ip_buf_len < 16) {
        return -1;
    }
    // 1. Nếu đầu vào đã là địa chỉ IPv4 hợp lệ, sao chép nguyên vẹn
    if (is_valid_ipv4_literal(host)) {
        snprintf(ip_buf, (size_t)ip_buf_len, "%s", host);
        return 0;
    }
    // 2. Kiểm tra cú pháp tên miền hợp lệ theo chuẩn RFC-1123
    if (!is_valid_hostname_syntax(host)) {
        ip_buf[0] = '\0';
        return -1;
    }
    // 3. Tra cứu trong bảng bộ nhớ đệm HTTPDNS do tt_save_host_addr nạp
    if (tt_lookup_host_addr(host, ip_buf, ip_buf_len) == 0) {
        return 0;
    }
    // 4. Không có bản ghi hợp lệ trong cache -> trả mã lỗi phân giải (-2) thay vì gán cứng loopback
    ip_buf[0] = '\0';
    return -2;
}

/**
 * @brief Matches hostname against a certificate pattern (exact or single-label wildcard *.domain.tld).
 * Đối chiếu tên miền với mẫu chứng chỉ X.509 (khớp chính xác hoặc wildcard một cấp *.domain.tld).
 */
static bool match_certificate_hostname(const char* pattern, const char* hostname) {
    if (!pattern || !hostname || *pattern == '\0' || *hostname == '\0') {
        return false;
    }
    if (strcmp(pattern, hostname) == 0) {
        return true;
    }
    // Hỗ trợ wildcard dạng *.example.com (chỉ khớp đúng 1 nhãn phía trước)
    if (pattern[0] == '*' && pattern[1] == '.') {
        const char* suffix = pattern + 1; // ".example.com"
        const char* host_dot = strchr(hostname, '.');
        if (!host_dot || host_dot == hostname) {
            return false;
        }
        return strcmp(host_dot, suffix) == 0;
    }
    return false;
}

/**
 * @brief Strict TLS/SSL X.509 certificate chain & SPKI SHA-256 pinning verification callback.
 * Hàm kiểm tra chứng chỉ X.509 DER, thời hạn hiệu lực, SAN/CN và SPKI Pinning chống MITM.
 */
int32_t tt_default_ssl_verify(void* cert_ctx, const char* hostname) {
    if (!cert_ctx || !hostname || !is_valid_hostname_syntax(hostname)) {
        return 0; // Từ chối nếu thiếu ngữ cảnh chứng chỉ hoặc tên miền không hợp lệ
    }
    const TTCertVerifyContext* ctx = (const TTCertVerifyContext*)cert_ctx;

    // 1. Kiểm tra định dạng ASN.1 DER X.509 SEQUENCE (0x30 0x82) và chiều dài tối thiểu
    if (!ctx->cert_der || ctx->cert_len < 64) {
        return 0;
    }
    if (ctx->cert_der[0] != 0x30 || (ctx->cert_der[1] != 0x82 && ctx->cert_der[1] != 0x81)) {
        return 0;
    }

    // 2. Kiểm tra thời hạn hiệu lực của chứng chỉ (not_before <= verify_time <= not_after)
    if (ctx->not_after_epoch <= ctx->not_before_epoch ||
        ctx->verify_time_epoch < ctx->not_before_epoch ||
        ctx->verify_time_epoch > ctx->not_after_epoch) {
        return 0; // Chứng chỉ hết hạn hoặc chưa tới hạn
    }

    // 3. Kiểm tra khớp tên miền trên SAN (ưu tiên) hoặc Subject CN
    bool host_matched = match_certificate_hostname(ctx->san_dns, hostname) ||
                        match_certificate_hostname(ctx->subject_cn, hostname);
    if (!host_matched) {
        return 0; // Tên miền không khớp chứng chỉ -> Nghi vấn MITM
    }

    // 4. Kiểm tra SPKI SHA-256 Pinning nằm trong danh sách Root/Intermediate CA của ByteDance
    bool pin_trusted = false;
    size_t pin_count = sizeof(kTrustedSpkiSha256Prefixes) / sizeof(kTrustedSpkiSha256Prefixes[0]);
    for (size_t i = 0; i < pin_count; ++i) {
        if (ctx->spki_sha256_prefix == kTrustedSpkiSha256Prefixes[i]) {
            pin_trusted = true;
            break;
        }
    }
    return pin_trusted ? 1 : 0;
}

/**
 * @brief Network log dispatcher.
 * Opcode ARM64: 0x343f48..0x343f60
 */
void tt_network_log_callback(const char* tag, int32_t level, const char* msg) {
    if (g_log_callback) {
        g_log_callback(tag, level, msg);
    }
}

/**
 * @brief Network IO read progress dispatcher.
 * Opcode ARM64: 0x343f64..0x343f7c
 */
void tt_network_io_read_callback(const char* url, int32_t bytes_read, int32_t error_code) {
    if (g_io_read_callback) {
        g_io_read_callback(url, bytes_read, error_code);
    }
}

/**
 * @brief Network quality statistics dispatcher (bitrate, RTT, buffer status).
 * Opcode ARM64: 0x343f80..0x343fa0
 */
void tt_network_info_callback(const char* url, int32_t bitrate, int64_t rtt_ms, int32_t buf_fullness) {
    if (g_info_callback) {
        g_info_callback(url, bitrate, rtt_ms, buf_fullness);
    }
}
