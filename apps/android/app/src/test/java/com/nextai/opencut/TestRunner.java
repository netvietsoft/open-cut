package com.nextai.opencut;

/**
 * TestRunner — Main entry point executing all verified unit tests for NextAI OpenCut Android.
 * Lớp khởi chạy chính thực thi toàn bộ các bài kiểm thử đơn vị cho NextAI OpenCut Android.
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class TestRunner {

    public static void main(String[] args) {
        System.out.println("=================================================");
        System.out.println("  NextAI OpenCut Android — Verified Test Suite   ");
        System.out.println("=================================================\n");

        int passedSuites = 0;
        int failedSuites = 0;

        // Suite 1: ContrastFormulaTest (P6 Fix Verification)
        try {
            ContrastFormulaTest.runAllTests();
            passedSuites++;
        } catch (Throwable t) {
            System.err.println("❌ ContrastFormulaTest FAILED: " + t.getMessage());
            t.printStackTrace();
            failedSuites++;
        }

        // Suite 2: EffectRegistryTest
        try {
            EffectRegistryTest.runAllTests();
            passedSuites++;
        } catch (Throwable t) {
            System.err.println("❌ EffectRegistryTest FAILED: " + t.getMessage());
            t.printStackTrace();
            failedSuites++;
        }

        // Suite 3: MediaItemTest
        try {
            MediaItemTest.runAllTests();
            passedSuites++;
        } catch (Throwable t) {
            System.err.println("❌ MediaItemTest FAILED: " + t.getMessage());
            t.printStackTrace();
            failedSuites++;
        }

        System.out.println("=================================================");
        System.out.println("  TEST SUMMARY: " + passedSuites + " Passed, " + failedSuites + " Failed");
        System.out.println("=================================================");

        if (failedSuites > 0) {
            System.exit(1);
        } else {
            System.out.println("🎉 ALL SUITES PASSED! Verified state achieved.");
            System.exit(0);
        }
    }
}
