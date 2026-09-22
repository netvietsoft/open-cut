package com.nextai.opencut.test;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.FaceDetector;
import android.graphics.PointF;
import java.io.File;
import java.util.List;

public class TestFaceDetect {
    public static void main(String[] args) {
        try {
            String path = args.length > 0 ? args[0] : "/sdcard/DCIM/Facebook/FB_IMG_1789812444308.jpg";
            BitmapFactory.Options opt = new BitmapFactory.Options();
            opt.inPreferredConfig = Bitmap.Config.RGB_565;
            Bitmap bmp = BitmapFactory.decodeFile(path, opt);
            if (bmp == null) {
                System.out.println("ERROR: Could not decode bitmap at " + path);
                return;
            }
            int w = bmp.getWidth();
            int h = bmp.getHeight();
            System.out.println("Loaded bitmap: " + w + "x" + h + ", config=" + bmp.getConfig());

            // Test at full resolution (must be even width)
            int evenW = (w / 2) * 2;
            Bitmap bFull = (evenW == w && bmp.getConfig() == Bitmap.Config.RGB_565) ? bmp :
                    Bitmap.createScaledBitmap(bmp, evenW, h, true).copy(Bitmap.Config.RGB_565, false);

            FaceDetector detectorFull = new FaceDetector(evenW, h, 10);
            FaceDetector.Face[] facesFull = new FaceDetector.Face[10];
            int countFull = detectorFull.findFaces(bFull, facesFull);
            System.out.println("Full scale (" + evenW + "x" + h + ") faces found: " + countFull);
            for (int i = 0; i < countFull; i++) {
                if (facesFull[i] != null) {
                    PointF mid = new PointF();
                    facesFull[i].getMidPoint(mid);
                    System.out.println("  Face " + i + ": mid=(" + mid.x + ", " + mid.y + "), eyesDist=" + facesFull[i].eyesDistance() + ", conf=" + facesFull[i].confidence());
                }
            }

            // Test FaceBodyDetectionEngine.detectFace
            com.nextai.opencut.engine.FaceBodyDetectionEngine.FaceLandmarks lm = 
                    com.nextai.opencut.engine.FaceBodyDetectionEngine.detectFace(bmp);
            System.out.println("FaceBodyDetectionEngine result:");
            System.out.println("  isDetected: " + lm.isDetected);
            System.out.println("  midEyes: " + lm.midEyes);
            System.out.println("  eyesDistance: " + lm.eyesDistance);
            System.out.println("  leftEye: " + lm.leftEye + ", bounds=" + lm.leftEyeBounds);
            System.out.println("  rightEye: " + lm.rightEye + ", bounds=" + lm.rightEyeBounds);
            System.out.println("  mouthCenter: " + lm.mouthCenter);
            System.out.println("  mouthBounds: " + lm.mouthBounds);
            System.out.println("  teethBounds: " + lm.teethBounds);

            // Find exact pupil Y by checking vertical luminance profile
            System.out.println("\n--- WOMAN EYE VERTICAL PROFILE (X=444, 472) ---");
            for (int y = 280; y <= 300; y++) {
                int cL = bmp.getPixel(444, y);
                int cR = bmp.getPixel(472, y);
                float lumL = (((cL >> 16) & 0xFF) + ((cL >> 8) & 0xFF) + (cL & 0xFF)) / 3f;
                float lumR = (((cR >> 16) & 0xFF) + ((cR >> 8) & 0xFF) + (cR & 0xFF)) / 3f;
                System.out.println(String.format("Y=%d: Left Lum=%.1f, Right Lum=%.1f", y, lumL, lumR));
            }

            System.out.println("\n--- MAN EYE VERTICAL PROFILE (X=340, 368) ---");
            for (int y = 262; y <= 280; y++) {
                int cL = bmp.getPixel(340, y);
                int cR = bmp.getPixel(368, y);
                float lumL = (((cL >> 16) & 0xFF) + ((cL >> 8) & 0xFF) + (cL & 0xFF)) / 3f;
                float lumR = (((cR >> 16) & 0xFF) + ((cR >> 8) & 0xFF) + (cR & 0xFF)) / 3f;
                System.out.println(String.format("Y=%d: Left Lum=%.1f, Right Lum=%.1f", y, lumL, lumR));
            }

            // Test Prototype Multi-Face Detection
            System.out.println("\n--- TESTING ENHANCED MULTI-FACE DETECTION ---");
            testEnhancedFaceDetection(bmp);

            // Test detectFaceNear
            System.out.println("\n--- TESTING DETECT FACE NEAR TOUCH ---");
            testDetectFaceNear(bmp, 350f, 270f); // Man's face
            testDetectFaceNear(bmp, 460f, 280f); // Woman's face
            testDetectFaceNear(bmp, 100f, 100f); // Tap away from faces

            // Test applying lipstick and eye brightening to both faces
            System.out.println("\n--- TESTING APPLYING EFFECTS ON BOTH FACES ---");
            testApplyEffects(bmp);
        } catch (Throwable t) {
            t.printStackTrace();
        }
    }

    private static void testApplyEffects(Bitmap bmp) {
        try {
            List<FaceLandmarksWrapper> allFaces = runFullFaceDetection(bmp);
            Bitmap mutable = bmp.copy(Bitmap.Config.ARGB_8888, true);

            for (int i = 0; i < allFaces.size(); i++) {
                FaceLandmarksWrapper fw = allFaces.get(i);
                com.nextai.opencut.engine.FaceBodyDetectionEngine.FaceLandmarks lm =
                        new com.nextai.opencut.engine.FaceBodyDetectionEngine.FaceLandmarks();
                lm.isDetected = true;
                lm.imageWidth = bmp.getWidth();
                lm.imageHeight = bmp.getHeight();
                lm.midEyes.set(fw.midEyes);
                lm.eyesDistance = fw.eyesDist;
                lm.leftEye.set(fw.leftEye);
                lm.rightEye.set(fw.rightEye);
                lm.mouthCenter.set(fw.mouthCenter);

                float halfW = Math.max(12.0f, fw.eyesDist * 0.28f);
                float halfH = Math.max(6.0f, fw.eyesDist * 0.10f);
                lm.mouthBounds.set(fw.mouthCenter.x - halfW, fw.mouthCenter.y - halfH,
                        fw.mouthCenter.x + halfW, fw.mouthCenter.y + halfH);
                lm.teethBounds.set(fw.mouthCenter.x - halfW * 0.6f, fw.mouthCenter.y - halfH * 0.5f,
                        fw.mouthCenter.x + halfW * 0.6f, fw.mouthCenter.y + halfH * 0.5f);

                float eyeR = Math.max(10.0f, fw.eyesDist * 0.22f);
                lm.leftEyeBounds.set(fw.leftEye.x - eyeR, fw.leftEye.y - eyeR, fw.leftEye.x + eyeR, fw.leftEye.y + eyeR);
                lm.rightEyeBounds.set(fw.rightEye.x - eyeR, fw.rightEye.y - eyeR, fw.rightEye.x + eyeR, fw.rightEye.y + eyeR);

                // Apply lipstick (Rosy Red 0xFFDE3163)
                mutable = com.nextai.opencut.engine.FaceBodyDetectionEngine.applyLocalizedLipstick(
                        mutable, lm, 0xFFDE3163, 0.70f, 0.40f);

                // Apply eye brightening
                mutable = com.nextai.opencut.engine.FaceBodyDetectionEngine.applyLocalizedEyeBrightening(
                        mutable, lm, 0.85f, 0.85f);

                System.out.println("  Applied lipstick & eye brightening to face " + i + " at mouth=" + fw.mouthCenter + ", eyes=(" + fw.leftEye + ", " + fw.rightEye + ")");
            }

            // Save crops of both faces for close inspection
            Bitmap cropWoman = Bitmap.createBitmap(mutable, 400, 240, 120, 120);
            Bitmap cropMan = Bitmap.createBitmap(mutable, 300, 220, 120, 120);
            java.io.FileOutputStream fosW = new java.io.FileOutputStream("/sdcard/DCIM/Facebook/crop_woman.jpg");
            cropWoman.compress(Bitmap.CompressFormat.JPEG, 95, fosW);
            fosW.close();
            java.io.FileOutputStream fosM = new java.io.FileOutputStream("/sdcard/DCIM/Facebook/crop_man.jpg");
            cropMan.compress(Bitmap.CompressFormat.JPEG, 95, fosM);
            fosM.close();

            // Save test output
            java.io.FileOutputStream fos = new java.io.FileOutputStream("/sdcard/DCIM/Facebook/test_edited.jpg");
            mutable.compress(Bitmap.CompressFormat.JPEG, 92, fos);
            fos.flush();
            fos.close();
            System.out.println("Saved edited test bitmap and crops successfully!");
        } catch (Throwable t) {
            t.printStackTrace();
        }
    }

    private static void testDetectFaceNear(Bitmap bmp, float touchX, float touchY) {
        System.out.println("Testing touch at (" + touchX + ", " + touchY + "):");
        // We will call the prototype logic
        List<FaceLandmarksWrapper> allFaces = runFullFaceDetection(bmp);
        FaceLandmarksWrapper closest = null;
        float minDistSq = Float.MAX_VALUE;
        for (FaceLandmarksWrapper f : allFaces) {
            float dx = f.midEyes.x - touchX;
            float dy = f.midEyes.y - touchY;
            float distSq = dx * dx + dy * dy;
            if (distSq < minDistSq) {
                minDistSq = distSq;
                closest = f;
            }
        }
        if (closest != null && minDistSq < (closest.eyesDist * 3.5f) * (closest.eyesDist * 3.5f)) {
            System.out.println("  Matched face at (" + closest.midEyes.x + ", " + closest.midEyes.y + ") with dist=" + Math.sqrt(minDistSq));
        } else {
            System.out.println("  No existing face close enough (minDist=" + Math.sqrt(minDistSq) + "). Creating custom landmark centered at touch!");
        }
    }

    private static class FaceLandmarksWrapper {
        PointF midEyes = new PointF();
        float eyesDist = 0;
        PointF leftEye = new PointF();
        PointF rightEye = new PointF();
        PointF mouthCenter = new PointF();
        float conf = 0;
    }

    private static java.util.List<FaceLandmarksWrapper> runFullFaceDetection(Bitmap bmp) {
        java.util.List<FaceLandmarksWrapper> list = new java.util.ArrayList<>();
        int w = bmp.getWidth();
        int h = bmp.getHeight();
        int evenW = (w / 2) * 2;
        Bitmap b565 = (evenW == w && bmp.getConfig() == Bitmap.Config.RGB_565) ? bmp :
                Bitmap.createScaledBitmap(bmp, evenW, h, true).copy(Bitmap.Config.RGB_565, false);

        FaceDetector detector = new FaceDetector(evenW, h, 10);
        FaceDetector.Face[] faces = new FaceDetector.Face[10];
        int count = detector.findFaces(b565, faces);

        for (int i = 0; i < count; i++) {
            FaceDetector.Face f = faces[i];
            if (f == null || f.confidence() < 0.40f) continue;
            PointF mid = new PointF();
            f.getMidPoint(mid);
            float dist = f.eyesDistance();
            if (mid.y > h * 0.75f || dist < 12.0f) continue;

            FaceLandmarksWrapper wrap = new FaceLandmarksWrapper();
            wrap.midEyes.set(mid);
            wrap.eyesDist = dist;
            wrap.conf = f.confidence();
            wrap.leftEye = refineEye(bmp, mid.x - dist * 0.5f, mid.y, dist * 0.28f);
            wrap.rightEye = refineEye(bmp, mid.x + dist * 0.5f, mid.y, dist * 0.28f);
            wrap.mouthCenter = refineLips(bmp, mid.x, mid.y, dist);
            list.add(wrap);
        }
        return list;
    }

    private static void testEnhancedFaceDetection(Bitmap bmp) {
        int w = bmp.getWidth();
        int h = bmp.getHeight();
        int evenW = (w / 2) * 2;
        Bitmap b565 = (evenW == w && bmp.getConfig() == Bitmap.Config.RGB_565) ? bmp :
                Bitmap.createScaledBitmap(bmp, evenW, h, true).copy(Bitmap.Config.RGB_565, false);

        FaceDetector detector = new FaceDetector(evenW, h, 10);
        FaceDetector.Face[] faces = new FaceDetector.Face[10];
        int count = detector.findFaces(b565, faces);
        System.out.println("Enhanced detector found " + count + " faces at full resolution!");

        for (int i = 0; i < count; i++) {
            FaceDetector.Face f = faces[i];
            if (f == null || f.confidence() < 0.40f) continue;

            PointF mid = new PointF();
            f.getMidPoint(mid);
            float eyesDist = f.eyesDistance();

            // Filter out false positives (e.g. background noise at the bottom)
            // Faces in portrait are typically in upper 75% of image and eyesDist > 12px
            if (mid.y > h * 0.75f || eyesDist < 12.0f) {
                System.out.println("  Face " + i + " rejected: Y=" + mid.y + " (too low) or eyesDist=" + eyesDist);
                continue;
            }

            float leftEyeX = mid.x - eyesDist * 0.5f;
            float leftEyeY = mid.y;
            float rightEyeX = mid.x + eyesDist * 0.5f;
            float rightEyeY = mid.y;

            // Refine eye centers: search for darkest local minimum (pupil) around expected eye
            PointF refinedLeft = refineEye(bmp, leftEyeX, leftEyeY, eyesDist * 0.28f);
            PointF refinedRight = refineEye(bmp, rightEyeX, rightEyeY, eyesDist * 0.28f);

            // Refine lips
            PointF refinedLips = refineLips(bmp, mid.x, mid.y, eyesDist);

            System.out.println("  == FACE " + i + " ==");
            System.out.println("     Confidence: " + f.confidence());
            System.out.println("     MidEyes: (" + mid.x + ", " + mid.y + "), eyesDist=" + eyesDist);
            System.out.println("     LeftEye: expected (" + leftEyeX + ", " + leftEyeY + ") -> refined " + refinedLeft);
            System.out.println("     RightEye: expected (" + rightEyeX + ", " + rightEyeY + ") -> refined " + refinedRight);
            System.out.println("     Lips: refined " + refinedLips);
        }
    }

    private static PointF refineEye(Bitmap bmp, float expX, float expY, float radius) {
        int w = bmp.getWidth();
        int h = bmp.getHeight();
        int minX = (int) Math.max(0, expX - radius);
        int maxX = (int) Math.min(w - 1, expX + radius);
        int minY = (int) Math.max(0, expY - radius);
        int maxY = (int) Math.min(h - 1, expY + radius);

        int bestX = (int) expX;
        int bestY = (int) expY;
        float minLum = 999.0f;

        for (int y = minY; y <= maxY; y++) {
            for (int x = minX; x <= maxX; x++) {
                int c = bmp.getPixel(x, y);
                int r = (c >> 16) & 0xFF, g = (c >> 8) & 0xFF, b = c & 0xFF;
                float lum = (r + g + b) / 3.0f;
                float dx = x - expX;
                float dy = y - expY;
                float dist = (float) Math.sqrt(dx * dx + dy * dy);
                float cost = lum + dist * 1.5f;
                if (cost < minLum) {
                    minLum = cost;
                    bestX = x;
                    bestY = y;
                }
            }
        }
        return new PointF(bestX, bestY);
    }

    private static PointF refineLips(Bitmap bmp, float midX, float midY, float eyesDist) {
        int w = bmp.getWidth();
        int h = bmp.getHeight();
        // Start below philtrum (1.20*eyesDist) to avoid nose shadow
        int searchTop = (int) Math.max(0, midY + eyesDist * 1.20f);
        int searchBottom = (int) Math.min(h - 1, midY + eyesDist * 2.35f);
        int searchLeft = (int) Math.max(0, midX - eyesDist * 0.65f);
        int searchRight = (int) Math.min(w - 1, midX + eyesDist * 0.65f);

        double sumX = 0, sumY = 0, sumWeight = 0;
        int minX = w, maxX = 0, minY = h, maxY = 0;

        for (int y = searchTop; y <= searchBottom; y++) {
            for (int x = searchLeft; x <= searchRight; x++) {
                int c = bmp.getPixel(x, y);
                int r = (c >> 16) & 0xFF, g = (c >> 8) & 0xFF, b = c & 0xFF;
                float lum = (r + g + b) / 3.0f;
                float redRatio = (r - g) / Math.max(1.0f, lum);

                if (r > g && redRatio > 0.28f && lum > 25 && lum < 200 && r > 45) {
                    float dxNorm = (x - midX) / (eyesDist * 0.65f);
                    float sym = Math.max(0.2f, 1.0f - dxNorm * dxNorm);
                    double weight = (redRatio - 0.20) * sym;

                    sumX += x * weight;
                    sumY += y * weight;
                    sumWeight += weight;

                    if (x < minX) minX = x;
                    if (x > maxX) maxX = x;
                    if (y < minY) minY = y;
                    if (y > maxY) maxY = y;
                }
            }
        }

        if (sumWeight > 0 && (maxX - minX) >= 4) {
            return new PointF((float)(sumX / sumWeight), (float)(sumY / sumWeight));
        }
        // Anatomical fallback
        return new PointF(midX, midY + eyesDist * 1.45f);
    }
}
