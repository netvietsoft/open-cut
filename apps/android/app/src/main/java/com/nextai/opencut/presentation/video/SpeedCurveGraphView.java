package com.nextai.opencut.presentation.video;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

/**
 * SpeedCurveGraphView — Đồ Thị Trực Quan Đường Cong Tốc Độ Bezier (0.1x - 100x)
 * Visual Bezier Speed Curve Graph (0.1x - 100x)
 * Hiển thị lưới tọa độ, đường cong Bezier Cubic mượt mà, và 5 điểm neo kéo thả tương tác
 * Renders coordinate grid, smooth cubic Bezier curve, and 5 draggable anchor points
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class SpeedCurveGraphView extends View {

    private final Paint gridPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint curvePaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint pointFillPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint pointStrokePaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint textPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Path path = new Path();

    // 5 normalized points: Y represents speed (0.0 = 0.1x, 0.5 = 1.0x, 0.8 = 5.0x, 1.0 = 10.0x)
    private final float[] pointsY = new float[]{0.5f, 0.5f, 0.5f, 0.5f, 0.5f};
    private int activePointIndex = -1;

    public SpeedCurveGraphView(Context context) {
        super(context);
        init();
    }

    public SpeedCurveGraphView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void init() {
        gridPaint.setColor(Color.parseColor("#334155"));
        gridPaint.setStrokeWidth(2f);
        gridPaint.setStyle(Paint.Style.STROKE);

        curvePaint.setColor(Color.parseColor("#00E5FF"));
        curvePaint.setStrokeWidth(6f);
        curvePaint.setStyle(Paint.Style.STROKE);

        pointFillPaint.setColor(Color.WHITE);
        pointFillPaint.setStyle(Paint.Style.FILL);

        pointStrokePaint.setColor(Color.parseColor("#00E5FF"));
        pointStrokePaint.setStrokeWidth(5f);
        pointStrokePaint.setStyle(Paint.Style.STROKE);

        textPaint.setColor(Color.parseColor("#94A3B8"));
        textPaint.setTextSize(22f);
    }

    public void setPresetPoints(float[] pts) {
        if (pts != null && pts.length == 5) {
            System.arraycopy(pts, 0, pointsY, 0, 5);
            invalidate();
        }
    }

    public float[] getPoints() {
        return pointsY;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        int w = getWidth();
        int h = getHeight();
        if (w <= 0 || h <= 0) return;

        // Draw background & grid / Vẽ nền và lưới tọa độ
        canvas.drawColor(Color.parseColor("#0F172A"));

        float pad = 40f;
        float graphW = w - pad * 2;
        float graphH = h - pad * 2;

        canvas.drawLine(pad, pad, pad + graphW, pad, gridPaint);
        canvas.drawText("10.0x", 6f, pad + 10f, textPaint);

        canvas.drawLine(pad, pad + graphH * 0.25f, pad + graphW, pad + graphH * 0.25f, gridPaint);
        canvas.drawText("5.0x", 6f, pad + graphH * 0.25f + 8f, textPaint);

        canvas.drawLine(pad, pad + graphH * 0.5f, pad + graphW, pad + graphH * 0.5f, gridPaint);
        canvas.drawText("1.0x", 6f, pad + graphH * 0.5f + 8f, textPaint);

        canvas.drawLine(pad, pad + graphH, pad + graphW, pad + graphH, gridPaint);
        canvas.drawText("0.1x", 6f, pad + graphH, textPaint);

        // Compute point screen coordinates / Tính toán tọa độ màn hình cho 5 điểm neo
        float[] px = new float[5];
        float[] py = new float[5];
        for (int i = 0; i < 5; i++) {
            px[i] = pad + (graphW / 4f) * i;
            py[i] = pad + graphH * (1.0f - Math.max(0.05f, Math.min(0.95f, pointsY[i])));
        }

        // Draw smooth Bezier cubic spline through the 5 points / Vẽ đường cong Bezier Cubic mượt qua 5 điểm
        path.reset();
        path.moveTo(px[0], py[0]);
        for (int i = 0; i < 4; i++) {
            float midX = (px[i] + px[i + 1]) / 2f;
            path.cubicTo(midX, py[i], midX, py[i + 1], px[i + 1], py[i + 1]);
        }
        canvas.drawPath(path, curvePaint);

        // Draw glowing control points / Vẽ các điểm điều khiển phát sáng
        for (int i = 0; i < 5; i++) {
            canvas.drawCircle(px[i], py[i], 16f, pointFillPaint);
            canvas.drawCircle(px[i], py[i], 16f, pointStrokePaint);
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        float x = event.getX();
        float y = event.getY();
        float pad = 40f;
        float graphW = getWidth() - pad * 2;
        float graphH = getHeight() - pad * 2;

        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                activePointIndex = -1;
                float minDst = 60f;
                for (int i = 0; i < 5; i++) {
                    float pX = pad + (graphW / 4f) * i;
                    float pY = pad + graphH * (1.0f - pointsY[i]);
                    float dst = (float) Math.hypot(x - pX, y - pY);
                    if (dst < minDst) {
                        minDst = dst;
                        activePointIndex = i;
                    }
                }
                return true;
            case MotionEvent.ACTION_MOVE:
                if (activePointIndex >= 0 && graphH > 0) {
                    float normY = 1.0f - ((y - pad) / graphH);
                    pointsY[activePointIndex] = Math.max(0.05f, Math.min(0.95f, normY));
                    invalidate();
                }
                return true;
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_CANCEL:
                activePointIndex = -1;
                return true;
        }
        return super.onTouchEvent(event);
    }
}
