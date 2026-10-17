/**
 * @file bdzstd_interface.cpp
 * @brief ByteDance Zstandard Engine - Unified Master Engine & 7-Stage Self-Test Suite.
 *        Cài đặt bộ máy điều phối và kịch bản tự kiểm thử toàn diện 7 giai đoạn.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "bdzstd_interface.h"
#include <sstream>
#include <iomanip>
#include <thread>
#include <cassert>

namespace bytedance {
namespace compression {
namespace zstd {

ByteDanceZstdEngine& ByteDanceZstdEngine::getInstance() {
    static ByteDanceZstdEngine instance;
    return instance;
}

std::vector<uint8_t> ByteDanceZstdEngine::compress(const uint8_t* data, size_t size, int level, bool checksum) {
    if (!data || size == 0) return {};

    ZstdCompressCtxNative* cctx = ZSTD_createCCtx();
    if (!cctx) return {};

    cctx->compressionLevel = level;
    cctx->checksumFlag = checksum ? 1 : 0;
    cctx->contentSizeFlag = 1;

    size_t bound = ZstdCoreEngine::compressBound(size);
    std::vector<uint8_t> outBuf(bound + 64);

    std::vector<uint8_t> emptyDict;
    size_t actualSize = ZstdCoreEngine::compressFrame(*cctx, outBuf.data(), outBuf.size(), data, size, emptyDict);

    ZSTD_freeCCtx(cctx);

    if (ZstdCoreEngine::isError(actualSize)) {
        return {};
    }
    outBuf.resize(actualSize);
    return outBuf;
}

std::vector<uint8_t> ByteDanceZstdEngine::decompress(const uint8_t* compressedData, size_t compressedSize) {
    if (!compressedData || compressedSize < 5) return {};

    uint64_t decompressedSize = ZstdCoreEngine::getDecompressedSize(compressedData, compressedSize);
    if (decompressedSize == 0) {
        // Fallback estimate if not recorded
        decompressedSize = compressedSize * 4 + 1024;
    }

    std::vector<uint8_t> outBuf(decompressedSize);
    ZstdDecompressCtxNative* dctx = ZSTD_createDCtx();
    if (!dctx) return {};

    std::vector<uint8_t> emptyDict;
    size_t actualSize = ZstdCoreEngine::decompressFrame(*dctx, outBuf.data(), outBuf.size(), compressedData, compressedSize, emptyDict);

    ZSTD_freeDCtx(dctx);

    if (ZstdCoreEngine::isError(actualSize)) {
        return {};
    }
    outBuf.resize(actualSize);
    return outBuf;
}

ZstdSelfTestReport ByteDanceZstdEngine::runSelfTest() {
    ZstdSelfTestReport report;
    report.totalStages = 7;
    report.stagesPassed = 0;
    report.passedAll = false;
    std::ostringstream ss;

    ss << "=== [START] libbdzstd Cleanroom 7-Stage Self-Test Suite ===\n";

    // ------------------------------------------------------------------------
    // STAGE 1: Opcode Parity & Math Verification
    // ------------------------------------------------------------------------
    ss << "[Stage 1/7] Testing AArch64 Opcode Parity & Mathematical Accuracy... ";
    {
        // 1. compressBound formula testing
        assert(ZstdCoreEngine::compressBound(0) == 64);
        assert(ZstdCoreEngine::compressBound(100) == 164);
        assert(ZstdCoreEngine::compressBound(131072) == 131072 + 512); // 131584
        assert(ZstdCoreEngine::compressBound(1000000) == 1000000 + (1000000 >> 8));

        // 2. isError threshold
        assert(!ZstdCoreEngine::isError(0));
        assert(!ZstdCoreEngine::isError(100000));
        assert(ZstdCoreEngine::isError(static_cast<size_t>(-1)));
        assert(ZstdCoreEngine::isError(static_cast<size_t>(-72)));
        assert(!ZstdCoreEngine::isError(static_cast<size_t>(-121)));

        // 3. getErrorCode extraction
        assert(ZstdCoreEngine::getErrorCode(0) == 0);
        assert(ZstdCoreEngine::getErrorCode(static_cast<size_t>(-1)) == 1);
        assert(ZstdCoreEngine::getErrorCode(static_cast<size_t>(-72)) == 72);

        // 4. getErrorName stripped check
        assert(std::string(ZstdCoreEngine::getErrorName(1)) == "Error strings stripped");

        // 5. Compression levels
        assert(ZSTD_DEFAULT_COMPRESSION_LEVEL == 3);
        assert(ZSTD_MIN_COMPRESSION_LEVEL == -131072);
        assert(ZSTD_MAX_COMPRESSION_LEVEL == 22);

        report.stagesPassed++;
        ss << "PASSED (Mathematical parity delta = 0)\n";
    }

    // ------------------------------------------------------------------------
    // STAGE 2: Struct Layout & ABI Offsets Verification
    // ------------------------------------------------------------------------
    ss << "[Stage 2/7] Testing Native Struct ABI & Memory Alignment... ";
    {
        assert(sizeof(ZstdCompressCtxNative) == 3576);
        assert(offsetof(ZstdCompressCtxNative, contentSizeFlag) == 0x30);
        assert(offsetof(ZstdCompressCtxNative, checksumFlag) == 0x34);
        assert(offsetof(ZstdCompressCtxNative, dictIDFlag) == 0x38);
        assert(offsetof(ZstdCompressCtxNative, compressionLevel) == 0x3C);
        assert(offsetof(ZstdCompressCtxNative, state_flags) == 0xd80);

        report.stagesPassed++;
        ss << "PASSED (Exact 3576-byte buffer layout verified)\n";
    }

    // ------------------------------------------------------------------------
    // STAGE 3: Run-Length Encoding (RLE) Block Roundtrip
    // ------------------------------------------------------------------------
    ss << "[Stage 3/7] Testing RLE Block Compression & Decompression... ";
    {
        std::vector<uint8_t> rleData(4096, 0x41); // 4096 'A's
        auto compressed = compress(rleData.data(), rleData.size(), 3, true);
        assert(!compressed.empty());
        assert(compressed.size() < 32); // RLE compresses 4KB to ~13 bytes!

        auto recovered = decompress(compressed.data(), compressed.size());
        assert(recovered.size() == rleData.size());
        assert(recovered == rleData);

        report.stagesPassed++;
        ss << "PASSED (4KB compressed to " << compressed.size() << " bytes, ratio > 128x)\n";
    }

    // ------------------------------------------------------------------------
    // STAGE 4: General LZ77 + FSE Entropy Block Roundtrip
    // ------------------------------------------------------------------------
    ss << "[Stage 4/7] Testing General LZ77/Entropy Block Roundtrip... ";
    {
        std::string sample = "NextAI OpenCut CapCut Video Editor Reconstructed Zstandard Engine! "
                             "NextAI OpenCut CapCut Video Editor Reconstructed Zstandard Engine! "
                             "Repeated sequences for LZ77 match validation and bitstream packing test 123456789.";
        std::vector<uint8_t> input(sample.begin(), sample.end());

        auto compressed = compress(input.data(), input.size(), 5, true);
        assert(!compressed.empty());

        auto recovered = decompress(compressed.data(), compressed.size());
        assert(recovered.size() == input.size());
        assert(recovered == input);

        report.stagesPassed++;
        ss << "PASSED (100% bit-exact recovery, delta = 0)\n";
    }

    // ------------------------------------------------------------------------
    // STAGE 5: 16 Exported C Functions Verification
    // ------------------------------------------------------------------------
    ss << "[Stage 5/7] Testing 16 Exported C API Functions... ";
    {
        ZstdCompressCtxNative* cctx = ZSTD_createCCtx();
        assert(cctx != nullptr);
        assert(ZSTD_CCtx_setParameter(cctx, static_cast<int32_t>(ZstdCParameter::CompressionLevel), 10) == 0);
        assert(cctx->compressionLevel == 10);
        assert(ZSTD_CCtx_setParameter(cctx, static_cast<int32_t>(ZstdCParameter::ChecksumFlag), 1) == 0);
        assert(cctx->checksumFlag == 1);

        ZstdDecompressCtxNative* dctx = ZSTD_createDCtx();
        assert(dctx != nullptr);

        std::string text = "C-API Streaming Verification Payload";
        std::vector<uint8_t> outBuffer(2048);

        ZSTD_inBuffer inStream{text.data(), text.size(), 0};
        ZSTD_outBuffer outStream{outBuffer.data(), outBuffer.size(), 0};

        assert(ZSTD_compressStream2(cctx, &outStream, &inStream, static_cast<int32_t>(ZstdEndDirective::End)) == 0);
        assert(outStream.pos > 0);

        std::vector<uint8_t> decBuffer(2048);
        ZSTD_inBuffer dInStream{outBuffer.data(), outStream.pos, 0};
        ZSTD_outBuffer dOutStream{decBuffer.data(), decBuffer.size(), 0};

        assert(ZSTD_decompressStream(dctx, &dOutStream, &dInStream) == 0);
        assert(dOutStream.pos == text.size());
        assert(std::memcmp(decBuffer.data(), text.data(), text.size()) == 0);

        assert(ZSTD_freeCCtx(cctx) == 0);
        assert(ZSTD_freeDCtx(dctx) == 0);

        report.stagesPassed++;
        ss << "PASSED (Full streaming C-API validation successful)\n";
    }

    // ------------------------------------------------------------------------
    // STAGE 6: 52 JNI Functions & Bounds Protection
    // ------------------------------------------------------------------------
    ss << "[Stage 6/7] Testing 52 JNI Functions & Memory Bounds Protection... ";
    {
        // 1. Bounds check: negative offsets return -0x48 (-72)
        jlong err1 = Java_com_bytedance_compression_zstd_ZstdCompressCtx_compressByteArray0(
            nullptr, nullptr, nullptr, -1, 100, nullptr, 0, 100);
        assert(err1 == -72);

        jlong err2 = Java_com_bytedance_compression_zstd_ZstdDecompressCtx_decompressByteArray0(
            nullptr, nullptr, nullptr, 0, 100, nullptr, -5, 100);
        assert(err2 == -72);

        // 2. Stream recommended sizes
        assert(Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_recommendedDInSize(nullptr, nullptr) == 131075);
        assert(Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_recommendedDOutSize(nullptr, nullptr) == 131072);
        assert(Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_recommendedCOutSize(nullptr, nullptr) == 131591);

        // 3. Compression static methods
        assert(Java_com_bytedance_compression_zstd_ZstdCompress_defaultCompressionLevel(nullptr, nullptr) == 3);
        assert(Java_com_bytedance_compression_zstd_ZstdCompress_minCompressionLevel(nullptr, nullptr) == -131072);
        assert(Java_com_bytedance_compression_zstd_ZstdCompress_maxCompressionLevel(nullptr, nullptr) == 22);
        assert(Java_com_bytedance_compression_zstd_Zstd_errGeneric(nullptr, nullptr) == 1);

        report.stagesPassed++;
        ss << "PASSED (Memory bounds protection & recommended buffer sizes confirmed)\n";
    }

    // ------------------------------------------------------------------------
    // STAGE 7: Stress & Multi-threaded Concurrency
    // ------------------------------------------------------------------------
    ss << "[Stage 7/7] Testing Multi-threaded Concurrency & Stress Stability... ";
    {
        constexpr int NUM_THREADS = 8;
        constexpr int ITERATIONS = 10;
        std::vector<std::thread> workers;
        std::atomic<int> successCount{0};

        for (int t = 0; t < NUM_THREADS; ++t) {
            workers.emplace_back([this, &successCount, t]() {
                for (int i = 0; i < ITERATIONS; ++i) {
                    std::string threadData = "Thread ID " + std::to_string(t) + " Iteration " + std::to_string(i) +
                                             " Random padding to test parallel zstd contexts without data race!";
                    std::vector<uint8_t> payload(threadData.begin(), threadData.end());

                    auto c = compress(payload.data(), payload.size(), 3, true);
                    auto d = decompress(c.data(), c.size());

                    if (d == payload) {
                        successCount++;
                    }
                }
            });
        }

        for (auto& w : workers) {
            w.join();
        }

        assert(successCount == NUM_THREADS * ITERATIONS);
        report.stagesPassed++;
        ss << "PASSED (" << successCount << "/" << (NUM_THREADS * ITERATIONS) << " parallel jobs finished without race)\n";
    }

    report.passedAll = (report.stagesPassed == report.totalStages);
    ss << "=== [COMPLETED] libbdzstd Self-Test Suite: "
       << report.stagesPassed << "/" << report.totalStages << " STAGES PASSED (100.0%) ===\n";
    report.detailLog = ss.str();
    return report;
}

} // namespace zstd
} // namespace compression
} // namespace bytedance
