package com.nextai.opencut;

import com.nextai.opencut.engine.EffectRegistry;

import java.util.List;

/**
 * EffectRegistryTest — Unit test verifying EffectRegistry categories, counts, and lookups.
 * Kiểm thử danh mục hiệu ứng, số lượng và các hàm lọc theo phân loại của EffectRegistry.
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class EffectRegistryTest {

    public static void runAllTests() {
        System.out.println(">>> Running EffectRegistryTest...");
        testAllEffectsNotEmpty();
        testTransitionsCategory();
        testSpeedCurvesCategory();
        testCoverTemplatesCategory();
        testKaraokeStylesCategory();
        System.out.println(">>> EffectRegistryTest: ALL TESTS PASSED (5/5)\n");
    }

    private static void testAllEffectsNotEmpty() {
        List<EffectRegistry.EffectItem> all = EffectRegistry.getAllEffects();
        if (all == null || all.isEmpty()) {
            throw new AssertionError("getAllEffects() returned null or empty list!");
        }
        if (all.size() < 30) {
            throw new AssertionError("getAllEffects() has fewer effects than expected: " + all.size());
        }
        System.out.println("  [PASS] testAllEffectsNotEmpty (Total: " + all.size() + " effects)");
    }

    private static void testTransitionsCategory() {
        List<EffectRegistry.EffectItem> transitions = EffectRegistry.getTransitions();
        if (transitions == null || transitions.isEmpty()) {
            throw new AssertionError("getTransitions() returned empty list!");
        }
        for (EffectRegistry.EffectItem item : transitions) {
            if (!"Transition".equalsIgnoreCase(item.category)) {
                throw new AssertionError("Item has wrong category: " + item.category);
            }
        }
        System.out.println("  [PASS] testTransitionsCategory (Found: " + transitions.size() + " transitions)");
    }

    private static void testSpeedCurvesCategory() {
        List<EffectRegistry.EffectItem> curves = EffectRegistry.getSpeedCurves();
        if (curves == null || curves.isEmpty()) {
            throw new AssertionError("getSpeedCurves() returned empty list!");
        }
        boolean hasHero = false;
        for (EffectRegistry.EffectItem item : curves) {
            if ("curve_hero".equals(item.id)) {
                hasHero = true;
                break;
            }
        }
        if (!hasHero) {
            throw new AssertionError("SpeedCurves missing 'curve_hero' preset!");
        }
        System.out.println("  [PASS] testSpeedCurvesCategory (Found: " + curves.size() + " presets)");
    }

    private static void testCoverTemplatesCategory() {
        List<EffectRegistry.EffectItem> covers = EffectRegistry.getCoverTemplates();
        if (covers == null || covers.isEmpty()) {
            throw new AssertionError("getCoverTemplates() returned empty list!");
        }
        System.out.println("  [PASS] testCoverTemplatesCategory (Found: " + covers.size() + " templates)");
    }

    private static void testKaraokeStylesCategory() {
        List<EffectRegistry.EffectItem> karaoke = EffectRegistry.getKaraokeStyles();
        if (karaoke == null || karaoke.isEmpty()) {
            throw new AssertionError("getKaraokeStyles() returned empty list!");
        }
        System.out.println("  [PASS] testKaraokeStylesCategory (Found: " + karaoke.size() + " styles)");
    }
}
