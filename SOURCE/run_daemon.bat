@echo off
title NextAI OpenCut - Orchestrator Daemon (CEO Agent 0)
echo ===============================================================================
echo NEXTAI OPENCUT - ORCHESTRATOR DAEMON (AGENT 0)
echo Tiêu chuẩn: Development Workspace Standard V2.1 Design-Gated
echo Thức dậy: 3 phút (180 giây) / 1 lần tự động quét, giao task, kiểm tra code
echo ===============================================================================

set PYTHON_EXE=C:\Users\boluc\AppData\Local\Python\bin\python.exe

if not exist "%PYTHON_EXE%" (
    echo [ERROR] Không tìm thấy Python tại: %PYTHON_EXE%
    pause
    exit /b 1
)

"%PYTHON_EXE%" "D:\Decompiler\App\Video\Capcut\SOURCE\scripts\orchestrator_daemon.py" --interval 180

pause
