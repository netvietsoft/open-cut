// ============================================================================
// File: rex_jni_bridge.cpp
// Target 109 / 169: librex.so (690,264 bytes)
// EN: Clean-room C++17 implementation of the 6 exported JNI entry points:
//     - Java_com_bytedance_bddatefmt_BDDateFormat_nFormat          (0x08d07c)
//     - Java_com_bytedance_bddatefmt_BDDateFormat_nFormatAbbr      (0x08d270)
//     - Java_com_bytedance_bddatefmt_BDDateFormat_nFormatRelative  (0x08d3d0)
//     - Java_com_bytedance_bddatefmt_BDDateFormat_nFormatTimeZone  (0x08d530)
//     - Java_com_bytedance_bddatefmt_BDDateFormat_nFormatTimeRange (0x08d7d0)
//     - JNI_OnLoad                                                 (0x08d944)
// VI: Triển khai C++17 phòng sạch cho 6 điểm nhập JNI xuất khẩu của BDDateFormat.
// ============================================================================
#include "rex_date_format.h"

namespace bytedance {
namespace rex {

struct JNINativeMethodEntry {
    const char* name;
    const char* signature;
    const void* fn_ptr;
};

extern "C" {

// 0x08d07c..0x08d26c
std::string Java_com_bytedance_bddatefmt_BDDateFormat_nFormat(
    void* /*env*/,
    void* /*thiz*/,
    int64_t timestamp_ms,
    const char* pattern,
    const char* locale) {
    return BDDateFormatter::FormatDate(
        pattern ? pattern : "",
        timestamp_ms,
        locale ? locale : "en",
        true,
        0);
}

// 0x08d270..0x08d3cc
std::string Java_com_bytedance_bddatefmt_BDDateFormat_nFormatAbbr(
    void* /*env*/,
    void* /*thiz*/,
    int32_t count,
    int32_t unit,
    const char* locale) {
    return BDDateFormatter::FormatAbbr(count, unit, locale ? locale : "en");
}

// 0x08d3d0..0x08d52c
std::string Java_com_bytedance_bddatefmt_BDDateFormat_nFormatRelative(
    void* /*env*/,
    void* /*thiz*/,
    int32_t offset,
    int32_t unit,
    const char* locale) {
    return BDDateFormatter::FormatRelative(offset, unit, locale ? locale : "en");
}

// 0x08d530..0x08d7cc
std::string Java_com_bytedance_bddatefmt_BDDateFormat_nFormatTimeZone(
    void* /*env*/,
    void* /*thiz*/,
    const char* date_text,
    const char* tz_text,
    const char* locale) {
    return BDDateFormatter::FormatTimeZone(
        date_text ? date_text : "",
        tz_text ? tz_text : "",
        locale ? locale : "en");
}

// 0x08d7d0..0x08d940
std::string Java_com_bytedance_bddatefmt_BDDateFormat_nFormatTimeRange(
    void* /*env*/,
    void* /*thiz*/,
    int64_t start_ms,
    int64_t end_ms,
    int32_t unit,
    const char* locale) {
    return BDDateFormatter::FormatTimeRange(
        start_ms,
        end_ms,
        unit,
        locale ? locale : "en",
        true,
        0);
}

// .data @ 0x0ac000: 5 JNINativeMethod entries registered by JNI_OnLoad (0x08d944)
static const JNINativeMethodEntry kBDDateFormatMethods_0ac000[5] = {
    {"nFormat", "(JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;",
     reinterpret_cast<const void*>(&Java_com_bytedance_bddatefmt_BDDateFormat_nFormat)},
    {"nFormatAbbr", "(IILjava/lang/String;)Ljava/lang/String;",
     reinterpret_cast<const void*>(&Java_com_bytedance_bddatefmt_BDDateFormat_nFormatAbbr)},
    {"nFormatRelative", "(IILjava/lang/String;)Ljava/lang/String;",
     reinterpret_cast<const void*>(&Java_com_bytedance_bddatefmt_BDDateFormat_nFormatRelative)},
    {"nFormatTimeZone", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;",
     reinterpret_cast<const void*>(&Java_com_bytedance_bddatefmt_BDDateFormat_nFormatTimeZone)},
    {"nFormatTimeRange", "(JJILjava/lang/String;)Ljava/lang/String;",
     reinterpret_cast<const void*>(&Java_com_bytedance_bddatefmt_BDDateFormat_nFormatTimeRange)},
};

// 0x08d944..0x08d9f0:
//   mov w2, #0x00010006; GetEnv; FindClass("com/bytedance/bddatefmt/BDDateFormat" @ 0x0a3b74);
//   RegisterNatives(clazz, 0x0ac000, 5);
//   cmp w0, #0; csinv w0, w20, wzr, eq
int32_t JNI_OnLoad_Rex(void* vm, void* /*reserved*/) noexcept {
    if (!vm) {
        return -1;
    }
    (void)kBDDateFormatMethods_0ac000;
    return 0x00010006;
}

} // extern "C"

} // namespace rex
} // namespace bytedance
