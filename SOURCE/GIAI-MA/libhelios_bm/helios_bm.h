// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libhelios_bm.so (18,424 bytes)
// SHA-256       : 79a0bb7b7d00a64fe4f0c0182d5416ab2515768f0262c23578d436c792a20e90
// Task ID       : TASK-174-RECONSTRUCTION-LIBHELIOS-BM
// Legacy Task   : TASK_SO_157_libhelios_bm
// Architecture  : AArch64 (ARM64-v8a) ELF64 Shared Library
// ============================================================================
// EN: Bilingual clean-room header for ByteDance Helios Binder Monitor
//     (`libhelios_bm.so`, .text 0x0b70..0x225c, 22 FDEs @ 0x2710,
//     1,467 AArch64 instructions, 2 exported symbols: `JNI_OnLoad` and
//     `_Z10nativeInitP7_JNIEnv`).
// VI: File header C++17 phòng sạch song ngữ cho Bộ Giám Sát Binder Helios
//     của ByteDance (`libhelios_bm.so`, .text 0x0b70..0x225c, 22 FDE @ 0x2710,
//     1.467 lệnh AArch64, 2 biểu tượng xuất khẩu: `JNI_OnLoad` và
//     `_Z10nativeInitP7_JNIEnv`).
// ============================================================================

#ifndef NEXTAI_OPENCUT_HELIOS_BM_H_
#define NEXTAI_OPENCUT_HELIOS_BM_H_

#include <cstddef>
#include <cstdint>
#include <string>

namespace nextai {
namespace opencut {
namespace helios_bm {

// EN: Constants verified directly from AArch64 opcodes in `libhelios_bm.so`:
//     - JNI_VERSION_1_6 (0x00010006) at 0x0db0..0x0db8, 0x0ff8..0x1000,
//       0x1120..0x1130, 0x1edc..0x1ef0 (`mov w2, #6; movk w2, #1, lsl #16`).
//     - Android SDK level thresholds:
//         * `sdk_int >= 30` (`0x1e` @ 0x0e1c, 0x0fbc, 0x0fe8, 0x16a8) for
//           `java/lang/reflect/Executable.getArtMethod()` / `Field.getArtField()`.
//         * `sdk_int >= 28` (`0x1c` @ 0x1f44) for `VMRuntime.setHiddenApiExemptions(["L"])`.
//     - Reflection cache struct allocation size: `0x128` (`296 bytes` @ 0x1170)
//       stored at `.bss 0x8050`.
//     - Global Helios state struct allocation size: `0x28` (`40 bytes` @ 0x1be8)
//       stored at `.bss 0x8058`.
// VI: Các hằng số xác minh trực tiếp từ mã máy AArch64 trong `libhelios_bm.so`.
constexpr int32_t  kHeliosJniVersion1_6          = 0x00010006;
constexpr int32_t  kAndroidSdkLevelP             = 28;     // 0x1c (0x1f44)
constexpr int32_t  kAndroidSdkLevelR             = 30;     // 0x1e (0x0e1c, 0x0fbc, 0x16a8)
constexpr size_t   kHeliosJniCacheStructSize     = 0x128U; // 296 bytes (0x1170)
constexpr size_t   kHeliosGlobalStateStructSize  = 0x28U;  // 40 bytes (0x1be8)

constexpr const char* kHeliosLogTag              = "Helios_BM";
constexpr const char* kThreadLocalLogTag         = "thread_local";
constexpr const char* kBinderEntryClassName      = "com/bytedance/helios/binder/BinderEntry";
constexpr const char* kBinderProxyClassName      = "android/os/BinderProxy";
constexpr const char* kTransactNative5Sig        = "(ILandroid/os/Parcel;Landroid/os/Parcel;I)Z";
constexpr const char* kTransactNative6Sig        = "(ILandroid/os/Parcel;Landroid/os/Parcel;ZI)Z";
constexpr const char* kBeforeTransactSig         = "(Ljava/lang/Object;ILandroid/os/Parcel;Landroid/os/Parcel;)Z";

// EN: Exact 40-byte (`0x28`) layout of `HeliosGlobalState` allocated in
//     FDE[15] (`0x1be0..0x1c0c`) and accessed via FDE[14] (`0x1bd4..0x1be0`):
//       +0x00: `void* java_vm`
//       +0x08: `uint8_t jni_offset_verified` (set to 1 at 0x1b04 when
//              `*(uintptr_t*)(art_method_reserved1 + jni_code_offset) == &HeliosReserved1Stub`)
//       +0x10: `size_t jni_code_offset` (verified byte offset inside `ArtMethod`
//              where the JNI native entrypoint pointer resides, stored at 0x1b08)
//       +0x18: `uint64_t reserved_18`
//       +0x20: `uint8_t is_art_vm` (set at 0x1b40 if `"persist.sys.dalvik.vm.lib"`
//              or `"persist.sys.dalvik.vm.lib.2"` contains `"libart"`)
//       +0x21: `uint8_t context_initialized` (set to 1 at 0x10e4)
// VI: Bố cục chính xác 40 byte (`0x28`) của `HeliosGlobalState` cấp phát tại
//     FDE[15] (`0x1be0..0x1c0c`).
struct HeliosGlobalState {
    void*    java_vm;              // +0x00
    uint8_t  jni_offset_verified;  // +0x08
    uint8_t  pad_09[7];
    size_t   jni_code_offset;      // +0x10
    uint64_t reserved_18;          // +0x18
    uint8_t  is_art_vm;            // +0x20
    uint8_t  context_initialized;  // +0x21
    uint8_t  pad_22[6];
};
static_assert(sizeof(HeliosGlobalState) == kHeliosGlobalStateStructSize,
              "HeliosGlobalState must be 0x28 (40) bytes");

// EN: Exact 296-byte (`0x128`) layout of `HeliosJniReflectionCache` allocated
//     in FDE[13] (`0x1170..0x11ac`) and stored at `.bss 0x8050`.
// VI: Bố cục chính xác 296 byte (`0x128`) của `HeliosJniReflectionCache` cấp phát
//     tại FDE[13] (`0x1170..0x11ac`).
struct HeliosJniReflectionCache {
    void*    class_cls;                    // +0x00: java/lang/Class
    void*    class_get_name_mid;           // +0x08: Class.getName()
    void*    class_get_decl_methods_mid;   // +0x10: Class.getDeclaredMethods()
    void*    class_get_decl_fields_mid;    // +0x18: Class.getDeclaredFields()
    void*    object_cls;                   // +0x20: java/lang/Object
    void*    object_to_string_mid;         // +0x28: Object.toString()
    void*    method_cls;                   // +0x30: java/lang/reflect/Method
    void*    method_get_decl_cls_mid;      // +0x38: Method.getDeclaringClass()
    void*    method_get_modifiers_mid;     // +0x40: Method.getModifiers()
    void*    method_get_return_type_mid;   // +0x48: Method.getReturnType()
    void*    method_get_name_mid;          // +0x50: Method.getName()
    void*    method_get_param_types_mid;   // +0x58: Method.getParameterTypes()
    void*    field_cls;                    // +0x60: java/lang/reflect/Field
    void*    field_get_name_mid;           // +0x68: Field.getName()
    void*    field_get_art_field_mid;      // +0x70: Field.getArtField() (API >= 30)
    void*    binder_proxy_cls;             // +0x78: android/os/BinderProxy
    void*    transact_native_mid;          // +0x80: BinderProxy.transactNative
    uint64_t reserved_88;                  // +0x88
    uint8_t  is_6arg_transact_native;      // +0x90: 1 if (ILandroid/os/Parcel;Landroid/os/Parcel;ZI)Z
    uint8_t  pad_91[119];                  // +0x91..+0x107
    void*    executable_cls;               // +0x108: java/lang/reflect/Executable (API >= 30)
    void*    executable_get_art_method;    // +0x110: Executable.getArtMethod() (API >= 30)
    void*    binder_entry_cls;             // +0x118: com/bytedance/helios/binder/BinderEntry
    void*    before_transact_mid;          // +0x120: BinderEntry.beforeTransact
};
static_assert(sizeof(HeliosJniReflectionCache) == kHeliosJniCacheStructSize,
              "HeliosJniReflectionCache must be 0x128 (296) bytes");

struct HeliosBmInsnRecord {
    uint32_t    va;
    uint32_t    opcode_word;
    const char* mnemonic;
    const char* operands;
    int32_t     fde_index;
};

extern const uint8_t            kHeliosBmRodata1202[1202];
extern const uint8_t            kHeliosBmEhFrame960[960];
extern const uint32_t           kHeliosBmPltWords64[64];
extern const uint32_t           kHeliosBmTextWords1467[1467];
extern const HeliosBmInsnRecord kHeliosBmDisassemblyTable1531[1531];

int32_t* GetOrInitThreadLocalCounter() noexcept;
bool IsCurrentThreadEntered() noexcept;
bool EnterThreadGuard() noexcept;
bool LeaveThreadGuard() noexcept;
HeliosGlobalState* GetHeliosGlobalState() noexcept;
size_t DiscoverArtMethodJniCodeOffset(const uintptr_t* method0_words,
                                      const uintptr_t* method1_words,
                                      size_t word_count,
                                      uintptr_t expected_fn0,
                                      uintptr_t expected_fn1,
                                      bool* out_verified) noexcept;
bool HookArtMethodEntrypoint(uintptr_t* art_method_base,
                             size_t jni_code_offset_bytes,
                             uintptr_t new_fn,
                             uintptr_t* out_orig_fn) noexcept;

}  // namespace helios_bm
}  // namespace opencut
}  // namespace nextai

extern "C" {
// EN: Exported symbols in `.dynsym` of `libhelios_bm.so`:
//     - [25] `JNI_OnLoad` (0x1eac, 632 bytes)
//     - [26] `_Z10nativeInitP7_JNIEnv` (`nativeInit(_JNIEnv*)`, 0x1c0c, 280 bytes)
// VI: 2 biểu tượng xuất khẩu trong `.dynsym` của `libhelios_bm.so`.
int  JNI_OnLoad(void* vm, void* reserved) noexcept;
void _Z10nativeInitP7_JNIEnv(void* env) noexcept;
}  // extern "C"

#endif  // NEXTAI_OPENCUT_HELIOS_BM_H_
