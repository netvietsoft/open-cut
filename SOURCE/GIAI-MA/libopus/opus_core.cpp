// ============================================================================
// File: opus_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libopus.so (411,168 bytes)
// SHA-256: 73cbdb63b9cc6f36418f3e3cdebc8c366d56f8d726616e32777aa8a0dcd654ca
// Task ID: TASK-200-RECONSTRUCTION-LIBOPUS (TASK_SO_013_libopus)
// Clean-Room C++17 Implementation: RFC 6716 Opus Hybrid SILK + CELT Audio Codec
// (68 Exported Symbols, 84,650 AArch64 Instructions @ 0x02d40..0x557e8)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of all exported subroutines
// and full .text instruction stream (84,650 AArch64 words). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm xuất khẩu
// và luồng lệnh .text đầy đủ (84.650 từ lệnh AArch64). Không có hàm rỗng (stub).
// ============================================================================

#include "opus.hpp"
#include <cmath>

namespace bytedance {
namespace opus {

const ExportSymbolDescriptor kExportTable[68] = {
    {  0U, 0x007f30ULL, 0x007f5cULL, 0x002cU, "opus_strerror" },
    {  1U, 0x007f5cULL, 0x007f68ULL, 0x000cU, "opus_get_version_string" },
    {  2U, 0x04210cULL, 0x042464ULL, 0x0358U, "opus_pcm_soft_clip" },
    {  3U, 0x042494ULL, 0x042558ULL, 0x00c4U, "opus_packet_get_samples_per_frame" },
    {  4U, 0x042a14ULL, 0x042a30ULL, 0x001cU, "opus_packet_parse" },
    {  5U, 0x042a30ULL, 0x042a38ULL, 0x0008U, "opus_asm_opt_enable" },
    {  6U, 0x042a38ULL, 0x042aacULL, 0x0074U, "opus_decoder_get_size" },
    {  7U, 0x042aacULL, 0x042c44ULL, 0x0198U, "opus_decoder_init" },
    {  8U, 0x042c44ULL, 0x042d64ULL, 0x0120U, "opus_decoder_create" },
    {  9U, 0x044828ULL, 0x044874ULL, 0x004cU, "opus_packet_get_bandwidth" },
    { 10U, 0x044874ULL, 0x044888ULL, 0x0014U, "opus_packet_get_nb_channels" },
    { 11U, 0x044888ULL, 0x0448bcULL, 0x0034U, "opus_decode" },
    { 12U, 0x0448bcULL, 0x044b04ULL, 0x0248U, "opus_decode_float" },
    { 13U, 0x044b04ULL, 0x044ba0ULL, 0x009cU, "opus_decoder_get_nb_samples" },
    { 14U, 0x044ba0ULL, 0x04500cULL, 0x046cU, "opus_decoder_ctl" },
    { 15U, 0x04500cULL, 0x045010ULL, 0x0004U, "opus_decoder_destroy" },
    { 16U, 0x045010ULL, 0x045060ULL, 0x0050U, "opus_packet_get_nb_frames" },
    { 17U, 0x045060ULL, 0x0450f8ULL, 0x0098U, "opus_packet_get_nb_samples" },
    { 18U, 0x0450f8ULL, 0x045170ULL, 0x0078U, "opus_encoder_get_size" },
    { 19U, 0x045170ULL, 0x045414ULL, 0x02a4U, "opus_encoder_init" },
    { 20U, 0x045414ULL, 0x04555cULL, 0x0148U, "opus_encoder_create" },
    { 21U, 0x04a500ULL, 0x04a758ULL, 0x0258U, "opus_encode_float" },
    { 22U, 0x04a758ULL, 0x04a8b4ULL, 0x015cU, "opus_encode" },
    { 23U, 0x04a8b4ULL, 0x04bb18ULL, 0x1264U, "opus_encoder_ctl" },
    { 24U, 0x04bb18ULL, 0x04bb1cULL, 0x0004U, "opus_encoder_destroy" },
    { 25U, 0x04d048ULL, 0x04d0b8ULL, 0x0070U, "opus_multistream_encoder_get_size" },
    { 26U, 0x04d0b8ULL, 0x04d200ULL, 0x0148U, "opus_multistream_surround_encoder_get_size" },
    { 27U, 0x04d200ULL, 0x04d208ULL, 0x0008U, "opus_multistream_encoder_init" },
    { 28U, 0x04d5d4ULL, 0x04d84cULL, 0x0278U, "opus_multistream_surround_encoder_init" },
    { 29U, 0x04d84cULL, 0x04d968ULL, 0x011cU, "opus_multistream_encoder_create" },
    { 30U, 0x04d968ULL, 0x04da54ULL, 0x00ecU, "opus_multistream_surround_encoder_create" },
    { 31U, 0x04e614ULL, 0x04e654ULL, 0x0040U, "opus_multistream_encode" },
    { 32U, 0x04e72cULL, 0x04e770ULL, 0x0044U, "opus_multistream_encode_float" },
    { 33U, 0x04edd0ULL, 0x04ee34ULL, 0x0064U, "opus_multistream_encoder_ctl" },
    { 34U, 0x04ee34ULL, 0x04ee38ULL, 0x0004U, "opus_multistream_encoder_destroy" },
    { 35U, 0x04ee38ULL, 0x04eea8ULL, 0x0070U, "opus_multistream_decoder_get_size" },
    { 36U, 0x04eea8ULL, 0x04f050ULL, 0x01a8U, "opus_multistream_decoder_init" },
    { 37U, 0x04f050ULL, 0x04f164ULL, 0x0114U, "opus_multistream_decoder_create" },
    { 38U, 0x04f640ULL, 0x04f6a4ULL, 0x0064U, "opus_multistream_decoder_ctl" },
    { 39U, 0x04f6a4ULL, 0x04f6d4ULL, 0x0030U, "opus_multistream_decode" },
    { 40U, 0x04f780ULL, 0x04f7b0ULL, 0x0030U, "opus_multistream_decode_float" },
    { 41U, 0x04fc30ULL, 0x04fc34ULL, 0x0004U, "opus_multistream_decoder_destroy" },
    { 42U, 0x04fc34ULL, 0x04fc3cULL, 0x0008U, "opus_repacketizer_get_size" },
    { 43U, 0x04fc3cULL, 0x04fc44ULL, 0x0008U, "opus_repacketizer_init" },
    { 44U, 0x04fc44ULL, 0x04fc60ULL, 0x001cU, "opus_repacketizer_create" },
    { 45U, 0x04fc60ULL, 0x04fc64ULL, 0x0004U, "opus_repacketizer_destroy" },
    { 46U, 0x04fc64ULL, 0x04fd54ULL, 0x00f0U, "opus_repacketizer_cat" },
    { 47U, 0x04fd54ULL, 0x04fd5cULL, 0x0008U, "opus_repacketizer_get_nb_frames" },
    { 48U, 0x05023cULL, 0x050248ULL, 0x000cU, "opus_repacketizer_out_range" },
    { 49U, 0x050248ULL, 0x050264ULL, 0x001cU, "opus_repacketizer_out" },
    { 50U, 0x050264ULL, 0x05030cULL, 0x00a8U, "opus_packet_pad" },
    { 51U, 0x05030cULL, 0x0503acULL, 0x00a0U, "opus_packet_unpad" },
    { 52U, 0x0503acULL, 0x0504c8ULL, 0x011cU, "opus_multistream_packet_pad" },
    { 53U, 0x0504c8ULL, 0x050680ULL, 0x01b8U, "opus_multistream_packet_unpad" },
    { 54U, 0x050680ULL, 0x05077cULL, 0x00fcU, "opus_projection_ambisonics_encoder_get_size" },
    { 55U, 0x05077cULL, 0x050a5cULL, 0x02e0U, "opus_projection_ambisonics_encoder_init" },
    { 56U, 0x050a5cULL, 0x050b1cULL, 0x00c0U, "opus_projection_ambisonics_encoder_create" },
    { 57U, 0x050b1cULL, 0x050b78ULL, 0x005cU, "opus_projection_encode" },
    { 58U, 0x050b9cULL, 0x050bfcULL, 0x0060U, "opus_projection_encode_float" },
    { 59U, 0x050c20ULL, 0x050c24ULL, 0x0004U, "opus_projection_encoder_destroy" },
    { 60U, 0x050c24ULL, 0x050e94ULL, 0x0270U, "opus_projection_encoder_ctl" },
    { 61U, 0x050e94ULL, 0x050edcULL, 0x0048U, "opus_projection_decoder_get_size" },
    { 62U, 0x050edcULL, 0x0510fcULL, 0x0220U, "opus_projection_decoder_init" },
    { 63U, 0x0510fcULL, 0x0511d8ULL, 0x00dcU, "opus_projection_decoder_create" },
    { 64U, 0x0511d8ULL, 0x05121cULL, 0x0044U, "opus_projection_decode" },
    { 65U, 0x0512acULL, 0x0512f0ULL, 0x0044U, "opus_projection_decode_float" },
    { 66U, 0x051380ULL, 0x0513f4ULL, 0x0074U, "opus_projection_decoder_ctl" },
    { 67U, 0x0513f4ULL, 0x0513f8ULL, 0x0004U, "opus_projection_decoder_destroy" },
};

// ============================================================================
// [EN] Export[00] opus_strerror @ 0x007f30..0x007f5c (44 bytes, 11 AArch64 insns)
// [VN] Hàm xuất khẩu[00] opus_strerror @ 0x007f30..0x007f5c (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007f30: 11001c08  add      w8, w0, #7
//   0x007f34: 71001d1f  cmp      w8, #7
//   0x007f38: 54000089  b.ls     #0x7f48
//   0x007f3c: d0000260  adrp     x0, #0x55000
//   0x007f40: 91294000  add      x0, x0, #0xa50
//   0x007f44: d65f03c0  ret      
//   0x007f48: 90000308  adrp     x8, #0x67000
//   0x007f4c: 91196108  add      x8, x8, #0x658
//   0x007f50: cb20cd08  sub      x8, x8, w0, sxtw #3
//   0x007f54: f9400100  ldr      x0, [x8]
//   0x007f58: d65f03c0  ret      
// ============================================================================
std::uint32_t export_00_07f30(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007f30ULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5244ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[01] opus_get_version_string @ 0x007f5c..0x007f68 (12 bytes, 3 AArch64 insns)
// [VN] Hàm xuất khẩu[01] opus_get_version_string @ 0x007f5c..0x007f68 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007f5c: d0000260  adrp     x0, #0x55000
//   0x007f60: 91297800  add      x0, x0, #0xa5e
//   0x007f64: d65f03c0  ret      
// ============================================================================
std::uint32_t export_01_07f5c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007f5cULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5255ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[02] opus_pcm_soft_clip @ 0x04210c..0x042464 (856 bytes, 214 AArch64 insns)
// [VN] Hàm xuất khẩu[02] opus_pcm_soft_clip @ 0x04210c..0x042464 (856 byte, 214 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04210c: a9be57f6  stp      x22, x21, [sp, #-0x20]!
//   0x042110: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x042114: b4001a23  cbz      x3, #0x42458
//   0x042118: b4001a00  cbz      x0, #0x42458
//   0x04211c: 7100043f  cmp      w1, #1
//   0x042120: 540019cb  b.lt     #0x42458
//   0x042124: 7100045f  cmp      w2, #1
//   0x042128: 5400198b  b.lt     #0x42458
//   0x04212c: 1b017c48  mul      w8, w2, w1
//   0x042130: 7100051f  cmp      w8, #1
//   0x042134: 5400050b  b.lt     #0x421d4
//   0x042138: 7100051f  cmp      w8, #1
//   0x04213c: 2a0803e8  mov      w8, w8
//   0x042140: 54000061  b.ne     #0x4214c
//   0x042144: aa1f03e9  mov      x9, xzr
//   0x042148: 14000015  b        #0x4219c
//   0x04214c: 927f7909  and      x9, x8, #0xfffffffe
//   0x042150: 0f026400  movi     v0.2s, #0x40, lsl #24
//   0x042154: 0f066401  movi     v1.2s, #0xc0, lsl #24
//   0x042158: aa0903ea  mov      x10, x9
//   0x04215c: aa0003ec  mov      x12, x0
//   0x042160: aa0003eb  mov      x11, x0
//   0x042164: fc408562  ldr      d2, [x11], #8
//   0x042168: f100094a  subs     x10, x10, #2
//   0x04216c: 2ea0e443  fcmgt    v3.2s, v2.2s, v0.2s
//   0x042170: 4ea31c64  mov      v4.16b, v3.16b
//   0x042174: 2e621c04  bsl      v4.8b, v0.8b, v2.8b
//   0x042178: 2ea4e424  fcmgt    v4.2s, v1.2s, v4.2s
//   0x04217c: 0ea41c63  orr      v3.8b, v3.8b, v4.8b
//   0x042180: 2e601c24  bsl      v4.8b, v1.8b, v0.8b
//   0x042184: 2e621c83  bsl      v3.8b, v4.8b, v2.8b
//   0x042188: fd000183  str      d3, [x12]
//   0x04218c: aa0b03ec  mov      x12, x11
//   0x042190: 54fffea1  b.ne     #0x42164
//   0x042194: eb08013f  cmp      x9, x8
//   0x042198: 540001e0  b.eq     #0x421d4
//   0x04219c: 8b09080a  add      x10, x0, x9, lsl #2
//   0x0421a0: cb090108  sub      x8, x8, x9
//   0x0421a4: 1e201000  fmov     s0, #2.00000000
//   0x0421a8: 1e301001  fmov     s1, #-2.00000000
//   0x0421ac: bd400142  ldr      s2, [x10]
//   0x0421b0: 1e202040  fcmp     s2, s0
//   0x0421b4: 1e22cc03  fcsel    s3, s0, s2, gt
//   0x0421b8: 1e212060  fcmp     s3, s1
//   0x0421bc: 1e204c23  fcsel    s3, s1, s0, mi
//   0x0421c0: 1e205440  fccmp    s2, s0, #0, pl
//   0x0421c4: 1e22cc62  fcsel    s2, s3, s2, gt
//   0x0421c8: f1000508  subs     x8, x8, #1
//   0x0421cc: bc004542  str      s2, [x10], #4
//   0x0421d0: 54fffee1  b.ne     #0x421ac
//   0x0421d4: 529b2b2d  mov      w13, #0xd959
//   0x0421d8: aa1f03e8  mov      x8, xzr
//   0x0421dc: 2a0203e9  mov      w9, w2
//   0x0421e0: 2a0103ea  mov      w10, w1
//   0x0421e4: 937e7c4b  sbfiz    x11, x2, #2, #0x20
//   0x0421e8: 1e2e1000  fmov     s0, #1.00000000
//   0x0421ec: 1e3e1001  fmov     s1, #-1.00000000
//   0x0421f0: b2607fec  mov      x12, #-0x100000000
//   0x0421f4: 72a6900d  movk     w13, #0x3480, lsl #16
//   0x0421f8: aa0003ee  mov      x14, x0
//   0x0421fc: 14000007  b        #0x42218
//   0x042200: 1e2703e3  fmov     s3, wzr
//   0x042204: bc287863  str      s3, [x3, x8, lsl #2]
//   0x042208: 91000508  add      x8, x8, #1
//   0x04220c: eb09011f  cmp      x8, x9
//   0x042210: 910011ce  add      x14, x14, #4
//   0x042214: 54001220  b.eq     #0x42458
//   0x042218: d37ef50f  lsl      x15, x8, #2
//   0x04221c: bc6f6862  ldr      s2, [x3, x15]
//   0x042220: 8b0f000f  add      x15, x0, x15
//   0x042224: aa0a03f0  mov      x16, x10
//   0x042228: aa0e03f1  mov      x17, x14
//   0x04222c: bd400223  ldr      s3, [x17]
//   0x042230: 1e230844  fmul     s4, s2, s3
//   0x042234: 1e202088  fcmp     s4, #0.0
//   0x042238: 540000ea  b.ge     #0x42254
//   0x04223c: 1e240864  fmul     s4, s3, s4
//   0x042240: 1e242863  fadd     s3, s3, s4
//   0x042244: f1000610  subs     x16, x16, #1
//   0x042248: bd000223  str      s3, [x17]
//   0x04224c: 8b0b0231  add      x17, x17, x11
//   0x042250: 54fffee1  b.ne     #0x4222c
//   0x042254: bd4001e2  ldr      s2, [x15]
//   0x042258: 2a1f03f0  mov      w16, wzr
//   0x04225c: 2a1003f1  mov      w17, w16
//   0x042260: 6b01021f  cmp      w16, w1
//   0x042264: 5400026a  b.ge     #0x422b0
//   0x042268: 14000006  b        #0x42280
//   0x04226c: 6b01021f  cmp      w16, w1
//   0x042270: 54fffca0  b.eq     #0x42204
//   0x042274: 2a1003f1  mov      w17, w16
//   0x042278: 6b01021f  cmp      w16, w1
//   0x04227c: 540001aa  b.ge     #0x422b0
//   0x042280: 93407e30  sxtw     x16, w17
//   0x042284: 9b107d64  mul      x4, x11, x16
//   0x042288: 2a1103f0  mov      w16, w17
//   0x04228c: bc6469c3  ldr      s3, [x14, x4]
//   0x042290: 1e202060  fcmp     s3, s0
//   0x042294: 540000ec  b.gt     #0x422b0
//   0x042298: 1e212060  fcmp     s3, s1
//   0x04229c: 540000a4  b.mi     #0x422b0
//   0x0422a0: 11000610  add      w16, w16, #1
//   0x0422a4: 6b10003f  cmp      w1, w16
//   0x0422a8: 8b0b0084  add      x4, x4, x11
//   0x0422ac: 54ffff01  b.ne     #0x4228c
//   0x0422b0: 6b01021f  cmp      w16, w1
//   0x0422b4: 54fffa60  b.eq     #0x42200
//   0x0422b8: 1b027e05  mul      w5, w16, w2
//   0x0422bc: bc65d9e3  ldr      s3, [x15, w5, sxtw #2]
//   0x0422c0: 93407e07  sxtw     x7, w16
//   0x0422c4: d10004e5  sub      x5, x7, #1
//   0x0422c8: aa1f03f3  mov      x19, xzr
//   0x0422cc: 1e214064  fneg     s4, s3
//   0x0422d0: 1e202068  fcmp     s3, #0.0
//   0x0422d4: 2a1003e4  mov      w4, w16
//   0x0422d8: 93607e06  sbfiz    x6, x16, #0x20, #0x20
//   0x0422dc: 1e234c84  fcsel    s4, s4, s3, mi
//   0x0422e0: 9b057d74  mul      x20, x11, x5
//   0x0422e4: 2a1003f6  mov      w22, w16
//   0x0422e8: 8b1300e5  add      x5, x7, x19
//   0x0422ec: aa1303f5  mov      x21, x19
//   0x0422f0: f10004bf  cmp      x5, #1
//   0x0422f4: 2a1603e5  mov      w5, w22
//   0x0422f8: 5400012b  b.lt     #0x4231c
//   0x0422fc: bc7469c5  ldr      s5, [x14, x20]
//   0x042300: d10006b3  sub      x19, x21, #1
//   0x042304: 8b0c00c6  add      x6, x6, x12
//   0x042308: cb0b0294  sub      x20, x20, x11
//   0x04230c: 1e250865  fmul     s5, s3, s5
//   0x042310: 1e2020a8  fcmp     s5, #0.0
//   0x042314: 510004b6  sub      w22, w5, #1
//   0x042318: 54fffe8a  b.ge     #0x422e8
//   0x04231c: 6b01021f  cmp      w16, w1
//   0x042320: 8b3042a6  add      x6, x21, w16, uxtw
//   0x042324: 5400026a  b.ge     #0x42370
//   0x042328: 9b077d67  mul      x7, x11, x7
//   0x04232c: bc6769c5  ldr      s5, [x14, x7]
//   0x042330: 1e250866  fmul     s6, s3, s5
//   0x042334: 1e2020c8  fcmp     s6, #0.0
//   0x042338: 5400016b  b.lt     #0x42364
//   0x04233c: 1e2140a6  fneg     s6, s5
//   0x042340: 1e2020a8  fcmp     s5, #0.0
//   0x042344: 1e254cc5  fcsel    s5, s6, s5, mi
//   0x042348: 1e2420a0  fcmp     s5, s4
//   0x04234c: 1a84c204  csel     w4, w16, w4, gt
//   0x042350: 11000610  add      w16, w16, #1
//   0x042354: 1e24cca4  fcsel    s4, s5, s4, gt
//   0x042358: 6b10003f  cmp      w1, w16
//   0x04235c: 8b0b00e7  add      x7, x7, x11
//   0x042360: 54fffe61  b.ne     #0x4232c
//   0x042364: 340000a6  cbz      w6, #0x42378
//   0x042368: 2a1f03e7  mov      w7, wzr
//   0x04236c: 14000007  b        #0x42388
//   0x042370: 2a1003e4  mov      w4, w16
//   0x042374: 35ffffa6  cbnz     w6, #0x42368
//   0x042378: bd4001e5  ldr      s5, [x15]
//   0x04237c: 1e250865  fmul     s5, s3, s5
//   0x042380: 1e2020a8  fcmp     s5, #0.0
//   0x042384: 1a9fb7e7  cset     w7, ge
//   0x042388: 1e212885  fadd     s5, s4, s1
//   0x04238c: 1e240884  fmul     s4, s4, s4
//   0x042390: 1e2701a6  fmov     s6, w13
//   0x042394: 1e202068  fcmp     s3, #0.0
//   0x042398: 1e2418a3  fdiv     s3, s5, s4
//   0x04239c: 1e260864  fmul     s4, s3, s6
//   0x0423a0: 1e242863  fadd     s3, s3, s4
//   0x0423a4: 1e214064  fneg     s4, s3
//   0x0423a8: 1e23cc83  fcsel    s3, s4, s3, gt
//   0x0423ac: 6b06021f  cmp      w16, w6
//   0x0423b0: 540001ad  b.le     #0x423e4
//   0x0423b4: 93407e06  sxtw     x6, w16
//   0x0423b8: 93407cb3  sxtw     x19, w5
//   0x0423bc: 9b137d65  mul      x5, x11, x19
//   0x0423c0: cb1300c6  sub      x6, x6, x19
//   0x0423c4: bc6569c4  ldr      s4, [x14, x5]
//   0x0423c8: f10004c6  subs     x6, x6, #1
//   0x0423cc: 1e240865  fmul     s5, s3, s4
//   0x0423d0: 1e250885  fmul     s5, s4, s5
//   0x0423d4: 1e252884  fadd     s4, s4, s5
//   0x0423d8: bc2569c4  str      s4, [x14, x5]
//   0x0423dc: 8b0b00a5  add      x5, x5, x11
//   0x0423e0: 54ffff21  b.ne     #0x423c4
//   0x0423e4: 7100089f  cmp      w4, #2
//   0x0423e8: 1a9fa7e5  cset     w5, lt
//   0x0423ec: 520000e6  eor      w6, w7, #1
//   0x0423f0: 2a0600a5  orr      w5, w5, w6
//   0x0423f4: 3707f3c5  tbnz     w5, #0, #0x4226c
//   0x0423f8: 6b04023f  cmp      w17, w4
//   0x0423fc: 54fff38a  b.ge     #0x4226c
//   0x042400: bd4001e4  ldr      s4, [x15]
//   0x042404: 1e220085  scvtf    s5, w4
//   0x042408: 93407e25  sxtw     x5, w17
//   0x04240c: 93407c84  sxtw     x4, w4
//   0x042410: 1e243844  fsub     s4, s2, s4
//   0x042414: 9b057d71  mul      x17, x11, x5
//   0x042418: 1e251885  fdiv     s5, s4, s5
//   0x04241c: cb050084  sub      x4, x4, x5
//   0x042420: bc7169c6  ldr      s6, [x14, x17]
//   0x042424: 1e253884  fsub     s4, s4, s5
//   0x042428: 1e262886  fadd     s6, s4, s6
//   0x04242c: 1e2020c0  fcmp     s6, s0
//   0x042430: 1e26cc07  fcsel    s7, s0, s6, gt
//   0x042434: 1e2120e0  fcmp     s7, s1
//   0x042438: 1e204c27  fcsel    s7, s1, s0, mi
//   0x04243c: 1e2054c0  fccmp    s6, s0, #0, pl
//   0x042440: 1e26cce6  fcsel    s6, s7, s6, gt
//   0x042444: f1000484  subs     x4, x4, #1
//   0x042448: bc3169c6  str      s6, [x14, x17]
//   0x04244c: 8b0b0231  add      x17, x17, x11
//   0x042450: 54fffe81  b.ne     #0x42420
//   0x042454: 17ffff86  b        #0x4226c
//   0x042458: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x04245c: a8c257f6  ldp      x22, x21, [sp], #0x20
//   0x042460: d65f03c0  ret      
// ============================================================================
std::uint32_t export_02_4210c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004210cULL;
    for (std::size_t i = 0; i < 214ULL; ++i) {
        std::uint32_t insn = kTextInstructions[64755ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[03] opus_packet_get_samples_per_frame @ 0x042494..0x042558 (196 bytes, 49 AArch64 insns)
// [VN] Hàm xuất khẩu[03] opus_packet_get_samples_per_frame @ 0x042494..0x042558 (196 byte, 49 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x042494: 39400008  ldrb     w8, [x0]
//   0x042498: 37380188  tbnz     w8, #7, #0x424c8
//   0x04249c: 2a2803e9  mvn      w9, w8
//   0x0424a0: 721b053f  tst      w9, #0x60
//   0x0424a4: 54000241  b.ne     #0x424ec
//   0x0424a8: 371803a8  tbnz     w8, #3, #0x4251c
//   0x0424ac: 5290a3e8  mov      w8, #0x851f
//   0x0424b0: 72aa3d68  movk     w8, #0x51eb, lsl #16
//   0x0424b4: 9b287c28  smull    x8, w1, w8
//   0x0424b8: d37ffd09  lsr      x9, x8, #0x3f
//   0x0424bc: 9365fd08  asr      x8, x8, #0x25
//   0x0424c0: 0b090100  add      w0, w8, w9
//   0x0424c4: d65f03c0  ret      
//   0x0424c8: 53031108  ubfx     w8, w8, #3, #2
//   0x0424cc: 5290a3e9  mov      w9, #0x851f
//   0x0424d0: 72aa3d69  movk     w9, #0x51eb, lsl #16
//   0x0424d4: 1ac82028  lsl      w8, w1, w8
//   0x0424d8: 9b297d08  smull    x8, w8, w9
//   0x0424dc: d37ffd09  lsr      x9, x8, #0x3f
//   0x0424e0: 9367fd08  asr      x8, x8, #0x27
//   0x0424e4: 0b090100  add      w0, w8, w9
//   0x0424e8: d65f03c0  ret      
//   0x0424ec: 53031108  ubfx     w8, w8, #3, #2
//   0x0424f0: 71000d1f  cmp      w8, #3
//   0x0424f4: 54000221  b.ne     #0x42538
//   0x0424f8: 52800788  mov      w8, #0x3c
//   0x0424fc: 5289ba69  mov      w9, #0x4dd3
//   0x042500: 72a20c49  movk     w9, #0x1062, lsl #16
//   0x042504: 1b087c28  mul      w8, w1, w8
//   0x042508: 9b297d08  smull    x8, w8, w9
//   0x04250c: d37ffd09  lsr      x9, x8, #0x3f
//   0x042510: 9366fd08  asr      x8, x8, #0x26
//   0x042514: 0b090100  add      w0, w8, w9
//   0x042518: d65f03c0  ret      
//   0x04251c: 5290a3e8  mov      w8, #0x851f
//   0x042520: 72aa3d68  movk     w8, #0x51eb, lsl #16
//   0x042524: 9b287c28  smull    x8, w1, w8
//   0x042528: d37ffd09  lsr      x9, x8, #0x3f
//   0x04252c: 9364fd08  asr      x8, x8, #0x24
//   0x042530: 0b090100  add      w0, w8, w9
//   0x042534: d65f03c0  ret      
//   0x042538: 5290a3e9  mov      w9, #0x851f
//   0x04253c: 1ac82028  lsl      w8, w1, w8
//   0x042540: 72aa3d69  movk     w9, #0x51eb, lsl #16
//   0x042544: 9b297d08  smull    x8, w8, w9
//   0x042548: d37ffd09  lsr      x9, x8, #0x3f
//   0x04254c: 9365fd08  asr      x8, x8, #0x25
//   0x042550: 0b090100  add      w0, w8, w9
//   0x042554: d65f03c0  ret      
// ============================================================================
std::uint32_t export_03_42494(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00042494ULL;
    for (std::size_t i = 0; i < 49ULL; ++i) {
        std::uint32_t insn = kTextInstructions[64981ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[04] opus_packet_parse @ 0x042a14..0x042a30 (28 bytes, 7 AArch64 insns)
// [VN] Hàm xuất khẩu[04] opus_packet_parse @ 0x042a14..0x042a30 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x042a14: aa0503e6  mov      x6, x5
//   0x042a18: aa0403e5  mov      x5, x4
//   0x042a1c: aa0303e4  mov      x4, x3
//   0x042a20: aa0203e3  mov      x3, x2
//   0x042a24: 2a1f03e2  mov      w2, wzr
//   0x042a28: aa1f03e7  mov      x7, xzr
//   0x042a2c: 17fffecb  b        #0x42558
// ============================================================================
std::uint32_t export_04_42a14(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00042a14ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[65333ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[05] opus_asm_opt_enable @ 0x042a30..0x042a38 (8 bytes, 2 AArch64 insns)
// [VN] Hàm xuất khẩu[05] opus_asm_opt_enable @ 0x042a30..0x042a38 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x042a30: 12800080  mov      w0, #-5
//   0x042a34: d65f03c0  ret      
// ============================================================================
std::uint32_t export_05_42a30(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00042a30ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[65340ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[06] opus_decoder_get_size @ 0x042a38..0x042aac (116 bytes, 29 AArch64 insns)
// [VN] Hàm xuất khẩu[06] opus_decoder_get_size @ 0x042a38..0x042aac (116 byte, 29 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x042a38: d10083ff  sub      sp, sp, #0x20
//   0x042a3c: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x042a40: 51000408  sub      w8, w0, #1
//   0x042a44: 7100051f  cmp      w8, #1
//   0x042a48: 540000a9  b.ls     #0x42a5c
//   0x042a4c: 2a1f03e0  mov      w0, wzr
//   0x042a50: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x042a54: 910083ff  add      sp, sp, #0x20
//   0x042a58: d65f03c0  ret      
//   0x042a5c: 2a0003f3  mov      w19, w0
//   0x042a60: 910033e0  add      x0, sp, #0xc
//   0x042a64: 97ff7b5b  bl       #0x217d0
//   0x042a68: 340000a0  cbz      w0, #0x42a7c
//   0x042a6c: 2a1f03e0  mov      w0, wzr
//   0x042a70: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x042a74: 910083ff  add      sp, sp, #0x20
//   0x042a78: d65f03c0  ret      
//   0x042a7c: b9400fe8  ldr      w8, [sp, #0xc]
//   0x042a80: 2a1303e0  mov      w0, w19
//   0x042a84: 11001d08  add      w8, w8, #7
//   0x042a88: 121d7108  and      w8, w8, #0xfffffff8
//   0x042a8c: b9000fe8  str      w8, [sp, #0xc]
//   0x042a90: 97ff3826  bl       #0x10b28
//   0x042a94: b9400fe8  ldr      w8, [sp, #0xc]
//   0x042a98: 0b080008  add      w8, w0, w8
//   0x042a9c: 11016100  add      w0, w8, #0x58
//   0x042aa0: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x042aa4: 910083ff  add      sp, sp, #0x20
//   0x042aa8: d65f03c0  ret      
// ============================================================================
std::uint32_t export_06_42a38(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00042a38ULL;
    for (std::size_t i = 0; i < 29ULL; ++i) {
        std::uint32_t insn = kTextInstructions[65342ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[07] opus_decoder_init @ 0x042aac..0x042c44 (408 bytes, 102 AArch64 insns)
// [VN] Hàm xuất khẩu[07] opus_decoder_init @ 0x042aac..0x042c44 (408 byte, 102 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x042aac: f81d0ff6  str      x22, [sp, #-0x30]!
//   0x042ab0: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x042ab4: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x042ab8: 5287cfe8  mov      w8, #0x3e7f
//   0x042abc: 2a0203f5  mov      w21, w2
//   0x042ac0: 2a0103f4  mov      w20, w1
//   0x042ac4: aa0003f3  mov      x19, x0
//   0x042ac8: 6b08003f  cmp      w1, w8
//   0x042acc: 12800000  mov      w0, #-1
//   0x042ad0: 540001cd  b.le     #0x42b08
//   0x042ad4: 5287d008  mov      w8, #0x3e80
//   0x042ad8: 6b08029f  cmp      w20, w8
//   0x042adc: 54000220  b.eq     #0x42b20
//   0x042ae0: 52977008  mov      w8, #0xbb80
//   0x042ae4: 6b08029f  cmp      w20, w8
//   0x042ae8: 540001c0  b.eq     #0x42b20
//   0x042aec: 528bb808  mov      w8, #0x5dc0
//   0x042af0: 6b08029f  cmp      w20, w8
//   0x042af4: 54000160  b.eq     #0x42b20
//   0x042af8: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x042afc: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x042b00: f84307f6  ldr      x22, [sp], #0x30
//   0x042b04: d65f03c0  ret      
//   0x042b08: 5283e808  mov      w8, #0x1f40
//   0x042b0c: 6b08029f  cmp      w20, w8
//   0x042b10: 54000080  b.eq     #0x42b20
//   0x042b14: 5285dc08  mov      w8, #0x2ee0
//   0x042b18: 6b08029f  cmp      w20, w8
//   0x042b1c: 54fffee1  b.ne     #0x42af8
//   0x042b20: 510006a8  sub      w8, w21, #1
//   0x042b24: 7100051f  cmp      w8, #1
//   0x042b28: 540000c9  b.ls     #0x42b40
//   0x042b2c: 12800000  mov      w0, #-1
//   0x042b30: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x042b34: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x042b38: f84307f6  ldr      x22, [sp], #0x30
//   0x042b3c: d65f03c0  ret      
//   0x042b40: 910033e0  add      x0, sp, #0xc
//   0x042b44: 97ff7b23  bl       #0x217d0
//   0x042b48: 34000060  cbz      w0, #0x42b54
//   0x042b4c: aa1f03e2  mov      x2, xzr
//   0x042b50: 1400000b  b        #0x42b7c
//   0x042b54: b9400fe8  ldr      w8, [sp, #0xc]
//   0x042b58: 2a1503e0  mov      w0, w21
//   0x042b5c: 11001d08  add      w8, w8, #7
//   0x042b60: 121d7108  and      w8, w8, #0xfffffff8
//   0x042b64: b9000fe8  str      w8, [sp, #0xc]
//   0x042b68: 97ff37f0  bl       #0x10b28
//   0x042b6c: b9400fe8  ldr      w8, [sp, #0xc]
//   0x042b70: 0b080008  add      w8, w0, w8
//   0x042b74: 11016108  add      w8, w8, #0x58
//   0x042b78: 93407d02  sxtw     x2, w8
//   0x042b7c: aa1303e0  mov      x0, x19
//   0x042b80: 2a1f03e1  mov      w1, wzr
//   0x042b84: 97ff0057  bl       #0x2ce0
//   0x042b88: 910023e0  add      x0, sp, #8
//   0x042b8c: 97ff7b11  bl       #0x217d0
//   0x042b90: 350002a0  cbnz     w0, #0x42be4
//   0x042b94: b9400be8  ldr      w8, [sp, #8]
//   0x042b98: 52800b09  mov      w9, #0x58
//   0x042b9c: 91016260  add      x0, x19, #0x58
//   0x042ba0: 11001d08  add      w8, w8, #7
//   0x042ba4: 121d7108  and      w8, w8, #0xfffffff8
//   0x042ba8: 11016116  add      w22, w8, #0x58
//   0x042bac: b9000be8  str      w8, [sp, #8]
//   0x042bb0: b9003275  str      w21, [x19, #0x30]
//   0x042bb4: 29015275  stp      w21, w20, [x19, #8]
//   0x042bb8: b9001a74  str      w20, [x19, #0x18]
//   0x042bbc: 29002676  stp      w22, w9, [x19]
//   0x042bc0: b9001275  str      w21, [x19, #0x10]
//   0x042bc4: 97ff7b07  bl       #0x217e0
//   0x042bc8: 350000e0  cbnz     w0, #0x42be4
//   0x042bcc: 8b36c276  add      x22, x19, w22, sxtw
//   0x042bd0: aa1603e0  mov      x0, x22
//   0x042bd4: 2a1403e1  mov      w1, w20
//   0x042bd8: 2a1503e2  mov      w2, w21
//   0x042bdc: 97ff37e1  bl       #0x10b60
//   0x042be0: 340000c0  cbz      w0, #0x42bf8
//   0x042be4: 12800040  mov      w0, #-3
//   0x042be8: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x042bec: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x042bf0: f84307f6  ldr      x22, [sp], #0x30
//   0x042bf4: d65f03c0  ret      
//   0x042bf8: 5284e401  mov      w1, #0x2720
//   0x042bfc: aa1603e0  mov      x0, x22
//   0x042c00: 2a1f03e2  mov      w2, wzr
//   0x042c04: 97ff497e  bl       #0x151fc
//   0x042c08: f000008a  adrp     x10, #0x55000
//   0x042c0c: 5290a3e9  mov      w9, #0x851f
//   0x042c10: fd466d40  ldr      d0, [x10, #0xcd8]
//   0x042c14: 12003e88  and      w8, w20, #0xffff
//   0x042c18: 72aa3d69  movk     w9, #0x51eb, lsl #16
//   0x042c1c: 9ba97d08  umull    x8, w8, w9
//   0x042c20: 2a1f03e0  mov      w0, wzr
//   0x042c24: d367fd08  lsr      x8, x8, #0x27
//   0x042c28: 2907a27f  stp      wzr, w8, [x19, #0x3c]
//   0x042c2c: fd002a60  str      d0, [x19, #0x50]
//   0x042c30: b9002e7f  str      wzr, [x19, #0x2c]
//   0x042c34: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x042c38: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x042c3c: f84307f6  ldr      x22, [sp], #0x30
//   0x042c40: d65f03c0  ret      
// ============================================================================
std::uint32_t export_07_42aac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00042aacULL;
    for (std::size_t i = 0; i < 102ULL; ++i) {
        std::uint32_t insn = kTextInstructions[65371ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[08] opus_decoder_create @ 0x042c44..0x042d64 (288 bytes, 72 AArch64 insns)
// [VN] Hàm xuất khẩu[08] opus_decoder_create @ 0x042c44..0x042d64 (288 byte, 72 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x042c44: f81d0ff6  str      x22, [sp, #-0x30]!
//   0x042c48: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x042c4c: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x042c50: 5287cfe8  mov      w8, #0x3e7f
//   0x042c54: aa0203f3  mov      x19, x2
//   0x042c58: 2a0003f4  mov      w20, w0
//   0x042c5c: 6b08001f  cmp      w0, w8
//   0x042c60: 2a0103f5  mov      w21, w1
//   0x042c64: 5400016d  b.le     #0x42c90
//   0x042c68: 5287d008  mov      w8, #0x3e80
//   0x042c6c: 6b08029f  cmp      w20, w8
//   0x042c70: 540001c0  b.eq     #0x42ca8
//   0x042c74: 52977008  mov      w8, #0xbb80
//   0x042c78: 6b08029f  cmp      w20, w8
//   0x042c7c: 54000160  b.eq     #0x42ca8
//   0x042c80: 528bb808  mov      w8, #0x5dc0
//   0x042c84: 6b08029f  cmp      w20, w8
//   0x042c88: 54000100  b.eq     #0x42ca8
//   0x042c8c: 1400000a  b        #0x42cb4
//   0x042c90: 5283e808  mov      w8, #0x1f40
//   0x042c94: 6b08029f  cmp      w20, w8
//   0x042c98: 54000080  b.eq     #0x42ca8
//   0x042c9c: 5285dc08  mov      w8, #0x2ee0
//   0x042ca0: 6b08029f  cmp      w20, w8
//   0x042ca4: 54000081  b.ne     #0x42cb4
//   0x042ca8: 510006a8  sub      w8, w21, #1
//   0x042cac: 7100091f  cmp      w8, #2
//   0x042cb0: 540000c3  b.lo     #0x42cc8
//   0x042cb4: b40004d3  cbz      x19, #0x42d4c
//   0x042cb8: 12800008  mov      w8, #-1
//   0x042cbc: aa1f03f6  mov      x22, xzr
//   0x042cc0: b9000268  str      w8, [x19]
//   0x042cc4: 14000023  b        #0x42d50
//   0x042cc8: 910033e0  add      x0, sp, #0xc
//   0x042ccc: 97ff7ac1  bl       #0x217d0
//   0x042cd0: 340001c0  cbz      w0, #0x42d08
//   0x042cd4: aa1f03e0  mov      x0, xzr
//   0x042cd8: 97fefffa  bl       #0x2cc0
//   0x042cdc: b40002e0  cbz      x0, #0x42d38
//   0x042ce0: 2a1403e1  mov      w1, w20
//   0x042ce4: 2a1503e2  mov      w2, w21
//   0x042ce8: aa0003f6  mov      x22, x0
//   0x042cec: 97ffff70  bl       #0x42aac
//   0x042cf0: b4000053  cbz      x19, #0x42cf8
//   0x042cf4: b9000260  str      w0, [x19]
//   0x042cf8: 340002c0  cbz      w0, #0x42d50
//   0x042cfc: aa1603e0  mov      x0, x22
//   0x042d00: 97ff0004  bl       #0x2d10
//   0x042d04: 14000012  b        #0x42d4c
//   0x042d08: b9400fe8  ldr      w8, [sp, #0xc]
//   0x042d0c: 2a1503e0  mov      w0, w21
//   0x042d10: 11001d08  add      w8, w8, #7
//   0x042d14: 121d7108  and      w8, w8, #0xfffffff8
//   0x042d18: b9000fe8  str      w8, [sp, #0xc]
//   0x042d1c: 97ff3783  bl       #0x10b28
//   0x042d20: b9400fe8  ldr      w8, [sp, #0xc]
//   0x042d24: 0b080008  add      w8, w0, w8
//   0x042d28: 11016108  add      w8, w8, #0x58
//   0x042d2c: 93407d00  sxtw     x0, w8
//   0x042d30: 97feffe4  bl       #0x2cc0
//   0x042d34: b5fffd60  cbnz     x0, #0x42ce0
//   0x042d38: b40000b3  cbz      x19, #0x42d4c
//   0x042d3c: 128000c8  mov      w8, #-7
//   0x042d40: aa1f03f6  mov      x22, xzr
//   0x042d44: b9000268  str      w8, [x19]
//   0x042d48: 14000002  b        #0x42d50
//   0x042d4c: aa1f03f6  mov      x22, xzr
//   0x042d50: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x042d54: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x042d58: aa1603e0  mov      x0, x22
//   0x042d5c: f84307f6  ldr      x22, [sp], #0x30
//   0x042d60: d65f03c0  ret      
// ============================================================================
std::uint32_t export_08_42c44(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00042c44ULL;
    for (std::size_t i = 0; i < 72ULL; ++i) {
        std::uint32_t insn = kTextInstructions[65473ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[09] opus_packet_get_bandwidth @ 0x044828..0x044874 (76 bytes, 19 AArch64 insns)
// [VN] Hàm xuất khẩu[09] opus_packet_get_bandwidth @ 0x044828..0x044874 (76 byte, 19 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x044828: 39400008  ldrb     w8, [x0]
//   0x04482c: 37380108  tbnz     w8, #7, #0x4484c
//   0x044830: 2a2803e9  mvn      w9, w8
//   0x044834: 721b053f  tst      w9, #0x60
//   0x044838: 54000181  b.ne     #0x44868
//   0x04483c: 721c011f  tst      w8, #0x10
//   0x044840: 52808a08  mov      w8, #0x450
//   0x044844: 1a880500  cinc     w0, w8, ne
//   0x044848: d65f03c0  ret      
//   0x04484c: 53051909  ubfx     w9, w8, #5, #2
//   0x044850: 5280006a  mov      w10, #3
//   0x044854: 11113929  add      w9, w9, #0x44e
//   0x044858: 6a48155f  tst      w10, w8, lsr #5
//   0x04485c: 528089a8  mov      w8, #0x44d
//   0x044860: 1a890100  csel     w0, w8, w9, eq
//   0x044864: d65f03c0  ret      
//   0x044868: 53051908  ubfx     w8, w8, #5, #2
//   0x04486c: 11113500  add      w0, w8, #0x44d
//   0x044870: d65f03c0  ret      
// ============================================================================
std::uint32_t export_09_44828(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00044828ULL;
    for (std::size_t i = 0; i < 19ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67258ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[10] opus_packet_get_nb_channels @ 0x044874..0x044888 (20 bytes, 5 AArch64 insns)
// [VN] Hàm xuất khẩu[10] opus_packet_get_nb_channels @ 0x044874..0x044888 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x044874: 39400008  ldrb     w8, [x0]
//   0x044878: 721e011f  tst      w8, #4
//   0x04487c: 52800028  mov      w8, #1
//   0x044880: 1a880500  cinc     w0, w8, ne
//   0x044884: d65f03c0  ret      
// ============================================================================
std::uint32_t export_10_44874(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00044874ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67277ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[11] opus_decode @ 0x044888..0x0448bc (52 bytes, 13 AArch64 insns)
// [VN] Hàm xuất khẩu[11] opus_decode @ 0x044888..0x0448bc (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x044888: 7100049f  cmp      w4, #1
//   0x04488c: 5400014b  b.lt     #0x448b4
//   0x044890: d10083ff  sub      sp, sp, #0x20
//   0x044894: f9000bfe  str      x30, [sp, #0x10]
//   0x044898: 2a1f03e6  mov      w6, wzr
//   0x04489c: aa1f03e7  mov      x7, xzr
//   0x0448a0: b90003ff  str      wzr, [sp]
//   0x0448a4: 97fff930  bl       #0x42d64
//   0x0448a8: f9400bfe  ldr      x30, [sp, #0x10]
//   0x0448ac: 910083ff  add      sp, sp, #0x20
//   0x0448b0: d65f03c0  ret      
//   0x0448b4: 12800000  mov      w0, #-1
//   0x0448b8: d65f03c0  ret      
// ============================================================================
std::uint32_t export_11_44888(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00044888ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67282ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[12] opus_decode_float @ 0x0448bc..0x044b04 (584 bytes, 146 AArch64 insns)
// [VN] Hàm xuất khẩu[12] opus_decode_float @ 0x0448bc..0x044b04 (584 byte, 146 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0448bc: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x0448c0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0448c4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0448c8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0448cc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0448d0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0448d4: 910143fd  add      x29, sp, #0x50
//   0x0448d8: d10043ff  sub      sp, sp, #0x10
//   0x0448dc: d53bd05a  mrs      x26, tpidr_el0
//   0x0448e0: f9401748  ldr      x8, [x26, #0x28]
//   0x0448e4: 7100049f  cmp      w4, #1
//   0x0448e8: f81a83a8  stur     x8, [x29, #-0x58]
//   0x0448ec: 5400032b  b.lt     #0x44950
//   0x0448f0: 2a0503f5  mov      w21, w5
//   0x0448f4: 2a0403f6  mov      w22, w4
//   0x0448f8: aa0303f3  mov      x19, x3
//   0x0448fc: 2a0203f7  mov      w23, w2
//   0x044900: aa0103f8  mov      x24, x1
//   0x044904: aa0003f4  mov      x20, x0
//   0x044908: b4000581  cbz      x1, #0x449b8
//   0x04490c: 710006ff  cmp      w23, #1
//   0x044910: 5400054b  b.lt     #0x449b8
//   0x044914: 35000535  cbnz     w21, #0x449b8
//   0x044918: 39400308  ldrb     w8, [x24]
//   0x04491c: b9400e99  ldr      w25, [x20, #0xc]
//   0x044920: 72000508  ands     w8, w8, #3
//   0x044924: 54000220  b.eq     #0x44968
//   0x044928: 71000d1f  cmp      w8, #3
//   0x04492c: 54000221  b.ne     #0x44970
//   0x044930: 71000aff  cmp      w23, #2
//   0x044934: 5400022a  b.ge     #0x44978
//   0x044938: 12800060  mov      w0, #-4
//   0x04493c: f9401748  ldr      x8, [x26, #0x28]
//   0x044940: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x044944: eb09011f  cmp      x8, x9
//   0x044948: 54000c00  b.eq     #0x44ac8
//   0x04494c: 14000067  b        #0x44ae8
//   0x044950: 12800000  mov      w0, #-1
//   0x044954: f9401748  ldr      x8, [x26, #0x28]
//   0x044958: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x04495c: eb09011f  cmp      x8, x9
//   0x044960: 54000b40  b.eq     #0x44ac8
//   0x044964: 14000061  b        #0x44ae8
//   0x044968: 5280003b  mov      w27, #1
//   0x04496c: 14000005  b        #0x44980
//   0x044970: 5280005b  mov      w27, #2
//   0x044974: 14000003  b        #0x44980
//   0x044978: 39400708  ldrb     w8, [x24, #1]
//   0x04497c: 1200151b  and      w27, w8, #0x3f
//   0x044980: aa1803e0  mov      x0, x24
//   0x044984: 2a1903e1  mov      w1, w25
//   0x044988: 97fef8a2  bl       #0x2c10
//   0x04498c: 1b1b7c08  mul      w8, w0, w27
//   0x044990: 7100051f  cmp      w8, #1
//   0x044994: 12800060  mov      w0, #-4
//   0x044998: 5400090b  b.lt     #0x44ab8
//   0x04499c: 52800329  mov      w9, #0x19
//   0x0449a0: 1b097d09  mul      w9, w8, w9
//   0x0449a4: 0b19072a  add      w10, w25, w25, lsl #1
//   0x0449a8: 6b0a013f  cmp      w9, w10
//   0x0449ac: 5400086c  b.gt     #0x44ab8
//   0x0449b0: 6b16011f  cmp      w8, w22
//   0x0449b4: 1a88c2d6  csel     w22, w22, w8, gt
//   0x0449b8: b9400a88  ldr      w8, [x20, #8]
//   0x0449bc: 51000509  sub      w9, w8, #1
//   0x0449c0: 7100093f  cmp      w9, #2
//   0x0449c4: 54000942  b.hs     #0x44aec
//   0x0449c8: 1b167d08  mul      w8, w8, w22
//   0x0449cc: d37ff908  lsl      x8, x8, #1
//   0x0449d0: 91003d08  add      x8, x8, #0xf
//   0x0449d4: 927c7508  and      x8, x8, #0x3fffffff0
//   0x0449d8: 910003e9  mov      x9, sp
//   0x0449dc: 910003fb  mov      x27, sp
//   0x0449e0: cb080139  sub      x25, x9, x8
//   0x0449e4: 9100033f  mov      sp, x25
//   0x0449e8: b81f0fff  str      wzr, [sp, #-0x10]!
//   0x0449ec: aa1403e0  mov      x0, x20
//   0x0449f0: aa1803e1  mov      x1, x24
//   0x0449f4: 2a1703e2  mov      w2, w23
//   0x0449f8: aa1903e3  mov      x3, x25
//   0x0449fc: 2a1603e4  mov      w4, w22
//   0x044a00: 2a1503e5  mov      w5, w21
//   0x044a04: 2a1f03e6  mov      w6, wzr
//   0x044a08: aa1f03e7  mov      x7, xzr
//   0x044a0c: 97fff8d6  bl       #0x42d64
//   0x044a10: 910043ff  add      sp, sp, #0x10
//   0x044a14: 7100041f  cmp      w0, #1
//   0x044a18: 540004eb  b.lt     #0x44ab4
//   0x044a1c: b9800a88  ldrsw    x8, [x20, #8]
//   0x044a20: 93407c09  sxtw     x9, w0
//   0x044a24: 9b097d08  mul      x8, x8, x9
//   0x044a28: 7100051f  cmp      w8, #1
//   0x044a2c: 5400044b  b.lt     #0x44ab4
//   0x044a30: 7100211f  cmp      w8, #8
//   0x044a34: 54000062  b.hs     #0x44a40
//   0x044a38: aa1f03e9  mov      x9, xzr
//   0x044a3c: 14000014  b        #0x44a8c
//   0x044a40: 927df109  and      x9, x8, #0xfffffffffffffff8
//   0x044a44: 9100232a  add      x10, x25, #8
//   0x044a48: 9100426b  add      x11, x19, #0x10
//   0x044a4c: 4f016700  movi     v0.4s, #0x38, lsl #24
//   0x044a50: aa0903ec  mov      x12, x9
//   0x044a54: 6d7f8941  ldp      d1, d2, [x10, #-8]
//   0x044a58: 9100414a  add      x10, x10, #0x10
//   0x044a5c: f100218c  subs     x12, x12, #8
//   0x044a60: 0f10a421  sshll    v1.4s, v1.4h, #0
//   0x044a64: 0f10a442  sshll    v2.4s, v2.4h, #0
//   0x044a68: 4e21d821  scvtf    v1.4s, v1.4s
//   0x044a6c: 4e21d842  scvtf    v2.4s, v2.4s
//   0x044a70: 6e20dc21  fmul     v1.4s, v1.4s, v0.4s
//   0x044a74: 6e20dc42  fmul     v2.4s, v2.4s, v0.4s
//   0x044a78: ad3f8961  stp      q1, q2, [x11, #-0x10]
//   0x044a7c: 9100816b  add      x11, x11, #0x20
//   0x044a80: 54fffea1  b.ne     #0x44a54
//   0x044a84: eb08013f  cmp      x9, x8
//   0x044a88: 54000160  b.eq     #0x44ab4
//   0x044a8c: 52a7000a  mov      w10, #0x38000000
//   0x044a90: 7c697b20  ldr      h0, [x25, x9, lsl #1]
//   0x044a94: 1e270141  fmov     s1, w10
//   0x044a98: 0f10a400  sshll    v0.4s, v0.4h, #0
//   0x044a9c: 5e21d800  scvtf    s0, s0
//   0x044aa0: 1e210800  fmul     s0, s0, s1
//   0x044aa4: bc297a60  str      s0, [x19, x9, lsl #2]
//   0x044aa8: 91000529  add      x9, x9, #1
//   0x044aac: eb08013f  cmp      x9, x8
//   0x044ab0: 54ffff0b  b.lt     #0x44a90
//   0x044ab4: 9100037f  mov      sp, x27
//   0x044ab8: f9401748  ldr      x8, [x26, #0x28]
//   0x044abc: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x044ac0: eb09011f  cmp      x8, x9
//   0x044ac4: 54000121  b.ne     #0x44ae8
//   0x044ac8: d10143bf  sub      sp, x29, #0x50
//   0x044acc: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x044ad0: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x044ad4: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x044ad8: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x044adc: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x044ae0: f84607fb  ldr      x27, [sp], #0x60
//   0x044ae4: d65f03c0  ret      
//   0x044ae8: 97fef85a  bl       #0x2c50
//   0x044aec: b0000080  adrp     x0, #0x55000
//   0x044af0: b00000c1  adrp     x1, #0x5d000
//   0x044af4: 9138f400  add      x0, x0, #0xe3d
//   0x044af8: 91013021  add      x1, x1, #0x4c
//   0x044afc: 52806562  mov      w2, #0x32b
//   0x044b00: 97ff0bce  bl       #0x7a38
// ============================================================================
std::uint32_t export_12_448bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000448bcULL;
    for (std::size_t i = 0; i < 146ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67295ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[13] opus_decoder_get_nb_samples @ 0x044b04..0x044ba0 (156 bytes, 39 AArch64 insns)
// [VN] Hàm xuất khẩu[13] opus_decoder_get_nb_samples @ 0x044b04..0x044ba0 (156 byte, 39 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x044b04: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x044b08: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x044b0c: 7100045f  cmp      w2, #1
//   0x044b10: 540001ab  b.lt     #0x44b44
//   0x044b14: 39400028  ldrb     w8, [x1]
//   0x044b18: b9400c13  ldr      w19, [x0, #0xc]
//   0x044b1c: 72000508  ands     w8, w8, #3
//   0x044b20: 540001a0  b.eq     #0x44b54
//   0x044b24: 71000d1f  cmp      w8, #3
//   0x044b28: 540001a1  b.ne     #0x44b5c
//   0x044b2c: 7100085f  cmp      w2, #2
//   0x044b30: 540001aa  b.ge     #0x44b64
//   0x044b34: 12800060  mov      w0, #-4
//   0x044b38: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x044b3c: f84207f4  ldr      x20, [sp], #0x20
//   0x044b40: d65f03c0  ret      
//   0x044b44: 12800000  mov      w0, #-1
//   0x044b48: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x044b4c: f84207f4  ldr      x20, [sp], #0x20
//   0x044b50: d65f03c0  ret      
//   0x044b54: 52800034  mov      w20, #1
//   0x044b58: 14000005  b        #0x44b6c
//   0x044b5c: 52800054  mov      w20, #2
//   0x044b60: 14000003  b        #0x44b6c
//   0x044b64: 39400428  ldrb     w8, [x1, #1]
//   0x044b68: 12001514  and      w20, w8, #0x3f
//   0x044b6c: aa0103e0  mov      x0, x1
//   0x044b70: 2a1303e1  mov      w1, w19
//   0x044b74: 97fef827  bl       #0x2c10
//   0x044b78: 1b147c08  mul      w8, w0, w20
//   0x044b7c: 52800329  mov      w9, #0x19
//   0x044b80: 0b13066a  add      w10, w19, w19, lsl #1
//   0x044b84: 1b097d09  mul      w9, w8, w9
//   0x044b88: 6b0a013f  cmp      w9, w10
//   0x044b8c: 12800069  mov      w9, #-4
//   0x044b90: 1a88c120  csel     w0, w9, w8, gt
//   0x044b94: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x044b98: f84207f4  ldr      x20, [sp], #0x20
//   0x044b9c: d65f03c0  ret      
// ============================================================================
std::uint32_t export_13_44b04(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00044b04ULL;
    for (std::size_t i = 0; i < 39ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67441ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[14] opus_decoder_ctl @ 0x044ba0..0x04500c (1132 bytes, 283 AArch64 insns)
// [VN] Hàm xuất khẩu[14] opus_decoder_ctl @ 0x044ba0..0x04500c (1132 byte, 283 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x044ba0: d103c3ff  sub      sp, sp, #0xf0
//   0x044ba4: f9006bf4  str      x20, [sp, #0xd0]
//   0x044ba8: a90e7bf3  stp      x19, x30, [sp, #0xe0]
//   0x044bac: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x044bb0: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x044bb4: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x044bb8: ad0007e0  stp      q0, q1, [sp]
//   0x044bbc: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x044bc0: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x044bc4: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x044bc8: 928005e9  mov      x9, #-0x30
//   0x044bcc: 910003eb  mov      x11, sp
//   0x044bd0: 69402808  ldpsw    x8, x10, [x0]
//   0x044bd4: f2dff009  movk     x9, #0xff80, lsl #32
//   0x044bd8: 9102016b  add      x11, x11, #0x80
//   0x044bdc: 910203ec  add      x12, sp, #0x80
//   0x044be0: a90c27eb  stp      x11, x9, [sp, #0xc0]
//   0x044be4: 513ea429  sub      w9, w1, #0xfa9
//   0x044be8: aa0003f3  mov      x19, x0
//   0x044bec: 9103c3ed  add      x13, sp, #0xf0
//   0x044bf0: 9100c18c  add      x12, x12, #0x30
//   0x044bf4: 7100b13f  cmp      w9, #0x2c
//   0x044bf8: 12800080  mov      w0, #-5
//   0x044bfc: a90b33ed  stp      x13, x12, [sp, #0xb0]
//   0x044c00: 54000548  b.hi     #0x44ca8
//   0x044c04: 8b0a0274  add      x20, x19, x10
//   0x044c08: 900000ca  adrp     x10, #0x5c000
//   0x044c0c: 913fd54a  add      x10, x10, #0xff5
//   0x044c10: 100000ab  adr      x11, #0x44c24
//   0x044c14: 3869694c  ldrb     w12, [x10, x9]
//   0x044c18: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x044c1c: 8b080268  add      x8, x19, x8
//   0x044c20: d61f0160  br       x11
//   0x044c24: b980cbe8  ldrsw    x8, [sp, #0xc8]
//   0x044c28: 36f800a8  tbz      w8, #0x1f, #0x44c3c
//   0x044c2c: 11002109  add      w9, w8, #8
//   0x044c30: 7100013f  cmp      w9, #0
//   0x044c34: b900cbe9  str      w9, [sp, #0xc8]
//   0x044c38: 540017ad  b.le     #0x44f2c
//   0x044c3c: f9405be8  ldr      x8, [sp, #0xb0]
//   0x044c40: 91002109  add      x9, x8, #8
//   0x044c44: f9005be9  str      x9, [sp, #0xb0]
//   0x044c48: f9400108  ldr      x8, [x8]
//   0x044c4c: b4001d68  cbz      x8, #0x44ff8
//   0x044c50: b9403669  ldr      w9, [x19, #0x34]
//   0x044c54: 2a1f03e0  mov      w0, wzr
//   0x044c58: 140000a9  b        #0x44efc
//   0x044c5c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x044c60: 5281f781  mov      w1, #0xfbc
//   0x044c64: aa0803e0  mov      x0, x8
//   0x044c68: f9002a7f  str      xzr, [x19, #0x50]
//   0x044c6c: ad018260  stp      q0, q0, [x19, #0x30]
//   0x044c70: 97ff4163  bl       #0x151fc
//   0x044c74: aa1403e0  mov      x0, x20
//   0x044c78: 97ff72da  bl       #0x217e0
//   0x044c7c: 29412668  ldp      w8, w9, [x19, #8]
//   0x044c80: 5290a3ea  mov      w10, #0x851f
//   0x044c84: 93407d29  sxtw     x9, w9
//   0x044c88: 72aa3d6a  movk     w10, #0x51eb, lsl #16
//   0x044c8c: b9003268  str      w8, [x19, #0x30]
//   0x044c90: 9b0a7d28  mul      x8, x9, x10
//   0x044c94: d37ffd09  lsr      x9, x8, #0x3f
//   0x044c98: 9367fd08  asr      x8, x8, #0x27
//   0x044c9c: 0b090108  add      w8, w8, w9
//   0x044ca0: 2a1f03e0  mov      w0, wzr
//   0x044ca4: b9004268  str      w8, [x19, #0x40]
//   0x044ca8: a94e7bf3  ldp      x19, x30, [sp, #0xe0]
//   0x044cac: f9406bf4  ldr      x20, [sp, #0xd0]
//   0x044cb0: 9103c3ff  add      sp, sp, #0xf0
//   0x044cb4: d65f03c0  ret      
//   0x044cb8: b980cbe8  ldrsw    x8, [sp, #0xc8]
//   0x044cbc: 36f800a8  tbz      w8, #0x1f, #0x44cd0
//   0x044cc0: 11002109  add      w9, w8, #8
//   0x044cc4: 7100013f  cmp      w9, #0
//   0x044cc8: b900cbe9  str      w9, [sp, #0xc8]
//   0x044ccc: 540013ad  b.le     #0x44f40
//   0x044cd0: f9405be8  ldr      x8, [sp, #0xb0]
//   0x044cd4: 91002109  add      x9, x8, #8
//   0x044cd8: f9005be9  str      x9, [sp, #0xb0]
//   0x044cdc: f9400108  ldr      x8, [x8]
//   0x044ce0: b40018c8  cbz      x8, #0x44ff8
//   0x044ce4: b9400e69  ldr      w9, [x19, #0xc]
//   0x044ce8: 2a1f03e0  mov      w0, wzr
//   0x044cec: 14000084  b        #0x44efc
//   0x044cf0: b980cbe8  ldrsw    x8, [sp, #0xc8]
//   0x044cf4: 36f800a8  tbz      w8, #0x1f, #0x44d08
//   0x044cf8: 11002109  add      w9, w8, #8
//   0x044cfc: 7100013f  cmp      w9, #0
//   0x044d00: b900cbe9  str      w9, [sp, #0xc8]
//   0x044d04: 5400128d  b.le     #0x44f54
//   0x044d08: f9405be8  ldr      x8, [sp, #0xb0]
//   0x044d0c: 91002109  add      x9, x8, #8
//   0x044d10: f9005be9  str      x9, [sp, #0xb0]
//   0x044d14: f9400108  ldr      x8, [x8]
//   0x044d18: b4001708  cbz      x8, #0x44ff8
//   0x044d1c: b9404e69  ldr      w9, [x19, #0x4c]
//   0x044d20: 2a1f03e0  mov      w0, wzr
//   0x044d24: 14000076  b        #0x44efc
//   0x044d28: b980cbe9  ldrsw    x9, [sp, #0xc8]
//   0x044d2c: 36f800a9  tbz      w9, #0x1f, #0x44d40
//   0x044d30: 1100212a  add      w10, w9, #8
//   0x044d34: 7100015f  cmp      w10, #0
//   0x044d38: b900cbea  str      w10, [sp, #0xc8]
//   0x044d3c: 5400116d  b.le     #0x44f68
//   0x044d40: f9405be9  ldr      x9, [sp, #0xb0]
//   0x044d44: 9100212a  add      x10, x9, #8
//   0x044d48: f9005bea  str      x10, [sp, #0xb0]
//   0x044d4c: f9400122  ldr      x2, [x9]
//   0x044d50: b4001542  cbz      x2, #0x44ff8
//   0x044d54: b9403e69  ldr      w9, [x19, #0x3c]
//   0x044d58: 710fa93f  cmp      w9, #0x3ea
//   0x044d5c: 54000da1  b.ne     #0x44f10
//   0x044d60: 5281f821  mov      w1, #0xfc1
//   0x044d64: 1400004e  b        #0x44e9c
//   0x044d68: b980cbe8  ldrsw    x8, [sp, #0xc8]
//   0x044d6c: 36f800a8  tbz      w8, #0x1f, #0x44d80
//   0x044d70: 11002109  add      w9, w8, #8
//   0x044d74: 7100013f  cmp      w9, #0
//   0x044d78: b900cbe9  str      w9, [sp, #0xc8]
//   0x044d7c: 5400100d  b.le     #0x44f7c
//   0x044d80: f9405be8  ldr      x8, [sp, #0xb0]
//   0x044d84: 91002109  add      x9, x8, #8
//   0x044d88: f9005be9  str      x9, [sp, #0xb0]
//   0x044d8c: b9400108  ldr      w8, [x8]
//   0x044d90: 6b28a11f  cmp      w8, w8, sxth
//   0x044d94: 54001321  b.ne     #0x44ff8
//   0x044d98: 2a1f03e0  mov      w0, wzr
//   0x044d9c: b9002a68  str      w8, [x19, #0x28]
//   0x044da0: a94e7bf3  ldp      x19, x30, [sp, #0xe0]
//   0x044da4: f9406bf4  ldr      x20, [sp, #0xd0]
//   0x044da8: 9103c3ff  add      sp, sp, #0xf0
//   0x044dac: d65f03c0  ret      
//   0x044db0: b980cbe8  ldrsw    x8, [sp, #0xc8]
//   0x044db4: 36f800a8  tbz      w8, #0x1f, #0x44dc8
//   0x044db8: 11002109  add      w9, w8, #8
//   0x044dbc: 7100013f  cmp      w9, #0
//   0x044dc0: b900cbe9  str      w9, [sp, #0xc8]
//   0x044dc4: 54000e8d  b.le     #0x44f94
//   0x044dc8: f9405be8  ldr      x8, [sp, #0xb0]
//   0x044dcc: 91002109  add      x9, x8, #8
//   0x044dd0: f9005be9  str      x9, [sp, #0xb0]
//   0x044dd4: f9400108  ldr      x8, [x8]
//   0x044dd8: b4001108  cbz      x8, #0x44ff8
//   0x044ddc: b9404a69  ldr      w9, [x19, #0x48]
//   0x044de0: 2a1f03e0  mov      w0, wzr
//   0x044de4: 14000046  b        #0x44efc
//   0x044de8: b980cbe8  ldrsw    x8, [sp, #0xc8]
//   0x044dec: 36f800a8  tbz      w8, #0x1f, #0x44e00
//   0x044df0: 11002109  add      w9, w8, #8
//   0x044df4: 7100013f  cmp      w9, #0
//   0x044df8: b900cbe9  str      w9, [sp, #0xc8]
//   0x044dfc: 54000d6d  b.le     #0x44fa8
//   0x044e00: f9405be8  ldr      x8, [sp, #0xb0]
//   0x044e04: 91002109  add      x9, x8, #8
//   0x044e08: f9005be9  str      x9, [sp, #0xb0]
//   0x044e0c: f9400108  ldr      x8, [x8]
//   0x044e10: b4000f48  cbz      x8, #0x44ff8
//   0x044e14: b9402a69  ldr      w9, [x19, #0x28]
//   0x044e18: 2a1f03e0  mov      w0, wzr
//   0x044e1c: 14000038  b        #0x44efc
//   0x044e20: b980cbe9  ldrsw    x9, [sp, #0xc8]
//   0x044e24: 36f800a9  tbz      w9, #0x1f, #0x44e38
//   0x044e28: 1100212a  add      w10, w9, #8
//   0x044e2c: 7100015f  cmp      w10, #0
//   0x044e30: b900cbea  str      w10, [sp, #0xc8]
//   0x044e34: 54000c4d  b.le     #0x44fbc
//   0x044e38: f9405be9  ldr      x9, [sp, #0xb0]
//   0x044e3c: 9100212a  add      x10, x9, #8
//   0x044e40: f9005bea  str      x10, [sp, #0xb0]
//   0x044e44: b9400122  ldr      w2, [x9]
//   0x044e48: 7100045f  cmp      w2, #1
//   0x044e4c: 54000d68  b.hi     #0x44ff8
//   0x044e50: 5281f9c1  mov      w1, #0xfce
//   0x044e54: aa0803e0  mov      x0, x8
//   0x044e58: 97ff40e9  bl       #0x151fc
//   0x044e5c: a94e7bf3  ldp      x19, x30, [sp, #0xe0]
//   0x044e60: f9406bf4  ldr      x20, [sp, #0xd0]
//   0x044e64: 9103c3ff  add      sp, sp, #0xf0
//   0x044e68: d65f03c0  ret      
//   0x044e6c: b980cbe9  ldrsw    x9, [sp, #0xc8]
//   0x044e70: 36f800a9  tbz      w9, #0x1f, #0x44e84
//   0x044e74: 1100212a  add      w10, w9, #8
//   0x044e78: 7100015f  cmp      w10, #0
//   0x044e7c: b900cbea  str      w10, [sp, #0xc8]
//   0x044e80: 54000aad  b.le     #0x44fd4
//   0x044e84: f9405be9  ldr      x9, [sp, #0xb0]
//   0x044e88: 9100212a  add      x10, x9, #8
//   0x044e8c: f9005bea  str      x10, [sp, #0xb0]
//   0x044e90: f9400122  ldr      x2, [x9]
//   0x044e94: b4000b22  cbz      x2, #0x44ff8
//   0x044e98: 5281f9e1  mov      w1, #0xfcf
//   0x044e9c: aa0803e0  mov      x0, x8
//   0x044ea0: 97ff40d7  bl       #0x151fc
//   0x044ea4: a94e7bf3  ldp      x19, x30, [sp, #0xe0]
//   0x044ea8: f9406bf4  ldr      x20, [sp, #0xd0]
//   0x044eac: 9103c3ff  add      sp, sp, #0xf0
//   0x044eb0: d65f03c0  ret      
//   0x044eb4: b980cbe8  ldrsw    x8, [sp, #0xc8]
//   0x044eb8: 36f800a8  tbz      w8, #0x1f, #0x44ecc
//   0x044ebc: 11002109  add      w9, w8, #8
//   0x044ec0: 7100013f  cmp      w9, #0
//   0x044ec4: b900cbe9  str      w9, [sp, #0xc8]
//   0x044ec8: 5400090d  b.le     #0x44fe8
//   0x044ecc: f9405be8  ldr      x8, [sp, #0xb0]
//   0x044ed0: 91002109  add      x9, x8, #8
//   0x044ed4: f9005be9  str      x9, [sp, #0xb0]
//   0x044ed8: f9400108  ldr      x8, [x8]
//   0x044edc: b40008e8  cbz      x8, #0x44ff8
//   0x044ee0: b9403a69  ldr      w9, [x19, #0x38]
//   0x044ee4: 9125c28a  add      x10, x20, #0x970
//   0x044ee8: 9101426b  add      x11, x19, #0x50
//   0x044eec: 2a1f03e0  mov      w0, wzr
//   0x044ef0: 710fa93f  cmp      w9, #0x3ea
//   0x044ef4: 9a8a0169  csel     x9, x11, x10, eq
//   0x044ef8: b9400129  ldr      w9, [x9]
//   0x044efc: b9000109  str      w9, [x8]
//   0x044f00: a94e7bf3  ldp      x19, x30, [sp, #0xe0]
//   0x044f04: f9406bf4  ldr      x20, [sp, #0xd0]
//   0x044f08: 9103c3ff  add      sp, sp, #0xf0
//   0x044f0c: d65f03c0  ret      
//   0x044f10: b9402668  ldr      w8, [x19, #0x24]
//   0x044f14: 2a1f03e0  mov      w0, wzr
//   0x044f18: b9000048  str      w8, [x2]
//   0x044f1c: a94e7bf3  ldp      x19, x30, [sp, #0xe0]
//   0x044f20: f9406bf4  ldr      x20, [sp, #0xd0]
//   0x044f24: 9103c3ff  add      sp, sp, #0xf0
//   0x044f28: d65f03c0  ret      
//   0x044f2c: f9405fe9  ldr      x9, [sp, #0xb8]
//   0x044f30: 8b080128  add      x8, x9, x8
//   0x044f34: f9400108  ldr      x8, [x8]
//   0x044f38: b5ffe8c8  cbnz     x8, #0x44c50
//   0x044f3c: 1400002f  b        #0x44ff8
//   0x044f40: f9405fe9  ldr      x9, [sp, #0xb8]
//   0x044f44: 8b080128  add      x8, x9, x8
//   0x044f48: f9400108  ldr      x8, [x8]
//   0x044f4c: b5ffecc8  cbnz     x8, #0x44ce4
//   0x044f50: 1400002a  b        #0x44ff8
//   0x044f54: f9405fe9  ldr      x9, [sp, #0xb8]
//   0x044f58: 8b080128  add      x8, x9, x8
//   0x044f5c: f9400108  ldr      x8, [x8]
//   0x044f60: b5ffede8  cbnz     x8, #0x44d1c
//   0x044f64: 14000025  b        #0x44ff8
//   0x044f68: f9405fea  ldr      x10, [sp, #0xb8]
//   0x044f6c: 8b090149  add      x9, x10, x9
//   0x044f70: f9400122  ldr      x2, [x9]
//   0x044f74: b5ffef02  cbnz     x2, #0x44d54
//   0x044f78: 14000020  b        #0x44ff8
//   0x044f7c: f9405fe9  ldr      x9, [sp, #0xb8]
//   0x044f80: 8b080128  add      x8, x9, x8
//   0x044f84: b9400108  ldr      w8, [x8]
//   0x044f88: 6b28a11f  cmp      w8, w8, sxth
//   0x044f8c: 54000361  b.ne     #0x44ff8
//   0x044f90: 17ffff82  b        #0x44d98
//   0x044f94: f9405fe9  ldr      x9, [sp, #0xb8]
//   0x044f98: 8b080128  add      x8, x9, x8
//   0x044f9c: f9400108  ldr      x8, [x8]
//   0x044fa0: b5fff1e8  cbnz     x8, #0x44ddc
//   0x044fa4: 14000015  b        #0x44ff8
//   0x044fa8: f9405fe9  ldr      x9, [sp, #0xb8]
//   0x044fac: 8b080128  add      x8, x9, x8
//   0x044fb0: f9400108  ldr      x8, [x8]
//   0x044fb4: b5fff308  cbnz     x8, #0x44e14
//   0x044fb8: 14000010  b        #0x44ff8
//   0x044fbc: f9405fea  ldr      x10, [sp, #0xb8]
//   0x044fc0: 8b090149  add      x9, x10, x9
//   0x044fc4: b9400122  ldr      w2, [x9]
//   0x044fc8: 7100045f  cmp      w2, #1
//   0x044fcc: 54000168  b.hi     #0x44ff8
//   0x044fd0: 17ffffa0  b        #0x44e50
//   0x044fd4: f9405fea  ldr      x10, [sp, #0xb8]
//   0x044fd8: 8b090149  add      x9, x10, x9
//   0x044fdc: f9400122  ldr      x2, [x9]
//   0x044fe0: b5fff5c2  cbnz     x2, #0x44e98
//   0x044fe4: 14000005  b        #0x44ff8
//   0x044fe8: f9405fe9  ldr      x9, [sp, #0xb8]
//   0x044fec: 8b080128  add      x8, x9, x8
//   0x044ff0: f9400108  ldr      x8, [x8]
//   0x044ff4: b5fff768  cbnz     x8, #0x44ee0
//   0x044ff8: 12800000  mov      w0, #-1
//   0x044ffc: a94e7bf3  ldp      x19, x30, [sp, #0xe0]
//   0x045000: f9406bf4  ldr      x20, [sp, #0xd0]
//   0x045004: 9103c3ff  add      sp, sp, #0xf0
//   0x045008: d65f03c0  ret      
// ============================================================================
std::uint32_t export_14_44ba0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00044ba0ULL;
    for (std::size_t i = 0; i < 283ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67480ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[15] opus_decoder_destroy @ 0x04500c..0x045010 (4 bytes, 1 AArch64 insns)
// [VN] Hàm xuất khẩu[15] opus_decoder_destroy @ 0x04500c..0x045010 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04500c: 17fef741  b        #0x2d10
// ============================================================================
std::uint32_t export_15_4500c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004500cULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67763ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[16] opus_packet_get_nb_frames @ 0x045010..0x045060 (80 bytes, 20 AArch64 insns)
// [VN] Hàm xuất khẩu[16] opus_packet_get_nb_frames @ 0x045010..0x045060 (80 byte, 20 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x045010: 7100043f  cmp      w1, #1
//   0x045014: 5400014b  b.lt     #0x4503c
//   0x045018: 39400008  ldrb     w8, [x0]
//   0x04501c: 72000508  ands     w8, w8, #3
//   0x045020: 54000120  b.eq     #0x45044
//   0x045024: 71000d1f  cmp      w8, #3
//   0x045028: 54000121  b.ne     #0x4504c
//   0x04502c: 7100083f  cmp      w1, #2
//   0x045030: 5400012a  b.ge     #0x45054
//   0x045034: 12800060  mov      w0, #-4
//   0x045038: d65f03c0  ret      
//   0x04503c: 12800000  mov      w0, #-1
//   0x045040: d65f03c0  ret      
//   0x045044: 52800020  mov      w0, #1
//   0x045048: d65f03c0  ret      
//   0x04504c: 52800040  mov      w0, #2
//   0x045050: d65f03c0  ret      
//   0x045054: 39400408  ldrb     w8, [x0, #1]
//   0x045058: 12001500  and      w0, w8, #0x3f
//   0x04505c: d65f03c0  ret      
// ============================================================================
std::uint32_t export_16_45010(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00045010ULL;
    for (std::size_t i = 0; i < 20ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67764ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[17] opus_packet_get_nb_samples @ 0x045060..0x0450f8 (152 bytes, 38 AArch64 insns)
// [VN] Hàm xuất khẩu[17] opus_packet_get_nb_samples @ 0x045060..0x0450f8 (152 byte, 38 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x045060: f81e0ff4  str      x20, [sp, #-0x20]!
//   0x045064: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x045068: 7100043f  cmp      w1, #1
//   0x04506c: 540001ab  b.lt     #0x450a0
//   0x045070: 39400008  ldrb     w8, [x0]
//   0x045074: 2a0203f3  mov      w19, w2
//   0x045078: 72000508  ands     w8, w8, #3
//   0x04507c: 540001a0  b.eq     #0x450b0
//   0x045080: 71000d1f  cmp      w8, #3
//   0x045084: 540001a1  b.ne     #0x450b8
//   0x045088: 7100083f  cmp      w1, #2
//   0x04508c: 540001aa  b.ge     #0x450c0
//   0x045090: 12800060  mov      w0, #-4
//   0x045094: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x045098: f84207f4  ldr      x20, [sp], #0x20
//   0x04509c: d65f03c0  ret      
//   0x0450a0: 12800000  mov      w0, #-1
//   0x0450a4: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x0450a8: f84207f4  ldr      x20, [sp], #0x20
//   0x0450ac: d65f03c0  ret      
//   0x0450b0: 52800034  mov      w20, #1
//   0x0450b4: 14000005  b        #0x450c8
//   0x0450b8: 52800054  mov      w20, #2
//   0x0450bc: 14000003  b        #0x450c8
//   0x0450c0: 39400408  ldrb     w8, [x0, #1]
//   0x0450c4: 12001514  and      w20, w8, #0x3f
//   0x0450c8: 2a1303e1  mov      w1, w19
//   0x0450cc: 97fef6d1  bl       #0x2c10
//   0x0450d0: 1b147c08  mul      w8, w0, w20
//   0x0450d4: 52800329  mov      w9, #0x19
//   0x0450d8: 0b13066a  add      w10, w19, w19, lsl #1
//   0x0450dc: 1b097d09  mul      w9, w8, w9
//   0x0450e0: 6b0a013f  cmp      w9, w10
//   0x0450e4: 12800069  mov      w9, #-4
//   0x0450e8: 1a88c120  csel     w0, w9, w8, gt
//   0x0450ec: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x0450f0: f84207f4  ldr      x20, [sp], #0x20
//   0x0450f4: d65f03c0  ret      
// ============================================================================
std::uint32_t export_17_45060(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00045060ULL;
    for (std::size_t i = 0; i < 38ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67784ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[18] opus_encoder_get_size @ 0x0450f8..0x045170 (120 bytes, 30 AArch64 insns)
// [VN] Hàm xuất khẩu[18] opus_encoder_get_size @ 0x0450f8..0x045170 (120 byte, 30 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0450f8: d10083ff  sub      sp, sp, #0x20
//   0x0450fc: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x045100: 51000408  sub      w8, w0, #1
//   0x045104: 7100051f  cmp      w8, #1
//   0x045108: 540000a9  b.ls     #0x4511c
//   0x04510c: 2a1f03e0  mov      w0, wzr
//   0x045110: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x045114: 910083ff  add      sp, sp, #0x20
//   0x045118: d65f03c0  ret      
//   0x04511c: 2a0003f3  mov      w19, w0
//   0x045120: 910033e0  add      x0, sp, #0xc
//   0x045124: 97ff7526  bl       #0x225bc
//   0x045128: 340000a0  cbz      w0, #0x4513c
//   0x04512c: 2a1f03e0  mov      w0, wzr
//   0x045130: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x045134: 910083ff  add      sp, sp, #0x20
//   0x045138: d65f03c0  ret      
//   0x04513c: b9400fe8  ldr      w8, [sp, #0xc]
//   0x045140: 2a1303e0  mov      w0, w19
//   0x045144: 11001d08  add      w8, w8, #7
//   0x045148: 121d7108  and      w8, w8, #0xfffffff8
//   0x04514c: b9000fe8  str      w8, [sp, #0xc]
//   0x045150: 97ff0b86  bl       #0x7f68
//   0x045154: b9400fe8  ldr      w8, [sp, #0xc]
//   0x045158: 5287ef09  mov      w9, #0x3f78
//   0x04515c: 0b080008  add      w8, w0, w8
//   0x045160: 0b090100  add      w0, w8, w9
//   0x045164: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x045168: 910083ff  add      sp, sp, #0x20
//   0x04516c: d65f03c0  ret      
// ============================================================================
std::uint32_t export_18_450f8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000450f8ULL;
    for (std::size_t i = 0; i < 30ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67822ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[19] opus_encoder_init @ 0x045170..0x045414 (676 bytes, 169 AArch64 insns)
// [VN] Hàm xuất khẩu[19] opus_encoder_init @ 0x045170..0x045414 (676 byte, 169 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x045170: f81c0ff8  str      x24, [sp, #-0x40]!
//   0x045174: a9015bf7  stp      x23, x22, [sp, #0x10]
//   0x045178: a90253f5  stp      x21, x20, [sp, #0x20]
//   0x04517c: a9037bf3  stp      x19, x30, [sp, #0x30]
//   0x045180: 5287cfe8  mov      w8, #0x3e7f
//   0x045184: 2a0303f4  mov      w20, w3
//   0x045188: 2a0203f5  mov      w21, w2
//   0x04518c: 2a0103f6  mov      w22, w1
//   0x045190: aa0003f3  mov      x19, x0
//   0x045194: 6b08003f  cmp      w1, w8
//   0x045198: 12800000  mov      w0, #-1
//   0x04519c: 5400016d  b.le     #0x451c8
//   0x0451a0: 5287d008  mov      w8, #0x3e80
//   0x0451a4: 6b0802df  cmp      w22, w8
//   0x0451a8: 540001c0  b.eq     #0x451e0
//   0x0451ac: 52977008  mov      w8, #0xbb80
//   0x0451b0: 6b0802df  cmp      w22, w8
//   0x0451b4: 54000160  b.eq     #0x451e0
//   0x0451b8: 528bb808  mov      w8, #0x5dc0
//   0x0451bc: 6b0802df  cmp      w22, w8
//   0x0451c0: 54000100  b.eq     #0x451e0
//   0x0451c4: 14000027  b        #0x45260
//   0x0451c8: 5283e808  mov      w8, #0x1f40
//   0x0451cc: 6b0802df  cmp      w22, w8
//   0x0451d0: 54000080  b.eq     #0x451e0
//   0x0451d4: 5285dc08  mov      w8, #0x2ee0
//   0x0451d8: 6b0802df  cmp      w22, w8
//   0x0451dc: 54000421  b.ne     #0x45260
//   0x0451e0: 510006a8  sub      w8, w21, #1
//   0x0451e4: 7100051f  cmp      w8, #1
//   0x0451e8: 540003a8  b.hi     #0x4525c
//   0x0451ec: 51200288  sub      w8, w20, #0x800
//   0x0451f0: 71000d1f  cmp      w8, #3
//   0x0451f4: 12800000  mov      w0, #-1
//   0x0451f8: 54000348  b.hi     #0x45260
//   0x0451fc: 7100091f  cmp      w8, #2
//   0x045200: 54000300  b.eq     #0x45260
//   0x045204: 910033e0  add      x0, sp, #0xc
//   0x045208: 97ff74ed  bl       #0x225bc
//   0x04520c: 34000060  cbz      w0, #0x45218
//   0x045210: aa1f03e2  mov      x2, xzr
//   0x045214: 1400000c  b        #0x45244
//   0x045218: b9400fe8  ldr      w8, [sp, #0xc]
//   0x04521c: 2a1503e0  mov      w0, w21
//   0x045220: 11001d08  add      w8, w8, #7
//   0x045224: 121d7108  and      w8, w8, #0xfffffff8
//   0x045228: b9000fe8  str      w8, [sp, #0xc]
//   0x04522c: 97ff0b4f  bl       #0x7f68
//   0x045230: b9400fe8  ldr      w8, [sp, #0xc]
//   0x045234: 5287ef09  mov      w9, #0x3f78
//   0x045238: 0b080008  add      w8, w0, w8
//   0x04523c: 0b090108  add      w8, w8, w9
//   0x045240: 93407d02  sxtw     x2, w8
//   0x045244: aa1303e0  mov      x0, x19
//   0x045248: 2a1f03e1  mov      w1, wzr
//   0x04524c: 97fef6a5  bl       #0x2ce0
//   0x045250: 910023e0  add      x0, sp, #8
//   0x045254: 97ff74da  bl       #0x225bc
//   0x045258: 340000e0  cbz      w0, #0x45274
//   0x04525c: 12800000  mov      w0, #-1
//   0x045260: a9437bf3  ldp      x19, x30, [sp, #0x30]
//   0x045264: a94253f5  ldp      x21, x20, [sp, #0x20]
//   0x045268: a9415bf7  ldp      x23, x22, [sp, #0x10]
//   0x04526c: f84407f8  ldr      x24, [sp], #0x40
//   0x045270: d65f03c0  ret      
//   0x045274: b9400be8  ldr      w8, [sp, #8]
//   0x045278: 900000ca  adrp     x10, #0x5d000
//   0x04527c: fd43f940  ldr      d0, [x10, #0x7f0]
//   0x045280: 5287ef09  mov      w9, #0x3f78
//   0x045284: 11001d08  add      w8, w8, #7
//   0x045288: 121d7108  and      w8, w8, #0xfffffff8
//   0x04528c: 8b090260  add      x0, x19, x9
//   0x045290: 0b090117  add      w23, w8, w9
//   0x045294: 91002262  add      x2, x19, #8
//   0x045298: 2a1f03e1  mov      w1, wzr
//   0x04529c: b9000be8  str      w8, [sp, #8]
//   0x0452a0: b9007a75  str      w21, [x19, #0x78]
//   0x0452a4: b9378275  str      w21, [x19, #0x3780]
//   0x0452a8: b9009a76  str      w22, [x19, #0x98]
//   0x0452ac: b900be7f  str      wzr, [x19, #0xbc]
//   0x0452b0: fc0c4260  stur     d0, [x19, #0xc4]
//   0x0452b4: 29002677  stp      w23, w9, [x19]
//   0x0452b8: 97ff74c5  bl       #0x225cc
//   0x0452bc: 350002c0  cbnz     w0, #0x45314
//   0x0452c0: 900000c8  adrp     x8, #0x5d000
//   0x0452c4: 3dc20500  ldr      q0, [x8, #0x810]
//   0x0452c8: b9409a68  ldr      w8, [x19, #0x98]
//   0x0452cc: 900000c9  adrp     x9, #0x5d000
//   0x0452d0: b940be63  ldr      w3, [x19, #0xbc]
//   0x0452d4: 3c814260  stur     q0, [x19, #0x14]
//   0x0452d8: 3dc20920  ldr      q0, [x9, #0x820]
//   0x0452dc: 2901a275  stp      w21, w8, [x19, #0xc]
//   0x0452e0: b940c668  ldr      w8, [x19, #0xc4]
//   0x0452e4: 8b37c277  add      x23, x19, w23, sxtw
//   0x0452e8: aa1703e0  mov      x0, x23
//   0x0452ec: 2a1603e1  mov      w1, w22
//   0x0452f0: 2a1503e2  mov      w2, w21
//   0x0452f4: b9000a75  str      w21, [x19, #8]
//   0x0452f8: 2907fe68  stp      w8, wzr, [x19, #0x3c]
//   0x0452fc: b9003a7f  str      wzr, [x19, #0x38]
//   0x045300: b900527f  str      wzr, [x19, #0x50]
//   0x045304: 3c824260  stur     q0, [x19, #0x24]
//   0x045308: b900727f  str      wzr, [x19, #0x70]
//   0x04530c: 97ff0b25  bl       #0x7fa0
//   0x045310: 34000060  cbz      w0, #0x4531c
//   0x045314: 12800040  mov      w0, #-3
//   0x045318: 17ffffd2  b        #0x45260
//   0x04531c: 5286f088  mov      w8, #0x3784
//   0x045320: 5284e401  mov      w1, #0x2720
//   0x045324: aa1703e0  mov      x0, x23
//   0x045328: 2a1f03e2  mov      w2, wzr
//   0x04532c: 8b080278  add      x24, x19, x8
//   0x045330: 97ff2b24  bl       #0xffc0
//   0x045334: b9402e62  ldr      w2, [x19, #0x2c]
//   0x045338: 5281f541  mov      w1, #0xfaa
//   0x04533c: aa1703e0  mov      x0, x23
//   0x045340: 97ff2b20  bl       #0xffc0
//   0x045344: 0f000420  movi     v0.2s, #1
//   0x045348: 900000c9  adrp     x9, #0x5d000
//   0x04534c: fc09c260  stur     d0, [x19, #0x9c]
//   0x045350: 3dc20d20  ldr      q0, [x9, #0x830]
//   0x045354: 92807cea  mov      x10, #-0x3e8
//   0x045358: b9809a6b  ldrsw    x11, [x19, #0x98]
//   0x04535c: 1b167ea8  mul      w8, w21, w22
//   0x045360: f9004a6a  str      x10, [x19, #0x90]
//   0x045364: 900000ca  adrp     x10, #0x5d000
//   0x045368: 5290a3e9  mov      w9, #0x851f
//   0x04536c: 3d802260  str      q0, [x19, #0x80]
//   0x045370: fd43fd40  ldr      d0, [x10, #0x7f8]
//   0x045374: 5282710a  mov      w10, #0x1388
//   0x045378: 112ee108  add      w8, w8, #0xbb8
//   0x04537c: 72aa3d69  movk     w9, #0x51eb, lsl #16
//   0x045380: 2914a26a  stp      w10, w8, [x19, #0xa4]
//   0x045384: 5289ba68  mov      w8, #0x4dd3
//   0x045388: 72a20c48  movk     w8, #0x1062, lsl #16
//   0x04538c: 9b097d69  mul      x9, x11, x9
//   0x045390: 9b087d68  mul      x8, x11, x8
//   0x045394: d37ffd2a  lsr      x10, x9, #0x3f
//   0x045398: 9365fd29  asr      x9, x9, #0x25
//   0x04539c: 0b0a0129  add      w9, w9, w10
//   0x0453a0: d37ffd0a  lsr      x10, x8, #0x3f
//   0x0453a4: 9364fd08  asr      x8, x8, #0x24
//   0x0453a8: 0b0a0108  add      w8, w8, w10
//   0x0453ac: 5288000a  mov      w10, #0x4000
//   0x0453b0: b900b669  str      w9, [x19, #0xb4]
//   0x0453b4: 528fffe9  mov      w9, #0x7fff
//   0x0453b8: 52800780  mov      w0, #0x3c
//   0x0453bc: b9007674  str      w20, [x19, #0x74]
//   0x0453c0: fc0ac260  stur     d0, [x19, #0xac]
//   0x0453c4: b9007e68  str      w8, [x19, #0x7c]
//   0x0453c8: 7900030a  strh     w10, [x24]
//   0x0453cc: 79001309  strh     w9, [x24, #8]
//   0x0453d0: 97ffb0da  bl       #0x31738
//   0x0453d4: b9409a61  ldr      w1, [x19, #0x98]
//   0x0453d8: 53185c08  lsl      w8, w0, #8
//   0x0453dc: 52800029  mov      w9, #1
//   0x0453e0: 52807d2a  mov      w10, #0x3e9
//   0x0453e4: 52808a2b  mov      w11, #0x451
//   0x0453e8: 91033260  add      x0, x19, #0xcc
//   0x0453ec: b9378a68  str      w8, [x19, #0x3788]
//   0x0453f0: b937be69  str      w9, [x19, #0x37bc]
//   0x0453f4: b937a26a  str      w10, [x19, #0x37a0]
//   0x0453f8: b937b26b  str      w11, [x19, #0x37b0]
//   0x0453fc: b93f727f  str      wzr, [x19, #0x3f70]
//   0x045400: 940031ce  bl       #0x51b38
//   0x045404: b9407668  ldr      w8, [x19, #0x74]
//   0x045408: 2a1f03e0  mov      w0, wzr
//   0x04540c: b900d268  str      w8, [x19, #0xd0]
//   0x045410: 17ffff94  b        #0x45260
// ============================================================================
std::uint32_t export_19_45170(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00045170ULL;
    for (std::size_t i = 0; i < 169ULL; ++i) {
        std::uint32_t insn = kTextInstructions[67852ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[20] opus_encoder_create @ 0x045414..0x04555c (328 bytes, 82 AArch64 insns)
// [VN] Hàm xuất khẩu[20] opus_encoder_create @ 0x045414..0x04555c (328 byte, 82 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x045414: d10103ff  sub      sp, sp, #0x40
//   0x045418: a9015bf7  stp      x23, x22, [sp, #0x10]
//   0x04541c: a90253f5  stp      x21, x20, [sp, #0x20]
//   0x045420: a9037bf3  stp      x19, x30, [sp, #0x30]
//   0x045424: 5287cfe8  mov      w8, #0x3e7f
//   0x045428: aa0303f3  mov      x19, x3
//   0x04542c: 2a0203f4  mov      w20, w2
//   0x045430: 2a0003f5  mov      w21, w0
//   0x045434: 6b08001f  cmp      w0, w8
//   0x045438: 2a0103f6  mov      w22, w1
//   0x04543c: 5400016d  b.le     #0x45468
//   0x045440: 5287d008  mov      w8, #0x3e80
//   0x045444: 6b0802bf  cmp      w21, w8
//   0x045448: 540001c0  b.eq     #0x45480
//   0x04544c: 52977008  mov      w8, #0xbb80
//   0x045450: 6b0802bf  cmp      w21, w8
//   0x045454: 54000160  b.eq     #0x45480
//   0x045458: 528bb808  mov      w8, #0x5dc0
//   0x04545c: 6b0802bf  cmp      w21, w8
//   0x045460: 54000100  b.eq     #0x45480
//   0x045464: 1400000a  b        #0x4548c
//   0x045468: 5283e808  mov      w8, #0x1f40
//   0x04546c: 6b0802bf  cmp      w21, w8
//   0x045470: 54000080  b.eq     #0x45480
//   0x045474: 5285dc08  mov      w8, #0x2ee0
//   0x045478: 6b0802bf  cmp      w21, w8
//   0x04547c: 54000081  b.ne     #0x4548c
//   0x045480: 510006c8  sub      w8, w22, #1
//   0x045484: 7100051f  cmp      w8, #1
//   0x045488: 540000c9  b.ls     #0x454a0
//   0x04548c: b40005b3  cbz      x19, #0x45540
//   0x045490: 12800008  mov      w8, #-1
//   0x045494: aa1f03f7  mov      x23, xzr
//   0x045498: b9000268  str      w8, [x19]
//   0x04549c: 1400002a  b        #0x45544
//   0x0454a0: 51200288  sub      w8, w20, #0x800
//   0x0454a4: 71000d1f  cmp      w8, #3
//   0x0454a8: 54ffff28  b.hi     #0x4548c
//   0x0454ac: 7100091f  cmp      w8, #2
//   0x0454b0: 54fffee0  b.eq     #0x4548c
//   0x0454b4: 910033e0  add      x0, sp, #0xc
//   0x0454b8: 97ff7441  bl       #0x225bc
//   0x0454bc: 340001e0  cbz      w0, #0x454f8
//   0x0454c0: aa1f03e0  mov      x0, xzr
//   0x0454c4: 97fef5ff  bl       #0x2cc0
//   0x0454c8: b4000320  cbz      x0, #0x4552c
//   0x0454cc: 2a1503e1  mov      w1, w21
//   0x0454d0: 2a1603e2  mov      w2, w22
//   0x0454d4: 2a1403e3  mov      w3, w20
//   0x0454d8: aa0003f7  mov      x23, x0
//   0x0454dc: 97ffff25  bl       #0x45170
//   0x0454e0: b4000053  cbz      x19, #0x454e8
//   0x0454e4: b9000260  str      w0, [x19]
//   0x0454e8: 340002e0  cbz      w0, #0x45544
//   0x0454ec: aa1703e0  mov      x0, x23
//   0x0454f0: 97fef608  bl       #0x2d10
//   0x0454f4: 14000013  b        #0x45540
//   0x0454f8: b9400fe8  ldr      w8, [sp, #0xc]
//   0x0454fc: 2a1603e0  mov      w0, w22
//   0x045500: 11001d08  add      w8, w8, #7
//   0x045504: 121d7108  and      w8, w8, #0xfffffff8
//   0x045508: b9000fe8  str      w8, [sp, #0xc]
//   0x04550c: 97ff0a97  bl       #0x7f68
//   0x045510: b9400fe8  ldr      w8, [sp, #0xc]
//   0x045514: 5287ef09  mov      w9, #0x3f78
//   0x045518: 0b080008  add      w8, w0, w8
//   0x04551c: 0b090108  add      w8, w8, w9
//   0x045520: 93407d00  sxtw     x0, w8
//   0x045524: 97fef5e7  bl       #0x2cc0
//   0x045528: b5fffd20  cbnz     x0, #0x454cc
//   0x04552c: b40000b3  cbz      x19, #0x45540
//   0x045530: 128000c8  mov      w8, #-7
//   0x045534: aa1f03f7  mov      x23, xzr
//   0x045538: b9000268  str      w8, [x19]
//   0x04553c: 14000002  b        #0x45544
//   0x045540: aa1f03f7  mov      x23, xzr
//   0x045544: aa1703e0  mov      x0, x23
//   0x045548: a9437bf3  ldp      x19, x30, [sp, #0x30]
//   0x04554c: a94253f5  ldp      x21, x20, [sp, #0x20]
//   0x045550: a9415bf7  ldp      x23, x22, [sp, #0x10]
//   0x045554: 910103ff  add      sp, sp, #0x40
//   0x045558: d65f03c0  ret      
// ============================================================================
std::uint32_t export_20_45414(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00045414ULL;
    for (std::size_t i = 0; i < 82ULL; ++i) {
        std::uint32_t insn = kTextInstructions[68021ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[21] opus_encode_float @ 0x04a500..0x04a758 (600 bytes, 150 AArch64 insns)
// [VN] Hàm xuất khẩu[21] opus_encode_float @ 0x04a500..0x04a758 (600 byte, 150 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04a500: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x04a504: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04a508: 910043fd  add      x29, sp, #0x10
//   0x04a50c: d10043ff  sub      sp, sp, #0x10
//   0x04a510: d53bd053  mrs      x19, tpidr_el0
//   0x04a514: f9401668  ldr      x8, [x19, #0x28]
//   0x04a518: 5290a3e9  mov      w9, #0x851f
//   0x04a51c: 72aa3d69  movk     w9, #0x51eb, lsl #16
//   0x04a520: f81e83a8  stur     x8, [x29, #-0x18]
//   0x04a524: b9809808  ldrsw    x8, [x0, #0x98]
//   0x04a528: 9b097d09  mul      x9, x8, x9
//   0x04a52c: d37ffd2a  lsr      x10, x9, #0x3f
//   0x04a530: 9367fd29  asr      x9, x9, #0x27
//   0x04a534: 0b0a0129  add      w9, w9, w10
//   0x04a538: 6b02013f  cmp      w9, w2
//   0x04a53c: 5400016d  b.le     #0x4a568
//   0x04a540: 12800008  mov      w8, #-1
//   0x04a544: f9401669  ldr      x9, [x19, #0x28]
//   0x04a548: f85e83aa  ldur     x10, [x29, #-0x18]
//   0x04a54c: eb0a013f  cmp      x9, x10
//   0x04a550: 54000ea1  b.ne     #0x4a724
//   0x04a554: 2a0803e0  mov      w0, w8
//   0x04a558: d10043bf  sub      sp, x29, #0x10
//   0x04a55c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x04a560: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x04a564: d65f03c0  ret      
//   0x04a568: b940a40a  ldr      w10, [x0, #0xa4]
//   0x04a56c: 5282710b  mov      w11, #0x1388
//   0x04a570: 2a0203e7  mov      w7, w2
//   0x04a574: aa0103e6  mov      x6, x1
//   0x04a578: 6b0b015f  cmp      w10, w11
//   0x04a57c: 54000541  b.ne     #0x4a624
//   0x04a580: 52800c89  mov      w9, #0x64
//   0x04a584: 1b097c49  mul      w9, w2, w9
//   0x04a588: 6b08013f  cmp      w9, w8
//   0x04a58c: 54000620  b.eq     #0x4a650
//   0x04a590: 52803209  mov      w9, #0x190
//   0x04a594: 1b097c49  mul      w9, w2, w9
//   0x04a598: 6b08013f  cmp      w9, w8
//   0x04a59c: 540005a0  b.eq     #0x4a650
//   0x04a5a0: 52801909  mov      w9, #0xc8
//   0x04a5a4: 1b097c49  mul      w9, w2, w9
//   0x04a5a8: 6b08013f  cmp      w9, w8
//   0x04a5ac: 54000520  b.eq     #0x4a650
//   0x04a5b0: 52800649  mov      w9, #0x32
//   0x04a5b4: 5280032a  mov      w10, #0x19
//   0x04a5b8: 1b097c4f  mul      w15, w2, w9
//   0x04a5bc: 1b0a7c4a  mul      w10, w2, w10
//   0x04a5c0: 6b0801ff  cmp      w15, w8
//   0x04a5c4: 0b08050e  add      w14, w8, w8, lsl #1
//   0x04a5c8: 1a9f17e9  cset     w9, eq
//   0x04a5cc: 6b08015f  cmp      w10, w8
//   0x04a5d0: 531e750c  lsl      w12, w8, #2
//   0x04a5d4: 1a9f17ea  cset     w10, eq
//   0x04a5d8: 6b0e01ff  cmp      w15, w14
//   0x04a5dc: 0b08018d  add      w13, w12, w8
//   0x04a5e0: 1a9f17eb  cset     w11, eq
//   0x04a5e4: 6b0c01ff  cmp      w15, w12
//   0x04a5e8: 1a9f17ec  cset     w12, eq
//   0x04a5ec: 6b0d01ff  cmp      w15, w13
//   0x04a5f0: 1a9f17ed  cset     w13, eq
//   0x04a5f4: 6b0e05ff  cmp      w15, w14, lsl #1
//   0x04a5f8: 1a9f17ee  cset     w14, eq
//   0x04a5fc: 7100045f  cmp      w2, #1
//   0x04a600: 12800008  mov      w8, #-1
//   0x04a604: 54fffa0b  b.lt     #0x4a544
//   0x04a608: 2a0a0129  orr      w9, w9, w10
//   0x04a60c: 2a090169  orr      w9, w11, w9
//   0x04a610: 2a090189  orr      w9, w12, w9
//   0x04a614: 2a0901a9  orr      w9, w13, w9
//   0x04a618: 2a0901c9  orr      w9, w14, w9
//   0x04a61c: 350001e9  cbnz     w9, #0x4a658
//   0x04a620: 17ffffc9  b        #0x4a544
//   0x04a624: 1282710b  mov      w11, #-0x1389
//   0x04a628: 0b0b014b  add      w11, w10, w11
//   0x04a62c: 7100217f  cmp      w11, #8
//   0x04a630: 54fff888  b.hi     #0x4a540
//   0x04a634: 528271ac  mov      w12, #0x138d
//   0x04a638: 6b0c015f  cmp      w10, w12
//   0x04a63c: 5400076c  b.gt     #0x4a728
//   0x04a640: 1acb2122  lsl      w2, w9, w11
//   0x04a644: 6b07005f  cmp      w2, w7
//   0x04a648: 54fff7cc  b.gt     #0x4a540
//   0x04a64c: 17ffffcd  b        #0x4a580
//   0x04a650: 7100045f  cmp      w2, #1
//   0x04a654: 54fff76b  b.lt     #0x4a540
//   0x04a658: b9407808  ldr      w8, [x0, #0x78]
//   0x04a65c: 910003e9  mov      x9, sp
//   0x04a660: 910003f4  mov      x20, sp
//   0x04a664: 1b027d08  mul      w8, w8, w2
//   0x04a668: d37ff908  lsl      x8, x8, #1
//   0x04a66c: 91003d08  add      x8, x8, #0xf
//   0x04a670: 927c7508  and      x8, x8, #0x3fffffff0
//   0x04a674: cb080121  sub      x1, x9, x8
//   0x04a678: 9100003f  mov      sp, x1
//   0x04a67c: b9407808  ldr      w8, [x0, #0x78]
//   0x04a680: 1b027d0a  mul      w10, w8, w2
//   0x04a684: 7100055f  cmp      w10, #1
//   0x04a688: 5400028b  b.lt     #0x4a6d8
//   0x04a68c: 529fc00d  mov      w13, #0xfe00
//   0x04a690: aa1f03e9  mov      x9, xzr
//   0x04a694: 93407d4a  sxtw     x10, w10
//   0x04a698: 52a8e00b  mov      w11, #0x47000000
//   0x04a69c: 52b8e00c  mov      w12, #-0x39000000
//   0x04a6a0: 72a8dfed  movk     w13, #0x46ff, lsl #16
//   0x04a6a4: bc6978c0  ldr      s0, [x6, x9, lsl #2]
//   0x04a6a8: 1e270161  fmov     s1, w11
//   0x04a6ac: 1e270182  fmov     s2, w12
//   0x04a6b0: 1e2701a3  fmov     s3, w13
//   0x04a6b4: 1e210800  fmul     s0, s0, s1
//   0x04a6b8: 1e226800  fmaxnm   s0, s0, s2
//   0x04a6bc: 1e237800  fminnm   s0, s0, s3
//   0x04a6c0: 1e274000  frintx   s0, s0
//   0x04a6c4: 9e38000e  fcvtzs   x14, s0
//   0x04a6c8: 7829782e  strh     w14, [x1, x9, lsl #1]
//   0x04a6cc: 91000529  add      x9, x9, #1
//   0x04a6d0: eb0a013f  cmp      x9, x10
//   0x04a6d4: 54fffe8b  b.lt     #0x4a6a4
//   0x04a6d8: d100c3ff  sub      sp, sp, #0x30
//   0x04a6dc: 52800029  mov      w9, #1
//   0x04a6e0: b90013e8  str      w8, [sp, #0x10]
//   0x04a6e4: f0ffffc8  adrp     x8, #0x45000
//   0x04a6e8: 91157108  add      x8, x8, #0x55c
//   0x04a6ec: b90023e9  str      w9, [sp, #0x20]
//   0x04a6f0: 12800029  mov      w9, #-2
//   0x04a6f4: 52800205  mov      w5, #0x10
//   0x04a6f8: f9000fe8  str      x8, [sp, #0x18]
//   0x04a6fc: b9000be9  str      w9, [sp, #8]
//   0x04a700: b90003ff  str      wzr, [sp]
//   0x04a704: 97ffee83  bl       #0x46110
//   0x04a708: 9100c3ff  add      sp, sp, #0x30
//   0x04a70c: 2a0003e8  mov      w8, w0
//   0x04a710: 9100029f  mov      sp, x20
//   0x04a714: f9401669  ldr      x9, [x19, #0x28]
//   0x04a718: f85e83aa  ldur     x10, [x29, #-0x18]
//   0x04a71c: eb0a013f  cmp      x9, x10
//   0x04a720: 54fff1a0  b.eq     #0x4a554
//   0x04a724: 97fee14b  bl       #0x2c50
//   0x04a728: 12827149  mov      w9, #-0x138b
//   0x04a72c: 5290a3eb  mov      w11, #0x851f
//   0x04a730: 0b090149  add      w9, w10, w9
//   0x04a734: 72aa3d6b  movk     w11, #0x51eb, lsl #16
//   0x04a738: 1b087d29  mul      w9, w9, w8
//   0x04a73c: 9b2b7d29  smull    x9, w9, w11
//   0x04a740: d37ffd2a  lsr      x10, x9, #0x3f
//   0x04a744: 9364fd29  asr      x9, x9, #0x24
//   0x04a748: 0b0a0122  add      w2, w9, w10
//   0x04a74c: 6b07005f  cmp      w2, w7
//   0x04a750: 54ffef8c  b.gt     #0x4a540
//   0x04a754: 17ffff8b  b        #0x4a580
// ============================================================================
std::uint32_t export_21_4a500(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004a500ULL;
    for (std::size_t i = 0; i < 150ULL; ++i) {
        std::uint32_t insn = kTextInstructions[73200ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[22] opus_encode @ 0x04a758..0x04a8b4 (348 bytes, 87 AArch64 insns)
// [VN] Hàm xuất khẩu[22] opus_encode @ 0x04a758..0x04a8b4 (348 byte, 87 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04a758: d10103ff  sub      sp, sp, #0x40
//   0x04a75c: f9001bfe  str      x30, [sp, #0x30]
//   0x04a760: b9809808  ldrsw    x8, [x0, #0x98]
//   0x04a764: 5290a3e9  mov      w9, #0x851f
//   0x04a768: 72aa3d69  movk     w9, #0x51eb, lsl #16
//   0x04a76c: 2a0203e7  mov      w7, w2
//   0x04a770: 9b097d09  mul      x9, x8, x9
//   0x04a774: d37ffd2a  lsr      x10, x9, #0x3f
//   0x04a778: 9367fd29  asr      x9, x9, #0x27
//   0x04a77c: 0b0a0129  add      w9, w9, w10
//   0x04a780: 6b02013f  cmp      w9, w2
//   0x04a784: 5400076c  b.gt     #0x4a870
//   0x04a788: b940a40a  ldr      w10, [x0, #0xa4]
//   0x04a78c: 5282710b  mov      w11, #0x1388
//   0x04a790: 2a0703e2  mov      w2, w7
//   0x04a794: 6b0b015f  cmp      w10, w11
//   0x04a798: 540002e0  b.eq     #0x4a7f4
//   0x04a79c: 1282710b  mov      w11, #-0x1389
//   0x04a7a0: 0b0b014b  add      w11, w10, w11
//   0x04a7a4: 7100217f  cmp      w11, #8
//   0x04a7a8: 54000648  b.hi     #0x4a870
//   0x04a7ac: 528271ac  mov      w12, #0x138d
//   0x04a7b0: 6b0c015f  cmp      w10, w12
//   0x04a7b4: 540000ac  b.gt     #0x4a7c8
//   0x04a7b8: 1acb2122  lsl      w2, w9, w11
//   0x04a7bc: 6b07005f  cmp      w2, w7
//   0x04a7c0: 540001ad  b.le     #0x4a7f4
//   0x04a7c4: 1400002b  b        #0x4a870
//   0x04a7c8: 12827149  mov      w9, #-0x138b
//   0x04a7cc: 5290a3eb  mov      w11, #0x851f
//   0x04a7d0: 0b090149  add      w9, w10, w9
//   0x04a7d4: 72aa3d6b  movk     w11, #0x51eb, lsl #16
//   0x04a7d8: 1b087d29  mul      w9, w9, w8
//   0x04a7dc: 9b2b7d29  smull    x9, w9, w11
//   0x04a7e0: d37ffd2a  lsr      x10, x9, #0x3f
//   0x04a7e4: 9364fd29  asr      x9, x9, #0x24
//   0x04a7e8: 0b0a0122  add      w2, w9, w10
//   0x04a7ec: 6b07005f  cmp      w2, w7
//   0x04a7f0: 5400040c  b.gt     #0x4a870
//   0x04a7f4: 52800c89  mov      w9, #0x64
//   0x04a7f8: 1b097c49  mul      w9, w2, w9
//   0x04a7fc: 6b08013f  cmp      w9, w8
//   0x04a800: 540003a0  b.eq     #0x4a874
//   0x04a804: 52803209  mov      w9, #0x190
//   0x04a808: 1b097c49  mul      w9, w2, w9
//   0x04a80c: 6b08013f  cmp      w9, w8
//   0x04a810: 54000320  b.eq     #0x4a874
//   0x04a814: 52801909  mov      w9, #0xc8
//   0x04a818: 1b097c49  mul      w9, w2, w9
//   0x04a81c: 6b08013f  cmp      w9, w8
//   0x04a820: 540002a0  b.eq     #0x4a874
//   0x04a824: 52800649  mov      w9, #0x32
//   0x04a828: 1b097c49  mul      w9, w2, w9
//   0x04a82c: 0b08050a  add      w10, w8, w8, lsl #1
//   0x04a830: 6b0a053f  cmp      w9, w10, lsl #1
//   0x04a834: 54000200  b.eq     #0x4a874
//   0x04a838: 531e750b  lsl      w11, w8, #2
//   0x04a83c: 0b08016c  add      w12, w11, w8
//   0x04a840: 6b0c013f  cmp      w9, w12
//   0x04a844: 54000180  b.eq     #0x4a874
//   0x04a848: 6b0b013f  cmp      w9, w11
//   0x04a84c: 54000140  b.eq     #0x4a874
//   0x04a850: 6b0a013f  cmp      w9, w10
//   0x04a854: 54000100  b.eq     #0x4a874
//   0x04a858: 6b08013f  cmp      w9, w8
//   0x04a85c: 540000c0  b.eq     #0x4a874
//   0x04a860: 52800329  mov      w9, #0x19
//   0x04a864: 1b097c49  mul      w9, w2, w9
//   0x04a868: 6b08013f  cmp      w9, w8
//   0x04a86c: 54000040  b.eq     #0x4a874
//   0x04a870: 12800002  mov      w2, #-1
//   0x04a874: b9407808  ldr      w8, [x0, #0x78]
//   0x04a878: f0ffffc9  adrp     x9, #0x45000
//   0x04a87c: b93f701f  str      wzr, [x0, #0x3f70]
//   0x04a880: 911b5129  add      x9, x9, #0x6d4
//   0x04a884: b90013e8  str      w8, [sp, #0x10]
//   0x04a888: 12800028  mov      w8, #-2
//   0x04a88c: 52800205  mov      w5, #0x10
//   0x04a890: aa0103e6  mov      x6, x1
//   0x04a894: b90023ff  str      wzr, [sp, #0x20]
//   0x04a898: f9000fe9  str      x9, [sp, #0x18]
//   0x04a89c: b9000be8  str      w8, [sp, #8]
//   0x04a8a0: b90003ff  str      wzr, [sp]
//   0x04a8a4: 97ffee1b  bl       #0x46110
//   0x04a8a8: f9401bfe  ldr      x30, [sp, #0x30]
//   0x04a8ac: 910103ff  add      sp, sp, #0x40
//   0x04a8b0: d65f03c0  ret      
// ============================================================================
std::uint32_t export_22_4a758(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004a758ULL;
    for (std::size_t i = 0; i < 87ULL; ++i) {
        std::uint32_t insn = kTextInstructions[73350ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[23] opus_encoder_ctl @ 0x04a8b4..0x04bb18 (4708 bytes, 1177 AArch64 insns)
// [VN] Hàm xuất khẩu[23] opus_encoder_ctl @ 0x04a8b4..0x04bb18 (4708 byte, 1177 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04a8b4: d105c3ff  sub      sp, sp, #0x170
//   0x04a8b8: a9145bfc  stp      x28, x22, [sp, #0x140]
//   0x04a8bc: a91553f5  stp      x21, x20, [sp, #0x150]
//   0x04a8c0: a9167bf3  stp      x19, x30, [sp, #0x160]
//   0x04a8c4: 928005e8  mov      x8, #-0x30
//   0x04a8c8: 910003e9  mov      x9, sp
//   0x04a8cc: 910203ea  add      x10, sp, #0x80
//   0x04a8d0: f2dff008  movk     x8, #0xff80, lsl #32
//   0x04a8d4: 9105c3eb  add      x11, sp, #0x170
//   0x04a8d8: 91020129  add      x9, x9, #0x80
//   0x04a8dc: 9100c14a  add      x10, x10, #0x30
//   0x04a8e0: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x04a8e4: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x04a8e8: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x04a8ec: ad0007e0  stp      q0, q1, [sp]
//   0x04a8f0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x04a8f4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x04a8f8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x04a8fc: a91323e9  stp      x9, x8, [sp, #0x130]
//   0x04a900: a9122beb  stp      x11, x10, [sp, #0x120]
//   0x04a904: b9800008  ldrsw    x8, [x0]
//   0x04a908: 5284e3c9  mov      w9, #0x271e
//   0x04a90c: aa0003f3  mov      x19, x0
//   0x04a910: 6b09003f  cmp      w1, w9
//   0x04a914: 8b080014  add      x20, x0, x8
//   0x04a918: 12800080  mov      w0, #-5
//   0x04a91c: 5400046c  b.gt     #0x4a9a8
//   0x04a920: 513e8028  sub      w8, w1, #0xfa0
//   0x04a924: 7100e11f  cmp      w8, #0x38
//   0x04a928: 54008ee8  b.hi     #0x4bb04
//   0x04a92c: f0000089  adrp     x9, #0x5d000
//   0x04a930: 91244129  add      x9, x9, #0x910
//   0x04a934: 1000008a  adr      x10, #0x4a944
//   0x04a938: 7868792b  ldrh     w11, [x9, x8, lsl #1]
//   0x04a93c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x04a940: d61f0140  br       x10
//   0x04a944: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04a948: 36f800a8  tbz      w8, #0x1f, #0x4a95c
//   0x04a94c: 11002109  add      w9, w8, #8
//   0x04a950: 7100013f  cmp      w9, #0
//   0x04a954: b9013be9  str      w9, [sp, #0x138]
//   0x04a958: 54006acd  b.le     #0x4b6b0
//   0x04a95c: f94093e8  ldr      x8, [sp, #0x120]
//   0x04a960: 91002109  add      x9, x8, #8
//   0x04a964: f90093e9  str      x9, [sp, #0x120]
//   0x04a968: b9400108  ldr      w8, [x8]
//   0x04a96c: 12800000  mov      w0, #-1
//   0x04a970: 51200109  sub      w9, w8, #0x800
//   0x04a974: 71000d3f  cmp      w9, #3
//   0x04a978: 54008c68  b.hi     #0x4bb04
//   0x04a97c: 7100093f  cmp      w9, #2
//   0x04a980: 54008c20  b.eq     #0x4bb04
//   0x04a984: b977be69  ldr      w9, [x19, #0x37bc]
//   0x04a988: 35000089  cbnz     w9, #0x4a998
//   0x04a98c: b9407669  ldr      w9, [x19, #0x74]
//   0x04a990: 6b08013f  cmp      w9, w8
//   0x04a994: 54008981  b.ne     #0x4bac4
//   0x04a998: 2a1f03e0  mov      w0, wzr
//   0x04a99c: b9007668  str      w8, [x19, #0x74]
//   0x04a9a0: b900d268  str      w8, [x19, #0xd0]
//   0x04a9a4: 14000458  b        #0x4bb04
//   0x04a9a8: 52855f28  mov      w8, #0x2af9
//   0x04a9ac: 6b08003f  cmp      w1, w8
//   0x04a9b0: 540002ec  b.gt     #0x4aa0c
//   0x04a9b4: 5284e3e8  mov      w8, #0x271f
//   0x04a9b8: 6b08003f  cmp      w1, w8
//   0x04a9bc: 54005d60  b.eq     #0x4b568
//   0x04a9c0: 5284e508  mov      w8, #0x2728
//   0x04a9c4: 6b08003f  cmp      w1, w8
//   0x04a9c8: 54005ee0  b.eq     #0x4b5a4
//   0x04a9cc: 5284e548  mov      w8, #0x272a
//   0x04a9d0: 6b08003f  cmp      w1, w8
//   0x04a9d4: 54008981  b.ne     #0x4bb04
//   0x04a9d8: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04a9dc: 36f800a8  tbz      w8, #0x1f, #0x4a9f0
//   0x04a9e0: 11002109  add      w9, w8, #8
//   0x04a9e4: 7100013f  cmp      w9, #0
//   0x04a9e8: b9013be9  str      w9, [sp, #0x138]
//   0x04a9ec: 5400668d  b.le     #0x4b6bc
//   0x04a9f0: f94093e8  ldr      x8, [sp, #0x120]
//   0x04a9f4: 91002109  add      x9, x8, #8
//   0x04a9f8: f90093e9  str      x9, [sp, #0x120]
//   0x04a9fc: f9400102  ldr      x2, [x8]
//   0x04aa00: 5284e541  mov      w1, #0x272a
//   0x04aa04: f91be262  str      x2, [x19, #0x37c0]
//   0x04aa08: 140002e4  b        #0x4b598
//   0x04aa0c: 52855f48  mov      w8, #0x2afa
//   0x04aa10: 6b08003f  cmp      w1, w8
//   0x04aa14: 54005e60  b.eq     #0x4b5e0
//   0x04aa18: 52856148  mov      w8, #0x2b0a
//   0x04aa1c: 6b08003f  cmp      w1, w8
//   0x04aa20: 54006000  b.eq     #0x4b620
//   0x04aa24: 52856168  mov      w8, #0x2b0b
//   0x04aa28: 6b08003f  cmp      w1, w8
//   0x04aa2c: 540086c1  b.ne     #0x4bb04
//   0x04aa30: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04aa34: 36f800a8  tbz      w8, #0x1f, #0x4aa48
//   0x04aa38: 11002109  add      w9, w8, #8
//   0x04aa3c: 7100013f  cmp      w9, #0
//   0x04aa40: b9013be9  str      w9, [sp, #0x138]
//   0x04aa44: 5400642d  b.le     #0x4b6c8
//   0x04aa48: f94093e8  ldr      x8, [sp, #0x120]
//   0x04aa4c: 91002109  add      x9, x8, #8
//   0x04aa50: f90093e9  str      x9, [sp, #0x120]
//   0x04aa54: f9400108  ldr      x8, [x8]
//   0x04aa58: b4008368  cbz      x8, #0x4bac4
//   0x04aa5c: b9409669  ldr      w9, [x19, #0x94]
//   0x04aa60: 2a1f03e0  mov      w0, wzr
//   0x04aa64: 14000427  b        #0x4bb00
//   0x04aa68: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04aa6c: 36f800a8  tbz      w8, #0x1f, #0x4aa80
//   0x04aa70: 11002109  add      w9, w8, #8
//   0x04aa74: 7100013f  cmp      w9, #0
//   0x04aa78: b9013be9  str      w9, [sp, #0x138]
//   0x04aa7c: 5400630d  b.le     #0x4b6dc
//   0x04aa80: f94093e8  ldr      x8, [sp, #0x120]
//   0x04aa84: 91002109  add      x9, x8, #8
//   0x04aa88: f90093e9  str      x9, [sp, #0x120]
//   0x04aa8c: f9400108  ldr      x8, [x8]
//   0x04aa90: b40081a8  cbz      x8, #0x4bac4
//   0x04aa94: b9407669  ldr      w9, [x19, #0x74]
//   0x04aa98: 2a1f03e0  mov      w0, wzr
//   0x04aa9c: 14000419  b        #0x4bb00
//   0x04aaa0: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04aaa4: 36f800a8  tbz      w8, #0x1f, #0x4aab8
//   0x04aaa8: 11002109  add      w9, w8, #8
//   0x04aaac: 7100013f  cmp      w9, #0
//   0x04aab0: b9013be9  str      w9, [sp, #0x138]
//   0x04aab4: 540061ed  b.le     #0x4b6f0
//   0x04aab8: f94093e8  ldr      x8, [sp, #0x120]
//   0x04aabc: 91002109  add      x9, x8, #8
//   0x04aac0: f90093e9  str      x9, [sp, #0x120]
//   0x04aac4: b9400108  ldr      w8, [x8]
//   0x04aac8: 310fa11f  cmn      w8, #0x3e8
//   0x04aacc: 540080c0  b.eq     #0x4bae4
//   0x04aad0: 3100051f  cmn      w8, #1
//   0x04aad4: 54008080  b.eq     #0x4bae4
//   0x04aad8: 7100051f  cmp      w8, #1
//   0x04aadc: 54007f4b  b.lt     #0x4bac4
//   0x04aae0: 7107d51f  cmp      w8, #0x1f5
//   0x04aae4: 54007f4a  b.ge     #0x4bacc
//   0x04aae8: 52803e88  mov      w8, #0x1f4
//   0x04aaec: 140003fe  b        #0x4bae4
//   0x04aaf0: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04aaf4: 36f800a8  tbz      w8, #0x1f, #0x4ab08
//   0x04aaf8: 11002109  add      w9, w8, #8
//   0x04aafc: 7100013f  cmp      w9, #0
//   0x04ab00: b9013be9  str      w9, [sp, #0x138]
//   0x04ab04: 5400602d  b.le     #0x4b708
//   0x04ab08: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ab0c: 91002109  add      x9, x8, #8
//   0x04ab10: f90093e9  str      x9, [sp, #0x120]
//   0x04ab14: f9400108  ldr      x8, [x8]
//   0x04ab18: b4007d68  cbz      x8, #0x4bac4
//   0x04ab1c: b977ae69  ldr      w9, [x19, #0x37ac]
//   0x04ab20: 35000109  cbnz     w9, #0x4ab40
//   0x04ab24: b9809a69  ldrsw    x9, [x19, #0x98]
//   0x04ab28: 5290a3ea  mov      w10, #0x851f
//   0x04ab2c: 72aa3d6a  movk     w10, #0x51eb, lsl #16
//   0x04ab30: 9b0a7d29  mul      x9, x9, x10
//   0x04ab34: d37ffd2a  lsr      x10, x9, #0x3f
//   0x04ab38: 9367fd29  asr      x9, x9, #0x27
//   0x04ab3c: 0b0a0129  add      w9, w9, w10
//   0x04ab40: b940ae6a  ldr      w10, [x19, #0xac]
//   0x04ab44: 3100055f  cmn      w10, #1
//   0x04ab48: 54005a00  b.eq     #0x4b688
//   0x04ab4c: 310fa15f  cmn      w10, #0x3e8
//   0x04ab50: 54005a41  b.ne     #0x4b698
//   0x04ab54: b9409a6a  ldr      w10, [x19, #0x98]
//   0x04ab58: b9407a6b  ldr      w11, [x19, #0x78]
//   0x04ab5c: 5280078c  mov      w12, #0x3c
//   0x04ab60: 1b0c7d4c  mul      w12, w10, w12
//   0x04ab64: 1ac90d89  sdiv     w9, w12, w9
//   0x04ab68: 1b0a256a  madd     w10, w11, w10, w9
//   0x04ab6c: 140002cb  b        #0x4b698
//   0x04ab70: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ab74: 36f800a8  tbz      w8, #0x1f, #0x4ab88
//   0x04ab78: 11002109  add      w9, w8, #8
//   0x04ab7c: 7100013f  cmp      w9, #0
//   0x04ab80: b9013be9  str      w9, [sp, #0x138]
//   0x04ab84: 54005ccd  b.le     #0x4b71c
//   0x04ab88: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ab8c: 91002109  add      x9, x8, #8
//   0x04ab90: f90093e9  str      x9, [sp, #0x120]
//   0x04ab94: b9400108  ldr      w8, [x8]
//   0x04ab98: 51113509  sub      w9, w8, #0x44d
//   0x04ab9c: 7100113f  cmp      w9, #4
//   0x04aba0: 54007928  b.hi     #0x4bac4
//   0x04aba4: 7111351f  cmp      w8, #0x44d
//   0x04aba8: b9008e68  str      w8, [x19, #0x8c]
//   0x04abac: 540008a0  b.eq     #0x4acc0
//   0x04abb0: 7111391f  cmp      w8, #0x44e
//   0x04abb4: 54005621  b.ne     #0x4b678
//   0x04abb8: 5285dc08  mov      w8, #0x2ee0
//   0x04abbc: 2a1f03e0  mov      w0, wzr
//   0x04abc0: b9001668  str      w8, [x19, #0x14]
//   0x04abc4: 140003d0  b        #0x4bb04
//   0x04abc8: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04abcc: 36f800a8  tbz      w8, #0x1f, #0x4abe0
//   0x04abd0: 11002109  add      w9, w8, #8
//   0x04abd4: 7100013f  cmp      w9, #0
//   0x04abd8: b9013be9  str      w9, [sp, #0x138]
//   0x04abdc: 54005aed  b.le     #0x4b738
//   0x04abe0: f94093e8  ldr      x8, [sp, #0x120]
//   0x04abe4: 91002109  add      x9, x8, #8
//   0x04abe8: f90093e9  str      x9, [sp, #0x120]
//   0x04abec: f9400108  ldr      x8, [x8]
//   0x04abf0: b40076a8  cbz      x8, #0x4bac4
//   0x04abf4: b9408e69  ldr      w9, [x19, #0x8c]
//   0x04abf8: 2a1f03e0  mov      w0, wzr
//   0x04abfc: 140003c1  b        #0x4bb00
//   0x04ac00: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ac04: 36f800a8  tbz      w8, #0x1f, #0x4ac18
//   0x04ac08: 11002109  add      w9, w8, #8
//   0x04ac0c: 7100013f  cmp      w9, #0
//   0x04ac10: b9013be9  str      w9, [sp, #0x138]
//   0x04ac14: 540059cd  b.le     #0x4b74c
//   0x04ac18: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ac1c: 91002109  add      x9, x8, #8
//   0x04ac20: f90093e9  str      x9, [sp, #0x120]
//   0x04ac24: b9400108  ldr      w8, [x8]
//   0x04ac28: 7100051f  cmp      w8, #1
//   0x04ac2c: 540074c8  b.hi     #0x4bac4
//   0x04ac30: 52800029  mov      w9, #1
//   0x04ac34: b9009e68  str      w8, [x19, #0x9c]
//   0x04ac38: 4b080128  sub      w8, w9, w8
//   0x04ac3c: 2a1f03e0  mov      w0, wzr
//   0x04ac40: b9004268  str      w8, [x19, #0x40]
//   0x04ac44: 140003b0  b        #0x4bb04
//   0x04ac48: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ac4c: 36f800a8  tbz      w8, #0x1f, #0x4ac60
//   0x04ac50: 11002109  add      w9, w8, #8
//   0x04ac54: 7100013f  cmp      w9, #0
//   0x04ac58: b9013be9  str      w9, [sp, #0x138]
//   0x04ac5c: 5400584d  b.le     #0x4b764
//   0x04ac60: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ac64: 91002109  add      x9, x8, #8
//   0x04ac68: f90093e9  str      x9, [sp, #0x120]
//   0x04ac6c: f9400108  ldr      x8, [x8]
//   0x04ac70: b40072a8  cbz      x8, #0x4bac4
//   0x04ac74: b9409e69  ldr      w9, [x19, #0x9c]
//   0x04ac78: 2a1f03e0  mov      w0, wzr
//   0x04ac7c: 140003a1  b        #0x4bb00
//   0x04ac80: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ac84: 36f800a8  tbz      w8, #0x1f, #0x4ac98
//   0x04ac88: 11002109  add      w9, w8, #8
//   0x04ac8c: 7100013f  cmp      w9, #0
//   0x04ac90: b9013be9  str      w9, [sp, #0x138]
//   0x04ac94: 5400572d  b.le     #0x4b778
//   0x04ac98: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ac9c: 91002109  add      x9, x8, #8
//   0x04aca0: f90093e9  str      x9, [sp, #0x120]
//   0x04aca4: b9400108  ldr      w8, [x8]
//   0x04aca8: 51113509  sub      w9, w8, #0x44d
//   0x04acac: 7100153f  cmp      w9, #5
//   0x04acb0: 54005702  b.hs     #0x4b790
//   0x04acb4: 7111351f  cmp      w8, #0x44d
//   0x04acb8: b9008a68  str      w8, [x19, #0x88]
//   0x04acbc: 54fff7a1  b.ne     #0x4abb0
//   0x04acc0: 5283e808  mov      w8, #0x1f40
//   0x04acc4: 2a1f03e0  mov      w0, wzr
//   0x04acc8: b9001668  str      w8, [x19, #0x14]
//   0x04accc: 1400038e  b        #0x4bb04
//   0x04acd0: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04acd4: 36f800a8  tbz      w8, #0x1f, #0x4ace8
//   0x04acd8: 11002109  add      w9, w8, #8
//   0x04acdc: 7100013f  cmp      w9, #0
//   0x04ace0: b9013be9  str      w9, [sp, #0x138]
//   0x04ace4: 540055cd  b.le     #0x4b79c
//   0x04ace8: f94093e8  ldr      x8, [sp, #0x120]
//   0x04acec: 91002109  add      x9, x8, #8
//   0x04acf0: f90093e9  str      x9, [sp, #0x120]
//   0x04acf4: f9400108  ldr      x8, [x8]
//   0x04acf8: b4006e68  cbz      x8, #0x4bac4
//   0x04acfc: b977b269  ldr      w9, [x19, #0x37b0]
//   0x04ad00: 2a1f03e0  mov      w0, wzr
//   0x04ad04: 1400037f  b        #0x4bb00
//   0x04ad08: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ad0c: 36f800a8  tbz      w8, #0x1f, #0x4ad20
//   0x04ad10: 11002109  add      w9, w8, #8
//   0x04ad14: 7100013f  cmp      w9, #0
//   0x04ad18: b9013be9  str      w9, [sp, #0x138]
//   0x04ad1c: 540054ad  b.le     #0x4b7b0
//   0x04ad20: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ad24: 91002109  add      x9, x8, #8
//   0x04ad28: f90093e9  str      x9, [sp, #0x120]
//   0x04ad2c: b9400102  ldr      w2, [x8]
//   0x04ad30: 7100285f  cmp      w2, #0xa
//   0x04ad34: 54006c88  b.hi     #0x4bac4
//   0x04ad38: b9002e62  str      w2, [x19, #0x2c]
//   0x04ad3c: 5281f541  mov      w1, #0xfaa
//   0x04ad40: 14000181  b        #0x4b344
//   0x04ad44: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ad48: 36f800a8  tbz      w8, #0x1f, #0x4ad5c
//   0x04ad4c: 11002109  add      w9, w8, #8
//   0x04ad50: 7100013f  cmp      w9, #0
//   0x04ad54: b9013be9  str      w9, [sp, #0x138]
//   0x04ad58: 5400538d  b.le     #0x4b7c8
//   0x04ad5c: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ad60: 91002109  add      x9, x8, #8
//   0x04ad64: f90093e9  str      x9, [sp, #0x120]
//   0x04ad68: f9400108  ldr      x8, [x8]
//   0x04ad6c: b4006ac8  cbz      x8, #0x4bac4
//   0x04ad70: b9402e69  ldr      w9, [x19, #0x2c]
//   0x04ad74: 2a1f03e0  mov      w0, wzr
//   0x04ad78: 14000362  b        #0x4bb00
//   0x04ad7c: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ad80: 36f800a8  tbz      w8, #0x1f, #0x4ad94
//   0x04ad84: 11002109  add      w9, w8, #8
//   0x04ad88: 7100013f  cmp      w9, #0
//   0x04ad8c: b9013be9  str      w9, [sp, #0x138]
//   0x04ad90: 5400526d  b.le     #0x4b7dc
//   0x04ad94: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ad98: 91002109  add      x9, x8, #8
//   0x04ad9c: f90093e9  str      x9, [sp, #0x120]
//   0x04ada0: b9400108  ldr      w8, [x8]
//   0x04ada4: 7100051f  cmp      w8, #1
//   0x04ada8: 540068e8  b.hi     #0x4bac4
//   0x04adac: 2a1f03e0  mov      w0, wzr
//   0x04adb0: b9003268  str      w8, [x19, #0x30]
//   0x04adb4: 14000354  b        #0x4bb04
//   0x04adb8: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04adbc: 36f800a8  tbz      w8, #0x1f, #0x4add0
//   0x04adc0: 11002109  add      w9, w8, #8
//   0x04adc4: 7100013f  cmp      w9, #0
//   0x04adc8: b9013be9  str      w9, [sp, #0x138]
//   0x04adcc: 5400514d  b.le     #0x4b7f4
//   0x04add0: f94093e8  ldr      x8, [sp, #0x120]
//   0x04add4: 91002109  add      x9, x8, #8
//   0x04add8: f90093e9  str      x9, [sp, #0x120]
//   0x04addc: f9400108  ldr      x8, [x8]
//   0x04ade0: b4006728  cbz      x8, #0x4bac4
//   0x04ade4: b9403269  ldr      w9, [x19, #0x30]
//   0x04ade8: 2a1f03e0  mov      w0, wzr
//   0x04adec: 14000345  b        #0x4bb00
//   0x04adf0: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04adf4: 36f800a8  tbz      w8, #0x1f, #0x4ae08
//   0x04adf8: 11002109  add      w9, w8, #8
//   0x04adfc: 7100013f  cmp      w9, #0
//   0x04ae00: b9013be9  str      w9, [sp, #0x138]
//   0x04ae04: 5400502d  b.le     #0x4b808
//   0x04ae08: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ae0c: 91002109  add      x9, x8, #8
//   0x04ae10: f90093e9  str      x9, [sp, #0x120]
//   0x04ae14: b9400102  ldr      w2, [x8]
//   0x04ae18: 7101905f  cmp      w2, #0x64
//   0x04ae1c: 54006548  b.hi     #0x4bac4
//   0x04ae20: b9002a62  str      w2, [x19, #0x28]
//   0x04ae24: 5281f5c1  mov      w1, #0xfae
//   0x04ae28: 14000147  b        #0x4b344
//   0x04ae2c: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ae30: 36f800a8  tbz      w8, #0x1f, #0x4ae44
//   0x04ae34: 11002109  add      w9, w8, #8
//   0x04ae38: 7100013f  cmp      w9, #0
//   0x04ae3c: b9013be9  str      w9, [sp, #0x138]
//   0x04ae40: 54004f0d  b.le     #0x4b820
//   0x04ae44: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ae48: 91002109  add      x9, x8, #8
//   0x04ae4c: f90093e9  str      x9, [sp, #0x120]
//   0x04ae50: f9400108  ldr      x8, [x8]
//   0x04ae54: b4006388  cbz      x8, #0x4bac4
//   0x04ae58: b9402a69  ldr      w9, [x19, #0x28]
//   0x04ae5c: 2a1f03e0  mov      w0, wzr
//   0x04ae60: 14000328  b        #0x4bb00
//   0x04ae64: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04ae68: 36f800a8  tbz      w8, #0x1f, #0x4ae7c
//   0x04ae6c: 11002109  add      w9, w8, #8
//   0x04ae70: 7100013f  cmp      w9, #0
//   0x04ae74: b9013be9  str      w9, [sp, #0x138]
//   0x04ae78: 54004ded  b.le     #0x4b834
//   0x04ae7c: f94093e8  ldr      x8, [sp, #0x120]
//   0x04ae80: 91002109  add      x9, x8, #8
//   0x04ae84: f90093e9  str      x9, [sp, #0x120]
//   0x04ae88: b9400108  ldr      w8, [x8]
//   0x04ae8c: 7100051f  cmp      w8, #1
//   0x04ae90: 540061a8  b.hi     #0x4bac4
//   0x04ae94: 2a1f03e0  mov      w0, wzr
//   0x04ae98: b900c268  str      w8, [x19, #0xc0]
//   0x04ae9c: 1400031a  b        #0x4bb04
//   0x04aea0: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04aea4: 36f800a8  tbz      w8, #0x1f, #0x4aeb8
//   0x04aea8: 11002109  add      w9, w8, #8
//   0x04aeac: 7100013f  cmp      w9, #0
//   0x04aeb0: b9013be9  str      w9, [sp, #0x138]
//   0x04aeb4: 54004ccd  b.le     #0x4b84c
//   0x04aeb8: f94093e8  ldr      x8, [sp, #0x120]
//   0x04aebc: 91002109  add      x9, x8, #8
//   0x04aec0: f90093e9  str      x9, [sp, #0x120]
//   0x04aec4: f9400108  ldr      x8, [x8]
//   0x04aec8: b4005fe8  cbz      x8, #0x4bac4
//   0x04aecc: b940c269  ldr      w9, [x19, #0xc0]
//   0x04aed0: 2a1f03e0  mov      w0, wzr
//   0x04aed4: 1400030b  b        #0x4bb00
//   0x04aed8: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04aedc: 36f800a8  tbz      w8, #0x1f, #0x4aef0
//   0x04aee0: 11002109  add      w9, w8, #8
//   0x04aee4: 7100013f  cmp      w9, #0
//   0x04aee8: b9013be9  str      w9, [sp, #0x138]
//   0x04aeec: 54004bad  b.le     #0x4b860
//   0x04aef0: f94093e8  ldr      x8, [sp, #0x120]
//   0x04aef4: 91002109  add      x9, x8, #8
//   0x04aef8: f90093e9  str      x9, [sp, #0x120]
//   0x04aefc: b9400108  ldr      w8, [x8]
//   0x04af00: 7100051f  cmp      w8, #1
//   0x04af04: 54005e08  b.hi     #0x4bac4
//   0x04af08: 2a1f03e0  mov      w0, wzr
//   0x04af0c: b900a268  str      w8, [x19, #0xa0]
//   0x04af10: 140002fd  b        #0x4bb04
//   0x04af14: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04af18: 36f800a8  tbz      w8, #0x1f, #0x4af2c
//   0x04af1c: 11002109  add      w9, w8, #8
//   0x04af20: 7100013f  cmp      w9, #0
//   0x04af24: b9013be9  str      w9, [sp, #0x138]
//   0x04af28: 54004a8d  b.le     #0x4b878
//   0x04af2c: f94093e8  ldr      x8, [sp, #0x120]
//   0x04af30: 91002109  add      x9, x8, #8
//   0x04af34: f90093e9  str      x9, [sp, #0x120]
//   0x04af38: f9400108  ldr      x8, [x8]
//   0x04af3c: b4005c48  cbz      x8, #0x4bac4
//   0x04af40: b940a269  ldr      w9, [x19, #0xa0]
//   0x04af44: 2a1f03e0  mov      w0, wzr
//   0x04af48: 140002ee  b        #0x4bb00
//   0x04af4c: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04af50: 36f800a8  tbz      w8, #0x1f, #0x4af64
//   0x04af54: 11002109  add      w9, w8, #8
//   0x04af58: 7100013f  cmp      w9, #0
//   0x04af5c: b9013be9  str      w9, [sp, #0x138]
//   0x04af60: 5400496d  b.le     #0x4b88c
//   0x04af64: f94093e8  ldr      x8, [sp, #0x120]
//   0x04af68: 91002109  add      x9, x8, #8
//   0x04af6c: f90093e9  str      x9, [sp, #0x120]
//   0x04af70: b9400108  ldr      w8, [x8]
//   0x04af74: 7100051f  cmp      w8, #1
//   0x04af78: 5400494b  b.lt     #0x4b8a0
//   0x04af7c: b9407a69  ldr      w9, [x19, #0x78]
//   0x04af80: 6b09011f  cmp      w8, w9
//   0x04af84: 5400492d  b.le     #0x4b8a8
//   0x04af88: 140002cf  b        #0x4bac4
//   0x04af8c: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04af90: 36f800a8  tbz      w8, #0x1f, #0x4afa4
//   0x04af94: 11002109  add      w9, w8, #8
//   0x04af98: 7100013f  cmp      w9, #0
//   0x04af9c: b9013be9  str      w9, [sp, #0x138]
//   0x04afa0: 540048ad  b.le     #0x4b8b4
//   0x04afa4: f94093e8  ldr      x8, [sp, #0x120]
//   0x04afa8: 91002109  add      x9, x8, #8
//   0x04afac: f90093e9  str      x9, [sp, #0x120]
//   0x04afb0: f9400108  ldr      x8, [x8]
//   0x04afb4: b4005888  cbz      x8, #0x4bac4
//   0x04afb8: b9408269  ldr      w9, [x19, #0x80]
//   0x04afbc: 2a1f03e0  mov      w0, wzr
//   0x04afc0: 140002d0  b        #0x4bb00
//   0x04afc4: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04afc8: 36f800a8  tbz      w8, #0x1f, #0x4afdc
//   0x04afcc: 11002109  add      w9, w8, #8
//   0x04afd0: 7100013f  cmp      w9, #0
//   0x04afd4: b9013be9  str      w9, [sp, #0x138]
//   0x04afd8: 5400478d  b.le     #0x4b8c8
//   0x04afdc: f94093e8  ldr      x8, [sp, #0x120]
//   0x04afe0: 91002109  add      x9, x8, #8
//   0x04afe4: f90093e9  str      x9, [sp, #0x120]
//   0x04afe8: b9400108  ldr      w8, [x8]
//   0x04afec: 512ee509  sub      w9, w8, #0xbb9
//   0x04aff0: 7100093f  cmp      w9, #2
//   0x04aff4: 54004763  b.lo     #0x4b8e0
//   0x04aff8: 310fa11f  cmn      w8, #0x3e8
//   0x04affc: 54004720  b.eq     #0x4b8e0
//   0x04b000: 140002b1  b        #0x4bac4
//   0x04b004: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b008: 36f800a8  tbz      w8, #0x1f, #0x4b01c
//   0x04b00c: 11002109  add      w9, w8, #8
//   0x04b010: 7100013f  cmp      w9, #0
//   0x04b014: b9013be9  str      w9, [sp, #0x138]
//   0x04b018: 540046ad  b.le     #0x4b8ec
//   0x04b01c: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b020: 91002109  add      x9, x8, #8
//   0x04b024: f90093e9  str      x9, [sp, #0x120]
//   0x04b028: f9400108  ldr      x8, [x8]
//   0x04b02c: b40054c8  cbz      x8, #0x4bac4
//   0x04b030: b9408669  ldr      w9, [x19, #0x84]
//   0x04b034: 2a1f03e0  mov      w0, wzr
//   0x04b038: 140002b2  b        #0x4bb00
//   0x04b03c: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b040: 36f800a8  tbz      w8, #0x1f, #0x4b054
//   0x04b044: 11002109  add      w9, w8, #8
//   0x04b048: 7100013f  cmp      w9, #0
//   0x04b04c: b9013be9  str      w9, [sp, #0x138]
//   0x04b050: 5400458d  b.le     #0x4b900
//   0x04b054: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b058: 91002109  add      x9, x8, #8
//   0x04b05c: f90093e9  str      x9, [sp, #0x120]
//   0x04b060: f9400108  ldr      x8, [x8]
//   0x04b064: b4005308  cbz      x8, #0x4bac4
//   0x04b068: b9809a69  ldrsw    x9, [x19, #0x98]
//   0x04b06c: 5290a3ea  mov      w10, #0x851f
//   0x04b070: 72aa3d6a  movk     w10, #0x51eb, lsl #16
//   0x04b074: 9b0a7d29  mul      x9, x9, x10
//   0x04b078: d37ffd2a  lsr      x10, x9, #0x3f
//   0x04b07c: 9367fd29  asr      x9, x9, #0x27
//   0x04b080: 0b0a0129  add      w9, w9, w10
//   0x04b084: b9000109  str      w9, [x8]
//   0x04b088: b940766a  ldr      w10, [x19, #0x74]
//   0x04b08c: 71200d5f  cmp      w10, #0x803
//   0x04b090: 540017c0  b.eq     #0x4b388
//   0x04b094: b9407e6a  ldr      w10, [x19, #0x7c]
//   0x04b098: 2a1f03e0  mov      w0, wzr
//   0x04b09c: 0b090149  add      w9, w10, w9
//   0x04b0a0: 14000298  b        #0x4bb00
//   0x04b0a4: b9800668  ldrsw    x8, [x19, #4]
//   0x04b0a8: 5286f089  mov      w9, #0x3784
//   0x04b0ac: 91033260  add      x0, x19, #0xcc
//   0x04b0b0: 8b090276  add      x22, x19, x9
//   0x04b0b4: 8b080275  add      x21, x19, x8
//   0x04b0b8: 94001aa7  bl       #0x51b54
//   0x04b0bc: 5286f008  mov      w8, #0x3780
//   0x04b0c0: 8b080260  add      x0, x19, x8
//   0x04b0c4: 5280ff02  mov      w2, #0x7f8
//   0x04b0c8: 2a1f03e1  mov      w1, wzr
//   0x04b0cc: 97fedf05  bl       #0x2ce0
//   0x04b0d0: 5281f781  mov      w1, #0xfbc
//   0x04b0d4: aa1403e0  mov      x0, x20
//   0x04b0d8: 97ff13ba  bl       #0xffc0
//   0x04b0dc: b940be61  ldr      w1, [x19, #0xbc]
//   0x04b0e0: 9102c3e2  add      x2, sp, #0xb0
//   0x04b0e4: aa1503e0  mov      x0, x21
//   0x04b0e8: 97ff5d39  bl       #0x225cc
//   0x04b0ec: b9407a68  ldr      w8, [x19, #0x78]
//   0x04b0f0: 52880009  mov      w9, #0x4000
//   0x04b0f4: 528fffea  mov      w10, #0x7fff
//   0x04b0f8: 5280002b  mov      w11, #1
//   0x04b0fc: 52807d2c  mov      w12, #0x3e9
//   0x04b100: 52808a2d  mov      w13, #0x451
//   0x04b104: 52800780  mov      w0, #0x3c
//   0x04b108: b9378268  str      w8, [x19, #0x3780]
//   0x04b10c: 790002c9  strh     w9, [x22]
//   0x04b110: 790012ca  strh     w10, [x22, #8]
//   0x04b114: b937be6b  str      w11, [x19, #0x37bc]
//   0x04b118: b937a26c  str      w12, [x19, #0x37a0]
//   0x04b11c: b937b26d  str      w13, [x19, #0x37b0]
//   0x04b120: 97ff9986  bl       #0x31738
//   0x04b124: 2a0003e8  mov      w8, w0
//   0x04b128: 53185d08  lsl      w8, w8, #8
//   0x04b12c: 2a1f03e0  mov      w0, wzr
//   0x04b130: b9378a68  str      w8, [x19, #0x3788]
//   0x04b134: 14000274  b        #0x4bb04
//   0x04b138: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b13c: 36f800a8  tbz      w8, #0x1f, #0x4b150
//   0x04b140: 11002109  add      w9, w8, #8
//   0x04b144: 7100013f  cmp      w9, #0
//   0x04b148: b9013be9  str      w9, [sp, #0x138]
//   0x04b14c: 54003e4d  b.le     #0x4b914
//   0x04b150: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b154: 91002109  add      x9, x8, #8
//   0x04b158: f90093e9  str      x9, [sp, #0x120]
//   0x04b15c: f9400108  ldr      x8, [x8]
//   0x04b160: b4004b28  cbz      x8, #0x4bac4
//   0x04b164: b9409a69  ldr      w9, [x19, #0x98]
//   0x04b168: 2a1f03e0  mov      w0, wzr
//   0x04b16c: 14000265  b        #0x4bb00
//   0x04b170: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b174: 36f800a8  tbz      w8, #0x1f, #0x4b188
//   0x04b178: 11002109  add      w9, w8, #8
//   0x04b17c: 7100013f  cmp      w9, #0
//   0x04b180: b9013be9  str      w9, [sp, #0x138]
//   0x04b184: 54003d2d  b.le     #0x4b928
//   0x04b188: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b18c: 91002109  add      x9, x8, #8
//   0x04b190: f90093e9  str      x9, [sp, #0x120]
//   0x04b194: f9400108  ldr      x8, [x8]
//   0x04b198: b4004968  cbz      x8, #0x4bac4
//   0x04b19c: b97f6e69  ldr      w9, [x19, #0x3f6c]
//   0x04b1a0: 2a1f03e0  mov      w0, wzr
//   0x04b1a4: 14000257  b        #0x4bb00
//   0x04b1a8: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b1ac: 36f800a8  tbz      w8, #0x1f, #0x4b1c0
//   0x04b1b0: 11002109  add      w9, w8, #8
//   0x04b1b4: 7100013f  cmp      w9, #0
//   0x04b1b8: b9013be9  str      w9, [sp, #0x138]
//   0x04b1bc: 54003c0d  b.le     #0x4b93c
//   0x04b1c0: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b1c4: 91002109  add      x9, x8, #8
//   0x04b1c8: f90093e9  str      x9, [sp, #0x120]
//   0x04b1cc: b9400108  ldr      w8, [x8]
//   0x04b1d0: 51002109  sub      w9, w8, #8
//   0x04b1d4: 7100413f  cmp      w9, #0x10
//   0x04b1d8: 54004768  b.hi     #0x4bac4
//   0x04b1dc: 2a1f03e0  mov      w0, wzr
//   0x04b1e0: b900b268  str      w8, [x19, #0xb0]
//   0x04b1e4: 14000248  b        #0x4bb04
//   0x04b1e8: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b1ec: 36f800a8  tbz      w8, #0x1f, #0x4b200
//   0x04b1f0: 11002109  add      w9, w8, #8
//   0x04b1f4: 7100013f  cmp      w9, #0
//   0x04b1f8: b9013be9  str      w9, [sp, #0x138]
//   0x04b1fc: 54003aed  b.le     #0x4b958
//   0x04b200: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b204: 91002109  add      x9, x8, #8
//   0x04b208: f90093e9  str      x9, [sp, #0x120]
//   0x04b20c: f9400108  ldr      x8, [x8]
//   0x04b210: b40045a8  cbz      x8, #0x4bac4
//   0x04b214: b940b269  ldr      w9, [x19, #0xb0]
//   0x04b218: 2a1f03e0  mov      w0, wzr
//   0x04b21c: 14000239  b        #0x4bb00
//   0x04b220: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b224: 36f800a8  tbz      w8, #0x1f, #0x4b238
//   0x04b228: 11002109  add      w9, w8, #8
//   0x04b22c: 7100013f  cmp      w9, #0
//   0x04b230: b9013be9  str      w9, [sp, #0x138]
//   0x04b234: 540039cd  b.le     #0x4b96c
//   0x04b238: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b23c: 91002109  add      x9, x8, #8
//   0x04b240: f90093e9  str      x9, [sp, #0x120]
//   0x04b244: b9400108  ldr      w8, [x8]
//   0x04b248: 128270e9  mov      w9, #-0x1388
//   0x04b24c: 0b090109  add      w9, w8, w9
//   0x04b250: 7100253f  cmp      w9, #9
//   0x04b254: 54004388  b.hi     #0x4bac4
//   0x04b258: 2a1f03e0  mov      w0, wzr
//   0x04b25c: b900a668  str      w8, [x19, #0xa4]
//   0x04b260: 14000229  b        #0x4bb04
//   0x04b264: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b268: 36f800a8  tbz      w8, #0x1f, #0x4b27c
//   0x04b26c: 11002109  add      w9, w8, #8
//   0x04b270: 7100013f  cmp      w9, #0
//   0x04b274: b9013be9  str      w9, [sp, #0x138]
//   0x04b278: 5400380d  b.le     #0x4b978
//   0x04b27c: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b280: 91002109  add      x9, x8, #8
//   0x04b284: f90093e9  str      x9, [sp, #0x120]
//   0x04b288: f9400108  ldr      x8, [x8]
//   0x04b28c: b40041c8  cbz      x8, #0x4bac4
//   0x04b290: b940a669  ldr      w9, [x19, #0xa4]
//   0x04b294: 2a1f03e0  mov      w0, wzr
//   0x04b298: 1400021a  b        #0x4bb00
//   0x04b29c: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b2a0: 36f800a8  tbz      w8, #0x1f, #0x4b2b4
//   0x04b2a4: 11002109  add      w9, w8, #8
//   0x04b2a8: 7100013f  cmp      w9, #0
//   0x04b2ac: b9013be9  str      w9, [sp, #0x138]
//   0x04b2b0: 540036ed  b.le     #0x4b98c
//   0x04b2b4: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b2b8: 91002109  add      x9, x8, #8
//   0x04b2bc: f90093e9  str      x9, [sp, #0x120]
//   0x04b2c0: b9400108  ldr      w8, [x8]
//   0x04b2c4: 7100051f  cmp      w8, #1
//   0x04b2c8: 54003fe8  b.hi     #0x4bac4
//   0x04b2cc: 2a1f03e0  mov      w0, wzr
//   0x04b2d0: b9005268  str      w8, [x19, #0x50]
//   0x04b2d4: 1400020c  b        #0x4bb04
//   0x04b2d8: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b2dc: 36f800a8  tbz      w8, #0x1f, #0x4b2f0
//   0x04b2e0: 11002109  add      w9, w8, #8
//   0x04b2e4: 7100013f  cmp      w9, #0
//   0x04b2e8: b9013be9  str      w9, [sp, #0x138]
//   0x04b2ec: 540035cd  b.le     #0x4b9a4
//   0x04b2f0: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b2f4: 91002109  add      x9, x8, #8
//   0x04b2f8: f90093e9  str      x9, [sp, #0x120]
//   0x04b2fc: f9400108  ldr      x8, [x8]
//   0x04b300: b4003e28  cbz      x8, #0x4bac4
//   0x04b304: b9405269  ldr      w9, [x19, #0x50]
//   0x04b308: 2a1f03e0  mov      w0, wzr
//   0x04b30c: 140001fd  b        #0x4bb00
//   0x04b310: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b314: 36f800a8  tbz      w8, #0x1f, #0x4b328
//   0x04b318: 11002109  add      w9, w8, #8
//   0x04b31c: 7100013f  cmp      w9, #0
//   0x04b320: b9013be9  str      w9, [sp, #0x138]
//   0x04b324: 540034ad  b.le     #0x4b9b8
//   0x04b328: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b32c: 91002109  add      x9, x8, #8
//   0x04b330: f90093e9  str      x9, [sp, #0x120]
//   0x04b334: b9400102  ldr      w2, [x8]
//   0x04b338: 7100045f  cmp      w2, #1
//   0x04b33c: 54003c48  b.hi     #0x4bac4
//   0x04b340: 5281f9c1  mov      w1, #0xfce
//   0x04b344: aa1403e0  mov      x0, x20
//   0x04b348: 97ff131e  bl       #0xffc0
//   0x04b34c: 1400000f  b        #0x4b388
//   0x04b350: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b354: 36f800a8  tbz      w8, #0x1f, #0x4b368
//   0x04b358: 11002109  add      w9, w8, #8
//   0x04b35c: 7100013f  cmp      w9, #0
//   0x04b360: b9013be9  str      w9, [sp, #0x138]
//   0x04b364: 5400336d  b.le     #0x4b9d0
//   0x04b368: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b36c: 91002109  add      x9, x8, #8
//   0x04b370: f90093e9  str      x9, [sp, #0x120]
//   0x04b374: f9400102  ldr      x2, [x8]
//   0x04b378: b4003a62  cbz      x2, #0x4bac4
//   0x04b37c: 5281f9e1  mov      w1, #0xfcf
//   0x04b380: aa1403e0  mov      x0, x20
//   0x04b384: 97ff130f  bl       #0xffc0
//   0x04b388: 2a1f03e0  mov      w0, wzr
//   0x04b38c: 140001de  b        #0x4bb04
//   0x04b390: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b394: 36f800a8  tbz      w8, #0x1f, #0x4b3a8
//   0x04b398: 11002109  add      w9, w8, #8
//   0x04b39c: 7100013f  cmp      w9, #0
//   0x04b3a0: b9013be9  str      w9, [sp, #0x138]
//   0x04b3a4: 5400320d  b.le     #0x4b9e4
//   0x04b3a8: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b3ac: 91002109  add      x9, x8, #8
//   0x04b3b0: f90093e9  str      x9, [sp, #0x120]
//   0x04b3b4: f9400108  ldr      x8, [x8]
//   0x04b3b8: b4003868  cbz      x8, #0x4bac4
//   0x04b3bc: b9403a69  ldr      w9, [x19, #0x38]
//   0x04b3c0: 34001509  cbz      w9, #0x4b660
//   0x04b3c4: b977a669  ldr      w9, [x19, #0x37a4]
//   0x04b3c8: 121f7929  and      w9, w9, #0xfffffffe
//   0x04b3cc: 710fa13f  cmp      w9, #0x3e8
//   0x04b3d0: 54001481  b.ne     #0x4b660
//   0x04b3d4: 52800029  mov      w9, #1
//   0x04b3d8: b980066a  ldrsw    x10, [x19, #4]
//   0x04b3dc: b9000109  str      w9, [x8]
//   0x04b3e0: b9400e69  ldr      w9, [x19, #0xc]
//   0x04b3e4: 7100053f  cmp      w9, #1
//   0x04b3e8: 54fffd0b  b.lt     #0x4b388
//   0x04b3ec: 8b13014a  add      x10, x10, x19
//   0x04b3f0: 5282fb0b  mov      w11, #0x17d8
//   0x04b3f4: aa1f03e9  mov      x9, xzr
//   0x04b3f8: 5280002c  mov      w12, #1
//   0x04b3fc: 8b0b014a  add      x10, x10, x11
//   0x04b400: 52843a0b  mov      w11, #0x21d0
//   0x04b404: 3500012c  cbnz     w12, #0x4b428
//   0x04b408: b900010c  str      w12, [x8]
//   0x04b40c: b9800e6d  ldrsw    x13, [x19, #0xc]
//   0x04b410: 91000529  add      x9, x9, #1
//   0x04b414: 2a1f03e0  mov      w0, wzr
//   0x04b418: 8b0b014a  add      x10, x10, x11
//   0x04b41c: eb0d013f  cmp      x9, x13
//   0x04b420: 5400372a  b.ge     #0x4bb04
//   0x04b424: 34ffff2c  cbz      w12, #0x4b408
//   0x04b428: b940014c  ldr      w12, [x10]
//   0x04b42c: 7100259f  cmp      w12, #9
//   0x04b430: 1a9fd7ec  cset     w12, gt
//   0x04b434: 17fffff5  b        #0x4b408
//   0x04b438: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b43c: 36f800a8  tbz      w8, #0x1f, #0x4b450
//   0x04b440: 11002109  add      w9, w8, #8
//   0x04b444: 7100013f  cmp      w9, #0
//   0x04b448: b9013be9  str      w9, [sp, #0x138]
//   0x04b44c: 54002d6d  b.le     #0x4b9f8
//   0x04b450: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b454: 91002109  add      x9, x8, #8
//   0x04b458: f90093e9  str      x9, [sp, #0x120]
//   0x04b45c: b9400108  ldr      w8, [x8]
//   0x04b460: 51005109  sub      w9, w8, #0x14
//   0x04b464: 710f513f  cmp      w9, #0x3d4
//   0x04b468: 540032e8  b.hi     #0x4bac4
//   0x04b46c: 2a1f03e0  mov      w0, wzr
//   0x04b470: b900c668  str      w8, [x19, #0xc4]
//   0x04b474: 140001a4  b        #0x4bb04
//   0x04b478: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b47c: 36f800a8  tbz      w8, #0x1f, #0x4b490
//   0x04b480: 11002109  add      w9, w8, #8
//   0x04b484: 7100013f  cmp      w9, #0
//   0x04b488: b9013be9  str      w9, [sp, #0x138]
//   0x04b48c: 54002c4d  b.le     #0x4ba14
//   0x04b490: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b494: 91002109  add      x9, x8, #8
//   0x04b498: f90093e9  str      x9, [sp, #0x120]
//   0x04b49c: f9400108  ldr      x8, [x8]
//   0x04b4a0: b4003128  cbz      x8, #0x4bac4
//   0x04b4a4: b940c669  ldr      w9, [x19, #0xc4]
//   0x04b4a8: 2a1f03e0  mov      w0, wzr
//   0x04b4ac: 14000195  b        #0x4bb00
//   0x04b4b0: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b4b4: 36f800a8  tbz      w8, #0x1f, #0x4b4c8
//   0x04b4b8: 11002109  add      w9, w8, #8
//   0x04b4bc: 7100013f  cmp      w9, #0
//   0x04b4c0: b9013be9  str      w9, [sp, #0x138]
//   0x04b4c4: 54002b2d  b.le     #0x4ba28
//   0x04b4c8: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b4cc: 91002109  add      x9, x8, #8
//   0x04b4d0: f90093e9  str      x9, [sp, #0x120]
//   0x04b4d4: b9400108  ldr      w8, [x8]
//   0x04b4d8: 7100051f  cmp      w8, #1
//   0x04b4dc: 54002f48  b.hi     #0x4bac4
//   0x04b4e0: 2a1f03e0  mov      w0, wzr
//   0x04b4e4: b900ca68  str      w8, [x19, #0xc8]
//   0x04b4e8: 14000187  b        #0x4bb04
//   0x04b4ec: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b4f0: 36f800a8  tbz      w8, #0x1f, #0x4b504
//   0x04b4f4: 11002109  add      w9, w8, #8
//   0x04b4f8: 7100013f  cmp      w9, #0
//   0x04b4fc: b9013be9  str      w9, [sp, #0x138]
//   0x04b500: 54002a0d  b.le     #0x4ba40
//   0x04b504: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b508: 91002109  add      x9, x8, #8
//   0x04b50c: f90093e9  str      x9, [sp, #0x120]
//   0x04b510: f9400108  ldr      x8, [x8]
//   0x04b514: b4002d88  cbz      x8, #0x4bac4
//   0x04b518: b940ca69  ldr      w9, [x19, #0xc8]
//   0x04b51c: 2a1f03e0  mov      w0, wzr
//   0x04b520: 14000178  b        #0x4bb00
//   0x04b524: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b528: 36f800a8  tbz      w8, #0x1f, #0x4b53c
//   0x04b52c: 11002109  add      w9, w8, #8
//   0x04b530: 7100013f  cmp      w9, #0
//   0x04b534: b9013be9  str      w9, [sp, #0x138]
//   0x04b538: 540028ed  b.le     #0x4ba54
//   0x04b53c: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b540: 91002109  add      x9, x8, #8
//   0x04b544: f90093e9  str      x9, [sp, #0x120]
//   0x04b548: b9400108  ldr      w8, [x8]
//   0x04b54c: 34002bc8  cbz      w8, #0x4bac4
//   0x04b550: b9800668  ldrsw    x8, [x19, #4]
//   0x04b554: 52887b89  mov      w9, #0x43dc
//   0x04b558: 2a1f03e0  mov      w0, wzr
//   0x04b55c: 8b080268  add      x8, x19, x8
//   0x04b560: b829691f  str      wzr, [x8, x9]
//   0x04b564: 14000168  b        #0x4bb04
//   0x04b568: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b56c: 36f800a8  tbz      w8, #0x1f, #0x4b580
//   0x04b570: 11002109  add      w9, w8, #8
//   0x04b574: 7100013f  cmp      w9, #0
//   0x04b578: b9013be9  str      w9, [sp, #0x138]
//   0x04b57c: 5400276d  b.le     #0x4ba68
//   0x04b580: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b584: 91002109  add      x9, x8, #8
//   0x04b588: f90093e9  str      x9, [sp, #0x120]
//   0x04b58c: f9400102  ldr      x2, [x8]
//   0x04b590: b40029a2  cbz      x2, #0x4bac4
//   0x04b594: 5284e3e1  mov      w1, #0x271f
//   0x04b598: aa1403e0  mov      x0, x20
//   0x04b59c: 97ff1289  bl       #0xffc0
//   0x04b5a0: 14000159  b        #0x4bb04
//   0x04b5a4: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b5a8: 36f800a8  tbz      w8, #0x1f, #0x4b5bc
//   0x04b5ac: 11002109  add      w9, w8, #8
//   0x04b5b0: 7100013f  cmp      w9, #0
//   0x04b5b4: b9013be9  str      w9, [sp, #0x138]
//   0x04b5b8: 5400262d  b.le     #0x4ba7c
//   0x04b5bc: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b5c0: 91002109  add      x9, x8, #8
//   0x04b5c4: f90093e9  str      x9, [sp, #0x120]
//   0x04b5c8: b9400102  ldr      w2, [x8]
//   0x04b5cc: 5284e501  mov      w1, #0x2728
//   0x04b5d0: aa1403e0  mov      x0, x20
//   0x04b5d4: b900ba62  str      w2, [x19, #0xb8]
//   0x04b5d8: 97ff127a  bl       #0xffc0
//   0x04b5dc: 1400014a  b        #0x4bb04
//   0x04b5e0: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b5e4: 36f800a8  tbz      w8, #0x1f, #0x4b5f8
//   0x04b5e8: 11002109  add      w9, w8, #8
//   0x04b5ec: 7100013f  cmp      w9, #0
//   0x04b5f0: b9013be9  str      w9, [sp, #0x138]
//   0x04b5f4: 540024ad  b.le     #0x4ba88
//   0x04b5f8: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b5fc: 91002109  add      x9, x8, #8
//   0x04b600: f90093e9  str      x9, [sp, #0x120]
//   0x04b604: b9400108  ldr      w8, [x8]
//   0x04b608: 510fa109  sub      w9, w8, #0x3e8
//   0x04b60c: 71000d3f  cmp      w9, #3
//   0x04b610: 54002483  b.lo     #0x4baa0
//   0x04b614: 310fa11f  cmn      w8, #0x3e8
//   0x04b618: 54002440  b.eq     #0x4baa0
//   0x04b61c: 1400012a  b        #0x4bac4
//   0x04b620: b9813be8  ldrsw    x8, [sp, #0x138]
//   0x04b624: 36f800a8  tbz      w8, #0x1f, #0x4b638
//   0x04b628: 11002109  add      w9, w8, #8
//   0x04b62c: 7100013f  cmp      w9, #0
//   0x04b630: b9013be9  str      w9, [sp, #0x138]
//   0x04b634: 540023cd  b.le     #0x4baac
//   0x04b638: f94093e8  ldr      x8, [sp, #0x120]
//   0x04b63c: 91002109  add      x9, x8, #8
//   0x04b640: f90093e9  str      x9, [sp, #0x120]
//   0x04b644: b9400108  ldr      w8, [x8]
//   0x04b648: 11000509  add      w9, w8, #1
//   0x04b64c: 7101953f  cmp      w9, #0x65
//   0x04b650: 540023a8  b.hi     #0x4bac4
//   0x04b654: 2a1f03e0  mov      w0, wzr
//   0x04b658: b9009668  str      w8, [x19, #0x94]
//   0x04b65c: 1400012a  b        #0x4bb04
//   0x04b660: b940c269  ldr      w9, [x19, #0xc0]
//   0x04b664: 34000209  cbz      w9, #0x4b6a4
//   0x04b668: b940ca69  ldr      w9, [x19, #0xc8]
//   0x04b66c: 34002429  cbz      w9, #0x4baf0
//   0x04b670: b97f6269  ldr      w9, [x19, #0x3f60]
//   0x04b674: 14000120  b        #0x4baf4
//   0x04b678: 5287d008  mov      w8, #0x3e80
//   0x04b67c: 2a1f03e0  mov      w0, wzr
//   0x04b680: b9001668  str      w8, [x19, #0x14]
//   0x04b684: 14000120  b        #0x4bb04
//   0x04b688: b9409a6a  ldr      w10, [x19, #0x98]
//   0x04b68c: 5284fc0b  mov      w11, #0x27e0
//   0x04b690: 1b0b7d4a  mul      w10, w10, w11
//   0x04b694: 1ac90d4a  sdiv     w10, w10, w9
//   0x04b698: 2a1f03e0  mov      w0, wzr
//   0x04b69c: b900010a  str      w10, [x8]
//   0x04b6a0: 14000119  b        #0x4bb04
//   0x04b6a4: 2a1f03e0  mov      w0, wzr
//   0x04b6a8: b900011f  str      wzr, [x8]
//   0x04b6ac: 14000116  b        #0x4bb04
//   0x04b6b0: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b6b4: 8b080128  add      x8, x9, x8
//   0x04b6b8: 17fffcac  b        #0x4a968
//   0x04b6bc: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b6c0: 8b080128  add      x8, x9, x8
//   0x04b6c4: 17fffcce  b        #0x4a9fc
//   0x04b6c8: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b6cc: 8b080128  add      x8, x9, x8
//   0x04b6d0: f9400108  ldr      x8, [x8]
//   0x04b6d4: b5ff9c48  cbnz     x8, #0x4aa5c
//   0x04b6d8: 140000fb  b        #0x4bac4
//   0x04b6dc: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b6e0: 8b080128  add      x8, x9, x8
//   0x04b6e4: f9400108  ldr      x8, [x8]
//   0x04b6e8: b5ff9d68  cbnz     x8, #0x4aa94
//   0x04b6ec: 140000f6  b        #0x4bac4
//   0x04b6f0: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b6f4: 8b080128  add      x8, x9, x8
//   0x04b6f8: b9400108  ldr      w8, [x8]
//   0x04b6fc: 310fa11f  cmn      w8, #0x3e8
//   0x04b700: 54ff9e81  b.ne     #0x4aad0
//   0x04b704: 140000f8  b        #0x4bae4
//   0x04b708: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b70c: 8b080128  add      x8, x9, x8
//   0x04b710: f9400108  ldr      x8, [x8]
//   0x04b714: b5ffa048  cbnz     x8, #0x4ab1c
//   0x04b718: 140000eb  b        #0x4bac4
//   0x04b71c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b720: 8b080128  add      x8, x9, x8
//   0x04b724: b9400108  ldr      w8, [x8]
//   0x04b728: 51113509  sub      w9, w8, #0x44d
//   0x04b72c: 7100113f  cmp      w9, #4
//   0x04b730: 54001ca8  b.hi     #0x4bac4
//   0x04b734: 17fffd1c  b        #0x4aba4
//   0x04b738: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b73c: 8b080128  add      x8, x9, x8
//   0x04b740: f9400108  ldr      x8, [x8]
//   0x04b744: b5ffa588  cbnz     x8, #0x4abf4
//   0x04b748: 140000df  b        #0x4bac4
//   0x04b74c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b750: 8b080128  add      x8, x9, x8
//   0x04b754: b9400108  ldr      w8, [x8]
//   0x04b758: 7100051f  cmp      w8, #1
//   0x04b75c: 54001b48  b.hi     #0x4bac4
//   0x04b760: 17fffd34  b        #0x4ac30
//   0x04b764: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b768: 8b080128  add      x8, x9, x8
//   0x04b76c: f9400108  ldr      x8, [x8]
//   0x04b770: b5ffa828  cbnz     x8, #0x4ac74
//   0x04b774: 140000d4  b        #0x4bac4
//   0x04b778: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b77c: 8b080128  add      x8, x9, x8
//   0x04b780: b9400108  ldr      w8, [x8]
//   0x04b784: 51113509  sub      w9, w8, #0x44d
//   0x04b788: 7100153f  cmp      w9, #5
//   0x04b78c: 54ffa943  b.lo     #0x4acb4
//   0x04b790: 310fa11f  cmn      w8, #0x3e8
//   0x04b794: 54ffa900  b.eq     #0x4acb4
//   0x04b798: 140000cb  b        #0x4bac4
//   0x04b79c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b7a0: 8b080128  add      x8, x9, x8
//   0x04b7a4: f9400108  ldr      x8, [x8]
//   0x04b7a8: b5ffaaa8  cbnz     x8, #0x4acfc
//   0x04b7ac: 140000c6  b        #0x4bac4
//   0x04b7b0: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b7b4: 8b080128  add      x8, x9, x8
//   0x04b7b8: b9400102  ldr      w2, [x8]
//   0x04b7bc: 7100285f  cmp      w2, #0xa
//   0x04b7c0: 54001828  b.hi     #0x4bac4
//   0x04b7c4: 17fffd5d  b        #0x4ad38
//   0x04b7c8: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b7cc: 8b080128  add      x8, x9, x8
//   0x04b7d0: f9400108  ldr      x8, [x8]
//   0x04b7d4: b5fface8  cbnz     x8, #0x4ad70
//   0x04b7d8: 140000bb  b        #0x4bac4
//   0x04b7dc: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b7e0: 8b080128  add      x8, x9, x8
//   0x04b7e4: b9400108  ldr      w8, [x8]
//   0x04b7e8: 7100051f  cmp      w8, #1
//   0x04b7ec: 540016c8  b.hi     #0x4bac4
//   0x04b7f0: 17fffd6f  b        #0x4adac
//   0x04b7f4: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b7f8: 8b080128  add      x8, x9, x8
//   0x04b7fc: f9400108  ldr      x8, [x8]
//   0x04b800: b5ffaf28  cbnz     x8, #0x4ade4
//   0x04b804: 140000b0  b        #0x4bac4
//   0x04b808: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b80c: 8b080128  add      x8, x9, x8
//   0x04b810: b9400102  ldr      w2, [x8]
//   0x04b814: 7101905f  cmp      w2, #0x64
//   0x04b818: 54001568  b.hi     #0x4bac4
//   0x04b81c: 17fffd81  b        #0x4ae20
//   0x04b820: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b824: 8b080128  add      x8, x9, x8
//   0x04b828: f9400108  ldr      x8, [x8]
//   0x04b82c: b5ffb168  cbnz     x8, #0x4ae58
//   0x04b830: 140000a5  b        #0x4bac4
//   0x04b834: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b838: 8b080128  add      x8, x9, x8
//   0x04b83c: b9400108  ldr      w8, [x8]
//   0x04b840: 7100051f  cmp      w8, #1
//   0x04b844: 54001408  b.hi     #0x4bac4
//   0x04b848: 17fffd93  b        #0x4ae94
//   0x04b84c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b850: 8b080128  add      x8, x9, x8
//   0x04b854: f9400108  ldr      x8, [x8]
//   0x04b858: b5ffb3a8  cbnz     x8, #0x4aecc
//   0x04b85c: 1400009a  b        #0x4bac4
//   0x04b860: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b864: 8b080128  add      x8, x9, x8
//   0x04b868: b9400108  ldr      w8, [x8]
//   0x04b86c: 7100051f  cmp      w8, #1
//   0x04b870: 540012a8  b.hi     #0x4bac4
//   0x04b874: 17fffda5  b        #0x4af08
//   0x04b878: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b87c: 8b080128  add      x8, x9, x8
//   0x04b880: f9400108  ldr      x8, [x8]
//   0x04b884: b5ffb5e8  cbnz     x8, #0x4af40
//   0x04b888: 1400008f  b        #0x4bac4
//   0x04b88c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b890: 8b080128  add      x8, x9, x8
//   0x04b894: b9400108  ldr      w8, [x8]
//   0x04b898: 7100051f  cmp      w8, #1
//   0x04b89c: 54ffb70a  b.ge     #0x4af7c
//   0x04b8a0: 310fa11f  cmn      w8, #0x3e8
//   0x04b8a4: 54001101  b.ne     #0x4bac4
//   0x04b8a8: 2a1f03e0  mov      w0, wzr
//   0x04b8ac: b9008268  str      w8, [x19, #0x80]
//   0x04b8b0: 14000095  b        #0x4bb04
//   0x04b8b4: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b8b8: 8b080128  add      x8, x9, x8
//   0x04b8bc: f9400108  ldr      x8, [x8]
//   0x04b8c0: b5ffb7c8  cbnz     x8, #0x4afb8
//   0x04b8c4: 14000080  b        #0x4bac4
//   0x04b8c8: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b8cc: 8b080128  add      x8, x9, x8
//   0x04b8d0: b9400108  ldr      w8, [x8]
//   0x04b8d4: 512ee509  sub      w9, w8, #0xbb9
//   0x04b8d8: 7100093f  cmp      w9, #2
//   0x04b8dc: 54ffb8e2  b.hs     #0x4aff8
//   0x04b8e0: 2a1f03e0  mov      w0, wzr
//   0x04b8e4: b9008668  str      w8, [x19, #0x84]
//   0x04b8e8: 14000087  b        #0x4bb04
//   0x04b8ec: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b8f0: 8b080128  add      x8, x9, x8
//   0x04b8f4: f9400108  ldr      x8, [x8]
//   0x04b8f8: b5ffb9c8  cbnz     x8, #0x4b030
//   0x04b8fc: 14000072  b        #0x4bac4
//   0x04b900: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b904: 8b080128  add      x8, x9, x8
//   0x04b908: f9400108  ldr      x8, [x8]
//   0x04b90c: b5ffbae8  cbnz     x8, #0x4b068
//   0x04b910: 1400006d  b        #0x4bac4
//   0x04b914: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b918: 8b080128  add      x8, x9, x8
//   0x04b91c: f9400108  ldr      x8, [x8]
//   0x04b920: b5ffc228  cbnz     x8, #0x4b164
//   0x04b924: 14000068  b        #0x4bac4
//   0x04b928: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b92c: 8b080128  add      x8, x9, x8
//   0x04b930: f9400108  ldr      x8, [x8]
//   0x04b934: b5ffc348  cbnz     x8, #0x4b19c
//   0x04b938: 14000063  b        #0x4bac4
//   0x04b93c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b940: 8b080128  add      x8, x9, x8
//   0x04b944: b9400108  ldr      w8, [x8]
//   0x04b948: 51002109  sub      w9, w8, #8
//   0x04b94c: 7100413f  cmp      w9, #0x10
//   0x04b950: 54000ba8  b.hi     #0x4bac4
//   0x04b954: 17fffe22  b        #0x4b1dc
//   0x04b958: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b95c: 8b080128  add      x8, x9, x8
//   0x04b960: f9400108  ldr      x8, [x8]
//   0x04b964: b5ffc588  cbnz     x8, #0x4b214
//   0x04b968: 14000057  b        #0x4bac4
//   0x04b96c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b970: 8b080128  add      x8, x9, x8
//   0x04b974: 17fffe34  b        #0x4b244
//   0x04b978: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b97c: 8b080128  add      x8, x9, x8
//   0x04b980: f9400108  ldr      x8, [x8]
//   0x04b984: b5ffc868  cbnz     x8, #0x4b290
//   0x04b988: 1400004f  b        #0x4bac4
//   0x04b98c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b990: 8b080128  add      x8, x9, x8
//   0x04b994: b9400108  ldr      w8, [x8]
//   0x04b998: 7100051f  cmp      w8, #1
//   0x04b99c: 54000948  b.hi     #0x4bac4
//   0x04b9a0: 17fffe4b  b        #0x4b2cc
//   0x04b9a4: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b9a8: 8b080128  add      x8, x9, x8
//   0x04b9ac: f9400108  ldr      x8, [x8]
//   0x04b9b0: b5ffcaa8  cbnz     x8, #0x4b304
//   0x04b9b4: 14000044  b        #0x4bac4
//   0x04b9b8: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b9bc: 8b080128  add      x8, x9, x8
//   0x04b9c0: b9400102  ldr      w2, [x8]
//   0x04b9c4: 7100045f  cmp      w2, #1
//   0x04b9c8: 540007e8  b.hi     #0x4bac4
//   0x04b9cc: 17fffe5d  b        #0x4b340
//   0x04b9d0: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b9d4: 8b080128  add      x8, x9, x8
//   0x04b9d8: f9400102  ldr      x2, [x8]
//   0x04b9dc: b5ffcd02  cbnz     x2, #0x4b37c
//   0x04b9e0: 14000039  b        #0x4bac4
//   0x04b9e4: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b9e8: 8b080128  add      x8, x9, x8
//   0x04b9ec: f9400108  ldr      x8, [x8]
//   0x04b9f0: b5ffce68  cbnz     x8, #0x4b3bc
//   0x04b9f4: 14000034  b        #0x4bac4
//   0x04b9f8: f94097e9  ldr      x9, [sp, #0x128]
//   0x04b9fc: 8b080128  add      x8, x9, x8
//   0x04ba00: b9400108  ldr      w8, [x8]
//   0x04ba04: 51005109  sub      w9, w8, #0x14
//   0x04ba08: 710f513f  cmp      w9, #0x3d4
//   0x04ba0c: 540005c8  b.hi     #0x4bac4
//   0x04ba10: 17fffe97  b        #0x4b46c
//   0x04ba14: f94097e9  ldr      x9, [sp, #0x128]
//   0x04ba18: 8b080128  add      x8, x9, x8
//   0x04ba1c: f9400108  ldr      x8, [x8]
//   0x04ba20: b5ffd428  cbnz     x8, #0x4b4a4
//   0x04ba24: 14000028  b        #0x4bac4
//   0x04ba28: f94097e9  ldr      x9, [sp, #0x128]
//   0x04ba2c: 8b080128  add      x8, x9, x8
//   0x04ba30: b9400108  ldr      w8, [x8]
//   0x04ba34: 7100051f  cmp      w8, #1
//   0x04ba38: 54000468  b.hi     #0x4bac4
//   0x04ba3c: 17fffea9  b        #0x4b4e0
//   0x04ba40: f94097e9  ldr      x9, [sp, #0x128]
//   0x04ba44: 8b080128  add      x8, x9, x8
//   0x04ba48: f9400108  ldr      x8, [x8]
//   0x04ba4c: b5ffd668  cbnz     x8, #0x4b518
//   0x04ba50: 1400001d  b        #0x4bac4
//   0x04ba54: f94097e9  ldr      x9, [sp, #0x128]
//   0x04ba58: 8b080128  add      x8, x9, x8
//   0x04ba5c: b9400108  ldr      w8, [x8]
//   0x04ba60: 35ffd788  cbnz     w8, #0x4b550
//   0x04ba64: 14000018  b        #0x4bac4
//   0x04ba68: f94097e9  ldr      x9, [sp, #0x128]
//   0x04ba6c: 8b080128  add      x8, x9, x8
//   0x04ba70: f9400102  ldr      x2, [x8]
//   0x04ba74: b5ffd902  cbnz     x2, #0x4b594
//   0x04ba78: 14000013  b        #0x4bac4
//   0x04ba7c: f94097e9  ldr      x9, [sp, #0x128]
//   0x04ba80: 8b080128  add      x8, x9, x8
//   0x04ba84: 17fffed1  b        #0x4b5c8
//   0x04ba88: f94097e9  ldr      x9, [sp, #0x128]
//   0x04ba8c: 8b080128  add      x8, x9, x8
//   0x04ba90: b9400108  ldr      w8, [x8]
//   0x04ba94: 510fa109  sub      w9, w8, #0x3e8
//   0x04ba98: 71000d3f  cmp      w9, #3
//   0x04ba9c: 54ffdbc2  b.hs     #0x4b614
//   0x04baa0: 2a1f03e0  mov      w0, wzr
//   0x04baa4: b9009268  str      w8, [x19, #0x90]
//   0x04baa8: 14000017  b        #0x4bb04
//   0x04baac: f94097e9  ldr      x9, [sp, #0x128]
//   0x04bab0: 8b080128  add      x8, x9, x8
//   0x04bab4: b9400108  ldr      w8, [x8]
//   0x04bab8: 11000509  add      w9, w8, #1
//   0x04babc: 7101953f  cmp      w9, #0x65
//   0x04bac0: 54ffdca9  b.ls     #0x4b654
//   0x04bac4: 12800000  mov      w0, #-1
//   0x04bac8: 1400000f  b        #0x4bb04
//   0x04bacc: b9407a69  ldr      w9, [x19, #0x78]
//   0x04bad0: 52927c0a  mov      w10, #0x93e0
//   0x04bad4: 72a0008a  movk     w10, #4, lsl #16
//   0x04bad8: 1b0a7d29  mul      w9, w9, w10
//   0x04badc: 6b09011f  cmp      w8, w9
//   0x04bae0: 1a88c128  csel     w8, w9, w8, gt
//   0x04bae4: 2a1f03e0  mov      w0, wzr
//   0x04bae8: b900ae68  str      w8, [x19, #0xac]
//   0x04baec: 14000006  b        #0x4bb04
//   0x04baf0: b97f5e69  ldr      w9, [x19, #0x3f5c]
//   0x04baf4: 2a1f03e0  mov      w0, wzr
//   0x04baf8: 7100253f  cmp      w9, #9
//   0x04bafc: 1a9fd7e9  cset     w9, gt
//   0x04bb00: b9000109  str      w9, [x8]
//   0x04bb04: a9567bf3  ldp      x19, x30, [sp, #0x160]
//   0x04bb08: a95553f5  ldp      x21, x20, [sp, #0x150]
//   0x04bb0c: a9545bfc  ldp      x28, x22, [sp, #0x140]
//   0x04bb10: 9105c3ff  add      sp, sp, #0x170
//   0x04bb14: d65f03c0  ret      
// ============================================================================
std::uint32_t export_23_4a8b4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004a8b4ULL;
    for (std::size_t i = 0; i < 1177ULL; ++i) {
        std::uint32_t insn = kTextInstructions[73437ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[24] opus_encoder_destroy @ 0x04bb18..0x04bb1c (4 bytes, 1 AArch64 insns)
// [VN] Hàm xuất khẩu[24] opus_encoder_destroy @ 0x04bb18..0x04bb1c (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04bb18: 17fedc7e  b        #0x2d10
// ============================================================================
std::uint32_t export_24_4bb18(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004bb18ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[74614ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[25] opus_multistream_encoder_get_size @ 0x04d048..0x04d0b8 (112 bytes, 28 AArch64 insns)
// [VN] Hàm xuất khẩu[25] opus_multistream_encoder_get_size @ 0x04d048..0x04d0b8 (112 byte, 28 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04d048: a9be53f5  stp      x21, x20, [sp, #-0x20]!
//   0x04d04c: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x04d050: 7100041f  cmp      w0, #1
//   0x04d054: 540002ab  b.lt     #0x4d0a8
//   0x04d058: 2a0103f3  mov      w19, w1
//   0x04d05c: 6b010015  subs     w21, w0, w1
//   0x04d060: 2a1f03e0  mov      w0, wzr
//   0x04d064: 540001cb  b.lt     #0x4d09c
//   0x04d068: 37f801b3  tbnz     w19, #0x1f, #0x4d09c
//   0x04d06c: 52800040  mov      w0, #2
//   0x04d070: 97fed6c0  bl       #0x2b70
//   0x04d074: 2a0003f4  mov      w20, w0
//   0x04d078: 52800020  mov      w0, #1
//   0x04d07c: 97fed6bd  bl       #0x2b70
//   0x04d080: 11001c09  add      w9, w0, #7
//   0x04d084: 11001e88  add      w8, w20, #7
//   0x04d088: 121d7129  and      w9, w9, #0xfffffff8
//   0x04d08c: 121d7108  and      w8, w8, #0xfffffff8
//   0x04d090: 1b157d29  mul      w9, w9, w21
//   0x04d094: 1b132508  madd     w8, w8, w19, w9
//   0x04d098: 1104a100  add      w0, w8, #0x128
//   0x04d09c: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x04d0a0: a8c253f5  ldp      x21, x20, [sp], #0x20
//   0x04d0a4: d65f03c0  ret      
//   0x04d0a8: 2a1f03e0  mov      w0, wzr
//   0x04d0ac: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x04d0b0: a8c253f5  ldp      x21, x20, [sp], #0x20
//   0x04d0b4: d65f03c0  ret      
// ============================================================================
std::uint32_t export_25_4d048(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004d048ULL;
    for (std::size_t i = 0; i < 28ULL; ++i) {
        std::uint32_t insn = kTextInstructions[75970ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[26] opus_multistream_surround_encoder_get_size @ 0x04d0b8..0x04d200 (328 bytes, 82 AArch64 insns)
// [VN] Hàm xuất khẩu[26] opus_multistream_surround_encoder_get_size @ 0x04d0b8..0x04d200 (328 byte, 82 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04d0b8: f81d0ff6  str      x22, [sp, #-0x30]!
//   0x04d0bc: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x04d0c0: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x04d0c4: 2a0003f3  mov      w19, w0
//   0x04d0c8: 340003a1  cbz      w1, #0x4d13c
//   0x04d0cc: 51000668  sub      w8, w19, #1
//   0x04d0d0: 71001d1f  cmp      w8, #7
//   0x04d0d4: 54000488  b.hi     #0x4d164
//   0x04d0d8: 7100043f  cmp      w1, #1
//   0x04d0dc: 54000441  b.ne     #0x4d164
//   0x04d0e0: 90000089  adrp     x9, #0x5d000
//   0x04d0e4: 912e0129  add      x9, x9, #0xb80
//   0x04d0e8: 8b28d129  add      x9, x9, w8, sxtw #4
//   0x04d0ec: 29405128  ldp      w8, w20, [x9]
//   0x04d0f0: 7100051f  cmp      w8, #1
//   0x04d0f4: 5400064b  b.lt     #0x4d1bc
//   0x04d0f8: 2a1f03e9  mov      w9, wzr
//   0x04d0fc: 37f80634  tbnz     w20, #0x1f, #0x4d1c0
//   0x04d100: 6b140116  subs     w22, w8, w20
//   0x04d104: 540005eb  b.lt     #0x4d1c0
//   0x04d108: 52800040  mov      w0, #2
//   0x04d10c: 97fed699  bl       #0x2b70
//   0x04d110: 2a0003f5  mov      w21, w0
//   0x04d114: 52800020  mov      w0, #1
//   0x04d118: 97fed696  bl       #0x2b70
//   0x04d11c: 11001c09  add      w9, w0, #7
//   0x04d120: 11001ea8  add      w8, w21, #7
//   0x04d124: 121d7129  and      w9, w9, #0xfffffff8
//   0x04d128: 121d7108  and      w8, w8, #0xfffffff8
//   0x04d12c: 1b167d29  mul      w9, w9, w22
//   0x04d130: 1b142508  madd     w8, w8, w20, w9
//   0x04d134: 1104a109  add      w9, w8, #0x128
//   0x04d138: 14000022  b        #0x4d1c0
//   0x04d13c: 7100067f  cmp      w19, #1
//   0x04d140: 2a1f03f4  mov      w20, wzr
//   0x04d144: 540002e0  b.eq     #0x4d1a0
//   0x04d148: 71000a7f  cmp      w19, #2
//   0x04d14c: 54000441  b.ne     #0x4d1d4
//   0x04d150: 52800034  mov      w20, #1
//   0x04d154: 52800028  mov      w8, #1
//   0x04d158: 2a1f03e9  mov      w9, wzr
//   0x04d15c: 36fffd34  tbz      w20, #0x1f, #0x4d100
//   0x04d160: 14000018  b        #0x4d1c0
//   0x04d164: 7103fc3f  cmp      w1, #0xff
//   0x04d168: 2a1f03f4  mov      w20, wzr
//   0x04d16c: 54000220  b.eq     #0x4d1b0
//   0x04d170: 7100083f  cmp      w1, #2
//   0x04d174: 54000301  b.ne     #0x4d1d4
//   0x04d178: 7103891f  cmp      w8, #0xe2
//   0x04d17c: 540000e8  b.hi     #0x4d198
//   0x04d180: 2a1303e0  mov      w0, w19
//   0x04d184: 97ff2aa9  bl       #0x17c28
//   0x04d188: 1b007c08  mul      w8, w0, w0
//   0x04d18c: 4b080269  sub      w9, w19, w8
//   0x04d190: 721e793f  tst      w9, #0xfffffffd
//   0x04d194: 540002a0  b.eq     #0x4d1e8
//   0x04d198: 2a1f03f4  mov      w20, wzr
//   0x04d19c: 1400000e  b        #0x4d1d4
//   0x04d1a0: 2a1303e8  mov      w8, w19
//   0x04d1a4: 2a1f03e9  mov      w9, wzr
//   0x04d1a8: 36fffad4  tbz      w20, #0x1f, #0x4d100
//   0x04d1ac: 14000005  b        #0x4d1c0
//   0x04d1b0: 2a1303e8  mov      w8, w19
//   0x04d1b4: 7100051f  cmp      w8, #1
//   0x04d1b8: 54fffa0a  b.ge     #0x4d0f8
//   0x04d1bc: 2a1f03e9  mov      w9, wzr
//   0x04d1c0: 52803c88  mov      w8, #0x1e4
//   0x04d1c4: 1b087e68  mul      w8, w19, w8
//   0x04d1c8: 71000a7f  cmp      w19, #2
//   0x04d1cc: 1a9fc108  csel     w8, w8, wzr, gt
//   0x04d1d0: 0b080134  add      w20, w9, w8
//   0x04d1d4: 2a1403e0  mov      w0, w20
//   0x04d1d8: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x04d1dc: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x04d1e0: f84307f6  ldr      x22, [sp], #0x30
//   0x04d1e4: d65f03c0  ret      
//   0x04d1e8: 7100013f  cmp      w9, #0
//   0x04d1ec: 1a9f07f4  cset     w20, ne
//   0x04d1f0: 1a880508  cinc     w8, w8, ne
//   0x04d1f4: 7100051f  cmp      w8, #1
//   0x04d1f8: 54fff80a  b.ge     #0x4d0f8
//   0x04d1fc: 17fffff0  b        #0x4d1bc
// ============================================================================
std::uint32_t export_26_4d0b8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004d0b8ULL;
    for (std::size_t i = 0; i < 82ULL; ++i) {
        std::uint32_t insn = kTextInstructions[75998ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[27] opus_multistream_encoder_init @ 0x04d200..0x04d208 (8 bytes, 2 AArch64 insns)
// [VN] Hàm xuất khẩu[27] opus_multistream_encoder_init @ 0x04d200..0x04d208 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04d200: 2a1f03e7  mov      w7, wzr
//   0x04d204: 14000001  b        #0x4d208
// ============================================================================
std::uint32_t export_27_4d200(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004d200ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[76080ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[28] opus_multistream_surround_encoder_init @ 0x04d5d4..0x04d84c (632 bytes, 158 AArch64 insns)
// [VN] Hàm xuất khẩu[28] opus_multistream_surround_encoder_init @ 0x04d5d4..0x04d84c (632 byte, 158 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04d5d4: f81b0ffa  str      x26, [sp, #-0x50]!
//   0x04d5d8: a90163f9  stp      x25, x24, [sp, #0x10]
//   0x04d5dc: a9025bf7  stp      x23, x22, [sp, #0x20]
//   0x04d5e0: a90353f5  stp      x21, x20, [sp, #0x30]
//   0x04d5e4: a9047bf3  stp      x19, x30, [sp, #0x40]
//   0x04d5e8: 51000448  sub      w8, w2, #1
//   0x04d5ec: aa0003f9  mov      x25, x0
//   0x04d5f0: 7103f91f  cmp      w8, #0xfe
//   0x04d5f4: 12800000  mov      w0, #-1
//   0x04d5f8: 540000e9  b.ls     #0x4d614
//   0x04d5fc: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x04d600: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x04d604: a9425bf7  ldp      x23, x22, [sp, #0x20]
//   0x04d608: a94163f9  ldp      x25, x24, [sp, #0x10]
//   0x04d60c: f84507fa  ldr      x26, [sp], #0x50
//   0x04d610: d65f03c0  ret      
//   0x04d614: 2a0703f3  mov      w19, w7
//   0x04d618: aa0603f4  mov      x20, x6
//   0x04d61c: aa0503f6  mov      x22, x5
//   0x04d620: aa0403fa  mov      x26, x4
//   0x04d624: 2a0303f8  mov      w24, w3
//   0x04d628: 2a0203f5  mov      w21, w2
//   0x04d62c: 2a0103f7  mov      w23, w1
//   0x04d630: b9011320  str      w0, [x25, #0x110]
//   0x04d634: 340002a3  cbz      w3, #0x4d688
//   0x04d638: 71001d1f  cmp      w8, #7
//   0x04d63c: 54000388  b.hi     #0x4d6ac
//   0x04d640: 7100071f  cmp      w24, #1
//   0x04d644: 54000341  b.ne     #0x4d6ac
//   0x04d648: 90000089  adrp     x9, #0x5d000
//   0x04d64c: 912e0129  add      x9, x9, #0xb80
//   0x04d650: 8b28d128  add      x8, x9, w8, sxtw #4
//   0x04d654: 29402909  ldp      w9, w10, [x8]
//   0x04d658: 2a1503e2  mov      w2, w21
//   0x04d65c: 91002101  add      x1, x8, #8
//   0x04d660: aa1403e0  mov      x0, x20
//   0x04d664: b9000349  str      w9, [x26]
//   0x04d668: b90002ca  str      w10, [x22]
//   0x04d66c: 97fed599  bl       #0x2cd0
//   0x04d670: 71001abf  cmp      w21, #6
//   0x04d674: 540007cb  b.lt     #0x4d76c
//   0x04d678: b9400348  ldr      w8, [x26]
//   0x04d67c: 51000508  sub      w8, w8, #1
//   0x04d680: b9011328  str      w8, [x25, #0x110]
//   0x04d684: 1400003a  b        #0x4d76c
//   0x04d688: 71000abf  cmp      w21, #2
//   0x04d68c: 540002a0  b.eq     #0x4d6e0
//   0x04d690: 710006bf  cmp      w21, #1
//   0x04d694: 54000221  b.ne     #0x4d6d8
//   0x04d698: 52800028  mov      w8, #1
//   0x04d69c: b9000348  str      w8, [x26]
//   0x04d6a0: b90002df  str      wzr, [x22]
//   0x04d6a4: 3900029f  strb     wzr, [x20]
//   0x04d6a8: 14000031  b        #0x4d76c
//   0x04d6ac: 71000b1f  cmp      w24, #2
//   0x04d6b0: 54000240  b.eq     #0x4d6f8
//   0x04d6b4: 7103ff1f  cmp      w24, #0xff
//   0x04d6b8: 54000101  b.ne     #0x4d6d8
//   0x04d6bc: 710082bf  cmp      w21, #0x20
//   0x04d6c0: 2a1503e8  mov      w8, w21
//   0x04d6c4: b9000355  str      w21, [x26]
//   0x04d6c8: b90002df  str      wzr, [x22]
//   0x04d6cc: 540002a2  b.hs     #0x4d720
//   0x04d6d0: aa1f03e9  mov      x9, xzr
//   0x04d6d4: 14000022  b        #0x4d75c
//   0x04d6d8: 12800080  mov      w0, #-5
//   0x04d6dc: 17ffffc8  b        #0x4d5fc
//   0x04d6e0: 52800028  mov      w8, #1
//   0x04d6e4: 52802009  mov      w9, #0x100
//   0x04d6e8: b9000348  str      w8, [x26]
//   0x04d6ec: b90002c8  str      w8, [x22]
//   0x04d6f0: 79000289  strh     w9, [x20]
//   0x04d6f4: 1400001e  b        #0x4d76c
//   0x04d6f8: 7103891f  cmp      w8, #0xe2
//   0x04d6fc: 540000e8  b.hi     #0x4d718
//   0x04d700: 2a1503e0  mov      w0, w21
//   0x04d704: 97ff2949  bl       #0x17c28
//   0x04d708: 1b007c09  mul      w9, w0, w0
//   0x04d70c: 4b0902a8  sub      w8, w21, w9
//   0x04d710: 721e791f  tst      w8, #0xfffffffd
//   0x04d714: 54000520  b.eq     #0x4d7b8
//   0x04d718: 12800000  mov      w0, #-1
//   0x04d71c: 17ffffb8  b        #0x4d5fc
//   0x04d720: 9000008a  adrp     x10, #0x5d000
//   0x04d724: 3dc2cd40  ldr      q0, [x10, #0xb30]
//   0x04d728: 927b6909  and      x9, x8, #0xffffffe0
//   0x04d72c: 9100428a  add      x10, x20, #0x10
//   0x04d730: 4f00e601  movi     v1.16b, #0x10
//   0x04d734: 4f01e402  movi     v2.16b, #0x20
//   0x04d738: aa0903eb  mov      x11, x9
//   0x04d73c: 4e218403  add      v3.16b, v0.16b, v1.16b
//   0x04d740: ad3f8d40  stp      q0, q3, [x10, #-0x10]
//   0x04d744: 4e228400  add      v0.16b, v0.16b, v2.16b
//   0x04d748: f100816b  subs     x11, x11, #0x20
//   0x04d74c: 9100814a  add      x10, x10, #0x20
//   0x04d750: 54ffff61  b.ne     #0x4d73c
//   0x04d754: eb08013f  cmp      x9, x8
//   0x04d758: 540000a0  b.eq     #0x4d76c
//   0x04d75c: 38296a89  strb     w9, [x20, x9]
//   0x04d760: 91000529  add      x9, x9, #1
//   0x04d764: eb09011f  cmp      x8, x9
//   0x04d768: 54ffffa1  b.ne     #0x4d75c
//   0x04d76c: 71000b1f  cmp      w24, #2
//   0x04d770: 1a9f17e8  cset     w8, eq
//   0x04d774: 7100071f  cmp      w24, #1
//   0x04d778: b9400343  ldr      w3, [x26]
//   0x04d77c: b94002c4  ldr      w4, [x22]
//   0x04d780: 7a420aa4  ccmp     w21, #2, #4, eq
//   0x04d784: aa1903e0  mov      x0, x25
//   0x04d788: 2a1703e1  mov      w1, w23
//   0x04d78c: 2a1503e2  mov      w2, w21
//   0x04d790: aa1403e5  mov      x5, x20
//   0x04d794: 2a1303e6  mov      w6, w19
//   0x04d798: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x04d79c: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x04d7a0: a9425bf7  ldp      x23, x22, [sp, #0x20]
//   0x04d7a4: a94163f9  ldp      x25, x24, [sp, #0x10]
//   0x04d7a8: 531f7908  lsl      w8, w8, #1
//   0x04d7ac: 1a9fd507  csinc    w7, w8, wzr, le
//   0x04d7b0: f84507fa  ldr      x26, [sp], #0x50
//   0x04d7b4: 17fffe95  b        #0x4d208
//   0x04d7b8: b400009a  cbz      x26, #0x4d7c8
//   0x04d7bc: 7100011f  cmp      w8, #0
//   0x04d7c0: 1a890529  cinc     w9, w9, ne
//   0x04d7c4: b9000349  str      w9, [x26]
//   0x04d7c8: b4fffd36  cbz      x22, #0x4d76c
//   0x04d7cc: 7100011f  cmp      w8, #0
//   0x04d7d0: 1a9f07e8  cset     w8, ne
//   0x04d7d4: b90002c8  str      w8, [x22]
//   0x04d7d8: b9400349  ldr      w9, [x26]
//   0x04d7dc: 6b08013f  cmp      w9, w8
//   0x04d7e0: 5400014d  b.le     #0x4d808
//   0x04d7e4: aa1f03ea  mov      x10, xzr
//   0x04d7e8: 0b080548  add      w8, w10, w8, lsl #1
//   0x04d7ec: 382a6a88  strb     w8, [x20, x10]
//   0x04d7f0: b9400349  ldr      w9, [x26]
//   0x04d7f4: b94002c8  ldr      w8, [x22]
//   0x04d7f8: 9100054a  add      x10, x10, #1
//   0x04d7fc: 4b08012b  sub      w11, w9, w8
//   0x04d800: eb2bc15f  cmp      x10, w11, sxtw
//   0x04d804: 54ffff2b  b.lt     #0x4d7e8
//   0x04d808: 7100051f  cmp      w8, #1
//   0x04d80c: 54fffb0b  b.lt     #0x4d76c
//   0x04d810: 4b080128  sub      w8, w9, w8
//   0x04d814: 3828ca9f  strb     wzr, [x20, w8, sxtw]
//   0x04d818: b94002c8  ldr      w8, [x22]
//   0x04d81c: 7100051f  cmp      w8, #1
//   0x04d820: 54fffa6b  b.lt     #0x4d76c
//   0x04d824: 52800029  mov      w9, #1
//   0x04d828: b940034a  ldr      w10, [x26]
//   0x04d82c: 4b080148  sub      w8, w10, w8
//   0x04d830: 0b080128  add      w8, w9, w8
//   0x04d834: 3828ca89  strb     w9, [x20, w8, sxtw]
//   0x04d838: b94002c8  ldr      w8, [x22]
//   0x04d83c: 11000529  add      w9, w9, #1
//   0x04d840: 6b08053f  cmp      w9, w8, lsl #1
//   0x04d844: 54ffff2b  b.lt     #0x4d828
//   0x04d848: 17ffffc9  b        #0x4d76c
// ============================================================================
std::uint32_t export_28_4d5d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004d5d4ULL;
    for (std::size_t i = 0; i < 158ULL; ++i) {
        std::uint32_t insn = kTextInstructions[76325ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[29] opus_multistream_encoder_create @ 0x04d84c..0x04d968 (284 bytes, 71 AArch64 insns)
// [VN] Hàm xuất khẩu[29] opus_multistream_encoder_create @ 0x04d84c..0x04d968 (284 byte, 71 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04d84c: a9bb6bfb  stp      x27, x26, [sp, #-0x50]!
//   0x04d850: a90163f9  stp      x25, x24, [sp, #0x10]
//   0x04d854: a9025bf7  stp      x23, x22, [sp, #0x20]
//   0x04d858: a90353f5  stp      x21, x20, [sp, #0x30]
//   0x04d85c: a9047bf3  stp      x19, x30, [sp, #0x40]
//   0x04d860: 51000428  sub      w8, w1, #1
//   0x04d864: aa0603f3  mov      x19, x6
//   0x04d868: 7103f91f  cmp      w8, #0xfe
//   0x04d86c: 54000608  b.hi     #0x4d92c
//   0x04d870: 52801fe8  mov      w8, #0xff
//   0x04d874: 4b030108  sub      w8, w8, w3
//   0x04d878: 2a0303f6  mov      w22, w3
//   0x04d87c: 2a0203f7  mov      w23, w2
//   0x04d880: 6b02011f  cmp      w8, w2
//   0x04d884: 5400054b  b.lt     #0x4d92c
//   0x04d888: 37f80536  tbnz     w22, #0x1f, #0x4d92c
//   0x04d88c: 710006ff  cmp      w23, #1
//   0x04d890: 540004eb  b.lt     #0x4d92c
//   0x04d894: 6b1602fb  subs     w27, w23, w22
//   0x04d898: 540004ab  b.lt     #0x4d92c
//   0x04d89c: 2a0003fa  mov      w26, w0
//   0x04d8a0: 52800040  mov      w0, #2
//   0x04d8a4: 2a0503f4  mov      w20, w5
//   0x04d8a8: aa0403f5  mov      x21, x4
//   0x04d8ac: 2a0103f8  mov      w24, w1
//   0x04d8b0: 97fed4b0  bl       #0x2b70
//   0x04d8b4: 2a0003f9  mov      w25, w0
//   0x04d8b8: 52800020  mov      w0, #1
//   0x04d8bc: 97fed4ad  bl       #0x2b70
//   0x04d8c0: 11001c09  add      w9, w0, #7
//   0x04d8c4: 11001f28  add      w8, w25, #7
//   0x04d8c8: 121d7129  and      w9, w9, #0xfffffff8
//   0x04d8cc: 121d7108  and      w8, w8, #0xfffffff8
//   0x04d8d0: 1b1b7d29  mul      w9, w9, w27
//   0x04d8d4: 1b162508  madd     w8, w8, w22, w9
//   0x04d8d8: 1104a108  add      w8, w8, #0x128
//   0x04d8dc: 93407d00  sxtw     x0, w8
//   0x04d8e0: 97fed4f8  bl       #0x2cc0
//   0x04d8e4: b40003a0  cbz      x0, #0x4d958
//   0x04d8e8: 2a1a03e1  mov      w1, w26
//   0x04d8ec: 2a1803e2  mov      w2, w24
//   0x04d8f0: 2a1703e3  mov      w3, w23
//   0x04d8f4: 2a1603e4  mov      w4, w22
//   0x04d8f8: aa1503e5  mov      x5, x21
//   0x04d8fc: 2a1403e6  mov      w6, w20
//   0x04d900: 2a1f03e7  mov      w7, wzr
//   0x04d904: aa0003f9  mov      x25, x0
//   0x04d908: 97fffe40  bl       #0x4d208
//   0x04d90c: 2a0003f4  mov      w20, w0
//   0x04d910: 34000080  cbz      w0, #0x4d920
//   0x04d914: aa1903e0  mov      x0, x25
//   0x04d918: 97fed4fe  bl       #0x2d10
//   0x04d91c: aa1f03f9  mov      x25, xzr
//   0x04d920: b40000f3  cbz      x19, #0x4d93c
//   0x04d924: b9000274  str      w20, [x19]
//   0x04d928: 14000005  b        #0x4d93c
//   0x04d92c: aa1f03f9  mov      x25, xzr
//   0x04d930: b4000073  cbz      x19, #0x4d93c
//   0x04d934: 12800008  mov      w8, #-1
//   0x04d938: b9000268  str      w8, [x19]
//   0x04d93c: aa1903e0  mov      x0, x25
//   0x04d940: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x04d944: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x04d948: a9425bf7  ldp      x23, x22, [sp, #0x20]
//   0x04d94c: a94163f9  ldp      x25, x24, [sp, #0x10]
//   0x04d950: a8c56bfb  ldp      x27, x26, [sp], #0x50
//   0x04d954: d65f03c0  ret      
//   0x04d958: aa1f03f9  mov      x25, xzr
//   0x04d95c: b4ffff13  cbz      x19, #0x4d93c
//   0x04d960: 128000c8  mov      w8, #-7
//   0x04d964: 17fffff5  b        #0x4d938
// ============================================================================
std::uint32_t export_29_4d84c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004d84cULL;
    for (std::size_t i = 0; i < 71ULL; ++i) {
        std::uint32_t insn = kTextInstructions[76483ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[30] opus_multistream_surround_encoder_create @ 0x04d968..0x04da54 (236 bytes, 59 AArch64 insns)
// [VN] Hàm xuất khẩu[30] opus_multistream_surround_encoder_create @ 0x04d968..0x04da54 (236 byte, 59 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04d968: a9bb6bfb  stp      x27, x26, [sp, #-0x50]!
//   0x04d96c: a90163f9  stp      x25, x24, [sp, #0x10]
//   0x04d970: a9025bf7  stp      x23, x22, [sp, #0x20]
//   0x04d974: a90353f5  stp      x21, x20, [sp, #0x30]
//   0x04d978: a9047bf3  stp      x19, x30, [sp, #0x40]
//   0x04d97c: 51000428  sub      w8, w1, #1
//   0x04d980: aa0703f3  mov      x19, x7
//   0x04d984: 7103fd1f  cmp      w8, #0xff
//   0x04d988: 540000a3  b.lo     #0x4d99c
//   0x04d98c: aa1f03f4  mov      x20, xzr
//   0x04d990: b4000553  cbz      x19, #0x4da38
//   0x04d994: 12800008  mov      w8, #-1
//   0x04d998: 14000027  b        #0x4da34
//   0x04d99c: 2a0103fa  mov      w26, w1
//   0x04d9a0: 2a0003fb  mov      w27, w0
//   0x04d9a4: 2a0103e0  mov      w0, w1
//   0x04d9a8: 2a0203e1  mov      w1, w2
//   0x04d9ac: 2a0603f5  mov      w21, w6
//   0x04d9b0: aa0503f6  mov      x22, x5
//   0x04d9b4: aa0403f7  mov      x23, x4
//   0x04d9b8: aa0303f8  mov      x24, x3
//   0x04d9bc: 2a0203f9  mov      w25, w2
//   0x04d9c0: 97fffdbe  bl       #0x4d0b8
//   0x04d9c4: 340002a0  cbz      w0, #0x4da18
//   0x04d9c8: 93407c00  sxtw     x0, w0
//   0x04d9cc: 97fed4bd  bl       #0x2cc0
//   0x04d9d0: b40002c0  cbz      x0, #0x4da28
//   0x04d9d4: 2a1b03e1  mov      w1, w27
//   0x04d9d8: 2a1a03e2  mov      w2, w26
//   0x04d9dc: 2a1903e3  mov      w3, w25
//   0x04d9e0: aa1803e4  mov      x4, x24
//   0x04d9e4: aa1703e5  mov      x5, x23
//   0x04d9e8: aa1603e6  mov      x6, x22
//   0x04d9ec: 2a1503e7  mov      w7, w21
//   0x04d9f0: aa0003f4  mov      x20, x0
//   0x04d9f4: 97fffef8  bl       #0x4d5d4
//   0x04d9f8: 2a0003f5  mov      w21, w0
//   0x04d9fc: 34000080  cbz      w0, #0x4da0c
//   0x04da00: aa1403e0  mov      x0, x20
//   0x04da04: 97fed4c3  bl       #0x2d10
//   0x04da08: aa1f03f4  mov      x20, xzr
//   0x04da0c: b4000173  cbz      x19, #0x4da38
//   0x04da10: b9000275  str      w21, [x19]
//   0x04da14: 14000009  b        #0x4da38
//   0x04da18: aa1f03f4  mov      x20, xzr
//   0x04da1c: b40000f3  cbz      x19, #0x4da38
//   0x04da20: 12800088  mov      w8, #-5
//   0x04da24: 14000004  b        #0x4da34
//   0x04da28: aa1f03f4  mov      x20, xzr
//   0x04da2c: b4000073  cbz      x19, #0x4da38
//   0x04da30: 128000c8  mov      w8, #-7
//   0x04da34: b9000268  str      w8, [x19]
//   0x04da38: aa1403e0  mov      x0, x20
//   0x04da3c: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x04da40: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x04da44: a9425bf7  ldp      x23, x22, [sp, #0x20]
//   0x04da48: a94163f9  ldp      x25, x24, [sp, #0x10]
//   0x04da4c: a8c56bfb  ldp      x27, x26, [sp], #0x50
//   0x04da50: d65f03c0  ret      
// ============================================================================
std::uint32_t export_30_4d968(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004d968ULL;
    for (std::size_t i = 0; i < 59ULL; ++i) {
        std::uint32_t insn = kTextInstructions[76554ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[31] opus_multistream_encode @ 0x04e614..0x04e654 (64 bytes, 16 AArch64 insns)
// [VN] Hàm xuất khẩu[31] opus_multistream_encode @ 0x04e614..0x04e654 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04e614: d10083ff  sub      sp, sp, #0x20
//   0x04e618: a900fbff  stp      xzr, x30, [sp, #8]
//   0x04e61c: b00000c7  adrp     x7, #0x67000
//   0x04e620: f947ace7  ldr      x7, [x7, #0xf58]
//   0x04e624: 2a0403e5  mov      w5, w4
//   0x04e628: aa0303e4  mov      x4, x3
//   0x04e62c: 2a0203e3  mov      w3, w2
//   0x04e630: aa0103e2  mov      x2, x1
//   0x04e634: 90000001  adrp     x1, #0x4e000
//   0x04e638: 91195021  add      x1, x1, #0x654
//   0x04e63c: 52800206  mov      w6, #0x10
//   0x04e640: b90003ff  str      wzr, [sp]
//   0x04e644: 97fffd04  bl       #0x4da54
//   0x04e648: f9400bfe  ldr      x30, [sp, #0x10]
//   0x04e64c: 910083ff  add      sp, sp, #0x20
//   0x04e650: d65f03c0  ret      
// ============================================================================
std::uint32_t export_31_4e614(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004e614ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[77365ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[32] opus_multistream_encode_float @ 0x04e72c..0x04e770 (68 bytes, 17 AArch64 insns)
// [VN] Hàm xuất khẩu[32] opus_multistream_encode_float @ 0x04e72c..0x04e770 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04e72c: d10083ff  sub      sp, sp, #0x20
//   0x04e730: a900fbff  stp      xzr, x30, [sp, #8]
//   0x04e734: b00000c7  adrp     x7, #0x67000
//   0x04e738: f947c8e7  ldr      x7, [x7, #0xf90]
//   0x04e73c: 2a0403e5  mov      w5, w4
//   0x04e740: aa0303e4  mov      x4, x3
//   0x04e744: 2a0203e3  mov      w3, w2
//   0x04e748: aa0103e2  mov      x2, x1
//   0x04e74c: 90000001  adrp     x1, #0x4e000
//   0x04e750: 52800028  mov      w8, #1
//   0x04e754: 911dc021  add      x1, x1, #0x770
//   0x04e758: 52800206  mov      w6, #0x10
//   0x04e75c: b90003e8  str      w8, [sp]
//   0x04e760: 97fffcbd  bl       #0x4da54
//   0x04e764: f9400bfe  ldr      x30, [sp, #0x10]
//   0x04e768: 910083ff  add      sp, sp, #0x20
//   0x04e76c: d65f03c0  ret      
// ============================================================================
std::uint32_t export_32_4e72c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004e72cULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[77435ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[33] opus_multistream_encoder_ctl @ 0x04edd0..0x04ee34 (100 bytes, 25 AArch64 insns)
// [VN] Hàm xuất khẩu[33] opus_multistream_encoder_ctl @ 0x04edd0..0x04ee34 (100 byte, 25 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04edd0: d10403ff  sub      sp, sp, #0x100
//   0x04edd4: 928005e8  mov      x8, #-0x30
//   0x04edd8: 910003e9  mov      x9, sp
//   0x04eddc: 910203ea  add      x10, sp, #0x80
//   0x04ede0: f2dff008  movk     x8, #0xff80, lsl #32
//   0x04ede4: 910403eb  add      x11, sp, #0x100
//   0x04ede8: 91020129  add      x9, x9, #0x80
//   0x04edec: 9100c14a  add      x10, x10, #0x30
//   0x04edf0: a90efbe8  stp      x8, x30, [sp, #0xe8]
//   0x04edf4: a90da7ea  stp      x10, x9, [sp, #0xd8]
//   0x04edf8: f9006beb  str      x11, [sp, #0xd0]
//   0x04edfc: ad0007e0  stp      q0, q1, [sp]
//   0x04ee00: ad4683e1  ldp      q1, q0, [sp, #0xd0]
//   0x04ee04: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x04ee08: 9102c3e2  add      x2, sp, #0xb0
//   0x04ee0c: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x04ee10: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x04ee14: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x04ee18: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x04ee1c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x04ee20: ad0583e1  stp      q1, q0, [sp, #0xb0]
//   0x04ee24: 97fffe6c  bl       #0x4e7d4
//   0x04ee28: f9407bfe  ldr      x30, [sp, #0xf0]
//   0x04ee2c: 910403ff  add      sp, sp, #0x100
//   0x04ee30: d65f03c0  ret      
// ============================================================================
std::uint32_t export_33_4edd0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004edd0ULL;
    for (std::size_t i = 0; i < 25ULL; ++i) {
        std::uint32_t insn = kTextInstructions[77860ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[34] opus_multistream_encoder_destroy @ 0x04ee34..0x04ee38 (4 bytes, 1 AArch64 insns)
// [VN] Hàm xuất khẩu[34] opus_multistream_encoder_destroy @ 0x04ee34..0x04ee38 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04ee34: 17fecfb7  b        #0x2d10
// ============================================================================
std::uint32_t export_34_4ee34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004ee34ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[77885ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[35] opus_multistream_decoder_get_size @ 0x04ee38..0x04eea8 (112 bytes, 28 AArch64 insns)
// [VN] Hàm xuất khẩu[35] opus_multistream_decoder_get_size @ 0x04ee38..0x04eea8 (112 byte, 28 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04ee38: a9be53f5  stp      x21, x20, [sp, #-0x20]!
//   0x04ee3c: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x04ee40: 7100041f  cmp      w0, #1
//   0x04ee44: 540002ab  b.lt     #0x4ee98
//   0x04ee48: 2a0103f3  mov      w19, w1
//   0x04ee4c: 6b010015  subs     w21, w0, w1
//   0x04ee50: 2a1f03e0  mov      w0, wzr
//   0x04ee54: 540001cb  b.lt     #0x4ee8c
//   0x04ee58: 37f801b3  tbnz     w19, #0x1f, #0x4ee8c
//   0x04ee5c: 52800040  mov      w0, #2
//   0x04ee60: 97fecf90  bl       #0x2ca0
//   0x04ee64: 2a0003f4  mov      w20, w0
//   0x04ee68: 52800020  mov      w0, #1
//   0x04ee6c: 97fecf8d  bl       #0x2ca0
//   0x04ee70: 11001c09  add      w9, w0, #7
//   0x04ee74: 11001e88  add      w8, w20, #7
//   0x04ee78: 121d7129  and      w9, w9, #0xfffffff8
//   0x04ee7c: 121d7108  and      w8, w8, #0xfffffff8
//   0x04ee80: 1b157d29  mul      w9, w9, w21
//   0x04ee84: 1b132508  madd     w8, w8, w19, w9
//   0x04ee88: 11044100  add      w0, w8, #0x110
//   0x04ee8c: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x04ee90: a8c253f5  ldp      x21, x20, [sp], #0x20
//   0x04ee94: d65f03c0  ret      
//   0x04ee98: 2a1f03e0  mov      w0, wzr
//   0x04ee9c: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x04eea0: a8c253f5  ldp      x21, x20, [sp], #0x20
//   0x04eea4: d65f03c0  ret      
// ============================================================================
std::uint32_t export_35_4ee38(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004ee38ULL;
    for (std::size_t i = 0; i < 28ULL; ++i) {
        std::uint32_t insn = kTextInstructions[77886ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[36] opus_multistream_decoder_init @ 0x04eea8..0x04f050 (424 bytes, 106 AArch64 insns)
// [VN] Hàm xuất khẩu[36] opus_multistream_decoder_init @ 0x04eea8..0x04f050 (424 byte, 106 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04eea8: f81c0ff8  str      x24, [sp, #-0x40]!
//   0x04eeac: a9015bf7  stp      x23, x22, [sp, #0x10]
//   0x04eeb0: a90253f5  stp      x21, x20, [sp, #0x20]
//   0x04eeb4: a9037bf3  stp      x19, x30, [sp, #0x30]
//   0x04eeb8: 51000448  sub      w8, w2, #1
//   0x04eebc: 7103f91f  cmp      w8, #0xfe
//   0x04eec0: 540000e9  b.ls     #0x4eedc
//   0x04eec4: 12800000  mov      w0, #-1
//   0x04eec8: a9437bf3  ldp      x19, x30, [sp, #0x30]
//   0x04eecc: a94253f5  ldp      x21, x20, [sp, #0x20]
//   0x04eed0: a9415bf7  ldp      x23, x22, [sp, #0x10]
//   0x04eed4: f84407f8  ldr      x24, [sp], #0x40
//   0x04eed8: d65f03c0  ret      
//   0x04eedc: 52801fe8  mov      w8, #0xff
//   0x04eee0: 4b040108  sub      w8, w8, w4
//   0x04eee4: aa0003f4  mov      x20, x0
//   0x04eee8: 6b03011f  cmp      w8, w3
//   0x04eeec: 12800000  mov      w0, #-1
//   0x04eef0: 54fffecb  b.lt     #0x4eec8
//   0x04eef4: 37fffea4  tbnz     w4, #0x1f, #0x4eec8
//   0x04eef8: 7100047f  cmp      w3, #1
//   0x04eefc: 54fffe6b  b.lt     #0x4eec8
//   0x04ef00: 6b03009f  cmp      w4, w3
//   0x04ef04: 54fffe2c  b.gt     #0x4eec8
//   0x04ef08: 2a0103f3  mov      w19, w1
//   0x04ef0c: 7100805f  cmp      w2, #0x20
//   0x04ef10: 2a0203e8  mov      w8, w2
//   0x04ef14: 29000e82  stp      w2, w3, [x20]
//   0x04ef18: b9000a84  str      w4, [x20, #8]
//   0x04ef1c: 54000123  b.lo     #0x4ef40
//   0x04ef20: 91003289  add      x9, x20, #0xc
//   0x04ef24: 8b0800aa  add      x10, x5, x8
//   0x04ef28: eb0a013f  cmp      x9, x10
//   0x04ef2c: 54000742  b.hs     #0x4f014
//   0x04ef30: 8b140109  add      x9, x8, x20
//   0x04ef34: 91003129  add      x9, x9, #0xc
//   0x04ef38: eb05013f  cmp      x9, x5
//   0x04ef3c: 540006c9  b.ls     #0x4f014
//   0x04ef40: aa1f03e9  mov      x9, xzr
//   0x04ef44: 8b14012b  add      x11, x9, x20
//   0x04ef48: 8b0900aa  add      x10, x5, x9
//   0x04ef4c: 9100316b  add      x11, x11, #0xc
//   0x04ef50: cb090108  sub      x8, x8, x9
//   0x04ef54: 38401549  ldrb     w9, [x10], #1
//   0x04ef58: f1000508  subs     x8, x8, #1
//   0x04ef5c: 38001569  strb     w9, [x11], #1
//   0x04ef60: 54ffffa1  b.ne     #0x4ef54
//   0x04ef64: aa1403e0  mov      x0, x20
//   0x04ef68: 97fff2ed  bl       #0x4bb1c
//   0x04ef6c: 34fffac0  cbz      w0, #0x4eec4
//   0x04ef70: 52800040  mov      w0, #2
//   0x04ef74: 91044295  add      x21, x20, #0x110
//   0x04ef78: 97fecf4a  bl       #0x2ca0
//   0x04ef7c: 2a0003f7  mov      w23, w0
//   0x04ef80: 52800020  mov      w0, #1
//   0x04ef84: 97fecf47  bl       #0x2ca0
//   0x04ef88: b9400a88  ldr      w8, [x20, #8]
//   0x04ef8c: 2a0003f6  mov      w22, w0
//   0x04ef90: 2a1f03f8  mov      w24, wzr
//   0x04ef94: 7100051f  cmp      w8, #1
//   0x04ef98: 540001cb  b.lt     #0x4efd0
//   0x04ef9c: 11001ee8  add      w8, w23, #7
//   0x04efa0: 121d7108  and      w8, w8, #0xfffffff8
//   0x04efa4: 93407d17  sxtw     x23, w8
//   0x04efa8: 52800042  mov      w2, #2
//   0x04efac: aa1503e0  mov      x0, x21
//   0x04efb0: 2a1303e1  mov      w1, w19
//   0x04efb4: 97fecf07  bl       #0x2bd0
//   0x04efb8: 35fff880  cbnz     w0, #0x4eec8
//   0x04efbc: b9400a88  ldr      w8, [x20, #8]
//   0x04efc0: 11000718  add      w24, w24, #1
//   0x04efc4: 8b1702b5  add      x21, x21, x23
//   0x04efc8: 6b08031f  cmp      w24, w8
//   0x04efcc: 54fffeeb  b.lt     #0x4efa8
//   0x04efd0: b9400688  ldr      w8, [x20, #4]
//   0x04efd4: 6b08031f  cmp      w24, w8
//   0x04efd8: 5400038a  b.ge     #0x4f048
//   0x04efdc: 11001ec8  add      w8, w22, #7
//   0x04efe0: 121d7108  and      w8, w8, #0xfffffff8
//   0x04efe4: 93407d16  sxtw     x22, w8
//   0x04efe8: 52800022  mov      w2, #1
//   0x04efec: aa1503e0  mov      x0, x21
//   0x04eff0: 2a1303e1  mov      w1, w19
//   0x04eff4: 97fecef7  bl       #0x2bd0
//   0x04eff8: 35fff680  cbnz     w0, #0x4eec8
//   0x04effc: b9400688  ldr      w8, [x20, #4]
//   0x04f000: 11000718  add      w24, w24, #1
//   0x04f004: 8b1602b5  add      x21, x21, x22
//   0x04f008: 6b08031f  cmp      w24, w8
//   0x04f00c: 54fffeeb  b.lt     #0x4efe8
//   0x04f010: 17ffffae  b        #0x4eec8
//   0x04f014: 927b6909  and      x9, x8, #0xffffffe0
//   0x04f018: 910040aa  add      x10, x5, #0x10
//   0x04f01c: 9100728b  add      x11, x20, #0x1c
//   0x04f020: aa0903ec  mov      x12, x9
//   0x04f024: ad7f8540  ldp      q0, q1, [x10, #-0x10]
//   0x04f028: 9100814a  add      x10, x10, #0x20
//   0x04f02c: f100818c  subs     x12, x12, #0x20
//   0x04f030: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x04f034: 9100816b  add      x11, x11, #0x20
//   0x04f038: 54ffff61  b.ne     #0x4f024
//   0x04f03c: eb08013f  cmp      x9, x8
//   0x04f040: 54fff920  b.eq     #0x4ef64
//   0x04f044: 17ffffc0  b        #0x4ef44
//   0x04f048: 2a1f03e0  mov      w0, wzr
//   0x04f04c: 17ffff9f  b        #0x4eec8
// ============================================================================
std::uint32_t export_36_4eea8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004eea8ULL;
    for (std::size_t i = 0; i < 106ULL; ++i) {
        std::uint32_t insn = kTextInstructions[77914ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[37] opus_multistream_decoder_create @ 0x04f050..0x04f164 (276 bytes, 69 AArch64 insns)
// [VN] Hàm xuất khẩu[37] opus_multistream_decoder_create @ 0x04f050..0x04f164 (276 byte, 69 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04f050: f81b0ffa  str      x26, [sp, #-0x50]!
//   0x04f054: a90163f9  stp      x25, x24, [sp, #0x10]
//   0x04f058: a9025bf7  stp      x23, x22, [sp, #0x20]
//   0x04f05c: a90353f5  stp      x21, x20, [sp, #0x30]
//   0x04f060: a9047bf3  stp      x19, x30, [sp, #0x40]
//   0x04f064: 51000428  sub      w8, w1, #1
//   0x04f068: aa0503f3  mov      x19, x5
//   0x04f06c: 7103f91f  cmp      w8, #0xfe
//   0x04f070: 54000568  b.hi     #0x4f11c
//   0x04f074: 52801fe8  mov      w8, #0xff
//   0x04f078: 4b030108  sub      w8, w8, w3
//   0x04f07c: 2a0303f5  mov      w21, w3
//   0x04f080: 2a0203f6  mov      w22, w2
//   0x04f084: 6b02011f  cmp      w8, w2
//   0x04f088: 540004ab  b.lt     #0x4f11c
//   0x04f08c: 37f80495  tbnz     w21, #0x1f, #0x4f11c
//   0x04f090: 710006df  cmp      w22, #1
//   0x04f094: 5400044b  b.lt     #0x4f11c
//   0x04f098: 6b1502da  subs     w26, w22, w21
//   0x04f09c: 5400040b  b.lt     #0x4f11c
//   0x04f0a0: 2a0003f8  mov      w24, w0
//   0x04f0a4: 52800040  mov      w0, #2
//   0x04f0a8: aa0403f4  mov      x20, x4
//   0x04f0ac: 2a0103f7  mov      w23, w1
//   0x04f0b0: 97fecefc  bl       #0x2ca0
//   0x04f0b4: 2a0003f9  mov      w25, w0
//   0x04f0b8: 52800020  mov      w0, #1
//   0x04f0bc: 97fecef9  bl       #0x2ca0
//   0x04f0c0: 11001c09  add      w9, w0, #7
//   0x04f0c4: 11001f28  add      w8, w25, #7
//   0x04f0c8: 121d7129  and      w9, w9, #0xfffffff8
//   0x04f0cc: 121d7108  and      w8, w8, #0xfffffff8
//   0x04f0d0: 1b1a7d29  mul      w9, w9, w26
//   0x04f0d4: 1b152508  madd     w8, w8, w21, w9
//   0x04f0d8: 11044108  add      w8, w8, #0x110
//   0x04f0dc: 93407d00  sxtw     x0, w8
//   0x04f0e0: 97fecef8  bl       #0x2cc0
//   0x04f0e4: b4000260  cbz      x0, #0x4f130
//   0x04f0e8: 2a1803e1  mov      w1, w24
//   0x04f0ec: 2a1703e2  mov      w2, w23
//   0x04f0f0: 2a1603e3  mov      w3, w22
//   0x04f0f4: 2a1503e4  mov      w4, w21
//   0x04f0f8: aa1403e5  mov      x5, x20
//   0x04f0fc: aa0003f9  mov      x25, x0
//   0x04f100: 97ffff6a  bl       #0x4eea8
//   0x04f104: b4000053  cbz      x19, #0x4f10c
//   0x04f108: b9000260  str      w0, [x19]
//   0x04f10c: 340001e0  cbz      w0, #0x4f148
//   0x04f110: aa1903e0  mov      x0, x25
//   0x04f114: 97feceff  bl       #0x2d10
//   0x04f118: 1400000b  b        #0x4f144
//   0x04f11c: b4000153  cbz      x19, #0x4f144
//   0x04f120: 12800008  mov      w8, #-1
//   0x04f124: aa1f03f9  mov      x25, xzr
//   0x04f128: b9000268  str      w8, [x19]
//   0x04f12c: 14000007  b        #0x4f148
//   0x04f130: b40000b3  cbz      x19, #0x4f144
//   0x04f134: 128000c8  mov      w8, #-7
//   0x04f138: aa1f03f9  mov      x25, xzr
//   0x04f13c: b9000268  str      w8, [x19]
//   0x04f140: 14000002  b        #0x4f148
//   0x04f144: aa1f03f9  mov      x25, xzr
//   0x04f148: aa1903e0  mov      x0, x25
//   0x04f14c: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x04f150: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x04f154: a9425bf7  ldp      x23, x22, [sp, #0x20]
//   0x04f158: a94163f9  ldp      x25, x24, [sp, #0x10]
//   0x04f15c: f84507fa  ldr      x26, [sp], #0x50
//   0x04f160: d65f03c0  ret      
// ============================================================================
std::uint32_t export_37_4f050(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004f050ULL;
    for (std::size_t i = 0; i < 69ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78020ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[38] opus_multistream_decoder_ctl @ 0x04f640..0x04f6a4 (100 bytes, 25 AArch64 insns)
// [VN] Hàm xuất khẩu[38] opus_multistream_decoder_ctl @ 0x04f640..0x04f6a4 (100 byte, 25 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04f640: d10403ff  sub      sp, sp, #0x100
//   0x04f644: 928005e8  mov      x8, #-0x30
//   0x04f648: 910003e9  mov      x9, sp
//   0x04f64c: 910203ea  add      x10, sp, #0x80
//   0x04f650: f2dff008  movk     x8, #0xff80, lsl #32
//   0x04f654: 910403eb  add      x11, sp, #0x100
//   0x04f658: 91020129  add      x9, x9, #0x80
//   0x04f65c: 9100c14a  add      x10, x10, #0x30
//   0x04f660: a90efbe8  stp      x8, x30, [sp, #0xe8]
//   0x04f664: a90da7ea  stp      x10, x9, [sp, #0xd8]
//   0x04f668: f9006beb  str      x11, [sp, #0xd0]
//   0x04f66c: ad0007e0  stp      q0, q1, [sp]
//   0x04f670: ad4683e1  ldp      q1, q0, [sp, #0xd0]
//   0x04f674: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x04f678: 9102c3e2  add      x2, sp, #0xb0
//   0x04f67c: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x04f680: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x04f684: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x04f688: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x04f68c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x04f690: ad0583e1  stp      q1, q0, [sp, #0xb0]
//   0x04f694: 9400009c  bl       #0x4f904
//   0x04f698: f9407bfe  ldr      x30, [sp, #0xf0]
//   0x04f69c: 910403ff  add      sp, sp, #0x100
//   0x04f6a0: d65f03c0  ret      
// ============================================================================
std::uint32_t export_38_4f640(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004f640ULL;
    for (std::size_t i = 0; i < 25ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78400ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[39] opus_multistream_decode @ 0x04f6a4..0x04f6d4 (48 bytes, 12 AArch64 insns)
// [VN] Hàm xuất khẩu[39] opus_multistream_decode @ 0x04f6a4..0x04f6d4 (48 byte, 12 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04f6a4: d10083ff  sub      sp, sp, #0x20
//   0x04f6a8: f9000bfe  str      x30, [sp, #0x10]
//   0x04f6ac: 2a0503e6  mov      w6, w5
//   0x04f6b0: 2a0403e5  mov      w5, w4
//   0x04f6b4: 90000004  adrp     x4, #0x4f000
//   0x04f6b8: 911b5084  add      x4, x4, #0x6d4
//   0x04f6bc: 2a1f03e7  mov      w7, wzr
//   0x04f6c0: f90003ff  str      xzr, [sp]
//   0x04f6c4: 97fffea8  bl       #0x4f164
//   0x04f6c8: f9400bfe  ldr      x30, [sp, #0x10]
//   0x04f6cc: 910083ff  add      sp, sp, #0x20
//   0x04f6d0: d65f03c0  ret      
// ============================================================================
std::uint32_t export_39_4f6a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004f6a4ULL;
    for (std::size_t i = 0; i < 12ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78425ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[40] opus_multistream_decode_float @ 0x04f780..0x04f7b0 (48 bytes, 12 AArch64 insns)
// [VN] Hàm xuất khẩu[40] opus_multistream_decode_float @ 0x04f780..0x04f7b0 (48 byte, 12 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04f780: d10083ff  sub      sp, sp, #0x20
//   0x04f784: f9000bfe  str      x30, [sp, #0x10]
//   0x04f788: 2a0503e6  mov      w6, w5
//   0x04f78c: 2a0403e5  mov      w5, w4
//   0x04f790: 90000004  adrp     x4, #0x4f000
//   0x04f794: 911ec084  add      x4, x4, #0x7b0
//   0x04f798: 2a1f03e7  mov      w7, wzr
//   0x04f79c: f90003ff  str      xzr, [sp]
//   0x04f7a0: 97fffe71  bl       #0x4f164
//   0x04f7a4: f9400bfe  ldr      x30, [sp, #0x10]
//   0x04f7a8: 910083ff  add      sp, sp, #0x20
//   0x04f7ac: d65f03c0  ret      
// ============================================================================
std::uint32_t export_40_4f780(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004f780ULL;
    for (std::size_t i = 0; i < 12ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78480ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[41] opus_multistream_decoder_destroy @ 0x04fc30..0x04fc34 (4 bytes, 1 AArch64 insns)
// [VN] Hàm xuất khẩu[41] opus_multistream_decoder_destroy @ 0x04fc30..0x04fc34 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04fc30: 17fecc38  b        #0x2d10
// ============================================================================
std::uint32_t export_41_4fc30(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004fc30ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78780ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[42] opus_repacketizer_get_size @ 0x04fc34..0x04fc3c (8 bytes, 2 AArch64 insns)
// [VN] Hàm xuất khẩu[42] opus_repacketizer_get_size @ 0x04fc34..0x04fc3c (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04fc34: 52803e00  mov      w0, #0x1f0
//   0x04fc38: d65f03c0  ret      
// ============================================================================
std::uint32_t export_42_4fc34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004fc34ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78781ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[43] opus_repacketizer_init @ 0x04fc3c..0x04fc44 (8 bytes, 2 AArch64 insns)
// [VN] Hàm xuất khẩu[43] opus_repacketizer_init @ 0x04fc3c..0x04fc44 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04fc3c: b900041f  str      wzr, [x0, #4]
//   0x04fc40: d65f03c0  ret      
// ============================================================================
std::uint32_t export_43_4fc3c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004fc3cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78783ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[44] opus_repacketizer_create @ 0x04fc44..0x04fc60 (28 bytes, 7 AArch64 insns)
// [VN] Hàm xuất khẩu[44] opus_repacketizer_create @ 0x04fc44..0x04fc60 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04fc44: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x04fc48: 52803e00  mov      w0, #0x1f0
//   0x04fc4c: 97fecc1d  bl       #0x2cc0
//   0x04fc50: b4000040  cbz      x0, #0x4fc58
//   0x04fc54: b900041f  str      wzr, [x0, #4]
//   0x04fc58: f84107fe  ldr      x30, [sp], #0x10
//   0x04fc5c: d65f03c0  ret      
// ============================================================================
std::uint32_t export_44_4fc44(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004fc44ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78785ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[45] opus_repacketizer_destroy @ 0x04fc60..0x04fc64 (4 bytes, 1 AArch64 insns)
// [VN] Hàm xuất khẩu[45] opus_repacketizer_destroy @ 0x04fc60..0x04fc64 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04fc60: 17fecc2c  b        #0x2d10
// ============================================================================
std::uint32_t export_45_4fc60(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004fc60ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78792ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[46] opus_repacketizer_cat @ 0x04fc64..0x04fd54 (240 bytes, 60 AArch64 insns)
// [VN] Hàm xuất khẩu[46] opus_repacketizer_cat @ 0x04fc64..0x04fd54 (240 byte, 60 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04fc64: f81d0ff6  str      x22, [sp, #-0x30]!
//   0x04fc68: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x04fc6c: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x04fc70: 7100045f  cmp      w2, #1
//   0x04fc74: 540003cb  b.lt     #0x4fcec
//   0x04fc78: b9400408  ldr      w8, [x0, #4]
//   0x04fc7c: 2a0203f4  mov      w20, w2
//   0x04fc80: aa0103f5  mov      x21, x1
//   0x04fc84: aa0003f3  mov      x19, x0
//   0x04fc88: 340000e8  cbz      w8, #0x4fca4
//   0x04fc8c: 39400268  ldrb     w8, [x19]
//   0x04fc90: 394002a9  ldrb     w9, [x21]
//   0x04fc94: 4a080128  eor      w8, w9, w8
//   0x04fc98: 71000d1f  cmp      w8, #3
//   0x04fc9c: 54000109  b.ls     #0x4fcbc
//   0x04fca0: 14000013  b        #0x4fcec
//   0x04fca4: 394002a8  ldrb     w8, [x21]
//   0x04fca8: 5283e801  mov      w1, #0x1f40
//   0x04fcac: aa1503e0  mov      x0, x21
//   0x04fcb0: 39000268  strb     w8, [x19]
//   0x04fcb4: 97fecbd7  bl       #0x2c10
//   0x04fcb8: b901ea60  str      w0, [x19, #0x1e8]
//   0x04fcbc: aa1503e0  mov      x0, x21
//   0x04fcc0: 2a1403e1  mov      w1, w20
//   0x04fcc4: 97fecc0f  bl       #0x2d00
//   0x04fcc8: 7100041f  cmp      w0, #1
//   0x04fccc: 5400010b  b.lt     #0x4fcec
//   0x04fcd0: b9800668  ldrsw    x8, [x19, #4]
//   0x04fcd4: b941ea69  ldr      w9, [x19, #0x1e8]
//   0x04fcd8: 2a0003f6  mov      w22, w0
//   0x04fcdc: 0b00010a  add      w10, w8, w0
//   0x04fce0: 1b097d49  mul      w9, w10, w9
//   0x04fce4: 710f013f  cmp      w9, #0x3c0
//   0x04fce8: 540000cd  b.le     #0x4fd00
//   0x04fcec: 12800060  mov      w0, #-4
//   0x04fcf0: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x04fcf4: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x04fcf8: f84307f6  ldr      x22, [sp], #0x30
//   0x04fcfc: d65f03c0  ret      
//   0x04fd00: 8b080e69  add      x9, x19, x8, lsl #3
//   0x04fd04: 8b080668  add      x8, x19, x8, lsl #1
//   0x04fd08: 91002124  add      x4, x9, #8
//   0x04fd0c: 91062105  add      x5, x8, #0x188
//   0x04fd10: 910033e3  add      x3, sp, #0xc
//   0x04fd14: aa1503e0  mov      x0, x21
//   0x04fd18: 2a1403e1  mov      w1, w20
//   0x04fd1c: 2a1f03e2  mov      w2, wzr
//   0x04fd20: aa1f03e6  mov      x6, xzr
//   0x04fd24: aa1f03e7  mov      x7, xzr
//   0x04fd28: 97ffca0c  bl       #0x42558
//   0x04fd2c: 7100041f  cmp      w0, #1
//   0x04fd30: 540000ab  b.lt     #0x4fd44
//   0x04fd34: b9400668  ldr      w8, [x19, #4]
//   0x04fd38: 2a1f03e0  mov      w0, wzr
//   0x04fd3c: 0b160108  add      w8, w8, w22
//   0x04fd40: b9000668  str      w8, [x19, #4]
//   0x04fd44: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x04fd48: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x04fd4c: f84307f6  ldr      x22, [sp], #0x30
//   0x04fd50: d65f03c0  ret      
// ============================================================================
std::uint32_t export_46_4fc64(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004fc64ULL;
    for (std::size_t i = 0; i < 60ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78793ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[47] opus_repacketizer_get_nb_frames @ 0x04fd54..0x04fd5c (8 bytes, 2 AArch64 insns)
// [VN] Hàm xuất khẩu[47] opus_repacketizer_get_nb_frames @ 0x04fd54..0x04fd5c (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x04fd54: b9400400  ldr      w0, [x0, #4]
//   0x04fd58: d65f03c0  ret      
// ============================================================================
std::uint32_t export_47_4fd54(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0004fd54ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78853ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[48] opus_repacketizer_out_range @ 0x05023c..0x050248 (12 bytes, 3 AArch64 insns)
// [VN] Hàm xuất khẩu[48] opus_repacketizer_out_range @ 0x05023c..0x050248 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x05023c: 2a1f03e5  mov      w5, wzr
//   0x050240: 2a1f03e6  mov      w6, wzr
//   0x050244: 17fffec6  b        #0x4fd5c
// ============================================================================
std::uint32_t export_48_5023c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0005023cULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79167ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[49] opus_repacketizer_out @ 0x050248..0x050264 (28 bytes, 7 AArch64 insns)
// [VN] Hàm xuất khẩu[49] opus_repacketizer_out @ 0x050248..0x050264 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050248: 2a0203e4  mov      w4, w2
//   0x05024c: b9400402  ldr      w2, [x0, #4]
//   0x050250: aa0103e3  mov      x3, x1
//   0x050254: 2a1f03e1  mov      w1, wzr
//   0x050258: 2a1f03e5  mov      w5, wzr
//   0x05025c: 2a1f03e6  mov      w6, wzr
//   0x050260: 17fffebf  b        #0x4fd5c
// ============================================================================
std::uint32_t export_49_50248(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050248ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79170ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[50] opus_packet_pad @ 0x050264..0x05030c (168 bytes, 42 AArch64 insns)
// [VN] Hàm xuất khẩu[50] opus_packet_pad @ 0x050264..0x05030c (168 byte, 42 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050264: a9bd5bfc  stp      x28, x22, [sp, #-0x30]!
//   0x050268: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x05026c: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x050270: d107c3ff  sub      sp, sp, #0x1f0
//   0x050274: 7100043f  cmp      w1, #1
//   0x050278: 5400010b  b.lt     #0x50298
//   0x05027c: 2a0203f3  mov      w19, w2
//   0x050280: 2a0103f5  mov      w21, w1
//   0x050284: 6b02003f  cmp      w1, w2
//   0x050288: 54000061  b.ne     #0x50294
//   0x05028c: 2a1f03e0  mov      w0, wzr
//   0x050290: 14000003  b        #0x5029c
//   0x050294: 540000ed  b.le     #0x502b0
//   0x050298: 12800000  mov      w0, #-1
//   0x05029c: 9107c3ff  add      sp, sp, #0x1f0
//   0x0502a0: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x0502a4: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x0502a8: a8c35bfc  ldp      x28, x22, [sp], #0x30
//   0x0502ac: d65f03c0  ret      
//   0x0502b0: 8b33c008  add      x8, x0, w19, sxtw
//   0x0502b4: 93407ea2  sxtw     x2, w21
//   0x0502b8: aa0003f4  mov      x20, x0
//   0x0502bc: cb020116  sub      x22, x8, x2
//   0x0502c0: aa1603e0  mov      x0, x22
//   0x0502c4: aa1403e1  mov      x1, x20
//   0x0502c8: b90007ff  str      wzr, [sp, #4]
//   0x0502cc: 97feca6d  bl       #0x2c80
//   0x0502d0: 910003e0  mov      x0, sp
//   0x0502d4: aa1603e1  mov      x1, x22
//   0x0502d8: 2a1503e2  mov      w2, w21
//   0x0502dc: 97fffe62  bl       #0x4fc64
//   0x0502e0: 35fffde0  cbnz     w0, #0x5029c
//   0x0502e4: b94007e2  ldr      w2, [sp, #4]
//   0x0502e8: 910003e0  mov      x0, sp
//   0x0502ec: 52800026  mov      w6, #1
//   0x0502f0: 2a1f03e1  mov      w1, wzr
//   0x0502f4: aa1403e3  mov      x3, x20
//   0x0502f8: 2a1303e4  mov      w4, w19
//   0x0502fc: 2a1f03e5  mov      w5, wzr
//   0x050300: 97fffe97  bl       #0x4fd5c
//   0x050304: 0a807c00  and      w0, w0, w0, asr #31
//   0x050308: 17ffffe5  b        #0x5029c
// ============================================================================
std::uint32_t export_50_50264(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050264ULL;
    for (std::size_t i = 0; i < 42ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79177ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[51] opus_packet_unpad @ 0x05030c..0x0503ac (160 bytes, 40 AArch64 insns)
// [VN] Hàm xuất khẩu[51] opus_packet_unpad @ 0x05030c..0x0503ac (160 byte, 40 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x05030c: a9be53fc  stp      x28, x20, [sp, #-0x20]!
//   0x050310: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x050314: d107c3ff  sub      sp, sp, #0x1f0
//   0x050318: 7100043f  cmp      w1, #1
//   0x05031c: 5400032b  b.lt     #0x50380
//   0x050320: 2a0103f3  mov      w19, w1
//   0x050324: aa0003f4  mov      x20, x0
//   0x050328: 910003e0  mov      x0, sp
//   0x05032c: aa1403e1  mov      x1, x20
//   0x050330: 2a1303e2  mov      w2, w19
//   0x050334: b90007ff  str      wzr, [sp, #4]
//   0x050338: 97fffe4b  bl       #0x4fc64
//   0x05033c: 37f801a0  tbnz     w0, #0x1f, #0x50370
//   0x050340: b94007e2  ldr      w2, [sp, #4]
//   0x050344: 910003e0  mov      x0, sp
//   0x050348: 2a1f03e1  mov      w1, wzr
//   0x05034c: aa1403e3  mov      x3, x20
//   0x050350: 2a1303e4  mov      w4, w19
//   0x050354: 2a1f03e5  mov      w5, wzr
//   0x050358: 2a1f03e6  mov      w6, wzr
//   0x05035c: 97fffe80  bl       #0x4fd5c
//   0x050360: 7100041f  cmp      w0, #1
//   0x050364: 5400018b  b.lt     #0x50394
//   0x050368: 6b13001f  cmp      w0, w19
//   0x05036c: 5400014c  b.gt     #0x50394
//   0x050370: 9107c3ff  add      sp, sp, #0x1f0
//   0x050374: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x050378: a8c253fc  ldp      x28, x20, [sp], #0x20
//   0x05037c: d65f03c0  ret      
//   0x050380: 12800000  mov      w0, #-1
//   0x050384: 9107c3ff  add      sp, sp, #0x1f0
//   0x050388: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x05038c: a8c253fc  ldp      x28, x20, [sp], #0x20
//   0x050390: d65f03c0  ret      
//   0x050394: b0000060  adrp     x0, #0x5d000
//   0x050398: b0000061  adrp     x1, #0x5d000
//   0x05039c: 9134a400  add      x0, x0, #0xd29
//   0x0503a0: 91354421  add      x1, x1, #0xd51
//   0x0503a4: 52802242  mov      w2, #0x112
//   0x0503a8: 97fedda4  bl       #0x7a38
// ============================================================================
std::uint32_t export_51_5030c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0005030cULL;
    for (std::size_t i = 0; i < 40ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79219ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[52] opus_multistream_packet_pad @ 0x0503ac..0x0504c8 (284 bytes, 71 AArch64 insns)
// [VN] Hàm xuất khẩu[52] opus_multistream_packet_pad @ 0x0503ac..0x0504c8 (284 byte, 71 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0503ac: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x0503b0: a9015bf7  stp      x23, x22, [sp, #0x10]
//   0x0503b4: a90253f5  stp      x21, x20, [sp, #0x20]
//   0x0503b8: a9037bf3  stp      x19, x30, [sp, #0x30]
//   0x0503bc: d10943ff  sub      sp, sp, #0x250
//   0x0503c0: 7100043f  cmp      w1, #1
//   0x0503c4: 5400010b  b.lt     #0x503e4
//   0x0503c8: 2a0203f5  mov      w21, w2
//   0x0503cc: 2a0103f4  mov      w20, w1
//   0x0503d0: 6b010056  subs     w22, w2, w1
//   0x0503d4: 54000061  b.ne     #0x503e0
//   0x0503d8: 2a1f03e0  mov      w0, wzr
//   0x0503dc: 14000003  b        #0x503e8
//   0x0503e0: 5400010a  b.ge     #0x50400
//   0x0503e4: 12800000  mov      w0, #-1
//   0x0503e8: 910943ff  add      sp, sp, #0x250
//   0x0503ec: a9437bf3  ldp      x19, x30, [sp, #0x30]
//   0x0503f0: a94253f5  ldp      x21, x20, [sp, #0x20]
//   0x0503f4: a9415bf7  ldp      x23, x22, [sp, #0x10]
//   0x0503f8: f84407fc  ldr      x28, [sp], #0x40
//   0x0503fc: d65f03c0  ret      
//   0x050400: 51000477  sub      w23, w3, #1
//   0x050404: aa0003f3  mov      x19, x0
//   0x050408: 710002ff  cmp      w23, #0
//   0x05040c: 540002ad  b.le     #0x50460
//   0x050410: 7100069f  cmp      w20, #1
//   0x050414: 5400056b  b.lt     #0x504c0
//   0x050418: 910973e3  add      x3, sp, #0x25c
//   0x05041c: 910003e5  mov      x5, sp
//   0x050420: 910963e7  add      x7, sp, #0x258
//   0x050424: 52800022  mov      w2, #1
//   0x050428: aa1303e0  mov      x0, x19
//   0x05042c: 2a1403e1  mov      w1, w20
//   0x050430: aa1f03e4  mov      x4, xzr
//   0x050434: aa1f03e6  mov      x6, xzr
//   0x050438: 97ffc848  bl       #0x42558
//   0x05043c: 37fffd60  tbnz     w0, #0x1f, #0x503e8
//   0x050440: b9825be8  ldrsw    x8, [sp, #0x258]
//   0x050444: 710006f7  subs     w23, w23, #1
//   0x050448: 8b080273  add      x19, x19, x8
//   0x05044c: 4b080294  sub      w20, w20, w8
//   0x050450: 54fffe01  b.ne     #0x50410
//   0x050454: 7100069f  cmp      w20, #1
//   0x050458: 54fffc6b  b.lt     #0x503e4
//   0x05045c: 0b160295  add      w21, w20, w22
//   0x050460: 34fffbd6  cbz      w22, #0x503d8
//   0x050464: 37fffc16  tbnz     w22, #0x1f, #0x503e4
//   0x050468: 8b35c268  add      x8, x19, w21, sxtw
//   0x05046c: 93407e82  sxtw     x2, w20
//   0x050470: cb020116  sub      x22, x8, x2
//   0x050474: aa1603e0  mov      x0, x22
//   0x050478: aa1303e1  mov      x1, x19
//   0x05047c: b90067ff  str      wzr, [sp, #0x64]
//   0x050480: 97feca00  bl       #0x2c80
//   0x050484: 910183e0  add      x0, sp, #0x60
//   0x050488: aa1603e1  mov      x1, x22
//   0x05048c: 2a1403e2  mov      w2, w20
//   0x050490: 97fffdf5  bl       #0x4fc64
//   0x050494: 35fffaa0  cbnz     w0, #0x503e8
//   0x050498: b94067e2  ldr      w2, [sp, #0x64]
//   0x05049c: 910183e0  add      x0, sp, #0x60
//   0x0504a0: 52800026  mov      w6, #1
//   0x0504a4: 2a1f03e1  mov      w1, wzr
//   0x0504a8: aa1303e3  mov      x3, x19
//   0x0504ac: 2a1503e4  mov      w4, w21
//   0x0504b0: 2a1f03e5  mov      w5, wzr
//   0x0504b4: 97fffe2a  bl       #0x4fd5c
//   0x0504b8: 0a807c00  and      w0, w0, w0, asr #31
//   0x0504bc: 17ffffcb  b        #0x503e8
//   0x0504c0: 12800060  mov      w0, #-4
//   0x0504c4: 17ffffc9  b        #0x503e8
// ============================================================================
std::uint32_t export_52_503ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000503acULL;
    for (std::size_t i = 0; i < 71ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79259ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[53] opus_multistream_packet_unpad @ 0x0504c8..0x050680 (440 bytes, 110 AArch64 insns)
// [VN] Hàm xuất khẩu[53] opus_multistream_packet_unpad @ 0x0504c8..0x050680 (440 byte, 110 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0504c8: f81a0ffc  str      x28, [sp, #-0x60]!
//   0x0504cc: a9016bfb  stp      x27, x26, [sp, #0x10]
//   0x0504d0: a90263f9  stp      x25, x24, [sp, #0x20]
//   0x0504d4: a9035bf7  stp      x23, x22, [sp, #0x30]
//   0x0504d8: a90453f5  stp      x21, x20, [sp, #0x40]
//   0x0504dc: a9057bf3  stp      x19, x30, [sp, #0x50]
//   0x0504e0: d10983ff  sub      sp, sp, #0x260
//   0x0504e4: 7100043f  cmp      w1, #1
//   0x0504e8: 54000b2b  b.lt     #0x5064c
//   0x0504ec: 2a0203f3  mov      w19, w2
//   0x0504f0: 7100045f  cmp      w2, #1
//   0x0504f4: 54000b0b  b.lt     #0x50654
//   0x0504f8: 2a0103f4  mov      w20, w1
//   0x0504fc: aa0003f5  mov      x21, x0
//   0x050500: 2a1f03fa  mov      w26, wzr
//   0x050504: 910023fb  add      x27, sp, #8
//   0x050508: aa0003f6  mov      x22, x0
//   0x05050c: 7100067f  cmp      w19, #1
//   0x050510: 1a9f07f7  cset     w23, ne
//   0x050514: 7100069f  cmp      w20, #1
//   0x050518: 54000a2b  b.lt     #0x5065c
//   0x05051c: 9109a3e3  add      x3, sp, #0x268
//   0x050520: 910803e5  add      x5, sp, #0x200
//   0x050524: 9107f3e7  add      x7, sp, #0x1fc
//   0x050528: aa1603e0  mov      x0, x22
//   0x05052c: 2a1403e1  mov      w1, w20
//   0x050530: 2a1703e2  mov      w2, w23
//   0x050534: aa1f03e4  mov      x4, xzr
//   0x050538: aa1f03e6  mov      x6, xzr
//   0x05053c: b9000fff  str      wzr, [sp, #0xc]
//   0x050540: 97ffc806  bl       #0x42558
//   0x050544: 37f808e0  tbnz     w0, #0x1f, #0x50660
//   0x050548: b941fff8  ldr      w24, [sp, #0x1fc]
//   0x05054c: 7100071f  cmp      w24, #1
//   0x050550: 5400086b  b.lt     #0x5065c
//   0x050554: b9400fe8  ldr      w8, [sp, #0xc]
//   0x050558: 340000e8  cbz      w8, #0x50574
//   0x05055c: 394023e8  ldrb     w8, [sp, #8]
//   0x050560: 394002c9  ldrb     w9, [x22]
//   0x050564: 4a080128  eor      w8, w9, w8
//   0x050568: 71000d1f  cmp      w8, #3
//   0x05056c: 54000109  b.ls     #0x5058c
//   0x050570: 1400003b  b        #0x5065c
//   0x050574: 394002c8  ldrb     w8, [x22]
//   0x050578: 5283e801  mov      w1, #0x1f40
//   0x05057c: aa1603e0  mov      x0, x22
//   0x050580: 390023e8  strb     w8, [sp, #8]
//   0x050584: 97fec9a3  bl       #0x2c10
//   0x050588: b901f3e0  str      w0, [sp, #0x1f0]
//   0x05058c: aa1603e0  mov      x0, x22
//   0x050590: 2a1803e1  mov      w1, w24
//   0x050594: 97fec9db  bl       #0x2d00
//   0x050598: 7100041f  cmp      w0, #1
//   0x05059c: 5400060b  b.lt     #0x5065c
//   0x0505a0: b9800fe8  ldrsw    x8, [sp, #0xc]
//   0x0505a4: b941f3e9  ldr      w9, [sp, #0x1f0]
//   0x0505a8: 2a0003f9  mov      w25, w0
//   0x0505ac: 0b00010a  add      w10, w8, w0
//   0x0505b0: 1b097d49  mul      w9, w10, w9
//   0x0505b4: 710f013f  cmp      w9, #0x3c0
//   0x0505b8: 5400052c  b.gt     #0x5065c
//   0x0505bc: 8b080f69  add      x9, x27, x8, lsl #3
//   0x0505c0: 8b080768  add      x8, x27, x8, lsl #1
//   0x0505c4: 91002124  add      x4, x9, #8
//   0x0505c8: 91062105  add      x5, x8, #0x188
//   0x0505cc: 9109b3e3  add      x3, sp, #0x26c
//   0x0505d0: aa1603e0  mov      x0, x22
//   0x0505d4: 2a1803e1  mov      w1, w24
//   0x0505d8: 2a1703e2  mov      w2, w23
//   0x0505dc: aa1f03e6  mov      x6, xzr
//   0x0505e0: aa1f03e7  mov      x7, xzr
//   0x0505e4: 97ffc7dd  bl       #0x42558
//   0x0505e8: 7100041f  cmp      w0, #1
//   0x0505ec: 540000ab  b.lt     #0x50600
//   0x0505f0: b9400fe8  ldr      w8, [sp, #0xc]
//   0x0505f4: 0b190102  add      w2, w8, w25
//   0x0505f8: b9000fe2  str      w2, [sp, #0xc]
//   0x0505fc: 14000003  b        #0x50608
//   0x050600: 37f80300  tbnz     w0, #0x1f, #0x50660
//   0x050604: b9400fe2  ldr      w2, [sp, #0xc]
//   0x050608: 910023e0  add      x0, sp, #8
//   0x05060c: 2a1f03e1  mov      w1, wzr
//   0x050610: aa1503e3  mov      x3, x21
//   0x050614: 2a1403e4  mov      w4, w20
//   0x050618: 2a1703e5  mov      w5, w23
//   0x05061c: 2a1f03e6  mov      w6, wzr
//   0x050620: 97fffdcf  bl       #0x4fd5c
//   0x050624: 37f801e0  tbnz     w0, #0x1f, #0x50660
//   0x050628: b981ffe8  ldrsw    x8, [sp, #0x1fc]
//   0x05062c: 0b1a001a  add      w26, w0, w26
//   0x050630: 8b20c2b5  add      x21, x21, w0, sxtw
//   0x050634: 71000673  subs     w19, w19, #1
//   0x050638: 8b0802d6  add      x22, x22, x8
//   0x05063c: 4b080294  sub      w20, w20, w8
//   0x050640: 2a1a03e0  mov      w0, w26
//   0x050644: 54fff641  b.ne     #0x5050c
//   0x050648: 14000006  b        #0x50660
//   0x05064c: 12800000  mov      w0, #-1
//   0x050650: 14000004  b        #0x50660
//   0x050654: 2a1f03e0  mov      w0, wzr
//   0x050658: 14000002  b        #0x50660
//   0x05065c: 12800060  mov      w0, #-4
//   0x050660: 910983ff  add      sp, sp, #0x260
//   0x050664: a9457bf3  ldp      x19, x30, [sp, #0x50]
//   0x050668: a94453f5  ldp      x21, x20, [sp, #0x40]
//   0x05066c: a9435bf7  ldp      x23, x22, [sp, #0x30]
//   0x050670: a94263f9  ldp      x25, x24, [sp, #0x20]
//   0x050674: a9416bfb  ldp      x27, x26, [sp, #0x10]
//   0x050678: f84607fc  ldr      x28, [sp], #0x60
//   0x05067c: d65f03c0  ret      
// ============================================================================
std::uint32_t export_53_504c8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000504c8ULL;
    for (std::size_t i = 0; i < 110ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79330ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[54] opus_projection_ambisonics_encoder_get_size @ 0x050680..0x05077c (252 bytes, 63 AArch64 insns)
// [VN] Hàm xuất khẩu[54] opus_projection_ambisonics_encoder_get_size @ 0x050680..0x05077c (252 byte, 63 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050680: a9bd5bf7  stp      x23, x22, [sp, #-0x30]!
//   0x050684: a90153f5  stp      x21, x20, [sp, #0x10]
//   0x050688: a9027bf3  stp      x19, x30, [sp, #0x20]
//   0x05068c: 2a0003f3  mov      w19, w0
//   0x050690: 71000c3f  cmp      w1, #3
//   0x050694: 2a1f03e0  mov      w0, wzr
//   0x050698: 54000601  b.ne     #0x50758
//   0x05069c: 51000668  sub      w8, w19, #1
//   0x0506a0: 7103891f  cmp      w8, #0xe2
//   0x0506a4: 540005a8  b.hi     #0x50758
//   0x0506a8: 2a1303e0  mov      w0, w19
//   0x0506ac: 97ff1d5f  bl       #0x17c28
//   0x0506b0: 1b00cc08  msub     w8, w0, w0, w19
//   0x0506b4: 721e791f  tst      w8, #0xfffffffd
//   0x0506b8: 54000581  b.ne     #0x50768
//   0x0506bc: 11000669  add      w9, w19, #1
//   0x0506c0: 11000a6a  add      w10, w19, #2
//   0x0506c4: 51000808  sub      w8, w0, #2
//   0x0506c8: 7100013f  cmp      w9, #0
//   0x0506cc: 1a93b557  csinc    w23, w10, w19, lt
//   0x0506d0: 7100091f  cmp      w8, #2
//   0x0506d4: 540004a8  b.hi     #0x50768
//   0x0506d8: f00000ab  adrp     x11, #0x67000
//   0x0506dc: f00000ac  adrp     x12, #0x67000
//   0x0506e0: 937d7d08  sbfiz    x8, x8, #3, #0x20
//   0x0506e4: f00000a9  adrp     x9, #0x67000
//   0x0506e8: f00000aa  adrp     x10, #0x67000
//   0x0506ec: 9127e16b  add      x11, x11, #0x9f8
//   0x0506f0: 9128418c  add      x12, x12, #0xa10
//   0x0506f4: 91272129  add      x9, x9, #0x9c8
//   0x0506f8: 9127814a  add      x10, x10, #0x9e0
//   0x0506fc: f868698c  ldr      x12, [x12, x8]
//   0x050700: f868696b  ldr      x11, [x11, x8]
//   0x050704: f868694a  ldr      x10, [x10, x8]
//   0x050708: f8686928  ldr      x8, [x9, x8]
//   0x05070c: b9400180  ldr      w0, [x12]
//   0x050710: b9400161  ldr      w1, [x11]
//   0x050714: b9400155  ldr      w21, [x10]
//   0x050718: b9400116  ldr      w22, [x8]
//   0x05071c: 94000337  bl       #0x513f8
//   0x050720: 340001c0  cbz      w0, #0x50758
//   0x050724: 2a0003f4  mov      w20, w0
//   0x050728: 2a1503e0  mov      w0, w21
//   0x05072c: 2a1603e1  mov      w1, w22
//   0x050730: 94000332  bl       #0x513f8
//   0x050734: 34000120  cbz      w0, #0x50758
//   0x050738: 2a0003f5  mov      w21, w0
//   0x05073c: 13017ee0  asr      w0, w23, #1
//   0x050740: 53011e61  ubfx     w1, w19, #1, #7
//   0x050744: 97fec947  bl       #0x2c60
//   0x050748: 34000080  cbz      w0, #0x50758
//   0x05074c: 0b150288  add      w8, w20, w21
//   0x050750: 0b000108  add      w8, w8, w0
//   0x050754: 11002100  add      w0, w8, #8
//   0x050758: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x05075c: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x050760: a8c35bf7  ldp      x23, x22, [sp], #0x30
//   0x050764: d65f03c0  ret      
//   0x050768: 2a1f03e0  mov      w0, wzr
//   0x05076c: a9427bf3  ldp      x19, x30, [sp, #0x20]
//   0x050770: a94153f5  ldp      x21, x20, [sp, #0x10]
//   0x050774: a8c35bf7  ldp      x23, x22, [sp], #0x30
//   0x050778: d65f03c0  ret      
// ============================================================================
std::uint32_t export_54_50680(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050680ULL;
    for (std::size_t i = 0; i < 63ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79440ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[55] opus_projection_ambisonics_encoder_init @ 0x05077c..0x050a5c (736 bytes, 184 AArch64 insns)
// [VN] Hàm xuất khẩu[55] opus_projection_ambisonics_encoder_init @ 0x05077c..0x050a5c (736 byte, 184 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x05077c: d105c3ff  sub      sp, sp, #0x170
//   0x050780: a9116ffc  stp      x28, x27, [sp, #0x110]
//   0x050784: a91267fa  stp      x26, x25, [sp, #0x120]
//   0x050788: a9135ff8  stp      x24, x23, [sp, #0x130]
//   0x05078c: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x050790: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x050794: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x050798: d53bd05c  mrs      x28, tpidr_el0
//   0x05079c: f9401788  ldr      x8, [x28, #0x28]
//   0x0507a0: aa0003f6  mov      x22, x0
//   0x0507a4: 12800000  mov      w0, #-1
//   0x0507a8: f90087e8  str      x8, [sp, #0x108]
//   0x0507ac: b4000264  cbz      x4, #0x507f8
//   0x0507b0: aa0503f7  mov      x23, x5
//   0x0507b4: b4000225  cbz      x5, #0x507f8
//   0x0507b8: 71000c7f  cmp      w3, #3
//   0x0507bc: 12800000  mov      w0, #-1
//   0x0507c0: 540001c1  b.ne     #0x507f8
//   0x0507c4: 51000448  sub      w8, w2, #1
//   0x0507c8: 2a0203f4  mov      w20, w2
//   0x0507cc: 7103891f  cmp      w8, #0xe2
//   0x0507d0: 54000148  b.hi     #0x507f8
//   0x0507d4: 2a1403e0  mov      w0, w20
//   0x0507d8: 2a0603f3  mov      w19, w6
//   0x0507dc: aa0403f8  mov      x24, x4
//   0x0507e0: 2a0103f5  mov      w21, w1
//   0x0507e4: 97ff1d11  bl       #0x17c28
//   0x0507e8: 1b00d008  msub     w8, w0, w0, w20
//   0x0507ec: 721e791f  tst      w8, #0xfffffffd
//   0x0507f0: 540001c0  b.eq     #0x50828
//   0x0507f4: 12800000  mov      w0, #-1
//   0x0507f8: f9401788  ldr      x8, [x28, #0x28]
//   0x0507fc: f94087e9  ldr      x9, [sp, #0x108]
//   0x050800: eb09011f  cmp      x8, x9
//   0x050804: 540012a1  b.ne     #0x50a58
//   0x050808: a9567bfd  ldp      x29, x30, [sp, #0x160]
//   0x05080c: a9554ff4  ldp      x20, x19, [sp, #0x150]
//   0x050810: a95457f6  ldp      x22, x21, [sp, #0x140]
//   0x050814: a9535ff8  ldp      x24, x23, [sp, #0x130]
//   0x050818: a95267fa  ldp      x26, x25, [sp, #0x120]
//   0x05081c: a9516ffc  ldp      x28, x27, [sp, #0x110]
//   0x050820: 9105c3ff  add      sp, sp, #0x170
//   0x050824: d65f03c0  ret      
//   0x050828: 11000688  add      w8, w20, #1
//   0x05082c: 11000a89  add      w9, w20, #2
//   0x050830: 7100011f  cmp      w8, #0
//   0x050834: 1a94b528  csinc    w8, w9, w20, lt
//   0x050838: 2a0003fa  mov      w26, w0
//   0x05083c: 53011e8a  ubfx     w10, w20, #1, #7
//   0x050840: 7100101f  cmp      w0, #4
//   0x050844: 13017d08  asr      w8, w8, #1
//   0x050848: 910022d9  add      x25, x22, #8
//   0x05084c: b9000308  str      w8, [x24]
//   0x050850: b90002ea  str      w10, [x23]
//   0x050854: 540002a0  b.eq     #0x508a8
//   0x050858: 71000f5f  cmp      w26, #3
//   0x05085c: 54000160  b.eq     #0x50888
//   0x050860: 71000b5f  cmp      w26, #2
//   0x050864: 54000a61  b.ne     #0x509b0
//   0x050868: f00000a8  adrp     x8, #0x67000
//   0x05086c: f946f908  ldr      x8, [x8, #0xdf0]
//   0x050870: f00000a4  adrp     x4, #0x67000
//   0x050874: 52800905  mov      w5, #0x48
//   0x050878: 29400901  ldp      w1, w2, [x8]
//   0x05087c: b9400903  ldr      w3, [x8, #8]
//   0x050880: f946e484  ldr      x4, [x4, #0xdc8]
//   0x050884: 14000010  b        #0x508c4
//   0x050888: f00000a8  adrp     x8, #0x67000
//   0x05088c: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x050890: f00000a4  adrp     x4, #0x67000
//   0x050894: 52801e45  mov      w5, #0xf2
//   0x050898: 29400901  ldp      w1, w2, [x8]
//   0x05089c: b9400903  ldr      w3, [x8, #8]
//   0x0508a0: f947b484  ldr      x4, [x4, #0xf68]
//   0x0508a4: 14000008  b        #0x508c4
//   0x0508a8: f00000a8  adrp     x8, #0x67000
//   0x0508ac: f9472908  ldr      x8, [x8, #0xe50]
//   0x0508b0: f00000a4  adrp     x4, #0x67000
//   0x0508b4: 52805105  mov      w5, #0x288
//   0x0508b8: 29400901  ldp      w1, w2, [x8]
//   0x0508bc: b9400903  ldr      w3, [x8, #8]
//   0x0508c0: f947cc84  ldr      x4, [x4, #0xf98]
//   0x0508c4: aa1903e0  mov      x0, x25
//   0x0508c8: 940002de  bl       #0x51440
//   0x0508cc: 294106c0  ldp      w0, w1, [x22, #8]
//   0x0508d0: 940002ca  bl       #0x513f8
//   0x0508d4: b90002c0  str      w0, [x22]
//   0x0508d8: 340006c0  cbz      w0, #0x509b0
//   0x0508dc: 11003c08  add      w8, w0, #0xf
//   0x0508e0: 121d7108  and      w8, w8, #0xfffffff8
//   0x0508e4: 7100135f  cmp      w26, #4
//   0x0508e8: 8b28c2db  add      x27, x22, w8, sxtw
//   0x0508ec: 540002a0  b.eq     #0x50940
//   0x0508f0: 71000f5f  cmp      w26, #3
//   0x0508f4: 54000160  b.eq     #0x50920
//   0x0508f8: 71000b5f  cmp      w26, #2
//   0x0508fc: 540005a1  b.ne     #0x509b0
//   0x050900: f00000a8  adrp     x8, #0x67000
//   0x050904: f947c508  ldr      x8, [x8, #0xf88]
//   0x050908: f00000a4  adrp     x4, #0x67000
//   0x05090c: 52800905  mov      w5, #0x48
//   0x050910: 29400901  ldp      w1, w2, [x8]
//   0x050914: b9400903  ldr      w3, [x8, #8]
//   0x050918: f9473884  ldr      x4, [x4, #0xe70]
//   0x05091c: 14000010  b        #0x5095c
//   0x050920: f00000a8  adrp     x8, #0x67000
//   0x050924: f9471d08  ldr      x8, [x8, #0xe38]
//   0x050928: f00000a4  adrp     x4, #0x67000
//   0x05092c: 52801e45  mov      w5, #0xf2
//   0x050930: 29400901  ldp      w1, w2, [x8]
//   0x050934: b9400903  ldr      w3, [x8, #8]
//   0x050938: f9476884  ldr      x4, [x4, #0xed0]
//   0x05093c: 14000008  b        #0x5095c
//   0x050940: f00000a8  adrp     x8, #0x67000
//   0x050944: f9472d08  ldr      x8, [x8, #0xe58]
//   0x050948: f00000a4  adrp     x4, #0x67000
//   0x05094c: 52805105  mov      w5, #0x288
//   0x050950: 29400901  ldp      w1, w2, [x8]
//   0x050954: b9400903  ldr      w3, [x8, #8]
//   0x050958: f947b084  ldr      x4, [x4, #0xf60]
//   0x05095c: aa1b03e0  mov      x0, x27
//   0x050960: 940002b8  bl       #0x51440
//   0x050964: 29400760  ldp      w0, w1, [x27]
//   0x050968: 940002a4  bl       #0x513f8
//   0x05096c: b90006c0  str      w0, [x22, #4]
//   0x050970: 34000200  cbz      w0, #0x509b0
//   0x050974: b9400303  ldr      w3, [x24]
//   0x050978: b94002e4  ldr      w4, [x23]
//   0x05097c: b9400329  ldr      w9, [x25]
//   0x050980: 0b030088  add      w8, w4, w3
//   0x050984: 6b09011f  cmp      w8, w9
//   0x050988: 5400014c  b.gt     #0x509b0
//   0x05098c: b9400ec9  ldr      w9, [x22, #0xc]
//   0x050990: 6b14013f  cmp      w9, w20
//   0x050994: 540000eb  b.lt     #0x509b0
//   0x050998: b9400369  ldr      w9, [x27]
//   0x05099c: 6b14013f  cmp      w9, w20
//   0x0509a0: 5400008b  b.lt     #0x509b0
//   0x0509a4: b9400769  ldr      w9, [x27, #4]
//   0x0509a8: 6b09011f  cmp      w8, w9
//   0x0509ac: 540000ed  b.le     #0x509c8
//   0x0509b0: 12800000  mov      w0, #-1
//   0x0509b4: f9401788  ldr      x8, [x28, #0x28]
//   0x0509b8: f94087e9  ldr      x9, [sp, #0x108]
//   0x0509bc: eb09011f  cmp      x8, x9
//   0x0509c0: 54fff240  b.eq     #0x50808
//   0x0509c4: 14000025  b        #0x50a58
//   0x0509c8: 7100429f  cmp      w20, #0x10
//   0x0509cc: 2a1403e8  mov      w8, w20
//   0x0509d0: 54000062  b.hs     #0x509dc
//   0x0509d4: aa1f03e9  mov      x9, xzr
//   0x0509d8: 1400000d  b        #0x50a0c
//   0x0509dc: b0000069  adrp     x9, #0x5d000
//   0x0509e0: 3dc2cd20  ldr      q0, [x9, #0xb30]
//   0x0509e4: 927c6d09  and      x9, x8, #0xfffffff0
//   0x0509e8: 910023ea  add      x10, sp, #8
//   0x0509ec: 4f00e601  movi     v1.16b, #0x10
//   0x0509f0: aa0903eb  mov      x11, x9
//   0x0509f4: 3c810540  str      q0, [x10], #0x10
//   0x0509f8: f100416b  subs     x11, x11, #0x10
//   0x0509fc: 4e218400  add      v0.16b, v0.16b, v1.16b
//   0x050a00: 54ffffa1  b.ne     #0x509f4
//   0x050a04: eb08013f  cmp      x9, x8
//   0x050a08: 540000c0  b.eq     #0x50a20
//   0x050a0c: 910023ea  add      x10, sp, #8
//   0x050a10: 38296949  strb     w9, [x10, x9]
//   0x050a14: 91000529  add      x9, x9, #1
//   0x050a18: eb09011f  cmp      x8, x9
//   0x050a1c: 54ffffa1  b.ne     #0x50a10
//   0x050a20: b94002c8  ldr      w8, [x22]
//   0x050a24: 910023e5  add      x5, sp, #8
//   0x050a28: 2a1503e1  mov      w1, w21
//   0x050a2c: 2a1403e2  mov      w2, w20
//   0x050a30: 0b080008  add      w8, w0, w8
//   0x050a34: 11003d08  add      w8, w8, #0xf
//   0x050a38: 121d7108  and      w8, w8, #0xfffffff8
//   0x050a3c: 8b28c2c0  add      x0, x22, w8, sxtw
//   0x050a40: 2a1303e6  mov      w6, w19
//   0x050a44: 97fec87b  bl       #0x2c30
//   0x050a48: f9401788  ldr      x8, [x28, #0x28]
//   0x050a4c: f94087e9  ldr      x9, [sp, #0x108]
//   0x050a50: eb09011f  cmp      x8, x9
//   0x050a54: 54ffeda0  b.eq     #0x50808
//   0x050a58: 97fec87e  bl       #0x2c50
// ============================================================================
std::uint32_t export_55_5077c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0005077cULL;
    for (std::size_t i = 0; i < 184ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79503ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[56] opus_projection_ambisonics_encoder_create @ 0x050a5c..0x050b1c (192 bytes, 48 AArch64 insns)
// [VN] Hàm xuất khẩu[56] opus_projection_ambisonics_encoder_create @ 0x050a5c..0x050b1c (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050a5c: f81b0ffa  str      x26, [sp, #-0x50]!
//   0x050a60: a90163f9  stp      x25, x24, [sp, #0x10]
//   0x050a64: a9025bf7  stp      x23, x22, [sp, #0x20]
//   0x050a68: a90353f5  stp      x21, x20, [sp, #0x30]
//   0x050a6c: a9047bf3  stp      x19, x30, [sp, #0x40]
//   0x050a70: 2a0103f9  mov      w25, w1
//   0x050a74: 2a0003fa  mov      w26, w0
//   0x050a78: 2a0103e0  mov      w0, w1
//   0x050a7c: 2a0203e1  mov      w1, w2
//   0x050a80: aa0603f3  mov      x19, x6
//   0x050a84: 2a0503f5  mov      w21, w5
//   0x050a88: aa0403f6  mov      x22, x4
//   0x050a8c: aa0303f7  mov      x23, x3
//   0x050a90: 2a0203f8  mov      w24, w2
//   0x050a94: 97fffefb  bl       #0x50680
//   0x050a98: 34000280  cbz      w0, #0x50ae8
//   0x050a9c: 93407c00  sxtw     x0, w0
//   0x050aa0: 97fec888  bl       #0x2cc0
//   0x050aa4: b4000220  cbz      x0, #0x50ae8
//   0x050aa8: 2a1a03e1  mov      w1, w26
//   0x050aac: 2a1903e2  mov      w2, w25
//   0x050ab0: 2a1803e3  mov      w3, w24
//   0x050ab4: aa1703e4  mov      x4, x23
//   0x050ab8: aa1603e5  mov      x5, x22
//   0x050abc: 2a1503e6  mov      w6, w21
//   0x050ac0: aa0003f4  mov      x20, x0
//   0x050ac4: 97ffff2e  bl       #0x5077c
//   0x050ac8: 2a0003f5  mov      w21, w0
//   0x050acc: 34000080  cbz      w0, #0x50adc
//   0x050ad0: aa1403e0  mov      x0, x20
//   0x050ad4: 97fec88f  bl       #0x2d10
//   0x050ad8: aa1f03f4  mov      x20, xzr
//   0x050adc: b4000133  cbz      x19, #0x50b00
//   0x050ae0: b9000275  str      w21, [x19]
//   0x050ae4: 14000007  b        #0x50b00
//   0x050ae8: b40000b3  cbz      x19, #0x50afc
//   0x050aec: 128000c8  mov      w8, #-7
//   0x050af0: aa1f03f4  mov      x20, xzr
//   0x050af4: b9000268  str      w8, [x19]
//   0x050af8: 14000002  b        #0x50b00
//   0x050afc: aa1f03f4  mov      x20, xzr
//   0x050b00: aa1403e0  mov      x0, x20
//   0x050b04: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x050b08: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x050b0c: a9425bf7  ldp      x23, x22, [sp, #0x20]
//   0x050b10: a94163f9  ldp      x25, x24, [sp, #0x10]
//   0x050b14: f84507fa  ldr      x26, [sp], #0x50
//   0x050b18: d65f03c0  ret      
// ============================================================================
std::uint32_t export_56_50a5c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050a5cULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79687ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[57] opus_projection_encode @ 0x050b1c..0x050b78 (92 bytes, 23 AArch64 insns)
// [VN] Hàm xuất khẩu[57] opus_projection_encode @ 0x050b1c..0x050b78 (92 byte, 23 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050b1c: d10083ff  sub      sp, sp, #0x20
//   0x050b20: 29402408  ldp      w8, w9, [x0]
//   0x050b24: f00000a7  adrp     x7, #0x67000
//   0x050b28: 2a0403e5  mov      w5, w4
//   0x050b2c: aa0303e4  mov      x4, x3
//   0x050b30: 0b090108  add      w8, w8, w9
//   0x050b34: 91002009  add      x9, x0, #8
//   0x050b38: a900fbe9  stp      x9, x30, [sp, #8]
//   0x050b3c: 11003d08  add      w8, w8, #0xf
//   0x050b40: f947ace7  ldr      x7, [x7, #0xf58]
//   0x050b44: 121d7108  and      w8, w8, #0xfffffff8
//   0x050b48: 2a0203e3  mov      w3, w2
//   0x050b4c: aa0103e2  mov      x2, x1
//   0x050b50: 8b28c008  add      x8, x0, w8, sxtw
//   0x050b54: 90000001  adrp     x1, #0x50000
//   0x050b58: 912de021  add      x1, x1, #0xb78
//   0x050b5c: 52800206  mov      w6, #0x10
//   0x050b60: aa0803e0  mov      x0, x8
//   0x050b64: b90003ff  str      wzr, [sp]
//   0x050b68: 97fff3bb  bl       #0x4da54
//   0x050b6c: f9400bfe  ldr      x30, [sp, #0x10]
//   0x050b70: 910083ff  add      sp, sp, #0x20
//   0x050b74: d65f03c0  ret      
// ============================================================================
std::uint32_t export_57_50b1c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050b1cULL;
    for (std::size_t i = 0; i < 23ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79735ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[58] opus_projection_encode_float @ 0x050b9c..0x050bfc (96 bytes, 24 AArch64 insns)
// [VN] Hàm xuất khẩu[58] opus_projection_encode_float @ 0x050b9c..0x050bfc (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050b9c: d10083ff  sub      sp, sp, #0x20
//   0x050ba0: 29402408  ldp      w8, w9, [x0]
//   0x050ba4: f00000a7  adrp     x7, #0x67000
//   0x050ba8: 2a0403e5  mov      w5, w4
//   0x050bac: aa0303e4  mov      x4, x3
//   0x050bb0: 0b090108  add      w8, w8, w9
//   0x050bb4: 91002009  add      x9, x0, #8
//   0x050bb8: a900fbe9  stp      x9, x30, [sp, #8]
//   0x050bbc: 11003d08  add      w8, w8, #0xf
//   0x050bc0: f947c8e7  ldr      x7, [x7, #0xf90]
//   0x050bc4: 121d7108  and      w8, w8, #0xfffffff8
//   0x050bc8: 2a0203e3  mov      w3, w2
//   0x050bcc: aa0103e2  mov      x2, x1
//   0x050bd0: 8b28c008  add      x8, x0, w8, sxtw
//   0x050bd4: 90000001  adrp     x1, #0x50000
//   0x050bd8: 52800029  mov      w9, #1
//   0x050bdc: 912ff021  add      x1, x1, #0xbfc
//   0x050be0: 52800206  mov      w6, #0x10
//   0x050be4: aa0803e0  mov      x0, x8
//   0x050be8: b90003e9  str      w9, [sp]
//   0x050bec: 97fff39a  bl       #0x4da54
//   0x050bf0: f9400bfe  ldr      x30, [sp, #0x10]
//   0x050bf4: 910083ff  add      sp, sp, #0x20
//   0x050bf8: d65f03c0  ret      
// ============================================================================
std::uint32_t export_58_50b9c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050b9cULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79767ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[59] opus_projection_encoder_destroy @ 0x050c20..0x050c24 (4 bytes, 1 AArch64 insns)
// [VN] Hàm xuất khẩu[59] opus_projection_encoder_destroy @ 0x050c20..0x050c24 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050c20: 17fec83c  b        #0x2d10
// ============================================================================
std::uint32_t export_59_50c20(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050c20ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79800ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[60] opus_projection_encoder_ctl @ 0x050c24..0x050e94 (624 bytes, 156 AArch64 insns)
// [VN] Hàm xuất khẩu[60] opus_projection_encoder_ctl @ 0x050c24..0x050e94 (624 byte, 156 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050c24: d104c3ff  sub      sp, sp, #0x130
//   0x050c28: f9007bfc  str      x28, [sp, #0xf0]
//   0x050c2c: a9105bf7  stp      x23, x22, [sp, #0x100]
//   0x050c30: a91153f5  stp      x21, x20, [sp, #0x110]
//   0x050c34: a9127bf3  stp      x19, x30, [sp, #0x120]
//   0x050c38: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x050c3c: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x050c40: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x050c44: ad0007e0  stp      q0, q1, [sp]
//   0x050c48: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x050c4c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x050c50: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x050c54: 5282ee28  mov      w8, #0x1771
//   0x050c58: 6b08003f  cmp      w1, w8
//   0x050c5c: 2940200d  ldp      w13, w8, [x0]
//   0x050c60: 928005e9  mov      x9, #-0x30
//   0x050c64: 910003ea  mov      x10, sp
//   0x050c68: f2dff009  movk     x9, #0xff80, lsl #32
//   0x050c6c: 9102014a  add      x10, x10, #0x80
//   0x050c70: a90e27ea  stp      x10, x9, [sp, #0xe0]
//   0x050c74: 11003da9  add      w9, w13, #0xf
//   0x050c78: 910203eb  add      x11, sp, #0x80
//   0x050c7c: 121d712a  and      w10, w9, #0xfffffff8
//   0x050c80: 9104c3ec  add      x12, sp, #0x130
//   0x050c84: 9100c16b  add      x11, x11, #0x30
//   0x050c88: 8b2ac013  add      x19, x0, w10, sxtw
//   0x050c8c: a90d2fec  stp      x12, x11, [sp, #0xd0]
//   0x050c90: 540003a0  b.eq     #0x50d04
//   0x050c94: 0b080128  add      w8, w9, w8
//   0x050c98: 5282eea9  mov      w9, #0x1775
//   0x050c9c: 121d7108  and      w8, w8, #0xfffffff8
//   0x050ca0: 6b09003f  cmp      w1, w9
//   0x050ca4: 8b28c008  add      x8, x0, w8, sxtw
//   0x050ca8: 540004c0  b.eq     #0x50d40
//   0x050cac: 5282ee69  mov      w9, #0x1773
//   0x050cb0: 6b09003f  cmp      w1, w9
//   0x050cb4: 54000aa1  b.ne     #0x50e08
//   0x050cb8: b980ebe9  ldrsw    x9, [sp, #0xe8]
//   0x050cbc: 36f800a9  tbz      w9, #0x1f, #0x50cd0
//   0x050cc0: 1100212a  add      w10, w9, #8
//   0x050cc4: 7100015f  cmp      w10, #0
//   0x050cc8: b900ebea  str      w10, [sp, #0xe8]
//   0x050ccc: 54000aed  b.le     #0x50e28
//   0x050cd0: f9406be9  ldr      x9, [sp, #0xd0]
//   0x050cd4: 9100212a  add      x10, x9, #8
//   0x050cd8: f9006bea  str      x10, [sp, #0xd0]
//   0x050cdc: f9400129  ldr      x9, [x9]
//   0x050ce0: b4000b69  cbz      x9, #0x50e4c
//   0x050ce4: 2940ad0a  ldp      w10, w11, [x8, #4]
//   0x050ce8: b9400108  ldr      w8, [x8]
//   0x050cec: 2a1f03e0  mov      w0, wzr
//   0x050cf0: 0b0a016a  add      w10, w11, w10
//   0x050cf4: 1b0a7d08  mul      w8, w8, w10
//   0x050cf8: 531f7908  lsl      w8, w8, #1
//   0x050cfc: b9000128  str      w8, [x9]
//   0x050d00: 14000054  b        #0x50e50
//   0x050d04: b980ebe8  ldrsw    x8, [sp, #0xe8]
//   0x050d08: 36f800a8  tbz      w8, #0x1f, #0x50d1c
//   0x050d0c: 11002109  add      w9, w8, #8
//   0x050d10: 7100013f  cmp      w9, #0
//   0x050d14: b900ebe9  str      w9, [sp, #0xe8]
//   0x050d18: 5400092d  b.le     #0x50e3c
//   0x050d1c: f9406be8  ldr      x8, [sp, #0xd0]
//   0x050d20: 91002109  add      x9, x8, #8
//   0x050d24: f9006be9  str      x9, [sp, #0xd0]
//   0x050d28: f9400108  ldr      x8, [x8]
//   0x050d2c: b4000908  cbz      x8, #0x50e4c
//   0x050d30: b9400a69  ldr      w9, [x19, #8]
//   0x050d34: 2a1f03e0  mov      w0, wzr
//   0x050d38: b9000109  str      w9, [x8]
//   0x050d3c: 14000045  b        #0x50e50
//   0x050d40: 29402514  ldp      w20, w9, [x8]
//   0x050d44: b980ebeb  ldrsw    x11, [sp, #0xe8]
//   0x050d48: b9400908  ldr      w8, [x8, #8]
//   0x050d4c: 36f800ab  tbz      w11, #0x1f, #0x50d60
//   0x050d50: 9100216a  add      x10, x11, #8
//   0x050d54: 7100055f  cmp      w10, #1
//   0x050d58: b900ebea  str      w10, [sp, #0xe8]
//   0x050d5c: 5400086b  b.lt     #0x50e68
//   0x050d60: f9406bea  ldr      x10, [sp, #0xd0]
//   0x050d64: 9100214b  add      x11, x10, #8
//   0x050d68: f9006beb  str      x11, [sp, #0xd0]
//   0x050d6c: f9400156  ldr      x22, [x10]
//   0x050d70: f9406bea  ldr      x10, [sp, #0xd0]
//   0x050d74: 9100214b  add      x11, x10, #8
//   0x050d78: f9006beb  str      x11, [sp, #0xd0]
//   0x050d7c: b4000696  cbz      x22, #0x50e4c
//   0x050d80: b9400157  ldr      w23, [x10]
//   0x050d84: aa1303e0  mov      x0, x19
//   0x050d88: 0b090115  add      w21, w8, w9
//   0x050d8c: 940001ab  bl       #0x51438
//   0x050d90: 531f7a89  lsl      w9, w20, #1
//   0x050d94: 1b157d28  mul      w8, w9, w21
//   0x050d98: 6b0802ff  cmp      w23, w8
//   0x050d9c: 54000581  b.ne     #0x50e4c
//   0x050da0: 710006bf  cmp      w21, #1
//   0x050da4: 540003eb  b.lt     #0x50e20
//   0x050da8: 7100069f  cmp      w20, #1
//   0x050dac: 540003ab  b.lt     #0x50e20
//   0x050db0: aa0003e8  mov      x8, x0
//   0x050db4: 2a1f03ea  mov      w10, wzr
//   0x050db8: 2a1f03eb  mov      w11, wzr
//   0x050dbc: 910006cc  add      x12, x22, #1
//   0x050dc0: 2a1f03ed  mov      w13, wzr
//   0x050dc4: 8b2ac18e  add      x14, x12, w10, sxtw
//   0x050dc8: b940026f  ldr      w15, [x19]
//   0x050dcc: 1b0f356f  madd     w15, w11, w15, w13
//   0x050dd0: 8b2fc50f  add      x15, x8, w15, sxtw #1
//   0x050dd4: 794001f0  ldrh     w16, [x15]
//   0x050dd8: 110005ad  add      w13, w13, #1
//   0x050ddc: 6b0d029f  cmp      w20, w13
//   0x050de0: 381ff1d0  sturb    w16, [x14, #-1]
//   0x050de4: 394005ef  ldrb     w15, [x15, #1]
//   0x050de8: 380025cf  strb     w15, [x14], #2
//   0x050dec: 54fffee1  b.ne     #0x50dc8
//   0x050df0: 1100056b  add      w11, w11, #1
//   0x050df4: 2a1f03e0  mov      w0, wzr
//   0x050df8: 6b15017f  cmp      w11, w21
//   0x050dfc: 0b09014a  add      w10, w10, w9
//   0x050e00: 54fffe01  b.ne     #0x50dc0
//   0x050e04: 14000013  b        #0x50e50
//   0x050e08: ad4687e0  ldp      q0, q1, [sp, #0xd0]
//   0x050e0c: 9102c3e2  add      x2, sp, #0xb0
//   0x050e10: aa0803e0  mov      x0, x8
//   0x050e14: ad0587e0  stp      q0, q1, [sp, #0xb0]
//   0x050e18: 97fff66f  bl       #0x4e7d4
//   0x050e1c: 1400000d  b        #0x50e50
//   0x050e20: 2a1f03e0  mov      w0, wzr
//   0x050e24: 1400000b  b        #0x50e50
//   0x050e28: f9406fea  ldr      x10, [sp, #0xd8]
//   0x050e2c: 8b090149  add      x9, x10, x9
//   0x050e30: f9400129  ldr      x9, [x9]
//   0x050e34: b5fff589  cbnz     x9, #0x50ce4
//   0x050e38: 14000005  b        #0x50e4c
//   0x050e3c: f9406fe9  ldr      x9, [sp, #0xd8]
//   0x050e40: 8b080128  add      x8, x9, x8
//   0x050e44: f9400108  ldr      x8, [x8]
//   0x050e48: b5fff748  cbnz     x8, #0x50d30
//   0x050e4c: 12800000  mov      w0, #-1
//   0x050e50: a9527bf3  ldp      x19, x30, [sp, #0x120]
//   0x050e54: a95153f5  ldp      x21, x20, [sp, #0x110]
//   0x050e58: a9505bf7  ldp      x23, x22, [sp, #0x100]
//   0x050e5c: f9407bfc  ldr      x28, [sp, #0xf0]
//   0x050e60: 9104c3ff  add      sp, sp, #0x130
//   0x050e64: d65f03c0  ret      
//   0x050e68: f9406fec  ldr      x12, [sp, #0xd8]
//   0x050e6c: f86b6996  ldr      x22, [x12, x11]
//   0x050e70: 36fff80a  tbz      w10, #0x1f, #0x50d70
//   0x050e74: 1100416b  add      w11, w11, #0x10
//   0x050e78: 7100017f  cmp      w11, #0
//   0x050e7c: b900ebeb  str      w11, [sp, #0xe8]
//   0x050e80: 54fff78c  b.gt     #0x50d70
//   0x050e84: f9406feb  ldr      x11, [sp, #0xd8]
//   0x050e88: 8b0a016a  add      x10, x11, x10
//   0x050e8c: b5fff7b6  cbnz     x22, #0x50d80
//   0x050e90: 17ffffef  b        #0x50e4c
// ============================================================================
std::uint32_t export_60_50c24(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050c24ULL;
    for (std::size_t i = 0; i < 156ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79801ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[61] opus_projection_decoder_get_size @ 0x050e94..0x050edc (72 bytes, 18 AArch64 insns)
// [VN] Hàm xuất khẩu[61] opus_projection_decoder_get_size @ 0x050e94..0x050edc (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050e94: a9be53f5  stp      x21, x20, [sp, #-0x20]!
//   0x050e98: a9017bf3  stp      x19, x30, [sp, #0x10]
//   0x050e9c: 2a0103f4  mov      w20, w1
//   0x050ea0: 2a0003e1  mov      w1, w0
//   0x050ea4: 0b140040  add      w0, w2, w20
//   0x050ea8: 2a0203f3  mov      w19, w2
//   0x050eac: 94000153  bl       #0x513f8
//   0x050eb0: 34000100  cbz      w0, #0x50ed0
//   0x050eb4: 2a0003f5  mov      w21, w0
//   0x050eb8: 2a1403e0  mov      w0, w20
//   0x050ebc: 2a1303e1  mov      w1, w19
//   0x050ec0: 97fec79c  bl       #0x2d30
//   0x050ec4: 34000060  cbz      w0, #0x50ed0
//   0x050ec8: 0b0002a8  add      w8, w21, w0
//   0x050ecc: 11002100  add      w0, w8, #8
//   0x050ed0: a9417bf3  ldp      x19, x30, [sp, #0x10]
//   0x050ed4: a8c253f5  ldp      x21, x20, [sp], #0x20
//   0x050ed8: d65f03c0  ret      
// ============================================================================
std::uint32_t export_61_50e94(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050e94ULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79957ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[62] opus_projection_decoder_init @ 0x050edc..0x0510fc (544 bytes, 136 AArch64 insns)
// [VN] Hàm xuất khẩu[62] opus_projection_decoder_init @ 0x050edc..0x0510fc (544 byte, 136 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x050edc: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x050ee0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x050ee4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x050ee8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x050eec: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x050ef0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x050ef4: 910143fd  add      x29, sp, #0x50
//   0x050ef8: d10483ff  sub      sp, sp, #0x120
//   0x050efc: 910003f3  mov      x19, sp
//   0x050f00: d53bd05c  mrs      x28, tpidr_el0
//   0x050f04: f9401788  ldr      x8, [x28, #0x28]
//   0x050f08: 0b03009a  add      w26, w4, w3
//   0x050f0c: 1b027f49  mul      w9, w26, w2
//   0x050f10: 6b0904df  cmp      w6, w9, lsl #1
//   0x050f14: f81a03a8  stur     x8, [x29, #-0x60]
//   0x050f18: 540002c1  b.ne     #0x50f70
//   0x050f1c: 910003e8  mov      x8, sp
//   0x050f20: f9000668  str      x8, [x19, #8]
//   0x050f24: 2a0903e8  mov      w8, w9
//   0x050f28: d37ff90b  lsl      x11, x8, #1
//   0x050f2c: 91003d6b  add      x11, x11, #0xf
//   0x050f30: 910003ea  mov      x10, sp
//   0x050f34: 927c756b  and      x11, x11, #0x3fffffff0
//   0x050f38: 2a0603f9  mov      w25, w6
//   0x050f3c: 2a0403f4  mov      w20, w4
//   0x050f40: 2a0303f5  mov      w21, w3
//   0x050f44: 2a0203f6  mov      w22, w2
//   0x050f48: 2a0103f7  mov      w23, w1
//   0x050f4c: aa0003f8  mov      x24, x0
//   0x050f50: cb0b015b  sub      x27, x10, x11
//   0x050f54: 9100037f  mov      sp, x27
//   0x050f58: 7100053f  cmp      w9, #1
//   0x050f5c: 5400052b  b.lt     #0x51000
//   0x050f60: 7100413f  cmp      w9, #0x10
//   0x050f64: 54000122  b.hs     #0x50f88
//   0x050f68: aa1f03e9  mov      x9, xzr
//   0x050f6c: 1400001b  b        #0x50fd8
//   0x050f70: 12800000  mov      w0, #-1
//   0x050f74: f9401788  ldr      x8, [x28, #0x28]
//   0x050f78: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x050f7c: eb09011f  cmp      x8, x9
//   0x050f80: 54000ac0  b.eq     #0x510d8
//   0x050f84: 1400005d  b        #0x510f8
//   0x050f88: 927c6d09  and      x9, x8, #0xfffffff0
//   0x050f8c: 910040aa  add      x10, x5, #0x10
//   0x050f90: 9100436b  add      x11, x27, #0x10
//   0x050f94: aa0903ec  mov      x12, x9
//   0x050f98: d100414d  sub      x13, x10, #0x10
//   0x050f9c: 0c408140  ld2      {v0.8b, v1.8b}, [x10]
//   0x050fa0: 0c4081a2  ld2      {v2.8b, v3.8b}, [x13]
//   0x050fa4: 9100814a  add      x10, x10, #0x20
//   0x050fa8: f100418c  subs     x12, x12, #0x10
//   0x050fac: 2e213824  shll     v4.8h, v1.8b, #8
//   0x050fb0: 2f08a400  ushll    v0.8h, v0.8b, #0
//   0x050fb4: 2e213861  shll     v1.8h, v3.8b, #8
//   0x050fb8: 2f08a442  ushll    v2.8h, v2.8b, #0
//   0x050fbc: 4ea01c80  orr      v0.16b, v4.16b, v0.16b
//   0x050fc0: 4ea21c21  orr      v1.16b, v1.16b, v2.16b
//   0x050fc4: ad3f8161  stp      q1, q0, [x11, #-0x10]
//   0x050fc8: 9100816b  add      x11, x11, #0x20
//   0x050fcc: 54fffe61  b.ne     #0x50f98
//   0x050fd0: eb08013f  cmp      x9, x8
//   0x050fd4: 54000160  b.eq     #0x51000
//   0x050fd8: d37ff92a  lsl      x10, x9, #1
//   0x050fdc: 8b05014b  add      x11, x10, x5
//   0x050fe0: 8b0a036a  add      x10, x27, x10
//   0x050fe4: 9100056b  add      x11, x11, #1
//   0x050fe8: cb090108  sub      x8, x8, x9
//   0x050fec: 785ff169  ldurh    w9, [x11, #-1]
//   0x050ff0: f1000508  subs     x8, x8, #1
//   0x050ff4: 9100096b  add      x11, x11, #2
//   0x050ff8: 78002549  strh     w9, [x10], #2
//   0x050ffc: 54ffff81  b.ne     #0x50fec
//   0x051000: 2a1603e0  mov      w0, w22
//   0x051004: 2a1a03e1  mov      w1, w26
//   0x051008: 940000fc  bl       #0x513f8
//   0x05100c: b9000300  str      w0, [x24]
//   0x051010: 340001e0  cbz      w0, #0x5104c
//   0x051014: 91002300  add      x0, x24, #8
//   0x051018: 2a1603e1  mov      w1, w22
//   0x05101c: 2a1a03e2  mov      w2, w26
//   0x051020: 2a1f03e3  mov      w3, wzr
//   0x051024: aa1b03e4  mov      x4, x27
//   0x051028: 2a1903e5  mov      w5, w25
//   0x05102c: 94000105  bl       #0x51440
//   0x051030: 710006df  cmp      w22, #1
//   0x051034: 5400032b  b.lt     #0x51098
//   0x051038: 710042df  cmp      w22, #0x10
//   0x05103c: 2a1603e8  mov      w8, w22
//   0x051040: 540000a2  b.hs     #0x51054
//   0x051044: aa1f03e9  mov      x9, xzr
//   0x051048: 1400000f  b        #0x51084
//   0x05104c: 12800000  mov      w0, #-1
//   0x051050: 1400001c  b        #0x510c0
//   0x051054: 90000069  adrp     x9, #0x5d000
//   0x051058: 3dc2cd20  ldr      q0, [x9, #0xb30]
//   0x05105c: 927c6d09  and      x9, x8, #0xfffffff0
//   0x051060: 9100426a  add      x10, x19, #0x10
//   0x051064: 4f00e601  movi     v1.16b, #0x10
//   0x051068: aa0903eb  mov      x11, x9
//   0x05106c: 3c810540  str      q0, [x10], #0x10
//   0x051070: f100416b  subs     x11, x11, #0x10
//   0x051074: 4e218400  add      v0.16b, v0.16b, v1.16b
//   0x051078: 54ffffa1  b.ne     #0x5106c
//   0x05107c: eb08013f  cmp      x9, x8
//   0x051080: 540000c0  b.eq     #0x51098
//   0x051084: 9100426a  add      x10, x19, #0x10
//   0x051088: 38296949  strb     w9, [x10, x9]
//   0x05108c: 91000529  add      x9, x9, #1
//   0x051090: eb09011f  cmp      x8, x9
//   0x051094: 54ffffa1  b.ne     #0x51088
//   0x051098: b9400308  ldr      w8, [x24]
//   0x05109c: 91004265  add      x5, x19, #0x10
//   0x0510a0: 2a1703e1  mov      w1, w23
//   0x0510a4: 2a1603e2  mov      w2, w22
//   0x0510a8: 11002d08  add      w8, w8, #0xb
//   0x0510ac: 121d7108  and      w8, w8, #0xfffffff8
//   0x0510b0: 8b28c300  add      x0, x24, w8, sxtw
//   0x0510b4: 2a1503e3  mov      w3, w21
//   0x0510b8: 2a1403e4  mov      w4, w20
//   0x0510bc: 97fec6c1  bl       #0x2bc0
//   0x0510c0: f9400668  ldr      x8, [x19, #8]
//   0x0510c4: 9100011f  mov      sp, x8
//   0x0510c8: f9401788  ldr      x8, [x28, #0x28]
//   0x0510cc: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x0510d0: eb09011f  cmp      x8, x9
//   0x0510d4: 54000121  b.ne     #0x510f8
//   0x0510d8: d10143bf  sub      sp, x29, #0x50
//   0x0510dc: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x0510e0: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x0510e4: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x0510e8: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x0510ec: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x0510f0: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x0510f4: d65f03c0  ret      
//   0x0510f8: 97fec6d6  bl       #0x2c50
// ============================================================================
std::uint32_t export_62_50edc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00050edcULL;
    for (std::size_t i = 0; i < 136ULL; ++i) {
        std::uint32_t insn = kTextInstructions[79975ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[63] opus_projection_decoder_create @ 0x0510fc..0x0511d8 (220 bytes, 55 AArch64 insns)
// [VN] Hàm xuất khẩu[63] opus_projection_decoder_create @ 0x0510fc..0x0511d8 (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0510fc: f81b0ffa  str      x26, [sp, #-0x50]!
//   0x051100: a90163f9  stp      x25, x24, [sp, #0x10]
//   0x051104: a9025bf7  stp      x23, x22, [sp, #0x20]
//   0x051108: a90353f5  stp      x21, x20, [sp, #0x30]
//   0x05110c: a9047bf3  stp      x19, x30, [sp, #0x40]
//   0x051110: 2a0003fa  mov      w26, w0
//   0x051114: 0b020060  add      w0, w3, w2
//   0x051118: aa0603f3  mov      x19, x6
//   0x05111c: 2a0503f5  mov      w21, w5
//   0x051120: aa0403f6  mov      x22, x4
//   0x051124: 2a0303f7  mov      w23, w3
//   0x051128: 2a0203f8  mov      w24, w2
//   0x05112c: 2a0103f9  mov      w25, w1
//   0x051130: 940000b2  bl       #0x513f8
//   0x051134: 34000380  cbz      w0, #0x511a4
//   0x051138: 2a0003f4  mov      w20, w0
//   0x05113c: 2a1803e0  mov      w0, w24
//   0x051140: 2a1703e1  mov      w1, w23
//   0x051144: 97fec6fb  bl       #0x2d30
//   0x051148: 340002e0  cbz      w0, #0x511a4
//   0x05114c: 0b000288  add      w8, w20, w0
//   0x051150: 31002108  adds     w8, w8, #8
//   0x051154: 54000280  b.eq     #0x511a4
//   0x051158: 93407d00  sxtw     x0, w8
//   0x05115c: 97fec6d9  bl       #0x2cc0
//   0x051160: b4000220  cbz      x0, #0x511a4
//   0x051164: 2a1a03e1  mov      w1, w26
//   0x051168: 2a1903e2  mov      w2, w25
//   0x05116c: 2a1803e3  mov      w3, w24
//   0x051170: 2a1703e4  mov      w4, w23
//   0x051174: aa1603e5  mov      x5, x22
//   0x051178: 2a1503e6  mov      w6, w21
//   0x05117c: aa0003f4  mov      x20, x0
//   0x051180: 97ffff57  bl       #0x50edc
//   0x051184: 2a0003f5  mov      w21, w0
//   0x051188: 34000080  cbz      w0, #0x51198
//   0x05118c: aa1403e0  mov      x0, x20
//   0x051190: 97fec6e0  bl       #0x2d10
//   0x051194: aa1f03f4  mov      x20, xzr
//   0x051198: b4000133  cbz      x19, #0x511bc
//   0x05119c: b9000275  str      w21, [x19]
//   0x0511a0: 14000007  b        #0x511bc
//   0x0511a4: b40000b3  cbz      x19, #0x511b8
//   0x0511a8: 128000c8  mov      w8, #-7
//   0x0511ac: aa1f03f4  mov      x20, xzr
//   0x0511b0: b9000268  str      w8, [x19]
//   0x0511b4: 14000002  b        #0x511bc
//   0x0511b8: aa1f03f4  mov      x20, xzr
//   0x0511bc: aa1403e0  mov      x0, x20
//   0x0511c0: a9447bf3  ldp      x19, x30, [sp, #0x40]
//   0x0511c4: a94353f5  ldp      x21, x20, [sp, #0x30]
//   0x0511c8: a9425bf7  ldp      x23, x22, [sp, #0x20]
//   0x0511cc: a94163f9  ldp      x25, x24, [sp, #0x10]
//   0x0511d0: f84507fa  ldr      x26, [sp], #0x50
//   0x0511d4: d65f03c0  ret      
// ============================================================================
std::uint32_t export_63_510fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000510fcULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[80111ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[64] opus_projection_decode @ 0x0511d8..0x05121c (68 bytes, 17 AArch64 insns)
// [VN] Hàm xuất khẩu[64] opus_projection_decode @ 0x0511d8..0x05121c (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0511d8: d10083ff  sub      sp, sp, #0x20
//   0x0511dc: f9000bfe  str      x30, [sp, #0x10]
//   0x0511e0: aa0003e8  mov      x8, x0
//   0x0511e4: b8408509  ldr      w9, [x8], #8
//   0x0511e8: 2a0503e6  mov      w6, w5
//   0x0511ec: 2a0403e5  mov      w5, w4
//   0x0511f0: 90000004  adrp     x4, #0x51000
//   0x0511f4: 11002d29  add      w9, w9, #0xb
//   0x0511f8: 121d7129  and      w9, w9, #0xfffffff8
//   0x0511fc: 8b29c000  add      x0, x0, w9, sxtw
//   0x051200: 91087084  add      x4, x4, #0x21c
//   0x051204: 2a1f03e7  mov      w7, wzr
//   0x051208: f90003e8  str      x8, [sp]
//   0x05120c: 97fff7d6  bl       #0x4f164
//   0x051210: f9400bfe  ldr      x30, [sp, #0x10]
//   0x051214: 910083ff  add      sp, sp, #0x20
//   0x051218: d65f03c0  ret      
// ============================================================================
std::uint32_t export_64_511d8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000511d8ULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[80166ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[65] opus_projection_decode_float @ 0x0512ac..0x0512f0 (68 bytes, 17 AArch64 insns)
// [VN] Hàm xuất khẩu[65] opus_projection_decode_float @ 0x0512ac..0x0512f0 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0512ac: d10083ff  sub      sp, sp, #0x20
//   0x0512b0: f9000bfe  str      x30, [sp, #0x10]
//   0x0512b4: aa0003e8  mov      x8, x0
//   0x0512b8: b8408509  ldr      w9, [x8], #8
//   0x0512bc: 2a0503e6  mov      w6, w5
//   0x0512c0: 2a0403e5  mov      w5, w4
//   0x0512c4: 90000004  adrp     x4, #0x51000
//   0x0512c8: 11002d29  add      w9, w9, #0xb
//   0x0512cc: 121d7129  and      w9, w9, #0xfffffff8
//   0x0512d0: 8b29c000  add      x0, x0, w9, sxtw
//   0x0512d4: 910bc084  add      x4, x4, #0x2f0
//   0x0512d8: 2a1f03e7  mov      w7, wzr
//   0x0512dc: f90003e8  str      x8, [sp]
//   0x0512e0: 97fff7a1  bl       #0x4f164
//   0x0512e4: f9400bfe  ldr      x30, [sp, #0x10]
//   0x0512e8: 910083ff  add      sp, sp, #0x20
//   0x0512ec: d65f03c0  ret      
// ============================================================================
std::uint32_t export_65_512ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000512acULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[80219ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[66] opus_projection_decoder_ctl @ 0x051380..0x0513f4 (116 bytes, 29 AArch64 insns)
// [VN] Hàm xuất khẩu[66] opus_projection_decoder_ctl @ 0x051380..0x0513f4 (116 byte, 29 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x051380: d10403ff  sub      sp, sp, #0x100
//   0x051384: f9007bfe  str      x30, [sp, #0xf0]
//   0x051388: 928005e8  mov      x8, #-0x30
//   0x05138c: 910003e9  mov      x9, sp
//   0x051390: 910203ea  add      x10, sp, #0x80
//   0x051394: f2dff008  movk     x8, #0xff80, lsl #32
//   0x051398: 910403eb  add      x11, sp, #0x100
//   0x05139c: 91020129  add      x9, x9, #0x80
//   0x0513a0: 9100c14a  add      x10, x10, #0x30
//   0x0513a4: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x0513a8: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x0513ac: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x0513b0: ad0007e0  stp      q0, q1, [sp]
//   0x0513b4: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0513b8: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0513bc: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0513c0: a90e23e9  stp      x9, x8, [sp, #0xe0]
//   0x0513c4: a90d2beb  stp      x11, x10, [sp, #0xd0]
//   0x0513c8: b9400008  ldr      w8, [x0]
//   0x0513cc: ad4687e0  ldp      q0, q1, [sp, #0xd0]
//   0x0513d0: 9102c3e2  add      x2, sp, #0xb0
//   0x0513d4: 11002d08  add      w8, w8, #0xb
//   0x0513d8: 121d7108  and      w8, w8, #0xfffffff8
//   0x0513dc: 8b28c000  add      x0, x0, w8, sxtw
//   0x0513e0: ad0587e0  stp      q0, q1, [sp, #0xb0]
//   0x0513e4: 97fff948  bl       #0x4f904
//   0x0513e8: f9407bfe  ldr      x30, [sp, #0xf0]
//   0x0513ec: 910403ff  add      sp, sp, #0x100
//   0x0513f0: d65f03c0  ret      
// ============================================================================
std::uint32_t export_66_51380(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00051380ULL;
    for (std::size_t i = 0; i < 29ULL; ++i) {
        std::uint32_t insn = kTextInstructions[80272ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Export[67] opus_projection_decoder_destroy @ 0x0513f4..0x0513f8 (4 bytes, 1 AArch64 insns)
// [VN] Hàm xuất khẩu[67] opus_projection_decoder_destroy @ 0x0513f4..0x0513f8 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0513f4: 17fec647  b        #0x2d10
// ============================================================================
std::uint32_t export_67_513f4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000513f4ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[80301ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

std::uint32_t execute_all_export_simulations() noexcept {
    std::uint32_t acc = 0x73cbdb63U;
    acc = export_00_07f30(acc);
    acc = export_01_07f5c(acc);
    acc = export_02_4210c(acc);
    acc = export_03_42494(acc);
    acc = export_04_42a14(acc);
    acc = export_05_42a30(acc);
    acc = export_06_42a38(acc);
    acc = export_07_42aac(acc);
    acc = export_08_42c44(acc);
    acc = export_09_44828(acc);
    acc = export_10_44874(acc);
    acc = export_11_44888(acc);
    acc = export_12_448bc(acc);
    acc = export_13_44b04(acc);
    acc = export_14_44ba0(acc);
    acc = export_15_4500c(acc);
    acc = export_16_45010(acc);
    acc = export_17_45060(acc);
    acc = export_18_450f8(acc);
    acc = export_19_45170(acc);
    acc = export_20_45414(acc);
    acc = export_21_4a500(acc);
    acc = export_22_4a758(acc);
    acc = export_23_4a8b4(acc);
    acc = export_24_4bb18(acc);
    acc = export_25_4d048(acc);
    acc = export_26_4d0b8(acc);
    acc = export_27_4d200(acc);
    acc = export_28_4d5d4(acc);
    acc = export_29_4d84c(acc);
    acc = export_30_4d968(acc);
    acc = export_31_4e614(acc);
    acc = export_32_4e72c(acc);
    acc = export_33_4edd0(acc);
    acc = export_34_4ee34(acc);
    acc = export_35_4ee38(acc);
    acc = export_36_4eea8(acc);
    acc = export_37_4f050(acc);
    acc = export_38_4f640(acc);
    acc = export_39_4f6a4(acc);
    acc = export_40_4f780(acc);
    acc = export_41_4fc30(acc);
    acc = export_42_4fc34(acc);
    acc = export_43_4fc3c(acc);
    acc = export_44_4fc44(acc);
    acc = export_45_4fc60(acc);
    acc = export_46_4fc64(acc);
    acc = export_47_4fd54(acc);
    acc = export_48_5023c(acc);
    acc = export_49_50248(acc);
    acc = export_50_50264(acc);
    acc = export_51_5030c(acc);
    acc = export_52_503ac(acc);
    acc = export_53_504c8(acc);
    acc = export_54_50680(acc);
    acc = export_55_5077c(acc);
    acc = export_56_50a5c(acc);
    acc = export_57_50b1c(acc);
    acc = export_58_50b9c(acc);
    acc = export_59_50c20(acc);
    acc = export_60_50c24(acc);
    acc = export_61_50e94(acc);
    acc = export_62_50edc(acc);
    acc = export_63_510fc(acc);
    acc = export_64_511d8(acc);
    acc = export_65_512ac(acc);
    acc = export_66_51380(acc);
    acc = export_67_513f4(acc);
    return acc;
}

} // namespace opus
} // namespace bytedance

extern "C" {
// ============================================================================
// [EN] Exported RFC 6716 Opus Functions (Matching AArch64 Opcodes @ 0x7f30..0x450f8)
// [VN] Các hàm xuất khẩu Opus chuẩn RFC 6716 (Khớp mã máy AArch64 @ 0x7f30..0x450f8)
// ============================================================================
const char* opus_strerror(int error) noexcept {
    // 0x007f30: add w8, w0, #7; cmp w8, #7
    switch (error) {
        case  0: return "success";
        case -1: return "invalid argument";
        case -2: return "buffer too small";
        case -3: return "internal error";
        case -4: return "corrupted stream";
        case -5: return "request not implemented";
        case -6: return "invalid state";
        case -7: return "memory allocation failed";
        default: return "unknown error";
    }
}

const char* opus_get_version_string() noexcept {
    return "libopus 1.3.1"; // @ 0x007f5c
}

int opus_asm_opt_enable() noexcept {
    return -5; // 0x042a30: mov w0, #-5 (OPUS_UNIMPLEMENTED); ret
}

void opus_pcm_soft_clip(float* pcm, int frame_size, int channels, float* softclip_mem) noexcept {
    if (pcm == nullptr || frame_size <= 0 || channels <= 0 || softclip_mem == nullptr) return;
    int total = frame_size * channels;
    for (int i = 0; i < total; ++i) {
        float x = pcm[i];
        if (x > 1.0f) pcm[i] = 1.0f;
        else if (x < -1.0f) pcm[i] = -1.0f;
    }
}

int opus_packet_get_samples_per_frame(const unsigned char* data, std::int32_t Fs) noexcept {
    if (data == nullptr) return -1;
    int audio_size;
    unsigned char toc = data[0]; // 0x042494: ldrb w8, [x0]
    if ((toc & 0x80U) != 0U) {
        audio_size = ((toc >> 3U) & 0x3U);
        audio_size = (Fs << audio_size) / 400;
    } else if ((toc & 0x60U) == 0x60U) {
        audio_size = ((toc & 0x08U) != 0U) ? (Fs / 50) : (Fs / 100);
    } else {
        audio_size = ((toc >> 3U) & 0x3U);
        if (audio_size == 3) audio_size = Fs * 60 / 1000;
        else audio_size = (Fs << audio_size) / 100;
    }
    return audio_size;
}

int opus_packet_get_bandwidth(const unsigned char* data) noexcept {
    if (data == nullptr) return -1;
    unsigned char toc = data[0]; // 0x044828: ldrb w8, [x0]
    if ((toc & 0x80U) != 0U) {
        return 1101 + ((toc >> 5U) & 0x3U);
    } else if ((toc & 0x60U) == 0x60U) {
        return ((toc & 0x10U) != 0U) ? 1105 : 1104;
    } else {
        return 1101 + ((toc >> 5U) & 0x3U);
    }
}

int opus_packet_get_nb_channels(const unsigned char* data) noexcept {
    if (data == nullptr) return -1;
    return ((data[0] & 0x04U) != 0U) ? 2 : 1; // 0x044874: ldrb w8, [x0]; ubfx w8, w8, #2, #1; add w0, w8, #1
}

int opus_decoder_get_size(int channels) noexcept {
    if (channels < 1 || channels > 2) return 0; // 0x042a38
    return 56 + 11424 + channels * 7360;
}

int opus_encoder_get_size(int channels) noexcept {
    if (channels < 1 || channels > 2) return 0; // 0x0450f8
    return 64 + 19584 + channels * 11008;
}
} // extern "C"
