package com.nextai.opencut.provider;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.MatrixCursor;
import android.net.Uri;
import android.os.ParcelFileDescriptor;
import android.provider.OpenableColumns;
import android.webkit.MimeTypeMap;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;

/**
 * OpenCutFileProvider — Bộ Cung Cấp Tệp Nội Dung An Toàn (Secure Content Provider)
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 *
 * Provides content:// URIs for exported videos and photos, safely preventing FileUriExposedException
 * on Android 7.0+ (API 24+) without external library dependencies.
 * Cung cấp URI dạng content:// cho video và ảnh đã xuất, ngăn ngừa triệt để lỗi FileUriExposedException
 * trên Android 7.0+ (API 24+) một cách độc lập không phụ thuộc thư viện ngoài.
 */
public class OpenCutFileProvider extends ContentProvider {

    public static final String AUTHORITY = "com.nextai.opencut.fileprovider";
    private static final Map<String, File> REGISTERED_FILES = new HashMap<>();

    /**
     * Generate secure content URI for exported file
     * Tạo Content URI an toàn từ đối tượng tệp File
     */
    public static synchronized Uri getUriForFile(Context context, File file) {
        if (file == null) return null;
        String fileName = file.getName();
        REGISTERED_FILES.put(fileName, file);
        return new Uri.Builder()
                .scheme("content")
                .authority(AUTHORITY)
                .path(fileName)
                .build();
    }

    public static Uri getUriForFile(Context context, String authority, File file) {
        return getUriForFile(context, file);
    }

    @Override
    public boolean onCreate() {
        return true;
    }

    @Override
    public ParcelFileDescriptor openFile(Uri uri, String mode) throws FileNotFoundException {
        File file = findTargetFile(uri);
        if (file == null || !file.exists()) {
            throw new FileNotFoundException("File not found for URI: " + uri);
        }
        int pfdMode = ParcelFileDescriptor.MODE_READ_ONLY;
        if ("w".equals(mode) || "wt".equals(mode)) {
            pfdMode = ParcelFileDescriptor.MODE_WRITE_ONLY;
        } else if ("rw".equals(mode)) {
            pfdMode = ParcelFileDescriptor.MODE_READ_WRITE;
        }
        return ParcelFileDescriptor.open(file, pfdMode);
    }

    @Override
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        File file = findTargetFile(uri);
        if (file == null || !file.exists()) return null;

        if (projection == null) {
            projection = new String[]{OpenableColumns.DISPLAY_NAME, OpenableColumns.SIZE};
        }

        MatrixCursor cursor = new MatrixCursor(projection, 1);
        MatrixCursor.RowBuilder row = cursor.newRow();
        for (String col : projection) {
            if (OpenableColumns.DISPLAY_NAME.equals(col)) {
                row.add(file.getName());
            } else if (OpenableColumns.SIZE.equals(col)) {
                row.add(file.length());
            } else {
                row.add(null);
            }
        }
        return cursor;
    }

    @Override
    public String getType(Uri uri) {
        File file = findTargetFile(uri);
        if (file == null) return "application/octet-stream";
        String name = file.getName();
        int lastDot = name.lastIndexOf('.');
        if (lastDot >= 0) {
            String ext = name.substring(lastDot + 1).toLowerCase();
            String mime = MimeTypeMap.getSingleton().getMimeTypeFromExtension(ext);
            if (mime != null) return mime;
        }
        if (name.endsWith(".mp4")) return "video/mp4";
        if (name.endsWith(".jpg") || name.endsWith(".jpeg")) return "image/jpeg";
        if (name.endsWith(".png")) return "image/png";
        return "application/octet-stream";
    }

    @Override
    public Uri insert(Uri uri, ContentValues values) {
        throw new UnsupportedOperationException("Insert not supported");
    }

    @Override
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        File file = findTargetFile(uri);
        if (file != null && file.exists()) {
            return file.delete() ? 1 : 0;
        }
        return 0;
    }

    @Override
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        throw new UnsupportedOperationException("Update not supported");
    }

    private synchronized File findTargetFile(Uri uri) {
        if (uri == null || uri.getPath() == null) return null;
        String path = uri.getPath();
        if (path.startsWith("/")) path = path.substring(1);

        File registered = REGISTERED_FILES.get(path);
        if (registered != null && registered.exists()) {
            return registered;
        }

        // Fallback search in standard app video directory
        // Tìm kiếm dự phòng trong thư mục xuất phim chuẩn của ứng dụng
        if (getContext() != null) {
            File appMovies = new File(getContext().getExternalFilesDir(android.os.Environment.DIRECTORY_MOVIES), "NextAI_OpenCut");
            File candidate = new File(appMovies, path);
            if (candidate.exists()) return candidate;

            File publicMovies = new File(android.os.Environment.getExternalStoragePublicDirectory(android.os.Environment.DIRECTORY_MOVIES), "NextAI_OpenCut");
            File pubCandidate = new File(publicMovies, path);
            if (pubCandidate.exists()) return pubCandidate;
        }
        return null;
    }
}
