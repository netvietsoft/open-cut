// ============================================================================
// RECONSTRUCTED C++ HEADER: speechepg_types.h
// Target Library: libspeechepg.so (18,256 bytes, ELF64 AArch64)
// Module: ByteDance SpeechPluginBridge JNI & Listener ABI Types
// Reference Evidence:
//   - .dynsym:       vaddr 0x000450 .. 0x000978 (size 0x000528 = 1,320 bytes, 55 entries)
//   - .dynstr:       vaddr 0x000978 .. 0x001564 (size 0x000bec = 3,052 bytes)
//   - .rela.dyn:     vaddr 0x0015f8 .. 0x001730 (size 0x000138 = 312 bytes, 13 relocs)
//   - .rela.plt:     vaddr 0x001730 .. 0x001a48 (size 0x000318 = 792 bytes, 33 relocs)
//   - .plt:          vaddr 0x001a50 .. 0x001c80 (size 0x000230 = 560 bytes)
//   - .text:         vaddr 0x001c80 .. 0x003248 (size 0x0015c8 = 5,576 bytes)
//   - .rodata:       vaddr 0x003248 .. 0x0034de (size 0x000296 = 662 bytes)
//   - .fini_array:   vaddr 0x007c00 .. 0x007c10 (size 0x000010 = 16 bytes: 0x1c90, 0x1c80)
//   - .data.rel.ro:  vaddr 0x007c10 .. 0x007c40 (size 0x000030 = 48 bytes)
//   - .dynamic:      vaddr 0x007c40 .. 0x007ea0 (size 0x000260 = 608 bytes)
//   - .got:          vaddr 0x007ea0 .. 0x008000 (size 0x000160 = 352 bytes)
//   - .bss:          vaddr 0x008000 .. 0x008010 (size 0x000010 = 16 bytes)
// ============================================================================
// Tệp tiêu đề định nghĩa cấu trúc ABI, hằng số hình học ELF64, địa chỉ opcodes
// AArch64, bảng phương thức ảo (vtable tại `0x007c18`) của `SpeechPluginListener`
// và kiểu dữ liệu lõi của cầu nối plugin `SpeechPluginBridge` trong `libspeechepg.so`.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <unordered_map>

namespace lab::speech::client {

// ============================================================================
// 1. ELF64 BINARY GEOMETRY & SECTION LAYOUT CONSTANTS
// Hằng số cấu trúc phân đoạn nhị phân ELF64 của libspeechepg.so (18,256 bytes)
// ============================================================================
struct SpeechEpgElf64Geometry {
    static constexpr uint64_t kFileSizeBytes         = 18256ULL;  // 0x004750 bytes
    static constexpr uint32_t kDynsymTotalEntries    = 55U;       // [000]..[054] in .dynsym (0x000450)
    static constexpr uint32_t kNonNullSymbolCount    = 52U;       // 34 imported + 18 exported
    static constexpr uint32_t kImportedSymbolCount   = 34U;       // [003]..[036] SHN_UNDEF
    static constexpr uint32_t kExportedSymbolCount   = 18U;       // [037]..[054] defined in .text

    // Section virtual addresses / Địa chỉ ảo các phân đoạn ELF64
    static constexpr uint64_t kSecDynsymVaddr        = 0x000450ULL; // size 0x000528 (1,320 B)
    static constexpr uint64_t kSecDynstrVaddr        = 0x000978ULL; // size 0x000bec (3,052 B)
    static constexpr uint64_t kSecRelaDynVaddr       = 0x0015f8ULL; // size 0x000138 (312 B, 13 relocs)
    static constexpr uint64_t kSecRelaPltVaddr       = 0x001730ULL; // size 0x000318 (792 B, 33 relocs)
    static constexpr uint64_t kSecPltVaddr           = 0x001a50ULL; // size 0x000230 (560 B)
    static constexpr uint64_t kSecTextVaddr          = 0x001c80ULL; // size 0x0015c8 (5,576 B)
    static constexpr uint64_t kSecTextEndVaddr       = 0x003248ULL;
    static constexpr uint64_t kSecRodataVaddr        = 0x003248ULL; // size 0x000296 (662 B)
    static constexpr uint64_t kSecRodataEndVaddr     = 0x0034deULL;
    static constexpr uint64_t kSecEhFrameHdrVaddr    = 0x0034e0ULL; // size 0x00010c (268 B)
    static constexpr uint64_t kSecEhFrameVaddr       = 0x0035f0ULL; // size 0x000460 (1,120 B)
    static constexpr uint64_t kSecFiniArrayVaddr     = 0x007c00ULL; // size 0x000010 (16 B: 0x1c90, 0x1c80)
    static constexpr uint64_t kSecDataRelRoVaddr     = 0x007c10ULL; // size 0x000030 (48 B)
    static constexpr uint64_t kSecDynamicVaddr       = 0x007c40ULL; // size 0x000260 (608 B)
    static constexpr uint64_t kSecGotVaddr           = 0x007ea0ULL; // size 0x000160 (352 B)
    static constexpr uint64_t kSecBssVaddr           = 0x008000ULL; // size 0x000010 (16 B)
};

// ============================================================================
// 2. EXPORTED SYMBOL VIRTUAL ADDRESSES (.dynsym [037]..[054])
// Địa chỉ ảo chính xác của toàn bộ 18 hàm xuất xưởng (.dynsym [037]..[054])
// ============================================================================
struct SpeechEpgExportedVaddrs {
    // [037] SpeechPluginBridge_resetEngineToNative
    static constexpr uint64_t kPlugin_resetEngineToNative          = 0x002f78ULL; // size 68 B
    // [038] SpeechPluginBridge_setOptionDoubleToNative
    static constexpr uint64_t kPlugin_setOptionDoubleToNative      = 0x002b80ULL; // size 308 B
    // [039] SpeechPluginBridge_initEngineToNative
    static constexpr uint64_t kPlugin_initEngineToNative           = 0x002cb4ULL; // size 196 B
    // [040] SpeechPluginBridge_sendDirectiveToNative
    static constexpr uint64_t kPlugin_sendDirectiveToNative        = 0x002d78ULL; // size 344 B
    // [041] SpeechPluginBridge_setOptionIntToNative
    static constexpr uint64_t kPlugin_setOptionIntToNative         = 0x002a4cULL; // size 308 B
    // [042] SpeechLogTracker_getInstanceToNative
    static constexpr uint64_t kLogTracker_getInstanceToNative      = 0x0023dcULL; // size 8 B
    // [043] SpeechPluginBridge_getVersionToNative
    static constexpr uint64_t kPlugin_getVersionToNative           = 0x0023e8ULL; // size 148 B
    // [044] SpeechPluginBridge_isEngineSupportedToNative
    static constexpr uint64_t kPlugin_isEngineSupportedToNative    = 0x00247cULL; // size 100 B
    // [045] SpeechPluginBridge_fetchResultToNative
    static constexpr uint64_t kPlugin_fetchResultToNative          = 0x003070ULL; // size 284 B
    // [046] JNI_OnLoad
    static constexpr uint64_t kJNI_OnLoad                          = 0x001f00ULL; // size 128 B
    // [047] SpeechPluginBridge_setOptionStringToNative
    static constexpr uint64_t kPlugin_setOptionStringToNative      = 0x002728ULL; // size 488 B
    // [048] SpeechPluginBridge_destroyEngineToNative
    static constexpr uint64_t kPlugin_destroyEngineToNative        = 0x0026b0ULL; // size 120 B
    // [049] SpeechPluginBridge_fetchStringResultToNative
    static constexpr uint64_t kPlugin_fetchStringResultToNative    = 0x00318cULL; // size 188 B
    // [050] SpeechPluginBridge_createEngineToNative
    static constexpr uint64_t kPlugin_createEngineToNative         = 0x0024e0ULL; // size 464 B
    // [051] SpeechPluginBridge_feedAudioToNative
    static constexpr uint64_t kPlugin_feedAudioToNative            = 0x002ed0ULL; // size 168 B
    // [052] SpeechLogTracker_writeLogToNative
    static constexpr uint64_t kLogTracker_writeLogToNative         = 0x0023e4ULL; // size 4 B
    // [053] SpeechPluginBridge_setOptionBooleanToNative
    static constexpr uint64_t kPlugin_setOptionBooleanToNative     = 0x002910ULL; // size 316 B
    // [054] SpeechPluginBridge_processAudioToNative
    static constexpr uint64_t kPlugin_processAudioToNative         = 0x002fbcULL; // size 180 B
};

// ============================================================================
// 3. INTERNAL .TEXT SUBROUTINE, .PLT, .DATA.REL.RO & .BSS OFFSETS
// Địa chỉ hàm nội bộ trong .text, bảng .plt, vtable .data.rel.ro và biến .bss
// ============================================================================
struct SpeechEpgInternalVaddrs {
    // .plt trampolines (0x001a70..0x001c70)
    static constexpr uint64_t kPlt_operator_new_nothrow            = 0x001a70ULL;
    static constexpr uint64_t kPlt_Options_Ctor                    = 0x001a80ULL;
    static constexpr uint64_t kPlt_Options_SetOption_Double        = 0x001a90ULL;
    static constexpr uint64_t kPlt_cxa_atexit                      = 0x001aa0ULL;
    static constexpr uint64_t kPlt_operator_new                    = 0x001ab0ULL;
    static constexpr uint64_t kPlt_Engine_GetVersion               = 0x001ac0ULL;
    static constexpr uint64_t kPlt_Engine_Init                     = 0x001ad0ULL;
    static constexpr uint64_t kPlt_stack_chk_fail                  = 0x001ae0ULL;
    static constexpr uint64_t kPlt_licbag_set_java_vm              = 0x001af0ULL;
    static constexpr uint64_t kPlt_operator_delete                 = 0x001b00ULL;
    static constexpr uint64_t kPlt_Engine_SendDirective            = 0x001b10ULL;
    static constexpr uint64_t kPlt_Options_SetOption_String        = 0x001b20ULL;
    static constexpr uint64_t kPlt_Engine_IsEngineSupported        = 0x001b30ULL;
    static constexpr uint64_t kPlt_Engine_Ctor                     = 0x001b40ULL;
    static constexpr uint64_t kPlt_android_log_print               = 0x001b50ULL;
    static constexpr uint64_t kPlt_Engine_Process                  = 0x001b60ULL;
    static constexpr uint64_t kPlt_Options_SetOption_Int           = 0x001b70ULL;
    static constexpr uint64_t kPlt_DefaultOptions                  = 0x001b80ULL;
    static constexpr uint64_t kPlt_Engine_AddListener              = 0x001b90ULL;
    static constexpr uint64_t kPlt_Options_IsValid                 = 0x001ba0ULL;
    static constexpr uint64_t kPlt_Engine_Dtor                     = 0x001bb0ULL;
    static constexpr uint64_t kPlt_cxa_finalize                    = 0x001bc0ULL;
    static constexpr uint64_t kPlt_Options_SetOption_Bool          = 0x001bd0ULL;
    static constexpr uint64_t kPlt_abort                           = 0x001be0ULL;
    static constexpr uint64_t kPlt_JNI_SetAssetManager             = 0x001bf0ULL;
    static constexpr uint64_t kPlt_EngineResult_ToString           = 0x001c00ULL;
    static constexpr uint64_t kPlt_Engine_Reset                    = 0x001c10ULL;
    static constexpr uint64_t kPlt_memcpy                          = 0x001c20ULL;
    static constexpr uint64_t kPlt_JNI_OnLoad_UUID                 = 0x001c30ULL;
    static constexpr uint64_t kPlt_Engine_Feed                     = 0x001c40ULL;
    static constexpr uint64_t kPlt_Engine_FetchResult              = 0x001c50ULL;
    static constexpr uint64_t kPlt_strlen                          = 0x001c60ULL;
    static constexpr uint64_t kPlt_Options_Dtor                    = 0x001c70ULL;

    // Internal .text functions (0x001c80..0x0023dc)
    static constexpr uint64_t kSub_CxaFinalizeThunk                = 0x001c80ULL;
    static constexpr uint64_t kSub_FiniNoop                        = 0x001c8cULL;
    static constexpr uint64_t kSub_JniEnvironment_SetJavaVM        = 0x001cbcULL;
    static constexpr uint64_t kSub_JniEnvironment_GetJavaVM        = 0x001cccULL;
    static constexpr uint64_t kSub_JniEnvironment_GetEnvOnce       = 0x001cdcULL;
    static constexpr uint64_t kSub_JniEnvironment_DetachOnce       = 0x001db4ULL;
    static constexpr uint64_t kSub_JniCallbackEnv_Ctor             = 0x001df0ULL;
    static constexpr uint64_t kSub_JniCallbackEnv_Dtor             = 0x001dfcULL;
    static constexpr uint64_t kSub_JniCallbackEnv_GetCallbackEnv   = 0x001e00ULL;
    static constexpr uint64_t kSub_JniCallbackEnv_DetachCallback   = 0x001e8cULL;
    static constexpr uint64_t kSub_Listener_Ctor                   = 0x001f80ULL;
    static constexpr uint64_t kSub_Listener_Dtor_D1Ev              = 0x001fa0ULL;
    static constexpr uint64_t kSub_Listener_Dtor_D0Ev              = 0x002058ULL;
    static constexpr uint64_t kSub_Listener_InitCallbackObject     = 0x002118ULL;
    static constexpr uint64_t kSub_Listener_OnMessage              = 0x002248ULL;
    static constexpr uint64_t kSub_JNIEnv_CallVoidMethod           = 0x002340ULL;

    // .data.rel.ro & .bss addresses
    static constexpr uint64_t kDataRelRo_DsoHandle                 = 0x007c10ULL;
    static constexpr uint64_t kDataRelRo_ListenerVtable            = 0x007c18ULL; // 5 pointers (40 B)
    static constexpr uint64_t kDataRelRo_ListenerVptr              = 0x007c28ULL; // +0x10 inside vtable
    static constexpr uint64_t kBss_JavaVM                          = 0x008000ULL; // via GOT 0x007fe8
    static constexpr uint64_t kBss_LicbagJavaVM                    = 0x008008ULL; // via GOT 0x007fc8
};

// ============================================================================
// 4. PROTOCOL CONSTANTS, MESSAGE TYPES & ERROR CODES
// Hằng số giao thức, mã thông điệp và mã lỗi quan sát từ hợp ngữ AArch64
// ============================================================================
struct SpeechEpgConstants {
    static constexpr const char* kLogTag                           = "speechengine"; // .rodata 0x003248
    static constexpr int32_t     kJniVersion1_6                    = 0x00010006;     // 0x001d24, 0x001f70
    static constexpr int64_t     kInvalidEngineHandle              = -1LL;           // 0x0023dc, 0x002698
    static constexpr int32_t     kErrSuccess                       = 0;
    static constexpr int32_t     kErrInvalidArgument               = -1;             // 0x0021d8
    static constexpr int32_t     kErrBufferTooSmall                = -1801;          // -0x709 @ 0x003130
    static constexpr int32_t     kMessageTypeEngineStart           = 1001;           // 0x03e9
    static constexpr int32_t     kMessageTypeEngineStop            = 1002;           // 0x03ea @ 0x00230c
    static constexpr int32_t     kMessageTypePartialResult         = 1003;           // 0x03eb
    static constexpr int32_t     kMessageTypeFinalResult           = 1004;           // 0x03ec
    static constexpr int32_t     kDirectiveStartEngine             = 1000;
    static constexpr int32_t     kDirectiveStopEngine              = 1001;
    static constexpr int32_t     kDirectiveCancelEngine            = 1002;
    static constexpr int32_t     kDirectiveSyncStopEngine          = 1003;
};

} // namespace lab::speech::client
