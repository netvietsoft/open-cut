// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: ByteVC1 Dynamic Library Loader (bytevc1_lib_loader.cc, Opcode 0x4660)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_ANIMAX_BYTEVC1_LOADER_H
#define NEXTAI_OPENCUT_ANIMAX_BYTEVC1_LOADER_H

#include "animax_bytevc1_types.h"
#include <string>
#include <mutex>
#include <memory>

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

/**
 * @brief Dynamic loader and symbol resolver for ByteDance libByteVC1_dec.so.
 * Trình nạp động và phân giải biểu tượng cho thư viện libByteVC1_dec.so của ByteDance.
 * 
 * Reconstructed from:
 * - 0x004660 - 0x004938: ByteVC1LibLoader::LoadLibrary
 * - ABI v1 vs v2 version negotiation (opcodes 0x4788, 0x4790)
 */
class ByteVC1LibLoader {
public:
    static ByteVC1LibLoader& getInstance();

    /**
     * @brief Attempt to load libByteVC1_dec.so and resolve all symbols (opcode 0x4660).
     * Cố gắng nạp libByteVC1_dec.so và phân giải toàn bộ 28 biểu tượng.
     * 
     * @param custom_path Optional file path to libByteVC1_dec.so
     * @return true if successfully loaded, false otherwise
     */
    bool loadLibrary(const std::string& custom_path = "");

    /**
     * @brief Unload library handle and release all symbols.
     * Giải phóng thư viện và hủy các con trỏ hàm.
     */
    void unloadLibrary();

    /**
     * @brief Check whether symbols are resolved and ready for decoding.
     * Kiểm tra xem các biểu tượng đã sẵn sàng giải mã hay chưa.
     */
    bool isLoaded() const;

    /**
     * @brief Access resolved function table.
     * Truy xuất bảng ký hiệu hàm đã nạp.
     */
    const ByteVC1SymbolsTable& getSymbols() const { return m_symbols; }

    /**
     * @brief Enable cleanroom synthetic software decoder emulation.
     * Bật cơ chế mô phỏng giải mã phần mềm sạch phục vụ kiểm thử khép kín không phụ thuộc blob bên ngoài.
     */
    void enableSoftwareEmulation(bool enable);

    /**
     * @brief Get count of successfully bound function pointers.
     * Lấy số lượng con trỏ hàm đã được liên kết thành công.
     */
    size_t getBoundSymbolCount() const;

private:
    ByteVC1LibLoader();
    ~ByteVC1LibLoader();

    void setupSoftwareEmulationSymbols();

    mutable std::mutex m_mutex;
    void* m_so_handle{nullptr};
    ByteVC1SymbolsTable m_symbols;
    bool m_emulation_enabled{false};
};

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_ANIMAX_BYTEVC1_LOADER_H
