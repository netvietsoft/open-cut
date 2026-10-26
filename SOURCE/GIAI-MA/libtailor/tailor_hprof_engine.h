/**
 * @file tailor_hprof_engine.h
 * @brief ByteDance Tailor HPROF Binary Stream Cropper Engine (`Tailor` class,
 *        `tailor_XHOOK`, `tailor_STRING`, `tailor_LOAD_CLASS`,
 *        `tailor_HEAP_DUMP_SEGMENT`, `tailor_INSTANCE_DUMP_WRITE`,
 *        `tailor_CLASS_DUMP`, `tailor_INSTANCE_DUMP`, `shrinkField`, etc.)
 *        Bộ máy cắt gọt luồng nhị phân HPROF của ByteDance Tailor.
 *
 * Binary Ground Truth (libtailor.so - 84,136 bytes, AArch64):
 * - `_ZN6Tailor4initEv` (`0x00b068..0x00b150`)
 * - `_Z18initKeepClassIDSetv` (`0x00b154..0x00b264`)
 * - `_Z10clearCachev` (`0x00b268..0x00b348`)
 * - `_ZN6Tailor12tailor_XHOOKEPKcm` (`0x00b34c..0x00b444`)
 * - `_Z13tailor_STRINGP6Streamj` (`0x00b448..0x00b54c`)
 * - `_Z17tailor_LOAD_CLASSP6Streamj` (`0x00b550..0x00b68c`)
 * - `_Z24tailor_HEAP_DUMP_SEGMENTP6Stream` (`0x00b690..0x00b884`)
 * - `_Z26tailor_INSTANCE_DUMP_WRITEP6Stream` (`0x00b888..0x00bd34`)
 * - `_Z20tailor_HEAP_DUMP_ENDP6Stream` (`0x00bd38..0x00bd68`)
 * - `_Z17tailor_CLASS_DUMPP6Streamj` (`0x00bd6c..0x00c25c`)
 * - `_Z20tailor_INSTANCE_DUMPP6Streamj` (`0x00c260..0x00c410`)
 * - `_Z24tailor_OBJECT_ARRAY_DUMPP6Streamj` (`0x00c414..0x00c46c`)
 * - `_Z27tailor_PRIMITIVE_ARRAY_DUMPP6Streamj` (`0x00c470..0x00c548`)
 * - `_Z11shrinkField12HprofTypeTag` (`0x00c5f0..0x00c640`)
 * - `_Z17bytesForTypeSignaturec` (`0x00c644..0x00c690`)
 * - `_Z12bytesForType12HprofTypeTag` (`0x00c694..0x00c6d4`)
 */

#ifndef OPENCUT_TAILOR_HPROF_ENGINE_H_
#define OPENCUT_TAILOR_HPROF_ENGINE_H_

#include "tailor_types.h"
#include "tailor_stream_writer.h"

namespace opencut {
namespace tailor {

/**
 * @brief Returns the byte width of an HPROF basic type tag (`0x00c694..0x00c6d4`).
 *        Trả về độ rộng byte của thẻ kiểu cơ bản HPROF (`0x00c694..0x00c6d4`).
 *
 * AArch64 Disassembly (`0x00c694..0x00c6d4`):
 * - `0x00c694: 08 08 00 51` (`sub w8, w0, #2`)
 * - `0x00c698: 1f 25 00 71` (`cmp w8, #9`)
 * - Lookup table at `.rodata` `0x00523c`:
 *   - `2 (OBJECT) -> 4` (or `BYTE_SIZE` at `0x01bfa8`)
 *   - `4 (BOOLEAN) -> 1`
 *   - `5 (CHAR) -> 2`
 *   - `6 (FLOAT) -> 4`
 *   - `7 (DOUBLE) -> 8`
 *   - `8 (BYTE) -> 1`
 *   - `9 (SHORT) -> 2`
 *   - `10 (INT) -> 4`
 *   - `11 (LONG) -> 8`
 */
uint32_t bytesForType(HprofTypeTag tag) noexcept;

/**
 * @brief Returns whether a field type tag should be kept in cropped instance dumps (`0x00c5f0..0x00c640`).
 *        Kiểm tra xem thẻ kiểu trường có được giữ lại trong bản chụp thực thể rút gọn hay không.
 *
 * AArch64 Disassembly (`0x00c5f0..0x00c640`):
 * - Returns `true` (`1`) when `tag == HPROF_BASIC_OBJECT (2)` (`cmp w0, #2`),
 *   or when `tag == HPROF_BASIC_INT (10)` (`cmp w0, #10`) and SDK condition holds.
 *   Primitive non-object fields (or byte/char arrays) are stripped/shrunk to save space.
 */
bool shrinkField(HprofTypeTag tag) noexcept;

/**
 * @brief Initializes the global HPROF caches (`STRING_CACHE_ID`, `CLASS_CACHE_NAME`,
 *        `CLASS_CACHE_LOAD`, `CLASS_CACHE_DUMP`, `INSTANCE_CACHE_DUMP`, `KEEP_CLASS_IDS`) (`0x00b154..0x00b264`).
 *        Khởi tạo bộ tập hợp `KEEP_CLASS_IDS` cho các lớp cần giữ toàn bộ trường.
 *
 * Whitelisted classes in `.rodata`:
 * - `"java.lang.String"` (`0x004c51`)
 * - `"android.graphics.Bitmap"` (`0x004c62`)
 * - `"java.nio.DirectByteBuffer"` (`0x004c7a`)
 * - `"libcore.util.NativeAllocationRegistry$CleanerThunk"` (`0x004c94`)
 */
void initKeepClassIDSet();

/**
 * @brief Clears and deallocates all global HPROF parsing caches (`0x00b268..0x00b348`).
 *        Xóa và giải phóng toàn bộ các bộ nhớ đệm phân tích HPROF toàn cục (`0x00b268..0x00b348`).
 */
void clearCache();

/**
 * @brief Processes an `HPROF_TAG_STRING` (`0x01`) record (`0x00b448..0x00b54c`).
 *        Xử lý bản ghi `HPROF_TAG_STRING` (`0x01`) (`0x00b448..0x00b54c`).
 */
int tailor_STRING(Stream* stream, uint32_t length);

/**
 * @brief Processes an `HPROF_TAG_LOAD_CLASS` (`0x02`) record (`0x00b550..0x00b68c`).
 *        Xử lý bản ghi `HPROF_TAG_LOAD_CLASS` (`0x02`) (`0x00b550..0x00b68c`).
 */
int tailor_LOAD_CLASS(Stream* stream, uint32_t length);

/**
 * @brief Processes an `HPROF_TAG_HEAP_DUMP` (`0x0C`) or `HPROF_TAG_HEAP_DUMP_SEGMENT` (`0x1C`) record (`0x00b690..0x00b884`).
 *        Xử lý bản ghi `HPROF_TAG_HEAP_DUMP` (`0x0C`) hoặc `HPROF_TAG_HEAP_DUMP_SEGMENT` (`0x1C`).
 */
int tailor_HEAP_DUMP_SEGMENT(Stream* stream);

/**
 * @brief Flushes buffered `InstanceDump` records after `ClassDump` metadata has been resolved (`0x00b888..0x00bd34`).
 *        Ghi toàn bộ các bản ghi `InstanceDump` đã đệm sau khi siêu dữ liệu `ClassDump` được giải quyết.
 */
void tailor_INSTANCE_DUMP_WRITE(Stream* stream);

/**
 * @brief Processes an `HPROF_TAG_HEAP_DUMP_END` (`0x2C`) record (`0x00bd38..0x00bd68`).
 *        Xử lý bản ghi `HPROF_TAG_HEAP_DUMP_END` (`0x2C`) (`0x00bd38..0x00bd68`).
 */
int tailor_HEAP_DUMP_END(Stream* stream);

/**
 * @brief Processes an `HPROF_GC_CLASS_DUMP` (`0x20`) sub-record (`0x00bd6c..0x00c25c`).
 *        Xử lý bản ghi con `HPROF_GC_CLASS_DUMP` (`0x20`) (`0x00bd6c..0x00c25c`).
 */
int tailor_CLASS_DUMP(Stream* stream, uint32_t offset);

/**
 * @brief Processes an `HPROF_GC_INSTANCE_DUMP` (`0x21`) sub-record (`0x00c260..0x00c410`).
 *        Xử lý bản ghi con `HPROF_GC_INSTANCE_DUMP` (`0x21`) (`0x00c260..0x00c410`).
 */
int tailor_INSTANCE_DUMP(Stream* stream, uint32_t offset);

/**
 * @brief Processes an `HPROF_GC_OBJ_ARRAY_DUMP` (`0x22`) sub-record (`0x00c414..0x00c46c`).
 *        Xử lý bản ghi con `HPROF_GC_OBJ_ARRAY_DUMP` (`0x22`) (`0x00c414..0x00c46c`).
 */
int tailor_OBJECT_ARRAY_DUMP(Stream* stream, uint32_t offset);

/**
 * @brief Processes an `HPROF_GC_PRIM_ARRAY_DUMP` (`0x23`) sub-record (`0x00c470..0x00c548`).
 *        Xử lý bản ghi con `HPROF_GC_PRIM_ARRAY_DUMP` (`0x23`) (`0x00c470..0x00c548`).
 *
 * Strips primitive array elements! Copies only the 17-byte header
 * (`subtag:1 + obj_id:4 + stack_serial:4 + num_elements:4 + elem_type:1`),
 * zeroes the `num_elements` field (`stream->fillZero(offset + 9, 4)`), and skips
 * the `num_elements * bytesForType(elem_type)` payload (`stream->skip(...)`)!
 */
int tailor_PRIMITIVE_ARRAY_DUMP(Stream* stream, uint32_t offset);

/**
 * @brief Reconstructed `Tailor` implementation matching `_ZTV6Tailor` (`0x0178a0`).
 *        Lớp `Tailor` tái tạo khớp với bảng phương thức ảo `_ZTV6Tailor` (`0x0178a0`).
 */
class TailorImpl final : public Tailor {
public:
    /**
     * @brief Constructs a `TailorImpl` writing to `target_path` with optional gzip (`0x00dc88..0x00dd04`).
     *        Khởi tạo `TailorImpl` ghi ra `target_path` với tùy chọn nén gzip.
     */
    TailorImpl(const char* target_path, bool gzip);

    /**
     * @brief Destructor (`_ZN6TailorD2Ev` at `0x00dd08..0x00dd78`, `_ZN6TailorD0Ev` at `0x00dd7c..0x00dda4`).
     *        Hàm hủy giải phóng `Stream`, `Writer` và các bộ nhớ đệm toàn cục.
     */
    ~TailorImpl() override;

    /**
     * @brief Initializes global `std::map` / `std::vector` / `std::set` caches (`_ZN6Tailor4initEv` at `0x00b068..0x00b150`).
     *        Khởi tạo các bộ nhớ đệm `std::map` / `std::vector` / `std::set` toàn cục.
     */
    void init();

    /**
     * @brief Incrementally parses and crops `count` bytes from `buf` (`_ZN6Tailor12tailor_XHOOKEPKcm` at `0x00b34c..0x00b444`).
     *        Phân tích và cắt gọt tăng dần `count` byte từ `buf`.
     */
    int handle(const char* buf, size_t count) override;

    Stream* stream() const noexcept { return stream_; }
    Writer* writer() const noexcept { return writer_; }

private:
    int tailor_XHOOK(const char* buf, size_t count);
};

} // namespace tailor
} // namespace opencut

#endif // OPENCUT_TAILOR_HPROF_ENGINE_H_
