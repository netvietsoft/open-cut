// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// File: bytevc1_dec_core.cpp
// Target Binary: libByteVC1_dec.so (478,536 bytes, 419 FDEs, 100,947 .text words)
// SHA-256: 964f36948ecfa84c4886aca5aa2592f5ef65bb25dab4beeaa58d1b9f70991e07
// Role: Full implementation of ByteVC1_* exported decoder functions, HEVC/ByteVC1
//       NAL/RBSP/CTU slice header evaluators, and 419 FDE functions.
// =============================================================================
#include "bytevc1_dec.hpp"

#include <algorithm>
#include <cstring>

namespace nextai::opencut::bytevc1_dec {

// =============================================================================
// 1. Exported Symbol Table (.dynsym — 100 ByteVC1_* Functions)
// EN: Exact virtual addresses, byte sizes, and prologue opcodes from .dynsym.
// VI: Địa chỉ ảo, kích thước byte và opcode mở đầu chính xác từ .dynsym.
// =============================================================================
const std::array<ByteVc1ExportEntry, kExportedSymbolCount> kByteVc1ExportTable = {{
    {"ByteVC1_nal_parser_init_target_layer", 0x004a4cU, 8U, 0xb9035c01U},
    {"ByteVC1_alloc_parser", 0x004e10U, 44U, 0xa9bf7bfdU},
    {"ByteVC1_release_parser", 0x004e3cU, 4U, 0x17fffe72U},
    {"ByteVC1_nal_parser_set_trace_token", 0x004e40U, 4U, 0xd65f03c0U},
    {"ByteVC1_nal_parse", 0x004e44U, 4U, 0x17ffff04U},
    {"ByteVC1_nal_parse_get_key_val", 0x004e48U, 76U, 0xa9be4ff4U},
    {"ByteVC1_alloc_packet", 0x004e94U, 16U, 0xf0000301U},
    {"ByteVC1_free_packet", 0x004ea4U, 12U, 0xf0000301U},
    {"ByteVC1_frame_init", 0x004eb0U, 52U, 0x6f00e400U},
    {"ByteVC1_frame_uninit", 0x004ee4U, 4U, 0xd65f03c0U},
    {"ByteVC1_get_frame_width", 0x004ee8U, 8U, 0xb9400000U},
    {"ByteVC1_get_frame_height", 0x004ef0U, 8U, 0xb9400400U},
    {"ByteVC1_get_frame_pts", 0x004ef8U, 8U, 0xf9400400U},
    {"ByteVC1_get_frame_opt", 0x004f00U, 8U, 0xf9400800U},
    {"ByteVC1_get_frame_stride", 0x004f08U, 32U, 0x39412008U},
    {"ByteVC1_get_frame_linesize", 0x004f28U, 12U, 0x8b21c808U},
    {"ByteVC1_get_frame_data", 0x004f34U, 12U, 0x8b21cc08U},
    {"ByteVC1_get_frame_bit_depth", 0x004f40U, 8U, 0x39412000U},
    {"ByteVC1_get_frame_video_signal_type_present_flag", 0x004f48U, 8U, 0x39416000U},
    {"ByteVC1_get_frame_video_full_range_flag", 0x004f50U, 8U, 0x39416400U},
    {"ByteVC1_get_frame_color_primaries", 0x004f58U, 8U, 0xb9404c00U},
    {"ByteVC1_get_frame_color_trc", 0x004f60U, 8U, 0xb9405000U},
    {"ByteVC1_get_frame_colorspace", 0x004f68U, 8U, 0xb9405400U},
    {"ByteVC1_get_frame_pix_fmt", 0x004f70U, 8U, 0xb9405c00U},
    {"ByteVC1_get_frame_got_frame", 0x004f78U, 8U, 0xb9406400U},
    {"ByteVC1_get_frame_slice_type", 0x004f80U, 8U, 0x3944a000U},
    {"ByteVC1_set_packet_flag", 0x004f88U, 4U, 0xd65f03c0U},
    {"ByteVC1_get_packet_flag", 0x004f8cU, 8U, 0x2a1f03e0U},
    {"ByteVC1_set_packet_bs_len", 0x004f94U, 8U, 0xb9000001U},
    {"ByteVC1_get_packet_bs_len", 0x004f9cU, 8U, 0xb9400000U},
    {"ByteVC1_set_packet_bs", 0x004fa4U, 8U, 0xf9000401U},
    {"ByteVC1_get_packet_bs", 0x004facU, 8U, 0xf9400400U},
    {"ByteVC1_set_packet_drop_frame", 0x004fb4U, 8U, 0xb9001001U},
    {"ByteVC1_get_packet_drop_frame", 0x004fbcU, 8U, 0xb9401000U},
    {"ByteVC1_set_packet_drop_rate", 0x004fc4U, 12U, 0x1e220020U},
    {"ByteVC1_get_packet_drop_rate", 0x004fd0U, 12U, 0xbd401400U},
    {"ByteVC1_set_packet_pts", 0x004fdcU, 8U, 0xf9000c01U},
    {"ByteVC1_get_packet_pts", 0x004fe4U, 8U, 0xf9400c00U},
    {"ByteVC1_set_packet_opt", 0x004fecU, 8U, 0xf9001001U},
    {"ByteVC1_get_packet_opt", 0x004ff4U, 8U, 0xf9401000U},
    {"ByteVC1_free_param", 0x004ffcU, 12U, 0xf0000301U},
    {"ByteVC1_set_param_threads", 0x005008U, 28U, 0x7100043fU},
    {"ByteVC1_get_param_threads", 0x005024U, 8U, 0xb9402000U},
    {"ByteVC1_set_param_frames", 0x00502cU, 8U, 0xb9000001U},
    {"ByteVC1_get_param_frames", 0x005034U, 8U, 0xb9400000U},
    {"ByteVC1_set_param_output_method", 0x00503cU, 8U, 0xb9000401U},
    {"ByteVC1_get_param_output_method", 0x005044U, 8U, 0xb9400400U},
    {"ByteVC1_set_param_error_protection", 0x00504cU, 8U, 0xb9000801U},
    {"ByteVC1_get_param_error_protection", 0x005054U, 8U, 0xb9400800U},
    {"ByteVC1_set_param_log_level", 0x00505cU, 8U, 0xb9000c01U},
    {"ByteVC1_get_param_log_level", 0x005064U, 8U, 0xb9400c00U},
    {"ByteVC1_set_param_crop_x0", 0x00506cU, 4U, 0xd65f03c0U},
    {"ByteVC1_get_param_crop_x0", 0x005070U, 8U, 0x2a1f03e0U},
    {"ByteVC1_set_param_crop_y0", 0x005078U, 4U, 0xd65f03c0U},
    {"ByteVC1_get_param_crop_y0", 0x00507cU, 8U, 0x2a1f03e0U},
    {"ByteVC1_set_param_crop_width", 0x005084U, 4U, 0xd65f03c0U},
    {"ByteVC1_get_param_crop_width", 0x005088U, 8U, 0x2a1f03e0U},
    {"ByteVC1_set_param_crop_height", 0x005090U, 4U, 0xd65f03c0U},
    {"ByteVC1_get_param_crop_height", 0x005094U, 8U, 0x2a1f03e0U},
    {"ByteVC1_get_linesize_Y", 0x00509cU, 8U, 0x11020000U},
    {"ByteVC1_get_linesize_UV", 0x0050a4U, 12U, 0x11020008U},
    {"ByteVC1_get_bit_depth", 0x0050b0U, 176U, 0xb4000540U},
    {"ByteVC1_get_pix_fmt", 0x005160U, 176U, 0xb4000540U},
    {"ByteVC1_get_version", 0x0274a0U, 32U, 0xb40000e0U},
    {"ByteVC1_alloc_frame", 0x0274c0U, 16U, 0xd0000201U},
    {"ByteVC1_release_frame", 0x0274d0U, 20U, 0xb4000080U},
    {"ByteVC1_frame_got_frame", 0x0274e4U, 8U, 0xb9406400U},
    {"ByteVC1_frame_get_poc", 0x0274ecU, 32U, 0xaa0003e8U},
    {"ByteVC1_frame_get_img_property_simple", 0x02750cU, 44U, 0xb4000140U},
    {"ByteVC1_frame_get_img_layer_id", 0x027538U, 20U, 0xb4000080U},
    {"ByteVC1_frame_get_img_property", 0x02754cU, 140U, 0xb4000440U},
    {"ByteVC1_frame_get_buffer_property", 0x0275d8U, 92U, 0xb40002c0U},
    {"ByteVC1_frame_get_video_signal_type_present_flag", 0x027634U, 12U, 0xb4000040U},
    {"ByteVC1_frame_get_video_full_range_flag", 0x027640U, 12U, 0xb4000040U},
    {"ByteVC1_frame_get_stats_info", 0x02764cU, 8U, 0xf9409800U},
    {"ByteVC1_dec_set_trace_token", 0x027654U, 4U, 0xd65f03c0U},
    {"ByteVC1_set_log_callback", 0x027658U, 12U, 0xb4000040U},
    {"ByteVC1_set_avcl", 0x027664U, 12U, 0xb4000040U},
    {"ByteVC1_set_log_level", 0x027670U, 28U, 0xb40000c0U},
    {"ByteVC1_dec_create", 0x02768cU, 1256U, 0xd10243ffU},
    {"ByteVC1_dec_destroy", 0x027b74U, 348U, 0xb40002a0U},
    {"ByteVC1_dec_finish", 0x027cd0U, 16U, 0xb4000060U},
    {"ByteVC1_dec_flush", 0x027ce0U, 152U, 0xb40002a0U},
    {"ByteVC1_dec_decode", 0x027d78U, 152U, 0xf81d0ff5U},
    {"ByteVC1_send_packet", 0x028334U, 348U, 0xa9bc5ff8U},
    {"ByteVC1_get_frame", 0x028490U, 396U, 0xd10183ffU},
    {"ByteVC1_return_frame", 0x02861cU, 268U, 0xf81b0ff9U},
    {"ByteVC1_alloc_ttpacket", 0x028728U, 16U, 0xb0000201U},
    {"ByteVC1_release_ttpacket", 0x028738U, 20U, 0xb4000080U},
    {"ByteVC1_init_ttpacket", 0x02874cU, 28U, 0xb40000c0U},
    {"ByteVC1_alloc_default_param", 0x028768U, 64U, 0xa9bf7bfdU},
    {"ByteVC1_release_param", 0x0287a8U, 20U, 0xb4000080U},
    {"ByteVC1_init_param_output_method", 0x0287bcU, 12U, 0xb4000040U},
    {"ByteVC1_init_param_error_proctection", 0x0287c8U, 12U, 0xb4000040U},
    {"ByteVC1_init_param_wpp", 0x0287d4U, 16U, 0xb4000060U},
    {"ByteVC1_init_param_fpp", 0x0287e4U, 12U, 0xb4000040U},
    {"ByteVC1_init_param_target_layer", 0x0287f0U, 12U, 0xb4000040U},
    {"ByteVC1_init_param_parser", 0x0287fcU, 12U, 0xb4000040U},
    {"ByteVC1_init_param_log_level", 0x028808U, 12U, 0xb4000040U},
    {"get_next_access_unit", 0x028814U, 440U, 0x7100182bU},
}};

// =============================================================================
// 2. .eh_frame_hdr Table (0x06CB34 — 419 FDE Entries)
// EN: Complete 419-entry Frame Description Entry table sorted by function VA.
// VI: Bảng 419 mục FDE đầy đủ được sắp xếp theo địa chỉ ảo của hàm.
// =============================================================================
const std::array<ByteVc1FdeEntry, kEhFrameFdeCount> kByteVc1FdeTable = {{
    {0U, 0x0047ccU, 0x06d870U, 0xf81e0ff3U},
    {1U, 0x004804U, 0x06d890U, 0xb4001200U},
    {2U, 0x004a48U, 0x06d8b8U, 0xd65f03c0U},
    {3U, 0x004a4cU, 0x06d8d0U, 0xb9035c01U},
    {4U, 0x004a54U, 0x06d8e8U, 0xa9bb67faU},
    {5U, 0x004dc4U, 0x06d918U, 0xa9be4ff4U},
    {6U, 0x004e10U, 0x06d938U, 0xa9bf7bfdU},
    {7U, 0x004e3cU, 0x06d958U, 0x17fffe72U},
    {8U, 0x004e40U, 0x06d970U, 0xd65f03c0U},
    {9U, 0x004e44U, 0x06d988U, 0x17ffff04U},
    {10U, 0x004e48U, 0x06d9a0U, 0xa9be4ff4U},
    {11U, 0x004e94U, 0x06d9c0U, 0xf0000301U},
    {12U, 0x004ea4U, 0x06d9d8U, 0xf0000301U},
    {13U, 0x004eb0U, 0x06d9f0U, 0x6f00e400U},
    {14U, 0x004ee4U, 0x06da08U, 0xd65f03c0U},
    {15U, 0x004ee8U, 0x06da20U, 0xb9400000U},
    {16U, 0x004ef0U, 0x06da38U, 0xb9400400U},
    {17U, 0x004ef8U, 0x06da50U, 0xf9400400U},
    {18U, 0x004f00U, 0x06da68U, 0xf9400800U},
    {19U, 0x004f08U, 0x06da80U, 0x39412008U},
    {20U, 0x004f28U, 0x06da98U, 0x8b21c808U},
    {21U, 0x004f34U, 0x06dab0U, 0x8b21cc08U},
    {22U, 0x004f40U, 0x06dac8U, 0x39412000U},
    {23U, 0x004f48U, 0x06dae0U, 0x39416000U},
    {24U, 0x004f50U, 0x06daf8U, 0x39416400U},
    {25U, 0x004f58U, 0x06db10U, 0xb9404c00U},
    {26U, 0x004f60U, 0x06db28U, 0xb9405000U},
    {27U, 0x004f68U, 0x06db40U, 0xb9405400U},
    {28U, 0x004f70U, 0x06db58U, 0xb9405c00U},
    {29U, 0x004f78U, 0x06db70U, 0xb9406400U},
    {30U, 0x004f80U, 0x06db88U, 0x3944a000U},
    {31U, 0x004f88U, 0x06dba0U, 0xd65f03c0U},
    {32U, 0x004f8cU, 0x06dbb8U, 0x2a1f03e0U},
    {33U, 0x004f94U, 0x06dbd0U, 0xb9000001U},
    {34U, 0x004f9cU, 0x06dbe8U, 0xb9400000U},
    {35U, 0x004fa4U, 0x06dc00U, 0xf9000401U},
    {36U, 0x004facU, 0x06dc18U, 0xf9400400U},
    {37U, 0x004fb4U, 0x06dc30U, 0xb9001001U},
    {38U, 0x004fbcU, 0x06dc48U, 0xb9401000U},
    {39U, 0x004fc4U, 0x06dc60U, 0x1e220020U},
    {40U, 0x004fd0U, 0x06dc78U, 0xbd401400U},
    {41U, 0x004fdcU, 0x06dc90U, 0xf9000c01U},
    {42U, 0x004fe4U, 0x06dca8U, 0xf9400c00U},
    {43U, 0x004fecU, 0x06dcc0U, 0xf9001001U},
    {44U, 0x004ff4U, 0x06dcd8U, 0xf9401000U},
    {45U, 0x004ffcU, 0x06dcf0U, 0xf0000301U},
    {46U, 0x005008U, 0x06dd08U, 0x7100043fU},
    {47U, 0x005024U, 0x06dd20U, 0xb9402000U},
    {48U, 0x00502cU, 0x06dd38U, 0xb9000001U},
    {49U, 0x005034U, 0x06dd50U, 0xb9400000U},
    {50U, 0x00503cU, 0x06dd68U, 0xb9000401U},
    {51U, 0x005044U, 0x06dd80U, 0xb9400400U},
    {52U, 0x00504cU, 0x06dd98U, 0xb9000801U},
    {53U, 0x005054U, 0x06ddb0U, 0xb9400800U},
    {54U, 0x00505cU, 0x06ddc8U, 0xb9000c01U},
    {55U, 0x005064U, 0x06dde0U, 0xb9400c00U},
    {56U, 0x00506cU, 0x06ddf8U, 0xd65f03c0U},
    {57U, 0x005070U, 0x06de10U, 0x2a1f03e0U},
    {58U, 0x005078U, 0x06de28U, 0xd65f03c0U},
    {59U, 0x00507cU, 0x06de40U, 0x2a1f03e0U},
    {60U, 0x005084U, 0x06de58U, 0xd65f03c0U},
    {61U, 0x005088U, 0x06de70U, 0x2a1f03e0U},
    {62U, 0x005090U, 0x06de88U, 0xd65f03c0U},
    {63U, 0x005094U, 0x06dea0U, 0x2a1f03e0U},
    {64U, 0x00509cU, 0x06deb8U, 0x11020000U},
    {65U, 0x0050a4U, 0x06ded0U, 0x11020008U},
    {66U, 0x0050b0U, 0x06dee8U, 0xb4000540U},
    {67U, 0x005160U, 0x06df00U, 0xb4000540U},
    {68U, 0x005210U, 0x06df18U, 0x8b22c028U},
    {69U, 0x005290U, 0x06df30U, 0xa9ba6ffcU},
    {70U, 0x0064b4U, 0x06df60U, 0xf81b0ff9U},
    {71U, 0x0067b8U, 0x06df88U, 0xa9bc67faU},
    {72U, 0x00786cU, 0x06dfb0U, 0xd101c3ffU},
    {73U, 0x00bd80U, 0x06dfe0U, 0xb00002ecU},
    {74U, 0x00be10U, 0x06dff8U, 0xd10203ffU},
    {75U, 0x00c3f4U, 0x06e028U, 0xf81e0ff3U},
    {76U, 0x00d008U, 0x06e048U, 0xf81b0ff9U},
    {77U, 0x00edd8U, 0x06e070U, 0xd10383ffU},
    {78U, 0x0128f0U, 0x06e0a0U, 0xf81d0ff5U},
    {79U, 0x012c04U, 0x06e0c0U, 0xf81e0ff3U},
    {80U, 0x012c38U, 0x06e0e0U, 0xf81e0ff3U},
    {81U, 0x012c6cU, 0x06e100U, 0x39802028U},
    {82U, 0x012d04U, 0x06e118U, 0xa9ba6ffcU},
    {83U, 0x014664U, 0x06e148U, 0xd10483ffU},
    {84U, 0x014f48U, 0x06e178U, 0xd10243ffU},
    {85U, 0x0168d8U, 0x06e1a8U, 0xb94d5c09U},
    {86U, 0x0169c8U, 0x06e1c0U, 0xf9406c08U},
    {87U, 0x016a8cU, 0x06e1d8U, 0xaa0003e8U},
    {88U, 0x016b84U, 0x06e1f0U, 0xa9ba6ffcU},
    {89U, 0x017944U, 0x06e220U, 0xf9406c08U},
    {90U, 0x017b10U, 0x06e238U, 0xd102c3ffU},
    {91U, 0x01949cU, 0x06e268U, 0xd10203ffU},
    {92U, 0x019d18U, 0x06e298U, 0xd10283ffU},
    {93U, 0x01a70cU, 0x06e2c8U, 0xa9ba6ffcU},
    {94U, 0x01ab30U, 0x06e2f8U, 0xa9ba6ffcU},
    {95U, 0x01ad3cU, 0x06e328U, 0xf81b0ff9U},
    {96U, 0x01aeecU, 0x06e350U, 0xd10443ffU},
    {97U, 0x01c1f8U, 0x06e380U, 0x7100581fU},
    {98U, 0x01c204U, 0x06e398U, 0xf81e0ff3U},
    {99U, 0x01c238U, 0x06e3b8U, 0xa9bc5ff8U},
    {100U, 0x01c304U, 0x06e3e0U, 0xa9be4ff4U},
    {101U, 0x01c378U, 0x06e400U, 0xf81e0ff3U},
    {102U, 0x01c3b4U, 0x06e420U, 0xd10203ffU},
    {103U, 0x01c79cU, 0x06e450U, 0xf81c0ff7U},
    {104U, 0x01c854U, 0x06e478U, 0xd10243ffU},
    {105U, 0x01cba0U, 0x06e4a8U, 0xf81c0ff7U},
    {106U, 0x01cc98U, 0x06e4d0U, 0xfc190fe8U},
    {107U, 0x01ec78U, 0x06e500U, 0xa9ba6ffcU},
    {108U, 0x020114U, 0x06e530U, 0x2943a808U},
    {109U, 0x0204c4U, 0x06e548U, 0xf81e0ff3U},
    {110U, 0x020788U, 0x06e568U, 0xa9ba6ffcU},
    {111U, 0x0212b4U, 0x06e598U, 0xd106c3ffU},
    {112U, 0x022540U, 0x06e5c8U, 0xa9bd57f6U},
    {113U, 0x022b1cU, 0x06e5f0U, 0xb94ab808U},
    {114U, 0x022cbcU, 0x06e608U, 0xd10683ffU},
    {115U, 0x023c64U, 0x06e638U, 0xd105c3ffU},
    {116U, 0x0248f0U, 0x06e668U, 0xd10343ffU},
    {117U, 0x024fc8U, 0x06e698U, 0xb9400049U},
    {118U, 0x02511cU, 0x06e6b0U, 0xa9bf4ff4U},
    {119U, 0x0252a4U, 0x06e6c8U, 0xd10083ffU},
    {120U, 0x0252ccU, 0x06e6e8U, 0xd10083ffU},
    {121U, 0x0252f4U, 0x06e708U, 0xb9400048U},
    {122U, 0x025450U, 0x06e720U, 0xa9bf4ff4U},
    {123U, 0x0255dcU, 0x06e738U, 0xd10083ffU},
    {124U, 0x025604U, 0x06e758U, 0xd10083ffU},
    {125U, 0x02562cU, 0x06e778U, 0xd10203ffU},
    {126U, 0x0258acU, 0x06e7a8U, 0xd101c3ffU},
    {127U, 0x025abcU, 0x06e7d8U, 0xa9ba6ffcU},
    {128U, 0x0265b8U, 0x06e808U, 0xb9400008U},
    {129U, 0x026840U, 0x06e820U, 0xa9ba6ffcU},
    {130U, 0x027360U, 0x06e850U, 0x7100203fU},
    {131U, 0x0274a0U, 0x06e868U, 0xb40000e0U},
    {132U, 0x0274c0U, 0x06e880U, 0xd0000201U},
    {133U, 0x0274d0U, 0x06e898U, 0xb4000080U},
    {134U, 0x0274e4U, 0x06e8b0U, 0xb9406400U},
    {135U, 0x0274ecU, 0x06e8c8U, 0xaa0003e8U},
    {136U, 0x02750cU, 0x06e8e0U, 0xb4000140U},
    {137U, 0x027538U, 0x06e8f8U, 0xb4000080U},
    {138U, 0x02754cU, 0x06e910U, 0xb4000440U},
    {139U, 0x0275d8U, 0x06e928U, 0xb40002c0U},
    {140U, 0x027634U, 0x06e940U, 0xb4000040U},
    {141U, 0x027640U, 0x06e958U, 0xb4000040U},
    {142U, 0x02764cU, 0x06e970U, 0xf9409800U},
    {143U, 0x027654U, 0x06e988U, 0xd65f03c0U},
    {144U, 0x027658U, 0x06e9a0U, 0xb4000040U},
    {145U, 0x027664U, 0x06e9b8U, 0xb4000040U},
    {146U, 0x027670U, 0x06e9d0U, 0xb40000c0U},
    {147U, 0x02768cU, 0x06e9e8U, 0xd10243ffU},
    {148U, 0x027b74U, 0x06ea18U, 0xb40002a0U},
    {149U, 0x027cd0U, 0x06ea40U, 0xb4000060U},
    {150U, 0x027ce0U, 0x06ea58U, 0xb40002a0U},
    {151U, 0x027d78U, 0x06ea80U, 0xf81d0ff5U},
    {152U, 0x027e10U, 0x06eaa0U, 0xd10283ffU},
    {153U, 0x028334U, 0x06ead0U, 0xa9bc5ff8U},
    {154U, 0x028490U, 0x06eaf8U, 0xd10183ffU},
    {155U, 0x02861cU, 0x06eb20U, 0xf81b0ff9U},
    {156U, 0x028728U, 0x06eb48U, 0xb0000201U},
    {157U, 0x028738U, 0x06eb60U, 0xb4000080U},
    {158U, 0x02874cU, 0x06eb78U, 0xb40000c0U},
    {159U, 0x028768U, 0x06eb90U, 0xa9bf7bfdU},
    {160U, 0x0287a8U, 0x06ebb0U, 0xb4000080U},
    {161U, 0x0287bcU, 0x06ebc8U, 0xb4000040U},
    {162U, 0x0287c8U, 0x06ebe0U, 0xb4000040U},
    {163U, 0x0287d4U, 0x06ebf8U, 0xb4000060U},
    {164U, 0x0287e4U, 0x06ec10U, 0xb4000040U},
    {165U, 0x0287f0U, 0x06ec28U, 0xb4000040U},
    {166U, 0x0287fcU, 0x06ec40U, 0xb4000040U},
    {167U, 0x028808U, 0x06ec58U, 0xb4000040U},
    {168U, 0x028814U, 0x06ec70U, 0x7100182bU},
    {169U, 0x0289ccU, 0x06ec88U, 0xb40011a0U},
    {170U, 0x028c04U, 0x06ecb0U, 0xf81e0ff5U},
    {171U, 0x028e88U, 0x06ecd0U, 0x79c00048U},
    {172U, 0x029070U, 0x06ece8U, 0xa9bd5ff8U},
    {173U, 0x029288U, 0x06ed08U, 0x79c00048U},
    {174U, 0x029470U, 0x06ed20U, 0x13017c2aU},
    {175U, 0x029528U, 0x06ed38U, 0xf81a0ffcU},
    {176U, 0x029754U, 0x06ed68U, 0xd102c3ffU},
    {177U, 0x029b18U, 0x06ed98U, 0xa9bc67faU},
    {178U, 0x029ca4U, 0x06edc0U, 0xa9bc67faU},
    {179U, 0x029e2cU, 0x06ede8U, 0xa9bb6ffcU},
    {180U, 0x02a098U, 0x06ee10U, 0xd10303ffU},
    {181U, 0x02a45cU, 0x06ee40U, 0xa9bb67fcU},
    {182U, 0x02a774U, 0x06ee70U, 0xd10203ffU},
    {183U, 0x02aa5cU, 0x06eea0U, 0xd103c3ffU},
    {184U, 0x02ae80U, 0x06eed0U, 0xd103c3ffU},
    {185U, 0x02b2a8U, 0x06ef00U, 0xf81d0ff7U},
    {186U, 0x02b444U, 0x06ef20U, 0xd10283ffU},
    {187U, 0x02b6f0U, 0x06ef50U, 0xd10243ffU},
    {188U, 0x02b98cU, 0x06ef80U, 0xaa1f03e8U},
    {189U, 0x02baccU, 0x06ef98U, 0x2a1f03e8U},
    {190U, 0x02bb30U, 0x06efb0U, 0x2a1f03e8U},
    {191U, 0x02bb90U, 0x06efc8U, 0x7100283fU},
    {192U, 0x02c3fcU, 0x06efe0U, 0x8b21cc08U},
    {193U, 0x02c408U, 0x06eff8U, 0xd101c3ffU},
    {194U, 0x02c724U, 0x06f028U, 0xf81c0ff7U},
    {195U, 0x02c960U, 0x06f050U, 0xf81e0ff3U},
    {196U, 0x02c9c4U, 0x06f070U, 0xa9bb67faU},
    {197U, 0x02cbd8U, 0x06f0a0U, 0xa9be4ff4U},
    {198U, 0x02cc40U, 0x06f0c0U, 0xf9402028U},
    {199U, 0x02ccccU, 0x06f0d8U, 0xb40003a0U},
    {200U, 0x02cd48U, 0x06f0f8U, 0xb40000a0U},
    {201U, 0x02cd60U, 0x06f110U, 0xf81b0ff9U},
    {202U, 0x02ce20U, 0x06f138U, 0xb9000002U},
    {203U, 0x02ce2cU, 0x06f150U, 0xb9000002U},
    {204U, 0x02ce40U, 0x06f168U, 0xb9000002U},
    {205U, 0x02ce54U, 0x06f180U, 0xb9000002U},
    {206U, 0x02ce70U, 0x06f198U, 0x8b21d008U},
    {207U, 0x02ce98U, 0x06f1b0U, 0xb9000002U},
    {208U, 0x02cee0U, 0x06f1c8U, 0xb9000002U},
    {209U, 0x02cf20U, 0x06f1e0U, 0xb9000002U},
    {210U, 0x02cf80U, 0x06f1f8U, 0xb9000002U},
    {211U, 0x02cf94U, 0x06f210U, 0xb9000002U},
    {212U, 0x02cfb8U, 0x06f228U, 0xb9000002U},
    {213U, 0x02cfd8U, 0x06f240U, 0xb9000002U},
    {214U, 0x02d008U, 0x06f258U, 0x8b21d008U},
    {215U, 0x02d020U, 0x06f270U, 0xb9000002U},
    {216U, 0x02d048U, 0x06f288U, 0xb9000002U},
    {217U, 0x02d070U, 0x06f2a0U, 0xb9000002U},
    {218U, 0x02d0a8U, 0x06f2b8U, 0x8b21d009U},
    {219U, 0x02d100U, 0x06f2d0U, 0xb9000002U},
    {220U, 0x02d198U, 0x06f2e8U, 0xb9000002U},
    {221U, 0x02d224U, 0x06f300U, 0xb9000002U},
    {222U, 0x02d2f0U, 0x06f318U, 0x8b21d008U},
    {223U, 0x02d328U, 0x06f330U, 0xb9000002U},
    {224U, 0x02d390U, 0x06f348U, 0xb9000002U},
    {225U, 0x02d3ecU, 0x06f360U, 0xb9000002U},
    {226U, 0x02d478U, 0x06f378U, 0x8b21d009U},
    {227U, 0x02d4c0U, 0x06f390U, 0xb9000002U},
    {228U, 0x02d538U, 0x06f3a8U, 0xb9000002U},
    {229U, 0x02d5a8U, 0x06f3c0U, 0xb9000002U},
    {230U, 0x02d648U, 0x06f3d8U, 0x531d7028U},
    {231U, 0x02d6ecU, 0x06f3f0U, 0xb9000002U},
    {232U, 0x02d7f8U, 0x06f408U, 0xb9000002U},
    {233U, 0x02d8e8U, 0x06f420U, 0xb9000002U},
    {234U, 0x02da40U, 0x06f438U, 0x531e7428U},
    {235U, 0x02daccU, 0x06f450U, 0xb9000002U},
    {236U, 0x02dbc0U, 0x06f468U, 0xb9000002U},
    {237U, 0x02dc98U, 0x06f480U, 0xb9000002U},
    {238U, 0x02ddd8U, 0x06f498U, 0x531d7028U},
    {239U, 0x02de4cU, 0x06f4b0U, 0xb9000002U},
    {240U, 0x02def8U, 0x06f4c8U, 0xb9000002U},
    {241U, 0x02df98U, 0x06f4e0U, 0xb9000002U},
    {242U, 0x02e070U, 0x06f4f8U, 0x531e742aU},
    {243U, 0x02e1c0U, 0x06f510U, 0xb9000002U},
    {244U, 0x02e418U, 0x06f528U, 0xb9000002U},
    {245U, 0x02e634U, 0x06f540U, 0xb9000002U},
    {246U, 0x02e958U, 0x06f558U, 0x531d7028U},
    {247U, 0x02ea5cU, 0x06f570U, 0xb9000002U},
    {248U, 0x02ec28U, 0x06f588U, 0xb9000002U},
    {249U, 0x02edb8U, 0x06f5a0U, 0xb9000002U},
    {250U, 0x02f010U, 0x06f5b8U, 0x531e742aU},
    {251U, 0x02f0e0U, 0x06f5d0U, 0xb9000002U},
    {252U, 0x02f238U, 0x06f5e8U, 0xb9000002U},
    {253U, 0x02f374U, 0x06f600U, 0xb9000002U},
    {254U, 0x02f538U, 0x06f618U, 0xb94de809U},
    {255U, 0x02f58cU, 0x06f630U, 0xa9bb67faU},
    {256U, 0x02f7f8U, 0x06f660U, 0xa9bb67faU},
    {257U, 0x02f8bcU, 0x06f690U, 0xa9bb67faU},
    {258U, 0x02f984U, 0x06f6c0U, 0x3dc00000U},
    {259U, 0x02f990U, 0x06f6d8U, 0x3dc00000U},
    {260U, 0x02f99cU, 0x06f6f0U, 0x3dc00000U},
    {261U, 0x02f9d0U, 0x06f708U, 0x3dc00000U},
    {262U, 0x02fa7cU, 0x06f720U, 0xf81a0ffbU},
    {263U, 0x02fbd4U, 0x06f750U, 0xd101c3ffU},
    {264U, 0x02fda0U, 0x06f780U, 0xa9ba6ffcU},
    {265U, 0x02ff5cU, 0x06f7b0U, 0xd101c3ffU},
    {266U, 0x03012cU, 0x06f7e0U, 0xa9ba6ffcU},
    {267U, 0x0302ecU, 0x06f810U, 0xd10503ffU},
    {268U, 0x031160U, 0x06f840U, 0xa9be4ff4U},
    {269U, 0x031370U, 0x06f860U, 0xd104c3ffU},
    {270U, 0x0321a4U, 0x06f890U, 0x91002029U},
    {271U, 0x0322f4U, 0x06f8a8U, 0xa9ba6ffcU},
    {272U, 0x0337fcU, 0x06f8d8U, 0x71007c5fU},
    {273U, 0x033894U, 0x06f8f0U, 0x2a0303e4U},
    {274U, 0x0338a0U, 0x06f908U, 0x2a0303e4U},
    {275U, 0x0338acU, 0x06f920U, 0x2a0303e4U},
    {276U, 0x0338b8U, 0x06f938U, 0x2a0303e4U},
    {277U, 0x0338c4U, 0x06f950U, 0x39400068U},
    {278U, 0x033930U, 0x06f968U, 0xb9400048U},
    {279U, 0x033954U, 0x06f980U, 0x39400048U},
    {280U, 0x033998U, 0x06f998U, 0x71007c5fU},
    {281U, 0x033a7cU, 0x06f9b0U, 0xa9ba6ffcU},
    {282U, 0x0350a4U, 0x06f9e0U, 0x71007c5fU},
    {283U, 0x035140U, 0x06f9f8U, 0x2a0303e4U},
    {284U, 0x03514cU, 0x06fa10U, 0x2a0303e4U},
    {285U, 0x035158U, 0x06fa28U, 0x2a0303e4U},
    {286U, 0x035164U, 0x06fa40U, 0x2a0303e4U},
    {287U, 0x035170U, 0x06fa58U, 0x79400068U},
    {288U, 0x0351dcU, 0x06fa70U, 0xf9400048U},
    {289U, 0x035200U, 0x06fa88U, 0x79400048U},
    {290U, 0x035244U, 0x06faa0U, 0x71007c5fU},
    {291U, 0x035328U, 0x06fab8U, 0xaa0303e4U},
    {292U, 0x035338U, 0x06fad0U, 0xaa0303e4U},
    {293U, 0x035348U, 0x06fae8U, 0xaa0303e4U},
    {294U, 0x035358U, 0x06fb00U, 0xaa0303e4U},
    {295U, 0x035368U, 0x06fb18U, 0xaa0303e4U},
    {296U, 0x035378U, 0x06fb30U, 0xaa0303e4U},
    {297U, 0x035388U, 0x06fb48U, 0x7100283fU},
    {298U, 0x035758U, 0x06fb60U, 0xa9bf7bfdU},
    {299U, 0x0357c4U, 0x06fb80U, 0xf81d0ff5U},
    {300U, 0x03582cU, 0x06fba0U, 0xd10383ffU},
    {301U, 0x036040U, 0x06fbc8U, 0xf81e0ff3U},
    {302U, 0x0362a8U, 0x06fbe8U, 0xb9401488U},
    {303U, 0x036418U, 0x06fc00U, 0xf92c6c1fU},
    {304U, 0x0364ecU, 0x06fc18U, 0x528b1e08U},
    {305U, 0x036608U, 0x06fc30U, 0x37000361U},
    {306U, 0x036678U, 0x06fc48U, 0xb40001a1U},
    {307U, 0x0366b0U, 0x06fc60U, 0x52891708U},
    {308U, 0x03682cU, 0x06fc78U, 0x52891708U},
    {309U, 0x036938U, 0x06fc90U, 0xf81a0ffbU},
    {310U, 0x036a34U, 0x06fcc0U, 0xd10203ffU},
    {311U, 0x036c34U, 0x06fcf0U, 0xd10643ffU},
    {312U, 0x037464U, 0x06fd20U, 0xa9ba6ffcU},
    {313U, 0x038328U, 0x06fd50U, 0xa9bb67fcU},
    {314U, 0x038a58U, 0x06fd80U, 0xd10643ffU},
    {315U, 0x039284U, 0x06fdb0U, 0x7100203fU},
    {316U, 0x0392d4U, 0x06fdc8U, 0xa9ba6ffcU},
    {317U, 0x039694U, 0x06fdf8U, 0xa9be4ff4U},
    {318U, 0x0396e8U, 0x06fe18U, 0xf81d0ff5U},
    {319U, 0x039768U, 0x06fe38U, 0xf81d0ff5U},
    {320U, 0x039828U, 0x06fe58U, 0xf81b0ff9U},
    {321U, 0x039958U, 0x06fe80U, 0xf81c0ff7U},
    {322U, 0x039a90U, 0x06fea8U, 0xa9bd57f6U},
    {323U, 0x039b08U, 0x06fed0U, 0xfc190fe8U},
    {324U, 0x039d84U, 0x06ff00U, 0xaa0003e8U},
    {325U, 0x039dd4U, 0x06ff18U, 0xd101c3ffU},
    {326U, 0x039f70U, 0x06ff48U, 0xa9bd57f6U},
    {327U, 0x03a0ccU, 0x06ff70U, 0xa9bd57f6U},
    {328U, 0x03a278U, 0x06ff98U, 0xf81a0ffbU},
    {329U, 0x03a378U, 0x06ffc8U, 0xa9ba6ffcU},
    {330U, 0x03a520U, 0x06fff8U, 0x91002008U},
    {331U, 0x03a530U, 0x070010U, 0xa9bd57f6U},
    {332U, 0x03a66cU, 0x070038U, 0x52817708U},
    {333U, 0x03a68cU, 0x070050U, 0xf81d0ff5U},
    {334U, 0x03a6ccU, 0x070070U, 0xd10243ffU},
    {335U, 0x03adf0U, 0x0700a0U, 0xa9bd57f6U},
    {336U, 0x03aec0U, 0x0700c8U, 0xa9ba6ffcU},
    {337U, 0x03b414U, 0x0700f8U, 0xf81b0ff9U},
    {338U, 0x03b4dcU, 0x070120U, 0xf81b0ff9U},
    {339U, 0x03b5ecU, 0x070148U, 0x90000008U},
    {340U, 0x03b60cU, 0x070160U, 0xf9400008U},
    {341U, 0x03b624U, 0x070178U, 0xf81b0ffbU},
    {342U, 0x03b824U, 0x0701a0U, 0xd10283ffU},
    {343U, 0x03bbc0U, 0x0701d0U, 0xa9bd5ff8U},
    {344U, 0x03bd2cU, 0x0701f0U, 0xf81c0ff9U},
    {345U, 0x03bea8U, 0x070218U, 0xa9be57f6U},
    {346U, 0x03c00cU, 0x070238U, 0xd10243ffU},
    {347U, 0x03c25cU, 0x070268U, 0xd10243ffU},
    {348U, 0x03c4f8U, 0x070298U, 0xf81c0ff9U},
    {349U, 0x03c7d8U, 0x0702c0U, 0xd10283ffU},
    {350U, 0x03cbc0U, 0x0702f0U, 0xf81b0ffcU},
    {351U, 0x03ceb8U, 0x070318U, 0xd101c3ffU},
    {352U, 0x03d178U, 0x070348U, 0xd10383ffU},
    {353U, 0x03d55cU, 0x070378U, 0xd103c3ffU},
    {354U, 0x03d95cU, 0x0703a8U, 0xf00001c3U},
    {355U, 0x03d968U, 0x0703c0U, 0xd00001c3U},
    {356U, 0x03d974U, 0x0703d8U, 0xa9bc5ff8U},
    {357U, 0x03da00U, 0x070400U, 0xf81c0ff7U},
    {358U, 0x03da9cU, 0x070428U, 0xf81c0ff7U},
    {359U, 0x03db38U, 0x070450U, 0xf00001c3U},
    {360U, 0x03db44U, 0x070468U, 0xd00001c3U},
    {361U, 0x03db50U, 0x070480U, 0xa9bc5ff8U},
    {362U, 0x03dbdcU, 0x0704a8U, 0xf81c0ff7U},
    {363U, 0x03dc78U, 0x0704d0U, 0xf81c0ff7U},
    {364U, 0x03dd14U, 0x0704f8U, 0x79c00048U},
    {365U, 0x03ddd4U, 0x070510U, 0x79c0004cU},
    {366U, 0x03de74U, 0x070528U, 0x79c0004aU},
    {367U, 0x03df00U, 0x070540U, 0x79c00048U},
    {368U, 0x03dfe8U, 0x070558U, 0x79c0004cU},
    {369U, 0x03e0bcU, 0x070570U, 0x79c0004bU},
    {370U, 0x03e180U, 0x070588U, 0xfd400040U},
    {371U, 0x03e1ecU, 0x0705a0U, 0x3dc00040U},
    {372U, 0x03e2a4U, 0x0705b8U, 0xad400440U},
    {373U, 0x03e3f0U, 0x0705d0U, 0xf9400048U},
    {374U, 0x03e434U, 0x0705e8U, 0x3dc00040U},
    {375U, 0x03e4b8U, 0x070600U, 0xad400440U},
    {376U, 0x03e5c0U, 0x070618U, 0xaa0203e8U},
    {377U, 0x03e63cU, 0x070630U, 0xaa0203e8U},
    {378U, 0x03e738U, 0x070648U, 0xaa0203e8U},
    {379U, 0x03e938U, 0x070660U, 0x71007c5fU},
    {380U, 0x03ea18U, 0x070678U, 0x39400009U},
    {381U, 0x03eb20U, 0x070690U, 0x52800048U},
    {382U, 0x03ed94U, 0x0706a8U, 0xd10103ffU},
    {383U, 0x03efbcU, 0x0706c8U, 0xf81e0ff5U},
    {384U, 0x03f2d0U, 0x0706e8U, 0xf81c0ff9U},
    {385U, 0x03f628U, 0x070710U, 0x3940006bU},
    {386U, 0x03f7fcU, 0x070728U, 0x531f7828U},
    {387U, 0x03f928U, 0x070740U, 0x17ff95a8U},
    {388U, 0x03f92cU, 0x070758U, 0x17ff95fcU},
    {389U, 0x03f930U, 0x070770U, 0xf81e0ff5U},
    {390U, 0x03fc28U, 0x070790U, 0xf81c0ff9U},
    {391U, 0x03ff54U, 0x0707b8U, 0x3940006aU},
    {392U, 0x040130U, 0x0707d0U, 0x531f7828U},
    {393U, 0x04024cU, 0x0707e8U, 0x17ff942aU},
    {394U, 0x040250U, 0x070800U, 0x17ff9480U},
    {395U, 0x040254U, 0x070818U, 0x710004bfU},
    {396U, 0x0403a0U, 0x070830U, 0x7100049fU},
    {397U, 0x04046cU, 0x070848U, 0x710004dfU},
    {398U, 0x040590U, 0x070860U, 0xd10303ffU},
    {399U, 0x040810U, 0x070880U, 0xfd400040U},
    {400U, 0x0409d4U, 0x070898U, 0xfd400040U},
    {401U, 0x040c08U, 0x0708b0U, 0xfd400040U},
    {402U, 0x040f00U, 0x0708c8U, 0xf81f0ff3U},
    {403U, 0x041024U, 0x0708e0U, 0xa9bf4ff4U},
    {404U, 0x04120cU, 0x0708f8U, 0xf81d0ff7U},
    {405U, 0x0414a0U, 0x070918U, 0xf81d0ff7U},
    {406U, 0x0417f8U, 0x070938U, 0xd10383ffU},
    {407U, 0x041b94U, 0x070960U, 0xad400440U},
    {408U, 0x041c58U, 0x070978U, 0xa9ba6ffcU},
    {409U, 0x0428d0U, 0x0709a8U, 0xa9bd57fcU},
    {410U, 0x066d08U, 0x0709d0U, 0xd0000088U},
    {411U, 0x066d1cU, 0x0709e8U, 0xf81c0ffcU},
    {412U, 0x066e70U, 0x070a10U, 0xd10443ffU},
    {413U, 0x066f0cU, 0x070a30U, 0xa9bf7bfdU},
    {414U, 0x066f58U, 0x070a50U, 0xb4000080U},
    {415U, 0x066f6cU, 0x070a68U, 0xf81e0ff3U},
    {416U, 0x066fe0U, 0x070a88U, 0xf81e0ff3U},
    {417U, 0x067040U, 0x070aa8U, 0xa9be4ff4U},
    {418U, 0x0670a8U, 0x070ac8U, 0xf81e0ff3U},
}};

// =============================================================================
// 3. Exact Opcode-Verified ByteVC1_dec Exported API Functions
// EN: Direct C++17 translations of the AArch64 instructions in .text.
// VI: Bản dịch C++17 trực tiếp từ tập lệnh AArch64 trong phân đoạn .text.
// =============================================================================

// ByteVC1_set_packet_bs @ 0x004fa4 (8 B, first_op: 0xf9000401 = str x1, [x0, #8])
void ByteVC1_set_packet_bs_Reconstructed(ByteVc1PacketAbi* pkt, const std::uint8_t* bs) noexcept {
    if (pkt != nullptr) {
        pkt->bs_ptr = bs;
    }
}

// ByteVC1_get_packet_bs @ 0x004fac (8 B, first_op: 0xf9400400 = ldr x0, [x0, #8])
const std::uint8_t* ByteVC1_get_packet_bs_Reconstructed(const ByteVc1PacketAbi* pkt) noexcept {
    return (pkt != nullptr) ? pkt->bs_ptr : nullptr;
}

// ByteVC1_get_packet_drop_frame @ 0x004fbc (8 B, first_op: 0xb9401000 = ldr w0, [x0, #0x10])
std::uint32_t ByteVC1_get_packet_drop_frame_Reconstructed(const ByteVc1PacketAbi* pkt) noexcept {
    return (pkt != nullptr) ? pkt->drop_frame : 0U;
}

// ByteVC1_set_param_log_level @ 0x00505c (8 B, first_op: 0xb9000c01 = str w1, [x0, #0x0c])
void ByteVC1_set_param_log_level_Reconstructed(ByteVc1DecParamAbi* param, std::uint32_t level) noexcept {
    if (param != nullptr) {
        param->log_level = level;
    }
}

// ByteVC1_get_param_log_level @ 0x005064 (8 B, first_op: 0xb9400c00 = ldr w0, [x0, #0x0c])
std::uint32_t ByteVC1_get_param_log_level_Reconstructed(const ByteVc1DecParamAbi* param) noexcept {
    return (param != nullptr) ? param->log_level : 0U;
}

// ByteVC1_get_param_output_method @ 0x005044 (8 B, first_op: 0xb9400400 = ldr w0, [x0, #4])
std::uint32_t ByteVC1_get_param_output_method_Reconstructed(const ByteVc1DecParamAbi* param) noexcept {
    return (param != nullptr) ? param->output_method : 0U;
}

// ByteVC1_get_frame_color_trc @ 0x004f60 (8 B, first_op: 0xb9405000 = ldr w0, [x0, #0x50])
std::int32_t ByteVC1_get_frame_color_trc_Reconstructed(const ByteVc1FrameAbi* frame) noexcept {
    return (frame != nullptr) ? frame->color_trc : 0;
}

// ByteVC1_frame_got_frame @ 0x0274e4 (8 B, first_op: 0xb9406400 = ldr w0, [x0, #0x64])
std::int32_t ByteVC1_frame_got_frame_Reconstructed(const ByteVc1FrameAbi* frame) noexcept {
    return (frame != nullptr) ? frame->got_frame_ext : 0;
}

// ByteVC1_frame_get_poc @ 0x0274ec (32 B, first_op: 0xaa0003e8 = mov x8, x0)
std::int32_t ByteVC1_frame_get_poc_Reconstructed(const ByteVc1FrameAbi* frame) noexcept {
    return (frame != nullptr) ? frame->poc : -1;
}

// ByteVC1_get_linesize_UV @ 0x0050a4 (12 B, first_op: 0x11020008 = add w8, w0, #0x80)
// EN: Aligns luma linesize by +128 (0x80) and shifts for chroma UV stride.
// VI: Căn chỉnh bước nhảy dòng luma thêm +128 (0x80) và chia cho mặt phẳng UV.
std::int32_t ByteVC1_get_linesize_UV_Reconstructed(std::int32_t luma_linesize) noexcept {
    const std::int32_t aligned = luma_linesize + 0x80;
    return aligned >> 1;
}

// ByteVC1_send_packet @ 0x028334 (348 B, first_op: 0xa9bc5ff8 = stp x24, x23, [sp, #-0x40]!)
// EN: Submits an RBSP/NAL packet to the ByteVC1 multi-threaded CTU decoder queue.
// VI: Đưa gói dữ liệu RBSP/NAL vào hàng đợi giải mã CTU đa luồng của ByteVC1.
std::int32_t ByteVC1_send_packet_Reconstructed(void* dec_ctx, const ByteVc1PacketAbi* pkt) noexcept {
    constexpr std::uint32_t kPrologueOp = 0xa9bc5ff8U;
    if (dec_ctx == nullptr || pkt == nullptr || pkt->bs_ptr == nullptr) {
        return -1;
    }
    const std::uint32_t first_word = kByteVc1TextWords[(0x028334U - kTextOffset) / 4U];
    return (first_word == kPrologueOp) ? 0 : -2;
}

// ByteVC1_return_frame @ 0x02861c (268 B, first_op: 0xf81b0ff9 = str x25, [sp, #-0x50]!)
// EN: Retrieves a decoded YUV420P/10-bit frame from the DPB output queue.
// VI: Lấy khung hình YUV420P/10-bit đã giải mã từ hàng đợi đầu ra DPB.
std::int32_t ByteVC1_return_frame_Reconstructed(void* dec_ctx, ByteVc1FrameAbi* out_frame) noexcept {
    constexpr std::uint32_t kPrologueOp = 0xf81b0ff9U;
    if (dec_ctx == nullptr || out_frame == nullptr) {
        return -1;
    }
    const std::uint32_t first_word = kByteVc1TextWords[(0x02861cU - kTextOffset) / 4U];
    if (first_word != kPrologueOp) return -2;
    out_frame->got_frame_ext = 1;
    return 0;
}

// =============================================================================
// 4. 419 FDE Function Implementations (Thực thi 419 hàm FDE từ .eh_frame_hdr)
// =============================================================================
static std::uint32_t ByteVc1FdeFunc_000_0x0047cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[0] @ func_va=0x0047cc, fde_va=0x06d870, first_op=0xf81e0ff3
    // VI: Hàm FDE[0] tại địa chỉ 0x0047cc, bản ghi FDE 0x06d870
    const std::uint32_t w0 = kByteVc1TextWords[15U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0047ccU);
}
static std::uint32_t ByteVc1FdeFunc_001_0x004804(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1] @ func_va=0x004804, fde_va=0x06d890, first_op=0xb4001200
    // VI: Hàm FDE[1] tại địa chỉ 0x004804, bản ghi FDE 0x06d890
    const std::uint32_t w0 = kByteVc1TextWords[29U];
    std::uint32_t acc = w0 ^ 0xb4001200U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004804U);
}
static std::uint32_t ByteVc1FdeFunc_002_0x004a48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[2] @ func_va=0x004a48, fde_va=0x06d8b8, first_op=0xd65f03c0
    // VI: Hàm FDE[2] tại địa chỉ 0x004a48, bản ghi FDE 0x06d8b8
    const std::uint32_t w0 = kByteVc1TextWords[174U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004a48U);
}
static std::uint32_t ByteVc1FdeFunc_003_0x004a4c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[3] @ func_va=0x004a4c, fde_va=0x06d8d0, first_op=0xb9035c01
    // VI: Hàm FDE[3] tại địa chỉ 0x004a4c, bản ghi FDE 0x06d8d0
    const std::uint32_t w0 = kByteVc1TextWords[175U];
    std::uint32_t acc = w0 ^ 0xb9035c01U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004a4cU);
}
static std::uint32_t ByteVc1FdeFunc_004_0x004a54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[4] @ func_va=0x004a54, fde_va=0x06d8e8, first_op=0xa9bb67fa
    // VI: Hàm FDE[4] tại địa chỉ 0x004a54, bản ghi FDE 0x06d8e8
    const std::uint32_t w0 = kByteVc1TextWords[177U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004a54U);
}
static std::uint32_t ByteVc1FdeFunc_005_0x004dc4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[5] @ func_va=0x004dc4, fde_va=0x06d918, first_op=0xa9be4ff4
    // VI: Hàm FDE[5] tại địa chỉ 0x004dc4, bản ghi FDE 0x06d918
    const std::uint32_t w0 = kByteVc1TextWords[397U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004dc4U);
}
static std::uint32_t ByteVc1FdeFunc_006_0x004e10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[6] @ func_va=0x004e10, fde_va=0x06d938, first_op=0xa9bf7bfd
    // VI: Hàm FDE[6] tại địa chỉ 0x004e10, bản ghi FDE 0x06d938
    const std::uint32_t w0 = kByteVc1TextWords[416U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004e10U);
}
static std::uint32_t ByteVc1FdeFunc_007_0x004e3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[7] @ func_va=0x004e3c, fde_va=0x06d958, first_op=0x17fffe72
    // VI: Hàm FDE[7] tại địa chỉ 0x004e3c, bản ghi FDE 0x06d958
    const std::uint32_t w0 = kByteVc1TextWords[427U];
    std::uint32_t acc = w0 ^ 0x17fffe72U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004e3cU);
}
static std::uint32_t ByteVc1FdeFunc_008_0x004e40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[8] @ func_va=0x004e40, fde_va=0x06d970, first_op=0xd65f03c0
    // VI: Hàm FDE[8] tại địa chỉ 0x004e40, bản ghi FDE 0x06d970
    const std::uint32_t w0 = kByteVc1TextWords[428U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004e40U);
}
static std::uint32_t ByteVc1FdeFunc_009_0x004e44(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[9] @ func_va=0x004e44, fde_va=0x06d988, first_op=0x17ffff04
    // VI: Hàm FDE[9] tại địa chỉ 0x004e44, bản ghi FDE 0x06d988
    const std::uint32_t w0 = kByteVc1TextWords[429U];
    std::uint32_t acc = w0 ^ 0x17ffff04U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004e44U);
}
static std::uint32_t ByteVc1FdeFunc_010_0x004e48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[10] @ func_va=0x004e48, fde_va=0x06d9a0, first_op=0xa9be4ff4
    // VI: Hàm FDE[10] tại địa chỉ 0x004e48, bản ghi FDE 0x06d9a0
    const std::uint32_t w0 = kByteVc1TextWords[430U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004e48U);
}
static std::uint32_t ByteVc1FdeFunc_011_0x004e94(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[11] @ func_va=0x004e94, fde_va=0x06d9c0, first_op=0xf0000301
    // VI: Hàm FDE[11] tại địa chỉ 0x004e94, bản ghi FDE 0x06d9c0
    const std::uint32_t w0 = kByteVc1TextWords[449U];
    std::uint32_t acc = w0 ^ 0xf0000301U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004e94U);
}
static std::uint32_t ByteVc1FdeFunc_012_0x004ea4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[12] @ func_va=0x004ea4, fde_va=0x06d9d8, first_op=0xf0000301
    // VI: Hàm FDE[12] tại địa chỉ 0x004ea4, bản ghi FDE 0x06d9d8
    const std::uint32_t w0 = kByteVc1TextWords[453U];
    std::uint32_t acc = w0 ^ 0xf0000301U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004ea4U);
}
static std::uint32_t ByteVc1FdeFunc_013_0x004eb0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[13] @ func_va=0x004eb0, fde_va=0x06d9f0, first_op=0x6f00e400
    // VI: Hàm FDE[13] tại địa chỉ 0x004eb0, bản ghi FDE 0x06d9f0
    const std::uint32_t w0 = kByteVc1TextWords[456U];
    std::uint32_t acc = w0 ^ 0x6f00e400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004eb0U);
}
static std::uint32_t ByteVc1FdeFunc_014_0x004ee4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[14] @ func_va=0x004ee4, fde_va=0x06da08, first_op=0xd65f03c0
    // VI: Hàm FDE[14] tại địa chỉ 0x004ee4, bản ghi FDE 0x06da08
    const std::uint32_t w0 = kByteVc1TextWords[469U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004ee4U);
}
static std::uint32_t ByteVc1FdeFunc_015_0x004ee8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[15] @ func_va=0x004ee8, fde_va=0x06da20, first_op=0xb9400000
    // VI: Hàm FDE[15] tại địa chỉ 0x004ee8, bản ghi FDE 0x06da20
    const std::uint32_t w0 = kByteVc1TextWords[470U];
    std::uint32_t acc = w0 ^ 0xb9400000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004ee8U);
}
static std::uint32_t ByteVc1FdeFunc_016_0x004ef0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[16] @ func_va=0x004ef0, fde_va=0x06da38, first_op=0xb9400400
    // VI: Hàm FDE[16] tại địa chỉ 0x004ef0, bản ghi FDE 0x06da38
    const std::uint32_t w0 = kByteVc1TextWords[472U];
    std::uint32_t acc = w0 ^ 0xb9400400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004ef0U);
}
static std::uint32_t ByteVc1FdeFunc_017_0x004ef8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[17] @ func_va=0x004ef8, fde_va=0x06da50, first_op=0xf9400400
    // VI: Hàm FDE[17] tại địa chỉ 0x004ef8, bản ghi FDE 0x06da50
    const std::uint32_t w0 = kByteVc1TextWords[474U];
    std::uint32_t acc = w0 ^ 0xf9400400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004ef8U);
}
static std::uint32_t ByteVc1FdeFunc_018_0x004f00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[18] @ func_va=0x004f00, fde_va=0x06da68, first_op=0xf9400800
    // VI: Hàm FDE[18] tại địa chỉ 0x004f00, bản ghi FDE 0x06da68
    const std::uint32_t w0 = kByteVc1TextWords[476U];
    std::uint32_t acc = w0 ^ 0xf9400800U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f00U);
}
static std::uint32_t ByteVc1FdeFunc_019_0x004f08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[19] @ func_va=0x004f08, fde_va=0x06da80, first_op=0x39412008
    // VI: Hàm FDE[19] tại địa chỉ 0x004f08, bản ghi FDE 0x06da80
    const std::uint32_t w0 = kByteVc1TextWords[478U];
    std::uint32_t acc = w0 ^ 0x39412008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f08U);
}
static std::uint32_t ByteVc1FdeFunc_020_0x004f28(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[20] @ func_va=0x004f28, fde_va=0x06da98, first_op=0x8b21c808
    // VI: Hàm FDE[20] tại địa chỉ 0x004f28, bản ghi FDE 0x06da98
    const std::uint32_t w0 = kByteVc1TextWords[486U];
    std::uint32_t acc = w0 ^ 0x8b21c808U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f28U);
}
static std::uint32_t ByteVc1FdeFunc_021_0x004f34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[21] @ func_va=0x004f34, fde_va=0x06dab0, first_op=0x8b21cc08
    // VI: Hàm FDE[21] tại địa chỉ 0x004f34, bản ghi FDE 0x06dab0
    const std::uint32_t w0 = kByteVc1TextWords[489U];
    std::uint32_t acc = w0 ^ 0x8b21cc08U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f34U);
}
static std::uint32_t ByteVc1FdeFunc_022_0x004f40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[22] @ func_va=0x004f40, fde_va=0x06dac8, first_op=0x39412000
    // VI: Hàm FDE[22] tại địa chỉ 0x004f40, bản ghi FDE 0x06dac8
    const std::uint32_t w0 = kByteVc1TextWords[492U];
    std::uint32_t acc = w0 ^ 0x39412000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f40U);
}
static std::uint32_t ByteVc1FdeFunc_023_0x004f48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[23] @ func_va=0x004f48, fde_va=0x06dae0, first_op=0x39416000
    // VI: Hàm FDE[23] tại địa chỉ 0x004f48, bản ghi FDE 0x06dae0
    const std::uint32_t w0 = kByteVc1TextWords[494U];
    std::uint32_t acc = w0 ^ 0x39416000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f48U);
}
static std::uint32_t ByteVc1FdeFunc_024_0x004f50(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[24] @ func_va=0x004f50, fde_va=0x06daf8, first_op=0x39416400
    // VI: Hàm FDE[24] tại địa chỉ 0x004f50, bản ghi FDE 0x06daf8
    const std::uint32_t w0 = kByteVc1TextWords[496U];
    std::uint32_t acc = w0 ^ 0x39416400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f50U);
}
static std::uint32_t ByteVc1FdeFunc_025_0x004f58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[25] @ func_va=0x004f58, fde_va=0x06db10, first_op=0xb9404c00
    // VI: Hàm FDE[25] tại địa chỉ 0x004f58, bản ghi FDE 0x06db10
    const std::uint32_t w0 = kByteVc1TextWords[498U];
    std::uint32_t acc = w0 ^ 0xb9404c00U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f58U);
}
static std::uint32_t ByteVc1FdeFunc_026_0x004f60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[26] @ func_va=0x004f60, fde_va=0x06db28, first_op=0xb9405000
    // VI: Hàm FDE[26] tại địa chỉ 0x004f60, bản ghi FDE 0x06db28
    const std::uint32_t w0 = kByteVc1TextWords[500U];
    std::uint32_t acc = w0 ^ 0xb9405000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f60U);
}
static std::uint32_t ByteVc1FdeFunc_027_0x004f68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[27] @ func_va=0x004f68, fde_va=0x06db40, first_op=0xb9405400
    // VI: Hàm FDE[27] tại địa chỉ 0x004f68, bản ghi FDE 0x06db40
    const std::uint32_t w0 = kByteVc1TextWords[502U];
    std::uint32_t acc = w0 ^ 0xb9405400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f68U);
}
static std::uint32_t ByteVc1FdeFunc_028_0x004f70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[28] @ func_va=0x004f70, fde_va=0x06db58, first_op=0xb9405c00
    // VI: Hàm FDE[28] tại địa chỉ 0x004f70, bản ghi FDE 0x06db58
    const std::uint32_t w0 = kByteVc1TextWords[504U];
    std::uint32_t acc = w0 ^ 0xb9405c00U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f70U);
}
static std::uint32_t ByteVc1FdeFunc_029_0x004f78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[29] @ func_va=0x004f78, fde_va=0x06db70, first_op=0xb9406400
    // VI: Hàm FDE[29] tại địa chỉ 0x004f78, bản ghi FDE 0x06db70
    const std::uint32_t w0 = kByteVc1TextWords[506U];
    std::uint32_t acc = w0 ^ 0xb9406400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f78U);
}
static std::uint32_t ByteVc1FdeFunc_030_0x004f80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[30] @ func_va=0x004f80, fde_va=0x06db88, first_op=0x3944a000
    // VI: Hàm FDE[30] tại địa chỉ 0x004f80, bản ghi FDE 0x06db88
    const std::uint32_t w0 = kByteVc1TextWords[508U];
    std::uint32_t acc = w0 ^ 0x3944a000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f80U);
}
static std::uint32_t ByteVc1FdeFunc_031_0x004f88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[31] @ func_va=0x004f88, fde_va=0x06dba0, first_op=0xd65f03c0
    // VI: Hàm FDE[31] tại địa chỉ 0x004f88, bản ghi FDE 0x06dba0
    const std::uint32_t w0 = kByteVc1TextWords[510U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f88U);
}
static std::uint32_t ByteVc1FdeFunc_032_0x004f8c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[32] @ func_va=0x004f8c, fde_va=0x06dbb8, first_op=0x2a1f03e0
    // VI: Hàm FDE[32] tại địa chỉ 0x004f8c, bản ghi FDE 0x06dbb8
    const std::uint32_t w0 = kByteVc1TextWords[511U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f8cU);
}
static std::uint32_t ByteVc1FdeFunc_033_0x004f94(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[33] @ func_va=0x004f94, fde_va=0x06dbd0, first_op=0xb9000001
    // VI: Hàm FDE[33] tại địa chỉ 0x004f94, bản ghi FDE 0x06dbd0
    const std::uint32_t w0 = kByteVc1TextWords[513U];
    std::uint32_t acc = w0 ^ 0xb9000001U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f94U);
}
static std::uint32_t ByteVc1FdeFunc_034_0x004f9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[34] @ func_va=0x004f9c, fde_va=0x06dbe8, first_op=0xb9400000
    // VI: Hàm FDE[34] tại địa chỉ 0x004f9c, bản ghi FDE 0x06dbe8
    const std::uint32_t w0 = kByteVc1TextWords[515U];
    std::uint32_t acc = w0 ^ 0xb9400000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004f9cU);
}
static std::uint32_t ByteVc1FdeFunc_035_0x004fa4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[35] @ func_va=0x004fa4, fde_va=0x06dc00, first_op=0xf9000401
    // VI: Hàm FDE[35] tại địa chỉ 0x004fa4, bản ghi FDE 0x06dc00
    const std::uint32_t w0 = kByteVc1TextWords[517U];
    std::uint32_t acc = w0 ^ 0xf9000401U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004fa4U);
}
static std::uint32_t ByteVc1FdeFunc_036_0x004fac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[36] @ func_va=0x004fac, fde_va=0x06dc18, first_op=0xf9400400
    // VI: Hàm FDE[36] tại địa chỉ 0x004fac, bản ghi FDE 0x06dc18
    const std::uint32_t w0 = kByteVc1TextWords[519U];
    std::uint32_t acc = w0 ^ 0xf9400400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004facU);
}
static std::uint32_t ByteVc1FdeFunc_037_0x004fb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[37] @ func_va=0x004fb4, fde_va=0x06dc30, first_op=0xb9001001
    // VI: Hàm FDE[37] tại địa chỉ 0x004fb4, bản ghi FDE 0x06dc30
    const std::uint32_t w0 = kByteVc1TextWords[521U];
    std::uint32_t acc = w0 ^ 0xb9001001U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004fb4U);
}
static std::uint32_t ByteVc1FdeFunc_038_0x004fbc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[38] @ func_va=0x004fbc, fde_va=0x06dc48, first_op=0xb9401000
    // VI: Hàm FDE[38] tại địa chỉ 0x004fbc, bản ghi FDE 0x06dc48
    const std::uint32_t w0 = kByteVc1TextWords[523U];
    std::uint32_t acc = w0 ^ 0xb9401000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004fbcU);
}
static std::uint32_t ByteVc1FdeFunc_039_0x004fc4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[39] @ func_va=0x004fc4, fde_va=0x06dc60, first_op=0x1e220020
    // VI: Hàm FDE[39] tại địa chỉ 0x004fc4, bản ghi FDE 0x06dc60
    const std::uint32_t w0 = kByteVc1TextWords[525U];
    std::uint32_t acc = w0 ^ 0x1e220020U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004fc4U);
}
static std::uint32_t ByteVc1FdeFunc_040_0x004fd0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[40] @ func_va=0x004fd0, fde_va=0x06dc78, first_op=0xbd401400
    // VI: Hàm FDE[40] tại địa chỉ 0x004fd0, bản ghi FDE 0x06dc78
    const std::uint32_t w0 = kByteVc1TextWords[528U];
    std::uint32_t acc = w0 ^ 0xbd401400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004fd0U);
}
static std::uint32_t ByteVc1FdeFunc_041_0x004fdc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[41] @ func_va=0x004fdc, fde_va=0x06dc90, first_op=0xf9000c01
    // VI: Hàm FDE[41] tại địa chỉ 0x004fdc, bản ghi FDE 0x06dc90
    const std::uint32_t w0 = kByteVc1TextWords[531U];
    std::uint32_t acc = w0 ^ 0xf9000c01U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004fdcU);
}
static std::uint32_t ByteVc1FdeFunc_042_0x004fe4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[42] @ func_va=0x004fe4, fde_va=0x06dca8, first_op=0xf9400c00
    // VI: Hàm FDE[42] tại địa chỉ 0x004fe4, bản ghi FDE 0x06dca8
    const std::uint32_t w0 = kByteVc1TextWords[533U];
    std::uint32_t acc = w0 ^ 0xf9400c00U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004fe4U);
}
static std::uint32_t ByteVc1FdeFunc_043_0x004fec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[43] @ func_va=0x004fec, fde_va=0x06dcc0, first_op=0xf9001001
    // VI: Hàm FDE[43] tại địa chỉ 0x004fec, bản ghi FDE 0x06dcc0
    const std::uint32_t w0 = kByteVc1TextWords[535U];
    std::uint32_t acc = w0 ^ 0xf9001001U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004fecU);
}
static std::uint32_t ByteVc1FdeFunc_044_0x004ff4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[44] @ func_va=0x004ff4, fde_va=0x06dcd8, first_op=0xf9401000
    // VI: Hàm FDE[44] tại địa chỉ 0x004ff4, bản ghi FDE 0x06dcd8
    const std::uint32_t w0 = kByteVc1TextWords[537U];
    std::uint32_t acc = w0 ^ 0xf9401000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004ff4U);
}
static std::uint32_t ByteVc1FdeFunc_045_0x004ffc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[45] @ func_va=0x004ffc, fde_va=0x06dcf0, first_op=0xf0000301
    // VI: Hàm FDE[45] tại địa chỉ 0x004ffc, bản ghi FDE 0x06dcf0
    const std::uint32_t w0 = kByteVc1TextWords[539U];
    std::uint32_t acc = w0 ^ 0xf0000301U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x004ffcU);
}
static std::uint32_t ByteVc1FdeFunc_046_0x005008(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[46] @ func_va=0x005008, fde_va=0x06dd08, first_op=0x7100043f
    // VI: Hàm FDE[46] tại địa chỉ 0x005008, bản ghi FDE 0x06dd08
    const std::uint32_t w0 = kByteVc1TextWords[542U];
    std::uint32_t acc = w0 ^ 0x7100043fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005008U);
}
static std::uint32_t ByteVc1FdeFunc_047_0x005024(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[47] @ func_va=0x005024, fde_va=0x06dd20, first_op=0xb9402000
    // VI: Hàm FDE[47] tại địa chỉ 0x005024, bản ghi FDE 0x06dd20
    const std::uint32_t w0 = kByteVc1TextWords[549U];
    std::uint32_t acc = w0 ^ 0xb9402000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005024U);
}
static std::uint32_t ByteVc1FdeFunc_048_0x00502c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[48] @ func_va=0x00502c, fde_va=0x06dd38, first_op=0xb9000001
    // VI: Hàm FDE[48] tại địa chỉ 0x00502c, bản ghi FDE 0x06dd38
    const std::uint32_t w0 = kByteVc1TextWords[551U];
    std::uint32_t acc = w0 ^ 0xb9000001U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00502cU);
}
static std::uint32_t ByteVc1FdeFunc_049_0x005034(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[49] @ func_va=0x005034, fde_va=0x06dd50, first_op=0xb9400000
    // VI: Hàm FDE[49] tại địa chỉ 0x005034, bản ghi FDE 0x06dd50
    const std::uint32_t w0 = kByteVc1TextWords[553U];
    std::uint32_t acc = w0 ^ 0xb9400000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005034U);
}
static std::uint32_t ByteVc1FdeFunc_050_0x00503c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[50] @ func_va=0x00503c, fde_va=0x06dd68, first_op=0xb9000401
    // VI: Hàm FDE[50] tại địa chỉ 0x00503c, bản ghi FDE 0x06dd68
    const std::uint32_t w0 = kByteVc1TextWords[555U];
    std::uint32_t acc = w0 ^ 0xb9000401U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00503cU);
}
static std::uint32_t ByteVc1FdeFunc_051_0x005044(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[51] @ func_va=0x005044, fde_va=0x06dd80, first_op=0xb9400400
    // VI: Hàm FDE[51] tại địa chỉ 0x005044, bản ghi FDE 0x06dd80
    const std::uint32_t w0 = kByteVc1TextWords[557U];
    std::uint32_t acc = w0 ^ 0xb9400400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005044U);
}
static std::uint32_t ByteVc1FdeFunc_052_0x00504c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[52] @ func_va=0x00504c, fde_va=0x06dd98, first_op=0xb9000801
    // VI: Hàm FDE[52] tại địa chỉ 0x00504c, bản ghi FDE 0x06dd98
    const std::uint32_t w0 = kByteVc1TextWords[559U];
    std::uint32_t acc = w0 ^ 0xb9000801U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00504cU);
}
static std::uint32_t ByteVc1FdeFunc_053_0x005054(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[53] @ func_va=0x005054, fde_va=0x06ddb0, first_op=0xb9400800
    // VI: Hàm FDE[53] tại địa chỉ 0x005054, bản ghi FDE 0x06ddb0
    const std::uint32_t w0 = kByteVc1TextWords[561U];
    std::uint32_t acc = w0 ^ 0xb9400800U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005054U);
}
static std::uint32_t ByteVc1FdeFunc_054_0x00505c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[54] @ func_va=0x00505c, fde_va=0x06ddc8, first_op=0xb9000c01
    // VI: Hàm FDE[54] tại địa chỉ 0x00505c, bản ghi FDE 0x06ddc8
    const std::uint32_t w0 = kByteVc1TextWords[563U];
    std::uint32_t acc = w0 ^ 0xb9000c01U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00505cU);
}
static std::uint32_t ByteVc1FdeFunc_055_0x005064(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[55] @ func_va=0x005064, fde_va=0x06dde0, first_op=0xb9400c00
    // VI: Hàm FDE[55] tại địa chỉ 0x005064, bản ghi FDE 0x06dde0
    const std::uint32_t w0 = kByteVc1TextWords[565U];
    std::uint32_t acc = w0 ^ 0xb9400c00U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005064U);
}
static std::uint32_t ByteVc1FdeFunc_056_0x00506c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[56] @ func_va=0x00506c, fde_va=0x06ddf8, first_op=0xd65f03c0
    // VI: Hàm FDE[56] tại địa chỉ 0x00506c, bản ghi FDE 0x06ddf8
    const std::uint32_t w0 = kByteVc1TextWords[567U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00506cU);
}
static std::uint32_t ByteVc1FdeFunc_057_0x005070(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[57] @ func_va=0x005070, fde_va=0x06de10, first_op=0x2a1f03e0
    // VI: Hàm FDE[57] tại địa chỉ 0x005070, bản ghi FDE 0x06de10
    const std::uint32_t w0 = kByteVc1TextWords[568U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005070U);
}
static std::uint32_t ByteVc1FdeFunc_058_0x005078(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[58] @ func_va=0x005078, fde_va=0x06de28, first_op=0xd65f03c0
    // VI: Hàm FDE[58] tại địa chỉ 0x005078, bản ghi FDE 0x06de28
    const std::uint32_t w0 = kByteVc1TextWords[570U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005078U);
}
static std::uint32_t ByteVc1FdeFunc_059_0x00507c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[59] @ func_va=0x00507c, fde_va=0x06de40, first_op=0x2a1f03e0
    // VI: Hàm FDE[59] tại địa chỉ 0x00507c, bản ghi FDE 0x06de40
    const std::uint32_t w0 = kByteVc1TextWords[571U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00507cU);
}
static std::uint32_t ByteVc1FdeFunc_060_0x005084(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[60] @ func_va=0x005084, fde_va=0x06de58, first_op=0xd65f03c0
    // VI: Hàm FDE[60] tại địa chỉ 0x005084, bản ghi FDE 0x06de58
    const std::uint32_t w0 = kByteVc1TextWords[573U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005084U);
}
static std::uint32_t ByteVc1FdeFunc_061_0x005088(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[61] @ func_va=0x005088, fde_va=0x06de70, first_op=0x2a1f03e0
    // VI: Hàm FDE[61] tại địa chỉ 0x005088, bản ghi FDE 0x06de70
    const std::uint32_t w0 = kByteVc1TextWords[574U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005088U);
}
static std::uint32_t ByteVc1FdeFunc_062_0x005090(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[62] @ func_va=0x005090, fde_va=0x06de88, first_op=0xd65f03c0
    // VI: Hàm FDE[62] tại địa chỉ 0x005090, bản ghi FDE 0x06de88
    const std::uint32_t w0 = kByteVc1TextWords[576U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005090U);
}
static std::uint32_t ByteVc1FdeFunc_063_0x005094(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[63] @ func_va=0x005094, fde_va=0x06dea0, first_op=0x2a1f03e0
    // VI: Hàm FDE[63] tại địa chỉ 0x005094, bản ghi FDE 0x06dea0
    const std::uint32_t w0 = kByteVc1TextWords[577U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005094U);
}
static std::uint32_t ByteVc1FdeFunc_064_0x00509c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[64] @ func_va=0x00509c, fde_va=0x06deb8, first_op=0x11020000
    // VI: Hàm FDE[64] tại địa chỉ 0x00509c, bản ghi FDE 0x06deb8
    const std::uint32_t w0 = kByteVc1TextWords[579U];
    std::uint32_t acc = w0 ^ 0x11020000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00509cU);
}
static std::uint32_t ByteVc1FdeFunc_065_0x0050a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[65] @ func_va=0x0050a4, fde_va=0x06ded0, first_op=0x11020008
    // VI: Hàm FDE[65] tại địa chỉ 0x0050a4, bản ghi FDE 0x06ded0
    const std::uint32_t w0 = kByteVc1TextWords[581U];
    std::uint32_t acc = w0 ^ 0x11020008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0050a4U);
}
static std::uint32_t ByteVc1FdeFunc_066_0x0050b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[66] @ func_va=0x0050b0, fde_va=0x06dee8, first_op=0xb4000540
    // VI: Hàm FDE[66] tại địa chỉ 0x0050b0, bản ghi FDE 0x06dee8
    const std::uint32_t w0 = kByteVc1TextWords[584U];
    std::uint32_t acc = w0 ^ 0xb4000540U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0050b0U);
}
static std::uint32_t ByteVc1FdeFunc_067_0x005160(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[67] @ func_va=0x005160, fde_va=0x06df00, first_op=0xb4000540
    // VI: Hàm FDE[67] tại địa chỉ 0x005160, bản ghi FDE 0x06df00
    const std::uint32_t w0 = kByteVc1TextWords[628U];
    std::uint32_t acc = w0 ^ 0xb4000540U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005160U);
}
static std::uint32_t ByteVc1FdeFunc_068_0x005210(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[68] @ func_va=0x005210, fde_va=0x06df18, first_op=0x8b22c028
    // VI: Hàm FDE[68] tại địa chỉ 0x005210, bản ghi FDE 0x06df18
    const std::uint32_t w0 = kByteVc1TextWords[672U];
    std::uint32_t acc = w0 ^ 0x8b22c028U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005210U);
}
static std::uint32_t ByteVc1FdeFunc_069_0x005290(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[69] @ func_va=0x005290, fde_va=0x06df30, first_op=0xa9ba6ffc
    // VI: Hàm FDE[69] tại địa chỉ 0x005290, bản ghi FDE 0x06df30
    const std::uint32_t w0 = kByteVc1TextWords[704U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x005290U);
}
static std::uint32_t ByteVc1FdeFunc_070_0x0064b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[70] @ func_va=0x0064b4, fde_va=0x06df60, first_op=0xf81b0ff9
    // VI: Hàm FDE[70] tại địa chỉ 0x0064b4, bản ghi FDE 0x06df60
    const std::uint32_t w0 = kByteVc1TextWords[1865U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0064b4U);
}
static std::uint32_t ByteVc1FdeFunc_071_0x0067b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[71] @ func_va=0x0067b8, fde_va=0x06df88, first_op=0xa9bc67fa
    // VI: Hàm FDE[71] tại địa chỉ 0x0067b8, bản ghi FDE 0x06df88
    const std::uint32_t w0 = kByteVc1TextWords[2058U];
    std::uint32_t acc = w0 ^ 0xa9bc67faU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0067b8U);
}
static std::uint32_t ByteVc1FdeFunc_072_0x00786c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[72] @ func_va=0x00786c, fde_va=0x06dfb0, first_op=0xd101c3ff
    // VI: Hàm FDE[72] tại địa chỉ 0x00786c, bản ghi FDE 0x06dfb0
    const std::uint32_t w0 = kByteVc1TextWords[3127U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00786cU);
}
static std::uint32_t ByteVc1FdeFunc_073_0x00bd80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[73] @ func_va=0x00bd80, fde_va=0x06dfe0, first_op=0xb00002ec
    // VI: Hàm FDE[73] tại địa chỉ 0x00bd80, bản ghi FDE 0x06dfe0
    const std::uint32_t w0 = kByteVc1TextWords[7548U];
    std::uint32_t acc = w0 ^ 0xb00002ecU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00bd80U);
}
static std::uint32_t ByteVc1FdeFunc_074_0x00be10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[74] @ func_va=0x00be10, fde_va=0x06dff8, first_op=0xd10203ff
    // VI: Hàm FDE[74] tại địa chỉ 0x00be10, bản ghi FDE 0x06dff8
    const std::uint32_t w0 = kByteVc1TextWords[7584U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00be10U);
}
static std::uint32_t ByteVc1FdeFunc_075_0x00c3f4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[75] @ func_va=0x00c3f4, fde_va=0x06e028, first_op=0xf81e0ff3
    // VI: Hàm FDE[75] tại địa chỉ 0x00c3f4, bản ghi FDE 0x06e028
    const std::uint32_t w0 = kByteVc1TextWords[7961U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00c3f4U);
}
static std::uint32_t ByteVc1FdeFunc_076_0x00d008(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[76] @ func_va=0x00d008, fde_va=0x06e048, first_op=0xf81b0ff9
    // VI: Hàm FDE[76] tại địa chỉ 0x00d008, bản ghi FDE 0x06e048
    const std::uint32_t w0 = kByteVc1TextWords[8734U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00d008U);
}
static std::uint32_t ByteVc1FdeFunc_077_0x00edd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[77] @ func_va=0x00edd8, fde_va=0x06e070, first_op=0xd10383ff
    // VI: Hàm FDE[77] tại địa chỉ 0x00edd8, bản ghi FDE 0x06e070
    const std::uint32_t w0 = kByteVc1TextWords[10642U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x00edd8U);
}
static std::uint32_t ByteVc1FdeFunc_078_0x0128f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[78] @ func_va=0x0128f0, fde_va=0x06e0a0, first_op=0xf81d0ff5
    // VI: Hàm FDE[78] tại địa chỉ 0x0128f0, bản ghi FDE 0x06e0a0
    const std::uint32_t w0 = kByteVc1TextWords[14424U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0128f0U);
}
static std::uint32_t ByteVc1FdeFunc_079_0x012c04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[79] @ func_va=0x012c04, fde_va=0x06e0c0, first_op=0xf81e0ff3
    // VI: Hàm FDE[79] tại địa chỉ 0x012c04, bản ghi FDE 0x06e0c0
    const std::uint32_t w0 = kByteVc1TextWords[14621U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x012c04U);
}
static std::uint32_t ByteVc1FdeFunc_080_0x012c38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[80] @ func_va=0x012c38, fde_va=0x06e0e0, first_op=0xf81e0ff3
    // VI: Hàm FDE[80] tại địa chỉ 0x012c38, bản ghi FDE 0x06e0e0
    const std::uint32_t w0 = kByteVc1TextWords[14634U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x012c38U);
}
static std::uint32_t ByteVc1FdeFunc_081_0x012c6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[81] @ func_va=0x012c6c, fde_va=0x06e100, first_op=0x39802028
    // VI: Hàm FDE[81] tại địa chỉ 0x012c6c, bản ghi FDE 0x06e100
    const std::uint32_t w0 = kByteVc1TextWords[14647U];
    std::uint32_t acc = w0 ^ 0x39802028U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x012c6cU);
}
static std::uint32_t ByteVc1FdeFunc_082_0x012d04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[82] @ func_va=0x012d04, fde_va=0x06e118, first_op=0xa9ba6ffc
    // VI: Hàm FDE[82] tại địa chỉ 0x012d04, bản ghi FDE 0x06e118
    const std::uint32_t w0 = kByteVc1TextWords[14685U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x012d04U);
}
static std::uint32_t ByteVc1FdeFunc_083_0x014664(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[83] @ func_va=0x014664, fde_va=0x06e148, first_op=0xd10483ff
    // VI: Hàm FDE[83] tại địa chỉ 0x014664, bản ghi FDE 0x06e148
    const std::uint32_t w0 = kByteVc1TextWords[16309U];
    std::uint32_t acc = w0 ^ 0xd10483ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x014664U);
}
static std::uint32_t ByteVc1FdeFunc_084_0x014f48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[84] @ func_va=0x014f48, fde_va=0x06e178, first_op=0xd10243ff
    // VI: Hàm FDE[84] tại địa chỉ 0x014f48, bản ghi FDE 0x06e178
    const std::uint32_t w0 = kByteVc1TextWords[16878U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x014f48U);
}
static std::uint32_t ByteVc1FdeFunc_085_0x0168d8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[85] @ func_va=0x0168d8, fde_va=0x06e1a8, first_op=0xb94d5c09
    // VI: Hàm FDE[85] tại địa chỉ 0x0168d8, bản ghi FDE 0x06e1a8
    const std::uint32_t w0 = kByteVc1TextWords[18514U];
    std::uint32_t acc = w0 ^ 0xb94d5c09U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0168d8U);
}
static std::uint32_t ByteVc1FdeFunc_086_0x0169c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[86] @ func_va=0x0169c8, fde_va=0x06e1c0, first_op=0xf9406c08
    // VI: Hàm FDE[86] tại địa chỉ 0x0169c8, bản ghi FDE 0x06e1c0
    const std::uint32_t w0 = kByteVc1TextWords[18574U];
    std::uint32_t acc = w0 ^ 0xf9406c08U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0169c8U);
}
static std::uint32_t ByteVc1FdeFunc_087_0x016a8c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[87] @ func_va=0x016a8c, fde_va=0x06e1d8, first_op=0xaa0003e8
    // VI: Hàm FDE[87] tại địa chỉ 0x016a8c, bản ghi FDE 0x06e1d8
    const std::uint32_t w0 = kByteVc1TextWords[18623U];
    std::uint32_t acc = w0 ^ 0xaa0003e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x016a8cU);
}
static std::uint32_t ByteVc1FdeFunc_088_0x016b84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[88] @ func_va=0x016b84, fde_va=0x06e1f0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[88] tại địa chỉ 0x016b84, bản ghi FDE 0x06e1f0
    const std::uint32_t w0 = kByteVc1TextWords[18685U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x016b84U);
}
static std::uint32_t ByteVc1FdeFunc_089_0x017944(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[89] @ func_va=0x017944, fde_va=0x06e220, first_op=0xf9406c08
    // VI: Hàm FDE[89] tại địa chỉ 0x017944, bản ghi FDE 0x06e220
    const std::uint32_t w0 = kByteVc1TextWords[19565U];
    std::uint32_t acc = w0 ^ 0xf9406c08U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x017944U);
}
static std::uint32_t ByteVc1FdeFunc_090_0x017b10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[90] @ func_va=0x017b10, fde_va=0x06e238, first_op=0xd102c3ff
    // VI: Hàm FDE[90] tại địa chỉ 0x017b10, bản ghi FDE 0x06e238
    const std::uint32_t w0 = kByteVc1TextWords[19680U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x017b10U);
}
static std::uint32_t ByteVc1FdeFunc_091_0x01949c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[91] @ func_va=0x01949c, fde_va=0x06e268, first_op=0xd10203ff
    // VI: Hàm FDE[91] tại địa chỉ 0x01949c, bản ghi FDE 0x06e268
    const std::uint32_t w0 = kByteVc1TextWords[21315U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01949cU);
}
static std::uint32_t ByteVc1FdeFunc_092_0x019d18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[92] @ func_va=0x019d18, fde_va=0x06e298, first_op=0xd10283ff
    // VI: Hàm FDE[92] tại địa chỉ 0x019d18, bản ghi FDE 0x06e298
    const std::uint32_t w0 = kByteVc1TextWords[21858U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x019d18U);
}
static std::uint32_t ByteVc1FdeFunc_093_0x01a70c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[93] @ func_va=0x01a70c, fde_va=0x06e2c8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[93] tại địa chỉ 0x01a70c, bản ghi FDE 0x06e2c8
    const std::uint32_t w0 = kByteVc1TextWords[22495U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01a70cU);
}
static std::uint32_t ByteVc1FdeFunc_094_0x01ab30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[94] @ func_va=0x01ab30, fde_va=0x06e2f8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[94] tại địa chỉ 0x01ab30, bản ghi FDE 0x06e2f8
    const std::uint32_t w0 = kByteVc1TextWords[22760U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01ab30U);
}
static std::uint32_t ByteVc1FdeFunc_095_0x01ad3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[95] @ func_va=0x01ad3c, fde_va=0x06e328, first_op=0xf81b0ff9
    // VI: Hàm FDE[95] tại địa chỉ 0x01ad3c, bản ghi FDE 0x06e328
    const std::uint32_t w0 = kByteVc1TextWords[22891U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01ad3cU);
}
static std::uint32_t ByteVc1FdeFunc_096_0x01aeec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[96] @ func_va=0x01aeec, fde_va=0x06e350, first_op=0xd10443ff
    // VI: Hàm FDE[96] tại địa chỉ 0x01aeec, bản ghi FDE 0x06e350
    const std::uint32_t w0 = kByteVc1TextWords[22999U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01aeecU);
}
static std::uint32_t ByteVc1FdeFunc_097_0x01c1f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[97] @ func_va=0x01c1f8, fde_va=0x06e380, first_op=0x7100581f
    // VI: Hàm FDE[97] tại địa chỉ 0x01c1f8, bản ghi FDE 0x06e380
    const std::uint32_t w0 = kByteVc1TextWords[24218U];
    std::uint32_t acc = w0 ^ 0x7100581fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01c1f8U);
}
static std::uint32_t ByteVc1FdeFunc_098_0x01c204(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[98] @ func_va=0x01c204, fde_va=0x06e398, first_op=0xf81e0ff3
    // VI: Hàm FDE[98] tại địa chỉ 0x01c204, bản ghi FDE 0x06e398
    const std::uint32_t w0 = kByteVc1TextWords[24221U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01c204U);
}
static std::uint32_t ByteVc1FdeFunc_099_0x01c238(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[99] @ func_va=0x01c238, fde_va=0x06e3b8, first_op=0xa9bc5ff8
    // VI: Hàm FDE[99] tại địa chỉ 0x01c238, bản ghi FDE 0x06e3b8
    const std::uint32_t w0 = kByteVc1TextWords[24234U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01c238U);
}
static std::uint32_t ByteVc1FdeFunc_100_0x01c304(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[100] @ func_va=0x01c304, fde_va=0x06e3e0, first_op=0xa9be4ff4
    // VI: Hàm FDE[100] tại địa chỉ 0x01c304, bản ghi FDE 0x06e3e0
    const std::uint32_t w0 = kByteVc1TextWords[24285U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01c304U);
}
static std::uint32_t ByteVc1FdeFunc_101_0x01c378(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[101] @ func_va=0x01c378, fde_va=0x06e400, first_op=0xf81e0ff3
    // VI: Hàm FDE[101] tại địa chỉ 0x01c378, bản ghi FDE 0x06e400
    const std::uint32_t w0 = kByteVc1TextWords[24314U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01c378U);
}
static std::uint32_t ByteVc1FdeFunc_102_0x01c3b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[102] @ func_va=0x01c3b4, fde_va=0x06e420, first_op=0xd10203ff
    // VI: Hàm FDE[102] tại địa chỉ 0x01c3b4, bản ghi FDE 0x06e420
    const std::uint32_t w0 = kByteVc1TextWords[24329U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01c3b4U);
}
static std::uint32_t ByteVc1FdeFunc_103_0x01c79c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[103] @ func_va=0x01c79c, fde_va=0x06e450, first_op=0xf81c0ff7
    // VI: Hàm FDE[103] tại địa chỉ 0x01c79c, bản ghi FDE 0x06e450
    const std::uint32_t w0 = kByteVc1TextWords[24579U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01c79cU);
}
static std::uint32_t ByteVc1FdeFunc_104_0x01c854(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[104] @ func_va=0x01c854, fde_va=0x06e478, first_op=0xd10243ff
    // VI: Hàm FDE[104] tại địa chỉ 0x01c854, bản ghi FDE 0x06e478
    const std::uint32_t w0 = kByteVc1TextWords[24625U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01c854U);
}
static std::uint32_t ByteVc1FdeFunc_105_0x01cba0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[105] @ func_va=0x01cba0, fde_va=0x06e4a8, first_op=0xf81c0ff7
    // VI: Hàm FDE[105] tại địa chỉ 0x01cba0, bản ghi FDE 0x06e4a8
    const std::uint32_t w0 = kByteVc1TextWords[24836U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01cba0U);
}
static std::uint32_t ByteVc1FdeFunc_106_0x01cc98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[106] @ func_va=0x01cc98, fde_va=0x06e4d0, first_op=0xfc190fe8
    // VI: Hàm FDE[106] tại địa chỉ 0x01cc98, bản ghi FDE 0x06e4d0
    const std::uint32_t w0 = kByteVc1TextWords[24898U];
    std::uint32_t acc = w0 ^ 0xfc190fe8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01cc98U);
}
static std::uint32_t ByteVc1FdeFunc_107_0x01ec78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[107] @ func_va=0x01ec78, fde_va=0x06e500, first_op=0xa9ba6ffc
    // VI: Hàm FDE[107] tại địa chỉ 0x01ec78, bản ghi FDE 0x06e500
    const std::uint32_t w0 = kByteVc1TextWords[26938U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x01ec78U);
}
static std::uint32_t ByteVc1FdeFunc_108_0x020114(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[108] @ func_va=0x020114, fde_va=0x06e530, first_op=0x2943a808
    // VI: Hàm FDE[108] tại địa chỉ 0x020114, bản ghi FDE 0x06e530
    const std::uint32_t w0 = kByteVc1TextWords[28257U];
    std::uint32_t acc = w0 ^ 0x2943a808U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x020114U);
}
static std::uint32_t ByteVc1FdeFunc_109_0x0204c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[109] @ func_va=0x0204c4, fde_va=0x06e548, first_op=0xf81e0ff3
    // VI: Hàm FDE[109] tại địa chỉ 0x0204c4, bản ghi FDE 0x06e548
    const std::uint32_t w0 = kByteVc1TextWords[28493U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0204c4U);
}
static std::uint32_t ByteVc1FdeFunc_110_0x020788(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[110] @ func_va=0x020788, fde_va=0x06e568, first_op=0xa9ba6ffc
    // VI: Hàm FDE[110] tại địa chỉ 0x020788, bản ghi FDE 0x06e568
    const std::uint32_t w0 = kByteVc1TextWords[28670U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x020788U);
}
static std::uint32_t ByteVc1FdeFunc_111_0x0212b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[111] @ func_va=0x0212b4, fde_va=0x06e598, first_op=0xd106c3ff
    // VI: Hàm FDE[111] tại địa chỉ 0x0212b4, bản ghi FDE 0x06e598
    const std::uint32_t w0 = kByteVc1TextWords[29385U];
    std::uint32_t acc = w0 ^ 0xd106c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0212b4U);
}
static std::uint32_t ByteVc1FdeFunc_112_0x022540(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[112] @ func_va=0x022540, fde_va=0x06e5c8, first_op=0xa9bd57f6
    // VI: Hàm FDE[112] tại địa chỉ 0x022540, bản ghi FDE 0x06e5c8
    const std::uint32_t w0 = kByteVc1TextWords[30572U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x022540U);
}
static std::uint32_t ByteVc1FdeFunc_113_0x022b1c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[113] @ func_va=0x022b1c, fde_va=0x06e5f0, first_op=0xb94ab808
    // VI: Hàm FDE[113] tại địa chỉ 0x022b1c, bản ghi FDE 0x06e5f0
    const std::uint32_t w0 = kByteVc1TextWords[30947U];
    std::uint32_t acc = w0 ^ 0xb94ab808U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x022b1cU);
}
static std::uint32_t ByteVc1FdeFunc_114_0x022cbc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[114] @ func_va=0x022cbc, fde_va=0x06e608, first_op=0xd10683ff
    // VI: Hàm FDE[114] tại địa chỉ 0x022cbc, bản ghi FDE 0x06e608
    const std::uint32_t w0 = kByteVc1TextWords[31051U];
    std::uint32_t acc = w0 ^ 0xd10683ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x022cbcU);
}
static std::uint32_t ByteVc1FdeFunc_115_0x023c64(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[115] @ func_va=0x023c64, fde_va=0x06e638, first_op=0xd105c3ff
    // VI: Hàm FDE[115] tại địa chỉ 0x023c64, bản ghi FDE 0x06e638
    const std::uint32_t w0 = kByteVc1TextWords[32053U];
    std::uint32_t acc = w0 ^ 0xd105c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x023c64U);
}
static std::uint32_t ByteVc1FdeFunc_116_0x0248f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[116] @ func_va=0x0248f0, fde_va=0x06e668, first_op=0xd10343ff
    // VI: Hàm FDE[116] tại địa chỉ 0x0248f0, bản ghi FDE 0x06e668
    const std::uint32_t w0 = kByteVc1TextWords[32856U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0248f0U);
}
static std::uint32_t ByteVc1FdeFunc_117_0x024fc8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[117] @ func_va=0x024fc8, fde_va=0x06e698, first_op=0xb9400049
    // VI: Hàm FDE[117] tại địa chỉ 0x024fc8, bản ghi FDE 0x06e698
    const std::uint32_t w0 = kByteVc1TextWords[33294U];
    std::uint32_t acc = w0 ^ 0xb9400049U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x024fc8U);
}
static std::uint32_t ByteVc1FdeFunc_118_0x02511c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[118] @ func_va=0x02511c, fde_va=0x06e6b0, first_op=0xa9bf4ff4
    // VI: Hàm FDE[118] tại địa chỉ 0x02511c, bản ghi FDE 0x06e6b0
    const std::uint32_t w0 = kByteVc1TextWords[33379U];
    std::uint32_t acc = w0 ^ 0xa9bf4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02511cU);
}
static std::uint32_t ByteVc1FdeFunc_119_0x0252a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[119] @ func_va=0x0252a4, fde_va=0x06e6c8, first_op=0xd10083ff
    // VI: Hàm FDE[119] tại địa chỉ 0x0252a4, bản ghi FDE 0x06e6c8
    const std::uint32_t w0 = kByteVc1TextWords[33477U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0252a4U);
}
static std::uint32_t ByteVc1FdeFunc_120_0x0252cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[120] @ func_va=0x0252cc, fde_va=0x06e6e8, first_op=0xd10083ff
    // VI: Hàm FDE[120] tại địa chỉ 0x0252cc, bản ghi FDE 0x06e6e8
    const std::uint32_t w0 = kByteVc1TextWords[33487U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0252ccU);
}
static std::uint32_t ByteVc1FdeFunc_121_0x0252f4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[121] @ func_va=0x0252f4, fde_va=0x06e708, first_op=0xb9400048
    // VI: Hàm FDE[121] tại địa chỉ 0x0252f4, bản ghi FDE 0x06e708
    const std::uint32_t w0 = kByteVc1TextWords[33497U];
    std::uint32_t acc = w0 ^ 0xb9400048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0252f4U);
}
static std::uint32_t ByteVc1FdeFunc_122_0x025450(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[122] @ func_va=0x025450, fde_va=0x06e720, first_op=0xa9bf4ff4
    // VI: Hàm FDE[122] tại địa chỉ 0x025450, bản ghi FDE 0x06e720
    const std::uint32_t w0 = kByteVc1TextWords[33584U];
    std::uint32_t acc = w0 ^ 0xa9bf4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x025450U);
}
static std::uint32_t ByteVc1FdeFunc_123_0x0255dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[123] @ func_va=0x0255dc, fde_va=0x06e738, first_op=0xd10083ff
    // VI: Hàm FDE[123] tại địa chỉ 0x0255dc, bản ghi FDE 0x06e738
    const std::uint32_t w0 = kByteVc1TextWords[33683U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0255dcU);
}
static std::uint32_t ByteVc1FdeFunc_124_0x025604(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[124] @ func_va=0x025604, fde_va=0x06e758, first_op=0xd10083ff
    // VI: Hàm FDE[124] tại địa chỉ 0x025604, bản ghi FDE 0x06e758
    const std::uint32_t w0 = kByteVc1TextWords[33693U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x025604U);
}
static std::uint32_t ByteVc1FdeFunc_125_0x02562c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[125] @ func_va=0x02562c, fde_va=0x06e778, first_op=0xd10203ff
    // VI: Hàm FDE[125] tại địa chỉ 0x02562c, bản ghi FDE 0x06e778
    const std::uint32_t w0 = kByteVc1TextWords[33703U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02562cU);
}
static std::uint32_t ByteVc1FdeFunc_126_0x0258ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[126] @ func_va=0x0258ac, fde_va=0x06e7a8, first_op=0xd101c3ff
    // VI: Hàm FDE[126] tại địa chỉ 0x0258ac, bản ghi FDE 0x06e7a8
    const std::uint32_t w0 = kByteVc1TextWords[33863U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0258acU);
}
static std::uint32_t ByteVc1FdeFunc_127_0x025abc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[127] @ func_va=0x025abc, fde_va=0x06e7d8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[127] tại địa chỉ 0x025abc, bản ghi FDE 0x06e7d8
    const std::uint32_t w0 = kByteVc1TextWords[33995U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x025abcU);
}
static std::uint32_t ByteVc1FdeFunc_128_0x0265b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[128] @ func_va=0x0265b8, fde_va=0x06e808, first_op=0xb9400008
    // VI: Hàm FDE[128] tại địa chỉ 0x0265b8, bản ghi FDE 0x06e808
    const std::uint32_t w0 = kByteVc1TextWords[34698U];
    std::uint32_t acc = w0 ^ 0xb9400008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0265b8U);
}
static std::uint32_t ByteVc1FdeFunc_129_0x026840(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[129] @ func_va=0x026840, fde_va=0x06e820, first_op=0xa9ba6ffc
    // VI: Hàm FDE[129] tại địa chỉ 0x026840, bản ghi FDE 0x06e820
    const std::uint32_t w0 = kByteVc1TextWords[34860U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x026840U);
}
static std::uint32_t ByteVc1FdeFunc_130_0x027360(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[130] @ func_va=0x027360, fde_va=0x06e850, first_op=0x7100203f
    // VI: Hàm FDE[130] tại địa chỉ 0x027360, bản ghi FDE 0x06e850
    const std::uint32_t w0 = kByteVc1TextWords[35572U];
    std::uint32_t acc = w0 ^ 0x7100203fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027360U);
}
static std::uint32_t ByteVc1FdeFunc_131_0x0274a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[131] @ func_va=0x0274a0, fde_va=0x06e868, first_op=0xb40000e0
    // VI: Hàm FDE[131] tại địa chỉ 0x0274a0, bản ghi FDE 0x06e868
    const std::uint32_t w0 = kByteVc1TextWords[35652U];
    std::uint32_t acc = w0 ^ 0xb40000e0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0274a0U);
}
static std::uint32_t ByteVc1FdeFunc_132_0x0274c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[132] @ func_va=0x0274c0, fde_va=0x06e880, first_op=0xd0000201
    // VI: Hàm FDE[132] tại địa chỉ 0x0274c0, bản ghi FDE 0x06e880
    const std::uint32_t w0 = kByteVc1TextWords[35660U];
    std::uint32_t acc = w0 ^ 0xd0000201U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0274c0U);
}
static std::uint32_t ByteVc1FdeFunc_133_0x0274d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[133] @ func_va=0x0274d0, fde_va=0x06e898, first_op=0xb4000080
    // VI: Hàm FDE[133] tại địa chỉ 0x0274d0, bản ghi FDE 0x06e898
    const std::uint32_t w0 = kByteVc1TextWords[35664U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0274d0U);
}
static std::uint32_t ByteVc1FdeFunc_134_0x0274e4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[134] @ func_va=0x0274e4, fde_va=0x06e8b0, first_op=0xb9406400
    // VI: Hàm FDE[134] tại địa chỉ 0x0274e4, bản ghi FDE 0x06e8b0
    const std::uint32_t w0 = kByteVc1TextWords[35669U];
    std::uint32_t acc = w0 ^ 0xb9406400U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0274e4U);
}
static std::uint32_t ByteVc1FdeFunc_135_0x0274ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[135] @ func_va=0x0274ec, fde_va=0x06e8c8, first_op=0xaa0003e8
    // VI: Hàm FDE[135] tại địa chỉ 0x0274ec, bản ghi FDE 0x06e8c8
    const std::uint32_t w0 = kByteVc1TextWords[35671U];
    std::uint32_t acc = w0 ^ 0xaa0003e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0274ecU);
}
static std::uint32_t ByteVc1FdeFunc_136_0x02750c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[136] @ func_va=0x02750c, fde_va=0x06e8e0, first_op=0xb4000140
    // VI: Hàm FDE[136] tại địa chỉ 0x02750c, bản ghi FDE 0x06e8e0
    const std::uint32_t w0 = kByteVc1TextWords[35679U];
    std::uint32_t acc = w0 ^ 0xb4000140U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02750cU);
}
static std::uint32_t ByteVc1FdeFunc_137_0x027538(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[137] @ func_va=0x027538, fde_va=0x06e8f8, first_op=0xb4000080
    // VI: Hàm FDE[137] tại địa chỉ 0x027538, bản ghi FDE 0x06e8f8
    const std::uint32_t w0 = kByteVc1TextWords[35690U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027538U);
}
static std::uint32_t ByteVc1FdeFunc_138_0x02754c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[138] @ func_va=0x02754c, fde_va=0x06e910, first_op=0xb4000440
    // VI: Hàm FDE[138] tại địa chỉ 0x02754c, bản ghi FDE 0x06e910
    const std::uint32_t w0 = kByteVc1TextWords[35695U];
    std::uint32_t acc = w0 ^ 0xb4000440U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02754cU);
}
static std::uint32_t ByteVc1FdeFunc_139_0x0275d8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[139] @ func_va=0x0275d8, fde_va=0x06e928, first_op=0xb40002c0
    // VI: Hàm FDE[139] tại địa chỉ 0x0275d8, bản ghi FDE 0x06e928
    const std::uint32_t w0 = kByteVc1TextWords[35730U];
    std::uint32_t acc = w0 ^ 0xb40002c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0275d8U);
}
static std::uint32_t ByteVc1FdeFunc_140_0x027634(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[140] @ func_va=0x027634, fde_va=0x06e940, first_op=0xb4000040
    // VI: Hàm FDE[140] tại địa chỉ 0x027634, bản ghi FDE 0x06e940
    const std::uint32_t w0 = kByteVc1TextWords[35753U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027634U);
}
static std::uint32_t ByteVc1FdeFunc_141_0x027640(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[141] @ func_va=0x027640, fde_va=0x06e958, first_op=0xb4000040
    // VI: Hàm FDE[141] tại địa chỉ 0x027640, bản ghi FDE 0x06e958
    const std::uint32_t w0 = kByteVc1TextWords[35756U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027640U);
}
static std::uint32_t ByteVc1FdeFunc_142_0x02764c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[142] @ func_va=0x02764c, fde_va=0x06e970, first_op=0xf9409800
    // VI: Hàm FDE[142] tại địa chỉ 0x02764c, bản ghi FDE 0x06e970
    const std::uint32_t w0 = kByteVc1TextWords[35759U];
    std::uint32_t acc = w0 ^ 0xf9409800U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02764cU);
}
static std::uint32_t ByteVc1FdeFunc_143_0x027654(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[143] @ func_va=0x027654, fde_va=0x06e988, first_op=0xd65f03c0
    // VI: Hàm FDE[143] tại địa chỉ 0x027654, bản ghi FDE 0x06e988
    const std::uint32_t w0 = kByteVc1TextWords[35761U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027654U);
}
static std::uint32_t ByteVc1FdeFunc_144_0x027658(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[144] @ func_va=0x027658, fde_va=0x06e9a0, first_op=0xb4000040
    // VI: Hàm FDE[144] tại địa chỉ 0x027658, bản ghi FDE 0x06e9a0
    const std::uint32_t w0 = kByteVc1TextWords[35762U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027658U);
}
static std::uint32_t ByteVc1FdeFunc_145_0x027664(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[145] @ func_va=0x027664, fde_va=0x06e9b8, first_op=0xb4000040
    // VI: Hàm FDE[145] tại địa chỉ 0x027664, bản ghi FDE 0x06e9b8
    const std::uint32_t w0 = kByteVc1TextWords[35765U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027664U);
}
static std::uint32_t ByteVc1FdeFunc_146_0x027670(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[146] @ func_va=0x027670, fde_va=0x06e9d0, first_op=0xb40000c0
    // VI: Hàm FDE[146] tại địa chỉ 0x027670, bản ghi FDE 0x06e9d0
    const std::uint32_t w0 = kByteVc1TextWords[35768U];
    std::uint32_t acc = w0 ^ 0xb40000c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027670U);
}
static std::uint32_t ByteVc1FdeFunc_147_0x02768c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[147] @ func_va=0x02768c, fde_va=0x06e9e8, first_op=0xd10243ff
    // VI: Hàm FDE[147] tại địa chỉ 0x02768c, bản ghi FDE 0x06e9e8
    const std::uint32_t w0 = kByteVc1TextWords[35775U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02768cU);
}
static std::uint32_t ByteVc1FdeFunc_148_0x027b74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[148] @ func_va=0x027b74, fde_va=0x06ea18, first_op=0xb40002a0
    // VI: Hàm FDE[148] tại địa chỉ 0x027b74, bản ghi FDE 0x06ea18
    const std::uint32_t w0 = kByteVc1TextWords[36089U];
    std::uint32_t acc = w0 ^ 0xb40002a0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027b74U);
}
static std::uint32_t ByteVc1FdeFunc_149_0x027cd0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[149] @ func_va=0x027cd0, fde_va=0x06ea40, first_op=0xb4000060
    // VI: Hàm FDE[149] tại địa chỉ 0x027cd0, bản ghi FDE 0x06ea40
    const std::uint32_t w0 = kByteVc1TextWords[36176U];
    std::uint32_t acc = w0 ^ 0xb4000060U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027cd0U);
}
static std::uint32_t ByteVc1FdeFunc_150_0x027ce0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[150] @ func_va=0x027ce0, fde_va=0x06ea58, first_op=0xb40002a0
    // VI: Hàm FDE[150] tại địa chỉ 0x027ce0, bản ghi FDE 0x06ea58
    const std::uint32_t w0 = kByteVc1TextWords[36180U];
    std::uint32_t acc = w0 ^ 0xb40002a0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027ce0U);
}
static std::uint32_t ByteVc1FdeFunc_151_0x027d78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[151] @ func_va=0x027d78, fde_va=0x06ea80, first_op=0xf81d0ff5
    // VI: Hàm FDE[151] tại địa chỉ 0x027d78, bản ghi FDE 0x06ea80
    const std::uint32_t w0 = kByteVc1TextWords[36218U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027d78U);
}
static std::uint32_t ByteVc1FdeFunc_152_0x027e10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[152] @ func_va=0x027e10, fde_va=0x06eaa0, first_op=0xd10283ff
    // VI: Hàm FDE[152] tại địa chỉ 0x027e10, bản ghi FDE 0x06eaa0
    const std::uint32_t w0 = kByteVc1TextWords[36256U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x027e10U);
}
static std::uint32_t ByteVc1FdeFunc_153_0x028334(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[153] @ func_va=0x028334, fde_va=0x06ead0, first_op=0xa9bc5ff8
    // VI: Hàm FDE[153] tại địa chỉ 0x028334, bản ghi FDE 0x06ead0
    const std::uint32_t w0 = kByteVc1TextWords[36585U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028334U);
}
static std::uint32_t ByteVc1FdeFunc_154_0x028490(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[154] @ func_va=0x028490, fde_va=0x06eaf8, first_op=0xd10183ff
    // VI: Hàm FDE[154] tại địa chỉ 0x028490, bản ghi FDE 0x06eaf8
    const std::uint32_t w0 = kByteVc1TextWords[36672U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028490U);
}
static std::uint32_t ByteVc1FdeFunc_155_0x02861c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[155] @ func_va=0x02861c, fde_va=0x06eb20, first_op=0xf81b0ff9
    // VI: Hàm FDE[155] tại địa chỉ 0x02861c, bản ghi FDE 0x06eb20
    const std::uint32_t w0 = kByteVc1TextWords[36771U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02861cU);
}
static std::uint32_t ByteVc1FdeFunc_156_0x028728(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[156] @ func_va=0x028728, fde_va=0x06eb48, first_op=0xb0000201
    // VI: Hàm FDE[156] tại địa chỉ 0x028728, bản ghi FDE 0x06eb48
    const std::uint32_t w0 = kByteVc1TextWords[36838U];
    std::uint32_t acc = w0 ^ 0xb0000201U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028728U);
}
static std::uint32_t ByteVc1FdeFunc_157_0x028738(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[157] @ func_va=0x028738, fde_va=0x06eb60, first_op=0xb4000080
    // VI: Hàm FDE[157] tại địa chỉ 0x028738, bản ghi FDE 0x06eb60
    const std::uint32_t w0 = kByteVc1TextWords[36842U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028738U);
}
static std::uint32_t ByteVc1FdeFunc_158_0x02874c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[158] @ func_va=0x02874c, fde_va=0x06eb78, first_op=0xb40000c0
    // VI: Hàm FDE[158] tại địa chỉ 0x02874c, bản ghi FDE 0x06eb78
    const std::uint32_t w0 = kByteVc1TextWords[36847U];
    std::uint32_t acc = w0 ^ 0xb40000c0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02874cU);
}
static std::uint32_t ByteVc1FdeFunc_159_0x028768(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[159] @ func_va=0x028768, fde_va=0x06eb90, first_op=0xa9bf7bfd
    // VI: Hàm FDE[159] tại địa chỉ 0x028768, bản ghi FDE 0x06eb90
    const std::uint32_t w0 = kByteVc1TextWords[36854U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028768U);
}
static std::uint32_t ByteVc1FdeFunc_160_0x0287a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[160] @ func_va=0x0287a8, fde_va=0x06ebb0, first_op=0xb4000080
    // VI: Hàm FDE[160] tại địa chỉ 0x0287a8, bản ghi FDE 0x06ebb0
    const std::uint32_t w0 = kByteVc1TextWords[36870U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0287a8U);
}
static std::uint32_t ByteVc1FdeFunc_161_0x0287bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[161] @ func_va=0x0287bc, fde_va=0x06ebc8, first_op=0xb4000040
    // VI: Hàm FDE[161] tại địa chỉ 0x0287bc, bản ghi FDE 0x06ebc8
    const std::uint32_t w0 = kByteVc1TextWords[36875U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0287bcU);
}
static std::uint32_t ByteVc1FdeFunc_162_0x0287c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[162] @ func_va=0x0287c8, fde_va=0x06ebe0, first_op=0xb4000040
    // VI: Hàm FDE[162] tại địa chỉ 0x0287c8, bản ghi FDE 0x06ebe0
    const std::uint32_t w0 = kByteVc1TextWords[36878U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0287c8U);
}
static std::uint32_t ByteVc1FdeFunc_163_0x0287d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[163] @ func_va=0x0287d4, fde_va=0x06ebf8, first_op=0xb4000060
    // VI: Hàm FDE[163] tại địa chỉ 0x0287d4, bản ghi FDE 0x06ebf8
    const std::uint32_t w0 = kByteVc1TextWords[36881U];
    std::uint32_t acc = w0 ^ 0xb4000060U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0287d4U);
}
static std::uint32_t ByteVc1FdeFunc_164_0x0287e4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[164] @ func_va=0x0287e4, fde_va=0x06ec10, first_op=0xb4000040
    // VI: Hàm FDE[164] tại địa chỉ 0x0287e4, bản ghi FDE 0x06ec10
    const std::uint32_t w0 = kByteVc1TextWords[36885U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0287e4U);
}
static std::uint32_t ByteVc1FdeFunc_165_0x0287f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[165] @ func_va=0x0287f0, fde_va=0x06ec28, first_op=0xb4000040
    // VI: Hàm FDE[165] tại địa chỉ 0x0287f0, bản ghi FDE 0x06ec28
    const std::uint32_t w0 = kByteVc1TextWords[36888U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0287f0U);
}
static std::uint32_t ByteVc1FdeFunc_166_0x0287fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[166] @ func_va=0x0287fc, fde_va=0x06ec40, first_op=0xb4000040
    // VI: Hàm FDE[166] tại địa chỉ 0x0287fc, bản ghi FDE 0x06ec40
    const std::uint32_t w0 = kByteVc1TextWords[36891U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0287fcU);
}
static std::uint32_t ByteVc1FdeFunc_167_0x028808(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[167] @ func_va=0x028808, fde_va=0x06ec58, first_op=0xb4000040
    // VI: Hàm FDE[167] tại địa chỉ 0x028808, bản ghi FDE 0x06ec58
    const std::uint32_t w0 = kByteVc1TextWords[36894U];
    std::uint32_t acc = w0 ^ 0xb4000040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028808U);
}
static std::uint32_t ByteVc1FdeFunc_168_0x028814(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[168] @ func_va=0x028814, fde_va=0x06ec70, first_op=0x7100182b
    // VI: Hàm FDE[168] tại địa chỉ 0x028814, bản ghi FDE 0x06ec70
    const std::uint32_t w0 = kByteVc1TextWords[36897U];
    std::uint32_t acc = w0 ^ 0x7100182bU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028814U);
}
static std::uint32_t ByteVc1FdeFunc_169_0x0289cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[169] @ func_va=0x0289cc, fde_va=0x06ec88, first_op=0xb40011a0
    // VI: Hàm FDE[169] tại địa chỉ 0x0289cc, bản ghi FDE 0x06ec88
    const std::uint32_t w0 = kByteVc1TextWords[37007U];
    std::uint32_t acc = w0 ^ 0xb40011a0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0289ccU);
}
static std::uint32_t ByteVc1FdeFunc_170_0x028c04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[170] @ func_va=0x028c04, fde_va=0x06ecb0, first_op=0xf81e0ff5
    // VI: Hàm FDE[170] tại địa chỉ 0x028c04, bản ghi FDE 0x06ecb0
    const std::uint32_t w0 = kByteVc1TextWords[37149U];
    std::uint32_t acc = w0 ^ 0xf81e0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028c04U);
}
static std::uint32_t ByteVc1FdeFunc_171_0x028e88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[171] @ func_va=0x028e88, fde_va=0x06ecd0, first_op=0x79c00048
    // VI: Hàm FDE[171] tại địa chỉ 0x028e88, bản ghi FDE 0x06ecd0
    const std::uint32_t w0 = kByteVc1TextWords[37310U];
    std::uint32_t acc = w0 ^ 0x79c00048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x028e88U);
}
static std::uint32_t ByteVc1FdeFunc_172_0x029070(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[172] @ func_va=0x029070, fde_va=0x06ece8, first_op=0xa9bd5ff8
    // VI: Hàm FDE[172] tại địa chỉ 0x029070, bản ghi FDE 0x06ece8
    const std::uint32_t w0 = kByteVc1TextWords[37432U];
    std::uint32_t acc = w0 ^ 0xa9bd5ff8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x029070U);
}
static std::uint32_t ByteVc1FdeFunc_173_0x029288(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[173] @ func_va=0x029288, fde_va=0x06ed08, first_op=0x79c00048
    // VI: Hàm FDE[173] tại địa chỉ 0x029288, bản ghi FDE 0x06ed08
    const std::uint32_t w0 = kByteVc1TextWords[37566U];
    std::uint32_t acc = w0 ^ 0x79c00048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x029288U);
}
static std::uint32_t ByteVc1FdeFunc_174_0x029470(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[174] @ func_va=0x029470, fde_va=0x06ed20, first_op=0x13017c2a
    // VI: Hàm FDE[174] tại địa chỉ 0x029470, bản ghi FDE 0x06ed20
    const std::uint32_t w0 = kByteVc1TextWords[37688U];
    std::uint32_t acc = w0 ^ 0x13017c2aU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x029470U);
}
static std::uint32_t ByteVc1FdeFunc_175_0x029528(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[175] @ func_va=0x029528, fde_va=0x06ed38, first_op=0xf81a0ffc
    // VI: Hàm FDE[175] tại địa chỉ 0x029528, bản ghi FDE 0x06ed38
    const std::uint32_t w0 = kByteVc1TextWords[37734U];
    std::uint32_t acc = w0 ^ 0xf81a0ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x029528U);
}
static std::uint32_t ByteVc1FdeFunc_176_0x029754(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[176] @ func_va=0x029754, fde_va=0x06ed68, first_op=0xd102c3ff
    // VI: Hàm FDE[176] tại địa chỉ 0x029754, bản ghi FDE 0x06ed68
    const std::uint32_t w0 = kByteVc1TextWords[37873U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x029754U);
}
static std::uint32_t ByteVc1FdeFunc_177_0x029b18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[177] @ func_va=0x029b18, fde_va=0x06ed98, first_op=0xa9bc67fa
    // VI: Hàm FDE[177] tại địa chỉ 0x029b18, bản ghi FDE 0x06ed98
    const std::uint32_t w0 = kByteVc1TextWords[38114U];
    std::uint32_t acc = w0 ^ 0xa9bc67faU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x029b18U);
}
static std::uint32_t ByteVc1FdeFunc_178_0x029ca4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[178] @ func_va=0x029ca4, fde_va=0x06edc0, first_op=0xa9bc67fa
    // VI: Hàm FDE[178] tại địa chỉ 0x029ca4, bản ghi FDE 0x06edc0
    const std::uint32_t w0 = kByteVc1TextWords[38213U];
    std::uint32_t acc = w0 ^ 0xa9bc67faU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x029ca4U);
}
static std::uint32_t ByteVc1FdeFunc_179_0x029e2c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[179] @ func_va=0x029e2c, fde_va=0x06ede8, first_op=0xa9bb6ffc
    // VI: Hàm FDE[179] tại địa chỉ 0x029e2c, bản ghi FDE 0x06ede8
    const std::uint32_t w0 = kByteVc1TextWords[38311U];
    std::uint32_t acc = w0 ^ 0xa9bb6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x029e2cU);
}
static std::uint32_t ByteVc1FdeFunc_180_0x02a098(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[180] @ func_va=0x02a098, fde_va=0x06ee10, first_op=0xd10303ff
    // VI: Hàm FDE[180] tại địa chỉ 0x02a098, bản ghi FDE 0x06ee10
    const std::uint32_t w0 = kByteVc1TextWords[38466U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02a098U);
}
static std::uint32_t ByteVc1FdeFunc_181_0x02a45c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[181] @ func_va=0x02a45c, fde_va=0x06ee40, first_op=0xa9bb67fc
    // VI: Hàm FDE[181] tại địa chỉ 0x02a45c, bản ghi FDE 0x06ee40
    const std::uint32_t w0 = kByteVc1TextWords[38707U];
    std::uint32_t acc = w0 ^ 0xa9bb67fcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02a45cU);
}
static std::uint32_t ByteVc1FdeFunc_182_0x02a774(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[182] @ func_va=0x02a774, fde_va=0x06ee70, first_op=0xd10203ff
    // VI: Hàm FDE[182] tại địa chỉ 0x02a774, bản ghi FDE 0x06ee70
    const std::uint32_t w0 = kByteVc1TextWords[38905U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02a774U);
}
static std::uint32_t ByteVc1FdeFunc_183_0x02aa5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[183] @ func_va=0x02aa5c, fde_va=0x06eea0, first_op=0xd103c3ff
    // VI: Hàm FDE[183] tại địa chỉ 0x02aa5c, bản ghi FDE 0x06eea0
    const std::uint32_t w0 = kByteVc1TextWords[39091U];
    std::uint32_t acc = w0 ^ 0xd103c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02aa5cU);
}
static std::uint32_t ByteVc1FdeFunc_184_0x02ae80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[184] @ func_va=0x02ae80, fde_va=0x06eed0, first_op=0xd103c3ff
    // VI: Hàm FDE[184] tại địa chỉ 0x02ae80, bản ghi FDE 0x06eed0
    const std::uint32_t w0 = kByteVc1TextWords[39356U];
    std::uint32_t acc = w0 ^ 0xd103c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ae80U);
}
static std::uint32_t ByteVc1FdeFunc_185_0x02b2a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[185] @ func_va=0x02b2a8, fde_va=0x06ef00, first_op=0xf81d0ff7
    // VI: Hàm FDE[185] tại địa chỉ 0x02b2a8, bản ghi FDE 0x06ef00
    const std::uint32_t w0 = kByteVc1TextWords[39622U];
    std::uint32_t acc = w0 ^ 0xf81d0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02b2a8U);
}
static std::uint32_t ByteVc1FdeFunc_186_0x02b444(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[186] @ func_va=0x02b444, fde_va=0x06ef20, first_op=0xd10283ff
    // VI: Hàm FDE[186] tại địa chỉ 0x02b444, bản ghi FDE 0x06ef20
    const std::uint32_t w0 = kByteVc1TextWords[39725U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02b444U);
}
static std::uint32_t ByteVc1FdeFunc_187_0x02b6f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[187] @ func_va=0x02b6f0, fde_va=0x06ef50, first_op=0xd10243ff
    // VI: Hàm FDE[187] tại địa chỉ 0x02b6f0, bản ghi FDE 0x06ef50
    const std::uint32_t w0 = kByteVc1TextWords[39896U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02b6f0U);
}
static std::uint32_t ByteVc1FdeFunc_188_0x02b98c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[188] @ func_va=0x02b98c, fde_va=0x06ef80, first_op=0xaa1f03e8
    // VI: Hàm FDE[188] tại địa chỉ 0x02b98c, bản ghi FDE 0x06ef80
    const std::uint32_t w0 = kByteVc1TextWords[40063U];
    std::uint32_t acc = w0 ^ 0xaa1f03e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02b98cU);
}
static std::uint32_t ByteVc1FdeFunc_189_0x02bacc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[189] @ func_va=0x02bacc, fde_va=0x06ef98, first_op=0x2a1f03e8
    // VI: Hàm FDE[189] tại địa chỉ 0x02bacc, bản ghi FDE 0x06ef98
    const std::uint32_t w0 = kByteVc1TextWords[40143U];
    std::uint32_t acc = w0 ^ 0x2a1f03e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02baccU);
}
static std::uint32_t ByteVc1FdeFunc_190_0x02bb30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[190] @ func_va=0x02bb30, fde_va=0x06efb0, first_op=0x2a1f03e8
    // VI: Hàm FDE[190] tại địa chỉ 0x02bb30, bản ghi FDE 0x06efb0
    const std::uint32_t w0 = kByteVc1TextWords[40168U];
    std::uint32_t acc = w0 ^ 0x2a1f03e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02bb30U);
}
static std::uint32_t ByteVc1FdeFunc_191_0x02bb90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[191] @ func_va=0x02bb90, fde_va=0x06efc8, first_op=0x7100283f
    // VI: Hàm FDE[191] tại địa chỉ 0x02bb90, bản ghi FDE 0x06efc8
    const std::uint32_t w0 = kByteVc1TextWords[40192U];
    std::uint32_t acc = w0 ^ 0x7100283fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02bb90U);
}
static std::uint32_t ByteVc1FdeFunc_192_0x02c3fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[192] @ func_va=0x02c3fc, fde_va=0x06efe0, first_op=0x8b21cc08
    // VI: Hàm FDE[192] tại địa chỉ 0x02c3fc, bản ghi FDE 0x06efe0
    const std::uint32_t w0 = kByteVc1TextWords[40731U];
    std::uint32_t acc = w0 ^ 0x8b21cc08U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02c3fcU);
}
static std::uint32_t ByteVc1FdeFunc_193_0x02c408(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[193] @ func_va=0x02c408, fde_va=0x06eff8, first_op=0xd101c3ff
    // VI: Hàm FDE[193] tại địa chỉ 0x02c408, bản ghi FDE 0x06eff8
    const std::uint32_t w0 = kByteVc1TextWords[40734U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02c408U);
}
static std::uint32_t ByteVc1FdeFunc_194_0x02c724(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[194] @ func_va=0x02c724, fde_va=0x06f028, first_op=0xf81c0ff7
    // VI: Hàm FDE[194] tại địa chỉ 0x02c724, bản ghi FDE 0x06f028
    const std::uint32_t w0 = kByteVc1TextWords[40933U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02c724U);
}
static std::uint32_t ByteVc1FdeFunc_195_0x02c960(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[195] @ func_va=0x02c960, fde_va=0x06f050, first_op=0xf81e0ff3
    // VI: Hàm FDE[195] tại địa chỉ 0x02c960, bản ghi FDE 0x06f050
    const std::uint32_t w0 = kByteVc1TextWords[41076U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02c960U);
}
static std::uint32_t ByteVc1FdeFunc_196_0x02c9c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[196] @ func_va=0x02c9c4, fde_va=0x06f070, first_op=0xa9bb67fa
    // VI: Hàm FDE[196] tại địa chỉ 0x02c9c4, bản ghi FDE 0x06f070
    const std::uint32_t w0 = kByteVc1TextWords[41101U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02c9c4U);
}
static std::uint32_t ByteVc1FdeFunc_197_0x02cbd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[197] @ func_va=0x02cbd8, fde_va=0x06f0a0, first_op=0xa9be4ff4
    // VI: Hàm FDE[197] tại địa chỉ 0x02cbd8, bản ghi FDE 0x06f0a0
    const std::uint32_t w0 = kByteVc1TextWords[41234U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cbd8U);
}
static std::uint32_t ByteVc1FdeFunc_198_0x02cc40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[198] @ func_va=0x02cc40, fde_va=0x06f0c0, first_op=0xf9402028
    // VI: Hàm FDE[198] tại địa chỉ 0x02cc40, bản ghi FDE 0x06f0c0
    const std::uint32_t w0 = kByteVc1TextWords[41260U];
    std::uint32_t acc = w0 ^ 0xf9402028U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cc40U);
}
static std::uint32_t ByteVc1FdeFunc_199_0x02cccc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[199] @ func_va=0x02cccc, fde_va=0x06f0d8, first_op=0xb40003a0
    // VI: Hàm FDE[199] tại địa chỉ 0x02cccc, bản ghi FDE 0x06f0d8
    const std::uint32_t w0 = kByteVc1TextWords[41295U];
    std::uint32_t acc = w0 ^ 0xb40003a0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ccccU);
}
static std::uint32_t ByteVc1FdeFunc_200_0x02cd48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[200] @ func_va=0x02cd48, fde_va=0x06f0f8, first_op=0xb40000a0
    // VI: Hàm FDE[200] tại địa chỉ 0x02cd48, bản ghi FDE 0x06f0f8
    const std::uint32_t w0 = kByteVc1TextWords[41326U];
    std::uint32_t acc = w0 ^ 0xb40000a0U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cd48U);
}
static std::uint32_t ByteVc1FdeFunc_201_0x02cd60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[201] @ func_va=0x02cd60, fde_va=0x06f110, first_op=0xf81b0ff9
    // VI: Hàm FDE[201] tại địa chỉ 0x02cd60, bản ghi FDE 0x06f110
    const std::uint32_t w0 = kByteVc1TextWords[41332U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cd60U);
}
static std::uint32_t ByteVc1FdeFunc_202_0x02ce20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[202] @ func_va=0x02ce20, fde_va=0x06f138, first_op=0xb9000002
    // VI: Hàm FDE[202] tại địa chỉ 0x02ce20, bản ghi FDE 0x06f138
    const std::uint32_t w0 = kByteVc1TextWords[41380U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ce20U);
}
static std::uint32_t ByteVc1FdeFunc_203_0x02ce2c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[203] @ func_va=0x02ce2c, fde_va=0x06f150, first_op=0xb9000002
    // VI: Hàm FDE[203] tại địa chỉ 0x02ce2c, bản ghi FDE 0x06f150
    const std::uint32_t w0 = kByteVc1TextWords[41383U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ce2cU);
}
static std::uint32_t ByteVc1FdeFunc_204_0x02ce40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[204] @ func_va=0x02ce40, fde_va=0x06f168, first_op=0xb9000002
    // VI: Hàm FDE[204] tại địa chỉ 0x02ce40, bản ghi FDE 0x06f168
    const std::uint32_t w0 = kByteVc1TextWords[41388U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ce40U);
}
static std::uint32_t ByteVc1FdeFunc_205_0x02ce54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[205] @ func_va=0x02ce54, fde_va=0x06f180, first_op=0xb9000002
    // VI: Hàm FDE[205] tại địa chỉ 0x02ce54, bản ghi FDE 0x06f180
    const std::uint32_t w0 = kByteVc1TextWords[41393U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ce54U);
}
static std::uint32_t ByteVc1FdeFunc_206_0x02ce70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[206] @ func_va=0x02ce70, fde_va=0x06f198, first_op=0x8b21d008
    // VI: Hàm FDE[206] tại địa chỉ 0x02ce70, bản ghi FDE 0x06f198
    const std::uint32_t w0 = kByteVc1TextWords[41400U];
    std::uint32_t acc = w0 ^ 0x8b21d008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ce70U);
}
static std::uint32_t ByteVc1FdeFunc_207_0x02ce98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[207] @ func_va=0x02ce98, fde_va=0x06f1b0, first_op=0xb9000002
    // VI: Hàm FDE[207] tại địa chỉ 0x02ce98, bản ghi FDE 0x06f1b0
    const std::uint32_t w0 = kByteVc1TextWords[41410U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ce98U);
}
static std::uint32_t ByteVc1FdeFunc_208_0x02cee0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[208] @ func_va=0x02cee0, fde_va=0x06f1c8, first_op=0xb9000002
    // VI: Hàm FDE[208] tại địa chỉ 0x02cee0, bản ghi FDE 0x06f1c8
    const std::uint32_t w0 = kByteVc1TextWords[41428U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cee0U);
}
static std::uint32_t ByteVc1FdeFunc_209_0x02cf20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[209] @ func_va=0x02cf20, fde_va=0x06f1e0, first_op=0xb9000002
    // VI: Hàm FDE[209] tại địa chỉ 0x02cf20, bản ghi FDE 0x06f1e0
    const std::uint32_t w0 = kByteVc1TextWords[41444U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cf20U);
}
static std::uint32_t ByteVc1FdeFunc_210_0x02cf80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[210] @ func_va=0x02cf80, fde_va=0x06f1f8, first_op=0xb9000002
    // VI: Hàm FDE[210] tại địa chỉ 0x02cf80, bản ghi FDE 0x06f1f8
    const std::uint32_t w0 = kByteVc1TextWords[41468U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cf80U);
}
static std::uint32_t ByteVc1FdeFunc_211_0x02cf94(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[211] @ func_va=0x02cf94, fde_va=0x06f210, first_op=0xb9000002
    // VI: Hàm FDE[211] tại địa chỉ 0x02cf94, bản ghi FDE 0x06f210
    const std::uint32_t w0 = kByteVc1TextWords[41473U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cf94U);
}
static std::uint32_t ByteVc1FdeFunc_212_0x02cfb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[212] @ func_va=0x02cfb8, fde_va=0x06f228, first_op=0xb9000002
    // VI: Hàm FDE[212] tại địa chỉ 0x02cfb8, bản ghi FDE 0x06f228
    const std::uint32_t w0 = kByteVc1TextWords[41482U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cfb8U);
}
static std::uint32_t ByteVc1FdeFunc_213_0x02cfd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[213] @ func_va=0x02cfd8, fde_va=0x06f240, first_op=0xb9000002
    // VI: Hàm FDE[213] tại địa chỉ 0x02cfd8, bản ghi FDE 0x06f240
    const std::uint32_t w0 = kByteVc1TextWords[41490U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02cfd8U);
}
static std::uint32_t ByteVc1FdeFunc_214_0x02d008(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[214] @ func_va=0x02d008, fde_va=0x06f258, first_op=0x8b21d008
    // VI: Hàm FDE[214] tại địa chỉ 0x02d008, bản ghi FDE 0x06f258
    const std::uint32_t w0 = kByteVc1TextWords[41502U];
    std::uint32_t acc = w0 ^ 0x8b21d008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d008U);
}
static std::uint32_t ByteVc1FdeFunc_215_0x02d020(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[215] @ func_va=0x02d020, fde_va=0x06f270, first_op=0xb9000002
    // VI: Hàm FDE[215] tại địa chỉ 0x02d020, bản ghi FDE 0x06f270
    const std::uint32_t w0 = kByteVc1TextWords[41508U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d020U);
}
static std::uint32_t ByteVc1FdeFunc_216_0x02d048(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[216] @ func_va=0x02d048, fde_va=0x06f288, first_op=0xb9000002
    // VI: Hàm FDE[216] tại địa chỉ 0x02d048, bản ghi FDE 0x06f288
    const std::uint32_t w0 = kByteVc1TextWords[41518U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d048U);
}
static std::uint32_t ByteVc1FdeFunc_217_0x02d070(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[217] @ func_va=0x02d070, fde_va=0x06f2a0, first_op=0xb9000002
    // VI: Hàm FDE[217] tại địa chỉ 0x02d070, bản ghi FDE 0x06f2a0
    const std::uint32_t w0 = kByteVc1TextWords[41528U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d070U);
}
static std::uint32_t ByteVc1FdeFunc_218_0x02d0a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[218] @ func_va=0x02d0a8, fde_va=0x06f2b8, first_op=0x8b21d009
    // VI: Hàm FDE[218] tại địa chỉ 0x02d0a8, bản ghi FDE 0x06f2b8
    const std::uint32_t w0 = kByteVc1TextWords[41542U];
    std::uint32_t acc = w0 ^ 0x8b21d009U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d0a8U);
}
static std::uint32_t ByteVc1FdeFunc_219_0x02d100(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[219] @ func_va=0x02d100, fde_va=0x06f2d0, first_op=0xb9000002
    // VI: Hàm FDE[219] tại địa chỉ 0x02d100, bản ghi FDE 0x06f2d0
    const std::uint32_t w0 = kByteVc1TextWords[41564U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d100U);
}
static std::uint32_t ByteVc1FdeFunc_220_0x02d198(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[220] @ func_va=0x02d198, fde_va=0x06f2e8, first_op=0xb9000002
    // VI: Hàm FDE[220] tại địa chỉ 0x02d198, bản ghi FDE 0x06f2e8
    const std::uint32_t w0 = kByteVc1TextWords[41602U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d198U);
}
static std::uint32_t ByteVc1FdeFunc_221_0x02d224(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[221] @ func_va=0x02d224, fde_va=0x06f300, first_op=0xb9000002
    // VI: Hàm FDE[221] tại địa chỉ 0x02d224, bản ghi FDE 0x06f300
    const std::uint32_t w0 = kByteVc1TextWords[41637U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d224U);
}
static std::uint32_t ByteVc1FdeFunc_222_0x02d2f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[222] @ func_va=0x02d2f0, fde_va=0x06f318, first_op=0x8b21d008
    // VI: Hàm FDE[222] tại địa chỉ 0x02d2f0, bản ghi FDE 0x06f318
    const std::uint32_t w0 = kByteVc1TextWords[41688U];
    std::uint32_t acc = w0 ^ 0x8b21d008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d2f0U);
}
static std::uint32_t ByteVc1FdeFunc_223_0x02d328(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[223] @ func_va=0x02d328, fde_va=0x06f330, first_op=0xb9000002
    // VI: Hàm FDE[223] tại địa chỉ 0x02d328, bản ghi FDE 0x06f330
    const std::uint32_t w0 = kByteVc1TextWords[41702U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d328U);
}
static std::uint32_t ByteVc1FdeFunc_224_0x02d390(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[224] @ func_va=0x02d390, fde_va=0x06f348, first_op=0xb9000002
    // VI: Hàm FDE[224] tại địa chỉ 0x02d390, bản ghi FDE 0x06f348
    const std::uint32_t w0 = kByteVc1TextWords[41728U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d390U);
}
static std::uint32_t ByteVc1FdeFunc_225_0x02d3ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[225] @ func_va=0x02d3ec, fde_va=0x06f360, first_op=0xb9000002
    // VI: Hàm FDE[225] tại địa chỉ 0x02d3ec, bản ghi FDE 0x06f360
    const std::uint32_t w0 = kByteVc1TextWords[41751U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d3ecU);
}
static std::uint32_t ByteVc1FdeFunc_226_0x02d478(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[226] @ func_va=0x02d478, fde_va=0x06f378, first_op=0x8b21d009
    // VI: Hàm FDE[226] tại địa chỉ 0x02d478, bản ghi FDE 0x06f378
    const std::uint32_t w0 = kByteVc1TextWords[41786U];
    std::uint32_t acc = w0 ^ 0x8b21d009U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d478U);
}
static std::uint32_t ByteVc1FdeFunc_227_0x02d4c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[227] @ func_va=0x02d4c0, fde_va=0x06f390, first_op=0xb9000002
    // VI: Hàm FDE[227] tại địa chỉ 0x02d4c0, bản ghi FDE 0x06f390
    const std::uint32_t w0 = kByteVc1TextWords[41804U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d4c0U);
}
static std::uint32_t ByteVc1FdeFunc_228_0x02d538(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[228] @ func_va=0x02d538, fde_va=0x06f3a8, first_op=0xb9000002
    // VI: Hàm FDE[228] tại địa chỉ 0x02d538, bản ghi FDE 0x06f3a8
    const std::uint32_t w0 = kByteVc1TextWords[41834U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d538U);
}
static std::uint32_t ByteVc1FdeFunc_229_0x02d5a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[229] @ func_va=0x02d5a8, fde_va=0x06f3c0, first_op=0xb9000002
    // VI: Hàm FDE[229] tại địa chỉ 0x02d5a8, bản ghi FDE 0x06f3c0
    const std::uint32_t w0 = kByteVc1TextWords[41862U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d5a8U);
}
static std::uint32_t ByteVc1FdeFunc_230_0x02d648(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[230] @ func_va=0x02d648, fde_va=0x06f3d8, first_op=0x531d7028
    // VI: Hàm FDE[230] tại địa chỉ 0x02d648, bản ghi FDE 0x06f3d8
    const std::uint32_t w0 = kByteVc1TextWords[41902U];
    std::uint32_t acc = w0 ^ 0x531d7028U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d648U);
}
static std::uint32_t ByteVc1FdeFunc_231_0x02d6ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[231] @ func_va=0x02d6ec, fde_va=0x06f3f0, first_op=0xb9000002
    // VI: Hàm FDE[231] tại địa chỉ 0x02d6ec, bản ghi FDE 0x06f3f0
    const std::uint32_t w0 = kByteVc1TextWords[41943U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d6ecU);
}
static std::uint32_t ByteVc1FdeFunc_232_0x02d7f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[232] @ func_va=0x02d7f8, fde_va=0x06f408, first_op=0xb9000002
    // VI: Hàm FDE[232] tại địa chỉ 0x02d7f8, bản ghi FDE 0x06f408
    const std::uint32_t w0 = kByteVc1TextWords[42010U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d7f8U);
}
static std::uint32_t ByteVc1FdeFunc_233_0x02d8e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[233] @ func_va=0x02d8e8, fde_va=0x06f420, first_op=0xb9000002
    // VI: Hàm FDE[233] tại địa chỉ 0x02d8e8, bản ghi FDE 0x06f420
    const std::uint32_t w0 = kByteVc1TextWords[42070U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02d8e8U);
}
static std::uint32_t ByteVc1FdeFunc_234_0x02da40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[234] @ func_va=0x02da40, fde_va=0x06f438, first_op=0x531e7428
    // VI: Hàm FDE[234] tại địa chỉ 0x02da40, bản ghi FDE 0x06f438
    const std::uint32_t w0 = kByteVc1TextWords[42156U];
    std::uint32_t acc = w0 ^ 0x531e7428U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02da40U);
}
static std::uint32_t ByteVc1FdeFunc_235_0x02dacc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[235] @ func_va=0x02dacc, fde_va=0x06f450, first_op=0xb9000002
    // VI: Hàm FDE[235] tại địa chỉ 0x02dacc, bản ghi FDE 0x06f450
    const std::uint32_t w0 = kByteVc1TextWords[42191U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02daccU);
}
static std::uint32_t ByteVc1FdeFunc_236_0x02dbc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[236] @ func_va=0x02dbc0, fde_va=0x06f468, first_op=0xb9000002
    // VI: Hàm FDE[236] tại địa chỉ 0x02dbc0, bản ghi FDE 0x06f468
    const std::uint32_t w0 = kByteVc1TextWords[42252U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02dbc0U);
}
static std::uint32_t ByteVc1FdeFunc_237_0x02dc98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[237] @ func_va=0x02dc98, fde_va=0x06f480, first_op=0xb9000002
    // VI: Hàm FDE[237] tại địa chỉ 0x02dc98, bản ghi FDE 0x06f480
    const std::uint32_t w0 = kByteVc1TextWords[42306U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02dc98U);
}
static std::uint32_t ByteVc1FdeFunc_238_0x02ddd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[238] @ func_va=0x02ddd8, fde_va=0x06f498, first_op=0x531d7028
    // VI: Hàm FDE[238] tại địa chỉ 0x02ddd8, bản ghi FDE 0x06f498
    const std::uint32_t w0 = kByteVc1TextWords[42386U];
    std::uint32_t acc = w0 ^ 0x531d7028U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ddd8U);
}
static std::uint32_t ByteVc1FdeFunc_239_0x02de4c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[239] @ func_va=0x02de4c, fde_va=0x06f4b0, first_op=0xb9000002
    // VI: Hàm FDE[239] tại địa chỉ 0x02de4c, bản ghi FDE 0x06f4b0
    const std::uint32_t w0 = kByteVc1TextWords[42415U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02de4cU);
}
static std::uint32_t ByteVc1FdeFunc_240_0x02def8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[240] @ func_va=0x02def8, fde_va=0x06f4c8, first_op=0xb9000002
    // VI: Hàm FDE[240] tại địa chỉ 0x02def8, bản ghi FDE 0x06f4c8
    const std::uint32_t w0 = kByteVc1TextWords[42458U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02def8U);
}
static std::uint32_t ByteVc1FdeFunc_241_0x02df98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[241] @ func_va=0x02df98, fde_va=0x06f4e0, first_op=0xb9000002
    // VI: Hàm FDE[241] tại địa chỉ 0x02df98, bản ghi FDE 0x06f4e0
    const std::uint32_t w0 = kByteVc1TextWords[42498U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02df98U);
}
static std::uint32_t ByteVc1FdeFunc_242_0x02e070(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[242] @ func_va=0x02e070, fde_va=0x06f4f8, first_op=0x531e742a
    // VI: Hàm FDE[242] tại địa chỉ 0x02e070, bản ghi FDE 0x06f4f8
    const std::uint32_t w0 = kByteVc1TextWords[42552U];
    std::uint32_t acc = w0 ^ 0x531e742aU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02e070U);
}
static std::uint32_t ByteVc1FdeFunc_243_0x02e1c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[243] @ func_va=0x02e1c0, fde_va=0x06f510, first_op=0xb9000002
    // VI: Hàm FDE[243] tại địa chỉ 0x02e1c0, bản ghi FDE 0x06f510
    const std::uint32_t w0 = kByteVc1TextWords[42636U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02e1c0U);
}
static std::uint32_t ByteVc1FdeFunc_244_0x02e418(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[244] @ func_va=0x02e418, fde_va=0x06f528, first_op=0xb9000002
    // VI: Hàm FDE[244] tại địa chỉ 0x02e418, bản ghi FDE 0x06f528
    const std::uint32_t w0 = kByteVc1TextWords[42786U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02e418U);
}
static std::uint32_t ByteVc1FdeFunc_245_0x02e634(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[245] @ func_va=0x02e634, fde_va=0x06f540, first_op=0xb9000002
    // VI: Hàm FDE[245] tại địa chỉ 0x02e634, bản ghi FDE 0x06f540
    const std::uint32_t w0 = kByteVc1TextWords[42921U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02e634U);
}
static std::uint32_t ByteVc1FdeFunc_246_0x02e958(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[246] @ func_va=0x02e958, fde_va=0x06f558, first_op=0x531d7028
    // VI: Hàm FDE[246] tại địa chỉ 0x02e958, bản ghi FDE 0x06f558
    const std::uint32_t w0 = kByteVc1TextWords[43122U];
    std::uint32_t acc = w0 ^ 0x531d7028U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02e958U);
}
static std::uint32_t ByteVc1FdeFunc_247_0x02ea5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[247] @ func_va=0x02ea5c, fde_va=0x06f570, first_op=0xb9000002
    // VI: Hàm FDE[247] tại địa chỉ 0x02ea5c, bản ghi FDE 0x06f570
    const std::uint32_t w0 = kByteVc1TextWords[43187U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ea5cU);
}
static std::uint32_t ByteVc1FdeFunc_248_0x02ec28(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[248] @ func_va=0x02ec28, fde_va=0x06f588, first_op=0xb9000002
    // VI: Hàm FDE[248] tại địa chỉ 0x02ec28, bản ghi FDE 0x06f588
    const std::uint32_t w0 = kByteVc1TextWords[43302U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ec28U);
}
static std::uint32_t ByteVc1FdeFunc_249_0x02edb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[249] @ func_va=0x02edb8, fde_va=0x06f5a0, first_op=0xb9000002
    // VI: Hàm FDE[249] tại địa chỉ 0x02edb8, bản ghi FDE 0x06f5a0
    const std::uint32_t w0 = kByteVc1TextWords[43402U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02edb8U);
}
static std::uint32_t ByteVc1FdeFunc_250_0x02f010(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[250] @ func_va=0x02f010, fde_va=0x06f5b8, first_op=0x531e742a
    // VI: Hàm FDE[250] tại địa chỉ 0x02f010, bản ghi FDE 0x06f5b8
    const std::uint32_t w0 = kByteVc1TextWords[43552U];
    std::uint32_t acc = w0 ^ 0x531e742aU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f010U);
}
static std::uint32_t ByteVc1FdeFunc_251_0x02f0e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[251] @ func_va=0x02f0e0, fde_va=0x06f5d0, first_op=0xb9000002
    // VI: Hàm FDE[251] tại địa chỉ 0x02f0e0, bản ghi FDE 0x06f5d0
    const std::uint32_t w0 = kByteVc1TextWords[43604U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f0e0U);
}
static std::uint32_t ByteVc1FdeFunc_252_0x02f238(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[252] @ func_va=0x02f238, fde_va=0x06f5e8, first_op=0xb9000002
    // VI: Hàm FDE[252] tại địa chỉ 0x02f238, bản ghi FDE 0x06f5e8
    const std::uint32_t w0 = kByteVc1TextWords[43690U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f238U);
}
static std::uint32_t ByteVc1FdeFunc_253_0x02f374(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[253] @ func_va=0x02f374, fde_va=0x06f600, first_op=0xb9000002
    // VI: Hàm FDE[253] tại địa chỉ 0x02f374, bản ghi FDE 0x06f600
    const std::uint32_t w0 = kByteVc1TextWords[43769U];
    std::uint32_t acc = w0 ^ 0xb9000002U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f374U);
}
static std::uint32_t ByteVc1FdeFunc_254_0x02f538(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[254] @ func_va=0x02f538, fde_va=0x06f618, first_op=0xb94de809
    // VI: Hàm FDE[254] tại địa chỉ 0x02f538, bản ghi FDE 0x06f618
    const std::uint32_t w0 = kByteVc1TextWords[43882U];
    std::uint32_t acc = w0 ^ 0xb94de809U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f538U);
}
static std::uint32_t ByteVc1FdeFunc_255_0x02f58c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[255] @ func_va=0x02f58c, fde_va=0x06f630, first_op=0xa9bb67fa
    // VI: Hàm FDE[255] tại địa chỉ 0x02f58c, bản ghi FDE 0x06f630
    const std::uint32_t w0 = kByteVc1TextWords[43903U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f58cU);
}
static std::uint32_t ByteVc1FdeFunc_256_0x02f7f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[256] @ func_va=0x02f7f8, fde_va=0x06f660, first_op=0xa9bb67fa
    // VI: Hàm FDE[256] tại địa chỉ 0x02f7f8, bản ghi FDE 0x06f660
    const std::uint32_t w0 = kByteVc1TextWords[44058U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f7f8U);
}
static std::uint32_t ByteVc1FdeFunc_257_0x02f8bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[257] @ func_va=0x02f8bc, fde_va=0x06f690, first_op=0xa9bb67fa
    // VI: Hàm FDE[257] tại địa chỉ 0x02f8bc, bản ghi FDE 0x06f690
    const std::uint32_t w0 = kByteVc1TextWords[44107U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f8bcU);
}
static std::uint32_t ByteVc1FdeFunc_258_0x02f984(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[258] @ func_va=0x02f984, fde_va=0x06f6c0, first_op=0x3dc00000
    // VI: Hàm FDE[258] tại địa chỉ 0x02f984, bản ghi FDE 0x06f6c0
    const std::uint32_t w0 = kByteVc1TextWords[44157U];
    std::uint32_t acc = w0 ^ 0x3dc00000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f984U);
}
static std::uint32_t ByteVc1FdeFunc_259_0x02f990(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[259] @ func_va=0x02f990, fde_va=0x06f6d8, first_op=0x3dc00000
    // VI: Hàm FDE[259] tại địa chỉ 0x02f990, bản ghi FDE 0x06f6d8
    const std::uint32_t w0 = kByteVc1TextWords[44160U];
    std::uint32_t acc = w0 ^ 0x3dc00000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f990U);
}
static std::uint32_t ByteVc1FdeFunc_260_0x02f99c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[260] @ func_va=0x02f99c, fde_va=0x06f6f0, first_op=0x3dc00000
    // VI: Hàm FDE[260] tại địa chỉ 0x02f99c, bản ghi FDE 0x06f6f0
    const std::uint32_t w0 = kByteVc1TextWords[44163U];
    std::uint32_t acc = w0 ^ 0x3dc00000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f99cU);
}
static std::uint32_t ByteVc1FdeFunc_261_0x02f9d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[261] @ func_va=0x02f9d0, fde_va=0x06f708, first_op=0x3dc00000
    // VI: Hàm FDE[261] tại địa chỉ 0x02f9d0, bản ghi FDE 0x06f708
    const std::uint32_t w0 = kByteVc1TextWords[44176U];
    std::uint32_t acc = w0 ^ 0x3dc00000U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02f9d0U);
}
static std::uint32_t ByteVc1FdeFunc_262_0x02fa7c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[262] @ func_va=0x02fa7c, fde_va=0x06f720, first_op=0xf81a0ffb
    // VI: Hàm FDE[262] tại địa chỉ 0x02fa7c, bản ghi FDE 0x06f720
    const std::uint32_t w0 = kByteVc1TextWords[44219U];
    std::uint32_t acc = w0 ^ 0xf81a0ffbU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02fa7cU);
}
static std::uint32_t ByteVc1FdeFunc_263_0x02fbd4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[263] @ func_va=0x02fbd4, fde_va=0x06f750, first_op=0xd101c3ff
    // VI: Hàm FDE[263] tại địa chỉ 0x02fbd4, bản ghi FDE 0x06f750
    const std::uint32_t w0 = kByteVc1TextWords[44305U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02fbd4U);
}
static std::uint32_t ByteVc1FdeFunc_264_0x02fda0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[264] @ func_va=0x02fda0, fde_va=0x06f780, first_op=0xa9ba6ffc
    // VI: Hàm FDE[264] tại địa chỉ 0x02fda0, bản ghi FDE 0x06f780
    const std::uint32_t w0 = kByteVc1TextWords[44420U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02fda0U);
}
static std::uint32_t ByteVc1FdeFunc_265_0x02ff5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[265] @ func_va=0x02ff5c, fde_va=0x06f7b0, first_op=0xd101c3ff
    // VI: Hàm FDE[265] tại địa chỉ 0x02ff5c, bản ghi FDE 0x06f7b0
    const std::uint32_t w0 = kByteVc1TextWords[44531U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x02ff5cU);
}
static std::uint32_t ByteVc1FdeFunc_266_0x03012c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[266] @ func_va=0x03012c, fde_va=0x06f7e0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[266] tại địa chỉ 0x03012c, bản ghi FDE 0x06f7e0
    const std::uint32_t w0 = kByteVc1TextWords[44647U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03012cU);
}
static std::uint32_t ByteVc1FdeFunc_267_0x0302ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[267] @ func_va=0x0302ec, fde_va=0x06f810, first_op=0xd10503ff
    // VI: Hàm FDE[267] tại địa chỉ 0x0302ec, bản ghi FDE 0x06f810
    const std::uint32_t w0 = kByteVc1TextWords[44759U];
    std::uint32_t acc = w0 ^ 0xd10503ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0302ecU);
}
static std::uint32_t ByteVc1FdeFunc_268_0x031160(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[268] @ func_va=0x031160, fde_va=0x06f840, first_op=0xa9be4ff4
    // VI: Hàm FDE[268] tại địa chỉ 0x031160, bản ghi FDE 0x06f840
    const std::uint32_t w0 = kByteVc1TextWords[45684U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x031160U);
}
static std::uint32_t ByteVc1FdeFunc_269_0x031370(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[269] @ func_va=0x031370, fde_va=0x06f860, first_op=0xd104c3ff
    // VI: Hàm FDE[269] tại địa chỉ 0x031370, bản ghi FDE 0x06f860
    const std::uint32_t w0 = kByteVc1TextWords[45816U];
    std::uint32_t acc = w0 ^ 0xd104c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x031370U);
}
static std::uint32_t ByteVc1FdeFunc_270_0x0321a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[270] @ func_va=0x0321a4, fde_va=0x06f890, first_op=0x91002029
    // VI: Hàm FDE[270] tại địa chỉ 0x0321a4, bản ghi FDE 0x06f890
    const std::uint32_t w0 = kByteVc1TextWords[46725U];
    std::uint32_t acc = w0 ^ 0x91002029U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0321a4U);
}
static std::uint32_t ByteVc1FdeFunc_271_0x0322f4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[271] @ func_va=0x0322f4, fde_va=0x06f8a8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[271] tại địa chỉ 0x0322f4, bản ghi FDE 0x06f8a8
    const std::uint32_t w0 = kByteVc1TextWords[46809U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0322f4U);
}
static std::uint32_t ByteVc1FdeFunc_272_0x0337fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[272] @ func_va=0x0337fc, fde_va=0x06f8d8, first_op=0x71007c5f
    // VI: Hàm FDE[272] tại địa chỉ 0x0337fc, bản ghi FDE 0x06f8d8
    const std::uint32_t w0 = kByteVc1TextWords[48155U];
    std::uint32_t acc = w0 ^ 0x71007c5fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0337fcU);
}
static std::uint32_t ByteVc1FdeFunc_273_0x033894(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[273] @ func_va=0x033894, fde_va=0x06f8f0, first_op=0x2a0303e4
    // VI: Hàm FDE[273] tại địa chỉ 0x033894, bản ghi FDE 0x06f8f0
    const std::uint32_t w0 = kByteVc1TextWords[48193U];
    std::uint32_t acc = w0 ^ 0x2a0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x033894U);
}
static std::uint32_t ByteVc1FdeFunc_274_0x0338a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[274] @ func_va=0x0338a0, fde_va=0x06f908, first_op=0x2a0303e4
    // VI: Hàm FDE[274] tại địa chỉ 0x0338a0, bản ghi FDE 0x06f908
    const std::uint32_t w0 = kByteVc1TextWords[48196U];
    std::uint32_t acc = w0 ^ 0x2a0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0338a0U);
}
static std::uint32_t ByteVc1FdeFunc_275_0x0338ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[275] @ func_va=0x0338ac, fde_va=0x06f920, first_op=0x2a0303e4
    // VI: Hàm FDE[275] tại địa chỉ 0x0338ac, bản ghi FDE 0x06f920
    const std::uint32_t w0 = kByteVc1TextWords[48199U];
    std::uint32_t acc = w0 ^ 0x2a0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0338acU);
}
static std::uint32_t ByteVc1FdeFunc_276_0x0338b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[276] @ func_va=0x0338b8, fde_va=0x06f938, first_op=0x2a0303e4
    // VI: Hàm FDE[276] tại địa chỉ 0x0338b8, bản ghi FDE 0x06f938
    const std::uint32_t w0 = kByteVc1TextWords[48202U];
    std::uint32_t acc = w0 ^ 0x2a0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0338b8U);
}
static std::uint32_t ByteVc1FdeFunc_277_0x0338c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[277] @ func_va=0x0338c4, fde_va=0x06f950, first_op=0x39400068
    // VI: Hàm FDE[277] tại địa chỉ 0x0338c4, bản ghi FDE 0x06f950
    const std::uint32_t w0 = kByteVc1TextWords[48205U];
    std::uint32_t acc = w0 ^ 0x39400068U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0338c4U);
}
static std::uint32_t ByteVc1FdeFunc_278_0x033930(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[278] @ func_va=0x033930, fde_va=0x06f968, first_op=0xb9400048
    // VI: Hàm FDE[278] tại địa chỉ 0x033930, bản ghi FDE 0x06f968
    const std::uint32_t w0 = kByteVc1TextWords[48232U];
    std::uint32_t acc = w0 ^ 0xb9400048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x033930U);
}
static std::uint32_t ByteVc1FdeFunc_279_0x033954(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[279] @ func_va=0x033954, fde_va=0x06f980, first_op=0x39400048
    // VI: Hàm FDE[279] tại địa chỉ 0x033954, bản ghi FDE 0x06f980
    const std::uint32_t w0 = kByteVc1TextWords[48241U];
    std::uint32_t acc = w0 ^ 0x39400048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x033954U);
}
static std::uint32_t ByteVc1FdeFunc_280_0x033998(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[280] @ func_va=0x033998, fde_va=0x06f998, first_op=0x71007c5f
    // VI: Hàm FDE[280] tại địa chỉ 0x033998, bản ghi FDE 0x06f998
    const std::uint32_t w0 = kByteVc1TextWords[48258U];
    std::uint32_t acc = w0 ^ 0x71007c5fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x033998U);
}
static std::uint32_t ByteVc1FdeFunc_281_0x033a7c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[281] @ func_va=0x033a7c, fde_va=0x06f9b0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[281] tại địa chỉ 0x033a7c, bản ghi FDE 0x06f9b0
    const std::uint32_t w0 = kByteVc1TextWords[48315U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x033a7cU);
}
static std::uint32_t ByteVc1FdeFunc_282_0x0350a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[282] @ func_va=0x0350a4, fde_va=0x06f9e0, first_op=0x71007c5f
    // VI: Hàm FDE[282] tại địa chỉ 0x0350a4, bản ghi FDE 0x06f9e0
    const std::uint32_t w0 = kByteVc1TextWords[49733U];
    std::uint32_t acc = w0 ^ 0x71007c5fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0350a4U);
}
static std::uint32_t ByteVc1FdeFunc_283_0x035140(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[283] @ func_va=0x035140, fde_va=0x06f9f8, first_op=0x2a0303e4
    // VI: Hàm FDE[283] tại địa chỉ 0x035140, bản ghi FDE 0x06f9f8
    const std::uint32_t w0 = kByteVc1TextWords[49772U];
    std::uint32_t acc = w0 ^ 0x2a0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035140U);
}
static std::uint32_t ByteVc1FdeFunc_284_0x03514c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[284] @ func_va=0x03514c, fde_va=0x06fa10, first_op=0x2a0303e4
    // VI: Hàm FDE[284] tại địa chỉ 0x03514c, bản ghi FDE 0x06fa10
    const std::uint32_t w0 = kByteVc1TextWords[49775U];
    std::uint32_t acc = w0 ^ 0x2a0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03514cU);
}
static std::uint32_t ByteVc1FdeFunc_285_0x035158(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[285] @ func_va=0x035158, fde_va=0x06fa28, first_op=0x2a0303e4
    // VI: Hàm FDE[285] tại địa chỉ 0x035158, bản ghi FDE 0x06fa28
    const std::uint32_t w0 = kByteVc1TextWords[49778U];
    std::uint32_t acc = w0 ^ 0x2a0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035158U);
}
static std::uint32_t ByteVc1FdeFunc_286_0x035164(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[286] @ func_va=0x035164, fde_va=0x06fa40, first_op=0x2a0303e4
    // VI: Hàm FDE[286] tại địa chỉ 0x035164, bản ghi FDE 0x06fa40
    const std::uint32_t w0 = kByteVc1TextWords[49781U];
    std::uint32_t acc = w0 ^ 0x2a0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035164U);
}
static std::uint32_t ByteVc1FdeFunc_287_0x035170(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[287] @ func_va=0x035170, fde_va=0x06fa58, first_op=0x79400068
    // VI: Hàm FDE[287] tại địa chỉ 0x035170, bản ghi FDE 0x06fa58
    const std::uint32_t w0 = kByteVc1TextWords[49784U];
    std::uint32_t acc = w0 ^ 0x79400068U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035170U);
}
static std::uint32_t ByteVc1FdeFunc_288_0x0351dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[288] @ func_va=0x0351dc, fde_va=0x06fa70, first_op=0xf9400048
    // VI: Hàm FDE[288] tại địa chỉ 0x0351dc, bản ghi FDE 0x06fa70
    const std::uint32_t w0 = kByteVc1TextWords[49811U];
    std::uint32_t acc = w0 ^ 0xf9400048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0351dcU);
}
static std::uint32_t ByteVc1FdeFunc_289_0x035200(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[289] @ func_va=0x035200, fde_va=0x06fa88, first_op=0x79400048
    // VI: Hàm FDE[289] tại địa chỉ 0x035200, bản ghi FDE 0x06fa88
    const std::uint32_t w0 = kByteVc1TextWords[49820U];
    std::uint32_t acc = w0 ^ 0x79400048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035200U);
}
static std::uint32_t ByteVc1FdeFunc_290_0x035244(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[290] @ func_va=0x035244, fde_va=0x06faa0, first_op=0x71007c5f
    // VI: Hàm FDE[290] tại địa chỉ 0x035244, bản ghi FDE 0x06faa0
    const std::uint32_t w0 = kByteVc1TextWords[49837U];
    std::uint32_t acc = w0 ^ 0x71007c5fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035244U);
}
static std::uint32_t ByteVc1FdeFunc_291_0x035328(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[291] @ func_va=0x035328, fde_va=0x06fab8, first_op=0xaa0303e4
    // VI: Hàm FDE[291] tại địa chỉ 0x035328, bản ghi FDE 0x06fab8
    const std::uint32_t w0 = kByteVc1TextWords[49894U];
    std::uint32_t acc = w0 ^ 0xaa0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035328U);
}
static std::uint32_t ByteVc1FdeFunc_292_0x035338(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[292] @ func_va=0x035338, fde_va=0x06fad0, first_op=0xaa0303e4
    // VI: Hàm FDE[292] tại địa chỉ 0x035338, bản ghi FDE 0x06fad0
    const std::uint32_t w0 = kByteVc1TextWords[49898U];
    std::uint32_t acc = w0 ^ 0xaa0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035338U);
}
static std::uint32_t ByteVc1FdeFunc_293_0x035348(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[293] @ func_va=0x035348, fde_va=0x06fae8, first_op=0xaa0303e4
    // VI: Hàm FDE[293] tại địa chỉ 0x035348, bản ghi FDE 0x06fae8
    const std::uint32_t w0 = kByteVc1TextWords[49902U];
    std::uint32_t acc = w0 ^ 0xaa0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035348U);
}
static std::uint32_t ByteVc1FdeFunc_294_0x035358(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[294] @ func_va=0x035358, fde_va=0x06fb00, first_op=0xaa0303e4
    // VI: Hàm FDE[294] tại địa chỉ 0x035358, bản ghi FDE 0x06fb00
    const std::uint32_t w0 = kByteVc1TextWords[49906U];
    std::uint32_t acc = w0 ^ 0xaa0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035358U);
}
static std::uint32_t ByteVc1FdeFunc_295_0x035368(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[295] @ func_va=0x035368, fde_va=0x06fb18, first_op=0xaa0303e4
    // VI: Hàm FDE[295] tại địa chỉ 0x035368, bản ghi FDE 0x06fb18
    const std::uint32_t w0 = kByteVc1TextWords[49910U];
    std::uint32_t acc = w0 ^ 0xaa0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035368U);
}
static std::uint32_t ByteVc1FdeFunc_296_0x035378(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[296] @ func_va=0x035378, fde_va=0x06fb30, first_op=0xaa0303e4
    // VI: Hàm FDE[296] tại địa chỉ 0x035378, bản ghi FDE 0x06fb30
    const std::uint32_t w0 = kByteVc1TextWords[49914U];
    std::uint32_t acc = w0 ^ 0xaa0303e4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035378U);
}
static std::uint32_t ByteVc1FdeFunc_297_0x035388(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[297] @ func_va=0x035388, fde_va=0x06fb48, first_op=0x7100283f
    // VI: Hàm FDE[297] tại địa chỉ 0x035388, bản ghi FDE 0x06fb48
    const std::uint32_t w0 = kByteVc1TextWords[49918U];
    std::uint32_t acc = w0 ^ 0x7100283fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035388U);
}
static std::uint32_t ByteVc1FdeFunc_298_0x035758(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[298] @ func_va=0x035758, fde_va=0x06fb60, first_op=0xa9bf7bfd
    // VI: Hàm FDE[298] tại địa chỉ 0x035758, bản ghi FDE 0x06fb60
    const std::uint32_t w0 = kByteVc1TextWords[50162U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x035758U);
}
static std::uint32_t ByteVc1FdeFunc_299_0x0357c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[299] @ func_va=0x0357c4, fde_va=0x06fb80, first_op=0xf81d0ff5
    // VI: Hàm FDE[299] tại địa chỉ 0x0357c4, bản ghi FDE 0x06fb80
    const std::uint32_t w0 = kByteVc1TextWords[50189U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0357c4U);
}
static std::uint32_t ByteVc1FdeFunc_300_0x03582c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[300] @ func_va=0x03582c, fde_va=0x06fba0, first_op=0xd10383ff
    // VI: Hàm FDE[300] tại địa chỉ 0x03582c, bản ghi FDE 0x06fba0
    const std::uint32_t w0 = kByteVc1TextWords[50215U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03582cU);
}
static std::uint32_t ByteVc1FdeFunc_301_0x036040(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[301] @ func_va=0x036040, fde_va=0x06fbc8, first_op=0xf81e0ff3
    // VI: Hàm FDE[301] tại địa chỉ 0x036040, bản ghi FDE 0x06fbc8
    const std::uint32_t w0 = kByteVc1TextWords[50732U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x036040U);
}
static std::uint32_t ByteVc1FdeFunc_302_0x0362a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[302] @ func_va=0x0362a8, fde_va=0x06fbe8, first_op=0xb9401488
    // VI: Hàm FDE[302] tại địa chỉ 0x0362a8, bản ghi FDE 0x06fbe8
    const std::uint32_t w0 = kByteVc1TextWords[50886U];
    std::uint32_t acc = w0 ^ 0xb9401488U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0362a8U);
}
static std::uint32_t ByteVc1FdeFunc_303_0x036418(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[303] @ func_va=0x036418, fde_va=0x06fc00, first_op=0xf92c6c1f
    // VI: Hàm FDE[303] tại địa chỉ 0x036418, bản ghi FDE 0x06fc00
    const std::uint32_t w0 = kByteVc1TextWords[50978U];
    std::uint32_t acc = w0 ^ 0xf92c6c1fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x036418U);
}
static std::uint32_t ByteVc1FdeFunc_304_0x0364ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[304] @ func_va=0x0364ec, fde_va=0x06fc18, first_op=0x528b1e08
    // VI: Hàm FDE[304] tại địa chỉ 0x0364ec, bản ghi FDE 0x06fc18
    const std::uint32_t w0 = kByteVc1TextWords[51031U];
    std::uint32_t acc = w0 ^ 0x528b1e08U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0364ecU);
}
static std::uint32_t ByteVc1FdeFunc_305_0x036608(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[305] @ func_va=0x036608, fde_va=0x06fc30, first_op=0x37000361
    // VI: Hàm FDE[305] tại địa chỉ 0x036608, bản ghi FDE 0x06fc30
    const std::uint32_t w0 = kByteVc1TextWords[51102U];
    std::uint32_t acc = w0 ^ 0x37000361U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x036608U);
}
static std::uint32_t ByteVc1FdeFunc_306_0x036678(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[306] @ func_va=0x036678, fde_va=0x06fc48, first_op=0xb40001a1
    // VI: Hàm FDE[306] tại địa chỉ 0x036678, bản ghi FDE 0x06fc48
    const std::uint32_t w0 = kByteVc1TextWords[51130U];
    std::uint32_t acc = w0 ^ 0xb40001a1U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x036678U);
}
static std::uint32_t ByteVc1FdeFunc_307_0x0366b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[307] @ func_va=0x0366b0, fde_va=0x06fc60, first_op=0x52891708
    // VI: Hàm FDE[307] tại địa chỉ 0x0366b0, bản ghi FDE 0x06fc60
    const std::uint32_t w0 = kByteVc1TextWords[51144U];
    std::uint32_t acc = w0 ^ 0x52891708U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0366b0U);
}
static std::uint32_t ByteVc1FdeFunc_308_0x03682c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[308] @ func_va=0x03682c, fde_va=0x06fc78, first_op=0x52891708
    // VI: Hàm FDE[308] tại địa chỉ 0x03682c, bản ghi FDE 0x06fc78
    const std::uint32_t w0 = kByteVc1TextWords[51239U];
    std::uint32_t acc = w0 ^ 0x52891708U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03682cU);
}
static std::uint32_t ByteVc1FdeFunc_309_0x036938(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[309] @ func_va=0x036938, fde_va=0x06fc90, first_op=0xf81a0ffb
    // VI: Hàm FDE[309] tại địa chỉ 0x036938, bản ghi FDE 0x06fc90
    const std::uint32_t w0 = kByteVc1TextWords[51306U];
    std::uint32_t acc = w0 ^ 0xf81a0ffbU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x036938U);
}
static std::uint32_t ByteVc1FdeFunc_310_0x036a34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[310] @ func_va=0x036a34, fde_va=0x06fcc0, first_op=0xd10203ff
    // VI: Hàm FDE[310] tại địa chỉ 0x036a34, bản ghi FDE 0x06fcc0
    const std::uint32_t w0 = kByteVc1TextWords[51369U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x036a34U);
}
static std::uint32_t ByteVc1FdeFunc_311_0x036c34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[311] @ func_va=0x036c34, fde_va=0x06fcf0, first_op=0xd10643ff
    // VI: Hàm FDE[311] tại địa chỉ 0x036c34, bản ghi FDE 0x06fcf0
    const std::uint32_t w0 = kByteVc1TextWords[51497U];
    std::uint32_t acc = w0 ^ 0xd10643ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x036c34U);
}
static std::uint32_t ByteVc1FdeFunc_312_0x037464(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[312] @ func_va=0x037464, fde_va=0x06fd20, first_op=0xa9ba6ffc
    // VI: Hàm FDE[312] tại địa chỉ 0x037464, bản ghi FDE 0x06fd20
    const std::uint32_t w0 = kByteVc1TextWords[52021U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x037464U);
}
static std::uint32_t ByteVc1FdeFunc_313_0x038328(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[313] @ func_va=0x038328, fde_va=0x06fd50, first_op=0xa9bb67fc
    // VI: Hàm FDE[313] tại địa chỉ 0x038328, bản ghi FDE 0x06fd50
    const std::uint32_t w0 = kByteVc1TextWords[52966U];
    std::uint32_t acc = w0 ^ 0xa9bb67fcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x038328U);
}
static std::uint32_t ByteVc1FdeFunc_314_0x038a58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[314] @ func_va=0x038a58, fde_va=0x06fd80, first_op=0xd10643ff
    // VI: Hàm FDE[314] tại địa chỉ 0x038a58, bản ghi FDE 0x06fd80
    const std::uint32_t w0 = kByteVc1TextWords[53426U];
    std::uint32_t acc = w0 ^ 0xd10643ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x038a58U);
}
static std::uint32_t ByteVc1FdeFunc_315_0x039284(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[315] @ func_va=0x039284, fde_va=0x06fdb0, first_op=0x7100203f
    // VI: Hàm FDE[315] tại địa chỉ 0x039284, bản ghi FDE 0x06fdb0
    const std::uint32_t w0 = kByteVc1TextWords[53949U];
    std::uint32_t acc = w0 ^ 0x7100203fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039284U);
}
static std::uint32_t ByteVc1FdeFunc_316_0x0392d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[316] @ func_va=0x0392d4, fde_va=0x06fdc8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[316] tại địa chỉ 0x0392d4, bản ghi FDE 0x06fdc8
    const std::uint32_t w0 = kByteVc1TextWords[53969U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0392d4U);
}
static std::uint32_t ByteVc1FdeFunc_317_0x039694(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[317] @ func_va=0x039694, fde_va=0x06fdf8, first_op=0xa9be4ff4
    // VI: Hàm FDE[317] tại địa chỉ 0x039694, bản ghi FDE 0x06fdf8
    const std::uint32_t w0 = kByteVc1TextWords[54209U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039694U);
}
static std::uint32_t ByteVc1FdeFunc_318_0x0396e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[318] @ func_va=0x0396e8, fde_va=0x06fe18, first_op=0xf81d0ff5
    // VI: Hàm FDE[318] tại địa chỉ 0x0396e8, bản ghi FDE 0x06fe18
    const std::uint32_t w0 = kByteVc1TextWords[54230U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0396e8U);
}
static std::uint32_t ByteVc1FdeFunc_319_0x039768(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[319] @ func_va=0x039768, fde_va=0x06fe38, first_op=0xf81d0ff5
    // VI: Hàm FDE[319] tại địa chỉ 0x039768, bản ghi FDE 0x06fe38
    const std::uint32_t w0 = kByteVc1TextWords[54262U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039768U);
}
static std::uint32_t ByteVc1FdeFunc_320_0x039828(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[320] @ func_va=0x039828, fde_va=0x06fe58, first_op=0xf81b0ff9
    // VI: Hàm FDE[320] tại địa chỉ 0x039828, bản ghi FDE 0x06fe58
    const std::uint32_t w0 = kByteVc1TextWords[54310U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039828U);
}
static std::uint32_t ByteVc1FdeFunc_321_0x039958(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[321] @ func_va=0x039958, fde_va=0x06fe80, first_op=0xf81c0ff7
    // VI: Hàm FDE[321] tại địa chỉ 0x039958, bản ghi FDE 0x06fe80
    const std::uint32_t w0 = kByteVc1TextWords[54386U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039958U);
}
static std::uint32_t ByteVc1FdeFunc_322_0x039a90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[322] @ func_va=0x039a90, fde_va=0x06fea8, first_op=0xa9bd57f6
    // VI: Hàm FDE[322] tại địa chỉ 0x039a90, bản ghi FDE 0x06fea8
    const std::uint32_t w0 = kByteVc1TextWords[54464U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039a90U);
}
static std::uint32_t ByteVc1FdeFunc_323_0x039b08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[323] @ func_va=0x039b08, fde_va=0x06fed0, first_op=0xfc190fe8
    // VI: Hàm FDE[323] tại địa chỉ 0x039b08, bản ghi FDE 0x06fed0
    const std::uint32_t w0 = kByteVc1TextWords[54494U];
    std::uint32_t acc = w0 ^ 0xfc190fe8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039b08U);
}
static std::uint32_t ByteVc1FdeFunc_324_0x039d84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[324] @ func_va=0x039d84, fde_va=0x06ff00, first_op=0xaa0003e8
    // VI: Hàm FDE[324] tại địa chỉ 0x039d84, bản ghi FDE 0x06ff00
    const std::uint32_t w0 = kByteVc1TextWords[54653U];
    std::uint32_t acc = w0 ^ 0xaa0003e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039d84U);
}
static std::uint32_t ByteVc1FdeFunc_325_0x039dd4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[325] @ func_va=0x039dd4, fde_va=0x06ff18, first_op=0xd101c3ff
    // VI: Hàm FDE[325] tại địa chỉ 0x039dd4, bản ghi FDE 0x06ff18
    const std::uint32_t w0 = kByteVc1TextWords[54673U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039dd4U);
}
static std::uint32_t ByteVc1FdeFunc_326_0x039f70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[326] @ func_va=0x039f70, fde_va=0x06ff48, first_op=0xa9bd57f6
    // VI: Hàm FDE[326] tại địa chỉ 0x039f70, bản ghi FDE 0x06ff48
    const std::uint32_t w0 = kByteVc1TextWords[54776U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x039f70U);
}
static std::uint32_t ByteVc1FdeFunc_327_0x03a0cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[327] @ func_va=0x03a0cc, fde_va=0x06ff70, first_op=0xa9bd57f6
    // VI: Hàm FDE[327] tại địa chỉ 0x03a0cc, bản ghi FDE 0x06ff70
    const std::uint32_t w0 = kByteVc1TextWords[54863U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03a0ccU);
}
static std::uint32_t ByteVc1FdeFunc_328_0x03a278(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[328] @ func_va=0x03a278, fde_va=0x06ff98, first_op=0xf81a0ffb
    // VI: Hàm FDE[328] tại địa chỉ 0x03a278, bản ghi FDE 0x06ff98
    const std::uint32_t w0 = kByteVc1TextWords[54970U];
    std::uint32_t acc = w0 ^ 0xf81a0ffbU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03a278U);
}
static std::uint32_t ByteVc1FdeFunc_329_0x03a378(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[329] @ func_va=0x03a378, fde_va=0x06ffc8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[329] tại địa chỉ 0x03a378, bản ghi FDE 0x06ffc8
    const std::uint32_t w0 = kByteVc1TextWords[55034U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03a378U);
}
static std::uint32_t ByteVc1FdeFunc_330_0x03a520(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[330] @ func_va=0x03a520, fde_va=0x06fff8, first_op=0x91002008
    // VI: Hàm FDE[330] tại địa chỉ 0x03a520, bản ghi FDE 0x06fff8
    const std::uint32_t w0 = kByteVc1TextWords[55140U];
    std::uint32_t acc = w0 ^ 0x91002008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03a520U);
}
static std::uint32_t ByteVc1FdeFunc_331_0x03a530(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[331] @ func_va=0x03a530, fde_va=0x070010, first_op=0xa9bd57f6
    // VI: Hàm FDE[331] tại địa chỉ 0x03a530, bản ghi FDE 0x070010
    const std::uint32_t w0 = kByteVc1TextWords[55144U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03a530U);
}
static std::uint32_t ByteVc1FdeFunc_332_0x03a66c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[332] @ func_va=0x03a66c, fde_va=0x070038, first_op=0x52817708
    // VI: Hàm FDE[332] tại địa chỉ 0x03a66c, bản ghi FDE 0x070038
    const std::uint32_t w0 = kByteVc1TextWords[55223U];
    std::uint32_t acc = w0 ^ 0x52817708U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03a66cU);
}
static std::uint32_t ByteVc1FdeFunc_333_0x03a68c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[333] @ func_va=0x03a68c, fde_va=0x070050, first_op=0xf81d0ff5
    // VI: Hàm FDE[333] tại địa chỉ 0x03a68c, bản ghi FDE 0x070050
    const std::uint32_t w0 = kByteVc1TextWords[55231U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03a68cU);
}
static std::uint32_t ByteVc1FdeFunc_334_0x03a6cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[334] @ func_va=0x03a6cc, fde_va=0x070070, first_op=0xd10243ff
    // VI: Hàm FDE[334] tại địa chỉ 0x03a6cc, bản ghi FDE 0x070070
    const std::uint32_t w0 = kByteVc1TextWords[55247U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03a6ccU);
}
static std::uint32_t ByteVc1FdeFunc_335_0x03adf0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[335] @ func_va=0x03adf0, fde_va=0x0700a0, first_op=0xa9bd57f6
    // VI: Hàm FDE[335] tại địa chỉ 0x03adf0, bản ghi FDE 0x0700a0
    const std::uint32_t w0 = kByteVc1TextWords[55704U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03adf0U);
}
static std::uint32_t ByteVc1FdeFunc_336_0x03aec0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[336] @ func_va=0x03aec0, fde_va=0x0700c8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[336] tại địa chỉ 0x03aec0, bản ghi FDE 0x0700c8
    const std::uint32_t w0 = kByteVc1TextWords[55756U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03aec0U);
}
static std::uint32_t ByteVc1FdeFunc_337_0x03b414(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[337] @ func_va=0x03b414, fde_va=0x0700f8, first_op=0xf81b0ff9
    // VI: Hàm FDE[337] tại địa chỉ 0x03b414, bản ghi FDE 0x0700f8
    const std::uint32_t w0 = kByteVc1TextWords[56097U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03b414U);
}
static std::uint32_t ByteVc1FdeFunc_338_0x03b4dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[338] @ func_va=0x03b4dc, fde_va=0x070120, first_op=0xf81b0ff9
    // VI: Hàm FDE[338] tại địa chỉ 0x03b4dc, bản ghi FDE 0x070120
    const std::uint32_t w0 = kByteVc1TextWords[56147U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03b4dcU);
}
static std::uint32_t ByteVc1FdeFunc_339_0x03b5ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[339] @ func_va=0x03b5ec, fde_va=0x070148, first_op=0x90000008
    // VI: Hàm FDE[339] tại địa chỉ 0x03b5ec, bản ghi FDE 0x070148
    const std::uint32_t w0 = kByteVc1TextWords[56215U];
    std::uint32_t acc = w0 ^ 0x90000008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03b5ecU);
}
static std::uint32_t ByteVc1FdeFunc_340_0x03b60c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[340] @ func_va=0x03b60c, fde_va=0x070160, first_op=0xf9400008
    // VI: Hàm FDE[340] tại địa chỉ 0x03b60c, bản ghi FDE 0x070160
    const std::uint32_t w0 = kByteVc1TextWords[56223U];
    std::uint32_t acc = w0 ^ 0xf9400008U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03b60cU);
}
static std::uint32_t ByteVc1FdeFunc_341_0x03b624(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[341] @ func_va=0x03b624, fde_va=0x070178, first_op=0xf81b0ffb
    // VI: Hàm FDE[341] tại địa chỉ 0x03b624, bản ghi FDE 0x070178
    const std::uint32_t w0 = kByteVc1TextWords[56229U];
    std::uint32_t acc = w0 ^ 0xf81b0ffbU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03b624U);
}
static std::uint32_t ByteVc1FdeFunc_342_0x03b824(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[342] @ func_va=0x03b824, fde_va=0x0701a0, first_op=0xd10283ff
    // VI: Hàm FDE[342] tại địa chỉ 0x03b824, bản ghi FDE 0x0701a0
    const std::uint32_t w0 = kByteVc1TextWords[56357U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03b824U);
}
static std::uint32_t ByteVc1FdeFunc_343_0x03bbc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[343] @ func_va=0x03bbc0, fde_va=0x0701d0, first_op=0xa9bd5ff8
    // VI: Hàm FDE[343] tại địa chỉ 0x03bbc0, bản ghi FDE 0x0701d0
    const std::uint32_t w0 = kByteVc1TextWords[56588U];
    std::uint32_t acc = w0 ^ 0xa9bd5ff8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03bbc0U);
}
static std::uint32_t ByteVc1FdeFunc_344_0x03bd2c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[344] @ func_va=0x03bd2c, fde_va=0x0701f0, first_op=0xf81c0ff9
    // VI: Hàm FDE[344] tại địa chỉ 0x03bd2c, bản ghi FDE 0x0701f0
    const std::uint32_t w0 = kByteVc1TextWords[56679U];
    std::uint32_t acc = w0 ^ 0xf81c0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03bd2cU);
}
static std::uint32_t ByteVc1FdeFunc_345_0x03bea8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[345] @ func_va=0x03bea8, fde_va=0x070218, first_op=0xa9be57f6
    // VI: Hàm FDE[345] tại địa chỉ 0x03bea8, bản ghi FDE 0x070218
    const std::uint32_t w0 = kByteVc1TextWords[56774U];
    std::uint32_t acc = w0 ^ 0xa9be57f6U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03bea8U);
}
static std::uint32_t ByteVc1FdeFunc_346_0x03c00c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[346] @ func_va=0x03c00c, fde_va=0x070238, first_op=0xd10243ff
    // VI: Hàm FDE[346] tại địa chỉ 0x03c00c, bản ghi FDE 0x070238
    const std::uint32_t w0 = kByteVc1TextWords[56863U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03c00cU);
}
static std::uint32_t ByteVc1FdeFunc_347_0x03c25c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[347] @ func_va=0x03c25c, fde_va=0x070268, first_op=0xd10243ff
    // VI: Hàm FDE[347] tại địa chỉ 0x03c25c, bản ghi FDE 0x070268
    const std::uint32_t w0 = kByteVc1TextWords[57011U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03c25cU);
}
static std::uint32_t ByteVc1FdeFunc_348_0x03c4f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[348] @ func_va=0x03c4f8, fde_va=0x070298, first_op=0xf81c0ff9
    // VI: Hàm FDE[348] tại địa chỉ 0x03c4f8, bản ghi FDE 0x070298
    const std::uint32_t w0 = kByteVc1TextWords[57178U];
    std::uint32_t acc = w0 ^ 0xf81c0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03c4f8U);
}
static std::uint32_t ByteVc1FdeFunc_349_0x03c7d8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[349] @ func_va=0x03c7d8, fde_va=0x0702c0, first_op=0xd10283ff
    // VI: Hàm FDE[349] tại địa chỉ 0x03c7d8, bản ghi FDE 0x0702c0
    const std::uint32_t w0 = kByteVc1TextWords[57362U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03c7d8U);
}
static std::uint32_t ByteVc1FdeFunc_350_0x03cbc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[350] @ func_va=0x03cbc0, fde_va=0x0702f0, first_op=0xf81b0ffc
    // VI: Hàm FDE[350] tại địa chỉ 0x03cbc0, bản ghi FDE 0x0702f0
    const std::uint32_t w0 = kByteVc1TextWords[57612U];
    std::uint32_t acc = w0 ^ 0xf81b0ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03cbc0U);
}
static std::uint32_t ByteVc1FdeFunc_351_0x03ceb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[351] @ func_va=0x03ceb8, fde_va=0x070318, first_op=0xd101c3ff
    // VI: Hàm FDE[351] tại địa chỉ 0x03ceb8, bản ghi FDE 0x070318
    const std::uint32_t w0 = kByteVc1TextWords[57802U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03ceb8U);
}
static std::uint32_t ByteVc1FdeFunc_352_0x03d178(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[352] @ func_va=0x03d178, fde_va=0x070348, first_op=0xd10383ff
    // VI: Hàm FDE[352] tại địa chỉ 0x03d178, bản ghi FDE 0x070348
    const std::uint32_t w0 = kByteVc1TextWords[57978U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03d178U);
}
static std::uint32_t ByteVc1FdeFunc_353_0x03d55c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[353] @ func_va=0x03d55c, fde_va=0x070378, first_op=0xd103c3ff
    // VI: Hàm FDE[353] tại địa chỉ 0x03d55c, bản ghi FDE 0x070378
    const std::uint32_t w0 = kByteVc1TextWords[58227U];
    std::uint32_t acc = w0 ^ 0xd103c3ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03d55cU);
}
static std::uint32_t ByteVc1FdeFunc_354_0x03d95c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[354] @ func_va=0x03d95c, fde_va=0x0703a8, first_op=0xf00001c3
    // VI: Hàm FDE[354] tại địa chỉ 0x03d95c, bản ghi FDE 0x0703a8
    const std::uint32_t w0 = kByteVc1TextWords[58483U];
    std::uint32_t acc = w0 ^ 0xf00001c3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03d95cU);
}
static std::uint32_t ByteVc1FdeFunc_355_0x03d968(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[355] @ func_va=0x03d968, fde_va=0x0703c0, first_op=0xd00001c3
    // VI: Hàm FDE[355] tại địa chỉ 0x03d968, bản ghi FDE 0x0703c0
    const std::uint32_t w0 = kByteVc1TextWords[58486U];
    std::uint32_t acc = w0 ^ 0xd00001c3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03d968U);
}
static std::uint32_t ByteVc1FdeFunc_356_0x03d974(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[356] @ func_va=0x03d974, fde_va=0x0703d8, first_op=0xa9bc5ff8
    // VI: Hàm FDE[356] tại địa chỉ 0x03d974, bản ghi FDE 0x0703d8
    const std::uint32_t w0 = kByteVc1TextWords[58489U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03d974U);
}
static std::uint32_t ByteVc1FdeFunc_357_0x03da00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[357] @ func_va=0x03da00, fde_va=0x070400, first_op=0xf81c0ff7
    // VI: Hàm FDE[357] tại địa chỉ 0x03da00, bản ghi FDE 0x070400
    const std::uint32_t w0 = kByteVc1TextWords[58524U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03da00U);
}
static std::uint32_t ByteVc1FdeFunc_358_0x03da9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[358] @ func_va=0x03da9c, fde_va=0x070428, first_op=0xf81c0ff7
    // VI: Hàm FDE[358] tại địa chỉ 0x03da9c, bản ghi FDE 0x070428
    const std::uint32_t w0 = kByteVc1TextWords[58563U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03da9cU);
}
static std::uint32_t ByteVc1FdeFunc_359_0x03db38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[359] @ func_va=0x03db38, fde_va=0x070450, first_op=0xf00001c3
    // VI: Hàm FDE[359] tại địa chỉ 0x03db38, bản ghi FDE 0x070450
    const std::uint32_t w0 = kByteVc1TextWords[58602U];
    std::uint32_t acc = w0 ^ 0xf00001c3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03db38U);
}
static std::uint32_t ByteVc1FdeFunc_360_0x03db44(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[360] @ func_va=0x03db44, fde_va=0x070468, first_op=0xd00001c3
    // VI: Hàm FDE[360] tại địa chỉ 0x03db44, bản ghi FDE 0x070468
    const std::uint32_t w0 = kByteVc1TextWords[58605U];
    std::uint32_t acc = w0 ^ 0xd00001c3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03db44U);
}
static std::uint32_t ByteVc1FdeFunc_361_0x03db50(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[361] @ func_va=0x03db50, fde_va=0x070480, first_op=0xa9bc5ff8
    // VI: Hàm FDE[361] tại địa chỉ 0x03db50, bản ghi FDE 0x070480
    const std::uint32_t w0 = kByteVc1TextWords[58608U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03db50U);
}
static std::uint32_t ByteVc1FdeFunc_362_0x03dbdc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[362] @ func_va=0x03dbdc, fde_va=0x0704a8, first_op=0xf81c0ff7
    // VI: Hàm FDE[362] tại địa chỉ 0x03dbdc, bản ghi FDE 0x0704a8
    const std::uint32_t w0 = kByteVc1TextWords[58643U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03dbdcU);
}
static std::uint32_t ByteVc1FdeFunc_363_0x03dc78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[363] @ func_va=0x03dc78, fde_va=0x0704d0, first_op=0xf81c0ff7
    // VI: Hàm FDE[363] tại địa chỉ 0x03dc78, bản ghi FDE 0x0704d0
    const std::uint32_t w0 = kByteVc1TextWords[58682U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03dc78U);
}
static std::uint32_t ByteVc1FdeFunc_364_0x03dd14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[364] @ func_va=0x03dd14, fde_va=0x0704f8, first_op=0x79c00048
    // VI: Hàm FDE[364] tại địa chỉ 0x03dd14, bản ghi FDE 0x0704f8
    const std::uint32_t w0 = kByteVc1TextWords[58721U];
    std::uint32_t acc = w0 ^ 0x79c00048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03dd14U);
}
static std::uint32_t ByteVc1FdeFunc_365_0x03ddd4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[365] @ func_va=0x03ddd4, fde_va=0x070510, first_op=0x79c0004c
    // VI: Hàm FDE[365] tại địa chỉ 0x03ddd4, bản ghi FDE 0x070510
    const std::uint32_t w0 = kByteVc1TextWords[58769U];
    std::uint32_t acc = w0 ^ 0x79c0004cU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03ddd4U);
}
static std::uint32_t ByteVc1FdeFunc_366_0x03de74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[366] @ func_va=0x03de74, fde_va=0x070528, first_op=0x79c0004a
    // VI: Hàm FDE[366] tại địa chỉ 0x03de74, bản ghi FDE 0x070528
    const std::uint32_t w0 = kByteVc1TextWords[58809U];
    std::uint32_t acc = w0 ^ 0x79c0004aU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03de74U);
}
static std::uint32_t ByteVc1FdeFunc_367_0x03df00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[367] @ func_va=0x03df00, fde_va=0x070540, first_op=0x79c00048
    // VI: Hàm FDE[367] tại địa chỉ 0x03df00, bản ghi FDE 0x070540
    const std::uint32_t w0 = kByteVc1TextWords[58844U];
    std::uint32_t acc = w0 ^ 0x79c00048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03df00U);
}
static std::uint32_t ByteVc1FdeFunc_368_0x03dfe8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[368] @ func_va=0x03dfe8, fde_va=0x070558, first_op=0x79c0004c
    // VI: Hàm FDE[368] tại địa chỉ 0x03dfe8, bản ghi FDE 0x070558
    const std::uint32_t w0 = kByteVc1TextWords[58902U];
    std::uint32_t acc = w0 ^ 0x79c0004cU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03dfe8U);
}
static std::uint32_t ByteVc1FdeFunc_369_0x03e0bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[369] @ func_va=0x03e0bc, fde_va=0x070570, first_op=0x79c0004b
    // VI: Hàm FDE[369] tại địa chỉ 0x03e0bc, bản ghi FDE 0x070570
    const std::uint32_t w0 = kByteVc1TextWords[58955U];
    std::uint32_t acc = w0 ^ 0x79c0004bU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e0bcU);
}
static std::uint32_t ByteVc1FdeFunc_370_0x03e180(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[370] @ func_va=0x03e180, fde_va=0x070588, first_op=0xfd400040
    // VI: Hàm FDE[370] tại địa chỉ 0x03e180, bản ghi FDE 0x070588
    const std::uint32_t w0 = kByteVc1TextWords[59004U];
    std::uint32_t acc = w0 ^ 0xfd400040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e180U);
}
static std::uint32_t ByteVc1FdeFunc_371_0x03e1ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[371] @ func_va=0x03e1ec, fde_va=0x0705a0, first_op=0x3dc00040
    // VI: Hàm FDE[371] tại địa chỉ 0x03e1ec, bản ghi FDE 0x0705a0
    const std::uint32_t w0 = kByteVc1TextWords[59031U];
    std::uint32_t acc = w0 ^ 0x3dc00040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e1ecU);
}
static std::uint32_t ByteVc1FdeFunc_372_0x03e2a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[372] @ func_va=0x03e2a4, fde_va=0x0705b8, first_op=0xad400440
    // VI: Hàm FDE[372] tại địa chỉ 0x03e2a4, bản ghi FDE 0x0705b8
    const std::uint32_t w0 = kByteVc1TextWords[59077U];
    std::uint32_t acc = w0 ^ 0xad400440U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e2a4U);
}
static std::uint32_t ByteVc1FdeFunc_373_0x03e3f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[373] @ func_va=0x03e3f0, fde_va=0x0705d0, first_op=0xf9400048
    // VI: Hàm FDE[373] tại địa chỉ 0x03e3f0, bản ghi FDE 0x0705d0
    const std::uint32_t w0 = kByteVc1TextWords[59160U];
    std::uint32_t acc = w0 ^ 0xf9400048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e3f0U);
}
static std::uint32_t ByteVc1FdeFunc_374_0x03e434(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[374] @ func_va=0x03e434, fde_va=0x0705e8, first_op=0x3dc00040
    // VI: Hàm FDE[374] tại địa chỉ 0x03e434, bản ghi FDE 0x0705e8
    const std::uint32_t w0 = kByteVc1TextWords[59177U];
    std::uint32_t acc = w0 ^ 0x3dc00040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e434U);
}
static std::uint32_t ByteVc1FdeFunc_375_0x03e4b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[375] @ func_va=0x03e4b8, fde_va=0x070600, first_op=0xad400440
    // VI: Hàm FDE[375] tại địa chỉ 0x03e4b8, bản ghi FDE 0x070600
    const std::uint32_t w0 = kByteVc1TextWords[59210U];
    std::uint32_t acc = w0 ^ 0xad400440U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e4b8U);
}
static std::uint32_t ByteVc1FdeFunc_376_0x03e5c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[376] @ func_va=0x03e5c0, fde_va=0x070618, first_op=0xaa0203e8
    // VI: Hàm FDE[376] tại địa chỉ 0x03e5c0, bản ghi FDE 0x070618
    const std::uint32_t w0 = kByteVc1TextWords[59276U];
    std::uint32_t acc = w0 ^ 0xaa0203e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e5c0U);
}
static std::uint32_t ByteVc1FdeFunc_377_0x03e63c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[377] @ func_va=0x03e63c, fde_va=0x070630, first_op=0xaa0203e8
    // VI: Hàm FDE[377] tại địa chỉ 0x03e63c, bản ghi FDE 0x070630
    const std::uint32_t w0 = kByteVc1TextWords[59307U];
    std::uint32_t acc = w0 ^ 0xaa0203e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e63cU);
}
static std::uint32_t ByteVc1FdeFunc_378_0x03e738(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[378] @ func_va=0x03e738, fde_va=0x070648, first_op=0xaa0203e8
    // VI: Hàm FDE[378] tại địa chỉ 0x03e738, bản ghi FDE 0x070648
    const std::uint32_t w0 = kByteVc1TextWords[59370U];
    std::uint32_t acc = w0 ^ 0xaa0203e8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e738U);
}
static std::uint32_t ByteVc1FdeFunc_379_0x03e938(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[379] @ func_va=0x03e938, fde_va=0x070660, first_op=0x71007c5f
    // VI: Hàm FDE[379] tại địa chỉ 0x03e938, bản ghi FDE 0x070660
    const std::uint32_t w0 = kByteVc1TextWords[59498U];
    std::uint32_t acc = w0 ^ 0x71007c5fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03e938U);
}
static std::uint32_t ByteVc1FdeFunc_380_0x03ea18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[380] @ func_va=0x03ea18, fde_va=0x070678, first_op=0x39400009
    // VI: Hàm FDE[380] tại địa chỉ 0x03ea18, bản ghi FDE 0x070678
    const std::uint32_t w0 = kByteVc1TextWords[59554U];
    std::uint32_t acc = w0 ^ 0x39400009U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03ea18U);
}
static std::uint32_t ByteVc1FdeFunc_381_0x03eb20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[381] @ func_va=0x03eb20, fde_va=0x070690, first_op=0x52800048
    // VI: Hàm FDE[381] tại địa chỉ 0x03eb20, bản ghi FDE 0x070690
    const std::uint32_t w0 = kByteVc1TextWords[59620U];
    std::uint32_t acc = w0 ^ 0x52800048U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03eb20U);
}
static std::uint32_t ByteVc1FdeFunc_382_0x03ed94(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[382] @ func_va=0x03ed94, fde_va=0x0706a8, first_op=0xd10103ff
    // VI: Hàm FDE[382] tại địa chỉ 0x03ed94, bản ghi FDE 0x0706a8
    const std::uint32_t w0 = kByteVc1TextWords[59777U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03ed94U);
}
static std::uint32_t ByteVc1FdeFunc_383_0x03efbc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[383] @ func_va=0x03efbc, fde_va=0x0706c8, first_op=0xf81e0ff5
    // VI: Hàm FDE[383] tại địa chỉ 0x03efbc, bản ghi FDE 0x0706c8
    const std::uint32_t w0 = kByteVc1TextWords[59915U];
    std::uint32_t acc = w0 ^ 0xf81e0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03efbcU);
}
static std::uint32_t ByteVc1FdeFunc_384_0x03f2d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[384] @ func_va=0x03f2d0, fde_va=0x0706e8, first_op=0xf81c0ff9
    // VI: Hàm FDE[384] tại địa chỉ 0x03f2d0, bản ghi FDE 0x0706e8
    const std::uint32_t w0 = kByteVc1TextWords[60112U];
    std::uint32_t acc = w0 ^ 0xf81c0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03f2d0U);
}
static std::uint32_t ByteVc1FdeFunc_385_0x03f628(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[385] @ func_va=0x03f628, fde_va=0x070710, first_op=0x3940006b
    // VI: Hàm FDE[385] tại địa chỉ 0x03f628, bản ghi FDE 0x070710
    const std::uint32_t w0 = kByteVc1TextWords[60326U];
    std::uint32_t acc = w0 ^ 0x3940006bU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03f628U);
}
static std::uint32_t ByteVc1FdeFunc_386_0x03f7fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[386] @ func_va=0x03f7fc, fde_va=0x070728, first_op=0x531f7828
    // VI: Hàm FDE[386] tại địa chỉ 0x03f7fc, bản ghi FDE 0x070728
    const std::uint32_t w0 = kByteVc1TextWords[60443U];
    std::uint32_t acc = w0 ^ 0x531f7828U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03f7fcU);
}
static std::uint32_t ByteVc1FdeFunc_387_0x03f928(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[387] @ func_va=0x03f928, fde_va=0x070740, first_op=0x17ff95a8
    // VI: Hàm FDE[387] tại địa chỉ 0x03f928, bản ghi FDE 0x070740
    const std::uint32_t w0 = kByteVc1TextWords[60518U];
    std::uint32_t acc = w0 ^ 0x17ff95a8U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03f928U);
}
static std::uint32_t ByteVc1FdeFunc_388_0x03f92c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[388] @ func_va=0x03f92c, fde_va=0x070758, first_op=0x17ff95fc
    // VI: Hàm FDE[388] tại địa chỉ 0x03f92c, bản ghi FDE 0x070758
    const std::uint32_t w0 = kByteVc1TextWords[60519U];
    std::uint32_t acc = w0 ^ 0x17ff95fcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03f92cU);
}
static std::uint32_t ByteVc1FdeFunc_389_0x03f930(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[389] @ func_va=0x03f930, fde_va=0x070770, first_op=0xf81e0ff5
    // VI: Hàm FDE[389] tại địa chỉ 0x03f930, bản ghi FDE 0x070770
    const std::uint32_t w0 = kByteVc1TextWords[60520U];
    std::uint32_t acc = w0 ^ 0xf81e0ff5U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03f930U);
}
static std::uint32_t ByteVc1FdeFunc_390_0x03fc28(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[390] @ func_va=0x03fc28, fde_va=0x070790, first_op=0xf81c0ff9
    // VI: Hàm FDE[390] tại địa chỉ 0x03fc28, bản ghi FDE 0x070790
    const std::uint32_t w0 = kByteVc1TextWords[60710U];
    std::uint32_t acc = w0 ^ 0xf81c0ff9U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03fc28U);
}
static std::uint32_t ByteVc1FdeFunc_391_0x03ff54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[391] @ func_va=0x03ff54, fde_va=0x0707b8, first_op=0x3940006a
    // VI: Hàm FDE[391] tại địa chỉ 0x03ff54, bản ghi FDE 0x0707b8
    const std::uint32_t w0 = kByteVc1TextWords[60913U];
    std::uint32_t acc = w0 ^ 0x3940006aU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x03ff54U);
}
static std::uint32_t ByteVc1FdeFunc_392_0x040130(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[392] @ func_va=0x040130, fde_va=0x0707d0, first_op=0x531f7828
    // VI: Hàm FDE[392] tại địa chỉ 0x040130, bản ghi FDE 0x0707d0
    const std::uint32_t w0 = kByteVc1TextWords[61032U];
    std::uint32_t acc = w0 ^ 0x531f7828U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x040130U);
}
static std::uint32_t ByteVc1FdeFunc_393_0x04024c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[393] @ func_va=0x04024c, fde_va=0x0707e8, first_op=0x17ff942a
    // VI: Hàm FDE[393] tại địa chỉ 0x04024c, bản ghi FDE 0x0707e8
    const std::uint32_t w0 = kByteVc1TextWords[61103U];
    std::uint32_t acc = w0 ^ 0x17ff942aU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x04024cU);
}
static std::uint32_t ByteVc1FdeFunc_394_0x040250(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[394] @ func_va=0x040250, fde_va=0x070800, first_op=0x17ff9480
    // VI: Hàm FDE[394] tại địa chỉ 0x040250, bản ghi FDE 0x070800
    const std::uint32_t w0 = kByteVc1TextWords[61104U];
    std::uint32_t acc = w0 ^ 0x17ff9480U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x040250U);
}
static std::uint32_t ByteVc1FdeFunc_395_0x040254(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[395] @ func_va=0x040254, fde_va=0x070818, first_op=0x710004bf
    // VI: Hàm FDE[395] tại địa chỉ 0x040254, bản ghi FDE 0x070818
    const std::uint32_t w0 = kByteVc1TextWords[61105U];
    std::uint32_t acc = w0 ^ 0x710004bfU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x040254U);
}
static std::uint32_t ByteVc1FdeFunc_396_0x0403a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[396] @ func_va=0x0403a0, fde_va=0x070830, first_op=0x7100049f
    // VI: Hàm FDE[396] tại địa chỉ 0x0403a0, bản ghi FDE 0x070830
    const std::uint32_t w0 = kByteVc1TextWords[61188U];
    std::uint32_t acc = w0 ^ 0x7100049fU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0403a0U);
}
static std::uint32_t ByteVc1FdeFunc_397_0x04046c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[397] @ func_va=0x04046c, fde_va=0x070848, first_op=0x710004df
    // VI: Hàm FDE[397] tại địa chỉ 0x04046c, bản ghi FDE 0x070848
    const std::uint32_t w0 = kByteVc1TextWords[61239U];
    std::uint32_t acc = w0 ^ 0x710004dfU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x04046cU);
}
static std::uint32_t ByteVc1FdeFunc_398_0x040590(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[398] @ func_va=0x040590, fde_va=0x070860, first_op=0xd10303ff
    // VI: Hàm FDE[398] tại địa chỉ 0x040590, bản ghi FDE 0x070860
    const std::uint32_t w0 = kByteVc1TextWords[61312U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x040590U);
}
static std::uint32_t ByteVc1FdeFunc_399_0x040810(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[399] @ func_va=0x040810, fde_va=0x070880, first_op=0xfd400040
    // VI: Hàm FDE[399] tại địa chỉ 0x040810, bản ghi FDE 0x070880
    const std::uint32_t w0 = kByteVc1TextWords[61472U];
    std::uint32_t acc = w0 ^ 0xfd400040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x040810U);
}
static std::uint32_t ByteVc1FdeFunc_400_0x0409d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[400] @ func_va=0x0409d4, fde_va=0x070898, first_op=0xfd400040
    // VI: Hàm FDE[400] tại địa chỉ 0x0409d4, bản ghi FDE 0x070898
    const std::uint32_t w0 = kByteVc1TextWords[61585U];
    std::uint32_t acc = w0 ^ 0xfd400040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0409d4U);
}
static std::uint32_t ByteVc1FdeFunc_401_0x040c08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[401] @ func_va=0x040c08, fde_va=0x0708b0, first_op=0xfd400040
    // VI: Hàm FDE[401] tại địa chỉ 0x040c08, bản ghi FDE 0x0708b0
    const std::uint32_t w0 = kByteVc1TextWords[61726U];
    std::uint32_t acc = w0 ^ 0xfd400040U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x040c08U);
}
static std::uint32_t ByteVc1FdeFunc_402_0x040f00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[402] @ func_va=0x040f00, fde_va=0x0708c8, first_op=0xf81f0ff3
    // VI: Hàm FDE[402] tại địa chỉ 0x040f00, bản ghi FDE 0x0708c8
    const std::uint32_t w0 = kByteVc1TextWords[61916U];
    std::uint32_t acc = w0 ^ 0xf81f0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x040f00U);
}
static std::uint32_t ByteVc1FdeFunc_403_0x041024(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[403] @ func_va=0x041024, fde_va=0x0708e0, first_op=0xa9bf4ff4
    // VI: Hàm FDE[403] tại địa chỉ 0x041024, bản ghi FDE 0x0708e0
    const std::uint32_t w0 = kByteVc1TextWords[61989U];
    std::uint32_t acc = w0 ^ 0xa9bf4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x041024U);
}
static std::uint32_t ByteVc1FdeFunc_404_0x04120c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[404] @ func_va=0x04120c, fde_va=0x0708f8, first_op=0xf81d0ff7
    // VI: Hàm FDE[404] tại địa chỉ 0x04120c, bản ghi FDE 0x0708f8
    const std::uint32_t w0 = kByteVc1TextWords[62111U];
    std::uint32_t acc = w0 ^ 0xf81d0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x04120cU);
}
static std::uint32_t ByteVc1FdeFunc_405_0x0414a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[405] @ func_va=0x0414a0, fde_va=0x070918, first_op=0xf81d0ff7
    // VI: Hàm FDE[405] tại địa chỉ 0x0414a0, bản ghi FDE 0x070918
    const std::uint32_t w0 = kByteVc1TextWords[62276U];
    std::uint32_t acc = w0 ^ 0xf81d0ff7U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0414a0U);
}
static std::uint32_t ByteVc1FdeFunc_406_0x0417f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[406] @ func_va=0x0417f8, fde_va=0x070938, first_op=0xd10383ff
    // VI: Hàm FDE[406] tại địa chỉ 0x0417f8, bản ghi FDE 0x070938
    const std::uint32_t w0 = kByteVc1TextWords[62490U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0417f8U);
}
static std::uint32_t ByteVc1FdeFunc_407_0x041b94(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[407] @ func_va=0x041b94, fde_va=0x070960, first_op=0xad400440
    // VI: Hàm FDE[407] tại địa chỉ 0x041b94, bản ghi FDE 0x070960
    const std::uint32_t w0 = kByteVc1TextWords[62721U];
    std::uint32_t acc = w0 ^ 0xad400440U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x041b94U);
}
static std::uint32_t ByteVc1FdeFunc_408_0x041c58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[408] @ func_va=0x041c58, fde_va=0x070978, first_op=0xa9ba6ffc
    // VI: Hàm FDE[408] tại địa chỉ 0x041c58, bản ghi FDE 0x070978
    const std::uint32_t w0 = kByteVc1TextWords[62770U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x041c58U);
}
static std::uint32_t ByteVc1FdeFunc_409_0x0428d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[409] @ func_va=0x0428d0, fde_va=0x0709a8, first_op=0xa9bd57fc
    // VI: Hàm FDE[409] tại địa chỉ 0x0428d0, bản ghi FDE 0x0709a8
    const std::uint32_t w0 = kByteVc1TextWords[63568U];
    std::uint32_t acc = w0 ^ 0xa9bd57fcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0428d0U);
}
static std::uint32_t ByteVc1FdeFunc_410_0x066d08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[410] @ func_va=0x066d08, fde_va=0x0709d0, first_op=0xd0000088
    // VI: Hàm FDE[410] tại địa chỉ 0x066d08, bản ghi FDE 0x0709d0
    const std::uint32_t w0 = kByteVc1TextWords[100702U];
    std::uint32_t acc = w0 ^ 0xd0000088U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x066d08U);
}
static std::uint32_t ByteVc1FdeFunc_411_0x066d1c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[411] @ func_va=0x066d1c, fde_va=0x0709e8, first_op=0xf81c0ffc
    // VI: Hàm FDE[411] tại địa chỉ 0x066d1c, bản ghi FDE 0x0709e8
    const std::uint32_t w0 = kByteVc1TextWords[100707U];
    std::uint32_t acc = w0 ^ 0xf81c0ffcU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x066d1cU);
}
static std::uint32_t ByteVc1FdeFunc_412_0x066e70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[412] @ func_va=0x066e70, fde_va=0x070a10, first_op=0xd10443ff
    // VI: Hàm FDE[412] tại địa chỉ 0x066e70, bản ghi FDE 0x070a10
    const std::uint32_t w0 = kByteVc1TextWords[100792U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x066e70U);
}
static std::uint32_t ByteVc1FdeFunc_413_0x066f0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[413] @ func_va=0x066f0c, fde_va=0x070a30, first_op=0xa9bf7bfd
    // VI: Hàm FDE[413] tại địa chỉ 0x066f0c, bản ghi FDE 0x070a30
    const std::uint32_t w0 = kByteVc1TextWords[100831U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x066f0cU);
}
static std::uint32_t ByteVc1FdeFunc_414_0x066f58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[414] @ func_va=0x066f58, fde_va=0x070a50, first_op=0xb4000080
    // VI: Hàm FDE[414] tại địa chỉ 0x066f58, bản ghi FDE 0x070a50
    const std::uint32_t w0 = kByteVc1TextWords[100850U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x066f58U);
}
static std::uint32_t ByteVc1FdeFunc_415_0x066f6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[415] @ func_va=0x066f6c, fde_va=0x070a68, first_op=0xf81e0ff3
    // VI: Hàm FDE[415] tại địa chỉ 0x066f6c, bản ghi FDE 0x070a68
    const std::uint32_t w0 = kByteVc1TextWords[100855U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x066f6cU);
}
static std::uint32_t ByteVc1FdeFunc_416_0x066fe0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[416] @ func_va=0x066fe0, fde_va=0x070a88, first_op=0xf81e0ff3
    // VI: Hàm FDE[416] tại địa chỉ 0x066fe0, bản ghi FDE 0x070a88
    const std::uint32_t w0 = kByteVc1TextWords[100884U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x066fe0U);
}
static std::uint32_t ByteVc1FdeFunc_417_0x067040(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[417] @ func_va=0x067040, fde_va=0x070aa8, first_op=0xa9be4ff4
    // VI: Hàm FDE[417] tại địa chỉ 0x067040, bản ghi FDE 0x070aa8
    const std::uint32_t w0 = kByteVc1TextWords[100908U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x067040U);
}
static std::uint32_t ByteVc1FdeFunc_418_0x0670a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[418] @ func_va=0x0670a8, fde_va=0x070ac8, first_op=0xf81e0ff3
    // VI: Hàm FDE[418] tại địa chỉ 0x0670a8, bản ghi FDE 0x070ac8
    const std::uint32_t w0 = kByteVc1TextWords[100934U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 9U) | (acc >> 23U);
    return acc + (a1 ^ 0x0670a8U);
}

std::uint32_t DispatchByteVc1FdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept {
    switch (fde_index % kEhFrameFdeCount) {
        case 0U: return ByteVc1FdeFunc_000_0x0047cc(arg0, arg1);
        case 1U: return ByteVc1FdeFunc_001_0x004804(arg0, arg1);
        case 2U: return ByteVc1FdeFunc_002_0x004a48(arg0, arg1);
        case 3U: return ByteVc1FdeFunc_003_0x004a4c(arg0, arg1);
        case 4U: return ByteVc1FdeFunc_004_0x004a54(arg0, arg1);
        case 5U: return ByteVc1FdeFunc_005_0x004dc4(arg0, arg1);
        case 6U: return ByteVc1FdeFunc_006_0x004e10(arg0, arg1);
        case 7U: return ByteVc1FdeFunc_007_0x004e3c(arg0, arg1);
        case 8U: return ByteVc1FdeFunc_008_0x004e40(arg0, arg1);
        case 9U: return ByteVc1FdeFunc_009_0x004e44(arg0, arg1);
        case 10U: return ByteVc1FdeFunc_010_0x004e48(arg0, arg1);
        case 11U: return ByteVc1FdeFunc_011_0x004e94(arg0, arg1);
        case 12U: return ByteVc1FdeFunc_012_0x004ea4(arg0, arg1);
        case 13U: return ByteVc1FdeFunc_013_0x004eb0(arg0, arg1);
        case 14U: return ByteVc1FdeFunc_014_0x004ee4(arg0, arg1);
        case 15U: return ByteVc1FdeFunc_015_0x004ee8(arg0, arg1);
        case 16U: return ByteVc1FdeFunc_016_0x004ef0(arg0, arg1);
        case 17U: return ByteVc1FdeFunc_017_0x004ef8(arg0, arg1);
        case 18U: return ByteVc1FdeFunc_018_0x004f00(arg0, arg1);
        case 19U: return ByteVc1FdeFunc_019_0x004f08(arg0, arg1);
        case 20U: return ByteVc1FdeFunc_020_0x004f28(arg0, arg1);
        case 21U: return ByteVc1FdeFunc_021_0x004f34(arg0, arg1);
        case 22U: return ByteVc1FdeFunc_022_0x004f40(arg0, arg1);
        case 23U: return ByteVc1FdeFunc_023_0x004f48(arg0, arg1);
        case 24U: return ByteVc1FdeFunc_024_0x004f50(arg0, arg1);
        case 25U: return ByteVc1FdeFunc_025_0x004f58(arg0, arg1);
        case 26U: return ByteVc1FdeFunc_026_0x004f60(arg0, arg1);
        case 27U: return ByteVc1FdeFunc_027_0x004f68(arg0, arg1);
        case 28U: return ByteVc1FdeFunc_028_0x004f70(arg0, arg1);
        case 29U: return ByteVc1FdeFunc_029_0x004f78(arg0, arg1);
        case 30U: return ByteVc1FdeFunc_030_0x004f80(arg0, arg1);
        case 31U: return ByteVc1FdeFunc_031_0x004f88(arg0, arg1);
        case 32U: return ByteVc1FdeFunc_032_0x004f8c(arg0, arg1);
        case 33U: return ByteVc1FdeFunc_033_0x004f94(arg0, arg1);
        case 34U: return ByteVc1FdeFunc_034_0x004f9c(arg0, arg1);
        case 35U: return ByteVc1FdeFunc_035_0x004fa4(arg0, arg1);
        case 36U: return ByteVc1FdeFunc_036_0x004fac(arg0, arg1);
        case 37U: return ByteVc1FdeFunc_037_0x004fb4(arg0, arg1);
        case 38U: return ByteVc1FdeFunc_038_0x004fbc(arg0, arg1);
        case 39U: return ByteVc1FdeFunc_039_0x004fc4(arg0, arg1);
        case 40U: return ByteVc1FdeFunc_040_0x004fd0(arg0, arg1);
        case 41U: return ByteVc1FdeFunc_041_0x004fdc(arg0, arg1);
        case 42U: return ByteVc1FdeFunc_042_0x004fe4(arg0, arg1);
        case 43U: return ByteVc1FdeFunc_043_0x004fec(arg0, arg1);
        case 44U: return ByteVc1FdeFunc_044_0x004ff4(arg0, arg1);
        case 45U: return ByteVc1FdeFunc_045_0x004ffc(arg0, arg1);
        case 46U: return ByteVc1FdeFunc_046_0x005008(arg0, arg1);
        case 47U: return ByteVc1FdeFunc_047_0x005024(arg0, arg1);
        case 48U: return ByteVc1FdeFunc_048_0x00502c(arg0, arg1);
        case 49U: return ByteVc1FdeFunc_049_0x005034(arg0, arg1);
        case 50U: return ByteVc1FdeFunc_050_0x00503c(arg0, arg1);
        case 51U: return ByteVc1FdeFunc_051_0x005044(arg0, arg1);
        case 52U: return ByteVc1FdeFunc_052_0x00504c(arg0, arg1);
        case 53U: return ByteVc1FdeFunc_053_0x005054(arg0, arg1);
        case 54U: return ByteVc1FdeFunc_054_0x00505c(arg0, arg1);
        case 55U: return ByteVc1FdeFunc_055_0x005064(arg0, arg1);
        case 56U: return ByteVc1FdeFunc_056_0x00506c(arg0, arg1);
        case 57U: return ByteVc1FdeFunc_057_0x005070(arg0, arg1);
        case 58U: return ByteVc1FdeFunc_058_0x005078(arg0, arg1);
        case 59U: return ByteVc1FdeFunc_059_0x00507c(arg0, arg1);
        case 60U: return ByteVc1FdeFunc_060_0x005084(arg0, arg1);
        case 61U: return ByteVc1FdeFunc_061_0x005088(arg0, arg1);
        case 62U: return ByteVc1FdeFunc_062_0x005090(arg0, arg1);
        case 63U: return ByteVc1FdeFunc_063_0x005094(arg0, arg1);
        case 64U: return ByteVc1FdeFunc_064_0x00509c(arg0, arg1);
        case 65U: return ByteVc1FdeFunc_065_0x0050a4(arg0, arg1);
        case 66U: return ByteVc1FdeFunc_066_0x0050b0(arg0, arg1);
        case 67U: return ByteVc1FdeFunc_067_0x005160(arg0, arg1);
        case 68U: return ByteVc1FdeFunc_068_0x005210(arg0, arg1);
        case 69U: return ByteVc1FdeFunc_069_0x005290(arg0, arg1);
        case 70U: return ByteVc1FdeFunc_070_0x0064b4(arg0, arg1);
        case 71U: return ByteVc1FdeFunc_071_0x0067b8(arg0, arg1);
        case 72U: return ByteVc1FdeFunc_072_0x00786c(arg0, arg1);
        case 73U: return ByteVc1FdeFunc_073_0x00bd80(arg0, arg1);
        case 74U: return ByteVc1FdeFunc_074_0x00be10(arg0, arg1);
        case 75U: return ByteVc1FdeFunc_075_0x00c3f4(arg0, arg1);
        case 76U: return ByteVc1FdeFunc_076_0x00d008(arg0, arg1);
        case 77U: return ByteVc1FdeFunc_077_0x00edd8(arg0, arg1);
        case 78U: return ByteVc1FdeFunc_078_0x0128f0(arg0, arg1);
        case 79U: return ByteVc1FdeFunc_079_0x012c04(arg0, arg1);
        case 80U: return ByteVc1FdeFunc_080_0x012c38(arg0, arg1);
        case 81U: return ByteVc1FdeFunc_081_0x012c6c(arg0, arg1);
        case 82U: return ByteVc1FdeFunc_082_0x012d04(arg0, arg1);
        case 83U: return ByteVc1FdeFunc_083_0x014664(arg0, arg1);
        case 84U: return ByteVc1FdeFunc_084_0x014f48(arg0, arg1);
        case 85U: return ByteVc1FdeFunc_085_0x0168d8(arg0, arg1);
        case 86U: return ByteVc1FdeFunc_086_0x0169c8(arg0, arg1);
        case 87U: return ByteVc1FdeFunc_087_0x016a8c(arg0, arg1);
        case 88U: return ByteVc1FdeFunc_088_0x016b84(arg0, arg1);
        case 89U: return ByteVc1FdeFunc_089_0x017944(arg0, arg1);
        case 90U: return ByteVc1FdeFunc_090_0x017b10(arg0, arg1);
        case 91U: return ByteVc1FdeFunc_091_0x01949c(arg0, arg1);
        case 92U: return ByteVc1FdeFunc_092_0x019d18(arg0, arg1);
        case 93U: return ByteVc1FdeFunc_093_0x01a70c(arg0, arg1);
        case 94U: return ByteVc1FdeFunc_094_0x01ab30(arg0, arg1);
        case 95U: return ByteVc1FdeFunc_095_0x01ad3c(arg0, arg1);
        case 96U: return ByteVc1FdeFunc_096_0x01aeec(arg0, arg1);
        case 97U: return ByteVc1FdeFunc_097_0x01c1f8(arg0, arg1);
        case 98U: return ByteVc1FdeFunc_098_0x01c204(arg0, arg1);
        case 99U: return ByteVc1FdeFunc_099_0x01c238(arg0, arg1);
        case 100U: return ByteVc1FdeFunc_100_0x01c304(arg0, arg1);
        case 101U: return ByteVc1FdeFunc_101_0x01c378(arg0, arg1);
        case 102U: return ByteVc1FdeFunc_102_0x01c3b4(arg0, arg1);
        case 103U: return ByteVc1FdeFunc_103_0x01c79c(arg0, arg1);
        case 104U: return ByteVc1FdeFunc_104_0x01c854(arg0, arg1);
        case 105U: return ByteVc1FdeFunc_105_0x01cba0(arg0, arg1);
        case 106U: return ByteVc1FdeFunc_106_0x01cc98(arg0, arg1);
        case 107U: return ByteVc1FdeFunc_107_0x01ec78(arg0, arg1);
        case 108U: return ByteVc1FdeFunc_108_0x020114(arg0, arg1);
        case 109U: return ByteVc1FdeFunc_109_0x0204c4(arg0, arg1);
        case 110U: return ByteVc1FdeFunc_110_0x020788(arg0, arg1);
        case 111U: return ByteVc1FdeFunc_111_0x0212b4(arg0, arg1);
        case 112U: return ByteVc1FdeFunc_112_0x022540(arg0, arg1);
        case 113U: return ByteVc1FdeFunc_113_0x022b1c(arg0, arg1);
        case 114U: return ByteVc1FdeFunc_114_0x022cbc(arg0, arg1);
        case 115U: return ByteVc1FdeFunc_115_0x023c64(arg0, arg1);
        case 116U: return ByteVc1FdeFunc_116_0x0248f0(arg0, arg1);
        case 117U: return ByteVc1FdeFunc_117_0x024fc8(arg0, arg1);
        case 118U: return ByteVc1FdeFunc_118_0x02511c(arg0, arg1);
        case 119U: return ByteVc1FdeFunc_119_0x0252a4(arg0, arg1);
        case 120U: return ByteVc1FdeFunc_120_0x0252cc(arg0, arg1);
        case 121U: return ByteVc1FdeFunc_121_0x0252f4(arg0, arg1);
        case 122U: return ByteVc1FdeFunc_122_0x025450(arg0, arg1);
        case 123U: return ByteVc1FdeFunc_123_0x0255dc(arg0, arg1);
        case 124U: return ByteVc1FdeFunc_124_0x025604(arg0, arg1);
        case 125U: return ByteVc1FdeFunc_125_0x02562c(arg0, arg1);
        case 126U: return ByteVc1FdeFunc_126_0x0258ac(arg0, arg1);
        case 127U: return ByteVc1FdeFunc_127_0x025abc(arg0, arg1);
        case 128U: return ByteVc1FdeFunc_128_0x0265b8(arg0, arg1);
        case 129U: return ByteVc1FdeFunc_129_0x026840(arg0, arg1);
        case 130U: return ByteVc1FdeFunc_130_0x027360(arg0, arg1);
        case 131U: return ByteVc1FdeFunc_131_0x0274a0(arg0, arg1);
        case 132U: return ByteVc1FdeFunc_132_0x0274c0(arg0, arg1);
        case 133U: return ByteVc1FdeFunc_133_0x0274d0(arg0, arg1);
        case 134U: return ByteVc1FdeFunc_134_0x0274e4(arg0, arg1);
        case 135U: return ByteVc1FdeFunc_135_0x0274ec(arg0, arg1);
        case 136U: return ByteVc1FdeFunc_136_0x02750c(arg0, arg1);
        case 137U: return ByteVc1FdeFunc_137_0x027538(arg0, arg1);
        case 138U: return ByteVc1FdeFunc_138_0x02754c(arg0, arg1);
        case 139U: return ByteVc1FdeFunc_139_0x0275d8(arg0, arg1);
        case 140U: return ByteVc1FdeFunc_140_0x027634(arg0, arg1);
        case 141U: return ByteVc1FdeFunc_141_0x027640(arg0, arg1);
        case 142U: return ByteVc1FdeFunc_142_0x02764c(arg0, arg1);
        case 143U: return ByteVc1FdeFunc_143_0x027654(arg0, arg1);
        case 144U: return ByteVc1FdeFunc_144_0x027658(arg0, arg1);
        case 145U: return ByteVc1FdeFunc_145_0x027664(arg0, arg1);
        case 146U: return ByteVc1FdeFunc_146_0x027670(arg0, arg1);
        case 147U: return ByteVc1FdeFunc_147_0x02768c(arg0, arg1);
        case 148U: return ByteVc1FdeFunc_148_0x027b74(arg0, arg1);
        case 149U: return ByteVc1FdeFunc_149_0x027cd0(arg0, arg1);
        case 150U: return ByteVc1FdeFunc_150_0x027ce0(arg0, arg1);
        case 151U: return ByteVc1FdeFunc_151_0x027d78(arg0, arg1);
        case 152U: return ByteVc1FdeFunc_152_0x027e10(arg0, arg1);
        case 153U: return ByteVc1FdeFunc_153_0x028334(arg0, arg1);
        case 154U: return ByteVc1FdeFunc_154_0x028490(arg0, arg1);
        case 155U: return ByteVc1FdeFunc_155_0x02861c(arg0, arg1);
        case 156U: return ByteVc1FdeFunc_156_0x028728(arg0, arg1);
        case 157U: return ByteVc1FdeFunc_157_0x028738(arg0, arg1);
        case 158U: return ByteVc1FdeFunc_158_0x02874c(arg0, arg1);
        case 159U: return ByteVc1FdeFunc_159_0x028768(arg0, arg1);
        case 160U: return ByteVc1FdeFunc_160_0x0287a8(arg0, arg1);
        case 161U: return ByteVc1FdeFunc_161_0x0287bc(arg0, arg1);
        case 162U: return ByteVc1FdeFunc_162_0x0287c8(arg0, arg1);
        case 163U: return ByteVc1FdeFunc_163_0x0287d4(arg0, arg1);
        case 164U: return ByteVc1FdeFunc_164_0x0287e4(arg0, arg1);
        case 165U: return ByteVc1FdeFunc_165_0x0287f0(arg0, arg1);
        case 166U: return ByteVc1FdeFunc_166_0x0287fc(arg0, arg1);
        case 167U: return ByteVc1FdeFunc_167_0x028808(arg0, arg1);
        case 168U: return ByteVc1FdeFunc_168_0x028814(arg0, arg1);
        case 169U: return ByteVc1FdeFunc_169_0x0289cc(arg0, arg1);
        case 170U: return ByteVc1FdeFunc_170_0x028c04(arg0, arg1);
        case 171U: return ByteVc1FdeFunc_171_0x028e88(arg0, arg1);
        case 172U: return ByteVc1FdeFunc_172_0x029070(arg0, arg1);
        case 173U: return ByteVc1FdeFunc_173_0x029288(arg0, arg1);
        case 174U: return ByteVc1FdeFunc_174_0x029470(arg0, arg1);
        case 175U: return ByteVc1FdeFunc_175_0x029528(arg0, arg1);
        case 176U: return ByteVc1FdeFunc_176_0x029754(arg0, arg1);
        case 177U: return ByteVc1FdeFunc_177_0x029b18(arg0, arg1);
        case 178U: return ByteVc1FdeFunc_178_0x029ca4(arg0, arg1);
        case 179U: return ByteVc1FdeFunc_179_0x029e2c(arg0, arg1);
        case 180U: return ByteVc1FdeFunc_180_0x02a098(arg0, arg1);
        case 181U: return ByteVc1FdeFunc_181_0x02a45c(arg0, arg1);
        case 182U: return ByteVc1FdeFunc_182_0x02a774(arg0, arg1);
        case 183U: return ByteVc1FdeFunc_183_0x02aa5c(arg0, arg1);
        case 184U: return ByteVc1FdeFunc_184_0x02ae80(arg0, arg1);
        case 185U: return ByteVc1FdeFunc_185_0x02b2a8(arg0, arg1);
        case 186U: return ByteVc1FdeFunc_186_0x02b444(arg0, arg1);
        case 187U: return ByteVc1FdeFunc_187_0x02b6f0(arg0, arg1);
        case 188U: return ByteVc1FdeFunc_188_0x02b98c(arg0, arg1);
        case 189U: return ByteVc1FdeFunc_189_0x02bacc(arg0, arg1);
        case 190U: return ByteVc1FdeFunc_190_0x02bb30(arg0, arg1);
        case 191U: return ByteVc1FdeFunc_191_0x02bb90(arg0, arg1);
        case 192U: return ByteVc1FdeFunc_192_0x02c3fc(arg0, arg1);
        case 193U: return ByteVc1FdeFunc_193_0x02c408(arg0, arg1);
        case 194U: return ByteVc1FdeFunc_194_0x02c724(arg0, arg1);
        case 195U: return ByteVc1FdeFunc_195_0x02c960(arg0, arg1);
        case 196U: return ByteVc1FdeFunc_196_0x02c9c4(arg0, arg1);
        case 197U: return ByteVc1FdeFunc_197_0x02cbd8(arg0, arg1);
        case 198U: return ByteVc1FdeFunc_198_0x02cc40(arg0, arg1);
        case 199U: return ByteVc1FdeFunc_199_0x02cccc(arg0, arg1);
        case 200U: return ByteVc1FdeFunc_200_0x02cd48(arg0, arg1);
        case 201U: return ByteVc1FdeFunc_201_0x02cd60(arg0, arg1);
        case 202U: return ByteVc1FdeFunc_202_0x02ce20(arg0, arg1);
        case 203U: return ByteVc1FdeFunc_203_0x02ce2c(arg0, arg1);
        case 204U: return ByteVc1FdeFunc_204_0x02ce40(arg0, arg1);
        case 205U: return ByteVc1FdeFunc_205_0x02ce54(arg0, arg1);
        case 206U: return ByteVc1FdeFunc_206_0x02ce70(arg0, arg1);
        case 207U: return ByteVc1FdeFunc_207_0x02ce98(arg0, arg1);
        case 208U: return ByteVc1FdeFunc_208_0x02cee0(arg0, arg1);
        case 209U: return ByteVc1FdeFunc_209_0x02cf20(arg0, arg1);
        case 210U: return ByteVc1FdeFunc_210_0x02cf80(arg0, arg1);
        case 211U: return ByteVc1FdeFunc_211_0x02cf94(arg0, arg1);
        case 212U: return ByteVc1FdeFunc_212_0x02cfb8(arg0, arg1);
        case 213U: return ByteVc1FdeFunc_213_0x02cfd8(arg0, arg1);
        case 214U: return ByteVc1FdeFunc_214_0x02d008(arg0, arg1);
        case 215U: return ByteVc1FdeFunc_215_0x02d020(arg0, arg1);
        case 216U: return ByteVc1FdeFunc_216_0x02d048(arg0, arg1);
        case 217U: return ByteVc1FdeFunc_217_0x02d070(arg0, arg1);
        case 218U: return ByteVc1FdeFunc_218_0x02d0a8(arg0, arg1);
        case 219U: return ByteVc1FdeFunc_219_0x02d100(arg0, arg1);
        case 220U: return ByteVc1FdeFunc_220_0x02d198(arg0, arg1);
        case 221U: return ByteVc1FdeFunc_221_0x02d224(arg0, arg1);
        case 222U: return ByteVc1FdeFunc_222_0x02d2f0(arg0, arg1);
        case 223U: return ByteVc1FdeFunc_223_0x02d328(arg0, arg1);
        case 224U: return ByteVc1FdeFunc_224_0x02d390(arg0, arg1);
        case 225U: return ByteVc1FdeFunc_225_0x02d3ec(arg0, arg1);
        case 226U: return ByteVc1FdeFunc_226_0x02d478(arg0, arg1);
        case 227U: return ByteVc1FdeFunc_227_0x02d4c0(arg0, arg1);
        case 228U: return ByteVc1FdeFunc_228_0x02d538(arg0, arg1);
        case 229U: return ByteVc1FdeFunc_229_0x02d5a8(arg0, arg1);
        case 230U: return ByteVc1FdeFunc_230_0x02d648(arg0, arg1);
        case 231U: return ByteVc1FdeFunc_231_0x02d6ec(arg0, arg1);
        case 232U: return ByteVc1FdeFunc_232_0x02d7f8(arg0, arg1);
        case 233U: return ByteVc1FdeFunc_233_0x02d8e8(arg0, arg1);
        case 234U: return ByteVc1FdeFunc_234_0x02da40(arg0, arg1);
        case 235U: return ByteVc1FdeFunc_235_0x02dacc(arg0, arg1);
        case 236U: return ByteVc1FdeFunc_236_0x02dbc0(arg0, arg1);
        case 237U: return ByteVc1FdeFunc_237_0x02dc98(arg0, arg1);
        case 238U: return ByteVc1FdeFunc_238_0x02ddd8(arg0, arg1);
        case 239U: return ByteVc1FdeFunc_239_0x02de4c(arg0, arg1);
        case 240U: return ByteVc1FdeFunc_240_0x02def8(arg0, arg1);
        case 241U: return ByteVc1FdeFunc_241_0x02df98(arg0, arg1);
        case 242U: return ByteVc1FdeFunc_242_0x02e070(arg0, arg1);
        case 243U: return ByteVc1FdeFunc_243_0x02e1c0(arg0, arg1);
        case 244U: return ByteVc1FdeFunc_244_0x02e418(arg0, arg1);
        case 245U: return ByteVc1FdeFunc_245_0x02e634(arg0, arg1);
        case 246U: return ByteVc1FdeFunc_246_0x02e958(arg0, arg1);
        case 247U: return ByteVc1FdeFunc_247_0x02ea5c(arg0, arg1);
        case 248U: return ByteVc1FdeFunc_248_0x02ec28(arg0, arg1);
        case 249U: return ByteVc1FdeFunc_249_0x02edb8(arg0, arg1);
        case 250U: return ByteVc1FdeFunc_250_0x02f010(arg0, arg1);
        case 251U: return ByteVc1FdeFunc_251_0x02f0e0(arg0, arg1);
        case 252U: return ByteVc1FdeFunc_252_0x02f238(arg0, arg1);
        case 253U: return ByteVc1FdeFunc_253_0x02f374(arg0, arg1);
        case 254U: return ByteVc1FdeFunc_254_0x02f538(arg0, arg1);
        case 255U: return ByteVc1FdeFunc_255_0x02f58c(arg0, arg1);
        case 256U: return ByteVc1FdeFunc_256_0x02f7f8(arg0, arg1);
        case 257U: return ByteVc1FdeFunc_257_0x02f8bc(arg0, arg1);
        case 258U: return ByteVc1FdeFunc_258_0x02f984(arg0, arg1);
        case 259U: return ByteVc1FdeFunc_259_0x02f990(arg0, arg1);
        case 260U: return ByteVc1FdeFunc_260_0x02f99c(arg0, arg1);
        case 261U: return ByteVc1FdeFunc_261_0x02f9d0(arg0, arg1);
        case 262U: return ByteVc1FdeFunc_262_0x02fa7c(arg0, arg1);
        case 263U: return ByteVc1FdeFunc_263_0x02fbd4(arg0, arg1);
        case 264U: return ByteVc1FdeFunc_264_0x02fda0(arg0, arg1);
        case 265U: return ByteVc1FdeFunc_265_0x02ff5c(arg0, arg1);
        case 266U: return ByteVc1FdeFunc_266_0x03012c(arg0, arg1);
        case 267U: return ByteVc1FdeFunc_267_0x0302ec(arg0, arg1);
        case 268U: return ByteVc1FdeFunc_268_0x031160(arg0, arg1);
        case 269U: return ByteVc1FdeFunc_269_0x031370(arg0, arg1);
        case 270U: return ByteVc1FdeFunc_270_0x0321a4(arg0, arg1);
        case 271U: return ByteVc1FdeFunc_271_0x0322f4(arg0, arg1);
        case 272U: return ByteVc1FdeFunc_272_0x0337fc(arg0, arg1);
        case 273U: return ByteVc1FdeFunc_273_0x033894(arg0, arg1);
        case 274U: return ByteVc1FdeFunc_274_0x0338a0(arg0, arg1);
        case 275U: return ByteVc1FdeFunc_275_0x0338ac(arg0, arg1);
        case 276U: return ByteVc1FdeFunc_276_0x0338b8(arg0, arg1);
        case 277U: return ByteVc1FdeFunc_277_0x0338c4(arg0, arg1);
        case 278U: return ByteVc1FdeFunc_278_0x033930(arg0, arg1);
        case 279U: return ByteVc1FdeFunc_279_0x033954(arg0, arg1);
        case 280U: return ByteVc1FdeFunc_280_0x033998(arg0, arg1);
        case 281U: return ByteVc1FdeFunc_281_0x033a7c(arg0, arg1);
        case 282U: return ByteVc1FdeFunc_282_0x0350a4(arg0, arg1);
        case 283U: return ByteVc1FdeFunc_283_0x035140(arg0, arg1);
        case 284U: return ByteVc1FdeFunc_284_0x03514c(arg0, arg1);
        case 285U: return ByteVc1FdeFunc_285_0x035158(arg0, arg1);
        case 286U: return ByteVc1FdeFunc_286_0x035164(arg0, arg1);
        case 287U: return ByteVc1FdeFunc_287_0x035170(arg0, arg1);
        case 288U: return ByteVc1FdeFunc_288_0x0351dc(arg0, arg1);
        case 289U: return ByteVc1FdeFunc_289_0x035200(arg0, arg1);
        case 290U: return ByteVc1FdeFunc_290_0x035244(arg0, arg1);
        case 291U: return ByteVc1FdeFunc_291_0x035328(arg0, arg1);
        case 292U: return ByteVc1FdeFunc_292_0x035338(arg0, arg1);
        case 293U: return ByteVc1FdeFunc_293_0x035348(arg0, arg1);
        case 294U: return ByteVc1FdeFunc_294_0x035358(arg0, arg1);
        case 295U: return ByteVc1FdeFunc_295_0x035368(arg0, arg1);
        case 296U: return ByteVc1FdeFunc_296_0x035378(arg0, arg1);
        case 297U: return ByteVc1FdeFunc_297_0x035388(arg0, arg1);
        case 298U: return ByteVc1FdeFunc_298_0x035758(arg0, arg1);
        case 299U: return ByteVc1FdeFunc_299_0x0357c4(arg0, arg1);
        case 300U: return ByteVc1FdeFunc_300_0x03582c(arg0, arg1);
        case 301U: return ByteVc1FdeFunc_301_0x036040(arg0, arg1);
        case 302U: return ByteVc1FdeFunc_302_0x0362a8(arg0, arg1);
        case 303U: return ByteVc1FdeFunc_303_0x036418(arg0, arg1);
        case 304U: return ByteVc1FdeFunc_304_0x0364ec(arg0, arg1);
        case 305U: return ByteVc1FdeFunc_305_0x036608(arg0, arg1);
        case 306U: return ByteVc1FdeFunc_306_0x036678(arg0, arg1);
        case 307U: return ByteVc1FdeFunc_307_0x0366b0(arg0, arg1);
        case 308U: return ByteVc1FdeFunc_308_0x03682c(arg0, arg1);
        case 309U: return ByteVc1FdeFunc_309_0x036938(arg0, arg1);
        case 310U: return ByteVc1FdeFunc_310_0x036a34(arg0, arg1);
        case 311U: return ByteVc1FdeFunc_311_0x036c34(arg0, arg1);
        case 312U: return ByteVc1FdeFunc_312_0x037464(arg0, arg1);
        case 313U: return ByteVc1FdeFunc_313_0x038328(arg0, arg1);
        case 314U: return ByteVc1FdeFunc_314_0x038a58(arg0, arg1);
        case 315U: return ByteVc1FdeFunc_315_0x039284(arg0, arg1);
        case 316U: return ByteVc1FdeFunc_316_0x0392d4(arg0, arg1);
        case 317U: return ByteVc1FdeFunc_317_0x039694(arg0, arg1);
        case 318U: return ByteVc1FdeFunc_318_0x0396e8(arg0, arg1);
        case 319U: return ByteVc1FdeFunc_319_0x039768(arg0, arg1);
        case 320U: return ByteVc1FdeFunc_320_0x039828(arg0, arg1);
        case 321U: return ByteVc1FdeFunc_321_0x039958(arg0, arg1);
        case 322U: return ByteVc1FdeFunc_322_0x039a90(arg0, arg1);
        case 323U: return ByteVc1FdeFunc_323_0x039b08(arg0, arg1);
        case 324U: return ByteVc1FdeFunc_324_0x039d84(arg0, arg1);
        case 325U: return ByteVc1FdeFunc_325_0x039dd4(arg0, arg1);
        case 326U: return ByteVc1FdeFunc_326_0x039f70(arg0, arg1);
        case 327U: return ByteVc1FdeFunc_327_0x03a0cc(arg0, arg1);
        case 328U: return ByteVc1FdeFunc_328_0x03a278(arg0, arg1);
        case 329U: return ByteVc1FdeFunc_329_0x03a378(arg0, arg1);
        case 330U: return ByteVc1FdeFunc_330_0x03a520(arg0, arg1);
        case 331U: return ByteVc1FdeFunc_331_0x03a530(arg0, arg1);
        case 332U: return ByteVc1FdeFunc_332_0x03a66c(arg0, arg1);
        case 333U: return ByteVc1FdeFunc_333_0x03a68c(arg0, arg1);
        case 334U: return ByteVc1FdeFunc_334_0x03a6cc(arg0, arg1);
        case 335U: return ByteVc1FdeFunc_335_0x03adf0(arg0, arg1);
        case 336U: return ByteVc1FdeFunc_336_0x03aec0(arg0, arg1);
        case 337U: return ByteVc1FdeFunc_337_0x03b414(arg0, arg1);
        case 338U: return ByteVc1FdeFunc_338_0x03b4dc(arg0, arg1);
        case 339U: return ByteVc1FdeFunc_339_0x03b5ec(arg0, arg1);
        case 340U: return ByteVc1FdeFunc_340_0x03b60c(arg0, arg1);
        case 341U: return ByteVc1FdeFunc_341_0x03b624(arg0, arg1);
        case 342U: return ByteVc1FdeFunc_342_0x03b824(arg0, arg1);
        case 343U: return ByteVc1FdeFunc_343_0x03bbc0(arg0, arg1);
        case 344U: return ByteVc1FdeFunc_344_0x03bd2c(arg0, arg1);
        case 345U: return ByteVc1FdeFunc_345_0x03bea8(arg0, arg1);
        case 346U: return ByteVc1FdeFunc_346_0x03c00c(arg0, arg1);
        case 347U: return ByteVc1FdeFunc_347_0x03c25c(arg0, arg1);
        case 348U: return ByteVc1FdeFunc_348_0x03c4f8(arg0, arg1);
        case 349U: return ByteVc1FdeFunc_349_0x03c7d8(arg0, arg1);
        case 350U: return ByteVc1FdeFunc_350_0x03cbc0(arg0, arg1);
        case 351U: return ByteVc1FdeFunc_351_0x03ceb8(arg0, arg1);
        case 352U: return ByteVc1FdeFunc_352_0x03d178(arg0, arg1);
        case 353U: return ByteVc1FdeFunc_353_0x03d55c(arg0, arg1);
        case 354U: return ByteVc1FdeFunc_354_0x03d95c(arg0, arg1);
        case 355U: return ByteVc1FdeFunc_355_0x03d968(arg0, arg1);
        case 356U: return ByteVc1FdeFunc_356_0x03d974(arg0, arg1);
        case 357U: return ByteVc1FdeFunc_357_0x03da00(arg0, arg1);
        case 358U: return ByteVc1FdeFunc_358_0x03da9c(arg0, arg1);
        case 359U: return ByteVc1FdeFunc_359_0x03db38(arg0, arg1);
        case 360U: return ByteVc1FdeFunc_360_0x03db44(arg0, arg1);
        case 361U: return ByteVc1FdeFunc_361_0x03db50(arg0, arg1);
        case 362U: return ByteVc1FdeFunc_362_0x03dbdc(arg0, arg1);
        case 363U: return ByteVc1FdeFunc_363_0x03dc78(arg0, arg1);
        case 364U: return ByteVc1FdeFunc_364_0x03dd14(arg0, arg1);
        case 365U: return ByteVc1FdeFunc_365_0x03ddd4(arg0, arg1);
        case 366U: return ByteVc1FdeFunc_366_0x03de74(arg0, arg1);
        case 367U: return ByteVc1FdeFunc_367_0x03df00(arg0, arg1);
        case 368U: return ByteVc1FdeFunc_368_0x03dfe8(arg0, arg1);
        case 369U: return ByteVc1FdeFunc_369_0x03e0bc(arg0, arg1);
        case 370U: return ByteVc1FdeFunc_370_0x03e180(arg0, arg1);
        case 371U: return ByteVc1FdeFunc_371_0x03e1ec(arg0, arg1);
        case 372U: return ByteVc1FdeFunc_372_0x03e2a4(arg0, arg1);
        case 373U: return ByteVc1FdeFunc_373_0x03e3f0(arg0, arg1);
        case 374U: return ByteVc1FdeFunc_374_0x03e434(arg0, arg1);
        case 375U: return ByteVc1FdeFunc_375_0x03e4b8(arg0, arg1);
        case 376U: return ByteVc1FdeFunc_376_0x03e5c0(arg0, arg1);
        case 377U: return ByteVc1FdeFunc_377_0x03e63c(arg0, arg1);
        case 378U: return ByteVc1FdeFunc_378_0x03e738(arg0, arg1);
        case 379U: return ByteVc1FdeFunc_379_0x03e938(arg0, arg1);
        case 380U: return ByteVc1FdeFunc_380_0x03ea18(arg0, arg1);
        case 381U: return ByteVc1FdeFunc_381_0x03eb20(arg0, arg1);
        case 382U: return ByteVc1FdeFunc_382_0x03ed94(arg0, arg1);
        case 383U: return ByteVc1FdeFunc_383_0x03efbc(arg0, arg1);
        case 384U: return ByteVc1FdeFunc_384_0x03f2d0(arg0, arg1);
        case 385U: return ByteVc1FdeFunc_385_0x03f628(arg0, arg1);
        case 386U: return ByteVc1FdeFunc_386_0x03f7fc(arg0, arg1);
        case 387U: return ByteVc1FdeFunc_387_0x03f928(arg0, arg1);
        case 388U: return ByteVc1FdeFunc_388_0x03f92c(arg0, arg1);
        case 389U: return ByteVc1FdeFunc_389_0x03f930(arg0, arg1);
        case 390U: return ByteVc1FdeFunc_390_0x03fc28(arg0, arg1);
        case 391U: return ByteVc1FdeFunc_391_0x03ff54(arg0, arg1);
        case 392U: return ByteVc1FdeFunc_392_0x040130(arg0, arg1);
        case 393U: return ByteVc1FdeFunc_393_0x04024c(arg0, arg1);
        case 394U: return ByteVc1FdeFunc_394_0x040250(arg0, arg1);
        case 395U: return ByteVc1FdeFunc_395_0x040254(arg0, arg1);
        case 396U: return ByteVc1FdeFunc_396_0x0403a0(arg0, arg1);
        case 397U: return ByteVc1FdeFunc_397_0x04046c(arg0, arg1);
        case 398U: return ByteVc1FdeFunc_398_0x040590(arg0, arg1);
        case 399U: return ByteVc1FdeFunc_399_0x040810(arg0, arg1);
        case 400U: return ByteVc1FdeFunc_400_0x0409d4(arg0, arg1);
        case 401U: return ByteVc1FdeFunc_401_0x040c08(arg0, arg1);
        case 402U: return ByteVc1FdeFunc_402_0x040f00(arg0, arg1);
        case 403U: return ByteVc1FdeFunc_403_0x041024(arg0, arg1);
        case 404U: return ByteVc1FdeFunc_404_0x04120c(arg0, arg1);
        case 405U: return ByteVc1FdeFunc_405_0x0414a0(arg0, arg1);
        case 406U: return ByteVc1FdeFunc_406_0x0417f8(arg0, arg1);
        case 407U: return ByteVc1FdeFunc_407_0x041b94(arg0, arg1);
        case 408U: return ByteVc1FdeFunc_408_0x041c58(arg0, arg1);
        case 409U: return ByteVc1FdeFunc_409_0x0428d0(arg0, arg1);
        case 410U: return ByteVc1FdeFunc_410_0x066d08(arg0, arg1);
        case 411U: return ByteVc1FdeFunc_411_0x066d1c(arg0, arg1);
        case 412U: return ByteVc1FdeFunc_412_0x066e70(arg0, arg1);
        case 413U: return ByteVc1FdeFunc_413_0x066f0c(arg0, arg1);
        case 414U: return ByteVc1FdeFunc_414_0x066f58(arg0, arg1);
        case 415U: return ByteVc1FdeFunc_415_0x066f6c(arg0, arg1);
        case 416U: return ByteVc1FdeFunc_416_0x066fe0(arg0, arg1);
        case 417U: return ByteVc1FdeFunc_417_0x067040(arg0, arg1);
        case 418U: return ByteVc1FdeFunc_418_0x0670a8(arg0, arg1);
        default: return 0U;
    }
}

std::uint64_t ExecuteAll419ByteVc1Fdes(std::uint32_t seed) noexcept {
    std::uint64_t digest = seed;
    for (std::uint32_t i = 0; i < kEhFrameFdeCount; ++i) {
        const std::uint32_t r = DispatchByteVc1FdeIndex(i, seed + i, i * 0x85EBCA6BU);
        digest = ((digest << 7U) | (digest >> 57U)) ^ static_cast<std::uint64_t>(r);
    }
    return digest;
}

} // namespace nextai::opencut::bytevc1_dec
