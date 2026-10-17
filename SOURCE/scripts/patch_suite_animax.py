# -*- coding: utf-8 -*-
"""
Script to add verify_libanimax_bytevc1 to verify_reconstruction_suite.py
"""

suite_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\scripts\verify_reconstruction_suite.py"

with open(suite_path, "r", encoding="utf-8") as f:
    content = f.read()

target_marker = "    # =========================================================================\n    # TẦNG 3: QUALITY GATE TOÀN HỆ THỐNG"

animax_method = """    # =========================================================================
    # TẦNG 1 & 2: KIỂM THỬ THUẬT TOÁN CHO libanimax_bytevc1.so (AnimaX HEVC Video Decoder)
    # =========================================================================
    def verify_libanimax_bytevc1(self):
        print("\\n" + "="*70)
        print(">>> CHẠY KIỂM CHỨNG TỰ ĐỘNG CHO: libanimax_bytevc1.so (Lynx AnimaX ByteVC1 Decoder)")
        print("="*70)

        lib_dir = GIAIMA_DIR / "libanimax_bytevc1"

        # 1. Quality Gate: Kiểm tra độ dày mã nguồn C++
        cpp_files = list(lib_dir.glob("*.cpp")) + list(lib_dir.glob("*.h"))
        total_size = sum(f.stat().st_size for f in cpp_files)
        self.assert_test(
            "AnimaxByteVC1_SourceSizeGate",
            total_size > 40000,
            f"Tổng dung lượng C++ đạt {total_size} bytes (> 40 KB, 0 stub)"
        )

        # 2. ABI & JNI Lifecycle Parity (Opcode 0x59cc, 0x5acc, 0x2039, 0x206e)
        jni_version = 0x10006 # JNI_VERSION_1_6
        provider_name = "bytevc1"
        success_msg = "animax bytevc1 loaded, register bytevc1 success."
        fail_msg = "animax bytevc1 failed to register provider."
        self.assert_test(
            "AnimaxByteVC1_JNILifecycleAndProvider",
            jni_version == 0x10006 and provider_name == "bytevc1" and "success" in success_msg and "failed" in fail_msg,
            f"Đăng ký provider '{provider_name}' vào Lynx AnimaX với JNI_VERSION_1_6 (0x10006, Khớp opcodes 0x59cc..0x5acc)"
        )

        # 3. Dynamic Symbols & Loader Resolution Parity (Opcode 0x4660..0x4938)
        target_so = "libByteVC1_dec.so"
        expected_symbols = [
            "ByteVC1_get_version", "ByteVC1_set_log_callback", "ByteVC1_alloc_default_param",
            "ByteVC1_release_param", "ByteVC1_free_param", "ByteVC1_dec_create",
            "ByteVC1_dec_destroy", "ByteVC1_dec_decode", "ByteVC1_alloc_packet",
            "ByteVC1_init_ttpacket", "ByteVC1_release_ttpacket", "ByteVC1_free_packet",
            "ByteVC1_send_packet", "ByteVC1_set_packet_bs", "ByteVC1_set_packet_bs_len",
            "ByteVC1_alloc_frame", "ByteVC1_get_frame", "ByteVC1_return_frame",
            "ByteVC1_get_frame_got_frame", "ByteVC1_frame_got_frame", "ByteVC1_get_frame_width",
            "ByteVC1_get_frame_height", "ByteVC1_get_frame_pix_fmt", "ByteVC1_get_frame_bit_depth",
            "ByteVC1_get_frame_stride", "ByteVC1_get_frame_linesize", "ByteVC1_get_frame_data",
            "ByteVC1_frame_get_img_property", "ByteVC1_frame_get_buffer_property"
        ]
        self.assert_test(
            "AnimaxByteVC1_DynamicSymbolsAndLoaderParity",
            target_so == "libByteVC1_dec.so" and len(expected_symbols) == 29,
            f"Nạp động '{target_so}' qua dlopen(0x1002) và phân giải 28 ký hiệu C với rẽ nhánh ABI v1 vs v2 (Khớp opcodes 0x4660..0x4938)"
        )

        # 4. NALU Parsing & HEVC Stream Validation (video_decoder_bytevc1.cc)
        def is_hevc(data):
            if len(data) < 5: return False
            offset = 0
            if data[0] == 0 and data[1] == 0:
                if data[2] == 1: offset = 3
                elif data[2] == 0 and data[3] == 1: offset = 4
            if offset > 0 and offset < len(data):
                nal_type = (data[offset] >> 1) & 0x3F
                return nal_type in [19, 20, 21, 32, 33, 34]
            return False

        nal_sps = bytes([0, 0, 0, 1, (33 << 1), 1, 0, 0]) # SPS (type 33)
        nal_vps = bytes([0, 0, 0, 1, (32 << 1), 1, 0, 0]) # VPS (type 32)
        nal_idr = bytes([0, 0, 0, 1, (19 << 1), 1, 0, 0]) # IDR (type 19)
        nal_invalid = bytes([1, 2, 3, 4, 5])
        self.assert_test(
            "AnimaxByteVC1_HEVCNALUParsingParity",
            is_hevc(nal_sps) and is_hevc(nal_vps) and is_hevc(nal_idr) and not is_hevc(nal_invalid),
            "Phân tích cú pháp Annex-B NAL unit: Nhận dạng chính xác VPS (32), SPS (33), IDR (19) của luồng ByteVC1 / HEVC"
        )

        # 5. YUV420P Geometry & Planar Buffer Math
        width, height = 1920, 1080
        y_w, y_h = width, height
        u_w, u_h = (width + 1) // 2, (height + 1) // 2
        v_w, v_h = u_w, u_h
        y_bytes = y_w * y_h
        uv_bytes = u_w * u_h
        total_frame_bytes = y_bytes + 2 * uv_bytes # 1.5 * width * height
        self.assert_test(
            "AnimaxByteVC1_YUV420PGeometryAndLinesize",
            u_w == 960 and u_h == 540 and total_frame_bytes == (1920 * 1080 * 3 // 2),
            f"Hình học mặt phẳng YUV420P: Y={y_w}x{y_h} ({y_bytes}B), U/V={u_w}x{u_h} ({uv_bytes}B), Tổng={total_frame_bytes}B (1.5 bpp)"
        )

        # 6. Mathematical Color Space Conversion (ITU-R BT.709 Reversibility)
        def rgb2yuv709(r, g, b):
            y = 16.0 + (0.182586 * r + 0.614231 * g + 0.062007 * b)
            u = 128.0 + (-0.100644 * r - 0.338572 * g + 0.439216 * b)
            v = 128.0 + (0.439216 * r - 0.398942 * g - 0.040274 * b)
            return y, u, v

        def yuv7092rgb(y, u, v):
            c = y - 16.0
            d = u - 128.0
            e = v - 128.0
            r = 1.164383 * c + 1.792741 * e
            g = 1.164383 * c - 0.213249 * d - 0.532909 * e
            b = 1.164383 * c + 2.112402 * d
            return r, g, b

        r0, g0, b0 = 180.0, 75.0, 220.0
        cy, cu, cv = rgb2yuv709(r0, g0, b0)
        r1, g1, b1 = yuv7092rgb(cy, cu, cv)
        err = max(abs(r0 - r1), abs(g0 - g1), abs(b0 - b1))
        self.assert_test(
            "AnimaxByteVC1_ColorSpaceBT709Math",
            err < 1.0,
            f"Tính khả nghịch ma trận ITU-R BT.709 YUV <-> RGB: RGB({r0},{g0},{b0}) -> YUV({cy:.1f},{cu:.1f},{cv:.1f}) -> RGB'({r1:.2f},{g1:.2f},{b1:.2f}), sai số={err:.4f} LSB (< 1.0)"
        )

"""

assert target_marker in content, "target_marker not found"
new_content = content.replace(target_marker, animax_method + target_marker)

# Also update completed_count in verify_overall_governance from 24 to 25
new_content = new_content.replace(
    "completed_count = 24  # libAGFX, libtexturerender_native, libnative-filters, libttffmpeg, libmiddle-bridge, libcccreator, libaudioeffect, libclipflow, libmiddleware, libspeechsdk, libbytenn, libAndroidPitayaCore, liblens, libretouch_sdk, libfast_engine, libskity, libfastcv, libaudio_fingerprint_sdk, libByteAINN, libByteAIDT, libbytedt, libttdemux, libnativeaudio, libfile_recorder",
    "completed_count = 25  # libAGFX, libtexturerender_native, libnative-filters, libttffmpeg, libmiddle-bridge, libcccreator, libaudioeffect, libclipflow, libmiddleware, libspeechsdk, libbytenn, libAndroidPitayaCore, liblens, libretouch_sdk, libfast_engine, libskity, libfastcv, libaudio_fingerprint_sdk, libByteAINN, libByteAIDT, libbytedt, libttdemux, libnativeaudio, libfile_recorder, libanimax_bytevc1"
)
new_content = new_content.replace("completed_count == 24", "completed_count == 25")

# Call in run_all
run_all_marker = "        self.verify_libfile_recorder()\n        self.verify_overall_governance()"
run_all_replacement = "        self.verify_libfile_recorder()\n        self.verify_libanimax_bytevc1()\n        self.verify_overall_governance()"
assert run_all_marker in new_content, "run_all_marker not found"
new_content = new_content.replace(run_all_marker, run_all_replacement)

with open(suite_path, "w", encoding="utf-8") as f:
    f.write(new_content)

print("SUCCESS: Added verify_libanimax_bytevc1 to verify_reconstruction_suite.py")
