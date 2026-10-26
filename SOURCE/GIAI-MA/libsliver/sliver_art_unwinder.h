/**
 * @file sliver_art_unwinder.h
 * @brief Multi-Android Dalvik/ART StackVisitor & Thread Unwinder (API 19..34).
 *        Bộ giải mã ngăn xếp Dalvik/ART đa phiên bản Android (API 19..34).
 *
 * Binary Ground Truth / Thực tế Nhị phân (OBSERVED):
 * - Factory & Dispatch: 0x003b40..0x003d80, 0x004d70..0x004fb0, 0x00700c..0x007134
 * - Thread State & Method Formatter: 0x007800..0x007e68
 * - ArtMethod Size & QuickFrame Offset Probing: 0x00e1b8..0x00e1fc
 * - VTables in .data.rel.ro:
 *   - ArtHelperBase:  0x017420
 *   - DvmHelper (19): 0x017460
 *   - ArtHelper4 (19..20):  0x0174c8 (StackVisitor4 @ 0x0174a0, size 0x830)
 *   - ArtHelper5 (21..22):  0x0176d0 (StackVisitor5 @ 0x0176a8, size 0x830)
 *   - ArtHelper6 (23):      0x017738 (StackVisitor6 @ 0x017710, size 0x838)
 *   - ArtHelper7 (24..25):  0x0177a0 (StackVisitor7 @ 0x017778, size 0x838)
 *   - ArtHelper8_0 (26):    0x017808 (StackVisitor8_0 @ 0x0177e0, size 0x838)
 *   - ArtHelper8_1 (27):    0x017870 (StackVisitor8_1 @ 0x017848, size 0x838)
 *   - ArtHelper9 (28):      0x0178d8 (StackVisitor9 @ 0x0178b0, size 0x838)
 *   - ArtHelper10 (29):     0x017940 (StackVisitor10 @ 0x017918, size 0x838)
 *   - ArtHelper11 (30):     0x0179a8 (StackVisitor11 @ 0x017980, size 0x838)
 *   - ArtHelper12 (31..32): 0x017a10 (StackVisitor12 @ 0x0179e8, size 0x838)
 *   - ArtHelper13 (33):     0x017a78 (StackVisitor13 @ 0x017a50, size 0x838)
 *   - ArtHelper14 (34):     0x017ae0 (StackVisitor14 @ 0x017ab8, size 0x838)
 */

#pragma once

#include "sliver_types.h"
#include <string>
#include <vector>

namespace bytedance {
namespace sliver {

/**
 * @brief Symbol table resolved from libart.so or libdvm.so for a specific Android SDK.
 *        Bảng ký hiệu phân giải từ libart.so hoặc libdvm.so cho một phiên bản Android SDK cụ thể.
 *
 * Binary Layout (64..72 bytes, initialized at 0x005548..0x005764):
 *   +0x00: void* thread_list_ptr      (_ZN3art7Runtime9instance_E -> ThreadList*)
 *   +0x08: void* suspend_by_peer_fn   (SuspendThreadByPeer)
 *   +0x10: void* suspend_by_tid_fn    (SuspendThreadByThreadId)
 *   +0x18: void* resume_fn            (ThreadList::Resume)
 *   +0x20: void* pretty_method_fn     (ArtMethod::PrettyMethod)
 *   +0x28: void* walk_stack_fn        (StackVisitor::WalkStack)
 *   +0x30: void* fetch_state_fn       (Monitor::FetchState)
 *   +0x38: void* describe_wait_fn     (Thread::DescribeWait)
 *   +0x40: bool  symbols_resolved
 */
struct ArtSymbolTable {
    void* thread_list_ptr{nullptr};    // +0x00
    void* suspend_by_peer_fn{nullptr}; // +0x08
    void* suspend_by_tid_fn{nullptr};  // +0x10
    void* resume_fn{nullptr};          // +0x18
    void* pretty_method_fn{nullptr};   // +0x20
    void* walk_stack_fn{nullptr};      // +0x28
    void* fetch_state_fn{nullptr};     // +0x30
    void* describe_wait_fn{nullptr};   // +0x38
    bool  symbols_resolved{false};     // +0x40
};

/**
 * @brief Simulated ART StackVisitor object matching the 0x830 / 0x838 byte layout.
 *        Đối tượng mô phỏng StackVisitor của ART khớp bố cục 0x830 / 0x838 byte.
 *
 * Binary Layout (0x00ee7c, 0x00ec20, 0x00f58c, 0x00f32c):
 *   +0x000: void**    vptr (VisitFrame @ index 2 -> +0x10)
 *   +0x008: void*     thread_ptr (art::Thread*)
 *   +0x010: void*     context_ptr
 *   +0x018: uintptr_t cur_shadow_frame
 *   +0x020: uintptr_t cur_quick_frame
 *   +0x028: uint8_t   opaque_art_fields[0x7f8] (zeroed in WalkStack epilogue: 0x800 bytes)
 *   +0x820: bool      (*frame_callback_v4_v5)(uintptr_t method, void* arg)
 *   +0x828: bool      (*frame_callback_v6_v14)(uintptr_t method, void* arg)
 *   +0x830: void*     callback_arg (UnwindFrameBuffer*)
 */
struct SimulatedArtStackVisitor {
    void*     vptr{nullptr};                                  // +0x000
    void*     thread_ptr{nullptr};                            // +0x008
    void*     context_ptr{nullptr};                           // +0x010
    uintptr_t cur_shadow_frame{0};                            // +0x018
    uintptr_t cur_quick_frame{0};                             // +0x020
    uint8_t   art_internal_storage[0x800]{};                  // +0x028..+0x827
    bool      (*frame_callback)(uintptr_t, void*){nullptr};   // +0x828
    void*     callback_arg{nullptr};                          // +0x830
};

/**
 * @brief Base class for Multi-Android Stack Unwinders (72 bytes = 0x48 @ 0x00bd68, VTable @ 0x017420).
 *        Lớp cơ sở cho bộ giải mã ngăn xếp đa phiên bản Android (72 byte = 0x48 @ 0x00bd68).
 */
class ArtHelperBase {
public:
    ArtHelperBase();
    virtual ~ArtHelperBase();

    /**
     * @brief Virtual slot #1 (+0x08): Initialize symbol table and internal visitor.
     *        Khe ảo #1 (+0x08): Khởi tạo bảng ký hiệu và đối tượng duyệt ngăn xếp.
     */
    virtual bool Init() = 0;

    /**
     * @brief Virtual slot #2 (+0x10): Walk the stack of a suspended thread.
     *        Khe ảo #2 (+0x10): Duyệt ngăn xếp của một luồng đã tạm dừng.
     */
    virtual void WalkThreadStack(void* art_thread, UnwindFrameBuffer* buffer) = 0;

    /**
     * @brief Virtual slot #3 (+0x18): Suspend a target thread by jobject peer or native peer.
     *        Khe ảo #3 (+0x18): Tạm dừng luồng mục tiêu theo đối tượng Java hoặc con trỏ gốc.
     */
    virtual void* SuspendThreadByPeer(void* peer, bool* timed_out) = 0;

    /**
     * @brief Virtual slot #4 (+0x20): Suspend a target thread by kernel thread ID (tid).
     *        Khe ảo #4 (+0x20): Tạm dừng luồng mục tiêu theo định danh luồng hạt nhân (tid).
     */
    virtual void* SuspendThreadByThreadId(uint32_t tid, bool* timed_out) = 0;

    /**
     * @brief Virtual slot #5 (+0x28): Resume a previously suspended thread.
     *        Khe ảo #5 (+0x28): Tiếp tục chạy một luồng đã tạm dừng trước đó.
     */
    virtual bool ResumeThread(void* art_thread) = 0;

    /**
     * @brief Core template method (0x00be1c..0x00c218): Suspends target thread (if not self),
     *        invokes WalkThreadStack (with 2-pass overflow reallocation), and resumes thread.
     *        Phương thức khuôn mẫu cốt lõi (0x00be1c..0x00c218): Tạm dừng luồng, duyệt ngăn xếp
     *        (hỗ trợ cấp phát lại 2 pha khi tràn) và khôi phục luồng.
     */
    CapturedStackSample* CaptureThreadStack(void* jthread_peer, void* native_thread_peer);

    /**
     * @brief Static frame visitor callback invoked by StackVisitor::VisitFrame (0x00c230..0x00c2c4).
     *        Hàm gọi lại tĩnh được gọi bởi StackVisitor::VisitFrame (0x00c230..0x00c2c4).
     */
    static bool OnVisitMethodFrame(uintptr_t art_method, void* user_data) noexcept;

    UnwindFrameBuffer* GetUnwindBuffer() const noexcept { return unwind_buffer_; }
    SimulatedArtStackVisitor* GetVisitor() const noexcept { return visitor_; }

protected:
    UnwindFrameBuffer*        unwind_buffer_{nullptr}; // +0x08 (allocated 0x48 bytes at 0x00bd84)
    SimulatedArtStackVisitor* visitor_{nullptr};       // +0x10 (allocated 0x830 / 0x838 bytes)
    uint8_t                   reserved_[0x30]{};       // +0x18..+0x47
};

/**
 * @brief Concrete multi-version ART/Dalvik Unwinder parameterized by Android API level (19..34).
 *        Lớp giải mã ngăn xếp ART/Dalvik cụ thể hóa theo cấp độ API Android (19..34).
 */
class VersionedArtHelper final : public ArtHelperBase {
public:
    explicit VersionedArtHelper(int32_t sdk_int, bool is_art);
    ~VersionedArtHelper() override;

    bool Init() override;
    void WalkThreadStack(void* art_thread, UnwindFrameBuffer* buffer) override;
    void* SuspendThreadByPeer(void* peer, bool* timed_out) override;
    void* SuspendThreadByThreadId(uint32_t tid, bool* timed_out) override;
    bool ResumeThread(void* art_thread) override;

    int32_t GetSdkInt() const noexcept { return sdk_int_; }
    bool IsArt() const noexcept { return is_art_; }
    const ArtSymbolTable& GetSymbols() const noexcept { return symbols_; }

private:
    int32_t        sdk_int_{30};
    bool           is_art_{true};
    ArtSymbolTable symbols_{};
};

// ============================================================================
// 4. Factory & Formatting Functions / Hàm Khởi tạo & Định dạng
// ============================================================================

/**
 * @brief Factory function creating the exact ArtHelper subclass for the active SDK (0x003b40 / 0x004d70).
 *        Hàm nhà máy tạo lớp con ArtHelper chính xác cho phiên bản SDK hiện hành (0x003b40 / 0x004d70).
 */
ArtHelperBase* CreateArtHelperForCurrentSdk();

/**
 * @brief Maps raw ART/Dalvik thread state integer to human-readable state name (0x007800..0x007b5c).
 *        Ánh xạ mã số trạng thái luồng ART/Dalvik sang chuỗi tên trạng thái (0x007800..0x007b5c).
 *
 * Jump tables in .rodata:
 *   0x00fc06 (SDK index table for API 19..34)
 *   0x00fc16..0x00fc55 (per-SDK state offset tables for states 67..72 / 1..8)
 *   0x0173b8..0x0173f8 (Dalvik state string pointer table)
 */
const char* ResolveThreadStateString(int32_t sdk_int, bool is_art, uint32_t raw_state) noexcept;

/**
 * @brief Resolves an art::ArtMethod* or Dalvik Method* to a pretty signature string (0x007bd0..0x007e68).
 *        Phân giải con trỏ art::ArtMethod* hoặc Dalvik Method* thành chuỗi chữ ký hàm (0x007bd0..0x007e68).
 */
std::string ResolvePrettyMethod(uintptr_t method_ptr);

/**
 * @brief Probes whether a field offset inside ArtMethod matches the reflected markMethod (0x00e1b8..0x00e1fc).
 *        Thăm dò xem độ lệch trường trong ArtMethod có khớp với markMethod phản chiếu hay không (0x00e1b8..0x00e1fc).
 */
bool ProbeArtMethodOffset(int32_t candidate_offset) noexcept;

/**
 * @brief Extracts kernel tid from art::Thread* (+0x10) or Dalvik Thread* (+0x35c) (0x004110..0x004130).
 *        Trích xuất tid hạt nhân từ art::Thread* (+0x10) hoặc Dalvik Thread* (+0x35c) (0x004110..0x004130).
 */
int32_t ExtractThreadIdFromNativePeer(uintptr_t native_peer, bool is_art) noexcept;

} // namespace sliver
} // namespace bytedance
