/**
 * Swagger Documentation Configuration / Cấu hình Tài liệu API Swagger
 * Generates interactive OpenAPI 3.0 UI for NextAI OpenCut endpoints.
 * Tạo giao diện tài liệu API tương tác chuẩn OpenAPI 3.0 cho toàn bộ endpoints.
 */

import swaggerJsdoc from 'swagger-jsdoc';

const options: swaggerJsdoc.Options = {
  definition: {
    openapi: '3.0.0',
    info: {
      title: 'NextAI OpenCut API Gateway & Microservices Documentation',
      version: '2.1.0',
      description: `
Tài liệu giao tiếp API chuẩn xác 100% cho NextAI OpenCut (Tái dựng siêu ứng dụng CapCut 19.4.0).
Bao gồm đầy đủ các phân hệ: Identity/Auth, AI Agent SSE Stream, Commerce/VIP Paywall, Template Feed, Editor Timeline và Admin Web CMS.
Máy chủ hoạt động tại cổng: **6033**.
      `,
      contact: {
        name: 'NextAI Technology Architecture Team',
        url: 'https://nextai.com'
      }
    },
    servers: [
      {
        url: 'http://localhost:6033',
        description: 'NextAI Local Development Gateway (Port 6033)'
      }
    ],
    components: {
      securitySchemes: {
        bearerAuth: {
          type: 'http',
          scheme: 'bearer',
          bearerFormat: 'JWT'
        },
        sessionIdHeader: {
          type: 'apiKey',
          in: 'header',
          name: 'sessionid'
        }
      }
    }
  },
  apis: ['./src/modules/**/*.ts', './src/server.ts']
};

export const swaggerSpec = swaggerJsdoc(options);
