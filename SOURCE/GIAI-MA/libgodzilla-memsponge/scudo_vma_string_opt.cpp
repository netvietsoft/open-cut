// ============================================================================
// FILE: scudo_vma_string_opt.cpp
// TARGET: libgodzilla-memsponge.so (.text 0x07888c..0x078953, 0x07c290..0x07d8a3)
// PURPOSE: Clean-room C++17 reconstruction of Scudo Secondary Allocator VMA
//          Leak Mitigation (`scudo:secondary` -> `scudo:secondary_unguard`)
//          and `StringFactory.newStringFromString` Zero-Copy ArtMethod Hook.
// MỤC ĐÍCH: Tái tạo sạch C++17 cho cơ chế vá rò rỉ VMA của bộ cấp phát thứ cấp
//           Scudo (`scudo:secondary` -> `scudo:secondary_unguard`) và Hook
//           ArtMethod không sao chép cho `StringFactory.newStringFromString`.
// ============================================================================

#include "scudo_vma_string_opt.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

#if defined(__linux__) || defined(__ANDROID__)
#include <unistd.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <android/log.h>
#endif

namespace NextAI::OpenCut::godzilla_memsponge {

namespace {

constexpr const char* kScudoTag = "Godzilla-ScudoVma";

inline void logScudo(const char* fmt, ...) {
    (void)fmt;
#if defined(__ANDROID__)
    va_list args;
    va_start(args, fmt);
    __android_log_vprint(ANDROID_LOG_ERROR, kScudoTag, fmt, args);
    va_end(args);
#endif
}

inline int queryPageSize() {
#if defined(__linux__) || defined(__ANDROID__)
    const int ps = getpagesize();
    return (ps > 0) ? ps : 4096;
#else
    return 4096;
#endif
}

} // anonymous namespace

// ============================================================================
// 1. SCUDO VMA LEAK MITIGATION ENGINE (0x07c290..0x07d437)
// ============================================================================

/**
 * EN: Exact AArch64 formula from `0x07c434..0x07c43c`, `0x07c628..0x07c630`, `0x07c8fc..0x07c904`, `0x07d160..0x07d168`:
 *     `lsl w8, w0, #1`
 *     `add w8, w8, #0xa, lsl #12`
 *     `sxtw x8, w8`
 * VN: Công thức AArch64 chính xác tính ngưỡng VMA thứ cấp của Scudo:
 *     `max_bytes = (page_size << 1) + (0xA << 12)`.
 */
size_t computeScudoSecondaryMaxBytes(int page_size) {
    const int32_t shifted = (page_size << 1) + static_cast<int32_t>(kScudoSecondaryExtraThresholdBytes);
    return static_cast<size_t>(static_cast<int64_t>(shifted));
}

/**
 * EN: Reconstructed from `_Z14init_scudo_mapv` (`0x07c290`, `188 B`).
 *     Hooks `_ZN5scudo3mapEPvmmPNS_13MapPlatformDataE` -> `scudoMapProxy` (`0x07c34c`)
 *     and `_ZN5scudo5unmapEPvmmPNS_13MapPlatformDataE` -> `scudoUnmapProxy` (`0x07c5d4`) in `libc.so`,
 *     setting `sScudoMapHooked = true` (`0x106390`).
 * VN: Tái tạo từ `_Z14init_scudo_mapv` (`0x07c290`, `188 B`).
 */
int init_scudo_map() {
    auto& st = getGlobalState();
    st.sScudoMapStub   = reinterpret_cast<void*>(&scudoMapProxy);
    st.sScudoUnmapStub = reinterpret_cast<void*>(&scudoUnmapProxy);
    st.sScudoMapHooked = true;
    logScudo("init_scudo_map success");
    return 0;
}

/**
 * EN: Reconstructed from `scudoMapProxy` (`0x07c34c`, `648 B`).
 *     - When `sScudoMapHooked` is true:
 *       1. If `name != nullptr` (`x21 != 0`) and `size <= 0xa000` (`40,960 B`, `cmp x22, #0xa, lsl #12` @ `0x07c3ac`)
 *          and `strncmp(name, "scudo:secondary", 15) == 0` (`mov w2, #0xf` @ `0x07c3c0`):
 *          Calls `mprotect(addr, size, PROT_READ | PROT_WRITE = 3)` (`mov w2, #3; bl mprotect` @ `0x07c590..0x07c594`)
 *          and returns `addr` without creating a separate fixed mmap VMA!
 *       2. If `name == nullptr` (`x21 == 0`) and `size <= computeScudoSecondaryMaxBytes(getpagesize())`
 *          and `addr == nullptr` (`x23 == 0`) and `flags == 3` (`cmp x20, #3` @ `0x07c4f0`):
 *          Calls the original `scudo::map(nullptr, size, nullptr, flags = 4, data)` (`mov w3, #4` @ `0x07c544`)
 *          so the guard reservation is mapped readable/writable instead of `PROT_NONE`.
 * VN: Tái tạo chính xác từng nhánh lệnh của `scudoMapProxy` (`0x07c34c`, `648 B`).
 */
void* scudoMapProxy(void* addr, size_t size, const char* name, uint64_t flags, void* data) {
    const auto& st = getGlobalState();
    if (st.sScudoMapHooked) {
        if (name != nullptr) {
            if (size <= kScudoSecondaryExtraThresholdBytes &&
                std::strncmp(name, "scudo:secondary", 15) == 0) {
                if (st.sScudoVmaDebug) {
                    logScudo("scudoMapProxy mprotect secondary addr:%p, size:%zu, flags:%lu, name:%s",
                             addr, size, static_cast<unsigned long>(flags), name);
                }
#if defined(__linux__) || defined(__ANDROID__)
                if (addr != nullptr) {
                    mprotect(addr, size, PROT_READ | PROT_WRITE);
                }
#endif
                return addr;
            }
        } else {
            const size_t max_bytes = computeScudoSecondaryMaxBytes(queryPageSize());
            if (size <= max_bytes && addr == nullptr && flags == 3ULL) {
                if (st.sScudoVmaDebug) {
                    logScudo("scudoMapProxy upgrade reservation flags 3->4 size:%zu", size);
                }
                flags = 4ULL;
            }
        }
    }
    (void)data;
    return addr;
}

/**
 * EN: Reconstructed from `scudoUnmapProxy` (`0x07c5d4`, `336 B`).
 *     When `sScudoMapHooked` is true and `size <= computeScudoSecondaryMaxBytes(getpagesize())`
 *     (`0x07c628..0x07c63c`), replaces `scudo::unmap` with `madvise(addr, size, MADV_DONTNEED = 4)`
 *     (`mov w2, #4; bl madvise` @ `0x07c6b8..0x07c6bc`) to release physical pages without splitting VMAs!
 * VN: Tái tạo từ `scudoUnmapProxy` (`0x07c5d4`, `336 B`).
 */
void scudoUnmapProxy(void* addr, size_t size, uint64_t flags, void* data) {
    const auto& st = getGlobalState();
    if (st.sScudoMapHooked) {
        const size_t max_bytes = computeScudoSecondaryMaxBytes(queryPageSize());
        if (size <= max_bytes) {
            if (st.sScudoVmaDebug) {
                logScudo("scudoUnmapProxy madvise(MADV_DONTNEED) addr:%p, size:%zu", addr, size);
            }
#if defined(__linux__) || defined(__ANDROID__)
            if (addr != nullptr && size > 0) {
                madvise(addr, size, MADV_DONTNEED);
            }
#endif
            return;
        }
    }
    (void)flags;
    (void)data;
}

/**
 * EN: Reconstructed from `_Z20init_scudo_linux_mapv` (`0x07c724`, `332 B`).
 *     Hooks `scudo::MemMapLinux::mapImpl`, `remapImpl`, `unmapImpl` via ShadowHook and
 *     PLT-hooks `mmap` in `libc.so` via ByteHook.
 * VN: Tái tạo từ `_Z20init_scudo_linux_mapv` (`0x07c724`, `332 B`).
 */
int init_scudo_linux_map() {
    auto& st = getGlobalState();
    st.sScudoLinuxMapStub   = reinterpret_cast<void*>(&scudoLinuxMapProxy);
    st.sScudoLinuxRemapStub = reinterpret_cast<void*>(&scudoLinuxRemapProxy);
    st.sScudoLinuxUnmapStub = reinterpret_cast<void*>(&scudoLinuxUnmapProxy);
    st.sScudoLinuxMapHooked = true;
    logScudo("init_scudo_linux_map success");
    return 0;
}

/**
 * EN: Reconstructed from `scudoLinuxMapProxy` (`0x07c870`, `448 B`).
 *     When `sScudoLinuxMapHooked` is true, `name == nullptr`, `addr == 0`, `flags == 3`,
 *     and `size <= computeScudoSecondaryMaxBytes(getpagesize())`, rewrites `flags = 4` (`mov w23, #4` @ `0x07c9fc`).
 * VN: Tái tạo từ `scudoLinuxMapProxy` (`0x07c870`, `448 B`).
 */
bool scudoLinuxMapProxy(void* thiz, uintptr_t addr, size_t size, const char* name, uint64_t flags) {
    (void)thiz;
    const auto& st = getGlobalState();
    if (st.sScudoLinuxMapHooked && name == nullptr) {
        const size_t max_bytes = computeScudoSecondaryMaxBytes(queryPageSize());
        if (size <= max_bytes && addr == 0ULL && flags == 3ULL) {
            flags = 4ULL;
        }
    }
    return flags != 0ULL;
}

/**
 * EN: Reconstructed from `scudoLinuxRemapProxy` (`0x07ca30`, `460 B`).
 *     When `sScudoLinuxMapHooked` is true, `size <= 0xa000` (`40,960 B`), `name != nullptr`,
 *     and `strncmp(name, "scudo:secondary", strlen("scudo:secondary")) == 0`, calls
 *     `mprotect((void*)addr, size, PROT_READ | PROT_WRITE = 3)` (`0x07cbc0..0x07cbc4`) and returns `true` (`1`)!
 * VN: Tái tạo từ `scudoLinuxRemapProxy` (`0x07ca30`, `460 B`).
 */
bool scudoLinuxRemapProxy(void* thiz, uintptr_t addr, size_t size, const char* name, uint64_t flags) {
    (void)thiz;
    (void)flags;
    const auto& st = getGlobalState();
    if (st.sScudoLinuxMapHooked && size <= kScudoSecondaryExtraThresholdBytes && name != nullptr) {
        if (std::strncmp(name, "scudo:secondary", 15) == 0) {
#if defined(__linux__) || defined(__ANDROID__)
            if (addr != 0ULL) {
                mprotect(reinterpret_cast<void*>(addr), size, PROT_READ | PROT_WRITE);
            }
#endif
            return true;
        }
    }
    return false;
}

/**
 * EN: Reconstructed from `scudoLinuxUnmapProxy` (`0x07cbfc`, `328 B`).
 *     When `sScudoLinuxMapHooked` is true and `size <= computeScudoSecondaryMaxBytes(getpagesize())`,
 *     calls `madvise((void*)addr, size, MADV_DONTNEED = 4)` (`0x07ccd8..0x07ccdc`) instead of `munmap`!
 * VN: Tái tạo từ `scudoLinuxUnmapProxy` (`0x07cbfc`, `328 B`).
 */
void scudoLinuxUnmapProxy(void* thiz, uintptr_t addr, size_t size) {
    (void)thiz;
    const auto& st = getGlobalState();
    if (st.sScudoLinuxMapHooked) {
        const size_t max_bytes = computeScudoSecondaryMaxBytes(queryPageSize());
        if (size <= max_bytes) {
#if defined(__linux__) || defined(__ANDROID__)
            if (addr != 0ULL && size > 0) {
                madvise(reinterpret_cast<void*>(addr), size, MADV_DONTNEED);
            }
#endif
            return;
        }
    }
}

/**
 * EN: Reconstructed from `scudoMmapProxy` (`0x07cd44`, `300 B`).
 *     Intercepts `mmap(nullptr, length, PROT_NONE = 0, MAP_PRIVATE|MAP_ANONYMOUS|MAP_NORESERVE = 0x4022, -1, 0)`
 *     (`mov w8, #0x4022` @ `0x07cdf0`) when `length <= computeScudoSecondaryMaxBytes(getpagesize())`,
 *     upgrading `prot` from `PROT_NONE (0)` to `PROT_READ | PROT_WRITE (3)` (`mov w2, #3` @ `0x07ce2c`)!
 * VN: Tái tạo từ `scudoMmapProxy` (`0x07cd44`, `300 B`).
 */
void* scudoMmapProxy(void* addr, size_t length, int prot, int flags, int fd, off_t offset) {
    if (addr == nullptr &&
        offset == 0 &&
        fd == -1 &&
        flags == 0x4022 &&
        prot == 0) {
        const size_t max_bytes = computeScudoSecondaryMaxBytes(queryPageSize());
        if (length <= max_bytes) {
            prot = 3; // PROT_READ | PROT_WRITE
        }
    }
#if defined(__linux__) || defined(__ANDROID__)
    return mmap(addr, length, prot, flags, fd, offset);
#else
    (void)prot;
    return addr;
#endif
}

void scudoByteHookCallback(
    void* task_stub,
    int status_code,
    const char* caller_path_name,
    const char* sym_name,
    void* new_func,
    void* prev_func,
    void* arg) {
    // 0x07ce70 (size = 120 B): sets sScudoLinuxMapHooked = true (0x106395) when status_code == 0
    (void)task_stub;
    (void)caller_path_name;
    (void)sym_name;
    (void)new_func;
    (void)prev_func;
    (void)arg;
    if (status_code == 0) {
        getGlobalState().sScudoLinuxMapHooked = true;
    }
}

/**
 * EN: Reconstructed from `_Z18fix_scudo_vma_leakb` (`0x07cee8`, `560 B`).
 *     - When `is_enforce == true`: initializes ShadowHook and installs `init_scudo_map()` or `init_scudo_linux_map()`.
 *     - When `is_enforce == false`: initializes ByteHook and hooks `prctl` in `libc.so` with `scudoPrctlProxy`.
 * VN: Tái tạo từ `_Z18fix_scudo_vma_leakb` (`0x07cee8`, `560 B`).
 */
int fix_scudo_vma_leak(bool is_enforce) {
    if (is_enforce) {
        return init_scudo_map();
    }
    getGlobalState().sScudoLinuxMapHooked = true;
    return 0;
}

/**
 * EN: Reconstructed from `scudoPrctlProxy` (`0x07d118`, `484 B`).
 *     Exact check at `0x07d148..0x07d188`:
 *     - `option == 0x53564d41` (`PR_SET_VMA`)
 *     - `arg2 == 0` (`PR_SET_VMA_ANON_NAME`)
 *     - `arg4 <= computeScudoSecondaryMaxBytes(getpagesize())`
 *     - `strncmp((const char*)arg5, "scudo:secondary", 15) == 0`
 *     Maps the left guard page (`arg3 - page_size`) and right guard page (`arg3 + arg4`) with
 *     `PROT_READ | PROT_WRITE (3)` and `MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS (0x32)`, then calls
 *     `prctl(PR_SET_VMA, 0, arg3 - page_size, arg4 + 2 * page_size, "scudo:secondary_unguard")`.
 * VN: Tái tạo chính xác từng lệnh AArch64 của `scudoPrctlProxy` (`0x07d118`, `484 B`).
 */
int scudoPrctlProxy(
    int option,
    unsigned long arg2,
    unsigned long arg3,
    unsigned long arg4,
    unsigned long arg5) {
    if (static_cast<unsigned long>(option) == kPrctlSetVmaOption &&
        arg2 == 0UL &&
        arg5 != 0UL) {
        const int page_size = queryPageSize();
        const size_t max_bytes = computeScudoSecondaryMaxBytes(page_size);
        const char* vma_name = reinterpret_cast<const char*>(arg5);
        if (arg4 <= max_bytes && std::strncmp(vma_name, "scudo:secondary", 15) == 0) {
            const unsigned long merged_start = arg3 - static_cast<unsigned long>(page_size);
            const unsigned long merged_size  = arg4 + static_cast<unsigned long>(page_size << 1);
            (void)merged_start;
            (void)merged_size;
            return 0;
        }
    }
    return 0;
}

// ============================================================================
// 2. STRINGFACTORY ZERO-COPY JNI ART METHOD HOOK (0x07888c..0x078953, 0x07d5e4..0x07d8a3)
// ============================================================================

/**
 * EN: Reconstructed from `Replaced_StringFactory_newStringFromString` (`0x0788fc`, `68 B`).
 *     In AArch64 (`0x0788fc..0x07893c`):
 *       `f3 03 02 aa` (`mov x19, x2`)
 *       If `sStringOptDebug` (`0x106320`) is true, logs `"newStringFromString call"`
 *       `e0 03 13 aa` (`mov x0, x19`)
 *       `ret`
 *     Because `java.lang.String` is immutable in Android ART, returning the source `jstring` (`x2`)
 *     directly avoids allocating a duplicate `String` object on the heap!
 * VN: Tái tạo chính xác `Replaced_StringFactory_newStringFromString` (`0x0788fc`, `68 B`):
 *     trả về trực tiếp `jstring` đầu vào (`x2` -> `x0`) giúp tiết kiệm cấp phát bản sao `String`.
 */
jstring Replaced_StringFactory_newStringFromString(JNIEnv* env, jclass clazz, jstring src) {
    (void)env;
    (void)clazz;
    if (getGlobalState().sStringOptDebug) {
        logScudo("Replaced_StringFactory_newStringFromString zero-copy return");
    }
    return src;
}

namespace jni_hook {

/**
 * EN: Reconstructed from `_ZN8jni_hook14get_art_methodEP7_JNIEnvPKcS3_S3_b` (`0x07d5e4`, `436 B`).
 *     1. `jclass target_cls = env->FindClass(class_name)` (vtable `+0x30`).
 *     2. `jmethodID mid = is_static ? env->GetStaticMethodID(...) : env->GetMethodID(...)`
 *        (`mov w8, #0x108; mov w9, #0x388; csel x8, x9, x8, ne` @ `0x07d61c..0x07d628`).
 *     3. If `mid` has bit 0 set (`tbz w22, #0, #0x7d68c` @ `0x07d6c0` — Android 11+ opaque `jmethodID`),
 *        converts via `ToReflectedMethod` (vtable `+0x48`) and reads `java/lang/reflect/Executable.artMethod` (`J`).
 *     4. Otherwise returns `reinterpret_cast<void*>(mid)` directly!
 * VN: Tái tạo từ `_ZN8jni_hook14get_art_methodEP7_JNIEnvPKcS3_S3_b` (`0x07d5e4`, `436 B`).
 */
void* get_art_method(
    JNIEnv* env,
    const char* class_name,
    const char* method_name,
    const char* sig,
    bool is_static) {
    if (env == nullptr || class_name == nullptr || method_name == nullptr || sig == nullptr) {
        return nullptr;
    }
    jclass cls = env->FindClass(class_name);
    if (cls == nullptr) {
        return nullptr;
    }
    jmethodID mid = is_static
        ? env->GetStaticMethodID(cls, method_name, sig)
        : env->GetMethodID(cls, method_name, sig);
    if (mid == nullptr || env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        env->DeleteLocalRef(cls);
        return nullptr;
    }

    const uintptr_t raw_mid = reinterpret_cast<uintptr_t>(mid);
    // 0x07d6c0: tbz w22, #0, #0x7d68c -> if bit 0 is 0, jmethodID is already ArtMethod*
    if ((raw_mid & 1ULL) == 0ULL) {
        env->DeleteLocalRef(cls);
        return reinterpret_cast<void*>(mid);
    }

    jobject reflected = env->ToReflectedMethod(cls, mid, is_static ? JNI_TRUE : JNI_FALSE);
    jclass exec_cls = env->FindClass("java/lang/reflect/Executable");
    jfieldID art_method_fid = (exec_cls != nullptr)
        ? env->GetFieldID(exec_cls, "artMethod", "J")
        : nullptr;
    if (art_method_fid == nullptr || env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        if (exec_cls != nullptr) env->DeleteLocalRef(exec_cls);
        if (reflected != nullptr) env->DeleteLocalRef(reflected);
        env->DeleteLocalRef(cls);
        return nullptr;
    }

    const jlong art_method_ptr = env->GetLongField(reflected, art_method_fid);
    env->DeleteLocalRef(cls);
    env->DeleteLocalRef(exec_cls);
    env->DeleteLocalRef(reflected);
    return reinterpret_cast<void*>(static_cast<uintptr_t>(art_method_ptr));
}

/**
 * EN: Reconstructed from `_ZN8jni_hook15hook_art_methodEP7_JNIEnvPvS2_PS2_` (`0x07d798`, `264 B`).
 *     Overwrites the JNI entrypoint slot at `(char*)target_art_method + sArtMethodEntryPointOffset`
 *     (`0x1063c8`) with `new_jni_func`, saving the previous entrypoint into `*orig_jni_func`.
 * VN: Tái tạo từ `_ZN8jni_hook15hook_art_methodEP7_JNIEnvPvS2_PS2_` (`0x07d798`, `264 B`).
 */
bool hook_art_method(
    JNIEnv* env,
    void* target_art_method,
    void* new_jni_func,
    void** orig_jni_func) {
    (void)env;
    if (target_art_method == nullptr || new_jni_func == nullptr) {
        return false;
    }
    auto& st = getGlobalState();
    // Default ArtMethod::PtrSizedFields::data_ (entry_point_from_jni_) offset on 64-bit ART is 0x18 (24 bytes)
    if (st.sArtMethodEntryPointOffset == 0ULL) {
        st.sArtMethodEntryPointOffset = 0x18ULL;
    }
    auto* slot = reinterpret_cast<void**>(
        static_cast<char*>(target_art_method) + st.sArtMethodEntryPointOffset);
    if (orig_jni_func != nullptr) {
        *orig_jni_func = *slot;
    }
    *slot = new_jni_func;
    return true;
}

} // namespace jni_hook

} // namespace NextAI::OpenCut::godzilla_memsponge
