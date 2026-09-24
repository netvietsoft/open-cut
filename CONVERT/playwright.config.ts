import { defineConfig } from '@playwright/test';

export default defineConfig({
  testDir: './tests/playwright',
  timeout: 30000,
  use: {
    channel: 'msedge',
    baseURL: 'http://localhost:6033',
    headless: true,
  },
});
