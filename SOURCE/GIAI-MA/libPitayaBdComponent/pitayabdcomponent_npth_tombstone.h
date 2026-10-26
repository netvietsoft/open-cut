/**
 * @file pitayabdcomponent_npth_tombstone.h
 * @brief PitayaNpthUtil Crash Tombstone Generator, OriginStack Parser & ELF BuildId Resolver (Target 46).
 *        Bộ sinh Tombstone sự cố PitayaNpthUtil, trình phân tích OriginStack và giải mã ELF BuildId (Mục tiêu 46).
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - Class: pitaya::PitayaNpthUtil (72 bytes / 0x48 bytes allocated at 0x002848)
 * - Exported Symbol:
 *   _ZN6pitaya14PitayaNpthUtil16GenerteTombstoneENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
 *   (@ 0x002898, 488 bytes)
 * - Internal Methods:
 *   - Instance() (@ 0x002804, 148 bytes, .bss guard @ 0x01c000, shared_ptr @ 0x01c008)
 *   - ParseOriginStack() (@ 0x002a80, 5,656 bytes)
 *   - WriteThreadTombstone() (@ 0x004098, 448 bytes)
 *   - WriteBuildIds() (@ 0x004258, 380 bytes)
 *   - SnprintfWrapper() (@ 0x0043d8, 164 bytes)
 *   - GetBuildIdForSo() (@ 0x00447c, 236 bytes)
 *   - ExtractSoPathFromFrame() (@ 0x004568, 620 bytes)
 *   - VectorInsertThreadStackInfo() (@ 0x0048b8, 804 bytes)
 */

#ifndef NEXTAI_OPENCUT_PITAYABDCOMPONENT_NPTH_TOMBSTONE_H_
#define NEXTAI_OPENCUT_PITAYABDCOMPONENT_NPTH_TOMBSTONE_H_

#include "pitayabdcomponent_types.h"

#include <memory>
#include <mutex>
#include <set>
#include <string>
#include <vector>

// External C hooks imported from libnpth_dumper.so / libnpth_dl.so (PLT 0x002380, 0x0024f0)
// Các hàm C ngoại vi được nhập từ libnpth_dumper.so / libnpth_dl.so (PLT 0x002380, 0x0024f0)
extern "C" {
const char* npth_bt_all(const char* dir_path);
const char* npth_dlbuildid(const char* so_path);
}

namespace pitaya {

/**
 * @class PitayaNpthUtil
 * @brief Singleton utility for capturing all thread backtraces via NPTH and formatting tombstone.txt.
 *        Tiện ích Singleton thu thập toàn bộ ngăn xếp luồng qua NPTH và định dạng tệp tombstone.txt.
 *
 * Exact 72-byte (0x48) AArch64 ABI layout verified at 0x002848..0x00286c & 0x0040cc..0x00411c:
 * - +0x00..+0x17: std::string pid_           (24B, extracted via regex "pid (\\d+)" from "----- pid")
 * - +0x18..+0x2f: std::string process_name_  (24B, extracted via regex "Cmd line: (.+)" from "Cmd line: ")
 * - +0x30..+0x47: std::set<std::string> cached_modules_ (24B RB-tree initialized with __begin_node_ = this + 0x38)
 */
class PitayaNpthUtil {
public:
    /**
     * Constructs a 72-byte PitayaNpthUtil instance.
     * Khởi tạo thực thể PitayaNpthUtil 72 byte.
     * Disassembly @ 0x002848..0x00286c.
     */
    PitayaNpthUtil();
    ~PitayaNpthUtil() = default;

    /**
     * Thread-safe Meyers singleton returning std::shared_ptr<PitayaNpthUtil>&.
     * Singleton Meyers an toàn đa luồng trả về tham chiếu std::shared_ptr<PitayaNpthUtil>&.
     * Disassembly @ 0x002804..0x002894 (148 bytes, .bss 0x01c000 / 0x01c008).
     */
    static std::shared_ptr<PitayaNpthUtil>& Instance();

    /**
     * Exported symbol: _ZN6pitaya14PitayaNpthUtil16GenerteTombstoneENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
     * Generates "%s/tombstone.txt" by invoking npth_bt_all(), parsing origin stacks, prioritizing
     * "pty-ord-t" Pitaya threads at the top, and resolving ELF BuildIds via npth_dlbuildid().
     * Sinh tệp "%s/tombstone.txt" bằng cách gọi npth_bt_all(), phân tích ngăn xếp gốc, ưu tiên
     * đưa các luồng Pitaya "pty-ord-t" lên đầu và giải mã ELF BuildId qua npth_dlbuildid().
     * Disassembly @ 0x002898..0x002a7c (488 bytes).
     */
    void GenerteTombstone(std::string dir_path);

    /**
     * Parses raw NPTH multi-thread stack dump into ordered vector of 96-byte ThreadStackInfo records.
     * Phân tích dữ liệu ngăn xếp đa luồng thô từ NPTH thành vector có thứ tự các bản ghi ThreadStackInfo 96 byte.
     * Disassembly @ 0x002a80..0x004094 (5,656 bytes).
     */
    void ParseOriginStack(const std::string& origin_stack,
                          std::vector<bdcomponent::ThreadStackInfo>* out_threads);

    /**
     * Formats and writes a single ThreadStackInfo block (header, backtrace, build ids, 64-byte separator) to fd.
     * Định dạng và ghi một khối ThreadStackInfo (tiêu đề, backtrace, build id, dải phân cách 64 byte) vào fd.
     * Disassembly @ 0x004098..0x004254 (448 bytes).
     */
    int WriteThreadTombstone(int fd, const bdcomponent::ThreadStackInfo& thread_info) const;

    /**
     * Formats and writes the "build id:\n" section for all unique .so paths in a thread's backtrace.
     * Định dạng và ghi phần "build id:\n" cho tất cả đường dẫn .so duy nhất trong backtrace của luồng.
     * Disassembly @ 0x004258..0x0043d4 (380 bytes).
     */
    int WriteBuildIds(int fd, const bdcomponent::ThreadStackInfo& thread_info) const;

    /**
     * Queries npth_dlbuildid(so_path.c_str()) and wraps the result in a std::string.
     * Truy vấn npth_dlbuildid(so_path.c_str()) và đóng gói kết quả vào std::string.
     * Disassembly @ 0x00447c..0x004564 (236 bytes).
     */
    static std::string GetBuildIdForSo(const std::string& so_path);

    /**
     * Trims leading/trailing spaces (0x20) from a "#00 pc <addr> <so_path> ..." frame line and extracts
     * the 4th whitespace-delimited token (after 3 space transitions: w12 == 3 -> 4).
     * Cắt khoảng trắng đầu/cuối (0x20) khỏi dòng khung "#00 pc <addr> <so_path> ..." và trích xuất
     * token thứ 4 phân tách bởi khoảng trắng (sau 3 bước chuyển khoảng trắng: w12 == 3 -> 4).
     * Disassembly @ 0x004568..0x0047d8 (620 bytes).
     */
    static std::string ExtractSoPathFromFrame(const std::string& frame_line);

    /**
     * Formats a complete tombstone text in memory (used by both file writer and unit tests).
     * Định dạng toàn bộ văn bản tombstone trong bộ nhớ (dùng cho cả trình ghi tệp và kiểm thử đơn vị).
     */
    std::string FormatThreadTombstoneString(const bdcomponent::ThreadStackInfo& thread_info) const;

    const std::string& pid() const noexcept { return pid_; }
    const std::string& process_name() const noexcept { return process_name_; }
    const std::set<std::string>& cached_modules() const noexcept { return cached_modules_; }

    // Test/mock configuration for deterministic offline verification
    // Cấu hình kiểm thử/giả lập phục vụ xác minh ngoại tuyến tất định
    static void SetMockOriginStackDump(const std::string& mock_dump);
    static void RegisterMockBuildId(const std::string& so_path, const std::string& build_id);
    static const std::string& GetLastGeneratedTombstoneContent();

private:
    std::string pid_;                   // +0x00 (24B)
    std::string process_name_;          // +0x18 (24B)
    std::set<std::string> cached_modules_; // +0x30 (24B)
};

}  // namespace pitaya

#endif  // NEXTAI_OPENCUT_PITAYABDCOMPONENT_NPTH_TOMBSTONE_H_
