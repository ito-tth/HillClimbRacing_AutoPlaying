#include <windows.h>
#include <opencv2/opencv.hpp>
#include <iostream>

/*
#ifdef _DEBUG
#pragma comment(lib, "opencv_world4120d.lib")
#else
#pragma comment(lib, "opencv_world4120.lib")
#endif
*/

cv::Mat captureScreenMat() {
    HWND hwnd = GetDesktopWindow(); // デスクトップ全体
    HDC hwindowDC = GetDC(hwnd);
    HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);

    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);

    HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
    SelectObject(hwindowCompatibleDC, hbwindow);
    BitBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, 0, 0, SRCCOPY);

    BITMAPINFOHEADER bi = { 0 };
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height; // OpenCVは上から下へ画像を描画するのでマイナス
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biCompression = BI_RGB;

    cv::Mat mat(height, width, CV_8UC3);
    GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, mat.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    // 後始末
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);

    return mat;
}
/*
int main() {
    cv::Mat screen = captureScreenMat();
    cv::imwrite("screenshot.jpg", screen);
    cv::imshow("スクリーンショット", screen);
    cv::waitKey(0);
    return 0;
}
*/