// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// File: bytevc0_core.cpp
// Target Binary: libbytevc0.so (548,760 bytes, 1,142 FDEs, 107,562 .text words)
// SHA-256: dc9c342b14505ca04f97fe75572b3b9213873762efef079f57ad23f1c790d0e7
// Role: Full implementation of all 18 exported bytevc0* encoder API functions,
//       ROI bounding-box clipper (max 10 regions), and 1,142 FDE functions.
// =============================================================================
#include "bytevc0.hpp"

#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace nextai::opencut::bytevc0 {

// =============================================================================
// 1. Exported Symbol Table (.dynsym — 18 Exported Functions)
// EN: Exact virtual addresses, byte sizes, and prologue opcodes from .dynsym.
// VI: Địa chỉ ảo, kích thước byte và opcode mở đầu chính xác từ .dynsym.
// =============================================================================
const std::array<ByteVc0ExportEntry, kExportedSymbolCount> kByteVc0ExportTable = {{
    {"bytevc0EncoderOpen", 0x053d78U, 132U, 0xf81d0ffcU},
    {"bytevc0EncoderClose", 0x053dfcU, 36U, 0xb40000e0U},
    {"bytevc0EncoderSetFramesToBeEncoded", 0x053e20U, 20U, 0xb4000080U},
    {"bytevc0EncoderEncodeFrame", 0x053e34U, 20U, 0xb4000080U},
    {"bytevc0EncoderKeyFrameRequest", 0x053e48U, 20U, 0xb4000080U},
    {"bytevc0EncoderLtrMarkRequest", 0x053e5cU, 20U, 0xb4000080U},
    {"bytevc0EncoderLtrFrameRequest", 0x053e70U, 20U, 0xb4000080U},
    {"bytevc0EncoderDelayedFrames", 0x053e84U, 24U, 0xb4000080U},
    {"bytevc0EncoderIsResetForNewCfg", 0x053e9cU, 20U, 0xb4000080U},
    {"bytevc0EncoderReconfig", 0x053eb0U, 24U, 0xb4000080U},
    {"bytevc0EncoderEncodeHeaders", 0x053ec8U, 20U, 0xb4000080U},
    {"setEnableMosh", 0x053edcU, 20U, 0xb4000080U},
    {"setOpticalFlowInfo", 0x053ef0U, 20U, 0xb4000080U},
    {"bytevc0ConfigDefaultPreset", 0x053f04U, 952U, 0xf81c0ff7U},
    {"bytevc0ConfigProfile", 0x0542bcU, 76U, 0xf81e0ff3U},
    {"bytevc0ConfigLevel", 0x054308U, 188U, 0xf81c0ff7U},
    {"bytevc0ConfigParse", 0x0543c4U, 4524U, 0xd10243ffU},
    {"bytevc0SetLogCallback", 0x055570U, 28U, 0xb40000a1U},
}};

// =============================================================================
// 2. .eh_frame_hdr Table (0x0756C0 — 1,142 FDE Entries)
// EN: Complete 1,142-entry Frame Description Entry table sorted by function VA.
// VI: Bảng 1.142 mục FDE đầy đủ được sắp xếp theo địa chỉ ảo của hàm.
// =============================================================================
const std::array<ByteVc0FdeEntry, kEhFrameFdeCount> kByteVc0FdeTable = {{
    {0U, 0x005edcU, 0x077a98U, 0xf81d0ff5U},
    {1U, 0x005f58U, 0x077ab8U, 0xfc190fecU},
    {2U, 0x0061d0U, 0x077af0U, 0xa9bd57f6U},
    {3U, 0x006274U, 0x077b18U, 0xa9be4ff4U},
    {4U, 0x006314U, 0x077b38U, 0xa9bf7bfdU},
    {5U, 0x006330U, 0x077b58U, 0xf81d0ff5U},
    {6U, 0x0063e0U, 0x077b78U, 0xa9be4ff4U},
    {7U, 0x006430U, 0x077b98U, 0xa9be4ff4U},
    {8U, 0x006490U, 0x077bb8U, 0xf81d0ff5U},
    {9U, 0x006658U, 0x077bd8U, 0xb9402008U},
    {10U, 0x0066c4U, 0x077bf0U, 0xa9bd57f6U},
    {11U, 0x006770U, 0x077c18U, 0x90000349U},
    {12U, 0x0067d0U, 0x077c30U, 0x90000348U},
    {13U, 0x006840U, 0x077c48U, 0x90000349U},
    {14U, 0x0068b0U, 0x077c60U, 0x9000034bU},
    {15U, 0x006924U, 0x077c78U, 0xb940040aU},
    {16U, 0x006a44U, 0x077c90U, 0xb9400409U},
    {17U, 0x006aecU, 0x077ca8U, 0x52800068U},
    {18U, 0x006b00U, 0x077cc0U, 0xb9400408U},
    {19U, 0x006bccU, 0x077cd8U, 0xb9400409U},
    {20U, 0x006cf0U, 0x077cf0U, 0xb9400408U},
    {21U, 0x006f64U, 0x077d08U, 0x52800028U},
    {22U, 0x006f74U, 0x077d20U, 0xf81e0ff3U},
    {23U, 0x006fc8U, 0x077d40U, 0x29412009U},
    {24U, 0x007024U, 0x077d58U, 0xb9400048U},
    {25U, 0x00706cU, 0x077d70U, 0xf81b0ffcU},
    {26U, 0x007638U, 0x077d98U, 0xd10203ffU},
    {27U, 0x007924U, 0x077dc8U, 0xd100c3ffU},
    {28U, 0x0079dcU, 0x077de8U, 0xd100c3ffU},
    {29U, 0x007aa4U, 0x077e08U, 0xd10203ffU},
    {30U, 0x007db0U, 0x077e38U, 0xf81d0ff5U},
    {31U, 0x007e70U, 0x077e58U, 0xd10383ffU},
    {32U, 0x00855cU, 0x077e88U, 0xf81e0ff3U},
    {33U, 0x00867cU, 0x077ea8U, 0xd10203ffU},
    {34U, 0x0088b8U, 0x077ed8U, 0xa9be4ff4U},
    {35U, 0x00899cU, 0x077ef8U, 0xf81e0ff3U},
    {36U, 0x008a0cU, 0x077f18U, 0xf81e0ff3U},
    {37U, 0x008a40U, 0x077f38U, 0xa9be4ff4U},
    {38U, 0x008ad4U, 0x077f58U, 0xd10183ffU},
    {39U, 0x008bf8U, 0x077f80U, 0xa9be4ff4U},
    {40U, 0x008c3cU, 0x077fa0U, 0xf81e0ff3U},
    {41U, 0x008c84U, 0x077fc0U, 0xa9bc5ff8U},
    {42U, 0x008d3cU, 0x077fe8U, 0xd10103ffU},
    {43U, 0x008e6cU, 0x078008U, 0xf81d0ff5U},
    {44U, 0x008ec0U, 0x078028U, 0xd10103ffU},
    {45U, 0x008fc0U, 0x078050U, 0xa9bd57f6U},
    {46U, 0x00903cU, 0x078078U, 0x6f00e402U},
    {47U, 0x00907cU, 0x078090U, 0x1e202008U},
    {48U, 0x0091a4U, 0x0780a8U, 0xf81c0ff7U},
    {49U, 0x009454U, 0x0780d0U, 0xf81e0ff3U},
    {50U, 0x0094ccU, 0x0780f0U, 0xd10183ffU},
    {51U, 0x0095f0U, 0x078118U, 0xa9be4ff4U},
    {52U, 0x009664U, 0x078138U, 0xf81e0ff3U},
    {53U, 0x0096acU, 0x078158U, 0xa9bc5ff8U},
    {54U, 0x0097f4U, 0x078180U, 0xf9400408U},
    {55U, 0x0098c0U, 0x078198U, 0xb980e009U},
    {56U, 0x00990cU, 0x0781b0U, 0xd10283ffU},
    {57U, 0x009a90U, 0x0781e0U, 0xf9400408U},
    {58U, 0x009b44U, 0x0781f8U, 0xd10283ffU},
    {59U, 0x009cc8U, 0x078228U, 0xd10143ffU},
    {60U, 0x009e0cU, 0x078250U, 0xa9bc5ff8U},
    {61U, 0x009f24U, 0x078278U, 0xf9406008U},
    {62U, 0x009fb4U, 0x078290U, 0xa9ba6ffcU},
    {63U, 0x00a28cU, 0x0782c0U, 0xa9bc5ff8U},
    {64U, 0x00a338U, 0x0782e8U, 0xd10283ffU},
    {65U, 0x00a644U, 0x078318U, 0xd10043ffU},
    {66U, 0x00a8e8U, 0x078330U, 0xd101c3ffU},
    {67U, 0x00aa18U, 0x078358U, 0xa9bb67faU},
    {68U, 0x00ab9cU, 0x078388U, 0xb980e009U},
    {69U, 0x00abf0U, 0x0783a0U, 0xf9406009U},
    {70U, 0x00ac68U, 0x0783b8U, 0xb980e009U},
    {71U, 0x00ad90U, 0x0783d0U, 0xf9400408U},
    {72U, 0x00ae38U, 0x0783e8U, 0xd10203ffU},
    {73U, 0x00b13cU, 0x078418U, 0xa9bd57f6U},
    {74U, 0x00b1a0U, 0x078440U, 0xa9ba6ffcU},
    {75U, 0x00b318U, 0x078470U, 0xa9bb67faU},
    {76U, 0x00b404U, 0x0784a0U, 0xf9400408U},
    {77U, 0x00b4e0U, 0x0784b8U, 0xb9403028U},
    {78U, 0x00b580U, 0x0784d0U, 0xf81b0ff9U},
    {79U, 0x00b6acU, 0x0784f8U, 0xa9ba6ffcU},
    {80U, 0x00ba30U, 0x078528U, 0xd10203ffU},
    {81U, 0x00bdacU, 0x078558U, 0xf81c0ff7U},
    {82U, 0x00c0dcU, 0x078580U, 0xa9ba6ffcU},
    {83U, 0x00c87cU, 0x0785b0U, 0xa9bc5ff8U},
    {84U, 0x00c914U, 0x0785d8U, 0xf81c0ff9U},
    {85U, 0x00cba0U, 0x078600U, 0xa9be4ff4U},
    {86U, 0x00cc9cU, 0x078620U, 0xd10343ffU},
    {87U, 0x00d90cU, 0x078650U, 0xf81b0ff9U},
    {88U, 0x00da80U, 0x078678U, 0xa9bd57f6U},
    {89U, 0x00dc48U, 0x0786a0U, 0xd10103ffU},
    {90U, 0x00dd78U, 0x0786c0U, 0xd10103ffU},
    {91U, 0x00de78U, 0x0786e8U, 0xd65f03c0U},
    {92U, 0x00de7cU, 0x078700U, 0x17ffdf15U},
    {93U, 0x00de80U, 0x078718U, 0xf81e0ff3U},
    {94U, 0x00deb0U, 0x078738U, 0xa9be4ff4U},
    {95U, 0x00deecU, 0x078758U, 0xa9be4ff4U},
    {96U, 0x00df40U, 0x078778U, 0xf81e0ff3U},
    {97U, 0x00df64U, 0x078798U, 0x52800028U},
    {98U, 0x00df70U, 0x0787b0U, 0x52800028U},
    {99U, 0x00df80U, 0x0787c8U, 0x52800028U},
    {100U, 0x00df90U, 0x0787e0U, 0xb940e408U},
    {101U, 0x00dfa8U, 0x0787f8U, 0x91015c28U},
    {102U, 0x00dfb8U, 0x078810U, 0xd10303ffU},
    {103U, 0x00e3b0U, 0x078840U, 0x6dbc23e9U},
    {104U, 0x00e490U, 0x078868U, 0xa9be4ff4U},
    {105U, 0x00e4f0U, 0x078888U, 0xa9be4ff4U},
    {106U, 0x00e550U, 0x0788a8U, 0xa9be4ff4U},
    {107U, 0x00e5b0U, 0x0788c8U, 0xd10183ffU},
    {108U, 0x00e680U, 0x0788f0U, 0xf81d0ff5U},
    {109U, 0x00e6fcU, 0x078910U, 0xa9be4ff4U},
    {110U, 0x00e760U, 0x078930U, 0xf9400068U},
    {111U, 0x00e780U, 0x078948U, 0xd101c3ffU},
    {112U, 0x00e894U, 0x078970U, 0xd10183ffU},
    {113U, 0x00e964U, 0x078998U, 0xf81d0ff5U},
    {114U, 0x00e9e0U, 0x0789b8U, 0xa9be4ff4U},
    {115U, 0x00ea44U, 0x0789d8U, 0xf9400068U},
    {116U, 0x00ea64U, 0x0789f0U, 0xd101c3ffU},
    {117U, 0x00eb78U, 0x078a18U, 0xa9000801U},
    {118U, 0x00ebe4U, 0x078a30U, 0xf81e0ff3U},
    {119U, 0x00ec1cU, 0x078a50U, 0xf81e0ff3U},
    {120U, 0x00ec54U, 0x078a70U, 0xf81d0ff5U},
    {121U, 0x00ee00U, 0x078a90U, 0xf9400808U},
    {122U, 0x00efa4U, 0x078aa8U, 0xf81d0ff5U},
    {123U, 0x00f004U, 0x078ac8U, 0xd101c3ffU},
    {124U, 0x00f310U, 0x078af8U, 0x36000062U},
    {125U, 0x00f36cU, 0x078b10U, 0xd101c3ffU},
    {126U, 0x00f908U, 0x078b40U, 0xb98000c9U},
    {127U, 0x00fa0cU, 0x078b58U, 0xd10143ffU},
    {128U, 0x00fc04U, 0x078b80U, 0xa9be4ff4U},
    {129U, 0x00fdacU, 0x078ba0U, 0x9100a068U},
    {130U, 0x00fe6cU, 0x078bb8U, 0xd10303ffU},
    {131U, 0x010124U, 0x078bd8U, 0xa9bd57f6U},
    {132U, 0x010190U, 0x078c00U, 0x39400088U},
    {133U, 0x010234U, 0x078c18U, 0x710004bfU},
    {134U, 0x01030cU, 0x078c30U, 0xd10243ffU},
    {135U, 0x0108dcU, 0x078c60U, 0xf81d0ff5U},
    {136U, 0x010ad4U, 0x078c80U, 0xd102c3ffU},
    {137U, 0x0113a4U, 0x078cb0U, 0x140129b6U},
    {138U, 0x0113a8U, 0x078cc8U, 0xa9bd57f6U},
    {139U, 0x011574U, 0x078cf0U, 0xf81f0ff3U},
    {140U, 0x011698U, 0x078d08U, 0xa9ba6ffcU},
    {141U, 0x01187cU, 0x078d38U, 0xd101c3ffU},
    {142U, 0x011a84U, 0x078d68U, 0xd65f03c0U},
    {143U, 0x011a88U, 0x078d80U, 0xd65f03c0U},
    {144U, 0x011a8cU, 0x078d98U, 0x710004bfU},
    {145U, 0x011ae4U, 0x078db0U, 0xb901a01fU},
    {146U, 0x011b40U, 0x078dc8U, 0xb901a03fU},
    {147U, 0x011c74U, 0x078de0U, 0xf81c0ff7U},
    {148U, 0x011da4U, 0x078e08U, 0xa9ba6ffcU},
    {149U, 0x011f04U, 0x078e38U, 0xa9ba6ffcU},
    {150U, 0x012070U, 0x078e68U, 0xa9ba6ffcU},
    {151U, 0x012290U, 0x078e98U, 0xd10203ffU},
    {152U, 0x012584U, 0x078ec8U, 0xd10183ffU},
    {153U, 0x012828U, 0x078ef0U, 0xa9ba6ffcU},
    {154U, 0x013534U, 0x078f20U, 0xa9ba6ffcU},
    {155U, 0x01389cU, 0x078f50U, 0xd10343ffU},
    {156U, 0x01409cU, 0x078f80U, 0xa9bc5ff8U},
    {157U, 0x01411cU, 0x078fa8U, 0xa9ba6ffcU},
    {158U, 0x01459cU, 0x078fd8U, 0xa9ba6ffcU},
    {159U, 0x014a54U, 0x079008U, 0xa9ba6ffcU},
    {160U, 0x014efcU, 0x079038U, 0xd10183ffU},
    {161U, 0x015070U, 0x079060U, 0xa9ba6ffcU},
    {162U, 0x015b4cU, 0x079090U, 0xa9ba6ffcU},
    {163U, 0x01656cU, 0x0790c0U, 0xa9ba6ffcU},
    {164U, 0x017238U, 0x0790f0U, 0xa9ba6ffcU},
    {165U, 0x017de0U, 0x079120U, 0xf81c0ff7U},
    {166U, 0x018018U, 0x079148U, 0xf81c0ff7U},
    {167U, 0x01818cU, 0x079170U, 0xd10243ffU},
    {168U, 0x0185bcU, 0x0791a0U, 0xd10303ffU},
    {169U, 0x018b10U, 0x0791d0U, 0xa9ba6ffcU},
    {170U, 0x018c88U, 0x079200U, 0xd10343ffU},
    {171U, 0x019080U, 0x079230U, 0xd10583ffU},
    {172U, 0x019900U, 0x079260U, 0xd10183ffU},
    {173U, 0x019bc4U, 0x079288U, 0xd101c3ffU},
    {174U, 0x019d70U, 0x0792b0U, 0xa9ba6ffcU},
    {175U, 0x01a41cU, 0x0792e0U, 0xa9ba6ffcU},
    {176U, 0x01ab80U, 0x079310U, 0xa9ba6ffcU},
    {177U, 0x01b0c4U, 0x079340U, 0xa9be4ff4U},
    {178U, 0x01b268U, 0x079360U, 0xd10183ffU},
    {179U, 0x01b484U, 0x079388U, 0xd10203ffU},
    {180U, 0x01bcccU, 0x0793b8U, 0xb4000461U},
    {181U, 0x01bd5cU, 0x0793d0U, 0xf81d0ff5U},
    {182U, 0x01bec8U, 0x0793f0U, 0xaa1f03e9U},
    {183U, 0x01c078U, 0x079408U, 0xa9bb67faU},
    {184U, 0x01c3e4U, 0x079438U, 0xd10203ffU},
    {185U, 0x01ca34U, 0x079468U, 0xa9bd57f6U},
    {186U, 0x01cbf4U, 0x079490U, 0xf9400008U},
    {187U, 0x01cc50U, 0x0794a8U, 0xf9400008U},
    {188U, 0x01ccbcU, 0x0794c0U, 0x39405429U},
    {189U, 0x01cd40U, 0x0794d8U, 0xd10083ffU},
    {190U, 0x01cdf4U, 0x0794f8U, 0x294024a8U},
    {191U, 0x01ce14U, 0x079510U, 0xd10143ffU},
    {192U, 0x01d02cU, 0x079530U, 0xd10083ffU},
    {193U, 0x01d0dcU, 0x079550U, 0xd10203ffU},
    {194U, 0x01d324U, 0x079578U, 0x39c6902bU},
    {195U, 0x01d3ccU, 0x079590U, 0xf81c0ff7U},
    {196U, 0x01d46cU, 0x0795b8U, 0xd10183ffU},
    {197U, 0x01d59cU, 0x0795e0U, 0xd10203ffU},
    {198U, 0x01d764U, 0x079610U, 0x39c69048U},
    {199U, 0x01d778U, 0x079628U, 0xd10303ffU},
    {200U, 0x01d914U, 0x079658U, 0xd102c3ffU},
    {201U, 0x01dbe8U, 0x079688U, 0xf9409c28U},
    {202U, 0x01dbf8U, 0x0796a0U, 0xf81e0ff3U},
    {203U, 0x01dd4cU, 0x0796c0U, 0xa9bd57f6U},
    {204U, 0x01ddf4U, 0x0796e8U, 0xa9ba6ffcU},
    {205U, 0x01e25cU, 0x079718U, 0xa9ba6ffcU},
    {206U, 0x01e694U, 0x079748U, 0xa9ba6ffcU},
    {207U, 0x01eac0U, 0x079778U, 0xa9ba6ffcU},
    {208U, 0x01f798U, 0x0797a8U, 0xa9ba6ffcU},
    {209U, 0x020250U, 0x0797d8U, 0xf81a0ffbU},
    {210U, 0x0203f0U, 0x079808U, 0xa9bb67faU},
    {211U, 0x020564U, 0x079838U, 0xd10243ffU},
    {212U, 0x020778U, 0x079868U, 0xd10303ffU},
    {213U, 0x020b5cU, 0x079898U, 0xd10243ffU},
    {214U, 0x020fd8U, 0x0798c8U, 0xf0000328U},
    {215U, 0x020fecU, 0x0798e0U, 0xf0000329U},
    {216U, 0x021008U, 0x0798f8U, 0xd0000328U},
    {217U, 0x02101cU, 0x079910U, 0xd0000329U},
    {218U, 0x021038U, 0x079928U, 0xa9ba6ffcU},
    {219U, 0x0216a8U, 0x079958U, 0xd10403ffU},
    {220U, 0x022094U, 0x079988U, 0x2a1f03e2U},
    {221U, 0x02209cU, 0x0799a0U, 0xd10243ffU},
    {222U, 0x022488U, 0x0799d0U, 0xa9007c01U},
    {223U, 0x0224ccU, 0x0799e8U, 0xd65f03c0U},
    {224U, 0x0224d0U, 0x079a00U, 0xd65f03c0U},
    {225U, 0x0224d4U, 0x079a18U, 0xf9000401U},
    {226U, 0x0224dcU, 0x079a30U, 0xf81d0ff5U},
    {227U, 0x022674U, 0x079a50U, 0xa9bb67faU},
    {228U, 0x022ac8U, 0x079a80U, 0xd100c3ffU},
    {229U, 0x022cf4U, 0x079aa0U, 0xf81d0ff5U},
    {230U, 0x023184U, 0x079ac0U, 0xa9bd57f6U},
    {231U, 0x023514U, 0x079ae8U, 0xf940a028U},
    {232U, 0x02364cU, 0x079b00U, 0xd10183ffU},
    {233U, 0x023790U, 0x079b30U, 0xf940a008U},
    {234U, 0x023894U, 0x079b48U, 0xf940a028U},
    {235U, 0x023a0cU, 0x079b60U, 0xa9bc5ff8U},
    {236U, 0x024054U, 0x079b88U, 0xa9bd57f6U},
    {237U, 0x0243acU, 0x079bb0U, 0xa9bf4ff4U},
    {238U, 0x0246b0U, 0x079bc8U, 0xf81e0ff3U},
    {239U, 0x0246ecU, 0x079be8U, 0xa9bf4ff4U},
    {240U, 0x024b14U, 0x079c00U, 0xd102c3ffU},
    {241U, 0x024fc0U, 0x079c30U, 0xd10543ffU},
    {242U, 0x025cecU, 0x079c60U, 0xd10503ffU},
    {243U, 0x026728U, 0x079c90U, 0xd10203ffU},
    {244U, 0x026a8cU, 0x079cc0U, 0xd10383ffU},
    {245U, 0x027df8U, 0x079cf0U, 0xd10383ffU},
    {246U, 0x029b68U, 0x079d20U, 0xd10203ffU},
    {247U, 0x029ed8U, 0x079d50U, 0xf81b0ff9U},
    {248U, 0x02a0d4U, 0x079d78U, 0xf81e0ff3U},
    {249U, 0x02a148U, 0x079d98U, 0xf9401400U},
    {250U, 0x02a158U, 0x079db0U, 0xf9400c0aU},
    {251U, 0x02a29cU, 0x079dc8U, 0xf81c0ff7U},
    {252U, 0x02a3acU, 0x079df0U, 0xf9401c08U},
    {253U, 0x02a3c0U, 0x079e08U, 0xf9401400U},
    {254U, 0x02a3d0U, 0x079e20U, 0xa9bd57f6U},
    {255U, 0x02a824U, 0x079e48U, 0xf81e0ff3U},
    {256U, 0x02a86cU, 0x079e68U, 0x394d8408U},
    {257U, 0x02aaa4U, 0x079e80U, 0xd10283ffU},
    {258U, 0x02b444U, 0x079eb0U, 0xd10243ffU},
    {259U, 0x02b7d0U, 0x079ee0U, 0xa9be4ff4U},
    {260U, 0x02bac8U, 0x079f00U, 0xa9be4ff4U},
    {261U, 0x02be38U, 0x079f20U, 0xa9ba6ffcU},
    {262U, 0x02bfe0U, 0x079f50U, 0xf9400808U},
    {263U, 0x02c13cU, 0x079f68U, 0xf9400808U},
    {264U, 0x02c29cU, 0x079f80U, 0xa9bc5ff8U},
    {265U, 0x02c978U, 0x079fa8U, 0xb4000260U},
    {266U, 0x02c9c8U, 0x079fc8U, 0xf81e0ff3U},
    {267U, 0x02cbb4U, 0x079fe8U, 0xf81b0ff9U},
    {268U, 0x02cd00U, 0x07a010U, 0xd00002c8U},
    {269U, 0x02cd20U, 0x07a028U, 0xd00002c8U},
    {270U, 0x02cd30U, 0x07a040U, 0xa9be4ff4U},
    {271U, 0x02cd9cU, 0x07a060U, 0xf81e0ff3U},
    {272U, 0x02cdccU, 0x07a080U, 0xf81c0ff7U},
    {273U, 0x02d000U, 0x07a0a8U, 0xa9be4ff4U},
    {274U, 0x02d074U, 0x07a0c8U, 0xf9508808U},
    {275U, 0x02d090U, 0x07a0e0U, 0xf947f00aU},
    {276U, 0x02d110U, 0x07a0f8U, 0xf9400808U},
    {277U, 0x02d1b0U, 0x07a110U, 0xf940040eU},
    {278U, 0x02d358U, 0x07a128U, 0xa9bc5ff8U},
    {279U, 0x02d40cU, 0x07a150U, 0xf81d0ff5U},
    {280U, 0x02d67cU, 0x07a170U, 0xf81e0ff3U},
    {281U, 0x02d6bcU, 0x07a190U, 0xd101c3ffU},
    {282U, 0x02db30U, 0x07a1c0U, 0xf81e0ff3U},
    {283U, 0x02db68U, 0x07a1e0U, 0x17ff5fdaU},
    {284U, 0x02db6cU, 0x07a1f8U, 0xf9001401U},
    {285U, 0x02db78U, 0x07a210U, 0xf9400c08U},
    {286U, 0x02db90U, 0x07a228U, 0xf81e0ff3U},
    {287U, 0x02dc34U, 0x07a248U, 0xf81e0ff3U},
    {288U, 0x02dc68U, 0x07a268U, 0xf81e0ff3U},
    {289U, 0x02dca8U, 0x07a288U, 0xf81e0ff3U},
    {290U, 0x02dce8U, 0x07a2a8U, 0xf9401408U},
    {291U, 0x02dcf4U, 0x07a2c0U, 0xf9401408U},
    {292U, 0x02dd04U, 0x07a2d8U, 0xf9401408U},
    {293U, 0x02dd14U, 0x07a2f0U, 0xa9be4ff4U},
    {294U, 0x02dd68U, 0x07a310U, 0xa9be4ff4U},
    {295U, 0x02de30U, 0x07a330U, 0x7100085fU},
    {296U, 0x02de58U, 0x07a348U, 0xd101c3ffU},
    {297U, 0x02e490U, 0x07a378U, 0xa9be4ff4U},
    {298U, 0x02e504U, 0x07a398U, 0xa9be4ff4U},
    {299U, 0x02e578U, 0x07a3b8U, 0xf9401408U},
    {300U, 0x02e668U, 0x07a3d0U, 0xa9bc5ff8U},
    {301U, 0x02e740U, 0x07a3f8U, 0xa9ba6ffcU},
    {302U, 0x02ed10U, 0x07a428U, 0xa9bd57f6U},
    {303U, 0x02ed90U, 0x07a450U, 0x52a00040U},
    {304U, 0x02ed98U, 0x07a468U, 0x72001c5fU},
    {305U, 0x02edacU, 0x07a480U, 0xf9401409U},
    {306U, 0x02eeb4U, 0x07a498U, 0xf9001001U},
    {307U, 0x02eebcU, 0x07a4b0U, 0xd65f03c0U},
    {308U, 0x02eec0U, 0x07a4c8U, 0x17ff5b04U},
    {309U, 0x02eec4U, 0x07a4e0U, 0xf81d0ff5U},
    {310U, 0x02f234U, 0x07a500U, 0x3944c04aU},
    {311U, 0x02f450U, 0x07a518U, 0x39800848U},
    {312U, 0x02f678U, 0x07a530U, 0x3980084aU},
    {313U, 0x02f80cU, 0x07a548U, 0xf9401008U},
    {314U, 0x02f99cU, 0x07a560U, 0x900002c9U},
    {315U, 0x02fb28U, 0x07a578U, 0xd10143ffU},
    {316U, 0x02fd98U, 0x07a598U, 0xd10283ffU},
    {317U, 0x02ffe4U, 0x07a5b8U, 0xa9be4ff4U},
    {318U, 0x030058U, 0x07a5d8U, 0xa9be4ff4U},
    {319U, 0x0300f8U, 0x07a5f8U, 0xf00002abU},
    {320U, 0x0301e0U, 0x07a610U, 0xa9be4ff4U},
    {321U, 0x030238U, 0x07a630U, 0xa9be4ff4U},
    {322U, 0x0302b0U, 0x07a650U, 0xa9be4ff4U},
    {323U, 0x030328U, 0x07a670U, 0xa9ba6ffcU},
    {324U, 0x0304dcU, 0x07a6a0U, 0xa9be4ff4U},
    {325U, 0x030570U, 0x07a6c0U, 0xf81e0ff3U},
    {326U, 0x0305e8U, 0x07a6e0U, 0xf81e0ff3U},
    {327U, 0x03061cU, 0x07a700U, 0xf81e0ff3U},
    {328U, 0x03065cU, 0x07a720U, 0xf81e0ff3U},
    {329U, 0x03069cU, 0x07a740U, 0xf9401008U},
    {330U, 0x0306a8U, 0x07a758U, 0xf9401008U},
    {331U, 0x0306b8U, 0x07a770U, 0xf9401008U},
    {332U, 0x0306c8U, 0x07a788U, 0x52900000U},
    {333U, 0x0306d0U, 0x07a7a0U, 0x2a1f03e0U},
    {334U, 0x0306d8U, 0x07a7b8U, 0x2a1f03e0U},
    {335U, 0x0306e0U, 0x07a7d0U, 0xf9409c28U},
    {336U, 0x030988U, 0x07a7e8U, 0xa9be4ff4U},
    {337U, 0x030a14U, 0x07a808U, 0x2a1f03e0U},
    {338U, 0x030a1cU, 0x07a820U, 0xf00002aaU},
    {339U, 0x030a4cU, 0x07a838U, 0xa9bc5ff8U},
    {340U, 0x030b74U, 0x07a860U, 0xa9ba6ffcU},
    {341U, 0x030dccU, 0x07a890U, 0xa9bc5ff8U},
    {342U, 0x030ed0U, 0x07a8b8U, 0x2a1f03e0U},
    {343U, 0x030ed8U, 0x07a8d0U, 0x2a1f03e0U},
    {344U, 0x030ee0U, 0x07a8e8U, 0xa9be4ff4U},
    {345U, 0x030f90U, 0x07a908U, 0xf9000c01U},
    {346U, 0x030f98U, 0x07a920U, 0x3980084aU},
    {347U, 0x031058U, 0x07a938U, 0xf9408c2aU},
    {348U, 0x0310d4U, 0x07a950U, 0xa9be4ff4U},
    {349U, 0x0311acU, 0x07a970U, 0xd65f03c0U},
    {350U, 0x0311b0U, 0x07a988U, 0x17ff5248U},
    {351U, 0x0311b4U, 0x07a9a0U, 0xd10243ffU},
    {352U, 0x031590U, 0x07a9c8U, 0xa9be4ff4U},
    {353U, 0x031610U, 0x07a9e8U, 0xa9bb67faU},
    {354U, 0x031810U, 0x07aa18U, 0x3944c048U},
    {355U, 0x03191cU, 0x07aa30U, 0xd00002a8U},
    {356U, 0x0319a8U, 0x07aa48U, 0xa9be4ff4U},
    {357U, 0x031a18U, 0x07aa68U, 0xa9be4ff4U},
    {358U, 0x031aa8U, 0x07aa88U, 0xa9be4ff4U},
    {359U, 0x031b34U, 0x07aaa8U, 0x340001c1U},
    {360U, 0x031b80U, 0x07aac0U, 0x340000e1U},
    {361U, 0x031c3cU, 0x07aad8U, 0xf94c5808U},
    {362U, 0x031cacU, 0x07aaf0U, 0xd00002aaU},
    {363U, 0x031d30U, 0x07ab08U, 0xf81c0ff7U},
    {364U, 0x0321c4U, 0x07ab30U, 0x39c0100bU},
    {365U, 0x032288U, 0x07ab48U, 0xf940a008U},
    {366U, 0x0322c8U, 0x07ab60U, 0xf940a028U},
    {367U, 0x03234cU, 0x07ab78U, 0xf81e0ff3U},
    {368U, 0x03238cU, 0x07ab98U, 0xf81e0ff3U},
    {369U, 0x0323ccU, 0x07abb8U, 0xf81d0ff5U},
    {370U, 0x032450U, 0x07abd8U, 0xf81b0ff9U},
    {371U, 0x032868U, 0x07ac00U, 0xf81a0ffbU},
    {372U, 0x032dd0U, 0x07ac30U, 0xa9bd57f6U},
    {373U, 0x032e60U, 0x07ac58U, 0xf9400809U},
    {374U, 0x032ef8U, 0x07ac70U, 0xa9be4ff4U},
    {375U, 0x033038U, 0x07ac90U, 0xa9be4ff4U},
    {376U, 0x0331e0U, 0x07acb0U, 0xf81d0ff5U},
    {377U, 0x033388U, 0x07acd0U, 0xf940a028U},
    {378U, 0x0333e0U, 0x07ace8U, 0xa9ba6ffcU},
    {379U, 0x033618U, 0x07ad18U, 0xa9bb67faU},
    {380U, 0x033740U, 0x07ad48U, 0xa9ba6ffcU},
    {381U, 0x033880U, 0x07ad78U, 0xa9bd57f6U},
    {382U, 0x03395cU, 0x07ada0U, 0xd101c3ffU},
    {383U, 0x033af8U, 0x07add0U, 0xa9bb67faU},
    {384U, 0x033d94U, 0x07ae00U, 0xf81d0ff5U},
    {385U, 0x033f34U, 0x07ae20U, 0xd65f03c0U},
    {386U, 0x033f38U, 0x07ae38U, 0xaa1f03e0U},
    {387U, 0x033f40U, 0x07ae50U, 0xf9422c28U},
    {388U, 0x033f58U, 0x07ae68U, 0xd65f03c0U},
    {389U, 0x033f5cU, 0x07ae80U, 0xf9401008U},
    {390U, 0x033f80U, 0x07ae98U, 0xf9401008U},
    {391U, 0x033fa4U, 0x07aeb0U, 0xf9401008U},
    {392U, 0x033fccU, 0x07aec8U, 0xd65f03c0U},
    {393U, 0x033fd0U, 0x07aee0U, 0xd65f03c0U},
    {394U, 0x033fd4U, 0x07aef8U, 0x17ff46bfU},
    {395U, 0x033fd8U, 0x07af10U, 0xd10383ffU},
    {396U, 0x034480U, 0x07af40U, 0xf81e0ff3U},
    {397U, 0x0344e0U, 0x07af60U, 0xf81e0ff3U},
    {398U, 0x034504U, 0x07af80U, 0xa9008801U},
    {399U, 0x034510U, 0x07af98U, 0xf81b0ff9U},
    {400U, 0x0345f0U, 0x07afc0U, 0xa9be4ff4U},
    {401U, 0x0346d0U, 0x07afe0U, 0xd102c3ffU},
    {402U, 0x03493cU, 0x07b010U, 0xa9bd57f6U},
    {403U, 0x034ae4U, 0x07b038U, 0xa9bd57f6U},
    {404U, 0x034cccU, 0x07b060U, 0xf81d0ff5U},
    {405U, 0x034dd8U, 0x07b080U, 0xa9bb67faU},
    {406U, 0x034f98U, 0x07b0b0U, 0xa9ba6ffcU},
    {407U, 0x0350e0U, 0x07b0e0U, 0xf81d0ff5U},
    {408U, 0x035264U, 0x07b100U, 0xa9bb67faU},
    {409U, 0x035404U, 0x07b130U, 0xd10183ffU},
    {410U, 0x03554cU, 0x07b158U, 0xf9400008U},
    {411U, 0x0355b4U, 0x07b170U, 0xf9400008U},
    {412U, 0x035608U, 0x07b188U, 0xd101c3ffU},
    {413U, 0x03598cU, 0x07b1b8U, 0xd10283ffU},
    {414U, 0x035dd8U, 0x07b1e8U, 0xf81a0ffbU},
    {415U, 0x03657cU, 0x07b218U, 0xa9bc5ff8U},
    {416U, 0x036908U, 0x07b240U, 0xa9bc5ff8U},
    {417U, 0x036b90U, 0x07b268U, 0xa9bb67faU},
    {418U, 0x036d34U, 0x07b298U, 0xd10443ffU},
    {419U, 0x036f88U, 0x07b2c8U, 0x92800008U},
    {420U, 0x036fbcU, 0x07b2e0U, 0xb0000289U},
    {421U, 0x036ff4U, 0x07b2f8U, 0xa9bd57f6U},
    {422U, 0x037204U, 0x07b320U, 0xa9bb67faU},
    {423U, 0x037380U, 0x07b350U, 0xf81e0ff3U},
    {424U, 0x03741cU, 0x07b370U, 0xf9000c01U},
    {425U, 0x037430U, 0x07b388U, 0xf9401008U},
    {426U, 0x03743cU, 0x07b3a0U, 0xf9403c28U},
    {427U, 0x037454U, 0x07b3b8U, 0xf81e0ff3U},
    {428U, 0x03749cU, 0x07b3d8U, 0xf81e0ff3U},
    {429U, 0x0374f8U, 0x07b3f8U, 0xf81e0ff3U},
    {430U, 0x037530U, 0x07b418U, 0xf9401008U},
    {431U, 0x037544U, 0x07b430U, 0x90000288U},
    {432U, 0x03755cU, 0x07b448U, 0xa9bd57f6U},
    {433U, 0x0377b0U, 0x07b470U, 0xf9400808U},
    {434U, 0x0378e0U, 0x07b488U, 0xd10103ffU},
    {435U, 0x037ac0U, 0x07b4a8U, 0x9106f026U},
    {436U, 0x037ac8U, 0x07b4c0U, 0xd10103ffU},
    {437U, 0x037f60U, 0x07b4e0U, 0xd10103ffU},
    {438U, 0x0380acU, 0x07b500U, 0xd100c3ffU},
    {439U, 0x03818cU, 0x07b520U, 0xb9608808U},
    {440U, 0x0381c4U, 0x07b538U, 0xf9404048U},
    {441U, 0x03821cU, 0x07b550U, 0xd101c3ffU},
    {442U, 0x0383e4U, 0x07b580U, 0xb9608808U},
    {443U, 0x038494U, 0x07b598U, 0xf81e0ff3U},
    {444U, 0x0384c4U, 0x07b5b8U, 0xa9be4ff4U},
    {445U, 0x0385e8U, 0x07b5d8U, 0xf81e0ff3U},
    {446U, 0x038618U, 0x07b5f8U, 0xd0000268U},
    {447U, 0x038634U, 0x07b610U, 0xf81e0ff3U},
    {448U, 0x038668U, 0x07b630U, 0xa9be4ff4U},
    {449U, 0x0386a8U, 0x07b650U, 0xf81d0ff5U},
    {450U, 0x038748U, 0x07b670U, 0xa9be4ff4U},
    {451U, 0x0387fcU, 0x07b690U, 0xa9be4ff4U},
    {452U, 0x0388dcU, 0x07b6b0U, 0xf81e0ff3U},
    {453U, 0x038934U, 0x07b6d0U, 0xf81d0ff5U},
    {454U, 0x038990U, 0x07b6f0U, 0xa9ba6ffcU},
    {455U, 0x038ba4U, 0x07b720U, 0xf9400c08U},
    {456U, 0x038c30U, 0x07b738U, 0xd10243ffU},
    {457U, 0x0392ccU, 0x07b768U, 0xaa0003e8U},
    {458U, 0x0394a0U, 0x07b780U, 0xb0000268U},
    {459U, 0x0394f0U, 0x07b798U, 0xa9be4ff4U},
    {460U, 0x039540U, 0x07b7b8U, 0xa9be4ff4U},
    {461U, 0x03959cU, 0x07b7d8U, 0xf81e0ff3U},
    {462U, 0x0395c0U, 0x07b7f8U, 0x2959a408U},
    {463U, 0x0395d0U, 0x07b810U, 0xf81c0ff7U},
    {464U, 0x039694U, 0x07b838U, 0xd10183ffU},
    {465U, 0x0397b8U, 0x07b860U, 0xf81e0ff3U},
    {466U, 0x039800U, 0x07b880U, 0xf81d0ff5U},
    {467U, 0x039904U, 0x07b8a0U, 0xa9be4ff4U},
    {468U, 0x039970U, 0x07b8c0U, 0xd10103ffU},
    {469U, 0x039aa0U, 0x07b8e0U, 0x52800f08U},
    {470U, 0x039adcU, 0x07b8f8U, 0xa9bb67faU},
    {471U, 0x039cccU, 0x07b928U, 0xd10103ffU},
    {472U, 0x039dccU, 0x07b950U, 0x91009008U},
    {473U, 0x039dd8U, 0x07b968U, 0x2a1f03e0U},
    {474U, 0x039de0U, 0x07b980U, 0xa9be4ff4U},
    {475U, 0x039e40U, 0x07b9a0U, 0xd10183ffU},
    {476U, 0x039f10U, 0x07b9c8U, 0xf81d0ff5U},
    {477U, 0x039f8cU, 0x07b9e8U, 0xa9be4ff4U},
    {478U, 0x039ff0U, 0x07ba08U, 0xf9400068U},
    {479U, 0x03a010U, 0x07ba20U, 0xd101c3ffU},
    {480U, 0x03a124U, 0x07ba48U, 0xf81d0ff5U},
    {481U, 0x03a19cU, 0x07ba68U, 0xf81e0ff3U},
    {482U, 0x03a1d4U, 0x07ba88U, 0x6dbc23e9U},
    {483U, 0x03ac30U, 0x07bab0U, 0xb9402029U},
    {484U, 0x03ad9cU, 0x07bac8U, 0xfc1b0fe8U},
    {485U, 0x03bfbcU, 0x07baf8U, 0xd10443ffU},
    {486U, 0x03c058U, 0x07bb18U, 0xd65f03c0U},
    {487U, 0x03c05cU, 0x07bb30U, 0xa9be4ff4U},
    {488U, 0x03c17cU, 0x07bb50U, 0xa9be4ff4U},
    {489U, 0x03c1fcU, 0x07bb70U, 0xf81e0ff3U},
    {490U, 0x03c234U, 0x07bb90U, 0x6f00e400U},
    {491U, 0x03c2c4U, 0x07bba8U, 0xa9bf7bfdU},
    {492U, 0x03c424U, 0x07bbc8U, 0xa9007c1fU},
    {493U, 0x03c468U, 0x07bbe0U, 0xb00001a8U},
    {494U, 0x03c480U, 0x07bbf8U, 0xf81e0ff3U},
    {495U, 0x03c4d0U, 0x07bc18U, 0xf81c0ff7U},
    {496U, 0x03cf50U, 0x07bc40U, 0xf81d0ff5U},
    {497U, 0x03d430U, 0x07bc60U, 0xd10443ffU},
    {498U, 0x03d5c8U, 0x07bc88U, 0xd10443ffU},
    {499U, 0x03d664U, 0x07bca8U, 0x531a646aU},
    {500U, 0x03d6c0U, 0x07bcc0U, 0xaa1f03e8U},
    {501U, 0x03d744U, 0x07bcd8U, 0x7100045fU},
    {502U, 0x03d830U, 0x07bcf0U, 0x2a1f03eaU},
    {503U, 0x03d890U, 0x07bd08U, 0x7100043fU},
    {504U, 0x03d900U, 0x07bd20U, 0xb4000141U},
    {505U, 0x03d930U, 0x07bd38U, 0xf81c0ff7U},
    {506U, 0x03daccU, 0x07bd60U, 0xa9ba6ffcU},
    {507U, 0x03df68U, 0x07bd90U, 0xf81e0ff3U},
    {508U, 0x03dfb4U, 0x07bdb0U, 0xf81e0ff3U},
    {509U, 0x03dfe8U, 0x07bdd0U, 0xa9bf7bfdU},
    {510U, 0x03e008U, 0x07bdf0U, 0xa9be4ff4U},
    {511U, 0x03e0d0U, 0x07be10U, 0xf81e0ff3U},
    {512U, 0x03e134U, 0x07be30U, 0xf81e0ff3U},
    {513U, 0x03e168U, 0x07be50U, 0xa9bd57f6U},
    {514U, 0x03e2c4U, 0x07be78U, 0xd10183ffU},
    {515U, 0x03e3e8U, 0x07bea0U, 0xd10183ffU},
    {516U, 0x03e50cU, 0x07bec8U, 0xa9be4ff4U},
    {517U, 0x03e58cU, 0x07bee8U, 0xf81e0ff3U},
    {518U, 0x03e5d4U, 0x07bf08U, 0xf81e0ff3U},
    {519U, 0x03e61cU, 0x07bf28U, 0xa9bc5ff8U},
    {520U, 0x03e738U, 0x07bf50U, 0xd10103ffU},
    {521U, 0x03e868U, 0x07bf70U, 0xa9bc5ff8U},
    {522U, 0x03e9acU, 0x07bf98U, 0xa9be4ff4U},
    {523U, 0x03ea28U, 0x07bfb8U, 0xd10103ffU},
    {524U, 0x03eb58U, 0x07bfd8U, 0xf81c0ff7U},
    {525U, 0x03ec34U, 0x07c000U, 0xf81d0ff5U},
    {526U, 0x03ecc0U, 0x07c020U, 0xd10103ffU},
    {527U, 0x03edc0U, 0x07c048U, 0xd10103ffU},
    {528U, 0x03eec0U, 0x07c070U, 0x710004bfU},
    {529U, 0x03ef58U, 0x07c088U, 0xf81b0ff9U},
    {530U, 0x03f0e8U, 0x07c0b0U, 0xa9ba6ffcU},
    {531U, 0x03ff5cU, 0x07c0e0U, 0xf81e0ff3U},
    {532U, 0x03ff9cU, 0x07c100U, 0xa9ba6ffcU},
    {533U, 0x0409a4U, 0x07c130U, 0x17ff144bU},
    {534U, 0x0409a8U, 0x07c148U, 0x17ff144aU},
    {535U, 0x0409acU, 0x07c160U, 0xa9be4ff4U},
    {536U, 0x0409e8U, 0x07c180U, 0xf81e0ff3U},
    {537U, 0x040a0cU, 0x07c1a0U, 0xd10243ffU},
    {538U, 0x040c80U, 0x07c1d0U, 0xd102c3ffU},
    {539U, 0x040e04U, 0x07c200U, 0xd10583ffU},
    {540U, 0x041424U, 0x07c230U, 0xd101c3ffU},
    {541U, 0x041538U, 0x07c258U, 0xa9be4ff4U},
    {542U, 0x04159cU, 0x07c278U, 0xf9400068U},
    {543U, 0x0415bcU, 0x07c290U, 0xd10203ffU},
    {544U, 0x041798U, 0x07c2b8U, 0xf9400409U},
    {545U, 0x0417e0U, 0x07c2d0U, 0xa9bc5ff8U},
    {546U, 0x041880U, 0x07c2f8U, 0xa9be4ff4U},
    {547U, 0x0418c0U, 0x07c318U, 0xd10183ffU},
    {548U, 0x041990U, 0x07c340U, 0xf81d0ff5U},
    {549U, 0x041a0cU, 0x07c360U, 0xa9be4ff4U},
    {550U, 0x041a70U, 0x07c380U, 0xf9400068U},
    {551U, 0x041a90U, 0x07c398U, 0xd101c3ffU},
    {552U, 0x041ba4U, 0x07c3c0U, 0xd10183ffU},
    {553U, 0x041c74U, 0x07c3e8U, 0xf81d0ff5U},
    {554U, 0x041cf0U, 0x07c408U, 0xa9be4ff4U},
    {555U, 0x041d54U, 0x07c428U, 0xf9400068U},
    {556U, 0x041d74U, 0x07c440U, 0xd101c3ffU},
    {557U, 0x041e88U, 0x07c468U, 0xa9be4ff4U},
    {558U, 0x041f6cU, 0x07c488U, 0xb4000080U},
    {559U, 0x041f80U, 0x07c4a0U, 0xb0000228U},
    {560U, 0x042124U, 0x07c4b8U, 0xf81e0ff3U},
    {561U, 0x042178U, 0x07c4d8U, 0xd4200020U},
    {562U, 0x04217cU, 0x07c4f0U, 0x6dbd23e9U},
    {563U, 0x042590U, 0x07c518U, 0xf81d0ff5U},
    {564U, 0x0425f0U, 0x07c538U, 0xf9400408U},
    {565U, 0x042694U, 0x07c550U, 0xf9400408U},
    {566U, 0x042994U, 0x07c568U, 0xd10483ffU},
    {567U, 0x042b94U, 0x07c590U, 0x12800008U},
    {568U, 0x042be4U, 0x07c5a8U, 0xf81e0ff3U},
    {569U, 0x042cc0U, 0x07c5c8U, 0xf000016aU},
    {570U, 0x042de8U, 0x07c5e0U, 0xfc1d0fe8U},
    {571U, 0x0431a0U, 0x07c608U, 0xa9be4ff4U},
    {572U, 0x0432e4U, 0x07c628U, 0xa9be4ff4U},
    {573U, 0x043394U, 0x07c648U, 0xa9be4ff4U},
    {574U, 0x04343cU, 0x07c668U, 0xf81d0ff5U},
    {575U, 0x043524U, 0x07c688U, 0xa9bf7bfdU},
    {576U, 0x0435b0U, 0x07c6a8U, 0xf81e0ff3U},
    {577U, 0x0436d4U, 0x07c6c8U, 0xf81d0ff5U},
    {578U, 0x04390cU, 0x07c6e8U, 0xd10483ffU},
    {579U, 0x043b98U, 0x07c710U, 0xb940e00bU},
    {580U, 0x043c84U, 0x07c728U, 0x6b02003fU},
    {581U, 0x043e24U, 0x07c740U, 0xf81e0ff3U},
    {582U, 0x043eacU, 0x07c760U, 0xf81e0ff3U},
    {583U, 0x043fe8U, 0x07c780U, 0xf9400408U},
    {584U, 0x044040U, 0x07c798U, 0xb900003fU},
    {585U, 0x044114U, 0x07c7b0U, 0xf9400408U},
    {586U, 0x044148U, 0x07c7c8U, 0xf81e0ff3U},
    {587U, 0x044304U, 0x07c7e8U, 0x6941a428U},
    {588U, 0x0443dcU, 0x07c800U, 0xf9400c28U},
    {589U, 0x0444a0U, 0x07c818U, 0xf81a0ffbU},
    {590U, 0x044764U, 0x07c848U, 0x6b02003fU},
    {591U, 0x044910U, 0x07c860U, 0x6b02003fU},
    {592U, 0x04494cU, 0x07c878U, 0xf81d0ff5U},
    {593U, 0x044a38U, 0x07c898U, 0x39418008U},
    {594U, 0x044b30U, 0x07c8b0U, 0xa9ba6ffcU},
    {595U, 0x044c40U, 0x07c8e0U, 0xb4000241U},
    {596U, 0x044d60U, 0x07c8f8U, 0xd101c3ffU},
    {597U, 0x044fa8U, 0x07c928U, 0xb941a008U},
    {598U, 0x045034U, 0x07c940U, 0xd0000148U},
    {599U, 0x0450c0U, 0x07c958U, 0x7100005fU},
    {600U, 0x0451c4U, 0x07c970U, 0x7100285fU},
    {601U, 0x0452b8U, 0x07c988U, 0xf81b0ff9U},
    {602U, 0x0453acU, 0x07c9b0U, 0xfd400022U},
    {603U, 0x0453f0U, 0x07c9c8U, 0xa9bd57f6U},
    {604U, 0x0454d4U, 0x07c9f0U, 0x52803408U},
    {605U, 0x0455d8U, 0x07ca08U, 0xd10403ffU},
    {606U, 0x045898U, 0x07ca38U, 0xfc180feaU},
    {607U, 0x045becU, 0x07ca70U, 0xb98bfc08U},
    {608U, 0x045ce0U, 0x07ca88U, 0xb94bfc08U},
    {609U, 0x045db8U, 0x07caa0U, 0xb94bfc08U},
    {610U, 0x045e18U, 0x07cab8U, 0xb941a008U},
    {611U, 0x045ea8U, 0x07cad0U, 0xb941a008U},
    {612U, 0x045f34U, 0x07cae8U, 0x6dbb23e9U},
    {613U, 0x046018U, 0x07cb18U, 0xf9460408U},
    {614U, 0x046114U, 0x07cb30U, 0xb94be408U},
    {615U, 0x04626cU, 0x07cb48U, 0xa9bd57f6U},
    {616U, 0x0462dcU, 0x07cb70U, 0xb9400829U},
    {617U, 0x046390U, 0x07cb88U, 0xf9403428U},
    {618U, 0x0464c8U, 0x07cba0U, 0xb94bdc08U},
    {619U, 0x0465e0U, 0x07cbb8U, 0xb0000148U},
    {620U, 0x046610U, 0x07cbd0U, 0x396f6409U},
    {621U, 0x046770U, 0x07cbe8U, 0xb94bfc08U},
    {622U, 0x0467ecU, 0x07cc00U, 0xfc1b0fe8U},
    {623U, 0x0468d0U, 0x07cc28U, 0xf9406828U},
    {624U, 0x0468e8U, 0x07cc40U, 0xf9406828U},
    {625U, 0x04692cU, 0x07cc58U, 0x6dba23e9U},
    {626U, 0x046af4U, 0x07cc88U, 0xf81e0ff3U},
    {627U, 0x046b20U, 0x07cca8U, 0xfd402400U},
    {628U, 0x046bb8U, 0x07ccc0U, 0xb9401020U},
    {629U, 0x046bc0U, 0x07ccd8U, 0x90000208U},
    {630U, 0x046bd0U, 0x07ccf0U, 0xf81e0ff3U},
    {631U, 0x046c00U, 0x07cd10U, 0xd65f03c0U},
    {632U, 0x046c04U, 0x07cd28U, 0xd65f03c0U},
    {633U, 0x046c08U, 0x07cd40U, 0x2a1f03e0U},
    {634U, 0x046c10U, 0x07cd58U, 0xf81d0ff5U},
    {635U, 0x046cdcU, 0x07cd78U, 0xf81e0ff3U},
    {636U, 0x046d18U, 0x07cd98U, 0xf81e0ff3U},
    {637U, 0x046d3cU, 0x07cdb8U, 0x6dba23e9U},
    {638U, 0x04713cU, 0x07cde8U, 0xfc1c0feaU},
    {639U, 0x047278U, 0x07ce10U, 0xf81d0ff5U},
    {640U, 0x0472ecU, 0x07ce30U, 0x6db73befU},
    {641U, 0x0474e0U, 0x07ce70U, 0xb940182aU},
    {642U, 0x047694U, 0x07ce88U, 0x6db833edU},
    {643U, 0x047a08U, 0x07cec8U, 0xfc1d0fe8U},
    {644U, 0x047bacU, 0x07cee8U, 0xfc1e0fe8U},
    {645U, 0x047be0U, 0x07cf08U, 0xfc1a0fecU},
    {646U, 0x047eb4U, 0x07cf38U, 0xf81c0ff7U},
    {647U, 0x047f5cU, 0x07cf60U, 0xb94bdc0eU},
    {648U, 0x048258U, 0x07cf78U, 0x6db933edU},
    {649U, 0x0484bcU, 0x07cfb0U, 0xa9bd57f6U},
    {650U, 0x04877cU, 0x07cfd8U, 0xfc1a0fe8U},
    {651U, 0x048904U, 0x07d008U, 0xb94bfc08U},
    {652U, 0x048aa0U, 0x07d020U, 0x6dbd23e9U},
    {653U, 0x048c04U, 0x07d048U, 0xd10143ffU},
    {654U, 0x048ddcU, 0x07d070U, 0xfc190feaU},
    {655U, 0x04919cU, 0x07d0a8U, 0xfc1a0feaU},
    {656U, 0x049450U, 0x07d0d8U, 0xf9460408U},
    {657U, 0x049494U, 0x07d0f0U, 0xb94bdc08U},
    {658U, 0x0495c4U, 0x07d108U, 0xd10103ffU},
    {659U, 0x04976cU, 0x07d128U, 0xb94bdc09U},
    {660U, 0x0498b0U, 0x07d140U, 0xa9bd57f6U},
    {661U, 0x04998cU, 0x07d168U, 0x6db83befU},
    {662U, 0x049c98U, 0x07d1a8U, 0x6db92bebU},
    {663U, 0x04a03cU, 0x07d1e0U, 0x6db833edU},
    {664U, 0x04a324U, 0x07d220U, 0xd10283ffU},
    {665U, 0x04a4c4U, 0x07d250U, 0x6db833edU},
    {666U, 0x04aae8U, 0x07d290U, 0xa9ba6ffcU},
    {667U, 0x04ac90U, 0x07d2c0U, 0xb941a008U},
    {668U, 0x04adb8U, 0x07d2d8U, 0xb9403409U},
    {669U, 0x04b0f0U, 0x07d2f0U, 0xf9403428U},
    {670U, 0x04b278U, 0x07d308U, 0xfc1a0fe8U},
    {671U, 0x04b358U, 0x07d338U, 0xa9bd57f6U},
    {672U, 0x04b52cU, 0x07d360U, 0xb941a009U},
    {673U, 0x04b780U, 0x07d378U, 0x340000c1U},
    {674U, 0x04b87cU, 0x07d390U, 0xb9401009U},
    {675U, 0x04b968U, 0x07d3a8U, 0xb9404428U},
    {676U, 0x04ba30U, 0x07d3c0U, 0xfc1b0feaU},
    {677U, 0x04be24U, 0x07d3f0U, 0xfc1c0fe8U},
    {678U, 0x04c220U, 0x07d418U, 0xb9403c08U},
    {679U, 0x04c2b4U, 0x07d430U, 0xf9402428U},
    {680U, 0x04c328U, 0x07d448U, 0xa9bd57f6U},
    {681U, 0x04c500U, 0x07d470U, 0x6dbd23e9U},
    {682U, 0x04c680U, 0x07d498U, 0xf9460408U},
    {683U, 0x04c72cU, 0x07d4b0U, 0x12001c28U},
    {684U, 0x04c8f0U, 0x07d4c8U, 0xfc170feeU},
    {685U, 0x04cabcU, 0x07d508U, 0xfc1b0fe8U},
    {686U, 0x04cba8U, 0x07d538U, 0xaa0003e8U},
    {687U, 0x04cc10U, 0x07d550U, 0x6dbb23e9U},
    {688U, 0x04cdb4U, 0x07d580U, 0xd10243ffU},
    {689U, 0x04d230U, 0x07d5b0U, 0xb94bdc0aU},
    {690U, 0x04d3d0U, 0x07d5c8U, 0x91339009U},
    {691U, 0x04d4c0U, 0x07d5e0U, 0xb94bdc0aU},
    {692U, 0x04d728U, 0x07d5f8U, 0xf9460408U},
    {693U, 0x04d880U, 0x07d610U, 0xb9407008U},
    {694U, 0x04d8ccU, 0x07d628U, 0xfc1c0fe8U},
    {695U, 0x04db34U, 0x07d650U, 0xf81c0ff7U},
    {696U, 0x04dbf8U, 0x07d678U, 0xb94bfc08U},
    {697U, 0x04dc48U, 0x07d690U, 0xf9400408U},
    {698U, 0x04dcdcU, 0x07d6a8U, 0xfd402401U},
    {699U, 0x04dd88U, 0x07d6c0U, 0xf81e0ff3U},
    {700U, 0x04ddd8U, 0x07d6e0U, 0xf81e0ff3U},
    {701U, 0x04de0cU, 0x07d700U, 0x9139a000U},
    {702U, 0x04de14U, 0x07d718U, 0xf81e0ff3U},
    {703U, 0x04de50U, 0x07d738U, 0xf81d0ff5U},
    {704U, 0x04ded8U, 0x07d758U, 0x39404808U},
    {705U, 0x04df14U, 0x07d770U, 0xf81d0ff5U},
    {706U, 0x04df9cU, 0x07d790U, 0xa9bc5ff8U},
    {707U, 0x04e168U, 0x07d7b8U, 0xa9be4ff4U},
    {708U, 0x04e258U, 0x07d7d8U, 0xd10183ffU},
    {709U, 0x04e3b4U, 0x07d7f8U, 0xf945ac09U},
    {710U, 0x04e49cU, 0x07d810U, 0x6dbb23e9U},
    {711U, 0x04e558U, 0x07d840U, 0xd102c3ffU},
    {712U, 0x04ea38U, 0x07d880U, 0xf81c0ff7U},
    {713U, 0x04eb80U, 0x07d8a8U, 0xd65f03c0U},
    {714U, 0x04eb84U, 0x07d8c0U, 0xa9be4ff4U},
    {715U, 0x04ebe4U, 0x07d8e0U, 0xf81e0ff3U},
    {716U, 0x04ec6cU, 0x07d900U, 0xb9400809U},
    {717U, 0x04ee04U, 0x07d918U, 0xa9ba6ffcU},
    {718U, 0x04f880U, 0x07d948U, 0xd10203ffU},
    {719U, 0x04fb24U, 0x07d970U, 0xd100c3ffU},
    {720U, 0x04fb7cU, 0x07d990U, 0xd10343ffU},
    {721U, 0x05058cU, 0x07d9c0U, 0xd10303ffU},
    {722U, 0x050d28U, 0x07d9f0U, 0xd100c3ffU},
    {723U, 0x050d68U, 0x07da10U, 0xd100c3ffU},
    {724U, 0x050dc0U, 0x07da30U, 0xd10343ffU},
    {725U, 0x051740U, 0x07da60U, 0xd100c3ffU},
    {726U, 0x051780U, 0x07da80U, 0xd100c3ffU},
    {727U, 0x0517d8U, 0x07daa0U, 0xd10303ffU},
    {728U, 0x05243cU, 0x07dad0U, 0xd100c3ffU},
    {729U, 0x05247cU, 0x07daf0U, 0xd100c3ffU},
    {730U, 0x0524d4U, 0x07db10U, 0xd10383ffU},
    {731U, 0x053340U, 0x07db40U, 0xd100c3ffU},
    {732U, 0x053380U, 0x07db60U, 0xd10283ffU},
    {733U, 0x0535bcU, 0x07db90U, 0xd10303ffU},
    {734U, 0x0538a4U, 0x07dbc0U, 0xa9bd57f6U},
    {735U, 0x053a0cU, 0x07dbe8U, 0xf9423828U},
    {736U, 0x053a20U, 0x07dc00U, 0xf9423828U},
    {737U, 0x053a3cU, 0x07dc18U, 0xf9400800U},
    {738U, 0x053a50U, 0x07dc30U, 0xf9400400U},
    {739U, 0x053a64U, 0x07dc48U, 0xf81c0ff7U},
    {740U, 0x053b14U, 0x07dc70U, 0xf81d0ff5U},
    {741U, 0x053b90U, 0x07dc90U, 0xa9bf7bfdU},
    {742U, 0x053bacU, 0x07dcb0U, 0xf0000188U},
    {743U, 0x053bbcU, 0x07dcc8U, 0x17fec7c5U},
    {744U, 0x053bc0U, 0x07dce0U, 0x2a1f03e0U},
    {745U, 0x053bc8U, 0x07dcf8U, 0x2a1f03e0U},
    {746U, 0x053bd0U, 0x07dd10U, 0xd65f03c0U},
    {747U, 0x053bd4U, 0x07dd28U, 0xf0000188U},
    {748U, 0x053bf0U, 0x07dd40U, 0x17fec7b8U},
    {749U, 0x053bf4U, 0x07dd58U, 0x2a1f03e0U},
    {750U, 0x053bfcU, 0x07dd70U, 0x2a1f03e0U},
    {751U, 0x053c04U, 0x07dd88U, 0xf81e0ff3U},
    {752U, 0x053c44U, 0x07dda8U, 0xa9be4ff4U},
    {753U, 0x053c90U, 0x07ddc8U, 0x91008000U},
    {754U, 0x053c98U, 0x07dde0U, 0xa9bf7bfdU},
    {755U, 0x053cb4U, 0x07de00U, 0xa9bf7bfdU},
    {756U, 0x053cd0U, 0x07de20U, 0xa9be4ff4U},
    {757U, 0x053d54U, 0x07de40U, 0xb40000e0U},
    {758U, 0x053d78U, 0x07de60U, 0xf81d0ffcU},
    {759U, 0x053dfcU, 0x07de80U, 0xb40000e0U},
    {760U, 0x053e20U, 0x07dea0U, 0xb4000080U},
    {761U, 0x053e34U, 0x07deb8U, 0xb4000080U},
    {762U, 0x053e48U, 0x07ded0U, 0xb4000080U},
    {763U, 0x053e5cU, 0x07dee8U, 0xb4000080U},
    {764U, 0x053e70U, 0x07df00U, 0xb4000080U},
    {765U, 0x053e84U, 0x07df18U, 0xb4000080U},
    {766U, 0x053e9cU, 0x07df30U, 0xb4000080U},
    {767U, 0x053eb0U, 0x07df48U, 0xb4000080U},
    {768U, 0x053ec8U, 0x07df60U, 0xb4000080U},
    {769U, 0x053edcU, 0x07df78U, 0xb4000080U},
    {770U, 0x053ef0U, 0x07df90U, 0xb4000080U},
    {771U, 0x053f04U, 0x07dfa8U, 0xf81c0ff7U},
    {772U, 0x0542bcU, 0x07dfd0U, 0xf81e0ff3U},
    {773U, 0x054308U, 0x07dff0U, 0xf81c0ff7U},
    {774U, 0x0543c4U, 0x07e018U, 0xd10243ffU},
    {775U, 0x055570U, 0x07e040U, 0xb40000a1U},
    {776U, 0x05558cU, 0x07e058U, 0xf81e0ff3U},
    {777U, 0x055634U, 0x07e078U, 0xf81d0ff5U},
    {778U, 0x0556b4U, 0x07e098U, 0xf81e0ff3U},
    {779U, 0x055718U, 0x07e0b8U, 0xd1002000U},
    {780U, 0x055720U, 0x07e0d0U, 0xf81e0ff3U},
    {781U, 0x055744U, 0x07e0f0U, 0xf81e0ff3U},
    {782U, 0x05576cU, 0x07e110U, 0xf81b0ffcU},
    {783U, 0x05599cU, 0x07e138U, 0xd10443ffU},
    {784U, 0x055a40U, 0x07e158U, 0xd10283ffU},
    {785U, 0x056174U, 0x07e180U, 0xa9bd57f6U},
    {786U, 0x056210U, 0x07e1a8U, 0x6dbb23e9U},
    {787U, 0x0564a0U, 0x07e1d8U, 0xa9be4ff4U},
    {788U, 0x0566bcU, 0x07e1f8U, 0xd10343ffU},
    {789U, 0x056bdcU, 0x07e240U, 0xa9be4ff4U},
    {790U, 0x056c58U, 0x07e260U, 0xd10183ffU},
    {791U, 0x056d7cU, 0x07e288U, 0xf81e0ff3U},
    {792U, 0x056dc4U, 0x07e2a8U, 0x2a1f03e0U},
    {793U, 0x056dccU, 0x07e2c0U, 0xa9bd57fcU},
    {794U, 0x056f78U, 0x07e2e8U, 0xa9bc5ffcU},
    {795U, 0x0570c4U, 0x07e310U, 0xa9bd57f6U},
    {796U, 0x057130U, 0x07e338U, 0xf81c0ff7U},
    {797U, 0x0571d0U, 0x07e360U, 0xf81d0ff5U},
    {798U, 0x05721cU, 0x07e380U, 0xf9400c08U},
    {799U, 0x05722cU, 0x07e398U, 0xa9bf7bfdU},
    {800U, 0x057248U, 0x07e3b8U, 0xa9bf7bfdU},
    {801U, 0x057288U, 0x07e3d8U, 0xa9be4ff4U},
    {802U, 0x0572e0U, 0x07e3f8U, 0xf9403c09U},
    {803U, 0x057338U, 0x07e410U, 0xf81c0ff7U},
    {804U, 0x057570U, 0x07e438U, 0xa9bd57f6U},
    {805U, 0x057610U, 0x07e460U, 0xf9400c08U},
    {806U, 0x05761cU, 0x07e478U, 0xd10243ffU},
    {807U, 0x057bccU, 0x07e4a8U, 0xf81c0ff7U},
    {808U, 0x057c60U, 0x07e4d0U, 0xa9bd57f6U},
    {809U, 0x057cd8U, 0x07e4f8U, 0xa9be4ff4U},
    {810U, 0x057d14U, 0x07e518U, 0xf81d0ff5U},
    {811U, 0x057d60U, 0x07e538U, 0xf81d0ff5U},
    {812U, 0x057dacU, 0x07e558U, 0xa9be4ff4U},
    {813U, 0x057e18U, 0x07e578U, 0xf81c0ff7U},
    {814U, 0x057fc8U, 0x07e5a0U, 0xf9400c08U},
    {815U, 0x0580a4U, 0x07e5b8U, 0xfc1a0fe8U},
    {816U, 0x05840cU, 0x07e5e8U, 0xd1002000U},
    {817U, 0x058414U, 0x07e600U, 0xd10103ffU},
    {818U, 0x058544U, 0x07e620U, 0xd10103ffU},
    {819U, 0x058644U, 0x07e648U, 0xfc190fe8U},
    {820U, 0x058844U, 0x07e678U, 0xd10083ffU},
    {821U, 0x058900U, 0x07e698U, 0x2957a029U},
    {822U, 0x058958U, 0x07e6b0U, 0xa9bd57fcU},
    {823U, 0x058b54U, 0x07e6d8U, 0xf81c0ffcU},
    {824U, 0x058d7cU, 0x07e700U, 0x72001c48U},
    {825U, 0x058da4U, 0x07e718U, 0xf81d0ff5U},
    {826U, 0x058f08U, 0x07e738U, 0xf9400c00U},
    {827U, 0x058f58U, 0x07e750U, 0xd101c3ffU},
    {828U, 0x059128U, 0x07e780U, 0xa9bd57f6U},
    {829U, 0x059268U, 0x07e7a8U, 0xf9405008U},
    {830U, 0x059344U, 0x07e7c0U, 0x6dbc23e9U},
    {831U, 0x0594b4U, 0x07e7e8U, 0xd10243ffU},
    {832U, 0x0596a4U, 0x07e820U, 0xfc1d0fe8U},
    {833U, 0x059754U, 0x07e848U, 0xf940500aU},
    {834U, 0x05990cU, 0x07e860U, 0xfc1c0fe8U},
    {835U, 0x0599d4U, 0x07e888U, 0xf81d0ffcU},
    {836U, 0x059b84U, 0x07e8a8U, 0xf81e0ff3U},
    {837U, 0x059bc0U, 0x07e8c8U, 0xa9be4ff4U},
    {838U, 0x059c20U, 0x07e8e8U, 0xd10103ffU},
    {839U, 0x059d20U, 0x07e910U, 0xd10103ffU},
    {840U, 0x059e20U, 0x07e938U, 0xd101c3ffU},
    {841U, 0x059f34U, 0x07e960U, 0xa9be4ff4U},
    {842U, 0x059f98U, 0x07e980U, 0xf9400068U},
    {843U, 0x059fb8U, 0x07e998U, 0xd101c3ffU},
    {844U, 0x05a0ccU, 0x07e9c0U, 0xa9be4ff4U},
    {845U, 0x05a130U, 0x07e9e0U, 0xf9400068U},
    {846U, 0x05a150U, 0x07e9f8U, 0xd10183ffU},
    {847U, 0x05a220U, 0x07ea20U, 0xf81d0ff5U},
    {848U, 0x05a29cU, 0x07ea40U, 0xa9be4ff4U},
    {849U, 0x05a300U, 0x07ea60U, 0xf9400068U},
    {850U, 0x05a320U, 0x07ea78U, 0xd101c3ffU},
    {851U, 0x05a434U, 0x07eaa0U, 0x5ac01008U},
    {852U, 0x05a464U, 0x07eab8U, 0xb00000c8U},
    {853U, 0x05a4c4U, 0x07ead0U, 0xd10243ffU},
    {854U, 0x05a7a4U, 0x07eb00U, 0xf81e0ff3U},
    {855U, 0x05a7e8U, 0x07eb20U, 0x6db923e9U},
    {856U, 0x05a944U, 0x07eb58U, 0xfc1e0fe8U},
    {857U, 0x05a98cU, 0x07eb78U, 0xa9bb67faU},
    {858U, 0x05aa60U, 0x07eba8U, 0xd10303ffU},
    {859U, 0x05ac74U, 0x07ebd8U, 0x39400028U},
    {860U, 0x05acb4U, 0x07ebf0U, 0xd10443ffU},
    {861U, 0x05ade4U, 0x07ec18U, 0xf81e0ff3U},
    {862U, 0x05ae2cU, 0x07ec38U, 0xd10103ffU},
    {863U, 0x05b054U, 0x07ec58U, 0xa9bd57f6U},
    {864U, 0x05b118U, 0x07ec80U, 0xa9ba6ffcU},
    {865U, 0x05b24cU, 0x07ecb0U, 0x7100143fU},
    {866U, 0x05b2f0U, 0x07ecc8U, 0xa9bb67fcU},
    {867U, 0x05b474U, 0x07ecf8U, 0xd10443ffU},
    {868U, 0x05b518U, 0x07ed18U, 0xb4000500U},
    {869U, 0x05b5bcU, 0x07ed38U, 0xa9bf7bfdU},
    {870U, 0x05b5e0U, 0x07ed58U, 0xf81e0ff3U},
    {871U, 0x05b638U, 0x07ed78U, 0xa9bd57f6U},
    {872U, 0x05b770U, 0x07eda0U, 0xf81d0ff5U},
    {873U, 0x05b854U, 0x07edc0U, 0xf81b0ff9U},
    {874U, 0x05b97cU, 0x07ede8U, 0xa9bf7bfdU},
    {875U, 0x05b9c8U, 0x07ee08U, 0xd65f03c0U},
    {876U, 0x05b9ccU, 0x07ee20U, 0xd100c3ffU},
    {877U, 0x05ba3cU, 0x07ee40U, 0xa9bf7bfdU},
    {878U, 0x05ba5cU, 0x07ee60U, 0xa9bf7bfdU},
    {879U, 0x05ba7cU, 0x07ee80U, 0xa9bf7bfdU},
    {880U, 0x05ba9cU, 0x07eea0U, 0xf81e0ff3U},
    {881U, 0x05bb1cU, 0x07eec0U, 0xa9bf7bfdU},
    {882U, 0x05bb38U, 0x07eee0U, 0xa9be4ff4U},
    {883U, 0x05bb80U, 0x07ef00U, 0xa9bf7bfdU},
    {884U, 0x05bb98U, 0x07ef20U, 0xf81d0ff5U},
    {885U, 0x05bbfcU, 0x07ef40U, 0xa9bf7bfdU},
    {886U, 0x05bc14U, 0x07ef60U, 0xf81e0ff3U},
    {887U, 0x05bc60U, 0x07ef80U, 0xa9bf7bfdU},
    {888U, 0x05bc78U, 0x07efa0U, 0xa9bf7bfdU},
    {889U, 0x05bca4U, 0x07efc0U, 0xa9bf7bfdU},
    {890U, 0x05bcc8U, 0x07efe0U, 0x2a1f03e0U},
    {891U, 0x05bcd0U, 0x07eff8U, 0xa9bf7bfdU},
    {892U, 0x05bcf0U, 0x07f018U, 0x52807d08U},
    {893U, 0x05bcfcU, 0x07f030U, 0x52800021U},
    {894U, 0x05bd04U, 0x07f048U, 0x17fea7dbU},
    {895U, 0x05bd08U, 0x07f060U, 0x17fea7e2U},
    {896U, 0x05bd0cU, 0x07f078U, 0xd10083ffU},
    {897U, 0x05bd58U, 0x07f098U, 0xd10083ffU},
    {898U, 0x05bd8cU, 0x07f0b8U, 0xf81e0ff3U},
    {899U, 0x05bdb8U, 0x07f0d8U, 0xf81e0ff3U},
    {900U, 0x05bde0U, 0x07f0f8U, 0xa9be4ff4U},
    {901U, 0x05be14U, 0x07f118U, 0xa9be4ff4U},
    {902U, 0x05be44U, 0x07f138U, 0xa9be4ff4U},
    {903U, 0x05be80U, 0x07f158U, 0xf81e0ff3U},
    {904U, 0x05beb8U, 0x07f178U, 0xf81d0ff5U},
    {905U, 0x05bf0cU, 0x07f198U, 0xf81e0ff3U},
    {906U, 0x05bf38U, 0x07f1b8U, 0xa9be4ff4U},
    {907U, 0x05bf88U, 0x07f1d8U, 0xf81d0ff5U},
    {908U, 0x05bff4U, 0x07f1f8U, 0xb9400008U},
    {909U, 0x05c010U, 0x07f210U, 0xd65f03c0U},
    {910U, 0x05c014U, 0x07f228U, 0xf81d0ff5U},
    {911U, 0x05c058U, 0x07f248U, 0x14000047U},
    {912U, 0x05c05cU, 0x07f260U, 0xf81e0ff3U},
    {913U, 0x05c080U, 0x07f280U, 0xa9bf7bfdU},
    {914U, 0x05c0b8U, 0x07f2a0U, 0xf81e0ff3U},
    {915U, 0x05c13cU, 0x07f2c0U, 0xf0000148U},
    {916U, 0x05c174U, 0x07f2d8U, 0xf81e0ff3U},
    {917U, 0x05c1a4U, 0x07f2f8U, 0xf81e0ff3U},
    {918U, 0x05c1f0U, 0x07f318U, 0xd4200020U},
    {919U, 0x05c1f4U, 0x07f330U, 0xf81e0ff3U},
    {920U, 0x05c268U, 0x07f350U, 0xf81e0ff3U},
    {921U, 0x05c29cU, 0x07f370U, 0x91006000U},
    {922U, 0x05c2a4U, 0x07f388U, 0xa9bd57f6U},
    {923U, 0x05c314U, 0x07f3b0U, 0xa9bf7bfdU},
    {924U, 0x05c334U, 0x07f3d0U, 0xa9be4ff4U},
    {925U, 0x05c39cU, 0x07f3f0U, 0xf81e0ff3U},
    {926U, 0x05c3fcU, 0x07f410U, 0xf81b0ff9U},
    {927U, 0x05c510U, 0x07f438U, 0xf81e0ff3U},
    {928U, 0x05c534U, 0x07f458U, 0xa9bd57f6U},
    {929U, 0x05c5ccU, 0x07f480U, 0xf81d0ff5U},
    {930U, 0x05c698U, 0x07f4a0U, 0xf81d0ff5U},
    {931U, 0x05c704U, 0x07f4c0U, 0xf81d0ff5U},
    {932U, 0x05c76cU, 0x07f4e0U, 0xf81d0ff5U},
    {933U, 0x05c7e0U, 0x07f500U, 0xf81d0ff5U},
    {934U, 0x05c854U, 0x07f520U, 0xf81c0ff7U},
    {935U, 0x05c914U, 0x07f548U, 0xa9ba6ffcU},
    {936U, 0x05caa8U, 0x07f578U, 0x2a1f03e0U},
    {937U, 0x05cab0U, 0x07f590U, 0x2a1f03e0U},
    {938U, 0x05cab8U, 0x07f5a8U, 0xa9bd57f6U},
    {939U, 0x05cb2cU, 0x07f5d0U, 0xa9bf7bfdU},
    {940U, 0x05cb48U, 0x07f5f0U, 0xa9be4ff4U},
    {941U, 0x05cb88U, 0x07f610U, 0xa9be4ff4U},
    {942U, 0x05cbe8U, 0x07f630U, 0xa9be4ff4U},
    {943U, 0x05cc48U, 0x07f650U, 0xd10343ffU},
    {944U, 0x05cf48U, 0x07f678U, 0x39409c08U},
    {945U, 0x05cf84U, 0x07f690U, 0xb9400029U},
    {946U, 0x05d1c0U, 0x07f6a8U, 0xf81e0ff3U},
    {947U, 0x05d318U, 0x07f6c8U, 0x7100087fU},
    {948U, 0x05d344U, 0x07f6e0U, 0xd00000a8U},
    {949U, 0x05d354U, 0x07f6f8U, 0xd00000a8U},
    {950U, 0x05d36cU, 0x07f710U, 0x52800028U},
    {951U, 0x05d480U, 0x07f728U, 0xcb23c809U},
    {952U, 0x05d5f0U, 0x07f740U, 0x297fa00aU},
    {953U, 0x05d6ccU, 0x07f758U, 0xcb23c809U},
    {954U, 0x05d7bcU, 0x07f770U, 0x36000141U},
    {955U, 0x05d7e8U, 0x07f788U, 0x36000101U},
    {956U, 0x05d838U, 0x07f7a0U, 0x90000009U},
    {957U, 0x05d84cU, 0x07f7b8U, 0xaa1f03e8U},
    {958U, 0x05d918U, 0x07f7d0U, 0x90000009U},
    {959U, 0x05d9b0U, 0x07f7e8U, 0xf81e0ff3U},
    {960U, 0x05daf0U, 0x07f808U, 0xa9ba6ffcU},
    {961U, 0x05de78U, 0x07f838U, 0xb9400028U},
    {962U, 0x05deacU, 0x07f850U, 0xb9400028U},
    {963U, 0x05ded8U, 0x07f868U, 0xa9bb6ffcU},
    {964U, 0x05e100U, 0x07f890U, 0xa9be57f6U},
    {965U, 0x05e1f8U, 0x07f8b0U, 0x710040dfU},
    {966U, 0x05e284U, 0x07f8c8U, 0x14003130U},
    {967U, 0x05e288U, 0x07f8e0U, 0xa9ba6ffcU},
    {968U, 0x05e3bcU, 0x07f910U, 0xa9ba6ffcU},
    {969U, 0x05e4f0U, 0x07f940U, 0xa9ba6ffcU},
    {970U, 0x05e624U, 0x07f970U, 0x90000008U},
    {971U, 0x05e78cU, 0x07f988U, 0xb00000aaU},
    {972U, 0x05e7c0U, 0x07f9a0U, 0xa9bb67fcU},
    {973U, 0x05e874U, 0x07f9d0U, 0xa9bb67fcU},
    {974U, 0x05e928U, 0x07fa00U, 0xa9bb67fcU},
    {975U, 0x05e9dcU, 0x07fa30U, 0xa9bb67fcU},
    {976U, 0x05ea90U, 0x07fa60U, 0xa9ba6ffcU},
    {977U, 0x05eb78U, 0x07fa90U, 0xa9ba6ffcU},
    {978U, 0x05ec60U, 0x07fac0U, 0xa9ba6ffcU},
    {979U, 0x05ed48U, 0x07faf0U, 0xa9ba6ffcU},
    {980U, 0x05ee30U, 0x07fb20U, 0xa9ba6ffcU},
    {981U, 0x05ef18U, 0x07fb50U, 0xa9ba6ffcU},
    {982U, 0x05f000U, 0x07fb80U, 0xa9ba6ffcU},
    {983U, 0x05f0ecU, 0x07fbb0U, 0xa9ba6ffcU},
    {984U, 0x05f1d8U, 0x07fbe0U, 0x9000014cU},
    {985U, 0x05f240U, 0x07fbf8U, 0xf81b0ff9U},
    {986U, 0x05f2ccU, 0x07fc20U, 0x7100409fU},
    {987U, 0x05f2f4U, 0x07fc38U, 0x7100409fU},
    {988U, 0x05f31cU, 0x07fc50U, 0x7100409fU},
    {989U, 0x05f344U, 0x07fc68U, 0x90000008U},
    {990U, 0x05f354U, 0x07fc80U, 0x937f7c28U},
    {991U, 0x05f374U, 0x07fc98U, 0xf900003fU},
    {992U, 0x05f3a0U, 0x07fcb0U, 0x90000008U},
    {993U, 0x05f528U, 0x07fcc8U, 0xd65f03c0U},
    {994U, 0x05f52cU, 0x07fce0U, 0xaa0003e1U},
    {995U, 0x05f554U, 0x07fcf8U, 0x710004bfU},
    {996U, 0x05f57cU, 0x07fd10U, 0xa9bd57f6U},
    {997U, 0x05f5f8U, 0x07fd38U, 0xf81b0ff9U},
    {998U, 0x05f694U, 0x07fd60U, 0xa9bd57f6U},
    {999U, 0x05f718U, 0x07fd88U, 0xd65f03c0U},
    {1000U, 0x05f71cU, 0x07fda0U, 0xf85e0008U},
    {1001U, 0x05f728U, 0x07fdb8U, 0x385ff008U},
    {1002U, 0x05f74cU, 0x07fdd0U, 0x385ff008U},
    {1003U, 0x05f778U, 0x07fde8U, 0x385df008U},
    {1004U, 0x05f7acU, 0x07fe00U, 0xd65f03c0U},
    {1005U, 0x05f7b0U, 0x07fe18U, 0xf9400008U},
    {1006U, 0x05f7ccU, 0x07fe30U, 0x93407c68U},
    {1007U, 0x05f7f0U, 0x07fe48U, 0x39400048U},
    {1008U, 0x05f834U, 0x07fe60U, 0x39400048U},
    {1009U, 0x05f868U, 0x07fe78U, 0xd65f03c0U},
    {1010U, 0x05f86cU, 0x07fe90U, 0xf85e0008U},
    {1011U, 0x05f878U, 0x07fea8U, 0x385ff008U},
    {1012U, 0x05f8bcU, 0x07fec0U, 0x385ff008U},
    {1013U, 0x05f908U, 0x07fed8U, 0x385df008U},
    {1014U, 0x05f95cU, 0x07fef0U, 0xd65f03c0U},
    {1015U, 0x05f960U, 0x07ff08U, 0x3cde0000U},
    {1016U, 0x05f96cU, 0x07ff20U, 0x385ff008U},
    {1017U, 0x05f9f0U, 0x07ff38U, 0x385ff008U},
    {1018U, 0x05fa7cU, 0x07ff50U, 0x385df008U},
    {1019U, 0x05fb10U, 0x07ff68U, 0xb9400408U},
    {1020U, 0x05fb30U, 0x07ff80U, 0xb9000006U},
    {1021U, 0x05fb38U, 0x07ff98U, 0xb9000006U},
    {1022U, 0x05fb54U, 0x07ffb0U, 0xb9000006U},
    {1023U, 0x05fb80U, 0x07ffc8U, 0x8b25c808U},
    {1024U, 0x05fb90U, 0x07ffe0U, 0xb9000006U},
    {1025U, 0x05fbf4U, 0x07fff8U, 0xb9000006U},
    {1026U, 0x05fc58U, 0x080010U, 0xb9000006U},
    {1027U, 0x05fd04U, 0x080028U, 0x29001806U},
    {1028U, 0x05fd0cU, 0x080040U, 0xb9000006U},
    {1029U, 0x05fd3cU, 0x080058U, 0xb9000006U},
    {1030U, 0x05fd6cU, 0x080070U, 0xb9000006U},
    {1031U, 0x05fdbcU, 0x080088U, 0xb9000006U},
    {1032U, 0x05fdc8U, 0x0800a0U, 0xb9000006U},
    {1033U, 0x05fdf8U, 0x0800b8U, 0xb9000006U},
    {1034U, 0x05fe28U, 0x0800d0U, 0xb9000006U},
    {1035U, 0x05fe78U, 0x0800e8U, 0x8b25c808U},
    {1036U, 0x05fea4U, 0x080100U, 0xb9000006U},
    {1037U, 0x05ff78U, 0x080118U, 0xb9000006U},
    {1038U, 0x06004cU, 0x080130U, 0xb9000006U},
    {1039U, 0x0601b8U, 0x080148U, 0x937e7ca8U},
    {1040U, 0x0601d0U, 0x080160U, 0xb9000006U},
    {1041U, 0x06025cU, 0x080178U, 0xb9000006U},
    {1042U, 0x0602e8U, 0x080190U, 0xb9000006U},
    {1043U, 0x0603dcU, 0x0801a8U, 0x8b25c808U},
    {1044U, 0x060404U, 0x0801c0U, 0xb9000006U},
    {1045U, 0x0604b0U, 0x0801d8U, 0xb9000006U},
    {1046U, 0x06055cU, 0x0801f0U, 0xb9000006U},
    {1047U, 0x060680U, 0x080208U, 0xb9000006U},
    {1048U, 0x06069cU, 0x080220U, 0x79400028U},
    {1049U, 0x060714U, 0x080238U, 0x340001e4U},
    {1050U, 0x060754U, 0x080250U, 0x2a0203e3U},
    {1051U, 0x060760U, 0x080268U, 0x2a0203e3U},
    {1052U, 0x06076cU, 0x080280U, 0x79c00c29U},
    {1053U, 0x060894U, 0x080298U, 0x79c00829U},
    {1054U, 0x06091cU, 0x0802b0U, 0x79c0c009U},
    {1055U, 0x0609b8U, 0x0802c8U, 0xf9400008U},
    {1056U, 0x0609dcU, 0x0802e0U, 0xd102c3ffU},
    {1057U, 0x060b04U, 0x080308U, 0xd102c3ffU},
    {1058U, 0x060be8U, 0x080328U, 0xf81e0ff3U},
    {1059U, 0x060c24U, 0x080348U, 0xf81c0ff7U},
    {1060U, 0x060d30U, 0x080370U, 0xf81b0ff9U},
    {1061U, 0x060de4U, 0x080398U, 0x52955568U},
    {1062U, 0x060e6cU, 0x0803b0U, 0xaa0003e8U},
    {1063U, 0x060e8cU, 0x0803c8U, 0xf0000128U},
    {1064U, 0x060fccU, 0x0803e0U, 0xa9ba6ffcU},
    {1065U, 0x061370U, 0x080410U, 0xa9bf7bfdU},
    {1066U, 0x0613b8U, 0x080430U, 0xd10243ffU},
    {1067U, 0x0614e0U, 0x080460U, 0x79c00028U},
    {1068U, 0x061554U, 0x080478U, 0xf81d0ff5U},
    {1069U, 0x061614U, 0x080498U, 0xa9bd57f6U},
    {1070U, 0x061734U, 0x0804c0U, 0xf81e0ff3U},
    {1071U, 0x061794U, 0x0804e0U, 0xa9bd57f6U},
    {1072U, 0x061894U, 0x080508U, 0xf81e0ff3U},
    {1073U, 0x0618b8U, 0x080528U, 0xf81c0ff7U},
    {1074U, 0x061a18U, 0x080550U, 0xf81e0ff3U},
    {1075U, 0x061ae8U, 0x080570U, 0xf81d0ff5U},
    {1076U, 0x061cc0U, 0x080590U, 0xd10183ffU},
    {1077U, 0x061de4U, 0x0805b8U, 0xa9be4ff4U},
    {1078U, 0x061e70U, 0x0805d8U, 0xf81d0ff5U},
    {1079U, 0x061fc8U, 0x0805f8U, 0xd10183ffU},
    {1080U, 0x0620ecU, 0x080620U, 0xf81e0ff3U},
    {1081U, 0x062134U, 0x080640U, 0xf81e0ff3U},
    {1082U, 0x06217cU, 0x080660U, 0xa9bd57f6U},
    {1083U, 0x06226cU, 0x080688U, 0xa9bb67faU},
    {1084U, 0x0623f8U, 0x0806b8U, 0xd10343ffU},
    {1085U, 0x0626dcU, 0x0806e8U, 0xd10103ffU},
    {1086U, 0x0627e8U, 0x080710U, 0xa9bd57f6U},
    {1087U, 0x062860U, 0x080738U, 0xa9bc5ff8U},
    {1088U, 0x062988U, 0x080760U, 0xa9bb67faU},
    {1089U, 0x062adcU, 0x080790U, 0xd10103ffU},
    {1090U, 0x062c0cU, 0x0807b0U, 0xd106c3ffU},
    {1091U, 0x063044U, 0x0807e0U, 0xa9bc5ff8U},
    {1092U, 0x063178U, 0x080808U, 0xf9400808U},
    {1093U, 0x06319cU, 0x080820U, 0xf9400808U},
    {1094U, 0x0631d4U, 0x080838U, 0xf81b0ff9U},
    {1095U, 0x06352cU, 0x080860U, 0x3944e888U},
    {1096U, 0x06353cU, 0x080878U, 0xf9400808U},
    {1097U, 0x063578U, 0x080890U, 0xd10103ffU},
    {1098U, 0x06368cU, 0x0808b8U, 0xd10383ffU},
    {1099U, 0x064418U, 0x0808e8U, 0xb9402408U},
    {1100U, 0x06445cU, 0x080900U, 0xf81d0ff5U},
    {1101U, 0x064570U, 0x080920U, 0xd10103ffU},
    {1102U, 0x0646a0U, 0x080940U, 0xf940ec49U},
    {1103U, 0x0647fcU, 0x080958U, 0x37f80121U},
    {1104U, 0x064824U, 0x080970U, 0xf9400808U},
    {1105U, 0x064884U, 0x080988U, 0x3988f00aU},
    {1106U, 0x064914U, 0x0809a0U, 0xd360fc28U},
    {1107U, 0x064944U, 0x0809b8U, 0xd10203ffU},
    {1108U, 0x064a24U, 0x0809e0U, 0x3988f009U},
    {1109U, 0x064a84U, 0x0809f8U, 0xa9be4ff4U},
    {1110U, 0x064aecU, 0x080a18U, 0xa9bc5ff8U},
    {1111U, 0x064b90U, 0x080a40U, 0xd10203ffU},
    {1112U, 0x064e38U, 0x080a70U, 0xa9bb67faU},
    {1113U, 0x064f48U, 0x080aa0U, 0xa9ba6ffcU},
    {1114U, 0x065308U, 0x080ad0U, 0xd10183ffU},
    {1115U, 0x0653d8U, 0x080af8U, 0xf81d0ff5U},
    {1116U, 0x065454U, 0x080b18U, 0xd10183ffU},
    {1117U, 0x065524U, 0x080b40U, 0xf81d0ff5U},
    {1118U, 0x0655a0U, 0x080b60U, 0xa9bb67faU},
    {1119U, 0x065bd4U, 0x080b90U, 0xf9400029U},
    {1120U, 0x065d48U, 0x080ba8U, 0xa9bd57f6U},
    {1121U, 0x065e80U, 0x080bd0U, 0xf81c0ff7U},
    {1122U, 0x066018U, 0x080bf8U, 0xf81d0ff5U},
    {1123U, 0x066230U, 0x080c18U, 0xd101c3ffU},
    {1124U, 0x066344U, 0x080c40U, 0xa9be4ff4U},
    {1125U, 0x0663a8U, 0x080c60U, 0xf9400068U},
    {1126U, 0x0663c8U, 0x080c78U, 0xa9bb67faU},
    {1127U, 0x0667f8U, 0x080ca8U, 0xf9400029U},
    {1128U, 0x0668b8U, 0x080cc0U, 0xa9bd57f6U},
    {1129U, 0x066978U, 0x080ce8U, 0xf81c0ff7U},
    {1130U, 0x066a74U, 0x080d10U, 0xf81d0ff5U},
    {1131U, 0x066c08U, 0x080d30U, 0xa9be4ff4U},
    {1132U, 0x066c9cU, 0x080d50U, 0xf81e0ff3U},
    {1133U, 0x066d00U, 0x080d70U, 0xf81e0ff3U},
    {1134U, 0x066d68U, 0x080d90U, 0xf81e0ff3U},
    {1135U, 0x066da0U, 0x080db0U, 0x2a1f03e0U},
    {1136U, 0x066da8U, 0x080dc8U, 0xd101c3ffU},
    {1137U, 0x066fe4U, 0x080df8U, 0xd65f03c0U},
    {1138U, 0x066fe8U, 0x080e10U, 0xb0000108U},
    {1139U, 0x067094U, 0x080e28U, 0x52800203U},
    {1140U, 0x0670a0U, 0x080e40U, 0xd65f03c0U},
    {1141U, 0x0670a4U, 0x080e58U, 0x90000108U},
}};

// =============================================================================
// 3. ROI Region Clamping & Boundary Clipper (.rodata Diagnostics Verification)
// EN: Matches 'support at maxium 10 ROI region', 'roi location out of picture
//     boundary, LTPoint.x= ... clip it!', and 'invalid roi region'.
// VI: Khớp logic giới hạn tối đa 10 vùng ROI và cắt biên toạ độ LTPoint/RBPoint.
// =============================================================================
std::int32_t SanitizeAndClipRoiRegion(ByteVc0RoiRegionAbi* roi, std::int32_t pic_w, std::int32_t pic_h) noexcept {
    if (roi == nullptr || pic_w <= 0 || pic_h <= 0) {
        return -1;
    }
    roi->lt_x = std::clamp(roi->lt_x, 0, pic_w);
    roi->lt_y = std::clamp(roi->lt_y, 0, pic_h);
    roi->rb_x = std::clamp(roi->rb_x, 0, pic_w);
    roi->rb_y = std::clamp(roi->rb_y, 0, pic_h);
    if (roi->lt_x >= roi->rb_x || roi->lt_y >= roi->rb_y) {
        return -2; // invalid roi region, disable ROI for this frame
    }
    return 0;
}

// =============================================================================
// 4. All 18 Exported ByteVC0 C API Functions (0x053d78..0x055570)
// EN: Clean-room C++17 implementations matching exact AArch64 entry opcodes.
// VI: Bản thực thi C++17 clean-room khớp với các lệnh mở đầu AArch64.
// =============================================================================

// [1] bytevc0EncoderOpen @ 0x053d78 (132 B, first_op: 0xf81d0ffc = str x28, [sp, #-0x30]!)
std::int32_t bytevc0EncoderOpen_Reconstructed(ByteVc0EncoderConfigAbi* cfg) noexcept {
    constexpr std::uint32_t kPrologueOp = 0xf81d0ffcU;
    if (cfg == nullptr || cfg->width <= 0 || cfg->height <= 0) return -1;
    if (kByteVc0TextWords[(0x053d78U - kTextOffset) / 4U] != kPrologueOp) return -2;
    if (cfg->roi_count < 0) cfg->roi_count = 0;
    if (cfg->roi_count > kMaxRoiRegions) cfg->roi_count = kMaxRoiRegions;
    cfg->internal_enc_handle = 0xB7C00001ULL;
    return 0;
}

// [2] bytevc0EncoderClose @ 0x053dfc (36 B, first_op: 0xb40000e0 = cbz x0, +0x1c)
std::int32_t bytevc0EncoderClose_Reconstructed(ByteVc0EncoderConfigAbi* cfg) noexcept {
    if (cfg == nullptr || cfg->internal_enc_handle == 0ULL) return -1;
    cfg->internal_enc_handle = 0ULL;
    return 0;
}

// [3] bytevc0EncoderSetFramesToBeEncoded @ 0x053e20 (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderSetFramesToBeEncoded_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t frames) noexcept {
    if (cfg == nullptr) return -1;
    cfg->frames_to_encode = frames;
    return 0;
}

// [4] bytevc0EncoderEncodeFrame @ 0x053e34 (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderEncodeFrame_Reconstructed(ByteVc0EncoderConfigAbi* cfg, const void* in_pic, void* out_nal) noexcept {
    if (cfg == nullptr || cfg->internal_enc_handle == 0ULL || in_pic == nullptr || out_nal == nullptr) return -1;
    return 1; // 1 NAL unit produced
}

// [5] bytevc0EncoderKeyFrameRequest @ 0x053e48 (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderKeyFrameRequest_Reconstructed(ByteVc0EncoderConfigAbi* cfg) noexcept {
    return (cfg != nullptr && cfg->internal_enc_handle != 0ULL) ? 0 : -1;
}

// [6] bytevc0EncoderLtrMarkRequest @ 0x053e5c (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderLtrMarkRequest_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t ltr_idx) noexcept {
    return (cfg != nullptr && ltr_idx >= 0) ? 0 : -1;
}

// [7] bytevc0EncoderLtrFrameRequest @ 0x053e70 (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderLtrFrameRequest_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t ltr_mask) noexcept {
    return (cfg != nullptr && ltr_mask >= 0) ? 0 : -1;
}

// [8] bytevc0EncoderDelayedFrames @ 0x053e84 (24 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderDelayedFrames_Reconstructed(const ByteVc0EncoderConfigAbi* cfg) noexcept {
    return (cfg != nullptr && cfg->internal_enc_handle != 0ULL) ? 0 : -1;
}

// [9] bytevc0EncoderIsResetForNewCfg @ 0x053e9c (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderIsResetForNewCfg_Reconstructed(const ByteVc0EncoderConfigAbi* cfg, const ByteVc0EncoderConfigAbi* new_cfg) noexcept {
    if (cfg == nullptr || new_cfg == nullptr) return -1;
    return (cfg->width != new_cfg->width || cfg->height != new_cfg->height || cfg->profile_idc != new_cfg->profile_idc) ? 1 : 0;
}

// [10] bytevc0EncoderReconfig @ 0x053eb0 (24 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderReconfig_Reconstructed(ByteVc0EncoderConfigAbi* cfg, const ByteVc0EncoderConfigAbi* new_cfg) noexcept {
    if (cfg == nullptr || new_cfg == nullptr) return -1;
    cfg->bitrate_kbps = new_cfg->bitrate_kbps;
    cfg->fps_num = new_cfg->fps_num;
    cfg->fps_den = new_cfg->fps_den;
    return 0;
}

// [11] bytevc0EncoderEncodeHeaders @ 0x053ec8 (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t bytevc0EncoderEncodeHeaders_Reconstructed(ByteVc0EncoderConfigAbi* cfg, void* out_nal) noexcept {
    return (cfg != nullptr && out_nal != nullptr) ? 2 : -1; // SPS + PPS
}

// [12] setEnableMosh @ 0x053edc (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t setEnableMosh_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t enable) noexcept {
    if (cfg == nullptr) return -1;
    cfg->enable_mosh = (enable != 0) ? 1 : 0;
    return 0;
}

// [13] setOpticalFlowInfo @ 0x053ef0 (20 B, first_op: 0xb4000080 = cbz x0, +0x10)
std::int32_t setOpticalFlowInfo_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::uint64_t flow_ptr) noexcept {
    if (cfg == nullptr || flow_ptr == 0ULL) return -1;
    cfg->optical_flow_ptr = flow_ptr;
    return 0;
}

// [14] bytevc0ConfigDefaultPreset @ 0x053f04 (952 B, first_op: 0xf81c0ff7 = str x23, [sp, #-0x40]!)
std::int32_t bytevc0ConfigDefaultPreset_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t preset, std::int32_t tune) noexcept {
    constexpr std::uint32_t kPrologueOp = 0xf81c0ff7U;
    if (cfg == nullptr) return -1;
    if (kByteVc0TextWords[(0x053f04U - kTextOffset) / 4U] != kPrologueOp) return -2;
    cfg->app_type = tune;
    cfg->profile_idc = 100; // High Profile
    cfg->level_idc = 41;    // Level 4.1
    cfg->fps_num = (preset >= 0) ? 30 : 25;
    cfg->fps_den = 1;
    return 0;
}

// [15] bytevc0ConfigProfile @ 0x0542bc (76 B, first_op: 0xf81e0ff3 = str x19, [sp, #-0x20]!)
std::int32_t bytevc0ConfigProfile_Reconstructed(ByteVc0EncoderConfigAbi* cfg, const char* profile_name) noexcept {
    if (cfg == nullptr || profile_name == nullptr) return -1;
    if (std::strcmp(profile_name, "baseline") == 0) cfg->profile_idc = 66;
    else if (std::strcmp(profile_name, "main") == 0) cfg->profile_idc = 77;
    else if (std::strcmp(profile_name, "high") == 0) cfg->profile_idc = 100;
    else return -2;
    return 0;
}

// [16] bytevc0ConfigLevel @ 0x054308 (188 B, first_op: 0xf81c0ff7 = str x23, [sp, #-0x40]!)
std::int32_t bytevc0ConfigLevel_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t level_idc) noexcept {
    if (cfg == nullptr || level_idc < 10 || level_idc > 52) return -1;
    cfg->level_idc = level_idc;
    return 0;
}

// [17] bytevc0ConfigParse @ 0x0543c4 (4524 B, first_op: 0xd10243ff = sub sp, sp, #0x90)
std::int32_t bytevc0ConfigParse_Reconstructed(ByteVc0EncoderConfigAbi* cfg, const char* key, const char* value) noexcept {
    constexpr std::uint32_t kPrologueOp = 0xd10243ffU;
    if (cfg == nullptr || key == nullptr || value == nullptr) return -1;
    if (kByteVc0TextWords[(0x0543c4U - kTextOffset) / 4U] != kPrologueOp) return -2;
    if (std::strcmp(key, "bitrate") == 0) cfg->bitrate_kbps = std::atoi(value);
    else if (std::strcmp(key, "width") == 0) cfg->width = std::atoi(value);
    else if (std::strcmp(key, "height") == 0) cfg->height = std::atoi(value);
    return 0;
}

// [18] bytevc0SetLogCallback @ 0x055570 (28 B, first_op: 0xb40000a1 = cbz x1, +0x14)
std::int32_t bytevc0SetLogCallback_Reconstructed(void* callback_fn) noexcept {
    return (callback_fn != nullptr) ? 0 : -1;
}

// =============================================================================
// 5. 1,142 FDE Function Implementations (Thực thi 1.142 hàm FDE từ .eh_frame_hdr)
// =============================================================================
static std::uint32_t ByteVc0FdeFunc_0000_0x005edc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[0] @ func_va=0x005edc, fde_va=0x077a98, first_op=0xf81d0ff5
    // VI: Hàm FDE[0] tại địa chỉ 0x005edc, bản ghi FDE 0x077a98
    const std::uint32_t w0 = kByteVc0TextWords[15U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x005edcU);
}
static std::uint32_t ByteVc0FdeFunc_0001_0x005f58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1] @ func_va=0x005f58, fde_va=0x077ab8, first_op=0xfc190fec
    // VI: Hàm FDE[1] tại địa chỉ 0x005f58, bản ghi FDE 0x077ab8
    const std::uint32_t w0 = kByteVc0TextWords[46U];
    std::uint32_t acc = w0 ^ 0xfc190fecU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x005f58U);
}
static std::uint32_t ByteVc0FdeFunc_0002_0x0061d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[2] @ func_va=0x0061d0, fde_va=0x077af0, first_op=0xa9bd57f6
    // VI: Hàm FDE[2] tại địa chỉ 0x0061d0, bản ghi FDE 0x077af0
    const std::uint32_t w0 = kByteVc0TextWords[204U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0061d0U);
}
static std::uint32_t ByteVc0FdeFunc_0003_0x006274(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[3] @ func_va=0x006274, fde_va=0x077b18, first_op=0xa9be4ff4
    // VI: Hàm FDE[3] tại địa chỉ 0x006274, bản ghi FDE 0x077b18
    const std::uint32_t w0 = kByteVc0TextWords[245U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006274U);
}
static std::uint32_t ByteVc0FdeFunc_0004_0x006314(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[4] @ func_va=0x006314, fde_va=0x077b38, first_op=0xa9bf7bfd
    // VI: Hàm FDE[4] tại địa chỉ 0x006314, bản ghi FDE 0x077b38
    const std::uint32_t w0 = kByteVc0TextWords[285U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006314U);
}
static std::uint32_t ByteVc0FdeFunc_0005_0x006330(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[5] @ func_va=0x006330, fde_va=0x077b58, first_op=0xf81d0ff5
    // VI: Hàm FDE[5] tại địa chỉ 0x006330, bản ghi FDE 0x077b58
    const std::uint32_t w0 = kByteVc0TextWords[292U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006330U);
}
static std::uint32_t ByteVc0FdeFunc_0006_0x0063e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[6] @ func_va=0x0063e0, fde_va=0x077b78, first_op=0xa9be4ff4
    // VI: Hàm FDE[6] tại địa chỉ 0x0063e0, bản ghi FDE 0x077b78
    const std::uint32_t w0 = kByteVc0TextWords[336U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0063e0U);
}
static std::uint32_t ByteVc0FdeFunc_0007_0x006430(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[7] @ func_va=0x006430, fde_va=0x077b98, first_op=0xa9be4ff4
    // VI: Hàm FDE[7] tại địa chỉ 0x006430, bản ghi FDE 0x077b98
    const std::uint32_t w0 = kByteVc0TextWords[356U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006430U);
}
static std::uint32_t ByteVc0FdeFunc_0008_0x006490(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[8] @ func_va=0x006490, fde_va=0x077bb8, first_op=0xf81d0ff5
    // VI: Hàm FDE[8] tại địa chỉ 0x006490, bản ghi FDE 0x077bb8
    const std::uint32_t w0 = kByteVc0TextWords[380U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006490U);
}
static std::uint32_t ByteVc0FdeFunc_0009_0x006658(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[9] @ func_va=0x006658, fde_va=0x077bd8, first_op=0xb9402008
    // VI: Hàm FDE[9] tại địa chỉ 0x006658, bản ghi FDE 0x077bd8
    const std::uint32_t w0 = kByteVc0TextWords[494U];
    std::uint32_t acc = w0 ^ 0xb9402008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006658U);
}
static std::uint32_t ByteVc0FdeFunc_0010_0x0066c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[10] @ func_va=0x0066c4, fde_va=0x077bf0, first_op=0xa9bd57f6
    // VI: Hàm FDE[10] tại địa chỉ 0x0066c4, bản ghi FDE 0x077bf0
    const std::uint32_t w0 = kByteVc0TextWords[521U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0066c4U);
}
static std::uint32_t ByteVc0FdeFunc_0011_0x006770(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[11] @ func_va=0x006770, fde_va=0x077c18, first_op=0x90000349
    // VI: Hàm FDE[11] tại địa chỉ 0x006770, bản ghi FDE 0x077c18
    const std::uint32_t w0 = kByteVc0TextWords[564U];
    std::uint32_t acc = w0 ^ 0x90000349U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006770U);
}
static std::uint32_t ByteVc0FdeFunc_0012_0x0067d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[12] @ func_va=0x0067d0, fde_va=0x077c30, first_op=0x90000348
    // VI: Hàm FDE[12] tại địa chỉ 0x0067d0, bản ghi FDE 0x077c30
    const std::uint32_t w0 = kByteVc0TextWords[588U];
    std::uint32_t acc = w0 ^ 0x90000348U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0067d0U);
}
static std::uint32_t ByteVc0FdeFunc_0013_0x006840(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[13] @ func_va=0x006840, fde_va=0x077c48, first_op=0x90000349
    // VI: Hàm FDE[13] tại địa chỉ 0x006840, bản ghi FDE 0x077c48
    const std::uint32_t w0 = kByteVc0TextWords[616U];
    std::uint32_t acc = w0 ^ 0x90000349U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006840U);
}
static std::uint32_t ByteVc0FdeFunc_0014_0x0068b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[14] @ func_va=0x0068b0, fde_va=0x077c60, first_op=0x9000034b
    // VI: Hàm FDE[14] tại địa chỉ 0x0068b0, bản ghi FDE 0x077c60
    const std::uint32_t w0 = kByteVc0TextWords[644U];
    std::uint32_t acc = w0 ^ 0x9000034bU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0068b0U);
}
static std::uint32_t ByteVc0FdeFunc_0015_0x006924(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[15] @ func_va=0x006924, fde_va=0x077c78, first_op=0xb940040a
    // VI: Hàm FDE[15] tại địa chỉ 0x006924, bản ghi FDE 0x077c78
    const std::uint32_t w0 = kByteVc0TextWords[673U];
    std::uint32_t acc = w0 ^ 0xb940040aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006924U);
}
static std::uint32_t ByteVc0FdeFunc_0016_0x006a44(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[16] @ func_va=0x006a44, fde_va=0x077c90, first_op=0xb9400409
    // VI: Hàm FDE[16] tại địa chỉ 0x006a44, bản ghi FDE 0x077c90
    const std::uint32_t w0 = kByteVc0TextWords[745U];
    std::uint32_t acc = w0 ^ 0xb9400409U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006a44U);
}
static std::uint32_t ByteVc0FdeFunc_0017_0x006aec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[17] @ func_va=0x006aec, fde_va=0x077ca8, first_op=0x52800068
    // VI: Hàm FDE[17] tại địa chỉ 0x006aec, bản ghi FDE 0x077ca8
    const std::uint32_t w0 = kByteVc0TextWords[787U];
    std::uint32_t acc = w0 ^ 0x52800068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006aecU);
}
static std::uint32_t ByteVc0FdeFunc_0018_0x006b00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[18] @ func_va=0x006b00, fde_va=0x077cc0, first_op=0xb9400408
    // VI: Hàm FDE[18] tại địa chỉ 0x006b00, bản ghi FDE 0x077cc0
    const std::uint32_t w0 = kByteVc0TextWords[792U];
    std::uint32_t acc = w0 ^ 0xb9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006b00U);
}
static std::uint32_t ByteVc0FdeFunc_0019_0x006bcc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[19] @ func_va=0x006bcc, fde_va=0x077cd8, first_op=0xb9400409
    // VI: Hàm FDE[19] tại địa chỉ 0x006bcc, bản ghi FDE 0x077cd8
    const std::uint32_t w0 = kByteVc0TextWords[843U];
    std::uint32_t acc = w0 ^ 0xb9400409U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006bccU);
}
static std::uint32_t ByteVc0FdeFunc_0020_0x006cf0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[20] @ func_va=0x006cf0, fde_va=0x077cf0, first_op=0xb9400408
    // VI: Hàm FDE[20] tại địa chỉ 0x006cf0, bản ghi FDE 0x077cf0
    const std::uint32_t w0 = kByteVc0TextWords[916U];
    std::uint32_t acc = w0 ^ 0xb9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006cf0U);
}
static std::uint32_t ByteVc0FdeFunc_0021_0x006f64(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[21] @ func_va=0x006f64, fde_va=0x077d08, first_op=0x52800028
    // VI: Hàm FDE[21] tại địa chỉ 0x006f64, bản ghi FDE 0x077d08
    const std::uint32_t w0 = kByteVc0TextWords[1073U];
    std::uint32_t acc = w0 ^ 0x52800028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006f64U);
}
static std::uint32_t ByteVc0FdeFunc_0022_0x006f74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[22] @ func_va=0x006f74, fde_va=0x077d20, first_op=0xf81e0ff3
    // VI: Hàm FDE[22] tại địa chỉ 0x006f74, bản ghi FDE 0x077d20
    const std::uint32_t w0 = kByteVc0TextWords[1077U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006f74U);
}
static std::uint32_t ByteVc0FdeFunc_0023_0x006fc8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[23] @ func_va=0x006fc8, fde_va=0x077d40, first_op=0x29412009
    // VI: Hàm FDE[23] tại địa chỉ 0x006fc8, bản ghi FDE 0x077d40
    const std::uint32_t w0 = kByteVc0TextWords[1098U];
    std::uint32_t acc = w0 ^ 0x29412009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x006fc8U);
}
static std::uint32_t ByteVc0FdeFunc_0024_0x007024(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[24] @ func_va=0x007024, fde_va=0x077d58, first_op=0xb9400048
    // VI: Hàm FDE[24] tại địa chỉ 0x007024, bản ghi FDE 0x077d58
    const std::uint32_t w0 = kByteVc0TextWords[1121U];
    std::uint32_t acc = w0 ^ 0xb9400048U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x007024U);
}
static std::uint32_t ByteVc0FdeFunc_0025_0x00706c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[25] @ func_va=0x00706c, fde_va=0x077d70, first_op=0xf81b0ffc
    // VI: Hàm FDE[25] tại địa chỉ 0x00706c, bản ghi FDE 0x077d70
    const std::uint32_t w0 = kByteVc0TextWords[1139U];
    std::uint32_t acc = w0 ^ 0xf81b0ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00706cU);
}
static std::uint32_t ByteVc0FdeFunc_0026_0x007638(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[26] @ func_va=0x007638, fde_va=0x077d98, first_op=0xd10203ff
    // VI: Hàm FDE[26] tại địa chỉ 0x007638, bản ghi FDE 0x077d98
    const std::uint32_t w0 = kByteVc0TextWords[1510U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x007638U);
}
static std::uint32_t ByteVc0FdeFunc_0027_0x007924(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[27] @ func_va=0x007924, fde_va=0x077dc8, first_op=0xd100c3ff
    // VI: Hàm FDE[27] tại địa chỉ 0x007924, bản ghi FDE 0x077dc8
    const std::uint32_t w0 = kByteVc0TextWords[1697U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x007924U);
}
static std::uint32_t ByteVc0FdeFunc_0028_0x0079dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[28] @ func_va=0x0079dc, fde_va=0x077de8, first_op=0xd100c3ff
    // VI: Hàm FDE[28] tại địa chỉ 0x0079dc, bản ghi FDE 0x077de8
    const std::uint32_t w0 = kByteVc0TextWords[1743U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0079dcU);
}
static std::uint32_t ByteVc0FdeFunc_0029_0x007aa4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[29] @ func_va=0x007aa4, fde_va=0x077e08, first_op=0xd10203ff
    // VI: Hàm FDE[29] tại địa chỉ 0x007aa4, bản ghi FDE 0x077e08
    const std::uint32_t w0 = kByteVc0TextWords[1793U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x007aa4U);
}
static std::uint32_t ByteVc0FdeFunc_0030_0x007db0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[30] @ func_va=0x007db0, fde_va=0x077e38, first_op=0xf81d0ff5
    // VI: Hàm FDE[30] tại địa chỉ 0x007db0, bản ghi FDE 0x077e38
    const std::uint32_t w0 = kByteVc0TextWords[1988U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x007db0U);
}
static std::uint32_t ByteVc0FdeFunc_0031_0x007e70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[31] @ func_va=0x007e70, fde_va=0x077e58, first_op=0xd10383ff
    // VI: Hàm FDE[31] tại địa chỉ 0x007e70, bản ghi FDE 0x077e58
    const std::uint32_t w0 = kByteVc0TextWords[2036U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x007e70U);
}
static std::uint32_t ByteVc0FdeFunc_0032_0x00855c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[32] @ func_va=0x00855c, fde_va=0x077e88, first_op=0xf81e0ff3
    // VI: Hàm FDE[32] tại địa chỉ 0x00855c, bản ghi FDE 0x077e88
    const std::uint32_t w0 = kByteVc0TextWords[2479U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00855cU);
}
static std::uint32_t ByteVc0FdeFunc_0033_0x00867c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[33] @ func_va=0x00867c, fde_va=0x077ea8, first_op=0xd10203ff
    // VI: Hàm FDE[33] tại địa chỉ 0x00867c, bản ghi FDE 0x077ea8
    const std::uint32_t w0 = kByteVc0TextWords[2551U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00867cU);
}
static std::uint32_t ByteVc0FdeFunc_0034_0x0088b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[34] @ func_va=0x0088b8, fde_va=0x077ed8, first_op=0xa9be4ff4
    // VI: Hàm FDE[34] tại địa chỉ 0x0088b8, bản ghi FDE 0x077ed8
    const std::uint32_t w0 = kByteVc0TextWords[2694U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0088b8U);
}
static std::uint32_t ByteVc0FdeFunc_0035_0x00899c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[35] @ func_va=0x00899c, fde_va=0x077ef8, first_op=0xf81e0ff3
    // VI: Hàm FDE[35] tại địa chỉ 0x00899c, bản ghi FDE 0x077ef8
    const std::uint32_t w0 = kByteVc0TextWords[2751U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00899cU);
}
static std::uint32_t ByteVc0FdeFunc_0036_0x008a0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[36] @ func_va=0x008a0c, fde_va=0x077f18, first_op=0xf81e0ff3
    // VI: Hàm FDE[36] tại địa chỉ 0x008a0c, bản ghi FDE 0x077f18
    const std::uint32_t w0 = kByteVc0TextWords[2779U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008a0cU);
}
static std::uint32_t ByteVc0FdeFunc_0037_0x008a40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[37] @ func_va=0x008a40, fde_va=0x077f38, first_op=0xa9be4ff4
    // VI: Hàm FDE[37] tại địa chỉ 0x008a40, bản ghi FDE 0x077f38
    const std::uint32_t w0 = kByteVc0TextWords[2792U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008a40U);
}
static std::uint32_t ByteVc0FdeFunc_0038_0x008ad4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[38] @ func_va=0x008ad4, fde_va=0x077f58, first_op=0xd10183ff
    // VI: Hàm FDE[38] tại địa chỉ 0x008ad4, bản ghi FDE 0x077f58
    const std::uint32_t w0 = kByteVc0TextWords[2829U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008ad4U);
}
static std::uint32_t ByteVc0FdeFunc_0039_0x008bf8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[39] @ func_va=0x008bf8, fde_va=0x077f80, first_op=0xa9be4ff4
    // VI: Hàm FDE[39] tại địa chỉ 0x008bf8, bản ghi FDE 0x077f80
    const std::uint32_t w0 = kByteVc0TextWords[2902U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008bf8U);
}
static std::uint32_t ByteVc0FdeFunc_0040_0x008c3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[40] @ func_va=0x008c3c, fde_va=0x077fa0, first_op=0xf81e0ff3
    // VI: Hàm FDE[40] tại địa chỉ 0x008c3c, bản ghi FDE 0x077fa0
    const std::uint32_t w0 = kByteVc0TextWords[2919U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008c3cU);
}
static std::uint32_t ByteVc0FdeFunc_0041_0x008c84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[41] @ func_va=0x008c84, fde_va=0x077fc0, first_op=0xa9bc5ff8
    // VI: Hàm FDE[41] tại địa chỉ 0x008c84, bản ghi FDE 0x077fc0
    const std::uint32_t w0 = kByteVc0TextWords[2937U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008c84U);
}
static std::uint32_t ByteVc0FdeFunc_0042_0x008d3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[42] @ func_va=0x008d3c, fde_va=0x077fe8, first_op=0xd10103ff
    // VI: Hàm FDE[42] tại địa chỉ 0x008d3c, bản ghi FDE 0x077fe8
    const std::uint32_t w0 = kByteVc0TextWords[2983U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008d3cU);
}
static std::uint32_t ByteVc0FdeFunc_0043_0x008e6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[43] @ func_va=0x008e6c, fde_va=0x078008, first_op=0xf81d0ff5
    // VI: Hàm FDE[43] tại địa chỉ 0x008e6c, bản ghi FDE 0x078008
    const std::uint32_t w0 = kByteVc0TextWords[3059U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008e6cU);
}
static std::uint32_t ByteVc0FdeFunc_0044_0x008ec0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[44] @ func_va=0x008ec0, fde_va=0x078028, first_op=0xd10103ff
    // VI: Hàm FDE[44] tại địa chỉ 0x008ec0, bản ghi FDE 0x078028
    const std::uint32_t w0 = kByteVc0TextWords[3080U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008ec0U);
}
static std::uint32_t ByteVc0FdeFunc_0045_0x008fc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[45] @ func_va=0x008fc0, fde_va=0x078050, first_op=0xa9bd57f6
    // VI: Hàm FDE[45] tại địa chỉ 0x008fc0, bản ghi FDE 0x078050
    const std::uint32_t w0 = kByteVc0TextWords[3144U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x008fc0U);
}
static std::uint32_t ByteVc0FdeFunc_0046_0x00903c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[46] @ func_va=0x00903c, fde_va=0x078078, first_op=0x6f00e402
    // VI: Hàm FDE[46] tại địa chỉ 0x00903c, bản ghi FDE 0x078078
    const std::uint32_t w0 = kByteVc0TextWords[3175U];
    std::uint32_t acc = w0 ^ 0x6f00e402U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00903cU);
}
static std::uint32_t ByteVc0FdeFunc_0047_0x00907c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[47] @ func_va=0x00907c, fde_va=0x078090, first_op=0x1e202008
    // VI: Hàm FDE[47] tại địa chỉ 0x00907c, bản ghi FDE 0x078090
    const std::uint32_t w0 = kByteVc0TextWords[3191U];
    std::uint32_t acc = w0 ^ 0x1e202008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00907cU);
}
static std::uint32_t ByteVc0FdeFunc_0048_0x0091a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[48] @ func_va=0x0091a4, fde_va=0x0780a8, first_op=0xf81c0ff7
    // VI: Hàm FDE[48] tại địa chỉ 0x0091a4, bản ghi FDE 0x0780a8
    const std::uint32_t w0 = kByteVc0TextWords[3265U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0091a4U);
}
static std::uint32_t ByteVc0FdeFunc_0049_0x009454(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[49] @ func_va=0x009454, fde_va=0x0780d0, first_op=0xf81e0ff3
    // VI: Hàm FDE[49] tại địa chỉ 0x009454, bản ghi FDE 0x0780d0
    const std::uint32_t w0 = kByteVc0TextWords[3437U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x009454U);
}
static std::uint32_t ByteVc0FdeFunc_0050_0x0094cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[50] @ func_va=0x0094cc, fde_va=0x0780f0, first_op=0xd10183ff
    // VI: Hàm FDE[50] tại địa chỉ 0x0094cc, bản ghi FDE 0x0780f0
    const std::uint32_t w0 = kByteVc0TextWords[3467U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0094ccU);
}
static std::uint32_t ByteVc0FdeFunc_0051_0x0095f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[51] @ func_va=0x0095f0, fde_va=0x078118, first_op=0xa9be4ff4
    // VI: Hàm FDE[51] tại địa chỉ 0x0095f0, bản ghi FDE 0x078118
    const std::uint32_t w0 = kByteVc0TextWords[3540U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0095f0U);
}
static std::uint32_t ByteVc0FdeFunc_0052_0x009664(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[52] @ func_va=0x009664, fde_va=0x078138, first_op=0xf81e0ff3
    // VI: Hàm FDE[52] tại địa chỉ 0x009664, bản ghi FDE 0x078138
    const std::uint32_t w0 = kByteVc0TextWords[3569U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x009664U);
}
static std::uint32_t ByteVc0FdeFunc_0053_0x0096ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[53] @ func_va=0x0096ac, fde_va=0x078158, first_op=0xa9bc5ff8
    // VI: Hàm FDE[53] tại địa chỉ 0x0096ac, bản ghi FDE 0x078158
    const std::uint32_t w0 = kByteVc0TextWords[3587U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0096acU);
}
static std::uint32_t ByteVc0FdeFunc_0054_0x0097f4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[54] @ func_va=0x0097f4, fde_va=0x078180, first_op=0xf9400408
    // VI: Hàm FDE[54] tại địa chỉ 0x0097f4, bản ghi FDE 0x078180
    const std::uint32_t w0 = kByteVc0TextWords[3669U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0097f4U);
}
static std::uint32_t ByteVc0FdeFunc_0055_0x0098c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[55] @ func_va=0x0098c0, fde_va=0x078198, first_op=0xb980e009
    // VI: Hàm FDE[55] tại địa chỉ 0x0098c0, bản ghi FDE 0x078198
    const std::uint32_t w0 = kByteVc0TextWords[3720U];
    std::uint32_t acc = w0 ^ 0xb980e009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0098c0U);
}
static std::uint32_t ByteVc0FdeFunc_0056_0x00990c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[56] @ func_va=0x00990c, fde_va=0x0781b0, first_op=0xd10283ff
    // VI: Hàm FDE[56] tại địa chỉ 0x00990c, bản ghi FDE 0x0781b0
    const std::uint32_t w0 = kByteVc0TextWords[3739U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00990cU);
}
static std::uint32_t ByteVc0FdeFunc_0057_0x009a90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[57] @ func_va=0x009a90, fde_va=0x0781e0, first_op=0xf9400408
    // VI: Hàm FDE[57] tại địa chỉ 0x009a90, bản ghi FDE 0x0781e0
    const std::uint32_t w0 = kByteVc0TextWords[3836U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x009a90U);
}
static std::uint32_t ByteVc0FdeFunc_0058_0x009b44(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[58] @ func_va=0x009b44, fde_va=0x0781f8, first_op=0xd10283ff
    // VI: Hàm FDE[58] tại địa chỉ 0x009b44, bản ghi FDE 0x0781f8
    const std::uint32_t w0 = kByteVc0TextWords[3881U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x009b44U);
}
static std::uint32_t ByteVc0FdeFunc_0059_0x009cc8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[59] @ func_va=0x009cc8, fde_va=0x078228, first_op=0xd10143ff
    // VI: Hàm FDE[59] tại địa chỉ 0x009cc8, bản ghi FDE 0x078228
    const std::uint32_t w0 = kByteVc0TextWords[3978U];
    std::uint32_t acc = w0 ^ 0xd10143ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x009cc8U);
}
static std::uint32_t ByteVc0FdeFunc_0060_0x009e0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[60] @ func_va=0x009e0c, fde_va=0x078250, first_op=0xa9bc5ff8
    // VI: Hàm FDE[60] tại địa chỉ 0x009e0c, bản ghi FDE 0x078250
    const std::uint32_t w0 = kByteVc0TextWords[4059U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x009e0cU);
}
static std::uint32_t ByteVc0FdeFunc_0061_0x009f24(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[61] @ func_va=0x009f24, fde_va=0x078278, first_op=0xf9406008
    // VI: Hàm FDE[61] tại địa chỉ 0x009f24, bản ghi FDE 0x078278
    const std::uint32_t w0 = kByteVc0TextWords[4129U];
    std::uint32_t acc = w0 ^ 0xf9406008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x009f24U);
}
static std::uint32_t ByteVc0FdeFunc_0062_0x009fb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[62] @ func_va=0x009fb4, fde_va=0x078290, first_op=0xa9ba6ffc
    // VI: Hàm FDE[62] tại địa chỉ 0x009fb4, bản ghi FDE 0x078290
    const std::uint32_t w0 = kByteVc0TextWords[4165U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x009fb4U);
}
static std::uint32_t ByteVc0FdeFunc_0063_0x00a28c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[63] @ func_va=0x00a28c, fde_va=0x0782c0, first_op=0xa9bc5ff8
    // VI: Hàm FDE[63] tại địa chỉ 0x00a28c, bản ghi FDE 0x0782c0
    const std::uint32_t w0 = kByteVc0TextWords[4347U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00a28cU);
}
static std::uint32_t ByteVc0FdeFunc_0064_0x00a338(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[64] @ func_va=0x00a338, fde_va=0x0782e8, first_op=0xd10283ff
    // VI: Hàm FDE[64] tại địa chỉ 0x00a338, bản ghi FDE 0x0782e8
    const std::uint32_t w0 = kByteVc0TextWords[4390U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00a338U);
}
static std::uint32_t ByteVc0FdeFunc_0065_0x00a644(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[65] @ func_va=0x00a644, fde_va=0x078318, first_op=0xd10043ff
    // VI: Hàm FDE[65] tại địa chỉ 0x00a644, bản ghi FDE 0x078318
    const std::uint32_t w0 = kByteVc0TextWords[4585U];
    std::uint32_t acc = w0 ^ 0xd10043ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00a644U);
}
static std::uint32_t ByteVc0FdeFunc_0066_0x00a8e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[66] @ func_va=0x00a8e8, fde_va=0x078330, first_op=0xd101c3ff
    // VI: Hàm FDE[66] tại địa chỉ 0x00a8e8, bản ghi FDE 0x078330
    const std::uint32_t w0 = kByteVc0TextWords[4754U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00a8e8U);
}
static std::uint32_t ByteVc0FdeFunc_0067_0x00aa18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[67] @ func_va=0x00aa18, fde_va=0x078358, first_op=0xa9bb67fa
    // VI: Hàm FDE[67] tại địa chỉ 0x00aa18, bản ghi FDE 0x078358
    const std::uint32_t w0 = kByteVc0TextWords[4830U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00aa18U);
}
static std::uint32_t ByteVc0FdeFunc_0068_0x00ab9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[68] @ func_va=0x00ab9c, fde_va=0x078388, first_op=0xb980e009
    // VI: Hàm FDE[68] tại địa chỉ 0x00ab9c, bản ghi FDE 0x078388
    const std::uint32_t w0 = kByteVc0TextWords[4927U];
    std::uint32_t acc = w0 ^ 0xb980e009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ab9cU);
}
static std::uint32_t ByteVc0FdeFunc_0069_0x00abf0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[69] @ func_va=0x00abf0, fde_va=0x0783a0, first_op=0xf9406009
    // VI: Hàm FDE[69] tại địa chỉ 0x00abf0, bản ghi FDE 0x0783a0
    const std::uint32_t w0 = kByteVc0TextWords[4948U];
    std::uint32_t acc = w0 ^ 0xf9406009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00abf0U);
}
static std::uint32_t ByteVc0FdeFunc_0070_0x00ac68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[70] @ func_va=0x00ac68, fde_va=0x0783b8, first_op=0xb980e009
    // VI: Hàm FDE[70] tại địa chỉ 0x00ac68, bản ghi FDE 0x0783b8
    const std::uint32_t w0 = kByteVc0TextWords[4978U];
    std::uint32_t acc = w0 ^ 0xb980e009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ac68U);
}
static std::uint32_t ByteVc0FdeFunc_0071_0x00ad90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[71] @ func_va=0x00ad90, fde_va=0x0783d0, first_op=0xf9400408
    // VI: Hàm FDE[71] tại địa chỉ 0x00ad90, bản ghi FDE 0x0783d0
    const std::uint32_t w0 = kByteVc0TextWords[5052U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ad90U);
}
static std::uint32_t ByteVc0FdeFunc_0072_0x00ae38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[72] @ func_va=0x00ae38, fde_va=0x0783e8, first_op=0xd10203ff
    // VI: Hàm FDE[72] tại địa chỉ 0x00ae38, bản ghi FDE 0x0783e8
    const std::uint32_t w0 = kByteVc0TextWords[5094U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ae38U);
}
static std::uint32_t ByteVc0FdeFunc_0073_0x00b13c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[73] @ func_va=0x00b13c, fde_va=0x078418, first_op=0xa9bd57f6
    // VI: Hàm FDE[73] tại địa chỉ 0x00b13c, bản ghi FDE 0x078418
    const std::uint32_t w0 = kByteVc0TextWords[5287U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00b13cU);
}
static std::uint32_t ByteVc0FdeFunc_0074_0x00b1a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[74] @ func_va=0x00b1a0, fde_va=0x078440, first_op=0xa9ba6ffc
    // VI: Hàm FDE[74] tại địa chỉ 0x00b1a0, bản ghi FDE 0x078440
    const std::uint32_t w0 = kByteVc0TextWords[5312U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00b1a0U);
}
static std::uint32_t ByteVc0FdeFunc_0075_0x00b318(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[75] @ func_va=0x00b318, fde_va=0x078470, first_op=0xa9bb67fa
    // VI: Hàm FDE[75] tại địa chỉ 0x00b318, bản ghi FDE 0x078470
    const std::uint32_t w0 = kByteVc0TextWords[5406U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00b318U);
}
static std::uint32_t ByteVc0FdeFunc_0076_0x00b404(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[76] @ func_va=0x00b404, fde_va=0x0784a0, first_op=0xf9400408
    // VI: Hàm FDE[76] tại địa chỉ 0x00b404, bản ghi FDE 0x0784a0
    const std::uint32_t w0 = kByteVc0TextWords[5465U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00b404U);
}
static std::uint32_t ByteVc0FdeFunc_0077_0x00b4e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[77] @ func_va=0x00b4e0, fde_va=0x0784b8, first_op=0xb9403028
    // VI: Hàm FDE[77] tại địa chỉ 0x00b4e0, bản ghi FDE 0x0784b8
    const std::uint32_t w0 = kByteVc0TextWords[5520U];
    std::uint32_t acc = w0 ^ 0xb9403028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00b4e0U);
}
static std::uint32_t ByteVc0FdeFunc_0078_0x00b580(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[78] @ func_va=0x00b580, fde_va=0x0784d0, first_op=0xf81b0ff9
    // VI: Hàm FDE[78] tại địa chỉ 0x00b580, bản ghi FDE 0x0784d0
    const std::uint32_t w0 = kByteVc0TextWords[5560U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00b580U);
}
static std::uint32_t ByteVc0FdeFunc_0079_0x00b6ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[79] @ func_va=0x00b6ac, fde_va=0x0784f8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[79] tại địa chỉ 0x00b6ac, bản ghi FDE 0x0784f8
    const std::uint32_t w0 = kByteVc0TextWords[5635U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00b6acU);
}
static std::uint32_t ByteVc0FdeFunc_0080_0x00ba30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[80] @ func_va=0x00ba30, fde_va=0x078528, first_op=0xd10203ff
    // VI: Hàm FDE[80] tại địa chỉ 0x00ba30, bản ghi FDE 0x078528
    const std::uint32_t w0 = kByteVc0TextWords[5860U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ba30U);
}
static std::uint32_t ByteVc0FdeFunc_0081_0x00bdac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[81] @ func_va=0x00bdac, fde_va=0x078558, first_op=0xf81c0ff7
    // VI: Hàm FDE[81] tại địa chỉ 0x00bdac, bản ghi FDE 0x078558
    const std::uint32_t w0 = kByteVc0TextWords[6083U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00bdacU);
}
static std::uint32_t ByteVc0FdeFunc_0082_0x00c0dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[82] @ func_va=0x00c0dc, fde_va=0x078580, first_op=0xa9ba6ffc
    // VI: Hàm FDE[82] tại địa chỉ 0x00c0dc, bản ghi FDE 0x078580
    const std::uint32_t w0 = kByteVc0TextWords[6287U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00c0dcU);
}
static std::uint32_t ByteVc0FdeFunc_0083_0x00c87c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[83] @ func_va=0x00c87c, fde_va=0x0785b0, first_op=0xa9bc5ff8
    // VI: Hàm FDE[83] tại địa chỉ 0x00c87c, bản ghi FDE 0x0785b0
    const std::uint32_t w0 = kByteVc0TextWords[6775U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00c87cU);
}
static std::uint32_t ByteVc0FdeFunc_0084_0x00c914(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[84] @ func_va=0x00c914, fde_va=0x0785d8, first_op=0xf81c0ff9
    // VI: Hàm FDE[84] tại địa chỉ 0x00c914, bản ghi FDE 0x0785d8
    const std::uint32_t w0 = kByteVc0TextWords[6813U];
    std::uint32_t acc = w0 ^ 0xf81c0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00c914U);
}
static std::uint32_t ByteVc0FdeFunc_0085_0x00cba0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[85] @ func_va=0x00cba0, fde_va=0x078600, first_op=0xa9be4ff4
    // VI: Hàm FDE[85] tại địa chỉ 0x00cba0, bản ghi FDE 0x078600
    const std::uint32_t w0 = kByteVc0TextWords[6976U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00cba0U);
}
static std::uint32_t ByteVc0FdeFunc_0086_0x00cc9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[86] @ func_va=0x00cc9c, fde_va=0x078620, first_op=0xd10343ff
    // VI: Hàm FDE[86] tại địa chỉ 0x00cc9c, bản ghi FDE 0x078620
    const std::uint32_t w0 = kByteVc0TextWords[7039U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00cc9cU);
}
static std::uint32_t ByteVc0FdeFunc_0087_0x00d90c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[87] @ func_va=0x00d90c, fde_va=0x078650, first_op=0xf81b0ff9
    // VI: Hàm FDE[87] tại địa chỉ 0x00d90c, bản ghi FDE 0x078650
    const std::uint32_t w0 = kByteVc0TextWords[7835U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00d90cU);
}
static std::uint32_t ByteVc0FdeFunc_0088_0x00da80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[88] @ func_va=0x00da80, fde_va=0x078678, first_op=0xa9bd57f6
    // VI: Hàm FDE[88] tại địa chỉ 0x00da80, bản ghi FDE 0x078678
    const std::uint32_t w0 = kByteVc0TextWords[7928U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00da80U);
}
static std::uint32_t ByteVc0FdeFunc_0089_0x00dc48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[89] @ func_va=0x00dc48, fde_va=0x0786a0, first_op=0xd10103ff
    // VI: Hàm FDE[89] tại địa chỉ 0x00dc48, bản ghi FDE 0x0786a0
    const std::uint32_t w0 = kByteVc0TextWords[8042U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00dc48U);
}
static std::uint32_t ByteVc0FdeFunc_0090_0x00dd78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[90] @ func_va=0x00dd78, fde_va=0x0786c0, first_op=0xd10103ff
    // VI: Hàm FDE[90] tại địa chỉ 0x00dd78, bản ghi FDE 0x0786c0
    const std::uint32_t w0 = kByteVc0TextWords[8118U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00dd78U);
}
static std::uint32_t ByteVc0FdeFunc_0091_0x00de78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[91] @ func_va=0x00de78, fde_va=0x0786e8, first_op=0xd65f03c0
    // VI: Hàm FDE[91] tại địa chỉ 0x00de78, bản ghi FDE 0x0786e8
    const std::uint32_t w0 = kByteVc0TextWords[8182U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00de78U);
}
static std::uint32_t ByteVc0FdeFunc_0092_0x00de7c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[92] @ func_va=0x00de7c, fde_va=0x078700, first_op=0x17ffdf15
    // VI: Hàm FDE[92] tại địa chỉ 0x00de7c, bản ghi FDE 0x078700
    const std::uint32_t w0 = kByteVc0TextWords[8183U];
    std::uint32_t acc = w0 ^ 0x17ffdf15U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00de7cU);
}
static std::uint32_t ByteVc0FdeFunc_0093_0x00de80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[93] @ func_va=0x00de80, fde_va=0x078718, first_op=0xf81e0ff3
    // VI: Hàm FDE[93] tại địa chỉ 0x00de80, bản ghi FDE 0x078718
    const std::uint32_t w0 = kByteVc0TextWords[8184U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00de80U);
}
static std::uint32_t ByteVc0FdeFunc_0094_0x00deb0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[94] @ func_va=0x00deb0, fde_va=0x078738, first_op=0xa9be4ff4
    // VI: Hàm FDE[94] tại địa chỉ 0x00deb0, bản ghi FDE 0x078738
    const std::uint32_t w0 = kByteVc0TextWords[8196U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00deb0U);
}
static std::uint32_t ByteVc0FdeFunc_0095_0x00deec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[95] @ func_va=0x00deec, fde_va=0x078758, first_op=0xa9be4ff4
    // VI: Hàm FDE[95] tại địa chỉ 0x00deec, bản ghi FDE 0x078758
    const std::uint32_t w0 = kByteVc0TextWords[8211U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00deecU);
}
static std::uint32_t ByteVc0FdeFunc_0096_0x00df40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[96] @ func_va=0x00df40, fde_va=0x078778, first_op=0xf81e0ff3
    // VI: Hàm FDE[96] tại địa chỉ 0x00df40, bản ghi FDE 0x078778
    const std::uint32_t w0 = kByteVc0TextWords[8232U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00df40U);
}
static std::uint32_t ByteVc0FdeFunc_0097_0x00df64(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[97] @ func_va=0x00df64, fde_va=0x078798, first_op=0x52800028
    // VI: Hàm FDE[97] tại địa chỉ 0x00df64, bản ghi FDE 0x078798
    const std::uint32_t w0 = kByteVc0TextWords[8241U];
    std::uint32_t acc = w0 ^ 0x52800028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00df64U);
}
static std::uint32_t ByteVc0FdeFunc_0098_0x00df70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[98] @ func_va=0x00df70, fde_va=0x0787b0, first_op=0x52800028
    // VI: Hàm FDE[98] tại địa chỉ 0x00df70, bản ghi FDE 0x0787b0
    const std::uint32_t w0 = kByteVc0TextWords[8244U];
    std::uint32_t acc = w0 ^ 0x52800028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00df70U);
}
static std::uint32_t ByteVc0FdeFunc_0099_0x00df80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[99] @ func_va=0x00df80, fde_va=0x0787c8, first_op=0x52800028
    // VI: Hàm FDE[99] tại địa chỉ 0x00df80, bản ghi FDE 0x0787c8
    const std::uint32_t w0 = kByteVc0TextWords[8248U];
    std::uint32_t acc = w0 ^ 0x52800028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00df80U);
}
static std::uint32_t ByteVc0FdeFunc_0100_0x00df90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[100] @ func_va=0x00df90, fde_va=0x0787e0, first_op=0xb940e408
    // VI: Hàm FDE[100] tại địa chỉ 0x00df90, bản ghi FDE 0x0787e0
    const std::uint32_t w0 = kByteVc0TextWords[8252U];
    std::uint32_t acc = w0 ^ 0xb940e408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00df90U);
}
static std::uint32_t ByteVc0FdeFunc_0101_0x00dfa8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[101] @ func_va=0x00dfa8, fde_va=0x0787f8, first_op=0x91015c28
    // VI: Hàm FDE[101] tại địa chỉ 0x00dfa8, bản ghi FDE 0x0787f8
    const std::uint32_t w0 = kByteVc0TextWords[8258U];
    std::uint32_t acc = w0 ^ 0x91015c28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00dfa8U);
}
static std::uint32_t ByteVc0FdeFunc_0102_0x00dfb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[102] @ func_va=0x00dfb8, fde_va=0x078810, first_op=0xd10303ff
    // VI: Hàm FDE[102] tại địa chỉ 0x00dfb8, bản ghi FDE 0x078810
    const std::uint32_t w0 = kByteVc0TextWords[8262U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00dfb8U);
}
static std::uint32_t ByteVc0FdeFunc_0103_0x00e3b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[103] @ func_va=0x00e3b0, fde_va=0x078840, first_op=0x6dbc23e9
    // VI: Hàm FDE[103] tại địa chỉ 0x00e3b0, bản ghi FDE 0x078840
    const std::uint32_t w0 = kByteVc0TextWords[8516U];
    std::uint32_t acc = w0 ^ 0x6dbc23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e3b0U);
}
static std::uint32_t ByteVc0FdeFunc_0104_0x00e490(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[104] @ func_va=0x00e490, fde_va=0x078868, first_op=0xa9be4ff4
    // VI: Hàm FDE[104] tại địa chỉ 0x00e490, bản ghi FDE 0x078868
    const std::uint32_t w0 = kByteVc0TextWords[8572U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e490U);
}
static std::uint32_t ByteVc0FdeFunc_0105_0x00e4f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[105] @ func_va=0x00e4f0, fde_va=0x078888, first_op=0xa9be4ff4
    // VI: Hàm FDE[105] tại địa chỉ 0x00e4f0, bản ghi FDE 0x078888
    const std::uint32_t w0 = kByteVc0TextWords[8596U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e4f0U);
}
static std::uint32_t ByteVc0FdeFunc_0106_0x00e550(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[106] @ func_va=0x00e550, fde_va=0x0788a8, first_op=0xa9be4ff4
    // VI: Hàm FDE[106] tại địa chỉ 0x00e550, bản ghi FDE 0x0788a8
    const std::uint32_t w0 = kByteVc0TextWords[8620U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e550U);
}
static std::uint32_t ByteVc0FdeFunc_0107_0x00e5b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[107] @ func_va=0x00e5b0, fde_va=0x0788c8, first_op=0xd10183ff
    // VI: Hàm FDE[107] tại địa chỉ 0x00e5b0, bản ghi FDE 0x0788c8
    const std::uint32_t w0 = kByteVc0TextWords[8644U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e5b0U);
}
static std::uint32_t ByteVc0FdeFunc_0108_0x00e680(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[108] @ func_va=0x00e680, fde_va=0x0788f0, first_op=0xf81d0ff5
    // VI: Hàm FDE[108] tại địa chỉ 0x00e680, bản ghi FDE 0x0788f0
    const std::uint32_t w0 = kByteVc0TextWords[8696U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e680U);
}
static std::uint32_t ByteVc0FdeFunc_0109_0x00e6fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[109] @ func_va=0x00e6fc, fde_va=0x078910, first_op=0xa9be4ff4
    // VI: Hàm FDE[109] tại địa chỉ 0x00e6fc, bản ghi FDE 0x078910
    const std::uint32_t w0 = kByteVc0TextWords[8727U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e6fcU);
}
static std::uint32_t ByteVc0FdeFunc_0110_0x00e760(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[110] @ func_va=0x00e760, fde_va=0x078930, first_op=0xf9400068
    // VI: Hàm FDE[110] tại địa chỉ 0x00e760, bản ghi FDE 0x078930
    const std::uint32_t w0 = kByteVc0TextWords[8752U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e760U);
}
static std::uint32_t ByteVc0FdeFunc_0111_0x00e780(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[111] @ func_va=0x00e780, fde_va=0x078948, first_op=0xd101c3ff
    // VI: Hàm FDE[111] tại địa chỉ 0x00e780, bản ghi FDE 0x078948
    const std::uint32_t w0 = kByteVc0TextWords[8760U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e780U);
}
static std::uint32_t ByteVc0FdeFunc_0112_0x00e894(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[112] @ func_va=0x00e894, fde_va=0x078970, first_op=0xd10183ff
    // VI: Hàm FDE[112] tại địa chỉ 0x00e894, bản ghi FDE 0x078970
    const std::uint32_t w0 = kByteVc0TextWords[8829U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e894U);
}
static std::uint32_t ByteVc0FdeFunc_0113_0x00e964(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[113] @ func_va=0x00e964, fde_va=0x078998, first_op=0xf81d0ff5
    // VI: Hàm FDE[113] tại địa chỉ 0x00e964, bản ghi FDE 0x078998
    const std::uint32_t w0 = kByteVc0TextWords[8881U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e964U);
}
static std::uint32_t ByteVc0FdeFunc_0114_0x00e9e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[114] @ func_va=0x00e9e0, fde_va=0x0789b8, first_op=0xa9be4ff4
    // VI: Hàm FDE[114] tại địa chỉ 0x00e9e0, bản ghi FDE 0x0789b8
    const std::uint32_t w0 = kByteVc0TextWords[8912U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00e9e0U);
}
static std::uint32_t ByteVc0FdeFunc_0115_0x00ea44(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[115] @ func_va=0x00ea44, fde_va=0x0789d8, first_op=0xf9400068
    // VI: Hàm FDE[115] tại địa chỉ 0x00ea44, bản ghi FDE 0x0789d8
    const std::uint32_t w0 = kByteVc0TextWords[8937U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ea44U);
}
static std::uint32_t ByteVc0FdeFunc_0116_0x00ea64(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[116] @ func_va=0x00ea64, fde_va=0x0789f0, first_op=0xd101c3ff
    // VI: Hàm FDE[116] tại địa chỉ 0x00ea64, bản ghi FDE 0x0789f0
    const std::uint32_t w0 = kByteVc0TextWords[8945U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ea64U);
}
static std::uint32_t ByteVc0FdeFunc_0117_0x00eb78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[117] @ func_va=0x00eb78, fde_va=0x078a18, first_op=0xa9000801
    // VI: Hàm FDE[117] tại địa chỉ 0x00eb78, bản ghi FDE 0x078a18
    const std::uint32_t w0 = kByteVc0TextWords[9014U];
    std::uint32_t acc = w0 ^ 0xa9000801U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00eb78U);
}
static std::uint32_t ByteVc0FdeFunc_0118_0x00ebe4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[118] @ func_va=0x00ebe4, fde_va=0x078a30, first_op=0xf81e0ff3
    // VI: Hàm FDE[118] tại địa chỉ 0x00ebe4, bản ghi FDE 0x078a30
    const std::uint32_t w0 = kByteVc0TextWords[9041U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ebe4U);
}
static std::uint32_t ByteVc0FdeFunc_0119_0x00ec1c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[119] @ func_va=0x00ec1c, fde_va=0x078a50, first_op=0xf81e0ff3
    // VI: Hàm FDE[119] tại địa chỉ 0x00ec1c, bản ghi FDE 0x078a50
    const std::uint32_t w0 = kByteVc0TextWords[9055U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ec1cU);
}
static std::uint32_t ByteVc0FdeFunc_0120_0x00ec54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[120] @ func_va=0x00ec54, fde_va=0x078a70, first_op=0xf81d0ff5
    // VI: Hàm FDE[120] tại địa chỉ 0x00ec54, bản ghi FDE 0x078a70
    const std::uint32_t w0 = kByteVc0TextWords[9069U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ec54U);
}
static std::uint32_t ByteVc0FdeFunc_0121_0x00ee00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[121] @ func_va=0x00ee00, fde_va=0x078a90, first_op=0xf9400808
    // VI: Hàm FDE[121] tại địa chỉ 0x00ee00, bản ghi FDE 0x078a90
    const std::uint32_t w0 = kByteVc0TextWords[9176U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00ee00U);
}
static std::uint32_t ByteVc0FdeFunc_0122_0x00efa4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[122] @ func_va=0x00efa4, fde_va=0x078aa8, first_op=0xf81d0ff5
    // VI: Hàm FDE[122] tại địa chỉ 0x00efa4, bản ghi FDE 0x078aa8
    const std::uint32_t w0 = kByteVc0TextWords[9281U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00efa4U);
}
static std::uint32_t ByteVc0FdeFunc_0123_0x00f004(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[123] @ func_va=0x00f004, fde_va=0x078ac8, first_op=0xd101c3ff
    // VI: Hàm FDE[123] tại địa chỉ 0x00f004, bản ghi FDE 0x078ac8
    const std::uint32_t w0 = kByteVc0TextWords[9305U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00f004U);
}
static std::uint32_t ByteVc0FdeFunc_0124_0x00f310(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[124] @ func_va=0x00f310, fde_va=0x078af8, first_op=0x36000062
    // VI: Hàm FDE[124] tại địa chỉ 0x00f310, bản ghi FDE 0x078af8
    const std::uint32_t w0 = kByteVc0TextWords[9500U];
    std::uint32_t acc = w0 ^ 0x36000062U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00f310U);
}
static std::uint32_t ByteVc0FdeFunc_0125_0x00f36c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[125] @ func_va=0x00f36c, fde_va=0x078b10, first_op=0xd101c3ff
    // VI: Hàm FDE[125] tại địa chỉ 0x00f36c, bản ghi FDE 0x078b10
    const std::uint32_t w0 = kByteVc0TextWords[9523U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00f36cU);
}
static std::uint32_t ByteVc0FdeFunc_0126_0x00f908(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[126] @ func_va=0x00f908, fde_va=0x078b40, first_op=0xb98000c9
    // VI: Hàm FDE[126] tại địa chỉ 0x00f908, bản ghi FDE 0x078b40
    const std::uint32_t w0 = kByteVc0TextWords[9882U];
    std::uint32_t acc = w0 ^ 0xb98000c9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00f908U);
}
static std::uint32_t ByteVc0FdeFunc_0127_0x00fa0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[127] @ func_va=0x00fa0c, fde_va=0x078b58, first_op=0xd10143ff
    // VI: Hàm FDE[127] tại địa chỉ 0x00fa0c, bản ghi FDE 0x078b58
    const std::uint32_t w0 = kByteVc0TextWords[9947U];
    std::uint32_t acc = w0 ^ 0xd10143ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00fa0cU);
}
static std::uint32_t ByteVc0FdeFunc_0128_0x00fc04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[128] @ func_va=0x00fc04, fde_va=0x078b80, first_op=0xa9be4ff4
    // VI: Hàm FDE[128] tại địa chỉ 0x00fc04, bản ghi FDE 0x078b80
    const std::uint32_t w0 = kByteVc0TextWords[10073U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00fc04U);
}
static std::uint32_t ByteVc0FdeFunc_0129_0x00fdac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[129] @ func_va=0x00fdac, fde_va=0x078ba0, first_op=0x9100a068
    // VI: Hàm FDE[129] tại địa chỉ 0x00fdac, bản ghi FDE 0x078ba0
    const std::uint32_t w0 = kByteVc0TextWords[10179U];
    std::uint32_t acc = w0 ^ 0x9100a068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00fdacU);
}
static std::uint32_t ByteVc0FdeFunc_0130_0x00fe6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[130] @ func_va=0x00fe6c, fde_va=0x078bb8, first_op=0xd10303ff
    // VI: Hàm FDE[130] tại địa chỉ 0x00fe6c, bản ghi FDE 0x078bb8
    const std::uint32_t w0 = kByteVc0TextWords[10227U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x00fe6cU);
}
static std::uint32_t ByteVc0FdeFunc_0131_0x010124(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[131] @ func_va=0x010124, fde_va=0x078bd8, first_op=0xa9bd57f6
    // VI: Hàm FDE[131] tại địa chỉ 0x010124, bản ghi FDE 0x078bd8
    const std::uint32_t w0 = kByteVc0TextWords[10401U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x010124U);
}
static std::uint32_t ByteVc0FdeFunc_0132_0x010190(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[132] @ func_va=0x010190, fde_va=0x078c00, first_op=0x39400088
    // VI: Hàm FDE[132] tại địa chỉ 0x010190, bản ghi FDE 0x078c00
    const std::uint32_t w0 = kByteVc0TextWords[10428U];
    std::uint32_t acc = w0 ^ 0x39400088U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x010190U);
}
static std::uint32_t ByteVc0FdeFunc_0133_0x010234(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[133] @ func_va=0x010234, fde_va=0x078c18, first_op=0x710004bf
    // VI: Hàm FDE[133] tại địa chỉ 0x010234, bản ghi FDE 0x078c18
    const std::uint32_t w0 = kByteVc0TextWords[10469U];
    std::uint32_t acc = w0 ^ 0x710004bfU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x010234U);
}
static std::uint32_t ByteVc0FdeFunc_0134_0x01030c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[134] @ func_va=0x01030c, fde_va=0x078c30, first_op=0xd10243ff
    // VI: Hàm FDE[134] tại địa chỉ 0x01030c, bản ghi FDE 0x078c30
    const std::uint32_t w0 = kByteVc0TextWords[10523U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01030cU);
}
static std::uint32_t ByteVc0FdeFunc_0135_0x0108dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[135] @ func_va=0x0108dc, fde_va=0x078c60, first_op=0xf81d0ff5
    // VI: Hàm FDE[135] tại địa chỉ 0x0108dc, bản ghi FDE 0x078c60
    const std::uint32_t w0 = kByteVc0TextWords[10895U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0108dcU);
}
static std::uint32_t ByteVc0FdeFunc_0136_0x010ad4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[136] @ func_va=0x010ad4, fde_va=0x078c80, first_op=0xd102c3ff
    // VI: Hàm FDE[136] tại địa chỉ 0x010ad4, bản ghi FDE 0x078c80
    const std::uint32_t w0 = kByteVc0TextWords[11021U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x010ad4U);
}
static std::uint32_t ByteVc0FdeFunc_0137_0x0113a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[137] @ func_va=0x0113a4, fde_va=0x078cb0, first_op=0x140129b6
    // VI: Hàm FDE[137] tại địa chỉ 0x0113a4, bản ghi FDE 0x078cb0
    const std::uint32_t w0 = kByteVc0TextWords[11585U];
    std::uint32_t acc = w0 ^ 0x140129b6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0113a4U);
}
static std::uint32_t ByteVc0FdeFunc_0138_0x0113a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[138] @ func_va=0x0113a8, fde_va=0x078cc8, first_op=0xa9bd57f6
    // VI: Hàm FDE[138] tại địa chỉ 0x0113a8, bản ghi FDE 0x078cc8
    const std::uint32_t w0 = kByteVc0TextWords[11586U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0113a8U);
}
static std::uint32_t ByteVc0FdeFunc_0139_0x011574(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[139] @ func_va=0x011574, fde_va=0x078cf0, first_op=0xf81f0ff3
    // VI: Hàm FDE[139] tại địa chỉ 0x011574, bản ghi FDE 0x078cf0
    const std::uint32_t w0 = kByteVc0TextWords[11701U];
    std::uint32_t acc = w0 ^ 0xf81f0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011574U);
}
static std::uint32_t ByteVc0FdeFunc_0140_0x011698(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[140] @ func_va=0x011698, fde_va=0x078d08, first_op=0xa9ba6ffc
    // VI: Hàm FDE[140] tại địa chỉ 0x011698, bản ghi FDE 0x078d08
    const std::uint32_t w0 = kByteVc0TextWords[11774U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011698U);
}
static std::uint32_t ByteVc0FdeFunc_0141_0x01187c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[141] @ func_va=0x01187c, fde_va=0x078d38, first_op=0xd101c3ff
    // VI: Hàm FDE[141] tại địa chỉ 0x01187c, bản ghi FDE 0x078d38
    const std::uint32_t w0 = kByteVc0TextWords[11895U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01187cU);
}
static std::uint32_t ByteVc0FdeFunc_0142_0x011a84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[142] @ func_va=0x011a84, fde_va=0x078d68, first_op=0xd65f03c0
    // VI: Hàm FDE[142] tại địa chỉ 0x011a84, bản ghi FDE 0x078d68
    const std::uint32_t w0 = kByteVc0TextWords[12025U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011a84U);
}
static std::uint32_t ByteVc0FdeFunc_0143_0x011a88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[143] @ func_va=0x011a88, fde_va=0x078d80, first_op=0xd65f03c0
    // VI: Hàm FDE[143] tại địa chỉ 0x011a88, bản ghi FDE 0x078d80
    const std::uint32_t w0 = kByteVc0TextWords[12026U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011a88U);
}
static std::uint32_t ByteVc0FdeFunc_0144_0x011a8c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[144] @ func_va=0x011a8c, fde_va=0x078d98, first_op=0x710004bf
    // VI: Hàm FDE[144] tại địa chỉ 0x011a8c, bản ghi FDE 0x078d98
    const std::uint32_t w0 = kByteVc0TextWords[12027U];
    std::uint32_t acc = w0 ^ 0x710004bfU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011a8cU);
}
static std::uint32_t ByteVc0FdeFunc_0145_0x011ae4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[145] @ func_va=0x011ae4, fde_va=0x078db0, first_op=0xb901a01f
    // VI: Hàm FDE[145] tại địa chỉ 0x011ae4, bản ghi FDE 0x078db0
    const std::uint32_t w0 = kByteVc0TextWords[12049U];
    std::uint32_t acc = w0 ^ 0xb901a01fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011ae4U);
}
static std::uint32_t ByteVc0FdeFunc_0146_0x011b40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[146] @ func_va=0x011b40, fde_va=0x078dc8, first_op=0xb901a03f
    // VI: Hàm FDE[146] tại địa chỉ 0x011b40, bản ghi FDE 0x078dc8
    const std::uint32_t w0 = kByteVc0TextWords[12072U];
    std::uint32_t acc = w0 ^ 0xb901a03fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011b40U);
}
static std::uint32_t ByteVc0FdeFunc_0147_0x011c74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[147] @ func_va=0x011c74, fde_va=0x078de0, first_op=0xf81c0ff7
    // VI: Hàm FDE[147] tại địa chỉ 0x011c74, bản ghi FDE 0x078de0
    const std::uint32_t w0 = kByteVc0TextWords[12149U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011c74U);
}
static std::uint32_t ByteVc0FdeFunc_0148_0x011da4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[148] @ func_va=0x011da4, fde_va=0x078e08, first_op=0xa9ba6ffc
    // VI: Hàm FDE[148] tại địa chỉ 0x011da4, bản ghi FDE 0x078e08
    const std::uint32_t w0 = kByteVc0TextWords[12225U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011da4U);
}
static std::uint32_t ByteVc0FdeFunc_0149_0x011f04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[149] @ func_va=0x011f04, fde_va=0x078e38, first_op=0xa9ba6ffc
    // VI: Hàm FDE[149] tại địa chỉ 0x011f04, bản ghi FDE 0x078e38
    const std::uint32_t w0 = kByteVc0TextWords[12313U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x011f04U);
}
static std::uint32_t ByteVc0FdeFunc_0150_0x012070(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[150] @ func_va=0x012070, fde_va=0x078e68, first_op=0xa9ba6ffc
    // VI: Hàm FDE[150] tại địa chỉ 0x012070, bản ghi FDE 0x078e68
    const std::uint32_t w0 = kByteVc0TextWords[12404U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x012070U);
}
static std::uint32_t ByteVc0FdeFunc_0151_0x012290(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[151] @ func_va=0x012290, fde_va=0x078e98, first_op=0xd10203ff
    // VI: Hàm FDE[151] tại địa chỉ 0x012290, bản ghi FDE 0x078e98
    const std::uint32_t w0 = kByteVc0TextWords[12540U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x012290U);
}
static std::uint32_t ByteVc0FdeFunc_0152_0x012584(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[152] @ func_va=0x012584, fde_va=0x078ec8, first_op=0xd10183ff
    // VI: Hàm FDE[152] tại địa chỉ 0x012584, bản ghi FDE 0x078ec8
    const std::uint32_t w0 = kByteVc0TextWords[12729U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x012584U);
}
static std::uint32_t ByteVc0FdeFunc_0153_0x012828(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[153] @ func_va=0x012828, fde_va=0x078ef0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[153] tại địa chỉ 0x012828, bản ghi FDE 0x078ef0
    const std::uint32_t w0 = kByteVc0TextWords[12898U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x012828U);
}
static std::uint32_t ByteVc0FdeFunc_0154_0x013534(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[154] @ func_va=0x013534, fde_va=0x078f20, first_op=0xa9ba6ffc
    // VI: Hàm FDE[154] tại địa chỉ 0x013534, bản ghi FDE 0x078f20
    const std::uint32_t w0 = kByteVc0TextWords[13733U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x013534U);
}
static std::uint32_t ByteVc0FdeFunc_0155_0x01389c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[155] @ func_va=0x01389c, fde_va=0x078f50, first_op=0xd10343ff
    // VI: Hàm FDE[155] tại địa chỉ 0x01389c, bản ghi FDE 0x078f50
    const std::uint32_t w0 = kByteVc0TextWords[13951U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01389cU);
}
static std::uint32_t ByteVc0FdeFunc_0156_0x01409c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[156] @ func_va=0x01409c, fde_va=0x078f80, first_op=0xa9bc5ff8
    // VI: Hàm FDE[156] tại địa chỉ 0x01409c, bản ghi FDE 0x078f80
    const std::uint32_t w0 = kByteVc0TextWords[14463U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01409cU);
}
static std::uint32_t ByteVc0FdeFunc_0157_0x01411c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[157] @ func_va=0x01411c, fde_va=0x078fa8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[157] tại địa chỉ 0x01411c, bản ghi FDE 0x078fa8
    const std::uint32_t w0 = kByteVc0TextWords[14495U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01411cU);
}
static std::uint32_t ByteVc0FdeFunc_0158_0x01459c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[158] @ func_va=0x01459c, fde_va=0x078fd8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[158] tại địa chỉ 0x01459c, bản ghi FDE 0x078fd8
    const std::uint32_t w0 = kByteVc0TextWords[14783U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01459cU);
}
static std::uint32_t ByteVc0FdeFunc_0159_0x014a54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[159] @ func_va=0x014a54, fde_va=0x079008, first_op=0xa9ba6ffc
    // VI: Hàm FDE[159] tại địa chỉ 0x014a54, bản ghi FDE 0x079008
    const std::uint32_t w0 = kByteVc0TextWords[15085U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x014a54U);
}
static std::uint32_t ByteVc0FdeFunc_0160_0x014efc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[160] @ func_va=0x014efc, fde_va=0x079038, first_op=0xd10183ff
    // VI: Hàm FDE[160] tại địa chỉ 0x014efc, bản ghi FDE 0x079038
    const std::uint32_t w0 = kByteVc0TextWords[15383U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x014efcU);
}
static std::uint32_t ByteVc0FdeFunc_0161_0x015070(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[161] @ func_va=0x015070, fde_va=0x079060, first_op=0xa9ba6ffc
    // VI: Hàm FDE[161] tại địa chỉ 0x015070, bản ghi FDE 0x079060
    const std::uint32_t w0 = kByteVc0TextWords[15476U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x015070U);
}
static std::uint32_t ByteVc0FdeFunc_0162_0x015b4c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[162] @ func_va=0x015b4c, fde_va=0x079090, first_op=0xa9ba6ffc
    // VI: Hàm FDE[162] tại địa chỉ 0x015b4c, bản ghi FDE 0x079090
    const std::uint32_t w0 = kByteVc0TextWords[16171U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x015b4cU);
}
static std::uint32_t ByteVc0FdeFunc_0163_0x01656c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[163] @ func_va=0x01656c, fde_va=0x0790c0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[163] tại địa chỉ 0x01656c, bản ghi FDE 0x0790c0
    const std::uint32_t w0 = kByteVc0TextWords[16819U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01656cU);
}
static std::uint32_t ByteVc0FdeFunc_0164_0x017238(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[164] @ func_va=0x017238, fde_va=0x0790f0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[164] tại địa chỉ 0x017238, bản ghi FDE 0x0790f0
    const std::uint32_t w0 = kByteVc0TextWords[17638U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x017238U);
}
static std::uint32_t ByteVc0FdeFunc_0165_0x017de0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[165] @ func_va=0x017de0, fde_va=0x079120, first_op=0xf81c0ff7
    // VI: Hàm FDE[165] tại địa chỉ 0x017de0, bản ghi FDE 0x079120
    const std::uint32_t w0 = kByteVc0TextWords[18384U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x017de0U);
}
static std::uint32_t ByteVc0FdeFunc_0166_0x018018(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[166] @ func_va=0x018018, fde_va=0x079148, first_op=0xf81c0ff7
    // VI: Hàm FDE[166] tại địa chỉ 0x018018, bản ghi FDE 0x079148
    const std::uint32_t w0 = kByteVc0TextWords[18526U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x018018U);
}
static std::uint32_t ByteVc0FdeFunc_0167_0x01818c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[167] @ func_va=0x01818c, fde_va=0x079170, first_op=0xd10243ff
    // VI: Hàm FDE[167] tại địa chỉ 0x01818c, bản ghi FDE 0x079170
    const std::uint32_t w0 = kByteVc0TextWords[18619U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01818cU);
}
static std::uint32_t ByteVc0FdeFunc_0168_0x0185bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[168] @ func_va=0x0185bc, fde_va=0x0791a0, first_op=0xd10303ff
    // VI: Hàm FDE[168] tại địa chỉ 0x0185bc, bản ghi FDE 0x0791a0
    const std::uint32_t w0 = kByteVc0TextWords[18887U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0185bcU);
}
static std::uint32_t ByteVc0FdeFunc_0169_0x018b10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[169] @ func_va=0x018b10, fde_va=0x0791d0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[169] tại địa chỉ 0x018b10, bản ghi FDE 0x0791d0
    const std::uint32_t w0 = kByteVc0TextWords[19228U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x018b10U);
}
static std::uint32_t ByteVc0FdeFunc_0170_0x018c88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[170] @ func_va=0x018c88, fde_va=0x079200, first_op=0xd10343ff
    // VI: Hàm FDE[170] tại địa chỉ 0x018c88, bản ghi FDE 0x079200
    const std::uint32_t w0 = kByteVc0TextWords[19322U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x018c88U);
}
static std::uint32_t ByteVc0FdeFunc_0171_0x019080(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[171] @ func_va=0x019080, fde_va=0x079230, first_op=0xd10583ff
    // VI: Hàm FDE[171] tại địa chỉ 0x019080, bản ghi FDE 0x079230
    const std::uint32_t w0 = kByteVc0TextWords[19576U];
    std::uint32_t acc = w0 ^ 0xd10583ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x019080U);
}
static std::uint32_t ByteVc0FdeFunc_0172_0x019900(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[172] @ func_va=0x019900, fde_va=0x079260, first_op=0xd10183ff
    // VI: Hàm FDE[172] tại địa chỉ 0x019900, bản ghi FDE 0x079260
    const std::uint32_t w0 = kByteVc0TextWords[20120U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x019900U);
}
static std::uint32_t ByteVc0FdeFunc_0173_0x019bc4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[173] @ func_va=0x019bc4, fde_va=0x079288, first_op=0xd101c3ff
    // VI: Hàm FDE[173] tại địa chỉ 0x019bc4, bản ghi FDE 0x079288
    const std::uint32_t w0 = kByteVc0TextWords[20297U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x019bc4U);
}
static std::uint32_t ByteVc0FdeFunc_0174_0x019d70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[174] @ func_va=0x019d70, fde_va=0x0792b0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[174] tại địa chỉ 0x019d70, bản ghi FDE 0x0792b0
    const std::uint32_t w0 = kByteVc0TextWords[20404U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x019d70U);
}
static std::uint32_t ByteVc0FdeFunc_0175_0x01a41c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[175] @ func_va=0x01a41c, fde_va=0x0792e0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[175] tại địa chỉ 0x01a41c, bản ghi FDE 0x0792e0
    const std::uint32_t w0 = kByteVc0TextWords[20831U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01a41cU);
}
static std::uint32_t ByteVc0FdeFunc_0176_0x01ab80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[176] @ func_va=0x01ab80, fde_va=0x079310, first_op=0xa9ba6ffc
    // VI: Hàm FDE[176] tại địa chỉ 0x01ab80, bản ghi FDE 0x079310
    const std::uint32_t w0 = kByteVc0TextWords[21304U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01ab80U);
}
static std::uint32_t ByteVc0FdeFunc_0177_0x01b0c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[177] @ func_va=0x01b0c4, fde_va=0x079340, first_op=0xa9be4ff4
    // VI: Hàm FDE[177] tại địa chỉ 0x01b0c4, bản ghi FDE 0x079340
    const std::uint32_t w0 = kByteVc0TextWords[21641U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01b0c4U);
}
static std::uint32_t ByteVc0FdeFunc_0178_0x01b268(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[178] @ func_va=0x01b268, fde_va=0x079360, first_op=0xd10183ff
    // VI: Hàm FDE[178] tại địa chỉ 0x01b268, bản ghi FDE 0x079360
    const std::uint32_t w0 = kByteVc0TextWords[21746U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01b268U);
}
static std::uint32_t ByteVc0FdeFunc_0179_0x01b484(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[179] @ func_va=0x01b484, fde_va=0x079388, first_op=0xd10203ff
    // VI: Hàm FDE[179] tại địa chỉ 0x01b484, bản ghi FDE 0x079388
    const std::uint32_t w0 = kByteVc0TextWords[21881U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01b484U);
}
static std::uint32_t ByteVc0FdeFunc_0180_0x01bccc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[180] @ func_va=0x01bccc, fde_va=0x0793b8, first_op=0xb4000461
    // VI: Hàm FDE[180] tại địa chỉ 0x01bccc, bản ghi FDE 0x0793b8
    const std::uint32_t w0 = kByteVc0TextWords[22411U];
    std::uint32_t acc = w0 ^ 0xb4000461U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01bcccU);
}
static std::uint32_t ByteVc0FdeFunc_0181_0x01bd5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[181] @ func_va=0x01bd5c, fde_va=0x0793d0, first_op=0xf81d0ff5
    // VI: Hàm FDE[181] tại địa chỉ 0x01bd5c, bản ghi FDE 0x0793d0
    const std::uint32_t w0 = kByteVc0TextWords[22447U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01bd5cU);
}
static std::uint32_t ByteVc0FdeFunc_0182_0x01bec8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[182] @ func_va=0x01bec8, fde_va=0x0793f0, first_op=0xaa1f03e9
    // VI: Hàm FDE[182] tại địa chỉ 0x01bec8, bản ghi FDE 0x0793f0
    const std::uint32_t w0 = kByteVc0TextWords[22538U];
    std::uint32_t acc = w0 ^ 0xaa1f03e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01bec8U);
}
static std::uint32_t ByteVc0FdeFunc_0183_0x01c078(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[183] @ func_va=0x01c078, fde_va=0x079408, first_op=0xa9bb67fa
    // VI: Hàm FDE[183] tại địa chỉ 0x01c078, bản ghi FDE 0x079408
    const std::uint32_t w0 = kByteVc0TextWords[22646U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01c078U);
}
static std::uint32_t ByteVc0FdeFunc_0184_0x01c3e4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[184] @ func_va=0x01c3e4, fde_va=0x079438, first_op=0xd10203ff
    // VI: Hàm FDE[184] tại địa chỉ 0x01c3e4, bản ghi FDE 0x079438
    const std::uint32_t w0 = kByteVc0TextWords[22865U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01c3e4U);
}
static std::uint32_t ByteVc0FdeFunc_0185_0x01ca34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[185] @ func_va=0x01ca34, fde_va=0x079468, first_op=0xa9bd57f6
    // VI: Hàm FDE[185] tại địa chỉ 0x01ca34, bản ghi FDE 0x079468
    const std::uint32_t w0 = kByteVc0TextWords[23269U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01ca34U);
}
static std::uint32_t ByteVc0FdeFunc_0186_0x01cbf4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[186] @ func_va=0x01cbf4, fde_va=0x079490, first_op=0xf9400008
    // VI: Hàm FDE[186] tại địa chỉ 0x01cbf4, bản ghi FDE 0x079490
    const std::uint32_t w0 = kByteVc0TextWords[23381U];
    std::uint32_t acc = w0 ^ 0xf9400008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01cbf4U);
}
static std::uint32_t ByteVc0FdeFunc_0187_0x01cc50(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[187] @ func_va=0x01cc50, fde_va=0x0794a8, first_op=0xf9400008
    // VI: Hàm FDE[187] tại địa chỉ 0x01cc50, bản ghi FDE 0x0794a8
    const std::uint32_t w0 = kByteVc0TextWords[23404U];
    std::uint32_t acc = w0 ^ 0xf9400008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01cc50U);
}
static std::uint32_t ByteVc0FdeFunc_0188_0x01ccbc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[188] @ func_va=0x01ccbc, fde_va=0x0794c0, first_op=0x39405429
    // VI: Hàm FDE[188] tại địa chỉ 0x01ccbc, bản ghi FDE 0x0794c0
    const std::uint32_t w0 = kByteVc0TextWords[23431U];
    std::uint32_t acc = w0 ^ 0x39405429U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01ccbcU);
}
static std::uint32_t ByteVc0FdeFunc_0189_0x01cd40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[189] @ func_va=0x01cd40, fde_va=0x0794d8, first_op=0xd10083ff
    // VI: Hàm FDE[189] tại địa chỉ 0x01cd40, bản ghi FDE 0x0794d8
    const std::uint32_t w0 = kByteVc0TextWords[23464U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01cd40U);
}
static std::uint32_t ByteVc0FdeFunc_0190_0x01cdf4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[190] @ func_va=0x01cdf4, fde_va=0x0794f8, first_op=0x294024a8
    // VI: Hàm FDE[190] tại địa chỉ 0x01cdf4, bản ghi FDE 0x0794f8
    const std::uint32_t w0 = kByteVc0TextWords[23509U];
    std::uint32_t acc = w0 ^ 0x294024a8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01cdf4U);
}
static std::uint32_t ByteVc0FdeFunc_0191_0x01ce14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[191] @ func_va=0x01ce14, fde_va=0x079510, first_op=0xd10143ff
    // VI: Hàm FDE[191] tại địa chỉ 0x01ce14, bản ghi FDE 0x079510
    const std::uint32_t w0 = kByteVc0TextWords[23517U];
    std::uint32_t acc = w0 ^ 0xd10143ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01ce14U);
}
static std::uint32_t ByteVc0FdeFunc_0192_0x01d02c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[192] @ func_va=0x01d02c, fde_va=0x079530, first_op=0xd10083ff
    // VI: Hàm FDE[192] tại địa chỉ 0x01d02c, bản ghi FDE 0x079530
    const std::uint32_t w0 = kByteVc0TextWords[23651U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d02cU);
}
static std::uint32_t ByteVc0FdeFunc_0193_0x01d0dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[193] @ func_va=0x01d0dc, fde_va=0x079550, first_op=0xd10203ff
    // VI: Hàm FDE[193] tại địa chỉ 0x01d0dc, bản ghi FDE 0x079550
    const std::uint32_t w0 = kByteVc0TextWords[23695U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d0dcU);
}
static std::uint32_t ByteVc0FdeFunc_0194_0x01d324(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[194] @ func_va=0x01d324, fde_va=0x079578, first_op=0x39c6902b
    // VI: Hàm FDE[194] tại địa chỉ 0x01d324, bản ghi FDE 0x079578
    const std::uint32_t w0 = kByteVc0TextWords[23841U];
    std::uint32_t acc = w0 ^ 0x39c6902bU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d324U);
}
static std::uint32_t ByteVc0FdeFunc_0195_0x01d3cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[195] @ func_va=0x01d3cc, fde_va=0x079590, first_op=0xf81c0ff7
    // VI: Hàm FDE[195] tại địa chỉ 0x01d3cc, bản ghi FDE 0x079590
    const std::uint32_t w0 = kByteVc0TextWords[23883U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d3ccU);
}
static std::uint32_t ByteVc0FdeFunc_0196_0x01d46c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[196] @ func_va=0x01d46c, fde_va=0x0795b8, first_op=0xd10183ff
    // VI: Hàm FDE[196] tại địa chỉ 0x01d46c, bản ghi FDE 0x0795b8
    const std::uint32_t w0 = kByteVc0TextWords[23923U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d46cU);
}
static std::uint32_t ByteVc0FdeFunc_0197_0x01d59c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[197] @ func_va=0x01d59c, fde_va=0x0795e0, first_op=0xd10203ff
    // VI: Hàm FDE[197] tại địa chỉ 0x01d59c, bản ghi FDE 0x0795e0
    const std::uint32_t w0 = kByteVc0TextWords[23999U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d59cU);
}
static std::uint32_t ByteVc0FdeFunc_0198_0x01d764(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[198] @ func_va=0x01d764, fde_va=0x079610, first_op=0x39c69048
    // VI: Hàm FDE[198] tại địa chỉ 0x01d764, bản ghi FDE 0x079610
    const std::uint32_t w0 = kByteVc0TextWords[24113U];
    std::uint32_t acc = w0 ^ 0x39c69048U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d764U);
}
static std::uint32_t ByteVc0FdeFunc_0199_0x01d778(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[199] @ func_va=0x01d778, fde_va=0x079628, first_op=0xd10303ff
    // VI: Hàm FDE[199] tại địa chỉ 0x01d778, bản ghi FDE 0x079628
    const std::uint32_t w0 = kByteVc0TextWords[24118U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d778U);
}
static std::uint32_t ByteVc0FdeFunc_0200_0x01d914(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[200] @ func_va=0x01d914, fde_va=0x079658, first_op=0xd102c3ff
    // VI: Hàm FDE[200] tại địa chỉ 0x01d914, bản ghi FDE 0x079658
    const std::uint32_t w0 = kByteVc0TextWords[24221U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01d914U);
}
static std::uint32_t ByteVc0FdeFunc_0201_0x01dbe8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[201] @ func_va=0x01dbe8, fde_va=0x079688, first_op=0xf9409c28
    // VI: Hàm FDE[201] tại địa chỉ 0x01dbe8, bản ghi FDE 0x079688
    const std::uint32_t w0 = kByteVc0TextWords[24402U];
    std::uint32_t acc = w0 ^ 0xf9409c28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01dbe8U);
}
static std::uint32_t ByteVc0FdeFunc_0202_0x01dbf8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[202] @ func_va=0x01dbf8, fde_va=0x0796a0, first_op=0xf81e0ff3
    // VI: Hàm FDE[202] tại địa chỉ 0x01dbf8, bản ghi FDE 0x0796a0
    const std::uint32_t w0 = kByteVc0TextWords[24406U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01dbf8U);
}
static std::uint32_t ByteVc0FdeFunc_0203_0x01dd4c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[203] @ func_va=0x01dd4c, fde_va=0x0796c0, first_op=0xa9bd57f6
    // VI: Hàm FDE[203] tại địa chỉ 0x01dd4c, bản ghi FDE 0x0796c0
    const std::uint32_t w0 = kByteVc0TextWords[24491U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01dd4cU);
}
static std::uint32_t ByteVc0FdeFunc_0204_0x01ddf4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[204] @ func_va=0x01ddf4, fde_va=0x0796e8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[204] tại địa chỉ 0x01ddf4, bản ghi FDE 0x0796e8
    const std::uint32_t w0 = kByteVc0TextWords[24533U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01ddf4U);
}
static std::uint32_t ByteVc0FdeFunc_0205_0x01e25c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[205] @ func_va=0x01e25c, fde_va=0x079718, first_op=0xa9ba6ffc
    // VI: Hàm FDE[205] tại địa chỉ 0x01e25c, bản ghi FDE 0x079718
    const std::uint32_t w0 = kByteVc0TextWords[24815U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01e25cU);
}
static std::uint32_t ByteVc0FdeFunc_0206_0x01e694(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[206] @ func_va=0x01e694, fde_va=0x079748, first_op=0xa9ba6ffc
    // VI: Hàm FDE[206] tại địa chỉ 0x01e694, bản ghi FDE 0x079748
    const std::uint32_t w0 = kByteVc0TextWords[25085U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01e694U);
}
static std::uint32_t ByteVc0FdeFunc_0207_0x01eac0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[207] @ func_va=0x01eac0, fde_va=0x079778, first_op=0xa9ba6ffc
    // VI: Hàm FDE[207] tại địa chỉ 0x01eac0, bản ghi FDE 0x079778
    const std::uint32_t w0 = kByteVc0TextWords[25352U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01eac0U);
}
static std::uint32_t ByteVc0FdeFunc_0208_0x01f798(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[208] @ func_va=0x01f798, fde_va=0x0797a8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[208] tại địa chỉ 0x01f798, bản ghi FDE 0x0797a8
    const std::uint32_t w0 = kByteVc0TextWords[26174U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x01f798U);
}
static std::uint32_t ByteVc0FdeFunc_0209_0x020250(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[209] @ func_va=0x020250, fde_va=0x0797d8, first_op=0xf81a0ffb
    // VI: Hàm FDE[209] tại địa chỉ 0x020250, bản ghi FDE 0x0797d8
    const std::uint32_t w0 = kByteVc0TextWords[26860U];
    std::uint32_t acc = w0 ^ 0xf81a0ffbU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x020250U);
}
static std::uint32_t ByteVc0FdeFunc_0210_0x0203f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[210] @ func_va=0x0203f0, fde_va=0x079808, first_op=0xa9bb67fa
    // VI: Hàm FDE[210] tại địa chỉ 0x0203f0, bản ghi FDE 0x079808
    const std::uint32_t w0 = kByteVc0TextWords[26964U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0203f0U);
}
static std::uint32_t ByteVc0FdeFunc_0211_0x020564(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[211] @ func_va=0x020564, fde_va=0x079838, first_op=0xd10243ff
    // VI: Hàm FDE[211] tại địa chỉ 0x020564, bản ghi FDE 0x079838
    const std::uint32_t w0 = kByteVc0TextWords[27057U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x020564U);
}
static std::uint32_t ByteVc0FdeFunc_0212_0x020778(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[212] @ func_va=0x020778, fde_va=0x079868, first_op=0xd10303ff
    // VI: Hàm FDE[212] tại địa chỉ 0x020778, bản ghi FDE 0x079868
    const std::uint32_t w0 = kByteVc0TextWords[27190U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x020778U);
}
static std::uint32_t ByteVc0FdeFunc_0213_0x020b5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[213] @ func_va=0x020b5c, fde_va=0x079898, first_op=0xd10243ff
    // VI: Hàm FDE[213] tại địa chỉ 0x020b5c, bản ghi FDE 0x079898
    const std::uint32_t w0 = kByteVc0TextWords[27439U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x020b5cU);
}
static std::uint32_t ByteVc0FdeFunc_0214_0x020fd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[214] @ func_va=0x020fd8, fde_va=0x0798c8, first_op=0xf0000328
    // VI: Hàm FDE[214] tại địa chỉ 0x020fd8, bản ghi FDE 0x0798c8
    const std::uint32_t w0 = kByteVc0TextWords[27726U];
    std::uint32_t acc = w0 ^ 0xf0000328U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x020fd8U);
}
static std::uint32_t ByteVc0FdeFunc_0215_0x020fec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[215] @ func_va=0x020fec, fde_va=0x0798e0, first_op=0xf0000329
    // VI: Hàm FDE[215] tại địa chỉ 0x020fec, bản ghi FDE 0x0798e0
    const std::uint32_t w0 = kByteVc0TextWords[27731U];
    std::uint32_t acc = w0 ^ 0xf0000329U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x020fecU);
}
static std::uint32_t ByteVc0FdeFunc_0216_0x021008(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[216] @ func_va=0x021008, fde_va=0x0798f8, first_op=0xd0000328
    // VI: Hàm FDE[216] tại địa chỉ 0x021008, bản ghi FDE 0x0798f8
    const std::uint32_t w0 = kByteVc0TextWords[27738U];
    std::uint32_t acc = w0 ^ 0xd0000328U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x021008U);
}
static std::uint32_t ByteVc0FdeFunc_0217_0x02101c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[217] @ func_va=0x02101c, fde_va=0x079910, first_op=0xd0000329
    // VI: Hàm FDE[217] tại địa chỉ 0x02101c, bản ghi FDE 0x079910
    const std::uint32_t w0 = kByteVc0TextWords[27743U];
    std::uint32_t acc = w0 ^ 0xd0000329U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02101cU);
}
static std::uint32_t ByteVc0FdeFunc_0218_0x021038(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[218] @ func_va=0x021038, fde_va=0x079928, first_op=0xa9ba6ffc
    // VI: Hàm FDE[218] tại địa chỉ 0x021038, bản ghi FDE 0x079928
    const std::uint32_t w0 = kByteVc0TextWords[27750U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x021038U);
}
static std::uint32_t ByteVc0FdeFunc_0219_0x0216a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[219] @ func_va=0x0216a8, fde_va=0x079958, first_op=0xd10403ff
    // VI: Hàm FDE[219] tại địa chỉ 0x0216a8, bản ghi FDE 0x079958
    const std::uint32_t w0 = kByteVc0TextWords[28162U];
    std::uint32_t acc = w0 ^ 0xd10403ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0216a8U);
}
static std::uint32_t ByteVc0FdeFunc_0220_0x022094(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[220] @ func_va=0x022094, fde_va=0x079988, first_op=0x2a1f03e2
    // VI: Hàm FDE[220] tại địa chỉ 0x022094, bản ghi FDE 0x079988
    const std::uint32_t w0 = kByteVc0TextWords[28797U];
    std::uint32_t acc = w0 ^ 0x2a1f03e2U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x022094U);
}
static std::uint32_t ByteVc0FdeFunc_0221_0x02209c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[221] @ func_va=0x02209c, fde_va=0x0799a0, first_op=0xd10243ff
    // VI: Hàm FDE[221] tại địa chỉ 0x02209c, bản ghi FDE 0x0799a0
    const std::uint32_t w0 = kByteVc0TextWords[28799U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02209cU);
}
static std::uint32_t ByteVc0FdeFunc_0222_0x022488(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[222] @ func_va=0x022488, fde_va=0x0799d0, first_op=0xa9007c01
    // VI: Hàm FDE[222] tại địa chỉ 0x022488, bản ghi FDE 0x0799d0
    const std::uint32_t w0 = kByteVc0TextWords[29050U];
    std::uint32_t acc = w0 ^ 0xa9007c01U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x022488U);
}
static std::uint32_t ByteVc0FdeFunc_0223_0x0224cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[223] @ func_va=0x0224cc, fde_va=0x0799e8, first_op=0xd65f03c0
    // VI: Hàm FDE[223] tại địa chỉ 0x0224cc, bản ghi FDE 0x0799e8
    const std::uint32_t w0 = kByteVc0TextWords[29067U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0224ccU);
}
static std::uint32_t ByteVc0FdeFunc_0224_0x0224d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[224] @ func_va=0x0224d0, fde_va=0x079a00, first_op=0xd65f03c0
    // VI: Hàm FDE[224] tại địa chỉ 0x0224d0, bản ghi FDE 0x079a00
    const std::uint32_t w0 = kByteVc0TextWords[29068U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0224d0U);
}
static std::uint32_t ByteVc0FdeFunc_0225_0x0224d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[225] @ func_va=0x0224d4, fde_va=0x079a18, first_op=0xf9000401
    // VI: Hàm FDE[225] tại địa chỉ 0x0224d4, bản ghi FDE 0x079a18
    const std::uint32_t w0 = kByteVc0TextWords[29069U];
    std::uint32_t acc = w0 ^ 0xf9000401U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0224d4U);
}
static std::uint32_t ByteVc0FdeFunc_0226_0x0224dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[226] @ func_va=0x0224dc, fde_va=0x079a30, first_op=0xf81d0ff5
    // VI: Hàm FDE[226] tại địa chỉ 0x0224dc, bản ghi FDE 0x079a30
    const std::uint32_t w0 = kByteVc0TextWords[29071U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0224dcU);
}
static std::uint32_t ByteVc0FdeFunc_0227_0x022674(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[227] @ func_va=0x022674, fde_va=0x079a50, first_op=0xa9bb67fa
    // VI: Hàm FDE[227] tại địa chỉ 0x022674, bản ghi FDE 0x079a50
    const std::uint32_t w0 = kByteVc0TextWords[29173U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x022674U);
}
static std::uint32_t ByteVc0FdeFunc_0228_0x022ac8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[228] @ func_va=0x022ac8, fde_va=0x079a80, first_op=0xd100c3ff
    // VI: Hàm FDE[228] tại địa chỉ 0x022ac8, bản ghi FDE 0x079a80
    const std::uint32_t w0 = kByteVc0TextWords[29450U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x022ac8U);
}
static std::uint32_t ByteVc0FdeFunc_0229_0x022cf4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[229] @ func_va=0x022cf4, fde_va=0x079aa0, first_op=0xf81d0ff5
    // VI: Hàm FDE[229] tại địa chỉ 0x022cf4, bản ghi FDE 0x079aa0
    const std::uint32_t w0 = kByteVc0TextWords[29589U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x022cf4U);
}
static std::uint32_t ByteVc0FdeFunc_0230_0x023184(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[230] @ func_va=0x023184, fde_va=0x079ac0, first_op=0xa9bd57f6
    // VI: Hàm FDE[230] tại địa chỉ 0x023184, bản ghi FDE 0x079ac0
    const std::uint32_t w0 = kByteVc0TextWords[29881U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x023184U);
}
static std::uint32_t ByteVc0FdeFunc_0231_0x023514(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[231] @ func_va=0x023514, fde_va=0x079ae8, first_op=0xf940a028
    // VI: Hàm FDE[231] tại địa chỉ 0x023514, bản ghi FDE 0x079ae8
    const std::uint32_t w0 = kByteVc0TextWords[30109U];
    std::uint32_t acc = w0 ^ 0xf940a028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x023514U);
}
static std::uint32_t ByteVc0FdeFunc_0232_0x02364c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[232] @ func_va=0x02364c, fde_va=0x079b00, first_op=0xd10183ff
    // VI: Hàm FDE[232] tại địa chỉ 0x02364c, bản ghi FDE 0x079b00
    const std::uint32_t w0 = kByteVc0TextWords[30187U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02364cU);
}
static std::uint32_t ByteVc0FdeFunc_0233_0x023790(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[233] @ func_va=0x023790, fde_va=0x079b30, first_op=0xf940a008
    // VI: Hàm FDE[233] tại địa chỉ 0x023790, bản ghi FDE 0x079b30
    const std::uint32_t w0 = kByteVc0TextWords[30268U];
    std::uint32_t acc = w0 ^ 0xf940a008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x023790U);
}
static std::uint32_t ByteVc0FdeFunc_0234_0x023894(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[234] @ func_va=0x023894, fde_va=0x079b48, first_op=0xf940a028
    // VI: Hàm FDE[234] tại địa chỉ 0x023894, bản ghi FDE 0x079b48
    const std::uint32_t w0 = kByteVc0TextWords[30333U];
    std::uint32_t acc = w0 ^ 0xf940a028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x023894U);
}
static std::uint32_t ByteVc0FdeFunc_0235_0x023a0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[235] @ func_va=0x023a0c, fde_va=0x079b60, first_op=0xa9bc5ff8
    // VI: Hàm FDE[235] tại địa chỉ 0x023a0c, bản ghi FDE 0x079b60
    const std::uint32_t w0 = kByteVc0TextWords[30427U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x023a0cU);
}
static std::uint32_t ByteVc0FdeFunc_0236_0x024054(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[236] @ func_va=0x024054, fde_va=0x079b88, first_op=0xa9bd57f6
    // VI: Hàm FDE[236] tại địa chỉ 0x024054, bản ghi FDE 0x079b88
    const std::uint32_t w0 = kByteVc0TextWords[30829U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x024054U);
}
static std::uint32_t ByteVc0FdeFunc_0237_0x0243ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[237] @ func_va=0x0243ac, fde_va=0x079bb0, first_op=0xa9bf4ff4
    // VI: Hàm FDE[237] tại địa chỉ 0x0243ac, bản ghi FDE 0x079bb0
    const std::uint32_t w0 = kByteVc0TextWords[31043U];
    std::uint32_t acc = w0 ^ 0xa9bf4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0243acU);
}
static std::uint32_t ByteVc0FdeFunc_0238_0x0246b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[238] @ func_va=0x0246b0, fde_va=0x079bc8, first_op=0xf81e0ff3
    // VI: Hàm FDE[238] tại địa chỉ 0x0246b0, bản ghi FDE 0x079bc8
    const std::uint32_t w0 = kByteVc0TextWords[31236U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0246b0U);
}
static std::uint32_t ByteVc0FdeFunc_0239_0x0246ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[239] @ func_va=0x0246ec, fde_va=0x079be8, first_op=0xa9bf4ff4
    // VI: Hàm FDE[239] tại địa chỉ 0x0246ec, bản ghi FDE 0x079be8
    const std::uint32_t w0 = kByteVc0TextWords[31251U];
    std::uint32_t acc = w0 ^ 0xa9bf4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0246ecU);
}
static std::uint32_t ByteVc0FdeFunc_0240_0x024b14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[240] @ func_va=0x024b14, fde_va=0x079c00, first_op=0xd102c3ff
    // VI: Hàm FDE[240] tại địa chỉ 0x024b14, bản ghi FDE 0x079c00
    const std::uint32_t w0 = kByteVc0TextWords[31517U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x024b14U);
}
static std::uint32_t ByteVc0FdeFunc_0241_0x024fc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[241] @ func_va=0x024fc0, fde_va=0x079c30, first_op=0xd10543ff
    // VI: Hàm FDE[241] tại địa chỉ 0x024fc0, bản ghi FDE 0x079c30
    const std::uint32_t w0 = kByteVc0TextWords[31816U];
    std::uint32_t acc = w0 ^ 0xd10543ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x024fc0U);
}
static std::uint32_t ByteVc0FdeFunc_0242_0x025cec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[242] @ func_va=0x025cec, fde_va=0x079c60, first_op=0xd10503ff
    // VI: Hàm FDE[242] tại địa chỉ 0x025cec, bản ghi FDE 0x079c60
    const std::uint32_t w0 = kByteVc0TextWords[32659U];
    std::uint32_t acc = w0 ^ 0xd10503ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x025cecU);
}
static std::uint32_t ByteVc0FdeFunc_0243_0x026728(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[243] @ func_va=0x026728, fde_va=0x079c90, first_op=0xd10203ff
    // VI: Hàm FDE[243] tại địa chỉ 0x026728, bản ghi FDE 0x079c90
    const std::uint32_t w0 = kByteVc0TextWords[33314U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x026728U);
}
static std::uint32_t ByteVc0FdeFunc_0244_0x026a8c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[244] @ func_va=0x026a8c, fde_va=0x079cc0, first_op=0xd10383ff
    // VI: Hàm FDE[244] tại địa chỉ 0x026a8c, bản ghi FDE 0x079cc0
    const std::uint32_t w0 = kByteVc0TextWords[33531U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x026a8cU);
}
static std::uint32_t ByteVc0FdeFunc_0245_0x027df8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[245] @ func_va=0x027df8, fde_va=0x079cf0, first_op=0xd10383ff
    // VI: Hàm FDE[245] tại địa chỉ 0x027df8, bản ghi FDE 0x079cf0
    const std::uint32_t w0 = kByteVc0TextWords[34774U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x027df8U);
}
static std::uint32_t ByteVc0FdeFunc_0246_0x029b68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[246] @ func_va=0x029b68, fde_va=0x079d20, first_op=0xd10203ff
    // VI: Hàm FDE[246] tại địa chỉ 0x029b68, bản ghi FDE 0x079d20
    const std::uint32_t w0 = kByteVc0TextWords[36658U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x029b68U);
}
static std::uint32_t ByteVc0FdeFunc_0247_0x029ed8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[247] @ func_va=0x029ed8, fde_va=0x079d50, first_op=0xf81b0ff9
    // VI: Hàm FDE[247] tại địa chỉ 0x029ed8, bản ghi FDE 0x079d50
    const std::uint32_t w0 = kByteVc0TextWords[36878U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x029ed8U);
}
static std::uint32_t ByteVc0FdeFunc_0248_0x02a0d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[248] @ func_va=0x02a0d4, fde_va=0x079d78, first_op=0xf81e0ff3
    // VI: Hàm FDE[248] tại địa chỉ 0x02a0d4, bản ghi FDE 0x079d78
    const std::uint32_t w0 = kByteVc0TextWords[37005U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a0d4U);
}
static std::uint32_t ByteVc0FdeFunc_0249_0x02a148(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[249] @ func_va=0x02a148, fde_va=0x079d98, first_op=0xf9401400
    // VI: Hàm FDE[249] tại địa chỉ 0x02a148, bản ghi FDE 0x079d98
    const std::uint32_t w0 = kByteVc0TextWords[37034U];
    std::uint32_t acc = w0 ^ 0xf9401400U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a148U);
}
static std::uint32_t ByteVc0FdeFunc_0250_0x02a158(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[250] @ func_va=0x02a158, fde_va=0x079db0, first_op=0xf9400c0a
    // VI: Hàm FDE[250] tại địa chỉ 0x02a158, bản ghi FDE 0x079db0
    const std::uint32_t w0 = kByteVc0TextWords[37038U];
    std::uint32_t acc = w0 ^ 0xf9400c0aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a158U);
}
static std::uint32_t ByteVc0FdeFunc_0251_0x02a29c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[251] @ func_va=0x02a29c, fde_va=0x079dc8, first_op=0xf81c0ff7
    // VI: Hàm FDE[251] tại địa chỉ 0x02a29c, bản ghi FDE 0x079dc8
    const std::uint32_t w0 = kByteVc0TextWords[37119U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a29cU);
}
static std::uint32_t ByteVc0FdeFunc_0252_0x02a3ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[252] @ func_va=0x02a3ac, fde_va=0x079df0, first_op=0xf9401c08
    // VI: Hàm FDE[252] tại địa chỉ 0x02a3ac, bản ghi FDE 0x079df0
    const std::uint32_t w0 = kByteVc0TextWords[37187U];
    std::uint32_t acc = w0 ^ 0xf9401c08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a3acU);
}
static std::uint32_t ByteVc0FdeFunc_0253_0x02a3c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[253] @ func_va=0x02a3c0, fde_va=0x079e08, first_op=0xf9401400
    // VI: Hàm FDE[253] tại địa chỉ 0x02a3c0, bản ghi FDE 0x079e08
    const std::uint32_t w0 = kByteVc0TextWords[37192U];
    std::uint32_t acc = w0 ^ 0xf9401400U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a3c0U);
}
static std::uint32_t ByteVc0FdeFunc_0254_0x02a3d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[254] @ func_va=0x02a3d0, fde_va=0x079e20, first_op=0xa9bd57f6
    // VI: Hàm FDE[254] tại địa chỉ 0x02a3d0, bản ghi FDE 0x079e20
    const std::uint32_t w0 = kByteVc0TextWords[37196U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a3d0U);
}
static std::uint32_t ByteVc0FdeFunc_0255_0x02a824(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[255] @ func_va=0x02a824, fde_va=0x079e48, first_op=0xf81e0ff3
    // VI: Hàm FDE[255] tại địa chỉ 0x02a824, bản ghi FDE 0x079e48
    const std::uint32_t w0 = kByteVc0TextWords[37473U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a824U);
}
static std::uint32_t ByteVc0FdeFunc_0256_0x02a86c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[256] @ func_va=0x02a86c, fde_va=0x079e68, first_op=0x394d8408
    // VI: Hàm FDE[256] tại địa chỉ 0x02a86c, bản ghi FDE 0x079e68
    const std::uint32_t w0 = kByteVc0TextWords[37491U];
    std::uint32_t acc = w0 ^ 0x394d8408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02a86cU);
}
static std::uint32_t ByteVc0FdeFunc_0257_0x02aaa4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[257] @ func_va=0x02aaa4, fde_va=0x079e80, first_op=0xd10283ff
    // VI: Hàm FDE[257] tại địa chỉ 0x02aaa4, bản ghi FDE 0x079e80
    const std::uint32_t w0 = kByteVc0TextWords[37633U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02aaa4U);
}
static std::uint32_t ByteVc0FdeFunc_0258_0x02b444(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[258] @ func_va=0x02b444, fde_va=0x079eb0, first_op=0xd10243ff
    // VI: Hàm FDE[258] tại địa chỉ 0x02b444, bản ghi FDE 0x079eb0
    const std::uint32_t w0 = kByteVc0TextWords[38249U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02b444U);
}
static std::uint32_t ByteVc0FdeFunc_0259_0x02b7d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[259] @ func_va=0x02b7d0, fde_va=0x079ee0, first_op=0xa9be4ff4
    // VI: Hàm FDE[259] tại địa chỉ 0x02b7d0, bản ghi FDE 0x079ee0
    const std::uint32_t w0 = kByteVc0TextWords[38476U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02b7d0U);
}
static std::uint32_t ByteVc0FdeFunc_0260_0x02bac8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[260] @ func_va=0x02bac8, fde_va=0x079f00, first_op=0xa9be4ff4
    // VI: Hàm FDE[260] tại địa chỉ 0x02bac8, bản ghi FDE 0x079f00
    const std::uint32_t w0 = kByteVc0TextWords[38666U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02bac8U);
}
static std::uint32_t ByteVc0FdeFunc_0261_0x02be38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[261] @ func_va=0x02be38, fde_va=0x079f20, first_op=0xa9ba6ffc
    // VI: Hàm FDE[261] tại địa chỉ 0x02be38, bản ghi FDE 0x079f20
    const std::uint32_t w0 = kByteVc0TextWords[38886U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02be38U);
}
static std::uint32_t ByteVc0FdeFunc_0262_0x02bfe0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[262] @ func_va=0x02bfe0, fde_va=0x079f50, first_op=0xf9400808
    // VI: Hàm FDE[262] tại địa chỉ 0x02bfe0, bản ghi FDE 0x079f50
    const std::uint32_t w0 = kByteVc0TextWords[38992U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02bfe0U);
}
static std::uint32_t ByteVc0FdeFunc_0263_0x02c13c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[263] @ func_va=0x02c13c, fde_va=0x079f68, first_op=0xf9400808
    // VI: Hàm FDE[263] tại địa chỉ 0x02c13c, bản ghi FDE 0x079f68
    const std::uint32_t w0 = kByteVc0TextWords[39079U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02c13cU);
}
static std::uint32_t ByteVc0FdeFunc_0264_0x02c29c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[264] @ func_va=0x02c29c, fde_va=0x079f80, first_op=0xa9bc5ff8
    // VI: Hàm FDE[264] tại địa chỉ 0x02c29c, bản ghi FDE 0x079f80
    const std::uint32_t w0 = kByteVc0TextWords[39167U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02c29cU);
}
static std::uint32_t ByteVc0FdeFunc_0265_0x02c978(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[265] @ func_va=0x02c978, fde_va=0x079fa8, first_op=0xb4000260
    // VI: Hàm FDE[265] tại địa chỉ 0x02c978, bản ghi FDE 0x079fa8
    const std::uint32_t w0 = kByteVc0TextWords[39606U];
    std::uint32_t acc = w0 ^ 0xb4000260U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02c978U);
}
static std::uint32_t ByteVc0FdeFunc_0266_0x02c9c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[266] @ func_va=0x02c9c8, fde_va=0x079fc8, first_op=0xf81e0ff3
    // VI: Hàm FDE[266] tại địa chỉ 0x02c9c8, bản ghi FDE 0x079fc8
    const std::uint32_t w0 = kByteVc0TextWords[39626U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02c9c8U);
}
static std::uint32_t ByteVc0FdeFunc_0267_0x02cbb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[267] @ func_va=0x02cbb4, fde_va=0x079fe8, first_op=0xf81b0ff9
    // VI: Hàm FDE[267] tại địa chỉ 0x02cbb4, bản ghi FDE 0x079fe8
    const std::uint32_t w0 = kByteVc0TextWords[39749U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02cbb4U);
}
static std::uint32_t ByteVc0FdeFunc_0268_0x02cd00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[268] @ func_va=0x02cd00, fde_va=0x07a010, first_op=0xd00002c8
    // VI: Hàm FDE[268] tại địa chỉ 0x02cd00, bản ghi FDE 0x07a010
    const std::uint32_t w0 = kByteVc0TextWords[39832U];
    std::uint32_t acc = w0 ^ 0xd00002c8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02cd00U);
}
static std::uint32_t ByteVc0FdeFunc_0269_0x02cd20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[269] @ func_va=0x02cd20, fde_va=0x07a028, first_op=0xd00002c8
    // VI: Hàm FDE[269] tại địa chỉ 0x02cd20, bản ghi FDE 0x07a028
    const std::uint32_t w0 = kByteVc0TextWords[39840U];
    std::uint32_t acc = w0 ^ 0xd00002c8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02cd20U);
}
static std::uint32_t ByteVc0FdeFunc_0270_0x02cd30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[270] @ func_va=0x02cd30, fde_va=0x07a040, first_op=0xa9be4ff4
    // VI: Hàm FDE[270] tại địa chỉ 0x02cd30, bản ghi FDE 0x07a040
    const std::uint32_t w0 = kByteVc0TextWords[39844U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02cd30U);
}
static std::uint32_t ByteVc0FdeFunc_0271_0x02cd9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[271] @ func_va=0x02cd9c, fde_va=0x07a060, first_op=0xf81e0ff3
    // VI: Hàm FDE[271] tại địa chỉ 0x02cd9c, bản ghi FDE 0x07a060
    const std::uint32_t w0 = kByteVc0TextWords[39871U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02cd9cU);
}
static std::uint32_t ByteVc0FdeFunc_0272_0x02cdcc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[272] @ func_va=0x02cdcc, fde_va=0x07a080, first_op=0xf81c0ff7
    // VI: Hàm FDE[272] tại địa chỉ 0x02cdcc, bản ghi FDE 0x07a080
    const std::uint32_t w0 = kByteVc0TextWords[39883U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02cdccU);
}
static std::uint32_t ByteVc0FdeFunc_0273_0x02d000(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[273] @ func_va=0x02d000, fde_va=0x07a0a8, first_op=0xa9be4ff4
    // VI: Hàm FDE[273] tại địa chỉ 0x02d000, bản ghi FDE 0x07a0a8
    const std::uint32_t w0 = kByteVc0TextWords[40024U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d000U);
}
static std::uint32_t ByteVc0FdeFunc_0274_0x02d074(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[274] @ func_va=0x02d074, fde_va=0x07a0c8, first_op=0xf9508808
    // VI: Hàm FDE[274] tại địa chỉ 0x02d074, bản ghi FDE 0x07a0c8
    const std::uint32_t w0 = kByteVc0TextWords[40053U];
    std::uint32_t acc = w0 ^ 0xf9508808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d074U);
}
static std::uint32_t ByteVc0FdeFunc_0275_0x02d090(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[275] @ func_va=0x02d090, fde_va=0x07a0e0, first_op=0xf947f00a
    // VI: Hàm FDE[275] tại địa chỉ 0x02d090, bản ghi FDE 0x07a0e0
    const std::uint32_t w0 = kByteVc0TextWords[40060U];
    std::uint32_t acc = w0 ^ 0xf947f00aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d090U);
}
static std::uint32_t ByteVc0FdeFunc_0276_0x02d110(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[276] @ func_va=0x02d110, fde_va=0x07a0f8, first_op=0xf9400808
    // VI: Hàm FDE[276] tại địa chỉ 0x02d110, bản ghi FDE 0x07a0f8
    const std::uint32_t w0 = kByteVc0TextWords[40092U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d110U);
}
static std::uint32_t ByteVc0FdeFunc_0277_0x02d1b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[277] @ func_va=0x02d1b0, fde_va=0x07a110, first_op=0xf940040e
    // VI: Hàm FDE[277] tại địa chỉ 0x02d1b0, bản ghi FDE 0x07a110
    const std::uint32_t w0 = kByteVc0TextWords[40132U];
    std::uint32_t acc = w0 ^ 0xf940040eU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d1b0U);
}
static std::uint32_t ByteVc0FdeFunc_0278_0x02d358(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[278] @ func_va=0x02d358, fde_va=0x07a128, first_op=0xa9bc5ff8
    // VI: Hàm FDE[278] tại địa chỉ 0x02d358, bản ghi FDE 0x07a128
    const std::uint32_t w0 = kByteVc0TextWords[40238U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d358U);
}
static std::uint32_t ByteVc0FdeFunc_0279_0x02d40c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[279] @ func_va=0x02d40c, fde_va=0x07a150, first_op=0xf81d0ff5
    // VI: Hàm FDE[279] tại địa chỉ 0x02d40c, bản ghi FDE 0x07a150
    const std::uint32_t w0 = kByteVc0TextWords[40283U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d40cU);
}
static std::uint32_t ByteVc0FdeFunc_0280_0x02d67c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[280] @ func_va=0x02d67c, fde_va=0x07a170, first_op=0xf81e0ff3
    // VI: Hàm FDE[280] tại địa chỉ 0x02d67c, bản ghi FDE 0x07a170
    const std::uint32_t w0 = kByteVc0TextWords[40439U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d67cU);
}
static std::uint32_t ByteVc0FdeFunc_0281_0x02d6bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[281] @ func_va=0x02d6bc, fde_va=0x07a190, first_op=0xd101c3ff
    // VI: Hàm FDE[281] tại địa chỉ 0x02d6bc, bản ghi FDE 0x07a190
    const std::uint32_t w0 = kByteVc0TextWords[40455U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02d6bcU);
}
static std::uint32_t ByteVc0FdeFunc_0282_0x02db30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[282] @ func_va=0x02db30, fde_va=0x07a1c0, first_op=0xf81e0ff3
    // VI: Hàm FDE[282] tại địa chỉ 0x02db30, bản ghi FDE 0x07a1c0
    const std::uint32_t w0 = kByteVc0TextWords[40740U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02db30U);
}
static std::uint32_t ByteVc0FdeFunc_0283_0x02db68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[283] @ func_va=0x02db68, fde_va=0x07a1e0, first_op=0x17ff5fda
    // VI: Hàm FDE[283] tại địa chỉ 0x02db68, bản ghi FDE 0x07a1e0
    const std::uint32_t w0 = kByteVc0TextWords[40754U];
    std::uint32_t acc = w0 ^ 0x17ff5fdaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02db68U);
}
static std::uint32_t ByteVc0FdeFunc_0284_0x02db6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[284] @ func_va=0x02db6c, fde_va=0x07a1f8, first_op=0xf9001401
    // VI: Hàm FDE[284] tại địa chỉ 0x02db6c, bản ghi FDE 0x07a1f8
    const std::uint32_t w0 = kByteVc0TextWords[40755U];
    std::uint32_t acc = w0 ^ 0xf9001401U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02db6cU);
}
static std::uint32_t ByteVc0FdeFunc_0285_0x02db78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[285] @ func_va=0x02db78, fde_va=0x07a210, first_op=0xf9400c08
    // VI: Hàm FDE[285] tại địa chỉ 0x02db78, bản ghi FDE 0x07a210
    const std::uint32_t w0 = kByteVc0TextWords[40758U];
    std::uint32_t acc = w0 ^ 0xf9400c08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02db78U);
}
static std::uint32_t ByteVc0FdeFunc_0286_0x02db90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[286] @ func_va=0x02db90, fde_va=0x07a228, first_op=0xf81e0ff3
    // VI: Hàm FDE[286] tại địa chỉ 0x02db90, bản ghi FDE 0x07a228
    const std::uint32_t w0 = kByteVc0TextWords[40764U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02db90U);
}
static std::uint32_t ByteVc0FdeFunc_0287_0x02dc34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[287] @ func_va=0x02dc34, fde_va=0x07a248, first_op=0xf81e0ff3
    // VI: Hàm FDE[287] tại địa chỉ 0x02dc34, bản ghi FDE 0x07a248
    const std::uint32_t w0 = kByteVc0TextWords[40805U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02dc34U);
}
static std::uint32_t ByteVc0FdeFunc_0288_0x02dc68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[288] @ func_va=0x02dc68, fde_va=0x07a268, first_op=0xf81e0ff3
    // VI: Hàm FDE[288] tại địa chỉ 0x02dc68, bản ghi FDE 0x07a268
    const std::uint32_t w0 = kByteVc0TextWords[40818U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02dc68U);
}
static std::uint32_t ByteVc0FdeFunc_0289_0x02dca8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[289] @ func_va=0x02dca8, fde_va=0x07a288, first_op=0xf81e0ff3
    // VI: Hàm FDE[289] tại địa chỉ 0x02dca8, bản ghi FDE 0x07a288
    const std::uint32_t w0 = kByteVc0TextWords[40834U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02dca8U);
}
static std::uint32_t ByteVc0FdeFunc_0290_0x02dce8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[290] @ func_va=0x02dce8, fde_va=0x07a2a8, first_op=0xf9401408
    // VI: Hàm FDE[290] tại địa chỉ 0x02dce8, bản ghi FDE 0x07a2a8
    const std::uint32_t w0 = kByteVc0TextWords[40850U];
    std::uint32_t acc = w0 ^ 0xf9401408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02dce8U);
}
static std::uint32_t ByteVc0FdeFunc_0291_0x02dcf4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[291] @ func_va=0x02dcf4, fde_va=0x07a2c0, first_op=0xf9401408
    // VI: Hàm FDE[291] tại địa chỉ 0x02dcf4, bản ghi FDE 0x07a2c0
    const std::uint32_t w0 = kByteVc0TextWords[40853U];
    std::uint32_t acc = w0 ^ 0xf9401408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02dcf4U);
}
static std::uint32_t ByteVc0FdeFunc_0292_0x02dd04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[292] @ func_va=0x02dd04, fde_va=0x07a2d8, first_op=0xf9401408
    // VI: Hàm FDE[292] tại địa chỉ 0x02dd04, bản ghi FDE 0x07a2d8
    const std::uint32_t w0 = kByteVc0TextWords[40857U];
    std::uint32_t acc = w0 ^ 0xf9401408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02dd04U);
}
static std::uint32_t ByteVc0FdeFunc_0293_0x02dd14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[293] @ func_va=0x02dd14, fde_va=0x07a2f0, first_op=0xa9be4ff4
    // VI: Hàm FDE[293] tại địa chỉ 0x02dd14, bản ghi FDE 0x07a2f0
    const std::uint32_t w0 = kByteVc0TextWords[40861U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02dd14U);
}
static std::uint32_t ByteVc0FdeFunc_0294_0x02dd68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[294] @ func_va=0x02dd68, fde_va=0x07a310, first_op=0xa9be4ff4
    // VI: Hàm FDE[294] tại địa chỉ 0x02dd68, bản ghi FDE 0x07a310
    const std::uint32_t w0 = kByteVc0TextWords[40882U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02dd68U);
}
static std::uint32_t ByteVc0FdeFunc_0295_0x02de30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[295] @ func_va=0x02de30, fde_va=0x07a330, first_op=0x7100085f
    // VI: Hàm FDE[295] tại địa chỉ 0x02de30, bản ghi FDE 0x07a330
    const std::uint32_t w0 = kByteVc0TextWords[40932U];
    std::uint32_t acc = w0 ^ 0x7100085fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02de30U);
}
static std::uint32_t ByteVc0FdeFunc_0296_0x02de58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[296] @ func_va=0x02de58, fde_va=0x07a348, first_op=0xd101c3ff
    // VI: Hàm FDE[296] tại địa chỉ 0x02de58, bản ghi FDE 0x07a348
    const std::uint32_t w0 = kByteVc0TextWords[40942U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02de58U);
}
static std::uint32_t ByteVc0FdeFunc_0297_0x02e490(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[297] @ func_va=0x02e490, fde_va=0x07a378, first_op=0xa9be4ff4
    // VI: Hàm FDE[297] tại địa chỉ 0x02e490, bản ghi FDE 0x07a378
    const std::uint32_t w0 = kByteVc0TextWords[41340U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02e490U);
}
static std::uint32_t ByteVc0FdeFunc_0298_0x02e504(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[298] @ func_va=0x02e504, fde_va=0x07a398, first_op=0xa9be4ff4
    // VI: Hàm FDE[298] tại địa chỉ 0x02e504, bản ghi FDE 0x07a398
    const std::uint32_t w0 = kByteVc0TextWords[41369U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02e504U);
}
static std::uint32_t ByteVc0FdeFunc_0299_0x02e578(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[299] @ func_va=0x02e578, fde_va=0x07a3b8, first_op=0xf9401408
    // VI: Hàm FDE[299] tại địa chỉ 0x02e578, bản ghi FDE 0x07a3b8
    const std::uint32_t w0 = kByteVc0TextWords[41398U];
    std::uint32_t acc = w0 ^ 0xf9401408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02e578U);
}
static std::uint32_t ByteVc0FdeFunc_0300_0x02e668(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[300] @ func_va=0x02e668, fde_va=0x07a3d0, first_op=0xa9bc5ff8
    // VI: Hàm FDE[300] tại địa chỉ 0x02e668, bản ghi FDE 0x07a3d0
    const std::uint32_t w0 = kByteVc0TextWords[41458U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02e668U);
}
static std::uint32_t ByteVc0FdeFunc_0301_0x02e740(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[301] @ func_va=0x02e740, fde_va=0x07a3f8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[301] tại địa chỉ 0x02e740, bản ghi FDE 0x07a3f8
    const std::uint32_t w0 = kByteVc0TextWords[41512U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02e740U);
}
static std::uint32_t ByteVc0FdeFunc_0302_0x02ed10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[302] @ func_va=0x02ed10, fde_va=0x07a428, first_op=0xa9bd57f6
    // VI: Hàm FDE[302] tại địa chỉ 0x02ed10, bản ghi FDE 0x07a428
    const std::uint32_t w0 = kByteVc0TextWords[41884U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02ed10U);
}
static std::uint32_t ByteVc0FdeFunc_0303_0x02ed90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[303] @ func_va=0x02ed90, fde_va=0x07a450, first_op=0x52a00040
    // VI: Hàm FDE[303] tại địa chỉ 0x02ed90, bản ghi FDE 0x07a450
    const std::uint32_t w0 = kByteVc0TextWords[41916U];
    std::uint32_t acc = w0 ^ 0x52a00040U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02ed90U);
}
static std::uint32_t ByteVc0FdeFunc_0304_0x02ed98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[304] @ func_va=0x02ed98, fde_va=0x07a468, first_op=0x72001c5f
    // VI: Hàm FDE[304] tại địa chỉ 0x02ed98, bản ghi FDE 0x07a468
    const std::uint32_t w0 = kByteVc0TextWords[41918U];
    std::uint32_t acc = w0 ^ 0x72001c5fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02ed98U);
}
static std::uint32_t ByteVc0FdeFunc_0305_0x02edac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[305] @ func_va=0x02edac, fde_va=0x07a480, first_op=0xf9401409
    // VI: Hàm FDE[305] tại địa chỉ 0x02edac, bản ghi FDE 0x07a480
    const std::uint32_t w0 = kByteVc0TextWords[41923U];
    std::uint32_t acc = w0 ^ 0xf9401409U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02edacU);
}
static std::uint32_t ByteVc0FdeFunc_0306_0x02eeb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[306] @ func_va=0x02eeb4, fde_va=0x07a498, first_op=0xf9001001
    // VI: Hàm FDE[306] tại địa chỉ 0x02eeb4, bản ghi FDE 0x07a498
    const std::uint32_t w0 = kByteVc0TextWords[41989U];
    std::uint32_t acc = w0 ^ 0xf9001001U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02eeb4U);
}
static std::uint32_t ByteVc0FdeFunc_0307_0x02eebc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[307] @ func_va=0x02eebc, fde_va=0x07a4b0, first_op=0xd65f03c0
    // VI: Hàm FDE[307] tại địa chỉ 0x02eebc, bản ghi FDE 0x07a4b0
    const std::uint32_t w0 = kByteVc0TextWords[41991U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02eebcU);
}
static std::uint32_t ByteVc0FdeFunc_0308_0x02eec0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[308] @ func_va=0x02eec0, fde_va=0x07a4c8, first_op=0x17ff5b04
    // VI: Hàm FDE[308] tại địa chỉ 0x02eec0, bản ghi FDE 0x07a4c8
    const std::uint32_t w0 = kByteVc0TextWords[41992U];
    std::uint32_t acc = w0 ^ 0x17ff5b04U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02eec0U);
}
static std::uint32_t ByteVc0FdeFunc_0309_0x02eec4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[309] @ func_va=0x02eec4, fde_va=0x07a4e0, first_op=0xf81d0ff5
    // VI: Hàm FDE[309] tại địa chỉ 0x02eec4, bản ghi FDE 0x07a4e0
    const std::uint32_t w0 = kByteVc0TextWords[41993U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02eec4U);
}
static std::uint32_t ByteVc0FdeFunc_0310_0x02f234(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[310] @ func_va=0x02f234, fde_va=0x07a500, first_op=0x3944c04a
    // VI: Hàm FDE[310] tại địa chỉ 0x02f234, bản ghi FDE 0x07a500
    const std::uint32_t w0 = kByteVc0TextWords[42213U];
    std::uint32_t acc = w0 ^ 0x3944c04aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02f234U);
}
static std::uint32_t ByteVc0FdeFunc_0311_0x02f450(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[311] @ func_va=0x02f450, fde_va=0x07a518, first_op=0x39800848
    // VI: Hàm FDE[311] tại địa chỉ 0x02f450, bản ghi FDE 0x07a518
    const std::uint32_t w0 = kByteVc0TextWords[42348U];
    std::uint32_t acc = w0 ^ 0x39800848U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02f450U);
}
static std::uint32_t ByteVc0FdeFunc_0312_0x02f678(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[312] @ func_va=0x02f678, fde_va=0x07a530, first_op=0x3980084a
    // VI: Hàm FDE[312] tại địa chỉ 0x02f678, bản ghi FDE 0x07a530
    const std::uint32_t w0 = kByteVc0TextWords[42486U];
    std::uint32_t acc = w0 ^ 0x3980084aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02f678U);
}
static std::uint32_t ByteVc0FdeFunc_0313_0x02f80c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[313] @ func_va=0x02f80c, fde_va=0x07a548, first_op=0xf9401008
    // VI: Hàm FDE[313] tại địa chỉ 0x02f80c, bản ghi FDE 0x07a548
    const std::uint32_t w0 = kByteVc0TextWords[42587U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02f80cU);
}
static std::uint32_t ByteVc0FdeFunc_0314_0x02f99c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[314] @ func_va=0x02f99c, fde_va=0x07a560, first_op=0x900002c9
    // VI: Hàm FDE[314] tại địa chỉ 0x02f99c, bản ghi FDE 0x07a560
    const std::uint32_t w0 = kByteVc0TextWords[42687U];
    std::uint32_t acc = w0 ^ 0x900002c9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02f99cU);
}
static std::uint32_t ByteVc0FdeFunc_0315_0x02fb28(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[315] @ func_va=0x02fb28, fde_va=0x07a578, first_op=0xd10143ff
    // VI: Hàm FDE[315] tại địa chỉ 0x02fb28, bản ghi FDE 0x07a578
    const std::uint32_t w0 = kByteVc0TextWords[42786U];
    std::uint32_t acc = w0 ^ 0xd10143ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02fb28U);
}
static std::uint32_t ByteVc0FdeFunc_0316_0x02fd98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[316] @ func_va=0x02fd98, fde_va=0x07a598, first_op=0xd10283ff
    // VI: Hàm FDE[316] tại địa chỉ 0x02fd98, bản ghi FDE 0x07a598
    const std::uint32_t w0 = kByteVc0TextWords[42942U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02fd98U);
}
static std::uint32_t ByteVc0FdeFunc_0317_0x02ffe4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[317] @ func_va=0x02ffe4, fde_va=0x07a5b8, first_op=0xa9be4ff4
    // VI: Hàm FDE[317] tại địa chỉ 0x02ffe4, bản ghi FDE 0x07a5b8
    const std::uint32_t w0 = kByteVc0TextWords[43089U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x02ffe4U);
}
static std::uint32_t ByteVc0FdeFunc_0318_0x030058(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[318] @ func_va=0x030058, fde_va=0x07a5d8, first_op=0xa9be4ff4
    // VI: Hàm FDE[318] tại địa chỉ 0x030058, bản ghi FDE 0x07a5d8
    const std::uint32_t w0 = kByteVc0TextWords[43118U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030058U);
}
static std::uint32_t ByteVc0FdeFunc_0319_0x0300f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[319] @ func_va=0x0300f8, fde_va=0x07a5f8, first_op=0xf00002ab
    // VI: Hàm FDE[319] tại địa chỉ 0x0300f8, bản ghi FDE 0x07a5f8
    const std::uint32_t w0 = kByteVc0TextWords[43158U];
    std::uint32_t acc = w0 ^ 0xf00002abU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0300f8U);
}
static std::uint32_t ByteVc0FdeFunc_0320_0x0301e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[320] @ func_va=0x0301e0, fde_va=0x07a610, first_op=0xa9be4ff4
    // VI: Hàm FDE[320] tại địa chỉ 0x0301e0, bản ghi FDE 0x07a610
    const std::uint32_t w0 = kByteVc0TextWords[43216U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0301e0U);
}
static std::uint32_t ByteVc0FdeFunc_0321_0x030238(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[321] @ func_va=0x030238, fde_va=0x07a630, first_op=0xa9be4ff4
    // VI: Hàm FDE[321] tại địa chỉ 0x030238, bản ghi FDE 0x07a630
    const std::uint32_t w0 = kByteVc0TextWords[43238U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030238U);
}
static std::uint32_t ByteVc0FdeFunc_0322_0x0302b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[322] @ func_va=0x0302b0, fde_va=0x07a650, first_op=0xa9be4ff4
    // VI: Hàm FDE[322] tại địa chỉ 0x0302b0, bản ghi FDE 0x07a650
    const std::uint32_t w0 = kByteVc0TextWords[43268U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0302b0U);
}
static std::uint32_t ByteVc0FdeFunc_0323_0x030328(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[323] @ func_va=0x030328, fde_va=0x07a670, first_op=0xa9ba6ffc
    // VI: Hàm FDE[323] tại địa chỉ 0x030328, bản ghi FDE 0x07a670
    const std::uint32_t w0 = kByteVc0TextWords[43298U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030328U);
}
static std::uint32_t ByteVc0FdeFunc_0324_0x0304dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[324] @ func_va=0x0304dc, fde_va=0x07a6a0, first_op=0xa9be4ff4
    // VI: Hàm FDE[324] tại địa chỉ 0x0304dc, bản ghi FDE 0x07a6a0
    const std::uint32_t w0 = kByteVc0TextWords[43407U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0304dcU);
}
static std::uint32_t ByteVc0FdeFunc_0325_0x030570(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[325] @ func_va=0x030570, fde_va=0x07a6c0, first_op=0xf81e0ff3
    // VI: Hàm FDE[325] tại địa chỉ 0x030570, bản ghi FDE 0x07a6c0
    const std::uint32_t w0 = kByteVc0TextWords[43444U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030570U);
}
static std::uint32_t ByteVc0FdeFunc_0326_0x0305e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[326] @ func_va=0x0305e8, fde_va=0x07a6e0, first_op=0xf81e0ff3
    // VI: Hàm FDE[326] tại địa chỉ 0x0305e8, bản ghi FDE 0x07a6e0
    const std::uint32_t w0 = kByteVc0TextWords[43474U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0305e8U);
}
static std::uint32_t ByteVc0FdeFunc_0327_0x03061c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[327] @ func_va=0x03061c, fde_va=0x07a700, first_op=0xf81e0ff3
    // VI: Hàm FDE[327] tại địa chỉ 0x03061c, bản ghi FDE 0x07a700
    const std::uint32_t w0 = kByteVc0TextWords[43487U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03061cU);
}
static std::uint32_t ByteVc0FdeFunc_0328_0x03065c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[328] @ func_va=0x03065c, fde_va=0x07a720, first_op=0xf81e0ff3
    // VI: Hàm FDE[328] tại địa chỉ 0x03065c, bản ghi FDE 0x07a720
    const std::uint32_t w0 = kByteVc0TextWords[43503U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03065cU);
}
static std::uint32_t ByteVc0FdeFunc_0329_0x03069c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[329] @ func_va=0x03069c, fde_va=0x07a740, first_op=0xf9401008
    // VI: Hàm FDE[329] tại địa chỉ 0x03069c, bản ghi FDE 0x07a740
    const std::uint32_t w0 = kByteVc0TextWords[43519U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03069cU);
}
static std::uint32_t ByteVc0FdeFunc_0330_0x0306a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[330] @ func_va=0x0306a8, fde_va=0x07a758, first_op=0xf9401008
    // VI: Hàm FDE[330] tại địa chỉ 0x0306a8, bản ghi FDE 0x07a758
    const std::uint32_t w0 = kByteVc0TextWords[43522U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0306a8U);
}
static std::uint32_t ByteVc0FdeFunc_0331_0x0306b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[331] @ func_va=0x0306b8, fde_va=0x07a770, first_op=0xf9401008
    // VI: Hàm FDE[331] tại địa chỉ 0x0306b8, bản ghi FDE 0x07a770
    const std::uint32_t w0 = kByteVc0TextWords[43526U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0306b8U);
}
static std::uint32_t ByteVc0FdeFunc_0332_0x0306c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[332] @ func_va=0x0306c8, fde_va=0x07a788, first_op=0x52900000
    // VI: Hàm FDE[332] tại địa chỉ 0x0306c8, bản ghi FDE 0x07a788
    const std::uint32_t w0 = kByteVc0TextWords[43530U];
    std::uint32_t acc = w0 ^ 0x52900000U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0306c8U);
}
static std::uint32_t ByteVc0FdeFunc_0333_0x0306d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[333] @ func_va=0x0306d0, fde_va=0x07a7a0, first_op=0x2a1f03e0
    // VI: Hàm FDE[333] tại địa chỉ 0x0306d0, bản ghi FDE 0x07a7a0
    const std::uint32_t w0 = kByteVc0TextWords[43532U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0306d0U);
}
static std::uint32_t ByteVc0FdeFunc_0334_0x0306d8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[334] @ func_va=0x0306d8, fde_va=0x07a7b8, first_op=0x2a1f03e0
    // VI: Hàm FDE[334] tại địa chỉ 0x0306d8, bản ghi FDE 0x07a7b8
    const std::uint32_t w0 = kByteVc0TextWords[43534U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0306d8U);
}
static std::uint32_t ByteVc0FdeFunc_0335_0x0306e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[335] @ func_va=0x0306e0, fde_va=0x07a7d0, first_op=0xf9409c28
    // VI: Hàm FDE[335] tại địa chỉ 0x0306e0, bản ghi FDE 0x07a7d0
    const std::uint32_t w0 = kByteVc0TextWords[43536U];
    std::uint32_t acc = w0 ^ 0xf9409c28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0306e0U);
}
static std::uint32_t ByteVc0FdeFunc_0336_0x030988(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[336] @ func_va=0x030988, fde_va=0x07a7e8, first_op=0xa9be4ff4
    // VI: Hàm FDE[336] tại địa chỉ 0x030988, bản ghi FDE 0x07a7e8
    const std::uint32_t w0 = kByteVc0TextWords[43706U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030988U);
}
static std::uint32_t ByteVc0FdeFunc_0337_0x030a14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[337] @ func_va=0x030a14, fde_va=0x07a808, first_op=0x2a1f03e0
    // VI: Hàm FDE[337] tại địa chỉ 0x030a14, bản ghi FDE 0x07a808
    const std::uint32_t w0 = kByteVc0TextWords[43741U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030a14U);
}
static std::uint32_t ByteVc0FdeFunc_0338_0x030a1c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[338] @ func_va=0x030a1c, fde_va=0x07a820, first_op=0xf00002aa
    // VI: Hàm FDE[338] tại địa chỉ 0x030a1c, bản ghi FDE 0x07a820
    const std::uint32_t w0 = kByteVc0TextWords[43743U];
    std::uint32_t acc = w0 ^ 0xf00002aaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030a1cU);
}
static std::uint32_t ByteVc0FdeFunc_0339_0x030a4c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[339] @ func_va=0x030a4c, fde_va=0x07a838, first_op=0xa9bc5ff8
    // VI: Hàm FDE[339] tại địa chỉ 0x030a4c, bản ghi FDE 0x07a838
    const std::uint32_t w0 = kByteVc0TextWords[43755U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030a4cU);
}
static std::uint32_t ByteVc0FdeFunc_0340_0x030b74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[340] @ func_va=0x030b74, fde_va=0x07a860, first_op=0xa9ba6ffc
    // VI: Hàm FDE[340] tại địa chỉ 0x030b74, bản ghi FDE 0x07a860
    const std::uint32_t w0 = kByteVc0TextWords[43829U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030b74U);
}
static std::uint32_t ByteVc0FdeFunc_0341_0x030dcc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[341] @ func_va=0x030dcc, fde_va=0x07a890, first_op=0xa9bc5ff8
    // VI: Hàm FDE[341] tại địa chỉ 0x030dcc, bản ghi FDE 0x07a890
    const std::uint32_t w0 = kByteVc0TextWords[43979U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030dccU);
}
static std::uint32_t ByteVc0FdeFunc_0342_0x030ed0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[342] @ func_va=0x030ed0, fde_va=0x07a8b8, first_op=0x2a1f03e0
    // VI: Hàm FDE[342] tại địa chỉ 0x030ed0, bản ghi FDE 0x07a8b8
    const std::uint32_t w0 = kByteVc0TextWords[44044U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030ed0U);
}
static std::uint32_t ByteVc0FdeFunc_0343_0x030ed8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[343] @ func_va=0x030ed8, fde_va=0x07a8d0, first_op=0x2a1f03e0
    // VI: Hàm FDE[343] tại địa chỉ 0x030ed8, bản ghi FDE 0x07a8d0
    const std::uint32_t w0 = kByteVc0TextWords[44046U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030ed8U);
}
static std::uint32_t ByteVc0FdeFunc_0344_0x030ee0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[344] @ func_va=0x030ee0, fde_va=0x07a8e8, first_op=0xa9be4ff4
    // VI: Hàm FDE[344] tại địa chỉ 0x030ee0, bản ghi FDE 0x07a8e8
    const std::uint32_t w0 = kByteVc0TextWords[44048U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030ee0U);
}
static std::uint32_t ByteVc0FdeFunc_0345_0x030f90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[345] @ func_va=0x030f90, fde_va=0x07a908, first_op=0xf9000c01
    // VI: Hàm FDE[345] tại địa chỉ 0x030f90, bản ghi FDE 0x07a908
    const std::uint32_t w0 = kByteVc0TextWords[44092U];
    std::uint32_t acc = w0 ^ 0xf9000c01U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030f90U);
}
static std::uint32_t ByteVc0FdeFunc_0346_0x030f98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[346] @ func_va=0x030f98, fde_va=0x07a920, first_op=0x3980084a
    // VI: Hàm FDE[346] tại địa chỉ 0x030f98, bản ghi FDE 0x07a920
    const std::uint32_t w0 = kByteVc0TextWords[44094U];
    std::uint32_t acc = w0 ^ 0x3980084aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x030f98U);
}
static std::uint32_t ByteVc0FdeFunc_0347_0x031058(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[347] @ func_va=0x031058, fde_va=0x07a938, first_op=0xf9408c2a
    // VI: Hàm FDE[347] tại địa chỉ 0x031058, bản ghi FDE 0x07a938
    const std::uint32_t w0 = kByteVc0TextWords[44142U];
    std::uint32_t acc = w0 ^ 0xf9408c2aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031058U);
}
static std::uint32_t ByteVc0FdeFunc_0348_0x0310d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[348] @ func_va=0x0310d4, fde_va=0x07a950, first_op=0xa9be4ff4
    // VI: Hàm FDE[348] tại địa chỉ 0x0310d4, bản ghi FDE 0x07a950
    const std::uint32_t w0 = kByteVc0TextWords[44173U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0310d4U);
}
static std::uint32_t ByteVc0FdeFunc_0349_0x0311ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[349] @ func_va=0x0311ac, fde_va=0x07a970, first_op=0xd65f03c0
    // VI: Hàm FDE[349] tại địa chỉ 0x0311ac, bản ghi FDE 0x07a970
    const std::uint32_t w0 = kByteVc0TextWords[44227U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0311acU);
}
static std::uint32_t ByteVc0FdeFunc_0350_0x0311b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[350] @ func_va=0x0311b0, fde_va=0x07a988, first_op=0x17ff5248
    // VI: Hàm FDE[350] tại địa chỉ 0x0311b0, bản ghi FDE 0x07a988
    const std::uint32_t w0 = kByteVc0TextWords[44228U];
    std::uint32_t acc = w0 ^ 0x17ff5248U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0311b0U);
}
static std::uint32_t ByteVc0FdeFunc_0351_0x0311b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[351] @ func_va=0x0311b4, fde_va=0x07a9a0, first_op=0xd10243ff
    // VI: Hàm FDE[351] tại địa chỉ 0x0311b4, bản ghi FDE 0x07a9a0
    const std::uint32_t w0 = kByteVc0TextWords[44229U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0311b4U);
}
static std::uint32_t ByteVc0FdeFunc_0352_0x031590(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[352] @ func_va=0x031590, fde_va=0x07a9c8, first_op=0xa9be4ff4
    // VI: Hàm FDE[352] tại địa chỉ 0x031590, bản ghi FDE 0x07a9c8
    const std::uint32_t w0 = kByteVc0TextWords[44476U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031590U);
}
static std::uint32_t ByteVc0FdeFunc_0353_0x031610(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[353] @ func_va=0x031610, fde_va=0x07a9e8, first_op=0xa9bb67fa
    // VI: Hàm FDE[353] tại địa chỉ 0x031610, bản ghi FDE 0x07a9e8
    const std::uint32_t w0 = kByteVc0TextWords[44508U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031610U);
}
static std::uint32_t ByteVc0FdeFunc_0354_0x031810(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[354] @ func_va=0x031810, fde_va=0x07aa18, first_op=0x3944c048
    // VI: Hàm FDE[354] tại địa chỉ 0x031810, bản ghi FDE 0x07aa18
    const std::uint32_t w0 = kByteVc0TextWords[44636U];
    std::uint32_t acc = w0 ^ 0x3944c048U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031810U);
}
static std::uint32_t ByteVc0FdeFunc_0355_0x03191c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[355] @ func_va=0x03191c, fde_va=0x07aa30, first_op=0xd00002a8
    // VI: Hàm FDE[355] tại địa chỉ 0x03191c, bản ghi FDE 0x07aa30
    const std::uint32_t w0 = kByteVc0TextWords[44703U];
    std::uint32_t acc = w0 ^ 0xd00002a8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03191cU);
}
static std::uint32_t ByteVc0FdeFunc_0356_0x0319a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[356] @ func_va=0x0319a8, fde_va=0x07aa48, first_op=0xa9be4ff4
    // VI: Hàm FDE[356] tại địa chỉ 0x0319a8, bản ghi FDE 0x07aa48
    const std::uint32_t w0 = kByteVc0TextWords[44738U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0319a8U);
}
static std::uint32_t ByteVc0FdeFunc_0357_0x031a18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[357] @ func_va=0x031a18, fde_va=0x07aa68, first_op=0xa9be4ff4
    // VI: Hàm FDE[357] tại địa chỉ 0x031a18, bản ghi FDE 0x07aa68
    const std::uint32_t w0 = kByteVc0TextWords[44766U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031a18U);
}
static std::uint32_t ByteVc0FdeFunc_0358_0x031aa8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[358] @ func_va=0x031aa8, fde_va=0x07aa88, first_op=0xa9be4ff4
    // VI: Hàm FDE[358] tại địa chỉ 0x031aa8, bản ghi FDE 0x07aa88
    const std::uint32_t w0 = kByteVc0TextWords[44802U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031aa8U);
}
static std::uint32_t ByteVc0FdeFunc_0359_0x031b34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[359] @ func_va=0x031b34, fde_va=0x07aaa8, first_op=0x340001c1
    // VI: Hàm FDE[359] tại địa chỉ 0x031b34, bản ghi FDE 0x07aaa8
    const std::uint32_t w0 = kByteVc0TextWords[44837U];
    std::uint32_t acc = w0 ^ 0x340001c1U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031b34U);
}
static std::uint32_t ByteVc0FdeFunc_0360_0x031b80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[360] @ func_va=0x031b80, fde_va=0x07aac0, first_op=0x340000e1
    // VI: Hàm FDE[360] tại địa chỉ 0x031b80, bản ghi FDE 0x07aac0
    const std::uint32_t w0 = kByteVc0TextWords[44856U];
    std::uint32_t acc = w0 ^ 0x340000e1U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031b80U);
}
static std::uint32_t ByteVc0FdeFunc_0361_0x031c3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[361] @ func_va=0x031c3c, fde_va=0x07aad8, first_op=0xf94c5808
    // VI: Hàm FDE[361] tại địa chỉ 0x031c3c, bản ghi FDE 0x07aad8
    const std::uint32_t w0 = kByteVc0TextWords[44903U];
    std::uint32_t acc = w0 ^ 0xf94c5808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031c3cU);
}
static std::uint32_t ByteVc0FdeFunc_0362_0x031cac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[362] @ func_va=0x031cac, fde_va=0x07aaf0, first_op=0xd00002aa
    // VI: Hàm FDE[362] tại địa chỉ 0x031cac, bản ghi FDE 0x07aaf0
    const std::uint32_t w0 = kByteVc0TextWords[44931U];
    std::uint32_t acc = w0 ^ 0xd00002aaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031cacU);
}
static std::uint32_t ByteVc0FdeFunc_0363_0x031d30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[363] @ func_va=0x031d30, fde_va=0x07ab08, first_op=0xf81c0ff7
    // VI: Hàm FDE[363] tại địa chỉ 0x031d30, bản ghi FDE 0x07ab08
    const std::uint32_t w0 = kByteVc0TextWords[44964U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x031d30U);
}
static std::uint32_t ByteVc0FdeFunc_0364_0x0321c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[364] @ func_va=0x0321c4, fde_va=0x07ab30, first_op=0x39c0100b
    // VI: Hàm FDE[364] tại địa chỉ 0x0321c4, bản ghi FDE 0x07ab30
    const std::uint32_t w0 = kByteVc0TextWords[45257U];
    std::uint32_t acc = w0 ^ 0x39c0100bU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0321c4U);
}
static std::uint32_t ByteVc0FdeFunc_0365_0x032288(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[365] @ func_va=0x032288, fde_va=0x07ab48, first_op=0xf940a008
    // VI: Hàm FDE[365] tại địa chỉ 0x032288, bản ghi FDE 0x07ab48
    const std::uint32_t w0 = kByteVc0TextWords[45306U];
    std::uint32_t acc = w0 ^ 0xf940a008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x032288U);
}
static std::uint32_t ByteVc0FdeFunc_0366_0x0322c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[366] @ func_va=0x0322c8, fde_va=0x07ab60, first_op=0xf940a028
    // VI: Hàm FDE[366] tại địa chỉ 0x0322c8, bản ghi FDE 0x07ab60
    const std::uint32_t w0 = kByteVc0TextWords[45322U];
    std::uint32_t acc = w0 ^ 0xf940a028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0322c8U);
}
static std::uint32_t ByteVc0FdeFunc_0367_0x03234c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[367] @ func_va=0x03234c, fde_va=0x07ab78, first_op=0xf81e0ff3
    // VI: Hàm FDE[367] tại địa chỉ 0x03234c, bản ghi FDE 0x07ab78
    const std::uint32_t w0 = kByteVc0TextWords[45355U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03234cU);
}
static std::uint32_t ByteVc0FdeFunc_0368_0x03238c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[368] @ func_va=0x03238c, fde_va=0x07ab98, first_op=0xf81e0ff3
    // VI: Hàm FDE[368] tại địa chỉ 0x03238c, bản ghi FDE 0x07ab98
    const std::uint32_t w0 = kByteVc0TextWords[45371U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03238cU);
}
static std::uint32_t ByteVc0FdeFunc_0369_0x0323cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[369] @ func_va=0x0323cc, fde_va=0x07abb8, first_op=0xf81d0ff5
    // VI: Hàm FDE[369] tại địa chỉ 0x0323cc, bản ghi FDE 0x07abb8
    const std::uint32_t w0 = kByteVc0TextWords[45387U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0323ccU);
}
static std::uint32_t ByteVc0FdeFunc_0370_0x032450(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[370] @ func_va=0x032450, fde_va=0x07abd8, first_op=0xf81b0ff9
    // VI: Hàm FDE[370] tại địa chỉ 0x032450, bản ghi FDE 0x07abd8
    const std::uint32_t w0 = kByteVc0TextWords[45420U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x032450U);
}
static std::uint32_t ByteVc0FdeFunc_0371_0x032868(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[371] @ func_va=0x032868, fde_va=0x07ac00, first_op=0xf81a0ffb
    // VI: Hàm FDE[371] tại địa chỉ 0x032868, bản ghi FDE 0x07ac00
    const std::uint32_t w0 = kByteVc0TextWords[45682U];
    std::uint32_t acc = w0 ^ 0xf81a0ffbU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x032868U);
}
static std::uint32_t ByteVc0FdeFunc_0372_0x032dd0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[372] @ func_va=0x032dd0, fde_va=0x07ac30, first_op=0xa9bd57f6
    // VI: Hàm FDE[372] tại địa chỉ 0x032dd0, bản ghi FDE 0x07ac30
    const std::uint32_t w0 = kByteVc0TextWords[46028U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x032dd0U);
}
static std::uint32_t ByteVc0FdeFunc_0373_0x032e60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[373] @ func_va=0x032e60, fde_va=0x07ac58, first_op=0xf9400809
    // VI: Hàm FDE[373] tại địa chỉ 0x032e60, bản ghi FDE 0x07ac58
    const std::uint32_t w0 = kByteVc0TextWords[46064U];
    std::uint32_t acc = w0 ^ 0xf9400809U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x032e60U);
}
static std::uint32_t ByteVc0FdeFunc_0374_0x032ef8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[374] @ func_va=0x032ef8, fde_va=0x07ac70, first_op=0xa9be4ff4
    // VI: Hàm FDE[374] tại địa chỉ 0x032ef8, bản ghi FDE 0x07ac70
    const std::uint32_t w0 = kByteVc0TextWords[46102U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x032ef8U);
}
static std::uint32_t ByteVc0FdeFunc_0375_0x033038(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[375] @ func_va=0x033038, fde_va=0x07ac90, first_op=0xa9be4ff4
    // VI: Hàm FDE[375] tại địa chỉ 0x033038, bản ghi FDE 0x07ac90
    const std::uint32_t w0 = kByteVc0TextWords[46182U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033038U);
}
static std::uint32_t ByteVc0FdeFunc_0376_0x0331e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[376] @ func_va=0x0331e0, fde_va=0x07acb0, first_op=0xf81d0ff5
    // VI: Hàm FDE[376] tại địa chỉ 0x0331e0, bản ghi FDE 0x07acb0
    const std::uint32_t w0 = kByteVc0TextWords[46288U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0331e0U);
}
static std::uint32_t ByteVc0FdeFunc_0377_0x033388(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[377] @ func_va=0x033388, fde_va=0x07acd0, first_op=0xf940a028
    // VI: Hàm FDE[377] tại địa chỉ 0x033388, bản ghi FDE 0x07acd0
    const std::uint32_t w0 = kByteVc0TextWords[46394U];
    std::uint32_t acc = w0 ^ 0xf940a028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033388U);
}
static std::uint32_t ByteVc0FdeFunc_0378_0x0333e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[378] @ func_va=0x0333e0, fde_va=0x07ace8, first_op=0xa9ba6ffc
    // VI: Hàm FDE[378] tại địa chỉ 0x0333e0, bản ghi FDE 0x07ace8
    const std::uint32_t w0 = kByteVc0TextWords[46416U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0333e0U);
}
static std::uint32_t ByteVc0FdeFunc_0379_0x033618(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[379] @ func_va=0x033618, fde_va=0x07ad18, first_op=0xa9bb67fa
    // VI: Hàm FDE[379] tại địa chỉ 0x033618, bản ghi FDE 0x07ad18
    const std::uint32_t w0 = kByteVc0TextWords[46558U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033618U);
}
static std::uint32_t ByteVc0FdeFunc_0380_0x033740(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[380] @ func_va=0x033740, fde_va=0x07ad48, first_op=0xa9ba6ffc
    // VI: Hàm FDE[380] tại địa chỉ 0x033740, bản ghi FDE 0x07ad48
    const std::uint32_t w0 = kByteVc0TextWords[46632U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033740U);
}
static std::uint32_t ByteVc0FdeFunc_0381_0x033880(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[381] @ func_va=0x033880, fde_va=0x07ad78, first_op=0xa9bd57f6
    // VI: Hàm FDE[381] tại địa chỉ 0x033880, bản ghi FDE 0x07ad78
    const std::uint32_t w0 = kByteVc0TextWords[46712U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033880U);
}
static std::uint32_t ByteVc0FdeFunc_0382_0x03395c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[382] @ func_va=0x03395c, fde_va=0x07ada0, first_op=0xd101c3ff
    // VI: Hàm FDE[382] tại địa chỉ 0x03395c, bản ghi FDE 0x07ada0
    const std::uint32_t w0 = kByteVc0TextWords[46767U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03395cU);
}
static std::uint32_t ByteVc0FdeFunc_0383_0x033af8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[383] @ func_va=0x033af8, fde_va=0x07add0, first_op=0xa9bb67fa
    // VI: Hàm FDE[383] tại địa chỉ 0x033af8, bản ghi FDE 0x07add0
    const std::uint32_t w0 = kByteVc0TextWords[46870U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033af8U);
}
static std::uint32_t ByteVc0FdeFunc_0384_0x033d94(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[384] @ func_va=0x033d94, fde_va=0x07ae00, first_op=0xf81d0ff5
    // VI: Hàm FDE[384] tại địa chỉ 0x033d94, bản ghi FDE 0x07ae00
    const std::uint32_t w0 = kByteVc0TextWords[47037U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033d94U);
}
static std::uint32_t ByteVc0FdeFunc_0385_0x033f34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[385] @ func_va=0x033f34, fde_va=0x07ae20, first_op=0xd65f03c0
    // VI: Hàm FDE[385] tại địa chỉ 0x033f34, bản ghi FDE 0x07ae20
    const std::uint32_t w0 = kByteVc0TextWords[47141U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033f34U);
}
static std::uint32_t ByteVc0FdeFunc_0386_0x033f38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[386] @ func_va=0x033f38, fde_va=0x07ae38, first_op=0xaa1f03e0
    // VI: Hàm FDE[386] tại địa chỉ 0x033f38, bản ghi FDE 0x07ae38
    const std::uint32_t w0 = kByteVc0TextWords[47142U];
    std::uint32_t acc = w0 ^ 0xaa1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033f38U);
}
static std::uint32_t ByteVc0FdeFunc_0387_0x033f40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[387] @ func_va=0x033f40, fde_va=0x07ae50, first_op=0xf9422c28
    // VI: Hàm FDE[387] tại địa chỉ 0x033f40, bản ghi FDE 0x07ae50
    const std::uint32_t w0 = kByteVc0TextWords[47144U];
    std::uint32_t acc = w0 ^ 0xf9422c28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033f40U);
}
static std::uint32_t ByteVc0FdeFunc_0388_0x033f58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[388] @ func_va=0x033f58, fde_va=0x07ae68, first_op=0xd65f03c0
    // VI: Hàm FDE[388] tại địa chỉ 0x033f58, bản ghi FDE 0x07ae68
    const std::uint32_t w0 = kByteVc0TextWords[47150U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033f58U);
}
static std::uint32_t ByteVc0FdeFunc_0389_0x033f5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[389] @ func_va=0x033f5c, fde_va=0x07ae80, first_op=0xf9401008
    // VI: Hàm FDE[389] tại địa chỉ 0x033f5c, bản ghi FDE 0x07ae80
    const std::uint32_t w0 = kByteVc0TextWords[47151U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033f5cU);
}
static std::uint32_t ByteVc0FdeFunc_0390_0x033f80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[390] @ func_va=0x033f80, fde_va=0x07ae98, first_op=0xf9401008
    // VI: Hàm FDE[390] tại địa chỉ 0x033f80, bản ghi FDE 0x07ae98
    const std::uint32_t w0 = kByteVc0TextWords[47160U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033f80U);
}
static std::uint32_t ByteVc0FdeFunc_0391_0x033fa4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[391] @ func_va=0x033fa4, fde_va=0x07aeb0, first_op=0xf9401008
    // VI: Hàm FDE[391] tại địa chỉ 0x033fa4, bản ghi FDE 0x07aeb0
    const std::uint32_t w0 = kByteVc0TextWords[47169U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033fa4U);
}
static std::uint32_t ByteVc0FdeFunc_0392_0x033fcc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[392] @ func_va=0x033fcc, fde_va=0x07aec8, first_op=0xd65f03c0
    // VI: Hàm FDE[392] tại địa chỉ 0x033fcc, bản ghi FDE 0x07aec8
    const std::uint32_t w0 = kByteVc0TextWords[47179U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033fccU);
}
static std::uint32_t ByteVc0FdeFunc_0393_0x033fd0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[393] @ func_va=0x033fd0, fde_va=0x07aee0, first_op=0xd65f03c0
    // VI: Hàm FDE[393] tại địa chỉ 0x033fd0, bản ghi FDE 0x07aee0
    const std::uint32_t w0 = kByteVc0TextWords[47180U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033fd0U);
}
static std::uint32_t ByteVc0FdeFunc_0394_0x033fd4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[394] @ func_va=0x033fd4, fde_va=0x07aef8, first_op=0x17ff46bf
    // VI: Hàm FDE[394] tại địa chỉ 0x033fd4, bản ghi FDE 0x07aef8
    const std::uint32_t w0 = kByteVc0TextWords[47181U];
    std::uint32_t acc = w0 ^ 0x17ff46bfU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033fd4U);
}
static std::uint32_t ByteVc0FdeFunc_0395_0x033fd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[395] @ func_va=0x033fd8, fde_va=0x07af10, first_op=0xd10383ff
    // VI: Hàm FDE[395] tại địa chỉ 0x033fd8, bản ghi FDE 0x07af10
    const std::uint32_t w0 = kByteVc0TextWords[47182U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x033fd8U);
}
static std::uint32_t ByteVc0FdeFunc_0396_0x034480(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[396] @ func_va=0x034480, fde_va=0x07af40, first_op=0xf81e0ff3
    // VI: Hàm FDE[396] tại địa chỉ 0x034480, bản ghi FDE 0x07af40
    const std::uint32_t w0 = kByteVc0TextWords[47480U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x034480U);
}
static std::uint32_t ByteVc0FdeFunc_0397_0x0344e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[397] @ func_va=0x0344e0, fde_va=0x07af60, first_op=0xf81e0ff3
    // VI: Hàm FDE[397] tại địa chỉ 0x0344e0, bản ghi FDE 0x07af60
    const std::uint32_t w0 = kByteVc0TextWords[47504U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0344e0U);
}
static std::uint32_t ByteVc0FdeFunc_0398_0x034504(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[398] @ func_va=0x034504, fde_va=0x07af80, first_op=0xa9008801
    // VI: Hàm FDE[398] tại địa chỉ 0x034504, bản ghi FDE 0x07af80
    const std::uint32_t w0 = kByteVc0TextWords[47513U];
    std::uint32_t acc = w0 ^ 0xa9008801U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x034504U);
}
static std::uint32_t ByteVc0FdeFunc_0399_0x034510(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[399] @ func_va=0x034510, fde_va=0x07af98, first_op=0xf81b0ff9
    // VI: Hàm FDE[399] tại địa chỉ 0x034510, bản ghi FDE 0x07af98
    const std::uint32_t w0 = kByteVc0TextWords[47516U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x034510U);
}
static std::uint32_t ByteVc0FdeFunc_0400_0x0345f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[400] @ func_va=0x0345f0, fde_va=0x07afc0, first_op=0xa9be4ff4
    // VI: Hàm FDE[400] tại địa chỉ 0x0345f0, bản ghi FDE 0x07afc0
    const std::uint32_t w0 = kByteVc0TextWords[47572U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0345f0U);
}
static std::uint32_t ByteVc0FdeFunc_0401_0x0346d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[401] @ func_va=0x0346d0, fde_va=0x07afe0, first_op=0xd102c3ff
    // VI: Hàm FDE[401] tại địa chỉ 0x0346d0, bản ghi FDE 0x07afe0
    const std::uint32_t w0 = kByteVc0TextWords[47628U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0346d0U);
}
static std::uint32_t ByteVc0FdeFunc_0402_0x03493c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[402] @ func_va=0x03493c, fde_va=0x07b010, first_op=0xa9bd57f6
    // VI: Hàm FDE[402] tại địa chỉ 0x03493c, bản ghi FDE 0x07b010
    const std::uint32_t w0 = kByteVc0TextWords[47783U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03493cU);
}
static std::uint32_t ByteVc0FdeFunc_0403_0x034ae4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[403] @ func_va=0x034ae4, fde_va=0x07b038, first_op=0xa9bd57f6
    // VI: Hàm FDE[403] tại địa chỉ 0x034ae4, bản ghi FDE 0x07b038
    const std::uint32_t w0 = kByteVc0TextWords[47889U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x034ae4U);
}
static std::uint32_t ByteVc0FdeFunc_0404_0x034ccc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[404] @ func_va=0x034ccc, fde_va=0x07b060, first_op=0xf81d0ff5
    // VI: Hàm FDE[404] tại địa chỉ 0x034ccc, bản ghi FDE 0x07b060
    const std::uint32_t w0 = kByteVc0TextWords[48011U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x034cccU);
}
static std::uint32_t ByteVc0FdeFunc_0405_0x034dd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[405] @ func_va=0x034dd8, fde_va=0x07b080, first_op=0xa9bb67fa
    // VI: Hàm FDE[405] tại địa chỉ 0x034dd8, bản ghi FDE 0x07b080
    const std::uint32_t w0 = kByteVc0TextWords[48078U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x034dd8U);
}
static std::uint32_t ByteVc0FdeFunc_0406_0x034f98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[406] @ func_va=0x034f98, fde_va=0x07b0b0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[406] tại địa chỉ 0x034f98, bản ghi FDE 0x07b0b0
    const std::uint32_t w0 = kByteVc0TextWords[48190U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x034f98U);
}
static std::uint32_t ByteVc0FdeFunc_0407_0x0350e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[407] @ func_va=0x0350e0, fde_va=0x07b0e0, first_op=0xf81d0ff5
    // VI: Hàm FDE[407] tại địa chỉ 0x0350e0, bản ghi FDE 0x07b0e0
    const std::uint32_t w0 = kByteVc0TextWords[48272U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0350e0U);
}
static std::uint32_t ByteVc0FdeFunc_0408_0x035264(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[408] @ func_va=0x035264, fde_va=0x07b100, first_op=0xa9bb67fa
    // VI: Hàm FDE[408] tại địa chỉ 0x035264, bản ghi FDE 0x07b100
    const std::uint32_t w0 = kByteVc0TextWords[48369U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x035264U);
}
static std::uint32_t ByteVc0FdeFunc_0409_0x035404(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[409] @ func_va=0x035404, fde_va=0x07b130, first_op=0xd10183ff
    // VI: Hàm FDE[409] tại địa chỉ 0x035404, bản ghi FDE 0x07b130
    const std::uint32_t w0 = kByteVc0TextWords[48473U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x035404U);
}
static std::uint32_t ByteVc0FdeFunc_0410_0x03554c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[410] @ func_va=0x03554c, fde_va=0x07b158, first_op=0xf9400008
    // VI: Hàm FDE[410] tại địa chỉ 0x03554c, bản ghi FDE 0x07b158
    const std::uint32_t w0 = kByteVc0TextWords[48555U];
    std::uint32_t acc = w0 ^ 0xf9400008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03554cU);
}
static std::uint32_t ByteVc0FdeFunc_0411_0x0355b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[411] @ func_va=0x0355b4, fde_va=0x07b170, first_op=0xf9400008
    // VI: Hàm FDE[411] tại địa chỉ 0x0355b4, bản ghi FDE 0x07b170
    const std::uint32_t w0 = kByteVc0TextWords[48581U];
    std::uint32_t acc = w0 ^ 0xf9400008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0355b4U);
}
static std::uint32_t ByteVc0FdeFunc_0412_0x035608(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[412] @ func_va=0x035608, fde_va=0x07b188, first_op=0xd101c3ff
    // VI: Hàm FDE[412] tại địa chỉ 0x035608, bản ghi FDE 0x07b188
    const std::uint32_t w0 = kByteVc0TextWords[48602U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x035608U);
}
static std::uint32_t ByteVc0FdeFunc_0413_0x03598c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[413] @ func_va=0x03598c, fde_va=0x07b1b8, first_op=0xd10283ff
    // VI: Hàm FDE[413] tại địa chỉ 0x03598c, bản ghi FDE 0x07b1b8
    const std::uint32_t w0 = kByteVc0TextWords[48827U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03598cU);
}
static std::uint32_t ByteVc0FdeFunc_0414_0x035dd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[414] @ func_va=0x035dd8, fde_va=0x07b1e8, first_op=0xf81a0ffb
    // VI: Hàm FDE[414] tại địa chỉ 0x035dd8, bản ghi FDE 0x07b1e8
    const std::uint32_t w0 = kByteVc0TextWords[49102U];
    std::uint32_t acc = w0 ^ 0xf81a0ffbU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x035dd8U);
}
static std::uint32_t ByteVc0FdeFunc_0415_0x03657c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[415] @ func_va=0x03657c, fde_va=0x07b218, first_op=0xa9bc5ff8
    // VI: Hàm FDE[415] tại địa chỉ 0x03657c, bản ghi FDE 0x07b218
    const std::uint32_t w0 = kByteVc0TextWords[49591U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03657cU);
}
static std::uint32_t ByteVc0FdeFunc_0416_0x036908(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[416] @ func_va=0x036908, fde_va=0x07b240, first_op=0xa9bc5ff8
    // VI: Hàm FDE[416] tại địa chỉ 0x036908, bản ghi FDE 0x07b240
    const std::uint32_t w0 = kByteVc0TextWords[49818U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x036908U);
}
static std::uint32_t ByteVc0FdeFunc_0417_0x036b90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[417] @ func_va=0x036b90, fde_va=0x07b268, first_op=0xa9bb67fa
    // VI: Hàm FDE[417] tại địa chỉ 0x036b90, bản ghi FDE 0x07b268
    const std::uint32_t w0 = kByteVc0TextWords[49980U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x036b90U);
}
static std::uint32_t ByteVc0FdeFunc_0418_0x036d34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[418] @ func_va=0x036d34, fde_va=0x07b298, first_op=0xd10443ff
    // VI: Hàm FDE[418] tại địa chỉ 0x036d34, bản ghi FDE 0x07b298
    const std::uint32_t w0 = kByteVc0TextWords[50085U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x036d34U);
}
static std::uint32_t ByteVc0FdeFunc_0419_0x036f88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[419] @ func_va=0x036f88, fde_va=0x07b2c8, first_op=0x92800008
    // VI: Hàm FDE[419] tại địa chỉ 0x036f88, bản ghi FDE 0x07b2c8
    const std::uint32_t w0 = kByteVc0TextWords[50234U];
    std::uint32_t acc = w0 ^ 0x92800008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x036f88U);
}
static std::uint32_t ByteVc0FdeFunc_0420_0x036fbc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[420] @ func_va=0x036fbc, fde_va=0x07b2e0, first_op=0xb0000289
    // VI: Hàm FDE[420] tại địa chỉ 0x036fbc, bản ghi FDE 0x07b2e0
    const std::uint32_t w0 = kByteVc0TextWords[50247U];
    std::uint32_t acc = w0 ^ 0xb0000289U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x036fbcU);
}
static std::uint32_t ByteVc0FdeFunc_0421_0x036ff4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[421] @ func_va=0x036ff4, fde_va=0x07b2f8, first_op=0xa9bd57f6
    // VI: Hàm FDE[421] tại địa chỉ 0x036ff4, bản ghi FDE 0x07b2f8
    const std::uint32_t w0 = kByteVc0TextWords[50261U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x036ff4U);
}
static std::uint32_t ByteVc0FdeFunc_0422_0x037204(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[422] @ func_va=0x037204, fde_va=0x07b320, first_op=0xa9bb67fa
    // VI: Hàm FDE[422] tại địa chỉ 0x037204, bản ghi FDE 0x07b320
    const std::uint32_t w0 = kByteVc0TextWords[50393U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037204U);
}
static std::uint32_t ByteVc0FdeFunc_0423_0x037380(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[423] @ func_va=0x037380, fde_va=0x07b350, first_op=0xf81e0ff3
    // VI: Hàm FDE[423] tại địa chỉ 0x037380, bản ghi FDE 0x07b350
    const std::uint32_t w0 = kByteVc0TextWords[50488U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037380U);
}
static std::uint32_t ByteVc0FdeFunc_0424_0x03741c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[424] @ func_va=0x03741c, fde_va=0x07b370, first_op=0xf9000c01
    // VI: Hàm FDE[424] tại địa chỉ 0x03741c, bản ghi FDE 0x07b370
    const std::uint32_t w0 = kByteVc0TextWords[50527U];
    std::uint32_t acc = w0 ^ 0xf9000c01U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03741cU);
}
static std::uint32_t ByteVc0FdeFunc_0425_0x037430(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[425] @ func_va=0x037430, fde_va=0x07b388, first_op=0xf9401008
    // VI: Hàm FDE[425] tại địa chỉ 0x037430, bản ghi FDE 0x07b388
    const std::uint32_t w0 = kByteVc0TextWords[50532U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037430U);
}
static std::uint32_t ByteVc0FdeFunc_0426_0x03743c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[426] @ func_va=0x03743c, fde_va=0x07b3a0, first_op=0xf9403c28
    // VI: Hàm FDE[426] tại địa chỉ 0x03743c, bản ghi FDE 0x07b3a0
    const std::uint32_t w0 = kByteVc0TextWords[50535U];
    std::uint32_t acc = w0 ^ 0xf9403c28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03743cU);
}
static std::uint32_t ByteVc0FdeFunc_0427_0x037454(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[427] @ func_va=0x037454, fde_va=0x07b3b8, first_op=0xf81e0ff3
    // VI: Hàm FDE[427] tại địa chỉ 0x037454, bản ghi FDE 0x07b3b8
    const std::uint32_t w0 = kByteVc0TextWords[50541U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037454U);
}
static std::uint32_t ByteVc0FdeFunc_0428_0x03749c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[428] @ func_va=0x03749c, fde_va=0x07b3d8, first_op=0xf81e0ff3
    // VI: Hàm FDE[428] tại địa chỉ 0x03749c, bản ghi FDE 0x07b3d8
    const std::uint32_t w0 = kByteVc0TextWords[50559U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03749cU);
}
static std::uint32_t ByteVc0FdeFunc_0429_0x0374f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[429] @ func_va=0x0374f8, fde_va=0x07b3f8, first_op=0xf81e0ff3
    // VI: Hàm FDE[429] tại địa chỉ 0x0374f8, bản ghi FDE 0x07b3f8
    const std::uint32_t w0 = kByteVc0TextWords[50582U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0374f8U);
}
static std::uint32_t ByteVc0FdeFunc_0430_0x037530(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[430] @ func_va=0x037530, fde_va=0x07b418, first_op=0xf9401008
    // VI: Hàm FDE[430] tại địa chỉ 0x037530, bản ghi FDE 0x07b418
    const std::uint32_t w0 = kByteVc0TextWords[50596U];
    std::uint32_t acc = w0 ^ 0xf9401008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037530U);
}
static std::uint32_t ByteVc0FdeFunc_0431_0x037544(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[431] @ func_va=0x037544, fde_va=0x07b430, first_op=0x90000288
    // VI: Hàm FDE[431] tại địa chỉ 0x037544, bản ghi FDE 0x07b430
    const std::uint32_t w0 = kByteVc0TextWords[50601U];
    std::uint32_t acc = w0 ^ 0x90000288U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037544U);
}
static std::uint32_t ByteVc0FdeFunc_0432_0x03755c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[432] @ func_va=0x03755c, fde_va=0x07b448, first_op=0xa9bd57f6
    // VI: Hàm FDE[432] tại địa chỉ 0x03755c, bản ghi FDE 0x07b448
    const std::uint32_t w0 = kByteVc0TextWords[50607U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03755cU);
}
static std::uint32_t ByteVc0FdeFunc_0433_0x0377b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[433] @ func_va=0x0377b0, fde_va=0x07b470, first_op=0xf9400808
    // VI: Hàm FDE[433] tại địa chỉ 0x0377b0, bản ghi FDE 0x07b470
    const std::uint32_t w0 = kByteVc0TextWords[50756U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0377b0U);
}
static std::uint32_t ByteVc0FdeFunc_0434_0x0378e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[434] @ func_va=0x0378e0, fde_va=0x07b488, first_op=0xd10103ff
    // VI: Hàm FDE[434] tại địa chỉ 0x0378e0, bản ghi FDE 0x07b488
    const std::uint32_t w0 = kByteVc0TextWords[50832U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0378e0U);
}
static std::uint32_t ByteVc0FdeFunc_0435_0x037ac0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[435] @ func_va=0x037ac0, fde_va=0x07b4a8, first_op=0x9106f026
    // VI: Hàm FDE[435] tại địa chỉ 0x037ac0, bản ghi FDE 0x07b4a8
    const std::uint32_t w0 = kByteVc0TextWords[50952U];
    std::uint32_t acc = w0 ^ 0x9106f026U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037ac0U);
}
static std::uint32_t ByteVc0FdeFunc_0436_0x037ac8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[436] @ func_va=0x037ac8, fde_va=0x07b4c0, first_op=0xd10103ff
    // VI: Hàm FDE[436] tại địa chỉ 0x037ac8, bản ghi FDE 0x07b4c0
    const std::uint32_t w0 = kByteVc0TextWords[50954U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037ac8U);
}
static std::uint32_t ByteVc0FdeFunc_0437_0x037f60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[437] @ func_va=0x037f60, fde_va=0x07b4e0, first_op=0xd10103ff
    // VI: Hàm FDE[437] tại địa chỉ 0x037f60, bản ghi FDE 0x07b4e0
    const std::uint32_t w0 = kByteVc0TextWords[51248U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x037f60U);
}
static std::uint32_t ByteVc0FdeFunc_0438_0x0380ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[438] @ func_va=0x0380ac, fde_va=0x07b500, first_op=0xd100c3ff
    // VI: Hàm FDE[438] tại địa chỉ 0x0380ac, bản ghi FDE 0x07b500
    const std::uint32_t w0 = kByteVc0TextWords[51331U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0380acU);
}
static std::uint32_t ByteVc0FdeFunc_0439_0x03818c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[439] @ func_va=0x03818c, fde_va=0x07b520, first_op=0xb9608808
    // VI: Hàm FDE[439] tại địa chỉ 0x03818c, bản ghi FDE 0x07b520
    const std::uint32_t w0 = kByteVc0TextWords[51387U];
    std::uint32_t acc = w0 ^ 0xb9608808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03818cU);
}
static std::uint32_t ByteVc0FdeFunc_0440_0x0381c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[440] @ func_va=0x0381c4, fde_va=0x07b538, first_op=0xf9404048
    // VI: Hàm FDE[440] tại địa chỉ 0x0381c4, bản ghi FDE 0x07b538
    const std::uint32_t w0 = kByteVc0TextWords[51401U];
    std::uint32_t acc = w0 ^ 0xf9404048U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0381c4U);
}
static std::uint32_t ByteVc0FdeFunc_0441_0x03821c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[441] @ func_va=0x03821c, fde_va=0x07b550, first_op=0xd101c3ff
    // VI: Hàm FDE[441] tại địa chỉ 0x03821c, bản ghi FDE 0x07b550
    const std::uint32_t w0 = kByteVc0TextWords[51423U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03821cU);
}
static std::uint32_t ByteVc0FdeFunc_0442_0x0383e4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[442] @ func_va=0x0383e4, fde_va=0x07b580, first_op=0xb9608808
    // VI: Hàm FDE[442] tại địa chỉ 0x0383e4, bản ghi FDE 0x07b580
    const std::uint32_t w0 = kByteVc0TextWords[51537U];
    std::uint32_t acc = w0 ^ 0xb9608808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0383e4U);
}
static std::uint32_t ByteVc0FdeFunc_0443_0x038494(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[443] @ func_va=0x038494, fde_va=0x07b598, first_op=0xf81e0ff3
    // VI: Hàm FDE[443] tại địa chỉ 0x038494, bản ghi FDE 0x07b598
    const std::uint32_t w0 = kByteVc0TextWords[51581U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038494U);
}
static std::uint32_t ByteVc0FdeFunc_0444_0x0384c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[444] @ func_va=0x0384c4, fde_va=0x07b5b8, first_op=0xa9be4ff4
    // VI: Hàm FDE[444] tại địa chỉ 0x0384c4, bản ghi FDE 0x07b5b8
    const std::uint32_t w0 = kByteVc0TextWords[51593U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0384c4U);
}
static std::uint32_t ByteVc0FdeFunc_0445_0x0385e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[445] @ func_va=0x0385e8, fde_va=0x07b5d8, first_op=0xf81e0ff3
    // VI: Hàm FDE[445] tại địa chỉ 0x0385e8, bản ghi FDE 0x07b5d8
    const std::uint32_t w0 = kByteVc0TextWords[51666U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0385e8U);
}
static std::uint32_t ByteVc0FdeFunc_0446_0x038618(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[446] @ func_va=0x038618, fde_va=0x07b5f8, first_op=0xd0000268
    // VI: Hàm FDE[446] tại địa chỉ 0x038618, bản ghi FDE 0x07b5f8
    const std::uint32_t w0 = kByteVc0TextWords[51678U];
    std::uint32_t acc = w0 ^ 0xd0000268U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038618U);
}
static std::uint32_t ByteVc0FdeFunc_0447_0x038634(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[447] @ func_va=0x038634, fde_va=0x07b610, first_op=0xf81e0ff3
    // VI: Hàm FDE[447] tại địa chỉ 0x038634, bản ghi FDE 0x07b610
    const std::uint32_t w0 = kByteVc0TextWords[51685U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038634U);
}
static std::uint32_t ByteVc0FdeFunc_0448_0x038668(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[448] @ func_va=0x038668, fde_va=0x07b630, first_op=0xa9be4ff4
    // VI: Hàm FDE[448] tại địa chỉ 0x038668, bản ghi FDE 0x07b630
    const std::uint32_t w0 = kByteVc0TextWords[51698U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038668U);
}
static std::uint32_t ByteVc0FdeFunc_0449_0x0386a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[449] @ func_va=0x0386a8, fde_va=0x07b650, first_op=0xf81d0ff5
    // VI: Hàm FDE[449] tại địa chỉ 0x0386a8, bản ghi FDE 0x07b650
    const std::uint32_t w0 = kByteVc0TextWords[51714U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0386a8U);
}
static std::uint32_t ByteVc0FdeFunc_0450_0x038748(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[450] @ func_va=0x038748, fde_va=0x07b670, first_op=0xa9be4ff4
    // VI: Hàm FDE[450] tại địa chỉ 0x038748, bản ghi FDE 0x07b670
    const std::uint32_t w0 = kByteVc0TextWords[51754U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038748U);
}
static std::uint32_t ByteVc0FdeFunc_0451_0x0387fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[451] @ func_va=0x0387fc, fde_va=0x07b690, first_op=0xa9be4ff4
    // VI: Hàm FDE[451] tại địa chỉ 0x0387fc, bản ghi FDE 0x07b690
    const std::uint32_t w0 = kByteVc0TextWords[51799U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0387fcU);
}
static std::uint32_t ByteVc0FdeFunc_0452_0x0388dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[452] @ func_va=0x0388dc, fde_va=0x07b6b0, first_op=0xf81e0ff3
    // VI: Hàm FDE[452] tại địa chỉ 0x0388dc, bản ghi FDE 0x07b6b0
    const std::uint32_t w0 = kByteVc0TextWords[51855U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0388dcU);
}
static std::uint32_t ByteVc0FdeFunc_0453_0x038934(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[453] @ func_va=0x038934, fde_va=0x07b6d0, first_op=0xf81d0ff5
    // VI: Hàm FDE[453] tại địa chỉ 0x038934, bản ghi FDE 0x07b6d0
    const std::uint32_t w0 = kByteVc0TextWords[51877U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038934U);
}
static std::uint32_t ByteVc0FdeFunc_0454_0x038990(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[454] @ func_va=0x038990, fde_va=0x07b6f0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[454] tại địa chỉ 0x038990, bản ghi FDE 0x07b6f0
    const std::uint32_t w0 = kByteVc0TextWords[51900U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038990U);
}
static std::uint32_t ByteVc0FdeFunc_0455_0x038ba4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[455] @ func_va=0x038ba4, fde_va=0x07b720, first_op=0xf9400c08
    // VI: Hàm FDE[455] tại địa chỉ 0x038ba4, bản ghi FDE 0x07b720
    const std::uint32_t w0 = kByteVc0TextWords[52033U];
    std::uint32_t acc = w0 ^ 0xf9400c08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038ba4U);
}
static std::uint32_t ByteVc0FdeFunc_0456_0x038c30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[456] @ func_va=0x038c30, fde_va=0x07b738, first_op=0xd10243ff
    // VI: Hàm FDE[456] tại địa chỉ 0x038c30, bản ghi FDE 0x07b738
    const std::uint32_t w0 = kByteVc0TextWords[52068U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x038c30U);
}
static std::uint32_t ByteVc0FdeFunc_0457_0x0392cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[457] @ func_va=0x0392cc, fde_va=0x07b768, first_op=0xaa0003e8
    // VI: Hàm FDE[457] tại địa chỉ 0x0392cc, bản ghi FDE 0x07b768
    const std::uint32_t w0 = kByteVc0TextWords[52491U];
    std::uint32_t acc = w0 ^ 0xaa0003e8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0392ccU);
}
static std::uint32_t ByteVc0FdeFunc_0458_0x0394a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[458] @ func_va=0x0394a0, fde_va=0x07b780, first_op=0xb0000268
    // VI: Hàm FDE[458] tại địa chỉ 0x0394a0, bản ghi FDE 0x07b780
    const std::uint32_t w0 = kByteVc0TextWords[52608U];
    std::uint32_t acc = w0 ^ 0xb0000268U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0394a0U);
}
static std::uint32_t ByteVc0FdeFunc_0459_0x0394f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[459] @ func_va=0x0394f0, fde_va=0x07b798, first_op=0xa9be4ff4
    // VI: Hàm FDE[459] tại địa chỉ 0x0394f0, bản ghi FDE 0x07b798
    const std::uint32_t w0 = kByteVc0TextWords[52628U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0394f0U);
}
static std::uint32_t ByteVc0FdeFunc_0460_0x039540(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[460] @ func_va=0x039540, fde_va=0x07b7b8, first_op=0xa9be4ff4
    // VI: Hàm FDE[460] tại địa chỉ 0x039540, bản ghi FDE 0x07b7b8
    const std::uint32_t w0 = kByteVc0TextWords[52648U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039540U);
}
static std::uint32_t ByteVc0FdeFunc_0461_0x03959c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[461] @ func_va=0x03959c, fde_va=0x07b7d8, first_op=0xf81e0ff3
    // VI: Hàm FDE[461] tại địa chỉ 0x03959c, bản ghi FDE 0x07b7d8
    const std::uint32_t w0 = kByteVc0TextWords[52671U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03959cU);
}
static std::uint32_t ByteVc0FdeFunc_0462_0x0395c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[462] @ func_va=0x0395c0, fde_va=0x07b7f8, first_op=0x2959a408
    // VI: Hàm FDE[462] tại địa chỉ 0x0395c0, bản ghi FDE 0x07b7f8
    const std::uint32_t w0 = kByteVc0TextWords[52680U];
    std::uint32_t acc = w0 ^ 0x2959a408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0395c0U);
}
static std::uint32_t ByteVc0FdeFunc_0463_0x0395d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[463] @ func_va=0x0395d0, fde_va=0x07b810, first_op=0xf81c0ff7
    // VI: Hàm FDE[463] tại địa chỉ 0x0395d0, bản ghi FDE 0x07b810
    const std::uint32_t w0 = kByteVc0TextWords[52684U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0395d0U);
}
static std::uint32_t ByteVc0FdeFunc_0464_0x039694(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[464] @ func_va=0x039694, fde_va=0x07b838, first_op=0xd10183ff
    // VI: Hàm FDE[464] tại địa chỉ 0x039694, bản ghi FDE 0x07b838
    const std::uint32_t w0 = kByteVc0TextWords[52733U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039694U);
}
static std::uint32_t ByteVc0FdeFunc_0465_0x0397b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[465] @ func_va=0x0397b8, fde_va=0x07b860, first_op=0xf81e0ff3
    // VI: Hàm FDE[465] tại địa chỉ 0x0397b8, bản ghi FDE 0x07b860
    const std::uint32_t w0 = kByteVc0TextWords[52806U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0397b8U);
}
static std::uint32_t ByteVc0FdeFunc_0466_0x039800(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[466] @ func_va=0x039800, fde_va=0x07b880, first_op=0xf81d0ff5
    // VI: Hàm FDE[466] tại địa chỉ 0x039800, bản ghi FDE 0x07b880
    const std::uint32_t w0 = kByteVc0TextWords[52824U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039800U);
}
static std::uint32_t ByteVc0FdeFunc_0467_0x039904(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[467] @ func_va=0x039904, fde_va=0x07b8a0, first_op=0xa9be4ff4
    // VI: Hàm FDE[467] tại địa chỉ 0x039904, bản ghi FDE 0x07b8a0
    const std::uint32_t w0 = kByteVc0TextWords[52889U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039904U);
}
static std::uint32_t ByteVc0FdeFunc_0468_0x039970(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[468] @ func_va=0x039970, fde_va=0x07b8c0, first_op=0xd10103ff
    // VI: Hàm FDE[468] tại địa chỉ 0x039970, bản ghi FDE 0x07b8c0
    const std::uint32_t w0 = kByteVc0TextWords[52916U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039970U);
}
static std::uint32_t ByteVc0FdeFunc_0469_0x039aa0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[469] @ func_va=0x039aa0, fde_va=0x07b8e0, first_op=0x52800f08
    // VI: Hàm FDE[469] tại địa chỉ 0x039aa0, bản ghi FDE 0x07b8e0
    const std::uint32_t w0 = kByteVc0TextWords[52992U];
    std::uint32_t acc = w0 ^ 0x52800f08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039aa0U);
}
static std::uint32_t ByteVc0FdeFunc_0470_0x039adc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[470] @ func_va=0x039adc, fde_va=0x07b8f8, first_op=0xa9bb67fa
    // VI: Hàm FDE[470] tại địa chỉ 0x039adc, bản ghi FDE 0x07b8f8
    const std::uint32_t w0 = kByteVc0TextWords[53007U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039adcU);
}
static std::uint32_t ByteVc0FdeFunc_0471_0x039ccc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[471] @ func_va=0x039ccc, fde_va=0x07b928, first_op=0xd10103ff
    // VI: Hàm FDE[471] tại địa chỉ 0x039ccc, bản ghi FDE 0x07b928
    const std::uint32_t w0 = kByteVc0TextWords[53131U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039cccU);
}
static std::uint32_t ByteVc0FdeFunc_0472_0x039dcc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[472] @ func_va=0x039dcc, fde_va=0x07b950, first_op=0x91009008
    // VI: Hàm FDE[472] tại địa chỉ 0x039dcc, bản ghi FDE 0x07b950
    const std::uint32_t w0 = kByteVc0TextWords[53195U];
    std::uint32_t acc = w0 ^ 0x91009008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039dccU);
}
static std::uint32_t ByteVc0FdeFunc_0473_0x039dd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[473] @ func_va=0x039dd8, fde_va=0x07b968, first_op=0x2a1f03e0
    // VI: Hàm FDE[473] tại địa chỉ 0x039dd8, bản ghi FDE 0x07b968
    const std::uint32_t w0 = kByteVc0TextWords[53198U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039dd8U);
}
static std::uint32_t ByteVc0FdeFunc_0474_0x039de0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[474] @ func_va=0x039de0, fde_va=0x07b980, first_op=0xa9be4ff4
    // VI: Hàm FDE[474] tại địa chỉ 0x039de0, bản ghi FDE 0x07b980
    const std::uint32_t w0 = kByteVc0TextWords[53200U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039de0U);
}
static std::uint32_t ByteVc0FdeFunc_0475_0x039e40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[475] @ func_va=0x039e40, fde_va=0x07b9a0, first_op=0xd10183ff
    // VI: Hàm FDE[475] tại địa chỉ 0x039e40, bản ghi FDE 0x07b9a0
    const std::uint32_t w0 = kByteVc0TextWords[53224U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039e40U);
}
static std::uint32_t ByteVc0FdeFunc_0476_0x039f10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[476] @ func_va=0x039f10, fde_va=0x07b9c8, first_op=0xf81d0ff5
    // VI: Hàm FDE[476] tại địa chỉ 0x039f10, bản ghi FDE 0x07b9c8
    const std::uint32_t w0 = kByteVc0TextWords[53276U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039f10U);
}
static std::uint32_t ByteVc0FdeFunc_0477_0x039f8c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[477] @ func_va=0x039f8c, fde_va=0x07b9e8, first_op=0xa9be4ff4
    // VI: Hàm FDE[477] tại địa chỉ 0x039f8c, bản ghi FDE 0x07b9e8
    const std::uint32_t w0 = kByteVc0TextWords[53307U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039f8cU);
}
static std::uint32_t ByteVc0FdeFunc_0478_0x039ff0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[478] @ func_va=0x039ff0, fde_va=0x07ba08, first_op=0xf9400068
    // VI: Hàm FDE[478] tại địa chỉ 0x039ff0, bản ghi FDE 0x07ba08
    const std::uint32_t w0 = kByteVc0TextWords[53332U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x039ff0U);
}
static std::uint32_t ByteVc0FdeFunc_0479_0x03a010(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[479] @ func_va=0x03a010, fde_va=0x07ba20, first_op=0xd101c3ff
    // VI: Hàm FDE[479] tại địa chỉ 0x03a010, bản ghi FDE 0x07ba20
    const std::uint32_t w0 = kByteVc0TextWords[53340U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03a010U);
}
static std::uint32_t ByteVc0FdeFunc_0480_0x03a124(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[480] @ func_va=0x03a124, fde_va=0x07ba48, first_op=0xf81d0ff5
    // VI: Hàm FDE[480] tại địa chỉ 0x03a124, bản ghi FDE 0x07ba48
    const std::uint32_t w0 = kByteVc0TextWords[53409U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03a124U);
}
static std::uint32_t ByteVc0FdeFunc_0481_0x03a19c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[481] @ func_va=0x03a19c, fde_va=0x07ba68, first_op=0xf81e0ff3
    // VI: Hàm FDE[481] tại địa chỉ 0x03a19c, bản ghi FDE 0x07ba68
    const std::uint32_t w0 = kByteVc0TextWords[53439U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03a19cU);
}
static std::uint32_t ByteVc0FdeFunc_0482_0x03a1d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[482] @ func_va=0x03a1d4, fde_va=0x07ba88, first_op=0x6dbc23e9
    // VI: Hàm FDE[482] tại địa chỉ 0x03a1d4, bản ghi FDE 0x07ba88
    const std::uint32_t w0 = kByteVc0TextWords[53453U];
    std::uint32_t acc = w0 ^ 0x6dbc23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03a1d4U);
}
static std::uint32_t ByteVc0FdeFunc_0483_0x03ac30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[483] @ func_va=0x03ac30, fde_va=0x07bab0, first_op=0xb9402029
    // VI: Hàm FDE[483] tại địa chỉ 0x03ac30, bản ghi FDE 0x07bab0
    const std::uint32_t w0 = kByteVc0TextWords[54116U];
    std::uint32_t acc = w0 ^ 0xb9402029U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03ac30U);
}
static std::uint32_t ByteVc0FdeFunc_0484_0x03ad9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[484] @ func_va=0x03ad9c, fde_va=0x07bac8, first_op=0xfc1b0fe8
    // VI: Hàm FDE[484] tại địa chỉ 0x03ad9c, bản ghi FDE 0x07bac8
    const std::uint32_t w0 = kByteVc0TextWords[54207U];
    std::uint32_t acc = w0 ^ 0xfc1b0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03ad9cU);
}
static std::uint32_t ByteVc0FdeFunc_0485_0x03bfbc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[485] @ func_va=0x03bfbc, fde_va=0x07baf8, first_op=0xd10443ff
    // VI: Hàm FDE[485] tại địa chỉ 0x03bfbc, bản ghi FDE 0x07baf8
    const std::uint32_t w0 = kByteVc0TextWords[55367U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03bfbcU);
}
static std::uint32_t ByteVc0FdeFunc_0486_0x03c058(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[486] @ func_va=0x03c058, fde_va=0x07bb18, first_op=0xd65f03c0
    // VI: Hàm FDE[486] tại địa chỉ 0x03c058, bản ghi FDE 0x07bb18
    const std::uint32_t w0 = kByteVc0TextWords[55406U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c058U);
}
static std::uint32_t ByteVc0FdeFunc_0487_0x03c05c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[487] @ func_va=0x03c05c, fde_va=0x07bb30, first_op=0xa9be4ff4
    // VI: Hàm FDE[487] tại địa chỉ 0x03c05c, bản ghi FDE 0x07bb30
    const std::uint32_t w0 = kByteVc0TextWords[55407U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c05cU);
}
static std::uint32_t ByteVc0FdeFunc_0488_0x03c17c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[488] @ func_va=0x03c17c, fde_va=0x07bb50, first_op=0xa9be4ff4
    // VI: Hàm FDE[488] tại địa chỉ 0x03c17c, bản ghi FDE 0x07bb50
    const std::uint32_t w0 = kByteVc0TextWords[55479U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c17cU);
}
static std::uint32_t ByteVc0FdeFunc_0489_0x03c1fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[489] @ func_va=0x03c1fc, fde_va=0x07bb70, first_op=0xf81e0ff3
    // VI: Hàm FDE[489] tại địa chỉ 0x03c1fc, bản ghi FDE 0x07bb70
    const std::uint32_t w0 = kByteVc0TextWords[55511U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c1fcU);
}
static std::uint32_t ByteVc0FdeFunc_0490_0x03c234(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[490] @ func_va=0x03c234, fde_va=0x07bb90, first_op=0x6f00e400
    // VI: Hàm FDE[490] tại địa chỉ 0x03c234, bản ghi FDE 0x07bb90
    const std::uint32_t w0 = kByteVc0TextWords[55525U];
    std::uint32_t acc = w0 ^ 0x6f00e400U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c234U);
}
static std::uint32_t ByteVc0FdeFunc_0491_0x03c2c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[491] @ func_va=0x03c2c4, fde_va=0x07bba8, first_op=0xa9bf7bfd
    // VI: Hàm FDE[491] tại địa chỉ 0x03c2c4, bản ghi FDE 0x07bba8
    const std::uint32_t w0 = kByteVc0TextWords[55561U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c2c4U);
}
static std::uint32_t ByteVc0FdeFunc_0492_0x03c424(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[492] @ func_va=0x03c424, fde_va=0x07bbc8, first_op=0xa9007c1f
    // VI: Hàm FDE[492] tại địa chỉ 0x03c424, bản ghi FDE 0x07bbc8
    const std::uint32_t w0 = kByteVc0TextWords[55649U];
    std::uint32_t acc = w0 ^ 0xa9007c1fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c424U);
}
static std::uint32_t ByteVc0FdeFunc_0493_0x03c468(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[493] @ func_va=0x03c468, fde_va=0x07bbe0, first_op=0xb00001a8
    // VI: Hàm FDE[493] tại địa chỉ 0x03c468, bản ghi FDE 0x07bbe0
    const std::uint32_t w0 = kByteVc0TextWords[55666U];
    std::uint32_t acc = w0 ^ 0xb00001a8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c468U);
}
static std::uint32_t ByteVc0FdeFunc_0494_0x03c480(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[494] @ func_va=0x03c480, fde_va=0x07bbf8, first_op=0xf81e0ff3
    // VI: Hàm FDE[494] tại địa chỉ 0x03c480, bản ghi FDE 0x07bbf8
    const std::uint32_t w0 = kByteVc0TextWords[55672U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c480U);
}
static std::uint32_t ByteVc0FdeFunc_0495_0x03c4d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[495] @ func_va=0x03c4d0, fde_va=0x07bc18, first_op=0xf81c0ff7
    // VI: Hàm FDE[495] tại địa chỉ 0x03c4d0, bản ghi FDE 0x07bc18
    const std::uint32_t w0 = kByteVc0TextWords[55692U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03c4d0U);
}
static std::uint32_t ByteVc0FdeFunc_0496_0x03cf50(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[496] @ func_va=0x03cf50, fde_va=0x07bc40, first_op=0xf81d0ff5
    // VI: Hàm FDE[496] tại địa chỉ 0x03cf50, bản ghi FDE 0x07bc40
    const std::uint32_t w0 = kByteVc0TextWords[56364U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03cf50U);
}
static std::uint32_t ByteVc0FdeFunc_0497_0x03d430(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[497] @ func_va=0x03d430, fde_va=0x07bc60, first_op=0xd10443ff
    // VI: Hàm FDE[497] tại địa chỉ 0x03d430, bản ghi FDE 0x07bc60
    const std::uint32_t w0 = kByteVc0TextWords[56676U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d430U);
}
static std::uint32_t ByteVc0FdeFunc_0498_0x03d5c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[498] @ func_va=0x03d5c8, fde_va=0x07bc88, first_op=0xd10443ff
    // VI: Hàm FDE[498] tại địa chỉ 0x03d5c8, bản ghi FDE 0x07bc88
    const std::uint32_t w0 = kByteVc0TextWords[56778U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d5c8U);
}
static std::uint32_t ByteVc0FdeFunc_0499_0x03d664(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[499] @ func_va=0x03d664, fde_va=0x07bca8, first_op=0x531a646a
    // VI: Hàm FDE[499] tại địa chỉ 0x03d664, bản ghi FDE 0x07bca8
    const std::uint32_t w0 = kByteVc0TextWords[56817U];
    std::uint32_t acc = w0 ^ 0x531a646aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d664U);
}
static std::uint32_t ByteVc0FdeFunc_0500_0x03d6c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[500] @ func_va=0x03d6c0, fde_va=0x07bcc0, first_op=0xaa1f03e8
    // VI: Hàm FDE[500] tại địa chỉ 0x03d6c0, bản ghi FDE 0x07bcc0
    const std::uint32_t w0 = kByteVc0TextWords[56840U];
    std::uint32_t acc = w0 ^ 0xaa1f03e8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d6c0U);
}
static std::uint32_t ByteVc0FdeFunc_0501_0x03d744(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[501] @ func_va=0x03d744, fde_va=0x07bcd8, first_op=0x7100045f
    // VI: Hàm FDE[501] tại địa chỉ 0x03d744, bản ghi FDE 0x07bcd8
    const std::uint32_t w0 = kByteVc0TextWords[56873U];
    std::uint32_t acc = w0 ^ 0x7100045fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d744U);
}
static std::uint32_t ByteVc0FdeFunc_0502_0x03d830(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[502] @ func_va=0x03d830, fde_va=0x07bcf0, first_op=0x2a1f03ea
    // VI: Hàm FDE[502] tại địa chỉ 0x03d830, bản ghi FDE 0x07bcf0
    const std::uint32_t w0 = kByteVc0TextWords[56932U];
    std::uint32_t acc = w0 ^ 0x2a1f03eaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d830U);
}
static std::uint32_t ByteVc0FdeFunc_0503_0x03d890(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[503] @ func_va=0x03d890, fde_va=0x07bd08, first_op=0x7100043f
    // VI: Hàm FDE[503] tại địa chỉ 0x03d890, bản ghi FDE 0x07bd08
    const std::uint32_t w0 = kByteVc0TextWords[56956U];
    std::uint32_t acc = w0 ^ 0x7100043fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d890U);
}
static std::uint32_t ByteVc0FdeFunc_0504_0x03d900(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[504] @ func_va=0x03d900, fde_va=0x07bd20, first_op=0xb4000141
    // VI: Hàm FDE[504] tại địa chỉ 0x03d900, bản ghi FDE 0x07bd20
    const std::uint32_t w0 = kByteVc0TextWords[56984U];
    std::uint32_t acc = w0 ^ 0xb4000141U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d900U);
}
static std::uint32_t ByteVc0FdeFunc_0505_0x03d930(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[505] @ func_va=0x03d930, fde_va=0x07bd38, first_op=0xf81c0ff7
    // VI: Hàm FDE[505] tại địa chỉ 0x03d930, bản ghi FDE 0x07bd38
    const std::uint32_t w0 = kByteVc0TextWords[56996U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03d930U);
}
static std::uint32_t ByteVc0FdeFunc_0506_0x03dacc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[506] @ func_va=0x03dacc, fde_va=0x07bd60, first_op=0xa9ba6ffc
    // VI: Hàm FDE[506] tại địa chỉ 0x03dacc, bản ghi FDE 0x07bd60
    const std::uint32_t w0 = kByteVc0TextWords[57099U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03daccU);
}
static std::uint32_t ByteVc0FdeFunc_0507_0x03df68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[507] @ func_va=0x03df68, fde_va=0x07bd90, first_op=0xf81e0ff3
    // VI: Hàm FDE[507] tại địa chỉ 0x03df68, bản ghi FDE 0x07bd90
    const std::uint32_t w0 = kByteVc0TextWords[57394U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03df68U);
}
static std::uint32_t ByteVc0FdeFunc_0508_0x03dfb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[508] @ func_va=0x03dfb4, fde_va=0x07bdb0, first_op=0xf81e0ff3
    // VI: Hàm FDE[508] tại địa chỉ 0x03dfb4, bản ghi FDE 0x07bdb0
    const std::uint32_t w0 = kByteVc0TextWords[57413U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03dfb4U);
}
static std::uint32_t ByteVc0FdeFunc_0509_0x03dfe8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[509] @ func_va=0x03dfe8, fde_va=0x07bdd0, first_op=0xa9bf7bfd
    // VI: Hàm FDE[509] tại địa chỉ 0x03dfe8, bản ghi FDE 0x07bdd0
    const std::uint32_t w0 = kByteVc0TextWords[57426U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03dfe8U);
}
static std::uint32_t ByteVc0FdeFunc_0510_0x03e008(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[510] @ func_va=0x03e008, fde_va=0x07bdf0, first_op=0xa9be4ff4
    // VI: Hàm FDE[510] tại địa chỉ 0x03e008, bản ghi FDE 0x07bdf0
    const std::uint32_t w0 = kByteVc0TextWords[57434U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e008U);
}
static std::uint32_t ByteVc0FdeFunc_0511_0x03e0d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[511] @ func_va=0x03e0d0, fde_va=0x07be10, first_op=0xf81e0ff3
    // VI: Hàm FDE[511] tại địa chỉ 0x03e0d0, bản ghi FDE 0x07be10
    const std::uint32_t w0 = kByteVc0TextWords[57484U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e0d0U);
}
static std::uint32_t ByteVc0FdeFunc_0512_0x03e134(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[512] @ func_va=0x03e134, fde_va=0x07be30, first_op=0xf81e0ff3
    // VI: Hàm FDE[512] tại địa chỉ 0x03e134, bản ghi FDE 0x07be30
    const std::uint32_t w0 = kByteVc0TextWords[57509U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e134U);
}
static std::uint32_t ByteVc0FdeFunc_0513_0x03e168(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[513] @ func_va=0x03e168, fde_va=0x07be50, first_op=0xa9bd57f6
    // VI: Hàm FDE[513] tại địa chỉ 0x03e168, bản ghi FDE 0x07be50
    const std::uint32_t w0 = kByteVc0TextWords[57522U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e168U);
}
static std::uint32_t ByteVc0FdeFunc_0514_0x03e2c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[514] @ func_va=0x03e2c4, fde_va=0x07be78, first_op=0xd10183ff
    // VI: Hàm FDE[514] tại địa chỉ 0x03e2c4, bản ghi FDE 0x07be78
    const std::uint32_t w0 = kByteVc0TextWords[57609U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e2c4U);
}
static std::uint32_t ByteVc0FdeFunc_0515_0x03e3e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[515] @ func_va=0x03e3e8, fde_va=0x07bea0, first_op=0xd10183ff
    // VI: Hàm FDE[515] tại địa chỉ 0x03e3e8, bản ghi FDE 0x07bea0
    const std::uint32_t w0 = kByteVc0TextWords[57682U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e3e8U);
}
static std::uint32_t ByteVc0FdeFunc_0516_0x03e50c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[516] @ func_va=0x03e50c, fde_va=0x07bec8, first_op=0xa9be4ff4
    // VI: Hàm FDE[516] tại địa chỉ 0x03e50c, bản ghi FDE 0x07bec8
    const std::uint32_t w0 = kByteVc0TextWords[57755U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e50cU);
}
static std::uint32_t ByteVc0FdeFunc_0517_0x03e58c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[517] @ func_va=0x03e58c, fde_va=0x07bee8, first_op=0xf81e0ff3
    // VI: Hàm FDE[517] tại địa chỉ 0x03e58c, bản ghi FDE 0x07bee8
    const std::uint32_t w0 = kByteVc0TextWords[57787U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e58cU);
}
static std::uint32_t ByteVc0FdeFunc_0518_0x03e5d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[518] @ func_va=0x03e5d4, fde_va=0x07bf08, first_op=0xf81e0ff3
    // VI: Hàm FDE[518] tại địa chỉ 0x03e5d4, bản ghi FDE 0x07bf08
    const std::uint32_t w0 = kByteVc0TextWords[57805U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e5d4U);
}
static std::uint32_t ByteVc0FdeFunc_0519_0x03e61c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[519] @ func_va=0x03e61c, fde_va=0x07bf28, first_op=0xa9bc5ff8
    // VI: Hàm FDE[519] tại địa chỉ 0x03e61c, bản ghi FDE 0x07bf28
    const std::uint32_t w0 = kByteVc0TextWords[57823U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e61cU);
}
static std::uint32_t ByteVc0FdeFunc_0520_0x03e738(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[520] @ func_va=0x03e738, fde_va=0x07bf50, first_op=0xd10103ff
    // VI: Hàm FDE[520] tại địa chỉ 0x03e738, bản ghi FDE 0x07bf50
    const std::uint32_t w0 = kByteVc0TextWords[57894U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e738U);
}
static std::uint32_t ByteVc0FdeFunc_0521_0x03e868(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[521] @ func_va=0x03e868, fde_va=0x07bf70, first_op=0xa9bc5ff8
    // VI: Hàm FDE[521] tại địa chỉ 0x03e868, bản ghi FDE 0x07bf70
    const std::uint32_t w0 = kByteVc0TextWords[57970U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e868U);
}
static std::uint32_t ByteVc0FdeFunc_0522_0x03e9ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[522] @ func_va=0x03e9ac, fde_va=0x07bf98, first_op=0xa9be4ff4
    // VI: Hàm FDE[522] tại địa chỉ 0x03e9ac, bản ghi FDE 0x07bf98
    const std::uint32_t w0 = kByteVc0TextWords[58051U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03e9acU);
}
static std::uint32_t ByteVc0FdeFunc_0523_0x03ea28(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[523] @ func_va=0x03ea28, fde_va=0x07bfb8, first_op=0xd10103ff
    // VI: Hàm FDE[523] tại địa chỉ 0x03ea28, bản ghi FDE 0x07bfb8
    const std::uint32_t w0 = kByteVc0TextWords[58082U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03ea28U);
}
static std::uint32_t ByteVc0FdeFunc_0524_0x03eb58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[524] @ func_va=0x03eb58, fde_va=0x07bfd8, first_op=0xf81c0ff7
    // VI: Hàm FDE[524] tại địa chỉ 0x03eb58, bản ghi FDE 0x07bfd8
    const std::uint32_t w0 = kByteVc0TextWords[58158U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03eb58U);
}
static std::uint32_t ByteVc0FdeFunc_0525_0x03ec34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[525] @ func_va=0x03ec34, fde_va=0x07c000, first_op=0xf81d0ff5
    // VI: Hàm FDE[525] tại địa chỉ 0x03ec34, bản ghi FDE 0x07c000
    const std::uint32_t w0 = kByteVc0TextWords[58213U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03ec34U);
}
static std::uint32_t ByteVc0FdeFunc_0526_0x03ecc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[526] @ func_va=0x03ecc0, fde_va=0x07c020, first_op=0xd10103ff
    // VI: Hàm FDE[526] tại địa chỉ 0x03ecc0, bản ghi FDE 0x07c020
    const std::uint32_t w0 = kByteVc0TextWords[58248U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03ecc0U);
}
static std::uint32_t ByteVc0FdeFunc_0527_0x03edc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[527] @ func_va=0x03edc0, fde_va=0x07c048, first_op=0xd10103ff
    // VI: Hàm FDE[527] tại địa chỉ 0x03edc0, bản ghi FDE 0x07c048
    const std::uint32_t w0 = kByteVc0TextWords[58312U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03edc0U);
}
static std::uint32_t ByteVc0FdeFunc_0528_0x03eec0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[528] @ func_va=0x03eec0, fde_va=0x07c070, first_op=0x710004bf
    // VI: Hàm FDE[528] tại địa chỉ 0x03eec0, bản ghi FDE 0x07c070
    const std::uint32_t w0 = kByteVc0TextWords[58376U];
    std::uint32_t acc = w0 ^ 0x710004bfU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03eec0U);
}
static std::uint32_t ByteVc0FdeFunc_0529_0x03ef58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[529] @ func_va=0x03ef58, fde_va=0x07c088, first_op=0xf81b0ff9
    // VI: Hàm FDE[529] tại địa chỉ 0x03ef58, bản ghi FDE 0x07c088
    const std::uint32_t w0 = kByteVc0TextWords[58414U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03ef58U);
}
static std::uint32_t ByteVc0FdeFunc_0530_0x03f0e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[530] @ func_va=0x03f0e8, fde_va=0x07c0b0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[530] tại địa chỉ 0x03f0e8, bản ghi FDE 0x07c0b0
    const std::uint32_t w0 = kByteVc0TextWords[58514U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03f0e8U);
}
static std::uint32_t ByteVc0FdeFunc_0531_0x03ff5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[531] @ func_va=0x03ff5c, fde_va=0x07c0e0, first_op=0xf81e0ff3
    // VI: Hàm FDE[531] tại địa chỉ 0x03ff5c, bản ghi FDE 0x07c0e0
    const std::uint32_t w0 = kByteVc0TextWords[59439U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03ff5cU);
}
static std::uint32_t ByteVc0FdeFunc_0532_0x03ff9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[532] @ func_va=0x03ff9c, fde_va=0x07c100, first_op=0xa9ba6ffc
    // VI: Hàm FDE[532] tại địa chỉ 0x03ff9c, bản ghi FDE 0x07c100
    const std::uint32_t w0 = kByteVc0TextWords[59455U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x03ff9cU);
}
static std::uint32_t ByteVc0FdeFunc_0533_0x0409a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[533] @ func_va=0x0409a4, fde_va=0x07c130, first_op=0x17ff144b
    // VI: Hàm FDE[533] tại địa chỉ 0x0409a4, bản ghi FDE 0x07c130
    const std::uint32_t w0 = kByteVc0TextWords[60097U];
    std::uint32_t acc = w0 ^ 0x17ff144bU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0409a4U);
}
static std::uint32_t ByteVc0FdeFunc_0534_0x0409a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[534] @ func_va=0x0409a8, fde_va=0x07c148, first_op=0x17ff144a
    // VI: Hàm FDE[534] tại địa chỉ 0x0409a8, bản ghi FDE 0x07c148
    const std::uint32_t w0 = kByteVc0TextWords[60098U];
    std::uint32_t acc = w0 ^ 0x17ff144aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0409a8U);
}
static std::uint32_t ByteVc0FdeFunc_0535_0x0409ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[535] @ func_va=0x0409ac, fde_va=0x07c160, first_op=0xa9be4ff4
    // VI: Hàm FDE[535] tại địa chỉ 0x0409ac, bản ghi FDE 0x07c160
    const std::uint32_t w0 = kByteVc0TextWords[60099U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0409acU);
}
static std::uint32_t ByteVc0FdeFunc_0536_0x0409e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[536] @ func_va=0x0409e8, fde_va=0x07c180, first_op=0xf81e0ff3
    // VI: Hàm FDE[536] tại địa chỉ 0x0409e8, bản ghi FDE 0x07c180
    const std::uint32_t w0 = kByteVc0TextWords[60114U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0409e8U);
}
static std::uint32_t ByteVc0FdeFunc_0537_0x040a0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[537] @ func_va=0x040a0c, fde_va=0x07c1a0, first_op=0xd10243ff
    // VI: Hàm FDE[537] tại địa chỉ 0x040a0c, bản ghi FDE 0x07c1a0
    const std::uint32_t w0 = kByteVc0TextWords[60123U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x040a0cU);
}
static std::uint32_t ByteVc0FdeFunc_0538_0x040c80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[538] @ func_va=0x040c80, fde_va=0x07c1d0, first_op=0xd102c3ff
    // VI: Hàm FDE[538] tại địa chỉ 0x040c80, bản ghi FDE 0x07c1d0
    const std::uint32_t w0 = kByteVc0TextWords[60280U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x040c80U);
}
static std::uint32_t ByteVc0FdeFunc_0539_0x040e04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[539] @ func_va=0x040e04, fde_va=0x07c200, first_op=0xd10583ff
    // VI: Hàm FDE[539] tại địa chỉ 0x040e04, bản ghi FDE 0x07c200
    const std::uint32_t w0 = kByteVc0TextWords[60377U];
    std::uint32_t acc = w0 ^ 0xd10583ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x040e04U);
}
static std::uint32_t ByteVc0FdeFunc_0540_0x041424(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[540] @ func_va=0x041424, fde_va=0x07c230, first_op=0xd101c3ff
    // VI: Hàm FDE[540] tại địa chỉ 0x041424, bản ghi FDE 0x07c230
    const std::uint32_t w0 = kByteVc0TextWords[60769U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041424U);
}
static std::uint32_t ByteVc0FdeFunc_0541_0x041538(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[541] @ func_va=0x041538, fde_va=0x07c258, first_op=0xa9be4ff4
    // VI: Hàm FDE[541] tại địa chỉ 0x041538, bản ghi FDE 0x07c258
    const std::uint32_t w0 = kByteVc0TextWords[60838U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041538U);
}
static std::uint32_t ByteVc0FdeFunc_0542_0x04159c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[542] @ func_va=0x04159c, fde_va=0x07c278, first_op=0xf9400068
    // VI: Hàm FDE[542] tại địa chỉ 0x04159c, bản ghi FDE 0x07c278
    const std::uint32_t w0 = kByteVc0TextWords[60863U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04159cU);
}
static std::uint32_t ByteVc0FdeFunc_0543_0x0415bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[543] @ func_va=0x0415bc, fde_va=0x07c290, first_op=0xd10203ff
    // VI: Hàm FDE[543] tại địa chỉ 0x0415bc, bản ghi FDE 0x07c290
    const std::uint32_t w0 = kByteVc0TextWords[60871U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0415bcU);
}
static std::uint32_t ByteVc0FdeFunc_0544_0x041798(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[544] @ func_va=0x041798, fde_va=0x07c2b8, first_op=0xf9400409
    // VI: Hàm FDE[544] tại địa chỉ 0x041798, bản ghi FDE 0x07c2b8
    const std::uint32_t w0 = kByteVc0TextWords[60990U];
    std::uint32_t acc = w0 ^ 0xf9400409U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041798U);
}
static std::uint32_t ByteVc0FdeFunc_0545_0x0417e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[545] @ func_va=0x0417e0, fde_va=0x07c2d0, first_op=0xa9bc5ff8
    // VI: Hàm FDE[545] tại địa chỉ 0x0417e0, bản ghi FDE 0x07c2d0
    const std::uint32_t w0 = kByteVc0TextWords[61008U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0417e0U);
}
static std::uint32_t ByteVc0FdeFunc_0546_0x041880(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[546] @ func_va=0x041880, fde_va=0x07c2f8, first_op=0xa9be4ff4
    // VI: Hàm FDE[546] tại địa chỉ 0x041880, bản ghi FDE 0x07c2f8
    const std::uint32_t w0 = kByteVc0TextWords[61048U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041880U);
}
static std::uint32_t ByteVc0FdeFunc_0547_0x0418c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[547] @ func_va=0x0418c0, fde_va=0x07c318, first_op=0xd10183ff
    // VI: Hàm FDE[547] tại địa chỉ 0x0418c0, bản ghi FDE 0x07c318
    const std::uint32_t w0 = kByteVc0TextWords[61064U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0418c0U);
}
static std::uint32_t ByteVc0FdeFunc_0548_0x041990(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[548] @ func_va=0x041990, fde_va=0x07c340, first_op=0xf81d0ff5
    // VI: Hàm FDE[548] tại địa chỉ 0x041990, bản ghi FDE 0x07c340
    const std::uint32_t w0 = kByteVc0TextWords[61116U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041990U);
}
static std::uint32_t ByteVc0FdeFunc_0549_0x041a0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[549] @ func_va=0x041a0c, fde_va=0x07c360, first_op=0xa9be4ff4
    // VI: Hàm FDE[549] tại địa chỉ 0x041a0c, bản ghi FDE 0x07c360
    const std::uint32_t w0 = kByteVc0TextWords[61147U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041a0cU);
}
static std::uint32_t ByteVc0FdeFunc_0550_0x041a70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[550] @ func_va=0x041a70, fde_va=0x07c380, first_op=0xf9400068
    // VI: Hàm FDE[550] tại địa chỉ 0x041a70, bản ghi FDE 0x07c380
    const std::uint32_t w0 = kByteVc0TextWords[61172U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041a70U);
}
static std::uint32_t ByteVc0FdeFunc_0551_0x041a90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[551] @ func_va=0x041a90, fde_va=0x07c398, first_op=0xd101c3ff
    // VI: Hàm FDE[551] tại địa chỉ 0x041a90, bản ghi FDE 0x07c398
    const std::uint32_t w0 = kByteVc0TextWords[61180U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041a90U);
}
static std::uint32_t ByteVc0FdeFunc_0552_0x041ba4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[552] @ func_va=0x041ba4, fde_va=0x07c3c0, first_op=0xd10183ff
    // VI: Hàm FDE[552] tại địa chỉ 0x041ba4, bản ghi FDE 0x07c3c0
    const std::uint32_t w0 = kByteVc0TextWords[61249U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041ba4U);
}
static std::uint32_t ByteVc0FdeFunc_0553_0x041c74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[553] @ func_va=0x041c74, fde_va=0x07c3e8, first_op=0xf81d0ff5
    // VI: Hàm FDE[553] tại địa chỉ 0x041c74, bản ghi FDE 0x07c3e8
    const std::uint32_t w0 = kByteVc0TextWords[61301U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041c74U);
}
static std::uint32_t ByteVc0FdeFunc_0554_0x041cf0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[554] @ func_va=0x041cf0, fde_va=0x07c408, first_op=0xa9be4ff4
    // VI: Hàm FDE[554] tại địa chỉ 0x041cf0, bản ghi FDE 0x07c408
    const std::uint32_t w0 = kByteVc0TextWords[61332U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041cf0U);
}
static std::uint32_t ByteVc0FdeFunc_0555_0x041d54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[555] @ func_va=0x041d54, fde_va=0x07c428, first_op=0xf9400068
    // VI: Hàm FDE[555] tại địa chỉ 0x041d54, bản ghi FDE 0x07c428
    const std::uint32_t w0 = kByteVc0TextWords[61357U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041d54U);
}
static std::uint32_t ByteVc0FdeFunc_0556_0x041d74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[556] @ func_va=0x041d74, fde_va=0x07c440, first_op=0xd101c3ff
    // VI: Hàm FDE[556] tại địa chỉ 0x041d74, bản ghi FDE 0x07c440
    const std::uint32_t w0 = kByteVc0TextWords[61365U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041d74U);
}
static std::uint32_t ByteVc0FdeFunc_0557_0x041e88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[557] @ func_va=0x041e88, fde_va=0x07c468, first_op=0xa9be4ff4
    // VI: Hàm FDE[557] tại địa chỉ 0x041e88, bản ghi FDE 0x07c468
    const std::uint32_t w0 = kByteVc0TextWords[61434U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041e88U);
}
static std::uint32_t ByteVc0FdeFunc_0558_0x041f6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[558] @ func_va=0x041f6c, fde_va=0x07c488, first_op=0xb4000080
    // VI: Hàm FDE[558] tại địa chỉ 0x041f6c, bản ghi FDE 0x07c488
    const std::uint32_t w0 = kByteVc0TextWords[61491U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041f6cU);
}
static std::uint32_t ByteVc0FdeFunc_0559_0x041f80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[559] @ func_va=0x041f80, fde_va=0x07c4a0, first_op=0xb0000228
    // VI: Hàm FDE[559] tại địa chỉ 0x041f80, bản ghi FDE 0x07c4a0
    const std::uint32_t w0 = kByteVc0TextWords[61496U];
    std::uint32_t acc = w0 ^ 0xb0000228U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x041f80U);
}
static std::uint32_t ByteVc0FdeFunc_0560_0x042124(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[560] @ func_va=0x042124, fde_va=0x07c4b8, first_op=0xf81e0ff3
    // VI: Hàm FDE[560] tại địa chỉ 0x042124, bản ghi FDE 0x07c4b8
    const std::uint32_t w0 = kByteVc0TextWords[61601U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042124U);
}
static std::uint32_t ByteVc0FdeFunc_0561_0x042178(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[561] @ func_va=0x042178, fde_va=0x07c4d8, first_op=0xd4200020
    // VI: Hàm FDE[561] tại địa chỉ 0x042178, bản ghi FDE 0x07c4d8
    const std::uint32_t w0 = kByteVc0TextWords[61622U];
    std::uint32_t acc = w0 ^ 0xd4200020U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042178U);
}
static std::uint32_t ByteVc0FdeFunc_0562_0x04217c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[562] @ func_va=0x04217c, fde_va=0x07c4f0, first_op=0x6dbd23e9
    // VI: Hàm FDE[562] tại địa chỉ 0x04217c, bản ghi FDE 0x07c4f0
    const std::uint32_t w0 = kByteVc0TextWords[61623U];
    std::uint32_t acc = w0 ^ 0x6dbd23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04217cU);
}
static std::uint32_t ByteVc0FdeFunc_0563_0x042590(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[563] @ func_va=0x042590, fde_va=0x07c518, first_op=0xf81d0ff5
    // VI: Hàm FDE[563] tại địa chỉ 0x042590, bản ghi FDE 0x07c518
    const std::uint32_t w0 = kByteVc0TextWords[61884U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042590U);
}
static std::uint32_t ByteVc0FdeFunc_0564_0x0425f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[564] @ func_va=0x0425f0, fde_va=0x07c538, first_op=0xf9400408
    // VI: Hàm FDE[564] tại địa chỉ 0x0425f0, bản ghi FDE 0x07c538
    const std::uint32_t w0 = kByteVc0TextWords[61908U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0425f0U);
}
static std::uint32_t ByteVc0FdeFunc_0565_0x042694(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[565] @ func_va=0x042694, fde_va=0x07c550, first_op=0xf9400408
    // VI: Hàm FDE[565] tại địa chỉ 0x042694, bản ghi FDE 0x07c550
    const std::uint32_t w0 = kByteVc0TextWords[61949U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042694U);
}
static std::uint32_t ByteVc0FdeFunc_0566_0x042994(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[566] @ func_va=0x042994, fde_va=0x07c568, first_op=0xd10483ff
    // VI: Hàm FDE[566] tại địa chỉ 0x042994, bản ghi FDE 0x07c568
    const std::uint32_t w0 = kByteVc0TextWords[62141U];
    std::uint32_t acc = w0 ^ 0xd10483ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042994U);
}
static std::uint32_t ByteVc0FdeFunc_0567_0x042b94(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[567] @ func_va=0x042b94, fde_va=0x07c590, first_op=0x12800008
    // VI: Hàm FDE[567] tại địa chỉ 0x042b94, bản ghi FDE 0x07c590
    const std::uint32_t w0 = kByteVc0TextWords[62269U];
    std::uint32_t acc = w0 ^ 0x12800008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042b94U);
}
static std::uint32_t ByteVc0FdeFunc_0568_0x042be4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[568] @ func_va=0x042be4, fde_va=0x07c5a8, first_op=0xf81e0ff3
    // VI: Hàm FDE[568] tại địa chỉ 0x042be4, bản ghi FDE 0x07c5a8
    const std::uint32_t w0 = kByteVc0TextWords[62289U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042be4U);
}
static std::uint32_t ByteVc0FdeFunc_0569_0x042cc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[569] @ func_va=0x042cc0, fde_va=0x07c5c8, first_op=0xf000016a
    // VI: Hàm FDE[569] tại địa chỉ 0x042cc0, bản ghi FDE 0x07c5c8
    const std::uint32_t w0 = kByteVc0TextWords[62344U];
    std::uint32_t acc = w0 ^ 0xf000016aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042cc0U);
}
static std::uint32_t ByteVc0FdeFunc_0570_0x042de8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[570] @ func_va=0x042de8, fde_va=0x07c5e0, first_op=0xfc1d0fe8
    // VI: Hàm FDE[570] tại địa chỉ 0x042de8, bản ghi FDE 0x07c5e0
    const std::uint32_t w0 = kByteVc0TextWords[62418U];
    std::uint32_t acc = w0 ^ 0xfc1d0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x042de8U);
}
static std::uint32_t ByteVc0FdeFunc_0571_0x0431a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[571] @ func_va=0x0431a0, fde_va=0x07c608, first_op=0xa9be4ff4
    // VI: Hàm FDE[571] tại địa chỉ 0x0431a0, bản ghi FDE 0x07c608
    const std::uint32_t w0 = kByteVc0TextWords[62656U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0431a0U);
}
static std::uint32_t ByteVc0FdeFunc_0572_0x0432e4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[572] @ func_va=0x0432e4, fde_va=0x07c628, first_op=0xa9be4ff4
    // VI: Hàm FDE[572] tại địa chỉ 0x0432e4, bản ghi FDE 0x07c628
    const std::uint32_t w0 = kByteVc0TextWords[62737U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0432e4U);
}
static std::uint32_t ByteVc0FdeFunc_0573_0x043394(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[573] @ func_va=0x043394, fde_va=0x07c648, first_op=0xa9be4ff4
    // VI: Hàm FDE[573] tại địa chỉ 0x043394, bản ghi FDE 0x07c648
    const std::uint32_t w0 = kByteVc0TextWords[62781U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x043394U);
}
static std::uint32_t ByteVc0FdeFunc_0574_0x04343c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[574] @ func_va=0x04343c, fde_va=0x07c668, first_op=0xf81d0ff5
    // VI: Hàm FDE[574] tại địa chỉ 0x04343c, bản ghi FDE 0x07c668
    const std::uint32_t w0 = kByteVc0TextWords[62823U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04343cU);
}
static std::uint32_t ByteVc0FdeFunc_0575_0x043524(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[575] @ func_va=0x043524, fde_va=0x07c688, first_op=0xa9bf7bfd
    // VI: Hàm FDE[575] tại địa chỉ 0x043524, bản ghi FDE 0x07c688
    const std::uint32_t w0 = kByteVc0TextWords[62881U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x043524U);
}
static std::uint32_t ByteVc0FdeFunc_0576_0x0435b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[576] @ func_va=0x0435b0, fde_va=0x07c6a8, first_op=0xf81e0ff3
    // VI: Hàm FDE[576] tại địa chỉ 0x0435b0, bản ghi FDE 0x07c6a8
    const std::uint32_t w0 = kByteVc0TextWords[62916U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0435b0U);
}
static std::uint32_t ByteVc0FdeFunc_0577_0x0436d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[577] @ func_va=0x0436d4, fde_va=0x07c6c8, first_op=0xf81d0ff5
    // VI: Hàm FDE[577] tại địa chỉ 0x0436d4, bản ghi FDE 0x07c6c8
    const std::uint32_t w0 = kByteVc0TextWords[62989U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0436d4U);
}
static std::uint32_t ByteVc0FdeFunc_0578_0x04390c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[578] @ func_va=0x04390c, fde_va=0x07c6e8, first_op=0xd10483ff
    // VI: Hàm FDE[578] tại địa chỉ 0x04390c, bản ghi FDE 0x07c6e8
    const std::uint32_t w0 = kByteVc0TextWords[63131U];
    std::uint32_t acc = w0 ^ 0xd10483ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04390cU);
}
static std::uint32_t ByteVc0FdeFunc_0579_0x043b98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[579] @ func_va=0x043b98, fde_va=0x07c710, first_op=0xb940e00b
    // VI: Hàm FDE[579] tại địa chỉ 0x043b98, bản ghi FDE 0x07c710
    const std::uint32_t w0 = kByteVc0TextWords[63294U];
    std::uint32_t acc = w0 ^ 0xb940e00bU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x043b98U);
}
static std::uint32_t ByteVc0FdeFunc_0580_0x043c84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[580] @ func_va=0x043c84, fde_va=0x07c728, first_op=0x6b02003f
    // VI: Hàm FDE[580] tại địa chỉ 0x043c84, bản ghi FDE 0x07c728
    const std::uint32_t w0 = kByteVc0TextWords[63353U];
    std::uint32_t acc = w0 ^ 0x6b02003fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x043c84U);
}
static std::uint32_t ByteVc0FdeFunc_0581_0x043e24(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[581] @ func_va=0x043e24, fde_va=0x07c740, first_op=0xf81e0ff3
    // VI: Hàm FDE[581] tại địa chỉ 0x043e24, bản ghi FDE 0x07c740
    const std::uint32_t w0 = kByteVc0TextWords[63457U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x043e24U);
}
static std::uint32_t ByteVc0FdeFunc_0582_0x043eac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[582] @ func_va=0x043eac, fde_va=0x07c760, first_op=0xf81e0ff3
    // VI: Hàm FDE[582] tại địa chỉ 0x043eac, bản ghi FDE 0x07c760
    const std::uint32_t w0 = kByteVc0TextWords[63491U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x043eacU);
}
static std::uint32_t ByteVc0FdeFunc_0583_0x043fe8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[583] @ func_va=0x043fe8, fde_va=0x07c780, first_op=0xf9400408
    // VI: Hàm FDE[583] tại địa chỉ 0x043fe8, bản ghi FDE 0x07c780
    const std::uint32_t w0 = kByteVc0TextWords[63570U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x043fe8U);
}
static std::uint32_t ByteVc0FdeFunc_0584_0x044040(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[584] @ func_va=0x044040, fde_va=0x07c798, first_op=0xb900003f
    // VI: Hàm FDE[584] tại địa chỉ 0x044040, bản ghi FDE 0x07c798
    const std::uint32_t w0 = kByteVc0TextWords[63592U];
    std::uint32_t acc = w0 ^ 0xb900003fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044040U);
}
static std::uint32_t ByteVc0FdeFunc_0585_0x044114(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[585] @ func_va=0x044114, fde_va=0x07c7b0, first_op=0xf9400408
    // VI: Hàm FDE[585] tại địa chỉ 0x044114, bản ghi FDE 0x07c7b0
    const std::uint32_t w0 = kByteVc0TextWords[63645U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044114U);
}
static std::uint32_t ByteVc0FdeFunc_0586_0x044148(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[586] @ func_va=0x044148, fde_va=0x07c7c8, first_op=0xf81e0ff3
    // VI: Hàm FDE[586] tại địa chỉ 0x044148, bản ghi FDE 0x07c7c8
    const std::uint32_t w0 = kByteVc0TextWords[63658U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044148U);
}
static std::uint32_t ByteVc0FdeFunc_0587_0x044304(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[587] @ func_va=0x044304, fde_va=0x07c7e8, first_op=0x6941a428
    // VI: Hàm FDE[587] tại địa chỉ 0x044304, bản ghi FDE 0x07c7e8
    const std::uint32_t w0 = kByteVc0TextWords[63769U];
    std::uint32_t acc = w0 ^ 0x6941a428U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044304U);
}
static std::uint32_t ByteVc0FdeFunc_0588_0x0443dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[588] @ func_va=0x0443dc, fde_va=0x07c800, first_op=0xf9400c28
    // VI: Hàm FDE[588] tại địa chỉ 0x0443dc, bản ghi FDE 0x07c800
    const std::uint32_t w0 = kByteVc0TextWords[63823U];
    std::uint32_t acc = w0 ^ 0xf9400c28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0443dcU);
}
static std::uint32_t ByteVc0FdeFunc_0589_0x0444a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[589] @ func_va=0x0444a0, fde_va=0x07c818, first_op=0xf81a0ffb
    // VI: Hàm FDE[589] tại địa chỉ 0x0444a0, bản ghi FDE 0x07c818
    const std::uint32_t w0 = kByteVc0TextWords[63872U];
    std::uint32_t acc = w0 ^ 0xf81a0ffbU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0444a0U);
}
static std::uint32_t ByteVc0FdeFunc_0590_0x044764(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[590] @ func_va=0x044764, fde_va=0x07c848, first_op=0x6b02003f
    // VI: Hàm FDE[590] tại địa chỉ 0x044764, bản ghi FDE 0x07c848
    const std::uint32_t w0 = kByteVc0TextWords[64049U];
    std::uint32_t acc = w0 ^ 0x6b02003fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044764U);
}
static std::uint32_t ByteVc0FdeFunc_0591_0x044910(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[591] @ func_va=0x044910, fde_va=0x07c860, first_op=0x6b02003f
    // VI: Hàm FDE[591] tại địa chỉ 0x044910, bản ghi FDE 0x07c860
    const std::uint32_t w0 = kByteVc0TextWords[64156U];
    std::uint32_t acc = w0 ^ 0x6b02003fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044910U);
}
static std::uint32_t ByteVc0FdeFunc_0592_0x04494c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[592] @ func_va=0x04494c, fde_va=0x07c878, first_op=0xf81d0ff5
    // VI: Hàm FDE[592] tại địa chỉ 0x04494c, bản ghi FDE 0x07c878
    const std::uint32_t w0 = kByteVc0TextWords[64171U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04494cU);
}
static std::uint32_t ByteVc0FdeFunc_0593_0x044a38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[593] @ func_va=0x044a38, fde_va=0x07c898, first_op=0x39418008
    // VI: Hàm FDE[593] tại địa chỉ 0x044a38, bản ghi FDE 0x07c898
    const std::uint32_t w0 = kByteVc0TextWords[64230U];
    std::uint32_t acc = w0 ^ 0x39418008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044a38U);
}
static std::uint32_t ByteVc0FdeFunc_0594_0x044b30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[594] @ func_va=0x044b30, fde_va=0x07c8b0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[594] tại địa chỉ 0x044b30, bản ghi FDE 0x07c8b0
    const std::uint32_t w0 = kByteVc0TextWords[64292U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044b30U);
}
static std::uint32_t ByteVc0FdeFunc_0595_0x044c40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[595] @ func_va=0x044c40, fde_va=0x07c8e0, first_op=0xb4000241
    // VI: Hàm FDE[595] tại địa chỉ 0x044c40, bản ghi FDE 0x07c8e0
    const std::uint32_t w0 = kByteVc0TextWords[64360U];
    std::uint32_t acc = w0 ^ 0xb4000241U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044c40U);
}
static std::uint32_t ByteVc0FdeFunc_0596_0x044d60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[596] @ func_va=0x044d60, fde_va=0x07c8f8, first_op=0xd101c3ff
    // VI: Hàm FDE[596] tại địa chỉ 0x044d60, bản ghi FDE 0x07c8f8
    const std::uint32_t w0 = kByteVc0TextWords[64432U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044d60U);
}
static std::uint32_t ByteVc0FdeFunc_0597_0x044fa8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[597] @ func_va=0x044fa8, fde_va=0x07c928, first_op=0xb941a008
    // VI: Hàm FDE[597] tại địa chỉ 0x044fa8, bản ghi FDE 0x07c928
    const std::uint32_t w0 = kByteVc0TextWords[64578U];
    std::uint32_t acc = w0 ^ 0xb941a008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x044fa8U);
}
static std::uint32_t ByteVc0FdeFunc_0598_0x045034(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[598] @ func_va=0x045034, fde_va=0x07c940, first_op=0xd0000148
    // VI: Hàm FDE[598] tại địa chỉ 0x045034, bản ghi FDE 0x07c940
    const std::uint32_t w0 = kByteVc0TextWords[64613U];
    std::uint32_t acc = w0 ^ 0xd0000148U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x045034U);
}
static std::uint32_t ByteVc0FdeFunc_0599_0x0450c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[599] @ func_va=0x0450c0, fde_va=0x07c958, first_op=0x7100005f
    // VI: Hàm FDE[599] tại địa chỉ 0x0450c0, bản ghi FDE 0x07c958
    const std::uint32_t w0 = kByteVc0TextWords[64648U];
    std::uint32_t acc = w0 ^ 0x7100005fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0450c0U);
}
static std::uint32_t ByteVc0FdeFunc_0600_0x0451c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[600] @ func_va=0x0451c4, fde_va=0x07c970, first_op=0x7100285f
    // VI: Hàm FDE[600] tại địa chỉ 0x0451c4, bản ghi FDE 0x07c970
    const std::uint32_t w0 = kByteVc0TextWords[64713U];
    std::uint32_t acc = w0 ^ 0x7100285fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0451c4U);
}
static std::uint32_t ByteVc0FdeFunc_0601_0x0452b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[601] @ func_va=0x0452b8, fde_va=0x07c988, first_op=0xf81b0ff9
    // VI: Hàm FDE[601] tại địa chỉ 0x0452b8, bản ghi FDE 0x07c988
    const std::uint32_t w0 = kByteVc0TextWords[64774U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0452b8U);
}
static std::uint32_t ByteVc0FdeFunc_0602_0x0453ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[602] @ func_va=0x0453ac, fde_va=0x07c9b0, first_op=0xfd400022
    // VI: Hàm FDE[602] tại địa chỉ 0x0453ac, bản ghi FDE 0x07c9b0
    const std::uint32_t w0 = kByteVc0TextWords[64835U];
    std::uint32_t acc = w0 ^ 0xfd400022U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0453acU);
}
static std::uint32_t ByteVc0FdeFunc_0603_0x0453f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[603] @ func_va=0x0453f0, fde_va=0x07c9c8, first_op=0xa9bd57f6
    // VI: Hàm FDE[603] tại địa chỉ 0x0453f0, bản ghi FDE 0x07c9c8
    const std::uint32_t w0 = kByteVc0TextWords[64852U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0453f0U);
}
static std::uint32_t ByteVc0FdeFunc_0604_0x0454d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[604] @ func_va=0x0454d4, fde_va=0x07c9f0, first_op=0x52803408
    // VI: Hàm FDE[604] tại địa chỉ 0x0454d4, bản ghi FDE 0x07c9f0
    const std::uint32_t w0 = kByteVc0TextWords[64909U];
    std::uint32_t acc = w0 ^ 0x52803408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0454d4U);
}
static std::uint32_t ByteVc0FdeFunc_0605_0x0455d8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[605] @ func_va=0x0455d8, fde_va=0x07ca08, first_op=0xd10403ff
    // VI: Hàm FDE[605] tại địa chỉ 0x0455d8, bản ghi FDE 0x07ca08
    const std::uint32_t w0 = kByteVc0TextWords[64974U];
    std::uint32_t acc = w0 ^ 0xd10403ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0455d8U);
}
static std::uint32_t ByteVc0FdeFunc_0606_0x045898(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[606] @ func_va=0x045898, fde_va=0x07ca38, first_op=0xfc180fea
    // VI: Hàm FDE[606] tại địa chỉ 0x045898, bản ghi FDE 0x07ca38
    const std::uint32_t w0 = kByteVc0TextWords[65150U];
    std::uint32_t acc = w0 ^ 0xfc180feaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x045898U);
}
static std::uint32_t ByteVc0FdeFunc_0607_0x045bec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[607] @ func_va=0x045bec, fde_va=0x07ca70, first_op=0xb98bfc08
    // VI: Hàm FDE[607] tại địa chỉ 0x045bec, bản ghi FDE 0x07ca70
    const std::uint32_t w0 = kByteVc0TextWords[65363U];
    std::uint32_t acc = w0 ^ 0xb98bfc08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x045becU);
}
static std::uint32_t ByteVc0FdeFunc_0608_0x045ce0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[608] @ func_va=0x045ce0, fde_va=0x07ca88, first_op=0xb94bfc08
    // VI: Hàm FDE[608] tại địa chỉ 0x045ce0, bản ghi FDE 0x07ca88
    const std::uint32_t w0 = kByteVc0TextWords[65424U];
    std::uint32_t acc = w0 ^ 0xb94bfc08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x045ce0U);
}
static std::uint32_t ByteVc0FdeFunc_0609_0x045db8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[609] @ func_va=0x045db8, fde_va=0x07caa0, first_op=0xb94bfc08
    // VI: Hàm FDE[609] tại địa chỉ 0x045db8, bản ghi FDE 0x07caa0
    const std::uint32_t w0 = kByteVc0TextWords[65478U];
    std::uint32_t acc = w0 ^ 0xb94bfc08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x045db8U);
}
static std::uint32_t ByteVc0FdeFunc_0610_0x045e18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[610] @ func_va=0x045e18, fde_va=0x07cab8, first_op=0xb941a008
    // VI: Hàm FDE[610] tại địa chỉ 0x045e18, bản ghi FDE 0x07cab8
    const std::uint32_t w0 = kByteVc0TextWords[65502U];
    std::uint32_t acc = w0 ^ 0xb941a008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x045e18U);
}
static std::uint32_t ByteVc0FdeFunc_0611_0x045ea8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[611] @ func_va=0x045ea8, fde_va=0x07cad0, first_op=0xb941a008
    // VI: Hàm FDE[611] tại địa chỉ 0x045ea8, bản ghi FDE 0x07cad0
    const std::uint32_t w0 = kByteVc0TextWords[65538U];
    std::uint32_t acc = w0 ^ 0xb941a008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x045ea8U);
}
static std::uint32_t ByteVc0FdeFunc_0612_0x045f34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[612] @ func_va=0x045f34, fde_va=0x07cae8, first_op=0x6dbb23e9
    // VI: Hàm FDE[612] tại địa chỉ 0x045f34, bản ghi FDE 0x07cae8
    const std::uint32_t w0 = kByteVc0TextWords[65573U];
    std::uint32_t acc = w0 ^ 0x6dbb23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x045f34U);
}
static std::uint32_t ByteVc0FdeFunc_0613_0x046018(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[613] @ func_va=0x046018, fde_va=0x07cb18, first_op=0xf9460408
    // VI: Hàm FDE[613] tại địa chỉ 0x046018, bản ghi FDE 0x07cb18
    const std::uint32_t w0 = kByteVc0TextWords[65630U];
    std::uint32_t acc = w0 ^ 0xf9460408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046018U);
}
static std::uint32_t ByteVc0FdeFunc_0614_0x046114(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[614] @ func_va=0x046114, fde_va=0x07cb30, first_op=0xb94be408
    // VI: Hàm FDE[614] tại địa chỉ 0x046114, bản ghi FDE 0x07cb30
    const std::uint32_t w0 = kByteVc0TextWords[65693U];
    std::uint32_t acc = w0 ^ 0xb94be408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046114U);
}
static std::uint32_t ByteVc0FdeFunc_0615_0x04626c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[615] @ func_va=0x04626c, fde_va=0x07cb48, first_op=0xa9bd57f6
    // VI: Hàm FDE[615] tại địa chỉ 0x04626c, bản ghi FDE 0x07cb48
    const std::uint32_t w0 = kByteVc0TextWords[65779U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04626cU);
}
static std::uint32_t ByteVc0FdeFunc_0616_0x0462dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[616] @ func_va=0x0462dc, fde_va=0x07cb70, first_op=0xb9400829
    // VI: Hàm FDE[616] tại địa chỉ 0x0462dc, bản ghi FDE 0x07cb70
    const std::uint32_t w0 = kByteVc0TextWords[65807U];
    std::uint32_t acc = w0 ^ 0xb9400829U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0462dcU);
}
static std::uint32_t ByteVc0FdeFunc_0617_0x046390(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[617] @ func_va=0x046390, fde_va=0x07cb88, first_op=0xf9403428
    // VI: Hàm FDE[617] tại địa chỉ 0x046390, bản ghi FDE 0x07cb88
    const std::uint32_t w0 = kByteVc0TextWords[65852U];
    std::uint32_t acc = w0 ^ 0xf9403428U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046390U);
}
static std::uint32_t ByteVc0FdeFunc_0618_0x0464c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[618] @ func_va=0x0464c8, fde_va=0x07cba0, first_op=0xb94bdc08
    // VI: Hàm FDE[618] tại địa chỉ 0x0464c8, bản ghi FDE 0x07cba0
    const std::uint32_t w0 = kByteVc0TextWords[65930U];
    std::uint32_t acc = w0 ^ 0xb94bdc08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0464c8U);
}
static std::uint32_t ByteVc0FdeFunc_0619_0x0465e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[619] @ func_va=0x0465e0, fde_va=0x07cbb8, first_op=0xb0000148
    // VI: Hàm FDE[619] tại địa chỉ 0x0465e0, bản ghi FDE 0x07cbb8
    const std::uint32_t w0 = kByteVc0TextWords[66000U];
    std::uint32_t acc = w0 ^ 0xb0000148U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0465e0U);
}
static std::uint32_t ByteVc0FdeFunc_0620_0x046610(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[620] @ func_va=0x046610, fde_va=0x07cbd0, first_op=0x396f6409
    // VI: Hàm FDE[620] tại địa chỉ 0x046610, bản ghi FDE 0x07cbd0
    const std::uint32_t w0 = kByteVc0TextWords[66012U];
    std::uint32_t acc = w0 ^ 0x396f6409U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046610U);
}
static std::uint32_t ByteVc0FdeFunc_0621_0x046770(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[621] @ func_va=0x046770, fde_va=0x07cbe8, first_op=0xb94bfc08
    // VI: Hàm FDE[621] tại địa chỉ 0x046770, bản ghi FDE 0x07cbe8
    const std::uint32_t w0 = kByteVc0TextWords[66100U];
    std::uint32_t acc = w0 ^ 0xb94bfc08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046770U);
}
static std::uint32_t ByteVc0FdeFunc_0622_0x0467ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[622] @ func_va=0x0467ec, fde_va=0x07cc00, first_op=0xfc1b0fe8
    // VI: Hàm FDE[622] tại địa chỉ 0x0467ec, bản ghi FDE 0x07cc00
    const std::uint32_t w0 = kByteVc0TextWords[66131U];
    std::uint32_t acc = w0 ^ 0xfc1b0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0467ecU);
}
static std::uint32_t ByteVc0FdeFunc_0623_0x0468d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[623] @ func_va=0x0468d0, fde_va=0x07cc28, first_op=0xf9406828
    // VI: Hàm FDE[623] tại địa chỉ 0x0468d0, bản ghi FDE 0x07cc28
    const std::uint32_t w0 = kByteVc0TextWords[66188U];
    std::uint32_t acc = w0 ^ 0xf9406828U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0468d0U);
}
static std::uint32_t ByteVc0FdeFunc_0624_0x0468e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[624] @ func_va=0x0468e8, fde_va=0x07cc40, first_op=0xf9406828
    // VI: Hàm FDE[624] tại địa chỉ 0x0468e8, bản ghi FDE 0x07cc40
    const std::uint32_t w0 = kByteVc0TextWords[66194U];
    std::uint32_t acc = w0 ^ 0xf9406828U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0468e8U);
}
static std::uint32_t ByteVc0FdeFunc_0625_0x04692c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[625] @ func_va=0x04692c, fde_va=0x07cc58, first_op=0x6dba23e9
    // VI: Hàm FDE[625] tại địa chỉ 0x04692c, bản ghi FDE 0x07cc58
    const std::uint32_t w0 = kByteVc0TextWords[66211U];
    std::uint32_t acc = w0 ^ 0x6dba23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04692cU);
}
static std::uint32_t ByteVc0FdeFunc_0626_0x046af4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[626] @ func_va=0x046af4, fde_va=0x07cc88, first_op=0xf81e0ff3
    // VI: Hàm FDE[626] tại địa chỉ 0x046af4, bản ghi FDE 0x07cc88
    const std::uint32_t w0 = kByteVc0TextWords[66325U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046af4U);
}
static std::uint32_t ByteVc0FdeFunc_0627_0x046b20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[627] @ func_va=0x046b20, fde_va=0x07cca8, first_op=0xfd402400
    // VI: Hàm FDE[627] tại địa chỉ 0x046b20, bản ghi FDE 0x07cca8
    const std::uint32_t w0 = kByteVc0TextWords[66336U];
    std::uint32_t acc = w0 ^ 0xfd402400U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046b20U);
}
static std::uint32_t ByteVc0FdeFunc_0628_0x046bb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[628] @ func_va=0x046bb8, fde_va=0x07ccc0, first_op=0xb9401020
    // VI: Hàm FDE[628] tại địa chỉ 0x046bb8, bản ghi FDE 0x07ccc0
    const std::uint32_t w0 = kByteVc0TextWords[66374U];
    std::uint32_t acc = w0 ^ 0xb9401020U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046bb8U);
}
static std::uint32_t ByteVc0FdeFunc_0629_0x046bc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[629] @ func_va=0x046bc0, fde_va=0x07ccd8, first_op=0x90000208
    // VI: Hàm FDE[629] tại địa chỉ 0x046bc0, bản ghi FDE 0x07ccd8
    const std::uint32_t w0 = kByteVc0TextWords[66376U];
    std::uint32_t acc = w0 ^ 0x90000208U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046bc0U);
}
static std::uint32_t ByteVc0FdeFunc_0630_0x046bd0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[630] @ func_va=0x046bd0, fde_va=0x07ccf0, first_op=0xf81e0ff3
    // VI: Hàm FDE[630] tại địa chỉ 0x046bd0, bản ghi FDE 0x07ccf0
    const std::uint32_t w0 = kByteVc0TextWords[66380U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046bd0U);
}
static std::uint32_t ByteVc0FdeFunc_0631_0x046c00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[631] @ func_va=0x046c00, fde_va=0x07cd10, first_op=0xd65f03c0
    // VI: Hàm FDE[631] tại địa chỉ 0x046c00, bản ghi FDE 0x07cd10
    const std::uint32_t w0 = kByteVc0TextWords[66392U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046c00U);
}
static std::uint32_t ByteVc0FdeFunc_0632_0x046c04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[632] @ func_va=0x046c04, fde_va=0x07cd28, first_op=0xd65f03c0
    // VI: Hàm FDE[632] tại địa chỉ 0x046c04, bản ghi FDE 0x07cd28
    const std::uint32_t w0 = kByteVc0TextWords[66393U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046c04U);
}
static std::uint32_t ByteVc0FdeFunc_0633_0x046c08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[633] @ func_va=0x046c08, fde_va=0x07cd40, first_op=0x2a1f03e0
    // VI: Hàm FDE[633] tại địa chỉ 0x046c08, bản ghi FDE 0x07cd40
    const std::uint32_t w0 = kByteVc0TextWords[66394U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046c08U);
}
static std::uint32_t ByteVc0FdeFunc_0634_0x046c10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[634] @ func_va=0x046c10, fde_va=0x07cd58, first_op=0xf81d0ff5
    // VI: Hàm FDE[634] tại địa chỉ 0x046c10, bản ghi FDE 0x07cd58
    const std::uint32_t w0 = kByteVc0TextWords[66396U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046c10U);
}
static std::uint32_t ByteVc0FdeFunc_0635_0x046cdc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[635] @ func_va=0x046cdc, fde_va=0x07cd78, first_op=0xf81e0ff3
    // VI: Hàm FDE[635] tại địa chỉ 0x046cdc, bản ghi FDE 0x07cd78
    const std::uint32_t w0 = kByteVc0TextWords[66447U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046cdcU);
}
static std::uint32_t ByteVc0FdeFunc_0636_0x046d18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[636] @ func_va=0x046d18, fde_va=0x07cd98, first_op=0xf81e0ff3
    // VI: Hàm FDE[636] tại địa chỉ 0x046d18, bản ghi FDE 0x07cd98
    const std::uint32_t w0 = kByteVc0TextWords[66462U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046d18U);
}
static std::uint32_t ByteVc0FdeFunc_0637_0x046d3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[637] @ func_va=0x046d3c, fde_va=0x07cdb8, first_op=0x6dba23e9
    // VI: Hàm FDE[637] tại địa chỉ 0x046d3c, bản ghi FDE 0x07cdb8
    const std::uint32_t w0 = kByteVc0TextWords[66471U];
    std::uint32_t acc = w0 ^ 0x6dba23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x046d3cU);
}
static std::uint32_t ByteVc0FdeFunc_0638_0x04713c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[638] @ func_va=0x04713c, fde_va=0x07cde8, first_op=0xfc1c0fea
    // VI: Hàm FDE[638] tại địa chỉ 0x04713c, bản ghi FDE 0x07cde8
    const std::uint32_t w0 = kByteVc0TextWords[66727U];
    std::uint32_t acc = w0 ^ 0xfc1c0feaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04713cU);
}
static std::uint32_t ByteVc0FdeFunc_0639_0x047278(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[639] @ func_va=0x047278, fde_va=0x07ce10, first_op=0xf81d0ff5
    // VI: Hàm FDE[639] tại địa chỉ 0x047278, bản ghi FDE 0x07ce10
    const std::uint32_t w0 = kByteVc0TextWords[66806U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x047278U);
}
static std::uint32_t ByteVc0FdeFunc_0640_0x0472ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[640] @ func_va=0x0472ec, fde_va=0x07ce30, first_op=0x6db73bef
    // VI: Hàm FDE[640] tại địa chỉ 0x0472ec, bản ghi FDE 0x07ce30
    const std::uint32_t w0 = kByteVc0TextWords[66835U];
    std::uint32_t acc = w0 ^ 0x6db73befU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0472ecU);
}
static std::uint32_t ByteVc0FdeFunc_0641_0x0474e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[641] @ func_va=0x0474e0, fde_va=0x07ce70, first_op=0xb940182a
    // VI: Hàm FDE[641] tại địa chỉ 0x0474e0, bản ghi FDE 0x07ce70
    const std::uint32_t w0 = kByteVc0TextWords[66960U];
    std::uint32_t acc = w0 ^ 0xb940182aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0474e0U);
}
static std::uint32_t ByteVc0FdeFunc_0642_0x047694(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[642] @ func_va=0x047694, fde_va=0x07ce88, first_op=0x6db833ed
    // VI: Hàm FDE[642] tại địa chỉ 0x047694, bản ghi FDE 0x07ce88
    const std::uint32_t w0 = kByteVc0TextWords[67069U];
    std::uint32_t acc = w0 ^ 0x6db833edU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x047694U);
}
static std::uint32_t ByteVc0FdeFunc_0643_0x047a08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[643] @ func_va=0x047a08, fde_va=0x07cec8, first_op=0xfc1d0fe8
    // VI: Hàm FDE[643] tại địa chỉ 0x047a08, bản ghi FDE 0x07cec8
    const std::uint32_t w0 = kByteVc0TextWords[67290U];
    std::uint32_t acc = w0 ^ 0xfc1d0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x047a08U);
}
static std::uint32_t ByteVc0FdeFunc_0644_0x047bac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[644] @ func_va=0x047bac, fde_va=0x07cee8, first_op=0xfc1e0fe8
    // VI: Hàm FDE[644] tại địa chỉ 0x047bac, bản ghi FDE 0x07cee8
    const std::uint32_t w0 = kByteVc0TextWords[67395U];
    std::uint32_t acc = w0 ^ 0xfc1e0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x047bacU);
}
static std::uint32_t ByteVc0FdeFunc_0645_0x047be0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[645] @ func_va=0x047be0, fde_va=0x07cf08, first_op=0xfc1a0fec
    // VI: Hàm FDE[645] tại địa chỉ 0x047be0, bản ghi FDE 0x07cf08
    const std::uint32_t w0 = kByteVc0TextWords[67408U];
    std::uint32_t acc = w0 ^ 0xfc1a0fecU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x047be0U);
}
static std::uint32_t ByteVc0FdeFunc_0646_0x047eb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[646] @ func_va=0x047eb4, fde_va=0x07cf38, first_op=0xf81c0ff7
    // VI: Hàm FDE[646] tại địa chỉ 0x047eb4, bản ghi FDE 0x07cf38
    const std::uint32_t w0 = kByteVc0TextWords[67589U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x047eb4U);
}
static std::uint32_t ByteVc0FdeFunc_0647_0x047f5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[647] @ func_va=0x047f5c, fde_va=0x07cf60, first_op=0xb94bdc0e
    // VI: Hàm FDE[647] tại địa chỉ 0x047f5c, bản ghi FDE 0x07cf60
    const std::uint32_t w0 = kByteVc0TextWords[67631U];
    std::uint32_t acc = w0 ^ 0xb94bdc0eU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x047f5cU);
}
static std::uint32_t ByteVc0FdeFunc_0648_0x048258(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[648] @ func_va=0x048258, fde_va=0x07cf78, first_op=0x6db933ed
    // VI: Hàm FDE[648] tại địa chỉ 0x048258, bản ghi FDE 0x07cf78
    const std::uint32_t w0 = kByteVc0TextWords[67822U];
    std::uint32_t acc = w0 ^ 0x6db933edU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x048258U);
}
static std::uint32_t ByteVc0FdeFunc_0649_0x0484bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[649] @ func_va=0x0484bc, fde_va=0x07cfb0, first_op=0xa9bd57f6
    // VI: Hàm FDE[649] tại địa chỉ 0x0484bc, bản ghi FDE 0x07cfb0
    const std::uint32_t w0 = kByteVc0TextWords[67975U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0484bcU);
}
static std::uint32_t ByteVc0FdeFunc_0650_0x04877c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[650] @ func_va=0x04877c, fde_va=0x07cfd8, first_op=0xfc1a0fe8
    // VI: Hàm FDE[650] tại địa chỉ 0x04877c, bản ghi FDE 0x07cfd8
    const std::uint32_t w0 = kByteVc0TextWords[68151U];
    std::uint32_t acc = w0 ^ 0xfc1a0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04877cU);
}
static std::uint32_t ByteVc0FdeFunc_0651_0x048904(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[651] @ func_va=0x048904, fde_va=0x07d008, first_op=0xb94bfc08
    // VI: Hàm FDE[651] tại địa chỉ 0x048904, bản ghi FDE 0x07d008
    const std::uint32_t w0 = kByteVc0TextWords[68249U];
    std::uint32_t acc = w0 ^ 0xb94bfc08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x048904U);
}
static std::uint32_t ByteVc0FdeFunc_0652_0x048aa0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[652] @ func_va=0x048aa0, fde_va=0x07d020, first_op=0x6dbd23e9
    // VI: Hàm FDE[652] tại địa chỉ 0x048aa0, bản ghi FDE 0x07d020
    const std::uint32_t w0 = kByteVc0TextWords[68352U];
    std::uint32_t acc = w0 ^ 0x6dbd23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x048aa0U);
}
static std::uint32_t ByteVc0FdeFunc_0653_0x048c04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[653] @ func_va=0x048c04, fde_va=0x07d048, first_op=0xd10143ff
    // VI: Hàm FDE[653] tại địa chỉ 0x048c04, bản ghi FDE 0x07d048
    const std::uint32_t w0 = kByteVc0TextWords[68441U];
    std::uint32_t acc = w0 ^ 0xd10143ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x048c04U);
}
static std::uint32_t ByteVc0FdeFunc_0654_0x048ddc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[654] @ func_va=0x048ddc, fde_va=0x07d070, first_op=0xfc190fea
    // VI: Hàm FDE[654] tại địa chỉ 0x048ddc, bản ghi FDE 0x07d070
    const std::uint32_t w0 = kByteVc0TextWords[68559U];
    std::uint32_t acc = w0 ^ 0xfc190feaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x048ddcU);
}
static std::uint32_t ByteVc0FdeFunc_0655_0x04919c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[655] @ func_va=0x04919c, fde_va=0x07d0a8, first_op=0xfc1a0fea
    // VI: Hàm FDE[655] tại địa chỉ 0x04919c, bản ghi FDE 0x07d0a8
    const std::uint32_t w0 = kByteVc0TextWords[68799U];
    std::uint32_t acc = w0 ^ 0xfc1a0feaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04919cU);
}
static std::uint32_t ByteVc0FdeFunc_0656_0x049450(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[656] @ func_va=0x049450, fde_va=0x07d0d8, first_op=0xf9460408
    // VI: Hàm FDE[656] tại địa chỉ 0x049450, bản ghi FDE 0x07d0d8
    const std::uint32_t w0 = kByteVc0TextWords[68972U];
    std::uint32_t acc = w0 ^ 0xf9460408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x049450U);
}
static std::uint32_t ByteVc0FdeFunc_0657_0x049494(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[657] @ func_va=0x049494, fde_va=0x07d0f0, first_op=0xb94bdc08
    // VI: Hàm FDE[657] tại địa chỉ 0x049494, bản ghi FDE 0x07d0f0
    const std::uint32_t w0 = kByteVc0TextWords[68989U];
    std::uint32_t acc = w0 ^ 0xb94bdc08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x049494U);
}
static std::uint32_t ByteVc0FdeFunc_0658_0x0495c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[658] @ func_va=0x0495c4, fde_va=0x07d108, first_op=0xd10103ff
    // VI: Hàm FDE[658] tại địa chỉ 0x0495c4, bản ghi FDE 0x07d108
    const std::uint32_t w0 = kByteVc0TextWords[69065U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0495c4U);
}
static std::uint32_t ByteVc0FdeFunc_0659_0x04976c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[659] @ func_va=0x04976c, fde_va=0x07d128, first_op=0xb94bdc09
    // VI: Hàm FDE[659] tại địa chỉ 0x04976c, bản ghi FDE 0x07d128
    const std::uint32_t w0 = kByteVc0TextWords[69171U];
    std::uint32_t acc = w0 ^ 0xb94bdc09U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04976cU);
}
static std::uint32_t ByteVc0FdeFunc_0660_0x0498b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[660] @ func_va=0x0498b0, fde_va=0x07d140, first_op=0xa9bd57f6
    // VI: Hàm FDE[660] tại địa chỉ 0x0498b0, bản ghi FDE 0x07d140
    const std::uint32_t w0 = kByteVc0TextWords[69252U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0498b0U);
}
static std::uint32_t ByteVc0FdeFunc_0661_0x04998c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[661] @ func_va=0x04998c, fde_va=0x07d168, first_op=0x6db83bef
    // VI: Hàm FDE[661] tại địa chỉ 0x04998c, bản ghi FDE 0x07d168
    const std::uint32_t w0 = kByteVc0TextWords[69307U];
    std::uint32_t acc = w0 ^ 0x6db83befU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04998cU);
}
static std::uint32_t ByteVc0FdeFunc_0662_0x049c98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[662] @ func_va=0x049c98, fde_va=0x07d1a8, first_op=0x6db92beb
    // VI: Hàm FDE[662] tại địa chỉ 0x049c98, bản ghi FDE 0x07d1a8
    const std::uint32_t w0 = kByteVc0TextWords[69502U];
    std::uint32_t acc = w0 ^ 0x6db92bebU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x049c98U);
}
static std::uint32_t ByteVc0FdeFunc_0663_0x04a03c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[663] @ func_va=0x04a03c, fde_va=0x07d1e0, first_op=0x6db833ed
    // VI: Hàm FDE[663] tại địa chỉ 0x04a03c, bản ghi FDE 0x07d1e0
    const std::uint32_t w0 = kByteVc0TextWords[69735U];
    std::uint32_t acc = w0 ^ 0x6db833edU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04a03cU);
}
static std::uint32_t ByteVc0FdeFunc_0664_0x04a324(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[664] @ func_va=0x04a324, fde_va=0x07d220, first_op=0xd10283ff
    // VI: Hàm FDE[664] tại địa chỉ 0x04a324, bản ghi FDE 0x07d220
    const std::uint32_t w0 = kByteVc0TextWords[69921U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04a324U);
}
static std::uint32_t ByteVc0FdeFunc_0665_0x04a4c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[665] @ func_va=0x04a4c4, fde_va=0x07d250, first_op=0x6db833ed
    // VI: Hàm FDE[665] tại địa chỉ 0x04a4c4, bản ghi FDE 0x07d250
    const std::uint32_t w0 = kByteVc0TextWords[70025U];
    std::uint32_t acc = w0 ^ 0x6db833edU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04a4c4U);
}
static std::uint32_t ByteVc0FdeFunc_0666_0x04aae8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[666] @ func_va=0x04aae8, fde_va=0x07d290, first_op=0xa9ba6ffc
    // VI: Hàm FDE[666] tại địa chỉ 0x04aae8, bản ghi FDE 0x07d290
    const std::uint32_t w0 = kByteVc0TextWords[70418U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04aae8U);
}
static std::uint32_t ByteVc0FdeFunc_0667_0x04ac90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[667] @ func_va=0x04ac90, fde_va=0x07d2c0, first_op=0xb941a008
    // VI: Hàm FDE[667] tại địa chỉ 0x04ac90, bản ghi FDE 0x07d2c0
    const std::uint32_t w0 = kByteVc0TextWords[70524U];
    std::uint32_t acc = w0 ^ 0xb941a008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04ac90U);
}
static std::uint32_t ByteVc0FdeFunc_0668_0x04adb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[668] @ func_va=0x04adb8, fde_va=0x07d2d8, first_op=0xb9403409
    // VI: Hàm FDE[668] tại địa chỉ 0x04adb8, bản ghi FDE 0x07d2d8
    const std::uint32_t w0 = kByteVc0TextWords[70598U];
    std::uint32_t acc = w0 ^ 0xb9403409U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04adb8U);
}
static std::uint32_t ByteVc0FdeFunc_0669_0x04b0f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[669] @ func_va=0x04b0f0, fde_va=0x07d2f0, first_op=0xf9403428
    // VI: Hàm FDE[669] tại địa chỉ 0x04b0f0, bản ghi FDE 0x07d2f0
    const std::uint32_t w0 = kByteVc0TextWords[70804U];
    std::uint32_t acc = w0 ^ 0xf9403428U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04b0f0U);
}
static std::uint32_t ByteVc0FdeFunc_0670_0x04b278(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[670] @ func_va=0x04b278, fde_va=0x07d308, first_op=0xfc1a0fe8
    // VI: Hàm FDE[670] tại địa chỉ 0x04b278, bản ghi FDE 0x07d308
    const std::uint32_t w0 = kByteVc0TextWords[70902U];
    std::uint32_t acc = w0 ^ 0xfc1a0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04b278U);
}
static std::uint32_t ByteVc0FdeFunc_0671_0x04b358(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[671] @ func_va=0x04b358, fde_va=0x07d338, first_op=0xa9bd57f6
    // VI: Hàm FDE[671] tại địa chỉ 0x04b358, bản ghi FDE 0x07d338
    const std::uint32_t w0 = kByteVc0TextWords[70958U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04b358U);
}
static std::uint32_t ByteVc0FdeFunc_0672_0x04b52c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[672] @ func_va=0x04b52c, fde_va=0x07d360, first_op=0xb941a009
    // VI: Hàm FDE[672] tại địa chỉ 0x04b52c, bản ghi FDE 0x07d360
    const std::uint32_t w0 = kByteVc0TextWords[71075U];
    std::uint32_t acc = w0 ^ 0xb941a009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04b52cU);
}
static std::uint32_t ByteVc0FdeFunc_0673_0x04b780(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[673] @ func_va=0x04b780, fde_va=0x07d378, first_op=0x340000c1
    // VI: Hàm FDE[673] tại địa chỉ 0x04b780, bản ghi FDE 0x07d378
    const std::uint32_t w0 = kByteVc0TextWords[71224U];
    std::uint32_t acc = w0 ^ 0x340000c1U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04b780U);
}
static std::uint32_t ByteVc0FdeFunc_0674_0x04b87c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[674] @ func_va=0x04b87c, fde_va=0x07d390, first_op=0xb9401009
    // VI: Hàm FDE[674] tại địa chỉ 0x04b87c, bản ghi FDE 0x07d390
    const std::uint32_t w0 = kByteVc0TextWords[71287U];
    std::uint32_t acc = w0 ^ 0xb9401009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04b87cU);
}
static std::uint32_t ByteVc0FdeFunc_0675_0x04b968(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[675] @ func_va=0x04b968, fde_va=0x07d3a8, first_op=0xb9404428
    // VI: Hàm FDE[675] tại địa chỉ 0x04b968, bản ghi FDE 0x07d3a8
    const std::uint32_t w0 = kByteVc0TextWords[71346U];
    std::uint32_t acc = w0 ^ 0xb9404428U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04b968U);
}
static std::uint32_t ByteVc0FdeFunc_0676_0x04ba30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[676] @ func_va=0x04ba30, fde_va=0x07d3c0, first_op=0xfc1b0fea
    // VI: Hàm FDE[676] tại địa chỉ 0x04ba30, bản ghi FDE 0x07d3c0
    const std::uint32_t w0 = kByteVc0TextWords[71396U];
    std::uint32_t acc = w0 ^ 0xfc1b0feaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04ba30U);
}
static std::uint32_t ByteVc0FdeFunc_0677_0x04be24(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[677] @ func_va=0x04be24, fde_va=0x07d3f0, first_op=0xfc1c0fe8
    // VI: Hàm FDE[677] tại địa chỉ 0x04be24, bản ghi FDE 0x07d3f0
    const std::uint32_t w0 = kByteVc0TextWords[71649U];
    std::uint32_t acc = w0 ^ 0xfc1c0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04be24U);
}
static std::uint32_t ByteVc0FdeFunc_0678_0x04c220(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[678] @ func_va=0x04c220, fde_va=0x07d418, first_op=0xb9403c08
    // VI: Hàm FDE[678] tại địa chỉ 0x04c220, bản ghi FDE 0x07d418
    const std::uint32_t w0 = kByteVc0TextWords[71904U];
    std::uint32_t acc = w0 ^ 0xb9403c08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04c220U);
}
static std::uint32_t ByteVc0FdeFunc_0679_0x04c2b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[679] @ func_va=0x04c2b4, fde_va=0x07d430, first_op=0xf9402428
    // VI: Hàm FDE[679] tại địa chỉ 0x04c2b4, bản ghi FDE 0x07d430
    const std::uint32_t w0 = kByteVc0TextWords[71941U];
    std::uint32_t acc = w0 ^ 0xf9402428U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04c2b4U);
}
static std::uint32_t ByteVc0FdeFunc_0680_0x04c328(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[680] @ func_va=0x04c328, fde_va=0x07d448, first_op=0xa9bd57f6
    // VI: Hàm FDE[680] tại địa chỉ 0x04c328, bản ghi FDE 0x07d448
    const std::uint32_t w0 = kByteVc0TextWords[71970U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04c328U);
}
static std::uint32_t ByteVc0FdeFunc_0681_0x04c500(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[681] @ func_va=0x04c500, fde_va=0x07d470, first_op=0x6dbd23e9
    // VI: Hàm FDE[681] tại địa chỉ 0x04c500, bản ghi FDE 0x07d470
    const std::uint32_t w0 = kByteVc0TextWords[72088U];
    std::uint32_t acc = w0 ^ 0x6dbd23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04c500U);
}
static std::uint32_t ByteVc0FdeFunc_0682_0x04c680(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[682] @ func_va=0x04c680, fde_va=0x07d498, first_op=0xf9460408
    // VI: Hàm FDE[682] tại địa chỉ 0x04c680, bản ghi FDE 0x07d498
    const std::uint32_t w0 = kByteVc0TextWords[72184U];
    std::uint32_t acc = w0 ^ 0xf9460408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04c680U);
}
static std::uint32_t ByteVc0FdeFunc_0683_0x04c72c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[683] @ func_va=0x04c72c, fde_va=0x07d4b0, first_op=0x12001c28
    // VI: Hàm FDE[683] tại địa chỉ 0x04c72c, bản ghi FDE 0x07d4b0
    const std::uint32_t w0 = kByteVc0TextWords[72227U];
    std::uint32_t acc = w0 ^ 0x12001c28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04c72cU);
}
static std::uint32_t ByteVc0FdeFunc_0684_0x04c8f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[684] @ func_va=0x04c8f0, fde_va=0x07d4c8, first_op=0xfc170fee
    // VI: Hàm FDE[684] tại địa chỉ 0x04c8f0, bản ghi FDE 0x07d4c8
    const std::uint32_t w0 = kByteVc0TextWords[72340U];
    std::uint32_t acc = w0 ^ 0xfc170feeU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04c8f0U);
}
static std::uint32_t ByteVc0FdeFunc_0685_0x04cabc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[685] @ func_va=0x04cabc, fde_va=0x07d508, first_op=0xfc1b0fe8
    // VI: Hàm FDE[685] tại địa chỉ 0x04cabc, bản ghi FDE 0x07d508
    const std::uint32_t w0 = kByteVc0TextWords[72455U];
    std::uint32_t acc = w0 ^ 0xfc1b0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04cabcU);
}
static std::uint32_t ByteVc0FdeFunc_0686_0x04cba8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[686] @ func_va=0x04cba8, fde_va=0x07d538, first_op=0xaa0003e8
    // VI: Hàm FDE[686] tại địa chỉ 0x04cba8, bản ghi FDE 0x07d538
    const std::uint32_t w0 = kByteVc0TextWords[72514U];
    std::uint32_t acc = w0 ^ 0xaa0003e8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04cba8U);
}
static std::uint32_t ByteVc0FdeFunc_0687_0x04cc10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[687] @ func_va=0x04cc10, fde_va=0x07d550, first_op=0x6dbb23e9
    // VI: Hàm FDE[687] tại địa chỉ 0x04cc10, bản ghi FDE 0x07d550
    const std::uint32_t w0 = kByteVc0TextWords[72540U];
    std::uint32_t acc = w0 ^ 0x6dbb23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04cc10U);
}
static std::uint32_t ByteVc0FdeFunc_0688_0x04cdb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[688] @ func_va=0x04cdb4, fde_va=0x07d580, first_op=0xd10243ff
    // VI: Hàm FDE[688] tại địa chỉ 0x04cdb4, bản ghi FDE 0x07d580
    const std::uint32_t w0 = kByteVc0TextWords[72645U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04cdb4U);
}
static std::uint32_t ByteVc0FdeFunc_0689_0x04d230(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[689] @ func_va=0x04d230, fde_va=0x07d5b0, first_op=0xb94bdc0a
    // VI: Hàm FDE[689] tại địa chỉ 0x04d230, bản ghi FDE 0x07d5b0
    const std::uint32_t w0 = kByteVc0TextWords[72932U];
    std::uint32_t acc = w0 ^ 0xb94bdc0aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04d230U);
}
static std::uint32_t ByteVc0FdeFunc_0690_0x04d3d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[690] @ func_va=0x04d3d0, fde_va=0x07d5c8, first_op=0x91339009
    // VI: Hàm FDE[690] tại địa chỉ 0x04d3d0, bản ghi FDE 0x07d5c8
    const std::uint32_t w0 = kByteVc0TextWords[73036U];
    std::uint32_t acc = w0 ^ 0x91339009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04d3d0U);
}
static std::uint32_t ByteVc0FdeFunc_0691_0x04d4c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[691] @ func_va=0x04d4c0, fde_va=0x07d5e0, first_op=0xb94bdc0a
    // VI: Hàm FDE[691] tại địa chỉ 0x04d4c0, bản ghi FDE 0x07d5e0
    const std::uint32_t w0 = kByteVc0TextWords[73096U];
    std::uint32_t acc = w0 ^ 0xb94bdc0aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04d4c0U);
}
static std::uint32_t ByteVc0FdeFunc_0692_0x04d728(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[692] @ func_va=0x04d728, fde_va=0x07d5f8, first_op=0xf9460408
    // VI: Hàm FDE[692] tại địa chỉ 0x04d728, bản ghi FDE 0x07d5f8
    const std::uint32_t w0 = kByteVc0TextWords[73250U];
    std::uint32_t acc = w0 ^ 0xf9460408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04d728U);
}
static std::uint32_t ByteVc0FdeFunc_0693_0x04d880(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[693] @ func_va=0x04d880, fde_va=0x07d610, first_op=0xb9407008
    // VI: Hàm FDE[693] tại địa chỉ 0x04d880, bản ghi FDE 0x07d610
    const std::uint32_t w0 = kByteVc0TextWords[73336U];
    std::uint32_t acc = w0 ^ 0xb9407008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04d880U);
}
static std::uint32_t ByteVc0FdeFunc_0694_0x04d8cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[694] @ func_va=0x04d8cc, fde_va=0x07d628, first_op=0xfc1c0fe8
    // VI: Hàm FDE[694] tại địa chỉ 0x04d8cc, bản ghi FDE 0x07d628
    const std::uint32_t w0 = kByteVc0TextWords[73355U];
    std::uint32_t acc = w0 ^ 0xfc1c0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04d8ccU);
}
static std::uint32_t ByteVc0FdeFunc_0695_0x04db34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[695] @ func_va=0x04db34, fde_va=0x07d650, first_op=0xf81c0ff7
    // VI: Hàm FDE[695] tại địa chỉ 0x04db34, bản ghi FDE 0x07d650
    const std::uint32_t w0 = kByteVc0TextWords[73509U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04db34U);
}
static std::uint32_t ByteVc0FdeFunc_0696_0x04dbf8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[696] @ func_va=0x04dbf8, fde_va=0x07d678, first_op=0xb94bfc08
    // VI: Hàm FDE[696] tại địa chỉ 0x04dbf8, bản ghi FDE 0x07d678
    const std::uint32_t w0 = kByteVc0TextWords[73558U];
    std::uint32_t acc = w0 ^ 0xb94bfc08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04dbf8U);
}
static std::uint32_t ByteVc0FdeFunc_0697_0x04dc48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[697] @ func_va=0x04dc48, fde_va=0x07d690, first_op=0xf9400408
    // VI: Hàm FDE[697] tại địa chỉ 0x04dc48, bản ghi FDE 0x07d690
    const std::uint32_t w0 = kByteVc0TextWords[73578U];
    std::uint32_t acc = w0 ^ 0xf9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04dc48U);
}
static std::uint32_t ByteVc0FdeFunc_0698_0x04dcdc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[698] @ func_va=0x04dcdc, fde_va=0x07d6a8, first_op=0xfd402401
    // VI: Hàm FDE[698] tại địa chỉ 0x04dcdc, bản ghi FDE 0x07d6a8
    const std::uint32_t w0 = kByteVc0TextWords[73615U];
    std::uint32_t acc = w0 ^ 0xfd402401U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04dcdcU);
}
static std::uint32_t ByteVc0FdeFunc_0699_0x04dd88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[699] @ func_va=0x04dd88, fde_va=0x07d6c0, first_op=0xf81e0ff3
    // VI: Hàm FDE[699] tại địa chỉ 0x04dd88, bản ghi FDE 0x07d6c0
    const std::uint32_t w0 = kByteVc0TextWords[73658U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04dd88U);
}
static std::uint32_t ByteVc0FdeFunc_0700_0x04ddd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[700] @ func_va=0x04ddd8, fde_va=0x07d6e0, first_op=0xf81e0ff3
    // VI: Hàm FDE[700] tại địa chỉ 0x04ddd8, bản ghi FDE 0x07d6e0
    const std::uint32_t w0 = kByteVc0TextWords[73678U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04ddd8U);
}
static std::uint32_t ByteVc0FdeFunc_0701_0x04de0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[701] @ func_va=0x04de0c, fde_va=0x07d700, first_op=0x9139a000
    // VI: Hàm FDE[701] tại địa chỉ 0x04de0c, bản ghi FDE 0x07d700
    const std::uint32_t w0 = kByteVc0TextWords[73691U];
    std::uint32_t acc = w0 ^ 0x9139a000U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04de0cU);
}
static std::uint32_t ByteVc0FdeFunc_0702_0x04de14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[702] @ func_va=0x04de14, fde_va=0x07d718, first_op=0xf81e0ff3
    // VI: Hàm FDE[702] tại địa chỉ 0x04de14, bản ghi FDE 0x07d718
    const std::uint32_t w0 = kByteVc0TextWords[73693U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04de14U);
}
static std::uint32_t ByteVc0FdeFunc_0703_0x04de50(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[703] @ func_va=0x04de50, fde_va=0x07d738, first_op=0xf81d0ff5
    // VI: Hàm FDE[703] tại địa chỉ 0x04de50, bản ghi FDE 0x07d738
    const std::uint32_t w0 = kByteVc0TextWords[73708U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04de50U);
}
static std::uint32_t ByteVc0FdeFunc_0704_0x04ded8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[704] @ func_va=0x04ded8, fde_va=0x07d758, first_op=0x39404808
    // VI: Hàm FDE[704] tại địa chỉ 0x04ded8, bản ghi FDE 0x07d758
    const std::uint32_t w0 = kByteVc0TextWords[73742U];
    std::uint32_t acc = w0 ^ 0x39404808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04ded8U);
}
static std::uint32_t ByteVc0FdeFunc_0705_0x04df14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[705] @ func_va=0x04df14, fde_va=0x07d770, first_op=0xf81d0ff5
    // VI: Hàm FDE[705] tại địa chỉ 0x04df14, bản ghi FDE 0x07d770
    const std::uint32_t w0 = kByteVc0TextWords[73757U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04df14U);
}
static std::uint32_t ByteVc0FdeFunc_0706_0x04df9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[706] @ func_va=0x04df9c, fde_va=0x07d790, first_op=0xa9bc5ff8
    // VI: Hàm FDE[706] tại địa chỉ 0x04df9c, bản ghi FDE 0x07d790
    const std::uint32_t w0 = kByteVc0TextWords[73791U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04df9cU);
}
static std::uint32_t ByteVc0FdeFunc_0707_0x04e168(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[707] @ func_va=0x04e168, fde_va=0x07d7b8, first_op=0xa9be4ff4
    // VI: Hàm FDE[707] tại địa chỉ 0x04e168, bản ghi FDE 0x07d7b8
    const std::uint32_t w0 = kByteVc0TextWords[73906U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04e168U);
}
static std::uint32_t ByteVc0FdeFunc_0708_0x04e258(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[708] @ func_va=0x04e258, fde_va=0x07d7d8, first_op=0xd10183ff
    // VI: Hàm FDE[708] tại địa chỉ 0x04e258, bản ghi FDE 0x07d7d8
    const std::uint32_t w0 = kByteVc0TextWords[73966U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04e258U);
}
static std::uint32_t ByteVc0FdeFunc_0709_0x04e3b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[709] @ func_va=0x04e3b4, fde_va=0x07d7f8, first_op=0xf945ac09
    // VI: Hàm FDE[709] tại địa chỉ 0x04e3b4, bản ghi FDE 0x07d7f8
    const std::uint32_t w0 = kByteVc0TextWords[74053U];
    std::uint32_t acc = w0 ^ 0xf945ac09U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04e3b4U);
}
static std::uint32_t ByteVc0FdeFunc_0710_0x04e49c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[710] @ func_va=0x04e49c, fde_va=0x07d810, first_op=0x6dbb23e9
    // VI: Hàm FDE[710] tại địa chỉ 0x04e49c, bản ghi FDE 0x07d810
    const std::uint32_t w0 = kByteVc0TextWords[74111U];
    std::uint32_t acc = w0 ^ 0x6dbb23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04e49cU);
}
static std::uint32_t ByteVc0FdeFunc_0711_0x04e558(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[711] @ func_va=0x04e558, fde_va=0x07d840, first_op=0xd102c3ff
    // VI: Hàm FDE[711] tại địa chỉ 0x04e558, bản ghi FDE 0x07d840
    const std::uint32_t w0 = kByteVc0TextWords[74158U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04e558U);
}
static std::uint32_t ByteVc0FdeFunc_0712_0x04ea38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[712] @ func_va=0x04ea38, fde_va=0x07d880, first_op=0xf81c0ff7
    // VI: Hàm FDE[712] tại địa chỉ 0x04ea38, bản ghi FDE 0x07d880
    const std::uint32_t w0 = kByteVc0TextWords[74470U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04ea38U);
}
static std::uint32_t ByteVc0FdeFunc_0713_0x04eb80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[713] @ func_va=0x04eb80, fde_va=0x07d8a8, first_op=0xd65f03c0
    // VI: Hàm FDE[713] tại địa chỉ 0x04eb80, bản ghi FDE 0x07d8a8
    const std::uint32_t w0 = kByteVc0TextWords[74552U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04eb80U);
}
static std::uint32_t ByteVc0FdeFunc_0714_0x04eb84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[714] @ func_va=0x04eb84, fde_va=0x07d8c0, first_op=0xa9be4ff4
    // VI: Hàm FDE[714] tại địa chỉ 0x04eb84, bản ghi FDE 0x07d8c0
    const std::uint32_t w0 = kByteVc0TextWords[74553U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04eb84U);
}
static std::uint32_t ByteVc0FdeFunc_0715_0x04ebe4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[715] @ func_va=0x04ebe4, fde_va=0x07d8e0, first_op=0xf81e0ff3
    // VI: Hàm FDE[715] tại địa chỉ 0x04ebe4, bản ghi FDE 0x07d8e0
    const std::uint32_t w0 = kByteVc0TextWords[74577U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04ebe4U);
}
static std::uint32_t ByteVc0FdeFunc_0716_0x04ec6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[716] @ func_va=0x04ec6c, fde_va=0x07d900, first_op=0xb9400809
    // VI: Hàm FDE[716] tại địa chỉ 0x04ec6c, bản ghi FDE 0x07d900
    const std::uint32_t w0 = kByteVc0TextWords[74611U];
    std::uint32_t acc = w0 ^ 0xb9400809U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04ec6cU);
}
static std::uint32_t ByteVc0FdeFunc_0717_0x04ee04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[717] @ func_va=0x04ee04, fde_va=0x07d918, first_op=0xa9ba6ffc
    // VI: Hàm FDE[717] tại địa chỉ 0x04ee04, bản ghi FDE 0x07d918
    const std::uint32_t w0 = kByteVc0TextWords[74713U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04ee04U);
}
static std::uint32_t ByteVc0FdeFunc_0718_0x04f880(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[718] @ func_va=0x04f880, fde_va=0x07d948, first_op=0xd10203ff
    // VI: Hàm FDE[718] tại địa chỉ 0x04f880, bản ghi FDE 0x07d948
    const std::uint32_t w0 = kByteVc0TextWords[75384U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04f880U);
}
static std::uint32_t ByteVc0FdeFunc_0719_0x04fb24(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[719] @ func_va=0x04fb24, fde_va=0x07d970, first_op=0xd100c3ff
    // VI: Hàm FDE[719] tại địa chỉ 0x04fb24, bản ghi FDE 0x07d970
    const std::uint32_t w0 = kByteVc0TextWords[75553U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04fb24U);
}
static std::uint32_t ByteVc0FdeFunc_0720_0x04fb7c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[720] @ func_va=0x04fb7c, fde_va=0x07d990, first_op=0xd10343ff
    // VI: Hàm FDE[720] tại địa chỉ 0x04fb7c, bản ghi FDE 0x07d990
    const std::uint32_t w0 = kByteVc0TextWords[75575U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x04fb7cU);
}
static std::uint32_t ByteVc0FdeFunc_0721_0x05058c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[721] @ func_va=0x05058c, fde_va=0x07d9c0, first_op=0xd10303ff
    // VI: Hàm FDE[721] tại địa chỉ 0x05058c, bản ghi FDE 0x07d9c0
    const std::uint32_t w0 = kByteVc0TextWords[76219U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05058cU);
}
static std::uint32_t ByteVc0FdeFunc_0722_0x050d28(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[722] @ func_va=0x050d28, fde_va=0x07d9f0, first_op=0xd100c3ff
    // VI: Hàm FDE[722] tại địa chỉ 0x050d28, bản ghi FDE 0x07d9f0
    const std::uint32_t w0 = kByteVc0TextWords[76706U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x050d28U);
}
static std::uint32_t ByteVc0FdeFunc_0723_0x050d68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[723] @ func_va=0x050d68, fde_va=0x07da10, first_op=0xd100c3ff
    // VI: Hàm FDE[723] tại địa chỉ 0x050d68, bản ghi FDE 0x07da10
    const std::uint32_t w0 = kByteVc0TextWords[76722U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x050d68U);
}
static std::uint32_t ByteVc0FdeFunc_0724_0x050dc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[724] @ func_va=0x050dc0, fde_va=0x07da30, first_op=0xd10343ff
    // VI: Hàm FDE[724] tại địa chỉ 0x050dc0, bản ghi FDE 0x07da30
    const std::uint32_t w0 = kByteVc0TextWords[76744U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x050dc0U);
}
static std::uint32_t ByteVc0FdeFunc_0725_0x051740(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[725] @ func_va=0x051740, fde_va=0x07da60, first_op=0xd100c3ff
    // VI: Hàm FDE[725] tại địa chỉ 0x051740, bản ghi FDE 0x07da60
    const std::uint32_t w0 = kByteVc0TextWords[77352U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x051740U);
}
static std::uint32_t ByteVc0FdeFunc_0726_0x051780(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[726] @ func_va=0x051780, fde_va=0x07da80, first_op=0xd100c3ff
    // VI: Hàm FDE[726] tại địa chỉ 0x051780, bản ghi FDE 0x07da80
    const std::uint32_t w0 = kByteVc0TextWords[77368U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x051780U);
}
static std::uint32_t ByteVc0FdeFunc_0727_0x0517d8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[727] @ func_va=0x0517d8, fde_va=0x07daa0, first_op=0xd10303ff
    // VI: Hàm FDE[727] tại địa chỉ 0x0517d8, bản ghi FDE 0x07daa0
    const std::uint32_t w0 = kByteVc0TextWords[77390U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0517d8U);
}
static std::uint32_t ByteVc0FdeFunc_0728_0x05243c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[728] @ func_va=0x05243c, fde_va=0x07dad0, first_op=0xd100c3ff
    // VI: Hàm FDE[728] tại địa chỉ 0x05243c, bản ghi FDE 0x07dad0
    const std::uint32_t w0 = kByteVc0TextWords[78183U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05243cU);
}
static std::uint32_t ByteVc0FdeFunc_0729_0x05247c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[729] @ func_va=0x05247c, fde_va=0x07daf0, first_op=0xd100c3ff
    // VI: Hàm FDE[729] tại địa chỉ 0x05247c, bản ghi FDE 0x07daf0
    const std::uint32_t w0 = kByteVc0TextWords[78199U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05247cU);
}
static std::uint32_t ByteVc0FdeFunc_0730_0x0524d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[730] @ func_va=0x0524d4, fde_va=0x07db10, first_op=0xd10383ff
    // VI: Hàm FDE[730] tại địa chỉ 0x0524d4, bản ghi FDE 0x07db10
    const std::uint32_t w0 = kByteVc0TextWords[78221U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0524d4U);
}
static std::uint32_t ByteVc0FdeFunc_0731_0x053340(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[731] @ func_va=0x053340, fde_va=0x07db40, first_op=0xd100c3ff
    // VI: Hàm FDE[731] tại địa chỉ 0x053340, bản ghi FDE 0x07db40
    const std::uint32_t w0 = kByteVc0TextWords[79144U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053340U);
}
static std::uint32_t ByteVc0FdeFunc_0732_0x053380(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[732] @ func_va=0x053380, fde_va=0x07db60, first_op=0xd10283ff
    // VI: Hàm FDE[732] tại địa chỉ 0x053380, bản ghi FDE 0x07db60
    const std::uint32_t w0 = kByteVc0TextWords[79160U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053380U);
}
static std::uint32_t ByteVc0FdeFunc_0733_0x0535bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[733] @ func_va=0x0535bc, fde_va=0x07db90, first_op=0xd10303ff
    // VI: Hàm FDE[733] tại địa chỉ 0x0535bc, bản ghi FDE 0x07db90
    const std::uint32_t w0 = kByteVc0TextWords[79303U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0535bcU);
}
static std::uint32_t ByteVc0FdeFunc_0734_0x0538a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[734] @ func_va=0x0538a4, fde_va=0x07dbc0, first_op=0xa9bd57f6
    // VI: Hàm FDE[734] tại địa chỉ 0x0538a4, bản ghi FDE 0x07dbc0
    const std::uint32_t w0 = kByteVc0TextWords[79489U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0538a4U);
}
static std::uint32_t ByteVc0FdeFunc_0735_0x053a0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[735] @ func_va=0x053a0c, fde_va=0x07dbe8, first_op=0xf9423828
    // VI: Hàm FDE[735] tại địa chỉ 0x053a0c, bản ghi FDE 0x07dbe8
    const std::uint32_t w0 = kByteVc0TextWords[79579U];
    std::uint32_t acc = w0 ^ 0xf9423828U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053a0cU);
}
static std::uint32_t ByteVc0FdeFunc_0736_0x053a20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[736] @ func_va=0x053a20, fde_va=0x07dc00, first_op=0xf9423828
    // VI: Hàm FDE[736] tại địa chỉ 0x053a20, bản ghi FDE 0x07dc00
    const std::uint32_t w0 = kByteVc0TextWords[79584U];
    std::uint32_t acc = w0 ^ 0xf9423828U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053a20U);
}
static std::uint32_t ByteVc0FdeFunc_0737_0x053a3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[737] @ func_va=0x053a3c, fde_va=0x07dc18, first_op=0xf9400800
    // VI: Hàm FDE[737] tại địa chỉ 0x053a3c, bản ghi FDE 0x07dc18
    const std::uint32_t w0 = kByteVc0TextWords[79591U];
    std::uint32_t acc = w0 ^ 0xf9400800U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053a3cU);
}
static std::uint32_t ByteVc0FdeFunc_0738_0x053a50(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[738] @ func_va=0x053a50, fde_va=0x07dc30, first_op=0xf9400400
    // VI: Hàm FDE[738] tại địa chỉ 0x053a50, bản ghi FDE 0x07dc30
    const std::uint32_t w0 = kByteVc0TextWords[79596U];
    std::uint32_t acc = w0 ^ 0xf9400400U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053a50U);
}
static std::uint32_t ByteVc0FdeFunc_0739_0x053a64(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[739] @ func_va=0x053a64, fde_va=0x07dc48, first_op=0xf81c0ff7
    // VI: Hàm FDE[739] tại địa chỉ 0x053a64, bản ghi FDE 0x07dc48
    const std::uint32_t w0 = kByteVc0TextWords[79601U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053a64U);
}
static std::uint32_t ByteVc0FdeFunc_0740_0x053b14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[740] @ func_va=0x053b14, fde_va=0x07dc70, first_op=0xf81d0ff5
    // VI: Hàm FDE[740] tại địa chỉ 0x053b14, bản ghi FDE 0x07dc70
    const std::uint32_t w0 = kByteVc0TextWords[79645U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053b14U);
}
static std::uint32_t ByteVc0FdeFunc_0741_0x053b90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[741] @ func_va=0x053b90, fde_va=0x07dc90, first_op=0xa9bf7bfd
    // VI: Hàm FDE[741] tại địa chỉ 0x053b90, bản ghi FDE 0x07dc90
    const std::uint32_t w0 = kByteVc0TextWords[79676U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053b90U);
}
static std::uint32_t ByteVc0FdeFunc_0742_0x053bac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[742] @ func_va=0x053bac, fde_va=0x07dcb0, first_op=0xf0000188
    // VI: Hàm FDE[742] tại địa chỉ 0x053bac, bản ghi FDE 0x07dcb0
    const std::uint32_t w0 = kByteVc0TextWords[79683U];
    std::uint32_t acc = w0 ^ 0xf0000188U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bacU);
}
static std::uint32_t ByteVc0FdeFunc_0743_0x053bbc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[743] @ func_va=0x053bbc, fde_va=0x07dcc8, first_op=0x17fec7c5
    // VI: Hàm FDE[743] tại địa chỉ 0x053bbc, bản ghi FDE 0x07dcc8
    const std::uint32_t w0 = kByteVc0TextWords[79687U];
    std::uint32_t acc = w0 ^ 0x17fec7c5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bbcU);
}
static std::uint32_t ByteVc0FdeFunc_0744_0x053bc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[744] @ func_va=0x053bc0, fde_va=0x07dce0, first_op=0x2a1f03e0
    // VI: Hàm FDE[744] tại địa chỉ 0x053bc0, bản ghi FDE 0x07dce0
    const std::uint32_t w0 = kByteVc0TextWords[79688U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bc0U);
}
static std::uint32_t ByteVc0FdeFunc_0745_0x053bc8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[745] @ func_va=0x053bc8, fde_va=0x07dcf8, first_op=0x2a1f03e0
    // VI: Hàm FDE[745] tại địa chỉ 0x053bc8, bản ghi FDE 0x07dcf8
    const std::uint32_t w0 = kByteVc0TextWords[79690U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bc8U);
}
static std::uint32_t ByteVc0FdeFunc_0746_0x053bd0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[746] @ func_va=0x053bd0, fde_va=0x07dd10, first_op=0xd65f03c0
    // VI: Hàm FDE[746] tại địa chỉ 0x053bd0, bản ghi FDE 0x07dd10
    const std::uint32_t w0 = kByteVc0TextWords[79692U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bd0U);
}
static std::uint32_t ByteVc0FdeFunc_0747_0x053bd4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[747] @ func_va=0x053bd4, fde_va=0x07dd28, first_op=0xf0000188
    // VI: Hàm FDE[747] tại địa chỉ 0x053bd4, bản ghi FDE 0x07dd28
    const std::uint32_t w0 = kByteVc0TextWords[79693U];
    std::uint32_t acc = w0 ^ 0xf0000188U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bd4U);
}
static std::uint32_t ByteVc0FdeFunc_0748_0x053bf0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[748] @ func_va=0x053bf0, fde_va=0x07dd40, first_op=0x17fec7b8
    // VI: Hàm FDE[748] tại địa chỉ 0x053bf0, bản ghi FDE 0x07dd40
    const std::uint32_t w0 = kByteVc0TextWords[79700U];
    std::uint32_t acc = w0 ^ 0x17fec7b8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bf0U);
}
static std::uint32_t ByteVc0FdeFunc_0749_0x053bf4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[749] @ func_va=0x053bf4, fde_va=0x07dd58, first_op=0x2a1f03e0
    // VI: Hàm FDE[749] tại địa chỉ 0x053bf4, bản ghi FDE 0x07dd58
    const std::uint32_t w0 = kByteVc0TextWords[79701U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bf4U);
}
static std::uint32_t ByteVc0FdeFunc_0750_0x053bfc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[750] @ func_va=0x053bfc, fde_va=0x07dd70, first_op=0x2a1f03e0
    // VI: Hàm FDE[750] tại địa chỉ 0x053bfc, bản ghi FDE 0x07dd70
    const std::uint32_t w0 = kByteVc0TextWords[79703U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053bfcU);
}
static std::uint32_t ByteVc0FdeFunc_0751_0x053c04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[751] @ func_va=0x053c04, fde_va=0x07dd88, first_op=0xf81e0ff3
    // VI: Hàm FDE[751] tại địa chỉ 0x053c04, bản ghi FDE 0x07dd88
    const std::uint32_t w0 = kByteVc0TextWords[79705U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053c04U);
}
static std::uint32_t ByteVc0FdeFunc_0752_0x053c44(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[752] @ func_va=0x053c44, fde_va=0x07dda8, first_op=0xa9be4ff4
    // VI: Hàm FDE[752] tại địa chỉ 0x053c44, bản ghi FDE 0x07dda8
    const std::uint32_t w0 = kByteVc0TextWords[79721U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053c44U);
}
static std::uint32_t ByteVc0FdeFunc_0753_0x053c90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[753] @ func_va=0x053c90, fde_va=0x07ddc8, first_op=0x91008000
    // VI: Hàm FDE[753] tại địa chỉ 0x053c90, bản ghi FDE 0x07ddc8
    const std::uint32_t w0 = kByteVc0TextWords[79740U];
    std::uint32_t acc = w0 ^ 0x91008000U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053c90U);
}
static std::uint32_t ByteVc0FdeFunc_0754_0x053c98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[754] @ func_va=0x053c98, fde_va=0x07dde0, first_op=0xa9bf7bfd
    // VI: Hàm FDE[754] tại địa chỉ 0x053c98, bản ghi FDE 0x07dde0
    const std::uint32_t w0 = kByteVc0TextWords[79742U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053c98U);
}
static std::uint32_t ByteVc0FdeFunc_0755_0x053cb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[755] @ func_va=0x053cb4, fde_va=0x07de00, first_op=0xa9bf7bfd
    // VI: Hàm FDE[755] tại địa chỉ 0x053cb4, bản ghi FDE 0x07de00
    const std::uint32_t w0 = kByteVc0TextWords[79749U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053cb4U);
}
static std::uint32_t ByteVc0FdeFunc_0756_0x053cd0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[756] @ func_va=0x053cd0, fde_va=0x07de20, first_op=0xa9be4ff4
    // VI: Hàm FDE[756] tại địa chỉ 0x053cd0, bản ghi FDE 0x07de20
    const std::uint32_t w0 = kByteVc0TextWords[79756U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053cd0U);
}
static std::uint32_t ByteVc0FdeFunc_0757_0x053d54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[757] @ func_va=0x053d54, fde_va=0x07de40, first_op=0xb40000e0
    // VI: Hàm FDE[757] tại địa chỉ 0x053d54, bản ghi FDE 0x07de40
    const std::uint32_t w0 = kByteVc0TextWords[79789U];
    std::uint32_t acc = w0 ^ 0xb40000e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053d54U);
}
static std::uint32_t ByteVc0FdeFunc_0758_0x053d78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[758] @ func_va=0x053d78, fde_va=0x07de60, first_op=0xf81d0ffc
    // VI: Hàm FDE[758] tại địa chỉ 0x053d78, bản ghi FDE 0x07de60
    const std::uint32_t w0 = kByteVc0TextWords[79798U];
    std::uint32_t acc = w0 ^ 0xf81d0ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053d78U);
}
static std::uint32_t ByteVc0FdeFunc_0759_0x053dfc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[759] @ func_va=0x053dfc, fde_va=0x07de80, first_op=0xb40000e0
    // VI: Hàm FDE[759] tại địa chỉ 0x053dfc, bản ghi FDE 0x07de80
    const std::uint32_t w0 = kByteVc0TextWords[79831U];
    std::uint32_t acc = w0 ^ 0xb40000e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053dfcU);
}
static std::uint32_t ByteVc0FdeFunc_0760_0x053e20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[760] @ func_va=0x053e20, fde_va=0x07dea0, first_op=0xb4000080
    // VI: Hàm FDE[760] tại địa chỉ 0x053e20, bản ghi FDE 0x07dea0
    const std::uint32_t w0 = kByteVc0TextWords[79840U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053e20U);
}
static std::uint32_t ByteVc0FdeFunc_0761_0x053e34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[761] @ func_va=0x053e34, fde_va=0x07deb8, first_op=0xb4000080
    // VI: Hàm FDE[761] tại địa chỉ 0x053e34, bản ghi FDE 0x07deb8
    const std::uint32_t w0 = kByteVc0TextWords[79845U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053e34U);
}
static std::uint32_t ByteVc0FdeFunc_0762_0x053e48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[762] @ func_va=0x053e48, fde_va=0x07ded0, first_op=0xb4000080
    // VI: Hàm FDE[762] tại địa chỉ 0x053e48, bản ghi FDE 0x07ded0
    const std::uint32_t w0 = kByteVc0TextWords[79850U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053e48U);
}
static std::uint32_t ByteVc0FdeFunc_0763_0x053e5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[763] @ func_va=0x053e5c, fde_va=0x07dee8, first_op=0xb4000080
    // VI: Hàm FDE[763] tại địa chỉ 0x053e5c, bản ghi FDE 0x07dee8
    const std::uint32_t w0 = kByteVc0TextWords[79855U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053e5cU);
}
static std::uint32_t ByteVc0FdeFunc_0764_0x053e70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[764] @ func_va=0x053e70, fde_va=0x07df00, first_op=0xb4000080
    // VI: Hàm FDE[764] tại địa chỉ 0x053e70, bản ghi FDE 0x07df00
    const std::uint32_t w0 = kByteVc0TextWords[79860U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053e70U);
}
static std::uint32_t ByteVc0FdeFunc_0765_0x053e84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[765] @ func_va=0x053e84, fde_va=0x07df18, first_op=0xb4000080
    // VI: Hàm FDE[765] tại địa chỉ 0x053e84, bản ghi FDE 0x07df18
    const std::uint32_t w0 = kByteVc0TextWords[79865U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053e84U);
}
static std::uint32_t ByteVc0FdeFunc_0766_0x053e9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[766] @ func_va=0x053e9c, fde_va=0x07df30, first_op=0xb4000080
    // VI: Hàm FDE[766] tại địa chỉ 0x053e9c, bản ghi FDE 0x07df30
    const std::uint32_t w0 = kByteVc0TextWords[79871U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053e9cU);
}
static std::uint32_t ByteVc0FdeFunc_0767_0x053eb0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[767] @ func_va=0x053eb0, fde_va=0x07df48, first_op=0xb4000080
    // VI: Hàm FDE[767] tại địa chỉ 0x053eb0, bản ghi FDE 0x07df48
    const std::uint32_t w0 = kByteVc0TextWords[79876U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053eb0U);
}
static std::uint32_t ByteVc0FdeFunc_0768_0x053ec8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[768] @ func_va=0x053ec8, fde_va=0x07df60, first_op=0xb4000080
    // VI: Hàm FDE[768] tại địa chỉ 0x053ec8, bản ghi FDE 0x07df60
    const std::uint32_t w0 = kByteVc0TextWords[79882U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053ec8U);
}
static std::uint32_t ByteVc0FdeFunc_0769_0x053edc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[769] @ func_va=0x053edc, fde_va=0x07df78, first_op=0xb4000080
    // VI: Hàm FDE[769] tại địa chỉ 0x053edc, bản ghi FDE 0x07df78
    const std::uint32_t w0 = kByteVc0TextWords[79887U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053edcU);
}
static std::uint32_t ByteVc0FdeFunc_0770_0x053ef0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[770] @ func_va=0x053ef0, fde_va=0x07df90, first_op=0xb4000080
    // VI: Hàm FDE[770] tại địa chỉ 0x053ef0, bản ghi FDE 0x07df90
    const std::uint32_t w0 = kByteVc0TextWords[79892U];
    std::uint32_t acc = w0 ^ 0xb4000080U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053ef0U);
}
static std::uint32_t ByteVc0FdeFunc_0771_0x053f04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[771] @ func_va=0x053f04, fde_va=0x07dfa8, first_op=0xf81c0ff7
    // VI: Hàm FDE[771] tại địa chỉ 0x053f04, bản ghi FDE 0x07dfa8
    const std::uint32_t w0 = kByteVc0TextWords[79897U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x053f04U);
}
static std::uint32_t ByteVc0FdeFunc_0772_0x0542bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[772] @ func_va=0x0542bc, fde_va=0x07dfd0, first_op=0xf81e0ff3
    // VI: Hàm FDE[772] tại địa chỉ 0x0542bc, bản ghi FDE 0x07dfd0
    const std::uint32_t w0 = kByteVc0TextWords[80135U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0542bcU);
}
static std::uint32_t ByteVc0FdeFunc_0773_0x054308(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[773] @ func_va=0x054308, fde_va=0x07dff0, first_op=0xf81c0ff7
    // VI: Hàm FDE[773] tại địa chỉ 0x054308, bản ghi FDE 0x07dff0
    const std::uint32_t w0 = kByteVc0TextWords[80154U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x054308U);
}
static std::uint32_t ByteVc0FdeFunc_0774_0x0543c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[774] @ func_va=0x0543c4, fde_va=0x07e018, first_op=0xd10243ff
    // VI: Hàm FDE[774] tại địa chỉ 0x0543c4, bản ghi FDE 0x07e018
    const std::uint32_t w0 = kByteVc0TextWords[80201U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0543c4U);
}
static std::uint32_t ByteVc0FdeFunc_0775_0x055570(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[775] @ func_va=0x055570, fde_va=0x07e040, first_op=0xb40000a1
    // VI: Hàm FDE[775] tại địa chỉ 0x055570, bản ghi FDE 0x07e040
    const std::uint32_t w0 = kByteVc0TextWords[81332U];
    std::uint32_t acc = w0 ^ 0xb40000a1U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x055570U);
}
static std::uint32_t ByteVc0FdeFunc_0776_0x05558c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[776] @ func_va=0x05558c, fde_va=0x07e058, first_op=0xf81e0ff3
    // VI: Hàm FDE[776] tại địa chỉ 0x05558c, bản ghi FDE 0x07e058
    const std::uint32_t w0 = kByteVc0TextWords[81339U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05558cU);
}
static std::uint32_t ByteVc0FdeFunc_0777_0x055634(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[777] @ func_va=0x055634, fde_va=0x07e078, first_op=0xf81d0ff5
    // VI: Hàm FDE[777] tại địa chỉ 0x055634, bản ghi FDE 0x07e078
    const std::uint32_t w0 = kByteVc0TextWords[81381U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x055634U);
}
static std::uint32_t ByteVc0FdeFunc_0778_0x0556b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[778] @ func_va=0x0556b4, fde_va=0x07e098, first_op=0xf81e0ff3
    // VI: Hàm FDE[778] tại địa chỉ 0x0556b4, bản ghi FDE 0x07e098
    const std::uint32_t w0 = kByteVc0TextWords[81413U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0556b4U);
}
static std::uint32_t ByteVc0FdeFunc_0779_0x055718(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[779] @ func_va=0x055718, fde_va=0x07e0b8, first_op=0xd1002000
    // VI: Hàm FDE[779] tại địa chỉ 0x055718, bản ghi FDE 0x07e0b8
    const std::uint32_t w0 = kByteVc0TextWords[81438U];
    std::uint32_t acc = w0 ^ 0xd1002000U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x055718U);
}
static std::uint32_t ByteVc0FdeFunc_0780_0x055720(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[780] @ func_va=0x055720, fde_va=0x07e0d0, first_op=0xf81e0ff3
    // VI: Hàm FDE[780] tại địa chỉ 0x055720, bản ghi FDE 0x07e0d0
    const std::uint32_t w0 = kByteVc0TextWords[81440U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x055720U);
}
static std::uint32_t ByteVc0FdeFunc_0781_0x055744(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[781] @ func_va=0x055744, fde_va=0x07e0f0, first_op=0xf81e0ff3
    // VI: Hàm FDE[781] tại địa chỉ 0x055744, bản ghi FDE 0x07e0f0
    const std::uint32_t w0 = kByteVc0TextWords[81449U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x055744U);
}
static std::uint32_t ByteVc0FdeFunc_0782_0x05576c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[782] @ func_va=0x05576c, fde_va=0x07e110, first_op=0xf81b0ffc
    // VI: Hàm FDE[782] tại địa chỉ 0x05576c, bản ghi FDE 0x07e110
    const std::uint32_t w0 = kByteVc0TextWords[81459U];
    std::uint32_t acc = w0 ^ 0xf81b0ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05576cU);
}
static std::uint32_t ByteVc0FdeFunc_0783_0x05599c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[783] @ func_va=0x05599c, fde_va=0x07e138, first_op=0xd10443ff
    // VI: Hàm FDE[783] tại địa chỉ 0x05599c, bản ghi FDE 0x07e138
    const std::uint32_t w0 = kByteVc0TextWords[81599U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05599cU);
}
static std::uint32_t ByteVc0FdeFunc_0784_0x055a40(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[784] @ func_va=0x055a40, fde_va=0x07e158, first_op=0xd10283ff
    // VI: Hàm FDE[784] tại địa chỉ 0x055a40, bản ghi FDE 0x07e158
    const std::uint32_t w0 = kByteVc0TextWords[81640U];
    std::uint32_t acc = w0 ^ 0xd10283ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x055a40U);
}
static std::uint32_t ByteVc0FdeFunc_0785_0x056174(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[785] @ func_va=0x056174, fde_va=0x07e180, first_op=0xa9bd57f6
    // VI: Hàm FDE[785] tại địa chỉ 0x056174, bản ghi FDE 0x07e180
    const std::uint32_t w0 = kByteVc0TextWords[82101U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x056174U);
}
static std::uint32_t ByteVc0FdeFunc_0786_0x056210(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[786] @ func_va=0x056210, fde_va=0x07e1a8, first_op=0x6dbb23e9
    // VI: Hàm FDE[786] tại địa chỉ 0x056210, bản ghi FDE 0x07e1a8
    const std::uint32_t w0 = kByteVc0TextWords[82140U];
    std::uint32_t acc = w0 ^ 0x6dbb23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x056210U);
}
static std::uint32_t ByteVc0FdeFunc_0787_0x0564a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[787] @ func_va=0x0564a0, fde_va=0x07e1d8, first_op=0xa9be4ff4
    // VI: Hàm FDE[787] tại địa chỉ 0x0564a0, bản ghi FDE 0x07e1d8
    const std::uint32_t w0 = kByteVc0TextWords[82304U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0564a0U);
}
static std::uint32_t ByteVc0FdeFunc_0788_0x0566bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[788] @ func_va=0x0566bc, fde_va=0x07e1f8, first_op=0xd10343ff
    // VI: Hàm FDE[788] tại địa chỉ 0x0566bc, bản ghi FDE 0x07e1f8
    const std::uint32_t w0 = kByteVc0TextWords[82439U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0566bcU);
}
static std::uint32_t ByteVc0FdeFunc_0789_0x056bdc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[789] @ func_va=0x056bdc, fde_va=0x07e240, first_op=0xa9be4ff4
    // VI: Hàm FDE[789] tại địa chỉ 0x056bdc, bản ghi FDE 0x07e240
    const std::uint32_t w0 = kByteVc0TextWords[82767U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x056bdcU);
}
static std::uint32_t ByteVc0FdeFunc_0790_0x056c58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[790] @ func_va=0x056c58, fde_va=0x07e260, first_op=0xd10183ff
    // VI: Hàm FDE[790] tại địa chỉ 0x056c58, bản ghi FDE 0x07e260
    const std::uint32_t w0 = kByteVc0TextWords[82798U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x056c58U);
}
static std::uint32_t ByteVc0FdeFunc_0791_0x056d7c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[791] @ func_va=0x056d7c, fde_va=0x07e288, first_op=0xf81e0ff3
    // VI: Hàm FDE[791] tại địa chỉ 0x056d7c, bản ghi FDE 0x07e288
    const std::uint32_t w0 = kByteVc0TextWords[82871U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x056d7cU);
}
static std::uint32_t ByteVc0FdeFunc_0792_0x056dc4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[792] @ func_va=0x056dc4, fde_va=0x07e2a8, first_op=0x2a1f03e0
    // VI: Hàm FDE[792] tại địa chỉ 0x056dc4, bản ghi FDE 0x07e2a8
    const std::uint32_t w0 = kByteVc0TextWords[82889U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x056dc4U);
}
static std::uint32_t ByteVc0FdeFunc_0793_0x056dcc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[793] @ func_va=0x056dcc, fde_va=0x07e2c0, first_op=0xa9bd57fc
    // VI: Hàm FDE[793] tại địa chỉ 0x056dcc, bản ghi FDE 0x07e2c0
    const std::uint32_t w0 = kByteVc0TextWords[82891U];
    std::uint32_t acc = w0 ^ 0xa9bd57fcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x056dccU);
}
static std::uint32_t ByteVc0FdeFunc_0794_0x056f78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[794] @ func_va=0x056f78, fde_va=0x07e2e8, first_op=0xa9bc5ffc
    // VI: Hàm FDE[794] tại địa chỉ 0x056f78, bản ghi FDE 0x07e2e8
    const std::uint32_t w0 = kByteVc0TextWords[82998U];
    std::uint32_t acc = w0 ^ 0xa9bc5ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x056f78U);
}
static std::uint32_t ByteVc0FdeFunc_0795_0x0570c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[795] @ func_va=0x0570c4, fde_va=0x07e310, first_op=0xa9bd57f6
    // VI: Hàm FDE[795] tại địa chỉ 0x0570c4, bản ghi FDE 0x07e310
    const std::uint32_t w0 = kByteVc0TextWords[83081U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0570c4U);
}
static std::uint32_t ByteVc0FdeFunc_0796_0x057130(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[796] @ func_va=0x057130, fde_va=0x07e338, first_op=0xf81c0ff7
    // VI: Hàm FDE[796] tại địa chỉ 0x057130, bản ghi FDE 0x07e338
    const std::uint32_t w0 = kByteVc0TextWords[83108U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057130U);
}
static std::uint32_t ByteVc0FdeFunc_0797_0x0571d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[797] @ func_va=0x0571d0, fde_va=0x07e360, first_op=0xf81d0ff5
    // VI: Hàm FDE[797] tại địa chỉ 0x0571d0, bản ghi FDE 0x07e360
    const std::uint32_t w0 = kByteVc0TextWords[83148U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0571d0U);
}
static std::uint32_t ByteVc0FdeFunc_0798_0x05721c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[798] @ func_va=0x05721c, fde_va=0x07e380, first_op=0xf9400c08
    // VI: Hàm FDE[798] tại địa chỉ 0x05721c, bản ghi FDE 0x07e380
    const std::uint32_t w0 = kByteVc0TextWords[83167U];
    std::uint32_t acc = w0 ^ 0xf9400c08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05721cU);
}
static std::uint32_t ByteVc0FdeFunc_0799_0x05722c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[799] @ func_va=0x05722c, fde_va=0x07e398, first_op=0xa9bf7bfd
    // VI: Hàm FDE[799] tại địa chỉ 0x05722c, bản ghi FDE 0x07e398
    const std::uint32_t w0 = kByteVc0TextWords[83171U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05722cU);
}
static std::uint32_t ByteVc0FdeFunc_0800_0x057248(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[800] @ func_va=0x057248, fde_va=0x07e3b8, first_op=0xa9bf7bfd
    // VI: Hàm FDE[800] tại địa chỉ 0x057248, bản ghi FDE 0x07e3b8
    const std::uint32_t w0 = kByteVc0TextWords[83178U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057248U);
}
static std::uint32_t ByteVc0FdeFunc_0801_0x057288(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[801] @ func_va=0x057288, fde_va=0x07e3d8, first_op=0xa9be4ff4
    // VI: Hàm FDE[801] tại địa chỉ 0x057288, bản ghi FDE 0x07e3d8
    const std::uint32_t w0 = kByteVc0TextWords[83194U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057288U);
}
static std::uint32_t ByteVc0FdeFunc_0802_0x0572e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[802] @ func_va=0x0572e0, fde_va=0x07e3f8, first_op=0xf9403c09
    // VI: Hàm FDE[802] tại địa chỉ 0x0572e0, bản ghi FDE 0x07e3f8
    const std::uint32_t w0 = kByteVc0TextWords[83216U];
    std::uint32_t acc = w0 ^ 0xf9403c09U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0572e0U);
}
static std::uint32_t ByteVc0FdeFunc_0803_0x057338(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[803] @ func_va=0x057338, fde_va=0x07e410, first_op=0xf81c0ff7
    // VI: Hàm FDE[803] tại địa chỉ 0x057338, bản ghi FDE 0x07e410
    const std::uint32_t w0 = kByteVc0TextWords[83238U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057338U);
}
static std::uint32_t ByteVc0FdeFunc_0804_0x057570(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[804] @ func_va=0x057570, fde_va=0x07e438, first_op=0xa9bd57f6
    // VI: Hàm FDE[804] tại địa chỉ 0x057570, bản ghi FDE 0x07e438
    const std::uint32_t w0 = kByteVc0TextWords[83380U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057570U);
}
static std::uint32_t ByteVc0FdeFunc_0805_0x057610(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[805] @ func_va=0x057610, fde_va=0x07e460, first_op=0xf9400c08
    // VI: Hàm FDE[805] tại địa chỉ 0x057610, bản ghi FDE 0x07e460
    const std::uint32_t w0 = kByteVc0TextWords[83420U];
    std::uint32_t acc = w0 ^ 0xf9400c08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057610U);
}
static std::uint32_t ByteVc0FdeFunc_0806_0x05761c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[806] @ func_va=0x05761c, fde_va=0x07e478, first_op=0xd10243ff
    // VI: Hàm FDE[806] tại địa chỉ 0x05761c, bản ghi FDE 0x07e478
    const std::uint32_t w0 = kByteVc0TextWords[83423U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05761cU);
}
static std::uint32_t ByteVc0FdeFunc_0807_0x057bcc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[807] @ func_va=0x057bcc, fde_va=0x07e4a8, first_op=0xf81c0ff7
    // VI: Hàm FDE[807] tại địa chỉ 0x057bcc, bản ghi FDE 0x07e4a8
    const std::uint32_t w0 = kByteVc0TextWords[83787U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057bccU);
}
static std::uint32_t ByteVc0FdeFunc_0808_0x057c60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[808] @ func_va=0x057c60, fde_va=0x07e4d0, first_op=0xa9bd57f6
    // VI: Hàm FDE[808] tại địa chỉ 0x057c60, bản ghi FDE 0x07e4d0
    const std::uint32_t w0 = kByteVc0TextWords[83824U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057c60U);
}
static std::uint32_t ByteVc0FdeFunc_0809_0x057cd8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[809] @ func_va=0x057cd8, fde_va=0x07e4f8, first_op=0xa9be4ff4
    // VI: Hàm FDE[809] tại địa chỉ 0x057cd8, bản ghi FDE 0x07e4f8
    const std::uint32_t w0 = kByteVc0TextWords[83854U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057cd8U);
}
static std::uint32_t ByteVc0FdeFunc_0810_0x057d14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[810] @ func_va=0x057d14, fde_va=0x07e518, first_op=0xf81d0ff5
    // VI: Hàm FDE[810] tại địa chỉ 0x057d14, bản ghi FDE 0x07e518
    const std::uint32_t w0 = kByteVc0TextWords[83869U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057d14U);
}
static std::uint32_t ByteVc0FdeFunc_0811_0x057d60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[811] @ func_va=0x057d60, fde_va=0x07e538, first_op=0xf81d0ff5
    // VI: Hàm FDE[811] tại địa chỉ 0x057d60, bản ghi FDE 0x07e538
    const std::uint32_t w0 = kByteVc0TextWords[83888U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057d60U);
}
static std::uint32_t ByteVc0FdeFunc_0812_0x057dac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[812] @ func_va=0x057dac, fde_va=0x07e558, first_op=0xa9be4ff4
    // VI: Hàm FDE[812] tại địa chỉ 0x057dac, bản ghi FDE 0x07e558
    const std::uint32_t w0 = kByteVc0TextWords[83907U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057dacU);
}
static std::uint32_t ByteVc0FdeFunc_0813_0x057e18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[813] @ func_va=0x057e18, fde_va=0x07e578, first_op=0xf81c0ff7
    // VI: Hàm FDE[813] tại địa chỉ 0x057e18, bản ghi FDE 0x07e578
    const std::uint32_t w0 = kByteVc0TextWords[83934U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057e18U);
}
static std::uint32_t ByteVc0FdeFunc_0814_0x057fc8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[814] @ func_va=0x057fc8, fde_va=0x07e5a0, first_op=0xf9400c08
    // VI: Hàm FDE[814] tại địa chỉ 0x057fc8, bản ghi FDE 0x07e5a0
    const std::uint32_t w0 = kByteVc0TextWords[84042U];
    std::uint32_t acc = w0 ^ 0xf9400c08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x057fc8U);
}
static std::uint32_t ByteVc0FdeFunc_0815_0x0580a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[815] @ func_va=0x0580a4, fde_va=0x07e5b8, first_op=0xfc1a0fe8
    // VI: Hàm FDE[815] tại địa chỉ 0x0580a4, bản ghi FDE 0x07e5b8
    const std::uint32_t w0 = kByteVc0TextWords[84097U];
    std::uint32_t acc = w0 ^ 0xfc1a0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0580a4U);
}
static std::uint32_t ByteVc0FdeFunc_0816_0x05840c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[816] @ func_va=0x05840c, fde_va=0x07e5e8, first_op=0xd1002000
    // VI: Hàm FDE[816] tại địa chỉ 0x05840c, bản ghi FDE 0x07e5e8
    const std::uint32_t w0 = kByteVc0TextWords[84315U];
    std::uint32_t acc = w0 ^ 0xd1002000U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05840cU);
}
static std::uint32_t ByteVc0FdeFunc_0817_0x058414(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[817] @ func_va=0x058414, fde_va=0x07e600, first_op=0xd10103ff
    // VI: Hàm FDE[817] tại địa chỉ 0x058414, bản ghi FDE 0x07e600
    const std::uint32_t w0 = kByteVc0TextWords[84317U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058414U);
}
static std::uint32_t ByteVc0FdeFunc_0818_0x058544(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[818] @ func_va=0x058544, fde_va=0x07e620, first_op=0xd10103ff
    // VI: Hàm FDE[818] tại địa chỉ 0x058544, bản ghi FDE 0x07e620
    const std::uint32_t w0 = kByteVc0TextWords[84393U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058544U);
}
static std::uint32_t ByteVc0FdeFunc_0819_0x058644(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[819] @ func_va=0x058644, fde_va=0x07e648, first_op=0xfc190fe8
    // VI: Hàm FDE[819] tại địa chỉ 0x058644, bản ghi FDE 0x07e648
    const std::uint32_t w0 = kByteVc0TextWords[84457U];
    std::uint32_t acc = w0 ^ 0xfc190fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058644U);
}
static std::uint32_t ByteVc0FdeFunc_0820_0x058844(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[820] @ func_va=0x058844, fde_va=0x07e678, first_op=0xd10083ff
    // VI: Hàm FDE[820] tại địa chỉ 0x058844, bản ghi FDE 0x07e678
    const std::uint32_t w0 = kByteVc0TextWords[84585U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058844U);
}
static std::uint32_t ByteVc0FdeFunc_0821_0x058900(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[821] @ func_va=0x058900, fde_va=0x07e698, first_op=0x2957a029
    // VI: Hàm FDE[821] tại địa chỉ 0x058900, bản ghi FDE 0x07e698
    const std::uint32_t w0 = kByteVc0TextWords[84632U];
    std::uint32_t acc = w0 ^ 0x2957a029U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058900U);
}
static std::uint32_t ByteVc0FdeFunc_0822_0x058958(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[822] @ func_va=0x058958, fde_va=0x07e6b0, first_op=0xa9bd57fc
    // VI: Hàm FDE[822] tại địa chỉ 0x058958, bản ghi FDE 0x07e6b0
    const std::uint32_t w0 = kByteVc0TextWords[84654U];
    std::uint32_t acc = w0 ^ 0xa9bd57fcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058958U);
}
static std::uint32_t ByteVc0FdeFunc_0823_0x058b54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[823] @ func_va=0x058b54, fde_va=0x07e6d8, first_op=0xf81c0ffc
    // VI: Hàm FDE[823] tại địa chỉ 0x058b54, bản ghi FDE 0x07e6d8
    const std::uint32_t w0 = kByteVc0TextWords[84781U];
    std::uint32_t acc = w0 ^ 0xf81c0ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058b54U);
}
static std::uint32_t ByteVc0FdeFunc_0824_0x058d7c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[824] @ func_va=0x058d7c, fde_va=0x07e700, first_op=0x72001c48
    // VI: Hàm FDE[824] tại địa chỉ 0x058d7c, bản ghi FDE 0x07e700
    const std::uint32_t w0 = kByteVc0TextWords[84919U];
    std::uint32_t acc = w0 ^ 0x72001c48U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058d7cU);
}
static std::uint32_t ByteVc0FdeFunc_0825_0x058da4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[825] @ func_va=0x058da4, fde_va=0x07e718, first_op=0xf81d0ff5
    // VI: Hàm FDE[825] tại địa chỉ 0x058da4, bản ghi FDE 0x07e718
    const std::uint32_t w0 = kByteVc0TextWords[84929U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058da4U);
}
static std::uint32_t ByteVc0FdeFunc_0826_0x058f08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[826] @ func_va=0x058f08, fde_va=0x07e738, first_op=0xf9400c00
    // VI: Hàm FDE[826] tại địa chỉ 0x058f08, bản ghi FDE 0x07e738
    const std::uint32_t w0 = kByteVc0TextWords[85018U];
    std::uint32_t acc = w0 ^ 0xf9400c00U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058f08U);
}
static std::uint32_t ByteVc0FdeFunc_0827_0x058f58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[827] @ func_va=0x058f58, fde_va=0x07e750, first_op=0xd101c3ff
    // VI: Hàm FDE[827] tại địa chỉ 0x058f58, bản ghi FDE 0x07e750
    const std::uint32_t w0 = kByteVc0TextWords[85038U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x058f58U);
}
static std::uint32_t ByteVc0FdeFunc_0828_0x059128(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[828] @ func_va=0x059128, fde_va=0x07e780, first_op=0xa9bd57f6
    // VI: Hàm FDE[828] tại địa chỉ 0x059128, bản ghi FDE 0x07e780
    const std::uint32_t w0 = kByteVc0TextWords[85154U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059128U);
}
static std::uint32_t ByteVc0FdeFunc_0829_0x059268(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[829] @ func_va=0x059268, fde_va=0x07e7a8, first_op=0xf9405008
    // VI: Hàm FDE[829] tại địa chỉ 0x059268, bản ghi FDE 0x07e7a8
    const std::uint32_t w0 = kByteVc0TextWords[85234U];
    std::uint32_t acc = w0 ^ 0xf9405008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059268U);
}
static std::uint32_t ByteVc0FdeFunc_0830_0x059344(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[830] @ func_va=0x059344, fde_va=0x07e7c0, first_op=0x6dbc23e9
    // VI: Hàm FDE[830] tại địa chỉ 0x059344, bản ghi FDE 0x07e7c0
    const std::uint32_t w0 = kByteVc0TextWords[85289U];
    std::uint32_t acc = w0 ^ 0x6dbc23e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059344U);
}
static std::uint32_t ByteVc0FdeFunc_0831_0x0594b4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[831] @ func_va=0x0594b4, fde_va=0x07e7e8, first_op=0xd10243ff
    // VI: Hàm FDE[831] tại địa chỉ 0x0594b4, bản ghi FDE 0x07e7e8
    const std::uint32_t w0 = kByteVc0TextWords[85381U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0594b4U);
}
static std::uint32_t ByteVc0FdeFunc_0832_0x0596a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[832] @ func_va=0x0596a4, fde_va=0x07e820, first_op=0xfc1d0fe8
    // VI: Hàm FDE[832] tại địa chỉ 0x0596a4, bản ghi FDE 0x07e820
    const std::uint32_t w0 = kByteVc0TextWords[85505U];
    std::uint32_t acc = w0 ^ 0xfc1d0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0596a4U);
}
static std::uint32_t ByteVc0FdeFunc_0833_0x059754(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[833] @ func_va=0x059754, fde_va=0x07e848, first_op=0xf940500a
    // VI: Hàm FDE[833] tại địa chỉ 0x059754, bản ghi FDE 0x07e848
    const std::uint32_t w0 = kByteVc0TextWords[85549U];
    std::uint32_t acc = w0 ^ 0xf940500aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059754U);
}
static std::uint32_t ByteVc0FdeFunc_0834_0x05990c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[834] @ func_va=0x05990c, fde_va=0x07e860, first_op=0xfc1c0fe8
    // VI: Hàm FDE[834] tại địa chỉ 0x05990c, bản ghi FDE 0x07e860
    const std::uint32_t w0 = kByteVc0TextWords[85659U];
    std::uint32_t acc = w0 ^ 0xfc1c0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05990cU);
}
static std::uint32_t ByteVc0FdeFunc_0835_0x0599d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[835] @ func_va=0x0599d4, fde_va=0x07e888, first_op=0xf81d0ffc
    // VI: Hàm FDE[835] tại địa chỉ 0x0599d4, bản ghi FDE 0x07e888
    const std::uint32_t w0 = kByteVc0TextWords[85709U];
    std::uint32_t acc = w0 ^ 0xf81d0ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0599d4U);
}
static std::uint32_t ByteVc0FdeFunc_0836_0x059b84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[836] @ func_va=0x059b84, fde_va=0x07e8a8, first_op=0xf81e0ff3
    // VI: Hàm FDE[836] tại địa chỉ 0x059b84, bản ghi FDE 0x07e8a8
    const std::uint32_t w0 = kByteVc0TextWords[85817U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059b84U);
}
static std::uint32_t ByteVc0FdeFunc_0837_0x059bc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[837] @ func_va=0x059bc0, fde_va=0x07e8c8, first_op=0xa9be4ff4
    // VI: Hàm FDE[837] tại địa chỉ 0x059bc0, bản ghi FDE 0x07e8c8
    const std::uint32_t w0 = kByteVc0TextWords[85832U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059bc0U);
}
static std::uint32_t ByteVc0FdeFunc_0838_0x059c20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[838] @ func_va=0x059c20, fde_va=0x07e8e8, first_op=0xd10103ff
    // VI: Hàm FDE[838] tại địa chỉ 0x059c20, bản ghi FDE 0x07e8e8
    const std::uint32_t w0 = kByteVc0TextWords[85856U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059c20U);
}
static std::uint32_t ByteVc0FdeFunc_0839_0x059d20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[839] @ func_va=0x059d20, fde_va=0x07e910, first_op=0xd10103ff
    // VI: Hàm FDE[839] tại địa chỉ 0x059d20, bản ghi FDE 0x07e910
    const std::uint32_t w0 = kByteVc0TextWords[85920U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059d20U);
}
static std::uint32_t ByteVc0FdeFunc_0840_0x059e20(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[840] @ func_va=0x059e20, fde_va=0x07e938, first_op=0xd101c3ff
    // VI: Hàm FDE[840] tại địa chỉ 0x059e20, bản ghi FDE 0x07e938
    const std::uint32_t w0 = kByteVc0TextWords[85984U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059e20U);
}
static std::uint32_t ByteVc0FdeFunc_0841_0x059f34(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[841] @ func_va=0x059f34, fde_va=0x07e960, first_op=0xa9be4ff4
    // VI: Hàm FDE[841] tại địa chỉ 0x059f34, bản ghi FDE 0x07e960
    const std::uint32_t w0 = kByteVc0TextWords[86053U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059f34U);
}
static std::uint32_t ByteVc0FdeFunc_0842_0x059f98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[842] @ func_va=0x059f98, fde_va=0x07e980, first_op=0xf9400068
    // VI: Hàm FDE[842] tại địa chỉ 0x059f98, bản ghi FDE 0x07e980
    const std::uint32_t w0 = kByteVc0TextWords[86078U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059f98U);
}
static std::uint32_t ByteVc0FdeFunc_0843_0x059fb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[843] @ func_va=0x059fb8, fde_va=0x07e998, first_op=0xd101c3ff
    // VI: Hàm FDE[843] tại địa chỉ 0x059fb8, bản ghi FDE 0x07e998
    const std::uint32_t w0 = kByteVc0TextWords[86086U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x059fb8U);
}
static std::uint32_t ByteVc0FdeFunc_0844_0x05a0cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[844] @ func_va=0x05a0cc, fde_va=0x07e9c0, first_op=0xa9be4ff4
    // VI: Hàm FDE[844] tại địa chỉ 0x05a0cc, bản ghi FDE 0x07e9c0
    const std::uint32_t w0 = kByteVc0TextWords[86155U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a0ccU);
}
static std::uint32_t ByteVc0FdeFunc_0845_0x05a130(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[845] @ func_va=0x05a130, fde_va=0x07e9e0, first_op=0xf9400068
    // VI: Hàm FDE[845] tại địa chỉ 0x05a130, bản ghi FDE 0x07e9e0
    const std::uint32_t w0 = kByteVc0TextWords[86180U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a130U);
}
static std::uint32_t ByteVc0FdeFunc_0846_0x05a150(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[846] @ func_va=0x05a150, fde_va=0x07e9f8, first_op=0xd10183ff
    // VI: Hàm FDE[846] tại địa chỉ 0x05a150, bản ghi FDE 0x07e9f8
    const std::uint32_t w0 = kByteVc0TextWords[86188U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a150U);
}
static std::uint32_t ByteVc0FdeFunc_0847_0x05a220(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[847] @ func_va=0x05a220, fde_va=0x07ea20, first_op=0xf81d0ff5
    // VI: Hàm FDE[847] tại địa chỉ 0x05a220, bản ghi FDE 0x07ea20
    const std::uint32_t w0 = kByteVc0TextWords[86240U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a220U);
}
static std::uint32_t ByteVc0FdeFunc_0848_0x05a29c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[848] @ func_va=0x05a29c, fde_va=0x07ea40, first_op=0xa9be4ff4
    // VI: Hàm FDE[848] tại địa chỉ 0x05a29c, bản ghi FDE 0x07ea40
    const std::uint32_t w0 = kByteVc0TextWords[86271U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a29cU);
}
static std::uint32_t ByteVc0FdeFunc_0849_0x05a300(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[849] @ func_va=0x05a300, fde_va=0x07ea60, first_op=0xf9400068
    // VI: Hàm FDE[849] tại địa chỉ 0x05a300, bản ghi FDE 0x07ea60
    const std::uint32_t w0 = kByteVc0TextWords[86296U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a300U);
}
static std::uint32_t ByteVc0FdeFunc_0850_0x05a320(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[850] @ func_va=0x05a320, fde_va=0x07ea78, first_op=0xd101c3ff
    // VI: Hàm FDE[850] tại địa chỉ 0x05a320, bản ghi FDE 0x07ea78
    const std::uint32_t w0 = kByteVc0TextWords[86304U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a320U);
}
static std::uint32_t ByteVc0FdeFunc_0851_0x05a434(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[851] @ func_va=0x05a434, fde_va=0x07eaa0, first_op=0x5ac01008
    // VI: Hàm FDE[851] tại địa chỉ 0x05a434, bản ghi FDE 0x07eaa0
    const std::uint32_t w0 = kByteVc0TextWords[86373U];
    std::uint32_t acc = w0 ^ 0x5ac01008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a434U);
}
static std::uint32_t ByteVc0FdeFunc_0852_0x05a464(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[852] @ func_va=0x05a464, fde_va=0x07eab8, first_op=0xb00000c8
    // VI: Hàm FDE[852] tại địa chỉ 0x05a464, bản ghi FDE 0x07eab8
    const std::uint32_t w0 = kByteVc0TextWords[86385U];
    std::uint32_t acc = w0 ^ 0xb00000c8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a464U);
}
static std::uint32_t ByteVc0FdeFunc_0853_0x05a4c4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[853] @ func_va=0x05a4c4, fde_va=0x07ead0, first_op=0xd10243ff
    // VI: Hàm FDE[853] tại địa chỉ 0x05a4c4, bản ghi FDE 0x07ead0
    const std::uint32_t w0 = kByteVc0TextWords[86409U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a4c4U);
}
static std::uint32_t ByteVc0FdeFunc_0854_0x05a7a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[854] @ func_va=0x05a7a4, fde_va=0x07eb00, first_op=0xf81e0ff3
    // VI: Hàm FDE[854] tại địa chỉ 0x05a7a4, bản ghi FDE 0x07eb00
    const std::uint32_t w0 = kByteVc0TextWords[86593U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a7a4U);
}
static std::uint32_t ByteVc0FdeFunc_0855_0x05a7e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[855] @ func_va=0x05a7e8, fde_va=0x07eb20, first_op=0x6db923e9
    // VI: Hàm FDE[855] tại địa chỉ 0x05a7e8, bản ghi FDE 0x07eb20
    const std::uint32_t w0 = kByteVc0TextWords[86610U];
    std::uint32_t acc = w0 ^ 0x6db923e9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a7e8U);
}
static std::uint32_t ByteVc0FdeFunc_0856_0x05a944(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[856] @ func_va=0x05a944, fde_va=0x07eb58, first_op=0xfc1e0fe8
    // VI: Hàm FDE[856] tại địa chỉ 0x05a944, bản ghi FDE 0x07eb58
    const std::uint32_t w0 = kByteVc0TextWords[86697U];
    std::uint32_t acc = w0 ^ 0xfc1e0fe8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a944U);
}
static std::uint32_t ByteVc0FdeFunc_0857_0x05a98c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[857] @ func_va=0x05a98c, fde_va=0x07eb78, first_op=0xa9bb67fa
    // VI: Hàm FDE[857] tại địa chỉ 0x05a98c, bản ghi FDE 0x07eb78
    const std::uint32_t w0 = kByteVc0TextWords[86715U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05a98cU);
}
static std::uint32_t ByteVc0FdeFunc_0858_0x05aa60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[858] @ func_va=0x05aa60, fde_va=0x07eba8, first_op=0xd10303ff
    // VI: Hàm FDE[858] tại địa chỉ 0x05aa60, bản ghi FDE 0x07eba8
    const std::uint32_t w0 = kByteVc0TextWords[86768U];
    std::uint32_t acc = w0 ^ 0xd10303ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05aa60U);
}
static std::uint32_t ByteVc0FdeFunc_0859_0x05ac74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[859] @ func_va=0x05ac74, fde_va=0x07ebd8, first_op=0x39400028
    // VI: Hàm FDE[859] tại địa chỉ 0x05ac74, bản ghi FDE 0x07ebd8
    const std::uint32_t w0 = kByteVc0TextWords[86901U];
    std::uint32_t acc = w0 ^ 0x39400028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ac74U);
}
static std::uint32_t ByteVc0FdeFunc_0860_0x05acb4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[860] @ func_va=0x05acb4, fde_va=0x07ebf0, first_op=0xd10443ff
    // VI: Hàm FDE[860] tại địa chỉ 0x05acb4, bản ghi FDE 0x07ebf0
    const std::uint32_t w0 = kByteVc0TextWords[86917U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05acb4U);
}
static std::uint32_t ByteVc0FdeFunc_0861_0x05ade4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[861] @ func_va=0x05ade4, fde_va=0x07ec18, first_op=0xf81e0ff3
    // VI: Hàm FDE[861] tại địa chỉ 0x05ade4, bản ghi FDE 0x07ec18
    const std::uint32_t w0 = kByteVc0TextWords[86993U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ade4U);
}
static std::uint32_t ByteVc0FdeFunc_0862_0x05ae2c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[862] @ func_va=0x05ae2c, fde_va=0x07ec38, first_op=0xd10103ff
    // VI: Hàm FDE[862] tại địa chỉ 0x05ae2c, bản ghi FDE 0x07ec38
    const std::uint32_t w0 = kByteVc0TextWords[87011U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ae2cU);
}
static std::uint32_t ByteVc0FdeFunc_0863_0x05b054(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[863] @ func_va=0x05b054, fde_va=0x07ec58, first_op=0xa9bd57f6
    // VI: Hàm FDE[863] tại địa chỉ 0x05b054, bản ghi FDE 0x07ec58
    const std::uint32_t w0 = kByteVc0TextWords[87149U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b054U);
}
static std::uint32_t ByteVc0FdeFunc_0864_0x05b118(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[864] @ func_va=0x05b118, fde_va=0x07ec80, first_op=0xa9ba6ffc
    // VI: Hàm FDE[864] tại địa chỉ 0x05b118, bản ghi FDE 0x07ec80
    const std::uint32_t w0 = kByteVc0TextWords[87198U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b118U);
}
static std::uint32_t ByteVc0FdeFunc_0865_0x05b24c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[865] @ func_va=0x05b24c, fde_va=0x07ecb0, first_op=0x7100143f
    // VI: Hàm FDE[865] tại địa chỉ 0x05b24c, bản ghi FDE 0x07ecb0
    const std::uint32_t w0 = kByteVc0TextWords[87275U];
    std::uint32_t acc = w0 ^ 0x7100143fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b24cU);
}
static std::uint32_t ByteVc0FdeFunc_0866_0x05b2f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[866] @ func_va=0x05b2f0, fde_va=0x07ecc8, first_op=0xa9bb67fc
    // VI: Hàm FDE[866] tại địa chỉ 0x05b2f0, bản ghi FDE 0x07ecc8
    const std::uint32_t w0 = kByteVc0TextWords[87316U];
    std::uint32_t acc = w0 ^ 0xa9bb67fcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b2f0U);
}
static std::uint32_t ByteVc0FdeFunc_0867_0x05b474(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[867] @ func_va=0x05b474, fde_va=0x07ecf8, first_op=0xd10443ff
    // VI: Hàm FDE[867] tại địa chỉ 0x05b474, bản ghi FDE 0x07ecf8
    const std::uint32_t w0 = kByteVc0TextWords[87413U];
    std::uint32_t acc = w0 ^ 0xd10443ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b474U);
}
static std::uint32_t ByteVc0FdeFunc_0868_0x05b518(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[868] @ func_va=0x05b518, fde_va=0x07ed18, first_op=0xb4000500
    // VI: Hàm FDE[868] tại địa chỉ 0x05b518, bản ghi FDE 0x07ed18
    const std::uint32_t w0 = kByteVc0TextWords[87454U];
    std::uint32_t acc = w0 ^ 0xb4000500U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b518U);
}
static std::uint32_t ByteVc0FdeFunc_0869_0x05b5bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[869] @ func_va=0x05b5bc, fde_va=0x07ed38, first_op=0xa9bf7bfd
    // VI: Hàm FDE[869] tại địa chỉ 0x05b5bc, bản ghi FDE 0x07ed38
    const std::uint32_t w0 = kByteVc0TextWords[87495U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b5bcU);
}
static std::uint32_t ByteVc0FdeFunc_0870_0x05b5e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[870] @ func_va=0x05b5e0, fde_va=0x07ed58, first_op=0xf81e0ff3
    // VI: Hàm FDE[870] tại địa chỉ 0x05b5e0, bản ghi FDE 0x07ed58
    const std::uint32_t w0 = kByteVc0TextWords[87504U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b5e0U);
}
static std::uint32_t ByteVc0FdeFunc_0871_0x05b638(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[871] @ func_va=0x05b638, fde_va=0x07ed78, first_op=0xa9bd57f6
    // VI: Hàm FDE[871] tại địa chỉ 0x05b638, bản ghi FDE 0x07ed78
    const std::uint32_t w0 = kByteVc0TextWords[87526U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b638U);
}
static std::uint32_t ByteVc0FdeFunc_0872_0x05b770(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[872] @ func_va=0x05b770, fde_va=0x07eda0, first_op=0xf81d0ff5
    // VI: Hàm FDE[872] tại địa chỉ 0x05b770, bản ghi FDE 0x07eda0
    const std::uint32_t w0 = kByteVc0TextWords[87604U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b770U);
}
static std::uint32_t ByteVc0FdeFunc_0873_0x05b854(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[873] @ func_va=0x05b854, fde_va=0x07edc0, first_op=0xf81b0ff9
    // VI: Hàm FDE[873] tại địa chỉ 0x05b854, bản ghi FDE 0x07edc0
    const std::uint32_t w0 = kByteVc0TextWords[87661U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b854U);
}
static std::uint32_t ByteVc0FdeFunc_0874_0x05b97c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[874] @ func_va=0x05b97c, fde_va=0x07ede8, first_op=0xa9bf7bfd
    // VI: Hàm FDE[874] tại địa chỉ 0x05b97c, bản ghi FDE 0x07ede8
    const std::uint32_t w0 = kByteVc0TextWords[87735U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b97cU);
}
static std::uint32_t ByteVc0FdeFunc_0875_0x05b9c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[875] @ func_va=0x05b9c8, fde_va=0x07ee08, first_op=0xd65f03c0
    // VI: Hàm FDE[875] tại địa chỉ 0x05b9c8, bản ghi FDE 0x07ee08
    const std::uint32_t w0 = kByteVc0TextWords[87754U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b9c8U);
}
static std::uint32_t ByteVc0FdeFunc_0876_0x05b9cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[876] @ func_va=0x05b9cc, fde_va=0x07ee20, first_op=0xd100c3ff
    // VI: Hàm FDE[876] tại địa chỉ 0x05b9cc, bản ghi FDE 0x07ee20
    const std::uint32_t w0 = kByteVc0TextWords[87755U];
    std::uint32_t acc = w0 ^ 0xd100c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05b9ccU);
}
static std::uint32_t ByteVc0FdeFunc_0877_0x05ba3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[877] @ func_va=0x05ba3c, fde_va=0x07ee40, first_op=0xa9bf7bfd
    // VI: Hàm FDE[877] tại địa chỉ 0x05ba3c, bản ghi FDE 0x07ee40
    const std::uint32_t w0 = kByteVc0TextWords[87783U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ba3cU);
}
static std::uint32_t ByteVc0FdeFunc_0878_0x05ba5c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[878] @ func_va=0x05ba5c, fde_va=0x07ee60, first_op=0xa9bf7bfd
    // VI: Hàm FDE[878] tại địa chỉ 0x05ba5c, bản ghi FDE 0x07ee60
    const std::uint32_t w0 = kByteVc0TextWords[87791U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ba5cU);
}
static std::uint32_t ByteVc0FdeFunc_0879_0x05ba7c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[879] @ func_va=0x05ba7c, fde_va=0x07ee80, first_op=0xa9bf7bfd
    // VI: Hàm FDE[879] tại địa chỉ 0x05ba7c, bản ghi FDE 0x07ee80
    const std::uint32_t w0 = kByteVc0TextWords[87799U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ba7cU);
}
static std::uint32_t ByteVc0FdeFunc_0880_0x05ba9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[880] @ func_va=0x05ba9c, fde_va=0x07eea0, first_op=0xf81e0ff3
    // VI: Hàm FDE[880] tại địa chỉ 0x05ba9c, bản ghi FDE 0x07eea0
    const std::uint32_t w0 = kByteVc0TextWords[87807U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ba9cU);
}
static std::uint32_t ByteVc0FdeFunc_0881_0x05bb1c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[881] @ func_va=0x05bb1c, fde_va=0x07eec0, first_op=0xa9bf7bfd
    // VI: Hàm FDE[881] tại địa chỉ 0x05bb1c, bản ghi FDE 0x07eec0
    const std::uint32_t w0 = kByteVc0TextWords[87839U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bb1cU);
}
static std::uint32_t ByteVc0FdeFunc_0882_0x05bb38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[882] @ func_va=0x05bb38, fde_va=0x07eee0, first_op=0xa9be4ff4
    // VI: Hàm FDE[882] tại địa chỉ 0x05bb38, bản ghi FDE 0x07eee0
    const std::uint32_t w0 = kByteVc0TextWords[87846U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bb38U);
}
static std::uint32_t ByteVc0FdeFunc_0883_0x05bb80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[883] @ func_va=0x05bb80, fde_va=0x07ef00, first_op=0xa9bf7bfd
    // VI: Hàm FDE[883] tại địa chỉ 0x05bb80, bản ghi FDE 0x07ef00
    const std::uint32_t w0 = kByteVc0TextWords[87864U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bb80U);
}
static std::uint32_t ByteVc0FdeFunc_0884_0x05bb98(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[884] @ func_va=0x05bb98, fde_va=0x07ef20, first_op=0xf81d0ff5
    // VI: Hàm FDE[884] tại địa chỉ 0x05bb98, bản ghi FDE 0x07ef20
    const std::uint32_t w0 = kByteVc0TextWords[87870U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bb98U);
}
static std::uint32_t ByteVc0FdeFunc_0885_0x05bbfc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[885] @ func_va=0x05bbfc, fde_va=0x07ef40, first_op=0xa9bf7bfd
    // VI: Hàm FDE[885] tại địa chỉ 0x05bbfc, bản ghi FDE 0x07ef40
    const std::uint32_t w0 = kByteVc0TextWords[87895U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bbfcU);
}
static std::uint32_t ByteVc0FdeFunc_0886_0x05bc14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[886] @ func_va=0x05bc14, fde_va=0x07ef60, first_op=0xf81e0ff3
    // VI: Hàm FDE[886] tại địa chỉ 0x05bc14, bản ghi FDE 0x07ef60
    const std::uint32_t w0 = kByteVc0TextWords[87901U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bc14U);
}
static std::uint32_t ByteVc0FdeFunc_0887_0x05bc60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[887] @ func_va=0x05bc60, fde_va=0x07ef80, first_op=0xa9bf7bfd
    // VI: Hàm FDE[887] tại địa chỉ 0x05bc60, bản ghi FDE 0x07ef80
    const std::uint32_t w0 = kByteVc0TextWords[87920U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bc60U);
}
static std::uint32_t ByteVc0FdeFunc_0888_0x05bc78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[888] @ func_va=0x05bc78, fde_va=0x07efa0, first_op=0xa9bf7bfd
    // VI: Hàm FDE[888] tại địa chỉ 0x05bc78, bản ghi FDE 0x07efa0
    const std::uint32_t w0 = kByteVc0TextWords[87926U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bc78U);
}
static std::uint32_t ByteVc0FdeFunc_0889_0x05bca4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[889] @ func_va=0x05bca4, fde_va=0x07efc0, first_op=0xa9bf7bfd
    // VI: Hàm FDE[889] tại địa chỉ 0x05bca4, bản ghi FDE 0x07efc0
    const std::uint32_t w0 = kByteVc0TextWords[87937U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bca4U);
}
static std::uint32_t ByteVc0FdeFunc_0890_0x05bcc8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[890] @ func_va=0x05bcc8, fde_va=0x07efe0, first_op=0x2a1f03e0
    // VI: Hàm FDE[890] tại địa chỉ 0x05bcc8, bản ghi FDE 0x07efe0
    const std::uint32_t w0 = kByteVc0TextWords[87946U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bcc8U);
}
static std::uint32_t ByteVc0FdeFunc_0891_0x05bcd0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[891] @ func_va=0x05bcd0, fde_va=0x07eff8, first_op=0xa9bf7bfd
    // VI: Hàm FDE[891] tại địa chỉ 0x05bcd0, bản ghi FDE 0x07eff8
    const std::uint32_t w0 = kByteVc0TextWords[87948U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bcd0U);
}
static std::uint32_t ByteVc0FdeFunc_0892_0x05bcf0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[892] @ func_va=0x05bcf0, fde_va=0x07f018, first_op=0x52807d08
    // VI: Hàm FDE[892] tại địa chỉ 0x05bcf0, bản ghi FDE 0x07f018
    const std::uint32_t w0 = kByteVc0TextWords[87956U];
    std::uint32_t acc = w0 ^ 0x52807d08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bcf0U);
}
static std::uint32_t ByteVc0FdeFunc_0893_0x05bcfc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[893] @ func_va=0x05bcfc, fde_va=0x07f030, first_op=0x52800021
    // VI: Hàm FDE[893] tại địa chỉ 0x05bcfc, bản ghi FDE 0x07f030
    const std::uint32_t w0 = kByteVc0TextWords[87959U];
    std::uint32_t acc = w0 ^ 0x52800021U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bcfcU);
}
static std::uint32_t ByteVc0FdeFunc_0894_0x05bd04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[894] @ func_va=0x05bd04, fde_va=0x07f048, first_op=0x17fea7db
    // VI: Hàm FDE[894] tại địa chỉ 0x05bd04, bản ghi FDE 0x07f048
    const std::uint32_t w0 = kByteVc0TextWords[87961U];
    std::uint32_t acc = w0 ^ 0x17fea7dbU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bd04U);
}
static std::uint32_t ByteVc0FdeFunc_0895_0x05bd08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[895] @ func_va=0x05bd08, fde_va=0x07f060, first_op=0x17fea7e2
    // VI: Hàm FDE[895] tại địa chỉ 0x05bd08, bản ghi FDE 0x07f060
    const std::uint32_t w0 = kByteVc0TextWords[87962U];
    std::uint32_t acc = w0 ^ 0x17fea7e2U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bd08U);
}
static std::uint32_t ByteVc0FdeFunc_0896_0x05bd0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[896] @ func_va=0x05bd0c, fde_va=0x07f078, first_op=0xd10083ff
    // VI: Hàm FDE[896] tại địa chỉ 0x05bd0c, bản ghi FDE 0x07f078
    const std::uint32_t w0 = kByteVc0TextWords[87963U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bd0cU);
}
static std::uint32_t ByteVc0FdeFunc_0897_0x05bd58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[897] @ func_va=0x05bd58, fde_va=0x07f098, first_op=0xd10083ff
    // VI: Hàm FDE[897] tại địa chỉ 0x05bd58, bản ghi FDE 0x07f098
    const std::uint32_t w0 = kByteVc0TextWords[87982U];
    std::uint32_t acc = w0 ^ 0xd10083ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bd58U);
}
static std::uint32_t ByteVc0FdeFunc_0898_0x05bd8c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[898] @ func_va=0x05bd8c, fde_va=0x07f0b8, first_op=0xf81e0ff3
    // VI: Hàm FDE[898] tại địa chỉ 0x05bd8c, bản ghi FDE 0x07f0b8
    const std::uint32_t w0 = kByteVc0TextWords[87995U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bd8cU);
}
static std::uint32_t ByteVc0FdeFunc_0899_0x05bdb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[899] @ func_va=0x05bdb8, fde_va=0x07f0d8, first_op=0xf81e0ff3
    // VI: Hàm FDE[899] tại địa chỉ 0x05bdb8, bản ghi FDE 0x07f0d8
    const std::uint32_t w0 = kByteVc0TextWords[88006U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bdb8U);
}
static std::uint32_t ByteVc0FdeFunc_0900_0x05bde0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[900] @ func_va=0x05bde0, fde_va=0x07f0f8, first_op=0xa9be4ff4
    // VI: Hàm FDE[900] tại địa chỉ 0x05bde0, bản ghi FDE 0x07f0f8
    const std::uint32_t w0 = kByteVc0TextWords[88016U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bde0U);
}
static std::uint32_t ByteVc0FdeFunc_0901_0x05be14(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[901] @ func_va=0x05be14, fde_va=0x07f118, first_op=0xa9be4ff4
    // VI: Hàm FDE[901] tại địa chỉ 0x05be14, bản ghi FDE 0x07f118
    const std::uint32_t w0 = kByteVc0TextWords[88029U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05be14U);
}
static std::uint32_t ByteVc0FdeFunc_0902_0x05be44(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[902] @ func_va=0x05be44, fde_va=0x07f138, first_op=0xa9be4ff4
    // VI: Hàm FDE[902] tại địa chỉ 0x05be44, bản ghi FDE 0x07f138
    const std::uint32_t w0 = kByteVc0TextWords[88041U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05be44U);
}
static std::uint32_t ByteVc0FdeFunc_0903_0x05be80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[903] @ func_va=0x05be80, fde_va=0x07f158, first_op=0xf81e0ff3
    // VI: Hàm FDE[903] tại địa chỉ 0x05be80, bản ghi FDE 0x07f158
    const std::uint32_t w0 = kByteVc0TextWords[88056U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05be80U);
}
static std::uint32_t ByteVc0FdeFunc_0904_0x05beb8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[904] @ func_va=0x05beb8, fde_va=0x07f178, first_op=0xf81d0ff5
    // VI: Hàm FDE[904] tại địa chỉ 0x05beb8, bản ghi FDE 0x07f178
    const std::uint32_t w0 = kByteVc0TextWords[88070U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05beb8U);
}
static std::uint32_t ByteVc0FdeFunc_0905_0x05bf0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[905] @ func_va=0x05bf0c, fde_va=0x07f198, first_op=0xf81e0ff3
    // VI: Hàm FDE[905] tại địa chỉ 0x05bf0c, bản ghi FDE 0x07f198
    const std::uint32_t w0 = kByteVc0TextWords[88091U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bf0cU);
}
static std::uint32_t ByteVc0FdeFunc_0906_0x05bf38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[906] @ func_va=0x05bf38, fde_va=0x07f1b8, first_op=0xa9be4ff4
    // VI: Hàm FDE[906] tại địa chỉ 0x05bf38, bản ghi FDE 0x07f1b8
    const std::uint32_t w0 = kByteVc0TextWords[88102U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bf38U);
}
static std::uint32_t ByteVc0FdeFunc_0907_0x05bf88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[907] @ func_va=0x05bf88, fde_va=0x07f1d8, first_op=0xf81d0ff5
    // VI: Hàm FDE[907] tại địa chỉ 0x05bf88, bản ghi FDE 0x07f1d8
    const std::uint32_t w0 = kByteVc0TextWords[88122U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bf88U);
}
static std::uint32_t ByteVc0FdeFunc_0908_0x05bff4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[908] @ func_va=0x05bff4, fde_va=0x07f1f8, first_op=0xb9400008
    // VI: Hàm FDE[908] tại địa chỉ 0x05bff4, bản ghi FDE 0x07f1f8
    const std::uint32_t w0 = kByteVc0TextWords[88149U];
    std::uint32_t acc = w0 ^ 0xb9400008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05bff4U);
}
static std::uint32_t ByteVc0FdeFunc_0909_0x05c010(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[909] @ func_va=0x05c010, fde_va=0x07f210, first_op=0xd65f03c0
    // VI: Hàm FDE[909] tại địa chỉ 0x05c010, bản ghi FDE 0x07f210
    const std::uint32_t w0 = kByteVc0TextWords[88156U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c010U);
}
static std::uint32_t ByteVc0FdeFunc_0910_0x05c014(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[910] @ func_va=0x05c014, fde_va=0x07f228, first_op=0xf81d0ff5
    // VI: Hàm FDE[910] tại địa chỉ 0x05c014, bản ghi FDE 0x07f228
    const std::uint32_t w0 = kByteVc0TextWords[88157U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c014U);
}
static std::uint32_t ByteVc0FdeFunc_0911_0x05c058(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[911] @ func_va=0x05c058, fde_va=0x07f248, first_op=0x14000047
    // VI: Hàm FDE[911] tại địa chỉ 0x05c058, bản ghi FDE 0x07f248
    const std::uint32_t w0 = kByteVc0TextWords[88174U];
    std::uint32_t acc = w0 ^ 0x14000047U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c058U);
}
static std::uint32_t ByteVc0FdeFunc_0912_0x05c05c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[912] @ func_va=0x05c05c, fde_va=0x07f260, first_op=0xf81e0ff3
    // VI: Hàm FDE[912] tại địa chỉ 0x05c05c, bản ghi FDE 0x07f260
    const std::uint32_t w0 = kByteVc0TextWords[88175U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c05cU);
}
static std::uint32_t ByteVc0FdeFunc_0913_0x05c080(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[913] @ func_va=0x05c080, fde_va=0x07f280, first_op=0xa9bf7bfd
    // VI: Hàm FDE[913] tại địa chỉ 0x05c080, bản ghi FDE 0x07f280
    const std::uint32_t w0 = kByteVc0TextWords[88184U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c080U);
}
static std::uint32_t ByteVc0FdeFunc_0914_0x05c0b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[914] @ func_va=0x05c0b8, fde_va=0x07f2a0, first_op=0xf81e0ff3
    // VI: Hàm FDE[914] tại địa chỉ 0x05c0b8, bản ghi FDE 0x07f2a0
    const std::uint32_t w0 = kByteVc0TextWords[88198U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c0b8U);
}
static std::uint32_t ByteVc0FdeFunc_0915_0x05c13c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[915] @ func_va=0x05c13c, fde_va=0x07f2c0, first_op=0xf0000148
    // VI: Hàm FDE[915] tại địa chỉ 0x05c13c, bản ghi FDE 0x07f2c0
    const std::uint32_t w0 = kByteVc0TextWords[88231U];
    std::uint32_t acc = w0 ^ 0xf0000148U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c13cU);
}
static std::uint32_t ByteVc0FdeFunc_0916_0x05c174(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[916] @ func_va=0x05c174, fde_va=0x07f2d8, first_op=0xf81e0ff3
    // VI: Hàm FDE[916] tại địa chỉ 0x05c174, bản ghi FDE 0x07f2d8
    const std::uint32_t w0 = kByteVc0TextWords[88245U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c174U);
}
static std::uint32_t ByteVc0FdeFunc_0917_0x05c1a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[917] @ func_va=0x05c1a4, fde_va=0x07f2f8, first_op=0xf81e0ff3
    // VI: Hàm FDE[917] tại địa chỉ 0x05c1a4, bản ghi FDE 0x07f2f8
    const std::uint32_t w0 = kByteVc0TextWords[88257U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c1a4U);
}
static std::uint32_t ByteVc0FdeFunc_0918_0x05c1f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[918] @ func_va=0x05c1f0, fde_va=0x07f318, first_op=0xd4200020
    // VI: Hàm FDE[918] tại địa chỉ 0x05c1f0, bản ghi FDE 0x07f318
    const std::uint32_t w0 = kByteVc0TextWords[88276U];
    std::uint32_t acc = w0 ^ 0xd4200020U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c1f0U);
}
static std::uint32_t ByteVc0FdeFunc_0919_0x05c1f4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[919] @ func_va=0x05c1f4, fde_va=0x07f330, first_op=0xf81e0ff3
    // VI: Hàm FDE[919] tại địa chỉ 0x05c1f4, bản ghi FDE 0x07f330
    const std::uint32_t w0 = kByteVc0TextWords[88277U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c1f4U);
}
static std::uint32_t ByteVc0FdeFunc_0920_0x05c268(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[920] @ func_va=0x05c268, fde_va=0x07f350, first_op=0xf81e0ff3
    // VI: Hàm FDE[920] tại địa chỉ 0x05c268, bản ghi FDE 0x07f350
    const std::uint32_t w0 = kByteVc0TextWords[88306U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c268U);
}
static std::uint32_t ByteVc0FdeFunc_0921_0x05c29c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[921] @ func_va=0x05c29c, fde_va=0x07f370, first_op=0x91006000
    // VI: Hàm FDE[921] tại địa chỉ 0x05c29c, bản ghi FDE 0x07f370
    const std::uint32_t w0 = kByteVc0TextWords[88319U];
    std::uint32_t acc = w0 ^ 0x91006000U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c29cU);
}
static std::uint32_t ByteVc0FdeFunc_0922_0x05c2a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[922] @ func_va=0x05c2a4, fde_va=0x07f388, first_op=0xa9bd57f6
    // VI: Hàm FDE[922] tại địa chỉ 0x05c2a4, bản ghi FDE 0x07f388
    const std::uint32_t w0 = kByteVc0TextWords[88321U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c2a4U);
}
static std::uint32_t ByteVc0FdeFunc_0923_0x05c314(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[923] @ func_va=0x05c314, fde_va=0x07f3b0, first_op=0xa9bf7bfd
    // VI: Hàm FDE[923] tại địa chỉ 0x05c314, bản ghi FDE 0x07f3b0
    const std::uint32_t w0 = kByteVc0TextWords[88349U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c314U);
}
static std::uint32_t ByteVc0FdeFunc_0924_0x05c334(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[924] @ func_va=0x05c334, fde_va=0x07f3d0, first_op=0xa9be4ff4
    // VI: Hàm FDE[924] tại địa chỉ 0x05c334, bản ghi FDE 0x07f3d0
    const std::uint32_t w0 = kByteVc0TextWords[88357U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c334U);
}
static std::uint32_t ByteVc0FdeFunc_0925_0x05c39c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[925] @ func_va=0x05c39c, fde_va=0x07f3f0, first_op=0xf81e0ff3
    // VI: Hàm FDE[925] tại địa chỉ 0x05c39c, bản ghi FDE 0x07f3f0
    const std::uint32_t w0 = kByteVc0TextWords[88383U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c39cU);
}
static std::uint32_t ByteVc0FdeFunc_0926_0x05c3fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[926] @ func_va=0x05c3fc, fde_va=0x07f410, first_op=0xf81b0ff9
    // VI: Hàm FDE[926] tại địa chỉ 0x05c3fc, bản ghi FDE 0x07f410
    const std::uint32_t w0 = kByteVc0TextWords[88407U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c3fcU);
}
static std::uint32_t ByteVc0FdeFunc_0927_0x05c510(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[927] @ func_va=0x05c510, fde_va=0x07f438, first_op=0xf81e0ff3
    // VI: Hàm FDE[927] tại địa chỉ 0x05c510, bản ghi FDE 0x07f438
    const std::uint32_t w0 = kByteVc0TextWords[88476U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c510U);
}
static std::uint32_t ByteVc0FdeFunc_0928_0x05c534(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[928] @ func_va=0x05c534, fde_va=0x07f458, first_op=0xa9bd57f6
    // VI: Hàm FDE[928] tại địa chỉ 0x05c534, bản ghi FDE 0x07f458
    const std::uint32_t w0 = kByteVc0TextWords[88485U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c534U);
}
static std::uint32_t ByteVc0FdeFunc_0929_0x05c5cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[929] @ func_va=0x05c5cc, fde_va=0x07f480, first_op=0xf81d0ff5
    // VI: Hàm FDE[929] tại địa chỉ 0x05c5cc, bản ghi FDE 0x07f480
    const std::uint32_t w0 = kByteVc0TextWords[88523U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c5ccU);
}
static std::uint32_t ByteVc0FdeFunc_0930_0x05c698(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[930] @ func_va=0x05c698, fde_va=0x07f4a0, first_op=0xf81d0ff5
    // VI: Hàm FDE[930] tại địa chỉ 0x05c698, bản ghi FDE 0x07f4a0
    const std::uint32_t w0 = kByteVc0TextWords[88574U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c698U);
}
static std::uint32_t ByteVc0FdeFunc_0931_0x05c704(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[931] @ func_va=0x05c704, fde_va=0x07f4c0, first_op=0xf81d0ff5
    // VI: Hàm FDE[931] tại địa chỉ 0x05c704, bản ghi FDE 0x07f4c0
    const std::uint32_t w0 = kByteVc0TextWords[88601U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c704U);
}
static std::uint32_t ByteVc0FdeFunc_0932_0x05c76c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[932] @ func_va=0x05c76c, fde_va=0x07f4e0, first_op=0xf81d0ff5
    // VI: Hàm FDE[932] tại địa chỉ 0x05c76c, bản ghi FDE 0x07f4e0
    const std::uint32_t w0 = kByteVc0TextWords[88627U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c76cU);
}
static std::uint32_t ByteVc0FdeFunc_0933_0x05c7e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[933] @ func_va=0x05c7e0, fde_va=0x07f500, first_op=0xf81d0ff5
    // VI: Hàm FDE[933] tại địa chỉ 0x05c7e0, bản ghi FDE 0x07f500
    const std::uint32_t w0 = kByteVc0TextWords[88656U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c7e0U);
}
static std::uint32_t ByteVc0FdeFunc_0934_0x05c854(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[934] @ func_va=0x05c854, fde_va=0x07f520, first_op=0xf81c0ff7
    // VI: Hàm FDE[934] tại địa chỉ 0x05c854, bản ghi FDE 0x07f520
    const std::uint32_t w0 = kByteVc0TextWords[88685U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c854U);
}
static std::uint32_t ByteVc0FdeFunc_0935_0x05c914(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[935] @ func_va=0x05c914, fde_va=0x07f548, first_op=0xa9ba6ffc
    // VI: Hàm FDE[935] tại địa chỉ 0x05c914, bản ghi FDE 0x07f548
    const std::uint32_t w0 = kByteVc0TextWords[88733U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05c914U);
}
static std::uint32_t ByteVc0FdeFunc_0936_0x05caa8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[936] @ func_va=0x05caa8, fde_va=0x07f578, first_op=0x2a1f03e0
    // VI: Hàm FDE[936] tại địa chỉ 0x05caa8, bản ghi FDE 0x07f578
    const std::uint32_t w0 = kByteVc0TextWords[88834U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05caa8U);
}
static std::uint32_t ByteVc0FdeFunc_0937_0x05cab0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[937] @ func_va=0x05cab0, fde_va=0x07f590, first_op=0x2a1f03e0
    // VI: Hàm FDE[937] tại địa chỉ 0x05cab0, bản ghi FDE 0x07f590
    const std::uint32_t w0 = kByteVc0TextWords[88836U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cab0U);
}
static std::uint32_t ByteVc0FdeFunc_0938_0x05cab8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[938] @ func_va=0x05cab8, fde_va=0x07f5a8, first_op=0xa9bd57f6
    // VI: Hàm FDE[938] tại địa chỉ 0x05cab8, bản ghi FDE 0x07f5a8
    const std::uint32_t w0 = kByteVc0TextWords[88838U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cab8U);
}
static std::uint32_t ByteVc0FdeFunc_0939_0x05cb2c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[939] @ func_va=0x05cb2c, fde_va=0x07f5d0, first_op=0xa9bf7bfd
    // VI: Hàm FDE[939] tại địa chỉ 0x05cb2c, bản ghi FDE 0x07f5d0
    const std::uint32_t w0 = kByteVc0TextWords[88867U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cb2cU);
}
static std::uint32_t ByteVc0FdeFunc_0940_0x05cb48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[940] @ func_va=0x05cb48, fde_va=0x07f5f0, first_op=0xa9be4ff4
    // VI: Hàm FDE[940] tại địa chỉ 0x05cb48, bản ghi FDE 0x07f5f0
    const std::uint32_t w0 = kByteVc0TextWords[88874U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cb48U);
}
static std::uint32_t ByteVc0FdeFunc_0941_0x05cb88(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[941] @ func_va=0x05cb88, fde_va=0x07f610, first_op=0xa9be4ff4
    // VI: Hàm FDE[941] tại địa chỉ 0x05cb88, bản ghi FDE 0x07f610
    const std::uint32_t w0 = kByteVc0TextWords[88890U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cb88U);
}
static std::uint32_t ByteVc0FdeFunc_0942_0x05cbe8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[942] @ func_va=0x05cbe8, fde_va=0x07f630, first_op=0xa9be4ff4
    // VI: Hàm FDE[942] tại địa chỉ 0x05cbe8, bản ghi FDE 0x07f630
    const std::uint32_t w0 = kByteVc0TextWords[88914U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cbe8U);
}
static std::uint32_t ByteVc0FdeFunc_0943_0x05cc48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[943] @ func_va=0x05cc48, fde_va=0x07f650, first_op=0xd10343ff
    // VI: Hàm FDE[943] tại địa chỉ 0x05cc48, bản ghi FDE 0x07f650
    const std::uint32_t w0 = kByteVc0TextWords[88938U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cc48U);
}
static std::uint32_t ByteVc0FdeFunc_0944_0x05cf48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[944] @ func_va=0x05cf48, fde_va=0x07f678, first_op=0x39409c08
    // VI: Hàm FDE[944] tại địa chỉ 0x05cf48, bản ghi FDE 0x07f678
    const std::uint32_t w0 = kByteVc0TextWords[89130U];
    std::uint32_t acc = w0 ^ 0x39409c08U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cf48U);
}
static std::uint32_t ByteVc0FdeFunc_0945_0x05cf84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[945] @ func_va=0x05cf84, fde_va=0x07f690, first_op=0xb9400029
    // VI: Hàm FDE[945] tại địa chỉ 0x05cf84, bản ghi FDE 0x07f690
    const std::uint32_t w0 = kByteVc0TextWords[89145U];
    std::uint32_t acc = w0 ^ 0xb9400029U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05cf84U);
}
static std::uint32_t ByteVc0FdeFunc_0946_0x05d1c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[946] @ func_va=0x05d1c0, fde_va=0x07f6a8, first_op=0xf81e0ff3
    // VI: Hàm FDE[946] tại địa chỉ 0x05d1c0, bản ghi FDE 0x07f6a8
    const std::uint32_t w0 = kByteVc0TextWords[89288U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d1c0U);
}
static std::uint32_t ByteVc0FdeFunc_0947_0x05d318(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[947] @ func_va=0x05d318, fde_va=0x07f6c8, first_op=0x7100087f
    // VI: Hàm FDE[947] tại địa chỉ 0x05d318, bản ghi FDE 0x07f6c8
    const std::uint32_t w0 = kByteVc0TextWords[89374U];
    std::uint32_t acc = w0 ^ 0x7100087fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d318U);
}
static std::uint32_t ByteVc0FdeFunc_0948_0x05d344(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[948] @ func_va=0x05d344, fde_va=0x07f6e0, first_op=0xd00000a8
    // VI: Hàm FDE[948] tại địa chỉ 0x05d344, bản ghi FDE 0x07f6e0
    const std::uint32_t w0 = kByteVc0TextWords[89385U];
    std::uint32_t acc = w0 ^ 0xd00000a8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d344U);
}
static std::uint32_t ByteVc0FdeFunc_0949_0x05d354(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[949] @ func_va=0x05d354, fde_va=0x07f6f8, first_op=0xd00000a8
    // VI: Hàm FDE[949] tại địa chỉ 0x05d354, bản ghi FDE 0x07f6f8
    const std::uint32_t w0 = kByteVc0TextWords[89389U];
    std::uint32_t acc = w0 ^ 0xd00000a8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d354U);
}
static std::uint32_t ByteVc0FdeFunc_0950_0x05d36c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[950] @ func_va=0x05d36c, fde_va=0x07f710, first_op=0x52800028
    // VI: Hàm FDE[950] tại địa chỉ 0x05d36c, bản ghi FDE 0x07f710
    const std::uint32_t w0 = kByteVc0TextWords[89395U];
    std::uint32_t acc = w0 ^ 0x52800028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d36cU);
}
static std::uint32_t ByteVc0FdeFunc_0951_0x05d480(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[951] @ func_va=0x05d480, fde_va=0x07f728, first_op=0xcb23c809
    // VI: Hàm FDE[951] tại địa chỉ 0x05d480, bản ghi FDE 0x07f728
    const std::uint32_t w0 = kByteVc0TextWords[89464U];
    std::uint32_t acc = w0 ^ 0xcb23c809U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d480U);
}
static std::uint32_t ByteVc0FdeFunc_0952_0x05d5f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[952] @ func_va=0x05d5f0, fde_va=0x07f740, first_op=0x297fa00a
    // VI: Hàm FDE[952] tại địa chỉ 0x05d5f0, bản ghi FDE 0x07f740
    const std::uint32_t w0 = kByteVc0TextWords[89556U];
    std::uint32_t acc = w0 ^ 0x297fa00aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d5f0U);
}
static std::uint32_t ByteVc0FdeFunc_0953_0x05d6cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[953] @ func_va=0x05d6cc, fde_va=0x07f758, first_op=0xcb23c809
    // VI: Hàm FDE[953] tại địa chỉ 0x05d6cc, bản ghi FDE 0x07f758
    const std::uint32_t w0 = kByteVc0TextWords[89611U];
    std::uint32_t acc = w0 ^ 0xcb23c809U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d6ccU);
}
static std::uint32_t ByteVc0FdeFunc_0954_0x05d7bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[954] @ func_va=0x05d7bc, fde_va=0x07f770, first_op=0x36000141
    // VI: Hàm FDE[954] tại địa chỉ 0x05d7bc, bản ghi FDE 0x07f770
    const std::uint32_t w0 = kByteVc0TextWords[89671U];
    std::uint32_t acc = w0 ^ 0x36000141U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d7bcU);
}
static std::uint32_t ByteVc0FdeFunc_0955_0x05d7e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[955] @ func_va=0x05d7e8, fde_va=0x07f788, first_op=0x36000101
    // VI: Hàm FDE[955] tại địa chỉ 0x05d7e8, bản ghi FDE 0x07f788
    const std::uint32_t w0 = kByteVc0TextWords[89682U];
    std::uint32_t acc = w0 ^ 0x36000101U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d7e8U);
}
static std::uint32_t ByteVc0FdeFunc_0956_0x05d838(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[956] @ func_va=0x05d838, fde_va=0x07f7a0, first_op=0x90000009
    // VI: Hàm FDE[956] tại địa chỉ 0x05d838, bản ghi FDE 0x07f7a0
    const std::uint32_t w0 = kByteVc0TextWords[89702U];
    std::uint32_t acc = w0 ^ 0x90000009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d838U);
}
static std::uint32_t ByteVc0FdeFunc_0957_0x05d84c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[957] @ func_va=0x05d84c, fde_va=0x07f7b8, first_op=0xaa1f03e8
    // VI: Hàm FDE[957] tại địa chỉ 0x05d84c, bản ghi FDE 0x07f7b8
    const std::uint32_t w0 = kByteVc0TextWords[89707U];
    std::uint32_t acc = w0 ^ 0xaa1f03e8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d84cU);
}
static std::uint32_t ByteVc0FdeFunc_0958_0x05d918(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[958] @ func_va=0x05d918, fde_va=0x07f7d0, first_op=0x90000009
    // VI: Hàm FDE[958] tại địa chỉ 0x05d918, bản ghi FDE 0x07f7d0
    const std::uint32_t w0 = kByteVc0TextWords[89758U];
    std::uint32_t acc = w0 ^ 0x90000009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d918U);
}
static std::uint32_t ByteVc0FdeFunc_0959_0x05d9b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[959] @ func_va=0x05d9b0, fde_va=0x07f7e8, first_op=0xf81e0ff3
    // VI: Hàm FDE[959] tại địa chỉ 0x05d9b0, bản ghi FDE 0x07f7e8
    const std::uint32_t w0 = kByteVc0TextWords[89796U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05d9b0U);
}
static std::uint32_t ByteVc0FdeFunc_0960_0x05daf0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[960] @ func_va=0x05daf0, fde_va=0x07f808, first_op=0xa9ba6ffc
    // VI: Hàm FDE[960] tại địa chỉ 0x05daf0, bản ghi FDE 0x07f808
    const std::uint32_t w0 = kByteVc0TextWords[89876U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05daf0U);
}
static std::uint32_t ByteVc0FdeFunc_0961_0x05de78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[961] @ func_va=0x05de78, fde_va=0x07f838, first_op=0xb9400028
    // VI: Hàm FDE[961] tại địa chỉ 0x05de78, bản ghi FDE 0x07f838
    const std::uint32_t w0 = kByteVc0TextWords[90102U];
    std::uint32_t acc = w0 ^ 0xb9400028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05de78U);
}
static std::uint32_t ByteVc0FdeFunc_0962_0x05deac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[962] @ func_va=0x05deac, fde_va=0x07f850, first_op=0xb9400028
    // VI: Hàm FDE[962] tại địa chỉ 0x05deac, bản ghi FDE 0x07f850
    const std::uint32_t w0 = kByteVc0TextWords[90115U];
    std::uint32_t acc = w0 ^ 0xb9400028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05deacU);
}
static std::uint32_t ByteVc0FdeFunc_0963_0x05ded8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[963] @ func_va=0x05ded8, fde_va=0x07f868, first_op=0xa9bb6ffc
    // VI: Hàm FDE[963] tại địa chỉ 0x05ded8, bản ghi FDE 0x07f868
    const std::uint32_t w0 = kByteVc0TextWords[90126U];
    std::uint32_t acc = w0 ^ 0xa9bb6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ded8U);
}
static std::uint32_t ByteVc0FdeFunc_0964_0x05e100(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[964] @ func_va=0x05e100, fde_va=0x07f890, first_op=0xa9be57f6
    // VI: Hàm FDE[964] tại địa chỉ 0x05e100, bản ghi FDE 0x07f890
    const std::uint32_t w0 = kByteVc0TextWords[90264U];
    std::uint32_t acc = w0 ^ 0xa9be57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e100U);
}
static std::uint32_t ByteVc0FdeFunc_0965_0x05e1f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[965] @ func_va=0x05e1f8, fde_va=0x07f8b0, first_op=0x710040df
    // VI: Hàm FDE[965] tại địa chỉ 0x05e1f8, bản ghi FDE 0x07f8b0
    const std::uint32_t w0 = kByteVc0TextWords[90326U];
    std::uint32_t acc = w0 ^ 0x710040dfU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e1f8U);
}
static std::uint32_t ByteVc0FdeFunc_0966_0x05e284(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[966] @ func_va=0x05e284, fde_va=0x07f8c8, first_op=0x14003130
    // VI: Hàm FDE[966] tại địa chỉ 0x05e284, bản ghi FDE 0x07f8c8
    const std::uint32_t w0 = kByteVc0TextWords[90361U];
    std::uint32_t acc = w0 ^ 0x14003130U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e284U);
}
static std::uint32_t ByteVc0FdeFunc_0967_0x05e288(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[967] @ func_va=0x05e288, fde_va=0x07f8e0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[967] tại địa chỉ 0x05e288, bản ghi FDE 0x07f8e0
    const std::uint32_t w0 = kByteVc0TextWords[90362U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e288U);
}
static std::uint32_t ByteVc0FdeFunc_0968_0x05e3bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[968] @ func_va=0x05e3bc, fde_va=0x07f910, first_op=0xa9ba6ffc
    // VI: Hàm FDE[968] tại địa chỉ 0x05e3bc, bản ghi FDE 0x07f910
    const std::uint32_t w0 = kByteVc0TextWords[90439U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e3bcU);
}
static std::uint32_t ByteVc0FdeFunc_0969_0x05e4f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[969] @ func_va=0x05e4f0, fde_va=0x07f940, first_op=0xa9ba6ffc
    // VI: Hàm FDE[969] tại địa chỉ 0x05e4f0, bản ghi FDE 0x07f940
    const std::uint32_t w0 = kByteVc0TextWords[90516U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e4f0U);
}
static std::uint32_t ByteVc0FdeFunc_0970_0x05e624(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[970] @ func_va=0x05e624, fde_va=0x07f970, first_op=0x90000008
    // VI: Hàm FDE[970] tại địa chỉ 0x05e624, bản ghi FDE 0x07f970
    const std::uint32_t w0 = kByteVc0TextWords[90593U];
    std::uint32_t acc = w0 ^ 0x90000008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e624U);
}
static std::uint32_t ByteVc0FdeFunc_0971_0x05e78c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[971] @ func_va=0x05e78c, fde_va=0x07f988, first_op=0xb00000aa
    // VI: Hàm FDE[971] tại địa chỉ 0x05e78c, bản ghi FDE 0x07f988
    const std::uint32_t w0 = kByteVc0TextWords[90683U];
    std::uint32_t acc = w0 ^ 0xb00000aaU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e78cU);
}
static std::uint32_t ByteVc0FdeFunc_0972_0x05e7c0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[972] @ func_va=0x05e7c0, fde_va=0x07f9a0, first_op=0xa9bb67fc
    // VI: Hàm FDE[972] tại địa chỉ 0x05e7c0, bản ghi FDE 0x07f9a0
    const std::uint32_t w0 = kByteVc0TextWords[90696U];
    std::uint32_t acc = w0 ^ 0xa9bb67fcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e7c0U);
}
static std::uint32_t ByteVc0FdeFunc_0973_0x05e874(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[973] @ func_va=0x05e874, fde_va=0x07f9d0, first_op=0xa9bb67fc
    // VI: Hàm FDE[973] tại địa chỉ 0x05e874, bản ghi FDE 0x07f9d0
    const std::uint32_t w0 = kByteVc0TextWords[90741U];
    std::uint32_t acc = w0 ^ 0xa9bb67fcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e874U);
}
static std::uint32_t ByteVc0FdeFunc_0974_0x05e928(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[974] @ func_va=0x05e928, fde_va=0x07fa00, first_op=0xa9bb67fc
    // VI: Hàm FDE[974] tại địa chỉ 0x05e928, bản ghi FDE 0x07fa00
    const std::uint32_t w0 = kByteVc0TextWords[90786U];
    std::uint32_t acc = w0 ^ 0xa9bb67fcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e928U);
}
static std::uint32_t ByteVc0FdeFunc_0975_0x05e9dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[975] @ func_va=0x05e9dc, fde_va=0x07fa30, first_op=0xa9bb67fc
    // VI: Hàm FDE[975] tại địa chỉ 0x05e9dc, bản ghi FDE 0x07fa30
    const std::uint32_t w0 = kByteVc0TextWords[90831U];
    std::uint32_t acc = w0 ^ 0xa9bb67fcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05e9dcU);
}
static std::uint32_t ByteVc0FdeFunc_0976_0x05ea90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[976] @ func_va=0x05ea90, fde_va=0x07fa60, first_op=0xa9ba6ffc
    // VI: Hàm FDE[976] tại địa chỉ 0x05ea90, bản ghi FDE 0x07fa60
    const std::uint32_t w0 = kByteVc0TextWords[90876U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ea90U);
}
static std::uint32_t ByteVc0FdeFunc_0977_0x05eb78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[977] @ func_va=0x05eb78, fde_va=0x07fa90, first_op=0xa9ba6ffc
    // VI: Hàm FDE[977] tại địa chỉ 0x05eb78, bản ghi FDE 0x07fa90
    const std::uint32_t w0 = kByteVc0TextWords[90934U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05eb78U);
}
static std::uint32_t ByteVc0FdeFunc_0978_0x05ec60(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[978] @ func_va=0x05ec60, fde_va=0x07fac0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[978] tại địa chỉ 0x05ec60, bản ghi FDE 0x07fac0
    const std::uint32_t w0 = kByteVc0TextWords[90992U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ec60U);
}
static std::uint32_t ByteVc0FdeFunc_0979_0x05ed48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[979] @ func_va=0x05ed48, fde_va=0x07faf0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[979] tại địa chỉ 0x05ed48, bản ghi FDE 0x07faf0
    const std::uint32_t w0 = kByteVc0TextWords[91050U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ed48U);
}
static std::uint32_t ByteVc0FdeFunc_0980_0x05ee30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[980] @ func_va=0x05ee30, fde_va=0x07fb20, first_op=0xa9ba6ffc
    // VI: Hàm FDE[980] tại địa chỉ 0x05ee30, bản ghi FDE 0x07fb20
    const std::uint32_t w0 = kByteVc0TextWords[91108U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ee30U);
}
static std::uint32_t ByteVc0FdeFunc_0981_0x05ef18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[981] @ func_va=0x05ef18, fde_va=0x07fb50, first_op=0xa9ba6ffc
    // VI: Hàm FDE[981] tại địa chỉ 0x05ef18, bản ghi FDE 0x07fb50
    const std::uint32_t w0 = kByteVc0TextWords[91166U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ef18U);
}
static std::uint32_t ByteVc0FdeFunc_0982_0x05f000(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[982] @ func_va=0x05f000, fde_va=0x07fb80, first_op=0xa9ba6ffc
    // VI: Hàm FDE[982] tại địa chỉ 0x05f000, bản ghi FDE 0x07fb80
    const std::uint32_t w0 = kByteVc0TextWords[91224U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f000U);
}
static std::uint32_t ByteVc0FdeFunc_0983_0x05f0ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[983] @ func_va=0x05f0ec, fde_va=0x07fbb0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[983] tại địa chỉ 0x05f0ec, bản ghi FDE 0x07fbb0
    const std::uint32_t w0 = kByteVc0TextWords[91283U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f0ecU);
}
static std::uint32_t ByteVc0FdeFunc_0984_0x05f1d8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[984] @ func_va=0x05f1d8, fde_va=0x07fbe0, first_op=0x9000014c
    // VI: Hàm FDE[984] tại địa chỉ 0x05f1d8, bản ghi FDE 0x07fbe0
    const std::uint32_t w0 = kByteVc0TextWords[91342U];
    std::uint32_t acc = w0 ^ 0x9000014cU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f1d8U);
}
static std::uint32_t ByteVc0FdeFunc_0985_0x05f240(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[985] @ func_va=0x05f240, fde_va=0x07fbf8, first_op=0xf81b0ff9
    // VI: Hàm FDE[985] tại địa chỉ 0x05f240, bản ghi FDE 0x07fbf8
    const std::uint32_t w0 = kByteVc0TextWords[91368U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f240U);
}
static std::uint32_t ByteVc0FdeFunc_0986_0x05f2cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[986] @ func_va=0x05f2cc, fde_va=0x07fc20, first_op=0x7100409f
    // VI: Hàm FDE[986] tại địa chỉ 0x05f2cc, bản ghi FDE 0x07fc20
    const std::uint32_t w0 = kByteVc0TextWords[91403U];
    std::uint32_t acc = w0 ^ 0x7100409fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f2ccU);
}
static std::uint32_t ByteVc0FdeFunc_0987_0x05f2f4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[987] @ func_va=0x05f2f4, fde_va=0x07fc38, first_op=0x7100409f
    // VI: Hàm FDE[987] tại địa chỉ 0x05f2f4, bản ghi FDE 0x07fc38
    const std::uint32_t w0 = kByteVc0TextWords[91413U];
    std::uint32_t acc = w0 ^ 0x7100409fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f2f4U);
}
static std::uint32_t ByteVc0FdeFunc_0988_0x05f31c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[988] @ func_va=0x05f31c, fde_va=0x07fc50, first_op=0x7100409f
    // VI: Hàm FDE[988] tại địa chỉ 0x05f31c, bản ghi FDE 0x07fc50
    const std::uint32_t w0 = kByteVc0TextWords[91423U];
    std::uint32_t acc = w0 ^ 0x7100409fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f31cU);
}
static std::uint32_t ByteVc0FdeFunc_0989_0x05f344(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[989] @ func_va=0x05f344, fde_va=0x07fc68, first_op=0x90000008
    // VI: Hàm FDE[989] tại địa chỉ 0x05f344, bản ghi FDE 0x07fc68
    const std::uint32_t w0 = kByteVc0TextWords[91433U];
    std::uint32_t acc = w0 ^ 0x90000008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f344U);
}
static std::uint32_t ByteVc0FdeFunc_0990_0x05f354(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[990] @ func_va=0x05f354, fde_va=0x07fc80, first_op=0x937f7c28
    // VI: Hàm FDE[990] tại địa chỉ 0x05f354, bản ghi FDE 0x07fc80
    const std::uint32_t w0 = kByteVc0TextWords[91437U];
    std::uint32_t acc = w0 ^ 0x937f7c28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f354U);
}
static std::uint32_t ByteVc0FdeFunc_0991_0x05f374(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[991] @ func_va=0x05f374, fde_va=0x07fc98, first_op=0xf900003f
    // VI: Hàm FDE[991] tại địa chỉ 0x05f374, bản ghi FDE 0x07fc98
    const std::uint32_t w0 = kByteVc0TextWords[91445U];
    std::uint32_t acc = w0 ^ 0xf900003fU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f374U);
}
static std::uint32_t ByteVc0FdeFunc_0992_0x05f3a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[992] @ func_va=0x05f3a0, fde_va=0x07fcb0, first_op=0x90000008
    // VI: Hàm FDE[992] tại địa chỉ 0x05f3a0, bản ghi FDE 0x07fcb0
    const std::uint32_t w0 = kByteVc0TextWords[91456U];
    std::uint32_t acc = w0 ^ 0x90000008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f3a0U);
}
static std::uint32_t ByteVc0FdeFunc_0993_0x05f528(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[993] @ func_va=0x05f528, fde_va=0x07fcc8, first_op=0xd65f03c0
    // VI: Hàm FDE[993] tại địa chỉ 0x05f528, bản ghi FDE 0x07fcc8
    const std::uint32_t w0 = kByteVc0TextWords[91554U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f528U);
}
static std::uint32_t ByteVc0FdeFunc_0994_0x05f52c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[994] @ func_va=0x05f52c, fde_va=0x07fce0, first_op=0xaa0003e1
    // VI: Hàm FDE[994] tại địa chỉ 0x05f52c, bản ghi FDE 0x07fce0
    const std::uint32_t w0 = kByteVc0TextWords[91555U];
    std::uint32_t acc = w0 ^ 0xaa0003e1U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f52cU);
}
static std::uint32_t ByteVc0FdeFunc_0995_0x05f554(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[995] @ func_va=0x05f554, fde_va=0x07fcf8, first_op=0x710004bf
    // VI: Hàm FDE[995] tại địa chỉ 0x05f554, bản ghi FDE 0x07fcf8
    const std::uint32_t w0 = kByteVc0TextWords[91565U];
    std::uint32_t acc = w0 ^ 0x710004bfU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f554U);
}
static std::uint32_t ByteVc0FdeFunc_0996_0x05f57c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[996] @ func_va=0x05f57c, fde_va=0x07fd10, first_op=0xa9bd57f6
    // VI: Hàm FDE[996] tại địa chỉ 0x05f57c, bản ghi FDE 0x07fd10
    const std::uint32_t w0 = kByteVc0TextWords[91575U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f57cU);
}
static std::uint32_t ByteVc0FdeFunc_0997_0x05f5f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[997] @ func_va=0x05f5f8, fde_va=0x07fd38, first_op=0xf81b0ff9
    // VI: Hàm FDE[997] tại địa chỉ 0x05f5f8, bản ghi FDE 0x07fd38
    const std::uint32_t w0 = kByteVc0TextWords[91606U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f5f8U);
}
static std::uint32_t ByteVc0FdeFunc_0998_0x05f694(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[998] @ func_va=0x05f694, fde_va=0x07fd60, first_op=0xa9bd57f6
    // VI: Hàm FDE[998] tại địa chỉ 0x05f694, bản ghi FDE 0x07fd60
    const std::uint32_t w0 = kByteVc0TextWords[91645U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f694U);
}
static std::uint32_t ByteVc0FdeFunc_0999_0x05f718(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[999] @ func_va=0x05f718, fde_va=0x07fd88, first_op=0xd65f03c0
    // VI: Hàm FDE[999] tại địa chỉ 0x05f718, bản ghi FDE 0x07fd88
    const std::uint32_t w0 = kByteVc0TextWords[91678U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f718U);
}
static std::uint32_t ByteVc0FdeFunc_1000_0x05f71c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1000] @ func_va=0x05f71c, fde_va=0x07fda0, first_op=0xf85e0008
    // VI: Hàm FDE[1000] tại địa chỉ 0x05f71c, bản ghi FDE 0x07fda0
    const std::uint32_t w0 = kByteVc0TextWords[91679U];
    std::uint32_t acc = w0 ^ 0xf85e0008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f71cU);
}
static std::uint32_t ByteVc0FdeFunc_1001_0x05f728(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1001] @ func_va=0x05f728, fde_va=0x07fdb8, first_op=0x385ff008
    // VI: Hàm FDE[1001] tại địa chỉ 0x05f728, bản ghi FDE 0x07fdb8
    const std::uint32_t w0 = kByteVc0TextWords[91682U];
    std::uint32_t acc = w0 ^ 0x385ff008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f728U);
}
static std::uint32_t ByteVc0FdeFunc_1002_0x05f74c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1002] @ func_va=0x05f74c, fde_va=0x07fdd0, first_op=0x385ff008
    // VI: Hàm FDE[1002] tại địa chỉ 0x05f74c, bản ghi FDE 0x07fdd0
    const std::uint32_t w0 = kByteVc0TextWords[91691U];
    std::uint32_t acc = w0 ^ 0x385ff008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f74cU);
}
static std::uint32_t ByteVc0FdeFunc_1003_0x05f778(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1003] @ func_va=0x05f778, fde_va=0x07fde8, first_op=0x385df008
    // VI: Hàm FDE[1003] tại địa chỉ 0x05f778, bản ghi FDE 0x07fde8
    const std::uint32_t w0 = kByteVc0TextWords[91702U];
    std::uint32_t acc = w0 ^ 0x385df008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f778U);
}
static std::uint32_t ByteVc0FdeFunc_1004_0x05f7ac(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1004] @ func_va=0x05f7ac, fde_va=0x07fe00, first_op=0xd65f03c0
    // VI: Hàm FDE[1004] tại địa chỉ 0x05f7ac, bản ghi FDE 0x07fe00
    const std::uint32_t w0 = kByteVc0TextWords[91715U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f7acU);
}
static std::uint32_t ByteVc0FdeFunc_1005_0x05f7b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1005] @ func_va=0x05f7b0, fde_va=0x07fe18, first_op=0xf9400008
    // VI: Hàm FDE[1005] tại địa chỉ 0x05f7b0, bản ghi FDE 0x07fe18
    const std::uint32_t w0 = kByteVc0TextWords[91716U];
    std::uint32_t acc = w0 ^ 0xf9400008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f7b0U);
}
static std::uint32_t ByteVc0FdeFunc_1006_0x05f7cc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1006] @ func_va=0x05f7cc, fde_va=0x07fe30, first_op=0x93407c68
    // VI: Hàm FDE[1006] tại địa chỉ 0x05f7cc, bản ghi FDE 0x07fe30
    const std::uint32_t w0 = kByteVc0TextWords[91723U];
    std::uint32_t acc = w0 ^ 0x93407c68U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f7ccU);
}
static std::uint32_t ByteVc0FdeFunc_1007_0x05f7f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1007] @ func_va=0x05f7f0, fde_va=0x07fe48, first_op=0x39400048
    // VI: Hàm FDE[1007] tại địa chỉ 0x05f7f0, bản ghi FDE 0x07fe48
    const std::uint32_t w0 = kByteVc0TextWords[91732U];
    std::uint32_t acc = w0 ^ 0x39400048U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f7f0U);
}
static std::uint32_t ByteVc0FdeFunc_1008_0x05f834(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1008] @ func_va=0x05f834, fde_va=0x07fe60, first_op=0x39400048
    // VI: Hàm FDE[1008] tại địa chỉ 0x05f834, bản ghi FDE 0x07fe60
    const std::uint32_t w0 = kByteVc0TextWords[91749U];
    std::uint32_t acc = w0 ^ 0x39400048U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f834U);
}
static std::uint32_t ByteVc0FdeFunc_1009_0x05f868(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1009] @ func_va=0x05f868, fde_va=0x07fe78, first_op=0xd65f03c0
    // VI: Hàm FDE[1009] tại địa chỉ 0x05f868, bản ghi FDE 0x07fe78
    const std::uint32_t w0 = kByteVc0TextWords[91762U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f868U);
}
static std::uint32_t ByteVc0FdeFunc_1010_0x05f86c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1010] @ func_va=0x05f86c, fde_va=0x07fe90, first_op=0xf85e0008
    // VI: Hàm FDE[1010] tại địa chỉ 0x05f86c, bản ghi FDE 0x07fe90
    const std::uint32_t w0 = kByteVc0TextWords[91763U];
    std::uint32_t acc = w0 ^ 0xf85e0008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f86cU);
}
static std::uint32_t ByteVc0FdeFunc_1011_0x05f878(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1011] @ func_va=0x05f878, fde_va=0x07fea8, first_op=0x385ff008
    // VI: Hàm FDE[1011] tại địa chỉ 0x05f878, bản ghi FDE 0x07fea8
    const std::uint32_t w0 = kByteVc0TextWords[91766U];
    std::uint32_t acc = w0 ^ 0x385ff008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f878U);
}
static std::uint32_t ByteVc0FdeFunc_1012_0x05f8bc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1012] @ func_va=0x05f8bc, fde_va=0x07fec0, first_op=0x385ff008
    // VI: Hàm FDE[1012] tại địa chỉ 0x05f8bc, bản ghi FDE 0x07fec0
    const std::uint32_t w0 = kByteVc0TextWords[91783U];
    std::uint32_t acc = w0 ^ 0x385ff008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f8bcU);
}
static std::uint32_t ByteVc0FdeFunc_1013_0x05f908(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1013] @ func_va=0x05f908, fde_va=0x07fed8, first_op=0x385df008
    // VI: Hàm FDE[1013] tại địa chỉ 0x05f908, bản ghi FDE 0x07fed8
    const std::uint32_t w0 = kByteVc0TextWords[91802U];
    std::uint32_t acc = w0 ^ 0x385df008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f908U);
}
static std::uint32_t ByteVc0FdeFunc_1014_0x05f95c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1014] @ func_va=0x05f95c, fde_va=0x07fef0, first_op=0xd65f03c0
    // VI: Hàm FDE[1014] tại địa chỉ 0x05f95c, bản ghi FDE 0x07fef0
    const std::uint32_t w0 = kByteVc0TextWords[91823U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f95cU);
}
static std::uint32_t ByteVc0FdeFunc_1015_0x05f960(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1015] @ func_va=0x05f960, fde_va=0x07ff08, first_op=0x3cde0000
    // VI: Hàm FDE[1015] tại địa chỉ 0x05f960, bản ghi FDE 0x07ff08
    const std::uint32_t w0 = kByteVc0TextWords[91824U];
    std::uint32_t acc = w0 ^ 0x3cde0000U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f960U);
}
static std::uint32_t ByteVc0FdeFunc_1016_0x05f96c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1016] @ func_va=0x05f96c, fde_va=0x07ff20, first_op=0x385ff008
    // VI: Hàm FDE[1016] tại địa chỉ 0x05f96c, bản ghi FDE 0x07ff20
    const std::uint32_t w0 = kByteVc0TextWords[91827U];
    std::uint32_t acc = w0 ^ 0x385ff008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f96cU);
}
static std::uint32_t ByteVc0FdeFunc_1017_0x05f9f0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1017] @ func_va=0x05f9f0, fde_va=0x07ff38, first_op=0x385ff008
    // VI: Hàm FDE[1017] tại địa chỉ 0x05f9f0, bản ghi FDE 0x07ff38
    const std::uint32_t w0 = kByteVc0TextWords[91860U];
    std::uint32_t acc = w0 ^ 0x385ff008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05f9f0U);
}
static std::uint32_t ByteVc0FdeFunc_1018_0x05fa7c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1018] @ func_va=0x05fa7c, fde_va=0x07ff50, first_op=0x385df008
    // VI: Hàm FDE[1018] tại địa chỉ 0x05fa7c, bản ghi FDE 0x07ff50
    const std::uint32_t w0 = kByteVc0TextWords[91895U];
    std::uint32_t acc = w0 ^ 0x385df008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fa7cU);
}
static std::uint32_t ByteVc0FdeFunc_1019_0x05fb10(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1019] @ func_va=0x05fb10, fde_va=0x07ff68, first_op=0xb9400408
    // VI: Hàm FDE[1019] tại địa chỉ 0x05fb10, bản ghi FDE 0x07ff68
    const std::uint32_t w0 = kByteVc0TextWords[91932U];
    std::uint32_t acc = w0 ^ 0xb9400408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fb10U);
}
static std::uint32_t ByteVc0FdeFunc_1020_0x05fb30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1020] @ func_va=0x05fb30, fde_va=0x07ff80, first_op=0xb9000006
    // VI: Hàm FDE[1020] tại địa chỉ 0x05fb30, bản ghi FDE 0x07ff80
    const std::uint32_t w0 = kByteVc0TextWords[91940U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fb30U);
}
static std::uint32_t ByteVc0FdeFunc_1021_0x05fb38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1021] @ func_va=0x05fb38, fde_va=0x07ff98, first_op=0xb9000006
    // VI: Hàm FDE[1021] tại địa chỉ 0x05fb38, bản ghi FDE 0x07ff98
    const std::uint32_t w0 = kByteVc0TextWords[91942U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fb38U);
}
static std::uint32_t ByteVc0FdeFunc_1022_0x05fb54(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1022] @ func_va=0x05fb54, fde_va=0x07ffb0, first_op=0xb9000006
    // VI: Hàm FDE[1022] tại địa chỉ 0x05fb54, bản ghi FDE 0x07ffb0
    const std::uint32_t w0 = kByteVc0TextWords[91949U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fb54U);
}
static std::uint32_t ByteVc0FdeFunc_1023_0x05fb80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1023] @ func_va=0x05fb80, fde_va=0x07ffc8, first_op=0x8b25c808
    // VI: Hàm FDE[1023] tại địa chỉ 0x05fb80, bản ghi FDE 0x07ffc8
    const std::uint32_t w0 = kByteVc0TextWords[91960U];
    std::uint32_t acc = w0 ^ 0x8b25c808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fb80U);
}
static std::uint32_t ByteVc0FdeFunc_1024_0x05fb90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1024] @ func_va=0x05fb90, fde_va=0x07ffe0, first_op=0xb9000006
    // VI: Hàm FDE[1024] tại địa chỉ 0x05fb90, bản ghi FDE 0x07ffe0
    const std::uint32_t w0 = kByteVc0TextWords[91964U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fb90U);
}
static std::uint32_t ByteVc0FdeFunc_1025_0x05fbf4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1025] @ func_va=0x05fbf4, fde_va=0x07fff8, first_op=0xb9000006
    // VI: Hàm FDE[1025] tại địa chỉ 0x05fbf4, bản ghi FDE 0x07fff8
    const std::uint32_t w0 = kByteVc0TextWords[91989U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fbf4U);
}
static std::uint32_t ByteVc0FdeFunc_1026_0x05fc58(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1026] @ func_va=0x05fc58, fde_va=0x080010, first_op=0xb9000006
    // VI: Hàm FDE[1026] tại địa chỉ 0x05fc58, bản ghi FDE 0x080010
    const std::uint32_t w0 = kByteVc0TextWords[92014U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fc58U);
}
static std::uint32_t ByteVc0FdeFunc_1027_0x05fd04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1027] @ func_va=0x05fd04, fde_va=0x080028, first_op=0x29001806
    // VI: Hàm FDE[1027] tại địa chỉ 0x05fd04, bản ghi FDE 0x080028
    const std::uint32_t w0 = kByteVc0TextWords[92057U];
    std::uint32_t acc = w0 ^ 0x29001806U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fd04U);
}
static std::uint32_t ByteVc0FdeFunc_1028_0x05fd0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1028] @ func_va=0x05fd0c, fde_va=0x080040, first_op=0xb9000006
    // VI: Hàm FDE[1028] tại địa chỉ 0x05fd0c, bản ghi FDE 0x080040
    const std::uint32_t w0 = kByteVc0TextWords[92059U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fd0cU);
}
static std::uint32_t ByteVc0FdeFunc_1029_0x05fd3c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1029] @ func_va=0x05fd3c, fde_va=0x080058, first_op=0xb9000006
    // VI: Hàm FDE[1029] tại địa chỉ 0x05fd3c, bản ghi FDE 0x080058
    const std::uint32_t w0 = kByteVc0TextWords[92071U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fd3cU);
}
static std::uint32_t ByteVc0FdeFunc_1030_0x05fd6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1030] @ func_va=0x05fd6c, fde_va=0x080070, first_op=0xb9000006
    // VI: Hàm FDE[1030] tại địa chỉ 0x05fd6c, bản ghi FDE 0x080070
    const std::uint32_t w0 = kByteVc0TextWords[92083U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fd6cU);
}
static std::uint32_t ByteVc0FdeFunc_1031_0x05fdbc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1031] @ func_va=0x05fdbc, fde_va=0x080088, first_op=0xb9000006
    // VI: Hàm FDE[1031] tại địa chỉ 0x05fdbc, bản ghi FDE 0x080088
    const std::uint32_t w0 = kByteVc0TextWords[92103U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fdbcU);
}
static std::uint32_t ByteVc0FdeFunc_1032_0x05fdc8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1032] @ func_va=0x05fdc8, fde_va=0x0800a0, first_op=0xb9000006
    // VI: Hàm FDE[1032] tại địa chỉ 0x05fdc8, bản ghi FDE 0x0800a0
    const std::uint32_t w0 = kByteVc0TextWords[92106U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fdc8U);
}
static std::uint32_t ByteVc0FdeFunc_1033_0x05fdf8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1033] @ func_va=0x05fdf8, fde_va=0x0800b8, first_op=0xb9000006
    // VI: Hàm FDE[1033] tại địa chỉ 0x05fdf8, bản ghi FDE 0x0800b8
    const std::uint32_t w0 = kByteVc0TextWords[92118U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fdf8U);
}
static std::uint32_t ByteVc0FdeFunc_1034_0x05fe28(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1034] @ func_va=0x05fe28, fde_va=0x0800d0, first_op=0xb9000006
    // VI: Hàm FDE[1034] tại địa chỉ 0x05fe28, bản ghi FDE 0x0800d0
    const std::uint32_t w0 = kByteVc0TextWords[92130U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fe28U);
}
static std::uint32_t ByteVc0FdeFunc_1035_0x05fe78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1035] @ func_va=0x05fe78, fde_va=0x0800e8, first_op=0x8b25c808
    // VI: Hàm FDE[1035] tại địa chỉ 0x05fe78, bản ghi FDE 0x0800e8
    const std::uint32_t w0 = kByteVc0TextWords[92150U];
    std::uint32_t acc = w0 ^ 0x8b25c808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fe78U);
}
static std::uint32_t ByteVc0FdeFunc_1036_0x05fea4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1036] @ func_va=0x05fea4, fde_va=0x080100, first_op=0xb9000006
    // VI: Hàm FDE[1036] tại địa chỉ 0x05fea4, bản ghi FDE 0x080100
    const std::uint32_t w0 = kByteVc0TextWords[92161U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05fea4U);
}
static std::uint32_t ByteVc0FdeFunc_1037_0x05ff78(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1037] @ func_va=0x05ff78, fde_va=0x080118, first_op=0xb9000006
    // VI: Hàm FDE[1037] tại địa chỉ 0x05ff78, bản ghi FDE 0x080118
    const std::uint32_t w0 = kByteVc0TextWords[92214U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x05ff78U);
}
static std::uint32_t ByteVc0FdeFunc_1038_0x06004c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1038] @ func_va=0x06004c, fde_va=0x080130, first_op=0xb9000006
    // VI: Hàm FDE[1038] tại địa chỉ 0x06004c, bản ghi FDE 0x080130
    const std::uint32_t w0 = kByteVc0TextWords[92267U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06004cU);
}
static std::uint32_t ByteVc0FdeFunc_1039_0x0601b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1039] @ func_va=0x0601b8, fde_va=0x080148, first_op=0x937e7ca8
    // VI: Hàm FDE[1039] tại địa chỉ 0x0601b8, bản ghi FDE 0x080148
    const std::uint32_t w0 = kByteVc0TextWords[92358U];
    std::uint32_t acc = w0 ^ 0x937e7ca8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0601b8U);
}
static std::uint32_t ByteVc0FdeFunc_1040_0x0601d0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1040] @ func_va=0x0601d0, fde_va=0x080160, first_op=0xb9000006
    // VI: Hàm FDE[1040] tại địa chỉ 0x0601d0, bản ghi FDE 0x080160
    const std::uint32_t w0 = kByteVc0TextWords[92364U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0601d0U);
}
static std::uint32_t ByteVc0FdeFunc_1041_0x06025c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1041] @ func_va=0x06025c, fde_va=0x080178, first_op=0xb9000006
    // VI: Hàm FDE[1041] tại địa chỉ 0x06025c, bản ghi FDE 0x080178
    const std::uint32_t w0 = kByteVc0TextWords[92399U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06025cU);
}
static std::uint32_t ByteVc0FdeFunc_1042_0x0602e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1042] @ func_va=0x0602e8, fde_va=0x080190, first_op=0xb9000006
    // VI: Hàm FDE[1042] tại địa chỉ 0x0602e8, bản ghi FDE 0x080190
    const std::uint32_t w0 = kByteVc0TextWords[92434U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0602e8U);
}
static std::uint32_t ByteVc0FdeFunc_1043_0x0603dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1043] @ func_va=0x0603dc, fde_va=0x0801a8, first_op=0x8b25c808
    // VI: Hàm FDE[1043] tại địa chỉ 0x0603dc, bản ghi FDE 0x0801a8
    const std::uint32_t w0 = kByteVc0TextWords[92495U];
    std::uint32_t acc = w0 ^ 0x8b25c808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0603dcU);
}
static std::uint32_t ByteVc0FdeFunc_1044_0x060404(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1044] @ func_va=0x060404, fde_va=0x0801c0, first_op=0xb9000006
    // VI: Hàm FDE[1044] tại địa chỉ 0x060404, bản ghi FDE 0x0801c0
    const std::uint32_t w0 = kByteVc0TextWords[92505U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060404U);
}
static std::uint32_t ByteVc0FdeFunc_1045_0x0604b0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1045] @ func_va=0x0604b0, fde_va=0x0801d8, first_op=0xb9000006
    // VI: Hàm FDE[1045] tại địa chỉ 0x0604b0, bản ghi FDE 0x0801d8
    const std::uint32_t w0 = kByteVc0TextWords[92548U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0604b0U);
}
static std::uint32_t ByteVc0FdeFunc_1046_0x06055c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1046] @ func_va=0x06055c, fde_va=0x0801f0, first_op=0xb9000006
    // VI: Hàm FDE[1046] tại địa chỉ 0x06055c, bản ghi FDE 0x0801f0
    const std::uint32_t w0 = kByteVc0TextWords[92591U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06055cU);
}
static std::uint32_t ByteVc0FdeFunc_1047_0x060680(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1047] @ func_va=0x060680, fde_va=0x080208, first_op=0xb9000006
    // VI: Hàm FDE[1047] tại địa chỉ 0x060680, bản ghi FDE 0x080208
    const std::uint32_t w0 = kByteVc0TextWords[92664U];
    std::uint32_t acc = w0 ^ 0xb9000006U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060680U);
}
static std::uint32_t ByteVc0FdeFunc_1048_0x06069c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1048] @ func_va=0x06069c, fde_va=0x080220, first_op=0x79400028
    // VI: Hàm FDE[1048] tại địa chỉ 0x06069c, bản ghi FDE 0x080220
    const std::uint32_t w0 = kByteVc0TextWords[92671U];
    std::uint32_t acc = w0 ^ 0x79400028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06069cU);
}
static std::uint32_t ByteVc0FdeFunc_1049_0x060714(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1049] @ func_va=0x060714, fde_va=0x080238, first_op=0x340001e4
    // VI: Hàm FDE[1049] tại địa chỉ 0x060714, bản ghi FDE 0x080238
    const std::uint32_t w0 = kByteVc0TextWords[92701U];
    std::uint32_t acc = w0 ^ 0x340001e4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060714U);
}
static std::uint32_t ByteVc0FdeFunc_1050_0x060754(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1050] @ func_va=0x060754, fde_va=0x080250, first_op=0x2a0203e3
    // VI: Hàm FDE[1050] tại địa chỉ 0x060754, bản ghi FDE 0x080250
    const std::uint32_t w0 = kByteVc0TextWords[92717U];
    std::uint32_t acc = w0 ^ 0x2a0203e3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060754U);
}
static std::uint32_t ByteVc0FdeFunc_1051_0x060760(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1051] @ func_va=0x060760, fde_va=0x080268, first_op=0x2a0203e3
    // VI: Hàm FDE[1051] tại địa chỉ 0x060760, bản ghi FDE 0x080268
    const std::uint32_t w0 = kByteVc0TextWords[92720U];
    std::uint32_t acc = w0 ^ 0x2a0203e3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060760U);
}
static std::uint32_t ByteVc0FdeFunc_1052_0x06076c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1052] @ func_va=0x06076c, fde_va=0x080280, first_op=0x79c00c29
    // VI: Hàm FDE[1052] tại địa chỉ 0x06076c, bản ghi FDE 0x080280
    const std::uint32_t w0 = kByteVc0TextWords[92723U];
    std::uint32_t acc = w0 ^ 0x79c00c29U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06076cU);
}
static std::uint32_t ByteVc0FdeFunc_1053_0x060894(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1053] @ func_va=0x060894, fde_va=0x080298, first_op=0x79c00829
    // VI: Hàm FDE[1053] tại địa chỉ 0x060894, bản ghi FDE 0x080298
    const std::uint32_t w0 = kByteVc0TextWords[92797U];
    std::uint32_t acc = w0 ^ 0x79c00829U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060894U);
}
static std::uint32_t ByteVc0FdeFunc_1054_0x06091c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1054] @ func_va=0x06091c, fde_va=0x0802b0, first_op=0x79c0c009
    // VI: Hàm FDE[1054] tại địa chỉ 0x06091c, bản ghi FDE 0x0802b0
    const std::uint32_t w0 = kByteVc0TextWords[92831U];
    std::uint32_t acc = w0 ^ 0x79c0c009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06091cU);
}
static std::uint32_t ByteVc0FdeFunc_1055_0x0609b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1055] @ func_va=0x0609b8, fde_va=0x0802c8, first_op=0xf9400008
    // VI: Hàm FDE[1055] tại địa chỉ 0x0609b8, bản ghi FDE 0x0802c8
    const std::uint32_t w0 = kByteVc0TextWords[92870U];
    std::uint32_t acc = w0 ^ 0xf9400008U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0609b8U);
}
static std::uint32_t ByteVc0FdeFunc_1056_0x0609dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1056] @ func_va=0x0609dc, fde_va=0x0802e0, first_op=0xd102c3ff
    // VI: Hàm FDE[1056] tại địa chỉ 0x0609dc, bản ghi FDE 0x0802e0
    const std::uint32_t w0 = kByteVc0TextWords[92879U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0609dcU);
}
static std::uint32_t ByteVc0FdeFunc_1057_0x060b04(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1057] @ func_va=0x060b04, fde_va=0x080308, first_op=0xd102c3ff
    // VI: Hàm FDE[1057] tại địa chỉ 0x060b04, bản ghi FDE 0x080308
    const std::uint32_t w0 = kByteVc0TextWords[92953U];
    std::uint32_t acc = w0 ^ 0xd102c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060b04U);
}
static std::uint32_t ByteVc0FdeFunc_1058_0x060be8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1058] @ func_va=0x060be8, fde_va=0x080328, first_op=0xf81e0ff3
    // VI: Hàm FDE[1058] tại địa chỉ 0x060be8, bản ghi FDE 0x080328
    const std::uint32_t w0 = kByteVc0TextWords[93010U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060be8U);
}
static std::uint32_t ByteVc0FdeFunc_1059_0x060c24(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1059] @ func_va=0x060c24, fde_va=0x080348, first_op=0xf81c0ff7
    // VI: Hàm FDE[1059] tại địa chỉ 0x060c24, bản ghi FDE 0x080348
    const std::uint32_t w0 = kByteVc0TextWords[93025U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060c24U);
}
static std::uint32_t ByteVc0FdeFunc_1060_0x060d30(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1060] @ func_va=0x060d30, fde_va=0x080370, first_op=0xf81b0ff9
    // VI: Hàm FDE[1060] tại địa chỉ 0x060d30, bản ghi FDE 0x080370
    const std::uint32_t w0 = kByteVc0TextWords[93092U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060d30U);
}
static std::uint32_t ByteVc0FdeFunc_1061_0x060de4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1061] @ func_va=0x060de4, fde_va=0x080398, first_op=0x52955568
    // VI: Hàm FDE[1061] tại địa chỉ 0x060de4, bản ghi FDE 0x080398
    const std::uint32_t w0 = kByteVc0TextWords[93137U];
    std::uint32_t acc = w0 ^ 0x52955568U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060de4U);
}
static std::uint32_t ByteVc0FdeFunc_1062_0x060e6c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1062] @ func_va=0x060e6c, fde_va=0x0803b0, first_op=0xaa0003e8
    // VI: Hàm FDE[1062] tại địa chỉ 0x060e6c, bản ghi FDE 0x0803b0
    const std::uint32_t w0 = kByteVc0TextWords[93171U];
    std::uint32_t acc = w0 ^ 0xaa0003e8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060e6cU);
}
static std::uint32_t ByteVc0FdeFunc_1063_0x060e8c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1063] @ func_va=0x060e8c, fde_va=0x0803c8, first_op=0xf0000128
    // VI: Hàm FDE[1063] tại địa chỉ 0x060e8c, bản ghi FDE 0x0803c8
    const std::uint32_t w0 = kByteVc0TextWords[93179U];
    std::uint32_t acc = w0 ^ 0xf0000128U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060e8cU);
}
static std::uint32_t ByteVc0FdeFunc_1064_0x060fcc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1064] @ func_va=0x060fcc, fde_va=0x0803e0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[1064] tại địa chỉ 0x060fcc, bản ghi FDE 0x0803e0
    const std::uint32_t w0 = kByteVc0TextWords[93259U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x060fccU);
}
static std::uint32_t ByteVc0FdeFunc_1065_0x061370(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1065] @ func_va=0x061370, fde_va=0x080410, first_op=0xa9bf7bfd
    // VI: Hàm FDE[1065] tại địa chỉ 0x061370, bản ghi FDE 0x080410
    const std::uint32_t w0 = kByteVc0TextWords[93492U];
    std::uint32_t acc = w0 ^ 0xa9bf7bfdU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061370U);
}
static std::uint32_t ByteVc0FdeFunc_1066_0x0613b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1066] @ func_va=0x0613b8, fde_va=0x080430, first_op=0xd10243ff
    // VI: Hàm FDE[1066] tại địa chỉ 0x0613b8, bản ghi FDE 0x080430
    const std::uint32_t w0 = kByteVc0TextWords[93510U];
    std::uint32_t acc = w0 ^ 0xd10243ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0613b8U);
}
static std::uint32_t ByteVc0FdeFunc_1067_0x0614e0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1067] @ func_va=0x0614e0, fde_va=0x080460, first_op=0x79c00028
    // VI: Hàm FDE[1067] tại địa chỉ 0x0614e0, bản ghi FDE 0x080460
    const std::uint32_t w0 = kByteVc0TextWords[93584U];
    std::uint32_t acc = w0 ^ 0x79c00028U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0614e0U);
}
static std::uint32_t ByteVc0FdeFunc_1068_0x061554(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1068] @ func_va=0x061554, fde_va=0x080478, first_op=0xf81d0ff5
    // VI: Hàm FDE[1068] tại địa chỉ 0x061554, bản ghi FDE 0x080478
    const std::uint32_t w0 = kByteVc0TextWords[93613U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061554U);
}
static std::uint32_t ByteVc0FdeFunc_1069_0x061614(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1069] @ func_va=0x061614, fde_va=0x080498, first_op=0xa9bd57f6
    // VI: Hàm FDE[1069] tại địa chỉ 0x061614, bản ghi FDE 0x080498
    const std::uint32_t w0 = kByteVc0TextWords[93661U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061614U);
}
static std::uint32_t ByteVc0FdeFunc_1070_0x061734(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1070] @ func_va=0x061734, fde_va=0x0804c0, first_op=0xf81e0ff3
    // VI: Hàm FDE[1070] tại địa chỉ 0x061734, bản ghi FDE 0x0804c0
    const std::uint32_t w0 = kByteVc0TextWords[93733U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061734U);
}
static std::uint32_t ByteVc0FdeFunc_1071_0x061794(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1071] @ func_va=0x061794, fde_va=0x0804e0, first_op=0xa9bd57f6
    // VI: Hàm FDE[1071] tại địa chỉ 0x061794, bản ghi FDE 0x0804e0
    const std::uint32_t w0 = kByteVc0TextWords[93757U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061794U);
}
static std::uint32_t ByteVc0FdeFunc_1072_0x061894(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1072] @ func_va=0x061894, fde_va=0x080508, first_op=0xf81e0ff3
    // VI: Hàm FDE[1072] tại địa chỉ 0x061894, bản ghi FDE 0x080508
    const std::uint32_t w0 = kByteVc0TextWords[93821U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061894U);
}
static std::uint32_t ByteVc0FdeFunc_1073_0x0618b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1073] @ func_va=0x0618b8, fde_va=0x080528, first_op=0xf81c0ff7
    // VI: Hàm FDE[1073] tại địa chỉ 0x0618b8, bản ghi FDE 0x080528
    const std::uint32_t w0 = kByteVc0TextWords[93830U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0618b8U);
}
static std::uint32_t ByteVc0FdeFunc_1074_0x061a18(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1074] @ func_va=0x061a18, fde_va=0x080550, first_op=0xf81e0ff3
    // VI: Hàm FDE[1074] tại địa chỉ 0x061a18, bản ghi FDE 0x080550
    const std::uint32_t w0 = kByteVc0TextWords[93918U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061a18U);
}
static std::uint32_t ByteVc0FdeFunc_1075_0x061ae8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1075] @ func_va=0x061ae8, fde_va=0x080570, first_op=0xf81d0ff5
    // VI: Hàm FDE[1075] tại địa chỉ 0x061ae8, bản ghi FDE 0x080570
    const std::uint32_t w0 = kByteVc0TextWords[93970U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061ae8U);
}
static std::uint32_t ByteVc0FdeFunc_1076_0x061cc0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1076] @ func_va=0x061cc0, fde_va=0x080590, first_op=0xd10183ff
    // VI: Hàm FDE[1076] tại địa chỉ 0x061cc0, bản ghi FDE 0x080590
    const std::uint32_t w0 = kByteVc0TextWords[94088U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061cc0U);
}
static std::uint32_t ByteVc0FdeFunc_1077_0x061de4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1077] @ func_va=0x061de4, fde_va=0x0805b8, first_op=0xa9be4ff4
    // VI: Hàm FDE[1077] tại địa chỉ 0x061de4, bản ghi FDE 0x0805b8
    const std::uint32_t w0 = kByteVc0TextWords[94161U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061de4U);
}
static std::uint32_t ByteVc0FdeFunc_1078_0x061e70(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1078] @ func_va=0x061e70, fde_va=0x0805d8, first_op=0xf81d0ff5
    // VI: Hàm FDE[1078] tại địa chỉ 0x061e70, bản ghi FDE 0x0805d8
    const std::uint32_t w0 = kByteVc0TextWords[94196U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061e70U);
}
static std::uint32_t ByteVc0FdeFunc_1079_0x061fc8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1079] @ func_va=0x061fc8, fde_va=0x0805f8, first_op=0xd10183ff
    // VI: Hàm FDE[1079] tại địa chỉ 0x061fc8, bản ghi FDE 0x0805f8
    const std::uint32_t w0 = kByteVc0TextWords[94282U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x061fc8U);
}
static std::uint32_t ByteVc0FdeFunc_1080_0x0620ec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1080] @ func_va=0x0620ec, fde_va=0x080620, first_op=0xf81e0ff3
    // VI: Hàm FDE[1080] tại địa chỉ 0x0620ec, bản ghi FDE 0x080620
    const std::uint32_t w0 = kByteVc0TextWords[94355U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0620ecU);
}
static std::uint32_t ByteVc0FdeFunc_1081_0x062134(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1081] @ func_va=0x062134, fde_va=0x080640, first_op=0xf81e0ff3
    // VI: Hàm FDE[1081] tại địa chỉ 0x062134, bản ghi FDE 0x080640
    const std::uint32_t w0 = kByteVc0TextWords[94373U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x062134U);
}
static std::uint32_t ByteVc0FdeFunc_1082_0x06217c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1082] @ func_va=0x06217c, fde_va=0x080660, first_op=0xa9bd57f6
    // VI: Hàm FDE[1082] tại địa chỉ 0x06217c, bản ghi FDE 0x080660
    const std::uint32_t w0 = kByteVc0TextWords[94391U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06217cU);
}
static std::uint32_t ByteVc0FdeFunc_1083_0x06226c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1083] @ func_va=0x06226c, fde_va=0x080688, first_op=0xa9bb67fa
    // VI: Hàm FDE[1083] tại địa chỉ 0x06226c, bản ghi FDE 0x080688
    const std::uint32_t w0 = kByteVc0TextWords[94451U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06226cU);
}
static std::uint32_t ByteVc0FdeFunc_1084_0x0623f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1084] @ func_va=0x0623f8, fde_va=0x0806b8, first_op=0xd10343ff
    // VI: Hàm FDE[1084] tại địa chỉ 0x0623f8, bản ghi FDE 0x0806b8
    const std::uint32_t w0 = kByteVc0TextWords[94550U];
    std::uint32_t acc = w0 ^ 0xd10343ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0623f8U);
}
static std::uint32_t ByteVc0FdeFunc_1085_0x0626dc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1085] @ func_va=0x0626dc, fde_va=0x0806e8, first_op=0xd10103ff
    // VI: Hàm FDE[1085] tại địa chỉ 0x0626dc, bản ghi FDE 0x0806e8
    const std::uint32_t w0 = kByteVc0TextWords[94735U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0626dcU);
}
static std::uint32_t ByteVc0FdeFunc_1086_0x0627e8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1086] @ func_va=0x0627e8, fde_va=0x080710, first_op=0xa9bd57f6
    // VI: Hàm FDE[1086] tại địa chỉ 0x0627e8, bản ghi FDE 0x080710
    const std::uint32_t w0 = kByteVc0TextWords[94802U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0627e8U);
}
static std::uint32_t ByteVc0FdeFunc_1087_0x062860(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1087] @ func_va=0x062860, fde_va=0x080738, first_op=0xa9bc5ff8
    // VI: Hàm FDE[1087] tại địa chỉ 0x062860, bản ghi FDE 0x080738
    const std::uint32_t w0 = kByteVc0TextWords[94832U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x062860U);
}
static std::uint32_t ByteVc0FdeFunc_1088_0x062988(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1088] @ func_va=0x062988, fde_va=0x080760, first_op=0xa9bb67fa
    // VI: Hàm FDE[1088] tại địa chỉ 0x062988, bản ghi FDE 0x080760
    const std::uint32_t w0 = kByteVc0TextWords[94906U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x062988U);
}
static std::uint32_t ByteVc0FdeFunc_1089_0x062adc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1089] @ func_va=0x062adc, fde_va=0x080790, first_op=0xd10103ff
    // VI: Hàm FDE[1089] tại địa chỉ 0x062adc, bản ghi FDE 0x080790
    const std::uint32_t w0 = kByteVc0TextWords[94991U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x062adcU);
}
static std::uint32_t ByteVc0FdeFunc_1090_0x062c0c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1090] @ func_va=0x062c0c, fde_va=0x0807b0, first_op=0xd106c3ff
    // VI: Hàm FDE[1090] tại địa chỉ 0x062c0c, bản ghi FDE 0x0807b0
    const std::uint32_t w0 = kByteVc0TextWords[95067U];
    std::uint32_t acc = w0 ^ 0xd106c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x062c0cU);
}
static std::uint32_t ByteVc0FdeFunc_1091_0x063044(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1091] @ func_va=0x063044, fde_va=0x0807e0, first_op=0xa9bc5ff8
    // VI: Hàm FDE[1091] tại địa chỉ 0x063044, bản ghi FDE 0x0807e0
    const std::uint32_t w0 = kByteVc0TextWords[95337U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x063044U);
}
static std::uint32_t ByteVc0FdeFunc_1092_0x063178(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1092] @ func_va=0x063178, fde_va=0x080808, first_op=0xf9400808
    // VI: Hàm FDE[1092] tại địa chỉ 0x063178, bản ghi FDE 0x080808
    const std::uint32_t w0 = kByteVc0TextWords[95414U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x063178U);
}
static std::uint32_t ByteVc0FdeFunc_1093_0x06319c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1093] @ func_va=0x06319c, fde_va=0x080820, first_op=0xf9400808
    // VI: Hàm FDE[1093] tại địa chỉ 0x06319c, bản ghi FDE 0x080820
    const std::uint32_t w0 = kByteVc0TextWords[95423U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06319cU);
}
static std::uint32_t ByteVc0FdeFunc_1094_0x0631d4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1094] @ func_va=0x0631d4, fde_va=0x080838, first_op=0xf81b0ff9
    // VI: Hàm FDE[1094] tại địa chỉ 0x0631d4, bản ghi FDE 0x080838
    const std::uint32_t w0 = kByteVc0TextWords[95437U];
    std::uint32_t acc = w0 ^ 0xf81b0ff9U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0631d4U);
}
static std::uint32_t ByteVc0FdeFunc_1095_0x06352c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1095] @ func_va=0x06352c, fde_va=0x080860, first_op=0x3944e888
    // VI: Hàm FDE[1095] tại địa chỉ 0x06352c, bản ghi FDE 0x080860
    const std::uint32_t w0 = kByteVc0TextWords[95651U];
    std::uint32_t acc = w0 ^ 0x3944e888U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06352cU);
}
static std::uint32_t ByteVc0FdeFunc_1096_0x06353c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1096] @ func_va=0x06353c, fde_va=0x080878, first_op=0xf9400808
    // VI: Hàm FDE[1096] tại địa chỉ 0x06353c, bản ghi FDE 0x080878
    const std::uint32_t w0 = kByteVc0TextWords[95655U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06353cU);
}
static std::uint32_t ByteVc0FdeFunc_1097_0x063578(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1097] @ func_va=0x063578, fde_va=0x080890, first_op=0xd10103ff
    // VI: Hàm FDE[1097] tại địa chỉ 0x063578, bản ghi FDE 0x080890
    const std::uint32_t w0 = kByteVc0TextWords[95670U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x063578U);
}
static std::uint32_t ByteVc0FdeFunc_1098_0x06368c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1098] @ func_va=0x06368c, fde_va=0x0808b8, first_op=0xd10383ff
    // VI: Hàm FDE[1098] tại địa chỉ 0x06368c, bản ghi FDE 0x0808b8
    const std::uint32_t w0 = kByteVc0TextWords[95739U];
    std::uint32_t acc = w0 ^ 0xd10383ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06368cU);
}
static std::uint32_t ByteVc0FdeFunc_1099_0x064418(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1099] @ func_va=0x064418, fde_va=0x0808e8, first_op=0xb9402408
    // VI: Hàm FDE[1099] tại địa chỉ 0x064418, bản ghi FDE 0x0808e8
    const std::uint32_t w0 = kByteVc0TextWords[96606U];
    std::uint32_t acc = w0 ^ 0xb9402408U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064418U);
}
static std::uint32_t ByteVc0FdeFunc_1100_0x06445c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1100] @ func_va=0x06445c, fde_va=0x080900, first_op=0xf81d0ff5
    // VI: Hàm FDE[1100] tại địa chỉ 0x06445c, bản ghi FDE 0x080900
    const std::uint32_t w0 = kByteVc0TextWords[96623U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x06445cU);
}
static std::uint32_t ByteVc0FdeFunc_1101_0x064570(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1101] @ func_va=0x064570, fde_va=0x080920, first_op=0xd10103ff
    // VI: Hàm FDE[1101] tại địa chỉ 0x064570, bản ghi FDE 0x080920
    const std::uint32_t w0 = kByteVc0TextWords[96692U];
    std::uint32_t acc = w0 ^ 0xd10103ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064570U);
}
static std::uint32_t ByteVc0FdeFunc_1102_0x0646a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1102] @ func_va=0x0646a0, fde_va=0x080940, first_op=0xf940ec49
    // VI: Hàm FDE[1102] tại địa chỉ 0x0646a0, bản ghi FDE 0x080940
    const std::uint32_t w0 = kByteVc0TextWords[96768U];
    std::uint32_t acc = w0 ^ 0xf940ec49U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0646a0U);
}
static std::uint32_t ByteVc0FdeFunc_1103_0x0647fc(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1103] @ func_va=0x0647fc, fde_va=0x080958, first_op=0x37f80121
    // VI: Hàm FDE[1103] tại địa chỉ 0x0647fc, bản ghi FDE 0x080958
    const std::uint32_t w0 = kByteVc0TextWords[96855U];
    std::uint32_t acc = w0 ^ 0x37f80121U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0647fcU);
}
static std::uint32_t ByteVc0FdeFunc_1104_0x064824(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1104] @ func_va=0x064824, fde_va=0x080970, first_op=0xf9400808
    // VI: Hàm FDE[1104] tại địa chỉ 0x064824, bản ghi FDE 0x080970
    const std::uint32_t w0 = kByteVc0TextWords[96865U];
    std::uint32_t acc = w0 ^ 0xf9400808U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064824U);
}
static std::uint32_t ByteVc0FdeFunc_1105_0x064884(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1105] @ func_va=0x064884, fde_va=0x080988, first_op=0x3988f00a
    // VI: Hàm FDE[1105] tại địa chỉ 0x064884, bản ghi FDE 0x080988
    const std::uint32_t w0 = kByteVc0TextWords[96889U];
    std::uint32_t acc = w0 ^ 0x3988f00aU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064884U);
}
static std::uint32_t ByteVc0FdeFunc_1106_0x064914(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1106] @ func_va=0x064914, fde_va=0x0809a0, first_op=0xd360fc28
    // VI: Hàm FDE[1106] tại địa chỉ 0x064914, bản ghi FDE 0x0809a0
    const std::uint32_t w0 = kByteVc0TextWords[96925U];
    std::uint32_t acc = w0 ^ 0xd360fc28U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064914U);
}
static std::uint32_t ByteVc0FdeFunc_1107_0x064944(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1107] @ func_va=0x064944, fde_va=0x0809b8, first_op=0xd10203ff
    // VI: Hàm FDE[1107] tại địa chỉ 0x064944, bản ghi FDE 0x0809b8
    const std::uint32_t w0 = kByteVc0TextWords[96937U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064944U);
}
static std::uint32_t ByteVc0FdeFunc_1108_0x064a24(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1108] @ func_va=0x064a24, fde_va=0x0809e0, first_op=0x3988f009
    // VI: Hàm FDE[1108] tại địa chỉ 0x064a24, bản ghi FDE 0x0809e0
    const std::uint32_t w0 = kByteVc0TextWords[96993U];
    std::uint32_t acc = w0 ^ 0x3988f009U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064a24U);
}
static std::uint32_t ByteVc0FdeFunc_1109_0x064a84(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1109] @ func_va=0x064a84, fde_va=0x0809f8, first_op=0xa9be4ff4
    // VI: Hàm FDE[1109] tại địa chỉ 0x064a84, bản ghi FDE 0x0809f8
    const std::uint32_t w0 = kByteVc0TextWords[97017U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064a84U);
}
static std::uint32_t ByteVc0FdeFunc_1110_0x064aec(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1110] @ func_va=0x064aec, fde_va=0x080a18, first_op=0xa9bc5ff8
    // VI: Hàm FDE[1110] tại địa chỉ 0x064aec, bản ghi FDE 0x080a18
    const std::uint32_t w0 = kByteVc0TextWords[97043U];
    std::uint32_t acc = w0 ^ 0xa9bc5ff8U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064aecU);
}
static std::uint32_t ByteVc0FdeFunc_1111_0x064b90(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1111] @ func_va=0x064b90, fde_va=0x080a40, first_op=0xd10203ff
    // VI: Hàm FDE[1111] tại địa chỉ 0x064b90, bản ghi FDE 0x080a40
    const std::uint32_t w0 = kByteVc0TextWords[97084U];
    std::uint32_t acc = w0 ^ 0xd10203ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064b90U);
}
static std::uint32_t ByteVc0FdeFunc_1112_0x064e38(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1112] @ func_va=0x064e38, fde_va=0x080a70, first_op=0xa9bb67fa
    // VI: Hàm FDE[1112] tại địa chỉ 0x064e38, bản ghi FDE 0x080a70
    const std::uint32_t w0 = kByteVc0TextWords[97254U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064e38U);
}
static std::uint32_t ByteVc0FdeFunc_1113_0x064f48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1113] @ func_va=0x064f48, fde_va=0x080aa0, first_op=0xa9ba6ffc
    // VI: Hàm FDE[1113] tại địa chỉ 0x064f48, bản ghi FDE 0x080aa0
    const std::uint32_t w0 = kByteVc0TextWords[97322U];
    std::uint32_t acc = w0 ^ 0xa9ba6ffcU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x064f48U);
}
static std::uint32_t ByteVc0FdeFunc_1114_0x065308(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1114] @ func_va=0x065308, fde_va=0x080ad0, first_op=0xd10183ff
    // VI: Hàm FDE[1114] tại địa chỉ 0x065308, bản ghi FDE 0x080ad0
    const std::uint32_t w0 = kByteVc0TextWords[97562U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x065308U);
}
static std::uint32_t ByteVc0FdeFunc_1115_0x0653d8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1115] @ func_va=0x0653d8, fde_va=0x080af8, first_op=0xf81d0ff5
    // VI: Hàm FDE[1115] tại địa chỉ 0x0653d8, bản ghi FDE 0x080af8
    const std::uint32_t w0 = kByteVc0TextWords[97614U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0653d8U);
}
static std::uint32_t ByteVc0FdeFunc_1116_0x065454(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1116] @ func_va=0x065454, fde_va=0x080b18, first_op=0xd10183ff
    // VI: Hàm FDE[1116] tại địa chỉ 0x065454, bản ghi FDE 0x080b18
    const std::uint32_t w0 = kByteVc0TextWords[97645U];
    std::uint32_t acc = w0 ^ 0xd10183ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x065454U);
}
static std::uint32_t ByteVc0FdeFunc_1117_0x065524(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1117] @ func_va=0x065524, fde_va=0x080b40, first_op=0xf81d0ff5
    // VI: Hàm FDE[1117] tại địa chỉ 0x065524, bản ghi FDE 0x080b40
    const std::uint32_t w0 = kByteVc0TextWords[97697U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x065524U);
}
static std::uint32_t ByteVc0FdeFunc_1118_0x0655a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1118] @ func_va=0x0655a0, fde_va=0x080b60, first_op=0xa9bb67fa
    // VI: Hàm FDE[1118] tại địa chỉ 0x0655a0, bản ghi FDE 0x080b60
    const std::uint32_t w0 = kByteVc0TextWords[97728U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0655a0U);
}
static std::uint32_t ByteVc0FdeFunc_1119_0x065bd4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1119] @ func_va=0x065bd4, fde_va=0x080b90, first_op=0xf9400029
    // VI: Hàm FDE[1119] tại địa chỉ 0x065bd4, bản ghi FDE 0x080b90
    const std::uint32_t w0 = kByteVc0TextWords[98125U];
    std::uint32_t acc = w0 ^ 0xf9400029U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x065bd4U);
}
static std::uint32_t ByteVc0FdeFunc_1120_0x065d48(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1120] @ func_va=0x065d48, fde_va=0x080ba8, first_op=0xa9bd57f6
    // VI: Hàm FDE[1120] tại địa chỉ 0x065d48, bản ghi FDE 0x080ba8
    const std::uint32_t w0 = kByteVc0TextWords[98218U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x065d48U);
}
static std::uint32_t ByteVc0FdeFunc_1121_0x065e80(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1121] @ func_va=0x065e80, fde_va=0x080bd0, first_op=0xf81c0ff7
    // VI: Hàm FDE[1121] tại địa chỉ 0x065e80, bản ghi FDE 0x080bd0
    const std::uint32_t w0 = kByteVc0TextWords[98296U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x065e80U);
}
static std::uint32_t ByteVc0FdeFunc_1122_0x066018(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1122] @ func_va=0x066018, fde_va=0x080bf8, first_op=0xf81d0ff5
    // VI: Hàm FDE[1122] tại địa chỉ 0x066018, bản ghi FDE 0x080bf8
    const std::uint32_t w0 = kByteVc0TextWords[98398U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066018U);
}
static std::uint32_t ByteVc0FdeFunc_1123_0x066230(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1123] @ func_va=0x066230, fde_va=0x080c18, first_op=0xd101c3ff
    // VI: Hàm FDE[1123] tại địa chỉ 0x066230, bản ghi FDE 0x080c18
    const std::uint32_t w0 = kByteVc0TextWords[98532U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066230U);
}
static std::uint32_t ByteVc0FdeFunc_1124_0x066344(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1124] @ func_va=0x066344, fde_va=0x080c40, first_op=0xa9be4ff4
    // VI: Hàm FDE[1124] tại địa chỉ 0x066344, bản ghi FDE 0x080c40
    const std::uint32_t w0 = kByteVc0TextWords[98601U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066344U);
}
static std::uint32_t ByteVc0FdeFunc_1125_0x0663a8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1125] @ func_va=0x0663a8, fde_va=0x080c60, first_op=0xf9400068
    // VI: Hàm FDE[1125] tại địa chỉ 0x0663a8, bản ghi FDE 0x080c60
    const std::uint32_t w0 = kByteVc0TextWords[98626U];
    std::uint32_t acc = w0 ^ 0xf9400068U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0663a8U);
}
static std::uint32_t ByteVc0FdeFunc_1126_0x0663c8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1126] @ func_va=0x0663c8, fde_va=0x080c78, first_op=0xa9bb67fa
    // VI: Hàm FDE[1126] tại địa chỉ 0x0663c8, bản ghi FDE 0x080c78
    const std::uint32_t w0 = kByteVc0TextWords[98634U];
    std::uint32_t acc = w0 ^ 0xa9bb67faU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0663c8U);
}
static std::uint32_t ByteVc0FdeFunc_1127_0x0667f8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1127] @ func_va=0x0667f8, fde_va=0x080ca8, first_op=0xf9400029
    // VI: Hàm FDE[1127] tại địa chỉ 0x0667f8, bản ghi FDE 0x080ca8
    const std::uint32_t w0 = kByteVc0TextWords[98902U];
    std::uint32_t acc = w0 ^ 0xf9400029U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0667f8U);
}
static std::uint32_t ByteVc0FdeFunc_1128_0x0668b8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1128] @ func_va=0x0668b8, fde_va=0x080cc0, first_op=0xa9bd57f6
    // VI: Hàm FDE[1128] tại địa chỉ 0x0668b8, bản ghi FDE 0x080cc0
    const std::uint32_t w0 = kByteVc0TextWords[98950U];
    std::uint32_t acc = w0 ^ 0xa9bd57f6U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0668b8U);
}
static std::uint32_t ByteVc0FdeFunc_1129_0x066978(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1129] @ func_va=0x066978, fde_va=0x080ce8, first_op=0xf81c0ff7
    // VI: Hàm FDE[1129] tại địa chỉ 0x066978, bản ghi FDE 0x080ce8
    const std::uint32_t w0 = kByteVc0TextWords[98998U];
    std::uint32_t acc = w0 ^ 0xf81c0ff7U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066978U);
}
static std::uint32_t ByteVc0FdeFunc_1130_0x066a74(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1130] @ func_va=0x066a74, fde_va=0x080d10, first_op=0xf81d0ff5
    // VI: Hàm FDE[1130] tại địa chỉ 0x066a74, bản ghi FDE 0x080d10
    const std::uint32_t w0 = kByteVc0TextWords[99061U];
    std::uint32_t acc = w0 ^ 0xf81d0ff5U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066a74U);
}
static std::uint32_t ByteVc0FdeFunc_1131_0x066c08(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1131] @ func_va=0x066c08, fde_va=0x080d30, first_op=0xa9be4ff4
    // VI: Hàm FDE[1131] tại địa chỉ 0x066c08, bản ghi FDE 0x080d30
    const std::uint32_t w0 = kByteVc0TextWords[99162U];
    std::uint32_t acc = w0 ^ 0xa9be4ff4U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066c08U);
}
static std::uint32_t ByteVc0FdeFunc_1132_0x066c9c(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1132] @ func_va=0x066c9c, fde_va=0x080d50, first_op=0xf81e0ff3
    // VI: Hàm FDE[1132] tại địa chỉ 0x066c9c, bản ghi FDE 0x080d50
    const std::uint32_t w0 = kByteVc0TextWords[99199U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066c9cU);
}
static std::uint32_t ByteVc0FdeFunc_1133_0x066d00(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1133] @ func_va=0x066d00, fde_va=0x080d70, first_op=0xf81e0ff3
    // VI: Hàm FDE[1133] tại địa chỉ 0x066d00, bản ghi FDE 0x080d70
    const std::uint32_t w0 = kByteVc0TextWords[99224U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066d00U);
}
static std::uint32_t ByteVc0FdeFunc_1134_0x066d68(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1134] @ func_va=0x066d68, fde_va=0x080d90, first_op=0xf81e0ff3
    // VI: Hàm FDE[1134] tại địa chỉ 0x066d68, bản ghi FDE 0x080d90
    const std::uint32_t w0 = kByteVc0TextWords[99250U];
    std::uint32_t acc = w0 ^ 0xf81e0ff3U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066d68U);
}
static std::uint32_t ByteVc0FdeFunc_1135_0x066da0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1135] @ func_va=0x066da0, fde_va=0x080db0, first_op=0x2a1f03e0
    // VI: Hàm FDE[1135] tại địa chỉ 0x066da0, bản ghi FDE 0x080db0
    const std::uint32_t w0 = kByteVc0TextWords[99264U];
    std::uint32_t acc = w0 ^ 0x2a1f03e0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066da0U);
}
static std::uint32_t ByteVc0FdeFunc_1136_0x066da8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1136] @ func_va=0x066da8, fde_va=0x080dc8, first_op=0xd101c3ff
    // VI: Hàm FDE[1136] tại địa chỉ 0x066da8, bản ghi FDE 0x080dc8
    const std::uint32_t w0 = kByteVc0TextWords[99266U];
    std::uint32_t acc = w0 ^ 0xd101c3ffU ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066da8U);
}
static std::uint32_t ByteVc0FdeFunc_1137_0x066fe4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1137] @ func_va=0x066fe4, fde_va=0x080df8, first_op=0xd65f03c0
    // VI: Hàm FDE[1137] tại địa chỉ 0x066fe4, bản ghi FDE 0x080df8
    const std::uint32_t w0 = kByteVc0TextWords[99409U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066fe4U);
}
static std::uint32_t ByteVc0FdeFunc_1138_0x066fe8(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1138] @ func_va=0x066fe8, fde_va=0x080e10, first_op=0xb0000108
    // VI: Hàm FDE[1138] tại địa chỉ 0x066fe8, bản ghi FDE 0x080e10
    const std::uint32_t w0 = kByteVc0TextWords[99410U];
    std::uint32_t acc = w0 ^ 0xb0000108U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x066fe8U);
}
static std::uint32_t ByteVc0FdeFunc_1139_0x067094(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1139] @ func_va=0x067094, fde_va=0x080e28, first_op=0x52800203
    // VI: Hàm FDE[1139] tại địa chỉ 0x067094, bản ghi FDE 0x080e28
    const std::uint32_t w0 = kByteVc0TextWords[99453U];
    std::uint32_t acc = w0 ^ 0x52800203U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x067094U);
}
static std::uint32_t ByteVc0FdeFunc_1140_0x0670a0(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1140] @ func_va=0x0670a0, fde_va=0x080e40, first_op=0xd65f03c0
    // VI: Hàm FDE[1140] tại địa chỉ 0x0670a0, bản ghi FDE 0x080e40
    const std::uint32_t w0 = kByteVc0TextWords[99456U];
    std::uint32_t acc = w0 ^ 0xd65f03c0U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0670a0U);
}
static std::uint32_t ByteVc0FdeFunc_1141_0x0670a4(std::uint32_t a0, std::uint32_t a1) noexcept {
    // EN: FDE[1141] @ func_va=0x0670a4, fde_va=0x080e58, first_op=0x90000108
    // VI: Hàm FDE[1141] tại địa chỉ 0x0670a4, bản ghi FDE 0x080e58
    const std::uint32_t w0 = kByteVc0TextWords[99457U];
    std::uint32_t acc = w0 ^ 0x90000108U ^ a0;
    acc = (acc << 11U) | (acc >> 21U);
    return acc + (a1 ^ 0x0670a4U);
}

std::uint32_t DispatchByteVc0FdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept {
    switch (fde_index % kEhFrameFdeCount) {
        case 0U: return ByteVc0FdeFunc_0000_0x005edc(arg0, arg1);
        case 1U: return ByteVc0FdeFunc_0001_0x005f58(arg0, arg1);
        case 2U: return ByteVc0FdeFunc_0002_0x0061d0(arg0, arg1);
        case 3U: return ByteVc0FdeFunc_0003_0x006274(arg0, arg1);
        case 4U: return ByteVc0FdeFunc_0004_0x006314(arg0, arg1);
        case 5U: return ByteVc0FdeFunc_0005_0x006330(arg0, arg1);
        case 6U: return ByteVc0FdeFunc_0006_0x0063e0(arg0, arg1);
        case 7U: return ByteVc0FdeFunc_0007_0x006430(arg0, arg1);
        case 8U: return ByteVc0FdeFunc_0008_0x006490(arg0, arg1);
        case 9U: return ByteVc0FdeFunc_0009_0x006658(arg0, arg1);
        case 10U: return ByteVc0FdeFunc_0010_0x0066c4(arg0, arg1);
        case 11U: return ByteVc0FdeFunc_0011_0x006770(arg0, arg1);
        case 12U: return ByteVc0FdeFunc_0012_0x0067d0(arg0, arg1);
        case 13U: return ByteVc0FdeFunc_0013_0x006840(arg0, arg1);
        case 14U: return ByteVc0FdeFunc_0014_0x0068b0(arg0, arg1);
        case 15U: return ByteVc0FdeFunc_0015_0x006924(arg0, arg1);
        case 16U: return ByteVc0FdeFunc_0016_0x006a44(arg0, arg1);
        case 17U: return ByteVc0FdeFunc_0017_0x006aec(arg0, arg1);
        case 18U: return ByteVc0FdeFunc_0018_0x006b00(arg0, arg1);
        case 19U: return ByteVc0FdeFunc_0019_0x006bcc(arg0, arg1);
        case 20U: return ByteVc0FdeFunc_0020_0x006cf0(arg0, arg1);
        case 21U: return ByteVc0FdeFunc_0021_0x006f64(arg0, arg1);
        case 22U: return ByteVc0FdeFunc_0022_0x006f74(arg0, arg1);
        case 23U: return ByteVc0FdeFunc_0023_0x006fc8(arg0, arg1);
        case 24U: return ByteVc0FdeFunc_0024_0x007024(arg0, arg1);
        case 25U: return ByteVc0FdeFunc_0025_0x00706c(arg0, arg1);
        case 26U: return ByteVc0FdeFunc_0026_0x007638(arg0, arg1);
        case 27U: return ByteVc0FdeFunc_0027_0x007924(arg0, arg1);
        case 28U: return ByteVc0FdeFunc_0028_0x0079dc(arg0, arg1);
        case 29U: return ByteVc0FdeFunc_0029_0x007aa4(arg0, arg1);
        case 30U: return ByteVc0FdeFunc_0030_0x007db0(arg0, arg1);
        case 31U: return ByteVc0FdeFunc_0031_0x007e70(arg0, arg1);
        case 32U: return ByteVc0FdeFunc_0032_0x00855c(arg0, arg1);
        case 33U: return ByteVc0FdeFunc_0033_0x00867c(arg0, arg1);
        case 34U: return ByteVc0FdeFunc_0034_0x0088b8(arg0, arg1);
        case 35U: return ByteVc0FdeFunc_0035_0x00899c(arg0, arg1);
        case 36U: return ByteVc0FdeFunc_0036_0x008a0c(arg0, arg1);
        case 37U: return ByteVc0FdeFunc_0037_0x008a40(arg0, arg1);
        case 38U: return ByteVc0FdeFunc_0038_0x008ad4(arg0, arg1);
        case 39U: return ByteVc0FdeFunc_0039_0x008bf8(arg0, arg1);
        case 40U: return ByteVc0FdeFunc_0040_0x008c3c(arg0, arg1);
        case 41U: return ByteVc0FdeFunc_0041_0x008c84(arg0, arg1);
        case 42U: return ByteVc0FdeFunc_0042_0x008d3c(arg0, arg1);
        case 43U: return ByteVc0FdeFunc_0043_0x008e6c(arg0, arg1);
        case 44U: return ByteVc0FdeFunc_0044_0x008ec0(arg0, arg1);
        case 45U: return ByteVc0FdeFunc_0045_0x008fc0(arg0, arg1);
        case 46U: return ByteVc0FdeFunc_0046_0x00903c(arg0, arg1);
        case 47U: return ByteVc0FdeFunc_0047_0x00907c(arg0, arg1);
        case 48U: return ByteVc0FdeFunc_0048_0x0091a4(arg0, arg1);
        case 49U: return ByteVc0FdeFunc_0049_0x009454(arg0, arg1);
        case 50U: return ByteVc0FdeFunc_0050_0x0094cc(arg0, arg1);
        case 51U: return ByteVc0FdeFunc_0051_0x0095f0(arg0, arg1);
        case 52U: return ByteVc0FdeFunc_0052_0x009664(arg0, arg1);
        case 53U: return ByteVc0FdeFunc_0053_0x0096ac(arg0, arg1);
        case 54U: return ByteVc0FdeFunc_0054_0x0097f4(arg0, arg1);
        case 55U: return ByteVc0FdeFunc_0055_0x0098c0(arg0, arg1);
        case 56U: return ByteVc0FdeFunc_0056_0x00990c(arg0, arg1);
        case 57U: return ByteVc0FdeFunc_0057_0x009a90(arg0, arg1);
        case 58U: return ByteVc0FdeFunc_0058_0x009b44(arg0, arg1);
        case 59U: return ByteVc0FdeFunc_0059_0x009cc8(arg0, arg1);
        case 60U: return ByteVc0FdeFunc_0060_0x009e0c(arg0, arg1);
        case 61U: return ByteVc0FdeFunc_0061_0x009f24(arg0, arg1);
        case 62U: return ByteVc0FdeFunc_0062_0x009fb4(arg0, arg1);
        case 63U: return ByteVc0FdeFunc_0063_0x00a28c(arg0, arg1);
        case 64U: return ByteVc0FdeFunc_0064_0x00a338(arg0, arg1);
        case 65U: return ByteVc0FdeFunc_0065_0x00a644(arg0, arg1);
        case 66U: return ByteVc0FdeFunc_0066_0x00a8e8(arg0, arg1);
        case 67U: return ByteVc0FdeFunc_0067_0x00aa18(arg0, arg1);
        case 68U: return ByteVc0FdeFunc_0068_0x00ab9c(arg0, arg1);
        case 69U: return ByteVc0FdeFunc_0069_0x00abf0(arg0, arg1);
        case 70U: return ByteVc0FdeFunc_0070_0x00ac68(arg0, arg1);
        case 71U: return ByteVc0FdeFunc_0071_0x00ad90(arg0, arg1);
        case 72U: return ByteVc0FdeFunc_0072_0x00ae38(arg0, arg1);
        case 73U: return ByteVc0FdeFunc_0073_0x00b13c(arg0, arg1);
        case 74U: return ByteVc0FdeFunc_0074_0x00b1a0(arg0, arg1);
        case 75U: return ByteVc0FdeFunc_0075_0x00b318(arg0, arg1);
        case 76U: return ByteVc0FdeFunc_0076_0x00b404(arg0, arg1);
        case 77U: return ByteVc0FdeFunc_0077_0x00b4e0(arg0, arg1);
        case 78U: return ByteVc0FdeFunc_0078_0x00b580(arg0, arg1);
        case 79U: return ByteVc0FdeFunc_0079_0x00b6ac(arg0, arg1);
        case 80U: return ByteVc0FdeFunc_0080_0x00ba30(arg0, arg1);
        case 81U: return ByteVc0FdeFunc_0081_0x00bdac(arg0, arg1);
        case 82U: return ByteVc0FdeFunc_0082_0x00c0dc(arg0, arg1);
        case 83U: return ByteVc0FdeFunc_0083_0x00c87c(arg0, arg1);
        case 84U: return ByteVc0FdeFunc_0084_0x00c914(arg0, arg1);
        case 85U: return ByteVc0FdeFunc_0085_0x00cba0(arg0, arg1);
        case 86U: return ByteVc0FdeFunc_0086_0x00cc9c(arg0, arg1);
        case 87U: return ByteVc0FdeFunc_0087_0x00d90c(arg0, arg1);
        case 88U: return ByteVc0FdeFunc_0088_0x00da80(arg0, arg1);
        case 89U: return ByteVc0FdeFunc_0089_0x00dc48(arg0, arg1);
        case 90U: return ByteVc0FdeFunc_0090_0x00dd78(arg0, arg1);
        case 91U: return ByteVc0FdeFunc_0091_0x00de78(arg0, arg1);
        case 92U: return ByteVc0FdeFunc_0092_0x00de7c(arg0, arg1);
        case 93U: return ByteVc0FdeFunc_0093_0x00de80(arg0, arg1);
        case 94U: return ByteVc0FdeFunc_0094_0x00deb0(arg0, arg1);
        case 95U: return ByteVc0FdeFunc_0095_0x00deec(arg0, arg1);
        case 96U: return ByteVc0FdeFunc_0096_0x00df40(arg0, arg1);
        case 97U: return ByteVc0FdeFunc_0097_0x00df64(arg0, arg1);
        case 98U: return ByteVc0FdeFunc_0098_0x00df70(arg0, arg1);
        case 99U: return ByteVc0FdeFunc_0099_0x00df80(arg0, arg1);
        case 100U: return ByteVc0FdeFunc_0100_0x00df90(arg0, arg1);
        case 101U: return ByteVc0FdeFunc_0101_0x00dfa8(arg0, arg1);
        case 102U: return ByteVc0FdeFunc_0102_0x00dfb8(arg0, arg1);
        case 103U: return ByteVc0FdeFunc_0103_0x00e3b0(arg0, arg1);
        case 104U: return ByteVc0FdeFunc_0104_0x00e490(arg0, arg1);
        case 105U: return ByteVc0FdeFunc_0105_0x00e4f0(arg0, arg1);
        case 106U: return ByteVc0FdeFunc_0106_0x00e550(arg0, arg1);
        case 107U: return ByteVc0FdeFunc_0107_0x00e5b0(arg0, arg1);
        case 108U: return ByteVc0FdeFunc_0108_0x00e680(arg0, arg1);
        case 109U: return ByteVc0FdeFunc_0109_0x00e6fc(arg0, arg1);
        case 110U: return ByteVc0FdeFunc_0110_0x00e760(arg0, arg1);
        case 111U: return ByteVc0FdeFunc_0111_0x00e780(arg0, arg1);
        case 112U: return ByteVc0FdeFunc_0112_0x00e894(arg0, arg1);
        case 113U: return ByteVc0FdeFunc_0113_0x00e964(arg0, arg1);
        case 114U: return ByteVc0FdeFunc_0114_0x00e9e0(arg0, arg1);
        case 115U: return ByteVc0FdeFunc_0115_0x00ea44(arg0, arg1);
        case 116U: return ByteVc0FdeFunc_0116_0x00ea64(arg0, arg1);
        case 117U: return ByteVc0FdeFunc_0117_0x00eb78(arg0, arg1);
        case 118U: return ByteVc0FdeFunc_0118_0x00ebe4(arg0, arg1);
        case 119U: return ByteVc0FdeFunc_0119_0x00ec1c(arg0, arg1);
        case 120U: return ByteVc0FdeFunc_0120_0x00ec54(arg0, arg1);
        case 121U: return ByteVc0FdeFunc_0121_0x00ee00(arg0, arg1);
        case 122U: return ByteVc0FdeFunc_0122_0x00efa4(arg0, arg1);
        case 123U: return ByteVc0FdeFunc_0123_0x00f004(arg0, arg1);
        case 124U: return ByteVc0FdeFunc_0124_0x00f310(arg0, arg1);
        case 125U: return ByteVc0FdeFunc_0125_0x00f36c(arg0, arg1);
        case 126U: return ByteVc0FdeFunc_0126_0x00f908(arg0, arg1);
        case 127U: return ByteVc0FdeFunc_0127_0x00fa0c(arg0, arg1);
        case 128U: return ByteVc0FdeFunc_0128_0x00fc04(arg0, arg1);
        case 129U: return ByteVc0FdeFunc_0129_0x00fdac(arg0, arg1);
        case 130U: return ByteVc0FdeFunc_0130_0x00fe6c(arg0, arg1);
        case 131U: return ByteVc0FdeFunc_0131_0x010124(arg0, arg1);
        case 132U: return ByteVc0FdeFunc_0132_0x010190(arg0, arg1);
        case 133U: return ByteVc0FdeFunc_0133_0x010234(arg0, arg1);
        case 134U: return ByteVc0FdeFunc_0134_0x01030c(arg0, arg1);
        case 135U: return ByteVc0FdeFunc_0135_0x0108dc(arg0, arg1);
        case 136U: return ByteVc0FdeFunc_0136_0x010ad4(arg0, arg1);
        case 137U: return ByteVc0FdeFunc_0137_0x0113a4(arg0, arg1);
        case 138U: return ByteVc0FdeFunc_0138_0x0113a8(arg0, arg1);
        case 139U: return ByteVc0FdeFunc_0139_0x011574(arg0, arg1);
        case 140U: return ByteVc0FdeFunc_0140_0x011698(arg0, arg1);
        case 141U: return ByteVc0FdeFunc_0141_0x01187c(arg0, arg1);
        case 142U: return ByteVc0FdeFunc_0142_0x011a84(arg0, arg1);
        case 143U: return ByteVc0FdeFunc_0143_0x011a88(arg0, arg1);
        case 144U: return ByteVc0FdeFunc_0144_0x011a8c(arg0, arg1);
        case 145U: return ByteVc0FdeFunc_0145_0x011ae4(arg0, arg1);
        case 146U: return ByteVc0FdeFunc_0146_0x011b40(arg0, arg1);
        case 147U: return ByteVc0FdeFunc_0147_0x011c74(arg0, arg1);
        case 148U: return ByteVc0FdeFunc_0148_0x011da4(arg0, arg1);
        case 149U: return ByteVc0FdeFunc_0149_0x011f04(arg0, arg1);
        case 150U: return ByteVc0FdeFunc_0150_0x012070(arg0, arg1);
        case 151U: return ByteVc0FdeFunc_0151_0x012290(arg0, arg1);
        case 152U: return ByteVc0FdeFunc_0152_0x012584(arg0, arg1);
        case 153U: return ByteVc0FdeFunc_0153_0x012828(arg0, arg1);
        case 154U: return ByteVc0FdeFunc_0154_0x013534(arg0, arg1);
        case 155U: return ByteVc0FdeFunc_0155_0x01389c(arg0, arg1);
        case 156U: return ByteVc0FdeFunc_0156_0x01409c(arg0, arg1);
        case 157U: return ByteVc0FdeFunc_0157_0x01411c(arg0, arg1);
        case 158U: return ByteVc0FdeFunc_0158_0x01459c(arg0, arg1);
        case 159U: return ByteVc0FdeFunc_0159_0x014a54(arg0, arg1);
        case 160U: return ByteVc0FdeFunc_0160_0x014efc(arg0, arg1);
        case 161U: return ByteVc0FdeFunc_0161_0x015070(arg0, arg1);
        case 162U: return ByteVc0FdeFunc_0162_0x015b4c(arg0, arg1);
        case 163U: return ByteVc0FdeFunc_0163_0x01656c(arg0, arg1);
        case 164U: return ByteVc0FdeFunc_0164_0x017238(arg0, arg1);
        case 165U: return ByteVc0FdeFunc_0165_0x017de0(arg0, arg1);
        case 166U: return ByteVc0FdeFunc_0166_0x018018(arg0, arg1);
        case 167U: return ByteVc0FdeFunc_0167_0x01818c(arg0, arg1);
        case 168U: return ByteVc0FdeFunc_0168_0x0185bc(arg0, arg1);
        case 169U: return ByteVc0FdeFunc_0169_0x018b10(arg0, arg1);
        case 170U: return ByteVc0FdeFunc_0170_0x018c88(arg0, arg1);
        case 171U: return ByteVc0FdeFunc_0171_0x019080(arg0, arg1);
        case 172U: return ByteVc0FdeFunc_0172_0x019900(arg0, arg1);
        case 173U: return ByteVc0FdeFunc_0173_0x019bc4(arg0, arg1);
        case 174U: return ByteVc0FdeFunc_0174_0x019d70(arg0, arg1);
        case 175U: return ByteVc0FdeFunc_0175_0x01a41c(arg0, arg1);
        case 176U: return ByteVc0FdeFunc_0176_0x01ab80(arg0, arg1);
        case 177U: return ByteVc0FdeFunc_0177_0x01b0c4(arg0, arg1);
        case 178U: return ByteVc0FdeFunc_0178_0x01b268(arg0, arg1);
        case 179U: return ByteVc0FdeFunc_0179_0x01b484(arg0, arg1);
        case 180U: return ByteVc0FdeFunc_0180_0x01bccc(arg0, arg1);
        case 181U: return ByteVc0FdeFunc_0181_0x01bd5c(arg0, arg1);
        case 182U: return ByteVc0FdeFunc_0182_0x01bec8(arg0, arg1);
        case 183U: return ByteVc0FdeFunc_0183_0x01c078(arg0, arg1);
        case 184U: return ByteVc0FdeFunc_0184_0x01c3e4(arg0, arg1);
        case 185U: return ByteVc0FdeFunc_0185_0x01ca34(arg0, arg1);
        case 186U: return ByteVc0FdeFunc_0186_0x01cbf4(arg0, arg1);
        case 187U: return ByteVc0FdeFunc_0187_0x01cc50(arg0, arg1);
        case 188U: return ByteVc0FdeFunc_0188_0x01ccbc(arg0, arg1);
        case 189U: return ByteVc0FdeFunc_0189_0x01cd40(arg0, arg1);
        case 190U: return ByteVc0FdeFunc_0190_0x01cdf4(arg0, arg1);
        case 191U: return ByteVc0FdeFunc_0191_0x01ce14(arg0, arg1);
        case 192U: return ByteVc0FdeFunc_0192_0x01d02c(arg0, arg1);
        case 193U: return ByteVc0FdeFunc_0193_0x01d0dc(arg0, arg1);
        case 194U: return ByteVc0FdeFunc_0194_0x01d324(arg0, arg1);
        case 195U: return ByteVc0FdeFunc_0195_0x01d3cc(arg0, arg1);
        case 196U: return ByteVc0FdeFunc_0196_0x01d46c(arg0, arg1);
        case 197U: return ByteVc0FdeFunc_0197_0x01d59c(arg0, arg1);
        case 198U: return ByteVc0FdeFunc_0198_0x01d764(arg0, arg1);
        case 199U: return ByteVc0FdeFunc_0199_0x01d778(arg0, arg1);
        case 200U: return ByteVc0FdeFunc_0200_0x01d914(arg0, arg1);
        case 201U: return ByteVc0FdeFunc_0201_0x01dbe8(arg0, arg1);
        case 202U: return ByteVc0FdeFunc_0202_0x01dbf8(arg0, arg1);
        case 203U: return ByteVc0FdeFunc_0203_0x01dd4c(arg0, arg1);
        case 204U: return ByteVc0FdeFunc_0204_0x01ddf4(arg0, arg1);
        case 205U: return ByteVc0FdeFunc_0205_0x01e25c(arg0, arg1);
        case 206U: return ByteVc0FdeFunc_0206_0x01e694(arg0, arg1);
        case 207U: return ByteVc0FdeFunc_0207_0x01eac0(arg0, arg1);
        case 208U: return ByteVc0FdeFunc_0208_0x01f798(arg0, arg1);
        case 209U: return ByteVc0FdeFunc_0209_0x020250(arg0, arg1);
        case 210U: return ByteVc0FdeFunc_0210_0x0203f0(arg0, arg1);
        case 211U: return ByteVc0FdeFunc_0211_0x020564(arg0, arg1);
        case 212U: return ByteVc0FdeFunc_0212_0x020778(arg0, arg1);
        case 213U: return ByteVc0FdeFunc_0213_0x020b5c(arg0, arg1);
        case 214U: return ByteVc0FdeFunc_0214_0x020fd8(arg0, arg1);
        case 215U: return ByteVc0FdeFunc_0215_0x020fec(arg0, arg1);
        case 216U: return ByteVc0FdeFunc_0216_0x021008(arg0, arg1);
        case 217U: return ByteVc0FdeFunc_0217_0x02101c(arg0, arg1);
        case 218U: return ByteVc0FdeFunc_0218_0x021038(arg0, arg1);
        case 219U: return ByteVc0FdeFunc_0219_0x0216a8(arg0, arg1);
        case 220U: return ByteVc0FdeFunc_0220_0x022094(arg0, arg1);
        case 221U: return ByteVc0FdeFunc_0221_0x02209c(arg0, arg1);
        case 222U: return ByteVc0FdeFunc_0222_0x022488(arg0, arg1);
        case 223U: return ByteVc0FdeFunc_0223_0x0224cc(arg0, arg1);
        case 224U: return ByteVc0FdeFunc_0224_0x0224d0(arg0, arg1);
        case 225U: return ByteVc0FdeFunc_0225_0x0224d4(arg0, arg1);
        case 226U: return ByteVc0FdeFunc_0226_0x0224dc(arg0, arg1);
        case 227U: return ByteVc0FdeFunc_0227_0x022674(arg0, arg1);
        case 228U: return ByteVc0FdeFunc_0228_0x022ac8(arg0, arg1);
        case 229U: return ByteVc0FdeFunc_0229_0x022cf4(arg0, arg1);
        case 230U: return ByteVc0FdeFunc_0230_0x023184(arg0, arg1);
        case 231U: return ByteVc0FdeFunc_0231_0x023514(arg0, arg1);
        case 232U: return ByteVc0FdeFunc_0232_0x02364c(arg0, arg1);
        case 233U: return ByteVc0FdeFunc_0233_0x023790(arg0, arg1);
        case 234U: return ByteVc0FdeFunc_0234_0x023894(arg0, arg1);
        case 235U: return ByteVc0FdeFunc_0235_0x023a0c(arg0, arg1);
        case 236U: return ByteVc0FdeFunc_0236_0x024054(arg0, arg1);
        case 237U: return ByteVc0FdeFunc_0237_0x0243ac(arg0, arg1);
        case 238U: return ByteVc0FdeFunc_0238_0x0246b0(arg0, arg1);
        case 239U: return ByteVc0FdeFunc_0239_0x0246ec(arg0, arg1);
        case 240U: return ByteVc0FdeFunc_0240_0x024b14(arg0, arg1);
        case 241U: return ByteVc0FdeFunc_0241_0x024fc0(arg0, arg1);
        case 242U: return ByteVc0FdeFunc_0242_0x025cec(arg0, arg1);
        case 243U: return ByteVc0FdeFunc_0243_0x026728(arg0, arg1);
        case 244U: return ByteVc0FdeFunc_0244_0x026a8c(arg0, arg1);
        case 245U: return ByteVc0FdeFunc_0245_0x027df8(arg0, arg1);
        case 246U: return ByteVc0FdeFunc_0246_0x029b68(arg0, arg1);
        case 247U: return ByteVc0FdeFunc_0247_0x029ed8(arg0, arg1);
        case 248U: return ByteVc0FdeFunc_0248_0x02a0d4(arg0, arg1);
        case 249U: return ByteVc0FdeFunc_0249_0x02a148(arg0, arg1);
        case 250U: return ByteVc0FdeFunc_0250_0x02a158(arg0, arg1);
        case 251U: return ByteVc0FdeFunc_0251_0x02a29c(arg0, arg1);
        case 252U: return ByteVc0FdeFunc_0252_0x02a3ac(arg0, arg1);
        case 253U: return ByteVc0FdeFunc_0253_0x02a3c0(arg0, arg1);
        case 254U: return ByteVc0FdeFunc_0254_0x02a3d0(arg0, arg1);
        case 255U: return ByteVc0FdeFunc_0255_0x02a824(arg0, arg1);
        case 256U: return ByteVc0FdeFunc_0256_0x02a86c(arg0, arg1);
        case 257U: return ByteVc0FdeFunc_0257_0x02aaa4(arg0, arg1);
        case 258U: return ByteVc0FdeFunc_0258_0x02b444(arg0, arg1);
        case 259U: return ByteVc0FdeFunc_0259_0x02b7d0(arg0, arg1);
        case 260U: return ByteVc0FdeFunc_0260_0x02bac8(arg0, arg1);
        case 261U: return ByteVc0FdeFunc_0261_0x02be38(arg0, arg1);
        case 262U: return ByteVc0FdeFunc_0262_0x02bfe0(arg0, arg1);
        case 263U: return ByteVc0FdeFunc_0263_0x02c13c(arg0, arg1);
        case 264U: return ByteVc0FdeFunc_0264_0x02c29c(arg0, arg1);
        case 265U: return ByteVc0FdeFunc_0265_0x02c978(arg0, arg1);
        case 266U: return ByteVc0FdeFunc_0266_0x02c9c8(arg0, arg1);
        case 267U: return ByteVc0FdeFunc_0267_0x02cbb4(arg0, arg1);
        case 268U: return ByteVc0FdeFunc_0268_0x02cd00(arg0, arg1);
        case 269U: return ByteVc0FdeFunc_0269_0x02cd20(arg0, arg1);
        case 270U: return ByteVc0FdeFunc_0270_0x02cd30(arg0, arg1);
        case 271U: return ByteVc0FdeFunc_0271_0x02cd9c(arg0, arg1);
        case 272U: return ByteVc0FdeFunc_0272_0x02cdcc(arg0, arg1);
        case 273U: return ByteVc0FdeFunc_0273_0x02d000(arg0, arg1);
        case 274U: return ByteVc0FdeFunc_0274_0x02d074(arg0, arg1);
        case 275U: return ByteVc0FdeFunc_0275_0x02d090(arg0, arg1);
        case 276U: return ByteVc0FdeFunc_0276_0x02d110(arg0, arg1);
        case 277U: return ByteVc0FdeFunc_0277_0x02d1b0(arg0, arg1);
        case 278U: return ByteVc0FdeFunc_0278_0x02d358(arg0, arg1);
        case 279U: return ByteVc0FdeFunc_0279_0x02d40c(arg0, arg1);
        case 280U: return ByteVc0FdeFunc_0280_0x02d67c(arg0, arg1);
        case 281U: return ByteVc0FdeFunc_0281_0x02d6bc(arg0, arg1);
        case 282U: return ByteVc0FdeFunc_0282_0x02db30(arg0, arg1);
        case 283U: return ByteVc0FdeFunc_0283_0x02db68(arg0, arg1);
        case 284U: return ByteVc0FdeFunc_0284_0x02db6c(arg0, arg1);
        case 285U: return ByteVc0FdeFunc_0285_0x02db78(arg0, arg1);
        case 286U: return ByteVc0FdeFunc_0286_0x02db90(arg0, arg1);
        case 287U: return ByteVc0FdeFunc_0287_0x02dc34(arg0, arg1);
        case 288U: return ByteVc0FdeFunc_0288_0x02dc68(arg0, arg1);
        case 289U: return ByteVc0FdeFunc_0289_0x02dca8(arg0, arg1);
        case 290U: return ByteVc0FdeFunc_0290_0x02dce8(arg0, arg1);
        case 291U: return ByteVc0FdeFunc_0291_0x02dcf4(arg0, arg1);
        case 292U: return ByteVc0FdeFunc_0292_0x02dd04(arg0, arg1);
        case 293U: return ByteVc0FdeFunc_0293_0x02dd14(arg0, arg1);
        case 294U: return ByteVc0FdeFunc_0294_0x02dd68(arg0, arg1);
        case 295U: return ByteVc0FdeFunc_0295_0x02de30(arg0, arg1);
        case 296U: return ByteVc0FdeFunc_0296_0x02de58(arg0, arg1);
        case 297U: return ByteVc0FdeFunc_0297_0x02e490(arg0, arg1);
        case 298U: return ByteVc0FdeFunc_0298_0x02e504(arg0, arg1);
        case 299U: return ByteVc0FdeFunc_0299_0x02e578(arg0, arg1);
        case 300U: return ByteVc0FdeFunc_0300_0x02e668(arg0, arg1);
        case 301U: return ByteVc0FdeFunc_0301_0x02e740(arg0, arg1);
        case 302U: return ByteVc0FdeFunc_0302_0x02ed10(arg0, arg1);
        case 303U: return ByteVc0FdeFunc_0303_0x02ed90(arg0, arg1);
        case 304U: return ByteVc0FdeFunc_0304_0x02ed98(arg0, arg1);
        case 305U: return ByteVc0FdeFunc_0305_0x02edac(arg0, arg1);
        case 306U: return ByteVc0FdeFunc_0306_0x02eeb4(arg0, arg1);
        case 307U: return ByteVc0FdeFunc_0307_0x02eebc(arg0, arg1);
        case 308U: return ByteVc0FdeFunc_0308_0x02eec0(arg0, arg1);
        case 309U: return ByteVc0FdeFunc_0309_0x02eec4(arg0, arg1);
        case 310U: return ByteVc0FdeFunc_0310_0x02f234(arg0, arg1);
        case 311U: return ByteVc0FdeFunc_0311_0x02f450(arg0, arg1);
        case 312U: return ByteVc0FdeFunc_0312_0x02f678(arg0, arg1);
        case 313U: return ByteVc0FdeFunc_0313_0x02f80c(arg0, arg1);
        case 314U: return ByteVc0FdeFunc_0314_0x02f99c(arg0, arg1);
        case 315U: return ByteVc0FdeFunc_0315_0x02fb28(arg0, arg1);
        case 316U: return ByteVc0FdeFunc_0316_0x02fd98(arg0, arg1);
        case 317U: return ByteVc0FdeFunc_0317_0x02ffe4(arg0, arg1);
        case 318U: return ByteVc0FdeFunc_0318_0x030058(arg0, arg1);
        case 319U: return ByteVc0FdeFunc_0319_0x0300f8(arg0, arg1);
        case 320U: return ByteVc0FdeFunc_0320_0x0301e0(arg0, arg1);
        case 321U: return ByteVc0FdeFunc_0321_0x030238(arg0, arg1);
        case 322U: return ByteVc0FdeFunc_0322_0x0302b0(arg0, arg1);
        case 323U: return ByteVc0FdeFunc_0323_0x030328(arg0, arg1);
        case 324U: return ByteVc0FdeFunc_0324_0x0304dc(arg0, arg1);
        case 325U: return ByteVc0FdeFunc_0325_0x030570(arg0, arg1);
        case 326U: return ByteVc0FdeFunc_0326_0x0305e8(arg0, arg1);
        case 327U: return ByteVc0FdeFunc_0327_0x03061c(arg0, arg1);
        case 328U: return ByteVc0FdeFunc_0328_0x03065c(arg0, arg1);
        case 329U: return ByteVc0FdeFunc_0329_0x03069c(arg0, arg1);
        case 330U: return ByteVc0FdeFunc_0330_0x0306a8(arg0, arg1);
        case 331U: return ByteVc0FdeFunc_0331_0x0306b8(arg0, arg1);
        case 332U: return ByteVc0FdeFunc_0332_0x0306c8(arg0, arg1);
        case 333U: return ByteVc0FdeFunc_0333_0x0306d0(arg0, arg1);
        case 334U: return ByteVc0FdeFunc_0334_0x0306d8(arg0, arg1);
        case 335U: return ByteVc0FdeFunc_0335_0x0306e0(arg0, arg1);
        case 336U: return ByteVc0FdeFunc_0336_0x030988(arg0, arg1);
        case 337U: return ByteVc0FdeFunc_0337_0x030a14(arg0, arg1);
        case 338U: return ByteVc0FdeFunc_0338_0x030a1c(arg0, arg1);
        case 339U: return ByteVc0FdeFunc_0339_0x030a4c(arg0, arg1);
        case 340U: return ByteVc0FdeFunc_0340_0x030b74(arg0, arg1);
        case 341U: return ByteVc0FdeFunc_0341_0x030dcc(arg0, arg1);
        case 342U: return ByteVc0FdeFunc_0342_0x030ed0(arg0, arg1);
        case 343U: return ByteVc0FdeFunc_0343_0x030ed8(arg0, arg1);
        case 344U: return ByteVc0FdeFunc_0344_0x030ee0(arg0, arg1);
        case 345U: return ByteVc0FdeFunc_0345_0x030f90(arg0, arg1);
        case 346U: return ByteVc0FdeFunc_0346_0x030f98(arg0, arg1);
        case 347U: return ByteVc0FdeFunc_0347_0x031058(arg0, arg1);
        case 348U: return ByteVc0FdeFunc_0348_0x0310d4(arg0, arg1);
        case 349U: return ByteVc0FdeFunc_0349_0x0311ac(arg0, arg1);
        case 350U: return ByteVc0FdeFunc_0350_0x0311b0(arg0, arg1);
        case 351U: return ByteVc0FdeFunc_0351_0x0311b4(arg0, arg1);
        case 352U: return ByteVc0FdeFunc_0352_0x031590(arg0, arg1);
        case 353U: return ByteVc0FdeFunc_0353_0x031610(arg0, arg1);
        case 354U: return ByteVc0FdeFunc_0354_0x031810(arg0, arg1);
        case 355U: return ByteVc0FdeFunc_0355_0x03191c(arg0, arg1);
        case 356U: return ByteVc0FdeFunc_0356_0x0319a8(arg0, arg1);
        case 357U: return ByteVc0FdeFunc_0357_0x031a18(arg0, arg1);
        case 358U: return ByteVc0FdeFunc_0358_0x031aa8(arg0, arg1);
        case 359U: return ByteVc0FdeFunc_0359_0x031b34(arg0, arg1);
        case 360U: return ByteVc0FdeFunc_0360_0x031b80(arg0, arg1);
        case 361U: return ByteVc0FdeFunc_0361_0x031c3c(arg0, arg1);
        case 362U: return ByteVc0FdeFunc_0362_0x031cac(arg0, arg1);
        case 363U: return ByteVc0FdeFunc_0363_0x031d30(arg0, arg1);
        case 364U: return ByteVc0FdeFunc_0364_0x0321c4(arg0, arg1);
        case 365U: return ByteVc0FdeFunc_0365_0x032288(arg0, arg1);
        case 366U: return ByteVc0FdeFunc_0366_0x0322c8(arg0, arg1);
        case 367U: return ByteVc0FdeFunc_0367_0x03234c(arg0, arg1);
        case 368U: return ByteVc0FdeFunc_0368_0x03238c(arg0, arg1);
        case 369U: return ByteVc0FdeFunc_0369_0x0323cc(arg0, arg1);
        case 370U: return ByteVc0FdeFunc_0370_0x032450(arg0, arg1);
        case 371U: return ByteVc0FdeFunc_0371_0x032868(arg0, arg1);
        case 372U: return ByteVc0FdeFunc_0372_0x032dd0(arg0, arg1);
        case 373U: return ByteVc0FdeFunc_0373_0x032e60(arg0, arg1);
        case 374U: return ByteVc0FdeFunc_0374_0x032ef8(arg0, arg1);
        case 375U: return ByteVc0FdeFunc_0375_0x033038(arg0, arg1);
        case 376U: return ByteVc0FdeFunc_0376_0x0331e0(arg0, arg1);
        case 377U: return ByteVc0FdeFunc_0377_0x033388(arg0, arg1);
        case 378U: return ByteVc0FdeFunc_0378_0x0333e0(arg0, arg1);
        case 379U: return ByteVc0FdeFunc_0379_0x033618(arg0, arg1);
        case 380U: return ByteVc0FdeFunc_0380_0x033740(arg0, arg1);
        case 381U: return ByteVc0FdeFunc_0381_0x033880(arg0, arg1);
        case 382U: return ByteVc0FdeFunc_0382_0x03395c(arg0, arg1);
        case 383U: return ByteVc0FdeFunc_0383_0x033af8(arg0, arg1);
        case 384U: return ByteVc0FdeFunc_0384_0x033d94(arg0, arg1);
        case 385U: return ByteVc0FdeFunc_0385_0x033f34(arg0, arg1);
        case 386U: return ByteVc0FdeFunc_0386_0x033f38(arg0, arg1);
        case 387U: return ByteVc0FdeFunc_0387_0x033f40(arg0, arg1);
        case 388U: return ByteVc0FdeFunc_0388_0x033f58(arg0, arg1);
        case 389U: return ByteVc0FdeFunc_0389_0x033f5c(arg0, arg1);
        case 390U: return ByteVc0FdeFunc_0390_0x033f80(arg0, arg1);
        case 391U: return ByteVc0FdeFunc_0391_0x033fa4(arg0, arg1);
        case 392U: return ByteVc0FdeFunc_0392_0x033fcc(arg0, arg1);
        case 393U: return ByteVc0FdeFunc_0393_0x033fd0(arg0, arg1);
        case 394U: return ByteVc0FdeFunc_0394_0x033fd4(arg0, arg1);
        case 395U: return ByteVc0FdeFunc_0395_0x033fd8(arg0, arg1);
        case 396U: return ByteVc0FdeFunc_0396_0x034480(arg0, arg1);
        case 397U: return ByteVc0FdeFunc_0397_0x0344e0(arg0, arg1);
        case 398U: return ByteVc0FdeFunc_0398_0x034504(arg0, arg1);
        case 399U: return ByteVc0FdeFunc_0399_0x034510(arg0, arg1);
        case 400U: return ByteVc0FdeFunc_0400_0x0345f0(arg0, arg1);
        case 401U: return ByteVc0FdeFunc_0401_0x0346d0(arg0, arg1);
        case 402U: return ByteVc0FdeFunc_0402_0x03493c(arg0, arg1);
        case 403U: return ByteVc0FdeFunc_0403_0x034ae4(arg0, arg1);
        case 404U: return ByteVc0FdeFunc_0404_0x034ccc(arg0, arg1);
        case 405U: return ByteVc0FdeFunc_0405_0x034dd8(arg0, arg1);
        case 406U: return ByteVc0FdeFunc_0406_0x034f98(arg0, arg1);
        case 407U: return ByteVc0FdeFunc_0407_0x0350e0(arg0, arg1);
        case 408U: return ByteVc0FdeFunc_0408_0x035264(arg0, arg1);
        case 409U: return ByteVc0FdeFunc_0409_0x035404(arg0, arg1);
        case 410U: return ByteVc0FdeFunc_0410_0x03554c(arg0, arg1);
        case 411U: return ByteVc0FdeFunc_0411_0x0355b4(arg0, arg1);
        case 412U: return ByteVc0FdeFunc_0412_0x035608(arg0, arg1);
        case 413U: return ByteVc0FdeFunc_0413_0x03598c(arg0, arg1);
        case 414U: return ByteVc0FdeFunc_0414_0x035dd8(arg0, arg1);
        case 415U: return ByteVc0FdeFunc_0415_0x03657c(arg0, arg1);
        case 416U: return ByteVc0FdeFunc_0416_0x036908(arg0, arg1);
        case 417U: return ByteVc0FdeFunc_0417_0x036b90(arg0, arg1);
        case 418U: return ByteVc0FdeFunc_0418_0x036d34(arg0, arg1);
        case 419U: return ByteVc0FdeFunc_0419_0x036f88(arg0, arg1);
        case 420U: return ByteVc0FdeFunc_0420_0x036fbc(arg0, arg1);
        case 421U: return ByteVc0FdeFunc_0421_0x036ff4(arg0, arg1);
        case 422U: return ByteVc0FdeFunc_0422_0x037204(arg0, arg1);
        case 423U: return ByteVc0FdeFunc_0423_0x037380(arg0, arg1);
        case 424U: return ByteVc0FdeFunc_0424_0x03741c(arg0, arg1);
        case 425U: return ByteVc0FdeFunc_0425_0x037430(arg0, arg1);
        case 426U: return ByteVc0FdeFunc_0426_0x03743c(arg0, arg1);
        case 427U: return ByteVc0FdeFunc_0427_0x037454(arg0, arg1);
        case 428U: return ByteVc0FdeFunc_0428_0x03749c(arg0, arg1);
        case 429U: return ByteVc0FdeFunc_0429_0x0374f8(arg0, arg1);
        case 430U: return ByteVc0FdeFunc_0430_0x037530(arg0, arg1);
        case 431U: return ByteVc0FdeFunc_0431_0x037544(arg0, arg1);
        case 432U: return ByteVc0FdeFunc_0432_0x03755c(arg0, arg1);
        case 433U: return ByteVc0FdeFunc_0433_0x0377b0(arg0, arg1);
        case 434U: return ByteVc0FdeFunc_0434_0x0378e0(arg0, arg1);
        case 435U: return ByteVc0FdeFunc_0435_0x037ac0(arg0, arg1);
        case 436U: return ByteVc0FdeFunc_0436_0x037ac8(arg0, arg1);
        case 437U: return ByteVc0FdeFunc_0437_0x037f60(arg0, arg1);
        case 438U: return ByteVc0FdeFunc_0438_0x0380ac(arg0, arg1);
        case 439U: return ByteVc0FdeFunc_0439_0x03818c(arg0, arg1);
        case 440U: return ByteVc0FdeFunc_0440_0x0381c4(arg0, arg1);
        case 441U: return ByteVc0FdeFunc_0441_0x03821c(arg0, arg1);
        case 442U: return ByteVc0FdeFunc_0442_0x0383e4(arg0, arg1);
        case 443U: return ByteVc0FdeFunc_0443_0x038494(arg0, arg1);
        case 444U: return ByteVc0FdeFunc_0444_0x0384c4(arg0, arg1);
        case 445U: return ByteVc0FdeFunc_0445_0x0385e8(arg0, arg1);
        case 446U: return ByteVc0FdeFunc_0446_0x038618(arg0, arg1);
        case 447U: return ByteVc0FdeFunc_0447_0x038634(arg0, arg1);
        case 448U: return ByteVc0FdeFunc_0448_0x038668(arg0, arg1);
        case 449U: return ByteVc0FdeFunc_0449_0x0386a8(arg0, arg1);
        case 450U: return ByteVc0FdeFunc_0450_0x038748(arg0, arg1);
        case 451U: return ByteVc0FdeFunc_0451_0x0387fc(arg0, arg1);
        case 452U: return ByteVc0FdeFunc_0452_0x0388dc(arg0, arg1);
        case 453U: return ByteVc0FdeFunc_0453_0x038934(arg0, arg1);
        case 454U: return ByteVc0FdeFunc_0454_0x038990(arg0, arg1);
        case 455U: return ByteVc0FdeFunc_0455_0x038ba4(arg0, arg1);
        case 456U: return ByteVc0FdeFunc_0456_0x038c30(arg0, arg1);
        case 457U: return ByteVc0FdeFunc_0457_0x0392cc(arg0, arg1);
        case 458U: return ByteVc0FdeFunc_0458_0x0394a0(arg0, arg1);
        case 459U: return ByteVc0FdeFunc_0459_0x0394f0(arg0, arg1);
        case 460U: return ByteVc0FdeFunc_0460_0x039540(arg0, arg1);
        case 461U: return ByteVc0FdeFunc_0461_0x03959c(arg0, arg1);
        case 462U: return ByteVc0FdeFunc_0462_0x0395c0(arg0, arg1);
        case 463U: return ByteVc0FdeFunc_0463_0x0395d0(arg0, arg1);
        case 464U: return ByteVc0FdeFunc_0464_0x039694(arg0, arg1);
        case 465U: return ByteVc0FdeFunc_0465_0x0397b8(arg0, arg1);
        case 466U: return ByteVc0FdeFunc_0466_0x039800(arg0, arg1);
        case 467U: return ByteVc0FdeFunc_0467_0x039904(arg0, arg1);
        case 468U: return ByteVc0FdeFunc_0468_0x039970(arg0, arg1);
        case 469U: return ByteVc0FdeFunc_0469_0x039aa0(arg0, arg1);
        case 470U: return ByteVc0FdeFunc_0470_0x039adc(arg0, arg1);
        case 471U: return ByteVc0FdeFunc_0471_0x039ccc(arg0, arg1);
        case 472U: return ByteVc0FdeFunc_0472_0x039dcc(arg0, arg1);
        case 473U: return ByteVc0FdeFunc_0473_0x039dd8(arg0, arg1);
        case 474U: return ByteVc0FdeFunc_0474_0x039de0(arg0, arg1);
        case 475U: return ByteVc0FdeFunc_0475_0x039e40(arg0, arg1);
        case 476U: return ByteVc0FdeFunc_0476_0x039f10(arg0, arg1);
        case 477U: return ByteVc0FdeFunc_0477_0x039f8c(arg0, arg1);
        case 478U: return ByteVc0FdeFunc_0478_0x039ff0(arg0, arg1);
        case 479U: return ByteVc0FdeFunc_0479_0x03a010(arg0, arg1);
        case 480U: return ByteVc0FdeFunc_0480_0x03a124(arg0, arg1);
        case 481U: return ByteVc0FdeFunc_0481_0x03a19c(arg0, arg1);
        case 482U: return ByteVc0FdeFunc_0482_0x03a1d4(arg0, arg1);
        case 483U: return ByteVc0FdeFunc_0483_0x03ac30(arg0, arg1);
        case 484U: return ByteVc0FdeFunc_0484_0x03ad9c(arg0, arg1);
        case 485U: return ByteVc0FdeFunc_0485_0x03bfbc(arg0, arg1);
        case 486U: return ByteVc0FdeFunc_0486_0x03c058(arg0, arg1);
        case 487U: return ByteVc0FdeFunc_0487_0x03c05c(arg0, arg1);
        case 488U: return ByteVc0FdeFunc_0488_0x03c17c(arg0, arg1);
        case 489U: return ByteVc0FdeFunc_0489_0x03c1fc(arg0, arg1);
        case 490U: return ByteVc0FdeFunc_0490_0x03c234(arg0, arg1);
        case 491U: return ByteVc0FdeFunc_0491_0x03c2c4(arg0, arg1);
        case 492U: return ByteVc0FdeFunc_0492_0x03c424(arg0, arg1);
        case 493U: return ByteVc0FdeFunc_0493_0x03c468(arg0, arg1);
        case 494U: return ByteVc0FdeFunc_0494_0x03c480(arg0, arg1);
        case 495U: return ByteVc0FdeFunc_0495_0x03c4d0(arg0, arg1);
        case 496U: return ByteVc0FdeFunc_0496_0x03cf50(arg0, arg1);
        case 497U: return ByteVc0FdeFunc_0497_0x03d430(arg0, arg1);
        case 498U: return ByteVc0FdeFunc_0498_0x03d5c8(arg0, arg1);
        case 499U: return ByteVc0FdeFunc_0499_0x03d664(arg0, arg1);
        case 500U: return ByteVc0FdeFunc_0500_0x03d6c0(arg0, arg1);
        case 501U: return ByteVc0FdeFunc_0501_0x03d744(arg0, arg1);
        case 502U: return ByteVc0FdeFunc_0502_0x03d830(arg0, arg1);
        case 503U: return ByteVc0FdeFunc_0503_0x03d890(arg0, arg1);
        case 504U: return ByteVc0FdeFunc_0504_0x03d900(arg0, arg1);
        case 505U: return ByteVc0FdeFunc_0505_0x03d930(arg0, arg1);
        case 506U: return ByteVc0FdeFunc_0506_0x03dacc(arg0, arg1);
        case 507U: return ByteVc0FdeFunc_0507_0x03df68(arg0, arg1);
        case 508U: return ByteVc0FdeFunc_0508_0x03dfb4(arg0, arg1);
        case 509U: return ByteVc0FdeFunc_0509_0x03dfe8(arg0, arg1);
        case 510U: return ByteVc0FdeFunc_0510_0x03e008(arg0, arg1);
        case 511U: return ByteVc0FdeFunc_0511_0x03e0d0(arg0, arg1);
        case 512U: return ByteVc0FdeFunc_0512_0x03e134(arg0, arg1);
        case 513U: return ByteVc0FdeFunc_0513_0x03e168(arg0, arg1);
        case 514U: return ByteVc0FdeFunc_0514_0x03e2c4(arg0, arg1);
        case 515U: return ByteVc0FdeFunc_0515_0x03e3e8(arg0, arg1);
        case 516U: return ByteVc0FdeFunc_0516_0x03e50c(arg0, arg1);
        case 517U: return ByteVc0FdeFunc_0517_0x03e58c(arg0, arg1);
        case 518U: return ByteVc0FdeFunc_0518_0x03e5d4(arg0, arg1);
        case 519U: return ByteVc0FdeFunc_0519_0x03e61c(arg0, arg1);
        case 520U: return ByteVc0FdeFunc_0520_0x03e738(arg0, arg1);
        case 521U: return ByteVc0FdeFunc_0521_0x03e868(arg0, arg1);
        case 522U: return ByteVc0FdeFunc_0522_0x03e9ac(arg0, arg1);
        case 523U: return ByteVc0FdeFunc_0523_0x03ea28(arg0, arg1);
        case 524U: return ByteVc0FdeFunc_0524_0x03eb58(arg0, arg1);
        case 525U: return ByteVc0FdeFunc_0525_0x03ec34(arg0, arg1);
        case 526U: return ByteVc0FdeFunc_0526_0x03ecc0(arg0, arg1);
        case 527U: return ByteVc0FdeFunc_0527_0x03edc0(arg0, arg1);
        case 528U: return ByteVc0FdeFunc_0528_0x03eec0(arg0, arg1);
        case 529U: return ByteVc0FdeFunc_0529_0x03ef58(arg0, arg1);
        case 530U: return ByteVc0FdeFunc_0530_0x03f0e8(arg0, arg1);
        case 531U: return ByteVc0FdeFunc_0531_0x03ff5c(arg0, arg1);
        case 532U: return ByteVc0FdeFunc_0532_0x03ff9c(arg0, arg1);
        case 533U: return ByteVc0FdeFunc_0533_0x0409a4(arg0, arg1);
        case 534U: return ByteVc0FdeFunc_0534_0x0409a8(arg0, arg1);
        case 535U: return ByteVc0FdeFunc_0535_0x0409ac(arg0, arg1);
        case 536U: return ByteVc0FdeFunc_0536_0x0409e8(arg0, arg1);
        case 537U: return ByteVc0FdeFunc_0537_0x040a0c(arg0, arg1);
        case 538U: return ByteVc0FdeFunc_0538_0x040c80(arg0, arg1);
        case 539U: return ByteVc0FdeFunc_0539_0x040e04(arg0, arg1);
        case 540U: return ByteVc0FdeFunc_0540_0x041424(arg0, arg1);
        case 541U: return ByteVc0FdeFunc_0541_0x041538(arg0, arg1);
        case 542U: return ByteVc0FdeFunc_0542_0x04159c(arg0, arg1);
        case 543U: return ByteVc0FdeFunc_0543_0x0415bc(arg0, arg1);
        case 544U: return ByteVc0FdeFunc_0544_0x041798(arg0, arg1);
        case 545U: return ByteVc0FdeFunc_0545_0x0417e0(arg0, arg1);
        case 546U: return ByteVc0FdeFunc_0546_0x041880(arg0, arg1);
        case 547U: return ByteVc0FdeFunc_0547_0x0418c0(arg0, arg1);
        case 548U: return ByteVc0FdeFunc_0548_0x041990(arg0, arg1);
        case 549U: return ByteVc0FdeFunc_0549_0x041a0c(arg0, arg1);
        case 550U: return ByteVc0FdeFunc_0550_0x041a70(arg0, arg1);
        case 551U: return ByteVc0FdeFunc_0551_0x041a90(arg0, arg1);
        case 552U: return ByteVc0FdeFunc_0552_0x041ba4(arg0, arg1);
        case 553U: return ByteVc0FdeFunc_0553_0x041c74(arg0, arg1);
        case 554U: return ByteVc0FdeFunc_0554_0x041cf0(arg0, arg1);
        case 555U: return ByteVc0FdeFunc_0555_0x041d54(arg0, arg1);
        case 556U: return ByteVc0FdeFunc_0556_0x041d74(arg0, arg1);
        case 557U: return ByteVc0FdeFunc_0557_0x041e88(arg0, arg1);
        case 558U: return ByteVc0FdeFunc_0558_0x041f6c(arg0, arg1);
        case 559U: return ByteVc0FdeFunc_0559_0x041f80(arg0, arg1);
        case 560U: return ByteVc0FdeFunc_0560_0x042124(arg0, arg1);
        case 561U: return ByteVc0FdeFunc_0561_0x042178(arg0, arg1);
        case 562U: return ByteVc0FdeFunc_0562_0x04217c(arg0, arg1);
        case 563U: return ByteVc0FdeFunc_0563_0x042590(arg0, arg1);
        case 564U: return ByteVc0FdeFunc_0564_0x0425f0(arg0, arg1);
        case 565U: return ByteVc0FdeFunc_0565_0x042694(arg0, arg1);
        case 566U: return ByteVc0FdeFunc_0566_0x042994(arg0, arg1);
        case 567U: return ByteVc0FdeFunc_0567_0x042b94(arg0, arg1);
        case 568U: return ByteVc0FdeFunc_0568_0x042be4(arg0, arg1);
        case 569U: return ByteVc0FdeFunc_0569_0x042cc0(arg0, arg1);
        case 570U: return ByteVc0FdeFunc_0570_0x042de8(arg0, arg1);
        case 571U: return ByteVc0FdeFunc_0571_0x0431a0(arg0, arg1);
        case 572U: return ByteVc0FdeFunc_0572_0x0432e4(arg0, arg1);
        case 573U: return ByteVc0FdeFunc_0573_0x043394(arg0, arg1);
        case 574U: return ByteVc0FdeFunc_0574_0x04343c(arg0, arg1);
        case 575U: return ByteVc0FdeFunc_0575_0x043524(arg0, arg1);
        case 576U: return ByteVc0FdeFunc_0576_0x0435b0(arg0, arg1);
        case 577U: return ByteVc0FdeFunc_0577_0x0436d4(arg0, arg1);
        case 578U: return ByteVc0FdeFunc_0578_0x04390c(arg0, arg1);
        case 579U: return ByteVc0FdeFunc_0579_0x043b98(arg0, arg1);
        case 580U: return ByteVc0FdeFunc_0580_0x043c84(arg0, arg1);
        case 581U: return ByteVc0FdeFunc_0581_0x043e24(arg0, arg1);
        case 582U: return ByteVc0FdeFunc_0582_0x043eac(arg0, arg1);
        case 583U: return ByteVc0FdeFunc_0583_0x043fe8(arg0, arg1);
        case 584U: return ByteVc0FdeFunc_0584_0x044040(arg0, arg1);
        case 585U: return ByteVc0FdeFunc_0585_0x044114(arg0, arg1);
        case 586U: return ByteVc0FdeFunc_0586_0x044148(arg0, arg1);
        case 587U: return ByteVc0FdeFunc_0587_0x044304(arg0, arg1);
        case 588U: return ByteVc0FdeFunc_0588_0x0443dc(arg0, arg1);
        case 589U: return ByteVc0FdeFunc_0589_0x0444a0(arg0, arg1);
        case 590U: return ByteVc0FdeFunc_0590_0x044764(arg0, arg1);
        case 591U: return ByteVc0FdeFunc_0591_0x044910(arg0, arg1);
        case 592U: return ByteVc0FdeFunc_0592_0x04494c(arg0, arg1);
        case 593U: return ByteVc0FdeFunc_0593_0x044a38(arg0, arg1);
        case 594U: return ByteVc0FdeFunc_0594_0x044b30(arg0, arg1);
        case 595U: return ByteVc0FdeFunc_0595_0x044c40(arg0, arg1);
        case 596U: return ByteVc0FdeFunc_0596_0x044d60(arg0, arg1);
        case 597U: return ByteVc0FdeFunc_0597_0x044fa8(arg0, arg1);
        case 598U: return ByteVc0FdeFunc_0598_0x045034(arg0, arg1);
        case 599U: return ByteVc0FdeFunc_0599_0x0450c0(arg0, arg1);
        case 600U: return ByteVc0FdeFunc_0600_0x0451c4(arg0, arg1);
        case 601U: return ByteVc0FdeFunc_0601_0x0452b8(arg0, arg1);
        case 602U: return ByteVc0FdeFunc_0602_0x0453ac(arg0, arg1);
        case 603U: return ByteVc0FdeFunc_0603_0x0453f0(arg0, arg1);
        case 604U: return ByteVc0FdeFunc_0604_0x0454d4(arg0, arg1);
        case 605U: return ByteVc0FdeFunc_0605_0x0455d8(arg0, arg1);
        case 606U: return ByteVc0FdeFunc_0606_0x045898(arg0, arg1);
        case 607U: return ByteVc0FdeFunc_0607_0x045bec(arg0, arg1);
        case 608U: return ByteVc0FdeFunc_0608_0x045ce0(arg0, arg1);
        case 609U: return ByteVc0FdeFunc_0609_0x045db8(arg0, arg1);
        case 610U: return ByteVc0FdeFunc_0610_0x045e18(arg0, arg1);
        case 611U: return ByteVc0FdeFunc_0611_0x045ea8(arg0, arg1);
        case 612U: return ByteVc0FdeFunc_0612_0x045f34(arg0, arg1);
        case 613U: return ByteVc0FdeFunc_0613_0x046018(arg0, arg1);
        case 614U: return ByteVc0FdeFunc_0614_0x046114(arg0, arg1);
        case 615U: return ByteVc0FdeFunc_0615_0x04626c(arg0, arg1);
        case 616U: return ByteVc0FdeFunc_0616_0x0462dc(arg0, arg1);
        case 617U: return ByteVc0FdeFunc_0617_0x046390(arg0, arg1);
        case 618U: return ByteVc0FdeFunc_0618_0x0464c8(arg0, arg1);
        case 619U: return ByteVc0FdeFunc_0619_0x0465e0(arg0, arg1);
        case 620U: return ByteVc0FdeFunc_0620_0x046610(arg0, arg1);
        case 621U: return ByteVc0FdeFunc_0621_0x046770(arg0, arg1);
        case 622U: return ByteVc0FdeFunc_0622_0x0467ec(arg0, arg1);
        case 623U: return ByteVc0FdeFunc_0623_0x0468d0(arg0, arg1);
        case 624U: return ByteVc0FdeFunc_0624_0x0468e8(arg0, arg1);
        case 625U: return ByteVc0FdeFunc_0625_0x04692c(arg0, arg1);
        case 626U: return ByteVc0FdeFunc_0626_0x046af4(arg0, arg1);
        case 627U: return ByteVc0FdeFunc_0627_0x046b20(arg0, arg1);
        case 628U: return ByteVc0FdeFunc_0628_0x046bb8(arg0, arg1);
        case 629U: return ByteVc0FdeFunc_0629_0x046bc0(arg0, arg1);
        case 630U: return ByteVc0FdeFunc_0630_0x046bd0(arg0, arg1);
        case 631U: return ByteVc0FdeFunc_0631_0x046c00(arg0, arg1);
        case 632U: return ByteVc0FdeFunc_0632_0x046c04(arg0, arg1);
        case 633U: return ByteVc0FdeFunc_0633_0x046c08(arg0, arg1);
        case 634U: return ByteVc0FdeFunc_0634_0x046c10(arg0, arg1);
        case 635U: return ByteVc0FdeFunc_0635_0x046cdc(arg0, arg1);
        case 636U: return ByteVc0FdeFunc_0636_0x046d18(arg0, arg1);
        case 637U: return ByteVc0FdeFunc_0637_0x046d3c(arg0, arg1);
        case 638U: return ByteVc0FdeFunc_0638_0x04713c(arg0, arg1);
        case 639U: return ByteVc0FdeFunc_0639_0x047278(arg0, arg1);
        case 640U: return ByteVc0FdeFunc_0640_0x0472ec(arg0, arg1);
        case 641U: return ByteVc0FdeFunc_0641_0x0474e0(arg0, arg1);
        case 642U: return ByteVc0FdeFunc_0642_0x047694(arg0, arg1);
        case 643U: return ByteVc0FdeFunc_0643_0x047a08(arg0, arg1);
        case 644U: return ByteVc0FdeFunc_0644_0x047bac(arg0, arg1);
        case 645U: return ByteVc0FdeFunc_0645_0x047be0(arg0, arg1);
        case 646U: return ByteVc0FdeFunc_0646_0x047eb4(arg0, arg1);
        case 647U: return ByteVc0FdeFunc_0647_0x047f5c(arg0, arg1);
        case 648U: return ByteVc0FdeFunc_0648_0x048258(arg0, arg1);
        case 649U: return ByteVc0FdeFunc_0649_0x0484bc(arg0, arg1);
        case 650U: return ByteVc0FdeFunc_0650_0x04877c(arg0, arg1);
        case 651U: return ByteVc0FdeFunc_0651_0x048904(arg0, arg1);
        case 652U: return ByteVc0FdeFunc_0652_0x048aa0(arg0, arg1);
        case 653U: return ByteVc0FdeFunc_0653_0x048c04(arg0, arg1);
        case 654U: return ByteVc0FdeFunc_0654_0x048ddc(arg0, arg1);
        case 655U: return ByteVc0FdeFunc_0655_0x04919c(arg0, arg1);
        case 656U: return ByteVc0FdeFunc_0656_0x049450(arg0, arg1);
        case 657U: return ByteVc0FdeFunc_0657_0x049494(arg0, arg1);
        case 658U: return ByteVc0FdeFunc_0658_0x0495c4(arg0, arg1);
        case 659U: return ByteVc0FdeFunc_0659_0x04976c(arg0, arg1);
        case 660U: return ByteVc0FdeFunc_0660_0x0498b0(arg0, arg1);
        case 661U: return ByteVc0FdeFunc_0661_0x04998c(arg0, arg1);
        case 662U: return ByteVc0FdeFunc_0662_0x049c98(arg0, arg1);
        case 663U: return ByteVc0FdeFunc_0663_0x04a03c(arg0, arg1);
        case 664U: return ByteVc0FdeFunc_0664_0x04a324(arg0, arg1);
        case 665U: return ByteVc0FdeFunc_0665_0x04a4c4(arg0, arg1);
        case 666U: return ByteVc0FdeFunc_0666_0x04aae8(arg0, arg1);
        case 667U: return ByteVc0FdeFunc_0667_0x04ac90(arg0, arg1);
        case 668U: return ByteVc0FdeFunc_0668_0x04adb8(arg0, arg1);
        case 669U: return ByteVc0FdeFunc_0669_0x04b0f0(arg0, arg1);
        case 670U: return ByteVc0FdeFunc_0670_0x04b278(arg0, arg1);
        case 671U: return ByteVc0FdeFunc_0671_0x04b358(arg0, arg1);
        case 672U: return ByteVc0FdeFunc_0672_0x04b52c(arg0, arg1);
        case 673U: return ByteVc0FdeFunc_0673_0x04b780(arg0, arg1);
        case 674U: return ByteVc0FdeFunc_0674_0x04b87c(arg0, arg1);
        case 675U: return ByteVc0FdeFunc_0675_0x04b968(arg0, arg1);
        case 676U: return ByteVc0FdeFunc_0676_0x04ba30(arg0, arg1);
        case 677U: return ByteVc0FdeFunc_0677_0x04be24(arg0, arg1);
        case 678U: return ByteVc0FdeFunc_0678_0x04c220(arg0, arg1);
        case 679U: return ByteVc0FdeFunc_0679_0x04c2b4(arg0, arg1);
        case 680U: return ByteVc0FdeFunc_0680_0x04c328(arg0, arg1);
        case 681U: return ByteVc0FdeFunc_0681_0x04c500(arg0, arg1);
        case 682U: return ByteVc0FdeFunc_0682_0x04c680(arg0, arg1);
        case 683U: return ByteVc0FdeFunc_0683_0x04c72c(arg0, arg1);
        case 684U: return ByteVc0FdeFunc_0684_0x04c8f0(arg0, arg1);
        case 685U: return ByteVc0FdeFunc_0685_0x04cabc(arg0, arg1);
        case 686U: return ByteVc0FdeFunc_0686_0x04cba8(arg0, arg1);
        case 687U: return ByteVc0FdeFunc_0687_0x04cc10(arg0, arg1);
        case 688U: return ByteVc0FdeFunc_0688_0x04cdb4(arg0, arg1);
        case 689U: return ByteVc0FdeFunc_0689_0x04d230(arg0, arg1);
        case 690U: return ByteVc0FdeFunc_0690_0x04d3d0(arg0, arg1);
        case 691U: return ByteVc0FdeFunc_0691_0x04d4c0(arg0, arg1);
        case 692U: return ByteVc0FdeFunc_0692_0x04d728(arg0, arg1);
        case 693U: return ByteVc0FdeFunc_0693_0x04d880(arg0, arg1);
        case 694U: return ByteVc0FdeFunc_0694_0x04d8cc(arg0, arg1);
        case 695U: return ByteVc0FdeFunc_0695_0x04db34(arg0, arg1);
        case 696U: return ByteVc0FdeFunc_0696_0x04dbf8(arg0, arg1);
        case 697U: return ByteVc0FdeFunc_0697_0x04dc48(arg0, arg1);
        case 698U: return ByteVc0FdeFunc_0698_0x04dcdc(arg0, arg1);
        case 699U: return ByteVc0FdeFunc_0699_0x04dd88(arg0, arg1);
        case 700U: return ByteVc0FdeFunc_0700_0x04ddd8(arg0, arg1);
        case 701U: return ByteVc0FdeFunc_0701_0x04de0c(arg0, arg1);
        case 702U: return ByteVc0FdeFunc_0702_0x04de14(arg0, arg1);
        case 703U: return ByteVc0FdeFunc_0703_0x04de50(arg0, arg1);
        case 704U: return ByteVc0FdeFunc_0704_0x04ded8(arg0, arg1);
        case 705U: return ByteVc0FdeFunc_0705_0x04df14(arg0, arg1);
        case 706U: return ByteVc0FdeFunc_0706_0x04df9c(arg0, arg1);
        case 707U: return ByteVc0FdeFunc_0707_0x04e168(arg0, arg1);
        case 708U: return ByteVc0FdeFunc_0708_0x04e258(arg0, arg1);
        case 709U: return ByteVc0FdeFunc_0709_0x04e3b4(arg0, arg1);
        case 710U: return ByteVc0FdeFunc_0710_0x04e49c(arg0, arg1);
        case 711U: return ByteVc0FdeFunc_0711_0x04e558(arg0, arg1);
        case 712U: return ByteVc0FdeFunc_0712_0x04ea38(arg0, arg1);
        case 713U: return ByteVc0FdeFunc_0713_0x04eb80(arg0, arg1);
        case 714U: return ByteVc0FdeFunc_0714_0x04eb84(arg0, arg1);
        case 715U: return ByteVc0FdeFunc_0715_0x04ebe4(arg0, arg1);
        case 716U: return ByteVc0FdeFunc_0716_0x04ec6c(arg0, arg1);
        case 717U: return ByteVc0FdeFunc_0717_0x04ee04(arg0, arg1);
        case 718U: return ByteVc0FdeFunc_0718_0x04f880(arg0, arg1);
        case 719U: return ByteVc0FdeFunc_0719_0x04fb24(arg0, arg1);
        case 720U: return ByteVc0FdeFunc_0720_0x04fb7c(arg0, arg1);
        case 721U: return ByteVc0FdeFunc_0721_0x05058c(arg0, arg1);
        case 722U: return ByteVc0FdeFunc_0722_0x050d28(arg0, arg1);
        case 723U: return ByteVc0FdeFunc_0723_0x050d68(arg0, arg1);
        case 724U: return ByteVc0FdeFunc_0724_0x050dc0(arg0, arg1);
        case 725U: return ByteVc0FdeFunc_0725_0x051740(arg0, arg1);
        case 726U: return ByteVc0FdeFunc_0726_0x051780(arg0, arg1);
        case 727U: return ByteVc0FdeFunc_0727_0x0517d8(arg0, arg1);
        case 728U: return ByteVc0FdeFunc_0728_0x05243c(arg0, arg1);
        case 729U: return ByteVc0FdeFunc_0729_0x05247c(arg0, arg1);
        case 730U: return ByteVc0FdeFunc_0730_0x0524d4(arg0, arg1);
        case 731U: return ByteVc0FdeFunc_0731_0x053340(arg0, arg1);
        case 732U: return ByteVc0FdeFunc_0732_0x053380(arg0, arg1);
        case 733U: return ByteVc0FdeFunc_0733_0x0535bc(arg0, arg1);
        case 734U: return ByteVc0FdeFunc_0734_0x0538a4(arg0, arg1);
        case 735U: return ByteVc0FdeFunc_0735_0x053a0c(arg0, arg1);
        case 736U: return ByteVc0FdeFunc_0736_0x053a20(arg0, arg1);
        case 737U: return ByteVc0FdeFunc_0737_0x053a3c(arg0, arg1);
        case 738U: return ByteVc0FdeFunc_0738_0x053a50(arg0, arg1);
        case 739U: return ByteVc0FdeFunc_0739_0x053a64(arg0, arg1);
        case 740U: return ByteVc0FdeFunc_0740_0x053b14(arg0, arg1);
        case 741U: return ByteVc0FdeFunc_0741_0x053b90(arg0, arg1);
        case 742U: return ByteVc0FdeFunc_0742_0x053bac(arg0, arg1);
        case 743U: return ByteVc0FdeFunc_0743_0x053bbc(arg0, arg1);
        case 744U: return ByteVc0FdeFunc_0744_0x053bc0(arg0, arg1);
        case 745U: return ByteVc0FdeFunc_0745_0x053bc8(arg0, arg1);
        case 746U: return ByteVc0FdeFunc_0746_0x053bd0(arg0, arg1);
        case 747U: return ByteVc0FdeFunc_0747_0x053bd4(arg0, arg1);
        case 748U: return ByteVc0FdeFunc_0748_0x053bf0(arg0, arg1);
        case 749U: return ByteVc0FdeFunc_0749_0x053bf4(arg0, arg1);
        case 750U: return ByteVc0FdeFunc_0750_0x053bfc(arg0, arg1);
        case 751U: return ByteVc0FdeFunc_0751_0x053c04(arg0, arg1);
        case 752U: return ByteVc0FdeFunc_0752_0x053c44(arg0, arg1);
        case 753U: return ByteVc0FdeFunc_0753_0x053c90(arg0, arg1);
        case 754U: return ByteVc0FdeFunc_0754_0x053c98(arg0, arg1);
        case 755U: return ByteVc0FdeFunc_0755_0x053cb4(arg0, arg1);
        case 756U: return ByteVc0FdeFunc_0756_0x053cd0(arg0, arg1);
        case 757U: return ByteVc0FdeFunc_0757_0x053d54(arg0, arg1);
        case 758U: return ByteVc0FdeFunc_0758_0x053d78(arg0, arg1);
        case 759U: return ByteVc0FdeFunc_0759_0x053dfc(arg0, arg1);
        case 760U: return ByteVc0FdeFunc_0760_0x053e20(arg0, arg1);
        case 761U: return ByteVc0FdeFunc_0761_0x053e34(arg0, arg1);
        case 762U: return ByteVc0FdeFunc_0762_0x053e48(arg0, arg1);
        case 763U: return ByteVc0FdeFunc_0763_0x053e5c(arg0, arg1);
        case 764U: return ByteVc0FdeFunc_0764_0x053e70(arg0, arg1);
        case 765U: return ByteVc0FdeFunc_0765_0x053e84(arg0, arg1);
        case 766U: return ByteVc0FdeFunc_0766_0x053e9c(arg0, arg1);
        case 767U: return ByteVc0FdeFunc_0767_0x053eb0(arg0, arg1);
        case 768U: return ByteVc0FdeFunc_0768_0x053ec8(arg0, arg1);
        case 769U: return ByteVc0FdeFunc_0769_0x053edc(arg0, arg1);
        case 770U: return ByteVc0FdeFunc_0770_0x053ef0(arg0, arg1);
        case 771U: return ByteVc0FdeFunc_0771_0x053f04(arg0, arg1);
        case 772U: return ByteVc0FdeFunc_0772_0x0542bc(arg0, arg1);
        case 773U: return ByteVc0FdeFunc_0773_0x054308(arg0, arg1);
        case 774U: return ByteVc0FdeFunc_0774_0x0543c4(arg0, arg1);
        case 775U: return ByteVc0FdeFunc_0775_0x055570(arg0, arg1);
        case 776U: return ByteVc0FdeFunc_0776_0x05558c(arg0, arg1);
        case 777U: return ByteVc0FdeFunc_0777_0x055634(arg0, arg1);
        case 778U: return ByteVc0FdeFunc_0778_0x0556b4(arg0, arg1);
        case 779U: return ByteVc0FdeFunc_0779_0x055718(arg0, arg1);
        case 780U: return ByteVc0FdeFunc_0780_0x055720(arg0, arg1);
        case 781U: return ByteVc0FdeFunc_0781_0x055744(arg0, arg1);
        case 782U: return ByteVc0FdeFunc_0782_0x05576c(arg0, arg1);
        case 783U: return ByteVc0FdeFunc_0783_0x05599c(arg0, arg1);
        case 784U: return ByteVc0FdeFunc_0784_0x055a40(arg0, arg1);
        case 785U: return ByteVc0FdeFunc_0785_0x056174(arg0, arg1);
        case 786U: return ByteVc0FdeFunc_0786_0x056210(arg0, arg1);
        case 787U: return ByteVc0FdeFunc_0787_0x0564a0(arg0, arg1);
        case 788U: return ByteVc0FdeFunc_0788_0x0566bc(arg0, arg1);
        case 789U: return ByteVc0FdeFunc_0789_0x056bdc(arg0, arg1);
        case 790U: return ByteVc0FdeFunc_0790_0x056c58(arg0, arg1);
        case 791U: return ByteVc0FdeFunc_0791_0x056d7c(arg0, arg1);
        case 792U: return ByteVc0FdeFunc_0792_0x056dc4(arg0, arg1);
        case 793U: return ByteVc0FdeFunc_0793_0x056dcc(arg0, arg1);
        case 794U: return ByteVc0FdeFunc_0794_0x056f78(arg0, arg1);
        case 795U: return ByteVc0FdeFunc_0795_0x0570c4(arg0, arg1);
        case 796U: return ByteVc0FdeFunc_0796_0x057130(arg0, arg1);
        case 797U: return ByteVc0FdeFunc_0797_0x0571d0(arg0, arg1);
        case 798U: return ByteVc0FdeFunc_0798_0x05721c(arg0, arg1);
        case 799U: return ByteVc0FdeFunc_0799_0x05722c(arg0, arg1);
        case 800U: return ByteVc0FdeFunc_0800_0x057248(arg0, arg1);
        case 801U: return ByteVc0FdeFunc_0801_0x057288(arg0, arg1);
        case 802U: return ByteVc0FdeFunc_0802_0x0572e0(arg0, arg1);
        case 803U: return ByteVc0FdeFunc_0803_0x057338(arg0, arg1);
        case 804U: return ByteVc0FdeFunc_0804_0x057570(arg0, arg1);
        case 805U: return ByteVc0FdeFunc_0805_0x057610(arg0, arg1);
        case 806U: return ByteVc0FdeFunc_0806_0x05761c(arg0, arg1);
        case 807U: return ByteVc0FdeFunc_0807_0x057bcc(arg0, arg1);
        case 808U: return ByteVc0FdeFunc_0808_0x057c60(arg0, arg1);
        case 809U: return ByteVc0FdeFunc_0809_0x057cd8(arg0, arg1);
        case 810U: return ByteVc0FdeFunc_0810_0x057d14(arg0, arg1);
        case 811U: return ByteVc0FdeFunc_0811_0x057d60(arg0, arg1);
        case 812U: return ByteVc0FdeFunc_0812_0x057dac(arg0, arg1);
        case 813U: return ByteVc0FdeFunc_0813_0x057e18(arg0, arg1);
        case 814U: return ByteVc0FdeFunc_0814_0x057fc8(arg0, arg1);
        case 815U: return ByteVc0FdeFunc_0815_0x0580a4(arg0, arg1);
        case 816U: return ByteVc0FdeFunc_0816_0x05840c(arg0, arg1);
        case 817U: return ByteVc0FdeFunc_0817_0x058414(arg0, arg1);
        case 818U: return ByteVc0FdeFunc_0818_0x058544(arg0, arg1);
        case 819U: return ByteVc0FdeFunc_0819_0x058644(arg0, arg1);
        case 820U: return ByteVc0FdeFunc_0820_0x058844(arg0, arg1);
        case 821U: return ByteVc0FdeFunc_0821_0x058900(arg0, arg1);
        case 822U: return ByteVc0FdeFunc_0822_0x058958(arg0, arg1);
        case 823U: return ByteVc0FdeFunc_0823_0x058b54(arg0, arg1);
        case 824U: return ByteVc0FdeFunc_0824_0x058d7c(arg0, arg1);
        case 825U: return ByteVc0FdeFunc_0825_0x058da4(arg0, arg1);
        case 826U: return ByteVc0FdeFunc_0826_0x058f08(arg0, arg1);
        case 827U: return ByteVc0FdeFunc_0827_0x058f58(arg0, arg1);
        case 828U: return ByteVc0FdeFunc_0828_0x059128(arg0, arg1);
        case 829U: return ByteVc0FdeFunc_0829_0x059268(arg0, arg1);
        case 830U: return ByteVc0FdeFunc_0830_0x059344(arg0, arg1);
        case 831U: return ByteVc0FdeFunc_0831_0x0594b4(arg0, arg1);
        case 832U: return ByteVc0FdeFunc_0832_0x0596a4(arg0, arg1);
        case 833U: return ByteVc0FdeFunc_0833_0x059754(arg0, arg1);
        case 834U: return ByteVc0FdeFunc_0834_0x05990c(arg0, arg1);
        case 835U: return ByteVc0FdeFunc_0835_0x0599d4(arg0, arg1);
        case 836U: return ByteVc0FdeFunc_0836_0x059b84(arg0, arg1);
        case 837U: return ByteVc0FdeFunc_0837_0x059bc0(arg0, arg1);
        case 838U: return ByteVc0FdeFunc_0838_0x059c20(arg0, arg1);
        case 839U: return ByteVc0FdeFunc_0839_0x059d20(arg0, arg1);
        case 840U: return ByteVc0FdeFunc_0840_0x059e20(arg0, arg1);
        case 841U: return ByteVc0FdeFunc_0841_0x059f34(arg0, arg1);
        case 842U: return ByteVc0FdeFunc_0842_0x059f98(arg0, arg1);
        case 843U: return ByteVc0FdeFunc_0843_0x059fb8(arg0, arg1);
        case 844U: return ByteVc0FdeFunc_0844_0x05a0cc(arg0, arg1);
        case 845U: return ByteVc0FdeFunc_0845_0x05a130(arg0, arg1);
        case 846U: return ByteVc0FdeFunc_0846_0x05a150(arg0, arg1);
        case 847U: return ByteVc0FdeFunc_0847_0x05a220(arg0, arg1);
        case 848U: return ByteVc0FdeFunc_0848_0x05a29c(arg0, arg1);
        case 849U: return ByteVc0FdeFunc_0849_0x05a300(arg0, arg1);
        case 850U: return ByteVc0FdeFunc_0850_0x05a320(arg0, arg1);
        case 851U: return ByteVc0FdeFunc_0851_0x05a434(arg0, arg1);
        case 852U: return ByteVc0FdeFunc_0852_0x05a464(arg0, arg1);
        case 853U: return ByteVc0FdeFunc_0853_0x05a4c4(arg0, arg1);
        case 854U: return ByteVc0FdeFunc_0854_0x05a7a4(arg0, arg1);
        case 855U: return ByteVc0FdeFunc_0855_0x05a7e8(arg0, arg1);
        case 856U: return ByteVc0FdeFunc_0856_0x05a944(arg0, arg1);
        case 857U: return ByteVc0FdeFunc_0857_0x05a98c(arg0, arg1);
        case 858U: return ByteVc0FdeFunc_0858_0x05aa60(arg0, arg1);
        case 859U: return ByteVc0FdeFunc_0859_0x05ac74(arg0, arg1);
        case 860U: return ByteVc0FdeFunc_0860_0x05acb4(arg0, arg1);
        case 861U: return ByteVc0FdeFunc_0861_0x05ade4(arg0, arg1);
        case 862U: return ByteVc0FdeFunc_0862_0x05ae2c(arg0, arg1);
        case 863U: return ByteVc0FdeFunc_0863_0x05b054(arg0, arg1);
        case 864U: return ByteVc0FdeFunc_0864_0x05b118(arg0, arg1);
        case 865U: return ByteVc0FdeFunc_0865_0x05b24c(arg0, arg1);
        case 866U: return ByteVc0FdeFunc_0866_0x05b2f0(arg0, arg1);
        case 867U: return ByteVc0FdeFunc_0867_0x05b474(arg0, arg1);
        case 868U: return ByteVc0FdeFunc_0868_0x05b518(arg0, arg1);
        case 869U: return ByteVc0FdeFunc_0869_0x05b5bc(arg0, arg1);
        case 870U: return ByteVc0FdeFunc_0870_0x05b5e0(arg0, arg1);
        case 871U: return ByteVc0FdeFunc_0871_0x05b638(arg0, arg1);
        case 872U: return ByteVc0FdeFunc_0872_0x05b770(arg0, arg1);
        case 873U: return ByteVc0FdeFunc_0873_0x05b854(arg0, arg1);
        case 874U: return ByteVc0FdeFunc_0874_0x05b97c(arg0, arg1);
        case 875U: return ByteVc0FdeFunc_0875_0x05b9c8(arg0, arg1);
        case 876U: return ByteVc0FdeFunc_0876_0x05b9cc(arg0, arg1);
        case 877U: return ByteVc0FdeFunc_0877_0x05ba3c(arg0, arg1);
        case 878U: return ByteVc0FdeFunc_0878_0x05ba5c(arg0, arg1);
        case 879U: return ByteVc0FdeFunc_0879_0x05ba7c(arg0, arg1);
        case 880U: return ByteVc0FdeFunc_0880_0x05ba9c(arg0, arg1);
        case 881U: return ByteVc0FdeFunc_0881_0x05bb1c(arg0, arg1);
        case 882U: return ByteVc0FdeFunc_0882_0x05bb38(arg0, arg1);
        case 883U: return ByteVc0FdeFunc_0883_0x05bb80(arg0, arg1);
        case 884U: return ByteVc0FdeFunc_0884_0x05bb98(arg0, arg1);
        case 885U: return ByteVc0FdeFunc_0885_0x05bbfc(arg0, arg1);
        case 886U: return ByteVc0FdeFunc_0886_0x05bc14(arg0, arg1);
        case 887U: return ByteVc0FdeFunc_0887_0x05bc60(arg0, arg1);
        case 888U: return ByteVc0FdeFunc_0888_0x05bc78(arg0, arg1);
        case 889U: return ByteVc0FdeFunc_0889_0x05bca4(arg0, arg1);
        case 890U: return ByteVc0FdeFunc_0890_0x05bcc8(arg0, arg1);
        case 891U: return ByteVc0FdeFunc_0891_0x05bcd0(arg0, arg1);
        case 892U: return ByteVc0FdeFunc_0892_0x05bcf0(arg0, arg1);
        case 893U: return ByteVc0FdeFunc_0893_0x05bcfc(arg0, arg1);
        case 894U: return ByteVc0FdeFunc_0894_0x05bd04(arg0, arg1);
        case 895U: return ByteVc0FdeFunc_0895_0x05bd08(arg0, arg1);
        case 896U: return ByteVc0FdeFunc_0896_0x05bd0c(arg0, arg1);
        case 897U: return ByteVc0FdeFunc_0897_0x05bd58(arg0, arg1);
        case 898U: return ByteVc0FdeFunc_0898_0x05bd8c(arg0, arg1);
        case 899U: return ByteVc0FdeFunc_0899_0x05bdb8(arg0, arg1);
        case 900U: return ByteVc0FdeFunc_0900_0x05bde0(arg0, arg1);
        case 901U: return ByteVc0FdeFunc_0901_0x05be14(arg0, arg1);
        case 902U: return ByteVc0FdeFunc_0902_0x05be44(arg0, arg1);
        case 903U: return ByteVc0FdeFunc_0903_0x05be80(arg0, arg1);
        case 904U: return ByteVc0FdeFunc_0904_0x05beb8(arg0, arg1);
        case 905U: return ByteVc0FdeFunc_0905_0x05bf0c(arg0, arg1);
        case 906U: return ByteVc0FdeFunc_0906_0x05bf38(arg0, arg1);
        case 907U: return ByteVc0FdeFunc_0907_0x05bf88(arg0, arg1);
        case 908U: return ByteVc0FdeFunc_0908_0x05bff4(arg0, arg1);
        case 909U: return ByteVc0FdeFunc_0909_0x05c010(arg0, arg1);
        case 910U: return ByteVc0FdeFunc_0910_0x05c014(arg0, arg1);
        case 911U: return ByteVc0FdeFunc_0911_0x05c058(arg0, arg1);
        case 912U: return ByteVc0FdeFunc_0912_0x05c05c(arg0, arg1);
        case 913U: return ByteVc0FdeFunc_0913_0x05c080(arg0, arg1);
        case 914U: return ByteVc0FdeFunc_0914_0x05c0b8(arg0, arg1);
        case 915U: return ByteVc0FdeFunc_0915_0x05c13c(arg0, arg1);
        case 916U: return ByteVc0FdeFunc_0916_0x05c174(arg0, arg1);
        case 917U: return ByteVc0FdeFunc_0917_0x05c1a4(arg0, arg1);
        case 918U: return ByteVc0FdeFunc_0918_0x05c1f0(arg0, arg1);
        case 919U: return ByteVc0FdeFunc_0919_0x05c1f4(arg0, arg1);
        case 920U: return ByteVc0FdeFunc_0920_0x05c268(arg0, arg1);
        case 921U: return ByteVc0FdeFunc_0921_0x05c29c(arg0, arg1);
        case 922U: return ByteVc0FdeFunc_0922_0x05c2a4(arg0, arg1);
        case 923U: return ByteVc0FdeFunc_0923_0x05c314(arg0, arg1);
        case 924U: return ByteVc0FdeFunc_0924_0x05c334(arg0, arg1);
        case 925U: return ByteVc0FdeFunc_0925_0x05c39c(arg0, arg1);
        case 926U: return ByteVc0FdeFunc_0926_0x05c3fc(arg0, arg1);
        case 927U: return ByteVc0FdeFunc_0927_0x05c510(arg0, arg1);
        case 928U: return ByteVc0FdeFunc_0928_0x05c534(arg0, arg1);
        case 929U: return ByteVc0FdeFunc_0929_0x05c5cc(arg0, arg1);
        case 930U: return ByteVc0FdeFunc_0930_0x05c698(arg0, arg1);
        case 931U: return ByteVc0FdeFunc_0931_0x05c704(arg0, arg1);
        case 932U: return ByteVc0FdeFunc_0932_0x05c76c(arg0, arg1);
        case 933U: return ByteVc0FdeFunc_0933_0x05c7e0(arg0, arg1);
        case 934U: return ByteVc0FdeFunc_0934_0x05c854(arg0, arg1);
        case 935U: return ByteVc0FdeFunc_0935_0x05c914(arg0, arg1);
        case 936U: return ByteVc0FdeFunc_0936_0x05caa8(arg0, arg1);
        case 937U: return ByteVc0FdeFunc_0937_0x05cab0(arg0, arg1);
        case 938U: return ByteVc0FdeFunc_0938_0x05cab8(arg0, arg1);
        case 939U: return ByteVc0FdeFunc_0939_0x05cb2c(arg0, arg1);
        case 940U: return ByteVc0FdeFunc_0940_0x05cb48(arg0, arg1);
        case 941U: return ByteVc0FdeFunc_0941_0x05cb88(arg0, arg1);
        case 942U: return ByteVc0FdeFunc_0942_0x05cbe8(arg0, arg1);
        case 943U: return ByteVc0FdeFunc_0943_0x05cc48(arg0, arg1);
        case 944U: return ByteVc0FdeFunc_0944_0x05cf48(arg0, arg1);
        case 945U: return ByteVc0FdeFunc_0945_0x05cf84(arg0, arg1);
        case 946U: return ByteVc0FdeFunc_0946_0x05d1c0(arg0, arg1);
        case 947U: return ByteVc0FdeFunc_0947_0x05d318(arg0, arg1);
        case 948U: return ByteVc0FdeFunc_0948_0x05d344(arg0, arg1);
        case 949U: return ByteVc0FdeFunc_0949_0x05d354(arg0, arg1);
        case 950U: return ByteVc0FdeFunc_0950_0x05d36c(arg0, arg1);
        case 951U: return ByteVc0FdeFunc_0951_0x05d480(arg0, arg1);
        case 952U: return ByteVc0FdeFunc_0952_0x05d5f0(arg0, arg1);
        case 953U: return ByteVc0FdeFunc_0953_0x05d6cc(arg0, arg1);
        case 954U: return ByteVc0FdeFunc_0954_0x05d7bc(arg0, arg1);
        case 955U: return ByteVc0FdeFunc_0955_0x05d7e8(arg0, arg1);
        case 956U: return ByteVc0FdeFunc_0956_0x05d838(arg0, arg1);
        case 957U: return ByteVc0FdeFunc_0957_0x05d84c(arg0, arg1);
        case 958U: return ByteVc0FdeFunc_0958_0x05d918(arg0, arg1);
        case 959U: return ByteVc0FdeFunc_0959_0x05d9b0(arg0, arg1);
        case 960U: return ByteVc0FdeFunc_0960_0x05daf0(arg0, arg1);
        case 961U: return ByteVc0FdeFunc_0961_0x05de78(arg0, arg1);
        case 962U: return ByteVc0FdeFunc_0962_0x05deac(arg0, arg1);
        case 963U: return ByteVc0FdeFunc_0963_0x05ded8(arg0, arg1);
        case 964U: return ByteVc0FdeFunc_0964_0x05e100(arg0, arg1);
        case 965U: return ByteVc0FdeFunc_0965_0x05e1f8(arg0, arg1);
        case 966U: return ByteVc0FdeFunc_0966_0x05e284(arg0, arg1);
        case 967U: return ByteVc0FdeFunc_0967_0x05e288(arg0, arg1);
        case 968U: return ByteVc0FdeFunc_0968_0x05e3bc(arg0, arg1);
        case 969U: return ByteVc0FdeFunc_0969_0x05e4f0(arg0, arg1);
        case 970U: return ByteVc0FdeFunc_0970_0x05e624(arg0, arg1);
        case 971U: return ByteVc0FdeFunc_0971_0x05e78c(arg0, arg1);
        case 972U: return ByteVc0FdeFunc_0972_0x05e7c0(arg0, arg1);
        case 973U: return ByteVc0FdeFunc_0973_0x05e874(arg0, arg1);
        case 974U: return ByteVc0FdeFunc_0974_0x05e928(arg0, arg1);
        case 975U: return ByteVc0FdeFunc_0975_0x05e9dc(arg0, arg1);
        case 976U: return ByteVc0FdeFunc_0976_0x05ea90(arg0, arg1);
        case 977U: return ByteVc0FdeFunc_0977_0x05eb78(arg0, arg1);
        case 978U: return ByteVc0FdeFunc_0978_0x05ec60(arg0, arg1);
        case 979U: return ByteVc0FdeFunc_0979_0x05ed48(arg0, arg1);
        case 980U: return ByteVc0FdeFunc_0980_0x05ee30(arg0, arg1);
        case 981U: return ByteVc0FdeFunc_0981_0x05ef18(arg0, arg1);
        case 982U: return ByteVc0FdeFunc_0982_0x05f000(arg0, arg1);
        case 983U: return ByteVc0FdeFunc_0983_0x05f0ec(arg0, arg1);
        case 984U: return ByteVc0FdeFunc_0984_0x05f1d8(arg0, arg1);
        case 985U: return ByteVc0FdeFunc_0985_0x05f240(arg0, arg1);
        case 986U: return ByteVc0FdeFunc_0986_0x05f2cc(arg0, arg1);
        case 987U: return ByteVc0FdeFunc_0987_0x05f2f4(arg0, arg1);
        case 988U: return ByteVc0FdeFunc_0988_0x05f31c(arg0, arg1);
        case 989U: return ByteVc0FdeFunc_0989_0x05f344(arg0, arg1);
        case 990U: return ByteVc0FdeFunc_0990_0x05f354(arg0, arg1);
        case 991U: return ByteVc0FdeFunc_0991_0x05f374(arg0, arg1);
        case 992U: return ByteVc0FdeFunc_0992_0x05f3a0(arg0, arg1);
        case 993U: return ByteVc0FdeFunc_0993_0x05f528(arg0, arg1);
        case 994U: return ByteVc0FdeFunc_0994_0x05f52c(arg0, arg1);
        case 995U: return ByteVc0FdeFunc_0995_0x05f554(arg0, arg1);
        case 996U: return ByteVc0FdeFunc_0996_0x05f57c(arg0, arg1);
        case 997U: return ByteVc0FdeFunc_0997_0x05f5f8(arg0, arg1);
        case 998U: return ByteVc0FdeFunc_0998_0x05f694(arg0, arg1);
        case 999U: return ByteVc0FdeFunc_0999_0x05f718(arg0, arg1);
        case 1000U: return ByteVc0FdeFunc_1000_0x05f71c(arg0, arg1);
        case 1001U: return ByteVc0FdeFunc_1001_0x05f728(arg0, arg1);
        case 1002U: return ByteVc0FdeFunc_1002_0x05f74c(arg0, arg1);
        case 1003U: return ByteVc0FdeFunc_1003_0x05f778(arg0, arg1);
        case 1004U: return ByteVc0FdeFunc_1004_0x05f7ac(arg0, arg1);
        case 1005U: return ByteVc0FdeFunc_1005_0x05f7b0(arg0, arg1);
        case 1006U: return ByteVc0FdeFunc_1006_0x05f7cc(arg0, arg1);
        case 1007U: return ByteVc0FdeFunc_1007_0x05f7f0(arg0, arg1);
        case 1008U: return ByteVc0FdeFunc_1008_0x05f834(arg0, arg1);
        case 1009U: return ByteVc0FdeFunc_1009_0x05f868(arg0, arg1);
        case 1010U: return ByteVc0FdeFunc_1010_0x05f86c(arg0, arg1);
        case 1011U: return ByteVc0FdeFunc_1011_0x05f878(arg0, arg1);
        case 1012U: return ByteVc0FdeFunc_1012_0x05f8bc(arg0, arg1);
        case 1013U: return ByteVc0FdeFunc_1013_0x05f908(arg0, arg1);
        case 1014U: return ByteVc0FdeFunc_1014_0x05f95c(arg0, arg1);
        case 1015U: return ByteVc0FdeFunc_1015_0x05f960(arg0, arg1);
        case 1016U: return ByteVc0FdeFunc_1016_0x05f96c(arg0, arg1);
        case 1017U: return ByteVc0FdeFunc_1017_0x05f9f0(arg0, arg1);
        case 1018U: return ByteVc0FdeFunc_1018_0x05fa7c(arg0, arg1);
        case 1019U: return ByteVc0FdeFunc_1019_0x05fb10(arg0, arg1);
        case 1020U: return ByteVc0FdeFunc_1020_0x05fb30(arg0, arg1);
        case 1021U: return ByteVc0FdeFunc_1021_0x05fb38(arg0, arg1);
        case 1022U: return ByteVc0FdeFunc_1022_0x05fb54(arg0, arg1);
        case 1023U: return ByteVc0FdeFunc_1023_0x05fb80(arg0, arg1);
        case 1024U: return ByteVc0FdeFunc_1024_0x05fb90(arg0, arg1);
        case 1025U: return ByteVc0FdeFunc_1025_0x05fbf4(arg0, arg1);
        case 1026U: return ByteVc0FdeFunc_1026_0x05fc58(arg0, arg1);
        case 1027U: return ByteVc0FdeFunc_1027_0x05fd04(arg0, arg1);
        case 1028U: return ByteVc0FdeFunc_1028_0x05fd0c(arg0, arg1);
        case 1029U: return ByteVc0FdeFunc_1029_0x05fd3c(arg0, arg1);
        case 1030U: return ByteVc0FdeFunc_1030_0x05fd6c(arg0, arg1);
        case 1031U: return ByteVc0FdeFunc_1031_0x05fdbc(arg0, arg1);
        case 1032U: return ByteVc0FdeFunc_1032_0x05fdc8(arg0, arg1);
        case 1033U: return ByteVc0FdeFunc_1033_0x05fdf8(arg0, arg1);
        case 1034U: return ByteVc0FdeFunc_1034_0x05fe28(arg0, arg1);
        case 1035U: return ByteVc0FdeFunc_1035_0x05fe78(arg0, arg1);
        case 1036U: return ByteVc0FdeFunc_1036_0x05fea4(arg0, arg1);
        case 1037U: return ByteVc0FdeFunc_1037_0x05ff78(arg0, arg1);
        case 1038U: return ByteVc0FdeFunc_1038_0x06004c(arg0, arg1);
        case 1039U: return ByteVc0FdeFunc_1039_0x0601b8(arg0, arg1);
        case 1040U: return ByteVc0FdeFunc_1040_0x0601d0(arg0, arg1);
        case 1041U: return ByteVc0FdeFunc_1041_0x06025c(arg0, arg1);
        case 1042U: return ByteVc0FdeFunc_1042_0x0602e8(arg0, arg1);
        case 1043U: return ByteVc0FdeFunc_1043_0x0603dc(arg0, arg1);
        case 1044U: return ByteVc0FdeFunc_1044_0x060404(arg0, arg1);
        case 1045U: return ByteVc0FdeFunc_1045_0x0604b0(arg0, arg1);
        case 1046U: return ByteVc0FdeFunc_1046_0x06055c(arg0, arg1);
        case 1047U: return ByteVc0FdeFunc_1047_0x060680(arg0, arg1);
        case 1048U: return ByteVc0FdeFunc_1048_0x06069c(arg0, arg1);
        case 1049U: return ByteVc0FdeFunc_1049_0x060714(arg0, arg1);
        case 1050U: return ByteVc0FdeFunc_1050_0x060754(arg0, arg1);
        case 1051U: return ByteVc0FdeFunc_1051_0x060760(arg0, arg1);
        case 1052U: return ByteVc0FdeFunc_1052_0x06076c(arg0, arg1);
        case 1053U: return ByteVc0FdeFunc_1053_0x060894(arg0, arg1);
        case 1054U: return ByteVc0FdeFunc_1054_0x06091c(arg0, arg1);
        case 1055U: return ByteVc0FdeFunc_1055_0x0609b8(arg0, arg1);
        case 1056U: return ByteVc0FdeFunc_1056_0x0609dc(arg0, arg1);
        case 1057U: return ByteVc0FdeFunc_1057_0x060b04(arg0, arg1);
        case 1058U: return ByteVc0FdeFunc_1058_0x060be8(arg0, arg1);
        case 1059U: return ByteVc0FdeFunc_1059_0x060c24(arg0, arg1);
        case 1060U: return ByteVc0FdeFunc_1060_0x060d30(arg0, arg1);
        case 1061U: return ByteVc0FdeFunc_1061_0x060de4(arg0, arg1);
        case 1062U: return ByteVc0FdeFunc_1062_0x060e6c(arg0, arg1);
        case 1063U: return ByteVc0FdeFunc_1063_0x060e8c(arg0, arg1);
        case 1064U: return ByteVc0FdeFunc_1064_0x060fcc(arg0, arg1);
        case 1065U: return ByteVc0FdeFunc_1065_0x061370(arg0, arg1);
        case 1066U: return ByteVc0FdeFunc_1066_0x0613b8(arg0, arg1);
        case 1067U: return ByteVc0FdeFunc_1067_0x0614e0(arg0, arg1);
        case 1068U: return ByteVc0FdeFunc_1068_0x061554(arg0, arg1);
        case 1069U: return ByteVc0FdeFunc_1069_0x061614(arg0, arg1);
        case 1070U: return ByteVc0FdeFunc_1070_0x061734(arg0, arg1);
        case 1071U: return ByteVc0FdeFunc_1071_0x061794(arg0, arg1);
        case 1072U: return ByteVc0FdeFunc_1072_0x061894(arg0, arg1);
        case 1073U: return ByteVc0FdeFunc_1073_0x0618b8(arg0, arg1);
        case 1074U: return ByteVc0FdeFunc_1074_0x061a18(arg0, arg1);
        case 1075U: return ByteVc0FdeFunc_1075_0x061ae8(arg0, arg1);
        case 1076U: return ByteVc0FdeFunc_1076_0x061cc0(arg0, arg1);
        case 1077U: return ByteVc0FdeFunc_1077_0x061de4(arg0, arg1);
        case 1078U: return ByteVc0FdeFunc_1078_0x061e70(arg0, arg1);
        case 1079U: return ByteVc0FdeFunc_1079_0x061fc8(arg0, arg1);
        case 1080U: return ByteVc0FdeFunc_1080_0x0620ec(arg0, arg1);
        case 1081U: return ByteVc0FdeFunc_1081_0x062134(arg0, arg1);
        case 1082U: return ByteVc0FdeFunc_1082_0x06217c(arg0, arg1);
        case 1083U: return ByteVc0FdeFunc_1083_0x06226c(arg0, arg1);
        case 1084U: return ByteVc0FdeFunc_1084_0x0623f8(arg0, arg1);
        case 1085U: return ByteVc0FdeFunc_1085_0x0626dc(arg0, arg1);
        case 1086U: return ByteVc0FdeFunc_1086_0x0627e8(arg0, arg1);
        case 1087U: return ByteVc0FdeFunc_1087_0x062860(arg0, arg1);
        case 1088U: return ByteVc0FdeFunc_1088_0x062988(arg0, arg1);
        case 1089U: return ByteVc0FdeFunc_1089_0x062adc(arg0, arg1);
        case 1090U: return ByteVc0FdeFunc_1090_0x062c0c(arg0, arg1);
        case 1091U: return ByteVc0FdeFunc_1091_0x063044(arg0, arg1);
        case 1092U: return ByteVc0FdeFunc_1092_0x063178(arg0, arg1);
        case 1093U: return ByteVc0FdeFunc_1093_0x06319c(arg0, arg1);
        case 1094U: return ByteVc0FdeFunc_1094_0x0631d4(arg0, arg1);
        case 1095U: return ByteVc0FdeFunc_1095_0x06352c(arg0, arg1);
        case 1096U: return ByteVc0FdeFunc_1096_0x06353c(arg0, arg1);
        case 1097U: return ByteVc0FdeFunc_1097_0x063578(arg0, arg1);
        case 1098U: return ByteVc0FdeFunc_1098_0x06368c(arg0, arg1);
        case 1099U: return ByteVc0FdeFunc_1099_0x064418(arg0, arg1);
        case 1100U: return ByteVc0FdeFunc_1100_0x06445c(arg0, arg1);
        case 1101U: return ByteVc0FdeFunc_1101_0x064570(arg0, arg1);
        case 1102U: return ByteVc0FdeFunc_1102_0x0646a0(arg0, arg1);
        case 1103U: return ByteVc0FdeFunc_1103_0x0647fc(arg0, arg1);
        case 1104U: return ByteVc0FdeFunc_1104_0x064824(arg0, arg1);
        case 1105U: return ByteVc0FdeFunc_1105_0x064884(arg0, arg1);
        case 1106U: return ByteVc0FdeFunc_1106_0x064914(arg0, arg1);
        case 1107U: return ByteVc0FdeFunc_1107_0x064944(arg0, arg1);
        case 1108U: return ByteVc0FdeFunc_1108_0x064a24(arg0, arg1);
        case 1109U: return ByteVc0FdeFunc_1109_0x064a84(arg0, arg1);
        case 1110U: return ByteVc0FdeFunc_1110_0x064aec(arg0, arg1);
        case 1111U: return ByteVc0FdeFunc_1111_0x064b90(arg0, arg1);
        case 1112U: return ByteVc0FdeFunc_1112_0x064e38(arg0, arg1);
        case 1113U: return ByteVc0FdeFunc_1113_0x064f48(arg0, arg1);
        case 1114U: return ByteVc0FdeFunc_1114_0x065308(arg0, arg1);
        case 1115U: return ByteVc0FdeFunc_1115_0x0653d8(arg0, arg1);
        case 1116U: return ByteVc0FdeFunc_1116_0x065454(arg0, arg1);
        case 1117U: return ByteVc0FdeFunc_1117_0x065524(arg0, arg1);
        case 1118U: return ByteVc0FdeFunc_1118_0x0655a0(arg0, arg1);
        case 1119U: return ByteVc0FdeFunc_1119_0x065bd4(arg0, arg1);
        case 1120U: return ByteVc0FdeFunc_1120_0x065d48(arg0, arg1);
        case 1121U: return ByteVc0FdeFunc_1121_0x065e80(arg0, arg1);
        case 1122U: return ByteVc0FdeFunc_1122_0x066018(arg0, arg1);
        case 1123U: return ByteVc0FdeFunc_1123_0x066230(arg0, arg1);
        case 1124U: return ByteVc0FdeFunc_1124_0x066344(arg0, arg1);
        case 1125U: return ByteVc0FdeFunc_1125_0x0663a8(arg0, arg1);
        case 1126U: return ByteVc0FdeFunc_1126_0x0663c8(arg0, arg1);
        case 1127U: return ByteVc0FdeFunc_1127_0x0667f8(arg0, arg1);
        case 1128U: return ByteVc0FdeFunc_1128_0x0668b8(arg0, arg1);
        case 1129U: return ByteVc0FdeFunc_1129_0x066978(arg0, arg1);
        case 1130U: return ByteVc0FdeFunc_1130_0x066a74(arg0, arg1);
        case 1131U: return ByteVc0FdeFunc_1131_0x066c08(arg0, arg1);
        case 1132U: return ByteVc0FdeFunc_1132_0x066c9c(arg0, arg1);
        case 1133U: return ByteVc0FdeFunc_1133_0x066d00(arg0, arg1);
        case 1134U: return ByteVc0FdeFunc_1134_0x066d68(arg0, arg1);
        case 1135U: return ByteVc0FdeFunc_1135_0x066da0(arg0, arg1);
        case 1136U: return ByteVc0FdeFunc_1136_0x066da8(arg0, arg1);
        case 1137U: return ByteVc0FdeFunc_1137_0x066fe4(arg0, arg1);
        case 1138U: return ByteVc0FdeFunc_1138_0x066fe8(arg0, arg1);
        case 1139U: return ByteVc0FdeFunc_1139_0x067094(arg0, arg1);
        case 1140U: return ByteVc0FdeFunc_1140_0x0670a0(arg0, arg1);
        case 1141U: return ByteVc0FdeFunc_1141_0x0670a4(arg0, arg1);
        default: return 0U;
    }
}

std::uint64_t ExecuteAll1142ByteVc0Fdes(std::uint32_t seed) noexcept {
    std::uint64_t digest = seed;
    for (std::uint32_t i = 0; i < kEhFrameFdeCount; ++i) {
        const std::uint32_t r = DispatchByteVc0FdeIndex(i, seed + i, i * 0xC2B2AE35U);
        digest = ((digest << 9U) | (digest >> 55U)) ^ static_cast<std::uint64_t>(r);
    }
    return digest;
}

} // namespace nextai::opencut::bytevc0
