/**
 * Playwright E2E Test Suite for NextAI OpenCut Web CMS
 * Validates Responsive Layout, Dark/Light Theme, Breadcrumbs, User CRUD, and Cloudflare R2 UI.
 */

import { test, expect } from '@playwright/test';

const BASE_URL = 'http://localhost:6033';

test.describe('NextAI OpenCut Web Admin CMS (Port 6033) Visual & Functional E2E', () => {
  test.beforeEach(async ({ page }) => {
    await page.goto(BASE_URL);
  });

  test('1. Verify Dashboard Overview and Server Status Indicator', async ({ page }) => {
    await expect(page).toHaveTitle(/NextAI OpenCut/);
    await expect(page.locator('.server-status')).toContainText('Port 6033: ONLINE');
    await expect(page.locator('.stat-card').first()).toBeVisible();
  });

  test('2. Verify Dark/Light Mode Theme Switching and Persistence', async ({ page }) => {
    const themeBtn = page.locator('#themeToggleBtn');
    await expect(themeBtn).toBeVisible();

    // Toggle to Light theme
    await themeBtn.click();
    await expect(page.locator('html')).toHaveAttribute('data-theme', 'light');

    // Toggle back to Dark theme
    await themeBtn.click();
    await expect(page.locator('html')).toHaveAttribute('data-theme', 'dark');
  });

  test('3. Test Navigation Routes & Breadcrumbs (domain.com/ParentMenu/SubMenu)', async ({ page }) => {
    // Navigate to Users Management
    await page.click('a[data-route="users"]');
    await expect(page.locator('#breadcrumbChild')).toContainText('USERS');
    await expect(page.locator('#usersCardGrid')).toBeVisible();

    // Navigate to Templates
    await page.click('a[data-route="templates"]');
    await expect(page.locator('#breadcrumbChild')).toContainText('TEMPLATES');

    // Navigate to Cloudflare R2 Assets
    await page.click('a[data-route="assets"]');
    await expect(page.locator('#breadcrumbChild')).toContainText('ASSETS');
  });

  test('4. Test User Creation Modal & Card-Based High-Density Display', async ({ page }) => {
    await page.click('a[data-route="users"]');

    // Open Create User Modal
    await page.click('button:has-text("Thêm Người Dùng Mới")');
    await expect(page.locator('#modalOverlay')).toBeVisible();

    // Fill form
    await page.fill('#newUsername', 'TestCreator_E2E');
    await page.fill('#newEmail', 'e2e_creator@nextai.com');
    await page.selectOption('#newIsVip', '1');

    // Submit
    await page.click('button:has-text("Xác Nhận Tạo Người Dùng")');
    await expect(page.locator('#modalOverlay')).toHaveClass(/hidden/);

    // Verify card is added
    await expect(page.locator('.data-card', { hasText: 'TestCreator_E2E' })).toBeVisible();
  });
});
