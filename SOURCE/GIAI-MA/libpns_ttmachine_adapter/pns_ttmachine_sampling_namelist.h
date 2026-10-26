/**
 * @file pns_ttmachine_sampling_namelist.h
 * @brief MT19937 Network Sampling, NameList Matching & URL/Domain Engine for libpns_ttmachine_adapter.so
 *        Bộ lấy mẫu mạng MT19937, Khớp danh sách tên & Phân tích URL/Domain cho libpns_ttmachine_adapter.so
 *
 * Disassembly Reference / Tham chiếu Disassembly:
 *   - 0x007ed4..0x008020: CityHash64 / MurmurHash64A string hash for deterministic seed
 *   - 0x00fbe8..0x00fc78: Split/tokenize string into vector<string> for NameList matching
 *   - 0x0318a8..0x0319d4: load_const_pool_extra_json (parses "common" & "incremental_list")
 *   - 0x0360f0..0x036238: _Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct
 *   - 0x03623c..0x0363bc: _Z5isHitPd (624-word MT19937 + 64-bit uniform [0,1) double)
 *   - 0x0363c0..0x0365e0: _Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct
 *   - 0x0365e4..0x0368e0: _Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct
 *   - 0x0368e4..0x036ea8: _Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct
 *   - 0x036eac..0x03708c: _Z10randomSeedPlPPvPdP22__TTMTransparentStruct
 *   - 0x03963c..0x039810: namelist_find_container (thread-safe rwlock lookup at 0x055778)
 *   - 0x03ac80..0x03aeec: namelist_match_entry (6-way jump table at 0x03add4 via 0x0437b6)
 */

#ifndef NEXTAI_OPENCUT_PNS_TTMACHINE_SAMPLING_NAMELIST_H_
#define NEXTAI_OPENCUT_PNS_TTMACHINE_SAMPLING_NAMELIST_H_

#include "pns_ttmachine_types.h"
#include <pthread.h>

namespace pns {
namespace ttmachine {

// ============================================================================
// 1. Bit-Exact MT19937 & String Hash Algorithms (0x007ed4, 0x03623c, 0x036eac)
//    Thuật toán MT19937 & Băm chuỗi chuẩn xác từng bit (0x007ed4, 0x03623c, 0x036eac)
// ============================================================================

/**
 * Computes the 64-bit string hash used by _Z10randomSeedPlPPvPdP22__TTMTransparentStruct
 * at 0x036fc0 (bl #0x7ed4: std::__ndk1::__murmur2_or_cityhash<uint64_t, 64>).
 * Tính giá trị băm chuỗi 64-bit được sử dụng bởi _Z10randomSeed tại 0x036fc0 (bl #0x7ed4).
 */
uint64_t ComputeNdkStringHash64(const char* data, size_t len) noexcept;

/**
 * Executes the exact 624-word MT19937 initialization and 2-word twist/tempering
 * from _Z5isHitPd (0x036280..0x036388) for a given 32-bit seed.
 * Thực thi khởi tạo MT19937 624 từ và xoắn/tôi luyện 2 từ chuẩn xác từ _Z5isHitPd (0x036280..0x036388).
 */
double GenerateMt19937UniformDouble(uint32_t seed) noexcept;

/**
 * Deterministic MT19937 sampling with string seed (0x036eac..0x03708c).
 * Lấy mẫu xác định MT19937 với hạt giống chuỗi (0x036eac..0x03708c).
 */
bool EvaluateDeterministicSeedSample(const char* seed_str, double sample_rate) noexcept;

// ============================================================================
// 2. NameListManager Singleton (0x055768..0x0557a8)
//    Quản lý danh sách tên đơn bản NameListManager (0x055768..0x0557a8)
// ============================================================================
class NameListManager {
public:
    static NameListManager& Instance();

    // Parses JSON incremental_list / common config (0x0318a8..0x0319d4)
    // Phân tích cấu hình JSON incremental_list / common (0x0318a8..0x0319d4)
    bool LoadConstPoolExtraJson(const char* json_str);

    // Registers or updates a NameListContainer (0x038174)
    // Đăng ký hoặc cập nhật một NameListContainer (0x038174)
    void RegisterContainer(const std::string& key, std::shared_ptr<NameListContainer> container);

    // Looks up a NameListContainer under pthread_rwlock_rdlock (0x03963c)
    // Tra cứu NameListContainer dưới khóa đọc pthread_rwlock_rdlock (0x03963c)
    std::shared_ptr<NameListContainer> FindContainer(const char* name_list_key) const;

    // Status code at 0x055770: 0 = uninitialized, 1 = loading, 2 = ready, 3 = error
    // Mã trạng thái tại 0x055770: 0 = chưa khởi tạo, 1 = đang tải, 2 = sẵn sàng, 3 = lỗi
    int32_t GetPrepareStatus() const noexcept { return prepare_status_.load(std::memory_order_acquire); }
    void SetPrepareStatus(int32_t status) noexcept { prepare_status_.store(status, std::memory_order_release); }

    // Tokenizes a string or domain/path into segments (0x00fbe8)
    // Tách chuỗi hoặc domain/path thành danh sách các phân đoạn (0x00fbe8)
    static std::vector<std::string> TokenizeValue(const char* c_str);

    // Resets all containers (used in tests and re-initialization)
    // Đặt lại toàn bộ container (dùng trong kiểm thử và khởi tạo lại)
    void Clear();

private:
    NameListManager();
    ~NameListManager();

    mutable pthread_rwlock_t rwlock_;
    std::atomic<int32_t> prepare_status_{0};
    std::unordered_map<std::string, std::shared_ptr<NameListContainer>> containers_;
};

// ============================================================================
// 3. URL & Domain Parsing Functions Registered in 0x014598
//    Các hàm phân tích URL & Domain đăng ký tại 0x014598
// ============================================================================
std::string UrlDecode(const std::string& encoded);
std::string ExtractUrlScheme(const std::string& url);
std::string ExtractUrlQueryString(const std::string& url);
std::string ExtractSecondLevelDomain(const std::string& host_or_url);
std::vector<std::string> ExtractUrlsSecondLevelDomains(const std::vector<std::string>& urls);
bool IsIpAddress(const std::string& host);
bool IsValidDomain(const std::string& host);
int32_t CompareVersionStrings(const std::string& v1, const std::string& v2);

} // namespace ttmachine
} // namespace pns

// ============================================================================
// 4. Exported C++ Mangled TTMachine Symbols (Exact ABI Signatures)
//    Các ký hiệu C++ Mangled xuất ra cho TTMachine (Chữ ký ABI chính xác)
// ============================================================================
extern "C" {

// 0x0360f0 (332 B): _Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct
JNIEXPORT void _Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct(
    void** out_list_obj,
    double* stack_rate,
    double* header_fields_rate,
    double* query_fields_rate,
    double* cookie_fields_rate,
    double* body_fields_rate,
    __TTMTransparentStruct* ttm_ctx);

// 0x03623c (388 B): _Z5isHitPd
JNIEXPORT bool _Z5isHitPd(double* sample_rate);

// 0x0363c0 (548 B): _Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct
JNIEXPORT void _Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct(
    long* out_result,
    void** param_val_obj,
    void** name_list_key_obj,
    long* strict_ready_flag,
    __TTMTransparentStruct* ttm_ctx);

// 0x0365e4 (768 B): _Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct
JNIEXPORT void _Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct(
    long* out_result,
    void** domain_val_obj,
    void** path_val_obj,
    void** name_list_key_obj,
    long* strict_ready_flag,
    __TTMTransparentStruct* ttm_ctx);

// 0x0368e4 (1480 B): _Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct
JNIEXPORT void _Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct(
    long* out_result,
    void** domain_val_obj,
    void** path_val_obj,
    void** name_list_key_obj,
    long* strict_ready_flag,
    __TTMTransparentStruct* ttm_ctx);

// 0x036eac (484 B): _Z10randomSeedPlPPvPdP22__TTMTransparentStruct
JNIEXPORT void _Z10randomSeedPlPPvPdP22__TTMTransparentStruct(
    long* out_result,
    void** seed_str_obj,
    double* sample_rate,
    __TTMTransparentStruct* ttm_ctx);

} // extern "C"

#endif // NEXTAI_OPENCUT_PNS_TTMACHINE_SAMPLING_NAMELIST_H_
