// ============================================================================
// RECONSTRUCTED C++ HEADER: speechengine_types.h
// Target Library: libspeechengine.so (18,256 bytes, ELF64 AArch64)
// Module: ByteDance SpeechEngine JNI Bridge & Listener ABI Types
// Reference Evidence:
//   - .dynsym:       vaddr 0x000450 .. 0x000978 (size 0x000528 = 1,320 bytes, 55 entries)
//   - .dynstr:       vaddr 0x000978 .. 0x001558 (size 0x000be0 = 3,040 bytes)
//   - .rela.dyn:     vaddr 0x0015e8 .. 0x001720 (size 0x000138 = 312 bytes, 13 relocs)
//   - .rela.plt:     vaddr 0x001720 .. 0x001a38 (size 0x000318 = 792 bytes, 33 relocs)
//   - .plt:          vaddr 0x001a40 .. 0x001c70 (size 0x000230 = 560 bytes)
//   - .text:         vaddr 0x001c70 .. 0x003238 (size 0x0015c8 = 5,576 bytes)
//   - .rodata:       vaddr 0x003238 .. 0x0034ce (size 0x000296 = 662 bytes)
//   - .fini_array:   vaddr 0x007c10 .. 0x007c20 (size 0x000010 = 16 bytes)
//   - .data.rel.ro:  vaddr 0x007c20 .. 0x007c50 (size 0x000030 = 48 bytes)
//   - .got:          vaddr 0x007ea0 .. 0x008000 (size 0x000160 = 352 bytes)
//   - .bss:          vaddr 0x008000 .. 0x008010 (size 0x000010 = 16 bytes)
// ============================================================================
// Tệp tiêu đề định nghĩa cấu trúc ABI, hằng số ELF64, địa chỉ opcodes AArch64,
// bảng phương thức ảo (vtable) của `SpeechEngineListener` và kiểu dữ liệu lõi
// của cầu nối `SpeechEngineBridge` trong `libspeechengine.so`.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>

namespace lab::speech::client {

// ============================================================================
// 1. ELF64 BINARY GEOMETRY & SECTION LAYOUT CONSTANTS
// Hằng số cấu trúc phân đoạn nhị phân ELF64 của libspeechengine.so (18,256 bytes)
// ============================================================================
struct SpeechEngineElf64Geometry {
    static constexpr uint64_t kFileSizeBytes         = 18256ULL;  // 0x004750 bytes
    static constexpr uint32_t kDynsymTotalEntries    = 55U;       // [000]..[054] in .dynsym (0x000450)
    static constexpr uint32_t kNonNullSymbolCount    = 52U;       // 34 imported + 18 exported
    static constexpr uint32_t kImportedSymbolCount   = 34U;       // [003]..[036] SHN_UNDEF
    static constexpr uint32_t kExportedSymbolCount   = 18U;       // [037]..[054] defined in .text

    // Section virtual addresses / Địa chỉ ảo các phân đoạn ELF64
    static constexpr uint64_t kSecDynsymVaddr        = 0x000450ULL; // size 0x000528 (1,320 B)
    static constexpr uint64_t kSecDynstrVaddr        = 0x000978ULL; // size 0x000be0 (3,040 B)
    static constexpr uint64_t kSecRelaDynVaddr       = 0x0015e8ULL; // size 0x000138 (312 B, 13 relocs)
    static constexpr uint64_t kSecRelaPltVaddr       = 0x001720ULL; // size 0x000318 (792 B, 33 relocs)
    static constexpr uint64_t kSecPltVaddr           = 0x001a40ULL; // size 0x000230 (560 B)
    static constexpr uint64_t kSecTextVaddr          = 0x001c70ULL; // size 0x0015c8 (5,576 B)
    static constexpr uint64_t kSecTextEndVaddr       = 0x003238ULL;
    static constexpr uint64_t kSecRodataVaddr        = 0x003238ULL; // size 0x000296 (662 B)
    static constexpr uint64_t kSecRodataEndVaddr     = 0x0034ceULL;
    static constexpr uint64_t kSecEhFrameHdrVaddr    = 0x0034d0ULL; // size 0x00010c (268 B)
    static constexpr uint64_t kSecEhFrameVaddr       = 0x0035e0ULL; // size 0x000460 (1,120 B)
    static constexpr uint64_t kSecFiniArrayVaddr     = 0x007c10ULL; // size 0x000010 (16 B: 0x1c80, 0x1c70)
    static constexpr uint64_t kSecDataRelRoVaddr     = 0x007c20ULL; // size 0x000030 (48 B)
    static constexpr uint64_t kSecDynamicVaddr       = 0x007c50ULL; // size 0x000250 (592 B)
    static constexpr uint64_t kSecGotVaddr           = 0x007ea0ULL; // size 0x000160 (352 B)
    static constexpr uint64_t kSecBssVaddr           = 0x008000ULL; // size 0x000010 (16 B)
};

// ============================================================================
// 2. EXPORTED SYMBOL VIRTUAL ADDRESSES (.dynsym [037]..[054])
// Địa chỉ ảo chính xác của toàn bộ 18 hàm xuất xưởng (.dynsym [037]..[054])
// ============================================================================
struct SpeechEngineExportedVaddrs {
    // [037] SpeechEngineBridge_getVersionToNative
    static constexpr uint64_t kBridge_getVersionToNative           = 0x001f70ULL; // size 148 B
    // [038] SpeechEngineBridge_feedAudioToNative
    static constexpr uint64_t kBridge_feedAudioToNative            = 0x002a58ULL; // size 168 B
    // [039] SpeechEngineBridge_setOptionIntToNative
    static constexpr uint64_t kBridge_setOptionIntToNative         = 0x0025d4ULL; // size 308 B
    // [040] SpeechEngineBridge_fetchStringResultToNative
    static constexpr uint64_t kBridge_fetchStringResultToNative    = 0x002d14ULL; // size 188 B
    // [041] SpeechLogTracker_getInstanceToNative
    static constexpr uint64_t kLogTracker_getInstanceToNative      = 0x00322cULL; // size 8 B
    // [042] JNI_OnLoad
    static constexpr uint64_t kJNI_OnLoad                          = 0x001ef0ULL; // size 128 B
    // [043] SpeechEngineBridge_resetEngineToNative
    static constexpr uint64_t kBridge_resetEngineToNative          = 0x002b00ULL; // size 68 B
    // [044] SpeechEngineBridge_setOptionStringToNative
    static constexpr uint64_t kBridge_setOptionStringToNative      = 0x0022b0ULL; // size 488 B
    // [045] SpeechEngineBridge_destroyEngineToNative
    static constexpr uint64_t kBridge_destroyEngineToNative        = 0x002238ULL; // size 120 B
    // [046] SpeechEngineBridge_fetchResultToNative
    static constexpr uint64_t kBridge_fetchResultToNative          = 0x002bf8ULL; // size 284 B
    // [047] SpeechEngineBridge_createEngineToNative
    static constexpr uint64_t kBridge_createEngineToNative         = 0x002068ULL; // size 464 B
    // [048] SpeechEngineBridge_isEngineSupportedToNative
    static constexpr uint64_t kBridge_isEngineSupportedToNative    = 0x002004ULL; // size 100 B
    // [049] SpeechEngineBridge_processAudioToNative
    static constexpr uint64_t kBridge_processAudioToNative         = 0x002b44ULL; // size 180 B
    // [050] SpeechLogTracker_writeLogToNative
    static constexpr uint64_t kLogTracker_writeLogToNative         = 0x003234ULL; // size 4 B
    // [051] SpeechEngineBridge_setOptionBooleanToNative
    static constexpr uint64_t kBridge_setOptionBooleanToNative     = 0x002498ULL; // size 316 B
    // [052] SpeechEngineBridge_setOptionDoubleToNative
    static constexpr uint64_t kBridge_setOptionDoubleToNative      = 0x002708ULL; // size 308 B
    // [053] SpeechEngineBridge_initEngineToNative
    static constexpr uint64_t kBridge_initEngineToNative           = 0x00283cULL; // size 196 B
    // [054] SpeechEngineBridge_sendDirectiveToNative
    static constexpr uint64_t kBridge_sendDirectiveToNative        = 0x002900ULL; // size 344 B
};

// ============================================================================
// 3. INTERNAL .TEXT SUBROUTINE, .PLT, .DATA.REL.RO & .BSS OFFSETS
// Địa chỉ hàm nội bộ trong .text, bảng .plt, vtable .data.rel.ro và biến .bss
// ============================================================================
struct SpeechEngineInternalVaddrs {
    // .plt trampolines (0x001a60..0x001c60)
    static constexpr uint64_t kPlt_memcpy                          = 0x001a60ULL;
    static constexpr uint64_t kPlt_operator_delete                 = 0x001a70ULL;
    static constexpr uint64_t kPlt_operator_new_nothrow            = 0x001a80ULL;
    static constexpr uint64_t kPlt_Engine_SendDirective            = 0x001a90ULL;
    static constexpr uint64_t kPlt_Engine_Init                     = 0x001aa0ULL;
    static constexpr uint64_t kPlt_Engine_Reset                    = 0x001ab0ULL;
    static constexpr uint64_t kPlt_Engine_Dtor                     = 0x001ac0ULL;
    static constexpr uint64_t kPlt_strlen                          = 0x001ad0ULL;
    static constexpr uint64_t kPlt_Engine_GetVersion               = 0x001ae0ULL;
    static constexpr uint64_t kPlt_Engine_Process                  = 0x001af0ULL;
    static constexpr uint64_t kPlt_Options_Dtor                    = 0x001b00ULL;
    static constexpr uint64_t kPlt_EngineResult_ToString           = 0x001b10ULL;
    static constexpr uint64_t kPlt_Options_SetOption_Double        = 0x001b20ULL;
    static constexpr uint64_t kPlt_Options_SetOption_Bool          = 0x001b30ULL;
    static constexpr uint64_t kPlt_Engine_FetchResult              = 0x001b40ULL;
    static constexpr uint64_t kPlt_android_log_print               = 0x001b50ULL;
    static constexpr uint64_t kPlt_Options_Ctor                    = 0x001b60ULL;
    static constexpr uint64_t kPlt_Engine_IsEngineSupported        = 0x001b70ULL;
    static constexpr uint64_t kPlt_JNI_SetAssetManager             = 0x001b80ULL;
    static constexpr uint64_t kPlt_DefaultOptions                  = 0x001b90ULL;
    static constexpr uint64_t kPlt_abort                           = 0x001ba0ULL;
    static constexpr uint64_t kPlt_cxa_atexit                      = 0x001bb0ULL;
    static constexpr uint64_t kPlt_Engine_AddListener              = 0x001bc0ULL;
    static constexpr uint64_t kPlt_JNI_OnLoad_UUID                 = 0x001bd0ULL;
    static constexpr uint64_t kPlt_operator_new                    = 0x001be0ULL;
    static constexpr uint64_t kPlt_cxa_finalize                    = 0x001bf0ULL;
    static constexpr uint64_t kPlt_stack_chk_fail                  = 0x001c00ULL;
    static constexpr uint64_t kPlt_Options_IsValid                 = 0x001c10ULL;
    static constexpr uint64_t kPlt_Options_SetOption_String        = 0x001c20ULL;
    static constexpr uint64_t kPlt_licbag_set_java_vm              = 0x001c30ULL;
    static constexpr uint64_t kPlt_Engine_Ctor                     = 0x001c40ULL;
    static constexpr uint64_t kPlt_Engine_Feed                     = 0x001c50ULL;
    static constexpr uint64_t kPlt_Options_SetOption_Int           = 0x001c60ULL;

    // Internal .text functions (0x001c70..0x003228)
    static constexpr uint64_t kSub_CxaFinalizeThunk                = 0x001c70ULL;
    static constexpr uint64_t kSub_FiniNoop                        = 0x001c7cULL;
    static constexpr uint64_t kSub_JniEnvironment_SetJavaVM        = 0x001cacULL;
    static constexpr uint64_t kSub_JniEnvironment_GetJavaVM        = 0x001cbcULL;
    static constexpr uint64_t kSub_JniEnvironment_GetEnvOnce       = 0x001cccULL;
    static constexpr uint64_t kSub_JniEnvironment_DetachOnce       = 0x001da4ULL;
    static constexpr uint64_t kSub_JniCallbackEnv_Ctor             = 0x001de0ULL;
    static constexpr uint64_t kSub_JniCallbackEnv_Dtor             = 0x001decULL;
    static constexpr uint64_t kSub_JniCallbackEnv_GetCallbackEnv   = 0x001df0ULL;
    static constexpr uint64_t kSub_JniCallbackEnv_DetachCallback   = 0x001e7cULL;
    static constexpr uint64_t kSub_Listener_Ctor                   = 0x002dd0ULL;
    static constexpr uint64_t kSub_Listener_Dtor_D1Ev              = 0x002df0ULL;
    static constexpr uint64_t kSub_Listener_Dtor_D0Ev              = 0x002ea8ULL;
    static constexpr uint64_t kSub_Listener_InitCallbackObject     = 0x002f68ULL;
    static constexpr uint64_t kSub_Listener_OnMessage              = 0x003098ULL;
    static constexpr uint64_t kSub_JNIEnv_CallVoidMethod           = 0x003190ULL;

    // .data.rel.ro & .bss addresses
    static constexpr uint64_t kDataRelRo_DsoHandle                 = 0x007c20ULL;
    static constexpr uint64_t kDataRelRo_ListenerVtable            = 0x007c28ULL; // 5 pointers (40 B)
    static constexpr uint64_t kDataRelRo_ListenerVptr              = 0x007c38ULL; // +0x10 inside vtable
    static constexpr uint64_t kBss_JavaVM                          = 0x008000ULL; // JavaVM* g_jvm
    static constexpr uint64_t kBss_LicbagJavaVM                    = 0x008008ULL; // JavaVM* g_licbag_jvm
};

// ============================================================================
// 4. PROTOCOL CONSTANTS, MESSAGE TYPES & ERROR CODES
// Hằng số giao thức, mã thông điệp và mã lỗi quan sát từ hợp ngữ AArch64
// ============================================================================
struct SpeechEngineConstants {
    static constexpr int32_t  kJniVersion1_6                       = 0x00010006; // 0x001d14, 0x001f60
    static constexpr int64_t  kInvalidEngineHandle                 = -1LL;       // 0x002220, 0x00322c
    static constexpr int32_t  kErrSuccess                          = 0;
    static constexpr int32_t  kErrInvalidArgument                  = -1;         // 0x003028
    static constexpr int32_t  kErrBufferTooSmall                   = -1801;      // -0x709 @ 0x002cb8
    static constexpr int32_t  kMessageTypeEngineStart              = 1001;       // 0x03e9
    static constexpr int32_t  kMessageTypeEngineStop               = 1002;       // 0x03ea @ 0x00315c
    static constexpr int32_t  kMessageTypePartialResult            = 1003;       // 0x03eb
    static constexpr int32_t  kMessageTypeFinalResult              = 1004;       // 0x03ec
    static constexpr int32_t  kDirectiveStartEngine                = 1000;
    static constexpr int32_t  kDirectiveStopEngine                 = 1001;
    static constexpr int32_t  kDirectiveCancelEngine               = 1002;
    static constexpr int32_t  kDirectiveSyncStopEngine             = 1003;
};

} // namespace lab::speech::client
