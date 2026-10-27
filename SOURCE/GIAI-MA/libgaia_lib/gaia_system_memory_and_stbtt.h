// ============================================================================
// File: gaia_system_memory_and_stbtt.h
// Target: libgaia_lib.so (329,704 bytes)
// Task ID: TASK-135-RECONSTRUCTION-LIBGAIA-LIB / TASK_SO_112_libgaia_lib
// Description:
//   EN: Clean-room C++17 declarations for AmazingEngine AELogSystem, ThreadPool,
//       FSystemTime, FileUtils, MemoryStream, AllowListManager, MemoryManager,
//       MemoryPool, NetworkClient/TTNetStub, PerformanceCap, and stb_truetype.
//   VN: Khai bao C++17 chuan clean-room cho AELogSystem, ThreadPool, FSystemTime,
//       FileUtils, MemoryStream, AllowListManager, MemoryManager, MemoryPool,
//       NetworkClient/TTNetStub, PerformanceCap va stb_truetype.
// ============================================================================

#pragma once

#include "gaia_types.h"
#include <cstdarg>
#include <deque>
#include <thread>
#include <condition_variable>

namespace AmazingEngine {

// ============================================================================
// 1. AELogSystem (0x0107a0 .. 0x011c00)
// ============================================================================
class AELogSystem {
public:
    using LogCallback = void (*)(int level, const char* tag, const char* msg);

    AELogSystem();
    ~AELogSystem();

    static int write(const char* file, int line, int level, const char* tag, const char* fmt, ...);      // 0x0107a0
    static int write_s(const char* file, int line, int level, const char* tag, const char* msg);         // 0x010aa8
    static int vwrite(const char* file, int line, int level, const char* tag, const char* fmt, va_list ap); // 0x010b4c
    static void registerLogFunction(LogCallback cb) noexcept;                                            // 0x010cf8
    static void setLogFilter(int minLevel) noexcept;                                                     // 0x010d20
};

extern AELogSystem g_aeLogT;

// ============================================================================
// 2. ThreadPool, ThreadUtility, FSystemTime, FTimerBase (0x019fd0 .. 0x01c290)
// ============================================================================
class ThreadPool : public RefBase {
public:
    explicit ThreadPool(unsigned int threadCount = 4); // 0x019fd0
    ~ThreadPool() override;                            // 0x01a01c

    void enqueueTask(std::function<void()> task);
    void stop() noexcept;
    uint32_t getThreadCount() const noexcept { return thread_count_; }

private:
    std::vector<std::thread> workers_;                 // +0x10
    std::deque<std::function<void()>> tasks_;          // +0x58
    std::mutex queue_mutex_;                           // +0x88
    std::condition_variable cv_;                       // +0xB0
    std::atomic<bool> running_{true};                  // +0xE0
    std::atomic<int32_t> active_tasks_{0};             // +0xE4
    uint32_t thread_count_ = 0;                        // +0xE8
};

class FSystemTime {
public:
    static double InitTiming() noexcept;               // 0x01bd00
    static double Seconds() noexcept;                  // 0x01bd50
    static uint64_t Cycles64() noexcept;               // 0x01bd90
};

// ============================================================================
// 3. FileUtils, MemoryStream, AllowListManager (0x01c7fc .. 0x0235dc)
// ============================================================================
class FileUtils {
public:
    static bool isFileExist(const std::string& path) noexcept;
    static bool isDirectoryExist(const std::string& path) noexcept;
    static int64_t getFileSize(const std::string& path) noexcept;
    static bool readFile(const std::string& path, std::string& outBuffer);
    static bool writeFile(const std::string& path, const void* data, size_t len);
    static std::string getFileExtension(const std::string& path);
};

class MemoryStream : public RefBase {
public:
    explicit MemoryStream(size_t initialSize = 0);
    ~MemoryStream() override;

    bool seek(size_t pos) noexcept;
    size_t read(void* dst, size_t len) noexcept;
    size_t write(const void* src, size_t len);
    const uint8_t* data() const noexcept { return buffer_.data(); }
    size_t size() const noexcept { return buffer_.size(); }
    size_t tell() const noexcept { return curr_pos_; }

private:
    std::vector<uint8_t> buffer_;
    size_t curr_pos_ = 0;
};

// ============================================================================
// 4. NetworkClient, NetworkClientBuilder, NetworkClientWS, NetworkRequest
//    (0x02aa40 .. 0x035ff0)
// ============================================================================
enum class NetworkClientType : int32_t {
    kDefault = 0,
    kTTNet   = 1
};

enum class NetworkCacheMode : int32_t {
    kDisabled = 0,
    kInMemory = 1,
    kDisk     = 2
};

enum class HttpMethod : int32_t {
    kGet  = 0,
    kPost = 1,
    kPut  = 2,
    kHead = 3
};

enum class HttpRequestBodyType : int32_t {
    kRaw  = 0,
    kForm = 1,
    kJson = 2
};

enum class NetworkStatus : int32_t {
    kStart   = 0,
    kUpdate  = 1,
    kSuccess = 2
};

struct NetworkResponse {
    int32_t status_code = 200;
    std::string status_text;
    std::map<std::string, std::string> headers;
    std::string body;
};

struct NetworkError {
    int32_t error_code = 0;
    std::string message;
};

class NetworkCall;

class NetworkRequest : public RefBase {
public:
    using OnFailedFunc = std::function<void(const NetworkRequest*, const NetworkError&)>;
    using OnResponseFunc = std::function<void(const NetworkRequest*, const NetworkResponse&, NetworkStatus)>;

    static NetworkRequest* create(HttpMethod method, const std::string& url); // 0x02d5ec
    ~NetworkRequest() override;                                               // 0x02da7c

    const std::string& getUrl() const noexcept { return url_; }               // 0x02d7a0
    void setUrl(const std::string& url) { url_ = url; }                       // 0x02d7a8
    void addHeader(const std::string& k, const std::string& v);               // 0x02d7b0
    void addParam(const std::string& k, const std::string& v);                // 0x02d7e0
    void setCachable(bool c) noexcept { cachable_ = c; }                      // 0x02d810
    bool isValid() const noexcept { return !url_.empty(); }                   // 0x02d81c
    HttpMethod getMethod() const noexcept { return method_; }                 // 0x02d844
    const std::map<std::string, std::string>& getHeaders() const noexcept { return headers_; } // 0x02d84c
    const std::map<std::string, std::string>& getParams() const noexcept { return params_; }   // 0x02d854
    bool isCachable() const noexcept { return cachable_; }                    // 0x02d864
    size_t getReadBufferSize() const noexcept { return read_buffer_size_; }   // 0x02d86c
    void setReadBufferSize(size_t s) noexcept { read_buffer_size_ = s; }      // 0x02d874
    const OnFailedFunc& getOnFailedFunc() const noexcept { return on_failed_; } // 0x02d87c
    void setOnFailedFunc(OnFailedFunc&& cb) { on_failed_ = std::move(cb); }   // 0x02d884
    const OnResponseFunc& getOnResponseFunc() const noexcept { return on_response_; } // 0x02d91c
    void setOnResponseFunc(OnResponseFunc&& cb) { on_response_ = std::move(cb); }     // 0x02d924
    void setUserData(void* p) noexcept { user_data_ = p; }                    // 0x02d9bc
    void* getUserData() const noexcept { return user_data_; }                 // 0x02d9c4
    void setBodyType(HttpRequestBodyType t) noexcept { body_type_ = t; }      // 0x02d9cc
    void setBodyData(const std::string& b) { body_ = b; }                     // 0x02d9d4
    void setBodyData(std::string&& b) noexcept { body_ = std::move(b); }      // 0x02d9fc
    const std::string& getBody() const noexcept { return body_; }             // 0x02da74

private:
    HttpMethod method_ = HttpMethod::kGet;
    std::string url_;
    std::map<std::string, std::string> headers_;
    std::map<std::string, std::string> params_;
    bool cachable_ = false;
    size_t read_buffer_size_ = 32768;
    HttpRequestBodyType body_type_ = HttpRequestBodyType::kRaw;
    std::string body_;
    void* user_data_ = nullptr;
    OnFailedFunc on_failed_;
    OnResponseFunc on_response_;
};

class NetworkClient;

class NetworkClientBuilder {
public:
    NetworkClient* build(NetworkClientType type);                             // 0x02aa40
    NetworkClientBuilder& useQuic(bool v) noexcept { use_quic_ = v; return *this; } // 0x02b000
    NetworkClientBuilder& useHttp2(bool v) noexcept { use_http2_ = v; return *this; } // 0x02b00c
    NetworkClientBuilder& setUserAgent(const std::string& ua) { user_agent_ = ua; return *this; } // 0x02b018
    NetworkClientBuilder& setCacheMode(NetworkCacheMode m) noexcept { cache_mode_ = m; return *this; } // 0x02b0f8
    NetworkClientBuilder& setCacheMaxSize(long s) noexcept { cache_max_size_ = s; return *this; } // 0x02b100

    bool useQuic() const noexcept { return use_quic_; }                       // 0x02b108
    bool useHttp2() const noexcept { return use_http2_; }                     // 0x02b110
    const std::string& getUserAgent() const noexcept { return user_agent_; }  // 0x02b118
    NetworkCacheMode getCacheMode() const noexcept { return cache_mode_; }    // 0x02b120
    long getCacheMaxSize() const noexcept { return cache_max_size_; }         // 0x02b128

private:
    bool use_quic_ = true;
    bool use_http2_ = true;
    std::string user_agent_ = "AmazingEngine";
    NetworkCacheMode cache_mode_ = NetworkCacheMode::kDisabled;
    long cache_max_size_ = 0;
};

class NetworkClient : public RefBase {
public:
    NetworkClient() = default;
    ~NetworkClient() override;                                                // 0x02c460

    virtual bool init(const NetworkClientBuilder& builder);                   // 0x02ada4
    void onRequestResponse(NetworkCall* call, const NetworkResponse& resp, NetworkStatus status); // 0x02b130
    void onRequestFailed(NetworkCall* call, const NetworkError& err);         // 0x02b444
    void onRequestCanceled(NetworkCall* call);                                // 0x02b5cc
    NetworkCall* createCall(NetworkRequest* req);                             // 0x02b754
    bool initCall(NetworkCall* call, NetworkRequest* req);                    // 0x02ba34
    bool sendRequest(NetworkRequest* req, bool async);                        // 0x02ba7c
    bool isRunning() const noexcept { return running_; }                      // 0x02bfd0
    void cancelRequest(NetworkRequest* req);                                  // 0x02bfe0
    void shutdown();                                                          // 0x02c168
    void processLoadingTasks();                                               // 0x02c510

protected:
    bool running_ = false;
    void* cronet_engine_ = nullptr;
};

class NetworkClientWS : public RefBase {
public:
    using OnStateChanged = void (*)(void*, uint32_t, int, const char*);
    using OnError        = void (*)(void*, uint32_t, int, const char*, const char*);
    using OnMessageRecv  = void (*)(void*, uint32_t, const char*, size_t);
    using OnLogFeedback  = void (*)(void*, uint32_t, const char*);

    NetworkClientWS();                                                        // 0x02c57c
    ~NetworkClientWS() override;                                              // 0x02c604

    virtual bool initWS(void* ctx, uint32_t id, OnStateChanged s, OnError e, OnMessageRecv m, OnLogFeedback l); // 0x02c6bc
    virtual void shutdown();                                                  // 0x02c6c4
    virtual bool startConnect(const std::string& url);                        // 0x02c6cc
    virtual bool sendData(const std::string& payload);                        // 0x02c6d4
    virtual bool isConnected() const noexcept;                                // 0x02c6dc

private:
    bool connected_ = false;
};

// ============================================================================
// 5. PerformanceCap, PerformanceEvaluate, StatisticsFrameCost (0x036064 .. 0x037d60)
// ============================================================================
enum class PerformanceEvaluateType : int32_t {
    kRenderThread    = 0,
    kAlgorithmThread = 1,
    kFirstFrame      = 2,
    kEffectSwitch    = 3
};

enum class PerformanceEvaluateSwitchMode : int32_t {
    kRenderCost    = 0,
    kAlgorithmCost = 1,
    kFirstFrame    = 2,
    kEffectSwitch  = 3
};

class StatisticsFrameCost {
public:
    explicit StatisticsFrameCost(PerformanceEvaluateType type);               // 0x036818
    ~StatisticsFrameCost();                                                   // 0x0362e4

    void beginRecord();                                                       // 0x0368b4
    void beginRecord(const std::string& tag);                                 // 0x036914
    void setTiggersDirtyTagFalse(const std::string& tag);                     // 0x036a18
    void endRecord();                                                         // 0x036af8
    void endRecord(const std::string& tag);                                   // 0x0370d8
    void printLog();                                                          // 0x036cb8
    void reset();                                                             // 0x03704c
    void trigStatisticsPoint(const std::string& pointTag);                    // 0x037284
    double getTimeCost() const noexcept { return total_cost_ms_; }            // 0x037a50
    double getTimeCost(const std::string& pointTag) const;                    // 0x037a6c
    void resetTriggers();                                                     // 0x037c0c
    void setDirtyFalse(bool v) noexcept { dirty_ = v; }                       // 0x037d50

private:
    PerformanceEvaluateType type_;
    int32_t frame_count_ = 0;
    double start_time_sec_ = 0.0;
    double total_cost_ms_ = 0.0;
    bool dirty_ = false;
    std::string current_tag_;
    std::map<std::string, double> point_costs_ms_;
};

class PerformanceEvaluate {
public:
    PerformanceEvaluate();                                                    // 0x03657c
    void setSwitchStatus(PerformanceEvaluateSwitchMode mode, bool enabled);   // 0x0366b0
    bool getSwitchStatus(PerformanceEvaluateSwitchMode mode) const noexcept;  // 0x03671c

private:
    std::map<PerformanceEvaluateSwitchMode, bool> switches_;
};

class PerformanceCap {
public:
    PerformanceCap();                                                         // 0x036064
    ~PerformanceCap();

    PerformanceEvaluate* getEvaluateInstance() const noexcept { return evaluate_; } // 0x0362b0
    StatisticsFrameCost* getStatisticsFrameCost(PerformanceEvaluateType type);      // 0x0362b8

private:
    PerformanceEvaluate* evaluate_ = nullptr;                                 // +0x00
    std::vector<StatisticsFrameCost*> frame_costs_;                           // +0x08 .. +0x18
};

// ============================================================================
// 6. stb_truetype Font & Signed Distance Field (SDF) Engine (0x03acf0 .. 0x040cc8)
// ============================================================================
int stbtt_InitFont(stbtt_fontinfo* info, const unsigned char* data, int offset) noexcept; // 0x03e8c8
int stbtt_FindGlyphIndex(const stbtt_fontinfo* info, int unicode_codepoint) noexcept;     // 0x03acf0
int stbtt_GetCodepointShape(const stbtt_fontinfo* info, int unicode_codepoint, stbtt_vertex** vertices) noexcept; // 0x03affc
int stbtt_GetGlyphShape(const stbtt_fontinfo* info, int glyph_index, stbtt_vertex** vertices) noexcept;           // 0x03b02c
int stbtt_GetGlyphBox(const stbtt_fontinfo* info, int glyph_index, int* x0, int* y0, int* x1, int* y1) noexcept;  // 0x03bc18
int stbtt_GetCodepointBox(const stbtt_fontinfo* info, int codepoint, int* x0, int* y0, int* x1, int* y1) noexcept; // 0x03be20
void stbtt_GetGlyphHMetrics(const stbtt_fontinfo* info, int glyph_index, int* advanceWidth, int* leftSideBearing) noexcept; // 0x03be78
int stbtt_GetGlyphKernAdvance(const stbtt_fontinfo* info, int g1, int g2) noexcept;       // 0x03bf3c
int stbtt_GetCodepointKernAdvance(const stbtt_fontinfo* info, int ch1, int ch2) noexcept; // 0x03c418
void stbtt_GetCodepointHMetrics(const stbtt_fontinfo* info, int codepoint, int* advanceWidth, int* leftSideBearing) noexcept; // 0x03c488
void stbtt_GetFontVMetrics(const stbtt_fontinfo* info, int* ascent, int* descent, int* lineGap) noexcept;         // 0x03c574
int stbtt_GetFontVMetricsOS2(const stbtt_fontinfo* info, int* typoAscent, int* typoDescent, int* typoLineGap) noexcept; // 0x03c5f0
void stbtt_GetFontBoundingBox(const stbtt_fontinfo* info, int* x0, int* y0, int* x1, int* y1) noexcept;           // 0x03c6f4
float stbtt_ScaleForPixelHeight(const stbtt_fontinfo* info, float height) noexcept;       // 0x03c77c
float stbtt_ScaleForMappingEmToPixels(const stbtt_fontinfo* info, float pixels) noexcept; // 0x03c7c0
void stbtt_FreeShape(const stbtt_fontinfo* info, stbtt_vertex* v) noexcept;               // 0x03c7e4
void stbtt_GetGlyphBitmapBoxSubpixel(const stbtt_fontinfo* font, int glyph, float scale_x, float scale_y, float shift_x, float shift_y, int* ix0, int* iy0, int* ix1, int* iy1) noexcept; // 0x03c7ec
void stbtt_GetGlyphBitmapBox(const stbtt_fontinfo* font, int glyph, float scale_x, float scale_y, int* ix0, int* iy0, int* ix1, int* iy1) noexcept; // 0x03c934
void stbtt_GetCodepointBitmapBoxSubpixel(const stbtt_fontinfo* font, int codepoint, float scale_x, float scale_y, float shift_x, float shift_y, int* ix0, int* iy0, int* ix1, int* iy1) noexcept; // 0x03c940
void stbtt_GetCodepointBitmapBox(const stbtt_fontinfo* font, int codepoint, float scale_x, float scale_y, int* ix0, int* iy0, int* ix1, int* iy1) noexcept; // 0x03c9c8
void stbtt_FreeBitmap(unsigned char* bitmap, void* userdata) noexcept;                    // 0x03e4e0
unsigned char* stbtt_GetGlyphBitmapSubpixel(const stbtt_fontinfo* info, float scale_x, float scale_y, float shift_x, float shift_y, int glyph, int* width, int* height, int* xoff, int* yoff) noexcept; // 0x03e4e4
unsigned char* stbtt_GetGlyphBitmap(const stbtt_fontinfo* info, float scale_x, float scale_y, int glyph, int* width, int* height, int* xoff, int* yoff) noexcept; // 0x03e6f4
unsigned char* stbtt_GetCodepointBitmapSubpixel(const stbtt_fontinfo* info, float scale_x, float scale_y, float shift_x, float shift_y, int codepoint, int* width, int* height, int* xoff, int* yoff) noexcept; // 0x03e700
unsigned char* stbtt_GetCodepointBitmap(const stbtt_fontinfo* info, float scale_x, float scale_y, int codepoint, int* width, int* height, int* xoff, int* yoff) noexcept; // 0x03e788
void stbtt_GetBakedQuad(const stbtt_bakedchar* chardata, int pw, int ph, int char_index, float* xpos, float* ypos, stbtt_aligned_quad* q, int opengl_fillrule) noexcept; // 0x03e800
int stbtt_GetFontOffsetForIndex(const unsigned char* data, int index) noexcept;           // 0x03f608
void stbtt_GetScaledFontVMetrics(const unsigned char* fontdata, int index, float size, float* ascent, float* descent, float* lineGap) noexcept; // 0x03f6b8
void stbtt_GetPackedQuad(const stbtt_packedchar* chardata, int pw, int ph, int char_index, float* xpos, float* ypos, stbtt_aligned_quad* q, int align_to_integer) noexcept; // 0x03f804
unsigned char* stbtt_GetGlyphSDF(const stbtt_fontinfo* info, float scale, int glyph, int padding, unsigned char onedge_value, float pixel_dist_scale, int* width, int* height, int* xoff, int* yoff) noexcept; // 0x03f928
unsigned char* stbtt_GetCodepointSDF(const stbtt_fontinfo* info, float scale, int codepoint, int padding, unsigned char onedge_value, float pixel_dist_scale, int* width, int* height, int* xoff, int* yoff) noexcept; // 0x040844
void stbtt_FreeSDF(unsigned char* bitmap, void* userdata) noexcept;                       // 0x0408cc
const char* stbtt_GetFontNameString(const stbtt_fontinfo* font, int* length, int platformID, int encodingID, int languageID, int nameID) noexcept; // 0x0408d0
const char* stbtt_GetIndexFontNameString(const stbtt_fontinfo* font, int* length, int platformID, int encodingID, int languageID, int nameID, int index) noexcept; // 0x040a24
int stbtt_GetNumberOfFonts(const unsigned char* data) noexcept;                           // 0x040c34
int stbtt_FindMatchingFont(const unsigned char* fontdata, const char* name, int flags) noexcept; // 0x040cc8

} // namespace AmazingEngine
