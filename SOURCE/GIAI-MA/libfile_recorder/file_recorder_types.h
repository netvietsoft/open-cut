// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: File Recorder & Storage Integrity Types
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FILE_RECORDER_TYPES_H
#define NEXTAI_OPENCUT_FILE_RECORDER_TYPES_H

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <functional>
#include <memory>

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

/**
 * @brief Hook operating modes from ByteHook library.
 * Chế độ vận hành can thiệp hàm từ thư viện ByteHook.
 */
enum class ByteHookMode : int32_t {
    AUTOMATIC = 0, ///< Automatic stack pop / Tự động dọn dẹp ngăn xếp
    MANUAL = 1     ///< Manual stack pop / Thủ công dọn dẹp ngăn xếp qua bytehook_pop_stack
};

/**
 * @brief Monitored storage categories identified in libfile_recorder.so rodata.
 * Phân loại các danh mục lưu trữ được giám sát trong rodata của libfile_recorder.so.
 */
enum class StorageCategory : uint32_t {
    UNKNOWN = 0,
    SHARED_PREFS = 1, ///< Whitelisted XML configs (/shared_prefs/, offset 0x8452)
    KEVA_KV = 2,       ///< ByteDance high-perf key-value storage (/keva/, offset 0x8461)
    DATABASES = 3,     ///< SQLite databases directory (/databases/, offset 0x8468)
    DB_LOCK = 4,       ///< Database lock sentinel (.db.lck, offset 0x8474)
    PROTECTED_APP = 5  ///< Monitored illegal removal target path
};

/**
 * @brief Crash check parameters configured via JNI nativeUpdateFileCheckParams.
 * Tham số kiểm tra sự cố được cấu hình qua JNI nativeUpdateFileCheckParams.
 */
struct FileCheckParams {
    std::string check_param_char1; ///< Sensitive path substring 1 (offset 0x10138)
    std::string check_param_char2; ///< Sensitive path substring 2 (offset 0x10140)
    bool is_active{false};         ///< True if check params are set
};

/**
 * @brief Access record emitted by hooked open/open64 calls.
 * Bản ghi truy cập tệp được phát ra bởi các lệnh can thiệp open/open64.
 */
struct FileAccessEvent {
    std::string pathname;      ///< Absolute or relative path / Đường dẫn tệp
    int32_t flags{0};          ///< POSIX open flags (O_RDONLY, O_WRONLY, O_CREAT, etc.)
    int32_t mode{0};           ///< POSIX file mode permissions
    int32_t result_fd{-1};     ///< File descriptor returned / Descriptor tệp trả về
    int64_t timestamp_ms{0};   ///< Access timestamp in milliseconds / Dấu thời gian (ms)
    bool is_whitelisted{false};///< Matched /shared_prefs/, /keva/, or /databases/
    bool is_crash_trigger{false}; ///< Matched crash check patterns
};

/**
 * @brief Illegal remove attempt event recorded by unlinkat hook.
 * Sự kiện cố gắng xóa tệp trái phép được ghi nhận bởi hook unlinkat.
 */
struct IllegalRemoveEvent {
    int32_t dirfd{-1};         ///< Directory file descriptor
    std::string pathname;      ///< Path of file attempted to be unlinked
    int32_t flags{0};          ///< AT_REMOVEDIR or other flags
    bool blocked{false};       ///< Whether the unlink operation was intercepted/blocked
    int64_t timestamp_ms{0};   ///< Interception timestamp
};

/**
 * @brief Constants extracted from libfile_recorder.so binary.
 * Các hằng số trích xuất từ nhị phân libfile_recorder.so.
 */
namespace BinaryConstants {
    /// JNI Version returned by JNI_OnLoad (0x10006 = JNI_VERSION_1_6, opcode 0x1c18)
    constexpr int32_t JNI_VERSION_1_6 = 0x00010006;

    /// Target Java Class in JNI registry (offset 0x80b8)
    constexpr const char* JNI_CLASS_NAME = "com/bytedance/osfix/disk/jni/JniNative";

    /// Sentinel string used to cleanly terminate the background worker thread (offset 0x848b)
    constexpr const char* THREAD_TERMINATE_SENTINEL = "___terminate_thread_work___";

    /// Sensitive file path patterns monitored by check_file_path (0x31b0)
    constexpr const char* PATTERN_SHARED_PREFS = "/shared_prefs/"; // offset 0x8452
    constexpr const char* PATTERN_KEVA = "/keva/";                 // offset 0x8461
    constexpr const char* PATTERN_DATABASES = "/databases/";       // offset 0x8468
    constexpr const char* PATTERN_DB_LOCK = ".db.lck";             // offset 0x8474

    /// Crash alert banner strings
    constexpr const char* CRASH_BANNER_FATAL = "-------------------------------Fatal CRASH--------------------------------"; // 0x83fb
    constexpr const char* CRASH_MSG_FORMAT = "------------Crash happened with pathname is %s,please contact @chenliguan---------"; // 0x83aa, 0x83d6
    constexpr const char* CRASH_CHECK_PARAM1 = "Crash checkParamChar1"; // 0x837e
    constexpr const char* CRASH_CHECK_PARAM2 = "Crash checkParamChar2"; // 0x8394
    constexpr const char* PRE_OPEN_LOG = ">>>>> bytehook pre open(), pathname:"; // 0x8347

    /// Mathematical fixed-point multiplier for division by 1,000,000 (0x431bde82d7b634db)
    /// 0x431bde82d7b634db / 2^(64 + 18) = 10^-6 (Microseconds to Seconds conversion)
    constexpr uint64_t FIXED_POINT_TIME_DIVISOR = 0x431bde82d7b634dbULL;
    constexpr int32_t FIXED_POINT_TIME_SHIFT = 18;
}

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_FILE_RECORDER_TYPES_H
