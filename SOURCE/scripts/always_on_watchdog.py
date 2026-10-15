# -*- coding: utf-8 -*-
"""
===================================================================================
NEXTAI OPENCUT - ALWAYS-ON WATCHDOG DAEMON (LUÔN LUÔN THỨC 24/7)
===================================================================================
Chỉ đạo tối cao: Chủ tịch
Điều phối: Agent 0 (Thư ký Orchestrator)
Đối kháng: Agent 13 (Adversary Auditor - Red Team Critic)
Mục tiêu:
  - Luôn luôn thức, không bao giờ bị off.
  - Tự động hồi sinh khi có sự cố, ghi log nhịp tim liên tục.
  - Quét và đào bới toàn bộ 167 file .so còn lại.
  - Đối kháng, soi code, kiểm tra tính xác thực khép kín.
===================================================================================
"""

import os
import sys
import time
import subprocess
import datetime
from pathlib import Path

# UTF-8 stdout
if sys.stdout.encoding != 'utf-8':
    try:
        sys.stdout.reconfigure(encoding='utf-8', errors='replace')
        sys.stderr.reconfigure(encoding='utf-8', errors='replace')
    except Exception:
        pass

BASE_DIR = Path(r"D:\Decompiler\App\Video\Capcut\SOURCE")
SCRIPTS_DIR = BASE_DIR / "scripts"
LOGS_DIR = BASE_DIR / "logs"
LOGS_DIR.mkdir(parents=True, exist_ok=True)

PYTHON_EXE = sys.executable or r"C:\Users\boluc\AppData\Local\Python\bin\python.exe"
DAEMON_SCRIPT = SCRIPTS_DIR / "orchestrator_daemon.py"
ADVERSARY_SCRIPT = SCRIPTS_DIR / "adversary_critic_agent.py"
VERIFY_SCRIPT = SCRIPTS_DIR / "verify_reconstruction_suite.py"
HEARTBEAT_LOG = LOGS_DIR / "orchestrator_always_on.log"

def log_heartbeat(msg):
    now_str = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    line = f"[{now_str}] [ALWAYS-ON WATCHDOG] {msg}"
    print(line, flush=True)
    try:
        with open(HEARTBEAT_LOG, "a", encoding="utf-8") as f:
            f.write(line + "\n")
    except Exception:
        pass

def main():
    log_heartbeat("="*80)
    log_heartbeat("KHỞI CHẠY HỆ THỐNG LUÔN LUÔN THỨC (ALWAYS-ON WATCHDOG RUNNER)")
    log_heartbeat("CHỈ ĐẠO BỞI: CHỦ TỊCH | ĐIỀU PHỐI: AGENT 0 | ĐỐI KHÁNG: AGENT 13")
    log_heartbeat("MỤC TIÊU: TÁI DỰNG & ĐỐI SOÁT TOÀN BỘ 169 FILE .SO (ZERO STUB)")
    log_heartbeat("="*80)

    loop_count = 0
    restart_count = 0

    while True:
        loop_count += 1
        now_str = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log_heartbeat(f"\n--- BẮT ĐẦU CHU KỲ WATCHDOG #{loop_count} (Hồi sinh: {restart_count} lần) [{now_str}] ---")

        # 1. Chạy Agent 0 Orchestrator
        try:
            log_heartbeat("Bước 1: Kích hoạt Agent 0 Orchestrator (Quét báo cáo, giao task, giải mã)...")
            res0 = subprocess.run([PYTHON_EXE, str(DAEMON_SCRIPT), "--once"], capture_output=True, text=True, encoding="utf-8", errors="replace")
            if res0.returncode == 0:
                log_heartbeat("[Agent 0] Thành công.")
            else:
                log_heartbeat(f"[Agent 0 CẢNH BÁO] Return code {res0.returncode}: {res0.stderr[:200]}")
        except Exception as e:
            log_heartbeat(f"[Agent 0 LỖI] {e}")

        # 2. Chạy Agent 13 Adversary Critic
        try:
            log_heartbeat("Bước 2: Kích hoạt Agent 13 Adversary Auditor (Soi code, phát hành trát thách thức)...")
            res13 = subprocess.run([PYTHON_EXE, str(ADVERSARY_SCRIPT)], capture_output=True, text=True, encoding="utf-8", errors="replace")
            if res13.returncode == 0:
                log_heartbeat("[Agent 13] Đã hoàn tất đối kiểm và cập nhật Sổ Cái Đối Kháng.")
            else:
                log_heartbeat(f"[Agent 13 CẢNH BÁO] Return code {res13.returncode}: {res13.stderr[:200]}")
        except Exception as e:
            log_heartbeat(f"[Agent 13 LỖI] {e}")

        # 3. Chạy Closed-Loop Verification Suite
        try:
            log_heartbeat("Bước 3: Chạy Closed-Loop Verification Test Suite...")
            res_v = subprocess.run([PYTHON_EXE, str(VERIFY_SCRIPT)], capture_output=True, text=True, encoding="utf-8", errors="replace")
            if res_v.returncode == 0:
                log_heartbeat("[Test Suite] 100% PASS.")
            else:
                log_heartbeat(f"[Test Suite CẢNH BÁO] Return code {res_v.returncode}")
        except Exception as e:
            log_heartbeat(f"[Test Suite LỖI] {e}")

        log_heartbeat(f"[WATCHDOG] Chu kỳ #{loop_count} kết thúc. Nghỉ 60 giây và tiếp tục chu kỳ #{loop_count + 1}...")
        time.sleep(60)

if __name__ == "__main__":
    main()
