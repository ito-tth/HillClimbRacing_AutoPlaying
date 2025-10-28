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
    HWND hwnd = GetDesktopWindow(); // �f�X�N�g�b�v�S��
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
    bi.biHeight = -height; // OpenCV�͏ォ�牺�։摜��`�悷��̂Ń}�C�i�X
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biCompression = BI_RGB;

    cv::Mat mat(height, width, CV_8UC3);
    GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, mat.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    // ��n��
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);

    return mat;
}
/*
int main() {
    cv::Mat screen = captureScreenMat();
    cv::imwrite("screenshot.jpg", screen);
    cv::imshow("�X�N���[���V���b�g", screen);
    cv::waitKey(0);
    return 0;
}
*/