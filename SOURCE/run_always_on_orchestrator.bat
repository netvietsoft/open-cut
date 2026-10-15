@echo off
chcp 65001 >nul
title NextAI OpenCut - Always-On Orchestrator & Adversary Auditor
echo ===============================================================================
echo NEXTAI OPENCUT - ALWAYS-ON WATCHDOG DAEMON ^& AGENT 13 ADVERSARY CRITIC
echo Chi dao toi cao: Chu tich ^| Dieu phoi: Agent 0 ^| Doi khang: Agent 13
echo ===============================================================================
echo.

"C:\Users\boluc\AppData\Local\Python\bin\python.exe" -u "%~dp0scripts\always_on_watchdog.py"
pause
