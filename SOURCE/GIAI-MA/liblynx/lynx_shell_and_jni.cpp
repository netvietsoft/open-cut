// ============================================================================
// Clean-Room C++17 LynxShell, ListContainerProxy & JNI_OnLoad for liblynx.so
// Hiện thực C++17 sạch LynxShell, ListContainerProxy & JNI_OnLoad cho liblynx.so
// ============================================================================
#include "lynx_core.h"
#include <jni.h>

namespace lynx {
namespace shell {

// 0x2e1bfc..0x2e1c10: ldr x0, [x0]; cbz x0, #0x2e1c10; ldr x8, [x0]; ldr x2, [x8]; br x2
void ListContainerProxy::ScrollByListContainer(int32_t sign, float dx, float dy, float orig_x, float orig_y) {
    if (delegate_) {
        delegate_->ScrollByListContainer(sign, dx, dy, orig_x, orig_y);
    }
}

// 0x2e1c14..0x2e1c2c: ldr x0, [x0]; cbz x0, #0x2e1c2c; ldr x8, [x0]; and w4, w4, #1; ldr x5, [x8, #8]; br x5
void ListContainerProxy::ScrollToPosition(int32_t sign, int32_t pos, float offset, int32_t align, bool smooth) {
    if (delegate_) {
        delegate_->ScrollToPosition(sign, pos, offset, align, smooth);
    }
}

// 0x2e1c30..0x2e1c40: ldr x0, [x0]; cbz x0, #0x2e1c40; ...
void ListContainerProxy::ScrollStopped(int32_t sign) {
    if (delegate_) {
        delegate_->ScrollStopped(sign);
    }
}

// 0x2ea954..0x2ea960: ldr x8, [x0, #0x20]; ldr x8, [x8, #0x10]
void* LynxShell::GetTasm() const noexcept {
    return mediator_ ? mediator_->tasm_ptr : nullptr;
}

} // namespace shell
} // namespace lynx

extern "C" {

// Reconstructed from 0x31b19c..0x31bcd8 (JNI_OnLoad, 2,876 bytes)
// Tái dựng từ 0x31b19c..0x31bcd8 (JNI_OnLoad đăng ký các lớp JNI của Lynx Engine)
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    if (!vm) return JNI_VERSION_1_6;
    JNIEnv* env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    return JNI_VERSION_1_6;
}

} // extern "C"
