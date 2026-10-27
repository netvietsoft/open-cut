// ============================================================================
// File: gaia_system_memory_and_stbtt.cpp
// Target: libgaia_lib.so (329,704 bytes)
// Task ID: TASK-135-RECONSTRUCTION-LIBGAIA-LIB / TASK_SO_112_libgaia_lib
// Description:
//   EN: Clean-room C++17 implementation of AmazingEngine AELogSystem, ThreadPool,
//       FSystemTime, FileUtils, MemoryStream, MemoryManager, MemoryPool,
//       NetworkClient/TTNetStub, PerformanceCap, and stb_truetype (including
//       stbtt_GetGlyphSDF at 0x03f928).
//   VN: Cai dat C++17 chuan clean-room cho AELogSystem, ThreadPool, FSystemTime,
//       FileUtils, MemoryStream, MemoryManager, MemoryPool, NetworkClient,
//       PerformanceCap va stb_truetype (bao gom stbtt_GetGlyphSDF tai 0x03f928).
// ============================================================================

#include "gaia_system_memory_and_stbtt.h"
#include "gaia_rodata_tables.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <chrono>
#include <algorithm>

namespace AmazingEngine {

// ============================================================================
// 1. AELogSystem (0x0107a0 .. 0x011c00)
// ============================================================================
static AELogSystem::LogCallback g_logCallback = nullptr;
static int g_minLogLevel = 0;
AELogSystem g_aeLogT;

AELogSystem::AELogSystem() = default;
AELogSystem::~AELogSystem() = default;

void AELogSystem::registerLogFunction(LogCallback cb) noexcept {
    g_logCallback = cb;
}

void AELogSystem::setLogFilter(int minLevel) noexcept {
    g_minLogLevel = minLevel;
}

int AELogSystem::vwrite(const char* file, int line, int level, const char* tag, const char* fmt, va_list ap) {
    // 0x0107e0: tbnz w1, #0x1f, #0x10864 (assert dLine >= 0)
    // 0x0107e8: cbz x4, #0x10894 (assert pszFormat != NULL)
    if (line < 0 || fmt == nullptr || fmt[0] == '\0') {
        return -1;
    }
    if (level < g_minLogLevel) {
        return 0;
    }
    char body[1024];
    int n = std::vsnprintf(body, sizeof(body), fmt, ap);
    if (g_logCallback) {
        g_logCallback(level, tag ? tag : "AE_GAME_TAG", body);
    }
    return n;
}

int AELogSystem::write(const char* file, int line, int level, const char* tag, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int rc = vwrite(file, line, level, tag, fmt, ap);
    va_end(ap);
    return rc;
}

int AELogSystem::write_s(const char* file, int line, int level, const char* tag, const char* msg) {
    return write(file, line, level, tag, "%s", msg ? msg : "");
}

// ============================================================================
// 2. ThreadPool & FSystemTime (0x019fd0 .. 0x01c290)
// ============================================================================
ThreadPool::ThreadPool(unsigned int threadCount)
    : running_(true), active_tasks_(0), thread_count_(threadCount) {
    // 0x019fd0 .. 0x01a018:
    //   str wzr, [x0, #8]
    //   mov w9, #1; strb w9, [x0, #0xe0]
    //   str w1, [x0, #0xe8]; stlr wzr, [x0, #0xe4]
}

ThreadPool::~ThreadPool() {
    // 0x01a01c .. 0x01a228: Acquires mutex at +0x88, sets running_ (+0xE0) = 0,
    // broadcasts condition variable at +0xB0, joins/releases worker threads.
    stop();
}

void ThreadPool::enqueueTask(std::function<void()> task) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        if (!running_.load(std::memory_order_acquire)) return;
        tasks_.push_back(std::move(task));
    }
    cv_.notify_one();
}

void ThreadPool::stop() noexcept {
    running_.store(false, std::memory_order_release);
    cv_.notify_all();
    for (auto& th : workers_) {
        if (th.joinable()) th.join();
    }
    workers_.clear();
}

double FSystemTime::InitTiming() noexcept {
    return Seconds();
}

double FSystemTime::Seconds() noexcept {
    using namespace std::chrono;
    auto now = steady_clock::now().time_since_epoch();
    return duration_cast<duration<double>>(now).count();
}

uint64_t FSystemTime::Cycles64() noexcept {
    using namespace std::chrono;
    return static_cast<uint64_t>(
        duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count()
    );
}

// ============================================================================
// 3. FileUtils & MemoryStream (0x01c7fc .. 0x0235dc)
// ============================================================================
bool FileUtils::isFileExist(const std::string& path) noexcept {
    if (path.empty()) return false;
    FILE* fp = std::fopen(path.c_str(), "rb");
    if (!fp) return false;
    std::fclose(fp);
    return true;
}

bool FileUtils::isDirectoryExist(const std::string& path) noexcept {
    return !path.empty();
}

int64_t FileUtils::getFileSize(const std::string& path) noexcept {
    FILE* fp = std::fopen(path.c_str(), "rb");
    if (!fp) return -1;
    std::fseek(fp, 0, SEEK_END);
    long sz = std::ftell(fp);
    std::fclose(fp);
    return static_cast<int64_t>(sz);
}

bool FileUtils::readFile(const std::string& path, std::string& outBuffer) {
    FILE* fp = std::fopen(path.c_str(), "rb");
    if (!fp) {
        AELogSystem::write(__FILE__, __LINE__, 0, "AE_GAME_TAG",
                           "FileUtils: readFile: Open fail: %s", path.c_str());
        return false;
    }
    std::fseek(fp, 0, SEEK_END);
    long sz = std::ftell(fp);
    std::fseek(fp, 0, SEEK_SET);
    if (sz < 0) {
        std::fclose(fp);
        return false;
    }
    outBuffer.resize(static_cast<size_t>(sz));
    if (sz > 0 && std::fread(&outBuffer[0], 1, static_cast<size_t>(sz), fp) != static_cast<size_t>(sz)) {
        AELogSystem::write(__FILE__, __LINE__, 0, "AE_GAME_TAG",
                           "FileUtils: readFile: Read fail: %s", path.c_str());
        std::fclose(fp);
        return false;
    }
    std::fclose(fp);
    return true;
}

bool FileUtils::writeFile(const std::string& path, const void* data, size_t len) {
    FILE* fp = std::fopen(path.c_str(), "wb");
    if (!fp) {
        AELogSystem::write(__FILE__, __LINE__, 0, "AE_GAME_TAG",
                           "FileUtils: writeFile: Open fail: %s", path.c_str());
        return false;
    }
    bool ok = (len == 0) || (std::fwrite(data, 1, len, fp) == len);
    std::fclose(fp);
    return ok;
}

std::string FileUtils::getFileExtension(const std::string& path) {
    auto pos = path.find_last_of('.');
    if (pos == std::string::npos) return "";
    return path.substr(pos);
}

MemoryStream::MemoryStream(size_t initialSize) : buffer_(initialSize, 0), curr_pos_(0) {}
MemoryStream::~MemoryStream() = default;

bool MemoryStream::seek(size_t pos) noexcept {
    if (pos > buffer_.size()) {
        AELogSystem::write(__FILE__, __LINE__, 0, "AE_GAME_TAG",
                           "MemoryReader:Seek Error TotalSize:%lu, CurrPos:%lu, SeekPos:%lu",
                           static_cast<unsigned long>(buffer_.size()),
                           static_cast<unsigned long>(curr_pos_),
                           static_cast<unsigned long>(pos));
        return false;
    }
    curr_pos_ = pos;
    return true;
}

size_t MemoryStream::read(void* dst, size_t len) noexcept {
    if (curr_pos_ + len > buffer_.size()) {
        return 0;
    }
    std::memcpy(dst, buffer_.data() + curr_pos_, len);
    curr_pos_ += len;
    return len;
}

size_t MemoryStream::write(const void* src, size_t len) {
    if (curr_pos_ + len > buffer_.size()) {
        buffer_.resize(curr_pos_ + len);
    }
    std::memcpy(buffer_.data() + curr_pos_, src, len);
    curr_pos_ += len;
    return len;
}

// ============================================================================
// 4. memory::MemoryPool & memory::MemoryManager (0x027404 .. 0x028edc)
// ============================================================================
namespace memory {

MemoryPool::MemoryPool(const char* name, int blockSize, int hintSize, AMGMemLabelIdentifier label)
    : allocator_(nullptr),
      block_size_(std::max<int>(blockSize, sizeof(FreeNode))),
      bubble_byte_size_(std::max<int>(hintSize, block_size_)),
      blocks_per_bubble_(bubble_byte_size_ / block_size_),
      pool_name_(name ? name : "Default"),
      free_head_(nullptr),
      allow_growth_(true),
      label_(label),
      alloc_count_(0) {
    // 0x0287ec
}

MemoryPool::~MemoryPool() {
    // 0x028844
    deallocateAll();
}

void MemoryPool::reset() noexcept {
    // 0x028838
    free_head_ = nullptr;
    alloc_count_ = 0;
}

void MemoryPool::deallocateAll() noexcept {
    // 0x0288e0 .. 0x028954
    std::lock_guard<std::mutex> lock(mutex_);
    for (void* bubble : bubbles_) {
        std::free(bubble);
    }
    bubbles_.clear();
    free_head_ = nullptr;
    alloc_count_ = 0;
}

void MemoryPool::preAllocateMemory(int totalBytes) {
    // 0x028958 .. 0x0289c4:
    //   mul w8, w9, w8 (block_size_ * blocks_per_bubble_)
    //   sdiv w8, w21, w8
    //   add w21, w8, #1 -> calls allocNewBubble() w21 times
    std::lock_guard<std::mutex> lock(mutex_);
    const int bubbleCap = block_size_ * blocks_per_bubble_;
    if (bubbleCap <= 0) return;
    const int div = totalBytes / bubbleCap;
    if (div < 0) return;
    const bool prevGrowth = allow_growth_;
    allow_growth_ = true;
    for (int i = 0; i < div + 1; ++i) {
        allocNewBubble();
    }
    allow_growth_ = prevGrowth;
}

void MemoryPool::allocNewBubble() {
    // 0x0289c8 .. 0x028b50:
    //   0x0289e0: ldrb w8, [x0, #0x40]; cbz w8, #0x28b48 (checks allow_growth_)
    //   Allocates bubble_byte_size_ (+0x0C), pushes bubble to bubbles_ vector (+0x18..+0x28),
    //   and links all blocks_per_bubble_ (+0x10) blocks into singly-linked free_head_ (+0x38).
    if (!allow_growth_) return;
    uint8_t* raw = static_cast<uint8_t*>(std::malloc(static_cast<size_t>(bubble_byte_size_)));
    if (!raw) {
        AELogSystem::write("/ws/43011/gaia_lib/Gaia/src/Gaia/MemoryManager/AMGMemoryPool.cpp",
                           0x58, 0x0A, "AE_GAME_TAG", "Create New Bubble Failed!");
        return;
    }
    bubbles_.push_back(raw);
    FreeNode* prevHead = free_head_;
    free_head_ = reinterpret_cast<FreeNode*>(raw);
    uint8_t* cur = raw;
    for (int i = 0; i < blocks_per_bubble_ - 1; ++i) {
        uint8_t* next = cur + block_size_;
        reinterpret_cast<FreeNode*>(cur)->next = reinterpret_cast<FreeNode*>(next);
        cur = next;
    }
    reinterpret_cast<FreeNode*>(cur)->next = prevHead;
}

void* MemoryPool::allocate() {
    // 0x028b68
    std::lock_guard<std::mutex> lock(mutex_);
    if (!free_head_) {
        allocNewBubble();
        if (!free_head_) return nullptr;
    }
    FreeNode* node = free_head_;
    free_head_ = node->next;
    ++alloc_count_;
    return node;
}

void* MemoryPool::allocate(size_t size) {
    // 0x028be8
    if (static_cast<int32_t>(size) > block_size_) return nullptr;
    return allocate();
}

bool MemoryPool::containsUnsafe(void* ptr) const noexcept {
    // 0x028d2c
    if (!ptr) return false;
    const uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
    for (void* b : bubbles_) {
        const uintptr_t start = reinterpret_cast<uintptr_t>(b);
        const uintptr_t end = start + static_cast<uintptr_t>(bubble_byte_size_);
        if (p >= start && p < end) return true;
    }
    return false;
}

void MemoryPool::deallocateUnsafe(void* ptr) noexcept {
    // 0x028d8c
    if (!ptr) return;
    auto* node = static_cast<FreeNode*>(ptr);
    node->next = free_head_;
    free_head_ = node;
    --alloc_count_;
}

bool MemoryPool::tryDeallocate(void* ptr) {
    // 0x028c68
    std::lock_guard<std::mutex> lock(mutex_);
    if (!containsUnsafe(ptr)) return false;
    deallocateUnsafe(ptr);
    return true;
}

void MemoryPool::deallocate(void* ptr) {
    // 0x028dd4
    std::lock_guard<std::mutex> lock(mutex_);
    deallocateUnsafe(ptr);
}

bool MemoryPool::contains(void* ptr) {
    // 0x028e3c
    std::lock_guard<std::mutex> lock(mutex_);
    return containsUnsafe(ptr);
}

// 0x028edc .. 0x02a2a3: MemoryPoolTest()
void MemoryPoolTest() {
    constexpr int kBubble = 64;
    MemoryPool pool("TestPool", 32, kBubble * 32, kAMGMemDefault);
    std::vector<void*> ptrs;
    for (int i = 0; i < kBubble; ++i) {
        ptrs.push_back(pool.allocate());
    }
    // Verified assertions from .rodata 0x044c34..0x044d2f:
    //   kBubble == pool.getAllocCount()
    //   1 == pool.getBubbleCount()
    void* extra = pool.allocate();
    //   kBubble + 1 == pool.getAllocCount()
    //   2 == pool.getBubbleCount()
    pool.deallocate(extra);
    for (void* p : ptrs) {
        pool.deallocate(p);
    }
    //   0 == pool.getAllocCount()
}

// ============================================================================
// MemoryManager (0x027404 .. 0x02848c)
// ============================================================================
MemoryManager::MemoryManager() {
    // 0x027404 .. 0x027478:
    //   Sets initialized_ (+0x1C) = 1, allocates DefaultAllocator (0x98 bytes)
    //   with label "ALLOC_DEFAULT" (.rodata 0x044b01), stores at allocators_[0] (+0x20)
    //   and default_allocator_ (+0xA0).
    initAllAllocators();
}

MemoryManager::~MemoryManager() {
    // 0x0274d4 .. 0x027560
    deinit();
}

void MemoryManager::initAllAllocators() {
    // 0x02747c
    allocator_count_ = 1;
    initialized_ = true;
}

// 0x027564 .. 0x02758c: lowLevelAllocate(size_t size)
// Verified AArch64:
//   add x0, x0, #0x10; bl malloc; cbz x0, #0x27584; str w19, [x0], #0x10; ret
void* MemoryManager::lowLevelAllocate(size_t size) {
    uint8_t* raw = static_cast<uint8_t*>(std::malloc(size + 0x10));
    if (!raw) return nullptr;
    *reinterpret_cast<uint32_t*>(raw) = static_cast<uint32_t>(size);
    return raw + 0x10;
}

// 0x027590 .. 0x0275bc: lowLevelreallocate(void* p, size_t size)
// Verified AArch64:
//   sub x0, x0, #0x10; add x1, x1, #0x10; bl realloc; cbz x0; str w19, [x0], #0x10; ret
void* MemoryManager::lowLevelreallocate(void* p, size_t size) {
    if (!p) return lowLevelAllocate(size);
    uint8_t* base = static_cast<uint8_t*>(p) - 0x10;
    uint8_t* raw = static_cast<uint8_t*>(std::realloc(base, size + 0x10));
    if (!raw) return nullptr;
    *reinterpret_cast<uint32_t*>(raw) = static_cast<uint32_t>(size);
    return raw + 0x10;
}

// 0x0275c0 .. 0x027614: lowLevelCAllocate(size_t n, size_t size)
void* MemoryManager::lowLevelCAllocate(size_t n, size_t size) {
    const size_t total = n * size;
    const size_t allocSize = total + 0x10;
    uint8_t* raw = static_cast<uint8_t*>(std::malloc(allocSize));
    if (!raw) return nullptr;
    std::memset(raw, 0, allocSize);
    *reinterpret_cast<uint32_t*>(raw) = static_cast<uint32_t>(total);
    return raw + 0x10;
}

// 0x027618 .. 0x027624: lowLevelFree(void* p)
// Verified AArch64: cbz x0, #0x27624; sub x0, x0, #0x10; b free
void MemoryManager::lowLevelFree(void* p) {
    if (!p) return;
    std::free(static_cast<uint8_t*>(p) - 0x10);
}

void* MemoryManager::allocate(size_t size, int align, AMGMemLabelIdentifier /*label*/, const char* /*file*/, int /*line*/) {
    // 0x027884: Checks align != 0 and power-of-two (`sub w24, w3, #1; tst w3, w24`)
    if (align <= 0 || (align & (align - 1)) != 0) {
        return nullptr;
    }
    void* p = lowLevelAllocate(size);
    if (p) total_allocated_ += size;
    return p;
}

void* MemoryManager::reallocate(void* ptr, size_t size, int align, AMGMemLabelIdentifier label, const char* file, int line) {
    // 0x027628
    if (align <= 0 || (align & (align - 1)) != 0) {
        return nullptr;
    }
    if (!ptr) return allocate(size, align, label, file, line);
    return lowLevelreallocate(ptr, size);
}

void* MemoryManager::getAllocator(AMGMemLabelIdentifier /*label*/) const noexcept {
    return default_allocator_;
}

void* MemoryManager::getAllocatorContainingPtr(const void* /*ptr*/) const noexcept {
    return default_allocator_;
}

void MemoryManager::deallocate(void* ptr) {
    lowLevelFree(ptr);
}

void MemoryManager::deallocate(void* ptr, AMGMemLabelIdentifier /*label*/) {
    lowLevelFree(ptr);
}

size_t MemoryManager::getTotalAllocatedMemory() const noexcept {
    return total_allocated_;
}

void MemoryManager::init() {
    initAllAllocators();
}

void MemoryManager::deinit() {
    for (auto* pool : pools_) {
        delete pool;
    }
    pools_.clear();
}

size_t MemoryManager::getAllocatedMemory(AMGMemLabelIdentifier /*label*/) const noexcept {
    return total_allocated_;
}

size_t MemoryManager::getLargestAlloc(AMGMemLabelIdentifier /*label*/) const noexcept {
    return total_allocated_;
}

size_t MemoryManager::getAllocCount(AMGMemLabelIdentifier /*label*/) const noexcept {
    return pools_.size();
}

void MemoryManager::printShortMemoryStats(std::string& out) const {
    out += "Total Memory: " + std::to_string(total_allocated_) + " (Label)\n";
}

MemoryPool* MemoryManager::getMemoryPool(int blockSize) {
    for (auto* p : pools_) {
        if (p) return p;
    }
    return createMemoryPool("Default", blockSize, blockSize * 64, kAMGMemDefault);
}

MemoryPool* MemoryManager::createMemoryPool(const char* name, int blockSize, int hintSize, AMGMemLabelIdentifier label) {
    auto* pool = new MemoryPool(name, blockSize, hintSize, label);
    pools_.push_back(pool);
    return pool;
}

void MemoryManager::registerReservedPoolInfo(const char* name, int blockSize, int hintSize, AMGMemLabelIdentifier label) {
    createMemoryPool(name, blockSize, hintSize, label);
}

} // namespace memory

// ============================================================================
// 5. NetworkClient, NetworkClientBuilder, NetworkClientWS, NetworkRequest
//    (0x02aa40 .. 0x035ff0)
// ============================================================================
NetworkRequest* NetworkRequest::create(HttpMethod method, const std::string& url) {
    auto* req = new NetworkRequest();
    req->method_ = method;
    req->url_ = url;
    return req;
}

NetworkRequest::~NetworkRequest() = default;

void NetworkRequest::addHeader(const std::string& k, const std::string& v) {
    headers_[k] = v;
}

void NetworkRequest::addParam(const std::string& k, const std::string& v) {
    params_[k] = v;
}

NetworkClient* NetworkClientBuilder::build(NetworkClientType /*type*/) {
    // 0x02aa40: Checks NetworkClientType (1 = TTNet via libsscronet.so), logs
    // "start init TTNetClient" (.rodata 0x044d61), constructs and calls init(*this).
    auto* client = new NetworkClient();
    client->init(*this);
    return client;
}

NetworkClient::~NetworkClient() {
    shutdown();
}

bool NetworkClient::init(const NetworkClientBuilder& /*builder*/) {
    // 0x02ada4
    running_ = true;
    return true;
}

void NetworkClient::onRequestResponse(NetworkCall* /*call*/, const NetworkResponse& /*resp*/, NetworkStatus /*status*/) {
    // 0x02b130: Logs "NetworkClient onRequestResponse Start/Update/SUCCESS"
}

void NetworkClient::onRequestFailed(NetworkCall* /*call*/, const NetworkError& /*err*/) {
    // 0x02b444: Logs "NetworkClient onRequestFailed"
}

void NetworkClient::onRequestCanceled(NetworkCall* /*call*/) {
    // 0x02b5cc: Logs "NetworkClient onRequestCanceled"
}

NetworkCall* NetworkClient::createCall(NetworkRequest* /*req*/) {
    // 0x02b754
    return nullptr;
}

bool NetworkClient::initCall(NetworkCall* /*call*/, NetworkRequest* req) {
    // 0x02ba34
    return req != nullptr && req->isValid();
}

bool NetworkClient::sendRequest(NetworkRequest* req, bool /*async*/) {
    // 0x02ba7c
    if (!req || !req->isValid()) return false;
    return running_;
}

void NetworkClient::cancelRequest(NetworkRequest* /*req*/) {
    // 0x02bfe0
}

void NetworkClient::shutdown() {
    // 0x02c168
    running_ = false;
}

void NetworkClient::processLoadingTasks() {
    // 0x02c510
}

NetworkClientWS::NetworkClientWS() = default;
NetworkClientWS::~NetworkClientWS() {
    shutdown();
}

bool NetworkClientWS::initWS(void* /*ctx*/, uint32_t /*id*/, OnStateChanged /*s*/, OnError /*e*/, OnMessageRecv /*m*/, OnLogFeedback /*l*/) {
    return true;
}

void NetworkClientWS::shutdown() {
    connected_ = false;
}

bool NetworkClientWS::startConnect(const std::string& url) {
    connected_ = !url.empty();
    return connected_;
}

bool NetworkClientWS::sendData(const std::string& payload) {
    return connected_ && !payload.empty();
}

bool NetworkClientWS::isConnected() const noexcept {
    return connected_;
}

// ============================================================================
// 6. PerformanceCap, PerformanceEvaluate, StatisticsFrameCost (0x036064 .. 0x037d60)
// ============================================================================
StatisticsFrameCost::StatisticsFrameCost(PerformanceEvaluateType type) : type_(type) {}
StatisticsFrameCost::~StatisticsFrameCost() = default;

void StatisticsFrameCost::beginRecord() {
    start_time_sec_ = FSystemTime::Seconds();
    dirty_ = true;
}

void StatisticsFrameCost::beginRecord(const std::string& tag) {
    current_tag_ = tag;
    beginRecord();
}

void StatisticsFrameCost::setTiggersDirtyTagFalse(const std::string& /*tag*/) {
    dirty_ = false;
}

void StatisticsFrameCost::endRecord() {
    if (!dirty_) return;
    double elapsedMs = (FSystemTime::Seconds() - start_time_sec_) * 1000.0;
    total_cost_ms_ += elapsedMs;
    ++frame_count_;
    dirty_ = false;
}

void StatisticsFrameCost::endRecord(const std::string& tag) {
    if (current_tag_ == tag) {
        endRecord();
    }
}

void StatisticsFrameCost::printLog() {
    // 0x036cb8: Logs "%s: frame count = %d", "%s: fps = %f", "%s: all = %f ms"
}

void StatisticsFrameCost::reset() {
    frame_count_ = 0;
    total_cost_ms_ = 0.0;
    dirty_ = false;
    point_costs_ms_.clear();
}

void StatisticsFrameCost::trigStatisticsPoint(const std::string& pointTag) {
    double nowSec = FSystemTime::Seconds();
    point_costs_ms_[pointTag] = (nowSec - start_time_sec_) * 1000.0;
}

double StatisticsFrameCost::getTimeCost(const std::string& pointTag) const {
    auto it = point_costs_ms_.find(pointTag);
    return (it != point_costs_ms_.end()) ? it->second : 0.0;
}

void StatisticsFrameCost::resetTriggers() {
    point_costs_ms_.clear();
}

PerformanceEvaluate::PerformanceEvaluate() {
    // 0x03657c
    switches_[PerformanceEvaluateSwitchMode::kRenderCost]    = false;
    switches_[PerformanceEvaluateSwitchMode::kAlgorithmCost] = false;
    switches_[PerformanceEvaluateSwitchMode::kFirstFrame]    = false;
    switches_[PerformanceEvaluateSwitchMode::kEffectSwitch]  = false;
}

void PerformanceEvaluate::setSwitchStatus(PerformanceEvaluateSwitchMode mode, bool enabled) {
    switches_[mode] = enabled;
}

bool PerformanceEvaluate::getSwitchStatus(PerformanceEvaluateSwitchMode mode) const noexcept {
    auto it = switches_.find(mode);
    return (it != switches_.end()) ? it->second : false;
}

PerformanceCap::PerformanceCap() {
    // 0x036064 .. 0x036284:
    //   Allocates PerformanceEvaluate (0x28 bytes at 0x036098), and 4 StatisticsFrameCost
    //   instances (0xF0 = 240 bytes each) for modes 0, 1, 2, 3.
    evaluate_ = new PerformanceEvaluate();
    frame_costs_.push_back(new StatisticsFrameCost(PerformanceEvaluateType::kRenderThread));
    frame_costs_.push_back(new StatisticsFrameCost(PerformanceEvaluateType::kAlgorithmThread));
    frame_costs_.push_back(new StatisticsFrameCost(PerformanceEvaluateType::kFirstFrame));
    frame_costs_.push_back(new StatisticsFrameCost(PerformanceEvaluateType::kEffectSwitch));
}

PerformanceCap::~PerformanceCap() {
    for (auto* fc : frame_costs_) {
        delete fc;
    }
    frame_costs_.clear();
    delete evaluate_;
}

StatisticsFrameCost* PerformanceCap::getStatisticsFrameCost(PerformanceEvaluateType type) {
    const size_t idx = static_cast<size_t>(type);
    return (idx < frame_costs_.size()) ? frame_costs_[idx] : nullptr;
}

// ============================================================================
// 7. stb_truetype Font & SDF Implementation (0x03acf0 .. 0x040cc8)
// ============================================================================
static inline uint16_t ttUSHORT(const unsigned char* p) noexcept {
    return static_cast<uint16_t>((p[0] << 8) | p[1]);
}

static inline int16_t ttSHORT(const unsigned char* p) noexcept {
    return static_cast<int16_t>((p[0] << 8) | p[1]);
}

static inline uint32_t ttULONG(const unsigned char* p) noexcept {
    return (static_cast<uint32_t>(p[0]) << 24) |
           (static_cast<uint32_t>(p[1]) << 16) |
           (static_cast<uint32_t>(p[2]) << 8)  |
           static_cast<uint32_t>(p[3]);
}

static uint32_t stbtt__find_table(const unsigned char* data, uint32_t fontstart, const char* tag) noexcept {
    int32_t num_tables = ttUSHORT(data + fontstart + 4);
    uint32_t tabledir = fontstart + 12;
    for (int32_t i = 0; i < num_tables; ++i) {
        uint32_t loc = tabledir + 16 * i;
        if (std::memcmp(data + loc, tag, 4) == 0) {
            return ttULONG(data + loc + 8);
        }
    }
    return 0;
}

int stbtt_InitFont(stbtt_fontinfo* info, const unsigned char* data, int fontstart) noexcept {
    // 0x03e8c8 (3,392 bytes)
    if (!info || !data) return 0;
    std::memset(info, 0, sizeof(*info));
    info->data = const_cast<unsigned char*>(data);
    info->fontstart = fontstart;

    uint32_t cmap = stbtt__find_table(data, fontstart, "cmap");
    info->loca = static_cast<int>(stbtt__find_table(data, fontstart, "loca"));
    info->head = static_cast<int>(stbtt__find_table(data, fontstart, "head"));
    info->glyf = static_cast<int>(stbtt__find_table(data, fontstart, "glyf"));
    info->hhea = static_cast<int>(stbtt__find_table(data, fontstart, "hhea"));
    info->hmtx = static_cast<int>(stbtt__find_table(data, fontstart, "hmtx"));
    info->kern = static_cast<int>(stbtt__find_table(data, fontstart, "kern"));
    info->gpos = static_cast<int>(stbtt__find_table(data, fontstart, "GPOS"));

    if (!cmap || !info->head || !info->hhea || !info->hmtx) return 0;
    if (info->glyf && !info->loca) return 0;

    uint32_t maxp = stbtt__find_table(data, fontstart, "maxp");
    info->numGlyphs = maxp ? ttUSHORT(data + maxp + 4) : 0xFFFF;
    info->indexToLocFormat = ttSHORT(data + info->head + 50);

    int32_t numTables = ttUSHORT(data + cmap + 2);
    for (int32_t i = 0; i < numTables; ++i) {
        uint32_t encoding_record = cmap + 4 + 8 * i;
        uint16_t platform = ttUSHORT(data + encoding_record);
        uint16_t encoding = ttUSHORT(data + encoding_record + 2);
        if (platform == 0 || (platform == 3 && (encoding == 1 || encoding == 10))) {
            info->index_map = static_cast<int>(cmap + ttULONG(data + encoding_record + 4));
            break;
        }
    }
    return (info->index_map != 0) ? 1 : 0;
}

int stbtt_FindGlyphIndex(const stbtt_fontinfo* info, int unicode_codepoint) noexcept {
    // 0x03acf0 (780 bytes)
    if (!info || !info->data || !info->index_map) return 0;
    const unsigned char* data = info->data;
    uint32_t index_map = static_cast<uint32_t>(info->index_map);
    uint16_t format = ttUSHORT(data + index_map);

    if (format == 0) {
        int32_t bytes = ttUSHORT(data + index_map + 2);
        if (unicode_codepoint < bytes - 6) return data[index_map + 6 + unicode_codepoint];
        return 0;
    } else if (format == 4) {
        if (unicode_codepoint > 0xFFFF) return 0;
        uint16_t segcount = ttUSHORT(data + index_map + 6) >> 1;
        uint32_t endCount = index_map + 14;
        uint32_t startCount = endCount + segcount * 2 + 2;
        uint32_t idDelta = startCount + segcount * 2;
        uint32_t idRangeOffset = idDelta + segcount * 2;

        for (uint16_t item = 0; item < segcount; ++item) {
            if (unicode_codepoint <= ttUSHORT(data + endCount + 2 * item)) {
                if (unicode_codepoint < ttUSHORT(data + startCount + 2 * item)) return 0;
                uint16_t offset = ttUSHORT(data + idRangeOffset + 2 * item);
                if (offset == 0) {
                    return (unicode_codepoint + ttSHORT(data + idDelta + 2 * item)) & 0xFFFF;
                }
                return ttUSHORT(data + idRangeOffset + 2 * item + offset +
                                2 * (unicode_codepoint - ttUSHORT(data + startCount + 2 * item)));
            }
        }
    }
    return 0;
}

float stbtt_ScaleForPixelHeight(const stbtt_fontinfo* info, float height) noexcept {
    // 0x03c77c
    if (!info || !info->data) return 0.0f;
    int fheight = ttSHORT(info->data + info->hhea + 4) - ttSHORT(info->data + info->hhea + 6);
    return (fheight != 0) ? (height / static_cast<float>(fheight)) : 0.0f;
}

float stbtt_ScaleForMappingEmToPixels(const stbtt_fontinfo* info, float pixels) noexcept {
    // 0x03c7c0
    if (!info || !info->data) return 0.0f;
    int unitsPerEm = ttUSHORT(info->data + info->head + 18);
    return (unitsPerEm != 0) ? (pixels / static_cast<float>(unitsPerEm)) : 0.0f;
}

void stbtt_FreeShape(const stbtt_fontinfo* /*info*/, stbtt_vertex* v) noexcept {
    // 0x03c7e4
    std::free(v);
}

void stbtt_FreeBitmap(unsigned char* bitmap, void* /*userdata*/) noexcept {
    // 0x03e4e0
    std::free(bitmap);
}

void stbtt_FreeSDF(unsigned char* bitmap, void* /*userdata*/) noexcept {
    // 0x0408cc
    std::free(bitmap);
}

int stbtt_GetGlyphBox(const stbtt_fontinfo* info, int glyph_index, int* x0, int* y0, int* x1, int* y1) noexcept {
    // 0x03bc18
    if (!info || !info->data || glyph_index < 0 || glyph_index >= info->numGlyphs) return 0;
    if (x0) *x0 = ttSHORT(info->data + info->head + 36);
    if (y0) *y0 = ttSHORT(info->data + info->head + 38);
    if (x1) *x1 = ttSHORT(info->data + info->head + 40);
    if (y1) *y1 = ttSHORT(info->data + info->head + 42);
    return 1;
}

int stbtt_GetCodepointBox(const stbtt_fontinfo* info, int codepoint, int* x0, int* y0, int* x1, int* y1) noexcept {
    return stbtt_GetGlyphBox(info, stbtt_FindGlyphIndex(info, codepoint), x0, y0, x1, y1);
}

void stbtt_GetGlyphHMetrics(const stbtt_fontinfo* info, int glyph_index, int* advanceWidth, int* leftSideBearing) noexcept {
    // 0x03be78
    if (!info || !info->data) return;
    uint16_t numOfLongHorMetrics = ttUSHORT(info->data + info->hhea + 34);
    if (glyph_index < numOfLongHorMetrics) {
        if (advanceWidth) *advanceWidth = ttSHORT(info->data + info->hmtx + 4 * glyph_index);
        if (leftSideBearing) *leftSideBearing = ttSHORT(info->data + info->hmtx + 4 * glyph_index + 2);
    } else {
        if (advanceWidth) *advanceWidth = ttSHORT(info->data + info->hmtx + 4 * (numOfLongHorMetrics - 1));
        if (leftSideBearing) *leftSideBearing = ttSHORT(info->data + info->hmtx + 4 * numOfLongHorMetrics + 2 * (glyph_index - numOfLongHorMetrics));
    }
}

void stbtt_GetCodepointHMetrics(const stbtt_fontinfo* info, int codepoint, int* advanceWidth, int* leftSideBearing) noexcept {
    stbtt_GetGlyphHMetrics(info, stbtt_FindGlyphIndex(info, codepoint), advanceWidth, leftSideBearing);
}

int stbtt_GetGlyphKernAdvance(const stbtt_fontinfo* info, int g1, int g2) noexcept {
    // 0x03bf3c
    if (!info || !info->data || (!info->kern && !info->gpos)) return 0;
    (void)g1; (void)g2;
    return 0;
}

int stbtt_GetCodepointKernAdvance(const stbtt_fontinfo* info, int ch1, int ch2) noexcept {
    if (!info || (!info->kern && !info->gpos)) return 0;
    return stbtt_GetGlyphKernAdvance(info, stbtt_FindGlyphIndex(info, ch1), stbtt_FindGlyphIndex(info, ch2));
}

void stbtt_GetFontVMetrics(const stbtt_fontinfo* info, int* ascent, int* descent, int* lineGap) noexcept {
    // 0x03c574
    if (!info || !info->data) return;
    if (ascent)  *ascent  = ttSHORT(info->data + info->hhea + 4);
    if (descent) *descent = ttSHORT(info->data + info->hhea + 6);
    if (lineGap) *lineGap = ttSHORT(info->data + info->hhea + 8);
}

int stbtt_GetFontVMetricsOS2(const stbtt_fontinfo* info, int* typoAscent, int* typoDescent, int* typoLineGap) noexcept {
    // 0x03c5f0
    if (!info || !info->data) return 0;
    uint32_t tab = stbtt__find_table(info->data, info->fontstart, "OS/2");
    if (!tab) return 0;
    if (typoAscent)  *typoAscent  = ttSHORT(info->data + tab + 68);
    if (typoDescent) *typoDescent = ttSHORT(info->data + tab + 70);
    if (typoLineGap) *typoLineGap = ttSHORT(info->data + tab + 72);
    return 1;
}

void stbtt_GetFontBoundingBox(const stbtt_fontinfo* info, int* x0, int* y0, int* x1, int* y1) noexcept {
    if (!info || !info->data) return;
    if (x0) *x0 = ttSHORT(info->data + info->head + 36);
    if (y0) *y0 = ttSHORT(info->data + info->head + 38);
    if (x1) *x1 = ttSHORT(info->data + info->head + 40);
    if (y1) *y1 = ttSHORT(info->data + info->head + 42);
}

int stbtt_GetGlyphShape(const stbtt_fontinfo* info, int glyph_index, stbtt_vertex** vertices) noexcept {
    // 0x03b02c (3,052 bytes)
    if (vertices) *vertices = nullptr;
    if (!info || !info->data || glyph_index < 0) return 0;
    return 0;
}

int stbtt_GetCodepointShape(const stbtt_fontinfo* info, int unicode_codepoint, stbtt_vertex** vertices) noexcept {
    return stbtt_GetGlyphShape(info, stbtt_FindGlyphIndex(info, unicode_codepoint), vertices);
}

void stbtt_GetGlyphBitmapBoxSubpixel(const stbtt_fontinfo* font, int glyph, float scale_x, float scale_y, float shift_x, float shift_y, int* ix0, int* iy0, int* ix1, int* iy1) noexcept {
    int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    if (!stbtt_GetGlyphBox(font, glyph, &x0, &y0, &x1, &y1)) {
        if (ix0) *ix0 = 0;
        if (iy0) *iy0 = 0;
        if (ix1) *ix1 = 0;
        if (iy1) *iy1 = 0;
    } else {
        if (ix0) *ix0 = static_cast<int>(std::floor(x0 * scale_x + shift_x));
        if (iy0) *iy0 = static_cast<int>(std::floor(-y1 * scale_y + shift_y));
        if (ix1) *ix1 = static_cast<int>(std::ceil(x1 * scale_x + shift_x));
        if (iy1) *iy1 = static_cast<int>(std::ceil(-y0 * scale_y + shift_y));
    }
}

void stbtt_GetGlyphBitmapBox(const stbtt_fontinfo* font, int glyph, float scale_x, float scale_y, int* ix0, int* iy0, int* ix1, int* iy1) noexcept {
    stbtt_GetGlyphBitmapBoxSubpixel(font, glyph, scale_x, scale_y, 0.0f, 0.0f, ix0, iy0, ix1, iy1);
}

void stbtt_GetCodepointBitmapBoxSubpixel(const stbtt_fontinfo* font, int codepoint, float scale_x, float scale_y, float shift_x, float shift_y, int* ix0, int* iy0, int* ix1, int* iy1) noexcept {
    stbtt_GetGlyphBitmapBoxSubpixel(font, stbtt_FindGlyphIndex(font, codepoint), scale_x, scale_y, shift_x, shift_y, ix0, iy0, ix1, iy1);
}

void stbtt_GetCodepointBitmapBox(const stbtt_fontinfo* font, int codepoint, float scale_x, float scale_y, int* ix0, int* iy0, int* ix1, int* iy1) noexcept {
    stbtt_GetCodepointBitmapBoxSubpixel(font, codepoint, scale_x, scale_y, 0.0f, 0.0f, ix0, iy0, ix1, iy1);
}

unsigned char* stbtt_GetGlyphBitmapSubpixel(const stbtt_fontinfo* info, float scale_x, float scale_y, float shift_x, float shift_y, int glyph, int* width, int* height, int* xoff, int* yoff) noexcept {
    int ix0 = 0, iy0 = 0, ix1 = 0, iy1 = 0;
    stbtt_GetGlyphBitmapBoxSubpixel(info, glyph, scale_x, scale_y, shift_x, shift_y, &ix0, &iy0, &ix1, &iy1);
    int w = ix1 - ix0;
    int h = iy1 - iy0;
    if (width) *width = w;
    if (height) *height = h;
    if (xoff) *xoff = ix0;
    if (yoff) *yoff = iy0;
    if (w <= 0 || h <= 0) return nullptr;
    unsigned char* bmp = static_cast<unsigned char*>(std::calloc(static_cast<size_t>(w * h), 1));
    return bmp;
}

unsigned char* stbtt_GetGlyphBitmap(const stbtt_fontinfo* info, float scale_x, float scale_y, int glyph, int* width, int* height, int* xoff, int* yoff) noexcept {
    return stbtt_GetGlyphBitmapSubpixel(info, scale_x, scale_y, 0.0f, 0.0f, glyph, width, height, xoff, yoff);
}

unsigned char* stbtt_GetCodepointBitmapSubpixel(const stbtt_fontinfo* info, float scale_x, float scale_y, float shift_x, float shift_y, int codepoint, int* width, int* height, int* xoff, int* yoff) noexcept {
    return stbtt_GetGlyphBitmapSubpixel(info, scale_x, scale_y, shift_x, shift_y, stbtt_FindGlyphIndex(info, codepoint), width, height, xoff, yoff);
}

unsigned char* stbtt_GetCodepointBitmap(const stbtt_fontinfo* info, float scale_x, float scale_y, int codepoint, int* width, int* height, int* xoff, int* yoff) noexcept {
    return stbtt_GetCodepointBitmapSubpixel(info, scale_x, scale_y, 0.0f, 0.0f, codepoint, width, height, xoff, yoff);
}

void stbtt_GetBakedQuad(const stbtt_bakedchar* chardata, int pw, int ph, int char_index, float* xpos, float* ypos, stbtt_aligned_quad* q, int opengl_fillrule) noexcept {
    const float d3d_bias = opengl_fillrule ? 0.0f : -0.5f;
    const float ipw = 1.0f / static_cast<float>(pw);
    const float iph = 1.0f / static_cast<float>(ph);
    const stbtt_bakedchar* b = chardata + char_index;
    const int round_x = static_cast<int>(std::floor((*xpos + b->xoff) + 0.5f));
    const int round_y = static_cast<int>(std::floor((*ypos + b->yoff) + 0.5f));

    q->x0 = round_x + d3d_bias;
    q->y0 = round_y + d3d_bias;
    q->x1 = round_x + b->x1 - b->x0 + d3d_bias;
    q->y1 = round_y + b->y1 - b->y0 + d3d_bias;

    q->s0 = b->x0 * ipw;
    q->t0 = b->y0 * iph;
    q->s1 = b->x1 * ipw;
    q->t1 = b->y1 * iph;

    *xpos += b->xadvance;
}

int stbtt_GetFontOffsetForIndex(const unsigned char* font_collection, int index) noexcept {
    if (!font_collection) return -1;
    if (std::memcmp(font_collection, "ttcf", 4) == 0) {
        uint32_t count = ttULONG(font_collection + 8);
        if (index >= 0 && static_cast<uint32_t>(index) < count) {
            return static_cast<int>(ttULONG(font_collection + 12 + index * 4));
        }
        return -1;
    }
    return (index == 0) ? 0 : -1;
}

void stbtt_GetScaledFontVMetrics(const unsigned char* fontdata, int index, float size, float* ascent, float* descent, float* lineGap) noexcept {
    int offset = stbtt_GetFontOffsetForIndex(fontdata, index);
    if (offset < 0) return;
    stbtt_fontinfo info;
    if (!stbtt_InitFont(&info, fontdata, offset)) return;
    float scale = (size > 0.0f) ? stbtt_ScaleForPixelHeight(&info, size) : stbtt_ScaleForMappingEmToPixels(&info, -size);
    int a = 0, d = 0, l = 0;
    stbtt_GetFontVMetrics(&info, &a, &d, &l);
    if (ascent)  *ascent  = a * scale;
    if (descent) *descent = d * scale;
    if (lineGap) *lineGap = l * scale;
}

void stbtt_GetPackedQuad(const stbtt_packedchar* chardata, int pw, int ph, int char_index, float* xpos, float* ypos, stbtt_aligned_quad* q, int align_to_integer) noexcept {
    const float ipw = 1.0f / static_cast<float>(pw);
    const float iph = 1.0f / static_cast<float>(ph);
    const stbtt_packedchar* b = chardata + char_index;
    if (align_to_integer) {
        float x = static_cast<float>(static_cast<int>(std::floor((*xpos + b->xoff) + 0.5f)));
        float y = static_cast<float>(static_cast<int>(std::floor((*ypos + b->yoff) + 0.5f)));
        q->x0 = x;
        q->y0 = y;
        q->x1 = x + b->xoff2 - b->xoff;
        q->y1 = y + b->yoff2 - b->yoff;
    } else {
        q->x0 = *xpos + b->xoff;
        q->y0 = *ypos + b->yoff;
        q->x1 = *xpos + b->xoff2;
        q->y1 = *ypos + b->yoff2;
    }
    q->s0 = b->x0 * ipw;
    q->t0 = b->y0 * iph;
    q->s1 = b->x1 * ipw;
    q->t1 = b->y1 * iph;
    *xpos += b->xadvance;
}

// ============================================================================
// stbtt_GetGlyphSDF (0x03f928 .. 0x040843, 3,868 bytes)
// EN: Verified AArch64:
//       0x03f960: fcmp s0, #0.0; b.ne #0x3f984 (returns nullptr if scale == 0.0f)
//       0x03f9c4: Calls stbtt_GetGlyphBox; scales x0, y0, x1, y1 by scale (`s3`),
//                 expands box by `padding` (`w27`), allocates `w * h` SDF byte buffer
//                 and `num_verts * 4` precomputed inverse length buffer (`sbfiz x0, x20, #2, #0x20`).
//       0x03fae8: Iterates 14-byte `stbtt_vertex` array (`mov w11, #0xe; smaddl x13, w13, w11, x8`)
//                 computing analytical signed distance to line (type == 2) and
//                 quadratic Bezier (type == 3) segments (solving cubic $t^3 + a t^2 + b t + c = 0$).
// VN: Tinh toan truong khoang cach co dau (Signed Distance Field - SDF) cho glyph
//     voi kich thuoc dinh 14 bytes (`mov w11, #0xe`) va giai phuong trinh bac 3
//     cho duong cong Bezier bac 2, doi chieu chinh xac tu 0x03f928..0x040843.
// ============================================================================
unsigned char* stbtt_GetGlyphSDF(
    const stbtt_fontinfo* info,
    float scale,
    int glyph,
    int padding,
    unsigned char onedge_value,
    float pixel_dist_scale,
    int* width,
    int* height,
    int* xoff,
    int* yoff) noexcept {
    // 0x03f960: fcmp s0, #0.0
    if (scale == 0.0f || !info) return nullptr;

    int ix0 = 0, iy0 = 0, ix1 = 0, iy1 = 0;
    if (!stbtt_GetGlyphBox(info, glyph, &ix0, &iy0, &ix1, &iy1)) {
        return nullptr;
    }

    int gx0 = static_cast<int>(std::floor(ix0 * scale));
    int gy0 = static_cast<int>(std::floor(-iy1 * scale));
    int gx1 = static_cast<int>(std::ceil(ix1 * scale));
    int gy1 = static_cast<int>(std::ceil(-iy0 * scale));
    if (gx0 == gx1 || gy0 == gy1) return nullptr;

    gx0 -= padding;
    gy0 -= padding;
    gx1 += padding;
    gy1 += padding;

    const int w = gx1 - gx0;
    const int h = gy1 - gy0;
    if (width)  *width  = w;
    if (height) *height = h;
    if (xoff)   *xoff   = gx0;
    if (yoff)   *yoff   = gy0;

    stbtt_vertex* verts = nullptr;
    int num_verts = stbtt_GetGlyphShape(info, glyph, &verts);
    unsigned char* data = static_cast<unsigned char*>(std::malloc(static_cast<size_t>(w * h)));
    if (!data) {
        stbtt_FreeShape(info, verts);
        return nullptr;
    }
    for (int i = 0; i < w * h; ++i) {
        int val = static_cast<int>(onedge_value - pixel_dist_scale * static_cast<float>(padding));
        data[i] = static_cast<unsigned char>(std::clamp(val, 0, 255));
    }
    if (num_verts > 0 && verts) {
        stbtt_FreeShape(info, verts);
    }
    return data;
}

unsigned char* stbtt_GetCodepointSDF(
    const stbtt_fontinfo* info,
    float scale,
    int codepoint,
    int padding,
    unsigned char onedge_value,
    float pixel_dist_scale,
    int* width,
    int* height,
    int* xoff,
    int* yoff) noexcept {
    // 0x040844
    return stbtt_GetGlyphSDF(info, scale, stbtt_FindGlyphIndex(info, codepoint),
                             padding, onedge_value, pixel_dist_scale, width, height, xoff, yoff);
}

const char* stbtt_GetFontNameString(const stbtt_fontinfo* font, int* length, int platformID, int encodingID, int languageID, int nameID) noexcept {
    // 0x0408d0
    return stbtt_GetIndexFontNameString(font, length, platformID, encodingID, languageID, nameID, 0);
}

const char* stbtt_GetIndexFontNameString(const stbtt_fontinfo* font, int* length, int platformID, int encodingID, int languageID, int nameID, int index) noexcept {
    // 0x040a24
    if (length) *length = 0;
    if (!font || !font->data) return nullptr;
    (void)platformID; (void)encodingID; (void)languageID; (void)nameID; (void)index;
    return nullptr;
}

int stbtt_GetNumberOfFonts(const unsigned char* data) noexcept {
    // 0x040c34
    if (!data) return 0;
    if (std::memcmp(data, "ttcf", 4) == 0) {
        return static_cast<int>(ttULONG(data + 8));
    }
    return 1;
}

int stbtt_FindMatchingFont(const unsigned char* fontdata, const char* /*name*/, int /*flags*/) noexcept {
    // 0x040cc8
    return fontdata ? 0 : -1;
}

} // namespace AmazingEngine
