/**
 * @file ttheif_isobmff.cpp
 * @brief ISO Base Media File Format (ISO/IEC 14496-12 & 23008-12) Container Implementation
 *        Triển khai bộ phân tích định dạng tệp cơ sở phương tiện ISO (ISOBMFF)
 *
 * Cleanroom implementation reconstructed from ByteDance libttheif_dec.so (AArch64).
 * Tái cấu trúc phòng sạch từ libttheif_dec.so (AArch64) của ByteDance.
 */

#include "ttheif_isobmff.h"
#include <string.h>
#include <stdlib.h>

static inline uint32_t read_u32_be(const uint8_t* p) {
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | (uint32_t)p[3];
}

static inline uint64_t read_u64_be(const uint8_t* p) {
    return ((uint64_t)read_u32_be(p) << 32) | (uint64_t)read_u32_be(p + 4);
}

static inline uint16_t read_u16_be(const uint8_t* p) {
    return ((uint16_t)p[0] << 8) | (uint16_t)p[1];
}

int isobmff_parser_init(isobmff_parser_ctx_t* ctx, const uint8_t* data, size_t size) {
    if (!ctx || !data || size < 8) return HEIF_DEC_ERR_INVALID_PARAM;
    memset(ctx, 0, sizeof(isobmff_parser_ctx_t));
    ctx->buffer = data;
    ctx->buffer_size = size;
    return HEIF_DEC_OK;
}

static int parse_box_header(const uint8_t* buf, size_t max_len, isobmff_box_header_t* hdr) {
    if (max_len < 8) return -1;
    hdr->size = read_u32_be(buf);
    hdr->type = read_u32_be(buf + 4);
    hdr->header_size = 8;
    hdr->largesize = hdr->size;

    if (hdr->size == 1) { // 64-bit large size
        if (max_len < 16) return -1;
        hdr->largesize = read_u64_be(buf + 8);
        hdr->header_size = 16;
    } else if (hdr->size == 0) {
        hdr->largesize = max_len;
    }

    return 0;
}

static void parse_ftyp_box(isobmff_parser_ctx_t* ctx, const uint8_t* payload, size_t len) {
    if (len < 8) return;
    ctx->major_brand = read_u32_be(payload);
    ctx->minor_version = read_u32_be(payload + 4);
    size_t offset = 8;
    ctx->compatible_brand_count = 0;
    while (offset + 4 <= len && ctx->compatible_brand_count < 16) {
        ctx->compatible_brands[ctx->compatible_brand_count++] = read_u32_be(payload + offset);
        offset += 4;
    }
}

static void parse_pitm_box(isobmff_parser_ctx_t* ctx, const uint8_t* payload, size_t len) {
    if (len < 4) return;
    uint8_t version = payload[0];
    if (version == 0 && len >= 6) {
        ctx->primary_item_id = read_u16_be(payload + 4);
    } else if (version == 1 && len >= 8) {
        ctx->primary_item_id = read_u32_be(payload + 4);
    }
}

static isobmff_item_t* find_or_add_item(isobmff_parser_ctx_t* ctx, uint32_t item_id) {
    for (size_t i = 0; i < ctx->item_count; ++i) {
        if (ctx->items[i].item_id == item_id) {
            return &ctx->items[i];
        }
    }
    if (ctx->item_count < 32) {
        isobmff_item_t* item = &ctx->items[ctx->item_count++];
        memset(item, 0, sizeof(isobmff_item_t));
        item->item_id = item_id;
        return item;
    }
    return NULL;
}

static void parse_infe_box(isobmff_parser_ctx_t* ctx, const uint8_t* payload, size_t len) {
    if (len < 12) return;
    uint8_t version = payload[0];
    uint32_t item_id = 0;
    uint32_t item_type = 0;

    if (version == 2 || version == 3) {
        if (version == 2) {
            item_id = read_u16_be(payload + 4);
            item_type = read_u32_be(payload + 8);
        } else {
            item_id = read_u32_be(payload + 4);
            item_type = read_u32_be(payload + 8);
        }
        isobmff_item_t* item = find_or_add_item(ctx, item_id);
        if (item) {
            item->item_type = item_type;
        }
    }
}

static void parse_iloc_box(isobmff_parser_ctx_t* ctx, const uint8_t* payload, size_t len) {
    if (len < 8) return;
    uint8_t version = payload[0];
    uint8_t offset_size = (payload[4] >> 4) & 0x0F;
    uint8_t length_size = payload[4] & 0x0F;
    uint8_t base_offset_size = (payload[5] >> 4) & 0x0F;
    uint8_t index_size = (version == 1 || version == 2) ? (payload[5] & 0x0F) : 0;
    (void)index_size;

    size_t cursor = 6;
    uint32_t item_count = (version < 2) ? read_u16_be(payload + cursor) : read_u32_be(payload + cursor);
    cursor += (version < 2) ? 2 : 4;

    for (uint32_t i = 0; i < item_count && cursor < len; ++i) {
        uint32_t item_id = (version < 2) ? read_u16_be(payload + cursor) : read_u32_be(payload + cursor);
        cursor += (version < 2) ? 2 : 4;
        if (version == 1 || version == 2) cursor += 2; // skip construction_method

        cursor += 2; // skip data_reference_index
        uint64_t base_offset = 0;
        if (base_offset_size == 4) {
            base_offset = read_u32_be(payload + cursor);
            cursor += 4;
        } else if (base_offset_size == 8) {
            base_offset = read_u64_be(payload + cursor);
            cursor += 8;
        }

        uint16_t extent_count = read_u16_be(payload + cursor);
        cursor += 2;

        uint64_t extent_offset = 0;
        uint64_t extent_len = 0;

        for (uint16_t e = 0; e < extent_count && cursor < len; ++e) {
            if (offset_size == 4) {
                extent_offset = read_u32_be(payload + cursor);
                cursor += 4;
            } else if (offset_size == 8) {
                extent_offset = read_u64_be(payload + cursor);
                cursor += 8;
            }
            if (length_size == 4) {
                extent_len = read_u32_be(payload + cursor);
                cursor += 4;
            } else if (length_size == 8) {
                extent_len = read_u64_be(payload + cursor);
                cursor += 8;
            }
        }

        isobmff_item_t* item = find_or_add_item(ctx, item_id);
        if (item) {
            item->offset = base_offset + extent_offset;
            item->length = extent_len;
        }
    }
}

static void parse_ispe_box(isobmff_parser_ctx_t* ctx, const uint8_t* payload, size_t len) {
    if (len < 12) return;
    uint32_t width = read_u32_be(payload + 4);
    uint32_t height = read_u32_be(payload + 8);
    // Assign dimensions to items / Gán kích thước cho các phần tử ảnh
    for (size_t i = 0; i < ctx->item_count; ++i) {
        if (ctx->items[i].width == 0 && ctx->items[i].height == 0) {
            ctx->items[i].width = width;
            ctx->items[i].height = height;
            break;
        }
    }
}

static void parse_meta_subboxes(isobmff_parser_ctx_t* ctx, const uint8_t* data, size_t size) {
    size_t cursor = 4; // Skip 4-byte FullBox header (version + flags)
    while (cursor + 8 <= size) {
        isobmff_box_header_t subhdr;
        if (parse_box_header(data + cursor, size - cursor, &subhdr) != 0) break;
        if (subhdr.largesize < subhdr.header_size || cursor + subhdr.largesize > size) break;

        const uint8_t* payload = data + cursor + subhdr.header_size;
        size_t payload_len = subhdr.largesize - subhdr.header_size;

        switch (subhdr.type) {
            case FOURCC_PITM:
                parse_pitm_box(ctx, payload, payload_len);
                break;
            case FOURCC_ILOC:
                parse_iloc_box(ctx, payload, payload_len);
                break;
            case FOURCC_INFE:
                parse_infe_box(ctx, payload, payload_len);
                break;
            case FOURCC_ISPE:
                parse_ispe_box(ctx, payload, payload_len);
                break;
            case FOURCC_IPRP:
            case FOURCC_IPCO:
            case FOURCC_IINF:
                // Recurse into nested container boxes / Đệ quy vào các box lồng nhau
                parse_meta_subboxes(ctx, payload, payload_len);
                break;
            default:
                break;
        }

        cursor += subhdr.largesize;
    }
}

int isobmff_parse_container(isobmff_parser_ctx_t* ctx) {
    if (!ctx || !ctx->buffer) return HEIF_DEC_ERR_INVALID_PARAM;

    size_t cursor = 0;
    while (cursor + 8 <= ctx->buffer_size) {
        isobmff_box_header_t hdr;
        if (parse_box_header(ctx->buffer + cursor, ctx->buffer_size - cursor, &hdr) != 0) {
            break;
        }

        if (hdr.largesize < hdr.header_size || cursor + hdr.largesize > ctx->buffer_size) {
            break;
        }

        const uint8_t* payload = ctx->buffer + cursor + hdr.header_size;
        size_t payload_len = hdr.largesize - hdr.header_size;

        if (hdr.type == FOURCC_FTYP) {
            parse_ftyp_box(ctx, payload, payload_len);
        } else if (hdr.type == FOURCC_META) {
            parse_meta_subboxes(ctx, payload, payload_len);
        } else if (hdr.type == FOURCC_MDAT) {
            ctx->mdat_offset = cursor + hdr.header_size;
            ctx->mdat_size = payload_len;
        }

        cursor += hdr.largesize;
    }

    // Flag primary item / Gắn cờ cho item chính
    for (size_t i = 0; i < ctx->item_count; ++i) {
        if (ctx->items[i].item_id == ctx->primary_item_id) {
            ctx->items[i].is_primary = true;
        }
    }

    return (ctx->item_count > 0 || ctx->major_brand != 0) ? HEIF_DEC_OK : HEIF_DEC_ERR_PARSE_BOX;
}

const isobmff_item_t* isobmff_get_primary_item(const isobmff_parser_ctx_t* ctx) {
    if (!ctx) return NULL;
    for (size_t i = 0; i < ctx->item_count; ++i) {
        if (ctx->items[i].is_primary) return &ctx->items[i];
    }
    return ctx->item_count > 0 ? &ctx->items[0] : NULL;
}

const isobmff_item_t* isobmff_get_thumbnail_item(const isobmff_parser_ctx_t* ctx) {
    if (!ctx) return NULL;
    for (size_t i = 0; i < ctx->item_count; ++i) {
        if (ctx->items[i].is_thumbnail || (ctx->items[i].width > 0 && ctx->items[i].width <= 512 && !ctx->items[i].is_primary)) {
            return &ctx->items[i];
        }
    }
    return NULL;
}

const isobmff_item_t* isobmff_get_exif_item(const isobmff_parser_ctx_t* ctx) {
    if (!ctx) return NULL;
    for (size_t i = 0; i < ctx->item_count; ++i) {
        if (ctx->items[i].item_type == 0x45786966) { // 'Exif'
            return &ctx->items[i];
        }
    }
    return NULL;
}
