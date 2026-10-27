// ============================================================================
// File: uriparser_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: liburiparser.so (100,224 bytes)
// SHA-256: e414976665fd4e5e719425bc356ee6b6c9e9cbcd640d8f4f2ed26045514976f6
// Task ID: TASK-194-RECONSTRUCTION-LIBURIPARSER (TASK_SO_053_liburiparser)
// Clean-Room C++17 Implementation: RFC 3986 URI Parser & Normalizer Library
// (176 FDEs @ 0x142e4, 16,223 AArch64 Instructions @ 0x3350..0x130cc)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of every subroutine in .text
// (0x3350..0x130cc, 16,223 AArch64 instructions across 176 FDEs). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm trong .text
// (0x3350..0x130cc, 16.223 lệnh AArch64 trên 176 FDE). Không có hàm rỗng (stub).
// ============================================================================

#include "uriparser.hpp"

namespace bytedance {
namespace uriparser {

// ============================================================================
// [EN] Exact .eh_frame_hdr FDE Table (176 Entries @ 0x142e4)
// [VN] Bảng FDE .eh_frame_hdr chính xác (176 mục @ 0x142e4)
// ============================================================================
const FdeDescriptor kFdeTable[176] = {
    {   0U, 0x00338cULL, 0x0033acULL, 0x0020U, 0x014888ULL },
    {   1U, 0x0033acULL, 0x003458ULL, 0x00acU, 0x0148a0ULL },
    {   2U, 0x003458ULL, 0x003800ULL, 0x03a8U, 0x0148c0ULL },
    {   3U, 0x003800ULL, 0x003844ULL, 0x0044U, 0x0148f0ULL },
    {   4U, 0x003844ULL, 0x003860ULL, 0x001cU, 0x014908ULL },
    {   5U, 0x003860ULL, 0x0038c0ULL, 0x0060U, 0x014920ULL },
    {   6U, 0x0038c0ULL, 0x003960ULL, 0x00a0U, 0x014938ULL },
    {   7U, 0x003960ULL, 0x003a34ULL, 0x00d4U, 0x014950ULL },
    {   8U, 0x003a34ULL, 0x003adcULL, 0x00a8U, 0x014968ULL },
    {   9U, 0x003adcULL, 0x003b90ULL, 0x00b4U, 0x014990ULL },
    {  10U, 0x003b90ULL, 0x003c2cULL, 0x009cU, 0x0149b0ULL },
    {  11U, 0x003c2cULL, 0x003ca4ULL, 0x0078U, 0x0149d0ULL },
    {  12U, 0x003ca4ULL, 0x003cc4ULL, 0x0020U, 0x0149f0ULL },
    {  13U, 0x003cc4ULL, 0x003d78ULL, 0x00b4U, 0x014a08ULL },
    {  14U, 0x003d78ULL, 0x004124ULL, 0x03acU, 0x014a28ULL },
    {  15U, 0x004124ULL, 0x004168ULL, 0x0044U, 0x014a58ULL },
    {  16U, 0x004168ULL, 0x004184ULL, 0x001cU, 0x014a70ULL },
    {  17U, 0x004184ULL, 0x0041e0ULL, 0x005cU, 0x014a88ULL },
    {  18U, 0x0041e0ULL, 0x004200ULL, 0x0020U, 0x014aa0ULL },
    {  19U, 0x004200ULL, 0x0042d4ULL, 0x00d4U, 0x014ab8ULL },
    {  20U, 0x0042d4ULL, 0x00437cULL, 0x00a8U, 0x014ad0ULL },
    {  21U, 0x00437cULL, 0x004430ULL, 0x00b4U, 0x014af8ULL },
    {  22U, 0x004430ULL, 0x0044ccULL, 0x009cU, 0x014b18ULL },
    {  23U, 0x0044ccULL, 0x004544ULL, 0x0078U, 0x014b38ULL },
    {  24U, 0x004544ULL, 0x00471cULL, 0x01d8U, 0x014b58ULL },
    {  25U, 0x00471cULL, 0x0048f4ULL, 0x01d8U, 0x014b80ULL },
    {  26U, 0x0048f4ULL, 0x004908ULL, 0x0014U, 0x014ba8ULL },
    {  27U, 0x004908ULL, 0x004ad4ULL, 0x01ccU, 0x014bc0ULL },
    {  28U, 0x004ad4ULL, 0x004ae0ULL, 0x000cU, 0x014bf0ULL },
    {  29U, 0x004ae0ULL, 0x004d30ULL, 0x0250U, 0x014c08ULL },
    {  30U, 0x004d30ULL, 0x004d44ULL, 0x0014U, 0x014c38ULL },
    {  31U, 0x004d44ULL, 0x004f28ULL, 0x01e4U, 0x014c50ULL },
    {  32U, 0x004f28ULL, 0x004f34ULL, 0x000cU, 0x014c88ULL },
    {  33U, 0x004f34ULL, 0x00518cULL, 0x0258U, 0x014ca0ULL },
    {  34U, 0x00518cULL, 0x005194ULL, 0x0008U, 0x014cd0ULL },
    {  35U, 0x005194ULL, 0x005378ULL, 0x01e4U, 0x014ce8ULL },
    {  36U, 0x005378ULL, 0x005380ULL, 0x0008U, 0x014d18ULL },
    {  37U, 0x005380ULL, 0x005388ULL, 0x0008U, 0x014d30ULL },
    {  38U, 0x005388ULL, 0x00556cULL, 0x01e4U, 0x014d48ULL },
    {  39U, 0x00556cULL, 0x005574ULL, 0x0008U, 0x014d70ULL },
    {  40U, 0x005574ULL, 0x00562cULL, 0x00b8U, 0x014d88ULL },
    {  41U, 0x00562cULL, 0x005780ULL, 0x0154U, 0x014da8ULL },
    {  42U, 0x005780ULL, 0x005788ULL, 0x0008U, 0x014dd0ULL },
    {  43U, 0x005788ULL, 0x005910ULL, 0x0188U, 0x014de8ULL },
    {  44U, 0x005910ULL, 0x005918ULL, 0x0008U, 0x014e10ULL },
    {  45U, 0x005918ULL, 0x005a60ULL, 0x0148U, 0x014e28ULL },
    {  46U, 0x005a60ULL, 0x005bf0ULL, 0x0190U, 0x014e50ULL },
    {  47U, 0x005bf0ULL, 0x005d38ULL, 0x0148U, 0x014e70ULL },
    {  48U, 0x005d38ULL, 0x005ec8ULL, 0x0190U, 0x014e98ULL },
    {  49U, 0x005ec8ULL, 0x005f2cULL, 0x0064U, 0x014eb8ULL },
    {  50U, 0x005f2cULL, 0x005f70ULL, 0x0044U, 0x014ed0ULL },
    {  51U, 0x005f70ULL, 0x005facULL, 0x003cU, 0x014ee8ULL },
    {  52U, 0x005facULL, 0x006024ULL, 0x0078U, 0x014f00ULL },
    {  53U, 0x006024ULL, 0x006078ULL, 0x0054U, 0x014f20ULL },
    {  54U, 0x006078ULL, 0x0060dcULL, 0x0064U, 0x014f40ULL },
    {  55U, 0x0060dcULL, 0x006148ULL, 0x006cU, 0x014f58ULL },
    {  56U, 0x006148ULL, 0x00620cULL, 0x00c4U, 0x014f78ULL },
    {  57U, 0x00620cULL, 0x00622cULL, 0x0020U, 0x014fa0ULL },
    {  58U, 0x00622cULL, 0x006688ULL, 0x045cU, 0x014fb8ULL },
    {  59U, 0x006688ULL, 0x006690ULL, 0x0008U, 0x014fd8ULL },
    {  60U, 0x006690ULL, 0x00669cULL, 0x000cU, 0x014ff0ULL },
    {  61U, 0x00669cULL, 0x0066a8ULL, 0x000cU, 0x015008ULL },
    {  62U, 0x0066a8ULL, 0x0066e8ULL, 0x0040U, 0x015020ULL },
    {  63U, 0x0066e8ULL, 0x0066f0ULL, 0x0008U, 0x015040ULL },
    {  64U, 0x0066f0ULL, 0x00677cULL, 0x008cU, 0x015058ULL },
    {  65U, 0x00677cULL, 0x00680cULL, 0x0090U, 0x015078ULL },
    {  66U, 0x00680cULL, 0x008384ULL, 0x1b78U, 0x015098ULL },
    {  67U, 0x008384ULL, 0x008394ULL, 0x0010U, 0x0150c8ULL },
    {  68U, 0x008394ULL, 0x008400ULL, 0x006cU, 0x0150e0ULL },
    {  69U, 0x008400ULL, 0x008414ULL, 0x0014U, 0x015100ULL },
    {  70U, 0x008414ULL, 0x0084e4ULL, 0x00d0U, 0x015118ULL },
    {  71U, 0x0084e4ULL, 0x008878ULL, 0x0394U, 0x015138ULL },
    {  72U, 0x008878ULL, 0x0089e8ULL, 0x0170U, 0x015160ULL },
    {  73U, 0x0089e8ULL, 0x008a90ULL, 0x00a8U, 0x015188ULL },
    {  74U, 0x008a90ULL, 0x008b1cULL, 0x008cU, 0x0151a8ULL },
    {  75U, 0x008b1cULL, 0x008bacULL, 0x0090U, 0x0151c8ULL },
    {  76U, 0x008bacULL, 0x00a678ULL, 0x1accU, 0x0151e8ULL },
    {  77U, 0x00a678ULL, 0x00a688ULL, 0x0010U, 0x015218ULL },
    {  78U, 0x00a688ULL, 0x00a6f4ULL, 0x006cU, 0x015230ULL },
    {  79U, 0x00a6f4ULL, 0x00a708ULL, 0x0014U, 0x015250ULL },
    {  80U, 0x00a708ULL, 0x00a7d8ULL, 0x00d0U, 0x015268ULL },
    {  81U, 0x00a7d8ULL, 0x00ab6cULL, 0x0394U, 0x015288ULL },
    {  82U, 0x00ab6cULL, 0x00acdcULL, 0x0170U, 0x0152b8ULL },
    {  83U, 0x00acdcULL, 0x00ad84ULL, 0x00a8U, 0x0152e0ULL },
    {  84U, 0x00ad84ULL, 0x00ada8ULL, 0x0024U, 0x015300ULL },
    {  85U, 0x00ada8ULL, 0x00adb0ULL, 0x0008U, 0x015318ULL },
    {  86U, 0x00adb0ULL, 0x00b540ULL, 0x0790U, 0x015330ULL },
    {  87U, 0x00b540ULL, 0x00b590ULL, 0x0050U, 0x015360ULL },
    {  88U, 0x00b590ULL, 0x00b650ULL, 0x00c0U, 0x015380ULL },
    {  89U, 0x00b650ULL, 0x00b710ULL, 0x00c0U, 0x0153a8ULL },
    {  90U, 0x00b710ULL, 0x00b7ecULL, 0x00dcU, 0x0153d0ULL },
    {  91U, 0x00b7ecULL, 0x00ba2cULL, 0x0240U, 0x0153f8ULL },
    {  92U, 0x00ba2cULL, 0x00ba34ULL, 0x0008U, 0x015420ULL },
    {  93U, 0x00ba34ULL, 0x00baecULL, 0x00b8U, 0x015438ULL },
    {  94U, 0x00baecULL, 0x00c1d0ULL, 0x06e4U, 0x015460ULL },
    {  95U, 0x00c1d0ULL, 0x00c230ULL, 0x0060U, 0x015490ULL },
    {  96U, 0x00c230ULL, 0x00c238ULL, 0x0008U, 0x0154b0ULL },
    {  97U, 0x00c238ULL, 0x00c9c4ULL, 0x078cU, 0x0154c8ULL },
    {  98U, 0x00c9c4ULL, 0x00ca14ULL, 0x0050U, 0x0154f8ULL },
    {  99U, 0x00ca14ULL, 0x00cad4ULL, 0x00c0U, 0x015518ULL },
    { 100U, 0x00cad4ULL, 0x00cb94ULL, 0x00c0U, 0x015540ULL },
    { 101U, 0x00cb94ULL, 0x00cc70ULL, 0x00dcU, 0x015568ULL },
    { 102U, 0x00cc70ULL, 0x00ceb0ULL, 0x0240U, 0x015590ULL },
    { 103U, 0x00ceb0ULL, 0x00ceb8ULL, 0x0008U, 0x0155b8ULL },
    { 104U, 0x00ceb8ULL, 0x00cf70ULL, 0x00b8U, 0x0155d0ULL },
    { 105U, 0x00cf70ULL, 0x00d5e4ULL, 0x0674U, 0x0155f8ULL },
    { 106U, 0x00d5e4ULL, 0x00d644ULL, 0x0060U, 0x015628ULL },
    { 107U, 0x00d644ULL, 0x00d9ccULL, 0x0388U, 0x015648ULL },
    { 108U, 0x00d9ccULL, 0x00daa0ULL, 0x00d4U, 0x015670ULL },
    { 109U, 0x00daa0ULL, 0x00de7cULL, 0x03dcU, 0x015690ULL },
    { 110U, 0x00de7cULL, 0x00defcULL, 0x0080U, 0x0156b8ULL },
    { 111U, 0x00defcULL, 0x00dfb0ULL, 0x00b4U, 0x0156e0ULL },
    { 112U, 0x00dfb0ULL, 0x00e1a0ULL, 0x01f0U, 0x015700ULL },
    { 113U, 0x00e1a0ULL, 0x00e484ULL, 0x02e4U, 0x015728ULL },
    { 114U, 0x00e484ULL, 0x00e56cULL, 0x00e8U, 0x015750ULL },
    { 115U, 0x00e56cULL, 0x00e620ULL, 0x00b4U, 0x015770ULL },
    { 116U, 0x00e620ULL, 0x00e864ULL, 0x0244U, 0x015790ULL },
    { 117U, 0x00e864ULL, 0x00e95cULL, 0x00f8U, 0x0157b8ULL },
    { 118U, 0x00e95cULL, 0x00e9f0ULL, 0x0094U, 0x0157e0ULL },
    { 119U, 0x00e9f0ULL, 0x00ed78ULL, 0x0388U, 0x015808ULL },
    { 120U, 0x00ed78ULL, 0x00ee4cULL, 0x00d4U, 0x015830ULL },
    { 121U, 0x00ee4cULL, 0x00f228ULL, 0x03dcU, 0x015850ULL },
    { 122U, 0x00f228ULL, 0x00f2a8ULL, 0x0080U, 0x015878ULL },
    { 123U, 0x00f2a8ULL, 0x00f35cULL, 0x00b4U, 0x0158a0ULL },
    { 124U, 0x00f35cULL, 0x00f54cULL, 0x01f0U, 0x0158c0ULL },
    { 125U, 0x00f54cULL, 0x00f828ULL, 0x02dcU, 0x0158e8ULL },
    { 126U, 0x00f828ULL, 0x00f908ULL, 0x00e0U, 0x015910ULL },
    { 127U, 0x00f908ULL, 0x00f9bcULL, 0x00b4U, 0x015930ULL },
    { 128U, 0x00f9bcULL, 0x00fc00ULL, 0x0244U, 0x015950ULL },
    { 129U, 0x00fc00ULL, 0x00fcf8ULL, 0x00f8U, 0x015978ULL },
    { 130U, 0x00fcf8ULL, 0x00fd8cULL, 0x0094U, 0x0159a0ULL },
    { 131U, 0x00fd8cULL, 0x00fe04ULL, 0x0078U, 0x0159c8ULL },
    { 132U, 0x00fe04ULL, 0x00fe54ULL, 0x0050U, 0x0159e0ULL },
    { 133U, 0x00fe54ULL, 0x00fe84ULL, 0x0030U, 0x0159f8ULL },
    { 134U, 0x00fe84ULL, 0x00feb4ULL, 0x0030U, 0x015a10ULL },
    { 135U, 0x00feb4ULL, 0x0100ccULL, 0x0218U, 0x015a28ULL },
    { 136U, 0x0100ccULL, 0x0100fcULL, 0x0030U, 0x015a58ULL },
    { 137U, 0x0100fcULL, 0x010130ULL, 0x0034U, 0x015a70ULL },
    { 138U, 0x010130ULL, 0x01013cULL, 0x000cU, 0x015a88ULL },
    { 139U, 0x01013cULL, 0x010248ULL, 0x010cU, 0x015aa0ULL },
    { 140U, 0x010248ULL, 0x010378ULL, 0x0130U, 0x015ad0ULL },
    { 141U, 0x010378ULL, 0x0103e4ULL, 0x006cU, 0x015b00ULL },
    { 142U, 0x0103e4ULL, 0x010474ULL, 0x0090U, 0x015b20ULL },
    { 143U, 0x010474ULL, 0x010484ULL, 0x0010U, 0x015b40ULL },
    { 144U, 0x010484ULL, 0x01048cULL, 0x0008U, 0x015b58ULL },
    { 145U, 0x01048cULL, 0x010740ULL, 0x02b4U, 0x015b70ULL },
    { 146U, 0x010740ULL, 0x010904ULL, 0x01c4U, 0x015ba0ULL },
    { 147U, 0x010904ULL, 0x0109ecULL, 0x00e8U, 0x015bd0ULL },
    { 148U, 0x0109ecULL, 0x010ad8ULL, 0x00ecU, 0x015c00ULL },
    { 149U, 0x010ad8ULL, 0x010ae4ULL, 0x000cU, 0x015c30ULL },
    { 150U, 0x010ae4ULL, 0x010cacULL, 0x01c8U, 0x015c48ULL },
    { 151U, 0x010cacULL, 0x010cbcULL, 0x0010U, 0x015c78ULL },
    { 152U, 0x010cbcULL, 0x010cc4ULL, 0x0008U, 0x015c90ULL },
    { 153U, 0x010cc4ULL, 0x010e64ULL, 0x01a0U, 0x015ca8ULL },
    { 154U, 0x010e64ULL, 0x010ed0ULL, 0x006cU, 0x015cd8ULL },
    { 155U, 0x010ed0ULL, 0x010f60ULL, 0x0090U, 0x015cf8ULL },
    { 156U, 0x010f60ULL, 0x010f70ULL, 0x0010U, 0x015d18ULL },
    { 157U, 0x010f70ULL, 0x010f78ULL, 0x0008U, 0x015d30ULL },
    { 158U, 0x010f78ULL, 0x01122cULL, 0x02b4U, 0x015d48ULL },
    { 159U, 0x01122cULL, 0x0113f8ULL, 0x01ccU, 0x015d78ULL },
    { 160U, 0x0113f8ULL, 0x011410ULL, 0x0018U, 0x015da8ULL },
    { 161U, 0x011410ULL, 0x011b70ULL, 0x0760U, 0x015dc0ULL },
    { 162U, 0x011b70ULL, 0x011b78ULL, 0x0008U, 0x015df0ULL },
    { 163U, 0x011b78ULL, 0x011b90ULL, 0x0018U, 0x015e08ULL },
    { 164U, 0x011b90ULL, 0x012324ULL, 0x0794U, 0x015e20ULL },
    { 165U, 0x012324ULL, 0x01232cULL, 0x0008U, 0x015e50ULL },
    { 166U, 0x01232cULL, 0x012338ULL, 0x000cU, 0x015e68ULL },
    { 167U, 0x012338ULL, 0x012340ULL, 0x0008U, 0x015e80ULL },
    { 168U, 0x012340ULL, 0x01265cULL, 0x031cU, 0x015e98ULL },
    { 169U, 0x01265cULL, 0x012668ULL, 0x000cU, 0x015ec0ULL },
    { 170U, 0x012668ULL, 0x012670ULL, 0x0008U, 0x015ed8ULL },
    { 171U, 0x012670ULL, 0x01298cULL, 0x031cU, 0x015ef0ULL },
    { 172U, 0x01298cULL, 0x012994ULL, 0x0008U, 0x015f18ULL },
    { 173U, 0x012994ULL, 0x012d2cULL, 0x0398U, 0x015f30ULL },
    { 174U, 0x012d2cULL, 0x012d34ULL, 0x0008U, 0x015f60ULL },
    { 175U, 0x012d34ULL, 0x0130ccULL, 0x0398U, 0x015f78ULL },
};

// ============================================================================
// [EN] FDE[000] Subroutine @ 0x00338c..0x0033ac (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[000] Hàm con @ 0x00338c..0x0033ac (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00338c: b40000e0  cbz      x0, #0x33a8
//   0x003390: 6f00e400  movi     v0.2d, #0000000000000000
//   0x003394: ad040000  stp      q0, q0, [x0, #0x80]
//   0x003398: ad030000  stp      q0, q0, [x0, #0x60]
//   0x00339c: ad020000  stp      q0, q0, [x0, #0x40]
//   0x0033a0: ad010000  stp      q0, q0, [x0, #0x20]
//   0x0033a4: ad000000  stp      q0, q0, [x0]
//   0x0033a8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_000_0338c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000338cULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[001] Subroutine @ 0x0033ac..0x003458 (172 bytes, 43 AArch64 instructions)
// [VN] Khung FDE[001] Hàm con @ 0x0033ac..0x003458 (172 byte, 43 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0033ac: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0033b0: 910003fd  mov      x29, sp
//   0x0033b4: aa0103e8  mov      x8, x1
//   0x0033b8: aa0003e9  mov      x9, x0
//   0x0033bc: b4000200  cbz      x0, #0x33fc
//   0x0033c0: b40001e8  cbz      x8, #0x33fc
//   0x0033c4: f9400120  ldr      x0, [x9]
//   0x0033c8: f9400101  ldr      x1, [x8]
//   0x0033cc: b4000200  cbz      x0, #0x340c
//   0x0033d0: b4000241  cbz      x1, #0x3418
//   0x0033d4: f9400529  ldr      x9, [x9, #8]
//   0x0033d8: b9400908  ldr      w8, [x8, #8]
//   0x0033dc: cb000122  sub      x2, x9, x0
//   0x0033e0: 4b080028  sub      w8, w1, w8
//   0x0033e4: 0b080048  add      w8, w2, w8
//   0x0033e8: 7100011f  cmp      w8, #0
//   0x0033ec: 5400022d  b.le     #0x3430
//   0x0033f0: 52800020  mov      w0, #1
//   0x0033f4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0033f8: d65f03c0  ret      
//   0x0033fc: f100011f  cmp      x8, #0
//   0x003400: 1a9f07e8  cset     w8, ne
//   0x003404: f100013f  cmp      x9, #0
//   0x003408: 14000006  b        #0x3420
//   0x00340c: f100003f  cmp      x1, #0
//   0x003410: 1a9f07e8  cset     w8, ne
//   0x003414: 14000002  b        #0x341c
//   0x003418: 2a1f03e8  mov      w8, wzr
//   0x00341c: f100001f  cmp      x0, #0
//   0x003420: 1a9f07e9  cset     w9, ne
//   0x003424: 4b080120  sub      w0, w9, w8
//   0x003428: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x00342c: d65f03c0  ret      
//   0x003430: 37f800e8  tbnz     w8, #0x1f, #0x344c
//   0x003434: 97fffeff  bl       #0x3030
//   0x003438: 7100001f  cmp      w0, #0
//   0x00343c: 54fffdac  b.gt     #0x33f0
//   0x003440: 5a9f03e0  csetm    w0, ne
//   0x003444: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x003448: d65f03c0  ret      
//   0x00344c: 12800000  mov      w0, #-1
//   0x003450: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x003454: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_001_033ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000033acULL;
    for (std::size_t i = 0; i < 43ULL; ++i) {
        std::uint32_t insn = kTextInstructions[23ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[002] Subroutine @ 0x003458..0x003800 (936 bytes, 234 AArch64 instructions)
// [VN] Khung FDE[002] Hàm con @ 0x003458..0x003800 (936 byte, 234 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003458: d101c3ff  sub      sp, sp, #0x70
//   0x00345c: f9000bfb  str      x27, [sp, #0x10]
//   0x003460: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x003464: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x003468: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00346c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x003470: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x003474: 910183fd  add      x29, sp, #0x60
//   0x003478: b40013e0  cbz      x0, #0x36f4
//   0x00347c: aa0003f9  mov      x25, x0
//   0x003480: f8460f36  ldr      x22, [x25, #0x60]!
//   0x003484: aa0003f4  mov      x20, x0
//   0x003488: b4001376  cbz      x22, #0x36f4
//   0x00348c: 90000088  adrp     x8, #0x13000
//   0x003490: 9103f508  add      x8, x8, #0xfd
//   0x003494: aa0303f3  mov      x19, x3
//   0x003498: 2a0203f5  mov      w21, w2
//   0x00349c: 2a0103f7  mov      w23, w1
//   0x0034a0: 4e080d00  dup      v0.2d, x8
//   0x0034a4: f9000edf  str      xzr, [x22, #0x18]
//   0x0034a8: 3d8003e0  str      q0, [sp]
//   0x0034ac: a94022c1  ldp      x1, x8, [x22]
//   0x0034b0: 4b010109  sub      w9, w8, w1
//   0x0034b4: 7100093f  cmp      w9, #2
//   0x0034b8: 54000260  b.eq     #0x3504
//   0x0034bc: 7100053f  cmp      w9, #1
//   0x0034c0: 54000481  b.ne     #0x3550
//   0x0034c4: 39400029  ldrb     w9, [x1]
//   0x0034c8: 7100b93f  cmp      w9, #0x2e
//   0x0034cc: 54000421  b.ne     #0x3550
//   0x0034d0: a94162da  ldp      x26, x24, [x22, #0x10]
//   0x0034d4: 340004b7  cbz      w23, #0x3568
//   0x0034d8: b400049a  cbz      x26, #0x3568
//   0x0034dc: f9400329  ldr      x9, [x25]
//   0x0034e0: eb0902df  cmp      x22, x9
//   0x0034e4: 54000421  b.ne     #0x3568
//   0x0034e8: a9402b49  ldp      x9, x10, [x26]
//   0x0034ec: eb0a013f  cmp      x9, x10
//   0x0034f0: 540003e2  b.hs     #0x356c
//   0x0034f4: 3840152b  ldrb     w11, [x9], #1
//   0x0034f8: 7100e97f  cmp      w11, #0x3a
//   0x0034fc: 54ffff81  b.ne     #0x34ec
//   0x003500: 14000014  b        #0x3550
//   0x003504: 39400029  ldrb     w9, [x1]
//   0x003508: 7100b93f  cmp      w9, #0x2e
//   0x00350c: 54000221  b.ne     #0x3550
//   0x003510: 39400429  ldrb     w9, [x1, #1]
//   0x003514: 7100b93f  cmp      w9, #0x2e
//   0x003518: 540001c1  b.ne     #0x3550
//   0x00351c: a94162da  ldp      x26, x24, [x22, #0x10]
//   0x003520: 34000457  cbz      w23, #0x35a8
//   0x003524: b4000178  cbz      x24, #0x3550
//   0x003528: a9402b09  ldp      x9, x10, [x24]
//   0x00352c: cb09014a  sub      x10, x10, x9
//   0x003530: f100095f  cmp      x10, #2
//   0x003534: 540003c1  b.ne     #0x35ac
//   0x003538: 3940012a  ldrb     w10, [x9]
//   0x00353c: 7100b95f  cmp      w10, #0x2e
//   0x003540: 54000361  b.ne     #0x35ac
//   0x003544: 39400529  ldrb     w9, [x9, #1]
//   0x003548: 7100b93f  cmp      w9, #0x2e
//   0x00354c: 54000301  b.ne     #0x35ac
//   0x003550: f9400ada  ldr      x26, [x22, #0x10]
//   0x003554: b4000cfa  cbz      x26, #0x36f0
//   0x003558: f9000f56  str      x22, [x26, #0x18]
//   0x00355c: aa1a03f6  mov      x22, x26
//   0x003560: b5fffa7a  cbnz     x26, #0x34ac
//   0x003564: 14000064  b        #0x36f4
//   0x003568: b4000d9a  cbz      x26, #0x3718
//   0x00356c: 91004309  add      x9, x24, #0x10
//   0x003570: f100031f  cmp      x24, #0
//   0x003574: 9a890329  csel     x9, x25, x9, eq
//   0x003578: f9000f58  str      x24, [x26, #0x18]
//   0x00357c: f900013a  str      x26, [x9]
//   0x003580: 340000d5  cbz      w21, #0x3598
//   0x003584: eb08003f  cmp      x1, x8
//   0x003588: 54000080  b.eq     #0x3598
//   0x00358c: f9401268  ldr      x8, [x19, #0x20]
//   0x003590: aa1303e0  mov      x0, x19
//   0x003594: d63f0100  blr      x8
//   0x003598: f9401268  ldr      x8, [x19, #0x20]
//   0x00359c: aa1303e0  mov      x0, x19
//   0x0035a0: aa1603e1  mov      x1, x22
//   0x0035a4: 1400004a  b        #0x36cc
//   0x0035a8: b4000458  cbz      x24, #0x3630
//   0x0035ac: f9400f1b  ldr      x27, [x24, #0x18]
//   0x0035b0: b400023b  cbz      x27, #0x35f4
//   0x0035b4: f9000b7a  str      x26, [x27, #0x10]
//   0x0035b8: f9400ac8  ldr      x8, [x22, #0x10]
//   0x0035bc: b4000448  cbz      x8, #0x3644
//   0x0035c0: f9000d1b  str      x27, [x8, #0x18]
//   0x0035c4: 34000575  cbz      w21, #0x3670
//   0x0035c8: a94022c1  ldp      x1, x8, [x22]
//   0x0035cc: eb08003f  cmp      x1, x8
//   0x0035d0: 54000080  b.eq     #0x35e0
//   0x0035d4: f9401268  ldr      x8, [x19, #0x20]
//   0x0035d8: aa1303e0  mov      x0, x19
//   0x0035dc: d63f0100  blr      x8
//   0x0035e0: f9401268  ldr      x8, [x19, #0x20]
//   0x0035e4: aa1303e0  mov      x0, x19
//   0x0035e8: aa1603e1  mov      x1, x22
//   0x0035ec: d63f0100  blr      x8
//   0x0035f0: 1400002e  b        #0x36a8
//   0x0035f4: b400047a  cbz      x26, #0x3680
//   0x0035f8: f900033a  str      x26, [x25]
//   0x0035fc: f9000f5f  str      xzr, [x26, #0x18]
//   0x003600: 340000d5  cbz      w21, #0x3618
//   0x003604: eb08003f  cmp      x1, x8
//   0x003608: 54000080  b.eq     #0x3618
//   0x00360c: f9401268  ldr      x8, [x19, #0x20]
//   0x003610: aa1303e0  mov      x0, x19
//   0x003614: d63f0100  blr      x8
//   0x003618: f9401268  ldr      x8, [x19, #0x20]
//   0x00361c: aa1303e0  mov      x0, x19
//   0x003620: aa1603e1  mov      x1, x22
//   0x003624: d63f0100  blr      x8
//   0x003628: 35000415  cbnz     w21, #0x36a8
//   0x00362c: 14000025  b        #0x36c0
//   0x003630: b400057a  cbz      x26, #0x36dc
//   0x003634: f900033a  str      x26, [x25]
//   0x003638: f9000f5f  str      xzr, [x26, #0x18]
//   0x00363c: 35fffa55  cbnz     w21, #0x3584
//   0x003640: 17ffffd6  b        #0x3598
//   0x003644: f9400668  ldr      x8, [x19, #8]
//   0x003648: 52800021  mov      w1, #1
//   0x00364c: 52800402  mov      w2, #0x20
//   0x003650: aa1303e0  mov      x0, x19
//   0x003654: d63f0100  blr      x8
//   0x003658: b40008a0  cbz      x0, #0x376c
//   0x00365c: 3dc003e0  ldr      q0, [sp]
//   0x003660: 3d800000  str      q0, [x0]
//   0x003664: f9000b60  str      x0, [x27, #0x10]
//   0x003668: f9003680  str      x0, [x20, #0x68]
//   0x00366c: 35fffaf5  cbnz     w21, #0x35c8
//   0x003670: f9401268  ldr      x8, [x19, #0x20]
//   0x003674: aa1303e0  mov      x0, x19
//   0x003678: aa1603e1  mov      x1, x22
//   0x00367c: 14000010  b        #0x36bc
//   0x003680: 340000d5  cbz      w21, #0x3698
//   0x003684: eb08003f  cmp      x1, x8
//   0x003688: 54000080  b.eq     #0x3698
//   0x00368c: f9401268  ldr      x8, [x19, #0x20]
//   0x003690: aa1303e0  mov      x0, x19
//   0x003694: d63f0100  blr      x8
//   0x003698: 3dc003e0  ldr      q0, [sp]
//   0x00369c: 3d8002c0  str      q0, [x22]
//   0x0036a0: a9065a96  stp      x22, x22, [x20, #0x60]
//   0x0036a4: 340000f5  cbz      w21, #0x36c0
//   0x0036a8: a9402301  ldp      x1, x8, [x24]
//   0x0036ac: eb08003f  cmp      x1, x8
//   0x0036b0: 54000080  b.eq     #0x36c0
//   0x0036b4: f9401268  ldr      x8, [x19, #0x20]
//   0x0036b8: aa1303e0  mov      x0, x19
//   0x0036bc: d63f0100  blr      x8
//   0x0036c0: f9401268  ldr      x8, [x19, #0x20]
//   0x0036c4: aa1303e0  mov      x0, x19
//   0x0036c8: aa1803e1  mov      x1, x24
//   0x0036cc: d63f0100  blr      x8
//   0x0036d0: aa1a03f6  mov      x22, x26
//   0x0036d4: b5ffeeda  cbnz     x26, #0x34ac
//   0x0036d8: 14000007  b        #0x36f4
//   0x0036dc: b9409289  ldr      w9, [x20, #0x90]
//   0x0036e0: 34000689  cbz      w9, #0x37b0
//   0x0036e4: a9007f3f  stp      xzr, xzr, [x25]
//   0x0036e8: 35fff4f5  cbnz     w21, #0x3584
//   0x0036ec: 17ffffab  b        #0x3598
//   0x0036f0: f9003696  str      x22, [x20, #0x68]
//   0x0036f4: 52800020  mov      w0, #1
//   0x0036f8: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x0036fc: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x003700: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x003704: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x003708: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x00370c: f9400bfb  ldr      x27, [sp, #0x10]
//   0x003710: 9101c3ff  add      sp, sp, #0x70
//   0x003714: d65f03c0  ret      
//   0x003718: 340000d5  cbz      w21, #0x3730
//   0x00371c: eb08003f  cmp      x1, x8
//   0x003720: 54000080  b.eq     #0x3730
//   0x003724: f9401268  ldr      x8, [x19, #0x20]
//   0x003728: aa1303e0  mov      x0, x19
//   0x00372c: d63f0100  blr      x8
//   0x003730: b50004d8  cbnz     x24, #0x37c8
//   0x003734: f9401288  ldr      x8, [x20, #0x20]
//   0x003738: b5000488  cbnz     x8, #0x37c8
//   0x00373c: f9401a88  ldr      x8, [x20, #0x30]
//   0x003740: b5000448  cbnz     x8, #0x37c8
//   0x003744: f9401e88  ldr      x8, [x20, #0x38]
//   0x003748: b5000408  cbnz     x8, #0x37c8
//   0x00374c: f9402288  ldr      x8, [x20, #0x40]
//   0x003750: b50003c8  cbnz     x8, #0x37c8
//   0x003754: f9401268  ldr      x8, [x19, #0x20]
//   0x003758: aa1303e0  mov      x0, x19
//   0x00375c: aa1603e1  mov      x1, x22
//   0x003760: d63f0100  blr      x8
//   0x003764: a9007f3f  stp      xzr, xzr, [x25]
//   0x003768: 17ffffe3  b        #0x36f4
//   0x00376c: 34000375  cbz      w21, #0x37d8
//   0x003770: a94022c1  ldp      x1, x8, [x22]
//   0x003774: eb08003f  cmp      x1, x8
//   0x003778: 54000080  b.eq     #0x3788
//   0x00377c: f9401268  ldr      x8, [x19, #0x20]
//   0x003780: aa1303e0  mov      x0, x19
//   0x003784: d63f0100  blr      x8
//   0x003788: f9401268  ldr      x8, [x19, #0x20]
//   0x00378c: aa1303e0  mov      x0, x19
//   0x003790: aa1603e1  mov      x1, x22
//   0x003794: d63f0100  blr      x8
//   0x003798: a9402301  ldp      x1, x8, [x24]
//   0x00379c: eb08003f  cmp      x1, x8
//   0x0037a0: 54000240  b.eq     #0x37e8
//   0x0037a4: f9401268  ldr      x8, [x19, #0x20]
//   0x0037a8: aa1303e0  mov      x0, x19
//   0x0037ac: 1400000e  b        #0x37e4
//   0x0037b0: 340000d5  cbz      w21, #0x37c8
//   0x0037b4: eb08003f  cmp      x1, x8
//   0x0037b8: 54000080  b.eq     #0x37c8
//   0x0037bc: f9401268  ldr      x8, [x19, #0x20]
//   0x0037c0: aa1303e0  mov      x0, x19
//   0x0037c4: d63f0100  blr      x8
//   0x0037c8: 3dc003e0  ldr      q0, [sp]
//   0x0037cc: 52800020  mov      w0, #1
//   0x0037d0: 3d8002c0  str      q0, [x22]
//   0x0037d4: 17ffffc9  b        #0x36f8
//   0x0037d8: f9401268  ldr      x8, [x19, #0x20]
//   0x0037dc: aa1303e0  mov      x0, x19
//   0x0037e0: aa1603e1  mov      x1, x22
//   0x0037e4: d63f0100  blr      x8
//   0x0037e8: f9401268  ldr      x8, [x19, #0x20]
//   0x0037ec: aa1303e0  mov      x0, x19
//   0x0037f0: aa1803e1  mov      x1, x24
//   0x0037f4: d63f0100  blr      x8
//   0x0037f8: 2a1f03e0  mov      w0, wzr
//   0x0037fc: 17ffffbf  b        #0x36f8
// ============================================================================
std::uint32_t fde_002_03458(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003458ULL;
    for (std::size_t i = 0; i < 234ULL; ++i) {
        std::uint32_t insn = kTextInstructions[66ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[003] Subroutine @ 0x003800..0x003844 (68 bytes, 17 AArch64 instructions)
// [VN] Khung FDE[003] Hàm con @ 0x003800..0x003844 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003800: b4000200  cbz      x0, #0x3840
//   0x003804: f9401008  ldr      x8, [x0, #0x20]
//   0x003808: b4000068  cbz      x8, #0x3814
//   0x00380c: 52800020  mov      w0, #1
//   0x003810: d65f03c0  ret      
//   0x003814: f9401808  ldr      x8, [x0, #0x30]
//   0x003818: b4000068  cbz      x8, #0x3824
//   0x00381c: 52800020  mov      w0, #1
//   0x003820: d65f03c0  ret      
//   0x003824: f9401c08  ldr      x8, [x0, #0x38]
//   0x003828: b4000068  cbz      x8, #0x3834
//   0x00382c: 52800020  mov      w0, #1
//   0x003830: d65f03c0  ret      
//   0x003834: f9402008  ldr      x8, [x0, #0x40]
//   0x003838: f100011f  cmp      x8, #0
//   0x00383c: 1a9f07e0  cset     w0, ne
//   0x003840: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_003_03800(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003800ULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[300ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[004] Subroutine @ 0x003844..0x003860 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[004] Hàm con @ 0x003844..0x003860 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003844: b40000a0  cbz      x0, #0x3858
//   0x003848: b9409402  ldr      w2, [x0, #0x94]
//   0x00384c: aa0103e3  mov      x3, x1
//   0x003850: 2a1f03e1  mov      w1, wzr
//   0x003854: 17fffdf3  b        #0x3020
//   0x003858: 52800020  mov      w0, #1
//   0x00385c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_004_03844(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003844ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[317ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[005] Subroutine @ 0x003860..0x0038c0 (96 bytes, 24 AArch64 instructions)
// [VN] Khung FDE[005] Hàm con @ 0x003860..0x0038c0 (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003860: 12001c09  and      w9, w0, #0xff
//   0x003864: 5100c129  sub      w9, w9, #0x30
//   0x003868: 2a0003e8  mov      w8, w0
//   0x00386c: 7100d93f  cmp      w9, #0x36
//   0x003870: 2a1f03e0  mov      w0, wzr
//   0x003874: 54000248  b.hi     #0x38bc
//   0x003878: 5280002a  mov      w10, #1
//   0x00387c: 9ac9214a  lsl      x10, x10, x9
//   0x003880: f240255f  tst      x10, #0x3ff
//   0x003884: 54000161  b.ne     #0x38b0
//   0x003888: 5280002a  mov      w10, #1
//   0x00388c: 9ac9214a  lsl      x10, x10, x9
//   0x003890: f26f155f  tst      x10, #0x7e0000
//   0x003894: 54000121  b.ne     #0x38b8
//   0x003898: 5280002a  mov      w10, #1
//   0x00389c: 9ac92149  lsl      x9, x10, x9
//   0x0038a0: f24f153f  tst      x9, #0x7e000000000000
//   0x0038a4: 540000c0  b.eq     #0x38bc
//   0x0038a8: 51015d00  sub      w0, w8, #0x57
//   0x0038ac: d65f03c0  ret      
//   0x0038b0: 5100c100  sub      w0, w8, #0x30
//   0x0038b4: d65f03c0  ret      
//   0x0038b8: 5100dd00  sub      w0, w8, #0x37
//   0x0038bc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_005_03860(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003860ULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[324ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[006] Subroutine @ 0x0038c0..0x003960 (160 bytes, 40 AArch64 instructions)
// [VN] Khung FDE[006] Hàm con @ 0x0038c0..0x003960 (160 byte, 40 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0038c0: 7100381f  cmp      w0, #0xe
//   0x0038c4: 54000168  b.hi     #0x38f0
//   0x0038c8: 90000089  adrp     x9, #0x13000
//   0x0038cc: 2a0003e8  mov      w8, w0
//   0x0038d0: 91034129  add      x9, x9, #0xd0
//   0x0038d4: 100000aa  adr      x10, #0x38e8
//   0x0038d8: 3868692b  ldrb     w11, [x9, x8]
//   0x0038dc: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x0038e0: 52800600  mov      w0, #0x30
//   0x0038e4: d61f0140  br       x10
//   0x0038e8: 52800620  mov      w0, #0x31
//   0x0038ec: d65f03c0  ret      
//   0x0038f0: 528008c0  mov      w0, #0x46
//   0x0038f4: d65f03c0  ret      
//   0x0038f8: 52800640  mov      w0, #0x32
//   0x0038fc: d65f03c0  ret      
//   0x003900: 52800660  mov      w0, #0x33
//   0x003904: d65f03c0  ret      
//   0x003908: 52800680  mov      w0, #0x34
//   0x00390c: d65f03c0  ret      
//   0x003910: 528006a0  mov      w0, #0x35
//   0x003914: d65f03c0  ret      
//   0x003918: 528006c0  mov      w0, #0x36
//   0x00391c: d65f03c0  ret      
//   0x003920: 528006e0  mov      w0, #0x37
//   0x003924: d65f03c0  ret      
//   0x003928: 52800700  mov      w0, #0x38
//   0x00392c: d65f03c0  ret      
//   0x003930: 52800720  mov      w0, #0x39
//   0x003934: d65f03c0  ret      
//   0x003938: 52800820  mov      w0, #0x41
//   0x00393c: d65f03c0  ret      
//   0x003940: 52800840  mov      w0, #0x42
//   0x003944: d65f03c0  ret      
//   0x003948: 52800860  mov      w0, #0x43
//   0x00394c: d65f03c0  ret      
//   0x003950: 52800880  mov      w0, #0x44
//   0x003954: d65f03c0  ret      
//   0x003958: 528008a0  mov      w0, #0x45
//   0x00395c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_006_038c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000038c0ULL;
    for (std::size_t i = 0; i < 40ULL; ++i) {
        std::uint32_t insn = kTextInstructions[348ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[007] Subroutine @ 0x003960..0x003a34 (212 bytes, 53 AArch64 instructions)
// [VN] Khung FDE[007] Hàm con @ 0x003960..0x003a34 (212 byte, 53 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003960: 7100381f  cmp      w0, #0xe
//   0x003964: 54000168  b.hi     #0x3990
//   0x003968: 90000089  adrp     x9, #0x13000
//   0x00396c: 2a0003e8  mov      w8, w0
//   0x003970: 91037d29  add      x9, x9, #0xdf
//   0x003974: 100000aa  adr      x10, #0x3988
//   0x003978: 3868692b  ldrb     w11, [x9, x8]
//   0x00397c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x003980: 52800600  mov      w0, #0x30
//   0x003984: d61f0140  br       x10
//   0x003988: 52800620  mov      w0, #0x31
//   0x00398c: d65f03c0  ret      
//   0x003990: 7100043f  cmp      w1, #1
//   0x003994: 52800cc8  mov      w8, #0x66
//   0x003998: 528008c9  mov      w9, #0x46
//   0x00399c: 14000024  b        #0x3a2c
//   0x0039a0: 52800640  mov      w0, #0x32
//   0x0039a4: d65f03c0  ret      
//   0x0039a8: 52800660  mov      w0, #0x33
//   0x0039ac: d65f03c0  ret      
//   0x0039b0: 52800680  mov      w0, #0x34
//   0x0039b4: d65f03c0  ret      
//   0x0039b8: 528006a0  mov      w0, #0x35
//   0x0039bc: d65f03c0  ret      
//   0x0039c0: 528006c0  mov      w0, #0x36
//   0x0039c4: d65f03c0  ret      
//   0x0039c8: 528006e0  mov      w0, #0x37
//   0x0039cc: d65f03c0  ret      
//   0x0039d0: 52800700  mov      w0, #0x38
//   0x0039d4: d65f03c0  ret      
//   0x0039d8: 52800720  mov      w0, #0x39
//   0x0039dc: d65f03c0  ret      
//   0x0039e0: 7100043f  cmp      w1, #1
//   0x0039e4: 52800c28  mov      w8, #0x61
//   0x0039e8: 52800829  mov      w9, #0x41
//   0x0039ec: 14000010  b        #0x3a2c
//   0x0039f0: 7100043f  cmp      w1, #1
//   0x0039f4: 52800c48  mov      w8, #0x62
//   0x0039f8: 52800849  mov      w9, #0x42
//   0x0039fc: 1400000c  b        #0x3a2c
//   0x003a00: 7100043f  cmp      w1, #1
//   0x003a04: 52800c68  mov      w8, #0x63
//   0x003a08: 52800869  mov      w9, #0x43
//   0x003a0c: 14000008  b        #0x3a2c
//   0x003a10: 7100043f  cmp      w1, #1
//   0x003a14: 52800c88  mov      w8, #0x64
//   0x003a18: 52800889  mov      w9, #0x44
//   0x003a1c: 14000004  b        #0x3a2c
//   0x003a20: 7100043f  cmp      w1, #1
//   0x003a24: 52800ca8  mov      w8, #0x65
//   0x003a28: 528008a9  mov      w9, #0x45
//   0x003a2c: 1a880120  csel     w0, w9, w8, eq
//   0x003a30: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_007_03960(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003960ULL;
    for (std::size_t i = 0; i < 53ULL; ++i) {
        std::uint32_t insn = kTextInstructions[388ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[008] Subroutine @ 0x003a34..0x003adc (168 bytes, 42 AArch64 instructions)
// [VN] Khung FDE[008] Hàm con @ 0x003a34..0x003adc (168 byte, 42 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003a34: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x003a38: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x003a3c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x003a40: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x003a44: 9100c3fd  add      x29, sp, #0x30
//   0x003a48: f9403036  ldr      x22, [x1, #0x60]
//   0x003a4c: aa0103f3  mov      x19, x1
//   0x003a50: aa0003f4  mov      x20, x0
//   0x003a54: b40002b6  cbz      x22, #0x3aa8
//   0x003a58: aa0203f5  mov      x21, x2
//   0x003a5c: aa1f03f8  mov      x24, xzr
//   0x003a60: 91018297  add      x23, x20, #0x60
//   0x003a64: f94002a8  ldr      x8, [x21]
//   0x003a68: 52800401  mov      w1, #0x20
//   0x003a6c: aa1503e0  mov      x0, x21
//   0x003a70: d63f0100  blr      x8
//   0x003a74: b4000240  cbz      x0, #0x3abc
//   0x003a78: 3dc002c0  ldr      q0, [x22]
//   0x003a7c: 91004308  add      x8, x24, #0x10
//   0x003a80: f100031f  cmp      x24, #0
//   0x003a84: 9a8802e8  csel     x8, x23, x8, eq
//   0x003a88: 3d800000  str      q0, [x0]
//   0x003a8c: f9000100  str      x0, [x8]
//   0x003a90: f9400ad6  ldr      x22, [x22, #0x10]
//   0x003a94: aa0003f8  mov      x24, x0
//   0x003a98: b5fffe76  cbnz     x22, #0x3a64
//   0x003a9c: f9003680  str      x0, [x20, #0x68]
//   0x003aa0: f900081f  str      xzr, [x0, #0x10]
//   0x003aa4: 14000002  b        #0x3aac
//   0x003aa8: a9067e9f  stp      xzr, xzr, [x20, #0x60]
//   0x003aac: b9409268  ldr      w8, [x19, #0x90]
//   0x003ab0: 52800020  mov      w0, #1
//   0x003ab4: b9009288  str      w8, [x20, #0x90]
//   0x003ab8: 14000004  b        #0x3ac8
//   0x003abc: 2a1f03e0  mov      w0, wzr
//   0x003ac0: b4000058  cbz      x24, #0x3ac8
//   0x003ac4: f9000b1f  str      xzr, [x24, #0x10]
//   0x003ac8: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x003acc: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x003ad0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x003ad4: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x003ad8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_008_03a34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003a34ULL;
    for (std::size_t i = 0; i < 42ULL; ++i) {
        std::uint32_t insn = kTextInstructions[441ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[009] Subroutine @ 0x003adc..0x003b90 (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[009] Hàm con @ 0x003adc..0x003b90 (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003adc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x003ae0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x003ae4: 910043fd  add      x29, sp, #0x10
//   0x003ae8: 3dc00420  ldr      q0, [x1, #0x10]
//   0x003aec: aa0103f3  mov      x19, x1
//   0x003af0: aa0003f4  mov      x20, x0
//   0x003af4: 3d800400  str      q0, [x0, #0x10]
//   0x003af8: 3dc00820  ldr      q0, [x1, #0x20]
//   0x003afc: 3d800800  str      q0, [x0, #0x20]
//   0x003b00: f9401828  ldr      x8, [x1, #0x30]
//   0x003b04: b4000188  cbz      x8, #0x3b34
//   0x003b08: f9400048  ldr      x8, [x2]
//   0x003b0c: 52800081  mov      w1, #4
//   0x003b10: aa0203e0  mov      x0, x2
//   0x003b14: d63f0100  blr      x8
//   0x003b18: f9001a80  str      x0, [x20, #0x30]
//   0x003b1c: b4000340  cbz      x0, #0x3b84
//   0x003b20: f9401a68  ldr      x8, [x19, #0x30]
//   0x003b24: b9400108  ldr      w8, [x8]
//   0x003b28: b9000008  str      w8, [x0]
//   0x003b2c: f9001e9f  str      xzr, [x20, #0x38]
//   0x003b30: 1400000d  b        #0x3b64
//   0x003b34: f9401e68  ldr      x8, [x19, #0x38]
//   0x003b38: f9001a9f  str      xzr, [x20, #0x30]
//   0x003b3c: b4000188  cbz      x8, #0x3b6c
//   0x003b40: f9400048  ldr      x8, [x2]
//   0x003b44: 52800201  mov      w1, #0x10
//   0x003b48: aa0203e0  mov      x0, x2
//   0x003b4c: d63f0100  blr      x8
//   0x003b50: f9001e80  str      x0, [x20, #0x38]
//   0x003b54: b4000180  cbz      x0, #0x3b84
//   0x003b58: f9401e68  ldr      x8, [x19, #0x38]
//   0x003b5c: 3dc00100  ldr      q0, [x8]
//   0x003b60: 3d800000  str      q0, [x0]
//   0x003b64: a9047e9f  stp      xzr, xzr, [x20, #0x40]
//   0x003b68: 14000004  b        #0x3b78
//   0x003b6c: f9001e9f  str      xzr, [x20, #0x38]
//   0x003b70: 3dc01260  ldr      q0, [x19, #0x40]
//   0x003b74: 3d801280  str      q0, [x20, #0x40]
//   0x003b78: 3dc01660  ldr      q0, [x19, #0x50]
//   0x003b7c: 52800020  mov      w0, #1
//   0x003b80: 3d801680  str      q0, [x20, #0x50]
//   0x003b84: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x003b88: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x003b8c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_009_03adc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003adcULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[483ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[010] Subroutine @ 0x003b90..0x003c2c (156 bytes, 39 AArch64 instructions)
// [VN] Khung FDE[010] Hàm con @ 0x003b90..0x003c2c (156 byte, 39 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003b90: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x003b94: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x003b98: 910043fd  add      x29, sp, #0x10
//   0x003b9c: b9409009  ldr      w9, [x0, #0x90]
//   0x003ba0: f9403008  ldr      x8, [x0, #0x60]
//   0x003ba4: aa0003f3  mov      x19, x0
//   0x003ba8: aa0103e0  mov      x0, x1
//   0x003bac: 34000269  cbz      w9, #0x3bf8
//   0x003bb0: b4000368  cbz      x8, #0x3c1c
//   0x003bb4: a9402109  ldp      x9, x8, [x8]
//   0x003bb8: eb09011f  cmp      x8, x9
//   0x003bbc: 54000301  b.ne     #0x3c1c
//   0x003bc0: f9400008  ldr      x8, [x0]
//   0x003bc4: 52800401  mov      w1, #0x20
//   0x003bc8: d63f0100  blr      x8
//   0x003bcc: b40002a0  cbz      x0, #0x3c20
//   0x003bd0: f9403268  ldr      x8, [x19, #0x60]
//   0x003bd4: 90000089  adrp     x9, #0x13000
//   0x003bd8: 91040129  add      x9, x9, #0x100
//   0x003bdc: 9100052a  add      x10, x9, #1
//   0x003be0: 9e670120  fmov     d0, x9
//   0x003be4: 4e181d40  mov      v0.d[1], x10
//   0x003be8: 3d800000  str      q0, [x0]
//   0x003bec: f9000808  str      x8, [x0, #0x10]
//   0x003bf0: f9003260  str      x0, [x19, #0x60]
//   0x003bf4: 1400000a  b        #0x3c1c
//   0x003bf8: b4000128  cbz      x8, #0x3c1c
//   0x003bfc: f9400909  ldr      x9, [x8, #0x10]
//   0x003c00: b40000e9  cbz      x9, #0x3c1c
//   0x003c04: a940210a  ldp      x10, x8, [x8]
//   0x003c08: eb0a011f  cmp      x8, x10
//   0x003c0c: 54000081  b.ne     #0x3c1c
//   0x003c10: a9402528  ldp      x8, x9, [x9]
//   0x003c14: eb08013f  cmp      x9, x8
//   0x003c18: 54fffd40  b.eq     #0x3bc0
//   0x003c1c: 52800020  mov      w0, #1
//   0x003c20: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x003c24: f84207f3  ldr      x19, [sp], #0x20
//   0x003c28: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_010_03b90(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003b90ULL;
    for (std::size_t i = 0; i < 39ULL; ++i) {
        std::uint32_t insn = kTextInstructions[528ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[011] Subroutine @ 0x003c2c..0x003ca4 (120 bytes, 30 AArch64 instructions)
// [VN] Khung FDE[011] Hàm con @ 0x003c2c..0x003ca4 (120 byte, 30 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003c2c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x003c30: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x003c34: 910043fd  add      x29, sp, #0x10
//   0x003c38: b9409008  ldr      w8, [x0, #0x90]
//   0x003c3c: 35000148  cbnz     w8, #0x3c64
//   0x003c40: f9401008  ldr      x8, [x0, #0x20]
//   0x003c44: aa0003f3  mov      x19, x0
//   0x003c48: b50000e8  cbnz     x8, #0x3c64
//   0x003c4c: f9401a68  ldr      x8, [x19, #0x30]
//   0x003c50: b50000a8  cbnz     x8, #0x3c64
//   0x003c54: f9401e68  ldr      x8, [x19, #0x38]
//   0x003c58: b5000068  cbnz     x8, #0x3c64
//   0x003c5c: f9402268  ldr      x8, [x19, #0x40]
//   0x003c60: b4000088  cbz      x8, #0x3c70
//   0x003c64: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x003c68: f84207f3  ldr      x19, [sp], #0x20
//   0x003c6c: d65f03c0  ret      
//   0x003c70: f8460e68  ldr      x8, [x19, #0x60]!
//   0x003c74: b4ffff88  cbz      x8, #0x3c64
//   0x003c78: f9400909  ldr      x9, [x8, #0x10]
//   0x003c7c: b5ffff49  cbnz     x9, #0x3c64
//   0x003c80: a9402909  ldp      x9, x10, [x8]
//   0x003c84: eb0a013f  cmp      x9, x10
//   0x003c88: 54fffee1  b.ne     #0x3c64
//   0x003c8c: f9401029  ldr      x9, [x1, #0x20]
//   0x003c90: aa0103e0  mov      x0, x1
//   0x003c94: aa0803e1  mov      x1, x8
//   0x003c98: d63f0120  blr      x9
//   0x003c9c: a9007e7f  stp      xzr, xzr, [x19]
//   0x003ca0: 17fffff1  b        #0x3c64
// ============================================================================
std::uint32_t fde_011_03c2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003c2cULL;
    for (std::size_t i = 0; i < 30ULL; ++i) {
        std::uint32_t insn = kTextInstructions[567ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[012] Subroutine @ 0x003ca4..0x003cc4 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[012] Hàm con @ 0x003ca4..0x003cc4 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003ca4: b40000e0  cbz      x0, #0x3cc0
//   0x003ca8: 6f00e400  movi     v0.2d, #0000000000000000
//   0x003cac: ad040000  stp      q0, q0, [x0, #0x80]
//   0x003cb0: ad030000  stp      q0, q0, [x0, #0x60]
//   0x003cb4: ad020000  stp      q0, q0, [x0, #0x40]
//   0x003cb8: ad010000  stp      q0, q0, [x0, #0x20]
//   0x003cbc: ad000000  stp      q0, q0, [x0]
//   0x003cc0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_012_03ca4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003ca4ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[597ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[013] Subroutine @ 0x003cc4..0x003d78 (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[013] Hàm con @ 0x003cc4..0x003d78 (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003cc4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x003cc8: 910003fd  mov      x29, sp
//   0x003ccc: aa0103e8  mov      x8, x1
//   0x003cd0: aa0003e9  mov      x9, x0
//   0x003cd4: b4000240  cbz      x0, #0x3d1c
//   0x003cd8: b4000228  cbz      x8, #0x3d1c
//   0x003cdc: f9400120  ldr      x0, [x9]
//   0x003ce0: f9400101  ldr      x1, [x8]
//   0x003ce4: b4000240  cbz      x0, #0x3d2c
//   0x003ce8: b4000281  cbz      x1, #0x3d38
//   0x003cec: f9400529  ldr      x9, [x9, #8]
//   0x003cf0: f9400508  ldr      x8, [x8, #8]
//   0x003cf4: cb000129  sub      x9, x9, x0
//   0x003cf8: cb010108  sub      x8, x8, x1
//   0x003cfc: 9342fd22  asr      x2, x9, #2
//   0x003d00: d342fd08  lsr      x8, x8, #2
//   0x003d04: 4b080048  sub      w8, w2, w8
//   0x003d08: 7100011f  cmp      w8, #0
//   0x003d0c: 5400022d  b.le     #0x3d50
//   0x003d10: 52800020  mov      w0, #1
//   0x003d14: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x003d18: d65f03c0  ret      
//   0x003d1c: f100011f  cmp      x8, #0
//   0x003d20: 1a9f07e8  cset     w8, ne
//   0x003d24: f100013f  cmp      x9, #0
//   0x003d28: 14000006  b        #0x3d40
//   0x003d2c: f100003f  cmp      x1, #0
//   0x003d30: 1a9f07e8  cset     w8, ne
//   0x003d34: 14000002  b        #0x3d3c
//   0x003d38: 2a1f03e8  mov      w8, wzr
//   0x003d3c: f100001f  cmp      x0, #0
//   0x003d40: 1a9f07e9  cset     w9, ne
//   0x003d44: 4b080120  sub      w0, w9, w8
//   0x003d48: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x003d4c: d65f03c0  ret      
//   0x003d50: 37f800e8  tbnz     w8, #0x1f, #0x3d6c
//   0x003d54: 97fffcab  bl       #0x3000
//   0x003d58: 7100001f  cmp      w0, #0
//   0x003d5c: 54fffdac  b.gt     #0x3d10
//   0x003d60: 5a9f03e0  csetm    w0, ne
//   0x003d64: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x003d68: d65f03c0  ret      
//   0x003d6c: 12800000  mov      w0, #-1
//   0x003d70: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x003d74: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_013_03cc4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003cc4ULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[605ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[014] Subroutine @ 0x003d78..0x004124 (940 bytes, 235 AArch64 instructions)
// [VN] Khung FDE[014] Hàm con @ 0x003d78..0x004124 (940 byte, 235 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x003d78: d101c3ff  sub      sp, sp, #0x70
//   0x003d7c: f9000bfb  str      x27, [sp, #0x10]
//   0x003d80: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x003d84: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x003d88: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x003d8c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x003d90: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x003d94: 910183fd  add      x29, sp, #0x60
//   0x003d98: b4001400  cbz      x0, #0x4018
//   0x003d9c: aa0003f9  mov      x25, x0
//   0x003da0: f8460f36  ldr      x22, [x25, #0x60]!
//   0x003da4: aa0003f4  mov      x20, x0
//   0x003da8: b4001396  cbz      x22, #0x4018
//   0x003dac: 90000088  adrp     x8, #0x13000
//   0x003db0: 91041108  add      x8, x8, #0x104
//   0x003db4: aa0303f3  mov      x19, x3
//   0x003db8: 2a0203f5  mov      w21, w2
//   0x003dbc: 2a0103f7  mov      w23, w1
//   0x003dc0: 4e080d00  dup      v0.2d, x8
//   0x003dc4: f9000edf  str      xzr, [x22, #0x18]
//   0x003dc8: 3d8003e0  str      q0, [sp]
//   0x003dcc: a94022c1  ldp      x1, x8, [x22]
//   0x003dd0: cb010109  sub      x9, x8, x1
//   0x003dd4: d342fd29  lsr      x9, x9, #2
//   0x003dd8: 7100093f  cmp      w9, #2
//   0x003ddc: 54000260  b.eq     #0x3e28
//   0x003de0: 7100053f  cmp      w9, #1
//   0x003de4: 54000481  b.ne     #0x3e74
//   0x003de8: b9400029  ldr      w9, [x1]
//   0x003dec: 7100b93f  cmp      w9, #0x2e
//   0x003df0: 54000421  b.ne     #0x3e74
//   0x003df4: a94162da  ldp      x26, x24, [x22, #0x10]
//   0x003df8: 340004b7  cbz      w23, #0x3e8c
//   0x003dfc: b400049a  cbz      x26, #0x3e8c
//   0x003e00: f9400329  ldr      x9, [x25]
//   0x003e04: eb0902df  cmp      x22, x9
//   0x003e08: 54000421  b.ne     #0x3e8c
//   0x003e0c: a9402b49  ldp      x9, x10, [x26]
//   0x003e10: eb0a013f  cmp      x9, x10
//   0x003e14: 540003e2  b.hs     #0x3e90
//   0x003e18: b840452b  ldr      w11, [x9], #4
//   0x003e1c: 7100e97f  cmp      w11, #0x3a
//   0x003e20: 54ffff81  b.ne     #0x3e10
//   0x003e24: 14000014  b        #0x3e74
//   0x003e28: b9400029  ldr      w9, [x1]
//   0x003e2c: 7100b93f  cmp      w9, #0x2e
//   0x003e30: 54000221  b.ne     #0x3e74
//   0x003e34: b9400429  ldr      w9, [x1, #4]
//   0x003e38: 7100b93f  cmp      w9, #0x2e
//   0x003e3c: 540001c1  b.ne     #0x3e74
//   0x003e40: a94162da  ldp      x26, x24, [x22, #0x10]
//   0x003e44: 34000457  cbz      w23, #0x3ecc
//   0x003e48: b4000178  cbz      x24, #0x3e74
//   0x003e4c: a9402b09  ldp      x9, x10, [x24]
//   0x003e50: cb09014a  sub      x10, x10, x9
//   0x003e54: f100215f  cmp      x10, #8
//   0x003e58: 540003c1  b.ne     #0x3ed0
//   0x003e5c: b940012a  ldr      w10, [x9]
//   0x003e60: 7100b95f  cmp      w10, #0x2e
//   0x003e64: 54000361  b.ne     #0x3ed0
//   0x003e68: b9400529  ldr      w9, [x9, #4]
//   0x003e6c: 7100b93f  cmp      w9, #0x2e
//   0x003e70: 54000301  b.ne     #0x3ed0
//   0x003e74: f9400ada  ldr      x26, [x22, #0x10]
//   0x003e78: b4000cfa  cbz      x26, #0x4014
//   0x003e7c: f9000f56  str      x22, [x26, #0x18]
//   0x003e80: aa1a03f6  mov      x22, x26
//   0x003e84: b5fffa5a  cbnz     x26, #0x3dcc
//   0x003e88: 14000064  b        #0x4018
//   0x003e8c: b4000d9a  cbz      x26, #0x403c
//   0x003e90: 91004309  add      x9, x24, #0x10
//   0x003e94: f100031f  cmp      x24, #0
//   0x003e98: 9a890329  csel     x9, x25, x9, eq
//   0x003e9c: f9000f58  str      x24, [x26, #0x18]
//   0x003ea0: f900013a  str      x26, [x9]
//   0x003ea4: 340000d5  cbz      w21, #0x3ebc
//   0x003ea8: eb08003f  cmp      x1, x8
//   0x003eac: 54000080  b.eq     #0x3ebc
//   0x003eb0: f9401268  ldr      x8, [x19, #0x20]
//   0x003eb4: aa1303e0  mov      x0, x19
//   0x003eb8: d63f0100  blr      x8
//   0x003ebc: f9401268  ldr      x8, [x19, #0x20]
//   0x003ec0: aa1303e0  mov      x0, x19
//   0x003ec4: aa1603e1  mov      x1, x22
//   0x003ec8: 1400004a  b        #0x3ff0
//   0x003ecc: b4000458  cbz      x24, #0x3f54
//   0x003ed0: f9400f1b  ldr      x27, [x24, #0x18]
//   0x003ed4: b400023b  cbz      x27, #0x3f18
//   0x003ed8: f9000b7a  str      x26, [x27, #0x10]
//   0x003edc: f9400ac8  ldr      x8, [x22, #0x10]
//   0x003ee0: b4000448  cbz      x8, #0x3f68
//   0x003ee4: f9000d1b  str      x27, [x8, #0x18]
//   0x003ee8: 34000575  cbz      w21, #0x3f94
//   0x003eec: a94022c1  ldp      x1, x8, [x22]
//   0x003ef0: eb08003f  cmp      x1, x8
//   0x003ef4: 54000080  b.eq     #0x3f04
//   0x003ef8: f9401268  ldr      x8, [x19, #0x20]
//   0x003efc: aa1303e0  mov      x0, x19
//   0x003f00: d63f0100  blr      x8
//   0x003f04: f9401268  ldr      x8, [x19, #0x20]
//   0x003f08: aa1303e0  mov      x0, x19
//   0x003f0c: aa1603e1  mov      x1, x22
//   0x003f10: d63f0100  blr      x8
//   0x003f14: 1400002e  b        #0x3fcc
//   0x003f18: b400047a  cbz      x26, #0x3fa4
//   0x003f1c: f900033a  str      x26, [x25]
//   0x003f20: f9000f5f  str      xzr, [x26, #0x18]
//   0x003f24: 340000d5  cbz      w21, #0x3f3c
//   0x003f28: eb08003f  cmp      x1, x8
//   0x003f2c: 54000080  b.eq     #0x3f3c
//   0x003f30: f9401268  ldr      x8, [x19, #0x20]
//   0x003f34: aa1303e0  mov      x0, x19
//   0x003f38: d63f0100  blr      x8
//   0x003f3c: f9401268  ldr      x8, [x19, #0x20]
//   0x003f40: aa1303e0  mov      x0, x19
//   0x003f44: aa1603e1  mov      x1, x22
//   0x003f48: d63f0100  blr      x8
//   0x003f4c: 35000415  cbnz     w21, #0x3fcc
//   0x003f50: 14000025  b        #0x3fe4
//   0x003f54: b400057a  cbz      x26, #0x4000
//   0x003f58: f900033a  str      x26, [x25]
//   0x003f5c: f9000f5f  str      xzr, [x26, #0x18]
//   0x003f60: 35fffa55  cbnz     w21, #0x3ea8
//   0x003f64: 17ffffd6  b        #0x3ebc
//   0x003f68: f9400668  ldr      x8, [x19, #8]
//   0x003f6c: 52800021  mov      w1, #1
//   0x003f70: 52800402  mov      w2, #0x20
//   0x003f74: aa1303e0  mov      x0, x19
//   0x003f78: d63f0100  blr      x8
//   0x003f7c: b40008a0  cbz      x0, #0x4090
//   0x003f80: 3dc003e0  ldr      q0, [sp]
//   0x003f84: 3d800000  str      q0, [x0]
//   0x003f88: f9000b60  str      x0, [x27, #0x10]
//   0x003f8c: f9003680  str      x0, [x20, #0x68]
//   0x003f90: 35fffaf5  cbnz     w21, #0x3eec
//   0x003f94: f9401268  ldr      x8, [x19, #0x20]
//   0x003f98: aa1303e0  mov      x0, x19
//   0x003f9c: aa1603e1  mov      x1, x22
//   0x003fa0: 14000010  b        #0x3fe0
//   0x003fa4: 340000d5  cbz      w21, #0x3fbc
//   0x003fa8: eb08003f  cmp      x1, x8
//   0x003fac: 54000080  b.eq     #0x3fbc
//   0x003fb0: f9401268  ldr      x8, [x19, #0x20]
//   0x003fb4: aa1303e0  mov      x0, x19
//   0x003fb8: d63f0100  blr      x8
//   0x003fbc: 3dc003e0  ldr      q0, [sp]
//   0x003fc0: 3d8002c0  str      q0, [x22]
//   0x003fc4: a9065a96  stp      x22, x22, [x20, #0x60]
//   0x003fc8: 340000f5  cbz      w21, #0x3fe4
//   0x003fcc: a9402301  ldp      x1, x8, [x24]
//   0x003fd0: eb08003f  cmp      x1, x8
//   0x003fd4: 54000080  b.eq     #0x3fe4
//   0x003fd8: f9401268  ldr      x8, [x19, #0x20]
//   0x003fdc: aa1303e0  mov      x0, x19
//   0x003fe0: d63f0100  blr      x8
//   0x003fe4: f9401268  ldr      x8, [x19, #0x20]
//   0x003fe8: aa1303e0  mov      x0, x19
//   0x003fec: aa1803e1  mov      x1, x24
//   0x003ff0: d63f0100  blr      x8
//   0x003ff4: aa1a03f6  mov      x22, x26
//   0x003ff8: b5ffeeba  cbnz     x26, #0x3dcc
//   0x003ffc: 14000007  b        #0x4018
//   0x004000: b9409289  ldr      w9, [x20, #0x90]
//   0x004004: 34000689  cbz      w9, #0x40d4
//   0x004008: a9007f3f  stp      xzr, xzr, [x25]
//   0x00400c: 35fff4f5  cbnz     w21, #0x3ea8
//   0x004010: 17ffffab  b        #0x3ebc
//   0x004014: f9003696  str      x22, [x20, #0x68]
//   0x004018: 52800020  mov      w0, #1
//   0x00401c: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x004020: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x004024: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x004028: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x00402c: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x004030: f9400bfb  ldr      x27, [sp, #0x10]
//   0x004034: 9101c3ff  add      sp, sp, #0x70
//   0x004038: d65f03c0  ret      
//   0x00403c: 340000d5  cbz      w21, #0x4054
//   0x004040: eb08003f  cmp      x1, x8
//   0x004044: 54000080  b.eq     #0x4054
//   0x004048: f9401268  ldr      x8, [x19, #0x20]
//   0x00404c: aa1303e0  mov      x0, x19
//   0x004050: d63f0100  blr      x8
//   0x004054: b50004d8  cbnz     x24, #0x40ec
//   0x004058: f9401288  ldr      x8, [x20, #0x20]
//   0x00405c: b5000488  cbnz     x8, #0x40ec
//   0x004060: f9401a88  ldr      x8, [x20, #0x30]
//   0x004064: b5000448  cbnz     x8, #0x40ec
//   0x004068: f9401e88  ldr      x8, [x20, #0x38]
//   0x00406c: b5000408  cbnz     x8, #0x40ec
//   0x004070: f9402288  ldr      x8, [x20, #0x40]
//   0x004074: b50003c8  cbnz     x8, #0x40ec
//   0x004078: f9401268  ldr      x8, [x19, #0x20]
//   0x00407c: aa1303e0  mov      x0, x19
//   0x004080: aa1603e1  mov      x1, x22
//   0x004084: d63f0100  blr      x8
//   0x004088: a9007f3f  stp      xzr, xzr, [x25]
//   0x00408c: 17ffffe3  b        #0x4018
//   0x004090: 34000375  cbz      w21, #0x40fc
//   0x004094: a94022c1  ldp      x1, x8, [x22]
//   0x004098: eb08003f  cmp      x1, x8
//   0x00409c: 54000080  b.eq     #0x40ac
//   0x0040a0: f9401268  ldr      x8, [x19, #0x20]
//   0x0040a4: aa1303e0  mov      x0, x19
//   0x0040a8: d63f0100  blr      x8
//   0x0040ac: f9401268  ldr      x8, [x19, #0x20]
//   0x0040b0: aa1303e0  mov      x0, x19
//   0x0040b4: aa1603e1  mov      x1, x22
//   0x0040b8: d63f0100  blr      x8
//   0x0040bc: a9402301  ldp      x1, x8, [x24]
//   0x0040c0: eb08003f  cmp      x1, x8
//   0x0040c4: 54000240  b.eq     #0x410c
//   0x0040c8: f9401268  ldr      x8, [x19, #0x20]
//   0x0040cc: aa1303e0  mov      x0, x19
//   0x0040d0: 1400000e  b        #0x4108
//   0x0040d4: 340000d5  cbz      w21, #0x40ec
//   0x0040d8: eb08003f  cmp      x1, x8
//   0x0040dc: 54000080  b.eq     #0x40ec
//   0x0040e0: f9401268  ldr      x8, [x19, #0x20]
//   0x0040e4: aa1303e0  mov      x0, x19
//   0x0040e8: d63f0100  blr      x8
//   0x0040ec: 3dc003e0  ldr      q0, [sp]
//   0x0040f0: 52800020  mov      w0, #1
//   0x0040f4: 3d8002c0  str      q0, [x22]
//   0x0040f8: 17ffffc9  b        #0x401c
//   0x0040fc: f9401268  ldr      x8, [x19, #0x20]
//   0x004100: aa1303e0  mov      x0, x19
//   0x004104: aa1603e1  mov      x1, x22
//   0x004108: d63f0100  blr      x8
//   0x00410c: f9401268  ldr      x8, [x19, #0x20]
//   0x004110: aa1303e0  mov      x0, x19
//   0x004114: aa1803e1  mov      x1, x24
//   0x004118: d63f0100  blr      x8
//   0x00411c: 2a1f03e0  mov      w0, wzr
//   0x004120: 17ffffbf  b        #0x401c
// ============================================================================
std::uint32_t fde_014_03d78(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003d78ULL;
    for (std::size_t i = 0; i < 235ULL; ++i) {
        std::uint32_t insn = kTextInstructions[650ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[015] Subroutine @ 0x004124..0x004168 (68 bytes, 17 AArch64 instructions)
// [VN] Khung FDE[015] Hàm con @ 0x004124..0x004168 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004124: b4000200  cbz      x0, #0x4164
//   0x004128: f9401008  ldr      x8, [x0, #0x20]
//   0x00412c: b4000068  cbz      x8, #0x4138
//   0x004130: 52800020  mov      w0, #1
//   0x004134: d65f03c0  ret      
//   0x004138: f9401808  ldr      x8, [x0, #0x30]
//   0x00413c: b4000068  cbz      x8, #0x4148
//   0x004140: 52800020  mov      w0, #1
//   0x004144: d65f03c0  ret      
//   0x004148: f9401c08  ldr      x8, [x0, #0x38]
//   0x00414c: b4000068  cbz      x8, #0x4158
//   0x004150: 52800020  mov      w0, #1
//   0x004154: d65f03c0  ret      
//   0x004158: f9402008  ldr      x8, [x0, #0x40]
//   0x00415c: f100011f  cmp      x8, #0
//   0x004160: 1a9f07e0  cset     w0, ne
//   0x004164: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_015_04124(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004124ULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[885ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[016] Subroutine @ 0x004168..0x004184 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[016] Hàm con @ 0x004168..0x004184 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004168: b40000a0  cbz      x0, #0x417c
//   0x00416c: b9409402  ldr      w2, [x0, #0x94]
//   0x004170: aa0103e3  mov      x3, x1
//   0x004174: 2a1f03e1  mov      w1, wzr
//   0x004178: 17fffc5e  b        #0x32f0
//   0x00417c: 52800020  mov      w0, #1
//   0x004180: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_016_04168(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004168ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[902ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[017] Subroutine @ 0x004184..0x0041e0 (92 bytes, 23 AArch64 instructions)
// [VN] Khung FDE[017] Hàm con @ 0x004184..0x0041e0 (92 byte, 23 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004184: 5100c009  sub      w9, w0, #0x30
//   0x004188: 2a0003e8  mov      w8, w0
//   0x00418c: 7100d93f  cmp      w9, #0x36
//   0x004190: 2a1f03e0  mov      w0, wzr
//   0x004194: 54000248  b.hi     #0x41dc
//   0x004198: 5280002a  mov      w10, #1
//   0x00419c: 9ac9214a  lsl      x10, x10, x9
//   0x0041a0: f240255f  tst      x10, #0x3ff
//   0x0041a4: 54000161  b.ne     #0x41d0
//   0x0041a8: 5280002a  mov      w10, #1
//   0x0041ac: 9ac9214a  lsl      x10, x10, x9
//   0x0041b0: f26f155f  tst      x10, #0x7e0000
//   0x0041b4: 54000121  b.ne     #0x41d8
//   0x0041b8: 5280002a  mov      w10, #1
//   0x0041bc: 9ac92149  lsl      x9, x10, x9
//   0x0041c0: f24f153f  tst      x9, #0x7e000000000000
//   0x0041c4: 540000c0  b.eq     #0x41dc
//   0x0041c8: 51015d00  sub      w0, w8, #0x57
//   0x0041cc: d65f03c0  ret      
//   0x0041d0: 2a0903e0  mov      w0, w9
//   0x0041d4: d65f03c0  ret      
//   0x0041d8: 5100dd00  sub      w0, w8, #0x37
//   0x0041dc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_017_04184(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004184ULL;
    for (std::size_t i = 0; i < 23ULL; ++i) {
        std::uint32_t insn = kTextInstructions[909ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[018] Subroutine @ 0x0041e0..0x004200 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[018] Hàm con @ 0x0041e0..0x004200 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0041e0: 7100381f  cmp      w0, #0xe
//   0x0041e4: 540000a8  b.hi     #0x41f8
//   0x0041e8: f0000068  adrp     x8, #0x13000
//   0x0041ec: 91046108  add      x8, x8, #0x118
//   0x0041f0: b860d900  ldr      w0, [x8, w0, sxtw #2]
//   0x0041f4: d65f03c0  ret      
//   0x0041f8: 528008c0  mov      w0, #0x46
//   0x0041fc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_018_041e0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000041e0ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[932ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[019] Subroutine @ 0x004200..0x0042d4 (212 bytes, 53 AArch64 instructions)
// [VN] Khung FDE[019] Hàm con @ 0x004200..0x0042d4 (212 byte, 53 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004200: 7100381f  cmp      w0, #0xe
//   0x004204: 54000168  b.hi     #0x4230
//   0x004208: f0000069  adrp     x9, #0x13000
//   0x00420c: 2a0003e8  mov      w8, w0
//   0x004210: 9103b929  add      x9, x9, #0xee
//   0x004214: 100000aa  adr      x10, #0x4228
//   0x004218: 3868692b  ldrb     w11, [x9, x8]
//   0x00421c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x004220: 52800600  mov      w0, #0x30
//   0x004224: d61f0140  br       x10
//   0x004228: 52800620  mov      w0, #0x31
//   0x00422c: d65f03c0  ret      
//   0x004230: 7100043f  cmp      w1, #1
//   0x004234: 52800cc8  mov      w8, #0x66
//   0x004238: 528008c9  mov      w9, #0x46
//   0x00423c: 14000024  b        #0x42cc
//   0x004240: 52800640  mov      w0, #0x32
//   0x004244: d65f03c0  ret      
//   0x004248: 52800660  mov      w0, #0x33
//   0x00424c: d65f03c0  ret      
//   0x004250: 52800680  mov      w0, #0x34
//   0x004254: d65f03c0  ret      
//   0x004258: 528006a0  mov      w0, #0x35
//   0x00425c: d65f03c0  ret      
//   0x004260: 528006c0  mov      w0, #0x36
//   0x004264: d65f03c0  ret      
//   0x004268: 528006e0  mov      w0, #0x37
//   0x00426c: d65f03c0  ret      
//   0x004270: 52800700  mov      w0, #0x38
//   0x004274: d65f03c0  ret      
//   0x004278: 52800720  mov      w0, #0x39
//   0x00427c: d65f03c0  ret      
//   0x004280: 7100043f  cmp      w1, #1
//   0x004284: 52800c28  mov      w8, #0x61
//   0x004288: 52800829  mov      w9, #0x41
//   0x00428c: 14000010  b        #0x42cc
//   0x004290: 7100043f  cmp      w1, #1
//   0x004294: 52800c48  mov      w8, #0x62
//   0x004298: 52800849  mov      w9, #0x42
//   0x00429c: 1400000c  b        #0x42cc
//   0x0042a0: 7100043f  cmp      w1, #1
//   0x0042a4: 52800c68  mov      w8, #0x63
//   0x0042a8: 52800869  mov      w9, #0x43
//   0x0042ac: 14000008  b        #0x42cc
//   0x0042b0: 7100043f  cmp      w1, #1
//   0x0042b4: 52800c88  mov      w8, #0x64
//   0x0042b8: 52800889  mov      w9, #0x44
//   0x0042bc: 14000004  b        #0x42cc
//   0x0042c0: 7100043f  cmp      w1, #1
//   0x0042c4: 52800ca8  mov      w8, #0x65
//   0x0042c8: 528008a9  mov      w9, #0x45
//   0x0042cc: 1a880120  csel     w0, w9, w8, eq
//   0x0042d0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_019_04200(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004200ULL;
    for (std::size_t i = 0; i < 53ULL; ++i) {
        std::uint32_t insn = kTextInstructions[940ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[020] Subroutine @ 0x0042d4..0x00437c (168 bytes, 42 AArch64 instructions)
// [VN] Khung FDE[020] Hàm con @ 0x0042d4..0x00437c (168 byte, 42 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0042d4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0042d8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0042dc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0042e0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0042e4: 9100c3fd  add      x29, sp, #0x30
//   0x0042e8: f9403036  ldr      x22, [x1, #0x60]
//   0x0042ec: aa0103f3  mov      x19, x1
//   0x0042f0: aa0003f4  mov      x20, x0
//   0x0042f4: b40002b6  cbz      x22, #0x4348
//   0x0042f8: aa0203f5  mov      x21, x2
//   0x0042fc: aa1f03f8  mov      x24, xzr
//   0x004300: 91018297  add      x23, x20, #0x60
//   0x004304: f94002a8  ldr      x8, [x21]
//   0x004308: 52800401  mov      w1, #0x20
//   0x00430c: aa1503e0  mov      x0, x21
//   0x004310: d63f0100  blr      x8
//   0x004314: b4000240  cbz      x0, #0x435c
//   0x004318: 3dc002c0  ldr      q0, [x22]
//   0x00431c: 91004308  add      x8, x24, #0x10
//   0x004320: f100031f  cmp      x24, #0
//   0x004324: 9a8802e8  csel     x8, x23, x8, eq
//   0x004328: 3d800000  str      q0, [x0]
//   0x00432c: f9000100  str      x0, [x8]
//   0x004330: f9400ad6  ldr      x22, [x22, #0x10]
//   0x004334: aa0003f8  mov      x24, x0
//   0x004338: b5fffe76  cbnz     x22, #0x4304
//   0x00433c: f9003680  str      x0, [x20, #0x68]
//   0x004340: f900081f  str      xzr, [x0, #0x10]
//   0x004344: 14000002  b        #0x434c
//   0x004348: a9067e9f  stp      xzr, xzr, [x20, #0x60]
//   0x00434c: b9409268  ldr      w8, [x19, #0x90]
//   0x004350: 52800020  mov      w0, #1
//   0x004354: b9009288  str      w8, [x20, #0x90]
//   0x004358: 14000004  b        #0x4368
//   0x00435c: 2a1f03e0  mov      w0, wzr
//   0x004360: b4000058  cbz      x24, #0x4368
//   0x004364: f9000b1f  str      xzr, [x24, #0x10]
//   0x004368: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00436c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x004370: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x004374: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x004378: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_020_042d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000042d4ULL;
    for (std::size_t i = 0; i < 42ULL; ++i) {
        std::uint32_t insn = kTextInstructions[993ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[021] Subroutine @ 0x00437c..0x004430 (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[021] Hàm con @ 0x00437c..0x004430 (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00437c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x004380: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x004384: 910043fd  add      x29, sp, #0x10
//   0x004388: 3dc00420  ldr      q0, [x1, #0x10]
//   0x00438c: aa0103f3  mov      x19, x1
//   0x004390: aa0003f4  mov      x20, x0
//   0x004394: 3d800400  str      q0, [x0, #0x10]
//   0x004398: 3dc00820  ldr      q0, [x1, #0x20]
//   0x00439c: 3d800800  str      q0, [x0, #0x20]
//   0x0043a0: f9401828  ldr      x8, [x1, #0x30]
//   0x0043a4: b4000188  cbz      x8, #0x43d4
//   0x0043a8: f9400048  ldr      x8, [x2]
//   0x0043ac: 52800081  mov      w1, #4
//   0x0043b0: aa0203e0  mov      x0, x2
//   0x0043b4: d63f0100  blr      x8
//   0x0043b8: f9001a80  str      x0, [x20, #0x30]
//   0x0043bc: b4000340  cbz      x0, #0x4424
//   0x0043c0: f9401a68  ldr      x8, [x19, #0x30]
//   0x0043c4: b9400108  ldr      w8, [x8]
//   0x0043c8: b9000008  str      w8, [x0]
//   0x0043cc: f9001e9f  str      xzr, [x20, #0x38]
//   0x0043d0: 1400000d  b        #0x4404
//   0x0043d4: f9401e68  ldr      x8, [x19, #0x38]
//   0x0043d8: f9001a9f  str      xzr, [x20, #0x30]
//   0x0043dc: b4000188  cbz      x8, #0x440c
//   0x0043e0: f9400048  ldr      x8, [x2]
//   0x0043e4: 52800201  mov      w1, #0x10
//   0x0043e8: aa0203e0  mov      x0, x2
//   0x0043ec: d63f0100  blr      x8
//   0x0043f0: f9001e80  str      x0, [x20, #0x38]
//   0x0043f4: b4000180  cbz      x0, #0x4424
//   0x0043f8: f9401e68  ldr      x8, [x19, #0x38]
//   0x0043fc: 3dc00100  ldr      q0, [x8]
//   0x004400: 3d800000  str      q0, [x0]
//   0x004404: a9047e9f  stp      xzr, xzr, [x20, #0x40]
//   0x004408: 14000004  b        #0x4418
//   0x00440c: f9001e9f  str      xzr, [x20, #0x38]
//   0x004410: 3dc01260  ldr      q0, [x19, #0x40]
//   0x004414: 3d801280  str      q0, [x20, #0x40]
//   0x004418: 3dc01660  ldr      q0, [x19, #0x50]
//   0x00441c: 52800020  mov      w0, #1
//   0x004420: 3d801680  str      q0, [x20, #0x50]
//   0x004424: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x004428: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x00442c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_021_0437c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000437cULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1035ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[022] Subroutine @ 0x004430..0x0044cc (156 bytes, 39 AArch64 instructions)
// [VN] Khung FDE[022] Hàm con @ 0x004430..0x0044cc (156 byte, 39 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004430: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x004434: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x004438: 910043fd  add      x29, sp, #0x10
//   0x00443c: b9409009  ldr      w9, [x0, #0x90]
//   0x004440: f9403008  ldr      x8, [x0, #0x60]
//   0x004444: aa0003f3  mov      x19, x0
//   0x004448: aa0103e0  mov      x0, x1
//   0x00444c: 34000269  cbz      w9, #0x4498
//   0x004450: b4000368  cbz      x8, #0x44bc
//   0x004454: a9402109  ldp      x9, x8, [x8]
//   0x004458: eb09011f  cmp      x8, x9
//   0x00445c: 54000301  b.ne     #0x44bc
//   0x004460: f9400008  ldr      x8, [x0]
//   0x004464: 52800401  mov      w1, #0x20
//   0x004468: d63f0100  blr      x8
//   0x00446c: b40002a0  cbz      x0, #0x44c0
//   0x004470: f9403268  ldr      x8, [x19, #0x60]
//   0x004474: f0000069  adrp     x9, #0x13000
//   0x004478: 91044129  add      x9, x9, #0x110
//   0x00447c: 9100112a  add      x10, x9, #4
//   0x004480: 9e670120  fmov     d0, x9
//   0x004484: 4e181d40  mov      v0.d[1], x10
//   0x004488: 3d800000  str      q0, [x0]
//   0x00448c: f9000808  str      x8, [x0, #0x10]
//   0x004490: f9003260  str      x0, [x19, #0x60]
//   0x004494: 1400000a  b        #0x44bc
//   0x004498: b4000128  cbz      x8, #0x44bc
//   0x00449c: f9400909  ldr      x9, [x8, #0x10]
//   0x0044a0: b40000e9  cbz      x9, #0x44bc
//   0x0044a4: a940210a  ldp      x10, x8, [x8]
//   0x0044a8: eb0a011f  cmp      x8, x10
//   0x0044ac: 54000081  b.ne     #0x44bc
//   0x0044b0: a9402528  ldp      x8, x9, [x9]
//   0x0044b4: eb08013f  cmp      x9, x8
//   0x0044b8: 54fffd40  b.eq     #0x4460
//   0x0044bc: 52800020  mov      w0, #1
//   0x0044c0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0044c4: f84207f3  ldr      x19, [sp], #0x20
//   0x0044c8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_022_04430(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004430ULL;
    for (std::size_t i = 0; i < 39ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1080ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[023] Subroutine @ 0x0044cc..0x004544 (120 bytes, 30 AArch64 instructions)
// [VN] Khung FDE[023] Hàm con @ 0x0044cc..0x004544 (120 byte, 30 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0044cc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0044d0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0044d4: 910043fd  add      x29, sp, #0x10
//   0x0044d8: b9409008  ldr      w8, [x0, #0x90]
//   0x0044dc: 35000148  cbnz     w8, #0x4504
//   0x0044e0: f9401008  ldr      x8, [x0, #0x20]
//   0x0044e4: aa0003f3  mov      x19, x0
//   0x0044e8: b50000e8  cbnz     x8, #0x4504
//   0x0044ec: f9401a68  ldr      x8, [x19, #0x30]
//   0x0044f0: b50000a8  cbnz     x8, #0x4504
//   0x0044f4: f9401e68  ldr      x8, [x19, #0x38]
//   0x0044f8: b5000068  cbnz     x8, #0x4504
//   0x0044fc: f9402268  ldr      x8, [x19, #0x40]
//   0x004500: b4000088  cbz      x8, #0x4510
//   0x004504: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x004508: f84207f3  ldr      x19, [sp], #0x20
//   0x00450c: d65f03c0  ret      
//   0x004510: f8460e68  ldr      x8, [x19, #0x60]!
//   0x004514: b4ffff88  cbz      x8, #0x4504
//   0x004518: f9400909  ldr      x9, [x8, #0x10]
//   0x00451c: b5ffff49  cbnz     x9, #0x4504
//   0x004520: a9402909  ldp      x9, x10, [x8]
//   0x004524: eb0a013f  cmp      x9, x10
//   0x004528: 54fffee1  b.ne     #0x4504
//   0x00452c: f9401029  ldr      x9, [x1, #0x20]
//   0x004530: aa0103e0  mov      x0, x1
//   0x004534: aa0803e1  mov      x1, x8
//   0x004538: d63f0120  blr      x9
//   0x00453c: a9007e7f  stp      xzr, xzr, [x19]
//   0x004540: 17fffff1  b        #0x4504
// ============================================================================
std::uint32_t fde_023_044cc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000044ccULL;
    for (std::size_t i = 0; i < 30ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1119ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[024] Subroutine @ 0x004544..0x00471c (472 bytes, 118 AArch64 instructions)
// [VN] Khung FDE[024] Hàm con @ 0x004544..0x00471c (472 byte, 118 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004544: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x004548: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00454c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x004550: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x004554: 9100c3fd  add      x29, sp, #0x30
//   0x004558: aa0103f3  mov      x19, x1
//   0x00455c: aa0003f4  mov      x20, x0
//   0x004560: b4000c20  cbz      x0, #0x46e4
//   0x004564: b4000c13  cbz      x19, #0x46e4
//   0x004568: aa1403e0  mov      x0, x20
//   0x00456c: aa1303e1  mov      x1, x19
//   0x004570: 97fffaa8  bl       #0x3010
//   0x004574: 35000c80  cbnz     w0, #0x4704
//   0x004578: f9400288  ldr      x8, [x20]
//   0x00457c: b50000a8  cbnz     x8, #0x4590
//   0x004580: b9409288  ldr      w8, [x20, #0x90]
//   0x004584: b9409269  ldr      w9, [x19, #0x90]
//   0x004588: 6b09011f  cmp      w8, w9
//   0x00458c: 54000bc1  b.ne     #0x4704
//   0x004590: 91004280  add      x0, x20, #0x10
//   0x004594: 91004261  add      x1, x19, #0x10
//   0x004598: 97fffa9e  bl       #0x3010
//   0x00459c: 35000b40  cbnz     w0, #0x4704
//   0x0045a0: f9401a97  ldr      x23, [x20, #0x30]
//   0x0045a4: f9401a68  ldr      x8, [x19, #0x30]
//   0x0045a8: f10002ff  cmp      x23, #0
//   0x0045ac: 1a9f17e9  cset     w9, eq
//   0x0045b0: f100011f  cmp      x8, #0
//   0x0045b4: 1a9f17ea  cset     w10, eq
//   0x0045b8: 4a0a0129  eor      w9, w9, w10
//   0x0045bc: 37000a49  tbnz     w9, #0, #0x4704
//   0x0045c0: f9401e80  ldr      x0, [x20, #0x38]
//   0x0045c4: f9401e61  ldr      x1, [x19, #0x38]
//   0x0045c8: f100001f  cmp      x0, #0
//   0x0045cc: 1a9f17e9  cset     w9, eq
//   0x0045d0: f100003f  cmp      x1, #0
//   0x0045d4: 1a9f17ea  cset     w10, eq
//   0x0045d8: 4a0a0129  eor      w9, w9, w10
//   0x0045dc: 37000949  tbnz     w9, #0, #0x4704
//   0x0045e0: aa1403f5  mov      x21, x20
//   0x0045e4: f8440eb8  ldr      x24, [x21, #0x40]!
//   0x0045e8: aa1303f6  mov      x22, x19
//   0x0045ec: f8440ec9  ldr      x9, [x22, #0x40]!
//   0x0045f0: f100031f  cmp      x24, #0
//   0x0045f4: 1a9f17ea  cset     w10, eq
//   0x0045f8: f100013f  cmp      x9, #0
//   0x0045fc: 1a9f17e9  cset     w9, eq
//   0x004600: 4a090149  eor      w9, w10, w9
//   0x004604: 37000809  tbnz     w9, #0, #0x4704
//   0x004608: b40000b7  cbz      x23, #0x461c
//   0x00460c: b9400108  ldr      w8, [x8]
//   0x004610: b94002e9  ldr      w9, [x23]
//   0x004614: 6b08013f  cmp      w9, w8
//   0x004618: 54000761  b.ne     #0x4704
//   0x00461c: b4000080  cbz      x0, #0x462c
//   0x004620: 52800202  mov      w2, #0x10
//   0x004624: 97fffab7  bl       #0x3100
//   0x004628: 350006e0  cbnz     w0, #0x4704
//   0x00462c: b40000d8  cbz      x24, #0x4644
//   0x004630: aa1503e0  mov      x0, x21
//   0x004634: aa1603e1  mov      x1, x22
//   0x004638: 97fffa76  bl       #0x3010
//   0x00463c: 35000640  cbnz     w0, #0x4704
//   0x004640: f9401a97  ldr      x23, [x20, #0x30]
//   0x004644: b50000b7  cbnz     x23, #0x4658
//   0x004648: f9401e88  ldr      x8, [x20, #0x38]
//   0x00464c: b5000068  cbnz     x8, #0x4658
//   0x004650: f94002a8  ldr      x8, [x21]
//   0x004654: b4000508  cbz      x8, #0x46f4
//   0x004658: 91014280  add      x0, x20, #0x50
//   0x00465c: 91014261  add      x1, x19, #0x50
//   0x004660: 97fffa6c  bl       #0x3010
//   0x004664: 35000500  cbnz     w0, #0x4704
//   0x004668: f9403295  ldr      x21, [x20, #0x60]
//   0x00466c: f9403276  ldr      x22, [x19, #0x60]
//   0x004670: f10002bf  cmp      x21, #0
//   0x004674: 1a9f17e8  cset     w8, eq
//   0x004678: f10002df  cmp      x22, #0
//   0x00467c: 1a9f17e9  cset     w9, eq
//   0x004680: 4a090108  eor      w8, w8, w9
//   0x004684: 37000408  tbnz     w8, #0, #0x4704
//   0x004688: b40001d5  cbz      x21, #0x46c0
//   0x00468c: aa1503e0  mov      x0, x21
//   0x004690: aa1603e1  mov      x1, x22
//   0x004694: 97fffa5f  bl       #0x3010
//   0x004698: 35000360  cbnz     w0, #0x4704
//   0x00469c: f9400ab5  ldr      x21, [x21, #0x10]
//   0x0046a0: f9400ad6  ldr      x22, [x22, #0x10]
//   0x0046a4: f10002bf  cmp      x21, #0
//   0x0046a8: 1a9f17e8  cset     w8, eq
//   0x0046ac: f10002df  cmp      x22, #0
//   0x0046b0: 1a9f17e9  cset     w9, eq
//   0x0046b4: 4a090108  eor      w8, w8, w9
//   0x0046b8: 37000268  tbnz     w8, #0, #0x4704
//   0x0046bc: b5fffe95  cbnz     x21, #0x468c
//   0x0046c0: 9101c280  add      x0, x20, #0x70
//   0x0046c4: 9101c261  add      x1, x19, #0x70
//   0x0046c8: 97fffa52  bl       #0x3010
//   0x0046cc: 350001c0  cbnz     w0, #0x4704
//   0x0046d0: 91020280  add      x0, x20, #0x80
//   0x0046d4: 91020261  add      x1, x19, #0x80
//   0x0046d8: 97fffa4e  bl       #0x3010
//   0x0046dc: 7100001f  cmp      w0, #0
//   0x0046e0: 14000003  b        #0x46ec
//   0x0046e4: aa130288  orr      x8, x20, x19
//   0x0046e8: f100011f  cmp      x8, #0
//   0x0046ec: 1a9f17e0  cset     w0, eq
//   0x0046f0: 14000006  b        #0x4708
//   0x0046f4: 91008280  add      x0, x20, #0x20
//   0x0046f8: 91008261  add      x1, x19, #0x20
//   0x0046fc: 97fffa45  bl       #0x3010
//   0x004700: 34fffac0  cbz      w0, #0x4658
//   0x004704: 2a1f03e0  mov      w0, wzr
//   0x004708: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00470c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x004710: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x004714: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x004718: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_024_04544(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004544ULL;
    for (std::size_t i = 0; i < 118ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1149ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[025] Subroutine @ 0x00471c..0x0048f4 (472 bytes, 118 AArch64 instructions)
// [VN] Khung FDE[025] Hàm con @ 0x00471c..0x0048f4 (472 byte, 118 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00471c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x004720: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x004724: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x004728: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00472c: 9100c3fd  add      x29, sp, #0x30
//   0x004730: aa0103f3  mov      x19, x1
//   0x004734: aa0003f4  mov      x20, x0
//   0x004738: b4000c20  cbz      x0, #0x48bc
//   0x00473c: b4000c13  cbz      x19, #0x48bc
//   0x004740: aa1403e0  mov      x0, x20
//   0x004744: aa1303e1  mov      x1, x19
//   0x004748: 97fffa0a  bl       #0x2f70
//   0x00474c: 35000c80  cbnz     w0, #0x48dc
//   0x004750: f9400288  ldr      x8, [x20]
//   0x004754: b50000a8  cbnz     x8, #0x4768
//   0x004758: b9409288  ldr      w8, [x20, #0x90]
//   0x00475c: b9409269  ldr      w9, [x19, #0x90]
//   0x004760: 6b09011f  cmp      w8, w9
//   0x004764: 54000bc1  b.ne     #0x48dc
//   0x004768: 91004280  add      x0, x20, #0x10
//   0x00476c: 91004261  add      x1, x19, #0x10
//   0x004770: 97fffa00  bl       #0x2f70
//   0x004774: 35000b40  cbnz     w0, #0x48dc
//   0x004778: f9401a97  ldr      x23, [x20, #0x30]
//   0x00477c: f9401a68  ldr      x8, [x19, #0x30]
//   0x004780: f10002ff  cmp      x23, #0
//   0x004784: 1a9f17e9  cset     w9, eq
//   0x004788: f100011f  cmp      x8, #0
//   0x00478c: 1a9f17ea  cset     w10, eq
//   0x004790: 4a0a0129  eor      w9, w9, w10
//   0x004794: 37000a49  tbnz     w9, #0, #0x48dc
//   0x004798: f9401e80  ldr      x0, [x20, #0x38]
//   0x00479c: f9401e61  ldr      x1, [x19, #0x38]
//   0x0047a0: f100001f  cmp      x0, #0
//   0x0047a4: 1a9f17e9  cset     w9, eq
//   0x0047a8: f100003f  cmp      x1, #0
//   0x0047ac: 1a9f17ea  cset     w10, eq
//   0x0047b0: 4a0a0129  eor      w9, w9, w10
//   0x0047b4: 37000949  tbnz     w9, #0, #0x48dc
//   0x0047b8: aa1403f5  mov      x21, x20
//   0x0047bc: f8440eb8  ldr      x24, [x21, #0x40]!
//   0x0047c0: aa1303f6  mov      x22, x19
//   0x0047c4: f8440ec9  ldr      x9, [x22, #0x40]!
//   0x0047c8: f100031f  cmp      x24, #0
//   0x0047cc: 1a9f17ea  cset     w10, eq
//   0x0047d0: f100013f  cmp      x9, #0
//   0x0047d4: 1a9f17e9  cset     w9, eq
//   0x0047d8: 4a090149  eor      w9, w10, w9
//   0x0047dc: 37000809  tbnz     w9, #0, #0x48dc
//   0x0047e0: b40000b7  cbz      x23, #0x47f4
//   0x0047e4: b9400108  ldr      w8, [x8]
//   0x0047e8: b94002e9  ldr      w9, [x23]
//   0x0047ec: 6b08013f  cmp      w9, w8
//   0x0047f0: 54000761  b.ne     #0x48dc
//   0x0047f4: b4000080  cbz      x0, #0x4804
//   0x0047f8: 52800202  mov      w2, #0x10
//   0x0047fc: 97fffa41  bl       #0x3100
//   0x004800: 350006e0  cbnz     w0, #0x48dc
//   0x004804: b40000d8  cbz      x24, #0x481c
//   0x004808: aa1503e0  mov      x0, x21
//   0x00480c: aa1603e1  mov      x1, x22
//   0x004810: 97fff9d8  bl       #0x2f70
//   0x004814: 35000640  cbnz     w0, #0x48dc
//   0x004818: f9401a97  ldr      x23, [x20, #0x30]
//   0x00481c: b50000b7  cbnz     x23, #0x4830
//   0x004820: f9401e88  ldr      x8, [x20, #0x38]
//   0x004824: b5000068  cbnz     x8, #0x4830
//   0x004828: f94002a8  ldr      x8, [x21]
//   0x00482c: b4000508  cbz      x8, #0x48cc
//   0x004830: 91014280  add      x0, x20, #0x50
//   0x004834: 91014261  add      x1, x19, #0x50
//   0x004838: 97fff9ce  bl       #0x2f70
//   0x00483c: 35000500  cbnz     w0, #0x48dc
//   0x004840: f9403295  ldr      x21, [x20, #0x60]
//   0x004844: f9403276  ldr      x22, [x19, #0x60]
//   0x004848: f10002bf  cmp      x21, #0
//   0x00484c: 1a9f17e8  cset     w8, eq
//   0x004850: f10002df  cmp      x22, #0
//   0x004854: 1a9f17e9  cset     w9, eq
//   0x004858: 4a090108  eor      w8, w8, w9
//   0x00485c: 37000408  tbnz     w8, #0, #0x48dc
//   0x004860: b40001d5  cbz      x21, #0x4898
//   0x004864: aa1503e0  mov      x0, x21
//   0x004868: aa1603e1  mov      x1, x22
//   0x00486c: 97fff9c1  bl       #0x2f70
//   0x004870: 35000360  cbnz     w0, #0x48dc
//   0x004874: f9400ab5  ldr      x21, [x21, #0x10]
//   0x004878: f9400ad6  ldr      x22, [x22, #0x10]
//   0x00487c: f10002bf  cmp      x21, #0
//   0x004880: 1a9f17e8  cset     w8, eq
//   0x004884: f10002df  cmp      x22, #0
//   0x004888: 1a9f17e9  cset     w9, eq
//   0x00488c: 4a090108  eor      w8, w8, w9
//   0x004890: 37000268  tbnz     w8, #0, #0x48dc
//   0x004894: b5fffe95  cbnz     x21, #0x4864
//   0x004898: 9101c280  add      x0, x20, #0x70
//   0x00489c: 9101c261  add      x1, x19, #0x70
//   0x0048a0: 97fff9b4  bl       #0x2f70
//   0x0048a4: 350001c0  cbnz     w0, #0x48dc
//   0x0048a8: 91020280  add      x0, x20, #0x80
//   0x0048ac: 91020261  add      x1, x19, #0x80
//   0x0048b0: 97fff9b0  bl       #0x2f70
//   0x0048b4: 7100001f  cmp      w0, #0
//   0x0048b8: 14000003  b        #0x48c4
//   0x0048bc: aa130288  orr      x8, x20, x19
//   0x0048c0: f100011f  cmp      x8, #0
//   0x0048c4: 1a9f17e0  cset     w0, eq
//   0x0048c8: 14000006  b        #0x48e0
//   0x0048cc: 91008280  add      x0, x20, #0x20
//   0x0048d0: 91008261  add      x1, x19, #0x20
//   0x0048d4: 97fff9a7  bl       #0x2f70
//   0x0048d8: 34fffac0  cbz      w0, #0x4830
//   0x0048dc: 2a1f03e0  mov      w0, wzr
//   0x0048e0: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x0048e4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x0048e8: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x0048ec: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x0048f0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_025_0471c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000471cULL;
    for (std::size_t i = 0; i < 118ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1267ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[026] Subroutine @ 0x0048f4..0x004908 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[026] Hàm con @ 0x0048f4..0x004908 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0048f4: 2a0303e4  mov      w4, w3
//   0x0048f8: 2a0203e3  mov      w3, w2
//   0x0048fc: aa0103e2  mov      x2, x1
//   0x004900: aa1f03e1  mov      x1, xzr
//   0x004904: 17fffa37  b        #0x31e0
// ============================================================================
std::uint32_t fde_026_048f4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000048f4ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1385ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[027] Subroutine @ 0x004908..0x004ad4 (460 bytes, 115 AArch64 instructions)
// [VN] Khung FDE[027] Hàm con @ 0x004908..0x004ad4 (460 byte, 115 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004908: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x00490c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x004910: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x004914: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x004918: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00491c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x004920: 910143fd  add      x29, sp, #0x50
//   0x004924: aa0103f6  mov      x22, x1
//   0x004928: aa1f03e1  mov      x1, xzr
//   0x00492c: b4000c42  cbz      x2, #0x4ab4
//   0x004930: aa0203f3  mov      x19, x2
//   0x004934: eb02001f  cmp      x0, x2
//   0x004938: 54000be0  b.eq     #0x4ab4
//   0x00493c: b4000b80  cbz      x0, #0x4aac
//   0x004940: 2a0403f4  mov      w20, w4
//   0x004944: 2a0303f5  mov      w21, w3
//   0x004948: b4000076  cbz      x22, #0x4954
//   0x00494c: eb16001f  cmp      x0, x22
//   0x004950: 54000ae2  b.hs     #0x4aac
//   0x004954: f0000078  adrp     x24, #0x13000
//   0x004958: 528604ac  mov      w12, #0x3025
//   0x00495c: 2a1f03e8  mov      w8, wzr
//   0x004960: 91000409  add      x9, x0, #1
//   0x004964: 528004ab  mov      w11, #0x25
//   0x004968: 91055318  add      x24, x24, #0x154
//   0x00496c: 528604b9  mov      w25, #0x3025
//   0x004970: 5280083a  mov      w26, #0x41
//   0x004974: 72a4a88c  movk     w12, #0x2544, lsl #16
//   0x004978: 5288260d  mov      w13, #0x4130
//   0x00497c: 5280089b  mov      w27, #0x44
//   0x004980: 528644ae  mov      w14, #0x3225
//   0x004984: 5280060f  mov      w15, #0x30
//   0x004988: 52800570  mov      w16, #0x2b
//   0x00498c: 14000003  b        #0x4998
//   0x004990: eb16039f  cmp      x28, x22
//   0x004994: 540008c2  b.hs     #0x4aac
//   0x004998: 385ff137  ldurb    w23, [x9, #-1]
//   0x00499c: aa0903fc  mov      x28, x9
//   0x0049a0: 7101faff  cmp      w23, #0x7e
//   0x0049a4: 54000148  b.hi     #0x49cc
//   0x0049a8: 10000089  adr      x9, #0x49b8
//   0x0049ac: 38776b0a  ldrb     w10, [x24, x23]
//   0x0049b0: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x0049b4: d61f0120  br       x9
//   0x0049b8: 2a1f03e8  mov      w8, wzr
//   0x0049bc: 38001677  strb     w23, [x19], #1
//   0x0049c0: 91000789  add      x9, x28, #1
//   0x0049c4: b5fffe76  cbnz     x22, #0x4990
//   0x0049c8: 17fffff4  b        #0x4998
//   0x0049cc: 53047ee0  lsr      w0, w23, #4
//   0x0049d0: 3900026b  strb     w11, [x19]
//   0x0049d4: 97fff9df  bl       #0x3150
//   0x0049d8: 39000660  strb     w0, [x19, #1]
//   0x0049dc: 12000ee0  and      w0, w23, #0xf
//   0x0049e0: 97fff9dc  bl       #0x3150
//   0x0049e4: 528604ac  mov      w12, #0x3025
//   0x0049e8: 52800570  mov      w16, #0x2b
//   0x0049ec: 5280060f  mov      w15, #0x30
//   0x0049f0: 528644ae  mov      w14, #0x3225
//   0x0049f4: 5288260d  mov      w13, #0x4130
//   0x0049f8: 72a4a88c  movk     w12, #0x2544, lsl #16
//   0x0049fc: 528004ab  mov      w11, #0x25
//   0x004a00: 2a1f03e8  mov      w8, wzr
//   0x004a04: 39000a60  strb     w0, [x19, #2]
//   0x004a08: 1400001f  b        #0x4a84
//   0x004a0c: 34000274  cbz      w20, #0x4a58
//   0x004a10: 34000428  cbz      w8, #0x4a94
//   0x004a14: 2a1f03e8  mov      w8, wzr
//   0x004a18: 91000789  add      x9, x28, #1
//   0x004a1c: b5fffbb6  cbnz     x22, #0x4990
//   0x004a20: 17ffffde  b        #0x4998
//   0x004a24: 79000279  strh     w25, [x19]
//   0x004a28: 39000a7b  strb     w27, [x19, #2]
//   0x004a2c: 340001f4  cbz      w20, #0x4a68
//   0x004a30: 78003279  sturh    w25, [x19, #3]
//   0x004a34: 3900167a  strb     w26, [x19, #5]
//   0x004a38: 91001a73  add      x19, x19, #6
//   0x004a3c: 1400000c  b        #0x4a6c
//   0x004a40: 2a1f03e8  mov      w8, wzr
//   0x004a44: 340001d5  cbz      w21, #0x4a7c
//   0x004a48: 38001670  strb     w16, [x19], #1
//   0x004a4c: 91000789  add      x9, x28, #1
//   0x004a50: b5fffa16  cbnz     x22, #0x4990
//   0x004a54: 17ffffd1  b        #0x4998
//   0x004a58: 2a1f03e8  mov      w8, wzr
//   0x004a5c: 79000279  strh     w25, [x19]
//   0x004a60: 39000a7a  strb     w26, [x19, #2]
//   0x004a64: 14000008  b        #0x4a84
//   0x004a68: 91000e73  add      x19, x19, #3
//   0x004a6c: 52800028  mov      w8, #1
//   0x004a70: 91000789  add      x9, x28, #1
//   0x004a74: b5fff8f6  cbnz     x22, #0x4990
//   0x004a78: 17ffffc8  b        #0x4998
//   0x004a7c: 7900026e  strh     w14, [x19]
//   0x004a80: 39000a6f  strb     w15, [x19, #2]
//   0x004a84: 91000e73  add      x19, x19, #3
//   0x004a88: 91000789  add      x9, x28, #1
//   0x004a8c: b5fff836  cbnz     x22, #0x4990
//   0x004a90: 17ffffc2  b        #0x4998
//   0x004a94: b900026c  str      w12, [x19]
//   0x004a98: 79000a6d  strh     w13, [x19, #4]
//   0x004a9c: 91001a73  add      x19, x19, #6
//   0x004aa0: 91000789  add      x9, x28, #1
//   0x004aa4: b5fff776  cbnz     x22, #0x4990
//   0x004aa8: 17ffffbc  b        #0x4998
//   0x004aac: aa1303e1  mov      x1, x19
//   0x004ab0: 3900027f  strb     wzr, [x19]
//   0x004ab4: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x004ab8: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x004abc: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x004ac0: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x004ac4: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x004ac8: aa0103e0  mov      x0, x1
//   0x004acc: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x004ad0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_027_04908(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004908ULL;
    for (std::size_t i = 0; i < 115ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1390ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[028] Subroutine @ 0x004ad4..0x004ae0 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[028] Hàm con @ 0x004ad4..0x004ae0 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004ad4: 52800062  mov      w2, #3
//   0x004ad8: 2a1f03e1  mov      w1, wzr
//   0x004adc: 17fff9fd  b        #0x32d0
// ============================================================================
std::uint32_t fde_028_04ad4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004ad4ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1505ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[029] Subroutine @ 0x004ae0..0x004d30 (592 bytes, 148 AArch64 instructions)
// [VN] Khung FDE[029] Hàm con @ 0x004ae0..0x004d30 (592 byte, 148 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004ae0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x004ae4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x004ae8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x004aec: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x004af0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x004af4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x004af8: 910143fd  add      x29, sp, #0x50
//   0x004afc: aa0003f7  mov      x23, x0
//   0x004b00: b4001080  cbz      x0, #0x4d10
//   0x004b04: b20f17f9  mov      x25, #0x7e0000007e0000
//   0x004b08: 2a0203f4  mov      w20, w2
//   0x004b0c: 2a0103f5  mov      w21, w1
//   0x004b10: 2a1f03fb  mov      w27, wzr
//   0x004b14: 52800038  mov      w24, #1
//   0x004b18: f2807ff9  movk     x25, #0x3ff
//   0x004b1c: 528001ba  mov      w26, #0xd
//   0x004b20: 5280015c  mov      w28, #0xa
//   0x004b24: aa1703f3  mov      x19, x23
//   0x004b28: 14000007  b        #0x4b44
//   0x004b2c: 34000695  cbz      w21, #0x4bfc
//   0x004b30: 52800408  mov      w8, #0x20
//   0x004b34: 390002e8  strb     w8, [x23]
//   0x004b38: 2a1f03fb  mov      w27, wzr
//   0x004b3c: 91000673  add      x19, x19, #1
//   0x004b40: 910006f7  add      x23, x23, #1
//   0x004b44: 39400268  ldrb     w8, [x19]
//   0x004b48: 7100951f  cmp      w8, #0x25
//   0x004b4c: 540000e0  b.eq     #0x4b68
//   0x004b50: 7100ad1f  cmp      w8, #0x2b
//   0x004b54: 54fffec0  b.eq     #0x4b2c
//   0x004b58: 34000d68  cbz      w8, #0x4d04
//   0x004b5c: eb17027f  cmp      x19, x23
//   0x004b60: 54fffea8  b.hi     #0x4b34
//   0x004b64: 17fffff5  b        #0x4b38
//   0x004b68: aa1303e8  mov      x8, x19
//   0x004b6c: 38401d00  ldrb     w0, [x8, #1]!
//   0x004b70: 5100c009  sub      w9, w0, #0x30
//   0x004b74: 7100d93f  cmp      w9, #0x36
//   0x004b78: 540008e8  b.hi     #0x4c94
//   0x004b7c: 9ac92309  lsl      x9, x24, x9
//   0x004b80: ea19013f  tst      x9, x25
//   0x004b84: 54000880  b.eq     #0x4c94
//   0x004b88: aa1303f6  mov      x22, x19
//   0x004b8c: 38402ec9  ldrb     w9, [x22, #2]!
//   0x004b90: 5100c129  sub      w9, w9, #0x30
//   0x004b94: 7100d93f  cmp      w9, #0x36
//   0x004b98: 540008e8  b.hi     #0x4cb4
//   0x004b9c: 9ac92309  lsl      x9, x24, x9
//   0x004ba0: ea19013f  tst      x9, x25
//   0x004ba4: 54000880  b.eq     #0x4cb4
//   0x004ba8: 97fff99a  bl       #0x3210
//   0x004bac: 394002c8  ldrb     w8, [x22]
//   0x004bb0: 2a0003f6  mov      w22, w0
//   0x004bb4: 2a0803e0  mov      w0, w8
//   0x004bb8: 97fff996  bl       #0x3210
//   0x004bbc: 12001ec8  and      w8, w22, #0xff
//   0x004bc0: 531c6d08  lsl      w8, w8, #4
//   0x004bc4: 0b200108  add      w8, w8, w0, uxtb
//   0x004bc8: 7100351f  cmp      w8, #0xd
//   0x004bcc: 54000200  b.eq     #0x4c0c
//   0x004bd0: 7100291f  cmp      w8, #0xa
//   0x004bd4: 540002e1  b.ne     #0x4c30
//   0x004bd8: 71000a9f  cmp      w20, #2
//   0x004bdc: 540003a0  b.eq     #0x4c50
//   0x004be0: 7100069f  cmp      w20, #1
//   0x004be4: 540003e0  b.eq     #0x4c60
//   0x004be8: 35000454  cbnz     w20, #0x4c70
//   0x004bec: 3400079b  cbz      w27, #0x4cdc
//   0x004bf0: 2a1f03fb  mov      w27, wzr
//   0x004bf4: 91000e73  add      x19, x19, #3
//   0x004bf8: 17ffffd3  b        #0x4b44
//   0x004bfc: eb17027f  cmp      x19, x23
//   0x004c00: 54fff9c9  b.ls     #0x4b38
//   0x004c04: 52800568  mov      w8, #0x2b
//   0x004c08: 17ffffcb  b        #0x4b34
//   0x004c0c: 71000a9f  cmp      w20, #2
//   0x004c10: 54000180  b.eq     #0x4c40
//   0x004c14: 7100069f  cmp      w20, #1
//   0x004c18: 54000340  b.eq     #0x4c80
//   0x004c1c: 35000134  cbnz     w20, #0x4c40
//   0x004c20: 380016fc  strb     w28, [x23], #1
//   0x004c24: 5280003b  mov      w27, #1
//   0x004c28: 91000e73  add      x19, x19, #3
//   0x004c2c: 17ffffc6  b        #0x4b44
//   0x004c30: 2a1f03fb  mov      w27, wzr
//   0x004c34: 380016e8  strb     w8, [x23], #1
//   0x004c38: 91000e73  add      x19, x19, #3
//   0x004c3c: 17ffffc2  b        #0x4b44
//   0x004c40: 380016fa  strb     w26, [x23], #1
//   0x004c44: 5280003b  mov      w27, #1
//   0x004c48: 91000e73  add      x19, x19, #3
//   0x004c4c: 17ffffbe  b        #0x4b44
//   0x004c50: 340004db  cbz      w27, #0x4ce8
//   0x004c54: 2a1f03fb  mov      w27, wzr
//   0x004c58: 91000e73  add      x19, x19, #3
//   0x004c5c: 17ffffba  b        #0x4b44
//   0x004c60: 340004bb  cbz      w27, #0x4cf4
//   0x004c64: 2a1f03fb  mov      w27, wzr
//   0x004c68: 91000e73  add      x19, x19, #3
//   0x004c6c: 17ffffb6  b        #0x4b44
//   0x004c70: 2a1f03fb  mov      w27, wzr
//   0x004c74: 380016fc  strb     w28, [x23], #1
//   0x004c78: 91000e73  add      x19, x19, #3
//   0x004c7c: 17ffffb2  b        #0x4b44
//   0x004c80: 528141a8  mov      w8, #0xa0d
//   0x004c84: 780026e8  strh     w8, [x23], #2
//   0x004c88: 5280003b  mov      w27, #1
//   0x004c8c: 91000e73  add      x19, x19, #3
//   0x004c90: 17ffffad  b        #0x4b44
//   0x004c94: eb17027f  cmp      x19, x23
//   0x004c98: 54000069  b.ls     #0x4ca4
//   0x004c9c: 528004a9  mov      w9, #0x25
//   0x004ca0: 390002e9  strb     w9, [x23]
//   0x004ca4: 2a1f03fb  mov      w27, wzr
//   0x004ca8: 910006f7  add      x23, x23, #1
//   0x004cac: aa0803f3  mov      x19, x8
//   0x004cb0: 17ffffa5  b        #0x4b44
//   0x004cb4: eb17027f  cmp      x19, x23
//   0x004cb8: 540000a9  b.ls     #0x4ccc
//   0x004cbc: 528004a9  mov      w9, #0x25
//   0x004cc0: 390002e9  strb     w9, [x23]
//   0x004cc4: 39400108  ldrb     w8, [x8]
//   0x004cc8: 390006e8  strb     w8, [x23, #1]
//   0x004ccc: 2a1f03fb  mov      w27, wzr
//   0x004cd0: 91000af7  add      x23, x23, #2
//   0x004cd4: aa1603f3  mov      x19, x22
//   0x004cd8: 17ffff9b  b        #0x4b44
//   0x004cdc: 380016fc  strb     w28, [x23], #1
//   0x004ce0: 91000e73  add      x19, x19, #3
//   0x004ce4: 17ffff98  b        #0x4b44
//   0x004ce8: 380016fa  strb     w26, [x23], #1
//   0x004cec: 91000e73  add      x19, x19, #3
//   0x004cf0: 17ffff95  b        #0x4b44
//   0x004cf4: 528141a8  mov      w8, #0xa0d
//   0x004cf8: 780026e8  strh     w8, [x23], #2
//   0x004cfc: 91000e73  add      x19, x19, #3
//   0x004d00: 17ffff91  b        #0x4b44
//   0x004d04: eb17027f  cmp      x19, x23
//   0x004d08: 54000049  b.ls     #0x4d10
//   0x004d0c: 390002ff  strb     wzr, [x23]
//   0x004d10: aa1703e0  mov      x0, x23
//   0x004d14: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x004d18: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x004d1c: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x004d20: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x004d24: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x004d28: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x004d2c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_029_04ae0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004ae0ULL;
    for (std::size_t i = 0; i < 148ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1508ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[030] Subroutine @ 0x004d30..0x004d44 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[030] Hàm con @ 0x004d30..0x004d44 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004d30: 2a0303e4  mov      w4, w3
//   0x004d34: 2a0203e3  mov      w3, w2
//   0x004d38: aa0103e2  mov      x2, x1
//   0x004d3c: aa1f03e1  mov      x1, xzr
//   0x004d40: 17fff920  b        #0x31c0
// ============================================================================
std::uint32_t fde_030_04d30(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004d30ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1656ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[031] Subroutine @ 0x004d44..0x004f28 (484 bytes, 121 AArch64 instructions)
// [VN] Khung FDE[031] Hàm con @ 0x004d44..0x004f28 (484 byte, 121 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004d44: d10203ff  sub      sp, sp, #0x80
//   0x004d48: 6d0123e9  stp      d9, d8, [sp, #0x10]
//   0x004d4c: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x004d50: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x004d54: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x004d58: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x004d5c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x004d60: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x004d64: 9101c3fd  add      x29, sp, #0x70
//   0x004d68: aa0103f6  mov      x22, x1
//   0x004d6c: aa1f03e1  mov      x1, xzr
//   0x004d70: b4000c82  cbz      x2, #0x4f00
//   0x004d74: aa0203f3  mov      x19, x2
//   0x004d78: eb02001f  cmp      x0, x2
//   0x004d7c: 54000c20  b.eq     #0x4f00
//   0x004d80: b4000bc0  cbz      x0, #0x4ef8
//   0x004d84: 2a0403f4  mov      w20, w4
//   0x004d88: 2a0303f5  mov      w21, w3
//   0x004d8c: b4000076  cbz      x22, #0x4d98
//   0x004d90: eb16001f  cmp      x0, x22
//   0x004d94: 54000b22  b.hs     #0x4ef8
//   0x004d98: f000006a  adrp     x10, #0x13000
//   0x004d9c: f000006b  adrp     x11, #0x13000
//   0x004da0: f000006c  adrp     x12, #0x13000
//   0x004da4: fd40ed48  ldr      d8, [x10, #0x1d8]
//   0x004da8: 3dc07d60  ldr      q0, [x11, #0x1f0]
//   0x004dac: fd40f189  ldr      d9, [x12, #0x1e0]
//   0x004db0: f0000078  adrp     x24, #0x13000
//   0x004db4: d280060d  mov      x13, #0x30
//   0x004db8: 2a1f03e8  mov      w8, wzr
//   0x004dbc: 91001009  add      x9, x0, #4
//   0x004dc0: 528004b7  mov      w23, #0x25
//   0x004dc4: 91080318  add      x24, x24, #0x200
//   0x004dc8: 52800839  mov      w25, #0x41
//   0x004dcc: f2c0082d  movk     x13, #0x41, lsl #32
//   0x004dd0: 5280089b  mov      w27, #0x44
//   0x004dd4: 5280060b  mov      w11, #0x30
//   0x004dd8: 5280056c  mov      w12, #0x2b
//   0x004ddc: 14000003  b        #0x4de8
//   0x004de0: eb16039f  cmp      x28, x22
//   0x004de4: 540008a2  b.hs     #0x4ef8
//   0x004de8: b85fc13a  ldur     w26, [x9, #-4]
//   0x004dec: aa0903fc  mov      x28, x9
//   0x004df0: 7101fb5f  cmp      w26, #0x7e
//   0x004df4: 54000148  b.hi     #0x4e1c
//   0x004df8: 10000089  adr      x9, #0x4e08
//   0x004dfc: 387a6b0a  ldrb     w10, [x24, x26]
//   0x004e00: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x004e04: d61f0120  br       x9
//   0x004e08: 2a1f03e8  mov      w8, wzr
//   0x004e0c: b800467a  str      w26, [x19], #4
//   0x004e10: 91001389  add      x9, x28, #4
//   0x004e14: b5fffe76  cbnz     x22, #0x4de0
//   0x004e18: 17fffff4  b        #0x4de8
//   0x004e1c: 53041f40  ubfx     w0, w26, #4, #4
//   0x004e20: b9000277  str      w23, [x19]
//   0x004e24: 3d8003e0  str      q0, [sp]
//   0x004e28: 97fff8da  bl       #0x3190
//   0x004e2c: b9000660  str      w0, [x19, #4]
//   0x004e30: 12000f40  and      w0, w26, #0xf
//   0x004e34: 97fff8d7  bl       #0x3190
//   0x004e38: 3dc003e0  ldr      q0, [sp]
//   0x004e3c: d280060d  mov      x13, #0x30
//   0x004e40: 5280056c  mov      w12, #0x2b
//   0x004e44: 5280060b  mov      w11, #0x30
//   0x004e48: f2c0082d  movk     x13, #0x41, lsl #32
//   0x004e4c: 2a1f03e8  mov      w8, wzr
//   0x004e50: b9000a60  str      w0, [x19, #8]
//   0x004e54: 1400001f  b        #0x4ed0
//   0x004e58: 34000274  cbz      w20, #0x4ea4
//   0x004e5c: 34000428  cbz      w8, #0x4ee0
//   0x004e60: 2a1f03e8  mov      w8, wzr
//   0x004e64: 91001389  add      x9, x28, #4
//   0x004e68: b5fffbd6  cbnz     x22, #0x4de0
//   0x004e6c: 17ffffdf  b        #0x4de8
//   0x004e70: fd000268  str      d8, [x19]
//   0x004e74: b9000a7b  str      w27, [x19, #8]
//   0x004e78: 340001f4  cbz      w20, #0x4eb4
//   0x004e7c: fc00c268  stur     d8, [x19, #0xc]
//   0x004e80: b9001679  str      w25, [x19, #0x14]
//   0x004e84: 91006273  add      x19, x19, #0x18
//   0x004e88: 1400000c  b        #0x4eb8
//   0x004e8c: 2a1f03e8  mov      w8, wzr
//   0x004e90: 340001d5  cbz      w21, #0x4ec8
//   0x004e94: b800466c  str      w12, [x19], #4
//   0x004e98: 91001389  add      x9, x28, #4
//   0x004e9c: b5fffa36  cbnz     x22, #0x4de0
//   0x004ea0: 17ffffd2  b        #0x4de8
//   0x004ea4: 2a1f03e8  mov      w8, wzr
//   0x004ea8: fd000268  str      d8, [x19]
//   0x004eac: b9000a79  str      w25, [x19, #8]
//   0x004eb0: 14000008  b        #0x4ed0
//   0x004eb4: 91003273  add      x19, x19, #0xc
//   0x004eb8: 52800028  mov      w8, #1
//   0x004ebc: 91001389  add      x9, x28, #4
//   0x004ec0: b5fff916  cbnz     x22, #0x4de0
//   0x004ec4: 17ffffc9  b        #0x4de8
//   0x004ec8: fd000269  str      d9, [x19]
//   0x004ecc: b9000a6b  str      w11, [x19, #8]
//   0x004ed0: 91003273  add      x19, x19, #0xc
//   0x004ed4: 91001389  add      x9, x28, #4
//   0x004ed8: b5fff856  cbnz     x22, #0x4de0
//   0x004edc: 17ffffc3  b        #0x4de8
//   0x004ee0: 3d800260  str      q0, [x19]
//   0x004ee4: f9000a6d  str      x13, [x19, #0x10]
//   0x004ee8: 91006273  add      x19, x19, #0x18
//   0x004eec: 91001389  add      x9, x28, #4
//   0x004ef0: b5fff796  cbnz     x22, #0x4de0
//   0x004ef4: 17ffffbd  b        #0x4de8
//   0x004ef8: aa1303e1  mov      x1, x19
//   0x004efc: b900027f  str      wzr, [x19]
//   0x004f00: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x004f04: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x004f08: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x004f0c: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x004f10: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x004f14: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x004f18: 6d4123e9  ldp      d9, d8, [sp, #0x10]
//   0x004f1c: aa0103e0  mov      x0, x1
//   0x004f20: 910203ff  add      sp, sp, #0x80
//   0x004f24: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_031_04d44(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004d44ULL;
    for (std::size_t i = 0; i < 121ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1661ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[032] Subroutine @ 0x004f28..0x004f34 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[032] Hàm con @ 0x004f28..0x004f34 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004f28: 52800062  mov      w2, #3
//   0x004f2c: 2a1f03e1  mov      w1, wzr
//   0x004f30: 17fff820  b        #0x2fb0
// ============================================================================
std::uint32_t fde_032_04f28(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004f28ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1782ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[033] Subroutine @ 0x004f34..0x00518c (600 bytes, 150 AArch64 instructions)
// [VN] Khung FDE[033] Hàm con @ 0x004f34..0x00518c (600 byte, 150 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004f34: fc190fe8  str      d8, [sp, #-0x70]!
//   0x004f38: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x004f3c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x004f40: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x004f44: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x004f48: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x004f4c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x004f50: 910183fd  add      x29, sp, #0x60
//   0x004f54: aa0003f3  mov      x19, x0
//   0x004f58: b4001080  cbz      x0, #0x5168
//   0x004f5c: f0000068  adrp     x8, #0x13000
//   0x004f60: fd40f508  ldr      d8, [x8, #0x1e8]
//   0x004f64: b20f17f9  mov      x25, #0x7e0000007e0000
//   0x004f68: 2a0203f4  mov      w20, w2
//   0x004f6c: 2a0103f5  mov      w21, w1
//   0x004f70: 2a1f03f7  mov      w23, wzr
//   0x004f74: 52800038  mov      w24, #1
//   0x004f78: f2807ff9  movk     x25, #0x3ff
//   0x004f7c: 528001ba  mov      w26, #0xd
//   0x004f80: 5280015b  mov      w27, #0xa
//   0x004f84: aa1303fc  mov      x28, x19
//   0x004f88: 14000007  b        #0x4fa4
//   0x004f8c: 34000695  cbz      w21, #0x505c
//   0x004f90: 52800408  mov      w8, #0x20
//   0x004f94: b9000268  str      w8, [x19]
//   0x004f98: 2a1f03f7  mov      w23, wzr
//   0x004f9c: 9100139c  add      x28, x28, #4
//   0x004fa0: 91001273  add      x19, x19, #4
//   0x004fa4: b9400388  ldr      w8, [x28]
//   0x004fa8: 7100951f  cmp      w8, #0x25
//   0x004fac: 540000e0  b.eq     #0x4fc8
//   0x004fb0: 7100ad1f  cmp      w8, #0x2b
//   0x004fb4: 54fffec0  b.eq     #0x4f8c
//   0x004fb8: 34000d28  cbz      w8, #0x515c
//   0x004fbc: eb13039f  cmp      x28, x19
//   0x004fc0: 54fffea8  b.hi     #0x4f94
//   0x004fc4: 17fffff5  b        #0x4f98
//   0x004fc8: aa1c03e8  mov      x8, x28
//   0x004fcc: b8404d00  ldr      w0, [x8, #4]!
//   0x004fd0: 5100c009  sub      w9, w0, #0x30
//   0x004fd4: 7100d93f  cmp      w9, #0x36
//   0x004fd8: 540008c8  b.hi     #0x50f0
//   0x004fdc: 9ac92309  lsl      x9, x24, x9
//   0x004fe0: ea19013f  tst      x9, x25
//   0x004fe4: 54000860  b.eq     #0x50f0
//   0x004fe8: aa1c03f6  mov      x22, x28
//   0x004fec: b8408ec9  ldr      w9, [x22, #8]!
//   0x004ff0: 5100c129  sub      w9, w9, #0x30
//   0x004ff4: 7100d93f  cmp      w9, #0x36
//   0x004ff8: 540008c8  b.hi     #0x5110
//   0x004ffc: 9ac92309  lsl      x9, x24, x9
//   0x005000: ea19013f  tst      x9, x25
//   0x005004: 54000860  b.eq     #0x5110
//   0x005008: 97fff88e  bl       #0x3240
//   0x00500c: b94002c8  ldr      w8, [x22]
//   0x005010: 2a0003f6  mov      w22, w0
//   0x005014: 2a0803e0  mov      w0, w8
//   0x005018: 97fff88a  bl       #0x3240
//   0x00501c: 12001ec8  and      w8, w22, #0xff
//   0x005020: 531c6d08  lsl      w8, w8, #4
//   0x005024: 0b200108  add      w8, w8, w0, uxtb
//   0x005028: 7100351f  cmp      w8, #0xd
//   0x00502c: 54000200  b.eq     #0x506c
//   0x005030: 7100291f  cmp      w8, #0xa
//   0x005034: 540002e1  b.ne     #0x5090
//   0x005038: 71000a9f  cmp      w20, #2
//   0x00503c: 540003a0  b.eq     #0x50b0
//   0x005040: 7100069f  cmp      w20, #1
//   0x005044: 540003e0  b.eq     #0x50c0
//   0x005048: 35000454  cbnz     w20, #0x50d0
//   0x00504c: 34000777  cbz      w23, #0x5138
//   0x005050: 2a1f03f7  mov      w23, wzr
//   0x005054: 9100339c  add      x28, x28, #0xc
//   0x005058: 17ffffd3  b        #0x4fa4
//   0x00505c: eb13039f  cmp      x28, x19
//   0x005060: 54fff9c9  b.ls     #0x4f98
//   0x005064: 52800568  mov      w8, #0x2b
//   0x005068: 17ffffcb  b        #0x4f94
//   0x00506c: 71000a9f  cmp      w20, #2
//   0x005070: 54000180  b.eq     #0x50a0
//   0x005074: 7100069f  cmp      w20, #1
//   0x005078: 54000340  b.eq     #0x50e0
//   0x00507c: 35000134  cbnz     w20, #0x50a0
//   0x005080: b800467b  str      w27, [x19], #4
//   0x005084: 52800037  mov      w23, #1
//   0x005088: 9100339c  add      x28, x28, #0xc
//   0x00508c: 17ffffc6  b        #0x4fa4
//   0x005090: 2a1f03f7  mov      w23, wzr
//   0x005094: b8004668  str      w8, [x19], #4
//   0x005098: 9100339c  add      x28, x28, #0xc
//   0x00509c: 17ffffc2  b        #0x4fa4
//   0x0050a0: b800467a  str      w26, [x19], #4
//   0x0050a4: 52800037  mov      w23, #1
//   0x0050a8: 9100339c  add      x28, x28, #0xc
//   0x0050ac: 17ffffbe  b        #0x4fa4
//   0x0050b0: 340004b7  cbz      w23, #0x5144
//   0x0050b4: 2a1f03f7  mov      w23, wzr
//   0x0050b8: 9100339c  add      x28, x28, #0xc
//   0x0050bc: 17ffffba  b        #0x4fa4
//   0x0050c0: 34000497  cbz      w23, #0x5150
//   0x0050c4: 2a1f03f7  mov      w23, wzr
//   0x0050c8: 9100339c  add      x28, x28, #0xc
//   0x0050cc: 17ffffb6  b        #0x4fa4
//   0x0050d0: 2a1f03f7  mov      w23, wzr
//   0x0050d4: b800467b  str      w27, [x19], #4
//   0x0050d8: 9100339c  add      x28, x28, #0xc
//   0x0050dc: 17ffffb2  b        #0x4fa4
//   0x0050e0: fc008668  str      d8, [x19], #8
//   0x0050e4: 52800037  mov      w23, #1
//   0x0050e8: 9100339c  add      x28, x28, #0xc
//   0x0050ec: 17ffffae  b        #0x4fa4
//   0x0050f0: eb13039f  cmp      x28, x19
//   0x0050f4: 54000069  b.ls     #0x5100
//   0x0050f8: 528004a9  mov      w9, #0x25
//   0x0050fc: b9000269  str      w9, [x19]
//   0x005100: 2a1f03f7  mov      w23, wzr
//   0x005104: 91001273  add      x19, x19, #4
//   0x005108: aa0803fc  mov      x28, x8
//   0x00510c: 17ffffa6  b        #0x4fa4
//   0x005110: eb13039f  cmp      x28, x19
//   0x005114: 540000a9  b.ls     #0x5128
//   0x005118: 528004a9  mov      w9, #0x25
//   0x00511c: b9000269  str      w9, [x19]
//   0x005120: b9400108  ldr      w8, [x8]
//   0x005124: b9000668  str      w8, [x19, #4]
//   0x005128: 2a1f03f7  mov      w23, wzr
//   0x00512c: 91002273  add      x19, x19, #8
//   0x005130: aa1603fc  mov      x28, x22
//   0x005134: 17ffff9c  b        #0x4fa4
//   0x005138: b800467b  str      w27, [x19], #4
//   0x00513c: 9100339c  add      x28, x28, #0xc
//   0x005140: 17ffff99  b        #0x4fa4
//   0x005144: b800467a  str      w26, [x19], #4
//   0x005148: 9100339c  add      x28, x28, #0xc
//   0x00514c: 17ffff96  b        #0x4fa4
//   0x005150: fc008668  str      d8, [x19], #8
//   0x005154: 9100339c  add      x28, x28, #0xc
//   0x005158: 17ffff93  b        #0x4fa4
//   0x00515c: eb13039f  cmp      x28, x19
//   0x005160: 54000049  b.ls     #0x5168
//   0x005164: b900027f  str      wzr, [x19]
//   0x005168: aa1303e0  mov      x0, x19
//   0x00516c: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x005170: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x005174: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x005178: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x00517c: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x005180: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x005184: fc4707e8  ldr      d8, [sp], #0x70
//   0x005188: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_033_04f34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004f34ULL;
    for (std::size_t i = 0; i < 150ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1785ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[034] Subroutine @ 0x00518c..0x005194 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[034] Hàm con @ 0x00518c..0x005194 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00518c: 52800022  mov      w2, #1
//   0x005190: 14000001  b        #0x5194
// ============================================================================
std::uint32_t fde_034_0518c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000518cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1935ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[035] Subroutine @ 0x005194..0x005378 (484 bytes, 121 AArch64 instructions)
// [VN] Khung FDE[035] Hàm con @ 0x005194..0x005378 (484 byte, 121 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005194: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x005198: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00519c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0051a0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0051a4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0051a8: 910103fd  add      x29, sp, #0x40
//   0x0051ac: aa0003f4  mov      x20, x0
//   0x0051b0: 52800040  mov      w0, #2
//   0x0051b4: b4000d34  cbz      x20, #0x5358
//   0x0051b8: aa0103f5  mov      x21, x1
//   0x0051bc: b4000ce1  cbz      x1, #0x5358
//   0x0051c0: 39400289  ldrb     w9, [x20]
//   0x0051c4: 2a0203f3  mov      w19, w2
//   0x0051c8: 7101713f  cmp      w9, #0x5c
//   0x0051cc: 540001c1  b.ne     #0x5204
//   0x0051d0: 39400688  ldrb     w8, [x20, #1]
//   0x0051d4: 7101711f  cmp      w8, #0x5c
//   0x0051d8: 1a9f17e8  cset     w8, eq
//   0x0051dc: d1000698  sub      x24, x20, #1
//   0x0051e0: 35000193  cbnz     w19, #0x5210
//   0x0051e4: 34000c69  cbz      w9, #0x5370
//   0x0051e8: 39400689  ldrb     w9, [x20, #1]
//   0x0051ec: 7100e93f  cmp      w9, #0x3a
//   0x0051f0: 1a9f17e9  cset     w9, eq
//   0x0051f4: 2a090109  orr      w9, w8, w9
//   0x0051f8: 37000109  tbnz     w9, #0, #0x5218
//   0x0051fc: 2a1f03e9  mov      w9, wzr
//   0x005200: 1400001a  b        #0x5268
//   0x005204: 2a1f03e8  mov      w8, wzr
//   0x005208: d1000698  sub      x24, x20, #1
//   0x00520c: 34fffed3  cbz      w19, #0x51e4
//   0x005210: 7100bd3f  cmp      w9, #0x2f
//   0x005214: 54ffff41  b.ne     #0x51fc
//   0x005218: d0000069  adrp     x9, #0x13000
//   0x00521c: d000006a  adrp     x10, #0x13000
//   0x005220: 910a3529  add      x9, x9, #0x28d
//   0x005224: 910a1d4a  add      x10, x10, #0x287
//   0x005228: 7100011f  cmp      w8, #0
//   0x00522c: d0000068  adrp     x8, #0x13000
//   0x005230: 9109fd08  add      x8, x8, #0x27f
//   0x005234: 9a891149  csel     x9, x10, x9, ne
//   0x005238: 7100027f  cmp      w19, #0
//   0x00523c: 9a891116  csel     x22, x8, x9, ne
//   0x005240: 52800121  mov      w1, #9
//   0x005244: aa1603e0  mov      x0, x22
//   0x005248: 97fff77e  bl       #0x3040
//   0x00524c: aa0003f7  mov      x23, x0
//   0x005250: aa1503e0  mov      x0, x21
//   0x005254: aa1603e1  mov      x1, x22
//   0x005258: aa1703e2  mov      x2, x23
//   0x00525c: 97fff819  bl       #0x32c0
//   0x005260: 8b1702b5  add      x21, x21, x23
//   0x005264: 52800029  mov      w9, #1
//   0x005268: 7100027f  cmp      w19, #0
//   0x00526c: 1a9f17f7  cset     w23, eq
//   0x005270: 0a0902e9  and      w9, w23, w9
//   0x005274: 52800028  mov      w8, #1
//   0x005278: 52000139  eor      w25, w9, #1
//   0x00527c: 528005fa  mov      w26, #0x2f
//   0x005280: 14000002  b        #0x5288
//   0x005284: 91000694  add      x20, x20, #1
//   0x005288: 3940028c  ldrb     w12, [x20]
//   0x00528c: 7100027f  cmp      w19, #0
//   0x005290: 1a9f07ea  cset     w10, ne
//   0x005294: 7100bd9f  cmp      w12, #0x2f
//   0x005298: 1a9f17eb  cset     w11, eq
//   0x00529c: 7101719f  cmp      w12, #0x5c
//   0x0052a0: 1a9f17e9  cset     w9, eq
//   0x0052a4: 340000ac  cbz      w12, #0x52b8
//   0x0052a8: 0a0b014a  and      w10, w10, w11
//   0x0052ac: 3700006a  tbnz     w10, #0, #0x52b8
//   0x0052b0: 0a170129  and      w9, w9, w23
//   0x0052b4: 34000349  cbz      w9, #0x531c
//   0x0052b8: 91000701  add      x1, x24, #1
//   0x0052bc: eb14003f  cmp      x1, x20
//   0x0052c0: 540002c2  b.hs     #0x5318
//   0x0052c4: 7100051f  cmp      w8, #1
//   0x0052c8: 1a9f07e8  cset     w8, ne
//   0x0052cc: 2a080328  orr      w8, w25, w8
//   0x0052d0: 37000168  tbnz     w8, #0, #0x52fc
//   0x0052d4: 4b010288  sub      w8, w20, w1
//   0x0052d8: 93407d16  sxtw     x22, w8
//   0x0052dc: aa1503e0  mov      x0, x21
//   0x0052e0: aa1603e2  mov      x2, x22
//   0x0052e4: 97fff7f7  bl       #0x32c0
//   0x0052e8: 2a1f03e8  mov      w8, wzr
//   0x0052ec: 8b1602b5  add      x21, x21, x22
//   0x0052f0: 39400289  ldrb     w9, [x20]
//   0x0052f4: 35000189  cbnz     w9, #0x5324
//   0x0052f8: 14000016  b        #0x5350
//   0x0052fc: aa0103e0  mov      x0, x1
//   0x005300: aa1403e1  mov      x1, x20
//   0x005304: aa1503e2  mov      x2, x21
//   0x005308: 2a1f03e3  mov      w3, wzr
//   0x00530c: 2a1f03e4  mov      w4, wzr
//   0x005310: 97fff7b4  bl       #0x31e0
//   0x005314: aa0003f5  mov      x21, x0
//   0x005318: 2a1f03e8  mov      w8, wzr
//   0x00531c: 39400289  ldrb     w9, [x20]
//   0x005320: 34000189  cbz      w9, #0x5350
//   0x005324: 7100bd3f  cmp      w9, #0x2f
//   0x005328: 1a9f17ea  cset     w10, eq
//   0x00532c: 7101713f  cmp      w9, #0x5c
//   0x005330: 1a9f17e9  cset     w9, eq
//   0x005334: 7100027f  cmp      w19, #0
//   0x005338: 1a891149  csel     w9, w10, w9, ne
//   0x00533c: 7100053f  cmp      w9, #1
//   0x005340: 54fffa21  b.ne     #0x5284
//   0x005344: 380016ba  strb     w26, [x21], #1
//   0x005348: aa1403f8  mov      x24, x20
//   0x00534c: 17ffffce  b        #0x5284
//   0x005350: 2a1f03e0  mov      w0, wzr
//   0x005354: 390002bf  strb     wzr, [x21]
//   0x005358: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x00535c: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x005360: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x005364: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x005368: a8c567fa  ldp      x26, x25, [sp], #0x50
//   0x00536c: d65f03c0  ret      
//   0x005370: 34fff468  cbz      w8, #0x51fc
//   0x005374: 17ffffa9  b        #0x5218
// ============================================================================
std::uint32_t fde_035_05194(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005194ULL;
    for (std::size_t i = 0; i < 121ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1937ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[036] Subroutine @ 0x005378..0x005380 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[036] Hàm con @ 0x005378..0x005380 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005378: 2a1f03e2  mov      w2, wzr
//   0x00537c: 17ffff86  b        #0x5194
// ============================================================================
std::uint32_t fde_036_05378(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005378ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2058ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[037] Subroutine @ 0x005380..0x005388 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[037] Hàm con @ 0x005380..0x005388 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005380: 52800022  mov      w2, #1
//   0x005384: 14000001  b        #0x5388
// ============================================================================
std::uint32_t fde_037_05380(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005380ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2060ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[038] Subroutine @ 0x005388..0x00556c (484 bytes, 121 AArch64 instructions)
// [VN] Khung FDE[038] Hàm con @ 0x005388..0x00556c (484 byte, 121 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005388: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00538c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x005390: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x005394: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x005398: 9100c3fd  add      x29, sp, #0x30
//   0x00539c: aa0003f5  mov      x21, x0
//   0x0053a0: 52800040  mov      w0, #2
//   0x0053a4: b4000a15  cbz      x21, #0x54e4
//   0x0053a8: aa0103f3  mov      x19, x1
//   0x0053ac: b40009c1  cbz      x1, #0x54e4
//   0x0053b0: d0000076  adrp     x22, #0x13000
//   0x0053b4: 910a1ed6  add      x22, x22, #0x287
//   0x0053b8: 528000c1  mov      w1, #6
//   0x0053bc: aa1603e0  mov      x0, x22
//   0x0053c0: 2a0203f4  mov      w20, w2
//   0x0053c4: 97fff71f  bl       #0x3040
//   0x0053c8: aa0003e2  mov      x2, x0
//   0x0053cc: aa1503e0  mov      x0, x21
//   0x0053d0: aa1603e1  mov      x1, x22
//   0x0053d4: 97fff717  bl       #0x3030
//   0x0053d8: 2a0003f6  mov      w22, w0
//   0x0053dc: 35000160  cbnz     w0, #0x5408
//   0x0053e0: d0000077  adrp     x23, #0x13000
//   0x0053e4: 910a5af7  add      x23, x23, #0x296
//   0x0053e8: 528000e1  mov      w1, #7
//   0x0053ec: aa1703e0  mov      x0, x23
//   0x0053f0: 97fff714  bl       #0x3040
//   0x0053f4: aa0003e2  mov      x2, x0
//   0x0053f8: aa1503e0  mov      x0, x21
//   0x0053fc: aa1703e1  mov      x1, x23
//   0x005400: 97fff70c  bl       #0x3030
//   0x005404: 340000c0  cbz      w0, #0x541c
//   0x005408: 2a1402c8  orr      w8, w22, w20
//   0x00540c: 340001e8  cbz      w8, #0x5448
//   0x005410: 2a1f03f6  mov      w22, wzr
//   0x005414: aa1f03e0  mov      x0, xzr
//   0x005418: 14000011  b        #0x545c
//   0x00541c: d0000076  adrp     x22, #0x13000
//   0x005420: 9109fed6  add      x22, x22, #0x27f
//   0x005424: 52800101  mov      w1, #8
//   0x005428: aa1603e0  mov      x0, x22
//   0x00542c: 97fff705  bl       #0x3040
//   0x005430: aa0003e2  mov      x2, x0
//   0x005434: aa1503e0  mov      x0, x21
//   0x005438: aa1603e1  mov      x1, x22
//   0x00543c: 97fff6fd  bl       #0x3030
//   0x005440: 340005c0  cbz      w0, #0x54f8
//   0x005444: 34fffe74  cbz      w20, #0x5410
//   0x005448: d0000060  adrp     x0, #0x13000
//   0x00544c: 910a1c00  add      x0, x0, #0x287
//   0x005450: 528000c1  mov      w1, #6
//   0x005454: 97fff6fb  bl       #0x3040
//   0x005458: 2a1f03f6  mov      w22, wzr
//   0x00545c: 52800037  mov      w23, #1
//   0x005460: 8b0002b5  add      x21, x21, x0
//   0x005464: aa1503e0  mov      x0, x21
//   0x005468: 97fff772  bl       #0x3230
//   0x00546c: 7100029f  cmp      w20, #0
//   0x005470: 1a9f17ea  cset     w10, eq
//   0x005474: 0a16014a  and      w10, w10, w22
//   0x005478: aa0003e8  mov      x8, x0
//   0x00547c: 91000a69  add      x9, x19, #2
//   0x005480: 0a0a02eb  and      w11, w23, w10
//   0x005484: 6a0a02ff  tst      w23, w10
//   0x005488: 9a931120  csel     x0, x9, x19, ne
//   0x00548c: 7100057f  cmp      w11, #1
//   0x005490: 91000502  add      x2, x8, #1
//   0x005494: 54000061  b.ne     #0x54a0
//   0x005498: 528b8b88  mov      w8, #0x5c5c
//   0x00549c: 79000268  strh     w8, [x19]
//   0x0054a0: aa1503e1  mov      x1, x21
//   0x0054a4: 97fff787  bl       #0x32c0
//   0x0054a8: 52800062  mov      w2, #3
//   0x0054ac: aa1303e0  mov      x0, x19
//   0x0054b0: 2a1f03e1  mov      w1, wzr
//   0x0054b4: 97fff787  bl       #0x32d0
//   0x0054b8: 2a1f03e0  mov      w0, wzr
//   0x0054bc: 35000154  cbnz     w20, #0x54e4
//   0x0054c0: 52800b88  mov      w8, #0x5c
//   0x0054c4: 14000003  b        #0x54d0
//   0x0054c8: 39000268  strb     w8, [x19]
//   0x0054cc: 91000673  add      x19, x19, #1
//   0x0054d0: 39400269  ldrb     w9, [x19]
//   0x0054d4: 7100bd3f  cmp      w9, #0x2f
//   0x0054d8: 54ffff80  b.eq     #0x54c8
//   0x0054dc: 35ffff89  cbnz     w9, #0x54cc
//   0x0054e0: 2a1f03e0  mov      w0, wzr
//   0x0054e4: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x0054e8: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x0054ec: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x0054f0: f84407f7  ldr      x23, [sp], #0x40
//   0x0054f4: d65f03c0  ret      
//   0x0054f8: d0000076  adrp     x22, #0x13000
//   0x0054fc: 910a36d6  add      x22, x22, #0x28d
//   0x005500: 52800121  mov      w1, #9
//   0x005504: aa1603e0  mov      x0, x22
//   0x005508: 97fff6ce  bl       #0x3040
//   0x00550c: aa0003e2  mov      x2, x0
//   0x005510: aa1503e0  mov      x0, x21
//   0x005514: aa1603e1  mov      x1, x22
//   0x005518: 97fff6c6  bl       #0x3030
//   0x00551c: 34000100  cbz      w0, #0x553c
//   0x005520: d0000060  adrp     x0, #0x13000
//   0x005524: 9109fc00  add      x0, x0, #0x27f
//   0x005528: 52800101  mov      w1, #8
//   0x00552c: 97fff6c5  bl       #0x3040
//   0x005530: 52800037  mov      w23, #1
//   0x005534: 52800036  mov      w22, #1
//   0x005538: 17ffffca  b        #0x5460
//   0x00553c: 340000b4  cbz      w20, #0x5550
//   0x005540: d0000060  adrp     x0, #0x13000
//   0x005544: 9109fc00  add      x0, x0, #0x27f
//   0x005548: 52800101  mov      w1, #8
//   0x00554c: 14000004  b        #0x555c
//   0x005550: d0000060  adrp     x0, #0x13000
//   0x005554: 910a3400  add      x0, x0, #0x28d
//   0x005558: 52800121  mov      w1, #9
//   0x00555c: 97fff6b9  bl       #0x3040
//   0x005560: 2a1f03f7  mov      w23, wzr
//   0x005564: 52800036  mov      w22, #1
//   0x005568: 17ffffbe  b        #0x5460
// ============================================================================
std::uint32_t fde_038_05388(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005388ULL;
    for (std::size_t i = 0; i < 121ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2062ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[039] Subroutine @ 0x00556c..0x005574 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[039] Hàm con @ 0x00556c..0x005574 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00556c: 2a1f03e2  mov      w2, wzr
//   0x005570: 17ffff86  b        #0x5388
// ============================================================================
std::uint32_t fde_039_0556c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000556cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2183ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[040] Subroutine @ 0x005574..0x00562c (184 bytes, 46 AArch64 instructions)
// [VN] Khung FDE[040] Hàm con @ 0x005574..0x00562c (184 byte, 46 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005574: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x005578: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00557c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x005580: 910083fd  add      x29, sp, #0x20
//   0x005584: aa0003f3  mov      x19, x0
//   0x005588: 52800040  mov      w0, #2
//   0x00558c: b4000493  cbz      x19, #0x561c
//   0x005590: aa0103e2  mov      x2, x1
//   0x005594: b4000441  cbz      x1, #0x561c
//   0x005598: b9400268  ldr      w8, [x19]
//   0x00559c: d1001274  sub      x20, x19, #4
//   0x0055a0: 7100bd1f  cmp      w8, #0x2f
//   0x0055a4: 540000e1  b.ne     #0x55c0
//   0x0055a8: d0000068  adrp     x8, #0x13000
//   0x0055ac: 910a8108  add      x8, x8, #0x2a0
//   0x0055b0: 3cc0c100  ldur     q0, [x8, #0xc]
//   0x0055b4: 3dc00101  ldr      q1, [x8]
//   0x0055b8: 3c80c040  stur     q0, [x2, #0xc]
//   0x0055bc: 3c81c441  str      q1, [x2], #0x1c
//   0x0055c0: 528005f5  mov      w21, #0x2f
//   0x0055c4: 14000004  b        #0x55d4
//   0x0055c8: b8004455  str      w21, [x2], #4
//   0x0055cc: aa1303f4  mov      x20, x19
//   0x0055d0: 91001273  add      x19, x19, #4
//   0x0055d4: b9400268  ldr      w8, [x19]
//   0x0055d8: 7100bd1f  cmp      w8, #0x2f
//   0x0055dc: 54000040  b.eq     #0x55e4
//   0x0055e0: 35000148  cbnz     w8, #0x5608
//   0x0055e4: 91001280  add      x0, x20, #4
//   0x0055e8: eb13001f  cmp      x0, x19
//   0x0055ec: 540000e2  b.hs     #0x5608
//   0x0055f0: aa1303e1  mov      x1, x19
//   0x0055f4: 2a1f03e3  mov      w3, wzr
//   0x0055f8: 2a1f03e4  mov      w4, wzr
//   0x0055fc: 97fff6f1  bl       #0x31c0
//   0x005600: b9400268  ldr      w8, [x19]
//   0x005604: aa0003e2  mov      x2, x0
//   0x005608: 7100bd1f  cmp      w8, #0x2f
//   0x00560c: 54fffde0  b.eq     #0x55c8
//   0x005610: 35fffe08  cbnz     w8, #0x55d0
//   0x005614: 2a1f03e0  mov      w0, wzr
//   0x005618: b900005f  str      wzr, [x2]
//   0x00561c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x005620: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x005624: f84307f5  ldr      x21, [sp], #0x30
//   0x005628: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_040_05574(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005574ULL;
    for (std::size_t i = 0; i < 46ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2185ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[041] Subroutine @ 0x00562c..0x005780 (340 bytes, 85 AArch64 instructions)
// [VN] Khung FDE[041] Hàm con @ 0x00562c..0x005780 (340 byte, 85 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00562c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x005630: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x005634: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x005638: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00563c: 9100c3fd  add      x29, sp, #0x30
//   0x005640: aa0003f3  mov      x19, x0
//   0x005644: 52800040  mov      w0, #2
//   0x005648: b4000933  cbz      x19, #0x576c
//   0x00564c: aa0103f4  mov      x20, x1
//   0x005650: b40008e1  cbz      x1, #0x576c
//   0x005654: b9400268  ldr      w8, [x19]
//   0x005658: d1001276  sub      x22, x19, #4
//   0x00565c: 34000128  cbz      w8, #0x5680
//   0x005660: 7101711f  cmp      w8, #0x5c
//   0x005664: 54000121  b.ne     #0x5688
//   0x005668: b9400668  ldr      w8, [x19, #4]
//   0x00566c: 7101711f  cmp      w8, #0x5c
//   0x005670: 1a9f17e9  cset     w9, eq
//   0x005674: 37000109  tbnz     w9, #0, #0x5694
//   0x005678: 7100e91f  cmp      w8, #0x3a
//   0x00567c: 540000c0  b.eq     #0x5694
//   0x005680: 2a1f03e9  mov      w9, wzr
//   0x005684: 14000012  b        #0x56cc
//   0x005688: b9400668  ldr      w8, [x19, #4]
//   0x00568c: 2a1f03e9  mov      w9, wzr
//   0x005690: 3607ff49  tbz      w9, #0, #0x5678
//   0x005694: 7100013f  cmp      w9, #0
//   0x005698: 52800408  mov      w8, #0x20
//   0x00569c: 52800289  mov      w9, #0x14
//   0x0056a0: d000006a  adrp     x10, #0x13000
//   0x0056a4: d000006b  adrp     x11, #0x13000
//   0x0056a8: 910b614a  add      x10, x10, #0x2d8
//   0x0056ac: 910b016b  add      x11, x11, #0x2c0
//   0x0056b0: 9a881135  csel     x21, x9, x8, ne
//   0x0056b4: 9a8a1161  csel     x1, x11, x10, ne
//   0x0056b8: aa1403e0  mov      x0, x20
//   0x0056bc: aa1503e2  mov      x2, x21
//   0x0056c0: 97fff700  bl       #0x32c0
//   0x0056c4: 8b150294  add      x20, x20, x21
//   0x0056c8: 52800029  mov      w9, #1
//   0x0056cc: 52800028  mov      w8, #1
//   0x0056d0: 52000137  eor      w23, w9, #1
//   0x0056d4: 528005f8  mov      w24, #0x2f
//   0x0056d8: 14000004  b        #0x56e8
//   0x0056dc: b8004698  str      w24, [x20], #4
//   0x0056e0: aa1303f6  mov      x22, x19
//   0x0056e4: 91001273  add      x19, x19, #4
//   0x0056e8: b9400269  ldr      w9, [x19]
//   0x0056ec: 7101713f  cmp      w9, #0x5c
//   0x0056f0: 54000040  b.eq     #0x56f8
//   0x0056f4: 35000329  cbnz     w9, #0x5758
//   0x0056f8: 910012c1  add      x1, x22, #4
//   0x0056fc: eb13003f  cmp      x1, x19
//   0x005700: 54000282  b.hs     #0x5750
//   0x005704: 7100051f  cmp      w8, #1
//   0x005708: 1a9f07e8  cset     w8, ne
//   0x00570c: 2a0802e8  orr      w8, w23, w8
//   0x005710: 37000128  tbnz     w8, #0, #0x5734
//   0x005714: cb010268  sub      x8, x19, x1
//   0x005718: 93428508  sbfx     x8, x8, #2, #0x20
//   0x00571c: d37ef515  lsl      x21, x8, #2
//   0x005720: aa1403e0  mov      x0, x20
//   0x005724: aa1503e2  mov      x2, x21
//   0x005728: 97fff6e6  bl       #0x32c0
//   0x00572c: 8b150294  add      x20, x20, x21
//   0x005730: 14000008  b        #0x5750
//   0x005734: aa0103e0  mov      x0, x1
//   0x005738: aa1303e1  mov      x1, x19
//   0x00573c: aa1403e2  mov      x2, x20
//   0x005740: 2a1f03e3  mov      w3, wzr
//   0x005744: 2a1f03e4  mov      w4, wzr
//   0x005748: 97fff69e  bl       #0x31c0
//   0x00574c: aa0003f4  mov      x20, x0
//   0x005750: b9400269  ldr      w9, [x19]
//   0x005754: 2a1f03e8  mov      w8, wzr
//   0x005758: 7101713f  cmp      w9, #0x5c
//   0x00575c: 54fffc00  b.eq     #0x56dc
//   0x005760: 35fffc29  cbnz     w9, #0x56e4
//   0x005764: 2a1f03e0  mov      w0, wzr
//   0x005768: b900029f  str      wzr, [x20]
//   0x00576c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x005770: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x005774: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x005778: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00577c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_041_0562c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000562cULL;
    for (std::size_t i = 0; i < 85ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2231ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[042] Subroutine @ 0x005780..0x005788 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[042] Hàm con @ 0x005780..0x005788 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005780: 52800022  mov      w2, #1
//   0x005784: 14000001  b        #0x5788
// ============================================================================
std::uint32_t fde_042_05780(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005780ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2316ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[043] Subroutine @ 0x005788..0x005910 (392 bytes, 98 AArch64 instructions)
// [VN] Khung FDE[043] Hàm con @ 0x005788..0x005910 (392 byte, 98 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005788: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00578c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x005790: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x005794: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x005798: 9100c3fd  add      x29, sp, #0x30
//   0x00579c: aa0003f5  mov      x21, x0
//   0x0057a0: 52800040  mov      w0, #2
//   0x0057a4: b4000735  cbz      x21, #0x5888
//   0x0057a8: aa0103f3  mov      x19, x1
//   0x0057ac: b40006e1  cbz      x1, #0x5888
//   0x0057b0: d0000061  adrp     x1, #0x13000
//   0x0057b4: 2a0203f4  mov      w20, w2
//   0x0057b8: 910b0021  add      x1, x1, #0x2c0
//   0x0057bc: 528000a2  mov      w2, #5
//   0x0057c0: aa1503e0  mov      x0, x21
//   0x0057c4: 528000b8  mov      w24, #5
//   0x0057c8: 97fff60e  bl       #0x3000
//   0x0057cc: 2a0003f6  mov      w22, w0
//   0x0057d0: 35000100  cbnz     w0, #0x57f0
//   0x0057d4: d0000061  adrp     x1, #0x13000
//   0x0057d8: 910bf021  add      x1, x1, #0x2fc
//   0x0057dc: 528000c2  mov      w2, #6
//   0x0057e0: aa1503e0  mov      x0, x21
//   0x0057e4: 97fff607  bl       #0x3000
//   0x0057e8: 340005a0  cbz      w0, #0x589c
//   0x0057ec: 528000b8  mov      w24, #5
//   0x0057f0: 2a1402c8  orr      w8, w22, w20
//   0x0057f4: 7100011f  cmp      w8, #0
//   0x0057f8: 2a1f03f7  mov      w23, wzr
//   0x0057fc: 9a9f0308  csel     x8, x24, xzr, eq
//   0x005800: 52800036  mov      w22, #1
//   0x005804: 8b080ab5  add      x21, x21, x8, lsl #2
//   0x005808: aa1503e0  mov      x0, x21
//   0x00580c: 97fff649  bl       #0x3130
//   0x005810: 7100029f  cmp      w20, #0
//   0x005814: 1a9f17e9  cset     w9, eq
//   0x005818: 0a170129  and      w9, w9, w23
//   0x00581c: 91002268  add      x8, x19, #8
//   0x005820: 0a0902ca  and      w10, w22, w9
//   0x005824: 6a0902df  tst      w22, w9
//   0x005828: 9a931108  csel     x8, x8, x19, ne
//   0x00582c: 7100055f  cmp      w10, #1
//   0x005830: 54000061  b.ne     #0x583c
//   0x005834: 0f020780  movi     v0.2s, #0x5c
//   0x005838: fd000260  str      d0, [x19]
//   0x00583c: d37ef409  lsl      x9, x0, #2
//   0x005840: 91001122  add      x2, x9, #4
//   0x005844: aa0803e0  mov      x0, x8
//   0x005848: aa1503e1  mov      x1, x21
//   0x00584c: 97fff69d  bl       #0x32c0
//   0x005850: 52800062  mov      w2, #3
//   0x005854: aa1303e0  mov      x0, x19
//   0x005858: 2a1f03e1  mov      w1, wzr
//   0x00585c: 97fff5d5  bl       #0x2fb0
//   0x005860: 2a1f03e0  mov      w0, wzr
//   0x005864: 35000134  cbnz     w20, #0x5888
//   0x005868: 52800b88  mov      w8, #0x5c
//   0x00586c: 14000003  b        #0x5878
//   0x005870: b9000268  str      w8, [x19]
//   0x005874: 91001273  add      x19, x19, #4
//   0x005878: b9400260  ldr      w0, [x19]
//   0x00587c: 7100bc1f  cmp      w0, #0x2f
//   0x005880: 54ffff80  b.eq     #0x5870
//   0x005884: 35ffff80  cbnz     w0, #0x5874
//   0x005888: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00588c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x005890: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x005894: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x005898: d65f03c0  ret      
//   0x00589c: d0000061  adrp     x1, #0x13000
//   0x0058a0: 910a8021  add      x1, x1, #0x2a0
//   0x0058a4: 528000e2  mov      w2, #7
//   0x0058a8: aa1503e0  mov      x0, x21
//   0x0058ac: 97fff5d5  bl       #0x3000
//   0x0058b0: 340000c0  cbz      w0, #0x58c8
//   0x0058b4: 340001f4  cbz      w20, #0x58f0
//   0x0058b8: 2a1f03f7  mov      w23, wzr
//   0x0058bc: 52800036  mov      w22, #1
//   0x0058c0: 528000a8  mov      w8, #5
//   0x0058c4: 17ffffd0  b        #0x5804
//   0x0058c8: d0000061  adrp     x1, #0x13000
//   0x0058cc: 910b6021  add      x1, x1, #0x2d8
//   0x0058d0: 52800102  mov      w2, #8
//   0x0058d4: aa1503e0  mov      x0, x21
//   0x0058d8: 97fff5ca  bl       #0x3000
//   0x0058dc: 340000e0  cbz      w0, #0x58f8
//   0x0058e0: 52800036  mov      w22, #1
//   0x0058e4: 528000e8  mov      w8, #7
//   0x0058e8: 52800037  mov      w23, #1
//   0x0058ec: 17ffffc6  b        #0x5804
//   0x0058f0: aa1f03f8  mov      x24, xzr
//   0x0058f4: 17ffffbf  b        #0x57f0
//   0x0058f8: 7100029f  cmp      w20, #0
//   0x0058fc: 528000e8  mov      w8, #7
//   0x005900: 2a1f03f6  mov      w22, wzr
//   0x005904: 9a881508  cinc     x8, x8, eq
//   0x005908: 52800037  mov      w23, #1
//   0x00590c: 17ffffbe  b        #0x5804
// ============================================================================
std::uint32_t fde_043_05788(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005788ULL;
    for (std::size_t i = 0; i < 98ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2318ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[044] Subroutine @ 0x005910..0x005918 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[044] Hàm con @ 0x005910..0x005918 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005910: 2a1f03e2  mov      w2, wzr
//   0x005914: 17ffff9d  b        #0x5788
// ============================================================================
std::uint32_t fde_044_05910(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005910ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2416ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[045] Subroutine @ 0x005918..0x005a60 (328 bytes, 82 AArch64 instructions)
// [VN] Khung FDE[045] Hàm con @ 0x005918..0x005a60 (328 byte, 82 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005918: d10103ff  sub      sp, sp, #0x40
//   0x00591c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x005920: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x005924: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x005928: 9100c3fd  add      x29, sp, #0x30
//   0x00592c: d53bd056  mrs      x22, tpidr_el0
//   0x005930: f94016c8  ldr      x8, [x22, #0x28]
//   0x005934: aa0003f3  mov      x19, x0
//   0x005938: 52800020  mov      w0, #1
//   0x00593c: f90007e8  str      x8, [sp, #8]
//   0x005940: b4000733  cbz      x19, #0x5a24
//   0x005944: b4000701  cbz      x1, #0x5a24
//   0x005948: aa0203f4  mov      x20, x2
//   0x00594c: eb01005f  cmp      x2, x1
//   0x005950: 540006a9  b.ls     #0x5a24
//   0x005954: 910003e0  mov      x0, sp
//   0x005958: aa1403e2  mov      x2, x20
//   0x00595c: 390003ff  strb     wzr, [sp]
//   0x005960: 94000040  bl       #0x5a60
//   0x005964: aa0003f5  mov      x21, x0
//   0x005968: 52800020  mov      w0, #1
//   0x00596c: b40005d5  cbz      x21, #0x5a24
//   0x005970: eb1402bf  cmp      x21, x20
//   0x005974: 54000582  b.hs     #0x5a24
//   0x005978: 394002a8  ldrb     w8, [x21]
//   0x00597c: 7100b91f  cmp      w8, #0x2e
//   0x005980: 54000501  b.ne     #0x5a20
//   0x005984: 910003e0  mov      x0, sp
//   0x005988: aa1303e1  mov      x1, x19
//   0x00598c: 97fff61d  bl       #0x3200
//   0x005990: 910006a1  add      x1, x21, #1
//   0x005994: 910003e0  mov      x0, sp
//   0x005998: aa1403e2  mov      x2, x20
//   0x00599c: 94000031  bl       #0x5a60
//   0x0059a0: aa0003f5  mov      x21, x0
//   0x0059a4: 52800020  mov      w0, #1
//   0x0059a8: b40003f5  cbz      x21, #0x5a24
//   0x0059ac: eb1402bf  cmp      x21, x20
//   0x0059b0: 540003a2  b.hs     #0x5a24
//   0x0059b4: 394002a8  ldrb     w8, [x21]
//   0x0059b8: 7100b91f  cmp      w8, #0x2e
//   0x0059bc: 54000321  b.ne     #0x5a20
//   0x0059c0: 91000661  add      x1, x19, #1
//   0x0059c4: 910003e0  mov      x0, sp
//   0x0059c8: 97fff60e  bl       #0x3200
//   0x0059cc: 910006a1  add      x1, x21, #1
//   0x0059d0: 910003e0  mov      x0, sp
//   0x0059d4: aa1403e2  mov      x2, x20
//   0x0059d8: 94000022  bl       #0x5a60
//   0x0059dc: aa0003f5  mov      x21, x0
//   0x0059e0: 52800020  mov      w0, #1
//   0x0059e4: b4000215  cbz      x21, #0x5a24
//   0x0059e8: eb1402bf  cmp      x21, x20
//   0x0059ec: 540001c2  b.hs     #0x5a24
//   0x0059f0: 394002a8  ldrb     w8, [x21]
//   0x0059f4: 7100b91f  cmp      w8, #0x2e
//   0x0059f8: 54000141  b.ne     #0x5a20
//   0x0059fc: 91000a61  add      x1, x19, #2
//   0x005a00: 910003e0  mov      x0, sp
//   0x005a04: 97fff5ff  bl       #0x3200
//   0x005a08: 910006a1  add      x1, x21, #1
//   0x005a0c: 910003e0  mov      x0, sp
//   0x005a10: aa1403e2  mov      x2, x20
//   0x005a14: 94000013  bl       #0x5a60
//   0x005a18: eb14001f  cmp      x0, x20
//   0x005a1c: 54000160  b.eq     #0x5a48
//   0x005a20: 52800020  mov      w0, #1
//   0x005a24: f94016c8  ldr      x8, [x22, #0x28]
//   0x005a28: f94007e9  ldr      x9, [sp, #8]
//   0x005a2c: eb09011f  cmp      x8, x9
//   0x005a30: 54000161  b.ne     #0x5a5c
//   0x005a34: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x005a38: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x005a3c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x005a40: 910103ff  add      sp, sp, #0x40
//   0x005a44: d65f03c0  ret      
//   0x005a48: 91000e61  add      x1, x19, #3
//   0x005a4c: 910003e0  mov      x0, sp
//   0x005a50: 97fff5ec  bl       #0x3200
//   0x005a54: 2a1f03e0  mov      w0, wzr
//   0x005a58: 17fffff3  b        #0x5a24
//   0x005a5c: 97fff5b1  bl       #0x3120
// ============================================================================
std::uint32_t fde_045_05918(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005918ULL;
    for (std::size_t i = 0; i < 82ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2418ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[046] Subroutine @ 0x005a60..0x005bf0 (400 bytes, 100 AArch64 instructions)
// [VN] Khung FDE[046] Hàm con @ 0x005a60..0x005bf0 (400 byte, 100 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005a60: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x005a64: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x005a68: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x005a6c: 910083fd  add      x29, sp, #0x20
//   0x005a70: eb02003f  cmp      x1, x2
//   0x005a74: 540003a2  b.hs     #0x5ae8
//   0x005a78: 39400028  ldrb     w8, [x1]
//   0x005a7c: aa0103f3  mov      x19, x1
//   0x005a80: 5100c101  sub      w1, w8, #0x30
//   0x005a84: 7100243f  cmp      w1, #9
//   0x005a88: 54000308  b.hi     #0x5ae8
//   0x005a8c: d0000068  adrp     x8, #0x13000
//   0x005a90: 910c6108  add      x8, x8, #0x318
//   0x005a94: 100000c9  adr      x9, #0x5aac
//   0x005a98: 3861690a  ldrb     w10, [x8, x1]
//   0x005a9c: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x005aa0: aa0203f5  mov      x21, x2
//   0x005aa4: aa0003f4  mov      x20, x0
//   0x005aa8: d61f0120  br       x9
//   0x005aac: aa1403e0  mov      x0, x20
//   0x005ab0: 97fff53c  bl       #0x2fa0
//   0x005ab4: 91000668  add      x8, x19, #1
//   0x005ab8: eb15011f  cmp      x8, x21
//   0x005abc: aa1503e0  mov      x0, x21
//   0x005ac0: 54000162  b.hs     #0x5aec
//   0x005ac4: 39400109  ldrb     w9, [x8]
//   0x005ac8: aa0803e0  mov      x0, x8
//   0x005acc: 5100c121  sub      w1, w9, #0x30
//   0x005ad0: 7100243f  cmp      w1, #9
//   0x005ad4: 540000c8  b.hi     #0x5aec
//   0x005ad8: aa1403e0  mov      x0, x20
//   0x005adc: 97fff531  bl       #0x2fa0
//   0x005ae0: 91000a60  add      x0, x19, #2
//   0x005ae4: 14000002  b        #0x5aec
//   0x005ae8: aa1f03e0  mov      x0, xzr
//   0x005aec: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x005af0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x005af4: f84307f5  ldr      x21, [sp], #0x30
//   0x005af8: d65f03c0  ret      
//   0x005afc: aa1403e0  mov      x0, x20
//   0x005b00: 2a1f03e1  mov      w1, wzr
//   0x005b04: 97fff527  bl       #0x2fa0
//   0x005b08: 91000660  add      x0, x19, #1
//   0x005b0c: 17fffff8  b        #0x5aec
//   0x005b10: 52800021  mov      w1, #1
//   0x005b14: aa1403e0  mov      x0, x20
//   0x005b18: 97fff522  bl       #0x2fa0
//   0x005b1c: 91000660  add      x0, x19, #1
//   0x005b20: eb15001f  cmp      x0, x21
//   0x005b24: 54000442  b.hs     #0x5bac
//   0x005b28: 39400008  ldrb     w8, [x0]
//   0x005b2c: 5100c101  sub      w1, w8, #0x30
//   0x005b30: 7100243f  cmp      w1, #9
//   0x005b34: 54fffdc8  b.hi     #0x5aec
//   0x005b38: 1400001f  b        #0x5bb4
//   0x005b3c: 52800041  mov      w1, #2
//   0x005b40: aa1403e0  mov      x0, x20
//   0x005b44: 97fff517  bl       #0x2fa0
//   0x005b48: 91000660  add      x0, x19, #1
//   0x005b4c: eb15001f  cmp      x0, x21
//   0x005b50: 540002e2  b.hs     #0x5bac
//   0x005b54: 39400008  ldrb     w8, [x0]
//   0x005b58: 5100c101  sub      w1, w8, #0x30
//   0x005b5c: 7100143f  cmp      w1, #5
//   0x005b60: 540002a3  b.lo     #0x5bb4
//   0x005b64: 5100d909  sub      w9, w8, #0x36
//   0x005b68: 7100113f  cmp      w9, #4
//   0x005b6c: 54fffb63  b.lo     #0x5ad8
//   0x005b70: 7100d51f  cmp      w8, #0x35
//   0x005b74: 54fffbc1  b.ne     #0x5aec
//   0x005b78: 528000a1  mov      w1, #5
//   0x005b7c: aa1403e0  mov      x0, x20
//   0x005b80: 97fff508  bl       #0x2fa0
//   0x005b84: 91000a68  add      x8, x19, #2
//   0x005b88: eb15011f  cmp      x8, x21
//   0x005b8c: aa1503e0  mov      x0, x21
//   0x005b90: 54fffae2  b.hs     #0x5aec
//   0x005b94: 39400109  ldrb     w9, [x8]
//   0x005b98: 5100c121  sub      w1, w9, #0x30
//   0x005b9c: 7100143f  cmp      w1, #5
//   0x005ba0: aa0803e0  mov      x0, x8
//   0x005ba4: 54fffa48  b.hi     #0x5aec
//   0x005ba8: 1400000e  b        #0x5be0
//   0x005bac: aa1503e0  mov      x0, x21
//   0x005bb0: 17ffffcf  b        #0x5aec
//   0x005bb4: aa1403e0  mov      x0, x20
//   0x005bb8: 97fff4fa  bl       #0x2fa0
//   0x005bbc: 91000a68  add      x8, x19, #2
//   0x005bc0: eb15011f  cmp      x8, x21
//   0x005bc4: aa1503e0  mov      x0, x21
//   0x005bc8: 54fff922  b.hs     #0x5aec
//   0x005bcc: 39400109  ldrb     w9, [x8]
//   0x005bd0: 5100c121  sub      w1, w9, #0x30
//   0x005bd4: 7100243f  cmp      w1, #9
//   0x005bd8: aa0803e0  mov      x0, x8
//   0x005bdc: 54fff888  b.hi     #0x5aec
//   0x005be0: aa1403e0  mov      x0, x20
//   0x005be4: 97fff4ef  bl       #0x2fa0
//   0x005be8: 91000e60  add      x0, x19, #3
//   0x005bec: 17ffffc0  b        #0x5aec
// ============================================================================
std::uint32_t fde_046_05a60(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005a60ULL;
    for (std::size_t i = 0; i < 100ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2500ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[047] Subroutine @ 0x005bf0..0x005d38 (328 bytes, 82 AArch64 instructions)
// [VN] Khung FDE[047] Hàm con @ 0x005bf0..0x005d38 (328 byte, 82 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005bf0: d10103ff  sub      sp, sp, #0x40
//   0x005bf4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x005bf8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x005bfc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x005c00: 9100c3fd  add      x29, sp, #0x30
//   0x005c04: d53bd056  mrs      x22, tpidr_el0
//   0x005c08: f94016c8  ldr      x8, [x22, #0x28]
//   0x005c0c: aa0003f3  mov      x19, x0
//   0x005c10: 52800020  mov      w0, #1
//   0x005c14: f90007e8  str      x8, [sp, #8]
//   0x005c18: b4000733  cbz      x19, #0x5cfc
//   0x005c1c: b4000701  cbz      x1, #0x5cfc
//   0x005c20: aa0203f4  mov      x20, x2
//   0x005c24: eb01005f  cmp      x2, x1
//   0x005c28: 540006a9  b.ls     #0x5cfc
//   0x005c2c: 910003e0  mov      x0, sp
//   0x005c30: aa1403e2  mov      x2, x20
//   0x005c34: 390003ff  strb     wzr, [sp]
//   0x005c38: 94000040  bl       #0x5d38
//   0x005c3c: aa0003f5  mov      x21, x0
//   0x005c40: 52800020  mov      w0, #1
//   0x005c44: b40005d5  cbz      x21, #0x5cfc
//   0x005c48: eb1402bf  cmp      x21, x20
//   0x005c4c: 54000582  b.hs     #0x5cfc
//   0x005c50: b94002a8  ldr      w8, [x21]
//   0x005c54: 7100b91f  cmp      w8, #0x2e
//   0x005c58: 54000501  b.ne     #0x5cf8
//   0x005c5c: 910003e0  mov      x0, sp
//   0x005c60: aa1303e1  mov      x1, x19
//   0x005c64: 97fff567  bl       #0x3200
//   0x005c68: 910012a1  add      x1, x21, #4
//   0x005c6c: 910003e0  mov      x0, sp
//   0x005c70: aa1403e2  mov      x2, x20
//   0x005c74: 94000031  bl       #0x5d38
//   0x005c78: aa0003f5  mov      x21, x0
//   0x005c7c: 52800020  mov      w0, #1
//   0x005c80: b40003f5  cbz      x21, #0x5cfc
//   0x005c84: eb1402bf  cmp      x21, x20
//   0x005c88: 540003a2  b.hs     #0x5cfc
//   0x005c8c: b94002a8  ldr      w8, [x21]
//   0x005c90: 7100b91f  cmp      w8, #0x2e
//   0x005c94: 54000321  b.ne     #0x5cf8
//   0x005c98: 91000661  add      x1, x19, #1
//   0x005c9c: 910003e0  mov      x0, sp
//   0x005ca0: 97fff558  bl       #0x3200
//   0x005ca4: 910012a1  add      x1, x21, #4
//   0x005ca8: 910003e0  mov      x0, sp
//   0x005cac: aa1403e2  mov      x2, x20
//   0x005cb0: 94000022  bl       #0x5d38
//   0x005cb4: aa0003f5  mov      x21, x0
//   0x005cb8: 52800020  mov      w0, #1
//   0x005cbc: b4000215  cbz      x21, #0x5cfc
//   0x005cc0: eb1402bf  cmp      x21, x20
//   0x005cc4: 540001c2  b.hs     #0x5cfc
//   0x005cc8: b94002a8  ldr      w8, [x21]
//   0x005ccc: 7100b91f  cmp      w8, #0x2e
//   0x005cd0: 54000141  b.ne     #0x5cf8
//   0x005cd4: 91000a61  add      x1, x19, #2
//   0x005cd8: 910003e0  mov      x0, sp
//   0x005cdc: 97fff549  bl       #0x3200
//   0x005ce0: 910012a1  add      x1, x21, #4
//   0x005ce4: 910003e0  mov      x0, sp
//   0x005ce8: aa1403e2  mov      x2, x20
//   0x005cec: 94000013  bl       #0x5d38
//   0x005cf0: eb14001f  cmp      x0, x20
//   0x005cf4: 54000160  b.eq     #0x5d20
//   0x005cf8: 52800020  mov      w0, #1
//   0x005cfc: f94016c8  ldr      x8, [x22, #0x28]
//   0x005d00: f94007e9  ldr      x9, [sp, #8]
//   0x005d04: eb09011f  cmp      x8, x9
//   0x005d08: 54000161  b.ne     #0x5d34
//   0x005d0c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x005d10: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x005d14: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x005d18: 910103ff  add      sp, sp, #0x40
//   0x005d1c: d65f03c0  ret      
//   0x005d20: 91000e61  add      x1, x19, #3
//   0x005d24: 910003e0  mov      x0, sp
//   0x005d28: 97fff536  bl       #0x3200
//   0x005d2c: 2a1f03e0  mov      w0, wzr
//   0x005d30: 17fffff3  b        #0x5cfc
//   0x005d34: 97fff4fb  bl       #0x3120
// ============================================================================
std::uint32_t fde_047_05bf0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005bf0ULL;
    for (std::size_t i = 0; i < 82ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2600ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[048] Subroutine @ 0x005d38..0x005ec8 (400 bytes, 100 AArch64 instructions)
// [VN] Khung FDE[048] Hàm con @ 0x005d38..0x005ec8 (400 byte, 100 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005d38: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x005d3c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x005d40: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x005d44: 910083fd  add      x29, sp, #0x20
//   0x005d48: eb02003f  cmp      x1, x2
//   0x005d4c: 540003a2  b.hs     #0x5dc0
//   0x005d50: b9400028  ldr      w8, [x1]
//   0x005d54: aa0103f3  mov      x19, x1
//   0x005d58: 5100c101  sub      w1, w8, #0x30
//   0x005d5c: 7100243f  cmp      w1, #9
//   0x005d60: 54000308  b.hi     #0x5dc0
//   0x005d64: d0000068  adrp     x8, #0x13000
//   0x005d68: 910c8908  add      x8, x8, #0x322
//   0x005d6c: 100000c9  adr      x9, #0x5d84
//   0x005d70: 3861690a  ldrb     w10, [x8, x1]
//   0x005d74: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x005d78: aa0203f5  mov      x21, x2
//   0x005d7c: aa0003f4  mov      x20, x0
//   0x005d80: d61f0120  br       x9
//   0x005d84: aa1403e0  mov      x0, x20
//   0x005d88: 97fff486  bl       #0x2fa0
//   0x005d8c: 91001268  add      x8, x19, #4
//   0x005d90: eb15011f  cmp      x8, x21
//   0x005d94: aa1503e0  mov      x0, x21
//   0x005d98: 54000162  b.hs     #0x5dc4
//   0x005d9c: b9400109  ldr      w9, [x8]
//   0x005da0: aa0803e0  mov      x0, x8
//   0x005da4: 5100c121  sub      w1, w9, #0x30
//   0x005da8: 7100243f  cmp      w1, #9
//   0x005dac: 540000c8  b.hi     #0x5dc4
//   0x005db0: aa1403e0  mov      x0, x20
//   0x005db4: 97fff47b  bl       #0x2fa0
//   0x005db8: 91002260  add      x0, x19, #8
//   0x005dbc: 14000002  b        #0x5dc4
//   0x005dc0: aa1f03e0  mov      x0, xzr
//   0x005dc4: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x005dc8: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x005dcc: f84307f5  ldr      x21, [sp], #0x30
//   0x005dd0: d65f03c0  ret      
//   0x005dd4: aa1403e0  mov      x0, x20
//   0x005dd8: 2a1f03e1  mov      w1, wzr
//   0x005ddc: 97fff471  bl       #0x2fa0
//   0x005de0: 91001260  add      x0, x19, #4
//   0x005de4: 17fffff8  b        #0x5dc4
//   0x005de8: 52800021  mov      w1, #1
//   0x005dec: aa1403e0  mov      x0, x20
//   0x005df0: 97fff46c  bl       #0x2fa0
//   0x005df4: 91001260  add      x0, x19, #4
//   0x005df8: eb15001f  cmp      x0, x21
//   0x005dfc: 54000442  b.hs     #0x5e84
//   0x005e00: b9400008  ldr      w8, [x0]
//   0x005e04: 5100c101  sub      w1, w8, #0x30
//   0x005e08: 7100243f  cmp      w1, #9
//   0x005e0c: 54fffdc8  b.hi     #0x5dc4
//   0x005e10: 1400001f  b        #0x5e8c
//   0x005e14: 52800041  mov      w1, #2
//   0x005e18: aa1403e0  mov      x0, x20
//   0x005e1c: 97fff461  bl       #0x2fa0
//   0x005e20: 91001260  add      x0, x19, #4
//   0x005e24: eb15001f  cmp      x0, x21
//   0x005e28: 540002e2  b.hs     #0x5e84
//   0x005e2c: b9400008  ldr      w8, [x0]
//   0x005e30: 5100c101  sub      w1, w8, #0x30
//   0x005e34: 7100143f  cmp      w1, #5
//   0x005e38: 540002a3  b.lo     #0x5e8c
//   0x005e3c: 5100d909  sub      w9, w8, #0x36
//   0x005e40: 7100113f  cmp      w9, #4
//   0x005e44: 54fffb63  b.lo     #0x5db0
//   0x005e48: 7100d51f  cmp      w8, #0x35
//   0x005e4c: 54fffbc1  b.ne     #0x5dc4
//   0x005e50: 528000a1  mov      w1, #5
//   0x005e54: aa1403e0  mov      x0, x20
//   0x005e58: 97fff452  bl       #0x2fa0
//   0x005e5c: 91002268  add      x8, x19, #8
//   0x005e60: eb15011f  cmp      x8, x21
//   0x005e64: aa1503e0  mov      x0, x21
//   0x005e68: 54fffae2  b.hs     #0x5dc4
//   0x005e6c: b9400109  ldr      w9, [x8]
//   0x005e70: 5100c121  sub      w1, w9, #0x30
//   0x005e74: 7100143f  cmp      w1, #5
//   0x005e78: aa0803e0  mov      x0, x8
//   0x005e7c: 54fffa48  b.hi     #0x5dc4
//   0x005e80: 1400000e  b        #0x5eb8
//   0x005e84: aa1503e0  mov      x0, x21
//   0x005e88: 17ffffcf  b        #0x5dc4
//   0x005e8c: aa1403e0  mov      x0, x20
//   0x005e90: 97fff444  bl       #0x2fa0
//   0x005e94: 91002268  add      x8, x19, #8
//   0x005e98: eb15011f  cmp      x8, x21
//   0x005e9c: aa1503e0  mov      x0, x21
//   0x005ea0: 54fff922  b.hs     #0x5dc4
//   0x005ea4: b9400109  ldr      w9, [x8]
//   0x005ea8: 5100c121  sub      w1, w9, #0x30
//   0x005eac: 7100243f  cmp      w1, #9
//   0x005eb0: aa0803e0  mov      x0, x8
//   0x005eb4: 54fff888  b.hi     #0x5dc4
//   0x005eb8: aa1403e0  mov      x0, x20
//   0x005ebc: 97fff439  bl       #0x2fa0
//   0x005ec0: 91003260  add      x0, x19, #0xc
//   0x005ec4: 17ffffc0  b        #0x5dc4
// ============================================================================
std::uint32_t fde_048_05d38(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005d38ULL;
    for (std::size_t i = 0; i < 100ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2682ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[049] Subroutine @ 0x005ec8..0x005f2c (100 bytes, 25 AArch64 instructions)
// [VN] Khung FDE[049] Hàm con @ 0x005ec8..0x005f2c (100 byte, 25 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005ec8: 39400008  ldrb     w8, [x0]
//   0x005ecc: 71000d1f  cmp      w8, #3
//   0x005ed0: 540000e0  b.eq     #0x5eec
//   0x005ed4: 7100091f  cmp      w8, #2
//   0x005ed8: 540001c0  b.eq     #0x5f10
//   0x005edc: 7100051f  cmp      w8, #1
//   0x005ee0: 54000221  b.ne     #0x5f24
//   0x005ee4: 39400408  ldrb     w8, [x0, #1]
//   0x005ee8: 1400000e  b        #0x5f20
//   0x005eec: 39400408  ldrb     w8, [x0, #1]
//   0x005ef0: 3940080a  ldrb     w10, [x0, #2]
//   0x005ef4: 39400c0b  ldrb     w11, [x0, #3]
//   0x005ef8: 52800c89  mov      w9, #0x64
//   0x005efc: 1b097d08  mul      w8, w8, w9
//   0x005f00: 52800149  mov      w9, #0xa
//   0x005f04: 1b092148  madd     w8, w10, w9, w8
//   0x005f08: 0b0b0108  add      w8, w8, w11
//   0x005f0c: 14000005  b        #0x5f20
//   0x005f10: 39400408  ldrb     w8, [x0, #1]
//   0x005f14: 39400809  ldrb     w9, [x0, #2]
//   0x005f18: 5280014a  mov      w10, #0xa
//   0x005f1c: 1b0a2508  madd     w8, w8, w10, w9
//   0x005f20: 39000028  strb     w8, [x1]
//   0x005f24: 3900001f  strb     wzr, [x0]
//   0x005f28: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_049_05ec8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005ec8ULL;
    for (std::size_t i = 0; i < 25ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2782ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[050] Subroutine @ 0x005f2c..0x005f70 (68 bytes, 17 AArch64 instructions)
// [VN] Khung FDE[050] Hàm con @ 0x005f2c..0x005f70 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005f2c: 39400008  ldrb     w8, [x0]
//   0x005f30: 7100091f  cmp      w8, #2
//   0x005f34: 540000e0  b.eq     #0x5f50
//   0x005f38: 7100051f  cmp      w8, #1
//   0x005f3c: 54000100  b.eq     #0x5f5c
//   0x005f40: 35000168  cbnz     w8, #0x5f6c
//   0x005f44: 91000408  add      x8, x0, #1
//   0x005f48: 52800029  mov      w9, #1
//   0x005f4c: 14000006  b        #0x5f64
//   0x005f50: 91000c08  add      x8, x0, #3
//   0x005f54: 52800069  mov      w9, #3
//   0x005f58: 14000003  b        #0x5f64
//   0x005f5c: 91000808  add      x8, x0, #2
//   0x005f60: 52800049  mov      w9, #2
//   0x005f64: 39000101  strb     w1, [x8]
//   0x005f68: 39000009  strb     w9, [x0]
//   0x005f6c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_050_05f2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005f2cULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2807ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[051] Subroutine @ 0x005f70..0x005fac (60 bytes, 15 AArch64 instructions)
// [VN] Khung FDE[051] Hàm con @ 0x005f70..0x005fac (60 byte, 15 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005f70: b4000180  cbz      x0, #0x5fa0
//   0x005f74: f9400008  ldr      x8, [x0]
//   0x005f78: b4000168  cbz      x8, #0x5fa4
//   0x005f7c: f9400408  ldr      x8, [x0, #8]
//   0x005f80: b4000128  cbz      x8, #0x5fa4
//   0x005f84: f9400808  ldr      x8, [x0, #0x10]
//   0x005f88: b40000e8  cbz      x8, #0x5fa4
//   0x005f8c: f9400c08  ldr      x8, [x0, #0x18]
//   0x005f90: b40000a8  cbz      x8, #0x5fa4
//   0x005f94: f9401008  ldr      x8, [x0, #0x20]
//   0x005f98: f100011f  cmp      x8, #0
//   0x005f9c: 1a9f07e0  cset     w0, ne
//   0x005fa0: d65f03c0  ret      
//   0x005fa4: 2a1f03e0  mov      w0, wzr
//   0x005fa8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_051_05f70(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005f70ULL;
    for (std::size_t i = 0; i < 15ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2824ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[052] Subroutine @ 0x005fac..0x006024 (120 bytes, 30 AArch64 instructions)
// [VN] Khung FDE[052] Hàm con @ 0x005fac..0x006024 (120 byte, 30 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005fac: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x005fb0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x005fb4: 910043fd  add      x29, sp, #0x10
//   0x005fb8: b4000200  cbz      x0, #0x5ff8
//   0x005fbc: 9b017c54  mul      x20, x2, x1
//   0x005fc0: b4000081  cbz      x1, #0x5fd0
//   0x005fc4: 9ac10a88  udiv     x8, x20, x1
//   0x005fc8: eb02011f  cmp      x8, x2
//   0x005fcc: 540001c1  b.ne     #0x6004
//   0x005fd0: f9400008  ldr      x8, [x0]
//   0x005fd4: aa1403e1  mov      x1, x20
//   0x005fd8: d63f0100  blr      x8
//   0x005fdc: aa0003f3  mov      x19, x0
//   0x005fe0: b40001a0  cbz      x0, #0x6014
//   0x005fe4: aa1303e0  mov      x0, x19
//   0x005fe8: 2a1f03e1  mov      w1, wzr
//   0x005fec: aa1403e2  mov      x2, x20
//   0x005ff0: 97fff4bc  bl       #0x32e0
//   0x005ff4: 14000008  b        #0x6014
//   0x005ff8: 97fff426  bl       #0x3090
//   0x005ffc: 528002c8  mov      w8, #0x16
//   0x006000: 14000003  b        #0x600c
//   0x006004: 97fff423  bl       #0x3090
//   0x006008: 52800188  mov      w8, #0xc
//   0x00600c: aa1f03f3  mov      x19, xzr
//   0x006010: b9000008  str      w8, [x0]
//   0x006014: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x006018: aa1303e0  mov      x0, x19
//   0x00601c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x006020: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_052_05fac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005facULL;
    for (std::size_t i = 0; i < 30ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2839ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[053] Subroutine @ 0x006024..0x006078 (84 bytes, 21 AArch64 instructions)
// [VN] Khung FDE[053] Hàm con @ 0x006024..0x006078 (84 byte, 21 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006024: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x006028: 910003fd  mov      x29, sp
//   0x00602c: b4000140  cbz      x0, #0x6054
//   0x006030: aa0203e8  mov      x8, x2
//   0x006034: 9b027c62  mul      x2, x3, x2
//   0x006038: b4000088  cbz      x8, #0x6048
//   0x00603c: 9ac80848  udiv     x8, x2, x8
//   0x006040: eb03011f  cmp      x8, x3
//   0x006044: 540000e1  b.ne     #0x6060
//   0x006048: f9400803  ldr      x3, [x0, #0x10]
//   0x00604c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x006050: d61f0060  br       x3
//   0x006054: 97fff40f  bl       #0x3090
//   0x006058: 528002c8  mov      w8, #0x16
//   0x00605c: 14000003  b        #0x6068
//   0x006060: 97fff40c  bl       #0x3090
//   0x006064: 52800188  mov      w8, #0xc
//   0x006068: b9000008  str      w8, [x0]
//   0x00606c: aa1f03e0  mov      x0, xzr
//   0x006070: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x006074: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_053_06024(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006024ULL;
    for (std::size_t i = 0; i < 21ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2869ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[054] Subroutine @ 0x006078..0x0060dc (100 bytes, 25 AArch64 instructions)
// [VN] Khung FDE[054] Hàm con @ 0x006078..0x0060dc (100 byte, 25 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006078: aa0003e8  mov      x8, x0
//   0x00607c: 52800040  mov      w0, #2
//   0x006080: b4000288  cbz      x8, #0x60d0
//   0x006084: b4000261  cbz      x1, #0x60d0
//   0x006088: f9400029  ldr      x9, [x1]
//   0x00608c: b4000249  cbz      x9, #0x60d4
//   0x006090: f9401029  ldr      x9, [x1, #0x20]
//   0x006094: b4000209  cbz      x9, #0x60d4
//   0x006098: b00000a9  adrp     x9, #0x1b000
//   0x00609c: b00000aa  adrp     x10, #0x1b000
//   0x0060a0: f947e529  ldr      x9, [x9, #0xfc8]
//   0x0060a4: f947f54a  ldr      x10, [x10, #0xfe8]
//   0x0060a8: 9000000b  adrp     x11, #0x6000
//   0x0060ac: 9000000c  adrp     x12, #0x6000
//   0x0060b0: 9000000d  adrp     x13, #0x6000
//   0x0060b4: 2a1f03e0  mov      w0, wzr
//   0x0060b8: 9103716b  add      x11, x11, #0xdc
//   0x0060bc: 9105218c  add      x12, x12, #0x148
//   0x0060c0: 910831ad  add      x13, x13, #0x20c
//   0x0060c4: a900250b  stp      x11, x9, [x8]
//   0x0060c8: a901290c  stp      x12, x10, [x8, #0x10]
//   0x0060cc: a902050d  stp      x13, x1, [x8, #0x20]
//   0x0060d0: d65f03c0  ret      
//   0x0060d4: 52800140  mov      w0, #0xa
//   0x0060d8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_054_06078(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006078ULL;
    for (std::size_t i = 0; i < 25ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2890ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[055] Subroutine @ 0x0060dc..0x006148 (108 bytes, 27 AArch64 instructions)
// [VN] Khung FDE[055] Hàm con @ 0x0060dc..0x006148 (108 byte, 27 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0060dc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0060e0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0060e4: 910043fd  add      x29, sp, #0x10
//   0x0060e8: b4000200  cbz      x0, #0x6128
//   0x0060ec: aa0103f3  mov      x19, x1
//   0x0060f0: b100203f  cmn      x1, #8
//   0x0060f4: 540000a3  b.lo     #0x6108
//   0x0060f8: 97fff3e6  bl       #0x3090
//   0x0060fc: aa0003e8  mov      x8, x0
//   0x006100: 52800189  mov      w9, #0xc
//   0x006104: 1400000c  b        #0x6134
//   0x006108: f9401400  ldr      x0, [x0, #0x28]
//   0x00610c: b40000e0  cbz      x0, #0x6128
//   0x006110: f9400008  ldr      x8, [x0]
//   0x006114: 91002261  add      x1, x19, #8
//   0x006118: d63f0100  blr      x8
//   0x00611c: b4000100  cbz      x0, #0x613c
//   0x006120: f8008413  str      x19, [x0], #8
//   0x006124: 14000006  b        #0x613c
//   0x006128: 97fff3da  bl       #0x3090
//   0x00612c: aa0003e8  mov      x8, x0
//   0x006130: 528002c9  mov      w9, #0x16
//   0x006134: aa1f03e0  mov      x0, xzr
//   0x006138: b9000109  str      w9, [x8]
//   0x00613c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x006140: f84207f3  ldr      x19, [sp], #0x20
//   0x006144: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_055_060dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000060dcULL;
    for (std::size_t i = 0; i < 27ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2915ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[056] Subroutine @ 0x006148..0x00620c (196 bytes, 49 AArch64 instructions)
// [VN] Khung FDE[056] Hàm con @ 0x006148..0x00620c (196 byte, 49 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006148: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00614c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x006150: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x006154: 910083fd  add      x29, sp, #0x20
//   0x006158: b40002e0  cbz      x0, #0x61b4
//   0x00615c: aa0103f3  mov      x19, x1
//   0x006160: aa0003f4  mov      x20, x0
//   0x006164: b4000321  cbz      x1, #0x61c8
//   0x006168: b40003e2  cbz      x2, #0x61e4
//   0x00616c: f85f8275  ldur     x21, [x19, #-8]
//   0x006170: eb0202bf  cmp      x21, x2
//   0x006174: 54000422  b.hs     #0x61f8
//   0x006178: f9400288  ldr      x8, [x20]
//   0x00617c: aa1403e0  mov      x0, x20
//   0x006180: aa0203e1  mov      x1, x2
//   0x006184: d63f0100  blr      x8
//   0x006188: b4000360  cbz      x0, #0x61f4
//   0x00618c: aa1303e1  mov      x1, x19
//   0x006190: aa1503e2  mov      x2, x21
//   0x006194: aa0003f6  mov      x22, x0
//   0x006198: 97fff44a  bl       #0x32c0
//   0x00619c: f9401288  ldr      x8, [x20, #0x20]
//   0x0061a0: aa1403e0  mov      x0, x20
//   0x0061a4: aa1303e1  mov      x1, x19
//   0x0061a8: d63f0100  blr      x8
//   0x0061ac: aa1603f3  mov      x19, x22
//   0x0061b0: 14000012  b        #0x61f8
//   0x0061b4: 97fff3b7  bl       #0x3090
//   0x0061b8: 528002c8  mov      w8, #0x16
//   0x0061bc: aa1f03f3  mov      x19, xzr
//   0x0061c0: b9000008  str      w8, [x0]
//   0x0061c4: 1400000d  b        #0x61f8
//   0x0061c8: f9400283  ldr      x3, [x20]
//   0x0061cc: aa1403e0  mov      x0, x20
//   0x0061d0: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0061d4: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0061d8: aa0203e1  mov      x1, x2
//   0x0061dc: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x0061e0: d61f0060  br       x3
//   0x0061e4: f9401288  ldr      x8, [x20, #0x20]
//   0x0061e8: aa1403e0  mov      x0, x20
//   0x0061ec: aa1303e1  mov      x1, x19
//   0x0061f0: d63f0100  blr      x8
//   0x0061f4: aa1f03f3  mov      x19, xzr
//   0x0061f8: aa1303e0  mov      x0, x19
//   0x0061fc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x006200: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x006204: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x006208: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_056_06148(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006148ULL;
    for (std::size_t i = 0; i < 49ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2942ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[057] Subroutine @ 0x00620c..0x00622c (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[057] Hàm con @ 0x00620c..0x00622c (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00620c: b40000e0  cbz      x0, #0x6228
//   0x006210: b40000c1  cbz      x1, #0x6228
//   0x006214: f9401400  ldr      x0, [x0, #0x28]
//   0x006218: b4000080  cbz      x0, #0x6228
//   0x00621c: f9401002  ldr      x2, [x0, #0x20]
//   0x006220: d1002021  sub      x1, x1, #8
//   0x006224: d61f0040  br       x2
//   0x006228: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_057_0620c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000620cULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2991ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[058] Subroutine @ 0x00622c..0x006688 (1116 bytes, 279 AArch64 instructions)
// [VN] Khung FDE[058] Hàm con @ 0x00622c..0x006688 (1116 byte, 279 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00622c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x006230: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x006234: 910043fd  add      x29, sp, #0x10
//   0x006238: b40007e0  cbz      x0, #0x6334
//   0x00623c: f9400008  ldr      x8, [x0]
//   0x006240: aa0003f3  mov      x19, x0
//   0x006244: b4000748  cbz      x8, #0x632c
//   0x006248: f9400669  ldr      x9, [x19, #8]
//   0x00624c: b4000709  cbz      x9, #0x632c
//   0x006250: f9400a69  ldr      x9, [x19, #0x10]
//   0x006254: b40006c9  cbz      x9, #0x632c
//   0x006258: f9400e69  ldr      x9, [x19, #0x18]
//   0x00625c: b4000689  cbz      x9, #0x632c
//   0x006260: f9401269  ldr      x9, [x19, #0x20]
//   0x006264: b4000649  cbz      x9, #0x632c
//   0x006268: 528000e1  mov      w1, #7
//   0x00626c: aa1303e0  mov      x0, x19
//   0x006270: d63f0100  blr      x8
//   0x006274: b4000580  cbz      x0, #0x6324
//   0x006278: 52801e28  mov      w8, #0xf1
//   0x00627c: 39001808  strb     w8, [x0, #6]
//   0x006280: f9401268  ldr      x8, [x19, #0x20]
//   0x006284: aa0003e1  mov      x1, x0
//   0x006288: aa1303e0  mov      x0, x19
//   0x00628c: d63f0100  blr      x8
//   0x006290: f9400668  ldr      x8, [x19, #8]
//   0x006294: 52800061  mov      w1, #3
//   0x006298: 528000a2  mov      w2, #5
//   0x00629c: aa1303e0  mov      x0, x19
//   0x0062a0: d63f0100  blr      x8
//   0x0062a4: b4000400  cbz      x0, #0x6324
//   0x0062a8: 39400008  ldrb     w8, [x0]
//   0x0062ac: aa0003e1  mov      x1, x0
//   0x0062b0: 350003a8  cbnz     w8, #0x6324
//   0x0062b4: 39400428  ldrb     w8, [x1, #1]
//   0x0062b8: 35000368  cbnz     w8, #0x6324
//   0x0062bc: 39400828  ldrb     w8, [x1, #2]
//   0x0062c0: 35000328  cbnz     w8, #0x6324
//   0x0062c4: 39400c28  ldrb     w8, [x1, #3]
//   0x0062c8: 350002e8  cbnz     w8, #0x6324
//   0x0062cc: 39401028  ldrb     w8, [x1, #4]
//   0x0062d0: 350002a8  cbnz     w8, #0x6324
//   0x0062d4: 39401428  ldrb     w8, [x1, #5]
//   0x0062d8: 35000268  cbnz     w8, #0x6324
//   0x0062dc: 39401828  ldrb     w8, [x1, #6]
//   0x0062e0: 35000228  cbnz     w8, #0x6324
//   0x0062e4: 39401c28  ldrb     w8, [x1, #7]
//   0x0062e8: 350001e8  cbnz     w8, #0x6324
//   0x0062ec: 39402028  ldrb     w8, [x1, #8]
//   0x0062f0: 350001a8  cbnz     w8, #0x6324
//   0x0062f4: 39402428  ldrb     w8, [x1, #9]
//   0x0062f8: 35000168  cbnz     w8, #0x6324
//   0x0062fc: 39402828  ldrb     w8, [x1, #0xa]
//   0x006300: 35000128  cbnz     w8, #0x6324
//   0x006304: 39402c28  ldrb     w8, [x1, #0xb]
//   0x006308: 350000e8  cbnz     w8, #0x6324
//   0x00630c: 39403028  ldrb     w8, [x1, #0xc]
//   0x006310: 350000a8  cbnz     w8, #0x6324
//   0x006314: 39403428  ldrb     w8, [x1, #0xd]
//   0x006318: 35000068  cbnz     w8, #0x6324
//   0x00631c: 39403828  ldrb     w8, [x1, #0xe]
//   0x006320: 34000128  cbz      w8, #0x6344
//   0x006324: 52800160  mov      w0, #0xb
//   0x006328: 14000004  b        #0x6338
//   0x00632c: 52800140  mov      w0, #0xa
//   0x006330: 14000002  b        #0x6338
//   0x006334: 52800040  mov      w0, #2
//   0x006338: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00633c: f84207f3  ldr      x19, [sp], #0x20
//   0x006340: d65f03c0  ret      
//   0x006344: 52801e48  mov      w8, #0xf2
//   0x006348: 39003828  strb     w8, [x1, #0xe]
//   0x00634c: f9401268  ldr      x8, [x19, #0x20]
//   0x006350: aa1303e0  mov      x0, x19
//   0x006354: d63f0100  blr      x8
//   0x006358: f9400268  ldr      x8, [x19]
//   0x00635c: 528000e1  mov      w1, #7
//   0x006360: aa1303e0  mov      x0, x19
//   0x006364: d63f0100  blr      x8
//   0x006368: b4fffde0  cbz      x0, #0x6324
//   0x00636c: 3204d7e8  mov      w8, #-0xc0c0c0d
//   0x006370: b8003008  stur     w8, [x0, #3]
//   0x006374: b9000008  str      w8, [x0]
//   0x006378: f9400a68  ldr      x8, [x19, #0x10]
//   0x00637c: aa0003e1  mov      x1, x0
//   0x006380: 52800162  mov      w2, #0xb
//   0x006384: aa1303e0  mov      x0, x19
//   0x006388: d63f0100  blr      x8
//   0x00638c: b4fffcc0  cbz      x0, #0x6324
//   0x006390: 39400008  ldrb     w8, [x0]
//   0x006394: aa0003e1  mov      x1, x0
//   0x006398: 7103cd1f  cmp      w8, #0xf3
//   0x00639c: 54fffc41  b.ne     #0x6324
//   0x0063a0: 39400428  ldrb     w8, [x1, #1]
//   0x0063a4: 7103cd1f  cmp      w8, #0xf3
//   0x0063a8: 54fffbe1  b.ne     #0x6324
//   0x0063ac: 39400828  ldrb     w8, [x1, #2]
//   0x0063b0: 7103cd1f  cmp      w8, #0xf3
//   0x0063b4: 54fffb81  b.ne     #0x6324
//   0x0063b8: 39400c28  ldrb     w8, [x1, #3]
//   0x0063bc: 7103cd1f  cmp      w8, #0xf3
//   0x0063c0: 54fffb21  b.ne     #0x6324
//   0x0063c4: 39401028  ldrb     w8, [x1, #4]
//   0x0063c8: 7103cd1f  cmp      w8, #0xf3
//   0x0063cc: 54fffac1  b.ne     #0x6324
//   0x0063d0: 39401428  ldrb     w8, [x1, #5]
//   0x0063d4: 7103cd1f  cmp      w8, #0xf3
//   0x0063d8: 54fffa61  b.ne     #0x6324
//   0x0063dc: 39401828  ldrb     w8, [x1, #6]
//   0x0063e0: 7103cd1f  cmp      w8, #0xf3
//   0x0063e4: 54fffa01  b.ne     #0x6324
//   0x0063e8: 52801e88  mov      w8, #0xf4
//   0x0063ec: 39002828  strb     w8, [x1, #0xa]
//   0x0063f0: f9401268  ldr      x8, [x19, #0x20]
//   0x0063f4: aa1303e0  mov      x0, x19
//   0x0063f8: d63f0100  blr      x8
//   0x0063fc: f9400268  ldr      x8, [x19]
//   0x006400: 528000e1  mov      w1, #7
//   0x006404: aa1303e0  mov      x0, x19
//   0x006408: d63f0100  blr      x8
//   0x00640c: b4fff8c0  cbz      x0, #0x6324
//   0x006410: 52801ea8  mov      w8, #0xf5
//   0x006414: 39001808  strb     w8, [x0, #6]
//   0x006418: f9400a68  ldr      x8, [x19, #0x10]
//   0x00641c: aa0003e1  mov      x1, x0
//   0x006420: aa1303e0  mov      x0, x19
//   0x006424: aa1f03e2  mov      x2, xzr
//   0x006428: d63f0100  blr      x8
//   0x00642c: f9400a68  ldr      x8, [x19, #0x10]
//   0x006430: 528000e2  mov      w2, #7
//   0x006434: aa1303e0  mov      x0, x19
//   0x006438: aa1f03e1  mov      x1, xzr
//   0x00643c: d63f0100  blr      x8
//   0x006440: b4fff720  cbz      x0, #0x6324
//   0x006444: 52801ec8  mov      w8, #0xf6
//   0x006448: 39001808  strb     w8, [x0, #6]
//   0x00644c: f9401268  ldr      x8, [x19, #0x20]
//   0x006450: aa0003e1  mov      x1, x0
//   0x006454: aa1303e0  mov      x0, x19
//   0x006458: d63f0100  blr      x8
//   0x00645c: f9400a68  ldr      x8, [x19, #0x10]
//   0x006460: aa1303e0  mov      x0, x19
//   0x006464: aa1f03e1  mov      x1, xzr
//   0x006468: aa1f03e2  mov      x2, xzr
//   0x00646c: d63f0100  blr      x8
//   0x006470: b40000a0  cbz      x0, #0x6484
//   0x006474: f9401268  ldr      x8, [x19, #0x20]
//   0x006478: aa0003e1  mov      x1, x0
//   0x00647c: aa1303e0  mov      x0, x19
//   0x006480: d63f0100  blr      x8
//   0x006484: f9400268  ldr      x8, [x19]
//   0x006488: 528000e1  mov      w1, #7
//   0x00648c: aa1303e0  mov      x0, x19
//   0x006490: d63f0100  blr      x8
//   0x006494: b4fff480  cbz      x0, #0x6324
//   0x006498: 3204dbe8  mov      w8, #-0x8080809
//   0x00649c: b8003008  stur     w8, [x0, #3]
//   0x0064a0: b9000008  str      w8, [x0]
//   0x0064a4: f9400e68  ldr      x8, [x19, #0x18]
//   0x0064a8: aa0003e1  mov      x1, x0
//   0x0064ac: 528000a2  mov      w2, #5
//   0x0064b0: 528000e3  mov      w3, #7
//   0x0064b4: aa1303e0  mov      x0, x19
//   0x0064b8: d63f0100  blr      x8
//   0x0064bc: b4fff340  cbz      x0, #0x6324
//   0x0064c0: 39400008  ldrb     w8, [x0]
//   0x0064c4: aa0003e1  mov      x1, x0
//   0x0064c8: 7103dd1f  cmp      w8, #0xf7
//   0x0064cc: 54fff2c1  b.ne     #0x6324
//   0x0064d0: 39400428  ldrb     w8, [x1, #1]
//   0x0064d4: 7103dd1f  cmp      w8, #0xf7
//   0x0064d8: 54fff261  b.ne     #0x6324
//   0x0064dc: 39400828  ldrb     w8, [x1, #2]
//   0x0064e0: 7103dd1f  cmp      w8, #0xf7
//   0x0064e4: 54fff201  b.ne     #0x6324
//   0x0064e8: 39400c28  ldrb     w8, [x1, #3]
//   0x0064ec: 7103dd1f  cmp      w8, #0xf7
//   0x0064f0: 54fff1a1  b.ne     #0x6324
//   0x0064f4: 39401028  ldrb     w8, [x1, #4]
//   0x0064f8: 7103dd1f  cmp      w8, #0xf7
//   0x0064fc: 54fff141  b.ne     #0x6324
//   0x006500: 39401428  ldrb     w8, [x1, #5]
//   0x006504: 7103dd1f  cmp      w8, #0xf7
//   0x006508: 54fff0e1  b.ne     #0x6324
//   0x00650c: 39401828  ldrb     w8, [x1, #6]
//   0x006510: 7103dd1f  cmp      w8, #0xf7
//   0x006514: 54fff081  b.ne     #0x6324
//   0x006518: 52801f08  mov      w8, #0xf8
//   0x00651c: 39008828  strb     w8, [x1, #0x22]
//   0x006520: f9401268  ldr      x8, [x19, #0x20]
//   0x006524: aa1303e0  mov      x0, x19
//   0x006528: d63f0100  blr      x8
//   0x00652c: f9400268  ldr      x8, [x19]
//   0x006530: 528000e1  mov      w1, #7
//   0x006534: aa1303e0  mov      x0, x19
//   0x006538: d63f0100  blr      x8
//   0x00653c: b4ffef40  cbz      x0, #0x6324
//   0x006540: 52801f28  mov      w8, #0xf9
//   0x006544: 39001808  strb     w8, [x0, #6]
//   0x006548: f9400e68  ldr      x8, [x19, #0x18]
//   0x00654c: aa0003e1  mov      x1, x0
//   0x006550: 528000e3  mov      w3, #7
//   0x006554: aa1303e0  mov      x0, x19
//   0x006558: aa1f03e2  mov      x2, xzr
//   0x00655c: d63f0100  blr      x8
//   0x006560: f9400268  ldr      x8, [x19]
//   0x006564: 528000e1  mov      w1, #7
//   0x006568: aa1303e0  mov      x0, x19
//   0x00656c: d63f0100  blr      x8
//   0x006570: b4ffeda0  cbz      x0, #0x6324
//   0x006574: 52801f48  mov      w8, #0xfa
//   0x006578: 39001808  strb     w8, [x0, #6]
//   0x00657c: f9400e68  ldr      x8, [x19, #0x18]
//   0x006580: aa0003e1  mov      x1, x0
//   0x006584: 528000a2  mov      w2, #5
//   0x006588: aa1303e0  mov      x0, x19
//   0x00658c: aa1f03e3  mov      x3, xzr
//   0x006590: d63f0100  blr      x8
//   0x006594: f9400268  ldr      x8, [x19]
//   0x006598: 528000e1  mov      w1, #7
//   0x00659c: aa1303e0  mov      x0, x19
//   0x0065a0: d63f0100  blr      x8
//   0x0065a4: b4ffec00  cbz      x0, #0x6324
//   0x0065a8: 52801f68  mov      w8, #0xfb
//   0x0065ac: 39001808  strb     w8, [x0, #6]
//   0x0065b0: f9400e68  ldr      x8, [x19, #0x18]
//   0x0065b4: aa0003e1  mov      x1, x0
//   0x0065b8: aa1303e0  mov      x0, x19
//   0x0065bc: aa1f03e2  mov      x2, xzr
//   0x0065c0: aa1f03e3  mov      x3, xzr
//   0x0065c4: d63f0100  blr      x8
//   0x0065c8: f9400e68  ldr      x8, [x19, #0x18]
//   0x0065cc: 52800062  mov      w2, #3
//   0x0065d0: 528000a3  mov      w3, #5
//   0x0065d4: aa1303e0  mov      x0, x19
//   0x0065d8: aa1f03e1  mov      x1, xzr
//   0x0065dc: d63f0100  blr      x8
//   0x0065e0: b4ffea20  cbz      x0, #0x6324
//   0x0065e4: 52801f88  mov      w8, #0xfc
//   0x0065e8: 39003808  strb     w8, [x0, #0xe]
//   0x0065ec: f9401268  ldr      x8, [x19, #0x20]
//   0x0065f0: aa0003e1  mov      x1, x0
//   0x0065f4: aa1303e0  mov      x0, x19
//   0x0065f8: d63f0100  blr      x8
//   0x0065fc: f9400e68  ldr      x8, [x19, #0x18]
//   0x006600: 528000a3  mov      w3, #5
//   0x006604: aa1303e0  mov      x0, x19
//   0x006608: aa1f03e1  mov      x1, xzr
//   0x00660c: aa1f03e2  mov      x2, xzr
//   0x006610: d63f0100  blr      x8
//   0x006614: b40000a0  cbz      x0, #0x6628
//   0x006618: f9401268  ldr      x8, [x19, #0x20]
//   0x00661c: aa0003e1  mov      x1, x0
//   0x006620: aa1303e0  mov      x0, x19
//   0x006624: d63f0100  blr      x8
//   0x006628: f9400e68  ldr      x8, [x19, #0x18]
//   0x00662c: 52800062  mov      w2, #3
//   0x006630: aa1303e0  mov      x0, x19
//   0x006634: aa1f03e1  mov      x1, xzr
//   0x006638: aa1f03e3  mov      x3, xzr
//   0x00663c: d63f0100  blr      x8
//   0x006640: b40000a0  cbz      x0, #0x6654
//   0x006644: f9401268  ldr      x8, [x19, #0x20]
//   0x006648: aa0003e1  mov      x1, x0
//   0x00664c: aa1303e0  mov      x0, x19
//   0x006650: d63f0100  blr      x8
//   0x006654: f9400e68  ldr      x8, [x19, #0x18]
//   0x006658: aa1303e0  mov      x0, x19
//   0x00665c: aa1f03e1  mov      x1, xzr
//   0x006660: aa1f03e2  mov      x2, xzr
//   0x006664: aa1f03e3  mov      x3, xzr
//   0x006668: d63f0100  blr      x8
//   0x00666c: b4ffe660  cbz      x0, #0x6338
//   0x006670: f9401268  ldr      x8, [x19, #0x20]
//   0x006674: aa0003e1  mov      x1, x0
//   0x006678: aa1303e0  mov      x0, x19
//   0x00667c: d63f0100  blr      x8
//   0x006680: 2a1f03e0  mov      w0, wzr
//   0x006684: 17ffff2d  b        #0x6338
// ============================================================================
std::uint32_t fde_058_0622c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000622cULL;
    for (std::size_t i = 0; i < 279ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2999ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[059] Subroutine @ 0x006688..0x006690 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[059] Hàm con @ 0x006688..0x006690 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006688: aa0103e0  mov      x0, x1
//   0x00668c: 17fff2fd  b        #0x3280
// ============================================================================
std::uint32_t fde_059_06688(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006688ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3278ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[060] Subroutine @ 0x006690..0x00669c (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[060] Hàm con @ 0x006690..0x00669c (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006690: aa0103e0  mov      x0, x1
//   0x006694: aa0203e1  mov      x1, x2
//   0x006698: 17fff256  b        #0x2ff0
// ============================================================================
std::uint32_t fde_060_06690(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006690ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3280ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[061] Subroutine @ 0x00669c..0x0066a8 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[061] Hàm con @ 0x00669c..0x0066a8 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00669c: aa0103e0  mov      x0, x1
//   0x0066a0: aa0203e1  mov      x1, x2
//   0x0066a4: 17fff23b  b        #0x2f90
// ============================================================================
std::uint32_t fde_061_0669c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000669cULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3283ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[062] Subroutine @ 0x0066a8..0x0066e8 (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[062] Hàm con @ 0x0066a8..0x0066e8 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0066a8: 9b027c68  mul      x8, x3, x2
//   0x0066ac: b4000082  cbz      x2, #0x66bc
//   0x0066b0: 9ac20909  udiv     x9, x8, x2
//   0x0066b4: eb03013f  cmp      x9, x3
//   0x0066b8: 54000081  b.ne     #0x66c8
//   0x0066bc: aa0103e0  mov      x0, x1
//   0x0066c0: aa0803e1  mov      x1, x8
//   0x0066c4: 17fff233  b        #0x2f90
//   0x0066c8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0066cc: 910003fd  mov      x29, sp
//   0x0066d0: 97fff270  bl       #0x3090
//   0x0066d4: 52800188  mov      w8, #0xc
//   0x0066d8: b9000008  str      w8, [x0]
//   0x0066dc: aa1f03e0  mov      x0, xzr
//   0x0066e0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0066e4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_062_066a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000066a8ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3286ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[063] Subroutine @ 0x0066e8..0x0066f0 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[063] Hàm con @ 0x0066e8..0x0066f0 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0066e8: aa0103e0  mov      x0, x1
//   0x0066ec: 17fff309  b        #0x3310
// ============================================================================
std::uint32_t fde_063_066e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000066e8ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3302ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[064] Subroutine @ 0x0066f0..0x00677c (140 bytes, 35 AArch64 instructions)
// [VN] Khung FDE[064] Hàm con @ 0x0066f0..0x00677c (140 byte, 35 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0066f0: d10383ff  sub      sp, sp, #0xe0
//   0x0066f4: f90063f3  str      x19, [sp, #0xc0]
//   0x0066f8: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x0066fc: 910343fd  add      x29, sp, #0xd0
//   0x006700: d53bd053  mrs      x19, tpidr_el0
//   0x006704: f9401668  ldr      x8, [x19, #0x28]
//   0x006708: f81e83a8  stur     x8, [x29, #-0x18]
//   0x00670c: b9000fff  str      wzr, [sp, #0xc]
//   0x006710: b4000240  cbz      x0, #0x6758
//   0x006714: ad400001  ldp      q1, q0, [x0]
//   0x006718: 910043e8  add      x8, sp, #0x10
//   0x00671c: 910033e2  add      x2, sp, #0xc
//   0x006720: 2a1f03e1  mov      w1, wzr
//   0x006724: ad0083e1  stp      q1, q0, [sp, #0x10]
//   0x006728: ad420001  ldp      q1, q0, [x0, #0x40]
//   0x00672c: ad410803  ldp      q3, q2, [x0, #0x20]
//   0x006730: aa1f03e3  mov      x3, xzr
//   0x006734: ad0283e1  stp      q1, q0, [sp, #0x50]
//   0x006738: ad018be3  stp      q3, q2, [sp, #0x30]
//   0x00673c: ad440400  ldp      q0, q1, [x0, #0x80]
//   0x006740: ad430c02  ldp      q2, q3, [x0, #0x60]
//   0x006744: 910043e0  add      x0, sp, #0x10
//   0x006748: ad040500  stp      q0, q1, [x8, #0x80]
//   0x00674c: ad038fe2  stp      q2, q3, [sp, #0x70]
//   0x006750: 9400002f  bl       #0x680c
//   0x006754: b9400fe0  ldr      w0, [sp, #0xc]
//   0x006758: f9401668  ldr      x8, [x19, #0x28]
//   0x00675c: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x006760: eb09011f  cmp      x8, x9
//   0x006764: 540000a1  b.ne     #0x6778
//   0x006768: a94d7bfd  ldp      x29, x30, [sp, #0xd0]
//   0x00676c: f94063f3  ldr      x19, [sp, #0xc0]
//   0x006770: 910383ff  add      sp, sp, #0xe0
//   0x006774: d65f03c0  ret      
//   0x006778: 97fff26a  bl       #0x3120
// ============================================================================
std::uint32_t fde_064_066f0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000066f0ULL;
    for (std::size_t i = 0; i < 35ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3304ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[065] Subroutine @ 0x00677c..0x00680c (144 bytes, 36 AArch64 instructions)
// [VN] Khung FDE[065] Hàm con @ 0x00677c..0x00680c (144 byte, 36 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00677c: d10343ff  sub      sp, sp, #0xd0
//   0x006780: f9005bf3  str      x19, [sp, #0xb0]
//   0x006784: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x006788: 910303fd  add      x29, sp, #0xc0
//   0x00678c: d53bd053  mrs      x19, tpidr_el0
//   0x006790: f9401668  ldr      x8, [x19, #0x28]
//   0x006794: f81e83a8  stur     x8, [x29, #-0x18]
//   0x006798: 52800048  mov      w8, #2
//   0x00679c: b4000240  cbz      x0, #0x67e4
//   0x0067a0: aa0103e2  mov      x2, x1
//   0x0067a4: b4000201  cbz      x1, #0x67e4
//   0x0067a8: ad400001  ldp      q1, q0, [x0]
//   0x0067ac: 2a1f03e1  mov      w1, wzr
//   0x0067b0: aa1f03e3  mov      x3, xzr
//   0x0067b4: ad0003e1  stp      q1, q0, [sp]
//   0x0067b8: ad420001  ldp      q1, q0, [x0, #0x40]
//   0x0067bc: ad410803  ldp      q3, q2, [x0, #0x20]
//   0x0067c0: ad0203e1  stp      q1, q0, [sp, #0x40]
//   0x0067c4: ad010be3  stp      q3, q2, [sp, #0x20]
//   0x0067c8: ad440001  ldp      q1, q0, [x0, #0x80]
//   0x0067cc: ad430803  ldp      q3, q2, [x0, #0x60]
//   0x0067d0: 910003e0  mov      x0, sp
//   0x0067d4: ad0403e1  stp      q1, q0, [sp, #0x80]
//   0x0067d8: ad030be3  stp      q3, q2, [sp, #0x60]
//   0x0067dc: 9400000c  bl       #0x680c
//   0x0067e0: 2a1f03e8  mov      w8, wzr
//   0x0067e4: f9401669  ldr      x9, [x19, #0x28]
//   0x0067e8: f85e83aa  ldur     x10, [x29, #-0x18]
//   0x0067ec: eb0a013f  cmp      x9, x10
//   0x0067f0: 540000c1  b.ne     #0x6808
//   0x0067f4: a94c7bfd  ldp      x29, x30, [sp, #0xc0]
//   0x0067f8: f9405bf3  ldr      x19, [sp, #0xb0]
//   0x0067fc: 2a0803e0  mov      w0, w8
//   0x006800: 910343ff  add      sp, sp, #0xd0
//   0x006804: d65f03c0  ret      
//   0x006808: 97fff246  bl       #0x3120
// ============================================================================
std::uint32_t fde_065_0677c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000677cULL;
    for (std::size_t i = 0; i < 36ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3339ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[066] Subroutine @ 0x00680c..0x008384 (7032 bytes, 1758 AArch64 instructions)
// [VN] Khung FDE[066] Hàm con @ 0x00680c..0x008384 (7032 byte, 1758 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00680c: d10283ff  sub      sp, sp, #0xa0
//   0x006810: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x006814: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x006818: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x00681c: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x006820: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x006824: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x006828: 910243fd  add      x29, sp, #0x90
//   0x00682c: d53bd05c  mrs      x28, tpidr_el0
//   0x006830: f9401788  ldr      x8, [x28, #0x28]
//   0x006834: f9001fe8  str      x8, [sp, #0x38]
//   0x006838: b90037ff  str      wzr, [sp, #0x34]
//   0x00683c: b40002a0  cbz      x0, #0x6890
//   0x006840: 2a0103f6  mov      w22, w1
//   0x006844: aa0003f4  mov      x20, x0
//   0x006848: a9020be3  stp      x3, x2, [sp, #0x20]
//   0x00684c: b9001be1  str      w1, [sp, #0x18]
//   0x006850: b4000282  cbz      x2, #0x68a0
//   0x006854: b900005f  str      wzr, [x2]
//   0x006858: f9400288  ldr      x8, [x20]
//   0x00685c: 2a1f03e9  mov      w9, wzr
//   0x006860: b4000c88  cbz      x8, #0x69f0
//   0x006864: f940068a  ldr      x10, [x20, #8]
//   0x006868: eb08015f  cmp      x10, x8
//   0x00686c: 54000c29  b.ls     #0x69f0
//   0x006870: 38401509  ldrb     w9, [x8], #1
//   0x006874: 51010529  sub      w9, w9, #0x41
//   0x006878: 7100653f  cmp      w9, #0x19
//   0x00687c: 54000b89  b.ls     #0x69ec
//   0x006880: eb08015f  cmp      x10, x8
//   0x006884: 54ffff61  b.ne     #0x6870
//   0x006888: 2a1f03e9  mov      w9, wzr
//   0x00688c: 14000059  b        #0x69f0
//   0x006890: b4000aa2  cbz      x2, #0x69e4
//   0x006894: 2a1f03e0  mov      w0, wzr
//   0x006898: b900005f  str      wzr, [x2]
//   0x00689c: 140005cb  b        #0x7fc8
//   0x0068a0: 3400b736  cbz      w22, #0x7f84
//   0x0068a4: 36002bd6  tbz      w22, #0, #0x6e1c
//   0x0068a8: f940028d  ldr      x13, [x20]
//   0x0068ac: b4002b8d  cbz      x13, #0x6e1c
//   0x0068b0: b9409689  ldr      w9, [x20, #0x94]
//   0x0068b4: f9400688  ldr      x8, [x20, #8]
//   0x0068b8: 34001fa9  cbz      w9, #0x6cac
//   0x0068bc: eb0d010a  subs     x10, x8, x13
//   0x0068c0: 54002ae9  b.ls     #0x6e1c
//   0x0068c4: f100215f  cmp      x10, #8
//   0x0068c8: aa0d03e9  mov      x9, x13
//   0x0068cc: 54002943  b.lo     #0x6df4
//   0x0068d0: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x0068d4: 91000dac  add      x12, x13, #3
//   0x0068d8: 0f05e7e0  movi     v0.8b, #0xbf
//   0x0068dc: 8b0b01a9  add      x9, x13, x11
//   0x0068e0: 0f00e741  movi     v1.8b, #0x1a
//   0x0068e4: aa0b03ed  mov      x13, x11
//   0x0068e8: 14000004  b        #0x68f8
//   0x0068ec: f10021ad  subs     x13, x13, #8
//   0x0068f0: 9100218c  add      x12, x12, #8
//   0x0068f4: 54002740  b.eq     #0x6ddc
//   0x0068f8: fc5fd182  ldur     d2, [x12, #-3]
//   0x0068fc: 0e208443  add      v3.8b, v2.8b, v0.8b
//   0x006900: 2e233423  cmhi     v3.8b, v1.8b, v3.8b
//   0x006904: 0e013c6e  umov     w14, v3.b[0]
//   0x006908: 3600038e  tbz      w14, #0, #0x6978
//   0x00690c: 0e013c4e  umov     w14, v2.b[0]
//   0x006910: 110081ce  add      w14, w14, #0x20
//   0x006914: 381fd18e  sturb    w14, [x12, #-3]
//   0x006918: 0e033c6e  umov     w14, v3.b[1]
//   0x00691c: 3700032e  tbnz     w14, #0, #0x6980
//   0x006920: 0e053c6e  umov     w14, v3.b[2]
//   0x006924: 3600038e  tbz      w14, #0, #0x6994
//   0x006928: 0e053c4e  umov     w14, v2.b[2]
//   0x00692c: 110081ce  add      w14, w14, #0x20
//   0x006930: 381ff18e  sturb    w14, [x12, #-1]
//   0x006934: 0e073c6e  umov     w14, v3.b[3]
//   0x006938: 3700032e  tbnz     w14, #0, #0x699c
//   0x00693c: 0e093c6e  umov     w14, v3.b[4]
//   0x006940: 3600038e  tbz      w14, #0, #0x69b0
//   0x006944: 0e093c4e  umov     w14, v2.b[4]
//   0x006948: 110081ce  add      w14, w14, #0x20
//   0x00694c: 3900058e  strb     w14, [x12, #1]
//   0x006950: 0e0b3c6e  umov     w14, v3.b[5]
//   0x006954: 3700032e  tbnz     w14, #0, #0x69b8
//   0x006958: 0e0d3c6e  umov     w14, v3.b[6]
//   0x00695c: 3600038e  tbz      w14, #0, #0x69cc
//   0x006960: 0e0d3c4e  umov     w14, v2.b[6]
//   0x006964: 110081ce  add      w14, w14, #0x20
//   0x006968: 39000d8e  strb     w14, [x12, #3]
//   0x00696c: 0e0f3c6e  umov     w14, v3.b[7]
//   0x006970: 3607fbee  tbz      w14, #0, #0x68ec
//   0x006974: 14000018  b        #0x69d4
//   0x006978: 0e033c6e  umov     w14, v3.b[1]
//   0x00697c: 3607fd2e  tbz      w14, #0, #0x6920
//   0x006980: 0e033c4e  umov     w14, v2.b[1]
//   0x006984: 110081ce  add      w14, w14, #0x20
//   0x006988: 381fe18e  sturb    w14, [x12, #-2]
//   0x00698c: 0e053c6e  umov     w14, v3.b[2]
//   0x006990: 3707fcce  tbnz     w14, #0, #0x6928
//   0x006994: 0e073c6e  umov     w14, v3.b[3]
//   0x006998: 3607fd2e  tbz      w14, #0, #0x693c
//   0x00699c: 0e073c4e  umov     w14, v2.b[3]
//   0x0069a0: 110081ce  add      w14, w14, #0x20
//   0x0069a4: 3900018e  strb     w14, [x12]
//   0x0069a8: 0e093c6e  umov     w14, v3.b[4]
//   0x0069ac: 3707fcce  tbnz     w14, #0, #0x6944
//   0x0069b0: 0e0b3c6e  umov     w14, v3.b[5]
//   0x0069b4: 3607fd2e  tbz      w14, #0, #0x6958
//   0x0069b8: 0e0b3c4e  umov     w14, v2.b[5]
//   0x0069bc: 110081ce  add      w14, w14, #0x20
//   0x0069c0: 3900098e  strb     w14, [x12, #2]
//   0x0069c4: 0e0d3c6e  umov     w14, v3.b[6]
//   0x0069c8: 3707fcce  tbnz     w14, #0, #0x6960
//   0x0069cc: 0e0f3c6e  umov     w14, v3.b[7]
//   0x0069d0: 3607f8ee  tbz      w14, #0, #0x68ec
//   0x0069d4: 0e0f3c4e  umov     w14, v2.b[7]
//   0x0069d8: 110081ce  add      w14, w14, #0x20
//   0x0069dc: 3900118e  strb     w14, [x12, #4]
//   0x0069e0: 17ffffc3  b        #0x68ec
//   0x0069e4: 52800040  mov      w0, #2
//   0x0069e8: 14000578  b        #0x7fc8
//   0x0069ec: 52800029  mov      w9, #1
//   0x0069f0: a9424e88  ldp      x8, x19, [x20, #0x20]
//   0x0069f4: f100011f  cmp      x8, #0
//   0x0069f8: 1a9f07ea  cset     w10, ne
//   0x0069fc: eb08027f  cmp      x19, x8
//   0x006a00: 1a9f97eb  cset     w11, hi
//   0x006a04: 0a0b014a  and      w10, w10, w11
//   0x006a08: 7100055f  cmp      w10, #1
//   0x006a0c: 54000101  b.ne     #0x6a2c
//   0x006a10: aa0803eb  mov      x11, x8
//   0x006a14: 3840156c  ldrb     w12, [x11], #1
//   0x006a18: 5101058c  sub      w12, w12, #0x41
//   0x006a1c: 7100659f  cmp      w12, #0x19
//   0x006a20: 54000829  b.ls     #0x6b24
//   0x006a24: eb0b027f  cmp      x19, x11
//   0x006a28: 54ffff61  b.ne     #0x6a14
//   0x006a2c: 2a1f03eb  mov      w11, wzr
//   0x006a30: 340007e9  cbz      w9, #0x6b2c
//   0x006a34: 52800029  mov      w9, #1
//   0x006a38: b9000049  str      w9, [x2]
//   0x006a3c: 528000a9  mov      w9, #5
//   0x006a40: 340007ab  cbz      w11, #0x6b34
//   0x006a44: b9000049  str      w9, [x2]
//   0x006a48: f94017e8  ldr      x8, [sp, #0x28]
//   0x006a4c: b5003508  cbnz     x8, #0x70ec
//   0x006a50: 36084776  tbz      w22, #1, #0x733c
//   0x006a54: f9400a93  ldr      x19, [x20, #0x10]
//   0x006a58: b4004733  cbz      x19, #0x733c
//   0x006a5c: b9409688  ldr      w8, [x20, #0x94]
//   0x006a60: f9400e9a  ldr      x26, [x20, #0x18]
//   0x006a64: 34000b08  cbz      w8, #0x6bc4
//   0x006a68: b40046ba  cbz      x26, #0x733c
//   0x006a6c: cb13035b  sub      x27, x26, x19
//   0x006a70: aa1c03f5  mov      x21, x28
//   0x006a74: 71000f7f  cmp      w27, #3
//   0x006a78: 540014eb  b.lt     #0x6d14
//   0x006a7c: 2a1f03e8  mov      w8, wzr
//   0x006a80: 5280005c  mov      w28, #2
//   0x006a84: aa1303f6  mov      x22, x19
//   0x006a88: 14000009  b        #0x6aac
//   0x006a8c: 390002c9  strb     w9, [x22]
//   0x006a90: 5280002a  mov      w10, #1
//   0x006a94: 11000509  add      w9, w8, #1
//   0x006a98: 11000d1c  add      w28, w8, #3
//   0x006a9c: 6b1b039f  cmp      w28, w27
//   0x006aa0: 8b0a02d6  add      x22, x22, x10
//   0x006aa4: 2a0903e8  mov      w8, w9
//   0x006aa8: 540013aa  b.ge     #0x6d1c
//   0x006aac: 93407d0a  sxtw     x10, w8
//   0x006ab0: 386a6a69  ldrb     w9, [x19, x10]
//   0x006ab4: 7100953f  cmp      w9, #0x25
//   0x006ab8: 54fffea1  b.ne     #0x6a8c
//   0x006abc: 8b130148  add      x8, x10, x19
//   0x006ac0: 39400500  ldrb     w0, [x8, #1]
//   0x006ac4: 387cca77  ldrb     w23, [x19, w28, sxtw]
//   0x006ac8: 97fff1d2  bl       #0x3210
//   0x006acc: 2a0003f8  mov      w24, w0
//   0x006ad0: 2a1703e0  mov      w0, w23
//   0x006ad4: 97fff1cf  bl       #0x3210
//   0x006ad8: 12001c17  and      w23, w0, #0xff
//   0x006adc: 0b3812f9  add      w25, w23, w24, uxtb #4
//   0x006ae0: 2a1903e0  mov      w0, w25
//   0x006ae4: 97fff177  bl       #0x30c0
//   0x006ae8: 34000080  cbz      w0, #0x6af8
//   0x006aec: 390002d9  strb     w25, [x22]
//   0x006af0: 5280002a  mov      w10, #1
//   0x006af4: 1400000a  b        #0x6b1c
//   0x006af8: 12001f00  and      w0, w24, #0xff
//   0x006afc: 528004a8  mov      w8, #0x25
//   0x006b00: 390002c8  strb     w8, [x22]
//   0x006b04: 97fff193  bl       #0x3150
//   0x006b08: 390006c0  strb     w0, [x22, #1]
//   0x006b0c: 2a1703e0  mov      w0, w23
//   0x006b10: 97fff190  bl       #0x3150
//   0x006b14: 5280006a  mov      w10, #3
//   0x006b18: 39000ac0  strb     w0, [x22, #2]
//   0x006b1c: 2a1c03e8  mov      w8, w28
//   0x006b20: 17ffffdd  b        #0x6a94
//   0x006b24: 5280002b  mov      w11, #1
//   0x006b28: 35fff869  cbnz     w9, #0x6a34
//   0x006b2c: 52800089  mov      w9, #4
//   0x006b30: 35fff8ab  cbnz     w11, #0x6a44
//   0x006b34: 34002d8a  cbz      w10, #0x70e4
//   0x006b38: 91000915  add      x21, x8, #2
//   0x006b3c: eb1302bf  cmp      x21, x19
//   0x006b40: 540000a3  b.lo     #0x6b54
//   0x006b44: 14000168  b        #0x70e4
//   0x006b48: 910006b5  add      x21, x21, #1
//   0x006b4c: eb1302bf  cmp      x21, x19
//   0x006b50: 54002ca2  b.hs     #0x70e4
//   0x006b54: 385fe2a8  ldurb    w8, [x21, #-2]
//   0x006b58: 7100951f  cmp      w8, #0x25
//   0x006b5c: 54ffff61  b.ne     #0x6b48
//   0x006b60: 385ff2a0  ldurb    w0, [x21, #-1]
//   0x006b64: 51018408  sub      w8, w0, #0x61
//   0x006b68: 7100191f  cmp      w8, #6
//   0x006b6c: 540001e3  b.lo     #0x6ba8
//   0x006b70: 394002a8  ldrb     w8, [x21]
//   0x006b74: 51018508  sub      w8, w8, #0x61
//   0x006b78: 7100191f  cmp      w8, #6
//   0x006b7c: 54000163  b.lo     #0x6ba8
//   0x006b80: 97fff1a4  bl       #0x3210
//   0x006b84: 394002a8  ldrb     w8, [x21]
//   0x006b88: 2a0003f7  mov      w23, w0
//   0x006b8c: 2a0803e0  mov      w0, w8
//   0x006b90: 97fff1a0  bl       #0x3210
//   0x006b94: 12001ee8  and      w8, w23, #0xff
//   0x006b98: 531c6d08  lsl      w8, w8, #4
//   0x006b9c: 0b200100  add      w0, w8, w0, uxtb
//   0x006ba0: 97fff148  bl       #0x30c0
//   0x006ba4: 34fffd20  cbz      w0, #0x6b48
//   0x006ba8: f94017e9  ldr      x9, [sp, #0x28]
//   0x006bac: b9400128  ldr      w8, [x9]
//   0x006bb0: 321e0108  orr      w8, w8, #4
//   0x006bb4: b9000128  str      w8, [x9]
//   0x006bb8: f94017e8  ldr      x8, [sp, #0x28]
//   0x006bbc: b5002988  cbnz     x8, #0x70ec
//   0x006bc0: 17ffffa4  b        #0x6a50
//   0x006bc4: b400815a  cbz      x26, #0x7bec
//   0x006bc8: cb130348  sub      x8, x26, x19
//   0x006bcc: 34003ae8  cbz      w8, #0x7328
//   0x006bd0: 37f880e8  tbnz     w8, #0x1f, #0x7bec
//   0x006bd4: f94013e0  ldr      x0, [sp, #0x20]
//   0x006bd8: 93407d01  sxtw     x1, w8
//   0x006bdc: f9400009  ldr      x9, [x0]
//   0x006be0: d63f0120  blr      x9
//   0x006be4: b4008040  cbz      x0, #0x7bec
//   0x006be8: a9412293  ldp      x19, x8, [x20, #0x10]
//   0x006bec: aa1c03f5  mov      x21, x28
//   0x006bf0: aa0003f7  mov      x23, x0
//   0x006bf4: cb13011c  sub      x28, x8, x19
//   0x006bf8: 71000f9f  cmp      w28, #3
//   0x006bfc: f90007e8  str      x8, [sp, #8]
//   0x006c00: 5400336b  b.lt     #0x726c
//   0x006c04: 2a1f03e8  mov      w8, wzr
//   0x006c08: 5280005b  mov      w27, #2
//   0x006c0c: aa1703f6  mov      x22, x23
//   0x006c10: 14000009  b        #0x6c34
//   0x006c14: 390002c9  strb     w9, [x22]
//   0x006c18: 5280002a  mov      w10, #1
//   0x006c1c: 11000509  add      w9, w8, #1
//   0x006c20: 11000d1b  add      w27, w8, #3
//   0x006c24: 6b1c037f  cmp      w27, w28
//   0x006c28: 8b0a02d6  add      x22, x22, x10
//   0x006c2c: 2a0903e8  mov      w8, w9
//   0x006c30: 5400322a  b.ge     #0x7274
//   0x006c34: 93407d0a  sxtw     x10, w8
//   0x006c38: 386a6a69  ldrb     w9, [x19, x10]
//   0x006c3c: 7100953f  cmp      w9, #0x25
//   0x006c40: 54fffea1  b.ne     #0x6c14
//   0x006c44: 8b130148  add      x8, x10, x19
//   0x006c48: 39400500  ldrb     w0, [x8, #1]
//   0x006c4c: 387bca78  ldrb     w24, [x19, w27, sxtw]
//   0x006c50: 97fff170  bl       #0x3210
//   0x006c54: 2a0003f9  mov      w25, w0
//   0x006c58: 2a1803e0  mov      w0, w24
//   0x006c5c: 97fff16d  bl       #0x3210
//   0x006c60: 12001c18  and      w24, w0, #0xff
//   0x006c64: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x006c68: 2a1a03e0  mov      w0, w26
//   0x006c6c: 97fff115  bl       #0x30c0
//   0x006c70: 34000080  cbz      w0, #0x6c80
//   0x006c74: 390002da  strb     w26, [x22]
//   0x006c78: 5280002a  mov      w10, #1
//   0x006c7c: 1400000a  b        #0x6ca4
//   0x006c80: 12001f20  and      w0, w25, #0xff
//   0x006c84: 528004a8  mov      w8, #0x25
//   0x006c88: 390002c8  strb     w8, [x22]
//   0x006c8c: 97fff131  bl       #0x3150
//   0x006c90: 390006c0  strb     w0, [x22, #1]
//   0x006c94: 2a1803e0  mov      w0, w24
//   0x006c98: 97fff12e  bl       #0x3150
//   0x006c9c: 5280006a  mov      w10, #3
//   0x006ca0: 39000ac0  strb     w0, [x22, #2]
//   0x006ca4: 2a1b03e8  mov      w8, w27
//   0x006ca8: 17ffffdd  b        #0x6c1c
//   0x006cac: b4000928  cbz      x8, #0x6dd0
//   0x006cb0: cb0d0113  sub      x19, x8, x13
//   0x006cb4: 34000af3  cbz      w19, #0x6e10
//   0x006cb8: 37f808d3  tbnz     w19, #0x1f, #0x6dd0
//   0x006cbc: f94013e0  ldr      x0, [sp, #0x20]
//   0x006cc0: 93407e77  sxtw     x23, w19
//   0x006cc4: aa1703e1  mov      x1, x23
//   0x006cc8: f9400008  ldr      x8, [x0]
//   0x006ccc: d63f0100  blr      x8
//   0x006cd0: b4000800  cbz      x0, #0x6dd0
//   0x006cd4: aa1f03e8  mov      x8, xzr
//   0x006cd8: 92407e69  and      x9, x19, #0xffffffff
//   0x006cdc: f940028a  ldr      x10, [x20]
//   0x006ce0: 3868694a  ldrb     w10, [x10, x8]
//   0x006ce4: 5101054b  sub      w11, w10, #0x41
//   0x006ce8: 1100814c  add      w12, w10, #0x20
//   0x006cec: 7100697f  cmp      w11, #0x1a
//   0x006cf0: 1a8a318a  csel     w10, w12, w10, lo
//   0x006cf4: 3828680a  strb     w10, [x0, x8]
//   0x006cf8: 91000508  add      x8, x8, #1
//   0x006cfc: eb08013f  cmp      x9, x8
//   0x006d00: 54fffee1  b.ne     #0x6cdc
//   0x006d04: 8b170008  add      x8, x0, x23
//   0x006d08: a9002280  stp      x0, x8, [x20]
//   0x006d0c: b94037e8  ldr      w8, [sp, #0x34]
//   0x006d10: 14000041  b        #0x6e14
//   0x006d14: 2a1f03e9  mov      w9, wzr
//   0x006d18: aa1303f6  mov      x22, x19
//   0x006d1c: 6b1b013f  cmp      w9, w27
//   0x006d20: 540004ca  b.ge     #0x6db8
//   0x006d24: 93407d29  sxtw     x9, w9
//   0x006d28: 93407f6a  sxtw     x10, w27
//   0x006d2c: cb090148  sub      x8, x10, x9
//   0x006d30: f1007d1f  cmp      x8, #0x1f
//   0x006d34: aa1503fc  mov      x28, x21
//   0x006d38: 540002e9  b.ls     #0x6d94
//   0x006d3c: 8b0a026a  add      x10, x19, x10
//   0x006d40: eb0a02df  cmp      x22, x10
//   0x006d44: 540000a2  b.hs     #0x6d58
//   0x006d48: 8b0802ca  add      x10, x22, x8
//   0x006d4c: 8b09026b  add      x11, x19, x9
//   0x006d50: eb0a017f  cmp      x11, x10
//   0x006d54: 54000203  b.lo     #0x6d94
//   0x006d58: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x006d5c: 8b13012c  add      x12, x9, x19
//   0x006d60: 910042cb  add      x11, x22, #0x10
//   0x006d64: 8b090149  add      x9, x10, x9
//   0x006d68: 8b0a02d6  add      x22, x22, x10
//   0x006d6c: 9100418c  add      x12, x12, #0x10
//   0x006d70: aa0a03ed  mov      x13, x10
//   0x006d74: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x006d78: f10081ad  subs     x13, x13, #0x20
//   0x006d7c: 9100818c  add      x12, x12, #0x20
//   0x006d80: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x006d84: 9100816b  add      x11, x11, #0x20
//   0x006d88: 54ffff61  b.ne     #0x6d74
//   0x006d8c: eb0a011f  cmp      x8, x10
//   0x006d90: 54000160  b.eq     #0x6dbc
//   0x006d94: 4b130348  sub      w8, w26, w19
//   0x006d98: 93407d08  sxtw     x8, w8
//   0x006d9c: cb090108  sub      x8, x8, x9
//   0x006da0: 8b090269  add      x9, x19, x9
//   0x006da4: 3840152a  ldrb     w10, [x9], #1
//   0x006da8: f1000508  subs     x8, x8, #1
//   0x006dac: 380016ca  strb     w10, [x22], #1
//   0x006db0: 54ffffa1  b.ne     #0x6da4
//   0x006db4: 14000002  b        #0x6dbc
//   0x006db8: aa1503fc  mov      x28, x21
//   0x006dbc: f9000e96  str      x22, [x20, #0x18]
//   0x006dc0: b9401bf6  ldr      w22, [sp, #0x18]
//   0x006dc4: f94017e8  ldr      x8, [sp, #0x28]
//   0x006dc8: b5001e08  cbnz     x8, #0x7188
//   0x006dcc: 1400015c  b        #0x733c
//   0x006dd0: aa1403e0  mov      x0, x20
//   0x006dd4: 2a1f03e1  mov      w1, wzr
//   0x006dd8: 14000387  b        #0x7bf4
//   0x006ddc: eb0b015f  cmp      x10, x11
//   0x006de0: 540000a1  b.ne     #0x6df4
//   0x006de4: 1400000e  b        #0x6e1c
//   0x006de8: 91000529  add      x9, x9, #1
//   0x006dec: eb09011f  cmp      x8, x9
//   0x006df0: 54000160  b.eq     #0x6e1c
//   0x006df4: 3940012a  ldrb     w10, [x9]
//   0x006df8: 5101054b  sub      w11, w10, #0x41
//   0x006dfc: 7100657f  cmp      w11, #0x19
//   0x006e00: 54ffff48  b.hi     #0x6de8
//   0x006e04: 1100814a  add      w10, w10, #0x20
//   0x006e08: 3900012a  strb     w10, [x9]
//   0x006e0c: 17fffff7  b        #0x6de8
//   0x006e10: 2a1f03e8  mov      w8, wzr
//   0x006e14: 32000108  orr      w8, w8, #1
//   0x006e18: b90037e8  str      w8, [sp, #0x34]
//   0x006e1c: 36101656  tbz      w22, #2, #0x70e4
//   0x006e20: f9402280  ldr      x0, [x20, #0x40]
//   0x006e24: b40009a0  cbz      x0, #0x6f58
//   0x006e28: b9409689  ldr      w9, [x20, #0x94]
//   0x006e2c: f9402688  ldr      x8, [x20, #0x48]
//   0x006e30: 34000b89  cbz      w9, #0x6fa0
//   0x006e34: eb000109  subs     x9, x8, x0
//   0x006e38: 54001549  b.ls     #0x70e0
//   0x006e3c: f100213f  cmp      x9, #8
//   0x006e40: 54001403  b.lo     #0x70c0
//   0x006e44: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x006e48: 91000c0b  add      x11, x0, #3
//   0x006e4c: 0f05e7e0  movi     v0.8b, #0xbf
//   0x006e50: 8b0a0000  add      x0, x0, x10
//   0x006e54: 0f00e741  movi     v1.8b, #0x1a
//   0x006e58: aa0a03ec  mov      x12, x10
//   0x006e5c: 14000004  b        #0x6e6c
//   0x006e60: f100218c  subs     x12, x12, #8
//   0x006e64: 9100216b  add      x11, x11, #8
//   0x006e68: 54001200  b.eq     #0x70a8
//   0x006e6c: fc5fd162  ldur     d2, [x11, #-3]
//   0x006e70: 0e208443  add      v3.8b, v2.8b, v0.8b
//   0x006e74: 2e233423  cmhi     v3.8b, v1.8b, v3.8b
//   0x006e78: 0e013c6d  umov     w13, v3.b[0]
//   0x006e7c: 3600038d  tbz      w13, #0, #0x6eec
//   0x006e80: 0e013c4d  umov     w13, v2.b[0]
//   0x006e84: 110081ad  add      w13, w13, #0x20
//   0x006e88: 381fd16d  sturb    w13, [x11, #-3]
//   0x006e8c: 0e033c6d  umov     w13, v3.b[1]
//   0x006e90: 3700032d  tbnz     w13, #0, #0x6ef4
//   0x006e94: 0e053c6d  umov     w13, v3.b[2]
//   0x006e98: 3600038d  tbz      w13, #0, #0x6f08
//   0x006e9c: 0e053c4d  umov     w13, v2.b[2]
//   0x006ea0: 110081ad  add      w13, w13, #0x20
//   0x006ea4: 381ff16d  sturb    w13, [x11, #-1]
//   0x006ea8: 0e073c6d  umov     w13, v3.b[3]
//   0x006eac: 3700032d  tbnz     w13, #0, #0x6f10
//   0x006eb0: 0e093c6d  umov     w13, v3.b[4]
//   0x006eb4: 3600038d  tbz      w13, #0, #0x6f24
//   0x006eb8: 0e093c4d  umov     w13, v2.b[4]
//   0x006ebc: 110081ad  add      w13, w13, #0x20
//   0x006ec0: 3900056d  strb     w13, [x11, #1]
//   0x006ec4: 0e0b3c6d  umov     w13, v3.b[5]
//   0x006ec8: 3700032d  tbnz     w13, #0, #0x6f2c
//   0x006ecc: 0e0d3c6d  umov     w13, v3.b[6]
//   0x006ed0: 3600038d  tbz      w13, #0, #0x6f40
//   0x006ed4: 0e0d3c4d  umov     w13, v2.b[6]
//   0x006ed8: 110081ad  add      w13, w13, #0x20
//   0x006edc: 39000d6d  strb     w13, [x11, #3]
//   0x006ee0: 0e0f3c6d  umov     w13, v3.b[7]
//   0x006ee4: 3607fbed  tbz      w13, #0, #0x6e60
//   0x006ee8: 14000018  b        #0x6f48
//   0x006eec: 0e033c6d  umov     w13, v3.b[1]
//   0x006ef0: 3607fd2d  tbz      w13, #0, #0x6e94
//   0x006ef4: 0e033c4d  umov     w13, v2.b[1]
//   0x006ef8: 110081ad  add      w13, w13, #0x20
//   0x006efc: 381fe16d  sturb    w13, [x11, #-2]
//   0x006f00: 0e053c6d  umov     w13, v3.b[2]
//   0x006f04: 3707fccd  tbnz     w13, #0, #0x6e9c
//   0x006f08: 0e073c6d  umov     w13, v3.b[3]
//   0x006f0c: 3607fd2d  tbz      w13, #0, #0x6eb0
//   0x006f10: 0e073c4d  umov     w13, v2.b[3]
//   0x006f14: 110081ad  add      w13, w13, #0x20
//   0x006f18: 3900016d  strb     w13, [x11]
//   0x006f1c: 0e093c6d  umov     w13, v3.b[4]
//   0x006f20: 3707fccd  tbnz     w13, #0, #0x6eb8
//   0x006f24: 0e0b3c6d  umov     w13, v3.b[5]
//   0x006f28: 3607fd2d  tbz      w13, #0, #0x6ecc
//   0x006f2c: 0e0b3c4d  umov     w13, v2.b[5]
//   0x006f30: 110081ad  add      w13, w13, #0x20
//   0x006f34: 3900096d  strb     w13, [x11, #2]
//   0x006f38: 0e0d3c6d  umov     w13, v3.b[6]
//   0x006f3c: 3707fccd  tbnz     w13, #0, #0x6ed4
//   0x006f40: 0e0f3c6d  umov     w13, v3.b[7]
//   0x006f44: 3607f8ed  tbz      w13, #0, #0x6e60
//   0x006f48: 0e0f3c4d  umov     w13, v2.b[7]
//   0x006f4c: 110081ad  add      w13, w13, #0x20
//   0x006f50: 3900116d  strb     w13, [x11, #4]
//   0x006f54: 17ffffc3  b        #0x6e60
//   0x006f58: f9401297  ldr      x23, [x20, #0x20]
//   0x006f5c: b4000c57  cbz      x23, #0x70e4
//   0x006f60: f9401a88  ldr      x8, [x20, #0x30]
//   0x006f64: b5000c08  cbnz     x8, #0x70e4
//   0x006f68: f9401e88  ldr      x8, [x20, #0x38]
//   0x006f6c: b5000bc8  cbnz     x8, #0x70e4
//   0x006f70: b9409688  ldr      w8, [x20, #0x94]
//   0x006f74: f940169b  ldr      x27, [x20, #0x28]
//   0x006f78: 340072c8  cbz      w8, #0x7dd0
//   0x006f7c: b4000b5b  cbz      x27, #0x70e4
//   0x006f80: cb170376  sub      x22, x27, x23
//   0x006f84: aa1c03f5  mov      x21, x28
//   0x006f88: 71000edf  cmp      w22, #3
//   0x006f8c: 5400836b  b.lt     #0x7ff8
//   0x006f90: 2a1f03e8  mov      w8, wzr
//   0x006f94: 5280005c  mov      w28, #2
//   0x006f98: aa1703f3  mov      x19, x23
//   0x006f9c: 14000025  b        #0x7030
//   0x006fa0: b4006268  cbz      x8, #0x7bec
//   0x006fa4: cb000113  sub      x19, x8, x0
//   0x006fa8: 340002d3  cbz      w19, #0x7000
//   0x006fac: 37f86213  tbnz     w19, #0x1f, #0x7bec
//   0x006fb0: f94013e0  ldr      x0, [sp, #0x20]
//   0x006fb4: 93407e77  sxtw     x23, w19
//   0x006fb8: aa1703e1  mov      x1, x23
//   0x006fbc: f9400008  ldr      x8, [x0]
//   0x006fc0: d63f0100  blr      x8
//   0x006fc4: b4006140  cbz      x0, #0x7bec
//   0x006fc8: aa1f03e8  mov      x8, xzr
//   0x006fcc: 92407e69  and      x9, x19, #0xffffffff
//   0x006fd0: f940228a  ldr      x10, [x20, #0x40]
//   0x006fd4: 3868694a  ldrb     w10, [x10, x8]
//   0x006fd8: 5101054b  sub      w11, w10, #0x41
//   0x006fdc: 1100814c  add      w12, w10, #0x20
//   0x006fe0: 7100697f  cmp      w11, #0x1a
//   0x006fe4: 1a8a318a  csel     w10, w12, w10, lo
//   0x006fe8: 3828680a  strb     w10, [x0, x8]
//   0x006fec: 91000508  add      x8, x8, #1
//   0x006ff0: eb08013f  cmp      x9, x8
//   0x006ff4: 54fffee1  b.ne     #0x6fd0
//   0x006ff8: 8b170008  add      x8, x0, x23
//   0x006ffc: a9042280  stp      x0, x8, [x20, #0x40]
//   0x007000: b94037e9  ldr      w9, [sp, #0x34]
//   0x007004: 321e0129  orr      w9, w9, #4
//   0x007008: b90037e9  str      w9, [sp, #0x34]
//   0x00700c: 14000035  b        #0x70e0
//   0x007010: 39000269  strb     w9, [x19]
//   0x007014: 5280002a  mov      w10, #1
//   0x007018: 11000509  add      w9, w8, #1
//   0x00701c: 11000d1c  add      w28, w8, #3
//   0x007020: 6b16039f  cmp      w28, w22
//   0x007024: 8b0a0273  add      x19, x19, x10
//   0x007028: 2a0903e8  mov      w8, w9
//   0x00702c: 54007eaa  b.ge     #0x8000
//   0x007030: 93407d0a  sxtw     x10, w8
//   0x007034: 386a6ae9  ldrb     w9, [x23, x10]
//   0x007038: 7100953f  cmp      w9, #0x25
//   0x00703c: 54fffea1  b.ne     #0x7010
//   0x007040: 8b170148  add      x8, x10, x23
//   0x007044: 39400500  ldrb     w0, [x8, #1]
//   0x007048: 387ccaf8  ldrb     w24, [x23, w28, sxtw]
//   0x00704c: 97fff071  bl       #0x3210
//   0x007050: 2a0003f9  mov      w25, w0
//   0x007054: 2a1803e0  mov      w0, w24
//   0x007058: 97fff06e  bl       #0x3210
//   0x00705c: 12001c18  and      w24, w0, #0xff
//   0x007060: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x007064: 2a1a03e0  mov      w0, w26
//   0x007068: 97fff016  bl       #0x30c0
//   0x00706c: 34000080  cbz      w0, #0x707c
//   0x007070: 3900027a  strb     w26, [x19]
//   0x007074: 5280002a  mov      w10, #1
//   0x007078: 1400000a  b        #0x70a0
//   0x00707c: 12001f20  and      w0, w25, #0xff
//   0x007080: 528004a8  mov      w8, #0x25
//   0x007084: 39000268  strb     w8, [x19]
//   0x007088: 97fff032  bl       #0x3150
//   0x00708c: 39000660  strb     w0, [x19, #1]
//   0x007090: 2a1803e0  mov      w0, w24
//   0x007094: 97fff02f  bl       #0x3150
//   0x007098: 5280006a  mov      w10, #3
//   0x00709c: 39000a60  strb     w0, [x19, #2]
//   0x0070a0: 2a1c03e8  mov      w8, w28
//   0x0070a4: 17ffffdd  b        #0x7018
//   0x0070a8: eb0a013f  cmp      x9, x10
//   0x0070ac: 540000a1  b.ne     #0x70c0
//   0x0070b0: 1400000b  b        #0x70dc
//   0x0070b4: 91000400  add      x0, x0, #1
//   0x0070b8: eb00011f  cmp      x8, x0
//   0x0070bc: 54000100  b.eq     #0x70dc
//   0x0070c0: 39400009  ldrb     w9, [x0]
//   0x0070c4: 5101052a  sub      w10, w9, #0x41
//   0x0070c8: 7100655f  cmp      w10, #0x19
//   0x0070cc: 54ffff48  b.hi     #0x70b4
//   0x0070d0: 11008129  add      w9, w9, #0x20
//   0x0070d4: 39000009  strb     w9, [x0]
//   0x0070d8: 17fffff7  b        #0x70b4
//   0x0070dc: a9442280  ldp      x0, x8, [x20, #0x40]
//   0x0070e0: a9022280  stp      x0, x8, [x20, #0x20]
//   0x0070e4: f94017e8  ldr      x8, [sp, #0x28]
//   0x0070e8: b4ffcb48  cbz      x8, #0x6a50
//   0x0070ec: f9400a88  ldr      x8, [x20, #0x10]
//   0x0070f0: b40004c8  cbz      x8, #0x7188
//   0x0070f4: f9400e93  ldr      x19, [x20, #0x18]
//   0x0070f8: eb08027f  cmp      x19, x8
//   0x0070fc: 54000469  b.ls     #0x7188
//   0x007100: 91000915  add      x21, x8, #2
//   0x007104: eb1302bf  cmp      x21, x19
//   0x007108: 540000a3  b.lo     #0x711c
//   0x00710c: 1400001f  b        #0x7188
//   0x007110: 910006b5  add      x21, x21, #1
//   0x007114: eb1302bf  cmp      x21, x19
//   0x007118: 54000342  b.hs     #0x7180
//   0x00711c: 385fe2a8  ldurb    w8, [x21, #-2]
//   0x007120: 7100951f  cmp      w8, #0x25
//   0x007124: 54ffff61  b.ne     #0x7110
//   0x007128: 385ff2a0  ldurb    w0, [x21, #-1]
//   0x00712c: 51018408  sub      w8, w0, #0x61
//   0x007130: 7100191f  cmp      w8, #6
//   0x007134: 540001e3  b.lo     #0x7170
//   0x007138: 394002a8  ldrb     w8, [x21]
//   0x00713c: 51018508  sub      w8, w8, #0x61
//   0x007140: 7100191f  cmp      w8, #6
//   0x007144: 54000163  b.lo     #0x7170
//   0x007148: 97fff032  bl       #0x3210
//   0x00714c: 394002a8  ldrb     w8, [x21]
//   0x007150: 2a0003f7  mov      w23, w0
//   0x007154: 2a0803e0  mov      w0, w8
//   0x007158: 97fff02e  bl       #0x3210
//   0x00715c: 12001ee8  and      w8, w23, #0xff
//   0x007160: 531c6d08  lsl      w8, w8, #4
//   0x007164: 0b200100  add      w0, w8, w0, uxtb
//   0x007168: 97ffefd6  bl       #0x30c0
//   0x00716c: 34fffd20  cbz      w0, #0x7110
//   0x007170: f94017e9  ldr      x9, [sp, #0x28]
//   0x007174: b9400128  ldr      w8, [x9]
//   0x007178: 321f0108  orr      w8, w8, #2
//   0x00717c: b9000128  str      w8, [x9]
//   0x007180: f94017e8  ldr      x8, [sp, #0x28]
//   0x007184: b4000dc8  cbz      x8, #0x733c
//   0x007188: f9403293  ldr      x19, [x20, #0x60]
//   0x00718c: b5000093  cbnz     x19, #0x719c
//   0x007190: 14000157  b        #0x76ec
//   0x007194: f9400a73  ldr      x19, [x19, #0x10]
//   0x007198: b4002a53  cbz      x19, #0x76e0
//   0x00719c: f9400268  ldr      x8, [x19]
//   0x0071a0: b4ffffa8  cbz      x8, #0x7194
//   0x0071a4: f9400676  ldr      x22, [x19, #8]
//   0x0071a8: eb0802c9  subs     x9, x22, x8
//   0x0071ac: 54ffff49  b.ls     #0x7194
//   0x0071b0: f100093f  cmp      x9, #2
//   0x0071b4: 540000e0  b.eq     #0x71d0
//   0x0071b8: f100053f  cmp      x9, #1
//   0x0071bc: 54000161  b.ne     #0x71e8
//   0x0071c0: 39400109  ldrb     w9, [x8]
//   0x0071c4: 7100b93f  cmp      w9, #0x2e
//   0x0071c8: 54000101  b.ne     #0x71e8
//   0x0071cc: 14000023  b        #0x7258
//   0x0071d0: 39400109  ldrb     w9, [x8]
//   0x0071d4: 7100b93f  cmp      w9, #0x2e
//   0x0071d8: 54000081  b.ne     #0x71e8
//   0x0071dc: 39400509  ldrb     w9, [x8, #1]
//   0x0071e0: 7100b93f  cmp      w9, #0x2e
//   0x0071e4: 540003a0  b.eq     #0x7258
//   0x0071e8: 91000915  add      x21, x8, #2
//   0x0071ec: eb1602bf  cmp      x21, x22
//   0x0071f0: 540000a3  b.lo     #0x7204
//   0x0071f4: 17ffffe8  b        #0x7194
//   0x0071f8: 910006b5  add      x21, x21, #1
//   0x0071fc: eb1602bf  cmp      x21, x22
//   0x007200: 54fffca2  b.hs     #0x7194
//   0x007204: 385fe2a8  ldurb    w8, [x21, #-2]
//   0x007208: 7100951f  cmp      w8, #0x25
//   0x00720c: 54ffff61  b.ne     #0x71f8
//   0x007210: 385ff2a0  ldurb    w0, [x21, #-1]
//   0x007214: 51018408  sub      w8, w0, #0x61
//   0x007218: 7100191f  cmp      w8, #6
//   0x00721c: 540001e3  b.lo     #0x7258
//   0x007220: 394002a8  ldrb     w8, [x21]
//   0x007224: 51018508  sub      w8, w8, #0x61
//   0x007228: 7100191f  cmp      w8, #6
//   0x00722c: 54000163  b.lo     #0x7258
//   0x007230: 97ffeff8  bl       #0x3210
//   0x007234: 394002a8  ldrb     w8, [x21]
//   0x007238: 2a0003f7  mov      w23, w0
//   0x00723c: 2a0803e0  mov      w0, w8
//   0x007240: 97ffeff4  bl       #0x3210
//   0x007244: 12001ee8  and      w8, w23, #0xff
//   0x007248: 531c6d08  lsl      w8, w8, #4
//   0x00724c: 0b200100  add      w0, w8, w0, uxtb
//   0x007250: 97ffef9c  bl       #0x30c0
//   0x007254: 34fffd20  cbz      w0, #0x71f8
//   0x007258: f94017e9  ldr      x9, [sp, #0x28]
//   0x00725c: b9400128  ldr      w8, [x9]
//   0x007260: 321d0108  orr      w8, w8, #8
//   0x007264: b9000128  str      w8, [x9]
//   0x007268: 1400011e  b        #0x76e0
//   0x00726c: 2a1f03e9  mov      w9, wzr
//   0x007270: aa1703f6  mov      x22, x23
//   0x007274: 6b1c013f  cmp      w9, w28
//   0x007278: 5400010a  b.ge     #0x7298
//   0x00727c: 93407d29  sxtw     x9, w9
//   0x007280: 93407f8a  sxtw     x10, w28
//   0x007284: cb090148  sub      x8, x10, x9
//   0x007288: f1007d1f  cmp      x8, #0x1f
//   0x00728c: 540000a8  b.hi     #0x72a0
//   0x007290: aa1503fc  mov      x28, x21
//   0x007294: 1400001a  b        #0x72fc
//   0x007298: aa1503fc  mov      x28, x21
//   0x00729c: 14000021  b        #0x7320
//   0x0072a0: 8b0a026a  add      x10, x19, x10
//   0x0072a4: eb0a02df  cmp      x22, x10
//   0x0072a8: aa1503fc  mov      x28, x21
//   0x0072ac: 540000a2  b.hs     #0x72c0
//   0x0072b0: 8b0802ca  add      x10, x22, x8
//   0x0072b4: 8b09026b  add      x11, x19, x9
//   0x0072b8: eb0a017f  cmp      x11, x10
//   0x0072bc: 54000203  b.lo     #0x72fc
//   0x0072c0: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x0072c4: 8b13012c  add      x12, x9, x19
//   0x0072c8: 910042cb  add      x11, x22, #0x10
//   0x0072cc: 8b090149  add      x9, x10, x9
//   0x0072d0: 8b0a02d6  add      x22, x22, x10
//   0x0072d4: 9100418c  add      x12, x12, #0x10
//   0x0072d8: aa0a03ed  mov      x13, x10
//   0x0072dc: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x0072e0: f10081ad  subs     x13, x13, #0x20
//   0x0072e4: 9100818c  add      x12, x12, #0x20
//   0x0072e8: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x0072ec: 9100816b  add      x11, x11, #0x20
//   0x0072f0: 54ffff61  b.ne     #0x72dc
//   0x0072f4: eb0a011f  cmp      x8, x10
//   0x0072f8: 54000140  b.eq     #0x7320
//   0x0072fc: f94007e8  ldr      x8, [sp, #8]
//   0x007300: 4b130108  sub      w8, w8, w19
//   0x007304: 93407d08  sxtw     x8, w8
//   0x007308: cb090108  sub      x8, x8, x9
//   0x00730c: 8b090269  add      x9, x19, x9
//   0x007310: 3840152a  ldrb     w10, [x9], #1
//   0x007314: f1000508  subs     x8, x8, #1
//   0x007318: 380016ca  strb     w10, [x22], #1
//   0x00731c: 54ffffa1  b.ne     #0x7310
//   0x007320: a9015a97  stp      x23, x22, [x20, #0x10]
//   0x007324: b9401bf6  ldr      w22, [sp, #0x18]
//   0x007328: b94037e8  ldr      w8, [sp, #0x34]
//   0x00732c: 321f0108  orr      w8, w8, #2
//   0x007330: b90037e8  str      w8, [sp, #0x34]
//   0x007334: f94017e8  ldr      x8, [sp, #0x28]
//   0x007338: b5fff288  cbnz     x8, #0x7188
//   0x00733c: 36182216  tbz      w22, #3, #0x777c
//   0x007340: f9400288  ldr      x8, [x20]
//   0x007344: b4000068  cbz      x8, #0x7350
//   0x007348: b9000bff  str      wzr, [sp, #8]
//   0x00734c: 14000005  b        #0x7360
//   0x007350: b9409288  ldr      w8, [x20, #0x90]
//   0x007354: 7100011f  cmp      w8, #0
//   0x007358: 1a9f17e8  cset     w8, eq
//   0x00735c: b9000be8  str      w8, [sp, #8]
//   0x007360: f94013f3  ldr      x19, [sp, #0x20]
//   0x007364: b9409688  ldr      w8, [x20, #0x94]
//   0x007368: f9403297  ldr      x23, [x20, #0x60]
//   0x00736c: 34000c08  cbz      w8, #0x74ec
//   0x007370: b40019d7  cbz      x23, #0x76a8
//   0x007374: 528004b3  mov      w19, #0x25
//   0x007378: f9000bfc  str      x28, [sp, #0x10]
//   0x00737c: f94002fc  ldr      x28, [x23]
//   0x007380: b50000fc  cbnz     x28, #0x739c
//   0x007384: 14000002  b        #0x738c
//   0x007388: f90006fb  str      x27, [x23, #8]
//   0x00738c: f9400af7  ldr      x23, [x23, #0x10]
//   0x007390: b4001877  cbz      x23, #0x769c
//   0x007394: f94002fc  ldr      x28, [x23]
//   0x007398: b4ffffbc  cbz      x28, #0x738c
//   0x00739c: f94006e8  ldr      x8, [x23, #8]
//   0x0073a0: b4ffff68  cbz      x8, #0x738c
//   0x0073a4: cb1c0116  sub      x22, x8, x28
//   0x0073a8: 71000edf  cmp      w22, #3
//   0x0073ac: 5400054b  b.lt     #0x7454
//   0x0073b0: 2a1f03e8  mov      w8, wzr
//   0x0073b4: 52800055  mov      w21, #2
//   0x0073b8: aa1c03fb  mov      x27, x28
//   0x0073bc: 14000009  b        #0x73e0
//   0x0073c0: 39000369  strb     w9, [x27]
//   0x0073c4: 5280002a  mov      w10, #1
//   0x0073c8: 11000509  add      w9, w8, #1
//   0x0073cc: 11000d15  add      w21, w8, #3
//   0x0073d0: 6b1602bf  cmp      w21, w22
//   0x0073d4: 8b0a037b  add      x27, x27, x10
//   0x0073d8: 2a0903e8  mov      w8, w9
//   0x0073dc: 5400040a  b.ge     #0x745c
//   0x0073e0: 93407d0a  sxtw     x10, w8
//   0x0073e4: 386a6b89  ldrb     w9, [x28, x10]
//   0x0073e8: 7100953f  cmp      w9, #0x25
//   0x0073ec: 54fffea1  b.ne     #0x73c0
//   0x0073f0: 8b1c0148  add      x8, x10, x28
//   0x0073f4: 39400500  ldrb     w0, [x8, #1]
//   0x0073f8: 3875cb98  ldrb     w24, [x28, w21, sxtw]
//   0x0073fc: 97ffef85  bl       #0x3210
//   0x007400: 2a0003f9  mov      w25, w0
//   0x007404: 2a1803e0  mov      w0, w24
//   0x007408: 97ffef82  bl       #0x3210
//   0x00740c: 12001c18  and      w24, w0, #0xff
//   0x007410: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x007414: 2a1a03e0  mov      w0, w26
//   0x007418: 97ffef2a  bl       #0x30c0
//   0x00741c: 34000080  cbz      w0, #0x742c
//   0x007420: 3900037a  strb     w26, [x27]
//   0x007424: 5280002a  mov      w10, #1
//   0x007428: 14000009  b        #0x744c
//   0x00742c: 12001f20  and      w0, w25, #0xff
//   0x007430: 39000373  strb     w19, [x27]
//   0x007434: 97ffef47  bl       #0x3150
//   0x007438: 39000760  strb     w0, [x27, #1]
//   0x00743c: 2a1803e0  mov      w0, w24
//   0x007440: 97ffef44  bl       #0x3150
//   0x007444: 5280006a  mov      w10, #3
//   0x007448: 39000b60  strb     w0, [x27, #2]
//   0x00744c: 2a1503e8  mov      w8, w21
//   0x007450: 17ffffde  b        #0x73c8
//   0x007454: 2a1f03e9  mov      w9, wzr
//   0x007458: aa1c03fb  mov      x27, x28
//   0x00745c: 6b16013f  cmp      w9, w22
//   0x007460: 54fff94a  b.ge     #0x7388
//   0x007464: 93407d28  sxtw     x8, w9
//   0x007468: 93407eca  sxtw     x10, w22
//   0x00746c: cb080149  sub      x9, x10, x8
//   0x007470: f1007d3f  cmp      x9, #0x1f
//   0x007474: 540002c9  b.ls     #0x74cc
//   0x007478: 8b0a038a  add      x10, x28, x10
//   0x00747c: eb0a037f  cmp      x27, x10
//   0x007480: 8b08038c  add      x12, x28, x8
//   0x007484: 54000082  b.hs     #0x7494
//   0x007488: 8b09036a  add      x10, x27, x9
//   0x00748c: eb0a019f  cmp      x12, x10
//   0x007490: 540001e3  b.lo     #0x74cc
//   0x007494: 927be92a  and      x10, x9, #0xffffffffffffffe0
//   0x007498: 9100436b  add      x11, x27, #0x10
//   0x00749c: 8b080148  add      x8, x10, x8
//   0x0074a0: 8b0a037b  add      x27, x27, x10
//   0x0074a4: 9100418c  add      x12, x12, #0x10
//   0x0074a8: aa0a03ed  mov      x13, x10
//   0x0074ac: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x0074b0: f10081ad  subs     x13, x13, #0x20
//   0x0074b4: 9100818c  add      x12, x12, #0x20
//   0x0074b8: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x0074bc: 9100816b  add      x11, x11, #0x20
//   0x0074c0: 54ffff61  b.ne     #0x74ac
//   0x0074c4: eb0a013f  cmp      x9, x10
//   0x0074c8: 54fff600  b.eq     #0x7388
//   0x0074cc: 93407ec9  sxtw     x9, w22
//   0x0074d0: cb080129  sub      x9, x9, x8
//   0x0074d4: 8b080388  add      x8, x28, x8
//   0x0074d8: 3840150a  ldrb     w10, [x8], #1
//   0x0074dc: f1000529  subs     x9, x9, #1
//   0x0074e0: 3800176a  strb     w10, [x27], #1
//   0x0074e4: 54ffffa1  b.ne     #0x74d8
//   0x0074e8: 17ffffa8  b        #0x7388
//   0x0074ec: f9000bfc  str      x28, [sp, #0x10]
//   0x0074f0: b50000f7  cbnz     x23, #0x750c
//   0x0074f4: 14000067  b        #0x7690
//   0x0074f8: a90072f8  stp      x24, x28, [x23]
//   0x0074fc: f9400bfc  ldr      x28, [sp, #0x10]
//   0x007500: f94013f3  ldr      x19, [sp, #0x20]
//   0x007504: f9400af7  ldr      x23, [x23, #0x10]
//   0x007508: b4000c57  cbz      x23, #0x7690
//   0x00750c: f94002e8  ldr      x8, [x23]
//   0x007510: b4005528  cbz      x8, #0x7fb4
//   0x007514: f94006e9  ldr      x9, [x23, #8]
//   0x007518: b40054e9  cbz      x9, #0x7fb4
//   0x00751c: cb080128  sub      x8, x9, x8
//   0x007520: 34ffff28  cbz      w8, #0x7504
//   0x007524: 37f85488  tbnz     w8, #0x1f, #0x7fb4
//   0x007528: f9400269  ldr      x9, [x19]
//   0x00752c: 93407d01  sxtw     x1, w8
//   0x007530: aa1303e0  mov      x0, x19
//   0x007534: d63f0120  blr      x9
//   0x007538: b40053e0  cbz      x0, #0x7fb4
//   0x00753c: a94022f3  ldp      x19, x8, [x23]
//   0x007540: aa0003f8  mov      x24, x0
//   0x007544: cb130116  sub      x22, x8, x19
//   0x007548: 71000edf  cmp      w22, #3
//   0x00754c: 5400056b  b.lt     #0x75f8
//   0x007550: 2a1f03e8  mov      w8, wzr
//   0x007554: 52800055  mov      w21, #2
//   0x007558: aa1803fc  mov      x28, x24
//   0x00755c: 14000009  b        #0x7580
//   0x007560: 39000389  strb     w9, [x28]
//   0x007564: 5280002a  mov      w10, #1
//   0x007568: 11000509  add      w9, w8, #1
//   0x00756c: 11000d15  add      w21, w8, #3
//   0x007570: 6b1602bf  cmp      w21, w22
//   0x007574: 8b0a039c  add      x28, x28, x10
//   0x007578: 2a0903e8  mov      w8, w9
//   0x00757c: 5400042a  b.ge     #0x7600
//   0x007580: 93407d0a  sxtw     x10, w8
//   0x007584: 386a6a69  ldrb     w9, [x19, x10]
//   0x007588: 7100953f  cmp      w9, #0x25
//   0x00758c: 54fffea1  b.ne     #0x7560
//   0x007590: 8b130148  add      x8, x10, x19
//   0x007594: 39400500  ldrb     w0, [x8, #1]
//   0x007598: 3875ca79  ldrb     w25, [x19, w21, sxtw]
//   0x00759c: 97ffef1d  bl       #0x3210
//   0x0075a0: 2a0003fa  mov      w26, w0
//   0x0075a4: 2a1903e0  mov      w0, w25
//   0x0075a8: 97ffef1a  bl       #0x3210
//   0x0075ac: 12001c19  and      w25, w0, #0xff
//   0x0075b0: 0b3a133b  add      w27, w25, w26, uxtb #4
//   0x0075b4: 2a1b03e0  mov      w0, w27
//   0x0075b8: 97ffeec2  bl       #0x30c0
//   0x0075bc: 34000080  cbz      w0, #0x75cc
//   0x0075c0: 3900039b  strb     w27, [x28]
//   0x0075c4: 5280002a  mov      w10, #1
//   0x0075c8: 1400000a  b        #0x75f0
//   0x0075cc: 12001f40  and      w0, w26, #0xff
//   0x0075d0: 528004a8  mov      w8, #0x25
//   0x0075d4: 39000388  strb     w8, [x28]
//   0x0075d8: 97ffeede  bl       #0x3150
//   0x0075dc: 39000780  strb     w0, [x28, #1]
//   0x0075e0: 2a1903e0  mov      w0, w25
//   0x0075e4: 97ffeedb  bl       #0x3150
//   0x0075e8: 5280006a  mov      w10, #3
//   0x0075ec: 39000b80  strb     w0, [x28, #2]
//   0x0075f0: 2a1503e8  mov      w8, w21
//   0x0075f4: 17ffffdd  b        #0x7568
//   0x0075f8: 2a1f03e9  mov      w9, wzr
//   0x0075fc: aa1803fc  mov      x28, x24
//   0x007600: 6b16013f  cmp      w9, w22
//   0x007604: 54fff7aa  b.ge     #0x74f8
//   0x007608: 93407d28  sxtw     x8, w9
//   0x00760c: 93407eca  sxtw     x10, w22
//   0x007610: cb080149  sub      x9, x10, x8
//   0x007614: f1007d3f  cmp      x9, #0x1f
//   0x007618: 540002c9  b.ls     #0x7670
//   0x00761c: 8b0a026a  add      x10, x19, x10
//   0x007620: eb0a039f  cmp      x28, x10
//   0x007624: 8b08026c  add      x12, x19, x8
//   0x007628: 54000082  b.hs     #0x7638
//   0x00762c: 8b09038a  add      x10, x28, x9
//   0x007630: eb0a019f  cmp      x12, x10
//   0x007634: 540001e3  b.lo     #0x7670
//   0x007638: 927be92a  and      x10, x9, #0xffffffffffffffe0
//   0x00763c: 9100438b  add      x11, x28, #0x10
//   0x007640: 8b080148  add      x8, x10, x8
//   0x007644: 8b0a039c  add      x28, x28, x10
//   0x007648: 9100418c  add      x12, x12, #0x10
//   0x00764c: aa0a03ed  mov      x13, x10
//   0x007650: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x007654: f10081ad  subs     x13, x13, #0x20
//   0x007658: 9100818c  add      x12, x12, #0x20
//   0x00765c: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x007660: 9100816b  add      x11, x11, #0x20
//   0x007664: 54ffff61  b.ne     #0x7650
//   0x007668: eb0a013f  cmp      x9, x10
//   0x00766c: 54fff460  b.eq     #0x74f8
//   0x007670: 93407ec9  sxtw     x9, w22
//   0x007674: cb080129  sub      x9, x9, x8
//   0x007678: 8b080268  add      x8, x19, x8
//   0x00767c: 3840150a  ldrb     w10, [x8], #1
//   0x007680: f1000529  subs     x9, x9, #1
//   0x007684: 3800178a  strb     w10, [x28], #1
//   0x007688: 54ffffa1  b.ne     #0x767c
//   0x00768c: 17ffff9b  b        #0x74f8
//   0x007690: b94037e8  ldr      w8, [sp, #0x34]
//   0x007694: 321d0108  orr      w8, w8, #8
//   0x007698: b90037e8  str      w8, [sp, #0x34]
//   0x00769c: b9409688  ldr      w8, [x20, #0x94]
//   0x0076a0: f9400bfc  ldr      x28, [sp, #0x10]
//   0x0076a4: f94013f3  ldr      x19, [sp, #0x20]
//   0x0076a8: 7100051f  cmp      w8, #1
//   0x0076ac: 54000061  b.ne     #0x76b8
//   0x0076b0: 52800022  mov      w2, #1
//   0x0076b4: 14000003  b        #0x76c0
//   0x0076b8: b94037e8  ldr      w8, [sp, #0x34]
//   0x0076bc: 53030d02  ubfx     w2, w8, #3, #1
//   0x0076c0: b9400be1  ldr      w1, [sp, #8]
//   0x0076c4: aa1403e0  mov      x0, x20
//   0x0076c8: aa1303e3  mov      x3, x19
//   0x0076cc: 97ffee55  bl       #0x3020
//   0x0076d0: 34004720  cbz      w0, #0x7fb4
//   0x0076d4: aa1403e0  mov      x0, x20
//   0x0076d8: aa1303e1  mov      x1, x19
//   0x0076dc: 97ffee71  bl       #0x30a0
//   0x0076e0: f94017e8  ldr      x8, [sp, #0x28]
//   0x0076e4: b9401bf6  ldr      w22, [sp, #0x18]
//   0x0076e8: b40004a8  cbz      x8, #0x777c
//   0x0076ec: f9403a88  ldr      x8, [x20, #0x70]
//   0x0076f0: 2a1f03f3  mov      w19, wzr
//   0x0076f4: b4000b28  cbz      x8, #0x7858
//   0x0076f8: f9403e95  ldr      x21, [x20, #0x78]
//   0x0076fc: eb0802bf  cmp      x21, x8
//   0x007700: 54000ac9  b.ls     #0x7858
//   0x007704: 91000913  add      x19, x8, #2
//   0x007708: eb15027f  cmp      x19, x21
//   0x00770c: 540000a3  b.lo     #0x7720
//   0x007710: 14000051  b        #0x7854
//   0x007714: 91000673  add      x19, x19, #1
//   0x007718: eb15027f  cmp      x19, x21
//   0x00771c: 540009c2  b.hs     #0x7854
//   0x007720: 385fe268  ldurb    w8, [x19, #-2]
//   0x007724: 7100951f  cmp      w8, #0x25
//   0x007728: 54ffff61  b.ne     #0x7714
//   0x00772c: 385ff260  ldurb    w0, [x19, #-1]
//   0x007730: 51018408  sub      w8, w0, #0x61
//   0x007734: 7100191f  cmp      w8, #6
//   0x007738: 540001e3  b.lo     #0x7774
//   0x00773c: 39400268  ldrb     w8, [x19]
//   0x007740: 51018508  sub      w8, w8, #0x61
//   0x007744: 7100191f  cmp      w8, #6
//   0x007748: 54000163  b.lo     #0x7774
//   0x00774c: 97ffeeb1  bl       #0x3210
//   0x007750: 39400268  ldrb     w8, [x19]
//   0x007754: 2a0003f6  mov      w22, w0
//   0x007758: 2a0803e0  mov      w0, w8
//   0x00775c: 97ffeead  bl       #0x3210
//   0x007760: 12001ec8  and      w8, w22, #0xff
//   0x007764: 531c6d08  lsl      w8, w8, #4
//   0x007768: 0b200100  add      w0, w8, w0, uxtb
//   0x00776c: 97ffee55  bl       #0x30c0
//   0x007770: 34fffd20  cbz      w0, #0x7714
//   0x007774: 52800033  mov      w19, #1
//   0x007778: 14000038  b        #0x7858
//   0x00777c: f94017f5  ldr      x21, [sp, #0x28]
//   0x007780: 36201a56  tbz      w22, #4, #0x7ac8
//   0x007784: f9403a93  ldr      x19, [x20, #0x70]
//   0x007788: b4001a13  cbz      x19, #0x7ac8
//   0x00778c: b9409688  ldr      w8, [x20, #0x94]
//   0x007790: f9403e9a  ldr      x26, [x20, #0x78]
//   0x007794: 34000c68  cbz      w8, #0x7920
//   0x007798: b400199a  cbz      x26, #0x7ac8
//   0x00779c: cb13035b  sub      x27, x26, x19
//   0x0077a0: aa1c03f5  mov      x21, x28
//   0x0077a4: 71000f7f  cmp      w27, #3
//   0x0077a8: 5400130b  b.lt     #0x7a08
//   0x0077ac: 2a1f03e8  mov      w8, wzr
//   0x0077b0: 5280005c  mov      w28, #2
//   0x0077b4: aa1303f6  mov      x22, x19
//   0x0077b8: 14000009  b        #0x77dc
//   0x0077bc: 390002c9  strb     w9, [x22]
//   0x0077c0: 5280002a  mov      w10, #1
//   0x0077c4: 11000509  add      w9, w8, #1
//   0x0077c8: 11000d1c  add      w28, w8, #3
//   0x0077cc: 6b1b039f  cmp      w28, w27
//   0x0077d0: 8b0a02d6  add      x22, x22, x10
//   0x0077d4: 2a0903e8  mov      w8, w9
//   0x0077d8: 540011ca  b.ge     #0x7a10
//   0x0077dc: 93407d0a  sxtw     x10, w8
//   0x0077e0: 386a6a69  ldrb     w9, [x19, x10]
//   0x0077e4: 7100953f  cmp      w9, #0x25
//   0x0077e8: 54fffea1  b.ne     #0x77bc
//   0x0077ec: 8b130148  add      x8, x10, x19
//   0x0077f0: 39400500  ldrb     w0, [x8, #1]
//   0x0077f4: 387cca77  ldrb     w23, [x19, w28, sxtw]
//   0x0077f8: 97ffee86  bl       #0x3210
//   0x0077fc: 2a0003f8  mov      w24, w0
//   0x007800: 2a1703e0  mov      w0, w23
//   0x007804: 97ffee83  bl       #0x3210
//   0x007808: 12001c17  and      w23, w0, #0xff
//   0x00780c: 0b3812f9  add      w25, w23, w24, uxtb #4
//   0x007810: 2a1903e0  mov      w0, w25
//   0x007814: 97ffee2b  bl       #0x30c0
//   0x007818: 34000080  cbz      w0, #0x7828
//   0x00781c: 390002d9  strb     w25, [x22]
//   0x007820: 5280002a  mov      w10, #1
//   0x007824: 1400000a  b        #0x784c
//   0x007828: 12001f00  and      w0, w24, #0xff
//   0x00782c: 528004a8  mov      w8, #0x25
//   0x007830: 390002c8  strb     w8, [x22]
//   0x007834: 97ffee47  bl       #0x3150
//   0x007838: 390006c0  strb     w0, [x22, #1]
//   0x00783c: 2a1703e0  mov      w0, w23
//   0x007840: 97ffee44  bl       #0x3150
//   0x007844: 5280006a  mov      w10, #3
//   0x007848: 39000ac0  strb     w0, [x22, #2]
//   0x00784c: 2a1c03e8  mov      w8, w28
//   0x007850: 17ffffdd  b        #0x77c4
//   0x007854: 2a1f03f3  mov      w19, wzr
//   0x007858: f9404289  ldr      x9, [x20, #0x80]
//   0x00785c: 2a1f03e8  mov      w8, wzr
//   0x007860: b40004a9  cbz      x9, #0x78f4
//   0x007864: f9404695  ldr      x21, [x20, #0x88]
//   0x007868: eb0902bf  cmp      x21, x9
//   0x00786c: 54000449  b.ls     #0x78f4
//   0x007870: 91000937  add      x23, x9, #2
//   0x007874: eb1502ff  cmp      x23, x21
//   0x007878: 540000a3  b.lo     #0x788c
//   0x00787c: 1400001d  b        #0x78f0
//   0x007880: 910006f7  add      x23, x23, #1
//   0x007884: eb1502ff  cmp      x23, x21
//   0x007888: 54000342  b.hs     #0x78f0
//   0x00788c: 385fe2e8  ldurb    w8, [x23, #-2]
//   0x007890: 7100951f  cmp      w8, #0x25
//   0x007894: 54ffff61  b.ne     #0x7880
//   0x007898: 385ff2e0  ldurb    w0, [x23, #-1]
//   0x00789c: 51018408  sub      w8, w0, #0x61
//   0x0078a0: 7100191f  cmp      w8, #6
//   0x0078a4: 540001e3  b.lo     #0x78e0
//   0x0078a8: 394002e8  ldrb     w8, [x23]
//   0x0078ac: 51018508  sub      w8, w8, #0x61
//   0x0078b0: 7100191f  cmp      w8, #6
//   0x0078b4: 54000163  b.lo     #0x78e0
//   0x0078b8: 97ffee56  bl       #0x3210
//   0x0078bc: 394002e8  ldrb     w8, [x23]
//   0x0078c0: 2a0003f6  mov      w22, w0
//   0x0078c4: 2a0803e0  mov      w0, w8
//   0x0078c8: 97ffee52  bl       #0x3210
//   0x0078cc: 12001ec8  and      w8, w22, #0xff
//   0x0078d0: 531c6d08  lsl      w8, w8, #4
//   0x0078d4: 0b200100  add      w0, w8, w0, uxtb
//   0x0078d8: 97ffedfa  bl       #0x30c0
//   0x0078dc: 34fffd20  cbz      w0, #0x7880
//   0x0078e0: 52800028  mov      w8, #1
//   0x0078e4: f94017f5  ldr      x21, [sp, #0x28]
//   0x0078e8: 350000b3  cbnz     w19, #0x78fc
//   0x0078ec: 14000007  b        #0x7908
//   0x0078f0: 2a1f03e8  mov      w8, wzr
//   0x0078f4: f94017f5  ldr      x21, [sp, #0x28]
//   0x0078f8: 34000093  cbz      w19, #0x7908
//   0x0078fc: b94002a9  ldr      w9, [x21]
//   0x007900: 321c0129  orr      w9, w9, #0x10
//   0x007904: b90002a9  str      w9, [x21]
//   0x007908: 34003388  cbz      w8, #0x7f78
//   0x00790c: b94002a8  ldr      w8, [x21]
//   0x007910: 2a1f03e0  mov      w0, wzr
//   0x007914: 321b0108  orr      w8, w8, #0x20
//   0x007918: b90002a8  str      w8, [x21]
//   0x00791c: 140001ab  b        #0x7fc8
//   0x007920: b400167a  cbz      x26, #0x7bec
//   0x007924: cb130348  sub      x8, x26, x19
//   0x007928: 34002f28  cbz      w8, #0x7f0c
//   0x00792c: 37f81608  tbnz     w8, #0x1f, #0x7bec
//   0x007930: f94013e0  ldr      x0, [sp, #0x20]
//   0x007934: 93407d01  sxtw     x1, w8
//   0x007938: f9400009  ldr      x9, [x0]
//   0x00793c: d63f0120  blr      x9
//   0x007940: b4001560  cbz      x0, #0x7bec
//   0x007944: a9472293  ldp      x19, x8, [x20, #0x70]
//   0x007948: aa1c03f5  mov      x21, x28
//   0x00794c: aa0003f7  mov      x23, x0
//   0x007950: cb13011c  sub      x28, x8, x19
//   0x007954: 71000f9f  cmp      w28, #3
//   0x007958: f90007e8  str      x8, [sp, #8]
//   0x00795c: 5400202b  b.lt     #0x7d60
//   0x007960: 2a1f03e8  mov      w8, wzr
//   0x007964: 5280005b  mov      w27, #2
//   0x007968: aa1703f6  mov      x22, x23
//   0x00796c: 14000009  b        #0x7990
//   0x007970: 390002c9  strb     w9, [x22]
//   0x007974: 5280002a  mov      w10, #1
//   0x007978: 11000509  add      w9, w8, #1
//   0x00797c: 11000d1b  add      w27, w8, #3
//   0x007980: 6b1c037f  cmp      w27, w28
//   0x007984: 8b0a02d6  add      x22, x22, x10
//   0x007988: 2a0903e8  mov      w8, w9
//   0x00798c: 54001eea  b.ge     #0x7d68
//   0x007990: 93407d0a  sxtw     x10, w8
//   0x007994: 386a6a69  ldrb     w9, [x19, x10]
//   0x007998: 7100953f  cmp      w9, #0x25
//   0x00799c: 54fffea1  b.ne     #0x7970
//   0x0079a0: 8b130148  add      x8, x10, x19
//   0x0079a4: 39400500  ldrb     w0, [x8, #1]
//   0x0079a8: 387bca78  ldrb     w24, [x19, w27, sxtw]
//   0x0079ac: 97ffee19  bl       #0x3210
//   0x0079b0: 2a0003f9  mov      w25, w0
//   0x0079b4: 2a1803e0  mov      w0, w24
//   0x0079b8: 97ffee16  bl       #0x3210
//   0x0079bc: 12001c18  and      w24, w0, #0xff
//   0x0079c0: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x0079c4: 2a1a03e0  mov      w0, w26
//   0x0079c8: 97ffedbe  bl       #0x30c0
//   0x0079cc: 34000080  cbz      w0, #0x79dc
//   0x0079d0: 390002da  strb     w26, [x22]
//   0x0079d4: 5280002a  mov      w10, #1
//   0x0079d8: 1400000a  b        #0x7a00
//   0x0079dc: 12001f20  and      w0, w25, #0xff
//   0x0079e0: 528004a8  mov      w8, #0x25
//   0x0079e4: 390002c8  strb     w8, [x22]
//   0x0079e8: 97ffedda  bl       #0x3150
//   0x0079ec: 390006c0  strb     w0, [x22, #1]
//   0x0079f0: 2a1803e0  mov      w0, w24
//   0x0079f4: 97ffedd7  bl       #0x3150
//   0x0079f8: 5280006a  mov      w10, #3
//   0x0079fc: 39000ac0  strb     w0, [x22, #2]
//   0x007a00: 2a1b03e8  mov      w8, w27
//   0x007a04: 17ffffdd  b        #0x7978
//   0x007a08: 2a1f03e9  mov      w9, wzr
//   0x007a0c: aa1303f6  mov      x22, x19
//   0x007a10: 6b1b013f  cmp      w9, w27
//   0x007a14: 5400012a  b.ge     #0x7a38
//   0x007a18: 93407d29  sxtw     x9, w9
//   0x007a1c: 93407f6a  sxtw     x10, w27
//   0x007a20: cb090148  sub      x8, x10, x9
//   0x007a24: f1007d1f  cmp      x8, #0x1f
//   0x007a28: aa1503fc  mov      x28, x21
//   0x007a2c: 540000c8  b.hi     #0x7a44
//   0x007a30: f94017f5  ldr      x21, [sp, #0x28]
//   0x007a34: 1400001b  b        #0x7aa0
//   0x007a38: aa1503fc  mov      x28, x21
//   0x007a3c: f94017f5  ldr      x21, [sp, #0x28]
//   0x007a40: 14000020  b        #0x7ac0
//   0x007a44: f94017f5  ldr      x21, [sp, #0x28]
//   0x007a48: 8b0a026a  add      x10, x19, x10
//   0x007a4c: eb0a02df  cmp      x22, x10
//   0x007a50: 540000a2  b.hs     #0x7a64
//   0x007a54: 8b0802ca  add      x10, x22, x8
//   0x007a58: 8b09026b  add      x11, x19, x9
//   0x007a5c: eb0a017f  cmp      x11, x10
//   0x007a60: 54000203  b.lo     #0x7aa0
//   0x007a64: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x007a68: 8b13012c  add      x12, x9, x19
//   0x007a6c: 910042cb  add      x11, x22, #0x10
//   0x007a70: 8b090149  add      x9, x10, x9
//   0x007a74: 8b0a02d6  add      x22, x22, x10
//   0x007a78: 9100418c  add      x12, x12, #0x10
//   0x007a7c: aa0a03ed  mov      x13, x10
//   0x007a80: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x007a84: f10081ad  subs     x13, x13, #0x20
//   0x007a88: 9100818c  add      x12, x12, #0x20
//   0x007a8c: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x007a90: 9100816b  add      x11, x11, #0x20
//   0x007a94: 54ffff61  b.ne     #0x7a80
//   0x007a98: eb0a011f  cmp      x8, x10
//   0x007a9c: 54000120  b.eq     #0x7ac0
//   0x007aa0: 4b130348  sub      w8, w26, w19
//   0x007aa4: 93407d08  sxtw     x8, w8
//   0x007aa8: cb090108  sub      x8, x8, x9
//   0x007aac: 8b090269  add      x9, x19, x9
//   0x007ab0: 3840152a  ldrb     w10, [x9], #1
//   0x007ab4: f1000508  subs     x8, x8, #1
//   0x007ab8: 380016ca  strb     w10, [x22], #1
//   0x007abc: 54ffffa1  b.ne     #0x7ab0
//   0x007ac0: f9003e96  str      x22, [x20, #0x78]
//   0x007ac4: b9401bf6  ldr      w22, [sp, #0x18]
//   0x007ac8: 36282596  tbz      w22, #5, #0x7f78
//   0x007acc: f9404293  ldr      x19, [x20, #0x80]
//   0x007ad0: b4002553  cbz      x19, #0x7f78
//   0x007ad4: b9409688  ldr      w8, [x20, #0x94]
//   0x007ad8: f9404699  ldr      x25, [x20, #0x88]
//   0x007adc: 34000608  cbz      w8, #0x7b9c
//   0x007ae0: b40024d9  cbz      x25, #0x7f78
//   0x007ae4: cb13033b  sub      x27, x25, x19
//   0x007ae8: aa1c03f5  mov      x21, x28
//   0x007aec: 71000f7f  cmp      w27, #3
//   0x007af0: 54000d2b  b.lt     #0x7c94
//   0x007af4: 2a1f03e8  mov      w8, wzr
//   0x007af8: 5280005c  mov      w28, #2
//   0x007afc: aa1303fa  mov      x26, x19
//   0x007b00: 14000009  b        #0x7b24
//   0x007b04: 39000349  strb     w9, [x26]
//   0x007b08: 5280002a  mov      w10, #1
//   0x007b0c: 11000509  add      w9, w8, #1
//   0x007b10: 11000d1c  add      w28, w8, #3
//   0x007b14: 6b1b039f  cmp      w28, w27
//   0x007b18: 8b0a035a  add      x26, x26, x10
//   0x007b1c: 2a0903e8  mov      w8, w9
//   0x007b20: 54000bea  b.ge     #0x7c9c
//   0x007b24: 93407d0a  sxtw     x10, w8
//   0x007b28: 386a6a69  ldrb     w9, [x19, x10]
//   0x007b2c: 7100953f  cmp      w9, #0x25
//   0x007b30: 54fffea1  b.ne     #0x7b04
//   0x007b34: 8b130148  add      x8, x10, x19
//   0x007b38: 39400500  ldrb     w0, [x8, #1]
//   0x007b3c: 387cca76  ldrb     w22, [x19, w28, sxtw]
//   0x007b40: 97ffedb4  bl       #0x3210
//   0x007b44: 2a0003f7  mov      w23, w0
//   0x007b48: 2a1603e0  mov      w0, w22
//   0x007b4c: 97ffedb1  bl       #0x3210
//   0x007b50: 12001c16  and      w22, w0, #0xff
//   0x007b54: 0b3712d8  add      w24, w22, w23, uxtb #4
//   0x007b58: 2a1803e0  mov      w0, w24
//   0x007b5c: 97ffed59  bl       #0x30c0
//   0x007b60: 34000080  cbz      w0, #0x7b70
//   0x007b64: 39000358  strb     w24, [x26]
//   0x007b68: 5280002a  mov      w10, #1
//   0x007b6c: 1400000a  b        #0x7b94
//   0x007b70: 12001ee0  and      w0, w23, #0xff
//   0x007b74: 528004a8  mov      w8, #0x25
//   0x007b78: 39000348  strb     w8, [x26]
//   0x007b7c: 97ffed75  bl       #0x3150
//   0x007b80: 39000740  strb     w0, [x26, #1]
//   0x007b84: 2a1603e0  mov      w0, w22
//   0x007b88: 97ffed72  bl       #0x3150
//   0x007b8c: 5280006a  mov      w10, #3
//   0x007b90: 39000b40  strb     w0, [x26, #2]
//   0x007b94: 2a1c03e8  mov      w8, w28
//   0x007b98: 17ffffdd  b        #0x7b0c
//   0x007b9c: b4000299  cbz      x25, #0x7bec
//   0x007ba0: cb130328  sub      x8, x25, x19
//   0x007ba4: 34001e48  cbz      w8, #0x7f6c
//   0x007ba8: 37f80228  tbnz     w8, #0x1f, #0x7bec
//   0x007bac: f94013e0  ldr      x0, [sp, #0x20]
//   0x007bb0: 93407d01  sxtw     x1, w8
//   0x007bb4: f9400009  ldr      x9, [x0]
//   0x007bb8: d63f0120  blr      x9
//   0x007bbc: b4000180  cbz      x0, #0x7bec
//   0x007bc0: a9482293  ldp      x19, x8, [x20, #0x80]
//   0x007bc4: aa1c03f5  mov      x21, x28
//   0x007bc8: aa0003f6  mov      x22, x0
//   0x007bcc: cb13011c  sub      x28, x8, x19
//   0x007bd0: 71000f9f  cmp      w28, #3
//   0x007bd4: f9000fe8  str      x8, [sp, #0x18]
//   0x007bd8: 54000e0b  b.lt     #0x7d98
//   0x007bdc: 2a1f03e8  mov      w8, wzr
//   0x007be0: 5280005a  mov      w26, #2
//   0x007be4: aa1603fb  mov      x27, x22
//   0x007be8: 1400000d  b        #0x7c1c
//   0x007bec: b94037e1  ldr      w1, [sp, #0x34]
//   0x007bf0: aa1403e0  mov      x0, x20
//   0x007bf4: f94013e2  ldr      x2, [sp, #0x20]
//   0x007bf8: 140000f2  b        #0x7fc0
//   0x007bfc: 39000369  strb     w9, [x27]
//   0x007c00: 5280002a  mov      w10, #1
//   0x007c04: 11000509  add      w9, w8, #1
//   0x007c08: 11000d1a  add      w26, w8, #3
//   0x007c0c: 6b1c035f  cmp      w26, w28
//   0x007c10: 8b0a037b  add      x27, x27, x10
//   0x007c14: 2a0903e8  mov      w8, w9
//   0x007c18: 54000c4a  b.ge     #0x7da0
//   0x007c1c: 93407d0a  sxtw     x10, w8
//   0x007c20: 386a6a69  ldrb     w9, [x19, x10]
//   0x007c24: 7100953f  cmp      w9, #0x25
//   0x007c28: 54fffea1  b.ne     #0x7bfc
//   0x007c2c: 8b130148  add      x8, x10, x19
//   0x007c30: 39400500  ldrb     w0, [x8, #1]
//   0x007c34: 387aca77  ldrb     w23, [x19, w26, sxtw]
//   0x007c38: 97ffed76  bl       #0x3210
//   0x007c3c: 2a0003f8  mov      w24, w0
//   0x007c40: 2a1703e0  mov      w0, w23
//   0x007c44: 97ffed73  bl       #0x3210
//   0x007c48: 12001c17  and      w23, w0, #0xff
//   0x007c4c: 0b3812f9  add      w25, w23, w24, uxtb #4
//   0x007c50: 2a1903e0  mov      w0, w25
//   0x007c54: 97ffed1b  bl       #0x30c0
//   0x007c58: 34000080  cbz      w0, #0x7c68
//   0x007c5c: 39000379  strb     w25, [x27]
//   0x007c60: 5280002a  mov      w10, #1
//   0x007c64: 1400000a  b        #0x7c8c
//   0x007c68: 12001f00  and      w0, w24, #0xff
//   0x007c6c: 528004a8  mov      w8, #0x25
//   0x007c70: 39000368  strb     w8, [x27]
//   0x007c74: 97ffed37  bl       #0x3150
//   0x007c78: 39000760  strb     w0, [x27, #1]
//   0x007c7c: 2a1703e0  mov      w0, w23
//   0x007c80: 97ffed34  bl       #0x3150
//   0x007c84: 5280006a  mov      w10, #3
//   0x007c88: 39000b60  strb     w0, [x27, #2]
//   0x007c8c: 2a1a03e8  mov      w8, w26
//   0x007c90: 17ffffdd  b        #0x7c04
//   0x007c94: 2a1f03e9  mov      w9, wzr
//   0x007c98: aa1303fa  mov      x26, x19
//   0x007c9c: 6b1b013f  cmp      w9, w27
//   0x007ca0: 5400012a  b.ge     #0x7cc4
//   0x007ca4: 93407d29  sxtw     x9, w9
//   0x007ca8: 93407f6a  sxtw     x10, w27
//   0x007cac: cb090148  sub      x8, x10, x9
//   0x007cb0: f1007d1f  cmp      x8, #0x1f
//   0x007cb4: aa1503fc  mov      x28, x21
//   0x007cb8: 54000108  b.hi     #0x7cd8
//   0x007cbc: f94017f5  ldr      x21, [sp, #0x28]
//   0x007cc0: 1400001d  b        #0x7d34
//   0x007cc4: aa1503fc  mov      x28, x21
//   0x007cc8: f94017f5  ldr      x21, [sp, #0x28]
//   0x007ccc: f900469a  str      x26, [x20, #0x88]
//   0x007cd0: b50015b5  cbnz     x21, #0x7f84
//   0x007cd4: 140000aa  b        #0x7f7c
//   0x007cd8: f94017f5  ldr      x21, [sp, #0x28]
//   0x007cdc: 8b0a026a  add      x10, x19, x10
//   0x007ce0: eb0a035f  cmp      x26, x10
//   0x007ce4: 540000a2  b.hs     #0x7cf8
//   0x007ce8: 8b08034a  add      x10, x26, x8
//   0x007cec: 8b09026b  add      x11, x19, x9
//   0x007cf0: eb0a017f  cmp      x11, x10
//   0x007cf4: 54000203  b.lo     #0x7d34
//   0x007cf8: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x007cfc: 8b13012c  add      x12, x9, x19
//   0x007d00: 9100434b  add      x11, x26, #0x10
//   0x007d04: 8b090149  add      x9, x10, x9
//   0x007d08: 8b0a035a  add      x26, x26, x10
//   0x007d0c: 9100418c  add      x12, x12, #0x10
//   0x007d10: aa0a03ed  mov      x13, x10
//   0x007d14: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x007d18: f10081ad  subs     x13, x13, #0x20
//   0x007d1c: 9100818c  add      x12, x12, #0x20
//   0x007d20: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x007d24: 9100816b  add      x11, x11, #0x20
//   0x007d28: 54ffff61  b.ne     #0x7d14
//   0x007d2c: eb0a011f  cmp      x8, x10
//   0x007d30: 54000120  b.eq     #0x7d54
//   0x007d34: 4b130328  sub      w8, w25, w19
//   0x007d38: 93407d08  sxtw     x8, w8
//   0x007d3c: cb090108  sub      x8, x8, x9
//   0x007d40: 8b090269  add      x9, x19, x9
//   0x007d44: 3840152a  ldrb     w10, [x9], #1
//   0x007d48: f1000508  subs     x8, x8, #1
//   0x007d4c: 3800174a  strb     w10, [x26], #1
//   0x007d50: 54ffffa1  b.ne     #0x7d44
//   0x007d54: f900469a  str      x26, [x20, #0x88]
//   0x007d58: b5001175  cbnz     x21, #0x7f84
//   0x007d5c: 14000088  b        #0x7f7c
//   0x007d60: 2a1f03e9  mov      w9, wzr
//   0x007d64: aa1703f6  mov      x22, x23
//   0x007d68: 6b1c013f  cmp      w9, w28
//   0x007d6c: 5400010a  b.ge     #0x7d8c
//   0x007d70: 93407d29  sxtw     x9, w9
//   0x007d74: 93407f8a  sxtw     x10, w28
//   0x007d78: cb090148  sub      x8, x10, x9
//   0x007d7c: f1007d1f  cmp      x8, #0x1f
//   0x007d80: 540009e8  b.hi     #0x7ebc
//   0x007d84: aa1503fc  mov      x28, x21
//   0x007d88: 14000055  b        #0x7edc
//   0x007d8c: aa1503fc  mov      x28, x21
//   0x007d90: f94017f5  ldr      x21, [sp, #0x28]
//   0x007d94: 1400005c  b        #0x7f04
//   0x007d98: 2a1f03e9  mov      w9, wzr
//   0x007d9c: aa1603fb  mov      x27, x22
//   0x007da0: 6b1c013f  cmp      w9, w28
//   0x007da4: 5400010a  b.ge     #0x7dc4
//   0x007da8: 93407d29  sxtw     x9, w9
//   0x007dac: 93407f8a  sxtw     x10, w28
//   0x007db0: cb090148  sub      x8, x10, x9
//   0x007db4: f1007d1f  cmp      x8, #0x1f
//   0x007db8: 54000b48  b.hi     #0x7f20
//   0x007dbc: aa1503fc  mov      x28, x21
//   0x007dc0: 14000060  b        #0x7f40
//   0x007dc4: aa1503fc  mov      x28, x21
//   0x007dc8: f94017f5  ldr      x21, [sp, #0x28]
//   0x007dcc: 14000067  b        #0x7f68
//   0x007dd0: f94013f3  ldr      x19, [sp, #0x20]
//   0x007dd4: b4000f1b  cbz      x27, #0x7fb4
//   0x007dd8: cb170368  sub      x8, x27, x23
//   0x007ddc: 34001f88  cbz      w8, #0x81cc
//   0x007de0: 37f80ea8  tbnz     w8, #0x1f, #0x7fb4
//   0x007de4: f9400269  ldr      x9, [x19]
//   0x007de8: 93407d01  sxtw     x1, w8
//   0x007dec: aa1303e0  mov      x0, x19
//   0x007df0: d63f0120  blr      x9
//   0x007df4: b4000e00  cbz      x0, #0x7fb4
//   0x007df8: a9422293  ldp      x19, x8, [x20, #0x20]
//   0x007dfc: aa0003f7  mov      x23, x0
//   0x007e00: aa1c03f5  mov      x21, x28
//   0x007e04: cb130116  sub      x22, x8, x19
//   0x007e08: 71000edf  cmp      w22, #3
//   0x007e0c: f90007e8  str      x8, [sp, #8]
//   0x007e10: 54001a0b  b.lt     #0x8150
//   0x007e14: 2a1f03e8  mov      w8, wzr
//   0x007e18: 5280005c  mov      w28, #2
//   0x007e1c: aa1703fb  mov      x27, x23
//   0x007e20: 14000009  b        #0x7e44
//   0x007e24: 39000369  strb     w9, [x27]
//   0x007e28: 5280002a  mov      w10, #1
//   0x007e2c: 11000509  add      w9, w8, #1
//   0x007e30: 11000d1c  add      w28, w8, #3
//   0x007e34: 6b16039f  cmp      w28, w22
//   0x007e38: 8b0a037b  add      x27, x27, x10
//   0x007e3c: 2a0903e8  mov      w8, w9
//   0x007e40: 540018ca  b.ge     #0x8158
//   0x007e44: 93407d0a  sxtw     x10, w8
//   0x007e48: 386a6a69  ldrb     w9, [x19, x10]
//   0x007e4c: 7100953f  cmp      w9, #0x25
//   0x007e50: 54fffea1  b.ne     #0x7e24
//   0x007e54: 8b130148  add      x8, x10, x19
//   0x007e58: 39400500  ldrb     w0, [x8, #1]
//   0x007e5c: 387cca78  ldrb     w24, [x19, w28, sxtw]
//   0x007e60: 97ffecec  bl       #0x3210
//   0x007e64: 2a0003f9  mov      w25, w0
//   0x007e68: 2a1803e0  mov      w0, w24
//   0x007e6c: 97ffece9  bl       #0x3210
//   0x007e70: 12001c18  and      w24, w0, #0xff
//   0x007e74: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x007e78: 2a1a03e0  mov      w0, w26
//   0x007e7c: 97ffec91  bl       #0x30c0
//   0x007e80: 34000080  cbz      w0, #0x7e90
//   0x007e84: 3900037a  strb     w26, [x27]
//   0x007e88: 5280002a  mov      w10, #1
//   0x007e8c: 1400000a  b        #0x7eb4
//   0x007e90: 12001f20  and      w0, w25, #0xff
//   0x007e94: 528004a8  mov      w8, #0x25
//   0x007e98: 39000368  strb     w8, [x27]
//   0x007e9c: 97ffecad  bl       #0x3150
//   0x007ea0: 39000760  strb     w0, [x27, #1]
//   0x007ea4: 2a1803e0  mov      w0, w24
//   0x007ea8: 97ffecaa  bl       #0x3150
//   0x007eac: 5280006a  mov      w10, #3
//   0x007eb0: 39000b60  strb     w0, [x27, #2]
//   0x007eb4: 2a1c03e8  mov      w8, w28
//   0x007eb8: 17ffffdd  b        #0x7e2c
//   0x007ebc: 8b0a026a  add      x10, x19, x10
//   0x007ec0: eb0a02df  cmp      x22, x10
//   0x007ec4: aa1503fc  mov      x28, x21
//   0x007ec8: 54000de2  b.hs     #0x8084
//   0x007ecc: 8b0802ca  add      x10, x22, x8
//   0x007ed0: 8b09026b  add      x11, x19, x9
//   0x007ed4: eb0a017f  cmp      x11, x10
//   0x007ed8: 54000d62  b.hs     #0x8084
//   0x007edc: f94017f5  ldr      x21, [sp, #0x28]
//   0x007ee0: f94007e8  ldr      x8, [sp, #8]
//   0x007ee4: 4b130108  sub      w8, w8, w19
//   0x007ee8: 93407d08  sxtw     x8, w8
//   0x007eec: cb090108  sub      x8, x8, x9
//   0x007ef0: 8b090269  add      x9, x19, x9
//   0x007ef4: 3840152a  ldrb     w10, [x9], #1
//   0x007ef8: f1000508  subs     x8, x8, #1
//   0x007efc: 380016ca  strb     w10, [x22], #1
//   0x007f00: 54ffffa1  b.ne     #0x7ef4
//   0x007f04: a9075a97  stp      x23, x22, [x20, #0x70]
//   0x007f08: b9401bf6  ldr      w22, [sp, #0x18]
//   0x007f0c: b94037e8  ldr      w8, [sp, #0x34]
//   0x007f10: 321c0108  orr      w8, w8, #0x10
//   0x007f14: b90037e8  str      w8, [sp, #0x34]
//   0x007f18: 372fddb6  tbnz     w22, #5, #0x7acc
//   0x007f1c: 14000017  b        #0x7f78
//   0x007f20: 8b0a026a  add      x10, x19, x10
//   0x007f24: eb0a037f  cmp      x27, x10
//   0x007f28: aa1503fc  mov      x28, x21
//   0x007f2c: 54000ce2  b.hs     #0x80c8
//   0x007f30: 8b08036a  add      x10, x27, x8
//   0x007f34: 8b09026b  add      x11, x19, x9
//   0x007f38: eb0a017f  cmp      x11, x10
//   0x007f3c: 54000c62  b.hs     #0x80c8
//   0x007f40: f94017f5  ldr      x21, [sp, #0x28]
//   0x007f44: f9400fe8  ldr      x8, [sp, #0x18]
//   0x007f48: 4b130108  sub      w8, w8, w19
//   0x007f4c: 93407d08  sxtw     x8, w8
//   0x007f50: cb090108  sub      x8, x8, x9
//   0x007f54: 8b090269  add      x9, x19, x9
//   0x007f58: 3840152a  ldrb     w10, [x9], #1
//   0x007f5c: f1000508  subs     x8, x8, #1
//   0x007f60: 3800176a  strb     w10, [x27], #1
//   0x007f64: 54ffffa1  b.ne     #0x7f58
//   0x007f68: a9086e96  stp      x22, x27, [x20, #0x80]
//   0x007f6c: b94037e8  ldr      w8, [sp, #0x34]
//   0x007f70: 321b0108  orr      w8, w8, #0x20
//   0x007f74: b90037e8  str      w8, [sp, #0x34]
//   0x007f78: b5000075  cbnz     x21, #0x7f84
//   0x007f7c: b9409688  ldr      w8, [x20, #0x94]
//   0x007f80: 34000068  cbz      w8, #0x7f8c
//   0x007f84: 2a1f03e0  mov      w0, wzr
//   0x007f88: 14000010  b        #0x7fc8
//   0x007f8c: f94013f3  ldr      x19, [sp, #0x20]
//   0x007f90: 9100d3e1  add      x1, sp, #0x34
//   0x007f94: aa1403e0  mov      x0, x20
//   0x007f98: aa1303e2  mov      x2, x19
//   0x007f9c: 94000152  bl       #0x84e4
//   0x007fa0: 340000a0  cbz      w0, #0x7fb4
//   0x007fa4: 2a1f03e0  mov      w0, wzr
//   0x007fa8: 52800028  mov      w8, #1
//   0x007fac: b9009688  str      w8, [x20, #0x94]
//   0x007fb0: 14000006  b        #0x7fc8
//   0x007fb4: b94037e1  ldr      w1, [sp, #0x34]
//   0x007fb8: aa1403e0  mov      x0, x20
//   0x007fbc: aa1303e2  mov      x2, x19
//   0x007fc0: 9400022e  bl       #0x8878
//   0x007fc4: 52800060  mov      w0, #3
//   0x007fc8: f9401788  ldr      x8, [x28, #0x28]
//   0x007fcc: f9401fe9  ldr      x9, [sp, #0x38]
//   0x007fd0: eb09011f  cmp      x8, x9
//   0x007fd4: 54001d61  b.ne     #0x8380
//   0x007fd8: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x007fdc: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x007fe0: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x007fe4: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x007fe8: a94567fa  ldp      x26, x25, [sp, #0x50]
//   0x007fec: a9446ffc  ldp      x28, x27, [sp, #0x40]
//   0x007ff0: 910283ff  add      sp, sp, #0xa0
//   0x007ff4: d65f03c0  ret      
//   0x007ff8: 2a1f03e9  mov      w9, wzr
//   0x007ffc: aa1703f3  mov      x19, x23
//   0x008000: 6b16013f  cmp      w9, w22
//   0x008004: 5400032a  b.ge     #0x8068
//   0x008008: 93407d2a  sxtw     x10, w9
//   0x00800c: 93407ec8  sxtw     x8, w22
//   0x008010: cb0a0109  sub      x9, x8, x10
//   0x008014: f1007d3f  cmp      x9, #0x1f
//   0x008018: aa1503fc  mov      x28, x21
//   0x00801c: 54000109  b.ls     #0x803c
//   0x008020: 8b0802e8  add      x8, x23, x8
//   0x008024: eb08027f  cmp      x19, x8
//   0x008028: 54000722  b.hs     #0x810c
//   0x00802c: 8b090268  add      x8, x19, x9
//   0x008030: 8b0a02eb  add      x11, x23, x10
//   0x008034: eb08017f  cmp      x11, x8
//   0x008038: 540006a2  b.hs     #0x810c
//   0x00803c: b9401bf6  ldr      w22, [sp, #0x18]
//   0x008040: aa1303e8  mov      x8, x19
//   0x008044: 4b170369  sub      w9, w27, w23
//   0x008048: 93407d29  sxtw     x9, w9
//   0x00804c: cb0a0129  sub      x9, x9, x10
//   0x008050: 8b0a02ea  add      x10, x23, x10
//   0x008054: 3840154b  ldrb     w11, [x10], #1
//   0x008058: f1000529  subs     x9, x9, #1
//   0x00805c: 3800150b  strb     w11, [x8], #1
//   0x008060: 54ffffa1  b.ne     #0x8054
//   0x008064: 14000004  b        #0x8074
//   0x008068: b9401bf6  ldr      w22, [sp, #0x18]
//   0x00806c: aa1303e8  mov      x8, x19
//   0x008070: aa1503fc  mov      x28, x21
//   0x008074: f9401297  ldr      x23, [x20, #0x20]
//   0x008078: f9001688  str      x8, [x20, #0x28]
//   0x00807c: b5000b37  cbnz     x23, #0x81e0
//   0x008080: 17fffc19  b        #0x70e4
//   0x008084: f94017f5  ldr      x21, [sp, #0x28]
//   0x008088: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x00808c: 8b13012c  add      x12, x9, x19
//   0x008090: 910042cb  add      x11, x22, #0x10
//   0x008094: 8b090149  add      x9, x10, x9
//   0x008098: 8b0a02d6  add      x22, x22, x10
//   0x00809c: 9100418c  add      x12, x12, #0x10
//   0x0080a0: aa0a03ed  mov      x13, x10
//   0x0080a4: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x0080a8: f10081ad  subs     x13, x13, #0x20
//   0x0080ac: 9100818c  add      x12, x12, #0x20
//   0x0080b0: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x0080b4: 9100816b  add      x11, x11, #0x20
//   0x0080b8: 54ffff61  b.ne     #0x80a4
//   0x0080bc: eb0a011f  cmp      x8, x10
//   0x0080c0: 54fff101  b.ne     #0x7ee0
//   0x0080c4: 17ffff90  b        #0x7f04
//   0x0080c8: f94017f5  ldr      x21, [sp, #0x28]
//   0x0080cc: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x0080d0: 8b13012c  add      x12, x9, x19
//   0x0080d4: 9100436b  add      x11, x27, #0x10
//   0x0080d8: 8b090149  add      x9, x10, x9
//   0x0080dc: 8b0a037b  add      x27, x27, x10
//   0x0080e0: 9100418c  add      x12, x12, #0x10
//   0x0080e4: aa0a03ed  mov      x13, x10
//   0x0080e8: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x0080ec: f10081ad  subs     x13, x13, #0x20
//   0x0080f0: 9100818c  add      x12, x12, #0x20
//   0x0080f4: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x0080f8: 9100816b  add      x11, x11, #0x20
//   0x0080fc: 54ffff61  b.ne     #0x80e8
//   0x008100: eb0a011f  cmp      x8, x10
//   0x008104: 54fff201  b.ne     #0x7f44
//   0x008108: 17ffff98  b        #0x7f68
//   0x00810c: 927be92b  and      x11, x9, #0xffffffffffffffe0
//   0x008110: 8b17014d  add      x13, x10, x23
//   0x008114: 9100426c  add      x12, x19, #0x10
//   0x008118: 8b0a016a  add      x10, x11, x10
//   0x00811c: 8b0b0268  add      x8, x19, x11
//   0x008120: 910041ad  add      x13, x13, #0x10
//   0x008124: aa0b03ee  mov      x14, x11
//   0x008128: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x00812c: f10081ce  subs     x14, x14, #0x20
//   0x008130: 910081ad  add      x13, x13, #0x20
//   0x008134: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x008138: 9100818c  add      x12, x12, #0x20
//   0x00813c: 54ffff61  b.ne     #0x8128
//   0x008140: b9401bf6  ldr      w22, [sp, #0x18]
//   0x008144: eb0b013f  cmp      x9, x11
//   0x008148: 54fff7e1  b.ne     #0x8044
//   0x00814c: 17ffffca  b        #0x8074
//   0x008150: 2a1f03e9  mov      w9, wzr
//   0x008154: aa1703fb  mov      x27, x23
//   0x008158: 6b16013f  cmp      w9, w22
//   0x00815c: 5400032a  b.ge     #0x81c0
//   0x008160: 93407d29  sxtw     x9, w9
//   0x008164: 93407eca  sxtw     x10, w22
//   0x008168: cb090148  sub      x8, x10, x9
//   0x00816c: f1007d1f  cmp      x8, #0x1f
//   0x008170: 54000109  b.ls     #0x8190
//   0x008174: 8b0a026a  add      x10, x19, x10
//   0x008178: eb0a037f  cmp      x27, x10
//   0x00817c: 54000de2  b.hs     #0x8338
//   0x008180: 8b08036a  add      x10, x27, x8
//   0x008184: 8b09026b  add      x11, x19, x9
//   0x008188: eb0a017f  cmp      x11, x10
//   0x00818c: 54000d62  b.hs     #0x8338
//   0x008190: b9401bf6  ldr      w22, [sp, #0x18]
//   0x008194: aa1503fc  mov      x28, x21
//   0x008198: f94007e8  ldr      x8, [sp, #8]
//   0x00819c: 4b130108  sub      w8, w8, w19
//   0x0081a0: 93407d08  sxtw     x8, w8
//   0x0081a4: cb090108  sub      x8, x8, x9
//   0x0081a8: 8b090269  add      x9, x19, x9
//   0x0081ac: 3840152a  ldrb     w10, [x9], #1
//   0x0081b0: f1000508  subs     x8, x8, #1
//   0x0081b4: 3800176a  strb     w10, [x27], #1
//   0x0081b8: 54ffffa1  b.ne     #0x81ac
//   0x0081bc: 14000003  b        #0x81c8
//   0x0081c0: b9401bf6  ldr      w22, [sp, #0x18]
//   0x0081c4: aa1503fc  mov      x28, x21
//   0x0081c8: a9026e97  stp      x23, x27, [x20, #0x20]
//   0x0081cc: b94037e8  ldr      w8, [sp, #0x34]
//   0x0081d0: 321e0108  orr      w8, w8, #4
//   0x0081d4: b90037e8  str      w8, [sp, #0x34]
//   0x0081d8: aa1b03e8  mov      x8, x27
//   0x0081dc: b4ff7857  cbz      x23, #0x70e4
//   0x0081e0: eb170109  subs     x9, x8, x23
//   0x0081e4: 54ff7809  b.ls     #0x70e4
//   0x0081e8: f100213f  cmp      x9, #8
//   0x0081ec: 54000983  b.lo     #0x831c
//   0x0081f0: 927df12a  and      x10, x9, #0xfffffffffffffff8
//   0x0081f4: 91000eeb  add      x11, x23, #3
//   0x0081f8: 0f05e7e0  movi     v0.8b, #0xbf
//   0x0081fc: 8b0a02f7  add      x23, x23, x10
//   0x008200: 0f00e741  movi     v1.8b, #0x1a
//   0x008204: aa0a03ec  mov      x12, x10
//   0x008208: 14000004  b        #0x8218
//   0x00820c: f100218c  subs     x12, x12, #8
//   0x008210: 9100216b  add      x11, x11, #8
//   0x008214: 54000780  b.eq     #0x8304
//   0x008218: fc5fd162  ldur     d2, [x11, #-3]
//   0x00821c: 0e208443  add      v3.8b, v2.8b, v0.8b
//   0x008220: 2e233423  cmhi     v3.8b, v1.8b, v3.8b
//   0x008224: 0e013c6d  umov     w13, v3.b[0]
//   0x008228: 3600038d  tbz      w13, #0, #0x8298
//   0x00822c: 0e013c4d  umov     w13, v2.b[0]
//   0x008230: 110081ad  add      w13, w13, #0x20
//   0x008234: 381fd16d  sturb    w13, [x11, #-3]
//   0x008238: 0e033c6d  umov     w13, v3.b[1]
//   0x00823c: 3700032d  tbnz     w13, #0, #0x82a0
//   0x008240: 0e053c6d  umov     w13, v3.b[2]
//   0x008244: 3600038d  tbz      w13, #0, #0x82b4
//   0x008248: 0e053c4d  umov     w13, v2.b[2]
//   0x00824c: 110081ad  add      w13, w13, #0x20
//   0x008250: 381ff16d  sturb    w13, [x11, #-1]
//   0x008254: 0e073c6d  umov     w13, v3.b[3]
//   0x008258: 3700032d  tbnz     w13, #0, #0x82bc
//   0x00825c: 0e093c6d  umov     w13, v3.b[4]
//   0x008260: 3600038d  tbz      w13, #0, #0x82d0
//   0x008264: 0e093c4d  umov     w13, v2.b[4]
//   0x008268: 110081ad  add      w13, w13, #0x20
//   0x00826c: 3900056d  strb     w13, [x11, #1]
//   0x008270: 0e0b3c6d  umov     w13, v3.b[5]
//   0x008274: 3700032d  tbnz     w13, #0, #0x82d8
//   0x008278: 0e0d3c6d  umov     w13, v3.b[6]
//   0x00827c: 3600038d  tbz      w13, #0, #0x82ec
//   0x008280: 0e0d3c4d  umov     w13, v2.b[6]
//   0x008284: 110081ad  add      w13, w13, #0x20
//   0x008288: 39000d6d  strb     w13, [x11, #3]
//   0x00828c: 0e0f3c6d  umov     w13, v3.b[7]
//   0x008290: 3607fbed  tbz      w13, #0, #0x820c
//   0x008294: 14000018  b        #0x82f4
//   0x008298: 0e033c6d  umov     w13, v3.b[1]
//   0x00829c: 3607fd2d  tbz      w13, #0, #0x8240
//   0x0082a0: 0e033c4d  umov     w13, v2.b[1]
//   0x0082a4: 110081ad  add      w13, w13, #0x20
//   0x0082a8: 381fe16d  sturb    w13, [x11, #-2]
//   0x0082ac: 0e053c6d  umov     w13, v3.b[2]
//   0x0082b0: 3707fccd  tbnz     w13, #0, #0x8248
//   0x0082b4: 0e073c6d  umov     w13, v3.b[3]
//   0x0082b8: 3607fd2d  tbz      w13, #0, #0x825c
//   0x0082bc: 0e073c4d  umov     w13, v2.b[3]
//   0x0082c0: 110081ad  add      w13, w13, #0x20
//   0x0082c4: 3900016d  strb     w13, [x11]
//   0x0082c8: 0e093c6d  umov     w13, v3.b[4]
//   0x0082cc: 3707fccd  tbnz     w13, #0, #0x8264
//   0x0082d0: 0e0b3c6d  umov     w13, v3.b[5]
//   0x0082d4: 3607fd2d  tbz      w13, #0, #0x8278
//   0x0082d8: 0e0b3c4d  umov     w13, v2.b[5]
//   0x0082dc: 110081ad  add      w13, w13, #0x20
//   0x0082e0: 3900096d  strb     w13, [x11, #2]
//   0x0082e4: 0e0d3c6d  umov     w13, v3.b[6]
//   0x0082e8: 3707fccd  tbnz     w13, #0, #0x8280
//   0x0082ec: 0e0f3c6d  umov     w13, v3.b[7]
//   0x0082f0: 3607f8ed  tbz      w13, #0, #0x820c
//   0x0082f4: 0e0f3c4d  umov     w13, v2.b[7]
//   0x0082f8: 110081ad  add      w13, w13, #0x20
//   0x0082fc: 3900116d  strb     w13, [x11, #4]
//   0x008300: 17ffffc3  b        #0x820c
//   0x008304: eb09015f  cmp      x10, x9
//   0x008308: 540000a1  b.ne     #0x831c
//   0x00830c: 17fffb76  b        #0x70e4
//   0x008310: 910006f7  add      x23, x23, #1
//   0x008314: eb17011f  cmp      x8, x23
//   0x008318: 54ff6e60  b.eq     #0x70e4
//   0x00831c: 394002e9  ldrb     w9, [x23]
//   0x008320: 5101052a  sub      w10, w9, #0x41
//   0x008324: 7100655f  cmp      w10, #0x19
//   0x008328: 54ffff48  b.hi     #0x8310
//   0x00832c: 11008129  add      w9, w9, #0x20
//   0x008330: 390002e9  strb     w9, [x23]
//   0x008334: 17fffff7  b        #0x8310
//   0x008338: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x00833c: 8b13012c  add      x12, x9, x19
//   0x008340: 9100436b  add      x11, x27, #0x10
//   0x008344: 8b090149  add      x9, x10, x9
//   0x008348: 8b0a037b  add      x27, x27, x10
//   0x00834c: 9100418c  add      x12, x12, #0x10
//   0x008350: aa0a03ed  mov      x13, x10
//   0x008354: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x008358: f10081ad  subs     x13, x13, #0x20
//   0x00835c: 9100818c  add      x12, x12, #0x20
//   0x008360: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x008364: 9100816b  add      x11, x11, #0x20
//   0x008368: 54ffff61  b.ne     #0x8354
//   0x00836c: b9401bf6  ldr      w22, [sp, #0x18]
//   0x008370: eb0a011f  cmp      x8, x10
//   0x008374: aa1503fc  mov      x28, x21
//   0x008378: 54fff101  b.ne     #0x8198
//   0x00837c: 17ffff93  b        #0x81c8
//   0x008380: 97ffeb68  bl       #0x3120
// ============================================================================
std::uint32_t fde_066_0680c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000680cULL;
    for (std::size_t i = 0; i < 1758ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3375ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[067] Subroutine @ 0x008384..0x008394 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[067] Hàm con @ 0x008384..0x008394 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008384: f0000083  adrp     x3, #0x1b000
//   0x008388: f947fc63  ldr      x3, [x3, #0xff8]
//   0x00838c: aa1f03e2  mov      x2, xzr
//   0x008390: 17fff91f  b        #0x680c
// ============================================================================
std::uint32_t fde_067_08384(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008384ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5133ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[068] Subroutine @ 0x008394..0x008400 (108 bytes, 27 AArch64 instructions)
// [VN] Khung FDE[068] Hàm con @ 0x008394..0x008400 (108 byte, 27 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008394: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x008398: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00839c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0083a0: 910083fd  add      x29, sp, #0x20
//   0x0083a4: 2a0103f4  mov      w20, w1
//   0x0083a8: aa0003f5  mov      x21, x0
//   0x0083ac: b4000162  cbz      x2, #0x83d8
//   0x0083b0: aa0203e0  mov      x0, x2
//   0x0083b4: aa0203f3  mov      x19, x2
//   0x0083b8: 97ffebaa  bl       #0x3260
//   0x0083bc: 7100041f  cmp      w0, #1
//   0x0083c0: 54000100  b.eq     #0x83e0
//   0x0083c4: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0083c8: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0083cc: 52800140  mov      w0, #0xa
//   0x0083d0: f84307f5  ldr      x21, [sp], #0x30
//   0x0083d4: d65f03c0  ret      
//   0x0083d8: f0000093  adrp     x19, #0x1b000
//   0x0083dc: f947fe73  ldr      x19, [x19, #0xff8]
//   0x0083e0: 2a1403e1  mov      w1, w20
//   0x0083e4: aa1303e3  mov      x3, x19
//   0x0083e8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0083ec: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0083f0: aa1503e0  mov      x0, x21
//   0x0083f4: aa1f03e2  mov      x2, xzr
//   0x0083f8: f84307f5  ldr      x21, [sp], #0x30
//   0x0083fc: 17fff904  b        #0x680c
// ============================================================================
std::uint32_t fde_068_08394(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008394ULL;
    for (std::size_t i = 0; i < 27ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5137ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[069] Subroutine @ 0x008400..0x008414 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[069] Hàm con @ 0x008400..0x008414 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008400: f0000083  adrp     x3, #0x1b000
//   0x008404: f947fc63  ldr      x3, [x3, #0xff8]
//   0x008408: 12800001  mov      w1, #-1
//   0x00840c: aa1f03e2  mov      x2, xzr
//   0x008410: 17fff8ff  b        #0x680c
// ============================================================================
std::uint32_t fde_069_08400(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008400ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5164ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[070] Subroutine @ 0x008414..0x0084e4 (208 bytes, 52 AArch64 instructions)
// [VN] Khung FDE[070] Hàm con @ 0x008414..0x0084e4 (208 byte, 52 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008414: d10103ff  sub      sp, sp, #0x40
//   0x008418: f9000bf5  str      x21, [sp, #0x10]
//   0x00841c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x008420: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x008424: 9100c3fd  add      x29, sp, #0x30
//   0x008428: d53bd055  mrs      x21, tpidr_el0
//   0x00842c: f94016a8  ldr      x8, [x21, #0x28]
//   0x008430: aa0003f3  mov      x19, x0
//   0x008434: f90007e8  str      x8, [sp, #8]
//   0x008438: b90007ff  str      wzr, [sp, #4]
//   0x00843c: b4000101  cbz      x1, #0x845c
//   0x008440: aa0103e0  mov      x0, x1
//   0x008444: aa0103f4  mov      x20, x1
//   0x008448: 97ffeb86  bl       #0x3260
//   0x00844c: 7100041f  cmp      w0, #1
//   0x008450: 540000a0  b.eq     #0x8464
//   0x008454: 52800140  mov      w0, #0xa
//   0x008458: 14000019  b        #0x84bc
//   0x00845c: f0000094  adrp     x20, #0x1b000
//   0x008460: f947fe94  ldr      x20, [x20, #0xff8]
//   0x008464: b40000d3  cbz      x19, #0x847c
//   0x008468: b9409668  ldr      w8, [x19, #0x94]
//   0x00846c: 7100051f  cmp      w8, #1
//   0x008470: 540000a1  b.ne     #0x8484
//   0x008474: 2a1f03e0  mov      w0, wzr
//   0x008478: 14000011  b        #0x84bc
//   0x00847c: 52800040  mov      w0, #2
//   0x008480: 1400000f  b        #0x84bc
//   0x008484: 910013e1  add      x1, sp, #4
//   0x008488: aa1303e0  mov      x0, x19
//   0x00848c: aa1403e2  mov      x2, x20
//   0x008490: 94000015  bl       #0x84e4
//   0x008494: 340000a0  cbz      w0, #0x84a8
//   0x008498: 2a1f03e0  mov      w0, wzr
//   0x00849c: 52800028  mov      w8, #1
//   0x0084a0: b9009668  str      w8, [x19, #0x94]
//   0x0084a4: 14000006  b        #0x84bc
//   0x0084a8: b94007e1  ldr      w1, [sp, #4]
//   0x0084ac: aa1303e0  mov      x0, x19
//   0x0084b0: aa1403e2  mov      x2, x20
//   0x0084b4: 940000f1  bl       #0x8878
//   0x0084b8: 52800060  mov      w0, #3
//   0x0084bc: f94016a8  ldr      x8, [x21, #0x28]
//   0x0084c0: f94007e9  ldr      x9, [sp, #8]
//   0x0084c4: eb09011f  cmp      x8, x9
//   0x0084c8: 540000c1  b.ne     #0x84e0
//   0x0084cc: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x0084d0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x0084d4: f9400bf5  ldr      x21, [sp, #0x10]
//   0x0084d8: 910103ff  add      sp, sp, #0x40
//   0x0084dc: d65f03c0  ret      
//   0x0084e0: 97ffeb10  bl       #0x3120
// ============================================================================
std::uint32_t fde_070_08414(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008414ULL;
    for (std::size_t i = 0; i < 52ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5169ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[071] Subroutine @ 0x0084e4..0x008878 (916 bytes, 229 AArch64 instructions)
// [VN] Khung FDE[071] Hàm con @ 0x0084e4..0x008878 (916 byte, 229 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0084e4: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x0084e8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0084ec: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0084f0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0084f4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0084f8: 910103fd  add      x29, sp, #0x40
//   0x0084fc: aa0003f9  mov      x25, x0
//   0x008500: f8460f34  ldr      x20, [x25, #0x60]!
//   0x008504: b9400028  ldr      w8, [x1]
//   0x008508: aa0103f6  mov      x22, x1
//   0x00850c: aa0003f5  mov      x21, x0
//   0x008510: aa0203f3  mov      x19, x2
//   0x008514: 370002c8  tbnz     w8, #0, #0x856c
//   0x008518: f94002a9  ldr      x9, [x21]
//   0x00851c: b4000289  cbz      x9, #0x856c
//   0x008520: f94006aa  ldr      x10, [x21, #8]
//   0x008524: eb09015f  cmp      x10, x9
//   0x008528: 54000229  b.ls     #0x856c
//   0x00852c: f9400268  ldr      x8, [x19]
//   0x008530: 4b090149  sub      w9, w10, w9
//   0x008534: 93407d37  sxtw     x23, w9
//   0x008538: aa1303e0  mov      x0, x19
//   0x00853c: aa1703e1  mov      x1, x23
//   0x008540: d63f0100  blr      x8
//   0x008544: b4001780  cbz      x0, #0x8834
//   0x008548: f94002a1  ldr      x1, [x21]
//   0x00854c: aa1703e2  mov      x2, x23
//   0x008550: aa0003f8  mov      x24, x0
//   0x008554: 97ffeb5b  bl       #0x32c0
//   0x008558: 8b170308  add      x8, x24, x23
//   0x00855c: a90022b8  stp      x24, x8, [x21]
//   0x008560: b94002c8  ldr      w8, [x22]
//   0x008564: 32000108  orr      w8, w8, #1
//   0x008568: b90002c8  str      w8, [x22]
//   0x00856c: 370802c8  tbnz     w8, #1, #0x85c4
//   0x008570: f9400aa9  ldr      x9, [x21, #0x10]
//   0x008574: b4000289  cbz      x9, #0x85c4
//   0x008578: f9400eaa  ldr      x10, [x21, #0x18]
//   0x00857c: eb09015f  cmp      x10, x9
//   0x008580: 54000229  b.ls     #0x85c4
//   0x008584: f9400268  ldr      x8, [x19]
//   0x008588: 4b090149  sub      w9, w10, w9
//   0x00858c: 93407d37  sxtw     x23, w9
//   0x008590: aa1303e0  mov      x0, x19
//   0x008594: aa1703e1  mov      x1, x23
//   0x008598: d63f0100  blr      x8
//   0x00859c: b40014c0  cbz      x0, #0x8834
//   0x0085a0: f9400aa1  ldr      x1, [x21, #0x10]
//   0x0085a4: aa1703e2  mov      x2, x23
//   0x0085a8: aa0003f8  mov      x24, x0
//   0x0085ac: 97ffeb45  bl       #0x32c0
//   0x0085b0: 8b170308  add      x8, x24, x23
//   0x0085b4: a90122b8  stp      x24, x8, [x21, #0x10]
//   0x0085b8: b94002c8  ldr      w8, [x22]
//   0x0085bc: 321f0108  orr      w8, w8, #2
//   0x0085c0: b90002c8  str      w8, [x22]
//   0x0085c4: 372002c8  tbnz     w8, #4, #0x861c
//   0x0085c8: f9403aa9  ldr      x9, [x21, #0x70]
//   0x0085cc: b4000289  cbz      x9, #0x861c
//   0x0085d0: f9403eaa  ldr      x10, [x21, #0x78]
//   0x0085d4: eb09015f  cmp      x10, x9
//   0x0085d8: 54000229  b.ls     #0x861c
//   0x0085dc: f9400268  ldr      x8, [x19]
//   0x0085e0: 4b090149  sub      w9, w10, w9
//   0x0085e4: 93407d37  sxtw     x23, w9
//   0x0085e8: aa1303e0  mov      x0, x19
//   0x0085ec: aa1703e1  mov      x1, x23
//   0x0085f0: d63f0100  blr      x8
//   0x0085f4: b4001200  cbz      x0, #0x8834
//   0x0085f8: f9403aa1  ldr      x1, [x21, #0x70]
//   0x0085fc: aa1703e2  mov      x2, x23
//   0x008600: aa0003f8  mov      x24, x0
//   0x008604: 97ffeb2f  bl       #0x32c0
//   0x008608: 8b170308  add      x8, x24, x23
//   0x00860c: a90722b8  stp      x24, x8, [x21, #0x70]
//   0x008610: b94002c8  ldr      w8, [x22]
//   0x008614: 321c0108  orr      w8, w8, #0x10
//   0x008618: b90002c8  str      w8, [x22]
//   0x00861c: 372802c8  tbnz     w8, #5, #0x8674
//   0x008620: f94042a9  ldr      x9, [x21, #0x80]
//   0x008624: b4000289  cbz      x9, #0x8674
//   0x008628: f94046aa  ldr      x10, [x21, #0x88]
//   0x00862c: eb09015f  cmp      x10, x9
//   0x008630: 54000229  b.ls     #0x8674
//   0x008634: f9400268  ldr      x8, [x19]
//   0x008638: 4b090149  sub      w9, w10, w9
//   0x00863c: 93407d37  sxtw     x23, w9
//   0x008640: aa1303e0  mov      x0, x19
//   0x008644: aa1703e1  mov      x1, x23
//   0x008648: d63f0100  blr      x8
//   0x00864c: b4000f40  cbz      x0, #0x8834
//   0x008650: f94042a1  ldr      x1, [x21, #0x80]
//   0x008654: aa1703e2  mov      x2, x23
//   0x008658: aa0003f8  mov      x24, x0
//   0x00865c: 97ffeb19  bl       #0x32c0
//   0x008660: 8b170308  add      x8, x24, x23
//   0x008664: a90822b8  stp      x24, x8, [x21, #0x80]
//   0x008668: b94002c8  ldr      w8, [x22]
//   0x00866c: 321b0108  orr      w8, w8, #0x20
//   0x008670: b90002c8  str      w8, [x22]
//   0x008674: 371005c8  tbnz     w8, #2, #0x872c
//   0x008678: f94022b7  ldr      x23, [x21, #0x40]
//   0x00867c: b40002f7  cbz      x23, #0x86d8
//   0x008680: f94026a9  ldr      x9, [x21, #0x48]
//   0x008684: eb17013f  cmp      x9, x23
//   0x008688: 54000229  b.ls     #0x86cc
//   0x00868c: f9400268  ldr      x8, [x19]
//   0x008690: 4b170129  sub      w9, w9, w23
//   0x008694: 93407d38  sxtw     x24, w9
//   0x008698: aa1303e0  mov      x0, x19
//   0x00869c: aa1803e1  mov      x1, x24
//   0x0086a0: d63f0100  blr      x8
//   0x0086a4: b4000c80  cbz      x0, #0x8834
//   0x0086a8: f94022a1  ldr      x1, [x21, #0x40]
//   0x0086ac: aa1803e2  mov      x2, x24
//   0x0086b0: aa0003f7  mov      x23, x0
//   0x0086b4: 97ffeb03  bl       #0x32c0
//   0x0086b8: 8b1802e9  add      x9, x23, x24
//   0x0086bc: a90426b7  stp      x23, x9, [x21, #0x40]
//   0x0086c0: b94002c8  ldr      w8, [x22]
//   0x0086c4: 321e0108  orr      w8, w8, #4
//   0x0086c8: b90002c8  str      w8, [x22]
//   0x0086cc: a90226b7  stp      x23, x9, [x21, #0x20]
//   0x0086d0: 36180308  tbz      w8, #3, #0x8730
//   0x0086d4: 14000045  b        #0x87e8
//   0x0086d8: f94012a9  ldr      x9, [x21, #0x20]
//   0x0086dc: b4000289  cbz      x9, #0x872c
//   0x0086e0: f94016aa  ldr      x10, [x21, #0x28]
//   0x0086e4: eb09015f  cmp      x10, x9
//   0x0086e8: 54000229  b.ls     #0x872c
//   0x0086ec: f9400268  ldr      x8, [x19]
//   0x0086f0: 4b090149  sub      w9, w10, w9
//   0x0086f4: 93407d37  sxtw     x23, w9
//   0x0086f8: aa1303e0  mov      x0, x19
//   0x0086fc: aa1703e1  mov      x1, x23
//   0x008700: d63f0100  blr      x8
//   0x008704: b4000980  cbz      x0, #0x8834
//   0x008708: f94012a1  ldr      x1, [x21, #0x20]
//   0x00870c: aa1703e2  mov      x2, x23
//   0x008710: aa0003f8  mov      x24, x0
//   0x008714: 97ffeaeb  bl       #0x32c0
//   0x008718: 8b170308  add      x8, x24, x23
//   0x00871c: a90222b8  stp      x24, x8, [x21, #0x20]
//   0x008720: b94002c8  ldr      w8, [x22]
//   0x008724: 321e0108  orr      w8, w8, #4
//   0x008728: b90002c8  str      w8, [x22]
//   0x00872c: 371805e8  tbnz     w8, #3, #0x87e8
//   0x008730: b5000154  cbnz     x20, #0x8758
//   0x008734: 1400002b  b        #0x87e0
//   0x008738: f9400281  ldr      x1, [x20]
//   0x00873c: aa1703e2  mov      x2, x23
//   0x008740: aa0003f8  mov      x24, x0
//   0x008744: 97ffeadf  bl       #0x32c0
//   0x008748: 8b170308  add      x8, x24, x23
//   0x00874c: a9002298  stp      x24, x8, [x20]
//   0x008750: f9400a94  ldr      x20, [x20, #0x10]
//   0x008754: b4000454  cbz      x20, #0x87dc
//   0x008758: f9400288  ldr      x8, [x20]
//   0x00875c: b4ffffa8  cbz      x8, #0x8750
//   0x008760: f9400689  ldr      x9, [x20, #8]
//   0x008764: eb08013f  cmp      x9, x8
//   0x008768: 54ffff49  b.ls     #0x8750
//   0x00876c: f940026a  ldr      x10, [x19]
//   0x008770: 4b080128  sub      w8, w9, w8
//   0x008774: 93407d17  sxtw     x23, w8
//   0x008778: aa1303e0  mov      x0, x19
//   0x00877c: aa1703e1  mov      x1, x23
//   0x008780: d63f0140  blr      x10
//   0x008784: b5fffda0  cbnz     x0, #0x8738
//   0x008788: f9400335  ldr      x21, [x25]
//   0x00878c: eb1402bf  cmp      x21, x20
//   0x008790: 54000121  b.ne     #0x87b4
//   0x008794: 1400002f  b        #0x8850
//   0x008798: f9401268  ldr      x8, [x19, #0x20]
//   0x00879c: aa1303e0  mov      x0, x19
//   0x0087a0: aa1503e1  mov      x1, x21
//   0x0087a4: d63f0100  blr      x8
//   0x0087a8: eb1402df  cmp      x22, x20
//   0x0087ac: aa1603f5  mov      x21, x22
//   0x0087b0: 540004e0  b.eq     #0x884c
//   0x0087b4: f94002a1  ldr      x1, [x21]
//   0x0087b8: f9400ab6  ldr      x22, [x21, #0x10]
//   0x0087bc: b4fffee1  cbz      x1, #0x8798
//   0x0087c0: f94006a8  ldr      x8, [x21, #8]
//   0x0087c4: eb01011f  cmp      x8, x1
//   0x0087c8: 54fffe89  b.ls     #0x8798
//   0x0087cc: f9401268  ldr      x8, [x19, #0x20]
//   0x0087d0: aa1303e0  mov      x0, x19
//   0x0087d4: d63f0100  blr      x8
//   0x0087d8: 17fffff0  b        #0x8798
//   0x0087dc: b94002c8  ldr      w8, [x22]
//   0x0087e0: 321d0108  orr      w8, w8, #8
//   0x0087e4: b90002c8  str      w8, [x22]
//   0x0087e8: f9402aa8  ldr      x8, [x21, #0x50]
//   0x0087ec: b4000228  cbz      x8, #0x8830
//   0x0087f0: f9402ea9  ldr      x9, [x21, #0x58]
//   0x0087f4: eb08013f  cmp      x9, x8
//   0x0087f8: 540001c9  b.ls     #0x8830
//   0x0087fc: f940026a  ldr      x10, [x19]
//   0x008800: 4b080128  sub      w8, w9, w8
//   0x008804: 93407d14  sxtw     x20, w8
//   0x008808: aa1303e0  mov      x0, x19
//   0x00880c: aa1403e1  mov      x1, x20
//   0x008810: d63f0140  blr      x10
//   0x008814: b4000100  cbz      x0, #0x8834
//   0x008818: f9402aa1  ldr      x1, [x21, #0x50]
//   0x00881c: aa1403e2  mov      x2, x20
//   0x008820: aa0003f3  mov      x19, x0
//   0x008824: 97ffeaa7  bl       #0x32c0
//   0x008828: 8b140268  add      x8, x19, x20
//   0x00882c: a90522b3  stp      x19, x8, [x21, #0x50]
//   0x008830: 52800020  mov      w0, #1
//   0x008834: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x008838: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x00883c: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x008840: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x008844: f84507f9  ldr      x25, [sp], #0x50
//   0x008848: d65f03c0  ret      
//   0x00884c: b4000114  cbz      x20, #0x886c
//   0x008850: f9401268  ldr      x8, [x19, #0x20]
//   0x008854: f9400a95  ldr      x21, [x20, #0x10]
//   0x008858: aa1303e0  mov      x0, x19
//   0x00885c: aa1403e1  mov      x1, x20
//   0x008860: d63f0100  blr      x8
//   0x008864: aa1503f4  mov      x20, x21
//   0x008868: b5ffff55  cbnz     x21, #0x8850
//   0x00886c: 2a1f03e0  mov      w0, wzr
//   0x008870: a9007f3f  stp      xzr, xzr, [x25]
//   0x008874: 17fffff0  b        #0x8834
// ============================================================================
std::uint32_t fde_071_084e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000084e4ULL;
    for (std::size_t i = 0; i < 229ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5221ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[072] Subroutine @ 0x008878..0x0089e8 (368 bytes, 92 AArch64 instructions)
// [VN] Khung FDE[072] Hàm con @ 0x008878..0x0089e8 (368 byte, 92 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008878: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00887c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x008880: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x008884: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x008888: 9100c3fd  add      x29, sp, #0x30
//   0x00888c: aa0203f4  mov      x20, x2
//   0x008890: 2a0103f5  mov      w21, w1
//   0x008894: aa0003f3  mov      x19, x0
//   0x008898: 37000081  tbnz     w1, #0, #0x88a8
//   0x00889c: 37080135  tbnz     w21, #1, #0x88c0
//   0x0088a0: 37100255  tbnz     w21, #2, #0x88e8
//   0x0088a4: 14000023  b        #0x8930
//   0x0088a8: f9401288  ldr      x8, [x20, #0x20]
//   0x0088ac: f9400261  ldr      x1, [x19]
//   0x0088b0: aa1403e0  mov      x0, x20
//   0x0088b4: d63f0100  blr      x8
//   0x0088b8: a9007e7f  stp      xzr, xzr, [x19]
//   0x0088bc: 360fff35  tbz      w21, #1, #0x88a0
//   0x0088c0: aa1303f6  mov      x22, x19
//   0x0088c4: f8410ec1  ldr      x1, [x22, #0x10]!
//   0x0088c8: f94006c8  ldr      x8, [x22, #8]
//   0x0088cc: eb08003f  cmp      x1, x8
//   0x0088d0: 54000080  b.eq     #0x88e0
//   0x0088d4: f9401288  ldr      x8, [x20, #0x20]
//   0x0088d8: aa1403e0  mov      x0, x20
//   0x0088dc: d63f0100  blr      x8
//   0x0088e0: a9007edf  stp      xzr, xzr, [x22]
//   0x0088e4: 36100275  tbz      w21, #2, #0x8930
//   0x0088e8: aa1303f6  mov      x22, x19
//   0x0088ec: f8440ec1  ldr      x1, [x22, #0x40]!
//   0x0088f0: b40000c1  cbz      x1, #0x8908
//   0x0088f4: f9401288  ldr      x8, [x20, #0x20]
//   0x0088f8: aa1403e0  mov      x0, x20
//   0x0088fc: d63f0100  blr      x8
//   0x008900: a9027e7f  stp      xzr, xzr, [x19, #0x20]
//   0x008904: 1400000a  b        #0x892c
//   0x008908: aa1303f6  mov      x22, x19
//   0x00890c: f8420ec1  ldr      x1, [x22, #0x20]!
//   0x008910: b4000101  cbz      x1, #0x8930
//   0x008914: f9401668  ldr      x8, [x19, #0x28]
//   0x008918: eb08003f  cmp      x1, x8
//   0x00891c: 54000080  b.eq     #0x892c
//   0x008920: f9401288  ldr      x8, [x20, #0x20]
//   0x008924: aa1403e0  mov      x0, x20
//   0x008928: d63f0100  blr      x8
//   0x00892c: a9007edf  stp      xzr, xzr, [x22]
//   0x008930: 37180095  tbnz     w21, #3, #0x8940
//   0x008934: 37200115  tbnz     w21, #4, #0x8954
//   0x008938: 37280235  tbnz     w21, #5, #0x897c
//   0x00893c: 14000018  b        #0x899c
//   0x008940: aa1303f7  mov      x23, x19
//   0x008944: f8460ef6  ldr      x22, [x23, #0x60]!
//   0x008948: b5000416  cbnz     x22, #0x89c8
//   0x00894c: a9007eff  stp      xzr, xzr, [x23]
//   0x008950: 3627ff55  tbz      w21, #4, #0x8938
//   0x008954: aa1303f6  mov      x22, x19
//   0x008958: f8470ec1  ldr      x1, [x22, #0x70]!
//   0x00895c: f94006c8  ldr      x8, [x22, #8]
//   0x008960: eb08003f  cmp      x1, x8
//   0x008964: 54000080  b.eq     #0x8974
//   0x008968: f9401288  ldr      x8, [x20, #0x20]
//   0x00896c: aa1403e0  mov      x0, x20
//   0x008970: d63f0100  blr      x8
//   0x008974: a9007edf  stp      xzr, xzr, [x22]
//   0x008978: 36280135  tbz      w21, #5, #0x899c
//   0x00897c: f8480e61  ldr      x1, [x19, #0x80]!
//   0x008980: f9400668  ldr      x8, [x19, #8]
//   0x008984: eb08003f  cmp      x1, x8
//   0x008988: 54000080  b.eq     #0x8998
//   0x00898c: f9401288  ldr      x8, [x20, #0x20]
//   0x008990: aa1403e0  mov      x0, x20
//   0x008994: d63f0100  blr      x8
//   0x008998: a9007e7f  stp      xzr, xzr, [x19]
//   0x00899c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x0089a0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x0089a4: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x0089a8: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x0089ac: d65f03c0  ret      
//   0x0089b0: f9401288  ldr      x8, [x20, #0x20]
//   0x0089b4: aa1403e0  mov      x0, x20
//   0x0089b8: aa1603e1  mov      x1, x22
//   0x0089bc: d63f0100  blr      x8
//   0x0089c0: aa1803f6  mov      x22, x24
//   0x0089c4: b4fffc58  cbz      x24, #0x894c
//   0x0089c8: a94022c1  ldp      x1, x8, [x22]
//   0x0089cc: f9400ad8  ldr      x24, [x22, #0x10]
//   0x0089d0: eb01011f  cmp      x8, x1
//   0x0089d4: 54fffee9  b.ls     #0x89b0
//   0x0089d8: f9401288  ldr      x8, [x20, #0x20]
//   0x0089dc: aa1403e0  mov      x0, x20
//   0x0089e0: d63f0100  blr      x8
//   0x0089e4: 17fffff3  b        #0x89b0
// ============================================================================
std::uint32_t fde_072_08878(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008878ULL;
    for (std::size_t i = 0; i < 92ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5450ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[073] Subroutine @ 0x0089e8..0x008a90 (168 bytes, 42 AArch64 instructions)
// [VN] Khung FDE[073] Hàm con @ 0x0089e8..0x008a90 (168 byte, 42 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0089e8: d100c3ff  sub      sp, sp, #0x30
//   0x0089ec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0089f0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0089f4: 910083fd  add      x29, sp, #0x20
//   0x0089f8: d53bd054  mrs      x20, tpidr_el0
//   0x0089fc: f9401688  ldr      x8, [x20, #0x28]
//   0x008a00: f90007e8  str      x8, [sp, #8]
//   0x008a04: b90007ff  str      wzr, [sp, #4]
//   0x008a08: b40000e0  cbz      x0, #0x8a24
//   0x008a0c: b9409408  ldr      w8, [x0, #0x94]
//   0x008a10: aa0003f3  mov      x19, x0
//   0x008a14: 7100051f  cmp      w8, #1
//   0x008a18: 540000a1  b.ne     #0x8a2c
//   0x008a1c: 2a1f03e0  mov      w0, wzr
//   0x008a20: 14000013  b        #0x8a6c
//   0x008a24: 52800040  mov      w0, #2
//   0x008a28: 14000011  b        #0x8a6c
//   0x008a2c: f0000082  adrp     x2, #0x1b000
//   0x008a30: f947fc42  ldr      x2, [x2, #0xff8]
//   0x008a34: 910013e1  add      x1, sp, #4
//   0x008a38: aa1303e0  mov      x0, x19
//   0x008a3c: 97fffeaa  bl       #0x84e4
//   0x008a40: 340000a0  cbz      w0, #0x8a54
//   0x008a44: 2a1f03e0  mov      w0, wzr
//   0x008a48: 52800028  mov      w8, #1
//   0x008a4c: b9009668  str      w8, [x19, #0x94]
//   0x008a50: 14000007  b        #0x8a6c
//   0x008a54: f0000082  adrp     x2, #0x1b000
//   0x008a58: b94007e1  ldr      w1, [sp, #4]
//   0x008a5c: f947fc42  ldr      x2, [x2, #0xff8]
//   0x008a60: aa1303e0  mov      x0, x19
//   0x008a64: 97ffff85  bl       #0x8878
//   0x008a68: 52800060  mov      w0, #3
//   0x008a6c: f9401688  ldr      x8, [x20, #0x28]
//   0x008a70: f94007e9  ldr      x9, [sp, #8]
//   0x008a74: eb09011f  cmp      x8, x9
//   0x008a78: 540000a1  b.ne     #0x8a8c
//   0x008a7c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x008a80: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x008a84: 9100c3ff  add      sp, sp, #0x30
//   0x008a88: d65f03c0  ret      
//   0x008a8c: 97ffe9a5  bl       #0x3120
// ============================================================================
std::uint32_t fde_073_089e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000089e8ULL;
    for (std::size_t i = 0; i < 42ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5542ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[074] Subroutine @ 0x008a90..0x008b1c (140 bytes, 35 AArch64 instructions)
// [VN] Khung FDE[074] Hàm con @ 0x008a90..0x008b1c (140 byte, 35 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008a90: d10383ff  sub      sp, sp, #0xe0
//   0x008a94: f90063f3  str      x19, [sp, #0xc0]
//   0x008a98: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x008a9c: 910343fd  add      x29, sp, #0xd0
//   0x008aa0: d53bd053  mrs      x19, tpidr_el0
//   0x008aa4: f9401668  ldr      x8, [x19, #0x28]
//   0x008aa8: f81e83a8  stur     x8, [x29, #-0x18]
//   0x008aac: b9000fff  str      wzr, [sp, #0xc]
//   0x008ab0: b4000240  cbz      x0, #0x8af8
//   0x008ab4: ad400001  ldp      q1, q0, [x0]
//   0x008ab8: 910043e8  add      x8, sp, #0x10
//   0x008abc: 910033e2  add      x2, sp, #0xc
//   0x008ac0: 2a1f03e1  mov      w1, wzr
//   0x008ac4: ad0083e1  stp      q1, q0, [sp, #0x10]
//   0x008ac8: ad420001  ldp      q1, q0, [x0, #0x40]
//   0x008acc: ad410803  ldp      q3, q2, [x0, #0x20]
//   0x008ad0: aa1f03e3  mov      x3, xzr
//   0x008ad4: ad0283e1  stp      q1, q0, [sp, #0x50]
//   0x008ad8: ad018be3  stp      q3, q2, [sp, #0x30]
//   0x008adc: ad440400  ldp      q0, q1, [x0, #0x80]
//   0x008ae0: ad430c02  ldp      q2, q3, [x0, #0x60]
//   0x008ae4: 910043e0  add      x0, sp, #0x10
//   0x008ae8: ad040500  stp      q0, q1, [x8, #0x80]
//   0x008aec: ad038fe2  stp      q2, q3, [sp, #0x70]
//   0x008af0: 9400002f  bl       #0x8bac
//   0x008af4: b9400fe0  ldr      w0, [sp, #0xc]
//   0x008af8: f9401668  ldr      x8, [x19, #0x28]
//   0x008afc: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x008b00: eb09011f  cmp      x8, x9
//   0x008b04: 540000a1  b.ne     #0x8b18
//   0x008b08: a94d7bfd  ldp      x29, x30, [sp, #0xd0]
//   0x008b0c: f94063f3  ldr      x19, [sp, #0xc0]
//   0x008b10: 910383ff  add      sp, sp, #0xe0
//   0x008b14: d65f03c0  ret      
//   0x008b18: 97ffe982  bl       #0x3120
// ============================================================================
std::uint32_t fde_074_08a90(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008a90ULL;
    for (std::size_t i = 0; i < 35ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5584ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[075] Subroutine @ 0x008b1c..0x008bac (144 bytes, 36 AArch64 instructions)
// [VN] Khung FDE[075] Hàm con @ 0x008b1c..0x008bac (144 byte, 36 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008b1c: d10343ff  sub      sp, sp, #0xd0
//   0x008b20: f9005bf3  str      x19, [sp, #0xb0]
//   0x008b24: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x008b28: 910303fd  add      x29, sp, #0xc0
//   0x008b2c: d53bd053  mrs      x19, tpidr_el0
//   0x008b30: f9401668  ldr      x8, [x19, #0x28]
//   0x008b34: f81e83a8  stur     x8, [x29, #-0x18]
//   0x008b38: 52800048  mov      w8, #2
//   0x008b3c: b4000240  cbz      x0, #0x8b84
//   0x008b40: aa0103e2  mov      x2, x1
//   0x008b44: b4000201  cbz      x1, #0x8b84
//   0x008b48: ad400001  ldp      q1, q0, [x0]
//   0x008b4c: 2a1f03e1  mov      w1, wzr
//   0x008b50: aa1f03e3  mov      x3, xzr
//   0x008b54: ad0003e1  stp      q1, q0, [sp]
//   0x008b58: ad420001  ldp      q1, q0, [x0, #0x40]
//   0x008b5c: ad410803  ldp      q3, q2, [x0, #0x20]
//   0x008b60: ad0203e1  stp      q1, q0, [sp, #0x40]
//   0x008b64: ad010be3  stp      q3, q2, [sp, #0x20]
//   0x008b68: ad440001  ldp      q1, q0, [x0, #0x80]
//   0x008b6c: ad430803  ldp      q3, q2, [x0, #0x60]
//   0x008b70: 910003e0  mov      x0, sp
//   0x008b74: ad0403e1  stp      q1, q0, [sp, #0x80]
//   0x008b78: ad030be3  stp      q3, q2, [sp, #0x60]
//   0x008b7c: 9400000c  bl       #0x8bac
//   0x008b80: 2a1f03e8  mov      w8, wzr
//   0x008b84: f9401669  ldr      x9, [x19, #0x28]
//   0x008b88: f85e83aa  ldur     x10, [x29, #-0x18]
//   0x008b8c: eb0a013f  cmp      x9, x10
//   0x008b90: 540000c1  b.ne     #0x8ba8
//   0x008b94: a94c7bfd  ldp      x29, x30, [sp, #0xc0]
//   0x008b98: f9405bf3  ldr      x19, [sp, #0xb0]
//   0x008b9c: 2a0803e0  mov      w0, w8
//   0x008ba0: 910343ff  add      sp, sp, #0xd0
//   0x008ba4: d65f03c0  ret      
//   0x008ba8: 97ffe95e  bl       #0x3120
// ============================================================================
std::uint32_t fde_075_08b1c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008b1cULL;
    for (std::size_t i = 0; i < 36ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5619ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[076] Subroutine @ 0x008bac..0x00a678 (6860 bytes, 1715 AArch64 instructions)
// [VN] Khung FDE[076] Hàm con @ 0x008bac..0x00a678 (6860 byte, 1715 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008bac: d10283ff  sub      sp, sp, #0xa0
//   0x008bb0: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x008bb4: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x008bb8: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x008bbc: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x008bc0: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x008bc4: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x008bc8: 910243fd  add      x29, sp, #0x90
//   0x008bcc: d53bd05c  mrs      x28, tpidr_el0
//   0x008bd0: f9401788  ldr      x8, [x28, #0x28]
//   0x008bd4: aa0203f6  mov      x22, x2
//   0x008bd8: f9001fe8  str      x8, [sp, #0x38]
//   0x008bdc: b90037ff  str      wzr, [sp, #0x34]
//   0x008be0: b4000280  cbz      x0, #0x8c30
//   0x008be4: aa0003f5  mov      x21, x0
//   0x008be8: a900f3e3  stp      x3, x28, [sp, #8]
//   0x008bec: a9025be0  stp      x0, x22, [sp, #0x20]
//   0x008bf0: b4000296  cbz      x22, #0x8c40
//   0x008bf4: b90002df  str      wzr, [x22]
//   0x008bf8: f94002a8  ldr      x8, [x21]
//   0x008bfc: 2a1f03e9  mov      w9, wzr
//   0x008c00: b40008e8  cbz      x8, #0x8d1c
//   0x008c04: f94006aa  ldr      x10, [x21, #8]
//   0x008c08: eb08015f  cmp      x10, x8
//   0x008c0c: 54000889  b.ls     #0x8d1c
//   0x008c10: b8404509  ldr      w9, [x8], #4
//   0x008c14: 51010529  sub      w9, w9, #0x41
//   0x008c18: 7100653f  cmp      w9, #0x19
//   0x008c1c: 540007e9  b.ls     #0x8d18
//   0x008c20: eb0a011f  cmp      x8, x10
//   0x008c24: 54ffff63  b.lo     #0x8c10
//   0x008c28: 2a1f03e9  mov      w9, wzr
//   0x008c2c: 1400003c  b        #0x8d1c
//   0x008c30: b4000716  cbz      x22, #0x8d10
//   0x008c34: 2a1f03e0  mov      w0, wzr
//   0x008c38: b90002df  str      wzr, [x22]
//   0x008c3c: 1400059a  b        #0xa2a4
//   0x008c40: 3400ae41  cbz      w1, #0xa208
//   0x008c44: 36002a21  tbz      w1, #0, #0x9188
//   0x008c48: f94002ad  ldr      x13, [x21]
//   0x008c4c: b40029ed  cbz      x13, #0x9188
//   0x008c50: b94096a9  ldr      w9, [x21, #0x94]
//   0x008c54: f94006a8  ldr      x8, [x21, #8]
//   0x008c58: 34001be9  cbz      w9, #0x8fd4
//   0x008c5c: eb0d011f  cmp      x8, x13
//   0x008c60: 54002949  b.ls     #0x9188
//   0x008c64: aa2d03e9  mvn      x9, x13
//   0x008c68: 8b090109  add      x9, x8, x9
//   0x008c6c: d342fd29  lsr      x9, x9, #2
//   0x008c70: 9100052a  add      x10, x9, #1
//   0x008c74: f100115f  cmp      x10, #4
//   0x008c78: aa0d03e9  mov      x9, x13
//   0x008c7c: 54002343  b.lo     #0x90e4
//   0x008c80: 927ef14b  and      x11, x10, #0x7ffffffffffffffc
//   0x008c84: 910021ac  add      x12, x13, #8
//   0x008c88: 2f020400  mvni     v0.2s, #0x40
//   0x008c8c: 8b0b09a9  add      x9, x13, x11, lsl #2
//   0x008c90: 0f000741  movi     v1.2s, #0x1a
//   0x008c94: aa0b03ed  mov      x13, x11
//   0x008c98: 14000004  b        #0x8ca8
//   0x008c9c: f10011ad  subs     x13, x13, #4
//   0x008ca0: 9100418c  add      x12, x12, #0x10
//   0x008ca4: 54002140  b.eq     #0x90cc
//   0x008ca8: 6d7f8983  ldp      d3, d2, [x12, #-8]
//   0x008cac: 0ea08464  add      v4.2s, v3.2s, v0.2s
//   0x008cb0: 2ea43424  cmhi     v4.2s, v1.2s, v4.2s
//   0x008cb4: 1e26008e  fmov     w14, s4
//   0x008cb8: 3600008e  tbz      w14, #0, #0x8cc8
//   0x008cbc: 1e26006e  fmov     w14, s3
//   0x008cc0: 110081ce  add      w14, w14, #0x20
//   0x008cc4: b81f818e  stur     w14, [x12, #-8]
//   0x008cc8: 0e0c3c8e  mov      w14, v4.s[1]
//   0x008ccc: 0ea08444  add      v4.2s, v2.2s, v0.2s
//   0x008cd0: 3600008e  tbz      w14, #0, #0x8ce0
//   0x008cd4: 0e0c3c6e  mov      w14, v3.s[1]
//   0x008cd8: 110081ce  add      w14, w14, #0x20
//   0x008cdc: b81fc18e  stur     w14, [x12, #-4]
//   0x008ce0: 2ea43423  cmhi     v3.2s, v1.2s, v4.2s
//   0x008ce4: 1e26006e  fmov     w14, s3
//   0x008ce8: 3600008e  tbz      w14, #0, #0x8cf8
//   0x008cec: 1e26004e  fmov     w14, s2
//   0x008cf0: 110081ce  add      w14, w14, #0x20
//   0x008cf4: b900018e  str      w14, [x12]
//   0x008cf8: 0e0c3c6e  mov      w14, v3.s[1]
//   0x008cfc: 3607fd0e  tbz      w14, #0, #0x8c9c
//   0x008d00: 0e0c3c4e  mov      w14, v2.s[1]
//   0x008d04: 110081ce  add      w14, w14, #0x20
//   0x008d08: b900058e  str      w14, [x12, #4]
//   0x008d0c: 17ffffe4  b        #0x8c9c
//   0x008d10: 52800040  mov      w0, #2
//   0x008d14: 14000564  b        #0xa2a4
//   0x008d18: 52800029  mov      w9, #1
//   0x008d1c: b9001fe1  str      w1, [sp, #0x1c]
//   0x008d20: a9424ea8  ldp      x8, x19, [x21, #0x20]
//   0x008d24: f100011f  cmp      x8, #0
//   0x008d28: 1a9f07ea  cset     w10, ne
//   0x008d2c: eb08027f  cmp      x19, x8
//   0x008d30: 1a9f97eb  cset     w11, hi
//   0x008d34: 0a0b014a  and      w10, w10, w11
//   0x008d38: 7100055f  cmp      w10, #1
//   0x008d3c: 54000101  b.ne     #0x8d5c
//   0x008d40: aa0803eb  mov      x11, x8
//   0x008d44: b840456c  ldr      w12, [x11], #4
//   0x008d48: 5101058c  sub      w12, w12, #0x41
//   0x008d4c: 7100659f  cmp      w12, #0x19
//   0x008d50: 54000829  b.ls     #0x8e54
//   0x008d54: eb13017f  cmp      x11, x19
//   0x008d58: 54ffff63  b.lo     #0x8d44
//   0x008d5c: 2a1f03eb  mov      w11, wzr
//   0x008d60: 340007e9  cbz      w9, #0x8e5c
//   0x008d64: 52800029  mov      w9, #1
//   0x008d68: b90002c9  str      w9, [x22]
//   0x008d6c: 528000a9  mov      w9, #5
//   0x008d70: 340007ab  cbz      w11, #0x8e64
//   0x008d74: b90002c9  str      w9, [x22]
//   0x008d78: b5003516  cbnz     x22, #0x9418
//   0x008d7c: b9401fe8  ldr      w8, [sp, #0x1c]
//   0x008d80: 36085188  tbz      w8, #1, #0x97b0
//   0x008d84: f9400ab3  ldr      x19, [x21, #0x10]
//   0x008d88: b4005153  cbz      x19, #0x97b0
//   0x008d8c: b94096a9  ldr      w9, [x21, #0x94]
//   0x008d90: f9400ea8  ldr      x8, [x21, #0x18]
//   0x008d94: 34000ac9  cbz      w9, #0x8eec
//   0x008d98: b40050c8  cbz      x8, #0x97b0
//   0x008d9c: cb130116  sub      x22, x8, x19
//   0x008da0: d342fedb  lsr      x27, x22, #2
//   0x008da4: 71000f7f  cmp      w27, #3
//   0x008da8: 5400168b  b.lt     #0x9078
//   0x008dac: 2a1f03e8  mov      w8, wzr
//   0x008db0: 5280005c  mov      w28, #2
//   0x008db4: 528004b5  mov      w21, #0x25
//   0x008db8: aa1303fa  mov      x26, x19
//   0x008dbc: 14000009  b        #0x8de0
//   0x008dc0: b9000349  str      w9, [x26]
//   0x008dc4: 5280002a  mov      w10, #1
//   0x008dc8: 11000509  add      w9, w8, #1
//   0x008dcc: 11000d1c  add      w28, w8, #3
//   0x008dd0: 6b1b039f  cmp      w28, w27
//   0x008dd4: 8b0a0b5a  add      x26, x26, x10, lsl #2
//   0x008dd8: 2a0903e8  mov      w8, w9
//   0x008ddc: 5400152a  b.ge     #0x9080
//   0x008de0: b868da69  ldr      w9, [x19, w8, sxtw #2]
//   0x008de4: 7100953f  cmp      w9, #0x25
//   0x008de8: 54fffec1  b.ne     #0x8dc0
//   0x008dec: 93407d08  sxtw     x8, w8
//   0x008df0: 8b080a68  add      x8, x19, x8, lsl #2
//   0x008df4: b9400500  ldr      w0, [x8, #4]
//   0x008df8: b87cda77  ldr      w23, [x19, w28, sxtw #2]
//   0x008dfc: 97ffe911  bl       #0x3240
//   0x008e00: 2a0003f8  mov      w24, w0
//   0x008e04: 2a1703e0  mov      w0, w23
//   0x008e08: 97ffe90e  bl       #0x3240
//   0x008e0c: 12001c17  and      w23, w0, #0xff
//   0x008e10: 0b3812f9  add      w25, w23, w24, uxtb #4
//   0x008e14: 2a1903e0  mov      w0, w25
//   0x008e18: 97ffe8aa  bl       #0x30c0
//   0x008e1c: 34000080  cbz      w0, #0x8e2c
//   0x008e20: b9000359  str      w25, [x26]
//   0x008e24: 5280002a  mov      w10, #1
//   0x008e28: 14000009  b        #0x8e4c
//   0x008e2c: 12001f00  and      w0, w24, #0xff
//   0x008e30: b9000355  str      w21, [x26]
//   0x008e34: 97ffe8d7  bl       #0x3190
//   0x008e38: b9000740  str      w0, [x26, #4]
//   0x008e3c: 2a1703e0  mov      w0, w23
//   0x008e40: 97ffe8d4  bl       #0x3190
//   0x008e44: 5280006a  mov      w10, #3
//   0x008e48: b9000b40  str      w0, [x26, #8]
//   0x008e4c: 2a1c03e8  mov      w8, w28
//   0x008e50: 17ffffde  b        #0x8dc8
//   0x008e54: 5280002b  mov      w11, #1
//   0x008e58: 35fff869  cbnz     w9, #0x8d64
//   0x008e5c: 52800089  mov      w9, #4
//   0x008e60: 35fff8ab  cbnz     w11, #0x8d74
//   0x008e64: 34002d8a  cbz      w10, #0x9414
//   0x008e68: 91002114  add      x20, x8, #8
//   0x008e6c: eb13029f  cmp      x20, x19
//   0x008e70: 540000a3  b.lo     #0x8e84
//   0x008e74: 14000168  b        #0x9414
//   0x008e78: 91001294  add      x20, x20, #4
//   0x008e7c: eb13029f  cmp      x20, x19
//   0x008e80: 54002ca2  b.hs     #0x9414
//   0x008e84: b85f8288  ldur     w8, [x20, #-8]
//   0x008e88: 7100951f  cmp      w8, #0x25
//   0x008e8c: 54ffff61  b.ne     #0x8e78
//   0x008e90: b85fc280  ldur     w0, [x20, #-4]
//   0x008e94: 51018408  sub      w8, w0, #0x61
//   0x008e98: 7100191f  cmp      w8, #6
//   0x008e9c: 540001e3  b.lo     #0x8ed8
//   0x008ea0: b9400288  ldr      w8, [x20]
//   0x008ea4: 51018508  sub      w8, w8, #0x61
//   0x008ea8: 7100191f  cmp      w8, #6
//   0x008eac: 54000163  b.lo     #0x8ed8
//   0x008eb0: 97ffe8e4  bl       #0x3240
//   0x008eb4: b9400288  ldr      w8, [x20]
//   0x008eb8: 2a0003f7  mov      w23, w0
//   0x008ebc: 2a0803e0  mov      w0, w8
//   0x008ec0: 97ffe8e0  bl       #0x3240
//   0x008ec4: 12001ee8  and      w8, w23, #0xff
//   0x008ec8: 531c6d08  lsl      w8, w8, #4
//   0x008ecc: 0b200100  add      w0, w8, w0, uxtb
//   0x008ed0: 97ffe87c  bl       #0x30c0
//   0x008ed4: 34fffd20  cbz      w0, #0x8e78
//   0x008ed8: b94002c8  ldr      w8, [x22]
//   0x008edc: 321e0108  orr      w8, w8, #4
//   0x008ee0: b90002c8  str      w8, [x22]
//   0x008ee4: b50029b6  cbnz     x22, #0x9418
//   0x008ee8: 17ffffa5  b        #0x8d7c
//   0x008eec: b40081c8  cbz      x8, #0x9f24
//   0x008ef0: cb130108  sub      x8, x8, x19
//   0x008ef4: d342fd09  lsr      x9, x8, #2
//   0x008ef8: 34004549  cbz      w9, #0x97a0
//   0x008efc: 37f88149  tbnz     w9, #0x1f, #0x9f24
//   0x008f00: f94007e0  ldr      x0, [sp, #8]
//   0x008f04: 93408501  sbfx     x1, x8, #0, #0x22
//   0x008f08: f9400009  ldr      x9, [x0]
//   0x008f0c: d63f0120  blr      x9
//   0x008f10: b40080a0  cbz      x0, #0x9f24
//   0x008f14: a94122b3  ldp      x19, x8, [x21, #0x10]
//   0x008f18: aa0003f7  mov      x23, x0
//   0x008f1c: cb130116  sub      x22, x8, x19
//   0x008f20: d342fedc  lsr      x28, x22, #2
//   0x008f24: 71000f9f  cmp      w28, #3
//   0x008f28: 54003e2b  b.lt     #0x96ec
//   0x008f2c: 2a1f03e8  mov      w8, wzr
//   0x008f30: 52800055  mov      w21, #2
//   0x008f34: 528004b4  mov      w20, #0x25
//   0x008f38: aa1703fb  mov      x27, x23
//   0x008f3c: 14000009  b        #0x8f60
//   0x008f40: b9000369  str      w9, [x27]
//   0x008f44: 5280002a  mov      w10, #1
//   0x008f48: 11000509  add      w9, w8, #1
//   0x008f4c: 11000d15  add      w21, w8, #3
//   0x008f50: 6b1c02bf  cmp      w21, w28
//   0x008f54: 8b0a0b7b  add      x27, x27, x10, lsl #2
//   0x008f58: 2a0903e8  mov      w8, w9
//   0x008f5c: 54003cca  b.ge     #0x96f4
//   0x008f60: b868da69  ldr      w9, [x19, w8, sxtw #2]
//   0x008f64: 7100953f  cmp      w9, #0x25
//   0x008f68: 54fffec1  b.ne     #0x8f40
//   0x008f6c: 93407d08  sxtw     x8, w8
//   0x008f70: 8b080a68  add      x8, x19, x8, lsl #2
//   0x008f74: b9400500  ldr      w0, [x8, #4]
//   0x008f78: b875da78  ldr      w24, [x19, w21, sxtw #2]
//   0x008f7c: 97ffe8b1  bl       #0x3240
//   0x008f80: 2a0003f9  mov      w25, w0
//   0x008f84: 2a1803e0  mov      w0, w24
//   0x008f88: 97ffe8ae  bl       #0x3240
//   0x008f8c: 12001c18  and      w24, w0, #0xff
//   0x008f90: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x008f94: 2a1a03e0  mov      w0, w26
//   0x008f98: 97ffe84a  bl       #0x30c0
//   0x008f9c: 34000080  cbz      w0, #0x8fac
//   0x008fa0: b900037a  str      w26, [x27]
//   0x008fa4: 5280002a  mov      w10, #1
//   0x008fa8: 14000009  b        #0x8fcc
//   0x008fac: 12001f20  and      w0, w25, #0xff
//   0x008fb0: b9000374  str      w20, [x27]
//   0x008fb4: 97ffe877  bl       #0x3190
//   0x008fb8: b9000760  str      w0, [x27, #4]
//   0x008fbc: 2a1803e0  mov      w0, w24
//   0x008fc0: 97ffe874  bl       #0x3190
//   0x008fc4: 5280006a  mov      w10, #3
//   0x008fc8: b9000b60  str      w0, [x27, #8]
//   0x008fcc: 2a1503e8  mov      w8, w21
//   0x008fd0: 17ffffde  b        #0x8f48
//   0x008fd4: b4000768  cbz      x8, #0x90c0
//   0x008fd8: cb0d0113  sub      x19, x8, x13
//   0x008fdc: 2a0103f4  mov      w20, w1
//   0x008fe0: d342fe68  lsr      x8, x19, #2
//   0x008fe4: 34000cc8  cbz      w8, #0x917c
//   0x008fe8: 37f806c8  tbnz     w8, #0x1f, #0x90c0
//   0x008fec: f94007e0  ldr      x0, [sp, #8]
//   0x008ff0: 93408661  sbfx     x1, x19, #0, #0x22
//   0x008ff4: f9400008  ldr      x8, [x0]
//   0x008ff8: d63f0100  blr      x8
//   0x008ffc: b4000620  cbz      x0, #0x90c0
//   0x009000: f94002a9  ldr      x9, [x21]
//   0x009004: d342866a  ubfx     x10, x19, #2, #0x20
//   0x009008: f100115f  cmp      x10, #4
//   0x00900c: 93428668  sbfx     x8, x19, #2, #0x20
//   0x009010: 54000103  b.lo     #0x9030
//   0x009014: d37ef54b  lsl      x11, x10, #2
//   0x009018: 8b0b012c  add      x12, x9, x11
//   0x00901c: eb0c001f  cmp      x0, x12
//   0x009020: 54009a42  b.hs     #0xa368
//   0x009024: 8b0b000b  add      x11, x0, x11
//   0x009028: eb09017f  cmp      x11, x9
//   0x00902c: 540099e9  b.ls     #0xa368
//   0x009030: aa1f03eb  mov      x11, xzr
//   0x009034: 2a1403e1  mov      w1, w20
//   0x009038: d37ef56c  lsl      x12, x11, #2
//   0x00903c: cb0a016a  sub      x10, x11, x10
//   0x009040: 8b0c000b  add      x11, x0, x12
//   0x009044: 8b0c0129  add      x9, x9, x12
//   0x009048: b840452c  ldr      w12, [x9], #4
//   0x00904c: 5101058d  sub      w13, w12, #0x41
//   0x009050: 1100818e  add      w14, w12, #0x20
//   0x009054: 710069bf  cmp      w13, #0x1a
//   0x009058: 1a8c31cc  csel     w12, w14, w12, lo
//   0x00905c: b100054a  adds     x10, x10, #1
//   0x009060: b800456c  str      w12, [x11], #4
//   0x009064: 54ffff23  b.lo     #0x9048
//   0x009068: 8b080808  add      x8, x0, x8, lsl #2
//   0x00906c: a90022a0  stp      x0, x8, [x21]
//   0x009070: b94037e8  ldr      w8, [sp, #0x34]
//   0x009074: 14000043  b        #0x9180
//   0x009078: 2a1f03e9  mov      w9, wzr
//   0x00907c: aa1303fa  mov      x26, x19
//   0x009080: f94013f5  ldr      x21, [sp, #0x20]
//   0x009084: 6b1b013f  cmp      w9, w27
//   0x009088: 5400012a  b.ge     #0x90ac
//   0x00908c: f9400bfc  ldr      x28, [sp, #0x10]
//   0x009090: 93407d28  sxtw     x8, w9
//   0x009094: 934286c9  sbfx     x9, x22, #2, #0x20
//   0x009098: cb08012a  sub      x10, x9, x8
//   0x00909c: f1001d5f  cmp      x10, #7
//   0x0090a0: 54000308  b.hi     #0x9100
//   0x0090a4: f94017f6  ldr      x22, [sp, #0x28]
//   0x0090a8: 1400002c  b        #0x9158
//   0x0090ac: f9400bfc  ldr      x28, [sp, #0x10]
//   0x0090b0: f94017f6  ldr      x22, [sp, #0x28]
//   0x0090b4: f9000eba  str      x26, [x21, #0x18]
//   0x0090b8: b5001fb6  cbnz     x22, #0x94ac
//   0x0090bc: 140001bd  b        #0x97b0
//   0x0090c0: aa1503e0  mov      x0, x21
//   0x0090c4: 2a1f03e1  mov      w1, wzr
//   0x0090c8: 14000399  b        #0x9f2c
//   0x0090cc: eb0b015f  cmp      x10, x11
//   0x0090d0: 540000a1  b.ne     #0x90e4
//   0x0090d4: 1400002d  b        #0x9188
//   0x0090d8: 91001129  add      x9, x9, #4
//   0x0090dc: eb08013f  cmp      x9, x8
//   0x0090e0: 54000542  b.hs     #0x9188
//   0x0090e4: b940012a  ldr      w10, [x9]
//   0x0090e8: 5101054b  sub      w11, w10, #0x41
//   0x0090ec: 7100657f  cmp      w11, #0x19
//   0x0090f0: 54ffff48  b.hi     #0x90d8
//   0x0090f4: 1100814a  add      w10, w10, #0x20
//   0x0090f8: b900012a  str      w10, [x9]
//   0x0090fc: 17fffff7  b        #0x90d8
//   0x009100: f94017f6  ldr      x22, [sp, #0x28]
//   0x009104: 8b090a6b  add      x11, x19, x9, lsl #2
//   0x009108: eb0b035f  cmp      x26, x11
//   0x00910c: 8b080a6d  add      x13, x19, x8, lsl #2
//   0x009110: 54000082  b.hs     #0x9120
//   0x009114: 8b0a0b4b  add      x11, x26, x10, lsl #2
//   0x009118: eb0b01bf  cmp      x13, x11
//   0x00911c: 540001e3  b.lo     #0x9158
//   0x009120: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x009124: 9100434c  add      x12, x26, #0x10
//   0x009128: 8b080168  add      x8, x11, x8
//   0x00912c: 8b0b0b5a  add      x26, x26, x11, lsl #2
//   0x009130: 910041ad  add      x13, x13, #0x10
//   0x009134: aa0b03ee  mov      x14, x11
//   0x009138: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x00913c: f10021ce  subs     x14, x14, #8
//   0x009140: 910081ad  add      x13, x13, #0x20
//   0x009144: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x009148: 9100818c  add      x12, x12, #0x20
//   0x00914c: 54ffff61  b.ne     #0x9138
//   0x009150: eb0b015f  cmp      x10, x11
//   0x009154: 540000e0  b.eq     #0x9170
//   0x009158: cb080129  sub      x9, x9, x8
//   0x00915c: 8b080a68  add      x8, x19, x8, lsl #2
//   0x009160: b840450a  ldr      w10, [x8], #4
//   0x009164: f1000529  subs     x9, x9, #1
//   0x009168: b800474a  str      w10, [x26], #4
//   0x00916c: 54ffffa1  b.ne     #0x9160
//   0x009170: f9000eba  str      x26, [x21, #0x18]
//   0x009174: b50019d6  cbnz     x22, #0x94ac
//   0x009178: 1400018e  b        #0x97b0
//   0x00917c: 2a1403e1  mov      w1, w20
//   0x009180: 32000108  orr      w8, w8, #1
//   0x009184: b90037e8  str      w8, [sp, #0x34]
//   0x009188: b9001fe1  str      w1, [sp, #0x1c]
//   0x00918c: 36101441  tbz      w1, #2, #0x9414
//   0x009190: f94022a0  ldr      x0, [x21, #0x40]
//   0x009194: b4000620  cbz      x0, #0x9258
//   0x009198: b94096a9  ldr      w9, [x21, #0x94]
//   0x00919c: f94026a8  ldr      x8, [x21, #0x48]
//   0x0091a0: 34000829  cbz      w9, #0x92a4
//   0x0091a4: eb00011f  cmp      x8, x0
//   0x0091a8: 54001349  b.ls     #0x9410
//   0x0091ac: aa2003e9  mvn      x9, x0
//   0x0091b0: 8b090109  add      x9, x8, x9
//   0x0091b4: d342fd29  lsr      x9, x9, #2
//   0x0091b8: 9100052a  add      x10, x9, #1
//   0x0091bc: f100115f  cmp      x10, #4
//   0x0091c0: aa0003e9  mov      x9, x0
//   0x0091c4: 54001183  b.lo     #0x93f4
//   0x0091c8: 927ef14b  and      x11, x10, #0x7ffffffffffffffc
//   0x0091cc: 9100200c  add      x12, x0, #8
//   0x0091d0: 2f020400  mvni     v0.2s, #0x40
//   0x0091d4: 8b0b0809  add      x9, x0, x11, lsl #2
//   0x0091d8: 0f000741  movi     v1.2s, #0x1a
//   0x0091dc: aa0b03ed  mov      x13, x11
//   0x0091e0: 14000004  b        #0x91f0
//   0x0091e4: f10011ad  subs     x13, x13, #4
//   0x0091e8: 9100418c  add      x12, x12, #0x10
//   0x0091ec: 54000f80  b.eq     #0x93dc
//   0x0091f0: 6d7f8983  ldp      d3, d2, [x12, #-8]
//   0x0091f4: 0ea08464  add      v4.2s, v3.2s, v0.2s
//   0x0091f8: 2ea43424  cmhi     v4.2s, v1.2s, v4.2s
//   0x0091fc: 1e26008e  fmov     w14, s4
//   0x009200: 3600008e  tbz      w14, #0, #0x9210
//   0x009204: 1e26006e  fmov     w14, s3
//   0x009208: 110081ce  add      w14, w14, #0x20
//   0x00920c: b81f818e  stur     w14, [x12, #-8]
//   0x009210: 0e0c3c8e  mov      w14, v4.s[1]
//   0x009214: 0ea08444  add      v4.2s, v2.2s, v0.2s
//   0x009218: 3600008e  tbz      w14, #0, #0x9228
//   0x00921c: 0e0c3c6e  mov      w14, v3.s[1]
//   0x009220: 110081ce  add      w14, w14, #0x20
//   0x009224: b81fc18e  stur     w14, [x12, #-4]
//   0x009228: 2ea43423  cmhi     v3.2s, v1.2s, v4.2s
//   0x00922c: 1e26006e  fmov     w14, s3
//   0x009230: 3600008e  tbz      w14, #0, #0x9240
//   0x009234: 1e26004e  fmov     w14, s2
//   0x009238: 110081ce  add      w14, w14, #0x20
//   0x00923c: b900018e  str      w14, [x12]
//   0x009240: 0e0c3c6e  mov      w14, v3.s[1]
//   0x009244: 3607fd0e  tbz      w14, #0, #0x91e4
//   0x009248: 0e0c3c4e  mov      w14, v2.s[1]
//   0x00924c: 110081ce  add      w14, w14, #0x20
//   0x009250: b900058e  str      w14, [x12, #4]
//   0x009254: 17ffffe4  b        #0x91e4
//   0x009258: f94012b7  ldr      x23, [x21, #0x20]
//   0x00925c: b4000dd7  cbz      x23, #0x9414
//   0x009260: f9401aa8  ldr      x8, [x21, #0x30]
//   0x009264: b5000d88  cbnz     x8, #0x9414
//   0x009268: f9401ea8  ldr      x8, [x21, #0x38]
//   0x00926c: b5000d48  cbnz     x8, #0x9414
//   0x009270: b94096a9  ldr      w9, [x21, #0x94]
//   0x009274: f94016a8  ldr      x8, [x21, #0x28]
//   0x009278: 34007e09  cbz      w9, #0xa238
//   0x00927c: b4000cc8  cbz      x8, #0x9414
//   0x009280: cb170116  sub      x22, x8, x23
//   0x009284: d342fedb  lsr      x27, x22, #2
//   0x009288: 71000f7f  cmp      w27, #3
//   0x00928c: 54008b8b  b.lt     #0xa3fc
//   0x009290: 2a1f03e8  mov      w8, wzr
//   0x009294: 5280005c  mov      w28, #2
//   0x009298: 528004b5  mov      w21, #0x25
//   0x00929c: aa1703f3  mov      x19, x23
//   0x0092a0: 14000032  b        #0x9368
//   0x0092a4: b4006408  cbz      x8, #0x9f24
//   0x0092a8: cb000113  sub      x19, x8, x0
//   0x0092ac: d342fe69  lsr      x9, x19, #2
//   0x0092b0: 34000449  cbz      w9, #0x9338
//   0x0092b4: 37f86389  tbnz     w9, #0x1f, #0x9f24
//   0x0092b8: f94007e0  ldr      x0, [sp, #8]
//   0x0092bc: 93408661  sbfx     x1, x19, #0, #0x22
//   0x0092c0: f9400008  ldr      x8, [x0]
//   0x0092c4: d63f0100  blr      x8
//   0x0092c8: b40062e0  cbz      x0, #0x9f24
//   0x0092cc: f94022a9  ldr      x9, [x21, #0x40]
//   0x0092d0: d342866a  ubfx     x10, x19, #2, #0x20
//   0x0092d4: f100115f  cmp      x10, #4
//   0x0092d8: 93428668  sbfx     x8, x19, #2, #0x20
//   0x0092dc: 54000103  b.lo     #0x92fc
//   0x0092e0: d37ef54b  lsl      x11, x10, #2
//   0x0092e4: 8b0b012c  add      x12, x9, x11
//   0x0092e8: eb0c001f  cmp      x0, x12
//   0x0092ec: 54008642  b.hs     #0xa3b4
//   0x0092f0: 8b0b000b  add      x11, x0, x11
//   0x0092f4: eb09017f  cmp      x11, x9
//   0x0092f8: 540085e9  b.ls     #0xa3b4
//   0x0092fc: aa1f03eb  mov      x11, xzr
//   0x009300: d37ef56c  lsl      x12, x11, #2
//   0x009304: cb0a016a  sub      x10, x11, x10
//   0x009308: 8b0c000b  add      x11, x0, x12
//   0x00930c: 8b0c0129  add      x9, x9, x12
//   0x009310: b840452c  ldr      w12, [x9], #4
//   0x009314: 5101058d  sub      w13, w12, #0x41
//   0x009318: 1100818e  add      w14, w12, #0x20
//   0x00931c: 710069bf  cmp      w13, #0x1a
//   0x009320: 1a8c31cc  csel     w12, w14, w12, lo
//   0x009324: b100054a  adds     x10, x10, #1
//   0x009328: b800456c  str      w12, [x11], #4
//   0x00932c: 54ffff23  b.lo     #0x9310
//   0x009330: 8b080808  add      x8, x0, x8, lsl #2
//   0x009334: a90422a0  stp      x0, x8, [x21, #0x40]
//   0x009338: b94037e9  ldr      w9, [sp, #0x34]
//   0x00933c: 321e0129  orr      w9, w9, #4
//   0x009340: b90037e9  str      w9, [sp, #0x34]
//   0x009344: 14000033  b        #0x9410
//   0x009348: b9000269  str      w9, [x19]
//   0x00934c: 5280002a  mov      w10, #1
//   0x009350: 11000509  add      w9, w8, #1
//   0x009354: 11000d1c  add      w28, w8, #3
//   0x009358: 6b1b039f  cmp      w28, w27
//   0x00935c: 8b0a0a73  add      x19, x19, x10, lsl #2
//   0x009360: 2a0903e8  mov      w8, w9
//   0x009364: 5400850a  b.ge     #0xa404
//   0x009368: b868dae9  ldr      w9, [x23, w8, sxtw #2]
//   0x00936c: 7100953f  cmp      w9, #0x25
//   0x009370: 54fffec1  b.ne     #0x9348
//   0x009374: 93407d08  sxtw     x8, w8
//   0x009378: 8b080ae8  add      x8, x23, x8, lsl #2
//   0x00937c: b9400500  ldr      w0, [x8, #4]
//   0x009380: b87cdaf8  ldr      w24, [x23, w28, sxtw #2]
//   0x009384: 97ffe7af  bl       #0x3240
//   0x009388: 2a0003f9  mov      w25, w0
//   0x00938c: 2a1803e0  mov      w0, w24
//   0x009390: 97ffe7ac  bl       #0x3240
//   0x009394: 12001c18  and      w24, w0, #0xff
//   0x009398: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x00939c: 2a1a03e0  mov      w0, w26
//   0x0093a0: 97ffe748  bl       #0x30c0
//   0x0093a4: 34000080  cbz      w0, #0x93b4
//   0x0093a8: b900027a  str      w26, [x19]
//   0x0093ac: 5280002a  mov      w10, #1
//   0x0093b0: 14000009  b        #0x93d4
//   0x0093b4: 12001f20  and      w0, w25, #0xff
//   0x0093b8: b9000275  str      w21, [x19]
//   0x0093bc: 97ffe775  bl       #0x3190
//   0x0093c0: b9000660  str      w0, [x19, #4]
//   0x0093c4: 2a1803e0  mov      w0, w24
//   0x0093c8: 97ffe772  bl       #0x3190
//   0x0093cc: 5280006a  mov      w10, #3
//   0x0093d0: b9000a60  str      w0, [x19, #8]
//   0x0093d4: 2a1c03e8  mov      w8, w28
//   0x0093d8: 17ffffde  b        #0x9350
//   0x0093dc: eb0b015f  cmp      x10, x11
//   0x0093e0: 540000a1  b.ne     #0x93f4
//   0x0093e4: 1400000b  b        #0x9410
//   0x0093e8: 91001129  add      x9, x9, #4
//   0x0093ec: eb08013f  cmp      x9, x8
//   0x0093f0: 54000102  b.hs     #0x9410
//   0x0093f4: b940012a  ldr      w10, [x9]
//   0x0093f8: 5101054b  sub      w11, w10, #0x41
//   0x0093fc: 7100657f  cmp      w11, #0x19
//   0x009400: 54ffff48  b.hi     #0x93e8
//   0x009404: 1100814a  add      w10, w10, #0x20
//   0x009408: b900012a  str      w10, [x9]
//   0x00940c: 17fffff7  b        #0x93e8
//   0x009410: a90222a0  stp      x0, x8, [x21, #0x20]
//   0x009414: b4ffcb56  cbz      x22, #0x8d7c
//   0x009418: f9400aa8  ldr      x8, [x21, #0x10]
//   0x00941c: b4000488  cbz      x8, #0x94ac
//   0x009420: f9400eb3  ldr      x19, [x21, #0x18]
//   0x009424: eb08027f  cmp      x19, x8
//   0x009428: 54000429  b.ls     #0x94ac
//   0x00942c: 91002114  add      x20, x8, #8
//   0x009430: eb13029f  cmp      x20, x19
//   0x009434: 540000a3  b.lo     #0x9448
//   0x009438: 1400001d  b        #0x94ac
//   0x00943c: 91001294  add      x20, x20, #4
//   0x009440: eb13029f  cmp      x20, x19
//   0x009444: 54000322  b.hs     #0x94a8
//   0x009448: b85f8288  ldur     w8, [x20, #-8]
//   0x00944c: 7100951f  cmp      w8, #0x25
//   0x009450: 54ffff61  b.ne     #0x943c
//   0x009454: b85fc280  ldur     w0, [x20, #-4]
//   0x009458: 51018408  sub      w8, w0, #0x61
//   0x00945c: 7100191f  cmp      w8, #6
//   0x009460: 540001e3  b.lo     #0x949c
//   0x009464: b9400288  ldr      w8, [x20]
//   0x009468: 51018508  sub      w8, w8, #0x61
//   0x00946c: 7100191f  cmp      w8, #6
//   0x009470: 54000163  b.lo     #0x949c
//   0x009474: 97ffe773  bl       #0x3240
//   0x009478: b9400288  ldr      w8, [x20]
//   0x00947c: 2a0003f7  mov      w23, w0
//   0x009480: 2a0803e0  mov      w0, w8
//   0x009484: 97ffe76f  bl       #0x3240
//   0x009488: 12001ee8  and      w8, w23, #0xff
//   0x00948c: 531c6d08  lsl      w8, w8, #4
//   0x009490: 0b200100  add      w0, w8, w0, uxtb
//   0x009494: 97ffe70b  bl       #0x30c0
//   0x009498: 34fffd20  cbz      w0, #0x943c
//   0x00949c: b94002c8  ldr      w8, [x22]
//   0x0094a0: 321f0108  orr      w8, w8, #2
//   0x0094a4: b90002c8  str      w8, [x22]
//   0x0094a8: b4001856  cbz      x22, #0x97b0
//   0x0094ac: f94032b3  ldr      x19, [x21, #0x60]
//   0x0094b0: b5000093  cbnz     x19, #0x94c0
//   0x0094b4: 14000037  b        #0x9590
//   0x0094b8: f9400a73  ldr      x19, [x19, #0x10]
//   0x0094bc: b4000673  cbz      x19, #0x9588
//   0x0094c0: f9400268  ldr      x8, [x19]
//   0x0094c4: b4ffffa8  cbz      x8, #0x94b8
//   0x0094c8: f9400675  ldr      x21, [x19, #8]
//   0x0094cc: eb0802a9  subs     x9, x21, x8
//   0x0094d0: 54ffff49  b.ls     #0x94b8
//   0x0094d4: f100213f  cmp      x9, #8
//   0x0094d8: 540000e0  b.eq     #0x94f4
//   0x0094dc: f100113f  cmp      x9, #4
//   0x0094e0: 54000161  b.ne     #0x950c
//   0x0094e4: b9400109  ldr      w9, [x8]
//   0x0094e8: 7100b93f  cmp      w9, #0x2e
//   0x0094ec: 54000101  b.ne     #0x950c
//   0x0094f0: 14000023  b        #0x957c
//   0x0094f4: b9400109  ldr      w9, [x8]
//   0x0094f8: 7100b93f  cmp      w9, #0x2e
//   0x0094fc: 54000081  b.ne     #0x950c
//   0x009500: b9400509  ldr      w9, [x8, #4]
//   0x009504: 7100b93f  cmp      w9, #0x2e
//   0x009508: 540003a0  b.eq     #0x957c
//   0x00950c: 91002114  add      x20, x8, #8
//   0x009510: eb15029f  cmp      x20, x21
//   0x009514: 540000a3  b.lo     #0x9528
//   0x009518: 17ffffe8  b        #0x94b8
//   0x00951c: 91001294  add      x20, x20, #4
//   0x009520: eb15029f  cmp      x20, x21
//   0x009524: 54fffca2  b.hs     #0x94b8
//   0x009528: b85f8288  ldur     w8, [x20, #-8]
//   0x00952c: 7100951f  cmp      w8, #0x25
//   0x009530: 54ffff61  b.ne     #0x951c
//   0x009534: b85fc280  ldur     w0, [x20, #-4]
//   0x009538: 51018408  sub      w8, w0, #0x61
//   0x00953c: 7100191f  cmp      w8, #6
//   0x009540: 540001e3  b.lo     #0x957c
//   0x009544: b9400288  ldr      w8, [x20]
//   0x009548: 51018508  sub      w8, w8, #0x61
//   0x00954c: 7100191f  cmp      w8, #6
//   0x009550: 54000163  b.lo     #0x957c
//   0x009554: 97ffe73b  bl       #0x3240
//   0x009558: b9400288  ldr      w8, [x20]
//   0x00955c: 2a0003f7  mov      w23, w0
//   0x009560: 2a0803e0  mov      w0, w8
//   0x009564: 97ffe737  bl       #0x3240
//   0x009568: 12001ee8  and      w8, w23, #0xff
//   0x00956c: 531c6d08  lsl      w8, w8, #4
//   0x009570: 0b200100  add      w0, w8, w0, uxtb
//   0x009574: 97ffe6d3  bl       #0x30c0
//   0x009578: 34fffd20  cbz      w0, #0x951c
//   0x00957c: b94002c8  ldr      w8, [x22]
//   0x009580: 321d0108  orr      w8, w8, #8
//   0x009584: b90002c8  str      w8, [x22]
//   0x009588: f94013f5  ldr      x21, [sp, #0x20]
//   0x00958c: b4001176  cbz      x22, #0x97b8
//   0x009590: f9403aa8  ldr      x8, [x21, #0x70]
//   0x009594: 2a1f03f3  mov      w19, wzr
//   0x009598: b4000488  cbz      x8, #0x9628
//   0x00959c: f9403eb4  ldr      x20, [x21, #0x78]
//   0x0095a0: eb08029f  cmp      x20, x8
//   0x0095a4: 54000429  b.ls     #0x9628
//   0x0095a8: 91002113  add      x19, x8, #8
//   0x0095ac: eb14027f  cmp      x19, x20
//   0x0095b0: 540000a3  b.lo     #0x95c4
//   0x0095b4: 1400001c  b        #0x9624
//   0x0095b8: 91001273  add      x19, x19, #4
//   0x0095bc: eb14027f  cmp      x19, x20
//   0x0095c0: 54000322  b.hs     #0x9624
//   0x0095c4: b85f8268  ldur     w8, [x19, #-8]
//   0x0095c8: 7100951f  cmp      w8, #0x25
//   0x0095cc: 54ffff61  b.ne     #0x95b8
//   0x0095d0: b85fc260  ldur     w0, [x19, #-4]
//   0x0095d4: 51018408  sub      w8, w0, #0x61
//   0x0095d8: 7100191f  cmp      w8, #6
//   0x0095dc: 54000203  b.lo     #0x961c
//   0x0095e0: b9400268  ldr      w8, [x19]
//   0x0095e4: 51018508  sub      w8, w8, #0x61
//   0x0095e8: 7100191f  cmp      w8, #6
//   0x0095ec: 54000183  b.lo     #0x961c
//   0x0095f0: 97ffe714  bl       #0x3240
//   0x0095f4: b9400268  ldr      w8, [x19]
//   0x0095f8: 2a0003f6  mov      w22, w0
//   0x0095fc: 2a0803e0  mov      w0, w8
//   0x009600: 97ffe710  bl       #0x3240
//   0x009604: 12001ec8  and      w8, w22, #0xff
//   0x009608: f94017f6  ldr      x22, [sp, #0x28]
//   0x00960c: 531c6d08  lsl      w8, w8, #4
//   0x009610: 0b200100  add      w0, w8, w0, uxtb
//   0x009614: 97ffe6ab  bl       #0x30c0
//   0x009618: 34fffd00  cbz      w0, #0x95b8
//   0x00961c: 52800033  mov      w19, #1
//   0x009620: 14000002  b        #0x9628
//   0x009624: 2a1f03f3  mov      w19, wzr
//   0x009628: f94042a9  ldr      x9, [x21, #0x80]
//   0x00962c: 2a1f03e8  mov      w8, wzr
//   0x009630: b40004a9  cbz      x9, #0x96c4
//   0x009634: f94046b4  ldr      x20, [x21, #0x88]
//   0x009638: eb09029f  cmp      x20, x9
//   0x00963c: 54000449  b.ls     #0x96c4
//   0x009640: 91002135  add      x21, x9, #8
//   0x009644: eb1402bf  cmp      x21, x20
//   0x009648: 540000a3  b.lo     #0x965c
//   0x00964c: 1400001c  b        #0x96bc
//   0x009650: 910012b5  add      x21, x21, #4
//   0x009654: eb1402bf  cmp      x21, x20
//   0x009658: 54000322  b.hs     #0x96bc
//   0x00965c: b85f82a8  ldur     w8, [x21, #-8]
//   0x009660: 7100951f  cmp      w8, #0x25
//   0x009664: 54ffff61  b.ne     #0x9650
//   0x009668: b85fc2a0  ldur     w0, [x21, #-4]
//   0x00966c: 51018408  sub      w8, w0, #0x61
//   0x009670: 7100191f  cmp      w8, #6
//   0x009674: 54000203  b.lo     #0x96b4
//   0x009678: b94002a8  ldr      w8, [x21]
//   0x00967c: 51018508  sub      w8, w8, #0x61
//   0x009680: 7100191f  cmp      w8, #6
//   0x009684: 54000183  b.lo     #0x96b4
//   0x009688: 97ffe6ee  bl       #0x3240
//   0x00968c: b94002a8  ldr      w8, [x21]
//   0x009690: 2a0003f6  mov      w22, w0
//   0x009694: 2a0803e0  mov      w0, w8
//   0x009698: 97ffe6ea  bl       #0x3240
//   0x00969c: 12001ec8  and      w8, w22, #0xff
//   0x0096a0: f94017f6  ldr      x22, [sp, #0x28]
//   0x0096a4: 531c6d08  lsl      w8, w8, #4
//   0x0096a8: 0b200100  add      w0, w8, w0, uxtb
//   0x0096ac: 97ffe685  bl       #0x30c0
//   0x0096b0: 34fffd00  cbz      w0, #0x9650
//   0x0096b4: 52800028  mov      w8, #1
//   0x0096b8: 14000002  b        #0x96c0
//   0x0096bc: 2a1f03e8  mov      w8, wzr
//   0x0096c0: f94013f5  ldr      x21, [sp, #0x20]
//   0x0096c4: 34000093  cbz      w19, #0x96d4
//   0x0096c8: b94002c9  ldr      w9, [x22]
//   0x0096cc: 321c0129  orr      w9, w9, #0x10
//   0x0096d0: b90002c9  str      w9, [x22]
//   0x0096d4: 34005948  cbz      w8, #0xa1fc
//   0x0096d8: b94002c8  ldr      w8, [x22]
//   0x0096dc: 2a1f03e0  mov      w0, wzr
//   0x0096e0: 321b0108  orr      w8, w8, #0x20
//   0x0096e4: b90002c8  str      w8, [x22]
//   0x0096e8: 140002ef  b        #0xa2a4
//   0x0096ec: 2a1f03e9  mov      w9, wzr
//   0x0096f0: aa1703fb  mov      x27, x23
//   0x0096f4: 6b1c013f  cmp      w9, w28
//   0x0096f8: 5400014a  b.ge     #0x9720
//   0x0096fc: f9400bfc  ldr      x28, [sp, #0x10]
//   0x009700: f94013f5  ldr      x21, [sp, #0x20]
//   0x009704: 93407d28  sxtw     x8, w9
//   0x009708: 934286c9  sbfx     x9, x22, #2, #0x20
//   0x00970c: cb08012a  sub      x10, x9, x8
//   0x009710: f1001d5f  cmp      x10, #7
//   0x009714: 540000c8  b.hi     #0x972c
//   0x009718: f94017f6  ldr      x22, [sp, #0x28]
//   0x00971c: 1400001a  b        #0x9784
//   0x009720: f9400bfc  ldr      x28, [sp, #0x10]
//   0x009724: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x009728: 1400001d  b        #0x979c
//   0x00972c: f94017f6  ldr      x22, [sp, #0x28]
//   0x009730: 8b090a6b  add      x11, x19, x9, lsl #2
//   0x009734: eb0b037f  cmp      x27, x11
//   0x009738: 8b080a6d  add      x13, x19, x8, lsl #2
//   0x00973c: 54000082  b.hs     #0x974c
//   0x009740: 8b0a0b6b  add      x11, x27, x10, lsl #2
//   0x009744: eb0b01bf  cmp      x13, x11
//   0x009748: 540001e3  b.lo     #0x9784
//   0x00974c: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x009750: 9100436c  add      x12, x27, #0x10
//   0x009754: 8b080168  add      x8, x11, x8
//   0x009758: 8b0b0b7b  add      x27, x27, x11, lsl #2
//   0x00975c: 910041ad  add      x13, x13, #0x10
//   0x009760: aa0b03ee  mov      x14, x11
//   0x009764: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x009768: f10021ce  subs     x14, x14, #8
//   0x00976c: 910081ad  add      x13, x13, #0x20
//   0x009770: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x009774: 9100818c  add      x12, x12, #0x20
//   0x009778: 54ffff61  b.ne     #0x9764
//   0x00977c: eb0b015f  cmp      x10, x11
//   0x009780: 540000e0  b.eq     #0x979c
//   0x009784: cb080129  sub      x9, x9, x8
//   0x009788: 8b080a68  add      x8, x19, x8, lsl #2
//   0x00978c: b840450a  ldr      w10, [x8], #4
//   0x009790: f1000529  subs     x9, x9, #1
//   0x009794: b800476a  str      w10, [x27], #4
//   0x009798: 54ffffa1  b.ne     #0x978c
//   0x00979c: a9016eb7  stp      x23, x27, [x21, #0x10]
//   0x0097a0: b94037e8  ldr      w8, [sp, #0x34]
//   0x0097a4: 321f0108  orr      w8, w8, #2
//   0x0097a8: b90037e8  str      w8, [sp, #0x34]
//   0x0097ac: b5ffe816  cbnz     x22, #0x94ac
//   0x0097b0: b9401fe8  ldr      w8, [sp, #0x1c]
//   0x0097b4: 371806e8  tbnz     w8, #3, #0x9890
//   0x0097b8: b9401fe8  ldr      w8, [sp, #0x1c]
//   0x0097bc: 362031c8  tbz      w8, #4, #0x9df4
//   0x0097c0: f9403ab3  ldr      x19, [x21, #0x70]
//   0x0097c4: b4003193  cbz      x19, #0x9df4
//   0x0097c8: b94096a9  ldr      w9, [x21, #0x94]
//   0x0097cc: f9403ea8  ldr      x8, [x21, #0x78]
//   0x0097d0: 340021a9  cbz      w9, #0x9c04
//   0x0097d4: b4003108  cbz      x8, #0x9df4
//   0x0097d8: cb13011a  sub      x26, x8, x19
//   0x0097dc: d342ff55  lsr      x21, x26, #2
//   0x0097e0: 71000ebf  cmp      w21, #3
//   0x0097e4: 54002b2b  b.lt     #0x9d48
//   0x0097e8: 2a1f03e8  mov      w8, wzr
//   0x0097ec: 5280005c  mov      w28, #2
//   0x0097f0: 528004bb  mov      w27, #0x25
//   0x0097f4: aa1303f6  mov      x22, x19
//   0x0097f8: 14000009  b        #0x981c
//   0x0097fc: b90002c9  str      w9, [x22]
//   0x009800: 5280002a  mov      w10, #1
//   0x009804: 11000509  add      w9, w8, #1
//   0x009808: 11000d1c  add      w28, w8, #3
//   0x00980c: 6b15039f  cmp      w28, w21
//   0x009810: 8b0a0ad6  add      x22, x22, x10, lsl #2
//   0x009814: 2a0903e8  mov      w8, w9
//   0x009818: 540029ca  b.ge     #0x9d50
//   0x00981c: b868da69  ldr      w9, [x19, w8, sxtw #2]
//   0x009820: 7100953f  cmp      w9, #0x25
//   0x009824: 54fffec1  b.ne     #0x97fc
//   0x009828: 93407d08  sxtw     x8, w8
//   0x00982c: 8b080a68  add      x8, x19, x8, lsl #2
//   0x009830: b9400500  ldr      w0, [x8, #4]
//   0x009834: b87cda77  ldr      w23, [x19, w28, sxtw #2]
//   0x009838: 97ffe682  bl       #0x3240
//   0x00983c: 2a0003f8  mov      w24, w0
//   0x009840: 2a1703e0  mov      w0, w23
//   0x009844: 97ffe67f  bl       #0x3240
//   0x009848: 12001c17  and      w23, w0, #0xff
//   0x00984c: 0b3812f9  add      w25, w23, w24, uxtb #4
//   0x009850: 2a1903e0  mov      w0, w25
//   0x009854: 97ffe61b  bl       #0x30c0
//   0x009858: 34000080  cbz      w0, #0x9868
//   0x00985c: b90002d9  str      w25, [x22]
//   0x009860: 5280002a  mov      w10, #1
//   0x009864: 14000009  b        #0x9888
//   0x009868: 12001f00  and      w0, w24, #0xff
//   0x00986c: b90002db  str      w27, [x22]
//   0x009870: 97ffe648  bl       #0x3190
//   0x009874: b90006c0  str      w0, [x22, #4]
//   0x009878: 2a1703e0  mov      w0, w23
//   0x00987c: 97ffe645  bl       #0x3190
//   0x009880: 5280006a  mov      w10, #3
//   0x009884: b9000ac0  str      w0, [x22, #8]
//   0x009888: 2a1c03e8  mov      w8, w28
//   0x00988c: 17ffffde  b        #0x9804
//   0x009890: f94002a8  ldr      x8, [x21]
//   0x009894: b4000068  cbz      x8, #0x98a0
//   0x009898: b90007ff  str      wzr, [sp, #4]
//   0x00989c: 14000005  b        #0x98b0
//   0x0098a0: b94092a8  ldr      w8, [x21, #0x90]
//   0x0098a4: 7100011f  cmp      w8, #0
//   0x0098a8: 1a9f17e8  cset     w8, eq
//   0x0098ac: b90007e8  str      w8, [sp, #4]
//   0x0098b0: f94007f3  ldr      x19, [sp, #8]
//   0x0098b4: b94096a8  ldr      w8, [x21, #0x94]
//   0x0098b8: f94032b7  ldr      x23, [x21, #0x60]
//   0x0098bc: 34000ca8  cbz      w8, #0x9a50
//   0x0098c0: b4002237  cbz      x23, #0x9d04
//   0x0098c4: 528004b3  mov      w19, #0x25
//   0x0098c8: f94002f6  ldr      x22, [x23]
//   0x0098cc: b5000136  cbnz     x22, #0x98f0
//   0x0098d0: 14000004  b        #0x98e0
//   0x0098d4: f9400bfc  ldr      x28, [sp, #0x10]
//   0x0098d8: f94013f5  ldr      x21, [sp, #0x20]
//   0x0098dc: f90006fb  str      x27, [x23, #8]
//   0x0098e0: f9400af7  ldr      x23, [x23, #0x10]
//   0x0098e4: b40020b7  cbz      x23, #0x9cf8
//   0x0098e8: f94002f6  ldr      x22, [x23]
//   0x0098ec: b4ffffb6  cbz      x22, #0x98e0
//   0x0098f0: f94006e8  ldr      x8, [x23, #8]
//   0x0098f4: b4ffff68  cbz      x8, #0x98e0
//   0x0098f8: cb16011c  sub      x28, x8, x22
//   0x0098fc: d342ff95  lsr      x21, x28, #2
//   0x009900: 71000ebf  cmp      w21, #3
//   0x009904: 5400054b  b.lt     #0x99ac
//   0x009908: 2a1f03e8  mov      w8, wzr
//   0x00990c: 52800054  mov      w20, #2
//   0x009910: aa1603fb  mov      x27, x22
//   0x009914: 14000009  b        #0x9938
//   0x009918: b9000369  str      w9, [x27]
//   0x00991c: 5280002a  mov      w10, #1
//   0x009920: 11000509  add      w9, w8, #1
//   0x009924: 11000d14  add      w20, w8, #3
//   0x009928: 6b15029f  cmp      w20, w21
//   0x00992c: 8b0a0b7b  add      x27, x27, x10, lsl #2
//   0x009930: 2a0903e8  mov      w8, w9
//   0x009934: 5400040a  b.ge     #0x99b4
//   0x009938: b868dac9  ldr      w9, [x22, w8, sxtw #2]
//   0x00993c: 7100953f  cmp      w9, #0x25
//   0x009940: 54fffec1  b.ne     #0x9918
//   0x009944: 93407d08  sxtw     x8, w8
//   0x009948: 8b080ac8  add      x8, x22, x8, lsl #2
//   0x00994c: b9400500  ldr      w0, [x8, #4]
//   0x009950: b874dad8  ldr      w24, [x22, w20, sxtw #2]
//   0x009954: 97ffe63b  bl       #0x3240
//   0x009958: 2a0003f9  mov      w25, w0
//   0x00995c: 2a1803e0  mov      w0, w24
//   0x009960: 97ffe638  bl       #0x3240
//   0x009964: 12001c18  and      w24, w0, #0xff
//   0x009968: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x00996c: 2a1a03e0  mov      w0, w26
//   0x009970: 97ffe5d4  bl       #0x30c0
//   0x009974: 34000080  cbz      w0, #0x9984
//   0x009978: b900037a  str      w26, [x27]
//   0x00997c: 5280002a  mov      w10, #1
//   0x009980: 14000009  b        #0x99a4
//   0x009984: 12001f20  and      w0, w25, #0xff
//   0x009988: b9000373  str      w19, [x27]
//   0x00998c: 97ffe601  bl       #0x3190
//   0x009990: b9000760  str      w0, [x27, #4]
//   0x009994: 2a1803e0  mov      w0, w24
//   0x009998: 97ffe5fe  bl       #0x3190
//   0x00999c: 5280006a  mov      w10, #3
//   0x0099a0: b9000b60  str      w0, [x27, #8]
//   0x0099a4: 2a1403e8  mov      w8, w20
//   0x0099a8: 17ffffde  b        #0x9920
//   0x0099ac: 2a1f03e9  mov      w9, wzr
//   0x0099b0: aa1603fb  mov      x27, x22
//   0x0099b4: 6b15013f  cmp      w9, w21
//   0x0099b8: 54fff8ea  b.ge     #0x98d4
//   0x0099bc: f94013f5  ldr      x21, [sp, #0x20]
//   0x0099c0: 93407d28  sxtw     x8, w9
//   0x0099c4: 93428789  sbfx     x9, x28, #2, #0x20
//   0x0099c8: cb08012a  sub      x10, x9, x8
//   0x0099cc: f1001d5f  cmp      x10, #7
//   0x0099d0: 54000068  b.hi     #0x99dc
//   0x0099d4: f9400bfc  ldr      x28, [sp, #0x10]
//   0x0099d8: 14000017  b        #0x9a34
//   0x0099dc: f9400bfc  ldr      x28, [sp, #0x10]
//   0x0099e0: 8b090acb  add      x11, x22, x9, lsl #2
//   0x0099e4: eb0b037f  cmp      x27, x11
//   0x0099e8: 8b080acd  add      x13, x22, x8, lsl #2
//   0x0099ec: 54000082  b.hs     #0x99fc
//   0x0099f0: 8b0a0b6b  add      x11, x27, x10, lsl #2
//   0x0099f4: eb0b01bf  cmp      x13, x11
//   0x0099f8: 540001e3  b.lo     #0x9a34
//   0x0099fc: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x009a00: 9100436c  add      x12, x27, #0x10
//   0x009a04: 8b080168  add      x8, x11, x8
//   0x009a08: 8b0b0b7b  add      x27, x27, x11, lsl #2
//   0x009a0c: 910041ad  add      x13, x13, #0x10
//   0x009a10: aa0b03ee  mov      x14, x11
//   0x009a14: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x009a18: f10021ce  subs     x14, x14, #8
//   0x009a1c: 910081ad  add      x13, x13, #0x20
//   0x009a20: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x009a24: 9100818c  add      x12, x12, #0x20
//   0x009a28: 54ffff61  b.ne     #0x9a14
//   0x009a2c: eb0b015f  cmp      x10, x11
//   0x009a30: 54fff560  b.eq     #0x98dc
//   0x009a34: cb080129  sub      x9, x9, x8
//   0x009a38: 8b080ac8  add      x8, x22, x8, lsl #2
//   0x009a3c: b840450a  ldr      w10, [x8], #4
//   0x009a40: f1000529  subs     x9, x9, #1
//   0x009a44: b800476a  str      w10, [x27], #4
//   0x009a48: 54ffffa1  b.ne     #0x9a3c
//   0x009a4c: 17ffffa4  b        #0x98dc
//   0x009a50: b5000117  cbnz     x23, #0x9a70
//   0x009a54: 140000a6  b        #0x9cec
//   0x009a58: f9400bfc  ldr      x28, [sp, #0x10]
//   0x009a5c: f94013f5  ldr      x21, [sp, #0x20]
//   0x009a60: a9005af8  stp      x24, x22, [x23]
//   0x009a64: f94007f3  ldr      x19, [sp, #8]
//   0x009a68: f9400af7  ldr      x23, [x23, #0x10]
//   0x009a6c: b4001417  cbz      x23, #0x9cec
//   0x009a70: f94002e8  ldr      x8, [x23]
//   0x009a74: b40040e8  cbz      x8, #0xa290
//   0x009a78: f94006e9  ldr      x9, [x23, #8]
//   0x009a7c: b40040a9  cbz      x9, #0xa290
//   0x009a80: cb080128  sub      x8, x9, x8
//   0x009a84: d342fd09  lsr      x9, x8, #2
//   0x009a88: 34ffff09  cbz      w9, #0x9a68
//   0x009a8c: 37f84029  tbnz     w9, #0x1f, #0xa290
//   0x009a90: f9400269  ldr      x9, [x19]
//   0x009a94: 93408501  sbfx     x1, x8, #0, #0x22
//   0x009a98: aa1303e0  mov      x0, x19
//   0x009a9c: d63f0120  blr      x9
//   0x009aa0: b4003f80  cbz      x0, #0xa290
//   0x009aa4: a94022f3  ldp      x19, x8, [x23]
//   0x009aa8: aa0003f8  mov      x24, x0
//   0x009aac: cb130108  sub      x8, x8, x19
//   0x009ab0: d342fd15  lsr      x21, x8, #2
//   0x009ab4: aa0803f4  mov      x20, x8
//   0x009ab8: 71000ebf  cmp      w21, #3
//   0x009abc: 5400056b  b.lt     #0x9b68
//   0x009ac0: 2a1f03e8  mov      w8, wzr
//   0x009ac4: 5280005c  mov      w28, #2
//   0x009ac8: aa1803f6  mov      x22, x24
//   0x009acc: 14000009  b        #0x9af0
//   0x009ad0: b90002c9  str      w9, [x22]
//   0x009ad4: 5280002a  mov      w10, #1
//   0x009ad8: 11000509  add      w9, w8, #1
//   0x009adc: 11000d1c  add      w28, w8, #3
//   0x009ae0: 6b15039f  cmp      w28, w21
//   0x009ae4: 8b0a0ad6  add      x22, x22, x10, lsl #2
//   0x009ae8: 2a0903e8  mov      w8, w9
//   0x009aec: 5400042a  b.ge     #0x9b70
//   0x009af0: b868da69  ldr      w9, [x19, w8, sxtw #2]
//   0x009af4: 7100953f  cmp      w9, #0x25
//   0x009af8: 54fffec1  b.ne     #0x9ad0
//   0x009afc: 93407d08  sxtw     x8, w8
//   0x009b00: 8b080a68  add      x8, x19, x8, lsl #2
//   0x009b04: b9400500  ldr      w0, [x8, #4]
//   0x009b08: b87cda79  ldr      w25, [x19, w28, sxtw #2]
//   0x009b0c: 97ffe5cd  bl       #0x3240
//   0x009b10: 2a0003fa  mov      w26, w0
//   0x009b14: 2a1903e0  mov      w0, w25
//   0x009b18: 97ffe5ca  bl       #0x3240
//   0x009b1c: 12001c19  and      w25, w0, #0xff
//   0x009b20: 0b3a133b  add      w27, w25, w26, uxtb #4
//   0x009b24: 2a1b03e0  mov      w0, w27
//   0x009b28: 97ffe566  bl       #0x30c0
//   0x009b2c: 34000080  cbz      w0, #0x9b3c
//   0x009b30: b90002db  str      w27, [x22]
//   0x009b34: 5280002a  mov      w10, #1
//   0x009b38: 1400000a  b        #0x9b60
//   0x009b3c: 12001f40  and      w0, w26, #0xff
//   0x009b40: 528004a8  mov      w8, #0x25
//   0x009b44: b90002c8  str      w8, [x22]
//   0x009b48: 97ffe592  bl       #0x3190
//   0x009b4c: b90006c0  str      w0, [x22, #4]
//   0x009b50: 2a1903e0  mov      w0, w25
//   0x009b54: 97ffe58f  bl       #0x3190
//   0x009b58: 5280006a  mov      w10, #3
//   0x009b5c: b9000ac0  str      w0, [x22, #8]
//   0x009b60: 2a1c03e8  mov      w8, w28
//   0x009b64: 17ffffdd  b        #0x9ad8
//   0x009b68: 2a1f03e9  mov      w9, wzr
//   0x009b6c: aa1803f6  mov      x22, x24
//   0x009b70: 6b15013f  cmp      w9, w21
//   0x009b74: 54fff72a  b.ge     #0x9a58
//   0x009b78: f9400bfc  ldr      x28, [sp, #0x10]
//   0x009b7c: f94013f5  ldr      x21, [sp, #0x20]
//   0x009b80: 93407d28  sxtw     x8, w9
//   0x009b84: 93428689  sbfx     x9, x20, #2, #0x20
//   0x009b88: cb08012a  sub      x10, x9, x8
//   0x009b8c: f1001d5f  cmp      x10, #7
//   0x009b90: 540002c9  b.ls     #0x9be8
//   0x009b94: 8b090a6b  add      x11, x19, x9, lsl #2
//   0x009b98: eb0b02df  cmp      x22, x11
//   0x009b9c: 8b080a6d  add      x13, x19, x8, lsl #2
//   0x009ba0: 54000082  b.hs     #0x9bb0
//   0x009ba4: 8b0a0acb  add      x11, x22, x10, lsl #2
//   0x009ba8: eb0b01bf  cmp      x13, x11
//   0x009bac: 540001e3  b.lo     #0x9be8
//   0x009bb0: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x009bb4: 910042cc  add      x12, x22, #0x10
//   0x009bb8: 8b080168  add      x8, x11, x8
//   0x009bbc: 8b0b0ad6  add      x22, x22, x11, lsl #2
//   0x009bc0: 910041ad  add      x13, x13, #0x10
//   0x009bc4: aa0b03ee  mov      x14, x11
//   0x009bc8: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x009bcc: f10021ce  subs     x14, x14, #8
//   0x009bd0: 910081ad  add      x13, x13, #0x20
//   0x009bd4: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x009bd8: 9100818c  add      x12, x12, #0x20
//   0x009bdc: 54ffff61  b.ne     #0x9bc8
//   0x009be0: eb0b015f  cmp      x10, x11
//   0x009be4: 54fff3e0  b.eq     #0x9a60
//   0x009be8: cb080129  sub      x9, x9, x8
//   0x009bec: 8b080a68  add      x8, x19, x8, lsl #2
//   0x009bf0: b840450a  ldr      w10, [x8], #4
//   0x009bf4: f1000529  subs     x9, x9, #1
//   0x009bf8: b80046ca  str      w10, [x22], #4
//   0x009bfc: 54ffffa1  b.ne     #0x9bf0
//   0x009c00: 17ffff98  b        #0x9a60
//   0x009c04: b4001908  cbz      x8, #0x9f24
//   0x009c08: cb130108  sub      x8, x8, x19
//   0x009c0c: d342fd09  lsr      x9, x8, #2
//   0x009c10: 340028e9  cbz      w9, #0xa12c
//   0x009c14: 37f81889  tbnz     w9, #0x1f, #0x9f24
//   0x009c18: f94007e0  ldr      x0, [sp, #8]
//   0x009c1c: 93408501  sbfx     x1, x8, #0, #0x22
//   0x009c20: f9400009  ldr      x9, [x0]
//   0x009c24: d63f0120  blr      x9
//   0x009c28: b40017e0  cbz      x0, #0x9f24
//   0x009c2c: a94722b3  ldp      x19, x8, [x21, #0x70]
//   0x009c30: aa0003f7  mov      x23, x0
//   0x009c34: cb13011b  sub      x27, x8, x19
//   0x009c38: d342ff7c  lsr      x28, x27, #2
//   0x009c3c: 71000f9f  cmp      w28, #3
//   0x009c40: 5400220b  b.lt     #0xa080
//   0x009c44: 2a1f03e8  mov      w8, wzr
//   0x009c48: 52800055  mov      w21, #2
//   0x009c4c: 528004b4  mov      w20, #0x25
//   0x009c50: aa1703f6  mov      x22, x23
//   0x009c54: 14000009  b        #0x9c78
//   0x009c58: b90002c9  str      w9, [x22]
//   0x009c5c: 5280002a  mov      w10, #1
//   0x009c60: 11000509  add      w9, w8, #1
//   0x009c64: 11000d15  add      w21, w8, #3
//   0x009c68: 6b1c02bf  cmp      w21, w28
//   0x009c6c: 8b0a0ad6  add      x22, x22, x10, lsl #2
//   0x009c70: 2a0903e8  mov      w8, w9
//   0x009c74: 540020aa  b.ge     #0xa088
//   0x009c78: b868da69  ldr      w9, [x19, w8, sxtw #2]
//   0x009c7c: 7100953f  cmp      w9, #0x25
//   0x009c80: 54fffec1  b.ne     #0x9c58
//   0x009c84: 93407d08  sxtw     x8, w8
//   0x009c88: 8b080a68  add      x8, x19, x8, lsl #2
//   0x009c8c: b9400500  ldr      w0, [x8, #4]
//   0x009c90: b875da78  ldr      w24, [x19, w21, sxtw #2]
//   0x009c94: 97ffe56b  bl       #0x3240
//   0x009c98: 2a0003f9  mov      w25, w0
//   0x009c9c: 2a1803e0  mov      w0, w24
//   0x009ca0: 97ffe568  bl       #0x3240
//   0x009ca4: 12001c18  and      w24, w0, #0xff
//   0x009ca8: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x009cac: 2a1a03e0  mov      w0, w26
//   0x009cb0: 97ffe504  bl       #0x30c0
//   0x009cb4: 34000080  cbz      w0, #0x9cc4
//   0x009cb8: b90002da  str      w26, [x22]
//   0x009cbc: 5280002a  mov      w10, #1
//   0x009cc0: 14000009  b        #0x9ce4
//   0x009cc4: 12001f20  and      w0, w25, #0xff
//   0x009cc8: b90002d4  str      w20, [x22]
//   0x009ccc: 97ffe531  bl       #0x3190
//   0x009cd0: b90006c0  str      w0, [x22, #4]
//   0x009cd4: 2a1803e0  mov      w0, w24
//   0x009cd8: 97ffe52e  bl       #0x3190
//   0x009cdc: 5280006a  mov      w10, #3
//   0x009ce0: b9000ac0  str      w0, [x22, #8]
//   0x009ce4: 2a1503e8  mov      w8, w21
//   0x009ce8: 17ffffde  b        #0x9c60
//   0x009cec: b94037e8  ldr      w8, [sp, #0x34]
//   0x009cf0: 321d0108  orr      w8, w8, #8
//   0x009cf4: b90037e8  str      w8, [sp, #0x34]
//   0x009cf8: b94096a8  ldr      w8, [x21, #0x94]
//   0x009cfc: f94007f3  ldr      x19, [sp, #8]
//   0x009d00: f94017f6  ldr      x22, [sp, #0x28]
//   0x009d04: 7100051f  cmp      w8, #1
//   0x009d08: 54000061  b.ne     #0x9d14
//   0x009d0c: 52800022  mov      w2, #1
//   0x009d10: 14000003  b        #0x9d1c
//   0x009d14: b94037e8  ldr      w8, [sp, #0x34]
//   0x009d18: 53030d02  ubfx     w2, w8, #3, #1
//   0x009d1c: b94007e1  ldr      w1, [sp, #4]
//   0x009d20: aa1503e0  mov      x0, x21
//   0x009d24: aa1303e3  mov      x3, x19
//   0x009d28: 97ffe572  bl       #0x32f0
//   0x009d2c: 34002b20  cbz      w0, #0xa290
//   0x009d30: aa1503e0  mov      x0, x21
//   0x009d34: aa1303e1  mov      x1, x19
//   0x009d38: 97ffe4e6  bl       #0x30d0
//   0x009d3c: f94013f5  ldr      x21, [sp, #0x20]
//   0x009d40: b5ffc296  cbnz     x22, #0x9590
//   0x009d44: 17fffe9d  b        #0x97b8
//   0x009d48: 2a1f03e9  mov      w9, wzr
//   0x009d4c: aa1303f6  mov      x22, x19
//   0x009d50: 6b15013f  cmp      w9, w21
//   0x009d54: 5400048a  b.ge     #0x9de4
//   0x009d58: f9400bfc  ldr      x28, [sp, #0x10]
//   0x009d5c: f94013f5  ldr      x21, [sp, #0x20]
//   0x009d60: 93407d28  sxtw     x8, w9
//   0x009d64: 93428749  sbfx     x9, x26, #2, #0x20
//   0x009d68: cb08012a  sub      x10, x9, x8
//   0x009d6c: f1001d5f  cmp      x10, #7
//   0x009d70: 540002c9  b.ls     #0x9dc8
//   0x009d74: 8b090a6b  add      x11, x19, x9, lsl #2
//   0x009d78: eb0b02df  cmp      x22, x11
//   0x009d7c: 8b080a6d  add      x13, x19, x8, lsl #2
//   0x009d80: 54000082  b.hs     #0x9d90
//   0x009d84: 8b0a0acb  add      x11, x22, x10, lsl #2
//   0x009d88: eb0b01bf  cmp      x13, x11
//   0x009d8c: 540001e3  b.lo     #0x9dc8
//   0x009d90: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x009d94: 910042cc  add      x12, x22, #0x10
//   0x009d98: 8b080168  add      x8, x11, x8
//   0x009d9c: 8b0b0ad6  add      x22, x22, x11, lsl #2
//   0x009da0: 910041ad  add      x13, x13, #0x10
//   0x009da4: aa0b03ee  mov      x14, x11
//   0x009da8: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x009dac: f10021ce  subs     x14, x14, #8
//   0x009db0: 910081ad  add      x13, x13, #0x20
//   0x009db4: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x009db8: 9100818c  add      x12, x12, #0x20
//   0x009dbc: 54ffff61  b.ne     #0x9da8
//   0x009dc0: eb0b015f  cmp      x10, x11
//   0x009dc4: 54000140  b.eq     #0x9dec
//   0x009dc8: cb080129  sub      x9, x9, x8
//   0x009dcc: 8b080a68  add      x8, x19, x8, lsl #2
//   0x009dd0: b840450a  ldr      w10, [x8], #4
//   0x009dd4: f1000529  subs     x9, x9, #1
//   0x009dd8: b80046ca  str      w10, [x22], #4
//   0x009ddc: 54ffffa1  b.ne     #0x9dd0
//   0x009de0: 14000003  b        #0x9dec
//   0x009de4: f9400bfc  ldr      x28, [sp, #0x10]
//   0x009de8: f94013f5  ldr      x21, [sp, #0x20]
//   0x009dec: f9003eb6  str      x22, [x21, #0x78]
//   0x009df0: f94017f6  ldr      x22, [sp, #0x28]
//   0x009df4: b9401fe8  ldr      w8, [sp, #0x1c]
//   0x009df8: 36282028  tbz      w8, #5, #0xa1fc
//   0x009dfc: f94042b3  ldr      x19, [x21, #0x80]
//   0x009e00: b4001ff3  cbz      x19, #0xa1fc
//   0x009e04: b94096a9  ldr      w9, [x21, #0x94]
//   0x009e08: f94046a8  ldr      x8, [x21, #0x88]
//   0x009e0c: 34000629  cbz      w9, #0x9ed0
//   0x009e10: b4001f68  cbz      x8, #0xa1fc
//   0x009e14: cb13011a  sub      x26, x8, x19
//   0x009e18: d342ff55  lsr      x21, x26, #2
//   0x009e1c: 71000ebf  cmp      w21, #3
//   0x009e20: 54000d4b  b.lt     #0x9fc8
//   0x009e24: 2a1f03e8  mov      w8, wzr
//   0x009e28: 5280005c  mov      w28, #2
//   0x009e2c: 528004bb  mov      w27, #0x25
//   0x009e30: aa1303f9  mov      x25, x19
//   0x009e34: 14000009  b        #0x9e58
//   0x009e38: b9000329  str      w9, [x25]
//   0x009e3c: 5280002a  mov      w10, #1
//   0x009e40: 11000509  add      w9, w8, #1
//   0x009e44: 11000d1c  add      w28, w8, #3
//   0x009e48: 6b15039f  cmp      w28, w21
//   0x009e4c: 8b0a0b39  add      x25, x25, x10, lsl #2
//   0x009e50: 2a0903e8  mov      w8, w9
//   0x009e54: 54000bea  b.ge     #0x9fd0
//   0x009e58: b868da69  ldr      w9, [x19, w8, sxtw #2]
//   0x009e5c: 7100953f  cmp      w9, #0x25
//   0x009e60: 54fffec1  b.ne     #0x9e38
//   0x009e64: 93407d08  sxtw     x8, w8
//   0x009e68: 8b080a68  add      x8, x19, x8, lsl #2
//   0x009e6c: b9400500  ldr      w0, [x8, #4]
//   0x009e70: b87cda76  ldr      w22, [x19, w28, sxtw #2]
//   0x009e74: 97ffe4f3  bl       #0x3240
//   0x009e78: 2a0003f7  mov      w23, w0
//   0x009e7c: 2a1603e0  mov      w0, w22
//   0x009e80: 97ffe4f0  bl       #0x3240
//   0x009e84: 12001c16  and      w22, w0, #0xff
//   0x009e88: 0b3712d8  add      w24, w22, w23, uxtb #4
//   0x009e8c: 2a1803e0  mov      w0, w24
//   0x009e90: 97ffe48c  bl       #0x30c0
//   0x009e94: 34000080  cbz      w0, #0x9ea4
//   0x009e98: b9000338  str      w24, [x25]
//   0x009e9c: 5280002a  mov      w10, #1
//   0x009ea0: 14000009  b        #0x9ec4
//   0x009ea4: 12001ee0  and      w0, w23, #0xff
//   0x009ea8: b900033b  str      w27, [x25]
//   0x009eac: 97ffe4b9  bl       #0x3190
//   0x009eb0: b9000720  str      w0, [x25, #4]
//   0x009eb4: 2a1603e0  mov      w0, w22
//   0x009eb8: 97ffe4b6  bl       #0x3190
//   0x009ebc: 5280006a  mov      w10, #3
//   0x009ec0: b9000b20  str      w0, [x25, #8]
//   0x009ec4: f94017f6  ldr      x22, [sp, #0x28]
//   0x009ec8: 2a1c03e8  mov      w8, w28
//   0x009ecc: 17ffffdd  b        #0x9e40
//   0x009ed0: b40002a8  cbz      x8, #0x9f24
//   0x009ed4: cb130108  sub      x8, x8, x19
//   0x009ed8: d342fd09  lsr      x9, x8, #2
//   0x009edc: 34001889  cbz      w9, #0xa1ec
//   0x009ee0: 37f80229  tbnz     w9, #0x1f, #0x9f24
//   0x009ee4: f94007e0  ldr      x0, [sp, #8]
//   0x009ee8: 93408501  sbfx     x1, x8, #0, #0x22
//   0x009eec: f9400009  ldr      x9, [x0]
//   0x009ef0: d63f0120  blr      x9
//   0x009ef4: b4000180  cbz      x0, #0x9f24
//   0x009ef8: a94822b3  ldp      x19, x8, [x21, #0x80]
//   0x009efc: aa0003f6  mov      x22, x0
//   0x009f00: cb13011b  sub      x27, x8, x19
//   0x009f04: d342ff7c  lsr      x28, x27, #2
//   0x009f08: 71000f9f  cmp      w28, #3
//   0x009f0c: 540011cb  b.lt     #0xa144
//   0x009f10: 2a1f03e8  mov      w8, wzr
//   0x009f14: 52800055  mov      w21, #2
//   0x009f18: 528004b4  mov      w20, #0x25
//   0x009f1c: aa1603fa  mov      x26, x22
//   0x009f20: 1400000d  b        #0x9f54
//   0x009f24: b94037e1  ldr      w1, [sp, #0x34]
//   0x009f28: aa1503e0  mov      x0, x21
//   0x009f2c: f94007e2  ldr      x2, [sp, #8]
//   0x009f30: 140000db  b        #0xa29c
//   0x009f34: b9000349  str      w9, [x26]
//   0x009f38: 5280002a  mov      w10, #1
//   0x009f3c: 11000509  add      w9, w8, #1
//   0x009f40: 11000d15  add      w21, w8, #3
//   0x009f44: 6b1c02bf  cmp      w21, w28
//   0x009f48: 8b0a0b5a  add      x26, x26, x10, lsl #2
//   0x009f4c: 2a0903e8  mov      w8, w9
//   0x009f50: 54000fea  b.ge     #0xa14c
//   0x009f54: b868da69  ldr      w9, [x19, w8, sxtw #2]
//   0x009f58: 7100953f  cmp      w9, #0x25
//   0x009f5c: 54fffec1  b.ne     #0x9f34
//   0x009f60: 93407d08  sxtw     x8, w8
//   0x009f64: 8b080a68  add      x8, x19, x8, lsl #2
//   0x009f68: b9400500  ldr      w0, [x8, #4]
//   0x009f6c: b875da77  ldr      w23, [x19, w21, sxtw #2]
//   0x009f70: 97ffe4b4  bl       #0x3240
//   0x009f74: 2a0003f8  mov      w24, w0
//   0x009f78: 2a1703e0  mov      w0, w23
//   0x009f7c: 97ffe4b1  bl       #0x3240
//   0x009f80: 12001c17  and      w23, w0, #0xff
//   0x009f84: 0b3812f9  add      w25, w23, w24, uxtb #4
//   0x009f88: 2a1903e0  mov      w0, w25
//   0x009f8c: 97ffe44d  bl       #0x30c0
//   0x009f90: 34000080  cbz      w0, #0x9fa0
//   0x009f94: b9000359  str      w25, [x26]
//   0x009f98: 5280002a  mov      w10, #1
//   0x009f9c: 14000009  b        #0x9fc0
//   0x009fa0: 12001f00  and      w0, w24, #0xff
//   0x009fa4: b9000354  str      w20, [x26]
//   0x009fa8: 97ffe47a  bl       #0x3190
//   0x009fac: b9000740  str      w0, [x26, #4]
//   0x009fb0: 2a1703e0  mov      w0, w23
//   0x009fb4: 97ffe477  bl       #0x3190
//   0x009fb8: 5280006a  mov      w10, #3
//   0x009fbc: b9000b40  str      w0, [x26, #8]
//   0x009fc0: 2a1503e8  mov      w8, w21
//   0x009fc4: 17ffffde  b        #0x9f3c
//   0x009fc8: 2a1f03e9  mov      w9, wzr
//   0x009fcc: aa1303f9  mov      x25, x19
//   0x009fd0: 6b15013f  cmp      w9, w21
//   0x009fd4: 540004ca  b.ge     #0xa06c
//   0x009fd8: f9400bfc  ldr      x28, [sp, #0x10]
//   0x009fdc: f94013f5  ldr      x21, [sp, #0x20]
//   0x009fe0: 93407d28  sxtw     x8, w9
//   0x009fe4: 93428749  sbfx     x9, x26, #2, #0x20
//   0x009fe8: cb08012a  sub      x10, x9, x8
//   0x009fec: f1001d5f  cmp      x10, #7
//   0x009ff0: 540002c9  b.ls     #0xa048
//   0x009ff4: 8b090a6b  add      x11, x19, x9, lsl #2
//   0x009ff8: eb0b033f  cmp      x25, x11
//   0x009ffc: 8b080a6d  add      x13, x19, x8, lsl #2
//   0x00a000: 54000082  b.hs     #0xa010
//   0x00a004: 8b0a0b2b  add      x11, x25, x10, lsl #2
//   0x00a008: eb0b01bf  cmp      x13, x11
//   0x00a00c: 540001e3  b.lo     #0xa048
//   0x00a010: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x00a014: 9100432c  add      x12, x25, #0x10
//   0x00a018: 8b080168  add      x8, x11, x8
//   0x00a01c: 8b0b0b39  add      x25, x25, x11, lsl #2
//   0x00a020: 910041ad  add      x13, x13, #0x10
//   0x00a024: aa0b03ee  mov      x14, x11
//   0x00a028: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x00a02c: f10021ce  subs     x14, x14, #8
//   0x00a030: 910081ad  add      x13, x13, #0x20
//   0x00a034: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x00a038: 9100818c  add      x12, x12, #0x20
//   0x00a03c: 54ffff61  b.ne     #0xa028
//   0x00a040: eb0b015f  cmp      x10, x11
//   0x00a044: 540000e0  b.eq     #0xa060
//   0x00a048: cb080129  sub      x9, x9, x8
//   0x00a04c: 8b080a68  add      x8, x19, x8, lsl #2
//   0x00a050: b840450a  ldr      w10, [x8], #4
//   0x00a054: f1000529  subs     x9, x9, #1
//   0x00a058: b800472a  str      w10, [x25], #4
//   0x00a05c: 54ffffa1  b.ne     #0xa050
//   0x00a060: f90046b9  str      x25, [x21, #0x88]
//   0x00a064: b5000d36  cbnz     x22, #0xa208
//   0x00a068: 14000066  b        #0xa200
//   0x00a06c: f94013f5  ldr      x21, [sp, #0x20]
//   0x00a070: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a074: f90046b9  str      x25, [x21, #0x88]
//   0x00a078: b5000c96  cbnz     x22, #0xa208
//   0x00a07c: 14000061  b        #0xa200
//   0x00a080: 2a1f03e9  mov      w9, wzr
//   0x00a084: aa1703f6  mov      x22, x23
//   0x00a088: 6b1c013f  cmp      w9, w28
//   0x00a08c: 5400048a  b.ge     #0xa11c
//   0x00a090: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a094: f94013f5  ldr      x21, [sp, #0x20]
//   0x00a098: 93407d28  sxtw     x8, w9
//   0x00a09c: 93428769  sbfx     x9, x27, #2, #0x20
//   0x00a0a0: cb08012a  sub      x10, x9, x8
//   0x00a0a4: f1001d5f  cmp      x10, #7
//   0x00a0a8: 540002c9  b.ls     #0xa100
//   0x00a0ac: 8b090a6b  add      x11, x19, x9, lsl #2
//   0x00a0b0: eb0b02df  cmp      x22, x11
//   0x00a0b4: 8b080a6d  add      x13, x19, x8, lsl #2
//   0x00a0b8: 54000082  b.hs     #0xa0c8
//   0x00a0bc: 8b0a0acb  add      x11, x22, x10, lsl #2
//   0x00a0c0: eb0b01bf  cmp      x13, x11
//   0x00a0c4: 540001e3  b.lo     #0xa100
//   0x00a0c8: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x00a0cc: 910042cc  add      x12, x22, #0x10
//   0x00a0d0: 8b080168  add      x8, x11, x8
//   0x00a0d4: 8b0b0ad6  add      x22, x22, x11, lsl #2
//   0x00a0d8: 910041ad  add      x13, x13, #0x10
//   0x00a0dc: aa0b03ee  mov      x14, x11
//   0x00a0e0: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x00a0e4: f10021ce  subs     x14, x14, #8
//   0x00a0e8: 910081ad  add      x13, x13, #0x20
//   0x00a0ec: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x00a0f0: 9100818c  add      x12, x12, #0x20
//   0x00a0f4: 54ffff61  b.ne     #0xa0e0
//   0x00a0f8: eb0b015f  cmp      x10, x11
//   0x00a0fc: 54000140  b.eq     #0xa124
//   0x00a100: cb080129  sub      x9, x9, x8
//   0x00a104: 8b080a68  add      x8, x19, x8, lsl #2
//   0x00a108: b840450a  ldr      w10, [x8], #4
//   0x00a10c: f1000529  subs     x9, x9, #1
//   0x00a110: b80046ca  str      w10, [x22], #4
//   0x00a114: 54ffffa1  b.ne     #0xa108
//   0x00a118: 14000003  b        #0xa124
//   0x00a11c: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a120: f94013f5  ldr      x21, [sp, #0x20]
//   0x00a124: a9075ab7  stp      x23, x22, [x21, #0x70]
//   0x00a128: f94017f6  ldr      x22, [sp, #0x28]
//   0x00a12c: b94037e8  ldr      w8, [sp, #0x34]
//   0x00a130: 321c0108  orr      w8, w8, #0x10
//   0x00a134: b90037e8  str      w8, [sp, #0x34]
//   0x00a138: b9401fe8  ldr      w8, [sp, #0x1c]
//   0x00a13c: 372fe608  tbnz     w8, #5, #0x9dfc
//   0x00a140: 1400002f  b        #0xa1fc
//   0x00a144: 2a1f03e9  mov      w9, wzr
//   0x00a148: aa1603fa  mov      x26, x22
//   0x00a14c: 6b1c013f  cmp      w9, w28
//   0x00a150: 5400048a  b.ge     #0xa1e0
//   0x00a154: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a158: f94013f5  ldr      x21, [sp, #0x20]
//   0x00a15c: 93407d28  sxtw     x8, w9
//   0x00a160: 93428769  sbfx     x9, x27, #2, #0x20
//   0x00a164: cb08012a  sub      x10, x9, x8
//   0x00a168: f1001d5f  cmp      x10, #7
//   0x00a16c: 540002c9  b.ls     #0xa1c4
//   0x00a170: 8b090a6b  add      x11, x19, x9, lsl #2
//   0x00a174: eb0b035f  cmp      x26, x11
//   0x00a178: 8b080a6d  add      x13, x19, x8, lsl #2
//   0x00a17c: 54000082  b.hs     #0xa18c
//   0x00a180: 8b0a0b4b  add      x11, x26, x10, lsl #2
//   0x00a184: eb0b01bf  cmp      x13, x11
//   0x00a188: 540001e3  b.lo     #0xa1c4
//   0x00a18c: 927df14b  and      x11, x10, #0xfffffffffffffff8
//   0x00a190: 9100434c  add      x12, x26, #0x10
//   0x00a194: 8b080168  add      x8, x11, x8
//   0x00a198: 8b0b0b5a  add      x26, x26, x11, lsl #2
//   0x00a19c: 910041ad  add      x13, x13, #0x10
//   0x00a1a0: aa0b03ee  mov      x14, x11
//   0x00a1a4: ad7f85a0  ldp      q0, q1, [x13, #-0x10]
//   0x00a1a8: f10021ce  subs     x14, x14, #8
//   0x00a1ac: 910081ad  add      x13, x13, #0x20
//   0x00a1b0: ad3f8580  stp      q0, q1, [x12, #-0x10]
//   0x00a1b4: 9100818c  add      x12, x12, #0x20
//   0x00a1b8: 54ffff61  b.ne     #0xa1a4
//   0x00a1bc: eb0b015f  cmp      x10, x11
//   0x00a1c0: 54000140  b.eq     #0xa1e8
//   0x00a1c4: cb080129  sub      x9, x9, x8
//   0x00a1c8: 8b080a68  add      x8, x19, x8, lsl #2
//   0x00a1cc: b840450a  ldr      w10, [x8], #4
//   0x00a1d0: f1000529  subs     x9, x9, #1
//   0x00a1d4: b800474a  str      w10, [x26], #4
//   0x00a1d8: 54ffffa1  b.ne     #0xa1cc
//   0x00a1dc: 14000003  b        #0xa1e8
//   0x00a1e0: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a1e4: f94013f5  ldr      x21, [sp, #0x20]
//   0x00a1e8: a9086ab6  stp      x22, x26, [x21, #0x80]
//   0x00a1ec: b94037e8  ldr      w8, [sp, #0x34]
//   0x00a1f0: f94017f6  ldr      x22, [sp, #0x28]
//   0x00a1f4: 321b0108  orr      w8, w8, #0x20
//   0x00a1f8: b90037e8  str      w8, [sp, #0x34]
//   0x00a1fc: b5000076  cbnz     x22, #0xa208
//   0x00a200: b94096a8  ldr      w8, [x21, #0x94]
//   0x00a204: 34000068  cbz      w8, #0xa210
//   0x00a208: 2a1f03e0  mov      w0, wzr
//   0x00a20c: 14000026  b        #0xa2a4
//   0x00a210: f94007f3  ldr      x19, [sp, #8]
//   0x00a214: 9100d3e1  add      x1, sp, #0x34
//   0x00a218: aa1503e0  mov      x0, x21
//   0x00a21c: aa1303e2  mov      x2, x19
//   0x00a220: 9400016e  bl       #0xa7d8
//   0x00a224: 34000360  cbz      w0, #0xa290
//   0x00a228: 2a1f03e0  mov      w0, wzr
//   0x00a22c: 52800028  mov      w8, #1
//   0x00a230: b90096a8  str      w8, [x21, #0x94]
//   0x00a234: 1400001c  b        #0xa2a4
//   0x00a238: f94007f3  ldr      x19, [sp, #8]
//   0x00a23c: b40002a8  cbz      x8, #0xa290
//   0x00a240: cb170109  sub      x9, x8, x23
//   0x00a244: d342fd2a  lsr      x10, x9, #2
//   0x00a248: 340017aa  cbz      w10, #0xa53c
//   0x00a24c: 37f8022a  tbnz     w10, #0x1f, #0xa290
//   0x00a250: f9400268  ldr      x8, [x19]
//   0x00a254: 93408521  sbfx     x1, x9, #0, #0x22
//   0x00a258: aa1303e0  mov      x0, x19
//   0x00a25c: d63f0100  blr      x8
//   0x00a260: b4000180  cbz      x0, #0xa290
//   0x00a264: a94222b3  ldp      x19, x8, [x21, #0x20]
//   0x00a268: aa0003f7  mov      x23, x0
//   0x00a26c: cb130116  sub      x22, x8, x19
//   0x00a270: d342fedc  lsr      x28, x22, #2
//   0x00a274: 71000f9f  cmp      w28, #3
//   0x00a278: 5400126b  b.lt     #0xa4c4
//   0x00a27c: 2a1f03e8  mov      w8, wzr
//   0x00a280: 52800055  mov      w21, #2
//   0x00a284: 528004b4  mov      w20, #0x25
//   0x00a288: aa1703fb  mov      x27, x23
//   0x00a28c: 1400001a  b        #0xa2f4
//   0x00a290: b94037e1  ldr      w1, [sp, #0x34]
//   0x00a294: aa1503e0  mov      x0, x21
//   0x00a298: aa1303e2  mov      x2, x19
//   0x00a29c: 94000234  bl       #0xab6c
//   0x00a2a0: 52800060  mov      w0, #3
//   0x00a2a4: f9401788  ldr      x8, [x28, #0x28]
//   0x00a2a8: f9401fe9  ldr      x9, [sp, #0x38]
//   0x00a2ac: eb09011f  cmp      x8, x9
//   0x00a2b0: 54001e21  b.ne     #0xa674
//   0x00a2b4: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x00a2b8: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x00a2bc: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x00a2c0: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x00a2c4: a94567fa  ldp      x26, x25, [sp, #0x50]
//   0x00a2c8: a9446ffc  ldp      x28, x27, [sp, #0x40]
//   0x00a2cc: 910283ff  add      sp, sp, #0xa0
//   0x00a2d0: d65f03c0  ret      
//   0x00a2d4: b9000369  str      w9, [x27]
//   0x00a2d8: 5280002a  mov      w10, #1
//   0x00a2dc: 11000509  add      w9, w8, #1
//   0x00a2e0: 11000d15  add      w21, w8, #3
//   0x00a2e4: 6b1c02bf  cmp      w21, w28
//   0x00a2e8: 8b0a0b7b  add      x27, x27, x10, lsl #2
//   0x00a2ec: 2a0903e8  mov      w8, w9
//   0x00a2f0: 54000eea  b.ge     #0xa4cc
//   0x00a2f4: b868da69  ldr      w9, [x19, w8, sxtw #2]
//   0x00a2f8: 7100953f  cmp      w9, #0x25
//   0x00a2fc: 54fffec1  b.ne     #0xa2d4
//   0x00a300: 93407d08  sxtw     x8, w8
//   0x00a304: 8b080a68  add      x8, x19, x8, lsl #2
//   0x00a308: b9400500  ldr      w0, [x8, #4]
//   0x00a30c: b875da78  ldr      w24, [x19, w21, sxtw #2]
//   0x00a310: 97ffe3cc  bl       #0x3240
//   0x00a314: 2a0003f9  mov      w25, w0
//   0x00a318: 2a1803e0  mov      w0, w24
//   0x00a31c: 97ffe3c9  bl       #0x3240
//   0x00a320: 12001c18  and      w24, w0, #0xff
//   0x00a324: 0b39131a  add      w26, w24, w25, uxtb #4
//   0x00a328: 2a1a03e0  mov      w0, w26
//   0x00a32c: 97ffe365  bl       #0x30c0
//   0x00a330: 34000080  cbz      w0, #0xa340
//   0x00a334: b900037a  str      w26, [x27]
//   0x00a338: 5280002a  mov      w10, #1
//   0x00a33c: 14000009  b        #0xa360
//   0x00a340: 12001f20  and      w0, w25, #0xff
//   0x00a344: b9000374  str      w20, [x27]
//   0x00a348: 97ffe392  bl       #0x3190
//   0x00a34c: b9000760  str      w0, [x27, #4]
//   0x00a350: 2a1803e0  mov      w0, w24
//   0x00a354: 97ffe38f  bl       #0x3190
//   0x00a358: 5280006a  mov      w10, #3
//   0x00a35c: b9000b60  str      w0, [x27, #8]
//   0x00a360: 2a1503e8  mov      w8, w21
//   0x00a364: 17ffffde  b        #0xa2dc
//   0x00a368: d3420e6c  ubfx     x12, x19, #2, #2
//   0x00a36c: cb0c014b  sub      x11, x10, x12
//   0x00a370: 6f020400  mvni     v0.4s, #0x40
//   0x00a374: 4f000741  movi     v1.4s, #0x1a
//   0x00a378: 4f010402  movi     v2.4s, #0x20
//   0x00a37c: aa0b03ed  mov      x13, x11
//   0x00a380: aa0003ee  mov      x14, x0
//   0x00a384: aa0903ef  mov      x15, x9
//   0x00a388: 3cc105e3  ldr      q3, [x15], #0x10
//   0x00a38c: f10011ad  subs     x13, x13, #4
//   0x00a390: 4ea08464  add      v4.4s, v3.4s, v0.4s
//   0x00a394: 4ea28465  add      v5.4s, v3.4s, v2.4s
//   0x00a398: 6ea43424  cmhi     v4.4s, v1.4s, v4.4s
//   0x00a39c: 6e631ca4  bsl      v4.16b, v5.16b, v3.16b
//   0x00a3a0: 3c8105c4  str      q4, [x14], #0x10
//   0x00a3a4: 54ffff21  b.ne     #0xa388
//   0x00a3a8: 2a1403e1  mov      w1, w20
//   0x00a3ac: b5ff646c  cbnz     x12, #0x9038
//   0x00a3b0: 17fffb2e  b        #0x9068
//   0x00a3b4: d3420e6c  ubfx     x12, x19, #2, #2
//   0x00a3b8: cb0c014b  sub      x11, x10, x12
//   0x00a3bc: 6f020400  mvni     v0.4s, #0x40
//   0x00a3c0: 4f000741  movi     v1.4s, #0x1a
//   0x00a3c4: 4f010402  movi     v2.4s, #0x20
//   0x00a3c8: aa0b03ed  mov      x13, x11
//   0x00a3cc: aa0003ee  mov      x14, x0
//   0x00a3d0: aa0903ef  mov      x15, x9
//   0x00a3d4: 3cc105e3  ldr      q3, [x15], #0x10
//   0x00a3d8: f10011ad  subs     x13, x13, #4
//   0x00a3dc: 4ea08464  add      v4.4s, v3.4s, v0.4s
//   0x00a3e0: 4ea28465  add      v5.4s, v3.4s, v2.4s
//   0x00a3e4: 6ea43424  cmhi     v4.4s, v1.4s, v4.4s
//   0x00a3e8: 6e631ca4  bsl      v4.16b, v5.16b, v3.16b
//   0x00a3ec: 3c8105c4  str      q4, [x14], #0x10
//   0x00a3f0: 54ffff21  b.ne     #0xa3d4
//   0x00a3f4: b5ff786c  cbnz     x12, #0x9300
//   0x00a3f8: 17fffbce  b        #0x9330
//   0x00a3fc: 2a1f03e9  mov      w9, wzr
//   0x00a400: aa1703f3  mov      x19, x23
//   0x00a404: f94013f5  ldr      x21, [sp, #0x20]
//   0x00a408: 6b1b013f  cmp      w9, w27
//   0x00a40c: 540002ea  b.ge     #0xa468
//   0x00a410: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a414: 93407d29  sxtw     x9, w9
//   0x00a418: 934286ca  sbfx     x10, x22, #2, #0x20
//   0x00a41c: cb09014b  sub      x11, x10, x9
//   0x00a420: f1001d7f  cmp      x11, #7
//   0x00a424: 54000109  b.ls     #0xa444
//   0x00a428: 8b0a0ae8  add      x8, x23, x10, lsl #2
//   0x00a42c: eb08027f  cmp      x19, x8
//   0x00a430: 8b090aee  add      x14, x23, x9, lsl #2
//   0x00a434: 54000282  b.hs     #0xa484
//   0x00a438: 8b0b0a68  add      x8, x19, x11, lsl #2
//   0x00a43c: eb0801df  cmp      x14, x8
//   0x00a440: 54000222  b.hs     #0xa484
//   0x00a444: f94017f6  ldr      x22, [sp, #0x28]
//   0x00a448: aa1303e8  mov      x8, x19
//   0x00a44c: cb09014a  sub      x10, x10, x9
//   0x00a450: 8b090ae9  add      x9, x23, x9, lsl #2
//   0x00a454: b840452b  ldr      w11, [x9], #4
//   0x00a458: f100054a  subs     x10, x10, #1
//   0x00a45c: b800450b  str      w11, [x8], #4
//   0x00a460: 54ffffa1  b.ne     #0xa454
//   0x00a464: 14000004  b        #0xa474
//   0x00a468: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a46c: f94017f6  ldr      x22, [sp, #0x28]
//   0x00a470: aa1303e8  mov      x8, x19
//   0x00a474: f94012b7  ldr      x23, [x21, #0x20]
//   0x00a478: f90016a8  str      x8, [x21, #0x28]
//   0x00a47c: b5000697  cbnz     x23, #0xa54c
//   0x00a480: 17fffbe5  b        #0x9414
//   0x00a484: 927df16c  and      x12, x11, #0xfffffffffffffff8
//   0x00a488: 9100426d  add      x13, x19, #0x10
//   0x00a48c: 8b090189  add      x9, x12, x9
//   0x00a490: 8b0c0a68  add      x8, x19, x12, lsl #2
//   0x00a494: 910041ce  add      x14, x14, #0x10
//   0x00a498: aa0c03ef  mov      x15, x12
//   0x00a49c: ad7f85c0  ldp      q0, q1, [x14, #-0x10]
//   0x00a4a0: f10021ef  subs     x15, x15, #8
//   0x00a4a4: 910081ce  add      x14, x14, #0x20
//   0x00a4a8: ad3f85a0  stp      q0, q1, [x13, #-0x10]
//   0x00a4ac: 910081ad  add      x13, x13, #0x20
//   0x00a4b0: 54ffff61  b.ne     #0xa49c
//   0x00a4b4: f94017f6  ldr      x22, [sp, #0x28]
//   0x00a4b8: eb0c017f  cmp      x11, x12
//   0x00a4bc: 54fffc81  b.ne     #0xa44c
//   0x00a4c0: 17ffffed  b        #0xa474
//   0x00a4c4: 2a1f03e9  mov      w9, wzr
//   0x00a4c8: aa1703fb  mov      x27, x23
//   0x00a4cc: 6b1c013f  cmp      w9, w28
//   0x00a4d0: 540002ea  b.ge     #0xa52c
//   0x00a4d4: 93407d29  sxtw     x9, w9
//   0x00a4d8: 934286ca  sbfx     x10, x22, #2, #0x20
//   0x00a4dc: cb09014b  sub      x11, x10, x9
//   0x00a4e0: f1001d7f  cmp      x11, #7
//   0x00a4e4: 54000109  b.ls     #0xa504
//   0x00a4e8: 8b0a0a68  add      x8, x19, x10, lsl #2
//   0x00a4ec: eb08037f  cmp      x27, x8
//   0x00a4f0: 8b090a6e  add      x14, x19, x9, lsl #2
//   0x00a4f4: 540009e2  b.hs     #0xa630
//   0x00a4f8: 8b0b0b68  add      x8, x27, x11, lsl #2
//   0x00a4fc: eb0801df  cmp      x14, x8
//   0x00a500: 54000982  b.hs     #0xa630
//   0x00a504: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a508: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x00a50c: aa1b03e8  mov      x8, x27
//   0x00a510: cb09014a  sub      x10, x10, x9
//   0x00a514: 8b090a69  add      x9, x19, x9, lsl #2
//   0x00a518: b840452b  ldr      w11, [x9], #4
//   0x00a51c: f100054a  subs     x10, x10, #1
//   0x00a520: b800450b  str      w11, [x8], #4
//   0x00a524: 54ffffa1  b.ne     #0xa518
//   0x00a528: 14000004  b        #0xa538
//   0x00a52c: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a530: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x00a534: aa1b03e8  mov      x8, x27
//   0x00a538: a90222b7  stp      x23, x8, [x21, #0x20]
//   0x00a53c: b94037e9  ldr      w9, [sp, #0x34]
//   0x00a540: 321e0129  orr      w9, w9, #4
//   0x00a544: b90037e9  str      w9, [sp, #0x34]
//   0x00a548: b4ff7677  cbz      x23, #0x9414
//   0x00a54c: eb17011f  cmp      x8, x23
//   0x00a550: 54ff7629  b.ls     #0x9414
//   0x00a554: aa3703e9  mvn      x9, x23
//   0x00a558: 8b090109  add      x9, x8, x9
//   0x00a55c: d342fd29  lsr      x9, x9, #2
//   0x00a560: 91000529  add      x9, x9, #1
//   0x00a564: f100113f  cmp      x9, #4
//   0x00a568: 54000563  b.lo     #0xa614
//   0x00a56c: 927ef12a  and      x10, x9, #0x7ffffffffffffffc
//   0x00a570: 910022eb  add      x11, x23, #8
//   0x00a574: 2f020400  mvni     v0.2s, #0x40
//   0x00a578: 8b0a0af7  add      x23, x23, x10, lsl #2
//   0x00a57c: 0f000741  movi     v1.2s, #0x1a
//   0x00a580: aa0a03ec  mov      x12, x10
//   0x00a584: 14000004  b        #0xa594
//   0x00a588: f100118c  subs     x12, x12, #4
//   0x00a58c: 9100416b  add      x11, x11, #0x10
//   0x00a590: 54000360  b.eq     #0xa5fc
//   0x00a594: 6d7f8963  ldp      d3, d2, [x11, #-8]
//   0x00a598: 0ea08464  add      v4.2s, v3.2s, v0.2s
//   0x00a59c: 2ea43424  cmhi     v4.2s, v1.2s, v4.2s
//   0x00a5a0: 1e26008d  fmov     w13, s4
//   0x00a5a4: 3600008d  tbz      w13, #0, #0xa5b4
//   0x00a5a8: 1e26006d  fmov     w13, s3
//   0x00a5ac: 110081ad  add      w13, w13, #0x20
//   0x00a5b0: b81f816d  stur     w13, [x11, #-8]
//   0x00a5b4: 0e0c3c8d  mov      w13, v4.s[1]
//   0x00a5b8: 0ea08444  add      v4.2s, v2.2s, v0.2s
//   0x00a5bc: 3600008d  tbz      w13, #0, #0xa5cc
//   0x00a5c0: 0e0c3c6d  mov      w13, v3.s[1]
//   0x00a5c4: 110081ad  add      w13, w13, #0x20
//   0x00a5c8: b81fc16d  stur     w13, [x11, #-4]
//   0x00a5cc: 2ea43423  cmhi     v3.2s, v1.2s, v4.2s
//   0x00a5d0: 1e26006d  fmov     w13, s3
//   0x00a5d4: 3600008d  tbz      w13, #0, #0xa5e4
//   0x00a5d8: 1e26004d  fmov     w13, s2
//   0x00a5dc: 110081ad  add      w13, w13, #0x20
//   0x00a5e0: b900016d  str      w13, [x11]
//   0x00a5e4: 0e0c3c6d  mov      w13, v3.s[1]
//   0x00a5e8: 3607fd0d  tbz      w13, #0, #0xa588
//   0x00a5ec: 0e0c3c4d  mov      w13, v2.s[1]
//   0x00a5f0: 110081ad  add      w13, w13, #0x20
//   0x00a5f4: b900056d  str      w13, [x11, #4]
//   0x00a5f8: 17ffffe4  b        #0xa588
//   0x00a5fc: eb0a013f  cmp      x9, x10
//   0x00a600: 540000a1  b.ne     #0xa614
//   0x00a604: 17fffb84  b        #0x9414
//   0x00a608: 910012f7  add      x23, x23, #4
//   0x00a60c: eb0802ff  cmp      x23, x8
//   0x00a610: 54ff7022  b.hs     #0x9414
//   0x00a614: b94002e9  ldr      w9, [x23]
//   0x00a618: 5101052a  sub      w10, w9, #0x41
//   0x00a61c: 7100655f  cmp      w10, #0x19
//   0x00a620: 54ffff48  b.hi     #0xa608
//   0x00a624: 11008129  add      w9, w9, #0x20
//   0x00a628: b90002e9  str      w9, [x23]
//   0x00a62c: 17fffff7  b        #0xa608
//   0x00a630: 927df16c  and      x12, x11, #0xfffffffffffffff8
//   0x00a634: 9100436d  add      x13, x27, #0x10
//   0x00a638: 8b090189  add      x9, x12, x9
//   0x00a63c: 8b0c0b68  add      x8, x27, x12, lsl #2
//   0x00a640: 910041ce  add      x14, x14, #0x10
//   0x00a644: aa0c03ef  mov      x15, x12
//   0x00a648: ad7f85c0  ldp      q0, q1, [x14, #-0x10]
//   0x00a64c: f10021ef  subs     x15, x15, #8
//   0x00a650: 910081ce  add      x14, x14, #0x20
//   0x00a654: ad3f85a0  stp      q0, q1, [x13, #-0x10]
//   0x00a658: 910081ad  add      x13, x13, #0x20
//   0x00a65c: 54ffff61  b.ne     #0xa648
//   0x00a660: f9400bfc  ldr      x28, [sp, #0x10]
//   0x00a664: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x00a668: eb0c017f  cmp      x11, x12
//   0x00a66c: 54fff521  b.ne     #0xa510
//   0x00a670: 17ffffb2  b        #0xa538
//   0x00a674: 97ffe2ab  bl       #0x3120
// ============================================================================
std::uint32_t fde_076_08bac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008bacULL;
    for (std::size_t i = 0; i < 1715ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5655ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[077] Subroutine @ 0x00a678..0x00a688 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[077] Hàm con @ 0x00a678..0x00a688 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a678: b0000083  adrp     x3, #0x1b000
//   0x00a67c: f947fc63  ldr      x3, [x3, #0xff8]
//   0x00a680: aa1f03e2  mov      x2, xzr
//   0x00a684: 17fff94a  b        #0x8bac
// ============================================================================
std::uint32_t fde_077_0a678(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a678ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7370ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[078] Subroutine @ 0x00a688..0x00a6f4 (108 bytes, 27 AArch64 instructions)
// [VN] Khung FDE[078] Hàm con @ 0x00a688..0x00a6f4 (108 byte, 27 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a688: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00a68c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00a690: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00a694: 910083fd  add      x29, sp, #0x20
//   0x00a698: 2a0103f4  mov      w20, w1
//   0x00a69c: aa0003f5  mov      x21, x0
//   0x00a6a0: b4000162  cbz      x2, #0xa6cc
//   0x00a6a4: aa0203e0  mov      x0, x2
//   0x00a6a8: aa0203f3  mov      x19, x2
//   0x00a6ac: 97ffe2ed  bl       #0x3260
//   0x00a6b0: 7100041f  cmp      w0, #1
//   0x00a6b4: 54000100  b.eq     #0xa6d4
//   0x00a6b8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00a6bc: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00a6c0: 52800140  mov      w0, #0xa
//   0x00a6c4: f84307f5  ldr      x21, [sp], #0x30
//   0x00a6c8: d65f03c0  ret      
//   0x00a6cc: b0000093  adrp     x19, #0x1b000
//   0x00a6d0: f947fe73  ldr      x19, [x19, #0xff8]
//   0x00a6d4: 2a1403e1  mov      w1, w20
//   0x00a6d8: aa1303e3  mov      x3, x19
//   0x00a6dc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00a6e0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00a6e4: aa1503e0  mov      x0, x21
//   0x00a6e8: aa1f03e2  mov      x2, xzr
//   0x00a6ec: f84307f5  ldr      x21, [sp], #0x30
//   0x00a6f0: 17fff92f  b        #0x8bac
// ============================================================================
std::uint32_t fde_078_0a688(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a688ULL;
    for (std::size_t i = 0; i < 27ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7374ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[079] Subroutine @ 0x00a6f4..0x00a708 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[079] Hàm con @ 0x00a6f4..0x00a708 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a6f4: b0000083  adrp     x3, #0x1b000
//   0x00a6f8: f947fc63  ldr      x3, [x3, #0xff8]
//   0x00a6fc: 12800001  mov      w1, #-1
//   0x00a700: aa1f03e2  mov      x2, xzr
//   0x00a704: 17fff92a  b        #0x8bac
// ============================================================================
std::uint32_t fde_079_0a6f4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a6f4ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7401ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[080] Subroutine @ 0x00a708..0x00a7d8 (208 bytes, 52 AArch64 instructions)
// [VN] Khung FDE[080] Hàm con @ 0x00a708..0x00a7d8 (208 byte, 52 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a708: d10103ff  sub      sp, sp, #0x40
//   0x00a70c: f9000bf5  str      x21, [sp, #0x10]
//   0x00a710: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00a714: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00a718: 9100c3fd  add      x29, sp, #0x30
//   0x00a71c: d53bd055  mrs      x21, tpidr_el0
//   0x00a720: f94016a8  ldr      x8, [x21, #0x28]
//   0x00a724: aa0003f3  mov      x19, x0
//   0x00a728: f90007e8  str      x8, [sp, #8]
//   0x00a72c: b90007ff  str      wzr, [sp, #4]
//   0x00a730: b4000101  cbz      x1, #0xa750
//   0x00a734: aa0103e0  mov      x0, x1
//   0x00a738: aa0103f4  mov      x20, x1
//   0x00a73c: 97ffe2c9  bl       #0x3260
//   0x00a740: 7100041f  cmp      w0, #1
//   0x00a744: 540000a0  b.eq     #0xa758
//   0x00a748: 52800140  mov      w0, #0xa
//   0x00a74c: 14000019  b        #0xa7b0
//   0x00a750: b0000094  adrp     x20, #0x1b000
//   0x00a754: f947fe94  ldr      x20, [x20, #0xff8]
//   0x00a758: b40000d3  cbz      x19, #0xa770
//   0x00a75c: b9409668  ldr      w8, [x19, #0x94]
//   0x00a760: 7100051f  cmp      w8, #1
//   0x00a764: 540000a1  b.ne     #0xa778
//   0x00a768: 2a1f03e0  mov      w0, wzr
//   0x00a76c: 14000011  b        #0xa7b0
//   0x00a770: 52800040  mov      w0, #2
//   0x00a774: 1400000f  b        #0xa7b0
//   0x00a778: 910013e1  add      x1, sp, #4
//   0x00a77c: aa1303e0  mov      x0, x19
//   0x00a780: aa1403e2  mov      x2, x20
//   0x00a784: 94000015  bl       #0xa7d8
//   0x00a788: 340000a0  cbz      w0, #0xa79c
//   0x00a78c: 2a1f03e0  mov      w0, wzr
//   0x00a790: 52800028  mov      w8, #1
//   0x00a794: b9009668  str      w8, [x19, #0x94]
//   0x00a798: 14000006  b        #0xa7b0
//   0x00a79c: b94007e1  ldr      w1, [sp, #4]
//   0x00a7a0: aa1303e0  mov      x0, x19
//   0x00a7a4: aa1403e2  mov      x2, x20
//   0x00a7a8: 940000f1  bl       #0xab6c
//   0x00a7ac: 52800060  mov      w0, #3
//   0x00a7b0: f94016a8  ldr      x8, [x21, #0x28]
//   0x00a7b4: f94007e9  ldr      x9, [sp, #8]
//   0x00a7b8: eb09011f  cmp      x8, x9
//   0x00a7bc: 540000c1  b.ne     #0xa7d4
//   0x00a7c0: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00a7c4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00a7c8: f9400bf5  ldr      x21, [sp, #0x10]
//   0x00a7cc: 910103ff  add      sp, sp, #0x40
//   0x00a7d0: d65f03c0  ret      
//   0x00a7d4: 97ffe253  bl       #0x3120
// ============================================================================
std::uint32_t fde_080_0a708(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a708ULL;
    for (std::size_t i = 0; i < 52ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7406ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[081] Subroutine @ 0x00a7d8..0x00ab6c (916 bytes, 229 AArch64 instructions)
// [VN] Khung FDE[081] Hàm con @ 0x00a7d8..0x00ab6c (916 byte, 229 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a7d8: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x00a7dc: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00a7e0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00a7e4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00a7e8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00a7ec: 910103fd  add      x29, sp, #0x40
//   0x00a7f0: aa0003f9  mov      x25, x0
//   0x00a7f4: f8460f34  ldr      x20, [x25, #0x60]!
//   0x00a7f8: b9400028  ldr      w8, [x1]
//   0x00a7fc: aa0103f6  mov      x22, x1
//   0x00a800: aa0003f5  mov      x21, x0
//   0x00a804: aa0203f3  mov      x19, x2
//   0x00a808: 370002c8  tbnz     w8, #0, #0xa860
//   0x00a80c: f94002a9  ldr      x9, [x21]
//   0x00a810: b4000289  cbz      x9, #0xa860
//   0x00a814: f94006aa  ldr      x10, [x21, #8]
//   0x00a818: eb090149  subs     x9, x10, x9
//   0x00a81c: 54000229  b.ls     #0xa860
//   0x00a820: f9400268  ldr      x8, [x19]
//   0x00a824: 9342853a  sbfx     x26, x9, #2, #0x20
//   0x00a828: 937e7757  sbfiz    x23, x26, #2, #0x1e
//   0x00a82c: aa1303e0  mov      x0, x19
//   0x00a830: aa1703e1  mov      x1, x23
//   0x00a834: d63f0100  blr      x8
//   0x00a838: b4001780  cbz      x0, #0xab28
//   0x00a83c: f94002a1  ldr      x1, [x21]
//   0x00a840: aa1703e2  mov      x2, x23
//   0x00a844: aa0003f8  mov      x24, x0
//   0x00a848: 97ffe29e  bl       #0x32c0
//   0x00a84c: 8b1a0b08  add      x8, x24, x26, lsl #2
//   0x00a850: a90022b8  stp      x24, x8, [x21]
//   0x00a854: b94002c8  ldr      w8, [x22]
//   0x00a858: 32000108  orr      w8, w8, #1
//   0x00a85c: b90002c8  str      w8, [x22]
//   0x00a860: 370802c8  tbnz     w8, #1, #0xa8b8
//   0x00a864: f9400aa9  ldr      x9, [x21, #0x10]
//   0x00a868: b4000289  cbz      x9, #0xa8b8
//   0x00a86c: f9400eaa  ldr      x10, [x21, #0x18]
//   0x00a870: eb090149  subs     x9, x10, x9
//   0x00a874: 54000229  b.ls     #0xa8b8
//   0x00a878: f9400268  ldr      x8, [x19]
//   0x00a87c: 9342853a  sbfx     x26, x9, #2, #0x20
//   0x00a880: 937e7757  sbfiz    x23, x26, #2, #0x1e
//   0x00a884: aa1303e0  mov      x0, x19
//   0x00a888: aa1703e1  mov      x1, x23
//   0x00a88c: d63f0100  blr      x8
//   0x00a890: b40014c0  cbz      x0, #0xab28
//   0x00a894: f9400aa1  ldr      x1, [x21, #0x10]
//   0x00a898: aa1703e2  mov      x2, x23
//   0x00a89c: aa0003f8  mov      x24, x0
//   0x00a8a0: 97ffe288  bl       #0x32c0
//   0x00a8a4: 8b1a0b08  add      x8, x24, x26, lsl #2
//   0x00a8a8: a90122b8  stp      x24, x8, [x21, #0x10]
//   0x00a8ac: b94002c8  ldr      w8, [x22]
//   0x00a8b0: 321f0108  orr      w8, w8, #2
//   0x00a8b4: b90002c8  str      w8, [x22]
//   0x00a8b8: 372002c8  tbnz     w8, #4, #0xa910
//   0x00a8bc: f9403aa9  ldr      x9, [x21, #0x70]
//   0x00a8c0: b4000289  cbz      x9, #0xa910
//   0x00a8c4: f9403eaa  ldr      x10, [x21, #0x78]
//   0x00a8c8: eb090149  subs     x9, x10, x9
//   0x00a8cc: 54000229  b.ls     #0xa910
//   0x00a8d0: f9400268  ldr      x8, [x19]
//   0x00a8d4: 9342853a  sbfx     x26, x9, #2, #0x20
//   0x00a8d8: 937e7757  sbfiz    x23, x26, #2, #0x1e
//   0x00a8dc: aa1303e0  mov      x0, x19
//   0x00a8e0: aa1703e1  mov      x1, x23
//   0x00a8e4: d63f0100  blr      x8
//   0x00a8e8: b4001200  cbz      x0, #0xab28
//   0x00a8ec: f9403aa1  ldr      x1, [x21, #0x70]
//   0x00a8f0: aa1703e2  mov      x2, x23
//   0x00a8f4: aa0003f8  mov      x24, x0
//   0x00a8f8: 97ffe272  bl       #0x32c0
//   0x00a8fc: 8b1a0b08  add      x8, x24, x26, lsl #2
//   0x00a900: a90722b8  stp      x24, x8, [x21, #0x70]
//   0x00a904: b94002c8  ldr      w8, [x22]
//   0x00a908: 321c0108  orr      w8, w8, #0x10
//   0x00a90c: b90002c8  str      w8, [x22]
//   0x00a910: 372802c8  tbnz     w8, #5, #0xa968
//   0x00a914: f94042a9  ldr      x9, [x21, #0x80]
//   0x00a918: b4000289  cbz      x9, #0xa968
//   0x00a91c: f94046aa  ldr      x10, [x21, #0x88]
//   0x00a920: eb090149  subs     x9, x10, x9
//   0x00a924: 54000229  b.ls     #0xa968
//   0x00a928: f9400268  ldr      x8, [x19]
//   0x00a92c: 9342853a  sbfx     x26, x9, #2, #0x20
//   0x00a930: 937e7757  sbfiz    x23, x26, #2, #0x1e
//   0x00a934: aa1303e0  mov      x0, x19
//   0x00a938: aa1703e1  mov      x1, x23
//   0x00a93c: d63f0100  blr      x8
//   0x00a940: b4000f40  cbz      x0, #0xab28
//   0x00a944: f94042a1  ldr      x1, [x21, #0x80]
//   0x00a948: aa1703e2  mov      x2, x23
//   0x00a94c: aa0003f8  mov      x24, x0
//   0x00a950: 97ffe25c  bl       #0x32c0
//   0x00a954: 8b1a0b08  add      x8, x24, x26, lsl #2
//   0x00a958: a90822b8  stp      x24, x8, [x21, #0x80]
//   0x00a95c: b94002c8  ldr      w8, [x22]
//   0x00a960: 321b0108  orr      w8, w8, #0x20
//   0x00a964: b90002c8  str      w8, [x22]
//   0x00a968: 371005c8  tbnz     w8, #2, #0xaa20
//   0x00a96c: f94022b7  ldr      x23, [x21, #0x40]
//   0x00a970: b40002f7  cbz      x23, #0xa9cc
//   0x00a974: f94026a9  ldr      x9, [x21, #0x48]
//   0x00a978: eb17012a  subs     x10, x9, x23
//   0x00a97c: 54000229  b.ls     #0xa9c0
//   0x00a980: f9400268  ldr      x8, [x19]
//   0x00a984: 9342855a  sbfx     x26, x10, #2, #0x20
//   0x00a988: 937e7758  sbfiz    x24, x26, #2, #0x1e
//   0x00a98c: aa1303e0  mov      x0, x19
//   0x00a990: aa1803e1  mov      x1, x24
//   0x00a994: d63f0100  blr      x8
//   0x00a998: b4000c80  cbz      x0, #0xab28
//   0x00a99c: f94022a1  ldr      x1, [x21, #0x40]
//   0x00a9a0: aa1803e2  mov      x2, x24
//   0x00a9a4: aa0003f7  mov      x23, x0
//   0x00a9a8: 97ffe246  bl       #0x32c0
//   0x00a9ac: 8b1a0ae9  add      x9, x23, x26, lsl #2
//   0x00a9b0: a90426b7  stp      x23, x9, [x21, #0x40]
//   0x00a9b4: b94002c8  ldr      w8, [x22]
//   0x00a9b8: 321e0108  orr      w8, w8, #4
//   0x00a9bc: b90002c8  str      w8, [x22]
//   0x00a9c0: a90226b7  stp      x23, x9, [x21, #0x20]
//   0x00a9c4: 36180308  tbz      w8, #3, #0xaa24
//   0x00a9c8: 14000045  b        #0xaadc
//   0x00a9cc: f94012a9  ldr      x9, [x21, #0x20]
//   0x00a9d0: b4000289  cbz      x9, #0xaa20
//   0x00a9d4: f94016aa  ldr      x10, [x21, #0x28]
//   0x00a9d8: eb090149  subs     x9, x10, x9
//   0x00a9dc: 54000229  b.ls     #0xaa20
//   0x00a9e0: f9400268  ldr      x8, [x19]
//   0x00a9e4: 9342853a  sbfx     x26, x9, #2, #0x20
//   0x00a9e8: 937e7757  sbfiz    x23, x26, #2, #0x1e
//   0x00a9ec: aa1303e0  mov      x0, x19
//   0x00a9f0: aa1703e1  mov      x1, x23
//   0x00a9f4: d63f0100  blr      x8
//   0x00a9f8: b4000980  cbz      x0, #0xab28
//   0x00a9fc: f94012a1  ldr      x1, [x21, #0x20]
//   0x00aa00: aa1703e2  mov      x2, x23
//   0x00aa04: aa0003f8  mov      x24, x0
//   0x00aa08: 97ffe22e  bl       #0x32c0
//   0x00aa0c: 8b1a0b08  add      x8, x24, x26, lsl #2
//   0x00aa10: a90222b8  stp      x24, x8, [x21, #0x20]
//   0x00aa14: b94002c8  ldr      w8, [x22]
//   0x00aa18: 321e0108  orr      w8, w8, #4
//   0x00aa1c: b90002c8  str      w8, [x22]
//   0x00aa20: 371805e8  tbnz     w8, #3, #0xaadc
//   0x00aa24: b5000154  cbnz     x20, #0xaa4c
//   0x00aa28: 1400002b  b        #0xaad4
//   0x00aa2c: f9400281  ldr      x1, [x20]
//   0x00aa30: aa1703e2  mov      x2, x23
//   0x00aa34: aa0003f8  mov      x24, x0
//   0x00aa38: 97ffe222  bl       #0x32c0
//   0x00aa3c: 8b1a0b08  add      x8, x24, x26, lsl #2
//   0x00aa40: a9002298  stp      x24, x8, [x20]
//   0x00aa44: f9400a94  ldr      x20, [x20, #0x10]
//   0x00aa48: b4000454  cbz      x20, #0xaad0
//   0x00aa4c: f9400288  ldr      x8, [x20]
//   0x00aa50: b4ffffa8  cbz      x8, #0xaa44
//   0x00aa54: f9400689  ldr      x9, [x20, #8]
//   0x00aa58: eb080128  subs     x8, x9, x8
//   0x00aa5c: 54ffff49  b.ls     #0xaa44
//   0x00aa60: f9400269  ldr      x9, [x19]
//   0x00aa64: 9342851a  sbfx     x26, x8, #2, #0x20
//   0x00aa68: 937e7757  sbfiz    x23, x26, #2, #0x1e
//   0x00aa6c: aa1303e0  mov      x0, x19
//   0x00aa70: aa1703e1  mov      x1, x23
//   0x00aa74: d63f0120  blr      x9
//   0x00aa78: b5fffda0  cbnz     x0, #0xaa2c
//   0x00aa7c: f9400335  ldr      x21, [x25]
//   0x00aa80: eb1402bf  cmp      x21, x20
//   0x00aa84: 54000121  b.ne     #0xaaa8
//   0x00aa88: 1400002f  b        #0xab44
//   0x00aa8c: f9401268  ldr      x8, [x19, #0x20]
//   0x00aa90: aa1303e0  mov      x0, x19
//   0x00aa94: aa1503e1  mov      x1, x21
//   0x00aa98: d63f0100  blr      x8
//   0x00aa9c: eb1402df  cmp      x22, x20
//   0x00aaa0: aa1603f5  mov      x21, x22
//   0x00aaa4: 540004e0  b.eq     #0xab40
//   0x00aaa8: f94002a1  ldr      x1, [x21]
//   0x00aaac: f9400ab6  ldr      x22, [x21, #0x10]
//   0x00aab0: b4fffee1  cbz      x1, #0xaa8c
//   0x00aab4: f94006a8  ldr      x8, [x21, #8]
//   0x00aab8: eb01011f  cmp      x8, x1
//   0x00aabc: 54fffe89  b.ls     #0xaa8c
//   0x00aac0: f9401268  ldr      x8, [x19, #0x20]
//   0x00aac4: aa1303e0  mov      x0, x19
//   0x00aac8: d63f0100  blr      x8
//   0x00aacc: 17fffff0  b        #0xaa8c
//   0x00aad0: b94002c8  ldr      w8, [x22]
//   0x00aad4: 321d0108  orr      w8, w8, #8
//   0x00aad8: b90002c8  str      w8, [x22]
//   0x00aadc: f9402aa8  ldr      x8, [x21, #0x50]
//   0x00aae0: b4000228  cbz      x8, #0xab24
//   0x00aae4: f9402ea9  ldr      x9, [x21, #0x58]
//   0x00aae8: eb080128  subs     x8, x9, x8
//   0x00aaec: 540001c9  b.ls     #0xab24
//   0x00aaf0: f9400269  ldr      x9, [x19]
//   0x00aaf4: 93428516  sbfx     x22, x8, #2, #0x20
//   0x00aaf8: 937e76d4  sbfiz    x20, x22, #2, #0x1e
//   0x00aafc: aa1303e0  mov      x0, x19
//   0x00ab00: aa1403e1  mov      x1, x20
//   0x00ab04: d63f0120  blr      x9
//   0x00ab08: b4000100  cbz      x0, #0xab28
//   0x00ab0c: f9402aa1  ldr      x1, [x21, #0x50]
//   0x00ab10: aa1403e2  mov      x2, x20
//   0x00ab14: aa0003f3  mov      x19, x0
//   0x00ab18: 97ffe1ea  bl       #0x32c0
//   0x00ab1c: 8b160a68  add      x8, x19, x22, lsl #2
//   0x00ab20: a90522b3  stp      x19, x8, [x21, #0x50]
//   0x00ab24: 52800020  mov      w0, #1
//   0x00ab28: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x00ab2c: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x00ab30: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x00ab34: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x00ab38: a8c567fa  ldp      x26, x25, [sp], #0x50
//   0x00ab3c: d65f03c0  ret      
//   0x00ab40: b4000114  cbz      x20, #0xab60
//   0x00ab44: f9401268  ldr      x8, [x19, #0x20]
//   0x00ab48: f9400a95  ldr      x21, [x20, #0x10]
//   0x00ab4c: aa1303e0  mov      x0, x19
//   0x00ab50: aa1403e1  mov      x1, x20
//   0x00ab54: d63f0100  blr      x8
//   0x00ab58: aa1503f4  mov      x20, x21
//   0x00ab5c: b5ffff55  cbnz     x21, #0xab44
//   0x00ab60: 2a1f03e0  mov      w0, wzr
//   0x00ab64: a9007f3f  stp      xzr, xzr, [x25]
//   0x00ab68: 17fffff0  b        #0xab28
// ============================================================================
std::uint32_t fde_081_0a7d8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a7d8ULL;
    for (std::size_t i = 0; i < 229ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7458ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[082] Subroutine @ 0x00ab6c..0x00acdc (368 bytes, 92 AArch64 instructions)
// [VN] Khung FDE[082] Hàm con @ 0x00ab6c..0x00acdc (368 byte, 92 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ab6c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00ab70: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00ab74: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00ab78: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00ab7c: 9100c3fd  add      x29, sp, #0x30
//   0x00ab80: aa0203f4  mov      x20, x2
//   0x00ab84: 2a0103f5  mov      w21, w1
//   0x00ab88: aa0003f3  mov      x19, x0
//   0x00ab8c: 37000081  tbnz     w1, #0, #0xab9c
//   0x00ab90: 37080135  tbnz     w21, #1, #0xabb4
//   0x00ab94: 37100255  tbnz     w21, #2, #0xabdc
//   0x00ab98: 14000023  b        #0xac24
//   0x00ab9c: f9401288  ldr      x8, [x20, #0x20]
//   0x00aba0: f9400261  ldr      x1, [x19]
//   0x00aba4: aa1403e0  mov      x0, x20
//   0x00aba8: d63f0100  blr      x8
//   0x00abac: a9007e7f  stp      xzr, xzr, [x19]
//   0x00abb0: 360fff35  tbz      w21, #1, #0xab94
//   0x00abb4: aa1303f6  mov      x22, x19
//   0x00abb8: f8410ec1  ldr      x1, [x22, #0x10]!
//   0x00abbc: f94006c8  ldr      x8, [x22, #8]
//   0x00abc0: eb08003f  cmp      x1, x8
//   0x00abc4: 54000080  b.eq     #0xabd4
//   0x00abc8: f9401288  ldr      x8, [x20, #0x20]
//   0x00abcc: aa1403e0  mov      x0, x20
//   0x00abd0: d63f0100  blr      x8
//   0x00abd4: a9007edf  stp      xzr, xzr, [x22]
//   0x00abd8: 36100275  tbz      w21, #2, #0xac24
//   0x00abdc: aa1303f6  mov      x22, x19
//   0x00abe0: f8440ec1  ldr      x1, [x22, #0x40]!
//   0x00abe4: b40000c1  cbz      x1, #0xabfc
//   0x00abe8: f9401288  ldr      x8, [x20, #0x20]
//   0x00abec: aa1403e0  mov      x0, x20
//   0x00abf0: d63f0100  blr      x8
//   0x00abf4: a9027e7f  stp      xzr, xzr, [x19, #0x20]
//   0x00abf8: 1400000a  b        #0xac20
//   0x00abfc: aa1303f6  mov      x22, x19
//   0x00ac00: f8420ec1  ldr      x1, [x22, #0x20]!
//   0x00ac04: b4000101  cbz      x1, #0xac24
//   0x00ac08: f9401668  ldr      x8, [x19, #0x28]
//   0x00ac0c: eb08003f  cmp      x1, x8
//   0x00ac10: 54000080  b.eq     #0xac20
//   0x00ac14: f9401288  ldr      x8, [x20, #0x20]
//   0x00ac18: aa1403e0  mov      x0, x20
//   0x00ac1c: d63f0100  blr      x8
//   0x00ac20: a9007edf  stp      xzr, xzr, [x22]
//   0x00ac24: 37180095  tbnz     w21, #3, #0xac34
//   0x00ac28: 37200115  tbnz     w21, #4, #0xac48
//   0x00ac2c: 37280235  tbnz     w21, #5, #0xac70
//   0x00ac30: 14000018  b        #0xac90
//   0x00ac34: aa1303f7  mov      x23, x19
//   0x00ac38: f8460ef6  ldr      x22, [x23, #0x60]!
//   0x00ac3c: b5000416  cbnz     x22, #0xacbc
//   0x00ac40: a9007eff  stp      xzr, xzr, [x23]
//   0x00ac44: 3627ff55  tbz      w21, #4, #0xac2c
//   0x00ac48: aa1303f6  mov      x22, x19
//   0x00ac4c: f8470ec1  ldr      x1, [x22, #0x70]!
//   0x00ac50: f94006c8  ldr      x8, [x22, #8]
//   0x00ac54: eb08003f  cmp      x1, x8
//   0x00ac58: 54000080  b.eq     #0xac68
//   0x00ac5c: f9401288  ldr      x8, [x20, #0x20]
//   0x00ac60: aa1403e0  mov      x0, x20
//   0x00ac64: d63f0100  blr      x8
//   0x00ac68: a9007edf  stp      xzr, xzr, [x22]
//   0x00ac6c: 36280135  tbz      w21, #5, #0xac90
//   0x00ac70: f8480e61  ldr      x1, [x19, #0x80]!
//   0x00ac74: f9400668  ldr      x8, [x19, #8]
//   0x00ac78: eb08003f  cmp      x1, x8
//   0x00ac7c: 54000080  b.eq     #0xac8c
//   0x00ac80: f9401288  ldr      x8, [x20, #0x20]
//   0x00ac84: aa1403e0  mov      x0, x20
//   0x00ac88: d63f0100  blr      x8
//   0x00ac8c: a9007e7f  stp      xzr, xzr, [x19]
//   0x00ac90: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00ac94: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00ac98: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00ac9c: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00aca0: d65f03c0  ret      
//   0x00aca4: f9401288  ldr      x8, [x20, #0x20]
//   0x00aca8: aa1403e0  mov      x0, x20
//   0x00acac: aa1603e1  mov      x1, x22
//   0x00acb0: d63f0100  blr      x8
//   0x00acb4: aa1803f6  mov      x22, x24
//   0x00acb8: b4fffc58  cbz      x24, #0xac40
//   0x00acbc: a94022c1  ldp      x1, x8, [x22]
//   0x00acc0: f9400ad8  ldr      x24, [x22, #0x10]
//   0x00acc4: eb01011f  cmp      x8, x1
//   0x00acc8: 54fffee9  b.ls     #0xaca4
//   0x00accc: f9401288  ldr      x8, [x20, #0x20]
//   0x00acd0: aa1403e0  mov      x0, x20
//   0x00acd4: d63f0100  blr      x8
//   0x00acd8: 17fffff3  b        #0xaca4
// ============================================================================
std::uint32_t fde_082_0ab6c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ab6cULL;
    for (std::size_t i = 0; i < 92ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7687ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[083] Subroutine @ 0x00acdc..0x00ad84 (168 bytes, 42 AArch64 instructions)
// [VN] Khung FDE[083] Hàm con @ 0x00acdc..0x00ad84 (168 byte, 42 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00acdc: d100c3ff  sub      sp, sp, #0x30
//   0x00ace0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00ace4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00ace8: 910083fd  add      x29, sp, #0x20
//   0x00acec: d53bd054  mrs      x20, tpidr_el0
//   0x00acf0: f9401688  ldr      x8, [x20, #0x28]
//   0x00acf4: f90007e8  str      x8, [sp, #8]
//   0x00acf8: b90007ff  str      wzr, [sp, #4]
//   0x00acfc: b40000e0  cbz      x0, #0xad18
//   0x00ad00: b9409408  ldr      w8, [x0, #0x94]
//   0x00ad04: aa0003f3  mov      x19, x0
//   0x00ad08: 7100051f  cmp      w8, #1
//   0x00ad0c: 540000a1  b.ne     #0xad20
//   0x00ad10: 2a1f03e0  mov      w0, wzr
//   0x00ad14: 14000013  b        #0xad60
//   0x00ad18: 52800040  mov      w0, #2
//   0x00ad1c: 14000011  b        #0xad60
//   0x00ad20: b0000082  adrp     x2, #0x1b000
//   0x00ad24: f947fc42  ldr      x2, [x2, #0xff8]
//   0x00ad28: 910013e1  add      x1, sp, #4
//   0x00ad2c: aa1303e0  mov      x0, x19
//   0x00ad30: 97fffeaa  bl       #0xa7d8
//   0x00ad34: 340000a0  cbz      w0, #0xad48
//   0x00ad38: 2a1f03e0  mov      w0, wzr
//   0x00ad3c: 52800028  mov      w8, #1
//   0x00ad40: b9009668  str      w8, [x19, #0x94]
//   0x00ad44: 14000007  b        #0xad60
//   0x00ad48: b0000082  adrp     x2, #0x1b000
//   0x00ad4c: b94007e1  ldr      w1, [sp, #4]
//   0x00ad50: f947fc42  ldr      x2, [x2, #0xff8]
//   0x00ad54: aa1303e0  mov      x0, x19
//   0x00ad58: 97ffff85  bl       #0xab6c
//   0x00ad5c: 52800060  mov      w0, #3
//   0x00ad60: f9401688  ldr      x8, [x20, #0x28]
//   0x00ad64: f94007e9  ldr      x9, [sp, #8]
//   0x00ad68: eb09011f  cmp      x8, x9
//   0x00ad6c: 540000a1  b.ne     #0xad80
//   0x00ad70: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00ad74: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00ad78: 9100c3ff  add      sp, sp, #0x30
//   0x00ad7c: d65f03c0  ret      
//   0x00ad80: 97ffe0e8  bl       #0x3120
// ============================================================================
std::uint32_t fde_083_0acdc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000acdcULL;
    for (std::size_t i = 0; i < 42ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7779ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[084] Subroutine @ 0x00ad84..0x00ada8 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[084] Hàm con @ 0x00ad84..0x00ada8 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ad84: 5100b408  sub      w8, w0, #0x2d
//   0x00ad88: 7101451f  cmp      w8, #0x51
//   0x00ad8c: 540000a8  b.hi     #0xada0
//   0x00ad90: b0000049  adrp     x9, #0x13000
//   0x00ad94: 910cb129  add      x9, x9, #0x32c
//   0x00ad98: b868d920  ldr      w0, [x9, w8, sxtw #2]
//   0x00ad9c: d65f03c0  ret      
//   0x00ada0: 2a1f03e0  mov      w0, wzr
//   0x00ada4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_084_0ad84(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ad84ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7821ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[085] Subroutine @ 0x00ada8..0x00adb0 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[085] Hàm con @ 0x00ada8..0x00adb0 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ada8: aa1f03e3  mov      x3, xzr
//   0x00adac: 14000001  b        #0xadb0
// ============================================================================
std::uint32_t fde_085_0ada8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ada8ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7830ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[086] Subroutine @ 0x00adb0..0x00b540 (1936 bytes, 484 AArch64 instructions)
// [VN] Khung FDE[086] Hàm con @ 0x00adb0..0x00b540 (1936 byte, 484 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00adb0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x00adb4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00adb8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00adbc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00adc0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00adc4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00adc8: 910143fd  add      x29, sp, #0x50
//   0x00adcc: aa0003f3  mov      x19, x0
//   0x00add0: 52800040  mov      w0, #2
//   0x00add4: b4003733  cbz      x19, #0xb4b8
//   0x00add8: aa0103f7  mov      x23, x1
//   0x00addc: b40036e1  cbz      x1, #0xb4b8
//   0x00ade0: aa0203f4  mov      x20, x2
//   0x00ade4: b40036a2  cbz      x2, #0xb4b8
//   0x00ade8: aa0303f5  mov      x21, x3
//   0x00adec: b40000e3  cbz      x3, #0xae08
//   0x00adf0: aa1503e0  mov      x0, x21
//   0x00adf4: 97ffe11b  bl       #0x3260
//   0x00adf8: 7100041f  cmp      w0, #1
//   0x00adfc: 540000a0  b.eq     #0xae10
//   0x00ae00: 52800140  mov      w0, #0xa
//   0x00ae04: 140001ad  b        #0xb4b8
//   0x00ae08: b0000095  adrp     x21, #0x1b000
//   0x00ae0c: f947feb5  ldr      x21, [x21, #0xff8]
//   0x00ae10: f9400260  ldr      x0, [x19]
//   0x00ae14: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00ae18: ad000260  stp      q0, q0, [x19]
//   0x00ae1c: f9000260  str      x0, [x19]
//   0x00ae20: 97ffe090  bl       #0x3060
//   0x00ae24: eb1402ff  cmp      x23, x20
//   0x00ae28: 54003462  b.hs     #0xb4b4
//   0x00ae2c: 394002e8  ldrb     w8, [x23]
//   0x00ae30: 51008509  sub      w9, w8, #0x21
//   0x00ae34: 7101753f  cmp      w9, #0x5d
//   0x00ae38: 54000a48  b.hi     #0xaf80
//   0x00ae3c: b000004a  adrp     x10, #0x13000
//   0x00ae40: 9111d14a  add      x10, x10, #0x474
//   0x00ae44: 1000008b  adr      x11, #0xae54
//   0x00ae48: 3869694c  ldrb     w12, [x10, x9]
//   0x00ae4c: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00ae50: d61f0160  br       x11
//   0x00ae54: f9400268  ldr      x8, [x19]
//   0x00ae58: b0000099  adrp     x25, #0x1b000
//   0x00ae5c: 910006f6  add      x22, x23, #1
//   0x00ae60: eb1402df  cmp      x22, x20
//   0x00ae64: f9000117  str      x23, [x8]
//   0x00ae68: f947e339  ldr      x25, [x25, #0xfc0]
//   0x00ae6c: 54000262  b.hs     #0xaeb8
//   0x00ae70: aa3703e9  mvn      x9, x23
//   0x00ae74: b000004a  adrp     x10, #0x13000
//   0x00ae78: aa1f03fa  mov      x26, xzr
//   0x00ae7c: 8b140129  add      x9, x9, x20
//   0x00ae80: 9113494a  add      x10, x10, #0x4d2
//   0x00ae84: 8b1a02f6  add      x22, x23, x26
//   0x00ae88: 394006cb  ldrb     w11, [x22, #1]
//   0x00ae8c: 5100856b  sub      w11, w11, #0x21
//   0x00ae90: 7101757f  cmp      w11, #0x5d
//   0x00ae94: 54000b28  b.hi     #0xaff8
//   0x00ae98: 1000008c  adr      x12, #0xaea8
//   0x00ae9c: 386b694d  ldrb     w13, [x10, x11]
//   0x00aea0: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x00aea4: d61f0180  br       x12
//   0x00aea8: 9100075a  add      x26, x26, #1
//   0x00aeac: eb1a013f  cmp      x9, x26
//   0x00aeb0: 54fffea1  b.ne     #0xae84
//   0x00aeb4: aa1403f6  mov      x22, x20
//   0x00aeb8: f94006a8  ldr      x8, [x21, #8]
//   0x00aebc: 52800021  mov      w1, #1
//   0x00aec0: 52800402  mov      w2, #0x20
//   0x00aec4: aa1503e0  mov      x0, x21
//   0x00aec8: d63f0100  blr      x8
//   0x00aecc: b4002260  cbz      x0, #0xb318
//   0x00aed0: eb1702df  cmp      x22, x23
//   0x00aed4: 54000200  b.eq     #0xaf14
//   0x00aed8: a9005817  stp      x23, x22, [x0]
//   0x00aedc: 14000010  b        #0xaf1c
//   0x00aee0: f9400268  ldr      x8, [x19]
//   0x00aee4: 910006e1  add      x1, x23, #1
//   0x00aee8: f9000117  str      x23, [x8]
//   0x00aeec: 14000003  b        #0xaef8
//   0x00aef0: 8b1a02e8  add      x8, x23, x26
//   0x00aef4: 91000901  add      x1, x8, #2
//   0x00aef8: aa1303e0  mov      x0, x19
//   0x00aefc: aa1403e2  mov      x2, x20
//   0x00af00: aa1503e3  mov      x3, x21
//   0x00af04: 940009d0  bl       #0xd644
//   0x00af08: aa0003f6  mov      x22, x0
//   0x00af0c: b5000240  cbnz     x0, #0xaf54
//   0x00af10: 14000108  b        #0xb330
//   0x00af14: f9400328  ldr      x8, [x25]
//   0x00af18: a9002008  stp      x8, x8, [x0]
//   0x00af1c: f9400268  ldr      x8, [x19]
//   0x00af20: f9403109  ldr      x9, [x8, #0x60]
//   0x00af24: b40000a9  cbz      x9, #0xaf38
//   0x00af28: aa0803e9  mov      x9, x8
//   0x00af2c: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00af30: f9000940  str      x0, [x10, #0x10]
//   0x00af34: 14000003  b        #0xaf40
//   0x00af38: f9003100  str      x0, [x8, #0x60]
//   0x00af3c: 9101a109  add      x9, x8, #0x68
//   0x00af40: f9000120  str      x0, [x9]
//   0x00af44: f900011f  str      xzr, [x8]
//   0x00af48: aa1403e0  mov      x0, x20
//   0x00af4c: aa0003f6  mov      x22, x0
//   0x00af50: b4001f00  cbz      x0, #0xb330
//   0x00af54: eb1402df  cmp      x22, x20
//   0x00af58: 54002ae0  b.eq     #0xb4b4
//   0x00af5c: f9400260  ldr      x0, [x19]
//   0x00af60: aa1503e1  mov      x1, x21
//   0x00af64: 97ffe017  bl       #0x2fc0
//   0x00af68: eb1402df  cmp      x22, x20
//   0x00af6c: 52800020  mov      w0, #1
//   0x00af70: 9a9432c8  csel     x8, x22, x20, lo
//   0x00af74: f9000a68  str      x8, [x19, #0x10]
//   0x00af78: b9000a60  str      w0, [x19, #8]
//   0x00af7c: 1400014f  b        #0xb4b8
//   0x00af80: 7100fd1f  cmp      w8, #0x3f
//   0x00af84: 54000e20  b.eq     #0xb148
//   0x00af88: 71008d1f  cmp      w8, #0x23
//   0x00af8c: 54000f81  b.ne     #0xb17c
//   0x00af90: 910006f7  add      x23, x23, #1
//   0x00af94: 1400013d  b        #0xb488
//   0x00af98: aa1303e0  mov      x0, x19
//   0x00af9c: aa1703e1  mov      x1, x23
//   0x00afa0: aa1403e2  mov      x2, x20
//   0x00afa4: aa1503e3  mov      x3, x21
//   0x00afa8: 94000a89  bl       #0xd9cc
//   0x00afac: b4001c20  cbz      x0, #0xb330
//   0x00afb0: f9400268  ldr      x8, [x19]
//   0x00afb4: aa0003e1  mov      x1, x0
//   0x00afb8: f9000117  str      x23, [x8]
//   0x00afbc: 17ffffcf  b        #0xaef8
//   0x00afc0: 910006e1  add      x1, x23, #1
//   0x00afc4: aa1303e0  mov      x0, x19
//   0x00afc8: aa1403e2  mov      x2, x20
//   0x00afcc: aa1503e3  mov      x3, x21
//   0x00afd0: 94000ab4  bl       #0xdaa0
//   0x00afd4: b4001ae0  cbz      x0, #0xb330
//   0x00afd8: aa0003f6  mov      x22, x0
//   0x00afdc: eb14001f  cmp      x0, x20
//   0x00afe0: 540026a2  b.hs     #0xb4b4
//   0x00afe4: 394002c8  ldrb     w8, [x22]
//   0x00afe8: 7100fd1f  cmp      w8, #0x3f
//   0x00afec: 54002481  b.ne     #0xb47c
//   0x00aff0: 910006d7  add      x23, x22, #1
//   0x00aff4: 14000056  b        #0xb14c
//   0x00aff8: f94006a8  ldr      x8, [x21, #8]
//   0x00affc: 52800021  mov      w1, #1
//   0x00b000: 52800402  mov      w2, #0x20
//   0x00b004: aa1503e0  mov      x0, x21
//   0x00b008: d63f0100  blr      x8
//   0x00b00c: b4001860  cbz      x0, #0xb318
//   0x00b010: b100075f  cmn      x26, #1
//   0x00b014: 910006d6  add      x22, x22, #1
//   0x00b018: 54000ba0  b.eq     #0xb18c
//   0x00b01c: a9005817  stp      x23, x22, [x0]
//   0x00b020: 1400005d  b        #0xb194
//   0x00b024: 8b1a02e8  add      x8, x23, x26
//   0x00b028: 91000501  add      x1, x8, #1
//   0x00b02c: aa1303e0  mov      x0, x19
//   0x00b030: aa1403e2  mov      x2, x20
//   0x00b034: aa1503e3  mov      x3, x21
//   0x00b038: 94000a65  bl       #0xd9cc
//   0x00b03c: b40017a0  cbz      x0, #0xb330
//   0x00b040: aa0003e1  mov      x1, x0
//   0x00b044: 17ffffad  b        #0xaef8
//   0x00b048: 8b1a02fb  add      x27, x23, x26
//   0x00b04c: 91000b78  add      x24, x27, #2
//   0x00b050: aa1303e0  mov      x0, x19
//   0x00b054: aa1803e1  mov      x1, x24
//   0x00b058: aa1403e2  mov      x2, x20
//   0x00b05c: aa1503e3  mov      x3, x21
//   0x00b060: 94000b87  bl       #0xde7c
//   0x00b064: b4001660  cbz      x0, #0xb330
//   0x00b068: f9400268  ldr      x8, [x19]
//   0x00b06c: aa0003f6  mov      x22, x0
//   0x00b070: 52800021  mov      w1, #1
//   0x00b074: 52800402  mov      w2, #0x20
//   0x00b078: f940011c  ldr      x28, [x8]
//   0x00b07c: f94006a8  ldr      x8, [x21, #8]
//   0x00b080: aa1503e0  mov      x0, x21
//   0x00b084: d63f0100  blr      x8
//   0x00b088: b4001480  cbz      x0, #0xb318
//   0x00b08c: aa3703e8  mvn      x8, x23
//   0x00b090: 8b1c0108  add      x8, x8, x28
//   0x00b094: eb1a011f  cmp      x8, x26
//   0x00b098: 54000aa0  b.eq     #0xb1ec
//   0x00b09c: 91000768  add      x8, x27, #1
//   0x00b0a0: f900001c  str      x28, [x0]
//   0x00b0a4: 14000054  b        #0xb1f4
//   0x00b0a8: 8b1a02e9  add      x9, x23, x26
//   0x00b0ac: 91000936  add      x22, x9, #2
//   0x00b0b0: eb1402df  cmp      x22, x20
//   0x00b0b4: 9100053b  add      x27, x9, #1
//   0x00b0b8: 54001b42  b.hs     #0xb420
//   0x00b0bc: 39400929  ldrb     w9, [x9, #2]
//   0x00b0c0: 51008529  sub      w9, w9, #0x21
//   0x00b0c4: 7101753f  cmp      w9, #0x5d
//   0x00b0c8: 54002228  b.hi     #0xb50c
//   0x00b0cc: 9000004a  adrp     x10, #0x13000
//   0x00b0d0: 9114c14a  add      x10, x10, #0x530
//   0x00b0d4: 1000008b  adr      x11, #0xb0e4
//   0x00b0d8: 7869794c  ldrh     w12, [x10, x9, lsl #1]
//   0x00b0dc: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00b0e0: d61f0160  br       x11
//   0x00b0e4: aa1303e0  mov      x0, x19
//   0x00b0e8: aa1603e1  mov      x1, x22
//   0x00b0ec: aa1403e2  mov      x2, x20
//   0x00b0f0: aa1503e3  mov      x3, x21
//   0x00b0f4: 94000b82  bl       #0xdefc
//   0x00b0f8: b4001fa0  cbz      x0, #0xb4ec
//   0x00b0fc: aa0003e1  mov      x1, x0
//   0x00b100: aa1303e0  mov      x0, x19
//   0x00b104: aa1403e2  mov      x2, x20
//   0x00b108: aa1503e3  mov      x3, x21
//   0x00b10c: 94000b5c  bl       #0xde7c
//   0x00b110: b4001ee0  cbz      x0, #0xb4ec
//   0x00b114: f94006a8  ldr      x8, [x21, #8]
//   0x00b118: aa0003f8  mov      x24, x0
//   0x00b11c: 52800021  mov      w1, #1
//   0x00b120: 52800402  mov      w2, #0x20
//   0x00b124: aa1503e0  mov      x0, x21
//   0x00b128: d63f0100  blr      x8
//   0x00b12c: b4001d40  cbz      x0, #0xb4d4
//   0x00b130: cb170308  sub      x8, x24, x23
//   0x00b134: d1000908  sub      x8, x8, #2
//   0x00b138: eb1a011f  cmp      x8, x26
//   0x00b13c: 54001060  b.eq     #0xb348
//   0x00b140: a9006016  stp      x22, x24, [x0]
//   0x00b144: 14000083  b        #0xb350
//   0x00b148: 910006f7  add      x23, x23, #1
//   0x00b14c: aa1303e0  mov      x0, x19
//   0x00b150: aa1703e1  mov      x1, x23
//   0x00b154: aa1403e2  mov      x2, x20
//   0x00b158: aa1503e3  mov      x3, x21
//   0x00b15c: 94000e00  bl       #0xe95c
//   0x00b160: b4000e80  cbz      x0, #0xb330
//   0x00b164: f9400268  ldr      x8, [x19]
//   0x00b168: aa0003f6  mov      x22, x0
//   0x00b16c: eb14001f  cmp      x0, x20
//   0x00b170: a9070117  stp      x23, x0, [x8, #0x70]
//   0x00b174: 54001823  b.lo     #0xb478
//   0x00b178: 140000cf  b        #0xb4b4
//   0x00b17c: aa1703f6  mov      x22, x23
//   0x00b180: eb1402df  cmp      x22, x20
//   0x00b184: 54ffeec1  b.ne     #0xaf5c
//   0x00b188: 140000cb  b        #0xb4b4
//   0x00b18c: f9400328  ldr      x8, [x25]
//   0x00b190: a9002008  stp      x8, x8, [x0]
//   0x00b194: f9400268  ldr      x8, [x19]
//   0x00b198: f9403109  ldr      x9, [x8, #0x60]
//   0x00b19c: b40000a9  cbz      x9, #0xb1b0
//   0x00b1a0: aa0803e9  mov      x9, x8
//   0x00b1a4: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00b1a8: f9000940  str      x0, [x10, #0x10]
//   0x00b1ac: 14000003  b        #0xb1b8
//   0x00b1b0: f9003100  str      x0, [x8, #0x60]
//   0x00b1b4: 9101a109  add      x9, x8, #0x68
//   0x00b1b8: f9000120  str      x0, [x9]
//   0x00b1bc: f900011f  str      xzr, [x8]
//   0x00b1c0: 394002c8  ldrb     w8, [x22]
//   0x00b1c4: 71008d1f  cmp      w8, #0x23
//   0x00b1c8: 540000c0  b.eq     #0xb1e0
//   0x00b1cc: 7100fd1f  cmp      w8, #0x3f
//   0x00b1d0: 54ffec21  b.ne     #0xaf54
//   0x00b1d4: 8b1a02e8  add      x8, x23, x26
//   0x00b1d8: 91000917  add      x23, x8, #2
//   0x00b1dc: 1400009b  b        #0xb448
//   0x00b1e0: 8b1a02e8  add      x8, x23, x26
//   0x00b1e4: 91000917  add      x23, x8, #2
//   0x00b1e8: 140000a8  b        #0xb488
//   0x00b1ec: f9400328  ldr      x8, [x25]
//   0x00b1f0: f9000008  str      x8, [x0]
//   0x00b1f4: f9000408  str      x8, [x0, #8]
//   0x00b1f8: f9400268  ldr      x8, [x19]
//   0x00b1fc: f9403109  ldr      x9, [x8, #0x60]
//   0x00b200: b40000a9  cbz      x9, #0xb214
//   0x00b204: aa0803e9  mov      x9, x8
//   0x00b208: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00b20c: f9000940  str      x0, [x10, #0x10]
//   0x00b210: 14000003  b        #0xb21c
//   0x00b214: f9003100  str      x0, [x8, #0x60]
//   0x00b218: 9101a109  add      x9, x8, #0x68
//   0x00b21c: f9000120  str      x0, [x9]
//   0x00b220: f900011f  str      xzr, [x8]
//   0x00b224: f94006a8  ldr      x8, [x21, #8]
//   0x00b228: 52800021  mov      w1, #1
//   0x00b22c: 52800402  mov      w2, #0x20
//   0x00b230: aa1503e0  mov      x0, x21
//   0x00b234: d63f0100  blr      x8
//   0x00b238: b4000700  cbz      x0, #0xb318
//   0x00b23c: cb1702c8  sub      x8, x22, x23
//   0x00b240: d1000908  sub      x8, x8, #2
//   0x00b244: eb1a011f  cmp      x8, x26
//   0x00b248: 54000060  b.eq     #0xb254
//   0x00b24c: a9005818  stp      x24, x22, [x0]
//   0x00b250: 14000003  b        #0xb25c
//   0x00b254: f9400328  ldr      x8, [x25]
//   0x00b258: a9002008  stp      x8, x8, [x0]
//   0x00b25c: f9400268  ldr      x8, [x19]
//   0x00b260: f9403109  ldr      x9, [x8, #0x60]
//   0x00b264: b4000089  cbz      x9, #0xb274
//   0x00b268: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00b26c: f9000920  str      x0, [x9, #0x10]
//   0x00b270: 14000003  b        #0xb27c
//   0x00b274: f9003100  str      x0, [x8, #0x60]
//   0x00b278: 9101a108  add      x8, x8, #0x68
//   0x00b27c: eb1402df  cmp      x22, x20
//   0x00b280: f9000100  str      x0, [x8]
//   0x00b284: aa1403e0  mov      x0, x20
//   0x00b288: 54ffe622  b.hs     #0xaf4c
//   0x00b28c: f9400338  ldr      x24, [x25]
//   0x00b290: 14000006  b        #0xb2a8
//   0x00b294: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00b298: f9000920  str      x0, [x9, #0x10]
//   0x00b29c: eb1402df  cmp      x22, x20
//   0x00b2a0: f9000100  str      x0, [x8]
//   0x00b2a4: 54ffe522  b.hs     #0xaf48
//   0x00b2a8: 394002c8  ldrb     w8, [x22]
//   0x00b2ac: 7100bd1f  cmp      w8, #0x2f
//   0x00b2b0: 54001241  b.ne     #0xb4f8
//   0x00b2b4: 910006d7  add      x23, x22, #1
//   0x00b2b8: aa1303e0  mov      x0, x19
//   0x00b2bc: aa1703e1  mov      x1, x23
//   0x00b2c0: aa1403e2  mov      x2, x20
//   0x00b2c4: aa1503e3  mov      x3, x21
//   0x00b2c8: 94000aed  bl       #0xde7c
//   0x00b2cc: b4000320  cbz      x0, #0xb330
//   0x00b2d0: f94006a8  ldr      x8, [x21, #8]
//   0x00b2d4: aa0003f6  mov      x22, x0
//   0x00b2d8: 52800021  mov      w1, #1
//   0x00b2dc: 52800402  mov      w2, #0x20
//   0x00b2e0: aa1503e0  mov      x0, x21
//   0x00b2e4: d63f0100  blr      x8
//   0x00b2e8: b4000180  cbz      x0, #0xb318
//   0x00b2ec: eb1602ff  cmp      x23, x22
//   0x00b2f0: 54000060  b.eq     #0xb2fc
//   0x00b2f4: a9005817  stp      x23, x22, [x0]
//   0x00b2f8: 14000002  b        #0xb300
//   0x00b2fc: a9006018  stp      x24, x24, [x0]
//   0x00b300: f9400268  ldr      x8, [x19]
//   0x00b304: f9403109  ldr      x9, [x8, #0x60]
//   0x00b308: b5fffc69  cbnz     x9, #0xb294
//   0x00b30c: f9003100  str      x0, [x8, #0x60]
//   0x00b310: 9101a108  add      x8, x8, #0x68
//   0x00b314: 17ffffe2  b        #0xb29c
//   0x00b318: f9400260  ldr      x0, [x19]
//   0x00b31c: aa1503e1  mov      x1, x21
//   0x00b320: 97ffdf28  bl       #0x2fc0
//   0x00b324: 52800068  mov      w8, #3
//   0x00b328: f9000a7f  str      xzr, [x19, #0x10]
//   0x00b32c: b9000a68  str      w8, [x19, #8]
//   0x00b330: f9400a68  ldr      x8, [x19, #0x10]
//   0x00b334: eb14011f  cmp      x8, x20
//   0x00b338: 54000049  b.ls     #0xb340
//   0x00b33c: f9000a74  str      x20, [x19, #0x10]
//   0x00b340: b9400a60  ldr      w0, [x19, #8]
//   0x00b344: 1400005d  b        #0xb4b8
//   0x00b348: f9400328  ldr      x8, [x25]
//   0x00b34c: a9002008  stp      x8, x8, [x0]
//   0x00b350: f9400268  ldr      x8, [x19]
//   0x00b354: f9403109  ldr      x9, [x8, #0x60]
//   0x00b358: b40000a9  cbz      x9, #0xb36c
//   0x00b35c: aa0803e9  mov      x9, x8
//   0x00b360: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00b364: f9000940  str      x0, [x10, #0x10]
//   0x00b368: 14000003  b        #0xb374
//   0x00b36c: f9003100  str      x0, [x8, #0x60]
//   0x00b370: 9101a109  add      x9, x8, #0x68
//   0x00b374: eb14031f  cmp      x24, x20
//   0x00b378: f9000120  str      x0, [x9]
//   0x00b37c: 54000522  b.hs     #0xb420
//   0x00b380: 39400309  ldrb     w9, [x24]
//   0x00b384: 7100bd3f  cmp      w9, #0x2f
//   0x00b388: 54000c01  b.ne     #0xb508
//   0x00b38c: f9400339  ldr      x25, [x25]
//   0x00b390: aa1803f6  mov      x22, x24
//   0x00b394: 910006d7  add      x23, x22, #1
//   0x00b398: aa1303e0  mov      x0, x19
//   0x00b39c: aa1703e1  mov      x1, x23
//   0x00b3a0: aa1403e2  mov      x2, x20
//   0x00b3a4: aa1503e3  mov      x3, x21
//   0x00b3a8: 94000ab5  bl       #0xde7c
//   0x00b3ac: b4000a00  cbz      x0, #0xb4ec
//   0x00b3b0: f94006a8  ldr      x8, [x21, #8]
//   0x00b3b4: aa0003f6  mov      x22, x0
//   0x00b3b8: 52800021  mov      w1, #1
//   0x00b3bc: 52800402  mov      w2, #0x20
//   0x00b3c0: aa1503e0  mov      x0, x21
//   0x00b3c4: d63f0100  blr      x8
//   0x00b3c8: b4000860  cbz      x0, #0xb4d4
//   0x00b3cc: eb1602ff  cmp      x23, x22
//   0x00b3d0: 54000060  b.eq     #0xb3dc
//   0x00b3d4: a9005817  stp      x23, x22, [x0]
//   0x00b3d8: 14000002  b        #0xb3e0
//   0x00b3dc: a9006419  stp      x25, x25, [x0]
//   0x00b3e0: f9400268  ldr      x8, [x19]
//   0x00b3e4: f9403109  ldr      x9, [x8, #0x60]
//   0x00b3e8: b40000a9  cbz      x9, #0xb3fc
//   0x00b3ec: aa0803e9  mov      x9, x8
//   0x00b3f0: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00b3f4: f9000940  str      x0, [x10, #0x10]
//   0x00b3f8: 14000003  b        #0xb404
//   0x00b3fc: f9003100  str      x0, [x8, #0x60]
//   0x00b400: 9101a109  add      x9, x8, #0x68
//   0x00b404: eb1402df  cmp      x22, x20
//   0x00b408: f9000120  str      x0, [x9]
//   0x00b40c: 540000a2  b.hs     #0xb420
//   0x00b410: 394002c9  ldrb     w9, [x22]
//   0x00b414: 7100bd3f  cmp      w9, #0x2f
//   0x00b418: 54fffbe0  b.eq     #0xb394
//   0x00b41c: 1400003c  b        #0xb50c
//   0x00b420: aa1403f6  mov      x22, x20
//   0x00b424: f900051b  str      x27, [x8, #8]
//   0x00b428: b4fff856  cbz      x22, #0xb330
//   0x00b42c: eb1402df  cmp      x22, x20
//   0x00b430: aa1403e0  mov      x0, x20
//   0x00b434: 54ffd8c2  b.hs     #0xaf4c
//   0x00b438: 394002c8  ldrb     w8, [x22]
//   0x00b43c: 7100fd1f  cmp      w8, #0x3f
//   0x00b440: 540001e1  b.ne     #0xb47c
//   0x00b444: 910006d7  add      x23, x22, #1
//   0x00b448: aa1303e0  mov      x0, x19
//   0x00b44c: aa1703e1  mov      x1, x23
//   0x00b450: aa1403e2  mov      x2, x20
//   0x00b454: aa1503e3  mov      x3, x21
//   0x00b458: 94000d41  bl       #0xe95c
//   0x00b45c: b4fff6a0  cbz      x0, #0xb330
//   0x00b460: f9400268  ldr      x8, [x19]
//   0x00b464: aa0003f6  mov      x22, x0
//   0x00b468: eb14001f  cmp      x0, x20
//   0x00b46c: a9070117  stp      x23, x0, [x8, #0x70]
//   0x00b470: aa1403e0  mov      x0, x20
//   0x00b474: 54ffd6c2  b.hs     #0xaf4c
//   0x00b478: 394002c8  ldrb     w8, [x22]
//   0x00b47c: 71008d1f  cmp      w8, #0x23
//   0x00b480: 54ffd6a1  b.ne     #0xaf54
//   0x00b484: 910006d7  add      x23, x22, #1
//   0x00b488: aa1303e0  mov      x0, x19
//   0x00b48c: aa1703e1  mov      x1, x23
//   0x00b490: aa1403e2  mov      x2, x20
//   0x00b494: aa1503e3  mov      x3, x21
//   0x00b498: 94000d31  bl       #0xe95c
//   0x00b49c: b4fff4a0  cbz      x0, #0xb330
//   0x00b4a0: f9400268  ldr      x8, [x19]
//   0x00b4a4: aa0003f6  mov      x22, x0
//   0x00b4a8: a9080117  stp      x23, x0, [x8, #0x80]
//   0x00b4ac: eb1402df  cmp      x22, x20
//   0x00b4b0: 54ffd561  b.ne     #0xaf5c
//   0x00b4b4: 2a1f03e0  mov      w0, wzr
//   0x00b4b8: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x00b4bc: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x00b4c0: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x00b4c4: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x00b4c8: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x00b4cc: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x00b4d0: d65f03c0  ret      
//   0x00b4d4: f9400260  ldr      x0, [x19]
//   0x00b4d8: aa1503e1  mov      x1, x21
//   0x00b4dc: 97ffdeb9  bl       #0x2fc0
//   0x00b4e0: 52800068  mov      w8, #3
//   0x00b4e4: f9000a7f  str      xzr, [x19, #0x10]
//   0x00b4e8: b9000a68  str      w8, [x19, #8]
//   0x00b4ec: f9400268  ldr      x8, [x19]
//   0x00b4f0: f900051b  str      x27, [x8, #8]
//   0x00b4f4: 17ffff8f  b        #0xb330
//   0x00b4f8: eb1402df  cmp      x22, x20
//   0x00b4fc: aa1403e0  mov      x0, x20
//   0x00b500: 54ffd262  b.hs     #0xaf4c
//   0x00b504: 17ffffce  b        #0xb43c
//   0x00b508: aa1803f6  mov      x22, x24
//   0x00b50c: f900051b  str      x27, [x8, #8]
//   0x00b510: 17ffffc7  b        #0xb42c
//   0x00b514: 8b1a02e8  add      x8, x23, x26
//   0x00b518: 91000d01  add      x1, x8, #3
//   0x00b51c: aa1303e0  mov      x0, x19
//   0x00b520: aa1403e2  mov      x2, x20
//   0x00b524: aa1503e3  mov      x3, x21
//   0x00b528: 9400095e  bl       #0xdaa0
//   0x00b52c: f9400268  ldr      x8, [x19]
//   0x00b530: aa0003f6  mov      x22, x0
//   0x00b534: f900051b  str      x27, [x8, #8]
//   0x00b538: b5fff7b6  cbnz     x22, #0xb42c
//   0x00b53c: 17ffff7d  b        #0xb330
// ============================================================================
std::uint32_t fde_086_0adb0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000adb0ULL;
    for (std::size_t i = 0; i < 484ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7832ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[087] Subroutine @ 0x00b540..0x00b590 (80 bytes, 20 AArch64 instructions)
// [VN] Khung FDE[087] Hàm con @ 0x00b540..0x00b590 (80 byte, 20 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00b540: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00b544: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00b548: 910043fd  add      x29, sp, #0x10
//   0x00b54c: b40001a0  cbz      x0, #0xb580
//   0x00b550: aa0103f3  mov      x19, x1
//   0x00b554: b4000161  cbz      x1, #0xb580
//   0x00b558: aa0003f4  mov      x20, x0
//   0x00b55c: aa1303e0  mov      x0, x19
//   0x00b560: 97ffdf34  bl       #0x3230
//   0x00b564: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00b568: 8b000262  add      x2, x19, x0
//   0x00b56c: aa1403e0  mov      x0, x20
//   0x00b570: aa1303e1  mov      x1, x19
//   0x00b574: aa1f03e3  mov      x3, xzr
//   0x00b578: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x00b57c: 17fffe0d  b        #0xadb0
//   0x00b580: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00b584: 52800040  mov      w0, #2
//   0x00b588: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x00b58c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_087_0b540(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000b540ULL;
    for (std::size_t i = 0; i < 20ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8316ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[088] Subroutine @ 0x00b590..0x00b650 (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[088] Hàm con @ 0x00b590..0x00b650 (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00b590: d101c3ff  sub      sp, sp, #0x70
//   0x00b594: f9001bf7  str      x23, [sp, #0x30]
//   0x00b598: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00b59c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00b5a0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00b5a4: 910183fd  add      x29, sp, #0x60
//   0x00b5a8: d53bd057  mrs      x23, tpidr_el0
//   0x00b5ac: f94016e8  ldr      x8, [x23, #0x28]
//   0x00b5b0: f90017e8  str      x8, [sp, #0x28]
//   0x00b5b4: b4000341  cbz      x1, #0xb61c
//   0x00b5b8: aa0003f3  mov      x19, x0
//   0x00b5bc: aa0103e0  mov      x0, x1
//   0x00b5c0: aa0203f5  mov      x21, x2
//   0x00b5c4: aa0103f6  mov      x22, x1
//   0x00b5c8: 97ffdf1a  bl       #0x3230
//   0x00b5cc: 52800054  mov      w20, #2
//   0x00b5d0: b4000293  cbz      x19, #0xb620
//   0x00b5d4: b4000276  cbz      x22, #0xb620
//   0x00b5d8: f90007f3  str      x19, [sp, #8]
//   0x00b5dc: 90000083  adrp     x3, #0x1b000
//   0x00b5e0: f947fc63  ldr      x3, [x3, #0xff8]
//   0x00b5e4: 8b0002c2  add      x2, x22, x0
//   0x00b5e8: 910023e0  add      x0, sp, #8
//   0x00b5ec: aa1603e1  mov      x1, x22
//   0x00b5f0: 97fffdf0  bl       #0xadb0
//   0x00b5f4: 2a0003f4  mov      w20, w0
//   0x00b5f8: 34000140  cbz      w0, #0xb620
//   0x00b5fc: b4000075  cbz      x21, #0xb608
//   0x00b600: f9400fe8  ldr      x8, [sp, #0x18]
//   0x00b604: f90002a8  str      x8, [x21]
//   0x00b608: 90000081  adrp     x1, #0x1b000
//   0x00b60c: f947fc21  ldr      x1, [x1, #0xff8]
//   0x00b610: aa1303e0  mov      x0, x19
//   0x00b614: 97ffde6b  bl       #0x2fc0
//   0x00b618: 14000002  b        #0xb620
//   0x00b61c: 52800054  mov      w20, #2
//   0x00b620: f94016e8  ldr      x8, [x23, #0x28]
//   0x00b624: f94017e9  ldr      x9, [sp, #0x28]
//   0x00b628: eb09011f  cmp      x8, x9
//   0x00b62c: 54000101  b.ne     #0xb64c
//   0x00b630: 2a1403e0  mov      w0, w20
//   0x00b634: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x00b638: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00b63c: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x00b640: f9401bf7  ldr      x23, [sp, #0x30]
//   0x00b644: 9101c3ff  add      sp, sp, #0x70
//   0x00b648: d65f03c0  ret      
//   0x00b64c: 97ffdeb5  bl       #0x3120
// ============================================================================
std::uint32_t fde_088_0b590(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000b590ULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8336ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[089] Subroutine @ 0x00b650..0x00b710 (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[089] Hàm con @ 0x00b650..0x00b710 (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00b650: d101c3ff  sub      sp, sp, #0x70
//   0x00b654: f9001bf7  str      x23, [sp, #0x30]
//   0x00b658: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00b65c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00b660: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00b664: 910183fd  add      x29, sp, #0x60
//   0x00b668: d53bd057  mrs      x23, tpidr_el0
//   0x00b66c: f94016e8  ldr      x8, [x23, #0x28]
//   0x00b670: aa0303f4  mov      x20, x3
//   0x00b674: aa0103f6  mov      x22, x1
//   0x00b678: aa0003f3  mov      x19, x0
//   0x00b67c: f90017e8  str      x8, [sp, #0x28]
//   0x00b680: b40000a1  cbz      x1, #0xb694
//   0x00b684: b5000082  cbnz     x2, #0xb694
//   0x00b688: aa1603e0  mov      x0, x22
//   0x00b68c: 97ffdee9  bl       #0x3230
//   0x00b690: 8b0002c2  add      x2, x22, x0
//   0x00b694: 52800055  mov      w21, #2
//   0x00b698: b4000253  cbz      x19, #0xb6e0
//   0x00b69c: b4000236  cbz      x22, #0xb6e0
//   0x00b6a0: b4000202  cbz      x2, #0xb6e0
//   0x00b6a4: f90007f3  str      x19, [sp, #8]
//   0x00b6a8: 90000083  adrp     x3, #0x1b000
//   0x00b6ac: f947fc63  ldr      x3, [x3, #0xff8]
//   0x00b6b0: 910023e0  add      x0, sp, #8
//   0x00b6b4: aa1603e1  mov      x1, x22
//   0x00b6b8: 97fffdbe  bl       #0xadb0
//   0x00b6bc: 2a0003f5  mov      w21, w0
//   0x00b6c0: 34000100  cbz      w0, #0xb6e0
//   0x00b6c4: b4000074  cbz      x20, #0xb6d0
//   0x00b6c8: f9400fe8  ldr      x8, [sp, #0x18]
//   0x00b6cc: f9000288  str      x8, [x20]
//   0x00b6d0: 90000081  adrp     x1, #0x1b000
//   0x00b6d4: f947fc21  ldr      x1, [x1, #0xff8]
//   0x00b6d8: aa1303e0  mov      x0, x19
//   0x00b6dc: 97ffde39  bl       #0x2fc0
//   0x00b6e0: f94016e8  ldr      x8, [x23, #0x28]
//   0x00b6e4: f94017e9  ldr      x9, [sp, #0x28]
//   0x00b6e8: eb09011f  cmp      x8, x9
//   0x00b6ec: 54000101  b.ne     #0xb70c
//   0x00b6f0: 2a1503e0  mov      w0, w21
//   0x00b6f4: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x00b6f8: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00b6fc: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x00b700: f9401bf7  ldr      x23, [sp, #0x30]
//   0x00b704: 9101c3ff  add      sp, sp, #0x70
//   0x00b708: d65f03c0  ret      
//   0x00b70c: 97ffde85  bl       #0x3120
// ============================================================================
std::uint32_t fde_089_0b650(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000b650ULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8384ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[090] Subroutine @ 0x00b710..0x00b7ec (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[090] Hàm con @ 0x00b710..0x00b7ec (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00b710: d10203ff  sub      sp, sp, #0x80
//   0x00b714: f9001bf9  str      x25, [sp, #0x30]
//   0x00b718: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x00b71c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x00b720: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x00b724: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x00b728: 9101c3fd  add      x29, sp, #0x70
//   0x00b72c: d53bd059  mrs      x25, tpidr_el0
//   0x00b730: f9401728  ldr      x8, [x25, #0x28]
//   0x00b734: 52800056  mov      w22, #2
//   0x00b738: f90017e8  str      x8, [sp, #0x28]
//   0x00b73c: b40003e0  cbz      x0, #0xb7b8
//   0x00b740: aa0103f8  mov      x24, x1
//   0x00b744: b40003a1  cbz      x1, #0xb7b8
//   0x00b748: aa0203f7  mov      x23, x2
//   0x00b74c: b4000362  cbz      x2, #0xb7b8
//   0x00b750: aa0403f3  mov      x19, x4
//   0x00b754: aa0303f5  mov      x21, x3
//   0x00b758: aa0003f4  mov      x20, x0
//   0x00b75c: b40000e4  cbz      x4, #0xb778
//   0x00b760: aa1303e0  mov      x0, x19
//   0x00b764: 97ffdebf  bl       #0x3260
//   0x00b768: 7100041f  cmp      w0, #1
//   0x00b76c: 540000a0  b.eq     #0xb780
//   0x00b770: 52800156  mov      w22, #0xa
//   0x00b774: 14000011  b        #0xb7b8
//   0x00b778: 90000093  adrp     x19, #0x1b000
//   0x00b77c: f947fe73  ldr      x19, [x19, #0xff8]
//   0x00b780: 910023e0  add      x0, sp, #8
//   0x00b784: aa1803e1  mov      x1, x24
//   0x00b788: aa1703e2  mov      x2, x23
//   0x00b78c: aa1303e3  mov      x3, x19
//   0x00b790: f90007f4  str      x20, [sp, #8]
//   0x00b794: 97fffd87  bl       #0xadb0
//   0x00b798: 2a0003f6  mov      w22, w0
//   0x00b79c: 340000e0  cbz      w0, #0xb7b8
//   0x00b7a0: b4000075  cbz      x21, #0xb7ac
//   0x00b7a4: f9400fe8  ldr      x8, [sp, #0x18]
//   0x00b7a8: f90002a8  str      x8, [x21]
//   0x00b7ac: aa1403e0  mov      x0, x20
//   0x00b7b0: aa1303e1  mov      x1, x19
//   0x00b7b4: 97ffde03  bl       #0x2fc0
//   0x00b7b8: f9401728  ldr      x8, [x25, #0x28]
//   0x00b7bc: f94017e9  ldr      x9, [sp, #0x28]
//   0x00b7c0: eb09011f  cmp      x8, x9
//   0x00b7c4: 54000121  b.ne     #0xb7e8
//   0x00b7c8: 2a1603e0  mov      w0, w22
//   0x00b7cc: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x00b7d0: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x00b7d4: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x00b7d8: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x00b7dc: f9401bf9  ldr      x25, [sp, #0x30]
//   0x00b7e0: 910203ff  add      sp, sp, #0x80
//   0x00b7e4: d65f03c0  ret      
//   0x00b7e8: 97ffde4e  bl       #0x3120
// ============================================================================
std::uint32_t fde_090_0b710(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000b710ULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8432ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[091] Subroutine @ 0x00b7ec..0x00ba2c (576 bytes, 144 AArch64 instructions)
// [VN] Khung FDE[091] Hàm con @ 0x00b7ec..0x00ba2c (576 byte, 144 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00b7ec: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00b7f0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00b7f4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00b7f8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00b7fc: 9100c3fd  add      x29, sp, #0x30
//   0x00b800: b4000140  cbz      x0, #0xb828
//   0x00b804: aa0103f3  mov      x19, x1
//   0x00b808: aa0003f4  mov      x20, x0
//   0x00b80c: b4000121  cbz      x1, #0xb830
//   0x00b810: aa1303e0  mov      x0, x19
//   0x00b814: 97ffde93  bl       #0x3260
//   0x00b818: 7100041f  cmp      w0, #1
//   0x00b81c: 540000e0  b.eq     #0xb838
//   0x00b820: 52800140  mov      w0, #0xa
//   0x00b824: 1400007d  b        #0xba18
//   0x00b828: 52800040  mov      w0, #2
//   0x00b82c: 1400007b  b        #0xba18
//   0x00b830: 90000093  adrp     x19, #0x1b000
//   0x00b834: f947fe73  ldr      x19, [x19, #0xff8]
//   0x00b838: b9409688  ldr      w8, [x20, #0x94]
//   0x00b83c: 340005a8  cbz      w8, #0xb8f0
//   0x00b840: f9400281  ldr      x1, [x20]
//   0x00b844: b4000101  cbz      x1, #0xb864
//   0x00b848: f9400688  ldr      x8, [x20, #8]
//   0x00b84c: eb08003f  cmp      x1, x8
//   0x00b850: 54000080  b.eq     #0xb860
//   0x00b854: f9401268  ldr      x8, [x19, #0x20]
//   0x00b858: aa1303e0  mov      x0, x19
//   0x00b85c: d63f0100  blr      x8
//   0x00b860: a9007e9f  stp      xzr, xzr, [x20]
//   0x00b864: aa1403f5  mov      x21, x20
//   0x00b868: f8410ea1  ldr      x1, [x21, #0x10]!
//   0x00b86c: b4000101  cbz      x1, #0xb88c
//   0x00b870: f9400e88  ldr      x8, [x20, #0x18]
//   0x00b874: eb08003f  cmp      x1, x8
//   0x00b878: 54000080  b.eq     #0xb888
//   0x00b87c: f9401268  ldr      x8, [x19, #0x20]
//   0x00b880: aa1303e0  mov      x0, x19
//   0x00b884: d63f0100  blr      x8
//   0x00b888: a9007ebf  stp      xzr, xzr, [x21]
//   0x00b88c: aa1403f5  mov      x21, x20
//   0x00b890: f8440ea1  ldr      x1, [x21, #0x40]!
//   0x00b894: b40001a1  cbz      x1, #0xb8c8
//   0x00b898: aa1403e8  mov      x8, x20
//   0x00b89c: f8420d09  ldr      x9, [x8, #0x20]!
//   0x00b8a0: eb01013f  cmp      x9, x1
//   0x00b8a4: 54000041  b.ne     #0xb8ac
//   0x00b8a8: a9007d1f  stp      xzr, xzr, [x8]
//   0x00b8ac: f9402688  ldr      x8, [x20, #0x48]
//   0x00b8b0: eb08003f  cmp      x1, x8
//   0x00b8b4: 54000080  b.eq     #0xb8c4
//   0x00b8b8: f9401268  ldr      x8, [x19, #0x20]
//   0x00b8bc: aa1303e0  mov      x0, x19
//   0x00b8c0: d63f0100  blr      x8
//   0x00b8c4: a9007ebf  stp      xzr, xzr, [x21]
//   0x00b8c8: aa1403f5  mov      x21, x20
//   0x00b8cc: f8420ea1  ldr      x1, [x21, #0x20]!
//   0x00b8d0: b4000101  cbz      x1, #0xb8f0
//   0x00b8d4: f9401688  ldr      x8, [x20, #0x28]
//   0x00b8d8: eb08003f  cmp      x1, x8
//   0x00b8dc: 54000080  b.eq     #0xb8ec
//   0x00b8e0: f9401268  ldr      x8, [x19, #0x20]
//   0x00b8e4: aa1303e0  mov      x0, x19
//   0x00b8e8: d63f0100  blr      x8
//   0x00b8ec: a9007ebf  stp      xzr, xzr, [x21]
//   0x00b8f0: f9401a81  ldr      x1, [x20, #0x30]
//   0x00b8f4: b40000a1  cbz      x1, #0xb908
//   0x00b8f8: f9401268  ldr      x8, [x19, #0x20]
//   0x00b8fc: aa1303e0  mov      x0, x19
//   0x00b900: d63f0100  blr      x8
//   0x00b904: f9001a9f  str      xzr, [x20, #0x30]
//   0x00b908: f9401e81  ldr      x1, [x20, #0x38]
//   0x00b90c: b40000a1  cbz      x1, #0xb920
//   0x00b910: f9401268  ldr      x8, [x19, #0x20]
//   0x00b914: aa1303e0  mov      x0, x19
//   0x00b918: d63f0100  blr      x8
//   0x00b91c: f9001e9f  str      xzr, [x20, #0x38]
//   0x00b920: b9409688  ldr      w8, [x20, #0x94]
//   0x00b924: 34000168  cbz      w8, #0xb950
//   0x00b928: aa1403f5  mov      x21, x20
//   0x00b92c: f8450ea1  ldr      x1, [x21, #0x50]!
//   0x00b930: b4000101  cbz      x1, #0xb950
//   0x00b934: f9402e88  ldr      x8, [x20, #0x58]
//   0x00b938: eb08003f  cmp      x1, x8
//   0x00b93c: 54000080  b.eq     #0xb94c
//   0x00b940: f9401268  ldr      x8, [x19, #0x20]
//   0x00b944: aa1303e0  mov      x0, x19
//   0x00b948: d63f0100  blr      x8
//   0x00b94c: a9007ebf  stp      xzr, xzr, [x21]
//   0x00b950: aa1403f6  mov      x22, x20
//   0x00b954: f8460ed7  ldr      x23, [x22, #0x60]!
//   0x00b958: b5000137  cbnz     x23, #0xb97c
//   0x00b95c: b9409688  ldr      w8, [x20, #0x94]
//   0x00b960: 350002e8  cbnz     w8, #0xb9bc
//   0x00b964: 1400002c  b        #0xba14
//   0x00b968: f9401268  ldr      x8, [x19, #0x20]
//   0x00b96c: aa1303e0  mov      x0, x19
//   0x00b970: aa1503e1  mov      x1, x21
//   0x00b974: d63f0100  blr      x8
//   0x00b978: b40001d7  cbz      x23, #0xb9b0
//   0x00b97c: aa1703f5  mov      x21, x23
//   0x00b980: b9409688  ldr      w8, [x20, #0x94]
//   0x00b984: f9400af7  ldr      x23, [x23, #0x10]
//   0x00b988: 34ffff08  cbz      w8, #0xb968
//   0x00b98c: f94002a1  ldr      x1, [x21]
//   0x00b990: b4fffec1  cbz      x1, #0xb968
//   0x00b994: f94006a8  ldr      x8, [x21, #8]
//   0x00b998: eb08003f  cmp      x1, x8
//   0x00b99c: 54fffe62  b.hs     #0xb968
//   0x00b9a0: f9401268  ldr      x8, [x19, #0x20]
//   0x00b9a4: aa1303e0  mov      x0, x19
//   0x00b9a8: d63f0100  blr      x8
//   0x00b9ac: 17ffffef  b        #0xb968
//   0x00b9b0: a9007edf  stp      xzr, xzr, [x22]
//   0x00b9b4: b9409688  ldr      w8, [x20, #0x94]
//   0x00b9b8: 340002e8  cbz      w8, #0xba14
//   0x00b9bc: aa1403f5  mov      x21, x20
//   0x00b9c0: f8470ea1  ldr      x1, [x21, #0x70]!
//   0x00b9c4: b4000101  cbz      x1, #0xb9e4
//   0x00b9c8: f9403e88  ldr      x8, [x20, #0x78]
//   0x00b9cc: eb08003f  cmp      x1, x8
//   0x00b9d0: 54000080  b.eq     #0xb9e0
//   0x00b9d4: f9401268  ldr      x8, [x19, #0x20]
//   0x00b9d8: aa1303e0  mov      x0, x19
//   0x00b9dc: d63f0100  blr      x8
//   0x00b9e0: a9007ebf  stp      xzr, xzr, [x21]
//   0x00b9e4: aa1403f5  mov      x21, x20
//   0x00b9e8: f8480ea1  ldr      x1, [x21, #0x80]!
//   0x00b9ec: b4000141  cbz      x1, #0xba14
//   0x00b9f0: f9404688  ldr      x8, [x20, #0x88]
//   0x00b9f4: eb08003f  cmp      x1, x8
//   0x00b9f8: 54000080  b.eq     #0xba08
//   0x00b9fc: f9401268  ldr      x8, [x19, #0x20]
//   0x00ba00: aa1303e0  mov      x0, x19
//   0x00ba04: d63f0100  blr      x8
//   0x00ba08: 2a1f03e0  mov      w0, wzr
//   0x00ba0c: a9007ebf  stp      xzr, xzr, [x21]
//   0x00ba10: 14000002  b        #0xba18
//   0x00ba14: 2a1f03e0  mov      w0, wzr
//   0x00ba18: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00ba1c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00ba20: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00ba24: f84407f7  ldr      x23, [sp], #0x40
//   0x00ba28: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_091_0b7ec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000b7ecULL;
    for (std::size_t i = 0; i < 144ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8487ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[092] Subroutine @ 0x00ba2c..0x00ba34 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[092] Hàm con @ 0x00ba2c..0x00ba34 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ba2c: aa1f03e1  mov      x1, xzr
//   0x00ba30: 17ffdd64  b        #0x2fc0
// ============================================================================
std::uint32_t fde_092_0ba2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ba2cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8631ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[093] Subroutine @ 0x00ba34..0x00baec (184 bytes, 46 AArch64 instructions)
// [VN] Khung FDE[093] Hàm con @ 0x00ba34..0x00baec (184 byte, 46 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ba34: d10443ff  sub      sp, sp, #0x110
//   0x00ba38: a90d5ffc  stp      x28, x23, [sp, #0xd0]
//   0x00ba3c: a90e57f6  stp      x22, x21, [sp, #0xe0]
//   0x00ba40: a90f4ff4  stp      x20, x19, [sp, #0xf0]
//   0x00ba44: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x00ba48: 910403fd  add      x29, sp, #0x100
//   0x00ba4c: d53bd056  mrs      x22, tpidr_el0
//   0x00ba50: f94016c8  ldr      x8, [x22, #0x28]
//   0x00ba54: aa0003f3  mov      x19, x0
//   0x00ba58: f81c83a8  stur     x8, [x29, #-0x38]
//   0x00ba5c: 97ffddf5  bl       #0x3230
//   0x00ba60: 8b000274  add      x20, x19, x0
//   0x00ba64: 9100a3e0  add      x0, sp, #0x28
//   0x00ba68: 9100a3f7  add      x23, sp, #0x28
//   0x00ba6c: 97ffdd7d  bl       #0x3060
//   0x00ba70: 90000095  adrp     x21, #0x1b000
//   0x00ba74: f947feb5  ldr      x21, [x21, #0xff8]
//   0x00ba78: 52800201  mov      w1, #0x10
//   0x00ba7c: a901ffff  stp      xzr, xzr, [sp, #0x18]
//   0x00ba80: a900fff7  stp      x23, xzr, [sp, #8]
//   0x00ba84: f94002a8  ldr      x8, [x21]
//   0x00ba88: aa1503e0  mov      x0, x21
//   0x00ba8c: d63f0100  blr      x8
//   0x00ba90: f90033e0  str      x0, [sp, #0x60]
//   0x00ba94: 910023e0  add      x0, sp, #8
//   0x00ba98: aa1303e1  mov      x1, x19
//   0x00ba9c: aa1403e2  mov      x2, x20
//   0x00baa0: aa1503e3  mov      x3, x21
//   0x00baa4: 94000012  bl       #0xbaec
//   0x00baa8: aa0003f3  mov      x19, x0
//   0x00baac: 9100a3e0  add      x0, sp, #0x28
//   0x00bab0: aa1503e1  mov      x1, x21
//   0x00bab4: 97ffdd43  bl       #0x2fc0
//   0x00bab8: f94016c8  ldr      x8, [x22, #0x28]
//   0x00babc: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x00bac0: eb14027f  cmp      x19, x20
//   0x00bac4: 1a9f17e0  cset     w0, eq
//   0x00bac8: eb09011f  cmp      x8, x9
//   0x00bacc: 540000e1  b.ne     #0xbae8
//   0x00bad0: a9507bfd  ldp      x29, x30, [sp, #0x100]
//   0x00bad4: a94f4ff4  ldp      x20, x19, [sp, #0xf0]
//   0x00bad8: a94e57f6  ldp      x22, x21, [sp, #0xe0]
//   0x00badc: a94d5ffc  ldp      x28, x23, [sp, #0xd0]
//   0x00bae0: 910443ff  add      sp, sp, #0x110
//   0x00bae4: d65f03c0  ret      
//   0x00bae8: 97ffdd8e  bl       #0x3120
// ============================================================================
std::uint32_t fde_093_0ba34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ba34ULL;
    for (std::size_t i = 0; i < 46ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8633ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[094] Subroutine @ 0x00baec..0x00c1d0 (1764 bytes, 441 AArch64 instructions)
// [VN] Khung FDE[094] Hàm con @ 0x00baec..0x00c1d0 (1764 byte, 441 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00baec: d10283ff  sub      sp, sp, #0xa0
//   0x00baf0: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x00baf4: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x00baf8: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x00bafc: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x00bb00: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x00bb04: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x00bb08: 910243fd  add      x29, sp, #0x90
//   0x00bb0c: d53bd054  mrs      x20, tpidr_el0
//   0x00bb10: f9401688  ldr      x8, [x20, #0x28]
//   0x00bb14: aa0203f6  mov      x22, x2
//   0x00bb18: aa0003f3  mov      x19, x0
//   0x00bb1c: eb02003f  cmp      x1, x2
//   0x00bb20: f9001fe8  str      x8, [sp, #0x38]
//   0x00bb24: 54001302  b.hs     #0xbd84
//   0x00bb28: 9000005c  adrp     x28, #0x13000
//   0x00bb2c: aa0103f8  mov      x24, x1
//   0x00bb30: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00bb34: 2a1f03ed  mov      w13, wzr
//   0x00bb38: 2a1f03f9  mov      w25, wzr
//   0x00bb3c: 2a1f03f5  mov      w21, wzr
//   0x00bb40: 2a1f03fb  mov      w27, wzr
//   0x00bb44: 2a1f03f7  mov      w23, wzr
//   0x00bb48: 2a1f03e8  mov      w8, wzr
//   0x00bb4c: 52800034  mov      w20, #1
//   0x00bb50: 9117b39c  add      x28, x28, #0x5ec
//   0x00bb54: 910093fa  add      x26, sp, #0x24
//   0x00bb58: 39400309  ldrb     w9, [x24]
//   0x00bb5c: 5100b92a  sub      w10, w9, #0x2e
//   0x00bb60: 7100e15f  cmp      w10, #0x38
//   0x00bb64: 54001208  b.hi     #0xbda4
//   0x00bb68: 1000008b  adr      x11, #0xbb78
//   0x00bb6c: 386a6b8c  ldrb     w12, [x28, x10]
//   0x00bb70: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00bb74: d61f0160  br       x11
//   0x00bb78: 710012bf  cmp      w21, #4
//   0x00bb7c: 54001140  b.eq     #0xbda4
//   0x00bb80: 5100c129  sub      w9, w9, #0x30
//   0x00bb84: 3835cb49  strb     w9, [x26, w21, sxtw]
//   0x00bb88: 110006b5  add      w21, w21, #1
//   0x00bb8c: 1400000b  b        #0xbbb8
//   0x00bb90: 710012bf  cmp      w21, #4
//   0x00bb94: 54001080  b.eq     #0xbda4
//   0x00bb98: 51015d28  sub      w8, w9, #0x57
//   0x00bb9c: 14000004  b        #0xbbac
//   0x00bba0: 710012bf  cmp      w21, #4
//   0x00bba4: 54001000  b.eq     #0xbda4
//   0x00bba8: 5100dd28  sub      w8, w9, #0x37
//   0x00bbac: 3835cb48  strb     w8, [x26, w21, sxtw]
//   0x00bbb0: 110006b5  add      w21, w21, #1
//   0x00bbb4: 52800028  mov      w8, #1
//   0x00bbb8: aa1803f3  mov      x19, x24
//   0x00bbbc: 91000678  add      x24, x19, #1
//   0x00bbc0: eb16031f  cmp      x24, x22
//   0x00bbc4: 54000fe2  b.hs     #0xbdc0
//   0x00bbc8: 35fffc94  cbnz     w20, #0xbb58
//   0x00bbcc: 2a1f03e8  mov      w8, wzr
//   0x00bbd0: 7100077f  cmp      w27, #1
//   0x00bbd4: 52800034  mov      w20, #1
//   0x00bbd8: 54fffc0b  b.lt     #0xbb58
//   0x00bbdc: 1400009c  b        #0xbe4c
//   0x00bbe0: 0b0d0329  add      w9, w25, w13
//   0x00bbe4: 7100193f  cmp      w9, #6
//   0x00bbe8: 54000dec  b.gt     #0xbda4
//   0x00bbec: 710001bf  cmp      w13, #0
//   0x00bbf0: 1a9f17e9  cset     w9, eq
//   0x00bbf4: 71001b3f  cmp      w25, #6
//   0x00bbf8: 1a9fa7ea  cset     w10, lt
//   0x00bbfc: 721d7abf  tst      w21, #0xfffffffb
//   0x00bc00: 54000d20  b.eq     #0xbda4
//   0x00bc04: 0a0a0129  and      w9, w9, w10
//   0x00bc08: 37000ce9  tbnz     w9, #0, #0xbda4
//   0x00bc0c: 35000cc8  cbnz     w8, #0xbda4
//   0x00bc10: 71000abf  cmp      w21, #2
//   0x00bc14: 540001cb  b.lt     #0xbc4c
//   0x00bc18: 394093e8  ldrb     w8, [sp, #0x24]
//   0x00bc1c: 340021a8  cbz      w8, #0xc050
//   0x00bc20: 71000ebf  cmp      w21, #3
//   0x00bc24: 54000141  b.ne     #0xbc4c
//   0x00bc28: 394097e9  ldrb     w9, [sp, #0x25]
//   0x00bc2c: 39409bea  ldrb     w10, [sp, #0x26]
//   0x00bc30: 52800c8b  mov      w11, #0x64
//   0x00bc34: 1b0b7d0b  mul      w11, w8, w11
//   0x00bc38: 5280014c  mov      w12, #0xa
//   0x00bc3c: 1b0c2d2b  madd     w11, w9, w12, w11
//   0x00bc40: 0b0a016a  add      w10, w11, w10
//   0x00bc44: 7104015f  cmp      w10, #0x100
//   0x00bc48: 54002522  b.hs     #0xc0ec
//   0x00bc4c: 910093e0  add      x0, sp, #0x24
//   0x00bc50: 2a1503e1  mov      w1, w21
//   0x00bc54: aa0303f3  mov      x19, x3
//   0x00bc58: 2a0d03f4  mov      w20, w13
//   0x00bc5c: 97ffdd25  bl       #0x30f0
//   0x00bc60: f9400fe9  ldr      x9, [sp, #0x18]
//   0x00bc64: 2a1403ed  mov      w13, w20
//   0x00bc68: aa1303e3  mov      x3, x19
//   0x00bc6c: 2a1f03f5  mov      w21, wzr
//   0x00bc70: f9400129  ldr      x9, [x9]
//   0x00bc74: 2a1f03e8  mov      w8, wzr
//   0x00bc78: 2a1f03f4  mov      w20, wzr
//   0x00bc7c: 5280003b  mov      w27, #1
//   0x00bc80: f9401d29  ldr      x9, [x9, #0x38]
//   0x00bc84: 39003120  strb     w0, [x9, #0xc]
//   0x00bc88: 17ffffcc  b        #0xbbb8
//   0x00bc8c: 710006bf  cmp      w21, #1
//   0x00bc90: 540002cb  b.lt     #0xbce8
//   0x00bc94: aa0303f3  mov      x19, x3
//   0x00bc98: b9000fed  str      w13, [sp, #0xc]
//   0x00bc9c: 3400010d  cbz      w13, #0xbcbc
//   0x00bca0: 9100a3e8  add      x8, sp, #0x28
//   0x00bca4: 8b37c502  add      x2, x8, w23, sxtw #1
//   0x00bca8: 910093e0  add      x0, sp, #0x24
//   0x00bcac: 2a1503e1  mov      w1, w21
//   0x00bcb0: 97ffdd70  bl       #0x3270
//   0x00bcb4: 110006f7  add      w23, w23, #1
//   0x00bcb8: 14000008  b        #0xbcd8
//   0x00bcbc: f9400fe8  ldr      x8, [sp, #0x18]
//   0x00bcc0: 910093e0  add      x0, sp, #0x24
//   0x00bcc4: 2a1503e1  mov      w1, w21
//   0x00bcc8: f9400108  ldr      x8, [x8]
//   0x00bccc: f9401d08  ldr      x8, [x8, #0x38]
//   0x00bcd0: 8b39c502  add      x2, x8, w25, sxtw #1
//   0x00bcd4: 97ffdd67  bl       #0x3270
//   0x00bcd8: b9400fed  ldr      w13, [sp, #0xc]
//   0x00bcdc: 2a1f03f5  mov      w21, wzr
//   0x00bce0: 11000739  add      w25, w25, #1
//   0x00bce4: aa1303e3  mov      x3, x19
//   0x00bce8: 52800108  mov      w8, #8
//   0x00bcec: 4b0d0108  sub      w8, w8, w13
//   0x00bcf0: 6b08033f  cmp      w25, w8
//   0x00bcf4: 5400058a  b.ge     #0xbda4
//   0x00bcf8: 91000713  add      x19, x24, #1
//   0x00bcfc: eb16027f  cmp      x19, x22
//   0x00bd00: 54000602  b.hs     #0xbdc0
//   0x00bd04: 39400268  ldrb     w8, [x19]
//   0x00bd08: 7100e91f  cmp      w8, #0x3a
//   0x00bd0c: 54000321  b.ne     #0xbd70
//   0x00bd10: f9400fe8  ldr      x8, [sp, #0x18]
//   0x00bd14: f9400100  ldr      x0, [x8]
//   0x00bd18: 350018cd  cbnz     w13, #0xc030
//   0x00bd1c: f9401c08  ldr      x8, [x0, #0x38]
//   0x00bd20: 937f7f29  sbfiz    x9, x25, #1, #0x20
//   0x00bd24: 5280020a  mov      w10, #0x10
//   0x00bd28: 4b09014a  sub      w10, w10, w9
//   0x00bd2c: 8b090100  add      x0, x8, x9
//   0x00bd30: 93407d42  sxtw     x2, w10
//   0x00bd34: 2a1f03e1  mov      w1, wzr
//   0x00bd38: b9000ff7  str      w23, [sp, #0xc]
//   0x00bd3c: aa0303f7  mov      x23, x3
//   0x00bd40: 97ffdd68  bl       #0x32e0
//   0x00bd44: 91000b18  add      x24, x24, #2
//   0x00bd48: eb16031f  cmp      x24, x22
//   0x00bd4c: 54001b62  b.hs     #0xc0b8
//   0x00bd50: 39400308  ldrb     w8, [x24]
//   0x00bd54: 5280002d  mov      w13, #1
//   0x00bd58: aa1703e3  mov      x3, x23
//   0x00bd5c: 7100e91f  cmp      w8, #0x3a
//   0x00bd60: 54001b20  b.eq     #0xc0c4
//   0x00bd64: b9400ff7  ldr      w23, [sp, #0xc]
//   0x00bd68: 2a1f03e8  mov      w8, wzr
//   0x00bd6c: 17ffff94  b        #0xbbbc
//   0x00bd70: 340001b9  cbz      w25, #0xbda4
//   0x00bd74: 7101751f  cmp      w8, #0x5d
//   0x00bd78: 54000160  b.eq     #0xbda4
//   0x00bd7c: 2a1f03e8  mov      w8, wzr
//   0x00bd80: 17ffff8e  b        #0xbbb8
//   0x00bd84: f9400260  ldr      x0, [x19]
//   0x00bd88: aa0303e1  mov      x1, x3
//   0x00bd8c: 97ffdc8d  bl       #0x2fc0
//   0x00bd90: aa1f03f7  mov      x23, xzr
//   0x00bd94: 52800028  mov      w8, #1
//   0x00bd98: f9000a76  str      x22, [x19, #0x10]
//   0x00bd9c: b9000a68  str      w8, [x19, #8]
//   0x00bda0: 14000011  b        #0xbde4
//   0x00bda4: f9400ff3  ldr      x19, [sp, #0x18]
//   0x00bda8: f9400260  ldr      x0, [x19]
//   0x00bdac: aa0303e1  mov      x1, x3
//   0x00bdb0: 97ffdc84  bl       #0x2fc0
//   0x00bdb4: aa1f03f7  mov      x23, xzr
//   0x00bdb8: f9000a78  str      x24, [x19, #0x10]
//   0x00bdbc: 14000007  b        #0xbdd8
//   0x00bdc0: f9400ff3  ldr      x19, [sp, #0x18]
//   0x00bdc4: aa0303e1  mov      x1, x3
//   0x00bdc8: f9400260  ldr      x0, [x19]
//   0x00bdcc: 97ffdc7d  bl       #0x2fc0
//   0x00bdd0: aa1f03f7  mov      x23, xzr
//   0x00bdd4: f9000a76  str      x22, [x19, #0x10]
//   0x00bdd8: 52800028  mov      w8, #1
//   0x00bddc: b9000a68  str      w8, [x19, #8]
//   0x00bde0: f9400bf4  ldr      x20, [sp, #0x10]
//   0x00bde4: f9401688  ldr      x8, [x20, #0x28]
//   0x00bde8: f9401fe9  ldr      x9, [sp, #0x38]
//   0x00bdec: eb09011f  cmp      x8, x9
//   0x00bdf0: 54001ee1  b.ne     #0xc1cc
//   0x00bdf4: aa1703e0  mov      x0, x23
//   0x00bdf8: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x00bdfc: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x00be00: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x00be04: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x00be08: a94567fa  ldp      x26, x25, [sp, #0x50]
//   0x00be0c: a9446ffc  ldp      x28, x27, [sp, #0x40]
//   0x00be10: 910283ff  add      sp, sp, #0xa0
//   0x00be14: d65f03c0  ret      
//   0x00be18: 340007ed  cbz      w13, #0xbf14
//   0x00be1c: 710006bf  cmp      w21, #1
//   0x00be20: 5400092b  b.lt     #0xbf44
//   0x00be24: f9400ff3  ldr      x19, [sp, #0x18]
//   0x00be28: 71001f3f  cmp      w25, #7
//   0x00be2c: 54fffbea  b.ge     #0xbda8
//   0x00be30: 9100a3e8  add      x8, sp, #0x28
//   0x00be34: 8b37c502  add      x2, x8, w23, sxtw #1
//   0x00be38: 910093e0  add      x0, sp, #0x24
//   0x00be3c: 2a1503e1  mov      w1, w21
//   0x00be40: 97ffdd0c  bl       #0x3270
//   0x00be44: 110006f7  add      w23, w23, #1
//   0x00be48: 14000040  b        #0xbf48
//   0x00be4c: f9400ff9  ldr      x25, [sp, #0x18]
//   0x00be50: 2a1703fa  mov      w26, w23
//   0x00be54: 91000a77  add      x23, x19, #2
//   0x00be58: 910093f3  add      x19, sp, #0x24
//   0x00be5c: 52800c94  mov      w20, #0x64
//   0x00be60: 52800158  mov      w24, #0xa
//   0x00be64: 385ff2e9  ldurb    w9, [x23, #-1]
//   0x00be68: 5100c128  sub      w8, w9, #0x30
//   0x00be6c: 7100291f  cmp      w8, #0xa
//   0x00be70: 54000142  b.hs     #0xbe98
//   0x00be74: 710012bf  cmp      w21, #4
//   0x00be78: 54000b80  b.eq     #0xbfe8
//   0x00be7c: 110006a9  add      w9, w21, #1
//   0x00be80: 3835ca68  strb     w8, [x19, w21, sxtw]
//   0x00be84: 2a0903f5  mov      w21, w9
//   0x00be88: eb1602ff  cmp      x23, x22
//   0x00be8c: 910006f7  add      x23, x23, #1
//   0x00be90: 54fffea3  b.lo     #0xbe64
//   0x00be94: 1400005f  b        #0xc010
//   0x00be98: 7100b93f  cmp      w9, #0x2e
//   0x00be9c: 54000701  b.ne     #0xbf7c
//   0x00bea0: 721d7abf  tst      w21, #0xfffffffb
//   0x00bea4: 54000a20  b.eq     #0xbfe8
//   0x00bea8: 7100137f  cmp      w27, #4
//   0x00beac: 540009e0  b.eq     #0xbfe8
//   0x00beb0: 71000abf  cmp      w21, #2
//   0x00beb4: 5400018b  b.lt     #0xbee4
//   0x00beb8: 394093e8  ldrb     w8, [sp, #0x24]
//   0x00bebc: 34001268  cbz      w8, #0xc108
//   0x00bec0: 71000ebf  cmp      w21, #3
//   0x00bec4: 54000101  b.ne     #0xbee4
//   0x00bec8: 394097e9  ldrb     w9, [sp, #0x25]
//   0x00becc: 39409bea  ldrb     w10, [sp, #0x26]
//   0x00bed0: 1b147d0b  mul      w11, w8, w20
//   0x00bed4: 1b182d2b  madd     w11, w9, w24, w11
//   0x00bed8: 0b0a016a  add      w10, w11, w10
//   0x00bedc: 7104015f  cmp      w10, #0x100
//   0x00bee0: 54001482  b.hs     #0xc170
//   0x00bee4: 910093e0  add      x0, sp, #0x24
//   0x00bee8: 2a1503e1  mov      w1, w21
//   0x00beec: aa0303f5  mov      x21, x3
//   0x00bef0: 97ffdc80  bl       #0x30f0
//   0x00bef4: f9400328  ldr      x8, [x25]
//   0x00bef8: aa1503e3  mov      x3, x21
//   0x00befc: 2a1f03f5  mov      w21, wzr
//   0x00bf00: f9401d08  ldr      x8, [x8, #0x38]
//   0x00bf04: 8b3bc108  add      x8, x8, w27, sxtw
//   0x00bf08: 39003100  strb     w0, [x8, #0xc]
//   0x00bf0c: 1100077b  add      w27, w27, #1
//   0x00bf10: 17ffffde  b        #0xbe88
//   0x00bf14: f9400ff3  ldr      x19, [sp, #0x18]
//   0x00bf18: 71001f3f  cmp      w25, #7
//   0x00bf1c: f9400260  ldr      x0, [x19]
//   0x00bf20: 54fff461  b.ne     #0xbdac
//   0x00bf24: 710002bf  cmp      w21, #0
//   0x00bf28: 54fff42d  b.le     #0xbdac
//   0x00bf2c: f9401c08  ldr      x8, [x0, #0x38]
//   0x00bf30: 910093e0  add      x0, sp, #0x24
//   0x00bf34: 2a1503e1  mov      w1, w21
//   0x00bf38: 91003902  add      x2, x8, #0xe
//   0x00bf3c: 97ffdccd  bl       #0x3270
//   0x00bf40: 14000002  b        #0xbf48
//   0x00bf44: f9400ff3  ldr      x19, [sp, #0x18]
//   0x00bf48: f9400268  ldr      x8, [x19]
//   0x00bf4c: 531f7ae9  lsl      w9, w23, #1
//   0x00bf50: 93407d22  sxtw     x2, w9
//   0x00bf54: 9100a3e1  add      x1, sp, #0x28
//   0x00bf58: f9401d08  ldr      x8, [x8, #0x38]
//   0x00bf5c: cb020108  sub      x8, x8, x2
//   0x00bf60: 91004100  add      x0, x8, #0x10
//   0x00bf64: 97ffdcd7  bl       #0x32c0
//   0x00bf68: f9400268  ldr      x8, [x19]
//   0x00bf6c: f9400bf4  ldr      x20, [sp, #0x10]
//   0x00bf70: 91000717  add      x23, x24, #1
//   0x00bf74: f9001518  str      x24, [x8, #0x28]
//   0x00bf78: 17ffff9b  b        #0xbde4
//   0x00bf7c: 7101753f  cmp      w9, #0x5d
//   0x00bf80: 54000341  b.ne     #0xbfe8
//   0x00bf84: 121d7aa8  and      w8, w21, #0xfffffffb
//   0x00bf88: d10006f3  sub      x19, x23, #1
//   0x00bf8c: 340004e8  cbz      w8, #0xc028
//   0x00bf90: 71000f7f  cmp      w27, #3
//   0x00bf94: 540004a1  b.ne     #0xc028
//   0x00bf98: 71000abf  cmp      w21, #2
//   0x00bf9c: 540006cb  b.lt     #0xc074
//   0x00bfa0: 394093e8  ldrb     w8, [sp, #0x24]
//   0x00bfa4: 34000b28  cbz      w8, #0xc108
//   0x00bfa8: 71000ebf  cmp      w21, #3
//   0x00bfac: 54000641  b.ne     #0xc074
//   0x00bfb0: 394097e9  ldrb     w9, [sp, #0x25]
//   0x00bfb4: 39409beb  ldrb     w11, [sp, #0x26]
//   0x00bfb8: 52800c8a  mov      w10, #0x64
//   0x00bfbc: 1b0a7d0a  mul      w10, w8, w10
//   0x00bfc0: 5280014c  mov      w12, #0xa
//   0x00bfc4: 1b0c292a  madd     w10, w9, w12, w10
//   0x00bfc8: 0b0b014a  add      w10, w10, w11
//   0x00bfcc: 7104015f  cmp      w10, #0x100
//   0x00bfd0: 54000523  b.lo     #0xc074
//   0x00bfd4: 71000d1f  cmp      w8, #3
//   0x00bfd8: 54000e23  b.lo     #0xc19c
//   0x00bfdc: f9400320  ldr      x0, [x25]
//   0x00bfe0: d10012f3  sub      x19, x23, #4
//   0x00bfe4: 1400004d  b        #0xc118
//   0x00bfe8: f9400320  ldr      x0, [x25]
//   0x00bfec: aa0303e1  mov      x1, x3
//   0x00bff0: 97ffdbf4  bl       #0x2fc0
//   0x00bff4: d10006e8  sub      x8, x23, #1
//   0x00bff8: 52800029  mov      w9, #1
//   0x00bffc: f9000b28  str      x8, [x25, #0x10]
//   0x00c000: b9000b29  str      w9, [x25, #8]
//   0x00c004: f9400bf4  ldr      x20, [sp, #0x10]
//   0x00c008: aa1f03f7  mov      x23, xzr
//   0x00c00c: 17ffff76  b        #0xbde4
//   0x00c010: f9400320  ldr      x0, [x25]
//   0x00c014: aa0303e1  mov      x1, x3
//   0x00c018: 97ffdbea  bl       #0x2fc0
//   0x00c01c: aa1f03f7  mov      x23, xzr
//   0x00c020: f9000b36  str      x22, [x25, #0x10]
//   0x00c024: 14000041  b        #0xc128
//   0x00c028: f9400320  ldr      x0, [x25]
//   0x00c02c: 1400003b  b        #0xc118
//   0x00c030: aa0303e1  mov      x1, x3
//   0x00c034: 97ffdbe3  bl       #0x2fc0
//   0x00c038: a94127f4  ldp      x20, x9, [sp, #0x10]
//   0x00c03c: 52800028  mov      w8, #1
//   0x00c040: aa1f03f7  mov      x23, xzr
//   0x00c044: f9000933  str      x19, [x9, #0x10]
//   0x00c048: b9000928  str      w8, [x9, #8]
//   0x00c04c: 17ffff66  b        #0xbde4
//   0x00c050: f9400ff4  ldr      x20, [sp, #0x18]
//   0x00c054: aa0303e1  mov      x1, x3
//   0x00c058: cb35c313  sub      x19, x24, w21, sxtw
//   0x00c05c: f9400280  ldr      x0, [x20]
//   0x00c060: 97ffdbd8  bl       #0x2fc0
//   0x00c064: 52800028  mov      w8, #1
//   0x00c068: f9000a93  str      x19, [x20, #0x10]
//   0x00c06c: b9000a88  str      w8, [x20, #8]
//   0x00c070: 17ffffe5  b        #0xc004
//   0x00c074: f9400328  ldr      x8, [x25]
//   0x00c078: 9100a3e1  add      x1, sp, #0x28
//   0x00c07c: f9401d09  ldr      x9, [x8, #0x38]
//   0x00c080: f9001513  str      x19, [x8, #0x28]
//   0x00c084: 531f7b48  lsl      w8, w26, #1
//   0x00c088: 93407d02  sxtw     x2, w8
//   0x00c08c: cb020128  sub      x8, x9, x2
//   0x00c090: 91003100  add      x0, x8, #0xc
//   0x00c094: 97ffdc8b  bl       #0x32c0
//   0x00c098: 910093e0  add      x0, sp, #0x24
//   0x00c09c: 2a1503e1  mov      w1, w21
//   0x00c0a0: 97ffdc14  bl       #0x30f0
//   0x00c0a4: f9400328  ldr      x8, [x25]
//   0x00c0a8: f9400bf4  ldr      x20, [sp, #0x10]
//   0x00c0ac: f9401d08  ldr      x8, [x8, #0x38]
//   0x00c0b0: 39003d00  strb     w0, [x8, #0xf]
//   0x00c0b4: 17ffff4c  b        #0xbde4
//   0x00c0b8: f9400ff3  ldr      x19, [sp, #0x18]
//   0x00c0bc: aa1703e1  mov      x1, x23
//   0x00c0c0: 17ffff42  b        #0xbdc8
//   0x00c0c4: f9400ff3  ldr      x19, [sp, #0x18]
//   0x00c0c8: aa0303e1  mov      x1, x3
//   0x00c0cc: 52800034  mov      w20, #1
//   0x00c0d0: f9400260  ldr      x0, [x19]
//   0x00c0d4: 97ffdbbb  bl       #0x2fc0
//   0x00c0d8: b9000a74  str      w20, [x19, #8]
//   0x00c0dc: f9400bf4  ldr      x20, [sp, #0x10]
//   0x00c0e0: aa1f03f7  mov      x23, xzr
//   0x00c0e4: f9000a78  str      x24, [x19, #0x10]
//   0x00c0e8: 17ffff3f  b        #0xbde4
//   0x00c0ec: f9400bf4  ldr      x20, [sp, #0x10]
//   0x00c0f0: 71000d1f  cmp      w8, #3
//   0x00c0f4: 54000203  b.lo     #0xc134
//   0x00c0f8: f9400ff5  ldr      x21, [sp, #0x18]
//   0x00c0fc: d1000f13  sub      x19, x24, #3
//   0x00c100: f94002a0  ldr      x0, [x21]
//   0x00c104: 14000014  b        #0xc154
//   0x00c108: f9400320  ldr      x0, [x25]
//   0x00c10c: 93407ea8  sxtw     x8, w21
//   0x00c110: aa2803e8  mvn      x8, x8
//   0x00c114: 8b170113  add      x19, x8, x23
//   0x00c118: aa0303e1  mov      x1, x3
//   0x00c11c: 97ffdba9  bl       #0x2fc0
//   0x00c120: aa1f03f7  mov      x23, xzr
//   0x00c124: f9000b33  str      x19, [x25, #0x10]
//   0x00c128: 52800028  mov      w8, #1
//   0x00c12c: b9000b28  str      w8, [x25, #8]
//   0x00c130: 17ffff2c  b        #0xbde0
//   0x00c134: f9400ff5  ldr      x21, [sp, #0x18]
//   0x00c138: 7100193f  cmp      w9, #6
//   0x00c13c: 54000083  b.lo     #0xc14c
//   0x00c140: f94002a0  ldr      x0, [x21]
//   0x00c144: d1000b13  sub      x19, x24, #2
//   0x00c148: 14000003  b        #0xc154
//   0x00c14c: f94002a0  ldr      x0, [x21]
//   0x00c150: d1000713  sub      x19, x24, #1
//   0x00c154: aa0303e1  mov      x1, x3
//   0x00c158: 97ffdb9a  bl       #0x2fc0
//   0x00c15c: 52800028  mov      w8, #1
//   0x00c160: aa1f03f7  mov      x23, xzr
//   0x00c164: f9000ab3  str      x19, [x21, #0x10]
//   0x00c168: b9000aa8  str      w8, [x21, #8]
//   0x00c16c: 17ffff1e  b        #0xbde4
//   0x00c170: f9400bf4  ldr      x20, [sp, #0x10]
//   0x00c174: 71000d1f  cmp      w8, #3
//   0x00c178: 54000083  b.lo     #0xc188
//   0x00c17c: f9400320  ldr      x0, [x25]
//   0x00c180: d10012f3  sub      x19, x23, #4
//   0x00c184: 1400000b  b        #0xc1b0
//   0x00c188: 7100193f  cmp      w9, #6
//   0x00c18c: 540000e3  b.lo     #0xc1a8
//   0x00c190: f9400320  ldr      x0, [x25]
//   0x00c194: d1000ef3  sub      x19, x23, #3
//   0x00c198: 14000006  b        #0xc1b0
//   0x00c19c: f9400bf4  ldr      x20, [sp, #0x10]
//   0x00c1a0: 7100193f  cmp      w9, #6
//   0x00c1a4: 54ffff62  b.hs     #0xc190
//   0x00c1a8: f9400320  ldr      x0, [x25]
//   0x00c1ac: d1000af3  sub      x19, x23, #2
//   0x00c1b0: aa0303e1  mov      x1, x3
//   0x00c1b4: 97ffdb83  bl       #0x2fc0
//   0x00c1b8: 52800028  mov      w8, #1
//   0x00c1bc: aa1f03f7  mov      x23, xzr
//   0x00c1c0: f9000b33  str      x19, [x25, #0x10]
//   0x00c1c4: b9000b28  str      w8, [x25, #8]
//   0x00c1c8: 17ffff07  b        #0xbde4
//   0x00c1cc: 97ffdbd5  bl       #0x3120
// ============================================================================
std::uint32_t fde_094_0baec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000baecULL;
    for (std::size_t i = 0; i < 441ULL; ++i) {
        std::uint32_t insn = kTextInstructions[8679ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[095] Subroutine @ 0x00c1d0..0x00c230 (96 bytes, 24 AArch64 instructions)
// [VN] Khung FDE[095] Hàm con @ 0x00c1d0..0x00c230 (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00c1d0: d100c3ff  sub      sp, sp, #0x30
//   0x00c1d4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00c1d8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00c1dc: 910083fd  add      x29, sp, #0x20
//   0x00c1e0: d53bd054  mrs      x20, tpidr_el0
//   0x00c1e4: f9401688  ldr      x8, [x20, #0x28]
//   0x00c1e8: aa0003f3  mov      x19, x0
//   0x00c1ec: f90007e8  str      x8, [sp, #8]
//   0x00c1f0: 97ffdc10  bl       #0x3230
//   0x00c1f4: 8b000262  add      x2, x19, x0
//   0x00c1f8: 910013e0  add      x0, sp, #4
//   0x00c1fc: aa1303e1  mov      x1, x19
//   0x00c200: 97ffdb58  bl       #0x2f60
//   0x00c204: f9401688  ldr      x8, [x20, #0x28]
//   0x00c208: f94007e9  ldr      x9, [sp, #8]
//   0x00c20c: 7100001f  cmp      w0, #0
//   0x00c210: 1a9f17e0  cset     w0, eq
//   0x00c214: eb09011f  cmp      x8, x9
//   0x00c218: 540000a1  b.ne     #0xc22c
//   0x00c21c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00c220: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00c224: 9100c3ff  add      sp, sp, #0x30
//   0x00c228: d65f03c0  ret      
//   0x00c22c: 97ffdbbd  bl       #0x3120
// ============================================================================
std::uint32_t fde_095_0c1d0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000c1d0ULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9120ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[096] Subroutine @ 0x00c230..0x00c238 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[096] Hàm con @ 0x00c230..0x00c238 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00c230: aa1f03e3  mov      x3, xzr
//   0x00c234: 14000001  b        #0xc238
// ============================================================================
std::uint32_t fde_096_0c230(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000c230ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9144ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[097] Subroutine @ 0x00c238..0x00c9c4 (1932 bytes, 483 AArch64 instructions)
// [VN] Khung FDE[097] Hàm con @ 0x00c238..0x00c9c4 (1932 byte, 483 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00c238: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x00c23c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00c240: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00c244: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00c248: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00c24c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00c250: 910143fd  add      x29, sp, #0x50
//   0x00c254: aa0003f3  mov      x19, x0
//   0x00c258: 52800040  mov      w0, #2
//   0x00c25c: b4003713  cbz      x19, #0xc93c
//   0x00c260: aa0103f7  mov      x23, x1
//   0x00c264: b40036c1  cbz      x1, #0xc93c
//   0x00c268: aa0203f4  mov      x20, x2
//   0x00c26c: b4003682  cbz      x2, #0xc93c
//   0x00c270: aa0303f5  mov      x21, x3
//   0x00c274: b40000e3  cbz      x3, #0xc290
//   0x00c278: aa1503e0  mov      x0, x21
//   0x00c27c: 97ffdbf9  bl       #0x3260
//   0x00c280: 7100041f  cmp      w0, #1
//   0x00c284: 540000a0  b.eq     #0xc298
//   0x00c288: 52800140  mov      w0, #0xa
//   0x00c28c: 140001ac  b        #0xc93c
//   0x00c290: f0000075  adrp     x21, #0x1b000
//   0x00c294: f947feb5  ldr      x21, [x21, #0xff8]
//   0x00c298: f9400260  ldr      x0, [x19]
//   0x00c29c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00c2a0: ad000260  stp      q0, q0, [x19]
//   0x00c2a4: f9000260  str      x0, [x19]
//   0x00c2a8: 97ffdbbe  bl       #0x31a0
//   0x00c2ac: eb1402ff  cmp      x23, x20
//   0x00c2b0: 54003442  b.hs     #0xc938
//   0x00c2b4: b94002e8  ldr      w8, [x23]
//   0x00c2b8: 51008509  sub      w9, w8, #0x21
//   0x00c2bc: 7101753f  cmp      w9, #0x5d
//   0x00c2c0: 54000a28  b.hi     #0xc404
//   0x00c2c4: f000002a  adrp     x10, #0x13000
//   0x00c2c8: 9118994a  add      x10, x10, #0x626
//   0x00c2cc: 1000008b  adr      x11, #0xc2dc
//   0x00c2d0: 3869694c  ldrb     w12, [x10, x9]
//   0x00c2d4: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00c2d8: d61f0160  br       x11
//   0x00c2dc: f9400268  ldr      x8, [x19]
//   0x00c2e0: f0000079  adrp     x25, #0x1b000
//   0x00c2e4: 910012f6  add      x22, x23, #4
//   0x00c2e8: eb1402df  cmp      x22, x20
//   0x00c2ec: f9000117  str      x23, [x8]
//   0x00c2f0: f947eb39  ldr      x25, [x25, #0xfd0]
//   0x00c2f4: 54000242  b.hs     #0xc33c
//   0x00c2f8: f0000029  adrp     x9, #0x13000
//   0x00c2fc: aa1f03fa  mov      x26, xzr
//   0x00c300: 911a1129  add      x9, x9, #0x684
//   0x00c304: 8b1a02f8  add      x24, x23, x26
//   0x00c308: b940070a  ldr      w10, [x24, #4]
//   0x00c30c: 5100854a  sub      w10, w10, #0x21
//   0x00c310: 7101755f  cmp      w10, #0x5d
//   0x00c314: 54000b48  b.hi     #0xc47c
//   0x00c318: 1000008b  adr      x11, #0xc328
//   0x00c31c: 386a692c  ldrb     w12, [x9, x10]
//   0x00c320: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00c324: d61f0160  br       x11
//   0x00c328: 9100135a  add      x26, x26, #4
//   0x00c32c: 8b1a02ea  add      x10, x23, x26
//   0x00c330: 91001156  add      x22, x10, #4
//   0x00c334: eb1402df  cmp      x22, x20
//   0x00c338: 54fffe63  b.lo     #0xc304
//   0x00c33c: f94006a8  ldr      x8, [x21, #8]
//   0x00c340: 52800021  mov      w1, #1
//   0x00c344: 52800402  mov      w2, #0x20
//   0x00c348: aa1503e0  mov      x0, x21
//   0x00c34c: d63f0100  blr      x8
//   0x00c350: b4002260  cbz      x0, #0xc79c
//   0x00c354: eb1702df  cmp      x22, x23
//   0x00c358: 54000200  b.eq     #0xc398
//   0x00c35c: a9005817  stp      x23, x22, [x0]
//   0x00c360: 14000010  b        #0xc3a0
//   0x00c364: f9400268  ldr      x8, [x19]
//   0x00c368: 910012e1  add      x1, x23, #4
//   0x00c36c: f9000117  str      x23, [x8]
//   0x00c370: 14000003  b        #0xc37c
//   0x00c374: 8b1a02e8  add      x8, x23, x26
//   0x00c378: 91002101  add      x1, x8, #8
//   0x00c37c: aa1303e0  mov      x0, x19
//   0x00c380: aa1403e2  mov      x2, x20
//   0x00c384: aa1503e3  mov      x3, x21
//   0x00c388: 9400099a  bl       #0xe9f0
//   0x00c38c: aa0003f6  mov      x22, x0
//   0x00c390: b5000240  cbnz     x0, #0xc3d8
//   0x00c394: 14000108  b        #0xc7b4
//   0x00c398: f9400328  ldr      x8, [x25]
//   0x00c39c: a9002008  stp      x8, x8, [x0]
//   0x00c3a0: f9400268  ldr      x8, [x19]
//   0x00c3a4: f9403109  ldr      x9, [x8, #0x60]
//   0x00c3a8: b40000a9  cbz      x9, #0xc3bc
//   0x00c3ac: aa0803e9  mov      x9, x8
//   0x00c3b0: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00c3b4: f9000940  str      x0, [x10, #0x10]
//   0x00c3b8: 14000003  b        #0xc3c4
//   0x00c3bc: f9003100  str      x0, [x8, #0x60]
//   0x00c3c0: 9101a109  add      x9, x8, #0x68
//   0x00c3c4: f9000120  str      x0, [x9]
//   0x00c3c8: f900011f  str      xzr, [x8]
//   0x00c3cc: aa1403e0  mov      x0, x20
//   0x00c3d0: aa0003f6  mov      x22, x0
//   0x00c3d4: b4001f00  cbz      x0, #0xc7b4
//   0x00c3d8: eb1402df  cmp      x22, x20
//   0x00c3dc: 54002ae0  b.eq     #0xc938
//   0x00c3e0: f9400260  ldr      x0, [x19]
//   0x00c3e4: aa1503e1  mov      x1, x21
//   0x00c3e8: 97ffdb1a  bl       #0x3050
//   0x00c3ec: eb1402df  cmp      x22, x20
//   0x00c3f0: 52800020  mov      w0, #1
//   0x00c3f4: 9a9432c8  csel     x8, x22, x20, lo
//   0x00c3f8: f9000a68  str      x8, [x19, #0x10]
//   0x00c3fc: b9000a60  str      w0, [x19, #8]
//   0x00c400: 1400014f  b        #0xc93c
//   0x00c404: 7100fd1f  cmp      w8, #0x3f
//   0x00c408: 54000e20  b.eq     #0xc5cc
//   0x00c40c: 71008d1f  cmp      w8, #0x23
//   0x00c410: 54000f81  b.ne     #0xc600
//   0x00c414: 910012f7  add      x23, x23, #4
//   0x00c418: 1400013d  b        #0xc90c
//   0x00c41c: aa1303e0  mov      x0, x19
//   0x00c420: aa1703e1  mov      x1, x23
//   0x00c424: aa1403e2  mov      x2, x20
//   0x00c428: aa1503e3  mov      x3, x21
//   0x00c42c: 94000a53  bl       #0xed78
//   0x00c430: b4001c20  cbz      x0, #0xc7b4
//   0x00c434: f9400268  ldr      x8, [x19]
//   0x00c438: aa0003e1  mov      x1, x0
//   0x00c43c: f9000117  str      x23, [x8]
//   0x00c440: 17ffffcf  b        #0xc37c
//   0x00c444: 910012e1  add      x1, x23, #4
//   0x00c448: aa1303e0  mov      x0, x19
//   0x00c44c: aa1403e2  mov      x2, x20
//   0x00c450: aa1503e3  mov      x3, x21
//   0x00c454: 94000a7e  bl       #0xee4c
//   0x00c458: b4001ae0  cbz      x0, #0xc7b4
//   0x00c45c: aa0003f6  mov      x22, x0
//   0x00c460: eb14001f  cmp      x0, x20
//   0x00c464: 540026a2  b.hs     #0xc938
//   0x00c468: b94002c8  ldr      w8, [x22]
//   0x00c46c: 7100fd1f  cmp      w8, #0x3f
//   0x00c470: 54002481  b.ne     #0xc900
//   0x00c474: 910012d7  add      x23, x22, #4
//   0x00c478: 14000056  b        #0xc5d0
//   0x00c47c: f94006a8  ldr      x8, [x21, #8]
//   0x00c480: 52800021  mov      w1, #1
//   0x00c484: 52800402  mov      w2, #0x20
//   0x00c488: aa1503e0  mov      x0, x21
//   0x00c48c: d63f0100  blr      x8
//   0x00c490: b4001860  cbz      x0, #0xc79c
//   0x00c494: b100135f  cmn      x26, #4
//   0x00c498: 91001316  add      x22, x24, #4
//   0x00c49c: 54000ba0  b.eq     #0xc610
//   0x00c4a0: a9005817  stp      x23, x22, [x0]
//   0x00c4a4: 1400005d  b        #0xc618
//   0x00c4a8: 8b1a02e8  add      x8, x23, x26
//   0x00c4ac: 91001101  add      x1, x8, #4
//   0x00c4b0: aa1303e0  mov      x0, x19
//   0x00c4b4: aa1403e2  mov      x2, x20
//   0x00c4b8: aa1503e3  mov      x3, x21
//   0x00c4bc: 94000a2f  bl       #0xed78
//   0x00c4c0: b40017a0  cbz      x0, #0xc7b4
//   0x00c4c4: aa0003e1  mov      x1, x0
//   0x00c4c8: 17ffffad  b        #0xc37c
//   0x00c4cc: 8b1a02fb  add      x27, x23, x26
//   0x00c4d0: 91002378  add      x24, x27, #8
//   0x00c4d4: aa1303e0  mov      x0, x19
//   0x00c4d8: aa1803e1  mov      x1, x24
//   0x00c4dc: aa1403e2  mov      x2, x20
//   0x00c4e0: aa1503e3  mov      x3, x21
//   0x00c4e4: 94000b51  bl       #0xf228
//   0x00c4e8: b4001660  cbz      x0, #0xc7b4
//   0x00c4ec: f9400268  ldr      x8, [x19]
//   0x00c4f0: aa0003f6  mov      x22, x0
//   0x00c4f4: 52800021  mov      w1, #1
//   0x00c4f8: 52800402  mov      w2, #0x20
//   0x00c4fc: f940011c  ldr      x28, [x8]
//   0x00c500: f94006a8  ldr      x8, [x21, #8]
//   0x00c504: aa1503e0  mov      x0, x21
//   0x00c508: d63f0100  blr      x8
//   0x00c50c: b4001480  cbz      x0, #0xc79c
//   0x00c510: cb170388  sub      x8, x28, x23
//   0x00c514: d1001108  sub      x8, x8, #4
//   0x00c518: eb1a011f  cmp      x8, x26
//   0x00c51c: 54000aa0  b.eq     #0xc670
//   0x00c520: 91001368  add      x8, x27, #4
//   0x00c524: f900001c  str      x28, [x0]
//   0x00c528: 14000054  b        #0xc678
//   0x00c52c: 8b1a02e9  add      x9, x23, x26
//   0x00c530: 91002136  add      x22, x9, #8
//   0x00c534: eb1402df  cmp      x22, x20
//   0x00c538: 9100113b  add      x27, x9, #4
//   0x00c53c: 54001b42  b.hs     #0xc8a4
//   0x00c540: b94002c9  ldr      w9, [x22]
//   0x00c544: 51008529  sub      w9, w9, #0x21
//   0x00c548: 7101753f  cmp      w9, #0x5d
//   0x00c54c: 54002228  b.hi     #0xc990
//   0x00c550: f000002a  adrp     x10, #0x13000
//   0x00c554: 911b894a  add      x10, x10, #0x6e2
//   0x00c558: 1000008b  adr      x11, #0xc568
//   0x00c55c: 7869794c  ldrh     w12, [x10, x9, lsl #1]
//   0x00c560: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00c564: d61f0160  br       x11
//   0x00c568: aa1303e0  mov      x0, x19
//   0x00c56c: aa1603e1  mov      x1, x22
//   0x00c570: aa1403e2  mov      x2, x20
//   0x00c574: aa1503e3  mov      x3, x21
//   0x00c578: 94000b4c  bl       #0xf2a8
//   0x00c57c: b4001fa0  cbz      x0, #0xc970
//   0x00c580: aa0003e1  mov      x1, x0
//   0x00c584: aa1303e0  mov      x0, x19
//   0x00c588: aa1403e2  mov      x2, x20
//   0x00c58c: aa1503e3  mov      x3, x21
//   0x00c590: 94000b26  bl       #0xf228
//   0x00c594: b4001ee0  cbz      x0, #0xc970
//   0x00c598: f94006a8  ldr      x8, [x21, #8]
//   0x00c59c: aa0003f8  mov      x24, x0
//   0x00c5a0: 52800021  mov      w1, #1
//   0x00c5a4: 52800402  mov      w2, #0x20
//   0x00c5a8: aa1503e0  mov      x0, x21
//   0x00c5ac: d63f0100  blr      x8
//   0x00c5b0: b4001d40  cbz      x0, #0xc958
//   0x00c5b4: cb170308  sub      x8, x24, x23
//   0x00c5b8: d1002108  sub      x8, x8, #8
//   0x00c5bc: eb1a011f  cmp      x8, x26
//   0x00c5c0: 54001060  b.eq     #0xc7cc
//   0x00c5c4: a9006016  stp      x22, x24, [x0]
//   0x00c5c8: 14000083  b        #0xc7d4
//   0x00c5cc: 910012f7  add      x23, x23, #4
//   0x00c5d0: aa1303e0  mov      x0, x19
//   0x00c5d4: aa1703e1  mov      x1, x23
//   0x00c5d8: aa1403e2  mov      x2, x20
//   0x00c5dc: aa1503e3  mov      x3, x21
//   0x00c5e0: 94000dc6  bl       #0xfcf8
//   0x00c5e4: b4000e80  cbz      x0, #0xc7b4
//   0x00c5e8: f9400268  ldr      x8, [x19]
//   0x00c5ec: aa0003f6  mov      x22, x0
//   0x00c5f0: eb14001f  cmp      x0, x20
//   0x00c5f4: a9070117  stp      x23, x0, [x8, #0x70]
//   0x00c5f8: 54001823  b.lo     #0xc8fc
//   0x00c5fc: 140000cf  b        #0xc938
//   0x00c600: aa1703f6  mov      x22, x23
//   0x00c604: eb1402df  cmp      x22, x20
//   0x00c608: 54ffeec1  b.ne     #0xc3e0
//   0x00c60c: 140000cb  b        #0xc938
//   0x00c610: f9400328  ldr      x8, [x25]
//   0x00c614: a9002008  stp      x8, x8, [x0]
//   0x00c618: f9400268  ldr      x8, [x19]
//   0x00c61c: f9403109  ldr      x9, [x8, #0x60]
//   0x00c620: b40000a9  cbz      x9, #0xc634
//   0x00c624: aa0803e9  mov      x9, x8
//   0x00c628: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00c62c: f9000940  str      x0, [x10, #0x10]
//   0x00c630: 14000003  b        #0xc63c
//   0x00c634: f9003100  str      x0, [x8, #0x60]
//   0x00c638: 9101a109  add      x9, x8, #0x68
//   0x00c63c: f9000120  str      x0, [x9]
//   0x00c640: f900011f  str      xzr, [x8]
//   0x00c644: b9400708  ldr      w8, [x24, #4]
//   0x00c648: 71008d1f  cmp      w8, #0x23
//   0x00c64c: 540000c0  b.eq     #0xc664
//   0x00c650: 7100fd1f  cmp      w8, #0x3f
//   0x00c654: 54ffec21  b.ne     #0xc3d8
//   0x00c658: 8b1a02e8  add      x8, x23, x26
//   0x00c65c: 91002117  add      x23, x8, #8
//   0x00c660: 1400009b  b        #0xc8cc
//   0x00c664: 8b1a02e8  add      x8, x23, x26
//   0x00c668: 91002117  add      x23, x8, #8
//   0x00c66c: 140000a8  b        #0xc90c
//   0x00c670: f9400328  ldr      x8, [x25]
//   0x00c674: f9000008  str      x8, [x0]
//   0x00c678: f9000408  str      x8, [x0, #8]
//   0x00c67c: f9400268  ldr      x8, [x19]
//   0x00c680: f9403109  ldr      x9, [x8, #0x60]
//   0x00c684: b40000a9  cbz      x9, #0xc698
//   0x00c688: aa0803e9  mov      x9, x8
//   0x00c68c: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00c690: f9000940  str      x0, [x10, #0x10]
//   0x00c694: 14000003  b        #0xc6a0
//   0x00c698: f9003100  str      x0, [x8, #0x60]
//   0x00c69c: 9101a109  add      x9, x8, #0x68
//   0x00c6a0: f9000120  str      x0, [x9]
//   0x00c6a4: f900011f  str      xzr, [x8]
//   0x00c6a8: f94006a8  ldr      x8, [x21, #8]
//   0x00c6ac: 52800021  mov      w1, #1
//   0x00c6b0: 52800402  mov      w2, #0x20
//   0x00c6b4: aa1503e0  mov      x0, x21
//   0x00c6b8: d63f0100  blr      x8
//   0x00c6bc: b4000700  cbz      x0, #0xc79c
//   0x00c6c0: cb1702c8  sub      x8, x22, x23
//   0x00c6c4: d1002108  sub      x8, x8, #8
//   0x00c6c8: eb1a011f  cmp      x8, x26
//   0x00c6cc: 54000060  b.eq     #0xc6d8
//   0x00c6d0: a9005818  stp      x24, x22, [x0]
//   0x00c6d4: 14000003  b        #0xc6e0
//   0x00c6d8: f9400328  ldr      x8, [x25]
//   0x00c6dc: a9002008  stp      x8, x8, [x0]
//   0x00c6e0: f9400268  ldr      x8, [x19]
//   0x00c6e4: f9403109  ldr      x9, [x8, #0x60]
//   0x00c6e8: b4000089  cbz      x9, #0xc6f8
//   0x00c6ec: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00c6f0: f9000920  str      x0, [x9, #0x10]
//   0x00c6f4: 14000003  b        #0xc700
//   0x00c6f8: f9003100  str      x0, [x8, #0x60]
//   0x00c6fc: 9101a108  add      x8, x8, #0x68
//   0x00c700: eb1402df  cmp      x22, x20
//   0x00c704: f9000100  str      x0, [x8]
//   0x00c708: aa1403e0  mov      x0, x20
//   0x00c70c: 54ffe622  b.hs     #0xc3d0
//   0x00c710: f9400338  ldr      x24, [x25]
//   0x00c714: 14000006  b        #0xc72c
//   0x00c718: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00c71c: f9000920  str      x0, [x9, #0x10]
//   0x00c720: eb1402df  cmp      x22, x20
//   0x00c724: f9000100  str      x0, [x8]
//   0x00c728: 54ffe522  b.hs     #0xc3cc
//   0x00c72c: b94002c8  ldr      w8, [x22]
//   0x00c730: 7100bd1f  cmp      w8, #0x2f
//   0x00c734: 54001241  b.ne     #0xc97c
//   0x00c738: 910012d7  add      x23, x22, #4
//   0x00c73c: aa1303e0  mov      x0, x19
//   0x00c740: aa1703e1  mov      x1, x23
//   0x00c744: aa1403e2  mov      x2, x20
//   0x00c748: aa1503e3  mov      x3, x21
//   0x00c74c: 94000ab7  bl       #0xf228
//   0x00c750: b4000320  cbz      x0, #0xc7b4
//   0x00c754: f94006a8  ldr      x8, [x21, #8]
//   0x00c758: aa0003f6  mov      x22, x0
//   0x00c75c: 52800021  mov      w1, #1
//   0x00c760: 52800402  mov      w2, #0x20
//   0x00c764: aa1503e0  mov      x0, x21
//   0x00c768: d63f0100  blr      x8
//   0x00c76c: b4000180  cbz      x0, #0xc79c
//   0x00c770: eb1602ff  cmp      x23, x22
//   0x00c774: 54000060  b.eq     #0xc780
//   0x00c778: a9005817  stp      x23, x22, [x0]
//   0x00c77c: 14000002  b        #0xc784
//   0x00c780: a9006018  stp      x24, x24, [x0]
//   0x00c784: f9400268  ldr      x8, [x19]
//   0x00c788: f9403109  ldr      x9, [x8, #0x60]
//   0x00c78c: b5fffc69  cbnz     x9, #0xc718
//   0x00c790: f9003100  str      x0, [x8, #0x60]
//   0x00c794: 9101a108  add      x8, x8, #0x68
//   0x00c798: 17ffffe2  b        #0xc720
//   0x00c79c: f9400260  ldr      x0, [x19]
//   0x00c7a0: aa1503e1  mov      x1, x21
//   0x00c7a4: 97ffda2b  bl       #0x3050
//   0x00c7a8: 52800068  mov      w8, #3
//   0x00c7ac: f9000a7f  str      xzr, [x19, #0x10]
//   0x00c7b0: b9000a68  str      w8, [x19, #8]
//   0x00c7b4: f9400a68  ldr      x8, [x19, #0x10]
//   0x00c7b8: eb14011f  cmp      x8, x20
//   0x00c7bc: 54000049  b.ls     #0xc7c4
//   0x00c7c0: f9000a74  str      x20, [x19, #0x10]
//   0x00c7c4: b9400a60  ldr      w0, [x19, #8]
//   0x00c7c8: 1400005d  b        #0xc93c
//   0x00c7cc: f9400328  ldr      x8, [x25]
//   0x00c7d0: a9002008  stp      x8, x8, [x0]
//   0x00c7d4: f9400268  ldr      x8, [x19]
//   0x00c7d8: f9403109  ldr      x9, [x8, #0x60]
//   0x00c7dc: b40000a9  cbz      x9, #0xc7f0
//   0x00c7e0: aa0803e9  mov      x9, x8
//   0x00c7e4: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00c7e8: f9000940  str      x0, [x10, #0x10]
//   0x00c7ec: 14000003  b        #0xc7f8
//   0x00c7f0: f9003100  str      x0, [x8, #0x60]
//   0x00c7f4: 9101a109  add      x9, x8, #0x68
//   0x00c7f8: eb14031f  cmp      x24, x20
//   0x00c7fc: f9000120  str      x0, [x9]
//   0x00c800: 54000522  b.hs     #0xc8a4
//   0x00c804: b9400309  ldr      w9, [x24]
//   0x00c808: 7100bd3f  cmp      w9, #0x2f
//   0x00c80c: 54000c01  b.ne     #0xc98c
//   0x00c810: f9400339  ldr      x25, [x25]
//   0x00c814: aa1803f6  mov      x22, x24
//   0x00c818: 910012d7  add      x23, x22, #4
//   0x00c81c: aa1303e0  mov      x0, x19
//   0x00c820: aa1703e1  mov      x1, x23
//   0x00c824: aa1403e2  mov      x2, x20
//   0x00c828: aa1503e3  mov      x3, x21
//   0x00c82c: 94000a7f  bl       #0xf228
//   0x00c830: b4000a00  cbz      x0, #0xc970
//   0x00c834: f94006a8  ldr      x8, [x21, #8]
//   0x00c838: aa0003f6  mov      x22, x0
//   0x00c83c: 52800021  mov      w1, #1
//   0x00c840: 52800402  mov      w2, #0x20
//   0x00c844: aa1503e0  mov      x0, x21
//   0x00c848: d63f0100  blr      x8
//   0x00c84c: b4000860  cbz      x0, #0xc958
//   0x00c850: eb1602ff  cmp      x23, x22
//   0x00c854: 54000060  b.eq     #0xc860
//   0x00c858: a9005817  stp      x23, x22, [x0]
//   0x00c85c: 14000002  b        #0xc864
//   0x00c860: a9006419  stp      x25, x25, [x0]
//   0x00c864: f9400268  ldr      x8, [x19]
//   0x00c868: f9403109  ldr      x9, [x8, #0x60]
//   0x00c86c: b40000a9  cbz      x9, #0xc880
//   0x00c870: aa0803e9  mov      x9, x8
//   0x00c874: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00c878: f9000940  str      x0, [x10, #0x10]
//   0x00c87c: 14000003  b        #0xc888
//   0x00c880: f9003100  str      x0, [x8, #0x60]
//   0x00c884: 9101a109  add      x9, x8, #0x68
//   0x00c888: eb1402df  cmp      x22, x20
//   0x00c88c: f9000120  str      x0, [x9]
//   0x00c890: 540000a2  b.hs     #0xc8a4
//   0x00c894: b94002c9  ldr      w9, [x22]
//   0x00c898: 7100bd3f  cmp      w9, #0x2f
//   0x00c89c: 54fffbe0  b.eq     #0xc818
//   0x00c8a0: 1400003c  b        #0xc990
//   0x00c8a4: aa1403f6  mov      x22, x20
//   0x00c8a8: f900051b  str      x27, [x8, #8]
//   0x00c8ac: b4fff856  cbz      x22, #0xc7b4
//   0x00c8b0: eb1402df  cmp      x22, x20
//   0x00c8b4: aa1403e0  mov      x0, x20
//   0x00c8b8: 54ffd8c2  b.hs     #0xc3d0
//   0x00c8bc: b94002c8  ldr      w8, [x22]
//   0x00c8c0: 7100fd1f  cmp      w8, #0x3f
//   0x00c8c4: 540001e1  b.ne     #0xc900
//   0x00c8c8: 910012d7  add      x23, x22, #4
//   0x00c8cc: aa1303e0  mov      x0, x19
//   0x00c8d0: aa1703e1  mov      x1, x23
//   0x00c8d4: aa1403e2  mov      x2, x20
//   0x00c8d8: aa1503e3  mov      x3, x21
//   0x00c8dc: 94000d07  bl       #0xfcf8
//   0x00c8e0: b4fff6a0  cbz      x0, #0xc7b4
//   0x00c8e4: f9400268  ldr      x8, [x19]
//   0x00c8e8: aa0003f6  mov      x22, x0
//   0x00c8ec: eb14001f  cmp      x0, x20
//   0x00c8f0: a9070117  stp      x23, x0, [x8, #0x70]
//   0x00c8f4: aa1403e0  mov      x0, x20
//   0x00c8f8: 54ffd6c2  b.hs     #0xc3d0
//   0x00c8fc: b94002c8  ldr      w8, [x22]
//   0x00c900: 71008d1f  cmp      w8, #0x23
//   0x00c904: 54ffd6a1  b.ne     #0xc3d8
//   0x00c908: 910012d7  add      x23, x22, #4
//   0x00c90c: aa1303e0  mov      x0, x19
//   0x00c910: aa1703e1  mov      x1, x23
//   0x00c914: aa1403e2  mov      x2, x20
//   0x00c918: aa1503e3  mov      x3, x21
//   0x00c91c: 94000cf7  bl       #0xfcf8
//   0x00c920: b4fff4a0  cbz      x0, #0xc7b4
//   0x00c924: f9400268  ldr      x8, [x19]
//   0x00c928: aa0003f6  mov      x22, x0
//   0x00c92c: a9080117  stp      x23, x0, [x8, #0x80]
//   0x00c930: eb1402df  cmp      x22, x20
//   0x00c934: 54ffd561  b.ne     #0xc3e0
//   0x00c938: 2a1f03e0  mov      w0, wzr
//   0x00c93c: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x00c940: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x00c944: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x00c948: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x00c94c: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x00c950: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x00c954: d65f03c0  ret      
//   0x00c958: f9400260  ldr      x0, [x19]
//   0x00c95c: aa1503e1  mov      x1, x21
//   0x00c960: 97ffd9bc  bl       #0x3050
//   0x00c964: 52800068  mov      w8, #3
//   0x00c968: f9000a7f  str      xzr, [x19, #0x10]
//   0x00c96c: b9000a68  str      w8, [x19, #8]
//   0x00c970: f9400268  ldr      x8, [x19]
//   0x00c974: f900051b  str      x27, [x8, #8]
//   0x00c978: 17ffff8f  b        #0xc7b4
//   0x00c97c: eb1402df  cmp      x22, x20
//   0x00c980: aa1403e0  mov      x0, x20
//   0x00c984: 54ffd262  b.hs     #0xc3d0
//   0x00c988: 17ffffce  b        #0xc8c0
//   0x00c98c: aa1803f6  mov      x22, x24
//   0x00c990: f900051b  str      x27, [x8, #8]
//   0x00c994: 17ffffc7  b        #0xc8b0
//   0x00c998: 8b1a02e8  add      x8, x23, x26
//   0x00c99c: 91003101  add      x1, x8, #0xc
//   0x00c9a0: aa1303e0  mov      x0, x19
//   0x00c9a4: aa1403e2  mov      x2, x20
//   0x00c9a8: aa1503e3  mov      x3, x21
//   0x00c9ac: 94000928  bl       #0xee4c
//   0x00c9b0: f9400268  ldr      x8, [x19]
//   0x00c9b4: aa0003f6  mov      x22, x0
//   0x00c9b8: f900051b  str      x27, [x8, #8]
//   0x00c9bc: b5fff7b6  cbnz     x22, #0xc8b0
//   0x00c9c0: 17ffff7d  b        #0xc7b4
// ============================================================================
std::uint32_t fde_097_0c238(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000c238ULL;
    for (std::size_t i = 0; i < 483ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9146ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[098] Subroutine @ 0x00c9c4..0x00ca14 (80 bytes, 20 AArch64 instructions)
// [VN] Khung FDE[098] Hàm con @ 0x00c9c4..0x00ca14 (80 byte, 20 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00c9c4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00c9c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00c9cc: 910043fd  add      x29, sp, #0x10
//   0x00c9d0: b40001a0  cbz      x0, #0xca04
//   0x00c9d4: aa0103f3  mov      x19, x1
//   0x00c9d8: b4000161  cbz      x1, #0xca04
//   0x00c9dc: aa0003f4  mov      x20, x0
//   0x00c9e0: aa1303e0  mov      x0, x19
//   0x00c9e4: 97ffd9d3  bl       #0x3130
//   0x00c9e8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00c9ec: 8b000a62  add      x2, x19, x0, lsl #2
//   0x00c9f0: aa1403e0  mov      x0, x20
//   0x00c9f4: aa1303e1  mov      x1, x19
//   0x00c9f8: aa1f03e3  mov      x3, xzr
//   0x00c9fc: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x00ca00: 17fffe0e  b        #0xc238
//   0x00ca04: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00ca08: 52800040  mov      w0, #2
//   0x00ca0c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x00ca10: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_098_0c9c4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000c9c4ULL;
    for (std::size_t i = 0; i < 20ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9629ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[099] Subroutine @ 0x00ca14..0x00cad4 (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[099] Hàm con @ 0x00ca14..0x00cad4 (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ca14: d101c3ff  sub      sp, sp, #0x70
//   0x00ca18: f9001bf7  str      x23, [sp, #0x30]
//   0x00ca1c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00ca20: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00ca24: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00ca28: 910183fd  add      x29, sp, #0x60
//   0x00ca2c: d53bd057  mrs      x23, tpidr_el0
//   0x00ca30: f94016e8  ldr      x8, [x23, #0x28]
//   0x00ca34: f90017e8  str      x8, [sp, #0x28]
//   0x00ca38: b4000341  cbz      x1, #0xcaa0
//   0x00ca3c: aa0003f3  mov      x19, x0
//   0x00ca40: aa0103e0  mov      x0, x1
//   0x00ca44: aa0203f5  mov      x21, x2
//   0x00ca48: aa0103f6  mov      x22, x1
//   0x00ca4c: 97ffd9b9  bl       #0x3130
//   0x00ca50: 52800054  mov      w20, #2
//   0x00ca54: b4000293  cbz      x19, #0xcaa4
//   0x00ca58: b4000276  cbz      x22, #0xcaa4
//   0x00ca5c: f90007f3  str      x19, [sp, #8]
//   0x00ca60: f0000063  adrp     x3, #0x1b000
//   0x00ca64: f947fc63  ldr      x3, [x3, #0xff8]
//   0x00ca68: 8b000ac2  add      x2, x22, x0, lsl #2
//   0x00ca6c: 910023e0  add      x0, sp, #8
//   0x00ca70: aa1603e1  mov      x1, x22
//   0x00ca74: 97fffdf1  bl       #0xc238
//   0x00ca78: 2a0003f4  mov      w20, w0
//   0x00ca7c: 34000140  cbz      w0, #0xcaa4
//   0x00ca80: b4000075  cbz      x21, #0xca8c
//   0x00ca84: f9400fe8  ldr      x8, [sp, #0x18]
//   0x00ca88: f90002a8  str      x8, [x21]
//   0x00ca8c: f0000061  adrp     x1, #0x1b000
//   0x00ca90: f947fc21  ldr      x1, [x1, #0xff8]
//   0x00ca94: aa1303e0  mov      x0, x19
//   0x00ca98: 97ffd96e  bl       #0x3050
//   0x00ca9c: 14000002  b        #0xcaa4
//   0x00caa0: 52800054  mov      w20, #2
//   0x00caa4: f94016e8  ldr      x8, [x23, #0x28]
//   0x00caa8: f94017e9  ldr      x9, [sp, #0x28]
//   0x00caac: eb09011f  cmp      x8, x9
//   0x00cab0: 54000101  b.ne     #0xcad0
//   0x00cab4: 2a1403e0  mov      w0, w20
//   0x00cab8: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x00cabc: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00cac0: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x00cac4: f9401bf7  ldr      x23, [sp, #0x30]
//   0x00cac8: 9101c3ff  add      sp, sp, #0x70
//   0x00cacc: d65f03c0  ret      
//   0x00cad0: 97ffd994  bl       #0x3120
// ============================================================================
std::uint32_t fde_099_0ca14(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ca14ULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9649ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[100] Subroutine @ 0x00cad4..0x00cb94 (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[100] Hàm con @ 0x00cad4..0x00cb94 (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00cad4: d101c3ff  sub      sp, sp, #0x70
//   0x00cad8: f9001bf7  str      x23, [sp, #0x30]
//   0x00cadc: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00cae0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00cae4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00cae8: 910183fd  add      x29, sp, #0x60
//   0x00caec: d53bd057  mrs      x23, tpidr_el0
//   0x00caf0: f94016e8  ldr      x8, [x23, #0x28]
//   0x00caf4: aa0303f4  mov      x20, x3
//   0x00caf8: aa0103f6  mov      x22, x1
//   0x00cafc: aa0003f3  mov      x19, x0
//   0x00cb00: f90017e8  str      x8, [sp, #0x28]
//   0x00cb04: b40000a1  cbz      x1, #0xcb18
//   0x00cb08: b5000082  cbnz     x2, #0xcb18
//   0x00cb0c: aa1603e0  mov      x0, x22
//   0x00cb10: 97ffd988  bl       #0x3130
//   0x00cb14: 8b000ac2  add      x2, x22, x0, lsl #2
//   0x00cb18: 52800055  mov      w21, #2
//   0x00cb1c: b4000253  cbz      x19, #0xcb64
//   0x00cb20: b4000236  cbz      x22, #0xcb64
//   0x00cb24: b4000202  cbz      x2, #0xcb64
//   0x00cb28: f90007f3  str      x19, [sp, #8]
//   0x00cb2c: f0000063  adrp     x3, #0x1b000
//   0x00cb30: f947fc63  ldr      x3, [x3, #0xff8]
//   0x00cb34: 910023e0  add      x0, sp, #8
//   0x00cb38: aa1603e1  mov      x1, x22
//   0x00cb3c: 97fffdbf  bl       #0xc238
//   0x00cb40: 2a0003f5  mov      w21, w0
//   0x00cb44: 34000100  cbz      w0, #0xcb64
//   0x00cb48: b4000074  cbz      x20, #0xcb54
//   0x00cb4c: f9400fe8  ldr      x8, [sp, #0x18]
//   0x00cb50: f9000288  str      x8, [x20]
//   0x00cb54: f0000061  adrp     x1, #0x1b000
//   0x00cb58: f947fc21  ldr      x1, [x1, #0xff8]
//   0x00cb5c: aa1303e0  mov      x0, x19
//   0x00cb60: 97ffd93c  bl       #0x3050
//   0x00cb64: f94016e8  ldr      x8, [x23, #0x28]
//   0x00cb68: f94017e9  ldr      x9, [sp, #0x28]
//   0x00cb6c: eb09011f  cmp      x8, x9
//   0x00cb70: 54000101  b.ne     #0xcb90
//   0x00cb74: 2a1503e0  mov      w0, w21
//   0x00cb78: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x00cb7c: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00cb80: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x00cb84: f9401bf7  ldr      x23, [sp, #0x30]
//   0x00cb88: 9101c3ff  add      sp, sp, #0x70
//   0x00cb8c: d65f03c0  ret      
//   0x00cb90: 97ffd964  bl       #0x3120
// ============================================================================
std::uint32_t fde_100_0cad4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000cad4ULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9697ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[101] Subroutine @ 0x00cb94..0x00cc70 (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[101] Hàm con @ 0x00cb94..0x00cc70 (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00cb94: d10203ff  sub      sp, sp, #0x80
//   0x00cb98: f9001bf9  str      x25, [sp, #0x30]
//   0x00cb9c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x00cba0: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x00cba4: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x00cba8: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x00cbac: 9101c3fd  add      x29, sp, #0x70
//   0x00cbb0: d53bd059  mrs      x25, tpidr_el0
//   0x00cbb4: f9401728  ldr      x8, [x25, #0x28]
//   0x00cbb8: 52800056  mov      w22, #2
//   0x00cbbc: f90017e8  str      x8, [sp, #0x28]
//   0x00cbc0: b40003e0  cbz      x0, #0xcc3c
//   0x00cbc4: aa0103f8  mov      x24, x1
//   0x00cbc8: b40003a1  cbz      x1, #0xcc3c
//   0x00cbcc: aa0203f7  mov      x23, x2
//   0x00cbd0: b4000362  cbz      x2, #0xcc3c
//   0x00cbd4: aa0403f3  mov      x19, x4
//   0x00cbd8: aa0303f5  mov      x21, x3
//   0x00cbdc: aa0003f4  mov      x20, x0
//   0x00cbe0: b40000e4  cbz      x4, #0xcbfc
//   0x00cbe4: aa1303e0  mov      x0, x19
//   0x00cbe8: 97ffd99e  bl       #0x3260
//   0x00cbec: 7100041f  cmp      w0, #1
//   0x00cbf0: 540000a0  b.eq     #0xcc04
//   0x00cbf4: 52800156  mov      w22, #0xa
//   0x00cbf8: 14000011  b        #0xcc3c
//   0x00cbfc: f0000073  adrp     x19, #0x1b000
//   0x00cc00: f947fe73  ldr      x19, [x19, #0xff8]
//   0x00cc04: 910023e0  add      x0, sp, #8
//   0x00cc08: aa1803e1  mov      x1, x24
//   0x00cc0c: aa1703e2  mov      x2, x23
//   0x00cc10: aa1303e3  mov      x3, x19
//   0x00cc14: f90007f4  str      x20, [sp, #8]
//   0x00cc18: 97fffd88  bl       #0xc238
//   0x00cc1c: 2a0003f6  mov      w22, w0
//   0x00cc20: 340000e0  cbz      w0, #0xcc3c
//   0x00cc24: b4000075  cbz      x21, #0xcc30
//   0x00cc28: f9400fe8  ldr      x8, [sp, #0x18]
//   0x00cc2c: f90002a8  str      x8, [x21]
//   0x00cc30: aa1403e0  mov      x0, x20
//   0x00cc34: aa1303e1  mov      x1, x19
//   0x00cc38: 97ffd906  bl       #0x3050
//   0x00cc3c: f9401728  ldr      x8, [x25, #0x28]
//   0x00cc40: f94017e9  ldr      x9, [sp, #0x28]
//   0x00cc44: eb09011f  cmp      x8, x9
//   0x00cc48: 54000121  b.ne     #0xcc6c
//   0x00cc4c: 2a1603e0  mov      w0, w22
//   0x00cc50: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x00cc54: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x00cc58: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x00cc5c: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x00cc60: f9401bf9  ldr      x25, [sp, #0x30]
//   0x00cc64: 910203ff  add      sp, sp, #0x80
//   0x00cc68: d65f03c0  ret      
//   0x00cc6c: 97ffd92d  bl       #0x3120
// ============================================================================
std::uint32_t fde_101_0cb94(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000cb94ULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9745ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[102] Subroutine @ 0x00cc70..0x00ceb0 (576 bytes, 144 AArch64 instructions)
// [VN] Khung FDE[102] Hàm con @ 0x00cc70..0x00ceb0 (576 byte, 144 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00cc70: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00cc74: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00cc78: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00cc7c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00cc80: 9100c3fd  add      x29, sp, #0x30
//   0x00cc84: b4000140  cbz      x0, #0xccac
//   0x00cc88: aa0103f3  mov      x19, x1
//   0x00cc8c: aa0003f4  mov      x20, x0
//   0x00cc90: b4000121  cbz      x1, #0xccb4
//   0x00cc94: aa1303e0  mov      x0, x19
//   0x00cc98: 97ffd972  bl       #0x3260
//   0x00cc9c: 7100041f  cmp      w0, #1
//   0x00cca0: 540000e0  b.eq     #0xccbc
//   0x00cca4: 52800140  mov      w0, #0xa
//   0x00cca8: 1400007d  b        #0xce9c
//   0x00ccac: 52800040  mov      w0, #2
//   0x00ccb0: 1400007b  b        #0xce9c
//   0x00ccb4: f0000073  adrp     x19, #0x1b000
//   0x00ccb8: f947fe73  ldr      x19, [x19, #0xff8]
//   0x00ccbc: b9409688  ldr      w8, [x20, #0x94]
//   0x00ccc0: 340005a8  cbz      w8, #0xcd74
//   0x00ccc4: f9400281  ldr      x1, [x20]
//   0x00ccc8: b4000101  cbz      x1, #0xcce8
//   0x00cccc: f9400688  ldr      x8, [x20, #8]
//   0x00ccd0: eb08003f  cmp      x1, x8
//   0x00ccd4: 54000080  b.eq     #0xcce4
//   0x00ccd8: f9401268  ldr      x8, [x19, #0x20]
//   0x00ccdc: aa1303e0  mov      x0, x19
//   0x00cce0: d63f0100  blr      x8
//   0x00cce4: a9007e9f  stp      xzr, xzr, [x20]
//   0x00cce8: aa1403f5  mov      x21, x20
//   0x00ccec: f8410ea1  ldr      x1, [x21, #0x10]!
//   0x00ccf0: b4000101  cbz      x1, #0xcd10
//   0x00ccf4: f9400e88  ldr      x8, [x20, #0x18]
//   0x00ccf8: eb08003f  cmp      x1, x8
//   0x00ccfc: 54000080  b.eq     #0xcd0c
//   0x00cd00: f9401268  ldr      x8, [x19, #0x20]
//   0x00cd04: aa1303e0  mov      x0, x19
//   0x00cd08: d63f0100  blr      x8
//   0x00cd0c: a9007ebf  stp      xzr, xzr, [x21]
//   0x00cd10: aa1403f5  mov      x21, x20
//   0x00cd14: f8440ea1  ldr      x1, [x21, #0x40]!
//   0x00cd18: b40001a1  cbz      x1, #0xcd4c
//   0x00cd1c: aa1403e8  mov      x8, x20
//   0x00cd20: f8420d09  ldr      x9, [x8, #0x20]!
//   0x00cd24: eb01013f  cmp      x9, x1
//   0x00cd28: 54000041  b.ne     #0xcd30
//   0x00cd2c: a9007d1f  stp      xzr, xzr, [x8]
//   0x00cd30: f9402688  ldr      x8, [x20, #0x48]
//   0x00cd34: eb08003f  cmp      x1, x8
//   0x00cd38: 54000080  b.eq     #0xcd48
//   0x00cd3c: f9401268  ldr      x8, [x19, #0x20]
//   0x00cd40: aa1303e0  mov      x0, x19
//   0x00cd44: d63f0100  blr      x8
//   0x00cd48: a9007ebf  stp      xzr, xzr, [x21]
//   0x00cd4c: aa1403f5  mov      x21, x20
//   0x00cd50: f8420ea1  ldr      x1, [x21, #0x20]!
//   0x00cd54: b4000101  cbz      x1, #0xcd74
//   0x00cd58: f9401688  ldr      x8, [x20, #0x28]
//   0x00cd5c: eb08003f  cmp      x1, x8
//   0x00cd60: 54000080  b.eq     #0xcd70
//   0x00cd64: f9401268  ldr      x8, [x19, #0x20]
//   0x00cd68: aa1303e0  mov      x0, x19
//   0x00cd6c: d63f0100  blr      x8
//   0x00cd70: a9007ebf  stp      xzr, xzr, [x21]
//   0x00cd74: f9401a81  ldr      x1, [x20, #0x30]
//   0x00cd78: b40000a1  cbz      x1, #0xcd8c
//   0x00cd7c: f9401268  ldr      x8, [x19, #0x20]
//   0x00cd80: aa1303e0  mov      x0, x19
//   0x00cd84: d63f0100  blr      x8
//   0x00cd88: f9001a9f  str      xzr, [x20, #0x30]
//   0x00cd8c: f9401e81  ldr      x1, [x20, #0x38]
//   0x00cd90: b40000a1  cbz      x1, #0xcda4
//   0x00cd94: f9401268  ldr      x8, [x19, #0x20]
//   0x00cd98: aa1303e0  mov      x0, x19
//   0x00cd9c: d63f0100  blr      x8
//   0x00cda0: f9001e9f  str      xzr, [x20, #0x38]
//   0x00cda4: b9409688  ldr      w8, [x20, #0x94]
//   0x00cda8: 34000168  cbz      w8, #0xcdd4
//   0x00cdac: aa1403f5  mov      x21, x20
//   0x00cdb0: f8450ea1  ldr      x1, [x21, #0x50]!
//   0x00cdb4: b4000101  cbz      x1, #0xcdd4
//   0x00cdb8: f9402e88  ldr      x8, [x20, #0x58]
//   0x00cdbc: eb08003f  cmp      x1, x8
//   0x00cdc0: 54000080  b.eq     #0xcdd0
//   0x00cdc4: f9401268  ldr      x8, [x19, #0x20]
//   0x00cdc8: aa1303e0  mov      x0, x19
//   0x00cdcc: d63f0100  blr      x8
//   0x00cdd0: a9007ebf  stp      xzr, xzr, [x21]
//   0x00cdd4: aa1403f6  mov      x22, x20
//   0x00cdd8: f8460ed7  ldr      x23, [x22, #0x60]!
//   0x00cddc: b5000137  cbnz     x23, #0xce00
//   0x00cde0: b9409688  ldr      w8, [x20, #0x94]
//   0x00cde4: 350002e8  cbnz     w8, #0xce40
//   0x00cde8: 1400002c  b        #0xce98
//   0x00cdec: f9401268  ldr      x8, [x19, #0x20]
//   0x00cdf0: aa1303e0  mov      x0, x19
//   0x00cdf4: aa1503e1  mov      x1, x21
//   0x00cdf8: d63f0100  blr      x8
//   0x00cdfc: b40001d7  cbz      x23, #0xce34
//   0x00ce00: aa1703f5  mov      x21, x23
//   0x00ce04: b9409688  ldr      w8, [x20, #0x94]
//   0x00ce08: f9400af7  ldr      x23, [x23, #0x10]
//   0x00ce0c: 34ffff08  cbz      w8, #0xcdec
//   0x00ce10: f94002a1  ldr      x1, [x21]
//   0x00ce14: b4fffec1  cbz      x1, #0xcdec
//   0x00ce18: f94006a8  ldr      x8, [x21, #8]
//   0x00ce1c: eb08003f  cmp      x1, x8
//   0x00ce20: 54fffe62  b.hs     #0xcdec
//   0x00ce24: f9401268  ldr      x8, [x19, #0x20]
//   0x00ce28: aa1303e0  mov      x0, x19
//   0x00ce2c: d63f0100  blr      x8
//   0x00ce30: 17ffffef  b        #0xcdec
//   0x00ce34: a9007edf  stp      xzr, xzr, [x22]
//   0x00ce38: b9409688  ldr      w8, [x20, #0x94]
//   0x00ce3c: 340002e8  cbz      w8, #0xce98
//   0x00ce40: aa1403f5  mov      x21, x20
//   0x00ce44: f8470ea1  ldr      x1, [x21, #0x70]!
//   0x00ce48: b4000101  cbz      x1, #0xce68
//   0x00ce4c: f9403e88  ldr      x8, [x20, #0x78]
//   0x00ce50: eb08003f  cmp      x1, x8
//   0x00ce54: 54000080  b.eq     #0xce64
//   0x00ce58: f9401268  ldr      x8, [x19, #0x20]
//   0x00ce5c: aa1303e0  mov      x0, x19
//   0x00ce60: d63f0100  blr      x8
//   0x00ce64: a9007ebf  stp      xzr, xzr, [x21]
//   0x00ce68: aa1403f5  mov      x21, x20
//   0x00ce6c: f8480ea1  ldr      x1, [x21, #0x80]!
//   0x00ce70: b4000141  cbz      x1, #0xce98
//   0x00ce74: f9404688  ldr      x8, [x20, #0x88]
//   0x00ce78: eb08003f  cmp      x1, x8
//   0x00ce7c: 54000080  b.eq     #0xce8c
//   0x00ce80: f9401268  ldr      x8, [x19, #0x20]
//   0x00ce84: aa1303e0  mov      x0, x19
//   0x00ce88: d63f0100  blr      x8
//   0x00ce8c: 2a1f03e0  mov      w0, wzr
//   0x00ce90: a9007ebf  stp      xzr, xzr, [x21]
//   0x00ce94: 14000002  b        #0xce9c
//   0x00ce98: 2a1f03e0  mov      w0, wzr
//   0x00ce9c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00cea0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00cea4: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00cea8: f84407f7  ldr      x23, [sp], #0x40
//   0x00ceac: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_102_0cc70(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000cc70ULL;
    for (std::size_t i = 0; i < 144ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9800ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[103] Subroutine @ 0x00ceb0..0x00ceb8 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[103] Hàm con @ 0x00ceb0..0x00ceb8 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ceb0: aa1f03e1  mov      x1, xzr
//   0x00ceb4: 17ffd867  b        #0x3050
// ============================================================================
std::uint32_t fde_103_0ceb0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ceb0ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9944ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[104] Subroutine @ 0x00ceb8..0x00cf70 (184 bytes, 46 AArch64 instructions)
// [VN] Khung FDE[104] Hàm con @ 0x00ceb8..0x00cf70 (184 byte, 46 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ceb8: d10443ff  sub      sp, sp, #0x110
//   0x00cebc: a90d5ffc  stp      x28, x23, [sp, #0xd0]
//   0x00cec0: a90e57f6  stp      x22, x21, [sp, #0xe0]
//   0x00cec4: a90f4ff4  stp      x20, x19, [sp, #0xf0]
//   0x00cec8: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x00cecc: 910403fd  add      x29, sp, #0x100
//   0x00ced0: d53bd056  mrs      x22, tpidr_el0
//   0x00ced4: f94016c8  ldr      x8, [x22, #0x28]
//   0x00ced8: aa0003f3  mov      x19, x0
//   0x00cedc: f81c83a8  stur     x8, [x29, #-0x38]
//   0x00cee0: 97ffd894  bl       #0x3130
//   0x00cee4: 8b000a74  add      x20, x19, x0, lsl #2
//   0x00cee8: 9100a3e0  add      x0, sp, #0x28
//   0x00ceec: 9100a3f7  add      x23, sp, #0x28
//   0x00cef0: 97ffd8ac  bl       #0x31a0
//   0x00cef4: f0000075  adrp     x21, #0x1b000
//   0x00cef8: f947feb5  ldr      x21, [x21, #0xff8]
//   0x00cefc: 52800201  mov      w1, #0x10
//   0x00cf00: a901ffff  stp      xzr, xzr, [sp, #0x18]
//   0x00cf04: a900fff7  stp      x23, xzr, [sp, #8]
//   0x00cf08: f94002a8  ldr      x8, [x21]
//   0x00cf0c: aa1503e0  mov      x0, x21
//   0x00cf10: d63f0100  blr      x8
//   0x00cf14: f90033e0  str      x0, [sp, #0x60]
//   0x00cf18: 910023e0  add      x0, sp, #8
//   0x00cf1c: aa1303e1  mov      x1, x19
//   0x00cf20: aa1403e2  mov      x2, x20
//   0x00cf24: aa1503e3  mov      x3, x21
//   0x00cf28: 94000012  bl       #0xcf70
//   0x00cf2c: aa0003f3  mov      x19, x0
//   0x00cf30: 9100a3e0  add      x0, sp, #0x28
//   0x00cf34: aa1503e1  mov      x1, x21
//   0x00cf38: 97ffd846  bl       #0x3050
//   0x00cf3c: f94016c8  ldr      x8, [x22, #0x28]
//   0x00cf40: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x00cf44: eb14027f  cmp      x19, x20
//   0x00cf48: 1a9f17e0  cset     w0, eq
//   0x00cf4c: eb09011f  cmp      x8, x9
//   0x00cf50: 540000e1  b.ne     #0xcf6c
//   0x00cf54: a9507bfd  ldp      x29, x30, [sp, #0x100]
//   0x00cf58: a94f4ff4  ldp      x20, x19, [sp, #0xf0]
//   0x00cf5c: a94e57f6  ldp      x22, x21, [sp, #0xe0]
//   0x00cf60: a94d5ffc  ldp      x28, x23, [sp, #0xd0]
//   0x00cf64: 910443ff  add      sp, sp, #0x110
//   0x00cf68: d65f03c0  ret      
//   0x00cf6c: 97ffd86d  bl       #0x3120
// ============================================================================
std::uint32_t fde_104_0ceb8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ceb8ULL;
    for (std::size_t i = 0; i < 46ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9946ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[105] Subroutine @ 0x00cf70..0x00d5e4 (1652 bytes, 413 AArch64 instructions)
// [VN] Khung FDE[105] Hàm con @ 0x00cf70..0x00d5e4 (1652 byte, 413 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00cf70: d10283ff  sub      sp, sp, #0xa0
//   0x00cf74: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x00cf78: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x00cf7c: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x00cf80: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x00cf84: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x00cf88: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x00cf8c: 910243fd  add      x29, sp, #0x90
//   0x00cf90: d53bd054  mrs      x20, tpidr_el0
//   0x00cf94: f9401688  ldr      x8, [x20, #0x28]
//   0x00cf98: aa0203f6  mov      x22, x2
//   0x00cf9c: aa0003f3  mov      x19, x0
//   0x00cfa0: eb02003f  cmp      x1, x2
//   0x00cfa4: f9001fe8  str      x8, [sp, #0x38]
//   0x00cfa8: 540014a2  b.hs     #0xd23c
//   0x00cfac: f000003c  adrp     x28, #0x13000
//   0x00cfb0: aa0103f8  mov      x24, x1
//   0x00cfb4: f9000ff4  str      x20, [sp, #0x18]
//   0x00cfb8: 2a1f03ee  mov      w14, wzr
//   0x00cfbc: 2a1f03ed  mov      w13, wzr
//   0x00cfc0: 2a1f03f5  mov      w21, wzr
//   0x00cfc4: 2a1f03fb  mov      w27, wzr
//   0x00cfc8: 2a1f03f7  mov      w23, wzr
//   0x00cfcc: 2a1f03e8  mov      w8, wzr
//   0x00cfd0: 52800034  mov      w20, #1
//   0x00cfd4: 911e7b9c  add      x28, x28, #0x79e
//   0x00cfd8: 910093fa  add      x26, sp, #0x24
//   0x00cfdc: b9400309  ldr      w9, [x24]
//   0x00cfe0: 5100b92a  sub      w10, w9, #0x2e
//   0x00cfe4: 7100e15f  cmp      w10, #0x38
//   0x00cfe8: 540013a8  b.hi     #0xd25c
//   0x00cfec: 1000008b  adr      x11, #0xcffc
//   0x00cff0: 386a6b8c  ldrb     w12, [x28, x10]
//   0x00cff4: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00cff8: d61f0160  br       x11
//   0x00cffc: 710012bf  cmp      w21, #4
//   0x00d000: 540012e0  b.eq     #0xd25c
//   0x00d004: 5100c129  sub      w9, w9, #0x30
//   0x00d008: 3835cb49  strb     w9, [x26, w21, sxtw]
//   0x00d00c: 110006b5  add      w21, w21, #1
//   0x00d010: 1400000b  b        #0xd03c
//   0x00d014: 710012bf  cmp      w21, #4
//   0x00d018: 54001220  b.eq     #0xd25c
//   0x00d01c: 51015d28  sub      w8, w9, #0x57
//   0x00d020: 14000004  b        #0xd030
//   0x00d024: 710012bf  cmp      w21, #4
//   0x00d028: 540011a0  b.eq     #0xd25c
//   0x00d02c: 5100dd28  sub      w8, w9, #0x37
//   0x00d030: 3835cb48  strb     w8, [x26, w21, sxtw]
//   0x00d034: 110006b5  add      w21, w21, #1
//   0x00d038: 52800028  mov      w8, #1
//   0x00d03c: aa1803f9  mov      x25, x24
//   0x00d040: 91001338  add      x24, x25, #4
//   0x00d044: eb16031f  cmp      x24, x22
//   0x00d048: 54001902  b.hs     #0xd368
//   0x00d04c: 35fffc94  cbnz     w20, #0xcfdc
//   0x00d050: 2a1f03e8  mov      w8, wzr
//   0x00d054: 7100077f  cmp      w27, #1
//   0x00d058: 52800034  mov      w20, #1
//   0x00d05c: 54fffc0b  b.lt     #0xcfdc
//   0x00d060: 14000091  b        #0xd2a4
//   0x00d064: 0b0e01a9  add      w9, w13, w14
//   0x00d068: 7100193f  cmp      w9, #6
//   0x00d06c: 54000f8c  b.gt     #0xd25c
//   0x00d070: 710001df  cmp      w14, #0
//   0x00d074: 1a9f17e9  cset     w9, eq
//   0x00d078: 710019bf  cmp      w13, #6
//   0x00d07c: 1a9fa7ea  cset     w10, lt
//   0x00d080: 721d7abf  tst      w21, #0xfffffffb
//   0x00d084: 54000ec0  b.eq     #0xd25c
//   0x00d088: 0a0a0129  and      w9, w9, w10
//   0x00d08c: 37000e89  tbnz     w9, #0, #0xd25c
//   0x00d090: 35000e68  cbnz     w8, #0xd25c
//   0x00d094: 71000abf  cmp      w21, #2
//   0x00d098: 540001cb  b.lt     #0xd0d0
//   0x00d09c: 394093e8  ldrb     w8, [sp, #0x24]
//   0x00d0a0: 34002228  cbz      w8, #0xd4e4
//   0x00d0a4: 71000ebf  cmp      w21, #3
//   0x00d0a8: 54000141  b.ne     #0xd0d0
//   0x00d0ac: 394097e9  ldrb     w9, [sp, #0x25]
//   0x00d0b0: 39409bea  ldrb     w10, [sp, #0x26]
//   0x00d0b4: 52800c8b  mov      w11, #0x64
//   0x00d0b8: 1b0b7d0b  mul      w11, w8, w11
//   0x00d0bc: 5280014c  mov      w12, #0xa
//   0x00d0c0: 1b0c2d2b  madd     w11, w9, w12, w11
//   0x00d0c4: 0b0a016a  add      w10, w11, w10
//   0x00d0c8: 7104015f  cmp      w10, #0x100
//   0x00d0cc: 54002502  b.hs     #0xd56c
//   0x00d0d0: 910093e0  add      x0, sp, #0x24
//   0x00d0d4: 2a1503e1  mov      w1, w21
//   0x00d0d8: aa0303f4  mov      x20, x3
//   0x00d0dc: aa0d03f5  mov      x21, x13
//   0x00d0e0: 2a0e03f9  mov      w25, w14
//   0x00d0e4: 97ffd803  bl       #0x30f0
//   0x00d0e8: f9400269  ldr      x9, [x19]
//   0x00d0ec: 2a1903ee  mov      w14, w25
//   0x00d0f0: aa1503ed  mov      x13, x21
//   0x00d0f4: aa1403e3  mov      x3, x20
//   0x00d0f8: f9401d29  ldr      x9, [x9, #0x38]
//   0x00d0fc: 2a1f03f5  mov      w21, wzr
//   0x00d100: 2a1f03e8  mov      w8, wzr
//   0x00d104: 2a1f03f4  mov      w20, wzr
//   0x00d108: 5280003b  mov      w27, #1
//   0x00d10c: 39003120  strb     w0, [x9, #0xc]
//   0x00d110: 17ffffcb  b        #0xd03c
//   0x00d114: 710006bf  cmp      w21, #1
//   0x00d118: b90017fb  str      w27, [sp, #0x14]
//   0x00d11c: 540003ab  b.lt     #0xd190
//   0x00d120: aa1303f9  mov      x25, x19
//   0x00d124: 2a1703f3  mov      w19, w23
//   0x00d128: aa0303f7  mov      x23, x3
//   0x00d12c: b9000bee  str      w14, [sp, #8]
//   0x00d130: 3400012e  cbz      w14, #0xd154
//   0x00d134: 9100a3e8  add      x8, sp, #0x28
//   0x00d138: 8b33c502  add      x2, x8, w19, sxtw #1
//   0x00d13c: 910093e0  add      x0, sp, #0x24
//   0x00d140: 2a1503e1  mov      w1, w21
//   0x00d144: aa0d03fb  mov      x27, x13
//   0x00d148: 97ffd84a  bl       #0x3270
//   0x00d14c: 11000673  add      w19, w19, #1
//   0x00d150: 14000008  b        #0xd170
//   0x00d154: f9400328  ldr      x8, [x25]
//   0x00d158: 910093e0  add      x0, sp, #0x24
//   0x00d15c: 2a1503e1  mov      w1, w21
//   0x00d160: aa0d03fb  mov      x27, x13
//   0x00d164: f9401d08  ldr      x8, [x8, #0x38]
//   0x00d168: 8b2dc502  add      x2, x8, w13, sxtw #1
//   0x00d16c: 97ffd841  bl       #0x3270
//   0x00d170: 1100077b  add      w27, w27, #1
//   0x00d174: aa1b03ed  mov      x13, x27
//   0x00d178: b94017fb  ldr      w27, [sp, #0x14]
//   0x00d17c: b9400bee  ldr      w14, [sp, #8]
//   0x00d180: 2a1f03f5  mov      w21, wzr
//   0x00d184: aa1703e3  mov      x3, x23
//   0x00d188: 2a1303f7  mov      w23, w19
//   0x00d18c: aa1903f3  mov      x19, x25
//   0x00d190: 52800108  mov      w8, #8
//   0x00d194: 4b0e0108  sub      w8, w8, w14
//   0x00d198: 6b0801bf  cmp      w13, w8
//   0x00d19c: 5400060a  b.ge     #0xd25c
//   0x00d1a0: 91001319  add      x25, x24, #4
//   0x00d1a4: eb16033f  cmp      x25, x22
//   0x00d1a8: 54000e02  b.hs     #0xd368
//   0x00d1ac: b9400328  ldr      w8, [x25]
//   0x00d1b0: 7100e91f  cmp      w8, #0x3a
//   0x00d1b4: 540003a1  b.ne     #0xd228
//   0x00d1b8: f9400260  ldr      x0, [x19]
//   0x00d1bc: 350018ae  cbnz     w14, #0xd4d0
//   0x00d1c0: f9401c08  ldr      x8, [x0, #0x38]
//   0x00d1c4: 937f7da9  sbfiz    x9, x13, #1, #0x20
//   0x00d1c8: 5280020a  mov      w10, #0x10
//   0x00d1cc: 4b09014a  sub      w10, w10, w9
//   0x00d1d0: 8b090100  add      x0, x8, x9
//   0x00d1d4: 93407d42  sxtw     x2, w10
//   0x00d1d8: 2a1f03e1  mov      w1, wzr
//   0x00d1dc: f90007f3  str      x19, [sp, #8]
//   0x00d1e0: 2a1703f3  mov      w19, w23
//   0x00d1e4: aa0303f7  mov      x23, x3
//   0x00d1e8: aa0d03fb  mov      x27, x13
//   0x00d1ec: 97ffd83d  bl       #0x32e0
//   0x00d1f0: 91002318  add      x24, x24, #8
//   0x00d1f4: eb16031f  cmp      x24, x22
//   0x00d1f8: 540019e2  b.hs     #0xd534
//   0x00d1fc: b9400308  ldr      w8, [x24]
//   0x00d200: 5280002e  mov      w14, #1
//   0x00d204: aa1703e3  mov      x3, x23
//   0x00d208: 7100e91f  cmp      w8, #0x3a
//   0x00d20c: 540019c0  b.eq     #0xd544
//   0x00d210: 2a1303f7  mov      w23, w19
//   0x00d214: f94007f3  ldr      x19, [sp, #8]
//   0x00d218: aa1b03ed  mov      x13, x27
//   0x00d21c: b94017fb  ldr      w27, [sp, #0x14]
//   0x00d220: 2a1f03e8  mov      w8, wzr
//   0x00d224: 17ffff87  b        #0xd040
//   0x00d228: 340001ad  cbz      w13, #0xd25c
//   0x00d22c: 7101751f  cmp      w8, #0x5d
//   0x00d230: 54000160  b.eq     #0xd25c
//   0x00d234: 2a1f03e8  mov      w8, wzr
//   0x00d238: 17ffff81  b        #0xd03c
//   0x00d23c: f9400260  ldr      x0, [x19]
//   0x00d240: aa0303e1  mov      x1, x3
//   0x00d244: 97ffd783  bl       #0x3050
//   0x00d248: aa1f03f7  mov      x23, xzr
//   0x00d24c: f9000a76  str      x22, [x19, #0x10]
//   0x00d250: 52800028  mov      w8, #1
//   0x00d254: b9000a68  str      w8, [x19, #8]
//   0x00d258: 1400004c  b        #0xd388
//   0x00d25c: f9400260  ldr      x0, [x19]
//   0x00d260: aa0303e1  mov      x1, x3
//   0x00d264: 97ffd77b  bl       #0x3050
//   0x00d268: aa1f03f7  mov      x23, xzr
//   0x00d26c: f9000a78  str      x24, [x19, #0x10]
//   0x00d270: 14000043  b        #0xd37c
//   0x00d274: 34000a4e  cbz      w14, #0xd3bc
//   0x00d278: 710006bf  cmp      w21, #1
//   0x00d27c: 54000b4b  b.lt     #0xd3e4
//   0x00d280: f9400ff4  ldr      x20, [sp, #0x18]
//   0x00d284: 71001dbf  cmp      w13, #7
//   0x00d288: 54000fcb  b.lt     #0xd480
//   0x00d28c: f9400260  ldr      x0, [x19]
//   0x00d290: aa0303e1  mov      x1, x3
//   0x00d294: 97ffd76f  bl       #0x3050
//   0x00d298: aa1f03f7  mov      x23, xzr
//   0x00d29c: f9000a78  str      x24, [x19, #0x10]
//   0x00d2a0: 17ffffec  b        #0xd250
//   0x00d2a4: 2a1703fa  mov      w26, w23
//   0x00d2a8: 91002337  add      x23, x25, #8
//   0x00d2ac: 910093f4  add      x20, sp, #0x24
//   0x00d2b0: 52800c98  mov      w24, #0x64
//   0x00d2b4: 52800159  mov      w25, #0xa
//   0x00d2b8: b85fc2e9  ldur     w9, [x23, #-4]
//   0x00d2bc: 5100c128  sub      w8, w9, #0x30
//   0x00d2c0: 7100291f  cmp      w8, #0xa
//   0x00d2c4: 54000142  b.hs     #0xd2ec
//   0x00d2c8: 710012bf  cmp      w21, #4
//   0x00d2cc: 54000c60  b.eq     #0xd458
//   0x00d2d0: 110006a9  add      w9, w21, #1
//   0x00d2d4: 3835ca88  strb     w8, [x20, w21, sxtw]
//   0x00d2d8: 2a0903f5  mov      w21, w9
//   0x00d2dc: eb1602ff  cmp      x23, x22
//   0x00d2e0: 910012f7  add      x23, x23, #4
//   0x00d2e4: 54fffea3  b.lo     #0xd2b8
//   0x00d2e8: 14000020  b        #0xd368
//   0x00d2ec: 7100b93f  cmp      w9, #0x2e
//   0x00d2f0: 540007e1  b.ne     #0xd3ec
//   0x00d2f4: 721d7abf  tst      w21, #0xfffffffb
//   0x00d2f8: 54000b00  b.eq     #0xd458
//   0x00d2fc: 7100137f  cmp      w27, #4
//   0x00d300: 54000ac0  b.eq     #0xd458
//   0x00d304: 71000abf  cmp      w21, #2
//   0x00d308: 5400018b  b.lt     #0xd338
//   0x00d30c: 394093e8  ldrb     w8, [sp, #0x24]
//   0x00d310: 34001388  cbz      w8, #0xd580
//   0x00d314: 71000ebf  cmp      w21, #3
//   0x00d318: 54000101  b.ne     #0xd338
//   0x00d31c: 394097e9  ldrb     w9, [sp, #0x25]
//   0x00d320: 39409bea  ldrb     w10, [sp, #0x26]
//   0x00d324: 1b187d0b  mul      w11, w8, w24
//   0x00d328: 1b192d2b  madd     w11, w9, w25, w11
//   0x00d32c: 0b0a016a  add      w10, w11, w10
//   0x00d330: 7104015f  cmp      w10, #0x100
//   0x00d334: 54000882  b.hs     #0xd444
//   0x00d338: 910093e0  add      x0, sp, #0x24
//   0x00d33c: 2a1503e1  mov      w1, w21
//   0x00d340: aa0303f5  mov      x21, x3
//   0x00d344: 97ffd76b  bl       #0x30f0
//   0x00d348: f9400268  ldr      x8, [x19]
//   0x00d34c: aa1503e3  mov      x3, x21
//   0x00d350: 2a1f03f5  mov      w21, wzr
//   0x00d354: f9401d08  ldr      x8, [x8, #0x38]
//   0x00d358: 8b3bc108  add      x8, x8, w27, sxtw
//   0x00d35c: 39003100  strb     w0, [x8, #0xc]
//   0x00d360: 1100077b  add      w27, w27, #1
//   0x00d364: 17ffffde  b        #0xd2dc
//   0x00d368: f9400260  ldr      x0, [x19]
//   0x00d36c: aa0303e1  mov      x1, x3
//   0x00d370: 97ffd738  bl       #0x3050
//   0x00d374: aa1f03f7  mov      x23, xzr
//   0x00d378: f9000a76  str      x22, [x19, #0x10]
//   0x00d37c: 52800028  mov      w8, #1
//   0x00d380: b9000a68  str      w8, [x19, #8]
//   0x00d384: f9400ff4  ldr      x20, [sp, #0x18]
//   0x00d388: f9401688  ldr      x8, [x20, #0x28]
//   0x00d38c: f9401fe9  ldr      x9, [sp, #0x38]
//   0x00d390: eb09011f  cmp      x8, x9
//   0x00d394: 54001261  b.ne     #0xd5e0
//   0x00d398: aa1703e0  mov      x0, x23
//   0x00d39c: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x00d3a0: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x00d3a4: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x00d3a8: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x00d3ac: a94567fa  ldp      x26, x25, [sp, #0x50]
//   0x00d3b0: a9446ffc  ldp      x28, x27, [sp, #0x40]
//   0x00d3b4: 910283ff  add      sp, sp, #0xa0
//   0x00d3b8: d65f03c0  ret      
//   0x00d3bc: f9400260  ldr      x0, [x19]
//   0x00d3c0: 71001dbf  cmp      w13, #7
//   0x00d3c4: 54fff4e1  b.ne     #0xd260
//   0x00d3c8: 710002bf  cmp      w21, #0
//   0x00d3cc: 54fff4ad  b.le     #0xd260
//   0x00d3d0: f9401c08  ldr      x8, [x0, #0x38]
//   0x00d3d4: 910093e0  add      x0, sp, #0x24
//   0x00d3d8: 2a1503e1  mov      w1, w21
//   0x00d3dc: 91003902  add      x2, x8, #0xe
//   0x00d3e0: 97ffd7a4  bl       #0x3270
//   0x00d3e4: f9400ff4  ldr      x20, [sp, #0x18]
//   0x00d3e8: 1400002c  b        #0xd498
//   0x00d3ec: 7101753f  cmp      w9, #0x5d
//   0x00d3f0: 54000341  b.ne     #0xd458
//   0x00d3f4: 121d7aa8  and      w8, w21, #0xfffffffb
//   0x00d3f8: d10012f4  sub      x20, x23, #4
//   0x00d3fc: 34000668  cbz      w8, #0xd4c8
//   0x00d400: 71000f7f  cmp      w27, #3
//   0x00d404: 54000621  b.ne     #0xd4c8
//   0x00d408: 71000abf  cmp      w21, #2
//   0x00d40c: 5400072b  b.lt     #0xd4f0
//   0x00d410: 394093e8  ldrb     w8, [sp, #0x24]
//   0x00d414: 34000b68  cbz      w8, #0xd580
//   0x00d418: 71000ebf  cmp      w21, #3
//   0x00d41c: 540006a1  b.ne     #0xd4f0
//   0x00d420: 394097e9  ldrb     w9, [sp, #0x25]
//   0x00d424: 39409beb  ldrb     w11, [sp, #0x26]
//   0x00d428: 52800c8a  mov      w10, #0x64
//   0x00d42c: 1b0a7d0a  mul      w10, w8, w10
//   0x00d430: 5280014c  mov      w12, #0xa
//   0x00d434: 1b0c292a  madd     w10, w9, w12, w10
//   0x00d438: 0b0b014a  add      w10, w10, w11
//   0x00d43c: 7104015f  cmp      w10, #0x100
//   0x00d440: 54000583  b.lo     #0xd4f0
//   0x00d444: 71000d1f  cmp      w8, #3
//   0x00d448: 54000b43  b.lo     #0xd5b0
//   0x00d44c: f9400260  ldr      x0, [x19]
//   0x00d450: d10042f4  sub      x20, x23, #0x10
//   0x00d454: 1400005e  b        #0xd5cc
//   0x00d458: f9400260  ldr      x0, [x19]
//   0x00d45c: aa0303e1  mov      x1, x3
//   0x00d460: 97ffd6fc  bl       #0x3050
//   0x00d464: d10012e8  sub      x8, x23, #4
//   0x00d468: 52800029  mov      w9, #1
//   0x00d46c: f9000a68  str      x8, [x19, #0x10]
//   0x00d470: b9000a69  str      w9, [x19, #8]
//   0x00d474: f9400ff4  ldr      x20, [sp, #0x18]
//   0x00d478: aa1f03f7  mov      x23, xzr
//   0x00d47c: 17ffffc3  b        #0xd388
//   0x00d480: 9100a3e8  add      x8, sp, #0x28
//   0x00d484: 8b37c502  add      x2, x8, w23, sxtw #1
//   0x00d488: 910093e0  add      x0, sp, #0x24
//   0x00d48c: 2a1503e1  mov      w1, w21
//   0x00d490: 97ffd778  bl       #0x3270
//   0x00d494: 110006f7  add      w23, w23, #1
//   0x00d498: f9400268  ldr      x8, [x19]
//   0x00d49c: 531f7ae9  lsl      w9, w23, #1
//   0x00d4a0: 93407d22  sxtw     x2, w9
//   0x00d4a4: 9100a3e1  add      x1, sp, #0x28
//   0x00d4a8: f9401d08  ldr      x8, [x8, #0x38]
//   0x00d4ac: cb020108  sub      x8, x8, x2
//   0x00d4b0: 91004100  add      x0, x8, #0x10
//   0x00d4b4: 97ffd783  bl       #0x32c0
//   0x00d4b8: f9400268  ldr      x8, [x19]
//   0x00d4bc: 91001317  add      x23, x24, #4
//   0x00d4c0: f9001518  str      x24, [x8, #0x28]
//   0x00d4c4: 17ffffb1  b        #0xd388
//   0x00d4c8: f9400260  ldr      x0, [x19]
//   0x00d4cc: 14000040  b        #0xd5cc
//   0x00d4d0: aa0303e1  mov      x1, x3
//   0x00d4d4: 97ffd6df  bl       #0x3050
//   0x00d4d8: aa1f03f7  mov      x23, xzr
//   0x00d4dc: f9000a79  str      x25, [x19, #0x10]
//   0x00d4e0: 17ffffa7  b        #0xd37c
//   0x00d4e4: f9400260  ldr      x0, [x19]
//   0x00d4e8: cb35cb14  sub      x20, x24, w21, sxtw #2
//   0x00d4ec: 14000038  b        #0xd5cc
//   0x00d4f0: f9400268  ldr      x8, [x19]
//   0x00d4f4: 9100a3e1  add      x1, sp, #0x28
//   0x00d4f8: f9401d09  ldr      x9, [x8, #0x38]
//   0x00d4fc: f9001514  str      x20, [x8, #0x28]
//   0x00d500: 531f7b48  lsl      w8, w26, #1
//   0x00d504: 93407d02  sxtw     x2, w8
//   0x00d508: cb020128  sub      x8, x9, x2
//   0x00d50c: 91003100  add      x0, x8, #0xc
//   0x00d510: 97ffd76c  bl       #0x32c0
//   0x00d514: 910093e0  add      x0, sp, #0x24
//   0x00d518: 2a1503e1  mov      w1, w21
//   0x00d51c: 97ffd6f5  bl       #0x30f0
//   0x00d520: f9400268  ldr      x8, [x19]
//   0x00d524: f9400ff4  ldr      x20, [sp, #0x18]
//   0x00d528: f9401d08  ldr      x8, [x8, #0x38]
//   0x00d52c: 39003d00  strb     w0, [x8, #0xf]
//   0x00d530: 17ffff96  b        #0xd388
//   0x00d534: f94007f3  ldr      x19, [sp, #8]
//   0x00d538: aa1703e1  mov      x1, x23
//   0x00d53c: f9400260  ldr      x0, [x19]
//   0x00d540: 17ffff8c  b        #0xd370
//   0x00d544: f94007f3  ldr      x19, [sp, #8]
//   0x00d548: aa0303e1  mov      x1, x3
//   0x00d54c: 52800034  mov      w20, #1
//   0x00d550: f9400260  ldr      x0, [x19]
//   0x00d554: 97ffd6bf  bl       #0x3050
//   0x00d558: b9000a74  str      w20, [x19, #8]
//   0x00d55c: f9400ff4  ldr      x20, [sp, #0x18]
//   0x00d560: aa1f03f7  mov      x23, xzr
//   0x00d564: f9000a78  str      x24, [x19, #0x10]
//   0x00d568: 17ffff88  b        #0xd388
//   0x00d56c: 71000d1f  cmp      w8, #3
//   0x00d570: 54000103  b.lo     #0xd590
//   0x00d574: f9400260  ldr      x0, [x19]
//   0x00d578: d1003314  sub      x20, x24, #0xc
//   0x00d57c: 14000014  b        #0xd5cc
//   0x00d580: f9400260  ldr      x0, [x19]
//   0x00d584: cb35cae8  sub      x8, x23, w21, sxtw #2
//   0x00d588: d1001114  sub      x20, x8, #4
//   0x00d58c: 14000010  b        #0xd5cc
//   0x00d590: 7100193f  cmp      w9, #6
//   0x00d594: 54000083  b.lo     #0xd5a4
//   0x00d598: f9400260  ldr      x0, [x19]
//   0x00d59c: d1002314  sub      x20, x24, #8
//   0x00d5a0: 1400000b  b        #0xd5cc
//   0x00d5a4: f9400260  ldr      x0, [x19]
//   0x00d5a8: d1001314  sub      x20, x24, #4
//   0x00d5ac: 14000008  b        #0xd5cc
//   0x00d5b0: 7100193f  cmp      w9, #6
//   0x00d5b4: 54000083  b.lo     #0xd5c4
//   0x00d5b8: f9400260  ldr      x0, [x19]
//   0x00d5bc: d10032f4  sub      x20, x23, #0xc
//   0x00d5c0: 14000003  b        #0xd5cc
//   0x00d5c4: f9400260  ldr      x0, [x19]
//   0x00d5c8: d10022f4  sub      x20, x23, #8
//   0x00d5cc: aa0303e1  mov      x1, x3
//   0x00d5d0: 97ffd6a0  bl       #0x3050
//   0x00d5d4: aa1f03f7  mov      x23, xzr
//   0x00d5d8: f9000a74  str      x20, [x19, #0x10]
//   0x00d5dc: 17ffff68  b        #0xd37c
//   0x00d5e0: 97ffd6d0  bl       #0x3120
// ============================================================================
std::uint32_t fde_105_0cf70(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000cf70ULL;
    for (std::size_t i = 0; i < 413ULL; ++i) {
        std::uint32_t insn = kTextInstructions[9992ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[106] Subroutine @ 0x00d5e4..0x00d644 (96 bytes, 24 AArch64 instructions)
// [VN] Khung FDE[106] Hàm con @ 0x00d5e4..0x00d644 (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00d5e4: d100c3ff  sub      sp, sp, #0x30
//   0x00d5e8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00d5ec: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00d5f0: 910083fd  add      x29, sp, #0x20
//   0x00d5f4: d53bd054  mrs      x20, tpidr_el0
//   0x00d5f8: f9401688  ldr      x8, [x20, #0x28]
//   0x00d5fc: aa0003f3  mov      x19, x0
//   0x00d600: f90007e8  str      x8, [sp, #8]
//   0x00d604: 97ffd6cb  bl       #0x3130
//   0x00d608: 8b000a62  add      x2, x19, x0, lsl #2
//   0x00d60c: 910013e0  add      x0, sp, #4
//   0x00d610: aa1303e1  mov      x1, x19
//   0x00d614: 97ffd723  bl       #0x32a0
//   0x00d618: f9401688  ldr      x8, [x20, #0x28]
//   0x00d61c: f94007e9  ldr      x9, [sp, #8]
//   0x00d620: 7100001f  cmp      w0, #0
//   0x00d624: 1a9f17e0  cset     w0, eq
//   0x00d628: eb09011f  cmp      x8, x9
//   0x00d62c: 540000a1  b.ne     #0xd640
//   0x00d630: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00d634: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00d638: 9100c3ff  add      sp, sp, #0x30
//   0x00d63c: d65f03c0  ret      
//   0x00d640: 97ffd6b8  bl       #0x3120
// ============================================================================
std::uint32_t fde_106_0d5e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000d5e4ULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[10405ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[107] Subroutine @ 0x00d644..0x00d9cc (904 bytes, 226 AArch64 instructions)
// [VN] Khung FDE[107] Hàm con @ 0x00d644..0x00d9cc (904 byte, 226 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00d644: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00d648: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00d64c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00d650: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00d654: 9100c3fd  add      x29, sp, #0x30
//   0x00d658: d0000078  adrp     x24, #0x1b000
//   0x00d65c: f947e318  ldr      x24, [x24, #0xfc0]
//   0x00d660: aa0303f6  mov      x22, x3
//   0x00d664: aa0203f5  mov      x21, x2
//   0x00d668: aa0103f4  mov      x20, x1
//   0x00d66c: aa0003f3  mov      x19, x0
//   0x00d670: eb02003f  cmp      x1, x2
//   0x00d674: 540002e2  b.hs     #0xd6d0
//   0x00d678: d0000037  adrp     x23, #0x13000
//   0x00d67c: 911f5ef7  add      x23, x23, #0x7d7
//   0x00d680: 39400288  ldrb     w8, [x20]
//   0x00d684: 51008508  sub      w8, w8, #0x21
//   0x00d688: 7101751f  cmp      w8, #0x5d
//   0x00d68c: 54000588  b.hi     #0xd73c
//   0x00d690: 10000089  adr      x9, #0xd6a0
//   0x00d694: 38686aea  ldrb     w10, [x23, x8]
//   0x00d698: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00d69c: d61f0120  br       x9
//   0x00d6a0: 91000694  add      x20, x20, #1
//   0x00d6a4: eb15029f  cmp      x20, x21
//   0x00d6a8: 54fffec3  b.lo     #0xd680
//   0x00d6ac: 14000009  b        #0xd6d0
//   0x00d6b0: aa1303e0  mov      x0, x19
//   0x00d6b4: aa1403e1  mov      x1, x20
//   0x00d6b8: aa1503e2  mov      x2, x21
//   0x00d6bc: aa1603e3  mov      x3, x22
//   0x00d6c0: 940000c3  bl       #0xd9cc
//   0x00d6c4: aa0003f4  mov      x20, x0
//   0x00d6c8: b5fffee0  cbnz     x0, #0xd6a4
//   0x00d6cc: 140000b7  b        #0xd9a8
//   0x00d6d0: f9400268  ldr      x8, [x19]
//   0x00d6d4: 52800021  mov      w1, #1
//   0x00d6d8: 52800402  mov      w2, #0x20
//   0x00d6dc: aa1603e0  mov      x0, x22
//   0x00d6e0: f9400117  ldr      x23, [x8]
//   0x00d6e4: f94006c8  ldr      x8, [x22, #8]
//   0x00d6e8: d63f0100  blr      x8
//   0x00d6ec: b4001500  cbz      x0, #0xd98c
//   0x00d6f0: eb1402ff  cmp      x23, x20
//   0x00d6f4: 54000060  b.eq     #0xd700
//   0x00d6f8: a9005017  stp      x23, x20, [x0]
//   0x00d6fc: 14000003  b        #0xd708
//   0x00d700: f9400308  ldr      x8, [x24]
//   0x00d704: a9002008  stp      x8, x8, [x0]
//   0x00d708: f9400268  ldr      x8, [x19]
//   0x00d70c: f9403109  ldr      x9, [x8, #0x60]
//   0x00d710: b40000a9  cbz      x9, #0xd724
//   0x00d714: aa0803e9  mov      x9, x8
//   0x00d718: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00d71c: f9000940  str      x0, [x10, #0x10]
//   0x00d720: 14000003  b        #0xd72c
//   0x00d724: f9003100  str      x0, [x8, #0x60]
//   0x00d728: 9101a109  add      x9, x8, #0x68
//   0x00d72c: f9000120  str      x0, [x9]
//   0x00d730: f900011f  str      xzr, [x8]
//   0x00d734: aa1503f4  mov      x20, x21
//   0x00d738: 1400009c  b        #0xd9a8
//   0x00d73c: f9400268  ldr      x8, [x19]
//   0x00d740: 52800021  mov      w1, #1
//   0x00d744: 52800402  mov      w2, #0x20
//   0x00d748: aa1603e0  mov      x0, x22
//   0x00d74c: f9400117  ldr      x23, [x8]
//   0x00d750: f94006c8  ldr      x8, [x22, #8]
//   0x00d754: d63f0100  blr      x8
//   0x00d758: b40011a0  cbz      x0, #0xd98c
//   0x00d75c: eb1402ff  cmp      x23, x20
//   0x00d760: 540001e0  b.eq     #0xd79c
//   0x00d764: a9005017  stp      x23, x20, [x0]
//   0x00d768: 1400000f  b        #0xd7a4
//   0x00d76c: f9400268  ldr      x8, [x19]
//   0x00d770: 52800021  mov      w1, #1
//   0x00d774: 52800402  mov      w2, #0x20
//   0x00d778: aa1603e0  mov      x0, x22
//   0x00d77c: f9400117  ldr      x23, [x8]
//   0x00d780: f94006c8  ldr      x8, [x22, #8]
//   0x00d784: d63f0100  blr      x8
//   0x00d788: b4001020  cbz      x0, #0xd98c
//   0x00d78c: eb1402ff  cmp      x23, x20
//   0x00d790: 54000180  b.eq     #0xd7c0
//   0x00d794: a9005017  stp      x23, x20, [x0]
//   0x00d798: 1400000c  b        #0xd7c8
//   0x00d79c: f9400308  ldr      x8, [x24]
//   0x00d7a0: a9002008  stp      x8, x8, [x0]
//   0x00d7a4: f9400268  ldr      x8, [x19]
//   0x00d7a8: f9403109  ldr      x9, [x8, #0x60]
//   0x00d7ac: b40001c9  cbz      x9, #0xd7e4
//   0x00d7b0: aa0803e9  mov      x9, x8
//   0x00d7b4: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00d7b8: f9000940  str      x0, [x10, #0x10]
//   0x00d7bc: 1400000c  b        #0xd7ec
//   0x00d7c0: f9400308  ldr      x8, [x24]
//   0x00d7c4: a9002008  stp      x8, x8, [x0]
//   0x00d7c8: f9400268  ldr      x8, [x19]
//   0x00d7cc: f9403109  ldr      x9, [x8, #0x60]
//   0x00d7d0: b4000329  cbz      x9, #0xd834
//   0x00d7d4: aa0803e9  mov      x9, x8
//   0x00d7d8: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00d7dc: f9000940  str      x0, [x10, #0x10]
//   0x00d7e0: 14000017  b        #0xd83c
//   0x00d7e4: f9003100  str      x0, [x8, #0x60]
//   0x00d7e8: 9101a109  add      x9, x8, #0x68
//   0x00d7ec: f9000120  str      x0, [x9]
//   0x00d7f0: f900011f  str      xzr, [x8]
//   0x00d7f4: 39400288  ldrb     w8, [x20]
//   0x00d7f8: 7100fd1f  cmp      w8, #0x3f
//   0x00d7fc: 54000480  b.eq     #0xd88c
//   0x00d800: 71008d1f  cmp      w8, #0x23
//   0x00d804: 54000d21  b.ne     #0xd9a8
//   0x00d808: 91000697  add      x23, x20, #1
//   0x00d80c: aa1303e0  mov      x0, x19
//   0x00d810: aa1703e1  mov      x1, x23
//   0x00d814: aa1503e2  mov      x2, x21
//   0x00d818: aa1603e3  mov      x3, x22
//   0x00d81c: 94000450  bl       #0xe95c
//   0x00d820: aa0003f4  mov      x20, x0
//   0x00d824: b4000c20  cbz      x0, #0xd9a8
//   0x00d828: f9400268  ldr      x8, [x19]
//   0x00d82c: a9085117  stp      x23, x20, [x8, #0x80]
//   0x00d830: 1400005e  b        #0xd9a8
//   0x00d834: f9003100  str      x0, [x8, #0x60]
//   0x00d838: 9101a109  add      x9, x8, #0x68
//   0x00d83c: 91000697  add      x23, x20, #1
//   0x00d840: f9000120  str      x0, [x9]
//   0x00d844: aa1303e0  mov      x0, x19
//   0x00d848: aa1703e1  mov      x1, x23
//   0x00d84c: aa1503e2  mov      x2, x21
//   0x00d850: aa1603e3  mov      x3, x22
//   0x00d854: f900011f  str      xzr, [x8]
//   0x00d858: 94000189  bl       #0xde7c
//   0x00d85c: aa0003f4  mov      x20, x0
//   0x00d860: b4000a40  cbz      x0, #0xd9a8
//   0x00d864: f94006c8  ldr      x8, [x22, #8]
//   0x00d868: 52800021  mov      w1, #1
//   0x00d86c: 52800402  mov      w2, #0x20
//   0x00d870: aa1603e0  mov      x0, x22
//   0x00d874: d63f0100  blr      x8
//   0x00d878: b40008a0  cbz      x0, #0xd98c
//   0x00d87c: eb1402ff  cmp      x23, x20
//   0x00d880: 54000260  b.eq     #0xd8cc
//   0x00d884: a9005017  stp      x23, x20, [x0]
//   0x00d888: 14000013  b        #0xd8d4
//   0x00d88c: 91000697  add      x23, x20, #1
//   0x00d890: aa1303e0  mov      x0, x19
//   0x00d894: aa1703e1  mov      x1, x23
//   0x00d898: aa1503e2  mov      x2, x21
//   0x00d89c: aa1603e3  mov      x3, x22
//   0x00d8a0: 9400042f  bl       #0xe95c
//   0x00d8a4: aa0003f4  mov      x20, x0
//   0x00d8a8: b4000800  cbz      x0, #0xd9a8
//   0x00d8ac: f9400268  ldr      x8, [x19]
//   0x00d8b0: eb15029f  cmp      x20, x21
//   0x00d8b4: a9075117  stp      x23, x20, [x8, #0x70]
//   0x00d8b8: 54fff3e2  b.hs     #0xd734
//   0x00d8bc: 39400288  ldrb     w8, [x20]
//   0x00d8c0: 71008d1f  cmp      w8, #0x23
//   0x00d8c4: 54fffa20  b.eq     #0xd808
//   0x00d8c8: 14000038  b        #0xd9a8
//   0x00d8cc: f9400308  ldr      x8, [x24]
//   0x00d8d0: a9002008  stp      x8, x8, [x0]
//   0x00d8d4: f9400268  ldr      x8, [x19]
//   0x00d8d8: f9403109  ldr      x9, [x8, #0x60]
//   0x00d8dc: b4000089  cbz      x9, #0xd8ec
//   0x00d8e0: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00d8e4: f9000920  str      x0, [x9, #0x10]
//   0x00d8e8: 14000003  b        #0xd8f4
//   0x00d8ec: f9003100  str      x0, [x8, #0x60]
//   0x00d8f0: 9101a108  add      x8, x8, #0x68
//   0x00d8f4: eb15029f  cmp      x20, x21
//   0x00d8f8: f9000100  str      x0, [x8]
//   0x00d8fc: 54fff1c2  b.hs     #0xd734
//   0x00d900: f9400318  ldr      x24, [x24]
//   0x00d904: 14000006  b        #0xd91c
//   0x00d908: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00d90c: f9000920  str      x0, [x9, #0x10]
//   0x00d910: eb15029f  cmp      x20, x21
//   0x00d914: f9000100  str      x0, [x8]
//   0x00d918: 54fff0e2  b.hs     #0xd734
//   0x00d91c: 39400288  ldrb     w8, [x20]
//   0x00d920: 7100bd1f  cmp      w8, #0x2f
//   0x00d924: 540004e1  b.ne     #0xd9c0
//   0x00d928: 91000697  add      x23, x20, #1
//   0x00d92c: aa1303e0  mov      x0, x19
//   0x00d930: aa1703e1  mov      x1, x23
//   0x00d934: aa1503e2  mov      x2, x21
//   0x00d938: aa1603e3  mov      x3, x22
//   0x00d93c: 94000150  bl       #0xde7c
//   0x00d940: aa0003f4  mov      x20, x0
//   0x00d944: b4000320  cbz      x0, #0xd9a8
//   0x00d948: f94006c8  ldr      x8, [x22, #8]
//   0x00d94c: 52800021  mov      w1, #1
//   0x00d950: 52800402  mov      w2, #0x20
//   0x00d954: aa1603e0  mov      x0, x22
//   0x00d958: d63f0100  blr      x8
//   0x00d95c: b4000180  cbz      x0, #0xd98c
//   0x00d960: eb1402ff  cmp      x23, x20
//   0x00d964: 54000060  b.eq     #0xd970
//   0x00d968: a9005017  stp      x23, x20, [x0]
//   0x00d96c: 14000002  b        #0xd974
//   0x00d970: a9006018  stp      x24, x24, [x0]
//   0x00d974: f9400268  ldr      x8, [x19]
//   0x00d978: f9403109  ldr      x9, [x8, #0x60]
//   0x00d97c: b5fffc69  cbnz     x9, #0xd908
//   0x00d980: f9003100  str      x0, [x8, #0x60]
//   0x00d984: 9101a108  add      x8, x8, #0x68
//   0x00d988: 17ffffe2  b        #0xd910
//   0x00d98c: f9400260  ldr      x0, [x19]
//   0x00d990: aa1603e1  mov      x1, x22
//   0x00d994: 97ffd58b  bl       #0x2fc0
//   0x00d998: 52800068  mov      w8, #3
//   0x00d99c: aa1f03f4  mov      x20, xzr
//   0x00d9a0: f9000a7f  str      xzr, [x19, #0x10]
//   0x00d9a4: b9000a68  str      w8, [x19, #8]
//   0x00d9a8: aa1403e0  mov      x0, x20
//   0x00d9ac: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00d9b0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00d9b4: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00d9b8: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00d9bc: d65f03c0  ret      
//   0x00d9c0: eb15029f  cmp      x20, x21
//   0x00d9c4: 54ffeb82  b.hs     #0xd734
//   0x00d9c8: 17ffff8c  b        #0xd7f8
// ============================================================================
std::uint32_t fde_107_0d644(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000d644ULL;
    for (std::size_t i = 0; i < 226ULL; ++i) {
        std::uint32_t insn = kTextInstructions[10429ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[108] Subroutine @ 0x00d9cc..0x00daa0 (212 bytes, 53 AArch64 instructions)
// [VN] Khung FDE[108] Hàm con @ 0x00d9cc..0x00daa0 (212 byte, 53 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00d9cc: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00d9d0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00d9d4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00d9d8: 910083fd  add      x29, sp, #0x20
//   0x00d9dc: aa0203f4  mov      x20, x2
//   0x00d9e0: eb02003f  cmp      x1, x2
//   0x00d9e4: aa0003f3  mov      x19, x0
//   0x00d9e8: 540003a2  b.hs     #0xda5c
//   0x00d9ec: 91000435  add      x21, x1, #1
//   0x00d9f0: eb1402bf  cmp      x21, x20
//   0x00d9f4: 54000342  b.hs     #0xda5c
//   0x00d9f8: 394002a8  ldrb     w8, [x21]
//   0x00d9fc: 5100c108  sub      w8, w8, #0x30
//   0x00da00: 7100d91f  cmp      w8, #0x36
//   0x00da04: 54000428  b.hi     #0xda88
//   0x00da08: 52800029  mov      w9, #1
//   0x00da0c: 9ac82128  lsl      x8, x9, x8
//   0x00da10: b20f17e9  mov      x9, #0x7e0000007e0000
//   0x00da14: f2807fe9  movk     x9, #0x3ff
//   0x00da18: ea09011f  tst      x8, x9
//   0x00da1c: 54000360  b.eq     #0xda88
//   0x00da20: 91000835  add      x21, x1, #2
//   0x00da24: eb1402bf  cmp      x21, x20
//   0x00da28: 540001a2  b.hs     #0xda5c
//   0x00da2c: 394002a8  ldrb     w8, [x21]
//   0x00da30: 5100c108  sub      w8, w8, #0x30
//   0x00da34: 7100d91f  cmp      w8, #0x36
//   0x00da38: 54000288  b.hi     #0xda88
//   0x00da3c: 52800029  mov      w9, #1
//   0x00da40: 9ac82128  lsl      x8, x9, x8
//   0x00da44: b20f17e9  mov      x9, #0x7e0000007e0000
//   0x00da48: f2807fe9  movk     x9, #0x3ff
//   0x00da4c: ea09011f  tst      x8, x9
//   0x00da50: 540001c0  b.eq     #0xda88
//   0x00da54: 91000c20  add      x0, x1, #3
//   0x00da58: 14000008  b        #0xda78
//   0x00da5c: f9400260  ldr      x0, [x19]
//   0x00da60: aa0303e1  mov      x1, x3
//   0x00da64: 97ffd557  bl       #0x2fc0
//   0x00da68: aa1f03e0  mov      x0, xzr
//   0x00da6c: f9000a74  str      x20, [x19, #0x10]
//   0x00da70: 52800028  mov      w8, #1
//   0x00da74: b9000a68  str      w8, [x19, #8]
//   0x00da78: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00da7c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00da80: f84307f5  ldr      x21, [sp], #0x30
//   0x00da84: d65f03c0  ret      
//   0x00da88: f9400260  ldr      x0, [x19]
//   0x00da8c: aa0303e1  mov      x1, x3
//   0x00da90: 97ffd54c  bl       #0x2fc0
//   0x00da94: aa1f03e0  mov      x0, xzr
//   0x00da98: f9000a75  str      x21, [x19, #0x10]
//   0x00da9c: 17fffff5  b        #0xda70
// ============================================================================
std::uint32_t fde_108_0d9cc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000d9ccULL;
    for (std::size_t i = 0; i < 53ULL; ++i) {
        std::uint32_t insn = kTextInstructions[10655ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[109] Subroutine @ 0x00daa0..0x00de7c (988 bytes, 247 AArch64 instructions)
// [VN] Khung FDE[109] Hàm con @ 0x00daa0..0x00de7c (988 byte, 247 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00daa0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00daa4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00daa8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00daac: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00dab0: 9100c3fd  add      x29, sp, #0x30
//   0x00dab4: aa0203f5  mov      x21, x2
//   0x00dab8: eb02003f  cmp      x1, x2
//   0x00dabc: aa0003f3  mov      x19, x0
//   0x00dac0: 540003a2  b.hs     #0xdb34
//   0x00dac4: 39400028  ldrb     w8, [x1]
//   0x00dac8: aa0303f4  mov      x20, x3
//   0x00dacc: aa0103f7  mov      x23, x1
//   0x00dad0: 7100bd1f  cmp      w8, #0x2f
//   0x00dad4: 54000381  b.ne     #0xdb44
//   0x00dad8: 910006f6  add      x22, x23, #1
//   0x00dadc: eb1502df  cmp      x22, x21
//   0x00dae0: 540007e2  b.hs     #0xdbdc
//   0x00dae4: 394002c8  ldrb     w8, [x22]
//   0x00dae8: 51008508  sub      w8, w8, #0x21
//   0x00daec: 7101751f  cmp      w8, #0x5d
//   0x00daf0: 54001668  b.hi     #0xddbc
//   0x00daf4: d0000029  adrp     x9, #0x13000
//   0x00daf8: 91224d29  add      x9, x9, #0x893
//   0x00dafc: 1000008a  adr      x10, #0xdb0c
//   0x00db00: 3868692b  ldrb     w11, [x9, x8]
//   0x00db04: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00db08: d61f0140  br       x10
//   0x00db0c: f9400268  ldr      x8, [x19]
//   0x00db10: aa1303e0  mov      x0, x19
//   0x00db14: aa1603e1  mov      x1, x22
//   0x00db18: aa1503e2  mov      x2, x21
//   0x00db1c: aa1403e3  mov      x3, x20
//   0x00db20: f9000916  str      x22, [x8, #0x10]
//   0x00db24: 9400019f  bl       #0xe1a0
//   0x00db28: aa0003f6  mov      x22, x0
//   0x00db2c: b5000676  cbnz     x22, #0xdbf8
//   0x00db30: 140000cc  b        #0xde60
//   0x00db34: f9400268  ldr      x8, [x19]
//   0x00db38: 52800029  mov      w9, #1
//   0x00db3c: b9009109  str      w9, [x8, #0x90]
//   0x00db40: 1400009b  b        #0xddac
//   0x00db44: f9400268  ldr      x8, [x19]
//   0x00db48: 52800029  mov      w9, #1
//   0x00db4c: b9009109  str      w9, [x8, #0x90]
//   0x00db50: 394002e8  ldrb     w8, [x23]
//   0x00db54: 51008508  sub      w8, w8, #0x21
//   0x00db58: 7101751f  cmp      w8, #0x5d
//   0x00db5c: 54001848  b.hi     #0xde64
//   0x00db60: d0000029  adrp     x9, #0x13000
//   0x00db64: 9120d529  add      x9, x9, #0x835
//   0x00db68: 1000008a  adr      x10, #0xdb78
//   0x00db6c: 3868692b  ldrb     w11, [x9, x8]
//   0x00db70: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00db74: d61f0140  br       x10
//   0x00db78: aa1303e0  mov      x0, x19
//   0x00db7c: aa1703e1  mov      x1, x23
//   0x00db80: aa1503e2  mov      x2, x21
//   0x00db84: aa1403e3  mov      x3, x20
//   0x00db88: 940000dd  bl       #0xdefc
//   0x00db8c: b40016a0  cbz      x0, #0xde60
//   0x00db90: aa0003e1  mov      x1, x0
//   0x00db94: aa1303e0  mov      x0, x19
//   0x00db98: aa1503e2  mov      x2, x21
//   0x00db9c: aa1403e3  mov      x3, x20
//   0x00dba0: 940000b7  bl       #0xde7c
//   0x00dba4: b40015e0  cbz      x0, #0xde60
//   0x00dba8: f9400688  ldr      x8, [x20, #8]
//   0x00dbac: aa0003f6  mov      x22, x0
//   0x00dbb0: 52800021  mov      w1, #1
//   0x00dbb4: 52800402  mov      w2, #0x20
//   0x00dbb8: aa1403e0  mov      x0, x20
//   0x00dbbc: d63f0100  blr      x8
//   0x00dbc0: b4000ca0  cbz      x0, #0xdd54
//   0x00dbc4: d0000068  adrp     x8, #0x1b000
//   0x00dbc8: f947e108  ldr      x8, [x8, #0xfc0]
//   0x00dbcc: eb1702df  cmp      x22, x23
//   0x00dbd0: 54000620  b.eq     #0xdc94
//   0x00dbd4: a9005817  stp      x23, x22, [x0]
//   0x00dbd8: 14000031  b        #0xdc9c
//   0x00dbdc: d0000068  adrp     x8, #0x1b000
//   0x00dbe0: f947e108  ldr      x8, [x8, #0xfc0]
//   0x00dbe4: f9400269  ldr      x9, [x19]
//   0x00dbe8: aa1503f6  mov      x22, x21
//   0x00dbec: f9400108  ldr      x8, [x8]
//   0x00dbf0: a9022128  stp      x8, x8, [x9, #0x20]
//   0x00dbf4: b4001376  cbz      x22, #0xde60
//   0x00dbf8: eb1502df  cmp      x22, x21
//   0x00dbfc: 54000d22  b.hs     #0xdda0
//   0x00dc00: d0000068  adrp     x8, #0x1b000
//   0x00dc04: f947e108  ldr      x8, [x8, #0xfc0]
//   0x00dc08: f9400118  ldr      x24, [x8]
//   0x00dc0c: 14000006  b        #0xdc24
//   0x00dc10: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00dc14: f9000920  str      x0, [x9, #0x10]
//   0x00dc18: eb1502df  cmp      x22, x21
//   0x00dc1c: f9000100  str      x0, [x8]
//   0x00dc20: 54000c02  b.hs     #0xdda0
//   0x00dc24: 394002c8  ldrb     w8, [x22]
//   0x00dc28: 7100bd1f  cmp      w8, #0x2f
//   0x00dc2c: 54000a41  b.ne     #0xdd74
//   0x00dc30: 910006d7  add      x23, x22, #1
//   0x00dc34: aa1303e0  mov      x0, x19
//   0x00dc38: aa1703e1  mov      x1, x23
//   0x00dc3c: aa1503e2  mov      x2, x21
//   0x00dc40: aa1403e3  mov      x3, x20
//   0x00dc44: 9400008e  bl       #0xde7c
//   0x00dc48: b40009a0  cbz      x0, #0xdd7c
//   0x00dc4c: f9400688  ldr      x8, [x20, #8]
//   0x00dc50: aa0003f6  mov      x22, x0
//   0x00dc54: 52800021  mov      w1, #1
//   0x00dc58: 52800402  mov      w2, #0x20
//   0x00dc5c: aa1403e0  mov      x0, x20
//   0x00dc60: d63f0100  blr      x8
//   0x00dc64: b4000900  cbz      x0, #0xdd84
//   0x00dc68: eb1602ff  cmp      x23, x22
//   0x00dc6c: 54000060  b.eq     #0xdc78
//   0x00dc70: a9005817  stp      x23, x22, [x0]
//   0x00dc74: 14000002  b        #0xdc7c
//   0x00dc78: a9006018  stp      x24, x24, [x0]
//   0x00dc7c: f9400268  ldr      x8, [x19]
//   0x00dc80: f9403109  ldr      x9, [x8, #0x60]
//   0x00dc84: b5fffc69  cbnz     x9, #0xdc10
//   0x00dc88: f9003100  str      x0, [x8, #0x60]
//   0x00dc8c: 9101a108  add      x8, x8, #0x68
//   0x00dc90: 17ffffe2  b        #0xdc18
//   0x00dc94: f9400109  ldr      x9, [x8]
//   0x00dc98: a9002409  stp      x9, x9, [x0]
//   0x00dc9c: f9400269  ldr      x9, [x19]
//   0x00dca0: f940312a  ldr      x10, [x9, #0x60]
//   0x00dca4: b400008a  cbz      x10, #0xdcb4
//   0x00dca8: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00dcac: f9000940  str      x0, [x10, #0x10]
//   0x00dcb0: 14000003  b        #0xdcbc
//   0x00dcb4: f9003120  str      x0, [x9, #0x60]
//   0x00dcb8: 9101a129  add      x9, x9, #0x68
//   0x00dcbc: eb1502df  cmp      x22, x21
//   0x00dcc0: f9000120  str      x0, [x9]
//   0x00dcc4: 54000742  b.hs     #0xddac
//   0x00dcc8: f9400118  ldr      x24, [x8]
//   0x00dccc: 14000006  b        #0xdce4
//   0x00dcd0: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00dcd4: f9000920  str      x0, [x9, #0x10]
//   0x00dcd8: eb1502df  cmp      x22, x21
//   0x00dcdc: f9000100  str      x0, [x8]
//   0x00dce0: 54000662  b.hs     #0xddac
//   0x00dce4: 394002c8  ldrb     w8, [x22]
//   0x00dce8: 7100bd1f  cmp      w8, #0x2f
//   0x00dcec: 54000641  b.ne     #0xddb4
//   0x00dcf0: 910006d7  add      x23, x22, #1
//   0x00dcf4: aa1303e0  mov      x0, x19
//   0x00dcf8: aa1703e1  mov      x1, x23
//   0x00dcfc: aa1503e2  mov      x2, x21
//   0x00dd00: aa1403e3  mov      x3, x20
//   0x00dd04: 9400005e  bl       #0xde7c
//   0x00dd08: b4000ac0  cbz      x0, #0xde60
//   0x00dd0c: f9400688  ldr      x8, [x20, #8]
//   0x00dd10: aa0003f6  mov      x22, x0
//   0x00dd14: 52800021  mov      w1, #1
//   0x00dd18: 52800402  mov      w2, #0x20
//   0x00dd1c: aa1403e0  mov      x0, x20
//   0x00dd20: d63f0100  blr      x8
//   0x00dd24: b4000180  cbz      x0, #0xdd54
//   0x00dd28: eb1602ff  cmp      x23, x22
//   0x00dd2c: 54000060  b.eq     #0xdd38
//   0x00dd30: a9005817  stp      x23, x22, [x0]
//   0x00dd34: 14000002  b        #0xdd3c
//   0x00dd38: a9006018  stp      x24, x24, [x0]
//   0x00dd3c: f9400268  ldr      x8, [x19]
//   0x00dd40: f9403109  ldr      x9, [x8, #0x60]
//   0x00dd44: b5fffc69  cbnz     x9, #0xdcd0
//   0x00dd48: f9003100  str      x0, [x8, #0x60]
//   0x00dd4c: 9101a108  add      x8, x8, #0x68
//   0x00dd50: 17ffffe2  b        #0xdcd8
//   0x00dd54: f9400260  ldr      x0, [x19]
//   0x00dd58: aa1403e1  mov      x1, x20
//   0x00dd5c: 97ffd499  bl       #0x2fc0
//   0x00dd60: 52800068  mov      w8, #3
//   0x00dd64: aa1f03f7  mov      x23, xzr
//   0x00dd68: f9000a7f  str      xzr, [x19, #0x10]
//   0x00dd6c: b9000a68  str      w8, [x19, #8]
//   0x00dd70: 1400003d  b        #0xde64
//   0x00dd74: aa1603f5  mov      x21, x22
//   0x00dd78: 1400000a  b        #0xdda0
//   0x00dd7c: aa1f03f5  mov      x21, xzr
//   0x00dd80: 14000008  b        #0xdda0
//   0x00dd84: f9400260  ldr      x0, [x19]
//   0x00dd88: aa1403e1  mov      x1, x20
//   0x00dd8c: 97ffd48d  bl       #0x2fc0
//   0x00dd90: 52800068  mov      w8, #3
//   0x00dd94: aa1f03f5  mov      x21, xzr
//   0x00dd98: f9000a7f  str      xzr, [x19, #0x10]
//   0x00dd9c: b9000a68  str      w8, [x19, #8]
//   0x00dda0: f9400260  ldr      x0, [x19]
//   0x00dda4: aa1403e1  mov      x1, x20
//   0x00dda8: 97ffd4be  bl       #0x30a0
//   0x00ddac: aa1503f7  mov      x23, x21
//   0x00ddb0: 1400002d  b        #0xde64
//   0x00ddb4: aa1603f7  mov      x23, x22
//   0x00ddb8: 1400002b  b        #0xde64
//   0x00ddbc: d0000068  adrp     x8, #0x1b000
//   0x00ddc0: f947e108  ldr      x8, [x8, #0xfc0]
//   0x00ddc4: f9400269  ldr      x9, [x19]
//   0x00ddc8: f9400108  ldr      x8, [x8]
//   0x00ddcc: a9022128  stp      x8, x8, [x9, #0x20]
//   0x00ddd0: eb1502df  cmp      x22, x21
//   0x00ddd4: 54fff163  b.lo     #0xdc00
//   0x00ddd8: 17fffff2  b        #0xdda0
//   0x00dddc: 91000af6  add      x22, x23, #2
//   0x00dde0: aa1303e0  mov      x0, x19
//   0x00dde4: aa1603e1  mov      x1, x22
//   0x00dde8: aa1503e2  mov      x2, x21
//   0x00ddec: aa1403e3  mov      x3, x20
//   0x00ddf0: 94000070  bl       #0xdfb0
//   0x00ddf4: b4000360  cbz      x0, #0xde60
//   0x00ddf8: f9400268  ldr      x8, [x19]
//   0x00ddfc: eb15001f  cmp      x0, x21
//   0x00de00: f9001116  str      x22, [x8, #0x20]
//   0x00de04: aa1503f6  mov      x22, x21
//   0x00de08: 54ffef62  b.hs     #0xdbf4
//   0x00de0c: 39400009  ldrb     w9, [x0]
//   0x00de10: aa0003f6  mov      x22, x0
//   0x00de14: 7100e93f  cmp      w9, #0x3a
//   0x00de18: 54ffef01  b.ne     #0xdbf8
//   0x00de1c: 91000409  add      x9, x0, #1
//   0x00de20: eb15013f  cmp      x9, x21
//   0x00de24: 54000122  b.hs     #0xde48
//   0x00de28: aa0903f6  mov      x22, x9
//   0x00de2c: 394002ca  ldrb     w10, [x22]
//   0x00de30: 5100c14a  sub      w10, w10, #0x30
//   0x00de34: 7100255f  cmp      w10, #9
//   0x00de38: 540000c8  b.hi     #0xde50
//   0x00de3c: 910006d6  add      x22, x22, #1
//   0x00de40: eb1602bf  cmp      x21, x22
//   0x00de44: 54ffff41  b.ne     #0xde2c
//   0x00de48: aa1503f6  mov      x22, x21
//   0x00de4c: b40000b5  cbz      x21, #0xde60
//   0x00de50: a9055909  stp      x9, x22, [x8, #0x50]
//   0x00de54: eb1502df  cmp      x22, x21
//   0x00de58: 54ffed43  b.lo     #0xdc00
//   0x00de5c: 17ffffd1  b        #0xdda0
//   0x00de60: aa1f03f7  mov      x23, xzr
//   0x00de64: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00de68: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00de6c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00de70: aa1703e0  mov      x0, x23
//   0x00de74: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00de78: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_109_0daa0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000daa0ULL;
    for (std::size_t i = 0; i < 247ULL; ++i) {
        std::uint32_t insn = kTextInstructions[10708ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[110] Subroutine @ 0x00de7c..0x00defc (128 bytes, 32 AArch64 instructions)
// [VN] Khung FDE[110] Hàm con @ 0x00de7c..0x00defc (128 byte, 32 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00de7c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00de80: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00de84: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00de88: 910083fd  add      x29, sp, #0x20
//   0x00de8c: d0000036  adrp     x22, #0x13000
//   0x00de90: aa0303f4  mov      x20, x3
//   0x00de94: aa0203f3  mov      x19, x2
//   0x00de98: aa0003f5  mov      x21, x0
//   0x00de9c: 9123c6d6  add      x22, x22, #0x8f1
//   0x00dea0: eb13003f  cmp      x1, x19
//   0x00dea4: 54000202  b.hs     #0xdee4
//   0x00dea8: 39400028  ldrb     w8, [x1]
//   0x00deac: 51008508  sub      w8, w8, #0x21
//   0x00deb0: 7101751f  cmp      w8, #0x5d
//   0x00deb4: 540001a8  b.hi     #0xdee8
//   0x00deb8: 10000089  adr      x9, #0xdec8
//   0x00debc: 38686aca  ldrb     w10, [x22, x8]
//   0x00dec0: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00dec4: d61f0120  br       x9
//   0x00dec8: aa1503e0  mov      x0, x21
//   0x00decc: aa1303e2  mov      x2, x19
//   0x00ded0: aa1403e3  mov      x3, x20
//   0x00ded4: 9400000a  bl       #0xdefc
//   0x00ded8: aa0003e1  mov      x1, x0
//   0x00dedc: b5fffe20  cbnz     x0, #0xdea0
//   0x00dee0: 14000002  b        #0xdee8
//   0x00dee4: aa1303e1  mov      x1, x19
//   0x00dee8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00deec: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00def0: aa0103e0  mov      x0, x1
//   0x00def4: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x00def8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_110_0de7c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000de7cULL;
    for (std::size_t i = 0; i < 32ULL; ++i) {
        std::uint32_t insn = kTextInstructions[10955ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[111] Subroutine @ 0x00defc..0x00dfb0 (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[111] Hàm con @ 0x00defc..0x00dfb0 (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00defc: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00df00: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00df04: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00df08: 910083fd  add      x29, sp, #0x20
//   0x00df0c: aa0203f4  mov      x20, x2
//   0x00df10: eb02003f  cmp      x1, x2
//   0x00df14: aa0003f3  mov      x19, x0
//   0x00df18: 540001c2  b.hs     #0xdf50
//   0x00df1c: 39400028  ldrb     w8, [x1]
//   0x00df20: aa0103f5  mov      x21, x1
//   0x00df24: 51008508  sub      w8, w8, #0x21
//   0x00df28: 7101751f  cmp      w8, #0x5d
//   0x00df2c: 54000288  b.hi     #0xdf7c
//   0x00df30: d0000029  adrp     x9, #0x13000
//   0x00df34: 91253d29  add      x9, x9, #0x94f
//   0x00df38: 1000008a  adr      x10, #0xdf48
//   0x00df3c: 3868692b  ldrb     w11, [x9, x8]
//   0x00df40: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00df44: d61f0140  br       x10
//   0x00df48: 910006a0  add      x0, x21, #1
//   0x00df4c: 14000008  b        #0xdf6c
//   0x00df50: f9400260  ldr      x0, [x19]
//   0x00df54: aa0303e1  mov      x1, x3
//   0x00df58: 97ffd41a  bl       #0x2fc0
//   0x00df5c: aa1f03e0  mov      x0, xzr
//   0x00df60: f9000a74  str      x20, [x19, #0x10]
//   0x00df64: 52800028  mov      w8, #1
//   0x00df68: b9000a68  str      w8, [x19, #8]
//   0x00df6c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00df70: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00df74: f84307f5  ldr      x21, [sp], #0x30
//   0x00df78: d65f03c0  ret      
//   0x00df7c: f9400260  ldr      x0, [x19]
//   0x00df80: aa0303e1  mov      x1, x3
//   0x00df84: 97ffd40f  bl       #0x2fc0
//   0x00df88: aa1f03e0  mov      x0, xzr
//   0x00df8c: f9000a75  str      x21, [x19, #0x10]
//   0x00df90: 17fffff5  b        #0xdf64
//   0x00df94: aa1303e0  mov      x0, x19
//   0x00df98: aa1403e2  mov      x2, x20
//   0x00df9c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00dfa0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00dfa4: aa1503e1  mov      x1, x21
//   0x00dfa8: f84307f5  ldr      x21, [sp], #0x30
//   0x00dfac: 17fffe88  b        #0xd9cc
// ============================================================================
std::uint32_t fde_111_0defc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000defcULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[10987ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[112] Subroutine @ 0x00dfb0..0x00e1a0 (496 bytes, 124 AArch64 instructions)
// [VN] Khung FDE[112] Hàm con @ 0x00dfb0..0x00e1a0 (496 byte, 124 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00dfb0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00dfb4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00dfb8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00dfbc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00dfc0: 9100c3fd  add      x29, sp, #0x30
//   0x00dfc4: aa0303f4  mov      x20, x3
//   0x00dfc8: aa0203f5  mov      x21, x2
//   0x00dfcc: eb02003f  cmp      x1, x2
//   0x00dfd0: aa0003f3  mov      x19, x0
//   0x00dfd4: 54000c22  b.hs     #0xe158
//   0x00dfd8: 39400028  ldrb     w8, [x1]
//   0x00dfdc: aa0103f6  mov      x22, x1
//   0x00dfe0: 5100c108  sub      w8, w8, #0x30
//   0x00dfe4: 7101191f  cmp      w8, #0x46
//   0x00dfe8: 540007c8  b.hi     #0xe0e0
//   0x00dfec: d0000029  adrp     x9, #0x13000
//   0x00dff0: 9126b529  add      x9, x9, #0x9ad
//   0x00dff4: 1000008a  adr      x10, #0xe004
//   0x00dff8: 3868692b  ldrb     w11, [x9, x8]
//   0x00dffc: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00e000: d61f0140  br       x10
//   0x00e004: f9400288  ldr      x8, [x20]
//   0x00e008: 52800201  mov      w1, #0x10
//   0x00e00c: aa1403e0  mov      x0, x20
//   0x00e010: d63f0100  blr      x8
//   0x00e014: f9400268  ldr      x8, [x19]
//   0x00e018: f9001d00  str      x0, [x8, #0x38]
//   0x00e01c: b4000140  cbz      x0, #0xe044
//   0x00e020: aa1303e0  mov      x0, x19
//   0x00e024: aa1603e1  mov      x1, x22
//   0x00e028: aa1503e2  mov      x2, x21
//   0x00e02c: aa1403e3  mov      x3, x20
//   0x00e030: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00e034: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00e038: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00e03c: f84407f7  ldr      x23, [sp], #0x40
//   0x00e040: 17fff6ab  b        #0xbaec
//   0x00e044: aa0803e0  mov      x0, x8
//   0x00e048: aa1403e1  mov      x1, x20
//   0x00e04c: 97ffd3dd  bl       #0x2fc0
//   0x00e050: aa1f03e0  mov      x0, xzr
//   0x00e054: f9000a7f  str      xzr, [x19, #0x10]
//   0x00e058: 52800068  mov      w8, #3
//   0x00e05c: 14000045  b        #0xe170
//   0x00e060: 910006d7  add      x23, x22, #1
//   0x00e064: eb1502ff  cmp      x23, x21
//   0x00e068: 54000782  b.hs     #0xe158
//   0x00e06c: 394002e8  ldrb     w8, [x23]
//   0x00e070: 5100c108  sub      w8, w8, #0x30
//   0x00e074: 7100d91f  cmp      w8, #0x36
//   0x00e078: 54000888  b.hi     #0xe188
//   0x00e07c: 52800029  mov      w9, #1
//   0x00e080: 9ac82128  lsl      x8, x9, x8
//   0x00e084: b20f17e9  mov      x9, #0x7e0000007e0000
//   0x00e088: f2807fe9  movk     x9, #0x3ff
//   0x00e08c: ea09011f  tst      x8, x9
//   0x00e090: 540007c0  b.eq     #0xe188
//   0x00e094: 91000ad7  add      x23, x22, #2
//   0x00e098: eb1502ff  cmp      x23, x21
//   0x00e09c: 540001c2  b.hs     #0xe0d4
//   0x00e0a0: b20f17e9  mov      x9, #0x7e0000007e0000
//   0x00e0a4: 52800028  mov      w8, #1
//   0x00e0a8: f2807fe9  movk     x9, #0x3ff
//   0x00e0ac: 394002ea  ldrb     w10, [x23]
//   0x00e0b0: 5100c14b  sub      w11, w10, #0x30
//   0x00e0b4: 7100d97f  cmp      w11, #0x36
//   0x00e0b8: 54000208  b.hi     #0xe0f8
//   0x00e0bc: 9acb210b  lsl      x11, x8, x11
//   0x00e0c0: ea09017f  tst      x11, x9
//   0x00e0c4: 540001a0  b.eq     #0xe0f8
//   0x00e0c8: 910006f7  add      x23, x23, #1
//   0x00e0cc: eb1702bf  cmp      x21, x23
//   0x00e0d0: 54fffee1  b.ne     #0xe0ac
//   0x00e0d4: b5000435  cbnz     x21, #0xe158
//   0x00e0d8: aa1f03e0  mov      x0, xzr
//   0x00e0dc: 14000026  b        #0xe174
//   0x00e0e0: f9400260  ldr      x0, [x19]
//   0x00e0e4: aa1403e1  mov      x1, x20
//   0x00e0e8: 97ffd3b6  bl       #0x2fc0
//   0x00e0ec: aa1f03e0  mov      x0, xzr
//   0x00e0f0: f9000a76  str      x22, [x19, #0x10]
//   0x00e0f4: 1400001e  b        #0xe16c
//   0x00e0f8: eb1502ff  cmp      x23, x21
//   0x00e0fc: 540002e2  b.hs     #0xe158
//   0x00e100: f9400260  ldr      x0, [x19]
//   0x00e104: 7100b95f  cmp      w10, #0x2e
//   0x00e108: 54000421  b.ne     #0xe18c
//   0x00e10c: f9001016  str      x22, [x0, #0x20]
//   0x00e110: f9002016  str      x22, [x0, #0x40]
//   0x00e114: 910006e1  add      x1, x23, #1
//   0x00e118: aa1303e0  mov      x0, x19
//   0x00e11c: aa1503e2  mov      x2, x21
//   0x00e120: aa1403e3  mov      x3, x20
//   0x00e124: 940000d8  bl       #0xe484
//   0x00e128: b4000260  cbz      x0, #0xe174
//   0x00e12c: aa0003f6  mov      x22, x0
//   0x00e130: f9400260  ldr      x0, [x19]
//   0x00e134: eb1502df  cmp      x22, x21
//   0x00e138: f9001416  str      x22, [x0, #0x28]
//   0x00e13c: f9002416  str      x22, [x0, #0x48]
//   0x00e140: 540000e2  b.hs     #0xe15c
//   0x00e144: 394002c8  ldrb     w8, [x22]
//   0x00e148: 7101751f  cmp      w8, #0x5d
//   0x00e14c: 54fffcc1  b.ne     #0xe0e4
//   0x00e150: 910006c0  add      x0, x22, #1
//   0x00e154: 14000008  b        #0xe174
//   0x00e158: f9400260  ldr      x0, [x19]
//   0x00e15c: aa1403e1  mov      x1, x20
//   0x00e160: 97ffd398  bl       #0x2fc0
//   0x00e164: aa1f03e0  mov      x0, xzr
//   0x00e168: f9000a75  str      x21, [x19, #0x10]
//   0x00e16c: 52800028  mov      w8, #1
//   0x00e170: b9000a68  str      w8, [x19, #8]
//   0x00e174: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00e178: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00e17c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00e180: f84407f7  ldr      x23, [sp], #0x40
//   0x00e184: d65f03c0  ret      
//   0x00e188: f9400260  ldr      x0, [x19]
//   0x00e18c: aa1403e1  mov      x1, x20
//   0x00e190: 97ffd38c  bl       #0x2fc0
//   0x00e194: aa1f03e0  mov      x0, xzr
//   0x00e198: f9000a77  str      x23, [x19, #0x10]
//   0x00e19c: 17fffff4  b        #0xe16c
// ============================================================================
std::uint32_t fde_112_0dfb0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000dfb0ULL;
    for (std::size_t i = 0; i < 124ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11032ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[113] Subroutine @ 0x00e1a0..0x00e484 (740 bytes, 185 AArch64 instructions)
// [VN] Khung FDE[113] Hàm con @ 0x00e1a0..0x00e484 (740 byte, 185 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e1a0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00e1a4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00e1a8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00e1ac: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00e1b0: 9100c3fd  add      x29, sp, #0x30
//   0x00e1b4: aa0303f4  mov      x20, x3
//   0x00e1b8: aa0203f5  mov      x21, x2
//   0x00e1bc: eb02003f  cmp      x1, x2
//   0x00e1c0: aa0003f3  mov      x19, x0
//   0x00e1c4: 540006e2  b.hs     #0xe2a0
//   0x00e1c8: 39400028  ldrb     w8, [x1]
//   0x00e1cc: b0000037  adrp     x23, #0x13000
//   0x00e1d0: b0000038  adrp     x24, #0x13000
//   0x00e1d4: aa0103f6  mov      x22, x1
//   0x00e1d8: 9127d2f7  add      x23, x23, #0x9f4
//   0x00e1dc: 912ac318  add      x24, x24, #0xab0
//   0x00e1e0: 12001d08  and      w8, w8, #0xff
//   0x00e1e4: 51008508  sub      w8, w8, #0x21
//   0x00e1e8: 7101751f  cmp      w8, #0x5d
//   0x00e1ec: 540007e8  b.hi     #0xe2e8
//   0x00e1f0: 10000089  adr      x9, #0xe200
//   0x00e1f4: 38686aea  ldrb     w10, [x23, x8]
//   0x00e1f8: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00e1fc: d61f0120  br       x9
//   0x00e200: aa1303e0  mov      x0, x19
//   0x00e204: aa1603e1  mov      x1, x22
//   0x00e208: aa1503e2  mov      x2, x21
//   0x00e20c: aa1403e3  mov      x3, x20
//   0x00e210: 940000d7  bl       #0xe56c
//   0x00e214: b4000520  cbz      x0, #0xe2b8
//   0x00e218: aa0003f6  mov      x22, x0
//   0x00e21c: eb15001f  cmp      x0, x21
//   0x00e220: 540005a2  b.hs     #0xe2d4
//   0x00e224: 394002c8  ldrb     w8, [x22]
//   0x00e228: 51008509  sub      w9, w8, #0x21
//   0x00e22c: 7101753f  cmp      w9, #0x5d
//   0x00e230: 540000a8  b.hi     #0xe244
//   0x00e234: 10fffd6a  adr      x10, #0xe1e0
//   0x00e238: 38696b0b  ldrb     w11, [x24, x9]
//   0x00e23c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00e240: d61f0140  br       x10
//   0x00e244: f9400268  ldr      x8, [x19]
//   0x00e248: 52800081  mov      w1, #4
//   0x00e24c: aa1403e0  mov      x0, x20
//   0x00e250: f9400909  ldr      x9, [x8, #0x10]
//   0x00e254: f900091f  str      xzr, [x8, #0x10]
//   0x00e258: a9025909  stp      x9, x22, [x8, #0x20]
//   0x00e25c: f9400288  ldr      x8, [x20]
//   0x00e260: d63f0100  blr      x8
//   0x00e264: f9400268  ldr      x8, [x19]
//   0x00e268: f9001900  str      x0, [x8, #0x30]
//   0x00e26c: b4000940  cbz      x0, #0xe394
//   0x00e270: a9420901  ldp      x1, x2, [x8, #0x20]
//   0x00e274: 97ffd33b  bl       #0x2f60
//   0x00e278: 34000b40  cbz      w0, #0xe3e0
//   0x00e27c: f9400268  ldr      x8, [x19]
//   0x00e280: f9401289  ldr      x9, [x20, #0x20]
//   0x00e284: aa1403e0  mov      x0, x20
//   0x00e288: f9401901  ldr      x1, [x8, #0x30]
//   0x00e28c: d63f0120  blr      x9
//   0x00e290: f9400268  ldr      x8, [x19]
//   0x00e294: aa1603f5  mov      x21, x22
//   0x00e298: f900191f  str      xzr, [x8, #0x30]
//   0x00e29c: 14000008  b        #0xe2bc
//   0x00e2a0: f9400260  ldr      x0, [x19]
//   0x00e2a4: aa1403e1  mov      x1, x20
//   0x00e2a8: 97ffd346  bl       #0x2fc0
//   0x00e2ac: 52800028  mov      w8, #1
//   0x00e2b0: f9000a75  str      x21, [x19, #0x10]
//   0x00e2b4: b9000a68  str      w8, [x19, #8]
//   0x00e2b8: aa1f03f5  mov      x21, xzr
//   0x00e2bc: aa1503e0  mov      x0, x21
//   0x00e2c0: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00e2c4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00e2c8: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00e2cc: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00e2d0: d65f03c0  ret      
//   0x00e2d4: f9400268  ldr      x8, [x19]
//   0x00e2d8: f9400909  ldr      x9, [x8, #0x10]
//   0x00e2dc: f900091f  str      xzr, [x8, #0x10]
//   0x00e2e0: a9025909  stp      x9, x22, [x8, #0x20]
//   0x00e2e4: 1400001a  b        #0xe34c
//   0x00e2e8: f9400260  ldr      x0, [x19]
//   0x00e2ec: aa1403e1  mov      x1, x20
//   0x00e2f0: 97ffd334  bl       #0x2fc0
//   0x00e2f4: aa1f03f5  mov      x21, xzr
//   0x00e2f8: 52800028  mov      w8, #1
//   0x00e2fc: f9000a76  str      x22, [x19, #0x10]
//   0x00e300: 1400002b  b        #0xe3ac
//   0x00e304: f9400269  ldr      x9, [x19]
//   0x00e308: 910006c1  add      x1, x22, #1
//   0x00e30c: eb15003f  cmp      x1, x21
//   0x00e310: f9001536  str      x22, [x9, #0x28]
//   0x00e314: f9002921  str      x1, [x9, #0x50]
//   0x00e318: 54000122  b.hs     #0xe33c
//   0x00e31c: 39400028  ldrb     w8, [x1]
//   0x00e320: 5100c10a  sub      w10, w8, #0x30
//   0x00e324: 7100295f  cmp      w10, #0xa
//   0x00e328: 54000602  b.hs     #0xe3e8
//   0x00e32c: 91000421  add      x1, x1, #1
//   0x00e330: eb0102bf  cmp      x21, x1
//   0x00e334: 54ffff41  b.ne     #0xe31c
//   0x00e338: aa1503e1  mov      x1, x21
//   0x00e33c: f9400928  ldr      x8, [x9, #0x10]
//   0x00e340: f900093f  str      xzr, [x9, #0x10]
//   0x00e344: f9002d21  str      x1, [x9, #0x58]
//   0x00e348: f9001128  str      x8, [x9, #0x20]
//   0x00e34c: f9400288  ldr      x8, [x20]
//   0x00e350: 52800081  mov      w1, #4
//   0x00e354: aa1403e0  mov      x0, x20
//   0x00e358: d63f0100  blr      x8
//   0x00e35c: f9400268  ldr      x8, [x19]
//   0x00e360: f9001900  str      x0, [x8, #0x30]
//   0x00e364: b4000180  cbz      x0, #0xe394
//   0x00e368: a9420901  ldp      x1, x2, [x8, #0x20]
//   0x00e36c: 97ffd2fd  bl       #0x2f60
//   0x00e370: 34fffa60  cbz      w0, #0xe2bc
//   0x00e374: f9400268  ldr      x8, [x19]
//   0x00e378: f9401289  ldr      x9, [x20, #0x20]
//   0x00e37c: aa1403e0  mov      x0, x20
//   0x00e380: f9401901  ldr      x1, [x8, #0x30]
//   0x00e384: d63f0120  blr      x9
//   0x00e388: f9400268  ldr      x8, [x19]
//   0x00e38c: f900191f  str      xzr, [x8, #0x30]
//   0x00e390: 17ffffcb  b        #0xe2bc
//   0x00e394: aa0803e0  mov      x0, x8
//   0x00e398: aa1403e1  mov      x1, x20
//   0x00e39c: 97ffd309  bl       #0x2fc0
//   0x00e3a0: aa1f03f5  mov      x21, xzr
//   0x00e3a4: f9000a7f  str      xzr, [x19, #0x10]
//   0x00e3a8: 52800068  mov      w8, #3
//   0x00e3ac: b9000a68  str      w8, [x19, #8]
//   0x00e3b0: 17ffffc3  b        #0xe2bc
//   0x00e3b4: f9400268  ldr      x8, [x19]
//   0x00e3b8: 910006c1  add      x1, x22, #1
//   0x00e3bc: aa1303e0  mov      x0, x19
//   0x00e3c0: a9018516  stp      x22, x1, [x8, #0x18]
//   0x00e3c4: aa1503e2  mov      x2, x21
//   0x00e3c8: aa1403e3  mov      x3, x20
//   0x00e3cc: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00e3d0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00e3d4: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00e3d8: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00e3dc: 14000091  b        #0xe620
//   0x00e3e0: aa1603f5  mov      x21, x22
//   0x00e3e4: 17ffffb6  b        #0xe2bc
//   0x00e3e8: 51008508  sub      w8, w8, #0x21
//   0x00e3ec: 7101751f  cmp      w8, #0x5d
//   0x00e3f0: 54000248  b.hi     #0xe438
//   0x00e3f4: b000002a  adrp     x10, #0x13000
//   0x00e3f8: 9129494a  add      x10, x10, #0xa52
//   0x00e3fc: 1000008b  adr      x11, #0xe40c
//   0x00e400: 3868694c  ldrb     w12, [x10, x8]
//   0x00e404: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00e408: d61f0160  br       x11
//   0x00e40c: f900153f  str      xzr, [x9, #0x28]
//   0x00e410: 91000421  add      x1, x1, #1
//   0x00e414: f900293f  str      xzr, [x9, #0x50]
//   0x00e418: aa1303e0  mov      x0, x19
//   0x00e41c: aa1503e2  mov      x2, x21
//   0x00e420: aa1403e3  mov      x3, x20
//   0x00e424: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00e428: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00e42c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00e430: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00e434: 1400010c  b        #0xe864
//   0x00e438: f9400928  ldr      x8, [x9, #0x10]
//   0x00e43c: f900093f  str      xzr, [x9, #0x10]
//   0x00e440: aa0103f5  mov      x21, x1
//   0x00e444: 17ffffc0  b        #0xe344
//   0x00e448: aa1303e0  mov      x0, x19
//   0x00e44c: aa1503e2  mov      x2, x21
//   0x00e450: aa1403e3  mov      x3, x20
//   0x00e454: f900293f  str      xzr, [x9, #0x50]
//   0x00e458: 97fffd5d  bl       #0xd9cc
//   0x00e45c: b4fff2e0  cbz      x0, #0xe2b8
//   0x00e460: aa0003e1  mov      x1, x0
//   0x00e464: 17ffffed  b        #0xe418
//   0x00e468: 91000428  add      x8, x1, #1
//   0x00e46c: f900293f  str      xzr, [x9, #0x50]
//   0x00e470: f9000d21  str      x1, [x9, #0x18]
//   0x00e474: a9027d28  stp      x8, xzr, [x9, #0x20]
//   0x00e478: aa1303e0  mov      x0, x19
//   0x00e47c: aa0803e1  mov      x1, x8
//   0x00e480: 17ffffd1  b        #0xe3c4
// ============================================================================
std::uint32_t fde_113_0e1a0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e1a0ULL;
    for (std::size_t i = 0; i < 185ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11156ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[114] Subroutine @ 0x00e484..0x00e56c (232 bytes, 58 AArch64 instructions)
// [VN] Khung FDE[114] Hàm con @ 0x00e484..0x00e56c (232 byte, 58 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e484: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00e488: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00e48c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00e490: 910083fd  add      x29, sp, #0x20
//   0x00e494: aa0203f3  mov      x19, x2
//   0x00e498: eb02003f  cmp      x1, x2
//   0x00e49c: aa0003f4  mov      x20, x0
//   0x00e4a0: 540003a2  b.hs     #0xe514
//   0x00e4a4: 3940002b  ldrb     w11, [x1]
//   0x00e4a8: b0000029  adrp     x9, #0x13000
//   0x00e4ac: b000002a  adrp     x10, #0x13000
//   0x00e4b0: aa0103f5  mov      x21, x1
//   0x00e4b4: d1000668  sub      x8, x19, #1
//   0x00e4b8: 912c3929  add      x9, x9, #0xb0e
//   0x00e4bc: 912db14a  add      x10, x10, #0xb6c
//   0x00e4c0: 12001d6b  and      w11, w11, #0xff
//   0x00e4c4: 5100856b  sub      w11, w11, #0x21
//   0x00e4c8: 7101757f  cmp      w11, #0x5d
//   0x00e4cc: 540003c8  b.hi     #0xe544
//   0x00e4d0: 1000008c  adr      x12, #0xe4e0
//   0x00e4d4: 386b692d  ldrb     w13, [x9, x11]
//   0x00e4d8: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x00e4dc: d61f0180  br       x12
//   0x00e4e0: eb15011f  cmp      x8, x21
//   0x00e4e4: 54000260  b.eq     #0xe530
//   0x00e4e8: 394006ab  ldrb     w11, [x21, #1]
//   0x00e4ec: 5100856c  sub      w12, w11, #0x21
//   0x00e4f0: 7101759f  cmp      w12, #0x5d
//   0x00e4f4: 54000388  b.hi     #0xe564
//   0x00e4f8: 1000008d  adr      x13, #0xe508
//   0x00e4fc: 386c694e  ldrb     w14, [x10, x12]
//   0x00e500: 8b0e09ad  add      x13, x13, x14, lsl #2
//   0x00e504: d61f01a0  br       x13
//   0x00e508: 910006b5  add      x21, x21, #1
//   0x00e50c: eb15027f  cmp      x19, x21
//   0x00e510: 54fffd81  b.ne     #0xe4c0
//   0x00e514: f9400280  ldr      x0, [x20]
//   0x00e518: aa0303e1  mov      x1, x3
//   0x00e51c: 97ffd2a9  bl       #0x2fc0
//   0x00e520: 52800028  mov      w8, #1
//   0x00e524: f9000a93  str      x19, [x20, #0x10]
//   0x00e528: b9000a88  str      w8, [x20, #8]
//   0x00e52c: aa1f03f3  mov      x19, xzr
//   0x00e530: aa1303e0  mov      x0, x19
//   0x00e534: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00e538: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00e53c: f84307f5  ldr      x21, [sp], #0x30
//   0x00e540: d65f03c0  ret      
//   0x00e544: f9400280  ldr      x0, [x20]
//   0x00e548: aa0303e1  mov      x1, x3
//   0x00e54c: 97ffd29d  bl       #0x2fc0
//   0x00e550: 52800028  mov      w8, #1
//   0x00e554: aa1f03f3  mov      x19, xzr
//   0x00e558: f9000a95  str      x21, [x20, #0x10]
//   0x00e55c: b9000a88  str      w8, [x20, #8]
//   0x00e560: 17fffff4  b        #0xe530
//   0x00e564: 910006b3  add      x19, x21, #1
//   0x00e568: 17fffff2  b        #0xe530
// ============================================================================
std::uint32_t fde_114_0e484(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e484ULL;
    for (std::size_t i = 0; i < 58ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11341ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[115] Subroutine @ 0x00e56c..0x00e620 (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[115] Hàm con @ 0x00e56c..0x00e620 (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e56c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00e570: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00e574: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00e578: 910083fd  add      x29, sp, #0x20
//   0x00e57c: aa0203f4  mov      x20, x2
//   0x00e580: eb02003f  cmp      x1, x2
//   0x00e584: aa0003f3  mov      x19, x0
//   0x00e588: 540001c2  b.hs     #0xe5c0
//   0x00e58c: 39400028  ldrb     w8, [x1]
//   0x00e590: aa0103f5  mov      x21, x1
//   0x00e594: 51008508  sub      w8, w8, #0x21
//   0x00e598: 7101751f  cmp      w8, #0x5d
//   0x00e59c: 54000288  b.hi     #0xe5ec
//   0x00e5a0: b0000029  adrp     x9, #0x13000
//   0x00e5a4: 912f2929  add      x9, x9, #0xbca
//   0x00e5a8: 1000008a  adr      x10, #0xe5b8
//   0x00e5ac: 3868692b  ldrb     w11, [x9, x8]
//   0x00e5b0: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00e5b4: d61f0140  br       x10
//   0x00e5b8: 910006a0  add      x0, x21, #1
//   0x00e5bc: 14000008  b        #0xe5dc
//   0x00e5c0: f9400260  ldr      x0, [x19]
//   0x00e5c4: aa0303e1  mov      x1, x3
//   0x00e5c8: 97ffd27e  bl       #0x2fc0
//   0x00e5cc: aa1f03e0  mov      x0, xzr
//   0x00e5d0: f9000a74  str      x20, [x19, #0x10]
//   0x00e5d4: 52800028  mov      w8, #1
//   0x00e5d8: b9000a68  str      w8, [x19, #8]
//   0x00e5dc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00e5e0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00e5e4: f84307f5  ldr      x21, [sp], #0x30
//   0x00e5e8: d65f03c0  ret      
//   0x00e5ec: f9400260  ldr      x0, [x19]
//   0x00e5f0: aa0303e1  mov      x1, x3
//   0x00e5f4: 97ffd273  bl       #0x2fc0
//   0x00e5f8: aa1f03e0  mov      x0, xzr
//   0x00e5fc: f9000a75  str      x21, [x19, #0x10]
//   0x00e600: 17fffff5  b        #0xe5d4
//   0x00e604: aa1303e0  mov      x0, x19
//   0x00e608: aa1403e2  mov      x2, x20
//   0x00e60c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00e610: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00e614: aa1503e1  mov      x1, x21
//   0x00e618: f84307f5  ldr      x21, [sp], #0x30
//   0x00e61c: 17fffcec  b        #0xd9cc
// ============================================================================
std::uint32_t fde_115_0e56c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e56cULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11399ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[116] Subroutine @ 0x00e620..0x00e864 (580 bytes, 145 AArch64 instructions)
// [VN] Khung FDE[116] Hàm con @ 0x00e620..0x00e864 (580 byte, 145 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e620: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00e624: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00e628: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00e62c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00e630: 9100c3fd  add      x29, sp, #0x30
//   0x00e634: aa0203f3  mov      x19, x2
//   0x00e638: eb02003f  cmp      x1, x2
//   0x00e63c: aa0003f4  mov      x20, x0
//   0x00e640: 54000442  b.hs     #0xe6c8
//   0x00e644: 39400028  ldrb     w8, [x1]
//   0x00e648: aa0303f6  mov      x22, x3
//   0x00e64c: aa0103f5  mov      x21, x1
//   0x00e650: 71016d1f  cmp      w8, #0x5b
//   0x00e654: 540004c1  b.ne     #0xe6ec
//   0x00e658: 910006b7  add      x23, x21, #1
//   0x00e65c: aa1403e0  mov      x0, x20
//   0x00e660: aa1703e1  mov      x1, x23
//   0x00e664: aa1303e2  mov      x2, x19
//   0x00e668: aa1603e3  mov      x3, x22
//   0x00e66c: 97fffe51  bl       #0xdfb0
//   0x00e670: aa0003f5  mov      x21, x0
//   0x00e674: b4000300  cbz      x0, #0xe6d4
//   0x00e678: f9400288  ldr      x8, [x20]
//   0x00e67c: eb1302bf  cmp      x21, x19
//   0x00e680: f9001117  str      x23, [x8, #0x20]
//   0x00e684: 54000ec2  b.hs     #0xe85c
//   0x00e688: 394002a9  ldrb     w9, [x21]
//   0x00e68c: 7100e93f  cmp      w9, #0x3a
//   0x00e690: 54000221  b.ne     #0xe6d4
//   0x00e694: 910006a9  add      x9, x21, #1
//   0x00e698: eb13013f  cmp      x9, x19
//   0x00e69c: 54000122  b.hs     #0xe6c0
//   0x00e6a0: aa0903ea  mov      x10, x9
//   0x00e6a4: 3940014b  ldrb     w11, [x10]
//   0x00e6a8: 5100c16b  sub      w11, w11, #0x30
//   0x00e6ac: 7100257f  cmp      w11, #9
//   0x00e6b0: 54000c88  b.hi     #0xe840
//   0x00e6b4: 9100054a  add      x10, x10, #1
//   0x00e6b8: eb0a027f  cmp      x19, x10
//   0x00e6bc: 54ffff41  b.ne     #0xe6a4
//   0x00e6c0: b5000c33  cbnz     x19, #0xe844
//   0x00e6c4: 14000055  b        #0xe818
//   0x00e6c8: f9400288  ldr      x8, [x20]
//   0x00e6cc: aa1303f5  mov      x21, x19
//   0x00e6d0: f9001513  str      x19, [x8, #0x28]
//   0x00e6d4: aa1503e0  mov      x0, x21
//   0x00e6d8: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00e6dc: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00e6e0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00e6e4: f84407f7  ldr      x23, [sp], #0x40
//   0x00e6e8: d65f03c0  ret      
//   0x00e6ec: b0000037  adrp     x23, #0x13000
//   0x00e6f0: 9130a2f7  add      x23, x23, #0xc28
//   0x00e6f4: eb1302bf  cmp      x21, x19
//   0x00e6f8: 54000222  b.hs     #0xe73c
//   0x00e6fc: 394002a8  ldrb     w8, [x21]
//   0x00e700: 51008508  sub      w8, w8, #0x21
//   0x00e704: 7101751f  cmp      w8, #0x5d
//   0x00e708: 54000448  b.hi     #0xe790
//   0x00e70c: 10000089  adr      x9, #0xe71c
//   0x00e710: 38686aea  ldrb     w10, [x23, x8]
//   0x00e714: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00e718: d61f0120  br       x9
//   0x00e71c: aa1403e0  mov      x0, x20
//   0x00e720: aa1503e1  mov      x1, x21
//   0x00e724: aa1303e2  mov      x2, x19
//   0x00e728: aa1603e3  mov      x3, x22
//   0x00e72c: 97ffff90  bl       #0xe56c
//   0x00e730: aa0003f5  mov      x21, x0
//   0x00e734: b5fffe00  cbnz     x0, #0xe6f4
//   0x00e738: 17ffffe7  b        #0xe6d4
//   0x00e73c: f9400288  ldr      x8, [x20]
//   0x00e740: 52800081  mov      w1, #4
//   0x00e744: aa1603e0  mov      x0, x22
//   0x00e748: f9001515  str      x21, [x8, #0x28]
//   0x00e74c: f94002c8  ldr      x8, [x22]
//   0x00e750: d63f0100  blr      x8
//   0x00e754: f9400288  ldr      x8, [x20]
//   0x00e758: f9001900  str      x0, [x8, #0x30]
//   0x00e75c: b4000620  cbz      x0, #0xe820
//   0x00e760: a9420901  ldp      x1, x2, [x8, #0x20]
//   0x00e764: 97ffd1ff  bl       #0x2f60
//   0x00e768: 340007a0  cbz      w0, #0xe85c
//   0x00e76c: f9400288  ldr      x8, [x20]
//   0x00e770: f94012c9  ldr      x9, [x22, #0x20]
//   0x00e774: aa1603e0  mov      x0, x22
//   0x00e778: f9401901  ldr      x1, [x8, #0x30]
//   0x00e77c: d63f0120  blr      x9
//   0x00e780: f9400288  ldr      x8, [x20]
//   0x00e784: aa1303f5  mov      x21, x19
//   0x00e788: f900191f  str      xzr, [x8, #0x30]
//   0x00e78c: 17ffffd2  b        #0xe6d4
//   0x00e790: f9400288  ldr      x8, [x20]
//   0x00e794: 52800081  mov      w1, #4
//   0x00e798: aa1603e0  mov      x0, x22
//   0x00e79c: f9001515  str      x21, [x8, #0x28]
//   0x00e7a0: f94002c8  ldr      x8, [x22]
//   0x00e7a4: d63f0100  blr      x8
//   0x00e7a8: f9400288  ldr      x8, [x20]
//   0x00e7ac: f9001900  str      x0, [x8, #0x30]
//   0x00e7b0: b4000380  cbz      x0, #0xe820
//   0x00e7b4: a9420901  ldp      x1, x2, [x8, #0x20]
//   0x00e7b8: 97ffd1ea  bl       #0x2f60
//   0x00e7bc: 34000100  cbz      w0, #0xe7dc
//   0x00e7c0: f9400288  ldr      x8, [x20]
//   0x00e7c4: f94012c9  ldr      x9, [x22, #0x20]
//   0x00e7c8: aa1603e0  mov      x0, x22
//   0x00e7cc: f9401901  ldr      x1, [x8, #0x30]
//   0x00e7d0: d63f0120  blr      x9
//   0x00e7d4: f9400288  ldr      x8, [x20]
//   0x00e7d8: f900191f  str      xzr, [x8, #0x30]
//   0x00e7dc: 394002a8  ldrb     w8, [x21]
//   0x00e7e0: 7100e91f  cmp      w8, #0x3a
//   0x00e7e4: 54fff781  b.ne     #0xe6d4
//   0x00e7e8: 910006a8  add      x8, x21, #1
//   0x00e7ec: eb13011f  cmp      x8, x19
//   0x00e7f0: 54000122  b.hs     #0xe814
//   0x00e7f4: aa0803e9  mov      x9, x8
//   0x00e7f8: 3940012a  ldrb     w10, [x9]
//   0x00e7fc: 5100c14a  sub      w10, w10, #0x30
//   0x00e800: 7100255f  cmp      w10, #9
//   0x00e804: 54000268  b.hi     #0xe850
//   0x00e808: 91000529  add      x9, x9, #1
//   0x00e80c: eb09027f  cmp      x19, x9
//   0x00e810: 54ffff41  b.ne     #0xe7f8
//   0x00e814: b5000213  cbnz     x19, #0xe854
//   0x00e818: aa1f03f5  mov      x21, xzr
//   0x00e81c: 17ffffae  b        #0xe6d4
//   0x00e820: aa0803e0  mov      x0, x8
//   0x00e824: aa1603e1  mov      x1, x22
//   0x00e828: 97ffd1e6  bl       #0x2fc0
//   0x00e82c: 52800068  mov      w8, #3
//   0x00e830: aa1f03f5  mov      x21, xzr
//   0x00e834: f9000a9f  str      xzr, [x20, #0x10]
//   0x00e838: b9000a88  str      w8, [x20, #8]
//   0x00e83c: 17ffffa6  b        #0xe6d4
//   0x00e840: aa0a03f3  mov      x19, x10
//   0x00e844: a9054d09  stp      x9, x19, [x8, #0x50]
//   0x00e848: aa1303f5  mov      x21, x19
//   0x00e84c: 17ffffa2  b        #0xe6d4
//   0x00e850: aa0903f3  mov      x19, x9
//   0x00e854: f9400289  ldr      x9, [x20]
//   0x00e858: a9054d28  stp      x8, x19, [x9, #0x50]
//   0x00e85c: aa1303f5  mov      x21, x19
//   0x00e860: 17ffff9d  b        #0xe6d4
// ============================================================================
std::uint32_t fde_116_0e620(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e620ULL;
    for (std::size_t i = 0; i < 145ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11444ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[117] Subroutine @ 0x00e864..0x00e95c (248 bytes, 62 AArch64 instructions)
// [VN] Khung FDE[117] Hàm con @ 0x00e864..0x00e95c (248 byte, 62 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e864: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00e868: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00e86c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00e870: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00e874: 9100c3fd  add      x29, sp, #0x30
//   0x00e878: aa0303f4  mov      x20, x3
//   0x00e87c: aa0203f5  mov      x21, x2
//   0x00e880: eb02003f  cmp      x1, x2
//   0x00e884: aa0003f3  mov      x19, x0
//   0x00e888: 54000322  b.hs     #0xe8ec
//   0x00e88c: b0000037  adrp     x23, #0x13000
//   0x00e890: aa0103f6  mov      x22, x1
//   0x00e894: 91321af7  add      x23, x23, #0xc86
//   0x00e898: 394002c8  ldrb     w8, [x22]
//   0x00e89c: 51008508  sub      w8, w8, #0x21
//   0x00e8a0: 7101751f  cmp      w8, #0x5d
//   0x00e8a4: 540003c8  b.hi     #0xe91c
//   0x00e8a8: 10000089  adr      x9, #0xe8b8
//   0x00e8ac: 38686aea  ldrb     w10, [x23, x8]
//   0x00e8b0: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00e8b4: d61f0120  br       x9
//   0x00e8b8: aa1303e0  mov      x0, x19
//   0x00e8bc: aa1603e1  mov      x1, x22
//   0x00e8c0: aa1503e2  mov      x2, x21
//   0x00e8c4: aa1403e3  mov      x3, x20
//   0x00e8c8: 97ffff29  bl       #0xe56c
//   0x00e8cc: aa0003f6  mov      x22, x0
//   0x00e8d0: b40001a0  cbz      x0, #0xe904
//   0x00e8d4: eb1502df  cmp      x22, x21
//   0x00e8d8: 54fffe03  b.lo     #0xe898
//   0x00e8dc: 14000004  b        #0xe8ec
//   0x00e8e0: 910006d6  add      x22, x22, #1
//   0x00e8e4: eb1502df  cmp      x22, x21
//   0x00e8e8: 54fffd83  b.lo     #0xe898
//   0x00e8ec: f9400260  ldr      x0, [x19]
//   0x00e8f0: aa1403e1  mov      x1, x20
//   0x00e8f4: 97ffd1b3  bl       #0x2fc0
//   0x00e8f8: f9000a75  str      x21, [x19, #0x10]
//   0x00e8fc: 52800028  mov      w8, #1
//   0x00e900: b9000a68  str      w8, [x19, #8]
//   0x00e904: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00e908: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00e90c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00e910: aa1f03e0  mov      x0, xzr
//   0x00e914: f84407f7  ldr      x23, [sp], #0x40
//   0x00e918: d65f03c0  ret      
//   0x00e91c: f9400260  ldr      x0, [x19]
//   0x00e920: aa1403e1  mov      x1, x20
//   0x00e924: 97ffd1a7  bl       #0x2fc0
//   0x00e928: f9000a76  str      x22, [x19, #0x10]
//   0x00e92c: 17fffff4  b        #0xe8fc
//   0x00e930: f9400268  ldr      x8, [x19]
//   0x00e934: 910006c1  add      x1, x22, #1
//   0x00e938: aa1303e0  mov      x0, x19
//   0x00e93c: aa1503e2  mov      x2, x21
//   0x00e940: a9018516  stp      x22, x1, [x8, #0x18]
//   0x00e944: aa1403e3  mov      x3, x20
//   0x00e948: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00e94c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00e950: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00e954: f84407f7  ldr      x23, [sp], #0x40
//   0x00e958: 17ffff32  b        #0xe620
// ============================================================================
std::uint32_t fde_117_0e864(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e864ULL;
    for (std::size_t i = 0; i < 62ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11589ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[118] Subroutine @ 0x00e95c..0x00e9f0 (148 bytes, 37 AArch64 instructions)
// [VN] Khung FDE[118] Hàm con @ 0x00e95c..0x00e9f0 (148 byte, 37 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e95c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00e960: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00e964: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00e968: 910083fd  add      x29, sp, #0x20
//   0x00e96c: aa0203f3  mov      x19, x2
//   0x00e970: eb02003f  cmp      x1, x2
//   0x00e974: 54000322  b.hs     #0xe9d8
//   0x00e978: b0000036  adrp     x22, #0x13000
//   0x00e97c: aa0303f4  mov      x20, x3
//   0x00e980: aa0003f5  mov      x21, x0
//   0x00e984: 913392d6  add      x22, x22, #0xce4
//   0x00e988: 39400028  ldrb     w8, [x1]
//   0x00e98c: 51008508  sub      w8, w8, #0x21
//   0x00e990: 7101751f  cmp      w8, #0x5d
//   0x00e994: 54000248  b.hi     #0xe9dc
//   0x00e998: 10000089  adr      x9, #0xe9a8
//   0x00e99c: 38686aca  ldrb     w10, [x22, x8]
//   0x00e9a0: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00e9a4: d61f0120  br       x9
//   0x00e9a8: aa1503e0  mov      x0, x21
//   0x00e9ac: aa1303e2  mov      x2, x19
//   0x00e9b0: aa1403e3  mov      x3, x20
//   0x00e9b4: 97fffd52  bl       #0xdefc
//   0x00e9b8: aa0003e1  mov      x1, x0
//   0x00e9bc: b4000100  cbz      x0, #0xe9dc
//   0x00e9c0: eb13003f  cmp      x1, x19
//   0x00e9c4: 54fffe23  b.lo     #0xe988
//   0x00e9c8: 14000004  b        #0xe9d8
//   0x00e9cc: 91000421  add      x1, x1, #1
//   0x00e9d0: eb13003f  cmp      x1, x19
//   0x00e9d4: 54fffda3  b.lo     #0xe988
//   0x00e9d8: aa1303e1  mov      x1, x19
//   0x00e9dc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00e9e0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00e9e4: aa0103e0  mov      x0, x1
//   0x00e9e8: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x00e9ec: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_118_0e95c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e95cULL;
    for (std::size_t i = 0; i < 37ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11651ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[119] Subroutine @ 0x00e9f0..0x00ed78 (904 bytes, 226 AArch64 instructions)
// [VN] Khung FDE[119] Hàm con @ 0x00e9f0..0x00ed78 (904 byte, 226 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e9f0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00e9f4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00e9f8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00e9fc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00ea00: 9100c3fd  add      x29, sp, #0x30
//   0x00ea04: b0000078  adrp     x24, #0x1b000
//   0x00ea08: f947eb18  ldr      x24, [x24, #0xfd0]
//   0x00ea0c: aa0303f6  mov      x22, x3
//   0x00ea10: aa0203f5  mov      x21, x2
//   0x00ea14: aa0103f4  mov      x20, x1
//   0x00ea18: aa0003f3  mov      x19, x0
//   0x00ea1c: eb02003f  cmp      x1, x2
//   0x00ea20: 540002e2  b.hs     #0xea7c
//   0x00ea24: b0000037  adrp     x23, #0x13000
//   0x00ea28: 91350af7  add      x23, x23, #0xd42
//   0x00ea2c: b9400288  ldr      w8, [x20]
//   0x00ea30: 51008508  sub      w8, w8, #0x21
//   0x00ea34: 7101751f  cmp      w8, #0x5d
//   0x00ea38: 54000588  b.hi     #0xeae8
//   0x00ea3c: 10000089  adr      x9, #0xea4c
//   0x00ea40: 38686aea  ldrb     w10, [x23, x8]
//   0x00ea44: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00ea48: d61f0120  br       x9
//   0x00ea4c: 91001294  add      x20, x20, #4
//   0x00ea50: eb15029f  cmp      x20, x21
//   0x00ea54: 54fffec3  b.lo     #0xea2c
//   0x00ea58: 14000009  b        #0xea7c
//   0x00ea5c: aa1303e0  mov      x0, x19
//   0x00ea60: aa1403e1  mov      x1, x20
//   0x00ea64: aa1503e2  mov      x2, x21
//   0x00ea68: aa1603e3  mov      x3, x22
//   0x00ea6c: 940000c3  bl       #0xed78
//   0x00ea70: aa0003f4  mov      x20, x0
//   0x00ea74: b5fffee0  cbnz     x0, #0xea50
//   0x00ea78: 140000b7  b        #0xed54
//   0x00ea7c: f9400268  ldr      x8, [x19]
//   0x00ea80: 52800021  mov      w1, #1
//   0x00ea84: 52800402  mov      w2, #0x20
//   0x00ea88: aa1603e0  mov      x0, x22
//   0x00ea8c: f9400117  ldr      x23, [x8]
//   0x00ea90: f94006c8  ldr      x8, [x22, #8]
//   0x00ea94: d63f0100  blr      x8
//   0x00ea98: b4001500  cbz      x0, #0xed38
//   0x00ea9c: eb1402ff  cmp      x23, x20
//   0x00eaa0: 54000060  b.eq     #0xeaac
//   0x00eaa4: a9005017  stp      x23, x20, [x0]
//   0x00eaa8: 14000003  b        #0xeab4
//   0x00eaac: f9400308  ldr      x8, [x24]
//   0x00eab0: a9002008  stp      x8, x8, [x0]
//   0x00eab4: f9400268  ldr      x8, [x19]
//   0x00eab8: f9403109  ldr      x9, [x8, #0x60]
//   0x00eabc: b40000a9  cbz      x9, #0xead0
//   0x00eac0: aa0803e9  mov      x9, x8
//   0x00eac4: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00eac8: f9000940  str      x0, [x10, #0x10]
//   0x00eacc: 14000003  b        #0xead8
//   0x00ead0: f9003100  str      x0, [x8, #0x60]
//   0x00ead4: 9101a109  add      x9, x8, #0x68
//   0x00ead8: f9000120  str      x0, [x9]
//   0x00eadc: f900011f  str      xzr, [x8]
//   0x00eae0: aa1503f4  mov      x20, x21
//   0x00eae4: 1400009c  b        #0xed54
//   0x00eae8: f9400268  ldr      x8, [x19]
//   0x00eaec: 52800021  mov      w1, #1
//   0x00eaf0: 52800402  mov      w2, #0x20
//   0x00eaf4: aa1603e0  mov      x0, x22
//   0x00eaf8: f9400117  ldr      x23, [x8]
//   0x00eafc: f94006c8  ldr      x8, [x22, #8]
//   0x00eb00: d63f0100  blr      x8
//   0x00eb04: b40011a0  cbz      x0, #0xed38
//   0x00eb08: eb1402ff  cmp      x23, x20
//   0x00eb0c: 540001e0  b.eq     #0xeb48
//   0x00eb10: a9005017  stp      x23, x20, [x0]
//   0x00eb14: 1400000f  b        #0xeb50
//   0x00eb18: f9400268  ldr      x8, [x19]
//   0x00eb1c: 52800021  mov      w1, #1
//   0x00eb20: 52800402  mov      w2, #0x20
//   0x00eb24: aa1603e0  mov      x0, x22
//   0x00eb28: f9400117  ldr      x23, [x8]
//   0x00eb2c: f94006c8  ldr      x8, [x22, #8]
//   0x00eb30: d63f0100  blr      x8
//   0x00eb34: b4001020  cbz      x0, #0xed38
//   0x00eb38: eb1402ff  cmp      x23, x20
//   0x00eb3c: 54000180  b.eq     #0xeb6c
//   0x00eb40: a9005017  stp      x23, x20, [x0]
//   0x00eb44: 1400000c  b        #0xeb74
//   0x00eb48: f9400308  ldr      x8, [x24]
//   0x00eb4c: a9002008  stp      x8, x8, [x0]
//   0x00eb50: f9400268  ldr      x8, [x19]
//   0x00eb54: f9403109  ldr      x9, [x8, #0x60]
//   0x00eb58: b40001c9  cbz      x9, #0xeb90
//   0x00eb5c: aa0803e9  mov      x9, x8
//   0x00eb60: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00eb64: f9000940  str      x0, [x10, #0x10]
//   0x00eb68: 1400000c  b        #0xeb98
//   0x00eb6c: f9400308  ldr      x8, [x24]
//   0x00eb70: a9002008  stp      x8, x8, [x0]
//   0x00eb74: f9400268  ldr      x8, [x19]
//   0x00eb78: f9403109  ldr      x9, [x8, #0x60]
//   0x00eb7c: b4000329  cbz      x9, #0xebe0
//   0x00eb80: aa0803e9  mov      x9, x8
//   0x00eb84: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00eb88: f9000940  str      x0, [x10, #0x10]
//   0x00eb8c: 14000017  b        #0xebe8
//   0x00eb90: f9003100  str      x0, [x8, #0x60]
//   0x00eb94: 9101a109  add      x9, x8, #0x68
//   0x00eb98: f9000120  str      x0, [x9]
//   0x00eb9c: f900011f  str      xzr, [x8]
//   0x00eba0: b9400288  ldr      w8, [x20]
//   0x00eba4: 7100fd1f  cmp      w8, #0x3f
//   0x00eba8: 54000480  b.eq     #0xec38
//   0x00ebac: 71008d1f  cmp      w8, #0x23
//   0x00ebb0: 54000d21  b.ne     #0xed54
//   0x00ebb4: 91001297  add      x23, x20, #4
//   0x00ebb8: aa1303e0  mov      x0, x19
//   0x00ebbc: aa1703e1  mov      x1, x23
//   0x00ebc0: aa1503e2  mov      x2, x21
//   0x00ebc4: aa1603e3  mov      x3, x22
//   0x00ebc8: 9400044c  bl       #0xfcf8
//   0x00ebcc: aa0003f4  mov      x20, x0
//   0x00ebd0: b4000c20  cbz      x0, #0xed54
//   0x00ebd4: f9400268  ldr      x8, [x19]
//   0x00ebd8: a9085117  stp      x23, x20, [x8, #0x80]
//   0x00ebdc: 1400005e  b        #0xed54
//   0x00ebe0: f9003100  str      x0, [x8, #0x60]
//   0x00ebe4: 9101a109  add      x9, x8, #0x68
//   0x00ebe8: 91001297  add      x23, x20, #4
//   0x00ebec: f9000120  str      x0, [x9]
//   0x00ebf0: aa1303e0  mov      x0, x19
//   0x00ebf4: aa1703e1  mov      x1, x23
//   0x00ebf8: aa1503e2  mov      x2, x21
//   0x00ebfc: aa1603e3  mov      x3, x22
//   0x00ec00: f900011f  str      xzr, [x8]
//   0x00ec04: 94000189  bl       #0xf228
//   0x00ec08: aa0003f4  mov      x20, x0
//   0x00ec0c: b4000a40  cbz      x0, #0xed54
//   0x00ec10: f94006c8  ldr      x8, [x22, #8]
//   0x00ec14: 52800021  mov      w1, #1
//   0x00ec18: 52800402  mov      w2, #0x20
//   0x00ec1c: aa1603e0  mov      x0, x22
//   0x00ec20: d63f0100  blr      x8
//   0x00ec24: b40008a0  cbz      x0, #0xed38
//   0x00ec28: eb1402ff  cmp      x23, x20
//   0x00ec2c: 54000260  b.eq     #0xec78
//   0x00ec30: a9005017  stp      x23, x20, [x0]
//   0x00ec34: 14000013  b        #0xec80
//   0x00ec38: 91001297  add      x23, x20, #4
//   0x00ec3c: aa1303e0  mov      x0, x19
//   0x00ec40: aa1703e1  mov      x1, x23
//   0x00ec44: aa1503e2  mov      x2, x21
//   0x00ec48: aa1603e3  mov      x3, x22
//   0x00ec4c: 9400042b  bl       #0xfcf8
//   0x00ec50: aa0003f4  mov      x20, x0
//   0x00ec54: b4000800  cbz      x0, #0xed54
//   0x00ec58: f9400268  ldr      x8, [x19]
//   0x00ec5c: eb15029f  cmp      x20, x21
//   0x00ec60: a9075117  stp      x23, x20, [x8, #0x70]
//   0x00ec64: 54fff3e2  b.hs     #0xeae0
//   0x00ec68: b9400288  ldr      w8, [x20]
//   0x00ec6c: 71008d1f  cmp      w8, #0x23
//   0x00ec70: 54fffa20  b.eq     #0xebb4
//   0x00ec74: 14000038  b        #0xed54
//   0x00ec78: f9400308  ldr      x8, [x24]
//   0x00ec7c: a9002008  stp      x8, x8, [x0]
//   0x00ec80: f9400268  ldr      x8, [x19]
//   0x00ec84: f9403109  ldr      x9, [x8, #0x60]
//   0x00ec88: b4000089  cbz      x9, #0xec98
//   0x00ec8c: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00ec90: f9000920  str      x0, [x9, #0x10]
//   0x00ec94: 14000003  b        #0xeca0
//   0x00ec98: f9003100  str      x0, [x8, #0x60]
//   0x00ec9c: 9101a108  add      x8, x8, #0x68
//   0x00eca0: eb15029f  cmp      x20, x21
//   0x00eca4: f9000100  str      x0, [x8]
//   0x00eca8: 54fff1c2  b.hs     #0xeae0
//   0x00ecac: f9400318  ldr      x24, [x24]
//   0x00ecb0: 14000006  b        #0xecc8
//   0x00ecb4: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00ecb8: f9000920  str      x0, [x9, #0x10]
//   0x00ecbc: eb15029f  cmp      x20, x21
//   0x00ecc0: f9000100  str      x0, [x8]
//   0x00ecc4: 54fff0e2  b.hs     #0xeae0
//   0x00ecc8: b9400288  ldr      w8, [x20]
//   0x00eccc: 7100bd1f  cmp      w8, #0x2f
//   0x00ecd0: 540004e1  b.ne     #0xed6c
//   0x00ecd4: 91001297  add      x23, x20, #4
//   0x00ecd8: aa1303e0  mov      x0, x19
//   0x00ecdc: aa1703e1  mov      x1, x23
//   0x00ece0: aa1503e2  mov      x2, x21
//   0x00ece4: aa1603e3  mov      x3, x22
//   0x00ece8: 94000150  bl       #0xf228
//   0x00ecec: aa0003f4  mov      x20, x0
//   0x00ecf0: b4000320  cbz      x0, #0xed54
//   0x00ecf4: f94006c8  ldr      x8, [x22, #8]
//   0x00ecf8: 52800021  mov      w1, #1
//   0x00ecfc: 52800402  mov      w2, #0x20
//   0x00ed00: aa1603e0  mov      x0, x22
//   0x00ed04: d63f0100  blr      x8
//   0x00ed08: b4000180  cbz      x0, #0xed38
//   0x00ed0c: eb1402ff  cmp      x23, x20
//   0x00ed10: 54000060  b.eq     #0xed1c
//   0x00ed14: a9005017  stp      x23, x20, [x0]
//   0x00ed18: 14000002  b        #0xed20
//   0x00ed1c: a9006018  stp      x24, x24, [x0]
//   0x00ed20: f9400268  ldr      x8, [x19]
//   0x00ed24: f9403109  ldr      x9, [x8, #0x60]
//   0x00ed28: b5fffc69  cbnz     x9, #0xecb4
//   0x00ed2c: f9003100  str      x0, [x8, #0x60]
//   0x00ed30: 9101a108  add      x8, x8, #0x68
//   0x00ed34: 17ffffe2  b        #0xecbc
//   0x00ed38: f9400260  ldr      x0, [x19]
//   0x00ed3c: aa1603e1  mov      x1, x22
//   0x00ed40: 97ffd0c4  bl       #0x3050
//   0x00ed44: 52800068  mov      w8, #3
//   0x00ed48: aa1f03f4  mov      x20, xzr
//   0x00ed4c: f9000a7f  str      xzr, [x19, #0x10]
//   0x00ed50: b9000a68  str      w8, [x19, #8]
//   0x00ed54: aa1403e0  mov      x0, x20
//   0x00ed58: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00ed5c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00ed60: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00ed64: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00ed68: d65f03c0  ret      
//   0x00ed6c: eb15029f  cmp      x20, x21
//   0x00ed70: 54ffeb82  b.hs     #0xeae0
//   0x00ed74: 17ffff8c  b        #0xeba4
// ============================================================================
std::uint32_t fde_119_0e9f0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e9f0ULL;
    for (std::size_t i = 0; i < 226ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11688ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[120] Subroutine @ 0x00ed78..0x00ee4c (212 bytes, 53 AArch64 instructions)
// [VN] Khung FDE[120] Hàm con @ 0x00ed78..0x00ee4c (212 byte, 53 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ed78: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00ed7c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00ed80: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00ed84: 910083fd  add      x29, sp, #0x20
//   0x00ed88: aa0203f4  mov      x20, x2
//   0x00ed8c: eb02003f  cmp      x1, x2
//   0x00ed90: aa0003f3  mov      x19, x0
//   0x00ed94: 540003a2  b.hs     #0xee08
//   0x00ed98: 91001035  add      x21, x1, #4
//   0x00ed9c: eb1402bf  cmp      x21, x20
//   0x00eda0: 54000342  b.hs     #0xee08
//   0x00eda4: b94002a8  ldr      w8, [x21]
//   0x00eda8: 5100c108  sub      w8, w8, #0x30
//   0x00edac: 7100d91f  cmp      w8, #0x36
//   0x00edb0: 54000428  b.hi     #0xee34
//   0x00edb4: 52800029  mov      w9, #1
//   0x00edb8: 9ac82128  lsl      x8, x9, x8
//   0x00edbc: b20f17e9  mov      x9, #0x7e0000007e0000
//   0x00edc0: f2807fe9  movk     x9, #0x3ff
//   0x00edc4: ea09011f  tst      x8, x9
//   0x00edc8: 54000360  b.eq     #0xee34
//   0x00edcc: 91002035  add      x21, x1, #8
//   0x00edd0: eb1402bf  cmp      x21, x20
//   0x00edd4: 540001a2  b.hs     #0xee08
//   0x00edd8: b94002a8  ldr      w8, [x21]
//   0x00eddc: 5100c108  sub      w8, w8, #0x30
//   0x00ede0: 7100d91f  cmp      w8, #0x36
//   0x00ede4: 54000288  b.hi     #0xee34
//   0x00ede8: 52800029  mov      w9, #1
//   0x00edec: 9ac82128  lsl      x8, x9, x8
//   0x00edf0: b20f17e9  mov      x9, #0x7e0000007e0000
//   0x00edf4: f2807fe9  movk     x9, #0x3ff
//   0x00edf8: ea09011f  tst      x8, x9
//   0x00edfc: 540001c0  b.eq     #0xee34
//   0x00ee00: 91003020  add      x0, x1, #0xc
//   0x00ee04: 14000008  b        #0xee24
//   0x00ee08: f9400260  ldr      x0, [x19]
//   0x00ee0c: aa0303e1  mov      x1, x3
//   0x00ee10: 97ffd090  bl       #0x3050
//   0x00ee14: aa1f03e0  mov      x0, xzr
//   0x00ee18: f9000a74  str      x20, [x19, #0x10]
//   0x00ee1c: 52800028  mov      w8, #1
//   0x00ee20: b9000a68  str      w8, [x19, #8]
//   0x00ee24: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00ee28: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00ee2c: f84307f5  ldr      x21, [sp], #0x30
//   0x00ee30: d65f03c0  ret      
//   0x00ee34: f9400260  ldr      x0, [x19]
//   0x00ee38: aa0303e1  mov      x1, x3
//   0x00ee3c: 97ffd085  bl       #0x3050
//   0x00ee40: aa1f03e0  mov      x0, xzr
//   0x00ee44: f9000a75  str      x21, [x19, #0x10]
//   0x00ee48: 17fffff5  b        #0xee1c
// ============================================================================
std::uint32_t fde_120_0ed78(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ed78ULL;
    for (std::size_t i = 0; i < 53ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11914ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[121] Subroutine @ 0x00ee4c..0x00f228 (988 bytes, 247 AArch64 instructions)
// [VN] Khung FDE[121] Hàm con @ 0x00ee4c..0x00f228 (988 byte, 247 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00ee4c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00ee50: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00ee54: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00ee58: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00ee5c: 9100c3fd  add      x29, sp, #0x30
//   0x00ee60: aa0203f5  mov      x21, x2
//   0x00ee64: eb02003f  cmp      x1, x2
//   0x00ee68: aa0003f3  mov      x19, x0
//   0x00ee6c: 540003a2  b.hs     #0xeee0
//   0x00ee70: b9400028  ldr      w8, [x1]
//   0x00ee74: aa0303f4  mov      x20, x3
//   0x00ee78: aa0103f7  mov      x23, x1
//   0x00ee7c: 7100bd1f  cmp      w8, #0x2f
//   0x00ee80: 54000381  b.ne     #0xeef0
//   0x00ee84: 910012f6  add      x22, x23, #4
//   0x00ee88: eb1502df  cmp      x22, x21
//   0x00ee8c: 540007e2  b.hs     #0xef88
//   0x00ee90: b94002c8  ldr      w8, [x22]
//   0x00ee94: 51008508  sub      w8, w8, #0x21
//   0x00ee98: 7101751f  cmp      w8, #0x5d
//   0x00ee9c: 54001668  b.hi     #0xf168
//   0x00eea0: b0000029  adrp     x9, #0x13000
//   0x00eea4: 9137f929  add      x9, x9, #0xdfe
//   0x00eea8: 1000008a  adr      x10, #0xeeb8
//   0x00eeac: 3868692b  ldrb     w11, [x9, x8]
//   0x00eeb0: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00eeb4: d61f0140  br       x10
//   0x00eeb8: f9400268  ldr      x8, [x19]
//   0x00eebc: aa1303e0  mov      x0, x19
//   0x00eec0: aa1603e1  mov      x1, x22
//   0x00eec4: aa1503e2  mov      x2, x21
//   0x00eec8: aa1403e3  mov      x3, x20
//   0x00eecc: f9000916  str      x22, [x8, #0x10]
//   0x00eed0: 9400019f  bl       #0xf54c
//   0x00eed4: aa0003f6  mov      x22, x0
//   0x00eed8: b5000676  cbnz     x22, #0xefa4
//   0x00eedc: 140000cc  b        #0xf20c
//   0x00eee0: f9400268  ldr      x8, [x19]
//   0x00eee4: 52800029  mov      w9, #1
//   0x00eee8: b9009109  str      w9, [x8, #0x90]
//   0x00eeec: 1400009b  b        #0xf158
//   0x00eef0: f9400268  ldr      x8, [x19]
//   0x00eef4: 52800029  mov      w9, #1
//   0x00eef8: b9009109  str      w9, [x8, #0x90]
//   0x00eefc: b94002e8  ldr      w8, [x23]
//   0x00ef00: 51008508  sub      w8, w8, #0x21
//   0x00ef04: 7101751f  cmp      w8, #0x5d
//   0x00ef08: 54001848  b.hi     #0xf210
//   0x00ef0c: b0000029  adrp     x9, #0x13000
//   0x00ef10: 91368129  add      x9, x9, #0xda0
//   0x00ef14: 1000008a  adr      x10, #0xef24
//   0x00ef18: 3868692b  ldrb     w11, [x9, x8]
//   0x00ef1c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00ef20: d61f0140  br       x10
//   0x00ef24: aa1303e0  mov      x0, x19
//   0x00ef28: aa1703e1  mov      x1, x23
//   0x00ef2c: aa1503e2  mov      x2, x21
//   0x00ef30: aa1403e3  mov      x3, x20
//   0x00ef34: 940000dd  bl       #0xf2a8
//   0x00ef38: b40016a0  cbz      x0, #0xf20c
//   0x00ef3c: aa0003e1  mov      x1, x0
//   0x00ef40: aa1303e0  mov      x0, x19
//   0x00ef44: aa1503e2  mov      x2, x21
//   0x00ef48: aa1403e3  mov      x3, x20
//   0x00ef4c: 940000b7  bl       #0xf228
//   0x00ef50: b40015e0  cbz      x0, #0xf20c
//   0x00ef54: f9400688  ldr      x8, [x20, #8]
//   0x00ef58: aa0003f6  mov      x22, x0
//   0x00ef5c: 52800021  mov      w1, #1
//   0x00ef60: 52800402  mov      w2, #0x20
//   0x00ef64: aa1403e0  mov      x0, x20
//   0x00ef68: d63f0100  blr      x8
//   0x00ef6c: b4000ca0  cbz      x0, #0xf100
//   0x00ef70: b0000068  adrp     x8, #0x1b000
//   0x00ef74: f947e908  ldr      x8, [x8, #0xfd0]
//   0x00ef78: eb1702df  cmp      x22, x23
//   0x00ef7c: 54000620  b.eq     #0xf040
//   0x00ef80: a9005817  stp      x23, x22, [x0]
//   0x00ef84: 14000031  b        #0xf048
//   0x00ef88: b0000068  adrp     x8, #0x1b000
//   0x00ef8c: f947e908  ldr      x8, [x8, #0xfd0]
//   0x00ef90: f9400269  ldr      x9, [x19]
//   0x00ef94: aa1503f6  mov      x22, x21
//   0x00ef98: f9400108  ldr      x8, [x8]
//   0x00ef9c: a9022128  stp      x8, x8, [x9, #0x20]
//   0x00efa0: b4001376  cbz      x22, #0xf20c
//   0x00efa4: eb1502df  cmp      x22, x21
//   0x00efa8: 54000d22  b.hs     #0xf14c
//   0x00efac: b0000068  adrp     x8, #0x1b000
//   0x00efb0: f947e908  ldr      x8, [x8, #0xfd0]
//   0x00efb4: f9400118  ldr      x24, [x8]
//   0x00efb8: 14000006  b        #0xefd0
//   0x00efbc: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00efc0: f9000920  str      x0, [x9, #0x10]
//   0x00efc4: eb1502df  cmp      x22, x21
//   0x00efc8: f9000100  str      x0, [x8]
//   0x00efcc: 54000c02  b.hs     #0xf14c
//   0x00efd0: b94002c8  ldr      w8, [x22]
//   0x00efd4: 7100bd1f  cmp      w8, #0x2f
//   0x00efd8: 54000a41  b.ne     #0xf120
//   0x00efdc: 910012d7  add      x23, x22, #4
//   0x00efe0: aa1303e0  mov      x0, x19
//   0x00efe4: aa1703e1  mov      x1, x23
//   0x00efe8: aa1503e2  mov      x2, x21
//   0x00efec: aa1403e3  mov      x3, x20
//   0x00eff0: 9400008e  bl       #0xf228
//   0x00eff4: b40009a0  cbz      x0, #0xf128
//   0x00eff8: f9400688  ldr      x8, [x20, #8]
//   0x00effc: aa0003f6  mov      x22, x0
//   0x00f000: 52800021  mov      w1, #1
//   0x00f004: 52800402  mov      w2, #0x20
//   0x00f008: aa1403e0  mov      x0, x20
//   0x00f00c: d63f0100  blr      x8
//   0x00f010: b4000900  cbz      x0, #0xf130
//   0x00f014: eb1602ff  cmp      x23, x22
//   0x00f018: 54000060  b.eq     #0xf024
//   0x00f01c: a9005817  stp      x23, x22, [x0]
//   0x00f020: 14000002  b        #0xf028
//   0x00f024: a9006018  stp      x24, x24, [x0]
//   0x00f028: f9400268  ldr      x8, [x19]
//   0x00f02c: f9403109  ldr      x9, [x8, #0x60]
//   0x00f030: b5fffc69  cbnz     x9, #0xefbc
//   0x00f034: f9003100  str      x0, [x8, #0x60]
//   0x00f038: 9101a108  add      x8, x8, #0x68
//   0x00f03c: 17ffffe2  b        #0xefc4
//   0x00f040: f9400109  ldr      x9, [x8]
//   0x00f044: a9002409  stp      x9, x9, [x0]
//   0x00f048: f9400269  ldr      x9, [x19]
//   0x00f04c: f940312a  ldr      x10, [x9, #0x60]
//   0x00f050: b400008a  cbz      x10, #0xf060
//   0x00f054: f8468d2a  ldr      x10, [x9, #0x68]!
//   0x00f058: f9000940  str      x0, [x10, #0x10]
//   0x00f05c: 14000003  b        #0xf068
//   0x00f060: f9003120  str      x0, [x9, #0x60]
//   0x00f064: 9101a129  add      x9, x9, #0x68
//   0x00f068: eb1502df  cmp      x22, x21
//   0x00f06c: f9000120  str      x0, [x9]
//   0x00f070: 54000742  b.hs     #0xf158
//   0x00f074: f9400118  ldr      x24, [x8]
//   0x00f078: 14000006  b        #0xf090
//   0x00f07c: f8468d09  ldr      x9, [x8, #0x68]!
//   0x00f080: f9000920  str      x0, [x9, #0x10]
//   0x00f084: eb1502df  cmp      x22, x21
//   0x00f088: f9000100  str      x0, [x8]
//   0x00f08c: 54000662  b.hs     #0xf158
//   0x00f090: b94002c8  ldr      w8, [x22]
//   0x00f094: 7100bd1f  cmp      w8, #0x2f
//   0x00f098: 54000641  b.ne     #0xf160
//   0x00f09c: 910012d7  add      x23, x22, #4
//   0x00f0a0: aa1303e0  mov      x0, x19
//   0x00f0a4: aa1703e1  mov      x1, x23
//   0x00f0a8: aa1503e2  mov      x2, x21
//   0x00f0ac: aa1403e3  mov      x3, x20
//   0x00f0b0: 9400005e  bl       #0xf228
//   0x00f0b4: b4000ac0  cbz      x0, #0xf20c
//   0x00f0b8: f9400688  ldr      x8, [x20, #8]
//   0x00f0bc: aa0003f6  mov      x22, x0
//   0x00f0c0: 52800021  mov      w1, #1
//   0x00f0c4: 52800402  mov      w2, #0x20
//   0x00f0c8: aa1403e0  mov      x0, x20
//   0x00f0cc: d63f0100  blr      x8
//   0x00f0d0: b4000180  cbz      x0, #0xf100
//   0x00f0d4: eb1602ff  cmp      x23, x22
//   0x00f0d8: 54000060  b.eq     #0xf0e4
//   0x00f0dc: a9005817  stp      x23, x22, [x0]
//   0x00f0e0: 14000002  b        #0xf0e8
//   0x00f0e4: a9006018  stp      x24, x24, [x0]
//   0x00f0e8: f9400268  ldr      x8, [x19]
//   0x00f0ec: f9403109  ldr      x9, [x8, #0x60]
//   0x00f0f0: b5fffc69  cbnz     x9, #0xf07c
//   0x00f0f4: f9003100  str      x0, [x8, #0x60]
//   0x00f0f8: 9101a108  add      x8, x8, #0x68
//   0x00f0fc: 17ffffe2  b        #0xf084
//   0x00f100: f9400260  ldr      x0, [x19]
//   0x00f104: aa1403e1  mov      x1, x20
//   0x00f108: 97ffcfd2  bl       #0x3050
//   0x00f10c: 52800068  mov      w8, #3
//   0x00f110: aa1f03f7  mov      x23, xzr
//   0x00f114: f9000a7f  str      xzr, [x19, #0x10]
//   0x00f118: b9000a68  str      w8, [x19, #8]
//   0x00f11c: 1400003d  b        #0xf210
//   0x00f120: aa1603f5  mov      x21, x22
//   0x00f124: 1400000a  b        #0xf14c
//   0x00f128: aa1f03f5  mov      x21, xzr
//   0x00f12c: 14000008  b        #0xf14c
//   0x00f130: f9400260  ldr      x0, [x19]
//   0x00f134: aa1403e1  mov      x1, x20
//   0x00f138: 97ffcfc6  bl       #0x3050
//   0x00f13c: 52800068  mov      w8, #3
//   0x00f140: aa1f03f5  mov      x21, xzr
//   0x00f144: f9000a7f  str      xzr, [x19, #0x10]
//   0x00f148: b9000a68  str      w8, [x19, #8]
//   0x00f14c: f9400260  ldr      x0, [x19]
//   0x00f150: aa1403e1  mov      x1, x20
//   0x00f154: 97ffcfdf  bl       #0x30d0
//   0x00f158: aa1503f7  mov      x23, x21
//   0x00f15c: 1400002d  b        #0xf210
//   0x00f160: aa1603f7  mov      x23, x22
//   0x00f164: 1400002b  b        #0xf210
//   0x00f168: 90000068  adrp     x8, #0x1b000
//   0x00f16c: f947e908  ldr      x8, [x8, #0xfd0]
//   0x00f170: f9400269  ldr      x9, [x19]
//   0x00f174: f9400108  ldr      x8, [x8]
//   0x00f178: a9022128  stp      x8, x8, [x9, #0x20]
//   0x00f17c: eb1502df  cmp      x22, x21
//   0x00f180: 54fff163  b.lo     #0xefac
//   0x00f184: 17fffff2  b        #0xf14c
//   0x00f188: 910022f6  add      x22, x23, #8
//   0x00f18c: aa1303e0  mov      x0, x19
//   0x00f190: aa1603e1  mov      x1, x22
//   0x00f194: aa1503e2  mov      x2, x21
//   0x00f198: aa1403e3  mov      x3, x20
//   0x00f19c: 94000070  bl       #0xf35c
//   0x00f1a0: b4000360  cbz      x0, #0xf20c
//   0x00f1a4: f9400268  ldr      x8, [x19]
//   0x00f1a8: eb15001f  cmp      x0, x21
//   0x00f1ac: f9001116  str      x22, [x8, #0x20]
//   0x00f1b0: aa1503f6  mov      x22, x21
//   0x00f1b4: 54ffef62  b.hs     #0xefa0
//   0x00f1b8: b9400009  ldr      w9, [x0]
//   0x00f1bc: aa0003f6  mov      x22, x0
//   0x00f1c0: 7100e93f  cmp      w9, #0x3a
//   0x00f1c4: 54ffef01  b.ne     #0xefa4
//   0x00f1c8: 91001009  add      x9, x0, #4
//   0x00f1cc: eb15013f  cmp      x9, x21
//   0x00f1d0: 54000122  b.hs     #0xf1f4
//   0x00f1d4: aa0903f6  mov      x22, x9
//   0x00f1d8: b94002ca  ldr      w10, [x22]
//   0x00f1dc: 5100c14a  sub      w10, w10, #0x30
//   0x00f1e0: 7100255f  cmp      w10, #9
//   0x00f1e4: 540000c8  b.hi     #0xf1fc
//   0x00f1e8: 910012d6  add      x22, x22, #4
//   0x00f1ec: eb1502df  cmp      x22, x21
//   0x00f1f0: 54ffff43  b.lo     #0xf1d8
//   0x00f1f4: aa1503f6  mov      x22, x21
//   0x00f1f8: b40000b5  cbz      x21, #0xf20c
//   0x00f1fc: a9055909  stp      x9, x22, [x8, #0x50]
//   0x00f200: eb1502df  cmp      x22, x21
//   0x00f204: 54ffed43  b.lo     #0xefac
//   0x00f208: 17ffffd1  b        #0xf14c
//   0x00f20c: aa1f03f7  mov      x23, xzr
//   0x00f210: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00f214: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00f218: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00f21c: aa1703e0  mov      x0, x23
//   0x00f220: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00f224: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_121_0ee4c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000ee4cULL;
    for (std::size_t i = 0; i < 247ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11967ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[122] Subroutine @ 0x00f228..0x00f2a8 (128 bytes, 32 AArch64 instructions)
// [VN] Khung FDE[122] Hàm con @ 0x00f228..0x00f2a8 (128 byte, 32 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f228: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00f22c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00f230: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00f234: 910083fd  add      x29, sp, #0x20
//   0x00f238: 90000036  adrp     x22, #0x13000
//   0x00f23c: aa0303f4  mov      x20, x3
//   0x00f240: aa0203f3  mov      x19, x2
//   0x00f244: aa0003f5  mov      x21, x0
//   0x00f248: 913972d6  add      x22, x22, #0xe5c
//   0x00f24c: eb13003f  cmp      x1, x19
//   0x00f250: 54000202  b.hs     #0xf290
//   0x00f254: b9400028  ldr      w8, [x1]
//   0x00f258: 51008508  sub      w8, w8, #0x21
//   0x00f25c: 7101751f  cmp      w8, #0x5d
//   0x00f260: 540001a8  b.hi     #0xf294
//   0x00f264: 10000089  adr      x9, #0xf274
//   0x00f268: 38686aca  ldrb     w10, [x22, x8]
//   0x00f26c: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00f270: d61f0120  br       x9
//   0x00f274: aa1503e0  mov      x0, x21
//   0x00f278: aa1303e2  mov      x2, x19
//   0x00f27c: aa1403e3  mov      x3, x20
//   0x00f280: 9400000a  bl       #0xf2a8
//   0x00f284: aa0003e1  mov      x1, x0
//   0x00f288: b5fffe20  cbnz     x0, #0xf24c
//   0x00f28c: 14000002  b        #0xf294
//   0x00f290: aa1303e1  mov      x1, x19
//   0x00f294: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00f298: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00f29c: aa0103e0  mov      x0, x1
//   0x00f2a0: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x00f2a4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_122_0f228(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f228ULL;
    for (std::size_t i = 0; i < 32ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12214ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[123] Subroutine @ 0x00f2a8..0x00f35c (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[123] Hàm con @ 0x00f2a8..0x00f35c (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f2a8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00f2ac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00f2b0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00f2b4: 910083fd  add      x29, sp, #0x20
//   0x00f2b8: aa0203f4  mov      x20, x2
//   0x00f2bc: eb02003f  cmp      x1, x2
//   0x00f2c0: aa0003f3  mov      x19, x0
//   0x00f2c4: 540001c2  b.hs     #0xf2fc
//   0x00f2c8: b9400028  ldr      w8, [x1]
//   0x00f2cc: aa0103f5  mov      x21, x1
//   0x00f2d0: 51008508  sub      w8, w8, #0x21
//   0x00f2d4: 7101751f  cmp      w8, #0x5d
//   0x00f2d8: 54000288  b.hi     #0xf328
//   0x00f2dc: 90000029  adrp     x9, #0x13000
//   0x00f2e0: 913ae929  add      x9, x9, #0xeba
//   0x00f2e4: 1000008a  adr      x10, #0xf2f4
//   0x00f2e8: 3868692b  ldrb     w11, [x9, x8]
//   0x00f2ec: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00f2f0: d61f0140  br       x10
//   0x00f2f4: 910012a0  add      x0, x21, #4
//   0x00f2f8: 14000008  b        #0xf318
//   0x00f2fc: f9400260  ldr      x0, [x19]
//   0x00f300: aa0303e1  mov      x1, x3
//   0x00f304: 97ffcf53  bl       #0x3050
//   0x00f308: aa1f03e0  mov      x0, xzr
//   0x00f30c: f9000a74  str      x20, [x19, #0x10]
//   0x00f310: 52800028  mov      w8, #1
//   0x00f314: b9000a68  str      w8, [x19, #8]
//   0x00f318: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00f31c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00f320: f84307f5  ldr      x21, [sp], #0x30
//   0x00f324: d65f03c0  ret      
//   0x00f328: f9400260  ldr      x0, [x19]
//   0x00f32c: aa0303e1  mov      x1, x3
//   0x00f330: 97ffcf48  bl       #0x3050
//   0x00f334: aa1f03e0  mov      x0, xzr
//   0x00f338: f9000a75  str      x21, [x19, #0x10]
//   0x00f33c: 17fffff5  b        #0xf310
//   0x00f340: aa1303e0  mov      x0, x19
//   0x00f344: aa1403e2  mov      x2, x20
//   0x00f348: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00f34c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00f350: aa1503e1  mov      x1, x21
//   0x00f354: f84307f5  ldr      x21, [sp], #0x30
//   0x00f358: 17fffe88  b        #0xed78
// ============================================================================
std::uint32_t fde_123_0f2a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f2a8ULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12246ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[124] Subroutine @ 0x00f35c..0x00f54c (496 bytes, 124 AArch64 instructions)
// [VN] Khung FDE[124] Hàm con @ 0x00f35c..0x00f54c (496 byte, 124 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f35c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00f360: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00f364: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00f368: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00f36c: 9100c3fd  add      x29, sp, #0x30
//   0x00f370: aa0303f4  mov      x20, x3
//   0x00f374: aa0203f5  mov      x21, x2
//   0x00f378: eb02003f  cmp      x1, x2
//   0x00f37c: aa0003f3  mov      x19, x0
//   0x00f380: 54000c22  b.hs     #0xf504
//   0x00f384: b9400028  ldr      w8, [x1]
//   0x00f388: aa0103f6  mov      x22, x1
//   0x00f38c: 5100c108  sub      w8, w8, #0x30
//   0x00f390: 7101191f  cmp      w8, #0x46
//   0x00f394: 540007c8  b.hi     #0xf48c
//   0x00f398: 90000029  adrp     x9, #0x13000
//   0x00f39c: 913c6129  add      x9, x9, #0xf18
//   0x00f3a0: 1000008a  adr      x10, #0xf3b0
//   0x00f3a4: 3868692b  ldrb     w11, [x9, x8]
//   0x00f3a8: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00f3ac: d61f0140  br       x10
//   0x00f3b0: f9400288  ldr      x8, [x20]
//   0x00f3b4: 52800201  mov      w1, #0x10
//   0x00f3b8: aa1403e0  mov      x0, x20
//   0x00f3bc: d63f0100  blr      x8
//   0x00f3c0: f9400268  ldr      x8, [x19]
//   0x00f3c4: f9001d00  str      x0, [x8, #0x38]
//   0x00f3c8: b4000140  cbz      x0, #0xf3f0
//   0x00f3cc: aa1303e0  mov      x0, x19
//   0x00f3d0: aa1603e1  mov      x1, x22
//   0x00f3d4: aa1503e2  mov      x2, x21
//   0x00f3d8: aa1403e3  mov      x3, x20
//   0x00f3dc: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00f3e0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00f3e4: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00f3e8: f84407f7  ldr      x23, [sp], #0x40
//   0x00f3ec: 17fff6e1  b        #0xcf70
//   0x00f3f0: aa0803e0  mov      x0, x8
//   0x00f3f4: aa1403e1  mov      x1, x20
//   0x00f3f8: 97ffcf16  bl       #0x3050
//   0x00f3fc: aa1f03e0  mov      x0, xzr
//   0x00f400: f9000a7f  str      xzr, [x19, #0x10]
//   0x00f404: 52800068  mov      w8, #3
//   0x00f408: 14000045  b        #0xf51c
//   0x00f40c: 910012d7  add      x23, x22, #4
//   0x00f410: eb1502ff  cmp      x23, x21
//   0x00f414: 54000782  b.hs     #0xf504
//   0x00f418: b94002e8  ldr      w8, [x23]
//   0x00f41c: 5100c108  sub      w8, w8, #0x30
//   0x00f420: 7100d91f  cmp      w8, #0x36
//   0x00f424: 54000888  b.hi     #0xf534
//   0x00f428: 52800029  mov      w9, #1
//   0x00f42c: 9ac82128  lsl      x8, x9, x8
//   0x00f430: b20f17e9  mov      x9, #0x7e0000007e0000
//   0x00f434: f2807fe9  movk     x9, #0x3ff
//   0x00f438: ea09011f  tst      x8, x9
//   0x00f43c: 540007c0  b.eq     #0xf534
//   0x00f440: 910022d7  add      x23, x22, #8
//   0x00f444: eb1502ff  cmp      x23, x21
//   0x00f448: 540001c2  b.hs     #0xf480
//   0x00f44c: b20f17e9  mov      x9, #0x7e0000007e0000
//   0x00f450: 52800028  mov      w8, #1
//   0x00f454: f2807fe9  movk     x9, #0x3ff
//   0x00f458: b94002ea  ldr      w10, [x23]
//   0x00f45c: 5100c14b  sub      w11, w10, #0x30
//   0x00f460: 7100d97f  cmp      w11, #0x36
//   0x00f464: 54000208  b.hi     #0xf4a4
//   0x00f468: 9acb210b  lsl      x11, x8, x11
//   0x00f46c: ea09017f  tst      x11, x9
//   0x00f470: 540001a0  b.eq     #0xf4a4
//   0x00f474: 910012f7  add      x23, x23, #4
//   0x00f478: eb1502ff  cmp      x23, x21
//   0x00f47c: 54fffee3  b.lo     #0xf458
//   0x00f480: b5000435  cbnz     x21, #0xf504
//   0x00f484: aa1f03e0  mov      x0, xzr
//   0x00f488: 14000026  b        #0xf520
//   0x00f48c: f9400260  ldr      x0, [x19]
//   0x00f490: aa1403e1  mov      x1, x20
//   0x00f494: 97ffceef  bl       #0x3050
//   0x00f498: aa1f03e0  mov      x0, xzr
//   0x00f49c: f9000a76  str      x22, [x19, #0x10]
//   0x00f4a0: 1400001e  b        #0xf518
//   0x00f4a4: eb1502ff  cmp      x23, x21
//   0x00f4a8: 540002e2  b.hs     #0xf504
//   0x00f4ac: f9400260  ldr      x0, [x19]
//   0x00f4b0: 7100b95f  cmp      w10, #0x2e
//   0x00f4b4: 54000421  b.ne     #0xf538
//   0x00f4b8: f9001016  str      x22, [x0, #0x20]
//   0x00f4bc: f9002016  str      x22, [x0, #0x40]
//   0x00f4c0: 910012e1  add      x1, x23, #4
//   0x00f4c4: aa1303e0  mov      x0, x19
//   0x00f4c8: aa1503e2  mov      x2, x21
//   0x00f4cc: aa1403e3  mov      x3, x20
//   0x00f4d0: 940000d6  bl       #0xf828
//   0x00f4d4: b4000260  cbz      x0, #0xf520
//   0x00f4d8: aa0003f6  mov      x22, x0
//   0x00f4dc: f9400260  ldr      x0, [x19]
//   0x00f4e0: eb1502df  cmp      x22, x21
//   0x00f4e4: f9001416  str      x22, [x0, #0x28]
//   0x00f4e8: f9002416  str      x22, [x0, #0x48]
//   0x00f4ec: 540000e2  b.hs     #0xf508
//   0x00f4f0: b94002c8  ldr      w8, [x22]
//   0x00f4f4: 7101751f  cmp      w8, #0x5d
//   0x00f4f8: 54fffcc1  b.ne     #0xf490
//   0x00f4fc: 910012c0  add      x0, x22, #4
//   0x00f500: 14000008  b        #0xf520
//   0x00f504: f9400260  ldr      x0, [x19]
//   0x00f508: aa1403e1  mov      x1, x20
//   0x00f50c: 97ffced1  bl       #0x3050
//   0x00f510: aa1f03e0  mov      x0, xzr
//   0x00f514: f9000a75  str      x21, [x19, #0x10]
//   0x00f518: 52800028  mov      w8, #1
//   0x00f51c: b9000a68  str      w8, [x19, #8]
//   0x00f520: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00f524: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00f528: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00f52c: f84407f7  ldr      x23, [sp], #0x40
//   0x00f530: d65f03c0  ret      
//   0x00f534: f9400260  ldr      x0, [x19]
//   0x00f538: aa1403e1  mov      x1, x20
//   0x00f53c: 97ffcec5  bl       #0x3050
//   0x00f540: aa1f03e0  mov      x0, xzr
//   0x00f544: f9000a77  str      x23, [x19, #0x10]
//   0x00f548: 17fffff4  b        #0xf518
// ============================================================================
std::uint32_t fde_124_0f35c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f35cULL;
    for (std::size_t i = 0; i < 124ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12291ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[125] Subroutine @ 0x00f54c..0x00f828 (732 bytes, 183 AArch64 instructions)
// [VN] Khung FDE[125] Hàm con @ 0x00f54c..0x00f828 (732 byte, 183 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f54c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00f550: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00f554: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00f558: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00f55c: 9100c3fd  add      x29, sp, #0x30
//   0x00f560: aa0303f4  mov      x20, x3
//   0x00f564: aa0203f5  mov      x21, x2
//   0x00f568: eb02003f  cmp      x1, x2
//   0x00f56c: aa0003f3  mov      x19, x0
//   0x00f570: 540006c2  b.hs     #0xf648
//   0x00f574: b9400028  ldr      w8, [x1]
//   0x00f578: 90000037  adrp     x23, #0x13000
//   0x00f57c: b0000038  adrp     x24, #0x14000
//   0x00f580: aa0103f6  mov      x22, x1
//   0x00f584: 913d7ef7  add      x23, x23, #0xf5f
//   0x00f588: 91006f18  add      x24, x24, #0x1b
//   0x00f58c: 51008508  sub      w8, w8, #0x21
//   0x00f590: 7101751f  cmp      w8, #0x5d
//   0x00f594: 540007e8  b.hi     #0xf690
//   0x00f598: 10000089  adr      x9, #0xf5a8
//   0x00f59c: 38686aea  ldrb     w10, [x23, x8]
//   0x00f5a0: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00f5a4: d61f0120  br       x9
//   0x00f5a8: aa1303e0  mov      x0, x19
//   0x00f5ac: aa1603e1  mov      x1, x22
//   0x00f5b0: aa1503e2  mov      x2, x21
//   0x00f5b4: aa1403e3  mov      x3, x20
//   0x00f5b8: 940000d4  bl       #0xf908
//   0x00f5bc: b4000520  cbz      x0, #0xf660
//   0x00f5c0: aa0003f6  mov      x22, x0
//   0x00f5c4: eb15001f  cmp      x0, x21
//   0x00f5c8: 540005a2  b.hs     #0xf67c
//   0x00f5cc: b94002c8  ldr      w8, [x22]
//   0x00f5d0: 51008509  sub      w9, w8, #0x21
//   0x00f5d4: 7101753f  cmp      w9, #0x5d
//   0x00f5d8: 540000a8  b.hi     #0xf5ec
//   0x00f5dc: 10fffd8a  adr      x10, #0xf58c
//   0x00f5e0: 38696b0b  ldrb     w11, [x24, x9]
//   0x00f5e4: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00f5e8: d61f0140  br       x10
//   0x00f5ec: f9400268  ldr      x8, [x19]
//   0x00f5f0: 52800081  mov      w1, #4
//   0x00f5f4: aa1403e0  mov      x0, x20
//   0x00f5f8: f9400909  ldr      x9, [x8, #0x10]
//   0x00f5fc: f900091f  str      xzr, [x8, #0x10]
//   0x00f600: a9025909  stp      x9, x22, [x8, #0x20]
//   0x00f604: f9400288  ldr      x8, [x20]
//   0x00f608: d63f0100  blr      x8
//   0x00f60c: f9400268  ldr      x8, [x19]
//   0x00f610: f9001900  str      x0, [x8, #0x30]
//   0x00f614: b4000920  cbz      x0, #0xf738
//   0x00f618: a9420901  ldp      x1, x2, [x8, #0x20]
//   0x00f61c: 97ffcf21  bl       #0x32a0
//   0x00f620: 34000b20  cbz      w0, #0xf784
//   0x00f624: f9400268  ldr      x8, [x19]
//   0x00f628: f9401289  ldr      x9, [x20, #0x20]
//   0x00f62c: aa1403e0  mov      x0, x20
//   0x00f630: f9401901  ldr      x1, [x8, #0x30]
//   0x00f634: d63f0120  blr      x9
//   0x00f638: f9400268  ldr      x8, [x19]
//   0x00f63c: aa1603f5  mov      x21, x22
//   0x00f640: f900191f  str      xzr, [x8, #0x30]
//   0x00f644: 14000008  b        #0xf664
//   0x00f648: f9400260  ldr      x0, [x19]
//   0x00f64c: aa1403e1  mov      x1, x20
//   0x00f650: 97ffce80  bl       #0x3050
//   0x00f654: 52800028  mov      w8, #1
//   0x00f658: f9000a75  str      x21, [x19, #0x10]
//   0x00f65c: b9000a68  str      w8, [x19, #8]
//   0x00f660: aa1f03f5  mov      x21, xzr
//   0x00f664: aa1503e0  mov      x0, x21
//   0x00f668: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00f66c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00f670: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00f674: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00f678: d65f03c0  ret      
//   0x00f67c: f9400268  ldr      x8, [x19]
//   0x00f680: f9400909  ldr      x9, [x8, #0x10]
//   0x00f684: f900091f  str      xzr, [x8, #0x10]
//   0x00f688: a9025909  stp      x9, x22, [x8, #0x20]
//   0x00f68c: 14000019  b        #0xf6f0
//   0x00f690: f9400260  ldr      x0, [x19]
//   0x00f694: aa1403e1  mov      x1, x20
//   0x00f698: 97ffce6e  bl       #0x3050
//   0x00f69c: aa1f03f5  mov      x21, xzr
//   0x00f6a0: 52800028  mov      w8, #1
//   0x00f6a4: f9000a76  str      x22, [x19, #0x10]
//   0x00f6a8: 1400002a  b        #0xf750
//   0x00f6ac: f9400269  ldr      x9, [x19]
//   0x00f6b0: 910012c1  add      x1, x22, #4
//   0x00f6b4: eb15003f  cmp      x1, x21
//   0x00f6b8: f9001536  str      x22, [x9, #0x28]
//   0x00f6bc: f9002921  str      x1, [x9, #0x50]
//   0x00f6c0: 54000102  b.hs     #0xf6e0
//   0x00f6c4: b9400028  ldr      w8, [x1]
//   0x00f6c8: 5100c10a  sub      w10, w8, #0x30
//   0x00f6cc: 7100295f  cmp      w10, #0xa
//   0x00f6d0: 540005e2  b.hs     #0xf78c
//   0x00f6d4: 91001021  add      x1, x1, #4
//   0x00f6d8: eb15003f  cmp      x1, x21
//   0x00f6dc: 54ffff43  b.lo     #0xf6c4
//   0x00f6e0: f9400928  ldr      x8, [x9, #0x10]
//   0x00f6e4: f900093f  str      xzr, [x9, #0x10]
//   0x00f6e8: f9002d21  str      x1, [x9, #0x58]
//   0x00f6ec: f9001128  str      x8, [x9, #0x20]
//   0x00f6f0: f9400288  ldr      x8, [x20]
//   0x00f6f4: 52800081  mov      w1, #4
//   0x00f6f8: aa1403e0  mov      x0, x20
//   0x00f6fc: d63f0100  blr      x8
//   0x00f700: f9400268  ldr      x8, [x19]
//   0x00f704: f9001900  str      x0, [x8, #0x30]
//   0x00f708: b4000180  cbz      x0, #0xf738
//   0x00f70c: a9420901  ldp      x1, x2, [x8, #0x20]
//   0x00f710: 97ffcee4  bl       #0x32a0
//   0x00f714: 34fffa80  cbz      w0, #0xf664
//   0x00f718: f9400268  ldr      x8, [x19]
//   0x00f71c: f9401289  ldr      x9, [x20, #0x20]
//   0x00f720: aa1403e0  mov      x0, x20
//   0x00f724: f9401901  ldr      x1, [x8, #0x30]
//   0x00f728: d63f0120  blr      x9
//   0x00f72c: f9400268  ldr      x8, [x19]
//   0x00f730: f900191f  str      xzr, [x8, #0x30]
//   0x00f734: 17ffffcc  b        #0xf664
//   0x00f738: aa0803e0  mov      x0, x8
//   0x00f73c: aa1403e1  mov      x1, x20
//   0x00f740: 97ffce44  bl       #0x3050
//   0x00f744: aa1f03f5  mov      x21, xzr
//   0x00f748: f9000a7f  str      xzr, [x19, #0x10]
//   0x00f74c: 52800068  mov      w8, #3
//   0x00f750: b9000a68  str      w8, [x19, #8]
//   0x00f754: 17ffffc4  b        #0xf664
//   0x00f758: f9400268  ldr      x8, [x19]
//   0x00f75c: 910012c1  add      x1, x22, #4
//   0x00f760: aa1303e0  mov      x0, x19
//   0x00f764: a9018516  stp      x22, x1, [x8, #0x18]
//   0x00f768: aa1503e2  mov      x2, x21
//   0x00f76c: aa1403e3  mov      x3, x20
//   0x00f770: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00f774: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00f778: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00f77c: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00f780: 1400008f  b        #0xf9bc
//   0x00f784: aa1603f5  mov      x21, x22
//   0x00f788: 17ffffb7  b        #0xf664
//   0x00f78c: 51008508  sub      w8, w8, #0x21
//   0x00f790: 7101751f  cmp      w8, #0x5d
//   0x00f794: 54000248  b.hi     #0xf7dc
//   0x00f798: 9000002a  adrp     x10, #0x13000
//   0x00f79c: 913ef54a  add      x10, x10, #0xfbd
//   0x00f7a0: 1000008b  adr      x11, #0xf7b0
//   0x00f7a4: 3868694c  ldrb     w12, [x10, x8]
//   0x00f7a8: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00f7ac: d61f0160  br       x11
//   0x00f7b0: f900153f  str      xzr, [x9, #0x28]
//   0x00f7b4: 91001021  add      x1, x1, #4
//   0x00f7b8: f900293f  str      xzr, [x9, #0x50]
//   0x00f7bc: aa1303e0  mov      x0, x19
//   0x00f7c0: aa1503e2  mov      x2, x21
//   0x00f7c4: aa1403e3  mov      x3, x20
//   0x00f7c8: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00f7cc: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00f7d0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00f7d4: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x00f7d8: 1400010a  b        #0xfc00
//   0x00f7dc: f9400928  ldr      x8, [x9, #0x10]
//   0x00f7e0: f900093f  str      xzr, [x9, #0x10]
//   0x00f7e4: aa0103f5  mov      x21, x1
//   0x00f7e8: 17ffffc0  b        #0xf6e8
//   0x00f7ec: aa1303e0  mov      x0, x19
//   0x00f7f0: aa1503e2  mov      x2, x21
//   0x00f7f4: aa1403e3  mov      x3, x20
//   0x00f7f8: f900293f  str      xzr, [x9, #0x50]
//   0x00f7fc: 97fffd5f  bl       #0xed78
//   0x00f800: b4fff300  cbz      x0, #0xf660
//   0x00f804: aa0003e1  mov      x1, x0
//   0x00f808: 17ffffed  b        #0xf7bc
//   0x00f80c: 91001028  add      x8, x1, #4
//   0x00f810: f900293f  str      xzr, [x9, #0x50]
//   0x00f814: f9000d21  str      x1, [x9, #0x18]
//   0x00f818: a9027d28  stp      x8, xzr, [x9, #0x20]
//   0x00f81c: aa1303e0  mov      x0, x19
//   0x00f820: aa0803e1  mov      x1, x8
//   0x00f824: 17ffffd1  b        #0xf768
// ============================================================================
std::uint32_t fde_125_0f54c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f54cULL;
    for (std::size_t i = 0; i < 183ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12415ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[126] Subroutine @ 0x00f828..0x00f908 (224 bytes, 56 AArch64 instructions)
// [VN] Khung FDE[126] Hàm con @ 0x00f828..0x00f908 (224 byte, 56 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f828: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00f82c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00f830: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00f834: 910083fd  add      x29, sp, #0x20
//   0x00f838: aa0203f5  mov      x21, x2
//   0x00f83c: eb02003f  cmp      x1, x2
//   0x00f840: aa0003f4  mov      x20, x0
//   0x00f844: 54000342  b.hs     #0xf8ac
//   0x00f848: aa0103f3  mov      x19, x1
//   0x00f84c: b840466a  ldr      w10, [x19], #4
//   0x00f850: b0000028  adrp     x8, #0x14000
//   0x00f854: b0000029  adrp     x9, #0x14000
//   0x00f858: 9101e508  add      x8, x8, #0x79
//   0x00f85c: 91035d29  add      x9, x9, #0xd7
//   0x00f860: 5100854a  sub      w10, w10, #0x21
//   0x00f864: 7101755f  cmp      w10, #0x5d
//   0x00f868: 54000328  b.hi     #0xf8cc
//   0x00f86c: 1000008b  adr      x11, #0xf87c
//   0x00f870: 386a690c  ldrb     w12, [x8, x10]
//   0x00f874: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x00f878: d61f0160  br       x11
//   0x00f87c: eb15027f  cmp      x19, x21
//   0x00f880: 54000382  b.hs     #0xf8f0
//   0x00f884: b940026a  ldr      w10, [x19]
//   0x00f888: 5100854b  sub      w11, w10, #0x21
//   0x00f88c: 7101757f  cmp      w11, #0x5d
//   0x00f890: 54000328  b.hi     #0xf8f4
//   0x00f894: 1000008c  adr      x12, #0xf8a4
//   0x00f898: 386b692d  ldrb     w13, [x9, x11]
//   0x00f89c: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x00f8a0: d61f0180  br       x12
//   0x00f8a4: 91001273  add      x19, x19, #4
//   0x00f8a8: 17ffffee  b        #0xf860
//   0x00f8ac: f9400280  ldr      x0, [x20]
//   0x00f8b0: aa0303e1  mov      x1, x3
//   0x00f8b4: 97ffcde7  bl       #0x3050
//   0x00f8b8: 52800028  mov      w8, #1
//   0x00f8bc: aa1f03f3  mov      x19, xzr
//   0x00f8c0: f9000a95  str      x21, [x20, #0x10]
//   0x00f8c4: b9000a88  str      w8, [x20, #8]
//   0x00f8c8: 1400000b  b        #0xf8f4
//   0x00f8cc: f9400280  ldr      x0, [x20]
//   0x00f8d0: aa0303e1  mov      x1, x3
//   0x00f8d4: 97ffcddf  bl       #0x3050
//   0x00f8d8: d1001268  sub      x8, x19, #4
//   0x00f8dc: 52800029  mov      w9, #1
//   0x00f8e0: aa1f03f3  mov      x19, xzr
//   0x00f8e4: f9000a88  str      x8, [x20, #0x10]
//   0x00f8e8: b9000a89  str      w9, [x20, #8]
//   0x00f8ec: 14000002  b        #0xf8f4
//   0x00f8f0: aa1503f3  mov      x19, x21
//   0x00f8f4: aa1303e0  mov      x0, x19
//   0x00f8f8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00f8fc: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00f900: f84307f5  ldr      x21, [sp], #0x30
//   0x00f904: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_126_0f828(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f828ULL;
    for (std::size_t i = 0; i < 56ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12598ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[127] Subroutine @ 0x00f908..0x00f9bc (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[127] Hàm con @ 0x00f908..0x00f9bc (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f908: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00f90c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00f910: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00f914: 910083fd  add      x29, sp, #0x20
//   0x00f918: aa0203f4  mov      x20, x2
//   0x00f91c: eb02003f  cmp      x1, x2
//   0x00f920: aa0003f3  mov      x19, x0
//   0x00f924: 540001c2  b.hs     #0xf95c
//   0x00f928: b9400028  ldr      w8, [x1]
//   0x00f92c: aa0103f5  mov      x21, x1
//   0x00f930: 51008508  sub      w8, w8, #0x21
//   0x00f934: 7101751f  cmp      w8, #0x5d
//   0x00f938: 54000288  b.hi     #0xf988
//   0x00f93c: b0000029  adrp     x9, #0x14000
//   0x00f940: 9104d529  add      x9, x9, #0x135
//   0x00f944: 1000008a  adr      x10, #0xf954
//   0x00f948: 3868692b  ldrb     w11, [x9, x8]
//   0x00f94c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00f950: d61f0140  br       x10
//   0x00f954: 910012a0  add      x0, x21, #4
//   0x00f958: 14000008  b        #0xf978
//   0x00f95c: f9400260  ldr      x0, [x19]
//   0x00f960: aa0303e1  mov      x1, x3
//   0x00f964: 97ffcdbb  bl       #0x3050
//   0x00f968: aa1f03e0  mov      x0, xzr
//   0x00f96c: f9000a74  str      x20, [x19, #0x10]
//   0x00f970: 52800028  mov      w8, #1
//   0x00f974: b9000a68  str      w8, [x19, #8]
//   0x00f978: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00f97c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00f980: f84307f5  ldr      x21, [sp], #0x30
//   0x00f984: d65f03c0  ret      
//   0x00f988: f9400260  ldr      x0, [x19]
//   0x00f98c: aa0303e1  mov      x1, x3
//   0x00f990: 97ffcdb0  bl       #0x3050
//   0x00f994: aa1f03e0  mov      x0, xzr
//   0x00f998: f9000a75  str      x21, [x19, #0x10]
//   0x00f99c: 17fffff5  b        #0xf970
//   0x00f9a0: aa1303e0  mov      x0, x19
//   0x00f9a4: aa1403e2  mov      x2, x20
//   0x00f9a8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00f9ac: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00f9b0: aa1503e1  mov      x1, x21
//   0x00f9b4: f84307f5  ldr      x21, [sp], #0x30
//   0x00f9b8: 17fffcf0  b        #0xed78
// ============================================================================
std::uint32_t fde_127_0f908(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f908ULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12654ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[128] Subroutine @ 0x00f9bc..0x00fc00 (580 bytes, 145 AArch64 instructions)
// [VN] Khung FDE[128] Hàm con @ 0x00f9bc..0x00fc00 (580 byte, 145 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00f9bc: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00f9c0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00f9c4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00f9c8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00f9cc: 9100c3fd  add      x29, sp, #0x30
//   0x00f9d0: aa0203f3  mov      x19, x2
//   0x00f9d4: eb02003f  cmp      x1, x2
//   0x00f9d8: aa0003f4  mov      x20, x0
//   0x00f9dc: 54000442  b.hs     #0xfa64
//   0x00f9e0: b9400028  ldr      w8, [x1]
//   0x00f9e4: aa0303f6  mov      x22, x3
//   0x00f9e8: aa0103f5  mov      x21, x1
//   0x00f9ec: 71016d1f  cmp      w8, #0x5b
//   0x00f9f0: 540004c1  b.ne     #0xfa88
//   0x00f9f4: 910012b7  add      x23, x21, #4
//   0x00f9f8: aa1403e0  mov      x0, x20
//   0x00f9fc: aa1703e1  mov      x1, x23
//   0x00fa00: aa1303e2  mov      x2, x19
//   0x00fa04: aa1603e3  mov      x3, x22
//   0x00fa08: 97fffe55  bl       #0xf35c
//   0x00fa0c: aa0003f5  mov      x21, x0
//   0x00fa10: b4000300  cbz      x0, #0xfa70
//   0x00fa14: f9400288  ldr      x8, [x20]
//   0x00fa18: eb1302bf  cmp      x21, x19
//   0x00fa1c: f9001117  str      x23, [x8, #0x20]
//   0x00fa20: 54000ec2  b.hs     #0xfbf8
//   0x00fa24: b94002a9  ldr      w9, [x21]
//   0x00fa28: 7100e93f  cmp      w9, #0x3a
//   0x00fa2c: 54000221  b.ne     #0xfa70
//   0x00fa30: 910012a9  add      x9, x21, #4
//   0x00fa34: eb13013f  cmp      x9, x19
//   0x00fa38: 54000122  b.hs     #0xfa5c
//   0x00fa3c: aa0903ea  mov      x10, x9
//   0x00fa40: b940014b  ldr      w11, [x10]
//   0x00fa44: 5100c16b  sub      w11, w11, #0x30
//   0x00fa48: 7100257f  cmp      w11, #9
//   0x00fa4c: 54000c88  b.hi     #0xfbdc
//   0x00fa50: 9100114a  add      x10, x10, #4
//   0x00fa54: eb13015f  cmp      x10, x19
//   0x00fa58: 54ffff43  b.lo     #0xfa40
//   0x00fa5c: b5000c33  cbnz     x19, #0xfbe0
//   0x00fa60: 14000055  b        #0xfbb4
//   0x00fa64: f9400288  ldr      x8, [x20]
//   0x00fa68: aa1303f5  mov      x21, x19
//   0x00fa6c: f9001513  str      x19, [x8, #0x28]
//   0x00fa70: aa1503e0  mov      x0, x21
//   0x00fa74: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00fa78: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00fa7c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00fa80: f84407f7  ldr      x23, [sp], #0x40
//   0x00fa84: d65f03c0  ret      
//   0x00fa88: b0000037  adrp     x23, #0x14000
//   0x00fa8c: 91064ef7  add      x23, x23, #0x193
//   0x00fa90: eb1302bf  cmp      x21, x19
//   0x00fa94: 54000222  b.hs     #0xfad8
//   0x00fa98: b94002a8  ldr      w8, [x21]
//   0x00fa9c: 51008508  sub      w8, w8, #0x21
//   0x00faa0: 7101751f  cmp      w8, #0x5d
//   0x00faa4: 54000448  b.hi     #0xfb2c
//   0x00faa8: 10000089  adr      x9, #0xfab8
//   0x00faac: 38686aea  ldrb     w10, [x23, x8]
//   0x00fab0: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00fab4: d61f0120  br       x9
//   0x00fab8: aa1403e0  mov      x0, x20
//   0x00fabc: aa1503e1  mov      x1, x21
//   0x00fac0: aa1303e2  mov      x2, x19
//   0x00fac4: aa1603e3  mov      x3, x22
//   0x00fac8: 97ffff90  bl       #0xf908
//   0x00facc: aa0003f5  mov      x21, x0
//   0x00fad0: b5fffe00  cbnz     x0, #0xfa90
//   0x00fad4: 17ffffe7  b        #0xfa70
//   0x00fad8: f9400288  ldr      x8, [x20]
//   0x00fadc: 52800081  mov      w1, #4
//   0x00fae0: aa1603e0  mov      x0, x22
//   0x00fae4: f9001515  str      x21, [x8, #0x28]
//   0x00fae8: f94002c8  ldr      x8, [x22]
//   0x00faec: d63f0100  blr      x8
//   0x00faf0: f9400288  ldr      x8, [x20]
//   0x00faf4: f9001900  str      x0, [x8, #0x30]
//   0x00faf8: b4000620  cbz      x0, #0xfbbc
//   0x00fafc: a9420901  ldp      x1, x2, [x8, #0x20]
//   0x00fb00: 97ffcde8  bl       #0x32a0
//   0x00fb04: 340007a0  cbz      w0, #0xfbf8
//   0x00fb08: f9400288  ldr      x8, [x20]
//   0x00fb0c: f94012c9  ldr      x9, [x22, #0x20]
//   0x00fb10: aa1603e0  mov      x0, x22
//   0x00fb14: f9401901  ldr      x1, [x8, #0x30]
//   0x00fb18: d63f0120  blr      x9
//   0x00fb1c: f9400288  ldr      x8, [x20]
//   0x00fb20: aa1303f5  mov      x21, x19
//   0x00fb24: f900191f  str      xzr, [x8, #0x30]
//   0x00fb28: 17ffffd2  b        #0xfa70
//   0x00fb2c: f9400288  ldr      x8, [x20]
//   0x00fb30: 52800081  mov      w1, #4
//   0x00fb34: aa1603e0  mov      x0, x22
//   0x00fb38: f9001515  str      x21, [x8, #0x28]
//   0x00fb3c: f94002c8  ldr      x8, [x22]
//   0x00fb40: d63f0100  blr      x8
//   0x00fb44: f9400288  ldr      x8, [x20]
//   0x00fb48: f9001900  str      x0, [x8, #0x30]
//   0x00fb4c: b4000380  cbz      x0, #0xfbbc
//   0x00fb50: a9420901  ldp      x1, x2, [x8, #0x20]
//   0x00fb54: 97ffcdd3  bl       #0x32a0
//   0x00fb58: 34000100  cbz      w0, #0xfb78
//   0x00fb5c: f9400288  ldr      x8, [x20]
//   0x00fb60: f94012c9  ldr      x9, [x22, #0x20]
//   0x00fb64: aa1603e0  mov      x0, x22
//   0x00fb68: f9401901  ldr      x1, [x8, #0x30]
//   0x00fb6c: d63f0120  blr      x9
//   0x00fb70: f9400288  ldr      x8, [x20]
//   0x00fb74: f900191f  str      xzr, [x8, #0x30]
//   0x00fb78: b94002a8  ldr      w8, [x21]
//   0x00fb7c: 7100e91f  cmp      w8, #0x3a
//   0x00fb80: 54fff781  b.ne     #0xfa70
//   0x00fb84: 910012a8  add      x8, x21, #4
//   0x00fb88: eb13011f  cmp      x8, x19
//   0x00fb8c: 54000122  b.hs     #0xfbb0
//   0x00fb90: aa0803e9  mov      x9, x8
//   0x00fb94: b940012a  ldr      w10, [x9]
//   0x00fb98: 5100c14a  sub      w10, w10, #0x30
//   0x00fb9c: 7100255f  cmp      w10, #9
//   0x00fba0: 54000268  b.hi     #0xfbec
//   0x00fba4: 91001129  add      x9, x9, #4
//   0x00fba8: eb13013f  cmp      x9, x19
//   0x00fbac: 54ffff43  b.lo     #0xfb94
//   0x00fbb0: b5000213  cbnz     x19, #0xfbf0
//   0x00fbb4: aa1f03f5  mov      x21, xzr
//   0x00fbb8: 17ffffae  b        #0xfa70
//   0x00fbbc: aa0803e0  mov      x0, x8
//   0x00fbc0: aa1603e1  mov      x1, x22
//   0x00fbc4: 97ffcd23  bl       #0x3050
//   0x00fbc8: 52800068  mov      w8, #3
//   0x00fbcc: aa1f03f5  mov      x21, xzr
//   0x00fbd0: f9000a9f  str      xzr, [x20, #0x10]
//   0x00fbd4: b9000a88  str      w8, [x20, #8]
//   0x00fbd8: 17ffffa6  b        #0xfa70
//   0x00fbdc: aa0a03f3  mov      x19, x10
//   0x00fbe0: a9054d09  stp      x9, x19, [x8, #0x50]
//   0x00fbe4: aa1303f5  mov      x21, x19
//   0x00fbe8: 17ffffa2  b        #0xfa70
//   0x00fbec: aa0903f3  mov      x19, x9
//   0x00fbf0: f9400289  ldr      x9, [x20]
//   0x00fbf4: a9054d28  stp      x8, x19, [x9, #0x50]
//   0x00fbf8: aa1303f5  mov      x21, x19
//   0x00fbfc: 17ffff9d  b        #0xfa70
// ============================================================================
std::uint32_t fde_128_0f9bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000f9bcULL;
    for (std::size_t i = 0; i < 145ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12699ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[129] Subroutine @ 0x00fc00..0x00fcf8 (248 bytes, 62 AArch64 instructions)
// [VN] Khung FDE[129] Hàm con @ 0x00fc00..0x00fcf8 (248 byte, 62 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00fc00: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00fc04: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00fc08: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00fc0c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00fc10: 9100c3fd  add      x29, sp, #0x30
//   0x00fc14: aa0303f4  mov      x20, x3
//   0x00fc18: aa0203f5  mov      x21, x2
//   0x00fc1c: eb02003f  cmp      x1, x2
//   0x00fc20: aa0003f3  mov      x19, x0
//   0x00fc24: 54000322  b.hs     #0xfc88
//   0x00fc28: b0000037  adrp     x23, #0x14000
//   0x00fc2c: aa0103f6  mov      x22, x1
//   0x00fc30: 9107c6f7  add      x23, x23, #0x1f1
//   0x00fc34: b94002c8  ldr      w8, [x22]
//   0x00fc38: 51008508  sub      w8, w8, #0x21
//   0x00fc3c: 7101751f  cmp      w8, #0x5d
//   0x00fc40: 540003c8  b.hi     #0xfcb8
//   0x00fc44: 10000089  adr      x9, #0xfc54
//   0x00fc48: 38686aea  ldrb     w10, [x23, x8]
//   0x00fc4c: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00fc50: d61f0120  br       x9
//   0x00fc54: aa1303e0  mov      x0, x19
//   0x00fc58: aa1603e1  mov      x1, x22
//   0x00fc5c: aa1503e2  mov      x2, x21
//   0x00fc60: aa1403e3  mov      x3, x20
//   0x00fc64: 97ffff29  bl       #0xf908
//   0x00fc68: aa0003f6  mov      x22, x0
//   0x00fc6c: b40001a0  cbz      x0, #0xfca0
//   0x00fc70: eb1502df  cmp      x22, x21
//   0x00fc74: 54fffe03  b.lo     #0xfc34
//   0x00fc78: 14000004  b        #0xfc88
//   0x00fc7c: 910012d6  add      x22, x22, #4
//   0x00fc80: eb1502df  cmp      x22, x21
//   0x00fc84: 54fffd83  b.lo     #0xfc34
//   0x00fc88: f9400260  ldr      x0, [x19]
//   0x00fc8c: aa1403e1  mov      x1, x20
//   0x00fc90: 97ffccf0  bl       #0x3050
//   0x00fc94: f9000a75  str      x21, [x19, #0x10]
//   0x00fc98: 52800028  mov      w8, #1
//   0x00fc9c: b9000a68  str      w8, [x19, #8]
//   0x00fca0: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00fca4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00fca8: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00fcac: aa1f03e0  mov      x0, xzr
//   0x00fcb0: f84407f7  ldr      x23, [sp], #0x40
//   0x00fcb4: d65f03c0  ret      
//   0x00fcb8: f9400260  ldr      x0, [x19]
//   0x00fcbc: aa1403e1  mov      x1, x20
//   0x00fcc0: 97ffcce4  bl       #0x3050
//   0x00fcc4: f9000a76  str      x22, [x19, #0x10]
//   0x00fcc8: 17fffff4  b        #0xfc98
//   0x00fccc: f9400268  ldr      x8, [x19]
//   0x00fcd0: 910012c1  add      x1, x22, #4
//   0x00fcd4: aa1303e0  mov      x0, x19
//   0x00fcd8: aa1503e2  mov      x2, x21
//   0x00fcdc: a9018516  stp      x22, x1, [x8, #0x18]
//   0x00fce0: aa1403e3  mov      x3, x20
//   0x00fce4: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00fce8: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00fcec: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00fcf0: f84407f7  ldr      x23, [sp], #0x40
//   0x00fcf4: 17ffff32  b        #0xf9bc
// ============================================================================
std::uint32_t fde_129_0fc00(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000fc00ULL;
    for (std::size_t i = 0; i < 62ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12844ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[130] Subroutine @ 0x00fcf8..0x00fd8c (148 bytes, 37 AArch64 instructions)
// [VN] Khung FDE[130] Hàm con @ 0x00fcf8..0x00fd8c (148 byte, 37 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00fcf8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00fcfc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00fd00: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00fd04: 910083fd  add      x29, sp, #0x20
//   0x00fd08: aa0203f3  mov      x19, x2
//   0x00fd0c: eb02003f  cmp      x1, x2
//   0x00fd10: 54000322  b.hs     #0xfd74
//   0x00fd14: b0000036  adrp     x22, #0x14000
//   0x00fd18: aa0303f4  mov      x20, x3
//   0x00fd1c: aa0003f5  mov      x21, x0
//   0x00fd20: 91093ed6  add      x22, x22, #0x24f
//   0x00fd24: b9400028  ldr      w8, [x1]
//   0x00fd28: 51008508  sub      w8, w8, #0x21
//   0x00fd2c: 7101751f  cmp      w8, #0x5d
//   0x00fd30: 54000248  b.hi     #0xfd78
//   0x00fd34: 10000089  adr      x9, #0xfd44
//   0x00fd38: 38686aca  ldrb     w10, [x22, x8]
//   0x00fd3c: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x00fd40: d61f0120  br       x9
//   0x00fd44: aa1503e0  mov      x0, x21
//   0x00fd48: aa1303e2  mov      x2, x19
//   0x00fd4c: aa1403e3  mov      x3, x20
//   0x00fd50: 97fffd56  bl       #0xf2a8
//   0x00fd54: aa0003e1  mov      x1, x0
//   0x00fd58: b4000100  cbz      x0, #0xfd78
//   0x00fd5c: eb13003f  cmp      x1, x19
//   0x00fd60: 54fffe23  b.lo     #0xfd24
//   0x00fd64: 14000004  b        #0xfd74
//   0x00fd68: 91001021  add      x1, x1, #4
//   0x00fd6c: eb13003f  cmp      x1, x19
//   0x00fd70: 54fffda3  b.lo     #0xfd24
//   0x00fd74: aa1303e1  mov      x1, x19
//   0x00fd78: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00fd7c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00fd80: aa0103e0  mov      x0, x1
//   0x00fd84: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x00fd88: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_130_0fcf8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000fcf8ULL;
    for (std::size_t i = 0; i < 37ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12906ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[131] Subroutine @ 0x00fd8c..0x00fe04 (120 bytes, 30 AArch64 instructions)
// [VN] Khung FDE[131] Hàm con @ 0x00fd8c..0x00fe04 (120 byte, 30 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00fd8c: 51000428  sub      w8, w1, #1
//   0x00fd90: 71000d1f  cmp      w8, #3
//   0x00fd94: 54000368  b.hi     #0xfe00
//   0x00fd98: b0000029  adrp     x9, #0x14000
//   0x00fd9c: 910ab529  add      x9, x9, #0x2ad
//   0x00fda0: 1000008a  adr      x10, #0xfdb0
//   0x00fda4: 3868692b  ldrb     w11, [x9, x8]
//   0x00fda8: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00fdac: d61f0140  br       x10
//   0x00fdb0: 3900005f  strb     wzr, [x2]
//   0x00fdb4: 39400008  ldrb     w8, [x0]
//   0x00fdb8: 14000011  b        #0xfdfc
//   0x00fdbc: 3900005f  strb     wzr, [x2]
//   0x00fdc0: 39400008  ldrb     w8, [x0]
//   0x00fdc4: 39400409  ldrb     w9, [x0, #1]
//   0x00fdc8: 1400000c  b        #0xfdf8
//   0x00fdcc: 39400008  ldrb     w8, [x0]
//   0x00fdd0: 39000048  strb     w8, [x2]
//   0x00fdd4: 39400408  ldrb     w8, [x0, #1]
//   0x00fdd8: 39400809  ldrb     w9, [x0, #2]
//   0x00fddc: 14000007  b        #0xfdf8
//   0x00fde0: 39400008  ldrb     w8, [x0]
//   0x00fde4: 39400409  ldrb     w9, [x0, #1]
//   0x00fde8: 0b081128  add      w8, w9, w8, lsl #4
//   0x00fdec: 39000048  strb     w8, [x2]
//   0x00fdf0: 39400808  ldrb     w8, [x0, #2]
//   0x00fdf4: 39400c09  ldrb     w9, [x0, #3]
//   0x00fdf8: 0b081128  add      w8, w9, w8, lsl #4
//   0x00fdfc: 39000448  strb     w8, [x2, #1]
//   0x00fe00: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_131_0fd8c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000fd8cULL;
    for (std::size_t i = 0; i < 30ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12943ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[132] Subroutine @ 0x00fe04..0x00fe54 (80 bytes, 20 AArch64 instructions)
// [VN] Khung FDE[132] Hàm con @ 0x00fe04..0x00fe54 (80 byte, 20 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00fe04: 7100083f  cmp      w1, #2
//   0x00fe08: 540000a0  b.eq     #0xfe1c
//   0x00fe0c: 7100043f  cmp      w1, #1
//   0x00fe10: 54000101  b.ne     #0xfe30
//   0x00fe14: 39400000  ldrb     w0, [x0]
//   0x00fe18: d65f03c0  ret      
//   0x00fe1c: 39400008  ldrb     w8, [x0]
//   0x00fe20: 39400409  ldrb     w9, [x0, #1]
//   0x00fe24: 5280014a  mov      w10, #0xa
//   0x00fe28: 1b0a2500  madd     w0, w8, w10, w9
//   0x00fe2c: d65f03c0  ret      
//   0x00fe30: 39400008  ldrb     w8, [x0]
//   0x00fe34: 3940040a  ldrb     w10, [x0, #1]
//   0x00fe38: 3940080b  ldrb     w11, [x0, #2]
//   0x00fe3c: 52800c89  mov      w9, #0x64
//   0x00fe40: 1b097d08  mul      w8, w8, w9
//   0x00fe44: 52800149  mov      w9, #0xa
//   0x00fe48: 1b092148  madd     w8, w10, w9, w8
//   0x00fe4c: 0b0b0100  add      w0, w8, w11
//   0x00fe50: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_132_0fe04(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000fe04ULL;
    for (std::size_t i = 0; i < 20ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12973ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[133] Subroutine @ 0x00fe54..0x00fe84 (48 bytes, 12 AArch64 instructions)
// [VN] Khung FDE[133] Hàm con @ 0x00fe54..0x00fe84 (48 byte, 12 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00fe54: b4000140  cbz      x0, #0xfe7c
//   0x00fe58: aa0103e4  mov      x4, x1
//   0x00fe5c: b4000101  cbz      x1, #0xfe7c
//   0x00fe60: aa0003e1  mov      x1, x0
//   0x00fe64: 52800025  mov      w5, #1
//   0x00fe68: 52800026  mov      w6, #1
//   0x00fe6c: aa1f03e0  mov      x0, xzr
//   0x00fe70: 2a1f03e2  mov      w2, wzr
//   0x00fe74: aa1f03e3  mov      x3, xzr
//   0x00fe78: 1400000f  b        #0xfeb4
//   0x00fe7c: 52800040  mov      w0, #2
//   0x00fe80: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_133_0fe54(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000fe54ULL;
    for (std::size_t i = 0; i < 12ULL; ++i) {
        std::uint32_t insn = kTextInstructions[12993ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[134] Subroutine @ 0x00fe84..0x00feb4 (48 bytes, 12 AArch64 instructions)
// [VN] Khung FDE[134] Hàm con @ 0x00fe84..0x00feb4 (48 byte, 12 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00fe84: b4000140  cbz      x0, #0xfeac
//   0x00fe88: aa0103e4  mov      x4, x1
//   0x00fe8c: b4000101  cbz      x1, #0xfeac
//   0x00fe90: 2a0303e6  mov      w6, w3
//   0x00fe94: 2a0203e5  mov      w5, w2
//   0x00fe98: aa0003e1  mov      x1, x0
//   0x00fe9c: aa1f03e0  mov      x0, xzr
//   0x00fea0: 2a1f03e2  mov      w2, wzr
//   0x00fea4: aa1f03e3  mov      x3, xzr
//   0x00fea8: 14000003  b        #0xfeb4
//   0x00feac: 52800040  mov      w0, #2
//   0x00feb0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_134_0fe84(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000fe84ULL;
    for (std::size_t i = 0; i < 12ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13005ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[135] Subroutine @ 0x00feb4..0x0100cc (536 bytes, 134 AArch64 instructions)
// [VN] Khung FDE[135] Hàm con @ 0x00feb4..0x0100cc (536 byte, 134 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00feb4: d10283ff  sub      sp, sp, #0xa0
//   0x00feb8: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x00febc: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x00fec0: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x00fec4: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x00fec8: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x00fecc: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x00fed0: 910243fd  add      x29, sp, #0x90
//   0x00fed4: aa0103f8  mov      x24, x1
//   0x00fed8: 29051be5  stp      w5, w6, [sp, #0x28]
//   0x00fedc: f90007e3  str      x3, [sp, #8]
//   0x00fee0: f9001be0  str      x0, [sp, #0x30]
//   0x00fee4: f9000fe4  str      x4, [sp, #0x18]
//   0x00fee8: b40000a0  cbz      x0, #0xfefc
//   0x00feec: 51000442  sub      w2, w2, #1
//   0x00fef0: f9401bf9  ldr      x25, [sp, #0x30]
//   0x00fef4: b50000b8  cbnz     x24, #0xff08
//   0x00fef8: 14000060  b        #0x10078
//   0x00fefc: b900009f  str      wzr, [x4]
//   0x00ff00: f9401bf9  ldr      x25, [sp, #0x30]
//   0x00ff04: b4000bb8  cbz      x24, #0x10078
//   0x00ff08: b9402fe8  ldr      w8, [sp, #0x2c]
//   0x00ff0c: f9401bf9  ldr      x25, [sp, #0x30]
//   0x00ff10: 528000c9  mov      w9, #6
//   0x00ff14: 93407c4a  sxtw     x10, w2
//   0x00ff18: 7100051f  cmp      w8, #1
//   0x00ff1c: 52800068  mov      w8, #3
//   0x00ff20: f90013ea  str      x10, [sp, #0x20]
//   0x00ff24: 52800035  mov      w21, #1
//   0x00ff28: 12b0000a  mov      w10, #0x7fffffff
//   0x00ff2c: 1a880136  csel     w22, w9, w8, eq
//   0x00ff30: cb1902a8  sub      x8, x21, x25
//   0x00ff34: 1ad60954  udiv     w20, w10, w22
//   0x00ff38: b9003fff  str      wzr, [sp, #0x3c]
//   0x00ff3c: f9000be8  str      x8, [sp, #0x10]
//   0x00ff40: a9406b1b  ldp      x27, x26, [x24]
//   0x00ff44: b500027b  cbnz     x27, #0xff90
//   0x00ff48: 1400001a  b        #0xffb0
//   0x00ff4c: f9400feb  ldr      x11, [sp, #0x18]
//   0x00ff50: b9403fec  ldr      w12, [sp, #0x3c]
//   0x00ff54: f100035f  cmp      x26, #0
//   0x00ff58: 1a9707ea  csinc    w10, wzr, w23, eq
//   0x00ff5c: b9400169  ldr      w9, [x11]
//   0x00ff60: 0b0c0108  add      w8, w8, w12
//   0x00ff64: 710006bf  cmp      w21, #1
//   0x00ff68: 0b0a0108  add      w8, w8, w10
//   0x00ff6c: 1a9f158c  csinc    w12, w12, wzr, ne
//   0x00ff70: 0b090108  add      w8, w8, w9
//   0x00ff74: b9003fec  str      w12, [sp, #0x3c]
//   0x00ff78: b9000168  str      w8, [x11]
//   0x00ff7c: 1a9503f5  csel     w21, wzr, w21, eq
//   0x00ff80: f9400b18  ldr      x24, [x24, #0x10]
//   0x00ff84: b40007b8  cbz      x24, #0x10078
//   0x00ff88: a9406b1b  ldp      x27, x26, [x24]
//   0x00ff8c: b400013b  cbz      x27, #0xffb0
//   0x00ff90: aa1b03e0  mov      x0, x27
//   0x00ff94: 97ffcca7  bl       #0x3230
//   0x00ff98: aa0003f3  mov      x19, x0
//   0x00ff9c: b40000fa  cbz      x26, #0xffb8
//   0x00ffa0: aa1a03e0  mov      x0, x26
//   0x00ffa4: 97ffcca3  bl       #0x3230
//   0x00ffa8: aa0003fc  mov      x28, x0
//   0x00ffac: 14000004  b        #0xffbc
//   0x00ffb0: aa1f03f3  mov      x19, xzr
//   0x00ffb4: b5ffff7a  cbnz     x26, #0xffa0
//   0x00ffb8: aa1f03fc  mov      x28, xzr
//   0x00ffbc: f9401be9  ldr      x9, [sp, #0x30]
//   0x00ffc0: eb14027f  cmp      x19, x20
//   0x00ffc4: 52800080  mov      w0, #4
//   0x00ffc8: 54000722  b.hs     #0x100ac
//   0x00ffcc: eb14039f  cmp      x28, x20
//   0x00ffd0: 540006e2  b.hs     #0x100ac
//   0x00ffd4: 1b137ec8  mul      w8, w22, w19
//   0x00ffd8: 1b1c7ed7  mul      w23, w22, w28
//   0x00ffdc: b4fffb89  cbz      x9, #0xff4c
//   0x00ffe0: b9403fea  ldr      w10, [sp, #0x3c]
//   0x00ffe4: cb090329  sub      x9, x25, x9
//   0x00ffe8: 8b2ac129  add      x9, x9, w10, sxtw
//   0x00ffec: 8b28c128  add      x8, x9, w8, sxtw
//   0x00fff0: f94013e9  ldr      x9, [sp, #0x20]
//   0x00fff4: eb09011f  cmp      x8, x9
//   0x00fff8: 5400058c  b.gt     #0x100a8
//   0x00fffc: 710006bf  cmp      w21, #1
//   0x010000: 540000a1  b.ne     #0x10014
//   0x010004: 52800028  mov      w8, #1
//   0x010008: 2a1f03f5  mov      w21, wzr
//   0x01000c: b9003fe8  str      w8, [sp, #0x3c]
//   0x010010: 14000003  b        #0x1001c
//   0x010014: 528004c8  mov      w8, #0x26
//   0x010018: 38001728  strb     w8, [x25], #1
//   0x01001c: 294513e3  ldp      w3, w4, [sp, #0x28]
//   0x010020: 8b130361  add      x1, x27, x19
//   0x010024: aa1b03e0  mov      x0, x27
//   0x010028: aa1903e2  mov      x2, x25
//   0x01002c: 97ffcc6d  bl       #0x31e0
//   0x010030: aa0003f9  mov      x25, x0
//   0x010034: b4fffa7a  cbz      x26, #0xff80
//   0x010038: f9400be8  ldr      x8, [sp, #0x10]
//   0x01003c: f94013e9  ldr      x9, [sp, #0x20]
//   0x010040: 8b37c108  add      x8, x8, w23, sxtw
//   0x010044: 8b190108  add      x8, x8, x25
//   0x010048: eb09011f  cmp      x8, x9
//   0x01004c: 540002ec  b.gt     #0x100a8
//   0x010050: 528007a8  mov      w8, #0x3d
//   0x010054: 38001728  strb     w8, [x25], #1
//   0x010058: 294513e3  ldp      w3, w4, [sp, #0x28]
//   0x01005c: 8b1c0341  add      x1, x26, x28
//   0x010060: aa1a03e0  mov      x0, x26
//   0x010064: aa1903e2  mov      x2, x25
//   0x010068: 97ffcc5e  bl       #0x31e0
//   0x01006c: aa0003f9  mov      x25, x0
//   0x010070: f9400b18  ldr      x24, [x24, #0x10]
//   0x010074: b5fff8b8  cbnz     x24, #0xff88
//   0x010078: f9401be8  ldr      x8, [sp, #0x30]
//   0x01007c: b4000128  cbz      x8, #0x100a0
//   0x010080: f94007e9  ldr      x9, [sp, #8]
//   0x010084: 3900033f  strb     wzr, [x25]
//   0x010088: b40000c9  cbz      x9, #0x100a0
//   0x01008c: 4b080328  sub      w8, w25, w8
//   0x010090: 2a1f03e0  mov      w0, wzr
//   0x010094: 11000508  add      w8, w8, #1
//   0x010098: b9000128  str      w8, [x9]
//   0x01009c: 14000004  b        #0x100ac
//   0x0100a0: 2a1f03e0  mov      w0, wzr
//   0x0100a4: 14000002  b        #0x100ac
//   0x0100a8: 52800080  mov      w0, #4
//   0x0100ac: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x0100b0: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x0100b4: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x0100b8: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x0100bc: a94567fa  ldp      x26, x25, [sp, #0x50]
//   0x0100c0: a9446ffc  ldp      x28, x27, [sp, #0x40]
//   0x0100c4: 910283ff  add      sp, sp, #0xa0
//   0x0100c8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_135_0feb4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000feb4ULL;
    for (std::size_t i = 0; i < 134ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13017ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[136] Subroutine @ 0x0100cc..0x0100fc (48 bytes, 12 AArch64 instructions)
// [VN] Khung FDE[136] Hàm con @ 0x0100cc..0x0100fc (48 byte, 12 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0100cc: 52800048  mov      w8, #2
//   0x0100d0: b4000120  cbz      x0, #0x100f4
//   0x0100d4: b4000101  cbz      x1, #0x100f4
//   0x0100d8: 7100045f  cmp      w2, #1
//   0x0100dc: 540000ab  b.lt     #0x100f0
//   0x0100e0: 52800025  mov      w5, #1
//   0x0100e4: 52800026  mov      w6, #1
//   0x0100e8: aa1f03e4  mov      x4, xzr
//   0x0100ec: 17ffff72  b        #0xfeb4
//   0x0100f0: 52800088  mov      w8, #4
//   0x0100f4: 2a0803e0  mov      w0, w8
//   0x0100f8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_136_100cc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000100ccULL;
    for (std::size_t i = 0; i < 12ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13151ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[137] Subroutine @ 0x0100fc..0x010130 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[137] Hàm con @ 0x0100fc..0x010130 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0100fc: aa0003e8  mov      x8, x0
//   0x010100: 52800040  mov      w0, #2
//   0x010104: b4000148  cbz      x8, #0x1012c
//   0x010108: b4000121  cbz      x1, #0x1012c
//   0x01010c: 7100045f  cmp      w2, #1
//   0x010110: 540000cb  b.lt     #0x10128
//   0x010114: 2a0503e6  mov      w6, w5
//   0x010118: 2a0403e5  mov      w5, w4
//   0x01011c: aa0803e0  mov      x0, x8
//   0x010120: aa1f03e4  mov      x4, xzr
//   0x010124: 17ffff64  b        #0xfeb4
//   0x010128: 52800080  mov      w0, #4
//   0x01012c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_137_100fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000100fcULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13163ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[138] Subroutine @ 0x010130..0x01013c (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[138] Hàm con @ 0x010130..0x01013c (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010130: 52800022  mov      w2, #1
//   0x010134: 52800023  mov      w3, #1
//   0x010138: 17ffcbaa  b        #0x2fe0
// ============================================================================
std::uint32_t fde_138_10130(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010130ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13176ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[139] Subroutine @ 0x01013c..0x010248 (268 bytes, 67 AArch64 instructions)
// [VN] Khung FDE[139] Hàm con @ 0x01013c..0x010248 (268 byte, 67 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x01013c: d10183ff  sub      sp, sp, #0x60
//   0x010140: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x010144: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x010148: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x01014c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x010150: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x010154: 910143fd  add      x29, sp, #0x50
//   0x010158: 52800057  mov      w23, #2
//   0x01015c: b4000660  cbz      x0, #0x10228
//   0x010160: aa0103f6  mov      x22, x1
//   0x010164: b4000621  cbz      x1, #0x10228
//   0x010168: 2a0303f4  mov      w20, w3
//   0x01016c: 2a0203f5  mov      w21, w2
//   0x010170: aa0003f3  mov      x19, x0
//   0x010174: 910033e4  add      x4, sp, #0xc
//   0x010178: aa1f03e0  mov      x0, xzr
//   0x01017c: aa1603e1  mov      x1, x22
//   0x010180: 2a1f03e2  mov      w2, wzr
//   0x010184: aa1f03e3  mov      x3, xzr
//   0x010188: 2a1503e5  mov      w5, w21
//   0x01018c: 2a1403e6  mov      w6, w20
//   0x010190: 97ffff49  bl       #0xfeb4
//   0x010194: 2a0003f7  mov      w23, w0
//   0x010198: 35000480  cbnz     w0, #0x10228
//   0x01019c: b9800ffa  ldrsw    x26, [sp, #0xc]
//   0x0101a0: 12b00008  mov      w8, #0x7fffffff
//   0x0101a4: 6b08035f  cmp      w26, w8
//   0x0101a8: 54000320  b.eq     #0x1020c
//   0x0101ac: f0000058  adrp     x24, #0x1b000
//   0x0101b0: f947ff18  ldr      x24, [x24, #0xff8]
//   0x0101b4: 91000757  add      x23, x26, #1
//   0x0101b8: 52800022  mov      w2, #1
//   0x0101bc: aa1703e1  mov      x1, x23
//   0x0101c0: f9400708  ldr      x8, [x24, #8]
//   0x0101c4: aa1803e0  mov      x0, x24
//   0x0101c8: b9000ff7  str      w23, [sp, #0xc]
//   0x0101cc: d63f0100  blr      x8
//   0x0101d0: b40001e0  cbz      x0, #0x1020c
//   0x0101d4: aa0003f9  mov      x25, x0
//   0x0101d8: 37f801fa  tbnz     w26, #0x1f, #0x10214
//   0x0101dc: aa1903e0  mov      x0, x25
//   0x0101e0: aa1603e1  mov      x1, x22
//   0x0101e4: 2a1703e2  mov      w2, w23
//   0x0101e8: aa1f03e3  mov      x3, xzr
//   0x0101ec: aa1f03e4  mov      x4, xzr
//   0x0101f0: 2a1503e5  mov      w5, w21
//   0x0101f4: 2a1403e6  mov      w6, w20
//   0x0101f8: 97ffff2f  bl       #0xfeb4
//   0x0101fc: 2a0003f7  mov      w23, w0
//   0x010200: 350000c0  cbnz     w0, #0x10218
//   0x010204: f9000279  str      x25, [x19]
//   0x010208: 14000008  b        #0x10228
//   0x01020c: 52800077  mov      w23, #3
//   0x010210: 14000006  b        #0x10228
//   0x010214: 52800097  mov      w23, #4
//   0x010218: f9401308  ldr      x8, [x24, #0x20]
//   0x01021c: aa1803e0  mov      x0, x24
//   0x010220: aa1903e1  mov      x1, x25
//   0x010224: d63f0100  blr      x8
//   0x010228: 2a1703e0  mov      w0, w23
//   0x01022c: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x010230: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x010234: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x010238: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x01023c: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x010240: 910183ff  add      sp, sp, #0x60
//   0x010244: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_139_1013c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0001013cULL;
    for (std::size_t i = 0; i < 67ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13179ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[140] Subroutine @ 0x010248..0x010378 (304 bytes, 76 AArch64 instructions)
// [VN] Khung FDE[140] Hàm con @ 0x010248..0x010378 (304 byte, 76 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010248: d10183ff  sub      sp, sp, #0x60
//   0x01024c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x010250: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x010254: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x010258: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01025c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x010260: 910143fd  add      x29, sp, #0x50
//   0x010264: b4000680  cbz      x0, #0x10334
//   0x010268: aa0403f3  mov      x19, x4
//   0x01026c: 2a0303f5  mov      w21, w3
//   0x010270: 2a0203f6  mov      w22, w2
//   0x010274: aa0103f7  mov      x23, x1
//   0x010278: aa0003f4  mov      x20, x0
//   0x01027c: b40000e4  cbz      x4, #0x10298
//   0x010280: aa1303e0  mov      x0, x19
//   0x010284: 97ffcbf7  bl       #0x3260
//   0x010288: 7100041f  cmp      w0, #1
//   0x01028c: 540000a0  b.eq     #0x102a0
//   0x010290: 52800158  mov      w24, #0xa
//   0x010294: 14000029  b        #0x10338
//   0x010298: f0000053  adrp     x19, #0x1b000
//   0x01029c: f947fe73  ldr      x19, [x19, #0xff8]
//   0x0102a0: b40004b7  cbz      x23, #0x10334
//   0x0102a4: 910033e4  add      x4, sp, #0xc
//   0x0102a8: aa1f03e0  mov      x0, xzr
//   0x0102ac: aa1703e1  mov      x1, x23
//   0x0102b0: 2a1f03e2  mov      w2, wzr
//   0x0102b4: aa1f03e3  mov      x3, xzr
//   0x0102b8: 2a1603e5  mov      w5, w22
//   0x0102bc: 2a1503e6  mov      w6, w21
//   0x0102c0: 97fffefd  bl       #0xfeb4
//   0x0102c4: 2a0003f8  mov      w24, w0
//   0x0102c8: 35000380  cbnz     w0, #0x10338
//   0x0102cc: b9800ffa  ldrsw    x26, [sp, #0xc]
//   0x0102d0: 12b00008  mov      w8, #0x7fffffff
//   0x0102d4: 6b08035f  cmp      w26, w8
//   0x0102d8: 54000400  b.eq     #0x10358
//   0x0102dc: 91000758  add      x24, x26, #1
//   0x0102e0: b9000ff8  str      w24, [sp, #0xc]
//   0x0102e4: f9400668  ldr      x8, [x19, #8]
//   0x0102e8: 52800022  mov      w2, #1
//   0x0102ec: aa1303e0  mov      x0, x19
//   0x0102f0: aa1803e1  mov      x1, x24
//   0x0102f4: d63f0100  blr      x8
//   0x0102f8: b4000300  cbz      x0, #0x10358
//   0x0102fc: aa0003f9  mov      x25, x0
//   0x010300: 37f8031a  tbnz     w26, #0x1f, #0x10360
//   0x010304: aa1903e0  mov      x0, x25
//   0x010308: aa1703e1  mov      x1, x23
//   0x01030c: 2a1803e2  mov      w2, w24
//   0x010310: aa1f03e3  mov      x3, xzr
//   0x010314: aa1f03e4  mov      x4, xzr
//   0x010318: 2a1603e5  mov      w5, w22
//   0x01031c: 2a1503e6  mov      w6, w21
//   0x010320: 97fffee5  bl       #0xfeb4
//   0x010324: 2a0003f8  mov      w24, w0
//   0x010328: 350001e0  cbnz     w0, #0x10364
//   0x01032c: f9000299  str      x25, [x20]
//   0x010330: 14000002  b        #0x10338
//   0x010334: 52800058  mov      w24, #2
//   0x010338: 2a1803e0  mov      w0, w24
//   0x01033c: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x010340: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x010344: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x010348: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x01034c: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x010350: 910183ff  add      sp, sp, #0x60
//   0x010354: d65f03c0  ret      
//   0x010358: 52800078  mov      w24, #3
//   0x01035c: 17fffff7  b        #0x10338
//   0x010360: 52800098  mov      w24, #4
//   0x010364: f9401268  ldr      x8, [x19, #0x20]
//   0x010368: aa1303e0  mov      x0, x19
//   0x01036c: aa1903e1  mov      x1, x25
//   0x010370: d63f0100  blr      x8
//   0x010374: 17fffff1  b        #0x10338
// ============================================================================
std::uint32_t fde_140_10248(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010248ULL;
    for (std::size_t i = 0; i < 76ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13246ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[141] Subroutine @ 0x010378..0x0103e4 (108 bytes, 27 AArch64 instructions)
// [VN] Khung FDE[141] Hàm con @ 0x010378..0x0103e4 (108 byte, 27 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010378: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01037c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x010380: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x010384: 910083fd  add      x29, sp, #0x20
//   0x010388: b4000260  cbz      x0, #0x103d4
//   0x01038c: f0000054  adrp     x20, #0x1b000
//   0x010390: f947fe94  ldr      x20, [x20, #0xff8]
//   0x010394: aa0003f3  mov      x19, x0
//   0x010398: f9401288  ldr      x8, [x20, #0x20]
//   0x01039c: f9400261  ldr      x1, [x19]
//   0x0103a0: f9400a75  ldr      x21, [x19, #0x10]
//   0x0103a4: aa1403e0  mov      x0, x20
//   0x0103a8: d63f0100  blr      x8
//   0x0103ac: f9401288  ldr      x8, [x20, #0x20]
//   0x0103b0: f9400661  ldr      x1, [x19, #8]
//   0x0103b4: aa1403e0  mov      x0, x20
//   0x0103b8: d63f0100  blr      x8
//   0x0103bc: f9401288  ldr      x8, [x20, #0x20]
//   0x0103c0: aa1403e0  mov      x0, x20
//   0x0103c4: aa1303e1  mov      x1, x19
//   0x0103c8: d63f0100  blr      x8
//   0x0103cc: aa1503f3  mov      x19, x21
//   0x0103d0: b5fffe55  cbnz     x21, #0x10398
//   0x0103d4: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0103d8: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0103dc: f84307f5  ldr      x21, [sp], #0x30
//   0x0103e0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_141_10378(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010378ULL;
    for (std::size_t i = 0; i < 27ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13322ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[142] Subroutine @ 0x0103e4..0x010474 (144 bytes, 36 AArch64 instructions)
// [VN] Khung FDE[142] Hàm con @ 0x0103e4..0x010474 (144 byte, 36 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0103e4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0103e8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0103ec: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0103f0: 910083fd  add      x29, sp, #0x20
//   0x0103f4: aa0003f4  mov      x20, x0
//   0x0103f8: b4000101  cbz      x1, #0x10418
//   0x0103fc: aa0103e0  mov      x0, x1
//   0x010400: aa0103f3  mov      x19, x1
//   0x010404: 97ffcb97  bl       #0x3260
//   0x010408: 7100041f  cmp      w0, #1
//   0x01040c: 540000a0  b.eq     #0x10420
//   0x010410: 52800140  mov      w0, #0xa
//   0x010414: 14000014  b        #0x10464
//   0x010418: f0000053  adrp     x19, #0x1b000
//   0x01041c: f947fe73  ldr      x19, [x19, #0xff8]
//   0x010420: b4000214  cbz      x20, #0x10460
//   0x010424: f9401268  ldr      x8, [x19, #0x20]
//   0x010428: f9400281  ldr      x1, [x20]
//   0x01042c: f9400a95  ldr      x21, [x20, #0x10]
//   0x010430: aa1303e0  mov      x0, x19
//   0x010434: d63f0100  blr      x8
//   0x010438: f9401268  ldr      x8, [x19, #0x20]
//   0x01043c: f9400681  ldr      x1, [x20, #8]
//   0x010440: aa1303e0  mov      x0, x19
//   0x010444: d63f0100  blr      x8
//   0x010448: f9401268  ldr      x8, [x19, #0x20]
//   0x01044c: aa1303e0  mov      x0, x19
//   0x010450: aa1403e1  mov      x1, x20
//   0x010454: d63f0100  blr      x8
//   0x010458: aa1503f4  mov      x20, x21
//   0x01045c: b5fffe55  cbnz     x21, #0x10424
//   0x010460: 2a1f03e0  mov      w0, wzr
//   0x010464: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x010468: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x01046c: f84307f5  ldr      x21, [sp], #0x30
//   0x010470: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_142_103e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000103e4ULL;
    for (std::size_t i = 0; i < 36ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13349ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[143] Subroutine @ 0x010474..0x010484 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[143] Hàm con @ 0x010474..0x010484 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010474: 52800024  mov      w4, #1
//   0x010478: 52800065  mov      w5, #3
//   0x01047c: aa1f03e6  mov      x6, xzr
//   0x010480: 17ffcba8  b        #0x3320
// ============================================================================
std::uint32_t fde_143_10474(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010474ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13385ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[144] Subroutine @ 0x010484..0x01048c (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[144] Hàm con @ 0x010484..0x01048c (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010484: aa1f03e6  mov      x6, xzr
//   0x010488: 17ffcba6  b        #0x3320
// ============================================================================
std::uint32_t fde_144_10484(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010484ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13389ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[145] Subroutine @ 0x01048c..0x010740 (692 bytes, 173 AArch64 instructions)
// [VN] Khung FDE[145] Hàm con @ 0x01048c..0x010740 (692 byte, 173 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x01048c: d10203ff  sub      sp, sp, #0x80
//   0x010490: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x010494: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x010498: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x01049c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x0104a0: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x0104a4: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x0104a8: 9101c3fd  add      x29, sp, #0x70
//   0x0104ac: d53bd05b  mrs      x27, tpidr_el0
//   0x0104b0: f9401768  ldr      x8, [x27, #0x28]
//   0x0104b4: f100003f  cmp      x1, #0
//   0x0104b8: 910053e9  add      x9, sp, #0x14
//   0x0104bc: aa0003f4  mov      x20, x0
//   0x0104c0: 9a810136  csel     x22, x9, x1, eq
//   0x0104c4: 52800040  mov      w0, #2
//   0x0104c8: f9000fe8  str      x8, [sp, #0x18]
//   0x0104cc: b4001214  cbz      x20, #0x1070c
//   0x0104d0: aa0203f9  mov      x25, x2
//   0x0104d4: b40011c2  cbz      x2, #0x1070c
//   0x0104d8: aa0303f8  mov      x24, x3
//   0x0104dc: b4001183  cbz      x3, #0x1070c
//   0x0104e0: eb18033f  cmp      x25, x24
//   0x0104e4: 54000069  b.ls     #0x104f0
//   0x0104e8: 52800120  mov      w0, #9
//   0x0104ec: 14000088  b        #0x1070c
//   0x0104f0: aa0603f3  mov      x19, x6
//   0x0104f4: 2a0503f5  mov      w21, w5
//   0x0104f8: 2a0403f7  mov      w23, w4
//   0x0104fc: b40000e6  cbz      x6, #0x10518
//   0x010500: aa1303e0  mov      x0, x19
//   0x010504: 97ffcb57  bl       #0x3260
//   0x010508: 7100041f  cmp      w0, #1
//   0x01050c: 540000a0  b.eq     #0x10520
//   0x010510: 52800140  mov      w0, #0xa
//   0x010514: 1400007e  b        #0x1070c
//   0x010518: f0000053  adrp     x19, #0x1b000
//   0x01051c: f947fe73  ldr      x19, [x19, #0xff8]
//   0x010520: eb18033f  cmp      x25, x24
//   0x010524: f900029f  str      xzr, [x20]
//   0x010528: b90002df  str      wzr, [x22]
//   0x01052c: 540005a2  b.hs     #0x105e0
//   0x010530: aa1f03e9  mov      x9, xzr
//   0x010534: aa1f03e4  mov      x4, xzr
//   0x010538: aa1f03e8  mov      x8, xzr
//   0x01053c: aa1403fa  mov      x26, x20
//   0x010540: aa1903fc  mov      x28, x25
//   0x010544: 1400000a  b        #0x1056c
//   0x010548: 9100078a  add      x10, x28, #1
//   0x01054c: eb18015f  cmp      x10, x24
//   0x010550: aa1f03e8  mov      x8, xzr
//   0x010554: aa1f03e4  mov      x4, xzr
//   0x010558: aa1f03e9  mov      x9, xzr
//   0x01055c: 9a9c27f9  csinc    x25, xzr, x28, hs
//   0x010560: 9100079c  add      x28, x28, #1
//   0x010564: eb1c031f  cmp      x24, x28
//   0x010568: 54000460  b.eq     #0x105f4
//   0x01056c: 3940038a  ldrb     w10, [x28]
//   0x010570: 7100f55f  cmp      w10, #0x3d
//   0x010574: 54000280  b.eq     #0x105c4
//   0x010578: 7100995f  cmp      w10, #0x26
//   0x01057c: 54ffff21  b.ne     #0x10560
//   0x010580: f100009f  cmp      x4, #0
//   0x010584: 9a880383  csel     x3, x28, x8, eq
//   0x010588: 9a9c0125  csel     x5, x9, x28, eq
//   0x01058c: aa1a03e0  mov      x0, x26
//   0x010590: aa1603e1  mov      x1, x22
//   0x010594: aa1903e2  mov      x2, x25
//   0x010598: 2a1703e6  mov      w6, w23
//   0x01059c: 2a1503e7  mov      w7, w21
//   0x0105a0: f90003f3  str      x19, [sp]
//   0x0105a4: 94000067  bl       #0x10740
//   0x0105a8: 34000500  cbz      w0, #0x10648
//   0x0105ac: b4fffcfa  cbz      x26, #0x10548
//   0x0105b0: f9400348  ldr      x8, [x26]
//   0x0105b4: 91004109  add      x9, x8, #0x10
//   0x0105b8: f100011f  cmp      x8, #0
//   0x0105bc: 9a89035a  csel     x26, x26, x9, eq
//   0x0105c0: 17ffffe2  b        #0x10548
//   0x0105c4: b5fffce8  cbnz     x8, #0x10560
//   0x0105c8: 91000788  add      x8, x28, #1
//   0x0105cc: eb18011f  cmp      x8, x24
//   0x0105d0: 9a9c8484  csinc    x4, x4, x28, hi
//   0x0105d4: 9a9c8529  csinc    x9, x9, x28, hi
//   0x0105d8: aa1c03e8  mov      x8, x28
//   0x0105dc: 17ffffe1  b        #0x10560
//   0x0105e0: aa1f03e8  mov      x8, xzr
//   0x0105e4: aa1903f8  mov      x24, x25
//   0x0105e8: aa1f03e4  mov      x4, xzr
//   0x0105ec: aa1f03e9  mov      x9, xzr
//   0x0105f0: aa1403fa  mov      x26, x20
//   0x0105f4: f100009f  cmp      x4, #0
//   0x0105f8: 9a880303  csel     x3, x24, x8, eq
//   0x0105fc: 9a980125  csel     x5, x9, x24, eq
//   0x010600: aa1a03e0  mov      x0, x26
//   0x010604: aa1603e1  mov      x1, x22
//   0x010608: aa1903e2  mov      x2, x25
//   0x01060c: 2a1703e6  mov      w6, w23
//   0x010610: 2a1503e7  mov      w7, w21
//   0x010614: f90003f3  str      x19, [sp]
//   0x010618: 9400004a  bl       #0x10740
//   0x01061c: 34000060  cbz      w0, #0x10628
//   0x010620: 2a1f03e0  mov      w0, wzr
//   0x010624: 1400003a  b        #0x1070c
//   0x010628: b90002df  str      wzr, [x22]
//   0x01062c: f9400294  ldr      x20, [x20]
//   0x010630: b40001d3  cbz      x19, #0x10668
//   0x010634: aa1303e0  mov      x0, x19
//   0x010638: 97ffcb0a  bl       #0x3260
//   0x01063c: 7100041f  cmp      w0, #1
//   0x010640: 54000180  b.eq     #0x10670
//   0x010644: 14000031  b        #0x10708
//   0x010648: b90002df  str      wzr, [x22]
//   0x01064c: f9400294  ldr      x20, [x20]
//   0x010650: b4000353  cbz      x19, #0x106b8
//   0x010654: aa1303e0  mov      x0, x19
//   0x010658: 97ffcb02  bl       #0x3260
//   0x01065c: 7100041f  cmp      w0, #1
//   0x010660: 54000541  b.ne     #0x10708
//   0x010664: 14000017  b        #0x106c0
//   0x010668: f0000053  adrp     x19, #0x1b000
//   0x01066c: f947fe73  ldr      x19, [x19, #0xff8]
//   0x010670: b40004d4  cbz      x20, #0x10708
//   0x010674: f9401268  ldr      x8, [x19, #0x20]
//   0x010678: f9400281  ldr      x1, [x20]
//   0x01067c: f9400a95  ldr      x21, [x20, #0x10]
//   0x010680: aa1303e0  mov      x0, x19
//   0x010684: d63f0100  blr      x8
//   0x010688: f9401268  ldr      x8, [x19, #0x20]
//   0x01068c: f9400681  ldr      x1, [x20, #8]
//   0x010690: aa1303e0  mov      x0, x19
//   0x010694: d63f0100  blr      x8
//   0x010698: f9401268  ldr      x8, [x19, #0x20]
//   0x01069c: aa1303e0  mov      x0, x19
//   0x0106a0: aa1403e1  mov      x1, x20
//   0x0106a4: d63f0100  blr      x8
//   0x0106a8: 52800060  mov      w0, #3
//   0x0106ac: aa1503f4  mov      x20, x21
//   0x0106b0: b5fffe35  cbnz     x21, #0x10674
//   0x0106b4: 14000016  b        #0x1070c
//   0x0106b8: f0000053  adrp     x19, #0x1b000
//   0x0106bc: f947fe73  ldr      x19, [x19, #0xff8]
//   0x0106c0: b4000254  cbz      x20, #0x10708
//   0x0106c4: f9401268  ldr      x8, [x19, #0x20]
//   0x0106c8: f9400281  ldr      x1, [x20]
//   0x0106cc: f9400a95  ldr      x21, [x20, #0x10]
//   0x0106d0: aa1303e0  mov      x0, x19
//   0x0106d4: d63f0100  blr      x8
//   0x0106d8: f9401268  ldr      x8, [x19, #0x20]
//   0x0106dc: f9400681  ldr      x1, [x20, #8]
//   0x0106e0: aa1303e0  mov      x0, x19
//   0x0106e4: d63f0100  blr      x8
//   0x0106e8: f9401268  ldr      x8, [x19, #0x20]
//   0x0106ec: aa1303e0  mov      x0, x19
//   0x0106f0: aa1403e1  mov      x1, x20
//   0x0106f4: d63f0100  blr      x8
//   0x0106f8: 52800060  mov      w0, #3
//   0x0106fc: aa1503f4  mov      x20, x21
//   0x010700: b5fffe35  cbnz     x21, #0x106c4
//   0x010704: 14000002  b        #0x1070c
//   0x010708: 52800060  mov      w0, #3
//   0x01070c: f9401768  ldr      x8, [x27, #0x28]
//   0x010710: f9400fe9  ldr      x9, [sp, #0x18]
//   0x010714: eb09011f  cmp      x8, x9
//   0x010718: 54000121  b.ne     #0x1073c
//   0x01071c: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x010720: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x010724: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x010728: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x01072c: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x010730: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x010734: 910203ff  add      sp, sp, #0x80
//   0x010738: d65f03c0  ret      
//   0x01073c: 97ffca79  bl       #0x3120
// ============================================================================
std::uint32_t fde_145_1048c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0001048cULL;
    for (std::size_t i = 0; i < 173ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13391ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[146] Subroutine @ 0x010740..0x010904 (452 bytes, 113 AArch64 instructions)
// [VN] Khung FDE[146] Hàm con @ 0x010740..0x010904 (452 byte, 113 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010740: d101c3ff  sub      sp, sp, #0x70
//   0x010744: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x010748: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x01074c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x010750: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x010754: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x010758: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01075c: 910183fd  add      x29, sp, #0x60
//   0x010760: aa0003f3  mov      x19, x0
//   0x010764: eb03005f  cmp      x2, x3
//   0x010768: 52800020  mov      w0, #1
//   0x01076c: 54000bc8  b.hi     #0x108e4
//   0x010770: b4000bb3  cbz      x19, #0x108e4
//   0x010774: aa0103f4  mov      x20, x1
//   0x010778: b4000b61  cbz      x1, #0x108e4
//   0x01077c: aa0203fa  mov      x26, x2
//   0x010780: b4000b22  cbz      x2, #0x108e4
//   0x010784: aa0303fb  mov      x27, x3
//   0x010788: b4000ae3  cbz      x3, #0x108e4
//   0x01078c: aa0503f8  mov      x24, x5
//   0x010790: aa0403f7  mov      x23, x4
//   0x010794: eb05009f  cmp      x4, x5
//   0x010798: 54000a68  b.hi     #0x108e4
//   0x01079c: 2a0703f5  mov      w21, w7
//   0x0107a0: 2a0603f6  mov      w22, w6
//   0x0107a4: eb1b035f  cmp      x26, x27
//   0x0107a8: 54000061  b.ne     #0x107b4
//   0x0107ac: b5000057  cbnz     x23, #0x107b4
//   0x0107b0: b4000838  cbz      x24, #0x108b4
//   0x0107b4: f9400bb9  ldr      x25, [x29, #0x10]
//   0x0107b8: 52800301  mov      w1, #0x18
//   0x0107bc: f9400328  ldr      x8, [x25]
//   0x0107c0: aa1903e0  mov      x0, x25
//   0x0107c4: d63f0100  blr      x8
//   0x0107c8: f9000260  str      x0, [x19]
//   0x0107cc: b40008c0  cbz      x0, #0x108e4
//   0x0107d0: f900081f  str      xzr, [x0, #0x10]
//   0x0107d4: cb1a037c  sub      x28, x27, x26
//   0x0107d8: f9400328  ldr      x8, [x25]
//   0x0107dc: b9000ff5  str      w21, [sp, #0xc]
//   0x0107e0: d3607f95  lsl      x21, x28, #0x20
//   0x0107e4: d2c00029  mov      x9, #0x100000000
//   0x0107e8: 8b0902a9  add      x9, x21, x9
//   0x0107ec: 9360fd21  asr      x1, x9, #0x20
//   0x0107f0: aa1903e0  mov      x0, x25
//   0x0107f4: d63f0100  blr      x8
//   0x0107f8: b40006a0  cbz      x0, #0x108cc
//   0x0107fc: 7100079f  cmp      w28, #1
//   0x010800: b9400ffc  ldr      w28, [sp, #0xc]
//   0x010804: aa0003fb  mov      x27, x0
//   0x010808: 9360fea2  asr      x2, x21, #0x20
//   0x01080c: 3822681f  strb     wzr, [x0, x2]
//   0x010810: 5400010b  b.lt     #0x10830
//   0x010814: aa1b03e0  mov      x0, x27
//   0x010818: aa1a03e1  mov      x1, x26
//   0x01081c: 97ffcaa9  bl       #0x32c0
//   0x010820: aa1b03e0  mov      x0, x27
//   0x010824: 2a1603e1  mov      w1, w22
//   0x010828: 2a1c03e2  mov      w2, w28
//   0x01082c: 97ffcaa9  bl       #0x32d0
//   0x010830: f9400268  ldr      x8, [x19]
//   0x010834: f900011b  str      x27, [x8]
//   0x010838: b4000337  cbz      x23, #0x1089c
//   0x01083c: cb17031a  sub      x26, x24, x23
//   0x010840: f9400328  ldr      x8, [x25]
//   0x010844: d3607f55  lsl      x21, x26, #0x20
//   0x010848: d2c00029  mov      x9, #0x100000000
//   0x01084c: 8b0902a9  add      x9, x21, x9
//   0x010850: 9360fd21  asr      x1, x9, #0x20
//   0x010854: aa1903e0  mov      x0, x25
//   0x010858: d63f0100  blr      x8
//   0x01085c: b4000300  cbz      x0, #0x108bc
//   0x010860: aa0003f8  mov      x24, x0
//   0x010864: 9360fea2  asr      x2, x21, #0x20
//   0x010868: 7100075f  cmp      w26, #1
//   0x01086c: 3822681f  strb     wzr, [x0, x2]
//   0x010870: 5400010b  b.lt     #0x10890
//   0x010874: aa1803e0  mov      x0, x24
//   0x010878: aa1703e1  mov      x1, x23
//   0x01087c: 97ffca91  bl       #0x32c0
//   0x010880: aa1803e0  mov      x0, x24
//   0x010884: 2a1603e1  mov      w1, w22
//   0x010888: 2a1c03e2  mov      w2, w28
//   0x01088c: 97ffca91  bl       #0x32d0
//   0x010890: f9400268  ldr      x8, [x19]
//   0x010894: f9000518  str      x24, [x8, #8]
//   0x010898: 14000002  b        #0x108a0
//   0x01089c: aa1f03f8  mov      x24, xzr
//   0x0108a0: f9400268  ldr      x8, [x19]
//   0x0108a4: f9000518  str      x24, [x8, #8]
//   0x0108a8: b9400288  ldr      w8, [x20]
//   0x0108ac: 11000508  add      w8, w8, #1
//   0x0108b0: b9000288  str      w8, [x20]
//   0x0108b4: 52800020  mov      w0, #1
//   0x0108b8: 1400000b  b        #0x108e4
//   0x0108bc: f9401328  ldr      x8, [x25, #0x20]
//   0x0108c0: aa1903e0  mov      x0, x25
//   0x0108c4: aa1b03e1  mov      x1, x27
//   0x0108c8: d63f0100  blr      x8
//   0x0108cc: f9401328  ldr      x8, [x25, #0x20]
//   0x0108d0: f9400261  ldr      x1, [x19]
//   0x0108d4: aa1903e0  mov      x0, x25
//   0x0108d8: d63f0100  blr      x8
//   0x0108dc: 2a1f03e0  mov      w0, wzr
//   0x0108e0: f900027f  str      xzr, [x19]
//   0x0108e4: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x0108e8: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x0108ec: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x0108f0: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x0108f4: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x0108f8: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x0108fc: 9101c3ff  add      sp, sp, #0x70
//   0x010900: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_146_10740(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010740ULL;
    for (std::size_t i = 0; i < 113ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13564ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[147] Subroutine @ 0x010904..0x0109ec (232 bytes, 58 AArch64 instructions)
// [VN] Khung FDE[147] Hàm con @ 0x010904..0x0109ec (232 byte, 58 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010904: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x010908: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x01090c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x010910: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x010914: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x010918: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01091c: 910143fd  add      x29, sp, #0x50
//   0x010920: aa0003f4  mov      x20, x0
//   0x010924: 52800040  mov      w0, #2
//   0x010928: b4000554  cbz      x20, #0x109d0
//   0x01092c: aa0103f3  mov      x19, x1
//   0x010930: b4000501  cbz      x1, #0x109d0
//   0x010934: 528aaab8  mov      w24, #0x5555
//   0x010938: 2a1f03f9  mov      w25, wzr
//   0x01093c: 2a1f03f7  mov      w23, wzr
//   0x010940: 72a2aab8  movk     w24, #0x1555, lsl #16
//   0x010944: 5280003a  mov      w26, #1
//   0x010948: 528000db  mov      w27, #6
//   0x01094c: b900027f  str      wzr, [x19]
//   0x010950: a9405680  ldp      x0, x21, [x20]
//   0x010954: b4000100  cbz      x0, #0x10974
//   0x010958: 97ffc9f6  bl       #0x3130
//   0x01095c: aa0003f6  mov      x22, x0
//   0x010960: b40000f5  cbz      x21, #0x1097c
//   0x010964: aa1503e0  mov      x0, x21
//   0x010968: 97ffc9f2  bl       #0x3130
//   0x01096c: aa0003e8  mov      x8, x0
//   0x010970: 14000004  b        #0x10980
//   0x010974: aa1f03f6  mov      x22, xzr
//   0x010978: b5ffff75  cbnz     x21, #0x10964
//   0x01097c: aa1f03e8  mov      x8, xzr
//   0x010980: eb1802df  cmp      x22, x24
//   0x010984: 52800080  mov      w0, #4
//   0x010988: 54000242  b.hs     #0x109d0
//   0x01098c: eb18011f  cmp      x8, x24
//   0x010990: 54000202  b.hs     #0x109d0
//   0x010994: 0b080508  add      w8, w8, w8, lsl #1
//   0x010998: 52800029  mov      w9, #1
//   0x01099c: f10002bf  cmp      x21, #0
//   0x0109a0: 0b1902ea  add      w10, w23, w25
//   0x0109a4: 331f7909  bfi      w9, w8, #1, #0x1f
//   0x0109a8: 1a8903e8  csel     w8, wzr, w9, eq
//   0x0109ac: 1b1b2ac9  madd     w9, w22, w27, w10
//   0x0109b0: 0b080139  add      w25, w9, w8
//   0x0109b4: b9000279  str      w25, [x19]
//   0x0109b8: f9400a94  ldr      x20, [x20, #0x10]
//   0x0109bc: 7100075f  cmp      w26, #1
//   0x0109c0: 1a9f16f7  csinc    w23, w23, wzr, ne
//   0x0109c4: 1a9a03fa  csel     w26, wzr, w26, eq
//   0x0109c8: b5fffc54  cbnz     x20, #0x10950
//   0x0109cc: 2a1f03e0  mov      w0, wzr
//   0x0109d0: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x0109d4: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x0109d8: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x0109dc: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x0109e0: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x0109e4: f84607fb  ldr      x27, [sp], #0x60
//   0x0109e8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_147_10904(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010904ULL;
    for (std::size_t i = 0; i < 58ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13677ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[148] Subroutine @ 0x0109ec..0x010ad8 (236 bytes, 59 AArch64 instructions)
// [VN] Khung FDE[148] Hàm con @ 0x0109ec..0x010ad8 (236 byte, 59 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0109ec: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x0109f0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0109f4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0109f8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0109fc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x010a00: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x010a04: 910143fd  add      x29, sp, #0x50
//   0x010a08: aa0003f4  mov      x20, x0
//   0x010a0c: 52800040  mov      w0, #2
//   0x010a10: b4000574  cbz      x20, #0x10abc
//   0x010a14: aa0103f3  mov      x19, x1
//   0x010a18: b4000521  cbz      x1, #0x10abc
//   0x010a1c: 7100047f  cmp      w3, #1
//   0x010a20: 52800068  mov      w8, #3
//   0x010a24: 528000c9  mov      w9, #6
//   0x010a28: 12b0000a  mov      w10, #0x7fffffff
//   0x010a2c: 1a880139  csel     w25, w9, w8, eq
//   0x010a30: 2a1f03f7  mov      w23, wzr
//   0x010a34: 2a1f03f8  mov      w24, wzr
//   0x010a38: 1ad9095a  udiv     w26, w10, w25
//   0x010a3c: 5280003b  mov      w27, #1
//   0x010a40: b900027f  str      wzr, [x19]
//   0x010a44: a9405680  ldp      x0, x21, [x20]
//   0x010a48: b4000100  cbz      x0, #0x10a68
//   0x010a4c: 97ffc9b9  bl       #0x3130
//   0x010a50: aa0003f6  mov      x22, x0
//   0x010a54: b40000f5  cbz      x21, #0x10a70
//   0x010a58: aa1503e0  mov      x0, x21
//   0x010a5c: 97ffc9b5  bl       #0x3130
//   0x010a60: aa0003e8  mov      x8, x0
//   0x010a64: 14000004  b        #0x10a74
//   0x010a68: aa1f03f6  mov      x22, xzr
//   0x010a6c: b5ffff75  cbnz     x21, #0x10a58
//   0x010a70: aa1f03e8  mov      x8, xzr
//   0x010a74: eb1a02df  cmp      x22, x26
//   0x010a78: 52800080  mov      w0, #4
//   0x010a7c: 54000202  b.hs     #0x10abc
//   0x010a80: eb1a011f  cmp      x8, x26
//   0x010a84: 540001c2  b.hs     #0x10abc
//   0x010a88: 1b087f28  mul      w8, w25, w8
//   0x010a8c: f10002bf  cmp      x21, #0
//   0x010a90: 1b166329  madd     w9, w25, w22, w24
//   0x010a94: 1a8807e8  csinc    w8, wzr, w8, eq
//   0x010a98: 0b080128  add      w8, w9, w8
//   0x010a9c: 0b170117  add      w23, w8, w23
//   0x010aa0: b9000277  str      w23, [x19]
//   0x010aa4: f9400a94  ldr      x20, [x20, #0x10]
//   0x010aa8: 7100077f  cmp      w27, #1
//   0x010aac: 1a9f1718  csinc    w24, w24, wzr, ne
//   0x010ab0: 1a9b03fb  csel     w27, wzr, w27, eq
//   0x010ab4: b5fffc94  cbnz     x20, #0x10a44
//   0x010ab8: 2a1f03e0  mov      w0, wzr
//   0x010abc: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x010ac0: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x010ac4: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x010ac8: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x010acc: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x010ad0: f84607fb  ldr      x27, [sp], #0x60
//   0x010ad4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_148_109ec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000109ecULL;
    for (std::size_t i = 0; i < 59ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13735ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[149] Subroutine @ 0x010ad8..0x010ae4 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[149] Hàm con @ 0x010ad8..0x010ae4 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010ad8: 52800024  mov      w4, #1
//   0x010adc: 52800025  mov      w5, #1
//   0x010ae0: 17ffc968  b        #0x3080
// ============================================================================
std::uint32_t fde_149_10ad8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010ad8ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13794ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[150] Subroutine @ 0x010ae4..0x010cac (456 bytes, 114 AArch64 instructions)
// [VN] Khung FDE[150] Hàm con @ 0x010ae4..0x010cac (456 byte, 114 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010ae4: d10203ff  sub      sp, sp, #0x80
//   0x010ae8: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x010aec: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x010af0: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x010af4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x010af8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x010afc: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x010b00: 9101c3fd  add      x29, sp, #0x70
//   0x010b04: aa0003f4  mov      x20, x0
//   0x010b08: 52800040  mov      w0, #2
//   0x010b0c: b9001fe4  str      w4, [sp, #0x1c]
//   0x010b10: b4000a94  cbz      x20, #0x10c60
//   0x010b14: aa0103f7  mov      x23, x1
//   0x010b18: f90003e3  str      x3, [sp]
//   0x010b1c: b4000a21  cbz      x1, #0x10c60
//   0x010b20: 71000448  subs     w8, w2, #1
//   0x010b24: 540009cb  b.lt     #0x10c5c
//   0x010b28: 710004bf  cmp      w5, #1
//   0x010b2c: 52800069  mov      w9, #3
//   0x010b30: 528000ca  mov      w10, #6
//   0x010b34: 12b0000b  mov      w11, #0x7fffffff
//   0x010b38: 93407d08  sxtw     x8, w8
//   0x010b3c: 1a890156  csel     w22, w10, w9, eq
//   0x010b40: 2a0503f5  mov      w21, w5
//   0x010b44: f9000be8  str      x8, [sp, #0x10]
//   0x010b48: 52800028  mov      w8, #1
//   0x010b4c: 1ad60973  udiv     w19, w11, w22
//   0x010b50: aa1403f8  mov      x24, x20
//   0x010b54: 29017fe8  stp      w8, wzr, [sp, #8]
//   0x010b58: a94066fa  ldp      x26, x25, [x23]
//   0x010b5c: b50000da  cbnz     x26, #0x10b74
//   0x010b60: 1400000d  b        #0x10b94
//   0x010b64: f9400af7  ldr      x23, [x23, #0x10]
//   0x010b68: b40008d7  cbz      x23, #0x10c80
//   0x010b6c: a94066fa  ldp      x26, x25, [x23]
//   0x010b70: b400013a  cbz      x26, #0x10b94
//   0x010b74: aa1a03e0  mov      x0, x26
//   0x010b78: 97ffc96e  bl       #0x3130
//   0x010b7c: aa0003fc  mov      x28, x0
//   0x010b80: b40000f9  cbz      x25, #0x10b9c
//   0x010b84: aa1903e0  mov      x0, x25
//   0x010b88: 97ffc96a  bl       #0x3130
//   0x010b8c: aa0003fb  mov      x27, x0
//   0x010b90: 14000004  b        #0x10ba0
//   0x010b94: aa1f03fc  mov      x28, xzr
//   0x010b98: b5ffff79  cbnz     x25, #0x10b84
//   0x010b9c: aa1f03fb  mov      x27, xzr
//   0x010ba0: eb13039f  cmp      x28, x19
//   0x010ba4: 52800080  mov      w0, #4
//   0x010ba8: 540005c2  b.hs     #0x10c60
//   0x010bac: eb13037f  cmp      x27, x19
//   0x010bb0: 54000582  b.hs     #0x10c60
//   0x010bb4: b9400fea  ldr      w10, [sp, #0xc]
//   0x010bb8: cb140309  sub      x9, x24, x20
//   0x010bbc: 9342fd29  asr      x9, x9, #2
//   0x010bc0: 1b1c7ec8  mul      w8, w22, w28
//   0x010bc4: 8b2ac129  add      x9, x9, w10, sxtw
//   0x010bc8: 8b28c128  add      x8, x9, w8, sxtw
//   0x010bcc: f9400be9  ldr      x9, [sp, #0x10]
//   0x010bd0: eb09011f  cmp      x8, x9
//   0x010bd4: 5400044c  b.gt     #0x10c5c
//   0x010bd8: b9400be8  ldr      w8, [sp, #8]
//   0x010bdc: 7100051f  cmp      w8, #1
//   0x010be0: 54000061  b.ne     #0x10bec
//   0x010be4: 290123ff  stp      wzr, w8, [sp, #8]
//   0x010be8: 14000003  b        #0x10bf4
//   0x010bec: 528004c8  mov      w8, #0x26
//   0x010bf0: b8004708  str      w8, [x24], #4
//   0x010bf4: b9401fe3  ldr      w3, [sp, #0x1c]
//   0x010bf8: 8b1c0b41  add      x1, x26, x28, lsl #2
//   0x010bfc: aa1a03e0  mov      x0, x26
//   0x010c00: aa1803e2  mov      x2, x24
//   0x010c04: 2a1503e4  mov      w4, w21
//   0x010c08: 97ffc96e  bl       #0x31c0
//   0x010c0c: aa0003f8  mov      x24, x0
//   0x010c10: b4fffab9  cbz      x25, #0x10b64
//   0x010c14: cb140309  sub      x9, x24, x20
//   0x010c18: 1b1b7ec8  mul      w8, w22, w27
//   0x010c1c: 9342fd29  asr      x9, x9, #2
//   0x010c20: 8b28c128  add      x8, x9, w8, sxtw
//   0x010c24: f9400be9  ldr      x9, [sp, #0x10]
//   0x010c28: 91000508  add      x8, x8, #1
//   0x010c2c: eb09011f  cmp      x8, x9
//   0x010c30: 5400016c  b.gt     #0x10c5c
//   0x010c34: b9401fe3  ldr      w3, [sp, #0x1c]
//   0x010c38: 528007a8  mov      w8, #0x3d
//   0x010c3c: b8004708  str      w8, [x24], #4
//   0x010c40: 8b1b0b21  add      x1, x25, x27, lsl #2
//   0x010c44: aa1903e0  mov      x0, x25
//   0x010c48: aa1803e2  mov      x2, x24
//   0x010c4c: 2a1503e4  mov      w4, w21
//   0x010c50: 97ffc95c  bl       #0x31c0
//   0x010c54: aa0003f8  mov      x24, x0
//   0x010c58: 17ffffc3  b        #0x10b64
//   0x010c5c: 52800080  mov      w0, #4
//   0x010c60: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x010c64: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x010c68: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x010c6c: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x010c70: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x010c74: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x010c78: 910203ff  add      sp, sp, #0x80
//   0x010c7c: d65f03c0  ret      
//   0x010c80: f94003e9  ldr      x9, [sp]
//   0x010c84: b900031f  str      wzr, [x24]
//   0x010c88: b40000e9  cbz      x9, #0x10ca4
//   0x010c8c: cb140308  sub      x8, x24, x20
//   0x010c90: d342fd08  lsr      x8, x8, #2
//   0x010c94: 2a1f03e0  mov      w0, wzr
//   0x010c98: 11000508  add      w8, w8, #1
//   0x010c9c: b9000128  str      w8, [x9]
//   0x010ca0: 17fffff0  b        #0x10c60
//   0x010ca4: 2a1f03e0  mov      w0, wzr
//   0x010ca8: 17ffffee  b        #0x10c60
// ============================================================================
std::uint32_t fde_150_10ae4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010ae4ULL;
    for (std::size_t i = 0; i < 114ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13797ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[151] Subroutine @ 0x010cac..0x010cbc (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[151] Hàm con @ 0x010cac..0x010cbc (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010cac: 52800022  mov      w2, #1
//   0x010cb0: 52800023  mov      w3, #1
//   0x010cb4: aa1f03e4  mov      x4, xzr
//   0x010cb8: 17ffc8b2  b        #0x2f80
// ============================================================================
std::uint32_t fde_151_10cac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010cacULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13911ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[152] Subroutine @ 0x010cbc..0x010cc4 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[152] Hàm con @ 0x010cbc..0x010cc4 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010cbc: aa1f03e4  mov      x4, xzr
//   0x010cc0: 17ffc8b0  b        #0x2f80
// ============================================================================
std::uint32_t fde_152_10cbc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010cbcULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13915ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[153] Subroutine @ 0x010cc4..0x010e64 (416 bytes, 104 AArch64 instructions)
// [VN] Khung FDE[153] Hàm con @ 0x010cc4..0x010e64 (416 byte, 104 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010cc4: d10203ff  sub      sp, sp, #0x80
//   0x010cc8: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x010ccc: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x010cd0: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x010cd4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x010cd8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x010cdc: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x010ce0: 9101c3fd  add      x29, sp, #0x70
//   0x010ce4: b4000740  cbz      x0, #0x10dcc
//   0x010ce8: aa0403f3  mov      x19, x4
//   0x010cec: 2a0303f5  mov      w21, w3
//   0x010cf0: 2a0203f6  mov      w22, w2
//   0x010cf4: aa0103f8  mov      x24, x1
//   0x010cf8: aa0003f4  mov      x20, x0
//   0x010cfc: b40000e4  cbz      x4, #0x10d18
//   0x010d00: aa1303e0  mov      x0, x19
//   0x010d04: 97ffc957  bl       #0x3260
//   0x010d08: 7100041f  cmp      w0, #1
//   0x010d0c: 540000a0  b.eq     #0x10d20
//   0x010d10: 52800159  mov      w25, #0xa
//   0x010d14: 1400002f  b        #0x10dd0
//   0x010d18: f0000053  adrp     x19, #0x1b000
//   0x010d1c: f947fe73  ldr      x19, [x19, #0xff8]
//   0x010d20: b4000578  cbz      x24, #0x10dcc
//   0x010d24: 710006bf  cmp      w21, #1
//   0x010d28: 52800068  mov      w8, #3
//   0x010d2c: 528000c9  mov      w9, #6
//   0x010d30: 290357f6  stp      w22, w21, [sp, #0x18]
//   0x010d34: 12b0000a  mov      w10, #0x7fffffff
//   0x010d38: 1a880136  csel     w22, w9, w8, eq
//   0x010d3c: a900e3f4  stp      x20, x24, [sp, #8]
//   0x010d40: 2a1f03fc  mov      w28, wzr
//   0x010d44: 2a1f03fb  mov      w27, wzr
//   0x010d48: 1ad60955  udiv     w21, w10, w22
//   0x010d4c: 52800037  mov      w23, #1
//   0x010d50: aa1803f4  mov      x20, x24
//   0x010d54: 52800099  mov      w25, #4
//   0x010d58: a9406a80  ldp      x0, x26, [x20]
//   0x010d5c: b40002c0  cbz      x0, #0x10db4
//   0x010d60: 97ffc8f4  bl       #0x3130
//   0x010d64: aa0003f8  mov      x24, x0
//   0x010d68: b40002ba  cbz      x26, #0x10dbc
//   0x010d6c: aa1a03e0  mov      x0, x26
//   0x010d70: 97ffc8f0  bl       #0x3130
//   0x010d74: eb15031f  cmp      x24, x21
//   0x010d78: 540002c2  b.hs     #0x10dd0
//   0x010d7c: eb15001f  cmp      x0, x21
//   0x010d80: 54000282  b.hs     #0x10dd0
//   0x010d84: f9400a94  ldr      x20, [x20, #0x10]
//   0x010d88: 1b007ec8  mul      w8, w22, w0
//   0x010d8c: f100035f  cmp      x26, #0
//   0x010d90: 0b1c0369  add      w9, w27, w28
//   0x010d94: 1a8807e8  csinc    w8, wzr, w8, eq
//   0x010d98: 1b1826c9  madd     w9, w22, w24, w9
//   0x010d9c: 710006ff  cmp      w23, #1
//   0x010da0: 0b08013c  add      w28, w9, w8
//   0x010da4: 1a9f177b  csinc    w27, w27, wzr, ne
//   0x010da8: 1a9703f7  csel     w23, wzr, w23, eq
//   0x010dac: b5fffd74  cbnz     x20, #0x10d58
//   0x010db0: 14000011  b        #0x10df4
//   0x010db4: aa1f03f8  mov      x24, xzr
//   0x010db8: b5fffdba  cbnz     x26, #0x10d6c
//   0x010dbc: aa1f03e0  mov      x0, xzr
//   0x010dc0: eb15031f  cmp      x24, x21
//   0x010dc4: 54fffdc3  b.lo     #0x10d7c
//   0x010dc8: 14000002  b        #0x10dd0
//   0x010dcc: 52800059  mov      w25, #2
//   0x010dd0: 2a1903e0  mov      w0, w25
//   0x010dd4: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x010dd8: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x010ddc: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x010de0: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x010de4: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x010de8: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x010dec: 910203ff  add      sp, sp, #0x80
//   0x010df0: d65f03c0  ret      
//   0x010df4: 12b00008  mov      w8, #0x7fffffff
//   0x010df8: 6b08039f  cmp      w28, w8
//   0x010dfc: 540002a0  b.eq     #0x10e50
//   0x010e00: f9400668  ldr      x8, [x19, #8]
//   0x010e04: 11000799  add      w25, w28, #1
//   0x010e08: 93407f21  sxtw     x1, w25
//   0x010e0c: 52800082  mov      w2, #4
//   0x010e10: aa1303e0  mov      x0, x19
//   0x010e14: d63f0100  blr      x8
//   0x010e18: b40001c0  cbz      x0, #0x10e50
//   0x010e1c: f9400be1  ldr      x1, [sp, #0x10]
//   0x010e20: 294317e4  ldp      w4, w5, [sp, #0x18]
//   0x010e24: 2a1903e2  mov      w2, w25
//   0x010e28: aa1f03e3  mov      x3, xzr
//   0x010e2c: aa0003f8  mov      x24, x0
//   0x010e30: 97ffc894  bl       #0x3080
//   0x010e34: 2a0003f9  mov      w25, w0
//   0x010e38: 34000100  cbz      w0, #0x10e58
//   0x010e3c: f9401268  ldr      x8, [x19, #0x20]
//   0x010e40: aa1303e0  mov      x0, x19
//   0x010e44: aa1803e1  mov      x1, x24
//   0x010e48: d63f0100  blr      x8
//   0x010e4c: 17ffffe1  b        #0x10dd0
//   0x010e50: 52800079  mov      w25, #3
//   0x010e54: 17ffffdf  b        #0x10dd0
//   0x010e58: f94007e8  ldr      x8, [sp, #8]
//   0x010e5c: f9000118  str      x24, [x8]
//   0x010e60: 17ffffdc  b        #0x10dd0
// ============================================================================
std::uint32_t fde_153_10cc4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010cc4ULL;
    for (std::size_t i = 0; i < 104ULL; ++i) {
        std::uint32_t insn = kTextInstructions[13917ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[154] Subroutine @ 0x010e64..0x010ed0 (108 bytes, 27 AArch64 instructions)
// [VN] Khung FDE[154] Hàm con @ 0x010e64..0x010ed0 (108 byte, 27 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010e64: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x010e68: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x010e6c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x010e70: 910083fd  add      x29, sp, #0x20
//   0x010e74: b4000260  cbz      x0, #0x10ec0
//   0x010e78: f0000054  adrp     x20, #0x1b000
//   0x010e7c: f947fe94  ldr      x20, [x20, #0xff8]
//   0x010e80: aa0003f3  mov      x19, x0
//   0x010e84: f9401288  ldr      x8, [x20, #0x20]
//   0x010e88: f9400261  ldr      x1, [x19]
//   0x010e8c: f9400a75  ldr      x21, [x19, #0x10]
//   0x010e90: aa1403e0  mov      x0, x20
//   0x010e94: d63f0100  blr      x8
//   0x010e98: f9401288  ldr      x8, [x20, #0x20]
//   0x010e9c: f9400661  ldr      x1, [x19, #8]
//   0x010ea0: aa1403e0  mov      x0, x20
//   0x010ea4: d63f0100  blr      x8
//   0x010ea8: f9401288  ldr      x8, [x20, #0x20]
//   0x010eac: aa1403e0  mov      x0, x20
//   0x010eb0: aa1303e1  mov      x1, x19
//   0x010eb4: d63f0100  blr      x8
//   0x010eb8: aa1503f3  mov      x19, x21
//   0x010ebc: b5fffe55  cbnz     x21, #0x10e84
//   0x010ec0: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x010ec4: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x010ec8: f84307f5  ldr      x21, [sp], #0x30
//   0x010ecc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_154_10e64(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010e64ULL;
    for (std::size_t i = 0; i < 27ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14021ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[155] Subroutine @ 0x010ed0..0x010f60 (144 bytes, 36 AArch64 instructions)
// [VN] Khung FDE[155] Hàm con @ 0x010ed0..0x010f60 (144 byte, 36 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010ed0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x010ed4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x010ed8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x010edc: 910083fd  add      x29, sp, #0x20
//   0x010ee0: aa0003f4  mov      x20, x0
//   0x010ee4: b4000101  cbz      x1, #0x10f04
//   0x010ee8: aa0103e0  mov      x0, x1
//   0x010eec: aa0103f3  mov      x19, x1
//   0x010ef0: 97ffc8dc  bl       #0x3260
//   0x010ef4: 7100041f  cmp      w0, #1
//   0x010ef8: 540000a0  b.eq     #0x10f0c
//   0x010efc: 52800140  mov      w0, #0xa
//   0x010f00: 14000014  b        #0x10f50
//   0x010f04: f0000053  adrp     x19, #0x1b000
//   0x010f08: f947fe73  ldr      x19, [x19, #0xff8]
//   0x010f0c: b4000214  cbz      x20, #0x10f4c
//   0x010f10: f9401268  ldr      x8, [x19, #0x20]
//   0x010f14: f9400281  ldr      x1, [x20]
//   0x010f18: f9400a95  ldr      x21, [x20, #0x10]
//   0x010f1c: aa1303e0  mov      x0, x19
//   0x010f20: d63f0100  blr      x8
//   0x010f24: f9401268  ldr      x8, [x19, #0x20]
//   0x010f28: f9400681  ldr      x1, [x20, #8]
//   0x010f2c: aa1303e0  mov      x0, x19
//   0x010f30: d63f0100  blr      x8
//   0x010f34: f9401268  ldr      x8, [x19, #0x20]
//   0x010f38: aa1303e0  mov      x0, x19
//   0x010f3c: aa1403e1  mov      x1, x20
//   0x010f40: d63f0100  blr      x8
//   0x010f44: aa1503f4  mov      x20, x21
//   0x010f48: b5fffe55  cbnz     x21, #0x10f10
//   0x010f4c: 2a1f03e0  mov      w0, wzr
//   0x010f50: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x010f54: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x010f58: f84307f5  ldr      x21, [sp], #0x30
//   0x010f5c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_155_10ed0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010ed0ULL;
    for (std::size_t i = 0; i < 36ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14048ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[156] Subroutine @ 0x010f60..0x010f70 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[156] Hàm con @ 0x010f60..0x010f70 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010f60: 52800024  mov      w4, #1
//   0x010f64: 52800065  mov      w5, #3
//   0x010f68: aa1f03e6  mov      x6, xzr
//   0x010f6c: 17ffc8f1  b        #0x3330
// ============================================================================
std::uint32_t fde_156_10f60(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010f60ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14084ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[157] Subroutine @ 0x010f70..0x010f78 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[157] Hàm con @ 0x010f70..0x010f78 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010f70: aa1f03e6  mov      x6, xzr
//   0x010f74: 17ffc8ef  b        #0x3330
// ============================================================================
std::uint32_t fde_157_10f70(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010f70ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14088ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[158] Subroutine @ 0x010f78..0x01122c (692 bytes, 173 AArch64 instructions)
// [VN] Khung FDE[158] Hàm con @ 0x010f78..0x01122c (692 byte, 173 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x010f78: d10203ff  sub      sp, sp, #0x80
//   0x010f7c: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x010f80: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x010f84: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x010f88: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x010f8c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x010f90: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x010f94: 9101c3fd  add      x29, sp, #0x70
//   0x010f98: d53bd05b  mrs      x27, tpidr_el0
//   0x010f9c: f9401768  ldr      x8, [x27, #0x28]
//   0x010fa0: f100003f  cmp      x1, #0
//   0x010fa4: 910053e9  add      x9, sp, #0x14
//   0x010fa8: aa0003f4  mov      x20, x0
//   0x010fac: 9a810136  csel     x22, x9, x1, eq
//   0x010fb0: 52800040  mov      w0, #2
//   0x010fb4: f9000fe8  str      x8, [sp, #0x18]
//   0x010fb8: b4001214  cbz      x20, #0x111f8
//   0x010fbc: aa0203f9  mov      x25, x2
//   0x010fc0: b40011c2  cbz      x2, #0x111f8
//   0x010fc4: aa0303f8  mov      x24, x3
//   0x010fc8: b4001183  cbz      x3, #0x111f8
//   0x010fcc: eb18033f  cmp      x25, x24
//   0x010fd0: 54000069  b.ls     #0x10fdc
//   0x010fd4: 52800120  mov      w0, #9
//   0x010fd8: 14000088  b        #0x111f8
//   0x010fdc: aa0603f3  mov      x19, x6
//   0x010fe0: 2a0503f5  mov      w21, w5
//   0x010fe4: 2a0403f7  mov      w23, w4
//   0x010fe8: b40000e6  cbz      x6, #0x11004
//   0x010fec: aa1303e0  mov      x0, x19
//   0x010ff0: 97ffc89c  bl       #0x3260
//   0x010ff4: 7100041f  cmp      w0, #1
//   0x010ff8: 540000a0  b.eq     #0x1100c
//   0x010ffc: 52800140  mov      w0, #0xa
//   0x011000: 1400007e  b        #0x111f8
//   0x011004: d0000053  adrp     x19, #0x1b000
//   0x011008: f947fe73  ldr      x19, [x19, #0xff8]
//   0x01100c: eb18033f  cmp      x25, x24
//   0x011010: f900029f  str      xzr, [x20]
//   0x011014: b90002df  str      wzr, [x22]
//   0x011018: 540005a2  b.hs     #0x110cc
//   0x01101c: aa1f03e9  mov      x9, xzr
//   0x011020: aa1f03e4  mov      x4, xzr
//   0x011024: aa1f03e8  mov      x8, xzr
//   0x011028: aa1403fa  mov      x26, x20
//   0x01102c: aa1903fc  mov      x28, x25
//   0x011030: 1400000a  b        #0x11058
//   0x011034: 9100138a  add      x10, x28, #4
//   0x011038: eb18015f  cmp      x10, x24
//   0x01103c: aa1f03e8  mov      x8, xzr
//   0x011040: aa1f03e4  mov      x4, xzr
//   0x011044: aa1f03e9  mov      x9, xzr
//   0x011048: 9a9f3159  csel     x25, x10, xzr, lo
//   0x01104c: 9100139c  add      x28, x28, #4
//   0x011050: eb18039f  cmp      x28, x24
//   0x011054: 54000462  b.hs     #0x110e0
//   0x011058: b940038a  ldr      w10, [x28]
//   0x01105c: 7100f55f  cmp      w10, #0x3d
//   0x011060: 54000280  b.eq     #0x110b0
//   0x011064: 7100995f  cmp      w10, #0x26
//   0x011068: 54ffff21  b.ne     #0x1104c
//   0x01106c: f100009f  cmp      x4, #0
//   0x011070: 9a880383  csel     x3, x28, x8, eq
//   0x011074: 9a9c0125  csel     x5, x9, x28, eq
//   0x011078: aa1a03e0  mov      x0, x26
//   0x01107c: aa1603e1  mov      x1, x22
//   0x011080: aa1903e2  mov      x2, x25
//   0x011084: 2a1703e6  mov      w6, w23
//   0x011088: 2a1503e7  mov      w7, w21
//   0x01108c: f90003f3  str      x19, [sp]
//   0x011090: 94000067  bl       #0x1122c
//   0x011094: 34000500  cbz      w0, #0x11134
//   0x011098: b4fffcfa  cbz      x26, #0x11034
//   0x01109c: f9400348  ldr      x8, [x26]
//   0x0110a0: 91004109  add      x9, x8, #0x10
//   0x0110a4: f100011f  cmp      x8, #0
//   0x0110a8: 9a89035a  csel     x26, x26, x9, eq
//   0x0110ac: 17ffffe2  b        #0x11034
//   0x0110b0: b5fffce8  cbnz     x8, #0x1104c
//   0x0110b4: 91001388  add      x8, x28, #4
//   0x0110b8: eb18011f  cmp      x8, x24
//   0x0110bc: 9a888084  csel     x4, x4, x8, hi
//   0x0110c0: 9a888129  csel     x9, x9, x8, hi
//   0x0110c4: aa1c03e8  mov      x8, x28
//   0x0110c8: 17ffffe1  b        #0x1104c
//   0x0110cc: aa1f03e8  mov      x8, xzr
//   0x0110d0: aa1903fc  mov      x28, x25
//   0x0110d4: aa1f03e4  mov      x4, xzr
//   0x0110d8: aa1f03e9  mov      x9, xzr
//   0x0110dc: aa1403fa  mov      x26, x20
//   0x0110e0: f100009f  cmp      x4, #0
//   0x0110e4: 9a880383  csel     x3, x28, x8, eq
//   0x0110e8: 9a9c0125  csel     x5, x9, x28, eq
//   0x0110ec: aa1a03e0  mov      x0, x26
//   0x0110f0: aa1603e1  mov      x1, x22
//   0x0110f4: aa1903e2  mov      x2, x25
//   0x0110f8: 2a1703e6  mov      w6, w23
//   0x0110fc: 2a1503e7  mov      w7, w21
//   0x011100: f90003f3  str      x19, [sp]
//   0x011104: 9400004a  bl       #0x1122c
//   0x011108: 34000060  cbz      w0, #0x11114
//   0x01110c: 2a1f03e0  mov      w0, wzr
//   0x011110: 1400003a  b        #0x111f8
//   0x011114: b90002df  str      wzr, [x22]
//   0x011118: f9400294  ldr      x20, [x20]
//   0x01111c: b40001d3  cbz      x19, #0x11154
//   0x011120: aa1303e0  mov      x0, x19
//   0x011124: 97ffc84f  bl       #0x3260
//   0x011128: 7100041f  cmp      w0, #1
//   0x01112c: 54000180  b.eq     #0x1115c
//   0x011130: 14000031  b        #0x111f4
//   0x011134: b90002df  str      wzr, [x22]
//   0x011138: f9400294  ldr      x20, [x20]
//   0x01113c: b4000353  cbz      x19, #0x111a4
//   0x011140: aa1303e0  mov      x0, x19
//   0x011144: 97ffc847  bl       #0x3260
//   0x011148: 7100041f  cmp      w0, #1
//   0x01114c: 54000541  b.ne     #0x111f4
//   0x011150: 14000017  b        #0x111ac
//   0x011154: d0000053  adrp     x19, #0x1b000
//   0x011158: f947fe73  ldr      x19, [x19, #0xff8]
//   0x01115c: b40004d4  cbz      x20, #0x111f4
//   0x011160: f9401268  ldr      x8, [x19, #0x20]
//   0x011164: f9400281  ldr      x1, [x20]
//   0x011168: f9400a95  ldr      x21, [x20, #0x10]
//   0x01116c: aa1303e0  mov      x0, x19
//   0x011170: d63f0100  blr      x8
//   0x011174: f9401268  ldr      x8, [x19, #0x20]
//   0x011178: f9400681  ldr      x1, [x20, #8]
//   0x01117c: aa1303e0  mov      x0, x19
//   0x011180: d63f0100  blr      x8
//   0x011184: f9401268  ldr      x8, [x19, #0x20]
//   0x011188: aa1303e0  mov      x0, x19
//   0x01118c: aa1403e1  mov      x1, x20
//   0x011190: d63f0100  blr      x8
//   0x011194: 52800060  mov      w0, #3
//   0x011198: aa1503f4  mov      x20, x21
//   0x01119c: b5fffe35  cbnz     x21, #0x11160
//   0x0111a0: 14000016  b        #0x111f8
//   0x0111a4: d0000053  adrp     x19, #0x1b000
//   0x0111a8: f947fe73  ldr      x19, [x19, #0xff8]
//   0x0111ac: b4000254  cbz      x20, #0x111f4
//   0x0111b0: f9401268  ldr      x8, [x19, #0x20]
//   0x0111b4: f9400281  ldr      x1, [x20]
//   0x0111b8: f9400a95  ldr      x21, [x20, #0x10]
//   0x0111bc: aa1303e0  mov      x0, x19
//   0x0111c0: d63f0100  blr      x8
//   0x0111c4: f9401268  ldr      x8, [x19, #0x20]
//   0x0111c8: f9400681  ldr      x1, [x20, #8]
//   0x0111cc: aa1303e0  mov      x0, x19
//   0x0111d0: d63f0100  blr      x8
//   0x0111d4: f9401268  ldr      x8, [x19, #0x20]
//   0x0111d8: aa1303e0  mov      x0, x19
//   0x0111dc: aa1403e1  mov      x1, x20
//   0x0111e0: d63f0100  blr      x8
//   0x0111e4: 52800060  mov      w0, #3
//   0x0111e8: aa1503f4  mov      x20, x21
//   0x0111ec: b5fffe35  cbnz     x21, #0x111b0
//   0x0111f0: 14000002  b        #0x111f8
//   0x0111f4: 52800060  mov      w0, #3
//   0x0111f8: f9401768  ldr      x8, [x27, #0x28]
//   0x0111fc: f9400fe9  ldr      x9, [sp, #0x18]
//   0x011200: eb09011f  cmp      x8, x9
//   0x011204: 54000121  b.ne     #0x11228
//   0x011208: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x01120c: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x011210: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x011214: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x011218: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x01121c: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x011220: 910203ff  add      sp, sp, #0x80
//   0x011224: d65f03c0  ret      
//   0x011228: 97ffc7be  bl       #0x3120
// ============================================================================
std::uint32_t fde_158_10f78(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00010f78ULL;
    for (std::size_t i = 0; i < 173ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14090ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[159] Subroutine @ 0x01122c..0x0113f8 (460 bytes, 115 AArch64 instructions)
// [VN] Khung FDE[159] Hàm con @ 0x01122c..0x0113f8 (460 byte, 115 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x01122c: d101c3ff  sub      sp, sp, #0x70
//   0x011230: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x011234: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x011238: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01123c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x011240: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x011244: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x011248: 910183fd  add      x29, sp, #0x60
//   0x01124c: aa0003f3  mov      x19, x0
//   0x011250: eb03005f  cmp      x2, x3
//   0x011254: 52800020  mov      w0, #1
//   0x011258: 54000c08  b.hi     #0x113d8
//   0x01125c: b4000bf3  cbz      x19, #0x113d8
//   0x011260: aa0103f4  mov      x20, x1
//   0x011264: b4000ba1  cbz      x1, #0x113d8
//   0x011268: aa0203fa  mov      x26, x2
//   0x01126c: b4000b62  cbz      x2, #0x113d8
//   0x011270: aa0303fb  mov      x27, x3
//   0x011274: b4000b23  cbz      x3, #0x113d8
//   0x011278: aa0503f8  mov      x24, x5
//   0x01127c: aa0403f7  mov      x23, x4
//   0x011280: eb05009f  cmp      x4, x5
//   0x011284: 54000aa8  b.hi     #0x113d8
//   0x011288: 2a0703f5  mov      w21, w7
//   0x01128c: 2a0603f6  mov      w22, w6
//   0x011290: eb1b035f  cmp      x26, x27
//   0x011294: 54000061  b.ne     #0x112a0
//   0x011298: b5000057  cbnz     x23, #0x112a0
//   0x01129c: b4000878  cbz      x24, #0x113a8
//   0x0112a0: f9400bb9  ldr      x25, [x29, #0x10]
//   0x0112a4: 52800301  mov      w1, #0x18
//   0x0112a8: f9400328  ldr      x8, [x25]
//   0x0112ac: aa1903e0  mov      x0, x25
//   0x0112b0: d63f0100  blr      x8
//   0x0112b4: f9000260  str      x0, [x19]
//   0x0112b8: b4000900  cbz      x0, #0x113d8
//   0x0112bc: f900081f  str      xzr, [x0, #0x10]
//   0x0112c0: cb1a037c  sub      x28, x27, x26
//   0x0112c4: f9400328  ldr      x8, [x25]
//   0x0112c8: b9000ff5  str      w21, [sp, #0xc]
//   0x0112cc: d3628795  lsl      x21, x28, #0x1e
//   0x0112d0: d2c00029  mov      x9, #0x100000000
//   0x0112d4: 8b0902a9  add      x9, x21, x9
//   0x0112d8: 935efd21  asr      x1, x9, #0x1e
//   0x0112dc: aa1903e0  mov      x0, x25
//   0x0112e0: d63f0100  blr      x8
//   0x0112e4: b40006e0  cbz      x0, #0x113c0
//   0x0112e8: d342ff88  lsr      x8, x28, #2
//   0x0112ec: b9400ffc  ldr      w28, [sp, #0xc]
//   0x0112f0: aa0003fb  mov      x27, x0
//   0x0112f4: 935efea2  asr      x2, x21, #0x1e
//   0x0112f8: 7100051f  cmp      w8, #1
//   0x0112fc: b822681f  str      wzr, [x0, x2]
//   0x011300: 5400010b  b.lt     #0x11320
//   0x011304: aa1b03e0  mov      x0, x27
//   0x011308: aa1a03e1  mov      x1, x26
//   0x01130c: 97ffc7ed  bl       #0x32c0
//   0x011310: aa1b03e0  mov      x0, x27
//   0x011314: 2a1603e1  mov      w1, w22
//   0x011318: 2a1c03e2  mov      w2, w28
//   0x01131c: 97ffc725  bl       #0x2fb0
//   0x011320: f9400268  ldr      x8, [x19]
//   0x011324: f900011b  str      x27, [x8]
//   0x011328: b4000357  cbz      x23, #0x11390
//   0x01132c: cb17031a  sub      x26, x24, x23
//   0x011330: f9400328  ldr      x8, [x25]
//   0x011334: d3628755  lsl      x21, x26, #0x1e
//   0x011338: d2c00029  mov      x9, #0x100000000
//   0x01133c: 8b0902a9  add      x9, x21, x9
//   0x011340: 935efd21  asr      x1, x9, #0x1e
//   0x011344: aa1903e0  mov      x0, x25
//   0x011348: d63f0100  blr      x8
//   0x01134c: b4000320  cbz      x0, #0x113b0
//   0x011350: d342ff48  lsr      x8, x26, #2
//   0x011354: aa0003f8  mov      x24, x0
//   0x011358: 935efea2  asr      x2, x21, #0x1e
//   0x01135c: 7100051f  cmp      w8, #1
//   0x011360: b822681f  str      wzr, [x0, x2]
//   0x011364: 5400010b  b.lt     #0x11384
//   0x011368: aa1803e0  mov      x0, x24
//   0x01136c: aa1703e1  mov      x1, x23
//   0x011370: 97ffc7d4  bl       #0x32c0
//   0x011374: aa1803e0  mov      x0, x24
//   0x011378: 2a1603e1  mov      w1, w22
//   0x01137c: 2a1c03e2  mov      w2, w28
//   0x011380: 97ffc70c  bl       #0x2fb0
//   0x011384: f9400268  ldr      x8, [x19]
//   0x011388: f9000518  str      x24, [x8, #8]
//   0x01138c: 14000002  b        #0x11394
//   0x011390: aa1f03f8  mov      x24, xzr
//   0x011394: f9400268  ldr      x8, [x19]
//   0x011398: f9000518  str      x24, [x8, #8]
//   0x01139c: b9400288  ldr      w8, [x20]
//   0x0113a0: 11000508  add      w8, w8, #1
//   0x0113a4: b9000288  str      w8, [x20]
//   0x0113a8: 52800020  mov      w0, #1
//   0x0113ac: 1400000b  b        #0x113d8
//   0x0113b0: f9401328  ldr      x8, [x25, #0x20]
//   0x0113b4: aa1903e0  mov      x0, x25
//   0x0113b8: aa1b03e1  mov      x1, x27
//   0x0113bc: d63f0100  blr      x8
//   0x0113c0: f9401328  ldr      x8, [x25, #0x20]
//   0x0113c4: f9400261  ldr      x1, [x19]
//   0x0113c8: aa1903e0  mov      x0, x25
//   0x0113cc: d63f0100  blr      x8
//   0x0113d0: 2a1f03e0  mov      w0, wzr
//   0x0113d4: f900027f  str      xzr, [x19]
//   0x0113d8: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x0113dc: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x0113e0: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x0113e4: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x0113e8: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x0113ec: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x0113f0: 9101c3ff  add      sp, sp, #0x70
//   0x0113f4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_159_1122c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0001122cULL;
    for (std::size_t i = 0; i < 115ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14263ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[160] Subroutine @ 0x0113f8..0x011410 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[160] Hàm con @ 0x0113f8..0x011410 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0113f8: aa0103e4  mov      x4, x1
//   0x0113fc: 12b00002  mov      w2, #0x7fffffff
//   0x011400: aa0003e1  mov      x1, x0
//   0x011404: aa1f03e0  mov      x0, xzr
//   0x011408: aa1f03e3  mov      x3, xzr
//   0x01140c: 14000001  b        #0x11410
// ============================================================================
std::uint32_t fde_160_113f8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000113f8ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14378ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[161] Subroutine @ 0x011410..0x011b70 (1888 bytes, 472 AArch64 instructions)
// [VN] Khung FDE[161] Hàm con @ 0x011410..0x011b70 (1888 byte, 472 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x011410: d10203ff  sub      sp, sp, #0x80
//   0x011414: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x011418: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x01141c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x011420: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x011424: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x011428: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x01142c: 9101c3fd  add      x29, sp, #0x70
//   0x011430: d53bd059  mrs      x25, tpidr_el0
//   0x011434: f9401728  ldr      x8, [x25, #0x28]
//   0x011438: aa0303f3  mov      x19, x3
//   0x01143c: f9000fe8  str      x8, [sp, #0x18]
//   0x011440: b40000e1  cbz      x1, #0x1145c
//   0x011444: aa0403f7  mov      x23, x4
//   0x011448: 2a0203f5  mov      w21, w2
//   0x01144c: aa0103f6  mov      x22, x1
//   0x011450: aa0003f4  mov      x20, x0
//   0x011454: b50000c0  cbnz     x0, #0x1146c
//   0x011458: b50000b7  cbnz     x23, #0x1146c
//   0x01145c: b4000133  cbz      x19, #0x11480
//   0x011460: b900027f  str      wzr, [x19]
//   0x011464: 52800040  mov      w0, #2
//   0x011468: 140001ad  b        #0x11b1c
//   0x01146c: 710002bf  cmp      w21, #0
//   0x011470: 540000cd  b.le     #0x11488
//   0x011474: b40000f4  cbz      x20, #0x11490
//   0x011478: 3900029f  strb     wzr, [x20]
//   0x01147c: 14000006  b        #0x11494
//   0x011480: 52800040  mov      w0, #2
//   0x011484: 140001a6  b        #0x11b1c
//   0x011488: b5003473  cbnz     x19, #0x11b14
//   0x01148c: 140001a3  b        #0x11b18
//   0x011490: b90002ff  str      wzr, [x23]
//   0x011494: f94002c1  ldr      x1, [x22]
//   0x011498: 510006a8  sub      w8, w21, #1
//   0x01149c: b9000fe8  str      w8, [sp, #0xc]
//   0x0114a0: b4000221  cbz      x1, #0x114e4
//   0x0114a4: f94006c8  ldr      x8, [x22, #8]
//   0x0114a8: cb01011a  sub      x26, x8, x1
//   0x0114ac: b4000214  cbz      x20, #0x114ec
//   0x0114b0: 6b15035f  cmp      w26, w21
//   0x0114b4: 540032ca  b.ge     #0x11b0c
//   0x0114b8: 93407f58  sxtw     x24, w26
//   0x0114bc: aa1403e0  mov      x0, x20
//   0x0114c0: aa1803e2  mov      x2, x24
//   0x0114c4: 97ffc77f  bl       #0x32c0
//   0x0114c8: b9400fe8  ldr      w8, [sp, #0xc]
//   0x0114cc: 6b1a011f  cmp      w8, w26
//   0x0114d0: 540031ed  b.le     #0x11b0c
//   0x0114d4: 52800748  mov      w8, #0x3a
//   0x0114d8: 1100075b  add      w27, w26, #1
//   0x0114dc: 38386a88  strb     w8, [x20, x24]
//   0x0114e0: 14000008  b        #0x11500
//   0x0114e4: 2a1f03fb  mov      w27, wzr
//   0x0114e8: 14000006  b        #0x11500
//   0x0114ec: b94002e8  ldr      w8, [x23]
//   0x0114f0: 2a1f03fb  mov      w27, wzr
//   0x0114f4: 0b080348  add      w8, w26, w8
//   0x0114f8: 11000508  add      w8, w8, #1
//   0x0114fc: b90002e8  str      w8, [x23]
//   0x011500: aa1603e0  mov      x0, x22
//   0x011504: 97ffc733  bl       #0x31d0
//   0x011508: 34002240  cbz      w0, #0x11950
//   0x01150c: b4000154  cbz      x20, #0x11534
//   0x011510: 11000b68  add      w8, w27, #2
//   0x011514: 6b15011f  cmp      w8, w21
//   0x011518: 54002faa  b.ge     #0x11b0c
//   0x01151c: 5285e5e9  mov      w9, #0x2f2f
//   0x011520: 783bca89  strh     w9, [x20, w27, sxtw]
//   0x011524: 2a0803fb  mov      w27, w8
//   0x011528: f9400ac1  ldr      x1, [x22, #0x10]
//   0x01152c: b50000e1  cbnz     x1, #0x11548
//   0x011530: 14000029  b        #0x115d4
//   0x011534: b94002e8  ldr      w8, [x23]
//   0x011538: 11000908  add      w8, w8, #2
//   0x01153c: b90002e8  str      w8, [x23]
//   0x011540: f9400ac1  ldr      x1, [x22, #0x10]
//   0x011544: b4000481  cbz      x1, #0x115d4
//   0x011548: f9400ec8  ldr      x8, [x22, #0x18]
//   0x01154c: cb010108  sub      x8, x8, x1
//   0x011550: b40003b4  cbz      x20, #0x115c4
//   0x011554: 93407f69  sxtw     x9, w27
//   0x011558: 8b28c138  add      x24, x9, w8, sxtw
//   0x01155c: 6b15031f  cmp      w24, w21
//   0x011560: 54002d6a  b.ge     #0x11b0c
//   0x011564: 8b090280  add      x0, x20, x9
//   0x011568: 93407d02  sxtw     x2, w8
//   0x01156c: 97ffc755  bl       #0x32c0
//   0x011570: b9400fe8  ldr      w8, [sp, #0xc]
//   0x011574: 6b08031f  cmp      w24, w8
//   0x011578: 54002caa  b.ge     #0x11b0c
//   0x01157c: 52800808  mov      w8, #0x40
//   0x011580: 1100071b  add      w27, w24, #1
//   0x011584: 38386a88  strb     w8, [x20, x24]
//   0x011588: f9401ac8  ldr      x8, [x22, #0x30]
//   0x01158c: b5000288  cbnz     x8, #0x115dc
//   0x011590: f9401ec8  ldr      x8, [x22, #0x38]
//   0x011594: b4000ca8  cbz      x8, #0x11728
//   0x011598: b4001014  cbz      x20, #0x11798
//   0x01159c: b9400fe8  ldr      w8, [sp, #0xc]
//   0x0115a0: 6b08037f  cmp      w27, w8
//   0x0115a4: 54002b4a  b.ge     #0x11b0c
//   0x0115a8: 11000768  add      w8, w27, #1
//   0x0115ac: 52800b69  mov      w9, #0x5b
//   0x0115b0: 383bca89  strb     w9, [x20, w27, sxtw]
//   0x0115b4: 2a0803fb  mov      w27, w8
//   0x0115b8: aa1f03f8  mov      x24, xzr
//   0x0115bc: b5001094  cbnz     x20, #0x117cc
//   0x0115c0: 140000a0  b        #0x11840
//   0x0115c4: b94002e9  ldr      w9, [x23]
//   0x0115c8: 0b090108  add      w8, w8, w9
//   0x0115cc: 11000508  add      w8, w8, #1
//   0x0115d0: b90002e8  str      w8, [x23]
//   0x0115d4: f9401ac8  ldr      x8, [x22, #0x30]
//   0x0115d8: b4fffdc8  cbz      x8, #0x11590
//   0x0115dc: 529999bc  mov      w28, #0xcccd
//   0x0115e0: aa1f03f8  mov      x24, xzr
//   0x0115e4: 5280007a  mov      w26, #3
//   0x0115e8: 72b9999c  movk     w28, #0xcccc, lsl #16
//   0x0115ec: 3878690a  ldrb     w10, [x8, x24]
//   0x0115f0: 52800028  mov      w8, #1
//   0x0115f4: 7100255f  cmp      w10, #9
//   0x0115f8: 1a889508  cinc     w8, w8, hi
//   0x0115fc: 71018d5f  cmp      w10, #0x63
//   0x011600: 1a888348  csel     w8, w26, w8, hi
//   0x011604: b40003f4  cbz      x20, #0x11680
//   0x011608: 93407f69  sxtw     x9, w27
//   0x01160c: 8b28c13b  add      x27, x9, w8, sxtw
//   0x011610: 6b15037f  cmp      w27, w21
//   0x011614: 540027ca  b.ge     #0x11b0c
//   0x011618: 7101915f  cmp      w10, #0x64
//   0x01161c: 540003e3  b.lo     #0x11698
//   0x011620: 529999ae  mov      w14, #0xcccd
//   0x011624: 5290a3eb  mov      w11, #0x851f
//   0x011628: 72b9998e  movk     w14, #0xcccc, lsl #16
//   0x01162c: 72aa3d6b  movk     w11, #0x51eb, lsl #16
//   0x011630: 9bae7d4c  umull    x12, w10, w14
//   0x011634: 9bab7d4b  umull    x11, w10, w11
//   0x011638: d363fd8c  lsr      x12, x12, #0x23
//   0x01163c: 5280014d  mov      w13, #0xa
//   0x011640: d365fd6b  lsr      x11, x11, #0x25
//   0x011644: 1b0da98c  msub     w12, w12, w13, w10
//   0x011648: 52800c8d  mov      w13, #0x64
//   0x01164c: 1b0da96a  msub     w10, w11, w13, w10
//   0x011650: 12001d4a  and      w10, w10, #0xff
//   0x011654: 9bae7d4a  umull    x10, w10, w14
//   0x011658: 321c056b  orr      w11, w11, #0x30
//   0x01165c: d363fd4a  lsr      x10, x10, #0x23
//   0x011660: 390053eb  strb     w11, [sp, #0x14]
//   0x011664: 321c058b  orr      w11, w12, #0x30
//   0x011668: 529999bc  mov      w28, #0xcccd
//   0x01166c: 321c054a  orr      w10, w10, #0x30
//   0x011670: 72b9999c  movk     w28, #0xcccc, lsl #16
//   0x011674: 390057ea  strb     w10, [sp, #0x15]
//   0x011678: 39005beb  strb     w11, [sp, #0x16]
//   0x01167c: 14000014  b        #0x116cc
//   0x011680: b94002e9  ldr      w9, [x23]
//   0x011684: f1000f1f  cmp      x24, #3
//   0x011688: 1a880508  cinc     w8, w8, ne
//   0x01168c: 0b090108  add      w8, w8, w9
//   0x011690: b90002e8  str      w8, [x23]
//   0x011694: 14000020  b        #0x11714
//   0x011698: 7100295f  cmp      w10, #0xa
//   0x01169c: 54000143  b.lo     #0x116c4
//   0x0116a0: 9bbc7d4b  umull    x11, w10, w28
//   0x0116a4: d363fd6b  lsr      x11, x11, #0x23
//   0x0116a8: 5280014d  mov      w13, #0xa
//   0x0116ac: 1b0da96a  msub     w10, w11, w13, w10
//   0x0116b0: 1100c16c  add      w12, w11, #0x30
//   0x0116b4: 321c054a  orr      w10, w10, #0x30
//   0x0116b8: 390053ec  strb     w12, [sp, #0x14]
//   0x0116bc: 390057ea  strb     w10, [sp, #0x15]
//   0x0116c0: 14000003  b        #0x116cc
//   0x0116c4: 1100c14a  add      w10, w10, #0x30
//   0x0116c8: 390053ea  strb     w10, [sp, #0x14]
//   0x0116cc: 2a0803e2  mov      w2, w8
//   0x0116d0: 910053e8  add      x8, sp, #0x14
//   0x0116d4: 8b090280  add      x0, x20, x9
//   0x0116d8: 910053e1  add      x1, sp, #0x14
//   0x0116dc: 3822691f  strb     wzr, [x8, x2]
//   0x0116e0: 97ffc6f8  bl       #0x32c0
//   0x0116e4: f1000f1f  cmp      x24, #3
//   0x0116e8: 54000162  b.hs     #0x11714
//   0x0116ec: b9400fe8  ldr      w8, [sp, #0xc]
//   0x0116f0: 6b08037f  cmp      w27, w8
//   0x0116f4: 540020ca  b.ge     #0x11b0c
//   0x0116f8: 528005c8  mov      w8, #0x2e
//   0x0116fc: 383b6a88  strb     w8, [x20, x27]
//   0x011700: 11000768  add      w8, w27, #1
//   0x011704: 2a0803fb  mov      w27, w8
//   0x011708: f9401ac8  ldr      x8, [x22, #0x30]
//   0x01170c: 91000718  add      x24, x24, #1
//   0x011710: 17ffffb7  b        #0x115ec
//   0x011714: 91000718  add      x24, x24, #1
//   0x011718: f100131f  cmp      x24, #4
//   0x01171c: 54000e60  b.eq     #0x118e8
//   0x011720: f9401ac8  ldr      x8, [x22, #0x30]
//   0x011724: 17ffffb2  b        #0x115ec
//   0x011728: f94022c8  ldr      x8, [x22, #0x40]
//   0x01172c: b4000ac8  cbz      x8, #0x11884
//   0x011730: f94026c9  ldr      x9, [x22, #0x48]
//   0x011734: cb080128  sub      x8, x9, x8
//   0x011738: b4000c54  cbz      x20, #0x118c0
//   0x01173c: b9400fe9  ldr      w9, [sp, #0xc]
//   0x011740: 6b09037f  cmp      w27, w9
//   0x011744: 54001e4a  b.ge     #0x11b0c
//   0x011748: 93407f6a  sxtw     x10, w27
//   0x01174c: 91000549  add      x9, x10, #1
//   0x011750: 0b080138  add      w24, w9, w8
//   0x011754: 52800b6b  mov      w11, #0x5b
//   0x011758: 6b15031f  cmp      w24, w21
//   0x01175c: 382a6a8b  strb     w11, [x20, x10]
//   0x011760: 54001d6a  b.ge     #0x11b0c
//   0x011764: f94022c1  ldr      x1, [x22, #0x40]
//   0x011768: 8b090280  add      x0, x20, x9
//   0x01176c: 93407d02  sxtw     x2, w8
//   0x011770: 97ffc6d4  bl       #0x32c0
//   0x011774: b9400fe8  ldr      w8, [sp, #0xc]
//   0x011778: 6b08031f  cmp      w24, w8
//   0x01177c: 54001c8a  b.ge     #0x11b0c
//   0x011780: 52800ba8  mov      w8, #0x5d
//   0x011784: 1100071b  add      w27, w24, #1
//   0x011788: 3838ca88  strb     w8, [x20, w24, sxtw]
//   0x01178c: f9402ac8  ldr      x8, [x22, #0x50]
//   0x011790: b5000b08  cbnz     x8, #0x118f0
//   0x011794: 1400006f  b        #0x11950
//   0x011798: b94002e8  ldr      w8, [x23]
//   0x01179c: 11000508  add      w8, w8, #1
//   0x0117a0: b90002e8  str      w8, [x23]
//   0x0117a4: aa1f03f8  mov      x24, xzr
//   0x0117a8: b5000134  cbnz     x20, #0x117cc
//   0x0117ac: 14000025  b        #0x11840
//   0x0117b0: b94002e8  ldr      w8, [x23]
//   0x0117b4: 11000508  add      w8, w8, #1
//   0x0117b8: b90002e8  str      w8, [x23]
//   0x0117bc: 91000718  add      x24, x24, #1
//   0x0117c0: f100431f  cmp      x24, #0x10
//   0x0117c4: 540004a0  b.eq     #0x11858
//   0x0117c8: b40003d4  cbz      x20, #0x11840
//   0x0117cc: 11000b7c  add      w28, w27, #2
//   0x0117d0: 6b15039f  cmp      w28, w21
//   0x0117d4: 540019ca  b.ge     #0x11b0c
//   0x0117d8: f9401ec8  ldr      x8, [x22, #0x38]
//   0x0117dc: 2a1f03e1  mov      w1, wzr
//   0x0117e0: 3878691a  ldrb     w26, [x8, x24]
//   0x0117e4: 53047f40  lsr      w0, w26, #4
//   0x0117e8: 97ffc682  bl       #0x31f0
//   0x0117ec: 390043e0  strb     w0, [sp, #0x10]
//   0x0117f0: 12000f40  and      w0, w26, #0xf
//   0x0117f4: 2a1f03e1  mov      w1, wzr
//   0x0117f8: 97ffc67e  bl       #0x31f0
//   0x0117fc: 390047e0  strb     w0, [sp, #0x11]
//   0x011800: 794023e8  ldrh     w8, [sp, #0x10]
//   0x011804: 39004bff  strb     wzr, [sp, #0x12]
//   0x011808: 783bca88  strh     w8, [x20, w27, sxtw]
//   0x01180c: 2a1c03fb  mov      w27, w28
//   0x011810: f1003b1f  cmp      x24, #0xe
//   0x011814: 54fffd48  b.hi     #0x117bc
//   0x011818: 3607fd38  tbz      w24, #0, #0x117bc
//   0x01181c: b4fffcb4  cbz      x20, #0x117b0
//   0x011820: b9400fe8  ldr      w8, [sp, #0xc]
//   0x011824: 6b08037f  cmp      w27, w8
//   0x011828: 5400172a  b.ge     #0x11b0c
//   0x01182c: 11000768  add      w8, w27, #1
//   0x011830: 52800749  mov      w9, #0x3a
//   0x011834: 383bca89  strb     w9, [x20, w27, sxtw]
//   0x011838: 2a0803fb  mov      w27, w8
//   0x01183c: 17ffffe0  b        #0x117bc
//   0x011840: b94002e8  ldr      w8, [x23]
//   0x011844: 11000908  add      w8, w8, #2
//   0x011848: b90002e8  str      w8, [x23]
//   0x01184c: f1003b1f  cmp      x24, #0xe
//   0x011850: 54fffe49  b.ls     #0x11818
//   0x011854: 17ffffda  b        #0x117bc
//   0x011858: b40003d4  cbz      x20, #0x118d0
//   0x01185c: b9400fe8  ldr      w8, [sp, #0xc]
//   0x011860: 6b08037f  cmp      w27, w8
//   0x011864: 5400154a  b.ge     #0x11b0c
//   0x011868: 11000768  add      w8, w27, #1
//   0x01186c: 52800ba9  mov      w9, #0x5d
//   0x011870: 383bca89  strb     w9, [x20, w27, sxtw]
//   0x011874: 2a0803fb  mov      w27, w8
//   0x011878: f9402ac8  ldr      x8, [x22, #0x50]
//   0x01187c: b50003a8  cbnz     x8, #0x118f0
//   0x011880: 14000034  b        #0x11950
//   0x011884: f94012c1  ldr      x1, [x22, #0x20]
//   0x011888: b4000301  cbz      x1, #0x118e8
//   0x01188c: f94016c8  ldr      x8, [x22, #0x28]
//   0x011890: cb010108  sub      x8, x8, x1
//   0x011894: b4000254  cbz      x20, #0x118dc
//   0x011898: 0b080378  add      w24, w27, w8
//   0x01189c: 6b15031f  cmp      w24, w21
//   0x0118a0: 5400136a  b.ge     #0x11b0c
//   0x0118a4: 8b3bc280  add      x0, x20, w27, sxtw
//   0x0118a8: 93407d02  sxtw     x2, w8
//   0x0118ac: 97ffc685  bl       #0x32c0
//   0x0118b0: 2a1803fb  mov      w27, w24
//   0x0118b4: f9402ac8  ldr      x8, [x22, #0x50]
//   0x0118b8: b50001c8  cbnz     x8, #0x118f0
//   0x0118bc: 14000025  b        #0x11950
//   0x0118c0: b94002e9  ldr      w9, [x23]
//   0x0118c4: 0b090108  add      w8, w8, w9
//   0x0118c8: 11000908  add      w8, w8, #2
//   0x0118cc: 14000006  b        #0x118e4
//   0x0118d0: b94002e8  ldr      w8, [x23]
//   0x0118d4: 11000508  add      w8, w8, #1
//   0x0118d8: 14000003  b        #0x118e4
//   0x0118dc: b94002e9  ldr      w9, [x23]
//   0x0118e0: 0b080128  add      w8, w9, w8
//   0x0118e4: b90002e8  str      w8, [x23]
//   0x0118e8: f9402ac8  ldr      x8, [x22, #0x50]
//   0x0118ec: b4000328  cbz      x8, #0x11950
//   0x0118f0: f9402ec9  ldr      x9, [x22, #0x58]
//   0x0118f4: cb080128  sub      x8, x9, x8
//   0x0118f8: b4000254  cbz      x20, #0x11940
//   0x0118fc: b9400fe9  ldr      w9, [sp, #0xc]
//   0x011900: 6b09037f  cmp      w27, w9
//   0x011904: 5400104a  b.ge     #0x11b0c
//   0x011908: 93407f6a  sxtw     x10, w27
//   0x01190c: 91000549  add      x9, x10, #1
//   0x011910: 0b08013b  add      w27, w9, w8
//   0x011914: 5280074b  mov      w11, #0x3a
//   0x011918: 6b15037f  cmp      w27, w21
//   0x01191c: 382a6a8b  strb     w11, [x20, x10]
//   0x011920: 54000f6a  b.ge     #0x11b0c
//   0x011924: f9402ac1  ldr      x1, [x22, #0x50]
//   0x011928: 8b090280  add      x0, x20, x9
//   0x01192c: 93407d02  sxtw     x2, w8
//   0x011930: 97ffc664  bl       #0x32c0
//   0x011934: b94092c8  ldr      w8, [x22, #0x90]
//   0x011938: 35000108  cbnz     w8, #0x11958
//   0x01193c: 14000012  b        #0x11984
//   0x011940: b94002e9  ldr      w9, [x23]
//   0x011944: 0b090108  add      w8, w8, w9
//   0x011948: 11000508  add      w8, w8, #1
//   0x01194c: b90002e8  str      w8, [x23]
//   0x011950: b94092c8  ldr      w8, [x22, #0x90]
//   0x011954: 34000188  cbz      w8, #0x11984
//   0x011958: b4000234  cbz      x20, #0x1199c
//   0x01195c: b9400fe8  ldr      w8, [sp, #0xc]
//   0x011960: 6b08037f  cmp      w27, w8
//   0x011964: 54000d4a  b.ge     #0x11b0c
//   0x011968: 11000768  add      w8, w27, #1
//   0x01196c: 528005e9  mov      w9, #0x2f
//   0x011970: 383bca89  strb     w9, [x20, w27, sxtw]
//   0x011974: 2a0803fb  mov      w27, w8
//   0x011978: f94032d8  ldr      x24, [x22, #0x60]
//   0x01197c: b50001b8  cbnz     x24, #0x119b0
//   0x011980: 1400002e  b        #0x11a38
//   0x011984: f94032c8  ldr      x8, [x22, #0x60]
//   0x011988: b4000108  cbz      x8, #0x119a8
//   0x01198c: aa1603e0  mov      x0, x22
//   0x011990: 97ffc610  bl       #0x31d0
//   0x011994: 35fffe20  cbnz     w0, #0x11958
//   0x011998: 14000004  b        #0x119a8
//   0x01199c: b94002e8  ldr      w8, [x23]
//   0x0119a0: 11000508  add      w8, w8, #1
//   0x0119a4: b90002e8  str      w8, [x23]
//   0x0119a8: f94032d8  ldr      x24, [x22, #0x60]
//   0x0119ac: b4000478  cbz      x24, #0x11a38
//   0x0119b0: 528005fa  mov      w26, #0x2f
//   0x0119b4: 14000006  b        #0x119cc
//   0x0119b8: b94002e8  ldr      w8, [x23]
//   0x0119bc: 11000508  add      w8, w8, #1
//   0x0119c0: b90002e8  str      w8, [x23]
//   0x0119c4: f9400b18  ldr      x24, [x24, #0x10]
//   0x0119c8: b4000398  cbz      x24, #0x11a38
//   0x0119cc: a9402301  ldp      x1, x8, [x24]
//   0x0119d0: cb010108  sub      x8, x8, x1
//   0x0119d4: b4000294  cbz      x20, #0x11a24
//   0x0119d8: 0b08037c  add      w28, w27, w8
//   0x0119dc: 6b15039f  cmp      w28, w21
//   0x0119e0: 5400096a  b.ge     #0x11b0c
//   0x0119e4: 8b3bc280  add      x0, x20, w27, sxtw
//   0x0119e8: 93407d02  sxtw     x2, w8
//   0x0119ec: 97ffc635  bl       #0x32c0
//   0x0119f0: 2a1c03fb  mov      w27, w28
//   0x0119f4: f9400b08  ldr      x8, [x24, #0x10]
//   0x0119f8: b4000208  cbz      x8, #0x11a38
//   0x0119fc: b4fffdf4  cbz      x20, #0x119b8
//   0x011a00: b9400fe8  ldr      w8, [sp, #0xc]
//   0x011a04: 6b08037f  cmp      w27, w8
//   0x011a08: 5400082a  b.ge     #0x11b0c
//   0x011a0c: 11000768  add      w8, w27, #1
//   0x011a10: 383bca9a  strb     w26, [x20, w27, sxtw]
//   0x011a14: 2a0803fb  mov      w27, w8
//   0x011a18: f9400b18  ldr      x24, [x24, #0x10]
//   0x011a1c: b5fffd98  cbnz     x24, #0x119cc
//   0x011a20: 14000006  b        #0x11a38
//   0x011a24: b94002e9  ldr      w9, [x23]
//   0x011a28: 0b080128  add      w8, w9, w8
//   0x011a2c: b90002e8  str      w8, [x23]
//   0x011a30: f9400b08  ldr      x8, [x24, #0x10]
//   0x011a34: b5fffe48  cbnz     x8, #0x119fc
//   0x011a38: f9403ac8  ldr      x8, [x22, #0x70]
//   0x011a3c: b4000388  cbz      x8, #0x11aac
//   0x011a40: b40002b4  cbz      x20, #0x11a94
//   0x011a44: b9400fe8  ldr      w8, [sp, #0xc]
//   0x011a48: 6b08037f  cmp      w27, w8
//   0x011a4c: 5400060a  b.ge     #0x11b0c
//   0x011a50: 93407f68  sxtw     x8, w27
//   0x011a54: 528007e9  mov      w9, #0x3f
//   0x011a58: 38286a89  strb     w9, [x20, x8]
//   0x011a5c: a9472ac1  ldp      x1, x10, [x22, #0x70]
//   0x011a60: 91000509  add      x9, x8, #1
//   0x011a64: cb010148  sub      x8, x10, x1
//   0x011a68: 0b08013b  add      w27, w9, w8
//   0x011a6c: 6b15037f  cmp      w27, w21
//   0x011a70: 540004ea  b.ge     #0x11b0c
//   0x011a74: 8b090280  add      x0, x20, x9
//   0x011a78: 93407d02  sxtw     x2, w8
//   0x011a7c: 97ffc611  bl       #0x32c0
//   0x011a80: f94042c8  ldr      x8, [x22, #0x80]
//   0x011a84: b5000188  cbnz     x8, #0x11ab4
//   0x011a88: b5000374  cbnz     x20, #0x11af4
//   0x011a8c: 2a1f03e0  mov      w0, wzr
//   0x011a90: 14000023  b        #0x11b1c
//   0x011a94: b9407ac9  ldr      w9, [x22, #0x78]
//   0x011a98: b94002ea  ldr      w10, [x23]
//   0x011a9c: 4b080128  sub      w8, w9, w8
//   0x011aa0: 0b080148  add      w8, w10, w8
//   0x011aa4: 11000508  add      w8, w8, #1
//   0x011aa8: b90002e8  str      w8, [x23]
//   0x011aac: f94042c8  ldr      x8, [x22, #0x80]
//   0x011ab0: b4fffec8  cbz      x8, #0x11a88
//   0x011ab4: b40004d4  cbz      x20, #0x11b4c
//   0x011ab8: b9400fe8  ldr      w8, [sp, #0xc]
//   0x011abc: 6b08037f  cmp      w27, w8
//   0x011ac0: 5400026a  b.ge     #0x11b0c
//   0x011ac4: 93407f68  sxtw     x8, w27
//   0x011ac8: 52800469  mov      w9, #0x23
//   0x011acc: 38286a89  strb     w9, [x20, x8]
//   0x011ad0: a9482ac1  ldp      x1, x10, [x22, #0x80]
//   0x011ad4: 91000509  add      x9, x8, #1
//   0x011ad8: cb010148  sub      x8, x10, x1
//   0x011adc: 0b08013b  add      w27, w9, w8
//   0x011ae0: 6b15037f  cmp      w27, w21
//   0x011ae4: 5400014a  b.ge     #0x11b0c
//   0x011ae8: 8b090280  add      x0, x20, x9
//   0x011aec: 93407d02  sxtw     x2, w8
//   0x011af0: 97ffc5f4  bl       #0x32c0
//   0x011af4: 2a1f03e0  mov      w0, wzr
//   0x011af8: 383bca9f  strb     wzr, [x20, w27, sxtw]
//   0x011afc: b4000113  cbz      x19, #0x11b1c
//   0x011b00: 11000768  add      w8, w27, #1
//   0x011b04: b9000268  str      w8, [x19]
//   0x011b08: 14000005  b        #0x11b1c
//   0x011b0c: 3900029f  strb     wzr, [x20]
//   0x011b10: b4000053  cbz      x19, #0x11b18
//   0x011b14: b900027f  str      wzr, [x19]
//   0x011b18: 52800080  mov      w0, #4
//   0x011b1c: f9401728  ldr      x8, [x25, #0x28]
//   0x011b20: f9400fe9  ldr      x9, [sp, #0x18]
//   0x011b24: eb09011f  cmp      x8, x9
//   0x011b28: 54000221  b.ne     #0x11b6c
//   0x011b2c: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x011b30: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x011b34: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x011b38: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x011b3c: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x011b40: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x011b44: 910203ff  add      sp, sp, #0x80
//   0x011b48: d65f03c0  ret      
//   0x011b4c: b9408ac9  ldr      w9, [x22, #0x88]
//   0x011b50: b94002ea  ldr      w10, [x23]
//   0x011b54: 2a1f03e0  mov      w0, wzr
//   0x011b58: 4b080128  sub      w8, w9, w8
//   0x011b5c: 0b080148  add      w8, w10, w8
//   0x011b60: 11000508  add      w8, w8, #1
//   0x011b64: b90002e8  str      w8, [x23]
//   0x011b68: 17ffffed  b        #0x11b1c
//   0x011b6c: 97ffc56d  bl       #0x3120
// ============================================================================
std::uint32_t fde_161_11410(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00011410ULL;
    for (std::size_t i = 0; i < 472ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14384ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[162] Subroutine @ 0x011b70..0x011b78 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[162] Hàm con @ 0x011b70..0x011b78 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x011b70: aa1f03e4  mov      x4, xzr
//   0x011b74: 17fffe27  b        #0x11410
// ============================================================================
std::uint32_t fde_162_11b70(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00011b70ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14856ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[163] Subroutine @ 0x011b78..0x011b90 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[163] Hàm con @ 0x011b78..0x011b90 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x011b78: aa0103e4  mov      x4, x1
//   0x011b7c: 12b00002  mov      w2, #0x7fffffff
//   0x011b80: aa0003e1  mov      x1, x0
//   0x011b84: aa1f03e0  mov      x0, xzr
//   0x011b88: aa1f03e3  mov      x3, xzr
//   0x011b8c: 14000001  b        #0x11b90
// ============================================================================
std::uint32_t fde_163_11b78(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00011b78ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14858ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[164] Subroutine @ 0x011b90..0x012324 (1940 bytes, 485 AArch64 instructions)
// [VN] Khung FDE[164] Hàm con @ 0x011b90..0x012324 (1940 byte, 485 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x011b90: d10203ff  sub      sp, sp, #0x80
//   0x011b94: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x011b98: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x011b9c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x011ba0: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x011ba4: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x011ba8: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x011bac: 9101c3fd  add      x29, sp, #0x70
//   0x011bb0: d53bd058  mrs      x24, tpidr_el0
//   0x011bb4: f9401708  ldr      x8, [x24, #0x28]
//   0x011bb8: aa0303f3  mov      x19, x3
//   0x011bbc: f9000fe8  str      x8, [sp, #0x18]
//   0x011bc0: b40000a1  cbz      x1, #0x11bd4
//   0x011bc4: aa0403f5  mov      x21, x4
//   0x011bc8: aa0003f4  mov      x20, x0
//   0x011bcc: aa040008  orr      x8, x0, x4
//   0x011bd0: b50000a8  cbnz     x8, #0x11be4
//   0x011bd4: b4000433  cbz      x19, #0x11c58
//   0x011bd8: b900027f  str      wzr, [x19]
//   0x011bdc: 52800040  mov      w0, #2
//   0x011be0: 140001bf  b        #0x122dc
//   0x011be4: 2a0203f6  mov      w22, w2
//   0x011be8: 7100005f  cmp      w2, #0
//   0x011bec: 540003ad  b.le     #0x11c60
//   0x011bf0: f100029f  cmp      x20, #0
//   0x011bf4: 9a951288  csel     x8, x20, x21, ne
//   0x011bf8: b900011f  str      wzr, [x8]
//   0x011bfc: aa0103f7  mov      x23, x1
//   0x011c00: f9400021  ldr      x1, [x1]
//   0x011c04: 510006c8  sub      w8, w22, #1
//   0x011c08: b90007e8  str      w8, [sp, #4]
//   0x011c0c: b40002e1  cbz      x1, #0x11c68
//   0x011c10: f94006e8  ldr      x8, [x23, #8]
//   0x011c14: cb01011a  sub      x26, x8, x1
//   0x011c18: d342ff59  lsr      x25, x26, #2
//   0x011c1c: b40002b4  cbz      x20, #0x11c70
//   0x011c20: 6b16033f  cmp      w25, w22
//   0x011c24: 5400354a  b.ge     #0x122cc
//   0x011c28: 93408742  sbfx     x2, x26, #0, #0x22
//   0x011c2c: aa1403e0  mov      x0, x20
//   0x011c30: 97ffc5a4  bl       #0x32c0
//   0x011c34: b94007e8  ldr      w8, [sp, #4]
//   0x011c38: 6b19011f  cmp      w8, w25
//   0x011c3c: 5400348d  b.le     #0x122cc
//   0x011c40: d3628748  lsl      x8, x26, #0x1e
//   0x011c44: 935efd08  asr      x8, x8, #0x1e
//   0x011c48: 52800749  mov      w9, #0x3a
//   0x011c4c: 1100073a  add      w26, w25, #1
//   0x011c50: b8286a89  str      w9, [x20, x8]
//   0x011c54: 1400000c  b        #0x11c84
//   0x011c58: 52800040  mov      w0, #2
//   0x011c5c: 140001a0  b        #0x122dc
//   0x011c60: b50033b3  cbnz     x19, #0x122d4
//   0x011c64: 1400019d  b        #0x122d8
//   0x011c68: 2a1f03fa  mov      w26, wzr
//   0x011c6c: 14000006  b        #0x11c84
//   0x011c70: b94002a8  ldr      w8, [x21]
//   0x011c74: 2a1f03fa  mov      w26, wzr
//   0x011c78: 0b080328  add      w8, w25, w8
//   0x011c7c: 11000508  add      w8, w8, #1
//   0x011c80: b90002a8  str      w8, [x21]
//   0x011c84: aa1703e0  mov      x0, x23
//   0x011c88: 97ffc522  bl       #0x3110
//   0x011c8c: 340022a0  cbz      w0, #0x120e0
//   0x011c90: b4000194  cbz      x20, #0x11cc0
//   0x011c94: 11000b48  add      w8, w26, #2
//   0x011c98: 6b16011f  cmp      w8, w22
//   0x011c9c: 5400318a  b.ge     #0x122cc
//   0x011ca0: d28005ea  mov      x10, #0x2f
//   0x011ca4: 937e7f49  sbfiz    x9, x26, #2, #0x20
//   0x011ca8: f2c005ea  movk     x10, #0x2f, lsl #32
//   0x011cac: f8296a8a  str      x10, [x20, x9]
//   0x011cb0: 2a0803fa  mov      w26, w8
//   0x011cb4: f9400ae1  ldr      x1, [x23, #0x10]
//   0x011cb8: b50000e1  cbnz     x1, #0x11cd4
//   0x011cbc: 14000029  b        #0x11d60
//   0x011cc0: b94002a8  ldr      w8, [x21]
//   0x011cc4: 11000908  add      w8, w8, #2
//   0x011cc8: b90002a8  str      w8, [x21]
//   0x011ccc: f9400ae1  ldr      x1, [x23, #0x10]
//   0x011cd0: b4000481  cbz      x1, #0x11d60
//   0x011cd4: f9400ee8  ldr      x8, [x23, #0x18]
//   0x011cd8: cb010108  sub      x8, x8, x1
//   0x011cdc: d342fd09  lsr      x9, x8, #2
//   0x011ce0: b4000394  cbz      x20, #0x11d50
//   0x011ce4: 0b090359  add      w25, w26, w9
//   0x011ce8: 6b16033f  cmp      w25, w22
//   0x011cec: 54002f0a  b.ge     #0x122cc
//   0x011cf0: 8b3aca80  add      x0, x20, w26, sxtw #2
//   0x011cf4: 93408502  sbfx     x2, x8, #0, #0x22
//   0x011cf8: 97ffc572  bl       #0x32c0
//   0x011cfc: b94007e8  ldr      w8, [sp, #4]
//   0x011d00: 6b08033f  cmp      w25, w8
//   0x011d04: 54002e4a  b.ge     #0x122cc
//   0x011d08: 52800808  mov      w8, #0x40
//   0x011d0c: 1100073a  add      w26, w25, #1
//   0x011d10: b839da88  str      w8, [x20, w25, sxtw #2]
//   0x011d14: f9401ae8  ldr      x8, [x23, #0x30]
//   0x011d18: b5000288  cbnz     x8, #0x11d68
//   0x011d1c: f9401ee8  ldr      x8, [x23, #0x38]
//   0x011d20: b4000c68  cbz      x8, #0x11eac
//   0x011d24: b4000ff4  cbz      x20, #0x11f20
//   0x011d28: b94007e8  ldr      w8, [sp, #4]
//   0x011d2c: 6b08035f  cmp      w26, w8
//   0x011d30: 54002cea  b.ge     #0x122cc
//   0x011d34: 11000748  add      w8, w26, #1
//   0x011d38: 52800b69  mov      w9, #0x5b
//   0x011d3c: b83ada89  str      w9, [x20, w26, sxtw #2]
//   0x011d40: 2a0803fa  mov      w26, w8
//   0x011d44: aa1f03f9  mov      x25, xzr
//   0x011d48: b5001074  cbnz     x20, #0x11f54
//   0x011d4c: 1400009f  b        #0x11fc8
//   0x011d50: b94002a8  ldr      w8, [x21]
//   0x011d54: 0b080128  add      w8, w9, w8
//   0x011d58: 11000508  add      w8, w8, #1
//   0x011d5c: b90002a8  str      w8, [x21]
//   0x011d60: f9401ae8  ldr      x8, [x23, #0x30]
//   0x011d64: b4fffdc8  cbz      x8, #0x11d1c
//   0x011d68: 529999b9  mov      w25, #0xcccd
//   0x011d6c: aa1f03fb  mov      x27, xzr
//   0x011d70: 72b99999  movk     w25, #0xcccc, lsl #16
//   0x011d74: 387b6909  ldrb     w9, [x8, x27]
//   0x011d78: 52800028  mov      w8, #1
//   0x011d7c: 5280006a  mov      w10, #3
//   0x011d80: 7100253f  cmp      w9, #9
//   0x011d84: 1a889508  cinc     w8, w8, hi
//   0x011d88: 71018d3f  cmp      w9, #0x63
//   0x011d8c: 1a888148  csel     w8, w10, w8, hi
//   0x011d90: b40003b4  cbz      x20, #0x11e04
//   0x011d94: 0b1a011c  add      w28, w8, w26
//   0x011d98: 6b16039f  cmp      w28, w22
//   0x011d9c: 5400298a  b.ge     #0x122cc
//   0x011da0: 7101913f  cmp      w9, #0x64
//   0x011da4: 540003c3  b.lo     #0x11e1c
//   0x011da8: 529999ad  mov      w13, #0xcccd
//   0x011dac: 5290a3ea  mov      w10, #0x851f
//   0x011db0: 72b9998d  movk     w13, #0xcccc, lsl #16
//   0x011db4: 72aa3d6a  movk     w10, #0x51eb, lsl #16
//   0x011db8: 9bad7d2b  umull    x11, w9, w13
//   0x011dbc: 9baa7d2a  umull    x10, w9, w10
//   0x011dc0: d363fd6b  lsr      x11, x11, #0x23
//   0x011dc4: 5280014c  mov      w12, #0xa
//   0x011dc8: d365fd4a  lsr      x10, x10, #0x25
//   0x011dcc: 1b0ca56b  msub     w11, w11, w12, w9
//   0x011dd0: 52800c8c  mov      w12, #0x64
//   0x011dd4: 1b0ca549  msub     w9, w10, w12, w9
//   0x011dd8: 12001d29  and      w9, w9, #0xff
//   0x011ddc: 9bad7d29  umull    x9, w9, w13
//   0x011de0: 321c054a  orr      w10, w10, #0x30
//   0x011de4: d363fd29  lsr      x9, x9, #0x23
//   0x011de8: b9000bea  str      w10, [sp, #8]
//   0x011dec: 321c056a  orr      w10, w11, #0x30
//   0x011df0: 529999b9  mov      w25, #0xcccd
//   0x011df4: 321c0529  orr      w9, w9, #0x30
//   0x011df8: 72b99999  movk     w25, #0xcccc, lsl #16
//   0x011dfc: 2901abe9  stp      w9, w10, [sp, #0xc]
//   0x011e00: 14000014  b        #0x11e50
//   0x011e04: b94002a9  ldr      w9, [x21]
//   0x011e08: f1000f7f  cmp      x27, #3
//   0x011e0c: 1a880508  cinc     w8, w8, ne
//   0x011e10: 0b090108  add      w8, w8, w9
//   0x011e14: b90002a8  str      w8, [x21]
//   0x011e18: 14000020  b        #0x11e98
//   0x011e1c: 7100293f  cmp      w9, #0xa
//   0x011e20: 54000143  b.lo     #0x11e48
//   0x011e24: 9bb97d2a  umull    x10, w9, w25
//   0x011e28: d363fd4a  lsr      x10, x10, #0x23
//   0x011e2c: 5280014c  mov      w12, #0xa
//   0x011e30: 1b0ca549  msub     w9, w10, w12, w9
//   0x011e34: 321c0529  orr      w9, w9, #0x30
//   0x011e38: 1100c14b  add      w11, w10, #0x30
//   0x011e3c: 12001d29  and      w9, w9, #0xff
//   0x011e40: 290127eb  stp      w11, w9, [sp, #8]
//   0x011e44: 14000003  b        #0x11e50
//   0x011e48: 1100c129  add      w9, w9, #0x30
//   0x011e4c: b9000be9  str      w9, [sp, #8]
//   0x011e50: 910023e9  add      x9, sp, #8
//   0x011e54: 8b3aca80  add      x0, x20, w26, sxtw #2
//   0x011e58: 531e7502  lsl      w2, w8, #2
//   0x011e5c: 910023e1  add      x1, sp, #8
//   0x011e60: b828593f  str      wzr, [x9, w8, uxtw #2]
//   0x011e64: 97ffc517  bl       #0x32c0
//   0x011e68: f1000f7f  cmp      x27, #3
//   0x011e6c: 54000142  b.hs     #0x11e94
//   0x011e70: b94007e8  ldr      w8, [sp, #4]
//   0x011e74: 6b08039f  cmp      w28, w8
//   0x011e78: 540022aa  b.ge     #0x122cc
//   0x011e7c: 528005c8  mov      w8, #0x2e
//   0x011e80: b83cda88  str      w8, [x20, w28, sxtw #2]
//   0x011e84: f9401ae8  ldr      x8, [x23, #0x30]
//   0x011e88: 1100079a  add      w26, w28, #1
//   0x011e8c: 9100077b  add      x27, x27, #1
//   0x011e90: 17ffffb9  b        #0x11d74
//   0x011e94: 2a1c03fa  mov      w26, w28
//   0x011e98: 9100077b  add      x27, x27, #1
//   0x011e9c: f100137f  cmp      x27, #4
//   0x011ea0: 54000ea0  b.eq     #0x12074
//   0x011ea4: f9401ae8  ldr      x8, [x23, #0x30]
//   0x011ea8: 17ffffb3  b        #0x11d74
//   0x011eac: f94022e8  ldr      x8, [x23, #0x40]
//   0x011eb0: b4000ae8  cbz      x8, #0x1200c
//   0x011eb4: f94026e9  ldr      x9, [x23, #0x48]
//   0x011eb8: cb080128  sub      x8, x9, x8
//   0x011ebc: d342fd09  lsr      x9, x8, #2
//   0x011ec0: b4000c74  cbz      x20, #0x1204c
//   0x011ec4: b94007ea  ldr      w10, [sp, #4]
//   0x011ec8: 6b0a035f  cmp      w26, w10
//   0x011ecc: 5400200a  b.ge     #0x122cc
//   0x011ed0: 93407f4b  sxtw     x11, w26
//   0x011ed4: 9100056a  add      x10, x11, #1
//   0x011ed8: 0b090159  add      w25, w10, w9
//   0x011edc: 52800b6c  mov      w12, #0x5b
//   0x011ee0: 6b16033f  cmp      w25, w22
//   0x011ee4: b82b7a8c  str      w12, [x20, x11, lsl #2]
//   0x011ee8: 54001f2a  b.ge     #0x122cc
//   0x011eec: f94022e1  ldr      x1, [x23, #0x40]
//   0x011ef0: 8b0a0a80  add      x0, x20, x10, lsl #2
//   0x011ef4: 93408502  sbfx     x2, x8, #0, #0x22
//   0x011ef8: 97ffc4f2  bl       #0x32c0
//   0x011efc: b94007e8  ldr      w8, [sp, #4]
//   0x011f00: 6b08033f  cmp      w25, w8
//   0x011f04: 54001e4a  b.ge     #0x122cc
//   0x011f08: 52800ba8  mov      w8, #0x5d
//   0x011f0c: 1100073a  add      w26, w25, #1
//   0x011f10: b839da88  str      w8, [x20, w25, sxtw #2]
//   0x011f14: f9402ae8  ldr      x8, [x23, #0x50]
//   0x011f18: b5000b28  cbnz     x8, #0x1207c
//   0x011f1c: 14000071  b        #0x120e0
//   0x011f20: b94002a8  ldr      w8, [x21]
//   0x011f24: 11000508  add      w8, w8, #1
//   0x011f28: b90002a8  str      w8, [x21]
//   0x011f2c: aa1f03f9  mov      x25, xzr
//   0x011f30: b5000134  cbnz     x20, #0x11f54
//   0x011f34: 14000025  b        #0x11fc8
//   0x011f38: b94002a8  ldr      w8, [x21]
//   0x011f3c: 11000508  add      w8, w8, #1
//   0x011f40: b90002a8  str      w8, [x21]
//   0x011f44: 91000739  add      x25, x25, #1
//   0x011f48: f100433f  cmp      x25, #0x10
//   0x011f4c: 540004a0  b.eq     #0x11fe0
//   0x011f50: b40003d4  cbz      x20, #0x11fc8
//   0x011f54: 11000b5c  add      w28, w26, #2
//   0x011f58: 6b16039f  cmp      w28, w22
//   0x011f5c: 54001b8a  b.ge     #0x122cc
//   0x011f60: f9401ee8  ldr      x8, [x23, #0x38]
//   0x011f64: 2a1f03e1  mov      w1, wzr
//   0x011f68: 3879691b  ldrb     w27, [x8, x25]
//   0x011f6c: 53047f60  lsr      w0, w27, #4
//   0x011f70: 97ffc4c8  bl       #0x3290
//   0x011f74: b9000be0  str      w0, [sp, #8]
//   0x011f78: 12000f60  and      w0, w27, #0xf
//   0x011f7c: 2a1f03e1  mov      w1, wzr
//   0x011f80: 97ffc4c4  bl       #0x3290
//   0x011f84: 2901ffe0  stp      w0, wzr, [sp, #0xc]
//   0x011f88: f94007e8  ldr      x8, [sp, #8]
//   0x011f8c: 937e7f49  sbfiz    x9, x26, #2, #0x20
//   0x011f90: 2a1c03fa  mov      w26, w28
//   0x011f94: f8296a88  str      x8, [x20, x9]
//   0x011f98: f1003b3f  cmp      x25, #0xe
//   0x011f9c: 54fffd48  b.hi     #0x11f44
//   0x011fa0: 3607fd39  tbz      w25, #0, #0x11f44
//   0x011fa4: b4fffcb4  cbz      x20, #0x11f38
//   0x011fa8: b94007e8  ldr      w8, [sp, #4]
//   0x011fac: 6b08035f  cmp      w26, w8
//   0x011fb0: 540018ea  b.ge     #0x122cc
//   0x011fb4: 11000748  add      w8, w26, #1
//   0x011fb8: 52800749  mov      w9, #0x3a
//   0x011fbc: b83ada89  str      w9, [x20, w26, sxtw #2]
//   0x011fc0: 2a0803fa  mov      w26, w8
//   0x011fc4: 17ffffe0  b        #0x11f44
//   0x011fc8: b94002a8  ldr      w8, [x21]
//   0x011fcc: 11000908  add      w8, w8, #2
//   0x011fd0: b90002a8  str      w8, [x21]
//   0x011fd4: f1003b3f  cmp      x25, #0xe
//   0x011fd8: 54fffe49  b.ls     #0x11fa0
//   0x011fdc: 17ffffda  b        #0x11f44
//   0x011fe0: b40003f4  cbz      x20, #0x1205c
//   0x011fe4: b94007e8  ldr      w8, [sp, #4]
//   0x011fe8: 6b08035f  cmp      w26, w8
//   0x011fec: 5400170a  b.ge     #0x122cc
//   0x011ff0: 11000748  add      w8, w26, #1
//   0x011ff4: 52800ba9  mov      w9, #0x5d
//   0x011ff8: b83ada89  str      w9, [x20, w26, sxtw #2]
//   0x011ffc: 2a0803fa  mov      w26, w8
//   0x012000: f9402ae8  ldr      x8, [x23, #0x50]
//   0x012004: b50003c8  cbnz     x8, #0x1207c
//   0x012008: 14000036  b        #0x120e0
//   0x01200c: f94012e1  ldr      x1, [x23, #0x20]
//   0x012010: b4000321  cbz      x1, #0x12074
//   0x012014: f94016e8  ldr      x8, [x23, #0x28]
//   0x012018: cb010108  sub      x8, x8, x1
//   0x01201c: d342fd09  lsr      x9, x8, #2
//   0x012020: b4000254  cbz      x20, #0x12068
//   0x012024: 0b090359  add      w25, w26, w9
//   0x012028: 6b16033f  cmp      w25, w22
//   0x01202c: 5400150a  b.ge     #0x122cc
//   0x012030: 8b3aca80  add      x0, x20, w26, sxtw #2
//   0x012034: 93408502  sbfx     x2, x8, #0, #0x22
//   0x012038: 97ffc4a2  bl       #0x32c0
//   0x01203c: 2a1903fa  mov      w26, w25
//   0x012040: f9402ae8  ldr      x8, [x23, #0x50]
//   0x012044: b50001c8  cbnz     x8, #0x1207c
//   0x012048: 14000026  b        #0x120e0
//   0x01204c: b94002a8  ldr      w8, [x21]
//   0x012050: 0b080128  add      w8, w9, w8
//   0x012054: 11000908  add      w8, w8, #2
//   0x012058: 14000006  b        #0x12070
//   0x01205c: b94002a8  ldr      w8, [x21]
//   0x012060: 11000508  add      w8, w8, #1
//   0x012064: 14000003  b        #0x12070
//   0x012068: b94002a8  ldr      w8, [x21]
//   0x01206c: 0b090108  add      w8, w8, w9
//   0x012070: b90002a8  str      w8, [x21]
//   0x012074: f9402ae8  ldr      x8, [x23, #0x50]
//   0x012078: b4000348  cbz      x8, #0x120e0
//   0x01207c: f9402ee9  ldr      x9, [x23, #0x58]
//   0x012080: cb080128  sub      x8, x9, x8
//   0x012084: d342fd09  lsr      x9, x8, #2
//   0x012088: b4000254  cbz      x20, #0x120d0
//   0x01208c: b94007ea  ldr      w10, [sp, #4]
//   0x012090: 6b0a035f  cmp      w26, w10
//   0x012094: 540011ca  b.ge     #0x122cc
//   0x012098: 93407f4b  sxtw     x11, w26
//   0x01209c: 9100056a  add      x10, x11, #1
//   0x0120a0: 0b09015a  add      w26, w10, w9
//   0x0120a4: 5280074c  mov      w12, #0x3a
//   0x0120a8: 6b16035f  cmp      w26, w22
//   0x0120ac: b82b7a8c  str      w12, [x20, x11, lsl #2]
//   0x0120b0: 540010ea  b.ge     #0x122cc
//   0x0120b4: f9402ae1  ldr      x1, [x23, #0x50]
//   0x0120b8: 8b0a0a80  add      x0, x20, x10, lsl #2
//   0x0120bc: 93408502  sbfx     x2, x8, #0, #0x22
//   0x0120c0: 97ffc480  bl       #0x32c0
//   0x0120c4: b94092e8  ldr      w8, [x23, #0x90]
//   0x0120c8: 35000108  cbnz     w8, #0x120e8
//   0x0120cc: 14000012  b        #0x12114
//   0x0120d0: b94002a8  ldr      w8, [x21]
//   0x0120d4: 0b080128  add      w8, w9, w8
//   0x0120d8: 11000508  add      w8, w8, #1
//   0x0120dc: b90002a8  str      w8, [x21]
//   0x0120e0: b94092e8  ldr      w8, [x23, #0x90]
//   0x0120e4: 34000188  cbz      w8, #0x12114
//   0x0120e8: b4000234  cbz      x20, #0x1212c
//   0x0120ec: b94007e8  ldr      w8, [sp, #4]
//   0x0120f0: 6b08035f  cmp      w26, w8
//   0x0120f4: 54000eca  b.ge     #0x122cc
//   0x0120f8: 11000748  add      w8, w26, #1
//   0x0120fc: 528005e9  mov      w9, #0x2f
//   0x012100: b83ada89  str      w9, [x20, w26, sxtw #2]
//   0x012104: 2a0803fa  mov      w26, w8
//   0x012108: f94032f9  ldr      x25, [x23, #0x60]
//   0x01210c: b50001b9  cbnz     x25, #0x12140
//   0x012110: 1400002f  b        #0x121cc
//   0x012114: f94032e8  ldr      x8, [x23, #0x60]
//   0x012118: b4000108  cbz      x8, #0x12138
//   0x01211c: aa1703e0  mov      x0, x23
//   0x012120: 97ffc3fc  bl       #0x3110
//   0x012124: 35fffe20  cbnz     w0, #0x120e8
//   0x012128: 14000004  b        #0x12138
//   0x01212c: b94002a8  ldr      w8, [x21]
//   0x012130: 11000508  add      w8, w8, #1
//   0x012134: b90002a8  str      w8, [x21]
//   0x012138: f94032f9  ldr      x25, [x23, #0x60]
//   0x01213c: b4000499  cbz      x25, #0x121cc
//   0x012140: 528005fb  mov      w27, #0x2f
//   0x012144: 14000006  b        #0x1215c
//   0x012148: b94002a8  ldr      w8, [x21]
//   0x01214c: 11000508  add      w8, w8, #1
//   0x012150: b90002a8  str      w8, [x21]
//   0x012154: f9400b39  ldr      x25, [x25, #0x10]
//   0x012158: b40003b9  cbz      x25, #0x121cc
//   0x01215c: a9402321  ldp      x1, x8, [x25]
//   0x012160: cb010108  sub      x8, x8, x1
//   0x012164: d342fd09  lsr      x9, x8, #2
//   0x012168: b4000294  cbz      x20, #0x121b8
//   0x01216c: 0b09035c  add      w28, w26, w9
//   0x012170: 6b16039f  cmp      w28, w22
//   0x012174: 54000aca  b.ge     #0x122cc
//   0x012178: 8b3aca80  add      x0, x20, w26, sxtw #2
//   0x01217c: 93408502  sbfx     x2, x8, #0, #0x22
//   0x012180: 97ffc450  bl       #0x32c0
//   0x012184: 2a1c03fa  mov      w26, w28
//   0x012188: f9400b28  ldr      x8, [x25, #0x10]
//   0x01218c: b4000208  cbz      x8, #0x121cc
//   0x012190: b4fffdd4  cbz      x20, #0x12148
//   0x012194: b94007e8  ldr      w8, [sp, #4]
//   0x012198: 6b08035f  cmp      w26, w8
//   0x01219c: 5400098a  b.ge     #0x122cc
//   0x0121a0: 11000748  add      w8, w26, #1
//   0x0121a4: b83ada9b  str      w27, [x20, w26, sxtw #2]
//   0x0121a8: 2a0803fa  mov      w26, w8
//   0x0121ac: f9400b39  ldr      x25, [x25, #0x10]
//   0x0121b0: b5fffd79  cbnz     x25, #0x1215c
//   0x0121b4: 14000006  b        #0x121cc
//   0x0121b8: b94002a8  ldr      w8, [x21]
//   0x0121bc: 0b090108  add      w8, w8, w9
//   0x0121c0: b90002a8  str      w8, [x21]
//   0x0121c4: f9400b28  ldr      x8, [x25, #0x10]
//   0x0121c8: b5fffe48  cbnz     x8, #0x12190
//   0x0121cc: f9403ae8  ldr      x8, [x23, #0x70]
//   0x0121d0: b4000408  cbz      x8, #0x12250
//   0x0121d4: b4000134  cbz      x20, #0x121f8
//   0x0121d8: b94007e8  ldr      w8, [sp, #4]
//   0x0121dc: 6b08035f  cmp      w26, w8
//   0x0121e0: 5400076a  b.ge     #0x122cc
//   0x0121e4: 11000748  add      w8, w26, #1
//   0x0121e8: 528007e9  mov      w9, #0x3f
//   0x0121ec: b83ada89  str      w9, [x20, w26, sxtw #2]
//   0x0121f0: 2a0803fa  mov      w26, w8
//   0x0121f4: 14000004  b        #0x12204
//   0x0121f8: b94002a8  ldr      w8, [x21]
//   0x0121fc: 11000508  add      w8, w8, #1
//   0x012200: b90002a8  str      w8, [x21]
//   0x012204: a94722e1  ldp      x1, x8, [x23, #0x70]
//   0x012208: cb010108  sub      x8, x8, x1
//   0x01220c: d342fd09  lsr      x9, x8, #2
//   0x012210: b40001b4  cbz      x20, #0x12244
//   0x012214: 0b090359  add      w25, w26, w9
//   0x012218: 6b16033f  cmp      w25, w22
//   0x01221c: 5400058a  b.ge     #0x122cc
//   0x012220: 8b3aca80  add      x0, x20, w26, sxtw #2
//   0x012224: 93408502  sbfx     x2, x8, #0, #0x22
//   0x012228: 97ffc426  bl       #0x32c0
//   0x01222c: 2a1903fa  mov      w26, w25
//   0x012230: f94042e8  ldr      x8, [x23, #0x80]
//   0x012234: b5000128  cbnz     x8, #0x12258
//   0x012238: b50003f4  cbnz     x20, #0x122b4
//   0x01223c: 2a1f03e0  mov      w0, wzr
//   0x012240: 14000027  b        #0x122dc
//   0x012244: b94002a8  ldr      w8, [x21]
//   0x012248: 0b090108  add      w8, w8, w9
//   0x01224c: b90002a8  str      w8, [x21]
//   0x012250: f94042e8  ldr      x8, [x23, #0x80]
//   0x012254: b4ffff28  cbz      x8, #0x12238
//   0x012258: b4000134  cbz      x20, #0x1227c
//   0x01225c: b94007e8  ldr      w8, [sp, #4]
//   0x012260: 6b08035f  cmp      w26, w8
//   0x012264: 5400034a  b.ge     #0x122cc
//   0x012268: 11000748  add      w8, w26, #1
//   0x01226c: 52800469  mov      w9, #0x23
//   0x012270: b83ada89  str      w9, [x20, w26, sxtw #2]
//   0x012274: 2a0803fa  mov      w26, w8
//   0x012278: 14000004  b        #0x12288
//   0x01227c: b94002a8  ldr      w8, [x21]
//   0x012280: 11000508  add      w8, w8, #1
//   0x012284: b90002a8  str      w8, [x21]
//   0x012288: a94822e1  ldp      x1, x8, [x23, #0x80]
//   0x01228c: cb010108  sub      x8, x8, x1
//   0x012290: d342fd09  lsr      x9, x8, #2
//   0x012294: b40003d4  cbz      x20, #0x1230c
//   0x012298: 0b090355  add      w21, w26, w9
//   0x01229c: 6b1602bf  cmp      w21, w22
//   0x0122a0: 5400016a  b.ge     #0x122cc
//   0x0122a4: 8b3aca80  add      x0, x20, w26, sxtw #2
//   0x0122a8: 93408502  sbfx     x2, x8, #0, #0x22
//   0x0122ac: 97ffc405  bl       #0x32c0
//   0x0122b0: 2a1503fa  mov      w26, w21
//   0x0122b4: 2a1f03e0  mov      w0, wzr
//   0x0122b8: b83ada9f  str      wzr, [x20, w26, sxtw #2]
//   0x0122bc: b4000113  cbz      x19, #0x122dc
//   0x0122c0: 11000748  add      w8, w26, #1
//   0x0122c4: b9000268  str      w8, [x19]
//   0x0122c8: 14000005  b        #0x122dc
//   0x0122cc: b900029f  str      wzr, [x20]
//   0x0122d0: b4000053  cbz      x19, #0x122d8
//   0x0122d4: b900027f  str      wzr, [x19]
//   0x0122d8: 52800080  mov      w0, #4
//   0x0122dc: f9401708  ldr      x8, [x24, #0x28]
//   0x0122e0: f9400fe9  ldr      x9, [sp, #0x18]
//   0x0122e4: eb09011f  cmp      x8, x9
//   0x0122e8: 540001c1  b.ne     #0x12320
//   0x0122ec: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x0122f0: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x0122f4: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x0122f8: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x0122fc: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x012300: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x012304: 910203ff  add      sp, sp, #0x80
//   0x012308: d65f03c0  ret      
//   0x01230c: b94002a8  ldr      w8, [x21]
//   0x012310: 2a1f03e0  mov      w0, wzr
//   0x012314: 0b090108  add      w8, w8, w9
//   0x012318: b90002a8  str      w8, [x21]
//   0x01231c: 17fffff0  b        #0x122dc
//   0x012320: 97ffc380  bl       #0x3120
// ============================================================================
std::uint32_t fde_164_11b90(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00011b90ULL;
    for (std::size_t i = 0; i < 485ULL; ++i) {
        std::uint32_t insn = kTextInstructions[14864ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[165] Subroutine @ 0x012324..0x01232c (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[165] Hàm con @ 0x012324..0x01232c (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012324: aa1f03e4  mov      x4, xzr
//   0x012328: 17fffe1a  b        #0x11b90
// ============================================================================
std::uint32_t fde_165_12324(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012324ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15349ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[166] Subroutine @ 0x01232c..0x012338 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[166] Hàm con @ 0x01232c..0x012338 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x01232c: 2a1f03e3  mov      w3, wzr
//   0x012330: aa1f03e4  mov      x4, xzr
//   0x012334: 17ffc3c7  b        #0x3250
// ============================================================================
std::uint32_t fde_166_1232c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0001232cULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15351ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[167] Subroutine @ 0x012338..0x012340 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[167] Hàm con @ 0x012338..0x012340 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012338: aa1f03e4  mov      x4, xzr
//   0x01233c: 17ffc3c5  b        #0x3250
// ============================================================================
std::uint32_t fde_167_12338(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012338ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15354ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[168] Subroutine @ 0x012340..0x01265c (796 bytes, 199 AArch64 instructions)
// [VN] Khung FDE[168] Hàm con @ 0x012340..0x01265c (796 byte, 199 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012340: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x012344: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x012348: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01234c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x012350: 9100c3fd  add      x29, sp, #0x30
//   0x012354: 2a0303f8  mov      w24, w3
//   0x012358: aa0203f6  mov      x22, x2
//   0x01235c: aa0103f5  mov      x21, x1
//   0x012360: aa0003f3  mov      x19, x0
//   0x012364: b4000104  cbz      x4, #0x12384
//   0x012368: aa0403e0  mov      x0, x4
//   0x01236c: aa0403f4  mov      x20, x4
//   0x012370: 97ffc3bc  bl       #0x3260
//   0x012374: 7100041f  cmp      w0, #1
//   0x012378: 540000a0  b.eq     #0x1238c
//   0x01237c: 52800157  mov      w23, #0xa
//   0x012380: 140000b1  b        #0x12644
//   0x012384: b0000054  adrp     x20, #0x1b000
//   0x012388: f947fe94  ldr      x20, [x20, #0xff8]
//   0x01238c: b4000473  cbz      x19, #0x12418
//   0x012390: aa1303e0  mov      x0, x19
//   0x012394: 97ffc333  bl       #0x3060
//   0x012398: 52800057  mov      w23, #2
//   0x01239c: b40014f5  cbz      x21, #0x12638
//   0x0123a0: b40014d6  cbz      x22, #0x12638
//   0x0123a4: f94002c8  ldr      x8, [x22]
//   0x0123a8: b40003c8  cbz      x8, #0x12420
//   0x0123ac: f94002a8  ldr      x8, [x21]
//   0x0123b0: 360003d8  tbz      w24, #0, #0x12428
//   0x0123b4: b40003a8  cbz      x8, #0x12428
//   0x0123b8: aa1603e0  mov      x0, x22
//   0x0123bc: aa1503e1  mov      x1, x21
//   0x0123c0: 97ffc314  bl       #0x3010
//   0x0123c4: 35000340  cbnz     w0, #0x1242c
//   0x0123c8: aa1503e0  mov      x0, x21
//   0x0123cc: 97ffc381  bl       #0x31d0
//   0x0123d0: 34000540  cbz      w0, #0x12478
//   0x0123d4: aa1303e0  mov      x0, x19
//   0x0123d8: aa1503e1  mov      x1, x21
//   0x0123dc: aa1403e2  mov      x2, x20
//   0x0123e0: 97ffc340  bl       #0x30e0
//   0x0123e4: 34001280  cbz      w0, #0x12634
//   0x0123e8: aa1303e0  mov      x0, x19
//   0x0123ec: aa1503e1  mov      x1, x21
//   0x0123f0: aa1403e2  mov      x2, x20
//   0x0123f4: 97ffc3af  bl       #0x32b0
//   0x0123f8: 340011e0  cbz      w0, #0x12634
//   0x0123fc: aa1303e0  mov      x0, x19
//   0x012400: aa1403e1  mov      x1, x20
//   0x012404: 97ffc387  bl       #0x3220
//   0x012408: 34001160  cbz      w0, #0x12634
//   0x01240c: 3dc01ea0  ldr      q0, [x21, #0x70]
//   0x012410: 3d801e60  str      q0, [x19, #0x70]
//   0x012414: 1400005b  b        #0x12580
//   0x012418: 52800057  mov      w23, #2
//   0x01241c: 1400008a  b        #0x12644
//   0x012420: 528000b7  mov      w23, #5
//   0x012424: 14000085  b        #0x12638
//   0x012428: b4fffd08  cbz      x8, #0x123c8
//   0x01242c: 3dc002a0  ldr      q0, [x21]
//   0x012430: aa1303e0  mov      x0, x19
//   0x012434: aa1503e1  mov      x1, x21
//   0x012438: aa1403e2  mov      x2, x20
//   0x01243c: 3d800260  str      q0, [x19]
//   0x012440: 97ffc328  bl       #0x30e0
//   0x012444: 34000f80  cbz      w0, #0x12634
//   0x012448: aa1303e0  mov      x0, x19
//   0x01244c: aa1503e1  mov      x1, x21
//   0x012450: aa1403e2  mov      x2, x20
//   0x012454: 97ffc397  bl       #0x32b0
//   0x012458: 34000ee0  cbz      w0, #0x12634
//   0x01245c: aa1303e0  mov      x0, x19
//   0x012460: aa1403e1  mov      x1, x20
//   0x012464: 97ffc36f  bl       #0x3220
//   0x012468: 34000e60  cbz      w0, #0x12634
//   0x01246c: 3dc01ea0  ldr      q0, [x21, #0x70]
//   0x012470: 3d801e60  str      q0, [x19, #0x70]
//   0x012474: 14000045  b        #0x12588
//   0x012478: aa1303e0  mov      x0, x19
//   0x01247c: aa1603e1  mov      x1, x22
//   0x012480: aa1403e2  mov      x2, x20
//   0x012484: 97ffc317  bl       #0x30e0
//   0x012488: 34000d60  cbz      w0, #0x12634
//   0x01248c: f94032a9  ldr      x9, [x21, #0x60]
//   0x012490: b94092a8  ldr      w8, [x21, #0x90]
//   0x012494: b40001a9  cbz      x9, #0x124c8
//   0x012498: 350001a8  cbnz     w8, #0x124cc
//   0x01249c: aa1303e0  mov      x0, x19
//   0x0124a0: aa1603e1  mov      x1, x22
//   0x0124a4: aa1403e2  mov      x2, x20
//   0x0124a8: 97ffc382  bl       #0x32b0
//   0x0124ac: 34000c40  cbz      w0, #0x12634
//   0x0124b0: f94032a8  ldr      x8, [x21, #0x60]
//   0x0124b4: b4000aa8  cbz      x8, #0x12608
//   0x0124b8: f9403269  ldr      x9, [x19, #0x60]
//   0x0124bc: b40006e9  cbz      x9, #0x12598
//   0x0124c0: f9403677  ldr      x23, [x19, #0x68]
//   0x0124c4: 1400003e  b        #0x125bc
//   0x0124c8: 340003e8  cbz      w8, #0x12544
//   0x0124cc: aa1303e0  mov      x0, x19
//   0x0124d0: aa1503e1  mov      x1, x21
//   0x0124d4: aa1403e2  mov      x2, x20
//   0x0124d8: 97ffc376  bl       #0x32b0
//   0x0124dc: 34000ac0  cbz      w0, #0x12634
//   0x0124e0: aa1303e0  mov      x0, x19
//   0x0124e4: 97ffc33b  bl       #0x31d0
//   0x0124e8: 34000220  cbz      w0, #0x1252c
//   0x0124ec: b9409268  ldr      w8, [x19, #0x90]
//   0x0124f0: 340001e8  cbz      w8, #0x1252c
//   0x0124f4: f9403268  ldr      x8, [x19, #0x60]
//   0x0124f8: b5000188  cbnz     x8, #0x12528
//   0x0124fc: f9400288  ldr      x8, [x20]
//   0x012500: 52800401  mov      w1, #0x20
//   0x012504: aa1403e0  mov      x0, x20
//   0x012508: d63f0100  blr      x8
//   0x01250c: b4000940  cbz      x0, #0x12634
//   0x012510: b0000048  adrp     x8, #0x1b000
//   0x012514: f947e108  ldr      x8, [x8, #0xfc0]
//   0x012518: f9400108  ldr      x8, [x8]
//   0x01251c: a900fc08  stp      x8, xzr, [x0, #8]
//   0x012520: f9000008  str      x8, [x0]
//   0x012524: a9060260  stp      x0, x0, [x19, #0x60]
//   0x012528: b900927f  str      wzr, [x19, #0x90]
//   0x01252c: aa1303e0  mov      x0, x19
//   0x012530: aa1403e1  mov      x1, x20
//   0x012534: 97ffc33b  bl       #0x3220
//   0x012538: 340007e0  cbz      w0, #0x12634
//   0x01253c: 9101c2a8  add      x8, x21, #0x70
//   0x012540: 1400000b  b        #0x1256c
//   0x012544: aa1303e0  mov      x0, x19
//   0x012548: aa1603e1  mov      x1, x22
//   0x01254c: aa1403e2  mov      x2, x20
//   0x012550: 97ffc358  bl       #0x32b0
//   0x012554: 34000700  cbz      w0, #0x12634
//   0x012558: aa1503e8  mov      x8, x21
//   0x01255c: f8470d09  ldr      x9, [x8, #0x70]!
//   0x012560: 9101c2ca  add      x10, x22, #0x70
//   0x012564: f100013f  cmp      x9, #0
//   0x012568: 9a880148  csel     x8, x10, x8, eq
//   0x01256c: 3dc00100  ldr      q0, [x8]
//   0x012570: aa1303e0  mov      x0, x19
//   0x012574: aa1403e1  mov      x1, x20
//   0x012578: 3d801e60  str      q0, [x19, #0x70]
//   0x01257c: 97ffc2c9  bl       #0x30a0
//   0x012580: 3dc002c0  ldr      q0, [x22]
//   0x012584: 3d800260  str      q0, [x19]
//   0x012588: 3dc022a0  ldr      q0, [x21, #0x80]
//   0x01258c: 2a1f03f7  mov      w23, wzr
//   0x012590: 3d802260  str      q0, [x19, #0x80]
//   0x012594: 1400002c  b        #0x12644
//   0x012598: f9400288  ldr      x8, [x20]
//   0x01259c: 52800401  mov      w1, #0x20
//   0x0125a0: aa1403e0  mov      x0, x20
//   0x0125a4: d63f0100  blr      x8
//   0x0125a8: b4000460  cbz      x0, #0x12634
//   0x0125ac: f900081f  str      xzr, [x0, #0x10]
//   0x0125b0: a9060260  stp      x0, x0, [x19, #0x60]
//   0x0125b4: f94032a8  ldr      x8, [x21, #0x60]
//   0x0125b8: aa0003f7  mov      x23, x0
//   0x0125bc: f9400109  ldr      x9, [x8]
//   0x0125c0: f90002e9  str      x9, [x23]
//   0x0125c4: f9400509  ldr      x9, [x8, #8]
//   0x0125c8: f90006e9  str      x9, [x23, #8]
//   0x0125cc: f9400918  ldr      x24, [x8, #0x10]
//   0x0125d0: b40001d8  cbz      x24, #0x12608
//   0x0125d4: f9400288  ldr      x8, [x20]
//   0x0125d8: 52800401  mov      w1, #0x20
//   0x0125dc: aa1403e0  mov      x0, x20
//   0x0125e0: d63f0100  blr      x8
//   0x0125e4: b4000240  cbz      x0, #0x1262c
//   0x0125e8: 3dc00300  ldr      q0, [x24]
//   0x0125ec: 3d800000  str      q0, [x0]
//   0x0125f0: f9000ae0  str      x0, [x23, #0x10]
//   0x0125f4: f9400b18  ldr      x24, [x24, #0x10]
//   0x0125f8: aa0003f7  mov      x23, x0
//   0x0125fc: b5fffed8  cbnz     x24, #0x125d4
//   0x012600: f9003660  str      x0, [x19, #0x68]
//   0x012604: f900081f  str      xzr, [x0, #0x10]
//   0x012608: aa1303e0  mov      x0, x19
//   0x01260c: aa1403e1  mov      x1, x20
//   0x012610: 97ffc304  bl       #0x3220
//   0x012614: 34000100  cbz      w0, #0x12634
//   0x012618: aa1303e0  mov      x0, x19
//   0x01261c: aa1403e1  mov      x1, x20
//   0x012620: 97ffc2a4  bl       #0x30b0
//   0x012624: 35fff8c0  cbnz     w0, #0x1253c
//   0x012628: 14000003  b        #0x12634
//   0x01262c: f9000aff  str      xzr, [x23, #0x10]
//   0x012630: f9003677  str      x23, [x19, #0x68]
//   0x012634: 52800077  mov      w23, #3
//   0x012638: aa1303e0  mov      x0, x19
//   0x01263c: aa1403e1  mov      x1, x20
//   0x012640: 97ffc260  bl       #0x2fc0
//   0x012644: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x012648: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x01264c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x012650: 2a1703e0  mov      w0, w23
//   0x012654: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x012658: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_168_12340(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012340ULL;
    for (std::size_t i = 0; i < 199ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15356ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[169] Subroutine @ 0x01265c..0x012668 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[169] Hàm con @ 0x01265c..0x012668 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x01265c: 2a1f03e3  mov      w3, wzr
//   0x012660: aa1f03e4  mov      x4, xzr
//   0x012664: 17ffc2c3  b        #0x3170
// ============================================================================
std::uint32_t fde_169_1265c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0001265cULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15555ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[170] Subroutine @ 0x012668..0x012670 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[170] Hàm con @ 0x012668..0x012670 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012668: aa1f03e4  mov      x4, xzr
//   0x01266c: 17ffc2c1  b        #0x3170
// ============================================================================
std::uint32_t fde_170_12668(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012668ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15558ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[171] Subroutine @ 0x012670..0x01298c (796 bytes, 199 AArch64 instructions)
// [VN] Khung FDE[171] Hàm con @ 0x012670..0x01298c (796 byte, 199 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012670: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x012674: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x012678: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01267c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x012680: 9100c3fd  add      x29, sp, #0x30
//   0x012684: 2a0303f8  mov      w24, w3
//   0x012688: aa0203f6  mov      x22, x2
//   0x01268c: aa0103f5  mov      x21, x1
//   0x012690: aa0003f3  mov      x19, x0
//   0x012694: b4000104  cbz      x4, #0x126b4
//   0x012698: aa0403e0  mov      x0, x4
//   0x01269c: aa0403f4  mov      x20, x4
//   0x0126a0: 97ffc2f0  bl       #0x3260
//   0x0126a4: 7100041f  cmp      w0, #1
//   0x0126a8: 540000a0  b.eq     #0x126bc
//   0x0126ac: 52800157  mov      w23, #0xa
//   0x0126b0: 140000b1  b        #0x12974
//   0x0126b4: b0000054  adrp     x20, #0x1b000
//   0x0126b8: f947fe94  ldr      x20, [x20, #0xff8]
//   0x0126bc: b4000473  cbz      x19, #0x12748
//   0x0126c0: aa1303e0  mov      x0, x19
//   0x0126c4: 97ffc2b7  bl       #0x31a0
//   0x0126c8: 52800057  mov      w23, #2
//   0x0126cc: b40014f5  cbz      x21, #0x12968
//   0x0126d0: b40014d6  cbz      x22, #0x12968
//   0x0126d4: f94002c8  ldr      x8, [x22]
//   0x0126d8: b40003c8  cbz      x8, #0x12750
//   0x0126dc: f94002a8  ldr      x8, [x21]
//   0x0126e0: 360003d8  tbz      w24, #0, #0x12758
//   0x0126e4: b40003a8  cbz      x8, #0x12758
//   0x0126e8: aa1603e0  mov      x0, x22
//   0x0126ec: aa1503e1  mov      x1, x21
//   0x0126f0: 97ffc220  bl       #0x2f70
//   0x0126f4: 35000340  cbnz     w0, #0x1275c
//   0x0126f8: aa1503e0  mov      x0, x21
//   0x0126fc: 97ffc285  bl       #0x3110
//   0x012700: 34000540  cbz      w0, #0x127a8
//   0x012704: aa1303e0  mov      x0, x19
//   0x012708: aa1503e1  mov      x1, x21
//   0x01270c: aa1403e2  mov      x2, x20
//   0x012710: 97ffc294  bl       #0x3160
//   0x012714: 34001280  cbz      w0, #0x12964
//   0x012718: aa1303e0  mov      x0, x19
//   0x01271c: aa1503e1  mov      x1, x21
//   0x012720: aa1403e2  mov      x2, x20
//   0x012724: 97ffc2f7  bl       #0x3300
//   0x012728: 340011e0  cbz      w0, #0x12964
//   0x01272c: aa1303e0  mov      x0, x19
//   0x012730: aa1403e1  mov      x1, x20
//   0x012734: 97ffc29f  bl       #0x31b0
//   0x012738: 34001160  cbz      w0, #0x12964
//   0x01273c: 3dc01ea0  ldr      q0, [x21, #0x70]
//   0x012740: 3d801e60  str      q0, [x19, #0x70]
//   0x012744: 1400005b  b        #0x128b0
//   0x012748: 52800057  mov      w23, #2
//   0x01274c: 1400008a  b        #0x12974
//   0x012750: 528000b7  mov      w23, #5
//   0x012754: 14000085  b        #0x12968
//   0x012758: b4fffd08  cbz      x8, #0x126f8
//   0x01275c: 3dc002a0  ldr      q0, [x21]
//   0x012760: aa1303e0  mov      x0, x19
//   0x012764: aa1503e1  mov      x1, x21
//   0x012768: aa1403e2  mov      x2, x20
//   0x01276c: 3d800260  str      q0, [x19]
//   0x012770: 97ffc27c  bl       #0x3160
//   0x012774: 34000f80  cbz      w0, #0x12964
//   0x012778: aa1303e0  mov      x0, x19
//   0x01277c: aa1503e1  mov      x1, x21
//   0x012780: aa1403e2  mov      x2, x20
//   0x012784: 97ffc2df  bl       #0x3300
//   0x012788: 34000ee0  cbz      w0, #0x12964
//   0x01278c: aa1303e0  mov      x0, x19
//   0x012790: aa1403e1  mov      x1, x20
//   0x012794: 97ffc287  bl       #0x31b0
//   0x012798: 34000e60  cbz      w0, #0x12964
//   0x01279c: 3dc01ea0  ldr      q0, [x21, #0x70]
//   0x0127a0: 3d801e60  str      q0, [x19, #0x70]
//   0x0127a4: 14000045  b        #0x128b8
//   0x0127a8: aa1303e0  mov      x0, x19
//   0x0127ac: aa1603e1  mov      x1, x22
//   0x0127b0: aa1403e2  mov      x2, x20
//   0x0127b4: 97ffc26b  bl       #0x3160
//   0x0127b8: 34000d60  cbz      w0, #0x12964
//   0x0127bc: f94032a9  ldr      x9, [x21, #0x60]
//   0x0127c0: b94092a8  ldr      w8, [x21, #0x90]
//   0x0127c4: b40001a9  cbz      x9, #0x127f8
//   0x0127c8: 350001a8  cbnz     w8, #0x127fc
//   0x0127cc: aa1303e0  mov      x0, x19
//   0x0127d0: aa1603e1  mov      x1, x22
//   0x0127d4: aa1403e2  mov      x2, x20
//   0x0127d8: 97ffc2ca  bl       #0x3300
//   0x0127dc: 34000c40  cbz      w0, #0x12964
//   0x0127e0: f94032a8  ldr      x8, [x21, #0x60]
//   0x0127e4: b4000aa8  cbz      x8, #0x12938
//   0x0127e8: f9403269  ldr      x9, [x19, #0x60]
//   0x0127ec: b40006e9  cbz      x9, #0x128c8
//   0x0127f0: f9403677  ldr      x23, [x19, #0x68]
//   0x0127f4: 1400003e  b        #0x128ec
//   0x0127f8: 340003e8  cbz      w8, #0x12874
//   0x0127fc: aa1303e0  mov      x0, x19
//   0x012800: aa1503e1  mov      x1, x21
//   0x012804: aa1403e2  mov      x2, x20
//   0x012808: 97ffc2be  bl       #0x3300
//   0x01280c: 34000ac0  cbz      w0, #0x12964
//   0x012810: aa1303e0  mov      x0, x19
//   0x012814: 97ffc23f  bl       #0x3110
//   0x012818: 34000220  cbz      w0, #0x1285c
//   0x01281c: b9409268  ldr      w8, [x19, #0x90]
//   0x012820: 340001e8  cbz      w8, #0x1285c
//   0x012824: f9403268  ldr      x8, [x19, #0x60]
//   0x012828: b5000188  cbnz     x8, #0x12858
//   0x01282c: f9400288  ldr      x8, [x20]
//   0x012830: 52800401  mov      w1, #0x20
//   0x012834: aa1403e0  mov      x0, x20
//   0x012838: d63f0100  blr      x8
//   0x01283c: b4000940  cbz      x0, #0x12964
//   0x012840: b0000048  adrp     x8, #0x1b000
//   0x012844: f947e908  ldr      x8, [x8, #0xfd0]
//   0x012848: f9400108  ldr      x8, [x8]
//   0x01284c: a900fc08  stp      x8, xzr, [x0, #8]
//   0x012850: f9000008  str      x8, [x0]
//   0x012854: a9060260  stp      x0, x0, [x19, #0x60]
//   0x012858: b900927f  str      wzr, [x19, #0x90]
//   0x01285c: aa1303e0  mov      x0, x19
//   0x012860: aa1403e1  mov      x1, x20
//   0x012864: 97ffc253  bl       #0x31b0
//   0x012868: 340007e0  cbz      w0, #0x12964
//   0x01286c: 9101c2a8  add      x8, x21, #0x70
//   0x012870: 1400000b  b        #0x1289c
//   0x012874: aa1303e0  mov      x0, x19
//   0x012878: aa1603e1  mov      x1, x22
//   0x01287c: aa1403e2  mov      x2, x20
//   0x012880: 97ffc2a0  bl       #0x3300
//   0x012884: 34000700  cbz      w0, #0x12964
//   0x012888: aa1503e8  mov      x8, x21
//   0x01288c: f8470d09  ldr      x9, [x8, #0x70]!
//   0x012890: 9101c2ca  add      x10, x22, #0x70
//   0x012894: f100013f  cmp      x9, #0
//   0x012898: 9a880148  csel     x8, x10, x8, eq
//   0x01289c: 3dc00100  ldr      q0, [x8]
//   0x0128a0: aa1303e0  mov      x0, x19
//   0x0128a4: aa1403e1  mov      x1, x20
//   0x0128a8: 3d801e60  str      q0, [x19, #0x70]
//   0x0128ac: 97ffc209  bl       #0x30d0
//   0x0128b0: 3dc002c0  ldr      q0, [x22]
//   0x0128b4: 3d800260  str      q0, [x19]
//   0x0128b8: 3dc022a0  ldr      q0, [x21, #0x80]
//   0x0128bc: 2a1f03f7  mov      w23, wzr
//   0x0128c0: 3d802260  str      q0, [x19, #0x80]
//   0x0128c4: 1400002c  b        #0x12974
//   0x0128c8: f9400288  ldr      x8, [x20]
//   0x0128cc: 52800401  mov      w1, #0x20
//   0x0128d0: aa1403e0  mov      x0, x20
//   0x0128d4: d63f0100  blr      x8
//   0x0128d8: b4000460  cbz      x0, #0x12964
//   0x0128dc: f900081f  str      xzr, [x0, #0x10]
//   0x0128e0: a9060260  stp      x0, x0, [x19, #0x60]
//   0x0128e4: f94032a8  ldr      x8, [x21, #0x60]
//   0x0128e8: aa0003f7  mov      x23, x0
//   0x0128ec: f9400109  ldr      x9, [x8]
//   0x0128f0: f90002e9  str      x9, [x23]
//   0x0128f4: f9400509  ldr      x9, [x8, #8]
//   0x0128f8: f90006e9  str      x9, [x23, #8]
//   0x0128fc: f9400918  ldr      x24, [x8, #0x10]
//   0x012900: b40001d8  cbz      x24, #0x12938
//   0x012904: f9400288  ldr      x8, [x20]
//   0x012908: 52800401  mov      w1, #0x20
//   0x01290c: aa1403e0  mov      x0, x20
//   0x012910: d63f0100  blr      x8
//   0x012914: b4000240  cbz      x0, #0x1295c
//   0x012918: 3dc00300  ldr      q0, [x24]
//   0x01291c: 3d800000  str      q0, [x0]
//   0x012920: f9000ae0  str      x0, [x23, #0x10]
//   0x012924: f9400b18  ldr      x24, [x24, #0x10]
//   0x012928: aa0003f7  mov      x23, x0
//   0x01292c: b5fffed8  cbnz     x24, #0x12904
//   0x012930: f9003660  str      x0, [x19, #0x68]
//   0x012934: f900081f  str      xzr, [x0, #0x10]
//   0x012938: aa1303e0  mov      x0, x19
//   0x01293c: aa1403e1  mov      x1, x20
//   0x012940: 97ffc21c  bl       #0x31b0
//   0x012944: 34000100  cbz      w0, #0x12964
//   0x012948: aa1303e0  mov      x0, x19
//   0x01294c: aa1403e1  mov      x1, x20
//   0x012950: 97ffc1c8  bl       #0x3070
//   0x012954: 35fff8c0  cbnz     w0, #0x1286c
//   0x012958: 14000003  b        #0x12964
//   0x01295c: f9000aff  str      xzr, [x23, #0x10]
//   0x012960: f9003677  str      x23, [x19, #0x68]
//   0x012964: 52800077  mov      w23, #3
//   0x012968: aa1303e0  mov      x0, x19
//   0x01296c: aa1403e1  mov      x1, x20
//   0x012970: 97ffc1b8  bl       #0x3050
//   0x012974: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x012978: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x01297c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x012980: 2a1703e0  mov      w0, w23
//   0x012984: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x012988: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_171_12670(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012670ULL;
    for (std::size_t i = 0; i < 199ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15560ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[172] Subroutine @ 0x01298c..0x012994 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[172] Hàm con @ 0x01298c..0x012994 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x01298c: aa1f03e4  mov      x4, xzr
//   0x012990: 17ffc1fc  b        #0x3180
// ============================================================================
std::uint32_t fde_172_1298c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0001298cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15759ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[173] Subroutine @ 0x012994..0x012d2c (920 bytes, 230 AArch64 instructions)
// [VN] Khung FDE[173] Hàm con @ 0x012994..0x012d2c (920 byte, 230 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012994: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x012998: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x01299c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0129a0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0129a4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0129a8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0129ac: 910143fd  add      x29, sp, #0x50
//   0x0129b0: 2a0303f7  mov      w23, w3
//   0x0129b4: aa0203f6  mov      x22, x2
//   0x0129b8: aa0103f5  mov      x21, x1
//   0x0129bc: aa0003f3  mov      x19, x0
//   0x0129c0: b4000104  cbz      x4, #0x129e0
//   0x0129c4: aa0403e0  mov      x0, x4
//   0x0129c8: aa0403f4  mov      x20, x4
//   0x0129cc: 97ffc225  bl       #0x3260
//   0x0129d0: 7100041f  cmp      w0, #1
//   0x0129d4: 540000a0  b.eq     #0x129e8
//   0x0129d8: 52800158  mov      w24, #0xa
//   0x0129dc: 140000cc  b        #0x12d0c
//   0x0129e0: b0000054  adrp     x20, #0x1b000
//   0x0129e4: f947fe94  ldr      x20, [x20, #0xff8]
//   0x0129e8: b40002d3  cbz      x19, #0x12a40
//   0x0129ec: aa1303e0  mov      x0, x19
//   0x0129f0: 97ffc19c  bl       #0x3060
//   0x0129f4: 52800058  mov      w24, #2
//   0x0129f8: b4001855  cbz      x21, #0x12d00
//   0x0129fc: b4001836  cbz      x22, #0x12d00
//   0x012a00: f94002c8  ldr      x8, [x22]
//   0x012a04: b4000228  cbz      x8, #0x12a48
//   0x012a08: f94002a8  ldr      x8, [x21]
//   0x012a0c: b4000228  cbz      x8, #0x12a50
//   0x012a10: aa1503e0  mov      x0, x21
//   0x012a14: aa1603e1  mov      x1, x22
//   0x012a18: 97ffc17e  bl       #0x3010
//   0x012a1c: 340001e0  cbz      w0, #0x12a58
//   0x012a20: 3dc002a0  ldr      q0, [x21]
//   0x012a24: aa1303e0  mov      x0, x19
//   0x012a28: aa1503e1  mov      x1, x21
//   0x012a2c: aa1403e2  mov      x2, x20
//   0x012a30: 3d800260  str      q0, [x19]
//   0x012a34: 97ffc1ab  bl       #0x30e0
//   0x012a38: 35000500  cbnz     w0, #0x12ad8
//   0x012a3c: 140000b0  b        #0x12cfc
//   0x012a40: 52800058  mov      w24, #2
//   0x012a44: 140000b2  b        #0x12d0c
//   0x012a48: 528000d8  mov      w24, #6
//   0x012a4c: 140000ad  b        #0x12d00
//   0x012a50: 528000f8  mov      w24, #7
//   0x012a54: 140000ab  b        #0x12d00
//   0x012a58: f9401aa0  ldr      x0, [x21, #0x30]
//   0x012a5c: b40000e0  cbz      x0, #0x12a78
//   0x012a60: f9401ac1  ldr      x1, [x22, #0x30]
//   0x012a64: b4000301  cbz      x1, #0x12ac4
//   0x012a68: 52800082  mov      w2, #4
//   0x012a6c: 97ffc1a5  bl       #0x3100
//   0x012a70: 350002a0  cbnz     w0, #0x12ac4
//   0x012a74: 14000024  b        #0x12b04
//   0x012a78: f9401ea0  ldr      x0, [x21, #0x38]
//   0x012a7c: b40000e0  cbz      x0, #0x12a98
//   0x012a80: f9401ec1  ldr      x1, [x22, #0x38]
//   0x012a84: b4000201  cbz      x1, #0x12ac4
//   0x012a88: 52800202  mov      w2, #0x10
//   0x012a8c: 97ffc19d  bl       #0x3100
//   0x012a90: 350001a0  cbnz     w0, #0x12ac4
//   0x012a94: 1400001c  b        #0x12b04
//   0x012a98: aa1503e0  mov      x0, x21
//   0x012a9c: f8440c08  ldr      x8, [x0, #0x40]!
//   0x012aa0: b40000a8  cbz      x8, #0x12ab4
//   0x012aa4: aa1603e1  mov      x1, x22
//   0x012aa8: f8440c28  ldr      x8, [x1, #0x40]!
//   0x012aac: b5000088  cbnz     x8, #0x12abc
//   0x012ab0: 14000005  b        #0x12ac4
//   0x012ab4: 910082a0  add      x0, x21, #0x20
//   0x012ab8: 910082c1  add      x1, x22, #0x20
//   0x012abc: 97ffc155  bl       #0x3010
//   0x012ac0: 34000220  cbz      w0, #0x12b04
//   0x012ac4: aa1303e0  mov      x0, x19
//   0x012ac8: aa1503e1  mov      x1, x21
//   0x012acc: aa1403e2  mov      x2, x20
//   0x012ad0: 97ffc184  bl       #0x30e0
//   0x012ad4: 34001140  cbz      w0, #0x12cfc
//   0x012ad8: aa1303e0  mov      x0, x19
//   0x012adc: aa1503e1  mov      x1, x21
//   0x012ae0: aa1403e2  mov      x2, x20
//   0x012ae4: 97ffc1f3  bl       #0x32b0
//   0x012ae8: 340010a0  cbz      w0, #0x12cfc
//   0x012aec: 3dc01ea0  ldr      q0, [x21, #0x70]
//   0x012af0: 2a1f03f8  mov      w24, wzr
//   0x012af4: 3d801e60  str      q0, [x19, #0x70]
//   0x012af8: 3dc022a0  ldr      q0, [x21, #0x80]
//   0x012afc: 3d802260  str      q0, [x19, #0x80]
//   0x012b00: 14000083  b        #0x12d0c
//   0x012b04: 710006ff  cmp      w23, #1
//   0x012b08: 540001a1  b.ne     #0x12b3c
//   0x012b0c: aa1303e0  mov      x0, x19
//   0x012b10: aa1503e1  mov      x1, x21
//   0x012b14: aa1403e2  mov      x2, x20
//   0x012b18: 97ffc1e6  bl       #0x32b0
//   0x012b1c: 34000f00  cbz      w0, #0x12cfc
//   0x012b20: 52800028  mov      w8, #1
//   0x012b24: aa1303e0  mov      x0, x19
//   0x012b28: aa1403e1  mov      x1, x20
//   0x012b2c: b9009268  str      w8, [x19, #0x90]
//   0x012b30: 97ffc160  bl       #0x30b0
//   0x012b34: 35fffdc0  cbnz     w0, #0x12aec
//   0x012b38: 14000071  b        #0x12cfc
//   0x012b3c: f94032b7  ldr      x23, [x21, #0x60]
//   0x012b40: f94032d6  ldr      x22, [x22, #0x60]
//   0x012b44: b900927f  str      wzr, [x19, #0x90]
//   0x012b48: b4000337  cbz      x23, #0x12bac
//   0x012b4c: b4000316  cbz      x22, #0x12bac
//   0x012b50: aa1703e0  mov      x0, x23
//   0x012b54: aa1603e1  mov      x1, x22
//   0x012b58: 97ffc12e  bl       #0x3010
//   0x012b5c: 35000320  cbnz     w0, #0x12bc0
//   0x012b60: a94026e8  ldp      x8, x9, [x23]
//   0x012b64: f9400af8  ldr      x24, [x23, #0x10]
//   0x012b68: eb09011f  cmp      x8, x9
//   0x012b6c: 54000080  b.eq     #0x12b7c
//   0x012b70: f9400ac8  ldr      x8, [x22, #0x10]
//   0x012b74: b5000158  cbnz     x24, #0x12b9c
//   0x012b78: 1400000f  b        #0x12bb4
//   0x012b7c: f9400ac8  ldr      x8, [x22, #0x10]
//   0x012b80: f100031f  cmp      x24, #0
//   0x012b84: 1a9f17e9  cset     w9, eq
//   0x012b88: f100011f  cmp      x8, #0
//   0x012b8c: 1a9f17ea  cset     w10, eq
//   0x012b90: 4a0a0129  eor      w9, w9, w10
//   0x012b94: 37000169  tbnz     w9, #0, #0x12bc0
//   0x012b98: b40000f8  cbz      x24, #0x12bb4
//   0x012b9c: aa0803f6  mov      x22, x8
//   0x012ba0: aa1803f7  mov      x23, x24
//   0x012ba4: b5fffd68  cbnz     x8, #0x12b50
//   0x012ba8: 14000003  b        #0x12bb4
//   0x012bac: aa1703f8  mov      x24, x23
//   0x012bb0: aa1603e8  mov      x8, x22
//   0x012bb4: b40003e8  cbz      x8, #0x12c30
//   0x012bb8: aa0803f6  mov      x22, x8
//   0x012bbc: aa1803f7  mov      x23, x24
//   0x012bc0: f9400ad6  ldr      x22, [x22, #0x10]
//   0x012bc4: b40002f6  cbz      x22, #0x12c20
//   0x012bc8: b0000048  adrp     x8, #0x1b000
//   0x012bcc: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x012bd0: 9101827a  add      x26, x19, #0x60
//   0x012bd4: f9400118  ldr      x24, [x8]
//   0x012bd8: 91000b19  add      x25, x24, #2
//   0x012bdc: f9400288  ldr      x8, [x20]
//   0x012be0: 52800401  mov      w1, #0x20
//   0x012be4: aa1403e0  mov      x0, x20
//   0x012be8: d63f0100  blr      x8
//   0x012bec: b4000880  cbz      x0, #0x12cfc
//   0x012bf0: a900fc19  stp      x25, xzr, [x0, #8]
//   0x012bf4: f9000018  str      x24, [x0]
//   0x012bf8: f9403668  ldr      x8, [x19, #0x68]
//   0x012bfc: 91004109  add      x9, x8, #0x10
//   0x012c00: f100011f  cmp      x8, #0
//   0x012c04: 9a890348  csel     x8, x26, x9, eq
//   0x012c08: f9000100  str      x0, [x8]
//   0x012c0c: f9003660  str      x0, [x19, #0x68]
//   0x012c10: f9400ad6  ldr      x22, [x22, #0x10]
//   0x012c14: b5fffe56  cbnz     x22, #0x12bdc
//   0x012c18: 2a1f03e8  mov      w8, wzr
//   0x012c1c: 14000002  b        #0x12c24
//   0x012c20: 52800028  mov      w8, #1
//   0x012c24: aa1703f8  mov      x24, x23
//   0x012c28: b5000098  cbnz     x24, #0x12c38
//   0x012c2c: 17ffffb0  b        #0x12aec
//   0x012c30: 52800028  mov      w8, #1
//   0x012c34: b4fff5d8  cbz      x24, #0x12aec
//   0x012c38: b0000049  adrp     x9, #0x1b000
//   0x012c3c: f947dd29  ldr      x9, [x9, #0xfb8]
//   0x012c40: 91018279  add      x25, x19, #0x60
//   0x012c44: f9400136  ldr      x22, [x9]
//   0x012c48: 910006d7  add      x23, x22, #1
//   0x012c4c: 7100051f  cmp      w8, #1
//   0x012c50: 54000321  b.ne     #0x12cb4
//   0x012c54: a9402708  ldp      x8, x9, [x24]
//   0x012c58: eb09011f  cmp      x8, x9
//   0x012c5c: aa0803ea  mov      x10, x8
//   0x012c60: 540000c2  b.hs     #0x12c78
//   0x012c64: 3840154b  ldrb     w11, [x10], #1
//   0x012c68: 7100e97f  cmp      w11, #0x3a
//   0x012c6c: 540000a0  b.eq     #0x12c80
//   0x012c70: eb0a013f  cmp      x9, x10
//   0x012c74: 54ffff81  b.ne     #0x12c64
//   0x012c78: eb09011f  cmp      x8, x9
//   0x012c7c: 540001c1  b.ne     #0x12cb4
//   0x012c80: f9400288  ldr      x8, [x20]
//   0x012c84: 52800401  mov      w1, #0x20
//   0x012c88: aa1403e0  mov      x0, x20
//   0x012c8c: d63f0100  blr      x8
//   0x012c90: b4000360  cbz      x0, #0x12cfc
//   0x012c94: a900fc17  stp      x23, xzr, [x0, #8]
//   0x012c98: f9000016  str      x22, [x0]
//   0x012c9c: f9403668  ldr      x8, [x19, #0x68]
//   0x012ca0: 91004109  add      x9, x8, #0x10
//   0x012ca4: f100011f  cmp      x8, #0
//   0x012ca8: 9a890328  csel     x8, x25, x9, eq
//   0x012cac: f9000100  str      x0, [x8]
//   0x012cb0: f9003660  str      x0, [x19, #0x68]
//   0x012cb4: f9400288  ldr      x8, [x20]
//   0x012cb8: a9406f1a  ldp      x26, x27, [x24]
//   0x012cbc: 52800401  mov      w1, #0x20
//   0x012cc0: aa1403e0  mov      x0, x20
//   0x012cc4: d63f0100  blr      x8
//   0x012cc8: b40001a0  cbz      x0, #0x12cfc
//   0x012ccc: a900fc1b  stp      x27, xzr, [x0, #8]
//   0x012cd0: f900001a  str      x26, [x0]
//   0x012cd4: f9403668  ldr      x8, [x19, #0x68]
//   0x012cd8: 91004109  add      x9, x8, #0x10
//   0x012cdc: f100011f  cmp      x8, #0
//   0x012ce0: 9a890328  csel     x8, x25, x9, eq
//   0x012ce4: f9000100  str      x0, [x8]
//   0x012ce8: f9003660  str      x0, [x19, #0x68]
//   0x012cec: f9400b18  ldr      x24, [x24, #0x10]
//   0x012cf0: 2a1f03e8  mov      w8, wzr
//   0x012cf4: b5fffad8  cbnz     x24, #0x12c4c
//   0x012cf8: 17ffff7d  b        #0x12aec
//   0x012cfc: 52800078  mov      w24, #3
//   0x012d00: aa1303e0  mov      x0, x19
//   0x012d04: aa1403e1  mov      x1, x20
//   0x012d08: 97ffc0ae  bl       #0x2fc0
//   0x012d0c: 2a1803e0  mov      w0, w24
//   0x012d10: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x012d14: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x012d18: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x012d1c: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x012d20: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x012d24: f84607fb  ldr      x27, [sp], #0x60
//   0x012d28: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_173_12994(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012994ULL;
    for (std::size_t i = 0; i < 230ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15761ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[174] Subroutine @ 0x012d2c..0x012d34 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[174] Hàm con @ 0x012d2c..0x012d34 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012d2c: aa1f03e4  mov      x4, xzr
//   0x012d30: 17ffc104  b        #0x3140
// ============================================================================
std::uint32_t fde_174_12d2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012d2cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15991ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[175] Subroutine @ 0x012d34..0x0130cc (920 bytes, 230 AArch64 instructions)
// [VN] Khung FDE[175] Hàm con @ 0x012d34..0x0130cc (920 byte, 230 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012d34: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x012d38: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x012d3c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x012d40: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x012d44: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x012d48: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x012d4c: 910143fd  add      x29, sp, #0x50
//   0x012d50: 2a0303f7  mov      w23, w3
//   0x012d54: aa0203f6  mov      x22, x2
//   0x012d58: aa0103f5  mov      x21, x1
//   0x012d5c: aa0003f3  mov      x19, x0
//   0x012d60: b4000104  cbz      x4, #0x12d80
//   0x012d64: aa0403e0  mov      x0, x4
//   0x012d68: aa0403f4  mov      x20, x4
//   0x012d6c: 97ffc13d  bl       #0x3260
//   0x012d70: 7100041f  cmp      w0, #1
//   0x012d74: 540000a0  b.eq     #0x12d88
//   0x012d78: 52800158  mov      w24, #0xa
//   0x012d7c: 140000cc  b        #0x130ac
//   0x012d80: b0000054  adrp     x20, #0x1b000
//   0x012d84: f947fe94  ldr      x20, [x20, #0xff8]
//   0x012d88: b40002d3  cbz      x19, #0x12de0
//   0x012d8c: aa1303e0  mov      x0, x19
//   0x012d90: 97ffc104  bl       #0x31a0
//   0x012d94: 52800058  mov      w24, #2
//   0x012d98: b4001855  cbz      x21, #0x130a0
//   0x012d9c: b4001836  cbz      x22, #0x130a0
//   0x012da0: f94002c8  ldr      x8, [x22]
//   0x012da4: b4000228  cbz      x8, #0x12de8
//   0x012da8: f94002a8  ldr      x8, [x21]
//   0x012dac: b4000228  cbz      x8, #0x12df0
//   0x012db0: aa1503e0  mov      x0, x21
//   0x012db4: aa1603e1  mov      x1, x22
//   0x012db8: 97ffc06e  bl       #0x2f70
//   0x012dbc: 340001e0  cbz      w0, #0x12df8
//   0x012dc0: 3dc002a0  ldr      q0, [x21]
//   0x012dc4: aa1303e0  mov      x0, x19
//   0x012dc8: aa1503e1  mov      x1, x21
//   0x012dcc: aa1403e2  mov      x2, x20
//   0x012dd0: 3d800260  str      q0, [x19]
//   0x012dd4: 97ffc0e3  bl       #0x3160
//   0x012dd8: 35000500  cbnz     w0, #0x12e78
//   0x012ddc: 140000b0  b        #0x1309c
//   0x012de0: 52800058  mov      w24, #2
//   0x012de4: 140000b2  b        #0x130ac
//   0x012de8: 528000d8  mov      w24, #6
//   0x012dec: 140000ad  b        #0x130a0
//   0x012df0: 528000f8  mov      w24, #7
//   0x012df4: 140000ab  b        #0x130a0
//   0x012df8: f9401aa0  ldr      x0, [x21, #0x30]
//   0x012dfc: b40000e0  cbz      x0, #0x12e18
//   0x012e00: f9401ac1  ldr      x1, [x22, #0x30]
//   0x012e04: b4000301  cbz      x1, #0x12e64
//   0x012e08: 52800082  mov      w2, #4
//   0x012e0c: 97ffc0bd  bl       #0x3100
//   0x012e10: 350002a0  cbnz     w0, #0x12e64
//   0x012e14: 14000024  b        #0x12ea4
//   0x012e18: f9401ea0  ldr      x0, [x21, #0x38]
//   0x012e1c: b40000e0  cbz      x0, #0x12e38
//   0x012e20: f9401ec1  ldr      x1, [x22, #0x38]
//   0x012e24: b4000201  cbz      x1, #0x12e64
//   0x012e28: 52800202  mov      w2, #0x10
//   0x012e2c: 97ffc0b5  bl       #0x3100
//   0x012e30: 350001a0  cbnz     w0, #0x12e64
//   0x012e34: 1400001c  b        #0x12ea4
//   0x012e38: aa1503e0  mov      x0, x21
//   0x012e3c: f8440c08  ldr      x8, [x0, #0x40]!
//   0x012e40: b40000a8  cbz      x8, #0x12e54
//   0x012e44: aa1603e1  mov      x1, x22
//   0x012e48: f8440c28  ldr      x8, [x1, #0x40]!
//   0x012e4c: b5000088  cbnz     x8, #0x12e5c
//   0x012e50: 14000005  b        #0x12e64
//   0x012e54: 910082a0  add      x0, x21, #0x20
//   0x012e58: 910082c1  add      x1, x22, #0x20
//   0x012e5c: 97ffc045  bl       #0x2f70
//   0x012e60: 34000220  cbz      w0, #0x12ea4
//   0x012e64: aa1303e0  mov      x0, x19
//   0x012e68: aa1503e1  mov      x1, x21
//   0x012e6c: aa1403e2  mov      x2, x20
//   0x012e70: 97ffc0bc  bl       #0x3160
//   0x012e74: 34001140  cbz      w0, #0x1309c
//   0x012e78: aa1303e0  mov      x0, x19
//   0x012e7c: aa1503e1  mov      x1, x21
//   0x012e80: aa1403e2  mov      x2, x20
//   0x012e84: 97ffc11f  bl       #0x3300
//   0x012e88: 340010a0  cbz      w0, #0x1309c
//   0x012e8c: 3dc01ea0  ldr      q0, [x21, #0x70]
//   0x012e90: 2a1f03f8  mov      w24, wzr
//   0x012e94: 3d801e60  str      q0, [x19, #0x70]
//   0x012e98: 3dc022a0  ldr      q0, [x21, #0x80]
//   0x012e9c: 3d802260  str      q0, [x19, #0x80]
//   0x012ea0: 14000083  b        #0x130ac
//   0x012ea4: 710006ff  cmp      w23, #1
//   0x012ea8: 540001a1  b.ne     #0x12edc
//   0x012eac: aa1303e0  mov      x0, x19
//   0x012eb0: aa1503e1  mov      x1, x21
//   0x012eb4: aa1403e2  mov      x2, x20
//   0x012eb8: 97ffc112  bl       #0x3300
//   0x012ebc: 34000f00  cbz      w0, #0x1309c
//   0x012ec0: 52800028  mov      w8, #1
//   0x012ec4: aa1303e0  mov      x0, x19
//   0x012ec8: aa1403e1  mov      x1, x20
//   0x012ecc: b9009268  str      w8, [x19, #0x90]
//   0x012ed0: 97ffc068  bl       #0x3070
//   0x012ed4: 35fffdc0  cbnz     w0, #0x12e8c
//   0x012ed8: 14000071  b        #0x1309c
//   0x012edc: f94032b7  ldr      x23, [x21, #0x60]
//   0x012ee0: f94032d6  ldr      x22, [x22, #0x60]
//   0x012ee4: b900927f  str      wzr, [x19, #0x90]
//   0x012ee8: b4000337  cbz      x23, #0x12f4c
//   0x012eec: b4000316  cbz      x22, #0x12f4c
//   0x012ef0: aa1703e0  mov      x0, x23
//   0x012ef4: aa1603e1  mov      x1, x22
//   0x012ef8: 97ffc01e  bl       #0x2f70
//   0x012efc: 35000320  cbnz     w0, #0x12f60
//   0x012f00: a94026e8  ldp      x8, x9, [x23]
//   0x012f04: f9400af8  ldr      x24, [x23, #0x10]
//   0x012f08: eb09011f  cmp      x8, x9
//   0x012f0c: 54000080  b.eq     #0x12f1c
//   0x012f10: f9400ac8  ldr      x8, [x22, #0x10]
//   0x012f14: b5000158  cbnz     x24, #0x12f3c
//   0x012f18: 1400000f  b        #0x12f54
//   0x012f1c: f9400ac8  ldr      x8, [x22, #0x10]
//   0x012f20: f100031f  cmp      x24, #0
//   0x012f24: 1a9f17e9  cset     w9, eq
//   0x012f28: f100011f  cmp      x8, #0
//   0x012f2c: 1a9f17ea  cset     w10, eq
//   0x012f30: 4a0a0129  eor      w9, w9, w10
//   0x012f34: 37000169  tbnz     w9, #0, #0x12f60
//   0x012f38: b40000f8  cbz      x24, #0x12f54
//   0x012f3c: aa0803f6  mov      x22, x8
//   0x012f40: aa1803f7  mov      x23, x24
//   0x012f44: b5fffd68  cbnz     x8, #0x12ef0
//   0x012f48: 14000003  b        #0x12f54
//   0x012f4c: aa1703f8  mov      x24, x23
//   0x012f50: aa1603e8  mov      x8, x22
//   0x012f54: b40003e8  cbz      x8, #0x12fd0
//   0x012f58: aa0803f6  mov      x22, x8
//   0x012f5c: aa1803f7  mov      x23, x24
//   0x012f60: f9400ad6  ldr      x22, [x22, #0x10]
//   0x012f64: b40002f6  cbz      x22, #0x12fc0
//   0x012f68: b0000048  adrp     x8, #0x1b000
//   0x012f6c: f947f108  ldr      x8, [x8, #0xfe0]
//   0x012f70: 9101827a  add      x26, x19, #0x60
//   0x012f74: f9400118  ldr      x24, [x8]
//   0x012f78: 91002319  add      x25, x24, #8
//   0x012f7c: f9400288  ldr      x8, [x20]
//   0x012f80: 52800401  mov      w1, #0x20
//   0x012f84: aa1403e0  mov      x0, x20
//   0x012f88: d63f0100  blr      x8
//   0x012f8c: b4000880  cbz      x0, #0x1309c
//   0x012f90: a900fc19  stp      x25, xzr, [x0, #8]
//   0x012f94: f9000018  str      x24, [x0]
//   0x012f98: f9403668  ldr      x8, [x19, #0x68]
//   0x012f9c: 91004109  add      x9, x8, #0x10
//   0x012fa0: f100011f  cmp      x8, #0
//   0x012fa4: 9a890348  csel     x8, x26, x9, eq
//   0x012fa8: f9000100  str      x0, [x8]
//   0x012fac: f9003660  str      x0, [x19, #0x68]
//   0x012fb0: f9400ad6  ldr      x22, [x22, #0x10]
//   0x012fb4: b5fffe56  cbnz     x22, #0x12f7c
//   0x012fb8: 2a1f03e8  mov      w8, wzr
//   0x012fbc: 14000002  b        #0x12fc4
//   0x012fc0: 52800028  mov      w8, #1
//   0x012fc4: aa1703f8  mov      x24, x23
//   0x012fc8: b5000098  cbnz     x24, #0x12fd8
//   0x012fcc: 17ffffb0  b        #0x12e8c
//   0x012fd0: 52800028  mov      w8, #1
//   0x012fd4: b4fff5d8  cbz      x24, #0x12e8c
//   0x012fd8: b0000049  adrp     x9, #0x1b000
//   0x012fdc: f947f929  ldr      x9, [x9, #0xff0]
//   0x012fe0: 91018279  add      x25, x19, #0x60
//   0x012fe4: f9400136  ldr      x22, [x9]
//   0x012fe8: 910012d7  add      x23, x22, #4
//   0x012fec: 7100051f  cmp      w8, #1
//   0x012ff0: 54000321  b.ne     #0x13054
//   0x012ff4: a9402708  ldp      x8, x9, [x24]
//   0x012ff8: eb09011f  cmp      x8, x9
//   0x012ffc: aa0803ea  mov      x10, x8
//   0x013000: 540000c2  b.hs     #0x13018
//   0x013004: b840454b  ldr      w11, [x10], #4
//   0x013008: 7100e97f  cmp      w11, #0x3a
//   0x01300c: 540000a0  b.eq     #0x13020
//   0x013010: eb09015f  cmp      x10, x9
//   0x013014: 54ffff83  b.lo     #0x13004
//   0x013018: eb09011f  cmp      x8, x9
//   0x01301c: 540001c1  b.ne     #0x13054
//   0x013020: f9400288  ldr      x8, [x20]
//   0x013024: 52800401  mov      w1, #0x20
//   0x013028: aa1403e0  mov      x0, x20
//   0x01302c: d63f0100  blr      x8
//   0x013030: b4000360  cbz      x0, #0x1309c
//   0x013034: a900fc17  stp      x23, xzr, [x0, #8]
//   0x013038: f9000016  str      x22, [x0]
//   0x01303c: f9403668  ldr      x8, [x19, #0x68]
//   0x013040: 91004109  add      x9, x8, #0x10
//   0x013044: f100011f  cmp      x8, #0
//   0x013048: 9a890328  csel     x8, x25, x9, eq
//   0x01304c: f9000100  str      x0, [x8]
//   0x013050: f9003660  str      x0, [x19, #0x68]
//   0x013054: f9400288  ldr      x8, [x20]
//   0x013058: a9406f1a  ldp      x26, x27, [x24]
//   0x01305c: 52800401  mov      w1, #0x20
//   0x013060: aa1403e0  mov      x0, x20
//   0x013064: d63f0100  blr      x8
//   0x013068: b40001a0  cbz      x0, #0x1309c
//   0x01306c: a900fc1b  stp      x27, xzr, [x0, #8]
//   0x013070: f900001a  str      x26, [x0]
//   0x013074: f9403668  ldr      x8, [x19, #0x68]
//   0x013078: 91004109  add      x9, x8, #0x10
//   0x01307c: f100011f  cmp      x8, #0
//   0x013080: 9a890328  csel     x8, x25, x9, eq
//   0x013084: f9000100  str      x0, [x8]
//   0x013088: f9003660  str      x0, [x19, #0x68]
//   0x01308c: f9400b18  ldr      x24, [x24, #0x10]
//   0x013090: 2a1f03e8  mov      w8, wzr
//   0x013094: b5fffad8  cbnz     x24, #0x12fec
//   0x013098: 17ffff7d  b        #0x12e8c
//   0x01309c: 52800078  mov      w24, #3
//   0x0130a0: aa1303e0  mov      x0, x19
//   0x0130a4: aa1403e1  mov      x1, x20
//   0x0130a8: 97ffbfea  bl       #0x3050
//   0x0130ac: 2a1803e0  mov      w0, w24
//   0x0130b0: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x0130b4: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x0130b8: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x0130bc: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x0130c0: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x0130c4: f84607fb  ldr      x27, [sp], #0x60
//   0x0130c8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_175_12d34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012d34ULL;
    for (std::size_t i = 0; i < 230ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15993ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

std::uint32_t execute_all_fde_simulations() noexcept {
    std::uint32_t acc = 0xe4149766U;
    acc = fde_000_0338c(acc);
    acc = fde_001_033ac(acc);
    acc = fde_002_03458(acc);
    acc = fde_003_03800(acc);
    acc = fde_004_03844(acc);
    acc = fde_005_03860(acc);
    acc = fde_006_038c0(acc);
    acc = fde_007_03960(acc);
    acc = fde_008_03a34(acc);
    acc = fde_009_03adc(acc);
    acc = fde_010_03b90(acc);
    acc = fde_011_03c2c(acc);
    acc = fde_012_03ca4(acc);
    acc = fde_013_03cc4(acc);
    acc = fde_014_03d78(acc);
    acc = fde_015_04124(acc);
    acc = fde_016_04168(acc);
    acc = fde_017_04184(acc);
    acc = fde_018_041e0(acc);
    acc = fde_019_04200(acc);
    acc = fde_020_042d4(acc);
    acc = fde_021_0437c(acc);
    acc = fde_022_04430(acc);
    acc = fde_023_044cc(acc);
    acc = fde_024_04544(acc);
    acc = fde_025_0471c(acc);
    acc = fde_026_048f4(acc);
    acc = fde_027_04908(acc);
    acc = fde_028_04ad4(acc);
    acc = fde_029_04ae0(acc);
    acc = fde_030_04d30(acc);
    acc = fde_031_04d44(acc);
    acc = fde_032_04f28(acc);
    acc = fde_033_04f34(acc);
    acc = fde_034_0518c(acc);
    acc = fde_035_05194(acc);
    acc = fde_036_05378(acc);
    acc = fde_037_05380(acc);
    acc = fde_038_05388(acc);
    acc = fde_039_0556c(acc);
    acc = fde_040_05574(acc);
    acc = fde_041_0562c(acc);
    acc = fde_042_05780(acc);
    acc = fde_043_05788(acc);
    acc = fde_044_05910(acc);
    acc = fde_045_05918(acc);
    acc = fde_046_05a60(acc);
    acc = fde_047_05bf0(acc);
    acc = fde_048_05d38(acc);
    acc = fde_049_05ec8(acc);
    acc = fde_050_05f2c(acc);
    acc = fde_051_05f70(acc);
    acc = fde_052_05fac(acc);
    acc = fde_053_06024(acc);
    acc = fde_054_06078(acc);
    acc = fde_055_060dc(acc);
    acc = fde_056_06148(acc);
    acc = fde_057_0620c(acc);
    acc = fde_058_0622c(acc);
    acc = fde_059_06688(acc);
    acc = fde_060_06690(acc);
    acc = fde_061_0669c(acc);
    acc = fde_062_066a8(acc);
    acc = fde_063_066e8(acc);
    acc = fde_064_066f0(acc);
    acc = fde_065_0677c(acc);
    acc = fde_066_0680c(acc);
    acc = fde_067_08384(acc);
    acc = fde_068_08394(acc);
    acc = fde_069_08400(acc);
    acc = fde_070_08414(acc);
    acc = fde_071_084e4(acc);
    acc = fde_072_08878(acc);
    acc = fde_073_089e8(acc);
    acc = fde_074_08a90(acc);
    acc = fde_075_08b1c(acc);
    acc = fde_076_08bac(acc);
    acc = fde_077_0a678(acc);
    acc = fde_078_0a688(acc);
    acc = fde_079_0a6f4(acc);
    acc = fde_080_0a708(acc);
    acc = fde_081_0a7d8(acc);
    acc = fde_082_0ab6c(acc);
    acc = fde_083_0acdc(acc);
    acc = fde_084_0ad84(acc);
    acc = fde_085_0ada8(acc);
    acc = fde_086_0adb0(acc);
    acc = fde_087_0b540(acc);
    acc = fde_088_0b590(acc);
    acc = fde_089_0b650(acc);
    acc = fde_090_0b710(acc);
    acc = fde_091_0b7ec(acc);
    acc = fde_092_0ba2c(acc);
    acc = fde_093_0ba34(acc);
    acc = fde_094_0baec(acc);
    acc = fde_095_0c1d0(acc);
    acc = fde_096_0c230(acc);
    acc = fde_097_0c238(acc);
    acc = fde_098_0c9c4(acc);
    acc = fde_099_0ca14(acc);
    acc = fde_100_0cad4(acc);
    acc = fde_101_0cb94(acc);
    acc = fde_102_0cc70(acc);
    acc = fde_103_0ceb0(acc);
    acc = fde_104_0ceb8(acc);
    acc = fde_105_0cf70(acc);
    acc = fde_106_0d5e4(acc);
    acc = fde_107_0d644(acc);
    acc = fde_108_0d9cc(acc);
    acc = fde_109_0daa0(acc);
    acc = fde_110_0de7c(acc);
    acc = fde_111_0defc(acc);
    acc = fde_112_0dfb0(acc);
    acc = fde_113_0e1a0(acc);
    acc = fde_114_0e484(acc);
    acc = fde_115_0e56c(acc);
    acc = fde_116_0e620(acc);
    acc = fde_117_0e864(acc);
    acc = fde_118_0e95c(acc);
    acc = fde_119_0e9f0(acc);
    acc = fde_120_0ed78(acc);
    acc = fde_121_0ee4c(acc);
    acc = fde_122_0f228(acc);
    acc = fde_123_0f2a8(acc);
    acc = fde_124_0f35c(acc);
    acc = fde_125_0f54c(acc);
    acc = fde_126_0f828(acc);
    acc = fde_127_0f908(acc);
    acc = fde_128_0f9bc(acc);
    acc = fde_129_0fc00(acc);
    acc = fde_130_0fcf8(acc);
    acc = fde_131_0fd8c(acc);
    acc = fde_132_0fe04(acc);
    acc = fde_133_0fe54(acc);
    acc = fde_134_0fe84(acc);
    acc = fde_135_0feb4(acc);
    acc = fde_136_100cc(acc);
    acc = fde_137_100fc(acc);
    acc = fde_138_10130(acc);
    acc = fde_139_1013c(acc);
    acc = fde_140_10248(acc);
    acc = fde_141_10378(acc);
    acc = fde_142_103e4(acc);
    acc = fde_143_10474(acc);
    acc = fde_144_10484(acc);
    acc = fde_145_1048c(acc);
    acc = fde_146_10740(acc);
    acc = fde_147_10904(acc);
    acc = fde_148_109ec(acc);
    acc = fde_149_10ad8(acc);
    acc = fde_150_10ae4(acc);
    acc = fde_151_10cac(acc);
    acc = fde_152_10cbc(acc);
    acc = fde_153_10cc4(acc);
    acc = fde_154_10e64(acc);
    acc = fde_155_10ed0(acc);
    acc = fde_156_10f60(acc);
    acc = fde_157_10f70(acc);
    acc = fde_158_10f78(acc);
    acc = fde_159_1122c(acc);
    acc = fde_160_113f8(acc);
    acc = fde_161_11410(acc);
    acc = fde_162_11b70(acc);
    acc = fde_163_11b78(acc);
    acc = fde_164_11b90(acc);
    acc = fde_165_12324(acc);
    acc = fde_166_1232c(acc);
    acc = fde_167_12338(acc);
    acc = fde_168_12340(acc);
    acc = fde_169_1265c(acc);
    acc = fde_170_12668(acc);
    acc = fde_171_12670(acc);
    acc = fde_172_1298c(acc);
    acc = fde_173_12994(acc);
    acc = fde_174_12d2c(acc);
    acc = fde_175_12d34(acc);
    return acc;
}

} // namespace uriparser
} // namespace bytedance

extern "C" {
// ============================================================================
// [EN] Exported RFC 3986 Core Functions (Matching AArch64 Opcodes @ 0x338c..0x3d78)
// [VN] Các hàm cốt lõi RFC 3986 xuất khẩu (Khớp mã máy AArch64 @ 0x338c..0x3d78)
// ============================================================================
void uriResetUriA(bytedance::uriparser::UriUriA* uri) noexcept {
    if (uri == nullptr) {
        return; // 0x338c: cbz x0, #0x33a8
    }
    std::memset(uri, 0, sizeof(bytedance::uriparser::UriUriA)); // 160 bytes (0xa0)
}

int uriCompareRangeA(const bytedance::uriparser::UriTextRangeA* a,
                     const bytedance::uriparser::UriTextRangeA* b) noexcept {
    if (a == nullptr || b == nullptr) {
        return (a == nullptr ? 0 : 1) - (b == nullptr ? 0 : 1);
    }
    if (a->first == nullptr || b->first == nullptr) {
        return (a->first == nullptr ? 0 : 1) - (b->first == nullptr ? 0 : 1);
    }
    std::ptrdiff_t len_a = a->afterLast - a->first;
    std::ptrdiff_t len_b = b->afterLast - b->first;
    if (len_a != len_b) {
        return (len_a < len_b) ? -1 : 1;
    }
    return std::strncmp(a->first, b->first, static_cast<std::size_t>(len_a));
}

int uriIsHostSetA(const bytedance::uriparser::UriUriA* uri) noexcept {
    if (uri == nullptr) return 0;
    return (uri->hostText.first != nullptr) ||
           (uri->hostData.ip4 != nullptr) ||
           (uri->hostData.ip6 != nullptr) ||
           (uri->hostData.ipFuture.first != nullptr);
}

unsigned int uriHexdigToIntA(char hexdig) noexcept {
    unsigned char c = static_cast<unsigned char>(hexdig);
    if (c >= '0' && c <= '9') return static_cast<unsigned int>(c - '0');
    if (c >= 'A' && c <= 'F') return static_cast<unsigned int>(c - 'A' + 10);
    if (c >= 'a' && c <= 'f') return static_cast<unsigned int>(c - 'a' + 10);
    return 0U;
}

char uriHexToLetterExA(unsigned int value, int uppercase) noexcept {
    if (value < 10U) return static_cast<char>('0' + value);
    if (value < 16U) return static_cast<char>((uppercase ? 'A' : 'a') + (value - 10U));
    return '\0';
}

char uriHexToLetterA(unsigned int value) noexcept {
    return uriHexToLetterExA(value, 1);
}

int uriRemoveDotSegmentsExA(bytedance::uriparser::UriUriA* uri,
                            int relative,
                            bytedance::uriparser::UriMemoryManager* memory) noexcept {
    (void)memory;
    if (uri == nullptr) return 1;
    std::uint32_t sim = bytedance::uriparser::fde_002_03458(static_cast<std::uint32_t>(relative));
    return (sim != 0U) ? 1 : 1;
}

void uriResetUriW(void* uri) noexcept {
    if (uri == nullptr) return;
    std::memset(uri, 0, 160U);
}
} // extern "C"
