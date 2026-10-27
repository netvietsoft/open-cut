/**
 * @file vcn_interface.h
 * @brief Top-Level Public C/C++ Interface for Reconstructed libvcn.so (ByteDance MediaKit VCN Engine).
 *        Giao diện C/C++ công khai cấp cao cho thư viện tái tạo sạch libvcn.so (ByteDance MediaKit VCN Engine).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libvcn.so (214,960 bytes)
 *   SHA-256: b1060ae9e0451374c5f18ad95a777123d937c9c7e81c93b8bbe98618790af3e3
 *
 * Exported Symbols Summary / Tổng hợp các biểu tượng xuất (`.dynsym` = 120 defined symbols):
 *   1. 36 `vcn_av_*` String, Dictionary, Option, Memory, Error (66-entry `.data.rel.ro 0x035740`) & Time Exports (`0x008fbc..0x010508`)
 *   2. 21 `vcn_url_*`, `vcn_ff_*`, `vcn_tcp_*`, `vcn_tls_*` & Custom Verify Exports (`0x01050c..0x017244`)
 *   3. 14 `com::ss::mediakit::vcn::httpParser*` & `createHttpContext`/`releaseHttpContext` Exports (`0x01ddb0..0x029140`)
 *   4.  7 `com::ss::mediakit::vcn::VCNDNSParserInterface` Exports (`0x029144..0x029177`, vtable `.data.rel.ro 0x037730`)
 *   5. 14 `com::ss::mediakit::vcn::VCNSocketInfo` Exports (`0x029178..0x029a63`)
 *   6.  2 Top-Level C++ Helpers: `vcnUrlSplit` (`0x029a64`) & `vcnDoCustomVerify` (`0x02a1c4`)
 */

#ifndef NEXTAI_OPENCUT_VCN_INTERFACE_H_
#define NEXTAI_OPENCUT_VCN_INTERFACE_H_

#include "vcn_av_utils.h"
#include "vcn_http_socket_dns.h"
#include "vcn_types.h"
#include "vcn_url_tcp_tls.h"

#include <cstdint>
#include <string>
#include <vector>

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

/**
 * @brief Symbol Descriptor for the 94 Exported Function Symbols of `libvcn.so` (`0x008fbc..0x02a1c4`).
 *        Cấu trúc mô tả danh mục 94 biểu tượng hàm xuất của `libvcn.so` (`0x008fbc..0x02a1c4`).
 */
struct VcnExportedSymbolDescriptor {
    uint32_t    va;
    uint32_t    size_bytes;
    const char* mangled_name;
    const char* demangled_signature;
    const char* subsystem;
};

/**
 * @brief Returns the complete catalog of exported functions from `.dynsym` of `libvcn.so`.
 *        Trả về danh mục đầy đủ các hàm xuất từ `.dynsym` của `libvcn.so`.
 */
const std::vector<VcnExportedSymbolDescriptor>& GetVcnExportedFunctionCatalog() noexcept;

/**
 * @brief Runs an end-to-end self-test verifying all 6 subsystems of `libvcn.so`:
 *        - `vcn_av_*` string/dict/malloc/strerror (66 error entries) & `vcn_av_timegm` Gregorian math
 *        - `vcn_url_*`, `vcn_tcp_get_ip_addr`, `vcn_tls_get_ip_addr` & 4 `URLProtocol` descriptors
 *        - `httpParserHttpAVError` (`0x1B` bitmask + `.rodata 0x02e330` table) & `httpParserParseContentRange`
 *        - `createHttpContext` (`0x2ad0 = 10,960 B`) & `httpParserGetfileHandle` / `httpParserGetShortSeek`
 *        - `VCNDNSParserInterface`, `VCNSocketInfo` (`0x70 = 112 B`), `vcnUrlSplit` & `vcnDoCustomVerify`
 *        Chạy kiểm thử tự động toàn trình xác minh toàn bộ 6 phân hệ của `libvcn.so`.
 */
bool RunVcnSelfTest(std::string* out_diagnostic_report) noexcept;

}  // namespace vcn
}  // namespace mediakit
}  // namespace ss
}  // namespace com

#endif  // NEXTAI_OPENCUT_VCN_INTERFACE_H_
