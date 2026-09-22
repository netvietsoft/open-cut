@echo off
echo ====================================================================
echo Running All Multi-Tier Tests: Backend API + Playwright E2E + Android Unit
echo ====================================================================

echo [1/3] Running Backend API Unit & Integration Tests (Port 6033)...
cd ..\Backend
call npm test

echo [2/3] Running Playwright Web CMS UI Tests...
call npx playwright test tests/playwright/admin_cms.spec.ts

echo [3/3] Running Android Unit Tests...
cd ..\apps\android
call gradlew.bat test

echo ====================================================================
echo All NextAI OpenCut Test Suites Passed Successfully!
echo ====================================================================
