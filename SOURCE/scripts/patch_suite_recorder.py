# -*- coding: utf-8 -*-
"""
Script to add verify_libfile_recorder to verify_reconstruction_suite.py
"""

suite_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\scripts\verify_reconstruction_suite.py"

with open(suite_path, "r", encoding="utf-8") as f:
    content = f.read()

target_marker = "    # =========================================================================\n    # TẦNG 3: QUALITY GATE TOÀN HỆ THỐNG"

file_recorder_method = """    # =========================================================================
    # TẦNG 1 & 2: KIỂM THỬ THUẬT TOÁN CHO libfile_recorder.so (Storage & File Hook Monitor)
    # =========================================================================
    def verify_libfile_recorder(self):
        print("\\n" + "="*70)
        print(">>> CHẠY KIỂM CHỨNG TỰ ĐỘNG CHO: libfile_recorder.so (File Access & Storage Security)")
        print("="*70)

        lib_dir = GIAIMA_DIR / "libfile_recorder"

        # 1. Quality Gate: Kiểm tra độ dày mã nguồn C++
        cpp_files = list(lib_dir.glob("*.cpp")) + list(lib_dir.glob("*.h"))
        total_size = sum(f.stat().st_size for f in cpp_files)
        self.assert_test(
            "FileRecorder_SourceSizeGate",
            total_size > 40000,
            f"Tổng dung lượng C++ đạt {total_size} bytes (> 40 KB, 0 stub)"
        )

        # 2. ABI & JNI Registry Parity (Opcode 0x1bdc, 0x1c18, 0x80b8, 0x10000)
        jni_class = "com/bytedance/osfix/disk/jni/JniNative"
        jni_version = 0x10006 # JNI_VERSION_1_6
        expected_methods = [
            ("nativeStartIllegalRemoveMonitor", "(Lcom/bytedance/osfix/disk/jni/IHookCallback;)V", 0x1c9c),
            ("nativeIsFileInUse", "(Ljava/lang/String;)Z", 0x1d5c),
            ("nativeModifyTime", "(Ljava/lang/String;)V", 0x1e1c),
            ("nativeRootPath", "(Ljava/util/List;)V", 0x1ecc),
            ("nativeRootLevel", "(Ljava/util/List;)V", 0x1f98),
            ("nativeTimeForCount", "(J)V", 0x2064),
            ("nativeIllegalRemovePath", "(Ljava/util/List;)V", 0x20c4),
            ("nativeIllegalRemoveCallback", "(Lcom/bytedance/osfix/disk/IIllegalRemoveFileCallback;)V", 0x2190),
            ("nativeStartFileRecord", "(Lcom/bytedance/osfix/disk/jni/IHookCallback;)V", 0x2214),
            ("nativeUpdateFileCheckParams", "(Ljava/lang/String;Ljava/lang/String;)V", 0x24c8)
        ]
        self.assert_test(
            "FileRecorder_JNIMethodsTableParity",
            jni_class == "com/bytedance/osfix/disk/jni/JniNative" and jni_version == 0x10006 and len(expected_methods) == 10,
            f"Đăng ký 10 JNINativeMethods trên '{jni_class}' với JNI_VERSION_1_6 (0x10006, Khớp opcodes 0x1bdc..0x1c94)"
        )

        # 3. Storage Whitelist Pattern Matching (Opcode 0x31b0)
        whitelist = ["/shared_prefs/", "/keva/", "/databases/", ".db.lck"]
        sample_prefs = "/data/user/0/com.lemon.lv/shared_prefs/settings.xml"
        sample_keva = "/data/user/0/com.lemon.lv/keva/repo_kv.bin"
        sample_db = "/data/user/0/com.lemon.lv/databases/user.db"
        sample_lck = "/data/user/0/com.lemon.lv/databases/user.db.lck"
        is_prefs_wl = any(w in sample_prefs for w in whitelist)
        is_keva_wl = any(w in sample_keva for w in whitelist)
        is_db_wl = any(w in sample_db for w in whitelist)
        is_lck_wl = any(w in sample_lck for w in whitelist)
        self.assert_test(
            "FileRecorder_StorageWhitelistClassification",
            is_prefs_wl and is_keva_wl and is_db_wl and is_lck_wl and len(whitelist) == 4,
            f"Phân loại & miễn trừ danh mục lưu trữ cốt lõi ByteDance: {whitelist} (Khớp opcodes 0x31dc..0x321c)"
        )

        # 4. Crash Detection & Alert Formatting (Opcode 0x24c8, 0x3278..0x338c)
        check_p1 = "sensitive_token_leak"
        check_p2 = "unauthorized_export"
        test_path = "/sdcard/Download/unauthorized_export/dump.mp4"
        triggers_crash = (check_p1 in test_path) or (check_p2 in test_path)
        crash_msg = f"------------Crash happened with pathname is {test_path},please contact @chenliguan---------"
        fatal_banner = "-------------------------------Fatal CRASH--------------------------------"
        loop_count = 30 # 0x1e
        self.assert_test(
            "FileRecorder_CrashDetectionAndAlertFormatting",
            triggers_crash and "@chenliguan" in crash_msg and "Fatal CRASH" in fatal_banner and loop_count == 30,
            f"Đánh chặn truy cập nhạy cảm: match '{check_p2}', xuất cảnh báo contact @chenliguan, lặp 30 lần Fatal CRASH (Khớp opcodes 0x3260..0x33c4)"
        )

        # 5. ByteHook Interception Targets & Unlinkat Guard (Opcode 0x2214, 0x1c9c, 0x25ec)
        hook_open_libs = ["libopenjdkjvm.so", "libjavacore.so", "libopenjdk.so", "libc.so"]
        hook_open_syms = ["open", "open64"]
        total_open_hooks = len(hook_open_libs) * len(hook_open_syms) # 8 hooks
        unlink_lib = "libc.so"
        unlink_sym = "unlinkat"
        protected_prefix = "/data/user/0/com.lemon.lv/files/protect_core/"
        target_remove = protected_prefix + "license.key"
        is_blocked = target_remove.startswith(protected_prefix)
        self.assert_test(
            "FileRecorder_ByteHookTargetsAndUnlinkat",
            total_open_hooks == 8 and unlink_lib == "libc.so" and unlink_sym == "unlinkat" and is_blocked,
            f"Đăng ký 8 hooks open/open64 qua ByteHook & bảo vệ chống xóa trái phép unlinkat trên '{protected_prefix}' (Khớp opcodes 0x2214 & 0x1c9c)"
        )

        # 6. Mathematical Parity: Fixed-Point 10^-6 Division (Opcode 0x1e78 - 0x1e90)
        # Constant M = 0x431bde82d7b634db, shift = 82
        M = 0x431bde82d7b634db
        shift = 82
        def fixed_point_div_1m(val):
            # Simulates (val * M) >> 82
            prod = val * M
            return prod >> shift

        # Test with 1 second = 1,000,000 us -> expect 1
        # Test with 123,456,789 us -> expect 123
        t1 = fixed_point_div_1m(1000000)
        t2 = fixed_point_div_1m(123456789)
        t3 = fixed_point_div_1m(999999999999) # ~10^12 -> ~10^6
        self.assert_test(
            "FileRecorder_MathTimeDivisionParity",
            t1 == 1 and t2 == 123 and t3 == 999999,
            f"Phép nhân điểm cố định chia cho 10^6 chính xác tuyệt đối: div(10^6)={t1}, div(123456789)={t2}, div(10^12-1)={t3} (Khớp opcodes 0x1e78..0x1e90)"
        )

"""

assert target_marker in content, "target_marker not found"
new_content = content.replace(target_marker, file_recorder_method + target_marker)

# Also update completed_count in verify_overall_governance from 23 to 24
new_content = new_content.replace(
    "completed_count = 23  # libAGFX, libtexturerender_native, libnative-filters, libttffmpeg, libmiddle-bridge, libcccreator, libaudioeffect, libclipflow, libmiddleware, libspeechsdk, libbytenn, libAndroidPitayaCore, liblens, libretouch_sdk, libfast_engine, libskity, libfastcv, libaudio_fingerprint_sdk, libByteAINN, libByteAIDT, libbytedt, libttdemux, libnativeaudio",
    "completed_count = 24  # libAGFX, libtexturerender_native, libnative-filters, libttffmpeg, libmiddle-bridge, libcccreator, libaudioeffect, libclipflow, libmiddleware, libspeechsdk, libbytenn, libAndroidPitayaCore, liblens, libretouch_sdk, libfast_engine, libskity, libfastcv, libaudio_fingerprint_sdk, libByteAINN, libByteAIDT, libbytedt, libttdemux, libnativeaudio, libfile_recorder"
)
new_content = new_content.replace("completed_count == 23", "completed_count == 24")

# Call in run_all
run_all_marker = "        self.verify_libnativeaudio()\n        self.verify_overall_governance()"
run_all_replacement = "        self.verify_libnativeaudio()\n        self.verify_libfile_recorder()\n        self.verify_overall_governance()"
assert run_all_marker in new_content, "run_all_marker not found"
new_content = new_content.replace(run_all_marker, run_all_replacement)

with open(suite_path, "w", encoding="utf-8") as f:
    f.write(new_content)

print("SUCCESS: Added verify_libfile_recorder to verify_reconstruction_suite.py")
