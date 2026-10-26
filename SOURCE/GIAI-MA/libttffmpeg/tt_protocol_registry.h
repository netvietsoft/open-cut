// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: tt_protocol_registry.h
// Description: Header for ByteDance Custom Network Protocols & IO Registry
// ===================================================================================

#pragma once

#include "ttffmpeg_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- Main Protocol Registry ---
int32_t tt_register_protocol(URLProtocol* protocol, int32_t size);
int32_t tt_register_3rd_protocol(URLProtocol* protocol, int32_t size);

// --- Protocol Registration Specific Functions ---
int32_t ttav_register_mdl_protocol(URLProtocol* protocol, int32_t size);
int32_t ttav_register_quic_protocol(URLProtocol* protocol, int32_t size);
int32_t ttav_register_httpx_protocol(URLProtocol* protocol, int32_t size);
int32_t ttav_register_mem_protocol(URLProtocol* protocol, int32_t size);
int32_t ttav_register_live_protocol(URLProtocol* protocol, int32_t size);
int32_t ttav_register_thirdparty_protocol(URLProtocol* protocol, int32_t size);

// --- Codec, Parser & Filter Registries ---
int32_t tt_register_input_format(void* iformat);
int32_t tt_register_avcodec(void* codec);
int32_t tt_register_codec_parser(void* parser);
int32_t tt_register_bitstream_filter(void* bsf);

// --- Network IO, DNS & TLS Callbacks ---
void tt_register_io_callback(void* open_cb, void* read_cb, void* seek_cb, void* close_cb);
int32_t tt_register_dnsparser(void* resolve_cb, void* cancel_cb, void* free_cb);
void tt_set_verify_callback(void* verify_cb);
void tt_save_host_addr(const char* host, const char* ip, int32_t port);
int32_t tt_lookup_host_addr(const char* host, char* ip_buf, int32_t ip_buf_len);
int32_t tt_default_dns_resolve(const char* host, char* ip_buf, int32_t ip_buf_len);
int32_t tt_default_ssl_verify(void* cert_ctx, const char* hostname);
void tt_network_log_callback(const char* tag, int32_t level, const char* msg);
void tt_network_io_read_callback(const char* url, int32_t bytes_read, int32_t error_code);
void tt_network_info_callback(const char* url, int32_t bitrate, int64_t rtt_ms, int32_t buf_fullness);

#ifdef __cplusplus
}
#endif
