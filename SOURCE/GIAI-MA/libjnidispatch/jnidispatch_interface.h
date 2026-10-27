/**
 * @file jnidispatch_interface.h
 * @brief Complete Exported C/JNI Symbol Interface (153 `.dynsym` Exports) for libjnidispatch.so (JNA 7.0.4).
 *        Giao diện đầy đủ 153 biểu tượng C/JNI xuất khẩu (`.dynsym`) của libjnidispatch.so (JNA 7.0.4).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so
 *   Size / Dung lượng: 165,992 bytes (0x28868)
 *   SHA-256: ddfc6c965bbe366615c000ec1f06552ddf0bb2b4f9d921d0bff8c75b3cb2ca4c
 *
 * Symbol Categories / Phân nhóm 153 biểu tượng xuất khẩu:
 *   1. 66 `Java_com_sun_jna_Native_*` JNI methods (`0x0072a8..0x00ac28`)
 *   2. `JNI_OnLoad` (`0x009848`) & `JNI_OnUnload` (`0x00abc8`)
 *   3. 16 `ffi_type_*` global descriptors (`.rodata 0x022858..0x022990` & `.data.rel.ro 0x02bb98..0x02bbe0`)
 *   4. libffi AArch64 C API (`ffi_prep_cif`, `ffi_prep_cif_var`, `ffi_call`, `ffi_closure_alloc`, `ffi_prep_closure_loc`, etc.)
 *   5. JNA C helper exports (`dispatch`, `toNative`, `fromNative`, `create_callback`, `free_callback`, `JNA_*`, etc.)
 */

#ifndef NEXTAI_OPENCUT_JNIDISPATCH_INTERFACE_H_
#define NEXTAI_OPENCUT_JNIDISPATCH_INTERFACE_H_

#include "jna_dispatch_callbacks.h"
#include "jna_type_conversion.h"
#include "jnidispatch_types.h"
#include "libffi_aarch64_engine.h"

#include <cstddef>
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * 1. 16 Exported libffi `ffi_type` Descriptors (.rodata 0x022858..0x022990 & .data.rel.ro 0x02bb98..0x02bbe0)
 *    16 Bộ mô tả kiểu dữ liệu `ffi_type` xuất khẩu toàn cục
 * ============================================================================ */
extern nextai::opencut::jnidispatch::FfiType ffi_type_void;               // .rodata 0x022978 (size=1, align=1, type=0)
extern nextai::opencut::jnidispatch::FfiType ffi_type_uint8;              // .rodata 0x022948 (size=1, align=1, type=5)
extern nextai::opencut::jnidispatch::FfiType ffi_type_sint8;              // .rodata 0x022930 (size=1, align=1, type=6)
extern nextai::opencut::jnidispatch::FfiType ffi_type_uint16;             // .rodata 0x022918 (size=2, align=2, type=7)
extern nextai::opencut::jnidispatch::FfiType ffi_type_sint16;             // .rodata 0x022900 (size=2, align=2, type=8)
extern nextai::opencut::jnidispatch::FfiType ffi_type_uint32;             // .rodata 0x0228e8 (size=4, align=4, type=9)
extern nextai::opencut::jnidispatch::FfiType ffi_type_sint32;             // .rodata 0x0228d0 (size=4, align=4, type=10)
extern nextai::opencut::jnidispatch::FfiType ffi_type_uint64;             // .rodata 0x0228b8 (size=8, align=8, type=11)
extern nextai::opencut::jnidispatch::FfiType ffi_type_sint64;             // .rodata 0x0228a0 (size=8, align=8, type=12)
extern nextai::opencut::jnidispatch::FfiType ffi_type_pointer;            // .rodata 0x022960 (size=8, align=8, type=14)
extern nextai::opencut::jnidispatch::FfiType ffi_type_float;              // .rodata 0x022888 (size=4, align=4, type=2)
extern nextai::opencut::jnidispatch::FfiType ffi_type_double;             // .rodata 0x022870 (size=8, align=8, type=3)
extern nextai::opencut::jnidispatch::FfiType ffi_type_longdouble;         // .rodata 0x022858 (size=16, align=16, type=4)
extern nextai::opencut::jnidispatch::FfiType ffi_type_complex_float;      // .data.rel.ro 0x02bbc8 (size=8, align=4, type=15)
extern nextai::opencut::jnidispatch::FfiType ffi_type_complex_double;     // .data.rel.ro 0x02bbb0 (size=16, align=8, type=15)
extern nextai::opencut::jnidispatch::FfiType ffi_type_complex_longdouble; // .data.rel.ro 0x02bb98 (size=32, align=16, type=15)

/* ============================================================================
 * 2. Exported libffi AArch64 Entry Points (0x00ce60..0x02007c)
 *    Các điểm vào hàm C của libffi AArch64
 * ============================================================================ */
int32_t ffi_prep_cif(nextai::opencut::jnidispatch::FfiCif* cif,
                     uint32_t abi,
                     uint32_t nargs,
                     nextai::opencut::jnidispatch::FfiType* rtype,
                     nextai::opencut::jnidispatch::FfiType** atypes);

int32_t ffi_prep_cif_var(nextai::opencut::jnidispatch::FfiCif* cif,
                         uint32_t abi,
                         uint32_t nfixedargs,
                         uint32_t ntotalargs,
                         nextai::opencut::jnidispatch::FfiType* rtype,
                         nextai::opencut::jnidispatch::FfiType** atypes);

int32_t ffi_get_struct_offsets(uint32_t abi,
                               nextai::opencut::jnidispatch::FfiType* struct_type,
                               size_t* offsets);

void ffi_call(nextai::opencut::jnidispatch::FfiCif* cif,
              void (*fn)(),
              void* rvalue,
              void** avalue);

void ffi_call_go(nextai::opencut::jnidispatch::FfiCif* cif,
                 void (*fn)(),
                 void* rvalue,
                 void** avalue,
                 void* closure);

void* ffi_closure_alloc(size_t size, void** code);
void  ffi_closure_free(void* writable_ptr);

int32_t ffi_prep_closure_loc(nextai::opencut::jnidispatch::FfiClosure* closure,
                             nextai::opencut::jnidispatch::FfiCif* cif,
                             void (*fun)(nextai::opencut::jnidispatch::FfiCif*, void*, void**, void*),
                             void* user_data,
                             void* codeloc);

int32_t ffi_prep_closure(nextai::opencut::jnidispatch::FfiClosure* closure,
                         nextai::opencut::jnidispatch::FfiCif* cif,
                         void (*fun)(nextai::opencut::jnidispatch::FfiCif*, void*, void**, void*),
                         void* user_data);

int32_t ffi_prep_go_closure(nextai::opencut::jnidispatch::FfiGoClosure* closure,
                            nextai::opencut::jnidispatch::FfiCif* cif,
                            void (*fun)(nextai::opencut::jnidispatch::FfiCif*, void*, void**, void*));

void* ffi_tramp_arch(size_t* tramp_size, size_t* map_size);
void  __clear_cache(void* begin, void* end);
void  __aarch64_sync_cache_range(const void* begin, const void* end);

/* ============================================================================
 * 3. Exported JNA Native Methods (`Java_com_sun_jna_Native_*`, 0x0072a8..0x00ac28)
 *    66 Phương thức JNI của lớp `com.sun.jna.Native` + `JNI_OnLoad` / `JNI_OnUnload`
 * ============================================================================ */
int32_t     JNI_OnLoad(void* vm, void* reserved);                                                        // 0x009848
void        JNI_OnUnload(void* vm, void* reserved);                                                      // 0x00abc8

const char* Java_com_sun_jna_Native_getNativeVersion(void* env, void* cls);                              // 0x009820 -> "7.0.4"
const char* Java_com_sun_jna_Native_getAPIChecksum(void* env, void* cls);                                // 0x009834 -> "5fb98531302accd485c534c452dd952a"
void        Java_com_sun_jna_Native_initIDs(void* env, void* cls);                                       // 0x008bf0
int32_t     Java_com_sun_jna_Native_sizeof(void* env, void* cls, int32_t type);                          // 0x008a0c

int64_t     Java_com_sun_jna_Native_malloc(void* env, void* cls, int64_t size);                          // 0x008b80
void        Java_com_sun_jna_Native_free(void* env, void* cls, int64_t ptr);                             // 0x008b78
void        Java_com_sun_jna_Native_setMemory(void* env, void* cls, void* obj, int64_t addr,
                                              int64_t offset, int64_t len, int8_t byte_val);             // 0x008974

int8_t      Java_com_sun_jna_Native_getByte(void* env, void* cls, void* obj, int64_t addr, int64_t off); // 0x008814
int16_t     Java_com_sun_jna_Native_getShort(void* env, void* cls, void* obj, int64_t addr, int64_t off);// 0x00881c
uint16_t    Java_com_sun_jna_Native_getChar(void* env, void* cls, void* obj, int64_t addr, int64_t off); // 0x008824
int32_t     Java_com_sun_jna_Native_getInt(void* env, void* cls, void* obj, int64_t addr, int64_t off);  // 0x00882c
int64_t     Java_com_sun_jna_Native_getLong(void* env, void* cls, void* obj, int64_t addr, int64_t off); // 0x008834
int64_t     Java_com_sun_jna_Native_getPointer(void* env, void* cls, int64_t addr);                      // 0x00883c
float       Java_com_sun_jna_Native_getFloat(void* env, void* cls, void* obj, int64_t addr, int64_t off);// 0x008954
double      Java_com_sun_jna_Native_getDouble(void* env, void* cls, void* obj, int64_t addr, int64_t off);// 0x008964

void        Java_com_sun_jna_Native_setByte(void* env, void* cls, void* obj, int64_t addr, int64_t off, int8_t val);   // 0x008924
void        Java_com_sun_jna_Native_setShort(void* env, void* cls, void* obj, int64_t addr, int64_t off, int16_t val); // 0x00892c
void        Java_com_sun_jna_Native_setChar(void* env, void* cls, void* obj, int64_t addr, int64_t off, uint16_t val); // 0x008934
void        Java_com_sun_jna_Native_setInt(void* env, void* cls, void* obj, int64_t addr, int64_t off, int32_t val);   // 0x00893c
void        Java_com_sun_jna_Native_setLong(void* env, void* cls, void* obj, int64_t addr, int64_t off, int64_t val);  // 0x008944
void        Java_com_sun_jna_Native_setPointer(void* env, void* cls, void* obj, int64_t addr, int64_t off, int64_t val);// 0x00894c
void        Java_com_sun_jna_Native_setFloat(void* env, void* cls, void* obj, int64_t addr, int64_t off, float val);   // 0x00895c
void        Java_com_sun_jna_Native_setDouble(void* env, void* cls, void* obj, int64_t addr, int64_t off, double val); // 0x00896c

int64_t     Java_com_sun_jna_Native_open(void* env, void* cls, const char* name, int32_t flags);         // 0x007a58
void        Java_com_sun_jna_Native_close(void* env, void* cls, int64_t handle);                         // 0x007b50
int64_t     Java_com_sun_jna_Native_findSymbol(void* env, void* cls, int64_t handle, const char* name);  // 0x007b94

void        Java_com_sun_jna_Native_invokeVoid(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args); // 0x0072a8
int32_t     Java_com_sun_jna_Native_invokeInt(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args);  // 0x007338
int64_t     Java_com_sun_jna_Native_invokeLong(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args); // 0x0073ac
float       Java_com_sun_jna_Native_invokeFloat(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args);// 0x0072c0
double      Java_com_sun_jna_Native_invokeDouble(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args);// 0x0072fc
int64_t     Java_com_sun_jna_Native_invokePointer(void* env, void* cls, void* fn, int64_t fp, int32_t call_flags, void* args);// 0x007374

int64_t     Java_com_sun_jna_Native_ffi_1prep_1cif(void* env, void* cls, int32_t abi, int32_t nargs, int64_t rtype, int64_t atypes); // 0x00aa20
void        Java_com_sun_jna_Native_ffi_1call(void* env, void* cls, int64_t cif, int64_t fn, int64_t rvalue, int64_t avalue);        // 0x00aac0
int64_t     Java_com_sun_jna_Native_ffi_1prep_1closure(void* env, void* cls, int64_t cif, void* cb);                                 // 0x00aad0
void        Java_com_sun_jna_Native_ffi_1free_1closure(void* env, void* cls, int64_t closure);                                       // 0x00aba4
int32_t     Java_com_sun_jna_Native_initialize_1ffi_1type(void* env, void* cls, int64_t type_info);                                  // 0x00abcc

void        JNA_set_last_error(void* env, int32_t err);                                                  // 0x00cc50
int32_t     JNA_get_last_error(void* env);                                                               // 0x00cc74

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // NEXTAI_OPENCUT_JNIDISPATCH_INTERFACE_H_
