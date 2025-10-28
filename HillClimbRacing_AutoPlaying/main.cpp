#include <opencv2/opencv.hpp>
#include <iostream>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world4120d.lib")
#else
#pragma comment(lib, "opencv_world4120.lib")
#endif


int main() {
    // 画像を読み込む（同じフォルダに test.jpg を置いてください）
    cv::Mat img = cv::imread("test.jpg");

    if (img.empty()) {
        std::cout << "画像が読み込めませんでした。" << std::endl;
        return -1;
    }

    // ウィンドウに画像を表示
    cv::imshow("表示テスト", img);
    cv::waitKey(0); // キー入力待ち
    return 0;
}