/**
 * @file avmdlbase_tls_quic.h
 * @brief ByteDance Mobile Download Base - TLS Connection & QUIC Transport Wrapper.
 *        Mô-đun kết nối bảo mật TLS và bao gói giao thức QUIC trong libavmdlbase.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef AVMDLBASE_TLS_QUIC_H
#define AVMDLBASE_TLS_QUIC_H

#include "avmdlbase_types.h"
#include <string>
#include <vector>
#include <memory>
#include <atomic>

namespace com {
namespace ss {
namespace ttmio {

/**
 * @brief MIOConnTLS: TLS secure connection matching binary offset 0x033850 (1,228 bytes).
 *        Vtable offset: 0x0735c0 (376 bytes).
 */
class MIOConnTLS {
public:
    static int32_t SSLDataIndex; // 0x078000
    static bool    SSLHasInit;   // 0x078050

    MIOConnTLS();
    virtual ~MIOConnTLS();

    /**
     * @brief Opens secure TLS connection with target host.
     *        Opcode 0x033850 (1,228 bytes).
     */
    virtual bool open(const MIOConfig& config);

    /**
     * @brief Initiates non-blocking socket connect.
     *        Opcode 0x034494 (712 bytes).
     */
    virtual bool startConnect();

    /**
     * @brief Creates and binds TCP socket.
     *        Opcode 0x0348bc (596 bytes).
     */
    virtual int32_t createTcpSocket();

    /**
     * @brief Notifies callback listener when TCP handshake completes.
     *        Opcode 0x035544 (544 bytes).
     */
    virtual void notifyTcpConnected();

    /**
     * @brief Sends payload over TLS stream.
     */
    virtual size_t sendData(const uint8_t* data, size_t len);

    /**
     * @brief Receives payload from TLS stream.
     */
    virtual size_t recvData(uint8_t* outBuf, size_t maxLen);

    virtual void close();

    bool isConnected() const noexcept { return mIsConnected.load(); }
    std::string getNegotiatedProtocol() const { return mNegotiatedAlpn; }

private:
    MIOConfig         mConfig;
    std::atomic<bool> mIsConnected{false};
    int32_t           mSocketFd = -1;
    std::string       mNegotiatedAlpn;
    void*             mSslContext = nullptr;
    void*             mSslSession = nullptr;
};

/**
 * @brief MIOTTQuicTransWrapper: QUIC transport wrapper matching binary offset 0x03b2f4 (3,232 bytes).
 *        Vtable offset: 0x074ca0 (200 bytes).
 */
class MIOTTQuicTransWrapper {
public:
    MIOTTQuicTransWrapper();
    virtual ~MIOTTQuicTransWrapper();

    /**
     * @brief Dynamically loads and resolves QUIC transport driver functions.
     *        Opcode 0x03b2f4 (3,232 bytes - largest method in libavmdlbase.so).
     */
    virtual bool load();

    virtual bool isLoaded() const noexcept { return mIsLoaded.load(); }
    virtual std::string getQuicVersion() const { return mQuicVersion; }

private:
    std::atomic<bool> mIsLoaded{false};
    void*             mLibraryHandle = nullptr;
    std::string       mQuicVersion;

    // Function pointers resolved from libttquic.so
    void* (*pfn_quic_engine_create)(void*) = nullptr;
    void (*pfn_quic_engine_destroy)(void*) = nullptr;
    void* (*pfn_quic_session_create)(void*, const char*, int) = nullptr;
    int (*pfn_quic_stream_write)(void*, const void*, size_t) = nullptr;
    int (*pfn_quic_stream_read)(void*, void*, size_t) = nullptr;
};

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // AVMDLBASE_TLS_QUIC_H
