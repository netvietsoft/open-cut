/**
 * @file vcn_types.h
 * @brief Clean-Room ABI Structs, Constants, Error Tables & URLProtocol Descriptors for libvcn.so.
 *        Cấu trúc ABI, hằng số, bảng lỗi 66 mục và bộ mô tả giao thức URLProtocol cho libvcn.so (ByteDance MediaKit VCN).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so
 *   Size / Dung lượng: 214,960 bytes (0x347b0)
 *   SHA-256: b1060ae9e0451374c5f18ad95a777123d937c9c7e81c93b8bbe98618790af3e3
 *   Sections / Các phân đoạn ELF:
 *     - .text        : VMA 0x008f80..0x02a20c (135,820 bytes, 33,955 instructions)
 *     - .rodata      : VMA 0x02a210..0x02e4fb (17,131 bytes)
 *     - .fini_array  : VMA 0x035728..0x035738 (file offset 0x031728, 16 bytes)
 *     - .data.rel.ro : VMA 0x035738..0x037778 (file offset 0x031738, 8,256 bytes)
 *     - .data        : VMA 0x038000..0x038018 (file offset 0x034000, 24 bytes)
 *     - .bss         : VMA 0x038018..0x038470 (1,112 bytes)
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   [OBSERVED] Directly verified from AArch64 machine code & .rodata/.data.rel.ro bytes of libvcn.so.
 *              Được kiểm chứng trực tiếp từ mã máy AArch64 và byte .rodata/.data.rel.ro của libvcn.so.
 */

#ifndef NEXTAI_OPENCUT_VCN_TYPES_H_
#define NEXTAI_OPENCUT_VCN_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

/**
 * @brief Binary & Protocol Constants [OBSERVED at .rodata 0x02a290, 0x02ca3d, 0x02cd23, 0x02e330]
 *        Các hằng số nhị phân và giao thức mạng trong `.rodata` của `libvcn.so`
 */
constexpr uint32_t    kVcnBinarySizeBytes        = 214960U;
constexpr size_t      kVcnMaxMallocBytes         = 0x7FFFFFDFULL;          // 0x00eac8: mov w9, #0xffdf; movk w9, #0x7fff, lsl #16
constexpr uint64_t    kVcnRelativeTimeOffsetUs   = 0x000000233438E800ULL;  // 0x00b1a4..0x00b1ac: 42ULL * 365 * 86400 * 1000000
constexpr size_t      kVcnTcpContextSize         = 0x0178U;                // 376 bytes (.data.rel.ro 0x036018)
constexpr size_t      kVcnTlsContextSize         = 0x0140U;                // 320 bytes (.data.rel.ro 0x036578)
constexpr size_t      kVcnHttpContextSize        = 0x18A0U;                // 6,304 bytes (.data.rel.ro 0x0369d8 & 0x0373b8)
constexpr size_t      kVcnParserHttpContextSize  = 0x2AD0U;                // 10,960 bytes (0x028e94: mov w2, #0x2ad0)
constexpr size_t      kVcnSocketInfoSize         = 0x0070U;                // 112 bytes (0x029178..0x0292d0)
constexpr const char* kVcnDefaultUserAgent       = "ttplayer(default)57.56.101"; // .rodata 0x02ca3d
constexpr const char* kVcnDefaultWhitelist       = "http,https,tls,rtp,tcp,udp,crypto,httpproxy"; // .rodata 0x02cd23

/**
 * @brief HTTP AVERROR Codes (`FFERRTAG` at `.rodata 0x02e330..0x02e344` & `0x01ddb0..0x01ddf4`)
 *        Bảng mã lỗi HTTP AVERROR tại `.rodata 0x02e330` và `httpParserHttpAVError` (`0x01ddb0`)
 *
 * Disassembly of `httpParserHttpAVError(int http_code, int default_averror)` (`0x01ddb0..0x01ddf4`):
 *   - `0x01ddb0: sub  w8, w0, #0x190`       (`w8 = http_code - 400`)
 *   - `0x01ddb4: cmp  w8, #5`
 *   - `0x01ddb8: b.hs #0x1ddc8`
 *   - `0x01ddbc: mov  w9, #0x1b`            (`0x1B = 0b11011` -> bits 0, 1, 3, 4 for 400, 401, 403, 404)
 *   - `0x01ddc0: lsr  w9, w9, w8`
 *   - `0x01ddc4: tbnz w9, #0, #0x1dde8`     (loads `.rodata 0x02e330[w8]`)
 *   - `0x01ddc8: mov  w9, #0xca08; movk w9, #0xa7a7, lsl #16` (`0xA7A7CA08 = AVERROR_HTTP_SERVER_ERROR`)
 *   - `0x01ddcc: cmp  w0, #0x1f3`           (`http_code > 499`)
 *   - `0x01ddd4: csel w10, w9, w1, gt`
 *   - `0x01ddd8: orr  w9, w9, #0x100`       (`0xA7A7CB08 = AVERROR_HTTP_OTHER_4XX`)
 *   - `0x01dddc: cmp  w8, #0x64`            (`(uint32_t)(http_code - 400) < 100`)
 *   - `0x01dde0: csel w0, w9, w10, lo`
 */
constexpr int32_t kVcnAvErrorHttpBadRequest   = static_cast<int32_t>(0xCFCFCB08U); // -808465656 (400)
constexpr int32_t kVcnAvErrorHttpUnauthorized = static_cast<int32_t>(0xCECFCB08U); // -825242872 (401)
constexpr int32_t kVcnAvErrorHttpForbidden    = static_cast<int32_t>(0xCCCFCB08U); // -858797304 (403)
constexpr int32_t kVcnAvErrorHttpNotFound     = static_cast<int32_t>(0xCBCFCB08U); // -875574520 (404)
constexpr int32_t kVcnAvErrorHttpOther4xx     = static_cast<int32_t>(0xA7A7CB08U); // -1482175736 (4xx)
constexpr int32_t kVcnAvErrorHttpServerError  = static_cast<int32_t>(0xA7A7CA08U); // -1482175992 (5xx)
constexpr int32_t kVcnErrorNullHttpContext    = static_cast<int32_t>(0xFFFE7960U); // -100000 (0x028c84: mov w0, #0x7960; movk w0, #0xfffe, lsl #16)
constexpr int32_t kVcnErrorCustomVerifyFailed = static_cast<int32_t>(0xFFFE7961U); // -99999  (0x02a1ec: mov x2, #-0x869f; movk x2, #0xfffe, lsl #16)

/**
 * @brief 5-Entry `.rodata 0x02e330` Lookup Table for HTTP 400..404 (`[OBSERVED]`)
 *        Bảng tra 5 mục tại `.rodata 0x02e330` cho mã trạng thái HTTP 400..404
 */
constexpr uint32_t kVcnHttp400To404ErrorTable[5] = {
    0xCFCFCB08U,  // 400: AVERROR_HTTP_BAD_REQUEST
    0xCECFCB08U,  // 401: AVERROR_HTTP_UNAUTHORIZED
    0xCFCFCB08U,  // 402: (masked out by 0x1B = 0b11011 -> falls through to 0xA7A7CB08)
    0xCCCFCB08U,  // 403: AVERROR_HTTP_FORBIDDEN
    0xCBCFCB08U   // 404: AVERROR_HTTP_NOT_FOUND
};

/**
 * @brief 24-Byte `VcnAvErrorEntry` at `.data.rel.ro 0x035740..0x035d70` (66 entries, stride `0x18`)
 *        Bố cục mục bảng lỗi 24-byte tại `.data.rel.ro 0x035740..0x035d70` (66 mục, bước nhảy `0x18`)
 */
struct VcnAvErrorEntry {
    int32_t     num;       // +0x00: AVERROR code
    int32_t     pad0;      // +0x04: alignment padding
    const char* tag;       // +0x08: Short symbolic tag (e.g. "HTTP_BAD_REQUEST")
    const char* str;       // +0x10: Human-readable message
};
static_assert(sizeof(VcnAvErrorEntry) == 24, "VcnAvErrorEntry must be 24 bytes on AArch64");

/**
 * @brief `AVDictionaryEntry` & `AVDictionary` (`0x0099c8..0x00a0c0`)
 *        Cấu trúc từ điển khóa-giá trị `AVDictionary` (`0x0099c8..0x00a0c0`)
 */
struct AVDictionaryEntry {
    char* key;
    char* value;
};

struct AVDictionary {
    int32_t            count;
    AVDictionaryEntry* elems;
};

/**
 * @brief 16-Byte `AVNetIOInterruptCB` (`0x01050c..0x01053c`)
 *        Cấu trúc callback kiểm tra ngắt I/O mạng `AVNetIOInterruptCB` (`0x01050c`)
 */
struct AVNetIOInterruptCB {
    int (*callback)(void* opaque);  // +0x00
    void* opaque;                   // +0x08
};
static_assert(sizeof(AVNetIOInterruptCB) == 16, "AVNetIOInterruptCB must be 16 bytes on AArch64");

struct VCNURLContext;

/**
 * @brief 200-Byte (`0xc8`) `URLProtocol` Descriptor [OBSERVED at `.data.rel.ro 0x035fa0, 0x036500, 0x036960, 0x037340`]
 *        Bố cục bộ mô tả giao thức `URLProtocol` 200-byte trong `.data.rel.ro`
 */
struct URLProtocol {
    const char* name;                                                                 // +0x00
    int (*url_open)(VCNURLContext* h, const char* url, int flags);                    // +0x08
    int (*url_open2)(VCNURLContext* h, const char* url, int flags, AVDictionary** options); // +0x10
    int (*url_accept)(VCNURLContext* s, VCNURLContext** c);                           // +0x18
    int (*url_handshake)(VCNURLContext* c);                                           // +0x20
    int (*url_read)(VCNURLContext* h, unsigned char* buf, int size);                  // +0x28
    int (*url_write)(VCNURLContext* h, const unsigned char* buf, int size);           // +0x30
    int64_t (*url_seek)(VCNURLContext* h, int64_t pos, int whence);                   // +0x38
    int (*url_close)(VCNURLContext* h);                                               // +0x40
    int (*url_read_pause)(VCNURLContext* h, int pause);                               // +0x48
    int64_t (*url_read_seek)(VCNURLContext* h, int stream_index, int64_t timestamp, int flags); // +0x50
    int (*url_get_file_handle)(VCNURLContext* h);                                     // +0x58
    int (*url_get_multi_file_handle)(VCNURLContext* h, int** handles, int* numhandles); // +0x60
    int (*url_get_short_seek)(VCNURLContext* h);                                      // +0x68
    int (*url_shutdown)(VCNURLContext* h, int flags);                                 // +0x70
    int         priv_data_size;                                                       // +0x78
    int         pad_7c;                                                               // +0x7c
    const void* priv_data_class;                                                      // +0x80
    int         flags;                                                                // +0x88
    int         pad_8c;                                                               // +0x8c
    int (*url_check)(VCNURLContext* h, int mask);                                     // +0x90
    int (*url_open_dir)(VCNURLContext* h);                                            // +0x98
    int (*url_read_dir)(VCNURLContext* h, void** next);                               // +0xa0
    int (*url_close_dir)(VCNURLContext* h);                                           // +0xa8
    int (*url_delete)(VCNURLContext* h);                                              // +0xb0
    int (*url_move)(VCNURLContext* h_src, VCNURLContext* h_dst);                      // +0xb8
    const char* default_whitelist;                                                    // +0xc0
};
static_assert(sizeof(URLProtocol) == 0xC8, "URLProtocol must be 200 bytes (0xc8) on AArch64");

/**
 * @brief `VCNURLContext` ABI Layout [OBSERVED at `0x010540..0x0123e0`, `0x014cb0`, `0x0171ac`, `0x028c80`, `0x02a1c4`]
 *        Bố cục cấu trúc `VCNURLContext` (khớp mọi độ lệch byte trong mã máy AArch64)
 */
using VcnNetInfoCallbackFn = void (*)(void* handle, int type, int64_t code, const char* info);
using VcnCustomVerifyFn    = int (*)(void* url_ctx, void* ssl_ctx, const char* host, int port);

struct VCNURLContext {
    const void*          av_class;               // +0x00 (`0x035e08` `&vcn_context_class`)
    const URLProtocol*   prot;                   // +0x08 (`0x028c98: ldr x9, [x8, #8]`)
    void*                priv_data;              // +0x10 (`0x014cb4: ldr x8, [x0, #0x10]`)
    char*                filename;               // +0x18
    int32_t              flags;                  // +0x20
    int32_t              max_packet_size;        // +0x24
    int32_t              is_streamed;            // +0x28
    int32_t              is_connected;           // +0x2c
    AVNetIOInterruptCB   interrupt_callback;     // +0x30..0x3f
    int64_t              rw_timeout;             // +0x40
    const char*          protocol_whitelist;     // +0x48
    const char*          protocol_blacklist;     // +0x50
    VcnNetInfoCallbackFn net_info_callback;      // +0x58 (`0x0123d4: ldr x4, [x0, #0x58]`)
    int64_t              log_handle;             // +0x60
    int64_t              wrapper_handle;         // +0x68
};

/**
 * @brief `VCNHttpContext` (`0x2ad0 = 10,960 bytes`) allocated by `createHttpContext` (`0x028e74..0x028f90`)
 *        Cấu trúc ngữ cảnh `VCNHttpContext` (`10,960 bytes`) khởi tạo tại `createHttpContext` (`0x028e74`)
 */
struct VCNHttpContext {
    VCNURLContext* hd;                           // +0x0000 (`0x028c90: ldr x8, [x8]`)
    int32_t        seekable;                     // +0x0008 (`0x028edc: mov w8, #3; str w8, [x19, #8]`)
    int32_t        http_code;                    // +0x000c
    char           line_buffer[0x2090];          // +0x0010..0x209f
    int64_t        off;                          // +0x20a0
    int64_t        end_off;                      // +0x20a8
    int64_t        content_range_off;            // +0x20b0 (`0x026234: str x0, [x19, #0x20b0]`)
    int64_t        filesize;                     // +0x20b8 (`0x026264: str x8, [x19, #0x20b8]`)
    uint8_t        reserved_20c0[0x0030];        // +0x20c0..0x20ef
    int32_t        buf_len;                      // +0x20f0 (`0x028f04: str wzr, [x19, #0x20f0]`)
    uint8_t        reserved_20f4[0x06e8];        // +0x20f4..0x27db
    int32_t        multiple_requests;            // +0x27dc (`0x028f0c: mov w9, #-1; str w9, [x19, #0x27dc]`)
    int32_t        is_chunked_range;             // +0x27e0 (`0x02628c: str wzr, [x19, #0x27e0]`)
    int32_t        rw_flag_27e4;                 // +0x27e4 (`0x028ee4: mov w8, #1; str w8, [x19, #0x27e4]`)
    int64_t        pad_27e8;                     // +0x27e8
    int32_t        flag_27f0;                    // +0x27f0 (`0x028f00: str wzr, [x19, #0x27f0]`)
    int32_t        pad_27f4;                     // +0x27f4
    int64_t        ptr_27f8;                     // +0x27f8 (`0x028f50: str xzr, [x19, #0x27f8]`)
    uint8_t        reserved_2800[0x0020];        // +0x2800..0x281f
    int32_t        send_expect_100;              // +0x2820 (`0x028ee8: mov w8, #1; str w8, [x19, #0x2820]`)
    uint8_t        reserved_2824[0x00b4];        // +0x2824..0x28d7
    int32_t        is_connected_flag;            // +0x28d8 (`0x028f08: str wzr, [x19, #0x28d8]`)
    uint8_t        reserved_28dc[0x0020];        // +0x28dc..0x28fb
    int32_t        timeout_sec;                  // +0x28fc (`0x028f1c: 120` from `.rodata 0x02a290`)
    int32_t        timeout_extra;                // +0x2900 (`0` from `.rodata 0x02a290`)
    uint8_t        reserved_2904[0x000c];        // +0x2904..0x290f
    int32_t        reply_code;                   // +0x2910 (`0x028f28: mov w8, #0xc8 (200); str w8, [x19, #0x2910]`)
    uint8_t        reserved_2914[0x000c];        // +0x2914..0x291f
    int32_t        is_redirect;                  // +0x2920 (`0x028f34: 1` from `.rodata 0x02a298`)
    int32_t        reconnect_count;              // +0x2924 (`0` from `.rodata 0x02a298`)
    int32_t        reconnect_delay_max;          // +0x2928 (`0x028f30: mov w8, #5; str w8, [x19, #0x2928]`)
    uint8_t        reserved_292c[0x00e4];        // +0x292c..0x2a0f
    int32_t        max_range_0;                  // +0x2a10 (`0x028f38: 0x7fffffff` via `mvni v1.2s, #0x80, lsl #24`)
    int32_t        max_range_1;                  // +0x2a14 (`0x7fffffff`)
    int32_t        flag_2a18;                    // +0x2a18 (`0x028f4c: str wzr, [x19, #0x2a18]`)
    uint8_t        reserved_2a1c[0x008c];        // +0x2a1c..0x2aa7
    int32_t        socket_fd_override;           // +0x2aa8 (`0x028f68: mov w9, #-1; str w9, [x19, #0x2aa8]`)
    uint8_t        reserved_2aac[0x0024];        // +0x2aac..0x2acf
};
static_assert(sizeof(VCNHttpContext) == 0x2AD0, "VCNHttpContext must be 0x2ad0 (10,960) bytes on AArch64");

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com

#endif  // NEXTAI_OPENCUT_VCN_TYPES_H_
