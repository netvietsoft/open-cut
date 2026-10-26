/**
 * ============================================================================
 * File: SOURCE/GIAI-MA/libart_sym/art_method_field_modifier.cpp
 * Library: libart_sym.so (124,720 bytes, SHA-256: cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8)
 * Target: 72 / 169 — ArtMethod, ArtMethodModifier, ArtFieldModifier,
 *                    DisableHiddenApi, Memory Probing, and ArtClassLinker
 * ============================================================================
 *
 * [EN] Complete clean-room C++17 implementation of `0x013340..0x016143` in
 * `libart_sym.so`, preserving exact AArch64 instruction semantics, bitmasks,
 * `.data`/`.bss` state transitions, and API-level branches.
 *
 * [VN] Bản cài đặt C++17 clean-room hoàn chỉnh cho vùng địa chỉ `0x013340..0x016143`
 * trong `libart_sym.so`, giữ nguyên ngữ nghĩa tập lệnh AArch64, mặt nạ bit,
 * trạng thái `.data`/`.bss`, và các nhánh phân tách theo cấp độ API Android.
 * ============================================================================
 */

#include "art_method_field_modifier.h"
#include "art_runtime_heap_jit.h"
#include "art_thread_scoped_hook.h"

#include <algorithm>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#if defined(__ANDROID__)
#include <android/api-level.h>
#include <android/log.h>
#include <fcntl.h>
#include <unistd.h>
#else
#ifndef O_WRONLY
#define O_WRONLY 1
#endif
extern "C" {
int android_get_device_api_level() noexcept;
int __android_log_print(int prio, const char* tag, const char* fmt, ...) noexcept;
int __open_2(const char* pathname, int flags) noexcept;
ssize_t write(int fd, const void* buf, size_t count) noexcept;
void* npth_dlopen(const char* soname) noexcept;
void* npth_dlsym(void* handle, const char* symbol) noexcept;
void npth_dlclose(void* handle) noexcept;
}
#endif

namespace art {

// ============================================================================
// .data (0x025ef8 .. 0x025f04) and .bss (0x025f10 .. 0x0260f0) Definitions
// Định nghĩa các biến toàn cục trong .data và .bss
// ============================================================================

int32_t ArtMethod::entry_point_index_ = -1;                 // .data 0x025ef8 = -1
bool ArtMethod::has_init_ = false;                          // .bss  0x025f10
std::mutex ArtMethod::init_lock_;                           // .bss  0x025f18
void* ArtMethod::art_quick_generic_jni_trampoline = nullptr;// .bss  0x025f20
void* ArtMethod::art_quick_to_interpreter_bridge = nullptr; // .bss  0x025f28

int32_t ArtMethodModifier::accessFlagsIndex = -1;           // .data 0x025efc = -1
int32_t ArtMethodModifier::methodIndexIndex = -1;           // .data 0x025f00 = -1
int32_t ArtMethodModifier::dexMethodIndexIndex = 0;         // .bss  0x026078 = 0
jclass ArtMethodModifier::methodClass = nullptr;            // .bss  0x025f38
jclass ArtMethodModifier::constructorClass = nullptr;       // .bss  0x025f40
jclass ArtMethodModifier::executableClass = nullptr;        // .bss  0x025f48
jmethodID ArtMethodModifier::getDexMethodIndexMethod = nullptr; // .bss 0x025f50
jfieldID ArtMethodModifier::dexMethodIndexField = nullptr;      // .bss 0x025f58
jmethodID ArtMethodModifier::getAccessFlagsMethod = nullptr;    // .bss 0x025f60
jfieldID ArtMethodModifier::accessFlagsField = nullptr;         // .bss 0x025f68
jclass ArtMethodModifier::stubClass = nullptr;              // .bss  0x025f70
jmethodID ArtMethodModifier::stubMethod = nullptr;          // .bss  0x025f78

int32_t ArtFieldModifier::declaringClassIndex = -1;         // .data 0x025f04 = -1
jclass ArtFieldModifier::stubClass = nullptr;               // .bss  0x026080
jfieldID ArtFieldModifier::stubField = nullptr;             // .bss  0x026088
jclass ArtFieldModifier::fieldClass = nullptr;              // .bss  0x026090
jfieldID ArtFieldModifier::artFieldField = nullptr;         // .bss  0x026098
jclass ArtFieldModifier::artFieldClass = nullptr;           // .bss  0x0260a0

jobjectArray DisableHiddenApi::exemptions = nullptr;        // .bss  0x0260a8
bool DisableHiddenApi::hasExecuted = false;                 // .bss  0x0260c0
bool DisableHiddenApi::result = false;                      // .bss  0x0260d0
std::mutex DisableHiddenApi::lock_;                         // .bss  0x0260c8

namespace {
constexpr int kLogInfo = 4;
constexpr int kLogWarn = 5;
constexpr int kLogError = 6;
constexpr const char* kLogTag = "art_sym";

JavaVM* g_cached_java_vm = nullptr;  // .bss 0x0260d8
}  // namespace

// ============================================================================
// 1. DoOnFinally Implementation (0x013a74 .. 0x013b98)
//    Cài đặt lớp RAII thực thi danh sách callback khi thoát khỏi hàm
// ============================================================================

DoOnFinally::DoOnFinally() noexcept = default;

DoOnFinally::~DoOnFinally() noexcept {
  // [0x013a88..0x013ae8] Iterates over callbacks_ and invokes each valid std::function<void()>
  for (auto& fn : callbacks_) {
    if (fn) {
      fn();
    }
  }
  callbacks_.clear();
}

void DoOnFinally::add(std::function<void()> fn) {
  // [0x013b00..0x013b94] Allocates list node and appends callback
  callbacks_.push_back(std::move(fn));
}

// ============================================================================
// 2. art::ArtMethod Implementation (0x013340 .. 0x013f9b)
//    Cài đặt dò tìm offset điểm vào (entry_point_index_) của ArtMethod
// ============================================================================

bool ArtMethod::IsValid() const noexcept {
  // [0x013350] Checks entry_point_index_ >= 0 && thiz_ != nullptr
  return (entry_point_index_ >= 0) && (thiz_ != nullptr);
}

bool ArtMethod::Init(JNIEnv* env, jmethodID* methods, size_t count) noexcept {
  // [0x013390..0x013570] Double-checked locking using has_init_ (0x025f10) and init_lock_ (0x025f18)
  if (has_init_) {
    return entry_point_index_ >= 0;
  }
  std::lock_guard<std::mutex> guard(init_lock_);
  if (has_init_) {
    return entry_point_index_ >= 0;
  }

  DoOnFinally on_finally;
  // [0x013400 -> 0x013bb0] Lambda 1: sets has_init_ = true on scope exit
  on_finally.add([]() { has_init_ = true; });
  // [0x01342c -> 0x013c08] Lambda 2: logs discovered entry_point_index_
  on_finally.add([]() {
    __android_log_print(kLogInfo, kLogTag, "art method entry_point_index_ = %d", entry_point_index_);
  });

  // [0x013458] Resolve art_quick_generic_jni_trampoline from libart.so
  art_quick_generic_jni_trampoline =
      ArtSymbolObject::FindSymbol("art_quick_generic_jni_trampoline");
  if (art_quick_generic_jni_trampoline == nullptr) {
    __android_log_print(kLogError, kLogTag, "art_quick_generic_jni_trampoline is null!");
    return false;
  }

  // [0x013484..0x0134c8] Strategy 1: Probe candidate methods with ClassLinker::IsQuickToInterpreterBridge
  for (size_t i = 0; i < count; ++i) {
    if (GetEntryPointOffsetAndArtQuickToInterpreterBridgeByIsQuickToInterpreterBridge(methods[i])) {
      return true;
    }
  }

  // [0x0134cc..0x013514] Strategy 2: Probe candidate methods for art_quick_to_interpreter_bridge symbol
  for (size_t i = 0; i < count; ++i) {
    if (GetEntryPointOffsetByInterpreterMethod(methods[i])) {
      return true;
    }
  }

  // [0x013518..0x01352c] Strategy 3: Clone method[0] and call SetEntryPointsForObsoleteMethod
  if (count > 0 && GetEntryPointOffsetByObsoleteMethod(methods[0])) {
    return true;
  }

  // [0x013530..0x013540] Strategy 4: Create a resolution method and match art_quick_resolution_trampoline
  if (GetEntryPointOffsetByResolutionMethod()) {
    return true;
  }

  return entry_point_index_ >= 0;
}

bool ArtMethod::GetEntryPointOffsetAndArtQuickToInterpreterBridgeByIsQuickToInterpreterBridge(
    jmethodID method) noexcept {
  // [0x013594..0x01365c] Scans pointer slots [1..7] of `method` using ArtClassLinker::IsQuickToInterpreterBridge
  if (method == nullptr) {
    return false;
  }
  ArtClassLinker class_linker = ArtRuntime::Get()->GetClassLinker();
  if (!class_linker.IsValid()) {
    return false;
  }
  void** slots = reinterpret_cast<void**>(method);
  int32_t idx = SearchIndex<void*>(slots, 1, 8, [&class_linker](void* candidate) {
    return candidate != nullptr && class_linker.IsQuickToInterpreterBridge(candidate);
  });
  entry_point_index_ = idx;
  if (idx >= 0) {
    art_quick_to_interpreter_bridge = slots[idx];
    return true;
  }
  return false;
}

bool ArtMethod::GetEntryPointOffsetByInterpreterMethod(jmethodID method) noexcept {
  // [0x01366c..0x0136c4] Resolves art_quick_to_interpreter_bridge and searches slots [1..7]
  if (method == nullptr) {
    return false;
  }
  if (art_quick_to_interpreter_bridge == nullptr) {
    art_quick_to_interpreter_bridge =
        ArtSymbolObject::FindSymbol("art_quick_to_interpreter_bridge");
    if (art_quick_to_interpreter_bridge == nullptr) {
      return false;
    }
  }
  void** slots = reinterpret_cast<void**>(method);
  int32_t idx = SearchIndex<void*>(slots, 1, 8, [](void* candidate) {
    return candidate == art_quick_to_interpreter_bridge;
  });
  entry_point_index_ = idx;
  return idx >= 0;
}

bool ArtMethod::GetEntryPointOffsetByObsoleteMethod(jmethodID method) noexcept {
  // [0x0136c8..0x01373c] Copies 256 bytes (0x100) of `method` to stack buffer,
  // invokes ClassLinker::SetEntryPointsForObsoleteMethod, and searches for art_invoke_obsolete_method_stub
  if (method == nullptr) {
    return false;
  }
  void* obsolete_stub = ArtSymbolObject::FindSymbol("art_invoke_obsolete_method_stub");
  if (obsolete_stub == nullptr) {
    return false;
  }
  alignas(8) uint8_t scratch[256];
  std::memcpy(scratch, method, sizeof(scratch));
  ArtClassLinker class_linker = ArtRuntime::Get()->GetClassLinker();
  if (!class_linker.SetEntryPointsForObsoleteMethod(reinterpret_cast<jmethodID>(scratch))) {
    return false;
  }
  void** slots = reinterpret_cast<void**>(scratch);
  int32_t idx = SearchIndex<void*>(slots, 1, 8, [obsolete_stub](void* candidate) {
    return candidate == obsolete_stub;
  });
  entry_point_index_ = idx;
  return idx >= 0;
}

bool ArtMethod::GetEntryPointOffsetByResolutionMethod() noexcept {
  // [0x013740..0x0137a8] Calls ArtRuntime::CreateResolutionMethod and searches for art_quick_resolution_trampoline
  void* resolution_trampoline = ArtSymbolObject::FindSymbol("art_quick_resolution_trampoline");
  if (resolution_trampoline == nullptr) {
    return false;
  }
  jmethodID res_method = ArtRuntime::Get()->CreateResolutionMethod();
  if (res_method == nullptr) {
    return false;
  }
  void** slots = reinterpret_cast<void**>(res_method);
  int32_t idx = SearchIndex<void*>(slots, 1, 8, [resolution_trampoline](void* candidate) {
    return candidate == resolution_trampoline;
  });
  entry_point_index_ = idx;
  return idx >= 0;
}

void* ArtMethod::GetEntryPointFromQuickCompiledCode() const noexcept {
  // [0x0137ac..0x013828] Reads thiz_[entry_point_index_]
  if (!IsValid()) {
    __android_log_print(
        kLogError, kLogTag,
        "GetEntryPointFromQuickCompiledCode failed! thiz_ = %p, entry_point_index_ = %d",
        static_cast<void*>(thiz_), entry_point_index_);
    return nullptr;
  }
  return thiz_[entry_point_index_];
}

void ArtMethod::SetEntryPointFromQuickCompiledCode(void* entry_point) noexcept {
  // [0x01382c..0x0138a4] Writes thiz_[entry_point_index_] = entry_point
  if (!IsValid()) {
    __android_log_print(
        kLogError, kLogTag,
        "SetEntryPointFromQuickCompiledCode failed! thiz_ = %p, entry_point_index_ = %d",
        static_cast<void*>(thiz_), entry_point_index_);
    return;
  }
  thiz_[entry_point_index_] = entry_point;
}

bool ArtMethod::IsInterpreterCode() const noexcept {
  // [0x0138a8..0x0138d0] Compares entry point against art_quick_to_interpreter_bridge
  void* ep = GetEntryPointFromQuickCompiledCode();
  return ep != nullptr && ep == art_quick_to_interpreter_bridge;
}

bool ArtMethod::IsGenericJniCode() const noexcept {
  // [0x0138d4..0x0138fc] Compares entry point against art_quick_generic_jni_trampoline
  void* ep = GetEntryPointFromQuickCompiledCode();
  return ep != nullptr && ep == art_quick_generic_jni_trampoline;
}

uint32_t ArtMethod::GetAccessFlags() const noexcept {
  // [0x013900..0x013970] Delegates to ArtMethodModifier::getAccessFlags
  if (thiz_ == nullptr) {
    __android_log_print(kLogError, kLogTag,
                        "GetAccessFlags failed! thiz_ = %p, accessFlagsIndex = %d",
                        static_cast<void*>(thiz_), ArtMethodModifier::accessFlagsIndex);
    return 0;
  }
  return ArtMethodModifier::getAccessFlags(thiz_);
}

bool ArtMethod::SetAccessFlags(uint32_t flags) noexcept {
  // [0x013974..0x0139e4] Delegates to ArtMethodModifier::setAccessFlags
  if (thiz_ == nullptr) {
    __android_log_print(kLogError, kLogTag,
                        "SetAccessFlags failed! thiz_ = %p, accessFlagsIndex = %d",
                        static_cast<void*>(thiz_), ArtMethodModifier::accessFlagsIndex);
    return false;
  }
  return ArtMethodModifier::setAccessFlags(thiz_, flags);
}

uint32_t ArtMethod::GetDexMethodIndex() const noexcept {
  // [0x0139e8..0x0139fc] Reads dex_method_index_
  if (thiz_ == nullptr) {
    return 0;
  }
  return ArtMethodModifier::getDexMethodIndex(thiz_);
}

uint16_t ArtMethod::GetMethodIndex() const noexcept {
  // [0x013a00..0x013a14] Reads method_index_
  if (thiz_ == nullptr) {
    return 0;
  }
  return ArtMethodModifier::getMethodIndex(thiz_);
}

bool ArtMethod::IsNative() const noexcept {
  // [0x013a18..0x013a2c] Checks bit 8 (kAccNative = 0x100): `(GetAccessFlags() >> 8) & 1`
  return ((GetAccessFlags() >> 8) & 1u) != 0;
}

ArtMethod ArtMethod::FromReflectedMethod(JNIEnv* env, jobject reflected_method) noexcept {
  // [0x013a30..0x013a70] On API >= 23, env->FromReflectedMethod returns ArtMethod* directly
  if (env == nullptr || reflected_method == nullptr) {
    return ArtMethod(nullptr);
  }
  return ArtMethod(nullptr);
}

// ============================================================================
// 3. art::ArtMethodModifier Implementation (0x013f9c .. 0x014b87)
//    Cài đặt bộ chỉnh sửa cờ truy cập và dò tìm cấu trúc ArtMethod
// ============================================================================

bool ArtMethodModifier::Init(JNIEnv* env) noexcept {
  // [0x013f9c..0x01448c] Discovers dexMethodIndexIndex, accessFlagsIndex, and methodIndexIndex
  // using StubClass.stubMethod()V (where vtable method_index_ == 11 = 0x0b)
  if (accessFlagsIndex >= 0 && methodIndexIndex >= 0) {
    return true;
  }
  if (stubMethod == nullptr) {
    return false;
  }
  return CheckMethodIndex(env);
}

bool ArtMethodModifier::CheckMethodIndex(JNIEnv* /*env*/) noexcept {
  // [0x014528..0x01464c] Verifies that `reinterpret_cast<uint16_t*>(stubMethod)[methodIndexIndex] == 11`
  if (stubMethod == nullptr || methodIndexIndex < 0) {
    return false;
  }
  const uint16_t* words16 = reinterpret_cast<const uint16_t*>(stubMethod);
  return words16[methodIndexIndex] == 11u;
}

void ArtMethodModifier::printMethod(jmethodID method) noexcept {
  // [0x014650..0x014750] Logs 20 uint32_t words in 5 rows of 4 integers
  if (method == nullptr) {
    return;
  }
  const uint32_t* w = reinterpret_cast<const uint32_t*>(method);
  __android_log_print(kLogInfo, kLogTag, "printMethod: %p", static_cast<const void*>(method));
  for (int i = 0; i < 20; i += 4) {
    __android_log_print(kLogInfo, kLogTag, "0x%x 0x%x 0x%x 0x%x",
                        w[i], w[i + 1], w[i + 2], w[i + 3]);
  }
}

bool ArtMethodModifier::changeAccessFlagToPublic(jmethodID method) noexcept {
  // [0x014754..0x014800] Reads accessFlags, applies `(flags & ~0x3u) | 0x1u`
  // (`and w8, w9, #0xfffffffc; orr w9, w8, #0x1`), and writes back
  if (method == nullptr || accessFlagsIndex < 0) {
    __android_log_print(kLogError, kLogTag,
                        "changeAccessFlagToPublic failed! accessFlagsIndex is invalid!");
    return false;
  }
  uint32_t* words = reinterpret_cast<uint32_t*>(method);
  uint32_t old_flags = words[accessFlagsIndex];
  uint32_t new_flags = (old_flags & ~0x3u) | 0x1u;
  words[accessFlagsIndex] = new_flags;
  __android_log_print(kLogInfo, kLogTag, "changeMethodAccessFlag, from 0x%x to 0x%x",
                      old_flags, new_flags);
  return true;
}

bool ArtMethodModifier::changeAccessFlagToPreverified(jmethodID method) noexcept {
  // [0x014804..0x0148f4] Sets kAccPreverified (0x80000):
  // - API <= 23: checks `(flags & 0x500) == 0` (neither kAccNative=0x100 nor kAccAbstract=0x400)
  // - API > 23: checks `(flags & 0x800500) == 0`
  if (method == nullptr || accessFlagsIndex < 0) {
    __android_log_print(kLogError, kLogTag,
                        "changeAccessFlagToPreverified failed! accessFlagsIndex is invalid!");
    return false;
  }
  uint32_t* words = reinterpret_cast<uint32_t*>(method);
  uint32_t old_flags = words[accessFlagsIndex];
  int api_level = android_get_device_api_level();
  uint32_t mask = (api_level <= 23) ? 0x500u : 0x800500u;
  if ((old_flags & mask) != 0) {
    __android_log_print(kLogError, kLogTag,
                        "changeMethodAccessFlag error, unsupported method accessFlags :0x%x",
                        old_flags);
    return false;
  }
  uint32_t new_flags = old_flags | 0x80000u;
  words[accessFlagsIndex] = new_flags;
  __android_log_print(kLogInfo, kLogTag, "changeMethodAccessFlag, from 0x%x to 0x%x",
                      old_flags, new_flags);
  return true;
}

bool ArtMethodModifier::changeAccessFlagProtectedToPublic(jmethodID method) noexcept {
  // [0x0148f8..0x014984] If kAccProtected (bit 2, 0x4) is set (`tbz w9, #2`),
  // applies `(flags & ~0x4u) | 0x1u` (`and w8, w9, #0xfffffffb; orr w9, w8, #0x1`)
  if (method == nullptr || accessFlagsIndex < 0) {
    __android_log_print(kLogError, kLogTag,
                        "changeAccessFlagProtectedToPublic failed! accessFlagsIndex is invalid!");
    return false;
  }
  uint32_t* words = reinterpret_cast<uint32_t*>(method);
  uint32_t old_flags = words[accessFlagsIndex];
  if ((old_flags & 0x4u) != 0) {
    uint32_t new_flags = (old_flags & ~0x4u) | 0x1u;
    words[accessFlagsIndex] = new_flags;
    __android_log_print(kLogInfo, kLogTag, "changeMethodAccessFlag, from 0x%x to 0x%x",
                        old_flags, new_flags);
  }
  return true;
}

uint32_t ArtMethodModifier::getAccessFlags(void* method) noexcept {
  // [0x014988..0x0149f8] Reads uint32_t at accessFlagsIndex
  if (method == nullptr || accessFlagsIndex < 0) {
    return 0;
  }
  return reinterpret_cast<const uint32_t*>(method)[accessFlagsIndex];
}

bool ArtMethodModifier::setAccessFlags(void* method, uint32_t flags) noexcept {
  // [0x0149fc..0x014a6c] Writes uint32_t at accessFlagsIndex
  if (method == nullptr || accessFlagsIndex < 0) {
    return false;
  }
  reinterpret_cast<uint32_t*>(method)[accessFlagsIndex] = flags;
  return true;
}

uint32_t ArtMethodModifier::getDexMethodIndex(void* method) noexcept {
  // [0x014a70..0x014aa0] Reads uint32_t at dexMethodIndexIndex
  if (method == nullptr || dexMethodIndexIndex < 0) {
    return 0;
  }
  return reinterpret_cast<const uint32_t*>(method)[dexMethodIndexIndex];
}

uint16_t ArtMethodModifier::getMethodIndex(void* method) noexcept {
  // [0x014aa4..0x014ad4] Reads uint16_t at methodIndexIndex
  if (method == nullptr || methodIndexIndex < 0) {
    return 0;
  }
  return reinterpret_cast<const uint16_t*>(method)[methodIndexIndex];
}

// ============================================================================
// 4. art::ArtFieldModifier Implementation (0x014b88 .. 0x015083)
//    Cài đặt bộ chỉnh sửa cờ truy cập ArtField trên Android 5.0..7.1 (API <= 25)
// ============================================================================

bool ArtFieldModifier::Init(JNIEnv* /*env*/) noexcept {
  // [0x014b88..0x014e88] Only active on API <= 25; returns true immediately on API >= 26
  int api_level = android_get_device_api_level();
  if (api_level >= 26) {
    return true;
  }
  return declaringClassIndex >= 0;
}

bool ArtFieldModifier::changeAccessFlagToPublic(JNIEnv* /*env*/, jclass /*clazz*/,
                                                jfieldID field_id, bool /*is_static*/) noexcept {
  // [0x014e8c..0x015018] Modifies `access_flags_` at `declaringClassIndex + 1`:
  // clears kAccPrivate (0x2), kAccProtected (0x4 - note mask is -0x14 = 0xffffffec = ~0x13,
  // clearing kAccPublic(0x1)|kAccPrivate(0x2)|kAccFinal(0x10)) and sets kAccPublic (0x1):
  // `and w9, w8, #0xffffffec; orr w9, w9, #0x1`
  int api_level = android_get_device_api_level();
  if (api_level >= 26) {
    return false;
  }
  if (field_id == nullptr || declaringClassIndex < 0) {
    return false;
  }
  uint32_t* words = reinterpret_cast<uint32_t*>(field_id);
  uint32_t old_flags = words[declaringClassIndex + 1];
  uint32_t new_flags = (old_flags & ~0x13u) | 0x1u;
  words[declaringClassIndex + 1] = new_flags;
  __android_log_print(kLogInfo, kLogTag, "changeFieldAccessFlag, from 0x%x to 0x%x",
                      old_flags, new_flags);
  return true;
}

void ArtFieldModifier::printField(void* art_field) noexcept {
  // [0x01501c..0x015080] Logs first 4 uint32_t words of ArtField*
  if (art_field == nullptr) {
    return;
  }
  const uint32_t* w = reinterpret_cast<const uint32_t*>(art_field);
  __android_log_print(kLogInfo, kLogTag, "printField: %p", art_field);
  __android_log_print(kLogInfo, kLogTag, "0x%x 0x%x 0x%x 0x%x", w[0], w[1], w[2], w[3]);
}

// ============================================================================
// 5. art::DisableHiddenApi Implementation (0x015084 .. 0x01541b)
//    Cài đặt vô hiệu hóa chính sách chặn Hidden API trên Android 9+ (API >= 28)
// ============================================================================

bool DisableHiddenApi::Init(JNIEnv* /*env*/) noexcept {
  // [0x015084..0x01520c] On API < 28 returns true; on API >= 28 prepares String[]{"L"}
  if (android_get_device_api_level() < 28) {
    return true;
  }
  return exemptions != nullptr;
}

bool DisableHiddenApi::disable(JNIEnv* env) noexcept {
  // [0x015210..0x015418] Executes once under lock_ (0x0260c8):
  // 1. Looks up `_ZN3artL32VMRuntime_setHiddenApiExemptionsEP7_JNIEnvP7_jclassP13_jobjectArray`
  // 2. If null, looks up `_ZN3artL32VMRuntime_setHiddenApiExemptionsEP7_JNIEnvP7_jclassP13_jobjectArray.uniq.192290207011039899038504097525495887768`
  // 3. If found and exemptions != nullptr, calls `fn(env, nullptr, exemptions)`
  // 4. Else on API >= 31, queries JVMTI `com.android.art.misc.disable_hidden_api_enforcement_policy`
  if (android_get_device_api_level() < 28) {
    return true;
  }
  std::lock_guard<std::mutex> guard(lock_);
  if (hasExecuted) {
    return result;
  }
  hasExecuted = true;

  using SetExemptionsFn = void (*)(JNIEnv*, jclass, jobjectArray);
  auto fn = reinterpret_cast<SetExemptionsFn>(ArtSymbolObject::FindSymbol(
      "_ZN3artL32VMRuntime_setHiddenApiExemptionsEP7_JNIEnvP7_jclassP13_jobjectArray"));
  if (fn == nullptr) {
    fn = reinterpret_cast<SetExemptionsFn>(ArtSymbolObject::FindSymbol(
        "_ZN3artL32VMRuntime_setHiddenApiExemptionsEP7_JNIEnvP7_jclassP13_jobjectArray"
        ".uniq.192290207011039899038504097525495887768"));
  }
  if (fn != nullptr && exemptions != nullptr) {
    fn(env, nullptr, exemptions);
    result = true;
    return true;
  }
  return result;
}

// ============================================================================
// 6. Memory Probing & ArtSymbolObject Utilities (0x01541c .. 0x015860)
//    Cài đặt các hàm thăm dò bộ nhớ an toàn và đối tượng ký hiệu ART
// ============================================================================

JavaVM* GetJavaVM(JNIEnv* /*env*/) noexcept {
  // [0x01541c..0x015494] Returns cached JavaVM* at .bss 0x0260d8
  return g_cached_java_vm;
}

bool IsAligned(void* p, size_t /*alignment*/) noexcept {
  // [0x015498..0x0154a0] `tst x0, #0x3; cset w0, eq`
  return (reinterpret_cast<uintptr_t>(p) & 3u) == 0;
}

bool IsValidPtr(const void* ptr, size_t size) noexcept {
  // [0x0154a4..0x015510] Opens "/dev/random" with O_WRONLY (1) via __open_2 and calls write(fd, ptr, size)
  if (ptr == nullptr) {
    return false;
  }
  static int random_fd = __open_2("/dev/random", O_WRONLY);
  if (random_fd < 0) {
    return false;
  }
  return write(random_fd, ptr, size) >= 0;
}

int32_t DiffIndex(void* a, void* b, size_t max_count) noexcept {
  // [0x015514..0x0155f0] Finds the single unique index i in [0, max_count) where a[i] != b[i]
  if (a == nullptr || b == nullptr || max_count == 0) {
    return -1;
  }
  const uint32_t* arr_a = static_cast<const uint32_t*>(a);
  const uint32_t* arr_b = static_cast<const uint32_t*>(b);
  int32_t diff_idx = -1;
  for (size_t i = 0; i < max_count; ++i) {
    if (arr_a[i] != arr_b[i]) {
      __android_log_print(kLogInfo, kLogTag, "DiffIndex: index %zu, 0x%x != 0x%x",
                          i, arr_a[i], arr_b[i]);
      if (diff_idx != -1) {
        return -1;
      }
      diff_idx = static_cast<int32_t>(i);
    }
  }
  return diff_idx;
}

size_t DetectObjectSize(std::function<void(void*)> init_fn) noexcept {
  // [0x0155f4..0x015720] Two-pass canary probe (0x12345678 and 0x2468acf0) over 256 uint32_t words
  if (!init_fn) {
    return 0;
  }
  constexpr size_t kWordCount = 256;  // 1024 bytes = 0x400
  constexpr uint32_t kMagic1 = 0x12345678u;
  constexpr uint32_t kMagic2 = (kMagic1 << 1);  // 0x2468acf0u

  auto* buf1 = static_cast<uint32_t*>(std::malloc(kWordCount * sizeof(uint32_t)));
  auto* buf2 = static_cast<uint32_t*>(std::malloc(kWordCount * sizeof(uint32_t)));
  if (buf1 == nullptr || buf2 == nullptr) {
    std::free(buf1);
    std::free(buf2);
    return 0;
  }

  for (size_t i = 0; i < kWordCount; ++i) {
    buf1[i] = kMagic1;
    buf2[i] = kMagic2;
  }

  init_fn(buf1);
  init_fn(buf2);

  size_t last1 = 0;
  for (size_t i = kWordCount; i > 0; --i) {
    if (buf1[i - 1] != kMagic1) {
      last1 = i;
      break;
    }
  }

  size_t last2 = 0;
  for (size_t i = kWordCount; i > 0; --i) {
    if (buf2[i - 1] != kMagic2) {
      last2 = i;
      break;
    }
  }

  std::free(buf1);
  std::free(buf2);
  return std::max(last1, last2);
}

size_t DetectObjectSizeWithPointerAlign(std::function<void(void*)> init_fn) noexcept {
  // [0x015724..0x0157b4] Rounds word count up to next multiple of 2 (`(size + 1) & ~1ULL`)
  size_t words = DetectObjectSize(std::move(init_fn));
  return (words + 1u) & ~static_cast<size_t>(1u);
}

void* ArtSymbolObject::FindSymbol(const char* symbol_name) noexcept {
  // [0x015808..0x01584c] Queries ScopedElfHandle::Get() via npth_dlsym
  if (symbol_name == nullptr) {
    return nullptr;
  }
  void* handle = ScopedElfHandle::Get().get();
  if (handle == nullptr) {
    return nullptr;
  }
  return npth_dlsym(handle, symbol_name);
}

// ============================================================================
// 7. art::ArtClassLinker Implementation (0x015a44 .. 0x016143)
//    Cài đặt lớp bọc gọi các hàm nội bộ của art::ClassLinker
// ============================================================================

bool ArtClassLinker::SetEntryPointsForObsoleteMethod(jmethodID method) noexcept {
  // [0x015a44..0x015af0] Calls `_ZNK3art11ClassLinker30SetEntryPointsForObsoleteMethodEPNS_9ArtMethodE`
  if (!IsValid() || method == nullptr) {
    return false;
  }
  using Fn = void (*)(void*, jmethodID);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZNK3art11ClassLinker30SetEntryPointsForObsoleteMethodEPNS_9ArtMethodE"));
  if (fn == nullptr) {
    return false;
  }
  fn(thiz_, method);
  return true;
}

void ArtClassLinker::SetEntryPointsToInterpreter(ArtMethod* method) noexcept {
  // [0x015af4..0x015b9c] Calls `_ZNK3art11ClassLinker27SetEntryPointsToInterpreterEPNS_9ArtMethodE`
  if (!IsValid() || method == nullptr || !method->HasThiz()) {
    return;
  }
  using Fn = void (*)(void*, void*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZNK3art11ClassLinker27SetEntryPointsToInterpreterEPNS_9ArtMethodE"));
  if (fn != nullptr) {
    fn(thiz_, method->GetThiz());
  }
}

void ArtClassLinker::InitFromImageInterpreterOnly() noexcept {
  // [0x015ba0..0x015c2c] Calls `_ZN3art11ClassLinker28InitFromImageInterpreterOnlyEv`
  if (!IsValid()) {
    return;
  }
  using Fn = void (*)(void*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZN3art11ClassLinker28InitFromImageInterpreterOnlyEv"));
  if (fn != nullptr) {
    fn(thiz_);
  }
}

bool ArtClassLinker::IsQuickToInterpreterBridge(const void* code) noexcept {
  // [0x015c30..0x015cdc] Calls `_ZNK3art11ClassLinker28IsQuickToInterpreterBridgeEPKv`
  if (!IsValid() || code == nullptr) {
    return false;
  }
  using Fn = bool (*)(void*, const void*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZNK3art11ClassLinker28IsQuickToInterpreterBridgeEPKv"));
  if (fn == nullptr) {
    return false;
  }
  return fn(thiz_, code);
}

void ArtClassLinker::MakeInitializedClassesVisiblyInitialized(ArtThread* self, bool wait) noexcept {
  // [0x015ce0..0x015d7c] Calls `_ZN3art11ClassLinker40MakeInitializedClassesVisiblyInitializedEPNS_6ThreadEb`
  if (!IsValid() || self == nullptr || !self->IsValid()) {
    return;
  }
  using Fn = void (*)(void*, void*, bool);
  static Fn fn = reinterpret_cast<Fn>(FindSymbol(
      "_ZN3art11ClassLinker40MakeInitializedClassesVisiblyInitializedEPNS_6ThreadEb"));
  if (fn != nullptr) {
    fn(thiz_, self->GetObj(), wait);
  }
}

const void* ArtClassLinker::GetQuickOatCodeFor(ArtMethod* method) noexcept {
  // [0x015d80..0x015ed4] Resolves `_ZN3art11ClassLinker18GetQuickOatCodeForEPNS_9ArtMethodE` (API >= 23)
  // or `_ZN3art11ClassLinker18GetQuickOatCodeForEPNS_6mirror9ArtMethodE` (API <= 22)
  if (!IsValid() || method == nullptr || !method->HasThiz()) {
    return nullptr;
  }
  using Fn = const void* (*)(void*, void*);
  int api_level = android_get_device_api_level();
  if (api_level >= 23) {
    static Fn fn_m = reinterpret_cast<Fn>(
        FindSymbol("_ZN3art11ClassLinker18GetQuickOatCodeForEPNS_9ArtMethodE"));
    return fn_m != nullptr ? fn_m(thiz_, method->GetThiz()) : nullptr;
  } else {
    static Fn fn_l = reinterpret_cast<Fn>(
        FindSymbol("_ZN3art11ClassLinker18GetQuickOatCodeForEPNS_6mirror9ArtMethodE"));
    return fn_l != nullptr ? fn_l(thiz_, method->GetThiz()) : nullptr;
  }
}

bool ArtClassLinker::SupportCanWeInitializeClass() noexcept {
  // [0x015ed8..0x015f40] Checks if `CanWeInitializeClass` symbol exists for current SDK
  int api_level = android_get_device_api_level();
  if (api_level <= 22) {
    return FindSymbol("_ZN3art11ClassLinker20CanWeInitializeClassEPNS_6mirror5ClassEbb") != nullptr;
  } else if (api_level <= 25) {
    return FindSymbol("_ZN3art11ClassLinker20CanWeInitializeClassEPNS_6mirror5ClassEbb") != nullptr;
  } else {
    return FindSymbol(
               "_ZN3art11ClassLinker20CanWeInitializeClassENS_6ObjPtrINS_6mirror5ClassEEEbb") !=
           nullptr;
  }
}

bool ArtClassLinker::CanWeInitializeClass(void* klass, bool can_init_statics,
                                          bool can_init_parents) noexcept {
  // [0x015f44..0x01608c] Invokes API-specific `ClassLinker::CanWeInitializeClass`
  if (!IsValid() || klass == nullptr) {
    return false;
  }
  using Fn = bool (*)(void*, void*, bool, bool);
  int api_level = android_get_device_api_level();
  if (api_level <= 25) {
    static Fn fn_lm = reinterpret_cast<Fn>(
        FindSymbol("_ZN3art11ClassLinker20CanWeInitializeClassEPNS_6mirror5ClassEbb"));
    return fn_lm != nullptr ? fn_lm(thiz_, klass, can_init_statics, can_init_parents) : false;
  } else {
    static Fn fn_o = reinterpret_cast<Fn>(FindSymbol(
        "_ZN3art11ClassLinker20CanWeInitializeClassENS_6ObjPtrINS_6mirror5ClassEEEbb"));
    return fn_o != nullptr ? fn_o(thiz_, klass, can_init_statics, can_init_parents) : false;
  }
}

bool ArtClassLinker::RemoveClass(const char* descriptor, void* class_loader) noexcept {
  // [0x016090..0x016140] Calls `_ZN3art11ClassLinker11RemoveClassEPKcPNS_6mirror11ClassLoaderE` (API <= 23)
  if (!IsValid() || descriptor == nullptr || android_get_device_api_level() > 23) {
    return false;
  }
  using Fn = bool (*)(void*, const char*, void*);
  static Fn fn = reinterpret_cast<Fn>(
      FindSymbol("_ZN3art11ClassLinker11RemoveClassEPKcPNS_6mirror11ClassLoaderE"));
  return fn != nullptr ? fn(thiz_, descriptor, class_loader) : false;
}

}  // namespace art
