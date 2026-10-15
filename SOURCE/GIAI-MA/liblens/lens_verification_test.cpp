// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_verification_test.cpp
// Description: Implementation of 10-Point Closed-Loop Verification Test
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "lens_verification_test.h"
#include "lens_engine.h"
#include "lens_bilateral_filter.h"
#include "lens_super_resolution.h"
#include "lens_denoise_nn.h"
#include "lens_vhdr.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <cassert>

namespace LENS::TEST {

LensTestResult RunLensSelfTest() {
    LensTestResult res;
    res.total_tests = 10;
    res.passed_tests = 0;
    std::stringstream ss;

    // TEST 1: Lanczos-3 Kernel Math Parity
    // L(0) = 1.0, L(1) = 0.0, L(3) = 0.0
    float l0 = ALGORITHM::LensAlgorithmVSM::Lanczos3Kernel(0.0f);
    float l3 = ALGORITHM::LensAlgorithmVSM::Lanczos3Kernel(3.0f);
    if (std::abs(l0 - 1.0f) < 1e-5f && std::abs(l3) < 1e-5f) {
        res.passed_tests++;
        ss << "[PASS 1/10] Lanczos-3 Kernel Math: L(0)=1.0, L(3)=0.0 (Exact)\n";
    } else {
        ss << "[FAIL 1/10] Lanczos-3 Kernel Math Failed\n";
    }

    // TEST 2: Bicubic Kernel Math Parity
    // B(0) = 1.0, B(1) = 0.0, B(2) = 0.0
    float b0 = ALGORITHM::LensAlgorithmVSM::BicubicKernel(0.0f);
    float b1 = ALGORITHM::LensAlgorithmVSM::BicubicKernel(1.0f);
    if (std::abs(b0 - 1.0f) < 1e-5f && std::abs(b1) < 1e-5f) {
        res.passed_tests++;
        ss << "[PASS 2/10] Bicubic Kernel Math: B(0)=1.0, B(1)=0.0 (Exact)\n";
    } else {
        ss << "[FAIL 2/10] Bicubic Kernel Math Failed\n";
    }

    // TEST 3: Super Resolution 2x Scaling Dimension & Integrity
    ALGORITHM::LensAlgorithmVSM vsm;
    FRAMEWORK::LensImageFrame in_frame(16, 16, 4);
    for (size_t i = 0; i < in_frame.data.size(); ++i) in_frame.data[i] = static_cast<uint8_t>(i % 256);
    FRAMEWORK::LensImageFrame out_frame;
    if (vsm.Process(in_frame, out_frame) && out_frame.width == 32 && out_frame.height == 32) {
        res.passed_tests++;
        ss << "[PASS 3/10] VSM Super Resolution 2x: 16x16 -> 32x32 Scaling Success\n";
    } else {
        ss << "[FAIL 3/10] VSM Super Resolution Failed\n";
    }

    // TEST 4: Bilateral Weight Pass Kernel Precomputation
    ALGORITHM::BilateralWeightPass bwp;
    bwp.PrecomputeSpatialKernel(3, 2.0f);
    const auto& kernel = bwp.GetSpatialKernel();
    if (kernel.size() == 49 && kernel[24] > 0.999f) { // Center pixel weight = 1.0
        res.passed_tests++;
        ss << "[PASS 4/10] Bilateral Weight Pass: 7x7 spatial kernel center weight = 1.0\n";
    } else {
        ss << "[FAIL 4/10] Bilateral Weight Pass Failed\n";
    }

    // TEST 5: Hierarchical Bilateral Filter Edge Preservation
    ALGORITHM::HierarchicalBilateralFilter hbf;
    FRAMEWORK::LensAlgorithmJsonInfo hbf_config;
    hbf_config.param_strength = 0.8f;
    hbf_config.param_sigma_range = 0.15f;
    hbf.Init(hbf_config);
    FRAMEWORK::LensImageFrame skin_in(8, 8, 4);
    // Fill with synthetic skin color (R=180, G=120, B=90, A=255)
    for (int i = 0; i < 64; ++i) {
        skin_in.data[i * 4 + 0] = 180;
        skin_in.data[i * 4 + 1] = 120;
        skin_in.data[i * 4 + 2] = 90;
        skin_in.data[i * 4 + 3] = 255;
    }
    // Introduce noise spike
    skin_in.data[0] = 240;
    FRAMEWORK::LensImageFrame skin_out;
    if (hbf.Process(skin_in, skin_out) && skin_out.data[0] < 240) {
        res.passed_tests++;
        ss << "[PASS 5/10] Hierarchical Bilateral Filter: Noise smoothed successfully\n";
    } else {
        ss << "[FAIL 5/10] Hierarchical Bilateral Filter Failed\n";
    }

    // TEST 6: Immerkaer Noise Floor Estimator
    std::vector<uint8_t> noisy_buf(16 * 16 * 4, 128);
    for (size_t i = 0; i < noisy_buf.size(); i += 8) noisy_buf[i] = 160;
    float sigma = ALGORITHM::VideoDenoiseNNProcess::EstimateNoiseFloor(noisy_buf.data(), 16, 16, 4);
    if (sigma > 2.0f) {
        res.passed_tests++;
        ss << "[PASS 6/10] Noise Floor Estimator: sigma = " << sigma << " > 2.0f\n";
    } else {
        ss << "[FAIL 6/10] Noise Floor Estimator Failed\n";
    }

    // TEST 7: VideoDenoiseNNProcess Temporal Filter
    ALGORITHM::VideoDenoiseNNProcess denoiser;
    FRAMEWORK::LensImageFrame d_in1(8, 8, 4);
    FRAMEWORK::LensImageFrame d_out1;
    denoiser.Process(d_in1, d_out1); // Initialize temporal history
    FRAMEWORK::LensImageFrame d_in2 = d_in1;
    d_in2.data[0] = 200; // Small change
    FRAMEWORK::LensImageFrame d_out2;
    if (denoiser.Process(d_in2, d_out2) && d_out2.data[0] < 200) {
        res.passed_tests++;
        ss << "[PASS 7/10] Temporal Denoise: Temporal recursive filter decay confirmed\n";
    } else {
        ss << "[FAIL 7/10] Temporal Denoise Failed\n";
    }

    // TEST 8: Extended Reinhard Tone Mapping (VHDR)
    float l_mapped = ALGORITHM::LensAlgorithmVHDR::ReinhardToneMap(2.0f, 2.25f);
    if (l_mapped > 0.0f && l_mapped < 2.0f) {
        res.passed_tests++;
        ss << "[PASS 8/10] Extended Reinhard Tone Map: L(2.0) -> " << l_mapped << " < 2.0 (Compressed)\n";
    } else {
        ss << "[FAIL 8/10] Reinhard Tone Map Failed\n";
    }

    // TEST 9: LensEngineFactory & Factory Lifecycle (Opcode 0x2c6550)
    auto engine = FRAMEWORK::LensEngineFactory::CreateLensEngine();
    if (engine && engine->Initialize("{}") && !engine->GetVersion().empty()) {
        res.passed_tests++;
        ss << "[PASS 9/10] LensEngineFactory: Lifecycle create and init success (Opcode 0x2c6550)\n";
    } else {
        ss << "[FAIL 9/10] LensEngineFactory Lifecycle Failed\n";
    }

    // TEST 10: LensAlgorithmUtils JSON Parser (Opcode 0x2c68c0)
    FRAMEWORK::LensAlgorithmJsonInfo json_info;
    const char* sample_json = "{\"algorithm_id\": 2, \"strength\": 1.5, \"radius\": 4.0}";
    if (FRAMEWORK::LensAlgorithmUtils::GetInfoFromJson(sample_json, "test", &json_info) &&
        json_info.algorithm_id == 2 && std::abs(json_info.param_strength - 1.5f) < 1e-4f) {
        res.passed_tests++;
        ss << "[PASS 10/10] LensAlgorithmUtils JSON Parser: parsed id=2, strength=1.5 (Opcode 0x2c68c0)\n";
    } else {
        ss << "[FAIL 10/10] JSON Parser Failed\n";
    }

    res.passed = (res.passed_tests == res.total_tests);
    res.report = ss.str();
    return res;
}

} // namespace LENS::TEST
