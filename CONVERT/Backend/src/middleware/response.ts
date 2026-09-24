/**
 * Standard Response Wrapper / Định dạng Phản hồi Chuẩn
 * Ensures 100% compliance with CapCut BaseResponse<T> format.
 * Đảm bảo tương thích 100% với định dạng BaseResponse<T> của máy chủ gốc.
 */

import { Response } from 'express';

export interface BaseResponse<T = any> {
  code: number;
  message: string;
  data: T;
  extra?: {
    now: number;
    logid: string;
  };
}

export function sendSuccess<T>(res: Response, data: T, message = 'success', code = 0) {
  const payload: BaseResponse<T> = {
    code,
    message,
    data,
    extra: {
      now: Date.now(),
      logid: `nextai_${Date.now()}_${Math.random().toString(36).substring(2, 9)}`
    }
  };
  return res.status(200).json(payload);
}

export function sendError(res: Response, message: string, code = 10001, status = 400) {
  const payload: BaseResponse<null> = {
    code,
    message,
    data: null,
    extra: {
      now: Date.now(),
      logid: `nextai_err_${Date.now()}_${Math.random().toString(36).substring(2, 9)}`
    }
  };
  return res.status(status).json(payload);
}
