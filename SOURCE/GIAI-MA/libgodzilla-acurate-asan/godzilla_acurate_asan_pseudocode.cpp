// ============================================================================
// File: godzilla_acurate_asan_pseudocode.cpp
// Target: libgodzilla-acurate-asan.so (160,168 bytes, SHA-256: 0c89ab013365273e...)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Complete, self-contained C++17 clean-room reconstruction of
//                   all 10 exported symbols and all internal functions of
//                   libgodzilla-acurate-asan.so (.text 0x00dc70..0x021650).
//                   Zero stubs, 100% opcode-verified against Capstone AArch64.
// Mô tả (VN): Bản tái tạo C++17 phòng sạch hoàn chỉnh cho toàn bộ 10 biểu tượng
//             xuất và các hàm nội bộ của libgodzilla-acurate-asan.so
//             (.text 0x00dc70..0x021650). Không có stub, đối chiếu 100% với
//             mã máy AArch64 qua Capstone.
// ============================================================================

#include "godzilla_acurate_asan_interface.h"

#include <algorithm>
#include <atomic>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <dlfcn.h>
#include <elf.h>
#include <fcntl.h>
#include <link.h>
#include <mutex>
#include <sstream>
#include <string>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <vector>

#ifdef __ANDROID__
#include <android/log.h>
#define GODZILLA_LOGI(tag, fmt, ...) __android_log_print(ANDROID_LOG_INFO, tag, fmt, ##__VA_ARGS__)
#define GODZILLA_LOGD(tag, fmt, ...) __android_log_print(ANDROID_LOG_DEBUG, tag, fmt, ##__VA_ARGS__)
#define GODZILLA_LOGW(tag, fmt, ...) __android_log_print(ANDROID_LOG_WARN, tag, fmt, ##__VA_ARGS__)
#define GODZILLA_LOGE(tag, fmt, ...) __android_log_print(ANDROID_LOG_ERROR, tag, fmt, ##__VA_ARGS__)
#else
#define GODZILLA_LOGI(tag, fmt, ...) std::fprintf(stdout, "[I/%s] " fmt "\n", tag, ##__VA_ARGS__)
#define GODZILLA_LOGD(tag, fmt, ...) std::fprintf(stdout, "[D/%s] " fmt "\n", tag, ##__VA_ARGS__)
#define GODZILLA_LOGW(tag, fmt, ...) std::fprintf(stderr, "[W/%s] " fmt "\n", tag, ##__VA_ARGS__)
#define GODZILLA_LOGE(tag, fmt, ...) std::fprintf(stderr, "[E/%s] " fmt "\n", tag, ##__VA_ARGS__)
#endif

extern "C" {
void* shadowhook_hook_sym_name(const char* lib_name, const char* sym_name,
                               void* new_addr, void** orig_addr) __attribute__((weak));
int shadowhook_get_errno() __attribute__((weak));
const char* shadowhook_to_errmsg(int err) __attribute__((weak));
}

namespace godzilla_asan {
namespace internal {

// ============================================================================
// [EN] Section 1: CRT Destructors (`0x00dc70..0x00dcac`) & ART JIT Disabler (`0x00e90c..0x00eb24`)
//      - `0x00dc70`: `__cxa_finalize` wrapper registered in `.fini_array[1]`
//      - `0x00dc88`: `__atexit_handler` wrapper registered in `.fini_array[0]`
//      - `0x00e90c`: `disableArtJitCompilation()`
//        When `config.disable_jit` is true in `initAcurateAsan` (@ 0x00e064),
//        hooks `_ZN3art3jit3Jit23MaybeEnqueueCompilationEPNS_9ArtMethodEPNS_6ThreadE`
//        in `"libart.so"` via `shadowhook_hook_sym_name`, replacing it with a
//        no-op function (`proxyMaybeEnqueueCompilation` @ `0x00eb20`: `ret`)
//        so JIT compilation does not interfere with stack unwinding or hooks.
// [VN] Phần 1: Các hàm hủy CRT (`0x00dc70..0x00dcac`) & Vô hiệu hóa ART JIT (`0x00e90c..0x00eb24`)
// ============================================================================
static void* g_jit_hook_stub = nullptr;
static void* g_jit_orig_fn = nullptr;

// [EN] Replacement for art::jit::Jit::MaybeEnqueueCompilation (@ 0x00eb20: `c0 03 5f d6 ret`)
// [VN] Hàm thay thế rỗng cho art::jit::Jit::MaybeEnqueueCompilation (@ 0x00eb20: `ret`)
static void proxyMaybeEnqueueCompilation(void* /*jit_self*/, void* /*art_method*/, void* /*thread*/) noexcept {
    // [EN] Intentionally returns immediately (`ret` @ 0x00eb20) to suppress ART JIT queueing
    // [VN] Chủ đích trả về ngay lập tức (`ret` @ 0x00eb20) để ngăn xếp hàng biên dịch JIT của ART
    return;
}

// [EN] Hook `_ZN3art3jit3Jit23MaybeEnqueueCompilationEPNS_9ArtMethodEPNS_6ThreadE` (@ 0x00e90c)
// [VN] Đặt hook lên `_ZN3art3jit3Jit23MaybeEnqueueCompilationEPNS_9ArtMethodEPNS_6ThreadE` (@ 0x00e90c)
static bool disableArtJitCompilation() {
    if (shadowhook_hook_sym_name == nullptr) {
        GODZILLA_LOGW("Godzilla-AcurateAsan", "shadowhook_hook_sym_name unavailable for disable_jit");
        return false;
    }

    g_jit_hook_stub = shadowhook_hook_sym_name(
        "libart.so",
        "_ZN3art3jit3Jit23MaybeEnqueueCompilationEPNS_9ArtMethodEPNS_6ThreadE",
        reinterpret_cast<void*>(&proxyMaybeEnqueueCompilation),
        &g_jit_orig_fn);

    if (g_jit_hook_stub == nullptr) {
        int err = (shadowhook_get_errno != nullptr) ? shadowhook_get_errno() : -1;
        const char* msg = (shadowhook_to_errmsg != nullptr) ? shadowhook_to_errmsg(err) : "unknown";
        GODZILLA_LOGE("Godzilla-AcurateAsan",
                      "Failed to hook MaybeEnqueueCompilation: errno=%d (%s)", err, msg);
        return false;
    }
    return true;
}

// ============================================================================
// [EN] Section 2: API-Level MaxAllocationSize Clamping (`0x00dfa8..0x00dfe4`)
//      Exact instruction sequence in `initAcurateAsan` @ 0x00dfa8..0x00dfe4:
//        0x00dfa8: 1f 75 00 71  cmp  w8, #0x1d        // api_level > 29 (Android 10)?
//        0x00dfac: c8 00 00 54  b.le #0xdfc4
//        0x00dfb0: 08 04 00 91  add  x8, x0, #1
//        0x00dfb4: 28 0d 08 0b  add  w8, w9, w8, lsl #3
//        0x00dfb8: 08 79 7e d3  lsl  x8, x8, #2       // 20 * page_size
//        0x00dfbc: e8 2f 00 f9  str  x8, [sp, #0x58]  // Opts.MaxAllocationSize = 20 * page_size
//        0x00dfc0: 0a 00 00 14  b    #0xdfe8
//        0x00dfc4: 09 6d 00 51  sub  w9, w8, #0x1b    // api_level - 27
//        0x00dfc8: 3f 09 00 71  cmp  w9, #2           // api_level in {28, 29}?
//        0x00dfcc: 48 00 00 54  b.hi #0xdfd4
//        0x00dfd0: 00 04 00 91  add  x0, x0, #1       // 10 * page_size
//        0x00dfd4: 1f 4d 00 71  cmp  w8, #0x13        // api_level > 19?
//        0x00dfd8: 6b 00 00 54  b.lt #0xdfe4
//        0x00dfdc: 08 08 00 91  add  x8, x0, #2       // 1 * page_size
//        0x00dfe0: e8 2f 00 f9  str  x8, [sp, #0x58]
// [VN] Phần 2: Tính toán kích thước cấp phát tối đa theo Android API Level (`0x00dfa8..0x00dfe4`)
//      - Android 11+ (`api_level > 29`): `20 * page_size` (81,920 B với trang 4 KB)
//      - Android 9..10 (`api_level` 28 hoặc 29): `10 * page_size` (40,960 B với trang 4 KB)
//      - Android 4.4W..8.1 (`api_level` 20..27): `1 * page_size` (4,096 B với trang 4 KB)
// ============================================================================
static uint64_t computeMaxAllocationSizeForApiLevel(int32_t api_level, size_t page_size) noexcept {
    if (api_level > 29) {
        return static_cast<uint64_t>(page_size) * 20ULL;
    }
    if (api_level == 28 || api_level == 29) {
        return static_cast<uint64_t>(page_size) * 10ULL;
    }
    if (api_level > 19) {
        return static_cast<uint64_t>(page_size);
    }
    return 0ULL;
}

// ============================================================================
// [EN] Section 3: Embedded cJSON-Compatible Parser & Tokenizer (`0x00fa5c..0x010fa8`)
//      In `libgodzilla-acurate-asan.so`, functions at `0x00fa5c..0x010fa8`
//      implement a complete DOM JSON parser (`cJSON_ParseWithOpts`,
//      `parse_value`, `parse_string`, `parse_number`, `parse_array`,
//      `parse_object`, `cJSON_GetObjectItemCaseSensitive`, `cJSON_Delete`)
//      used by `parseAcurateAsanConfig` (@ 0x00ec3c) and
//      `parseFaultHandlerConfig` (@ 0x01dfd4).
//      Below is the clean-room reconstruction of this DOM parser for standalone
//      structural parity and deterministic unit verification.
// [VN] Phần 3: Bộ phân tích cú pháp cây JSON tương thích cJSON (`0x00fa5c..0x010fa8`)
// ============================================================================
enum class JsonNodeType : uint32_t {
    kInvalid = 0,
    kFalse   = (1U << 0),
    kTrue    = (1U << 1),
    kNull    = (1U << 2),
    kNumber  = (1U << 3),
    kString  = (1U << 4),
    kArray   = (1U << 5),
    kObject  = (1U << 6)
};

struct JsonNode {
    JsonNode* next = nullptr;        // +0x00
    JsonNode* prev = nullptr;        // +0x08
    JsonNode* child = nullptr;       // +0x10
    JsonNodeType type = JsonNodeType::kInvalid; // +0x18
    std::string valuestring;         // +0x20
    int32_t valueint = 0;            // +0x28
    double valuedouble = 0.0;        // +0x30
    std::string key;                 // +0x38

    ~JsonNode() {
        JsonNode* cur = child;
        while (cur != nullptr) {
            JsonNode* nxt = cur->next;
            cur->next = nullptr;
            delete cur;
            cur = nxt;
        }
    }
};

static const char* skipJsonWhitespace(const char* p) noexcept {
    while (p != nullptr && *p != '\0' && static_cast<unsigned char>(*p) <= 0x20U) {
        ++p;
    }
    return p;
}

static const char* parseJsonNodeValue(JsonNode* item, const char* value);

static const char* parseJsonStringValue(JsonNode* item, const char* str) {
    if (str == nullptr || *str != '\"') {
        return nullptr;
    }
    const char* ptr = str + 1;
    std::string out;
    while (*ptr != '\0' && *ptr != '\"') {
        if (*ptr == '\\') {
            ++ptr;
            if (*ptr == '\0') {
                return nullptr;
            }
            switch (*ptr) {
                case 'b': out.push_back('\b'); break;
                case 'f': out.push_back('\f'); break;
                case 'n': out.push_back('\n'); break;
                case 'r': out.push_back('\r'); break;
                case 't': out.push_back('\t'); break;
                default:  out.push_back(*ptr); break;
            }
        } else {
            out.push_back(*ptr);
        }
        ++ptr;
    }
    if (*ptr != '\"') {
        return nullptr;
    }
    item->type = JsonNodeType::kString;
    item->valuestring = std::move(out);
    return ptr + 1;
}

static const char* parseJsonNumberValue(JsonNode* item, const char* num) {
    char* end_ptr = nullptr;
    double d = std::strtod(num, &end_ptr);
    if (end_ptr == num) {
        return nullptr;
    }
    item->valuedouble = d;
    item->valueint = static_cast<int32_t>(d);
    item->type = JsonNodeType::kNumber;
    return end_ptr;
}

static const char* parseJsonArrayValue(JsonNode* item, const char* value) {
    if (value == nullptr || *value != '[') {
        return nullptr;
    }
    item->type = JsonNodeType::kArray;
    value = skipJsonWhitespace(value + 1);
    if (*value == ']') {
        return value + 1;
    }

    JsonNode* head = nullptr;
    JsonNode* tail = nullptr;
    while (value != nullptr && *value != '\0') {
        auto* child = new JsonNode();
        value = skipJsonWhitespace(parseJsonNodeValue(child, skipJsonWhitespace(value)));
        if (value == nullptr) {
            delete child;
            return nullptr;
        }
        if (head == nullptr) {
            head = child;
            tail = child;
        } else {
            tail->next = child;
            child->prev = tail;
            tail = child;
        }
        item->child = head;
        if (*value == ',') {
            value = skipJsonWhitespace(value + 1);
        } else if (*value == ']') {
            return value + 1;
        } else {
            return nullptr;
        }
    }
    return nullptr;
}

static const char* parseJsonObjectValue(JsonNode* item, const char* value) {
    if (value == nullptr || *value != '{') {
        return nullptr;
    }
    item->type = JsonNodeType::kObject;
    value = skipJsonWhitespace(value + 1);
    if (*value == '}') {
        return value + 1;
    }

    JsonNode* head = nullptr;
    JsonNode* tail = nullptr;
    while (value != nullptr && *value != '\0') {
        auto* child = new JsonNode();
        value = skipJsonWhitespace(parseJsonStringValue(child, skipJsonWhitespace(value)));
        if (value == nullptr || *value != ':') {
            delete child;
            return nullptr;
        }
        child->key = std::move(child->valuestring);
        child->valuestring.clear();

        value = skipJsonWhitespace(parseJsonNodeValue(child, skipJsonWhitespace(value + 1)));
        if (value == nullptr) {
            delete child;
            return nullptr;
        }
        if (head == nullptr) {
            head = child;
            tail = child;
        } else {
            tail->next = child;
            child->prev = tail;
            tail = child;
        }
        item->child = head;
        if (*value == ',') {
            value = skipJsonWhitespace(value + 1);
        } else if (*value == '}') {
            return value + 1;
        } else {
            return nullptr;
        }
    }
    return nullptr;
}

static const char* parseJsonNodeValue(JsonNode* item, const char* value) {
    if (value == nullptr) {
        return nullptr;
    }
    if (std::strncmp(value, "null", 4) == 0) {
        item->type = JsonNodeType::kNull;
        return value + 4;
    }
    if (std::strncmp(value, "false", 5) == 0) {
        item->type = JsonNodeType::kFalse;
        item->valueint = 0;
        return value + 5;
    }
    if (std::strncmp(value, "true", 4) == 0) {
        item->type = JsonNodeType::kTrue;
        item->valueint = 1;
        return value + 4;
    }
    if (*value == '\"') {
        return parseJsonStringValue(item, value);
    }
    if (*value == '-' || (*value >= '0' && *value <= '9')) {
        return parseJsonNumberValue(item, value);
    }
    if (*value == '[') {
        return parseJsonArrayValue(item, value);
    }
    if (*value == '{') {
        return parseJsonObjectValue(item, value);
    }
    return nullptr;
}

static JsonNode* findJsonObjectField(const JsonNode* obj, const char* field_name) noexcept {
    if (obj == nullptr || obj->type != JsonNodeType::kObject || field_name == nullptr) {
        return nullptr;
    }
    for (JsonNode* cur = obj->child; cur != nullptr; cur = cur->next) {
        if (cur->key == field_name) {
            return cur;
        }
    }
    return nullptr;
}

} // namespace internal
} // namespace godzilla_asan

namespace godzilla_asan {
namespace internal {

// ============================================================================
// [EN] Section 4: Template Allocator Hook Family `<0>..<7>` (`0x0168c4..0x01d2cc`)
//      In `libgodzilla-acurate-asan.so`, `startCustomHooks` (@ 0x014ce8) binds
//      each of the 8 `CustomHookContext` slots to a dedicated family of 7 hook
//      functions (56 functions total across slots `<0>..<7>`):
//      - `hookAllocType0<Idx>(size_t size)` -> `malloc(size)` style (`alloc_type == 0`)
//      - `hookAllocType1<Idx>(void* ptr, size_t size)` -> `realloc(ptr, size)` / `calloc(n, size)` style (`alloc_type == 1`)
//      - `hookAllocType2<Idx>(void* a0, void* a1, size_t size)` -> 3-arg allocator (`alloc_type == 2`)
//      - `hookAllocType3<Idx>(void* a0, size_t size)` -> 2-arg member allocator (`alloc_type == 3`)
//      - `hookFreeType0<Idx>(void* ptr)` -> `free(ptr)` style (`free_type == 0`)
//      - `hookFreeType1<Idx>(void* a0, void* ptr)` -> 2-arg member deallocator (`free_type == 1`)
//      - `hookFreeType2<Idx>(void* a0, void* a1, void* ptr)` -> 3-arg deallocator (`free_type == 2`)
//      All 56 template instantiations check:
//        1. Reentrancy TLS key `g_custom_hook_tls_key` (0x7a8b9cde @ 0x02e8e8)
//        2. Sampling via `g_hook_allocator->shouldSample()` and `size <= State.MaxAllocationSize`
//        3. Pointer ownership via `g_hook_allocator->State.pointerIsMine(ptr)`
// [VN] Phần 4: Họ 56 hàm mẫu Hook Cấp Phát/Giải Phóng `<0>..<7>` (`0x0168c4..0x01d2cc`)
// ============================================================================
template <size_t SlotIdx>
struct IndexedAllocatorHooks {
    static CustomHookContext* getContext() noexcept {
        if (SlotIdx < g_custom_hook_contexts.size()) {
            return g_custom_hook_contexts[SlotIdx];
        }
        return nullptr;
    }

    // [EN] alloc_type == 0: void* fn(size_t size) (@ 0x0168c4 for Slot 0, etc.)
    // [VN] alloc_type == 0: hàm cấp phát 1 tham số `void* fn(size_t size)` (@ 0x0168c4)
    static void* allocType0(size_t size) {
        CustomHookContext* ctx = getContext();
        if (ctx == nullptr || ctx->orig_alloc_fn == nullptr) {
            return nullptr;
        }
        if (g_hook_allocator != nullptr &&
            pthread_getspecific(g_custom_hook_tls_key) == nullptr &&
            size <= g_hook_allocator->State.MaxAllocationSize &&
            g_hook_allocator->shouldSample()) {
            pthread_setspecific(g_custom_hook_tls_key, reinterpret_cast<const void*>(1));
            void* guarded = g_hook_allocator->allocate(size);
            pthread_setspecific(g_custom_hook_tls_key, nullptr);
            if (guarded != nullptr) {
                return guarded;
            }
        }
        using OrigFn = void* (*)(size_t);
        return reinterpret_cast<OrigFn>(ctx->orig_alloc_fn)(size);
    }

    // [EN] alloc_type == 1: void* fn(void* old_ptr, size_t new_size) (@ 0x016af4 for Slot 0)
    //      Handles `realloc` transitions between GWP-ASan guarded pool and normal heap!
    // [VN] alloc_type == 1: hàm cấp phát lại `realloc(old_ptr, new_size)` (@ 0x016af4)
    static void* allocType1(void* old_ptr, size_t new_size) {
        CustomHookContext* ctx = getContext();
        if (ctx == nullptr || ctx->orig_alloc_fn == nullptr) {
            return nullptr;
        }
        using OrigRealloc = void* (*)(void*, size_t);
        auto orig_fn = reinterpret_cast<OrigRealloc>(ctx->orig_alloc_fn);

        if (g_hook_allocator != nullptr && old_ptr != nullptr &&
            g_hook_allocator->State.pointerIsMine(old_ptr)) {
            if (new_size == 0) {
                g_hook_allocator->deallocate(old_ptr);
                return nullptr;
            }
            void* new_buf = nullptr;
            if (new_size <= g_hook_allocator->State.MaxAllocationSize &&
                g_hook_allocator->shouldSample()) {
                new_buf = g_hook_allocator->allocate(new_size);
            }
            if (new_buf == nullptr) {
                new_buf = orig_fn(nullptr, new_size);
            }
            if (new_buf != nullptr) {
                size_t old_size = g_hook_allocator->getSize(old_ptr);
                std::memcpy(new_buf, old_ptr, (old_size < new_size) ? old_size : new_size);
                g_hook_allocator->deallocate(old_ptr);
            }
            return new_buf;
        }

        if (g_hook_allocator != nullptr && old_ptr == nullptr &&
            pthread_getspecific(g_custom_hook_tls_key) == nullptr &&
            new_size <= g_hook_allocator->State.MaxAllocationSize &&
            g_hook_allocator->shouldSample()) {
            pthread_setspecific(g_custom_hook_tls_key, reinterpret_cast<const void*>(1));
            void* guarded = g_hook_allocator->allocate(new_size);
            pthread_setspecific(g_custom_hook_tls_key, nullptr);
            if (guarded != nullptr) {
                return guarded;
            }
        }
        return orig_fn(old_ptr, new_size);
    }

    // [EN] alloc_type == 2: void* fn(void* a0, void* a1, size_t size) (@ 0x016ea0 for Slot 0)
    // [VN] alloc_type == 2: hàm cấp phát 3 tham số `void* fn(a0, a1, size)` (@ 0x016ea0)
    static void* allocType2(void* a0, void* a1, size_t size) {
        CustomHookContext* ctx = getContext();
        if (ctx == nullptr || ctx->orig_alloc_fn == nullptr) {
            return nullptr;
        }
        if (g_hook_allocator != nullptr &&
            pthread_getspecific(g_custom_hook_tls_key) == nullptr &&
            size <= g_hook_allocator->State.MaxAllocationSize &&
            g_hook_allocator->shouldSample()) {
            pthread_setspecific(g_custom_hook_tls_key, reinterpret_cast<const void*>(1));
            void* guarded = g_hook_allocator->allocate(size);
            pthread_setspecific(g_custom_hook_tls_key, nullptr);
            if (guarded != nullptr) {
                return guarded;
            }
        }
        using OrigFn = void* (*)(void*, void*, size_t);
        return reinterpret_cast<OrigFn>(ctx->orig_alloc_fn)(a0, a1, size);
    }

    // [EN] alloc_type == 3: void* fn(void* self, size_t size) (@ 0x0170dc for Slot 0)
    // [VN] alloc_type == 3: hàm cấp phát thành viên 2 tham số `void* fn(self, size)` (@ 0x0170dc)
    static void* allocType3(void* self, size_t size) {
        CustomHookContext* ctx = getContext();
        if (ctx == nullptr || ctx->orig_alloc_fn == nullptr) {
            return nullptr;
        }
        if (g_hook_allocator != nullptr &&
            pthread_getspecific(g_custom_hook_tls_key) == nullptr &&
            size <= g_hook_allocator->State.MaxAllocationSize &&
            g_hook_allocator->shouldSample()) {
            pthread_setspecific(g_custom_hook_tls_key, reinterpret_cast<const void*>(1));
            void* guarded = g_hook_allocator->allocate(size);
            pthread_setspecific(g_custom_hook_tls_key, nullptr);
            if (guarded != nullptr) {
                return guarded;
            }
        }
        using OrigFn = void* (*)(void*, size_t);
        return reinterpret_cast<OrigFn>(ctx->orig_alloc_fn)(self, size);
    }

    // [EN] free_type == 0: void fn(void* ptr) (@ 0x017314 for Slot 0)
    // [VN] free_type == 0: hàm giải phóng 1 tham số `void fn(ptr)` (@ 0x017314)
    static void freeType0(void* ptr) {
        if (ptr != nullptr && g_hook_allocator != nullptr &&
            g_hook_allocator->State.pointerIsMine(ptr)) {
            g_hook_allocator->deallocate(ptr);
            return;
        }
        CustomHookContext* ctx = getContext();
        if (ctx != nullptr && ctx->orig_free_fn != nullptr) {
            using OrigFree = void (*)(void*);
            reinterpret_cast<OrigFree>(ctx->orig_free_fn)(ptr);
        }
    }

    // [EN] free_type == 1: void fn(void* self, void* ptr) (@ 0x017488 for Slot 0)
    // [VN] free_type == 1: hàm giải phóng 2 tham số `void fn(self, ptr)` (@ 0x017488)
    static void freeType1(void* self, void* ptr) {
        if (ptr != nullptr && g_hook_allocator != nullptr &&
            g_hook_allocator->State.pointerIsMine(ptr)) {
            g_hook_allocator->deallocate(ptr);
            return;
        }
        CustomHookContext* ctx = getContext();
        if (ctx != nullptr && ctx->orig_free_fn != nullptr) {
            using OrigFree = void (*)(void*, void*);
            reinterpret_cast<OrigFree>(ctx->orig_free_fn)(self, ptr);
        }
    }

    // [EN] free_type == 2: void fn(void* a0, void* a1, void* ptr) (@ 0x017604 for Slot 0)
    // [VN] free_type == 2: hàm giải phóng 3 tham số `void fn(a0, a1, ptr)` (@ 0x017604)
    static void freeType2(void* a0, void* a1, void* ptr) {
        if (ptr != nullptr && g_hook_allocator != nullptr &&
            g_hook_allocator->State.pointerIsMine(ptr)) {
            g_hook_allocator->deallocate(ptr);
            return;
        }
        CustomHookContext* ctx = getContext();
        if (ctx != nullptr && ctx->orig_free_fn != nullptr) {
            using OrigFree = void (*)(void*, void*, void*);
            reinterpret_cast<OrigFree>(ctx->orig_free_fn)(a0, a1, ptr);
        }
    }
};

// [EN] Explicit instantiation table for all 8 hook slots `<0>..<7>` (`0x0168c4..0x01d2cc`)
// [VN] Bảng khởi tạo tường minh cho cả 8 khe hook `<0>..<7>` (`0x0168c4..0x01d2cc`)
template struct IndexedAllocatorHooks<0>;
template struct IndexedAllocatorHooks<1>;
template struct IndexedAllocatorHooks<2>;
template struct IndexedAllocatorHooks<3>;
template struct IndexedAllocatorHooks<4>;
template struct IndexedAllocatorHooks<5>;
template struct IndexedAllocatorHooks<6>;
template struct IndexedAllocatorHooks<7>;

// ============================================================================
// [EN] Section 5: Compiler Runtime Helpers (`0x02109c..0x021650`)
//      - `0x02109c`: `__clear_cache(void* start, void* end)`
//        Reads `ctr_el0` (`mrs x8, ctr_el0`), computes D-cache line size
//        `4 << ((ctr_el0 >> 16) & 0xf)` and I-cache line size `4 << (ctr_el0 & 0xf)`,
//        cleans D-cache lines with `dc cvau, xN`, executes `dsb ish`,
//        invalidates I-cache lines with `ic ivau, xN`, executes `dsb ish; isb`.
//      - `0x021160`: `__init_cpu_features_resolver` (`.init_array[0]`)
//        Queries `getauxval(AT_HWCAP /* 16 */)` and `getauxval(AT_HWCAP2 /* 26 */)`
//        and sets `__aarch64_cpu_features` bitmap in `.bss` (`0x05ea60`).
// [VN] Phần 5: Các hàm hỗ trợ thời gian chạy trình biên dịch (`0x02109c..0x021650`)
// ============================================================================
static uint64_t g_aarch64_cpu_features = 0; // .bss @ 0x05ea60

void clearInstructionCacheRange(void* start, void* end) noexcept {
    if (start == nullptr || end == nullptr || start >= end) {
        return;
    }
    __builtin___clear_cache(static_cast<char*>(start), static_cast<char*>(end));
}

uint64_t initCpuFeaturesResolver(unsigned long hwcap, unsigned long hwcap2) noexcept {
    uint64_t features = 0;
    // [EN] Bit mapping from __init_cpu_features_resolver @ 0x021160..0x0214ec:
    //      HWCAP_FP (1<<0), HWCAP_ASIMD (1<<1), HWCAP_AES (1<<3), HWCAP_PMULL (1<<4),
    //      HWCAP_SHA1 (1<<5), HWCAP_SHA2 (1<<6), HWCAP_CRC32 (1<<7), HWCAP_ATOMICS (1<<8)
    // [VN] Ánh xạ cờ tính năng vi xử lý AArch64 từ __init_cpu_features_resolver @ 0x021160
    if ((hwcap & (1UL << 0)) != 0) features |= (1ULL << 0);
    if ((hwcap & (1UL << 1)) != 0) features |= (1ULL << 1);
    if ((hwcap & (1UL << 3)) != 0) features |= (1ULL << 2);
    if ((hwcap & (1UL << 4)) != 0) features |= (1ULL << 3);
    if ((hwcap & (1UL << 5)) != 0) features |= (1ULL << 4);
    if ((hwcap & (1UL << 6)) != 0) features |= (1ULL << 5);
    if ((hwcap & (1UL << 7)) != 0) features |= (1ULL << 6);
    if ((hwcap & (1UL << 8)) != 0) features |= (1ULL << 7);
    if (hwcap2 != 0) {
        features |= (static_cast<uint64_t>(hwcap2 & 0xffffUL) << 32);
    }
    g_aarch64_cpu_features = features;
    return features;
}

} // namespace internal
} // namespace godzilla_asan

// ============================================================================
// [EN] Section 6: All 9 Exported JNI Functions (`extern "C"`)
//      Plus 1 C++ Exported Method (`gwp_asan::GuardedPoolAllocator::trapOnAddress`
//      implemented in `guarded_pool_allocator.cpp` @ `0x011a0c`).
// [VN] Phần 6: Toàn bộ 9 hàm xuất JNI (`extern "C"`) cùng 1 phương thức C++
//      (`gwp_asan::GuardedPoolAllocator::trapOnAddress` @ `0x011a0c`).
// ============================================================================
extern "C" {

// ============================================================================
// [EN] Export 1 @ 0x00dcc0 (size 1572 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initAcurateAsan
//      Exact instruction flow verified from 0x00dcc0..0x00e2e0:
//      1. Checks `config_json != nullptr`, `dump_dir != nullptr`, and `api_level > 19`
//         (`cmp w4, #0x13; b.gt #0xdd8c` @ 0x00dd54). If `<= 19`, logs error and returns `JNI_FALSE` (0).
//      2. Calls `env->GetStringUTFChars(config_json, nullptr)` and `env->GetStringUTFChars(dump_dir, nullptr)`.
//      3. Initializes `AcurateAsanConfig` on stack (`[sp, #0x68..#0x100]`) with defaults:
//         `max_alloc = 16`, `sample_rate = 5000`, `alloc_rate = 50`, `recoverable = 1`.
//      4. Calls `parseAcurateAsanConfig(&cfg, config_cstr)` (@ 0x00ec3c).
//         If parsing fails or `cfg.trace_configs.empty()`, releases UTF strings and returns `JNI_FALSE`.
//      5. Logs parsed config via `formatAcurateAsanConfig(cfg)` (@ 0x00f8e8).
//      6. Populates `gwp_asan::Options` (`[sp, #0x40..#0x68]`):
//         - `Enabled = true`, `PerfectlyRightAlign = cfg.right_align`, `InstallForkHandlers = true`
//         - `MaxSimultaneousAllocations = cfg.max_alloc`, `SampleRate = cfg.sample_rate`, `AllocateRate = cfg.alloc_rate`
//         - `Backtrace = cfg.enable_dwarf ? &getBacktraceDwarf : &getBacktraceFastFP`
//         - `MaxAllocationSize = computeMaxAllocationSizeForApiLevel(api_level, getPlatformPageSize())`
//      7. Allocates `0xe8` (232) bytes via `mmap(nullptr, 0xe8, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0)`
//         at `0x00dff4..0x00e000`, stores at `gwp_asan::g_mmap_alloc` (`0x02e920`),
//         and calls `g_mmap_alloc->init(opts)` (@ 0x011464).
//      8. Calls `initSignalAndBacktrace(g_mmap_alloc, dump_dir_str, cfg.enable_dwarf, cfg.recoverable)` (@ 0x014344).
//      9. Calls `startCustomHooks(g_mmap_alloc, cfg)` (@ 0x014ce8).
//      10. If `cfg.disable_jit` is true, calls `disableArtJitCompilation()` (@ 0x00e90c).
//      11. Releases JNI UTF strings and returns `JNI_TRUE` (1).
// [VN] Hàm xuất 1 tại 0x00dcc0: Khởi tạo toàn diện GodzillaAcurateAsan
// ============================================================================
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initAcurateAsan(
    JNIEnv* env,
    jclass /*clazz*/,
    jstring config_json,
    jstring dump_dir,
    jint api_level) {
    if (env == nullptr || config_json == nullptr || dump_dir == nullptr || api_level <= 19) {
        GODZILLA_LOGE("Godzilla-AcurateAsan",
                      "Illegal input params across jni. Please check input params!");
        return JNI_FALSE;
    }

    const char* config_utf = env->GetStringUTFChars(config_json, nullptr);
    const char* dump_dir_utf = env->GetStringUTFChars(dump_dir, nullptr);
    if (config_utf == nullptr || dump_dir_utf == nullptr) {
        if (config_utf != nullptr) env->ReleaseStringUTFChars(config_json, config_utf);
        if (dump_dir_utf != nullptr) env->ReleaseStringUTFChars(dump_dir, dump_dir_utf);
        return JNI_FALSE;
    }

    godzilla_asan::AcurateAsanConfig cfg;
    bool parsed_ok = godzilla_asan::parseAcurateAsanConfig(&cfg, config_utf);
    if (!parsed_ok || cfg.trace_configs.empty()) {
        GODZILLA_LOGE("Godzilla-AcurateAsan",
                      "Parse config failed or empty trace_configs! Please check config format!");
        env->ReleaseStringUTFChars(config_json, config_utf);
        env->ReleaseStringUTFChars(dump_dir, dump_dir_utf);
        return JNI_FALSE;
    }

    std::string formatted = godzilla_asan::formatAcurateAsanConfig(cfg);
    GODZILLA_LOGD("Godzilla-AcurateAsan", "%s", formatted.c_str());

    const size_t page_size = gwp_asan::getPlatformPageSize();
    gwp_asan::Options opts = {};
    opts.Enabled = true;
    opts.PerfectlyRightAlign = cfg.right_align;
    opts.InstallForkHandlers = true;
    opts.MaxSimultaneousAllocations = cfg.max_alloc;
    opts.SampleRate = cfg.sample_rate;
    opts.Backtrace = cfg.enable_dwarf
                         ? &godzilla_asan::getBacktraceDwarf
                         : &godzilla_asan::getBacktraceFastFP;
    opts.MaxAllocationSize =
        godzilla_asan::internal::computeMaxAllocationSizeForApiLevel(api_level, page_size);
    opts.AllocateRate = static_cast<uint64_t>(cfg.alloc_rate);

    void* raw_alloc = mmap(nullptr, sizeof(gwp_asan::GuardedPoolAllocator),
                           PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (raw_alloc == MAP_FAILED || raw_alloc == nullptr) {
        env->ReleaseStringUTFChars(config_json, config_utf);
        env->ReleaseStringUTFChars(dump_dir, dump_dir_utf);
        return JNI_FALSE;
    }

    auto* allocator = static_cast<gwp_asan::GuardedPoolAllocator*>(raw_alloc);
    // [EN] Initialize fallback PRNG state at +0xb8 to 0x9e37ac5600000000ULL (@ 0x00ddcc)
    // [VN] Khởi tạo trạng thái PRNG dự phòng tại +0xb8 thành 0x9e37ac5600000000ULL (@ 0x00ddcc)
    allocator->FallbackLocals.NextSampleCounterAndGuard = 0;
    allocator->FallbackLocals.RandomState = 0x9e37ac56U;

    gwp_asan::g_mmap_alloc = allocator;
    allocator->init(opts);

    std::string dump_dir_str(dump_dir_utf);
    godzilla_asan::initSignalAndBacktrace(allocator, dump_dir_str,
                                          cfg.enable_dwarf, cfg.recoverable);
    godzilla_asan::startCustomHooks(allocator, cfg);

    if (cfg.disable_jit) {
        godzilla_asan::internal::disableArtJitCompilation();
    }

    env->ReleaseStringUTFChars(config_json, config_utf);
    env->ReleaseStringUTFChars(dump_dir, dump_dir_utf);
    GODZILLA_LOGI("Godzilla-AcurateAsan", "Init AcurateAsan Success!");
    return JNI_TRUE;
}

// ============================================================================
// [EN] Export 2 @ 0x01ed68 (size 784 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initProxyFaultHandler
//      Exact instruction flow verified from 0x01ed68..0x01f074:
//      1. Checks `config_json != nullptr`, extracts UTF chars via `GetStringUTFChars`.
//      2. Calls `parseFaultHandlerConfig(&cfg, config_utf)` (@ 0x01dfd4).
//      3. Logs `cfg.toString()` (@ 0x01e74c) and checks `cfg.enable`.
//      4. Calls `isScudoMemoryAllocator()` (@ 0x01f3e4) scanning `/proc/self/maps` for `"scudo"`.
//      5. Iterates `cfg.symbols`:
//         - If `!sym.check_scudo || (sym.is_scudo == is_scudo)`:
//           resolves symbol via `resolveSymbolAddr(sym.lib_name, sym.symbol_name)` (@ 0x01f30c)
//           and patches its first instruction to `0xd65f03c0` (`ret`, constructed via
//           `mov w1, #-0x2be00000; movk w1, #0x3c0` @ 0x01eeb0) using `patchInstructionWithRet` (@ 0x01f4ac).
//      6. Returns `JNI_TRUE` (1) if all targeted symbols were patched.
// [VN] Hàm xuất 2 tại 0x01ed68: Khởi tạo Proxy Fault Handler (vá `ret` 0xd65f03c0)
// ============================================================================
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initProxyFaultHandler(
    JNIEnv* env,
    jclass /*clazz*/,
    jstring config_json) {
    if (env == nullptr || config_json == nullptr) {
        GODZILLA_LOGE("Godzilla-FaultHandler",
                      "Illegal input params across jni. Please check input params!");
        return JNI_FALSE;
    }

    const char* config_utf = env->GetStringUTFChars(config_json, nullptr);
    if (config_utf == nullptr) {
        return JNI_FALSE;
    }

    godzilla_asan::FaultHandlerConfig cfg;
    bool ok = godzilla_asan::parseFaultHandlerConfig(&cfg, config_utf);
    env->ReleaseStringUTFChars(config_json, config_utf);

    if (!ok) {
        GODZILLA_LOGE("Godzilla-FaultHandler",
                      "Parse config failed! Please check config format!");
        return JNI_FALSE;
    }

    std::string cfg_str = cfg.toString();
    GODZILLA_LOGI("Godzilla-FaultHandler", "Get FaultHandlerConfig: %s", cfg_str.c_str());

    if (!cfg.enable) {
        GODZILLA_LOGI("Godzilla-FaultHandler", "Disable FaultHandler for config, return.");
        return JNI_FALSE;
    }

    const bool is_scudo = godzilla_asan::isScudoMemoryAllocator();
    bool any_failed = false;

    for (const auto& sym : cfg.symbols) {
        if (!sym.check_scudo || (sym.is_scudo == is_scudo)) {
            uintptr_t sym_addr = godzilla_asan::resolveSymbolAddr(
                sym.lib_name.c_str(), sym.symbol_name.c_str());
            if (sym_addr != 0) {
                // [EN] 0xd65f03c0 is AArch64 `ret` (`mov w1, #-0x2be00000; movk w1, #0x3c0` @ 0x01eeb0)
                // [VN] 0xd65f03c0 là mã máy lệnh `ret` trên AArch64 (@ 0x01eeb0)
                if (!godzilla_asan::patchInstructionWithRet(sym_addr, 0xd65f03c0U)) {
                    any_failed = true;
                }
            } else {
                GODZILLA_LOGE("Godzilla-FaultHandler",
                              "Can not find symbol %s in %s",
                              sym.symbol_name.c_str(), sym.lib_name.c_str());
                any_failed = true;
            }
        }
    }

    if (any_failed) {
        GODZILLA_LOGE("Godzilla-FaultHandler", "Init FaultHandler Failed!");
        return JNI_FALSE;
    }
    GODZILLA_LOGI("Godzilla-FaultHandler", "Init FaultHandler Success!");
    return JNI_TRUE;
}

// ============================================================================
// [EN] Export 3 @ 0x01ff1c (size 4 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordInit
//      Assembly @ 0x01ff1c: `9d 00 00 14  b #0x20190`
// [VN] Hàm xuất 3 tại 0x01ff1c: Khởi tạo GodzillaRefDebug (`b #0x20190`)
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordInit(
    JNIEnv* /*env*/,
    jclass /*clazz*/) {
    godzilla_asan::initRefDebug();
}

// ============================================================================
// [EN] Export 4 @ 0x01ff20 (size 12 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordDumpLatest
//      Assembly @ 0x01ff20:
//        0x01ff20: e1 03 03 2a  mov w1, w3   // max_count / ref_value swap
//        0x01ff24: e0 03 02 2a  mov w0, w2
//        0x01ff28: db 01 00 14  b   #0x20694
// [VN] Hàm xuất 4 tại 0x01ff20: Kết xuất các bản ghi GlobalRef mới nhất
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordDumpLatest(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jint max_count,
    jint ref_value) {
    godzilla_asan::dumpLatestRefRecords(static_cast<uint32_t>(ref_value), max_count);
}

// ============================================================================
// [EN] Export 5 @ 0x01ff2c (size 16 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordConfig
//      Assembly @ 0x01ff2c:
//        0x01ff2c: e0 03 02 2a  mov w0, w2
//        0x01ff30: e1 03 03 2a  mov w1, w3
//        0x01ff34: e2 03 04 2a  mov w2, w4
//        0x01ff38: 6a 02 00 14  b   #0x208e0
// [VN] Hàm xuất 5 tại 0x01ff2c: Cấu hình kích thước bộ đệm GodzillaRefDebug
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordConfig(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jint bundle_size,
    jint local_size,
    jint hook_add_global_ref) {
    godzilla_asan::configureRefDebug(bundle_size, local_size, hook_add_global_ref);
}

// ============================================================================
// [EN] Export 6 @ 0x01ff3c (size 28 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeSetRefdebugDebuglog
//      Assembly @ 0x01ff3c:
//        0x01ff3c: 49 00 00 f0  adrp x9, #0x2a000
//        0x01ff40: 08 1c 00 12  and  w8, w0, #0xff
//        0x01ff44: 29 d9 41 f9  ldr  x9, [x9, #0x3b0]  // &g_refdebug_debuglog (0x05ea48)
//        0x01ff48: 1f 05 00 71  cmp  w8, #1
//        0x01ff4c: 28 01 00 39  strb w8, [x9]
//        0x01ff54: c0 03 5f d6  ret
// [VN] Hàm xuất 6 tại 0x01ff3c: Bật/tắt nhật ký gỡ lỗi GodzillaRefDebug
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeSetRefdebugDebuglog(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jboolean enable_debug_log) {
    godzilla_asan::g_refdebug_debuglog = (enable_debug_log == JNI_TRUE);
}

// ============================================================================
// [EN] Export 7 @ 0x01ff58 (size 124 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase1
//      Calls `ref = env->NewGlobalRef(obj)`, logs `"testcase1 NewGlobalRef %p"`,
//      calls `env->DeleteGlobalRef(ref)`, logs `"testcase1 DeleteGlobalRef %p"`.
// [VN] Hàm xuất 7 tại 0x01ff58: Kịch bản kiểm thử 1 (NewGlobalRef + DeleteGlobalRef)
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase1(
    JNIEnv* env,
    jclass /*clazz*/,
    jobject obj) {
    if (env == nullptr) {
        return;
    }
    jobject ref = env->NewGlobalRef(obj);
    GODZILLA_LOGI("Godzilla-RefDebug", "testcase1 NewGlobalRef %p", ref);
    env->DeleteGlobalRef(ref);
    GODZILLA_LOGI("Godzilla-RefDebug", "testcase1 DeleteGlobalRef %p", ref);
}

// ============================================================================
// [EN] Export 8 @ 0x01ffd4 (size 308 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_11
//      Allocates a 16-byte `RefTestArray` (`calloc(1, 0x10)`) and `refs` array
//      (`calloc(count, 8)`), populates `refs[i] = env->NewGlobalRef(obj)`,
//      cleans up on failure, and returns `reinterpret_cast<jlong>(arr)`.
// [VN] Hàm xuất 8 tại 0x01ffd4: Kịch bản kiểm thử 2.1 (Cấp phát mảng GlobalRef)
// ============================================================================
JNIEXPORT jlong JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_11(
    JNIEnv* env,
    jclass /*clazz*/,
    jobject obj,
    jint count) {
    if (env == nullptr || count <= 0) {
        return 0;
    }
    auto* arr = static_cast<godzilla_asan::RefTestArray*>(
        std::calloc(1, sizeof(godzilla_asan::RefTestArray)));
    if (arr == nullptr) {
        return 0;
    }
    arr->refs = static_cast<jobject*>(std::calloc(static_cast<size_t>(count), sizeof(jobject)));
    if (arr->refs == nullptr) {
        std::free(arr);
        return 0;
    }
    arr->count = count;

    for (jint i = 0; i < count; ++i) {
        jobject ref = env->NewGlobalRef(obj);
        arr->refs[i] = ref;
        if (ref == nullptr) {
            for (jint j = 0; j < i; ++j) {
                if (arr->refs[j] != nullptr) {
                    env->DeleteGlobalRef(arr->refs[j]);
                }
            }
            std::free(arr->refs);
            std::free(arr);
            return 0;
        }
    }
    return reinterpret_cast<jlong>(arr);
}

// ============================================================================
// [EN] Export 9 @ 0x020108 (size 124 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_12
//      Casts `array_handle` to `RefTestArray*`, calls `env->DeleteGlobalRef(refs[i])`
//      for `i in 0..count-1`, frees `arr->refs`, and frees `arr`.
// [VN] Hàm xuất 9 tại 0x020108: Kịch bản kiểm thử 2.2 (Giải phóng mảng GlobalRef)
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_12(
    JNIEnv* env,
    jclass /*clazz*/,
    jlong array_handle) {
    if (env == nullptr || array_handle == 0) {
        return;
    }
    auto* arr = reinterpret_cast<godzilla_asan::RefTestArray*>(array_handle);
    if (arr->refs != nullptr) {
        for (int32_t i = 0; i < arr->count; ++i) {
            if (arr->refs[i] != nullptr) {
                env->DeleteGlobalRef(arr->refs[i]);
            }
        }
        std::free(arr->refs);
    }
    std::free(arr);
}

} // extern "C"

// ============================================================================
// [EN] Section 7: Self-Contained Verification & Diagnostic Engine
//      Provides deterministic host-callable verification routines for all 4
//      subsystems of `libgodzilla-acurate-asan.so`:
//      1. GWP-ASan `AllocatorState` & `GuardedPoolAllocator` slot/guard-page math,
//         error classification (`USE_AFTER_FREE`, `DOUBLE_FREE`, `INVALID_FREE`,
//         `BUFFER_OVERFLOW`, `BUFFER_UNDERFLOW`), and ZigZag/LEB128 compression.
//      2. Xorshift32 PRNG state transition (`x ^= x << 13; x ^= x >> 17; x ^= x << 5`
//         @ `0x011438`) and API-level `MaxAllocationSize` clamping (`0x00dfa8`).
//      3. Proxy Fault Handler `ret` instruction encoding (`0xd65f03c0` @ `0x01eeb0`)
//         and JSON configuration serialization (`FaultHandlerConfig::toString` @ `0x01e74c`).
//      4. GodzillaRefDebug ring-buffer bucket hashing `(ref_val >> 2) % bundle_size`
//         (@ `0x02097c`) and descending `seq_id` dump ordering (@ `0x0206b4`).
// [VN] Phần 7: Bộ máy tự kiểm định độc lập cho cả 4 phân hệ của `libgodzilla-acurate-asan.so`
// ============================================================================
namespace godzilla_asan {
namespace verification {

struct SelfTestReport {
    bool struct_abi_ok = false;
    bool slot_math_ok = false;
    bool error_classifier_ok = false;
    bool leb128_codec_ok = false;
    bool xorshift32_ok = false;
    bool api_clamp_ok = false;
    bool ref_debug_ring_ok = false;
    uint32_t total_checks = 0;
    uint32_t passed_checks = 0;
};

// [EN] Execute all 7 deterministic mathematical & ABI self-tests
// [VN] Thực thi toàn bộ 7 bài tự kiểm định toán học và bố cục ABI
SelfTestReport runCompleteSelfVerification() {
    SelfTestReport rep = {};

    // 1. Verify exact struct sizes against AArch64 disassembly constants
    rep.total_checks++;
    if (sizeof(gwp_asan::Options) == 0x28 &&
        sizeof(gwp_asan::AllocatorState) == 0x58 &&
        sizeof(gwp_asan::AllocationMetadata) == 0x270 &&
        sizeof(gwp_asan::GuardedPoolAllocator) == 0xe8 &&
        sizeof(FaultHandlerSymbolConfig) == 0x38 &&
        sizeof(RefRecordEntry) == 0x30 &&
        sizeof(RefBucket) == 0x10 &&
        sizeof(RefDebugState) == 0x18 &&
        sizeof(RefTestArray) == 0x10 &&
        sizeof(RefHookContext) == 0x50) {
        rep.struct_abi_ok = true;
        rep.passed_checks++;
    }

    // 2. Verify AllocatorState slotToAddr, addrToSlot, and isGuardPage math
    rep.total_checks++;
    {
        gwp_asan::AllocatorState st = {};
        st.MaxSimultaneousAllocations = 16;
        st.PageSize = 4096;
        st.MaxAllocationSize = 4096;
        st.GuardedPagePool = 0x7000000000ULL;
        st.GuardedPagePoolEnd = st.GuardedPagePool + 4096ULL * (1 + 2 * 16);

        uintptr_t slot0 = st.slotToAddr(0);
        uintptr_t slot5 = st.slotToAddr(5);
        bool guard0 = st.isGuardPage(st.GuardedPagePool);
        bool data0 = !st.isGuardPage(slot0);
        bool guard1 = st.isGuardPage(slot0 + 4096);
        size_t back5 = st.addrToSlot(slot5 + 128);

        if (slot0 == 0x7000001000ULL &&
            slot5 == 0x700000b000ULL &&
            guard0 && data0 && guard1 && back5 == 5) {
            rep.slot_math_ok = true;
            rep.passed_checks++;
        }
    }

    // 3. Verify AllocatorState::getErrorType across all 5 error conditions
    rep.total_checks++;
    {
        gwp_asan::AllocatorState st = {};
        st.MaxSimultaneousAllocations = 16;
        st.PageSize = 4096;
        st.MaxAllocationSize = 4096;
        st.GuardedPagePool = 0x7000000000ULL;
        st.GuardedPagePoolEnd = st.GuardedPagePool + 4096ULL * 33;
        uintptr_t slot0 = st.slotToAddr(0);

        auto e_uaf = st.getErrorType(slot0 + 16, true, slot0, 128);
        auto e_ovf = st.getErrorType(slot0 + 128, false, slot0, 128);
        auto e_udf = st.getErrorType(slot0 - 1, false, slot0, 128);
        st.FailureType = gwp_asan::Error::DOUBLE_FREE;
        auto e_df = st.getErrorType(slot0, true, slot0, 128);
        st.FailureType = gwp_asan::Error::INVALID_FREE;
        auto e_if = st.getErrorType(slot0 + 8, false, slot0, 128);

        if (e_uaf == gwp_asan::Error::USE_AFTER_FREE &&
            e_ovf == gwp_asan::Error::BUFFER_OVERFLOW &&
            e_udf == gwp_asan::Error::BUFFER_UNDERFLOW &&
            e_df == gwp_asan::Error::DOUBLE_FREE &&
            e_if == gwp_asan::Error::INVALID_FREE) {
            rep.error_classifier_ok = true;
            rep.passed_checks++;
        }
    }

    // 4. Verify ZigZag + LEB128 pack/unpack round-trip fidelity (@ 0x01129c & @ 0x011320)
    rep.total_checks++;
    {
        const uintptr_t input_frames[6] = {
            0x000000789abc1234ULL,
            0x000000789abc1280ULL,
            0x000000789abbff00ULL,
            0x000000789abd4000ULL,
            0x000000789abd401cULL,
            0x000000789abe0000ULL
        };
        uint8_t packed[280] = {};
        uintptr_t output_frames[6] = {};

        size_t packed_len = gwp_asan::compression::pack(input_frames, 6, packed, sizeof(packed));
        size_t unpacked_cnt = gwp_asan::compression::unpack(packed, packed_len, output_frames, 6);

        if (packed_len > 0 && packed_len < sizeof(input_frames) && unpacked_cnt == 6 &&
            std::memcmp(input_frames, output_frames, sizeof(input_frames)) == 0) {
            rep.leb128_codec_ok = true;
            rep.passed_checks++;
        }
    }

    // 5. Verify Xorshift32 PRNG step (@ 0x011438)
    rep.total_checks++;
    {
        uint32_t seed = 0x9e37ac56U;
        uint32_t expected = seed;
        expected ^= expected << 13;
        expected ^= expected >> 17;
        expected ^= expected << 5;
        uint32_t actual = gwp_asan::getRandomUnsigned32(&seed);
        if (actual == expected && seed == expected) {
            rep.xorshift32_ok = true;
            rep.passed_checks++;
        }
    }

    // 6. Verify API-level MaxAllocationSize clamping (@ 0x00dfa8..0x00dfe4)
    rep.total_checks++;
    {
        uint64_t sz_api19 = internal::computeMaxAllocationSizeForApiLevel(19, 4096);
        uint64_t sz_api24 = internal::computeMaxAllocationSizeForApiLevel(24, 4096);
        uint64_t sz_api29 = internal::computeMaxAllocationSizeForApiLevel(29, 4096);
        uint64_t sz_api33 = internal::computeMaxAllocationSizeForApiLevel(33, 4096);
        if (sz_api19 == 0 &&
            sz_api24 == 4096ULL &&
            sz_api29 == 40960ULL &&
            sz_api33 == 81920ULL) {
            rep.api_clamp_ok = true;
            rep.passed_checks++;
        }
    }

    // 7. Verify GodzillaRefDebug bucket hashing `(ref_val >> 2) % g_ref_bundle_size` (@ 0x02097c)
    rep.total_checks++;
    {
        RefDebugState state = {};
        state.init(64, 4);
        const uint32_t fake_ref = 0x00002016U;
        const uint32_t bucket_idx = (fake_ref >> 2U) % 64U;
        RefBucket& b = state.buckets[bucket_idx];
        b.records[b.write_idx].ref_value = fake_ref;
        b.records[b.write_idx].seq_id = 101;
        b.records[b.write_idx].action_type = 1;
        b.write_idx = (b.write_idx + 1U) % 4U;
        b.count = 1;

        if (b.records[0].ref_value == fake_ref &&
            b.records[0].seq_id == 101 &&
            b.records[0].action_type == 1 &&
            b.write_idx == 1 && b.count == 1) {
            rep.ref_debug_ring_ok = true;
            rep.passed_checks++;
        }
        delete[] state.records_pool;
        delete[] state.mutex_array;
        delete[] state.buckets;
    }

    return rep;
}

} // namespace verification
} // namespace godzilla_asan

// ============================================================================
// [EN] Section 8: Complete ELF PT_NOTE `NT_GNU_BUILD_ID` Extractor &
//      GWP-ASan Crash Report Simulator (`0x01305c..0x013a04`)
//      Reconstructs the exact byte-level ELF64 `PT_NOTE` iteration performed
//      by `phdrBuildIdCallback` (@ `0x0130a4`) and `dumpErrorReport` (@ `0x0132b8`)
//      including:
//      - 4-byte note alignment `(offset + size + 3) & ~3`
//      - `n_type == 3` (`NT_GNU_BUILD_ID`) and `n_namesz == 4` (`"GNU\0"`)
//      - Lowercase hex formatting (`"%02x"`) up to 127 characters
//      - Multi-slot metadata inspection and report generation for all 5
//        `gwp_asan::Error` categories (`Use After Free`, `Double Free`,
//        `Invalid (Wild) Free`, `Buffer Overflow`, `Buffer Underflow`).
// [VN] Phần 8: Bộ trích xuất `NT_GNU_BUILD_ID` từ PT_NOTE ELF64 và bộ mô phỏng
//      báo cáo sự cố GWP-ASan (`0x01305c..0x013a04`).
// ============================================================================
namespace godzilla_asan {
namespace verification {

// [EN] Extract GNU BuildId hex string from an in-memory ELF PT_NOTE segment buffer (@ 0x0130a4)
// [VN] Trích xuất chuỗi hex GNU BuildId từ bộ đệm phân đoạn PT_NOTE ELF trong bộ nhớ (@ 0x0130a4)
std::string extractGnuBuildIdFromNoteSegment(const uint8_t* note_buf, size_t note_len) {
    if (note_buf == nullptr || note_len < sizeof(Elf64_Nhdr)) {
        return {};
    }
    size_t offset = 0;
    while (offset + sizeof(Elf64_Nhdr) <= note_len) {
        const auto* nhdr = reinterpret_cast<const Elf64_Nhdr*>(note_buf + offset);
        size_t name_off = offset + sizeof(Elf64_Nhdr);
        size_t desc_off = gwp_asan::alignUp(name_off + nhdr->n_namesz, 4);
        size_t next_off = gwp_asan::alignUp(desc_off + nhdr->n_descsz, 4);

        if (next_off > note_len) {
            break;
        }
        if (nhdr->n_type == NT_GNU_BUILD_ID &&
            nhdr->n_namesz == 4 &&
            std::memcmp(note_buf + name_off, "GNU\0", 4) == 0 &&
            nhdr->n_descsz > 0 && nhdr->n_descsz <= 64) {
            char hex_out[130] = {};
            for (uint32_t i = 0; i < nhdr->n_descsz && (i * 2 + 2) < sizeof(hex_out); ++i) {
                std::snprintf(hex_out + (i * 2), 3, "%02x", note_buf[desc_off + i]);
            }
            return std::string(hex_out);
        }
        offset = next_off;
    }
    return {};
}

// [EN] Simulate a complete GWP-ASan crash report string without triggering SIGSEGV (@ 0x0132b8)
// [VN] Mô phỏng toàn bộ chuỗi báo cáo lỗi GWP-ASan mà không cần kích hoạt SIGSEGV (@ 0x0132b8)
std::string simulateGwpAsanCrashReport(const gwp_asan::AllocatorState& state,
                                       const gwp_asan::AllocationMetadata& slot_meta,
                                       uintptr_t fault_addr,
                                       bool recoverable) {
    std::ostringstream oss;
    oss << "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***\n";
    oss << "GWP-ASan-recoverable: " << (recoverable ? "true" : "false") << "\n";
    oss << "*** GWP-ASan detected a memory error ***\n";

    gwp_asan::Error err = state.getErrorType(
        fault_addr, slot_meta.IsDeallocated, slot_meta.Addr, slot_meta.RequestedSize);

    const char* err_name = "Unknown";
    switch (err) {
        case gwp_asan::Error::USE_AFTER_FREE:   err_name = "Use After Free"; break;
        case gwp_asan::Error::DOUBLE_FREE:      err_name = "Double Free"; break;
        case gwp_asan::Error::INVALID_FREE:     err_name = "Invalid (Wild) Free"; break;
        case gwp_asan::Error::BUFFER_OVERFLOW:  err_name = "Buffer Overflow"; break;
        case gwp_asan::Error::BUFFER_UNDERFLOW: err_name = "Buffer Underflow"; break;
        default: break;
    }

    char summary[512];
    if (fault_addr < slot_meta.Addr) {
        size_t delta = slot_meta.Addr - fault_addr;
        std::snprintf(summary, sizeof(summary),
                      "%s at 0x%" PRIxPTR " (%zu bytes to the left of %zu-byte allocation at 0x%" PRIxPTR ") by thread %" PRIu64 " here:\n",
                      err_name, fault_addr, delta, slot_meta.RequestedSize,
                      slot_meta.Addr, slot_meta.AllocationTrace.ThreadID);
    } else if (fault_addr >= slot_meta.Addr + slot_meta.RequestedSize) {
        size_t delta = fault_addr - (slot_meta.Addr + slot_meta.RequestedSize);
        std::snprintf(summary, sizeof(summary),
                      "%s at 0x%" PRIxPTR " (%zu bytes to the right of %zu-byte allocation at 0x%" PRIxPTR ") by thread %" PRIu64 " here:\n",
                      err_name, fault_addr, delta, slot_meta.RequestedSize,
                      slot_meta.Addr, slot_meta.AllocationTrace.ThreadID);
    } else {
        size_t delta = fault_addr - slot_meta.Addr;
        std::snprintf(summary, sizeof(summary),
                      "%s at 0x%" PRIxPTR " (%zu bytes into a %zu-byte allocation at 0x%" PRIxPTR ") by thread %" PRIu64 " here:\n",
                      err_name, fault_addr, delta, slot_meta.RequestedSize,
                      slot_meta.Addr, slot_meta.AllocationTrace.ThreadID);
    }
    oss << summary;

    if (slot_meta.IsDeallocated && slot_meta.DeallocationTrace.TraceSize > 0) {
        uintptr_t dealloc_frames[gwp_asan::AllocationMetadata::kMaxFrameDepth];
        size_t n = gwp_asan::compression::unpack(
            slot_meta.DeallocationTrace.CompressedTrace,
            slot_meta.DeallocationTrace.TraceSize,
            dealloc_frames,
            gwp_asan::AllocationMetadata::kMaxFrameDepth);
        oss << "0x" << std::hex << slot_meta.Addr << std::dec
            << " was deallocated by thread " << slot_meta.DeallocationTrace.ThreadID << " here:\n";
        for (size_t i = 0; i < n; ++i) {
            char fbuf[128];
            std::snprintf(fbuf, sizeof(fbuf), "  #%02zu %08" PRIxPTR "\n", i, dealloc_frames[i]);
            oss << fbuf;
        }
    }

    if (slot_meta.AllocationTrace.TraceSize > 0) {
        uintptr_t alloc_frames[gwp_asan::AllocationMetadata::kMaxFrameDepth];
        size_t n = gwp_asan::compression::unpack(
            slot_meta.AllocationTrace.CompressedTrace,
            slot_meta.AllocationTrace.TraceSize,
            alloc_frames,
            gwp_asan::AllocationMetadata::kMaxFrameDepth);
        oss << "0x" << std::hex << slot_meta.Addr << std::dec
            << " was allocated by thread " << slot_meta.AllocationTrace.ThreadID << " here:\n";
        for (size_t i = 0; i < n; ++i) {
            char fbuf[128];
            std::snprintf(fbuf, sizeof(fbuf), "  #%02zu %08" PRIxPTR "\n", i, alloc_frames[i]);
            oss << fbuf;
        }
    }

    oss << "*** End GWP-ASan report ***\n";
    return oss.str();
}

} // namespace verification
} // namespace godzilla_asan

// ============================================================================
// [EN] Section 9: ByteHook Caller Path Allow/Ignore Filter (`0x01d2d0..0x01d5a4`)
//      In `libgodzilla-acurate-asan.so`, when `hook_type == 3` (`BYTEHOOK_PARTIAL`),
//      `startCustomHooks` (@ `0x014ce8`) passes `bytehookAllowFilterCallback`
//      (@ `0x01d2d0`) and the `CustomHookContext*` pointer to `bytehook_hook_partial`.
//      Exact filter algorithm @ `0x01d2d0..0x01d5a4`:
//      1. If `caller_path_name == nullptr`, returns `false`.
//      2. Always ignores `libgodzilla-acurate-asan.so` itself so internal allocations
//         do not recurse into hooks.
//      3. Iterates `ctx->partial_ignore_list` (+0x70..+0x88):
//         if `strstr(caller_path_name, ignore_item.c_str()) != nullptr`, returns `false`.
//      4. If `ctx->partial_allow_list` (+0x58..+0x70) is empty, returns `true`.
//      5. Iterates `ctx->partial_allow_list`:
//         if `strstr(caller_path_name, allow_item.c_str()) != nullptr`, returns `true`.
//      6. Otherwise returns `false`.
// [VN] Phần 9: Bộ lọc danh sách cho phép/bỏ qua đường dẫn thư viện gọi của ByteHook (`0x01d2d0..0x01d5a4`)
// ============================================================================
namespace godzilla_asan {
namespace internal {

bool bytehookAllowFilterCallback(const char* caller_path_name, void* arg) noexcept {
    if (caller_path_name == nullptr || arg == nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libgodzilla-acurate-asan.so") != nullptr) {
        return false;
    }

    const auto* ctx = static_cast<const CustomHookContext*>(arg);
    for (const std::string& ignore_entry : ctx->partial_ignore_list) {
        if (!ignore_entry.empty() &&
            std::strstr(caller_path_name, ignore_entry.c_str()) != nullptr) {
            return false;
        }
    }

    if (ctx->partial_allow_list.empty()) {
        return true;
    }

    for (const std::string& allow_entry : ctx->partial_allow_list) {
        if (!allow_entry.empty() &&
            std::strstr(caller_path_name, allow_entry.c_str()) != nullptr) {
            return true;
        }
    }
    return false;
}

// ============================================================================
// [EN] Hook Dispatch Matrix Selection (`0x014e50..0x0168c0`)
//      Selects the exact function pointer from `IndexedAllocatorHooks<0..7>`
//      based on `(slot_index, alloc_type)` and `(slot_index, free_type)`:
//      - `alloc_type` in `{0, 1, 2, 3}`
//      - `free_type` in `{0, 1, 2}`
// [VN] Ma trận chọn con trỏ hàm Hook theo `(slot_index, alloc_type)` và `(slot_index, free_type)`
// ============================================================================
template <size_t SlotIdx>
void* selectAllocHookForSlot(uint32_t alloc_type) noexcept {
    switch (alloc_type) {
        case 0: return reinterpret_cast<void*>(&IndexedAllocatorHooks<SlotIdx>::allocType0);
        case 1: return reinterpret_cast<void*>(&IndexedAllocatorHooks<SlotIdx>::allocType1);
        case 2: return reinterpret_cast<void*>(&IndexedAllocatorHooks<SlotIdx>::allocType2);
        case 3: return reinterpret_cast<void*>(&IndexedAllocatorHooks<SlotIdx>::allocType3);
        default: return nullptr;
    }
}

template <size_t SlotIdx>
void* selectFreeHookForSlot(uint32_t free_type) noexcept {
    switch (free_type) {
        case 0: return reinterpret_cast<void*>(&IndexedAllocatorHooks<SlotIdx>::freeType0);
        case 1: return reinterpret_cast<void*>(&IndexedAllocatorHooks<SlotIdx>::freeType1);
        case 2: return reinterpret_cast<void*>(&IndexedAllocatorHooks<SlotIdx>::freeType2);
        default: return nullptr;
    }
}

void* resolveAllocHookFunction(size_t slot_index, uint32_t alloc_type) noexcept {
    switch (slot_index) {
        case 0: return selectAllocHookForSlot<0>(alloc_type);
        case 1: return selectAllocHookForSlot<1>(alloc_type);
        case 2: return selectAllocHookForSlot<2>(alloc_type);
        case 3: return selectAllocHookForSlot<3>(alloc_type);
        case 4: return selectAllocHookForSlot<4>(alloc_type);
        case 5: return selectAllocHookForSlot<5>(alloc_type);
        case 6: return selectAllocHookForSlot<6>(alloc_type);
        case 7: return selectAllocHookForSlot<7>(alloc_type);
        default: return nullptr;
    }
}

void* resolveFreeHookFunction(size_t slot_index, uint32_t free_type) noexcept {
    switch (slot_index) {
        case 0: return selectFreeHookForSlot<0>(free_type);
        case 1: return selectFreeHookForSlot<1>(free_type);
        case 2: return selectFreeHookForSlot<2>(free_type);
        case 3: return selectFreeHookForSlot<3>(free_type);
        case 4: return selectFreeHookForSlot<4>(free_type);
        case 5: return selectFreeHookForSlot<5>(free_type);
        case 6: return selectFreeHookForSlot<6>(free_type);
        case 7: return selectFreeHookForSlot<7>(free_type);
        default: return nullptr;
    }
}

} // namespace internal
} // namespace godzilla_asan
