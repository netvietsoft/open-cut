/**
 * @file PitayaBdComponent_pseudocode.cpp
 * @brief Clean-Room Exported Symbol Registry & Disassembly Dispatch Table for libPitayaBdComponent.so (Target 46).
 *        Bảng đăng ký ký hiệu xuất khẩu phòng sạch & Bảng điều phối hợp ngữ cho libPitayaBdComponent.so (Mục tiêu 46).
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - File: extracted/lib/arm64-v8a/libPitayaBdComponent.so (100,176 bytes, ELF64 AArch64)
 * - Exported Functions (3):
 *   1. 0x002780 (132 B): Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack
 *   2. 0x002898 (488 B): _ZN6pitaya14PitayaNpthUtil16GenerteTombstoneENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
 *   3. 0x004c54 (340 B): Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr
 * - Exported VTable Objects (4):
 *   4. 0x01b5c0 ( 80 B): _ZTVNSt6__ndk119basic_istringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEEE
 *   5. 0x01b610 ( 80 B): _ZTCNSt6__ndk119basic_istringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEEE0_NS_13basic_istreamIcS2_EE
 *   6. 0x01b660 (128 B): _ZTVNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEEE
 *   7. 0x01b6e0 (128 B): _ZTVNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEE
 */

#include "PitayaBdComponent_interface.h"

namespace NextAI {
namespace OpenCut {
namespace PitayaBdComponent {

struct ExportedSymbolDescriptor {
    uint64_t vaddr;
    uint32_t size_bytes;
    const char* mangled_name;
    const char* demangled_name;
};

static constexpr ExportedSymbolDescriptor kPitayaBdComponentExportTable[] = {
    {
        0x002780ULL,
        132U,
        "Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack",
        "Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack(JNIEnv*, jobject, jstring)"
    },
    {
        0x002898ULL,
        488U,
        "_ZN6pitaya14PitayaNpthUtil16GenerteTombstoneENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE",
        "pitaya::PitayaNpthUtil::GenerteTombstone(std::__ndk1::basic_string<char>)"
    },
    {
        0x004c54ULL,
        340U,
        "Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr",
        "Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr(JNIEnv*, jobject)"
    },
    {
        0x01b5c0ULL,
        80U,
        "_ZTVNSt6__ndk119basic_istringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEEE",
        "vtable for std::__ndk1::basic_istringstream<char>"
    },
    {
        0x01b610ULL,
        80U,
        "_ZTCNSt6__ndk119basic_istringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEEE0_NS_13basic_istreamIcS2_EE",
        "construction vtable for std::__ndk1::basic_istream<char>-in-std::__ndk1::basic_istringstream<char>"
    },
    {
        0x01b660ULL,
        128U,
        "_ZTVNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEEE",
        "vtable for std::__ndk1::basic_stringbuf<char>"
    },
    {
        0x01b6e0ULL,
        128U,
        "_ZTVNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEE",
        "vtable for std::__ndk1::basic_streambuf<char>"
    }
};

const ExportedSymbolDescriptor* GetPitayaBdComponentExportTable(size_t* out_count) noexcept {
    if (out_count != nullptr) {
        *out_count = sizeof(kPitayaBdComponentExportTable) / sizeof(kPitayaBdComponentExportTable[0]);
    }
    return kPitayaBdComponentExportTable;
}

}  // namespace PitayaBdComponent
}  // namespace OpenCut
}  // namespace NextAI
