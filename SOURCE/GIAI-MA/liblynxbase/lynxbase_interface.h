// ============================================================================
// File: lynxbase_interface.h
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: Unified Public C++17 & C ABI Umbrella Header for `liblynxbase.so`
//            (326 defined STT_FUNC + 6 defined STT_OBJECT symbols)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Master public interface aggregating all headers of the clean-room C++17
//      reconstruction of `liblynxbase.so` (`lynxbase_types.h`,
//      `lynxbase_fml_loop.h`, `lynxbase_string_crypto.h`,
//      `lynxbase_jni_log_error.h`) and declaring diagnostic self-test entry points.
// [VN] Header giao diện công khai hợp nhất toàn bộ các module C++17 tái tạo sạch
//      của `liblynxbase.so` (`lynxbase_types.h`, `lynxbase_fml_loop.h`,
//      `lynxbase_string_crypto.h`, `lynxbase_jni_log_error.h`) và khai báo các
//      hàm tự kiểm thử đối chứng nhị phân.
// ============================================================================

#ifndef LYNXBASE_INTERFACE_H_
#define LYNXBASE_INTERFACE_H_

#include "lynxbase_types.h"
#include "lynxbase_fml_loop.h"
#include "lynxbase_string_crypto.h"
#include "lynxbase_jni_log_error.h"

namespace lynx {
namespace verification {

struct LynxBaseParityReport {
    uint32_t binary_size_bytes{232080};
    uint32_t defined_func_symbols{326};
    uint32_t defined_object_symbols{6};
    jint jni_onload_version{0};
    bool md5_rfc1321_passed{false};
    bool cityhash64_passed{false};
    bool data_uri_decode_passed{false};
    bool js_dtoa_passed{false};
    bool utf_conversion_passed{false};
    bool reciprocal_time_math_passed{false};
    bool fml_loop_and_queues_passed{false};
    bool lynx_error_and_logging_passed{false};

    bool AllPassed() const noexcept {
        return jni_onload_version == constants::kLynxBaseJniVersion &&
               md5_rfc1321_passed &&
               cityhash64_passed &&
               data_uri_decode_passed &&
               js_dtoa_passed &&
               utf_conversion_passed &&
               reciprocal_time_math_passed &&
               fml_loop_and_queues_passed &&
               lynx_error_and_logging_passed;
    }
};

LynxBaseParityReport RunLynxBaseParitySuite();

} // namespace verification
} // namespace lynx

#endif // LYNXBASE_INTERFACE_H_
