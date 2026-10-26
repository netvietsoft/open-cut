/**
 * ============================================================================
 * File: SOURCE/GIAI-MA/libart_sym/art_method_field_modifier.h
 * Library: libart_sym.so (124,720 bytes, SHA-256: cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8)
 * Target: 72 / 169 — ArtMethod, ArtMethodModifier, ArtFieldModifier,
 *                    DisableHiddenApi, and ArtClassLinker Subsystem
 * ============================================================================
 *
 * [EN] Clean-room C++17 declarations for `art::ArtMethod`, `art::ArtMethodModifier`,
 * `art::ArtFieldModifier`, `art::DisableHiddenApi`, and `art::ArtClassLinker`,
 * reconstructed from AArch64 disassembly (`0x013340..0x01541b` and `0x015a44..0x016143`).
 *
 * [VN] Khai báo C++17 clean-room cho `art::ArtMethod`, `art::ArtMethodModifier`,
 * `art::ArtFieldModifier`, `art::DisableHiddenApi`, và `art::ArtClassLinker`,
 * được tái dựng từ mã máy AArch64 (`0x013340..0x01541b` và `0x015a44..0x016143`).
 * ============================================================================
 */

#ifndef NEXTAI_OPENCUT_LIBART_SYM_METHOD_FIELD_MODIFIER_H_
#define NEXTAI_OPENCUT_LIBART_SYM_METHOD_FIELD_MODIFIER_H_

#include "art_sym_types.h"

namespace art {

// ============================================================================
// 1. art::ArtMethod — Entry-Point Offset Discovery & Bridge Inspection
//    Khám phá vị trí con trỏ điểm vào (entry_point) và kiểm tra cầu nối thực thi
//    Addresses / Địa chỉ: 0x013340 .. 0x013f9b
// ============================================================================

class ArtMethod {
 public:
  // [0x013340] Default constructor: zeroes thiz_ (+0x00)
  ArtMethod() noexcept : thiz_(nullptr) {}

  // [0x013348] Wraps a raw _jmethodID* (ArtMethod*)
  explicit ArtMethod(jmethodID method) noexcept : thiz_(reinterpret_cast<void**>(method)) {}

  // [0x013350] Returns true if entry_point_index_ >= 0 and thiz_ != nullptr
  bool IsValid() const noexcept;

  // [0x013370] Returns true if thiz_ != nullptr
  bool HasThiz() const noexcept { return thiz_ != nullptr; }

  // [0x01337c] Returns raw ArtMethod* pointer
  void* GetThiz() const noexcept { return thiz_; }

  // [0x013384] Returns discovered pointer-array index of entry_point_from_quick_compiled_code_
  static int32_t GetEntryPointIndex() noexcept { return entry_point_index_; }

  // [0x013390] Discovers entry_point_index_ across 4 fallback strategies using
  // `methods[0..count-1]` and resolves `art_quick_generic_jni_trampoline`
  static bool Init(JNIEnv* env, jmethodID* methods, size_t count) noexcept;

  // [0x013588] Returns resolved address of `art_quick_generic_jni_trampoline`
  static void* GetArtQuickGenericJniTrampoline() noexcept {
    return art_quick_generic_jni_trampoline;
  }

  // [0x013594] Strategy 1: Calls ArtClassLinker::IsQuickToInterpreterBridge on candidate pointers
  static bool GetEntryPointOffsetAndArtQuickToInterpreterBridgeByIsQuickToInterpreterBridge(
      jmethodID method) noexcept;

  // [0x013660] Returns resolved address of `art_quick_to_interpreter_bridge`
  static void* GetArtQuickToInterpreterBridge() noexcept {
    return art_quick_to_interpreter_bridge;
  }

  // [0x01366c] Strategy 2: Searches method words for `art_quick_to_interpreter_bridge`
  static bool GetEntryPointOffsetByInterpreterMethod(jmethodID method) noexcept;

  // [0x0136c8] Strategy 3: Clones method into 256-byte scratch buffer, calls
  // ArtClassLinker::SetEntryPointsForObsoleteMethod, and searches for `art_invoke_obsolete_method_stub`
  static bool GetEntryPointOffsetByObsoleteMethod(jmethodID method) noexcept;

  // [0x013740] Strategy 4: Calls ArtRuntime::CreateResolutionMethod and searches
  // for `art_quick_resolution_trampoline`
  static bool GetEntryPointOffsetByResolutionMethod() noexcept;

  // [0x0137ac] Reads `thiz_[entry_point_index_]`
  void* GetEntryPointFromQuickCompiledCode() const noexcept;

  // [0x01382c] Writes `thiz_[entry_point_index_] = entry_point`
  void SetEntryPointFromQuickCompiledCode(void* entry_point) noexcept;

  // [0x0138a8] Checks if current entry point equals `art_quick_to_interpreter_bridge`
  bool IsInterpreterCode() const noexcept;

  // [0x0138d4] Checks if current entry point equals `art_quick_generic_jni_trampoline`
  bool IsGenericJniCode() const noexcept;

  // [0x013900] Reads access_flags via ArtMethodModifier::getAccessFlags(thiz_)
  uint32_t GetAccessFlags() const noexcept;

  // [0x013974] Writes access_flags via ArtMethodModifier::setAccessFlags(thiz_, flags)
  bool SetAccessFlags(uint32_t flags) noexcept;

  // [0x0139e8] Reads dex_method_index_ via ArtMethodModifier
  uint32_t GetDexMethodIndex() const noexcept;

  // [0x013a00] Reads method_index_ (vtable index) via ArtMethodModifier
  uint16_t GetMethodIndex() const noexcept;

  // [0x013a18] Checks whether kAccNative (0x100) is set in GetAccessFlags()
  bool IsNative() const noexcept;

  // [0x013a30] Converts java.lang.reflect.Method/Constructor jobject to ArtMethod*
  // via env->FromReflectedMethod(reflected_method)
  static ArtMethod FromReflectedMethod(JNIEnv* env, jobject reflected_method) noexcept;

  // Static state in .data (0x025ef8) and .bss (0x025f10..0x025f30)
  static int32_t entry_point_index_;             // .data 0x025ef8 = -1
  static bool has_init_;                         // .bss  0x025f10
  static std::mutex init_lock_;                  // .bss  0x025f18
  static void* art_quick_generic_jni_trampoline; // .bss  0x025f20
  static void* art_quick_to_interpreter_bridge;  // .bss  0x025f28

 private:
  void** thiz_;  // +0x00: Pointer to ArtMethod pointer slots
};

// ============================================================================
// 2. art::ArtMethodModifier — Access Flags, DexMethodIndex & MethodIndex Patcher
//    Trình khám phá và chỉnh sửa cờ truy cập, chỉ số Dex và chỉ số bảng phương thức ảo
//    Addresses / Địa chỉ: 0x013f9c .. 0x014b87
// ============================================================================

class ArtMethodModifier {
 public:
  // [0x013f9c] Initializes Method/Constructor/Executable reflection handles,
  // inspects `com/bytedance/frameworks/core/artsym/StubClass.stubMethod()V`,
  // and discovers `dexMethodIndexIndex`, `accessFlagsIndex`, and `methodIndexIndex` (== 11)
  static bool Init(JNIEnv* env) noexcept;

  // [0x014528] Verifies whether `methodIndexIndex` holds matching 16-bit vtable indices
  static bool CheckMethodIndex(JNIEnv* env) noexcept;

  // [0x014650] Dumps first 20 uint32_t words of an ArtMethod* to logcat ("art_sym")
  static void printMethod(jmethodID method) noexcept;

  // [0x014754] Patches accessFlags: `(flags & ~0x3u) | 0x1u` (clears private/protected, sets public)
  static bool changeAccessFlagToPublic(jmethodID method) noexcept;

  // [0x014804] Sets kAccPreverified (0x80000) if method is not native/abstract
  // (checks `flags & 0x500` on API <= 23, or `flags & 0x800500` on API > 23)
  static bool changeAccessFlagToPreverified(jmethodID method) noexcept;

  // [0x0148f8] If kAccProtected (0x4) is set, clears 0x4 and sets kAccPublic (0x1): `(flags & ~4u) | 1u`
  static bool changeAccessFlagProtectedToPublic(jmethodID method) noexcept;

  // [0x014988] Returns `(reinterpret_cast<uint32_t*>(method))[accessFlagsIndex]`
  static uint32_t getAccessFlags(void* method) noexcept;

  // [0x0149fc] Writes `(reinterpret_cast<uint32_t*>(method))[accessFlagsIndex] = flags`
  static bool setAccessFlags(void* method, uint32_t flags) noexcept;

  // [0x014a70] Returns `(reinterpret_cast<uint32_t*>(method))[dexMethodIndexIndex]`
  static uint32_t getDexMethodIndex(void* method) noexcept;

  // [0x014aa4] Returns `(reinterpret_cast<uint16_t*>(method))[methodIndexIndex]`
  static uint16_t getMethodIndex(void* method) noexcept;

  // Static state in .data (0x025efc..0x025f00) and .bss (0x025f38..0x026078)
  static int32_t accessFlagsIndex;        // .data 0x025efc = -1
  static int32_t methodIndexIndex;        // .data 0x025f00 = -1
  static int32_t dexMethodIndexIndex;     // .bss  0x026078 = 0
  static jclass methodClass;              // .bss  0x025f38
  static jclass constructorClass;         // .bss  0x025f40
  static jclass executableClass;          // .bss  0x025f48
  static jmethodID getDexMethodIndexMethod;  // .bss 0x025f50
  static jfieldID dexMethodIndexField;       // .bss 0x025f58
  static jmethodID getAccessFlagsMethod;     // .bss 0x025f60
  static jfieldID accessFlagsField;          // .bss 0x025f68
  static jclass stubClass;                   // .bss 0x025f70
  static jmethodID stubMethod;               // .bss 0x025f78
};

// ============================================================================
// 3. art::ArtFieldModifier — ArtField Access Flags & DeclaringClass Patcher
//    Trình khám phá và chỉnh sửa cờ truy cập cho trường ArtField (API <= 25)
//    Addresses / Địa chỉ: 0x014b88 .. 0x015083
// ============================================================================

class ArtFieldModifier {
 public:
  // [0x014b88] Initializes `java/lang/reflect/Field` and `java/lang/reflect/ArtField`
  // (on API <= 22) and discovers `declaringClassIndex` inside `StubClass.stubField`
  static bool Init(JNIEnv* env) noexcept;

  // [0x014e8c] Converts `jfieldID` to `ArtField*` (handling JNI encoded field IDs on
  // API <= 22 via `java.lang.reflect.Field.artField`) and modifies `access_flags_`
  // at `declaringClassIndex + 1`: `(flags & ~0x13u) | 0x1u` (clears final/private/protected, sets public)
  static bool changeAccessFlagToPublic(JNIEnv* env, jclass clazz, jfieldID field_id,
                                       bool is_static) noexcept;

  // [0x01501c] Dumps first 4 uint32_t words of ArtField* to logcat ("art_sym")
  static void printField(void* art_field) noexcept;

  static int32_t declaringClassIndex;  // .data 0x025f04 = -1
  static jclass stubClass;             // .bss  0x026080
  static jfieldID stubField;           // .bss  0x026088
  static jclass fieldClass;            // .bss  0x026090
  static jfieldID artFieldField;       // .bss  0x026098
  static jclass artFieldClass;         // .bss  0x0260a0
};

// ============================================================================
// 4. art::DisableHiddenApi — Android 9+ (API 28..34) Hidden API Bypass
//    Vượt qua cơ chế chặn Hidden API trên Android 9 (P) đến Android 14 (U)
//    Addresses / Địa chỉ: 0x015084 .. 0x01541b
// ============================================================================

class DisableHiddenApi {
 public:
  // [0x015084] Creates global `String[]{"L"}` array (`exemptions`) on API >= 28
  static bool Init(JNIEnv* env) noexcept;

  // [0x015210] Invokes `_ZN3artL32VMRuntime_setHiddenApiExemptionsEP7_JNIEnvP7_jclassP13_jobjectArray`
  // (or `.uniq.192290207011039899038504097525495887768` on Android 13+/Clang LTO)
  // or falls back to JVMTI `com.android.art.misc.disable_hidden_api_enforcement_policy` on API >= 31
  static bool disable(JNIEnv* env) noexcept;

  static jobjectArray exemptions;  // .bss 0x0260a8
  static bool hasExecuted;         // .bss 0x0260c0
  static bool result;              // .bss 0x0260d0
  static std::mutex lock_;         // .bss 0x0260c8
};

// ============================================================================
// 5. art::ArtClassLinker — Wrapper for Internal `art::ClassLinker` Symbols
//    Lớp bọc gọi trực tiếp các hàm nội bộ của `art::ClassLinker` trong libart.so
//    Addresses / Địa chỉ: 0x015a44 .. 0x016143
// ============================================================================

class ArtClassLinker : public ArtSymbolObject {
 public:
  ArtClassLinker() noexcept : ArtSymbolObject(nullptr) {}
  explicit ArtClassLinker(void* obj) noexcept : ArtSymbolObject(obj) {}

  // [0x015a44] Calls `_ZNK3art11ClassLinker30SetEntryPointsForObsoleteMethodEPNS_9ArtMethodE`
  bool SetEntryPointsForObsoleteMethod(jmethodID method) noexcept;

  // [0x015af4] Calls `_ZNK3art11ClassLinker27SetEntryPointsToInterpreterEPNS_9ArtMethodE`
  void SetEntryPointsToInterpreter(ArtMethod* method) noexcept;

  // [0x015ba0] Calls `_ZN3art11ClassLinker28InitFromImageInterpreterOnlyEv`
  void InitFromImageInterpreterOnly() noexcept;

  // [0x015c30] Calls `_ZNK3art11ClassLinker28IsQuickToInterpreterBridgeEPKv`
  bool IsQuickToInterpreterBridge(const void* code) noexcept;

  // [0x015ce0] Calls `_ZN3art11ClassLinker40MakeInitializedClassesVisiblyInitializedEPNS_6ThreadEb`
  void MakeInitializedClassesVisiblyInitialized(ArtThread* self, bool wait) noexcept;

  // [0x015d80] Calls `ClassLinker::GetQuickOatCodeFor(ArtMethod*)` (API >= 23 or API <= 22)
  const void* GetQuickOatCodeFor(ArtMethod* method) noexcept;

  // [0x015ed8] Checks if `CanWeInitializeClass` symbol can be resolved for the active SDK version
  bool SupportCanWeInitializeClass() noexcept;

  // [0x015f44] Calls `ClassLinker::CanWeInitializeClass(Class*, bool, bool)` across API <= 22, 23..25, >= 26
  bool CanWeInitializeClass(void* klass, bool can_init_statics, bool can_init_parents) noexcept;

  // [0x016090] Calls `_ZN3art11ClassLinker11RemoveClassEPKcPNS_6mirror11ClassLoaderE` (API <= 23)
  bool RemoveClass(const char* descriptor, void* class_loader) noexcept;
};

}  // namespace art

#endif  // NEXTAI_OPENCUT_LIBART_SYM_METHOD_FIELD_MODIFIER_H_
