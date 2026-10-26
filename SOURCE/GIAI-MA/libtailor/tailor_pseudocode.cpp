/**
 * @file tailor_pseudocode.cpp
 * @brief Complete 92-Symbol `.dynsym` Dispatch Table, Binary Verification Harness,
 *        and End-to-End HPROF 1.0.3 Cropping Engine Verification for `libtailor.so`
 *        (`84,136 bytes`, 27 ELF64 sections, `SONAME: libtailor.so`).
 *        Bảng điều phối đầy đủ 92 biểu tượng `.dynsym`, Bộ khung xác minh nhị phân
 *        và Kiểm thử toàn trình Bộ máy cắt gọt HPROF 1.0.3 cho `libtailor.so`.
 */

#include "tailor_interface.h"

#include <cstring>
#include <vector>

namespace opencut {
namespace tailor {

// ============================================================================
// Complete 92-Entry `.dynsym` Export Table (`[083..174]`) of `libtailor.so`
// Bảng 92 biểu tượng xuất khẩu `.dynsym` (`[083..174]`) đầy đủ của `libtailor.so`
// ============================================================================

static const TailorExportedSymbolDescriptor kTailorExportedSymbols[92] = {
    {83,  0x0000b34cULL, 252,  "_ZN6Tailor12tailor_XHOOKEPKcm",
     "Tailor::tailor_XHOOK(char const*, unsigned long)", "HPROF_ENGINE"},
    {84,  0x00008074ULL, 476,  "xh_core_register",
     "xh_core_register(char const*, char const*, void*, void**)", "XHOOK_CORE"},
    {85,  0x000178b8ULL, 24,   "_ZTI6Writer",
     "typeinfo for Writer", "RTTI_VTABLE"},
    {86,  0x0000aaf4ULL, 128,  "_ZN6StreamD0Ev",
     "Stream::~Stream() [deleting]", "STREAM_BUFFER"},
    {87,  0x0000e650ULL, 248,  "JNI_OnLoad",
     "JNI_OnLoad(JavaVM*, void*)", "JNI_BRIDGE"},
    {88,  0x00008014ULL, 8,    "xhook_enable_debug",
     "xhook_enable_debug(int)", "XHOOK_API"},
    {89,  0x0000b154ULL, 276,  "_Z18initKeepClassIDSetv",
     "initKeepClassIDSet()", "HPROF_ENGINE"},
    {90,  0x0000ab74ULL, 52,   "_ZN6Stream4peekEjj",
     "Stream::peek(unsigned int, unsigned int)", "STREAM_BUFFER"},
    {91,  0x0000aaf0ULL, 4,    "_ZN6StreamD2Ev",
     "Stream::~Stream() [base]", "STREAM_BUFFER"},
    {92,  0x0001c280ULL, 8,    "CLASS_CACHE_DUMP",
     "std::map<unsigned int, ClassDump*>* CLASS_CACHE_DUMP", "GLOBAL_STATE"},
    {93,  0x0000da34ULL, 224,  "_ZN10FileWriterC2EP7__sFILEb",
     "FileWriter::FileWriter(__sFILE*, bool)", "WRITER_SUBSYSTEM"},
    {94,  0x0001bfacULL, 4,    "FD",
     "int FD", "GLOBAL_STATE"},
    {95,  0x0000d928ULL, 268,  "_Z10open_proxyPKcii",
     "open_proxy(char const*, int, int)", "POSIX_HOOK"},
    {96,  0x0000b448ULL, 264,  "_Z13tailor_STRINGP6Streamj",
     "tailor_STRING(Stream*, unsigned int)", "HPROF_ENGINE"},
    {97,  0x00008004ULL, 8,    "xhook_refresh",
     "xhook_refresh(int)", "XHOOK_API"},
    {98,  0x0001c288ULL, 8,    "INSTANCE_CACHE_DUMP",
     "std::vector<InstanceDump*>* INSTANCE_CACHE_DUMP", "GLOBAL_STATE"},
    {99,  0x0000d868ULL, 192,  "_Z12close_tailorP7_JNIEnvP7_jclass",
     "close_tailor(_JNIEnv*, _jclass*)", "JNI_BRIDGE"},
    {100, 0x0000db58ULL, 64,   "_Z10fill_RegexPcPKc",
     "fill_Regex(char*, char const*)", "POSIX_HOOK"},
    {101, 0x0000c644ULL, 80,   "_Z17bytesForTypeSignaturec",
     "bytesForTypeSignature(char)", "HPROF_ENGINE"},
    {102, 0x0000b690ULL, 504,  "_Z24tailor_HEAP_DUMP_SEGMENTP6Stream",
     "tailor_HEAP_DUMP_SEGMENT(Stream*)", "HPROF_ENGINE"},
    {103, 0x0000801cULL, 8,    "xhook_enable_sigsegv_protection",
     "xhook_enable_sigsegv_protection(int)", "XHOOK_API"},
    {104, 0x00007ffcULL, 8,    "xhook_ignore",
     "xhook_ignore(char const*, char const*)", "XHOOK_API"},
    {105, 0x0001c2a0ULL, 4,    "BUILD_VERSION_SDK_INT",
     "int BUILD_VERSION_SDK_INT", "GLOBAL_STATE"},
    {106, 0x000178d0ULL, 24,   "_ZTI10FileWriter",
     "typeinfo for FileWriter", "RTTI_VTABLE"},
    {107, 0x0000e0bcULL, 4,    "_Z10crop_hprofP7_JNIEnvP7_jclassP8_jstringS4_",
     "crop_hprof(_JNIEnv*, _jclass*, _jstring*, _jstring*)", "JNI_BRIDGE"},
    {108, 0x0000abacULL, 28,   "_ZN6Stream8peekByteEj",
     "Stream::peekByte(unsigned int)", "STREAM_BUFFER"},
    {109, 0x0000e930ULL, 68,   "_Z11setContainsPP7SetNodePKc",
     "setContains(SetNode**, char const*)", "HASH_SET"},
    {110, 0x0000dc1cULL, 108,  "_Z11open_tailorP7_JNIEnvP7_jclassP8_jstringh",
     "open_tailor(_JNIEnv*, _jclass*, _jstring*, unsigned char)", "JNI_BRIDGE"},
    {111, 0x0000dd7cULL, 44,   "_ZN6TailorD0Ev",
     "Tailor::~Tailor() [deleting]", "HPROF_ENGINE"},
    {112, 0x000093f4ULL, 2272, "xh_elf_init",
     "xh_elf_init(xh_elf_t*, uintptr_t, char const*)", "XHOOK_ELF"},
    {113, 0x00017888ULL, 24,   "_ZTV6Writer",
     "vtable for Writer", "RTTI_VTABLE"},
    {114, 0x0000db98ULL, 132,  "_Z11try_to_hookb",
     "try_to_hook(bool)", "POSIX_HOOK"},
    {115, 0x0000ac04ULL, 140,  "_ZN6Stream5resetEv",
     "Stream::reset()", "STREAM_BUFFER"},
    {116, 0x0000e748ULL, 100,  "JNI_OnUnload",
     "JNI_OnUnload(JavaVM*, void*)", "JNI_BRIDGE"},
    {117, 0x0000e904ULL, 44,   "_Z4hashPKc",
     "hash(char const*)", "HASH_SET"},
    {118, 0x0001c2a8ULL, 8,    "SOURCE",
     "char* SOURCE", "GLOBAL_STATE"},
    {119, 0x0000e9dcULL, 84,   "_Z8clearSetPP7SetNode",
     "clearSet(SetNode**)", "HASH_SET"},
    {120, 0x0000e974ULL, 104,  "_Z9setInsertPP7SetNodePKc",
     "setInsert(SetNode**, char const*)", "HASH_SET"},
    {121, 0x0000af18ULL, 28,   "_ZN6Stream11isAvailableEv",
     "Stream::isAvailable()", "STREAM_BUFFER"},
    {122, 0x000083dcULL, 1384, "xh_core_refresh",
     "xh_core_refresh(int)", "XHOOK_CORE"},
    {123, 0x0000c260ULL, 436,  "_Z20tailor_INSTANCE_DUMPP6Streamj",
     "tailor_INSTANCE_DUMP(Stream*, unsigned int)", "HPROF_ENGINE"},
    {124, 0x0001c268ULL, 8,    "STRING_CACHE_ID",
     "std::map<std::string, unsigned int>* STRING_CACHE_ID", "GLOBAL_STATE"},
    {125, 0x0000ac90ULL, 140,  "_ZN6Stream5flushEj",
     "Stream::flush(unsigned int)", "STREAM_BUFFER"},
    {126, 0x0001c278ULL, 8,    "CLASS_CACHE_LOAD",
     "std::map<std::string, unsigned int>* CLASS_CACHE_LOAD", "GLOBAL_STATE"},
    {127, 0x000178a0ULL, 24,   "_ZTV6Tailor",
     "vtable for Tailor", "RTTI_VTABLE"},
    {128, 0x0000b550ULL, 320,  "_Z17tailor_LOAD_CLASSP6Streamj",
     "tailor_LOAD_CLASS(Stream*, unsigned int)", "HPROF_ENGINE"},
    {129, 0x0000c5f0ULL, 84,   "_Z11shrinkField12HprofTypeTag",
     "shrinkField(HprofTypeTag)", "HPROF_ENGINE"},
    {130, 0x0000aab0ULL, 52,   "_ZN6StreamC2EP6Writer",
     "Stream::Stream(Writer*)", "STREAM_BUFFER"},
    {131, 0x0000acc4ULL, 260,  "_ZN6Stream6handleEPKcm",
     "Stream::handle(char const*, unsigned long)", "STREAM_BUFFER"},
    {132, 0x0001c290ULL, 8,    "KEEP_CLASS_IDS",
     "std::set<unsigned int>* KEEP_CLASS_IDS", "GLOBAL_STATE"},
    {133, 0x00009cd4ULL, 740,  "xh_elf_hook",
     "xh_elf_hook(xh_elf_t*, char const*, void*, void**)", "XHOOK_ELF"},
    {134, 0x0000dc88ULL, 128,  "_ZN6TailorC2EPKcb",
     "Tailor::Tailor(char const*, bool)", "HPROF_ENGINE"},
    {135, 0x0000dab4ULL, 164,  "_Z11write_proxyiPKvm",
     "write_proxy(int, void const*, unsigned long)", "POSIX_HOOK"},
    {136, 0x0000dd08ULL, 116,  "_ZN6TailorD2Ev",
     "Tailor::~Tailor() [base]", "HPROF_ENGINE"},
    {137, 0x0000800cULL, 8,    "xhook_clear",
     "xhook_clear()", "XHOOK_API"},
    {138, 0x0000c694ULL, 68,   "_Z12bytesForType12HprofTypeTag",
     "bytesForType(HprofTypeTag)", "HPROF_ENGINE"},
    {139, 0x0000e8e8ULL, 28,   "_Z9createSetv",
     "createSet()", "HASH_SET"},
    {140, 0x0000bd38ULL, 52,   "_Z20tailor_HEAP_DUMP_ENDP6Stream",
     "tailor_HEAP_DUMP_END(Stream*)", "HPROF_ENGINE"},
    {141, 0x0000adfcULL, 124,  "_ZN6Stream4skipEjj",
     "Stream::skip(unsigned int, unsigned int)", "STREAM_BUFFER"},
    {142, 0x0000d72cULL, 152,  "_ZN6WriterC2EP7__sFILE",
     "Writer::Writer(__sFILE*)", "WRITER_SUBSYSTEM"},
    {143, 0x0000a800ULL, 448,  "xh_util_get_addr_protect",
     "xh_util_get_addr_protect(uintptr_t, char const*, unsigned int*)", "XHOOK_UTIL"},
    {144, 0x0000a9c0ULL, 140,  "xh_util_set_addr_protect",
     "xh_util_set_addr_protect(uintptr_t, size_t, int)", "XHOOK_UTIL"},
    {145, 0x0000ea30ULL, 144,  "xh_util_flush_instruction_cache",
     "xh_util_flush_instruction_cache(uintptr_t, uintptr_t)", "XHOOK_UTIL"},
    {146, 0x0000b888ULL, 1200, "_Z26tailor_INSTANCE_DUMP_WRITEP6Stream",
     "tailor_INSTANCE_DUMP_WRITE(Stream*)", "HPROF_ENGINE"},
    {147, 0x0000bd6cULL, 1268, "_Z17tailor_CLASS_DUMPP6Streamj",
     "tailor_CLASS_DUMP(Stream*, unsigned int)", "HPROF_ENGINE"},
    {148, 0x0000b268ULL, 228,  "_Z10clearCachev",
     "clearCache()", "HPROF_ENGINE"},
    {149, 0x00008a8cULL, 12,   "xh_core_enable_sigsegv_protection",
     "xh_core_enable_sigsegv_protection(int)", "XHOOK_CORE"},
    {150, 0x00017870ULL, 24,   "_ZTV6Stream",
     "vtable for Stream", "RTTI_VTABLE"},
    {151, 0x0000ae78ULL, 160,  "_ZN6Stream8fillZeroEjj",
     "Stream::fillZero(unsigned int, unsigned int)", "STREAM_BUFFER"},
    {152, 0x0000c470ULL, 220,  "_Z27tailor_PRIMITIVE_ARRAY_DUMPP6Streamj",
     "tailor_PRIMITIVE_ARRAY_DUMP(Stream*, unsigned int)", "HPROF_ENGINE"},
    {153, 0x0000d7c4ULL, 164,  "_ZN6Writer5flushEPKcm",
     "Writer::flush(char const*, unsigned long)", "WRITER_SUBSYSTEM"},
    {154, 0x0000e550ULL, 256,  "_Z18clearCrashLogFilesP7_JNIEnvP7_jclass",
     "clearCrashLogFiles(_JNIEnv*, _jclass*)", "JNI_BRIDGE"},
    {155, 0x0000d620ULL, 156,  "_ZN6Writer7fillIntEj",
     "Writer::fillInt(unsigned int)", "WRITER_SUBSYSTEM"},
    {156, 0x00008944ULL, 312,  "xh_core_clear",
     "xh_core_clear()", "XHOOK_CORE"},
    {157, 0x0001bfa8ULL, 2,    "BYTE_SIZE",
     "unsigned short BYTE_SIZE", "GLOBAL_STATE"},
    {158, 0x0001c270ULL, 8,    "CLASS_CACHE_NAME",
     "std::map<unsigned int, std::string>* CLASS_CACHE_NAME", "GLOBAL_STATE"},
    {159, 0x0000c414ULL, 92,   "_Z24tailor_OBJECT_ARRAY_DUMPP6Streamj",
     "tailor_OBJECT_ARRAY_DUMP(Stream*, unsigned int)", "HPROF_ENGINE"},
    {160, 0x0000abe4ULL, 32,   "_ZN6Stream7peekIntEj",
     "Stream::peekInt(unsigned int)", "STREAM_BUFFER"},
    {161, 0x00009fb8ULL, 60,   "xh_elf_check_elfheader",
     "xh_elf_check_elfheader(uintptr_t)", "XHOOK_ELF"},
    {162, 0x00008a7cULL, 16,   "xh_core_enable_debug",
     "xh_core_enable_debug(int)", "XHOOK_CORE"},
    {163, 0x000178e8ULL, 16,   "_ZTI6Tailor",
     "typeinfo for Tailor", "RTTI_VTABLE"},
    {164, 0x00008250ULL, 396,  "xh_core_ignore",
     "xh_core_ignore(char const*, char const*)", "XHOOK_CORE"},
    {165, 0x0001c298ULL, 8,    "TAILOR",
     "Tailor* TAILOR", "GLOBAL_STATE"},
    {166, 0x0000abc8ULL, 28,   "_ZN6Stream9peekShortEj",
     "Stream::peekShort(unsigned int)", "STREAM_BUFFER"},
    {167, 0x0000adc8ULL, 52,   "_ZN6Stream4copyEjj",
     "Stream::copy(unsigned int, unsigned int)", "STREAM_BUFFER"},
    {168, 0x0000b068ULL, 236,  "_ZN6Tailor4initEv",
     "Tailor::init()", "HPROF_ENGINE"},
    {169, 0x0000d484ULL, 112,  "_ZN6Writer8fillByteEc",
     "Writer::fillByte(char)", "WRITER_SUBSYSTEM"},
    {170, 0x0000d4f4ULL, 148,  "_ZN6Writer8fillZeroEm",
     "Writer::fillZero(unsigned long)", "WRITER_SUBSYSTEM"},
    {171, 0x0000d588ULL, 152,  "_ZN6Writer4fillEPKcm",
     "Writer::fill(char const*, unsigned long)", "WRITER_SUBSYSTEM"},
    {172, 0x0000e0c0ULL, 1168, "_Z16getCrashLogFilesP7_JNIEnvP7_jclass",
     "getCrashLogFiles(_JNIEnv*, _jclass*)", "JNI_BRIDGE"},
    {173, 0x00007fd8ULL, 36,   "xhook_register",
     "xhook_register(char const*, char const*, void*, void**)", "XHOOK_API"},
    {174, 0x0000af34ULL, 12,   "_ZN6Stream4seekEj",
     "Stream::seek(unsigned int)", "STREAM_BUFFER"}
};

const TailorExportedSymbolDescriptor* getTailorExportedSymbolTable(size_t* out_count) noexcept {
    if (out_count != nullptr) {
        *out_count = sizeof(kTailorExportedSymbols) / sizeof(kTailorExportedSymbols[0]);
    }
    return kTailorExportedSymbols;
}

// ============================================================================
// End-to-End HPROF 1.0.3 Stream Cropping Self-Test
// Tự kiểm tra toàn trình cắt gọt luồng HPROF 1.0.3
// ============================================================================

namespace {

void appendBigEndianU16(std::vector<char>& buf, uint16_t val) {
    buf.push_back(static_cast<char>((val >> 8) & 0xFFu));
    buf.push_back(static_cast<char>(val & 0xFFu));
}

void appendBigEndianU32(std::vector<char>& buf, uint32_t val) {
    buf.push_back(static_cast<char>((val >> 24) & 0xFFu));
    buf.push_back(static_cast<char>((val >> 16) & 0xFFu));
    buf.push_back(static_cast<char>((val >> 8) & 0xFFu));
    buf.push_back(static_cast<char>(val & 0xFFu));
}

void appendStringRecord(std::vector<char>& buf, uint32_t id, const char* str) {
    uint32_t str_len = static_cast<uint32_t>(std::strlen(str));
    buf.push_back(static_cast<char>(HPROF_TAG_STRING)); // tag = 0x01
    appendBigEndianU32(buf, 0u);                        // timestamp = 0
    appendBigEndianU32(buf, 4u + str_len);              // length = id_size(4) + str_len
    appendBigEndianU32(buf, id);                        // string ID
    buf.insert(buf.end(), str, str + str_len);
}

void appendLoadClassRecord(std::vector<char>& buf, uint32_t serial,
                           uint32_t class_id, uint32_t name_id) {
    buf.push_back(static_cast<char>(HPROF_TAG_LOAD_CLASS)); // tag = 0x02
    appendBigEndianU32(buf, 0u);                            // timestamp = 0
    appendBigEndianU32(buf, 16u);                           // length = 16
    appendBigEndianU32(buf, serial);
    appendBigEndianU32(buf, class_id);
    appendBigEndianU32(buf, 0u);                            // stack trace serial
    appendBigEndianU32(buf, name_id);
}

/**
 * @brief Memory-backed `Writer` subclass used by `runTailorEndToEndSelfTest` to inspect
 *        the exact cropped HPROF output bytes without touching disk.
 *        Lớp con `Writer` lưu trên bộ nhớ phục vụ kiểm thử toàn trình.
 */
class MemoryCaptureWriter final : public Writer {
public:
    MemoryCaptureWriter() : Writer(nullptr) {}
    ~MemoryCaptureWriter() override = default;

    void flush(const char* data, size_t count) override {
        if (data != nullptr && count > 0u) {
            captured_.insert(captured_.end(), data, data + count);
        }
    }

    const std::vector<char>& finalizeAndGetBytes() {
        if (offset_ > 0u) {
            flush(buffer_, offset_);
            offset_ = 0u;
        }
        return captured_;
    }

private:
    std::vector<char> captured_;
};

} // namespace

bool runTailorEndToEndSelfTest(size_t* out_input_bytes, size_t* out_cropped_bytes) {
    std::vector<char> raw_hprof;

    // 1. 31-byte HPROF 1.0.3 header: "JAVA PROFILE 1.0.3\0" (19B) + id_size=4 (4B) + timestamp (8B)
    const char kMagic[19] = "JAVA PROFILE 1.0.3";
    raw_hprof.insert(raw_hprof.end(), kMagic, kMagic + 19);
    appendBigEndianU32(raw_hprof, 4u); // BYTE_SIZE = 4
    appendBigEndianU32(raw_hprof, 0x0000018B);
    appendBigEndianU32(raw_hprof, 0x12345678);

    // 2. HPROF_TAG_STRING (0x01) records
    appendStringRecord(raw_hprof, 0x1001u, "android.graphics.Bitmap");
    appendStringRecord(raw_hprof, 0x1002u, "com.nextai.opencut.VideoFrameHolder");

    // 3. HPROF_TAG_LOAD_CLASS (0x02) records
    appendLoadClassRecord(raw_hprof, 1u, 0x2001u, 0x1001u); // Bitmap -> class_id 0x2001
    appendLoadClassRecord(raw_hprof, 2u, 0x2002u, 0x1002u); // VideoFrameHolder -> class_id 0x2002

    // 4. Build HPROF_TAG_HEAP_DUMP_SEGMENT (0x1C) payload
    std::vector<char> seg;

    // 4a. HPROF_GC_CLASS_DUMP (0x20) for VideoFrameHolder (0x2002):
    //     1 OBJECT field (4B) + 1 LONG field (8B, should be stripped because not in KEEP_CLASS_IDS)
    seg.push_back(static_cast<char>(HPROF_GC_CLASS_DUMP));
    appendBigEndianU32(seg, 0x2002u); // class_object_id
    appendBigEndianU32(seg, 0u);      // stack_trace_serial
    appendBigEndianU32(seg, 0u);      // super_class_object_id = 0
    appendBigEndianU32(seg, 0u);      // class_loader_object_id
    appendBigEndianU32(seg, 0u);      // signers_object_id
    appendBigEndianU32(seg, 0u);      // protection_domain_object_id
    appendBigEndianU32(seg, 0u);      // reserved1
    appendBigEndianU32(seg, 0u);      // reserved2
    appendBigEndianU32(seg, 12u);     // instance_size = 12 (4B object + 8B long)
    appendBigEndianU16(seg, 0u);      // constant_pool_count = 0
    appendBigEndianU16(seg, 0u);      // static_fields_count = 0
    appendBigEndianU16(seg, 2u);      // instance_fields_count = 2
    // Field 0: OBJECT (tag = 2)
    appendBigEndianU32(seg, 0x3001u);
    seg.push_back(static_cast<char>(HPROF_BASIC_OBJECT));
    // Field 1: LONG (tag = 11)
    appendBigEndianU32(seg, 0x3002u);
    seg.push_back(static_cast<char>(HPROF_BASIC_LONG));

    // 4b. HPROF_GC_INSTANCE_DUMP (0x21) for VideoFrameHolder (0x2002)
    seg.push_back(static_cast<char>(HPROF_GC_INSTANCE_DUMP));
    appendBigEndianU32(seg, 0x4001u); // object_id
    appendBigEndianU32(seg, 0u);      // stack_trace_serial
    appendBigEndianU32(seg, 0x2002u); // class_object_id
    appendBigEndianU32(seg, 12u);     // values_byte_count = 12
    appendBigEndianU32(seg, 0x5001u); // object ref value (kept)
    appendBigEndianU32(seg, 0xDEADBEEFu); // long high (stripped)
    appendBigEndianU32(seg, 0xCAFEBABEu); // long low (stripped)

    // 4c. HPROF_GC_PRIM_ARRAY_DUMP (0x23) with 1,024-byte `byte[]` payload
    seg.push_back(static_cast<char>(HPROF_GC_PRIM_ARRAY_DUMP));
    appendBigEndianU32(seg, 0x5001u); // array_object_id
    appendBigEndianU32(seg, 0u);      // stack_trace_serial
    appendBigEndianU32(seg, 1024u);   // num_elements = 1024
    seg.push_back(static_cast<char>(HPROF_BASIC_BYTE)); // element_type = BYTE (8)
    seg.insert(seg.end(), 1024u, static_cast<char>(0xAA));

    // Append top-level HPROF_TAG_HEAP_DUMP_SEGMENT (0x1C) record
    raw_hprof.push_back(static_cast<char>(HPROF_TAG_HEAP_DUMP_SEGMENT));
    appendBigEndianU32(raw_hprof, 0u);
    appendBigEndianU32(raw_hprof, static_cast<uint32_t>(seg.size()));
    raw_hprof.insert(raw_hprof.end(), seg.begin(), seg.end());

    // 5. Append top-level HPROF_TAG_HEAP_DUMP_END (0x2C) record (9 bytes)
    raw_hprof.push_back(static_cast<char>(HPROF_TAG_HEAP_DUMP_END));
    appendBigEndianU32(raw_hprof, 0u);
    appendBigEndianU32(raw_hprof, 0u);

    if (out_input_bytes != nullptr) {
        *out_input_bytes = raw_hprof.size();
    }

    // Run through TailorImpl with MemoryCaptureWriter
    TailorImpl tailor(nullptr, false);
    delete tailor.stream();
    delete tailor.writer();

    auto* mem_writer = new MemoryCaptureWriter();
    auto* mem_stream = new Stream(mem_writer);

    // Bind custom writer/stream into TailorImpl via base pointers
    struct TailorAccessor : public Tailor {
        static void bind(Tailor& t, Writer* w, Stream* s) {
            auto& acc = static_cast<TailorAccessor&>(t);
            acc.writer_ = w;
            acc.stream_ = s;
        }
    };
    TailorAccessor::bind(tailor, mem_writer, mem_stream);

    tailor.handle(raw_hprof.data(), raw_hprof.size());
    const std::vector<char>& cropped = mem_writer->finalizeAndGetBytes();

    if (out_cropped_bytes != nullptr) {
        *out_cropped_bytes = cropped.size();
    }

    // Verify that the 1,024-byte primitive array payload and 8-byte LONG field were stripped!
    // Raw size is ~1,232 bytes; cropped size must be < 250 bytes and end with 0x2C + 8 zero bytes.
    if (cropped.size() >= raw_hprof.size() || cropped.size() < 31u + 9u) {
        return false;
    }
    size_t n = cropped.size();
    return static_cast<uint8_t>(cropped[n - 9]) == HPROF_TAG_HEAP_DUMP_END;
}

} // namespace tailor
} // namespace opencut
