/**
 * @file tailor_hprof_engine.cpp
 * @brief Implementation of ByteDance Tailor HPROF Binary Stream Cropper Engine
 *        (`0x00b068..0x00c6d4`, `0x00dc88..0x00dda4`).
 *        Triển khai Bộ máy cắt gọt luồng nhị phân HPROF của ByteDance Tailor.
 */

#include "tailor_hprof_engine.h"

#include <cstring>

namespace opencut {
namespace tailor {

// ============================================================================
// Global Data & BSS Definitions (`0x01bfa8..0x01c2a0`)
// Định nghĩa dữ liệu toàn cục & BSS (`0x01bfa8..0x01c2a0`)
// ============================================================================

/**
 * `.data` at `0x01bfa8`: `uint16_t BYTE_SIZE = 4;` (`0x0004`)
 * Kích thước mã định danh đối tượng mặc định `BYTE_SIZE = 4`.
 */
uint16_t BYTE_SIZE = 4;

/**
 * `.bss` at `0x01c268..0x01c2a0`
 */
std::map<std::string, uint32_t>* STRING_CACHE_ID = nullptr;
std::map<uint32_t, std::string>* CLASS_CACHE_NAME = nullptr;
std::map<std::string, uint32_t>* CLASS_CACHE_LOAD = nullptr;
std::map<uint32_t, ClassDump*>* CLASS_CACHE_DUMP = nullptr;
std::vector<InstanceDump*>* INSTANCE_CACHE_DUMP = nullptr;
std::set<uint32_t>* KEEP_CLASS_IDS = nullptr;
int BUILD_VERSION_SDK_INT = 29;

// ============================================================================
// Helper Functions (`bytesForType`, `shrinkField`, `initKeepClassIDSet`, `clearCache`)
// Các hàm bổ trợ (`bytesForType`, `shrinkField`, `initKeepClassIDSet`, `clearCache`)
// ============================================================================

uint32_t bytesForType(HprofTypeTag tag) noexcept {
    /**
     * Exact AArch64 disassembly of `_Z12bytesForType12HprofTypeTag` (`0x00c694..0x00c6d4`):
     *   0x00c694: 08 08 00 51  sub w8, w0, #2
     *   0x00c698: 1f 25 00 71  cmp w8, #9
     *   0x00c69c: 48 01 00 54  b.hi 0xc6c4
     *   0x00c6a0: 09 00 00 90  adrp x9, #0x5000
     *   0x00c6a4: 29 f1 08 91  add x9, x9, #0x23c  ; .rodata lookup table @ 0x00523c
     *   0x00c6a8: 28 79 68 38  ldrb w8, [x9, x8]
     *   Looking up `.rodata` @ `0x00523c`:
     *   tag=2 (OBJECT)  -> BYTE_SIZE (4)
     *   tag=4 (BOOLEAN) -> 1
     *   tag=5 (CHAR)    -> 2
     *   tag=6 (FLOAT)   -> 4
     *   tag=7 (DOUBLE)  -> 8
     *   tag=8 (BYTE)    -> 1
     *   tag=9 (SHORT)   -> 2
     *   tag=10 (INT)    -> 4
     *   tag=11 (LONG)   -> 8
     */
    switch (tag) {
        case HPROF_BASIC_OBJECT:
            return BYTE_SIZE;
        case HPROF_BASIC_BOOLEAN:
        case HPROF_BASIC_BYTE:
            return 1u;
        case HPROF_BASIC_CHAR:
        case HPROF_BASIC_SHORT:
            return 2u;
        case HPROF_BASIC_FLOAT:
        case HPROF_BASIC_INT:
            return 4u;
        case HPROF_BASIC_DOUBLE:
        case HPROF_BASIC_LONG:
            return 8u;
        default:
            return 0u;
    }
}

bool shrinkField(HprofTypeTag tag) noexcept {
    /**
     * Exact AArch64 disassembly of `_Z11shrinkField12HprofTypeTag` (`0x00c5f0..0x00c640`):
     *   0x00c5f0: 1f 08 00 71  cmp w0, #2          ; HPROF_BASIC_OBJECT
     *   0x00c5f4: 40 01 00 54  b.eq 0xc61c         ; return true (keep object reference)
     *   0x00c5f8: 1f 28 00 71  cmp w0, #0xa        ; HPROF_BASIC_INT
     *   0x00c5fc: 41 01 00 54  b.ne 0xc624         ; if not INT, return false (strip primitive)
     *   0x00c600: 88 00 00 90  adrp x8, #0x1c000
     *   0x00c604: 08 a1 42 b9  ldr w8, [x8, #0x2a0]; BUILD_VERSION_SDK_INT
     *   0x00c608: 08 69 1f 11  sub w8, w8, #0x1a   ; SDK - 26 (Android 8.0 Oreo)
     *   0x00c60c: 1f 09 00 71  cmp w8, #2          ; SDK < 26 (i.e. Android 5..7 Bitmap mWidth/mHeight/mBuffer)
     *   Returns true for HPROF_BASIC_OBJECT (2), or for HPROF_BASIC_INT (10) when SDK is in range.
     */
    if (tag == HPROF_BASIC_OBJECT) {
        return true;
    }
    if (tag == HPROF_BASIC_INT) {
        // On Android 8.0/8.1 (SDK 26, 27), `sub w8, w8, #26; cmp w8, #2` keeps INT fields if needed
        uint32_t sdk_offset = static_cast<uint32_t>(BUILD_VERSION_SDK_INT - 26);
        return sdk_offset >= 2u;
    }
    return false;
}

void initKeepClassIDSet() {
    /**
     * Exact AArch64 disassembly of `_Z18initKeepClassIDSetv` (`0x00b154..0x00b264`):
     * Looks up class IDs in `CLASS_CACHE_LOAD` for the 4 critical classes whose fields
     * must be retained intact (unshrunk) in `KEEP_CLASS_IDS`:
     *   1. `"java.lang.String"` (`0x004c51`)
     *   2. `"android.graphics.Bitmap"` (`0x004c62`)
     *   3. `"java.nio.DirectByteBuffer"` (`0x004c7a`)
     *   4. `"libcore.util.NativeAllocationRegistry$CleanerThunk"` (`0x004c94`)
     */
    if (KEEP_CLASS_IDS == nullptr || CLASS_CACHE_LOAD == nullptr) {
        return;
    }
    static constexpr const char* kWhitelistedClasses[4] = {
        "java.lang.String",
        "android.graphics.Bitmap",
        "java.nio.DirectByteBuffer",
        "libcore.util.NativeAllocationRegistry$CleanerThunk"
    };
    for (const char* cls_name : kWhitelistedClasses) {
        auto it = CLASS_CACHE_LOAD->find(cls_name);
        if (it != CLASS_CACHE_LOAD->end() && it->second != 0u) {
            KEEP_CLASS_IDS->insert(it->second);
        }
    }
}

void clearCache() {
    /**
     * Exact AArch64 disassembly of `_Z10clearCachev` (`0x00b268..0x00b348`):
     * Frees all `ClassDump*` in `CLASS_CACHE_DUMP`, frees all `InstanceDump*` in
     * `INSTANCE_CACHE_DUMP`, and clears all 6 global containers.
     */
    if (STRING_CACHE_ID != nullptr) {
        STRING_CACHE_ID->clear();
    }
    if (CLASS_CACHE_NAME != nullptr) {
        CLASS_CACHE_NAME->clear();
    }
    if (CLASS_CACHE_LOAD != nullptr) {
        CLASS_CACHE_LOAD->clear();
    }
    if (KEEP_CLASS_IDS != nullptr) {
        KEEP_CLASS_IDS->clear();
    }
    if (CLASS_CACHE_DUMP != nullptr) {
        for (auto& kv : *CLASS_CACHE_DUMP) {
            delete kv.second;
        }
        CLASS_CACHE_DUMP->clear();
    }
    if (INSTANCE_CACHE_DUMP != nullptr) {
        for (InstanceDump* inst : *INSTANCE_CACHE_DUMP) {
            delete inst;
        }
        INSTANCE_CACHE_DUMP->clear();
    }
}

// ============================================================================
// HPROF Record Handlers (`0x00b448..0x00c548`)
// Các trình xử lý bản ghi HPROF (`0x00b448..0x00c548`)
// ============================================================================

int tailor_STRING(Stream* stream, uint32_t length) {
    /**
     * Exact AArch64 disassembly of `_Z13tailor_STRINGP6Streamj` (`0x00b448..0x00b54c`):
     * - Layout of `HPROF_TAG_STRING (0x01)` record:
     *   - `[0]`: tag `0x01` (1B)
     *   - `[1..4]`: timestamp (4B)
     *   - `[5..8]`: record length `length` (4B)
     *   - `[9..12]`: string ID `id` (4B, big-endian)
     *   - `[13 .. 9 + length - 1]`: UTF-8 string content (`length - 4` bytes)
     * - Checks if the UTF-8 string matches one of the 4 whitelisted class names in `STRING_CACHE_ID`.
     *   If it matches, stores `STRING_CACHE_ID[str] = id` and flushes the string record (`9 + length` bytes).
     *   Also copies or skips according to whether strings are retained.
     */
    uint32_t total_record_bytes = length + 9u;
    if (stream->available() < total_record_bytes) {
        return 0;
    }

    uint32_t string_id = stream->peekInt(9u);
    uint32_t utf8_len = (length >= BYTE_SIZE) ? (length - BYTE_SIZE) : 0u;
    std::string value(stream->buffer() + 9u + BYTE_SIZE, utf8_len);

    if (STRING_CACHE_ID != nullptr) {
        auto it = STRING_CACHE_ID->find(value);
        if (it != STRING_CACHE_ID->end()) {
            it->second = string_id;
            if (CLASS_CACHE_NAME != nullptr) {
                (*CLASS_CACHE_NAME)[string_id] = value;
            }
        }
    }

    stream->flush(total_record_bytes);
    return 1;
}

int tailor_LOAD_CLASS(Stream* stream, uint32_t length) {
    /**
     * Exact AArch64 disassembly of `_Z17tailor_LOAD_CLASSP6Streamj` (`0x00b550..0x00b68c`):
     * - Layout of `HPROF_TAG_LOAD_CLASS (0x02)` record (`length = 16`, total `25` bytes):
     *   - `[0]`: tag `0x02` (1B)
     *   - `[1..4]`: timestamp (4B)
     *   - `[5..8]`: record length `16` (4B)
     *   - `[9..12]`: class serial number (4B)
     *   - `[13..16]`: class object ID (`class_id`, 4B)
     *   - `[17..20]`: stack trace serial number (4B)
     *   - `[21..24]`: class name string ID (`name_id`, 4B)
     * - Checks if `name_id` is in `CLASS_CACHE_NAME`; if found, records
     *   `CLASS_CACHE_LOAD[class_name] = class_id`.
     * - Flushes all `9 + length` (`25`) bytes to the output stream.
     */
    uint32_t total_record_bytes = length + 9u;
    if (stream->available() < total_record_bytes) {
        return 0;
    }

    uint32_t class_id = stream->peekInt(13u);
    uint32_t name_string_id = stream->peekInt(21u);

    if (CLASS_CACHE_NAME != nullptr && CLASS_CACHE_LOAD != nullptr) {
        auto it = CLASS_CACHE_NAME->find(name_string_id);
        if (it != CLASS_CACHE_NAME->end()) {
            (*CLASS_CACHE_LOAD)[it->second] = class_id;
        }
    }

    stream->flush(total_record_bytes);
    return 1;
}

int tailor_CLASS_DUMP(Stream* stream, uint32_t offset) {
    /**
     * Exact AArch64 disassembly of `_Z17tailor_CLASS_DUMPP6Streamj` (`0x00bd6c..0x00c25c`):
     * Parses `HPROF_GC_CLASS_DUMP (0x20)` starting at `offset`:
     * - `offset + 0`: subtag `0x20` (1B)
     * - `offset + 1`: `class_object_id` (4B)
     * - `offset + 5`: `stack_trace_serial` (4B)
     * - `offset + 9`: `super_class_object_id` (4B)
     * - `offset + 13`: `class_loader_object_id` (4B)
     * - `offset + 17`: `signers_object_id` (4B)
     * - `offset + 21`: `protection_domain_object_id` (4B)
     * - `offset + 25`: `reserved1` (4B)
     * - `offset + 29`: `reserved2` (4B)
     * - `offset + 33`: `instance_size` (4B)
     * - `offset + 37`: `constant_pool_count` (2B)
     *   Followed by `constant_pool_count` entries of `(index:2B, type:1B, value:bytesForType(type))`
     * - Next: `static_fields_count` (2B)
     *   Followed by `static_fields_count` entries of `(name_id:4B, type:1B, value:bytesForType(type))`
     * - Next: `instance_fields_count` (2B)
     *   Followed by `instance_fields_count` entries of `(name_id:4B, type:1B)` (5 bytes each).
     *
     * Stores `ClassDump` in `CLASS_CACHE_DUMP[class_object_id]` and rewrites the
     * `ClassDump` sub-record so that stripped primitive fields are removed from the
     * `instance_fields` descriptor table (unless `class_object_id` is in `KEEP_CLASS_IDS`).
     */
    if (stream->available() < offset + 39u) {
        return -1;
    }

    uint32_t class_id = stream->peekInt(offset + 1u);
    uint32_t super_id = stream->peekInt(offset + 9u);

    uint32_t cursor = offset + 37u;
    uint16_t cp_count = stream->peekShort(cursor);
    cursor += 2u;

    for (uint16_t i = 0; i < cp_count; ++i) {
        if (stream->available() < cursor + 3u) {
            return -1;
        }
        auto tag = static_cast<HprofTypeTag>(stream->peekByte(cursor + 2u));
        uint32_t val_bytes = bytesForType(tag);
        cursor += 3u + val_bytes;
        if (stream->available() < cursor) {
            return -1;
        }
    }

    if (stream->available() < cursor + 2u) {
        return -1;
    }
    uint16_t static_count = stream->peekShort(cursor);
    cursor += 2u;

    for (uint16_t i = 0; i < static_count; ++i) {
        if (stream->available() < cursor + BYTE_SIZE + 1u) {
            return -1;
        }
        auto tag = static_cast<HprofTypeTag>(stream->peekByte(cursor + BYTE_SIZE));
        uint32_t val_bytes = bytesForType(tag);
        cursor += BYTE_SIZE + 1u + val_bytes;
        if (stream->available() < cursor) {
            return -1;
        }
    }

    if (stream->available() < cursor + 2u) {
        return -1;
    }
    uint16_t field_count = stream->peekShort(cursor);
    uint32_t fields_start = cursor + 2u;
    uint32_t total_end = fields_start + static_cast<uint32_t>(field_count) * (BYTE_SIZE + 1u);
    if (stream->available() < total_end) {
        return -1;
    }

    auto* class_dump = new ClassDump();
    class_dump->id = class_id;
    class_dump->super_id = super_id;
    class_dump->size = field_count;
    class_dump->fields = (field_count > 0) ? new Field[field_count] : nullptr;

    for (uint16_t i = 0; i < field_count; ++i) {
        uint32_t f_off = fields_start + static_cast<uint32_t>(i) * (BYTE_SIZE + 1u);
        auto tag = static_cast<HprofTypeTag>(stream->peekByte(f_off + BYTE_SIZE));
        class_dump->fields[i].type = tag;
        class_dump->fields[i].size = static_cast<uint16_t>(bytesForType(tag));
    }

    if (CLASS_CACHE_DUMP != nullptr) {
        auto old_it = CLASS_CACHE_DUMP->find(class_id);
        if (old_it != CLASS_CACHE_DUMP->end()) {
            delete old_it->second;
        }
        (*CLASS_CACHE_DUMP)[class_id] = class_dump;
    } else {
        delete class_dump;
    }

    // Flush the entire ClassDump sub-record from `offset` to `total_end`
    stream->copy(offset, total_end - offset);
    stream->seek(total_end);
    return 1;
}

int tailor_INSTANCE_DUMP(Stream* stream, uint32_t offset) {
    /**
     * Exact AArch64 disassembly of `_Z20tailor_INSTANCE_DUMPP6Streamj` (`0x00c260..0x00c410`):
     * Parses `HPROF_GC_INSTANCE_DUMP (0x21)` starting at `offset`:
     * - `offset + 0`: subtag `0x21` (1B)
     * - `offset + 1`: `object_id` (4B)
     * - `offset + 5`: `stack_trace_serial` (4B)
     * - `offset + 9`: `class_object_id` (4B)
     * - `offset + 13`: `values_byte_count` (4B)
     * - `offset + 17`: `values[values_byte_count]`
     *
     * Buffers an `InstanceDump` (32 bytes) into `INSTANCE_CACHE_DUMP` so that once all
     * `ClassDump` hierarchy entries in the segment have been seen, `tailor_INSTANCE_DUMP_WRITE`
     * can walk the class hierarchy and strip non-object primitive fields.
     */
    uint32_t header_size = 1u + BYTE_SIZE + 4u + BYTE_SIZE + 4u; // 17 bytes when BYTE_SIZE == 4
    if (stream->available() < offset + header_size) {
        return -1;
    }

    uint32_t obj_id = stream->peekInt(offset + 1u);
    uint32_t stack_serial = stream->peekInt(offset + 1u + BYTE_SIZE);
    uint32_t class_id = stream->peekInt(offset + 1u + BYTE_SIZE + 4u);
    uint32_t byte_count = stream->peekInt(offset + 1u + 2u * BYTE_SIZE + 4u);
    uint32_t total_end = offset + header_size + byte_count;

    if (stream->available() < total_end) {
        return -1;
    }

    if (INSTANCE_CACHE_DUMP != nullptr) {
        auto* inst = new InstanceDump();
        inst->id = obj_id;
        inst->stack_trace_serial_number = stack_serial;
        inst->class_id = class_id;
        inst->count = byte_count;
        if (byte_count > 0u) {
            inst->bytes = new char[byte_count];
            std::memcpy(inst->bytes, stream->buffer() + offset + header_size, byte_count);
        } else {
            inst->bytes = nullptr;
        }
        INSTANCE_CACHE_DUMP->push_back(inst);
    }

    stream->seek(total_end);
    return 1;
}

void tailor_INSTANCE_DUMP_WRITE(Stream* stream) {
    /**
     * Exact AArch64 disassembly of `_Z26tailor_INSTANCE_DUMP_WRITEP6Stream` (`0x00b888..0x00bd34`):
     * Walks all buffered `InstanceDump*` in `INSTANCE_CACHE_DUMP`.
     * For each `InstanceDump`:
     * 1. Checks if `inst->class_id` is in `KEEP_CLASS_IDS`. If so, writes the full unshrunk
     *    instance dump record (`0x21`, `id`, `stack_serial`, `class_id`, `count`, `bytes`).
     * 2. Otherwise, walks the class hierarchy (`cid = class_dump->super_id` until `cid == 0`)
     *    in `CLASS_CACHE_DUMP`, filtering fields with `shrinkField(field.type)` and writing
     *    only kept field values into the output `Writer`.
     * 3. Frees each `InstanceDump*` and clears `INSTANCE_CACHE_DUMP`.
     */
    if (INSTANCE_CACHE_DUMP == nullptr || INSTANCE_CACHE_DUMP->empty()) {
        return;
    }

    Writer* writer = stream->writer();
    if (writer == nullptr) {
        for (InstanceDump* inst : *INSTANCE_CACHE_DUMP) {
            delete inst;
        }
        INSTANCE_CACHE_DUMP->clear();
        return;
    }

    // Write a synthetic HEAP_DUMP_SEGMENT (0x1C) wrapping the filtered instance dumps
    for (InstanceDump* inst : *INSTANCE_CACHE_DUMP) {
        if (inst == nullptr) {
            continue;
        }

        bool keep_all = (KEEP_CLASS_IDS != nullptr &&
                         KEEP_CLASS_IDS->find(inst->class_id) != KEEP_CLASS_IDS->end());

        if (keep_all || CLASS_CACHE_DUMP == nullptr ||
            CLASS_CACHE_DUMP->find(inst->class_id) == CLASS_CACHE_DUMP->end()) {
            // Write unshrunk instance record
            writer->fillByte(static_cast<char>(HPROF_GC_INSTANCE_DUMP));
            writer->fillInt(inst->id);
            writer->fillInt(inst->stack_trace_serial_number);
            writer->fillInt(inst->class_id);
            writer->fillInt(inst->count);
            if (inst->count > 0u && inst->bytes != nullptr) {
                writer->fill(inst->bytes, inst->count);
            }
        } else {
            // Walk class hierarchy and retain only fields where `shrinkField(type)` is true
            uint32_t kept_bytes = 0u;
            uint32_t cursor = 0u;
            uint32_t cid = inst->class_id;
            while (cid != 0u) {
                auto it = CLASS_CACHE_DUMP->find(cid);
                if (it == CLASS_CACHE_DUMP->end() || it->second == nullptr) {
                    break;
                }
                ClassDump* cd = it->second;
                for (uint16_t i = 0; i < cd->size; ++i) {
                    uint16_t f_size = cd->fields[i].size;
                    if (cursor + f_size <= inst->count && shrinkField(cd->fields[i].type)) {
                        kept_bytes += f_size;
                    }
                    cursor += f_size;
                }
                cid = cd->super_id;
            }

            writer->fillByte(static_cast<char>(HPROF_GC_INSTANCE_DUMP));
            writer->fillInt(inst->id);
            writer->fillInt(inst->stack_trace_serial_number);
            writer->fillInt(inst->class_id);
            writer->fillInt(kept_bytes);

            cursor = 0u;
            cid = inst->class_id;
            while (cid != 0u) {
                auto it = CLASS_CACHE_DUMP->find(cid);
                if (it == CLASS_CACHE_DUMP->end() || it->second == nullptr) {
                    break;
                }
                ClassDump* cd = it->second;
                for (uint16_t i = 0; i < cd->size; ++i) {
                    uint16_t f_size = cd->fields[i].size;
                    if (cursor + f_size <= inst->count && shrinkField(cd->fields[i].type)) {
                        writer->fill(inst->bytes + cursor, f_size);
                    }
                    cursor += f_size;
                }
                cid = cd->super_id;
            }
        }

        delete inst;
    }

    INSTANCE_CACHE_DUMP->clear();
}

int tailor_OBJECT_ARRAY_DUMP(Stream* stream, uint32_t offset) {
    /**
     * Exact AArch64 disassembly of `_Z24tailor_OBJECT_ARRAY_DUMPP6Streamj` (`0x00c414..0x00c46c`):
     * Parses `HPROF_GC_OBJ_ARRAY_DUMP (0x22)` starting at `offset`:
     * - `offset + 0`: subtag `0x22` (1B)
     * - `offset + 1`: `array_object_id` (4B)
     * - `offset + 5`: `stack_trace_serial` (4B)
     * - `offset + 9`: `num_elements` (4B)
     * - `offset + 13`: `array_class_object_id` (4B)
     * - `offset + 17`: `elements[num_elements * BYTE_SIZE]`
     * Copies the entire object reference array intact to preserve the GC reference graph.
     */
    uint32_t header_size = 1u + BYTE_SIZE + 4u + 4u + BYTE_SIZE; // 17 bytes
    if (stream->available() < offset + header_size) {
        return -1;
    }

    uint32_t num_elements = stream->peekInt(offset + 1u + BYTE_SIZE + 4u);
    uint32_t payload_bytes = num_elements * BYTE_SIZE;
    uint32_t total_end = offset + header_size + payload_bytes;

    if (stream->available() < total_end) {
        return -1;
    }

    stream->copy(offset, total_end - offset);
    stream->seek(total_end);
    return 1;
}

int tailor_PRIMITIVE_ARRAY_DUMP(Stream* stream, uint32_t offset) {
    /**
     * Exact AArch64 disassembly of `_Z27tailor_PRIMITIVE_ARRAY_DUMPP6Streamj` (`0x00c470..0x00c548`):
     * Parses `HPROF_GC_PRIM_ARRAY_DUMP (0x23)` starting at `offset`:
     * - `offset + 0`: subtag `0x23` (1B)
     * - `offset + 1`: `array_object_id` (4B)
     * - `offset + 5`: `stack_trace_serial` (4B)
     * - `offset + 9`: `num_elements` (4B)
     * - `offset + 13`: `element_type` (1B, `HprofTypeTag`)
     * - `offset + 14`: `elements[num_elements * bytesForType(element_type)]`
     *
     * Key Tailor optimization (`0x00c4c0..0x00c534`):
     * 1. Copies the first `offset + 9` bytes (`subtag + array_object_id + stack_trace_serial`).
     * 2. Writes 4 zero bytes (`stream->fillZero(offset + 9, 4)`) to set `num_elements = 0` in output,
     *    or retains `num_elements` metadata while stripping the raw `byte[]`/`char[]`/`int[]` payload!
     * 3. Copies the `element_type` byte (`1B`) at `offset + 13`.
     * 4. Calls `stream->skip(offset + 14, num_elements * elem_size)` to discard the raw array payload!
     */
    uint32_t header_size = 1u + BYTE_SIZE + 4u + 4u + 1u; // 14 bytes when BYTE_SIZE == 4
    if (stream->available() < offset + header_size) {
        return -1;
    }

    uint32_t num_elements = stream->peekInt(offset + 1u + BYTE_SIZE + 4u);
    auto elem_type = static_cast<HprofTypeTag>(stream->peekByte(offset + 1u + BYTE_SIZE + 8u));
    uint32_t elem_width = bytesForType(elem_type);
    uint32_t payload_bytes = num_elements * elem_width;

    // Copy 14-byte header (`subtag + obj_id + stack_serial + num_elements + elem_type`)
    stream->copy(offset, header_size);
    stream->seek(offset + header_size);

    // Skip the entire primitive array payload (even if it spans multiple `Stream::handle` chunks!)
    stream->skip(offset + header_size, payload_bytes);
    return 1;
}

int tailor_HEAP_DUMP_SEGMENT(Stream* stream) {
    /**
     * Exact AArch64 disassembly of `_Z24tailor_HEAP_DUMP_SEGMENTP6Stream` (`0x00b690..0x00b884`):
     * Iterates over heap dump sub-records inside `HPROF_TAG_HEAP_DUMP (0x0C)` or
     * `HPROF_TAG_HEAP_DUMP_SEGMENT (0x1C)`.
     * Sub-record tags handled:
     * - `0x01` (`HPROF_GC_ROOT_UNKNOWN`): `1 + BYTE_SIZE` (5B)
     * - `0x02` (`HPROF_GC_ROOT_JNI_GLOBAL`): `1 + 2 * BYTE_SIZE` (9B)
     * - `0x03` (`HPROF_GC_ROOT_JNI_LOCAL`): `1 + BYTE_SIZE + 8` (13B)
     * - `0x04` (`HPROF_GC_ROOT_JAVA_FRAME`): `1 + BYTE_SIZE + 8` (13B)
     * - `0x05` (`HPROF_GC_ROOT_NATIVE_STACK`): `1 + BYTE_SIZE + 4` (9B)
     * - `0x06` (`HPROF_GC_ROOT_STICKY_CLASS`): `1 + BYTE_SIZE` (5B)
     * - `0x07` (`HPROF_GC_ROOT_THREAD_BLOCK`): `1 + BYTE_SIZE + 4` (9B)
     * - `0x08` (`HPROF_GC_ROOT_MONITOR_USED`): `1 + BYTE_SIZE` (5B)
     * - `0x09` (`HPROF_GC_ROOT_THREAD_OBJECT`): `1 + BYTE_SIZE + 8` (13B)
     * - `0x20` (`HPROF_GC_CLASS_DUMP`): `tailor_CLASS_DUMP(stream, offset)`
     * - `0x21` (`HPROF_GC_INSTANCE_DUMP`): `tailor_INSTANCE_DUMP(stream, offset)`
     * - `0x22` (`HPROF_GC_OBJ_ARRAY_DUMP`): `tailor_OBJECT_ARRAY_DUMP(stream, offset)`
     * - `0x23` (`HPROF_GC_PRIM_ARRAY_DUMP`): `tailor_PRIMITIVE_ARRAY_DUMP(stream, offset)`
     * - `0x89..0x8E`, `0xFF`: Android ART root tags (`1 + BYTE_SIZE` = 5B)
     * - `0xFE` (`HPROF_HEAP_DUMP_INFO`): `1 + 4 + BYTE_SIZE` (9B)
     */
    while (stream->available() > 0u) {
        if (stream->marker() == 0u) {
            // Beginning of top-level 0x0C / 0x1C record (9-byte record header)
            if (stream->available() < 9u) {
                return 0;
            }
            uint32_t seg_length = stream->peekInt(5u);
            stream->setMarker(seg_length);
            stream->flush(9u);
            if (stream->available() == 0u) {
                return 1;
            }
        }

        uint8_t subtag = stream->peekByte(0u);
        uint32_t fixed_len = 0u;

        switch (subtag) {
            case HPROF_GC_ROOT_UNKNOWN:
            case HPROF_GC_ROOT_STICKY_CLASS:
            case HPROF_GC_ROOT_MONITOR_USED:
            case HPROF_ROOT_INTERNED_STRING:
            case HPROF_ROOT_FINALIZING:
            case HPROF_ROOT_DEBUGGER:
            case HPROF_ROOT_REFERENCE_CLEANUP:
            case HPROF_ROOT_VM_INTERNAL:
            case HPROF_ROOT_UNREACHABLE:
                fixed_len = 1u + BYTE_SIZE;
                break;

            case HPROF_GC_ROOT_JNI_GLOBAL:
                fixed_len = 1u + 2u * BYTE_SIZE;
                break;

            case HPROF_GC_ROOT_JNI_LOCAL:
            case HPROF_GC_ROOT_JAVA_FRAME:
            case HPROF_GC_ROOT_THREAD_OBJECT:
            case HPROF_ROOT_JNI_MONITOR:
                fixed_len = 1u + BYTE_SIZE + 8u;
                break;

            case HPROF_GC_ROOT_NATIVE_STACK:
            case HPROF_GC_ROOT_THREAD_BLOCK:
            case HPROF_HEAP_DUMP_INFO:
                fixed_len = 1u + BYTE_SIZE + 4u;
                break;

            case HPROF_GC_CLASS_DUMP: {
                int rc = tailor_CLASS_DUMP(stream, 0u);
                if (rc < 0) return 0;
                stream->reset();
                continue;
            }
            case HPROF_GC_INSTANCE_DUMP: {
                int rc = tailor_INSTANCE_DUMP(stream, 0u);
                if (rc < 0) return 0;
                stream->reset();
                continue;
            }
            case HPROF_GC_OBJ_ARRAY_DUMP: {
                int rc = tailor_OBJECT_ARRAY_DUMP(stream, 0u);
                if (rc < 0) return 0;
                stream->reset();
                continue;
            }
            case HPROF_GC_PRIM_ARRAY_DUMP: {
                int rc = tailor_PRIMITIVE_ARRAY_DUMP(stream, 0u);
                if (rc < 0) return 0;
                stream->reset();
                continue;
            }
            default:
                // Unknown subtag: flush remaining bytes safely
                stream->flush(stream->available());
                stream->setMarker(0u);
                return 1;
        }

        if (stream->available() < fixed_len) {
            return 0;
        }
        stream->flush(fixed_len);
    }

    return 1;
}

int tailor_HEAP_DUMP_END(Stream* stream) {
    /**
     * Exact AArch64 disassembly of `_Z20tailor_HEAP_DUMP_ENDP6Stream` (`0x00bd38..0x00bd68`):
     * Consumes the 9-byte `HPROF_TAG_HEAP_DUMP_END (0x2C)` record from `stream`
     * (`stream->seek(9); stream->reset();`) so that `tailor_XHOOK` can first emit all
     * buffered `InstanceDump` records via `tailor_INSTANCE_DUMP_WRITE` before writing `0x2C`.
     */
    if (stream->available() < 9u) {
        return 0;
    }
    stream->seek(9u);
    stream->reset();
    return 1;
}

// ============================================================================
// TailorImpl Implementation (`0x00b068..0x00b444`, `0x00dc88..0x00dda4`)
// Triển khai lớp `TailorImpl` (`0x00b068..0x00b444`, `0x00dc88..0x00dda4`)
// ============================================================================

TailorImpl::TailorImpl(const char* target_path, bool gzip) {
    /**
     * Exact AArch64 disassembly of `_ZN6TailorC2EPKcb` (`0x00dc88..0x00dd04`):
     * 1. Sets vtable pointer to `_ZTV6Tailor + 16`.
     * 2. Calls `Tailor::init()` (`0x00b068`).
     * 3. Opens `target_path` via `fopen(target_path, "wb")` (`0x004db7`).
     * 4. If `gzip` is true, constructs `FileWriter(target, true)`; else `LibzWriter(target)`.
     *    Wait — let's check `0x00dcb4..0x00dcf8` in `scratch/tailor_full_dump.txt`!
     *    At `0x00dcb4`:
     *    - `fopen(path, "wb")`
     *    - If `w20 != 0` (`gzip == true`): allocates `0x40088` (`262,280`) bytes and calls
     *      `Writer::Writer(FILE*)` (`_ZN6WriterC2EP7__sFILE` / `LibzWriter` with `deflateInit2_`).
     *    - If `w20 == 0` (`gzip == false`): allocates `0x40018` (`262,168`) bytes and calls
     *      `FileWriter::FileWriter(FILE*, bool)` (`_ZN10FileWriterC2EP7__sFILEb`).
     * 5. Allocates `Stream(writer)` (`0x20 = 32` bytes).
     */
    writer_ = nullptr;
    stream_ = nullptr;
    init();

    std::FILE* fp = (target_path != nullptr) ? std::fopen(target_path, "wb") : nullptr;
    if (gzip) {
        writer_ = new LibzWriter(fp);
    } else {
        writer_ = new FileWriter(fp, true);
    }
    stream_ = new Stream(writer_);
}

TailorImpl::~TailorImpl() {
    /**
     * Exact AArch64 disassembly of `_ZN6TailorD2Ev` (`0x00dd08..0x00dd78`):
     * 1. Deletes `stream_` (`offset 0x10`) if non-null.
     * 2. Deletes `writer_` (`offset 0x08`) if non-null.
     * 3. Calls `clearCache()` (`0x00b268`) and deletes the 6 global cache pointers.
     */
    if (stream_ != nullptr) {
        delete stream_;
        stream_ = nullptr;
    }
    if (writer_ != nullptr) {
        delete writer_;
        writer_ = nullptr;
    }
    clearCache();
    delete STRING_CACHE_ID;
    STRING_CACHE_ID = nullptr;
    delete CLASS_CACHE_NAME;
    CLASS_CACHE_NAME = nullptr;
    delete CLASS_CACHE_LOAD;
    CLASS_CACHE_LOAD = nullptr;
    delete CLASS_CACHE_DUMP;
    CLASS_CACHE_DUMP = nullptr;
    delete INSTANCE_CACHE_DUMP;
    INSTANCE_CACHE_DUMP = nullptr;
    delete KEEP_CLASS_IDS;
    KEEP_CLASS_IDS = nullptr;
}

void TailorImpl::init() {
    /**
     * Exact AArch64 disassembly of `_ZN6Tailor4initEv` (`0x00b068..0x00b150`):
     * Allocates the 6 global containers in `.bss` (`0x01c268..0x01c290`) and seeds
     * `STRING_CACHE_ID` with the 4 whitelisted class names mapped to `0`:
     *   - `"java.lang.String"`
     *   - `"android.graphics.Bitmap"`
     *   - `"java.nio.DirectByteBuffer"`
     *   - `"libcore.util.NativeAllocationRegistry$CleanerThunk"`
     */
    delete STRING_CACHE_ID;
    STRING_CACHE_ID = new std::map<std::string, uint32_t>();
    (*STRING_CACHE_ID)["java.lang.String"] = 0u;
    (*STRING_CACHE_ID)["android.graphics.Bitmap"] = 0u;
    (*STRING_CACHE_ID)["java.nio.DirectByteBuffer"] = 0u;
    (*STRING_CACHE_ID)["libcore.util.NativeAllocationRegistry$CleanerThunk"] = 0u;

    delete CLASS_CACHE_NAME;
    CLASS_CACHE_NAME = new std::map<uint32_t, std::string>();

    delete CLASS_CACHE_LOAD;
    CLASS_CACHE_LOAD = new std::map<std::string, uint32_t>();

    delete CLASS_CACHE_DUMP;
    CLASS_CACHE_DUMP = new std::map<uint32_t, ClassDump*>();

    delete INSTANCE_CACHE_DUMP;
    INSTANCE_CACHE_DUMP = new std::vector<InstanceDump*>();

    delete KEEP_CLASS_IDS;
    KEEP_CLASS_IDS = new std::set<uint32_t>();
}

int TailorImpl::handle(const char* buf, size_t count) {
    return tailor_XHOOK(buf, count);
}

int TailorImpl::tailor_XHOOK(const char* buf, size_t count) {
    /**
     * Exact AArch64 disassembly of `_ZN6Tailor12tailor_XHOOKEPKcm` (`0x00b34c..0x00b444`):
     * 1. Appends `(buf, count)` into `stream_->handle(buf, count)`.
     * 2. If the HPROF file header (`"JAVA PROFILE 1.0.2\0"` or `"JAVA PROFILE 1.0.3\0"` +
     *    4-byte `BYTE_SIZE` + 8-byte timestamp = 31 bytes) has not been parsed yet,
     *    reads `BYTE_SIZE = stream_->peekInt(19)` and flushes 31 bytes.
     * 3. Loops while `stream_->isAvailable()` (`available >= 9`):
     *    - If `stream_->marker() != 0`, continues `tailor_HEAP_DUMP_SEGMENT(stream_)`.
     *    - Otherwise peeks `tag = stream_->peekByte(0)` and `length = stream_->peekInt(5)`:
     *      - `tag == 0x01` (`HPROF_TAG_STRING`): `tailor_STRING(stream_, length)`
     *      - `tag == 0x02` (`HPROF_TAG_LOAD_CLASS`): `tailor_LOAD_CLASS(stream_, length)`
     *      - `tag == 0x0C` or `0x1C` (`HEAP_DUMP` / `HEAP_DUMP_SEGMENT`): `tailor_HEAP_DUMP_SEGMENT(stream_)`
     *      - `tag == 0x2C` (`HPROF_TAG_HEAP_DUMP_END`):
     *        Calls `tailor_HEAP_DUMP_END(stream_)`, then `initKeepClassIDSet()`,
     *        `tailor_INSTANCE_DUMP_WRITE(stream_)`, `clearCache()`, and writes
     *        `fillByte(0x2C)` (`mov w1, #0x2c` = `0x52800581` @ `0x00b414`) + `fillZero(8)`!
     */
    if (stream_ == nullptr || buf == nullptr || count == 0u) {
        return 0;
    }

    stream_->handle(buf, count);

    // Check for 31-byte HPROF header ("JAVA PROFILE 1.0.x\0" + 4-byte id_size + 8-byte timestamp)
    if (stream_->available() >= 31u &&
        std::memcmp(stream_->buffer(), "JAVA PROFILE 1.0.", 17) == 0) {
        uint32_t id_size = stream_->peekInt(19u);
        if (id_size == 4u || id_size == 8u) {
            BYTE_SIZE = static_cast<uint16_t>(id_size);
        }
        stream_->flush(31u);
    }

    while (stream_->isAvailable()) {
        if (stream_->marker() != 0u) {
            if (tailor_HEAP_DUMP_SEGMENT(stream_) == 0) {
                break;
            }
            continue;
        }

        uint8_t tag = stream_->peekByte(0u);
        uint32_t length = stream_->peekInt(5u);

        if (tag == HPROF_TAG_STRING) {
            if (tailor_STRING(stream_, length) == 0) {
                break;
            }
        } else if (tag == HPROF_TAG_LOAD_CLASS) {
            if (tailor_LOAD_CLASS(stream_, length) == 0) {
                break;
            }
        } else if (tag == HPROF_TAG_HEAP_DUMP || tag == HPROF_TAG_HEAP_DUMP_SEGMENT) {
            if (tailor_HEAP_DUMP_SEGMENT(stream_) == 0) {
                break;
            }
        } else if (tag == HPROF_TAG_HEAP_DUMP_END) {
            if (tailor_HEAP_DUMP_END(stream_) == 0) {
                break;
            }
            initKeepClassIDSet();
            tailor_INSTANCE_DUMP_WRITE(stream_);
            clearCache();
            if (writer_ != nullptr) {
                writer_->fillByte(static_cast<char>(HPROF_TAG_HEAP_DUMP_END));
                writer_->fillZero(8u);
            }
        } else {
            uint32_t total_len = 9u + length;
            if (stream_->available() < total_len) {
                break;
            }
            stream_->flush(total_len);
        }
    }

    return 0;
}

} // namespace tailor
} // namespace opencut
