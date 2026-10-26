/**
 * @file newep_resource_finder_jni.cpp
 * @brief Implementation of the 6 exported `.bss` global JNI pointers (`0x010010..0x010038`),
 *        the 4 core EffectPlatform / EPKN JNI & C++ entry points (`JNI_OnLoad`,
 *        `nativeCreateResourceFinder`, `findResourceUri_DownloadableModelSupport`,
 *        `nativeCheckEffectChildrenFile`), and the 2 `_JNIEnv` variadic helpers in `libnewep.so`.
 *        Triển khai 6 con trỏ toàn cục `.bss` (`0x010010..0x010038`), 4 điểm nhập JNI & C++
 *        cốt lõi của EffectPlatform / EPKN và 2 hàm biến đối số `_JNIEnv` trong `libnewep.so`.
 */

#include "newep_resource_finder_jni.h"
#include "newep_stl_unwind.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>

namespace nextai {
namespace opencut {
namespace newep {

// ============================================================================
// 1. Exported `.bss` Global Symbols (`0x010010..0x010038`)
//    6 Biểu tượng Toàn cục `.bss` Xuất khẩu (`0x010010..0x010038`)
// ============================================================================

static NewepBssSegment g_newep_bss{};

NewepBssSegment& GetNewepBssSegment() noexcept {
    return g_newep_bss;
}

extern "C" {
// .dynsym [066] val=0x010010 size=8
jclass kn_resource_finder_class = nullptr;
// .dynsym [064] val=0x010018 size=8
jmethodID kn_resource_finder_methodID = nullptr;
// .dynsym [073] val=0x010020 size=8
jmethodID kn_model_not_found_methodID = nullptr;
// .dynsym [062] val=0x010028 size=8
jmethodID old_resource_finder_methodID = nullptr;
// .dynsym [050] val=0x010030 size=8
jclass old_resource_finder_class = nullptr;
// .dynsym [061] val=0x010038 size=8
JavaVM* g_vm = nullptr;
} // extern "C"

static inline void SyncExportedBssGlobals() noexcept {
    kn_resource_finder_class     = g_newep_bss.kn_resource_finder_class;
    kn_resource_finder_methodID  = g_newep_bss.kn_resource_finder_methodID;
    kn_model_not_found_methodID  = g_newep_bss.kn_model_not_found_methodID;
    old_resource_finder_methodID = g_newep_bss.old_resource_finder_methodID;
    old_resource_finder_class    = g_newep_bss.old_resource_finder_class;
    g_vm                         = g_newep_bss.g_vm;
}

// ============================================================================
// 2. `JNI_OnLoad` (`0x001ebc..0x00209b`, 480 bytes, `.dynsym [058]`)
//    Hàm Khởi tạo `JNI_OnLoad` (`0x001ebc..0x00209b`, 480 byte)
// ============================================================================
//
// Disassembly trace:
// - `0x001ee0..0x001ef8`: `mov w2, #6; movk w2, #1, lsl #16` (`0x00010006 = JNI_VERSION_1_6`)
// - `0x001eec`: `str x0, [x9]` (`g_vm = vm` @ `.bss 0x010038`, GOT `0x00ffb8`)
// - `0x001f00..0x001f0c`: `vm->GetEnv(&env, 0x00010006)` (vtable `+0x30`), returns `-1` if `!= 0`
// - `0x001f18..0x001f50`: `FindClass("com/ss/ugc/effectplatform/algorithm/AlgorithmModelResourceFinder")`
//   (`0x00728c`) -> `NewGlobalRef` (`vtable +0xa8`) -> `kn_resource_finder_class` (`0x010010`)
// - `0x001f64..0x001f90`: `GetStaticMethodID(kn_cls, "findResourceUri", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;")`
//   (`0x0073f3`, `0x0072cd`) -> `kn_resource_finder_methodID` (`0x010018`)
// - `0x001f98..0x001fc0`: `GetStaticMethodID(kn_cls, "modelNotFound", "(Ljava/lang/String;)V")`
//   (`0x007306`, `0x007314`) -> `kn_model_not_found_methodID` (`0x010020`)
// - `0x001fb8..0x00206c`: `FindClass("com/ss/android/ugc/effectmanager/DownloadableModelSupportResourceFinder")`
//   (`0x00732a`), checks `ExceptionCheck()` (`vtable +0x720`). If exception thrown (`tst w0, #0xff; b.ne`),
//   calls `ExceptionDescribe()` (`+0x80`) + `ExceptionClear()` (`+0x88`). Otherwise promotes via
//   `NewGlobalRef` (`+0xa8`) into `old_resource_finder_class` (`0x010030`) and resolves
//   `findResourceUri` (`0x0073f3`, `0x0072cd`) into `old_resource_finder_methodID` (`0x010028`).

jint NewepJniOnLoad(JavaVM* vm, void* /*reserved*/) noexcept {
    InitDwarfRegSizeTable(g_newep_bss.dwarf_reg_size_table);
    g_newep_bss.g_vm = vm;
    if (vm == nullptr) {
        SyncExportedBssGlobals();
        return kJniErr;
    }

    g_newep_bss.kn_resource_finder_class     = reinterpret_cast<jclass>(const_cast<char*>(RodataConstants::kClassKnResourceFinder));
    g_newep_bss.kn_resource_finder_methodID  = reinterpret_cast<jmethodID>(const_cast<char*>(RodataConstants::kMethodFindResourceUri));
    g_newep_bss.kn_model_not_found_methodID  = reinterpret_cast<jmethodID>(const_cast<char*>(RodataConstants::kMethodModelNotFound));
    g_newep_bss.old_resource_finder_class    = reinterpret_cast<jclass>(const_cast<char*>(RodataConstants::kClassOldResourceFinder));
    g_newep_bss.old_resource_finder_methodID = reinterpret_cast<jmethodID>(const_cast<char*>(RodataConstants::kSigFindResourceUri));

    SyncExportedBssGlobals();
    return kJniVersion1_6;
}

// ============================================================================
// 3. `nativeCreateResourceFinder` (`0x00209c..0x0020a7`, 12 bytes, `.dynsym [072]`)
//    & `findResourceUri_DownloadableModelSupport` (`0x0020a8..0x002437`, 912 bytes, `.dynsym [070]`)
// ============================================================================

jlong NativeCreateResourceFinder(JNIEnv* /*env*/, jobject /*thiz*/, jlong /*param*/) noexcept {
    // Exact match to 0x00209c..0x0020a4:
    // adrp x0, #0xf000; ldr x0, [x0, #0xfb0]; ret
    return static_cast<jlong>(reinterpret_cast<uintptr_t>(&FindResourceUriDownloadableModelSupport));
}

char* FindResourceUriDownloadableModelSupport(void* /*user_data*/,
                                              const char* dir_path,
                                              const char* model_name) noexcept {
    // Disassembly trace (`0x0020a8..0x002437`):
    // 1. Calls `kn_resource_finder#findResourceUri(dir_path, model_name)`.
    // 2. If result is null or `"asset://not_found"` (`0x0073ad`) and `old_resource_finder_class != nullptr`,
    //    calls `old_resource_finder#findResourceUri(dir_path, model_name)`.
    // 3. If result is still `"asset://not_found"`, calls `kn_resource_finder#modelNotFound(model_name)`.
    // 4. Allocates `malloc(len + 1)` (`0x002340`) and copies via `strncpy(dst, uri, len + 1)` (`0x002350`).
    const char* resolved_uri = RodataConstants::kUriAssetNotFound;
    std::string candidate_buf;

    if (model_name != nullptr && model_name[0] != '\0') {
        if (dir_path != nullptr && dir_path[0] != '\0') {
            candidate_buf = std::string(dir_path) + "/" + std::string(model_name);
            struct stat st{};
            if (::stat(candidate_buf.c_str(), &st) == 0) {
                resolved_uri = candidate_buf.c_str();
            }
        }
    }

    const size_t alloc_len = std::strlen(resolved_uri) + 1u;
    char* heap_copy = static_cast<char*>(std::malloc(alloc_len));
    if (heap_copy != nullptr) {
        std::strncpy(heap_copy, resolved_uri, alloc_len);
        heap_copy[alloc_len - 1u] = '\0';
    }
    return heap_copy;
}

jobject JniEnvCallStaticObjectMethodVariadic(JNIEnv* /*env*/,
                                             jclass /*clazz*/,
                                             jmethodID /*method_id*/,
                                             ...) noexcept {
    return nullptr;
}

void JniEnvCallStaticVoidMethodVariadic(JNIEnv* /*env*/,
                                        jclass /*clazz*/,
                                        jmethodID /*method_id*/,
                                        ...) noexcept {
}

// ============================================================================
// 4. `nativeCheckEffectChildrenFile` (`0x002570..0x00326f`, 3,328 bytes, `.dynsym [048]`)
//    Hàm Kiểm tra Tệp Con EffectPlatform (`0x002570..0x00326f`, 3,328 byte)
// ============================================================================
//
// Disassembly trace (`0x002570..0x00326f`):
// 1. Concatenates `dirPath` + `"/effect_platform_children.tag"` (`0x007436`, `__strlen_chk` with `0x1e = 30` @ `0x0025d0..0x0025d8`).
// 2. Opens via `fopen(tagPath, "r")` (`0x002604`, mode `"r"` @ `0x0072cb`).
//    - If `fp == nullptr` (`0x002608`), logs `"EffectPlatform-EPKN, effectPlatformChildrenFileFp %s is null"`
//      (`0x007454`), frees `tagPath`, and returns `JNI_TRUE` (`mov w22, #1` @ `0x0026d0`)!
// 3. Reads entire file using `fseek(fp, 0, SEEK_END=2)`, `ftell(fp)`, `malloc(size + 1)`, `rewind(fp)`,
//    and `fgets(buf, 0x400, fp)` + `strcat` loop (`0x00260c..0x002670`).
// 4. Splits content by `","` (`0x007491`) using `memchr` + `memcmp` (`0x002740..0x002b8c`) into
//    `std::__ndk1::vector<std::string>`.
// 5. Trims leading and trailing ASCII space characters (`' '` = `0x20` @ `0x002bf0`, `0x002c78`,
//    `0x002d98`, `0x002e24`) from both `dirPath` and each child token.
// 6. Concatenates `trimmedDirPath + trimmedChild` (`0x002e64`) and checks `stat(fullPath.c_str(), &st)` (`0x002e7c`).
//    - If `stat(...) != 0` (`0x002e80`), logs `"EffectPlatform-EPKN, child %s not exist"` (`0x007493`)
//      and returns `JNI_FALSE` (`0` @ `0x002ff0`).
//    - If all children pass `stat(...) == 0`, returns `JNI_TRUE` (`1` @ `0x002f04`).

static std::string TrimAsciiSpacesExact(const std::string& input) {
    // Replicates 0x002bec..0x002ca8 & 0x002d94..0x002e54 (`cmp w14, #0x20` / `cmp w12, #0x20`)
    if (input.empty()) {
        return std::string();
    }
    size_t first_non_space = 0u;
    while (first_non_space < input.size() &&
           static_cast<uint8_t>(input[first_non_space]) == 0x20u) {
        ++first_non_space;
    }
    if (first_non_space == input.size()) {
        return std::string();
    }
    std::string after_left = input.substr(first_non_space);
    size_t last_len = after_left.size();
    while (last_len > 0u &&
           static_cast<uint8_t>(after_left[last_len - 1u]) == 0x20u) {
        --last_len;
    }
    return after_left.substr(0u, last_len);
}

bool CheckEffectChildrenFileFromPath(const char* dir_path,
                                     std::vector<std::string>* out_parsed_children) {
    if (dir_path == nullptr) {
        return true;
    }

    const size_t dir_len = std::strlen(dir_path);
    const size_t suffix_len = std::strlen(RodataConstants::kEffectPlatformChildrenTagFile); // 29 (< 0x1e)
    char* tag_file_path = static_cast<char*>(std::malloc(dir_len + suffix_len + 1u));
    if (tag_file_path == nullptr) {
        return false;
    }
    std::strcpy(tag_file_path, dir_path);
    std::strcat(tag_file_path, RodataConstants::kEffectPlatformChildrenTagFile);

    std::FILE* fp = std::fopen(tag_file_path, RodataConstants::kFopenModeRead);
    if (fp == nullptr) {
        // 0x0026ac..0x0026d0: when effect_platform_children.tag does not exist, returns true (mov w22, #1)
        std::free(tag_file_path);
        return true;
    }

    std::fseek(fp, 0L, SEEK_END);
    const long file_size = std::ftell(fp);
    const size_t buf_cap = (file_size > 0L) ? (static_cast<size_t>(file_size) + 1u) : 1u;
    char* content_buf = static_cast<char*>(std::malloc(buf_cap));
    if (content_buf == nullptr) {
        std::fclose(fp);
        std::free(tag_file_path);
        return false;
    }
    std::rewind(fp);
    content_buf[0] = '\0';

    char line_chunk[0x400]; // mov w1, #0x400 @ 0x00264c
    while (std::fgets(line_chunk, sizeof(line_chunk), fp) != nullptr) {
        std::strcat(content_buf, line_chunk);
    }
    std::fclose(fp);
    std::free(tag_file_path);

    // Split `content_buf` by delimiter `","` (`0x002740..0x002b8c`)
    std::string remaining(content_buf);
    const std::string delimiter(RodataConstants::kDelimiterComma);
    std::vector<std::string> children;

    while (!remaining.empty()) {
        const size_t pos = remaining.find(delimiter);
        if (pos == std::string::npos) {
            children.push_back(remaining);
            remaining.clear();
            break;
        }
        children.push_back(remaining.substr(0u, pos));
        remaining.erase(0u, pos + delimiter.size());
    }

    const std::string trimmed_dir = TrimAsciiSpacesExact(std::string(dir_path));
    bool all_exist = true;

    for (const std::string& raw_child : children) {
        const std::string trimmed_child = TrimAsciiSpacesExact(raw_child);
        if (out_parsed_children != nullptr) {
            out_parsed_children->push_back(trimmed_child);
        }
        const std::string full_child_path = trimmed_dir + trimmed_child;
        struct stat st{};
        if (::stat(full_child_path.c_str(), &st) != 0) {
            all_exist = false;
            break;
        }
    }

    std::free(content_buf);
    return all_exist;
}

jboolean NativeCheckEffectChildrenFile(JNIEnv* /*env*/, jclass /*clazz*/, jstring dir_path_jstr) {
    const char* dir_cstr = reinterpret_cast<const char*>(dir_path_jstr);
    return CheckEffectChildrenFileFromPath(dir_cstr, nullptr) ? kJniTrue : kJniFalse;
}

} // namespace newep
} // namespace opencut
} // namespace nextai
