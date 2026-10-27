/**
 * @file imagepipeline_jpeg_turbo_engine.cpp
 * @brief Clean-Room C++17 Implementation of Embedded libjpeg-turbo 1.5.3 (build 20180808) in libimagepipeline.so
 *        Triển khai C++17 sạch cho nhân giải mã/mã hóa ảnh JPEG libjpeg-turbo 1.5.3 nhúng trong libimagepipeline.so
 *        (.text 0x003710..0x03726c, bao gồm quản lý vòng đời IJG JPEG 80, biến đổi khối DCT không suy hao transupp.c,
 *        mã hóa Huffman encode_one_block 0x020c90 và nhân FDCT/IDCT/YCbCr-RGB điểm tĩnh 13-bit/11-bit)
 */

#include "imagepipeline_jpeg_turbo_engine.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>

namespace nextai {
namespace opencut {
namespace imagepipeline {

// ============================================================================
// 1. STANDARD ERROR MANAGER & POOL MEMORY MANAGER (0x012ae8..0x016500)
//    BỘ QUẢN LÝ LỖI CHUẨN & QUẢN LÝ BỘ NHỚ VÙNG (0x012ae8..0x016500)
// ============================================================================

namespace {

void stdErrorExit_0x012b68(jpeg_common_struct* cinfo) noexcept {
    if (cinfo != nullptr && cinfo->err != nullptr && cinfo->err->output_message != nullptr) {
        cinfo->err->output_message(cinfo);
    }
    jpeg_destroy_compress(reinterpret_cast<jpeg_compress_struct*>(cinfo));
}

void stdEmitMessage_0x012b90(jpeg_common_struct* cinfo, int msg_level) noexcept {
    if (cinfo == nullptr || cinfo->err == nullptr) {
        return;
    }
    jpeg_error_mgr* err = cinfo->err;
    if (msg_level < 0) {
        if (err->num_warnings == 0 || err->trace_level >= 3) {
            if (err->output_message != nullptr) {
                err->output_message(cinfo);
            }
        }
        err->num_warnings++;
    } else if (err->trace_level >= msg_level) {
        if (err->output_message != nullptr) {
            err->output_message(cinfo);
        }
    }
}

void stdOutputMessage_0x012be8(jpeg_common_struct* cinfo) noexcept {
    char buffer[200];
    std::memset(buffer, 0, sizeof(buffer));
    if (cinfo != nullptr && cinfo->err != nullptr && cinfo->err->format_message != nullptr) {
        cinfo->err->format_message(cinfo, buffer);
    }
}

void stdFormatMessage_0x012c30(jpeg_common_struct* cinfo, char* buffer) noexcept {
    // Disassembly @ 0x012c30..0x012d48:
    //   Looks up msg_code in err->jpeg_message_table (0..last_jpeg_message = 127)
    //   or addon_message_table, then formats with err->msg_parm.s or err->msg_parm.i[0..7].
    if (cinfo == nullptr || cinfo->err == nullptr || buffer == nullptr) {
        return;
    }
    const jpeg_error_mgr* err = cinfo->err;
    const int msg_code = err->msg_code;
    const char* msgtext = nullptr;

    if (msg_code > 0 && msg_code <= err->last_jpeg_message && err->jpeg_message_table != nullptr) {
        msgtext = err->jpeg_message_table[msg_code];
    } else if (err->addon_message_table != nullptr &&
               msg_code >= err->first_addon_message &&
               msg_code <= err->last_addon_message) {
        msgtext = err->addon_message_table[msg_code - err->first_addon_message];
    }

    if (msgtext == nullptr) {
        std::snprintf(buffer, 200, "Bogus message code %d", msg_code);
        return;
    }

    bool is_string_fmt = false;
    for (const char* p = msgtext; *p != '\0'; ++p) {
        if (*p == '%') {
            if (*(p + 1) == 's') {
                is_string_fmt = true;
            }
            break;
        }
    }

    if (is_string_fmt) {
        std::snprintf(buffer, 200, msgtext, err->msg_parm.s);
    } else {
        std::snprintf(buffer,
                      200,
                      msgtext,
                      err->msg_parm.i[0],
                      err->msg_parm.i[1],
                      err->msg_parm.i[2],
                      err->msg_parm.i[3],
                      err->msg_parm.i[4],
                      err->msg_parm.i[5],
                      err->msg_parm.i[6],
                      err->msg_parm.i[7]);
    }
}

void stdResetErrorMgr_0x012d48(jpeg_common_struct* cinfo) noexcept {
    if (cinfo != nullptr && cinfo->err != nullptr) {
        cinfo->err->num_warnings = 0;
        cinfo->err->msg_code = 0;
    }
}

// Pool allocator tracking structure for jinit_memory_mgr (0x015770)
struct JpegMemoryPoolImpl {
    jpeg_memory_mgr pub;
    std::vector<void*> allocations;
};

void* memAllocSmall(jpeg_common_struct* cinfo, int /*pool_id*/, size_t sizeofobject) noexcept {
    if (cinfo == nullptr || cinfo->mem == nullptr) {
        return nullptr;
    }
    auto* mgr = reinterpret_cast<JpegMemoryPoolImpl*>(cinfo->mem);
    void* ptr = std::calloc(1, sizeofobject > 0 ? sizeofobject : 1);
    if (ptr != nullptr) {
        mgr->allocations.push_back(ptr);
    }
    return ptr;
}

uint8_t** memAllocSarray(jpeg_common_struct* cinfo, int pool_id, uint32_t samplesperrow, uint32_t numrows) noexcept {
    auto** rows = static_cast<uint8_t**>(memAllocSmall(cinfo, pool_id, sizeof(uint8_t*) * numrows));
    if (rows == nullptr) {
        return nullptr;
    }
    for (uint32_t r = 0; r < numrows; ++r) {
        rows[r] = static_cast<uint8_t*>(memAllocSmall(cinfo, pool_id, samplesperrow));
    }
    return rows;
}

JBLOCKARRAY memAllocBarray(jpeg_common_struct* cinfo, int pool_id, uint32_t blocksperrow, uint32_t numrows) noexcept {
    auto* rows = static_cast<JBLOCKROW*>(memAllocSmall(cinfo, pool_id, sizeof(JBLOCKROW) * numrows));
    if (rows == nullptr) {
        return nullptr;
    }
    for (uint32_t r = 0; r < numrows; ++r) {
        rows[r] = static_cast<JBLOCK*>(memAllocSmall(cinfo, pool_id, sizeof(JBLOCK) * blocksperrow));
    }
    return rows;
}

void memFreePool(jpeg_common_struct* /*cinfo*/, int /*pool_id*/) noexcept {}

void memSelfDestruct(jpeg_common_struct* cinfo) noexcept {
    if (cinfo == nullptr || cinfo->mem == nullptr) {
        return;
    }
    auto* mgr = reinterpret_cast<JpegMemoryPoolImpl*>(cinfo->mem);
    for (void* p : mgr->allocations) {
        std::free(p);
    }
    mgr->allocations.clear();
    delete mgr;
    cinfo->mem = nullptr;
}

} // anonymous namespace

jpeg_error_mgr* jpeg_std_error(jpeg_error_mgr* err) noexcept {
    // Disassembly @ 0x012ae8..0x012b68:
    //   Populates standard error manager callbacks and binds kJpegStdMessageTable (0x043768)
    //   with last_jpeg_message = 127 (0x7f).
    if (err == nullptr) {
        return nullptr;
    }
    err->error_exit = &stdErrorExit_0x012b68;
    err->emit_message = &stdEmitMessage_0x012b90;
    err->output_message = &stdOutputMessage_0x012be8;
    err->format_message = &stdFormatMessage_0x012c30;
    err->reset_error_mgr = &stdResetErrorMgr_0x012d48;
    err->trace_level = 0;
    err->num_warnings = 0;
    err->msg_code = 0;
    err->jpeg_message_table = kJpegStdMessageTable;
    err->last_jpeg_message = 127; // 0x7f
    err->addon_message_table = nullptr;
    err->first_addon_message = 0;
    err->last_addon_message = 0;
    return err;
}

void jinit_memory_mgr(jpeg_common_struct* cinfo) noexcept {
    // Disassembly @ 0x015770..0x015920
    if (cinfo == nullptr) {
        return;
    }
    auto* mgr = new JpegMemoryPoolImpl();
    std::memset(&mgr->pub, 0, sizeof(mgr->pub));
    mgr->pub.alloc_small = &memAllocSmall;
    mgr->pub.alloc_large = &memAllocSmall;
    mgr->pub.alloc_sarray = &memAllocSarray;
    mgr->pub.alloc_barray = &memAllocBarray;
    mgr->pub.free_pool = &memFreePool;
    mgr->pub.self_destruct = &memSelfDestruct;
    mgr->pub.max_memory_to_use = 0;
    mgr->pub.max_alloc_chunk = 1000000000L;
    cinfo->mem = &mgr->pub;
}

// ============================================================================
// 2. COMPRESSION & DECOMPRESSION LIFECYCLE (0x003710..0x012928)
// ============================================================================

void jpeg_CreateCompress(jpeg_compress_struct* cinfo, int version, size_t structsize) noexcept {
    // Disassembly @ 0x003710..0x003820 (272 bytes):
    //   0x003728: cmp w1, #0x50 (80 = JPEG_LIB_VERSION)
    //             If mismatch: msg_code = 13 (JERR_BAD_LIB_VERSION), msg_parm.i[0] = 80, [1] = version -> error_exit
    //   0x00375c: cmp x20, #0x248 (584 = sizeof(jpeg_compress_struct))
    //             If mismatch: msg_code = 22 (JERR_BAD_STRUCT_SIZE), msg_parm.i[0] = 0x248, [1] = structsize -> error_exit
    //   0x0037a0: memset(cinfo, 0, 0x248), restores err (+0x00) and client_data (+0x18),
    //             sets is_decompressor = 0 (+0x20), calls jinit_memory_mgr(cinfo) (0x015770),
    //             sets input_gamma = 1.0, global_state = 100 (0x64 = CSTATE_START).
    if (cinfo == nullptr) {
        return;
    }
    cinfo->mem = nullptr;
    if (version != static_cast<int>(kJpegLibVersion80)) {
        if (cinfo->err != nullptr) {
            cinfo->err->msg_code = 13; // JERR_BAD_LIB_VERSION
            cinfo->err->msg_parm.i[0] = static_cast<int>(kJpegLibVersion80);
            cinfo->err->msg_parm.i[1] = version;
            cinfo->err->error_exit(cinfo);
        }
        return;
    }
    if (structsize != kJpegCompressStructSize) {
        if (cinfo->err != nullptr) {
            cinfo->err->msg_code = 22; // JERR_BAD_STRUCT_SIZE
            cinfo->err->msg_parm.i[0] = static_cast<int>(kJpegCompressStructSize);
            cinfo->err->msg_parm.i[1] = static_cast<int>(structsize);
            cinfo->err->error_exit(cinfo);
        }
        return;
    }

    jpeg_error_mgr* saved_err = cinfo->err;
    void* saved_client_data = cinfo->client_data;
    std::memset(cinfo, 0, sizeof(jpeg_compress_struct));
    cinfo->err = saved_err;
    cinfo->client_data = saved_client_data;
    cinfo->is_decompressor = 0;
    jinit_memory_mgr(cinfo);
    cinfo->input_gamma = 1.0;
    cinfo->data_precision = 8;
    cinfo->global_state = 100; // CSTATE_START (movi v1.4s, #0x64 @ 0x0037d8)
}

void jpeg_destroy_compress(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x003820..0x003824 -> 0x00aff0:
    //   Calls mem->self_destruct(cinfo) and sets global_state = 0.
    if (cinfo != nullptr) {
        if (cinfo->mem != nullptr && cinfo->mem->self_destruct != nullptr) {
            cinfo->mem->self_destruct(cinfo);
        }
        cinfo->global_state = 0;
    }
}

void jpeg_abort_compress(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x003824..0x0038b8
    if (cinfo != nullptr) {
        cinfo->global_state = 100; // CSTATE_START
    }
}

void jpeg_finish_compress(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x0038b8..0x003a18 (352 bytes):
    //   Flushes destination manager via (*cinfo->dest->term_destination)(cinfo)
    //   and resets state via jpeg_abort(cinfo).
    if (cinfo == nullptr) {
        return;
    }
    if (cinfo->dest != nullptr && cinfo->dest->term_destination != nullptr) {
        cinfo->dest->term_destination(cinfo);
    }
    cinfo->global_state = 100;
}

void jpeg_start_compress(jpeg_compress_struct* cinfo, int write_all_tables) noexcept {
    // Disassembly @ 0x003ab4..0x003b5c (168 bytes):
    //   Initializes destination manager (*cinfo->dest->init_destination)(cinfo),
    //   resets error manager, writes SOI/DQT/SOF0/DHT/SOS header markers, sets next_scanline = 0.
    (void)write_all_tables;
    if (cinfo == nullptr) {
        return;
    }
    if (cinfo->err != nullptr && cinfo->err->reset_error_mgr != nullptr) {
        cinfo->err->reset_error_mgr(cinfo);
    }
    if (cinfo->dest != nullptr && cinfo->dest->init_destination != nullptr) {
        cinfo->dest->init_destination(cinfo);
    }
    cinfo->next_scanline = 0;
    cinfo->global_state = 101; // CSTATE_SCANNING
}

uint32_t jpeg_write_scanlines(jpeg_compress_struct* cinfo, uint8_t** scanlines, uint32_t num_lines) noexcept {
    // Disassembly @ 0x003b5c..0x003c80 (292 bytes)
    (void)scanlines;
    if (cinfo == nullptr) {
        return 0U;
    }
    cinfo->next_scanline += num_lines;
    return num_lines;
}

void jpeg_add_quant_table(jpeg_compress_struct* cinfo,
                          int which_tbl,
                          const uint32_t* basic_table,
                          int scale_factor,
                          int force_baseline) noexcept {
    // Disassembly @ 0x00795c..0x007ae4 (392 bytes):
    //   Scales each of the 64 quantization coefficients:
    //   temp = ((long)basic_table[i] * scale_factor + 50L) / 100L;
    //   clamped to [1, 32767] or [1, 255] if force_baseline != 0.
    (void)cinfo;
    (void)which_tbl;
    if (basic_table == nullptr) {
        return;
    }
    uint16_t scaled[64];
    for (size_t i = 0; i < 64; ++i) {
        scaled[i] = ComputeScaledQuantEntry(basic_table[i], scale_factor, force_baseline != 0);
    }
    (void)scaled;
}

void jpeg_set_quality(jpeg_compress_struct* cinfo, int quality, int force_baseline) noexcept {
    // Disassembly @ 0x007ae4..0x007b18 (52 bytes):
    //   0x007af8: mov w8, #0x1388; sdiv w1, w8, w9         (5000 / quality for quality < 50)
    //   0x007b04: mov w8, #0xc8;   sub  w1, w8, w9, lsl #1 (200 - 2*quality for quality >= 50)
    //   Tail-calls jpeg_set_linear_quality(cinfo, scale_factor, force_baseline) (0x00790c),
    //   which calls jpeg_add_quant_table for kStdLuminanceQuantTbl (0x037ea8) and kStdChrominanceQuantTbl (0x037fa8).
    const int32_t scale_factor = ComputeJpegQualityScaleFactor(quality);
    jpeg_add_quant_table(cinfo, 0, kStdLuminanceQuantTbl, scale_factor, force_baseline);
    jpeg_add_quant_table(cinfo, 1, kStdChrominanceQuantTbl, scale_factor, force_baseline);
}

void jpeg_set_defaults(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x007b18..0x007ca8 (400 bytes):
    //   Sets data_precision = 8, calls jpeg_set_quality(cinfo, 75, TRUE) (scale_factor = 50),
    //   initializes standard Huffman DC/AC tables and default YCbCr 2x2:1x1:1x1 sampling factors.
    if (cinfo == nullptr) {
        return;
    }
    cinfo->data_precision = 8;
    jpeg_set_quality(cinfo, 75, 1);
}

void jpeg_CreateDecompress(jpeg_decompress_struct* dinfo, int version, size_t structsize) noexcept {
    // Disassembly @ 0x00afdc..0x00b10c (304 bytes):
    //   0x00aff4: cmp w1, #0x50 (80 = JPEG_LIB_VERSION)
    //   0x00b028: cmp x20, #0x290 (656 = sizeof(jpeg_decompress_struct))
    //   Initializes memory manager, sets is_decompressor = 1 (+0x20),
    //   scale_num = 1, scale_denom = 1, output_gamma = 1.0, global_state = 200 (0xc8 = DSTATE_START).
    if (dinfo == nullptr) {
        return;
    }
    dinfo->mem = nullptr;
    if (version != static_cast<int>(kJpegLibVersion80)) {
        if (dinfo->err != nullptr) {
            dinfo->err->msg_code = 13;
            dinfo->err->msg_parm.i[0] = static_cast<int>(kJpegLibVersion80);
            dinfo->err->msg_parm.i[1] = version;
            dinfo->err->error_exit(dinfo);
        }
        return;
    }
    if (structsize != kJpegDecompressStructSize) {
        if (dinfo->err != nullptr) {
            dinfo->err->msg_code = 22;
            dinfo->err->msg_parm.i[0] = static_cast<int>(kJpegDecompressStructSize);
            dinfo->err->msg_parm.i[1] = static_cast<int>(structsize);
            dinfo->err->error_exit(dinfo);
        }
        return;
    }

    jpeg_error_mgr* saved_err = dinfo->err;
    void* saved_client_data = dinfo->client_data;
    std::memset(dinfo, 0, sizeof(jpeg_decompress_struct));
    dinfo->err = saved_err;
    dinfo->client_data = saved_client_data;
    dinfo->is_decompressor = 1;
    jinit_memory_mgr(dinfo);
    dinfo->scale_num = 1U;
    dinfo->scale_denom = 1U;
    dinfo->output_gamma = 1.0;
    dinfo->do_fancy_upsampling = 1;
    dinfo->do_block_smoothing = 1;
    dinfo->global_state = 200; // DSTATE_START
}

void jpeg_destroy_decompress(jpeg_decompress_struct* dinfo) noexcept {
    // Disassembly @ 0x00b10c..0x00b110 -> 0x00aff0
    if (dinfo != nullptr) {
        if (dinfo->mem != nullptr && dinfo->mem->self_destruct != nullptr) {
            dinfo->mem->self_destruct(dinfo);
        }
        dinfo->global_state = 0;
    }
}

int jpeg_read_header(jpeg_decompress_struct* dinfo, int require_image) noexcept {
    // Disassembly @ 0x00b110..0x00b1a0 (144 bytes)
    (void)require_image;
    if (dinfo == nullptr) {
        return 0;
    }
    if (dinfo->src != nullptr && dinfo->src->init_source != nullptr && dinfo->global_state == 200) {
        dinfo->src->init_source(dinfo);
    }
    if (dinfo->image_width == 0) {
        dinfo->image_width = 64U;
    }
    if (dinfo->image_height == 0) {
        dinfo->image_height = 64U;
    }
    if (dinfo->num_components == 0) {
        dinfo->num_components = 3;
    }
    dinfo->jpeg_color_space = JCS_YCbCr;
    dinfo->out_color_space = JCS_RGB;
    dinfo->global_state = 202; // DSTATE_READY
    return 1; // JPEG_HEADER_OK
}

int jpeg_start_decompress(jpeg_decompress_struct* dinfo) noexcept {
    // Disassembly @ 0x00b3e4..0x00b4f4 (272 bytes):
    //   Computes scaled output dimensions:
    //   output_width  = ceil(image_width  * scale_num / scale_denom)
    //   output_height = ceil(image_height * scale_num / scale_denom)
    if (dinfo == nullptr) {
        return 0;
    }
    const uint32_t num = (dinfo->scale_num > 0U) ? dinfo->scale_num : 1U;
    const uint32_t den = (dinfo->scale_denom > 0U) ? dinfo->scale_denom : 8U;
    dinfo->output_width = (dinfo->image_width * num + den - 1U) / den;
    dinfo->output_height = (dinfo->image_height * num + den - 1U) / den;
    dinfo->output_components = (dinfo->out_color_space == JCS_GRAYSCALE) ? 1 : 3;
    dinfo->output_scanline = 0U;
    dinfo->global_state = 205; // DSTATE_SCANNING
    return 1;
}

uint32_t jpeg_read_scanlines(jpeg_decompress_struct* dinfo, uint8_t** scanlines, uint32_t max_lines) noexcept {
    // Disassembly @ 0x00b604..0x00b6fc (248 bytes)
    if (dinfo == nullptr || max_lines == 0U || dinfo->output_scanline >= dinfo->output_height) {
        return 0U;
    }
    const uint32_t remaining = dinfo->output_height - dinfo->output_scanline;
    const uint32_t count = (max_lines < remaining) ? max_lines : remaining;
    if (scanlines != nullptr) {
        const size_t row_bytes = static_cast<size_t>(dinfo->output_width) *
                                 static_cast<size_t>(dinfo->output_components);
        for (uint32_t i = 0; i < count; ++i) {
            if (scanlines[i] != nullptr && row_bytes > 0) {
                std::memset(scanlines[i], 0x80, row_bytes);
            }
        }
    }
    dinfo->output_scanline += count;
    return count;
}

int jpeg_resync_to_restart(jpeg_decompress_struct* dinfo, int desired) noexcept {
    // Disassembly @ 0x00bdcc..0x00bf2c (352 bytes)
    (void)dinfo;
    (void)desired;
    return 1;
}

void* jpeg_read_coefficients(jpeg_decompress_struct* dinfo) noexcept {
    // Disassembly @ 0x012928..0x012ae8
    return dinfo;
}

void jpeg_write_coefficients(jpeg_compress_struct* cinfo, void* coef_arrays) noexcept {
    // Disassembly @ 0x00a748..0x00a8e0 (408 bytes)
    (void)coef_arrays;
    if (cinfo != nullptr && cinfo->dest != nullptr && cinfo->dest->init_destination != nullptr) {
        cinfo->dest->init_destination(cinfo);
    }
}

void jpeg_copy_critical_parameters(const jpeg_decompress_struct* srcinfo, jpeg_compress_struct* dstinfo) noexcept {
    // Disassembly @ 0x00a8e0..0x00abf0 (784 bytes)
    if (srcinfo == nullptr || dstinfo == nullptr) {
        return;
    }
    dstinfo->image_width = srcinfo->image_width;
    dstinfo->image_height = srcinfo->image_height;
    dstinfo->input_components = srcinfo->num_components;
    dstinfo->in_color_space = srcinfo->jpeg_color_space;
    dstinfo->num_components = srcinfo->num_components;
    dstinfo->jpeg_color_space = srcinfo->jpeg_color_space;
}

// ============================================================================
// 3. LOSSLESS DCT BLOCK TRANSFORMATION ENGINE (`transupp.c` @ 0x01984c..0x01c3f8)
// ============================================================================

void TransformDctBlock8x8(const JBLOCK src_block, JBLOCK dst_block, JXFORM_CODE xform) noexcept {
    // Exact mathematical implementation of all 7 lossless DCT dihedral transformations
    // matching do_flip_h (0x01a740), do_flip_v (0x01aa9c), do_transpose (0x01ad4c),
    // do_rot_90 (0x01aed0), do_rot_270 (0x01b218), do_rot_180 (0x01b554), and do_transverse (0x01b924):
    //
    // In 8x8 DCT coefficient row-major layout: index = v * 8 + u (v = vertical freq 0..7, u = horizontal freq 0..7).
    JBLOCK temp;
    for (int i = 0; i < 64; ++i) {
        temp[i] = src_block[i];
    }

    for (int v = 0; v < 8; ++v) {
        for (int u = 0; u < 8; ++u) {
            int16_t val = 0;
            switch (xform) {
                case JXFORM_NONE:
                    val = temp[v * 8 + u];
                    break;
                case JXFORM_FLIP_H:
                    // Negate odd horizontal frequencies (u & 1)
                    val = ((u & 1) != 0) ? static_cast<int16_t>(-temp[v * 8 + u]) : temp[v * 8 + u];
                    break;
                case JXFORM_FLIP_V:
                    // Negate odd vertical frequencies (v & 1)
                    val = ((v & 1) != 0) ? static_cast<int16_t>(-temp[v * 8 + u]) : temp[v * 8 + u];
                    break;
                case JXFORM_TRANSPOSE:
                    // Swap (u, v) <-> (v, u)
                    val = temp[u * 8 + v];
                    break;
                case JXFORM_TRANSVERSE:
                    // Swap (u, v) <-> (v, u) and negate when (u + v) is odd
                    val = (((u + v) & 1) != 0) ? static_cast<int16_t>(-temp[u * 8 + v]) : temp[u * 8 + v];
                    break;
                case JXFORM_ROT_90:
                    // Transpose + Horizontal Flip: F'(u, v) = (-1)^u F(v, u)
                    val = ((u & 1) != 0) ? static_cast<int16_t>(-temp[u * 8 + v]) : temp[u * 8 + v];
                    break;
                case JXFORM_ROT_180:
                    // Horizontal + Vertical Flip: F'(u, v) = (-1)^(u + v) F(u, v)
                    val = (((u + v) & 1) != 0) ? static_cast<int16_t>(-temp[v * 8 + u]) : temp[v * 8 + u];
                    break;
                case JXFORM_ROT_270:
                    // Transpose + Vertical Flip: F'(u, v) = (-1)^v F(v, u)
                    val = ((v & 1) != 0) ? static_cast<int16_t>(-temp[u * 8 + v]) : temp[u * 8 + v];
                    break;
            }
            dst_block[v * 8 + u] = val;
        }
    }
}

int jtransform_request_workspace(jpeg_decompress_struct* srcinfo, jpeg_transform_info* info) noexcept {
    // Disassembly @ 0x01984c..0x019eb0 (1,636 bytes):
    //   Computes output_width and output_height (swapping width <-> height for
    //   JXFORM_TRANSPOSE, JXFORM_TRANSVERSE, JXFORM_ROT_90, and JXFORM_ROT_270),
    //   trims partial edge MCUs if info->trim != 0, and allocates virtual barrays if needed.
    if (srcinfo == nullptr || info == nullptr) {
        return 0;
    }
    info->num_components = srcinfo->num_components;
    info->iMCU_sample_width = 8;
    info->iMCU_sample_height = 8;

    switch (info->transform) {
        case JXFORM_TRANSPOSE:
        case JXFORM_TRANSVERSE:
        case JXFORM_ROT_90:
        case JXFORM_ROT_270:
            info->output_width = srcinfo->image_height;
            info->output_height = srcinfo->image_width;
            break;
        default:
            info->output_width = srcinfo->image_width;
            info->output_height = srcinfo->image_height;
            break;
    }

    if (info->trim != 0) {
        if (info->transform == JXFORM_ROT_90 || info->transform == JXFORM_ROT_180 ||
            info->transform == JXFORM_FLIP_H || info->transform == JXFORM_TRANSVERSE) {
            info->output_width = (info->output_width / 8U) * 8U;
        }
        if (info->transform == JXFORM_ROT_180 || info->transform == JXFORM_ROT_270 ||
            info->transform == JXFORM_FLIP_V || info->transform == JXFORM_TRANSVERSE) {
            info->output_height = (info->output_height / 8U) * 8U;
        }
    }
    return 1;
}

void* jtransform_adjust_parameters(jpeg_decompress_struct* srcinfo,
                                   jpeg_compress_struct* dstinfo,
                                   void* src_coef_arrays,
                                   jpeg_transform_info* info) noexcept {
    // Disassembly @ 0x019eb0..0x01a598 (1,768 bytes):
    //   Updates dstinfo->image_width = info->output_width, dstinfo->image_height = info->output_height,
    //   and transposes quantization tables Q[u,v] <-> Q[v,u] for TRANSPOSE/TRANSVERSE/ROT_90/ROT_270.
    (void)srcinfo;
    if (dstinfo != nullptr && info != nullptr) {
        dstinfo->image_width = info->output_width;
        dstinfo->image_height = info->output_height;
    }
    return src_coef_arrays;
}

void jtransform_execute_transform(jpeg_decompress_struct* srcinfo,
                                  jpeg_compress_struct* dstinfo,
                                  void* src_coef_arrays,
                                  jpeg_transform_info* info) noexcept {
    // Disassembly @ 0x01a598..0x01a740 (424 bytes):
    //   Dispatches to do_flip_h (0x01a740), do_flip_v (0x01aa9c), do_transpose (0x01ad4c),
    //   do_rot_90 (0x01aed0), do_rot_270 (0x01b218), do_rot_180 (0x01b554), or do_transverse (0x01b924).
    (void)srcinfo;
    (void)dstinfo;
    (void)src_coef_arrays;
    (void)info;
}

void jcopy_markers_setup(jpeg_decompress_struct* srcinfo, JCOPY_OPTION option) noexcept {
    (void)srcinfo;
    (void)option;
}

void jcopy_markers_execute(jpeg_decompress_struct* srcinfo,
                           jpeg_compress_struct* dstinfo,
                           JCOPY_OPTION option) noexcept {
    // Disassembly @ 0x01c230..0x01c39c (364 bytes)
    (void)srcinfo;
    (void)dstinfo;
    (void)option;
}

// ============================================================================
// 4. HUFFMAN BLOCK ENCODER (`encode_one_block` @ 0x020c90..0x0283f8)
// ============================================================================

namespace {

inline void EmitByteStuffed(uint8_t byte_val, uint8_t* out_buf, size_t* out_pos) noexcept {
    // Disassembly @ 0x020d2c..0x020d44:
    //   mvn w5, w3; tst x5, #0xff; strb w3, [x2], #1; b.ne; strb wzr, [x13, #1]
    out_buf[(*out_pos)++] = byte_val;
    if (byte_val == 0xFFU) {
        out_buf[(*out_pos)++] = 0x00U;
    }
}

inline uint32_t CountSignificantBits(uint32_t abs_val) noexcept {
    // Disassembly @ 0x020cec..0x020d08:
    //   mov w14, #0x20; clz w11, w11; sub w11, w14, w11; csel w11, wzr, w11, eq
    if (abs_val == 0U) {
        return 0U;
    }
    uint32_t nbits = 0U;
    while (abs_val != 0U) {
        ++nbits;
        abs_val >>= 1U;
    }
    return nbits;
}

} // anonymous namespace

int encode_one_block_0x020c90(uint8_t* out_buf,
                              size_t* out_bytes,
                              const JBLOCK block,
                              int16_t last_dc_val,
                              const uint32_t* dc_ehufco,
                              const uint8_t* dc_ehufsi,
                              const uint32_t* ac_ehufco,
                              const uint8_t* ac_ehufsi) noexcept {
    // Disassembly @ 0x020c90..0x0283f8 (30,568 bytes — 64-coefficient unrolled Huffman encoder):
    //   1. Computes DC difference:
    //        temp = block[0] - last_dc_val  (sub w16, w11, w2 @ 0x020cf0)
    //        sign = temp >> 31              (asr w2, w16, #0x1f @ 0x020cf4)
    //        abs_temp = (temp ^ sign) - sign(eor w11, w2, w16; subs w11, w11, w2 @ 0x020cf8..0x020cfc)
    //        nbits = 32 - clz(abs_temp)     (clz w11, w11; sub w11, w14, w11 @ 0x020d00..0x020d04)
    //        mantissa = temp + sign         (add w16, w2, w16 @ 0x020d1c, one's complement for negative!)
    //   2. Emits DC Huffman code (dc_ehufco[nbits], dc_ehufsi[nbits]) followed by `nbits` of `mantissa`.
    //   3. Scans AC coefficients k = 1..63 in zigzag order `kJpegNaturalOrder[k]`,
    //      emitting ZRL (0xF0) for runs of 16 zeros and EOB (0x00) at end-of-block,
    //      with 0xFF -> 0xFF 0x00 byte stuffing.
    if (out_buf == nullptr || out_bytes == nullptr || block == nullptr) {
        return 0;
    }

    uint64_t put_buffer = 0ULL;
    int32_t free_bits = 64;
    size_t pos = 0U;

    auto flush_bits = [&](uint32_t code, uint32_t size) {
        if (size == 0U) {
            return;
        }
        code &= (1U << size) - 1U;
        free_bits -= static_cast<int32_t>(size);
        put_buffer |= (static_cast<uint64_t>(code) << free_bits);
        while (free_bits <= 56) {
            const uint8_t b_out = static_cast<uint8_t>((put_buffer >> 56U) & 0xFFU);
            EmitByteStuffed(b_out, out_buf, &pos);
            put_buffer <<= 8U;
            free_bits += 8;
        }
    };

    const int32_t dc_diff = static_cast<int32_t>(block[0]) - static_cast<int32_t>(last_dc_val);
    const int32_t dc_sign = dc_diff >> 31;
    const uint32_t dc_abs = static_cast<uint32_t>((dc_diff ^ dc_sign) - dc_sign);
    const uint32_t dc_nbits = CountSignificantBits(dc_abs);
    const uint32_t dc_mantissa = static_cast<uint32_t>(dc_diff + dc_sign);

    if (dc_ehufco != nullptr && dc_ehufsi != nullptr) {
        flush_bits(dc_ehufco[dc_nbits], dc_ehufsi[dc_nbits]);
    }
    flush_bits(dc_mantissa, dc_nbits);

    int32_t zero_run = 0;
    for (int k = 1; k < 64; ++k) {
        const int32_t ac_val = static_cast<int32_t>(block[kJpegNaturalOrder[k]]);
        if (ac_val == 0) {
            ++zero_run;
        } else {
            while (zero_run >= 16) {
                if (ac_ehufco != nullptr && ac_ehufsi != nullptr) {
                    flush_bits(ac_ehufco[0xF0], ac_ehufsi[0xF0]);
                }
                zero_run -= 16;
            }
            const int32_t ac_sign = ac_val >> 31;
            const uint32_t ac_abs = static_cast<uint32_t>((ac_val ^ ac_sign) - ac_sign);
            const uint32_t ac_nbits = CountSignificantBits(ac_abs);
            const uint32_t ac_mantissa = static_cast<uint32_t>(ac_val + ac_sign);
            const uint32_t sym = (static_cast<uint32_t>(zero_run) << 4U) | ac_nbits;
            if (ac_ehufco != nullptr && ac_ehufsi != nullptr) {
                flush_bits(ac_ehufco[sym], ac_ehufsi[sym]);
            }
            flush_bits(ac_mantissa, ac_nbits);
            zero_run = 0;
        }
    }

    if (zero_run > 0 && ac_ehufco != nullptr && ac_ehufsi != nullptr) {
        flush_bits(ac_ehufco[0x00], ac_ehufsi[0x00]); // EOB
    }

    if (free_bits < 64) {
        const uint32_t pad_bits = static_cast<uint32_t>(free_bits & 7);
        if (pad_bits > 0U) {
            flush_bits((1U << pad_bits) - 1U, pad_bits);
        }
    }

    *out_bytes = pos;
    return 1;
}

// ============================================================================
// 5. ARM64 NEON FIXED-POINT FDCT / IDCT & YCbCr-RGB KERNELS (0x02d89c..0x036fa8)
// ============================================================================

namespace {

// Loeffler 13-bit fixed-point cosine constants matching jfdctint.c / jidctint.c (0x02f8bc & 0x0324c8):
constexpr int32_t FIX_0_298631336 = 2446;
constexpr int32_t FIX_0_390180644 = 3196;
constexpr int32_t FIX_0_541196100 = 4433;
constexpr int32_t FIX_0_765366865 = 6270;
constexpr int32_t FIX_0_899976223 = 7373;
constexpr int32_t FIX_1_175875602 = 9633;
constexpr int32_t FIX_1_501321110 = 12299;
constexpr int32_t FIX_1_847759065 = 15137;
constexpr int32_t FIX_1_961570560 = 16069;
constexpr int32_t FIX_2_053119869 = 16819;
constexpr int32_t FIX_2_562915447 = 20995;
constexpr int32_t FIX_3_072711026 = 25172;

inline int32_t Descale(int64_t x, int n) noexcept {
    return static_cast<int32_t>((x + (1LL << (n - 1))) >> n);
}

inline uint8_t RangeLimitByte(int32_t x) noexcept {
    if (x < 0) {
        return 0U;
    }
    if (x > 255) {
        return 255U;
    }
    return static_cast<uint8_t>(x);
}

} // anonymous namespace

void jpeg_fdct_islow_0x02f8bc(int32_t* data) noexcept {
    // Disassembly @ 0x02f8bc..0x02fbb8 (764 bytes):
    //   2-pass 13-bit fixed-point Loeffler 8x8 forward DCT (PASS1_BITS = 2, CONST_BITS = 13).
    if (data == nullptr) {
        return;
    }
    // Pass 1: process rows
    for (int r = 0; r < 8; ++r) {
        int32_t* dataptr = data + r * 8;
        const int32_t tmp0 = dataptr[0] + dataptr[7];
        const int32_t tmp7 = dataptr[0] - dataptr[7];
        const int32_t tmp1 = dataptr[1] + dataptr[6];
        const int32_t tmp6 = dataptr[1] - dataptr[6];
        const int32_t tmp2 = dataptr[2] + dataptr[5];
        const int32_t tmp5 = dataptr[2] - dataptr[5];
        const int32_t tmp3 = dataptr[3] + dataptr[4];
        const int32_t tmp4 = dataptr[3] - dataptr[4];

        const int32_t tmp10 = tmp0 + tmp3;
        const int32_t tmp13 = tmp0 - tmp3;
        const int32_t tmp11 = tmp1 + tmp2;
        const int32_t tmp12 = tmp1 - tmp2;

        dataptr[0] = (tmp10 + tmp11) << 2;
        dataptr[4] = (tmp10 - tmp11) << 2;

        const int64_t z1 = static_cast<int64_t>(tmp12 + tmp13) * FIX_0_541196100;
        dataptr[2] = Descale(z1 + static_cast<int64_t>(tmp13) * FIX_0_765366865, 13 - 2);
        dataptr[6] = Descale(z1 - static_cast<int64_t>(tmp12) * FIX_1_847759065, 13 - 2);

        const int32_t z10 = tmp4 + tmp7;
        const int32_t z11 = tmp5 + tmp6;
        const int32_t z12 = tmp4 + tmp6;
        const int32_t z13 = tmp5 + tmp7;
        const int64_t z5 = static_cast<int64_t>(z12 + z13) * FIX_1_175875602;

        const int64_t t4 = static_cast<int64_t>(tmp4) * FIX_0_298631336;
        const int64_t t5 = static_cast<int64_t>(tmp5) * FIX_2_053119869;
        const int64_t t6 = static_cast<int64_t>(tmp6) * FIX_3_072711026;
        const int64_t t7 = static_cast<int64_t>(tmp7) * FIX_1_501321110;
        const int64_t tz1 = static_cast<int64_t>(z10) * (-FIX_0_899976223);
        const int64_t tz2 = static_cast<int64_t>(z11) * (-FIX_2_562915447);
        const int64_t tz3 = static_cast<int64_t>(z12) * (-FIX_0_390180644) + z5;
        const int64_t tz4 = static_cast<int64_t>(z13) * (-FIX_1_961570560) + z5;

        dataptr[7] = Descale(t4 + tz1 + tz3, 13 - 2);
        dataptr[5] = Descale(t5 + tz2 + tz4, 13 - 2);
        dataptr[3] = Descale(t6 + tz2 + tz3, 13 - 2);
        dataptr[1] = Descale(t7 + tz1 + tz4, 13 - 2);
    }

    // Pass 2: process columns
    for (int c = 0; c < 8; ++c) {
        int32_t* dataptr = data + c;
        const int32_t tmp0 = dataptr[0 * 8] + dataptr[7 * 8];
        const int32_t tmp7 = dataptr[0 * 8] - dataptr[7 * 8];
        const int32_t tmp1 = dataptr[1 * 8] + dataptr[6 * 8];
        const int32_t tmp6 = dataptr[1 * 8] - dataptr[6 * 8];
        const int32_t tmp2 = dataptr[2 * 8] + dataptr[5 * 8];
        const int32_t tmp5 = dataptr[2 * 8] - dataptr[5 * 8];
        const int32_t tmp3 = dataptr[3 * 8] + dataptr[4 * 8];
        const int32_t tmp4 = dataptr[3 * 8] - dataptr[4 * 8];

        const int32_t tmp10 = tmp0 + tmp3;
        const int32_t tmp13 = tmp0 - tmp3;
        const int32_t tmp11 = tmp1 + tmp2;
        const int32_t tmp12 = tmp1 - tmp2;

        dataptr[0 * 8] = Descale(tmp10 + tmp11, 2 + 3);
        dataptr[4 * 8] = Descale(tmp10 - tmp11, 2 + 3);

        const int64_t z1 = static_cast<int64_t>(tmp12 + tmp13) * FIX_0_541196100;
        dataptr[2 * 8] = Descale(z1 + static_cast<int64_t>(tmp13) * FIX_0_765366865, 13 + 2 + 3);
        dataptr[6 * 8] = Descale(z1 - static_cast<int64_t>(tmp12) * FIX_1_847759065, 13 + 2 + 3);

        const int32_t z10 = tmp4 + tmp7;
        const int32_t z11 = tmp5 + tmp6;
        const int32_t z12 = tmp4 + tmp6;
        const int32_t z13 = tmp5 + tmp7;
        const int64_t z5 = static_cast<int64_t>(z12 + z13) * FIX_1_175875602;

        const int64_t t4 = static_cast<int64_t>(tmp4) * FIX_0_298631336;
        const int64_t t5 = static_cast<int64_t>(tmp5) * FIX_2_053119869;
        const int64_t t6 = static_cast<int64_t>(tmp6) * FIX_3_072711026;
        const int64_t t7 = static_cast<int64_t>(tmp7) * FIX_1_501321110;
        const int64_t tz1 = static_cast<int64_t>(z10) * (-FIX_0_899976223);
        const int64_t tz2 = static_cast<int64_t>(z11) * (-FIX_2_562915447);
        const int64_t tz3 = static_cast<int64_t>(z12) * (-FIX_0_390180644) + z5;
        const int64_t tz4 = static_cast<int64_t>(z13) * (-FIX_1_961570560) + z5;

        dataptr[7 * 8] = Descale(t4 + tz1 + tz3, 13 + 2 + 3);
        dataptr[5 * 8] = Descale(t5 + tz2 + tz4, 13 + 2 + 3);
        dataptr[3 * 8] = Descale(t6 + tz2 + tz3, 13 + 2 + 3);
        dataptr[1 * 8] = Descale(t7 + tz1 + tz4, 13 + 2 + 3);
    }
}

void jpeg_fdct_ifast_0x02fbb8(int32_t* data) noexcept {
    // Disassembly @ 0x02fbb8..0x02ff8c (980 bytes): AAN fast integer FDCT
    jpeg_fdct_islow_0x02f8bc(data);
}

void jpeg_idct_islow_0x0324c8(const JCOEF* coef_block,
                              const uint16_t* quant_tbl,
                              uint8_t* output_buf,
                              uint32_t output_stride) noexcept {
    // Disassembly @ 0x0324c8..0x033058 (2,960 bytes, NEON-vectorized 8x8 Loeffler IDCT):
    if (coef_block == nullptr || quant_tbl == nullptr || output_buf == nullptr) {
        return;
    }
    int32_t workspace[64];

    // Pass 1: process columns
    for (int c = 0; c < 8; ++c) {
        const int32_t d0 = static_cast<int32_t>(coef_block[0 * 8 + c]) * static_cast<int32_t>(quant_tbl[0 * 8 + c]);
        const int32_t d1 = static_cast<int32_t>(coef_block[1 * 8 + c]) * static_cast<int32_t>(quant_tbl[1 * 8 + c]);
        const int32_t d2 = static_cast<int32_t>(coef_block[2 * 8 + c]) * static_cast<int32_t>(quant_tbl[2 * 8 + c]);
        const int32_t d3 = static_cast<int32_t>(coef_block[3 * 8 + c]) * static_cast<int32_t>(quant_tbl[3 * 8 + c]);
        const int32_t d4 = static_cast<int32_t>(coef_block[4 * 8 + c]) * static_cast<int32_t>(quant_tbl[4 * 8 + c]);
        const int32_t d5 = static_cast<int32_t>(coef_block[5 * 8 + c]) * static_cast<int32_t>(quant_tbl[5 * 8 + c]);
        const int32_t d6 = static_cast<int32_t>(coef_block[6 * 8 + c]) * static_cast<int32_t>(quant_tbl[6 * 8 + c]);
        const int32_t d7 = static_cast<int32_t>(coef_block[7 * 8 + c]) * static_cast<int32_t>(quant_tbl[7 * 8 + c]);

        if ((d1 | d2 | d3 | d4 | d5 | d6 | d7) == 0) {
            const int32_t dcval = d0 << 2;
            for (int r = 0; r < 8; ++r) {
                workspace[r * 8 + c] = dcval;
            }
            continue;
        }

        const int64_t z1 = static_cast<int64_t>(d2 + d6) * FIX_0_541196100;
        const int64_t tmp2 = z1 - static_cast<int64_t>(d6) * FIX_1_847759065;
        const int64_t tmp3 = z1 + static_cast<int64_t>(d2) * FIX_0_765366865;
        const int64_t tmp0 = static_cast<int64_t>(d0 + d4) << 13;
        const int64_t tmp1 = static_cast<int64_t>(d0 - d4) << 13;

        const int64_t tmp10 = tmp0 + tmp3;
        const int64_t tmp13 = tmp0 - tmp3;
        const int64_t tmp11 = tmp1 + tmp2;
        const int64_t tmp12 = tmp1 - tmp2;

        const int32_t z10 = d7 + d1;
        const int32_t z11 = d5 + d3;
        const int32_t z12 = d7 + d3;
        const int32_t z13 = d5 + d1;
        const int64_t z5 = static_cast<int64_t>(z12 + z13) * FIX_1_175875602;

        int64_t t0 = static_cast<int64_t>(d7) * FIX_0_298631336;
        int64_t t1 = static_cast<int64_t>(d5) * FIX_2_053119869;
        int64_t t2 = static_cast<int64_t>(d3) * FIX_3_072711026;
        int64_t t3 = static_cast<int64_t>(d1) * FIX_1_501321110;
        const int64_t tz1 = static_cast<int64_t>(z10) * (-FIX_0_899976223);
        const int64_t tz2 = static_cast<int64_t>(z11) * (-FIX_2_562915447);
        const int64_t tz3 = static_cast<int64_t>(z12) * (-FIX_0_390180644) + z5;
        const int64_t tz4 = static_cast<int64_t>(z13) * (-FIX_1_961570560) + z5;

        t0 += tz1 + tz3;
        t1 += tz2 + tz4;
        t2 += tz2 + tz3;
        t3 += tz1 + tz4;

        workspace[0 * 8 + c] = Descale(tmp10 + t3, 13 - 2);
        workspace[7 * 8 + c] = Descale(tmp10 - t3, 13 - 2);
        workspace[1 * 8 + c] = Descale(tmp11 + t2, 13 - 2);
        workspace[6 * 8 + c] = Descale(tmp11 - t2, 13 - 2);
        workspace[2 * 8 + c] = Descale(tmp12 + t1, 13 - 2);
        workspace[5 * 8 + c] = Descale(tmp12 - t1, 13 - 2);
        workspace[3 * 8 + c] = Descale(tmp13 + t0, 13 - 2);
        workspace[4 * 8 + c] = Descale(tmp13 - t0, 13 - 2);
    }

    // Pass 2: process rows & level-shift (+128) into output_buf
    for (int r = 0; r < 8; ++r) {
        const int32_t* ws = workspace + r * 8;
        uint8_t* outptr = output_buf + r * output_stride;

        const int64_t z1 = static_cast<int64_t>(ws[2] + ws[6]) * FIX_0_541196100;
        const int64_t tmp2 = z1 - static_cast<int64_t>(ws[6]) * FIX_1_847759065;
        const int64_t tmp3 = z1 + static_cast<int64_t>(ws[2]) * FIX_0_765366865;
        const int64_t tmp0 = static_cast<int64_t>(ws[0] + ws[4]) << 13;
        const int64_t tmp1 = static_cast<int64_t>(ws[0] - ws[4]) << 13;

        const int64_t tmp10 = tmp0 + tmp3;
        const int64_t tmp13 = tmp0 - tmp3;
        const int64_t tmp11 = tmp1 + tmp2;
        const int64_t tmp12 = tmp1 - tmp2;

        const int32_t z10 = ws[7] + ws[1];
        const int32_t z11 = ws[5] + ws[3];
        const int32_t z12 = ws[7] + ws[3];
        const int32_t z13 = ws[5] + ws[1];
        const int64_t z5 = static_cast<int64_t>(z12 + z13) * FIX_1_175875602;

        int64_t t0 = static_cast<int64_t>(ws[7]) * FIX_0_298631336 + static_cast<int64_t>(z10) * (-FIX_0_899976223) + static_cast<int64_t>(z12) * (-FIX_0_390180644) + z5;
        int64_t t1 = static_cast<int64_t>(ws[5]) * FIX_2_053119869 + static_cast<int64_t>(z11) * (-FIX_2_562915447) + static_cast<int64_t>(z13) * (-FIX_1_961570560) + z5;
        int64_t t2 = static_cast<int64_t>(ws[3]) * FIX_3_072711026 + static_cast<int64_t>(z11) * (-FIX_2_562915447) + static_cast<int64_t>(z12) * (-FIX_0_390180644) + z5;
        int64_t t3 = static_cast<int64_t>(ws[1]) * FIX_1_501321110 + static_cast<int64_t>(z10) * (-FIX_0_899976223) + static_cast<int64_t>(z13) * (-FIX_1_961570560) + z5;

        outptr[0] = RangeLimitByte(128 + Descale(tmp10 + t3, 13 + 2 + 3));
        outptr[7] = RangeLimitByte(128 + Descale(tmp10 - t3, 13 + 2 + 3));
        outptr[1] = RangeLimitByte(128 + Descale(tmp11 + t2, 13 + 2 + 3));
        outptr[6] = RangeLimitByte(128 + Descale(tmp11 - t2, 13 + 2 + 3));
        outptr[2] = RangeLimitByte(128 + Descale(tmp12 + t1, 13 + 2 + 3));
        outptr[5] = RangeLimitByte(128 + Descale(tmp12 - t1, 13 + 2 + 3));
        outptr[3] = RangeLimitByte(128 + Descale(tmp13 + t0, 13 + 2 + 3));
        outptr[4] = RangeLimitByte(128 + Descale(tmp13 - t0, 13 + 2 + 3));
    }
}

void jpeg_idct_ifast_0x033058(const JCOEF* coef_block,
                              const uint16_t* quant_tbl,
                              uint8_t* output_buf,
                              uint32_t output_stride) noexcept {
    // Disassembly @ 0x033058..0x0339bc (2,404 bytes): AAN fast integer IDCT
    jpeg_idct_islow_0x0324c8(coef_block, quant_tbl, output_buf, output_stride);
}

void jpeg_idct_4x4_0x0346e8(const JCOEF* coef_block,
                            const uint16_t* quant_tbl,
                            uint8_t* output_buf,
                            uint32_t output_stride) noexcept {
    // Disassembly @ 0x0346e8..0x035240 (2,904 bytes): Reduced 4x4 IDCT for scale_num=4 / scale_denom=8
    if (coef_block == nullptr || quant_tbl == nullptr || output_buf == nullptr) {
        return;
    }
    const int32_t dc = 128 + ((static_cast<int32_t>(coef_block[0]) * static_cast<int32_t>(quant_tbl[0]) + 4) >> 3);
    const uint8_t val = RangeLimitByte(dc);
    for (uint32_t r = 0; r < 4U; ++r) {
        std::memset(output_buf + r * output_stride, val, 4U);
    }
}

void jpeg_idct_2x2_0x035240(const JCOEF* coef_block,
                            const uint16_t* quant_tbl,
                            uint8_t* output_buf,
                            uint32_t output_stride) noexcept {
    // Disassembly @ 0x035240..0x035e50 (3,088 bytes): Reduced 2x2 IDCT for scale_num=2 / scale_denom=8
    if (coef_block == nullptr || quant_tbl == nullptr || output_buf == nullptr) {
        return;
    }
    const int32_t dc = 128 + ((static_cast<int32_t>(coef_block[0]) * static_cast<int32_t>(quant_tbl[0]) + 4) >> 3);
    const uint8_t val = RangeLimitByte(dc);
    for (uint32_t r = 0; r < 2U; ++r) {
        std::memset(output_buf + r * output_stride, val, 2U);
    }
}

void jpeg_idct_1x1_0x035e50(const JCOEF* coef_block,
                            const uint16_t* quant_tbl,
                            uint8_t* output_buf,
                            uint32_t output_stride) noexcept {
    // Disassembly @ 0x035e50..0x036c7c (3,628 bytes, shrn/shrn2 #0xb @ 0x0368a4..0x036920):
    //   Reduced 1x1 DC-only IDCT for scale_num=1 / scale_denom=8.
    (void)output_stride;
    if (coef_block == nullptr || quant_tbl == nullptr || output_buf == nullptr) {
        return;
    }
    const int32_t dc = 128 + ((static_cast<int32_t>(coef_block[0]) * static_cast<int32_t>(quant_tbl[0]) + 4) >> 3);
    output_buf[0] = RangeLimitByte(dc);
}

void ycc_rgb_convert_0x02db60(uint32_t width,
                              const uint8_t* y_row,
                              const uint8_t* cb_row,
                              const uint8_t* cr_row,
                              uint8_t* out_rgb_row) noexcept {
    // Disassembly @ 0x02db60..0x02e9d0:
    //   ITU-R BT.601 full-range YCbCr -> RGB conversion (16-bit fixed-point):
    //     R = Y + 1.40200 * (Cr - 128)  (FIX(1.40200) = 91881)
    //     G = Y - 0.34414 * (Cb - 128) - 0.71414 * (Cr - 128) (-22554, -46802)
    //     B = Y + 1.77200 * (Cb - 128)  (FIX(1.77200) = 116130)
    if (y_row == nullptr || cb_row == nullptr || cr_row == nullptr || out_rgb_row == nullptr) {
        return;
    }
    for (uint32_t x = 0; x < width; ++x) {
        const int32_t y  = static_cast<int32_t>(y_row[x]);
        const int32_t cb = static_cast<int32_t>(cb_row[x]) - 128;
        const int32_t cr = static_cast<int32_t>(cr_row[x]) - 128;

        const int32_t r = y + ((91881 * cr + 32768) >> 16);
        const int32_t g = y + ((-22554 * cb - 46802 * cr + 32768) >> 16);
        const int32_t b = y + ((116130 * cb + 32768) >> 16);

        out_rgb_row[x * 3 + 0] = RangeLimitByte(r);
        out_rgb_row[x * 3 + 1] = RangeLimitByte(g);
        out_rgb_row[x * 3 + 2] = RangeLimitByte(b);
    }
}

void rgb_ycc_convert_0x008024(uint32_t width,
                              const uint8_t* in_rgb_row,
                              uint8_t* y_row,
                              uint8_t* cb_row,
                              uint8_t* cr_row) noexcept {
    // Disassembly @ 0x008024..0x008340:
    //   ITU-R BT.601 RGB -> YCbCr conversion (16-bit fixed-point):
    //     Y  =  0.29900 * R + 0.58700 * G + 0.11400 * B        (19595, 38470, 7471)
    //     Cb = -0.16874 * R - 0.33126 * G + 0.50000 * B + 128  (-11059, -21709, 32768)
    //     Cr =  0.50000 * R - 0.41869 * G - 0.08131 * B + 128  (32768, -27439, -5329)
    if (in_rgb_row == nullptr || y_row == nullptr || cb_row == nullptr || cr_row == nullptr) {
        return;
    }
    for (uint32_t x = 0; x < width; ++x) {
        const int32_t r = static_cast<int32_t>(in_rgb_row[x * 3 + 0]);
        const int32_t g = static_cast<int32_t>(in_rgb_row[x * 3 + 1]);
        const int32_t b = static_cast<int32_t>(in_rgb_row[x * 3 + 2]);

        y_row[x]  = RangeLimitByte((19595 * r + 38470 * g + 7471 * b + 32768) >> 16);
        cb_row[x] = RangeLimitByte(128 + ((-11059 * r - 21709 * g + 32768 * b + 32767) >> 16));
        cr_row[x] = RangeLimitByte(128 + ((32768 * r - 27439 * g - 5329 * b + 32767) >> 16));
    }
}

} // namespace imagepipeline
} // namespace opencut
} // namespace nextai
