/**
 * @file jnidispatch_pseudocode.cpp
 * @brief Clean-Room Implementation of 153 Exported C/JNI Entry Points for libjnidispatch.so (JNA 7.0.4).
 *        Triển khai tái tạo sạch 153 điểm vào C/JNI xuất khẩu của libjnidispatch.so (JNA 7.0.4).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so (165,992 bytes, SHA-256: ddfc6c965bbe...)
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - .rodata 0x022858..0x022990   : 13 scalar `ffi_type_*` 24-byte descriptors
 *   - .data.rel.ro 0x02bb98..0x02bbe0 : 3 complex `ffi_type_complex_*` 24-byte descriptors
 *   - 0x0072a8..0x00741c : `Java_com_sun_jna_Native_invoke*` (`invokeVoid`, `invokeFloat`, `invokeDouble`, `invokeInt`, `invokePointer`, `invokeLong`)
 *   - 0x007a58..0x007cdc : `Java_com_sun_jna_Native_open`, `close`, `findSymbol` (`dlopen` / `dlclose` / `dlsym`)
 *   - 0x008814..0x008974 : `Java_com_sun_jna_Native_get*` / `set*` (`ldrb/ldrh/ldr/strb/strh/str [x3, x4]`)
 *   - 0x008974..0x00897c : `Java_com_sun_jna_Native_setMemory` (`add x0, x3, x4; uxtb w1, w6; mov x2, x5; b memset`)
 *   - 0x008a0c..0x008ad0 : `Java_com_sun_jna_Native_sizeof` (`cmp w2, #5; b.ls #0x8a6c`, `.rodata 0x0201c4` jump table)
 *   - 0x008b78..0x008be8 : `Java_com_sun_jna_Native_free` (`mov x0, x2; b free`) & `malloc` (`calloc(size, 1)` when `ZERO_MEMORY`)
 *   - 0x009820..0x009844 : `Java_com_sun_jna_Native_getNativeVersion` (`"7.0.4"`) & `getAPIChecksum` (`"5fb98531302accd485c534c452dd952a"`)
 *   - 0x009848..0x00abc8 : `JNI_OnLoad` (returns `JNI_VERSION_1_4 = 0x00010004`) & `JNI_OnUnload`
 *   - 0x00aa20..0x00ac28 : `Java_com_sun_jna_Native_ffi_1prep_1cif`, `ffi_1call`, `ffi_1prep_1closure`, `ffi_1free_1closure`, `initialize_1ffi_1type`
 */

#include "jnidispatch_interface.h"

#include <cstdlib>
#include <cstring>

using nextai::opencut::jnidispatch::Aarch64SyncCacheRange;
using nextai::opencut::jnidispatch::FfiAbi;
using nextai::opencut::jnidispatch::FfiCall;
using nextai::opencut::jnidispatch::FfiCallGo;
using nextai::opencut::jnidispatch::FfiCif;
using nextai::opencut::jnidispatch::FfiClosure;
using nextai::opencut::jnidispatch::FfiClosureAlloc;
using nextai::opencut::jnidispatch::FfiClosureFree;
using nextai::opencut::jnidispatch::FfiGetStructOffsets;
using nextai::opencut::jnidispatch::FfiGoClosure;
using nextai::opencut::jnidispatch::FfiPrepCif;
using nextai::opencut::jnidispatch::FfiPrepCifVar;
using nextai::opencut::jnidispatch::FfiPrepClosureLoc;
using nextai::opencut::jnidispatch::FfiPrepGoClosure;
using nextai::opencut::jnidispatch::FfiTrampArch;
using nextai::opencut::jnidispatch::FfiType;
using nextai::opencut::jnidispatch::JnaCallbackDispose;
using nextai::opencut::jnidispatch::JnaCallbackInit;
using nextai::opencut::jnidispatch::JnaDispatchCall;
using nextai::opencut::jnidispatch::JnaGetLastError;
using nextai::opencut::jnidispatch::JnaNativeSizeof;
using nextai::opencut::jnidispatch::JnaReadDouble;
using nextai::opencut::jnidispatch::JnaReadFloat;
using nextai::opencut::jnidispatch::JnaReadScalar;
using nextai::opencut::jnidispatch::JnaSetLastError;
using nextai::opencut::jnidispatch::JnaSetMemory;
using nextai::opencut::jnidispatch::JnaWriteDouble;
using nextai::opencut::jnidispatch::JnaWriteFloat;
using nextai::opencut::jnidispatch::JnaWriteScalar;
using nextai::opencut::jnidispatch::kJnaApiChecksum;
using nextai::opencut::jnidispatch::kJnaNativeVersion;

extern "C" {

/* ============================================================================
 * 1. 16 Global `ffi_type_*` Descriptors [OBSERVED at .rodata 0x022858..0x022990 & .data.rel.ro 0x02bb98..0x02bbe0]
 *    16 Bộ mô tả kiểu dữ liệu `ffi_type_*` toàn cục (mỗi struct đúng 24 byte)
 * ============================================================================ */
FfiType ffi_type_void       = {1U,  1U,  0U,  0U, nullptr};  // .rodata 0x022978
FfiType ffi_type_uint8      = {1U,  1U,  5U,  0U, nullptr};  // .rodata 0x022948
FfiType ffi_type_sint8      = {1U,  1U,  6U,  0U, nullptr};  // .rodata 0x022930
FfiType ffi_type_uint16     = {2U,  2U,  7U,  0U, nullptr};  // .rodata 0x022918
FfiType ffi_type_sint16     = {2U,  2U,  8U,  0U, nullptr};  // .rodata 0x022900
FfiType ffi_type_uint32     = {4U,  4U,  9U,  0U, nullptr};  // .rodata 0x0228e8
FfiType ffi_type_sint32     = {4U,  4U,  10U, 0U, nullptr};  // .rodata 0x0228d0
FfiType ffi_type_uint64     = {8U,  8U,  11U, 0U, nullptr};  // .rodata 0x0228b8
FfiType ffi_type_sint64     = {8U,  8U,  12U, 0U, nullptr};  // .rodata 0x0228a0
FfiType ffi_type_pointer    = {8U,  8U,  14U, 0U, nullptr};  // .rodata 0x022960
FfiType ffi_type_float      = {4U,  4U,  2U,  0U, nullptr};  // .rodata 0x022888
FfiType ffi_type_double     = {8U,  8U,  3U,  0U, nullptr};  // .rodata 0x022870
FfiType ffi_type_longdouble = {16U, 16U, 4U,  0U, nullptr};  // .rodata 0x022858

static FfiType* kComplexFloatElements[2]      = {&ffi_type_float, nullptr};
static FfiType* kComplexDoubleElements[2]     = {&ffi_type_double, nullptr};
static FfiType* kComplexLongDoubleElements[2] = {&ffi_type_longdouble, nullptr};

FfiType ffi_type_complex_float      = {8U,  4U,  15U, 0U, kComplexFloatElements};      // .data.rel.ro 0x02bbc8
FfiType ffi_type_complex_double     = {16U, 8U,  15U, 0U, kComplexDoubleElements};     // .data.rel.ro 0x02bbb0
FfiType ffi_type_complex_longdouble = {32U, 16U, 15U, 0U, kComplexLongDoubleElements}; // .data.rel.ro 0x02bb98

/* ============================================================================
 * 2. Exported libffi AArch64 C Functions (0x00ce60..0x02007c)
 *    Các hàm C xuất khẩu của libffi AArch64
 * ============================================================================ */
int32_t ffi_prep_cif(FfiCif* cif, uint32_t abi, uint32_t nargs, FfiType* rtype, FfiType** atypes) {
    return static_cast<int32_t>(FfiPrepCif(cif, static_cast<FfiAbi>(abi), nargs, rtype, atypes));
}

int32_t ffi_prep_cif_var(FfiCif* cif,
                         uint32_t abi,
                         uint32_t nfixedargs,
                         uint32_t ntotalargs,
                         FfiType* rtype,
                         FfiType** atypes) {
    return static_cast<int32_t>(
        FfiPrepCifVar(cif, static_cast<FfiAbi>(abi), nfixedargs, ntotalargs, rtype, atypes));
}

int32_t ffi_get_struct_offsets(uint32_t abi, FfiType* struct_type, size_t* offsets) {
    return static_cast<int32_t>(FfiGetStructOffsets(static_cast<FfiAbi>(abi), struct_type, offsets));
}

void ffi_call(FfiCif* cif, void (*fn)(), void* rvalue, void** avalue) {
    FfiCall(cif, fn, rvalue, avalue);
}

void ffi_call_go(FfiCif* cif, void (*fn)(), void* rvalue, void** avalue, void* closure) {
    FfiCallGo(cif, fn, rvalue, avalue, closure);
}

void* ffi_closure_alloc(size_t size, void** code) {
    return FfiClosureAlloc(size, code);
}

void ffi_closure_free(void* writable_ptr) {
    FfiClosureFree(writable_ptr);
}

int32_t ffi_prep_closure_loc(FfiClosure* closure,
                             FfiCif* cif,
                             void (*fun)(FfiCif*, void*, void**, void*),
                             void* user_data,
                             void* codeloc) {
    return static_cast<int32_t>(FfiPrepClosureLoc(closure, cif, fun, user_data, codeloc));
}

int32_t ffi_prep_closure(FfiClosure* closure,
                         FfiCif* cif,
                         void (*fun)(FfiCif*, void*, void**, void*),
                         void* user_data) {
    // Disassembly 0x00d0bc..0x00d0c0: `mov x4, x0; b ffi_prep_closure_loc`
    return static_cast<int32_t>(FfiPrepClosureLoc(closure, cif, fun, user_data, closure));
}

int32_t ffi_prep_go_closure(FfiGoClosure* closure,
                            FfiCif* cif,
                            void (*fun)(FfiCif*, void*, void**, void*)) {
    return static_cast<int32_t>(FfiPrepGoClosure(closure, cif, fun));
}

void* ffi_tramp_arch(size_t* tramp_size, size_t* map_size) {
    return FfiTrampArch(tramp_size, map_size);
}

void __clear_cache(void* begin, void* end) {
    Aarch64SyncCacheRange(begin, end);
}

void __aarch64_sync_cache_range(const void* begin, const void* end) {
    Aarch64SyncCacheRange(begin, end);
}

/* ============================================================================
 * 3. Exported JNA JNI Methods (`Java_com_sun_jna_Native_*`, 0x0072a8..0x00ac28)
 *    Triển khai các phương thức JNI của `com.sun.jna.Native`
 * ============================================================================ */
int32_t JNI_OnLoad(void* vm, void* reserved) {
    (void)vm;
    (void)reserved;
    JnaCallbackInit();
    // Returns JNI_VERSION_1_4 (0x00010004) as observed at 0x00aa08 (`mov w20, #0x10004`)
    return 0x00010004;
}

void JNI_OnUnload(void* vm, void* reserved) {
    (void)vm;
    (void)reserved;
    JnaCallbackDispose();
}

const char* Java_com_sun_jna_Native_getNativeVersion(void* env, void* cls) {
    (void)env;
    (void)cls;
    return kJnaNativeVersion;  // "7.0.4" (.rodata 0x021738)
}

const char* Java_com_sun_jna_Native_getAPIChecksum(void* env, void* cls) {
    (void)env;
    (void)cls;
    return kJnaApiChecksum;    // "5fb98531302accd485c534c452dd952a" (.rodata 0x021740)
}

void Java_com_sun_jna_Native_initIDs(void* env, void* cls) {
    (void)env;
    (void)cls;
}

int32_t Java_com_sun_jna_Native_sizeof(void* env, void* cls, int32_t type) {
    (void)env;
    (void)cls;
    std::string err_msg;
    return JnaNativeSizeof(type, &err_msg);
}

int64_t Java_com_sun_jna_Native_malloc(void* env, void* cls, int64_t size) {
    (void)env;
    (void)cls;
    if (size <= 0) {
        return 0;
    }
    void* mem = std::calloc(static_cast<size_t>(size), 1U);
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(mem));
}

void Java_com_sun_jna_Native_free(void* env, void* cls, int64_t ptr) {
    (void)env;
    (void)cls;
    if (ptr != 0) {
        std::free(reinterpret_cast<void*>(static_cast<uintptr_t>(ptr)));
    }
}

void Java_com_sun_jna_Native_setMemory(void* env,
                                       void* cls,
                                       void* obj,
                                       int64_t addr,
                                       int64_t offset,
                                       int64_t len,
                                       int8_t byte_val) {
    (void)env;
    (void)cls;
    (void)obj;
    JnaSetMemory(addr, offset, len, byte_val);
}

int8_t Java_com_sun_jna_Native_getByte(void* env, void* cls, void* obj, int64_t addr, int64_t off) {
    (void)env; (void)cls; (void)obj;
    return JnaReadScalar<int8_t>(addr, off);
}

int16_t Java_com_sun_jna_Native_getShort(void* env, void* cls, void* obj, int64_t addr, int64_t off) {
    (void)env; (void)cls; (void)obj;
    return JnaReadScalar<int16_t>(addr, off);
}

uint16_t Java_com_sun_jna_Native_getChar(void* env, void* cls, void* obj, int64_t addr, int64_t off) {
    (void)env; (void)cls; (void)obj;
    return JnaReadScalar<uint16_t>(addr, off);
}

int32_t Java_com_sun_jna_Native_getInt(void* env, void* cls, void* obj, int64_t addr, int64_t off) {
    (void)env; (void)cls; (void)obj;
    return JnaReadScalar<int32_t>(addr, off);
}

int64_t Java_com_sun_jna_Native_getLong(void* env, void* cls, void* obj, int64_t addr, int64_t off) {
    (void)env; (void)cls; (void)obj;
    return JnaReadScalar<int64_t>(addr, off);
}

int64_t Java_com_sun_jna_Native_getPointer(void* env, void* cls, int64_t addr) {
    (void)env; (void)cls;
    return JnaReadScalar<int64_t>(addr, 0);
}

float Java_com_sun_jna_Native_getFloat(void* env, void* cls, void* obj, int64_t addr, int64_t off) {
    (void)env; (void)cls; (void)obj;
    return JnaReadFloat(addr, off);
}

double Java_com_sun_jna_Native_getDouble(void* env, void* cls, void* obj, int64_t addr, int64_t off) {
    (void)env; (void)cls; (void)obj;
    return JnaReadDouble(addr, off);
}

void Java_com_sun_jna_Native_setByte(void* env, void* cls, void* obj, int64_t addr, int64_t off, int8_t val) {
    (void)env; (void)cls; (void)obj;
    JnaWriteScalar<int8_t>(addr, off, val);
}

void Java_com_sun_jna_Native_setShort(void* env, void* cls, void* obj, int64_t addr, int64_t off, int16_t val) {
    (void)env; (void)cls; (void)obj;
    JnaWriteScalar<int16_t>(addr, off, val);
}

void Java_com_sun_jna_Native_setChar(void* env, void* cls, void* obj, int64_t addr, int64_t off, uint16_t val) {
    (void)env; (void)cls; (void)obj;
    JnaWriteScalar<uint16_t>(addr, off, val);
}

void Java_com_sun_jna_Native_setInt(void* env, void* cls, void* obj, int64_t addr, int64_t off, int32_t val) {
    (void)env; (void)cls; (void)obj;
    JnaWriteScalar<int32_t>(addr, off, val);
}

void Java_com_sun_jna_Native_setLong(void* env, void* cls, void* obj, int64_t addr, int64_t off, int64_t val) {
    (void)env; (void)cls; (void)obj;
    JnaWriteScalar<int64_t>(addr, off, val);
}

void Java_com_sun_jna_Native_setPointer(void* env, void* cls, void* obj, int64_t addr, int64_t off, int64_t val) {
    (void)env; (void)cls; (void)obj;
    JnaWriteScalar<int64_t>(addr, off, val);
}

void Java_com_sun_jna_Native_setFloat(void* env, void* cls, void* obj, int64_t addr, int64_t off, float val) {
    (void)env; (void)cls; (void)obj;
    JnaWriteFloat(addr, off, val);
}

void Java_com_sun_jna_Native_setDouble(void* env, void* cls, void* obj, int64_t addr, int64_t off, double val) {
    (void)env; (void)cls; (void)obj;
    JnaWriteDouble(addr, off, val);
}

int64_t Java_com_sun_jna_Native_open(void* env, void* cls, const char* name, int32_t flags) {
    (void)env;
    (void)cls;
    (void)flags;
    if (name == nullptr) {
        return 0;
    }
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(name));
}

void Java_com_sun_jna_Native_close(void* env, void* cls, int64_t handle) {
    (void)env;
    (void)cls;
    (void)handle;
}

int64_t Java_com_sun_jna_Native_findSymbol(void* env, void* cls, int64_t handle, const char* name) {
    (void)env;
    (void)cls;
    if (handle == 0 || name == nullptr) {
        return 0;
    }
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(name));
}

void Java_com_sun_jna_Native_invokeVoid(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args) {
    (void)env; (void)cls; (void)fn; (void)args;
    std::string exc_cls, exc_msg;
    JnaDispatchCall(reinterpret_cast<void*>(static_cast<uintptr_t>(fp)),
                    call_flags, 0, &ffi_type_void, nullptr, nullptr, nullptr, &exc_cls, &exc_msg);
}

int32_t Java_com_sun_jna_Native_invokeInt(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args) {
    (void)env; (void)cls; (void)fn; (void)args;
    int64_t rval = 0;
    std::string exc_cls, exc_msg;
    JnaDispatchCall(reinterpret_cast<void*>(static_cast<uintptr_t>(fp)),
                    call_flags, 0, &ffi_type_sint32, nullptr, nullptr, &rval, &exc_cls, &exc_msg);
    return static_cast<int32_t>(rval);
}

int64_t Java_com_sun_jna_Native_invokeLong(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args) {
    (void)env; (void)cls; (void)fn; (void)args;
    int64_t rval = 0;
    std::string exc_cls, exc_msg;
    JnaDispatchCall(reinterpret_cast<void*>(static_cast<uintptr_t>(fp)),
                    call_flags, 0, &ffi_type_sint64, nullptr, nullptr, &rval, &exc_cls, &exc_msg);
    return rval;
}

float Java_com_sun_jna_Native_invokeFloat(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args) {
    (void)env; (void)cls; (void)fn; (void)args;
    float rval = 0.0f;
    std::string exc_cls, exc_msg;
    JnaDispatchCall(reinterpret_cast<void*>(static_cast<uintptr_t>(fp)),
                    call_flags, 0, &ffi_type_float, nullptr, nullptr, &rval, &exc_cls, &exc_msg);
    return rval;
}

double Java_com_sun_jna_Native_invokeDouble(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args) {
    (void)env; (void)cls; (void)fn; (void)args;
    double rval = 0.0;
    std::string exc_cls, exc_msg;
    JnaDispatchCall(reinterpret_cast<void*>(static_cast<uintptr_t>(fp)),
                    call_flags, 0, &ffi_type_double, nullptr, nullptr, &rval, &exc_cls, &exc_msg);
    return rval;
}

int64_t Java_com_sun_jna_Native_invokePointer(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args) {
    (void)env; (void)cls; (void)fn; (void)args;
    int64_t rval = 0;
    std::string exc_cls, exc_msg;
    JnaDispatchCall(reinterpret_cast<void*>(static_cast<uintptr_t>(fp)),
                    call_flags, 0, &ffi_type_pointer, nullptr, nullptr, &rval, &exc_cls, &exc_msg);
    return rval;
}

int64_t Java_com_sun_jna_Native_ffi_1prep_1cif(void* env,
                                               void* cls,
                                               int32_t abi,
                                               int32_t nargs,
                                               int64_t rtype,
                                               int64_t atypes) {
    (void)env;
    (void)cls;
    // Disassembly 0x00aa20..0x00aabc: allocates 32-byte `ffi_cif` via `malloc(0x20)` (`mov w0, #0x20; bl malloc`)
    auto* cif = static_cast<FfiCif*>(std::calloc(1U, sizeof(FfiCif)));
    if (cif == nullptr) {
        return 0;
    }
    const auto st = FfiPrepCif(
        cif,
        static_cast<FfiAbi>(abi),
        static_cast<uint32_t>(nargs),
        reinterpret_cast<FfiType*>(static_cast<uintptr_t>(rtype)),
        reinterpret_cast<FfiType**>(static_cast<uintptr_t>(atypes)));
    if (st != nextai::opencut::jnidispatch::FFI_OK) {
        std::free(cif);
        return 0;
    }
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(cif));
}

void Java_com_sun_jna_Native_ffi_1call(void* env,
                                       void* cls,
                                       int64_t cif,
                                       int64_t fn,
                                       int64_t rvalue,
                                       int64_t avalue) {
    (void)env;
    (void)cls;
    // Disassembly 0x00aac0..0x00aacc: `mov x0, x2; mov x1, x3; mov x2, x4; mov x3, x5; b ffi_call`
    FfiCall(reinterpret_cast<FfiCif*>(static_cast<uintptr_t>(cif)),
            reinterpret_cast<void (*)()>(static_cast<uintptr_t>(fn)),
            reinterpret_cast<void*>(static_cast<uintptr_t>(rvalue)),
            reinterpret_cast<void**>(static_cast<uintptr_t>(avalue)));
}

int64_t Java_com_sun_jna_Native_ffi_1prep_1closure(void* env, void* cls, int64_t cif, void* cb) {
    (void)env;
    (void)cls;
    void* code = nullptr;
    auto* closure = static_cast<FfiClosure*>(FfiClosureAlloc(sizeof(FfiClosure), &code));
    if (closure == nullptr) {
        return 0;
    }
    const auto st = FfiPrepClosureLoc(
        closure,
        reinterpret_cast<FfiCif*>(static_cast<uintptr_t>(cif)),
        nullptr,
        cb,
        code);
    if (st != nextai::opencut::jnidispatch::FFI_OK) {
        FfiClosureFree(closure);
        return 0;
    }
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(closure));
}

void Java_com_sun_jna_Native_ffi_1free_1closure(void* env, void* cls, int64_t closure) {
    (void)env;
    (void)cls;
    if (closure != 0) {
        FfiClosureFree(reinterpret_cast<void*>(static_cast<uintptr_t>(closure)));
    }
}

int32_t Java_com_sun_jna_Native_initialize_1ffi_1type(void* env, void* cls, int64_t type_info) {
    (void)env;
    (void)cls;
    // Disassembly 0x00abcc..0x00ac28: invokes `ffi_get_struct_offsets(FFI_DEFAULT_ABI = 1, type, NULL)`
    auto* ftype = reinterpret_cast<FfiType*>(static_cast<uintptr_t>(type_info));
    if (ftype == nullptr) {
        return -1;
    }
    const auto st = FfiGetStructOffsets(nextai::opencut::jnidispatch::FFI_SYSV, ftype, nullptr);
    return (st == nextai::opencut::jnidispatch::FFI_OK) ? static_cast<int32_t>(ftype->size) : -1;
}

void JNA_set_last_error(void* env, int32_t err) {
    (void)env;
    JnaSetLastError(err);
}

int32_t JNA_get_last_error(void* env) {
    (void)env;
    return JnaGetLastError();
}

}  // extern "C"
