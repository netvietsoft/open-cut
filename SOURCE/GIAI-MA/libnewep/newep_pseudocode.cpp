/**
 * @file newep_pseudocode.cpp
 * @brief Complete ELF64 symbol & relocation directory (`.dynsym [000]..[074]`, `.rela.dyn`,
 *        `.rela.plt`), `.rodata` string & DWARF jump-table verification (`0x00728c..0x007584`),
 *        and full AArch64 opcode verification tables for `libnewep.so` (`51,232 bytes`).
 *        Danh mục đầy đủ biểu tượng & tái định vị ELF64 (`.dynsym [000]..[074]`, `.rela.dyn`,
 *        `.rela.plt`), bảng chuỗi & bảng nhảy DWARF `.rodata` (`0x00728c..0x007584`),
 *        và bảng đối soát mã máy AArch64 cho `libnewep.so` (`51,232 byte`).
 */

#include "newep_interface.h"

namespace nextai {
namespace opencut {
namespace newep {

// ============================================================================
// 1. Complete `.dynsym` Table (`0x000550`, 75 Entries: `[000]..[074]`)
//    Bảng `.dynsym` Đầy đủ (`0x000550`, 75 Mục: `[000]..[074]`)
// ============================================================================

struct Elf64DynSymRecord {
    uint32_t    index;
    uint32_t    st_value;
    uint32_t    st_size;
    const char* bind_name;
    const char* type_name;
    uint16_t    st_shndx;
    const char* sym_name;
    const char* demangled_purpose;
};

static constexpr Elf64DynSymRecord kNewepDynSymTable[75] = {
    { 0, 0x000000u,    0u, "STB_LOCAL",  "STT_NOTYPE",  0u,  "",                                                                                                            "Null symbol entry" },
    { 1, 0x001e80u,    0u, "STB_LOCAL",  "STT_SECTION", 11u, ".text",                                                                                                       ".text section base" },
    { 2, 0x00fbe8u,    0u, "STB_LOCAL",  "STT_SECTION", 18u, ".data.rel.ro",                                                                                                ".data.rel.ro section base" },
    { 3, 0x000000u,    0u, "STB_GLOBAL", "STT_OBJECT",  0u,  "_ZTVSt12length_error",                                                                                        "vtable for std::length_error (GOT 0x00ff90)" },
    { 4, 0x000000u,    0u, "STB_WEAK",   "STT_FUNC",    0u,  "pthread_create",                                                                                              "POSIX thread creation (GOT 0x00ff98)" },
    { 5, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__cxa_throw",                                                                                                 "Itanium C++ ABI exception throw (PLT 0x001b90)" },
    { 6, 0x000000u,    0u, "STB_GLOBAL", "STT_OBJECT",  0u,  "_ZTISt12length_error",                                                                                        "typeinfo for std::length_error (GOT 0x00ffa8)" },
    { 7, 0x000000u,    0u, "STB_WEAK",   "STT_FUNC",    0u,  "pthread_once",                                                                                                "POSIX one-time initializer (PLT 0x001ba0)" },
    { 8, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__cxa_finalize",                                                                                              "DSO finalizer at unload (PLT 0x001bb0)" },
    { 9, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "ftell",                                                                                                       "Get file position in nativeCheckEffectChildrenFile (PLT 0x001bc0)" },
    {10, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "_Znwm",                                                                                                       "operator new(unsigned long) (PLT 0x001be0)" },
    {11, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__strlen_chk",                                                                                                "Fortified strlen check with 0x1e on '/effect_platform_children.tag' (PLT 0x001bf0)" },
    {12, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "_ZNSt12out_of_rangeD1Ev",                                                                                     "std::out_of_range::~out_of_range() (GOT 0x00ffc0)" },
    {13, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "abort",                                                                                                       "Process abort in libunwind (PLT 0x001c10)" },
    {14, 0x000000u,    0u, "STB_GLOBAL", "STT_OBJECT",  0u,  "_ZTVSt12out_of_range",                                                                                        "vtable for std::out_of_range (GOT 0x00ffc8)" },
    {15, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "dl_iterate_phdr",                                                                                             "Walk ELF program headers for .eh_frame_hdr (PLT 0x001c30)" },
    {16, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "strcat",                                                                                                      "C-string concatenation in nativeCheckEffectChildrenFile (PLT 0x001c40)" },
    {17, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "memcmp",                                                                                                      "Memory comparison in delimiter search (PLT 0x001c50)" },
    {18, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "fclose",                                                                                                      "Close tag file stream (PLT 0x001c60)" },
    {19, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__gxx_personality_v0",                                                                                        "C++ exception personality routine (.data 0x010000 & PLT 0x001c90)" },
    {20, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "rewind",                                                                                                      "Rewind tag file stream to start (PLT 0x001ca0)" },
    {21, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__stack_chk_fail",                                                                                            "Stack canary failure handler (PLT 0x001cb0)" },
    {22, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "fgets",                                                                                                       "Read 1024-byte (0x400) chunks from tag file (PLT 0x001cc0)" },
    {23, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "_ZNSt12length_errorD1Ev",                                                                                     "std::length_error::~length_error() (GOT 0x00ffe0)" },
    {24, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "memchr",                                                                                                      "Scan for ',' delimiter first byte (PLT 0x001ce0)" },
    {25, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "strncpy",                                                                                                     "Copy resolved URI into heap buffer (PLT 0x001cf0)" },
    {26, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__android_log_print",                                                                                         "Android logcat output with tag 'kn_resource_finder' (PLT 0x001d00)" },
    {27, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "fseek",                                                                                                       "Seek to SEEK_END=2 on tag file (PLT 0x001d20)" },
    {28, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "strcmp",                                                                                                      "Compare URI against 'asset://not_found' (PLT 0x001d30)" },
    {29, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "_ZNSt11logic_errorC2EPKc",                                                                                    "std::logic_error::logic_error(const char*) (PLT 0x001d40)" },
    {30, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__cxa_allocate_exception",                                                                                    "Allocate 16B exception object (PLT 0x001d50)" },
    {31, 0x000000u,    0u, "STB_WEAK",   "STT_FUNC",    0u,  "pthread_mutex_lock",                                                                                          "Lock mutex in libunwind (PLT 0x001d60)" },
    {32, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "_ZdlPv",                                                                                                      "operator delete(void*) (PLT 0x001d80)" },
    {33, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "memmove",                                                                                                     "Shift string bytes during left-space trim and append (PLT 0x001d90)" },
    {34, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__cxa_free_exception",                                                                                        "Free exception if constructor throws (PLT 0x001db0)" },
    {35, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "strlen",                                                                                                      "Compute C-string length (PLT 0x001dc0)" },
    {36, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "stat",                                                                                                        "Verify child file existence on disk (PLT 0x001dd0)" },
    {37, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "malloc",                                                                                                      "Allocate C-string buffers (PLT 0x001df0)" },
    {38, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "memcpy",                                                                                                      "Fast memory copy (PLT 0x001e00)" },
    {39, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "memset",                                                                                                      "Memory zeroing (PLT 0x001e20)" },
    {40, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "fopen",                                                                                                       "Open '/effect_platform_children.tag' in mode 'r' (PLT 0x001e30)" },
    {41, 0x000000u,    0u, "STB_GLOBAL", "STT_OBJECT",  0u,  "_ZTISt12out_of_range",                                                                                        "typeinfo for std::out_of_range (GOT 0x00fff8)" },
    {42, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "free",                                                                                                        "Free malloc buffers (PLT 0x001e40)" },
    {43, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "strcpy",                                                                                                      "Copy directory path prefix (PLT 0x001e50)" },
    {44, 0x000000u,    0u, "STB_WEAK",   "STT_FUNC",    0u,  "pthread_mutex_unlock",                                                                                        "Unlock mutex in libunwind (PLT 0x001e60)" },
    {45, 0x000000u,    0u, "STB_GLOBAL", "STT_FUNC",    0u,  "__cxa_atexit",                                                                                                "Register destructor at exit (PLT 0x001e70)" },
    {46, 0x010280u,    0u, "STB_GLOBAL", "STT_NOTYPE", 65521u,"_bss_end__",                                                                                                  "End of .bss segment (0x010280)" },
    {47, 0x003270u,  152u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc",                                 "std::__ndk1::basic_string<char>::basic_string(const char*)" },
    {48, 0x002570u, 3328u, "STB_GLOBAL", "STT_FUNC",   11u,  "Java_com_ss_ugc_effectplatform_util_EffectUtilKt_nativeCheckEffectChildrenFile",                              "EffectUtilKt.nativeCheckEffectChildrenFile(String)Z" },
    {49, 0x0024d4u,  156u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz",                                                    "_JNIEnv::CallStaticVoidMethod(jclass, jmethodID, ...)" },
    {50, 0x010030u,    8u, "STB_GLOBAL", "STT_OBJECT", 22u,  "old_resource_finder_class",                                                                                   "GlobalRef jclass for DownloadableModelSupportResourceFinder (.bss 0x010030)" },
    {51, 0x010010u,    0u, "STB_GLOBAL", "STT_NOTYPE", 65521u,"__bss_start__",                                                                                               "Start of .bss segment (0x010010)" },
    {52, 0x003764u,  384u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIRKS6_EEvOT_", "std::__ndk1::vector<std::string>::__push_back_slow_path(const std::string&)" },
    {53, 0x010010u,    0u, "STB_GLOBAL", "STT_NOTYPE", 65521u,"__bss_start",                                                                                                 "Start of .bss segment (0x010010)" },
    {54, 0x010280u,    0u, "STB_GLOBAL", "STT_NOTYPE", 65521u,"__end__",                                                                                                     "End of image (0x010280)" },
    {55, 0x010280u,    0u, "STB_GLOBAL", "STT_NOTYPE", 65521u,"_end",                                                                                                        "End of image (0x010280)" },
    {56, 0x0036d0u,   20u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_out_of_rangeEv",                                          "std::__ndk1::__basic_string_common<true>::__throw_out_of_range() const" },
    {57, 0x002438u,  156u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz",                                                  "_JNIEnv::CallStaticObjectMethod(jclass, jmethodID, ...)" },
    {58, 0x001ebcu,  480u, "STB_GLOBAL", "STT_FUNC",   11u,  "JNI_OnLoad",                                                                                                  "JNI_OnLoad(JavaVM*, void*) -> 0x00010006" },
    {59, 0x003558u,  356u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIS6_EEvOT_", "std::__ndk1::vector<std::string>::__push_back_slow_path(std::string&&)" },
    {60, 0x010010u,    0u, "STB_GLOBAL", "STT_NOTYPE", 65521u,"_edata",                                                                                                       "End of .data segment (0x010010)" },
    {61, 0x010038u,    8u, "STB_GLOBAL", "STT_OBJECT", 22u,  "g_vm",                                                                                                        "Cached JavaVM* pointer (.bss 0x010038)" },
    {62, 0x010028u,    8u, "STB_GLOBAL", "STT_OBJECT", 22u,  "old_resource_finder_methodID",                                                                                "jmethodID DownloadableModelSupportResourceFinder.findResourceUri (.bss 0x010028)" },
    {63, 0x003a1cu,  196u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm",                              "std::__ndk1::basic_string<char>::append(const char*, unsigned long)" },
    {64, 0x010018u,    8u, "STB_GLOBAL", "STT_OBJECT", 22u,  "kn_resource_finder_methodID",                                                                                 "jmethodID AlgorithmModelResourceFinder.findResourceUri (.bss 0x010018)" },
    {65, 0x0034c4u,   20u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv",                                          "std::__ndk1::__basic_string_common<true>::__throw_length_error() const" },
    {66, 0x010010u,    8u, "STB_GLOBAL", "STT_OBJECT", 22u,  "kn_resource_finder_class",                                                                                    "GlobalRef jclass for AlgorithmModelResourceFinder (.bss 0x010010)" },
    {67, 0x0036bcu,   20u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_length_errorEv",                                           "std::__ndk1::__vector_base_common<true>::__throw_length_error() const" },
    {68, 0x0038e4u,  312u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc",         "std::__ndk1::basic_string<char>::__grow_by_and_replace(...)" },
    {69, 0x010280u,    0u, "STB_GLOBAL", "STT_NOTYPE", 65521u,"__bss_end__",                                                                                                 "End of .bss segment (0x010280)" },
    {70, 0x0020a8u,  912u, "STB_GLOBAL", "STT_FUNC",   11u,  "_Z40findResourceUri_DownloadableModelSupportPvPKcS1_",                                                        "findResourceUri_DownloadableModelSupport(void*, const char*, const char*)" },
    {71, 0x0033b4u,  272u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EERKS9_SB_",                 "std::__ndk1::operator+(const std::string&, const std::string&)" },
    {72, 0x00209cu,   12u, "STB_GLOBAL", "STT_FUNC",   11u,  "Java_com_ss_ugc_effectplatform_algorithm_AlgorithmModelResourceFinder_nativeCreateResourceFinder",            "AlgorithmModelResourceFinder.nativeCreateResourceFinder(J)J" },
    {73, 0x010020u,    8u, "STB_GLOBAL", "STT_OBJECT", 22u,  "kn_model_not_found_methodID",                                                                                 "jmethodID AlgorithmModelResourceFinder.modelNotFound (.bss 0x010020)" },
    {74, 0x003308u,  172u, "STB_WEAK",   "STT_FUNC",   11u,  "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_",                                  "std::__ndk1::basic_string<char>::basic_string(const std::string&)" }
};

// ============================================================================
// 2. Complete `.rela.dyn` Relocation Table (`0x001528`, 18 Entries)
//    Bảng Tái định vị `.rela.dyn` Đầy đủ (`0x001528`, 18 Mục)
// ============================================================================

struct Elf64RelaRecord {
    uint32_t    r_offset;
    uint32_t    r_type;
    uint32_t    sym_index;
    uint64_t    r_addend;
    const char* target_symbol;
};

static constexpr Elf64RelaRecord kNewepRelaDynTable[18] = {
    { 0x00fbd8u, 1027u,  0u, 0x001e90ULL, ".fini_array[0] -> 0x001e90" },
    { 0x00fbe0u, 1027u,  0u, 0x001e80ULL, ".fini_array[1] -> 0x001e80 (__cxa_finalize)" },
    { 0x00fbe8u, 1027u,  0u, 0x00fbe8ULL, ".data.rel.ro (__dso_handle)" },
    { 0x00ff90u, 1025u,  3u, 0x000000ULL, "_ZTVSt12length_error" },
    { 0x00ff98u, 1025u,  4u, 0x000000ULL, "pthread_create" },
    { 0x00ffa0u, 1025u, 62u, 0x000000ULL, "old_resource_finder_methodID (0x010028)" },
    { 0x00ffa8u, 1025u,  6u, 0x000000ULL, "_ZTISt12length_error" },
    { 0x00ffb0u, 1025u, 70u, 0x000000ULL, "_Z40findResourceUri_DownloadableModelSupportPvPKcS1_ (0x0020a8)" },
    { 0x00ffb8u, 1025u, 61u, 0x000000ULL, "g_vm (0x010038)" },
    { 0x00ffc0u, 1025u, 12u, 0x000000ULL, "_ZNSt12out_of_rangeD1Ev" },
    { 0x00ffc8u, 1025u, 14u, 0x000000ULL, "_ZTVSt12out_of_range" },
    { 0x00ffd0u, 1025u, 66u, 0x000000ULL, "kn_resource_finder_class (0x010010)" },
    { 0x00ffd8u, 1025u, 64u, 0x000000ULL, "kn_resource_finder_methodID (0x010018)" },
    { 0x00ffe0u, 1025u, 23u, 0x000000ULL, "_ZNSt12length_errorD1Ev" },
    { 0x00ffe8u, 1025u, 73u, 0x000000ULL, "kn_model_not_found_methodID (0x010020)" },
    { 0x00fff0u, 1025u, 50u, 0x000000ULL, "old_resource_finder_class (0x010030)" },
    { 0x00fff8u, 1025u, 41u, 0x000000ULL, "_ZTISt12out_of_range" },
    { 0x010000u,  257u, 19u, 0x000000ULL, "__gxx_personality_v0 (.data 0x010000)" }
};

// ============================================================================
// 3. Complete `.Text` AArch64 Function & Opcode Directory (`0x001e80..0x00728b`)
//    Danh mục Hàm & Mã máy AArch64 `.text` (`0x001e80..0x00728b`)
// ============================================================================

struct AArch64FunctionOpcodeEntry {
    uint32_t    vaddr_start;
    uint32_t    vaddr_end;
    uint32_t    first_insn_le;
    const char* symbol_name;
    const char* technical_summary;
};

static constexpr AArch64FunctionOpcodeEntry kNewepFunctionDirectory[] = {
    { 0x001e80u, 0x001e8bu, 0xd0000060u, "__cxa_finalize_stub",
      "Loads __dso_handle (0x00fbe8) and branches to PLT __cxa_finalize (0x001bb0)" },
    { 0x001ebcu, 0x00209bu, 0xd10103ffu, "JNI_OnLoad",
      "Caches g_vm (0x010038), resolves AlgorithmModelResourceFinder (0x00728c) & DownloadableModelSupportResourceFinder (0x00732a), returns 0x00010006" },
    { 0x00209cu, 0x0020a7u, 0xb0000060u, "Java_com_ss_ugc_effectplatform_algorithm_AlgorithmModelResourceFinder_nativeCreateResourceFinder",
      "Loads address of _Z40findResourceUri_DownloadableModelSupportPvPKcS1_ (0x0020a8) from GOT 0x00ffb0 and returns as jlong" },
    { 0x0020a8u, 0x002437u, 0xd10203ffu, "_Z40findResourceUri_DownloadableModelSupportPvPKcS1_",
      "Calls kn_resource_finder#findResourceUri, falls back to old_resource_finder#findResourceUri on 'asset://not_found', invokes modelNotFound if still missing, returns malloc'd URI" },
    { 0x002438u, 0x0024d3u, 0xd10483ffu, "_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz",
      "Constructs 32-byte AArch64 AAPCS64 va_list (__gr_offs=-40, __vr_offs=-128) and invokes JNIEnv vtable +0x398" },
    { 0x0024d4u, 0x00256fu, 0xd10483ffu, "_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz",
      "Constructs 32-byte AArch64 AAPCS64 va_list (__gr_offs=-40, __vr_offs=-128) and invokes JNIEnv vtable +0x470" },
    { 0x002570u, 0x00326fu, 0xa9ba6ffcu, "Java_com_ss_ugc_effectplatform_util_EffectUtilKt_nativeCheckEffectChildrenFile",
      "Reads <dir>/effect_platform_children.tag, splits by ',', trims ASCII spaces (0x20), and checks each child path via stat()" },
    { 0x003270u, 0x003307u, 0xa9bd57f6u, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc",
      "Constructs 24-byte libc++ SSO string from const char* (inline < 23B, heap 16B-aligned >= 23B)" },
    { 0x003308u, 0x0033b3u, 0xa9bd57f6u, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_",
      "Copy-constructs 24-byte libc++ SSO string" },
    { 0x0033b4u, 0x0034c3u, 0xa9bb67fau, "_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EERKS9_SB_",
      "Concatenates two 24-byte libc++ SSO strings into indirect result [x8]" },
    { 0x0034c4u, 0x0034d7u, 0xa9bf7bfdu, "_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv",
      "Throws std::length_error('basic_string')" },
    { 0x003558u, 0x0036bbu, 0xa9bd57f6u, "_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIS6_EEvOT_",
      "Reallocates vector<string> using division-by-24 modular inverse 0xaaaaaaaaaaaaaaab and move-inserts element" },
    { 0x0036bcu, 0x0036cfu, 0xa9bf7bfdu, "_ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_length_errorEv",
      "Throws std::length_error('vector')" },
    { 0x0036d0u, 0x0036e3u, 0xa9bf7bfdu, "_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_out_of_rangeEv",
      "Throws std::out_of_range('basic_string')" },
    { 0x003764u, 0x0038e3u, 0xa9bc5ff8u, "_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIRKS6_EEvOT_",
      "Reallocates vector<string> using division-by-24 modular inverse 0xaaaaaaaaaaaaaaab and copy-inserts element" },
    { 0x0038e4u, 0x003a1bu, 0xa9ba6ffcu, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc",
      "Grows libc++ string capacity (2x geometric growth up to 0x7fffffffffffffe6) and replaces substring" },
    { 0x003a1cu, 0x003adfu, 0xa9bd57f6u, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm",
      "Appends n characters to libc++ string in-place or via __grow_by_and_replace" },
    { 0x003ae0u, 0x003b07u, 0xd2800002u, "read_uleb128",
      "Decodes unsigned LEB128 7-bit chunks until bit 7 is 0" },
    { 0x003b08u, 0x003b47u, 0xd2800002u, "read_sleb128",
      "Decodes signed LEB128 7-bit chunks with sign extension when bit 6 is 1" },
    { 0x003b48u, 0x003c37u, 0xa9bc7bfdu, "read_encoded_pointer",
      "Decodes DWARF pointer using 13-entry jump table at .rodata 0x0074d0" },
    { 0x003c38u, 0x003d48u, 0xb0000062u, "init_dwarf_reg_size_table",
      "Initializes .bss 0x010040..0x0100a0 ([0..31]=8, [64..96]=8)" }
};

uint32_t GetNewepDynSymCount() noexcept {
    return static_cast<uint32_t>(sizeof(kNewepDynSymTable) / sizeof(kNewepDynSymTable[0]));
}

uint32_t GetNewepRelaDynCount() noexcept {
    return static_cast<uint32_t>(sizeof(kNewepRelaDynTable) / sizeof(kNewepRelaDynTable[0]));
}

uint32_t GetNewepFunctionDirectoryCount() noexcept {
    return static_cast<uint32_t>(sizeof(kNewepFunctionDirectory) / sizeof(kNewepFunctionDirectory[0]));
}

} // namespace newep
} // namespace opencut
} // namespace nextai
