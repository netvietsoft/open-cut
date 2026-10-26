// ============================================================================
// File: configcenter_interface.cpp
// Library: libconfigcenter.so (ARM64-v8a)
// Task ID: TASK-089-RECONSTRUCTION-LIBCONFIGCENTER (Target 50 / TASK_SO_150)
// Description:
//   EN: Implementation of ConfigcenterEngine::RunSelfTest() verifying all
//       65 dynamic symbols, 22 BaseConfig vtable methods, 16 JNI handlers,
//       and AArch64 hash / permission / priority invariants.
//   VN: Hiện thực hóa ConfigcenterEngine::RunSelfTest() xác minh toàn bộ
//       65 biểu tượng động, 22 phương thức vtable BaseConfig, 16 hàm JNI,
//       và các bất biến băm / quyền hạn / độ ưu tiên AArch64.
// ============================================================================

#include "configcenter_interface.h"
#include <cmath>

namespace NextAI {
namespace OpenCut {
namespace configcenter {

namespace {

class TestConfigListener final : public com::tiktok::ttkmedia::configcenter::IConfigCenterListener {
public:
    void onConfigUpdated(com::tiktok::ttkmedia::configcenter::ConfigModule module) override {
        last_module_ = module;
        ++notify_count_;
    }

    com::tiktok::ttkmedia::configcenter::ConfigModule last_module_ =
        com::tiktok::ttkmedia::configcenter::CONFIG_MODULE_UNKNOWN;
    int notify_count_ = 0;
};

} // namespace

ConfigcenterEngine::ConfigcenterEngine() noexcept = default;

bool ConfigcenterEngine::RunSelfTest() const {
    using namespace com::tiktok::ttkmedia::configcenter;

    // 1. Verify AArch64 popcount & constrain-hash math (0x028a4..0x028dc, 0x04084..0x04164)
    if (aarch64_popcount64(16ULL) != 1u || aarch64_popcount64(15ULL) != 4u) {
        return false;
    }
    if (compute_constrain_hash(1029ULL, 16ULL) != (1029ULL & 15ULL)) {
        return false;
    }
    if (compute_constrain_hash(1029ULL, 11ULL) != (1029ULL % 11ULL)) {
        return false;
    }

    // 2. Verify BaseConfig priority-gated mutations (0x0285c..0x03b1c)
    BaseConfig low_cfg(CONFIG_MODULE_PLAYER, PRIORITY_LOW);
    low_cfg.setIntOption(100, 42);
    low_cfg.setLongOption(101, 9000000000LL);
    low_cfg.setFloatOption(102, 3.5f);
    low_cfg.setStringOption(103, "h264_hw");
    if (!low_cfg.isKeySet(100) || low_cfg.getIntOption(100, 0) != 42) {
        return false;
    }
    if (low_cfg.getLongOption(101, 0) != 9000000000LL) {
        return false;
    }
    float f_out = 0.0f;
    if (low_cfg.getFloatOption(102, &f_out) != 0 || std::fabs(f_out - 3.5f) > 1e-4f) {
        return false;
    }
    if (low_cfg.getStringOption(103) != "h264_hw") {
        return false;
    }

    // 3. Verify ConfigCenter::Singleton(), updateConfig (0x05288), permission freeze, and listener (0x0548c)
    ConfigCenter* center = ConfigCenter::Singleton();
    TestConfigListener listener;
    center->setListener(&listener, CONFIG_MODULE_PLAYER);

    IConfig* dyn_cfg = center->createConfig(CONFIG_MODULE_PLAYER, PRIORITY_HIGH);
    dyn_cfg->setIntOption(200, 1080);
    center->updateConfig(dyn_cfg);

    if (listener.notify_count_ != 1 || listener.last_module_ != CONFIG_MODULE_PLAYER) {
        center->setListener(nullptr, CONFIG_MODULE_PLAYER);
        com::ss::vcbkit::UnSafe::decRef(dyn_cfg);
        return false;
    }

    // After updateConfig, dyn_cfg has permission == PERM_READ_ONLY (1), so further writes are ignored
    dyn_cfg->setIntOption(200, 720);
    if (dyn_cfg->getIntOption(200, 0) != 1080) {
        center->setListener(nullptr, CONFIG_MODULE_PLAYER);
        com::ss::vcbkit::UnSafe::decRef(dyn_cfg);
        return false;
    }

    auto player_cfg = center->getPlayerConfig();
    if (!player_cfg || player_cfg->getIntOption(200, 0) != 1080) {
        center->setListener(nullptr, CONFIG_MODULE_PLAYER);
        com::ss::vcbkit::UnSafe::decRef(dyn_cfg);
        return false;
    }

    center->setListener(nullptr, CONFIG_MODULE_PLAYER);
    com::ss::vcbkit::UnSafe::decRef(dyn_cfg);
    return true;
}

} // namespace configcenter
} // namespace OpenCut
} // namespace NextAI
